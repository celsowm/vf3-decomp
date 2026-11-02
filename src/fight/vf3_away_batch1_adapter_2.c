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
int vf3_away_batch1_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c034f7cu: goto P_0c034f7c;
case 0x0c034f7eu: goto P_0c034f7e;
case 0x0c034f80u: goto P_0c034f80;
case 0x0c034f82u: goto P_0c034f82;
case 0x0c034f84u: goto P_0c034f84;
case 0x0c034f86u: goto P_0c034f86;
case 0x0c034f88u: goto P_0c034f88;
case 0x0c034f8au: goto P_0c034f8a;
case 0x0c034f8cu: goto P_0c034f8c;
case 0x0c034f8eu: goto P_0c034f8e;
case 0x0c034f90u: goto P_0c034f90;
case 0x0c034f92u: goto P_0c034f92;
case 0x0c034f94u: goto P_0c034f94;
case 0x0c034f96u: goto P_0c034f96;
case 0x0c034f98u: goto P_0c034f98;
case 0x0c034f9au: goto P_0c034f9a;
case 0x0c034f9cu: goto P_0c034f9c;
case 0x0c034f9eu: goto P_0c034f9e;
case 0x0c034fa0u: goto P_0c034fa0;
case 0x0c034fa2u: goto P_0c034fa2;
case 0x0c034fa4u: goto P_0c034fa4;
case 0x0c034fa6u: goto P_0c034fa6;
case 0x0c034fa8u: goto P_0c034fa8;
case 0x0c034faau: goto P_0c034faa;
case 0x0c034facu: goto P_0c034fac;
case 0x0c034faeu: goto P_0c034fae;
case 0x0c034fb0u: goto P_0c034fb0;
case 0x0c034fb2u: goto P_0c034fb2;
case 0x0c034fb4u: goto P_0c034fb4;
case 0x0c034fb6u: goto P_0c034fb6;
case 0x0c034fb8u: goto P_0c034fb8;
case 0x0c034fbau: goto P_0c034fba;
case 0x0c034fbcu: goto P_0c034fbc;
case 0x0c034fbeu: goto P_0c034fbe;
case 0x0c034fc0u: goto P_0c034fc0;
case 0x0c034fc2u: goto P_0c034fc2;
case 0x0c034fc4u: goto P_0c034fc4;
case 0x0c034fc6u: goto P_0c034fc6;
case 0x0c034fc8u: goto P_0c034fc8;
case 0x0c034fcau: goto P_0c034fca;
case 0x0c034fccu: goto P_0c034fcc;
case 0x0c034fceu: goto P_0c034fce;
case 0x0c034fd0u: goto P_0c034fd0;
case 0x0c034fd2u: goto P_0c034fd2;
case 0x0c034fd4u: goto P_0c034fd4;
case 0x0c034fd6u: goto P_0c034fd6;
case 0x0c034fd8u: goto P_0c034fd8;
case 0x0c034fdau: goto P_0c034fda;
case 0x0c034fdcu: goto P_0c034fdc;
case 0x0c034fdeu: goto P_0c034fde;
case 0x0c034fe0u: goto P_0c034fe0;
case 0x0c034fe2u: goto P_0c034fe2;
case 0x0c034fe4u: goto P_0c034fe4;
case 0x0c034fe6u: goto P_0c034fe6;
case 0x0c034fe8u: goto P_0c034fe8;
case 0x0c034feau: goto P_0c034fea;
case 0x0c034fecu: goto P_0c034fec;
case 0x0c034feeu: goto P_0c034fee;
case 0x0c034ff0u: goto P_0c034ff0;
case 0x0c034ff2u: goto P_0c034ff2;
case 0x0c034ff4u: goto P_0c034ff4;
case 0x0c034ff6u: goto P_0c034ff6;
case 0x0c034ff8u: goto P_0c034ff8;
case 0x0c034ffau: goto P_0c034ffa;
case 0x0c034ffcu: goto P_0c034ffc;
case 0x0c034ffeu: goto P_0c034ffe;
case 0x0c035000u: goto P_0c035000;
case 0x0c035002u: goto P_0c035002;
case 0x0c035004u: goto P_0c035004;
case 0x0c035006u: goto P_0c035006;
case 0x0c035008u: goto P_0c035008;
case 0x0c03500au: goto P_0c03500a;
case 0x0c03500cu: goto P_0c03500c;
case 0x0c035012u: goto P_0c035012;
case 0x0c035014u: goto P_0c035014;
case 0x0c035016u: goto P_0c035016;
case 0x0c035018u: goto P_0c035018;
case 0x0c03501au: goto P_0c03501a;
case 0x0c03501cu: goto P_0c03501c;
case 0x0c03501eu: goto P_0c03501e;
case 0x0c035020u: goto P_0c035020;
case 0x0c035022u: goto P_0c035022;
case 0x0c035024u: goto P_0c035024;
case 0x0c035026u: goto P_0c035026;
case 0x0c035028u: goto P_0c035028;
case 0x0c03502au: goto P_0c03502a;
case 0x0c03502cu: goto P_0c03502c;
case 0x0c03502eu: goto P_0c03502e;
case 0x0c035030u: goto P_0c035030;
case 0x0c035032u: goto P_0c035032;
case 0x0c035034u: goto P_0c035034;
case 0x0c035036u: goto P_0c035036;
case 0x0c035038u: goto P_0c035038;
case 0x0c03503au: goto P_0c03503a;
case 0x0c03503cu: goto P_0c03503c;
case 0x0c03503eu: goto P_0c03503e;
case 0x0c035040u: goto P_0c035040;
case 0x0c035042u: goto P_0c035042;
case 0x0c035044u: goto P_0c035044;
case 0x0c035046u: goto P_0c035046;
case 0x0c035048u: goto P_0c035048;
case 0x0c03504au: goto P_0c03504a;
case 0x0c03504cu: goto P_0c03504c;
case 0x0c03504eu: goto P_0c03504e;
case 0x0c035050u: goto P_0c035050;
case 0x0c035052u: goto P_0c035052;
case 0x0c035054u: goto P_0c035054;
case 0x0c035056u: goto P_0c035056;
case 0x0c035058u: goto P_0c035058;
case 0x0c03505au: goto P_0c03505a;
case 0x0c03505cu: goto P_0c03505c;
case 0x0c03505eu: goto P_0c03505e;
case 0x0c035060u: goto P_0c035060;
case 0x0c035062u: goto P_0c035062;
case 0x0c035064u: goto P_0c035064;
case 0x0c035066u: goto P_0c035066;
case 0x0c035068u: goto P_0c035068;
case 0x0c03506au: goto P_0c03506a;
case 0x0c03506cu: goto P_0c03506c;
case 0x0c03506eu: goto P_0c03506e;
case 0x0c035070u: goto P_0c035070;
case 0x0c035072u: goto P_0c035072;
case 0x0c035074u: goto P_0c035074;
case 0x0c035076u: goto P_0c035076;
case 0x0c035078u: goto P_0c035078;
case 0x0c03513au: goto P_0c03513a;
case 0x0c03513cu: goto P_0c03513c;
case 0x0c03513eu: goto P_0c03513e;
case 0x0c035140u: goto P_0c035140;
case 0x0c035142u: goto P_0c035142;
case 0x0c035144u: goto P_0c035144;
case 0x0c035146u: goto P_0c035146;
case 0x0c035148u: goto P_0c035148;
case 0x0c03514au: goto P_0c03514a;
case 0x0c03514cu: goto P_0c03514c;
case 0x0c03514eu: goto P_0c03514e;
case 0x0c035150u: goto P_0c035150;
case 0x0c035152u: goto P_0c035152;
case 0x0c035154u: goto P_0c035154;
case 0x0c035156u: goto P_0c035156;
case 0x0c035158u: goto P_0c035158;
case 0x0c03515au: goto P_0c03515a;
case 0x0c03515cu: goto P_0c03515c;
case 0x0c03515eu: goto P_0c03515e;
case 0x0c035160u: goto P_0c035160;
case 0x0c035162u: goto P_0c035162;
case 0x0c035164u: goto P_0c035164;
case 0x0c035166u: goto P_0c035166;
case 0x0c035168u: goto P_0c035168;
case 0x0c03516au: goto P_0c03516a;
case 0x0c03516cu: goto P_0c03516c;
case 0x0c03516eu: goto P_0c03516e;
case 0x0c035170u: goto P_0c035170;
case 0x0c035172u: goto P_0c035172;
case 0x0c035174u: goto P_0c035174;
case 0x0c035176u: goto P_0c035176;
case 0x0c035178u: goto P_0c035178;
case 0x0c03517au: goto P_0c03517a;
case 0x0c03517cu: goto P_0c03517c;
case 0x0c03517eu: goto P_0c03517e;
case 0x0c035180u: goto P_0c035180;
case 0x0c035182u: goto P_0c035182;
case 0x0c035184u: goto P_0c035184;
case 0x0c035186u: goto P_0c035186;
case 0x0c035188u: goto P_0c035188;
case 0x0c03518au: goto P_0c03518a;
case 0x0c03518cu: goto P_0c03518c;
case 0x0c03518eu: goto P_0c03518e;
case 0x0c035190u: goto P_0c035190;
case 0x0c035192u: goto P_0c035192;
case 0x0c035194u: goto P_0c035194;
case 0x0c035196u: goto P_0c035196;
case 0x0c035198u: goto P_0c035198;
case 0x0c03519au: goto P_0c03519a;
case 0x0c03519cu: goto P_0c03519c;
case 0x0c03519eu: goto P_0c03519e;
case 0x0c0351a0u: goto P_0c0351a0;
case 0x0c0351a2u: goto P_0c0351a2;
case 0x0c0351a4u: goto P_0c0351a4;
case 0x0c0351a6u: goto P_0c0351a6;
case 0x0c0351a8u: goto P_0c0351a8;
case 0x0c0351aau: goto P_0c0351aa;
case 0x0c0351acu: goto P_0c0351ac;
case 0x0c0351aeu: goto P_0c0351ae;
case 0x0c0351b0u: goto P_0c0351b0;
case 0x0c0351b2u: goto P_0c0351b2;
case 0x0c0351b4u: goto P_0c0351b4;
case 0x0c0351b6u: goto P_0c0351b6;
case 0x0c0351b8u: goto P_0c0351b8;
case 0x0c0351bau: goto P_0c0351ba;
case 0x0c0351bcu: goto P_0c0351bc;
case 0x0c0351beu: goto P_0c0351be;
case 0x0c0351d8u: goto P_0c0351d8;
case 0x0c0351dau: goto P_0c0351da;
case 0x0c0351dcu: goto P_0c0351dc;
case 0x0c0351deu: goto P_0c0351de;
case 0x0c0351e0u: goto P_0c0351e0;
case 0x0c0351e2u: goto P_0c0351e2;
case 0x0c0351e4u: goto P_0c0351e4;
case 0x0c0351e6u: goto P_0c0351e6;
case 0x0c0351e8u: goto P_0c0351e8;
case 0x0c0351eau: goto P_0c0351ea;
case 0x0c0351ecu: goto P_0c0351ec;
case 0x0c0351eeu: goto P_0c0351ee;
case 0x0c0351f0u: goto P_0c0351f0;
case 0x0c0351f2u: goto P_0c0351f2;
case 0x0c0351f4u: goto P_0c0351f4;
case 0x0c0351f6u: goto P_0c0351f6;
case 0x0c0351f8u: goto P_0c0351f8;
case 0x0c0351fau: goto P_0c0351fa;
case 0x0c0351fcu: goto P_0c0351fc;
case 0x0c0351feu: goto P_0c0351fe;
case 0x0c035200u: goto P_0c035200;
case 0x0c035202u: goto P_0c035202;
case 0x0c035204u: goto P_0c035204;
case 0x0c035206u: goto P_0c035206;
case 0x0c035208u: goto P_0c035208;
case 0x0c03520au: goto P_0c03520a;
case 0x0c03520cu: goto P_0c03520c;
case 0x0c03520eu: goto P_0c03520e;
case 0x0c035210u: goto P_0c035210;
case 0x0c035212u: goto P_0c035212;
case 0x0c035214u: goto P_0c035214;
case 0x0c035216u: goto P_0c035216;
case 0x0c035218u: goto P_0c035218;
case 0x0c03521au: goto P_0c03521a;
case 0x0c03521cu: goto P_0c03521c;
case 0x0c03521eu: goto P_0c03521e;
case 0x0c035220u: goto P_0c035220;
case 0x0c035222u: goto P_0c035222;
case 0x0c035224u: goto P_0c035224;
case 0x0c035226u: goto P_0c035226;
case 0x0c035228u: goto P_0c035228;
case 0x0c03522au: goto P_0c03522a;
case 0x0c03522cu: goto P_0c03522c;
case 0x0c03522eu: goto P_0c03522e;
case 0x0c035230u: goto P_0c035230;
case 0x0c035232u: goto P_0c035232;
case 0x0c035234u: goto P_0c035234;
case 0x0c035236u: goto P_0c035236;
default: return vf3_matrix_family(target,s,ram);
}
P_0c034f7c: /* original 2fe6, guest PC 0x0c034f7c */
if(!s->budget--) { s->failed_pc=0x0c034f7cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c034f7e;
P_0c034f7e: /* original 2fd6, guest PC 0x0c034f7e */
if(!s->budget--) { s->failed_pc=0x0c034f7eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c034f80;
P_0c034f80: /* original 6d53, guest PC 0x0c034f80 */
if(!s->budget--) { s->failed_pc=0x0c034f80u; return 0; }
r[13]=r[5];
goto P_0c034f82;
P_0c034f82: /* original 2fc6, guest PC 0x0c034f82 */
if(!s->budget--) { s->failed_pc=0x0c034f82u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c034f84;
P_0c034f84: /* original 2dd8, guest PC 0x0c034f84 */
if(!s->budget--) { s->failed_pc=0x0c034f84u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c034f86;
P_0c034f86: /* original 2fb6, guest PC 0x0c034f86 */
if(!s->budget--) { s->failed_pc=0x0c034f86u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c034f88;
P_0c034f88: /* original 6b43, guest PC 0x0c034f88 */
if(!s->budget--) { s->failed_pc=0x0c034f88u; return 0; }
r[11]=r[4];
goto P_0c034f8a;
P_0c034f8a: /* original 4f22, guest PC 0x0c034f8a */
if(!s->budget--) { s->failed_pc=0x0c034f8au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c034f8c;
P_0c034f8c: /* original dc3c, guest PC 0x0c034f8c */
if(!s->budget--) { s->failed_pc=0x0c034f8cu; return 0; }
r[12]=read(ram,0x0c035080u,4);
goto P_0c034f8e;
P_0c034f8e: /* original 8f01, guest PC 0x0c034f8e */
if(!s->budget--) { s->failed_pc=0x0c034f8eu; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[12],4);
r[14]=tmp;
if(!cond) { goto P_0c034f94; }
goto P_0c034f92;
P_0c034f90: /* original 6ec2, guest PC 0x0c034f90 */
if(!s->budget--) { s->failed_pc=0x0c034f90u; return 0; }
tmp=read(ram,r[12],4);
r[14]=tmp;
goto P_0c034f92;
P_0c034f92: /* original 5de6, guest PC 0x0c034f92 */
if(!s->budget--) { s->failed_pc=0x0c034f92u; return 0; }
r[13]=read(ram,r[14]+24,4);
goto P_0c034f94;
P_0c034f94: /* original 60b0, guest PC 0x0c034f94 */
if(!s->budget--) { s->failed_pc=0x0c034f94u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[11],1);
r[0]=tmp;
goto P_0c034f96;
P_0c034f96: /* original 882f, guest PC 0x0c034f96 */
if(!s->budget--) { s->failed_pc=0x0c034f96u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002fu)!=0);
goto P_0c034f98;
P_0c034f98: /* original 8d03, guest PC 0x0c034f98 */
if(!s->budget--) { s->failed_pc=0x0c034f98u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c034fa2; }
goto P_0c034f9c;
P_0c034f9a: /* original 6403, guest PC 0x0c034f9a */
if(!s->budget--) { s->failed_pc=0x0c034f9au; return 0; }
r[4]=r[0];
goto P_0c034f9c;
P_0c034f9c: /* original 6043, guest PC 0x0c034f9c */
if(!s->budget--) { s->failed_pc=0x0c034f9cu; return 0; }
r[0]=r[4];
goto P_0c034f9e;
P_0c034f9e: /* original 885c, guest PC 0x0c034f9e */
if(!s->budget--) { s->failed_pc=0x0c034f9eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000005cu)!=0);
goto P_0c034fa0;
P_0c034fa0: /* original 8b0e, guest PC 0x0c034fa0 */
if(!s->budget--) { s->failed_pc=0x0c034fa0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034fc0; }
goto P_0c034fa2;
P_0c034fa2: /* original 64e3, guest PC 0x0c034fa2 */
if(!s->budget--) { s->failed_pc=0x0c034fa2u; return 0; }
r[4]=r[14];
goto P_0c034fa4;
P_0c034fa4: /* original d237, guest PC 0x0c034fa4 */
if(!s->budget--) { s->failed_pc=0x0c034fa4u; return 0; }
r[2]=read(ram,0x0c035084u,4);
goto P_0c034fa6;
P_0c034fa6: /* original 55e3, guest PC 0x0c034fa6 */
if(!s->budget--) { s->failed_pc=0x0c034fa6u; return 0; }
r[5]=read(ram,r[14]+12,4);
goto P_0c034fa8;
P_0c034fa8: /* original 67b3, guest PC 0x0c034fa8 */
if(!s->budget--) { s->failed_pc=0x0c034fa8u; return 0; }
r[7]=r[11];
goto P_0c034faa;
P_0c034faa: /* original 56e4, guest PC 0x0c034faa */
if(!s->budget--) { s->failed_pc=0x0c034faau; return 0; }
r[6]=read(ram,r[14]+16,4);
goto P_0c034fac;
P_0c034fac: /* original 7440, guest PC 0x0c034fac */
if(!s->budget--) { s->failed_pc=0x0c034facu; return 0; }
r[4]+=0x00000040u;
goto P_0c034fae;
P_0c034fae: /* original 420b, guest PC 0x0c034fae */
if(!s->budget--) { s->failed_pc=0x0c034faeu; return 0; }
target=r[2];
r[16]=code_base|0x0c034fb2u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034fb2u) { target=s->pc; goto dispatch; }
goto P_0c034fb2;
P_0c034fb0: /* original 7440, guest PC 0x0c034fb0 */
if(!s->budget--) { s->failed_pc=0x0c034fb0u; return 0; }
r[4]+=0x00000040u;
goto P_0c034fb2;
P_0c034fb2: /* original 6403, guest PC 0x0c034fb2 */
if(!s->budget--) { s->failed_pc=0x0c034fb2u; return 0; }
r[4]=r[0];
goto P_0c034fb4;
P_0c034fb4: /* original 2448, guest PC 0x0c034fb4 */
if(!s->budget--) { s->failed_pc=0x0c034fb4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c034fb6;
P_0c034fb6: /* original 890b, guest PC 0x0c034fb6 */
if(!s->budget--) { s->failed_pc=0x0c034fb6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c034fd0; }
goto P_0c034fb8;
P_0c034fb8: /* original 9760, guest PC 0x0c034fb8 */
if(!s->budget--) { s->failed_pc=0x0c034fb8u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03507cu,2);
goto P_0c034fba;
P_0c034fba: /* original 955e, guest PC 0x0c034fba */
if(!s->budget--) { s->failed_pc=0x0c034fbau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03507au,2);
goto P_0c034fbc;
P_0c034fbc: /* original a01c, guest PC 0x0c034fbc */
if(!s->budget--) { s->failed_pc=0x0c034fbcu; return 0; }
r[5]+=r[4];
goto P_0c034ff8;
P_0c034fbe: /* original 354c, guest PC 0x0c034fbe */
if(!s->budget--) { s->failed_pc=0x0c034fbeu; return 0; }
r[5]+=r[4];
goto P_0c034fc0;
P_0c034fc0: /* original d331, guest PC 0x0c034fc0 */
if(!s->budget--) { s->failed_pc=0x0c034fc0u; return 0; }
r[3]=read(ram,0x0c035088u,4);
goto P_0c034fc2;
P_0c034fc2: /* original e600, guest PC 0x0c034fc2 */
if(!s->budget--) { s->failed_pc=0x0c034fc2u; return 0; }
r[6]=0x00000000u;
goto P_0c034fc4;
P_0c034fc4: /* original 55e6, guest PC 0x0c034fc4 */
if(!s->budget--) { s->failed_pc=0x0c034fc4u; return 0; }
r[5]=read(ram,r[14]+24,4);
goto P_0c034fc6;
P_0c034fc6: /* original 430b, guest PC 0x0c034fc6 */
if(!s->budget--) { s->failed_pc=0x0c034fc6u; return 0; }
target=r[3];
r[16]=code_base|0x0c034fcau;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c034fcau) { target=s->pc; goto dispatch; }
goto P_0c034fca;
P_0c034fc8: /* original 64b3, guest PC 0x0c034fc8 */
if(!s->budget--) { s->failed_pc=0x0c034fc8u; return 0; }
r[4]=r[11];
goto P_0c034fca;
P_0c034fca: /* original 6503, guest PC 0x0c034fca */
if(!s->budget--) { s->failed_pc=0x0c034fcau; return 0; }
r[5]=r[0];
goto P_0c034fcc;
P_0c034fcc: /* original 2558, guest PC 0x0c034fcc */
if(!s->budget--) { s->failed_pc=0x0c034fccu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c034fce;
P_0c034fce: /* original 8b01, guest PC 0x0c034fce */
if(!s->budget--) { s->failed_pc=0x0c034fceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034fd4; }
goto P_0c034fd0;
P_0c034fd0: /* original a017, guest PC 0x0c034fd0 */
if(!s->budget--) { s->failed_pc=0x0c034fd0u; return 0; }
r[0]=0xfffffff8u;
goto P_0c035002;
P_0c034fd2: /* original e0f8, guest PC 0x0c034fd2 */
if(!s->budget--) { s->failed_pc=0x0c034fd2u; return 0; }
r[0]=0xfffffff8u;
goto P_0c034fd4;
P_0c034fd4: /* original 75ff, guest PC 0x0c034fd4 */
if(!s->budget--) { s->failed_pc=0x0c034fd4u; return 0; }
r[5]+=0xffffffffu;
goto P_0c034fd6;
P_0c034fd6: /* original 64c2, guest PC 0x0c034fd6 */
if(!s->budget--) { s->failed_pc=0x0c034fd6u; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c034fd8;
P_0c034fd8: /* original e32c, guest PC 0x0c034fd8 */
if(!s->budget--) { s->failed_pc=0x0c034fd8u; return 0; }
r[3]=0x0000002cu;
goto P_0c034fda;
P_0c034fda: /* original 0537, guest PC 0x0c034fda */
if(!s->budget--) { s->failed_pc=0x0c034fdau; return 0; }
r[19]=r[5]*r[3];
goto P_0c034fdc;
P_0c034fdc: /* original 5446, guest PC 0x0c034fdc */
if(!s->budget--) { s->failed_pc=0x0c034fdcu; return 0; }
r[4]=read(ram,r[4]+24,4);
goto P_0c034fde;
P_0c034fde: /* original 7410, guest PC 0x0c034fde */
if(!s->budget--) { s->failed_pc=0x0c034fdeu; return 0; }
r[4]+=0x00000010u;
goto P_0c034fe0;
P_0c034fe0: /* original 051a, guest PC 0x0c034fe0 */
if(!s->budget--) { s->failed_pc=0x0c034fe0u; return 0; }
r[5]=r[19];
goto P_0c034fe2;
P_0c034fe2: /* original 345c, guest PC 0x0c034fe2 */
if(!s->budget--) { s->failed_pc=0x0c034fe2u; return 0; }
r[4]+=r[5];
goto P_0c034fe4;
P_0c034fe4: /* original 8448, guest PC 0x0c034fe4 */
if(!s->budget--) { s->failed_pc=0x0c034fe4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c034fe6;
P_0c034fe6: /* original 600c, guest PC 0x0c034fe6 */
if(!s->budget--) { s->failed_pc=0x0c034fe6u; return 0; }
r[0]=r[0]&255u;
goto P_0c034fe8;
P_0c034fe8: /* original c802, guest PC 0x0c034fe8 */
if(!s->budget--) { s->failed_pc=0x0c034fe8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c034fea;
P_0c034fea: /* original 8b01, guest PC 0x0c034fea */
if(!s->budget--) { s->failed_pc=0x0c034feau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c034ff0; }
goto P_0c034fec;
P_0c034fec: /* original a009, guest PC 0x0c034fec */
if(!s->budget--) { s->failed_pc=0x0c034fecu; return 0; }
r[0]=0xfffffff5u;
goto P_0c035002;
P_0c034fee: /* original e0f5, guest PC 0x0c034fee */
if(!s->budget--) { s->failed_pc=0x0c034feeu; return 0; }
r[0]=0xfffffff5u;
goto P_0c034ff0;
P_0c034ff0: /* original 6542, guest PC 0x0c034ff0 */
if(!s->budget--) { s->failed_pc=0x0c034ff0u; return 0; }
tmp=read(ram,r[4],4);
r[5]=tmp;
goto P_0c034ff2;
P_0c034ff2: /* original 9342, guest PC 0x0c034ff2 */
if(!s->budget--) { s->failed_pc=0x0c034ff2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03507au,2);
goto P_0c034ff4;
P_0c034ff4: /* original 5741, guest PC 0x0c034ff4 */
if(!s->budget--) { s->failed_pc=0x0c034ff4u; return 0; }
r[7]=read(ram,r[4]+4,4);
goto P_0c034ff6;
P_0c034ff6: /* original 353c, guest PC 0x0c034ff6 */
if(!s->budget--) { s->failed_pc=0x0c034ff6u; return 0; }
r[5]+=r[3];
goto P_0c034ff8;
P_0c034ff8: /* original d324, guest PC 0x0c034ff8 */
if(!s->budget--) { s->failed_pc=0x0c034ff8u; return 0; }
r[3]=read(ram,0x0c03508cu,4);
goto P_0c034ffa;
P_0c034ffa: /* original 66d3, guest PC 0x0c034ffa */
if(!s->budget--) { s->failed_pc=0x0c034ffau; return 0; }
r[6]=r[13];
goto P_0c034ffc;
P_0c034ffc: /* original 64c2, guest PC 0x0c034ffc */
if(!s->budget--) { s->failed_pc=0x0c034ffcu; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c034ffe;
P_0c034ffe: /* original 430b, guest PC 0x0c034ffe */
if(!s->budget--) { s->failed_pc=0x0c034ffeu; return 0; }
target=r[3];
r[16]=code_base|0x0c035002u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035002u) { target=s->pc; goto dispatch; }
goto P_0c035002;
P_0c035000: /* original 7440, guest PC 0x0c035000 */
if(!s->budget--) { s->failed_pc=0x0c035000u; return 0; }
r[4]+=0x00000040u;
goto P_0c035002;
P_0c035002: /* original 4f26, guest PC 0x0c035002 */
if(!s->budget--) { s->failed_pc=0x0c035002u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c035004;
P_0c035004: /* original 6bf6, guest PC 0x0c035004 */
if(!s->budget--) { s->failed_pc=0x0c035004u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c035006;
P_0c035006: /* original 6cf6, guest PC 0x0c035006 */
if(!s->budget--) { s->failed_pc=0x0c035006u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c035008;
P_0c035008: /* original 6df6, guest PC 0x0c035008 */
if(!s->budget--) { s->failed_pc=0x0c035008u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03500a;
P_0c03500a: /* original 000b, guest PC 0x0c03500a */
if(!s->budget--) { s->failed_pc=0x0c03500au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03500c: /* original 6ef6, guest PC 0x0c03500c */
if(!s->budget--) { s->failed_pc=0x0c03500cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03500eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03500eu; return 0; } return 1;
P_0c035012: /* original 2fe6, guest PC 0x0c035012 */
if(!s->budget--) { s->failed_pc=0x0c035012u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035014;
P_0c035014: /* original 2fd6, guest PC 0x0c035014 */
if(!s->budget--) { s->failed_pc=0x0c035014u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035016;
P_0c035016: /* original 2fc6, guest PC 0x0c035016 */
if(!s->budget--) { s->failed_pc=0x0c035016u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035018;
P_0c035018: /* original 2fb6, guest PC 0x0c035018 */
if(!s->budget--) { s->failed_pc=0x0c035018u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03501a;
P_0c03501a: /* original 2fa6, guest PC 0x0c03501a */
if(!s->budget--) { s->failed_pc=0x0c03501au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03501c;
P_0c03501c: /* original 2f96, guest PC 0x0c03501c */
if(!s->budget--) { s->failed_pc=0x0c03501cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03501e;
P_0c03501e: /* original 2f86, guest PC 0x0c03501e */
if(!s->budget--) { s->failed_pc=0x0c03501eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035020;
P_0c035020: /* original d317, guest PC 0x0c035020 */
if(!s->budget--) { s->failed_pc=0x0c035020u; return 0; }
r[3]=read(ram,0x0c035080u,4);
goto P_0c035022;
P_0c035022: /* original 6b42, guest PC 0x0c035022 */
if(!s->budget--) { s->failed_pc=0x0c035022u; return 0; }
tmp=read(ram,r[4],4);
r[11]=tmp;
goto P_0c035024;
P_0c035024: /* original 6d32, guest PC 0x0c035024 */
if(!s->budget--) { s->failed_pc=0x0c035024u; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c035026;
P_0c035026: /* original 4f22, guest PC 0x0c035026 */
if(!s->budget--) { s->failed_pc=0x0c035026u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c035028;
P_0c035028: /* original 5dd6, guest PC 0x0c035028 */
if(!s->budget--) { s->failed_pc=0x0c035028u; return 0; }
r[13]=read(ram,r[13]+24,4);
goto P_0c03502a;
P_0c03502a: /* original 5cd1, guest PC 0x0c03502a */
if(!s->budget--) { s->failed_pc=0x0c03502au; return 0; }
r[12]=read(ram,r[13]+4,4);
goto P_0c03502c;
P_0c03502c: /* original 3cb7, guest PC 0x0c03502c */
if(!s->budget--) { s->failed_pc=0x0c03502cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>(int32_t)r[11])!=0);
goto P_0c03502e;
P_0c03502e: /* original 8f02, guest PC 0x0c03502e */
if(!s->budget--) { s->failed_pc=0x0c03502eu; return 0; }
cond=r[17]&1u;
r[2]=read(ram,r[4]+8,4);
if(!cond) { goto P_0c035036; }
goto P_0c035032;
P_0c035030: /* original 5242, guest PC 0x0c035030 */
if(!s->budget--) { s->failed_pc=0x0c035030u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c035032;
P_0c035032: /* original a001, guest PC 0x0c035032 */
if(!s->budget--) { s->failed_pc=0x0c035032u; return 0; }
r[10]=r[11];
goto P_0c035038;
P_0c035034: /* original 6ab3, guest PC 0x0c035034 */
if(!s->budget--) { s->failed_pc=0x0c035034u; return 0; }
r[10]=r[11];
goto P_0c035036;
P_0c035036: /* original 6ac3, guest PC 0x0c035036 */
if(!s->budget--) { s->failed_pc=0x0c035036u; return 0; }
r[10]=r[12];
goto P_0c035038;
P_0c035038: /* original 6843, guest PC 0x0c035038 */
if(!s->budget--) { s->failed_pc=0x0c035038u; return 0; }
r[8]=r[4];
goto P_0c03503a;
P_0c03503a: /* original 69d3, guest PC 0x0c03503a */
if(!s->budget--) { s->failed_pc=0x0c03503au; return 0; }
r[9]=r[13];
goto P_0c03503c;
P_0c03503c: /* original 4a15, guest PC 0x0c03503c */
if(!s->budget--) { s->failed_pc=0x0c03503cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>0)!=0);
goto P_0c03503e;
P_0c03503e: /* original 7810, guest PC 0x0c03503e */
if(!s->budget--) { s->failed_pc=0x0c03503eu; return 0; }
r[8]+=0x00000010u;
goto P_0c035040;
P_0c035040: /* original ee00, guest PC 0x0c035040 */
if(!s->budget--) { s->failed_pc=0x0c035040u; return 0; }
r[14]=0x00000000u;
goto P_0c035042;
P_0c035042: /* original 1d22, guest PC 0x0c035042 */
if(!s->budget--) { s->failed_pc=0x0c035042u; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c035044;
P_0c035044: /* original 8f0a, guest PC 0x0c035044 */
if(!s->budget--) { s->failed_pc=0x0c035044u; return 0; }
cond=r[17]&1u;
r[9]+=0x00000010u;
if(!cond) { goto P_0c03505c; }
goto P_0c035048;
P_0c035046: /* original 7910, guest PC 0x0c035046 */
if(!s->budget--) { s->failed_pc=0x0c035046u; return 0; }
r[9]+=0x00000010u;
goto P_0c035048;
P_0c035048: /* original 6593, guest PC 0x0c035048 */
if(!s->budget--) { s->failed_pc=0x0c035048u; return 0; }
r[5]=r[9];
goto P_0c03504a;
P_0c03504a: /* original d211, guest PC 0x0c03504a */
if(!s->budget--) { s->failed_pc=0x0c03504au; return 0; }
r[2]=read(ram,0x0c035090u,4);
goto P_0c03504c;
P_0c03504c: /* original 6483, guest PC 0x0c03504c */
if(!s->budget--) { s->failed_pc=0x0c03504cu; return 0; }
r[4]=r[8];
goto P_0c03504e;
P_0c03504e: /* original e62c, guest PC 0x0c03504e */
if(!s->budget--) { s->failed_pc=0x0c03504eu; return 0; }
r[6]=0x0000002cu;
goto P_0c035050;
P_0c035050: /* original 792c, guest PC 0x0c035050 */
if(!s->budget--) { s->failed_pc=0x0c035050u; return 0; }
r[9]+=0x0000002cu;
goto P_0c035052;
P_0c035052: /* original 420b, guest PC 0x0c035052 */
if(!s->budget--) { s->failed_pc=0x0c035052u; return 0; }
target=r[2];
r[16]=code_base|0x0c035056u;
r[8]+=0x0000002cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035056u) { target=s->pc; goto dispatch; }
goto P_0c035056;
P_0c035054: /* original 782c, guest PC 0x0c035054 */
if(!s->budget--) { s->failed_pc=0x0c035054u; return 0; }
r[8]+=0x0000002cu;
goto P_0c035056;
P_0c035056: /* original 7e01, guest PC 0x0c035056 */
if(!s->budget--) { s->failed_pc=0x0c035056u; return 0; }
r[14]+=0x00000001u;
goto P_0c035058;
P_0c035058: /* original 3ea3, guest PC 0x0c035058 */
if(!s->budget--) { s->failed_pc=0x0c035058u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[10])!=0);
goto P_0c03505a;
P_0c03505a: /* original 8bf5, guest PC 0x0c03505a */
if(!s->budget--) { s->failed_pc=0x0c03505au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c035048; }
goto P_0c03505c;
P_0c03505c: /* original 3cb3, guest PC 0x0c03505c */
if(!s->budget--) { s->failed_pc=0x0c03505cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[11])!=0);
goto P_0c03505e;
P_0c03505e: /* original 8d02, guest PC 0x0c03505e */
if(!s->budget--) { s->failed_pc=0x0c03505eu; return 0; }
cond=r[17]&1u;
write(ram,r[13],r[14],4);
if(cond) { goto P_0c035066; }
goto P_0c035062;
P_0c035060: /* original 2de2, guest PC 0x0c035060 */
if(!s->budget--) { s->failed_pc=0x0c035060u; return 0; }
write(ram,r[13],r[14],4);
goto P_0c035062;
P_0c035062: /* original a001, guest PC 0x0c035062 */
if(!s->budget--) { s->failed_pc=0x0c035062u; return 0; }
r[0]=0xfffffff4u;
goto P_0c035068;
P_0c035064: /* original e0f4, guest PC 0x0c035064 */
if(!s->budget--) { s->failed_pc=0x0c035064u; return 0; }
r[0]=0xfffffff4u;
goto P_0c035066;
P_0c035066: /* original e000, guest PC 0x0c035066 */
if(!s->budget--) { s->failed_pc=0x0c035066u; return 0; }
r[0]=0x00000000u;
goto P_0c035068;
P_0c035068: /* original 4f26, guest PC 0x0c035068 */
if(!s->budget--) { s->failed_pc=0x0c035068u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03506a;
P_0c03506a: /* original 68f6, guest PC 0x0c03506a */
if(!s->budget--) { s->failed_pc=0x0c03506au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03506c;
P_0c03506c: /* original 69f6, guest PC 0x0c03506c */
if(!s->budget--) { s->failed_pc=0x0c03506cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03506e;
P_0c03506e: /* original 6af6, guest PC 0x0c03506e */
if(!s->budget--) { s->failed_pc=0x0c03506eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c035070;
P_0c035070: /* original 6bf6, guest PC 0x0c035070 */
if(!s->budget--) { s->failed_pc=0x0c035070u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c035072;
P_0c035072: /* original 6cf6, guest PC 0x0c035072 */
if(!s->budget--) { s->failed_pc=0x0c035072u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c035074;
P_0c035074: /* original 6df6, guest PC 0x0c035074 */
if(!s->budget--) { s->failed_pc=0x0c035074u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c035076;
P_0c035076: /* original 000b, guest PC 0x0c035076 */
if(!s->budget--) { s->failed_pc=0x0c035076u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c035078: /* original 6ef6, guest PC 0x0c035078 */
if(!s->budget--) { s->failed_pc=0x0c035078u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03507au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03507au; return 0; } return 1;
P_0c03513a: /* original 2fe6, guest PC 0x0c03513a */
if(!s->budget--) { s->failed_pc=0x0c03513au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03513c;
P_0c03513c: /* original 2fd6, guest PC 0x0c03513c */
if(!s->budget--) { s->failed_pc=0x0c03513cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03513e;
P_0c03513e: /* original 6d53, guest PC 0x0c03513e */
if(!s->budget--) { s->failed_pc=0x0c03513eu; return 0; }
r[13]=r[5];
goto P_0c035140;
P_0c035140: /* original 2fc6, guest PC 0x0c035140 */
if(!s->budget--) { s->failed_pc=0x0c035140u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035142;
P_0c035142: /* original 2dd8, guest PC 0x0c035142 */
if(!s->budget--) { s->failed_pc=0x0c035142u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c035144;
P_0c035144: /* original 2fb6, guest PC 0x0c035144 */
if(!s->budget--) { s->failed_pc=0x0c035144u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035146;
P_0c035146: /* original 2fa6, guest PC 0x0c035146 */
if(!s->budget--) { s->failed_pc=0x0c035146u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035148;
P_0c035148: /* original 4f22, guest PC 0x0c035148 */
if(!s->budget--) { s->failed_pc=0x0c035148u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03514a;
P_0c03514a: /* original 8f03, guest PC 0x0c03514a */
if(!s->budget--) { s->failed_pc=0x0c03514au; return 0; }
cond=r[17]&1u;
r[6]=0x00000000u;
if(!cond) { goto P_0c035154; }
goto P_0c03514e;
P_0c03514c: /* original e600, guest PC 0x0c03514c */
if(!s->budget--) { s->failed_pc=0x0c03514cu; return 0; }
r[6]=0x00000000u;
goto P_0c03514e;
P_0c03514e: /* original d31e, guest PC 0x0c03514e */
if(!s->budget--) { s->failed_pc=0x0c03514eu; return 0; }
r[3]=read(ram,0x0c0351c8u,4);
goto P_0c035150;
P_0c035150: /* original 6d32, guest PC 0x0c035150 */
if(!s->budget--) { s->failed_pc=0x0c035150u; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c035152;
P_0c035152: /* original 5dd6, guest PC 0x0c035152 */
if(!s->budget--) { s->failed_pc=0x0c035152u; return 0; }
r[13]=read(ram,r[13]+24,4);
goto P_0c035154;
P_0c035154: /* original d21d, guest PC 0x0c035154 */
if(!s->budget--) { s->failed_pc=0x0c035154u; return 0; }
r[2]=read(ram,0x0c0351ccu,4);
goto P_0c035156;
P_0c035156: /* original 420b, guest PC 0x0c035156 */
if(!s->budget--) { s->failed_pc=0x0c035156u; return 0; }
target=r[2];
r[16]=code_base|0x0c03515au;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03515au) { target=s->pc; goto dispatch; }
goto P_0c03515a;
P_0c035158: /* original 65d3, guest PC 0x0c035158 */
if(!s->budget--) { s->failed_pc=0x0c035158u; return 0; }
r[5]=r[13];
goto P_0c03515a;
P_0c03515a: /* original dc1d, guest PC 0x0c03515a */
if(!s->budget--) { s->failed_pc=0x0c03515au; return 0; }
r[12]=read(ram,0x0c0351d0u,4);
goto P_0c03515c;
P_0c03515c: /* original 6503, guest PC 0x0c03515c */
if(!s->budget--) { s->failed_pc=0x0c03515cu; return 0; }
r[5]=r[0];
goto P_0c03515e;
P_0c03515e: /* original 2558, guest PC 0x0c03515e */
if(!s->budget--) { s->failed_pc=0x0c03515eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c035160;
P_0c035160: /* original 8b01, guest PC 0x0c035160 */
if(!s->budget--) { s->failed_pc=0x0c035160u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c035166; }
goto P_0c035162;
P_0c035162: /* original a023, guest PC 0x0c035162 */
if(!s->budget--) { s->failed_pc=0x0c035162u; return 0; }
r[4]=0xfffffff8u;
goto P_0c0351ac;
P_0c035164: /* original e4f8, guest PC 0x0c035164 */
if(!s->budget--) { s->failed_pc=0x0c035164u; return 0; }
r[4]=0xfffffff8u;
goto P_0c035166;
P_0c035166: /* original d218, guest PC 0x0c035166 */
if(!s->budget--) { s->failed_pc=0x0c035166u; return 0; }
r[2]=read(ram,0x0c0351c8u,4);
goto P_0c035168;
P_0c035168: /* original 6753, guest PC 0x0c035168 */
if(!s->budget--) { s->failed_pc=0x0c035168u; return 0; }
r[7]=r[5];
goto P_0c03516a;
P_0c03516a: /* original 77ff, guest PC 0x0c03516a */
if(!s->budget--) { s->failed_pc=0x0c03516au; return 0; }
r[7]+=0xffffffffu;
goto P_0c03516c;
P_0c03516c: /* original 9b2a, guest PC 0x0c03516c */
if(!s->budget--) { s->failed_pc=0x0c03516cu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0351c4u,2);
goto P_0c03516e;
P_0c03516e: /* original e32c, guest PC 0x0c03516e */
if(!s->budget--) { s->failed_pc=0x0c03516eu; return 0; }
r[3]=0x0000002cu;
goto P_0c035170;
P_0c035170: /* original 6622, guest PC 0x0c035170 */
if(!s->budget--) { s->failed_pc=0x0c035170u; return 0; }
tmp=read(ram,r[2],4);
r[6]=tmp;
goto P_0c035172;
P_0c035172: /* original 0737, guest PC 0x0c035172 */
if(!s->budget--) { s->failed_pc=0x0c035172u; return 0; }
r[19]=r[7]*r[3];
goto P_0c035174;
P_0c035174: /* original 6162, guest PC 0x0c035174 */
if(!s->budget--) { s->failed_pc=0x0c035174u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c035176;
P_0c035176: /* original e400, guest PC 0x0c035176 */
if(!s->budget--) { s->failed_pc=0x0c035176u; return 0; }
r[4]=0x00000000u;
goto P_0c035178;
P_0c035178: /* original da16, guest PC 0x0c035178 */
if(!s->budget--) { s->failed_pc=0x0c035178u; return 0; }
r[10]=read(ram,0x0c0351d4u,4);
goto P_0c03517a;
P_0c03517a: /* original 5e6c, guest PC 0x0c03517a */
if(!s->budget--) { s->failed_pc=0x0c03517au; return 0; }
r[14]=read(ram,r[6]+48,4);
goto P_0c03517c;
P_0c03517c: /* original 4115, guest PC 0x0c03517c */
if(!s->budget--) { s->failed_pc=0x0c03517cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c03517e;
P_0c03517e: /* original 8f14, guest PC 0x0c03517e */
if(!s->budget--) { s->failed_pc=0x0c03517eu; return 0; }
cond=r[17]&1u;
r[7]=r[19];
if(!cond) { goto P_0c0351aa; }
goto P_0c035182;
P_0c035180: /* original 071a, guest PC 0x0c035180 */
if(!s->budget--) { s->failed_pc=0x0c035180u; return 0; }
r[7]=r[19];
goto P_0c035182;
P_0c035182: /* original e048, guest PC 0x0c035182 */
if(!s->budget--) { s->failed_pc=0x0c035182u; return 0; }
r[0]=0x00000048u;
goto P_0c035184;
P_0c035184: /* original 03ed, guest PC 0x0c035184 */
if(!s->budget--) { s->failed_pc=0x0c035184u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c035186;
P_0c035186: /* original 2338, guest PC 0x0c035186 */
if(!s->budget--) { s->failed_pc=0x0c035186u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c035188;
P_0c035188: /* original 8b0a, guest PC 0x0c035188 */
if(!s->budget--) { s->failed_pc=0x0c035188u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0351a0; }
goto P_0c03518a;
P_0c03518a: /* original 7d10, guest PC 0x0c03518a */
if(!s->budget--) { s->failed_pc=0x0c03518au; return 0; }
r[13]+=0x00000010u;
goto P_0c03518c;
P_0c03518c: /* original 3d7c, guest PC 0x0c03518c */
if(!s->budget--) { s->failed_pc=0x0c03518cu; return 0; }
r[13]+=r[7];
goto P_0c03518e;
P_0c03518e: /* original 66d2, guest PC 0x0c03518e */
if(!s->budget--) { s->failed_pc=0x0c03518eu; return 0; }
tmp=read(ram,r[13],4);
r[6]=tmp;
goto P_0c035190;
P_0c035190: /* original 57d1, guest PC 0x0c035190 */
if(!s->budget--) { s->failed_pc=0x0c035190u; return 0; }
r[7]=read(ram,r[13]+4,4);
goto P_0c035192;
P_0c035192: /* original 36bc, guest PC 0x0c035192 */
if(!s->budget--) { s->failed_pc=0x0c035192u; return 0; }
r[6]+=r[11];
goto P_0c035194;
P_0c035194: /* original 4a0b, guest PC 0x0c035194 */
if(!s->budget--) { s->failed_pc=0x0c035194u; return 0; }
target=r[10];
r[16]=code_base|0x0c035198u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035198u) { target=s->pc; goto dispatch; }
goto P_0c035198;
P_0c035196: /* original 64e3, guest PC 0x0c035196 */
if(!s->budget--) { s->failed_pc=0x0c035196u; return 0; }
r[4]=r[14];
goto P_0c035198;
P_0c035198: /* original 4c0b, guest PC 0x0c035198 */
if(!s->budget--) { s->failed_pc=0x0c035198u; return 0; }
target=r[12];
r[16]=code_base|0x0c03519cu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03519cu) { target=s->pc; goto dispatch; }
goto P_0c03519c;
P_0c03519a: /* original e400, guest PC 0x0c03519a */
if(!s->budget--) { s->failed_pc=0x0c03519au; return 0; }
r[4]=0x00000000u;
goto P_0c03519c;
P_0c03519c: /* original a009, guest PC 0x0c03519c */
if(!s->budget--) { s->failed_pc=0x0c03519cu; return 0; }
r[0]=r[14];
goto P_0c0351b2;
P_0c03519e: /* original 60e3, guest PC 0x0c03519e */
if(!s->budget--) { s->failed_pc=0x0c03519eu; return 0; }
r[0]=r[14];
goto P_0c0351a0;
P_0c0351a0: /* original 6362, guest PC 0x0c0351a0 */
if(!s->budget--) { s->failed_pc=0x0c0351a0u; return 0; }
tmp=read(ram,r[6],4);
r[3]=tmp;
goto P_0c0351a2;
P_0c0351a2: /* original 7401, guest PC 0x0c0351a2 */
if(!s->budget--) { s->failed_pc=0x0c0351a2u; return 0; }
r[4]+=0x00000001u;
goto P_0c0351a4;
P_0c0351a4: /* original 3433, guest PC 0x0c0351a4 */
if(!s->budget--) { s->failed_pc=0x0c0351a4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0351a6;
P_0c0351a6: /* original 8fec, guest PC 0x0c0351a6 */
if(!s->budget--) { s->failed_pc=0x0c0351a6u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000050u;
if(!cond) { goto P_0c035182; }
goto P_0c0351aa;
P_0c0351a8: /* original 7e50, guest PC 0x0c0351a8 */
if(!s->budget--) { s->failed_pc=0x0c0351a8u; return 0; }
r[14]+=0x00000050u;
goto P_0c0351aa;
P_0c0351aa: /* original e4f7, guest PC 0x0c0351aa */
if(!s->budget--) { s->failed_pc=0x0c0351aau; return 0; }
r[4]=0xfffffff7u;
goto P_0c0351ac;
P_0c0351ac: /* original 4c0b, guest PC 0x0c0351ac */
if(!s->budget--) { s->failed_pc=0x0c0351acu; return 0; }
target=r[12];
r[16]=code_base|0x0c0351b0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0351b0u) { target=s->pc; goto dispatch; }
goto P_0c0351b0;
P_0c0351ae: /* original 0009, guest PC 0x0c0351ae */
if(!s->budget--) { s->failed_pc=0x0c0351aeu; return 0; }
goto P_0c0351b0;
P_0c0351b0: /* original e000, guest PC 0x0c0351b0 */
if(!s->budget--) { s->failed_pc=0x0c0351b0u; return 0; }
r[0]=0x00000000u;
goto P_0c0351b2;
P_0c0351b2: /* original 4f26, guest PC 0x0c0351b2 */
if(!s->budget--) { s->failed_pc=0x0c0351b2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0351b4;
P_0c0351b4: /* original 6af6, guest PC 0x0c0351b4 */
if(!s->budget--) { s->failed_pc=0x0c0351b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0351b6;
P_0c0351b6: /* original 6bf6, guest PC 0x0c0351b6 */
if(!s->budget--) { s->failed_pc=0x0c0351b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0351b8;
P_0c0351b8: /* original 6cf6, guest PC 0x0c0351b8 */
if(!s->budget--) { s->failed_pc=0x0c0351b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0351ba;
P_0c0351ba: /* original 6df6, guest PC 0x0c0351ba */
if(!s->budget--) { s->failed_pc=0x0c0351bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0351bc;
P_0c0351bc: /* original 000b, guest PC 0x0c0351bc */
if(!s->budget--) { s->failed_pc=0x0c0351bcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0351be: /* original 6ef6, guest PC 0x0c0351be */
if(!s->budget--) { s->failed_pc=0x0c0351beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0351c0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0351c0u; return 0; } return 1;
P_0c0351d8: /* original 2fe6, guest PC 0x0c0351d8 */
if(!s->budget--) { s->failed_pc=0x0c0351d8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0351da;
P_0c0351da: /* original 2fd6, guest PC 0x0c0351da */
if(!s->budget--) { s->failed_pc=0x0c0351dau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0351dc;
P_0c0351dc: /* original 2fc6, guest PC 0x0c0351dc */
if(!s->budget--) { s->failed_pc=0x0c0351dcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0351de;
P_0c0351de: /* original 2fb6, guest PC 0x0c0351de */
if(!s->budget--) { s->failed_pc=0x0c0351deu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0351e0;
P_0c0351e0: /* original 6b53, guest PC 0x0c0351e0 */
if(!s->budget--) { s->failed_pc=0x0c0351e0u; return 0; }
r[11]=r[5];
goto P_0c0351e2;
P_0c0351e2: /* original 4f22, guest PC 0x0c0351e2 */
if(!s->budget--) { s->failed_pc=0x0c0351e2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0351e4;
P_0c0351e4: /* original 4b18, guest PC 0x0c0351e4 */
if(!s->budget--) { s->failed_pc=0x0c0351e4u; return 0; }
r[11]<<=8;
goto P_0c0351e6;
P_0c0351e6: /* original 4b08, guest PC 0x0c0351e6 */
if(!s->budget--) { s->failed_pc=0x0c0351e6u; return 0; }
r[11]<<=2;
goto P_0c0351e8;
P_0c0351e8: /* original 7ffc, guest PC 0x0c0351e8 */
if(!s->budget--) { s->failed_pc=0x0c0351e8u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0351ea;
P_0c0351ea: /* original 2f42, guest PC 0x0c0351ea */
if(!s->budget--) { s->failed_pc=0x0c0351eau; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0351ec;
P_0c0351ec: /* original e400, guest PC 0x0c0351ec */
if(!s->budget--) { s->failed_pc=0x0c0351ecu; return 0; }
r[4]=0x00000000u;
goto P_0c0351ee;
P_0c0351ee: /* original d3a7, guest PC 0x0c0351ee */
if(!s->budget--) { s->failed_pc=0x0c0351eeu; return 0; }
r[3]=read(ram,0x0c03548cu,4);
goto P_0c0351f0;
P_0c0351f0: /* original 4b00, guest PC 0x0c0351f0 */
if(!s->budget--) { s->failed_pc=0x0c0351f0u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c0351f2;
P_0c0351f2: /* original dca7, guest PC 0x0c0351f2 */
if(!s->budget--) { s->failed_pc=0x0c0351f2u; return 0; }
r[12]=read(ram,0x0c035490u,4);
goto P_0c0351f4;
P_0c0351f4: /* original 6632, guest PC 0x0c0351f4 */
if(!s->budget--) { s->failed_pc=0x0c0351f4u; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c0351f6;
P_0c0351f6: /* original dda7, guest PC 0x0c0351f6 */
if(!s->budget--) { s->failed_pc=0x0c0351f6u; return 0; }
r[13]=read(ram,0x0c035494u,4);
goto P_0c0351f8;
P_0c0351f8: /* original 6262, guest PC 0x0c0351f8 */
if(!s->budget--) { s->failed_pc=0x0c0351f8u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c0351fa;
P_0c0351fa: /* original 4215, guest PC 0x0c0351fa */
if(!s->budget--) { s->failed_pc=0x0c0351fau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0351fc;
P_0c0351fc: /* original 8f12, guest PC 0x0c0351fc */
if(!s->budget--) { s->failed_pc=0x0c0351fcu; return 0; }
cond=r[17]&1u;
r[14]=read(ram,r[6]+48,4);
if(!cond) { goto P_0c035224; }
goto P_0c035200;
P_0c0351fe: /* original 5e6c, guest PC 0x0c0351fe */
if(!s->budget--) { s->failed_pc=0x0c0351feu; return 0; }
r[14]=read(ram,r[6]+48,4);
goto P_0c035200;
P_0c035200: /* original e048, guest PC 0x0c035200 */
if(!s->budget--) { s->failed_pc=0x0c035200u; return 0; }
r[0]=0x00000048u;
goto P_0c035202;
P_0c035202: /* original 03ed, guest PC 0x0c035202 */
if(!s->budget--) { s->failed_pc=0x0c035202u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c035204;
P_0c035204: /* original 2338, guest PC 0x0c035204 */
if(!s->budget--) { s->failed_pc=0x0c035204u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c035206;
P_0c035206: /* original 8b08, guest PC 0x0c035206 */
if(!s->budget--) { s->failed_pc=0x0c035206u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03521a; }
goto P_0c035208;
P_0c035208: /* original 66f2, guest PC 0x0c035208 */
if(!s->budget--) { s->failed_pc=0x0c035208u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c03520a;
P_0c03520a: /* original e500, guest PC 0x0c03520a */
if(!s->budget--) { s->failed_pc=0x0c03520au; return 0; }
r[5]=0x00000000u;
goto P_0c03520c;
P_0c03520c: /* original 67b3, guest PC 0x0c03520c */
if(!s->budget--) { s->failed_pc=0x0c03520cu; return 0; }
r[7]=r[11];
goto P_0c03520e;
P_0c03520e: /* original 4c0b, guest PC 0x0c03520e */
if(!s->budget--) { s->failed_pc=0x0c03520eu; return 0; }
target=r[12];
r[16]=code_base|0x0c035212u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035212u) { target=s->pc; goto dispatch; }
goto P_0c035212;
P_0c035210: /* original 64e3, guest PC 0x0c035210 */
if(!s->budget--) { s->failed_pc=0x0c035210u; return 0; }
r[4]=r[14];
goto P_0c035212;
P_0c035212: /* original 4d0b, guest PC 0x0c035212 */
if(!s->budget--) { s->failed_pc=0x0c035212u; return 0; }
target=r[13];
r[16]=code_base|0x0c035216u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035216u) { target=s->pc; goto dispatch; }
goto P_0c035216;
P_0c035214: /* original e400, guest PC 0x0c035214 */
if(!s->budget--) { s->failed_pc=0x0c035214u; return 0; }
r[4]=0x00000000u;
goto P_0c035216;
P_0c035216: /* original a008, guest PC 0x0c035216 */
if(!s->budget--) { s->failed_pc=0x0c035216u; return 0; }
r[0]=r[14];
goto P_0c03522a;
P_0c035218: /* original 60e3, guest PC 0x0c035218 */
if(!s->budget--) { s->failed_pc=0x0c035218u; return 0; }
r[0]=r[14];
goto P_0c03521a;
P_0c03521a: /* original 6362, guest PC 0x0c03521a */
if(!s->budget--) { s->failed_pc=0x0c03521au; return 0; }
tmp=read(ram,r[6],4);
r[3]=tmp;
goto P_0c03521c;
P_0c03521c: /* original 7401, guest PC 0x0c03521c */
if(!s->budget--) { s->failed_pc=0x0c03521cu; return 0; }
r[4]+=0x00000001u;
goto P_0c03521e;
P_0c03521e: /* original 3433, guest PC 0x0c03521e */
if(!s->budget--) { s->failed_pc=0x0c03521eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c035220;
P_0c035220: /* original 8fee, guest PC 0x0c035220 */
if(!s->budget--) { s->failed_pc=0x0c035220u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000050u;
if(!cond) { goto P_0c035200; }
goto P_0c035224;
P_0c035222: /* original 7e50, guest PC 0x0c035222 */
if(!s->budget--) { s->failed_pc=0x0c035222u; return 0; }
r[14]+=0x00000050u;
goto P_0c035224;
P_0c035224: /* original 4d0b, guest PC 0x0c035224 */
if(!s->budget--) { s->failed_pc=0x0c035224u; return 0; }
target=r[13];
r[16]=code_base|0x0c035228u;
r[4]=0xfffffff7u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035228u) { target=s->pc; goto dispatch; }
goto P_0c035228;
P_0c035226: /* original e4f7, guest PC 0x0c035226 */
if(!s->budget--) { s->failed_pc=0x0c035226u; return 0; }
r[4]=0xfffffff7u;
goto P_0c035228;
P_0c035228: /* original e000, guest PC 0x0c035228 */
if(!s->budget--) { s->failed_pc=0x0c035228u; return 0; }
r[0]=0x00000000u;
goto P_0c03522a;
P_0c03522a: /* original 7f04, guest PC 0x0c03522a */
if(!s->budget--) { s->failed_pc=0x0c03522au; return 0; }
r[15]+=0x00000004u;
goto P_0c03522c;
P_0c03522c: /* original 4f26, guest PC 0x0c03522c */
if(!s->budget--) { s->failed_pc=0x0c03522cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03522e;
P_0c03522e: /* original 6bf6, guest PC 0x0c03522e */
if(!s->budget--) { s->failed_pc=0x0c03522eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c035230;
P_0c035230: /* original 6cf6, guest PC 0x0c035230 */
if(!s->budget--) { s->failed_pc=0x0c035230u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c035232;
P_0c035232: /* original 6df6, guest PC 0x0c035232 */
if(!s->budget--) { s->failed_pc=0x0c035232u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c035234;
P_0c035234: /* original 000b, guest PC 0x0c035234 */
if(!s->budget--) { s->failed_pc=0x0c035234u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c035236: /* original 6ef6, guest PC 0x0c035236 */
if(!s->budget--) { s->failed_pc=0x0c035236u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c035238u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c035238u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
