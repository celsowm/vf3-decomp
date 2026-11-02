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
int vf3_away_batch28_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05d698u: goto P_0c05d698;
case 0x0c05d69au: goto P_0c05d69a;
case 0x0c05d69cu: goto P_0c05d69c;
case 0x0c05d69eu: goto P_0c05d69e;
case 0x0c05d6a0u: goto P_0c05d6a0;
case 0x0c05d6a2u: goto P_0c05d6a2;
case 0x0c05d6a4u: goto P_0c05d6a4;
case 0x0c05d6a6u: goto P_0c05d6a6;
case 0x0c05d6a8u: goto P_0c05d6a8;
case 0x0c05d6aau: goto P_0c05d6aa;
case 0x0c05d6acu: goto P_0c05d6ac;
case 0x0c05d6aeu: goto P_0c05d6ae;
case 0x0c05d6b0u: goto P_0c05d6b0;
case 0x0c05d6b2u: goto P_0c05d6b2;
case 0x0c05d6b4u: goto P_0c05d6b4;
case 0x0c05d6b6u: goto P_0c05d6b6;
case 0x0c05d6b8u: goto P_0c05d6b8;
case 0x0c05d6bau: goto P_0c05d6ba;
case 0x0c05d6bcu: goto P_0c05d6bc;
case 0x0c05d6beu: goto P_0c05d6be;
case 0x0c05d6c0u: goto P_0c05d6c0;
case 0x0c05d6c2u: goto P_0c05d6c2;
case 0x0c05d6c4u: goto P_0c05d6c4;
case 0x0c05d6c6u: goto P_0c05d6c6;
case 0x0c05d6c8u: goto P_0c05d6c8;
case 0x0c05d6cau: goto P_0c05d6ca;
case 0x0c05d6ccu: goto P_0c05d6cc;
case 0x0c05d6ceu: goto P_0c05d6ce;
case 0x0c05d6d0u: goto P_0c05d6d0;
case 0x0c05d6d2u: goto P_0c05d6d2;
case 0x0c05d6d4u: goto P_0c05d6d4;
case 0x0c05d6d6u: goto P_0c05d6d6;
case 0x0c05d6d8u: goto P_0c05d6d8;
case 0x0c05d6dau: goto P_0c05d6da;
case 0x0c05d6dcu: goto P_0c05d6dc;
case 0x0c05d6deu: goto P_0c05d6de;
case 0x0c05d6e0u: goto P_0c05d6e0;
case 0x0c05d6e2u: goto P_0c05d6e2;
case 0x0c05d6e4u: goto P_0c05d6e4;
case 0x0c05d6e6u: goto P_0c05d6e6;
case 0x0c05d6e8u: goto P_0c05d6e8;
case 0x0c05d6eau: goto P_0c05d6ea;
case 0x0c05d6ecu: goto P_0c05d6ec;
case 0x0c05d6eeu: goto P_0c05d6ee;
case 0x0c05d6f0u: goto P_0c05d6f0;
case 0x0c05d6f2u: goto P_0c05d6f2;
case 0x0c05d6f4u: goto P_0c05d6f4;
case 0x0c05d6f6u: goto P_0c05d6f6;
case 0x0c05d6f8u: goto P_0c05d6f8;
case 0x0c05d6fau: goto P_0c05d6fa;
case 0x0c05d6fcu: goto P_0c05d6fc;
case 0x0c05d6feu: goto P_0c05d6fe;
case 0x0c05d700u: goto P_0c05d700;
case 0x0c05d702u: goto P_0c05d702;
case 0x0c05d704u: goto P_0c05d704;
case 0x0c05d706u: goto P_0c05d706;
case 0x0c05d708u: goto P_0c05d708;
case 0x0c05d70au: goto P_0c05d70a;
case 0x0c05d70cu: goto P_0c05d70c;
case 0x0c05d70eu: goto P_0c05d70e;
case 0x0c05d710u: goto P_0c05d710;
case 0x0c05d712u: goto P_0c05d712;
case 0x0c05d714u: goto P_0c05d714;
case 0x0c05d716u: goto P_0c05d716;
case 0x0c05d718u: goto P_0c05d718;
case 0x0c05d71au: goto P_0c05d71a;
case 0x0c05d71cu: goto P_0c05d71c;
case 0x0c05d71eu: goto P_0c05d71e;
case 0x0c05d720u: goto P_0c05d720;
case 0x0c05d722u: goto P_0c05d722;
case 0x0c05d724u: goto P_0c05d724;
case 0x0c05d726u: goto P_0c05d726;
case 0x0c05d728u: goto P_0c05d728;
case 0x0c05d72au: goto P_0c05d72a;
case 0x0c05d72cu: goto P_0c05d72c;
case 0x0c05d72eu: goto P_0c05d72e;
case 0x0c05d730u: goto P_0c05d730;
case 0x0c05d732u: goto P_0c05d732;
case 0x0c05d734u: goto P_0c05d734;
case 0x0c05d736u: goto P_0c05d736;
case 0x0c05d738u: goto P_0c05d738;
case 0x0c05d73au: goto P_0c05d73a;
case 0x0c05d73cu: goto P_0c05d73c;
case 0x0c05d73eu: goto P_0c05d73e;
case 0x0c05d740u: goto P_0c05d740;
case 0x0c05d742u: goto P_0c05d742;
case 0x0c05d744u: goto P_0c05d744;
case 0x0c05d746u: goto P_0c05d746;
case 0x0c05d748u: goto P_0c05d748;
case 0x0c05d74au: goto P_0c05d74a;
case 0x0c05d74cu: goto P_0c05d74c;
case 0x0c05d74eu: goto P_0c05d74e;
case 0x0c05d750u: goto P_0c05d750;
case 0x0c05d752u: goto P_0c05d752;
case 0x0c05d754u: goto P_0c05d754;
case 0x0c05d756u: goto P_0c05d756;
case 0x0c05d758u: goto P_0c05d758;
case 0x0c05d75au: goto P_0c05d75a;
case 0x0c05d75cu: goto P_0c05d75c;
case 0x0c05d75eu: goto P_0c05d75e;
case 0x0c05d760u: goto P_0c05d760;
case 0x0c05d762u: goto P_0c05d762;
case 0x0c05d764u: goto P_0c05d764;
case 0x0c05d766u: goto P_0c05d766;
case 0x0c05d768u: goto P_0c05d768;
case 0x0c05d76au: goto P_0c05d76a;
case 0x0c05d76cu: goto P_0c05d76c;
case 0x0c05d76eu: goto P_0c05d76e;
case 0x0c05d770u: goto P_0c05d770;
case 0x0c05d772u: goto P_0c05d772;
case 0x0c05d774u: goto P_0c05d774;
case 0x0c05d776u: goto P_0c05d776;
case 0x0c05d778u: goto P_0c05d778;
case 0x0c05d77au: goto P_0c05d77a;
case 0x0c05d77cu: goto P_0c05d77c;
case 0x0c05d77eu: goto P_0c05d77e;
case 0x0c05d780u: goto P_0c05d780;
case 0x0c05d782u: goto P_0c05d782;
case 0x0c05d784u: goto P_0c05d784;
case 0x0c05d786u: goto P_0c05d786;
case 0x0c05d788u: goto P_0c05d788;
case 0x0c05d78au: goto P_0c05d78a;
case 0x0c05d78cu: goto P_0c05d78c;
case 0x0c05d78eu: goto P_0c05d78e;
case 0x0c05d790u: goto P_0c05d790;
case 0x0c05d792u: goto P_0c05d792;
case 0x0c05d794u: goto P_0c05d794;
case 0x0c05d796u: goto P_0c05d796;
case 0x0c05d798u: goto P_0c05d798;
case 0x0c05d79au: goto P_0c05d79a;
case 0x0c05d79cu: goto P_0c05d79c;
case 0x0c05d79eu: goto P_0c05d79e;
case 0x0c05d7a0u: goto P_0c05d7a0;
case 0x0c05d7a2u: goto P_0c05d7a2;
case 0x0c05d7a4u: goto P_0c05d7a4;
case 0x0c05d7a6u: goto P_0c05d7a6;
case 0x0c05d7a8u: goto P_0c05d7a8;
case 0x0c05d7aau: goto P_0c05d7aa;
case 0x0c05d7acu: goto P_0c05d7ac;
case 0x0c05d7aeu: goto P_0c05d7ae;
case 0x0c05d7b0u: goto P_0c05d7b0;
case 0x0c05d7b2u: goto P_0c05d7b2;
case 0x0c05d7b4u: goto P_0c05d7b4;
case 0x0c05d7b6u: goto P_0c05d7b6;
case 0x0c05d7b8u: goto P_0c05d7b8;
case 0x0c05d7bau: goto P_0c05d7ba;
case 0x0c05d7bcu: goto P_0c05d7bc;
case 0x0c05d7beu: goto P_0c05d7be;
case 0x0c05d7c0u: goto P_0c05d7c0;
case 0x0c05d7c2u: goto P_0c05d7c2;
case 0x0c05d7c4u: goto P_0c05d7c4;
case 0x0c05d7c6u: goto P_0c05d7c6;
case 0x0c05d7c8u: goto P_0c05d7c8;
case 0x0c05d7cau: goto P_0c05d7ca;
case 0x0c05d7ccu: goto P_0c05d7cc;
case 0x0c05d7ceu: goto P_0c05d7ce;
case 0x0c05d7d0u: goto P_0c05d7d0;
case 0x0c05d7d2u: goto P_0c05d7d2;
case 0x0c05d7d4u: goto P_0c05d7d4;
case 0x0c05d7d6u: goto P_0c05d7d6;
case 0x0c05d7d8u: goto P_0c05d7d8;
case 0x0c05d7dau: goto P_0c05d7da;
case 0x0c05d7dcu: goto P_0c05d7dc;
case 0x0c05d7deu: goto P_0c05d7de;
case 0x0c05d7e0u: goto P_0c05d7e0;
case 0x0c05d7e2u: goto P_0c05d7e2;
case 0x0c05d7e4u: goto P_0c05d7e4;
case 0x0c05d7e6u: goto P_0c05d7e6;
case 0x0c05d7e8u: goto P_0c05d7e8;
case 0x0c05d7eau: goto P_0c05d7ea;
case 0x0c05d7ecu: goto P_0c05d7ec;
case 0x0c05d7eeu: goto P_0c05d7ee;
case 0x0c05d7f0u: goto P_0c05d7f0;
case 0x0c05d7f2u: goto P_0c05d7f2;
case 0x0c05d7f4u: goto P_0c05d7f4;
case 0x0c05d7f6u: goto P_0c05d7f6;
case 0x0c05d7f8u: goto P_0c05d7f8;
case 0x0c05d7fau: goto P_0c05d7fa;
case 0x0c05d7fcu: goto P_0c05d7fc;
case 0x0c05d7feu: goto P_0c05d7fe;
case 0x0c05d800u: goto P_0c05d800;
case 0x0c05d802u: goto P_0c05d802;
case 0x0c05d804u: goto P_0c05d804;
case 0x0c05d806u: goto P_0c05d806;
case 0x0c05d808u: goto P_0c05d808;
case 0x0c05d80au: goto P_0c05d80a;
case 0x0c05d80cu: goto P_0c05d80c;
case 0x0c05d80eu: goto P_0c05d80e;
case 0x0c05d810u: goto P_0c05d810;
case 0x0c05d812u: goto P_0c05d812;
case 0x0c05d814u: goto P_0c05d814;
case 0x0c05d816u: goto P_0c05d816;
case 0x0c05d818u: goto P_0c05d818;
case 0x0c05d81au: goto P_0c05d81a;
case 0x0c05d81cu: goto P_0c05d81c;
case 0x0c05d81eu: goto P_0c05d81e;
case 0x0c05d820u: goto P_0c05d820;
case 0x0c05d822u: goto P_0c05d822;
case 0x0c05d824u: goto P_0c05d824;
case 0x0c05d826u: goto P_0c05d826;
case 0x0c05d828u: goto P_0c05d828;
case 0x0c05d82au: goto P_0c05d82a;
case 0x0c05d82cu: goto P_0c05d82c;
case 0x0c05d82eu: goto P_0c05d82e;
case 0x0c05d830u: goto P_0c05d830;
case 0x0c05d832u: goto P_0c05d832;
case 0x0c05d834u: goto P_0c05d834;
case 0x0c05d836u: goto P_0c05d836;
case 0x0c05d838u: goto P_0c05d838;
case 0x0c05d83au: goto P_0c05d83a;
case 0x0c05d83cu: goto P_0c05d83c;
case 0x0c05d83eu: goto P_0c05d83e;
case 0x0c05d840u: goto P_0c05d840;
case 0x0c05d842u: goto P_0c05d842;
case 0x0c05d844u: goto P_0c05d844;
case 0x0c05d846u: goto P_0c05d846;
case 0x0c05d848u: goto P_0c05d848;
case 0x0c05d84au: goto P_0c05d84a;
case 0x0c05d84cu: goto P_0c05d84c;
case 0x0c05d84eu: goto P_0c05d84e;
case 0x0c05d850u: goto P_0c05d850;
case 0x0c05d852u: goto P_0c05d852;
case 0x0c05d854u: goto P_0c05d854;
case 0x0c05d856u: goto P_0c05d856;
case 0x0c05d858u: goto P_0c05d858;
case 0x0c05d85au: goto P_0c05d85a;
case 0x0c05d85cu: goto P_0c05d85c;
case 0x0c05d85eu: goto P_0c05d85e;
case 0x0c05d860u: goto P_0c05d860;
case 0x0c05d862u: goto P_0c05d862;
case 0x0c05d864u: goto P_0c05d864;
case 0x0c05d866u: goto P_0c05d866;
case 0x0c05d868u: goto P_0c05d868;
case 0x0c05d86au: goto P_0c05d86a;
case 0x0c05d86cu: goto P_0c05d86c;
case 0x0c05d86eu: goto P_0c05d86e;
case 0x0c05d870u: goto P_0c05d870;
case 0x0c05d872u: goto P_0c05d872;
case 0x0c05d874u: goto P_0c05d874;
case 0x0c05d876u: goto P_0c05d876;
case 0x0c05d878u: goto P_0c05d878;
case 0x0c05d87au: goto P_0c05d87a;
case 0x0c05d87cu: goto P_0c05d87c;
case 0x0c05d87eu: goto P_0c05d87e;
case 0x0c05d880u: goto P_0c05d880;
case 0x0c05d882u: goto P_0c05d882;
case 0x0c05d884u: goto P_0c05d884;
case 0x0c05d886u: goto P_0c05d886;
case 0x0c05d888u: goto P_0c05d888;
case 0x0c05d88au: goto P_0c05d88a;
case 0x0c05d88cu: goto P_0c05d88c;
case 0x0c05d88eu: goto P_0c05d88e;
case 0x0c05d890u: goto P_0c05d890;
case 0x0c05d892u: goto P_0c05d892;
case 0x0c05d894u: goto P_0c05d894;
case 0x0c05d896u: goto P_0c05d896;
case 0x0c05d898u: goto P_0c05d898;
case 0x0c05d89au: goto P_0c05d89a;
case 0x0c05d89cu: goto P_0c05d89c;
case 0x0c05d89eu: goto P_0c05d89e;
case 0x0c05d8a0u: goto P_0c05d8a0;
case 0x0c05d8a2u: goto P_0c05d8a2;
case 0x0c05d8a4u: goto P_0c05d8a4;
case 0x0c05d8a6u: goto P_0c05d8a6;
case 0x0c05d8a8u: goto P_0c05d8a8;
case 0x0c05d8aau: goto P_0c05d8aa;
case 0x0c05d8acu: goto P_0c05d8ac;
case 0x0c05d8aeu: goto P_0c05d8ae;
case 0x0c05d8b0u: goto P_0c05d8b0;
case 0x0c05d8b2u: goto P_0c05d8b2;
case 0x0c05d8b4u: goto P_0c05d8b4;
case 0x0c05d8b6u: goto P_0c05d8b6;
case 0x0c05d8b8u: goto P_0c05d8b8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05d698: /* original 2fe6, guest PC 0x0c05d698 */
if(!s->budget--) { s->failed_pc=0x0c05d698u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d69a;
P_0c05d69a: /* original 6243, guest PC 0x0c05d69a */
if(!s->budget--) { s->failed_pc=0x0c05d69au; return 0; }
r[2]=r[4];
goto P_0c05d69c;
P_0c05d69c: /* original d387, guest PC 0x0c05d69c */
if(!s->budget--) { s->failed_pc=0x0c05d69cu; return 0; }
r[3]=read(ram,0x0c05d8bcu,4);
goto P_0c05d69e;
P_0c05d69e: /* original ee00, guest PC 0x0c05d69e */
if(!s->budget--) { s->failed_pc=0x0c05d69eu; return 0; }
r[14]=0x00000000u;
goto P_0c05d6a0;
P_0c05d6a0: /* original 2fd6, guest PC 0x0c05d6a0 */
if(!s->budget--) { s->failed_pc=0x0c05d6a0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d6a2;
P_0c05d6a2: /* original 4208, guest PC 0x0c05d6a2 */
if(!s->budget--) { s->failed_pc=0x0c05d6a2u; return 0; }
r[2]<<=2;
goto P_0c05d6a4;
P_0c05d6a4: /* original 2fc6, guest PC 0x0c05d6a4 */
if(!s->budget--) { s->failed_pc=0x0c05d6a4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d6a6;
P_0c05d6a6: /* original 2fb6, guest PC 0x0c05d6a6 */
if(!s->budget--) { s->failed_pc=0x0c05d6a6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d6a8;
P_0c05d6a8: /* original 2fa6, guest PC 0x0c05d6a8 */
if(!s->budget--) { s->failed_pc=0x0c05d6a8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d6aa;
P_0c05d6aa: /* original 2f96, guest PC 0x0c05d6aa */
if(!s->budget--) { s->failed_pc=0x0c05d6aau; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d6ac;
P_0c05d6ac: /* original 2f86, guest PC 0x0c05d6ac */
if(!s->budget--) { s->failed_pc=0x0c05d6acu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d6ae;
P_0c05d6ae: /* original 7fec, guest PC 0x0c05d6ae */
if(!s->budget--) { s->failed_pc=0x0c05d6aeu; return 0; }
r[15]+=0xffffffecu;
goto P_0c05d6b0;
P_0c05d6b0: /* original 2322, guest PC 0x0c05d6b0 */
if(!s->budget--) { s->failed_pc=0x0c05d6b0u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c05d6b2;
P_0c05d6b2: /* original 6253, guest PC 0x0c05d6b2 */
if(!s->budget--) { s->failed_pc=0x0c05d6b2u; return 0; }
r[2]=r[5];
goto P_0c05d6b4;
P_0c05d6b4: /* original d182, guest PC 0x0c05d6b4 */
if(!s->budget--) { s->failed_pc=0x0c05d6b4u; return 0; }
r[1]=read(ram,0x0c05d8c0u,4);
goto P_0c05d6b6;
P_0c05d6b6: /* original 4208, guest PC 0x0c05d6b6 */
if(!s->budget--) { s->failed_pc=0x0c05d6b6u; return 0; }
r[2]<<=2;
goto P_0c05d6b8;
P_0c05d6b8: /* original 2122, guest PC 0x0c05d6b8 */
if(!s->budget--) { s->failed_pc=0x0c05d6b8u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c05d6ba;
P_0c05d6ba: /* original 6363, guest PC 0x0c05d6ba */
if(!s->budget--) { s->failed_pc=0x0c05d6bau; return 0; }
r[3]=r[6];
goto P_0c05d6bc;
P_0c05d6bc: /* original d081, guest PC 0x0c05d6bc */
if(!s->budget--) { s->failed_pc=0x0c05d6bcu; return 0; }
r[0]=read(ram,0x0c05d8c4u,4);
goto P_0c05d6be;
P_0c05d6be: /* original 4308, guest PC 0x0c05d6be */
if(!s->budget--) { s->failed_pc=0x0c05d6beu; return 0; }
r[3]<<=2;
goto P_0c05d6c0;
P_0c05d6c0: /* original 2032, guest PC 0x0c05d6c0 */
if(!s->budget--) { s->failed_pc=0x0c05d6c0u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c05d6c2;
P_0c05d6c2: /* original 6373, guest PC 0x0c05d6c2 */
if(!s->budget--) { s->failed_pc=0x0c05d6c2u; return 0; }
r[3]=r[7];
goto P_0c05d6c4;
P_0c05d6c4: /* original d280, guest PC 0x0c05d6c4 */
if(!s->budget--) { s->failed_pc=0x0c05d6c4u; return 0; }
r[2]=read(ram,0x0c05d8c8u,4);
goto P_0c05d6c6;
P_0c05d6c6: /* original 4308, guest PC 0x0c05d6c6 */
if(!s->budget--) { s->failed_pc=0x0c05d6c6u; return 0; }
r[3]<<=2;
goto P_0c05d6c8;
P_0c05d6c8: /* original 2232, guest PC 0x0c05d6c8 */
if(!s->budget--) { s->failed_pc=0x0c05d6c8u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c05d6ca;
P_0c05d6ca: /* original 710c, guest PC 0x0c05d6ca */
if(!s->budget--) { s->failed_pc=0x0c05d6cau; return 0; }
r[1]+=0x0000000cu;
goto P_0c05d6cc;
P_0c05d6cc: /* original 53fc, guest PC 0x0c05d6cc */
if(!s->budget--) { s->failed_pc=0x0c05d6ccu; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c05d6ce;
P_0c05d6ce: /* original 4308, guest PC 0x0c05d6ce */
if(!s->budget--) { s->failed_pc=0x0c05d6ceu; return 0; }
r[3]<<=2;
goto P_0c05d6d0;
P_0c05d6d0: /* original 2132, guest PC 0x0c05d6d0 */
if(!s->budget--) { s->failed_pc=0x0c05d6d0u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c05d6d2;
P_0c05d6d2: /* original 6bf3, guest PC 0x0c05d6d2 */
if(!s->budget--) { s->failed_pc=0x0c05d6d2u; return 0; }
r[11]=r[15];
goto P_0c05d6d4;
P_0c05d6d4: /* original 7b0c, guest PC 0x0c05d6d4 */
if(!s->budget--) { s->failed_pc=0x0c05d6d4u; return 0; }
r[11]+=0x0000000cu;
goto P_0c05d6d6;
P_0c05d6d6: /* original 63b3, guest PC 0x0c05d6d6 */
if(!s->budget--) { s->failed_pc=0x0c05d6d6u; return 0; }
r[3]=r[11];
goto P_0c05d6d8;
P_0c05d6d8: /* original d07c, guest PC 0x0c05d6d8 */
if(!s->budget--) { s->failed_pc=0x0c05d6d8u; return 0; }
r[0]=read(ram,0x0c05d8ccu,4);
goto P_0c05d6da;
P_0c05d6da: /* original 6de3, guest PC 0x0c05d6da */
if(!s->budget--) { s->failed_pc=0x0c05d6dau; return 0; }
r[13]=r[14];
goto P_0c05d6dc;
P_0c05d6dc: /* original d87c, guest PC 0x0c05d6dc */
if(!s->budget--) { s->failed_pc=0x0c05d6dcu; return 0; }
r[8]=read(ram,0x0c05d8d0u,4);
goto P_0c05d6de;
P_0c05d6de: /* original 6ad3, guest PC 0x0c05d6de */
if(!s->budget--) { s->failed_pc=0x0c05d6deu; return 0; }
r[10]=r[13];
goto P_0c05d6e0;
P_0c05d6e0: /* original 1f31, guest PC 0x0c05d6e0 */
if(!s->budget--) { s->failed_pc=0x0c05d6e0u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c05d6e2;
P_0c05d6e2: /* original 6202, guest PC 0x0c05d6e2 */
if(!s->budget--) { s->failed_pc=0x0c05d6e2u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c05d6e4;
P_0c05d6e4: /* original d97b, guest PC 0x0c05d6e4 */
if(!s->budget--) { s->failed_pc=0x0c05d6e4u; return 0; }
r[9]=read(ram,0x0c05d8d4u,4);
goto P_0c05d6e6;
P_0c05d6e6: /* original 2322, guest PC 0x0c05d6e6 */
if(!s->budget--) { s->failed_pc=0x0c05d6e6u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c05d6e8;
P_0c05d6e8: /* original 7304, guest PC 0x0c05d6e8 */
if(!s->budget--) { s->failed_pc=0x0c05d6e8u; return 0; }
r[3]+=0x00000004u;
goto P_0c05d6ea;
P_0c05d6ea: /* original 1f32, guest PC 0x0c05d6ea */
if(!s->budget--) { s->failed_pc=0x0c05d6eau; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c05d6ec;
P_0c05d6ec: /* original a0d6, guest PC 0x0c05d6ec */
if(!s->budget--) { s->failed_pc=0x0c05d6ecu; return 0; }
r[12]=0xfffffff8u;
goto P_0c05d89c;
P_0c05d6ee: /* original ecf8, guest PC 0x0c05d6ee */
if(!s->budget--) { s->failed_pc=0x0c05d6eeu; return 0; }
r[12]=0xfffffff8u;
goto P_0c05d6f0;
P_0c05d6f0: /* original 63d3, guest PC 0x0c05d6f0 */
if(!s->budget--) { s->failed_pc=0x0c05d6f0u; return 0; }
r[3]=r[13];
goto P_0c05d6f2;
P_0c05d6f2: /* original 4308, guest PC 0x0c05d6f2 */
if(!s->budget--) { s->failed_pc=0x0c05d6f2u; return 0; }
r[3]<<=2;
goto P_0c05d6f4;
P_0c05d6f4: /* original 33bc, guest PC 0x0c05d6f4 */
if(!s->budget--) { s->failed_pc=0x0c05d6f4u; return 0; }
r[3]+=r[11];
goto P_0c05d6f6;
P_0c05d6f6: /* original 2f32, guest PC 0x0c05d6f6 */
if(!s->budget--) { s->failed_pc=0x0c05d6f6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c05d6f8;
P_0c05d6f8: /* original 6032, guest PC 0x0c05d6f8 */
if(!s->budget--) { s->failed_pc=0x0c05d6f8u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05d6fa;
P_0c05d6fa: /* original c81f, guest PC 0x0c05d6fa */
if(!s->budget--) { s->failed_pc=0x0c05d6fau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&31u)==0)!=0);
goto P_0c05d6fc;
P_0c05d6fc: /* original 8906, guest PC 0x0c05d6fc */
if(!s->budget--) { s->failed_pc=0x0c05d6fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d70c; }
goto P_0c05d6fe;
P_0c05d6fe: /* original 6233, guest PC 0x0c05d6fe */
if(!s->budget--) { s->failed_pc=0x0c05d6feu; return 0; }
r[2]=r[3];
goto P_0c05d700;
P_0c05d700: /* original 2f32, guest PC 0x0c05d700 */
if(!s->budget--) { s->failed_pc=0x0c05d700u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c05d702;
P_0c05d702: /* original 6122, guest PC 0x0c05d702 */
if(!s->budget--) { s->failed_pc=0x0c05d702u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c05d704;
P_0c05d704: /* original 711f, guest PC 0x0c05d704 */
if(!s->budget--) { s->failed_pc=0x0c05d704u; return 0; }
r[1]+=0x0000001fu;
goto P_0c05d706;
P_0c05d706: /* original e2e0, guest PC 0x0c05d706 */
if(!s->budget--) { s->failed_pc=0x0c05d706u; return 0; }
r[2]=0xffffffe0u;
goto P_0c05d708;
P_0c05d708: /* original 2129, guest PC 0x0c05d708 */
if(!s->budget--) { s->failed_pc=0x0c05d708u; return 0; }
r[1]&=r[2];
goto P_0c05d70a;
P_0c05d70a: /* original 2312, guest PC 0x0c05d70a */
if(!s->budget--) { s->failed_pc=0x0c05d70au; return 0; }
write(ram,r[3],r[1],4);
goto P_0c05d70c;
P_0c05d70c: /* original 63d3, guest PC 0x0c05d70c */
if(!s->budget--) { s->failed_pc=0x0c05d70cu; return 0; }
r[3]=r[13];
goto P_0c05d70e;
P_0c05d70e: /* original 62d3, guest PC 0x0c05d70e */
if(!s->budget--) { s->failed_pc=0x0c05d70eu; return 0; }
r[2]=r[13];
goto P_0c05d710;
P_0c05d710: /* original 4308, guest PC 0x0c05d710 */
if(!s->budget--) { s->failed_pc=0x0c05d710u; return 0; }
r[3]<<=2;
goto P_0c05d712;
P_0c05d712: /* original 332c, guest PC 0x0c05d712 */
if(!s->budget--) { s->failed_pc=0x0c05d712u; return 0; }
r[3]+=r[2];
goto P_0c05d714;
P_0c05d714: /* original d270, guest PC 0x0c05d714 */
if(!s->budget--) { s->failed_pc=0x0c05d714u; return 0; }
r[2]=read(ram,0x0c05d8d8u,4);
goto P_0c05d716;
P_0c05d716: /* original 4308, guest PC 0x0c05d716 */
if(!s->budget--) { s->failed_pc=0x0c05d716u; return 0; }
r[3]<<=2;
goto P_0c05d718;
P_0c05d718: /* original 633e, guest PC 0x0c05d718 */
if(!s->budget--) { s->failed_pc=0x0c05d718u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c05d71a;
P_0c05d71a: /* original 338c, guest PC 0x0c05d71a */
if(!s->budget--) { s->failed_pc=0x0c05d71au; return 0; }
r[3]+=r[8];
goto P_0c05d71c;
P_0c05d71c: /* original 2f32, guest PC 0x0c05d71c */
if(!s->budget--) { s->failed_pc=0x0c05d71cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c05d71e;
P_0c05d71e: /* original 6022, guest PC 0x0c05d71e */
if(!s->budget--) { s->failed_pc=0x0c05d71eu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05d720;
P_0c05d720: /* original 8801, guest PC 0x0c05d720 */
if(!s->budget--) { s->failed_pc=0x0c05d720u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05d722;
P_0c05d722: /* original 8b06, guest PC 0x0c05d722 */
if(!s->budget--) { s->failed_pc=0x0c05d722u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d732; }
goto P_0c05d724;
P_0c05d724: /* original d16d, guest PC 0x0c05d724 */
if(!s->budget--) { s->failed_pc=0x0c05d724u; return 0; }
r[1]=read(ram,0x0c05d8dcu,4);
goto P_0c05d726;
P_0c05d726: /* original 6012, guest PC 0x0c05d726 */
if(!s->budget--) { s->failed_pc=0x0c05d726u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05d728;
P_0c05d728: /* original 8820, guest PC 0x0c05d728 */
if(!s->budget--) { s->failed_pc=0x0c05d728u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c05d72a;
P_0c05d72a: /* original 8b02, guest PC 0x0c05d72a */
if(!s->budget--) { s->failed_pc=0x0c05d72au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d732; }
goto P_0c05d72c;
P_0c05d72c: /* original 62f2, guest PC 0x0c05d72c */
if(!s->budget--) { s->failed_pc=0x0c05d72cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c05d72e;
P_0c05d72e: /* original a013, guest PC 0x0c05d72e */
if(!s->budget--) { s->failed_pc=0x0c05d72eu; return 0; }
write(ram,r[2],r[9],4);
goto P_0c05d758;
P_0c05d730: /* original 2292, guest PC 0x0c05d730 */
if(!s->budget--) { s->failed_pc=0x0c05d730u; return 0; }
write(ram,r[2],r[9],4);
goto P_0c05d732;
P_0c05d732: /* original e200, guest PC 0x0c05d732 */
if(!s->budget--) { s->failed_pc=0x0c05d732u; return 0; }
r[2]=0x00000000u;
goto P_0c05d734;
P_0c05d734: /* original 3426, guest PC 0x0c05d734 */
if(!s->budget--) { s->failed_pc=0x0c05d734u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[2])!=0);
goto P_0c05d736;
P_0c05d736: /* original 8b0d, guest PC 0x0c05d736 */
if(!s->budget--) { s->failed_pc=0x0c05d736u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d754; }
goto P_0c05d738;
P_0c05d738: /* original 61f2, guest PC 0x0c05d738 */
if(!s->budget--) { s->failed_pc=0x0c05d738u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c05d73a;
P_0c05d73a: /* original 60d3, guest PC 0x0c05d73a */
if(!s->budget--) { s->failed_pc=0x0c05d73au; return 0; }
r[0]=r[13];
goto P_0c05d73c;
P_0c05d73c: /* original 0009, guest PC 0x0c05d73c */
if(!s->budget--) { s->failed_pc=0x0c05d73cu; return 0; }
goto P_0c05d73e;
P_0c05d73e: /* original 4008, guest PC 0x0c05d73e */
if(!s->budget--) { s->failed_pc=0x0c05d73eu; return 0; }
r[0]<<=2;
goto P_0c05d740;
P_0c05d740: /* original 03be, guest PC 0x0c05d740 */
if(!s->budget--) { s->failed_pc=0x0c05d740u; return 0; }
r[3]=read(ram,r[11]+r[0],4);
goto P_0c05d742;
P_0c05d742: /* original 60e3, guest PC 0x0c05d742 */
if(!s->budget--) { s->failed_pc=0x0c05d742u; return 0; }
r[0]=r[14];
goto P_0c05d744;
P_0c05d744: /* original 0009, guest PC 0x0c05d744 */
if(!s->budget--) { s->failed_pc=0x0c05d744u; return 0; }
goto P_0c05d746;
P_0c05d746: /* original 4008, guest PC 0x0c05d746 */
if(!s->budget--) { s->failed_pc=0x0c05d746u; return 0; }
r[0]<<=2;
goto P_0c05d748;
P_0c05d748: /* original 330c, guest PC 0x0c05d748 */
if(!s->budget--) { s->failed_pc=0x0c05d748u; return 0; }
r[3]+=r[0];
goto P_0c05d74a;
P_0c05d74a: /* original 3e4c, guest PC 0x0c05d74a */
if(!s->budget--) { s->failed_pc=0x0c05d74au; return 0; }
r[14]+=r[4];
goto P_0c05d74c;
P_0c05d74c: /* original 2132, guest PC 0x0c05d74c */
if(!s->budget--) { s->failed_pc=0x0c05d74cu; return 0; }
write(ram,r[1],r[3],4);
goto P_0c05d74e;
P_0c05d74e: /* original 7e17, guest PC 0x0c05d74e */
if(!s->budget--) { s->failed_pc=0x0c05d74eu; return 0; }
r[14]+=0x00000017u;
goto P_0c05d750;
P_0c05d750: /* original a002, guest PC 0x0c05d750 */
if(!s->budget--) { s->failed_pc=0x0c05d750u; return 0; }
r[14]&=r[12];
goto P_0c05d758;
P_0c05d752: /* original 2ec9, guest PC 0x0c05d752 */
if(!s->budget--) { s->failed_pc=0x0c05d752u; return 0; }
r[14]&=r[12];
goto P_0c05d754;
P_0c05d754: /* original 61f2, guest PC 0x0c05d754 */
if(!s->budget--) { s->failed_pc=0x0c05d754u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c05d756;
P_0c05d756: /* original 21a2, guest PC 0x0c05d756 */
if(!s->budget--) { s->failed_pc=0x0c05d756u; return 0; }
write(ram,r[1],r[10],4);
goto P_0c05d758;
P_0c05d758: /* original 63d3, guest PC 0x0c05d758 */
if(!s->budget--) { s->failed_pc=0x0c05d758u; return 0; }
r[3]=r[13];
goto P_0c05d75a;
P_0c05d75a: /* original 62d3, guest PC 0x0c05d75a */
if(!s->budget--) { s->failed_pc=0x0c05d75au; return 0; }
r[2]=r[13];
goto P_0c05d75c;
P_0c05d75c: /* original 4308, guest PC 0x0c05d75c */
if(!s->budget--) { s->failed_pc=0x0c05d75cu; return 0; }
r[3]<<=2;
goto P_0c05d75e;
P_0c05d75e: /* original 332c, guest PC 0x0c05d75e */
if(!s->budget--) { s->failed_pc=0x0c05d75eu; return 0; }
r[3]+=r[2];
goto P_0c05d760;
P_0c05d760: /* original d25d, guest PC 0x0c05d760 */
if(!s->budget--) { s->failed_pc=0x0c05d760u; return 0; }
r[2]=read(ram,0x0c05d8d8u,4);
goto P_0c05d762;
P_0c05d762: /* original 4308, guest PC 0x0c05d762 */
if(!s->budget--) { s->failed_pc=0x0c05d762u; return 0; }
r[3]<<=2;
goto P_0c05d764;
P_0c05d764: /* original 633e, guest PC 0x0c05d764 */
if(!s->budget--) { s->failed_pc=0x0c05d764u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c05d766;
P_0c05d766: /* original 338c, guest PC 0x0c05d766 */
if(!s->budget--) { s->failed_pc=0x0c05d766u; return 0; }
r[3]+=r[8];
goto P_0c05d768;
P_0c05d768: /* original 2f32, guest PC 0x0c05d768 */
if(!s->budget--) { s->failed_pc=0x0c05d768u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c05d76a;
P_0c05d76a: /* original 6022, guest PC 0x0c05d76a */
if(!s->budget--) { s->failed_pc=0x0c05d76au; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05d76c;
P_0c05d76c: /* original 8801, guest PC 0x0c05d76c */
if(!s->budget--) { s->failed_pc=0x0c05d76cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05d76e;
P_0c05d76e: /* original 8b06, guest PC 0x0c05d76e */
if(!s->budget--) { s->failed_pc=0x0c05d76eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d77e; }
goto P_0c05d770;
P_0c05d770: /* original d15a, guest PC 0x0c05d770 */
if(!s->budget--) { s->failed_pc=0x0c05d770u; return 0; }
r[1]=read(ram,0x0c05d8dcu,4);
goto P_0c05d772;
P_0c05d772: /* original 6012, guest PC 0x0c05d772 */
if(!s->budget--) { s->failed_pc=0x0c05d772u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05d774;
P_0c05d774: /* original 8821, guest PC 0x0c05d774 */
if(!s->budget--) { s->failed_pc=0x0c05d774u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000021u)!=0);
goto P_0c05d776;
P_0c05d776: /* original 8b02, guest PC 0x0c05d776 */
if(!s->budget--) { s->failed_pc=0x0c05d776u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d77e; }
goto P_0c05d778;
P_0c05d778: /* original 62f2, guest PC 0x0c05d778 */
if(!s->budget--) { s->failed_pc=0x0c05d778u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c05d77a;
P_0c05d77a: /* original a013, guest PC 0x0c05d77a */
if(!s->budget--) { s->failed_pc=0x0c05d77au; return 0; }
write(ram,r[2]+4,r[9],4);
goto P_0c05d7a4;
P_0c05d77c: /* original 1291, guest PC 0x0c05d77c */
if(!s->budget--) { s->failed_pc=0x0c05d77cu; return 0; }
write(ram,r[2]+4,r[9],4);
goto P_0c05d77e;
P_0c05d77e: /* original e200, guest PC 0x0c05d77e */
if(!s->budget--) { s->failed_pc=0x0c05d77eu; return 0; }
r[2]=0x00000000u;
goto P_0c05d780;
P_0c05d780: /* original 3526, guest PC 0x0c05d780 */
if(!s->budget--) { s->failed_pc=0x0c05d780u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[2])!=0);
goto P_0c05d782;
P_0c05d782: /* original 8b0d, guest PC 0x0c05d782 */
if(!s->budget--) { s->failed_pc=0x0c05d782u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d7a0; }
goto P_0c05d784;
P_0c05d784: /* original 61f2, guest PC 0x0c05d784 */
if(!s->budget--) { s->failed_pc=0x0c05d784u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c05d786;
P_0c05d786: /* original 60d3, guest PC 0x0c05d786 */
if(!s->budget--) { s->failed_pc=0x0c05d786u; return 0; }
r[0]=r[13];
goto P_0c05d788;
P_0c05d788: /* original 0009, guest PC 0x0c05d788 */
if(!s->budget--) { s->failed_pc=0x0c05d788u; return 0; }
goto P_0c05d78a;
P_0c05d78a: /* original 4008, guest PC 0x0c05d78a */
if(!s->budget--) { s->failed_pc=0x0c05d78au; return 0; }
r[0]<<=2;
goto P_0c05d78c;
P_0c05d78c: /* original 03be, guest PC 0x0c05d78c */
if(!s->budget--) { s->failed_pc=0x0c05d78cu; return 0; }
r[3]=read(ram,r[11]+r[0],4);
goto P_0c05d78e;
P_0c05d78e: /* original 60e3, guest PC 0x0c05d78e */
if(!s->budget--) { s->failed_pc=0x0c05d78eu; return 0; }
r[0]=r[14];
goto P_0c05d790;
P_0c05d790: /* original 0009, guest PC 0x0c05d790 */
if(!s->budget--) { s->failed_pc=0x0c05d790u; return 0; }
goto P_0c05d792;
P_0c05d792: /* original 4008, guest PC 0x0c05d792 */
if(!s->budget--) { s->failed_pc=0x0c05d792u; return 0; }
r[0]<<=2;
goto P_0c05d794;
P_0c05d794: /* original 330c, guest PC 0x0c05d794 */
if(!s->budget--) { s->failed_pc=0x0c05d794u; return 0; }
r[3]+=r[0];
goto P_0c05d796;
P_0c05d796: /* original 3e5c, guest PC 0x0c05d796 */
if(!s->budget--) { s->failed_pc=0x0c05d796u; return 0; }
r[14]+=r[5];
goto P_0c05d798;
P_0c05d798: /* original 1131, guest PC 0x0c05d798 */
if(!s->budget--) { s->failed_pc=0x0c05d798u; return 0; }
write(ram,r[1]+4,r[3],4);
goto P_0c05d79a;
P_0c05d79a: /* original 7e17, guest PC 0x0c05d79a */
if(!s->budget--) { s->failed_pc=0x0c05d79au; return 0; }
r[14]+=0x00000017u;
goto P_0c05d79c;
P_0c05d79c: /* original a002, guest PC 0x0c05d79c */
if(!s->budget--) { s->failed_pc=0x0c05d79cu; return 0; }
r[14]&=r[12];
goto P_0c05d7a4;
P_0c05d79e: /* original 2ec9, guest PC 0x0c05d79e */
if(!s->budget--) { s->failed_pc=0x0c05d79eu; return 0; }
r[14]&=r[12];
goto P_0c05d7a0;
P_0c05d7a0: /* original 61f2, guest PC 0x0c05d7a0 */
if(!s->budget--) { s->failed_pc=0x0c05d7a0u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c05d7a2;
P_0c05d7a2: /* original 11a1, guest PC 0x0c05d7a2 */
if(!s->budget--) { s->failed_pc=0x0c05d7a2u; return 0; }
write(ram,r[1]+4,r[10],4);
goto P_0c05d7a4;
P_0c05d7a4: /* original 63d3, guest PC 0x0c05d7a4 */
if(!s->budget--) { s->failed_pc=0x0c05d7a4u; return 0; }
r[3]=r[13];
goto P_0c05d7a6;
P_0c05d7a6: /* original 62d3, guest PC 0x0c05d7a6 */
if(!s->budget--) { s->failed_pc=0x0c05d7a6u; return 0; }
r[2]=r[13];
goto P_0c05d7a8;
P_0c05d7a8: /* original 4308, guest PC 0x0c05d7a8 */
if(!s->budget--) { s->failed_pc=0x0c05d7a8u; return 0; }
r[3]<<=2;
goto P_0c05d7aa;
P_0c05d7aa: /* original 332c, guest PC 0x0c05d7aa */
if(!s->budget--) { s->failed_pc=0x0c05d7aau; return 0; }
r[3]+=r[2];
goto P_0c05d7ac;
P_0c05d7ac: /* original d24a, guest PC 0x0c05d7ac */
if(!s->budget--) { s->failed_pc=0x0c05d7acu; return 0; }
r[2]=read(ram,0x0c05d8d8u,4);
goto P_0c05d7ae;
P_0c05d7ae: /* original 4308, guest PC 0x0c05d7ae */
if(!s->budget--) { s->failed_pc=0x0c05d7aeu; return 0; }
r[3]<<=2;
goto P_0c05d7b0;
P_0c05d7b0: /* original 633e, guest PC 0x0c05d7b0 */
if(!s->budget--) { s->failed_pc=0x0c05d7b0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c05d7b2;
P_0c05d7b2: /* original 338c, guest PC 0x0c05d7b2 */
if(!s->budget--) { s->failed_pc=0x0c05d7b2u; return 0; }
r[3]+=r[8];
goto P_0c05d7b4;
P_0c05d7b4: /* original 2f32, guest PC 0x0c05d7b4 */
if(!s->budget--) { s->failed_pc=0x0c05d7b4u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c05d7b6;
P_0c05d7b6: /* original 6022, guest PC 0x0c05d7b6 */
if(!s->budget--) { s->failed_pc=0x0c05d7b6u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05d7b8;
P_0c05d7b8: /* original 8801, guest PC 0x0c05d7b8 */
if(!s->budget--) { s->failed_pc=0x0c05d7b8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05d7ba;
P_0c05d7ba: /* original 8b06, guest PC 0x0c05d7ba */
if(!s->budget--) { s->failed_pc=0x0c05d7bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d7ca; }
goto P_0c05d7bc;
P_0c05d7bc: /* original d147, guest PC 0x0c05d7bc */
if(!s->budget--) { s->failed_pc=0x0c05d7bcu; return 0; }
r[1]=read(ram,0x0c05d8dcu,4);
goto P_0c05d7be;
P_0c05d7be: /* original 6012, guest PC 0x0c05d7be */
if(!s->budget--) { s->failed_pc=0x0c05d7beu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05d7c0;
P_0c05d7c0: /* original 8822, guest PC 0x0c05d7c0 */
if(!s->budget--) { s->failed_pc=0x0c05d7c0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000022u)!=0);
goto P_0c05d7c2;
P_0c05d7c2: /* original 8b02, guest PC 0x0c05d7c2 */
if(!s->budget--) { s->failed_pc=0x0c05d7c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d7ca; }
goto P_0c05d7c4;
P_0c05d7c4: /* original 62f2, guest PC 0x0c05d7c4 */
if(!s->budget--) { s->failed_pc=0x0c05d7c4u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c05d7c6;
P_0c05d7c6: /* original a013, guest PC 0x0c05d7c6 */
if(!s->budget--) { s->failed_pc=0x0c05d7c6u; return 0; }
write(ram,r[2]+8,r[9],4);
goto P_0c05d7f0;
P_0c05d7c8: /* original 1292, guest PC 0x0c05d7c8 */
if(!s->budget--) { s->failed_pc=0x0c05d7c8u; return 0; }
write(ram,r[2]+8,r[9],4);
goto P_0c05d7ca;
P_0c05d7ca: /* original e200, guest PC 0x0c05d7ca */
if(!s->budget--) { s->failed_pc=0x0c05d7cau; return 0; }
r[2]=0x00000000u;
goto P_0c05d7cc;
P_0c05d7cc: /* original 3626, guest PC 0x0c05d7cc */
if(!s->budget--) { s->failed_pc=0x0c05d7ccu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>r[2])!=0);
goto P_0c05d7ce;
P_0c05d7ce: /* original 8b0d, guest PC 0x0c05d7ce */
if(!s->budget--) { s->failed_pc=0x0c05d7ceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d7ec; }
goto P_0c05d7d0;
P_0c05d7d0: /* original 61f2, guest PC 0x0c05d7d0 */
if(!s->budget--) { s->failed_pc=0x0c05d7d0u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c05d7d2;
P_0c05d7d2: /* original 60d3, guest PC 0x0c05d7d2 */
if(!s->budget--) { s->failed_pc=0x0c05d7d2u; return 0; }
r[0]=r[13];
goto P_0c05d7d4;
P_0c05d7d4: /* original 0009, guest PC 0x0c05d7d4 */
if(!s->budget--) { s->failed_pc=0x0c05d7d4u; return 0; }
goto P_0c05d7d6;
P_0c05d7d6: /* original 4008, guest PC 0x0c05d7d6 */
if(!s->budget--) { s->failed_pc=0x0c05d7d6u; return 0; }
r[0]<<=2;
goto P_0c05d7d8;
P_0c05d7d8: /* original 03be, guest PC 0x0c05d7d8 */
if(!s->budget--) { s->failed_pc=0x0c05d7d8u; return 0; }
r[3]=read(ram,r[11]+r[0],4);
goto P_0c05d7da;
P_0c05d7da: /* original 60e3, guest PC 0x0c05d7da */
if(!s->budget--) { s->failed_pc=0x0c05d7dau; return 0; }
r[0]=r[14];
goto P_0c05d7dc;
P_0c05d7dc: /* original 0009, guest PC 0x0c05d7dc */
if(!s->budget--) { s->failed_pc=0x0c05d7dcu; return 0; }
goto P_0c05d7de;
P_0c05d7de: /* original 4008, guest PC 0x0c05d7de */
if(!s->budget--) { s->failed_pc=0x0c05d7deu; return 0; }
r[0]<<=2;
goto P_0c05d7e0;
P_0c05d7e0: /* original 330c, guest PC 0x0c05d7e0 */
if(!s->budget--) { s->failed_pc=0x0c05d7e0u; return 0; }
r[3]+=r[0];
goto P_0c05d7e2;
P_0c05d7e2: /* original 3e6c, guest PC 0x0c05d7e2 */
if(!s->budget--) { s->failed_pc=0x0c05d7e2u; return 0; }
r[14]+=r[6];
goto P_0c05d7e4;
P_0c05d7e4: /* original 1132, guest PC 0x0c05d7e4 */
if(!s->budget--) { s->failed_pc=0x0c05d7e4u; return 0; }
write(ram,r[1]+8,r[3],4);
goto P_0c05d7e6;
P_0c05d7e6: /* original 7e17, guest PC 0x0c05d7e6 */
if(!s->budget--) { s->failed_pc=0x0c05d7e6u; return 0; }
r[14]+=0x00000017u;
goto P_0c05d7e8;
P_0c05d7e8: /* original a002, guest PC 0x0c05d7e8 */
if(!s->budget--) { s->failed_pc=0x0c05d7e8u; return 0; }
r[14]&=r[12];
goto P_0c05d7f0;
P_0c05d7ea: /* original 2ec9, guest PC 0x0c05d7ea */
if(!s->budget--) { s->failed_pc=0x0c05d7eau; return 0; }
r[14]&=r[12];
goto P_0c05d7ec;
P_0c05d7ec: /* original 61f2, guest PC 0x0c05d7ec */
if(!s->budget--) { s->failed_pc=0x0c05d7ecu; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c05d7ee;
P_0c05d7ee: /* original 11a2, guest PC 0x0c05d7ee */
if(!s->budget--) { s->failed_pc=0x0c05d7eeu; return 0; }
write(ram,r[1]+8,r[10],4);
goto P_0c05d7f0;
P_0c05d7f0: /* original 63d3, guest PC 0x0c05d7f0 */
if(!s->budget--) { s->failed_pc=0x0c05d7f0u; return 0; }
r[3]=r[13];
goto P_0c05d7f2;
P_0c05d7f2: /* original 62d3, guest PC 0x0c05d7f2 */
if(!s->budget--) { s->failed_pc=0x0c05d7f2u; return 0; }
r[2]=r[13];
goto P_0c05d7f4;
P_0c05d7f4: /* original 4308, guest PC 0x0c05d7f4 */
if(!s->budget--) { s->failed_pc=0x0c05d7f4u; return 0; }
r[3]<<=2;
goto P_0c05d7f6;
P_0c05d7f6: /* original 332c, guest PC 0x0c05d7f6 */
if(!s->budget--) { s->failed_pc=0x0c05d7f6u; return 0; }
r[3]+=r[2];
goto P_0c05d7f8;
P_0c05d7f8: /* original d237, guest PC 0x0c05d7f8 */
if(!s->budget--) { s->failed_pc=0x0c05d7f8u; return 0; }
r[2]=read(ram,0x0c05d8d8u,4);
goto P_0c05d7fa;
P_0c05d7fa: /* original 4308, guest PC 0x0c05d7fa */
if(!s->budget--) { s->failed_pc=0x0c05d7fau; return 0; }
r[3]<<=2;
goto P_0c05d7fc;
P_0c05d7fc: /* original 633e, guest PC 0x0c05d7fc */
if(!s->budget--) { s->failed_pc=0x0c05d7fcu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c05d7fe;
P_0c05d7fe: /* original 338c, guest PC 0x0c05d7fe */
if(!s->budget--) { s->failed_pc=0x0c05d7feu; return 0; }
r[3]+=r[8];
goto P_0c05d800;
P_0c05d800: /* original 2f32, guest PC 0x0c05d800 */
if(!s->budget--) { s->failed_pc=0x0c05d800u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c05d802;
P_0c05d802: /* original 6022, guest PC 0x0c05d802 */
if(!s->budget--) { s->failed_pc=0x0c05d802u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05d804;
P_0c05d804: /* original 8801, guest PC 0x0c05d804 */
if(!s->budget--) { s->failed_pc=0x0c05d804u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05d806;
P_0c05d806: /* original 8b06, guest PC 0x0c05d806 */
if(!s->budget--) { s->failed_pc=0x0c05d806u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d816; }
goto P_0c05d808;
P_0c05d808: /* original d134, guest PC 0x0c05d808 */
if(!s->budget--) { s->failed_pc=0x0c05d808u; return 0; }
r[1]=read(ram,0x0c05d8dcu,4);
goto P_0c05d80a;
P_0c05d80a: /* original 6012, guest PC 0x0c05d80a */
if(!s->budget--) { s->failed_pc=0x0c05d80au; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05d80c;
P_0c05d80c: /* original 8823, guest PC 0x0c05d80c */
if(!s->budget--) { s->failed_pc=0x0c05d80cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000023u)!=0);
goto P_0c05d80e;
P_0c05d80e: /* original 8b02, guest PC 0x0c05d80e */
if(!s->budget--) { s->failed_pc=0x0c05d80eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d816; }
goto P_0c05d810;
P_0c05d810: /* original 62f2, guest PC 0x0c05d810 */
if(!s->budget--) { s->failed_pc=0x0c05d810u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c05d812;
P_0c05d812: /* original a013, guest PC 0x0c05d812 */
if(!s->budget--) { s->failed_pc=0x0c05d812u; return 0; }
write(ram,r[2]+12,r[9],4);
goto P_0c05d83c;
P_0c05d814: /* original 1293, guest PC 0x0c05d814 */
if(!s->budget--) { s->failed_pc=0x0c05d814u; return 0; }
write(ram,r[2]+12,r[9],4);
goto P_0c05d816;
P_0c05d816: /* original e200, guest PC 0x0c05d816 */
if(!s->budget--) { s->failed_pc=0x0c05d816u; return 0; }
r[2]=0x00000000u;
goto P_0c05d818;
P_0c05d818: /* original 3726, guest PC 0x0c05d818 */
if(!s->budget--) { s->failed_pc=0x0c05d818u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>r[2])!=0);
goto P_0c05d81a;
P_0c05d81a: /* original 8b0d, guest PC 0x0c05d81a */
if(!s->budget--) { s->failed_pc=0x0c05d81au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d838; }
goto P_0c05d81c;
P_0c05d81c: /* original 61f2, guest PC 0x0c05d81c */
if(!s->budget--) { s->failed_pc=0x0c05d81cu; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c05d81e;
P_0c05d81e: /* original 60d3, guest PC 0x0c05d81e */
if(!s->budget--) { s->failed_pc=0x0c05d81eu; return 0; }
r[0]=r[13];
goto P_0c05d820;
P_0c05d820: /* original 0009, guest PC 0x0c05d820 */
if(!s->budget--) { s->failed_pc=0x0c05d820u; return 0; }
goto P_0c05d822;
P_0c05d822: /* original 4008, guest PC 0x0c05d822 */
if(!s->budget--) { s->failed_pc=0x0c05d822u; return 0; }
r[0]<<=2;
goto P_0c05d824;
P_0c05d824: /* original 03be, guest PC 0x0c05d824 */
if(!s->budget--) { s->failed_pc=0x0c05d824u; return 0; }
r[3]=read(ram,r[11]+r[0],4);
goto P_0c05d826;
P_0c05d826: /* original 60e3, guest PC 0x0c05d826 */
if(!s->budget--) { s->failed_pc=0x0c05d826u; return 0; }
r[0]=r[14];
goto P_0c05d828;
P_0c05d828: /* original 0009, guest PC 0x0c05d828 */
if(!s->budget--) { s->failed_pc=0x0c05d828u; return 0; }
goto P_0c05d82a;
P_0c05d82a: /* original 4008, guest PC 0x0c05d82a */
if(!s->budget--) { s->failed_pc=0x0c05d82au; return 0; }
r[0]<<=2;
goto P_0c05d82c;
P_0c05d82c: /* original 330c, guest PC 0x0c05d82c */
if(!s->budget--) { s->failed_pc=0x0c05d82cu; return 0; }
r[3]+=r[0];
goto P_0c05d82e;
P_0c05d82e: /* original 3e7c, guest PC 0x0c05d82e */
if(!s->budget--) { s->failed_pc=0x0c05d82eu; return 0; }
r[14]+=r[7];
goto P_0c05d830;
P_0c05d830: /* original 1133, guest PC 0x0c05d830 */
if(!s->budget--) { s->failed_pc=0x0c05d830u; return 0; }
write(ram,r[1]+12,r[3],4);
goto P_0c05d832;
P_0c05d832: /* original 7e17, guest PC 0x0c05d832 */
if(!s->budget--) { s->failed_pc=0x0c05d832u; return 0; }
r[14]+=0x00000017u;
goto P_0c05d834;
P_0c05d834: /* original a002, guest PC 0x0c05d834 */
if(!s->budget--) { s->failed_pc=0x0c05d834u; return 0; }
r[14]&=r[12];
goto P_0c05d83c;
P_0c05d836: /* original 2ec9, guest PC 0x0c05d836 */
if(!s->budget--) { s->failed_pc=0x0c05d836u; return 0; }
r[14]&=r[12];
goto P_0c05d838;
P_0c05d838: /* original 61f2, guest PC 0x0c05d838 */
if(!s->budget--) { s->failed_pc=0x0c05d838u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c05d83a;
P_0c05d83a: /* original 11a3, guest PC 0x0c05d83a */
if(!s->budget--) { s->failed_pc=0x0c05d83au; return 0; }
write(ram,r[1]+12,r[10],4);
goto P_0c05d83c;
P_0c05d83c: /* original 63d3, guest PC 0x0c05d83c */
if(!s->budget--) { s->failed_pc=0x0c05d83cu; return 0; }
r[3]=r[13];
goto P_0c05d83e;
P_0c05d83e: /* original 62d3, guest PC 0x0c05d83e */
if(!s->budget--) { s->failed_pc=0x0c05d83eu; return 0; }
r[2]=r[13];
goto P_0c05d840;
P_0c05d840: /* original 4308, guest PC 0x0c05d840 */
if(!s->budget--) { s->failed_pc=0x0c05d840u; return 0; }
r[3]<<=2;
goto P_0c05d842;
P_0c05d842: /* original 332c, guest PC 0x0c05d842 */
if(!s->budget--) { s->failed_pc=0x0c05d842u; return 0; }
r[3]+=r[2];
goto P_0c05d844;
P_0c05d844: /* original d224, guest PC 0x0c05d844 */
if(!s->budget--) { s->failed_pc=0x0c05d844u; return 0; }
r[2]=read(ram,0x0c05d8d8u,4);
goto P_0c05d846;
P_0c05d846: /* original 4308, guest PC 0x0c05d846 */
if(!s->budget--) { s->failed_pc=0x0c05d846u; return 0; }
r[3]<<=2;
goto P_0c05d848;
P_0c05d848: /* original 633e, guest PC 0x0c05d848 */
if(!s->budget--) { s->failed_pc=0x0c05d848u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c05d84a;
P_0c05d84a: /* original 338c, guest PC 0x0c05d84a */
if(!s->budget--) { s->failed_pc=0x0c05d84au; return 0; }
r[3]+=r[8];
goto P_0c05d84c;
P_0c05d84c: /* original 2f32, guest PC 0x0c05d84c */
if(!s->budget--) { s->failed_pc=0x0c05d84cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c05d84e;
P_0c05d84e: /* original 6022, guest PC 0x0c05d84e */
if(!s->budget--) { s->failed_pc=0x0c05d84eu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05d850;
P_0c05d850: /* original 8801, guest PC 0x0c05d850 */
if(!s->budget--) { s->failed_pc=0x0c05d850u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05d852;
P_0c05d852: /* original 8b06, guest PC 0x0c05d852 */
if(!s->budget--) { s->failed_pc=0x0c05d852u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d862; }
goto P_0c05d854;
P_0c05d854: /* original d121, guest PC 0x0c05d854 */
if(!s->budget--) { s->failed_pc=0x0c05d854u; return 0; }
r[1]=read(ram,0x0c05d8dcu,4);
goto P_0c05d856;
P_0c05d856: /* original 6012, guest PC 0x0c05d856 */
if(!s->budget--) { s->failed_pc=0x0c05d856u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05d858;
P_0c05d858: /* original 8824, guest PC 0x0c05d858 */
if(!s->budget--) { s->failed_pc=0x0c05d858u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000024u)!=0);
goto P_0c05d85a;
P_0c05d85a: /* original 8b02, guest PC 0x0c05d85a */
if(!s->budget--) { s->failed_pc=0x0c05d85au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d862; }
goto P_0c05d85c;
P_0c05d85c: /* original 62f2, guest PC 0x0c05d85c */
if(!s->budget--) { s->failed_pc=0x0c05d85cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c05d85e;
P_0c05d85e: /* original a015, guest PC 0x0c05d85e */
if(!s->budget--) { s->failed_pc=0x0c05d85eu; return 0; }
write(ram,r[2]+16,r[9],4);
goto P_0c05d88c;
P_0c05d860: /* original 1294, guest PC 0x0c05d860 */
if(!s->budget--) { s->failed_pc=0x0c05d860u; return 0; }
write(ram,r[2]+16,r[9],4);
goto P_0c05d862;
P_0c05d862: /* original e200, guest PC 0x0c05d862 */
if(!s->budget--) { s->failed_pc=0x0c05d862u; return 0; }
r[2]=0x00000000u;
goto P_0c05d864;
P_0c05d864: /* original 53fc, guest PC 0x0c05d864 */
if(!s->budget--) { s->failed_pc=0x0c05d864u; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c05d866;
P_0c05d866: /* original 3326, guest PC 0x0c05d866 */
if(!s->budget--) { s->failed_pc=0x0c05d866u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[2])!=0);
goto P_0c05d868;
P_0c05d868: /* original 8b0e, guest PC 0x0c05d868 */
if(!s->budget--) { s->failed_pc=0x0c05d868u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d888; }
goto P_0c05d86a;
P_0c05d86a: /* original 63f2, guest PC 0x0c05d86a */
if(!s->budget--) { s->failed_pc=0x0c05d86au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c05d86c;
P_0c05d86c: /* original 60d3, guest PC 0x0c05d86c */
if(!s->budget--) { s->failed_pc=0x0c05d86cu; return 0; }
r[0]=r[13];
goto P_0c05d86e;
P_0c05d86e: /* original 0009, guest PC 0x0c05d86e */
if(!s->budget--) { s->failed_pc=0x0c05d86eu; return 0; }
goto P_0c05d870;
P_0c05d870: /* original 4008, guest PC 0x0c05d870 */
if(!s->budget--) { s->failed_pc=0x0c05d870u; return 0; }
r[0]<<=2;
goto P_0c05d872;
P_0c05d872: /* original 01be, guest PC 0x0c05d872 */
if(!s->budget--) { s->failed_pc=0x0c05d872u; return 0; }
r[1]=read(ram,r[11]+r[0],4);
goto P_0c05d874;
P_0c05d874: /* original 60e3, guest PC 0x0c05d874 */
if(!s->budget--) { s->failed_pc=0x0c05d874u; return 0; }
r[0]=r[14];
goto P_0c05d876;
P_0c05d876: /* original 0009, guest PC 0x0c05d876 */
if(!s->budget--) { s->failed_pc=0x0c05d876u; return 0; }
goto P_0c05d878;
P_0c05d878: /* original 4008, guest PC 0x0c05d878 */
if(!s->budget--) { s->failed_pc=0x0c05d878u; return 0; }
r[0]<<=2;
goto P_0c05d87a;
P_0c05d87a: /* original 310c, guest PC 0x0c05d87a */
if(!s->budget--) { s->failed_pc=0x0c05d87au; return 0; }
r[1]+=r[0];
goto P_0c05d87c;
P_0c05d87c: /* original 1314, guest PC 0x0c05d87c */
if(!s->budget--) { s->failed_pc=0x0c05d87cu; return 0; }
write(ram,r[3]+16,r[1],4);
goto P_0c05d87e;
P_0c05d87e: /* original 53fc, guest PC 0x0c05d87e */
if(!s->budget--) { s->failed_pc=0x0c05d87eu; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c05d880;
P_0c05d880: /* original 3e3c, guest PC 0x0c05d880 */
if(!s->budget--) { s->failed_pc=0x0c05d880u; return 0; }
r[14]+=r[3];
goto P_0c05d882;
P_0c05d882: /* original 7e17, guest PC 0x0c05d882 */
if(!s->budget--) { s->failed_pc=0x0c05d882u; return 0; }
r[14]+=0x00000017u;
goto P_0c05d884;
P_0c05d884: /* original a002, guest PC 0x0c05d884 */
if(!s->budget--) { s->failed_pc=0x0c05d884u; return 0; }
r[14]&=r[12];
goto P_0c05d88c;
P_0c05d886: /* original 2ec9, guest PC 0x0c05d886 */
if(!s->budget--) { s->failed_pc=0x0c05d886u; return 0; }
r[14]&=r[12];
goto P_0c05d888;
P_0c05d888: /* original 63f2, guest PC 0x0c05d888 */
if(!s->budget--) { s->failed_pc=0x0c05d888u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c05d88a;
P_0c05d88a: /* original 13a4, guest PC 0x0c05d88a */
if(!s->budget--) { s->failed_pc=0x0c05d88au; return 0; }
write(ram,r[3]+16,r[10],4);
goto P_0c05d88c;
P_0c05d88c: /* original 53f2, guest PC 0x0c05d88c */
if(!s->budget--) { s->failed_pc=0x0c05d88cu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c05d88e;
P_0c05d88e: /* original 4e08, guest PC 0x0c05d88e */
if(!s->budget--) { s->failed_pc=0x0c05d88eu; return 0; }
r[14]<<=2;
goto P_0c05d890;
P_0c05d890: /* original 52f1, guest PC 0x0c05d890 */
if(!s->budget--) { s->failed_pc=0x0c05d890u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c05d892;
P_0c05d892: /* original 7d01, guest PC 0x0c05d892 */
if(!s->budget--) { s->failed_pc=0x0c05d892u; return 0; }
r[13]+=0x00000001u;
goto P_0c05d894;
P_0c05d894: /* original 6122, guest PC 0x0c05d894 */
if(!s->budget--) { s->failed_pc=0x0c05d894u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c05d896;
P_0c05d896: /* original 3e1c, guest PC 0x0c05d896 */
if(!s->budget--) { s->failed_pc=0x0c05d896u; return 0; }
r[14]+=r[1];
goto P_0c05d898;
P_0c05d898: /* original 23e2, guest PC 0x0c05d898 */
if(!s->budget--) { s->failed_pc=0x0c05d898u; return 0; }
write(ram,r[3],r[14],4);
goto P_0c05d89a;
P_0c05d89a: /* original ee00, guest PC 0x0c05d89a */
if(!s->budget--) { s->failed_pc=0x0c05d89au; return 0; }
r[14]=0x00000000u;
goto P_0c05d89c;
P_0c05d89c: /* original 53fe, guest PC 0x0c05d89c */
if(!s->budget--) { s->failed_pc=0x0c05d89cu; return 0; }
r[3]=read(ram,r[15]+56,4);
goto P_0c05d89e;
P_0c05d89e: /* original 3d32, guest PC 0x0c05d89e */
if(!s->budget--) { s->failed_pc=0x0c05d89eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[3])!=0);
goto P_0c05d8a0;
P_0c05d8a0: /* original 8901, guest PC 0x0c05d8a0 */
if(!s->budget--) { s->failed_pc=0x0c05d8a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d8a6; }
goto P_0c05d8a2;
P_0c05d8a2: /* original af25, guest PC 0x0c05d8a2 */
if(!s->budget--) { s->failed_pc=0x0c05d8a2u; return 0; }
goto P_0c05d6f0;
P_0c05d8a4: /* original 0009, guest PC 0x0c05d8a4 */
if(!s->budget--) { s->failed_pc=0x0c05d8a4u; return 0; }
goto P_0c05d8a6;
P_0c05d8a6: /* original e000, guest PC 0x0c05d8a6 */
if(!s->budget--) { s->failed_pc=0x0c05d8a6u; return 0; }
r[0]=0x00000000u;
goto P_0c05d8a8;
P_0c05d8a8: /* original 7f14, guest PC 0x0c05d8a8 */
if(!s->budget--) { s->failed_pc=0x0c05d8a8u; return 0; }
r[15]+=0x00000014u;
goto P_0c05d8aa;
P_0c05d8aa: /* original 68f6, guest PC 0x0c05d8aa */
if(!s->budget--) { s->failed_pc=0x0c05d8aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c05d8ac;
P_0c05d8ac: /* original 69f6, guest PC 0x0c05d8ac */
if(!s->budget--) { s->failed_pc=0x0c05d8acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05d8ae;
P_0c05d8ae: /* original 6af6, guest PC 0x0c05d8ae */
if(!s->budget--) { s->failed_pc=0x0c05d8aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05d8b0;
P_0c05d8b0: /* original 6bf6, guest PC 0x0c05d8b0 */
if(!s->budget--) { s->failed_pc=0x0c05d8b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05d8b2;
P_0c05d8b2: /* original 6cf6, guest PC 0x0c05d8b2 */
if(!s->budget--) { s->failed_pc=0x0c05d8b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05d8b4;
P_0c05d8b4: /* original 6df6, guest PC 0x0c05d8b4 */
if(!s->budget--) { s->failed_pc=0x0c05d8b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05d8b6;
P_0c05d8b6: /* original 000b, guest PC 0x0c05d8b6 */
if(!s->budget--) { s->failed_pc=0x0c05d8b6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05d8b8: /* original 6ef6, guest PC 0x0c05d8b8 */
if(!s->budget--) { s->failed_pc=0x0c05d8b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05d8bau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05d8bau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
