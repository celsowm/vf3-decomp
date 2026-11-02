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
int vf3_away_batch261_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c086178u: goto P_0c086178;
case 0x0c08617au: goto P_0c08617a;
case 0x0c08617cu: goto P_0c08617c;
case 0x0c08617eu: goto P_0c08617e;
case 0x0c086180u: goto P_0c086180;
case 0x0c086182u: goto P_0c086182;
case 0x0c086184u: goto P_0c086184;
case 0x0c086186u: goto P_0c086186;
case 0x0c086188u: goto P_0c086188;
case 0x0c08618au: goto P_0c08618a;
case 0x0c08618cu: goto P_0c08618c;
case 0x0c08618eu: goto P_0c08618e;
case 0x0c086190u: goto P_0c086190;
case 0x0c086192u: goto P_0c086192;
case 0x0c086194u: goto P_0c086194;
case 0x0c086196u: goto P_0c086196;
case 0x0c086198u: goto P_0c086198;
case 0x0c08619au: goto P_0c08619a;
case 0x0c08619cu: goto P_0c08619c;
case 0x0c08619eu: goto P_0c08619e;
case 0x0c0861a0u: goto P_0c0861a0;
case 0x0c0861a2u: goto P_0c0861a2;
case 0x0c0861a4u: goto P_0c0861a4;
case 0x0c0861a6u: goto P_0c0861a6;
case 0x0c0861a8u: goto P_0c0861a8;
case 0x0c0861aau: goto P_0c0861aa;
case 0x0c0861acu: goto P_0c0861ac;
case 0x0c0861aeu: goto P_0c0861ae;
case 0x0c0861b0u: goto P_0c0861b0;
case 0x0c0861b2u: goto P_0c0861b2;
case 0x0c0861b4u: goto P_0c0861b4;
case 0x0c0861b6u: goto P_0c0861b6;
case 0x0c0861b8u: goto P_0c0861b8;
case 0x0c0861bau: goto P_0c0861ba;
case 0x0c0861bcu: goto P_0c0861bc;
case 0x0c0861beu: goto P_0c0861be;
case 0x0c0861c0u: goto P_0c0861c0;
case 0x0c0861c2u: goto P_0c0861c2;
case 0x0c0861c4u: goto P_0c0861c4;
case 0x0c0861c6u: goto P_0c0861c6;
case 0x0c0861c8u: goto P_0c0861c8;
case 0x0c0861cau: goto P_0c0861ca;
case 0x0c0861ccu: goto P_0c0861cc;
case 0x0c0861ceu: goto P_0c0861ce;
case 0x0c0861d0u: goto P_0c0861d0;
case 0x0c0861d2u: goto P_0c0861d2;
case 0x0c0861d4u: goto P_0c0861d4;
case 0x0c0861d6u: goto P_0c0861d6;
case 0x0c0861d8u: goto P_0c0861d8;
case 0x0c0861dau: goto P_0c0861da;
case 0x0c0861dcu: goto P_0c0861dc;
case 0x0c0861deu: goto P_0c0861de;
case 0x0c0861e0u: goto P_0c0861e0;
case 0x0c0861e2u: goto P_0c0861e2;
case 0x0c0861e4u: goto P_0c0861e4;
case 0x0c0861e6u: goto P_0c0861e6;
case 0x0c0861e8u: goto P_0c0861e8;
case 0x0c0861eau: goto P_0c0861ea;
case 0x0c0861ecu: goto P_0c0861ec;
case 0x0c0861eeu: goto P_0c0861ee;
case 0x0c0861f0u: goto P_0c0861f0;
case 0x0c0861f2u: goto P_0c0861f2;
case 0x0c0861f4u: goto P_0c0861f4;
case 0x0c0861f6u: goto P_0c0861f6;
case 0x0c0861f8u: goto P_0c0861f8;
case 0x0c0861fau: goto P_0c0861fa;
case 0x0c0861fcu: goto P_0c0861fc;
case 0x0c0861feu: goto P_0c0861fe;
case 0x0c086200u: goto P_0c086200;
case 0x0c086202u: goto P_0c086202;
case 0x0c086204u: goto P_0c086204;
case 0x0c086206u: goto P_0c086206;
default: return vf3_matrix_family(target,s,ram);
}
P_0c086178: /* original 2fe6, guest PC 0x0c086178 */
if(!s->budget--) { s->failed_pc=0x0c086178u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08617a;
P_0c08617a: /* original 2fd6, guest PC 0x0c08617a */
if(!s->budget--) { s->failed_pc=0x0c08617au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08617c;
P_0c08617c: /* original 2fc6, guest PC 0x0c08617c */
if(!s->budget--) { s->failed_pc=0x0c08617cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08617e;
P_0c08617e: /* original 2fb6, guest PC 0x0c08617e */
if(!s->budget--) { s->failed_pc=0x0c08617eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086180;
P_0c086180: /* original 2fa6, guest PC 0x0c086180 */
if(!s->budget--) { s->failed_pc=0x0c086180u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086182;
P_0c086182: /* original 4f22, guest PC 0x0c086182 */
if(!s->budget--) { s->failed_pc=0x0c086182u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c086184;
P_0c086184: /* original db21, guest PC 0x0c086184 */
if(!s->budget--) { s->failed_pc=0x0c086184u; return 0; }
r[11]=read(ram,0x0c08620cu,4);
goto P_0c086186;
P_0c086186: /* original 7ffc, guest PC 0x0c086186 */
if(!s->budget--) { s->failed_pc=0x0c086186u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c086188;
P_0c086188: /* original 2f42, guest PC 0x0c086188 */
if(!s->budget--) { s->failed_pc=0x0c086188u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c08618a;
P_0c08618a: /* original d321, guest PC 0x0c08618a */
if(!s->budget--) { s->failed_pc=0x0c08618au; return 0; }
r[3]=read(ram,0x0c086210u,4);
goto P_0c08618c;
P_0c08618c: /* original 430b, guest PC 0x0c08618c */
if(!s->budget--) { s->failed_pc=0x0c08618cu; return 0; }
target=r[3];
r[16]=code_base|0x0c086190u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c086190u) { target=s->pc; goto dispatch; }
goto P_0c086190;
P_0c08618e: /* original e400, guest PC 0x0c08618e */
if(!s->budget--) { s->failed_pc=0x0c08618eu; return 0; }
r[4]=0x00000000u;
goto P_0c086190;
P_0c086190: /* original 64f2, guest PC 0x0c086190 */
if(!s->budget--) { s->failed_pc=0x0c086190u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c086192;
P_0c086192: /* original 9d39, guest PC 0x0c086192 */
if(!s->budget--) { s->failed_pc=0x0c086192u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086208u,2);
goto P_0c086194;
P_0c086194: /* original 5345, guest PC 0x0c086194 */
if(!s->budget--) { s->failed_pc=0x0c086194u; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c086196;
P_0c086196: /* original d220, guest PC 0x0c086196 */
if(!s->budget--) { s->failed_pc=0x0c086196u; return 0; }
r[2]=read(ram,0x0c086218u,4);
goto P_0c086198;
P_0c086198: /* original 3d4c, guest PC 0x0c086198 */
if(!s->budget--) { s->failed_pc=0x0c086198u; return 0; }
r[13]+=r[4];
goto P_0c08619a;
P_0c08619a: /* original da1e, guest PC 0x0c08619a */
if(!s->budget--) { s->failed_pc=0x0c08619au; return 0; }
r[10]=read(ram,0x0c086214u,4);
goto P_0c08619c;
P_0c08619c: /* original 420b, guest PC 0x0c08619c */
if(!s->budget--) { s->failed_pc=0x0c08619cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0861a0u;
write(ram,r[11],r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0861a0u) { target=s->pc; goto dispatch; }
goto P_0c0861a0;
P_0c08619e: /* original 2b32, guest PC 0x0c08619e */
if(!s->budget--) { s->failed_pc=0x0c08619eu; return 0; }
write(ram,r[11],r[3],4);
goto P_0c0861a0;
P_0c0861a0: /* original 62b2, guest PC 0x0c0861a0 */
if(!s->budget--) { s->failed_pc=0x0c0861a0u; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c0861a2;
P_0c0861a2: /* original 3d22, guest PC 0x0c0861a2 */
if(!s->budget--) { s->failed_pc=0x0c0861a2u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[2])!=0);
goto P_0c0861a4;
P_0c0861a4: /* original 8b04, guest PC 0x0c0861a4 */
if(!s->budget--) { s->failed_pc=0x0c0861a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0861b0; }
goto P_0c0861a6;
P_0c0861a6: /* original de1d, guest PC 0x0c0861a6 */
if(!s->budget--) { s->failed_pc=0x0c0861a6u; return 0; }
r[14]=read(ram,0x0c08621cu,4);
goto P_0c0861a8;
P_0c0861a8: /* original 4e0b, guest PC 0x0c0861a8 */
if(!s->budget--) { s->failed_pc=0x0c0861a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0861acu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0861acu) { target=s->pc; goto dispatch; }
goto P_0c0861ac;
P_0c0861aa: /* original e401, guest PC 0x0c0861aa */
if(!s->budget--) { s->failed_pc=0x0c0861aau; return 0; }
r[4]=0x00000001u;
goto P_0c0861ac;
P_0c0861ac: /* original a024, guest PC 0x0c0861ac */
if(!s->budget--) { s->failed_pc=0x0c0861acu; return 0; }
goto P_0c0861f8;
P_0c0861ae: /* original 0009, guest PC 0x0c0861ae */
if(!s->budget--) { s->failed_pc=0x0c0861aeu; return 0; }
goto P_0c0861b0;
P_0c0861b0: /* original 5cd4, guest PC 0x0c0861b0 */
if(!s->budget--) { s->failed_pc=0x0c0861b0u; return 0; }
r[12]=read(ram,r[13]+16,4);
goto P_0c0861b2;
P_0c0861b2: /* original e401, guest PC 0x0c0861b2 */
if(!s->budget--) { s->failed_pc=0x0c0861b2u; return 0; }
r[4]=0x00000001u;
goto P_0c0861b4;
P_0c0861b4: /* original 63c3, guest PC 0x0c0861b4 */
if(!s->budget--) { s->failed_pc=0x0c0861b4u; return 0; }
r[3]=r[12];
goto P_0c0861b6;
P_0c0861b6: /* original 2348, guest PC 0x0c0861b6 */
if(!s->budget--) { s->failed_pc=0x0c0861b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0861b8;
P_0c0861b8: /* original 891c, guest PC 0x0c0861b8 */
if(!s->budget--) { s->failed_pc=0x0c0861b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0861f4; }
goto P_0c0861ba;
P_0c0861ba: /* original de19, guest PC 0x0c0861ba */
if(!s->budget--) { s->failed_pc=0x0c0861bau; return 0; }
r[14]=read(ram,0x0c086220u,4);
goto P_0c0861bc;
P_0c0861bc: /* original 4e0b, guest PC 0x0c0861bc */
if(!s->budget--) { s->failed_pc=0x0c0861bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0861c0u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0861c0u) { target=s->pc; goto dispatch; }
goto P_0c0861c0;
P_0c0861be: /* original 64d3, guest PC 0x0c0861be */
if(!s->budget--) { s->failed_pc=0x0c0861beu; return 0; }
r[4]=r[13];
goto P_0c0861c0;
P_0c0861c0: /* original e00c, guest PC 0x0c0861c0 */
if(!s->budget--) { s->failed_pc=0x0c0861c0u; return 0; }
r[0]=0x0000000cu;
goto P_0c0861c2;
P_0c0861c2: /* original f4d6, guest PC 0x0c0861c2 */
if(!s->budget--) { s->failed_pc=0x0c0861c2u; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c0861c4;
P_0c0861c4: /* original c717, guest PC 0x0c0861c4 */
if(!s->budget--) { s->failed_pc=0x0c0861c4u; return 0; }
r[0]=code_base|0x00086224u;
goto P_0c0861c6;
P_0c0861c6: /* original f508, guest PC 0x0c0861c6 */
if(!s->budget--) { s->failed_pc=0x0c0861c6u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0861c8;
P_0c0861c8: /* original f452, guest PC 0x0c0861c8 */
if(!s->budget--) { s->failed_pc=0x0c0861c8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c0861ca;
P_0c0861ca: /* original f43d, guest PC 0x0c0861ca */
if(!s->budget--) { s->failed_pc=0x0c0861cau; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0861cc;
P_0c0861cc: /* original 0e5a, guest PC 0x0c0861cc */
if(!s->budget--) { s->failed_pc=0x0c0861ccu; return 0; }
r[14]=r[53];
goto P_0c0861ce;
P_0c0861ce: /* original 4e11, guest PC 0x0c0861ce */
if(!s->budget--) { s->failed_pc=0x0c0861ceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0861d0;
P_0c0861d0: /* original 8b04, guest PC 0x0c0861d0 */
if(!s->budget--) { s->failed_pc=0x0c0861d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0861dc; }
goto P_0c0861d2;
P_0c0861d2: /* original e41f, guest PC 0x0c0861d2 */
if(!s->budget--) { s->failed_pc=0x0c0861d2u; return 0; }
r[4]=0x0000001fu;
goto P_0c0861d4;
P_0c0861d4: /* original 3e47, guest PC 0x0c0861d4 */
if(!s->budget--) { s->failed_pc=0x0c0861d4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[4])!=0);
goto P_0c0861d6;
P_0c0861d6: /* original 8b03, guest PC 0x0c0861d6 */
if(!s->budget--) { s->failed_pc=0x0c0861d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0861e0; }
goto P_0c0861d8;
P_0c0861d8: /* original a002, guest PC 0x0c0861d8 */
if(!s->budget--) { s->failed_pc=0x0c0861d8u; return 0; }
r[14]=r[4];
goto P_0c0861e0;
P_0c0861da: /* original 6e43, guest PC 0x0c0861da */
if(!s->budget--) { s->failed_pc=0x0c0861dau; return 0; }
r[14]=r[4];
goto P_0c0861dc;
P_0c0861dc: /* original e400, guest PC 0x0c0861dc */
if(!s->budget--) { s->failed_pc=0x0c0861dcu; return 0; }
r[4]=0x00000000u;
goto P_0c0861de;
P_0c0861de: /* original 6e43, guest PC 0x0c0861de */
if(!s->budget--) { s->failed_pc=0x0c0861deu; return 0; }
r[14]=r[4];
goto P_0c0861e0;
P_0c0861e0: /* original e402, guest PC 0x0c0861e0 */
if(!s->budget--) { s->failed_pc=0x0c0861e0u; return 0; }
r[4]=0x00000002u;
goto P_0c0861e2;
P_0c0861e2: /* original 2c48, guest PC 0x0c0861e2 */
if(!s->budget--) { s->failed_pc=0x0c0861e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[4])==0)!=0);
goto P_0c0861e4;
P_0c0861e4: /* original 8900, guest PC 0x0c0861e4 */
if(!s->budget--) { s->failed_pc=0x0c0861e4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0861e8; }
goto P_0c0861e6;
P_0c0861e6: /* original 7e20, guest PC 0x0c0861e6 */
if(!s->budget--) { s->failed_pc=0x0c0861e6u; return 0; }
r[14]+=0x00000020u;
goto P_0c0861e8;
P_0c0861e8: /* original 60e3, guest PC 0x0c0861e8 */
if(!s->budget--) { s->failed_pc=0x0c0861e8u; return 0; }
r[0]=r[14];
goto P_0c0861ea;
P_0c0861ea: /* original 4000, guest PC 0x0c0861ea */
if(!s->budget--) { s->failed_pc=0x0c0861eau; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0861ec;
P_0c0861ec: /* original 04ad, guest PC 0x0c0861ec */
if(!s->budget--) { s->failed_pc=0x0c0861ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c0861ee;
P_0c0861ee: /* original dc0e, guest PC 0x0c0861ee */
if(!s->budget--) { s->failed_pc=0x0c0861eeu; return 0; }
r[12]=read(ram,0x0c086228u,4);
goto P_0c0861f0;
P_0c0861f0: /* original 4c0b, guest PC 0x0c0861f0 */
if(!s->budget--) { s->failed_pc=0x0c0861f0u; return 0; }
target=r[12];
r[16]=code_base|0x0c0861f4u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0861f4u) { target=s->pc; goto dispatch; }
goto P_0c0861f4;
P_0c0861f2: /* original 644d, guest PC 0x0c0861f2 */
if(!s->budget--) { s->failed_pc=0x0c0861f2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0861f4;
P_0c0861f4: /* original afd4, guest PC 0x0c0861f4 */
if(!s->budget--) { s->failed_pc=0x0c0861f4u; return 0; }
r[13]+=0x00000014u;
goto P_0c0861a0;
P_0c0861f6: /* original 7d14, guest PC 0x0c0861f6 */
if(!s->budget--) { s->failed_pc=0x0c0861f6u; return 0; }
r[13]+=0x00000014u;
goto P_0c0861f8;
P_0c0861f8: /* original 7f04, guest PC 0x0c0861f8 */
if(!s->budget--) { s->failed_pc=0x0c0861f8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0861fa;
P_0c0861fa: /* original 4f26, guest PC 0x0c0861fa */
if(!s->budget--) { s->failed_pc=0x0c0861fau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0861fc;
P_0c0861fc: /* original 6af6, guest PC 0x0c0861fc */
if(!s->budget--) { s->failed_pc=0x0c0861fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0861fe;
P_0c0861fe: /* original 6bf6, guest PC 0x0c0861fe */
if(!s->budget--) { s->failed_pc=0x0c0861feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c086200;
P_0c086200: /* original 6cf6, guest PC 0x0c086200 */
if(!s->budget--) { s->failed_pc=0x0c086200u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c086202;
P_0c086202: /* original 6df6, guest PC 0x0c086202 */
if(!s->budget--) { s->failed_pc=0x0c086202u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c086204;
P_0c086204: /* original 000b, guest PC 0x0c086204 */
if(!s->budget--) { s->failed_pc=0x0c086204u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c086206: /* original 6ef6, guest PC 0x0c086206 */
if(!s->budget--) { s->failed_pc=0x0c086206u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c086208u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c086208u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
