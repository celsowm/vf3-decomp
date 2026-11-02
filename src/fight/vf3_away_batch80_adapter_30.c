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
int vf3_away_batch80_adapter_30(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0cc5e6u: goto P_0c0cc5e6;
case 0x0c0cc5e8u: goto P_0c0cc5e8;
case 0x0c0cc5eau: goto P_0c0cc5ea;
case 0x0c0cc5ecu: goto P_0c0cc5ec;
case 0x0c0cc5eeu: goto P_0c0cc5ee;
case 0x0c0cc5f0u: goto P_0c0cc5f0;
case 0x0c0cc5f2u: goto P_0c0cc5f2;
case 0x0c0cc5f4u: goto P_0c0cc5f4;
case 0x0c0cc5f6u: goto P_0c0cc5f6;
case 0x0c0cc5f8u: goto P_0c0cc5f8;
case 0x0c0cc5fau: goto P_0c0cc5fa;
case 0x0c0cc5fcu: goto P_0c0cc5fc;
case 0x0c0cc5feu: goto P_0c0cc5fe;
case 0x0c0cc600u: goto P_0c0cc600;
case 0x0c0cc602u: goto P_0c0cc602;
case 0x0c0cc604u: goto P_0c0cc604;
case 0x0c0cc606u: goto P_0c0cc606;
case 0x0c0cc608u: goto P_0c0cc608;
case 0x0c0cc60au: goto P_0c0cc60a;
case 0x0c0cc60cu: goto P_0c0cc60c;
case 0x0c0cc60eu: goto P_0c0cc60e;
case 0x0c0cc610u: goto P_0c0cc610;
case 0x0c0cc612u: goto P_0c0cc612;
case 0x0c0cc614u: goto P_0c0cc614;
case 0x0c0cc616u: goto P_0c0cc616;
case 0x0c0cc618u: goto P_0c0cc618;
case 0x0c0cc61au: goto P_0c0cc61a;
case 0x0c0cc61cu: goto P_0c0cc61c;
case 0x0c0cc61eu: goto P_0c0cc61e;
case 0x0c0cc620u: goto P_0c0cc620;
case 0x0c0cc622u: goto P_0c0cc622;
case 0x0c0cc624u: goto P_0c0cc624;
case 0x0c0cc626u: goto P_0c0cc626;
case 0x0c0cc628u: goto P_0c0cc628;
case 0x0c0cc62au: goto P_0c0cc62a;
case 0x0c0cc62cu: goto P_0c0cc62c;
case 0x0c0cc62eu: goto P_0c0cc62e;
case 0x0c0cc630u: goto P_0c0cc630;
case 0x0c0cc632u: goto P_0c0cc632;
case 0x0c0cc634u: goto P_0c0cc634;
case 0x0c0cc636u: goto P_0c0cc636;
case 0x0c0cc638u: goto P_0c0cc638;
case 0x0c0cc63au: goto P_0c0cc63a;
case 0x0c0cc63cu: goto P_0c0cc63c;
case 0x0c0cc63eu: goto P_0c0cc63e;
case 0x0c0cc640u: goto P_0c0cc640;
case 0x0c0cc642u: goto P_0c0cc642;
case 0x0c0cc644u: goto P_0c0cc644;
case 0x0c0cc646u: goto P_0c0cc646;
case 0x0c0cc648u: goto P_0c0cc648;
case 0x0c0cc64au: goto P_0c0cc64a;
case 0x0c0cc64cu: goto P_0c0cc64c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0cc5e6: /* original 2fe6, guest PC 0x0c0cc5e6 */
if(!s->budget--) { s->failed_pc=0x0c0cc5e6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc5e8;
P_0c0cc5e8: /* original 2fd6, guest PC 0x0c0cc5e8 */
if(!s->budget--) { s->failed_pc=0x0c0cc5e8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc5ea;
P_0c0cc5ea: /* original 2fc6, guest PC 0x0c0cc5ea */
if(!s->budget--) { s->failed_pc=0x0c0cc5eau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc5ec;
P_0c0cc5ec: /* original 2fb6, guest PC 0x0c0cc5ec */
if(!s->budget--) { s->failed_pc=0x0c0cc5ecu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc5ee;
P_0c0cc5ee: /* original 2fa6, guest PC 0x0c0cc5ee */
if(!s->budget--) { s->failed_pc=0x0c0cc5eeu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc5f0;
P_0c0cc5f0: /* original 2f96, guest PC 0x0c0cc5f0 */
if(!s->budget--) { s->failed_pc=0x0c0cc5f0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc5f2;
P_0c0cc5f2: /* original d11f, guest PC 0x0c0cc5f2 */
if(!s->budget--) { s->failed_pc=0x0c0cc5f2u; return 0; }
r[1]=read(ram,0x0c0cc670u,4);
goto P_0c0cc5f4;
P_0c0cc5f4: /* original 4f22, guest PC 0x0c0cc5f4 */
if(!s->budget--) { s->failed_pc=0x0c0cc5f4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cc5f6;
P_0c0cc5f6: /* original 6212, guest PC 0x0c0cc5f6 */
if(!s->budget--) { s->failed_pc=0x0c0cc5f6u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0cc5f8;
P_0c0cc5f8: /* original d31c, guest PC 0x0c0cc5f8 */
if(!s->budget--) { s->failed_pc=0x0c0cc5f8u; return 0; }
r[3]=read(ram,0x0c0cc66cu,4);
goto P_0c0cc5fa;
P_0c0cc5fa: /* original 2238, guest PC 0x0c0cc5fa */
if(!s->budget--) { s->failed_pc=0x0c0cc5fau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cc5fc;
P_0c0cc5fc: /* original 8f1f, guest PC 0x0c0cc5fc */
if(!s->budget--) { s->failed_pc=0x0c0cc5fcu; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(!cond) { goto P_0c0cc63e; }
goto P_0c0cc600;
P_0c0cc5fe: /* original 6e43, guest PC 0x0c0cc5fe */
if(!s->budget--) { s->failed_pc=0x0c0cc5feu; return 0; }
r[14]=r[4];
goto P_0c0cc600;
P_0c0cc600: /* original 902b, guest PC 0x0c0cc600 */
if(!s->budget--) { s->failed_pc=0x0c0cc600u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc65au,2);
goto P_0c0cc602;
P_0c0cc602: /* original ec00, guest PC 0x0c0cc602 */
if(!s->budget--) { s->failed_pc=0x0c0cc602u; return 0; }
r[12]=0x00000000u;
goto P_0c0cc604;
P_0c0cc604: /* original d91b, guest PC 0x0c0cc604 */
if(!s->budget--) { s->failed_pc=0x0c0cc604u; return 0; }
r[9]=read(ram,0x0c0cc674u,4);
goto P_0c0cc606;
P_0c0cc606: /* original dd1c, guest PC 0x0c0cc606 */
if(!s->budget--) { s->failed_pc=0x0c0cc606u; return 0; }
r[13]=read(ram,0x0c0cc678u,4);
goto P_0c0cc608;
P_0c0cc608: /* original 0bee, guest PC 0x0c0cc608 */
if(!s->budget--) { s->failed_pc=0x0c0cc608u; return 0; }
r[11]=read(ram,r[14]+r[0],4);
goto P_0c0cc60a;
P_0c0cc60a: /* original a006, guest PC 0x0c0cc60a */
if(!s->budget--) { s->failed_pc=0x0c0cc60au; return 0; }
r[10]=0x00000008u;
goto P_0c0cc61a;
P_0c0cc60c: /* original ea08, guest PC 0x0c0cc60c */
if(!s->budget--) { s->failed_pc=0x0c0cc60cu; return 0; }
r[10]=0x00000008u;
goto P_0c0cc60e;
P_0c0cc60e: /* original 65d5, guest PC 0x0c0cc60e */
if(!s->budget--) { s->failed_pc=0x0c0cc60eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[13]+=2;
r[5]=tmp;
goto P_0c0cc610;
P_0c0cc610: /* original 35ec, guest PC 0x0c0cc610 */
if(!s->budget--) { s->failed_pc=0x0c0cc610u; return 0; }
r[5]+=r[14];
goto P_0c0cc612;
P_0c0cc612: /* original 490b, guest PC 0x0c0cc612 */
if(!s->budget--) { s->failed_pc=0x0c0cc612u; return 0; }
target=r[9];
r[16]=code_base|0x0c0cc616u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cc616u) { target=s->pc; goto dispatch; }
goto P_0c0cc616;
P_0c0cc614: /* original 64b3, guest PC 0x0c0cc614 */
if(!s->budget--) { s->failed_pc=0x0c0cc614u; return 0; }
r[4]=r[11];
goto P_0c0cc616;
P_0c0cc616: /* original 7c01, guest PC 0x0c0cc616 */
if(!s->budget--) { s->failed_pc=0x0c0cc616u; return 0; }
r[12]+=0x00000001u;
goto P_0c0cc618;
P_0c0cc618: /* original 7b40, guest PC 0x0c0cc618 */
if(!s->budget--) { s->failed_pc=0x0c0cc618u; return 0; }
r[11]+=0x00000040u;
goto P_0c0cc61a;
P_0c0cc61a: /* original 3ca3, guest PC 0x0c0cc61a */
if(!s->budget--) { s->failed_pc=0x0c0cc61au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[10])!=0);
goto P_0c0cc61c;
P_0c0cc61c: /* original 8bf7, guest PC 0x0c0cc61c */
if(!s->budget--) { s->failed_pc=0x0c0cc61cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc60e; }
goto P_0c0cc61e;
P_0c0cc61e: /* original 9016, guest PC 0x0c0cc61e */
if(!s->budget--) { s->failed_pc=0x0c0cc61eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc64eu,2);
goto P_0c0cc620;
P_0c0cc620: /* original 04ee, guest PC 0x0c0cc620 */
if(!s->budget--) { s->failed_pc=0x0c0cc620u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0cc622;
P_0c0cc622: /* original 7004, guest PC 0x0c0cc622 */
if(!s->budget--) { s->failed_pc=0x0c0cc622u; return 0; }
r[0]+=0x00000004u;
goto P_0c0cc624;
P_0c0cc624: /* original 07ee, guest PC 0x0c0cc624 */
if(!s->budget--) { s->failed_pc=0x0c0cc624u; return 0; }
r[7]=read(ram,r[14]+r[0],4);
goto P_0c0cc626;
P_0c0cc626: /* original 7004, guest PC 0x0c0cc626 */
if(!s->budget--) { s->failed_pc=0x0c0cc626u; return 0; }
r[0]+=0x00000004u;
goto P_0c0cc628;
P_0c0cc628: /* original 05ee, guest PC 0x0c0cc628 */
if(!s->budget--) { s->failed_pc=0x0c0cc628u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0cc62a;
P_0c0cc62a: /* original 7004, guest PC 0x0c0cc62a */
if(!s->budget--) { s->failed_pc=0x0c0cc62au; return 0; }
r[0]+=0x00000004u;
goto P_0c0cc62c;
P_0c0cc62c: /* original 06ee, guest PC 0x0c0cc62c */
if(!s->budget--) { s->failed_pc=0x0c0cc62cu; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c0cc62e;
P_0c0cc62e: /* original 70f8, guest PC 0x0c0cc62e */
if(!s->budget--) { s->failed_pc=0x0c0cc62eu; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0cc630;
P_0c0cc630: /* original 0e46, guest PC 0x0c0cc630 */
if(!s->budget--) { s->failed_pc=0x0c0cc630u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0cc632;
P_0c0cc632: /* original 7004, guest PC 0x0c0cc632 */
if(!s->budget--) { s->failed_pc=0x0c0cc632u; return 0; }
r[0]+=0x00000004u;
goto P_0c0cc634;
P_0c0cc634: /* original 0e76, guest PC 0x0c0cc634 */
if(!s->budget--) { s->failed_pc=0x0c0cc634u; return 0; }
write(ram,r[14]+r[0],r[7],4);
goto P_0c0cc636;
P_0c0cc636: /* original 7004, guest PC 0x0c0cc636 */
if(!s->budget--) { s->failed_pc=0x0c0cc636u; return 0; }
r[0]+=0x00000004u;
goto P_0c0cc638;
P_0c0cc638: /* original 0e56, guest PC 0x0c0cc638 */
if(!s->budget--) { s->failed_pc=0x0c0cc638u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c0cc63a;
P_0c0cc63a: /* original 70f4, guest PC 0x0c0cc63a */
if(!s->budget--) { s->failed_pc=0x0c0cc63au; return 0; }
r[0]+=0xfffffff4u;
goto P_0c0cc63c;
P_0c0cc63c: /* original 0e66, guest PC 0x0c0cc63c */
if(!s->budget--) { s->failed_pc=0x0c0cc63cu; return 0; }
write(ram,r[14]+r[0],r[6],4);
goto P_0c0cc63e;
P_0c0cc63e: /* original 4f26, guest PC 0x0c0cc63e */
if(!s->budget--) { s->failed_pc=0x0c0cc63eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cc640;
P_0c0cc640: /* original 69f6, guest PC 0x0c0cc640 */
if(!s->budget--) { s->failed_pc=0x0c0cc640u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0cc642;
P_0c0cc642: /* original 6af6, guest PC 0x0c0cc642 */
if(!s->budget--) { s->failed_pc=0x0c0cc642u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0cc644;
P_0c0cc644: /* original 6bf6, guest PC 0x0c0cc644 */
if(!s->budget--) { s->failed_pc=0x0c0cc644u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0cc646;
P_0c0cc646: /* original 6cf6, guest PC 0x0c0cc646 */
if(!s->budget--) { s->failed_pc=0x0c0cc646u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cc648;
P_0c0cc648: /* original 6df6, guest PC 0x0c0cc648 */
if(!s->budget--) { s->failed_pc=0x0c0cc648u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cc64a;
P_0c0cc64a: /* original 000b, guest PC 0x0c0cc64a */
if(!s->budget--) { s->failed_pc=0x0c0cc64au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cc64c: /* original 6ef6, guest PC 0x0c0cc64c */
if(!s->budget--) { s->failed_pc=0x0c0cc64cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0cc64eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0cc64eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
