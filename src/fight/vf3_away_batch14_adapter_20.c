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
int vf3_away_batch14_adapter_20(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c089270u: goto P_0c089270;
case 0x0c089272u: goto P_0c089272;
case 0x0c089274u: goto P_0c089274;
case 0x0c089276u: goto P_0c089276;
case 0x0c089278u: goto P_0c089278;
case 0x0c08927au: goto P_0c08927a;
case 0x0c08927cu: goto P_0c08927c;
case 0x0c08927eu: goto P_0c08927e;
case 0x0c089280u: goto P_0c089280;
case 0x0c089282u: goto P_0c089282;
case 0x0c089284u: goto P_0c089284;
case 0x0c089286u: goto P_0c089286;
case 0x0c089288u: goto P_0c089288;
case 0x0c08928au: goto P_0c08928a;
case 0x0c08928cu: goto P_0c08928c;
case 0x0c08928eu: goto P_0c08928e;
case 0x0c089290u: goto P_0c089290;
case 0x0c089292u: goto P_0c089292;
case 0x0c089294u: goto P_0c089294;
case 0x0c089296u: goto P_0c089296;
case 0x0c089298u: goto P_0c089298;
case 0x0c0892b8u: goto P_0c0892b8;
case 0x0c0892bau: goto P_0c0892ba;
case 0x0c0892bcu: goto P_0c0892bc;
case 0x0c0892beu: goto P_0c0892be;
case 0x0c0892c0u: goto P_0c0892c0;
case 0x0c0892c2u: goto P_0c0892c2;
case 0x0c0892c4u: goto P_0c0892c4;
case 0x0c0892c6u: goto P_0c0892c6;
case 0x0c0892c8u: goto P_0c0892c8;
case 0x0c0892cau: goto P_0c0892ca;
case 0x0c0892ccu: goto P_0c0892cc;
case 0x0c0892ceu: goto P_0c0892ce;
case 0x0c0892d0u: goto P_0c0892d0;
case 0x0c0892d2u: goto P_0c0892d2;
case 0x0c0892d4u: goto P_0c0892d4;
case 0x0c0892d6u: goto P_0c0892d6;
case 0x0c0892d8u: goto P_0c0892d8;
case 0x0c0892dau: goto P_0c0892da;
case 0x0c0892dcu: goto P_0c0892dc;
case 0x0c0892deu: goto P_0c0892de;
case 0x0c0892e0u: goto P_0c0892e0;
case 0x0c0892e2u: goto P_0c0892e2;
case 0x0c0892e4u: goto P_0c0892e4;
case 0x0c0892e6u: goto P_0c0892e6;
case 0x0c0892e8u: goto P_0c0892e8;
case 0x0c0892eau: goto P_0c0892ea;
case 0x0c0892ecu: goto P_0c0892ec;
case 0x0c0892eeu: goto P_0c0892ee;
case 0x0c0892f0u: goto P_0c0892f0;
case 0x0c0892f2u: goto P_0c0892f2;
case 0x0c0892f4u: goto P_0c0892f4;
case 0x0c0892f6u: goto P_0c0892f6;
case 0x0c0892f8u: goto P_0c0892f8;
case 0x0c0892fau: goto P_0c0892fa;
case 0x0c0892fcu: goto P_0c0892fc;
case 0x0c0892feu: goto P_0c0892fe;
case 0x0c089300u: goto P_0c089300;
case 0x0c089302u: goto P_0c089302;
case 0x0c089304u: goto P_0c089304;
case 0x0c089306u: goto P_0c089306;
case 0x0c089308u: goto P_0c089308;
case 0x0c08930au: goto P_0c08930a;
case 0x0c08930cu: goto P_0c08930c;
case 0x0c08930eu: goto P_0c08930e;
case 0x0c089310u: goto P_0c089310;
case 0x0c089312u: goto P_0c089312;
case 0x0c089314u: goto P_0c089314;
case 0x0c089316u: goto P_0c089316;
case 0x0c089318u: goto P_0c089318;
case 0x0c08931au: goto P_0c08931a;
case 0x0c08931cu: goto P_0c08931c;
case 0x0c08931eu: goto P_0c08931e;
case 0x0c089320u: goto P_0c089320;
case 0x0c089322u: goto P_0c089322;
case 0x0c089324u: goto P_0c089324;
case 0x0c089326u: goto P_0c089326;
case 0x0c089328u: goto P_0c089328;
case 0x0c08932au: goto P_0c08932a;
case 0x0c08932cu: goto P_0c08932c;
case 0x0c08932eu: goto P_0c08932e;
case 0x0c089330u: goto P_0c089330;
case 0x0c089332u: goto P_0c089332;
case 0x0c089334u: goto P_0c089334;
case 0x0c089336u: goto P_0c089336;
case 0x0c089338u: goto P_0c089338;
case 0x0c08933au: goto P_0c08933a;
case 0x0c08933cu: goto P_0c08933c;
case 0x0c08933eu: goto P_0c08933e;
case 0x0c089340u: goto P_0c089340;
case 0x0c089342u: goto P_0c089342;
case 0x0c089344u: goto P_0c089344;
case 0x0c089346u: goto P_0c089346;
case 0x0c089764u: goto P_0c089764;
case 0x0c089766u: goto P_0c089766;
case 0x0c089768u: goto P_0c089768;
case 0x0c08976au: goto P_0c08976a;
case 0x0c08976cu: goto P_0c08976c;
case 0x0c08976eu: goto P_0c08976e;
case 0x0c089770u: goto P_0c089770;
case 0x0c089772u: goto P_0c089772;
case 0x0c089774u: goto P_0c089774;
case 0x0c089776u: goto P_0c089776;
case 0x0c089778u: goto P_0c089778;
case 0x0c08977au: goto P_0c08977a;
case 0x0c08977cu: goto P_0c08977c;
case 0x0c08977eu: goto P_0c08977e;
case 0x0c089780u: goto P_0c089780;
case 0x0c089782u: goto P_0c089782;
case 0x0c089784u: goto P_0c089784;
case 0x0c089786u: goto P_0c089786;
case 0x0c089788u: goto P_0c089788;
case 0x0c08978au: goto P_0c08978a;
case 0x0c08978cu: goto P_0c08978c;
case 0x0c08978eu: goto P_0c08978e;
case 0x0c089790u: goto P_0c089790;
case 0x0c089792u: goto P_0c089792;
case 0x0c089794u: goto P_0c089794;
case 0x0c089796u: goto P_0c089796;
case 0x0c089798u: goto P_0c089798;
case 0x0c08979au: goto P_0c08979a;
case 0x0c08979cu: goto P_0c08979c;
case 0x0c08979eu: goto P_0c08979e;
case 0x0c0897a0u: goto P_0c0897a0;
case 0x0c0897a2u: goto P_0c0897a2;
case 0x0c0897a4u: goto P_0c0897a4;
case 0x0c0897a6u: goto P_0c0897a6;
case 0x0c0897a8u: goto P_0c0897a8;
case 0x0c0897aau: goto P_0c0897aa;
case 0x0c0897acu: goto P_0c0897ac;
case 0x0c0897aeu: goto P_0c0897ae;
case 0x0c0897b0u: goto P_0c0897b0;
case 0x0c0897b2u: goto P_0c0897b2;
case 0x0c0897b4u: goto P_0c0897b4;
case 0x0c0897b6u: goto P_0c0897b6;
case 0x0c0897b8u: goto P_0c0897b8;
case 0x0c0897bau: goto P_0c0897ba;
case 0x0c0897bcu: goto P_0c0897bc;
case 0x0c0897beu: goto P_0c0897be;
case 0x0c0897c0u: goto P_0c0897c0;
case 0x0c0897c2u: goto P_0c0897c2;
case 0x0c0897c4u: goto P_0c0897c4;
case 0x0c0897c6u: goto P_0c0897c6;
case 0x0c0897c8u: goto P_0c0897c8;
case 0x0c0897cau: goto P_0c0897ca;
case 0x0c0897ccu: goto P_0c0897cc;
case 0x0c0897ceu: goto P_0c0897ce;
case 0x0c0897d0u: goto P_0c0897d0;
case 0x0c0897d2u: goto P_0c0897d2;
case 0x0c0897d4u: goto P_0c0897d4;
case 0x0c0897d6u: goto P_0c0897d6;
case 0x0c0897d8u: goto P_0c0897d8;
case 0x0c0897dau: goto P_0c0897da;
case 0x0c0897dcu: goto P_0c0897dc;
case 0x0c0897deu: goto P_0c0897de;
case 0x0c0897e0u: goto P_0c0897e0;
case 0x0c0897e2u: goto P_0c0897e2;
case 0x0c0897e4u: goto P_0c0897e4;
case 0x0c0897e6u: goto P_0c0897e6;
case 0x0c0897e8u: goto P_0c0897e8;
case 0x0c0897eau: goto P_0c0897ea;
case 0x0c0897ecu: goto P_0c0897ec;
case 0x0c0897eeu: goto P_0c0897ee;
case 0x0c0897f0u: goto P_0c0897f0;
case 0x0c0897f2u: goto P_0c0897f2;
case 0x0c0897f4u: goto P_0c0897f4;
case 0x0c0897f6u: goto P_0c0897f6;
case 0x0c0897f8u: goto P_0c0897f8;
case 0x0c0897fau: goto P_0c0897fa;
case 0x0c0897fcu: goto P_0c0897fc;
case 0x0c0897feu: goto P_0c0897fe;
case 0x0c089800u: goto P_0c089800;
case 0x0c089802u: goto P_0c089802;
case 0x0c089804u: goto P_0c089804;
case 0x0c089806u: goto P_0c089806;
case 0x0c089808u: goto P_0c089808;
case 0x0c08980au: goto P_0c08980a;
case 0x0c08980cu: goto P_0c08980c;
case 0x0c08980eu: goto P_0c08980e;
case 0x0c089810u: goto P_0c089810;
case 0x0c089812u: goto P_0c089812;
case 0x0c089814u: goto P_0c089814;
case 0x0c089816u: goto P_0c089816;
case 0x0c089818u: goto P_0c089818;
case 0x0c08981au: goto P_0c08981a;
case 0x0c08981cu: goto P_0c08981c;
case 0x0c08981eu: goto P_0c08981e;
case 0x0c089820u: goto P_0c089820;
case 0x0c089822u: goto P_0c089822;
case 0x0c089824u: goto P_0c089824;
case 0x0c089826u: goto P_0c089826;
case 0x0c089828u: goto P_0c089828;
case 0x0c08982au: goto P_0c08982a;
case 0x0c08982cu: goto P_0c08982c;
case 0x0c08982eu: goto P_0c08982e;
case 0x0c089830u: goto P_0c089830;
case 0x0c089832u: goto P_0c089832;
case 0x0c089834u: goto P_0c089834;
case 0x0c089836u: goto P_0c089836;
case 0x0c089838u: goto P_0c089838;
case 0x0c08983au: goto P_0c08983a;
case 0x0c08983cu: goto P_0c08983c;
case 0x0c08983eu: goto P_0c08983e;
case 0x0c089840u: goto P_0c089840;
case 0x0c089842u: goto P_0c089842;
case 0x0c089844u: goto P_0c089844;
case 0x0c089846u: goto P_0c089846;
case 0x0c089848u: goto P_0c089848;
case 0x0c08984au: goto P_0c08984a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c089270: /* original 2fe6, guest PC 0x0c089270 */
if(!s->budget--) { s->failed_pc=0x0c089270u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089272;
P_0c089272: /* original 2fd6, guest PC 0x0c089272 */
if(!s->budget--) { s->failed_pc=0x0c089272u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089274;
P_0c089274: /* original 2fc6, guest PC 0x0c089274 */
if(!s->budget--) { s->failed_pc=0x0c089274u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089276;
P_0c089276: /* original 2fb6, guest PC 0x0c089276 */
if(!s->budget--) { s->failed_pc=0x0c089276u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089278;
P_0c089278: /* original 2fa6, guest PC 0x0c089278 */
if(!s->budget--) { s->failed_pc=0x0c089278u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08927a;
P_0c08927a: /* original 2f96, guest PC 0x0c08927a */
if(!s->budget--) { s->failed_pc=0x0c08927au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08927c;
P_0c08927c: /* original 2f86, guest PC 0x0c08927c */
if(!s->budget--) { s->failed_pc=0x0c08927cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08927e;
P_0c08927e: /* original 4f22, guest PC 0x0c08927e */
if(!s->budget--) { s->failed_pc=0x0c08927eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c089280;
P_0c089280: /* original 7ffc, guest PC 0x0c089280 */
if(!s->budget--) { s->failed_pc=0x0c089280u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c089282;
P_0c089282: /* original 2f42, guest PC 0x0c089282 */
if(!s->budget--) { s->failed_pc=0x0c089282u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c089284;
P_0c089284: /* original d106, guest PC 0x0c089284 */
if(!s->budget--) { s->failed_pc=0x0c089284u; return 0; }
r[1]=read(ram,0x0c0892a0u,4);
goto P_0c089286;
P_0c089286: /* original d305, guest PC 0x0c089286 */
if(!s->budget--) { s->failed_pc=0x0c089286u; return 0; }
r[3]=read(ram,0x0c08929cu,4);
goto P_0c089288;
P_0c089288: /* original 6212, guest PC 0x0c089288 */
if(!s->budget--) { s->failed_pc=0x0c089288u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c08928a;
P_0c08928a: /* original 2238, guest PC 0x0c08928a */
if(!s->budget--) { s->failed_pc=0x0c08928au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c08928c;
P_0c08928c: /* original 8b52, guest PC 0x0c08928c */
if(!s->budget--) { s->failed_pc=0x0c08928cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089334; }
goto P_0c08928e;
P_0c08928e: /* original 9904, guest PC 0x0c08928e */
if(!s->budget--) { s->failed_pc=0x0c08928eu; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08929au,2);
goto P_0c089290;
P_0c089290: /* original eb00, guest PC 0x0c089290 */
if(!s->budget--) { s->failed_pc=0x0c089290u; return 0; }
r[11]=0x00000000u;
goto P_0c089292;
P_0c089292: /* original ea1a, guest PC 0x0c089292 */
if(!s->budget--) { s->failed_pc=0x0c089292u; return 0; }
r[10]=0x0000001au;
goto P_0c089294;
P_0c089294: /* original e802, guest PC 0x0c089294 */
if(!s->budget--) { s->failed_pc=0x0c089294u; return 0; }
r[8]=0x00000002u;
goto P_0c089296;
P_0c089296: /* original a04b, guest PC 0x0c089296 */
if(!s->budget--) { s->failed_pc=0x0c089296u; return 0; }
r[12]=0x00000005u;
goto P_0c089330;
P_0c089298: /* original ec05, guest PC 0x0c089298 */
if(!s->budget--) { s->failed_pc=0x0c089298u; return 0; }
r[12]=0x00000005u;
if(!vf3_matrix_family(0x0c08929au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08929au; return 0; } return 1;
P_0c0892b8: /* original 64c3, guest PC 0x0c0892b8 */
if(!s->budget--) { s->failed_pc=0x0c0892b8u; return 0; }
r[4]=r[12];
goto P_0c0892ba;
P_0c0892ba: /* original 74ff, guest PC 0x0c0892ba */
if(!s->budget--) { s->failed_pc=0x0c0892bau; return 0; }
r[4]+=0xffffffffu;
goto P_0c0892bc;
P_0c0892bc: /* original 6e43, guest PC 0x0c0892bc */
if(!s->budget--) { s->failed_pc=0x0c0892bcu; return 0; }
r[14]=r[4];
goto P_0c0892be;
P_0c0892be: /* original 60f2, guest PC 0x0c0892be */
if(!s->budget--) { s->failed_pc=0x0c0892beu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0892c0;
P_0c0892c0: /* original 4e08, guest PC 0x0c0892c0 */
if(!s->budget--) { s->failed_pc=0x0c0892c0u; return 0; }
r[14]<<=2;
goto P_0c0892c2;
P_0c0892c2: /* original 0eee, guest PC 0x0c0892c2 */
if(!s->budget--) { s->failed_pc=0x0c0892c2u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c0892c4;
P_0c0892c4: /* original e032, guest PC 0x0c0892c4 */
if(!s->budget--) { s->failed_pc=0x0c0892c4u; return 0; }
r[0]=0x00000032u;
goto P_0c0892c6;
P_0c0892c6: /* original 04ec, guest PC 0x0c0892c6 */
if(!s->budget--) { s->failed_pc=0x0c0892c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0892c8;
P_0c0892c8: /* original 2448, guest PC 0x0c0892c8 */
if(!s->budget--) { s->failed_pc=0x0c0892c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0892ca;
P_0c0892ca: /* original 6d43, guest PC 0x0c0892ca */
if(!s->budget--) { s->failed_pc=0x0c0892cau; return 0; }
r[13]=r[4];
goto P_0c0892cc;
P_0c0892cc: /* original 8f09, guest PC 0x0c0892cc */
if(!s->budget--) { s->failed_pc=0x0c0892ccu; return 0; }
cond=r[17]&1u;
r[13]+=0xffffffffu;
if(!cond) { goto P_0c0892e2; }
goto P_0c0892d0;
P_0c0892ce: /* original 7dff, guest PC 0x0c0892ce */
if(!s->budget--) { s->failed_pc=0x0c0892ceu; return 0; }
r[13]+=0xffffffffu;
goto P_0c0892d0;
P_0c0892d0: /* original d23e, guest PC 0x0c0892d0 */
if(!s->budget--) { s->failed_pc=0x0c0892d0u; return 0; }
r[2]=read(ram,0x0c0893ccu,4);
goto P_0c0892d2;
P_0c0892d2: /* original 420b, guest PC 0x0c0892d2 */
if(!s->budget--) { s->failed_pc=0x0c0892d2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0892d6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0892d6u) { target=s->pc; goto dispatch; }
goto P_0c0892d6;
P_0c0892d4: /* original 0009, guest PC 0x0c0892d4 */
if(!s->budget--) { s->failed_pc=0x0c0892d4u; return 0; }
goto P_0c0892d6;
P_0c0892d6: /* original ed7f, guest PC 0x0c0892d6 */
if(!s->budget--) { s->failed_pc=0x0c0892d6u; return 0; }
r[13]=0x0000007fu;
goto P_0c0892d8;
P_0c0892d8: /* original 6403, guest PC 0x0c0892d8 */
if(!s->budget--) { s->failed_pc=0x0c0892d8u; return 0; }
r[4]=r[0];
goto P_0c0892da;
P_0c0892da: /* original 2d49, guest PC 0x0c0892da */
if(!s->budget--) { s->failed_pc=0x0c0892dau; return 0; }
r[13]&=r[4];
goto P_0c0892dc;
P_0c0892dc: /* original e030, guest PC 0x0c0892dc */
if(!s->budget--) { s->failed_pc=0x0c0892dcu; return 0; }
r[0]=0x00000030u;
goto P_0c0892de;
P_0c0892de: /* original 2499, guest PC 0x0c0892de */
if(!s->budget--) { s->failed_pc=0x0c0892deu; return 0; }
r[4]&=r[9];
goto P_0c0892e0;
P_0c0892e0: /* original 0e45, guest PC 0x0c0892e0 */
if(!s->budget--) { s->failed_pc=0x0c0892e0u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0892e2;
P_0c0892e2: /* original e032, guest PC 0x0c0892e2 */
if(!s->budget--) { s->failed_pc=0x0c0892e2u; return 0; }
r[0]=0x00000032u;
goto P_0c0892e4;
P_0c0892e4: /* original e330, guest PC 0x0c0892e4 */
if(!s->budget--) { s->failed_pc=0x0c0892e4u; return 0; }
r[3]=0x00000030u;
goto P_0c0892e6;
P_0c0892e6: /* original 0ed4, guest PC 0x0c0892e6 */
if(!s->budget--) { s->failed_pc=0x0c0892e6u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0892e8;
P_0c0892e8: /* original 33ec, guest PC 0x0c0892e8 */
if(!s->budget--) { s->failed_pc=0x0c0892e8u; return 0; }
r[3]+=r[14];
goto P_0c0892ea;
P_0c0892ea: /* original e02e, guest PC 0x0c0892ea */
if(!s->budget--) { s->failed_pc=0x0c0892eau; return 0; }
r[0]=0x0000002eu;
goto P_0c0892ec;
P_0c0892ec: /* original 6331, guest PC 0x0c0892ec */
if(!s->budget--) { s->failed_pc=0x0c0892ecu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[3]=tmp;
goto P_0c0892ee;
P_0c0892ee: /* original 02ed, guest PC 0x0c0892ee */
if(!s->budget--) { s->failed_pc=0x0c0892eeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0892f0;
P_0c0892f0: /* original 323c, guest PC 0x0c0892f0 */
if(!s->budget--) { s->failed_pc=0x0c0892f0u; return 0; }
r[2]+=r[3];
goto P_0c0892f2;
P_0c0892f2: /* original 0e25, guest PC 0x0c0892f2 */
if(!s->budget--) { s->failed_pc=0x0c0892f2u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0892f4;
P_0c0892f4: /* original bdfc, guest PC 0x0c0892f4 */
if(!s->budget--) { s->failed_pc=0x0c0892f4u; return 0; }
target=code_base|0x0c088ef0u; r[16]=code_base|0x0c0892f8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0892f8u) { target=s->pc; goto dispatch; }
goto P_0c0892f8;
P_0c0892f6: /* original 64e3, guest PC 0x0c0892f6 */
if(!s->budget--) { s->failed_pc=0x0c0892f6u; return 0; }
r[4]=r[14];
goto P_0c0892f8;
P_0c0892f8: /* original 3c87, guest PC 0x0c0892f8 */
if(!s->budget--) { s->failed_pc=0x0c0892f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>(int32_t)r[8])!=0);
goto P_0c0892fa;
P_0c0892fa: /* original 8b08, guest PC 0x0c0892fa */
if(!s->budget--) { s->failed_pc=0x0c0892fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08930e; }
goto P_0c0892fc;
P_0c0892fc: /* original 85e5, guest PC 0x0c0892fc */
if(!s->budget--) { s->failed_pc=0x0c0892fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+10,2);
goto P_0c0892fe;
P_0c0892fe: /* original 6d03, guest PC 0x0c0892fe */
if(!s->budget--) { s->failed_pc=0x0c0892feu; return 0; }
r[13]=r[0];
goto P_0c089300;
P_0c089300: /* original 7d01, guest PC 0x0c089300 */
if(!s->budget--) { s->failed_pc=0x0c089300u; return 0; }
r[13]+=0x00000001u;
goto P_0c089302;
P_0c089302: /* original 3da3, guest PC 0x0c089302 */
if(!s->budget--) { s->failed_pc=0x0c089302u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[10])!=0);
goto P_0c089304;
P_0c089304: /* original 8b03, guest PC 0x0c089304 */
if(!s->budget--) { s->failed_pc=0x0c089304u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08930e; }
goto P_0c089306;
P_0c089306: /* original 65c3, guest PC 0x0c089306 */
if(!s->budget--) { s->failed_pc=0x0c089306u; return 0; }
r[5]=r[12];
goto P_0c089308;
P_0c089308: /* original be6a, guest PC 0x0c089308 */
if(!s->budget--) { s->failed_pc=0x0c089308u; return 0; }
target=code_base|0x0c088fe0u; r[16]=code_base|0x0c08930cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08930cu) { target=s->pc; goto dispatch; }
goto P_0c08930c;
P_0c08930a: /* original 64e3, guest PC 0x0c08930a */
if(!s->budget--) { s->failed_pc=0x0c08930au; return 0; }
r[4]=r[14];
goto P_0c08930c;
P_0c08930c: /* original 6db3, guest PC 0x0c08930c */
if(!s->budget--) { s->failed_pc=0x0c08930cu; return 0; }
r[13]=r[11];
goto P_0c08930e;
P_0c08930e: /* original 60d3, guest PC 0x0c08930e */
if(!s->budget--) { s->failed_pc=0x0c08930eu; return 0; }
r[0]=r[13];
goto P_0c089310;
P_0c089310: /* original 81e5, guest PC 0x0c089310 */
if(!s->budget--) { s->failed_pc=0x0c089310u; return 0; }
write(ram,r[14]+10,r[0],2);
goto P_0c089312;
P_0c089312: /* original 85e4, guest PC 0x0c089312 */
if(!s->budget--) { s->failed_pc=0x0c089312u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+8,2);
goto P_0c089314;
P_0c089314: /* original 6403, guest PC 0x0c089314 */
if(!s->budget--) { s->failed_pc=0x0c089314u; return 0; }
r[4]=r[0];
goto P_0c089316;
P_0c089316: /* original e02c, guest PC 0x0c089316 */
if(!s->budget--) { s->failed_pc=0x0c089316u; return 0; }
r[0]=0x0000002cu;
goto P_0c089318;
P_0c089318: /* original 05ec, guest PC 0x0c089318 */
if(!s->budget--) { s->failed_pc=0x0c089318u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08931a;
P_0c08931a: /* original 3453, guest PC 0x0c08931a */
if(!s->budget--) { s->failed_pc=0x0c08931au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c08931c;
P_0c08931c: /* original 8b04, guest PC 0x0c08931c */
if(!s->budget--) { s->failed_pc=0x0c08931cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089328; }
goto P_0c08931e;
P_0c08931e: /* original 65c3, guest PC 0x0c08931e */
if(!s->budget--) { s->failed_pc=0x0c08931eu; return 0; }
r[5]=r[12];
goto P_0c089320;
P_0c089320: /* original beb2, guest PC 0x0c089320 */
if(!s->budget--) { s->failed_pc=0x0c089320u; return 0; }
target=code_base|0x0c089088u; r[16]=code_base|0x0c089324u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c089324u) { target=s->pc; goto dispatch; }
goto P_0c089324;
P_0c089322: /* original 64e3, guest PC 0x0c089322 */
if(!s->budget--) { s->failed_pc=0x0c089322u; return 0; }
r[4]=r[14];
goto P_0c089324;
P_0c089324: /* original a001, guest PC 0x0c089324 */
if(!s->budget--) { s->failed_pc=0x0c089324u; return 0; }
r[4]=r[11];
goto P_0c08932a;
P_0c089326: /* original 64b3, guest PC 0x0c089326 */
if(!s->budget--) { s->failed_pc=0x0c089326u; return 0; }
r[4]=r[11];
goto P_0c089328;
P_0c089328: /* original 7401, guest PC 0x0c089328 */
if(!s->budget--) { s->failed_pc=0x0c089328u; return 0; }
r[4]+=0x00000001u;
goto P_0c08932a;
P_0c08932a: /* original 6043, guest PC 0x0c08932a */
if(!s->budget--) { s->failed_pc=0x0c08932au; return 0; }
r[0]=r[4];
goto P_0c08932c;
P_0c08932c: /* original 7cff, guest PC 0x0c08932c */
if(!s->budget--) { s->failed_pc=0x0c08932cu; return 0; }
r[12]+=0xffffffffu;
goto P_0c08932e;
P_0c08932e: /* original 81e4, guest PC 0x0c08932e */
if(!s->budget--) { s->failed_pc=0x0c08932eu; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c089330;
P_0c089330: /* original 2cc8, guest PC 0x0c089330 */
if(!s->budget--) { s->failed_pc=0x0c089330u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c089332;
P_0c089332: /* original 8bc1, guest PC 0x0c089332 */
if(!s->budget--) { s->failed_pc=0x0c089332u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0892b8; }
goto P_0c089334;
P_0c089334: /* original 7f04, guest PC 0x0c089334 */
if(!s->budget--) { s->failed_pc=0x0c089334u; return 0; }
r[15]+=0x00000004u;
goto P_0c089336;
P_0c089336: /* original 4f26, guest PC 0x0c089336 */
if(!s->budget--) { s->failed_pc=0x0c089336u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c089338;
P_0c089338: /* original 68f6, guest PC 0x0c089338 */
if(!s->budget--) { s->failed_pc=0x0c089338u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08933a;
P_0c08933a: /* original 69f6, guest PC 0x0c08933a */
if(!s->budget--) { s->failed_pc=0x0c08933au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08933c;
P_0c08933c: /* original 6af6, guest PC 0x0c08933c */
if(!s->budget--) { s->failed_pc=0x0c08933cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08933e;
P_0c08933e: /* original 6bf6, guest PC 0x0c08933e */
if(!s->budget--) { s->failed_pc=0x0c08933eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c089340;
P_0c089340: /* original 6cf6, guest PC 0x0c089340 */
if(!s->budget--) { s->failed_pc=0x0c089340u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c089342;
P_0c089342: /* original 6df6, guest PC 0x0c089342 */
if(!s->budget--) { s->failed_pc=0x0c089342u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c089344;
P_0c089344: /* original 000b, guest PC 0x0c089344 */
if(!s->budget--) { s->failed_pc=0x0c089344u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c089346: /* original 6ef6, guest PC 0x0c089346 */
if(!s->budget--) { s->failed_pc=0x0c089346u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c089348u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c089348u; return 0; } return 1;
P_0c089764: /* original f571, guest PC 0x0c089764 */
if(!s->budget--) { s->failed_pc=0x0c089764u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'-');
goto P_0c089766;
P_0c089766: /* original 2fe6, guest PC 0x0c089766 */
if(!s->budget--) { s->failed_pc=0x0c089766u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089768;
P_0c089768: /* original f461, guest PC 0x0c089768 */
if(!s->budget--) { s->failed_pc=0x0c089768u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
goto P_0c08976a;
P_0c08976a: /* original 6e53, guest PC 0x0c08976a */
if(!s->budget--) { s->failed_pc=0x0c08976au; return 0; }
r[14]=r[5];
goto P_0c08976c;
P_0c08976c: /* original 4f22, guest PC 0x0c08976c */
if(!s->budget--) { s->failed_pc=0x0c08976cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08976e;
P_0c08976e: /* original c74b, guest PC 0x0c08976e */
if(!s->budget--) { s->failed_pc=0x0c08976eu; return 0; }
r[0]=code_base|0x0008989cu;
goto P_0c089770;
P_0c089770: /* original 7ffc, guest PC 0x0c089770 */
if(!s->budget--) { s->failed_pc=0x0c089770u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c089772;
P_0c089772: /* original 2f62, guest PC 0x0c089772 */
if(!s->budget--) { s->failed_pc=0x0c089772u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c089774;
P_0c089774: /* original f35c, guest PC 0x0c089774 */
if(!s->budget--) { s->failed_pc=0x0c089774u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c089776;
P_0c089776: /* original f352, guest PC 0x0c089776 */
if(!s->budget--) { s->failed_pc=0x0c089776u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c089778;
P_0c089778: /* original f04c, guest PC 0x0c089778 */
if(!s->budget--) { s->failed_pc=0x0c089778u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c08977a;
P_0c08977a: /* original f34e, guest PC 0x0c08977a */
if(!s->budget--) { s->failed_pc=0x0c08977au; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c08977c;
P_0c08977c: /* original f53c, guest PC 0x0c08977c */
if(!s->budget--) { s->failed_pc=0x0c08977cu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c08977e;
P_0c08977e: /* original f585, guest PC 0x0c08977e */
if(!s->budget--) { s->failed_pc=0x0c08977eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[8]))!=0);
goto P_0c089780;
P_0c089780: /* original 8d21, guest PC 0x0c089780 */
if(!s->budget--) { s->failed_pc=0x0c089780u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,9,r[0]);
if(cond) { goto P_0c0897c6; }
goto P_0c089784;
P_0c089782: /* original f908, guest PC 0x0c089782 */
if(!s->budget--) { s->failed_pc=0x0c089782u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c089784;
P_0c089784: /* original f892, guest PC 0x0c089784 */
if(!s->budget--) { s->failed_pc=0x0c089784u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[9],r[18],'*');
goto P_0c089786;
P_0c089786: /* original e010, guest PC 0x0c089786 */
if(!s->budget--) { s->failed_pc=0x0c089786u; return 0; }
r[0]=0x00000010u;
goto P_0c089788;
P_0c089788: /* original f487, guest PC 0x0c089788 */
if(!s->budget--) { s->failed_pc=0x0c089788u; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c08978a;
P_0c08978a: /* original 55e9, guest PC 0x0c08978a */
if(!s->budget--) { s->failed_pc=0x0c08978au; return 0; }
r[5]=read(ram,r[14]+36,4);
goto P_0c08978c;
P_0c08978c: /* original 4515, guest PC 0x0c08978c */
if(!s->budget--) { s->failed_pc=0x0c08978cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>0)!=0);
goto P_0c08978e;
P_0c08978e: /* original 8914, guest PC 0x0c08978e */
if(!s->budget--) { s->failed_pc=0x0c08978eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0897ba; }
goto P_0c089790;
P_0c089790: /* original e016, guest PC 0x0c089790 */
if(!s->budget--) { s->failed_pc=0x0c089790u; return 0; }
r[0]=0x00000016u;
goto P_0c089792;
P_0c089792: /* original e303, guest PC 0x0c089792 */
if(!s->budget--) { s->failed_pc=0x0c089792u; return 0; }
r[3]=0x00000003u;
goto P_0c089794;
P_0c089794: /* original e2ff, guest PC 0x0c089794 */
if(!s->budget--) { s->failed_pc=0x0c089794u; return 0; }
r[2]=0xffffffffu;
goto P_0c089796;
P_0c089796: /* original 1e29, guest PC 0x0c089796 */
if(!s->budget--) { s->failed_pc=0x0c089796u; return 0; }
write(ram,r[14]+36,r[2],4);
goto P_0c089798;
P_0c089798: /* original 054c, guest PC 0x0c089798 */
if(!s->budget--) { s->failed_pc=0x0c089798u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c08979a;
P_0c08979a: /* original 3533, guest PC 0x0c08979a */
if(!s->budget--) { s->failed_pc=0x0c08979au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[3])!=0);
goto P_0c08979c;
P_0c08979c: /* original 890d, guest PC 0x0c08979c */
if(!s->budget--) { s->failed_pc=0x0c08979cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0897ba; }
goto P_0c08979e;
P_0c08979e: /* original 7501, guest PC 0x0c08979e */
if(!s->budget--) { s->failed_pc=0x0c08979eu; return 0; }
r[5]+=0x00000001u;
goto P_0c0897a0;
P_0c0897a0: /* original e20a, guest PC 0x0c0897a0 */
if(!s->budget--) { s->failed_pc=0x0c0897a0u; return 0; }
r[2]=0x0000000au;
goto P_0c0897a2;
P_0c0897a2: /* original 0454, guest PC 0x0c0897a2 */
if(!s->budget--) { s->failed_pc=0x0c0897a2u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0897a4;
P_0c0897a4: /* original d13e, guest PC 0x0c0897a4 */
if(!s->budget--) { s->failed_pc=0x0c0897a4u; return 0; }
r[1]=read(ram,0x0c0898a0u,4);
goto P_0c0897a6;
P_0c0897a6: /* original 410b, guest PC 0x0c0897a6 */
if(!s->budget--) { s->failed_pc=0x0c0897a6u; return 0; }
target=r[1];
r[16]=code_base|0x0c0897aau;
write(ram,r[14]+36,r[2],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0897aau) { target=s->pc; goto dispatch; }
goto P_0c0897aa;
P_0c0897a8: /* original 1e29, guest PC 0x0c0897a8 */
if(!s->budget--) { s->failed_pc=0x0c0897a8u; return 0; }
write(ram,r[14]+36,r[2],4);
goto P_0c0897aa;
P_0c0897aa: /* original e303, guest PC 0x0c0897aa */
if(!s->budget--) { s->failed_pc=0x0c0897aau; return 0; }
r[3]=0x00000003u;
goto P_0c0897ac;
P_0c0897ac: /* original 6403, guest PC 0x0c0897ac */
if(!s->budget--) { s->failed_pc=0x0c0897acu; return 0; }
r[4]=r[0];
goto P_0c0897ae;
P_0c0897ae: /* original d03d, guest PC 0x0c0897ae */
if(!s->budget--) { s->failed_pc=0x0c0897aeu; return 0; }
r[0]=read(ram,0x0c0898a4u,4);
goto P_0c0897b0;
P_0c0897b0: /* original 2439, guest PC 0x0c0897b0 */
if(!s->budget--) { s->failed_pc=0x0c0897b0u; return 0; }
r[4]&=r[3];
goto P_0c0897b2;
P_0c0897b2: /* original d23d, guest PC 0x0c0897b2 */
if(!s->budget--) { s->failed_pc=0x0c0897b2u; return 0; }
r[2]=read(ram,0x0c0898a8u,4);
goto P_0c0897b4;
P_0c0897b4: /* original 4408, guest PC 0x0c0897b4 */
if(!s->budget--) { s->failed_pc=0x0c0897b4u; return 0; }
r[4]<<=2;
goto P_0c0897b6;
P_0c0897b6: /* original 420b, guest PC 0x0c0897b6 */
if(!s->budget--) { s->failed_pc=0x0c0897b6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0897bau;
r[4]=read(ram,r[4]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0897bau) { target=s->pc; goto dispatch; }
goto P_0c0897ba;
P_0c0897b8: /* original 044e, guest PC 0x0c0897b8 */
if(!s->budget--) { s->failed_pc=0x0c0897b8u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c0897ba;
P_0c0897ba: /* original 63f2, guest PC 0x0c0897ba */
if(!s->budget--) { s->failed_pc=0x0c0897bau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0897bc;
P_0c0897bc: /* original e201, guest PC 0x0c0897bc */
if(!s->budget--) { s->failed_pc=0x0c0897bcu; return 0; }
r[2]=0x00000001u;
goto P_0c0897be;
P_0c0897be: /* original 2320, guest PC 0x0c0897be */
if(!s->budget--) { s->failed_pc=0x0c0897beu; return 0; }
write(ram,r[3],r[2],1);
goto P_0c0897c0;
P_0c0897c0: /* original 60f2, guest PC 0x0c0897c0 */
if(!s->budget--) { s->failed_pc=0x0c0897c0u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0897c2;
P_0c0897c2: /* original 6000, guest PC 0x0c0897c2 */
if(!s->budget--) { s->failed_pc=0x0c0897c2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[0],1);
r[0]=tmp;
goto P_0c0897c4;
P_0c0897c4: /* original 80eb, guest PC 0x0c0897c4 */
if(!s->budget--) { s->failed_pc=0x0c0897c4u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c0897c6;
P_0c0897c6: /* original 7f04, guest PC 0x0c0897c6 */
if(!s->budget--) { s->failed_pc=0x0c0897c6u; return 0; }
r[15]+=0x00000004u;
goto P_0c0897c8;
P_0c0897c8: /* original 4f26, guest PC 0x0c0897c8 */
if(!s->budget--) { s->failed_pc=0x0c0897c8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0897ca;
P_0c0897ca: /* original 000b, guest PC 0x0c0897ca */
if(!s->budget--) { s->failed_pc=0x0c0897cau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0897cc: /* original 6ef6, guest PC 0x0c0897cc */
if(!s->budget--) { s->failed_pc=0x0c0897ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0897ce;
P_0c0897ce: /* original c738, guest PC 0x0c0897ce */
if(!s->budget--) { s->failed_pc=0x0c0897ceu; return 0; }
r[0]=code_base|0x000898b0u;
goto P_0c0897d0;
P_0c0897d0: /* original 2fe6, guest PC 0x0c0897d0 */
if(!s->budget--) { s->failed_pc=0x0c0897d0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0897d2;
P_0c0897d2: /* original 2fd6, guest PC 0x0c0897d2 */
if(!s->budget--) { s->failed_pc=0x0c0897d2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0897d4;
P_0c0897d4: /* original ed00, guest PC 0x0c0897d4 */
if(!s->budget--) { s->failed_pc=0x0c0897d4u; return 0; }
r[13]=0x00000000u;
goto P_0c0897d6;
P_0c0897d6: /* original 2fc6, guest PC 0x0c0897d6 */
if(!s->budget--) { s->failed_pc=0x0c0897d6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0897d8;
P_0c0897d8: /* original 6e43, guest PC 0x0c0897d8 */
if(!s->budget--) { s->failed_pc=0x0c0897d8u; return 0; }
r[14]=r[4];
goto P_0c0897da;
P_0c0897da: /* original 2fb6, guest PC 0x0c0897da */
if(!s->budget--) { s->failed_pc=0x0c0897dau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0897dc;
P_0c0897dc: /* original eb20, guest PC 0x0c0897dc */
if(!s->budget--) { s->failed_pc=0x0c0897dcu; return 0; }
r[11]=0x00000020u;
goto P_0c0897de;
P_0c0897de: /* original 2fa6, guest PC 0x0c0897de */
if(!s->budget--) { s->failed_pc=0x0c0897deu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0897e0;
P_0c0897e0: /* original ea7f, guest PC 0x0c0897e0 */
if(!s->budget--) { s->failed_pc=0x0c0897e0u; return 0; }
r[10]=0x0000007fu;
goto P_0c0897e2;
P_0c0897e2: /* original 2f96, guest PC 0x0c0897e2 */
if(!s->budget--) { s->failed_pc=0x0c0897e2u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0897e4;
P_0c0897e4: /* original 7e18, guest PC 0x0c0897e4 */
if(!s->budget--) { s->failed_pc=0x0c0897e4u; return 0; }
r[14]+=0x00000018u;
goto P_0c0897e6;
P_0c0897e6: /* original fffb, guest PC 0x0c0897e6 */
if(!s->budget--) { s->failed_pc=0x0c0897e6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0897e8;
P_0c0897e8: /* original f308, guest PC 0x0c0897e8 */
if(!s->budget--) { s->failed_pc=0x0c0897e8u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0897ea;
P_0c0897ea: /* original e010, guest PC 0x0c0897ea */
if(!s->budget--) { s->failed_pc=0x0c0897eau; return 0; }
r[0]=0x00000010u;
goto P_0c0897ec;
P_0c0897ec: /* original 4f22, guest PC 0x0c0897ec */
if(!s->budget--) { s->failed_pc=0x0c0897ecu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0897ee;
P_0c0897ee: /* original dc2f, guest PC 0x0c0897ee */
if(!s->budget--) { s->failed_pc=0x0c0897eeu; return 0; }
r[12]=read(ram,0x0c0898acu,4);
goto P_0c0897f0;
P_0c0897f0: /* original f437, guest PC 0x0c0897f0 */
if(!s->budget--) { s->failed_pc=0x0c0897f0u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0897f2;
P_0c0897f2: /* original 60d3, guest PC 0x0c0897f2 */
if(!s->budget--) { s->failed_pc=0x0c0897f2u; return 0; }
r[0]=r[13];
goto P_0c0897f4;
P_0c0897f4: /* original 814a, guest PC 0x0c0897f4 */
if(!s->budget--) { s->failed_pc=0x0c0897f4u; return 0; }
write(ram,r[4]+20,r[0],2);
goto P_0c0897f6;
P_0c0897f6: /* original e016, guest PC 0x0c0897f6 */
if(!s->budget--) { s->failed_pc=0x0c0897f6u; return 0; }
r[0]=0x00000016u;
goto P_0c0897f8;
P_0c0897f8: /* original 04d4, guest PC 0x0c0897f8 */
if(!s->budget--) { s->failed_pc=0x0c0897f8u; return 0; }
write(ram,r[4]+r[0],r[13],1);
goto P_0c0897fa;
P_0c0897fa: /* original c72e, guest PC 0x0c0897fa */
if(!s->budget--) { s->failed_pc=0x0c0897fau; return 0; }
r[0]=code_base|0x000898b4u;
goto P_0c0897fc;
P_0c0897fc: /* original ff08, guest PC 0x0c0897fc */
if(!s->budget--) { s->failed_pc=0x0c0897fcu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0897fe;
P_0c0897fe: /* original d928, guest PC 0x0c0897fe */
if(!s->budget--) { s->failed_pc=0x0c0897feu; return 0; }
r[9]=read(ram,0x0c0898a0u,4);
goto P_0c089800;
P_0c089800: /* original f3c8, guest PC 0x0c089800 */
if(!s->budget--) { s->failed_pc=0x0c089800u; return 0; }
vf3_matrix_load(s,ram,3,r[12]);
goto P_0c089802;
P_0c089802: /* original e00c, guest PC 0x0c089802 */
if(!s->budget--) { s->failed_pc=0x0c089802u; return 0; }
r[0]=0x0000000cu;
goto P_0c089804;
P_0c089804: /* original fe37, guest PC 0x0c089804 */
if(!s->budget--) { s->failed_pc=0x0c089804u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089806;
P_0c089806: /* original e004, guest PC 0x0c089806 */
if(!s->budget--) { s->failed_pc=0x0c089806u; return 0; }
r[0]=0x00000004u;
goto P_0c089808;
P_0c089808: /* original f3c6, guest PC 0x0c089808 */
if(!s->budget--) { s->failed_pc=0x0c089808u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c08980a;
P_0c08980a: /* original e010, guest PC 0x0c08980a */
if(!s->budget--) { s->failed_pc=0x0c08980au; return 0; }
r[0]=0x00000010u;
goto P_0c08980c;
P_0c08980c: /* original fe37, guest PC 0x0c08980c */
if(!s->budget--) { s->failed_pc=0x0c08980cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08980e;
P_0c08980e: /* original e008, guest PC 0x0c08980e */
if(!s->budget--) { s->failed_pc=0x0c08980eu; return 0; }
r[0]=0x00000008u;
goto P_0c089810;
P_0c089810: /* original f3c6, guest PC 0x0c089810 */
if(!s->budget--) { s->failed_pc=0x0c089810u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c089812;
P_0c089812: /* original e014, guest PC 0x0c089812 */
if(!s->budget--) { s->failed_pc=0x0c089812u; return 0; }
r[0]=0x00000014u;
goto P_0c089814;
P_0c089814: /* original fe37, guest PC 0x0c089814 */
if(!s->budget--) { s->failed_pc=0x0c089814u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089816;
P_0c089816: /* original 84cc, guest PC 0x0c089816 */
if(!s->budget--) { s->failed_pc=0x0c089816u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+12,1);
goto P_0c089818;
P_0c089818: /* original 7c10, guest PC 0x0c089818 */
if(!s->budget--) { s->failed_pc=0x0c089818u; return 0; }
r[12]+=0x00000010u;
goto P_0c08981a;
P_0c08981a: /* original 80ea, guest PC 0x0c08981a */
if(!s->budget--) { s->failed_pc=0x0c08981au; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c08981c;
P_0c08981c: /* original e01c, guest PC 0x0c08981c */
if(!s->budget--) { s->failed_pc=0x0c08981cu; return 0; }
r[0]=0x0000001cu;
goto P_0c08981e;
P_0c08981e: /* original fef7, guest PC 0x0c08981e */
if(!s->budget--) { s->failed_pc=0x0c08981eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c089820;
P_0c089820: /* original 60d3, guest PC 0x0c089820 */
if(!s->budget--) { s->failed_pc=0x0c089820u; return 0; }
r[0]=r[13];
goto P_0c089822;
P_0c089822: /* original 81e3, guest PC 0x0c089822 */
if(!s->budget--) { s->failed_pc=0x0c089822u; return 0; }
write(ram,r[14]+6,r[0],2);
goto P_0c089824;
P_0c089824: /* original 80eb, guest PC 0x0c089824 */
if(!s->budget--) { s->failed_pc=0x0c089824u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c089826;
P_0c089826: /* original 1e09, guest PC 0x0c089826 */
if(!s->budget--) { s->failed_pc=0x0c089826u; return 0; }
write(ram,r[14]+36,r[0],4);
goto P_0c089828;
P_0c089828: /* original 490b, guest PC 0x0c089828 */
if(!s->budget--) { s->failed_pc=0x0c089828u; return 0; }
target=r[9];
r[16]=code_base|0x0c08982cu;
write(ram,r[14]+8,r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08982cu) { target=s->pc; goto dispatch; }
goto P_0c08982c;
P_0c08982a: /* original 81e4, guest PC 0x0c08982a */
if(!s->budget--) { s->failed_pc=0x0c08982au; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c08982c;
P_0c08982c: /* original 6403, guest PC 0x0c08982c */
if(!s->budget--) { s->failed_pc=0x0c08982cu; return 0; }
r[4]=r[0];
goto P_0c08982e;
P_0c08982e: /* original 24a9, guest PC 0x0c08982e */
if(!s->budget--) { s->failed_pc=0x0c08982eu; return 0; }
r[4]&=r[10];
goto P_0c089830;
P_0c089830: /* original 4b10, guest PC 0x0c089830 */
if(!s->budget--) { s->failed_pc=0x0c089830u; return 0; }
--r[11];
r[17]=(r[17]&~1u)|((r[11]==0)!=0);
goto P_0c089832;
P_0c089832: /* original 81e3, guest PC 0x0c089832 */
if(!s->budget--) { s->failed_pc=0x0c089832u; return 0; }
write(ram,r[14]+6,r[0],2);
goto P_0c089834;
P_0c089834: /* original 2e41, guest PC 0x0c089834 */
if(!s->budget--) { s->failed_pc=0x0c089834u; return 0; }
write(ram,r[14],r[4],2);
goto P_0c089836;
P_0c089836: /* original 8fe3, guest PC 0x0c089836 */
if(!s->budget--) { s->failed_pc=0x0c089836u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000028u;
if(!cond) { goto P_0c089800; }
goto P_0c08983a;
P_0c089838: /* original 7e28, guest PC 0x0c089838 */
if(!s->budget--) { s->failed_pc=0x0c089838u; return 0; }
r[14]+=0x00000028u;
goto P_0c08983a;
P_0c08983a: /* original 4f26, guest PC 0x0c08983a */
if(!s->budget--) { s->failed_pc=0x0c08983au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08983c;
P_0c08983c: /* original fff9, guest PC 0x0c08983c */
if(!s->budget--) { s->failed_pc=0x0c08983cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08983e;
P_0c08983e: /* original 69f6, guest PC 0x0c08983e */
if(!s->budget--) { s->failed_pc=0x0c08983eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c089840;
P_0c089840: /* original 6af6, guest PC 0x0c089840 */
if(!s->budget--) { s->failed_pc=0x0c089840u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c089842;
P_0c089842: /* original 6bf6, guest PC 0x0c089842 */
if(!s->budget--) { s->failed_pc=0x0c089842u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c089844;
P_0c089844: /* original 6cf6, guest PC 0x0c089844 */
if(!s->budget--) { s->failed_pc=0x0c089844u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c089846;
P_0c089846: /* original 6df6, guest PC 0x0c089846 */
if(!s->budget--) { s->failed_pc=0x0c089846u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c089848;
P_0c089848: /* original 000b, guest PC 0x0c089848 */
if(!s->budget--) { s->failed_pc=0x0c089848u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08984a: /* original 6ef6, guest PC 0x0c08984a */
if(!s->budget--) { s->failed_pc=0x0c08984au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08984cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
