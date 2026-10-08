/* Static C ABI adapters. Generated with tools/oracle/translate_adapters.py.
 * Matrix operations are hand-written in matrix_family.c; unknown code fails.
 * Executed opcodes are checked against the untouched identity image. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <math.h>
#include <string.h>
#define read vf3_matrix_read
#define write vf3_matrix_write
static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }
static uint32_t truncate_float(uint32_t u) { double d=as_float(u); if(isnan(d) || d< -2147483648.0) return 0x80000000u; if(d>=2147483648.0) return 0x7fffffffu; return (uint32_t)(int32_t)d; }
static void divide_step(vf3_matrix_state*s,unsigned n,unsigned m) { uint32_t *r=s->v; unsigned oldq=(r[17]>>8)&1u,sign=(r[17]>>9)&1u,q=r[n]>>31; uint32_t divisor=r[m],shifted=(r[n]<<1)|(r[17]&1u); r[n]=oldq==sign?shifted-divisor:shifted+divisor; unsigned carry=oldq==sign?r[n]>shifted:r[n]<shifted; q^=carry^sign; r[17]=(r[17]&~0x101u)|(q<<8)|(q==sign); }
int vf3_percentage_aux_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07385cu: goto P_0c07385c;
case 0x0c07385eu: goto P_0c07385e;
case 0x0c073860u: goto P_0c073860;
case 0x0c073862u: goto P_0c073862;
case 0x0c073864u: goto P_0c073864;
case 0x0c073866u: goto P_0c073866;
case 0x0c073868u: goto P_0c073868;
case 0x0c07386au: goto P_0c07386a;
case 0x0c07386cu: goto P_0c07386c;
case 0x0c07386eu: goto P_0c07386e;
case 0x0c073870u: goto P_0c073870;
case 0x0c073872u: goto P_0c073872;
case 0x0c073874u: goto P_0c073874;
case 0x0c073876u: goto P_0c073876;
case 0x0c073878u: goto P_0c073878;
case 0x0c07387au: goto P_0c07387a;
case 0x0c07387cu: goto P_0c07387c;
case 0x0c07387eu: goto P_0c07387e;
case 0x0c073880u: goto P_0c073880;
case 0x0c073882u: goto P_0c073882;
case 0x0c073884u: goto P_0c073884;
case 0x0c073886u: goto P_0c073886;
case 0x0c073888u: goto P_0c073888;
case 0x0c07388au: goto P_0c07388a;
case 0x0c07388cu: goto P_0c07388c;
case 0x0c07388eu: goto P_0c07388e;
case 0x0c073890u: goto P_0c073890;
case 0x0c073892u: goto P_0c073892;
case 0x0c073894u: goto P_0c073894;
case 0x0c073896u: goto P_0c073896;
case 0x0c073898u: goto P_0c073898;
case 0x0c07389au: goto P_0c07389a;
case 0x0c07389cu: goto P_0c07389c;
case 0x0c07389eu: goto P_0c07389e;
case 0x0c0738a0u: goto P_0c0738a0;
case 0x0c0738a2u: goto P_0c0738a2;
case 0x0c0738a4u: goto P_0c0738a4;
case 0x0c0738a6u: goto P_0c0738a6;
case 0x0c0738a8u: goto P_0c0738a8;
case 0x0c0738aau: goto P_0c0738aa;
case 0x0c0738acu: goto P_0c0738ac;
case 0x0c0738aeu: goto P_0c0738ae;
case 0x0c0738b0u: goto P_0c0738b0;
case 0x0c0738b2u: goto P_0c0738b2;
case 0x0c0738b4u: goto P_0c0738b4;
case 0x0c0738b6u: goto P_0c0738b6;
case 0x0c0738b8u: goto P_0c0738b8;
case 0x0c0738bau: goto P_0c0738ba;
case 0x0c0738bcu: goto P_0c0738bc;
case 0x0c0738beu: goto P_0c0738be;
case 0x0c0738c0u: goto P_0c0738c0;
case 0x0c0738c2u: goto P_0c0738c2;
case 0x0c0738c4u: goto P_0c0738c4;
case 0x0c0738c6u: goto P_0c0738c6;
case 0x0c0738c8u: goto P_0c0738c8;
case 0x0c0738cau: goto P_0c0738ca;
case 0x0c0738ccu: goto P_0c0738cc;
case 0x0c0738ceu: goto P_0c0738ce;
case 0x0c0738d0u: goto P_0c0738d0;
case 0x0c0738d2u: goto P_0c0738d2;
case 0x0c0738d4u: goto P_0c0738d4;
case 0x0c0738d6u: goto P_0c0738d6;
case 0x0c081a46u: goto P_0c081a46;
case 0x0c081a48u: goto P_0c081a48;
case 0x0c081a4au: goto P_0c081a4a;
case 0x0c081a4cu: goto P_0c081a4c;
case 0x0c081a4eu: goto P_0c081a4e;
case 0x0c081a50u: goto P_0c081a50;
case 0x0c081a52u: goto P_0c081a52;
case 0x0c081a54u: goto P_0c081a54;
case 0x0c081a56u: goto P_0c081a56;
case 0x0c081a58u: goto P_0c081a58;
case 0x0c081a5au: goto P_0c081a5a;
case 0x0c081a5cu: goto P_0c081a5c;
case 0x0c081a5eu: goto P_0c081a5e;
case 0x0c081a60u: goto P_0c081a60;
case 0x0c081a62u: goto P_0c081a62;
case 0x0c081a64u: goto P_0c081a64;
case 0x0c081a66u: goto P_0c081a66;
case 0x0c081a68u: goto P_0c081a68;
case 0x0c081a6au: goto P_0c081a6a;
case 0x0c081a6cu: goto P_0c081a6c;
case 0x0c081a6eu: goto P_0c081a6e;
case 0x0c081a70u: goto P_0c081a70;
case 0x0c081a72u: goto P_0c081a72;
case 0x0c081a74u: goto P_0c081a74;
case 0x0c081a76u: goto P_0c081a76;
case 0x0c081a78u: goto P_0c081a78;
case 0x0c081a7au: goto P_0c081a7a;
case 0x0c081a7cu: goto P_0c081a7c;
case 0x0c081a7eu: goto P_0c081a7e;
case 0x0c081a80u: goto P_0c081a80;
case 0x0c081a82u: goto P_0c081a82;
case 0x0c081a84u: goto P_0c081a84;
case 0x0c081a86u: goto P_0c081a86;
case 0x0c081a88u: goto P_0c081a88;
case 0x0c081a8au: goto P_0c081a8a;
case 0x0c081a8cu: goto P_0c081a8c;
case 0x0c081a8eu: goto P_0c081a8e;
case 0x0c081a90u: goto P_0c081a90;
case 0x0c081a92u: goto P_0c081a92;
case 0x0c081a94u: goto P_0c081a94;
case 0x0c081a96u: goto P_0c081a96;
case 0x0c081a98u: goto P_0c081a98;
case 0x0c081a9au: goto P_0c081a9a;
case 0x0c081a9cu: goto P_0c081a9c;
case 0x0c081a9eu: goto P_0c081a9e;
case 0x0c081aa0u: goto P_0c081aa0;
case 0x0c081aa2u: goto P_0c081aa2;
case 0x0c081aa4u: goto P_0c081aa4;
case 0x0c081aa6u: goto P_0c081aa6;
case 0x0c081aa8u: goto P_0c081aa8;
case 0x0c081aaau: goto P_0c081aaa;
case 0x0c081aacu: goto P_0c081aac;
case 0x0c081aaeu: goto P_0c081aae;
case 0x0c081ab0u: goto P_0c081ab0;
case 0x0c081ab2u: goto P_0c081ab2;
case 0x0c081ab4u: goto P_0c081ab4;
case 0x0c081ab6u: goto P_0c081ab6;
case 0x0c081ab8u: goto P_0c081ab8;
case 0x0c081abau: goto P_0c081aba;
case 0x0c081abcu: goto P_0c081abc;
case 0x0c081abeu: goto P_0c081abe;
case 0x0c081ac0u: goto P_0c081ac0;
case 0x0c081ac2u: goto P_0c081ac2;
case 0x0c081ac4u: goto P_0c081ac4;
case 0x0c081ac6u: goto P_0c081ac6;
case 0x0c081ac8u: goto P_0c081ac8;
case 0x0c081acau: goto P_0c081aca;
case 0x0c081accu: goto P_0c081acc;
case 0x0c081aceu: goto P_0c081ace;
case 0x0c081ad0u: goto P_0c081ad0;
case 0x0c081ad2u: goto P_0c081ad2;
case 0x0c081ad4u: goto P_0c081ad4;
case 0x0c081ad6u: goto P_0c081ad6;
case 0x0c081ad8u: goto P_0c081ad8;
case 0x0c081adau: goto P_0c081ada;
case 0x0c081adcu: goto P_0c081adc;
case 0x0c081adeu: goto P_0c081ade;
case 0x0c081ae0u: goto P_0c081ae0;
case 0x0c081ae2u: goto P_0c081ae2;
case 0x0c081ae4u: goto P_0c081ae4;
case 0x0c081ae6u: goto P_0c081ae6;
case 0x0c081ae8u: goto P_0c081ae8;
case 0x0c081aeau: goto P_0c081aea;
case 0x0c081aecu: goto P_0c081aec;
case 0x0c081aeeu: goto P_0c081aee;
case 0x0c081af0u: goto P_0c081af0;
case 0x0c081af2u: goto P_0c081af2;
case 0x0c081af4u: goto P_0c081af4;
case 0x0c081af6u: goto P_0c081af6;
case 0x0c081af8u: goto P_0c081af8;
case 0x0c08919eu: goto P_0c08919e;
case 0x0c0891a0u: goto P_0c0891a0;
case 0x0c0891a2u: goto P_0c0891a2;
case 0x0c0891a4u: goto P_0c0891a4;
case 0x0c0891a6u: goto P_0c0891a6;
case 0x0c0891a8u: goto P_0c0891a8;
case 0x0c0891aau: goto P_0c0891aa;
case 0x0c0891acu: goto P_0c0891ac;
case 0x0c0891aeu: goto P_0c0891ae;
case 0x0c0891b0u: goto P_0c0891b0;
case 0x0c0891b2u: goto P_0c0891b2;
case 0x0c0891b4u: goto P_0c0891b4;
case 0x0c0891b6u: goto P_0c0891b6;
case 0x0c0891b8u: goto P_0c0891b8;
case 0x0c0891bau: goto P_0c0891ba;
case 0x0c0891bcu: goto P_0c0891bc;
case 0x0c0891beu: goto P_0c0891be;
case 0x0c0891c0u: goto P_0c0891c0;
case 0x0c0891c2u: goto P_0c0891c2;
case 0x0c0891c4u: goto P_0c0891c4;
case 0x0c0891c6u: goto P_0c0891c6;
case 0x0c0891c8u: goto P_0c0891c8;
case 0x0c0891cau: goto P_0c0891ca;
case 0x0c0891ccu: goto P_0c0891cc;
case 0x0c0891ceu: goto P_0c0891ce;
case 0x0c0891d0u: goto P_0c0891d0;
case 0x0c0891d2u: goto P_0c0891d2;
case 0x0c0891d4u: goto P_0c0891d4;
case 0x0c0891d6u: goto P_0c0891d6;
case 0x0c0891d8u: goto P_0c0891d8;
case 0x0c0891dau: goto P_0c0891da;
case 0x0c0891dcu: goto P_0c0891dc;
case 0x0c0891deu: goto P_0c0891de;
case 0x0c0891e0u: goto P_0c0891e0;
case 0x0c0891e2u: goto P_0c0891e2;
case 0x0c0891e4u: goto P_0c0891e4;
case 0x0c0891e6u: goto P_0c0891e6;
case 0x0c0891e8u: goto P_0c0891e8;
case 0x0c0891eau: goto P_0c0891ea;
case 0x0c0891ecu: goto P_0c0891ec;
case 0x0c0891eeu: goto P_0c0891ee;
case 0x0c0891f0u: goto P_0c0891f0;
case 0x0c0891f2u: goto P_0c0891f2;
case 0x0c0891f4u: goto P_0c0891f4;
case 0x0c0891f6u: goto P_0c0891f6;
case 0x0c0891f8u: goto P_0c0891f8;
case 0x0c0891fau: goto P_0c0891fa;
case 0x0c0891fcu: goto P_0c0891fc;
case 0x0c0891feu: goto P_0c0891fe;
case 0x0c089200u: goto P_0c089200;
case 0x0c089202u: goto P_0c089202;
case 0x0c089204u: goto P_0c089204;
case 0x0c089206u: goto P_0c089206;
case 0x0c089208u: goto P_0c089208;
case 0x0c08920au: goto P_0c08920a;
case 0x0c08920cu: goto P_0c08920c;
case 0x0c08920eu: goto P_0c08920e;
case 0x0c089210u: goto P_0c089210;
case 0x0c089212u: goto P_0c089212;
case 0x0c089214u: goto P_0c089214;
case 0x0c089216u: goto P_0c089216;
case 0x0c089218u: goto P_0c089218;
case 0x0c08921au: goto P_0c08921a;
case 0x0c08921cu: goto P_0c08921c;
case 0x0c08921eu: goto P_0c08921e;
case 0x0c089220u: goto P_0c089220;
case 0x0c089222u: goto P_0c089222;
case 0x0c089224u: goto P_0c089224;
case 0x0c089226u: goto P_0c089226;
case 0x0c089228u: goto P_0c089228;
case 0x0c08922au: goto P_0c08922a;
case 0x0c08922cu: goto P_0c08922c;
case 0x0c08922eu: goto P_0c08922e;
case 0x0c089230u: goto P_0c089230;
case 0x0c089232u: goto P_0c089232;
case 0x0c089234u: goto P_0c089234;
case 0x0c089236u: goto P_0c089236;
case 0x0c089238u: goto P_0c089238;
case 0x0c08923au: goto P_0c08923a;
case 0x0c08923cu: goto P_0c08923c;
case 0x0c08923eu: goto P_0c08923e;
case 0x0c089240u: goto P_0c089240;
case 0x0c089242u: goto P_0c089242;
case 0x0c089244u: goto P_0c089244;
case 0x0c089246u: goto P_0c089246;
case 0x0c089248u: goto P_0c089248;
case 0x0c08924au: goto P_0c08924a;
case 0x0c08924cu: goto P_0c08924c;
case 0x0c08924eu: goto P_0c08924e;
case 0x0c089250u: goto P_0c089250;
case 0x0c089252u: goto P_0c089252;
case 0x0c089254u: goto P_0c089254;
case 0x0c089256u: goto P_0c089256;
case 0x0c089258u: goto P_0c089258;
case 0x0c08925au: goto P_0c08925a;
case 0x0c08925cu: goto P_0c08925c;
case 0x0c08925eu: goto P_0c08925e;
case 0x0c089260u: goto P_0c089260;
case 0x0c089262u: goto P_0c089262;
case 0x0c089264u: goto P_0c089264;
case 0x0c089266u: goto P_0c089266;
case 0x0c089268u: goto P_0c089268;
case 0x0c08926au: goto P_0c08926a;
case 0x0c08926cu: goto P_0c08926c;
case 0x0c08926eu: goto P_0c08926e;
case 0x0c089270u: goto P_0c089270;
case 0x0c089272u: goto P_0c089272;
case 0x0c089274u: goto P_0c089274;
case 0x0c089276u: goto P_0c089276;
case 0x0c089278u: goto P_0c089278;
case 0x0c08927au: goto P_0c08927a;
case 0x0c08927cu: goto P_0c08927c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07385c: /* original 4f22, guest PC 0x0c07385c */
if(!s->budget--) { s->failed_pc=0x0c07385cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07385e;
P_0c07385e: /* original 6212, guest PC 0x0c07385e */
if(!s->budget--) { s->failed_pc=0x0c07385eu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c073860;
P_0c073860: /* original d33e, guest PC 0x0c073860 */
if(!s->budget--) { s->failed_pc=0x0c073860u; return 0; }
r[3]=read(ram,0x0c07395cu,4);
goto P_0c073862;
P_0c073862: /* original 5e44, guest PC 0x0c073862 */
if(!s->budget--) { s->failed_pc=0x0c073862u; return 0; }
r[14]=read(ram,r[4]+16,4);
goto P_0c073864;
P_0c073864: /* original 2238, guest PC 0x0c073864 */
if(!s->budget--) { s->failed_pc=0x0c073864u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c073866;
P_0c073866: /* original 8f32, guest PC 0x0c073866 */
if(!s->budget--) { s->failed_pc=0x0c073866u; return 0; }
cond=r[17]&1u;
r[13]=read(ram,r[4]+20,4);
if(!cond) { goto P_0c0738ce; }
goto P_0c07386a;
P_0c073868: /* original 5d45, guest PC 0x0c073868 */
if(!s->budget--) { s->failed_pc=0x0c073868u; return 0; }
r[13]=read(ram,r[4]+20,4);
goto P_0c07386a;
P_0c07386a: /* original 9071, guest PC 0x0c07386a */
if(!s->budget--) { s->failed_pc=0x0c07386au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073950u,2);
goto P_0c07386c;
P_0c07386c: /* original e404, guest PC 0x0c07386c */
if(!s->budget--) { s->failed_pc=0x0c07386cu; return 0; }
r[4]=0x00000004u;
goto P_0c07386e;
P_0c07386e: /* original 65d3, guest PC 0x0c07386e */
if(!s->budget--) { s->failed_pc=0x0c07386eu; return 0; }
r[5]=r[13];
goto P_0c073870;
P_0c073870: /* original 0e46, guest PC 0x0c073870 */
if(!s->budget--) { s->failed_pc=0x0c073870u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c073872;
P_0c073872: /* original 0d46, guest PC 0x0c073872 */
if(!s->budget--) { s->failed_pc=0x0c073872u; return 0; }
write(ram,r[13]+r[0],r[4],4);
goto P_0c073874;
P_0c073874: /* original 906d, guest PC 0x0c073874 */
if(!s->budget--) { s->failed_pc=0x0c073874u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073952u,2);
goto P_0c073876;
P_0c073876: /* original f48d, guest PC 0x0c073876 */
if(!s->budget--) { s->failed_pc=0x0c073876u; return 0; }
fr[4]=0;
goto P_0c073878;
P_0c073878: /* original fe47, guest PC 0x0c073878 */
if(!s->budget--) { s->failed_pc=0x0c073878u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c07387a;
P_0c07387a: /* original 7004, guest PC 0x0c07387a */
if(!s->budget--) { s->failed_pc=0x0c07387au; return 0; }
r[0]+=0x00000004u;
goto P_0c07387c;
P_0c07387c: /* original fe47, guest PC 0x0c07387c */
if(!s->budget--) { s->failed_pc=0x0c07387cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c07387e;
P_0c07387e: /* original 7004, guest PC 0x0c07387e */
if(!s->budget--) { s->failed_pc=0x0c07387eu; return 0; }
r[0]+=0x00000004u;
goto P_0c073880;
P_0c073880: /* original fe47, guest PC 0x0c073880 */
if(!s->budget--) { s->failed_pc=0x0c073880u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c073882;
P_0c073882: /* original 70f8, guest PC 0x0c073882 */
if(!s->budget--) { s->failed_pc=0x0c073882u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c073884;
P_0c073884: /* original fd47, guest PC 0x0c073884 */
if(!s->budget--) { s->failed_pc=0x0c073884u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c073886;
P_0c073886: /* original 7004, guest PC 0x0c073886 */
if(!s->budget--) { s->failed_pc=0x0c073886u; return 0; }
r[0]+=0x00000004u;
goto P_0c073888;
P_0c073888: /* original fd47, guest PC 0x0c073888 */
if(!s->budget--) { s->failed_pc=0x0c073888u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c07388a;
P_0c07388a: /* original 7004, guest PC 0x0c07388a */
if(!s->budget--) { s->failed_pc=0x0c07388au; return 0; }
r[0]+=0x00000004u;
goto P_0c07388c;
P_0c07388c: /* original fd47, guest PC 0x0c07388c */
if(!s->budget--) { s->failed_pc=0x0c07388cu; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c07388e;
P_0c07388e: /* original 9061, guest PC 0x0c07388e */
if(!s->budget--) { s->failed_pc=0x0c07388eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073954u,2);
goto P_0c073890;
P_0c073890: /* original fe47, guest PC 0x0c073890 */
if(!s->budget--) { s->failed_pc=0x0c073890u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c073892;
P_0c073892: /* original 7004, guest PC 0x0c073892 */
if(!s->budget--) { s->failed_pc=0x0c073892u; return 0; }
r[0]+=0x00000004u;
goto P_0c073894;
P_0c073894: /* original fe47, guest PC 0x0c073894 */
if(!s->budget--) { s->failed_pc=0x0c073894u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c073896;
P_0c073896: /* original 7004, guest PC 0x0c073896 */
if(!s->budget--) { s->failed_pc=0x0c073896u; return 0; }
r[0]+=0x00000004u;
goto P_0c073898;
P_0c073898: /* original fe47, guest PC 0x0c073898 */
if(!s->budget--) { s->failed_pc=0x0c073898u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c07389a;
P_0c07389a: /* original 70f8, guest PC 0x0c07389a */
if(!s->budget--) { s->failed_pc=0x0c07389au; return 0; }
r[0]+=0xfffffff8u;
goto P_0c07389c;
P_0c07389c: /* original fd47, guest PC 0x0c07389c */
if(!s->budget--) { s->failed_pc=0x0c07389cu; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c07389e;
P_0c07389e: /* original 7004, guest PC 0x0c07389e */
if(!s->budget--) { s->failed_pc=0x0c07389eu; return 0; }
r[0]+=0x00000004u;
goto P_0c0738a0;
P_0c0738a0: /* original fd47, guest PC 0x0c0738a0 */
if(!s->budget--) { s->failed_pc=0x0c0738a0u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0738a2;
P_0c0738a2: /* original 7004, guest PC 0x0c0738a2 */
if(!s->budget--) { s->failed_pc=0x0c0738a2u; return 0; }
r[0]+=0x00000004u;
goto P_0c0738a4;
P_0c0738a4: /* original fd47, guest PC 0x0c0738a4 */
if(!s->budget--) { s->failed_pc=0x0c0738a4u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0738a6;
P_0c0738a6: /* original d32f, guest PC 0x0c0738a6 */
if(!s->budget--) { s->failed_pc=0x0c0738a6u; return 0; }
r[3]=read(ram,0x0c073964u,4);
goto P_0c0738a8;
P_0c0738a8: /* original 430b, guest PC 0x0c0738a8 */
if(!s->budget--) { s->failed_pc=0x0c0738a8u; return 0; }
target=r[3];
r[16]=0x0c0738acu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0738acu) { target=s->pc; goto dispatch; }
goto P_0c0738ac;
P_0c0738aa: /* original 64e3, guest PC 0x0c0738aa */
if(!s->budget--) { s->failed_pc=0x0c0738aau; return 0; }
r[4]=r[14];
goto P_0c0738ac;
P_0c0738ac: /* original d22e, guest PC 0x0c0738ac */
if(!s->budget--) { s->failed_pc=0x0c0738acu; return 0; }
r[2]=read(ram,0x0c073968u,4);
goto P_0c0738ae;
P_0c0738ae: /* original 65d3, guest PC 0x0c0738ae */
if(!s->budget--) { s->failed_pc=0x0c0738aeu; return 0; }
r[5]=r[13];
goto P_0c0738b0;
P_0c0738b0: /* original 420b, guest PC 0x0c0738b0 */
if(!s->budget--) { s->failed_pc=0x0c0738b0u; return 0; }
target=r[2];
r[16]=0x0c0738b4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0738b4u) { target=s->pc; goto dispatch; }
goto P_0c0738b4;
P_0c0738b2: /* original 64e3, guest PC 0x0c0738b2 */
if(!s->budget--) { s->failed_pc=0x0c0738b2u; return 0; }
r[4]=r[14];
goto P_0c0738b4;
P_0c0738b4: /* original 65d3, guest PC 0x0c0738b4 */
if(!s->budget--) { s->failed_pc=0x0c0738b4u; return 0; }
r[5]=r[13];
goto P_0c0738b6;
P_0c0738b6: /* original b7a3, guest PC 0x0c0738b6 */
if(!s->budget--) { s->failed_pc=0x0c0738b6u; return 0; }
target=0x0c074800u; r[16]=0x0c0738bau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0738bau) { target=s->pc; goto dispatch; }
goto P_0c0738ba;
P_0c0738b8: /* original 64e3, guest PC 0x0c0738b8 */
if(!s->budget--) { s->failed_pc=0x0c0738b8u; return 0; }
r[4]=r[14];
goto P_0c0738ba;
P_0c0738ba: /* original d22c, guest PC 0x0c0738ba */
if(!s->budget--) { s->failed_pc=0x0c0738bau; return 0; }
r[2]=read(ram,0x0c07396cu,4);
goto P_0c0738bc;
P_0c0738bc: /* original 65d3, guest PC 0x0c0738bc */
if(!s->budget--) { s->failed_pc=0x0c0738bcu; return 0; }
r[5]=r[13];
goto P_0c0738be;
P_0c0738be: /* original 420b, guest PC 0x0c0738be */
if(!s->budget--) { s->failed_pc=0x0c0738beu; return 0; }
target=r[2];
r[16]=0x0c0738c2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0738c2u) { target=s->pc; goto dispatch; }
goto P_0c0738c2;
P_0c0738c0: /* original 64e3, guest PC 0x0c0738c0 */
if(!s->budget--) { s->failed_pc=0x0c0738c0u; return 0; }
r[4]=r[14];
goto P_0c0738c2;
P_0c0738c2: /* original 65e3, guest PC 0x0c0738c2 */
if(!s->budget--) { s->failed_pc=0x0c0738c2u; return 0; }
r[5]=r[14];
goto P_0c0738c4;
P_0c0738c4: /* original 66d3, guest PC 0x0c0738c4 */
if(!s->budget--) { s->failed_pc=0x0c0738c4u; return 0; }
r[6]=r[13];
goto P_0c0738c6;
P_0c0738c6: /* original b664, guest PC 0x0c0738c6 */
if(!s->budget--) { s->failed_pc=0x0c0738c6u; return 0; }
target=0x0c074592u; r[16]=0x0c0738cau;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0738cau) { target=s->pc; goto dispatch; }
goto P_0c0738ca;
P_0c0738c8: /* original 64c3, guest PC 0x0c0738c8 */
if(!s->budget--) { s->failed_pc=0x0c0738c8u; return 0; }
r[4]=r[12];
goto P_0c0738ca;
P_0c0738ca: /* original d229, guest PC 0x0c0738ca */
if(!s->budget--) { s->failed_pc=0x0c0738cau; return 0; }
r[2]=read(ram,0x0c073970u,4);
goto P_0c0738cc;
P_0c0738cc: /* original 1c23, guest PC 0x0c0738cc */
if(!s->budget--) { s->failed_pc=0x0c0738ccu; return 0; }
write(ram,r[12]+12,r[2],4);
goto P_0c0738ce;
P_0c0738ce: /* original 4f26, guest PC 0x0c0738ce */
if(!s->budget--) { s->failed_pc=0x0c0738ceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0738d0;
P_0c0738d0: /* original 6cf6, guest PC 0x0c0738d0 */
if(!s->budget--) { s->failed_pc=0x0c0738d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0738d2;
P_0c0738d2: /* original 6df6, guest PC 0x0c0738d2 */
if(!s->budget--) { s->failed_pc=0x0c0738d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0738d4;
P_0c0738d4: /* original 000b, guest PC 0x0c0738d4 */
if(!s->budget--) { s->failed_pc=0x0c0738d4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0738d6: /* original 6ef6, guest PC 0x0c0738d6 */
if(!s->budget--) { s->failed_pc=0x0c0738d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0738d8u,s,ram);
P_0c081a46: /* original 4f22, guest PC 0x0c081a46 */
if(!s->budget--) { s->failed_pc=0x0c081a46u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c081a48;
P_0c081a48: /* original 6263, guest PC 0x0c081a48 */
if(!s->budget--) { s->failed_pc=0x0c081a48u; return 0; }
r[2]=r[6];
goto P_0c081a4a;
P_0c081a4a: /* original 4f12, guest PC 0x0c081a4a */
if(!s->budget--) { s->failed_pc=0x0c081a4au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c081a4c;
P_0c081a4c: /* original 7ff0, guest PC 0x0c081a4c */
if(!s->budget--) { s->failed_pc=0x0c081a4cu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c081a4e;
P_0c081a4e: /* original 1f41, guest PC 0x0c081a4e */
if(!s->budget--) { s->failed_pc=0x0c081a4eu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c081a50;
P_0c081a50: /* original 2f62, guest PC 0x0c081a50 */
if(!s->budget--) { s->failed_pc=0x0c081a50u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c081a52;
P_0c081a52: /* original d339, guest PC 0x0c081a52 */
if(!s->budget--) { s->failed_pc=0x0c081a52u; return 0; }
r[3]=read(ram,0x0c081b38u,4);
goto P_0c081a54;
P_0c081a54: /* original 6430, guest PC 0x0c081a54 */
if(!s->budget--) { s->failed_pc=0x0c081a54u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[4]=tmp;
goto P_0c081a56;
P_0c081a56: /* original 224f, guest PC 0x0c081a56 */
if(!s->budget--) { s->failed_pc=0x0c081a56u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[2]*(int32_t)(int16_t)r[4]);
goto P_0c081a58;
P_0c081a58: /* original 52f1, guest PC 0x0c081a58 */
if(!s->budget--) { s->failed_pc=0x0c081a58u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c081a5a;
P_0c081a5a: /* original 041a, guest PC 0x0c081a5a */
if(!s->budget--) { s->failed_pc=0x0c081a5au; return 0; }
r[4]=r[19];
goto P_0c081a5c;
P_0c081a5c: /* original 342c, guest PC 0x0c081a5c */
if(!s->budget--) { s->failed_pc=0x0c081a5cu; return 0; }
r[4]+=r[2];
goto P_0c081a5e;
P_0c081a5e: /* original e207, guest PC 0x0c081a5e */
if(!s->budget--) { s->failed_pc=0x0c081a5eu; return 0; }
r[2]=0x00000007u;
goto P_0c081a60;
P_0c081a60: /* original 644e, guest PC 0x0c081a60 */
if(!s->budget--) { s->failed_pc=0x0c081a60u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c081a62;
P_0c081a62: /* original 452c, guest PC 0x0c081a62 */
if(!s->budget--) { s->failed_pc=0x0c081a62u; return 0; }
r[5]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[5]>>((-r[2])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[2]&31u);
goto P_0c081a64;
P_0c081a64: /* original 4400, guest PC 0x0c081a64 */
if(!s->budget--) { s->failed_pc=0x0c081a64u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c081a66;
P_0c081a66: /* original 1f52, guest PC 0x0c081a66 */
if(!s->budget--) { s->failed_pc=0x0c081a66u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c081a68;
P_0c081a68: /* original 245b, guest PC 0x0c081a68 */
if(!s->budget--) { s->failed_pc=0x0c081a68u; return 0; }
r[4]|=r[5];
goto P_0c081a6a;
P_0c081a6a: /* original 1f43, guest PC 0x0c081a6a */
if(!s->budget--) { s->failed_pc=0x0c081a6au; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c081a6c;
P_0c081a6c: /* original d533, guest PC 0x0c081a6c */
if(!s->budget--) { s->failed_pc=0x0c081a6cu; return 0; }
r[5]=read(ram,0x0c081b3cu,4);
goto P_0c081a6e;
P_0c081a6e: /* original d134, guest PC 0x0c081a6e */
if(!s->budget--) { s->failed_pc=0x0c081a6eu; return 0; }
r[1]=read(ram,0x0c081b40u,4);
goto P_0c081a70;
P_0c081a70: /* original 410b, guest PC 0x0c081a70 */
if(!s->budget--) { s->failed_pc=0x0c081a70u; return 0; }
target=r[1];
r[16]=0x0c081a74u;
r[6]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081a74u) { target=s->pc; goto dispatch; }
goto P_0c081a74;
P_0c081a72: /* original e601, guest PC 0x0c081a72 */
if(!s->budget--) { s->failed_pc=0x0c081a72u; return 0; }
r[6]=0x00000001u;
goto P_0c081a74;
P_0c081a74: /* original d333, guest PC 0x0c081a74 */
if(!s->budget--) { s->failed_pc=0x0c081a74u; return 0; }
r[3]=read(ram,0x0c081b44u,4);
goto P_0c081a76;
P_0c081a76: /* original 62f2, guest PC 0x0c081a76 */
if(!s->budget--) { s->failed_pc=0x0c081a76u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c081a78;
P_0c081a78: /* original 6430, guest PC 0x0c081a78 */
if(!s->budget--) { s->failed_pc=0x0c081a78u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[4]=tmp;
goto P_0c081a7a;
P_0c081a7a: /* original 224f, guest PC 0x0c081a7a */
if(!s->budget--) { s->failed_pc=0x0c081a7au; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[2]*(int32_t)(int16_t)r[4]);
goto P_0c081a7c;
P_0c081a7c: /* original 52f1, guest PC 0x0c081a7c */
if(!s->budget--) { s->failed_pc=0x0c081a7cu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c081a7e;
P_0c081a7e: /* original 041a, guest PC 0x0c081a7e */
if(!s->budget--) { s->failed_pc=0x0c081a7eu; return 0; }
r[4]=r[19];
goto P_0c081a80;
P_0c081a80: /* original 342c, guest PC 0x0c081a80 */
if(!s->budget--) { s->failed_pc=0x0c081a80u; return 0; }
r[4]+=r[2];
goto P_0c081a82;
P_0c081a82: /* original 52f2, guest PC 0x0c081a82 */
if(!s->budget--) { s->failed_pc=0x0c081a82u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c081a84;
P_0c081a84: /* original 644e, guest PC 0x0c081a84 */
if(!s->budget--) { s->failed_pc=0x0c081a84u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c081a86;
P_0c081a86: /* original 4400, guest PC 0x0c081a86 */
if(!s->budget--) { s->failed_pc=0x0c081a86u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c081a88;
P_0c081a88: /* original 242b, guest PC 0x0c081a88 */
if(!s->budget--) { s->failed_pc=0x0c081a88u; return 0; }
r[4]|=r[2];
goto P_0c081a8a;
P_0c081a8a: /* original 2f42, guest PC 0x0c081a8a */
if(!s->budget--) { s->failed_pc=0x0c081a8au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c081a8c;
P_0c081a8c: /* original d52e, guest PC 0x0c081a8c */
if(!s->budget--) { s->failed_pc=0x0c081a8cu; return 0; }
r[5]=read(ram,0x0c081b48u,4);
goto P_0c081a8e;
P_0c081a8e: /* original d12c, guest PC 0x0c081a8e */
if(!s->budget--) { s->failed_pc=0x0c081a8eu; return 0; }
r[1]=read(ram,0x0c081b40u,4);
goto P_0c081a90;
P_0c081a90: /* original 410b, guest PC 0x0c081a90 */
if(!s->budget--) { s->failed_pc=0x0c081a90u; return 0; }
target=r[1];
r[16]=0x0c081a94u;
r[6]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081a94u) { target=s->pc; goto dispatch; }
goto P_0c081a94;
P_0c081a92: /* original e601, guest PC 0x0c081a92 */
if(!s->budget--) { s->failed_pc=0x0c081a92u; return 0; }
r[6]=0x00000001u;
goto P_0c081a94;
P_0c081a94: /* original 7f10, guest PC 0x0c081a94 */
if(!s->budget--) { s->failed_pc=0x0c081a94u; return 0; }
r[15]+=0x00000010u;
goto P_0c081a96;
P_0c081a96: /* original 4f16, guest PC 0x0c081a96 */
if(!s->budget--) { s->failed_pc=0x0c081a96u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c081a98;
P_0c081a98: /* original 4f26, guest PC 0x0c081a98 */
if(!s->budget--) { s->failed_pc=0x0c081a98u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c081a9a;
P_0c081a9a: /* original 000b, guest PC 0x0c081a9a */
if(!s->budget--) { s->failed_pc=0x0c081a9au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c081a9c: /* original 0009, guest PC 0x0c081a9c */
if(!s->budget--) { s->failed_pc=0x0c081a9cu; return 0; }
goto P_0c081a9e;
P_0c081a9e: /* original 4f22, guest PC 0x0c081a9e */
if(!s->budget--) { s->failed_pc=0x0c081a9eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c081aa0;
P_0c081aa0: /* original 6263, guest PC 0x0c081aa0 */
if(!s->budget--) { s->failed_pc=0x0c081aa0u; return 0; }
r[2]=r[6];
goto P_0c081aa2;
P_0c081aa2: /* original 4400, guest PC 0x0c081aa2 */
if(!s->budget--) { s->failed_pc=0x0c081aa2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c081aa4;
P_0c081aa4: /* original 4f12, guest PC 0x0c081aa4 */
if(!s->budget--) { s->failed_pc=0x0c081aa4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c081aa6;
P_0c081aa6: /* original 7ff0, guest PC 0x0c081aa6 */
if(!s->budget--) { s->failed_pc=0x0c081aa6u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c081aa8;
P_0c081aa8: /* original 1f51, guest PC 0x0c081aa8 */
if(!s->budget--) { s->failed_pc=0x0c081aa8u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c081aaa;
P_0c081aaa: /* original 2f62, guest PC 0x0c081aaa */
if(!s->budget--) { s->failed_pc=0x0c081aaau; return 0; }
write(ram,r[15],r[6],4);
goto P_0c081aac;
P_0c081aac: /* original e601, guest PC 0x0c081aac */
if(!s->budget--) { s->failed_pc=0x0c081aacu; return 0; }
r[6]=0x00000001u;
goto P_0c081aae;
P_0c081aae: /* original d322, guest PC 0x0c081aae */
if(!s->budget--) { s->failed_pc=0x0c081aaeu; return 0; }
r[3]=read(ram,0x0c081b38u,4);
goto P_0c081ab0;
P_0c081ab0: /* original 6530, guest PC 0x0c081ab0 */
if(!s->budget--) { s->failed_pc=0x0c081ab0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[5]=tmp;
goto P_0c081ab2;
P_0c081ab2: /* original 225f, guest PC 0x0c081ab2 */
if(!s->budget--) { s->failed_pc=0x0c081ab2u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[2]*(int32_t)(int16_t)r[5]);
goto P_0c081ab4;
P_0c081ab4: /* original 52f1, guest PC 0x0c081ab4 */
if(!s->budget--) { s->failed_pc=0x0c081ab4u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c081ab6;
P_0c081ab6: /* original 1f42, guest PC 0x0c081ab6 */
if(!s->budget--) { s->failed_pc=0x0c081ab6u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c081ab8;
P_0c081ab8: /* original 051a, guest PC 0x0c081ab8 */
if(!s->budget--) { s->failed_pc=0x0c081ab8u; return 0; }
r[5]=r[19];
goto P_0c081aba;
P_0c081aba: /* original 352c, guest PC 0x0c081aba */
if(!s->budget--) { s->failed_pc=0x0c081abau; return 0; }
r[5]+=r[2];
goto P_0c081abc;
P_0c081abc: /* original e207, guest PC 0x0c081abc */
if(!s->budget--) { s->failed_pc=0x0c081abcu; return 0; }
r[2]=0x00000007u;
goto P_0c081abe;
P_0c081abe: /* original 655e, guest PC 0x0c081abe */
if(!s->budget--) { s->failed_pc=0x0c081abeu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c081ac0;
P_0c081ac0: /* original 452c, guest PC 0x0c081ac0 */
if(!s->budget--) { s->failed_pc=0x0c081ac0u; return 0; }
r[5]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[5]>>((-r[2])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[2]&31u);
goto P_0c081ac2;
P_0c081ac2: /* original 254b, guest PC 0x0c081ac2 */
if(!s->budget--) { s->failed_pc=0x0c081ac2u; return 0; }
r[5]|=r[4];
goto P_0c081ac4;
P_0c081ac4: /* original 1f53, guest PC 0x0c081ac4 */
if(!s->budget--) { s->failed_pc=0x0c081ac4u; return 0; }
write(ram,r[15]+12,r[5],4);
goto P_0c081ac6;
P_0c081ac6: /* original d51d, guest PC 0x0c081ac6 */
if(!s->budget--) { s->failed_pc=0x0c081ac6u; return 0; }
r[5]=read(ram,0x0c081b3cu,4);
goto P_0c081ac8;
P_0c081ac8: /* original d11d, guest PC 0x0c081ac8 */
if(!s->budget--) { s->failed_pc=0x0c081ac8u; return 0; }
r[1]=read(ram,0x0c081b40u,4);
goto P_0c081aca;
P_0c081aca: /* original 410b, guest PC 0x0c081aca */
if(!s->budget--) { s->failed_pc=0x0c081acau; return 0; }
target=r[1];
r[16]=0x0c081aceu;
r[4]=read(ram,r[15]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081aceu) { target=s->pc; goto dispatch; }
goto P_0c081ace;
P_0c081acc: /* original 54f3, guest PC 0x0c081acc */
if(!s->budget--) { s->failed_pc=0x0c081accu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c081ace;
P_0c081ace: /* original d31d, guest PC 0x0c081ace */
if(!s->budget--) { s->failed_pc=0x0c081aceu; return 0; }
r[3]=read(ram,0x0c081b44u,4);
goto P_0c081ad0;
P_0c081ad0: /* original 62f2, guest PC 0x0c081ad0 */
if(!s->budget--) { s->failed_pc=0x0c081ad0u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c081ad2;
P_0c081ad2: /* original 6430, guest PC 0x0c081ad2 */
if(!s->budget--) { s->failed_pc=0x0c081ad2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[4]=tmp;
goto P_0c081ad4;
P_0c081ad4: /* original 51f2, guest PC 0x0c081ad4 */
if(!s->budget--) { s->failed_pc=0x0c081ad4u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c081ad6;
P_0c081ad6: /* original 224f, guest PC 0x0c081ad6 */
if(!s->budget--) { s->failed_pc=0x0c081ad6u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[2]*(int32_t)(int16_t)r[4]);
goto P_0c081ad8;
P_0c081ad8: /* original 52f1, guest PC 0x0c081ad8 */
if(!s->budget--) { s->failed_pc=0x0c081ad8u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c081ada;
P_0c081ada: /* original 041a, guest PC 0x0c081ada */
if(!s->budget--) { s->failed_pc=0x0c081adau; return 0; }
r[4]=r[19];
goto P_0c081adc;
P_0c081adc: /* original 342c, guest PC 0x0c081adc */
if(!s->budget--) { s->failed_pc=0x0c081adcu; return 0; }
r[4]+=r[2];
goto P_0c081ade;
P_0c081ade: /* original e207, guest PC 0x0c081ade */
if(!s->budget--) { s->failed_pc=0x0c081adeu; return 0; }
r[2]=0x00000007u;
goto P_0c081ae0;
P_0c081ae0: /* original 644e, guest PC 0x0c081ae0 */
if(!s->budget--) { s->failed_pc=0x0c081ae0u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c081ae2;
P_0c081ae2: /* original 442c, guest PC 0x0c081ae2 */
if(!s->budget--) { s->failed_pc=0x0c081ae2u; return 0; }
r[4]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[4]>>((-r[2])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[2]&31u);
goto P_0c081ae4;
P_0c081ae4: /* original 241b, guest PC 0x0c081ae4 */
if(!s->budget--) { s->failed_pc=0x0c081ae4u; return 0; }
r[4]|=r[1];
goto P_0c081ae6;
P_0c081ae6: /* original 2f42, guest PC 0x0c081ae6 */
if(!s->budget--) { s->failed_pc=0x0c081ae6u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c081ae8;
P_0c081ae8: /* original d518, guest PC 0x0c081ae8 */
if(!s->budget--) { s->failed_pc=0x0c081ae8u; return 0; }
r[5]=read(ram,0x0c081b4cu,4);
goto P_0c081aea;
P_0c081aea: /* original d315, guest PC 0x0c081aea */
if(!s->budget--) { s->failed_pc=0x0c081aeau; return 0; }
r[3]=read(ram,0x0c081b40u,4);
goto P_0c081aec;
P_0c081aec: /* original 430b, guest PC 0x0c081aec */
if(!s->budget--) { s->failed_pc=0x0c081aecu; return 0; }
target=r[3];
r[16]=0x0c081af0u;
r[6]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081af0u) { target=s->pc; goto dispatch; }
goto P_0c081af0;
P_0c081aee: /* original e601, guest PC 0x0c081aee */
if(!s->budget--) { s->failed_pc=0x0c081aeeu; return 0; }
r[6]=0x00000001u;
goto P_0c081af0;
P_0c081af0: /* original 7f10, guest PC 0x0c081af0 */
if(!s->budget--) { s->failed_pc=0x0c081af0u; return 0; }
r[15]+=0x00000010u;
goto P_0c081af2;
P_0c081af2: /* original 4f16, guest PC 0x0c081af2 */
if(!s->budget--) { s->failed_pc=0x0c081af2u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c081af4;
P_0c081af4: /* original 4f26, guest PC 0x0c081af4 */
if(!s->budget--) { s->failed_pc=0x0c081af4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c081af6;
P_0c081af6: /* original 000b, guest PC 0x0c081af6 */
if(!s->budget--) { s->failed_pc=0x0c081af6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c081af8: /* original 0009, guest PC 0x0c081af8 */
if(!s->budget--) { s->failed_pc=0x0c081af8u; return 0; }
return vf3_matrix_family(0x0c081afau,s,ram);
P_0c08919e: /* original 4f22, guest PC 0x0c08919e */
if(!s->budget--) { s->failed_pc=0x0c08919eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0891a0;
P_0c0891a0: /* original 2238, guest PC 0x0c0891a0 */
if(!s->budget--) { s->failed_pc=0x0c0891a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0891a2;
P_0c0891a2: /* original 8f5b, guest PC 0x0c0891a2 */
if(!s->budget--) { s->failed_pc=0x0c0891a2u; return 0; }
cond=r[17]&1u;
r[8]=r[4];
if(!cond) { goto P_0c08925c; }
goto P_0c0891a6;
P_0c0891a4: /* original 6843, guest PC 0x0c0891a4 */
if(!s->budget--) { s->failed_pc=0x0c0891a4u; return 0; }
r[8]=r[4];
goto P_0c0891a6;
P_0c0891a6: /* original c73f, guest PC 0x0c0891a6 */
if(!s->budget--) { s->failed_pc=0x0c0891a6u; return 0; }
r[0]=0x0c0892a4u;
goto P_0c0891a8;
P_0c0891a8: /* original 6e93, guest PC 0x0c0891a8 */
if(!s->budget--) { s->failed_pc=0x0c0891a8u; return 0; }
r[14]=r[9];
goto P_0c0891aa;
P_0c0891aa: /* original e300, guest PC 0x0c0891aa */
if(!s->budget--) { s->failed_pc=0x0c0891aau; return 0; }
r[3]=0x00000000u;
goto P_0c0891ac;
P_0c0891ac: /* original 7e18, guest PC 0x0c0891ac */
if(!s->budget--) { s->failed_pc=0x0c0891acu; return 0; }
r[14]+=0x00000018u;
goto P_0c0891ae;
P_0c0891ae: /* original 1835, guest PC 0x0c0891ae */
if(!s->budget--) { s->failed_pc=0x0c0891aeu; return 0; }
write(ram,r[8]+20,r[3],4);
goto P_0c0891b0;
P_0c0891b0: /* original da3d, guest PC 0x0c0891b0 */
if(!s->budget--) { s->failed_pc=0x0c0891b0u; return 0; }
r[10]=read(ram,0x0c0892a8u,4);
goto P_0c0891b2;
P_0c0891b2: /* original ff08, guest PC 0x0c0891b2 */
if(!s->budget--) { s->failed_pc=0x0c0891b2u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0891b4;
P_0c0891b4: /* original dc3d, guest PC 0x0c0891b4 */
if(!s->budget--) { s->failed_pc=0x0c0891b4u; return 0; }
r[12]=read(ram,0x0c0892acu,4);
goto P_0c0891b6;
P_0c0891b6: /* original a048, guest PC 0x0c0891b6 */
if(!s->budget--) { s->failed_pc=0x0c0891b6u; return 0; }
r[11]=0x00000005u;
goto P_0c08924a;
P_0c0891b8: /* original eb05, guest PC 0x0c0891b8 */
if(!s->budget--) { s->failed_pc=0x0c0891b8u; return 0; }
r[11]=0x00000005u;
goto P_0c0891ba;
P_0c0891ba: /* original 6db3, guest PC 0x0c0891ba */
if(!s->budget--) { s->failed_pc=0x0c0891bau; return 0; }
r[13]=r[11];
goto P_0c0891bc;
P_0c0891bc: /* original 7dff, guest PC 0x0c0891bc */
if(!s->budget--) { s->failed_pc=0x0c0891bcu; return 0; }
r[13]+=0xffffffffu;
goto P_0c0891be;
P_0c0891be: /* original 64d3, guest PC 0x0c0891be */
if(!s->budget--) { s->failed_pc=0x0c0891beu; return 0; }
r[4]=r[13];
goto P_0c0891c0;
P_0c0891c0: /* original 4400, guest PC 0x0c0891c0 */
if(!s->budget--) { s->failed_pc=0x0c0891c0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0891c2;
P_0c0891c2: /* original 62d3, guest PC 0x0c0891c2 */
if(!s->budget--) { s->failed_pc=0x0c0891c2u; return 0; }
r[2]=r[13];
goto P_0c0891c4;
P_0c0891c4: /* original 6043, guest PC 0x0c0891c4 */
if(!s->budget--) { s->failed_pc=0x0c0891c4u; return 0; }
r[0]=r[4];
goto P_0c0891c6;
P_0c0891c6: /* original 4208, guest PC 0x0c0891c6 */
if(!s->budget--) { s->failed_pc=0x0c0891c6u; return 0; }
r[2]<<=2;
goto P_0c0891c8;
P_0c0891c8: /* original 6383, guest PC 0x0c0891c8 */
if(!s->budget--) { s->failed_pc=0x0c0891c8u; return 0; }
r[3]=r[8];
goto P_0c0891ca;
P_0c0891ca: /* original 4008, guest PC 0x0c0891ca */
if(!s->budget--) { s->failed_pc=0x0c0891cau; return 0; }
r[0]<<=2;
goto P_0c0891cc;
P_0c0891cc: /* original 323c, guest PC 0x0c0891cc */
if(!s->budget--) { s->failed_pc=0x0c0891ccu; return 0; }
r[2]+=r[3];
goto P_0c0891ce;
P_0c0891ce: /* original e12c, guest PC 0x0c0891ce */
if(!s->budget--) { s->failed_pc=0x0c0891ceu; return 0; }
r[1]=0x0000002cu;
goto P_0c0891d0;
P_0c0891d0: /* original 22e2, guest PC 0x0c0891d0 */
if(!s->budget--) { s->failed_pc=0x0c0891d0u; return 0; }
write(ram,r[2],r[14],4);
goto P_0c0891d2;
P_0c0891d2: /* original 03ae, guest PC 0x0c0891d2 */
if(!s->budget--) { s->failed_pc=0x0c0891d2u; return 0; }
r[3]=read(ram,r[10]+r[0],4);
goto P_0c0891d4;
P_0c0891d4: /* original 6043, guest PC 0x0c0891d4 */
if(!s->budget--) { s->failed_pc=0x0c0891d4u; return 0; }
r[0]=r[4];
goto P_0c0891d6;
P_0c0891d6: /* original 7001, guest PC 0x0c0891d6 */
if(!s->budget--) { s->failed_pc=0x0c0891d6u; return 0; }
r[0]+=0x00000001u;
goto P_0c0891d8;
P_0c0891d8: /* original 64d3, guest PC 0x0c0891d8 */
if(!s->budget--) { s->failed_pc=0x0c0891d8u; return 0; }
r[4]=r[13];
goto P_0c0891da;
P_0c0891da: /* original 4008, guest PC 0x0c0891da */
if(!s->budget--) { s->failed_pc=0x0c0891dau; return 0; }
r[0]<<=2;
goto P_0c0891dc;
P_0c0891dc: /* original 1e39, guest PC 0x0c0891dc */
if(!s->budget--) { s->failed_pc=0x0c0891dcu; return 0; }
write(ram,r[14]+36,r[3],4);
goto P_0c0891de;
P_0c0891de: /* original 03ae, guest PC 0x0c0891de */
if(!s->budget--) { s->failed_pc=0x0c0891deu; return 0; }
r[3]=read(ram,r[10]+r[0],4);
goto P_0c0891e0;
P_0c0891e0: /* original 4408, guest PC 0x0c0891e0 */
if(!s->budget--) { s->failed_pc=0x0c0891e0u; return 0; }
r[4]<<=2;
goto P_0c0891e2;
P_0c0891e2: /* original 4400, guest PC 0x0c0891e2 */
if(!s->budget--) { s->failed_pc=0x0c0891e2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0891e4;
P_0c0891e4: /* original 1e3a, guest PC 0x0c0891e4 */
if(!s->budget--) { s->failed_pc=0x0c0891e4u; return 0; }
write(ram,r[14]+40,r[3],4);
goto P_0c0891e6;
P_0c0891e6: /* original 31ec, guest PC 0x0c0891e6 */
if(!s->budget--) { s->failed_pc=0x0c0891e6u; return 0; }
r[1]+=r[14];
goto P_0c0891e8;
P_0c0891e8: /* original d331, guest PC 0x0c0891e8 */
if(!s->budget--) { s->failed_pc=0x0c0891e8u; return 0; }
r[3]=read(ram,0x0c0892b0u,4);
goto P_0c0891ea;
P_0c0891ea: /* original e22d, guest PC 0x0c0891ea */
if(!s->budget--) { s->failed_pc=0x0c0891eau; return 0; }
r[2]=0x0000002du;
goto P_0c0891ec;
P_0c0891ec: /* original 32ec, guest PC 0x0c0891ec */
if(!s->budget--) { s->failed_pc=0x0c0891ecu; return 0; }
r[2]+=r[14];
goto P_0c0891ee;
P_0c0891ee: /* original 343c, guest PC 0x0c0891ee */
if(!s->budget--) { s->failed_pc=0x0c0891eeu; return 0; }
r[4]+=r[3];
goto P_0c0891f0;
P_0c0891f0: /* original 8442, guest PC 0x0c0891f0 */
if(!s->budget--) { s->failed_pc=0x0c0891f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c0891f2;
P_0c0891f2: /* original 2100, guest PC 0x0c0891f2 */
if(!s->budget--) { s->failed_pc=0x0c0891f2u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0891f4;
P_0c0891f4: /* original 8443, guest PC 0x0c0891f4 */
if(!s->budget--) { s->failed_pc=0x0c0891f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c0891f6;
P_0c0891f6: /* original 2200, guest PC 0x0c0891f6 */
if(!s->budget--) { s->failed_pc=0x0c0891f6u; return 0; }
write(ram,r[2],r[0],1);
goto P_0c0891f8;
P_0c0891f8: /* original e004, guest PC 0x0c0891f8 */
if(!s->budget--) { s->failed_pc=0x0c0891f8u; return 0; }
r[0]=0x00000004u;
goto P_0c0891fa;
P_0c0891fa: /* original f346, guest PC 0x0c0891fa */
if(!s->budget--) { s->failed_pc=0x0c0891fau; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0891fc;
P_0c0891fc: /* original e01c, guest PC 0x0c0891fc */
if(!s->budget--) { s->failed_pc=0x0c0891fcu; return 0; }
r[0]=0x0000001cu;
goto P_0c0891fe;
P_0c0891fe: /* original e528, guest PC 0x0c0891fe */
if(!s->budget--) { s->failed_pc=0x0c0891feu; return 0; }
r[5]=0x00000028u;
goto P_0c089200;
P_0c089200: /* original fe37, guest PC 0x0c089200 */
if(!s->budget--) { s->failed_pc=0x0c089200u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089202;
P_0c089202: /* original e634, guest PC 0x0c089202 */
if(!s->budget--) { s->failed_pc=0x0c089202u; return 0; }
r[6]=0x00000034u;
goto P_0c089204;
P_0c089204: /* original 6741, guest PC 0x0c089204 */
if(!s->budget--) { s->failed_pc=0x0c089204u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[7]=tmp;
goto P_0c089206;
P_0c089206: /* original d22b, guest PC 0x0c089206 */
if(!s->budget--) { s->failed_pc=0x0c089206u; return 0; }
r[2]=read(ram,0x0c0892b4u,4);
goto P_0c089208;
P_0c089208: /* original 420b, guest PC 0x0c089208 */
if(!s->budget--) { s->failed_pc=0x0c089208u; return 0; }
target=r[2];
r[16]=0x0c08920cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08920cu) { target=s->pc; goto dispatch; }
goto P_0c08920c;
P_0c08920a: /* original 64e3, guest PC 0x0c08920a */
if(!s->budget--) { s->failed_pc=0x0c08920au; return 0; }
r[4]=r[14];
goto P_0c08920c;
P_0c08920c: /* original 64d3, guest PC 0x0c08920c */
if(!s->budget--) { s->failed_pc=0x0c08920cu; return 0; }
r[4]=r[13];
goto P_0c08920e;
P_0c08920e: /* original 4408, guest PC 0x0c08920e */
if(!s->budget--) { s->failed_pc=0x0c08920eu; return 0; }
r[4]<<=2;
goto P_0c089210;
P_0c089210: /* original 6503, guest PC 0x0c089210 */
if(!s->budget--) { s->failed_pc=0x0c089210u; return 0; }
r[5]=r[0];
goto P_0c089212;
P_0c089212: /* original 6043, guest PC 0x0c089212 */
if(!s->budget--) { s->failed_pc=0x0c089212u; return 0; }
r[0]=r[4];
goto P_0c089214;
P_0c089214: /* original 4008, guest PC 0x0c089214 */
if(!s->budget--) { s->failed_pc=0x0c089214u; return 0; }
r[0]<<=2;
goto P_0c089216;
P_0c089216: /* original f3c6, guest PC 0x0c089216 */
if(!s->budget--) { s->failed_pc=0x0c089216u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c089218;
P_0c089218: /* original e00c, guest PC 0x0c089218 */
if(!s->budget--) { s->failed_pc=0x0c089218u; return 0; }
r[0]=0x0000000cu;
goto P_0c08921a;
P_0c08921a: /* original 7bff, guest PC 0x0c08921a */
if(!s->budget--) { s->failed_pc=0x0c08921au; return 0; }
r[11]+=0xffffffffu;
goto P_0c08921c;
P_0c08921c: /* original fe37, guest PC 0x0c08921c */
if(!s->budget--) { s->failed_pc=0x0c08921cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08921e;
P_0c08921e: /* original 6043, guest PC 0x0c08921e */
if(!s->budget--) { s->failed_pc=0x0c08921eu; return 0; }
r[0]=r[4];
goto P_0c089220;
P_0c089220: /* original 7001, guest PC 0x0c089220 */
if(!s->budget--) { s->failed_pc=0x0c089220u; return 0; }
r[0]+=0x00000001u;
goto P_0c089222;
P_0c089222: /* original 4008, guest PC 0x0c089222 */
if(!s->budget--) { s->failed_pc=0x0c089222u; return 0; }
r[0]<<=2;
goto P_0c089224;
P_0c089224: /* original f3c6, guest PC 0x0c089224 */
if(!s->budget--) { s->failed_pc=0x0c089224u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c089226;
P_0c089226: /* original e010, guest PC 0x0c089226 */
if(!s->budget--) { s->failed_pc=0x0c089226u; return 0; }
r[0]=0x00000010u;
goto P_0c089228;
P_0c089228: /* original fe37, guest PC 0x0c089228 */
if(!s->budget--) { s->failed_pc=0x0c089228u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08922a;
P_0c08922a: /* original 6043, guest PC 0x0c08922a */
if(!s->budget--) { s->failed_pc=0x0c08922au; return 0; }
r[0]=r[4];
goto P_0c08922c;
P_0c08922c: /* original 7002, guest PC 0x0c08922c */
if(!s->budget--) { s->failed_pc=0x0c08922cu; return 0; }
r[0]+=0x00000002u;
goto P_0c08922e;
P_0c08922e: /* original 4008, guest PC 0x0c08922e */
if(!s->budget--) { s->failed_pc=0x0c08922eu; return 0; }
r[0]<<=2;
goto P_0c089230;
P_0c089230: /* original f3c6, guest PC 0x0c089230 */
if(!s->budget--) { s->failed_pc=0x0c089230u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c089232;
P_0c089232: /* original e014, guest PC 0x0c089232 */
if(!s->budget--) { s->failed_pc=0x0c089232u; return 0; }
r[0]=0x00000014u;
goto P_0c089234;
P_0c089234: /* original fe37, guest PC 0x0c089234 */
if(!s->budget--) { s->failed_pc=0x0c089234u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089236;
P_0c089236: /* original 6043, guest PC 0x0c089236 */
if(!s->budget--) { s->failed_pc=0x0c089236u; return 0; }
r[0]=r[4];
goto P_0c089238;
P_0c089238: /* original 7003, guest PC 0x0c089238 */
if(!s->budget--) { s->failed_pc=0x0c089238u; return 0; }
r[0]+=0x00000003u;
goto P_0c08923a;
P_0c08923a: /* original 4008, guest PC 0x0c08923a */
if(!s->budget--) { s->failed_pc=0x0c08923au; return 0; }
r[0]<<=2;
goto P_0c08923c;
P_0c08923c: /* original f3c6, guest PC 0x0c08923c */
if(!s->budget--) { s->failed_pc=0x0c08923cu; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c08923e;
P_0c08923e: /* original e018, guest PC 0x0c08923e */
if(!s->budget--) { s->failed_pc=0x0c08923eu; return 0; }
r[0]=0x00000018u;
goto P_0c089240;
P_0c089240: /* original fe37, guest PC 0x0c089240 */
if(!s->budget--) { s->failed_pc=0x0c089240u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089242;
P_0c089242: /* original e020, guest PC 0x0c089242 */
if(!s->budget--) { s->failed_pc=0x0c089242u; return 0; }
r[0]=0x00000020u;
goto P_0c089244;
P_0c089244: /* original fef7, guest PC 0x0c089244 */
if(!s->budget--) { s->failed_pc=0x0c089244u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c089246;
P_0c089246: /* original 6e53, guest PC 0x0c089246 */
if(!s->budget--) { s->failed_pc=0x0c089246u; return 0; }
r[14]=r[5];
goto P_0c089248;
P_0c089248: /* original 7e28, guest PC 0x0c089248 */
if(!s->budget--) { s->failed_pc=0x0c089248u; return 0; }
r[14]+=0x00000028u;
goto P_0c08924a;
P_0c08924a: /* original 2bb8, guest PC 0x0c08924a */
if(!s->budget--) { s->failed_pc=0x0c08924au; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c08924c;
P_0c08924c: /* original 8bb5, guest PC 0x0c08924c */
if(!s->budget--) { s->failed_pc=0x0c08924cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0891ba; }
goto P_0c08924e;
P_0c08924e: /* original a003, guest PC 0x0c08924e */
if(!s->budget--) { s->failed_pc=0x0c08924eu; return 0; }
r[14]=0x0000003cu;
goto P_0c089258;
P_0c089250: /* original ee3c, guest PC 0x0c089250 */
if(!s->budget--) { s->failed_pc=0x0c089250u; return 0; }
r[14]=0x0000003cu;
goto P_0c089252;
P_0c089252: /* original b00d, guest PC 0x0c089252 */
if(!s->budget--) { s->failed_pc=0x0c089252u; return 0; }
target=0x0c089270u; r[16]=0x0c089256u;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c089256u) { target=s->pc; goto dispatch; }
goto P_0c089256;
P_0c089254: /* original 6493, guest PC 0x0c089254 */
if(!s->budget--) { s->failed_pc=0x0c089254u; return 0; }
r[4]=r[9];
goto P_0c089256;
P_0c089256: /* original 7eff, guest PC 0x0c089256 */
if(!s->budget--) { s->failed_pc=0x0c089256u; return 0; }
r[14]+=0xffffffffu;
goto P_0c089258;
P_0c089258: /* original 2ee8, guest PC 0x0c089258 */
if(!s->budget--) { s->failed_pc=0x0c089258u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c08925a;
P_0c08925a: /* original 8bfa, guest PC 0x0c08925a */
if(!s->budget--) { s->failed_pc=0x0c08925au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089252; }
goto P_0c08925c;
P_0c08925c: /* original 4f26, guest PC 0x0c08925c */
if(!s->budget--) { s->failed_pc=0x0c08925cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08925e;
P_0c08925e: /* original fff9, guest PC 0x0c08925e */
if(!s->budget--) { s->failed_pc=0x0c08925eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c089260;
P_0c089260: /* original 68f6, guest PC 0x0c089260 */
if(!s->budget--) { s->failed_pc=0x0c089260u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c089262;
P_0c089262: /* original 69f6, guest PC 0x0c089262 */
if(!s->budget--) { s->failed_pc=0x0c089262u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c089264;
P_0c089264: /* original 6af6, guest PC 0x0c089264 */
if(!s->budget--) { s->failed_pc=0x0c089264u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c089266;
P_0c089266: /* original 6bf6, guest PC 0x0c089266 */
if(!s->budget--) { s->failed_pc=0x0c089266u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c089268;
P_0c089268: /* original 6cf6, guest PC 0x0c089268 */
if(!s->budget--) { s->failed_pc=0x0c089268u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08926a;
P_0c08926a: /* original 6df6, guest PC 0x0c08926a */
if(!s->budget--) { s->failed_pc=0x0c08926au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08926c;
P_0c08926c: /* original 000b, guest PC 0x0c08926c */
if(!s->budget--) { s->failed_pc=0x0c08926cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08926e: /* original 6ef6, guest PC 0x0c08926e */
if(!s->budget--) { s->failed_pc=0x0c08926eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c089270;
P_0c089270: /* original 2fe6, guest PC 0x0c089270 */
if(!s->budget--) { s->failed_pc=0x0c089270u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089272;
P_0c089272: /* original 2fd6, guest PC 0x0c089272 */
if(!s->budget--) { s->failed_pc=0x0c089272u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089274;
P_0c089274: /* original 2fc6, guest PC 0x0c089274 */
if(!s->budget--) { s->failed_pc=0x0c089274u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089276;
P_0c089276: /* original 2fb6, guest PC 0x0c089276 */
if(!s->budget--) { s->failed_pc=0x0c089276u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089278;
P_0c089278: /* original 2fa6, guest PC 0x0c089278 */
if(!s->budget--) { s->failed_pc=0x0c089278u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08927a;
P_0c08927a: /* original 2f96, guest PC 0x0c08927a */
if(!s->budget--) { s->failed_pc=0x0c08927au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08927c;
P_0c08927c: /* original 2f86, guest PC 0x0c08927c */
if(!s->budget--) { s->failed_pc=0x0c08927cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
return vf3_matrix_family(0x0c08927eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c07385cu,0x0c07385eu,0x0c073860u,0x0c073862u,0x0c073864u,0x0c073866u,0x0c073868u,0x0c07386au,0x0c07386cu,0x0c07386eu,0x0c073870u,0x0c073872u,0x0c073874u,0x0c073876u,0x0c073878u,0x0c07387au,
0x0c07387cu,0x0c07387eu,0x0c073880u,0x0c073882u,0x0c073884u,0x0c073886u,0x0c073888u,0x0c07388au,0x0c07388cu,0x0c07388eu,0x0c073890u,0x0c073892u,0x0c073894u,0x0c073896u,0x0c073898u,0x0c07389au,
0x0c07389cu,0x0c07389eu,0x0c0738a0u,0x0c0738a2u,0x0c0738a4u,0x0c0738a6u,0x0c0738a8u,0x0c0738aau,0x0c0738acu,0x0c0738aeu,0x0c0738b0u,0x0c0738b2u,0x0c0738b4u,0x0c0738b6u,0x0c0738b8u,0x0c0738bau,
0x0c0738bcu,0x0c0738beu,0x0c0738c0u,0x0c0738c2u,0x0c0738c4u,0x0c0738c6u,0x0c0738c8u,0x0c0738cau,0x0c0738ccu,0x0c0738ceu,0x0c0738d0u,0x0c0738d2u,0x0c0738d4u,0x0c0738d6u,0x0c081a46u,0x0c081a48u,
0x0c081a4au,0x0c081a4cu,0x0c081a4eu,0x0c081a50u,0x0c081a52u,0x0c081a54u,0x0c081a56u,0x0c081a58u,0x0c081a5au,0x0c081a5cu,0x0c081a5eu,0x0c081a60u,0x0c081a62u,0x0c081a64u,0x0c081a66u,0x0c081a68u,
0x0c081a6au,0x0c081a6cu,0x0c081a6eu,0x0c081a70u,0x0c081a72u,0x0c081a74u,0x0c081a76u,0x0c081a78u,0x0c081a7au,0x0c081a7cu,0x0c081a7eu,0x0c081a80u,0x0c081a82u,0x0c081a84u,0x0c081a86u,0x0c081a88u,
0x0c081a8au,0x0c081a8cu,0x0c081a8eu,0x0c081a90u,0x0c081a92u,0x0c081a94u,0x0c081a96u,0x0c081a98u,0x0c081a9au,0x0c081a9cu,0x0c081a9eu,0x0c081aa0u,0x0c081aa2u,0x0c081aa4u,0x0c081aa6u,0x0c081aa8u,
0x0c081aaau,0x0c081aacu,0x0c081aaeu,0x0c081ab0u,0x0c081ab2u,0x0c081ab4u,0x0c081ab6u,0x0c081ab8u,0x0c081abau,0x0c081abcu,0x0c081abeu,0x0c081ac0u,0x0c081ac2u,0x0c081ac4u,0x0c081ac6u,0x0c081ac8u,
0x0c081acau,0x0c081accu,0x0c081aceu,0x0c081ad0u,0x0c081ad2u,0x0c081ad4u,0x0c081ad6u,0x0c081ad8u,0x0c081adau,0x0c081adcu,0x0c081adeu,0x0c081ae0u,0x0c081ae2u,0x0c081ae4u,0x0c081ae6u,0x0c081ae8u,
0x0c081aeau,0x0c081aecu,0x0c081aeeu,0x0c081af0u,0x0c081af2u,0x0c081af4u,0x0c081af6u,0x0c081af8u,0x0c08919eu,0x0c0891a0u,0x0c0891a2u,0x0c0891a4u,0x0c0891a6u,0x0c0891a8u,0x0c0891aau,0x0c0891acu,
0x0c0891aeu,0x0c0891b0u,0x0c0891b2u,0x0c0891b4u,0x0c0891b6u,0x0c0891b8u,0x0c0891bau,0x0c0891bcu,0x0c0891beu,0x0c0891c0u,0x0c0891c2u,0x0c0891c4u,0x0c0891c6u,0x0c0891c8u,0x0c0891cau,0x0c0891ccu,
0x0c0891ceu,0x0c0891d0u,0x0c0891d2u,0x0c0891d4u,0x0c0891d6u,0x0c0891d8u,0x0c0891dau,0x0c0891dcu,0x0c0891deu,0x0c0891e0u,0x0c0891e2u,0x0c0891e4u,0x0c0891e6u,0x0c0891e8u,0x0c0891eau,0x0c0891ecu,
0x0c0891eeu,0x0c0891f0u,0x0c0891f2u,0x0c0891f4u,0x0c0891f6u,0x0c0891f8u,0x0c0891fau,0x0c0891fcu,0x0c0891feu,0x0c089200u,0x0c089202u,0x0c089204u,0x0c089206u,0x0c089208u,0x0c08920au,0x0c08920cu,
0x0c08920eu,0x0c089210u,0x0c089212u,0x0c089214u,0x0c089216u,0x0c089218u,0x0c08921au,0x0c08921cu,0x0c08921eu,0x0c089220u,0x0c089222u,0x0c089224u,0x0c089226u,0x0c089228u,0x0c08922au,0x0c08922cu,
0x0c08922eu,0x0c089230u,0x0c089232u,0x0c089234u,0x0c089236u,0x0c089238u,0x0c08923au,0x0c08923cu,0x0c08923eu,0x0c089240u,0x0c089242u,0x0c089244u,0x0c089246u,0x0c089248u,0x0c08924au,0x0c08924cu,
0x0c08924eu,0x0c089250u,0x0c089252u,0x0c089254u,0x0c089256u,0x0c089258u,0x0c08925au,0x0c08925cu,0x0c08925eu,0x0c089260u,0x0c089262u,0x0c089264u,0x0c089266u,0x0c089268u,0x0c08926au,0x0c08926cu,
0x0c08926eu,0x0c089270u,0x0c089272u,0x0c089274u,0x0c089276u,0x0c089278u,0x0c08927au,0x0c08927cu,
};
int vf3_percentage_aux_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
