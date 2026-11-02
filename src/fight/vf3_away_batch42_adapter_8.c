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
int vf3_away_batch42_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c073f82u: goto P_0c073f82;
case 0x0c073f84u: goto P_0c073f84;
case 0x0c073f86u: goto P_0c073f86;
case 0x0c073f88u: goto P_0c073f88;
case 0x0c073f8au: goto P_0c073f8a;
case 0x0c073f8cu: goto P_0c073f8c;
case 0x0c073f8eu: goto P_0c073f8e;
case 0x0c073f90u: goto P_0c073f90;
case 0x0c073f92u: goto P_0c073f92;
case 0x0c073f94u: goto P_0c073f94;
case 0x0c073f96u: goto P_0c073f96;
case 0x0c073f98u: goto P_0c073f98;
case 0x0c073f9au: goto P_0c073f9a;
case 0x0c073f9cu: goto P_0c073f9c;
case 0x0c073f9eu: goto P_0c073f9e;
case 0x0c073fa0u: goto P_0c073fa0;
case 0x0c073fa2u: goto P_0c073fa2;
case 0x0c073fa4u: goto P_0c073fa4;
case 0x0c073fa6u: goto P_0c073fa6;
case 0x0c073fa8u: goto P_0c073fa8;
case 0x0c073faau: goto P_0c073faa;
case 0x0c073facu: goto P_0c073fac;
case 0x0c073faeu: goto P_0c073fae;
case 0x0c073fb0u: goto P_0c073fb0;
case 0x0c073fb2u: goto P_0c073fb2;
case 0x0c073fb4u: goto P_0c073fb4;
case 0x0c073fb6u: goto P_0c073fb6;
case 0x0c073fb8u: goto P_0c073fb8;
case 0x0c073fbau: goto P_0c073fba;
case 0x0c073fbcu: goto P_0c073fbc;
case 0x0c073fbeu: goto P_0c073fbe;
case 0x0c073fc0u: goto P_0c073fc0;
case 0x0c073fc2u: goto P_0c073fc2;
case 0x0c073fc4u: goto P_0c073fc4;
case 0x0c073fc6u: goto P_0c073fc6;
case 0x0c073fc8u: goto P_0c073fc8;
case 0x0c073fcau: goto P_0c073fca;
case 0x0c073fccu: goto P_0c073fcc;
case 0x0c073fceu: goto P_0c073fce;
case 0x0c073fd0u: goto P_0c073fd0;
case 0x0c073fd2u: goto P_0c073fd2;
case 0x0c073fd4u: goto P_0c073fd4;
case 0x0c073fd6u: goto P_0c073fd6;
case 0x0c073fd8u: goto P_0c073fd8;
case 0x0c073fdau: goto P_0c073fda;
case 0x0c073fdcu: goto P_0c073fdc;
case 0x0c073fdeu: goto P_0c073fde;
case 0x0c073fe0u: goto P_0c073fe0;
case 0x0c073fe2u: goto P_0c073fe2;
case 0x0c073fe4u: goto P_0c073fe4;
case 0x0c073fe6u: goto P_0c073fe6;
case 0x0c073fe8u: goto P_0c073fe8;
case 0x0c073feau: goto P_0c073fea;
case 0x0c073fecu: goto P_0c073fec;
case 0x0c073feeu: goto P_0c073fee;
case 0x0c073ff0u: goto P_0c073ff0;
case 0x0c073ff2u: goto P_0c073ff2;
case 0x0c073ff4u: goto P_0c073ff4;
case 0x0c073ff6u: goto P_0c073ff6;
case 0x0c073ff8u: goto P_0c073ff8;
case 0x0c074014u: goto P_0c074014;
case 0x0c074016u: goto P_0c074016;
case 0x0c074018u: goto P_0c074018;
case 0x0c07401au: goto P_0c07401a;
case 0x0c07401cu: goto P_0c07401c;
case 0x0c07401eu: goto P_0c07401e;
case 0x0c074020u: goto P_0c074020;
case 0x0c074022u: goto P_0c074022;
case 0x0c074024u: goto P_0c074024;
case 0x0c074026u: goto P_0c074026;
case 0x0c074028u: goto P_0c074028;
case 0x0c07402au: goto P_0c07402a;
case 0x0c07402cu: goto P_0c07402c;
case 0x0c07402eu: goto P_0c07402e;
case 0x0c074030u: goto P_0c074030;
case 0x0c074032u: goto P_0c074032;
case 0x0c074034u: goto P_0c074034;
case 0x0c074036u: goto P_0c074036;
case 0x0c074038u: goto P_0c074038;
case 0x0c07403au: goto P_0c07403a;
case 0x0c07403cu: goto P_0c07403c;
case 0x0c07403eu: goto P_0c07403e;
case 0x0c074040u: goto P_0c074040;
case 0x0c074042u: goto P_0c074042;
case 0x0c074044u: goto P_0c074044;
case 0x0c074046u: goto P_0c074046;
case 0x0c074048u: goto P_0c074048;
case 0x0c07404au: goto P_0c07404a;
case 0x0c07404cu: goto P_0c07404c;
case 0x0c07404eu: goto P_0c07404e;
case 0x0c074050u: goto P_0c074050;
case 0x0c074052u: goto P_0c074052;
case 0x0c074054u: goto P_0c074054;
case 0x0c074056u: goto P_0c074056;
case 0x0c074058u: goto P_0c074058;
case 0x0c07405au: goto P_0c07405a;
case 0x0c07405cu: goto P_0c07405c;
case 0x0c07405eu: goto P_0c07405e;
case 0x0c074060u: goto P_0c074060;
case 0x0c074062u: goto P_0c074062;
case 0x0c074064u: goto P_0c074064;
case 0x0c074066u: goto P_0c074066;
case 0x0c074068u: goto P_0c074068;
case 0x0c07406au: goto P_0c07406a;
case 0x0c07406cu: goto P_0c07406c;
case 0x0c07406eu: goto P_0c07406e;
case 0x0c074070u: goto P_0c074070;
case 0x0c074072u: goto P_0c074072;
case 0x0c074074u: goto P_0c074074;
case 0x0c074076u: goto P_0c074076;
case 0x0c074078u: goto P_0c074078;
case 0x0c07407au: goto P_0c07407a;
case 0x0c07407cu: goto P_0c07407c;
case 0x0c07407eu: goto P_0c07407e;
case 0x0c074080u: goto P_0c074080;
case 0x0c074082u: goto P_0c074082;
case 0x0c074084u: goto P_0c074084;
case 0x0c074086u: goto P_0c074086;
case 0x0c074088u: goto P_0c074088;
case 0x0c07408au: goto P_0c07408a;
case 0x0c07408cu: goto P_0c07408c;
case 0x0c07408eu: goto P_0c07408e;
case 0x0c074090u: goto P_0c074090;
case 0x0c074092u: goto P_0c074092;
case 0x0c074094u: goto P_0c074094;
case 0x0c074096u: goto P_0c074096;
case 0x0c074098u: goto P_0c074098;
case 0x0c07409au: goto P_0c07409a;
case 0x0c07409cu: goto P_0c07409c;
case 0x0c07409eu: goto P_0c07409e;
case 0x0c0740a0u: goto P_0c0740a0;
case 0x0c0740a2u: goto P_0c0740a2;
case 0x0c0740a4u: goto P_0c0740a4;
case 0x0c0740a6u: goto P_0c0740a6;
case 0x0c0740a8u: goto P_0c0740a8;
case 0x0c0740aau: goto P_0c0740aa;
case 0x0c0740acu: goto P_0c0740ac;
case 0x0c0740aeu: goto P_0c0740ae;
case 0x0c0740b0u: goto P_0c0740b0;
case 0x0c0740b2u: goto P_0c0740b2;
case 0x0c0740b4u: goto P_0c0740b4;
case 0x0c0740b6u: goto P_0c0740b6;
case 0x0c0740b8u: goto P_0c0740b8;
case 0x0c0740bau: goto P_0c0740ba;
case 0x0c0740bcu: goto P_0c0740bc;
case 0x0c0740beu: goto P_0c0740be;
case 0x0c0740c0u: goto P_0c0740c0;
case 0x0c0740c2u: goto P_0c0740c2;
case 0x0c0740c4u: goto P_0c0740c4;
case 0x0c0740c6u: goto P_0c0740c6;
case 0x0c0740c8u: goto P_0c0740c8;
case 0x0c0740cau: goto P_0c0740ca;
case 0x0c0740ccu: goto P_0c0740cc;
case 0x0c0740ceu: goto P_0c0740ce;
case 0x0c0740d0u: goto P_0c0740d0;
case 0x0c0740d2u: goto P_0c0740d2;
case 0x0c0740d4u: goto P_0c0740d4;
case 0x0c0740d6u: goto P_0c0740d6;
case 0x0c0740d8u: goto P_0c0740d8;
case 0x0c0740dau: goto P_0c0740da;
case 0x0c0740dcu: goto P_0c0740dc;
case 0x0c0740deu: goto P_0c0740de;
case 0x0c0740e0u: goto P_0c0740e0;
case 0x0c0740e2u: goto P_0c0740e2;
case 0x0c0740e4u: goto P_0c0740e4;
case 0x0c0740e6u: goto P_0c0740e6;
case 0x0c0740e8u: goto P_0c0740e8;
case 0x0c0740eau: goto P_0c0740ea;
case 0x0c0740ecu: goto P_0c0740ec;
case 0x0c0740eeu: goto P_0c0740ee;
case 0x0c0740f0u: goto P_0c0740f0;
case 0x0c0740f2u: goto P_0c0740f2;
case 0x0c0740f4u: goto P_0c0740f4;
case 0x0c074108u: goto P_0c074108;
case 0x0c07410au: goto P_0c07410a;
case 0x0c07410cu: goto P_0c07410c;
case 0x0c07410eu: goto P_0c07410e;
case 0x0c074110u: goto P_0c074110;
case 0x0c074112u: goto P_0c074112;
case 0x0c074114u: goto P_0c074114;
case 0x0c074116u: goto P_0c074116;
case 0x0c074118u: goto P_0c074118;
case 0x0c07411au: goto P_0c07411a;
case 0x0c07411cu: goto P_0c07411c;
case 0x0c07411eu: goto P_0c07411e;
case 0x0c074120u: goto P_0c074120;
case 0x0c074122u: goto P_0c074122;
case 0x0c074124u: goto P_0c074124;
case 0x0c074126u: goto P_0c074126;
case 0x0c074128u: goto P_0c074128;
case 0x0c07412au: goto P_0c07412a;
case 0x0c07412cu: goto P_0c07412c;
case 0x0c07412eu: goto P_0c07412e;
case 0x0c074130u: goto P_0c074130;
case 0x0c074132u: goto P_0c074132;
case 0x0c074134u: goto P_0c074134;
case 0x0c074136u: goto P_0c074136;
case 0x0c074138u: goto P_0c074138;
case 0x0c07413au: goto P_0c07413a;
case 0x0c07413cu: goto P_0c07413c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c073f82: /* original 4f22, guest PC 0x0c073f82 */
if(!s->budget--) { s->failed_pc=0x0c073f82u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c073f84;
P_0c073f84: /* original 7ff8, guest PC 0x0c073f84 */
if(!s->budget--) { s->failed_pc=0x0c073f84u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c073f86;
P_0c073f86: /* original 2f42, guest PC 0x0c073f86 */
if(!s->budget--) { s->failed_pc=0x0c073f86u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c073f88;
P_0c073f88: /* original 1f51, guest PC 0x0c073f88 */
if(!s->budget--) { s->failed_pc=0x0c073f88u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c073f8a;
P_0c073f8a: /* original d11e, guest PC 0x0c073f8a */
if(!s->budget--) { s->failed_pc=0x0c073f8au; return 0; }
r[1]=read(ram,0x0c074004u,4);
goto P_0c073f8c;
P_0c073f8c: /* original d31c, guest PC 0x0c073f8c */
if(!s->budget--) { s->failed_pc=0x0c073f8cu; return 0; }
r[3]=read(ram,0x0c074000u,4);
goto P_0c073f8e;
P_0c073f8e: /* original 6212, guest PC 0x0c073f8e */
if(!s->budget--) { s->failed_pc=0x0c073f8eu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c073f90;
P_0c073f90: /* original 2238, guest PC 0x0c073f90 */
if(!s->budget--) { s->failed_pc=0x0c073f90u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c073f92;
P_0c073f92: /* original 8b0b, guest PC 0x0c073f92 */
if(!s->budget--) { s->failed_pc=0x0c073f92u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073fac; }
goto P_0c073f94;
P_0c073f94: /* original d31c, guest PC 0x0c073f94 */
if(!s->budget--) { s->failed_pc=0x0c073f94u; return 0; }
r[3]=read(ram,0x0c074008u,4);
goto P_0c073f96;
P_0c073f96: /* original 6030, guest PC 0x0c073f96 */
if(!s->budget--) { s->failed_pc=0x0c073f96u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c073f98;
P_0c073f98: /* original 600c, guest PC 0x0c073f98 */
if(!s->budget--) { s->failed_pc=0x0c073f98u; return 0; }
r[0]=r[0]&255u;
goto P_0c073f9a;
P_0c073f9a: /* original c90f, guest PC 0x0c073f9a */
if(!s->budget--) { s->failed_pc=0x0c073f9au; return 0; }
r[0]&=15u;
goto P_0c073f9c;
P_0c073f9c: /* original 880d, guest PC 0x0c073f9c */
if(!s->budget--) { s->failed_pc=0x0c073f9cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c073f9e;
P_0c073f9e: /* original 8905, guest PC 0x0c073f9e */
if(!s->budget--) { s->failed_pc=0x0c073f9eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c073fac; }
goto P_0c073fa0;
P_0c073fa0: /* original 55f1, guest PC 0x0c073fa0 */
if(!s->budget--) { s->failed_pc=0x0c073fa0u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c073fa2;
P_0c073fa2: /* original b007, guest PC 0x0c073fa2 */
if(!s->budget--) { s->failed_pc=0x0c073fa2u; return 0; }
target=code_base|0x0c073fb4u; r[16]=code_base|0x0c073fa6u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073fa6u) { target=s->pc; goto dispatch; }
goto P_0c073fa6;
P_0c073fa4: /* original 64f2, guest PC 0x0c073fa4 */
if(!s->budget--) { s->failed_pc=0x0c073fa4u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c073fa6;
P_0c073fa6: /* original 65f2, guest PC 0x0c073fa6 */
if(!s->budget--) { s->failed_pc=0x0c073fa6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c073fa8;
P_0c073fa8: /* original b004, guest PC 0x0c073fa8 */
if(!s->budget--) { s->failed_pc=0x0c073fa8u; return 0; }
target=code_base|0x0c073fb4u; r[16]=code_base|0x0c073facu;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073facu) { target=s->pc; goto dispatch; }
goto P_0c073fac;
P_0c073faa: /* original 54f1, guest PC 0x0c073faa */
if(!s->budget--) { s->failed_pc=0x0c073faau; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c073fac;
P_0c073fac: /* original 7f08, guest PC 0x0c073fac */
if(!s->budget--) { s->failed_pc=0x0c073facu; return 0; }
r[15]+=0x00000008u;
goto P_0c073fae;
P_0c073fae: /* original 4f26, guest PC 0x0c073fae */
if(!s->budget--) { s->failed_pc=0x0c073faeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c073fb0;
P_0c073fb0: /* original 000b, guest PC 0x0c073fb0 */
if(!s->budget--) { s->failed_pc=0x0c073fb0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c073fb2: /* original 0009, guest PC 0x0c073fb2 */
if(!s->budget--) { s->failed_pc=0x0c073fb2u; return 0; }
goto P_0c073fb4;
P_0c073fb4: /* original 2fe6, guest PC 0x0c073fb4 */
if(!s->budget--) { s->failed_pc=0x0c073fb4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c073fb6;
P_0c073fb6: /* original e600, guest PC 0x0c073fb6 */
if(!s->budget--) { s->failed_pc=0x0c073fb6u; return 0; }
r[6]=0x00000000u;
goto P_0c073fb8;
P_0c073fb8: /* original 2fc6, guest PC 0x0c073fb8 */
if(!s->budget--) { s->failed_pc=0x0c073fb8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c073fba;
P_0c073fba: /* original 901f, guest PC 0x0c073fba */
if(!s->budget--) { s->failed_pc=0x0c073fbau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073ffcu,2);
goto P_0c073fbc;
P_0c073fbc: /* original f646, guest PC 0x0c073fbc */
if(!s->budget--) { s->failed_pc=0x0c073fbcu; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c073fbe;
P_0c073fbe: /* original 7008, guest PC 0x0c073fbe */
if(!s->budget--) { s->failed_pc=0x0c073fbeu; return 0; }
r[0]+=0x00000008u;
goto P_0c073fc0;
P_0c073fc0: /* original f846, guest PC 0x0c073fc0 */
if(!s->budget--) { s->failed_pc=0x0c073fc0u; return 0; }
vf3_matrix_load(s,ram,8,r[4]+r[0]);
goto P_0c073fc2;
P_0c073fc2: /* original e010, guest PC 0x0c073fc2 */
if(!s->budget--) { s->failed_pc=0x0c073fc2u; return 0; }
r[0]=0x00000010u;
goto P_0c073fc4;
P_0c073fc4: /* original f946, guest PC 0x0c073fc4 */
if(!s->budget--) { s->failed_pc=0x0c073fc4u; return 0; }
vf3_matrix_load(s,ram,9,r[4]+r[0]);
goto P_0c073fc6;
P_0c073fc6: /* original e018, guest PC 0x0c073fc6 */
if(!s->budget--) { s->failed_pc=0x0c073fc6u; return 0; }
r[0]=0x00000018u;
goto P_0c073fc8;
P_0c073fc8: /* original fa46, guest PC 0x0c073fc8 */
if(!s->budget--) { s->failed_pc=0x0c073fc8u; return 0; }
vf3_matrix_load(s,ram,10,r[4]+r[0]);
goto P_0c073fca;
P_0c073fca: /* original c710, guest PC 0x0c073fca */
if(!s->budget--) { s->failed_pc=0x0c073fcau; return 0; }
r[0]=code_base|0x0007400cu;
goto P_0c073fcc;
P_0c073fcc: /* original f708, guest PC 0x0c073fcc */
if(!s->budget--) { s->failed_pc=0x0c073fccu; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c073fce;
P_0c073fce: /* original c710, guest PC 0x0c073fce */
if(!s->budget--) { s->failed_pc=0x0c073fceu; return 0; }
r[0]=code_base|0x00074010u;
goto P_0c073fd0;
P_0c073fd0: /* original f675, guest PC 0x0c073fd0 */
if(!s->budget--) { s->failed_pc=0x0c073fd0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[7]))!=0);
goto P_0c073fd2;
P_0c073fd2: /* original 8f03, guest PC 0x0c073fd2 */
if(!s->budget--) { s->failed_pc=0x0c073fd2u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,5,r[0]);
if(!cond) { goto P_0c073fdc; }
goto P_0c073fd6;
P_0c073fd4: /* original f508, guest PC 0x0c073fd4 */
if(!s->budget--) { s->failed_pc=0x0c073fd4u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c073fd6;
P_0c073fd6: /* original f46c, guest PC 0x0c073fd6 */
if(!s->budget--) { s->failed_pc=0x0c073fd6u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c073fd8;
P_0c073fd8: /* original a004, guest PC 0x0c073fd8 */
if(!s->budget--) { s->failed_pc=0x0c073fd8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c073fe4;
P_0c073fda: /* original f450, guest PC 0x0c073fda */
if(!s->budget--) { s->failed_pc=0x0c073fdau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c073fdc;
P_0c073fdc: /* original f565, guest PC 0x0c073fdc */
if(!s->budget--) { s->failed_pc=0x0c073fdcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[6]))!=0);
goto P_0c073fde;
P_0c073fde: /* original 8b07, guest PC 0x0c073fde */
if(!s->budget--) { s->failed_pc=0x0c073fdeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073ff0; }
goto P_0c073fe0;
P_0c073fe0: /* original f46c, guest PC 0x0c073fe0 */
if(!s->budget--) { s->failed_pc=0x0c073fe0u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c073fe2;
P_0c073fe2: /* original f470, guest PC 0x0c073fe2 */
if(!s->budget--) { s->failed_pc=0x0c073fe2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'+');
goto P_0c073fe4;
P_0c073fe4: /* original f941, guest PC 0x0c073fe4 */
if(!s->budget--) { s->failed_pc=0x0c073fe4u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[4],r[18],'-');
goto P_0c073fe6;
P_0c073fe6: /* original e010, guest PC 0x0c073fe6 */
if(!s->budget--) { s->failed_pc=0x0c073fe6u; return 0; }
r[0]=0x00000010u;
goto P_0c073fe8;
P_0c073fe8: /* original f641, guest PC 0x0c073fe8 */
if(!s->budget--) { s->failed_pc=0x0c073fe8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'-');
goto P_0c073fea;
P_0c073fea: /* original f497, guest PC 0x0c073fea */
if(!s->budget--) { s->failed_pc=0x0c073feau; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c073fec;
P_0c073fec: /* original 9006, guest PC 0x0c073fec */
if(!s->budget--) { s->failed_pc=0x0c073fecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073ffcu,2);
goto P_0c073fee;
P_0c073fee: /* original f467, guest PC 0x0c073fee */
if(!s->budget--) { s->failed_pc=0x0c073feeu; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c073ff0;
P_0c073ff0: /* original f875, guest PC 0x0c073ff0 */
if(!s->budget--) { s->failed_pc=0x0c073ff0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[7]))!=0);
goto P_0c073ff2;
P_0c073ff2: /* original 8b0f, guest PC 0x0c073ff2 */
if(!s->budget--) { s->failed_pc=0x0c073ff2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074014; }
goto P_0c073ff4;
P_0c073ff4: /* original f48c, guest PC 0x0c073ff4 */
if(!s->budget--) { s->failed_pc=0x0c073ff4u; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c073ff6;
P_0c073ff6: /* original a00f, guest PC 0x0c073ff6 */
if(!s->budget--) { s->failed_pc=0x0c073ff6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c074018;
P_0c073ff8: /* original f450, guest PC 0x0c073ff8 */
if(!s->budget--) { s->failed_pc=0x0c073ff8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
if(!vf3_matrix_family(0x0c073ffau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c073ffau; return 0; } return 1;
P_0c074014: /* original f585, guest PC 0x0c074014 */
if(!s->budget--) { s->failed_pc=0x0c074014u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[8]))!=0);
goto P_0c074016;
P_0c074016: /* original 8b05, guest PC 0x0c074016 */
if(!s->budget--) { s->failed_pc=0x0c074016u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074024; }
goto P_0c074018;
P_0c074018: /* original fa41, guest PC 0x0c074018 */
if(!s->budget--) { s->failed_pc=0x0c074018u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[4],r[18],'-');
goto P_0c07401a;
P_0c07401a: /* original e018, guest PC 0x0c07401a */
if(!s->budget--) { s->failed_pc=0x0c07401au; return 0; }
r[0]=0x00000018u;
goto P_0c07401c;
P_0c07401c: /* original f841, guest PC 0x0c07401c */
if(!s->budget--) { s->failed_pc=0x0c07401cu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'-');
goto P_0c07401e;
P_0c07401e: /* original f4a7, guest PC 0x0c07401e */
if(!s->budget--) { s->failed_pc=0x0c07401eu; return 0; }
vf3_matrix_store(s,ram,10,r[4]+r[0]);
goto P_0c074020;
P_0c074020: /* original 9069, guest PC 0x0c074020 */
if(!s->budget--) { s->failed_pc=0x0c074020u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0740f6u,2);
goto P_0c074022;
P_0c074022: /* original f487, guest PC 0x0c074022 */
if(!s->budget--) { s->failed_pc=0x0c074022u; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c074024;
P_0c074024: /* original 9068, guest PC 0x0c074024 */
if(!s->budget--) { s->failed_pc=0x0c074024u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0740f8u,2);
goto P_0c074026;
P_0c074026: /* original 004e, guest PC 0x0c074026 */
if(!s->budget--) { s->failed_pc=0x0c074026u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c074028;
P_0c074028: /* original c924, guest PC 0x0c074028 */
if(!s->budget--) { s->failed_pc=0x0c074028u; return 0; }
r[0]&=36u;
goto P_0c07402a;
P_0c07402a: /* original 6503, guest PC 0x0c07402a */
if(!s->budget--) { s->failed_pc=0x0c07402au; return 0; }
r[5]=r[0];
goto P_0c07402c;
P_0c07402c: /* original 2558, guest PC 0x0c07402c */
if(!s->budget--) { s->failed_pc=0x0c07402cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c07402e;
P_0c07402e: /* original 8901, guest PC 0x0c07402e */
if(!s->budget--) { s->failed_pc=0x0c07402eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074034; }
goto P_0c074030;
P_0c074030: /* original a082, guest PC 0x0c074030 */
if(!s->budget--) { s->failed_pc=0x0c074030u; return 0; }
goto P_0c074138;
P_0c074032: /* original 0009, guest PC 0x0c074032 */
if(!s->budget--) { s->failed_pc=0x0c074032u; return 0; }
goto P_0c074034;
P_0c074034: /* original d332, guest PC 0x0c074034 */
if(!s->budget--) { s->failed_pc=0x0c074034u; return 0; }
r[3]=read(ram,0x0c074100u,4);
goto P_0c074036;
P_0c074036: /* original ec0f, guest PC 0x0c074036 */
if(!s->budget--) { s->failed_pc=0x0c074036u; return 0; }
r[12]=0x0000000fu;
goto P_0c074038;
P_0c074038: /* original 6030, guest PC 0x0c074038 */
if(!s->budget--) { s->failed_pc=0x0c074038u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c07403a;
P_0c07403a: /* original 600c, guest PC 0x0c07403a */
if(!s->budget--) { s->failed_pc=0x0c07403au; return 0; }
r[0]=r[0]&255u;
goto P_0c07403c;
P_0c07403c: /* original 2c09, guest PC 0x0c07403c */
if(!s->budget--) { s->failed_pc=0x0c07403cu; return 0; }
r[12]&=r[0];
goto P_0c07403e;
P_0c07403e: /* original 4c00, guest PC 0x0c07403e */
if(!s->budget--) { s->failed_pc=0x0c07403eu; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c074040;
P_0c074040: /* original a077, guest PC 0x0c074040 */
if(!s->budget--) { s->failed_pc=0x0c074040u; return 0; }
r[7]=r[6];
goto P_0c074132;
P_0c074042: /* original 6763, guest PC 0x0c074042 */
if(!s->budget--) { s->failed_pc=0x0c074042u; return 0; }
r[7]=r[6];
goto P_0c074044;
P_0c074044: /* original 65c3, guest PC 0x0c074044 */
if(!s->budget--) { s->failed_pc=0x0c074044u; return 0; }
r[5]=r[12];
goto P_0c074046;
P_0c074046: /* original 357c, guest PC 0x0c074046 */
if(!s->budget--) { s->failed_pc=0x0c074046u; return 0; }
r[5]+=r[7];
goto P_0c074048;
P_0c074048: /* original 4508, guest PC 0x0c074048 */
if(!s->budget--) { s->failed_pc=0x0c074048u; return 0; }
r[5]<<=2;
goto P_0c07404a;
P_0c07404a: /* original d12e, guest PC 0x0c07404a */
if(!s->budget--) { s->failed_pc=0x0c07404au; return 0; }
r[1]=read(ram,0x0c074104u,4);
goto P_0c07404c;
P_0c07404c: /* original 4500, guest PC 0x0c07404c */
if(!s->budget--) { s->failed_pc=0x0c07404cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07404e;
P_0c07404e: /* original f48d, guest PC 0x0c07404e */
if(!s->budget--) { s->failed_pc=0x0c07404eu; return 0; }
fr[4]=0;
goto P_0c074050;
P_0c074050: /* original 351c, guest PC 0x0c074050 */
if(!s->budget--) { s->failed_pc=0x0c074050u; return 0; }
r[5]+=r[1];
goto P_0c074052;
P_0c074052: /* original 6352, guest PC 0x0c074052 */
if(!s->budget--) { s->failed_pc=0x0c074052u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c074054;
P_0c074054: /* original ee07, guest PC 0x0c074054 */
if(!s->budget--) { s->failed_pc=0x0c074054u; return 0; }
r[14]=0x00000007u;
goto P_0c074056;
P_0c074056: /* original e004, guest PC 0x0c074056 */
if(!s->budget--) { s->failed_pc=0x0c074056u; return 0; }
r[0]=0x00000004u;
goto P_0c074058;
P_0c074058: /* original 2e39, guest PC 0x0c074058 */
if(!s->budget--) { s->failed_pc=0x0c074058u; return 0; }
r[14]&=r[3];
goto P_0c07405a;
P_0c07405a: /* original 2ee8, guest PC 0x0c07405a */
if(!s->budget--) { s->failed_pc=0x0c07405au; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c07405c;
P_0c07405c: /* original 8d68, guest PC 0x0c07405c */
if(!s->budget--) { s->failed_pc=0x0c07405cu; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,5,r[5]+r[0]);
if(cond) { goto P_0c074130; }
goto P_0c074060;
P_0c07405e: /* original f556, guest PC 0x0c07405e */
if(!s->budget--) { s->failed_pc=0x0c07405eu; return 0; }
vf3_matrix_load(s,ram,5,r[5]+r[0]);
goto P_0c074060;
P_0c074060: /* original 60e3, guest PC 0x0c074060 */
if(!s->budget--) { s->failed_pc=0x0c074060u; return 0; }
r[0]=r[14];
goto P_0c074062;
P_0c074062: /* original 8802, guest PC 0x0c074062 */
if(!s->budget--) { s->failed_pc=0x0c074062u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c074064;
P_0c074064: /* original 8d30, guest PC 0x0c074064 */
if(!s->budget--) { s->failed_pc=0x0c074064u; return 0; }
cond=r[17]&1u;
r[5]=0x0000001cu;
if(cond) { goto P_0c0740c8; }
goto P_0c074068;
P_0c074066: /* original e51c, guest PC 0x0c074066 */
if(!s->budget--) { s->failed_pc=0x0c074066u; return 0; }
r[5]=0x0000001cu;
goto P_0c074068;
P_0c074068: /* original 60e3, guest PC 0x0c074068 */
if(!s->budget--) { s->failed_pc=0x0c074068u; return 0; }
r[0]=r[14];
goto P_0c07406a;
P_0c07406a: /* original 8803, guest PC 0x0c07406a */
if(!s->budget--) { s->failed_pc=0x0c07406au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c07406c;
P_0c07406c: /* original 8914, guest PC 0x0c07406c */
if(!s->budget--) { s->failed_pc=0x0c07406cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074098; }
goto P_0c07406e;
P_0c07406e: /* original e103, guest PC 0x0c07406e */
if(!s->budget--) { s->failed_pc=0x0c07406eu; return 0; }
r[1]=0x00000003u;
goto P_0c074070;
P_0c074070: /* original 3e16, guest PC 0x0c074070 */
if(!s->budget--) { s->failed_pc=0x0c074070u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[1])!=0);
goto P_0c074072;
P_0c074072: /* original 893c, guest PC 0x0c074072 */
if(!s->budget--) { s->failed_pc=0x0c074072u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0740ee; }
goto P_0c074074;
P_0c074074: /* original 9041, guest PC 0x0c074074 */
if(!s->budget--) { s->failed_pc=0x0c074074u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0740fau,2);
goto P_0c074076;
P_0c074076: /* original 0e4e, guest PC 0x0c074076 */
if(!s->budget--) { s->failed_pc=0x0c074076u; return 0; }
r[14]=read(ram,r[4]+r[0],4);
goto P_0c074078;
P_0c074078: /* original a009, guest PC 0x0c074078 */
if(!s->budget--) { s->failed_pc=0x0c074078u; return 0; }
r[1]=r[6];
goto P_0c07408e;
P_0c07407a: /* original 6163, guest PC 0x0c07407a */
if(!s->budget--) { s->failed_pc=0x0c07407au; return 0; }
r[1]=r[6];
goto P_0c07407c;
P_0c07407c: /* original f7e8, guest PC 0x0c07407c */
if(!s->budget--) { s->failed_pc=0x0c07407cu; return 0; }
vf3_matrix_load(s,ram,7,r[14]);
goto P_0c07407e;
P_0c07407e: /* original f575, guest PC 0x0c07407e */
if(!s->budget--) { s->failed_pc=0x0c07407eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[7]))!=0);
goto P_0c074080;
P_0c074080: /* original 8903, guest PC 0x0c074080 */
if(!s->budget--) { s->failed_pc=0x0c074080u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07408a; }
goto P_0c074082;
P_0c074082: /* original f751, guest PC 0x0c074082 */
if(!s->budget--) { s->failed_pc=0x0c074082u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'-');
goto P_0c074084;
P_0c074084: /* original f745, guest PC 0x0c074084 */
if(!s->budget--) { s->failed_pc=0x0c074084u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[4]))!=0);
goto P_0c074086;
P_0c074086: /* original 8b00, guest PC 0x0c074086 */
if(!s->budget--) { s->failed_pc=0x0c074086u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07408a; }
goto P_0c074088;
P_0c074088: /* original f47c, guest PC 0x0c074088 */
if(!s->budget--) { s->failed_pc=0x0c074088u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c07408a;
P_0c07408a: /* original 7e0c, guest PC 0x0c07408a */
if(!s->budget--) { s->failed_pc=0x0c07408au; return 0; }
r[14]+=0x0000000cu;
goto P_0c07408c;
P_0c07408c: /* original 7101, guest PC 0x0c07408c */
if(!s->budget--) { s->failed_pc=0x0c07408cu; return 0; }
r[1]+=0x00000001u;
goto P_0c07408e;
P_0c07408e: /* original 3152, guest PC 0x0c07408e */
if(!s->budget--) { s->failed_pc=0x0c07408eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>=r[5])!=0);
goto P_0c074090;
P_0c074090: /* original 8bf4, guest PC 0x0c074090 */
if(!s->budget--) { s->failed_pc=0x0c074090u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07407c; }
goto P_0c074092;
P_0c074092: /* original f941, guest PC 0x0c074092 */
if(!s->budget--) { s->failed_pc=0x0c074092u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[4],r[18],'-');
goto P_0c074094;
P_0c074094: /* original a013, guest PC 0x0c074094 */
if(!s->budget--) { s->failed_pc=0x0c074094u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'-');
goto P_0c0740be;
P_0c074096: /* original f641, guest PC 0x0c074096 */
if(!s->budget--) { s->failed_pc=0x0c074096u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'-');
goto P_0c074098;
P_0c074098: /* original 902f, guest PC 0x0c074098 */
if(!s->budget--) { s->failed_pc=0x0c074098u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0740fau,2);
goto P_0c07409a;
P_0c07409a: /* original 014e, guest PC 0x0c07409a */
if(!s->budget--) { s->failed_pc=0x0c07409au; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c07409c;
P_0c07409c: /* original a00b, guest PC 0x0c07409c */
if(!s->budget--) { s->failed_pc=0x0c07409cu; return 0; }
r[14]=r[6];
goto P_0c0740b6;
P_0c07409e: /* original 6e63, guest PC 0x0c07409e */
if(!s->budget--) { s->failed_pc=0x0c07409eu; return 0; }
r[14]=r[6];
goto P_0c0740a0;
P_0c0740a0: /* original f718, guest PC 0x0c0740a0 */
if(!s->budget--) { s->failed_pc=0x0c0740a0u; return 0; }
vf3_matrix_load(s,ram,7,r[1]);
goto P_0c0740a2;
P_0c0740a2: /* original f755, guest PC 0x0c0740a2 */
if(!s->budget--) { s->failed_pc=0x0c0740a2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[5]))!=0);
goto P_0c0740a4;
P_0c0740a4: /* original 8905, guest PC 0x0c0740a4 */
if(!s->budget--) { s->failed_pc=0x0c0740a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0740b2; }
goto P_0c0740a6;
P_0c0740a6: /* original f37c, guest PC 0x0c0740a6 */
if(!s->budget--) { s->failed_pc=0x0c0740a6u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c0740a8;
P_0c0740a8: /* original f75c, guest PC 0x0c0740a8 */
if(!s->budget--) { s->failed_pc=0x0c0740a8u; return 0; }
vf3_matrix_move(s,7,5);
goto P_0c0740aa;
P_0c0740aa: /* original f731, guest PC 0x0c0740aa */
if(!s->budget--) { s->failed_pc=0x0c0740aau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c0740ac;
P_0c0740ac: /* original f745, guest PC 0x0c0740ac */
if(!s->budget--) { s->failed_pc=0x0c0740acu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[4]))!=0);
goto P_0c0740ae;
P_0c0740ae: /* original 8b00, guest PC 0x0c0740ae */
if(!s->budget--) { s->failed_pc=0x0c0740aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0740b2; }
goto P_0c0740b0;
P_0c0740b0: /* original f47c, guest PC 0x0c0740b0 */
if(!s->budget--) { s->failed_pc=0x0c0740b0u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c0740b2;
P_0c0740b2: /* original 710c, guest PC 0x0c0740b2 */
if(!s->budget--) { s->failed_pc=0x0c0740b2u; return 0; }
r[1]+=0x0000000cu;
goto P_0c0740b4;
P_0c0740b4: /* original 7e01, guest PC 0x0c0740b4 */
if(!s->budget--) { s->failed_pc=0x0c0740b4u; return 0; }
r[14]+=0x00000001u;
goto P_0c0740b6;
P_0c0740b6: /* original 3e52, guest PC 0x0c0740b6 */
if(!s->budget--) { s->failed_pc=0x0c0740b6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[5])!=0);
goto P_0c0740b8;
P_0c0740b8: /* original 8bf2, guest PC 0x0c0740b8 */
if(!s->budget--) { s->failed_pc=0x0c0740b8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0740a0; }
goto P_0c0740ba;
P_0c0740ba: /* original f640, guest PC 0x0c0740ba */
if(!s->budget--) { s->failed_pc=0x0c0740bau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'+');
goto P_0c0740bc;
P_0c0740bc: /* original f940, guest PC 0x0c0740bc */
if(!s->budget--) { s->failed_pc=0x0c0740bcu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[4],r[18],'+');
goto P_0c0740be;
P_0c0740be: /* original e010, guest PC 0x0c0740be */
if(!s->budget--) { s->failed_pc=0x0c0740beu; return 0; }
r[0]=0x00000010u;
goto P_0c0740c0;
P_0c0740c0: /* original f497, guest PC 0x0c0740c0 */
if(!s->budget--) { s->failed_pc=0x0c0740c0u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c0740c2;
P_0c0740c2: /* original 901b, guest PC 0x0c0740c2 */
if(!s->budget--) { s->failed_pc=0x0c0740c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0740fcu,2);
goto P_0c0740c4;
P_0c0740c4: /* original a034, guest PC 0x0c0740c4 */
if(!s->budget--) { s->failed_pc=0x0c0740c4u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c074130;
P_0c0740c6: /* original f467, guest PC 0x0c0740c6 */
if(!s->budget--) { s->failed_pc=0x0c0740c6u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0740c8;
P_0c0740c8: /* original 9017, guest PC 0x0c0740c8 */
if(!s->budget--) { s->failed_pc=0x0c0740c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0740fau,2);
goto P_0c0740ca;
P_0c0740ca: /* original 0e4e, guest PC 0x0c0740ca */
if(!s->budget--) { s->failed_pc=0x0c0740cau; return 0; }
r[14]=read(ram,r[4]+r[0],4);
goto P_0c0740cc;
P_0c0740cc: /* original a00a, guest PC 0x0c0740cc */
if(!s->budget--) { s->failed_pc=0x0c0740ccu; return 0; }
r[1]=r[6];
goto P_0c0740e4;
P_0c0740ce: /* original 6163, guest PC 0x0c0740ce */
if(!s->budget--) { s->failed_pc=0x0c0740ceu; return 0; }
r[1]=r[6];
goto P_0c0740d0;
P_0c0740d0: /* original e008, guest PC 0x0c0740d0 */
if(!s->budget--) { s->failed_pc=0x0c0740d0u; return 0; }
r[0]=0x00000008u;
goto P_0c0740d2;
P_0c0740d2: /* original f7e6, guest PC 0x0c0740d2 */
if(!s->budget--) { s->failed_pc=0x0c0740d2u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0740d4;
P_0c0740d4: /* original f575, guest PC 0x0c0740d4 */
if(!s->budget--) { s->failed_pc=0x0c0740d4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[7]))!=0);
goto P_0c0740d6;
P_0c0740d6: /* original 8903, guest PC 0x0c0740d6 */
if(!s->budget--) { s->failed_pc=0x0c0740d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0740e0; }
goto P_0c0740d8;
P_0c0740d8: /* original f751, guest PC 0x0c0740d8 */
if(!s->budget--) { s->failed_pc=0x0c0740d8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'-');
goto P_0c0740da;
P_0c0740da: /* original f475, guest PC 0x0c0740da */
if(!s->budget--) { s->failed_pc=0x0c0740dau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[7]))!=0);
goto P_0c0740dc;
P_0c0740dc: /* original 8b00, guest PC 0x0c0740dc */
if(!s->budget--) { s->failed_pc=0x0c0740dcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0740e0; }
goto P_0c0740de;
P_0c0740de: /* original f47c, guest PC 0x0c0740de */
if(!s->budget--) { s->failed_pc=0x0c0740deu; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c0740e0;
P_0c0740e0: /* original 7e0c, guest PC 0x0c0740e0 */
if(!s->budget--) { s->failed_pc=0x0c0740e0u; return 0; }
r[14]+=0x0000000cu;
goto P_0c0740e2;
P_0c0740e2: /* original 7101, guest PC 0x0c0740e2 */
if(!s->budget--) { s->failed_pc=0x0c0740e2u; return 0; }
r[1]+=0x00000001u;
goto P_0c0740e4;
P_0c0740e4: /* original 3152, guest PC 0x0c0740e4 */
if(!s->budget--) { s->failed_pc=0x0c0740e4u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>=r[5])!=0);
goto P_0c0740e6;
P_0c0740e6: /* original 8bf3, guest PC 0x0c0740e6 */
if(!s->budget--) { s->failed_pc=0x0c0740e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0740d0; }
goto P_0c0740e8;
P_0c0740e8: /* original fa41, guest PC 0x0c0740e8 */
if(!s->budget--) { s->failed_pc=0x0c0740e8u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[4],r[18],'-');
goto P_0c0740ea;
P_0c0740ea: /* original a01d, guest PC 0x0c0740ea */
if(!s->budget--) { s->failed_pc=0x0c0740eau; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'-');
goto P_0c074128;
P_0c0740ec: /* original f841, guest PC 0x0c0740ec */
if(!s->budget--) { s->failed_pc=0x0c0740ecu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'-');
goto P_0c0740ee;
P_0c0740ee: /* original 9004, guest PC 0x0c0740ee */
if(!s->budget--) { s->failed_pc=0x0c0740eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0740fau,2);
goto P_0c0740f0;
P_0c0740f0: /* original 0e4e, guest PC 0x0c0740f0 */
if(!s->budget--) { s->failed_pc=0x0c0740f0u; return 0; }
r[14]=read(ram,r[4]+r[0],4);
goto P_0c0740f2;
P_0c0740f2: /* original a015, guest PC 0x0c0740f2 */
if(!s->budget--) { s->failed_pc=0x0c0740f2u; return 0; }
r[1]=r[6];
goto P_0c074120;
P_0c0740f4: /* original 6163, guest PC 0x0c0740f4 */
if(!s->budget--) { s->failed_pc=0x0c0740f4u; return 0; }
r[1]=r[6];
if(!vf3_matrix_family(0x0c0740f6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0740f6u; return 0; } return 1;
P_0c074108: /* original e008, guest PC 0x0c074108 */
if(!s->budget--) { s->failed_pc=0x0c074108u; return 0; }
r[0]=0x00000008u;
goto P_0c07410a;
P_0c07410a: /* original f7e6, guest PC 0x0c07410a */
if(!s->budget--) { s->failed_pc=0x0c07410au; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c07410c;
P_0c07410c: /* original f755, guest PC 0x0c07410c */
if(!s->budget--) { s->failed_pc=0x0c07410cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[5]))!=0);
goto P_0c07410e;
P_0c07410e: /* original 8905, guest PC 0x0c07410e */
if(!s->budget--) { s->failed_pc=0x0c07410eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07411c; }
goto P_0c074110;
P_0c074110: /* original f37c, guest PC 0x0c074110 */
if(!s->budget--) { s->failed_pc=0x0c074110u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c074112;
P_0c074112: /* original f75c, guest PC 0x0c074112 */
if(!s->budget--) { s->failed_pc=0x0c074112u; return 0; }
vf3_matrix_move(s,7,5);
goto P_0c074114;
P_0c074114: /* original f731, guest PC 0x0c074114 */
if(!s->budget--) { s->failed_pc=0x0c074114u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c074116;
P_0c074116: /* original f745, guest PC 0x0c074116 */
if(!s->budget--) { s->failed_pc=0x0c074116u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[4]))!=0);
goto P_0c074118;
P_0c074118: /* original 8b00, guest PC 0x0c074118 */
if(!s->budget--) { s->failed_pc=0x0c074118u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07411c; }
goto P_0c07411a;
P_0c07411a: /* original f47c, guest PC 0x0c07411a */
if(!s->budget--) { s->failed_pc=0x0c07411au; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c07411c;
P_0c07411c: /* original 7e0c, guest PC 0x0c07411c */
if(!s->budget--) { s->failed_pc=0x0c07411cu; return 0; }
r[14]+=0x0000000cu;
goto P_0c07411e;
P_0c07411e: /* original 7101, guest PC 0x0c07411e */
if(!s->budget--) { s->failed_pc=0x0c07411eu; return 0; }
r[1]+=0x00000001u;
goto P_0c074120;
P_0c074120: /* original 3152, guest PC 0x0c074120 */
if(!s->budget--) { s->failed_pc=0x0c074120u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>=r[5])!=0);
goto P_0c074122;
P_0c074122: /* original 8bf1, guest PC 0x0c074122 */
if(!s->budget--) { s->failed_pc=0x0c074122u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074108; }
goto P_0c074124;
P_0c074124: /* original f840, guest PC 0x0c074124 */
if(!s->budget--) { s->failed_pc=0x0c074124u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'+');
goto P_0c074126;
P_0c074126: /* original fa40, guest PC 0x0c074126 */
if(!s->budget--) { s->failed_pc=0x0c074126u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[4],r[18],'+');
goto P_0c074128;
P_0c074128: /* original e018, guest PC 0x0c074128 */
if(!s->budget--) { s->failed_pc=0x0c074128u; return 0; }
r[0]=0x00000018u;
goto P_0c07412a;
P_0c07412a: /* original f4a7, guest PC 0x0c07412a */
if(!s->budget--) { s->failed_pc=0x0c07412au; return 0; }
vf3_matrix_store(s,ram,10,r[4]+r[0]);
goto P_0c07412c;
P_0c07412c: /* original 9084, guest PC 0x0c07412c */
if(!s->budget--) { s->failed_pc=0x0c07412cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074238u,2);
goto P_0c07412e;
P_0c07412e: /* original f487, guest PC 0x0c07412e */
if(!s->budget--) { s->failed_pc=0x0c07412eu; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c074130;
P_0c074130: /* original 7701, guest PC 0x0c074130 */
if(!s->budget--) { s->failed_pc=0x0c074130u; return 0; }
r[7]+=0x00000001u;
goto P_0c074132;
P_0c074132: /* original e502, guest PC 0x0c074132 */
if(!s->budget--) { s->failed_pc=0x0c074132u; return 0; }
r[5]=0x00000002u;
goto P_0c074134;
P_0c074134: /* original 3752, guest PC 0x0c074134 */
if(!s->budget--) { s->failed_pc=0x0c074134u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[5])!=0);
goto P_0c074136;
P_0c074136: /* original 8b85, guest PC 0x0c074136 */
if(!s->budget--) { s->failed_pc=0x0c074136u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074044; }
goto P_0c074138;
P_0c074138: /* original 6cf6, guest PC 0x0c074138 */
if(!s->budget--) { s->failed_pc=0x0c074138u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07413a;
P_0c07413a: /* original 000b, guest PC 0x0c07413a */
if(!s->budget--) { s->failed_pc=0x0c07413au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07413c: /* original 6ef6, guest PC 0x0c07413c */
if(!s->budget--) { s->failed_pc=0x0c07413cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07413eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
