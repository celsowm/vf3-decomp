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
int vf3_away_batch59_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08d158u: goto P_0c08d158;
case 0x0c08d15au: goto P_0c08d15a;
case 0x0c08d15cu: goto P_0c08d15c;
case 0x0c08d15eu: goto P_0c08d15e;
case 0x0c08d160u: goto P_0c08d160;
case 0x0c08d162u: goto P_0c08d162;
case 0x0c08d164u: goto P_0c08d164;
case 0x0c08d166u: goto P_0c08d166;
case 0x0c08d168u: goto P_0c08d168;
case 0x0c08d16au: goto P_0c08d16a;
case 0x0c08d16cu: goto P_0c08d16c;
case 0x0c08d16eu: goto P_0c08d16e;
case 0x0c08d170u: goto P_0c08d170;
case 0x0c08d172u: goto P_0c08d172;
case 0x0c08d174u: goto P_0c08d174;
case 0x0c08d176u: goto P_0c08d176;
case 0x0c08d178u: goto P_0c08d178;
case 0x0c08d17au: goto P_0c08d17a;
case 0x0c08d17cu: goto P_0c08d17c;
case 0x0c08d17eu: goto P_0c08d17e;
case 0x0c08d180u: goto P_0c08d180;
case 0x0c08d182u: goto P_0c08d182;
case 0x0c08d184u: goto P_0c08d184;
case 0x0c08d186u: goto P_0c08d186;
case 0x0c08d188u: goto P_0c08d188;
case 0x0c08d18au: goto P_0c08d18a;
case 0x0c08d18cu: goto P_0c08d18c;
case 0x0c08d18eu: goto P_0c08d18e;
case 0x0c08d190u: goto P_0c08d190;
case 0x0c0c9ce6u: goto P_0c0c9ce6;
case 0x0c0c9ce8u: goto P_0c0c9ce8;
case 0x0c0c9ceau: goto P_0c0c9cea;
case 0x0c0c9cecu: goto P_0c0c9cec;
case 0x0c0c9ceeu: goto P_0c0c9cee;
case 0x0c0c9cf0u: goto P_0c0c9cf0;
case 0x0c0c9cf2u: goto P_0c0c9cf2;
case 0x0c0c9cf4u: goto P_0c0c9cf4;
case 0x0c0c9cf6u: goto P_0c0c9cf6;
case 0x0c0c9cf8u: goto P_0c0c9cf8;
case 0x0c0c9cfau: goto P_0c0c9cfa;
case 0x0c0c9cfcu: goto P_0c0c9cfc;
case 0x0c0c9cfeu: goto P_0c0c9cfe;
case 0x0c0c9d00u: goto P_0c0c9d00;
case 0x0c0c9d02u: goto P_0c0c9d02;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08d158: /* original d335, guest PC 0x0c08d158 */
if(!s->budget--) { s->failed_pc=0x0c08d158u; return 0; }
r[3]=read(ram,0x0c08d230u,4);
goto P_0c08d15a;
P_0c08d15a: /* original 7ffc, guest PC 0x0c08d15a */
if(!s->budget--) { s->failed_pc=0x0c08d15au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08d15c;
P_0c08d15c: /* original 554d, guest PC 0x0c08d15c */
if(!s->budget--) { s->failed_pc=0x0c08d15cu; return 0; }
r[5]=read(ram,r[4]+52,4);
goto P_0c08d15e;
P_0c08d15e: /* original e040, guest PC 0x0c08d15e */
if(!s->budget--) { s->failed_pc=0x0c08d15eu; return 0; }
r[0]=0x00000040u;
goto P_0c08d160;
P_0c08d160: /* original d732, guest PC 0x0c08d160 */
if(!s->budget--) { s->failed_pc=0x0c08d160u; return 0; }
r[7]=read(ram,0x0c08d22cu,4);
goto P_0c08d162;
P_0c08d162: /* original 4508, guest PC 0x0c08d162 */
if(!s->budget--) { s->failed_pc=0x0c08d162u; return 0; }
r[5]<<=2;
goto P_0c08d164;
P_0c08d164: /* original 064e, guest PC 0x0c08d164 */
if(!s->budget--) { s->failed_pc=0x0c08d164u; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c08d166;
P_0c08d166: /* original 2f32, guest PC 0x0c08d166 */
if(!s->budget--) { s->failed_pc=0x0c08d166u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08d168;
P_0c08d168: /* original 335c, guest PC 0x0c08d168 */
if(!s->budget--) { s->failed_pc=0x0c08d168u; return 0; }
r[3]+=r[5];
goto P_0c08d16a;
P_0c08d16a: /* original 375c, guest PC 0x0c08d16a */
if(!s->budget--) { s->failed_pc=0x0c08d16au; return 0; }
r[7]+=r[5];
goto P_0c08d16c;
P_0c08d16c: /* original 6232, guest PC 0x0c08d16c */
if(!s->budget--) { s->failed_pc=0x0c08d16cu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c08d16e;
P_0c08d16e: /* original 6772, guest PC 0x0c08d16e */
if(!s->budget--) { s->failed_pc=0x0c08d16eu; return 0; }
tmp=read(ram,r[7],4);
r[7]=tmp;
goto P_0c08d170;
P_0c08d170: /* original e040, guest PC 0x0c08d170 */
if(!s->budget--) { s->failed_pc=0x0c08d170u; return 0; }
r[0]=0x00000040u;
goto P_0c08d172;
P_0c08d172: /* original 6323, guest PC 0x0c08d172 */
if(!s->budget--) { s->failed_pc=0x0c08d172u; return 0; }
r[3]=r[2];
goto P_0c08d174;
P_0c08d174: /* original 336c, guest PC 0x0c08d174 */
if(!s->budget--) { s->failed_pc=0x0c08d174u; return 0; }
r[3]+=r[6];
goto P_0c08d176;
P_0c08d176: /* original 376c, guest PC 0x0c08d176 */
if(!s->budget--) { s->failed_pc=0x0c08d176u; return 0; }
r[7]+=r[6];
goto P_0c08d178;
P_0c08d178: /* original 2f22, guest PC 0x0c08d178 */
if(!s->budget--) { s->failed_pc=0x0c08d178u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c08d17a;
P_0c08d17a: /* original 6230, guest PC 0x0c08d17a */
if(!s->budget--) { s->failed_pc=0x0c08d17au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c08d17c;
P_0c08d17c: /* original 6770, guest PC 0x0c08d17c */
if(!s->budget--) { s->failed_pc=0x0c08d17cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]=tmp;
goto P_0c08d17e;
P_0c08d17e: /* original 622c, guest PC 0x0c08d17e */
if(!s->budget--) { s->failed_pc=0x0c08d17eu; return 0; }
r[2]=r[2]&255u;
goto P_0c08d180;
P_0c08d180: /* original 677c, guest PC 0x0c08d180 */
if(!s->budget--) { s->failed_pc=0x0c08d180u; return 0; }
r[7]=r[7]&255u;
goto P_0c08d182;
P_0c08d182: /* original 2f22, guest PC 0x0c08d182 */
if(!s->budget--) { s->failed_pc=0x0c08d182u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c08d184;
P_0c08d184: /* original 145d, guest PC 0x0c08d184 */
if(!s->budget--) { s->failed_pc=0x0c08d184u; return 0; }
write(ram,r[4]+52,r[5],4);
goto P_0c08d186;
P_0c08d186: /* original 0466, guest PC 0x0c08d186 */
if(!s->budget--) { s->failed_pc=0x0c08d186u; return 0; }
write(ram,r[4]+r[0],r[6],4);
goto P_0c08d188;
P_0c08d188: /* original 147e, guest PC 0x0c08d188 */
if(!s->budget--) { s->failed_pc=0x0c08d188u; return 0; }
write(ram,r[4]+56,r[7],4);
goto P_0c08d18a;
P_0c08d18a: /* original 63f2, guest PC 0x0c08d18a */
if(!s->budget--) { s->failed_pc=0x0c08d18au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c08d18c;
P_0c08d18c: /* original 143f, guest PC 0x0c08d18c */
if(!s->budget--) { s->failed_pc=0x0c08d18cu; return 0; }
write(ram,r[4]+60,r[3],4);
goto P_0c08d18e;
P_0c08d18e: /* original 000b, guest PC 0x0c08d18e */
if(!s->budget--) { s->failed_pc=0x0c08d18eu; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c08d190: /* original 7f04, guest PC 0x0c08d190 */
if(!s->budget--) { s->failed_pc=0x0c08d190u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c08d192u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08d192u; return 0; } return 1;
P_0c0c9ce6: /* original 901d, guest PC 0x0c0c9ce6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ce6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9d24u,2);
goto P_0c0c9ce8;
P_0c0c9ce8: /* original d412, guest PC 0x0c0c9ce8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ce8u; return 0; }
r[4]=read(ram,0x0c0c9d34u,4);
goto P_0c0c9cea;
P_0c0c9cea: /* original d316, guest PC 0x0c0c9cea */
if(!s->budget--) { s->failed_pc=0x0c0c9ceau; return 0; }
r[3]=read(ram,0x0c0c9d44u,4);
goto P_0c0c9cec;
P_0c0c9cec: /* original 054e, guest PC 0x0c0c9cec */
if(!s->budget--) { s->failed_pc=0x0c0c9cecu; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0c9cee;
P_0c0c9cee: /* original 4f12, guest PC 0x0c0c9cee */
if(!s->budget--) { s->failed_pc=0x0c0c9ceeu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c9cf0;
P_0c0c9cf0: /* original 0537, guest PC 0x0c0c9cf0 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf0u; return 0; }
r[19]=r[5]*r[3];
goto P_0c0c9cf2;
P_0c0c9cf2: /* original 051a, guest PC 0x0c0c9cf2 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf2u; return 0; }
r[5]=r[19];
goto P_0c0c9cf4;
P_0c0c9cf4: /* original 7501, guest PC 0x0c0c9cf4 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf4u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c9cf6;
P_0c0c9cf6: /* original 0456, guest PC 0x0c0c9cf6 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf6u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c0c9cf8;
P_0c0c9cf8: /* original 4529, guest PC 0x0c0c9cf8 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf8u; return 0; }
r[5]>>=16;
goto P_0c0c9cfa;
P_0c0c9cfa: /* original 9412, guest PC 0x0c0c9cfa */
if(!s->budget--) { s->failed_pc=0x0c0c9cfau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9d22u,2);
goto P_0c0c9cfc;
P_0c0c9cfc: /* original 2459, guest PC 0x0c0c9cfc */
if(!s->budget--) { s->failed_pc=0x0c0c9cfcu; return 0; }
r[4]&=r[5];
goto P_0c0c9cfe;
P_0c0c9cfe: /* original 6043, guest PC 0x0c0c9cfe */
if(!s->budget--) { s->failed_pc=0x0c0c9cfeu; return 0; }
r[0]=r[4];
goto P_0c0c9d00;
P_0c0c9d00: /* original 000b, guest PC 0x0c0c9d00 */
if(!s->budget--) { s->failed_pc=0x0c0c9d00u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c0c9d02: /* original 4f16, guest PC 0x0c0c9d02 */
if(!s->budget--) { s->failed_pc=0x0c0c9d02u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c0c9d04u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9d04u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
