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
int vf3_away_batch125_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c09fe68u: goto P_0c09fe68;
case 0x0c09fe6au: goto P_0c09fe6a;
case 0x0c09fe6cu: goto P_0c09fe6c;
case 0x0c09fe6eu: goto P_0c09fe6e;
case 0x0c09fe70u: goto P_0c09fe70;
case 0x0c09fe72u: goto P_0c09fe72;
case 0x0c09fe74u: goto P_0c09fe74;
case 0x0c09fe76u: goto P_0c09fe76;
case 0x0c09fe78u: goto P_0c09fe78;
case 0x0c09fe7au: goto P_0c09fe7a;
case 0x0c09fe7cu: goto P_0c09fe7c;
case 0x0c09fe7eu: goto P_0c09fe7e;
case 0x0c09fe80u: goto P_0c09fe80;
case 0x0c09fe82u: goto P_0c09fe82;
case 0x0c09fe84u: goto P_0c09fe84;
case 0x0c09fe86u: goto P_0c09fe86;
case 0x0c09fe88u: goto P_0c09fe88;
case 0x0c09fe8au: goto P_0c09fe8a;
case 0x0c09fe8cu: goto P_0c09fe8c;
case 0x0c09fe8eu: goto P_0c09fe8e;
case 0x0c09fe90u: goto P_0c09fe90;
case 0x0c09fe92u: goto P_0c09fe92;
case 0x0c09fe94u: goto P_0c09fe94;
case 0x0c09fe96u: goto P_0c09fe96;
case 0x0c09fe98u: goto P_0c09fe98;
case 0x0c09fe9au: goto P_0c09fe9a;
case 0x0c09fe9cu: goto P_0c09fe9c;
case 0x0c09fe9eu: goto P_0c09fe9e;
case 0x0c09fea0u: goto P_0c09fea0;
case 0x0c09fea2u: goto P_0c09fea2;
case 0x0c09fea4u: goto P_0c09fea4;
case 0x0c09fea6u: goto P_0c09fea6;
case 0x0c09fea8u: goto P_0c09fea8;
case 0x0c09feaau: goto P_0c09feaa;
case 0x0c09feacu: goto P_0c09feac;
case 0x0c09feaeu: goto P_0c09feae;
case 0x0c09feb0u: goto P_0c09feb0;
case 0x0c09feb2u: goto P_0c09feb2;
case 0x0c09feb4u: goto P_0c09feb4;
case 0x0c09feb6u: goto P_0c09feb6;
case 0x0c09feb8u: goto P_0c09feb8;
case 0x0c09febau: goto P_0c09feba;
case 0x0c09febcu: goto P_0c09febc;
case 0x0c09febeu: goto P_0c09febe;
case 0x0c09fec0u: goto P_0c09fec0;
case 0x0c09fec2u: goto P_0c09fec2;
case 0x0c09fec4u: goto P_0c09fec4;
case 0x0c09fec6u: goto P_0c09fec6;
case 0x0c09fec8u: goto P_0c09fec8;
case 0x0c09fecau: goto P_0c09feca;
case 0x0c09feccu: goto P_0c09fecc;
case 0x0c09feceu: goto P_0c09fece;
case 0x0c09fed0u: goto P_0c09fed0;
case 0x0c09fed2u: goto P_0c09fed2;
case 0x0c09fed4u: goto P_0c09fed4;
case 0x0c09fed6u: goto P_0c09fed6;
case 0x0c09fed8u: goto P_0c09fed8;
case 0x0c09fedau: goto P_0c09feda;
case 0x0c09fedcu: goto P_0c09fedc;
case 0x0c09fedeu: goto P_0c09fede;
case 0x0c09fee0u: goto P_0c09fee0;
case 0x0c09fee2u: goto P_0c09fee2;
case 0x0c09fee4u: goto P_0c09fee4;
case 0x0c09fee6u: goto P_0c09fee6;
case 0x0c09fee8u: goto P_0c09fee8;
case 0x0c09feeau: goto P_0c09feea;
case 0x0c09feecu: goto P_0c09feec;
case 0x0c09feeeu: goto P_0c09feee;
case 0x0c09fef0u: goto P_0c09fef0;
case 0x0c09fef2u: goto P_0c09fef2;
case 0x0c09fef4u: goto P_0c09fef4;
case 0x0c09fef6u: goto P_0c09fef6;
case 0x0c09fef8u: goto P_0c09fef8;
case 0x0c09fefau: goto P_0c09fefa;
case 0x0c09fefcu: goto P_0c09fefc;
case 0x0c0c66d0u: goto P_0c0c66d0;
case 0x0c0c66d2u: goto P_0c0c66d2;
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
P_0c09fe68: /* original 2fe6, guest PC 0x0c09fe68 */
if(!s->budget--) { s->failed_pc=0x0c09fe68u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe6a;
P_0c09fe6a: /* original 2fd6, guest PC 0x0c09fe6a */
if(!s->budget--) { s->failed_pc=0x0c09fe6au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe6c;
P_0c09fe6c: /* original 2fc6, guest PC 0x0c09fe6c */
if(!s->budget--) { s->failed_pc=0x0c09fe6cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe6e;
P_0c09fe6e: /* original 2fb6, guest PC 0x0c09fe6e */
if(!s->budget--) { s->failed_pc=0x0c09fe6eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe70;
P_0c09fe70: /* original 2fa6, guest PC 0x0c09fe70 */
if(!s->budget--) { s->failed_pc=0x0c09fe70u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe72;
P_0c09fe72: /* original 2f96, guest PC 0x0c09fe72 */
if(!s->budget--) { s->failed_pc=0x0c09fe72u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe74;
P_0c09fe74: /* original e900, guest PC 0x0c09fe74 */
if(!s->budget--) { s->failed_pc=0x0c09fe74u; return 0; }
r[9]=0x00000000u;
goto P_0c09fe76;
P_0c09fe76: /* original 2f86, guest PC 0x0c09fe76 */
if(!s->budget--) { s->failed_pc=0x0c09fe76u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe78;
P_0c09fe78: /* original e812, guest PC 0x0c09fe78 */
if(!s->budget--) { s->failed_pc=0x0c09fe78u; return 0; }
r[8]=0x00000012u;
goto P_0c09fe7a;
P_0c09fe7a: /* original 4f22, guest PC 0x0c09fe7a */
if(!s->budget--) { s->failed_pc=0x0c09fe7au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09fe7c;
P_0c09fe7c: /* original d343, guest PC 0x0c09fe7c */
if(!s->budget--) { s->failed_pc=0x0c09fe7cu; return 0; }
r[3]=read(ram,0x0c09ff8cu,4);
goto P_0c09fe7e;
P_0c09fe7e: /* original 6e93, guest PC 0x0c09fe7e */
if(!s->budget--) { s->failed_pc=0x0c09fe7eu; return 0; }
r[14]=r[9];
goto P_0c09fe80;
P_0c09fe80: /* original dc41, guest PC 0x0c09fe80 */
if(!s->budget--) { s->failed_pc=0x0c09fe80u; return 0; }
r[12]=read(ram,0x0c09ff88u,4);
goto P_0c09fe82;
P_0c09fe82: /* original 7ff0, guest PC 0x0c09fe82 */
if(!s->budget--) { s->failed_pc=0x0c09fe82u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09fe84;
P_0c09fe84: /* original 2f32, guest PC 0x0c09fe84 */
if(!s->budget--) { s->failed_pc=0x0c09fe84u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09fe86;
P_0c09fe86: /* original 6bc3, guest PC 0x0c09fe86 */
if(!s->budget--) { s->failed_pc=0x0c09fe86u; return 0; }
r[11]=r[12];
goto P_0c09fe88;
P_0c09fe88: /* original d241, guest PC 0x0c09fe88 */
if(!s->budget--) { s->failed_pc=0x0c09fe88u; return 0; }
r[2]=read(ram,0x0c09ff90u,4);
goto P_0c09fe8a;
P_0c09fe8a: /* original 1f23, guest PC 0x0c09fe8a */
if(!s->budget--) { s->failed_pc=0x0c09fe8au; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c09fe8c;
P_0c09fe8c: /* original d341, guest PC 0x0c09fe8c */
if(!s->budget--) { s->failed_pc=0x0c09fe8cu; return 0; }
r[3]=read(ram,0x0c09ff94u,4);
goto P_0c09fe8e;
P_0c09fe8e: /* original 1f31, guest PC 0x0c09fe8e */
if(!s->budget--) { s->failed_pc=0x0c09fe8eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09fe90;
P_0c09fe90: /* original d241, guest PC 0x0c09fe90 */
if(!s->budget--) { s->failed_pc=0x0c09fe90u; return 0; }
r[2]=read(ram,0x0c09ff98u,4);
goto P_0c09fe92;
P_0c09fe92: /* original 1f22, guest PC 0x0c09fe92 */
if(!s->budget--) { s->failed_pc=0x0c09fe92u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c09fe94;
P_0c09fe94: /* original 9a73, guest PC 0x0c09fe94 */
if(!s->budget--) { s->failed_pc=0x0c09fe94u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ff7eu,2);
goto P_0c09fe96;
P_0c09fe96: /* original dd41, guest PC 0x0c09fe96 */
if(!s->budget--) { s->failed_pc=0x0c09fe96u; return 0; }
r[13]=read(ram,0x0c09ff9cu,4);
goto P_0c09fe98;
P_0c09fe98: /* original 3acc, guest PC 0x0c09fe98 */
if(!s->budget--) { s->failed_pc=0x0c09fe98u; return 0; }
r[10]+=r[12];
goto P_0c09fe9a;
P_0c09fe9a: /* original 65f2, guest PC 0x0c09fe9a */
if(!s->budget--) { s->failed_pc=0x0c09fe9au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c09fe9c;
P_0c09fe9c: /* original 7504, guest PC 0x0c09fe9c */
if(!s->budget--) { s->failed_pc=0x0c09fe9cu; return 0; }
r[5]+=0x00000004u;
goto P_0c09fe9e;
P_0c09fe9e: /* original 2f52, guest PC 0x0c09fe9e */
if(!s->budget--) { s->failed_pc=0x0c09fe9eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c09fea0;
P_0c09fea0: /* original 75fc, guest PC 0x0c09fea0 */
if(!s->budget--) { s->failed_pc=0x0c09fea0u; return 0; }
r[5]+=0xfffffffcu;
goto P_0c09fea2;
P_0c09fea2: /* original 6552, guest PC 0x0c09fea2 */
if(!s->budget--) { s->failed_pc=0x0c09fea2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c09fea4;
P_0c09fea4: /* original 4d0b, guest PC 0x0c09fea4 */
if(!s->budget--) { s->failed_pc=0x0c09fea4u; return 0; }
target=r[13];
r[16]=code_base|0x0c09fea8u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fea8u) { target=s->pc; goto dispatch; }
goto P_0c09fea8;
P_0c09fea6: /* original 64b3, guest PC 0x0c09fea6 */
if(!s->budget--) { s->failed_pc=0x0c09fea6u; return 0; }
r[4]=r[11];
goto P_0c09fea8;
P_0c09fea8: /* original 55f3, guest PC 0x0c09fea8 */
if(!s->budget--) { s->failed_pc=0x0c09fea8u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c09feaa;
P_0c09feaa: /* original 64c3, guest PC 0x0c09feaa */
if(!s->budget--) { s->failed_pc=0x0c09feaau; return 0; }
r[4]=r[12];
goto P_0c09feac;
P_0c09feac: /* original 7448, guest PC 0x0c09feac */
if(!s->budget--) { s->failed_pc=0x0c09feacu; return 0; }
r[4]+=0x00000048u;
goto P_0c09feae;
P_0c09feae: /* original 7504, guest PC 0x0c09feae */
if(!s->budget--) { s->failed_pc=0x0c09feaeu; return 0; }
r[5]+=0x00000004u;
goto P_0c09feb0;
P_0c09feb0: /* original 1f53, guest PC 0x0c09feb0 */
if(!s->budget--) { s->failed_pc=0x0c09feb0u; return 0; }
write(ram,r[15]+12,r[5],4);
goto P_0c09feb2;
P_0c09feb2: /* original 75fc, guest PC 0x0c09feb2 */
if(!s->budget--) { s->failed_pc=0x0c09feb2u; return 0; }
r[5]+=0xfffffffcu;
goto P_0c09feb4;
P_0c09feb4: /* original 6552, guest PC 0x0c09feb4 */
if(!s->budget--) { s->failed_pc=0x0c09feb4u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c09feb6;
P_0c09feb6: /* original 4d0b, guest PC 0x0c09feb6 */
if(!s->budget--) { s->failed_pc=0x0c09feb6u; return 0; }
target=r[13];
r[16]=code_base|0x0c09febau;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09febau) { target=s->pc; goto dispatch; }
goto P_0c09feba;
P_0c09feb8: /* original 34ec, guest PC 0x0c09feb8 */
if(!s->budget--) { s->failed_pc=0x0c09feb8u; return 0; }
r[4]+=r[14];
goto P_0c09feba;
P_0c09feba: /* original 55f1, guest PC 0x0c09feba */
if(!s->budget--) { s->failed_pc=0x0c09febau; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c09febc;
P_0c09febc: /* original 7502, guest PC 0x0c09febc */
if(!s->budget--) { s->failed_pc=0x0c09febcu; return 0; }
r[5]+=0x00000002u;
goto P_0c09febe;
P_0c09febe: /* original 1f51, guest PC 0x0c09febe */
if(!s->budget--) { s->failed_pc=0x0c09febeu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c09fec0;
P_0c09fec0: /* original 75fe, guest PC 0x0c09fec0 */
if(!s->budget--) { s->failed_pc=0x0c09fec0u; return 0; }
r[5]+=0xfffffffeu;
goto P_0c09fec2;
P_0c09fec2: /* original 945d, guest PC 0x0c09fec2 */
if(!s->budget--) { s->failed_pc=0x0c09fec2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ff80u,2);
goto P_0c09fec4;
P_0c09fec4: /* original 6551, guest PC 0x0c09fec4 */
if(!s->budget--) { s->failed_pc=0x0c09fec4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c09fec6;
P_0c09fec6: /* original 34cc, guest PC 0x0c09fec6 */
if(!s->budget--) { s->failed_pc=0x0c09fec6u; return 0; }
r[4]+=r[12];
goto P_0c09fec8;
P_0c09fec8: /* original 655d, guest PC 0x0c09fec8 */
if(!s->budget--) { s->failed_pc=0x0c09fec8u; return 0; }
r[5]=r[5]&65535u;
goto P_0c09feca;
P_0c09feca: /* original 4d0b, guest PC 0x0c09feca */
if(!s->budget--) { s->failed_pc=0x0c09fecau; return 0; }
target=r[13];
r[16]=code_base|0x0c09feceu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09feceu) { target=s->pc; goto dispatch; }
goto P_0c09fece;
P_0c09fecc: /* original 34ec, guest PC 0x0c09fecc */
if(!s->budget--) { s->failed_pc=0x0c09feccu; return 0; }
r[4]+=r[14];
goto P_0c09fece;
P_0c09fece: /* original 55f2, guest PC 0x0c09fece */
if(!s->budget--) { s->failed_pc=0x0c09feceu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c09fed0;
P_0c09fed0: /* original 7501, guest PC 0x0c09fed0 */
if(!s->budget--) { s->failed_pc=0x0c09fed0u; return 0; }
r[5]+=0x00000001u;
goto P_0c09fed2;
P_0c09fed2: /* original 1f52, guest PC 0x0c09fed2 */
if(!s->budget--) { s->failed_pc=0x0c09fed2u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c09fed4;
P_0c09fed4: /* original 75ff, guest PC 0x0c09fed4 */
if(!s->budget--) { s->failed_pc=0x0c09fed4u; return 0; }
r[5]+=0xffffffffu;
goto P_0c09fed6;
P_0c09fed6: /* original d332, guest PC 0x0c09fed6 */
if(!s->budget--) { s->failed_pc=0x0c09fed6u; return 0; }
r[3]=read(ram,0x0c09ffa0u,4);
goto P_0c09fed8;
P_0c09fed8: /* original 6550, guest PC 0x0c09fed8 */
if(!s->budget--) { s->failed_pc=0x0c09fed8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c09feda;
P_0c09feda: /* original 430b, guest PC 0x0c09feda */
if(!s->budget--) { s->failed_pc=0x0c09fedau; return 0; }
target=r[3];
r[16]=code_base|0x0c09fedeu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fedeu) { target=s->pc; goto dispatch; }
goto P_0c09fede;
P_0c09fedc: /* original 64a3, guest PC 0x0c09fedc */
if(!s->budget--) { s->failed_pc=0x0c09fedcu; return 0; }
r[4]=r[10];
goto P_0c09fede;
P_0c09fede: /* original 7901, guest PC 0x0c09fede */
if(!s->budget--) { s->failed_pc=0x0c09fedeu; return 0; }
r[9]+=0x00000001u;
goto P_0c09fee0;
P_0c09fee0: /* original 3983, guest PC 0x0c09fee0 */
if(!s->budget--) { s->failed_pc=0x0c09fee0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[8])!=0);
goto P_0c09fee2;
P_0c09fee2: /* original 7e04, guest PC 0x0c09fee2 */
if(!s->budget--) { s->failed_pc=0x0c09fee2u; return 0; }
r[14]+=0x00000004u;
goto P_0c09fee4;
P_0c09fee4: /* original 7a01, guest PC 0x0c09fee4 */
if(!s->budget--) { s->failed_pc=0x0c09fee4u; return 0; }
r[10]+=0x00000001u;
goto P_0c09fee6;
P_0c09fee6: /* original 8fd8, guest PC 0x0c09fee6 */
if(!s->budget--) { s->failed_pc=0x0c09fee6u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000004u;
if(!cond) { goto P_0c09fe9a; }
goto P_0c09feea;
P_0c09fee8: /* original 7b04, guest PC 0x0c09fee8 */
if(!s->budget--) { s->failed_pc=0x0c09fee8u; return 0; }
r[11]+=0x00000004u;
goto P_0c09feea;
P_0c09feea: /* original 7f10, guest PC 0x0c09feea */
if(!s->budget--) { s->failed_pc=0x0c09feeau; return 0; }
r[15]+=0x00000010u;
goto P_0c09feec;
P_0c09feec: /* original 4f26, guest PC 0x0c09feec */
if(!s->budget--) { s->failed_pc=0x0c09feecu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09feee;
P_0c09feee: /* original 68f6, guest PC 0x0c09feee */
if(!s->budget--) { s->failed_pc=0x0c09feeeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09fef0;
P_0c09fef0: /* original 69f6, guest PC 0x0c09fef0 */
if(!s->budget--) { s->failed_pc=0x0c09fef0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09fef2;
P_0c09fef2: /* original 6af6, guest PC 0x0c09fef2 */
if(!s->budget--) { s->failed_pc=0x0c09fef2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09fef4;
P_0c09fef4: /* original 6bf6, guest PC 0x0c09fef4 */
if(!s->budget--) { s->failed_pc=0x0c09fef4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09fef6;
P_0c09fef6: /* original 6cf6, guest PC 0x0c09fef6 */
if(!s->budget--) { s->failed_pc=0x0c09fef6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09fef8;
P_0c09fef8: /* original 6df6, guest PC 0x0c09fef8 */
if(!s->budget--) { s->failed_pc=0x0c09fef8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09fefa;
P_0c09fefa: /* original 000b, guest PC 0x0c09fefa */
if(!s->budget--) { s->failed_pc=0x0c09fefau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09fefc: /* original 6ef6, guest PC 0x0c09fefc */
if(!s->budget--) { s->failed_pc=0x0c09fefcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09fefeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09fefeu; return 0; } return 1;
P_0c0c66d0: /* original 000b, guest PC 0x0c0c66d0 */
if(!s->budget--) { s->failed_pc=0x0c0c66d0u; return 0; }
target=r[16];
write(ram,r[4],r[5],1);
s->pc=target; return ram->oob==0;
P_0c0c66d2: /* original 2450, guest PC 0x0c0c66d2 */
if(!s->budget--) { s->failed_pc=0x0c0c66d2u; return 0; }
write(ram,r[4],r[5],1);
if(!vf3_matrix_family(0x0c0c66d4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66d4u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
