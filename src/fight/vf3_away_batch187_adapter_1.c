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
int vf3_away_batch187_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09f984u: goto P_0c09f984;
case 0x0c09f986u: goto P_0c09f986;
case 0x0c09f988u: goto P_0c09f988;
case 0x0c09f98au: goto P_0c09f98a;
case 0x0c09f98cu: goto P_0c09f98c;
case 0x0c09f98eu: goto P_0c09f98e;
case 0x0c09f990u: goto P_0c09f990;
case 0x0c09f992u: goto P_0c09f992;
case 0x0c09f994u: goto P_0c09f994;
case 0x0c09f996u: goto P_0c09f996;
case 0x0c09f998u: goto P_0c09f998;
case 0x0c09f99au: goto P_0c09f99a;
case 0x0c09f99cu: goto P_0c09f99c;
case 0x0c09f99eu: goto P_0c09f99e;
case 0x0c09f9a0u: goto P_0c09f9a0;
case 0x0c09f9a2u: goto P_0c09f9a2;
case 0x0c09f9a4u: goto P_0c09f9a4;
case 0x0c09f9a6u: goto P_0c09f9a6;
case 0x0c09f9a8u: goto P_0c09f9a8;
case 0x0c09f9aau: goto P_0c09f9aa;
case 0x0c09f9acu: goto P_0c09f9ac;
case 0x0c09f9aeu: goto P_0c09f9ae;
case 0x0c09f9b0u: goto P_0c09f9b0;
case 0x0c09f9b2u: goto P_0c09f9b2;
case 0x0c09f9b4u: goto P_0c09f9b4;
case 0x0c09f9b6u: goto P_0c09f9b6;
case 0x0c09f9b8u: goto P_0c09f9b8;
case 0x0c09f9bau: goto P_0c09f9ba;
case 0x0c09f9bcu: goto P_0c09f9bc;
case 0x0c09f9beu: goto P_0c09f9be;
case 0x0c09f9c0u: goto P_0c09f9c0;
case 0x0c09f9c2u: goto P_0c09f9c2;
case 0x0c09f9c4u: goto P_0c09f9c4;
case 0x0c09f9c6u: goto P_0c09f9c6;
case 0x0c09f9c8u: goto P_0c09f9c8;
case 0x0c09f9cau: goto P_0c09f9ca;
case 0x0c09f9ccu: goto P_0c09f9cc;
case 0x0c09f9ceu: goto P_0c09f9ce;
case 0x0c09f9d0u: goto P_0c09f9d0;
case 0x0c09f9d2u: goto P_0c09f9d2;
case 0x0c09f9d4u: goto P_0c09f9d4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09f984: /* original 2fe6, guest PC 0x0c09f984 */
if(!s->budget--) { s->failed_pc=0x0c09f984u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f986;
P_0c09f986: /* original 6e43, guest PC 0x0c09f986 */
if(!s->budget--) { s->failed_pc=0x0c09f986u; return 0; }
r[14]=r[4];
goto P_0c09f988;
P_0c09f988: /* original 9027, guest PC 0x0c09f988 */
if(!s->budget--) { s->failed_pc=0x0c09f988u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f9dau,2);
goto P_0c09f98a;
P_0c09f98a: /* original e3f8, guest PC 0x0c09f98a */
if(!s->budget--) { s->failed_pc=0x0c09f98au; return 0; }
r[3]=0xfffffff8u;
goto P_0c09f98c;
P_0c09f98c: /* original d218, guest PC 0x0c09f98c */
if(!s->budget--) { s->failed_pc=0x0c09f98cu; return 0; }
r[2]=read(ram,0x0c09f9f0u,4);
goto P_0c09f98e;
P_0c09f98e: /* original 04ed, guest PC 0x0c09f98e */
if(!s->budget--) { s->failed_pc=0x0c09f98eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09f990;
P_0c09f990: /* original 7004, guest PC 0x0c09f990 */
if(!s->budget--) { s->failed_pc=0x0c09f990u; return 0; }
r[0]+=0x00000004u;
goto P_0c09f992;
P_0c09f992: /* original 06ed, guest PC 0x0c09f992 */
if(!s->budget--) { s->failed_pc=0x0c09f992u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09f994;
P_0c09f994: /* original e03e, guest PC 0x0c09f994 */
if(!s->budget--) { s->failed_pc=0x0c09f994u; return 0; }
r[0]=0x0000003eu;
goto P_0c09f996;
P_0c09f996: /* original 05ed, guest PC 0x0c09f996 */
if(!s->budget--) { s->failed_pc=0x0c09f996u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09f998;
P_0c09f998: /* original e040, guest PC 0x0c09f998 */
if(!s->budget--) { s->failed_pc=0x0c09f998u; return 0; }
r[0]=0x00000040u;
goto P_0c09f99a;
P_0c09f99a: /* original 07ed, guest PC 0x0c09f99a */
if(!s->budget--) { s->failed_pc=0x0c09f99au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09f99c;
P_0c09f99c: /* original 4418, guest PC 0x0c09f99c */
if(!s->budget--) { s->failed_pc=0x0c09f99cu; return 0; }
r[4]<<=8;
goto P_0c09f99e;
P_0c09f99e: /* original 655d, guest PC 0x0c09f99e */
if(!s->budget--) { s->failed_pc=0x0c09f99eu; return 0; }
r[5]=r[5]&65535u;
goto P_0c09f9a0;
P_0c09f9a0: /* original 677d, guest PC 0x0c09f9a0 */
if(!s->budget--) { s->failed_pc=0x0c09f9a0u; return 0; }
r[7]=r[7]&65535u;
goto P_0c09f9a2;
P_0c09f9a2: /* original 4528, guest PC 0x0c09f9a2 */
if(!s->budget--) { s->failed_pc=0x0c09f9a2u; return 0; }
r[5]<<=16;
goto P_0c09f9a4;
P_0c09f9a4: /* original 257b, guest PC 0x0c09f9a4 */
if(!s->budget--) { s->failed_pc=0x0c09f9a4u; return 0; }
r[5]|=r[7];
goto P_0c09f9a6;
P_0c09f9a6: /* original 453c, guest PC 0x0c09f9a6 */
if(!s->budget--) { s->failed_pc=0x0c09f9a6u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c09f9a8;
P_0c09f9a8: /* original 4f22, guest PC 0x0c09f9a8 */
if(!s->budget--) { s->failed_pc=0x0c09f9a8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09f9aa;
P_0c09f9aa: /* original 2529, guest PC 0x0c09f9aa */
if(!s->budget--) { s->failed_pc=0x0c09f9aau; return 0; }
r[5]&=r[2];
goto P_0c09f9ac;
P_0c09f9ac: /* original 3547, guest PC 0x0c09f9ac */
if(!s->budget--) { s->failed_pc=0x0c09f9acu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[4])!=0);
goto P_0c09f9ae;
P_0c09f9ae: /* original 666d, guest PC 0x0c09f9ae */
if(!s->budget--) { s->failed_pc=0x0c09f9aeu; return 0; }
r[6]=r[6]&65535u;
goto P_0c09f9b0;
P_0c09f9b0: /* original 8d0e, guest PC 0x0c09f9b0 */
if(!s->budget--) { s->failed_pc=0x0c09f9b0u; return 0; }
cond=r[17]&1u;
r[6]<<=8;
if(cond) { goto P_0c09f9d0; }
goto P_0c09f9b4;
P_0c09f9b2: /* original 4618, guest PC 0x0c09f9b2 */
if(!s->budget--) { s->failed_pc=0x0c09f9b2u; return 0; }
r[6]<<=8;
goto P_0c09f9b4;
P_0c09f9b4: /* original 3468, guest PC 0x0c09f9b4 */
if(!s->budget--) { s->failed_pc=0x0c09f9b4u; return 0; }
r[4]-=r[6];
goto P_0c09f9b6;
P_0c09f9b6: /* original 445a, guest PC 0x0c09f9b6 */
if(!s->budget--) { s->failed_pc=0x0c09f9b6u; return 0; }
r[53]=r[4];
goto P_0c09f9b8;
P_0c09f9b8: /* original 3568, guest PC 0x0c09f9b8 */
if(!s->budget--) { s->failed_pc=0x0c09f9b8u; return 0; }
r[5]-=r[6];
goto P_0c09f9ba;
P_0c09f9ba: /* original 9410, guest PC 0x0c09f9ba */
if(!s->budget--) { s->failed_pc=0x0c09f9bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f9deu,2);
goto P_0c09f9bc;
P_0c09f9bc: /* original f32d, guest PC 0x0c09f9bc */
if(!s->budget--) { s->failed_pc=0x0c09f9bcu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c09f9be;
P_0c09f9be: /* original 455a, guest PC 0x0c09f9be */
if(!s->budget--) { s->failed_pc=0x0c09f9beu; return 0; }
r[53]=r[5];
goto P_0c09f9c0;
P_0c09f9c0: /* original 950c, guest PC 0x0c09f9c0 */
if(!s->budget--) { s->failed_pc=0x0c09f9c0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f9dcu,2);
goto P_0c09f9c2;
P_0c09f9c2: /* original f22d, guest PC 0x0c09f9c2 */
if(!s->budget--) { s->failed_pc=0x0c09f9c2u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c09f9c4;
P_0c09f9c4: /* original 35ec, guest PC 0x0c09f9c4 */
if(!s->budget--) { s->failed_pc=0x0c09f9c4u; return 0; }
r[5]+=r[14];
goto P_0c09f9c6;
P_0c09f9c6: /* original f42c, guest PC 0x0c09f9c6 */
if(!s->budget--) { s->failed_pc=0x0c09f9c6u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c09f9c8;
P_0c09f9c8: /* original f433, guest PC 0x0c09f9c8 */
if(!s->budget--) { s->failed_pc=0x0c09f9c8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c09f9ca;
P_0c09f9ca: /* original f52c, guest PC 0x0c09f9ca */
if(!s->budget--) { s->failed_pc=0x0c09f9cau; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c09f9cc;
P_0c09f9cc: /* original bcc2, guest PC 0x0c09f9cc */
if(!s->budget--) { s->failed_pc=0x0c09f9ccu; return 0; }
target=code_base|0x0c09f354u; r[16]=code_base|0x0c09f9d0u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f9d0u) { target=s->pc; goto dispatch; }
goto P_0c09f9d0;
P_0c09f9ce: /* original 34ec, guest PC 0x0c09f9ce */
if(!s->budget--) { s->failed_pc=0x0c09f9ceu; return 0; }
r[4]+=r[14];
goto P_0c09f9d0;
P_0c09f9d0: /* original 4f26, guest PC 0x0c09f9d0 */
if(!s->budget--) { s->failed_pc=0x0c09f9d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09f9d2;
P_0c09f9d2: /* original 000b, guest PC 0x0c09f9d2 */
if(!s->budget--) { s->failed_pc=0x0c09f9d2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09f9d4: /* original 6ef6, guest PC 0x0c09f9d4 */
if(!s->budget--) { s->failed_pc=0x0c09f9d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09f9d6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f9d6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
