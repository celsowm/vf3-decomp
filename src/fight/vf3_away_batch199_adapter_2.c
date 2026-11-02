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
int vf3_away_batch199_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09d670u: goto P_0c09d670;
case 0x0c09d672u: goto P_0c09d672;
case 0x0c09d674u: goto P_0c09d674;
case 0x0c09d676u: goto P_0c09d676;
case 0x0c09d678u: goto P_0c09d678;
case 0x0c09d67au: goto P_0c09d67a;
case 0x0c09d67cu: goto P_0c09d67c;
case 0x0c09d67eu: goto P_0c09d67e;
case 0x0c09d680u: goto P_0c09d680;
case 0x0c09d682u: goto P_0c09d682;
case 0x0c09d684u: goto P_0c09d684;
case 0x0c09d686u: goto P_0c09d686;
case 0x0c09d688u: goto P_0c09d688;
case 0x0c09d68au: goto P_0c09d68a;
case 0x0c09d68cu: goto P_0c09d68c;
case 0x0c09d68eu: goto P_0c09d68e;
case 0x0c09d690u: goto P_0c09d690;
case 0x0c09d692u: goto P_0c09d692;
case 0x0c09d694u: goto P_0c09d694;
case 0x0c09d696u: goto P_0c09d696;
case 0x0c09d698u: goto P_0c09d698;
case 0x0c09d69au: goto P_0c09d69a;
case 0x0c09d69cu: goto P_0c09d69c;
case 0x0c09d69eu: goto P_0c09d69e;
case 0x0c09d6a0u: goto P_0c09d6a0;
case 0x0c09d6a2u: goto P_0c09d6a2;
case 0x0c09d6a4u: goto P_0c09d6a4;
case 0x0c09d6a6u: goto P_0c09d6a6;
case 0x0c09d6a8u: goto P_0c09d6a8;
case 0x0c09d6aau: goto P_0c09d6aa;
case 0x0c09d6acu: goto P_0c09d6ac;
case 0x0c09d6aeu: goto P_0c09d6ae;
case 0x0c09d6b0u: goto P_0c09d6b0;
case 0x0c09d6b2u: goto P_0c09d6b2;
case 0x0c09d6b4u: goto P_0c09d6b4;
case 0x0c09d6b6u: goto P_0c09d6b6;
case 0x0c09d6b8u: goto P_0c09d6b8;
case 0x0c09d6bau: goto P_0c09d6ba;
case 0x0c09d6bcu: goto P_0c09d6bc;
case 0x0c09d6beu: goto P_0c09d6be;
case 0x0c09d6c0u: goto P_0c09d6c0;
case 0x0c09d6c2u: goto P_0c09d6c2;
case 0x0c09d6c4u: goto P_0c09d6c4;
case 0x0c09d6c6u: goto P_0c09d6c6;
case 0x0c09d6c8u: goto P_0c09d6c8;
case 0x0c09d6e0u: goto P_0c09d6e0;
case 0x0c09d6e2u: goto P_0c09d6e2;
case 0x0c09d6e4u: goto P_0c09d6e4;
case 0x0c09d6e6u: goto P_0c09d6e6;
case 0x0c09d6e8u: goto P_0c09d6e8;
case 0x0c09d6eau: goto P_0c09d6ea;
case 0x0c09d6ecu: goto P_0c09d6ec;
case 0x0c09d6eeu: goto P_0c09d6ee;
case 0x0c09d6f0u: goto P_0c09d6f0;
case 0x0c09d6f2u: goto P_0c09d6f2;
case 0x0c09d6f4u: goto P_0c09d6f4;
case 0x0c09d6f6u: goto P_0c09d6f6;
case 0x0c09d6f8u: goto P_0c09d6f8;
case 0x0c09d6fau: goto P_0c09d6fa;
case 0x0c09d6fcu: goto P_0c09d6fc;
case 0x0c09d6feu: goto P_0c09d6fe;
case 0x0c09d700u: goto P_0c09d700;
case 0x0c09d702u: goto P_0c09d702;
case 0x0c09d704u: goto P_0c09d704;
case 0x0c09d706u: goto P_0c09d706;
case 0x0c09d708u: goto P_0c09d708;
case 0x0c09d70au: goto P_0c09d70a;
case 0x0c09d70cu: goto P_0c09d70c;
case 0x0c09d70eu: goto P_0c09d70e;
case 0x0c09d710u: goto P_0c09d710;
case 0x0c09d712u: goto P_0c09d712;
case 0x0c09d714u: goto P_0c09d714;
case 0x0c09d716u: goto P_0c09d716;
case 0x0c09d718u: goto P_0c09d718;
case 0x0c09d71au: goto P_0c09d71a;
case 0x0c09d71cu: goto P_0c09d71c;
case 0x0c09d71eu: goto P_0c09d71e;
case 0x0c09d720u: goto P_0c09d720;
case 0x0c09d722u: goto P_0c09d722;
case 0x0c09d724u: goto P_0c09d724;
case 0x0c09d726u: goto P_0c09d726;
case 0x0c09d728u: goto P_0c09d728;
case 0x0c09d72au: goto P_0c09d72a;
case 0x0c09d72cu: goto P_0c09d72c;
case 0x0c09d72eu: goto P_0c09d72e;
case 0x0c09d730u: goto P_0c09d730;
case 0x0c09d732u: goto P_0c09d732;
case 0x0c09d734u: goto P_0c09d734;
case 0x0c09d736u: goto P_0c09d736;
case 0x0c09d738u: goto P_0c09d738;
case 0x0c09d73au: goto P_0c09d73a;
case 0x0c09d73cu: goto P_0c09d73c;
case 0x0c09d73eu: goto P_0c09d73e;
case 0x0c09d740u: goto P_0c09d740;
case 0x0c09d742u: goto P_0c09d742;
case 0x0c09d744u: goto P_0c09d744;
case 0x0c09d746u: goto P_0c09d746;
case 0x0c09d748u: goto P_0c09d748;
case 0x0c09d74au: goto P_0c09d74a;
case 0x0c09d74cu: goto P_0c09d74c;
case 0x0c09d74eu: goto P_0c09d74e;
case 0x0c09d750u: goto P_0c09d750;
case 0x0c09d752u: goto P_0c09d752;
case 0x0c09d754u: goto P_0c09d754;
case 0x0c09d756u: goto P_0c09d756;
case 0x0c09d758u: goto P_0c09d758;
case 0x0c09d75au: goto P_0c09d75a;
case 0x0c09d75cu: goto P_0c09d75c;
case 0x0c09d75eu: goto P_0c09d75e;
case 0x0c09d760u: goto P_0c09d760;
case 0x0c09d762u: goto P_0c09d762;
case 0x0c09d764u: goto P_0c09d764;
case 0x0c09d766u: goto P_0c09d766;
case 0x0c09d768u: goto P_0c09d768;
case 0x0c09d76au: goto P_0c09d76a;
case 0x0c09d76cu: goto P_0c09d76c;
case 0x0c09d76eu: goto P_0c09d76e;
case 0x0c09d770u: goto P_0c09d770;
case 0x0c09d772u: goto P_0c09d772;
case 0x0c09d774u: goto P_0c09d774;
case 0x0c09d776u: goto P_0c09d776;
case 0x0c09d778u: goto P_0c09d778;
case 0x0c09d77au: goto P_0c09d77a;
case 0x0c09d77cu: goto P_0c09d77c;
case 0x0c09d77eu: goto P_0c09d77e;
case 0x0c09d780u: goto P_0c09d780;
case 0x0c09d782u: goto P_0c09d782;
case 0x0c09d784u: goto P_0c09d784;
case 0x0c09d786u: goto P_0c09d786;
case 0x0c09d788u: goto P_0c09d788;
case 0x0c09d78au: goto P_0c09d78a;
case 0x0c09d78cu: goto P_0c09d78c;
case 0x0c09d78eu: goto P_0c09d78e;
case 0x0c09d790u: goto P_0c09d790;
case 0x0c09d792u: goto P_0c09d792;
case 0x0c09d794u: goto P_0c09d794;
case 0x0c09d796u: goto P_0c09d796;
case 0x0c09d798u: goto P_0c09d798;
case 0x0c09d79au: goto P_0c09d79a;
case 0x0c09d79cu: goto P_0c09d79c;
case 0x0c09d79eu: goto P_0c09d79e;
case 0x0c09d7a0u: goto P_0c09d7a0;
case 0x0c09d7a2u: goto P_0c09d7a2;
case 0x0c09d7a4u: goto P_0c09d7a4;
case 0x0c09d7a6u: goto P_0c09d7a6;
case 0x0c09d7a8u: goto P_0c09d7a8;
case 0x0c09d7aau: goto P_0c09d7aa;
case 0x0c09d7acu: goto P_0c09d7ac;
case 0x0c09d7aeu: goto P_0c09d7ae;
case 0x0c09d7b0u: goto P_0c09d7b0;
case 0x0c09d7b2u: goto P_0c09d7b2;
case 0x0c09d7b4u: goto P_0c09d7b4;
case 0x0c09d7b6u: goto P_0c09d7b6;
case 0x0c09d7b8u: goto P_0c09d7b8;
case 0x0c09d7bau: goto P_0c09d7ba;
case 0x0c09d7bcu: goto P_0c09d7bc;
case 0x0c09d7beu: goto P_0c09d7be;
case 0x0c09d7c0u: goto P_0c09d7c0;
case 0x0c09d7c2u: goto P_0c09d7c2;
case 0x0c09d7c4u: goto P_0c09d7c4;
case 0x0c09d7c6u: goto P_0c09d7c6;
case 0x0c09d7c8u: goto P_0c09d7c8;
case 0x0c09d7cau: goto P_0c09d7ca;
case 0x0c09d7ccu: goto P_0c09d7cc;
case 0x0c09d7ceu: goto P_0c09d7ce;
case 0x0c09d7d0u: goto P_0c09d7d0;
case 0x0c09d7d2u: goto P_0c09d7d2;
case 0x0c09d7d4u: goto P_0c09d7d4;
case 0x0c09d7d6u: goto P_0c09d7d6;
case 0x0c09d7d8u: goto P_0c09d7d8;
case 0x0c09d7dau: goto P_0c09d7da;
case 0x0c09d7dcu: goto P_0c09d7dc;
case 0x0c09d7deu: goto P_0c09d7de;
case 0x0c09d7e0u: goto P_0c09d7e0;
case 0x0c09d7e2u: goto P_0c09d7e2;
case 0x0c09d7e4u: goto P_0c09d7e4;
case 0x0c09d7e6u: goto P_0c09d7e6;
case 0x0c09d7e8u: goto P_0c09d7e8;
case 0x0c09d7eau: goto P_0c09d7ea;
case 0x0c09d7ecu: goto P_0c09d7ec;
case 0x0c09d7eeu: goto P_0c09d7ee;
case 0x0c09d7f0u: goto P_0c09d7f0;
case 0x0c09d7f2u: goto P_0c09d7f2;
case 0x0c09d7f4u: goto P_0c09d7f4;
case 0x0c09d7f6u: goto P_0c09d7f6;
case 0x0c09d7f8u: goto P_0c09d7f8;
case 0x0c09d7fau: goto P_0c09d7fa;
case 0x0c09d7fcu: goto P_0c09d7fc;
case 0x0c09d7feu: goto P_0c09d7fe;
case 0x0c09d800u: goto P_0c09d800;
case 0x0c09d802u: goto P_0c09d802;
case 0x0c09d804u: goto P_0c09d804;
case 0x0c09d806u: goto P_0c09d806;
case 0x0c09d808u: goto P_0c09d808;
case 0x0c09d80au: goto P_0c09d80a;
case 0x0c09d80cu: goto P_0c09d80c;
case 0x0c09d80eu: goto P_0c09d80e;
case 0x0c09d810u: goto P_0c09d810;
case 0x0c09d812u: goto P_0c09d812;
case 0x0c09d814u: goto P_0c09d814;
case 0x0c09d816u: goto P_0c09d816;
case 0x0c09d818u: goto P_0c09d818;
case 0x0c09d81au: goto P_0c09d81a;
case 0x0c09d81cu: goto P_0c09d81c;
case 0x0c09d81eu: goto P_0c09d81e;
case 0x0c09d820u: goto P_0c09d820;
case 0x0c09d822u: goto P_0c09d822;
case 0x0c09d824u: goto P_0c09d824;
case 0x0c09d826u: goto P_0c09d826;
case 0x0c09d828u: goto P_0c09d828;
case 0x0c09d82au: goto P_0c09d82a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09d670: /* original 9030, guest PC 0x0c09d670 */
if(!s->budget--) { s->failed_pc=0x0c09d670u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d6d4u,2);
goto P_0c09d672;
P_0c09d672: /* original 9230, guest PC 0x0c09d672 */
if(!s->budget--) { s->failed_pc=0x0c09d672u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d6d6u,2);
goto P_0c09d674;
P_0c09d674: /* original 034d, guest PC 0x0c09d674 */
if(!s->budget--) { s->failed_pc=0x0c09d674u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09d676;
P_0c09d676: /* original 633d, guest PC 0x0c09d676 */
if(!s->budget--) { s->failed_pc=0x0c09d676u; return 0; }
r[3]=r[3]&65535u;
goto P_0c09d678;
P_0c09d678: /* original 3327, guest PC 0x0c09d678 */
if(!s->budget--) { s->failed_pc=0x0c09d678u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c09d67a;
P_0c09d67a: /* original 8b01, guest PC 0x0c09d67a */
if(!s->budget--) { s->failed_pc=0x0c09d67au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09d680; }
goto P_0c09d67c;
P_0c09d67c: /* original a0dc, guest PC 0x0c09d67c */
if(!s->budget--) { s->failed_pc=0x0c09d67cu; return 0; }
return vf3_matrix_family(0x0c09d838u,s,ram);
P_0c09d67e: /* original 0009, guest PC 0x0c09d67e */
if(!s->budget--) { s->failed_pc=0x0c09d67eu; return 0; }
goto P_0c09d680;
P_0c09d680: /* original a000, guest PC 0x0c09d680 */
if(!s->budget--) { s->failed_pc=0x0c09d680u; return 0; }
goto P_0c09d684;
P_0c09d682: /* original 0009, guest PC 0x0c09d682 */
if(!s->budget--) { s->failed_pc=0x0c09d682u; return 0; }
goto P_0c09d684;
P_0c09d684: /* original 2fe6, guest PC 0x0c09d684 */
if(!s->budget--) { s->failed_pc=0x0c09d684u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d686;
P_0c09d686: /* original 2fd6, guest PC 0x0c09d686 */
if(!s->budget--) { s->failed_pc=0x0c09d686u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d688;
P_0c09d688: /* original 2fc6, guest PC 0x0c09d688 */
if(!s->budget--) { s->failed_pc=0x0c09d688u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d68a;
P_0c09d68a: /* original 2fb6, guest PC 0x0c09d68a */
if(!s->budget--) { s->failed_pc=0x0c09d68au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d68c;
P_0c09d68c: /* original 2f96, guest PC 0x0c09d68c */
if(!s->budget--) { s->failed_pc=0x0c09d68cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d68e;
P_0c09d68e: /* original 2f86, guest PC 0x0c09d68e */
if(!s->budget--) { s->failed_pc=0x0c09d68eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d690;
P_0c09d690: /* original 4f22, guest PC 0x0c09d690 */
if(!s->budget--) { s->failed_pc=0x0c09d690u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d692;
P_0c09d692: /* original 7fec, guest PC 0x0c09d692 */
if(!s->budget--) { s->failed_pc=0x0c09d692u; return 0; }
r[15]+=0xffffffecu;
goto P_0c09d694;
P_0c09d694: /* original 2f52, guest PC 0x0c09d694 */
if(!s->budget--) { s->failed_pc=0x0c09d694u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c09d696;
P_0c09d696: /* original 901b, guest PC 0x0c09d696 */
if(!s->budget--) { s->failed_pc=0x0c09d696u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d6d0u,2);
goto P_0c09d698;
P_0c09d698: /* original 084e, guest PC 0x0c09d698 */
if(!s->budget--) { s->failed_pc=0x0c09d698u; return 0; }
r[8]=read(ram,r[4]+r[0],4);
goto P_0c09d69a;
P_0c09d69a: /* original 6382, guest PC 0x0c09d69a */
if(!s->budget--) { s->failed_pc=0x0c09d69au; return 0; }
tmp=read(ram,r[8],4);
r[3]=tmp;
goto P_0c09d69c;
P_0c09d69c: /* original 1f34, guest PC 0x0c09d69c */
if(!s->budget--) { s->failed_pc=0x0c09d69cu; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c09d69e;
P_0c09d69e: /* original 63f2, guest PC 0x0c09d69e */
if(!s->budget--) { s->failed_pc=0x0c09d69eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09d6a0;
P_0c09d6a0: /* original 5e82, guest PC 0x0c09d6a0 */
if(!s->budget--) { s->failed_pc=0x0c09d6a0u; return 0; }
r[14]=read(ram,r[8]+8,4);
goto P_0c09d6a2;
P_0c09d6a2: /* original 6232, guest PC 0x0c09d6a2 */
if(!s->budget--) { s->failed_pc=0x0c09d6a2u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c09d6a4;
P_0c09d6a4: /* original 5c81, guest PC 0x0c09d6a4 */
if(!s->budget--) { s->failed_pc=0x0c09d6a4u; return 0; }
r[12]=read(ram,r[8]+4,4);
goto P_0c09d6a6;
P_0c09d6a6: /* original 1f21, guest PC 0x0c09d6a6 */
if(!s->budget--) { s->failed_pc=0x0c09d6a6u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c09d6a8;
P_0c09d6a8: /* original a0ac, guest PC 0x0c09d6a8 */
if(!s->budget--) { s->failed_pc=0x0c09d6a8u; return 0; }
r[9]=0x00000000u;
goto P_0c09d804;
P_0c09d6aa: /* original e900, guest PC 0x0c09d6aa */
if(!s->budget--) { s->failed_pc=0x0c09d6aau; return 0; }
r[9]=0x00000000u;
goto P_0c09d6ac;
P_0c09d6ac: /* original 6583, guest PC 0x0c09d6ac */
if(!s->budget--) { s->failed_pc=0x0c09d6acu; return 0; }
r[5]=r[8];
goto P_0c09d6ae;
P_0c09d6ae: /* original 750c, guest PC 0x0c09d6ae */
if(!s->budget--) { s->failed_pc=0x0c09d6aeu; return 0; }
r[5]+=0x0000000cu;
goto P_0c09d6b0;
P_0c09d6b0: /* original 359c, guest PC 0x0c09d6b0 */
if(!s->budget--) { s->failed_pc=0x0c09d6b0u; return 0; }
r[5]+=r[9];
goto P_0c09d6b2;
P_0c09d6b2: /* original 9711, guest PC 0x0c09d6b2 */
if(!s->budget--) { s->failed_pc=0x0c09d6b2u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d6d8u,2);
goto P_0c09d6b4;
P_0c09d6b4: /* original 6550, guest PC 0x0c09d6b4 */
if(!s->budget--) { s->failed_pc=0x0c09d6b4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c09d6b6;
P_0c09d6b6: /* original 6053, guest PC 0x0c09d6b6 */
if(!s->budget--) { s->failed_pc=0x0c09d6b6u; return 0; }
r[0]=r[5];
goto P_0c09d6b8;
P_0c09d6b8: /* original 307c, guest PC 0x0c09d6b8 */
if(!s->budget--) { s->failed_pc=0x0c09d6b8u; return 0; }
r[0]+=r[7];
goto P_0c09d6ba;
P_0c09d6ba: /* original 675c, guest PC 0x0c09d6ba */
if(!s->budget--) { s->failed_pc=0x0c09d6bau; return 0; }
r[7]=r[5]&255u;
goto P_0c09d6bc;
P_0c09d6bc: /* original 80f8, guest PC 0x0c09d6bc */
if(!s->budget--) { s->failed_pc=0x0c09d6bcu; return 0; }
write(ram,r[15]+8,r[0],1);
goto P_0c09d6be;
P_0c09d6be: /* original 6073, guest PC 0x0c09d6be */
if(!s->budget--) { s->failed_pc=0x0c09d6beu; return 0; }
r[0]=r[7];
goto P_0c09d6c0;
P_0c09d6c0: /* original 8801, guest PC 0x0c09d6c0 */
if(!s->budget--) { s->failed_pc=0x0c09d6c0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09d6c2;
P_0c09d6c2: /* original 8f0d, guest PC 0x0c09d6c2 */
if(!s->budget--) { s->failed_pc=0x0c09d6c2u; return 0; }
cond=r[17]&1u;
fr[4]=0;
if(!cond) { goto P_0c09d6e0; }
goto P_0c09d6c6;
P_0c09d6c4: /* original f48d, guest PC 0x0c09d6c4 */
if(!s->budget--) { s->failed_pc=0x0c09d6c4u; return 0; }
fr[4]=0;
goto P_0c09d6c6;
P_0c09d6c6: /* original a097, guest PC 0x0c09d6c6 */
if(!s->budget--) { s->failed_pc=0x0c09d6c6u; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c09d7f8;
P_0c09d6c8: /* original f4e9, guest PC 0x0c09d6c8 */
if(!s->budget--) { s->failed_pc=0x0c09d6c8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c09d6cau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09d6cau; return 0; } return 1;
P_0c09d6e0: /* original e501, guest PC 0x0c09d6e0 */
if(!s->budget--) { s->failed_pc=0x0c09d6e0u; return 0; }
r[5]=0x00000001u;
goto P_0c09d6e2;
P_0c09d6e2: /* original 3753, guest PC 0x0c09d6e2 */
if(!s->budget--) { s->failed_pc=0x0c09d6e2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[5])!=0);
goto P_0c09d6e4;
P_0c09d6e4: /* original 8901, guest PC 0x0c09d6e4 */
if(!s->budget--) { s->failed_pc=0x0c09d6e4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d6ea; }
goto P_0c09d6e6;
P_0c09d6e6: /* original a087, guest PC 0x0c09d6e6 */
if(!s->budget--) { s->failed_pc=0x0c09d6e6u; return 0; }
goto P_0c09d7f8;
P_0c09d6e8: /* original 0009, guest PC 0x0c09d6e8 */
if(!s->budget--) { s->failed_pc=0x0c09d6e8u; return 0; }
goto P_0c09d6ea;
P_0c09d6ea: /* original 55f4, guest PC 0x0c09d6ea */
if(!s->budget--) { s->failed_pc=0x0c09d6eau; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c09d6ec;
P_0c09d6ec: /* original ed00, guest PC 0x0c09d6ec */
if(!s->budget--) { s->failed_pc=0x0c09d6ecu; return 0; }
r[13]=0x00000000u;
goto P_0c09d6ee;
P_0c09d6ee: /* original 7501, guest PC 0x0c09d6ee */
if(!s->budget--) { s->failed_pc=0x0c09d6eeu; return 0; }
r[5]+=0x00000001u;
goto P_0c09d6f0;
P_0c09d6f0: /* original 1f54, guest PC 0x0c09d6f0 */
if(!s->budget--) { s->failed_pc=0x0c09d6f0u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c09d6f2;
P_0c09d6f2: /* original 979b, guest PC 0x0c09d6f2 */
if(!s->budget--) { s->failed_pc=0x0c09d6f2u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d82cu,2);
goto P_0c09d6f4;
P_0c09d6f4: /* original 6550, guest PC 0x0c09d6f4 */
if(!s->budget--) { s->failed_pc=0x0c09d6f4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c09d6f6;
P_0c09d6f6: /* original 1f73, guest PC 0x0c09d6f6 */
if(!s->budget--) { s->failed_pc=0x0c09d6f6u; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c09d6f8;
P_0c09d6f8: /* original 9099, guest PC 0x0c09d6f8 */
if(!s->budget--) { s->failed_pc=0x0c09d6f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d82eu,2);
goto P_0c09d6fa;
P_0c09d6fa: /* original 655c, guest PC 0x0c09d6fa */
if(!s->budget--) { s->failed_pc=0x0c09d6fau; return 0; }
r[5]=r[5]&255u;
goto P_0c09d6fc;
P_0c09d6fc: /* original 2558, guest PC 0x0c09d6fc */
if(!s->budget--) { s->failed_pc=0x0c09d6fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c09d6fe;
P_0c09d6fe: /* original 074d, guest PC 0x0c09d6fe */
if(!s->budget--) { s->failed_pc=0x0c09d6feu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09d700;
P_0c09d700: /* original 677d, guest PC 0x0c09d700 */
if(!s->budget--) { s->failed_pc=0x0c09d700u; return 0; }
r[7]=r[7]&65535u;
goto P_0c09d702;
P_0c09d702: /* original 8d26, guest PC 0x0c09d702 */
if(!s->budget--) { s->failed_pc=0x0c09d702u; return 0; }
cond=r[17]&1u;
r[7]<<=8;
if(cond) { goto P_0c09d752; }
goto P_0c09d706;
P_0c09d704: /* original 4718, guest PC 0x0c09d704 */
if(!s->budget--) { s->failed_pc=0x0c09d704u; return 0; }
r[7]<<=8;
goto P_0c09d706;
P_0c09d706: /* original 67d3, guest PC 0x0c09d706 */
if(!s->budget--) { s->failed_pc=0x0c09d706u; return 0; }
r[7]=r[13];
goto P_0c09d708;
P_0c09d708: /* original 37cc, guest PC 0x0c09d708 */
if(!s->budget--) { s->failed_pc=0x0c09d708u; return 0; }
r[7]+=r[12];
goto P_0c09d70a;
P_0c09d70a: /* original 6770, guest PC 0x0c09d70a */
if(!s->budget--) { s->failed_pc=0x0c09d70au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]=tmp;
goto P_0c09d70c;
P_0c09d70c: /* original 35d7, guest PC 0x0c09d70c */
if(!s->budget--) { s->failed_pc=0x0c09d70cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[13])!=0);
goto P_0c09d70e;
P_0c09d70e: /* original 677c, guest PC 0x0c09d70e */
if(!s->budget--) { s->failed_pc=0x0c09d70eu; return 0; }
r[7]=r[7]&255u;
goto P_0c09d710;
P_0c09d710: /* original 8f1b, guest PC 0x0c09d710 */
if(!s->budget--) { s->failed_pc=0x0c09d710u; return 0; }
cond=r[17]&1u;
r[7]<<=8;
if(!cond) { goto P_0c09d74a; }
goto P_0c09d714;
P_0c09d712: /* original 4718, guest PC 0x0c09d712 */
if(!s->budget--) { s->failed_pc=0x0c09d712u; return 0; }
r[7]<<=8;
goto P_0c09d714;
P_0c09d714: /* original 3767, guest PC 0x0c09d714 */
if(!s->budget--) { s->failed_pc=0x0c09d714u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>(int32_t)r[6])!=0);
goto P_0c09d716;
P_0c09d716: /* original 891c, guest PC 0x0c09d716 */
if(!s->budget--) { s->failed_pc=0x0c09d716u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d752; }
goto P_0c09d718;
P_0c09d718: /* original 3670, guest PC 0x0c09d718 */
if(!s->budget--) { s->failed_pc=0x0c09d718u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[7])!=0);
goto P_0c09d71a;
P_0c09d71a: /* original 8902, guest PC 0x0c09d71a */
if(!s->budget--) { s->failed_pc=0x0c09d71au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d722; }
goto P_0c09d71c;
P_0c09d71c: /* original 7d01, guest PC 0x0c09d71c */
if(!s->budget--) { s->failed_pc=0x0c09d71cu; return 0; }
r[13]+=0x00000001u;
goto P_0c09d71e;
P_0c09d71e: /* original aff2, guest PC 0x0c09d71e */
if(!s->budget--) { s->failed_pc=0x0c09d71eu; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c09d706;
P_0c09d720: /* original 1f73, guest PC 0x0c09d720 */
if(!s->budget--) { s->failed_pc=0x0c09d720u; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c09d722;
P_0c09d722: /* original 84f8, guest PC 0x0c09d722 */
if(!s->budget--) { s->failed_pc=0x0c09d722u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+8,1);
goto P_0c09d724;
P_0c09d724: /* original 3c5c, guest PC 0x0c09d724 */
if(!s->budget--) { s->failed_pc=0x0c09d724u; return 0; }
r[12]+=r[5];
goto P_0c09d726;
P_0c09d726: /* original 67d3, guest PC 0x0c09d726 */
if(!s->budget--) { s->failed_pc=0x0c09d726u; return 0; }
r[7]=r[13];
goto P_0c09d728;
P_0c09d728: /* original 2008, guest PC 0x0c09d728 */
if(!s->budget--) { s->failed_pc=0x0c09d728u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c09d72a;
P_0c09d72a: /* original 8d07, guest PC 0x0c09d72a */
if(!s->budget--) { s->failed_pc=0x0c09d72au; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(cond) { goto P_0c09d73c; }
goto P_0c09d72e;
P_0c09d72c: /* original 7701, guest PC 0x0c09d72c */
if(!s->budget--) { s->failed_pc=0x0c09d72cu; return 0; }
r[7]+=0x00000001u;
goto P_0c09d72e;
P_0c09d72e: /* original 6d53, guest PC 0x0c09d72e */
if(!s->budget--) { s->failed_pc=0x0c09d72eu; return 0; }
r[13]=r[5];
goto P_0c09d730;
P_0c09d730: /* original 6b73, guest PC 0x0c09d730 */
if(!s->budget--) { s->failed_pc=0x0c09d730u; return 0; }
r[11]=r[7];
goto P_0c09d732;
P_0c09d732: /* original 3d5c, guest PC 0x0c09d732 */
if(!s->budget--) { s->failed_pc=0x0c09d732u; return 0; }
r[13]+=r[5];
goto P_0c09d734;
P_0c09d734: /* original 35dc, guest PC 0x0c09d734 */
if(!s->budget--) { s->failed_pc=0x0c09d734u; return 0; }
r[5]+=r[13];
goto P_0c09d736;
P_0c09d736: /* original 4b00, guest PC 0x0c09d736 */
if(!s->budget--) { s->failed_pc=0x0c09d736u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c09d738;
P_0c09d738: /* original 7502, guest PC 0x0c09d738 */
if(!s->budget--) { s->failed_pc=0x0c09d738u; return 0; }
r[5]+=0x00000002u;
goto P_0c09d73a;
P_0c09d73a: /* original 37bc, guest PC 0x0c09d73a */
if(!s->budget--) { s->failed_pc=0x0c09d73au; return 0; }
r[7]+=r[11];
goto P_0c09d73c;
P_0c09d73c: /* original 4708, guest PC 0x0c09d73c */
if(!s->budget--) { s->failed_pc=0x0c09d73cu; return 0; }
r[7]<<=2;
goto P_0c09d73e;
P_0c09d73e: /* original 37ec, guest PC 0x0c09d73e */
if(!s->budget--) { s->failed_pc=0x0c09d73eu; return 0; }
r[7]+=r[14];
goto P_0c09d740;
P_0c09d740: /* original f478, guest PC 0x0c09d740 */
if(!s->budget--) { s->failed_pc=0x0c09d740u; return 0; }
vf3_matrix_load(s,ram,4,r[7]);
goto P_0c09d742;
P_0c09d742: /* original 7502, guest PC 0x0c09d742 */
if(!s->budget--) { s->failed_pc=0x0c09d742u; return 0; }
r[5]+=0x00000002u;
goto P_0c09d744;
P_0c09d744: /* original 4508, guest PC 0x0c09d744 */
if(!s->budget--) { s->failed_pc=0x0c09d744u; return 0; }
r[5]<<=2;
goto P_0c09d746;
P_0c09d746: /* original a057, guest PC 0x0c09d746 */
if(!s->budget--) { s->failed_pc=0x0c09d746u; return 0; }
r[14]+=r[5];
goto P_0c09d7f8;
P_0c09d748: /* original 3e5c, guest PC 0x0c09d748 */
if(!s->budget--) { s->failed_pc=0x0c09d748u; return 0; }
r[14]+=r[5];
goto P_0c09d74a;
P_0c09d74a: /* original 9070, guest PC 0x0c09d74a */
if(!s->budget--) { s->failed_pc=0x0c09d74au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d82eu,2);
goto P_0c09d74c;
P_0c09d74c: /* original 074d, guest PC 0x0c09d74c */
if(!s->budget--) { s->failed_pc=0x0c09d74cu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09d74e;
P_0c09d74e: /* original 677d, guest PC 0x0c09d74e */
if(!s->budget--) { s->failed_pc=0x0c09d74eu; return 0; }
r[7]=r[7]&65535u;
goto P_0c09d750;
P_0c09d750: /* original 4718, guest PC 0x0c09d750 */
if(!s->budget--) { s->failed_pc=0x0c09d750u; return 0; }
r[7]<<=8;
goto P_0c09d752;
P_0c09d752: /* original 84f8, guest PC 0x0c09d752 */
if(!s->budget--) { s->failed_pc=0x0c09d752u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+8,1);
goto P_0c09d754;
P_0c09d754: /* original 6b73, guest PC 0x0c09d754 */
if(!s->budget--) { s->failed_pc=0x0c09d754u; return 0; }
r[11]=r[7];
goto P_0c09d756;
P_0c09d756: /* original 53f3, guest PC 0x0c09d756 */
if(!s->budget--) { s->failed_pc=0x0c09d756u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c09d758;
P_0c09d758: /* original 6163, guest PC 0x0c09d758 */
if(!s->budget--) { s->failed_pc=0x0c09d758u; return 0; }
r[1]=r[6];
goto P_0c09d75a;
P_0c09d75a: /* original 2008, guest PC 0x0c09d75a */
if(!s->budget--) { s->failed_pc=0x0c09d75au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c09d75c;
P_0c09d75c: /* original 3b38, guest PC 0x0c09d75c */
if(!s->budget--) { s->failed_pc=0x0c09d75cu; return 0; }
r[11]-=r[3];
goto P_0c09d75e;
P_0c09d75e: /* original 8d38, guest PC 0x0c09d75e */
if(!s->budget--) { s->failed_pc=0x0c09d75eu; return 0; }
cond=r[17]&1u;
r[1]-=r[3];
if(cond) { goto P_0c09d7d2; }
goto P_0c09d762;
P_0c09d760: /* original 3138, guest PC 0x0c09d760 */
if(!s->budget--) { s->failed_pc=0x0c09d760u; return 0; }
r[1]-=r[3];
goto P_0c09d762;
P_0c09d762: /* original 415a, guest PC 0x0c09d762 */
if(!s->budget--) { s->failed_pc=0x0c09d762u; return 0; }
r[53]=r[1];
goto P_0c09d764;
P_0c09d764: /* original 67d3, guest PC 0x0c09d764 */
if(!s->budget--) { s->failed_pc=0x0c09d764u; return 0; }
r[7]=r[13];
goto P_0c09d766;
P_0c09d766: /* original 4700, guest PC 0x0c09d766 */
if(!s->budget--) { s->failed_pc=0x0c09d766u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c09d768;
P_0c09d768: /* original 62d3, guest PC 0x0c09d768 */
if(!s->budget--) { s->failed_pc=0x0c09d768u; return 0; }
r[2]=r[13];
goto P_0c09d76a;
P_0c09d76a: /* original 372c, guest PC 0x0c09d76a */
if(!s->budget--) { s->failed_pc=0x0c09d76au; return 0; }
r[7]+=r[2];
goto P_0c09d76c;
P_0c09d76c: /* original f32d, guest PC 0x0c09d76c */
if(!s->budget--) { s->failed_pc=0x0c09d76cu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c09d76e;
P_0c09d76e: /* original 4b5a, guest PC 0x0c09d76e */
if(!s->budget--) { s->failed_pc=0x0c09d76eu; return 0; }
r[53]=r[11];
goto P_0c09d770;
P_0c09d770: /* original 4708, guest PC 0x0c09d770 */
if(!s->budget--) { s->failed_pc=0x0c09d770u; return 0; }
r[7]<<=2;
goto P_0c09d772;
P_0c09d772: /* original 37ec, guest PC 0x0c09d772 */
if(!s->budget--) { s->failed_pc=0x0c09d772u; return 0; }
r[7]+=r[14];
goto P_0c09d774;
P_0c09d774: /* original f22d, guest PC 0x0c09d774 */
if(!s->budget--) { s->failed_pc=0x0c09d774u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c09d776;
P_0c09d776: /* original e004, guest PC 0x0c09d776 */
if(!s->budget--) { s->failed_pc=0x0c09d776u; return 0; }
r[0]=0x00000004u;
goto P_0c09d778;
P_0c09d778: /* original f876, guest PC 0x0c09d778 */
if(!s->budget--) { s->failed_pc=0x0c09d778u; return 0; }
vf3_matrix_load(s,ram,8,r[7]+r[0]);
goto P_0c09d77a;
P_0c09d77a: /* original e008, guest PC 0x0c09d77a */
if(!s->budget--) { s->failed_pc=0x0c09d77au; return 0; }
r[0]=0x00000008u;
goto P_0c09d77c;
P_0c09d77c: /* original f53c, guest PC 0x0c09d77c */
if(!s->budget--) { s->failed_pc=0x0c09d77cu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c09d77e;
P_0c09d77e: /* original f976, guest PC 0x0c09d77e */
if(!s->budget--) { s->failed_pc=0x0c09d77eu; return 0; }
vf3_matrix_load(s,ram,9,r[7]+r[0]);
goto P_0c09d780;
P_0c09d780: /* original e00c, guest PC 0x0c09d780 */
if(!s->budget--) { s->failed_pc=0x0c09d780u; return 0; }
r[0]=0x0000000cu;
goto P_0c09d782;
P_0c09d782: /* original f176, guest PC 0x0c09d782 */
if(!s->budget--) { s->failed_pc=0x0c09d782u; return 0; }
vf3_matrix_load(s,ram,1,r[7]+r[0]);
goto P_0c09d784;
P_0c09d784: /* original c72a, guest PC 0x0c09d784 */
if(!s->budget--) { s->failed_pc=0x0c09d784u; return 0; }
r[0]=code_base|0x0009d830u;
goto P_0c09d786;
P_0c09d786: /* original f523, guest PC 0x0c09d786 */
if(!s->budget--) { s->failed_pc=0x0c09d786u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
goto P_0c09d788;
P_0c09d788: /* original f408, guest PC 0x0c09d788 */
if(!s->budget--) { s->failed_pc=0x0c09d788u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c09d78a;
P_0c09d78a: /* original c72a, guest PC 0x0c09d78a */
if(!s->budget--) { s->failed_pc=0x0c09d78au; return 0; }
r[0]=code_base|0x0009d834u;
goto P_0c09d78c;
P_0c09d78c: /* original fa3c, guest PC 0x0c09d78c */
if(!s->budget--) { s->failed_pc=0x0c09d78cu; return 0; }
vf3_matrix_move(s,10,3);
goto P_0c09d78e;
P_0c09d78e: /* original f942, guest PC 0x0c09d78e */
if(!s->budget--) { s->failed_pc=0x0c09d78eu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[4],r[18],'*');
goto P_0c09d790;
P_0c09d790: /* original f708, guest PC 0x0c09d790 */
if(!s->budget--) { s->failed_pc=0x0c09d790u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c09d792;
P_0c09d792: /* original f842, guest PC 0x0c09d792 */
if(!s->budget--) { s->failed_pc=0x0c09d792u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'*');
goto P_0c09d794;
P_0c09d794: /* original fb78, guest PC 0x0c09d794 */
if(!s->budget--) { s->failed_pc=0x0c09d794u; return 0; }
vf3_matrix_load(s,ram,11,r[7]);
goto P_0c09d796;
P_0c09d796: /* original f49c, guest PC 0x0c09d796 */
if(!s->budget--) { s->failed_pc=0x0c09d796u; return 0; }
vf3_matrix_move(s,4,9);
goto P_0c09d798;
P_0c09d798: /* original f08c, guest PC 0x0c09d798 */
if(!s->budget--) { s->failed_pc=0x0c09d798u; return 0; }
vf3_matrix_move(s,0,8);
goto P_0c09d79a;
P_0c09d79a: /* original f65c, guest PC 0x0c09d79a */
if(!s->budget--) { s->failed_pc=0x0c09d79au; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c09d79c;
P_0c09d79c: /* original f452, guest PC 0x0c09d79c */
if(!s->budget--) { s->failed_pc=0x0c09d79cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c09d79e;
P_0c09d79e: /* original f670, guest PC 0x0c09d79e */
if(!s->budget--) { s->failed_pc=0x0c09d79eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'+');
goto P_0c09d7a0;
P_0c09d7a0: /* original f34c, guest PC 0x0c09d7a0 */
if(!s->budget--) { s->failed_pc=0x0c09d7a0u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c09d7a2;
P_0c09d7a2: /* original f36e, guest PC 0x0c09d7a2 */
if(!s->budget--) { s->failed_pc=0x0c09d7a2u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[6],fr[3],r[18]);
goto P_0c09d7a4;
P_0c09d7a4: /* original f0ac, guest PC 0x0c09d7a4 */
if(!s->budget--) { s->failed_pc=0x0c09d7a4u; return 0; }
vf3_matrix_move(s,0,10);
goto P_0c09d7a6;
P_0c09d7a6: /* original f8bc, guest PC 0x0c09d7a6 */
if(!s->budget--) { s->failed_pc=0x0c09d7a6u; return 0; }
vf3_matrix_move(s,8,11);
goto P_0c09d7a8;
P_0c09d7a8: /* original 6253, guest PC 0x0c09d7a8 */
if(!s->budget--) { s->failed_pc=0x0c09d7a8u; return 0; }
r[2]=r[5];
goto P_0c09d7aa;
P_0c09d7aa: /* original 6153, guest PC 0x0c09d7aa */
if(!s->budget--) { s->failed_pc=0x0c09d7aau; return 0; }
r[1]=r[5];
goto P_0c09d7ac;
P_0c09d7ac: /* original 4200, guest PC 0x0c09d7ac */
if(!s->budget--) { s->failed_pc=0x0c09d7acu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c09d7ae;
P_0c09d7ae: /* original 3c5c, guest PC 0x0c09d7ae */
if(!s->budget--) { s->failed_pc=0x0c09d7aeu; return 0; }
r[12]+=r[5];
goto P_0c09d7b0;
P_0c09d7b0: /* original f43c, guest PC 0x0c09d7b0 */
if(!s->budget--) { s->failed_pc=0x0c09d7b0u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c09d7b2;
P_0c09d7b2: /* original f462, guest PC 0x0c09d7b2 */
if(!s->budget--) { s->failed_pc=0x0c09d7b2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c09d7b4;
P_0c09d7b4: /* original 321c, guest PC 0x0c09d7b4 */
if(!s->budget--) { s->failed_pc=0x0c09d7b4u; return 0; }
r[2]+=r[1];
goto P_0c09d7b6;
P_0c09d7b6: /* original 6523, guest PC 0x0c09d7b6 */
if(!s->budget--) { s->failed_pc=0x0c09d7b6u; return 0; }
r[5]=r[2];
goto P_0c09d7b8;
P_0c09d7b8: /* original f84e, guest PC 0x0c09d7b8 */
if(!s->budget--) { s->failed_pc=0x0c09d7b8u; return 0; }
fr[8]=vf3_fpu_mac(fr[0],fr[4],fr[8],r[18]);
goto P_0c09d7ba;
P_0c09d7ba: /* original f46c, guest PC 0x0c09d7ba */
if(!s->budget--) { s->failed_pc=0x0c09d7bau; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c09d7bc;
P_0c09d7bc: /* original f460, guest PC 0x0c09d7bc */
if(!s->budget--) { s->failed_pc=0x0c09d7bcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'+');
goto P_0c09d7be;
P_0c09d7be: /* original f6bc, guest PC 0x0c09d7be */
if(!s->budget--) { s->failed_pc=0x0c09d7beu; return 0; }
vf3_matrix_move(s,6,11);
goto P_0c09d7c0;
P_0c09d7c0: /* original f611, guest PC 0x0c09d7c0 */
if(!s->budget--) { s->failed_pc=0x0c09d7c0u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[1],r[18],'-');
goto P_0c09d7c2;
P_0c09d7c2: /* original f05c, guest PC 0x0c09d7c2 */
if(!s->budget--) { s->failed_pc=0x0c09d7c2u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c09d7c4;
P_0c09d7c4: /* original f470, guest PC 0x0c09d7c4 */
if(!s->budget--) { s->failed_pc=0x0c09d7c4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'+');
goto P_0c09d7c6;
P_0c09d7c6: /* original f462, guest PC 0x0c09d7c6 */
if(!s->budget--) { s->failed_pc=0x0c09d7c6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c09d7c8;
P_0c09d7c8: /* original f452, guest PC 0x0c09d7c8 */
if(!s->budget--) { s->failed_pc=0x0c09d7c8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c09d7ca;
P_0c09d7ca: /* original f84e, guest PC 0x0c09d7ca */
if(!s->budget--) { s->failed_pc=0x0c09d7cau; return 0; }
fr[8]=vf3_fpu_mac(fr[0],fr[4],fr[8],r[18]);
goto P_0c09d7cc;
P_0c09d7cc: /* original f48c, guest PC 0x0c09d7cc */
if(!s->budget--) { s->failed_pc=0x0c09d7ccu; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c09d7ce;
P_0c09d7ce: /* original a010, guest PC 0x0c09d7ce */
if(!s->budget--) { s->failed_pc=0x0c09d7ceu; return 0; }
r[5]+=0x00000002u;
goto P_0c09d7f2;
P_0c09d7d0: /* original 7502, guest PC 0x0c09d7d0 */
if(!s->budget--) { s->failed_pc=0x0c09d7d0u; return 0; }
r[5]+=0x00000002u;
goto P_0c09d7d2;
P_0c09d7d2: /* original 4b5a, guest PC 0x0c09d7d2 */
if(!s->budget--) { s->failed_pc=0x0c09d7d2u; return 0; }
r[53]=r[11];
goto P_0c09d7d4;
P_0c09d7d4: /* original 67d3, guest PC 0x0c09d7d4 */
if(!s->budget--) { s->failed_pc=0x0c09d7d4u; return 0; }
r[7]=r[13];
goto P_0c09d7d6;
P_0c09d7d6: /* original 4708, guest PC 0x0c09d7d6 */
if(!s->budget--) { s->failed_pc=0x0c09d7d6u; return 0; }
r[7]<<=2;
goto P_0c09d7d8;
P_0c09d7d8: /* original 37ec, guest PC 0x0c09d7d8 */
if(!s->budget--) { s->failed_pc=0x0c09d7d8u; return 0; }
r[7]+=r[14];
goto P_0c09d7da;
P_0c09d7da: /* original f32d, guest PC 0x0c09d7da */
if(!s->budget--) { s->failed_pc=0x0c09d7dau; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c09d7dc;
P_0c09d7dc: /* original 415a, guest PC 0x0c09d7dc */
if(!s->budget--) { s->failed_pc=0x0c09d7dcu; return 0; }
r[53]=r[1];
goto P_0c09d7de;
P_0c09d7de: /* original f479, guest PC 0x0c09d7de */
if(!s->budget--) { s->failed_pc=0x0c09d7deu; return 0; }
vf3_matrix_load(s,ram,4,r[7]);
r[7]+=(r[18]&0x100000u)?8:4;
goto P_0c09d7e0;
P_0c09d7e0: /* original 3c5c, guest PC 0x0c09d7e0 */
if(!s->budget--) { s->failed_pc=0x0c09d7e0u; return 0; }
r[12]+=r[5];
goto P_0c09d7e2;
P_0c09d7e2: /* original f22d, guest PC 0x0c09d7e2 */
if(!s->budget--) { s->failed_pc=0x0c09d7e2u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c09d7e4;
P_0c09d7e4: /* original f578, guest PC 0x0c09d7e4 */
if(!s->budget--) { s->failed_pc=0x0c09d7e4u; return 0; }
vf3_matrix_load(s,ram,5,r[7]);
goto P_0c09d7e6;
P_0c09d7e6: /* original f541, guest PC 0x0c09d7e6 */
if(!s->budget--) { s->failed_pc=0x0c09d7e6u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'-');
goto P_0c09d7e8;
P_0c09d7e8: /* original f62c, guest PC 0x0c09d7e8 */
if(!s->budget--) { s->failed_pc=0x0c09d7e8u; return 0; }
vf3_matrix_move(s,6,2);
goto P_0c09d7ea;
P_0c09d7ea: /* original f633, guest PC 0x0c09d7ea */
if(!s->budget--) { s->failed_pc=0x0c09d7eau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'/');
goto P_0c09d7ec;
P_0c09d7ec: /* original f05c, guest PC 0x0c09d7ec */
if(!s->budget--) { s->failed_pc=0x0c09d7ecu; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c09d7ee;
P_0c09d7ee: /* original f72c, guest PC 0x0c09d7ee */
if(!s->budget--) { s->failed_pc=0x0c09d7eeu; return 0; }
vf3_matrix_move(s,7,2);
goto P_0c09d7f0;
P_0c09d7f0: /* original f46e, guest PC 0x0c09d7f0 */
if(!s->budget--) { s->failed_pc=0x0c09d7f0u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[6],fr[4],r[18]);
goto P_0c09d7f2;
P_0c09d7f2: /* original 7502, guest PC 0x0c09d7f2 */
if(!s->budget--) { s->failed_pc=0x0c09d7f2u; return 0; }
r[5]+=0x00000002u;
goto P_0c09d7f4;
P_0c09d7f4: /* original 4508, guest PC 0x0c09d7f4 */
if(!s->budget--) { s->failed_pc=0x0c09d7f4u; return 0; }
r[5]<<=2;
goto P_0c09d7f6;
P_0c09d7f6: /* original 3e5c, guest PC 0x0c09d7f6 */
if(!s->budget--) { s->failed_pc=0x0c09d7f6u; return 0; }
r[14]+=r[5];
goto P_0c09d7f8;
P_0c09d7f8: /* original 53f1, guest PC 0x0c09d7f8 */
if(!s->budget--) { s->failed_pc=0x0c09d7f8u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09d7fa;
P_0c09d7fa: /* original 7901, guest PC 0x0c09d7fa */
if(!s->budget--) { s->failed_pc=0x0c09d7fau; return 0; }
r[9]+=0x00000001u;
goto P_0c09d7fc;
P_0c09d7fc: /* original f34a, guest PC 0x0c09d7fc */
if(!s->budget--) { s->failed_pc=0x0c09d7fcu; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c09d7fe;
P_0c09d7fe: /* original 53f1, guest PC 0x0c09d7fe */
if(!s->budget--) { s->failed_pc=0x0c09d7feu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09d800;
P_0c09d800: /* original 7304, guest PC 0x0c09d800 */
if(!s->budget--) { s->failed_pc=0x0c09d800u; return 0; }
r[3]+=0x00000004u;
goto P_0c09d802;
P_0c09d802: /* original 1f31, guest PC 0x0c09d802 */
if(!s->budget--) { s->failed_pc=0x0c09d802u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09d804;
P_0c09d804: /* original e53f, guest PC 0x0c09d804 */
if(!s->budget--) { s->failed_pc=0x0c09d804u; return 0; }
r[5]=0x0000003fu;
goto P_0c09d806;
P_0c09d806: /* original 3952, guest PC 0x0c09d806 */
if(!s->budget--) { s->failed_pc=0x0c09d806u; return 0; }
r[17]=(r[17]&~1u)|((r[9]>=r[5])!=0);
goto P_0c09d808;
P_0c09d808: /* original 8901, guest PC 0x0c09d808 */
if(!s->budget--) { s->failed_pc=0x0c09d808u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d80e; }
goto P_0c09d80a;
P_0c09d80a: /* original af4f, guest PC 0x0c09d80a */
if(!s->budget--) { s->failed_pc=0x0c09d80au; return 0; }
goto P_0c09d6ac;
P_0c09d80c: /* original 0009, guest PC 0x0c09d80c */
if(!s->budget--) { s->failed_pc=0x0c09d80cu; return 0; }
goto P_0c09d80e;
P_0c09d80e: /* original 64f2, guest PC 0x0c09d80e */
if(!s->budget--) { s->failed_pc=0x0c09d80eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c09d810;
P_0c09d810: /* original bdfa, guest PC 0x0c09d810 */
if(!s->budget--) { s->failed_pc=0x0c09d810u; return 0; }
target=code_base|0x0c09d408u; r[16]=code_base|0x0c09d814u;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d814u) { target=s->pc; goto dispatch; }
goto P_0c09d814;
P_0c09d812: /* original 6442, guest PC 0x0c09d812 */
if(!s->budget--) { s->failed_pc=0x0c09d812u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c09d814;
P_0c09d814: /* original 53f1, guest PC 0x0c09d814 */
if(!s->budget--) { s->failed_pc=0x0c09d814u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09d816;
P_0c09d816: /* original 62f2, guest PC 0x0c09d816 */
if(!s->budget--) { s->failed_pc=0x0c09d816u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09d818;
P_0c09d818: /* original 7f14, guest PC 0x0c09d818 */
if(!s->budget--) { s->failed_pc=0x0c09d818u; return 0; }
r[15]+=0x00000014u;
goto P_0c09d81a;
P_0c09d81a: /* original 4f26, guest PC 0x0c09d81a */
if(!s->budget--) { s->failed_pc=0x0c09d81au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d81c;
P_0c09d81c: /* original 2232, guest PC 0x0c09d81c */
if(!s->budget--) { s->failed_pc=0x0c09d81cu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c09d81e;
P_0c09d81e: /* original 68f6, guest PC 0x0c09d81e */
if(!s->budget--) { s->failed_pc=0x0c09d81eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09d820;
P_0c09d820: /* original 69f6, guest PC 0x0c09d820 */
if(!s->budget--) { s->failed_pc=0x0c09d820u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09d822;
P_0c09d822: /* original 6bf6, guest PC 0x0c09d822 */
if(!s->budget--) { s->failed_pc=0x0c09d822u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09d824;
P_0c09d824: /* original 6cf6, guest PC 0x0c09d824 */
if(!s->budget--) { s->failed_pc=0x0c09d824u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09d826;
P_0c09d826: /* original 6df6, guest PC 0x0c09d826 */
if(!s->budget--) { s->failed_pc=0x0c09d826u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09d828;
P_0c09d828: /* original 000b, guest PC 0x0c09d828 */
if(!s->budget--) { s->failed_pc=0x0c09d828u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09d82a: /* original 6ef6, guest PC 0x0c09d82a */
if(!s->budget--) { s->failed_pc=0x0c09d82au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09d82cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09d82cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
