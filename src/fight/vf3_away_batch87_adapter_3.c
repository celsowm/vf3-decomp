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
int vf3_away_batch87_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0af37cu: goto P_0c0af37c;
case 0x0c0af37eu: goto P_0c0af37e;
case 0x0c0af380u: goto P_0c0af380;
case 0x0c0af382u: goto P_0c0af382;
case 0x0c0af384u: goto P_0c0af384;
case 0x0c0af386u: goto P_0c0af386;
case 0x0c0af388u: goto P_0c0af388;
case 0x0c0af38au: goto P_0c0af38a;
case 0x0c0af38cu: goto P_0c0af38c;
case 0x0c0af38eu: goto P_0c0af38e;
case 0x0c0af390u: goto P_0c0af390;
case 0x0c0af392u: goto P_0c0af392;
case 0x0c0af394u: goto P_0c0af394;
case 0x0c0af396u: goto P_0c0af396;
case 0x0c0af398u: goto P_0c0af398;
case 0x0c0af39au: goto P_0c0af39a;
case 0x0c0af39cu: goto P_0c0af39c;
case 0x0c0af39eu: goto P_0c0af39e;
case 0x0c0af3a0u: goto P_0c0af3a0;
case 0x0c0af3a2u: goto P_0c0af3a2;
case 0x0c0af3a4u: goto P_0c0af3a4;
case 0x0c0af3a6u: goto P_0c0af3a6;
case 0x0c0af3a8u: goto P_0c0af3a8;
case 0x0c0af3aau: goto P_0c0af3aa;
case 0x0c0af3acu: goto P_0c0af3ac;
case 0x0c0af3aeu: goto P_0c0af3ae;
case 0x0c0af3b0u: goto P_0c0af3b0;
case 0x0c0af3b2u: goto P_0c0af3b2;
case 0x0c0af3b4u: goto P_0c0af3b4;
case 0x0c0af3b6u: goto P_0c0af3b6;
case 0x0c0af3b8u: goto P_0c0af3b8;
case 0x0c0af3bau: goto P_0c0af3ba;
case 0x0c0af3bcu: goto P_0c0af3bc;
case 0x0c0af3beu: goto P_0c0af3be;
case 0x0c0af3c0u: goto P_0c0af3c0;
case 0x0c0af3c2u: goto P_0c0af3c2;
case 0x0c0af3c4u: goto P_0c0af3c4;
case 0x0c0af3c6u: goto P_0c0af3c6;
case 0x0c0af3c8u: goto P_0c0af3c8;
case 0x0c0af3cau: goto P_0c0af3ca;
case 0x0c0af3ccu: goto P_0c0af3cc;
case 0x0c0af3ceu: goto P_0c0af3ce;
case 0x0c0af3d0u: goto P_0c0af3d0;
case 0x0c0af3d2u: goto P_0c0af3d2;
case 0x0c0af3d4u: goto P_0c0af3d4;
case 0x0c0af3d6u: goto P_0c0af3d6;
case 0x0c0af3d8u: goto P_0c0af3d8;
case 0x0c0af3dau: goto P_0c0af3da;
case 0x0c0af3dcu: goto P_0c0af3dc;
case 0x0c0af3deu: goto P_0c0af3de;
case 0x0c0af3e0u: goto P_0c0af3e0;
case 0x0c0af3e2u: goto P_0c0af3e2;
case 0x0c0af3e4u: goto P_0c0af3e4;
case 0x0c0af3e6u: goto P_0c0af3e6;
case 0x0c0af3e8u: goto P_0c0af3e8;
case 0x0c0af3eau: goto P_0c0af3ea;
case 0x0c0af3ecu: goto P_0c0af3ec;
case 0x0c0af3eeu: goto P_0c0af3ee;
case 0x0c0af3f0u: goto P_0c0af3f0;
case 0x0c0af3f2u: goto P_0c0af3f2;
case 0x0c0af3f4u: goto P_0c0af3f4;
case 0x0c0af3f6u: goto P_0c0af3f6;
case 0x0c0af3f8u: goto P_0c0af3f8;
case 0x0c0af3fau: goto P_0c0af3fa;
case 0x0c0af3fcu: goto P_0c0af3fc;
case 0x0c0af3feu: goto P_0c0af3fe;
case 0x0c0af400u: goto P_0c0af400;
case 0x0c0af402u: goto P_0c0af402;
case 0x0c0af404u: goto P_0c0af404;
case 0x0c0af406u: goto P_0c0af406;
case 0x0c0af408u: goto P_0c0af408;
case 0x0c0af40au: goto P_0c0af40a;
case 0x0c0af40cu: goto P_0c0af40c;
case 0x0c0af40eu: goto P_0c0af40e;
case 0x0c0af410u: goto P_0c0af410;
case 0x0c0af412u: goto P_0c0af412;
case 0x0c0af414u: goto P_0c0af414;
case 0x0c0af416u: goto P_0c0af416;
case 0x0c0af418u: goto P_0c0af418;
case 0x0c0af41au: goto P_0c0af41a;
case 0x0c0af41cu: goto P_0c0af41c;
case 0x0c0af41eu: goto P_0c0af41e;
case 0x0c0af420u: goto P_0c0af420;
case 0x0c0af422u: goto P_0c0af422;
case 0x0c0af424u: goto P_0c0af424;
case 0x0c0af426u: goto P_0c0af426;
case 0x0c0af428u: goto P_0c0af428;
case 0x0c0af42au: goto P_0c0af42a;
case 0x0c0af42cu: goto P_0c0af42c;
case 0x0c0af42eu: goto P_0c0af42e;
case 0x0c0af430u: goto P_0c0af430;
case 0x0c0af432u: goto P_0c0af432;
case 0x0c0af434u: goto P_0c0af434;
case 0x0c0af436u: goto P_0c0af436;
case 0x0c0af438u: goto P_0c0af438;
case 0x0c0af43au: goto P_0c0af43a;
case 0x0c0af43cu: goto P_0c0af43c;
case 0x0c0af43eu: goto P_0c0af43e;
case 0x0c0af440u: goto P_0c0af440;
case 0x0c0af442u: goto P_0c0af442;
case 0x0c0af444u: goto P_0c0af444;
case 0x0c0af446u: goto P_0c0af446;
case 0x0c0af728u: goto P_0c0af728;
case 0x0c0af72au: goto P_0c0af72a;
case 0x0c0af72cu: goto P_0c0af72c;
case 0x0c0af72eu: goto P_0c0af72e;
case 0x0c0af730u: goto P_0c0af730;
case 0x0c0af732u: goto P_0c0af732;
case 0x0c0af734u: goto P_0c0af734;
case 0x0c0af736u: goto P_0c0af736;
case 0x0c0af738u: goto P_0c0af738;
case 0x0c0af73au: goto P_0c0af73a;
case 0x0c0af73cu: goto P_0c0af73c;
case 0x0c0af73eu: goto P_0c0af73e;
case 0x0c0af740u: goto P_0c0af740;
case 0x0c0af742u: goto P_0c0af742;
case 0x0c0af744u: goto P_0c0af744;
case 0x0c0af746u: goto P_0c0af746;
case 0x0c0af748u: goto P_0c0af748;
case 0x0c0af74au: goto P_0c0af74a;
case 0x0c0af74cu: goto P_0c0af74c;
case 0x0c0af74eu: goto P_0c0af74e;
case 0x0c0af750u: goto P_0c0af750;
case 0x0c0af752u: goto P_0c0af752;
case 0x0c0af754u: goto P_0c0af754;
case 0x0c0af756u: goto P_0c0af756;
case 0x0c0af758u: goto P_0c0af758;
case 0x0c0af75au: goto P_0c0af75a;
case 0x0c0af75cu: goto P_0c0af75c;
case 0x0c0af75eu: goto P_0c0af75e;
case 0x0c0af760u: goto P_0c0af760;
case 0x0c0af762u: goto P_0c0af762;
case 0x0c0af764u: goto P_0c0af764;
case 0x0c0af766u: goto P_0c0af766;
case 0x0c0af768u: goto P_0c0af768;
case 0x0c0af76au: goto P_0c0af76a;
case 0x0c0af76cu: goto P_0c0af76c;
case 0x0c0af76eu: goto P_0c0af76e;
case 0x0c0af770u: goto P_0c0af770;
case 0x0c0af772u: goto P_0c0af772;
case 0x0c0af774u: goto P_0c0af774;
case 0x0c0af776u: goto P_0c0af776;
case 0x0c0af778u: goto P_0c0af778;
case 0x0c0af77au: goto P_0c0af77a;
case 0x0c0af77cu: goto P_0c0af77c;
case 0x0c0af77eu: goto P_0c0af77e;
case 0x0c0af780u: goto P_0c0af780;
case 0x0c0af782u: goto P_0c0af782;
case 0x0c0af784u: goto P_0c0af784;
case 0x0c0af786u: goto P_0c0af786;
case 0x0c0af788u: goto P_0c0af788;
case 0x0c0af78au: goto P_0c0af78a;
case 0x0c0af78cu: goto P_0c0af78c;
case 0x0c0af78eu: goto P_0c0af78e;
case 0x0c0af790u: goto P_0c0af790;
case 0x0c0af792u: goto P_0c0af792;
case 0x0c0af794u: goto P_0c0af794;
case 0x0c0af796u: goto P_0c0af796;
case 0x0c0af798u: goto P_0c0af798;
case 0x0c0af79au: goto P_0c0af79a;
case 0x0c0af79cu: goto P_0c0af79c;
case 0x0c0af79eu: goto P_0c0af79e;
case 0x0c0af7a0u: goto P_0c0af7a0;
case 0x0c0af7a2u: goto P_0c0af7a2;
case 0x0c0af7a4u: goto P_0c0af7a4;
case 0x0c0af7a6u: goto P_0c0af7a6;
case 0x0c0af7a8u: goto P_0c0af7a8;
case 0x0c0af7aau: goto P_0c0af7aa;
case 0x0c0af7acu: goto P_0c0af7ac;
case 0x0c0af7aeu: goto P_0c0af7ae;
case 0x0c0af7b0u: goto P_0c0af7b0;
case 0x0c0af7b2u: goto P_0c0af7b2;
case 0x0c0af7b4u: goto P_0c0af7b4;
case 0x0c0af7b6u: goto P_0c0af7b6;
case 0x0c0af7b8u: goto P_0c0af7b8;
case 0x0c0af7bau: goto P_0c0af7ba;
case 0x0c0af7bcu: goto P_0c0af7bc;
case 0x0c0af7beu: goto P_0c0af7be;
case 0x0c0af7c0u: goto P_0c0af7c0;
case 0x0c0af7c2u: goto P_0c0af7c2;
case 0x0c0af7c4u: goto P_0c0af7c4;
case 0x0c0af7c6u: goto P_0c0af7c6;
case 0x0c0af7c8u: goto P_0c0af7c8;
case 0x0c0af7cau: goto P_0c0af7ca;
case 0x0c0af7ccu: goto P_0c0af7cc;
case 0x0c0af7ceu: goto P_0c0af7ce;
case 0x0c0af7d0u: goto P_0c0af7d0;
case 0x0c0af7d2u: goto P_0c0af7d2;
case 0x0c0af7d4u: goto P_0c0af7d4;
case 0x0c0af7d6u: goto P_0c0af7d6;
case 0x0c0af7d8u: goto P_0c0af7d8;
case 0x0c0af7dau: goto P_0c0af7da;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0af37c: /* original 2fe6, guest PC 0x0c0af37c */
if(!s->budget--) { s->failed_pc=0x0c0af37cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af37e;
P_0c0af37e: /* original 6e43, guest PC 0x0c0af37e */
if(!s->budget--) { s->failed_pc=0x0c0af37eu; return 0; }
r[14]=r[4];
goto P_0c0af380;
P_0c0af380: /* original 2fd6, guest PC 0x0c0af380 */
if(!s->budget--) { s->failed_pc=0x0c0af380u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af382;
P_0c0af382: /* original 2fc6, guest PC 0x0c0af382 */
if(!s->budget--) { s->failed_pc=0x0c0af382u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af384;
P_0c0af384: /* original fffb, guest PC 0x0c0af384 */
if(!s->budget--) { s->failed_pc=0x0c0af384u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0af386;
P_0c0af386: /* original ffeb, guest PC 0x0c0af386 */
if(!s->budget--) { s->failed_pc=0x0c0af386u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0af388;
P_0c0af388: /* original ffdb, guest PC 0x0c0af388 */
if(!s->budget--) { s->failed_pc=0x0c0af388u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0af38a;
P_0c0af38a: /* original ffcb, guest PC 0x0c0af38a */
if(!s->budget--) { s->failed_pc=0x0c0af38au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0af38c;
P_0c0af38c: /* original 4f22, guest PC 0x0c0af38c */
if(!s->budget--) { s->failed_pc=0x0c0af38cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0af38e;
P_0c0af38e: /* original 7ff4, guest PC 0x0c0af38e */
if(!s->budget--) { s->failed_pc=0x0c0af38eu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0af390;
P_0c0af390: /* original 2f52, guest PC 0x0c0af390 */
if(!s->budget--) { s->failed_pc=0x0c0af390u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0af392;
P_0c0af392: /* original d452, guest PC 0x0c0af392 */
if(!s->budget--) { s->failed_pc=0x0c0af392u; return 0; }
r[4]=read(ram,0x0c0af4dcu,4);
goto P_0c0af394;
P_0c0af394: /* original d552, guest PC 0x0c0af394 */
if(!s->budget--) { s->failed_pc=0x0c0af394u; return 0; }
r[5]=read(ram,0x0c0af4e0u,4);
goto P_0c0af396;
P_0c0af396: /* original 5341, guest PC 0x0c0af396 */
if(!s->budget--) { s->failed_pc=0x0c0af396u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0af398;
P_0c0af398: /* original 2358, guest PC 0x0c0af398 */
if(!s->budget--) { s->failed_pc=0x0c0af398u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0af39a;
P_0c0af39a: /* original 8f44, guest PC 0x0c0af39a */
if(!s->budget--) { s->failed_pc=0x0c0af39au; return 0; }
cond=r[17]&1u;
r[12]=r[6];
if(!cond) { goto P_0c0af426; }
goto P_0c0af39e;
P_0c0af39c: /* original 6c63, guest PC 0x0c0af39c */
if(!s->budget--) { s->failed_pc=0x0c0af39cu; return 0; }
r[12]=r[6];
goto P_0c0af39e;
P_0c0af39e: /* original 6242, guest PC 0x0c0af39e */
if(!s->budget--) { s->failed_pc=0x0c0af39eu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0af3a0;
P_0c0af3a0: /* original 2528, guest PC 0x0c0af3a0 */
if(!s->budget--) { s->failed_pc=0x0c0af3a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c0af3a2;
P_0c0af3a2: /* original 8b40, guest PC 0x0c0af3a2 */
if(!s->budget--) { s->failed_pc=0x0c0af3a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0af426; }
goto P_0c0af3a4;
P_0c0af3a4: /* original 85ef, guest PC 0x0c0af3a4 */
if(!s->budget--) { s->failed_pc=0x0c0af3a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0af3a6;
P_0c0af3a6: /* original 81ef, guest PC 0x0c0af3a6 */
if(!s->budget--) { s->failed_pc=0x0c0af3a6u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0af3a8;
P_0c0af3a8: /* original 6403, guest PC 0x0c0af3a8 */
if(!s->budget--) { s->failed_pc=0x0c0af3a8u; return 0; }
r[4]=r[0];
goto P_0c0af3aa;
P_0c0af3aa: /* original 6d03, guest PC 0x0c0af3aa */
if(!s->budget--) { s->failed_pc=0x0c0af3aau; return 0; }
r[13]=r[0];
goto P_0c0af3ac;
P_0c0af3ac: /* original e010, guest PC 0x0c0af3ac */
if(!s->budget--) { s->failed_pc=0x0c0af3acu; return 0; }
r[0]=0x00000010u;
goto P_0c0af3ae;
P_0c0af3ae: /* original 6343, guest PC 0x0c0af3ae */
if(!s->budget--) { s->failed_pc=0x0c0af3aeu; return 0; }
r[3]=r[4];
goto P_0c0af3b0;
P_0c0af3b0: /* original 3348, guest PC 0x0c0af3b0 */
if(!s->budget--) { s->failed_pc=0x0c0af3b0u; return 0; }
r[3]-=r[4];
goto P_0c0af3b2;
P_0c0af3b2: /* original 643d, guest PC 0x0c0af3b2 */
if(!s->budget--) { s->failed_pc=0x0c0af3b2u; return 0; }
r[4]=r[3]&65535u;
goto P_0c0af3b4;
P_0c0af3b4: /* original 1f42, guest PC 0x0c0af3b4 */
if(!s->budget--) { s->failed_pc=0x0c0af3b4u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0af3b6;
P_0c0af3b6: /* original f4e6, guest PC 0x0c0af3b6 */
if(!s->budget--) { s->failed_pc=0x0c0af3b6u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0af3b8;
P_0c0af3b8: /* original e018, guest PC 0x0c0af3b8 */
if(!s->budget--) { s->failed_pc=0x0c0af3b8u; return 0; }
r[0]=0x00000018u;
goto P_0c0af3ba;
P_0c0af3ba: /* original f5e6, guest PC 0x0c0af3ba */
if(!s->budget--) { s->failed_pc=0x0c0af3bau; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0af3bc;
P_0c0af3bc: /* original 908a, guest PC 0x0c0af3bc */
if(!s->budget--) { s->failed_pc=0x0c0af3bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af4d4u,2);
goto P_0c0af3be;
P_0c0af3be: /* original fde6, guest PC 0x0c0af3be */
if(!s->budget--) { s->failed_pc=0x0c0af3beu; return 0; }
vf3_matrix_load(s,ram,13,r[14]+r[0]);
goto P_0c0af3c0;
P_0c0af3c0: /* original 7008, guest PC 0x0c0af3c0 */
if(!s->budget--) { s->failed_pc=0x0c0af3c0u; return 0; }
r[0]+=0x00000008u;
goto P_0c0af3c2;
P_0c0af3c2: /* original fce6, guest PC 0x0c0af3c2 */
if(!s->budget--) { s->failed_pc=0x0c0af3c2u; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c0af3c4;
P_0c0af3c4: /* original e004, guest PC 0x0c0af3c4 */
if(!s->budget--) { s->failed_pc=0x0c0af3c4u; return 0; }
r[0]=0x00000004u;
goto P_0c0af3c6;
P_0c0af3c6: /* original ffdc, guest PC 0x0c0af3c6 */
if(!s->budget--) { s->failed_pc=0x0c0af3c6u; return 0; }
vf3_matrix_move(s,15,13);
goto P_0c0af3c8;
P_0c0af3c8: /* original ff41, guest PC 0x0c0af3c8 */
if(!s->budget--) { s->failed_pc=0x0c0af3c8u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'-');
goto P_0c0af3ca;
P_0c0af3ca: /* original f3cc, guest PC 0x0c0af3ca */
if(!s->budget--) { s->failed_pc=0x0c0af3cau; return 0; }
vf3_matrix_move(s,3,12);
goto P_0c0af3cc;
P_0c0af3cc: /* original f351, guest PC 0x0c0af3cc */
if(!s->budget--) { s->failed_pc=0x0c0af3ccu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c0af3ce;
P_0c0af3ce: /* original ff37, guest PC 0x0c0af3ce */
if(!s->budget--) { s->failed_pc=0x0c0af3ceu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0af3d0;
P_0c0af3d0: /* original 5df2, guest PC 0x0c0af3d0 */
if(!s->budget--) { s->failed_pc=0x0c0af3d0u; return 0; }
r[13]=read(ram,r[15]+8,4);
goto P_0c0af3d2;
P_0c0af3d2: /* original d344, guest PC 0x0c0af3d2 */
if(!s->budget--) { s->failed_pc=0x0c0af3d2u; return 0; }
r[3]=read(ram,0x0c0af4e4u,4);
goto P_0c0af3d4;
P_0c0af3d4: /* original 6ddf, guest PC 0x0c0af3d4 */
if(!s->budget--) { s->failed_pc=0x0c0af3d4u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c0af3d6;
P_0c0af3d6: /* original 430b, guest PC 0x0c0af3d6 */
if(!s->budget--) { s->failed_pc=0x0c0af3d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0af3dau;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0af3dau) { target=s->pc; goto dispatch; }
goto P_0c0af3da;
P_0c0af3d8: /* original 64d3, guest PC 0x0c0af3d8 */
if(!s->budget--) { s->failed_pc=0x0c0af3d8u; return 0; }
r[4]=r[13];
goto P_0c0af3da;
P_0c0af3da: /* original f3fc, guest PC 0x0c0af3da */
if(!s->budget--) { s->failed_pc=0x0c0af3dau; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0af3dc;
P_0c0af3dc: /* original ff0c, guest PC 0x0c0af3dc */
if(!s->budget--) { s->failed_pc=0x0c0af3dcu; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c0af3de;
P_0c0af3de: /* original ff32, guest PC 0x0c0af3de */
if(!s->budget--) { s->failed_pc=0x0c0af3deu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c0af3e0;
P_0c0af3e0: /* original d341, guest PC 0x0c0af3e0 */
if(!s->budget--) { s->failed_pc=0x0c0af3e0u; return 0; }
r[3]=read(ram,0x0c0af4e8u,4);
goto P_0c0af3e2;
P_0c0af3e2: /* original f40c, guest PC 0x0c0af3e2 */
if(!s->budget--) { s->failed_pc=0x0c0af3e2u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0af3e4;
P_0c0af3e4: /* original 430b, guest PC 0x0c0af3e4 */
if(!s->budget--) { s->failed_pc=0x0c0af3e4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0af3e8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0af3e8u) { target=s->pc; goto dispatch; }
goto P_0c0af3e8;
P_0c0af3e6: /* original 64d3, guest PC 0x0c0af3e6 */
if(!s->budget--) { s->failed_pc=0x0c0af3e6u; return 0; }
r[4]=r[13];
goto P_0c0af3e8;
P_0c0af3e8: /* original e004, guest PC 0x0c0af3e8 */
if(!s->budget--) { s->failed_pc=0x0c0af3e8u; return 0; }
r[0]=0x00000004u;
goto P_0c0af3ea;
P_0c0af3ea: /* original f40c, guest PC 0x0c0af3ea */
if(!s->budget--) { s->failed_pc=0x0c0af3eau; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0af3ec;
P_0c0af3ec: /* original f3f6, guest PC 0x0c0af3ec */
if(!s->budget--) { s->failed_pc=0x0c0af3ecu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0af3ee;
P_0c0af3ee: /* original f2fc, guest PC 0x0c0af3ee */
if(!s->budget--) { s->failed_pc=0x0c0af3eeu; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c0af3f0;
P_0c0af3f0: /* original f432, guest PC 0x0c0af3f0 */
if(!s->budget--) { s->failed_pc=0x0c0af3f0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0af3f2;
P_0c0af3f2: /* original d33d, guest PC 0x0c0af3f2 */
if(!s->budget--) { s->failed_pc=0x0c0af3f2u; return 0; }
r[3]=read(ram,0x0c0af4e8u,4);
goto P_0c0af3f4;
P_0c0af3f4: /* original ff4c, guest PC 0x0c0af3f4 */
if(!s->budget--) { s->failed_pc=0x0c0af3f4u; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c0af3f6;
P_0c0af3f6: /* original ff20, guest PC 0x0c0af3f6 */
if(!s->budget--) { s->failed_pc=0x0c0af3f6u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[2],r[18],'+');
goto P_0c0af3f8;
P_0c0af3f8: /* original 430b, guest PC 0x0c0af3f8 */
if(!s->budget--) { s->failed_pc=0x0c0af3f8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0af3fcu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0af3fcu) { target=s->pc; goto dispatch; }
goto P_0c0af3fc;
P_0c0af3fa: /* original 64d3, guest PC 0x0c0af3fa */
if(!s->budget--) { s->failed_pc=0x0c0af3fau; return 0; }
r[4]=r[13];
goto P_0c0af3fc;
P_0c0af3fc: /* original fe0c, guest PC 0x0c0af3fc */
if(!s->budget--) { s->failed_pc=0x0c0af3fcu; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c0af3fe;
P_0c0af3fe: /* original fef2, guest PC 0x0c0af3fe */
if(!s->budget--) { s->failed_pc=0x0c0af3feu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'*');
goto P_0c0af400;
P_0c0af400: /* original d238, guest PC 0x0c0af400 */
if(!s->budget--) { s->failed_pc=0x0c0af400u; return 0; }
r[2]=read(ram,0x0c0af4e4u,4);
goto P_0c0af402;
P_0c0af402: /* original f40c, guest PC 0x0c0af402 */
if(!s->budget--) { s->failed_pc=0x0c0af402u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0af404;
P_0c0af404: /* original 420b, guest PC 0x0c0af404 */
if(!s->budget--) { s->failed_pc=0x0c0af404u; return 0; }
target=r[2];
r[16]=code_base|0x0c0af408u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0af408u) { target=s->pc; goto dispatch; }
goto P_0c0af408;
P_0c0af406: /* original 64d3, guest PC 0x0c0af406 */
if(!s->budget--) { s->failed_pc=0x0c0af406u; return 0; }
r[4]=r[13];
goto P_0c0af408;
P_0c0af408: /* original f40c, guest PC 0x0c0af408 */
if(!s->budget--) { s->failed_pc=0x0c0af408u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0af40a;
P_0c0af40a: /* original f4e2, guest PC 0x0c0af40a */
if(!s->budget--) { s->failed_pc=0x0c0af40au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'*');
goto P_0c0af40c;
P_0c0af40c: /* original f3ec, guest PC 0x0c0af40c */
if(!s->budget--) { s->failed_pc=0x0c0af40cu; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c0af40e;
P_0c0af40e: /* original e010, guest PC 0x0c0af40e */
if(!s->budget--) { s->failed_pc=0x0c0af40eu; return 0; }
r[0]=0x00000010u;
goto P_0c0af410;
P_0c0af410: /* original fe4c, guest PC 0x0c0af410 */
if(!s->budget--) { s->failed_pc=0x0c0af410u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c0af412;
P_0c0af412: /* original fe31, guest PC 0x0c0af412 */
if(!s->budget--) { s->failed_pc=0x0c0af412u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'-');
goto P_0c0af414;
P_0c0af414: /* original f3fc, guest PC 0x0c0af414 */
if(!s->budget--) { s->failed_pc=0x0c0af414u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0af416;
P_0c0af416: /* original ffdc, guest PC 0x0c0af416 */
if(!s->budget--) { s->failed_pc=0x0c0af416u; return 0; }
vf3_matrix_move(s,15,13);
goto P_0c0af418;
P_0c0af418: /* original ff31, guest PC 0x0c0af418 */
if(!s->budget--) { s->failed_pc=0x0c0af418u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'-');
goto P_0c0af41a;
P_0c0af41a: /* original f3ec, guest PC 0x0c0af41a */
if(!s->budget--) { s->failed_pc=0x0c0af41au; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c0af41c;
P_0c0af41c: /* original fecc, guest PC 0x0c0af41c */
if(!s->budget--) { s->failed_pc=0x0c0af41cu; return 0; }
vf3_matrix_move(s,14,12);
goto P_0c0af41e;
P_0c0af41e: /* original fe31, guest PC 0x0c0af41e */
if(!s->budget--) { s->failed_pc=0x0c0af41eu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'-');
goto P_0c0af420;
P_0c0af420: /* original fef7, guest PC 0x0c0af420 */
if(!s->budget--) { s->failed_pc=0x0c0af420u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0af422;
P_0c0af422: /* original e018, guest PC 0x0c0af422 */
if(!s->budget--) { s->failed_pc=0x0c0af422u; return 0; }
r[0]=0x00000018u;
goto P_0c0af424;
P_0c0af424: /* original fee7, guest PC 0x0c0af424 */
if(!s->budget--) { s->failed_pc=0x0c0af424u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c0af426;
P_0c0af426: /* original 53c2, guest PC 0x0c0af426 */
if(!s->budget--) { s->failed_pc=0x0c0af426u; return 0; }
r[3]=read(ram,r[12]+8,4);
goto P_0c0af428;
P_0c0af428: /* original 66c3, guest PC 0x0c0af428 */
if(!s->budget--) { s->failed_pc=0x0c0af428u; return 0; }
r[6]=r[12];
goto P_0c0af42a;
P_0c0af42a: /* original 64e3, guest PC 0x0c0af42a */
if(!s->budget--) { s->failed_pc=0x0c0af42au; return 0; }
r[4]=r[14];
goto P_0c0af42c;
P_0c0af42c: /* original 7305, guest PC 0x0c0af42c */
if(!s->budget--) { s->failed_pc=0x0c0af42cu; return 0; }
r[3]+=0x00000005u;
goto P_0c0af42e;
P_0c0af42e: /* original 1c32, guest PC 0x0c0af42e */
if(!s->budget--) { s->failed_pc=0x0c0af42eu; return 0; }
write(ram,r[12]+8,r[3],4);
goto P_0c0af430;
P_0c0af430: /* original 65f2, guest PC 0x0c0af430 */
if(!s->budget--) { s->failed_pc=0x0c0af430u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0af432;
P_0c0af432: /* original 7f0c, guest PC 0x0c0af432 */
if(!s->budget--) { s->failed_pc=0x0c0af432u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0af434;
P_0c0af434: /* original 4f26, guest PC 0x0c0af434 */
if(!s->budget--) { s->failed_pc=0x0c0af434u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0af436;
P_0c0af436: /* original d32d, guest PC 0x0c0af436 */
if(!s->budget--) { s->failed_pc=0x0c0af436u; return 0; }
r[3]=read(ram,0x0c0af4ecu,4);
goto P_0c0af438;
P_0c0af438: /* original fcf9, guest PC 0x0c0af438 */
if(!s->budget--) { s->failed_pc=0x0c0af438u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0af43a;
P_0c0af43a: /* original fdf9, guest PC 0x0c0af43a */
if(!s->budget--) { s->failed_pc=0x0c0af43au; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0af43c;
P_0c0af43c: /* original fef9, guest PC 0x0c0af43c */
if(!s->budget--) { s->failed_pc=0x0c0af43cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0af43e;
P_0c0af43e: /* original fff9, guest PC 0x0c0af43e */
if(!s->budget--) { s->failed_pc=0x0c0af43eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0af440;
P_0c0af440: /* original 6cf6, guest PC 0x0c0af440 */
if(!s->budget--) { s->failed_pc=0x0c0af440u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0af442;
P_0c0af442: /* original 6df6, guest PC 0x0c0af442 */
if(!s->budget--) { s->failed_pc=0x0c0af442u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0af444;
P_0c0af444: /* original 432b, guest PC 0x0c0af444 */
if(!s->budget--) { s->failed_pc=0x0c0af444u; return 0; }
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
P_0c0af446: /* original 6ef6, guest PC 0x0c0af446 */
if(!s->budget--) { s->failed_pc=0x0c0af446u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0af448u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0af448u; return 0; } return 1;
P_0c0af728: /* original 2fe6, guest PC 0x0c0af728 */
if(!s->budget--) { s->failed_pc=0x0c0af728u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af72a;
P_0c0af72a: /* original 6e43, guest PC 0x0c0af72a */
if(!s->budget--) { s->failed_pc=0x0c0af72au; return 0; }
r[14]=r[4];
goto P_0c0af72c;
P_0c0af72c: /* original 2fd6, guest PC 0x0c0af72c */
if(!s->budget--) { s->failed_pc=0x0c0af72cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af72e;
P_0c0af72e: /* original 6d63, guest PC 0x0c0af72e */
if(!s->budget--) { s->failed_pc=0x0c0af72eu; return 0; }
r[13]=r[6];
goto P_0c0af730;
P_0c0af730: /* original 53d2, guest PC 0x0c0af730 */
if(!s->budget--) { s->failed_pc=0x0c0af730u; return 0; }
r[3]=read(ram,r[13]+8,4);
goto P_0c0af732;
P_0c0af732: /* original 907a, guest PC 0x0c0af732 */
if(!s->budget--) { s->failed_pc=0x0c0af732u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af82au,2);
goto P_0c0af734;
P_0c0af734: /* original 4f22, guest PC 0x0c0af734 */
if(!s->budget--) { s->failed_pc=0x0c0af734u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0af736;
P_0c0af736: /* original d441, guest PC 0x0c0af736 */
if(!s->budget--) { s->failed_pc=0x0c0af736u; return 0; }
r[4]=read(ram,0x0c0af83cu,4);
goto P_0c0af738;
P_0c0af738: /* original 0e36, guest PC 0x0c0af738 */
if(!s->budget--) { s->failed_pc=0x0c0af738u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0af73a;
P_0c0af73a: /* original 9377, guest PC 0x0c0af73a */
if(!s->budget--) { s->failed_pc=0x0c0af73au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af82cu,2);
goto P_0c0af73c;
P_0c0af73c: /* original 7ff8, guest PC 0x0c0af73c */
if(!s->budget--) { s->failed_pc=0x0c0af73cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0af73e;
P_0c0af73e: /* original 52d3, guest PC 0x0c0af73e */
if(!s->budget--) { s->failed_pc=0x0c0af73eu; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0af740;
P_0c0af740: /* original 2238, guest PC 0x0c0af740 */
if(!s->budget--) { s->failed_pc=0x0c0af740u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0af742;
P_0c0af742: /* original 890e, guest PC 0x0c0af742 */
if(!s->budget--) { s->failed_pc=0x0c0af742u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af762; }
goto P_0c0af744;
P_0c0af744: /* original 51d3, guest PC 0x0c0af744 */
if(!s->budget--) { s->failed_pc=0x0c0af744u; return 0; }
r[1]=read(ram,r[13]+12,4);
goto P_0c0af746;
P_0c0af746: /* original 9372, guest PC 0x0c0af746 */
if(!s->budget--) { s->failed_pc=0x0c0af746u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af82eu,2);
goto P_0c0af748;
P_0c0af748: /* original 2139, guest PC 0x0c0af748 */
if(!s->budget--) { s->failed_pc=0x0c0af748u; return 0; }
r[1]&=r[3];
goto P_0c0af74a;
P_0c0af74a: /* original 1d13, guest PC 0x0c0af74a */
if(!s->budget--) { s->failed_pc=0x0c0af74au; return 0; }
write(ram,r[13]+12,r[1],4);
goto P_0c0af74c;
P_0c0af74c: /* original d53c, guest PC 0x0c0af74c */
if(!s->budget--) { s->failed_pc=0x0c0af74cu; return 0; }
r[5]=read(ram,0x0c0af840u,4);
goto P_0c0af74e;
P_0c0af74e: /* original 5241, guest PC 0x0c0af74e */
if(!s->budget--) { s->failed_pc=0x0c0af74eu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c0af750;
P_0c0af750: /* original 2258, guest PC 0x0c0af750 */
if(!s->budget--) { s->failed_pc=0x0c0af750u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0af752;
P_0c0af752: /* original 8b06, guest PC 0x0c0af752 */
if(!s->budget--) { s->failed_pc=0x0c0af752u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0af762; }
goto P_0c0af754;
P_0c0af754: /* original 6342, guest PC 0x0c0af754 */
if(!s->budget--) { s->failed_pc=0x0c0af754u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0af756;
P_0c0af756: /* original 2538, guest PC 0x0c0af756 */
if(!s->budget--) { s->failed_pc=0x0c0af756u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0af758;
P_0c0af758: /* original 8b03, guest PC 0x0c0af758 */
if(!s->budget--) { s->failed_pc=0x0c0af758u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0af762; }
goto P_0c0af75a;
P_0c0af75a: /* original 85ef, guest PC 0x0c0af75a */
if(!s->budget--) { s->failed_pc=0x0c0af75au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0af75c;
P_0c0af75c: /* original 9368, guest PC 0x0c0af75c */
if(!s->budget--) { s->failed_pc=0x0c0af75cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af830u,2);
goto P_0c0af75e;
P_0c0af75e: /* original 303c, guest PC 0x0c0af75e */
if(!s->budget--) { s->failed_pc=0x0c0af75eu; return 0; }
r[0]+=r[3];
goto P_0c0af760;
P_0c0af760: /* original 81ef, guest PC 0x0c0af760 */
if(!s->budget--) { s->failed_pc=0x0c0af760u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0af762;
P_0c0af762: /* original 53d4, guest PC 0x0c0af762 */
if(!s->budget--) { s->failed_pc=0x0c0af762u; return 0; }
r[3]=read(ram,r[13]+16,4);
goto P_0c0af764;
P_0c0af764: /* original d437, guest PC 0x0c0af764 */
if(!s->budget--) { s->failed_pc=0x0c0af764u; return 0; }
r[4]=read(ram,0x0c0af844u,4);
goto P_0c0af766;
P_0c0af766: /* original 2348, guest PC 0x0c0af766 */
if(!s->budget--) { s->failed_pc=0x0c0af766u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0af768;
P_0c0af768: /* original 8903, guest PC 0x0c0af768 */
if(!s->budget--) { s->failed_pc=0x0c0af768u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af772; }
goto P_0c0af76a;
P_0c0af76a: /* original 52d3, guest PC 0x0c0af76a */
if(!s->budget--) { s->failed_pc=0x0c0af76au; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0af76c;
P_0c0af76c: /* original d336, guest PC 0x0c0af76c */
if(!s->budget--) { s->failed_pc=0x0c0af76cu; return 0; }
r[3]=read(ram,0x0c0af848u,4);
goto P_0c0af76e;
P_0c0af76e: /* original 223b, guest PC 0x0c0af76e */
if(!s->budget--) { s->failed_pc=0x0c0af76eu; return 0; }
r[2]|=r[3];
goto P_0c0af770;
P_0c0af770: /* original 1d23, guest PC 0x0c0af770 */
if(!s->budget--) { s->failed_pc=0x0c0af770u; return 0; }
write(ram,r[13]+12,r[2],4);
goto P_0c0af772;
P_0c0af772: /* original 51d3, guest PC 0x0c0af772 */
if(!s->budget--) { s->failed_pc=0x0c0af772u; return 0; }
r[1]=read(ram,r[13]+12,4);
goto P_0c0af774;
P_0c0af774: /* original 2418, guest PC 0x0c0af774 */
if(!s->budget--) { s->failed_pc=0x0c0af774u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[1])==0)!=0);
goto P_0c0af776;
P_0c0af776: /* original 891e, guest PC 0x0c0af776 */
if(!s->budget--) { s->failed_pc=0x0c0af776u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af7b6; }
goto P_0c0af778;
P_0c0af778: /* original d334, guest PC 0x0c0af778 */
if(!s->budget--) { s->failed_pc=0x0c0af778u; return 0; }
r[3]=read(ram,0x0c0af84cu,4);
goto P_0c0af77a;
P_0c0af77a: /* original 65f3, guest PC 0x0c0af77a */
if(!s->budget--) { s->failed_pc=0x0c0af77au; return 0; }
r[5]=r[15];
goto P_0c0af77c;
P_0c0af77c: /* original 52d3, guest PC 0x0c0af77c */
if(!s->budget--) { s->failed_pc=0x0c0af77cu; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0af77e;
P_0c0af77e: /* original 66f3, guest PC 0x0c0af77e */
if(!s->budget--) { s->failed_pc=0x0c0af77eu; return 0; }
r[6]=r[15];
goto P_0c0af780;
P_0c0af780: /* original 2239, guest PC 0x0c0af780 */
if(!s->budget--) { s->failed_pc=0x0c0af780u; return 0; }
r[2]&=r[3];
goto P_0c0af782;
P_0c0af782: /* original 1d23, guest PC 0x0c0af782 */
if(!s->budget--) { s->failed_pc=0x0c0af782u; return 0; }
write(ram,r[13]+12,r[2],4);
goto P_0c0af784;
P_0c0af784: /* original 85ef, guest PC 0x0c0af784 */
if(!s->budget--) { s->failed_pc=0x0c0af784u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0af786;
P_0c0af786: /* original 640d, guest PC 0x0c0af786 */
if(!s->budget--) { s->failed_pc=0x0c0af786u; return 0; }
r[4]=r[0]&65535u;
goto P_0c0af788;
P_0c0af788: /* original 9053, guest PC 0x0c0af788 */
if(!s->budget--) { s->failed_pc=0x0c0af788u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af832u,2);
goto P_0c0af78a;
P_0c0af78a: /* original f3e6, guest PC 0x0c0af78a */
if(!s->budget--) { s->failed_pc=0x0c0af78au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0af78c;
P_0c0af78c: /* original e004, guest PC 0x0c0af78c */
if(!s->budget--) { s->failed_pc=0x0c0af78cu; return 0; }
r[0]=0x00000004u;
goto P_0c0af78e;
P_0c0af78e: /* original ff37, guest PC 0x0c0af78e */
if(!s->budget--) { s->failed_pc=0x0c0af78eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0af790;
P_0c0af790: /* original 9050, guest PC 0x0c0af790 */
if(!s->budget--) { s->failed_pc=0x0c0af790u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af834u,2);
goto P_0c0af792;
P_0c0af792: /* original f3e6, guest PC 0x0c0af792 */
if(!s->budget--) { s->failed_pc=0x0c0af792u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0af794;
P_0c0af794: /* original ff3a, guest PC 0x0c0af794 */
if(!s->budget--) { s->failed_pc=0x0c0af794u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0af796;
P_0c0af796: /* original d22e, guest PC 0x0c0af796 */
if(!s->budget--) { s->failed_pc=0x0c0af796u; return 0; }
r[2]=read(ram,0x0c0af850u,4);
goto P_0c0af798;
P_0c0af798: /* original 420b, guest PC 0x0c0af798 */
if(!s->budget--) { s->failed_pc=0x0c0af798u; return 0; }
target=r[2];
r[16]=code_base|0x0c0af79cu;
r[5]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0af79cu) { target=s->pc; goto dispatch; }
goto P_0c0af79c;
P_0c0af79a: /* original 7504, guest PC 0x0c0af79a */
if(!s->budget--) { s->failed_pc=0x0c0af79au; return 0; }
r[5]+=0x00000004u;
goto P_0c0af79c;
P_0c0af79c: /* original 904b, guest PC 0x0c0af79c */
if(!s->budget--) { s->failed_pc=0x0c0af79cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af836u,2);
goto P_0c0af79e;
P_0c0af79e: /* original f2f8, guest PC 0x0c0af79e */
if(!s->budget--) { s->failed_pc=0x0c0af79eu; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0af7a0;
P_0c0af7a0: /* original f5e6, guest PC 0x0c0af7a0 */
if(!s->budget--) { s->failed_pc=0x0c0af7a0u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0af7a2;
P_0c0af7a2: /* original 7008, guest PC 0x0c0af7a2 */
if(!s->budget--) { s->failed_pc=0x0c0af7a2u; return 0; }
r[0]+=0x00000008u;
goto P_0c0af7a4;
P_0c0af7a4: /* original f4e6, guest PC 0x0c0af7a4 */
if(!s->budget--) { s->failed_pc=0x0c0af7a4u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0af7a6;
P_0c0af7a6: /* original e004, guest PC 0x0c0af7a6 */
if(!s->budget--) { s->failed_pc=0x0c0af7a6u; return 0; }
r[0]=0x00000004u;
goto P_0c0af7a8;
P_0c0af7a8: /* original f3f6, guest PC 0x0c0af7a8 */
if(!s->budget--) { s->failed_pc=0x0c0af7a8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0af7aa;
P_0c0af7aa: /* original e010, guest PC 0x0c0af7aa */
if(!s->budget--) { s->failed_pc=0x0c0af7aau; return 0; }
r[0]=0x00000010u;
goto P_0c0af7ac;
P_0c0af7ac: /* original f421, guest PC 0x0c0af7ac */
if(!s->budget--) { s->failed_pc=0x0c0af7acu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'-');
goto P_0c0af7ae;
P_0c0af7ae: /* original f531, guest PC 0x0c0af7ae */
if(!s->budget--) { s->failed_pc=0x0c0af7aeu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c0af7b0;
P_0c0af7b0: /* original fe57, guest PC 0x0c0af7b0 */
if(!s->budget--) { s->failed_pc=0x0c0af7b0u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0af7b2;
P_0c0af7b2: /* original e018, guest PC 0x0c0af7b2 */
if(!s->budget--) { s->failed_pc=0x0c0af7b2u; return 0; }
r[0]=0x00000018u;
goto P_0c0af7b4;
P_0c0af7b4: /* original fe47, guest PC 0x0c0af7b4 */
if(!s->budget--) { s->failed_pc=0x0c0af7b4u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0af7b6;
P_0c0af7b6: /* original d327, guest PC 0x0c0af7b6 */
if(!s->budget--) { s->failed_pc=0x0c0af7b6u; return 0; }
r[3]=read(ram,0x0c0af854u,4);
goto P_0c0af7b8;
P_0c0af7b8: /* original 64e2, guest PC 0x0c0af7b8 */
if(!s->budget--) { s->failed_pc=0x0c0af7b8u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0af7ba;
P_0c0af7ba: /* original 2348, guest PC 0x0c0af7ba */
if(!s->budget--) { s->failed_pc=0x0c0af7bau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0af7bc;
P_0c0af7bc: /* original 8906, guest PC 0x0c0af7bc */
if(!s->budget--) { s->failed_pc=0x0c0af7bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af7cc; }
goto P_0c0af7be;
P_0c0af7be: /* original d226, guest PC 0x0c0af7be */
if(!s->budget--) { s->failed_pc=0x0c0af7beu; return 0; }
r[2]=read(ram,0x0c0af858u,4);
goto P_0c0af7c0;
P_0c0af7c0: /* original 2429, guest PC 0x0c0af7c0 */
if(!s->budget--) { s->failed_pc=0x0c0af7c0u; return 0; }
r[4]&=r[2];
goto P_0c0af7c2;
P_0c0af7c2: /* original 2e42, guest PC 0x0c0af7c2 */
if(!s->budget--) { s->failed_pc=0x0c0af7c2u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0af7c4;
P_0c0af7c4: /* original d325, guest PC 0x0c0af7c4 */
if(!s->budget--) { s->failed_pc=0x0c0af7c4u; return 0; }
r[3]=read(ram,0x0c0af85cu,4);
goto P_0c0af7c6;
P_0c0af7c6: /* original 51d3, guest PC 0x0c0af7c6 */
if(!s->budget--) { s->failed_pc=0x0c0af7c6u; return 0; }
r[1]=read(ram,r[13]+12,4);
goto P_0c0af7c8;
P_0c0af7c8: /* original 213b, guest PC 0x0c0af7c8 */
if(!s->budget--) { s->failed_pc=0x0c0af7c8u; return 0; }
r[1]|=r[3];
goto P_0c0af7ca;
P_0c0af7ca: /* original 1d13, guest PC 0x0c0af7ca */
if(!s->budget--) { s->failed_pc=0x0c0af7cau; return 0; }
write(ram,r[13]+12,r[1],4);
goto P_0c0af7cc;
P_0c0af7cc: /* original 7f08, guest PC 0x0c0af7cc */
if(!s->budget--) { s->failed_pc=0x0c0af7ccu; return 0; }
r[15]+=0x00000008u;
goto P_0c0af7ce;
P_0c0af7ce: /* original 52d3, guest PC 0x0c0af7ce */
if(!s->budget--) { s->failed_pc=0x0c0af7ceu; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0af7d0;
P_0c0af7d0: /* original 4f26, guest PC 0x0c0af7d0 */
if(!s->budget--) { s->failed_pc=0x0c0af7d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0af7d2;
P_0c0af7d2: /* original e048, guest PC 0x0c0af7d2 */
if(!s->budget--) { s->failed_pc=0x0c0af7d2u; return 0; }
r[0]=0x00000048u;
goto P_0c0af7d4;
P_0c0af7d4: /* original 0e26, guest PC 0x0c0af7d4 */
if(!s->budget--) { s->failed_pc=0x0c0af7d4u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0af7d6;
P_0c0af7d6: /* original 6df6, guest PC 0x0c0af7d6 */
if(!s->budget--) { s->failed_pc=0x0c0af7d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0af7d8;
P_0c0af7d8: /* original 000b, guest PC 0x0c0af7d8 */
if(!s->budget--) { s->failed_pc=0x0c0af7d8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0af7da: /* original 6ef6, guest PC 0x0c0af7da */
if(!s->budget--) { s->failed_pc=0x0c0af7dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0af7dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0af7dcu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
