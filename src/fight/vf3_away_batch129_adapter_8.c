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
int vf3_away_batch129_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a2760u: goto P_0c0a2760;
case 0x0c0a2762u: goto P_0c0a2762;
case 0x0c0a2764u: goto P_0c0a2764;
case 0x0c0a2766u: goto P_0c0a2766;
case 0x0c0a2768u: goto P_0c0a2768;
case 0x0c0a276au: goto P_0c0a276a;
case 0x0c0a276cu: goto P_0c0a276c;
case 0x0c0a276eu: goto P_0c0a276e;
case 0x0c0a2770u: goto P_0c0a2770;
case 0x0c0a2772u: goto P_0c0a2772;
case 0x0c0a2774u: goto P_0c0a2774;
case 0x0c0a2776u: goto P_0c0a2776;
case 0x0c0a2778u: goto P_0c0a2778;
case 0x0c0a277au: goto P_0c0a277a;
case 0x0c0a277cu: goto P_0c0a277c;
case 0x0c0a277eu: goto P_0c0a277e;
case 0x0c0a2780u: goto P_0c0a2780;
case 0x0c0a2782u: goto P_0c0a2782;
case 0x0c0a2784u: goto P_0c0a2784;
case 0x0c0a2786u: goto P_0c0a2786;
case 0x0c0a2788u: goto P_0c0a2788;
case 0x0c0a278au: goto P_0c0a278a;
case 0x0c0a278cu: goto P_0c0a278c;
case 0x0c0a278eu: goto P_0c0a278e;
case 0x0c0a2790u: goto P_0c0a2790;
case 0x0c0a2792u: goto P_0c0a2792;
case 0x0c0a2794u: goto P_0c0a2794;
case 0x0c0a2796u: goto P_0c0a2796;
case 0x0c0a2798u: goto P_0c0a2798;
case 0x0c0a279au: goto P_0c0a279a;
case 0x0c0a279cu: goto P_0c0a279c;
case 0x0c0a279eu: goto P_0c0a279e;
case 0x0c0a27a0u: goto P_0c0a27a0;
case 0x0c0a27a2u: goto P_0c0a27a2;
case 0x0c0a27a4u: goto P_0c0a27a4;
case 0x0c0a27a6u: goto P_0c0a27a6;
case 0x0c0a27a8u: goto P_0c0a27a8;
case 0x0c0a27aau: goto P_0c0a27aa;
case 0x0c0a27acu: goto P_0c0a27ac;
case 0x0c0a27aeu: goto P_0c0a27ae;
case 0x0c0a27b0u: goto P_0c0a27b0;
case 0x0c0a27b2u: goto P_0c0a27b2;
case 0x0c0a27b4u: goto P_0c0a27b4;
case 0x0c0a27b6u: goto P_0c0a27b6;
case 0x0c0a27b8u: goto P_0c0a27b8;
case 0x0c0a27bau: goto P_0c0a27ba;
case 0x0c0a27bcu: goto P_0c0a27bc;
case 0x0c0a27beu: goto P_0c0a27be;
case 0x0c0a27c0u: goto P_0c0a27c0;
case 0x0c0a27c2u: goto P_0c0a27c2;
case 0x0c0a27c4u: goto P_0c0a27c4;
case 0x0c0a27c6u: goto P_0c0a27c6;
case 0x0c0a27c8u: goto P_0c0a27c8;
case 0x0c0a27cau: goto P_0c0a27ca;
case 0x0c0a27ccu: goto P_0c0a27cc;
case 0x0c0a27ceu: goto P_0c0a27ce;
case 0x0c0a27d0u: goto P_0c0a27d0;
case 0x0c0a27d2u: goto P_0c0a27d2;
case 0x0c0a27d4u: goto P_0c0a27d4;
case 0x0c0a27d6u: goto P_0c0a27d6;
case 0x0c0a27d8u: goto P_0c0a27d8;
case 0x0c0a27dau: goto P_0c0a27da;
case 0x0c0a27dcu: goto P_0c0a27dc;
case 0x0c0a27deu: goto P_0c0a27de;
case 0x0c0a27e0u: goto P_0c0a27e0;
case 0x0c0a27e2u: goto P_0c0a27e2;
case 0x0c0a27e4u: goto P_0c0a27e4;
case 0x0c0a27e6u: goto P_0c0a27e6;
case 0x0c0a27e8u: goto P_0c0a27e8;
case 0x0c0a27eau: goto P_0c0a27ea;
case 0x0c0a27ecu: goto P_0c0a27ec;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a2760: /* original 2fe6, guest PC 0x0c0a2760 */
if(!s->budget--) { s->failed_pc=0x0c0a2760u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2762;
P_0c0a2762: /* original 2fd6, guest PC 0x0c0a2762 */
if(!s->budget--) { s->failed_pc=0x0c0a2762u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2764;
P_0c0a2764: /* original 6d43, guest PC 0x0c0a2764 */
if(!s->budget--) { s->failed_pc=0x0c0a2764u; return 0; }
r[13]=r[4];
goto P_0c0a2766;
P_0c0a2766: /* original 2fc6, guest PC 0x0c0a2766 */
if(!s->budget--) { s->failed_pc=0x0c0a2766u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2768;
P_0c0a2768: /* original 2fb6, guest PC 0x0c0a2768 */
if(!s->budget--) { s->failed_pc=0x0c0a2768u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a276a;
P_0c0a276a: /* original 2fa6, guest PC 0x0c0a276a */
if(!s->budget--) { s->failed_pc=0x0c0a276au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a276c;
P_0c0a276c: /* original 2f96, guest PC 0x0c0a276c */
if(!s->budget--) { s->failed_pc=0x0c0a276cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a276e;
P_0c0a276e: /* original e900, guest PC 0x0c0a276e */
if(!s->budget--) { s->failed_pc=0x0c0a276eu; return 0; }
r[9]=0x00000000u;
goto P_0c0a2770;
P_0c0a2770: /* original 2f86, guest PC 0x0c0a2770 */
if(!s->budget--) { s->failed_pc=0x0c0a2770u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2772;
P_0c0a2772: /* original 6042, guest PC 0x0c0a2772 */
if(!s->budget--) { s->failed_pc=0x0c0a2772u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c0a2774;
P_0c0a2774: /* original 4f22, guest PC 0x0c0a2774 */
if(!s->budget--) { s->failed_pc=0x0c0a2774u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2776;
P_0c0a2776: /* original c880, guest PC 0x0c0a2776 */
if(!s->budget--) { s->failed_pc=0x0c0a2776u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0a2778;
P_0c0a2778: /* original 8d2f, guest PC 0x0c0a2778 */
if(!s->budget--) { s->failed_pc=0x0c0a2778u; return 0; }
cond=r[17]&1u;
r[5]=r[9];
if(cond) { goto P_0c0a27da; }
goto P_0c0a277c;
P_0c0a277a: /* original 6593, guest PC 0x0c0a277a */
if(!s->budget--) { s->failed_pc=0x0c0a277au; return 0; }
r[5]=r[9];
goto P_0c0a277c;
P_0c0a277c: /* original 6242, guest PC 0x0c0a277c */
if(!s->budget--) { s->failed_pc=0x0c0a277cu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0a277e;
P_0c0a277e: /* original e020, guest PC 0x0c0a277e */
if(!s->budget--) { s->failed_pc=0x0c0a277eu; return 0; }
r[0]=0x00000020u;
goto P_0c0a2780;
P_0c0a2780: /* original d337, guest PC 0x0c0a2780 */
if(!s->budget--) { s->failed_pc=0x0c0a2780u; return 0; }
r[3]=read(ram,0x0c0a2860u,4);
goto P_0c0a2782;
P_0c0a2782: /* original 9169, guest PC 0x0c0a2782 */
if(!s->budget--) { s->failed_pc=0x0c0a2782u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2858u,2);
goto P_0c0a2784;
P_0c0a2784: /* original 2239, guest PC 0x0c0a2784 */
if(!s->budget--) { s->failed_pc=0x0c0a2784u; return 0; }
r[2]&=r[3];
goto P_0c0a2786;
P_0c0a2786: /* original 03dd, guest PC 0x0c0a2786 */
if(!s->budget--) { s->failed_pc=0x0c0a2786u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a2788;
P_0c0a2788: /* original e022, guest PC 0x0c0a2788 */
if(!s->budget--) { s->failed_pc=0x0c0a2788u; return 0; }
r[0]=0x00000022u;
goto P_0c0a278a;
P_0c0a278a: /* original 3210, guest PC 0x0c0a278a */
if(!s->budget--) { s->failed_pc=0x0c0a278au; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c0a278c;
P_0c0a278c: /* original 02dd, guest PC 0x0c0a278c */
if(!s->budget--) { s->failed_pc=0x0c0a278cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a278e;
P_0c0a278e: /* original 633d, guest PC 0x0c0a278e */
if(!s->budget--) { s->failed_pc=0x0c0a278eu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a2790;
P_0c0a2790: /* original 622d, guest PC 0x0c0a2790 */
if(!s->budget--) { s->failed_pc=0x0c0a2790u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0a2792;
P_0c0a2792: /* original 232b, guest PC 0x0c0a2792 */
if(!s->budget--) { s->failed_pc=0x0c0a2792u; return 0; }
r[3]|=r[2];
goto P_0c0a2794;
P_0c0a2794: /* original 2338, guest PC 0x0c0a2794 */
if(!s->budget--) { s->failed_pc=0x0c0a2794u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2796;
P_0c0a2796: /* original 8920, guest PC 0x0c0a2796 */
if(!s->budget--) { s->failed_pc=0x0c0a2796u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a27da; }
goto P_0c0a2798;
P_0c0a2798: /* original e020, guest PC 0x0c0a2798 */
if(!s->budget--) { s->failed_pc=0x0c0a2798u; return 0; }
r[0]=0x00000020u;
goto P_0c0a279a;
P_0c0a279a: /* original d332, guest PC 0x0c0a279a */
if(!s->budget--) { s->failed_pc=0x0c0a279au; return 0; }
r[3]=read(ram,0x0c0a2864u,4);
goto P_0c0a279c;
P_0c0a279c: /* original 04dd, guest PC 0x0c0a279c */
if(!s->budget--) { s->failed_pc=0x0c0a279cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a279e;
P_0c0a279e: /* original 58d4, guest PC 0x0c0a279e */
if(!s->budget--) { s->failed_pc=0x0c0a279eu; return 0; }
r[8]=read(ram,r[13]+16,4);
goto P_0c0a27a0;
P_0c0a27a0: /* original 430b, guest PC 0x0c0a27a0 */
if(!s->budget--) { s->failed_pc=0x0c0a27a0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a27a4u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a27a4u) { target=s->pc; goto dispatch; }
goto P_0c0a27a4;
P_0c0a27a2: /* original 644d, guest PC 0x0c0a27a2 */
if(!s->budget--) { s->failed_pc=0x0c0a27a2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a27a4;
P_0c0a27a4: /* original ea01, guest PC 0x0c0a27a4 */
if(!s->budget--) { s->failed_pc=0x0c0a27a4u; return 0; }
r[10]=0x00000001u;
goto P_0c0a27a6;
P_0c0a27a6: /* original a013, guest PC 0x0c0a27a6 */
if(!s->budget--) { s->failed_pc=0x0c0a27a6u; return 0; }
r[12]=r[9];
goto P_0c0a27d0;
P_0c0a27a8: /* original 6c93, guest PC 0x0c0a27a8 */
if(!s->budget--) { s->failed_pc=0x0c0a27a8u; return 0; }
r[12]=r[9];
goto P_0c0a27aa;
P_0c0a27aa: /* original 6ec3, guest PC 0x0c0a27aa */
if(!s->budget--) { s->failed_pc=0x0c0a27aau; return 0; }
r[14]=r[12];
goto P_0c0a27ac;
P_0c0a27ac: /* original 4e08, guest PC 0x0c0a27ac */
if(!s->budget--) { s->failed_pc=0x0c0a27acu; return 0; }
r[14]<<=2;
goto P_0c0a27ae;
P_0c0a27ae: /* original 3e8c, guest PC 0x0c0a27ae */
if(!s->budget--) { s->failed_pc=0x0c0a27aeu; return 0; }
r[14]+=r[8];
goto P_0c0a27b0;
P_0c0a27b0: /* original 63e2, guest PC 0x0c0a27b0 */
if(!s->budget--) { s->failed_pc=0x0c0a27b0u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0a27b2;
P_0c0a27b2: /* original 5231, guest PC 0x0c0a27b2 */
if(!s->budget--) { s->failed_pc=0x0c0a27b2u; return 0; }
r[2]=read(ram,r[3]+4,4);
goto P_0c0a27b4;
P_0c0a27b4: /* original 22a8, guest PC 0x0c0a27b4 */
if(!s->budget--) { s->failed_pc=0x0c0a27b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[10])==0)!=0);
goto P_0c0a27b6;
P_0c0a27b6: /* original 8904, guest PC 0x0c0a27b6 */
if(!s->budget--) { s->failed_pc=0x0c0a27b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a27c2; }
goto P_0c0a27b8;
P_0c0a27b8: /* original d22b, guest PC 0x0c0a27b8 */
if(!s->budget--) { s->failed_pc=0x0c0a27b8u; return 0; }
r[2]=read(ram,0x0c0a2868u,4);
goto P_0c0a27ba;
P_0c0a27ba: /* original 420b, guest PC 0x0c0a27ba */
if(!s->budget--) { s->failed_pc=0x0c0a27bau; return 0; }
target=r[2];
r[16]=code_base|0x0c0a27beu;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a27beu) { target=s->pc; goto dispatch; }
goto P_0c0a27be;
P_0c0a27bc: /* original 64e2, guest PC 0x0c0a27bc */
if(!s->budget--) { s->failed_pc=0x0c0a27bcu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0a27be;
P_0c0a27be: /* original a006, guest PC 0x0c0a27be */
if(!s->budget--) { s->failed_pc=0x0c0a27beu; return 0; }
goto P_0c0a27ce;
P_0c0a27c0: /* original 0009, guest PC 0x0c0a27c0 */
if(!s->budget--) { s->failed_pc=0x0c0a27c0u; return 0; }
goto P_0c0a27c2;
P_0c0a27c2: /* original 6be2, guest PC 0x0c0a27c2 */
if(!s->budget--) { s->failed_pc=0x0c0a27c2u; return 0; }
tmp=read(ram,r[14],4);
r[11]=tmp;
goto P_0c0a27c4;
P_0c0a27c4: /* original d229, guest PC 0x0c0a27c4 */
if(!s->budget--) { s->failed_pc=0x0c0a27c4u; return 0; }
r[2]=read(ram,0x0c0a286cu,4);
goto P_0c0a27c6;
P_0c0a27c6: /* original 55b1, guest PC 0x0c0a27c6 */
if(!s->budget--) { s->failed_pc=0x0c0a27c6u; return 0; }
r[5]=read(ram,r[11]+4,4);
goto P_0c0a27c8;
P_0c0a27c8: /* original 56b2, guest PC 0x0c0a27c8 */
if(!s->budget--) { s->failed_pc=0x0c0a27c8u; return 0; }
r[6]=read(ram,r[11]+8,4);
goto P_0c0a27ca;
P_0c0a27ca: /* original 420b, guest PC 0x0c0a27ca */
if(!s->budget--) { s->failed_pc=0x0c0a27cau; return 0; }
target=r[2];
r[16]=code_base|0x0c0a27ceu;
tmp=read(ram,r[11],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a27ceu) { target=s->pc; goto dispatch; }
goto P_0c0a27ce;
P_0c0a27cc: /* original 64b2, guest PC 0x0c0a27cc */
if(!s->budget--) { s->failed_pc=0x0c0a27ccu; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c0a27ce;
P_0c0a27ce: /* original 7c01, guest PC 0x0c0a27ce */
if(!s->budget--) { s->failed_pc=0x0c0a27ceu; return 0; }
r[12]+=0x00000001u;
goto P_0c0a27d0;
P_0c0a27d0: /* original 85d6, guest PC 0x0c0a27d0 */
if(!s->budget--) { s->failed_pc=0x0c0a27d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+12,2);
goto P_0c0a27d2;
P_0c0a27d2: /* original 600d, guest PC 0x0c0a27d2 */
if(!s->budget--) { s->failed_pc=0x0c0a27d2u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a27d4;
P_0c0a27d4: /* original 3c03, guest PC 0x0c0a27d4 */
if(!s->budget--) { s->failed_pc=0x0c0a27d4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[0])!=0);
goto P_0c0a27d6;
P_0c0a27d6: /* original 8be8, guest PC 0x0c0a27d6 */
if(!s->budget--) { s->failed_pc=0x0c0a27d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a27aa; }
goto P_0c0a27d8;
P_0c0a27d8: /* original 6593, guest PC 0x0c0a27d8 */
if(!s->budget--) { s->failed_pc=0x0c0a27d8u; return 0; }
r[5]=r[9];
goto P_0c0a27da;
P_0c0a27da: /* original 4f26, guest PC 0x0c0a27da */
if(!s->budget--) { s->failed_pc=0x0c0a27dau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a27dc;
P_0c0a27dc: /* original 6053, guest PC 0x0c0a27dc */
if(!s->budget--) { s->failed_pc=0x0c0a27dcu; return 0; }
r[0]=r[5];
goto P_0c0a27de;
P_0c0a27de: /* original 68f6, guest PC 0x0c0a27de */
if(!s->budget--) { s->failed_pc=0x0c0a27deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a27e0;
P_0c0a27e0: /* original 69f6, guest PC 0x0c0a27e0 */
if(!s->budget--) { s->failed_pc=0x0c0a27e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a27e2;
P_0c0a27e2: /* original 6af6, guest PC 0x0c0a27e2 */
if(!s->budget--) { s->failed_pc=0x0c0a27e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a27e4;
P_0c0a27e4: /* original 6bf6, guest PC 0x0c0a27e4 */
if(!s->budget--) { s->failed_pc=0x0c0a27e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a27e6;
P_0c0a27e6: /* original 6cf6, guest PC 0x0c0a27e6 */
if(!s->budget--) { s->failed_pc=0x0c0a27e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a27e8;
P_0c0a27e8: /* original 6df6, guest PC 0x0c0a27e8 */
if(!s->budget--) { s->failed_pc=0x0c0a27e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a27ea;
P_0c0a27ea: /* original 000b, guest PC 0x0c0a27ea */
if(!s->budget--) { s->failed_pc=0x0c0a27eau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a27ec: /* original 6ef6, guest PC 0x0c0a27ec */
if(!s->budget--) { s->failed_pc=0x0c0a27ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a27eeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a27eeu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
