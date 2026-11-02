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
int vf3_away_batch3_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c036132u: goto P_0c036132;
case 0x0c036134u: goto P_0c036134;
case 0x0c036136u: goto P_0c036136;
case 0x0c036138u: goto P_0c036138;
case 0x0c03613au: goto P_0c03613a;
case 0x0c03613cu: goto P_0c03613c;
case 0x0c03613eu: goto P_0c03613e;
case 0x0c036140u: goto P_0c036140;
case 0x0c036142u: goto P_0c036142;
case 0x0c036144u: goto P_0c036144;
case 0x0c036146u: goto P_0c036146;
case 0x0c036148u: goto P_0c036148;
case 0x0c03614au: goto P_0c03614a;
case 0x0c03614cu: goto P_0c03614c;
case 0x0c03614eu: goto P_0c03614e;
case 0x0c036150u: goto P_0c036150;
case 0x0c036152u: goto P_0c036152;
case 0x0c036154u: goto P_0c036154;
case 0x0c036156u: goto P_0c036156;
case 0x0c036158u: goto P_0c036158;
case 0x0c03615au: goto P_0c03615a;
case 0x0c03615cu: goto P_0c03615c;
case 0x0c03615eu: goto P_0c03615e;
case 0x0c036160u: goto P_0c036160;
case 0x0c036162u: goto P_0c036162;
case 0x0c036164u: goto P_0c036164;
case 0x0c036166u: goto P_0c036166;
case 0x0c036168u: goto P_0c036168;
case 0x0c03616au: goto P_0c03616a;
case 0x0c03616cu: goto P_0c03616c;
case 0x0c03616eu: goto P_0c03616e;
case 0x0c036170u: goto P_0c036170;
case 0x0c036172u: goto P_0c036172;
case 0x0c036174u: goto P_0c036174;
case 0x0c036176u: goto P_0c036176;
case 0x0c036178u: goto P_0c036178;
case 0x0c03617au: goto P_0c03617a;
case 0x0c03617cu: goto P_0c03617c;
case 0x0c03617eu: goto P_0c03617e;
case 0x0c036180u: goto P_0c036180;
case 0x0c036182u: goto P_0c036182;
case 0x0c036184u: goto P_0c036184;
case 0x0c036186u: goto P_0c036186;
case 0x0c0361a8u: goto P_0c0361a8;
case 0x0c0361aau: goto P_0c0361aa;
case 0x0c0361acu: goto P_0c0361ac;
case 0x0c0361aeu: goto P_0c0361ae;
case 0x0c0361b0u: goto P_0c0361b0;
case 0x0c0361b2u: goto P_0c0361b2;
case 0x0c0361b4u: goto P_0c0361b4;
case 0x0c0361b6u: goto P_0c0361b6;
case 0x0c0361b8u: goto P_0c0361b8;
case 0x0c0361bau: goto P_0c0361ba;
case 0x0c0361bcu: goto P_0c0361bc;
case 0x0c0361beu: goto P_0c0361be;
case 0x0c0361c0u: goto P_0c0361c0;
case 0x0c0361c2u: goto P_0c0361c2;
case 0x0c0361c4u: goto P_0c0361c4;
case 0x0c0361c6u: goto P_0c0361c6;
case 0x0c0361c8u: goto P_0c0361c8;
case 0x0c0361cau: goto P_0c0361ca;
case 0x0c0361ccu: goto P_0c0361cc;
case 0x0c0361ceu: goto P_0c0361ce;
case 0x0c0361d0u: goto P_0c0361d0;
case 0x0c0361d2u: goto P_0c0361d2;
case 0x0c0361d4u: goto P_0c0361d4;
case 0x0c0361d6u: goto P_0c0361d6;
case 0x0c0361d8u: goto P_0c0361d8;
case 0x0c0361dau: goto P_0c0361da;
case 0x0c0361dcu: goto P_0c0361dc;
case 0x0c0361deu: goto P_0c0361de;
case 0x0c0361e0u: goto P_0c0361e0;
case 0x0c0361e2u: goto P_0c0361e2;
case 0x0c0361e4u: goto P_0c0361e4;
case 0x0c0361e6u: goto P_0c0361e6;
case 0x0c0361e8u: goto P_0c0361e8;
case 0x0c0361eau: goto P_0c0361ea;
case 0x0c0361ecu: goto P_0c0361ec;
case 0x0c0361eeu: goto P_0c0361ee;
case 0x0c0361f0u: goto P_0c0361f0;
case 0x0c0361f2u: goto P_0c0361f2;
case 0x0c0361f4u: goto P_0c0361f4;
case 0x0c0361f6u: goto P_0c0361f6;
case 0x0c0361f8u: goto P_0c0361f8;
case 0x0c0361fau: goto P_0c0361fa;
case 0x0c0361fcu: goto P_0c0361fc;
case 0x0c0361feu: goto P_0c0361fe;
case 0x0c036200u: goto P_0c036200;
case 0x0c036202u: goto P_0c036202;
case 0x0c036204u: goto P_0c036204;
case 0x0c036206u: goto P_0c036206;
case 0x0c036208u: goto P_0c036208;
case 0x0c03620au: goto P_0c03620a;
case 0x0c03620cu: goto P_0c03620c;
case 0x0c03620eu: goto P_0c03620e;
case 0x0c036210u: goto P_0c036210;
case 0x0c036212u: goto P_0c036212;
case 0x0c036214u: goto P_0c036214;
case 0x0c036216u: goto P_0c036216;
case 0x0c036218u: goto P_0c036218;
case 0x0c03621au: goto P_0c03621a;
case 0x0c03621cu: goto P_0c03621c;
case 0x0c03621eu: goto P_0c03621e;
case 0x0c036220u: goto P_0c036220;
case 0x0c036222u: goto P_0c036222;
case 0x0c036224u: goto P_0c036224;
case 0x0c036226u: goto P_0c036226;
case 0x0c036228u: goto P_0c036228;
case 0x0c03622au: goto P_0c03622a;
case 0x0c03622cu: goto P_0c03622c;
case 0x0c03622eu: goto P_0c03622e;
case 0x0c036230u: goto P_0c036230;
case 0x0c036232u: goto P_0c036232;
case 0x0c036234u: goto P_0c036234;
case 0x0c036236u: goto P_0c036236;
case 0x0c036238u: goto P_0c036238;
case 0x0c03623au: goto P_0c03623a;
case 0x0c03623cu: goto P_0c03623c;
case 0x0c03623eu: goto P_0c03623e;
case 0x0c036240u: goto P_0c036240;
case 0x0c036242u: goto P_0c036242;
case 0x0c036244u: goto P_0c036244;
case 0x0c036246u: goto P_0c036246;
case 0x0c036248u: goto P_0c036248;
case 0x0c03624au: goto P_0c03624a;
case 0x0c03624cu: goto P_0c03624c;
case 0x0c03624eu: goto P_0c03624e;
case 0x0c036250u: goto P_0c036250;
case 0x0c036252u: goto P_0c036252;
case 0x0c036254u: goto P_0c036254;
case 0x0c036256u: goto P_0c036256;
case 0x0c036258u: goto P_0c036258;
case 0x0c03625au: goto P_0c03625a;
case 0x0c03625cu: goto P_0c03625c;
case 0x0c03625eu: goto P_0c03625e;
case 0x0c036260u: goto P_0c036260;
case 0x0c036262u: goto P_0c036262;
case 0x0c036264u: goto P_0c036264;
case 0x0c036266u: goto P_0c036266;
case 0x0c036268u: goto P_0c036268;
case 0x0c03626au: goto P_0c03626a;
case 0x0c03626cu: goto P_0c03626c;
case 0x0c03626eu: goto P_0c03626e;
case 0x0c036270u: goto P_0c036270;
case 0x0c036272u: goto P_0c036272;
case 0x0c036274u: goto P_0c036274;
case 0x0c036276u: goto P_0c036276;
case 0x0c036278u: goto P_0c036278;
case 0x0c03627au: goto P_0c03627a;
case 0x0c03627cu: goto P_0c03627c;
case 0x0c03627eu: goto P_0c03627e;
case 0x0c036280u: goto P_0c036280;
case 0x0c036282u: goto P_0c036282;
case 0x0c036284u: goto P_0c036284;
case 0x0c036286u: goto P_0c036286;
case 0x0c036288u: goto P_0c036288;
case 0x0c03628au: goto P_0c03628a;
case 0x0c03628cu: goto P_0c03628c;
case 0x0c03628eu: goto P_0c03628e;
case 0x0c036290u: goto P_0c036290;
case 0x0c036292u: goto P_0c036292;
case 0x0c036294u: goto P_0c036294;
case 0x0c036296u: goto P_0c036296;
case 0x0c036298u: goto P_0c036298;
case 0x0c03629au: goto P_0c03629a;
case 0x0c03629cu: goto P_0c03629c;
case 0x0c03629eu: goto P_0c03629e;
case 0x0c0362a0u: goto P_0c0362a0;
case 0x0c0362a2u: goto P_0c0362a2;
case 0x0c0362a4u: goto P_0c0362a4;
case 0x0c0362a6u: goto P_0c0362a6;
case 0x0c0362a8u: goto P_0c0362a8;
case 0x0c0362aau: goto P_0c0362aa;
case 0x0c0362acu: goto P_0c0362ac;
case 0x0c0362aeu: goto P_0c0362ae;
case 0x0c0362b0u: goto P_0c0362b0;
case 0x0c0362b2u: goto P_0c0362b2;
case 0x0c0362b4u: goto P_0c0362b4;
case 0x0c0362b6u: goto P_0c0362b6;
case 0x0c0362b8u: goto P_0c0362b8;
case 0x0c0362bau: goto P_0c0362ba;
case 0x0c0362bcu: goto P_0c0362bc;
case 0x0c0362beu: goto P_0c0362be;
case 0x0c0362c0u: goto P_0c0362c0;
case 0x0c0362c2u: goto P_0c0362c2;
case 0x0c0362c4u: goto P_0c0362c4;
case 0x0c0362f8u: goto P_0c0362f8;
case 0x0c0362fau: goto P_0c0362fa;
case 0x0c0362fcu: goto P_0c0362fc;
case 0x0c0362feu: goto P_0c0362fe;
case 0x0c036300u: goto P_0c036300;
case 0x0c036302u: goto P_0c036302;
case 0x0c036304u: goto P_0c036304;
case 0x0c036306u: goto P_0c036306;
case 0x0c036308u: goto P_0c036308;
case 0x0c03630au: goto P_0c03630a;
case 0x0c03630cu: goto P_0c03630c;
case 0x0c03630eu: goto P_0c03630e;
case 0x0c036310u: goto P_0c036310;
case 0x0c036312u: goto P_0c036312;
case 0x0c036314u: goto P_0c036314;
default: return vf3_matrix_family(target,s,ram);
}
P_0c036132: /* original 2fe6, guest PC 0x0c036132 */
if(!s->budget--) { s->failed_pc=0x0c036132u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036134;
P_0c036134: /* original 2fd6, guest PC 0x0c036134 */
if(!s->budget--) { s->failed_pc=0x0c036134u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036136;
P_0c036136: /* original 2fc6, guest PC 0x0c036136 */
if(!s->budget--) { s->failed_pc=0x0c036136u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036138;
P_0c036138: /* original 2f86, guest PC 0x0c036138 */
if(!s->budget--) { s->failed_pc=0x0c036138u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03613a;
P_0c03613a: /* original 4f22, guest PC 0x0c03613a */
if(!s->budget--) { s->failed_pc=0x0c03613au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03613c;
P_0c03613c: /* original d314, guest PC 0x0c03613c */
if(!s->budget--) { s->failed_pc=0x0c03613cu; return 0; }
r[3]=read(ram,0x0c036190u,4);
goto P_0c03613e;
P_0c03613e: /* original b225, guest PC 0x0c03613e */
if(!s->budget--) { s->failed_pc=0x0c03613eu; return 0; }
target=code_base|0x0c03658cu; r[16]=code_base|0x0c036142u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036142u) { target=s->pc; goto dispatch; }
goto P_0c036142;
P_0c036140: /* original 2f36, guest PC 0x0c036140 */
if(!s->budget--) { s->failed_pc=0x0c036140u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036142;
P_0c036142: /* original de14, guest PC 0x0c036142 */
if(!s->budget--) { s->failed_pc=0x0c036142u; return 0; }
r[14]=read(ram,0x0c036194u,4);
goto P_0c036144;
P_0c036144: /* original 9020, guest PC 0x0c036144 */
if(!s->budget--) { s->failed_pc=0x0c036144u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036188u,2);
goto P_0c036146;
P_0c036146: /* original 64e2, guest PC 0x0c036146 */
if(!s->budget--) { s->failed_pc=0x0c036146u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c036148;
P_0c036148: /* original 004e, guest PC 0x0c036148 */
if(!s->budget--) { s->failed_pc=0x0c036148u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c03614a;
P_0c03614a: /* original 8801, guest PC 0x0c03614a */
if(!s->budget--) { s->failed_pc=0x0c03614au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c03614c;
P_0c03614c: /* original 8d06, guest PC 0x0c03614c */
if(!s->budget--) { s->failed_pc=0x0c03614cu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c03615c; }
goto P_0c036150;
P_0c03614e: /* original 7f04, guest PC 0x0c03614e */
if(!s->budget--) { s->failed_pc=0x0c03614eu; return 0; }
r[15]+=0x00000004u;
goto P_0c036150;
P_0c036150: /* original d211, guest PC 0x0c036150 */
if(!s->budget--) { s->failed_pc=0x0c036150u; return 0; }
r[2]=read(ram,0x0c036198u,4);
goto P_0c036152;
P_0c036152: /* original b21b, guest PC 0x0c036152 */
if(!s->budget--) { s->failed_pc=0x0c036152u; return 0; }
target=code_base|0x0c03658cu; r[16]=code_base|0x0c036156u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036156u) { target=s->pc; goto dispatch; }
goto P_0c036156;
P_0c036154: /* original 2f26, guest PC 0x0c036154 */
if(!s->budget--) { s->failed_pc=0x0c036154u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036156;
P_0c036156: /* original 7f04, guest PC 0x0c036156 */
if(!s->budget--) { s->failed_pc=0x0c036156u; return 0; }
r[15]+=0x00000004u;
goto P_0c036158;
P_0c036158: /* original a091, guest PC 0x0c036158 */
if(!s->budget--) { s->failed_pc=0x0c036158u; return 0; }
r[0]=0xfffffffdu;
goto P_0c03627e;
P_0c03615a: /* original e0fd, guest PC 0x0c03615a */
if(!s->budget--) { s->failed_pc=0x0c03615au; return 0; }
r[0]=0xfffffffdu;
goto P_0c03615c;
P_0c03615c: /* original 9015, guest PC 0x0c03615c */
if(!s->budget--) { s->failed_pc=0x0c03615cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03618au,2);
goto P_0c03615e;
P_0c03615e: /* original ec01, guest PC 0x0c03615e */
if(!s->budget--) { s->failed_pc=0x0c03615eu; return 0; }
r[12]=0x00000001u;
goto P_0c036160;
P_0c036160: /* original 024e, guest PC 0x0c036160 */
if(!s->budget--) { s->failed_pc=0x0c036160u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c036162;
P_0c036162: /* original 5326, guest PC 0x0c036162 */
if(!s->budget--) { s->failed_pc=0x0c036162u; return 0; }
r[3]=read(ram,r[2]+24,4);
goto P_0c036164;
P_0c036164: /* original 23c8, guest PC 0x0c036164 */
if(!s->budget--) { s->failed_pc=0x0c036164u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c036166;
P_0c036166: /* original 8905, guest PC 0x0c036166 */
if(!s->budget--) { s->failed_pc=0x0c036166u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036174; }
goto P_0c036168;
P_0c036168: /* original d10c, guest PC 0x0c036168 */
if(!s->budget--) { s->failed_pc=0x0c036168u; return 0; }
r[1]=read(ram,0x0c03619cu,4);
goto P_0c03616a;
P_0c03616a: /* original b20f, guest PC 0x0c03616a */
if(!s->budget--) { s->failed_pc=0x0c03616au; return 0; }
target=code_base|0x0c03658cu; r[16]=code_base|0x0c03616eu;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03616eu) { target=s->pc; goto dispatch; }
goto P_0c03616e;
P_0c03616c: /* original 2f16, guest PC 0x0c03616c */
if(!s->budget--) { s->failed_pc=0x0c03616cu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03616e;
P_0c03616e: /* original 7f04, guest PC 0x0c03616e */
if(!s->budget--) { s->failed_pc=0x0c03616eu; return 0; }
r[15]+=0x00000004u;
goto P_0c036170;
P_0c036170: /* original a085, guest PC 0x0c036170 */
if(!s->budget--) { s->failed_pc=0x0c036170u; return 0; }
r[0]=0xffffffffu;
goto P_0c03627e;
P_0c036172: /* original e0ff, guest PC 0x0c036172 */
if(!s->budget--) { s->failed_pc=0x0c036172u; return 0; }
r[0]=0xffffffffu;
goto P_0c036174;
P_0c036174: /* original d30a, guest PC 0x0c036174 */
if(!s->budget--) { s->failed_pc=0x0c036174u; return 0; }
r[3]=read(ram,0x0c0361a0u,4);
goto P_0c036176;
P_0c036176: /* original 6032, guest PC 0x0c036176 */
if(!s->budget--) { s->failed_pc=0x0c036176u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c036178;
P_0c036178: /* original 401b, guest PC 0x0c036178 */
if(!s->budget--) { s->failed_pc=0x0c036178u; return 0; }
tmp=read(ram,r[0],1);
r[17]=(r[17]&~1u)|((tmp==0)!=0);
write(ram,r[0],tmp|0x80u,1);
goto P_0c03617a;
P_0c03617a: /* original 8915, guest PC 0x0c03617a */
if(!s->budget--) { s->failed_pc=0x0c03617au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0361a8; }
goto P_0c03617c;
P_0c03617c: /* original d109, guest PC 0x0c03617c */
if(!s->budget--) { s->failed_pc=0x0c03617cu; return 0; }
r[1]=read(ram,0x0c0361a4u,4);
goto P_0c03617e;
P_0c03617e: /* original b205, guest PC 0x0c03617e */
if(!s->budget--) { s->failed_pc=0x0c03617eu; return 0; }
target=code_base|0x0c03658cu; r[16]=code_base|0x0c036182u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036182u) { target=s->pc; goto dispatch; }
goto P_0c036182;
P_0c036180: /* original 2f16, guest PC 0x0c036180 */
if(!s->budget--) { s->failed_pc=0x0c036180u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036182;
P_0c036182: /* original 7f04, guest PC 0x0c036182 */
if(!s->budget--) { s->failed_pc=0x0c036182u; return 0; }
r[15]+=0x00000004u;
goto P_0c036184;
P_0c036184: /* original a07b, guest PC 0x0c036184 */
if(!s->budget--) { s->failed_pc=0x0c036184u; return 0; }
r[0]=0xfffffffeu;
goto P_0c03627e;
P_0c036186: /* original e0fe, guest PC 0x0c036186 */
if(!s->budget--) { s->failed_pc=0x0c036186u; return 0; }
r[0]=0xfffffffeu;
if(!vf3_matrix_family(0x0c036188u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c036188u; return 0; } return 1;
P_0c0361a8: /* original 63e2, guest PC 0x0c0361a8 */
if(!s->budget--) { s->failed_pc=0x0c0361a8u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0361aa;
P_0c0361aa: /* original 908c, guest PC 0x0c0361aa */
if(!s->budget--) { s->failed_pc=0x0c0361aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0362c6u,2);
goto P_0c0361ac;
P_0c0361ac: /* original 6233, guest PC 0x0c0361ac */
if(!s->budget--) { s->failed_pc=0x0c0361acu; return 0; }
r[2]=r[3];
goto P_0c0361ae;
P_0c0361ae: /* original 012e, guest PC 0x0c0361ae */
if(!s->budget--) { s->failed_pc=0x0c0361aeu; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c0361b0;
P_0c0361b0: /* original 7004, guest PC 0x0c0361b0 */
if(!s->budget--) { s->failed_pc=0x0c0361b0u; return 0; }
r[0]+=0x00000004u;
goto P_0c0361b2;
P_0c0361b2: /* original 0316, guest PC 0x0c0361b2 */
if(!s->budget--) { s->failed_pc=0x0c0361b2u; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c0361b4;
P_0c0361b4: /* original be6c, guest PC 0x0c0361b4 */
if(!s->budget--) { s->failed_pc=0x0c0361b4u; return 0; }
target=code_base|0x0c035e90u; r[16]=code_base|0x0c0361b8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0361b8u) { target=s->pc; goto dispatch; }
goto P_0c0361b8;
P_0c0361b6: /* original 0009, guest PC 0x0c0361b6 */
if(!s->budget--) { s->failed_pc=0x0c0361b6u; return 0; }
goto P_0c0361b8;
P_0c0361b8: /* original 62e2, guest PC 0x0c0361b8 */
if(!s->budget--) { s->failed_pc=0x0c0361b8u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0361ba;
P_0c0361ba: /* original 9185, guest PC 0x0c0361ba */
if(!s->budget--) { s->failed_pc=0x0c0361bau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0362c8u,2);
goto P_0c0361bc;
P_0c0361bc: /* original 6323, guest PC 0x0c0361bc */
if(!s->budget--) { s->failed_pc=0x0c0361bcu; return 0; }
r[3]=r[2];
goto P_0c0361be;
P_0c0361be: /* original 6023, guest PC 0x0c0361be */
if(!s->budget--) { s->failed_pc=0x0c0361beu; return 0; }
r[0]=r[2];
goto P_0c0361c0;
P_0c0361c0: /* original 313c, guest PC 0x0c0361c0 */
if(!s->budget--) { s->failed_pc=0x0c0361c0u; return 0; }
r[1]+=r[3];
goto P_0c0361c2;
P_0c0361c2: /* original 9382, guest PC 0x0c0361c2 */
if(!s->budget--) { s->failed_pc=0x0c0361c2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0362cau,2);
goto P_0c0361c4;
P_0c0361c4: /* original 6112, guest PC 0x0c0361c4 */
if(!s->budget--) { s->failed_pc=0x0c0361c4u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c0361c6;
P_0c0361c6: /* original 330c, guest PC 0x0c0361c6 */
if(!s->budget--) { s->failed_pc=0x0c0361c6u; return 0; }
r[3]+=r[0];
goto P_0c0361c8;
P_0c0361c8: /* original 4108, guest PC 0x0c0361c8 */
if(!s->budget--) { s->failed_pc=0x0c0361c8u; return 0; }
r[1]<<=2;
goto P_0c0361ca;
P_0c0361ca: /* original 313c, guest PC 0x0c0361ca */
if(!s->budget--) { s->failed_pc=0x0c0361cau; return 0; }
r[1]+=r[3];
goto P_0c0361cc;
P_0c0361cc: /* original 6012, guest PC 0x0c0361cc */
if(!s->budget--) { s->failed_pc=0x0c0361ccu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c0361ce;
P_0c0361ce: /* original 917d, guest PC 0x0c0361ce */
if(!s->budget--) { s->failed_pc=0x0c0361ceu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0362ccu,2);
goto P_0c0361d0;
P_0c0361d0: /* original 312c, guest PC 0x0c0361d0 */
if(!s->budget--) { s->failed_pc=0x0c0361d0u; return 0; }
r[1]+=r[2];
goto P_0c0361d2;
P_0c0361d2: /* original 2102, guest PC 0x0c0361d2 */
if(!s->budget--) { s->failed_pc=0x0c0361d2u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0361d4;
P_0c0361d4: /* original 907b, guest PC 0x0c0361d4 */
if(!s->budget--) { s->failed_pc=0x0c0361d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0362ceu,2);
goto P_0c0361d6;
P_0c0361d6: /* original 63e2, guest PC 0x0c0361d6 */
if(!s->budget--) { s->failed_pc=0x0c0361d6u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0361d8;
P_0c0361d8: /* original 9176, guest PC 0x0c0361d8 */
if(!s->budget--) { s->failed_pc=0x0c0361d8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0362c8u,2);
goto P_0c0361da;
P_0c0361da: /* original 6433, guest PC 0x0c0361da */
if(!s->budget--) { s->failed_pc=0x0c0361dau; return 0; }
r[4]=r[3];
goto P_0c0361dc;
P_0c0361dc: /* original 083e, guest PC 0x0c0361dc */
if(!s->budget--) { s->failed_pc=0x0c0361dcu; return 0; }
r[8]=read(ram,r[3]+r[0],4);
goto P_0c0361de;
P_0c0361de: /* original 314c, guest PC 0x0c0361de */
if(!s->budget--) { s->failed_pc=0x0c0361deu; return 0; }
r[1]+=r[4];
goto P_0c0361e0;
P_0c0361e0: /* original 6033, guest PC 0x0c0361e0 */
if(!s->budget--) { s->failed_pc=0x0c0361e0u; return 0; }
r[0]=r[3];
goto P_0c0361e2;
P_0c0361e2: /* original 9372, guest PC 0x0c0361e2 */
if(!s->budget--) { s->failed_pc=0x0c0361e2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0362cau,2);
goto P_0c0361e4;
P_0c0361e4: /* original 7804, guest PC 0x0c0361e4 */
if(!s->budget--) { s->failed_pc=0x0c0361e4u; return 0; }
r[8]+=0x00000004u;
goto P_0c0361e6;
P_0c0361e6: /* original 6412, guest PC 0x0c0361e6 */
if(!s->budget--) { s->failed_pc=0x0c0361e6u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c0361e8;
P_0c0361e8: /* original 330c, guest PC 0x0c0361e8 */
if(!s->budget--) { s->failed_pc=0x0c0361e8u; return 0; }
r[3]+=r[0];
goto P_0c0361ea;
P_0c0361ea: /* original d23c, guest PC 0x0c0361ea */
if(!s->budget--) { s->failed_pc=0x0c0361eau; return 0; }
r[2]=read(ram,0x0c0362dcu,4);
goto P_0c0361ec;
P_0c0361ec: /* original 4408, guest PC 0x0c0361ec */
if(!s->budget--) { s->failed_pc=0x0c0361ecu; return 0; }
r[4]<<=2;
goto P_0c0361ee;
P_0c0361ee: /* original 343c, guest PC 0x0c0361ee */
if(!s->budget--) { s->failed_pc=0x0c0361eeu; return 0; }
r[4]+=r[3];
goto P_0c0361f0;
P_0c0361f0: /* original 420b, guest PC 0x0c0361f0 */
if(!s->budget--) { s->failed_pc=0x0c0361f0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0361f4u;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0361f4u) { target=s->pc; goto dispatch; }
goto P_0c0361f4;
P_0c0361f2: /* original 6442, guest PC 0x0c0361f2 */
if(!s->budget--) { s->failed_pc=0x0c0361f2u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0361f4;
P_0c0361f4: /* original 2802, guest PC 0x0c0361f4 */
if(!s->budget--) { s->failed_pc=0x0c0361f4u; return 0; }
write(ram,r[8],r[0],4);
goto P_0c0361f6;
P_0c0361f6: /* original 906a, guest PC 0x0c0361f6 */
if(!s->budget--) { s->failed_pc=0x0c0361f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0362ceu,2);
goto P_0c0361f8;
P_0c0361f8: /* original 63e2, guest PC 0x0c0361f8 */
if(!s->budget--) { s->failed_pc=0x0c0361f8u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0361fa;
P_0c0361fa: /* original 023e, guest PC 0x0c0361fa */
if(!s->budget--) { s->failed_pc=0x0c0361fau; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0361fc;
P_0c0361fc: /* original 12c6, guest PC 0x0c0361fc */
if(!s->budget--) { s->failed_pc=0x0c0361fcu; return 0; }
write(ram,r[2]+24,r[12],4);
goto P_0c0361fe;
P_0c0361fe: /* original 9067, guest PC 0x0c0361fe */
if(!s->budget--) { s->failed_pc=0x0c0361feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0362d0u,2);
goto P_0c036200;
P_0c036200: /* original ed00, guest PC 0x0c036200 */
if(!s->budget--) { s->failed_pc=0x0c036200u; return 0; }
r[13]=0x00000000u;
goto P_0c036202;
P_0c036202: /* original 63e2, guest PC 0x0c036202 */
if(!s->budget--) { s->failed_pc=0x0c036202u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c036204;
P_0c036204: /* original 03d6, guest PC 0x0c036204 */
if(!s->budget--) { s->failed_pc=0x0c036204u; return 0; }
write(ram,r[3]+r[0],r[13],4);
goto P_0c036206;
P_0c036206: /* original 905f, guest PC 0x0c036206 */
if(!s->budget--) { s->failed_pc=0x0c036206u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0362c8u,2);
goto P_0c036208;
P_0c036208: /* original 63e2, guest PC 0x0c036208 */
if(!s->budget--) { s->failed_pc=0x0c036208u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03620a;
P_0c03620a: /* original 023e, guest PC 0x0c03620a */
if(!s->budget--) { s->failed_pc=0x0c03620au; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c03620c;
P_0c03620c: /* original 22ca, guest PC 0x0c03620c */
if(!s->budget--) { s->failed_pc=0x0c03620cu; return 0; }
r[2]^=r[12];
goto P_0c03620e;
P_0c03620e: /* original 0326, guest PC 0x0c03620e */
if(!s->budget--) { s->failed_pc=0x0c03620eu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c036210;
P_0c036210: /* original 63e2, guest PC 0x0c036210 */
if(!s->budget--) { s->failed_pc=0x0c036210u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c036212;
P_0c036212: /* original 9159, guest PC 0x0c036212 */
if(!s->budget--) { s->failed_pc=0x0c036212u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0362c8u,2);
goto P_0c036214;
P_0c036214: /* original 6233, guest PC 0x0c036214 */
if(!s->budget--) { s->failed_pc=0x0c036214u; return 0; }
r[2]=r[3];
goto P_0c036216;
P_0c036216: /* original 6033, guest PC 0x0c036216 */
if(!s->budget--) { s->failed_pc=0x0c036216u; return 0; }
r[0]=r[3];
goto P_0c036218;
P_0c036218: /* original 312c, guest PC 0x0c036218 */
if(!s->budget--) { s->failed_pc=0x0c036218u; return 0; }
r[1]+=r[2];
goto P_0c03621a;
P_0c03621a: /* original 9256, guest PC 0x0c03621a */
if(!s->budget--) { s->failed_pc=0x0c03621au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0362cau,2);
goto P_0c03621c;
P_0c03621c: /* original 6112, guest PC 0x0c03621c */
if(!s->budget--) { s->failed_pc=0x0c03621cu; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c03621e;
P_0c03621e: /* original 320c, guest PC 0x0c03621e */
if(!s->budget--) { s->failed_pc=0x0c03621eu; return 0; }
r[2]+=r[0];
goto P_0c036220;
P_0c036220: /* original 4108, guest PC 0x0c036220 */
if(!s->budget--) { s->failed_pc=0x0c036220u; return 0; }
r[1]<<=2;
goto P_0c036222;
P_0c036222: /* original 312c, guest PC 0x0c036222 */
if(!s->budget--) { s->failed_pc=0x0c036222u; return 0; }
r[1]+=r[2];
goto P_0c036224;
P_0c036224: /* original 6012, guest PC 0x0c036224 */
if(!s->budget--) { s->failed_pc=0x0c036224u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c036226;
P_0c036226: /* original 9154, guest PC 0x0c036226 */
if(!s->budget--) { s->failed_pc=0x0c036226u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0362d2u,2);
goto P_0c036228;
P_0c036228: /* original 313c, guest PC 0x0c036228 */
if(!s->budget--) { s->failed_pc=0x0c036228u; return 0; }
r[1]+=r[3];
goto P_0c03622a;
P_0c03622a: /* original 2102, guest PC 0x0c03622a */
if(!s->budget--) { s->failed_pc=0x0c03622au; return 0; }
write(ram,r[1],r[0],4);
goto P_0c03622c;
P_0c03622c: /* original 9052, guest PC 0x0c03622c */
if(!s->budget--) { s->failed_pc=0x0c03622cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0362d4u,2);
goto P_0c03622e;
P_0c03622e: /* original 63e2, guest PC 0x0c03622e */
if(!s->budget--) { s->failed_pc=0x0c03622eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c036230;
P_0c036230: /* original 023e, guest PC 0x0c036230 */
if(!s->budget--) { s->failed_pc=0x0c036230u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c036232;
P_0c036232: /* original 22ca, guest PC 0x0c036232 */
if(!s->budget--) { s->failed_pc=0x0c036232u; return 0; }
r[2]^=r[12];
goto P_0c036234;
P_0c036234: /* original 0326, guest PC 0x0c036234 */
if(!s->budget--) { s->failed_pc=0x0c036234u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c036236;
P_0c036236: /* original 904e, guest PC 0x0c036236 */
if(!s->budget--) { s->failed_pc=0x0c036236u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0362d6u,2);
goto P_0c036238;
P_0c036238: /* original 63e2, guest PC 0x0c036238 */
if(!s->budget--) { s->failed_pc=0x0c036238u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03623a;
P_0c03623a: /* original 03d6, guest PC 0x0c03623a */
if(!s->budget--) { s->failed_pc=0x0c03623au; return 0; }
write(ram,r[3]+r[0],r[13],4);
goto P_0c03623c;
P_0c03623c: /* original 64e2, guest PC 0x0c03623c */
if(!s->budget--) { s->failed_pc=0x0c03623cu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c03623e;
P_0c03623e: /* original 65d3, guest PC 0x0c03623e */
if(!s->budget--) { s->failed_pc=0x0c03623eu; return 0; }
r[5]=r[13];
goto P_0c036240;
P_0c036240: /* original e607, guest PC 0x0c036240 */
if(!s->budget--) { s->failed_pc=0x0c036240u; return 0; }
r[6]=0x00000007u;
goto P_0c036242;
P_0c036242: /* original 7428, guest PC 0x0c036242 */
if(!s->budget--) { s->failed_pc=0x0c036242u; return 0; }
r[4]+=0x00000028u;
goto P_0c036244;
P_0c036244: /* original 9348, guest PC 0x0c036244 */
if(!s->budget--) { s->failed_pc=0x0c036244u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0362d8u,2);
goto P_0c036246;
P_0c036246: /* original 60e2, guest PC 0x0c036246 */
if(!s->budget--) { s->failed_pc=0x0c036246u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c036248;
P_0c036248: /* original 330c, guest PC 0x0c036248 */
if(!s->budget--) { s->failed_pc=0x0c036248u; return 0; }
r[3]+=r[0];
goto P_0c03624a;
P_0c03624a: /* original 335c, guest PC 0x0c03624a */
if(!s->budget--) { s->failed_pc=0x0c03624au; return 0; }
r[3]+=r[5];
goto P_0c03624c;
P_0c03624c: /* original 6230, guest PC 0x0c03624c */
if(!s->budget--) { s->failed_pc=0x0c03624cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c03624e;
P_0c03624e: /* original 2228, guest PC 0x0c03624e */
if(!s->budget--) { s->failed_pc=0x0c03624eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c036250;
P_0c036250: /* original 8d07, guest PC 0x0c036250 */
if(!s->budget--) { s->failed_pc=0x0c036250u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000001u;
if(cond) { goto P_0c036262; }
goto P_0c036254;
P_0c036252: /* original 7501, guest PC 0x0c036252 */
if(!s->budget--) { s->failed_pc=0x0c036252u; return 0; }
r[5]+=0x00000001u;
goto P_0c036254;
P_0c036254: /* original 8446, guest PC 0x0c036254 */
if(!s->budget--) { s->failed_pc=0x0c036254u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+6,1);
goto P_0c036256;
P_0c036256: /* original 8047, guest PC 0x0c036256 */
if(!s->budget--) { s->failed_pc=0x0c036256u; return 0; }
write(ram,r[4]+7,r[0],1);
goto P_0c036258;
P_0c036258: /* original 60d3, guest PC 0x0c036258 */
if(!s->budget--) { s->failed_pc=0x0c036258u; return 0; }
r[0]=r[13];
goto P_0c03625a;
P_0c03625a: /* original 8046, guest PC 0x0c03625a */
if(!s->budget--) { s->failed_pc=0x0c03625au; return 0; }
write(ram,r[4]+6,r[0],1);
goto P_0c03625c;
P_0c03625c: /* original 5346, guest PC 0x0c03625c */
if(!s->budget--) { s->failed_pc=0x0c03625cu; return 0; }
r[3]=read(ram,r[4]+24,4);
goto P_0c03625e;
P_0c03625e: /* original 1437, guest PC 0x0c03625e */
if(!s->budget--) { s->failed_pc=0x0c03625eu; return 0; }
write(ram,r[4]+28,r[3],4);
goto P_0c036260;
P_0c036260: /* original 1406, guest PC 0x0c036260 */
if(!s->budget--) { s->failed_pc=0x0c036260u; return 0; }
write(ram,r[4]+24,r[0],4);
goto P_0c036262;
P_0c036262: /* original 3563, guest PC 0x0c036262 */
if(!s->budget--) { s->failed_pc=0x0c036262u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c036264;
P_0c036264: /* original 8fee, guest PC 0x0c036264 */
if(!s->budget--) { s->failed_pc=0x0c036264u; return 0; }
cond=r[17]&1u;
r[4]+=0x0000002cu;
if(!cond) { goto P_0c036244; }
goto P_0c036268;
P_0c036266: /* original 742c, guest PC 0x0c036266 */
if(!s->budget--) { s->failed_pc=0x0c036266u; return 0; }
r[4]+=0x0000002cu;
goto P_0c036268;
P_0c036268: /* original d31d, guest PC 0x0c036268 */
if(!s->budget--) { s->failed_pc=0x0c036268u; return 0; }
r[3]=read(ram,0x0c0362e0u,4);
goto P_0c03626a;
P_0c03626a: /* original b18f, guest PC 0x0c03626a */
if(!s->budget--) { s->failed_pc=0x0c03626au; return 0; }
target=code_base|0x0c03658cu; r[16]=code_base|0x0c03626eu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03626eu) { target=s->pc; goto dispatch; }
goto P_0c03626e;
P_0c03626c: /* original 2f36, guest PC 0x0c03626c */
if(!s->budget--) { s->failed_pc=0x0c03626cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03626e;
P_0c03626e: /* original 9034, guest PC 0x0c03626e */
if(!s->budget--) { s->failed_pc=0x0c03626eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0362dau,2);
goto P_0c036270;
P_0c036270: /* original 7f04, guest PC 0x0c036270 */
if(!s->budget--) { s->failed_pc=0x0c036270u; return 0; }
r[15]+=0x00000004u;
goto P_0c036272;
P_0c036272: /* original 61e2, guest PC 0x0c036272 */
if(!s->budget--) { s->failed_pc=0x0c036272u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c036274;
P_0c036274: /* original 01d6, guest PC 0x0c036274 */
if(!s->budget--) { s->failed_pc=0x0c036274u; return 0; }
write(ram,r[1]+r[0],r[13],4);
goto P_0c036276;
P_0c036276: /* original 60d3, guest PC 0x0c036276 */
if(!s->budget--) { s->failed_pc=0x0c036276u; return 0; }
r[0]=r[13];
goto P_0c036278;
P_0c036278: /* original d21a, guest PC 0x0c036278 */
if(!s->budget--) { s->failed_pc=0x0c036278u; return 0; }
r[2]=read(ram,0x0c0362e4u,4);
goto P_0c03627a;
P_0c03627a: /* original 6322, guest PC 0x0c03627a */
if(!s->budget--) { s->failed_pc=0x0c03627au; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03627c;
P_0c03627c: /* original 23d0, guest PC 0x0c03627c */
if(!s->budget--) { s->failed_pc=0x0c03627cu; return 0; }
write(ram,r[3],r[13],1);
goto P_0c03627e;
P_0c03627e: /* original 4f26, guest PC 0x0c03627e */
if(!s->budget--) { s->failed_pc=0x0c03627eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c036280;
P_0c036280: /* original 68f6, guest PC 0x0c036280 */
if(!s->budget--) { s->failed_pc=0x0c036280u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c036282;
P_0c036282: /* original 6cf6, guest PC 0x0c036282 */
if(!s->budget--) { s->failed_pc=0x0c036282u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c036284;
P_0c036284: /* original 6df6, guest PC 0x0c036284 */
if(!s->budget--) { s->failed_pc=0x0c036284u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c036286;
P_0c036286: /* original 000b, guest PC 0x0c036286 */
if(!s->budget--) { s->failed_pc=0x0c036286u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c036288: /* original 6ef6, guest PC 0x0c036288 */
if(!s->budget--) { s->failed_pc=0x0c036288u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c03628a;
P_0c03628a: /* original 4f22, guest PC 0x0c03628a */
if(!s->budget--) { s->failed_pc=0x0c03628au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03628c;
P_0c03628c: /* original d316, guest PC 0x0c03628c */
if(!s->budget--) { s->failed_pc=0x0c03628cu; return 0; }
r[3]=read(ram,0x0c0362e8u,4);
goto P_0c03628e;
P_0c03628e: /* original b17d, guest PC 0x0c03628e */
if(!s->budget--) { s->failed_pc=0x0c03628eu; return 0; }
target=code_base|0x0c03658cu; r[16]=code_base|0x0c036292u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036292u) { target=s->pc; goto dispatch; }
goto P_0c036292;
P_0c036290: /* original 2f36, guest PC 0x0c036290 */
if(!s->budget--) { s->failed_pc=0x0c036290u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036292;
P_0c036292: /* original d116, guest PC 0x0c036292 */
if(!s->budget--) { s->failed_pc=0x0c036292u; return 0; }
r[1]=read(ram,0x0c0362ecu,4);
goto P_0c036294;
P_0c036294: /* original 9021, guest PC 0x0c036294 */
if(!s->budget--) { s->failed_pc=0x0c036294u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0362dau,2);
goto P_0c036296;
P_0c036296: /* original 6412, guest PC 0x0c036296 */
if(!s->budget--) { s->failed_pc=0x0c036296u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c036298;
P_0c036298: /* original 034e, guest PC 0x0c036298 */
if(!s->budget--) { s->failed_pc=0x0c036298u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c03629a;
P_0c03629a: /* original 2338, guest PC 0x0c03629a */
if(!s->budget--) { s->failed_pc=0x0c03629au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03629c;
P_0c03629c: /* original 8d07, guest PC 0x0c03629c */
if(!s->budget--) { s->failed_pc=0x0c03629cu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c0362ae; }
goto P_0c0362a0;
P_0c03629e: /* original 7f04, guest PC 0x0c03629e */
if(!s->budget--) { s->failed_pc=0x0c03629eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0362a0;
P_0c0362a0: /* original d313, guest PC 0x0c0362a0 */
if(!s->budget--) { s->failed_pc=0x0c0362a0u; return 0; }
r[3]=read(ram,0x0c0362f0u,4);
goto P_0c0362a2;
P_0c0362a2: /* original b173, guest PC 0x0c0362a2 */
if(!s->budget--) { s->failed_pc=0x0c0362a2u; return 0; }
target=code_base|0x0c03658cu; r[16]=code_base|0x0c0362a6u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0362a6u) { target=s->pc; goto dispatch; }
goto P_0c0362a6;
P_0c0362a4: /* original 2f36, guest PC 0x0c0362a4 */
if(!s->budget--) { s->failed_pc=0x0c0362a4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0362a6;
P_0c0362a6: /* original 7f04, guest PC 0x0c0362a6 */
if(!s->budget--) { s->failed_pc=0x0c0362a6u; return 0; }
r[15]+=0x00000004u;
goto P_0c0362a8;
P_0c0362a8: /* original 4f26, guest PC 0x0c0362a8 */
if(!s->budget--) { s->failed_pc=0x0c0362a8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0362aa;
P_0c0362aa: /* original 000b, guest PC 0x0c0362aa */
if(!s->budget--) { s->failed_pc=0x0c0362aau; return 0; }
target=r[16];
r[0]=0xfffffffdu;
s->pc=target; return ram->oob==0;
P_0c0362ac: /* original e0fd, guest PC 0x0c0362ac */
if(!s->budget--) { s->failed_pc=0x0c0362acu; return 0; }
r[0]=0xfffffffdu;
goto P_0c0362ae;
P_0c0362ae: /* original 900e, guest PC 0x0c0362ae */
if(!s->budget--) { s->failed_pc=0x0c0362aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0362ceu,2);
goto P_0c0362b0;
P_0c0362b0: /* original 034e, guest PC 0x0c0362b0 */
if(!s->budget--) { s->failed_pc=0x0c0362b0u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0362b2;
P_0c0362b2: /* original 5036, guest PC 0x0c0362b2 */
if(!s->budget--) { s->failed_pc=0x0c0362b2u; return 0; }
r[0]=read(ram,r[3]+24,4);
goto P_0c0362b4;
P_0c0362b4: /* original c801, guest PC 0x0c0362b4 */
if(!s->budget--) { s->failed_pc=0x0c0362b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0362b6;
P_0c0362b6: /* original 891f, guest PC 0x0c0362b6 */
if(!s->budget--) { s->failed_pc=0x0c0362b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0362f8; }
goto P_0c0362b8;
P_0c0362b8: /* original d20e, guest PC 0x0c0362b8 */
if(!s->budget--) { s->failed_pc=0x0c0362b8u; return 0; }
r[2]=read(ram,0x0c0362f4u,4);
goto P_0c0362ba;
P_0c0362ba: /* original b167, guest PC 0x0c0362ba */
if(!s->budget--) { s->failed_pc=0x0c0362bau; return 0; }
target=code_base|0x0c03658cu; r[16]=code_base|0x0c0362beu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0362beu) { target=s->pc; goto dispatch; }
goto P_0c0362be;
P_0c0362bc: /* original 2f26, guest PC 0x0c0362bc */
if(!s->budget--) { s->failed_pc=0x0c0362bcu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0362be;
P_0c0362be: /* original 7f04, guest PC 0x0c0362be */
if(!s->budget--) { s->failed_pc=0x0c0362beu; return 0; }
r[15]+=0x00000004u;
goto P_0c0362c0;
P_0c0362c0: /* original 4f26, guest PC 0x0c0362c0 */
if(!s->budget--) { s->failed_pc=0x0c0362c0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0362c2;
P_0c0362c2: /* original 000b, guest PC 0x0c0362c2 */
if(!s->budget--) { s->failed_pc=0x0c0362c2u; return 0; }
target=r[16];
r[0]=0xffffffffu;
s->pc=target; return ram->oob==0;
P_0c0362c4: /* original e0ff, guest PC 0x0c0362c4 */
if(!s->budget--) { s->failed_pc=0x0c0362c4u; return 0; }
r[0]=0xffffffffu;
if(!vf3_matrix_family(0x0c0362c6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0362c6u; return 0; } return 1;
P_0c0362f8: /* original d23b, guest PC 0x0c0362f8 */
if(!s->budget--) { s->failed_pc=0x0c0362f8u; return 0; }
r[2]=read(ram,0x0c0363e8u,4);
goto P_0c0362fa;
P_0c0362fa: /* original b147, guest PC 0x0c0362fa */
if(!s->budget--) { s->failed_pc=0x0c0362fau; return 0; }
target=code_base|0x0c03658cu; r[16]=code_base|0x0c0362feu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0362feu) { target=s->pc; goto dispatch; }
goto P_0c0362fe;
P_0c0362fc: /* original 2f26, guest PC 0x0c0362fc */
if(!s->budget--) { s->failed_pc=0x0c0362fcu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0362fe;
P_0c0362fe: /* original d33b, guest PC 0x0c0362fe */
if(!s->budget--) { s->failed_pc=0x0c0362feu; return 0; }
r[3]=read(ram,0x0c0363ecu,4);
goto P_0c036300;
P_0c036300: /* original 6032, guest PC 0x0c036300 */
if(!s->budget--) { s->failed_pc=0x0c036300u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c036302;
P_0c036302: /* original 401b, guest PC 0x0c036302 */
if(!s->budget--) { s->failed_pc=0x0c036302u; return 0; }
tmp=read(ram,r[0],1);
r[17]=(r[17]&~1u)|((tmp==0)!=0);
write(ram,r[0],tmp|0x80u,1);
goto P_0c036304;
P_0c036304: /* original 8d07, guest PC 0x0c036304 */
if(!s->budget--) { s->failed_pc=0x0c036304u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { return vf3_matrix_family(0x0c036316u,s,ram); }
goto P_0c036308;
P_0c036306: /* original 7f04, guest PC 0x0c036306 */
if(!s->budget--) { s->failed_pc=0x0c036306u; return 0; }
r[15]+=0x00000004u;
goto P_0c036308;
P_0c036308: /* original d139, guest PC 0x0c036308 */
if(!s->budget--) { s->failed_pc=0x0c036308u; return 0; }
r[1]=read(ram,0x0c0363f0u,4);
goto P_0c03630a;
P_0c03630a: /* original b13f, guest PC 0x0c03630a */
if(!s->budget--) { s->failed_pc=0x0c03630au; return 0; }
target=code_base|0x0c03658cu; r[16]=code_base|0x0c03630eu;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03630eu) { target=s->pc; goto dispatch; }
goto P_0c03630e;
P_0c03630c: /* original 2f16, guest PC 0x0c03630c */
if(!s->budget--) { s->failed_pc=0x0c03630cu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03630e;
P_0c03630e: /* original 7f04, guest PC 0x0c03630e */
if(!s->budget--) { s->failed_pc=0x0c03630eu; return 0; }
r[15]+=0x00000004u;
goto P_0c036310;
P_0c036310: /* original 4f26, guest PC 0x0c036310 */
if(!s->budget--) { s->failed_pc=0x0c036310u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c036312;
P_0c036312: /* original 000b, guest PC 0x0c036312 */
if(!s->budget--) { s->failed_pc=0x0c036312u; return 0; }
target=r[16];
r[0]=0xfffffffeu;
s->pc=target; return ram->oob==0;
P_0c036314: /* original e0fe, guest PC 0x0c036314 */
if(!s->budget--) { s->failed_pc=0x0c036314u; return 0; }
r[0]=0xfffffffeu;
return vf3_matrix_family(0x0c036316u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
