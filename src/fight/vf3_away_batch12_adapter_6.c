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
int vf3_away_batch12_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06c636u: goto P_0c06c636;
case 0x0c06c638u: goto P_0c06c638;
case 0x0c06c63au: goto P_0c06c63a;
case 0x0c06c63cu: goto P_0c06c63c;
case 0x0c06c63eu: goto P_0c06c63e;
case 0x0c06c640u: goto P_0c06c640;
case 0x0c06c642u: goto P_0c06c642;
case 0x0c06c644u: goto P_0c06c644;
case 0x0c06c646u: goto P_0c06c646;
case 0x0c06c648u: goto P_0c06c648;
case 0x0c06c64au: goto P_0c06c64a;
case 0x0c06c64cu: goto P_0c06c64c;
case 0x0c06c64eu: goto P_0c06c64e;
case 0x0c06c650u: goto P_0c06c650;
case 0x0c06c652u: goto P_0c06c652;
case 0x0c06c654u: goto P_0c06c654;
case 0x0c06c656u: goto P_0c06c656;
case 0x0c06c658u: goto P_0c06c658;
case 0x0c06c65au: goto P_0c06c65a;
case 0x0c06c65cu: goto P_0c06c65c;
case 0x0c06c65eu: goto P_0c06c65e;
case 0x0c06c660u: goto P_0c06c660;
case 0x0c06c662u: goto P_0c06c662;
case 0x0c06c664u: goto P_0c06c664;
case 0x0c06c666u: goto P_0c06c666;
case 0x0c06c668u: goto P_0c06c668;
case 0x0c06c66au: goto P_0c06c66a;
case 0x0c06c66cu: goto P_0c06c66c;
case 0x0c06c66eu: goto P_0c06c66e;
case 0x0c06c670u: goto P_0c06c670;
case 0x0c06c672u: goto P_0c06c672;
case 0x0c06c674u: goto P_0c06c674;
case 0x0c06c676u: goto P_0c06c676;
case 0x0c06c678u: goto P_0c06c678;
case 0x0c06c67au: goto P_0c06c67a;
case 0x0c06c67cu: goto P_0c06c67c;
case 0x0c06c67eu: goto P_0c06c67e;
case 0x0c06c680u: goto P_0c06c680;
case 0x0c06c682u: goto P_0c06c682;
case 0x0c06c684u: goto P_0c06c684;
case 0x0c06c686u: goto P_0c06c686;
case 0x0c06c688u: goto P_0c06c688;
case 0x0c06c68au: goto P_0c06c68a;
case 0x0c06c68cu: goto P_0c06c68c;
case 0x0c06c68eu: goto P_0c06c68e;
case 0x0c06c690u: goto P_0c06c690;
case 0x0c06c692u: goto P_0c06c692;
case 0x0c06c694u: goto P_0c06c694;
case 0x0c06c696u: goto P_0c06c696;
case 0x0c06c698u: goto P_0c06c698;
case 0x0c06c69au: goto P_0c06c69a;
case 0x0c06c69cu: goto P_0c06c69c;
case 0x0c06c69eu: goto P_0c06c69e;
case 0x0c06c6a0u: goto P_0c06c6a0;
case 0x0c06c6a2u: goto P_0c06c6a2;
case 0x0c06c6a4u: goto P_0c06c6a4;
case 0x0c06c6a6u: goto P_0c06c6a6;
case 0x0c06c6a8u: goto P_0c06c6a8;
case 0x0c06c6aau: goto P_0c06c6aa;
case 0x0c06c6acu: goto P_0c06c6ac;
case 0x0c06c6aeu: goto P_0c06c6ae;
case 0x0c06c6b0u: goto P_0c06c6b0;
case 0x0c06c6b2u: goto P_0c06c6b2;
case 0x0c06c6b4u: goto P_0c06c6b4;
case 0x0c06c6b6u: goto P_0c06c6b6;
case 0x0c06c6b8u: goto P_0c06c6b8;
case 0x0c06c6bau: goto P_0c06c6ba;
case 0x0c06c6bcu: goto P_0c06c6bc;
case 0x0c06c6beu: goto P_0c06c6be;
case 0x0c06c6c0u: goto P_0c06c6c0;
case 0x0c06c6c2u: goto P_0c06c6c2;
case 0x0c06c6c4u: goto P_0c06c6c4;
case 0x0c06c6c6u: goto P_0c06c6c6;
case 0x0c06c6c8u: goto P_0c06c6c8;
case 0x0c06c6cau: goto P_0c06c6ca;
case 0x0c06c6ccu: goto P_0c06c6cc;
case 0x0c06c6ceu: goto P_0c06c6ce;
case 0x0c06c6d0u: goto P_0c06c6d0;
case 0x0c06c6d2u: goto P_0c06c6d2;
case 0x0c06c6d4u: goto P_0c06c6d4;
case 0x0c06c6d6u: goto P_0c06c6d6;
case 0x0c06c6d8u: goto P_0c06c6d8;
case 0x0c06c6dau: goto P_0c06c6da;
case 0x0c06c6dcu: goto P_0c06c6dc;
case 0x0c06c6deu: goto P_0c06c6de;
case 0x0c06c720u: goto P_0c06c720;
case 0x0c06c722u: goto P_0c06c722;
case 0x0c06c724u: goto P_0c06c724;
case 0x0c06c726u: goto P_0c06c726;
case 0x0c06c728u: goto P_0c06c728;
case 0x0c06c72au: goto P_0c06c72a;
case 0x0c06c72cu: goto P_0c06c72c;
case 0x0c06c72eu: goto P_0c06c72e;
case 0x0c06c730u: goto P_0c06c730;
case 0x0c06c732u: goto P_0c06c732;
case 0x0c06c734u: goto P_0c06c734;
case 0x0c06c736u: goto P_0c06c736;
case 0x0c06c738u: goto P_0c06c738;
case 0x0c06c73au: goto P_0c06c73a;
case 0x0c06c73cu: goto P_0c06c73c;
case 0x0c06c73eu: goto P_0c06c73e;
case 0x0c06c740u: goto P_0c06c740;
case 0x0c06c742u: goto P_0c06c742;
case 0x0c06c744u: goto P_0c06c744;
case 0x0c06c746u: goto P_0c06c746;
case 0x0c06c748u: goto P_0c06c748;
case 0x0c06c74au: goto P_0c06c74a;
case 0x0c06c74cu: goto P_0c06c74c;
case 0x0c06c74eu: goto P_0c06c74e;
case 0x0c06c750u: goto P_0c06c750;
case 0x0c06c752u: goto P_0c06c752;
case 0x0c06c754u: goto P_0c06c754;
case 0x0c06c756u: goto P_0c06c756;
case 0x0c06c758u: goto P_0c06c758;
case 0x0c06c75au: goto P_0c06c75a;
case 0x0c06c75cu: goto P_0c06c75c;
case 0x0c06c75eu: goto P_0c06c75e;
case 0x0c06c760u: goto P_0c06c760;
case 0x0c06c762u: goto P_0c06c762;
case 0x0c06c764u: goto P_0c06c764;
case 0x0c06c766u: goto P_0c06c766;
case 0x0c06c768u: goto P_0c06c768;
case 0x0c06c76au: goto P_0c06c76a;
case 0x0c06c76cu: goto P_0c06c76c;
case 0x0c06c76eu: goto P_0c06c76e;
case 0x0c06c770u: goto P_0c06c770;
case 0x0c06c772u: goto P_0c06c772;
case 0x0c06c774u: goto P_0c06c774;
case 0x0c06c776u: goto P_0c06c776;
case 0x0c06c778u: goto P_0c06c778;
case 0x0c06c77au: goto P_0c06c77a;
case 0x0c06c77cu: goto P_0c06c77c;
case 0x0c06c77eu: goto P_0c06c77e;
case 0x0c06c780u: goto P_0c06c780;
case 0x0c06c782u: goto P_0c06c782;
case 0x0c06c784u: goto P_0c06c784;
case 0x0c06c786u: goto P_0c06c786;
case 0x0c06c788u: goto P_0c06c788;
case 0x0c06c78au: goto P_0c06c78a;
case 0x0c06c78cu: goto P_0c06c78c;
case 0x0c06c78eu: goto P_0c06c78e;
case 0x0c06c790u: goto P_0c06c790;
case 0x0c06c792u: goto P_0c06c792;
case 0x0c06c794u: goto P_0c06c794;
case 0x0c06c796u: goto P_0c06c796;
case 0x0c06c798u: goto P_0c06c798;
case 0x0c06c79au: goto P_0c06c79a;
case 0x0c06c79cu: goto P_0c06c79c;
case 0x0c06c79eu: goto P_0c06c79e;
case 0x0c06c7a0u: goto P_0c06c7a0;
case 0x0c06c7a2u: goto P_0c06c7a2;
case 0x0c06c7a4u: goto P_0c06c7a4;
case 0x0c06c7a6u: goto P_0c06c7a6;
case 0x0c06c7a8u: goto P_0c06c7a8;
case 0x0c06c7aau: goto P_0c06c7aa;
case 0x0c06c7acu: goto P_0c06c7ac;
case 0x0c06c7aeu: goto P_0c06c7ae;
case 0x0c06c7b0u: goto P_0c06c7b0;
case 0x0c06c7b2u: goto P_0c06c7b2;
case 0x0c06c7b4u: goto P_0c06c7b4;
case 0x0c06c7b6u: goto P_0c06c7b6;
case 0x0c06c7b8u: goto P_0c06c7b8;
case 0x0c06c7bau: goto P_0c06c7ba;
case 0x0c06c7bcu: goto P_0c06c7bc;
case 0x0c06c7beu: goto P_0c06c7be;
case 0x0c06c7c0u: goto P_0c06c7c0;
case 0x0c06c7c2u: goto P_0c06c7c2;
case 0x0c06c7c4u: goto P_0c06c7c4;
case 0x0c06c7c6u: goto P_0c06c7c6;
case 0x0c06c7c8u: goto P_0c06c7c8;
case 0x0c06c7cau: goto P_0c06c7ca;
case 0x0c07b35cu: goto P_0c07b35c;
case 0x0c07b35eu: goto P_0c07b35e;
case 0x0c07b360u: goto P_0c07b360;
case 0x0c07b362u: goto P_0c07b362;
case 0x0c07b364u: goto P_0c07b364;
case 0x0c07b366u: goto P_0c07b366;
case 0x0c07b368u: goto P_0c07b368;
case 0x0c07b36au: goto P_0c07b36a;
case 0x0c07b36cu: goto P_0c07b36c;
case 0x0c07b36eu: goto P_0c07b36e;
case 0x0c07b370u: goto P_0c07b370;
case 0x0c07b372u: goto P_0c07b372;
case 0x0c07b374u: goto P_0c07b374;
case 0x0c07b376u: goto P_0c07b376;
case 0x0c07b378u: goto P_0c07b378;
case 0x0c07b37au: goto P_0c07b37a;
case 0x0c07b37cu: goto P_0c07b37c;
case 0x0c07b37eu: goto P_0c07b37e;
case 0x0c07b380u: goto P_0c07b380;
case 0x0c07b382u: goto P_0c07b382;
case 0x0c07b384u: goto P_0c07b384;
case 0x0c07b386u: goto P_0c07b386;
case 0x0c07b388u: goto P_0c07b388;
case 0x0c07b38au: goto P_0c07b38a;
case 0x0c07b38cu: goto P_0c07b38c;
case 0x0c07b38eu: goto P_0c07b38e;
case 0x0c07b390u: goto P_0c07b390;
case 0x0c07b392u: goto P_0c07b392;
case 0x0c07b394u: goto P_0c07b394;
case 0x0c07b396u: goto P_0c07b396;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06c636: /* original 2fe6, guest PC 0x0c06c636 */
if(!s->budget--) { s->failed_pc=0x0c06c636u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c638;
P_0c06c638: /* original 4400, guest PC 0x0c06c638 */
if(!s->budget--) { s->failed_pc=0x0c06c638u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c63a;
P_0c06c63a: /* original 4f22, guest PC 0x0c06c63a */
if(!s->budget--) { s->failed_pc=0x0c06c63au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c63c;
P_0c06c63c: /* original e101, guest PC 0x0c06c63c */
if(!s->budget--) { s->failed_pc=0x0c06c63cu; return 0; }
r[1]=0x00000001u;
goto P_0c06c63e;
P_0c06c63e: /* original 6e53, guest PC 0x0c06c63e */
if(!s->budget--) { s->failed_pc=0x0c06c63eu; return 0; }
r[14]=r[5];
goto P_0c06c640;
P_0c06c640: /* original 7ff8, guest PC 0x0c06c640 */
if(!s->budget--) { s->failed_pc=0x0c06c640u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c06c642;
P_0c06c642: /* original 2f62, guest PC 0x0c06c642 */
if(!s->budget--) { s->failed_pc=0x0c06c642u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c06c644;
P_0c06c644: /* original 6643, guest PC 0x0c06c644 */
if(!s->budget--) { s->failed_pc=0x0c06c644u; return 0; }
r[6]=r[4];
goto P_0c06c646;
P_0c06c646: /* original d326, guest PC 0x0c06c646 */
if(!s->budget--) { s->failed_pc=0x0c06c646u; return 0; }
r[3]=read(ram,0x0c06c6e0u,4);
goto P_0c06c648;
P_0c06c648: /* original 1f31, guest PC 0x0c06c648 */
if(!s->budget--) { s->failed_pc=0x0c06c648u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c06c64a;
P_0c06c64a: /* original e307, guest PC 0x0c06c64a */
if(!s->budget--) { s->failed_pc=0x0c06c64au; return 0; }
r[3]=0x00000007u;
goto P_0c06c64c;
P_0c06c64c: /* original d228, guest PC 0x0c06c64c */
if(!s->budget--) { s->failed_pc=0x0c06c64cu; return 0; }
r[2]=read(ram,0x0c06c6f0u,4);
goto P_0c06c64e;
P_0c06c64e: /* original 4e3d, guest PC 0x0c06c64e */
if(!s->budget--) { s->failed_pc=0x0c06c64eu; return 0; }
r[14]=(r[3]&0x80000000u)?((r[3]&31u)?r[14]>>((-r[3])&31u):0):r[14]<<(r[3]&31u);
goto P_0c06c650;
P_0c06c650: /* original 6422, guest PC 0x0c06c650 */
if(!s->budget--) { s->failed_pc=0x0c06c650u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c06c652;
P_0c06c652: /* original 3416, guest PC 0x0c06c652 */
if(!s->budget--) { s->failed_pc=0x0c06c652u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[1])!=0);
goto P_0c06c654;
P_0c06c654: /* original 8d03, guest PC 0x0c06c654 */
if(!s->budget--) { s->failed_pc=0x0c06c654u; return 0; }
cond=r[17]&1u;
r[6]|=r[14];
if(cond) { goto P_0c06c65e; }
goto P_0c06c658;
P_0c06c656: /* original 26eb, guest PC 0x0c06c656 */
if(!s->budget--) { s->failed_pc=0x0c06c656u; return 0; }
r[6]|=r[14];
goto P_0c06c658;
P_0c06c658: /* original d526, guest PC 0x0c06c658 */
if(!s->budget--) { s->failed_pc=0x0c06c658u; return 0; }
r[5]=read(ram,0x0c06c6f4u,4);
goto P_0c06c65a;
P_0c06c65a: /* original a001, guest PC 0x0c06c65a */
if(!s->budget--) { s->failed_pc=0x0c06c65au; return 0; }
goto P_0c06c660;
P_0c06c65c: /* original 0009, guest PC 0x0c06c65c */
if(!s->budget--) { s->failed_pc=0x0c06c65cu; return 0; }
goto P_0c06c65e;
P_0c06c65e: /* original d526, guest PC 0x0c06c65e */
if(!s->budget--) { s->failed_pc=0x0c06c65eu; return 0; }
r[5]=read(ram,0x0c06c6f8u,4);
goto P_0c06c660;
P_0c06c660: /* original b023, guest PC 0x0c06c660 */
if(!s->budget--) { s->failed_pc=0x0c06c660u; return 0; }
target=code_base|0x0c06c6aau; r[16]=code_base|0x0c06c664u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c664u) { target=s->pc; goto dispatch; }
goto P_0c06c664;
P_0c06c662: /* original 0009, guest PC 0x0c06c662 */
if(!s->budget--) { s->failed_pc=0x0c06c662u; return 0; }
goto P_0c06c664;
P_0c06c664: /* original d225, guest PC 0x0c06c664 */
if(!s->budget--) { s->failed_pc=0x0c06c664u; return 0; }
r[2]=read(ram,0x0c06c6fcu,4);
goto P_0c06c666;
P_0c06c666: /* original d326, guest PC 0x0c06c666 */
if(!s->budget--) { s->failed_pc=0x0c06c666u; return 0; }
r[3]=read(ram,0x0c06c700u,4);
goto P_0c06c668;
P_0c06c668: /* original 6422, guest PC 0x0c06c668 */
if(!s->budget--) { s->failed_pc=0x0c06c668u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c06c66a;
P_0c06c66a: /* original 2438, guest PC 0x0c06c66a */
if(!s->budget--) { s->failed_pc=0x0c06c66au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c06c66c;
P_0c06c66c: /* original 8b0e, guest PC 0x0c06c66c */
if(!s->budget--) { s->failed_pc=0x0c06c66cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c68c; }
goto P_0c06c66e;
P_0c06c66e: /* original d125, guest PC 0x0c06c66e */
if(!s->budget--) { s->failed_pc=0x0c06c66eu; return 0; }
r[1]=read(ram,0x0c06c704u,4);
goto P_0c06c670;
P_0c06c670: /* original 6010, guest PC 0x0c06c670 */
if(!s->budget--) { s->failed_pc=0x0c06c670u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[0]=tmp;
goto P_0c06c672;
P_0c06c672: /* original 600c, guest PC 0x0c06c672 */
if(!s->budget--) { s->failed_pc=0x0c06c672u; return 0; }
r[0]=r[0]&255u;
goto P_0c06c674;
P_0c06c674: /* original 8803, guest PC 0x0c06c674 */
if(!s->budget--) { s->failed_pc=0x0c06c674u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c06c676;
P_0c06c676: /* original 8b14, guest PC 0x0c06c676 */
if(!s->budget--) { s->failed_pc=0x0c06c676u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c6a2; }
goto P_0c06c678;
P_0c06c678: /* original 64f2, guest PC 0x0c06c678 */
if(!s->budget--) { s->failed_pc=0x0c06c678u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06c67a;
P_0c06c67a: /* original d523, guest PC 0x0c06c67a */
if(!s->budget--) { s->failed_pc=0x0c06c67au; return 0; }
r[5]=read(ram,0x0c06c708u,4);
goto P_0c06c67c;
P_0c06c67c: /* original 7403, guest PC 0x0c06c67c */
if(!s->budget--) { s->failed_pc=0x0c06c67cu; return 0; }
r[4]+=0x00000003u;
goto P_0c06c67e;
P_0c06c67e: /* original d223, guest PC 0x0c06c67e */
if(!s->budget--) { s->failed_pc=0x0c06c67eu; return 0; }
r[2]=read(ram,0x0c06c70cu,4);
goto P_0c06c680;
P_0c06c680: /* original 4400, guest PC 0x0c06c680 */
if(!s->budget--) { s->failed_pc=0x0c06c680u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c682;
P_0c06c682: /* original 24eb, guest PC 0x0c06c682 */
if(!s->budget--) { s->failed_pc=0x0c06c682u; return 0; }
r[4]|=r[14];
goto P_0c06c684;
P_0c06c684: /* original 420b, guest PC 0x0c06c684 */
if(!s->budget--) { s->failed_pc=0x0c06c684u; return 0; }
target=r[2];
r[16]=code_base|0x0c06c688u;
r[6]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c688u) { target=s->pc; goto dispatch; }
goto P_0c06c688;
P_0c06c686: /* original e601, guest PC 0x0c06c686 */
if(!s->budget--) { s->failed_pc=0x0c06c686u; return 0; }
r[6]=0x00000001u;
goto P_0c06c688;
P_0c06c688: /* original a00b, guest PC 0x0c06c688 */
if(!s->budget--) { s->failed_pc=0x0c06c688u; return 0; }
goto P_0c06c6a2;
P_0c06c68a: /* original 0009, guest PC 0x0c06c68a */
if(!s->budget--) { s->failed_pc=0x0c06c68au; return 0; }
goto P_0c06c68c;
P_0c06c68c: /* original 65f2, guest PC 0x0c06c68c */
if(!s->budget--) { s->failed_pc=0x0c06c68cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06c68e;
P_0c06c68e: /* original e120, guest PC 0x0c06c68e */
if(!s->budget--) { s->failed_pc=0x0c06c68eu; return 0; }
r[1]=0x00000020u;
goto P_0c06c690;
P_0c06c690: /* original e615, guest PC 0x0c06c690 */
if(!s->budget--) { s->failed_pc=0x0c06c690u; return 0; }
r[6]=0x00000015u;
goto P_0c06c692;
P_0c06c692: /* original 2f16, guest PC 0x0c06c692 */
if(!s->budget--) { s->failed_pc=0x0c06c692u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c694;
P_0c06c694: /* original d215, guest PC 0x0c06c694 */
if(!s->budget--) { s->failed_pc=0x0c06c694u; return 0; }
r[2]=read(ram,0x0c06c6ecu,4);
goto P_0c06c696;
P_0c06c696: /* original 4500, guest PC 0x0c06c696 */
if(!s->budget--) { s->failed_pc=0x0c06c696u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c06c698;
P_0c06c698: /* original e701, guest PC 0x0c06c698 */
if(!s->budget--) { s->failed_pc=0x0c06c698u; return 0; }
r[7]=0x00000001u;
goto P_0c06c69a;
P_0c06c69a: /* original 25eb, guest PC 0x0c06c69a */
if(!s->budget--) { s->failed_pc=0x0c06c69au; return 0; }
r[5]|=r[14];
goto P_0c06c69c;
P_0c06c69c: /* original 420b, guest PC 0x0c06c69c */
if(!s->budget--) { s->failed_pc=0x0c06c69cu; return 0; }
target=r[2];
r[16]=code_base|0x0c06c6a0u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c6a0u) { target=s->pc; goto dispatch; }
goto P_0c06c6a0;
P_0c06c69e: /* original 54f2, guest PC 0x0c06c69e */
if(!s->budget--) { s->failed_pc=0x0c06c69eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c06c6a0;
P_0c06c6a0: /* original 7f04, guest PC 0x0c06c6a0 */
if(!s->budget--) { s->failed_pc=0x0c06c6a0u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c6a2;
P_0c06c6a2: /* original 7f08, guest PC 0x0c06c6a2 */
if(!s->budget--) { s->failed_pc=0x0c06c6a2u; return 0; }
r[15]+=0x00000008u;
goto P_0c06c6a4;
P_0c06c6a4: /* original 4f26, guest PC 0x0c06c6a4 */
if(!s->budget--) { s->failed_pc=0x0c06c6a4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c6a6;
P_0c06c6a6: /* original 000b, guest PC 0x0c06c6a6 */
if(!s->budget--) { s->failed_pc=0x0c06c6a6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06c6a8: /* original 6ef6, guest PC 0x0c06c6a8 */
if(!s->budget--) { s->failed_pc=0x0c06c6a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c6aa;
P_0c06c6aa: /* original 4f22, guest PC 0x0c06c6aa */
if(!s->budget--) { s->failed_pc=0x0c06c6aau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c6ac;
P_0c06c6ac: /* original 7ff4, guest PC 0x0c06c6ac */
if(!s->budget--) { s->failed_pc=0x0c06c6acu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c06c6ae;
P_0c06c6ae: /* original 1f41, guest PC 0x0c06c6ae */
if(!s->budget--) { s->failed_pc=0x0c06c6aeu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c06c6b0;
P_0c06c6b0: /* original 1f52, guest PC 0x0c06c6b0 */
if(!s->budget--) { s->failed_pc=0x0c06c6b0u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c06c6b2;
P_0c06c6b2: /* original 2f62, guest PC 0x0c06c6b2 */
if(!s->budget--) { s->failed_pc=0x0c06c6b2u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c06c6b4;
P_0c06c6b4: /* original 53f2, guest PC 0x0c06c6b4 */
if(!s->budget--) { s->failed_pc=0x0c06c6b4u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c06c6b6;
P_0c06c6b6: /* original 2f36, guest PC 0x0c06c6b6 */
if(!s->budget--) { s->failed_pc=0x0c06c6b6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c6b8;
P_0c06c6b8: /* original d215, guest PC 0x0c06c6b8 */
if(!s->budget--) { s->failed_pc=0x0c06c6b8u; return 0; }
r[2]=read(ram,0x0c06c710u,4);
goto P_0c06c6ba;
P_0c06c6ba: /* original 2f26, guest PC 0x0c06c6ba */
if(!s->budget--) { s->failed_pc=0x0c06c6bau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c6bc;
P_0c06c6bc: /* original 53f3, guest PC 0x0c06c6bc */
if(!s->budget--) { s->failed_pc=0x0c06c6bcu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c06c6be;
P_0c06c6be: /* original 2f36, guest PC 0x0c06c6be */
if(!s->budget--) { s->failed_pc=0x0c06c6beu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c6c0;
P_0c06c6c0: /* original d114, guest PC 0x0c06c6c0 */
if(!s->budget--) { s->failed_pc=0x0c06c6c0u; return 0; }
r[1]=read(ram,0x0c06c714u,4);
goto P_0c06c6c2;
P_0c06c6c2: /* original 2f16, guest PC 0x0c06c6c2 */
if(!s->budget--) { s->failed_pc=0x0c06c6c2u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c6c4;
P_0c06c6c4: /* original d314, guest PC 0x0c06c6c4 */
if(!s->budget--) { s->failed_pc=0x0c06c6c4u; return 0; }
r[3]=read(ram,0x0c06c718u,4);
goto P_0c06c6c6;
P_0c06c6c6: /* original 2f36, guest PC 0x0c06c6c6 */
if(!s->budget--) { s->failed_pc=0x0c06c6c6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c6c8;
P_0c06c6c8: /* original d214, guest PC 0x0c06c6c8 */
if(!s->budget--) { s->failed_pc=0x0c06c6c8u; return 0; }
r[2]=read(ram,0x0c06c71cu,4);
goto P_0c06c6ca;
P_0c06c6ca: /* original 420b, guest PC 0x0c06c6ca */
if(!s->budget--) { s->failed_pc=0x0c06c6cau; return 0; }
target=r[2];
r[16]=code_base|0x0c06c6ceu;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c6ceu) { target=s->pc; goto dispatch; }
goto P_0c06c6ce;
P_0c06c6cc: /* original 54f5, guest PC 0x0c06c6cc */
if(!s->budget--) { s->failed_pc=0x0c06c6ccu; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c06c6ce;
P_0c06c6ce: /* original 7f20, guest PC 0x0c06c6ce */
if(!s->budget--) { s->failed_pc=0x0c06c6ceu; return 0; }
r[15]+=0x00000020u;
goto P_0c06c6d0;
P_0c06c6d0: /* original 4f26, guest PC 0x0c06c6d0 */
if(!s->budget--) { s->failed_pc=0x0c06c6d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c6d2;
P_0c06c6d2: /* original 000b, guest PC 0x0c06c6d2 */
if(!s->budget--) { s->failed_pc=0x0c06c6d2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06c6d4: /* original 0009, guest PC 0x0c06c6d4 */
if(!s->budget--) { s->failed_pc=0x0c06c6d4u; return 0; }
goto P_0c06c6d6;
P_0c06c6d6: /* original 4f22, guest PC 0x0c06c6d6 */
if(!s->budget--) { s->failed_pc=0x0c06c6d6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c6d8;
P_0c06c6d8: /* original bf76, guest PC 0x0c06c6d8 */
if(!s->budget--) { s->failed_pc=0x0c06c6d8u; return 0; }
target=code_base|0x0c06c5c8u; r[16]=code_base|0x0c06c6dcu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c6dcu) { target=s->pc; goto dispatch; }
goto P_0c06c6dc;
P_0c06c6da: /* original 0009, guest PC 0x0c06c6da */
if(!s->budget--) { s->failed_pc=0x0c06c6dau; return 0; }
goto P_0c06c6dc;
P_0c06c6dc: /* original a020, guest PC 0x0c06c6dc */
if(!s->budget--) { s->failed_pc=0x0c06c6dcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c720;
P_0c06c6de: /* original 4f26, guest PC 0x0c06c6de */
if(!s->budget--) { s->failed_pc=0x0c06c6deu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c06c6e0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06c6e0u; return 0; } return 1;
P_0c06c720: /* original 2fe6, guest PC 0x0c06c720 */
if(!s->budget--) { s->failed_pc=0x0c06c720u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c722;
P_0c06c722: /* original 9053, guest PC 0x0c06c722 */
if(!s->budget--) { s->failed_pc=0x0c06c722u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7ccu,2);
goto P_0c06c724;
P_0c06c724: /* original 7ffc, guest PC 0x0c06c724 */
if(!s->budget--) { s->failed_pc=0x0c06c724u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c726;
P_0c06c726: /* original de2c, guest PC 0x0c06c726 */
if(!s->budget--) { s->failed_pc=0x0c06c726u; return 0; }
r[14]=read(ram,0x0c06c7d8u,4);
goto P_0c06c728;
P_0c06c728: /* original 00ec, guest PC 0x0c06c728 */
if(!s->budget--) { s->failed_pc=0x0c06c728u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c72a;
P_0c06c72a: /* original 8801, guest PC 0x0c06c72a */
if(!s->budget--) { s->failed_pc=0x0c06c72au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c72c;
P_0c06c72c: /* original 8d12, guest PC 0x0c06c72c */
if(!s->budget--) { s->failed_pc=0x0c06c72cu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c06c754; }
goto P_0c06c730;
P_0c06c72e: /* original 6403, guest PC 0x0c06c72e */
if(!s->budget--) { s->failed_pc=0x0c06c72eu; return 0; }
r[4]=r[0];
goto P_0c06c730;
P_0c06c730: /* original 904d, guest PC 0x0c06c730 */
if(!s->budget--) { s->failed_pc=0x0c06c730u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7ceu,2);
goto P_0c06c732;
P_0c06c732: /* original 04ec, guest PC 0x0c06c732 */
if(!s->budget--) { s->failed_pc=0x0c06c732u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c734;
P_0c06c734: /* original 70ff, guest PC 0x0c06c734 */
if(!s->budget--) { s->failed_pc=0x0c06c734u; return 0; }
r[0]+=0xffffffffu;
goto P_0c06c736;
P_0c06c736: /* original 03ec, guest PC 0x0c06c736 */
if(!s->budget--) { s->failed_pc=0x0c06c736u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c738;
P_0c06c738: /* original 2338, guest PC 0x0c06c738 */
if(!s->budget--) { s->failed_pc=0x0c06c738u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06c73a;
P_0c06c73a: /* original 8f02, guest PC 0x0c06c73a */
if(!s->budget--) { s->failed_pc=0x0c06c73au; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c06c742; }
goto P_0c06c73e;
P_0c06c73c: /* original 2f32, guest PC 0x0c06c73c */
if(!s->budget--) { s->failed_pc=0x0c06c73cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c73e;
P_0c06c73e: /* original 2448, guest PC 0x0c06c73e */
if(!s->budget--) { s->failed_pc=0x0c06c73eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06c740;
P_0c06c740: /* original 890c, guest PC 0x0c06c740 */
if(!s->budget--) { s->failed_pc=0x0c06c740u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c75c; }
goto P_0c06c742;
P_0c06c742: /* original 9045, guest PC 0x0c06c742 */
if(!s->budget--) { s->failed_pc=0x0c06c742u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d0u,2);
goto P_0c06c744;
P_0c06c744: /* original 63f2, guest PC 0x0c06c744 */
if(!s->budget--) { s->failed_pc=0x0c06c744u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06c746;
P_0c06c746: /* original 04ec, guest PC 0x0c06c746 */
if(!s->budget--) { s->failed_pc=0x0c06c746u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c748;
P_0c06c748: /* original 3342, guest PC 0x0c06c748 */
if(!s->budget--) { s->failed_pc=0x0c06c748u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[4])!=0);
goto P_0c06c74a;
P_0c06c74a: /* original 8903, guest PC 0x0c06c74a */
if(!s->budget--) { s->failed_pc=0x0c06c74au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c754; }
goto P_0c06c74c;
P_0c06c74c: /* original 9041, guest PC 0x0c06c74c */
if(!s->budget--) { s->failed_pc=0x0c06c74cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d2u,2);
goto P_0c06c74e;
P_0c06c74e: /* original e102, guest PC 0x0c06c74e */
if(!s->budget--) { s->failed_pc=0x0c06c74eu; return 0; }
r[1]=0x00000002u;
goto P_0c06c750;
P_0c06c750: /* original a007, guest PC 0x0c06c750 */
if(!s->budget--) { s->failed_pc=0x0c06c750u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c06c762;
P_0c06c752: /* original 0e14, guest PC 0x0c06c752 */
if(!s->budget--) { s->failed_pc=0x0c06c752u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c06c754;
P_0c06c754: /* original 903d, guest PC 0x0c06c754 */
if(!s->budget--) { s->failed_pc=0x0c06c754u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d2u,2);
goto P_0c06c756;
P_0c06c756: /* original e303, guest PC 0x0c06c756 */
if(!s->budget--) { s->failed_pc=0x0c06c756u; return 0; }
r[3]=0x00000003u;
goto P_0c06c758;
P_0c06c758: /* original a003, guest PC 0x0c06c758 */
if(!s->budget--) { s->failed_pc=0x0c06c758u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06c762;
P_0c06c75a: /* original 0e34, guest PC 0x0c06c75a */
if(!s->budget--) { s->failed_pc=0x0c06c75au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06c75c;
P_0c06c75c: /* original 9039, guest PC 0x0c06c75c */
if(!s->budget--) { s->failed_pc=0x0c06c75cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d2u,2);
goto P_0c06c75e;
P_0c06c75e: /* original e101, guest PC 0x0c06c75e */
if(!s->budget--) { s->failed_pc=0x0c06c75eu; return 0; }
r[1]=0x00000001u;
goto P_0c06c760;
P_0c06c760: /* original 0e14, guest PC 0x0c06c760 */
if(!s->budget--) { s->failed_pc=0x0c06c760u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c06c762;
P_0c06c762: /* original 9036, guest PC 0x0c06c762 */
if(!s->budget--) { s->failed_pc=0x0c06c762u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d2u,2);
goto P_0c06c764;
P_0c06c764: /* original 00ec, guest PC 0x0c06c764 */
if(!s->budget--) { s->failed_pc=0x0c06c764u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c766;
P_0c06c766: /* original 8803, guest PC 0x0c06c766 */
if(!s->budget--) { s->failed_pc=0x0c06c766u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c06c768;
P_0c06c768: /* original 8f03, guest PC 0x0c06c768 */
if(!s->budget--) { s->failed_pc=0x0c06c768u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c06c772; }
goto P_0c06c76c;
P_0c06c76a: /* original 6403, guest PC 0x0c06c76a */
if(!s->budget--) { s->failed_pc=0x0c06c76au; return 0; }
r[4]=r[0];
goto P_0c06c76c;
P_0c06c76c: /* original 7f04, guest PC 0x0c06c76c */
if(!s->budget--) { s->failed_pc=0x0c06c76cu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c76e;
P_0c06c76e: /* original a018, guest PC 0x0c06c76e */
if(!s->budget--) { s->failed_pc=0x0c06c76eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c7a2;
P_0c06c770: /* original 6ef6, guest PC 0x0c06c770 */
if(!s->budget--) { s->failed_pc=0x0c06c770u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c772;
P_0c06c772: /* original d31a, guest PC 0x0c06c772 */
if(!s->budget--) { s->failed_pc=0x0c06c772u; return 0; }
r[3]=read(ram,0x0c06c7dcu,4);
goto P_0c06c774;
P_0c06c774: /* original e23f, guest PC 0x0c06c774 */
if(!s->budget--) { s->failed_pc=0x0c06c774u; return 0; }
r[2]=0x0000003fu;
goto P_0c06c776;
P_0c06c776: /* original 902d, guest PC 0x0c06c776 */
if(!s->budget--) { s->failed_pc=0x0c06c776u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d4u,2);
goto P_0c06c778;
P_0c06c778: /* original 6532, guest PC 0x0c06c778 */
if(!s->budget--) { s->failed_pc=0x0c06c778u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06c77a;
P_0c06c77a: /* original e303, guest PC 0x0c06c77a */
if(!s->budget--) { s->failed_pc=0x0c06c77au; return 0; }
r[3]=0x00000003u;
goto P_0c06c77c;
P_0c06c77c: /* original 04ec, guest PC 0x0c06c77c */
if(!s->budget--) { s->failed_pc=0x0c06c77cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c77e;
P_0c06c77e: /* original 2529, guest PC 0x0c06c77e */
if(!s->budget--) { s->failed_pc=0x0c06c77eu; return 0; }
r[5]&=r[2];
goto P_0c06c780;
P_0c06c780: /* original 2558, guest PC 0x0c06c780 */
if(!s->budget--) { s->failed_pc=0x0c06c780u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06c782;
P_0c06c782: /* original 8f01, guest PC 0x0c06c782 */
if(!s->budget--) { s->failed_pc=0x0c06c782u; return 0; }
cond=r[17]&1u;
r[4]&=r[3];
if(!cond) { goto P_0c06c788; }
goto P_0c06c786;
P_0c06c784: /* original 2439, guest PC 0x0c06c784 */
if(!s->budget--) { s->failed_pc=0x0c06c784u; return 0; }
r[4]&=r[3];
goto P_0c06c786;
P_0c06c786: /* original 7401, guest PC 0x0c06c786 */
if(!s->budget--) { s->failed_pc=0x0c06c786u; return 0; }
r[4]+=0x00000001u;
goto P_0c06c788;
P_0c06c788: /* original e302, guest PC 0x0c06c788 */
if(!s->budget--) { s->failed_pc=0x0c06c788u; return 0; }
r[3]=0x00000002u;
goto P_0c06c78a;
P_0c06c78a: /* original 3436, guest PC 0x0c06c78a */
if(!s->budget--) { s->failed_pc=0x0c06c78au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[3])!=0);
goto P_0c06c78c;
P_0c06c78c: /* original 8b00, guest PC 0x0c06c78c */
if(!s->budget--) { s->failed_pc=0x0c06c78cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c790; }
goto P_0c06c78e;
P_0c06c78e: /* original e400, guest PC 0x0c06c78e */
if(!s->budget--) { s->failed_pc=0x0c06c78eu; return 0; }
r[4]=0x00000000u;
goto P_0c06c790;
P_0c06c790: /* original 0e44, guest PC 0x0c06c790 */
if(!s->budget--) { s->failed_pc=0x0c06c790u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06c792;
P_0c06c792: /* original 4408, guest PC 0x0c06c792 */
if(!s->budget--) { s->failed_pc=0x0c06c792u; return 0; }
r[4]<<=2;
goto P_0c06c794;
P_0c06c794: /* original d012, guest PC 0x0c06c794 */
if(!s->budget--) { s->failed_pc=0x0c06c794u; return 0; }
r[0]=read(ram,0x0c06c7e0u,4);
goto P_0c06c796;
P_0c06c796: /* original 034e, guest PC 0x0c06c796 */
if(!s->budget--) { s->failed_pc=0x0c06c796u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c06c798;
P_0c06c798: /* original 2f32, guest PC 0x0c06c798 */
if(!s->budget--) { s->failed_pc=0x0c06c798u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c79a;
P_0c06c79a: /* original 7f04, guest PC 0x0c06c79a */
if(!s->budget--) { s->failed_pc=0x0c06c79au; return 0; }
r[15]+=0x00000004u;
goto P_0c06c79c;
P_0c06c79c: /* original 6233, guest PC 0x0c06c79c */
if(!s->budget--) { s->failed_pc=0x0c06c79cu; return 0; }
r[2]=r[3];
goto P_0c06c79e;
P_0c06c79e: /* original 422b, guest PC 0x0c06c79e */
if(!s->budget--) { s->failed_pc=0x0c06c79eu; return 0; }
target=r[2];
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
P_0c06c7a0: /* original 6ef6, guest PC 0x0c06c7a0 */
if(!s->budget--) { s->failed_pc=0x0c06c7a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c7a2;
P_0c06c7a2: /* original d30e, guest PC 0x0c06c7a2 */
if(!s->budget--) { s->failed_pc=0x0c06c7a2u; return 0; }
r[3]=read(ram,0x0c06c7dcu,4);
goto P_0c06c7a4;
P_0c06c7a4: /* original e23f, guest PC 0x0c06c7a4 */
if(!s->budget--) { s->failed_pc=0x0c06c7a4u; return 0; }
r[2]=0x0000003fu;
goto P_0c06c7a6;
P_0c06c7a6: /* original 9015, guest PC 0x0c06c7a6 */
if(!s->budget--) { s->failed_pc=0x0c06c7a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d4u,2);
goto P_0c06c7a8;
P_0c06c7a8: /* original e601, guest PC 0x0c06c7a8 */
if(!s->budget--) { s->failed_pc=0x0c06c7a8u; return 0; }
r[6]=0x00000001u;
goto P_0c06c7aa;
P_0c06c7aa: /* original d70b, guest PC 0x0c06c7aa */
if(!s->budget--) { s->failed_pc=0x0c06c7aau; return 0; }
r[7]=read(ram,0x0c06c7d8u,4);
goto P_0c06c7ac;
P_0c06c7ac: /* original 7ffc, guest PC 0x0c06c7ac */
if(!s->budget--) { s->failed_pc=0x0c06c7acu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c7ae;
P_0c06c7ae: /* original 6532, guest PC 0x0c06c7ae */
if(!s->budget--) { s->failed_pc=0x0c06c7aeu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06c7b0;
P_0c06c7b0: /* original 047c, guest PC 0x0c06c7b0 */
if(!s->budget--) { s->failed_pc=0x0c06c7b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c06c7b2;
P_0c06c7b2: /* original 2529, guest PC 0x0c06c7b2 */
if(!s->budget--) { s->failed_pc=0x0c06c7b2u; return 0; }
r[5]&=r[2];
goto P_0c06c7b4;
P_0c06c7b4: /* original 2558, guest PC 0x0c06c7b4 */
if(!s->budget--) { s->failed_pc=0x0c06c7b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06c7b6;
P_0c06c7b6: /* original 8f02, guest PC 0x0c06c7b6 */
if(!s->budget--) { s->failed_pc=0x0c06c7b6u; return 0; }
cond=r[17]&1u;
r[4]&=r[6];
if(!cond) { goto P_0c06c7be; }
goto P_0c06c7ba;
P_0c06c7b8: /* original 2469, guest PC 0x0c06c7b8 */
if(!s->budget--) { s->failed_pc=0x0c06c7b8u; return 0; }
r[4]&=r[6];
goto P_0c06c7ba;
P_0c06c7ba: /* original 246a, guest PC 0x0c06c7ba */
if(!s->budget--) { s->failed_pc=0x0c06c7bau; return 0; }
r[4]^=r[6];
goto P_0c06c7bc;
P_0c06c7bc: /* original 0744, guest PC 0x0c06c7bc */
if(!s->budget--) { s->failed_pc=0x0c06c7bcu; return 0; }
write(ram,r[7]+r[0],r[4],1);
goto P_0c06c7be;
P_0c06c7be: /* original d008, guest PC 0x0c06c7be */
if(!s->budget--) { s->failed_pc=0x0c06c7beu; return 0; }
r[0]=read(ram,0x0c06c7e0u,4);
goto P_0c06c7c0;
P_0c06c7c0: /* original 4408, guest PC 0x0c06c7c0 */
if(!s->budget--) { s->failed_pc=0x0c06c7c0u; return 0; }
r[4]<<=2;
goto P_0c06c7c2;
P_0c06c7c2: /* original 034e, guest PC 0x0c06c7c2 */
if(!s->budget--) { s->failed_pc=0x0c06c7c2u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c06c7c4;
P_0c06c7c4: /* original 6233, guest PC 0x0c06c7c4 */
if(!s->budget--) { s->failed_pc=0x0c06c7c4u; return 0; }
r[2]=r[3];
goto P_0c06c7c6;
P_0c06c7c6: /* original 2f32, guest PC 0x0c06c7c6 */
if(!s->budget--) { s->failed_pc=0x0c06c7c6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c7c8;
P_0c06c7c8: /* original 422b, guest PC 0x0c06c7c8 */
if(!s->budget--) { s->failed_pc=0x0c06c7c8u; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c06c7ca: /* original 7f04, guest PC 0x0c06c7ca */
if(!s->budget--) { s->failed_pc=0x0c06c7cau; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c06c7ccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06c7ccu; return 0; } return 1;
P_0c07b35c: /* original d553, guest PC 0x0c07b35c */
if(!s->budget--) { s->failed_pc=0x0c07b35cu; return 0; }
r[5]=read(ram,0x0c07b4acu,4);
goto P_0c07b35e;
P_0c07b35e: /* original 7ffc, guest PC 0x0c07b35e */
if(!s->budget--) { s->failed_pc=0x0c07b35eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07b360;
P_0c07b360: /* original e004, guest PC 0x0c07b360 */
if(!s->budget--) { s->failed_pc=0x0c07b360u; return 0; }
r[0]=0x00000004u;
goto P_0c07b362;
P_0c07b362: /* original f358, guest PC 0x0c07b362 */
if(!s->budget--) { s->failed_pc=0x0c07b362u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c07b364;
P_0c07b364: /* original f432, guest PC 0x0c07b364 */
if(!s->budget--) { s->failed_pc=0x0c07b364u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c07b366;
P_0c07b366: /* original ff3a, guest PC 0x0c07b366 */
if(!s->budget--) { s->failed_pc=0x0c07b366u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c07b368;
P_0c07b368: /* original d651, guest PC 0x0c07b368 */
if(!s->budget--) { s->failed_pc=0x0c07b368u; return 0; }
r[6]=read(ram,0x0c07b4b0u,4);
goto P_0c07b36a;
P_0c07b36a: /* original d352, guest PC 0x0c07b36a */
if(!s->budget--) { s->failed_pc=0x0c07b36au; return 0; }
r[3]=read(ram,0x0c07b4b4u,4);
goto P_0c07b36c;
P_0c07b36c: /* original f968, guest PC 0x0c07b36c */
if(!s->budget--) { s->failed_pc=0x0c07b36cu; return 0; }
vf3_matrix_load(s,ram,9,r[6]);
goto P_0c07b36e;
P_0c07b36e: /* original d252, guest PC 0x0c07b36e */
if(!s->budget--) { s->failed_pc=0x0c07b36eu; return 0; }
r[2]=read(ram,0x0c07b4b8u,4);
goto P_0c07b370;
P_0c07b370: /* original f592, guest PC 0x0c07b370 */
if(!s->budget--) { s->failed_pc=0x0c07b370u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[9],r[18],'*');
goto P_0c07b372;
P_0c07b372: /* original fa38, guest PC 0x0c07b372 */
if(!s->budget--) { s->failed_pc=0x0c07b372u; return 0; }
vf3_matrix_load(s,ram,10,r[3]);
goto P_0c07b374;
P_0c07b374: /* original fb28, guest PC 0x0c07b374 */
if(!s->budget--) { s->failed_pc=0x0c07b374u; return 0; }
vf3_matrix_load(s,ram,11,r[2]);
goto P_0c07b376;
P_0c07b376: /* original f4a0, guest PC 0x0c07b376 */
if(!s->budget--) { s->failed_pc=0x0c07b376u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[10],r[18],'+');
goto P_0c07b378;
P_0c07b378: /* original f5b0, guest PC 0x0c07b378 */
if(!s->budget--) { s->failed_pc=0x0c07b378u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[11],r[18],'+');
goto P_0c07b37a;
P_0c07b37a: /* original f447, guest PC 0x0c07b37a */
if(!s->budget--) { s->failed_pc=0x0c07b37au; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c07b37c;
P_0c07b37c: /* original e008, guest PC 0x0c07b37c */
if(!s->budget--) { s->failed_pc=0x0c07b37cu; return 0; }
r[0]=0x00000008u;
goto P_0c07b37e;
P_0c07b37e: /* original f457, guest PC 0x0c07b37e */
if(!s->budget--) { s->failed_pc=0x0c07b37eu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c07b380;
P_0c07b380: /* original e00c, guest PC 0x0c07b380 */
if(!s->budget--) { s->failed_pc=0x0c07b380u; return 0; }
r[0]=0x0000000cu;
goto P_0c07b382;
P_0c07b382: /* original f487, guest PC 0x0c07b382 */
if(!s->budget--) { s->failed_pc=0x0c07b382u; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c07b384;
P_0c07b384: /* original e010, guest PC 0x0c07b384 */
if(!s->budget--) { s->failed_pc=0x0c07b384u; return 0; }
r[0]=0x00000010u;
goto P_0c07b386;
P_0c07b386: /* original f358, guest PC 0x0c07b386 */
if(!s->budget--) { s->failed_pc=0x0c07b386u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c07b388;
P_0c07b388: /* original f362, guest PC 0x0c07b388 */
if(!s->budget--) { s->failed_pc=0x0c07b388u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c07b38a;
P_0c07b38a: /* original f437, guest PC 0x0c07b38a */
if(!s->budget--) { s->failed_pc=0x0c07b38au; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07b38c;
P_0c07b38c: /* original e014, guest PC 0x0c07b38c */
if(!s->budget--) { s->failed_pc=0x0c07b38cu; return 0; }
r[0]=0x00000014u;
goto P_0c07b38e;
P_0c07b38e: /* original f368, guest PC 0x0c07b38e */
if(!s->budget--) { s->failed_pc=0x0c07b38eu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
goto P_0c07b390;
P_0c07b390: /* original f372, guest PC 0x0c07b390 */
if(!s->budget--) { s->failed_pc=0x0c07b390u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c07b392;
P_0c07b392: /* original f437, guest PC 0x0c07b392 */
if(!s->budget--) { s->failed_pc=0x0c07b392u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07b394;
P_0c07b394: /* original 000b, guest PC 0x0c07b394 */
if(!s->budget--) { s->failed_pc=0x0c07b394u; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c07b396: /* original 7f04, guest PC 0x0c07b396 */
if(!s->budget--) { s->failed_pc=0x0c07b396u; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c07b398u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
