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
int vf3_away_batch119_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c5dbau: goto P_0c0c5dba;
case 0x0c0c5dbcu: goto P_0c0c5dbc;
case 0x0c0c5dbeu: goto P_0c0c5dbe;
case 0x0c0c5dc0u: goto P_0c0c5dc0;
case 0x0c0c5dc2u: goto P_0c0c5dc2;
case 0x0c0c5dc4u: goto P_0c0c5dc4;
case 0x0c0c5dc6u: goto P_0c0c5dc6;
case 0x0c0c5dc8u: goto P_0c0c5dc8;
case 0x0c0c5dcau: goto P_0c0c5dca;
case 0x0c0c5dccu: goto P_0c0c5dcc;
case 0x0c0c5dceu: goto P_0c0c5dce;
case 0x0c0c5dd0u: goto P_0c0c5dd0;
case 0x0c0c5dd2u: goto P_0c0c5dd2;
case 0x0c0c5dd4u: goto P_0c0c5dd4;
case 0x0c0c5dd6u: goto P_0c0c5dd6;
case 0x0c0c5dd8u: goto P_0c0c5dd8;
case 0x0c0c5ddau: goto P_0c0c5dda;
case 0x0c0c5ddcu: goto P_0c0c5ddc;
case 0x0c0c5ddeu: goto P_0c0c5dde;
case 0x0c0c5de0u: goto P_0c0c5de0;
case 0x0c0c5de2u: goto P_0c0c5de2;
case 0x0c0c5de4u: goto P_0c0c5de4;
case 0x0c0c5de6u: goto P_0c0c5de6;
case 0x0c0c5de8u: goto P_0c0c5de8;
case 0x0c0c5deau: goto P_0c0c5dea;
case 0x0c0c5decu: goto P_0c0c5dec;
case 0x0c0c5deeu: goto P_0c0c5dee;
case 0x0c0c5df0u: goto P_0c0c5df0;
case 0x0c0c5df2u: goto P_0c0c5df2;
case 0x0c0c5df4u: goto P_0c0c5df4;
case 0x0c0c61a8u: goto P_0c0c61a8;
case 0x0c0c61aau: goto P_0c0c61aa;
case 0x0c0c61acu: goto P_0c0c61ac;
case 0x0c0c61aeu: goto P_0c0c61ae;
case 0x0c0c61b0u: goto P_0c0c61b0;
case 0x0c0c61b2u: goto P_0c0c61b2;
case 0x0c0c61b4u: goto P_0c0c61b4;
case 0x0c0c61b6u: goto P_0c0c61b6;
case 0x0c0c61b8u: goto P_0c0c61b8;
case 0x0c0c61bau: goto P_0c0c61ba;
case 0x0c0c61bcu: goto P_0c0c61bc;
case 0x0c0c61beu: goto P_0c0c61be;
case 0x0c0c61c0u: goto P_0c0c61c0;
case 0x0c0c61c2u: goto P_0c0c61c2;
case 0x0c0c61c4u: goto P_0c0c61c4;
case 0x0c0c61c6u: goto P_0c0c61c6;
case 0x0c0c61c8u: goto P_0c0c61c8;
case 0x0c0c61cau: goto P_0c0c61ca;
case 0x0c0c61ccu: goto P_0c0c61cc;
case 0x0c0c61ceu: goto P_0c0c61ce;
case 0x0c0c61d0u: goto P_0c0c61d0;
case 0x0c0c61d2u: goto P_0c0c61d2;
case 0x0c0c61d4u: goto P_0c0c61d4;
case 0x0c0c61d6u: goto P_0c0c61d6;
case 0x0c0c61d8u: goto P_0c0c61d8;
case 0x0c0c61dau: goto P_0c0c61da;
case 0x0c0c61dcu: goto P_0c0c61dc;
case 0x0c0c61deu: goto P_0c0c61de;
case 0x0c0c61e0u: goto P_0c0c61e0;
case 0x0c0c61e2u: goto P_0c0c61e2;
case 0x0c0c61e4u: goto P_0c0c61e4;
case 0x0c0c61e6u: goto P_0c0c61e6;
case 0x0c0c61e8u: goto P_0c0c61e8;
case 0x0c0c61eau: goto P_0c0c61ea;
case 0x0c0c61ecu: goto P_0c0c61ec;
case 0x0c0c61eeu: goto P_0c0c61ee;
case 0x0c0c61f0u: goto P_0c0c61f0;
case 0x0c0c61f2u: goto P_0c0c61f2;
case 0x0c0c61f4u: goto P_0c0c61f4;
case 0x0c0c61f6u: goto P_0c0c61f6;
case 0x0c0c61f8u: goto P_0c0c61f8;
case 0x0c0c61fau: goto P_0c0c61fa;
case 0x0c0c61fcu: goto P_0c0c61fc;
case 0x0c0c61feu: goto P_0c0c61fe;
case 0x0c0c6200u: goto P_0c0c6200;
case 0x0c0c6202u: goto P_0c0c6202;
case 0x0c0c6204u: goto P_0c0c6204;
case 0x0c0c6206u: goto P_0c0c6206;
case 0x0c0c6208u: goto P_0c0c6208;
case 0x0c0c620au: goto P_0c0c620a;
case 0x0c0c620cu: goto P_0c0c620c;
case 0x0c0c620eu: goto P_0c0c620e;
case 0x0c0c6210u: goto P_0c0c6210;
case 0x0c0c6212u: goto P_0c0c6212;
case 0x0c0c6214u: goto P_0c0c6214;
case 0x0c0c6216u: goto P_0c0c6216;
case 0x0c0c6218u: goto P_0c0c6218;
case 0x0c0c621au: goto P_0c0c621a;
case 0x0c0c621cu: goto P_0c0c621c;
case 0x0c0c621eu: goto P_0c0c621e;
case 0x0c0c6220u: goto P_0c0c6220;
case 0x0c0c6222u: goto P_0c0c6222;
case 0x0c0c6224u: goto P_0c0c6224;
case 0x0c0c6226u: goto P_0c0c6226;
case 0x0c0c6228u: goto P_0c0c6228;
case 0x0c0c622au: goto P_0c0c622a;
case 0x0c0c622cu: goto P_0c0c622c;
case 0x0c0c622eu: goto P_0c0c622e;
case 0x0c0c6230u: goto P_0c0c6230;
case 0x0c0c6232u: goto P_0c0c6232;
case 0x0c0c6234u: goto P_0c0c6234;
case 0x0c0c6236u: goto P_0c0c6236;
case 0x0c0c6238u: goto P_0c0c6238;
case 0x0c0c623au: goto P_0c0c623a;
case 0x0c0c623cu: goto P_0c0c623c;
case 0x0c0c623eu: goto P_0c0c623e;
case 0x0c0c6240u: goto P_0c0c6240;
case 0x0c0c6242u: goto P_0c0c6242;
case 0x0c0c6244u: goto P_0c0c6244;
case 0x0c0c6246u: goto P_0c0c6246;
case 0x0c0c6248u: goto P_0c0c6248;
case 0x0c0c624au: goto P_0c0c624a;
case 0x0c0c624cu: goto P_0c0c624c;
case 0x0c0c624eu: goto P_0c0c624e;
case 0x0c0c6250u: goto P_0c0c6250;
case 0x0c0c6252u: goto P_0c0c6252;
case 0x0c0c6254u: goto P_0c0c6254;
case 0x0c0c66b8u: goto P_0c0c66b8;
case 0x0c0c66bau: goto P_0c0c66ba;
case 0x0c0ca05cu: goto P_0c0ca05c;
case 0x0c0ca05eu: goto P_0c0ca05e;
case 0x0c0ca060u: goto P_0c0ca060;
case 0x0c0ca062u: goto P_0c0ca062;
case 0x0c0ca064u: goto P_0c0ca064;
case 0x0c0ca066u: goto P_0c0ca066;
case 0x0c0ca068u: goto P_0c0ca068;
case 0x0c0ca06au: goto P_0c0ca06a;
case 0x0c0ca06cu: goto P_0c0ca06c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c5dba: /* original 2fe6, guest PC 0x0c0c5dba */
if(!s->budget--) { s->failed_pc=0x0c0c5dbau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5dbc;
P_0c0c5dbc: /* original 4411, guest PC 0x0c0c5dbc */
if(!s->budget--) { s->failed_pc=0x0c0c5dbcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c5dbe;
P_0c0c5dbe: /* original 4f22, guest PC 0x0c0c5dbe */
if(!s->budget--) { s->failed_pc=0x0c0c5dbeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5dc0;
P_0c0c5dc0: /* original d517, guest PC 0x0c0c5dc0 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc0u; return 0; }
r[5]=read(ram,0x0c0c5e20u,4);
goto P_0c0c5dc2;
P_0c0c5dc2: /* original 8b15, guest PC 0x0c0c5dc2 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5df0; }
goto P_0c0c5dc4;
P_0c0c5dc4: /* original 921c, guest PC 0x0c0c5dc4 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5e00u,2);
goto P_0c0c5dc6;
P_0c0c5dc6: /* original 3423, guest PC 0x0c0c5dc6 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0c5dc8;
P_0c0c5dc8: /* original 8912, guest PC 0x0c0c5dc8 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5df0; }
goto P_0c0c5dca;
P_0c0c5dca: /* original d016, guest PC 0x0c0c5dca */
if(!s->budget--) { s->failed_pc=0x0c0c5dcau; return 0; }
r[0]=read(ram,0x0c0c5e24u,4);
goto P_0c0c5dcc;
P_0c0c5dcc: /* original 4408, guest PC 0x0c0c5dcc */
if(!s->budget--) { s->failed_pc=0x0c0c5dccu; return 0; }
r[4]<<=2;
goto P_0c0c5dce;
P_0c0c5dce: /* original 6e43, guest PC 0x0c0c5dce */
if(!s->budget--) { s->failed_pc=0x0c0c5dceu; return 0; }
r[14]=r[4];
goto P_0c0c5dd0;
P_0c0c5dd0: /* original 03ee, guest PC 0x0c0c5dd0 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd0u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0c5dd2;
P_0c0c5dd2: /* original 4311, guest PC 0x0c0c5dd2 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0c5dd4;
P_0c0c5dd4: /* original 8b0c, guest PC 0x0c0c5dd4 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5df0; }
goto P_0c0c5dd6;
P_0c0c5dd6: /* original d414, guest PC 0x0c0c5dd6 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd6u; return 0; }
r[4]=read(ram,0x0c0c5e28u,4);
goto P_0c0c5dd8;
P_0c0c5dd8: /* original 60e3, guest PC 0x0c0c5dd8 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd8u; return 0; }
r[0]=r[14];
goto P_0c0c5dda;
P_0c0c5dda: /* original 6252, guest PC 0x0c0c5dda */
if(!s->budget--) { s->failed_pc=0x0c0c5ddau; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c0c5ddc;
P_0c0c5ddc: /* original 034e, guest PC 0x0c0c5ddc */
if(!s->budget--) { s->failed_pc=0x0c0c5ddcu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0c5dde;
P_0c0c5dde: /* original 3320, guest PC 0x0c0c5dde */
if(!s->budget--) { s->failed_pc=0x0c0c5ddeu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0c5de0;
P_0c0c5de0: /* original 8906, guest PC 0x0c0c5de0 */
if(!s->budget--) { s->failed_pc=0x0c0c5de0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5df0; }
goto P_0c0c5de2;
P_0c0c5de2: /* original 6352, guest PC 0x0c0c5de2 */
if(!s->budget--) { s->failed_pc=0x0c0c5de2u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c0c5de4;
P_0c0c5de4: /* original 60e3, guest PC 0x0c0c5de4 */
if(!s->budget--) { s->failed_pc=0x0c0c5de4u; return 0; }
r[0]=r[14];
goto P_0c0c5de6;
P_0c0c5de6: /* original 0436, guest PC 0x0c0c5de6 */
if(!s->budget--) { s->failed_pc=0x0c0c5de6u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c0c5de8;
P_0c0c5de8: /* original d310, guest PC 0x0c0c5de8 */
if(!s->budget--) { s->failed_pc=0x0c0c5de8u; return 0; }
r[3]=read(ram,0x0c0c5e2cu,4);
goto P_0c0c5dea;
P_0c0c5dea: /* original d00e, guest PC 0x0c0c5dea */
if(!s->budget--) { s->failed_pc=0x0c0c5deau; return 0; }
r[0]=read(ram,0x0c0c5e24u,4);
goto P_0c0c5dec;
P_0c0c5dec: /* original 430b, guest PC 0x0c0c5dec */
if(!s->budget--) { s->failed_pc=0x0c0c5decu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5df0u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5df0u) { target=s->pc; goto dispatch; }
goto P_0c0c5df0;
P_0c0c5dee: /* original 04ee, guest PC 0x0c0c5dee */
if(!s->budget--) { s->failed_pc=0x0c0c5deeu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c5df0;
P_0c0c5df0: /* original 4f26, guest PC 0x0c0c5df0 */
if(!s->budget--) { s->failed_pc=0x0c0c5df0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5df2;
P_0c0c5df2: /* original 000b, guest PC 0x0c0c5df2 */
if(!s->budget--) { s->failed_pc=0x0c0c5df2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5df4: /* original 6ef6, guest PC 0x0c0c5df4 */
if(!s->budget--) { s->failed_pc=0x0c0c5df4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c5df6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5df6u; return 0; } return 1;
P_0c0c61a8: /* original 2fe6, guest PC 0x0c0c61a8 */
if(!s->budget--) { s->failed_pc=0x0c0c61a8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61aa;
P_0c0c61aa: /* original 4411, guest PC 0x0c0c61aa */
if(!s->budget--) { s->failed_pc=0x0c0c61aau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c61ac;
P_0c0c61ac: /* original 2fd6, guest PC 0x0c0c61ac */
if(!s->budget--) { s->failed_pc=0x0c0c61acu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61ae;
P_0c0c61ae: /* original 2fc6, guest PC 0x0c0c61ae */
if(!s->budget--) { s->failed_pc=0x0c0c61aeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b0;
P_0c0c61b0: /* original 2fb6, guest PC 0x0c0c61b0 */
if(!s->budget--) { s->failed_pc=0x0c0c61b0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b2;
P_0c0c61b2: /* original 2fa6, guest PC 0x0c0c61b2 */
if(!s->budget--) { s->failed_pc=0x0c0c61b2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b4;
P_0c0c61b4: /* original 2f96, guest PC 0x0c0c61b4 */
if(!s->budget--) { s->failed_pc=0x0c0c61b4u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b6;
P_0c0c61b6: /* original 2f86, guest PC 0x0c0c61b6 */
if(!s->budget--) { s->failed_pc=0x0c0c61b6u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b8;
P_0c0c61b8: /* original 4f22, guest PC 0x0c0c61b8 */
if(!s->budget--) { s->failed_pc=0x0c0c61b8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c61ba;
P_0c0c61ba: /* original 7ffc, guest PC 0x0c0c61ba */
if(!s->budget--) { s->failed_pc=0x0c0c61bau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c61bc;
P_0c0c61bc: /* original 8b41, guest PC 0x0c0c61bc */
if(!s->budget--) { s->failed_pc=0x0c0c61bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6242; }
goto P_0c0c61be;
P_0c0c61be: /* original 924a, guest PC 0x0c0c61be */
if(!s->budget--) { s->failed_pc=0x0c0c61beu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6256u,2);
goto P_0c0c61c0;
P_0c0c61c0: /* original 3423, guest PC 0x0c0c61c0 */
if(!s->budget--) { s->failed_pc=0x0c0c61c0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0c61c2;
P_0c0c61c2: /* original 893e, guest PC 0x0c0c61c2 */
if(!s->budget--) { s->failed_pc=0x0c0c61c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6242; }
goto P_0c0c61c4;
P_0c0c61c4: /* original d325, guest PC 0x0c0c61c4 */
if(!s->budget--) { s->failed_pc=0x0c0c61c4u; return 0; }
r[3]=read(ram,0x0c0c625cu,4);
goto P_0c0c61c6;
P_0c0c61c6: /* original 6143, guest PC 0x0c0c61c6 */
if(!s->budget--) { s->failed_pc=0x0c0c61c6u; return 0; }
r[1]=r[4];
goto P_0c0c61c8;
P_0c0c61c8: /* original 4108, guest PC 0x0c0c61c8 */
if(!s->budget--) { s->failed_pc=0x0c0c61c8u; return 0; }
r[1]<<=2;
goto P_0c0c61ca;
P_0c0c61ca: /* original 313c, guest PC 0x0c0c61ca */
if(!s->budget--) { s->failed_pc=0x0c0c61cau; return 0; }
r[1]+=r[3];
goto P_0c0c61cc;
P_0c0c61cc: /* original 2f12, guest PC 0x0c0c61cc */
if(!s->budget--) { s->failed_pc=0x0c0c61ccu; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0c61ce;
P_0c0c61ce: /* original 6212, guest PC 0x0c0c61ce */
if(!s->budget--) { s->failed_pc=0x0c0c61ceu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0c61d0;
P_0c0c61d0: /* original 4211, guest PC 0x0c0c61d0 */
if(!s->budget--) { s->failed_pc=0x0c0c61d0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c0c61d2;
P_0c0c61d2: /* original 8b36, guest PC 0x0c0c61d2 */
if(!s->budget--) { s->failed_pc=0x0c0c61d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6242; }
goto P_0c0c61d4;
P_0c0c61d4: /* original da23, guest PC 0x0c0c61d4 */
if(!s->budget--) { s->failed_pc=0x0c0c61d4u; return 0; }
r[10]=read(ram,0x0c0c6264u,4);
goto P_0c0c61d6;
P_0c0c61d6: /* original ec00, guest PC 0x0c0c61d6 */
if(!s->budget--) { s->failed_pc=0x0c0c61d6u; return 0; }
r[12]=0x00000000u;
goto P_0c0c61d8;
P_0c0c61d8: /* original db23, guest PC 0x0c0c61d8 */
if(!s->budget--) { s->failed_pc=0x0c0c61d8u; return 0; }
r[11]=read(ram,0x0c0c6268u,4);
goto P_0c0c61da;
P_0c0c61da: /* original dd24, guest PC 0x0c0c61da */
if(!s->budget--) { s->failed_pc=0x0c0c61dau; return 0; }
r[13]=read(ram,0x0c0c626cu,4);
goto P_0c0c61dc;
P_0c0c61dc: /* original d920, guest PC 0x0c0c61dc */
if(!s->budget--) { s->failed_pc=0x0c0c61dcu; return 0; }
r[9]=read(ram,0x0c0c6260u,4);
goto P_0c0c61de;
P_0c0c61de: /* original 983b, guest PC 0x0c0c61de */
if(!s->budget--) { s->failed_pc=0x0c0c61deu; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6258u,2);
goto P_0c0c61e0;
P_0c0c61e0: /* original 6ec3, guest PC 0x0c0c61e0 */
if(!s->budget--) { s->failed_pc=0x0c0c61e0u; return 0; }
r[14]=r[12];
goto P_0c0c61e2;
P_0c0c61e2: /* original 4e08, guest PC 0x0c0c61e2 */
if(!s->budget--) { s->failed_pc=0x0c0c61e2u; return 0; }
r[14]<<=2;
goto P_0c0c61e4;
P_0c0c61e4: /* original 4e00, guest PC 0x0c0c61e4 */
if(!s->budget--) { s->failed_pc=0x0c0c61e4u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c0c61e6;
P_0c0c61e6: /* original 3ebc, guest PC 0x0c0c61e6 */
if(!s->budget--) { s->failed_pc=0x0c0c61e6u; return 0; }
r[14]+=r[11];
goto P_0c0c61e8;
P_0c0c61e8: /* original 53e1, guest PC 0x0c0c61e8 */
if(!s->budget--) { s->failed_pc=0x0c0c61e8u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0c61ea;
P_0c0c61ea: /* original 2338, guest PC 0x0c0c61ea */
if(!s->budget--) { s->failed_pc=0x0c0c61eau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c61ec;
P_0c0c61ec: /* original 8929, guest PC 0x0c0c61ec */
if(!s->budget--) { s->failed_pc=0x0c0c61ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6242; }
goto P_0c0c61ee;
P_0c0c61ee: /* original 52e1, guest PC 0x0c0c61ee */
if(!s->budget--) { s->failed_pc=0x0c0c61eeu; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0c61f0;
P_0c0c61f0: /* original 3420, guest PC 0x0c0c61f0 */
if(!s->budget--) { s->failed_pc=0x0c0c61f0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c0c61f2;
P_0c0c61f2: /* original 8b24, guest PC 0x0c0c61f2 */
if(!s->budget--) { s->failed_pc=0x0c0c61f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c623e; }
goto P_0c0c61f4;
P_0c0c61f4: /* original 6392, guest PC 0x0c0c61f4 */
if(!s->budget--) { s->failed_pc=0x0c0c61f4u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c0c61f6;
P_0c0c61f6: /* original 61e2, guest PC 0x0c0c61f6 */
if(!s->budget--) { s->failed_pc=0x0c0c61f6u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0c61f8;
P_0c0c61f8: /* original 3310, guest PC 0x0c0c61f8 */
if(!s->budget--) { s->failed_pc=0x0c0c61f8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c0c61fa;
P_0c0c61fa: /* original 891a, guest PC 0x0c0c61fa */
if(!s->budget--) { s->failed_pc=0x0c0c61fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6232; }
goto P_0c0c61fc;
P_0c0c61fc: /* original 65a2, guest PC 0x0c0c61fc */
if(!s->budget--) { s->failed_pc=0x0c0c61fcu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0c61fe;
P_0c0c61fe: /* original d31c, guest PC 0x0c0c61fe */
if(!s->budget--) { s->failed_pc=0x0c0c61feu; return 0; }
r[3]=read(ram,0x0c0c6270u,4);
goto P_0c0c6200;
P_0c0c6200: /* original 35dc, guest PC 0x0c0c6200 */
if(!s->budget--) { s->failed_pc=0x0c0c6200u; return 0; }
r[5]+=r[13];
goto P_0c0c6202;
P_0c0c6202: /* original 430b, guest PC 0x0c0c6202 */
if(!s->budget--) { s->failed_pc=0x0c0c6202u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6206u;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6206u) { target=s->pc; goto dispatch; }
goto P_0c0c6206;
P_0c0c6204: /* original 64e2, guest PC 0x0c0c6204 */
if(!s->budget--) { s->failed_pc=0x0c0c6204u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0c6206;
P_0c0c6206: /* original d41b, guest PC 0x0c0c6206 */
if(!s->budget--) { s->failed_pc=0x0c0c6206u; return 0; }
r[4]=read(ram,0x0c0c6274u,4);
goto P_0c0c6208;
P_0c0c6208: /* original bd44, guest PC 0x0c0c6208 */
if(!s->budget--) { s->failed_pc=0x0c0c6208u; return 0; }
target=code_base|0x0c0c5c94u; r[16]=code_base|0x0c0c620cu;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c620cu) { target=s->pc; goto dispatch; }
goto P_0c0c620c;
P_0c0c620a: /* original e500, guest PC 0x0c0c620a */
if(!s->budget--) { s->failed_pc=0x0c0c620au; return 0; }
r[5]=0x00000000u;
goto P_0c0c620c;
P_0c0c620c: /* original d31a, guest PC 0x0c0c620c */
if(!s->budget--) { s->failed_pc=0x0c0c620cu; return 0; }
r[3]=read(ram,0x0c0c6278u,4);
goto P_0c0c620e;
P_0c0c620e: /* original 430b, guest PC 0x0c0c620e */
if(!s->budget--) { s->failed_pc=0x0c0c620eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6212u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6212u) { target=s->pc; goto dispatch; }
goto P_0c0c6212;
P_0c0c6210: /* original e403, guest PC 0x0c0c6210 */
if(!s->budget--) { s->failed_pc=0x0c0c6210u; return 0; }
r[4]=0x00000003u;
goto P_0c0c6212;
P_0c0c6212: /* original d21a, guest PC 0x0c0c6212 */
if(!s->budget--) { s->failed_pc=0x0c0c6212u; return 0; }
r[2]=read(ram,0x0c0c627cu,4);
goto P_0c0c6214;
P_0c0c6214: /* original e503, guest PC 0x0c0c6214 */
if(!s->budget--) { s->failed_pc=0x0c0c6214u; return 0; }
r[5]=0x00000003u;
goto P_0c0c6216;
P_0c0c6216: /* original 64a2, guest PC 0x0c0c6216 */
if(!s->budget--) { s->failed_pc=0x0c0c6216u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c0c6218;
P_0c0c6218: /* original 420b, guest PC 0x0c0c6218 */
if(!s->budget--) { s->failed_pc=0x0c0c6218u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c621cu;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c621cu) { target=s->pc; goto dispatch; }
goto P_0c0c621c;
P_0c0c621a: /* original 34dc, guest PC 0x0c0c621a */
if(!s->budget--) { s->failed_pc=0x0c0c621au; return 0; }
r[4]+=r[13];
goto P_0c0c621c;
P_0c0c621c: /* original 2008, guest PC 0x0c0c621c */
if(!s->budget--) { s->failed_pc=0x0c0c621cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c621e;
P_0c0c621e: /* original 8903, guest PC 0x0c0c621e */
if(!s->budget--) { s->failed_pc=0x0c0c621eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6228; }
goto P_0c0c6220;
P_0c0c6220: /* original d217, guest PC 0x0c0c6220 */
if(!s->budget--) { s->failed_pc=0x0c0c6220u; return 0; }
r[2]=read(ram,0x0c0c6280u,4);
goto P_0c0c6222;
P_0c0c6222: /* original 6583, guest PC 0x0c0c6222 */
if(!s->budget--) { s->failed_pc=0x0c0c6222u; return 0; }
r[5]=r[8];
goto P_0c0c6224;
P_0c0c6224: /* original 420b, guest PC 0x0c0c6224 */
if(!s->budget--) { s->failed_pc=0x0c0c6224u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c6228u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6228u) { target=s->pc; goto dispatch; }
goto P_0c0c6228;
P_0c0c6226: /* original e401, guest PC 0x0c0c6226 */
if(!s->budget--) { s->failed_pc=0x0c0c6226u; return 0; }
r[4]=0x00000001u;
goto P_0c0c6228;
P_0c0c6228: /* original 4c08, guest PC 0x0c0c6228 */
if(!s->budget--) { s->failed_pc=0x0c0c6228u; return 0; }
r[12]<<=2;
goto P_0c0c622a;
P_0c0c622a: /* original 4c00, guest PC 0x0c0c622a */
if(!s->budget--) { s->failed_pc=0x0c0c622au; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c0c622c;
P_0c0c622c: /* original 3cbc, guest PC 0x0c0c622c */
if(!s->budget--) { s->failed_pc=0x0c0c622cu; return 0; }
r[12]+=r[11];
goto P_0c0c622e;
P_0c0c622e: /* original 63c2, guest PC 0x0c0c622e */
if(!s->budget--) { s->failed_pc=0x0c0c622eu; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c0c6230;
P_0c0c6230: /* original 2932, guest PC 0x0c0c6230 */
if(!s->budget--) { s->failed_pc=0x0c0c6230u; return 0; }
write(ram,r[9],r[3],4);
goto P_0c0c6232;
P_0c0c6232: /* original d314, guest PC 0x0c0c6232 */
if(!s->budget--) { s->failed_pc=0x0c0c6232u; return 0; }
r[3]=read(ram,0x0c0c6284u,4);
goto P_0c0c6234;
P_0c0c6234: /* original 64f2, guest PC 0x0c0c6234 */
if(!s->budget--) { s->failed_pc=0x0c0c6234u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c6236;
P_0c0c6236: /* original 430b, guest PC 0x0c0c6236 */
if(!s->budget--) { s->failed_pc=0x0c0c6236u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c623au;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c623au) { target=s->pc; goto dispatch; }
goto P_0c0c623a;
P_0c0c6238: /* original 6442, guest PC 0x0c0c6238 */
if(!s->budget--) { s->failed_pc=0x0c0c6238u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c623a;
P_0c0c623a: /* original a002, guest PC 0x0c0c623a */
if(!s->budget--) { s->failed_pc=0x0c0c623au; return 0; }
goto P_0c0c6242;
P_0c0c623c: /* original 0009, guest PC 0x0c0c623c */
if(!s->budget--) { s->failed_pc=0x0c0c623cu; return 0; }
goto P_0c0c623e;
P_0c0c623e: /* original afcf, guest PC 0x0c0c623e */
if(!s->budget--) { s->failed_pc=0x0c0c623eu; return 0; }
r[12]+=0x00000001u;
goto P_0c0c61e0;
P_0c0c6240: /* original 7c01, guest PC 0x0c0c6240 */
if(!s->budget--) { s->failed_pc=0x0c0c6240u; return 0; }
r[12]+=0x00000001u;
goto P_0c0c6242;
P_0c0c6242: /* original 7f04, guest PC 0x0c0c6242 */
if(!s->budget--) { s->failed_pc=0x0c0c6242u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c6244;
P_0c0c6244: /* original 4f26, guest PC 0x0c0c6244 */
if(!s->budget--) { s->failed_pc=0x0c0c6244u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c6246;
P_0c0c6246: /* original 68f6, guest PC 0x0c0c6246 */
if(!s->budget--) { s->failed_pc=0x0c0c6246u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c6248;
P_0c0c6248: /* original 69f6, guest PC 0x0c0c6248 */
if(!s->budget--) { s->failed_pc=0x0c0c6248u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c624a;
P_0c0c624a: /* original 6af6, guest PC 0x0c0c624a */
if(!s->budget--) { s->failed_pc=0x0c0c624au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c624c;
P_0c0c624c: /* original 6bf6, guest PC 0x0c0c624c */
if(!s->budget--) { s->failed_pc=0x0c0c624cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c624e;
P_0c0c624e: /* original 6cf6, guest PC 0x0c0c624e */
if(!s->budget--) { s->failed_pc=0x0c0c624eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c6250;
P_0c0c6250: /* original 6df6, guest PC 0x0c0c6250 */
if(!s->budget--) { s->failed_pc=0x0c0c6250u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c6252;
P_0c0c6252: /* original 000b, guest PC 0x0c0c6252 */
if(!s->budget--) { s->failed_pc=0x0c0c6252u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c6254: /* original 6ef6, guest PC 0x0c0c6254 */
if(!s->budget--) { s->failed_pc=0x0c0c6254u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c6256u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c6256u; return 0; } return 1;
P_0c0c66b8: /* original 000b, guest PC 0x0c0c66b8 */
if(!s->budget--) { s->failed_pc=0x0c0c66b8u; return 0; }
target=r[16];
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c66ba: /* original 6040, guest PC 0x0c0c66ba */
if(!s->budget--) { s->failed_pc=0x0c0c66bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
if(!vf3_matrix_family(0x0c0c66bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66bcu; return 0; } return 1;
P_0c0ca05c: /* original e061, guest PC 0x0c0ca05c */
if(!s->budget--) { s->failed_pc=0x0c0ca05cu; return 0; }
r[0]=0x00000061u;
goto P_0c0ca05e;
P_0c0ca05e: /* original 034c, guest PC 0x0c0ca05e */
if(!s->budget--) { s->failed_pc=0x0c0ca05eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0ca060;
P_0c0ca060: /* original d003, guest PC 0x0c0ca060 */
if(!s->budget--) { s->failed_pc=0x0c0ca060u; return 0; }
r[0]=read(ram,0x0c0ca070u,4);
goto P_0c0ca062;
P_0c0ca062: /* original 633c, guest PC 0x0c0ca062 */
if(!s->budget--) { s->failed_pc=0x0c0ca062u; return 0; }
r[3]=r[3]&255u;
goto P_0c0ca064;
P_0c0ca064: /* original 4308, guest PC 0x0c0ca064 */
if(!s->budget--) { s->failed_pc=0x0c0ca064u; return 0; }
r[3]<<=2;
goto P_0c0ca066;
P_0c0ca066: /* original 043e, guest PC 0x0c0ca066 */
if(!s->budget--) { s->failed_pc=0x0c0ca066u; return 0; }
r[4]=read(ram,r[3]+r[0],4);
goto P_0c0ca068;
P_0c0ca068: /* original d302, guest PC 0x0c0ca068 */
if(!s->budget--) { s->failed_pc=0x0c0ca068u; return 0; }
r[3]=read(ram,0x0c0ca074u,4);
goto P_0c0ca06a;
P_0c0ca06a: /* original 432b, guest PC 0x0c0ca06a */
if(!s->budget--) { s->failed_pc=0x0c0ca06au; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0c5d86u: return vf3_matrix_family(0x0c0c5d86u,s,ram);
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
P_0c0ca06c: /* original 0009, guest PC 0x0c0ca06c */
if(!s->budget--) { s->failed_pc=0x0c0ca06cu; return 0; }
if(!vf3_matrix_family(0x0c0ca06eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ca06eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
