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
int vf3_away_batch4_adapter_10(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04a604u: goto P_0c04a604;
case 0x0c04a606u: goto P_0c04a606;
case 0x0c04a608u: goto P_0c04a608;
case 0x0c04a60au: goto P_0c04a60a;
case 0x0c04a60cu: goto P_0c04a60c;
case 0x0c04a60eu: goto P_0c04a60e;
case 0x0c04a610u: goto P_0c04a610;
case 0x0c04a612u: goto P_0c04a612;
case 0x0c04a614u: goto P_0c04a614;
case 0x0c04a6a8u: goto P_0c04a6a8;
case 0x0c04a6aau: goto P_0c04a6aa;
case 0x0c04a6acu: goto P_0c04a6ac;
case 0x0c04a6aeu: goto P_0c04a6ae;
case 0x0c04a6b0u: goto P_0c04a6b0;
case 0x0c04a6b2u: goto P_0c04a6b2;
case 0x0c04a6b4u: goto P_0c04a6b4;
case 0x0c04a6b6u: goto P_0c04a6b6;
case 0x0c04a6b8u: goto P_0c04a6b8;
case 0x0c04a6bau: goto P_0c04a6ba;
case 0x0c04a6bcu: goto P_0c04a6bc;
case 0x0c04a6beu: goto P_0c04a6be;
case 0x0c04a6c0u: goto P_0c04a6c0;
case 0x0c04a6c2u: goto P_0c04a6c2;
case 0x0c04a6c4u: goto P_0c04a6c4;
case 0x0c04a6c6u: goto P_0c04a6c6;
case 0x0c04b9e4u: goto P_0c04b9e4;
case 0x0c04b9e6u: goto P_0c04b9e6;
case 0x0c04b9e8u: goto P_0c04b9e8;
case 0x0c04b9eau: goto P_0c04b9ea;
case 0x0c04b9ecu: goto P_0c04b9ec;
case 0x0c04b9eeu: goto P_0c04b9ee;
case 0x0c04b9f0u: goto P_0c04b9f0;
case 0x0c04b9f2u: goto P_0c04b9f2;
case 0x0c04b9f4u: goto P_0c04b9f4;
case 0x0c04b9f6u: goto P_0c04b9f6;
case 0x0c04b9f8u: goto P_0c04b9f8;
case 0x0c04b9fau: goto P_0c04b9fa;
case 0x0c04bae6u: goto P_0c04bae6;
case 0x0c04bae8u: goto P_0c04bae8;
case 0x0c04baeau: goto P_0c04baea;
case 0x0c04baecu: goto P_0c04baec;
case 0x0c04baeeu: goto P_0c04baee;
case 0x0c04baf0u: goto P_0c04baf0;
case 0x0c04baf2u: goto P_0c04baf2;
case 0x0c04baf4u: goto P_0c04baf4;
case 0x0c04baf6u: goto P_0c04baf6;
case 0x0c04baf8u: goto P_0c04baf8;
case 0x0c04bafau: goto P_0c04bafa;
case 0x0c04bafcu: goto P_0c04bafc;
case 0x0c04bafeu: goto P_0c04bafe;
case 0x0c04bb00u: goto P_0c04bb00;
case 0x0c04bb02u: goto P_0c04bb02;
case 0x0c04bb04u: goto P_0c04bb04;
case 0x0c04bb06u: goto P_0c04bb06;
case 0x0c04bb08u: goto P_0c04bb08;
case 0x0c04bb0au: goto P_0c04bb0a;
case 0x0c04bb0cu: goto P_0c04bb0c;
case 0x0c04bb0eu: goto P_0c04bb0e;
case 0x0c04bb10u: goto P_0c04bb10;
case 0x0c04bb12u: goto P_0c04bb12;
case 0x0c04bb14u: goto P_0c04bb14;
case 0x0c04bb16u: goto P_0c04bb16;
case 0x0c04bb18u: goto P_0c04bb18;
case 0x0c04bb1au: goto P_0c04bb1a;
case 0x0c04bb1cu: goto P_0c04bb1c;
case 0x0c04bb1eu: goto P_0c04bb1e;
case 0x0c04bb20u: goto P_0c04bb20;
case 0x0c04bb22u: goto P_0c04bb22;
case 0x0c04bb24u: goto P_0c04bb24;
case 0x0c04bb26u: goto P_0c04bb26;
case 0x0c04bb28u: goto P_0c04bb28;
case 0x0c04bb58u: goto P_0c04bb58;
case 0x0c04bb5au: goto P_0c04bb5a;
case 0x0c04bb5cu: goto P_0c04bb5c;
case 0x0c04bb5eu: goto P_0c04bb5e;
case 0x0c04bb60u: goto P_0c04bb60;
case 0x0c04bb62u: goto P_0c04bb62;
case 0x0c04bb64u: goto P_0c04bb64;
case 0x0c04bb66u: goto P_0c04bb66;
case 0x0c04bb68u: goto P_0c04bb68;
case 0x0c04bb6au: goto P_0c04bb6a;
case 0x0c04bb6cu: goto P_0c04bb6c;
case 0x0c04bb6eu: goto P_0c04bb6e;
case 0x0c04bb70u: goto P_0c04bb70;
case 0x0c04bb72u: goto P_0c04bb72;
case 0x0c04bb74u: goto P_0c04bb74;
case 0x0c04bb76u: goto P_0c04bb76;
case 0x0c04bb78u: goto P_0c04bb78;
case 0x0c04bb7au: goto P_0c04bb7a;
case 0x0c04bb7cu: goto P_0c04bb7c;
case 0x0c04bb7eu: goto P_0c04bb7e;
case 0x0c04bb80u: goto P_0c04bb80;
case 0x0c04bb82u: goto P_0c04bb82;
case 0x0c04bb84u: goto P_0c04bb84;
case 0x0c04bb86u: goto P_0c04bb86;
case 0x0c04bb88u: goto P_0c04bb88;
case 0x0c04bb8au: goto P_0c04bb8a;
case 0x0c04bb8cu: goto P_0c04bb8c;
case 0x0c04bb8eu: goto P_0c04bb8e;
case 0x0c04bb90u: goto P_0c04bb90;
case 0x0c04bb92u: goto P_0c04bb92;
case 0x0c04bb94u: goto P_0c04bb94;
case 0x0c04bb96u: goto P_0c04bb96;
case 0x0c04bb98u: goto P_0c04bb98;
case 0x0c04bb9au: goto P_0c04bb9a;
case 0x0c04bb9cu: goto P_0c04bb9c;
case 0x0c04bb9eu: goto P_0c04bb9e;
case 0x0c04bba0u: goto P_0c04bba0;
case 0x0c04bba2u: goto P_0c04bba2;
case 0x0c04bba4u: goto P_0c04bba4;
case 0x0c04bba6u: goto P_0c04bba6;
case 0x0c04bba8u: goto P_0c04bba8;
case 0x0c04bbaau: goto P_0c04bbaa;
case 0x0c04bbacu: goto P_0c04bbac;
case 0x0c04bbaeu: goto P_0c04bbae;
case 0x0c04bbb0u: goto P_0c04bbb0;
case 0x0c04bbb2u: goto P_0c04bbb2;
case 0x0c04bbb4u: goto P_0c04bbb4;
case 0x0c04bbb6u: goto P_0c04bbb6;
case 0x0c04bbb8u: goto P_0c04bbb8;
case 0x0c04bbbau: goto P_0c04bbba;
case 0x0c04bbbcu: goto P_0c04bbbc;
case 0x0c04bbbeu: goto P_0c04bbbe;
case 0x0c04bbc0u: goto P_0c04bbc0;
case 0x0c04bbc2u: goto P_0c04bbc2;
case 0x0c04bbc4u: goto P_0c04bbc4;
case 0x0c04bbc6u: goto P_0c04bbc6;
case 0x0c04bbc8u: goto P_0c04bbc8;
case 0x0c04bbcau: goto P_0c04bbca;
case 0x0c04bbccu: goto P_0c04bbcc;
case 0x0c04bbceu: goto P_0c04bbce;
case 0x0c04bbd0u: goto P_0c04bbd0;
case 0x0c04bbd2u: goto P_0c04bbd2;
case 0x0c04bbd4u: goto P_0c04bbd4;
case 0x0c04bbd6u: goto P_0c04bbd6;
case 0x0c04bbd8u: goto P_0c04bbd8;
case 0x0c04bbdau: goto P_0c04bbda;
case 0x0c04bbdcu: goto P_0c04bbdc;
case 0x0c04bbdeu: goto P_0c04bbde;
case 0x0c04bbe0u: goto P_0c04bbe0;
case 0x0c04bbe2u: goto P_0c04bbe2;
case 0x0c04bbe4u: goto P_0c04bbe4;
case 0x0c04bbe6u: goto P_0c04bbe6;
case 0x0c04bc14u: goto P_0c04bc14;
case 0x0c04bc16u: goto P_0c04bc16;
case 0x0c04bc18u: goto P_0c04bc18;
case 0x0c04bc1au: goto P_0c04bc1a;
case 0x0c04bc1cu: goto P_0c04bc1c;
case 0x0c04bc1eu: goto P_0c04bc1e;
case 0x0c04bc20u: goto P_0c04bc20;
case 0x0c04bc22u: goto P_0c04bc22;
case 0x0c04bc24u: goto P_0c04bc24;
case 0x0c04bc26u: goto P_0c04bc26;
case 0x0c04bc28u: goto P_0c04bc28;
case 0x0c04bc2au: goto P_0c04bc2a;
case 0x0c04bc2cu: goto P_0c04bc2c;
case 0x0c04bc2eu: goto P_0c04bc2e;
case 0x0c04bc30u: goto P_0c04bc30;
case 0x0c04bc32u: goto P_0c04bc32;
case 0x0c04bc34u: goto P_0c04bc34;
case 0x0c04bc36u: goto P_0c04bc36;
case 0x0c04bc38u: goto P_0c04bc38;
case 0x0c04bc3au: goto P_0c04bc3a;
case 0x0c04bc3cu: goto P_0c04bc3c;
case 0x0c04bc3eu: goto P_0c04bc3e;
case 0x0c04bc40u: goto P_0c04bc40;
case 0x0c04bc42u: goto P_0c04bc42;
case 0x0c04bc44u: goto P_0c04bc44;
case 0x0c04bc46u: goto P_0c04bc46;
case 0x0c04bc48u: goto P_0c04bc48;
case 0x0c04bc4au: goto P_0c04bc4a;
case 0x0c04bc4cu: goto P_0c04bc4c;
case 0x0c04bc4eu: goto P_0c04bc4e;
case 0x0c04bc50u: goto P_0c04bc50;
case 0x0c04bd62u: goto P_0c04bd62;
case 0x0c04bd64u: goto P_0c04bd64;
case 0x0c04bd66u: goto P_0c04bd66;
case 0x0c04bd68u: goto P_0c04bd68;
case 0x0c04bd6au: goto P_0c04bd6a;
case 0x0c04bd6cu: goto P_0c04bd6c;
case 0x0c04bd6eu: goto P_0c04bd6e;
case 0x0c04bd70u: goto P_0c04bd70;
case 0x0c04bd72u: goto P_0c04bd72;
case 0x0c04bd74u: goto P_0c04bd74;
case 0x0c04bd76u: goto P_0c04bd76;
case 0x0c04bd78u: goto P_0c04bd78;
case 0x0c04bd7au: goto P_0c04bd7a;
case 0x0c04bd7cu: goto P_0c04bd7c;
case 0x0c04bd7eu: goto P_0c04bd7e;
case 0x0c04bd80u: goto P_0c04bd80;
case 0x0c04bd82u: goto P_0c04bd82;
case 0x0c04bd84u: goto P_0c04bd84;
case 0x0c04bd86u: goto P_0c04bd86;
case 0x0c04bd88u: goto P_0c04bd88;
case 0x0c04bd8au: goto P_0c04bd8a;
case 0x0c04bd8cu: goto P_0c04bd8c;
case 0x0c04bd8eu: goto P_0c04bd8e;
case 0x0c04bd90u: goto P_0c04bd90;
case 0x0c04bd92u: goto P_0c04bd92;
case 0x0c04bd94u: goto P_0c04bd94;
case 0x0c04bd96u: goto P_0c04bd96;
case 0x0c04bd98u: goto P_0c04bd98;
case 0x0c04bdbcu: goto P_0c04bdbc;
case 0x0c04bdbeu: goto P_0c04bdbe;
case 0x0c04bdc0u: goto P_0c04bdc0;
case 0x0c04bdc2u: goto P_0c04bdc2;
case 0x0c04bdc4u: goto P_0c04bdc4;
case 0x0c04bdc6u: goto P_0c04bdc6;
case 0x0c04bdc8u: goto P_0c04bdc8;
case 0x0c04bdcau: goto P_0c04bdca;
case 0x0c04bdccu: goto P_0c04bdcc;
case 0x0c04bdceu: goto P_0c04bdce;
case 0x0c04bdd0u: goto P_0c04bdd0;
case 0x0c04bdd2u: goto P_0c04bdd2;
case 0x0c04bdd4u: goto P_0c04bdd4;
case 0x0c04bdd6u: goto P_0c04bdd6;
case 0x0c04bdd8u: goto P_0c04bdd8;
case 0x0c04bddau: goto P_0c04bdda;
case 0x0c04bddcu: goto P_0c04bddc;
case 0x0c04bddeu: goto P_0c04bdde;
case 0x0c04bde0u: goto P_0c04bde0;
case 0x0c04bde2u: goto P_0c04bde2;
case 0x0c04bde4u: goto P_0c04bde4;
case 0x0c04bde6u: goto P_0c04bde6;
case 0x0c04bde8u: goto P_0c04bde8;
case 0x0c04bdeau: goto P_0c04bdea;
case 0x0c04bdecu: goto P_0c04bdec;
case 0x0c04bdeeu: goto P_0c04bdee;
case 0x0c04bdf0u: goto P_0c04bdf0;
case 0x0c04bdf2u: goto P_0c04bdf2;
case 0x0c04bdf4u: goto P_0c04bdf4;
case 0x0c04bdf6u: goto P_0c04bdf6;
case 0x0c04bdf8u: goto P_0c04bdf8;
case 0x0c04bdfau: goto P_0c04bdfa;
case 0x0c04bdfcu: goto P_0c04bdfc;
case 0x0c04bdfeu: goto P_0c04bdfe;
case 0x0c04be00u: goto P_0c04be00;
case 0x0c04be02u: goto P_0c04be02;
case 0x0c04be04u: goto P_0c04be04;
case 0x0c04be06u: goto P_0c04be06;
case 0x0c04be08u: goto P_0c04be08;
case 0x0c04be0au: goto P_0c04be0a;
case 0x0c04be0cu: goto P_0c04be0c;
case 0x0c04be0eu: goto P_0c04be0e;
case 0x0c04be10u: goto P_0c04be10;
case 0x0c04be12u: goto P_0c04be12;
case 0x0c04be14u: goto P_0c04be14;
case 0x0c04be16u: goto P_0c04be16;
case 0x0c04be18u: goto P_0c04be18;
case 0x0c04be1au: goto P_0c04be1a;
case 0x0c04be1cu: goto P_0c04be1c;
case 0x0c04be1eu: goto P_0c04be1e;
case 0x0c04be20u: goto P_0c04be20;
case 0x0c04be22u: goto P_0c04be22;
case 0x0c04be24u: goto P_0c04be24;
case 0x0c04be26u: goto P_0c04be26;
case 0x0c04be28u: goto P_0c04be28;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04a604: /* original 2f36, guest PC 0x0c04a604 */
if(!s->budget--) { s->failed_pc=0x0c04a604u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04a606;
P_0c04a606: /* original e340, guest PC 0x0c04a606 */
if(!s->budget--) { s->failed_pc=0x0c04a606u; return 0; }
r[3]=0x00000040u;
goto P_0c04a608;
P_0c04a608: /* original 3302, guest PC 0x0c04a608 */
if(!s->budget--) { s->failed_pc=0x0c04a608u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[0])!=0);
goto P_0c04a60a;
P_0c04a60a: /* original 8f4d, guest PC 0x0c04a60a */
if(!s->budget--) { s->failed_pc=0x0c04a60au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04a6a8; }
goto P_0c04a60e;
P_0c04a60c: /* original 0009, guest PC 0x0c04a60c */
if(!s->budget--) { s->failed_pc=0x0c04a60cu; return 0; }
goto P_0c04a60e;
P_0c04a60e: /* original d302, guest PC 0x0c04a60e */
if(!s->budget--) { s->failed_pc=0x0c04a60eu; return 0; }
r[3]=read(ram,0x0c04a618u,4);
goto P_0c04a610;
P_0c04a610: /* original 033e, guest PC 0x0c04a610 */
if(!s->budget--) { s->failed_pc=0x0c04a610u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c04a612;
P_0c04a612: /* original 432b, guest PC 0x0c04a612 */
if(!s->budget--) { s->failed_pc=0x0c04a612u; return 0; }
target=r[3];
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
P_0c04a614: /* original 0009, guest PC 0x0c04a614 */
if(!s->budget--) { s->failed_pc=0x0c04a614u; return 0; }
if(!vf3_matrix_family(0x0c04a616u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04a616u; return 0; } return 1;
P_0c04a6a8: /* original 2f26, guest PC 0x0c04a6a8 */
if(!s->budget--) { s->failed_pc=0x0c04a6a8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04a6aa;
P_0c04a6aa: /* original 6323, guest PC 0x0c04a6aa */
if(!s->budget--) { s->failed_pc=0x0c04a6aau; return 0; }
r[3]=r[2];
goto P_0c04a6ac;
P_0c04a6ac: /* original 330c, guest PC 0x0c04a6ac */
if(!s->budget--) { s->failed_pc=0x0c04a6acu; return 0; }
r[3]+=r[0];
goto P_0c04a6ae;
P_0c04a6ae: /* original 6026, guest PC 0x0c04a6ae */
if(!s->budget--) { s->failed_pc=0x0c04a6aeu; return 0; }
tmp=read(ram,r[2],4);
r[2]+=4;
r[0]=tmp;
goto P_0c04a6b0;
P_0c04a6b0: /* original 3322, guest PC 0x0c04a6b0 */
if(!s->budget--) { s->failed_pc=0x0c04a6b0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c04a6b2;
P_0c04a6b2: /* original 8b06, guest PC 0x0c04a6b2 */
if(!s->budget--) { s->failed_pc=0x0c04a6b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04a6c2; }
goto P_0c04a6b4;
P_0c04a6b4: /* original 2102, guest PC 0x0c04a6b4 */
if(!s->budget--) { s->failed_pc=0x0c04a6b4u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c04a6b6;
P_0c04a6b6: /* original 6026, guest PC 0x0c04a6b6 */
if(!s->budget--) { s->failed_pc=0x0c04a6b6u; return 0; }
tmp=read(ram,r[2],4);
r[2]+=4;
r[0]=tmp;
goto P_0c04a6b8;
P_0c04a6b8: /* original 3322, guest PC 0x0c04a6b8 */
if(!s->budget--) { s->failed_pc=0x0c04a6b8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c04a6ba;
P_0c04a6ba: /* original 8b02, guest PC 0x0c04a6ba */
if(!s->budget--) { s->failed_pc=0x0c04a6bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04a6c2; }
goto P_0c04a6bc;
P_0c04a6bc: /* original 1101, guest PC 0x0c04a6bc */
if(!s->budget--) { s->failed_pc=0x0c04a6bcu; return 0; }
write(ram,r[1]+4,r[0],4);
goto P_0c04a6be;
P_0c04a6be: /* original aff6, guest PC 0x0c04a6be */
if(!s->budget--) { s->failed_pc=0x0c04a6beu; return 0; }
r[1]+=0x00000008u;
goto P_0c04a6ae;
P_0c04a6c0: /* original 7108, guest PC 0x0c04a6c0 */
if(!s->budget--) { s->failed_pc=0x0c04a6c0u; return 0; }
r[1]+=0x00000008u;
goto P_0c04a6c2;
P_0c04a6c2: /* original 62f6, guest PC 0x0c04a6c2 */
if(!s->budget--) { s->failed_pc=0x0c04a6c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c04a6c4;
P_0c04a6c4: /* original 000b, guest PC 0x0c04a6c4 */
if(!s->budget--) { s->failed_pc=0x0c04a6c4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
s->pc=target; return ram->oob==0;
P_0c04a6c6: /* original 63f6, guest PC 0x0c04a6c6 */
if(!s->budget--) { s->failed_pc=0x0c04a6c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
if(!vf3_matrix_family(0x0c04a6c8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04a6c8u; return 0; } return 1;
P_0c04b9e4: /* original e700, guest PC 0x0c04b9e4 */
if(!s->budget--) { s->failed_pc=0x0c04b9e4u; return 0; }
r[7]=0x00000000u;
goto P_0c04b9e6;
P_0c04b9e6: /* original 6373, guest PC 0x0c04b9e6 */
if(!s->budget--) { s->failed_pc=0x0c04b9e6u; return 0; }
r[3]=r[7];
goto P_0c04b9e8;
P_0c04b9e8: /* original 3362, guest PC 0x0c04b9e8 */
if(!s->budget--) { s->failed_pc=0x0c04b9e8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[6])!=0);
goto P_0c04b9ea;
P_0c04b9ea: /* original 8d05, guest PC 0x0c04b9ea */
if(!s->budget--) { s->failed_pc=0x0c04b9eau; return 0; }
cond=r[17]&1u;
r[0]=r[4];
if(cond) { goto P_0c04b9f8; }
goto P_0c04b9ee;
P_0c04b9ec: /* original 6043, guest PC 0x0c04b9ec */
if(!s->budget--) { s->failed_pc=0x0c04b9ecu; return 0; }
r[0]=r[4];
goto P_0c04b9ee;
P_0c04b9ee: /* original 7701, guest PC 0x0c04b9ee */
if(!s->budget--) { s->failed_pc=0x0c04b9eeu; return 0; }
r[7]+=0x00000001u;
goto P_0c04b9f0;
P_0c04b9f0: /* original 2050, guest PC 0x0c04b9f0 */
if(!s->budget--) { s->failed_pc=0x0c04b9f0u; return 0; }
write(ram,r[0],r[5],1);
goto P_0c04b9f2;
P_0c04b9f2: /* original 3762, guest PC 0x0c04b9f2 */
if(!s->budget--) { s->failed_pc=0x0c04b9f2u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[6])!=0);
goto P_0c04b9f4;
P_0c04b9f4: /* original 8ffb, guest PC 0x0c04b9f4 */
if(!s->budget--) { s->failed_pc=0x0c04b9f4u; return 0; }
cond=r[17]&1u;
r[0]+=0x00000001u;
if(!cond) { goto P_0c04b9ee; }
goto P_0c04b9f8;
P_0c04b9f6: /* original 7001, guest PC 0x0c04b9f6 */
if(!s->budget--) { s->failed_pc=0x0c04b9f6u; return 0; }
r[0]+=0x00000001u;
goto P_0c04b9f8;
P_0c04b9f8: /* original 000b, guest PC 0x0c04b9f8 */
if(!s->budget--) { s->failed_pc=0x0c04b9f8u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c04b9fa: /* original 6043, guest PC 0x0c04b9fa */
if(!s->budget--) { s->failed_pc=0x0c04b9fau; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c04b9fcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04b9fcu; return 0; } return 1;
P_0c04bae6: /* original 2fe6, guest PC 0x0c04bae6 */
if(!s->budget--) { s->failed_pc=0x0c04bae6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bae8;
P_0c04bae8: /* original 2fd6, guest PC 0x0c04bae8 */
if(!s->budget--) { s->failed_pc=0x0c04bae8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04baea;
P_0c04baea: /* original 6d43, guest PC 0x0c04baea */
if(!s->budget--) { s->failed_pc=0x0c04baeau; return 0; }
r[13]=r[4];
goto P_0c04baec;
P_0c04baec: /* original 2fc6, guest PC 0x0c04baec */
if(!s->budget--) { s->failed_pc=0x0c04baecu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04baee;
P_0c04baee: /* original 2fb6, guest PC 0x0c04baee */
if(!s->budget--) { s->failed_pc=0x0c04baeeu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04baf0;
P_0c04baf0: /* original 2fa6, guest PC 0x0c04baf0 */
if(!s->budget--) { s->failed_pc=0x0c04baf0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04baf2;
P_0c04baf2: /* original 2f96, guest PC 0x0c04baf2 */
if(!s->budget--) { s->failed_pc=0x0c04baf2u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04baf4;
P_0c04baf4: /* original 6973, guest PC 0x0c04baf4 */
if(!s->budget--) { s->failed_pc=0x0c04baf4u; return 0; }
r[9]=r[7];
goto P_0c04baf6;
P_0c04baf6: /* original 4f22, guest PC 0x0c04baf6 */
if(!s->budget--) { s->failed_pc=0x0c04baf6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04baf8;
P_0c04baf8: /* original 901e, guest PC 0x0c04baf8 */
if(!s->budget--) { s->failed_pc=0x0c04baf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bb38u,2);
goto P_0c04bafa;
P_0c04bafa: /* original 3f0c, guest PC 0x0c04bafa */
if(!s->budget--) { s->failed_pc=0x0c04bafau; return 0; }
r[15]+=r[0];
goto P_0c04bafc;
P_0c04bafc: /* original 6bf3, guest PC 0x0c04bafc */
if(!s->budget--) { s->failed_pc=0x0c04bafcu; return 0; }
r[11]=r[15];
goto P_0c04bafe;
P_0c04bafe: /* original 1f51, guest PC 0x0c04bafe */
if(!s->budget--) { s->failed_pc=0x0c04bafeu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c04bb00;
P_0c04bb00: /* original 2f62, guest PC 0x0c04bb00 */
if(!s->budget--) { s->failed_pc=0x0c04bb00u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c04bb02;
P_0c04bb02: /* original e500, guest PC 0x0c04bb02 */
if(!s->budget--) { s->failed_pc=0x0c04bb02u; return 0; }
r[5]=0x00000000u;
goto P_0c04bb04;
P_0c04bb04: /* original 9a16, guest PC 0x0c04bb04 */
if(!s->budget--) { s->failed_pc=0x0c04bb04u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bb34u,2);
goto P_0c04bb06;
P_0c04bb06: /* original 7b08, guest PC 0x0c04bb06 */
if(!s->budget--) { s->failed_pc=0x0c04bb06u; return 0; }
r[11]+=0x00000008u;
goto P_0c04bb08;
P_0c04bb08: /* original d30e, guest PC 0x0c04bb08 */
if(!s->budget--) { s->failed_pc=0x0c04bb08u; return 0; }
r[3]=read(ram,0x0c04bb44u,4);
goto P_0c04bb0a;
P_0c04bb0a: /* original 66a3, guest PC 0x0c04bb0a */
if(!s->budget--) { s->failed_pc=0x0c04bb0au; return 0; }
r[6]=r[10];
goto P_0c04bb0c;
P_0c04bb0c: /* original 430b, guest PC 0x0c04bb0c */
if(!s->budget--) { s->failed_pc=0x0c04bb0cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04bb10u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04bb10u) { target=s->pc; goto dispatch; }
goto P_0c04bb10;
P_0c04bb0e: /* original 64b3, guest PC 0x0c04bb0e */
if(!s->budget--) { s->failed_pc=0x0c04bb0eu; return 0; }
r[4]=r[11];
goto P_0c04bb10;
P_0c04bb10: /* original 900d, guest PC 0x0c04bb10 */
if(!s->budget--) { s->failed_pc=0x0c04bb10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bb2eu,2);
goto P_0c04bb12;
P_0c04bb12: /* original 02de, guest PC 0x0c04bb12 */
if(!s->budget--) { s->failed_pc=0x0c04bb12u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c04bb14;
P_0c04bb14: /* original 7004, guest PC 0x0c04bb14 */
if(!s->budget--) { s->failed_pc=0x0c04bb14u; return 0; }
r[0]+=0x00000004u;
goto P_0c04bb16;
P_0c04bb16: /* original 03de, guest PC 0x0c04bb16 */
if(!s->budget--) { s->failed_pc=0x0c04bb16u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c04bb18;
P_0c04bb18: /* original 3320, guest PC 0x0c04bb18 */
if(!s->budget--) { s->failed_pc=0x0c04bb18u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c04bb1a;
P_0c04bb1a: /* original 8b01, guest PC 0x0c04bb1a */
if(!s->budget--) { s->failed_pc=0x0c04bb1au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04bb20; }
goto P_0c04bb1c;
P_0c04bb1c: /* original a049, guest PC 0x0c04bb1c */
if(!s->budget--) { s->failed_pc=0x0c04bb1cu; return 0; }
r[0]=0xffffffffu;
goto P_0c04bbb2;
P_0c04bb1e: /* original e0ff, guest PC 0x0c04bb1e */
if(!s->budget--) { s->failed_pc=0x0c04bb1eu; return 0; }
r[0]=0xffffffffu;
goto P_0c04bb20;
P_0c04bb20: /* original 9e07, guest PC 0x0c04bb20 */
if(!s->budget--) { s->failed_pc=0x0c04bb20u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bb32u,2);
goto P_0c04bb22;
P_0c04bb22: /* original e400, guest PC 0x0c04bb22 */
if(!s->budget--) { s->failed_pc=0x0c04bb22u; return 0; }
r[4]=0x00000000u;
goto P_0c04bb24;
P_0c04bb24: /* original 6c43, guest PC 0x0c04bb24 */
if(!s->budget--) { s->failed_pc=0x0c04bb24u; return 0; }
r[12]=r[4];
goto P_0c04bb26;
P_0c04bb26: /* original a01a, guest PC 0x0c04bb26 */
if(!s->budget--) { s->failed_pc=0x0c04bb26u; return 0; }
r[14]+=r[13];
goto P_0c04bb5e;
P_0c04bb28: /* original 3edc, guest PC 0x0c04bb28 */
if(!s->budget--) { s->failed_pc=0x0c04bb28u; return 0; }
r[14]+=r[13];
if(!vf3_matrix_family(0x0c04bb2au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04bb2au; return 0; } return 1;
P_0c04bb58: /* original 9283, guest PC 0x0c04bb58 */
if(!s->budget--) { s->failed_pc=0x0c04bb58u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bc62u,2);
goto P_0c04bb5a;
P_0c04bb5a: /* original 7c01, guest PC 0x0c04bb5a */
if(!s->budget--) { s->failed_pc=0x0c04bb5au; return 0; }
r[12]+=0x00000001u;
goto P_0c04bb5c;
P_0c04bb5c: /* original 3e2c, guest PC 0x0c04bb5c */
if(!s->budget--) { s->failed_pc=0x0c04bb5cu; return 0; }
r[14]+=r[2];
goto P_0c04bb5e;
P_0c04bb5e: /* original 53e3, guest PC 0x0c04bb5e */
if(!s->budget--) { s->failed_pc=0x0c04bb5eu; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c04bb60;
P_0c04bb60: /* original 2338, guest PC 0x0c04bb60 */
if(!s->budget--) { s->failed_pc=0x0c04bb60u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04bb62;
P_0c04bb62: /* original 8bf9, guest PC 0x0c04bb62 */
if(!s->budget--) { s->failed_pc=0x0c04bb62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04bb58; }
goto P_0c04bb64;
P_0c04bb64: /* original e301, guest PC 0x0c04bb64 */
if(!s->budget--) { s->failed_pc=0x0c04bb64u; return 0; }
r[3]=0x00000001u;
goto P_0c04bb66;
P_0c04bb66: /* original 1e42, guest PC 0x0c04bb66 */
if(!s->budget--) { s->failed_pc=0x0c04bb66u; return 0; }
write(ram,r[14]+8,r[4],4);
goto P_0c04bb68;
P_0c04bb68: /* original 1e33, guest PC 0x0c04bb68 */
if(!s->budget--) { s->failed_pc=0x0c04bb68u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c04bb6a;
P_0c04bb6a: /* original 4909, guest PC 0x0c04bb6a */
if(!s->budget--) { s->failed_pc=0x0c04bb6au; return 0; }
r[9]>>=2;
goto P_0c04bb6c;
P_0c04bb6c: /* original 907a, guest PC 0x0c04bb6c */
if(!s->budget--) { s->failed_pc=0x0c04bb6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bc64u,2);
goto P_0c04bb6e;
P_0c04bb6e: /* original 66a3, guest PC 0x0c04bb6e */
if(!s->budget--) { s->failed_pc=0x0c04bb6eu; return 0; }
r[6]=r[10];
goto P_0c04bb70;
P_0c04bb70: /* original 02de, guest PC 0x0c04bb70 */
if(!s->budget--) { s->failed_pc=0x0c04bb70u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c04bb72;
P_0c04bb72: /* original 1e25, guest PC 0x0c04bb72 */
if(!s->budget--) { s->failed_pc=0x0c04bb72u; return 0; }
write(ram,r[14]+20,r[2],4);
goto P_0c04bb74;
P_0c04bb74: /* original 63f2, guest PC 0x0c04bb74 */
if(!s->budget--) { s->failed_pc=0x0c04bb74u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c04bb76;
P_0c04bb76: /* original 2e32, guest PC 0x0c04bb76 */
if(!s->budget--) { s->failed_pc=0x0c04bb76u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c04bb78;
P_0c04bb78: /* original 1e91, guest PC 0x0c04bb78 */
if(!s->budget--) { s->failed_pc=0x0c04bb78u; return 0; }
write(ram,r[14]+4,r[9],4);
goto P_0c04bb7a;
P_0c04bb7a: /* original 9074, guest PC 0x0c04bb7a */
if(!s->budget--) { s->failed_pc=0x0c04bb7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bc66u,2);
goto P_0c04bb7c;
P_0c04bb7c: /* original 0e46, guest PC 0x0c04bb7c */
if(!s->budget--) { s->failed_pc=0x0c04bb7cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c04bb7e;
P_0c04bb7e: /* original 7004, guest PC 0x0c04bb7e */
if(!s->budget--) { s->failed_pc=0x0c04bb7eu; return 0; }
r[0]+=0x00000004u;
goto P_0c04bb80;
P_0c04bb80: /* original 1e44, guest PC 0x0c04bb80 */
if(!s->budget--) { s->failed_pc=0x0c04bb80u; return 0; }
write(ram,r[14]+16,r[4],4);
goto P_0c04bb82;
P_0c04bb82: /* original 0e46, guest PC 0x0c04bb82 */
if(!s->budget--) { s->failed_pc=0x0c04bb82u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c04bb84;
P_0c04bb84: /* original 64e3, guest PC 0x0c04bb84 */
if(!s->budget--) { s->failed_pc=0x0c04bb84u; return 0; }
r[4]=r[14];
goto P_0c04bb86;
P_0c04bb86: /* original 956f, guest PC 0x0c04bb86 */
if(!s->budget--) { s->failed_pc=0x0c04bb86u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bc68u,2);
goto P_0c04bb88;
P_0c04bb88: /* original d33b, guest PC 0x0c04bb88 */
if(!s->budget--) { s->failed_pc=0x0c04bb88u; return 0; }
r[3]=read(ram,0x0c04bc78u,4);
goto P_0c04bb8a;
P_0c04bb8a: /* original 35dc, guest PC 0x0c04bb8a */
if(!s->budget--) { s->failed_pc=0x0c04bb8au; return 0; }
r[5]+=r[13];
goto P_0c04bb8c;
P_0c04bb8c: /* original 430b, guest PC 0x0c04bb8c */
if(!s->budget--) { s->failed_pc=0x0c04bb8cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04bb90u;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04bb90u) { target=s->pc; goto dispatch; }
goto P_0c04bb90;
P_0c04bb8e: /* original 7418, guest PC 0x0c04bb8e */
if(!s->budget--) { s->failed_pc=0x0c04bb8eu; return 0; }
r[4]+=0x00000018u;
goto P_0c04bb90;
P_0c04bb90: /* original d23a, guest PC 0x0c04bb90 */
if(!s->budget--) { s->failed_pc=0x0c04bb90u; return 0; }
r[2]=read(ram,0x0c04bc7cu,4);
goto P_0c04bb92;
P_0c04bb92: /* original 420b, guest PC 0x0c04bb92 */
if(!s->budget--) { s->failed_pc=0x0c04bb92u; return 0; }
target=r[2];
r[16]=code_base|0x0c04bb96u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04bb96u) { target=s->pc; goto dispatch; }
goto P_0c04bb96;
P_0c04bb94: /* original 64b3, guest PC 0x0c04bb94 */
if(!s->budget--) { s->failed_pc=0x0c04bb94u; return 0; }
r[4]=r[11];
goto P_0c04bb96;
P_0c04bb96: /* original d338, guest PC 0x0c04bb96 */
if(!s->budget--) { s->failed_pc=0x0c04bb96u; return 0; }
r[3]=read(ram,0x0c04bc78u,4);
goto P_0c04bb98;
P_0c04bb98: /* original 64e3, guest PC 0x0c04bb98 */
if(!s->budget--) { s->failed_pc=0x0c04bb98u; return 0; }
r[4]=r[14];
goto P_0c04bb9a;
P_0c04bb9a: /* original 66a3, guest PC 0x0c04bb9a */
if(!s->budget--) { s->failed_pc=0x0c04bb9au; return 0; }
r[6]=r[10];
goto P_0c04bb9c;
P_0c04bb9c: /* original 65b3, guest PC 0x0c04bb9c */
if(!s->budget--) { s->failed_pc=0x0c04bb9cu; return 0; }
r[5]=r[11];
goto P_0c04bb9e;
P_0c04bb9e: /* original 430b, guest PC 0x0c04bb9e */
if(!s->budget--) { s->failed_pc=0x0c04bb9eu; return 0; }
target=r[3];
r[16]=code_base|0x0c04bba2u;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04bba2u) { target=s->pc; goto dispatch; }
goto P_0c04bba2;
P_0c04bba0: /* original 7418, guest PC 0x0c04bba0 */
if(!s->budget--) { s->failed_pc=0x0c04bba0u; return 0; }
r[4]+=0x00000018u;
goto P_0c04bba2;
P_0c04bba2: /* original 62f2, guest PC 0x0c04bba2 */
if(!s->budget--) { s->failed_pc=0x0c04bba2u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04bba4;
P_0c04bba4: /* original 79ff, guest PC 0x0c04bba4 */
if(!s->budget--) { s->failed_pc=0x0c04bba4u; return 0; }
r[9]+=0xffffffffu;
goto P_0c04bba6;
P_0c04bba6: /* original 4908, guest PC 0x0c04bba6 */
if(!s->budget--) { s->failed_pc=0x0c04bba6u; return 0; }
r[9]<<=2;
goto P_0c04bba8;
P_0c04bba8: /* original 60c3, guest PC 0x0c04bba8 */
if(!s->budget--) { s->failed_pc=0x0c04bba8u; return 0; }
r[0]=r[12];
goto P_0c04bbaa;
P_0c04bbaa: /* original 392c, guest PC 0x0c04bbaa */
if(!s->budget--) { s->failed_pc=0x0c04bbaau; return 0; }
r[9]+=r[2];
goto P_0c04bbac;
P_0c04bbac: /* original 1e96, guest PC 0x0c04bbac */
if(!s->budget--) { s->failed_pc=0x0c04bbacu; return 0; }
write(ram,r[14]+24,r[9],4);
goto P_0c04bbae;
P_0c04bbae: /* original 53f1, guest PC 0x0c04bbae */
if(!s->budget--) { s->failed_pc=0x0c04bbaeu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c04bbb0;
P_0c04bbb0: /* original 1e38, guest PC 0x0c04bbb0 */
if(!s->budget--) { s->failed_pc=0x0c04bbb0u; return 0; }
write(ram,r[14]+32,r[3],4);
goto P_0c04bbb2;
P_0c04bbb2: /* original 915a, guest PC 0x0c04bbb2 */
if(!s->budget--) { s->failed_pc=0x0c04bbb2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bc6au,2);
goto P_0c04bbb4;
P_0c04bbb4: /* original 3f1c, guest PC 0x0c04bbb4 */
if(!s->budget--) { s->failed_pc=0x0c04bbb4u; return 0; }
r[15]+=r[1];
goto P_0c04bbb6;
P_0c04bbb6: /* original 4f26, guest PC 0x0c04bbb6 */
if(!s->budget--) { s->failed_pc=0x0c04bbb6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04bbb8;
P_0c04bbb8: /* original 69f6, guest PC 0x0c04bbb8 */
if(!s->budget--) { s->failed_pc=0x0c04bbb8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04bbba;
P_0c04bbba: /* original 6af6, guest PC 0x0c04bbba */
if(!s->budget--) { s->failed_pc=0x0c04bbbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04bbbc;
P_0c04bbbc: /* original 6bf6, guest PC 0x0c04bbbc */
if(!s->budget--) { s->failed_pc=0x0c04bbbcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04bbbe;
P_0c04bbbe: /* original 6cf6, guest PC 0x0c04bbbe */
if(!s->budget--) { s->failed_pc=0x0c04bbbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04bbc0;
P_0c04bbc0: /* original 6df6, guest PC 0x0c04bbc0 */
if(!s->budget--) { s->failed_pc=0x0c04bbc0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04bbc2;
P_0c04bbc2: /* original 000b, guest PC 0x0c04bbc2 */
if(!s->budget--) { s->failed_pc=0x0c04bbc2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04bbc4: /* original 6ef6, guest PC 0x0c04bbc4 */
if(!s->budget--) { s->failed_pc=0x0c04bbc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04bbc6;
P_0c04bbc6: /* original 2fe6, guest PC 0x0c04bbc6 */
if(!s->budget--) { s->failed_pc=0x0c04bbc6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bbc8;
P_0c04bbc8: /* original 6e53, guest PC 0x0c04bbc8 */
if(!s->budget--) { s->failed_pc=0x0c04bbc8u; return 0; }
r[14]=r[5];
goto P_0c04bbca;
P_0c04bbca: /* original 904f, guest PC 0x0c04bbca */
if(!s->budget--) { s->failed_pc=0x0c04bbcau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bc6cu,2);
goto P_0c04bbcc;
P_0c04bbcc: /* original e200, guest PC 0x0c04bbcc */
if(!s->budget--) { s->failed_pc=0x0c04bbccu; return 0; }
r[2]=0x00000000u;
goto P_0c04bbce;
P_0c04bbce: /* original 034e, guest PC 0x0c04bbce */
if(!s->budget--) { s->failed_pc=0x0c04bbceu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c04bbd0;
P_0c04bbd0: /* original 73ff, guest PC 0x0c04bbd0 */
if(!s->budget--) { s->failed_pc=0x0c04bbd0u; return 0; }
r[3]+=0xffffffffu;
goto P_0c04bbd2;
P_0c04bbd2: /* original 0436, guest PC 0x0c04bbd2 */
if(!s->budget--) { s->failed_pc=0x0c04bbd2u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c04bbd4;
P_0c04bbd4: /* original 1e23, guest PC 0x0c04bbd4 */
if(!s->budget--) { s->failed_pc=0x0c04bbd4u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c04bbd6;
P_0c04bbd6: /* original 9046, guest PC 0x0c04bbd6 */
if(!s->budget--) { s->failed_pc=0x0c04bbd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bc66u,2);
goto P_0c04bbd8;
P_0c04bbd8: /* original 03ee, guest PC 0x0c04bbd8 */
if(!s->budget--) { s->failed_pc=0x0c04bbd8u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c04bbda;
P_0c04bbda: /* original 2338, guest PC 0x0c04bbda */
if(!s->budget--) { s->failed_pc=0x0c04bbdau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04bbdc;
P_0c04bbdc: /* original 8902, guest PC 0x0c04bbdc */
if(!s->budget--) { s->failed_pc=0x0c04bbdcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04bbe4; }
goto P_0c04bbde;
P_0c04bbde: /* original 03ee, guest PC 0x0c04bbde */
if(!s->budget--) { s->failed_pc=0x0c04bbdeu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c04bbe0;
P_0c04bbe0: /* original 432b, guest PC 0x0c04bbe0 */
if(!s->budget--) { s->failed_pc=0x0c04bbe0u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c04bbe2: /* original 6ef6, guest PC 0x0c04bbe2 */
if(!s->budget--) { s->failed_pc=0x0c04bbe2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04bbe4;
P_0c04bbe4: /* original 000b, guest PC 0x0c04bbe4 */
if(!s->budget--) { s->failed_pc=0x0c04bbe4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04bbe6: /* original 6ef6, guest PC 0x0c04bbe6 */
if(!s->budget--) { s->failed_pc=0x0c04bbe6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04bbe8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04bbe8u; return 0; } return 1;
P_0c04bc14: /* original 2fe6, guest PC 0x0c04bc14 */
if(!s->budget--) { s->failed_pc=0x0c04bc14u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bc16;
P_0c04bc16: /* original 2fd6, guest PC 0x0c04bc16 */
if(!s->budget--) { s->failed_pc=0x0c04bc16u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bc18;
P_0c04bc18: /* original 6d43, guest PC 0x0c04bc18 */
if(!s->budget--) { s->failed_pc=0x0c04bc18u; return 0; }
r[13]=r[4];
goto P_0c04bc1a;
P_0c04bc1a: /* original 2fc6, guest PC 0x0c04bc1a */
if(!s->budget--) { s->failed_pc=0x0c04bc1au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bc1c;
P_0c04bc1c: /* original ec00, guest PC 0x0c04bc1c */
if(!s->budget--) { s->failed_pc=0x0c04bc1cu; return 0; }
r[12]=0x00000000u;
goto P_0c04bc1e;
P_0c04bc1e: /* original 4f22, guest PC 0x0c04bc1e */
if(!s->budget--) { s->failed_pc=0x0c04bc1eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04bc20;
P_0c04bc20: /* original 9e26, guest PC 0x0c04bc20 */
if(!s->budget--) { s->failed_pc=0x0c04bc20u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bc70u,2);
goto P_0c04bc22;
P_0c04bc22: /* original a009, guest PC 0x0c04bc22 */
if(!s->budget--) { s->failed_pc=0x0c04bc22u; return 0; }
r[14]+=r[13];
goto P_0c04bc38;
P_0c04bc24: /* original 3edc, guest PC 0x0c04bc24 */
if(!s->budget--) { s->failed_pc=0x0c04bc24u; return 0; }
r[14]+=r[13];
goto P_0c04bc26;
P_0c04bc26: /* original 52e3, guest PC 0x0c04bc26 */
if(!s->budget--) { s->failed_pc=0x0c04bc26u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c04bc28;
P_0c04bc28: /* original 2228, guest PC 0x0c04bc28 */
if(!s->budget--) { s->failed_pc=0x0c04bc28u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04bc2a;
P_0c04bc2a: /* original 8902, guest PC 0x0c04bc2a */
if(!s->budget--) { s->failed_pc=0x0c04bc2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04bc32; }
goto P_0c04bc2c;
P_0c04bc2c: /* original 65e3, guest PC 0x0c04bc2c */
if(!s->budget--) { s->failed_pc=0x0c04bc2cu; return 0; }
r[5]=r[14];
goto P_0c04bc2e;
P_0c04bc2e: /* original bfca, guest PC 0x0c04bc2e */
if(!s->budget--) { s->failed_pc=0x0c04bc2eu; return 0; }
target=code_base|0x0c04bbc6u; r[16]=code_base|0x0c04bc32u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04bc32u) { target=s->pc; goto dispatch; }
goto P_0c04bc32;
P_0c04bc30: /* original 64d3, guest PC 0x0c04bc30 */
if(!s->budget--) { s->failed_pc=0x0c04bc30u; return 0; }
r[4]=r[13];
goto P_0c04bc32;
P_0c04bc32: /* original 9216, guest PC 0x0c04bc32 */
if(!s->budget--) { s->failed_pc=0x0c04bc32u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bc62u,2);
goto P_0c04bc34;
P_0c04bc34: /* original 7c01, guest PC 0x0c04bc34 */
if(!s->budget--) { s->failed_pc=0x0c04bc34u; return 0; }
r[12]+=0x00000001u;
goto P_0c04bc36;
P_0c04bc36: /* original 3e2c, guest PC 0x0c04bc36 */
if(!s->budget--) { s->failed_pc=0x0c04bc36u; return 0; }
r[14]+=r[2];
goto P_0c04bc38;
P_0c04bc38: /* original 901b, guest PC 0x0c04bc38 */
if(!s->budget--) { s->failed_pc=0x0c04bc38u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bc72u,2);
goto P_0c04bc3a;
P_0c04bc3a: /* original 03de, guest PC 0x0c04bc3a */
if(!s->budget--) { s->failed_pc=0x0c04bc3au; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c04bc3c;
P_0c04bc3c: /* original 3c33, guest PC 0x0c04bc3c */
if(!s->budget--) { s->failed_pc=0x0c04bc3cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[3])!=0);
goto P_0c04bc3e;
P_0c04bc3e: /* original 8bf2, guest PC 0x0c04bc3e */
if(!s->budget--) { s->failed_pc=0x0c04bc3eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04bc26; }
goto P_0c04bc40;
P_0c04bc40: /* original 4f26, guest PC 0x0c04bc40 */
if(!s->budget--) { s->failed_pc=0x0c04bc40u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04bc42;
P_0c04bc42: /* original 64d3, guest PC 0x0c04bc42 */
if(!s->budget--) { s->failed_pc=0x0c04bc42u; return 0; }
r[4]=r[13];
goto P_0c04bc44;
P_0c04bc44: /* original d30f, guest PC 0x0c04bc44 */
if(!s->budget--) { s->failed_pc=0x0c04bc44u; return 0; }
r[3]=read(ram,0x0c04bc84u,4);
goto P_0c04bc46;
P_0c04bc46: /* original 9612, guest PC 0x0c04bc46 */
if(!s->budget--) { s->failed_pc=0x0c04bc46u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bc6eu,2);
goto P_0c04bc48;
P_0c04bc48: /* original e500, guest PC 0x0c04bc48 */
if(!s->budget--) { s->failed_pc=0x0c04bc48u; return 0; }
r[5]=0x00000000u;
goto P_0c04bc4a;
P_0c04bc4a: /* original 6cf6, guest PC 0x0c04bc4a */
if(!s->budget--) { s->failed_pc=0x0c04bc4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04bc4c;
P_0c04bc4c: /* original 6df6, guest PC 0x0c04bc4c */
if(!s->budget--) { s->failed_pc=0x0c04bc4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04bc4e;
P_0c04bc4e: /* original 432b, guest PC 0x0c04bc4e */
if(!s->budget--) { s->failed_pc=0x0c04bc4eu; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c04bc50: /* original 6ef6, guest PC 0x0c04bc50 */
if(!s->budget--) { s->failed_pc=0x0c04bc50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04bc52u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04bc52u; return 0; } return 1;
P_0c04bd62: /* original 2fe6, guest PC 0x0c04bd62 */
if(!s->budget--) { s->failed_pc=0x0c04bd62u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bd64;
P_0c04bd64: /* original 2fd6, guest PC 0x0c04bd64 */
if(!s->budget--) { s->failed_pc=0x0c04bd64u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bd66;
P_0c04bd66: /* original 6d43, guest PC 0x0c04bd66 */
if(!s->budget--) { s->failed_pc=0x0c04bd66u; return 0; }
r[13]=r[4];
goto P_0c04bd68;
P_0c04bd68: /* original 2fc6, guest PC 0x0c04bd68 */
if(!s->budget--) { s->failed_pc=0x0c04bd68u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bd6a;
P_0c04bd6a: /* original 64d3, guest PC 0x0c04bd6a */
if(!s->budget--) { s->failed_pc=0x0c04bd6au; return 0; }
r[4]=r[13];
goto P_0c04bd6c;
P_0c04bd6c: /* original 2fb6, guest PC 0x0c04bd6c */
if(!s->budget--) { s->failed_pc=0x0c04bd6cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bd6e;
P_0c04bd6e: /* original ec00, guest PC 0x0c04bd6e */
if(!s->budget--) { s->failed_pc=0x0c04bd6eu; return 0; }
r[12]=0x00000000u;
goto P_0c04bd70;
P_0c04bd70: /* original 2fa6, guest PC 0x0c04bd70 */
if(!s->budget--) { s->failed_pc=0x0c04bd70u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bd72;
P_0c04bd72: /* original 2f96, guest PC 0x0c04bd72 */
if(!s->budget--) { s->failed_pc=0x0c04bd72u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bd74;
P_0c04bd74: /* original d90b, guest PC 0x0c04bd74 */
if(!s->budget--) { s->failed_pc=0x0c04bd74u; return 0; }
r[9]=read(ram,0x0c04bda4u,4);
goto P_0c04bd76;
P_0c04bd76: /* original d20f, guest PC 0x0c04bd76 */
if(!s->budget--) { s->failed_pc=0x0c04bd76u; return 0; }
r[2]=read(ram,0x0c04bdb4u,4);
goto P_0c04bd78;
P_0c04bd78: /* original 6392, guest PC 0x0c04bd78 */
if(!s->budget--) { s->failed_pc=0x0c04bd78u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c04bd7a;
P_0c04bd7a: /* original 4f22, guest PC 0x0c04bd7a */
if(!s->budget--) { s->failed_pc=0x0c04bd7au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04bd7c;
P_0c04bd7c: /* original 2232, guest PC 0x0c04bd7c */
if(!s->budget--) { s->failed_pc=0x0c04bd7cu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c04bd7e;
P_0c04bd7e: /* original 036a, guest PC 0x0c04bd7e */
if(!s->budget--) { s->failed_pc=0x0c04bd7eu; return 0; }
r[3]=r[18];
goto P_0c04bd80;
P_0c04bd80: /* original 7ffc, guest PC 0x0c04bd80 */
if(!s->budget--) { s->failed_pc=0x0c04bd80u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04bd82;
P_0c04bd82: /* original 29d2, guest PC 0x0c04bd82 */
if(!s->budget--) { s->failed_pc=0x0c04bd82u; return 0; }
write(ram,r[9],r[13],4);
goto P_0c04bd84;
P_0c04bd84: /* original 9e0a, guest PC 0x0c04bd84 */
if(!s->budget--) { s->failed_pc=0x0c04bd84u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bd9cu,2);
goto P_0c04bd86;
P_0c04bd86: /* original 2f32, guest PC 0x0c04bd86 */
if(!s->budget--) { s->failed_pc=0x0c04bd86u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c04bd88;
P_0c04bd88: /* original d10b, guest PC 0x0c04bd88 */
if(!s->budget--) { s->failed_pc=0x0c04bd88u; return 0; }
r[1]=read(ram,0x0c04bdb8u,4);
goto P_0c04bd8a;
P_0c04bd8a: /* original 3edc, guest PC 0x0c04bd8a */
if(!s->budget--) { s->failed_pc=0x0c04bd8au; return 0; }
r[14]+=r[13];
goto P_0c04bd8c;
P_0c04bd8c: /* original d307, guest PC 0x0c04bd8c */
if(!s->budget--) { s->failed_pc=0x0c04bd8cu; return 0; }
r[3]=read(ram,0x0c04bdacu,4);
goto P_0c04bd8e;
P_0c04bd8e: /* original 416a, guest PC 0x0c04bd8e */
if(!s->budget--) { s->failed_pc=0x0c04bd8eu; return 0; }
r[18]=r[1];
goto P_0c04bd90;
P_0c04bd90: /* original 430b, guest PC 0x0c04bd90 */
if(!s->budget--) { s->failed_pc=0x0c04bd90u; return 0; }
target=r[3];
r[16]=code_base|0x0c04bd94u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04bd94u) { target=s->pc; goto dispatch; }
goto P_0c04bd94;
P_0c04bd92: /* original 7404, guest PC 0x0c04bd92 */
if(!s->budget--) { s->failed_pc=0x0c04bd92u; return 0; }
r[4]+=0x00000004u;
goto P_0c04bd94;
P_0c04bd94: /* original da06, guest PC 0x0c04bd94 */
if(!s->budget--) { s->failed_pc=0x0c04bd94u; return 0; }
r[10]=read(ram,0x0c04bdb0u,4);
goto P_0c04bd96;
P_0c04bd96: /* original a032, guest PC 0x0c04bd96 */
if(!s->budget--) { s->failed_pc=0x0c04bd96u; return 0; }
r[11]=0x00000003u;
goto P_0c04bdfe;
P_0c04bd98: /* original eb03, guest PC 0x0c04bd98 */
if(!s->budget--) { s->failed_pc=0x0c04bd98u; return 0; }
r[11]=0x00000003u;
if(!vf3_matrix_family(0x0c04bd9au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04bd9au; return 0; } return 1;
P_0c04bdbc: /* original 9035, guest PC 0x0c04bdbc */
if(!s->budget--) { s->failed_pc=0x0c04bdbcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04be2au,2);
goto P_0c04bdbe;
P_0c04bdbe: /* original 0de6, guest PC 0x0c04bdbe */
if(!s->budget--) { s->failed_pc=0x0c04bdbeu; return 0; }
write(ram,r[13]+r[0],r[14],4);
goto P_0c04bdc0;
P_0c04bdc0: /* original 50e3, guest PC 0x0c04bdc0 */
if(!s->budget--) { s->failed_pc=0x0c04bdc0u; return 0; }
r[0]=read(ram,r[14]+12,4);
goto P_0c04bdc2;
P_0c04bdc2: /* original 8800, guest PC 0x0c04bdc2 */
if(!s->budget--) { s->failed_pc=0x0c04bdc2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c04bdc4;
P_0c04bdc4: /* original 8918, guest PC 0x0c04bdc4 */
if(!s->budget--) { s->failed_pc=0x0c04bdc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04bdf8; }
goto P_0c04bdc6;
P_0c04bdc6: /* original 8801, guest PC 0x0c04bdc6 */
if(!s->budget--) { s->failed_pc=0x0c04bdc6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c04bdc8;
P_0c04bdc8: /* original 8908, guest PC 0x0c04bdc8 */
if(!s->budget--) { s->failed_pc=0x0c04bdc8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04bddc; }
goto P_0c04bdca;
P_0c04bdca: /* original 8802, guest PC 0x0c04bdca */
if(!s->budget--) { s->failed_pc=0x0c04bdcau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c04bdcc;
P_0c04bdcc: /* original 8911, guest PC 0x0c04bdcc */
if(!s->budget--) { s->failed_pc=0x0c04bdccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04bdf2; }
goto P_0c04bdce;
P_0c04bdce: /* original 8803, guest PC 0x0c04bdce */
if(!s->budget--) { s->failed_pc=0x0c04bdceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c04bdd0;
P_0c04bdd0: /* original 8b12, guest PC 0x0c04bdd0 */
if(!s->budget--) { s->failed_pc=0x0c04bdd0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04bdf8; }
goto P_0c04bdd2;
P_0c04bdd2: /* original 65e3, guest PC 0x0c04bdd2 */
if(!s->budget--) { s->failed_pc=0x0c04bdd2u; return 0; }
r[5]=r[14];
goto P_0c04bdd4;
P_0c04bdd4: /* original bef7, guest PC 0x0c04bdd4 */
if(!s->budget--) { s->failed_pc=0x0c04bdd4u; return 0; }
target=code_base|0x0c04bbc6u; r[16]=code_base|0x0c04bdd8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04bdd8u) { target=s->pc; goto dispatch; }
goto P_0c04bdd8;
P_0c04bdd6: /* original 64d3, guest PC 0x0c04bdd6 */
if(!s->budget--) { s->failed_pc=0x0c04bdd6u; return 0; }
r[4]=r[13];
goto P_0c04bdd8;
P_0c04bdd8: /* original a00e, guest PC 0x0c04bdd8 */
if(!s->budget--) { s->failed_pc=0x0c04bdd8u; return 0; }
goto P_0c04bdf8;
P_0c04bdda: /* original 0009, guest PC 0x0c04bdda */
if(!s->budget--) { s->failed_pc=0x0c04bddau; return 0; }
goto P_0c04bddc;
P_0c04bddc: /* original 9026, guest PC 0x0c04bddc */
if(!s->budget--) { s->failed_pc=0x0c04bddcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04be2cu,2);
goto P_0c04bdde;
P_0c04bdde: /* original 53e5, guest PC 0x0c04bdde */
if(!s->budget--) { s->failed_pc=0x0c04bddeu; return 0; }
r[3]=read(ram,r[14]+20,4);
goto P_0c04bde0;
P_0c04bde0: /* original 02de, guest PC 0x0c04bde0 */
if(!s->budget--) { s->failed_pc=0x0c04bde0u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c04bde2;
P_0c04bde2: /* original 3326, guest PC 0x0c04bde2 */
if(!s->budget--) { s->failed_pc=0x0c04bde2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[2])!=0);
goto P_0c04bde4;
P_0c04bde4: /* original 8908, guest PC 0x0c04bde4 */
if(!s->budget--) { s->failed_pc=0x0c04bde4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04bdf8; }
goto P_0c04bde6;
P_0c04bde6: /* original 64e3, guest PC 0x0c04bde6 */
if(!s->budget--) { s->failed_pc=0x0c04bde6u; return 0; }
r[4]=r[14];
goto P_0c04bde8;
P_0c04bde8: /* original e501, guest PC 0x0c04bde8 */
if(!s->budget--) { s->failed_pc=0x0c04bde8u; return 0; }
r[5]=0x00000001u;
goto P_0c04bdea;
P_0c04bdea: /* original 4a0b, guest PC 0x0c04bdea */
if(!s->budget--) { s->failed_pc=0x0c04bdeau; return 0; }
target=r[10];
r[16]=code_base|0x0c04bdeeu;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04bdeeu) { target=s->pc; goto dispatch; }
goto P_0c04bdee;
P_0c04bdec: /* original 7418, guest PC 0x0c04bdec */
if(!s->budget--) { s->failed_pc=0x0c04bdecu; return 0; }
r[4]+=0x00000018u;
goto P_0c04bdee;
P_0c04bdee: /* original a003, guest PC 0x0c04bdee */
if(!s->budget--) { s->failed_pc=0x0c04bdeeu; return 0; }
goto P_0c04bdf8;
P_0c04bdf0: /* original 0009, guest PC 0x0c04bdf0 */
if(!s->budget--) { s->failed_pc=0x0c04bdf0u; return 0; }
goto P_0c04bdf2;
P_0c04bdf2: /* original 1eb3, guest PC 0x0c04bdf2 */
if(!s->budget--) { s->failed_pc=0x0c04bdf2u; return 0; }
write(ram,r[14]+12,r[11],4);
goto P_0c04bdf4;
P_0c04bdf4: /* original d30f, guest PC 0x0c04bdf4 */
if(!s->budget--) { s->failed_pc=0x0c04bdf4u; return 0; }
r[3]=read(ram,0x0c04be34u,4);
goto P_0c04bdf6;
P_0c04bdf6: /* original 1e38, guest PC 0x0c04bdf6 */
if(!s->budget--) { s->failed_pc=0x0c04bdf6u; return 0; }
write(ram,r[14]+32,r[3],4);
goto P_0c04bdf8;
P_0c04bdf8: /* original 9319, guest PC 0x0c04bdf8 */
if(!s->budget--) { s->failed_pc=0x0c04bdf8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04be2eu,2);
goto P_0c04bdfa;
P_0c04bdfa: /* original 7c01, guest PC 0x0c04bdfa */
if(!s->budget--) { s->failed_pc=0x0c04bdfau; return 0; }
r[12]+=0x00000001u;
goto P_0c04bdfc;
P_0c04bdfc: /* original 3e3c, guest PC 0x0c04bdfc */
if(!s->budget--) { s->failed_pc=0x0c04bdfcu; return 0; }
r[14]+=r[3];
goto P_0c04bdfe;
P_0c04bdfe: /* original 9017, guest PC 0x0c04bdfe */
if(!s->budget--) { s->failed_pc=0x0c04bdfeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04be30u,2);
goto P_0c04be00;
P_0c04be00: /* original 02de, guest PC 0x0c04be00 */
if(!s->budget--) { s->failed_pc=0x0c04be00u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c04be02;
P_0c04be02: /* original 3c23, guest PC 0x0c04be02 */
if(!s->budget--) { s->failed_pc=0x0c04be02u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[2])!=0);
goto P_0c04be04;
P_0c04be04: /* original 8bda, guest PC 0x0c04be04 */
if(!s->budget--) { s->failed_pc=0x0c04be04u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04bdbc; }
goto P_0c04be06;
P_0c04be06: /* original 9011, guest PC 0x0c04be06 */
if(!s->budget--) { s->failed_pc=0x0c04be06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04be2cu,2);
goto P_0c04be08;
P_0c04be08: /* original 02de, guest PC 0x0c04be08 */
if(!s->budget--) { s->failed_pc=0x0c04be08u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c04be0a;
P_0c04be0a: /* original 7201, guest PC 0x0c04be0a */
if(!s->budget--) { s->failed_pc=0x0c04be0au; return 0; }
r[2]+=0x00000001u;
goto P_0c04be0c;
P_0c04be0c: /* original 0d26, guest PC 0x0c04be0c */
if(!s->budget--) { s->failed_pc=0x0c04be0cu; return 0; }
write(ram,r[13]+r[0],r[2],4);
goto P_0c04be0e;
P_0c04be0e: /* original d10a, guest PC 0x0c04be0e */
if(!s->budget--) { s->failed_pc=0x0c04be0eu; return 0; }
r[1]=read(ram,0x0c04be38u,4);
goto P_0c04be10;
P_0c04be10: /* original 6312, guest PC 0x0c04be10 */
if(!s->budget--) { s->failed_pc=0x0c04be10u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c04be12;
P_0c04be12: /* original 2932, guest PC 0x0c04be12 */
if(!s->budget--) { s->failed_pc=0x0c04be12u; return 0; }
write(ram,r[9],r[3],4);
goto P_0c04be14;
P_0c04be14: /* original 62f2, guest PC 0x0c04be14 */
if(!s->budget--) { s->failed_pc=0x0c04be14u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04be16;
P_0c04be16: /* original 7f04, guest PC 0x0c04be16 */
if(!s->budget--) { s->failed_pc=0x0c04be16u; return 0; }
r[15]+=0x00000004u;
goto P_0c04be18;
P_0c04be18: /* original 4f26, guest PC 0x0c04be18 */
if(!s->budget--) { s->failed_pc=0x0c04be18u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04be1a;
P_0c04be1a: /* original 426a, guest PC 0x0c04be1a */
if(!s->budget--) { s->failed_pc=0x0c04be1au; return 0; }
r[18]=r[2];
goto P_0c04be1c;
P_0c04be1c: /* original 69f6, guest PC 0x0c04be1c */
if(!s->budget--) { s->failed_pc=0x0c04be1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04be1e;
P_0c04be1e: /* original 6af6, guest PC 0x0c04be1e */
if(!s->budget--) { s->failed_pc=0x0c04be1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04be20;
P_0c04be20: /* original 6bf6, guest PC 0x0c04be20 */
if(!s->budget--) { s->failed_pc=0x0c04be20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04be22;
P_0c04be22: /* original 6cf6, guest PC 0x0c04be22 */
if(!s->budget--) { s->failed_pc=0x0c04be22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04be24;
P_0c04be24: /* original 6df6, guest PC 0x0c04be24 */
if(!s->budget--) { s->failed_pc=0x0c04be24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04be26;
P_0c04be26: /* original 000b, guest PC 0x0c04be26 */
if(!s->budget--) { s->failed_pc=0x0c04be26u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04be28: /* original 6ef6, guest PC 0x0c04be28 */
if(!s->budget--) { s->failed_pc=0x0c04be28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04be2au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04be2au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
