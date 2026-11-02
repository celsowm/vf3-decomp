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
int vf3_away_batch175_adapter_36(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0ca05cu: goto P_0c0ca05c;
case 0x0c0ca05eu: goto P_0c0ca05e;
case 0x0c0ca060u: goto P_0c0ca060;
case 0x0c0ca062u: goto P_0c0ca062;
case 0x0c0ca064u: goto P_0c0ca064;
case 0x0c0ca066u: goto P_0c0ca066;
case 0x0c0ca068u: goto P_0c0ca068;
case 0x0c0ca06au: goto P_0c0ca06a;
case 0x0c0ca06cu: goto P_0c0ca06c;
case 0x0c0ca234u: goto P_0c0ca234;
case 0x0c0ca236u: goto P_0c0ca236;
case 0x0c0ca238u: goto P_0c0ca238;
case 0x0c0ca23au: goto P_0c0ca23a;
case 0x0c0ca23cu: goto P_0c0ca23c;
case 0x0c0ca23eu: goto P_0c0ca23e;
case 0x0c0ca240u: goto P_0c0ca240;
case 0x0c0ca242u: goto P_0c0ca242;
case 0x0c0ca244u: goto P_0c0ca244;
case 0x0c0ca246u: goto P_0c0ca246;
case 0x0c0ca248u: goto P_0c0ca248;
case 0x0c0ca24au: goto P_0c0ca24a;
case 0x0c0ca24cu: goto P_0c0ca24c;
case 0x0c0ca24eu: goto P_0c0ca24e;
case 0x0c0ca250u: goto P_0c0ca250;
case 0x0c0ca252u: goto P_0c0ca252;
case 0x0c0ca254u: goto P_0c0ca254;
case 0x0c0ca256u: goto P_0c0ca256;
case 0x0c0ca258u: goto P_0c0ca258;
case 0x0c0ca25au: goto P_0c0ca25a;
case 0x0c0ca25cu: goto P_0c0ca25c;
case 0x0c0ca25eu: goto P_0c0ca25e;
case 0x0c0ca260u: goto P_0c0ca260;
case 0x0c0ca262u: goto P_0c0ca262;
case 0x0c0ca264u: goto P_0c0ca264;
case 0x0c0ca266u: goto P_0c0ca266;
case 0x0c0ca268u: goto P_0c0ca268;
case 0x0c0ca26au: goto P_0c0ca26a;
case 0x0c0ca26cu: goto P_0c0ca26c;
case 0x0c0ca26eu: goto P_0c0ca26e;
case 0x0c0ca270u: goto P_0c0ca270;
case 0x0c0ca272u: goto P_0c0ca272;
case 0x0c0ca274u: goto P_0c0ca274;
case 0x0c0ca276u: goto P_0c0ca276;
case 0x0c0ca278u: goto P_0c0ca278;
case 0x0c0ca27au: goto P_0c0ca27a;
case 0x0c0ca27cu: goto P_0c0ca27c;
case 0x0c0ca27eu: goto P_0c0ca27e;
case 0x0c0ca280u: goto P_0c0ca280;
case 0x0c0ca322u: goto P_0c0ca322;
case 0x0c0ca324u: goto P_0c0ca324;
default: return vf3_matrix_family(target,s,ram);
}
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
P_0c0ca234: /* original d52a, guest PC 0x0c0ca234 */
if(!s->budget--) { s->failed_pc=0x0c0ca234u; return 0; }
r[5]=read(ram,0x0c0ca2e0u,4);
goto P_0c0ca236;
P_0c0ca236: /* original e01c, guest PC 0x0c0ca236 */
if(!s->budget--) { s->failed_pc=0x0c0ca236u; return 0; }
r[0]=0x0000001cu;
goto P_0c0ca238;
P_0c0ca238: /* original d42a, guest PC 0x0c0ca238 */
if(!s->budget--) { s->failed_pc=0x0c0ca238u; return 0; }
r[4]=read(ram,0x0c0ca2e4u,4);
goto P_0c0ca23a;
P_0c0ca23a: /* original e3fe, guest PC 0x0c0ca23a */
if(!s->budget--) { s->failed_pc=0x0c0ca23au; return 0; }
r[3]=0xfffffffeu;
goto P_0c0ca23c;
P_0c0ca23c: /* original 5251, guest PC 0x0c0ca23c */
if(!s->budget--) { s->failed_pc=0x0c0ca23cu; return 0; }
r[2]=read(ram,r[5]+4,4);
goto P_0c0ca23e;
P_0c0ca23e: /* original e70f, guest PC 0x0c0ca23e */
if(!s->budget--) { s->failed_pc=0x0c0ca23eu; return 0; }
r[7]=0x0000000fu;
goto P_0c0ca240;
P_0c0ca240: /* original 4f22, guest PC 0x0c0ca240 */
if(!s->budget--) { s->failed_pc=0x0c0ca240u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ca242;
P_0c0ca242: /* original 2239, guest PC 0x0c0ca242 */
if(!s->budget--) { s->failed_pc=0x0c0ca242u; return 0; }
r[2]&=r[3];
goto P_0c0ca244;
P_0c0ca244: /* original 1521, guest PC 0x0c0ca244 */
if(!s->budget--) { s->failed_pc=0x0c0ca244u; return 0; }
write(ram,r[5]+4,r[2],4);
goto P_0c0ca246;
P_0c0ca246: /* original 004c, guest PC 0x0c0ca246 */
if(!s->budget--) { s->failed_pc=0x0c0ca246u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0ca248;
P_0c0ca248: /* original 7ffc, guest PC 0x0c0ca248 */
if(!s->budget--) { s->failed_pc=0x0c0ca248u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ca24a;
P_0c0ca24a: /* original d427, guest PC 0x0c0ca24a */
if(!s->budget--) { s->failed_pc=0x0c0ca24au; return 0; }
r[4]=read(ram,0x0c0ca2e8u,4);
goto P_0c0ca24c;
P_0c0ca24c: /* original 600c, guest PC 0x0c0ca24c */
if(!s->budget--) { s->failed_pc=0x0c0ca24cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ca24e;
P_0c0ca24e: /* original 2709, guest PC 0x0c0ca24e */
if(!s->budget--) { s->failed_pc=0x0c0ca24eu; return 0; }
r[7]&=r[0];
goto P_0c0ca250;
P_0c0ca250: /* original 5341, guest PC 0x0c0ca250 */
if(!s->budget--) { s->failed_pc=0x0c0ca250u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0ca252;
P_0c0ca252: /* original 6642, guest PC 0x0c0ca252 */
if(!s->budget--) { s->failed_pc=0x0c0ca252u; return 0; }
tmp=read(ram,r[4],4);
r[6]=tmp;
goto P_0c0ca254;
P_0c0ca254: /* original 2f32, guest PC 0x0c0ca254 */
if(!s->budget--) { s->failed_pc=0x0c0ca254u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ca256;
P_0c0ca256: /* original 3760, guest PC 0x0c0ca256 */
if(!s->budget--) { s->failed_pc=0x0c0ca256u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[6])!=0);
goto P_0c0ca258;
P_0c0ca258: /* original 8d0c, guest PC 0x0c0ca258 */
if(!s->budget--) { s->failed_pc=0x0c0ca258u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000008u;
if(cond) { goto P_0c0ca274; }
goto P_0c0ca25c;
P_0c0ca25a: /* original 7408, guest PC 0x0c0ca25a */
if(!s->budget--) { s->failed_pc=0x0c0ca25au; return 0; }
r[4]+=0x00000008u;
goto P_0c0ca25c;
P_0c0ca25c: /* original 6063, guest PC 0x0c0ca25c */
if(!s->budget--) { s->failed_pc=0x0c0ca25cu; return 0; }
r[0]=r[6];
goto P_0c0ca25e;
P_0c0ca25e: /* original 88ff, guest PC 0x0c0ca25e */
if(!s->budget--) { s->failed_pc=0x0c0ca25eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0ca260;
P_0c0ca260: /* original 8bf6, guest PC 0x0c0ca260 */
if(!s->budget--) { s->failed_pc=0x0c0ca260u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ca250; }
goto P_0c0ca262;
P_0c0ca262: /* original e000, guest PC 0x0c0ca262 */
if(!s->budget--) { s->failed_pc=0x0c0ca262u; return 0; }
r[0]=0x00000000u;
goto P_0c0ca264;
P_0c0ca264: /* original 8051, guest PC 0x0c0ca264 */
if(!s->budget--) { s->failed_pc=0x0c0ca264u; return 0; }
write(ram,r[5]+1,r[0],1);
goto P_0c0ca266;
P_0c0ca266: /* original d421, guest PC 0x0c0ca266 */
if(!s->budget--) { s->failed_pc=0x0c0ca266u; return 0; }
r[4]=read(ram,0x0c0ca2ecu,4);
goto P_0c0ca268;
P_0c0ca268: /* original b05b, guest PC 0x0c0ca268 */
if(!s->budget--) { s->failed_pc=0x0c0ca268u; return 0; }
target=code_base|0x0c0ca322u; r[16]=code_base|0x0c0ca26cu;
r[5]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ca26cu) { target=s->pc; goto dispatch; }
goto P_0c0ca26c;
P_0c0ca26a: /* original e501, guest PC 0x0c0ca26a */
if(!s->budget--) { s->failed_pc=0x0c0ca26au; return 0; }
r[5]=0x00000001u;
goto P_0c0ca26c;
P_0c0ca26c: /* original 7f04, guest PC 0x0c0ca26c */
if(!s->budget--) { s->failed_pc=0x0c0ca26cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0ca26e;
P_0c0ca26e: /* original 4f26, guest PC 0x0c0ca26e */
if(!s->budget--) { s->failed_pc=0x0c0ca26eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ca270;
P_0c0ca270: /* original 000b, guest PC 0x0c0ca270 */
if(!s->budget--) { s->failed_pc=0x0c0ca270u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0ca272: /* original 0009, guest PC 0x0c0ca272 */
if(!s->budget--) { s->failed_pc=0x0c0ca272u; return 0; }
goto P_0c0ca274;
P_0c0ca274: /* original 63f2, guest PC 0x0c0ca274 */
if(!s->budget--) { s->failed_pc=0x0c0ca274u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0ca276;
P_0c0ca276: /* original 430b, guest PC 0x0c0ca276 */
if(!s->budget--) { s->failed_pc=0x0c0ca276u; return 0; }
target=r[3];
r[16]=code_base|0x0c0ca27au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ca27au) { target=s->pc; goto dispatch; }
goto P_0c0ca27a;
P_0c0ca278: /* original 0009, guest PC 0x0c0ca278 */
if(!s->budget--) { s->failed_pc=0x0c0ca278u; return 0; }
goto P_0c0ca27a;
P_0c0ca27a: /* original 7f04, guest PC 0x0c0ca27a */
if(!s->budget--) { s->failed_pc=0x0c0ca27au; return 0; }
r[15]+=0x00000004u;
goto P_0c0ca27c;
P_0c0ca27c: /* original 4f26, guest PC 0x0c0ca27c */
if(!s->budget--) { s->failed_pc=0x0c0ca27cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ca27e;
P_0c0ca27e: /* original 000b, guest PC 0x0c0ca27e */
if(!s->budget--) { s->failed_pc=0x0c0ca27eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0ca280: /* original 0009, guest PC 0x0c0ca280 */
if(!s->budget--) { s->failed_pc=0x0c0ca280u; return 0; }
if(!vf3_matrix_family(0x0c0ca282u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ca282u; return 0; } return 1;
P_0c0ca322: /* original 000b, guest PC 0x0c0ca322 */
if(!s->budget--) { s->failed_pc=0x0c0ca322u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0ca324: /* original 0009, guest PC 0x0c0ca324 */
if(!s->budget--) { s->failed_pc=0x0c0ca324u; return 0; }
if(!vf3_matrix_family(0x0c0ca326u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ca326u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
