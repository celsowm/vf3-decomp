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
int vf3_away_batch3_adapter_11(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042e30u: goto P_0c042e30;
case 0x0c042e32u: goto P_0c042e32;
case 0x0c042e34u: goto P_0c042e34;
case 0x0c042e36u: goto P_0c042e36;
case 0x0c042e38u: goto P_0c042e38;
case 0x0c042e3au: goto P_0c042e3a;
case 0x0c042efcu: goto P_0c042efc;
case 0x0c042efeu: goto P_0c042efe;
case 0x0c042f00u: goto P_0c042f00;
case 0x0c042f02u: goto P_0c042f02;
case 0x0c042f04u: goto P_0c042f04;
case 0x0c042f06u: goto P_0c042f06;
case 0x0c042f08u: goto P_0c042f08;
case 0x0c042f0au: goto P_0c042f0a;
case 0x0c042f0cu: goto P_0c042f0c;
case 0x0c042f0eu: goto P_0c042f0e;
case 0x0c042f10u: goto P_0c042f10;
case 0x0c042f12u: goto P_0c042f12;
case 0x0c042fa0u: goto P_0c042fa0;
case 0x0c042fa2u: goto P_0c042fa2;
case 0x0c042fa4u: goto P_0c042fa4;
case 0x0c042fa6u: goto P_0c042fa6;
case 0x0c042fa8u: goto P_0c042fa8;
case 0x0c042faau: goto P_0c042faa;
case 0x0c042facu: goto P_0c042fac;
case 0x0c042faeu: goto P_0c042fae;
case 0x0c042fb0u: goto P_0c042fb0;
case 0x0c042fb2u: goto P_0c042fb2;
case 0x0c042fb4u: goto P_0c042fb4;
case 0x0c042fb6u: goto P_0c042fb6;
case 0x0c042fb8u: goto P_0c042fb8;
case 0x0c042fbau: goto P_0c042fba;
case 0x0c042fbcu: goto P_0c042fbc;
case 0x0c042fbeu: goto P_0c042fbe;
case 0x0c042fc0u: goto P_0c042fc0;
case 0x0c042fc2u: goto P_0c042fc2;
case 0x0c042fc4u: goto P_0c042fc4;
case 0x0c042fc6u: goto P_0c042fc6;
case 0x0c042fc8u: goto P_0c042fc8;
case 0x0c042fcau: goto P_0c042fca;
case 0x0c042fccu: goto P_0c042fcc;
case 0x0c042fceu: goto P_0c042fce;
case 0x0c042fd0u: goto P_0c042fd0;
case 0x0c042fd2u: goto P_0c042fd2;
case 0x0c042fd4u: goto P_0c042fd4;
case 0x0c042fd6u: goto P_0c042fd6;
case 0x0c042fd8u: goto P_0c042fd8;
case 0x0c043104u: goto P_0c043104;
case 0x0c043106u: goto P_0c043106;
case 0x0c043108u: goto P_0c043108;
case 0x0c04310au: goto P_0c04310a;
case 0x0c04310cu: goto P_0c04310c;
case 0x0c04310eu: goto P_0c04310e;
case 0x0c0431dau: goto P_0c0431da;
case 0x0c0431dcu: goto P_0c0431dc;
case 0x0c0431deu: goto P_0c0431de;
case 0x0c0431e0u: goto P_0c0431e0;
case 0x0c0431e2u: goto P_0c0431e2;
case 0x0c0431e4u: goto P_0c0431e4;
case 0x0c0431e6u: goto P_0c0431e6;
case 0x0c0431e8u: goto P_0c0431e8;
case 0x0c0431eau: goto P_0c0431ea;
case 0x0c0431ecu: goto P_0c0431ec;
case 0x0c0431eeu: goto P_0c0431ee;
case 0x0c0431f0u: goto P_0c0431f0;
case 0x0c0431f2u: goto P_0c0431f2;
case 0x0c0431f4u: goto P_0c0431f4;
case 0x0c0431f6u: goto P_0c0431f6;
case 0x0c0431f8u: goto P_0c0431f8;
case 0x0c0431fau: goto P_0c0431fa;
case 0x0c0431fcu: goto P_0c0431fc;
case 0x0c0431feu: goto P_0c0431fe;
case 0x0c043200u: goto P_0c043200;
case 0x0c043202u: goto P_0c043202;
case 0x0c043204u: goto P_0c043204;
case 0x0c043206u: goto P_0c043206;
case 0x0c043208u: goto P_0c043208;
case 0x0c04320au: goto P_0c04320a;
case 0x0c04320cu: goto P_0c04320c;
case 0x0c04320eu: goto P_0c04320e;
case 0x0c043210u: goto P_0c043210;
case 0x0c043212u: goto P_0c043212;
case 0x0c043214u: goto P_0c043214;
case 0x0c043216u: goto P_0c043216;
case 0x0c043218u: goto P_0c043218;
case 0x0c04321au: goto P_0c04321a;
case 0x0c04321cu: goto P_0c04321c;
case 0x0c04321eu: goto P_0c04321e;
case 0x0c043220u: goto P_0c043220;
case 0x0c043222u: goto P_0c043222;
case 0x0c043224u: goto P_0c043224;
case 0x0c043226u: goto P_0c043226;
case 0x0c043228u: goto P_0c043228;
case 0x0c04322au: goto P_0c04322a;
case 0x0c04322cu: goto P_0c04322c;
case 0x0c04322eu: goto P_0c04322e;
case 0x0c043230u: goto P_0c043230;
case 0x0c043232u: goto P_0c043232;
case 0x0c043234u: goto P_0c043234;
case 0x0c043236u: goto P_0c043236;
case 0x0c043238u: goto P_0c043238;
case 0x0c04323au: goto P_0c04323a;
case 0x0c04323cu: goto P_0c04323c;
case 0x0c04323eu: goto P_0c04323e;
case 0x0c043240u: goto P_0c043240;
case 0x0c043242u: goto P_0c043242;
case 0x0c043244u: goto P_0c043244;
case 0x0c043246u: goto P_0c043246;
case 0x0c043248u: goto P_0c043248;
case 0x0c04324au: goto P_0c04324a;
case 0x0c04324cu: goto P_0c04324c;
case 0x0c04324eu: goto P_0c04324e;
case 0x0c043250u: goto P_0c043250;
case 0x0c043252u: goto P_0c043252;
case 0x0c043254u: goto P_0c043254;
case 0x0c043256u: goto P_0c043256;
case 0x0c043258u: goto P_0c043258;
case 0x0c04325au: goto P_0c04325a;
case 0x0c04325cu: goto P_0c04325c;
case 0x0c04325eu: goto P_0c04325e;
case 0x0c043260u: goto P_0c043260;
case 0x0c043262u: goto P_0c043262;
case 0x0c043264u: goto P_0c043264;
case 0x0c043266u: goto P_0c043266;
case 0x0c043268u: goto P_0c043268;
case 0x0c043286u: goto P_0c043286;
case 0x0c043288u: goto P_0c043288;
case 0x0c04328au: goto P_0c04328a;
case 0x0c04328cu: goto P_0c04328c;
case 0x0c04328eu: goto P_0c04328e;
case 0x0c043290u: goto P_0c043290;
case 0x0c043292u: goto P_0c043292;
case 0x0c043294u: goto P_0c043294;
case 0x0c043296u: goto P_0c043296;
case 0x0c043298u: goto P_0c043298;
case 0x0c04329au: goto P_0c04329a;
case 0x0c04329cu: goto P_0c04329c;
case 0x0c04329eu: goto P_0c04329e;
case 0x0c0432a0u: goto P_0c0432a0;
case 0x0c0432a2u: goto P_0c0432a2;
case 0x0c0432a4u: goto P_0c0432a4;
case 0x0c0432a6u: goto P_0c0432a6;
case 0x0c0432a8u: goto P_0c0432a8;
case 0x0c0432aau: goto P_0c0432aa;
case 0x0c0432acu: goto P_0c0432ac;
case 0x0c0432aeu: goto P_0c0432ae;
case 0x0c0432b0u: goto P_0c0432b0;
case 0x0c0432b2u: goto P_0c0432b2;
case 0x0c0432b4u: goto P_0c0432b4;
case 0x0c0432b6u: goto P_0c0432b6;
case 0x0c0432b8u: goto P_0c0432b8;
case 0x0c0432bau: goto P_0c0432ba;
case 0x0c0432bcu: goto P_0c0432bc;
case 0x0c0432beu: goto P_0c0432be;
case 0x0c0432c0u: goto P_0c0432c0;
case 0x0c0432c2u: goto P_0c0432c2;
case 0x0c0432c4u: goto P_0c0432c4;
case 0x0c0432c6u: goto P_0c0432c6;
case 0x0c0432c8u: goto P_0c0432c8;
case 0x0c0432cau: goto P_0c0432ca;
case 0x0c0432ccu: goto P_0c0432cc;
case 0x0c0432ceu: goto P_0c0432ce;
case 0x0c0432d0u: goto P_0c0432d0;
case 0x0c0432d2u: goto P_0c0432d2;
case 0x0c0432d4u: goto P_0c0432d4;
case 0x0c0432d6u: goto P_0c0432d6;
case 0x0c0432d8u: goto P_0c0432d8;
case 0x0c0432dau: goto P_0c0432da;
case 0x0c0432dcu: goto P_0c0432dc;
case 0x0c043500u: goto P_0c043500;
case 0x0c043502u: goto P_0c043502;
case 0x0c043504u: goto P_0c043504;
case 0x0c043506u: goto P_0c043506;
case 0x0c043508u: goto P_0c043508;
case 0x0c04350au: goto P_0c04350a;
case 0x0c04350cu: goto P_0c04350c;
case 0x0c04350eu: goto P_0c04350e;
case 0x0c043510u: goto P_0c043510;
case 0x0c043512u: goto P_0c043512;
case 0x0c043514u: goto P_0c043514;
case 0x0c043516u: goto P_0c043516;
case 0x0c043518u: goto P_0c043518;
case 0x0c04351au: goto P_0c04351a;
case 0x0c04351cu: goto P_0c04351c;
case 0x0c04351eu: goto P_0c04351e;
case 0x0c043520u: goto P_0c043520;
case 0x0c043522u: goto P_0c043522;
case 0x0c043524u: goto P_0c043524;
case 0x0c043526u: goto P_0c043526;
case 0x0c043528u: goto P_0c043528;
case 0x0c04352au: goto P_0c04352a;
case 0x0c04352cu: goto P_0c04352c;
case 0x0c04352eu: goto P_0c04352e;
case 0x0c043530u: goto P_0c043530;
case 0x0c043532u: goto P_0c043532;
case 0x0c043534u: goto P_0c043534;
case 0x0c043536u: goto P_0c043536;
case 0x0c043538u: goto P_0c043538;
case 0x0c04353au: goto P_0c04353a;
case 0x0c04353cu: goto P_0c04353c;
case 0x0c04353eu: goto P_0c04353e;
case 0x0c043540u: goto P_0c043540;
case 0x0c043542u: goto P_0c043542;
case 0x0c043544u: goto P_0c043544;
case 0x0c043546u: goto P_0c043546;
case 0x0c043548u: goto P_0c043548;
case 0x0c04354au: goto P_0c04354a;
case 0x0c04354cu: goto P_0c04354c;
case 0x0c04354eu: goto P_0c04354e;
case 0x0c043550u: goto P_0c043550;
case 0x0c043552u: goto P_0c043552;
case 0x0c043554u: goto P_0c043554;
case 0x0c043556u: goto P_0c043556;
case 0x0c043558u: goto P_0c043558;
case 0x0c04355au: goto P_0c04355a;
case 0x0c04355cu: goto P_0c04355c;
case 0x0c04355eu: goto P_0c04355e;
case 0x0c043560u: goto P_0c043560;
default: return vf3_matrix_family(target,s,ram);
}
P_0c042e30: /* original d102, guest PC 0x0c042e30 */
if(!s->budget--) { s->failed_pc=0x0c042e30u; return 0; }
r[1]=read(ram,0x0c042e3cu,4);
goto P_0c042e32;
P_0c042e32: /* original d203, guest PC 0x0c042e32 */
if(!s->budget--) { s->failed_pc=0x0c042e32u; return 0; }
r[2]=read(ram,0x0c042e40u,4);
goto P_0c042e34;
P_0c042e34: /* original e000, guest PC 0x0c042e34 */
if(!s->budget--) { s->failed_pc=0x0c042e34u; return 0; }
r[0]=0x00000000u;
goto P_0c042e36;
P_0c042e36: /* original 2122, guest PC 0x0c042e36 */
if(!s->budget--) { s->failed_pc=0x0c042e36u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c042e38;
P_0c042e38: /* original 000b, guest PC 0x0c042e38 */
if(!s->budget--) { s->failed_pc=0x0c042e38u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042e3a: /* original 62f6, guest PC 0x0c042e3a */
if(!s->budget--) { s->failed_pc=0x0c042e3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042e3cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042e3cu; return 0; } return 1;
P_0c042efc: /* original 2f36, guest PC 0x0c042efc */
if(!s->budget--) { s->failed_pc=0x0c042efcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042efe;
P_0c042efe: /* original d305, guest PC 0x0c042efe */
if(!s->budget--) { s->failed_pc=0x0c042efeu; return 0; }
r[3]=read(ram,0x0c042f14u,4);
goto P_0c042f00;
P_0c042f00: /* original 033e, guest PC 0x0c042f00 */
if(!s->budget--) { s->failed_pc=0x0c042f00u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c042f02;
P_0c042f02: /* original 70fc, guest PC 0x0c042f02 */
if(!s->budget--) { s->failed_pc=0x0c042f02u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c042f04;
P_0c042f04: /* original 432b, guest PC 0x0c042f04 */
if(!s->budget--) { s->failed_pc=0x0c042f04u; return 0; }
target=r[3];
r[0]=read(ram,r[2]+r[0],4);
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
P_0c042f06: /* original 002e, guest PC 0x0c042f06 */
if(!s->budget--) { s->failed_pc=0x0c042f06u; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c042f08;
P_0c042f08: /* original 2f36, guest PC 0x0c042f08 */
if(!s->budget--) { s->failed_pc=0x0c042f08u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042f0a;
P_0c042f0a: /* original d302, guest PC 0x0c042f0a */
if(!s->budget--) { s->failed_pc=0x0c042f0au; return 0; }
r[3]=read(ram,0x0c042f14u,4);
goto P_0c042f0c;
P_0c042f0c: /* original 033e, guest PC 0x0c042f0c */
if(!s->budget--) { s->failed_pc=0x0c042f0cu; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c042f0e;
P_0c042f0e: /* original 70fc, guest PC 0x0c042f0e */
if(!s->budget--) { s->failed_pc=0x0c042f0eu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c042f10;
P_0c042f10: /* original 432b, guest PC 0x0c042f10 */
if(!s->budget--) { s->failed_pc=0x0c042f10u; return 0; }
target=r[3];
r[3]=read(ram,r[2]+r[0],4);
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
P_0c042f12: /* original 032e, guest PC 0x0c042f12 */
if(!s->budget--) { s->failed_pc=0x0c042f12u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
if(!vf3_matrix_family(0x0c042f14u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042f14u; return 0; } return 1;
P_0c042fa0: /* original 2f26, guest PC 0x0c042fa0 */
if(!s->budget--) { s->failed_pc=0x0c042fa0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042fa2;
P_0c042fa2: /* original 2f36, guest PC 0x0c042fa2 */
if(!s->budget--) { s->failed_pc=0x0c042fa2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042fa4;
P_0c042fa4: /* original 2f46, guest PC 0x0c042fa4 */
if(!s->budget--) { s->failed_pc=0x0c042fa4u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042fa6;
P_0c042fa6: /* original 8800, guest PC 0x0c042fa6 */
if(!s->budget--) { s->failed_pc=0x0c042fa6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c042fa8;
P_0c042fa8: /* original 8d13, guest PC 0x0c042fa8 */
if(!s->budget--) { s->failed_pc=0x0c042fa8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042fd2; }
goto P_0c042fac;
P_0c042faa: /* original 0009, guest PC 0x0c042faa */
if(!s->budget--) { s->failed_pc=0x0c042faau; return 0; }
goto P_0c042fac;
P_0c042fac: /* original 6423, guest PC 0x0c042fac */
if(!s->budget--) { s->failed_pc=0x0c042facu; return 0; }
r[4]=r[2];
goto P_0c042fae;
P_0c042fae: /* original 340c, guest PC 0x0c042fae */
if(!s->budget--) { s->failed_pc=0x0c042faeu; return 0; }
r[4]+=r[0];
goto P_0c042fb0;
P_0c042fb0: /* original 6024, guest PC 0x0c042fb0 */
if(!s->budget--) { s->failed_pc=0x0c042fb0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[2]+=1;
r[0]=tmp;
goto P_0c042fb2;
P_0c042fb2: /* original 2100, guest PC 0x0c042fb2 */
if(!s->budget--) { s->failed_pc=0x0c042fb2u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c042fb4;
P_0c042fb4: /* original 3426, guest PC 0x0c042fb4 */
if(!s->budget--) { s->failed_pc=0x0c042fb4u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[2])!=0);
goto P_0c042fb6;
P_0c042fb6: /* original 8b0c, guest PC 0x0c042fb6 */
if(!s->budget--) { s->failed_pc=0x0c042fb6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042fd2; }
goto P_0c042fb8;
P_0c042fb8: /* original 6024, guest PC 0x0c042fb8 */
if(!s->budget--) { s->failed_pc=0x0c042fb8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[2]+=1;
r[0]=tmp;
goto P_0c042fba;
P_0c042fba: /* original 8011, guest PC 0x0c042fba */
if(!s->budget--) { s->failed_pc=0x0c042fbau; return 0; }
write(ram,r[1]+1,r[0],1);
goto P_0c042fbc;
P_0c042fbc: /* original 3426, guest PC 0x0c042fbc */
if(!s->budget--) { s->failed_pc=0x0c042fbcu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[2])!=0);
goto P_0c042fbe;
P_0c042fbe: /* original 8b08, guest PC 0x0c042fbe */
if(!s->budget--) { s->failed_pc=0x0c042fbeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042fd2; }
goto P_0c042fc0;
P_0c042fc0: /* original 6024, guest PC 0x0c042fc0 */
if(!s->budget--) { s->failed_pc=0x0c042fc0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[2]+=1;
r[0]=tmp;
goto P_0c042fc2;
P_0c042fc2: /* original 8012, guest PC 0x0c042fc2 */
if(!s->budget--) { s->failed_pc=0x0c042fc2u; return 0; }
write(ram,r[1]+2,r[0],1);
goto P_0c042fc4;
P_0c042fc4: /* original 3426, guest PC 0x0c042fc4 */
if(!s->budget--) { s->failed_pc=0x0c042fc4u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[2])!=0);
goto P_0c042fc6;
P_0c042fc6: /* original 8b04, guest PC 0x0c042fc6 */
if(!s->budget--) { s->failed_pc=0x0c042fc6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042fd2; }
goto P_0c042fc8;
P_0c042fc8: /* original 6024, guest PC 0x0c042fc8 */
if(!s->budget--) { s->failed_pc=0x0c042fc8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[2]+=1;
r[0]=tmp;
goto P_0c042fca;
P_0c042fca: /* original 8013, guest PC 0x0c042fca */
if(!s->budget--) { s->failed_pc=0x0c042fcau; return 0; }
write(ram,r[1]+3,r[0],1);
goto P_0c042fcc;
P_0c042fcc: /* original 3426, guest PC 0x0c042fcc */
if(!s->budget--) { s->failed_pc=0x0c042fccu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[2])!=0);
goto P_0c042fce;
P_0c042fce: /* original 7104, guest PC 0x0c042fce */
if(!s->budget--) { s->failed_pc=0x0c042fceu; return 0; }
r[1]+=0x00000004u;
goto P_0c042fd0;
P_0c042fd0: /* original 89ee, guest PC 0x0c042fd0 */
if(!s->budget--) { s->failed_pc=0x0c042fd0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042fb0; }
goto P_0c042fd2;
P_0c042fd2: /* original 64f6, guest PC 0x0c042fd2 */
if(!s->budget--) { s->failed_pc=0x0c042fd2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c042fd4;
P_0c042fd4: /* original 63f6, guest PC 0x0c042fd4 */
if(!s->budget--) { s->failed_pc=0x0c042fd4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042fd6;
P_0c042fd6: /* original 000b, guest PC 0x0c042fd6 */
if(!s->budget--) { s->failed_pc=0x0c042fd6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042fd8: /* original 62f6, guest PC 0x0c042fd8 */
if(!s->budget--) { s->failed_pc=0x0c042fd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042fdau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042fdau; return 0; } return 1;
P_0c043104: /* original e600, guest PC 0x0c043104 */
if(!s->budget--) { s->failed_pc=0x0c043104u; return 0; }
r[6]=0x00000000u;
goto P_0c043106;
P_0c043106: /* original d702, guest PC 0x0c043106 */
if(!s->budget--) { s->failed_pc=0x0c043106u; return 0; }
r[7]=read(ram,0x0c043110u,4);
goto P_0c043108;
P_0c043108: /* original d002, guest PC 0x0c043108 */
if(!s->budget--) { s->failed_pc=0x0c043108u; return 0; }
r[0]=read(ram,0x0c043114u,4);
goto P_0c04310a;
P_0c04310a: /* original 6002, guest PC 0x0c04310a */
if(!s->budget--) { s->failed_pc=0x0c04310au; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c04310c;
P_0c04310c: /* original 402b, guest PC 0x0c04310c */
if(!s->budget--) { s->failed_pc=0x0c04310cu; return 0; }
target=r[0];
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
P_0c04310e: /* original 0009, guest PC 0x0c04310e */
if(!s->budget--) { s->failed_pc=0x0c04310eu; return 0; }
if(!vf3_matrix_family(0x0c043110u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c043110u; return 0; } return 1;
P_0c0431da: /* original 2fe6, guest PC 0x0c0431da */
if(!s->budget--) { s->failed_pc=0x0c0431dau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0431dc;
P_0c0431dc: /* original e300, guest PC 0x0c0431dc */
if(!s->budget--) { s->failed_pc=0x0c0431dcu; return 0; }
r[3]=0x00000000u;
goto P_0c0431de;
P_0c0431de: /* original 2fd6, guest PC 0x0c0431de */
if(!s->budget--) { s->failed_pc=0x0c0431deu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0431e0;
P_0c0431e0: /* original 6073, guest PC 0x0c0431e0 */
if(!s->budget--) { s->failed_pc=0x0c0431e0u; return 0; }
r[0]=r[7];
goto P_0c0431e2;
P_0c0431e2: /* original 2fc6, guest PC 0x0c0431e2 */
if(!s->budget--) { s->failed_pc=0x0c0431e2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0431e4;
P_0c0431e4: /* original 6c53, guest PC 0x0c0431e4 */
if(!s->budget--) { s->failed_pc=0x0c0431e4u; return 0; }
r[12]=r[5];
goto P_0c0431e6;
P_0c0431e6: /* original 2fb6, guest PC 0x0c0431e6 */
if(!s->budget--) { s->failed_pc=0x0c0431e6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0431e8;
P_0c0431e8: /* original 4c18, guest PC 0x0c0431e8 */
if(!s->budget--) { s->failed_pc=0x0c0431e8u; return 0; }
r[12]<<=8;
goto P_0c0431ea;
P_0c0431ea: /* original 4f22, guest PC 0x0c0431ea */
if(!s->budget--) { s->failed_pc=0x0c0431eau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0431ec;
P_0c0431ec: /* original 4c08, guest PC 0x0c0431ec */
if(!s->budget--) { s->failed_pc=0x0c0431ecu; return 0; }
r[12]<<=2;
goto P_0c0431ee;
P_0c0431ee: /* original 6e63, guest PC 0x0c0431ee */
if(!s->budget--) { s->failed_pc=0x0c0431eeu; return 0; }
r[14]=r[6];
goto P_0c0431f0;
P_0c0431f0: /* original 4c00, guest PC 0x0c0431f0 */
if(!s->budget--) { s->failed_pc=0x0c0431f0u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c0431f2;
P_0c0431f2: /* original 8801, guest PC 0x0c0431f2 */
if(!s->budget--) { s->failed_pc=0x0c0431f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0431f4;
P_0c0431f4: /* original 7ff0, guest PC 0x0c0431f4 */
if(!s->budget--) { s->failed_pc=0x0c0431f4u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0431f6;
P_0c0431f6: /* original 6df3, guest PC 0x0c0431f6 */
if(!s->budget--) { s->failed_pc=0x0c0431f6u; return 0; }
r[13]=r[15];
goto P_0c0431f8;
P_0c0431f8: /* original 2d42, guest PC 0x0c0431f8 */
if(!s->budget--) { s->failed_pc=0x0c0431f8u; return 0; }
write(ram,r[13],r[4],4);
goto P_0c0431fa;
P_0c0431fa: /* original 1d51, guest PC 0x0c0431fa */
if(!s->budget--) { s->failed_pc=0x0c0431fau; return 0; }
write(ram,r[13]+4,r[5],4);
goto P_0c0431fc;
P_0c0431fc: /* original 64d3, guest PC 0x0c0431fc */
if(!s->budget--) { s->failed_pc=0x0c0431fcu; return 0; }
r[4]=r[13];
goto P_0c0431fe;
P_0c0431fe: /* original 1d33, guest PC 0x0c0431fe */
if(!s->budget--) { s->failed_pc=0x0c0431feu; return 0; }
write(ram,r[13]+12,r[3],4);
goto P_0c043200;
P_0c043200: /* original 8f08, guest PC 0x0c043200 */
if(!s->budget--) { s->failed_pc=0x0c043200u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000008u;
if(!cond) { goto P_0c043214; }
goto P_0c043204;
P_0c043202: /* original 7408, guest PC 0x0c043202 */
if(!s->budget--) { s->failed_pc=0x0c043202u; return 0; }
r[4]+=0x00000008u;
goto P_0c043204;
P_0c043204: /* original 65c3, guest PC 0x0c043204 */
if(!s->budget--) { s->failed_pc=0x0c043204u; return 0; }
r[5]=r[12];
goto P_0c043206;
P_0c043206: /* original eb11, guest PC 0x0c043206 */
if(!s->budget--) { s->failed_pc=0x0c043206u; return 0; }
r[11]=0x00000011u;
goto P_0c043208;
P_0c043208: /* original 24e2, guest PC 0x0c043208 */
if(!s->budget--) { s->failed_pc=0x0c043208u; return 0; }
write(ram,r[4],r[14],4);
goto P_0c04320a;
P_0c04320a: /* original d348, guest PC 0x0c04320a */
if(!s->budget--) { s->failed_pc=0x0c04320au; return 0; }
r[3]=read(ram,0x0c04332cu,4);
goto P_0c04320c;
P_0c04320c: /* original 430b, guest PC 0x0c04320c */
if(!s->budget--) { s->failed_pc=0x0c04320cu; return 0; }
target=r[3];
r[16]=code_base|0x0c043210u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043210u) { target=s->pc; goto dispatch; }
goto P_0c043210;
P_0c04320e: /* original 64e3, guest PC 0x0c04320e */
if(!s->budget--) { s->failed_pc=0x0c04320eu; return 0; }
r[4]=r[14];
goto P_0c043210;
P_0c043210: /* original a009, guest PC 0x0c043210 */
if(!s->budget--) { s->failed_pc=0x0c043210u; return 0; }
goto P_0c043226;
P_0c043212: /* original 0009, guest PC 0x0c043212 */
if(!s->budget--) { s->failed_pc=0x0c043212u; return 0; }
goto P_0c043214;
P_0c043214: /* original 2778, guest PC 0x0c043214 */
if(!s->budget--) { s->failed_pc=0x0c043214u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c043216;
P_0c043216: /* original 8b04, guest PC 0x0c043216 */
if(!s->budget--) { s->failed_pc=0x0c043216u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043222; }
goto P_0c043218;
P_0c043218: /* original d245, guest PC 0x0c043218 */
if(!s->budget--) { s->failed_pc=0x0c043218u; return 0; }
r[2]=read(ram,0x0c043330u,4);
goto P_0c04321a;
P_0c04321a: /* original eb10, guest PC 0x0c04321a */
if(!s->budget--) { s->failed_pc=0x0c04321au; return 0; }
r[11]=0x00000010u;
goto P_0c04321c;
P_0c04321c: /* original 22eb, guest PC 0x0c04321c */
if(!s->budget--) { s->failed_pc=0x0c04321cu; return 0; }
r[2]|=r[14];
goto P_0c04321e;
P_0c04321e: /* original a002, guest PC 0x0c04321e */
if(!s->budget--) { s->failed_pc=0x0c04321eu; return 0; }
write(ram,r[4],r[2],4);
goto P_0c043226;
P_0c043220: /* original 2422, guest PC 0x0c043220 */
if(!s->budget--) { s->failed_pc=0x0c043220u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c043222;
P_0c043222: /* original a01b, guest PC 0x0c043222 */
if(!s->budget--) { s->failed_pc=0x0c043222u; return 0; }
r[0]=0xffffffeeu;
goto P_0c04325c;
P_0c043224: /* original e0ee, guest PC 0x0c043224 */
if(!s->budget--) { s->failed_pc=0x0c043224u; return 0; }
r[0]=0xffffffeeu;
goto P_0c043226;
P_0c043226: /* original d243, guest PC 0x0c043226 */
if(!s->budget--) { s->failed_pc=0x0c043226u; return 0; }
r[2]=read(ram,0x0c043334u,4);
goto P_0c043228;
P_0c043228: /* original 65d3, guest PC 0x0c043228 */
if(!s->budget--) { s->failed_pc=0x0c043228u; return 0; }
r[5]=r[13];
goto P_0c04322a;
P_0c04322a: /* original 420b, guest PC 0x0c04322a */
if(!s->budget--) { s->failed_pc=0x0c04322au; return 0; }
target=r[2];
r[16]=code_base|0x0c04322eu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04322eu) { target=s->pc; goto dispatch; }
goto P_0c04322e;
P_0c04322c: /* original 64b3, guest PC 0x0c04322c */
if(!s->budget--) { s->failed_pc=0x0c04322cu; return 0; }
r[4]=r[11];
goto P_0c04322e;
P_0c04322e: /* original 6d03, guest PC 0x0c04322e */
if(!s->budget--) { s->failed_pc=0x0c04322eu; return 0; }
r[13]=r[0];
goto P_0c043230;
P_0c043230: /* original 2dd8, guest PC 0x0c043230 */
if(!s->budget--) { s->failed_pc=0x0c043230u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c043232;
P_0c043232: /* original 8912, guest PC 0x0c043232 */
if(!s->budget--) { s->failed_pc=0x0c043232u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04325a; }
goto P_0c043234;
P_0c043234: /* original e3e4, guest PC 0x0c043234 */
if(!s->budget--) { s->failed_pc=0x0c043234u; return 0; }
r[3]=0xffffffe4u;
goto P_0c043236;
P_0c043236: /* original 60e3, guest PC 0x0c043236 */
if(!s->budget--) { s->failed_pc=0x0c043236u; return 0; }
r[0]=r[14];
goto P_0c043238;
P_0c043238: /* original 403c, guest PC 0x0c043238 */
if(!s->budget--) { s->failed_pc=0x0c043238u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c04323a;
P_0c04323a: /* original c90f, guest PC 0x0c04323a */
if(!s->budget--) { s->failed_pc=0x0c04323au; return 0; }
r[0]&=15u;
goto P_0c04323c;
P_0c04323c: /* original 880a, guest PC 0x0c04323c */
if(!s->budget--) { s->failed_pc=0x0c04323cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c04323e;
P_0c04323e: /* original 890c, guest PC 0x0c04323e */
if(!s->budget--) { s->failed_pc=0x0c04323eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04325a; }
goto P_0c043240;
P_0c043240: /* original e31f, guest PC 0x0c043240 */
if(!s->budget--) { s->failed_pc=0x0c043240u; return 0; }
r[3]=0x0000001fu;
goto P_0c043242;
P_0c043242: /* original 23e8, guest PC 0x0c043242 */
if(!s->budget--) { s->failed_pc=0x0c043242u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c043244;
P_0c043244: /* original 8b05, guest PC 0x0c043244 */
if(!s->budget--) { s->failed_pc=0x0c043244u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043252; }
goto P_0c043246;
P_0c043246: /* original d33c, guest PC 0x0c043246 */
if(!s->budget--) { s->failed_pc=0x0c043246u; return 0; }
r[3]=read(ram,0x0c043338u,4);
goto P_0c043248;
P_0c043248: /* original 65c3, guest PC 0x0c043248 */
if(!s->budget--) { s->failed_pc=0x0c043248u; return 0; }
r[5]=r[12];
goto P_0c04324a;
P_0c04324a: /* original 430b, guest PC 0x0c04324a */
if(!s->budget--) { s->failed_pc=0x0c04324au; return 0; }
target=r[3];
r[16]=code_base|0x0c04324eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04324eu) { target=s->pc; goto dispatch; }
goto P_0c04324e;
P_0c04324c: /* original 64e3, guest PC 0x0c04324c */
if(!s->budget--) { s->failed_pc=0x0c04324cu; return 0; }
r[4]=r[14];
goto P_0c04324e;
P_0c04324e: /* original a004, guest PC 0x0c04324e */
if(!s->budget--) { s->failed_pc=0x0c04324eu; return 0; }
goto P_0c04325a;
P_0c043250: /* original 0009, guest PC 0x0c043250 */
if(!s->budget--) { s->failed_pc=0x0c043250u; return 0; }
goto P_0c043252;
P_0c043252: /* original d336, guest PC 0x0c043252 */
if(!s->budget--) { s->failed_pc=0x0c043252u; return 0; }
r[3]=read(ram,0x0c04332cu,4);
goto P_0c043254;
P_0c043254: /* original 65c3, guest PC 0x0c043254 */
if(!s->budget--) { s->failed_pc=0x0c043254u; return 0; }
r[5]=r[12];
goto P_0c043256;
P_0c043256: /* original 430b, guest PC 0x0c043256 */
if(!s->budget--) { s->failed_pc=0x0c043256u; return 0; }
target=r[3];
r[16]=code_base|0x0c04325au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04325au) { target=s->pc; goto dispatch; }
goto P_0c04325a;
P_0c043258: /* original 64e3, guest PC 0x0c043258 */
if(!s->budget--) { s->failed_pc=0x0c043258u; return 0; }
r[4]=r[14];
goto P_0c04325a;
P_0c04325a: /* original 60d3, guest PC 0x0c04325a */
if(!s->budget--) { s->failed_pc=0x0c04325au; return 0; }
r[0]=r[13];
goto P_0c04325c;
P_0c04325c: /* original 7f10, guest PC 0x0c04325c */
if(!s->budget--) { s->failed_pc=0x0c04325cu; return 0; }
r[15]+=0x00000010u;
goto P_0c04325e;
P_0c04325e: /* original 4f26, guest PC 0x0c04325e */
if(!s->budget--) { s->failed_pc=0x0c04325eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043260;
P_0c043260: /* original 6bf6, guest PC 0x0c043260 */
if(!s->budget--) { s->failed_pc=0x0c043260u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c043262;
P_0c043262: /* original 6cf6, guest PC 0x0c043262 */
if(!s->budget--) { s->failed_pc=0x0c043262u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c043264;
P_0c043264: /* original 6df6, guest PC 0x0c043264 */
if(!s->budget--) { s->failed_pc=0x0c043264u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c043266;
P_0c043266: /* original 000b, guest PC 0x0c043266 */
if(!s->budget--) { s->failed_pc=0x0c043266u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c043268: /* original 6ef6, guest PC 0x0c043268 */
if(!s->budget--) { s->failed_pc=0x0c043268u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04326au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04326au; return 0; } return 1;
P_0c043286: /* original 2fe6, guest PC 0x0c043286 */
if(!s->budget--) { s->failed_pc=0x0c043286u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043288;
P_0c043288: /* original 6e53, guest PC 0x0c043288 */
if(!s->budget--) { s->failed_pc=0x0c043288u; return 0; }
r[14]=r[5];
goto P_0c04328a;
P_0c04328a: /* original 2fd6, guest PC 0x0c04328a */
if(!s->budget--) { s->failed_pc=0x0c04328au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04328c;
P_0c04328c: /* original 6d63, guest PC 0x0c04328c */
if(!s->budget--) { s->failed_pc=0x0c04328cu; return 0; }
r[13]=r[6];
goto P_0c04328e;
P_0c04328e: /* original 2fc6, guest PC 0x0c04328e */
if(!s->budget--) { s->failed_pc=0x0c04328eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043290;
P_0c043290: /* original 4f22, guest PC 0x0c043290 */
if(!s->budget--) { s->failed_pc=0x0c043290u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043292;
P_0c043292: /* original 7ff8, guest PC 0x0c043292 */
if(!s->budget--) { s->failed_pc=0x0c043292u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c043294;
P_0c043294: /* original 6cf3, guest PC 0x0c043294 */
if(!s->budget--) { s->failed_pc=0x0c043294u; return 0; }
r[12]=r[15];
goto P_0c043296;
P_0c043296: /* original 2c52, guest PC 0x0c043296 */
if(!s->budget--) { s->failed_pc=0x0c043296u; return 0; }
write(ram,r[12],r[5],4);
goto P_0c043298;
P_0c043298: /* original 1cd1, guest PC 0x0c043298 */
if(!s->budget--) { s->failed_pc=0x0c043298u; return 0; }
write(ram,r[12]+4,r[13],4);
goto P_0c04329a;
P_0c04329a: /* original d328, guest PC 0x0c04329a */
if(!s->budget--) { s->failed_pc=0x0c04329au; return 0; }
r[3]=read(ram,0x0c04333cu,4);
goto P_0c04329c;
P_0c04329c: /* original 430b, guest PC 0x0c04329c */
if(!s->budget--) { s->failed_pc=0x0c04329cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0432a0u;
r[5]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0432a0u) { target=s->pc; goto dispatch; }
goto P_0c0432a0;
P_0c04329e: /* original 65c3, guest PC 0x0c04329e */
if(!s->budget--) { s->failed_pc=0x0c04329eu; return 0; }
r[5]=r[12];
goto P_0c0432a0;
P_0c0432a0: /* original 6c03, guest PC 0x0c0432a0 */
if(!s->budget--) { s->failed_pc=0x0c0432a0u; return 0; }
r[12]=r[0];
goto P_0c0432a2;
P_0c0432a2: /* original 2cc8, guest PC 0x0c0432a2 */
if(!s->budget--) { s->failed_pc=0x0c0432a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0432a4;
P_0c0432a4: /* original 8b14, guest PC 0x0c0432a4 */
if(!s->budget--) { s->failed_pc=0x0c0432a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0432d0; }
goto P_0c0432a6;
P_0c0432a6: /* original 2dd8, guest PC 0x0c0432a6 */
if(!s->budget--) { s->failed_pc=0x0c0432a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0432a8;
P_0c0432a8: /* original 8912, guest PC 0x0c0432a8 */
if(!s->budget--) { s->failed_pc=0x0c0432a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0432d0; }
goto P_0c0432aa;
P_0c0432aa: /* original e3e4, guest PC 0x0c0432aa */
if(!s->budget--) { s->failed_pc=0x0c0432aau; return 0; }
r[3]=0xffffffe4u;
goto P_0c0432ac;
P_0c0432ac: /* original 60e3, guest PC 0x0c0432ac */
if(!s->budget--) { s->failed_pc=0x0c0432acu; return 0; }
r[0]=r[14];
goto P_0c0432ae;
P_0c0432ae: /* original 403c, guest PC 0x0c0432ae */
if(!s->budget--) { s->failed_pc=0x0c0432aeu; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c0432b0;
P_0c0432b0: /* original c90f, guest PC 0x0c0432b0 */
if(!s->budget--) { s->failed_pc=0x0c0432b0u; return 0; }
r[0]&=15u;
goto P_0c0432b2;
P_0c0432b2: /* original 880a, guest PC 0x0c0432b2 */
if(!s->budget--) { s->failed_pc=0x0c0432b2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c0432b4;
P_0c0432b4: /* original 890c, guest PC 0x0c0432b4 */
if(!s->budget--) { s->failed_pc=0x0c0432b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0432d0; }
goto P_0c0432b6;
P_0c0432b6: /* original e31f, guest PC 0x0c0432b6 */
if(!s->budget--) { s->failed_pc=0x0c0432b6u; return 0; }
r[3]=0x0000001fu;
goto P_0c0432b8;
P_0c0432b8: /* original 23e8, guest PC 0x0c0432b8 */
if(!s->budget--) { s->failed_pc=0x0c0432b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c0432ba;
P_0c0432ba: /* original 8b05, guest PC 0x0c0432ba */
if(!s->budget--) { s->failed_pc=0x0c0432bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0432c8; }
goto P_0c0432bc;
P_0c0432bc: /* original d31e, guest PC 0x0c0432bc */
if(!s->budget--) { s->failed_pc=0x0c0432bcu; return 0; }
r[3]=read(ram,0x0c043338u,4);
goto P_0c0432be;
P_0c0432be: /* original 65d3, guest PC 0x0c0432be */
if(!s->budget--) { s->failed_pc=0x0c0432beu; return 0; }
r[5]=r[13];
goto P_0c0432c0;
P_0c0432c0: /* original 430b, guest PC 0x0c0432c0 */
if(!s->budget--) { s->failed_pc=0x0c0432c0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0432c4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0432c4u) { target=s->pc; goto dispatch; }
goto P_0c0432c4;
P_0c0432c2: /* original 64e3, guest PC 0x0c0432c2 */
if(!s->budget--) { s->failed_pc=0x0c0432c2u; return 0; }
r[4]=r[14];
goto P_0c0432c4;
P_0c0432c4: /* original a004, guest PC 0x0c0432c4 */
if(!s->budget--) { s->failed_pc=0x0c0432c4u; return 0; }
goto P_0c0432d0;
P_0c0432c6: /* original 0009, guest PC 0x0c0432c6 */
if(!s->budget--) { s->failed_pc=0x0c0432c6u; return 0; }
goto P_0c0432c8;
P_0c0432c8: /* original d318, guest PC 0x0c0432c8 */
if(!s->budget--) { s->failed_pc=0x0c0432c8u; return 0; }
r[3]=read(ram,0x0c04332cu,4);
goto P_0c0432ca;
P_0c0432ca: /* original 65d3, guest PC 0x0c0432ca */
if(!s->budget--) { s->failed_pc=0x0c0432cau; return 0; }
r[5]=r[13];
goto P_0c0432cc;
P_0c0432cc: /* original 430b, guest PC 0x0c0432cc */
if(!s->budget--) { s->failed_pc=0x0c0432ccu; return 0; }
target=r[3];
r[16]=code_base|0x0c0432d0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0432d0u) { target=s->pc; goto dispatch; }
goto P_0c0432d0;
P_0c0432ce: /* original 64e3, guest PC 0x0c0432ce */
if(!s->budget--) { s->failed_pc=0x0c0432ceu; return 0; }
r[4]=r[14];
goto P_0c0432d0;
P_0c0432d0: /* original 7f08, guest PC 0x0c0432d0 */
if(!s->budget--) { s->failed_pc=0x0c0432d0u; return 0; }
r[15]+=0x00000008u;
goto P_0c0432d2;
P_0c0432d2: /* original 60c3, guest PC 0x0c0432d2 */
if(!s->budget--) { s->failed_pc=0x0c0432d2u; return 0; }
r[0]=r[12];
goto P_0c0432d4;
P_0c0432d4: /* original 4f26, guest PC 0x0c0432d4 */
if(!s->budget--) { s->failed_pc=0x0c0432d4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0432d6;
P_0c0432d6: /* original 6cf6, guest PC 0x0c0432d6 */
if(!s->budget--) { s->failed_pc=0x0c0432d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0432d8;
P_0c0432d8: /* original 6df6, guest PC 0x0c0432d8 */
if(!s->budget--) { s->failed_pc=0x0c0432d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0432da;
P_0c0432da: /* original 000b, guest PC 0x0c0432da */
if(!s->budget--) { s->failed_pc=0x0c0432dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0432dc: /* original 6ef6, guest PC 0x0c0432dc */
if(!s->budget--) { s->failed_pc=0x0c0432dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0432deu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0432deu; return 0; } return 1;
P_0c043500: /* original 4615, guest PC 0x0c043500 */
if(!s->budget--) { s->failed_pc=0x0c043500u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c043502;
P_0c043502: /* original 6743, guest PC 0x0c043502 */
if(!s->budget--) { s->failed_pc=0x0c043502u; return 0; }
r[7]=r[4];
goto P_0c043504;
P_0c043504: /* original 8f06, guest PC 0x0c043504 */
if(!s->budget--) { s->failed_pc=0x0c043504u; return 0; }
cond=r[17]&1u;
r[4]=r[5];
if(!cond) { goto P_0c043514; }
goto P_0c043508;
P_0c043506: /* original 6453, guest PC 0x0c043506 */
if(!s->budget--) { s->failed_pc=0x0c043506u; return 0; }
r[4]=r[5];
goto P_0c043508;
P_0c043508: /* original 6374, guest PC 0x0c043508 */
if(!s->budget--) { s->failed_pc=0x0c043508u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]+=1;
r[3]=tmp;
goto P_0c04350a;
P_0c04350a: /* original 76ff, guest PC 0x0c04350a */
if(!s->budget--) { s->failed_pc=0x0c04350au; return 0; }
r[6]+=0xffffffffu;
goto P_0c04350c;
P_0c04350c: /* original 4615, guest PC 0x0c04350c */
if(!s->budget--) { s->failed_pc=0x0c04350cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c04350e;
P_0c04350e: /* original 2430, guest PC 0x0c04350e */
if(!s->budget--) { s->failed_pc=0x0c04350eu; return 0; }
write(ram,r[4],r[3],1);
goto P_0c043510;
P_0c043510: /* original 8dfa, guest PC 0x0c043510 */
if(!s->budget--) { s->failed_pc=0x0c043510u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(cond) { goto P_0c043508; }
goto P_0c043514;
P_0c043512: /* original 7401, guest PC 0x0c043512 */
if(!s->budget--) { s->failed_pc=0x0c043512u; return 0; }
r[4]+=0x00000001u;
goto P_0c043514;
P_0c043514: /* original 000b, guest PC 0x0c043514 */
if(!s->budget--) { s->failed_pc=0x0c043514u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c043516: /* original 0009, guest PC 0x0c043516 */
if(!s->budget--) { s->failed_pc=0x0c043516u; return 0; }
goto P_0c043518;
P_0c043518: /* original 2fe6, guest PC 0x0c043518 */
if(!s->budget--) { s->failed_pc=0x0c043518u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04351a;
P_0c04351a: /* original a023, guest PC 0x0c04351a */
if(!s->budget--) { s->failed_pc=0x0c04351au; return 0; }
return vf3_matrix_family(0x0c043564u,s,ram);
P_0c04351c: /* original 0009, guest PC 0x0c04351c */
if(!s->budget--) { s->failed_pc=0x0c04351cu; return 0; }
goto P_0c04351e;
P_0c04351e: /* original 6240, guest PC 0x0c04351e */
if(!s->budget--) { s->failed_pc=0x0c04351eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c043520;
P_0c043520: /* original 2228, guest PC 0x0c043520 */
if(!s->budget--) { s->failed_pc=0x0c043520u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c043522;
P_0c043522: /* original 8918, guest PC 0x0c043522 */
if(!s->budget--) { s->failed_pc=0x0c043522u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043556; }
goto P_0c043524;
P_0c043524: /* original 6744, guest PC 0x0c043524 */
if(!s->budget--) { s->failed_pc=0x0c043524u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[7]=tmp;
goto P_0c043526;
P_0c043526: /* original ee61, guest PC 0x0c043526 */
if(!s->budget--) { s->failed_pc=0x0c043526u; return 0; }
r[14]=0x00000061u;
goto P_0c043528;
P_0c043528: /* original 607e, guest PC 0x0c043528 */
if(!s->budget--) { s->failed_pc=0x0c043528u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[7];
goto P_0c04352a;
P_0c04352a: /* original 30e3, guest PC 0x0c04352a */
if(!s->budget--) { s->failed_pc=0x0c04352au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=(int32_t)r[14])!=0);
goto P_0c04352c;
P_0c04352c: /* original 8b03, guest PC 0x0c04352c */
if(!s->budget--) { s->failed_pc=0x0c04352cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043536; }
goto P_0c04352e;
P_0c04352e: /* original e27a, guest PC 0x0c04352e */
if(!s->budget--) { s->failed_pc=0x0c04352eu; return 0; }
r[2]=0x0000007au;
goto P_0c043530;
P_0c043530: /* original 3027, guest PC 0x0c043530 */
if(!s->budget--) { s->failed_pc=0x0c043530u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>(int32_t)r[2])!=0);
goto P_0c043532;
P_0c043532: /* original 8900, guest PC 0x0c043532 */
if(!s->budget--) { s->failed_pc=0x0c043532u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043536; }
goto P_0c043534;
P_0c043534: /* original 77e0, guest PC 0x0c043534 */
if(!s->budget--) { s->failed_pc=0x0c043534u; return 0; }
r[7]+=0xffffffe0u;
goto P_0c043536;
P_0c043536: /* original 6173, guest PC 0x0c043536 */
if(!s->budget--) { s->failed_pc=0x0c043536u; return 0; }
r[1]=r[7];
goto P_0c043538;
P_0c043538: /* original 6754, guest PC 0x0c043538 */
if(!s->budget--) { s->failed_pc=0x0c043538u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[7]=tmp;
goto P_0c04353a;
P_0c04353a: /* original 607e, guest PC 0x0c04353a */
if(!s->budget--) { s->failed_pc=0x0c04353au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[7];
goto P_0c04353c;
P_0c04353c: /* original 30e3, guest PC 0x0c04353c */
if(!s->budget--) { s->failed_pc=0x0c04353cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=(int32_t)r[14])!=0);
goto P_0c04353e;
P_0c04353e: /* original 8b03, guest PC 0x0c04353e */
if(!s->budget--) { s->failed_pc=0x0c04353eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043548; }
goto P_0c043540;
P_0c043540: /* original e27a, guest PC 0x0c043540 */
if(!s->budget--) { s->failed_pc=0x0c043540u; return 0; }
r[2]=0x0000007au;
goto P_0c043542;
P_0c043542: /* original 3027, guest PC 0x0c043542 */
if(!s->budget--) { s->failed_pc=0x0c043542u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>(int32_t)r[2])!=0);
goto P_0c043544;
P_0c043544: /* original 8900, guest PC 0x0c043544 */
if(!s->budget--) { s->failed_pc=0x0c043544u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043548; }
goto P_0c043546;
P_0c043546: /* original 77e0, guest PC 0x0c043546 */
if(!s->budget--) { s->failed_pc=0x0c043546u; return 0; }
r[7]+=0xffffffe0u;
goto P_0c043548;
P_0c043548: /* original 6e73, guest PC 0x0c043548 */
if(!s->budget--) { s->failed_pc=0x0c043548u; return 0; }
r[14]=r[7];
goto P_0c04354a;
P_0c04354a: /* original 6eee, guest PC 0x0c04354a */
if(!s->budget--) { s->failed_pc=0x0c04354au; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)r[14];
goto P_0c04354c;
P_0c04354c: /* original 611e, guest PC 0x0c04354c */
if(!s->budget--) { s->failed_pc=0x0c04354cu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)r[1];
goto P_0c04354e;
P_0c04354e: /* original 31e0, guest PC 0x0c04354e */
if(!s->budget--) { s->failed_pc=0x0c04354eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[14])!=0);
goto P_0c043550;
P_0c043550: /* original 8907, guest PC 0x0c043550 */
if(!s->budget--) { s->failed_pc=0x0c043550u; return 0; }
cond=r[17]&1u;
if(cond) { return vf3_matrix_family(0x0c043562u,s,ram); }
goto P_0c043552;
P_0c043552: /* original a003, guest PC 0x0c043552 */
if(!s->budget--) { s->failed_pc=0x0c043552u; return 0; }
goto P_0c04355c;
P_0c043554: /* original 0009, guest PC 0x0c043554 */
if(!s->budget--) { s->failed_pc=0x0c043554u; return 0; }
goto P_0c043556;
P_0c043556: /* original 6350, guest PC 0x0c043556 */
if(!s->budget--) { s->failed_pc=0x0c043556u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[3]=tmp;
goto P_0c043558;
P_0c043558: /* original 2338, guest PC 0x0c043558 */
if(!s->budget--) { s->failed_pc=0x0c043558u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04355a;
P_0c04355a: /* original 8905, guest PC 0x0c04355a */
if(!s->budget--) { s->failed_pc=0x0c04355au; return 0; }
cond=r[17]&1u;
if(cond) { return vf3_matrix_family(0x0c043568u,s,ram); }
goto P_0c04355c;
P_0c04355c: /* original e000, guest PC 0x0c04355c */
if(!s->budget--) { s->failed_pc=0x0c04355cu; return 0; }
r[0]=0x00000000u;
goto P_0c04355e;
P_0c04355e: /* original 000b, guest PC 0x0c04355e */
if(!s->budget--) { s->failed_pc=0x0c04355eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c043560: /* original 6ef6, guest PC 0x0c043560 */
if(!s->budget--) { s->failed_pc=0x0c043560u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c043562u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
