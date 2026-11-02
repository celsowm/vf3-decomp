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
int vf3_away_batch8_adapter_13(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c062c24u: goto P_0c062c24;
case 0x0c062c26u: goto P_0c062c26;
case 0x0c062c28u: goto P_0c062c28;
case 0x0c062c2au: goto P_0c062c2a;
case 0x0c062c2cu: goto P_0c062c2c;
case 0x0c062c2eu: goto P_0c062c2e;
case 0x0c062c30u: goto P_0c062c30;
case 0x0c062c32u: goto P_0c062c32;
case 0x0c062c34u: goto P_0c062c34;
case 0x0c062c36u: goto P_0c062c36;
case 0x0c062c38u: goto P_0c062c38;
case 0x0c062c3au: goto P_0c062c3a;
case 0x0c062c3cu: goto P_0c062c3c;
case 0x0c062c3eu: goto P_0c062c3e;
case 0x0c062c40u: goto P_0c062c40;
case 0x0c062c42u: goto P_0c062c42;
case 0x0c062c44u: goto P_0c062c44;
case 0x0c062c46u: goto P_0c062c46;
case 0x0c062c48u: goto P_0c062c48;
case 0x0c062c4au: goto P_0c062c4a;
case 0x0c062c4cu: goto P_0c062c4c;
case 0x0c062e7eu: goto P_0c062e7e;
case 0x0c062e80u: goto P_0c062e80;
case 0x0c062e82u: goto P_0c062e82;
case 0x0c062e84u: goto P_0c062e84;
case 0x0c062e86u: goto P_0c062e86;
case 0x0c062e88u: goto P_0c062e88;
case 0x0c062e8au: goto P_0c062e8a;
case 0x0c062e8cu: goto P_0c062e8c;
case 0x0c062f60u: goto P_0c062f60;
case 0x0c062f62u: goto P_0c062f62;
case 0x0c062f64u: goto P_0c062f64;
case 0x0c062f66u: goto P_0c062f66;
case 0x0c062f68u: goto P_0c062f68;
case 0x0c062f6au: goto P_0c062f6a;
case 0x0c062f6cu: goto P_0c062f6c;
case 0x0c062f6eu: goto P_0c062f6e;
case 0x0c062f70u: goto P_0c062f70;
case 0x0c062f72u: goto P_0c062f72;
case 0x0c062f74u: goto P_0c062f74;
case 0x0c062f76u: goto P_0c062f76;
case 0x0c062f78u: goto P_0c062f78;
case 0x0c062f7au: goto P_0c062f7a;
case 0x0c062f7cu: goto P_0c062f7c;
case 0x0c062f7eu: goto P_0c062f7e;
case 0x0c062f80u: goto P_0c062f80;
case 0x0c062f82u: goto P_0c062f82;
case 0x0c062f84u: goto P_0c062f84;
case 0x0c062f86u: goto P_0c062f86;
case 0x0c062f88u: goto P_0c062f88;
case 0x0c062f8au: goto P_0c062f8a;
case 0x0c062f8cu: goto P_0c062f8c;
case 0x0c062f8eu: goto P_0c062f8e;
case 0x0c062f90u: goto P_0c062f90;
case 0x0c062f92u: goto P_0c062f92;
case 0x0c062f94u: goto P_0c062f94;
case 0x0c062f96u: goto P_0c062f96;
case 0x0c062f98u: goto P_0c062f98;
case 0x0c062f9au: goto P_0c062f9a;
case 0x0c062f9cu: goto P_0c062f9c;
case 0x0c062f9eu: goto P_0c062f9e;
case 0x0c062fa0u: goto P_0c062fa0;
case 0x0c062fa2u: goto P_0c062fa2;
case 0x0c062fa4u: goto P_0c062fa4;
case 0x0c062fa6u: goto P_0c062fa6;
case 0x0c062fa8u: goto P_0c062fa8;
case 0x0c062faau: goto P_0c062faa;
case 0x0c062facu: goto P_0c062fac;
case 0x0c062faeu: goto P_0c062fae;
case 0x0c062fb0u: goto P_0c062fb0;
case 0x0c062fb2u: goto P_0c062fb2;
case 0x0c062fb4u: goto P_0c062fb4;
case 0x0c062fb6u: goto P_0c062fb6;
case 0x0c062fb8u: goto P_0c062fb8;
case 0x0c062fbau: goto P_0c062fba;
case 0x0c062fbcu: goto P_0c062fbc;
case 0x0c062fbeu: goto P_0c062fbe;
case 0x0c062fc0u: goto P_0c062fc0;
case 0x0c0631d8u: goto P_0c0631d8;
case 0x0c0631dau: goto P_0c0631da;
case 0x0c0631dcu: goto P_0c0631dc;
case 0x0c0631deu: goto P_0c0631de;
case 0x0c0631e0u: goto P_0c0631e0;
case 0x0c0631e2u: goto P_0c0631e2;
case 0x0c0631e4u: goto P_0c0631e4;
case 0x0c0631e6u: goto P_0c0631e6;
case 0x0c0631e8u: goto P_0c0631e8;
case 0x0c0631eau: goto P_0c0631ea;
case 0x0c0631ecu: goto P_0c0631ec;
case 0x0c0631eeu: goto P_0c0631ee;
case 0x0c0631f0u: goto P_0c0631f0;
case 0x0c0631f2u: goto P_0c0631f2;
case 0x0c0631f4u: goto P_0c0631f4;
case 0x0c0631f6u: goto P_0c0631f6;
case 0x0c0631f8u: goto P_0c0631f8;
case 0x0c0631fau: goto P_0c0631fa;
case 0x0c0631fcu: goto P_0c0631fc;
case 0x0c0631feu: goto P_0c0631fe;
case 0x0c063200u: goto P_0c063200;
case 0x0c063202u: goto P_0c063202;
case 0x0c063204u: goto P_0c063204;
case 0x0c063206u: goto P_0c063206;
case 0x0c063208u: goto P_0c063208;
case 0x0c06320au: goto P_0c06320a;
case 0x0c06320cu: goto P_0c06320c;
case 0x0c06320eu: goto P_0c06320e;
case 0x0c063210u: goto P_0c063210;
case 0x0c063212u: goto P_0c063212;
case 0x0c063214u: goto P_0c063214;
case 0x0c063216u: goto P_0c063216;
case 0x0c063218u: goto P_0c063218;
case 0x0c06321au: goto P_0c06321a;
case 0x0c06321cu: goto P_0c06321c;
case 0x0c06321eu: goto P_0c06321e;
case 0x0c063220u: goto P_0c063220;
case 0x0c063222u: goto P_0c063222;
case 0x0c063224u: goto P_0c063224;
case 0x0c063226u: goto P_0c063226;
case 0x0c063228u: goto P_0c063228;
case 0x0c06322au: goto P_0c06322a;
case 0x0c06322cu: goto P_0c06322c;
case 0x0c06322eu: goto P_0c06322e;
case 0x0c063230u: goto P_0c063230;
case 0x0c063232u: goto P_0c063232;
case 0x0c063234u: goto P_0c063234;
case 0x0c063236u: goto P_0c063236;
case 0x0c063238u: goto P_0c063238;
case 0x0c06323au: goto P_0c06323a;
case 0x0c06323cu: goto P_0c06323c;
case 0x0c06323eu: goto P_0c06323e;
case 0x0c063240u: goto P_0c063240;
case 0x0c063242u: goto P_0c063242;
case 0x0c063244u: goto P_0c063244;
case 0x0c063246u: goto P_0c063246;
case 0x0c063248u: goto P_0c063248;
case 0x0c06324au: goto P_0c06324a;
case 0x0c06324cu: goto P_0c06324c;
case 0x0c06324eu: goto P_0c06324e;
case 0x0c063250u: goto P_0c063250;
case 0x0c063252u: goto P_0c063252;
case 0x0c063254u: goto P_0c063254;
case 0x0c063256u: goto P_0c063256;
case 0x0c063258u: goto P_0c063258;
case 0x0c06325au: goto P_0c06325a;
case 0x0c06325cu: goto P_0c06325c;
case 0x0c06325eu: goto P_0c06325e;
case 0x0c063260u: goto P_0c063260;
case 0x0c063262u: goto P_0c063262;
case 0x0c063264u: goto P_0c063264;
case 0x0c063266u: goto P_0c063266;
case 0x0c063268u: goto P_0c063268;
case 0x0c06326au: goto P_0c06326a;
case 0x0c06326cu: goto P_0c06326c;
case 0x0c06326eu: goto P_0c06326e;
case 0x0c063270u: goto P_0c063270;
case 0x0c063272u: goto P_0c063272;
case 0x0c063274u: goto P_0c063274;
case 0x0c063276u: goto P_0c063276;
case 0x0c063278u: goto P_0c063278;
case 0x0c06327au: goto P_0c06327a;
case 0x0c06327cu: goto P_0c06327c;
case 0x0c06327eu: goto P_0c06327e;
case 0x0c063280u: goto P_0c063280;
case 0x0c063282u: goto P_0c063282;
case 0x0c063284u: goto P_0c063284;
case 0x0c063286u: goto P_0c063286;
case 0x0c063288u: goto P_0c063288;
case 0x0c06328au: goto P_0c06328a;
case 0x0c06328cu: goto P_0c06328c;
case 0x0c06328eu: goto P_0c06328e;
case 0x0c063290u: goto P_0c063290;
case 0x0c063292u: goto P_0c063292;
case 0x0c063294u: goto P_0c063294;
case 0x0c063296u: goto P_0c063296;
case 0x0c063298u: goto P_0c063298;
case 0x0c06329au: goto P_0c06329a;
case 0x0c06329cu: goto P_0c06329c;
case 0x0c06329eu: goto P_0c06329e;
case 0x0c0632a0u: goto P_0c0632a0;
case 0x0c0632a2u: goto P_0c0632a2;
case 0x0c0632a4u: goto P_0c0632a4;
case 0x0c0632a6u: goto P_0c0632a6;
case 0x0c0632a8u: goto P_0c0632a8;
case 0x0c0632aau: goto P_0c0632aa;
case 0x0c0632acu: goto P_0c0632ac;
case 0x0c0632aeu: goto P_0c0632ae;
case 0x0c0632b0u: goto P_0c0632b0;
case 0x0c0632b2u: goto P_0c0632b2;
case 0x0c0632b4u: goto P_0c0632b4;
case 0x0c0632b6u: goto P_0c0632b6;
case 0x0c0632b8u: goto P_0c0632b8;
case 0x0c0632bau: goto P_0c0632ba;
case 0x0c0632bcu: goto P_0c0632bc;
case 0x0c0632beu: goto P_0c0632be;
case 0x0c0632c0u: goto P_0c0632c0;
case 0x0c0632c2u: goto P_0c0632c2;
case 0x0c0632c4u: goto P_0c0632c4;
case 0x0c0632c6u: goto P_0c0632c6;
case 0x0c0632c8u: goto P_0c0632c8;
case 0x0c0632cau: goto P_0c0632ca;
case 0x0c0632ccu: goto P_0c0632cc;
case 0x0c0632ceu: goto P_0c0632ce;
case 0x0c0632d0u: goto P_0c0632d0;
default: return vf3_matrix_family(target,s,ram);
}
P_0c062c24: /* original 2fd6, guest PC 0x0c062c24 */
if(!s->budget--) { s->failed_pc=0x0c062c24u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062c26;
P_0c062c26: /* original e700, guest PC 0x0c062c26 */
if(!s->budget--) { s->failed_pc=0x0c062c26u; return 0; }
r[7]=0x00000000u;
goto P_0c062c28;
P_0c062c28: /* original d51b, guest PC 0x0c062c28 */
if(!s->budget--) { s->failed_pc=0x0c062c28u; return 0; }
r[5]=read(ram,0x0c062c98u,4);
goto P_0c062c2a;
P_0c062c2a: /* original 7ffc, guest PC 0x0c062c2a */
if(!s->budget--) { s->failed_pc=0x0c062c2au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c062c2c;
P_0c062c2c: /* original dd1b, guest PC 0x0c062c2c */
if(!s->budget--) { s->failed_pc=0x0c062c2cu; return 0; }
r[13]=read(ram,0x0c062c9cu,4);
goto P_0c062c2e;
P_0c062c2e: /* original 6653, guest PC 0x0c062c2e */
if(!s->budget--) { s->failed_pc=0x0c062c2eu; return 0; }
r[6]=r[5];
goto P_0c062c30;
P_0c062c30: /* original 912f, guest PC 0x0c062c30 */
if(!s->budget--) { s->failed_pc=0x0c062c30u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062c92u,2);
goto P_0c062c32;
P_0c062c32: /* original 2f52, guest PC 0x0c062c32 */
if(!s->budget--) { s->failed_pc=0x0c062c32u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c062c34;
P_0c062c34: /* original 3640, guest PC 0x0c062c34 */
if(!s->budget--) { s->failed_pc=0x0c062c34u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[4])!=0);
goto P_0c062c36;
P_0c062c36: /* original 8f03, guest PC 0x0c062c36 */
if(!s->budget--) { s->failed_pc=0x0c062c36u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(!cond) { goto P_0c062c40; }
goto P_0c062c3a;
P_0c062c38: /* original 7701, guest PC 0x0c062c38 */
if(!s->budget--) { s->failed_pc=0x0c062c38u; return 0; }
r[7]+=0x00000001u;
goto P_0c062c3a;
P_0c062c3a: /* original 6251, guest PC 0x0c062c3a */
if(!s->budget--) { s->failed_pc=0x0c062c3au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c062c3c;
P_0c062c3c: /* original 22d9, guest PC 0x0c062c3c */
if(!s->budget--) { s->failed_pc=0x0c062c3cu; return 0; }
r[2]&=r[13];
goto P_0c062c3e;
P_0c062c3e: /* original 2521, guest PC 0x0c062c3e */
if(!s->budget--) { s->failed_pc=0x0c062c3eu; return 0; }
write(ram,r[5],r[2],2);
goto P_0c062c40;
P_0c062c40: /* original 754c, guest PC 0x0c062c40 */
if(!s->budget--) { s->failed_pc=0x0c062c40u; return 0; }
r[5]+=0x0000004cu;
goto P_0c062c42;
P_0c062c42: /* original 3713, guest PC 0x0c062c42 */
if(!s->budget--) { s->failed_pc=0x0c062c42u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[1])!=0);
goto P_0c062c44;
P_0c062c44: /* original 8ff6, guest PC 0x0c062c44 */
if(!s->budget--) { s->failed_pc=0x0c062c44u; return 0; }
cond=r[17]&1u;
r[6]+=0x0000004cu;
if(!cond) { goto P_0c062c34; }
goto P_0c062c48;
P_0c062c46: /* original 764c, guest PC 0x0c062c46 */
if(!s->budget--) { s->failed_pc=0x0c062c46u; return 0; }
r[6]+=0x0000004cu;
goto P_0c062c48;
P_0c062c48: /* original 7f04, guest PC 0x0c062c48 */
if(!s->budget--) { s->failed_pc=0x0c062c48u; return 0; }
r[15]+=0x00000004u;
goto P_0c062c4a;
P_0c062c4a: /* original 000b, guest PC 0x0c062c4a */
if(!s->budget--) { s->failed_pc=0x0c062c4au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c062c4c: /* original 6df6, guest PC 0x0c062c4c */
if(!s->budget--) { s->failed_pc=0x0c062c4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
if(!vf3_matrix_family(0x0c062c4eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062c4eu; return 0; } return 1;
P_0c062e7e: /* original 4609, guest PC 0x0c062e7e */
if(!s->budget--) { s->failed_pc=0x0c062e7eu; return 0; }
r[6]>>=2;
goto P_0c062e80;
P_0c062e80: /* original 6056, guest PC 0x0c062e80 */
if(!s->budget--) { s->failed_pc=0x0c062e80u; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[0]=tmp;
goto P_0c062e82;
P_0c062e82: /* original 4610, guest PC 0x0c062e82 */
if(!s->budget--) { s->failed_pc=0x0c062e82u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c062e84;
P_0c062e84: /* original 2402, guest PC 0x0c062e84 */
if(!s->budget--) { s->failed_pc=0x0c062e84u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c062e86;
P_0c062e86: /* original 8ffb, guest PC 0x0c062e86 */
if(!s->budget--) { s->failed_pc=0x0c062e86u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c062e80; }
goto P_0c062e8a;
P_0c062e88: /* original 7404, guest PC 0x0c062e88 */
if(!s->budget--) { s->failed_pc=0x0c062e88u; return 0; }
r[4]+=0x00000004u;
goto P_0c062e8a;
P_0c062e8a: /* original 000b, guest PC 0x0c062e8a */
if(!s->budget--) { s->failed_pc=0x0c062e8au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062e8c: /* original 0009, guest PC 0x0c062e8c */
if(!s->budget--) { s->failed_pc=0x0c062e8cu; return 0; }
if(!vf3_matrix_family(0x0c062e8eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062e8eu; return 0; } return 1;
P_0c062f60: /* original d638, guest PC 0x0c062f60 */
if(!s->budget--) { s->failed_pc=0x0c062f60u; return 0; }
r[6]=read(ram,0x0c063044u,4);
goto P_0c062f62;
P_0c062f62: /* original e400, guest PC 0x0c062f62 */
if(!s->budget--) { s->failed_pc=0x0c062f62u; return 0; }
r[4]=0x00000000u;
goto P_0c062f64;
P_0c062f64: /* original 2642, guest PC 0x0c062f64 */
if(!s->budget--) { s->failed_pc=0x0c062f64u; return 0; }
write(ram,r[6],r[4],4);
goto P_0c062f66;
P_0c062f66: /* original e301, guest PC 0x0c062f66 */
if(!s->budget--) { s->failed_pc=0x0c062f66u; return 0; }
r[3]=0x00000001u;
goto P_0c062f68;
P_0c062f68: /* original d537, guest PC 0x0c062f68 */
if(!s->budget--) { s->failed_pc=0x0c062f68u; return 0; }
r[5]=read(ram,0x0c063048u,4);
goto P_0c062f6a;
P_0c062f6a: /* original 2532, guest PC 0x0c062f6a */
if(!s->budget--) { s->failed_pc=0x0c062f6au; return 0; }
write(ram,r[5],r[3],4);
goto P_0c062f6c;
P_0c062f6c: /* original 2542, guest PC 0x0c062f6c */
if(!s->budget--) { s->failed_pc=0x0c062f6cu; return 0; }
write(ram,r[5],r[4],4);
goto P_0c062f6e;
P_0c062f6e: /* original 6362, guest PC 0x0c062f6e */
if(!s->budget--) { s->failed_pc=0x0c062f6eu; return 0; }
tmp=read(ram,r[6],4);
r[3]=tmp;
goto P_0c062f70;
P_0c062f70: /* original 2338, guest PC 0x0c062f70 */
if(!s->budget--) { s->failed_pc=0x0c062f70u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c062f72;
P_0c062f72: /* original 8bfc, guest PC 0x0c062f72 */
if(!s->budget--) { s->failed_pc=0x0c062f72u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062f6e; }
goto P_0c062f74;
P_0c062f74: /* original d724, guest PC 0x0c062f74 */
if(!s->budget--) { s->failed_pc=0x0c062f74u; return 0; }
r[7]=read(ram,0x0c063008u,4);
goto P_0c062f76;
P_0c062f76: /* original 6672, guest PC 0x0c062f76 */
if(!s->budget--) { s->failed_pc=0x0c062f76u; return 0; }
tmp=read(ram,r[7],4);
r[6]=tmp;
goto P_0c062f78;
P_0c062f78: /* original e3fe, guest PC 0x0c062f78 */
if(!s->budget--) { s->failed_pc=0x0c062f78u; return 0; }
r[3]=0xfffffffeu;
goto P_0c062f7a;
P_0c062f7a: /* original 2639, guest PC 0x0c062f7a */
if(!s->budget--) { s->failed_pc=0x0c062f7au; return 0; }
r[6]&=r[3];
goto P_0c062f7c;
P_0c062f7c: /* original 2762, guest PC 0x0c062f7c */
if(!s->budget--) { s->failed_pc=0x0c062f7cu; return 0; }
write(ram,r[7],r[6],4);
goto P_0c062f7e;
P_0c062f7e: /* original e201, guest PC 0x0c062f7e */
if(!s->budget--) { s->failed_pc=0x0c062f7eu; return 0; }
r[2]=0x00000001u;
goto P_0c062f80;
P_0c062f80: /* original 2522, guest PC 0x0c062f80 */
if(!s->budget--) { s->failed_pc=0x0c062f80u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c062f82;
P_0c062f82: /* original 2542, guest PC 0x0c062f82 */
if(!s->budget--) { s->failed_pc=0x0c062f82u; return 0; }
write(ram,r[5],r[4],4);
goto P_0c062f84;
P_0c062f84: /* original d529, guest PC 0x0c062f84 */
if(!s->budget--) { s->failed_pc=0x0c062f84u; return 0; }
r[5]=read(ram,0x0c06302cu,4);
goto P_0c062f86;
P_0c062f86: /* original e700, guest PC 0x0c062f86 */
if(!s->budget--) { s->failed_pc=0x0c062f86u; return 0; }
r[7]=0x00000000u;
goto P_0c062f88;
P_0c062f88: /* original 903b, guest PC 0x0c062f88 */
if(!s->budget--) { s->failed_pc=0x0c062f88u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063002u,2);
goto P_0c062f8a;
P_0c062f8a: /* original e608, guest PC 0x0c062f8a */
if(!s->budget--) { s->failed_pc=0x0c062f8au; return 0; }
r[6]=0x00000008u;
goto P_0c062f8c;
P_0c062f8c: /* original d129, guest PC 0x0c062f8c */
if(!s->budget--) { s->failed_pc=0x0c062f8cu; return 0; }
r[1]=read(ram,0x0c063034u,4);
goto P_0c062f8e;
P_0c062f8e: /* original 2542, guest PC 0x0c062f8e */
if(!s->budget--) { s->failed_pc=0x0c062f8eu; return 0; }
write(ram,r[5],r[4],4);
goto P_0c062f90;
P_0c062f90: /* original 1541, guest PC 0x0c062f90 */
if(!s->budget--) { s->failed_pc=0x0c062f90u; return 0; }
write(ram,r[5]+4,r[4],4);
goto P_0c062f92;
P_0c062f92: /* original d527, guest PC 0x0c062f92 */
if(!s->budget--) { s->failed_pc=0x0c062f92u; return 0; }
r[5]=read(ram,0x0c063030u,4);
goto P_0c062f94;
P_0c062f94: /* original d228, guest PC 0x0c062f94 */
if(!s->budget--) { s->failed_pc=0x0c062f94u; return 0; }
r[2]=read(ram,0x0c063038u,4);
goto P_0c062f96;
P_0c062f96: /* original 2542, guest PC 0x0c062f96 */
if(!s->budget--) { s->failed_pc=0x0c062f96u; return 0; }
write(ram,r[5],r[4],4);
goto P_0c062f98;
P_0c062f98: /* original 1541, guest PC 0x0c062f98 */
if(!s->budget--) { s->failed_pc=0x0c062f98u; return 0; }
write(ram,r[5]+4,r[4],4);
goto P_0c062f9a;
P_0c062f9a: /* original e507, guest PC 0x0c062f9a */
if(!s->budget--) { s->failed_pc=0x0c062f9au; return 0; }
r[5]=0x00000007u;
goto P_0c062f9c;
P_0c062f9c: /* original d327, guest PC 0x0c062f9c */
if(!s->budget--) { s->failed_pc=0x0c062f9cu; return 0; }
r[3]=read(ram,0x0c06303cu,4);
goto P_0c062f9e;
P_0c062f9e: /* original 2142, guest PC 0x0c062f9e */
if(!s->budget--) { s->failed_pc=0x0c062f9eu; return 0; }
write(ram,r[1],r[4],4);
goto P_0c062fa0;
P_0c062fa0: /* original 2252, guest PC 0x0c062fa0 */
if(!s->budget--) { s->failed_pc=0x0c062fa0u; return 0; }
write(ram,r[2],r[5],4);
goto P_0c062fa2;
P_0c062fa2: /* original 2352, guest PC 0x0c062fa2 */
if(!s->budget--) { s->failed_pc=0x0c062fa2u; return 0; }
write(ram,r[3],r[5],4);
goto P_0c062fa4;
P_0c062fa4: /* original d126, guest PC 0x0c062fa4 */
if(!s->budget--) { s->failed_pc=0x0c062fa4u; return 0; }
r[1]=read(ram,0x0c063040u,4);
goto P_0c062fa6;
P_0c062fa6: /* original 6573, guest PC 0x0c062fa6 */
if(!s->budget--) { s->failed_pc=0x0c062fa6u; return 0; }
r[5]=r[7];
goto P_0c062fa8;
P_0c062fa8: /* original 6213, guest PC 0x0c062fa8 */
if(!s->budget--) { s->failed_pc=0x0c062fa8u; return 0; }
r[2]=r[1];
goto P_0c062faa;
P_0c062faa: /* original 325c, guest PC 0x0c062faa */
if(!s->budget--) { s->failed_pc=0x0c062faau; return 0; }
r[2]+=r[5];
goto P_0c062fac;
P_0c062fac: /* original 1246, guest PC 0x0c062fac */
if(!s->budget--) { s->failed_pc=0x0c062facu; return 0; }
write(ram,r[2]+24,r[4],4);
goto P_0c062fae;
P_0c062fae: /* original 6313, guest PC 0x0c062fae */
if(!s->budget--) { s->failed_pc=0x0c062faeu; return 0; }
r[3]=r[1];
goto P_0c062fb0;
P_0c062fb0: /* original 335c, guest PC 0x0c062fb0 */
if(!s->budget--) { s->failed_pc=0x0c062fb0u; return 0; }
r[3]+=r[5];
goto P_0c062fb2;
P_0c062fb2: /* original 330c, guest PC 0x0c062fb2 */
if(!s->budget--) { s->failed_pc=0x0c062fb2u; return 0; }
r[3]+=r[0];
goto P_0c062fb4;
P_0c062fb4: /* original 1366, guest PC 0x0c062fb4 */
if(!s->budget--) { s->failed_pc=0x0c062fb4u; return 0; }
write(ram,r[3]+24,r[6],4);
goto P_0c062fb6;
P_0c062fb6: /* original 7701, guest PC 0x0c062fb6 */
if(!s->budget--) { s->failed_pc=0x0c062fb6u; return 0; }
r[7]+=0x00000001u;
goto P_0c062fb8;
P_0c062fb8: /* original 3762, guest PC 0x0c062fb8 */
if(!s->budget--) { s->failed_pc=0x0c062fb8u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[6])!=0);
goto P_0c062fba;
P_0c062fba: /* original 8ff5, guest PC 0x0c062fba */
if(!s->budget--) { s->failed_pc=0x0c062fbau; return 0; }
cond=r[17]&1u;
r[5]+=0x00000020u;
if(!cond) { goto P_0c062fa8; }
goto P_0c062fbe;
P_0c062fbc: /* original 7520, guest PC 0x0c062fbc */
if(!s->budget--) { s->failed_pc=0x0c062fbcu; return 0; }
r[5]+=0x00000020u;
goto P_0c062fbe;
P_0c062fbe: /* original 000b, guest PC 0x0c062fbe */
if(!s->budget--) { s->failed_pc=0x0c062fbeu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c062fc0: /* original e000, guest PC 0x0c062fc0 */
if(!s->budget--) { s->failed_pc=0x0c062fc0u; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c062fc2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062fc2u; return 0; } return 1;
P_0c0631d8: /* original 2fe6, guest PC 0x0c0631d8 */
if(!s->budget--) { s->failed_pc=0x0c0631d8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0631da;
P_0c0631da: /* original e600, guest PC 0x0c0631da */
if(!s->budget--) { s->failed_pc=0x0c0631dau; return 0; }
r[6]=0x00000000u;
goto P_0c0631dc;
P_0c0631dc: /* original d54d, guest PC 0x0c0631dc */
if(!s->budget--) { s->failed_pc=0x0c0631dcu; return 0; }
r[5]=read(ram,0x0c063314u,4);
goto P_0c0631de;
P_0c0631de: /* original ee02, guest PC 0x0c0631de */
if(!s->budget--) { s->failed_pc=0x0c0631deu; return 0; }
r[14]=0x00000002u;
goto P_0c0631e0;
P_0c0631e0: /* original 2fd6, guest PC 0x0c0631e0 */
if(!s->budget--) { s->failed_pc=0x0c0631e0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0631e2;
P_0c0631e2: /* original ed03, guest PC 0x0c0631e2 */
if(!s->budget--) { s->failed_pc=0x0c0631e2u; return 0; }
r[13]=0x00000003u;
goto P_0c0631e4;
P_0c0631e4: /* original 2fc6, guest PC 0x0c0631e4 */
if(!s->budget--) { s->failed_pc=0x0c0631e4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0631e6;
P_0c0631e6: /* original 2fb6, guest PC 0x0c0631e6 */
if(!s->budget--) { s->failed_pc=0x0c0631e6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0631e8;
P_0c0631e8: /* original 2fa6, guest PC 0x0c0631e8 */
if(!s->budget--) { s->failed_pc=0x0c0631e8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0631ea;
P_0c0631ea: /* original eafc, guest PC 0x0c0631ea */
if(!s->budget--) { s->failed_pc=0x0c0631eau; return 0; }
r[10]=0xfffffffcu;
goto P_0c0631ec;
P_0c0631ec: /* original d34a, guest PC 0x0c0631ec */
if(!s->budget--) { s->failed_pc=0x0c0631ecu; return 0; }
r[3]=read(ram,0x0c063318u,4);
goto P_0c0631ee;
P_0c0631ee: /* original 2f96, guest PC 0x0c0631ee */
if(!s->budget--) { s->failed_pc=0x0c0631eeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0631f0;
P_0c0631f0: /* original 2f86, guest PC 0x0c0631f0 */
if(!s->budget--) { s->failed_pc=0x0c0631f0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0631f2;
P_0c0631f2: /* original 6432, guest PC 0x0c0631f2 */
if(!s->budget--) { s->failed_pc=0x0c0631f2u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0631f4;
P_0c0631f4: /* original d149, guest PC 0x0c0631f4 */
if(!s->budget--) { s->failed_pc=0x0c0631f4u; return 0; }
r[1]=read(ram,0x0c06331cu,4);
goto P_0c0631f6;
P_0c0631f6: /* original 4418, guest PC 0x0c0631f6 */
if(!s->budget--) { s->failed_pc=0x0c0631f6u; return 0; }
r[4]<<=8;
goto P_0c0631f8;
P_0c0631f8: /* original 9887, guest PC 0x0c0631f8 */
if(!s->budget--) { s->failed_pc=0x0c0631f8u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06330au,2);
goto P_0c0631fa;
P_0c0631fa: /* original 345c, guest PC 0x0c0631fa */
if(!s->budget--) { s->failed_pc=0x0c0631fau; return 0; }
r[4]+=r[5];
goto P_0c0631fc;
P_0c0631fc: /* original 6212, guest PC 0x0c0631fc */
if(!s->budget--) { s->failed_pc=0x0c0631fcu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0631fe;
P_0c0631fe: /* original 4208, guest PC 0x0c0631fe */
if(!s->budget--) { s->failed_pc=0x0c0631feu; return 0; }
r[2]<<=2;
goto P_0c063200;
P_0c063200: /* original d947, guest PC 0x0c063200 */
if(!s->budget--) { s->failed_pc=0x0c063200u; return 0; }
r[9]=read(ram,0x0c063320u,4);
goto P_0c063202;
P_0c063202: /* original 4208, guest PC 0x0c063202 */
if(!s->budget--) { s->failed_pc=0x0c063202u; return 0; }
r[2]<<=2;
goto P_0c063204;
P_0c063204: /* original dc47, guest PC 0x0c063204 */
if(!s->budget--) { s->failed_pc=0x0c063204u; return 0; }
r[12]=read(ram,0x0c063324u,4);
goto P_0c063206;
P_0c063206: /* original 4200, guest PC 0x0c063206 */
if(!s->budget--) { s->failed_pc=0x0c063206u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c063208;
P_0c063208: /* original 342c, guest PC 0x0c063208 */
if(!s->budget--) { s->failed_pc=0x0c063208u; return 0; }
r[4]+=r[2];
goto P_0c06320a;
P_0c06320a: /* original 5246, guest PC 0x0c06320a */
if(!s->budget--) { s->failed_pc=0x0c06320au; return 0; }
r[2]=read(ram,r[4]+24,4);
goto P_0c06320c;
P_0c06320c: /* original 22a9, guest PC 0x0c06320c */
if(!s->budget--) { s->failed_pc=0x0c06320cu; return 0; }
r[2]&=r[10];
goto P_0c06320e;
P_0c06320e: /* original 1426, guest PC 0x0c06320e */
if(!s->budget--) { s->failed_pc=0x0c06320eu; return 0; }
write(ram,r[4]+24,r[2],4);
goto P_0c063210;
P_0c063210: /* original 6463, guest PC 0x0c063210 */
if(!s->budget--) { s->failed_pc=0x0c063210u; return 0; }
r[4]=r[6];
goto P_0c063212;
P_0c063212: /* original 6043, guest PC 0x0c063212 */
if(!s->budget--) { s->failed_pc=0x0c063212u; return 0; }
r[0]=r[4];
goto P_0c063214;
P_0c063214: /* original 0009, guest PC 0x0c063214 */
if(!s->budget--) { s->failed_pc=0x0c063214u; return 0; }
goto P_0c063216;
P_0c063216: /* original 4008, guest PC 0x0c063216 */
if(!s->budget--) { s->failed_pc=0x0c063216u; return 0; }
r[0]<<=2;
goto P_0c063218;
P_0c063218: /* original 07ce, guest PC 0x0c063218 */
if(!s->budget--) { s->failed_pc=0x0c063218u; return 0; }
r[7]=read(ram,r[12]+r[0],4);
goto P_0c06321a;
P_0c06321a: /* original 6043, guest PC 0x0c06321a */
if(!s->budget--) { s->failed_pc=0x0c06321au; return 0; }
r[0]=r[4];
goto P_0c06321c;
P_0c06321c: /* original 0009, guest PC 0x0c06321c */
if(!s->budget--) { s->failed_pc=0x0c06321cu; return 0; }
goto P_0c06321e;
P_0c06321e: /* original 4018, guest PC 0x0c06321e */
if(!s->budget--) { s->failed_pc=0x0c06321eu; return 0; }
r[0]<<=8;
goto P_0c063220;
P_0c063220: /* original 305c, guest PC 0x0c063220 */
if(!s->budget--) { s->failed_pc=0x0c063220u; return 0; }
r[0]+=r[5];
goto P_0c063222;
P_0c063222: /* original 6373, guest PC 0x0c063222 */
if(!s->budget--) { s->failed_pc=0x0c063222u; return 0; }
r[3]=r[7];
goto P_0c063224;
P_0c063224: /* original 4308, guest PC 0x0c063224 */
if(!s->budget--) { s->failed_pc=0x0c063224u; return 0; }
r[3]<<=2;
goto P_0c063226;
P_0c063226: /* original 4308, guest PC 0x0c063226 */
if(!s->budget--) { s->failed_pc=0x0c063226u; return 0; }
r[3]<<=2;
goto P_0c063228;
P_0c063228: /* original 4300, guest PC 0x0c063228 */
if(!s->budget--) { s->failed_pc=0x0c063228u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c06322a;
P_0c06322a: /* original 303c, guest PC 0x0c06322a */
if(!s->budget--) { s->failed_pc=0x0c06322au; return 0; }
r[0]+=r[3];
goto P_0c06322c;
P_0c06322c: /* original 5006, guest PC 0x0c06322c */
if(!s->budget--) { s->failed_pc=0x0c06322cu; return 0; }
r[0]=read(ram,r[0]+24,4);
goto P_0c06322e;
P_0c06322e: /* original 20d9, guest PC 0x0c06322e */
if(!s->budget--) { s->failed_pc=0x0c06322eu; return 0; }
r[0]&=r[13];
goto P_0c063230;
P_0c063230: /* original 8801, guest PC 0x0c063230 */
if(!s->budget--) { s->failed_pc=0x0c063230u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c063232;
P_0c063232: /* original 8b41, guest PC 0x0c063232 */
if(!s->budget--) { s->failed_pc=0x0c063232u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0632b8; }
goto P_0c063234;
P_0c063234: /* original d13c, guest PC 0x0c063234 */
if(!s->budget--) { s->failed_pc=0x0c063234u; return 0; }
r[1]=read(ram,0x0c063328u,4);
goto P_0c063236;
P_0c063236: /* original 6d43, guest PC 0x0c063236 */
if(!s->budget--) { s->failed_pc=0x0c063236u; return 0; }
r[13]=r[4];
goto P_0c063238;
P_0c063238: /* original 4d18, guest PC 0x0c063238 */
if(!s->budget--) { s->failed_pc=0x0c063238u; return 0; }
r[13]<<=8;
goto P_0c06323a;
P_0c06323a: /* original 66d3, guest PC 0x0c06323a */
if(!s->budget--) { s->failed_pc=0x0c06323au; return 0; }
r[6]=r[13];
goto P_0c06323c;
P_0c06323c: /* original 365c, guest PC 0x0c06323c */
if(!s->budget--) { s->failed_pc=0x0c06323cu; return 0; }
r[6]+=r[5];
goto P_0c06323e;
P_0c06323e: /* original 6b73, guest PC 0x0c06323e */
if(!s->budget--) { s->failed_pc=0x0c06323eu; return 0; }
r[11]=r[7];
goto P_0c063240;
P_0c063240: /* original 4b08, guest PC 0x0c063240 */
if(!s->budget--) { s->failed_pc=0x0c063240u; return 0; }
r[11]<<=2;
goto P_0c063242;
P_0c063242: /* original 4b08, guest PC 0x0c063242 */
if(!s->budget--) { s->failed_pc=0x0c063242u; return 0; }
r[11]<<=2;
goto P_0c063244;
P_0c063244: /* original 4b00, guest PC 0x0c063244 */
if(!s->budget--) { s->failed_pc=0x0c063244u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c063246;
P_0c063246: /* original 36bc, guest PC 0x0c063246 */
if(!s->budget--) { s->failed_pc=0x0c063246u; return 0; }
r[6]+=r[11];
goto P_0c063248;
P_0c063248: /* original 5366, guest PC 0x0c063248 */
if(!s->budget--) { s->failed_pc=0x0c063248u; return 0; }
r[3]=read(ram,r[6]+24,4);
goto P_0c06324a;
P_0c06324a: /* original 23a9, guest PC 0x0c06324a */
if(!s->budget--) { s->failed_pc=0x0c06324au; return 0; }
r[3]&=r[10];
goto P_0c06324c;
P_0c06324c: /* original 23eb, guest PC 0x0c06324c */
if(!s->budget--) { s->failed_pc=0x0c06324cu; return 0; }
r[3]|=r[14];
goto P_0c06324e;
P_0c06324e: /* original 1636, guest PC 0x0c06324e */
if(!s->budget--) { s->failed_pc=0x0c06324eu; return 0; }
write(ram,r[6]+24,r[3],4);
goto P_0c063250;
P_0c063250: /* original 5261, guest PC 0x0c063250 */
if(!s->budget--) { s->failed_pc=0x0c063250u; return 0; }
r[2]=read(ram,r[6]+4,4);
goto P_0c063252;
P_0c063252: /* original 2122, guest PC 0x0c063252 */
if(!s->budget--) { s->failed_pc=0x0c063252u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c063254;
P_0c063254: /* original 5363, guest PC 0x0c063254 */
if(!s->budget--) { s->failed_pc=0x0c063254u; return 0; }
r[3]=read(ram,r[6]+12,4);
goto P_0c063256;
P_0c063256: /* original 339c, guest PC 0x0c063256 */
if(!s->budget--) { s->failed_pc=0x0c063256u; return 0; }
r[3]+=r[9];
goto P_0c063258;
P_0c063258: /* original d234, guest PC 0x0c063258 */
if(!s->budget--) { s->failed_pc=0x0c063258u; return 0; }
r[2]=read(ram,0x0c06332cu,4);
goto P_0c06325a;
P_0c06325a: /* original 4300, guest PC 0x0c06325a */
if(!s->budget--) { s->failed_pc=0x0c06325au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c06325c;
P_0c06325c: /* original 2232, guest PC 0x0c06325c */
if(!s->budget--) { s->failed_pc=0x0c06325cu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c06325e;
P_0c06325e: /* original 5065, guest PC 0x0c06325e */
if(!s->budget--) { s->failed_pc=0x0c06325eu; return 0; }
r[0]=read(ram,r[6]+20,4);
goto P_0c063260;
P_0c063260: /* original d333, guest PC 0x0c063260 */
if(!s->budget--) { s->failed_pc=0x0c063260u; return 0; }
r[3]=read(ram,0x0c063330u,4);
goto P_0c063262;
P_0c063262: /* original 4009, guest PC 0x0c063262 */
if(!s->budget--) { s->failed_pc=0x0c063262u; return 0; }
r[0]>>=2;
goto P_0c063264;
P_0c063264: /* original 4009, guest PC 0x0c063264 */
if(!s->budget--) { s->failed_pc=0x0c063264u; return 0; }
r[0]>>=2;
goto P_0c063266;
P_0c063266: /* original 4001, guest PC 0x0c063266 */
if(!s->budget--) { s->failed_pc=0x0c063266u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c063268;
P_0c063268: /* original 2302, guest PC 0x0c063268 */
if(!s->budget--) { s->failed_pc=0x0c063268u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c06326a;
P_0c06326a: /* original 9e4f, guest PC 0x0c06326a */
if(!s->budget--) { s->failed_pc=0x0c06326au; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06330cu,2);
goto P_0c06326c;
P_0c06326c: /* original 5066, guest PC 0x0c06326c */
if(!s->budget--) { s->failed_pc=0x0c06326cu; return 0; }
r[0]=read(ram,r[6]+24,4);
goto P_0c06326e;
P_0c06326e: /* original c804, guest PC 0x0c06326e */
if(!s->budget--) { s->failed_pc=0x0c06326eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c063270;
P_0c063270: /* original 8f01, guest PC 0x0c063270 */
if(!s->budget--) { s->failed_pc=0x0c063270u; return 0; }
cond=r[17]&1u;
r[0]=r[13];
if(!cond) { goto P_0c063276; }
goto P_0c063274;
P_0c063272: /* original 60d3, guest PC 0x0c063272 */
if(!s->budget--) { s->failed_pc=0x0c063272u; return 0; }
r[0]=r[13];
goto P_0c063274;
P_0c063274: /* original 9e4b, guest PC 0x0c063274 */
if(!s->budget--) { s->failed_pc=0x0c063274u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06330eu,2);
goto P_0c063276;
P_0c063276: /* original 305c, guest PC 0x0c063276 */
if(!s->budget--) { s->failed_pc=0x0c063276u; return 0; }
r[0]+=r[5];
goto P_0c063278;
P_0c063278: /* original 30bc, guest PC 0x0c063278 */
if(!s->budget--) { s->failed_pc=0x0c063278u; return 0; }
r[0]+=r[11];
goto P_0c06327a;
P_0c06327a: /* original 5006, guest PC 0x0c06327a */
if(!s->budget--) { s->failed_pc=0x0c06327au; return 0; }
r[0]=read(ram,r[0]+24,4);
goto P_0c06327c;
P_0c06327c: /* original c810, guest PC 0x0c06327c */
if(!s->budget--) { s->failed_pc=0x0c06327cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c06327e;
P_0c06327e: /* original 8900, guest PC 0x0c06327e */
if(!s->budget--) { s->failed_pc=0x0c06327eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c063282; }
goto P_0c063280;
P_0c063280: /* original 2e8b, guest PC 0x0c063280 */
if(!s->budget--) { s->failed_pc=0x0c063280u; return 0; }
r[14]|=r[8];
goto P_0c063282;
P_0c063282: /* original d32c, guest PC 0x0c063282 */
if(!s->budget--) { s->failed_pc=0x0c063282u; return 0; }
r[3]=read(ram,0x0c063334u,4);
goto P_0c063284;
P_0c063284: /* original 23e2, guest PC 0x0c063284 */
if(!s->budget--) { s->failed_pc=0x0c063284u; return 0; }
write(ram,r[3],r[14],4);
goto P_0c063286;
P_0c063286: /* original 66d3, guest PC 0x0c063286 */
if(!s->budget--) { s->failed_pc=0x0c063286u; return 0; }
r[6]=r[13];
goto P_0c063288;
P_0c063288: /* original d12b, guest PC 0x0c063288 */
if(!s->budget--) { s->failed_pc=0x0c063288u; return 0; }
r[1]=read(ram,0x0c063338u,4);
goto P_0c06328a;
P_0c06328a: /* original 365c, guest PC 0x0c06328a */
if(!s->budget--) { s->failed_pc=0x0c06328au; return 0; }
r[6]+=r[5];
goto P_0c06328c;
P_0c06328c: /* original 36bc, guest PC 0x0c06328c */
if(!s->budget--) { s->failed_pc=0x0c06328cu; return 0; }
r[6]+=r[11];
goto P_0c06328e;
P_0c06328e: /* original 5263, guest PC 0x0c06328e */
if(!s->budget--) { s->failed_pc=0x0c06328eu; return 0; }
r[2]=read(ram,r[6]+12,4);
goto P_0c063290;
P_0c063290: /* original 2122, guest PC 0x0c063290 */
if(!s->budget--) { s->failed_pc=0x0c063290u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c063292;
P_0c063292: /* original 5065, guest PC 0x0c063292 */
if(!s->budget--) { s->failed_pc=0x0c063292u; return 0; }
r[0]=read(ram,r[6]+20,4);
goto P_0c063294;
P_0c063294: /* original d229, guest PC 0x0c063294 */
if(!s->budget--) { s->failed_pc=0x0c063294u; return 0; }
r[2]=read(ram,0x0c06333cu,4);
goto P_0c063296;
P_0c063296: /* original 2202, guest PC 0x0c063296 */
if(!s->budget--) { s->failed_pc=0x0c063296u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c063298;
P_0c063298: /* original d029, guest PC 0x0c063298 */
if(!s->budget--) { s->failed_pc=0x0c063298u; return 0; }
r[0]=read(ram,0x0c063340u,4);
goto P_0c06329a;
P_0c06329a: /* original e301, guest PC 0x0c06329a */
if(!s->budget--) { s->failed_pc=0x0c06329au; return 0; }
r[3]=0x00000001u;
goto P_0c06329c;
P_0c06329c: /* original 2032, guest PC 0x0c06329c */
if(!s->budget--) { s->failed_pc=0x0c06329cu; return 0; }
write(ram,r[0],r[3],4);
goto P_0c06329e;
P_0c06329e: /* original 6543, guest PC 0x0c06329e */
if(!s->budget--) { s->failed_pc=0x0c06329eu; return 0; }
r[5]=r[4];
goto P_0c0632a0;
P_0c0632a0: /* original d11e, guest PC 0x0c0632a0 */
if(!s->budget--) { s->failed_pc=0x0c0632a0u; return 0; }
r[1]=read(ram,0x0c06331cu,4);
goto P_0c0632a2;
P_0c0632a2: /* original 4508, guest PC 0x0c0632a2 */
if(!s->budget--) { s->failed_pc=0x0c0632a2u; return 0; }
r[5]<<=2;
goto P_0c0632a4;
P_0c0632a4: /* original d31c, guest PC 0x0c0632a4 */
if(!s->budget--) { s->failed_pc=0x0c0632a4u; return 0; }
r[3]=read(ram,0x0c063318u,4);
goto P_0c0632a6;
P_0c0632a6: /* original 35cc, guest PC 0x0c0632a6 */
if(!s->budget--) { s->failed_pc=0x0c0632a6u; return 0; }
r[5]+=r[12];
goto P_0c0632a8;
P_0c0632a8: /* original 2172, guest PC 0x0c0632a8 */
if(!s->budget--) { s->failed_pc=0x0c0632a8u; return 0; }
write(ram,r[1],r[7],4);
goto P_0c0632aa;
P_0c0632aa: /* original 2342, guest PC 0x0c0632aa */
if(!s->budget--) { s->failed_pc=0x0c0632aau; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0632ac;
P_0c0632ac: /* original 6052, guest PC 0x0c0632ac */
if(!s->budget--) { s->failed_pc=0x0c0632acu; return 0; }
tmp=read(ram,r[5],4);
r[0]=tmp;
goto P_0c0632ae;
P_0c0632ae: /* original 7001, guest PC 0x0c0632ae */
if(!s->budget--) { s->failed_pc=0x0c0632aeu; return 0; }
r[0]+=0x00000001u;
goto P_0c0632b0;
P_0c0632b0: /* original c907, guest PC 0x0c0632b0 */
if(!s->budget--) { s->failed_pc=0x0c0632b0u; return 0; }
r[0]&=7u;
goto P_0c0632b2;
P_0c0632b2: /* original 2502, guest PC 0x0c0632b2 */
if(!s->budget--) { s->failed_pc=0x0c0632b2u; return 0; }
write(ram,r[5],r[0],4);
goto P_0c0632b4;
P_0c0632b4: /* original a003, guest PC 0x0c0632b4 */
if(!s->budget--) { s->failed_pc=0x0c0632b4u; return 0; }
r[6]=0x00000001u;
goto P_0c0632be;
P_0c0632b6: /* original e601, guest PC 0x0c0632b6 */
if(!s->budget--) { s->failed_pc=0x0c0632b6u; return 0; }
r[6]=0x00000001u;
goto P_0c0632b8;
P_0c0632b8: /* original 7401, guest PC 0x0c0632b8 */
if(!s->budget--) { s->failed_pc=0x0c0632b8u; return 0; }
r[4]+=0x00000001u;
goto P_0c0632ba;
P_0c0632ba: /* original 34e2, guest PC 0x0c0632ba */
if(!s->budget--) { s->failed_pc=0x0c0632bau; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[14])!=0);
goto P_0c0632bc;
P_0c0632bc: /* original 8ba9, guest PC 0x0c0632bc */
if(!s->budget--) { s->failed_pc=0x0c0632bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063212; }
goto P_0c0632be;
P_0c0632be: /* original 6063, guest PC 0x0c0632be */
if(!s->budget--) { s->failed_pc=0x0c0632beu; return 0; }
r[0]=r[6];
goto P_0c0632c0;
P_0c0632c0: /* original 0009, guest PC 0x0c0632c0 */
if(!s->budget--) { s->failed_pc=0x0c0632c0u; return 0; }
goto P_0c0632c2;
P_0c0632c2: /* original 68f6, guest PC 0x0c0632c2 */
if(!s->budget--) { s->failed_pc=0x0c0632c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0632c4;
P_0c0632c4: /* original 69f6, guest PC 0x0c0632c4 */
if(!s->budget--) { s->failed_pc=0x0c0632c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0632c6;
P_0c0632c6: /* original 6af6, guest PC 0x0c0632c6 */
if(!s->budget--) { s->failed_pc=0x0c0632c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0632c8;
P_0c0632c8: /* original 6bf6, guest PC 0x0c0632c8 */
if(!s->budget--) { s->failed_pc=0x0c0632c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0632ca;
P_0c0632ca: /* original 6cf6, guest PC 0x0c0632ca */
if(!s->budget--) { s->failed_pc=0x0c0632cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0632cc;
P_0c0632cc: /* original 6df6, guest PC 0x0c0632cc */
if(!s->budget--) { s->failed_pc=0x0c0632ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0632ce;
P_0c0632ce: /* original 000b, guest PC 0x0c0632ce */
if(!s->budget--) { s->failed_pc=0x0c0632ceu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0632d0: /* original 6ef6, guest PC 0x0c0632d0 */
if(!s->budget--) { s->failed_pc=0x0c0632d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0632d2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0632d2u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
