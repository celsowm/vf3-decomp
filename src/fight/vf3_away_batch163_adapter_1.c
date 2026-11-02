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
int vf3_away_batch163_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0396c0u: goto P_0c0396c0;
case 0x0c0396c2u: goto P_0c0396c2;
case 0x0c0396c4u: goto P_0c0396c4;
case 0x0c0396c6u: goto P_0c0396c6;
case 0x0c0396c8u: goto P_0c0396c8;
case 0x0c0396cau: goto P_0c0396ca;
case 0x0c0396ccu: goto P_0c0396cc;
case 0x0c0396ceu: goto P_0c0396ce;
case 0x0c0396d0u: goto P_0c0396d0;
case 0x0c0396d2u: goto P_0c0396d2;
case 0x0c0396d4u: goto P_0c0396d4;
case 0x0c0396d6u: goto P_0c0396d6;
case 0x0c0396d8u: goto P_0c0396d8;
case 0x0c0396dau: goto P_0c0396da;
case 0x0c0396dcu: goto P_0c0396dc;
case 0x0c0396deu: goto P_0c0396de;
case 0x0c0396e0u: goto P_0c0396e0;
case 0x0c0396e2u: goto P_0c0396e2;
case 0x0c0396e4u: goto P_0c0396e4;
case 0x0c0396e6u: goto P_0c0396e6;
case 0x0c0396e8u: goto P_0c0396e8;
case 0x0c0396eau: goto P_0c0396ea;
case 0x0c0396f0u: goto P_0c0396f0;
case 0x0c0396f2u: goto P_0c0396f2;
case 0x0c039700u: goto P_0c039700;
case 0x0c039702u: goto P_0c039702;
case 0x0c039704u: goto P_0c039704;
case 0x0c039706u: goto P_0c039706;
case 0x0c039708u: goto P_0c039708;
case 0x0c03970au: goto P_0c03970a;
case 0x0c03970cu: goto P_0c03970c;
case 0x0c03970eu: goto P_0c03970e;
case 0x0c039710u: goto P_0c039710;
case 0x0c039712u: goto P_0c039712;
case 0x0c039714u: goto P_0c039714;
case 0x0c039716u: goto P_0c039716;
case 0x0c039718u: goto P_0c039718;
case 0x0c03971au: goto P_0c03971a;
case 0x0c03971cu: goto P_0c03971c;
case 0x0c03971eu: goto P_0c03971e;
case 0x0c039720u: goto P_0c039720;
case 0x0c039722u: goto P_0c039722;
case 0x0c039724u: goto P_0c039724;
case 0x0c039726u: goto P_0c039726;
case 0x0c039728u: goto P_0c039728;
case 0x0c03972au: goto P_0c03972a;
case 0x0c03972cu: goto P_0c03972c;
case 0x0c03972eu: goto P_0c03972e;
case 0x0c039730u: goto P_0c039730;
case 0x0c039fd0u: goto P_0c039fd0;
case 0x0c039fd2u: goto P_0c039fd2;
case 0x0c039fd4u: goto P_0c039fd4;
case 0x0c039fd6u: goto P_0c039fd6;
case 0x0c039fd8u: goto P_0c039fd8;
case 0x0c039fdau: goto P_0c039fda;
case 0x0c039fdcu: goto P_0c039fdc;
case 0x0c039fdeu: goto P_0c039fde;
case 0x0c039fe0u: goto P_0c039fe0;
case 0x0c039fe2u: goto P_0c039fe2;
case 0x0c039fe4u: goto P_0c039fe4;
case 0x0c039fe6u: goto P_0c039fe6;
case 0x0c039fe8u: goto P_0c039fe8;
case 0x0c039feau: goto P_0c039fea;
case 0x0c039fecu: goto P_0c039fec;
case 0x0c039feeu: goto P_0c039fee;
case 0x0c039ff0u: goto P_0c039ff0;
case 0x0c039ff2u: goto P_0c039ff2;
case 0x0c039ff4u: goto P_0c039ff4;
case 0x0c039ff6u: goto P_0c039ff6;
case 0x0c039ff8u: goto P_0c039ff8;
case 0x0c039ffau: goto P_0c039ffa;
case 0x0c039ffcu: goto P_0c039ffc;
case 0x0c039ffeu: goto P_0c039ffe;
case 0x0c03a000u: goto P_0c03a000;
case 0x0c03a002u: goto P_0c03a002;
case 0x0c03a004u: goto P_0c03a004;
case 0x0c03a006u: goto P_0c03a006;
case 0x0c03a008u: goto P_0c03a008;
case 0x0c03a00au: goto P_0c03a00a;
case 0x0c03a00cu: goto P_0c03a00c;
case 0x0c03a00eu: goto P_0c03a00e;
case 0x0c03a010u: goto P_0c03a010;
case 0x0c03a012u: goto P_0c03a012;
case 0x0c03a014u: goto P_0c03a014;
case 0x0c03a016u: goto P_0c03a016;
case 0x0c03a018u: goto P_0c03a018;
case 0x0c03a01au: goto P_0c03a01a;
case 0x0c03a01cu: goto P_0c03a01c;
case 0x0c03a01eu: goto P_0c03a01e;
case 0x0c03a020u: goto P_0c03a020;
case 0x0c03a022u: goto P_0c03a022;
case 0x0c03a024u: goto P_0c03a024;
case 0x0c03a026u: goto P_0c03a026;
case 0x0c03a028u: goto P_0c03a028;
case 0x0c03a02au: goto P_0c03a02a;
case 0x0c03a02cu: goto P_0c03a02c;
case 0x0c03a02eu: goto P_0c03a02e;
case 0x0c03a030u: goto P_0c03a030;
case 0x0c03a032u: goto P_0c03a032;
case 0x0c03a034u: goto P_0c03a034;
case 0x0c03a040u: goto P_0c03a040;
case 0x0c03a042u: goto P_0c03a042;
case 0x0c03a044u: goto P_0c03a044;
case 0x0c03a046u: goto P_0c03a046;
case 0x0c03a048u: goto P_0c03a048;
case 0x0c03a04au: goto P_0c03a04a;
case 0x0c03a04cu: goto P_0c03a04c;
case 0x0c03a04eu: goto P_0c03a04e;
case 0x0c03a050u: goto P_0c03a050;
case 0x0c03a052u: goto P_0c03a052;
case 0x0c03a054u: goto P_0c03a054;
case 0x0c03b300u: goto P_0c03b300;
case 0x0c03b302u: goto P_0c03b302;
case 0x0c03b304u: goto P_0c03b304;
case 0x0c03b306u: goto P_0c03b306;
case 0x0c03b308u: goto P_0c03b308;
case 0x0c03b30au: goto P_0c03b30a;
case 0x0c03b30cu: goto P_0c03b30c;
case 0x0c03b30eu: goto P_0c03b30e;
case 0x0c03b310u: goto P_0c03b310;
case 0x0c03b312u: goto P_0c03b312;
case 0x0c03b314u: goto P_0c03b314;
case 0x0c03b316u: goto P_0c03b316;
case 0x0c03b318u: goto P_0c03b318;
case 0x0c03b31au: goto P_0c03b31a;
case 0x0c03b31cu: goto P_0c03b31c;
case 0x0c03b31eu: goto P_0c03b31e;
case 0x0c03b320u: goto P_0c03b320;
case 0x0c03b322u: goto P_0c03b322;
case 0x0c03b324u: goto P_0c03b324;
case 0x0c03b326u: goto P_0c03b326;
case 0x0c03b328u: goto P_0c03b328;
case 0x0c03b32au: goto P_0c03b32a;
case 0x0c03b32cu: goto P_0c03b32c;
case 0x0c03b32eu: goto P_0c03b32e;
case 0x0c03b330u: goto P_0c03b330;
case 0x0c03b332u: goto P_0c03b332;
case 0x0c03b334u: goto P_0c03b334;
case 0x0c03b336u: goto P_0c03b336;
case 0x0c03b338u: goto P_0c03b338;
case 0x0c03c1c0u: goto P_0c03c1c0;
case 0x0c03c1c2u: goto P_0c03c1c2;
case 0x0c03c1c4u: goto P_0c03c1c4;
case 0x0c03c1c6u: goto P_0c03c1c6;
case 0x0c03c1c8u: goto P_0c03c1c8;
case 0x0c03c1cau: goto P_0c03c1ca;
case 0x0c03c1ccu: goto P_0c03c1cc;
case 0x0c03c1ceu: goto P_0c03c1ce;
case 0x0c03c1d0u: goto P_0c03c1d0;
case 0x0c03c1d2u: goto P_0c03c1d2;
case 0x0c03c1d4u: goto P_0c03c1d4;
case 0x0c03c1d6u: goto P_0c03c1d6;
case 0x0c03c1d8u: goto P_0c03c1d8;
case 0x0c03c1dau: goto P_0c03c1da;
case 0x0c03c1dcu: goto P_0c03c1dc;
case 0x0c03c1deu: goto P_0c03c1de;
case 0x0c03c1e0u: goto P_0c03c1e0;
case 0x0c03c1e2u: goto P_0c03c1e2;
case 0x0c03c1e4u: goto P_0c03c1e4;
case 0x0c03c1e6u: goto P_0c03c1e6;
case 0x0c03c1e8u: goto P_0c03c1e8;
case 0x0c03c1eau: goto P_0c03c1ea;
case 0x0c03c1ecu: goto P_0c03c1ec;
case 0x0c03c1eeu: goto P_0c03c1ee;
case 0x0c03c1f0u: goto P_0c03c1f0;
case 0x0c03c1f2u: goto P_0c03c1f2;
case 0x0c03c1f4u: goto P_0c03c1f4;
case 0x0c03c1f6u: goto P_0c03c1f6;
case 0x0c03c1f8u: goto P_0c03c1f8;
case 0x0c03c1fau: goto P_0c03c1fa;
case 0x0c03c1fcu: goto P_0c03c1fc;
case 0x0c03c1feu: goto P_0c03c1fe;
case 0x0c03c200u: goto P_0c03c200;
case 0x0c03c202u: goto P_0c03c202;
case 0x0c03c204u: goto P_0c03c204;
case 0x0c03c206u: goto P_0c03c206;
case 0x0c03c208u: goto P_0c03c208;
case 0x0c03d040u: goto P_0c03d040;
case 0x0c03d042u: goto P_0c03d042;
case 0x0c03d044u: goto P_0c03d044;
case 0x0c03d046u: goto P_0c03d046;
case 0x0c03d048u: goto P_0c03d048;
case 0x0c03d060u: goto P_0c03d060;
case 0x0c03d062u: goto P_0c03d062;
case 0x0c03d064u: goto P_0c03d064;
case 0x0c03d066u: goto P_0c03d066;
case 0x0c03d068u: goto P_0c03d068;
case 0x0c03d06au: goto P_0c03d06a;
case 0x0c03d06cu: goto P_0c03d06c;
case 0x0c03d06eu: goto P_0c03d06e;
case 0x0c03d070u: goto P_0c03d070;
case 0x0c03d072u: goto P_0c03d072;
case 0x0c03d074u: goto P_0c03d074;
case 0x0c03d076u: goto P_0c03d076;
case 0x0c03d078u: goto P_0c03d078;
case 0x0c03d07au: goto P_0c03d07a;
case 0x0c03d07cu: goto P_0c03d07c;
case 0x0c03d07eu: goto P_0c03d07e;
case 0x0c03d080u: goto P_0c03d080;
case 0x0c03d082u: goto P_0c03d082;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0396c0: /* original 2fd6, guest PC 0x0c0396c0 */
if(!s->budget--) { s->failed_pc=0x0c0396c0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0396c2;
P_0c0396c2: /* original 4408, guest PC 0x0c0396c2 */
if(!s->budget--) { s->failed_pc=0x0c0396c2u; return 0; }
r[4]<<=2;
goto P_0c0396c4;
P_0c0396c4: /* original 7ffc, guest PC 0x0c0396c4 */
if(!s->budget--) { s->failed_pc=0x0c0396c4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0396c6;
P_0c0396c6: /* original 2f42, guest PC 0x0c0396c6 */
if(!s->budget--) { s->failed_pc=0x0c0396c6u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0396c8;
P_0c0396c8: /* original d35e, guest PC 0x0c0396c8 */
if(!s->budget--) { s->failed_pc=0x0c0396c8u; return 0; }
r[3]=read(ram,0x0c039844u,4);
goto P_0c0396ca;
P_0c0396ca: /* original d15f, guest PC 0x0c0396ca */
if(!s->budget--) { s->failed_pc=0x0c0396cau; return 0; }
r[1]=read(ram,0x0c039848u,4);
goto P_0c0396cc;
P_0c0396cc: /* original 6032, guest PC 0x0c0396cc */
if(!s->budget--) { s->failed_pc=0x0c0396ccu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0396ce;
P_0c0396ce: /* original 044e, guest PC 0x0c0396ce */
if(!s->budget--) { s->failed_pc=0x0c0396ceu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c0396d0;
P_0c0396d0: /* original 6243, guest PC 0x0c0396d0 */
if(!s->budget--) { s->failed_pc=0x0c0396d0u; return 0; }
r[2]=r[4];
goto P_0c0396d2;
P_0c0396d2: /* original 4229, guest PC 0x0c0396d2 */
if(!s->budget--) { s->failed_pc=0x0c0396d2u; return 0; }
r[2]>>=16;
goto P_0c0396d4;
P_0c0396d4: /* original 4219, guest PC 0x0c0396d4 */
if(!s->budget--) { s->failed_pc=0x0c0396d4u; return 0; }
r[2]>>=8;
goto P_0c0396d6;
P_0c0396d6: /* original 2122, guest PC 0x0c0396d6 */
if(!s->budget--) { s->failed_pc=0x0c0396d6u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c0396d8;
P_0c0396d8: /* original e100, guest PC 0x0c0396d8 */
if(!s->budget--) { s->failed_pc=0x0c0396d8u; return 0; }
r[1]=0x00000000u;
goto P_0c0396da;
P_0c0396da: /* original d35c, guest PC 0x0c0396da */
if(!s->budget--) { s->failed_pc=0x0c0396dau; return 0; }
r[3]=read(ram,0x0c03984cu,4);
goto P_0c0396dc;
P_0c0396dc: /* original 2322, guest PC 0x0c0396dc */
if(!s->budget--) { s->failed_pc=0x0c0396dcu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0396de;
P_0c0396de: /* original d75c, guest PC 0x0c0396de */
if(!s->budget--) { s->failed_pc=0x0c0396deu; return 0; }
r[7]=read(ram,0x0c039850u,4);
goto P_0c0396e0;
P_0c0396e0: /* original d25c, guest PC 0x0c0396e0 */
if(!s->budget--) { s->failed_pc=0x0c0396e0u; return 0; }
r[2]=read(ram,0x0c039854u,4);
goto P_0c0396e2;
P_0c0396e2: /* original 2749, guest PC 0x0c0396e2 */
if(!s->budget--) { s->failed_pc=0x0c0396e2u; return 0; }
r[7]&=r[4];
goto P_0c0396e4;
P_0c0396e4: /* original 272b, guest PC 0x0c0396e4 */
if(!s->budget--) { s->failed_pc=0x0c0396e4u; return 0; }
r[7]|=r[2];
goto P_0c0396e6;
P_0c0396e6: /* original 6d73, guest PC 0x0c0396e6 */
if(!s->budget--) { s->failed_pc=0x0c0396e6u; return 0; }
r[13]=r[7];
goto P_0c0396e8;
P_0c0396e8: /* original a013, guest PC 0x0c0396e8 */
if(!s->budget--) { s->failed_pc=0x0c0396e8u; return 0; }
r[0]=0x00000008u;
goto P_0c039712;
P_0c0396ea: /* original e008, guest PC 0x0c0396ea */
if(!s->budget--) { s->failed_pc=0x0c0396eau; return 0; }
r[0]=0x00000008u;
if(!vf3_matrix_family(0x0c0396ecu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0396ecu; return 0; } return 1;
P_0c0396f0: /* original a00a, guest PC 0x0c0396f0 */
if(!s->budget--) { s->failed_pc=0x0c0396f0u; return 0; }
r[4]=r[0];
goto P_0c039708;
P_0c0396f2: /* original 6403, guest PC 0x0c0396f2 */
if(!s->budget--) { s->failed_pc=0x0c0396f2u; return 0; }
r[4]=r[0];
if(!vf3_matrix_family(0x0c0396f4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0396f4u; return 0; } return 1;
P_0c039700: /* original 6256, guest PC 0x0c039700 */
if(!s->budget--) { s->failed_pc=0x0c039700u; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[2]=tmp;
goto P_0c039702;
P_0c039702: /* original 74ff, guest PC 0x0c039702 */
if(!s->budget--) { s->failed_pc=0x0c039702u; return 0; }
r[4]+=0xffffffffu;
goto P_0c039704;
P_0c039704: /* original 2d22, guest PC 0x0c039704 */
if(!s->budget--) { s->failed_pc=0x0c039704u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c039706;
P_0c039706: /* original 7d04, guest PC 0x0c039706 */
if(!s->budget--) { s->failed_pc=0x0c039706u; return 0; }
r[13]+=0x00000004u;
goto P_0c039708;
P_0c039708: /* original 2448, guest PC 0x0c039708 */
if(!s->budget--) { s->failed_pc=0x0c039708u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03970a;
P_0c03970a: /* original 8bf9, guest PC 0x0c03970a */
if(!s->budget--) { s->failed_pc=0x0c03970au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c039700; }
goto P_0c03970c;
P_0c03970c: /* original 0783, guest PC 0x0c03970c */
if(!s->budget--) { s->failed_pc=0x0c03970cu; return 0; }
if((r[7]&0xFC000000u)==0xE0000000u) pref(ram,r[7]);
goto P_0c03970e;
P_0c03970e: /* original 7101, guest PC 0x0c03970e */
if(!s->budget--) { s->failed_pc=0x0c03970eu; return 0; }
r[1]+=0x00000001u;
goto P_0c039710;
P_0c039710: /* original 7720, guest PC 0x0c039710 */
if(!s->budget--) { s->failed_pc=0x0c039710u; return 0; }
r[7]+=0x00000020u;
goto P_0c039712;
P_0c039712: /* original 3163, guest PC 0x0c039712 */
if(!s->budget--) { s->failed_pc=0x0c039712u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[6])!=0);
goto P_0c039714;
P_0c039714: /* original 8bec, guest PC 0x0c039714 */
if(!s->budget--) { s->failed_pc=0x0c039714u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0396f0; }
goto P_0c039716;
P_0c039716: /* original d24b, guest PC 0x0c039716 */
if(!s->budget--) { s->failed_pc=0x0c039716u; return 0; }
r[2]=read(ram,0x0c039844u,4);
goto P_0c039718;
P_0c039718: /* original 64f2, guest PC 0x0c039718 */
if(!s->budget--) { s->failed_pc=0x0c039718u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c03971a;
P_0c03971a: /* original 7f04, guest PC 0x0c03971a */
if(!s->budget--) { s->failed_pc=0x0c03971au; return 0; }
r[15]+=0x00000004u;
goto P_0c03971c;
P_0c03971c: /* original 6322, guest PC 0x0c03971c */
if(!s->budget--) { s->failed_pc=0x0c03971cu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03971e;
P_0c03971e: /* original d14e, guest PC 0x0c03971e */
if(!s->budget--) { s->failed_pc=0x0c03971eu; return 0; }
r[1]=read(ram,0x0c039858u,4);
goto P_0c039720;
P_0c039720: /* original 343c, guest PC 0x0c039720 */
if(!s->budget--) { s->failed_pc=0x0c039720u; return 0; }
r[4]+=r[3];
goto P_0c039722;
P_0c039722: /* original d34b, guest PC 0x0c039722 */
if(!s->budget--) { s->failed_pc=0x0c039722u; return 0; }
r[3]=read(ram,0x0c039850u,4);
goto P_0c039724;
P_0c039724: /* original 6042, guest PC 0x0c039724 */
if(!s->budget--) { s->failed_pc=0x0c039724u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c039726;
P_0c039726: /* original 2739, guest PC 0x0c039726 */
if(!s->budget--) { s->failed_pc=0x0c039726u; return 0; }
r[7]&=r[3];
goto P_0c039728;
P_0c039728: /* original 2019, guest PC 0x0c039728 */
if(!s->budget--) { s->failed_pc=0x0c039728u; return 0; }
r[0]&=r[1];
goto P_0c03972a;
P_0c03972a: /* original 207b, guest PC 0x0c03972a */
if(!s->budget--) { s->failed_pc=0x0c03972au; return 0; }
r[0]|=r[7];
goto P_0c03972c;
P_0c03972c: /* original 2402, guest PC 0x0c03972c */
if(!s->budget--) { s->failed_pc=0x0c03972cu; return 0; }
write(ram,r[4],r[0],4);
goto P_0c03972e;
P_0c03972e: /* original 000b, guest PC 0x0c03972e */
if(!s->budget--) { s->failed_pc=0x0c03972eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c039730: /* original 6df6, guest PC 0x0c039730 */
if(!s->budget--) { s->failed_pc=0x0c039730u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
if(!vf3_matrix_family(0x0c039732u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c039732u; return 0; } return 1;
P_0c039fd0: /* original f34c, guest PC 0x0c039fd0 */
if(!s->budget--) { s->failed_pc=0x0c039fd0u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c039fd2;
P_0c039fd2: /* original f35d, guest PC 0x0c039fd2 */
if(!s->budget--) { s->failed_pc=0x0c039fd2u; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c039fd4;
P_0c039fd4: /* original f69d, guest PC 0x0c039fd4 */
if(!s->budget--) { s->failed_pc=0x0c039fd4u; return 0; }
fr[6]=0x3f800000u;
goto P_0c039fd6;
P_0c039fd6: /* original f365, guest PC 0x0c039fd6 */
if(!s->budget--) { s->failed_pc=0x0c039fd6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c039fd8;
P_0c039fd8: /* original 8d02, guest PC 0x0c039fd8 */
if(!s->budget--) { s->failed_pc=0x0c039fd8u; return 0; }
cond=r[17]&1u;
fr[7]=0;
if(cond) { goto P_0c039fe0; }
goto P_0c039fdc;
P_0c039fda: /* original f78d, guest PC 0x0c039fda */
if(!s->budget--) { s->failed_pc=0x0c039fdau; return 0; }
fr[7]=0;
goto P_0c039fdc;
P_0c039fdc: /* original a002, guest PC 0x0c039fdc */
if(!s->budget--) { s->failed_pc=0x0c039fdcu; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c039fe4;
P_0c039fde: /* original f54c, guest PC 0x0c039fde */
if(!s->budget--) { s->failed_pc=0x0c039fdeu; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c039fe0;
P_0c039fe0: /* original f56c, guest PC 0x0c039fe0 */
if(!s->budget--) { s->failed_pc=0x0c039fe0u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c039fe2;
P_0c039fe2: /* original f543, guest PC 0x0c039fe2 */
if(!s->budget--) { s->failed_pc=0x0c039fe2u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'/');
goto P_0c039fe4;
P_0c039fe4: /* original e40d, guest PC 0x0c039fe4 */
if(!s->budget--) { s->failed_pc=0x0c039fe4u; return 0; }
r[4]=0x0000000du;
goto P_0c039fe6;
P_0c039fe6: /* original e501, guest PC 0x0c039fe6 */
if(!s->budget--) { s->failed_pc=0x0c039fe6u; return 0; }
r[5]=0x00000001u;
goto P_0c039fe8;
P_0c039fe8: /* original 445a, guest PC 0x0c039fe8 */
if(!s->budget--) { s->failed_pc=0x0c039fe8u; return 0; }
r[53]=r[4];
goto P_0c039fea;
P_0c039fea: /* original 6343, guest PC 0x0c039fea */
if(!s->budget--) { s->failed_pc=0x0c039feau; return 0; }
r[3]=r[4];
goto P_0c039fec;
P_0c039fec: /* original 4300, guest PC 0x0c039fec */
if(!s->budget--) { s->failed_pc=0x0c039fecu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c039fee;
P_0c039fee: /* original 74ff, guest PC 0x0c039fee */
if(!s->budget--) { s->failed_pc=0x0c039feeu; return 0; }
r[4]+=0xffffffffu;
goto P_0c039ff0;
P_0c039ff0: /* original f32d, guest PC 0x0c039ff0 */
if(!s->budget--) { s->failed_pc=0x0c039ff0u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c039ff2;
P_0c039ff2: /* original 435a, guest PC 0x0c039ff2 */
if(!s->budget--) { s->failed_pc=0x0c039ff2u; return 0; }
r[53]=r[3];
goto P_0c039ff4;
P_0c039ff4: /* original 3453, guest PC 0x0c039ff4 */
if(!s->budget--) { s->failed_pc=0x0c039ff4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c039ff6;
P_0c039ff6: /* original f22d, guest PC 0x0c039ff6 */
if(!s->budget--) { s->failed_pc=0x0c039ff6u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c039ff8;
P_0c039ff8: /* original f83c, guest PC 0x0c039ff8 */
if(!s->budget--) { s->failed_pc=0x0c039ff8u; return 0; }
vf3_matrix_move(s,8,3);
goto P_0c039ffa;
P_0c039ffa: /* original f382, guest PC 0x0c039ffa */
if(!s->budget--) { s->failed_pc=0x0c039ffau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c039ffc;
P_0c039ffc: /* original f270, guest PC 0x0c039ffc */
if(!s->budget--) { s->failed_pc=0x0c039ffcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'+');
goto P_0c039ffe;
P_0c039ffe: /* original f352, guest PC 0x0c039ffe */
if(!s->budget--) { s->failed_pc=0x0c039ffeu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03a000;
P_0c03a000: /* original f260, guest PC 0x0c03a000 */
if(!s->budget--) { s->failed_pc=0x0c03a000u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'+');
goto P_0c03a002;
P_0c03a002: /* original f352, guest PC 0x0c03a002 */
if(!s->budget--) { s->failed_pc=0x0c03a002u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03a004;
P_0c03a004: /* original f73c, guest PC 0x0c03a004 */
if(!s->budget--) { s->failed_pc=0x0c03a004u; return 0; }
vf3_matrix_move(s,7,3);
goto P_0c03a006;
P_0c03a006: /* original 8def, guest PC 0x0c03a006 */
if(!s->budget--) { s->failed_pc=0x0c03a006u; return 0; }
cond=r[17]&1u;
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'/');
if(cond) { goto P_0c039fe8; }
goto P_0c03a00a;
P_0c03a008: /* original f723, guest PC 0x0c03a008 */
if(!s->budget--) { s->failed_pc=0x0c03a008u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'/');
goto P_0c03a00a;
P_0c03a00a: /* original f760, guest PC 0x0c03a00a */
if(!s->budget--) { s->failed_pc=0x0c03a00au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'+');
goto P_0c03a00c;
P_0c03a00c: /* original c713, guest PC 0x0c03a00c */
if(!s->budget--) { s->failed_pc=0x0c03a00cu; return 0; }
r[0]=code_base|0x0003a05cu;
goto P_0c03a00e;
P_0c03a00e: /* original f465, guest PC 0x0c03a00e */
if(!s->budget--) { s->failed_pc=0x0c03a00eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c03a010;
P_0c03a010: /* original d315, guest PC 0x0c03a010 */
if(!s->budget--) { s->failed_pc=0x0c03a010u; return 0; }
r[3]=read(ram,0x0c03a068u,4);
goto P_0c03a012;
P_0c03a012: /* original f573, guest PC 0x0c03a012 */
if(!s->budget--) { s->failed_pc=0x0c03a012u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'/');
goto P_0c03a014;
P_0c03a014: /* original f708, guest PC 0x0c03a014 */
if(!s->budget--) { s->failed_pc=0x0c03a014u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c03a016;
P_0c03a016: /* original c712, guest PC 0x0c03a016 */
if(!s->budget--) { s->failed_pc=0x0c03a016u; return 0; }
r[0]=code_base|0x0003a060u;
goto P_0c03a018;
P_0c03a018: /* original f208, guest PC 0x0c03a018 */
if(!s->budget--) { s->failed_pc=0x0c03a018u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03a01a;
P_0c03a01a: /* original c712, guest PC 0x0c03a01a */
if(!s->budget--) { s->failed_pc=0x0c03a01au; return 0; }
r[0]=code_base|0x0003a064u;
goto P_0c03a01c;
P_0c03a01c: /* original f108, guest PC 0x0c03a01c */
if(!s->budget--) { s->failed_pc=0x0c03a01cu; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c03a01e;
P_0c03a01e: /* original f35c, guest PC 0x0c03a01e */
if(!s->budget--) { s->failed_pc=0x0c03a01eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c03a020;
P_0c03a020: /* original f370, guest PC 0x0c03a020 */
if(!s->budget--) { s->failed_pc=0x0c03a020u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'+');
goto P_0c03a022;
P_0c03a022: /* original f322, guest PC 0x0c03a022 */
if(!s->budget--) { s->failed_pc=0x0c03a022u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c03a024;
P_0c03a024: /* original f373, guest PC 0x0c03a024 */
if(!s->budget--) { s->failed_pc=0x0c03a024u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'/');
goto P_0c03a026;
P_0c03a026: /* original f310, guest PC 0x0c03a026 */
if(!s->budget--) { s->failed_pc=0x0c03a026u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'+');
goto P_0c03a028;
P_0c03a028: /* original f33d, guest PC 0x0c03a028 */
if(!s->budget--) { s->failed_pc=0x0c03a028u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03a02a;
P_0c03a02a: /* original 045a, guest PC 0x0c03a02a */
if(!s->budget--) { s->failed_pc=0x0c03a02au; return 0; }
r[4]=r[53];
goto P_0c03a02c;
P_0c03a02c: /* original 8f08, guest PC 0x0c03a02c */
if(!s->budget--) { s->failed_pc=0x0c03a02cu; return 0; }
cond=r[17]&1u;
r[4]&=r[3];
if(!cond) { goto P_0c03a040; }
goto P_0c03a030;
P_0c03a02e: /* original 2439, guest PC 0x0c03a02e */
if(!s->budget--) { s->failed_pc=0x0c03a02eu; return 0; }
r[4]&=r[3];
goto P_0c03a030;
P_0c03a030: /* original 9011, guest PC 0x0c03a030 */
if(!s->budget--) { s->failed_pc=0x0c03a030u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03a056u,2);
goto P_0c03a032;
P_0c03a032: /* original a00a, guest PC 0x0c03a032 */
if(!s->budget--) { s->failed_pc=0x0c03a032u; return 0; }
goto P_0c03a04a;
P_0c03a034: /* original 0009, guest PC 0x0c03a034 */
if(!s->budget--) { s->failed_pc=0x0c03a034u; return 0; }
if(!vf3_matrix_family(0x0c03a036u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a036u; return 0; } return 1;
P_0c03a040: /* original c70a, guest PC 0x0c03a040 */
if(!s->budget--) { s->failed_pc=0x0c03a040u; return 0; }
r[0]=code_base|0x0003a06cu;
goto P_0c03a042;
P_0c03a042: /* original f308, guest PC 0x0c03a042 */
if(!s->budget--) { s->failed_pc=0x0c03a042u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03a044;
P_0c03a044: /* original f345, guest PC 0x0c03a044 */
if(!s->budget--) { s->failed_pc=0x0c03a044u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c03a046;
P_0c03a046: /* original 8b03, guest PC 0x0c03a046 */
if(!s->budget--) { s->failed_pc=0x0c03a046u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a050; }
goto P_0c03a048;
P_0c03a048: /* original d003, guest PC 0x0c03a048 */
if(!s->budget--) { s->failed_pc=0x0c03a048u; return 0; }
r[0]=read(ram,0x0c03a058u,4);
goto P_0c03a04a;
P_0c03a04a: /* original 3048, guest PC 0x0c03a04a */
if(!s->budget--) { s->failed_pc=0x0c03a04au; return 0; }
r[0]-=r[4];
goto P_0c03a04c;
P_0c03a04c: /* original 000b, guest PC 0x0c03a04c */
if(!s->budget--) { s->failed_pc=0x0c03a04cu; return 0; }
target=r[16];
r[0]=r[0]&65535u;
s->pc=target; return ram->oob==0;
P_0c03a04e: /* original 600d, guest PC 0x0c03a04e */
if(!s->budget--) { s->failed_pc=0x0c03a04eu; return 0; }
r[0]=r[0]&65535u;
goto P_0c03a050;
P_0c03a050: /* original 6043, guest PC 0x0c03a050 */
if(!s->budget--) { s->failed_pc=0x0c03a050u; return 0; }
r[0]=r[4];
goto P_0c03a052;
P_0c03a052: /* original 000b, guest PC 0x0c03a052 */
if(!s->budget--) { s->failed_pc=0x0c03a052u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03a054: /* original 0009, guest PC 0x0c03a054 */
if(!s->budget--) { s->failed_pc=0x0c03a054u; return 0; }
if(!vf3_matrix_family(0x0c03a056u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a056u; return 0; } return 1;
P_0c03b300: /* original 2fe6, guest PC 0x0c03b300 */
if(!s->budget--) { s->failed_pc=0x0c03b300u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03b302;
P_0c03b302: /* original 6743, guest PC 0x0c03b302 */
if(!s->budget--) { s->failed_pc=0x0c03b302u; return 0; }
r[7]=r[4];
goto P_0c03b304;
P_0c03b304: /* original 4f22, guest PC 0x0c03b304 */
if(!s->budget--) { s->failed_pc=0x0c03b304u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03b306;
P_0c03b306: /* original 4729, guest PC 0x0c03b306 */
if(!s->budget--) { s->failed_pc=0x0c03b306u; return 0; }
r[7]>>=16;
goto P_0c03b308;
P_0c03b308: /* original 6543, guest PC 0x0c03b308 */
if(!s->budget--) { s->failed_pc=0x0c03b308u; return 0; }
r[5]=r[4];
goto P_0c03b30a;
P_0c03b30a: /* original 4719, guest PC 0x0c03b30a */
if(!s->budget--) { s->failed_pc=0x0c03b30au; return 0; }
r[7]>>=8;
goto P_0c03b30c;
P_0c03b30c: /* original 6643, guest PC 0x0c03b30c */
if(!s->budget--) { s->failed_pc=0x0c03b30cu; return 0; }
r[6]=r[4];
goto P_0c03b30e;
P_0c03b30e: /* original 677e, guest PC 0x0c03b30e */
if(!s->budget--) { s->failed_pc=0x0c03b30eu; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)r[7];
goto P_0c03b310;
P_0c03b310: /* original 7ffc, guest PC 0x0c03b310 */
if(!s->budget--) { s->failed_pc=0x0c03b310u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03b312;
P_0c03b312: /* original 6073, guest PC 0x0c03b312 */
if(!s->budget--) { s->failed_pc=0x0c03b312u; return 0; }
r[0]=r[7];
goto P_0c03b314;
P_0c03b314: /* original 6ef3, guest PC 0x0c03b314 */
if(!s->budget--) { s->failed_pc=0x0c03b314u; return 0; }
r[14]=r[15];
goto P_0c03b316;
P_0c03b316: /* original 4529, guest PC 0x0c03b316 */
if(!s->budget--) { s->failed_pc=0x0c03b316u; return 0; }
r[5]>>=16;
goto P_0c03b318;
P_0c03b318: /* original 80e3, guest PC 0x0c03b318 */
if(!s->budget--) { s->failed_pc=0x0c03b318u; return 0; }
write(ram,r[14]+3,r[0],1);
goto P_0c03b31a;
P_0c03b31a: /* original 655f, guest PC 0x0c03b31a */
if(!s->budget--) { s->failed_pc=0x0c03b31au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c03b31c;
P_0c03b31c: /* original 6053, guest PC 0x0c03b31c */
if(!s->budget--) { s->failed_pc=0x0c03b31cu; return 0; }
r[0]=r[5];
goto P_0c03b31e;
P_0c03b31e: /* original e3f8, guest PC 0x0c03b31e */
if(!s->budget--) { s->failed_pc=0x0c03b31eu; return 0; }
r[3]=0xfffffff8u;
goto P_0c03b320;
P_0c03b320: /* original 80e2, guest PC 0x0c03b320 */
if(!s->budget--) { s->failed_pc=0x0c03b320u; return 0; }
write(ram,r[14]+2,r[0],1);
goto P_0c03b322;
P_0c03b322: /* original 463c, guest PC 0x0c03b322 */
if(!s->budget--) { s->failed_pc=0x0c03b322u; return 0; }
r[6]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[6]>>((-r[3])&31u)):((int32_t)r[6]<0?0xffffffffu:0)):r[6]<<(r[3]&31u);
goto P_0c03b324;
P_0c03b324: /* original 6063, guest PC 0x0c03b324 */
if(!s->budget--) { s->failed_pc=0x0c03b324u; return 0; }
r[0]=r[6];
goto P_0c03b326;
P_0c03b326: /* original 80e1, guest PC 0x0c03b326 */
if(!s->budget--) { s->failed_pc=0x0c03b326u; return 0; }
write(ram,r[14]+1,r[0],1);
goto P_0c03b328;
P_0c03b328: /* original 2e40, guest PC 0x0c03b328 */
if(!s->budget--) { s->failed_pc=0x0c03b328u; return 0; }
write(ram,r[14],r[4],1);
goto P_0c03b32a;
P_0c03b32a: /* original 63e2, guest PC 0x0c03b32a */
if(!s->budget--) { s->failed_pc=0x0c03b32au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03b32c;
P_0c03b32c: /* original d21e, guest PC 0x0c03b32c */
if(!s->budget--) { s->failed_pc=0x0c03b32cu; return 0; }
r[2]=read(ram,0x0c03b3a8u,4);
goto P_0c03b32e;
P_0c03b32e: /* original 420b, guest PC 0x0c03b32e */
if(!s->budget--) { s->failed_pc=0x0c03b32eu; return 0; }
target=r[2];
r[16]=code_base|0x0c03b332u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03b332u) { target=s->pc; goto dispatch; }
goto P_0c03b332;
P_0c03b330: /* original 2f36, guest PC 0x0c03b330 */
if(!s->budget--) { s->failed_pc=0x0c03b330u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03b332;
P_0c03b332: /* original 7f08, guest PC 0x0c03b332 */
if(!s->budget--) { s->failed_pc=0x0c03b332u; return 0; }
r[15]+=0x00000008u;
goto P_0c03b334;
P_0c03b334: /* original 4f26, guest PC 0x0c03b334 */
if(!s->budget--) { s->failed_pc=0x0c03b334u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03b336;
P_0c03b336: /* original 000b, guest PC 0x0c03b336 */
if(!s->budget--) { s->failed_pc=0x0c03b336u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03b338: /* original 6ef6, guest PC 0x0c03b338 */
if(!s->budget--) { s->failed_pc=0x0c03b338u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03b33au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03b33au; return 0; } return 1;
P_0c03c1c0: /* original fffb, guest PC 0x0c03c1c0 */
if(!s->budget--) { s->failed_pc=0x0c03c1c0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c03c1c2;
P_0c03c1c2: /* original ffeb, guest PC 0x0c03c1c2 */
if(!s->budget--) { s->failed_pc=0x0c03c1c2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c03c1c4;
P_0c03c1c4: /* original ffdb, guest PC 0x0c03c1c4 */
if(!s->budget--) { s->failed_pc=0x0c03c1c4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c03c1c6;
P_0c03c1c6: /* original ffcb, guest PC 0x0c03c1c6 */
if(!s->budget--) { s->failed_pc=0x0c03c1c6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c03c1c8;
P_0c03c1c8: /* original f049, guest PC 0x0c03c1c8 */
if(!s->budget--) { s->failed_pc=0x0c03c1c8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1ca;
P_0c03c1ca: /* original f149, guest PC 0x0c03c1ca */
if(!s->budget--) { s->failed_pc=0x0c03c1cau; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1cc;
P_0c03c1cc: /* original f249, guest PC 0x0c03c1cc */
if(!s->budget--) { s->failed_pc=0x0c03c1ccu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1ce;
P_0c03c1ce: /* original f349, guest PC 0x0c03c1ce */
if(!s->budget--) { s->failed_pc=0x0c03c1ceu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1d0;
P_0c03c1d0: /* original f449, guest PC 0x0c03c1d0 */
if(!s->budget--) { s->failed_pc=0x0c03c1d0u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1d2;
P_0c03c1d2: /* original f549, guest PC 0x0c03c1d2 */
if(!s->budget--) { s->failed_pc=0x0c03c1d2u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1d4;
P_0c03c1d4: /* original f649, guest PC 0x0c03c1d4 */
if(!s->budget--) { s->failed_pc=0x0c03c1d4u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1d6;
P_0c03c1d6: /* original f749, guest PC 0x0c03c1d6 */
if(!s->budget--) { s->failed_pc=0x0c03c1d6u; return 0; }
vf3_matrix_load(s,ram,7,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1d8;
P_0c03c1d8: /* original f849, guest PC 0x0c03c1d8 */
if(!s->budget--) { s->failed_pc=0x0c03c1d8u; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1da;
P_0c03c1da: /* original f949, guest PC 0x0c03c1da */
if(!s->budget--) { s->failed_pc=0x0c03c1dau; return 0; }
vf3_matrix_load(s,ram,9,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1dc;
P_0c03c1dc: /* original fa49, guest PC 0x0c03c1dc */
if(!s->budget--) { s->failed_pc=0x0c03c1dcu; return 0; }
vf3_matrix_load(s,ram,10,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1de;
P_0c03c1de: /* original fb49, guest PC 0x0c03c1de */
if(!s->budget--) { s->failed_pc=0x0c03c1deu; return 0; }
vf3_matrix_load(s,ram,11,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1e0;
P_0c03c1e0: /* original fc49, guest PC 0x0c03c1e0 */
if(!s->budget--) { s->failed_pc=0x0c03c1e0u; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1e2;
P_0c03c1e2: /* original fd49, guest PC 0x0c03c1e2 */
if(!s->budget--) { s->failed_pc=0x0c03c1e2u; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1e4;
P_0c03c1e4: /* original fe49, guest PC 0x0c03c1e4 */
if(!s->budget--) { s->failed_pc=0x0c03c1e4u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1e6;
P_0c03c1e6: /* original ff49, guest PC 0x0c03c1e6 */
if(!s->budget--) { s->failed_pc=0x0c03c1e6u; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1e8;
P_0c03c1e8: /* original fbfd, guest PC 0x0c03c1e8 */
if(!s->budget--) { s->failed_pc=0x0c03c1e8u; return 0; }
vf3_matrix_swap(s);
goto P_0c03c1ea;
P_0c03c1ea: /* original f1fd, guest PC 0x0c03c1ea */
if(!s->budget--) { s->failed_pc=0x0c03c1eau; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c03c1ec;
P_0c03c1ec: /* original f5fd, guest PC 0x0c03c1ec */
if(!s->budget--) { s->failed_pc=0x0c03c1ecu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c03c1ee;
P_0c03c1ee: /* original f9fd, guest PC 0x0c03c1ee */
if(!s->budget--) { s->failed_pc=0x0c03c1eeu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+8,r[18],fr+8)) goto unsupported;
goto P_0c03c1f0;
P_0c03c1f0: /* original fdfd, guest PC 0x0c03c1f0 */
if(!s->budget--) { s->failed_pc=0x0c03c1f0u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+12,r[18],fr+12)) goto unsupported;
goto P_0c03c1f2;
P_0c03c1f2: /* original fbfd, guest PC 0x0c03c1f2 */
if(!s->budget--) { s->failed_pc=0x0c03c1f2u; return 0; }
vf3_matrix_swap(s);
goto P_0c03c1f4;
P_0c03c1f4: /* original fcf9, guest PC 0x0c03c1f4 */
if(!s->budget--) { s->failed_pc=0x0c03c1f4u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1f6;
P_0c03c1f6: /* original fdf9, guest PC 0x0c03c1f6 */
if(!s->budget--) { s->failed_pc=0x0c03c1f6u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1f8;
P_0c03c1f8: /* original fef9, guest PC 0x0c03c1f8 */
if(!s->budget--) { s->failed_pc=0x0c03c1f8u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1fa;
P_0c03c1fa: /* original fff9, guest PC 0x0c03c1fa */
if(!s->budget--) { s->failed_pc=0x0c03c1fau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1fc;
P_0c03c1fc: /* original 000b, guest PC 0x0c03c1fc */
if(!s->budget--) { s->failed_pc=0x0c03c1fcu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03c1fe: /* original 0009, guest PC 0x0c03c1fe */
if(!s->budget--) { s->failed_pc=0x0c03c1feu; return 0; }
goto P_0c03c200;
P_0c03c200: /* original d491, guest PC 0x0c03c200 */
if(!s->budget--) { s->failed_pc=0x0c03c200u; return 0; }
r[4]=read(ram,0x0c03c448u,4);
goto P_0c03c202;
P_0c03c202: /* original d392, guest PC 0x0c03c202 */
if(!s->budget--) { s->failed_pc=0x0c03c202u; return 0; }
r[3]=read(ram,0x0c03c44cu,4);
goto P_0c03c204;
P_0c03c204: /* original 5442, guest PC 0x0c03c204 */
if(!s->budget--) { s->failed_pc=0x0c03c204u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c03c206;
P_0c03c206: /* original 432b, guest PC 0x0c03c206 */
if(!s->budget--) { s->failed_pc=0x0c03c206u; return 0; }
target=r[3];
r[4]+=0xffffffc0u;
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
P_0c03c208: /* original 74c0, guest PC 0x0c03c208 */
if(!s->budget--) { s->failed_pc=0x0c03c208u; return 0; }
r[4]+=0xffffffc0u;
if(!vf3_matrix_family(0x0c03c20au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03c20au; return 0; } return 1;
P_0c03d040: /* original 7ffc, guest PC 0x0c03d040 */
if(!s->budget--) { s->failed_pc=0x0c03d040u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03d042;
P_0c03d042: /* original 6543, guest PC 0x0c03d042 */
if(!s->budget--) { s->failed_pc=0x0c03d042u; return 0; }
r[5]=r[4];
goto P_0c03d044;
P_0c03d044: /* original 2f42, guest PC 0x0c03d044 */
if(!s->budget--) { s->failed_pc=0x0c03d044u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c03d046;
P_0c03d046: /* original a00b, guest PC 0x0c03d046 */
if(!s->budget--) { s->failed_pc=0x0c03d046u; return 0; }
goto P_0c03d060;
P_0c03d048: /* original 0009, guest PC 0x0c03d048 */
if(!s->budget--) { s->failed_pc=0x0c03d048u; return 0; }
if(!vf3_matrix_family(0x0c03d04au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03d04au; return 0; } return 1;
P_0c03d060: /* original f449, guest PC 0x0c03d060 */
if(!s->budget--) { s->failed_pc=0x0c03d060u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03d062;
P_0c03d062: /* original f549, guest PC 0x0c03d062 */
if(!s->budget--) { s->failed_pc=0x0c03d062u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03d064;
P_0c03d064: /* original f649, guest PC 0x0c03d064 */
if(!s->budget--) { s->failed_pc=0x0c03d064u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03d066;
P_0c03d066: /* original f78d, guest PC 0x0c03d066 */
if(!s->budget--) { s->failed_pc=0x0c03d066u; return 0; }
fr[7]=0;
goto P_0c03d068;
P_0c03d068: /* original 750c, guest PC 0x0c03d068 */
if(!s->budget--) { s->failed_pc=0x0c03d068u; return 0; }
r[5]+=0x0000000cu;
goto P_0c03d06a;
P_0c03d06a: /* original f5ed, guest PC 0x0c03d06a */
if(!s->budget--) { s->failed_pc=0x0c03d06au; return 0; }
if(!vf3_fpu_fipr(fr+4,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c03d06c;
P_0c03d06c: /* original f07c, guest PC 0x0c03d06c */
if(!s->budget--) { s->failed_pc=0x0c03d06cu; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c03d06e;
P_0c03d06e: /* original f06d, guest PC 0x0c03d06e */
if(!s->budget--) { s->failed_pc=0x0c03d06eu; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c03d070;
P_0c03d070: /* original f77d, guest PC 0x0c03d070 */
if(!s->budget--) { s->failed_pc=0x0c03d070u; return 0; }
if(!vf3_fpu_fsrra(fr[7],r[18],&fr[7])) goto unsupported;
goto P_0c03d072;
P_0c03d072: /* original f672, guest PC 0x0c03d072 */
if(!s->budget--) { s->failed_pc=0x0c03d072u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c03d074;
P_0c03d074: /* original f572, guest PC 0x0c03d074 */
if(!s->budget--) { s->failed_pc=0x0c03d074u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c03d076;
P_0c03d076: /* original f472, guest PC 0x0c03d076 */
if(!s->budget--) { s->failed_pc=0x0c03d076u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c03d078;
P_0c03d078: /* original f56b, guest PC 0x0c03d078 */
if(!s->budget--) { s->failed_pc=0x0c03d078u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c03d07a;
P_0c03d07a: /* original f55b, guest PC 0x0c03d07a */
if(!s->budget--) { s->failed_pc=0x0c03d07au; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c03d07c;
P_0c03d07c: /* original f54b, guest PC 0x0c03d07c */
if(!s->budget--) { s->failed_pc=0x0c03d07cu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c03d07e;
P_0c03d07e: /* original 0009, guest PC 0x0c03d07e */
if(!s->budget--) { s->failed_pc=0x0c03d07eu; return 0; }
goto P_0c03d080;
P_0c03d080: /* original 000b, guest PC 0x0c03d080 */
if(!s->budget--) { s->failed_pc=0x0c03d080u; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c03d082: /* original 7f04, guest PC 0x0c03d082 */
if(!s->budget--) { s->failed_pc=0x0c03d082u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c03d084u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03d084u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
