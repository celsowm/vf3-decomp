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
int vf3_away_batch167_adapter_28(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c109cu: goto P_0c0c109c;
case 0x0c0c109eu: goto P_0c0c109e;
case 0x0c0c10a0u: goto P_0c0c10a0;
case 0x0c0c1184u: goto P_0c0c1184;
case 0x0c0c1186u: goto P_0c0c1186;
case 0x0c0c1188u: goto P_0c0c1188;
case 0x0c0c118au: goto P_0c0c118a;
case 0x0c0c118cu: goto P_0c0c118c;
case 0x0c0c118eu: goto P_0c0c118e;
case 0x0c0c1190u: goto P_0c0c1190;
case 0x0c0c1836u: goto P_0c0c1836;
case 0x0c0c1838u: goto P_0c0c1838;
case 0x0c0c183au: goto P_0c0c183a;
case 0x0c0c183cu: goto P_0c0c183c;
case 0x0c0c183eu: goto P_0c0c183e;
case 0x0c0c1840u: goto P_0c0c1840;
case 0x0c0c1842u: goto P_0c0c1842;
case 0x0c0c1844u: goto P_0c0c1844;
case 0x0c0c1846u: goto P_0c0c1846;
case 0x0c0c1848u: goto P_0c0c1848;
case 0x0c0c184au: goto P_0c0c184a;
case 0x0c0c184cu: goto P_0c0c184c;
case 0x0c0c184eu: goto P_0c0c184e;
case 0x0c0c1850u: goto P_0c0c1850;
case 0x0c0c1852u: goto P_0c0c1852;
case 0x0c0c1854u: goto P_0c0c1854;
case 0x0c0c1856u: goto P_0c0c1856;
case 0x0c0c1858u: goto P_0c0c1858;
case 0x0c0c185au: goto P_0c0c185a;
case 0x0c0c185cu: goto P_0c0c185c;
case 0x0c0c185eu: goto P_0c0c185e;
case 0x0c0c1860u: goto P_0c0c1860;
case 0x0c0c1862u: goto P_0c0c1862;
case 0x0c0c1864u: goto P_0c0c1864;
case 0x0c0c1866u: goto P_0c0c1866;
case 0x0c0c1868u: goto P_0c0c1868;
case 0x0c0c186au: goto P_0c0c186a;
case 0x0c0c186cu: goto P_0c0c186c;
case 0x0c0c186eu: goto P_0c0c186e;
case 0x0c0c1870u: goto P_0c0c1870;
case 0x0c0c1872u: goto P_0c0c1872;
case 0x0c0c1874u: goto P_0c0c1874;
case 0x0c0c1876u: goto P_0c0c1876;
case 0x0c0c1878u: goto P_0c0c1878;
case 0x0c0c187au: goto P_0c0c187a;
case 0x0c0c187cu: goto P_0c0c187c;
case 0x0c0c187eu: goto P_0c0c187e;
case 0x0c0c1880u: goto P_0c0c1880;
case 0x0c0c1882u: goto P_0c0c1882;
case 0x0c0c1884u: goto P_0c0c1884;
case 0x0c0c1886u: goto P_0c0c1886;
case 0x0c0c1888u: goto P_0c0c1888;
case 0x0c0c188au: goto P_0c0c188a;
case 0x0c0c188cu: goto P_0c0c188c;
case 0x0c0c188eu: goto P_0c0c188e;
case 0x0c0c1890u: goto P_0c0c1890;
case 0x0c0c1892u: goto P_0c0c1892;
case 0x0c0c1894u: goto P_0c0c1894;
case 0x0c0c1896u: goto P_0c0c1896;
case 0x0c0c1898u: goto P_0c0c1898;
case 0x0c0c189au: goto P_0c0c189a;
case 0x0c0c189cu: goto P_0c0c189c;
case 0x0c0c189eu: goto P_0c0c189e;
case 0x0c0c18a0u: goto P_0c0c18a0;
case 0x0c0c18a2u: goto P_0c0c18a2;
case 0x0c0c18a4u: goto P_0c0c18a4;
case 0x0c0c18a6u: goto P_0c0c18a6;
case 0x0c0c18a8u: goto P_0c0c18a8;
case 0x0c0c18aau: goto P_0c0c18aa;
case 0x0c0c18acu: goto P_0c0c18ac;
case 0x0c0c18aeu: goto P_0c0c18ae;
case 0x0c0c18b0u: goto P_0c0c18b0;
case 0x0c0c18b2u: goto P_0c0c18b2;
case 0x0c0c18b4u: goto P_0c0c18b4;
case 0x0c0c18b6u: goto P_0c0c18b6;
case 0x0c0c18b8u: goto P_0c0c18b8;
case 0x0c0c18bau: goto P_0c0c18ba;
case 0x0c0c18bcu: goto P_0c0c18bc;
case 0x0c0c18beu: goto P_0c0c18be;
case 0x0c0c1a62u: goto P_0c0c1a62;
case 0x0c0c1a64u: goto P_0c0c1a64;
case 0x0c0c5eaeu: goto P_0c0c5eae;
case 0x0c0c5eb0u: goto P_0c0c5eb0;
case 0x0c0c5eb2u: goto P_0c0c5eb2;
case 0x0c0c5eb4u: goto P_0c0c5eb4;
case 0x0c0c5eb6u: goto P_0c0c5eb6;
case 0x0c0c5eb8u: goto P_0c0c5eb8;
case 0x0c0c5ebau: goto P_0c0c5eba;
case 0x0c0c5ebcu: goto P_0c0c5ebc;
case 0x0c0c5ebeu: goto P_0c0c5ebe;
case 0x0c0c5ec0u: goto P_0c0c5ec0;
case 0x0c0c5ec2u: goto P_0c0c5ec2;
case 0x0c0c5ec4u: goto P_0c0c5ec4;
case 0x0c0c5ec6u: goto P_0c0c5ec6;
case 0x0c0c5ec8u: goto P_0c0c5ec8;
case 0x0c0c5ecau: goto P_0c0c5eca;
case 0x0c0c5eccu: goto P_0c0c5ecc;
case 0x0c0c5eceu: goto P_0c0c5ece;
case 0x0c0c5ed0u: goto P_0c0c5ed0;
case 0x0c0c5ed2u: goto P_0c0c5ed2;
case 0x0c0c5ed4u: goto P_0c0c5ed4;
case 0x0c0c5ed6u: goto P_0c0c5ed6;
case 0x0c0c5ed8u: goto P_0c0c5ed8;
case 0x0c0c5edau: goto P_0c0c5eda;
case 0x0c0c5edcu: goto P_0c0c5edc;
case 0x0c0c5edeu: goto P_0c0c5ede;
case 0x0c0c5ee0u: goto P_0c0c5ee0;
case 0x0c0c5ee2u: goto P_0c0c5ee2;
case 0x0c0c5ee4u: goto P_0c0c5ee4;
case 0x0c0c5ee6u: goto P_0c0c5ee6;
case 0x0c0c5ee8u: goto P_0c0c5ee8;
case 0x0c0c5eeau: goto P_0c0c5eea;
case 0x0c0c5eecu: goto P_0c0c5eec;
case 0x0c0c5eeeu: goto P_0c0c5eee;
case 0x0c0c5ef0u: goto P_0c0c5ef0;
case 0x0c0c5ef2u: goto P_0c0c5ef2;
case 0x0c0c5ef4u: goto P_0c0c5ef4;
case 0x0c0c5ef6u: goto P_0c0c5ef6;
case 0x0c0c5ef8u: goto P_0c0c5ef8;
case 0x0c0c5efau: goto P_0c0c5efa;
case 0x0c0c5efcu: goto P_0c0c5efc;
case 0x0c0c5efeu: goto P_0c0c5efe;
case 0x0c0c5f00u: goto P_0c0c5f00;
case 0x0c0c5f02u: goto P_0c0c5f02;
case 0x0c0c5f04u: goto P_0c0c5f04;
case 0x0c0c5f06u: goto P_0c0c5f06;
case 0x0c0c5f08u: goto P_0c0c5f08;
case 0x0c0c5f0au: goto P_0c0c5f0a;
case 0x0c0c5f0cu: goto P_0c0c5f0c;
case 0x0c0c5f0eu: goto P_0c0c5f0e;
case 0x0c0c5f10u: goto P_0c0c5f10;
case 0x0c0c66b8u: goto P_0c0c66b8;
case 0x0c0c66bau: goto P_0c0c66ba;
case 0x0c0c70a4u: goto P_0c0c70a4;
case 0x0c0c70a6u: goto P_0c0c70a6;
case 0x0c0c70a8u: goto P_0c0c70a8;
case 0x0c0c70aau: goto P_0c0c70aa;
case 0x0c0c70acu: goto P_0c0c70ac;
case 0x0c0c70aeu: goto P_0c0c70ae;
case 0x0c0c70b0u: goto P_0c0c70b0;
case 0x0c0c70b2u: goto P_0c0c70b2;
case 0x0c0c70b4u: goto P_0c0c70b4;
case 0x0c0c70b6u: goto P_0c0c70b6;
case 0x0c0c70b8u: goto P_0c0c70b8;
case 0x0c0c70bau: goto P_0c0c70ba;
case 0x0c0c70bcu: goto P_0c0c70bc;
case 0x0c0c70beu: goto P_0c0c70be;
case 0x0c0c70c0u: goto P_0c0c70c0;
case 0x0c0c70c2u: goto P_0c0c70c2;
case 0x0c0c70c4u: goto P_0c0c70c4;
case 0x0c0c70c6u: goto P_0c0c70c6;
case 0x0c0c70c8u: goto P_0c0c70c8;
case 0x0c0c70cau: goto P_0c0c70ca;
case 0x0c0c70ccu: goto P_0c0c70cc;
case 0x0c0c70ceu: goto P_0c0c70ce;
case 0x0c0c70d0u: goto P_0c0c70d0;
case 0x0c0c70d2u: goto P_0c0c70d2;
case 0x0c0c70d4u: goto P_0c0c70d4;
case 0x0c0c70d6u: goto P_0c0c70d6;
case 0x0c0c70d8u: goto P_0c0c70d8;
case 0x0c0c70dau: goto P_0c0c70da;
case 0x0c0c70dcu: goto P_0c0c70dc;
case 0x0c0c70deu: goto P_0c0c70de;
case 0x0c0c70e0u: goto P_0c0c70e0;
case 0x0c0c70e2u: goto P_0c0c70e2;
case 0x0c0c70e4u: goto P_0c0c70e4;
case 0x0c0c7648u: goto P_0c0c7648;
case 0x0c0c764au: goto P_0c0c764a;
case 0x0c0c764cu: goto P_0c0c764c;
case 0x0c0c764eu: goto P_0c0c764e;
case 0x0c0c7650u: goto P_0c0c7650;
case 0x0c0c7652u: goto P_0c0c7652;
case 0x0c0c7654u: goto P_0c0c7654;
case 0x0c0c7656u: goto P_0c0c7656;
case 0x0c0c7658u: goto P_0c0c7658;
case 0x0c0c765au: goto P_0c0c765a;
case 0x0c0c765cu: goto P_0c0c765c;
case 0x0c0c765eu: goto P_0c0c765e;
case 0x0c0c7660u: goto P_0c0c7660;
case 0x0c0c7662u: goto P_0c0c7662;
case 0x0c0c7664u: goto P_0c0c7664;
case 0x0c0c7666u: goto P_0c0c7666;
case 0x0c0c7668u: goto P_0c0c7668;
case 0x0c0c766au: goto P_0c0c766a;
case 0x0c0c766cu: goto P_0c0c766c;
case 0x0c0c766eu: goto P_0c0c766e;
case 0x0c0c7670u: goto P_0c0c7670;
case 0x0c0c7672u: goto P_0c0c7672;
case 0x0c0c7674u: goto P_0c0c7674;
case 0x0c0c7676u: goto P_0c0c7676;
case 0x0c0c7678u: goto P_0c0c7678;
case 0x0c0c767au: goto P_0c0c767a;
case 0x0c0c767cu: goto P_0c0c767c;
case 0x0c0c767eu: goto P_0c0c767e;
case 0x0c0c7680u: goto P_0c0c7680;
case 0x0c0c7682u: goto P_0c0c7682;
case 0x0c0c7684u: goto P_0c0c7684;
case 0x0c0c7686u: goto P_0c0c7686;
case 0x0c0c7688u: goto P_0c0c7688;
case 0x0c0c768au: goto P_0c0c768a;
case 0x0c0c768cu: goto P_0c0c768c;
case 0x0c0c768eu: goto P_0c0c768e;
case 0x0c0c7690u: goto P_0c0c7690;
case 0x0c0c7692u: goto P_0c0c7692;
case 0x0c0c7694u: goto P_0c0c7694;
case 0x0c0c7696u: goto P_0c0c7696;
case 0x0c0c7698u: goto P_0c0c7698;
case 0x0c0c769au: goto P_0c0c769a;
case 0x0c0c769cu: goto P_0c0c769c;
case 0x0c0c769eu: goto P_0c0c769e;
case 0x0c0c76a0u: goto P_0c0c76a0;
case 0x0c0c76a2u: goto P_0c0c76a2;
case 0x0c0c76a4u: goto P_0c0c76a4;
case 0x0c0c76a6u: goto P_0c0c76a6;
case 0x0c0c76a8u: goto P_0c0c76a8;
case 0x0c0c76aau: goto P_0c0c76aa;
case 0x0c0c76acu: goto P_0c0c76ac;
case 0x0c0c76aeu: goto P_0c0c76ae;
case 0x0c0c76b0u: goto P_0c0c76b0;
case 0x0c0c76b2u: goto P_0c0c76b2;
case 0x0c0c76b4u: goto P_0c0c76b4;
case 0x0c0c76b6u: goto P_0c0c76b6;
case 0x0c0c76b8u: goto P_0c0c76b8;
case 0x0c0c76bau: goto P_0c0c76ba;
case 0x0c0c76bcu: goto P_0c0c76bc;
case 0x0c0c76beu: goto P_0c0c76be;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c109c: /* original d34f, guest PC 0x0c0c109c */
if(!s->budget--) { s->failed_pc=0x0c0c109cu; return 0; }
r[3]=read(ram,0x0c0c11dcu,4);
goto P_0c0c109e;
P_0c0c109e: /* original 432b, guest PC 0x0c0c109e */
if(!s->budget--) { s->failed_pc=0x0c0c109eu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c07b204u: return vf3_matrix_family(0x0c07b204u,s,ram);
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
P_0c0c10a0: /* original 0009, guest PC 0x0c0c10a0 */
if(!s->budget--) { s->failed_pc=0x0c0c10a0u; return 0; }
if(!vf3_matrix_family(0x0c0c10a2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c10a2u; return 0; } return 1;
P_0c0c1184: /* original 4f22, guest PC 0x0c0c1184 */
if(!s->budget--) { s->failed_pc=0x0c0c1184u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c1186;
P_0c0c1186: /* original 0546, guest PC 0x0c0c1186 */
if(!s->budget--) { s->failed_pc=0x0c0c1186u; return 0; }
write(ram,r[5]+r[0],r[4],4);
goto P_0c0c1188;
P_0c0c1188: /* original 7004, guest PC 0x0c0c1188 */
if(!s->budget--) { s->failed_pc=0x0c0c1188u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c118a;
P_0c0c118a: /* original b46a, guest PC 0x0c0c118a */
if(!s->budget--) { s->failed_pc=0x0c0c118au; return 0; }
target=code_base|0x0c0c1a62u; r[16]=code_base|0x0c0c118eu;
write(ram,r[5]+r[0],r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c118eu) { target=s->pc; goto dispatch; }
goto P_0c0c118e;
P_0c0c118c: /* original 0546, guest PC 0x0c0c118c */
if(!s->budget--) { s->failed_pc=0x0c0c118cu; return 0; }
write(ram,r[5]+r[0],r[4],4);
goto P_0c0c118e;
P_0c0c118e: /* original af85, guest PC 0x0c0c118e */
if(!s->budget--) { s->failed_pc=0x0c0c118eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c109c;
P_0c0c1190: /* original 4f26, guest PC 0x0c0c1190 */
if(!s->budget--) { s->failed_pc=0x0c0c1190u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c0c1192u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c1192u; return 0; } return 1;
P_0c0c1836: /* original 2fe6, guest PC 0x0c0c1836 */
if(!s->budget--) { s->failed_pc=0x0c0c1836u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1838;
P_0c0c1838: /* original 6053, guest PC 0x0c0c1838 */
if(!s->budget--) { s->failed_pc=0x0c0c1838u; return 0; }
r[0]=r[5];
goto P_0c0c183a;
P_0c0c183a: /* original 2fc6, guest PC 0x0c0c183a */
if(!s->budget--) { s->failed_pc=0x0c0c183au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c183c;
P_0c0c183c: /* original e3f9, guest PC 0x0c0c183c */
if(!s->budget--) { s->failed_pc=0x0c0c183cu; return 0; }
r[3]=0xfffffff9u;
goto P_0c0c183e;
P_0c0c183e: /* original 2fb6, guest PC 0x0c0c183e */
if(!s->budget--) { s->failed_pc=0x0c0c183eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1840;
P_0c0c1840: /* original ec3f, guest PC 0x0c0c1840 */
if(!s->budget--) { s->failed_pc=0x0c0c1840u; return 0; }
r[12]=0x0000003fu;
goto P_0c0c1842;
P_0c0c1842: /* original 2fa6, guest PC 0x0c0c1842 */
if(!s->budget--) { s->failed_pc=0x0c0c1842u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1844;
P_0c0c1844: /* original eb3f, guest PC 0x0c0c1844 */
if(!s->budget--) { s->failed_pc=0x0c0c1844u; return 0; }
r[11]=0x0000003fu;
goto P_0c0c1846;
P_0c0c1846: /* original 453d, guest PC 0x0c0c1846 */
if(!s->budget--) { s->failed_pc=0x0c0c1846u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c0c1848;
P_0c0c1848: /* original 2f96, guest PC 0x0c0c1848 */
if(!s->budget--) { s->failed_pc=0x0c0c1848u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c184a;
P_0c0c184a: /* original 4001, guest PC 0x0c0c184a */
if(!s->budget--) { s->failed_pc=0x0c0c184au; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c0c184c;
P_0c0c184c: /* original 2f86, guest PC 0x0c0c184c */
if(!s->budget--) { s->failed_pc=0x0c0c184cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c184e;
P_0c0c184e: /* original 2b59, guest PC 0x0c0c184e */
if(!s->budget--) { s->failed_pc=0x0c0c184eu; return 0; }
r[11]&=r[5];
goto P_0c0c1850;
P_0c0c1850: /* original 5e43, guest PC 0x0c0c1850 */
if(!s->budget--) { s->failed_pc=0x0c0c1850u; return 0; }
r[14]=read(ram,r[4]+12,4);
goto P_0c0c1852;
P_0c0c1852: /* original 2c09, guest PC 0x0c0c1852 */
if(!s->budget--) { s->failed_pc=0x0c0c1852u; return 0; }
r[12]&=r[0];
goto P_0c0c1854;
P_0c0c1854: /* original e801, guest PC 0x0c0c1854 */
if(!s->budget--) { s->failed_pc=0x0c0c1854u; return 0; }
r[8]=0x00000001u;
goto P_0c0c1856;
P_0c0c1856: /* original ea00, guest PC 0x0c0c1856 */
if(!s->budget--) { s->failed_pc=0x0c0c1856u; return 0; }
r[10]=0x00000000u;
goto P_0c0c1858;
P_0c0c1858: /* original 36cc, guest PC 0x0c0c1858 */
if(!s->budget--) { s->failed_pc=0x0c0c1858u; return 0; }
r[6]+=r[12];
goto P_0c0c185a;
P_0c0c185a: /* original 37bc, guest PC 0x0c0c185a */
if(!s->budget--) { s->failed_pc=0x0c0c185au; return 0; }
r[7]+=r[11];
goto P_0c0c185c;
P_0c0c185c: /* original a021, guest PC 0x0c0c185c */
if(!s->budget--) { s->failed_pc=0x0c0c185cu; return 0; }
r[9]=r[10];
goto P_0c0c18a2;
P_0c0c185e: /* original 69a3, guest PC 0x0c0c185e */
if(!s->budget--) { s->failed_pc=0x0c0c185eu; return 0; }
r[9]=r[10];
goto P_0c0c1860;
P_0c0c1860: /* original 63e1, guest PC 0x0c0c1860 */
if(!s->budget--) { s->failed_pc=0x0c0c1860u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[3]=tmp;
goto P_0c0c1862;
P_0c0c1862: /* original 633d, guest PC 0x0c0c1862 */
if(!s->budget--) { s->failed_pc=0x0c0c1862u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c1864;
P_0c0c1864: /* original 2388, guest PC 0x0c0c1864 */
if(!s->budget--) { s->failed_pc=0x0c0c1864u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0c1866;
P_0c0c1866: /* original 891a, guest PC 0x0c0c1866 */
if(!s->budget--) { s->failed_pc=0x0c0c1866u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c1868;
P_0c0c1868: /* original 85e3, guest PC 0x0c0c1868 */
if(!s->budget--) { s->failed_pc=0x0c0c1868u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+6,2);
goto P_0c0c186a;
P_0c0c186a: /* original 610d, guest PC 0x0c0c186a */
if(!s->budget--) { s->failed_pc=0x0c0c186au; return 0; }
r[1]=r[0]&65535u;
goto P_0c0c186c;
P_0c0c186c: /* original 85e4, guest PC 0x0c0c186c */
if(!s->budget--) { s->failed_pc=0x0c0c186cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+8,2);
goto P_0c0c186e;
P_0c0c186e: /* original 3c17, guest PC 0x0c0c186e */
if(!s->budget--) { s->failed_pc=0x0c0c186eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>(int32_t)r[1])!=0);
goto P_0c0c1870;
P_0c0c1870: /* original 8d15, guest PC 0x0c0c1870 */
if(!s->budget--) { s->failed_pc=0x0c0c1870u; return 0; }
cond=r[17]&1u;
r[5]=r[0]&65535u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c1874;
P_0c0c1872: /* original 650d, guest PC 0x0c0c1872 */
if(!s->budget--) { s->failed_pc=0x0c0c1872u; return 0; }
r[5]=r[0]&65535u;
goto P_0c0c1874;
P_0c0c1874: /* original 3166, guest PC 0x0c0c1874 */
if(!s->budget--) { s->failed_pc=0x0c0c1874u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[6])!=0);
goto P_0c0c1876;
P_0c0c1876: /* original 8912, guest PC 0x0c0c1876 */
if(!s->budget--) { s->failed_pc=0x0c0c1876u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c1878;
P_0c0c1878: /* original 3b57, guest PC 0x0c0c1878 */
if(!s->budget--) { s->failed_pc=0x0c0c1878u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>(int32_t)r[5])!=0);
goto P_0c0c187a;
P_0c0c187a: /* original 8910, guest PC 0x0c0c187a */
if(!s->budget--) { s->failed_pc=0x0c0c187au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c187c;
P_0c0c187c: /* original 3576, guest PC 0x0c0c187c */
if(!s->budget--) { s->failed_pc=0x0c0c187cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[7])!=0);
goto P_0c0c187e;
P_0c0c187e: /* original 890e, guest PC 0x0c0c187e */
if(!s->budget--) { s->failed_pc=0x0c0c187eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c1880;
P_0c0c1880: /* original 85e5, guest PC 0x0c0c1880 */
if(!s->budget--) { s->failed_pc=0x0c0c1880u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+10,2);
goto P_0c0c1882;
P_0c0c1882: /* original 600d, guest PC 0x0c0c1882 */
if(!s->budget--) { s->failed_pc=0x0c0c1882u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c1884;
P_0c0c1884: /* original 310c, guest PC 0x0c0c1884 */
if(!s->budget--) { s->failed_pc=0x0c0c1884u; return 0; }
r[1]+=r[0];
goto P_0c0c1886;
P_0c0c1886: /* original 85e6, guest PC 0x0c0c1886 */
if(!s->budget--) { s->failed_pc=0x0c0c1886u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c0c1888;
P_0c0c1888: /* original 3c17, guest PC 0x0c0c1888 */
if(!s->budget--) { s->failed_pc=0x0c0c1888u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>(int32_t)r[1])!=0);
goto P_0c0c188a;
P_0c0c188a: /* original 600d, guest PC 0x0c0c188a */
if(!s->budget--) { s->failed_pc=0x0c0c188au; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c188c;
P_0c0c188c: /* original 8d07, guest PC 0x0c0c188c */
if(!s->budget--) { s->failed_pc=0x0c0c188cu; return 0; }
cond=r[17]&1u;
r[5]+=r[0];
if(cond) { goto P_0c0c189e; }
goto P_0c0c1890;
P_0c0c188e: /* original 350c, guest PC 0x0c0c188e */
if(!s->budget--) { s->failed_pc=0x0c0c188eu; return 0; }
r[5]+=r[0];
goto P_0c0c1890;
P_0c0c1890: /* original 3166, guest PC 0x0c0c1890 */
if(!s->budget--) { s->failed_pc=0x0c0c1890u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[6])!=0);
goto P_0c0c1892;
P_0c0c1892: /* original 8904, guest PC 0x0c0c1892 */
if(!s->budget--) { s->failed_pc=0x0c0c1892u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c1894;
P_0c0c1894: /* original 3b57, guest PC 0x0c0c1894 */
if(!s->budget--) { s->failed_pc=0x0c0c1894u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>(int32_t)r[5])!=0);
goto P_0c0c1896;
P_0c0c1896: /* original 8902, guest PC 0x0c0c1896 */
if(!s->budget--) { s->failed_pc=0x0c0c1896u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c1898;
P_0c0c1898: /* original 3576, guest PC 0x0c0c1898 */
if(!s->budget--) { s->failed_pc=0x0c0c1898u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[7])!=0);
goto P_0c0c189a;
P_0c0c189a: /* original 8900, guest PC 0x0c0c189a */
if(!s->budget--) { s->failed_pc=0x0c0c189au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c189c;
P_0c0c189c: /* original 2ea1, guest PC 0x0c0c189c */
if(!s->budget--) { s->failed_pc=0x0c0c189cu; return 0; }
write(ram,r[14],r[10],2);
goto P_0c0c189e;
P_0c0c189e: /* original 7e44, guest PC 0x0c0c189e */
if(!s->budget--) { s->failed_pc=0x0c0c189eu; return 0; }
r[14]+=0x00000044u;
goto P_0c0c18a0;
P_0c0c18a0: /* original 7901, guest PC 0x0c0c18a0 */
if(!s->budget--) { s->failed_pc=0x0c0c18a0u; return 0; }
r[9]+=0x00000001u;
goto P_0c0c18a2;
P_0c0c18a2: /* original e278, guest PC 0x0c0c18a2 */
if(!s->budget--) { s->failed_pc=0x0c0c18a2u; return 0; }
r[2]=0x00000078u;
goto P_0c0c18a4;
P_0c0c18a4: /* original 3922, guest PC 0x0c0c18a4 */
if(!s->budget--) { s->failed_pc=0x0c0c18a4u; return 0; }
r[17]=(r[17]&~1u)|((r[9]>=r[2])!=0);
goto P_0c0c18a6;
P_0c0c18a6: /* original 8bdb, guest PC 0x0c0c18a6 */
if(!s->budget--) { s->failed_pc=0x0c0c18a6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1860; }
goto P_0c0c18a8;
P_0c0c18a8: /* original e022, guest PC 0x0c0c18a8 */
if(!s->budget--) { s->failed_pc=0x0c0c18a8u; return 0; }
r[0]=0x00000022u;
goto P_0c0c18aa;
P_0c0c18aa: /* original 024d, guest PC 0x0c0c18aa */
if(!s->budget--) { s->failed_pc=0x0c0c18aau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c18ac;
P_0c0c18ac: /* original e301, guest PC 0x0c0c18ac */
if(!s->budget--) { s->failed_pc=0x0c0c18acu; return 0; }
r[3]=0x00000001u;
goto P_0c0c18ae;
P_0c0c18ae: /* original 223b, guest PC 0x0c0c18ae */
if(!s->budget--) { s->failed_pc=0x0c0c18aeu; return 0; }
r[2]|=r[3];
goto P_0c0c18b0;
P_0c0c18b0: /* original 0425, guest PC 0x0c0c18b0 */
if(!s->budget--) { s->failed_pc=0x0c0c18b0u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0c18b2;
P_0c0c18b2: /* original 68f6, guest PC 0x0c0c18b2 */
if(!s->budget--) { s->failed_pc=0x0c0c18b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c18b4;
P_0c0c18b4: /* original 69f6, guest PC 0x0c0c18b4 */
if(!s->budget--) { s->failed_pc=0x0c0c18b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c18b6;
P_0c0c18b6: /* original 6af6, guest PC 0x0c0c18b6 */
if(!s->budget--) { s->failed_pc=0x0c0c18b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c18b8;
P_0c0c18b8: /* original 6bf6, guest PC 0x0c0c18b8 */
if(!s->budget--) { s->failed_pc=0x0c0c18b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c18ba;
P_0c0c18ba: /* original 6cf6, guest PC 0x0c0c18ba */
if(!s->budget--) { s->failed_pc=0x0c0c18bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c18bc;
P_0c0c18bc: /* original 000b, guest PC 0x0c0c18bc */
if(!s->budget--) { s->failed_pc=0x0c0c18bcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c18be: /* original 6ef6, guest PC 0x0c0c18be */
if(!s->budget--) { s->failed_pc=0x0c0c18beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c18c0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c18c0u; return 0; } return 1;
P_0c0c1a62: /* original 000b, guest PC 0x0c0c1a62 */
if(!s->budget--) { s->failed_pc=0x0c0c1a62u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c1a64: /* original 0009, guest PC 0x0c0c1a64 */
if(!s->budget--) { s->failed_pc=0x0c0c1a64u; return 0; }
if(!vf3_matrix_family(0x0c0c1a66u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c1a66u; return 0; } return 1;
P_0c0c5eae: /* original 2fe6, guest PC 0x0c0c5eae */
if(!s->budget--) { s->failed_pc=0x0c0c5eaeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5eb0;
P_0c0c5eb0: /* original 2fd6, guest PC 0x0c0c5eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5eb2;
P_0c0c5eb2: /* original ed1f, guest PC 0x0c0c5eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb2u; return 0; }
r[13]=0x0000001fu;
goto P_0c0c5eb4;
P_0c0c5eb4: /* original 2d49, guest PC 0x0c0c5eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb4u; return 0; }
r[13]&=r[4];
goto P_0c0c5eb6;
P_0c0c5eb6: /* original d31b, guest PC 0x0c0c5eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb6u; return 0; }
r[3]=read(ram,0x0c0c5f24u,4);
goto P_0c0c5eb8;
P_0c0c5eb8: /* original 4d00, guest PC 0x0c0c5eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c0c5eba;
P_0c0c5eba: /* original 6ed3, guest PC 0x0c0c5eba */
if(!s->budget--) { s->failed_pc=0x0c0c5ebau; return 0; }
r[14]=r[13];
goto P_0c0c5ebc;
P_0c0c5ebc: /* original 4e08, guest PC 0x0c0c5ebc */
if(!s->budget--) { s->failed_pc=0x0c0c5ebcu; return 0; }
r[14]<<=2;
goto P_0c0c5ebe;
P_0c0c5ebe: /* original 3e3c, guest PC 0x0c0c5ebe */
if(!s->budget--) { s->failed_pc=0x0c0c5ebeu; return 0; }
r[14]+=r[3];
goto P_0c0c5ec0;
P_0c0c5ec0: /* original 62e2, guest PC 0x0c0c5ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0c5ec2;
P_0c0c5ec2: /* original 4f22, guest PC 0x0c0c5ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5ec4;
P_0c0c5ec4: /* original 2228, guest PC 0x0c0c5ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c5ec6;
P_0c0c5ec6: /* original 8920, guest PC 0x0c0c5ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5f0a; }
goto P_0c0c5ec8;
P_0c0c5ec8: /* original d217, guest PC 0x0c0c5ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec8u; return 0; }
r[2]=read(ram,0x0c0c5f28u,4);
goto P_0c0c5eca;
P_0c0c5eca: /* original 61e2, guest PC 0x0c0c5eca */
if(!s->budget--) { s->failed_pc=0x0c0c5ecau; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0c5ecc;
P_0c0c5ecc: /* original 6022, guest PC 0x0c0c5ecc */
if(!s->budget--) { s->failed_pc=0x0c0c5eccu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0c5ece;
P_0c0c5ece: /* original 3010, guest PC 0x0c0c5ece */
if(!s->budget--) { s->failed_pc=0x0c0c5eceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c0c5ed0;
P_0c0c5ed0: /* original 891b, guest PC 0x0c0c5ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5f0a; }
goto P_0c0c5ed2;
P_0c0c5ed2: /* original d317, guest PC 0x0c0c5ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed2u; return 0; }
r[3]=read(ram,0x0c0c5f30u,4);
goto P_0c0c5ed4;
P_0c0c5ed4: /* original d115, guest PC 0x0c0c5ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed4u; return 0; }
r[1]=read(ram,0x0c0c5f2cu,4);
goto P_0c0c5ed6;
P_0c0c5ed6: /* original 6532, guest PC 0x0c0c5ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed6u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c0c5ed8;
P_0c0c5ed8: /* original d216, guest PC 0x0c0c5ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed8u; return 0; }
r[2]=read(ram,0x0c0c5f34u,4);
goto P_0c0c5eda;
P_0c0c5eda: /* original 351c, guest PC 0x0c0c5eda */
if(!s->budget--) { s->failed_pc=0x0c0c5edau; return 0; }
r[5]+=r[1];
goto P_0c0c5edc;
P_0c0c5edc: /* original 420b, guest PC 0x0c0c5edc */
if(!s->budget--) { s->failed_pc=0x0c0c5edcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c5ee0u;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5ee0u) { target=s->pc; goto dispatch; }
goto P_0c0c5ee0;
P_0c0c5ede: /* original 64e2, guest PC 0x0c0c5ede */
if(!s->budget--) { s->failed_pc=0x0c0c5edeu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0c5ee0;
P_0c0c5ee0: /* original d30e, guest PC 0x0c0c5ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee0u; return 0; }
r[3]=read(ram,0x0c0c5f1cu,4);
goto P_0c0c5ee2;
P_0c0c5ee2: /* original 430b, guest PC 0x0c0c5ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5ee6u;
r[4]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5ee6u) { target=s->pc; goto dispatch; }
goto P_0c0c5ee6;
P_0c0c5ee4: /* original e404, guest PC 0x0c0c5ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee4u; return 0; }
r[4]=0x00000004u;
goto P_0c0c5ee6;
P_0c0c5ee6: /* original d212, guest PC 0x0c0c5ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee6u; return 0; }
r[2]=read(ram,0x0c0c5f30u,4);
goto P_0c0c5ee8;
P_0c0c5ee8: /* original e504, guest PC 0x0c0c5ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee8u; return 0; }
r[5]=0x00000004u;
goto P_0c0c5eea;
P_0c0c5eea: /* original d113, guest PC 0x0c0c5eea */
if(!s->budget--) { s->failed_pc=0x0c0c5eeau; return 0; }
r[1]=read(ram,0x0c0c5f38u,4);
goto P_0c0c5eec;
P_0c0c5eec: /* original 6422, guest PC 0x0c0c5eec */
if(!s->budget--) { s->failed_pc=0x0c0c5eecu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0c5eee;
P_0c0c5eee: /* original d30f, guest PC 0x0c0c5eee */
if(!s->budget--) { s->failed_pc=0x0c0c5eeeu; return 0; }
r[3]=read(ram,0x0c0c5f2cu,4);
goto P_0c0c5ef0;
P_0c0c5ef0: /* original 410b, guest PC 0x0c0c5ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef0u; return 0; }
target=r[1];
r[16]=code_base|0x0c0c5ef4u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5ef4u) { target=s->pc; goto dispatch; }
goto P_0c0c5ef4;
P_0c0c5ef2: /* original 343c, guest PC 0x0c0c5ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef2u; return 0; }
r[4]+=r[3];
goto P_0c0c5ef4;
P_0c0c5ef4: /* original 2008, guest PC 0x0c0c5ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c5ef6;
P_0c0c5ef6: /* original 8903, guest PC 0x0c0c5ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5f00; }
goto P_0c0c5ef8;
P_0c0c5ef8: /* original d210, guest PC 0x0c0c5ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef8u; return 0; }
r[2]=read(ram,0x0c0c5f3cu,4);
goto P_0c0c5efa;
P_0c0c5efa: /* original 950a, guest PC 0x0c0c5efa */
if(!s->budget--) { s->failed_pc=0x0c0c5efau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5f12u,2);
goto P_0c0c5efc;
P_0c0c5efc: /* original 420b, guest PC 0x0c0c5efc */
if(!s->budget--) { s->failed_pc=0x0c0c5efcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c5f00u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5f00u) { target=s->pc; goto dispatch; }
goto P_0c0c5f00;
P_0c0c5efe: /* original e401, guest PC 0x0c0c5efe */
if(!s->budget--) { s->failed_pc=0x0c0c5efeu; return 0; }
r[4]=0x00000001u;
goto P_0c0c5f00;
P_0c0c5f00: /* original d008, guest PC 0x0c0c5f00 */
if(!s->budget--) { s->failed_pc=0x0c0c5f00u; return 0; }
r[0]=read(ram,0x0c0c5f24u,4);
goto P_0c0c5f02;
P_0c0c5f02: /* original 4d08, guest PC 0x0c0c5f02 */
if(!s->budget--) { s->failed_pc=0x0c0c5f02u; return 0; }
r[13]<<=2;
goto P_0c0c5f04;
P_0c0c5f04: /* original d308, guest PC 0x0c0c5f04 */
if(!s->budget--) { s->failed_pc=0x0c0c5f04u; return 0; }
r[3]=read(ram,0x0c0c5f28u,4);
goto P_0c0c5f06;
P_0c0c5f06: /* original 02de, guest PC 0x0c0c5f06 */
if(!s->budget--) { s->failed_pc=0x0c0c5f06u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c0c5f08;
P_0c0c5f08: /* original 2322, guest PC 0x0c0c5f08 */
if(!s->budget--) { s->failed_pc=0x0c0c5f08u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0c5f0a;
P_0c0c5f0a: /* original 4f26, guest PC 0x0c0c5f0a */
if(!s->budget--) { s->failed_pc=0x0c0c5f0au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5f0c;
P_0c0c5f0c: /* original 6df6, guest PC 0x0c0c5f0c */
if(!s->budget--) { s->failed_pc=0x0c0c5f0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c5f0e;
P_0c0c5f0e: /* original 000b, guest PC 0x0c0c5f0e */
if(!s->budget--) { s->failed_pc=0x0c0c5f0eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5f10: /* original 6ef6, guest PC 0x0c0c5f10 */
if(!s->budget--) { s->failed_pc=0x0c0c5f10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c5f12u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5f12u; return 0; } return 1;
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
P_0c0c70a4: /* original d413, guest PC 0x0c0c70a4 */
if(!s->budget--) { s->failed_pc=0x0c0c70a4u; return 0; }
r[4]=read(ram,0x0c0c70f4u,4);
goto P_0c0c70a6;
P_0c0c70a6: /* original e01c, guest PC 0x0c0c70a6 */
if(!s->budget--) { s->failed_pc=0x0c0c70a6u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c70a8;
P_0c0c70a8: /* original e50f, guest PC 0x0c0c70a8 */
if(!s->budget--) { s->failed_pc=0x0c0c70a8u; return 0; }
r[5]=0x0000000fu;
goto P_0c0c70aa;
P_0c0c70aa: /* original 044c, guest PC 0x0c0c70aa */
if(!s->budget--) { s->failed_pc=0x0c0c70aau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c70ac;
P_0c0c70ac: /* original d012, guest PC 0x0c0c70ac */
if(!s->budget--) { s->failed_pc=0x0c0c70acu; return 0; }
r[0]=read(ram,0x0c0c70f8u,4);
goto P_0c0c70ae;
P_0c0c70ae: /* original 644c, guest PC 0x0c0c70ae */
if(!s->budget--) { s->failed_pc=0x0c0c70aeu; return 0; }
r[4]=r[4]&255u;
goto P_0c0c70b0;
P_0c0c70b0: /* original 2459, guest PC 0x0c0c70b0 */
if(!s->budget--) { s->failed_pc=0x0c0c70b0u; return 0; }
r[4]&=r[5];
goto P_0c0c70b2;
P_0c0c70b2: /* original 4408, guest PC 0x0c0c70b2 */
if(!s->budget--) { s->failed_pc=0x0c0c70b2u; return 0; }
r[4]<<=2;
goto P_0c0c70b4;
P_0c0c70b4: /* original 4408, guest PC 0x0c0c70b4 */
if(!s->budget--) { s->failed_pc=0x0c0c70b4u; return 0; }
r[4]<<=2;
goto P_0c0c70b6;
P_0c0c70b6: /* original 4408, guest PC 0x0c0c70b6 */
if(!s->budget--) { s->failed_pc=0x0c0c70b6u; return 0; }
r[4]<<=2;
goto P_0c0c70b8;
P_0c0c70b8: /* original 044c, guest PC 0x0c0c70b8 */
if(!s->budget--) { s->failed_pc=0x0c0c70b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c70ba;
P_0c0c70ba: /* original 644c, guest PC 0x0c0c70ba */
if(!s->budget--) { s->failed_pc=0x0c0c70bau; return 0; }
r[4]=r[4]&255u;
goto P_0c0c70bc;
P_0c0c70bc: /* original 3457, guest PC 0x0c0c70bc */
if(!s->budget--) { s->failed_pc=0x0c0c70bcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[5])!=0);
goto P_0c0c70be;
P_0c0c70be: /* original 8b01, guest PC 0x0c0c70be */
if(!s->budget--) { s->failed_pc=0x0c0c70beu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c70c4; }
goto P_0c0c70c0;
P_0c0c70c0: /* original a003, guest PC 0x0c0c70c0 */
if(!s->budget--) { s->failed_pc=0x0c0c70c0u; return 0; }
r[4]=r[5];
goto P_0c0c70ca;
P_0c0c70c2: /* original 6453, guest PC 0x0c0c70c2 */
if(!s->budget--) { s->failed_pc=0x0c0c70c2u; return 0; }
r[4]=r[5];
goto P_0c0c70c4;
P_0c0c70c4: /* original 4411, guest PC 0x0c0c70c4 */
if(!s->budget--) { s->failed_pc=0x0c0c70c4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c70c6;
P_0c0c70c6: /* original 8900, guest PC 0x0c0c70c6 */
if(!s->budget--) { s->failed_pc=0x0c0c70c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c70ca; }
goto P_0c0c70c8;
P_0c0c70c8: /* original e400, guest PC 0x0c0c70c8 */
if(!s->budget--) { s->failed_pc=0x0c0c70c8u; return 0; }
r[4]=0x00000000u;
goto P_0c0c70ca;
P_0c0c70ca: /* original d20c, guest PC 0x0c0c70ca */
if(!s->budget--) { s->failed_pc=0x0c0c70cau; return 0; }
r[2]=read(ram,0x0c0c70fcu,4);
goto P_0c0c70cc;
P_0c0c70cc: /* original 4400, guest PC 0x0c0c70cc */
if(!s->budget--) { s->failed_pc=0x0c0c70ccu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0c70ce;
P_0c0c70ce: /* original d60c, guest PC 0x0c0c70ce */
if(!s->budget--) { s->failed_pc=0x0c0c70ceu; return 0; }
r[6]=read(ram,0x0c0c7100u,4);
goto P_0c0c70d0;
P_0c0c70d0: /* original 6043, guest PC 0x0c0c70d0 */
if(!s->budget--) { s->failed_pc=0x0c0c70d0u; return 0; }
r[0]=r[4];
goto P_0c0c70d2;
P_0c0c70d2: /* original 910a, guest PC 0x0c0c70d2 */
if(!s->budget--) { s->failed_pc=0x0c0c70d2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c70eau,2);
goto P_0c0c70d4;
P_0c0c70d4: /* original 6522, guest PC 0x0c0c70d4 */
if(!s->budget--) { s->failed_pc=0x0c0c70d4u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c0c70d6;
P_0c0c70d6: /* original 036c, guest PC 0x0c0c70d6 */
if(!s->budget--) { s->failed_pc=0x0c0c70d6u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0c70d8;
P_0c0c70d8: /* original 7001, guest PC 0x0c0c70d8 */
if(!s->budget--) { s->failed_pc=0x0c0c70d8u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c70da;
P_0c0c70da: /* original 315c, guest PC 0x0c0c70da */
if(!s->budget--) { s->failed_pc=0x0c0c70dau; return 0; }
r[1]+=r[5];
goto P_0c0c70dc;
P_0c0c70dc: /* original 2130, guest PC 0x0c0c70dc */
if(!s->budget--) { s->failed_pc=0x0c0c70dcu; return 0; }
write(ram,r[1],r[3],1);
goto P_0c0c70de;
P_0c0c70de: /* original 036c, guest PC 0x0c0c70de */
if(!s->budget--) { s->failed_pc=0x0c0c70deu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0c70e0;
P_0c0c70e0: /* original 9004, guest PC 0x0c0c70e0 */
if(!s->budget--) { s->failed_pc=0x0c0c70e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c70ecu,2);
goto P_0c0c70e2;
P_0c0c70e2: /* original 000b, guest PC 0x0c0c70e2 */
if(!s->budget--) { s->failed_pc=0x0c0c70e2u; return 0; }
target=r[16];
write(ram,r[5]+r[0],r[3],1);
s->pc=target; return ram->oob==0;
P_0c0c70e4: /* original 0534, guest PC 0x0c0c70e4 */
if(!s->budget--) { s->failed_pc=0x0c0c70e4u; return 0; }
write(ram,r[5]+r[0],r[3],1);
if(!vf3_matrix_family(0x0c0c70e6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c70e6u; return 0; } return 1;
P_0c0c7648: /* original 2fe6, guest PC 0x0c0c7648 */
if(!s->budget--) { s->failed_pc=0x0c0c7648u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c764a;
P_0c0c764a: /* original 2fd6, guest PC 0x0c0c764a */
if(!s->budget--) { s->failed_pc=0x0c0c764au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c764c;
P_0c0c764c: /* original 2fc6, guest PC 0x0c0c764c */
if(!s->budget--) { s->failed_pc=0x0c0c764cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c764e;
P_0c0c764e: /* original 2fb6, guest PC 0x0c0c764e */
if(!s->budget--) { s->failed_pc=0x0c0c764eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7650;
P_0c0c7650: /* original 2fa6, guest PC 0x0c0c7650 */
if(!s->budget--) { s->failed_pc=0x0c0c7650u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7652;
P_0c0c7652: /* original 2f96, guest PC 0x0c0c7652 */
if(!s->budget--) { s->failed_pc=0x0c0c7652u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7654;
P_0c0c7654: /* original da40, guest PC 0x0c0c7654 */
if(!s->budget--) { s->failed_pc=0x0c0c7654u; return 0; }
r[10]=read(ram,0x0c0c7758u,4);
goto P_0c0c7656;
P_0c0c7656: /* original 9077, guest PC 0x0c0c7656 */
if(!s->budget--) { s->failed_pc=0x0c0c7656u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7748u,2);
goto P_0c0c7658;
P_0c0c7658: /* original 4f22, guest PC 0x0c0c7658 */
if(!s->budget--) { s->failed_pc=0x0c0c7658u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c765a;
P_0c0c765a: /* original 0cae, guest PC 0x0c0c765a */
if(!s->budget--) { s->failed_pc=0x0c0c765au; return 0; }
r[12]=read(ram,r[10]+r[0],4);
goto P_0c0c765c;
P_0c0c765c: /* original 7004, guest PC 0x0c0c765c */
if(!s->budget--) { s->failed_pc=0x0c0c765cu; return 0; }
r[0]+=0x00000004u;
goto P_0c0c765e;
P_0c0c765e: /* original dd3f, guest PC 0x0c0c765e */
if(!s->budget--) { s->failed_pc=0x0c0c765eu; return 0; }
r[13]=read(ram,0x0c0c775cu,4);
goto P_0c0c7660;
P_0c0c7660: /* original 2cc8, guest PC 0x0c0c7660 */
if(!s->budget--) { s->failed_pc=0x0c0c7660u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0c7662;
P_0c0c7662: /* original 8d0e, guest PC 0x0c0c7662 */
if(!s->budget--) { s->failed_pc=0x0c0c7662u; return 0; }
cond=r[17]&1u;
r[11]=read(ram,r[10]+r[0],4);
if(cond) { goto P_0c0c7682; }
goto P_0c0c7666;
P_0c0c7664: /* original 0bae, guest PC 0x0c0c7664 */
if(!s->budget--) { s->failed_pc=0x0c0c7664u; return 0; }
r[11]=read(ram,r[10]+r[0],4);
goto P_0c0c7666;
P_0c0c7666: /* original 85c6, guest PC 0x0c0c7666 */
if(!s->budget--) { s->failed_pc=0x0c0c7666u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+12,2);
goto P_0c0c7668;
P_0c0c7668: /* original 996f, guest PC 0x0c0c7668 */
if(!s->budget--) { s->failed_pc=0x0c0c7668u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c774au,2);
goto P_0c0c766a;
P_0c0c766a: /* original 6e0d, guest PC 0x0c0c766a */
if(!s->budget--) { s->failed_pc=0x0c0c766au; return 0; }
r[14]=r[0]&65535u;
goto P_0c0c766c;
P_0c0c766c: /* original 4e15, guest PC 0x0c0c766c */
if(!s->budget--) { s->failed_pc=0x0c0c766cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c766e;
P_0c0c766e: /* original 8b05, guest PC 0x0c0c766e */
if(!s->budget--) { s->failed_pc=0x0c0c766eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c767c; }
goto P_0c0c7670;
P_0c0c7670: /* original 6493, guest PC 0x0c0c7670 */
if(!s->budget--) { s->failed_pc=0x0c0c7670u; return 0; }
r[4]=r[9];
goto P_0c0c7672;
P_0c0c7672: /* original 4d0b, guest PC 0x0c0c7672 */
if(!s->budget--) { s->failed_pc=0x0c0c7672u; return 0; }
target=r[13];
r[16]=code_base|0x0c0c7676u;
r[9]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7676u) { target=s->pc; goto dispatch; }
goto P_0c0c7676;
P_0c0c7674: /* original 7901, guest PC 0x0c0c7674 */
if(!s->budget--) { s->failed_pc=0x0c0c7674u; return 0; }
r[9]+=0x00000001u;
goto P_0c0c7676;
P_0c0c7676: /* original 7eff, guest PC 0x0c0c7676 */
if(!s->budget--) { s->failed_pc=0x0c0c7676u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0c7678;
P_0c0c7678: /* original 4e15, guest PC 0x0c0c7678 */
if(!s->budget--) { s->failed_pc=0x0c0c7678u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c767a;
P_0c0c767a: /* original 89f9, guest PC 0x0c0c767a */
if(!s->budget--) { s->failed_pc=0x0c0c767au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7670; }
goto P_0c0c767c;
P_0c0c767c: /* original d338, guest PC 0x0c0c767c */
if(!s->budget--) { s->failed_pc=0x0c0c767cu; return 0; }
r[3]=read(ram,0x0c0c7760u,4);
goto P_0c0c767e;
P_0c0c767e: /* original 430b, guest PC 0x0c0c767e */
if(!s->budget--) { s->failed_pc=0x0c0c767eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7682u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7682u) { target=s->pc; goto dispatch; }
goto P_0c0c7682;
P_0c0c7680: /* original 64c3, guest PC 0x0c0c7680 */
if(!s->budget--) { s->failed_pc=0x0c0c7680u; return 0; }
r[4]=r[12];
goto P_0c0c7682;
P_0c0c7682: /* original 2bb8, guest PC 0x0c0c7682 */
if(!s->budget--) { s->failed_pc=0x0c0c7682u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0c7684;
P_0c0c7684: /* original 890d, guest PC 0x0c0c7684 */
if(!s->budget--) { s->failed_pc=0x0c0c7684u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c76a2; }
goto P_0c0c7686;
P_0c0c7686: /* original 85b6, guest PC 0x0c0c7686 */
if(!s->budget--) { s->failed_pc=0x0c0c7686u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+12,2);
goto P_0c0c7688;
P_0c0c7688: /* original 9c60, guest PC 0x0c0c7688 */
if(!s->budget--) { s->failed_pc=0x0c0c7688u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c774cu,2);
goto P_0c0c768a;
P_0c0c768a: /* original 6e0d, guest PC 0x0c0c768a */
if(!s->budget--) { s->failed_pc=0x0c0c768au; return 0; }
r[14]=r[0]&65535u;
goto P_0c0c768c;
P_0c0c768c: /* original 4e15, guest PC 0x0c0c768c */
if(!s->budget--) { s->failed_pc=0x0c0c768cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c768e;
P_0c0c768e: /* original 8b05, guest PC 0x0c0c768e */
if(!s->budget--) { s->failed_pc=0x0c0c768eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c769c; }
goto P_0c0c7690;
P_0c0c7690: /* original 64c3, guest PC 0x0c0c7690 */
if(!s->budget--) { s->failed_pc=0x0c0c7690u; return 0; }
r[4]=r[12];
goto P_0c0c7692;
P_0c0c7692: /* original 4d0b, guest PC 0x0c0c7692 */
if(!s->budget--) { s->failed_pc=0x0c0c7692u; return 0; }
target=r[13];
r[16]=code_base|0x0c0c7696u;
r[12]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7696u) { target=s->pc; goto dispatch; }
goto P_0c0c7696;
P_0c0c7694: /* original 7c01, guest PC 0x0c0c7694 */
if(!s->budget--) { s->failed_pc=0x0c0c7694u; return 0; }
r[12]+=0x00000001u;
goto P_0c0c7696;
P_0c0c7696: /* original 7eff, guest PC 0x0c0c7696 */
if(!s->budget--) { s->failed_pc=0x0c0c7696u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0c7698;
P_0c0c7698: /* original 4e15, guest PC 0x0c0c7698 */
if(!s->budget--) { s->failed_pc=0x0c0c7698u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c769a;
P_0c0c769a: /* original 89f9, guest PC 0x0c0c769a */
if(!s->budget--) { s->failed_pc=0x0c0c769au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7690; }
goto P_0c0c769c;
P_0c0c769c: /* original d330, guest PC 0x0c0c769c */
if(!s->budget--) { s->failed_pc=0x0c0c769cu; return 0; }
r[3]=read(ram,0x0c0c7760u,4);
goto P_0c0c769e;
P_0c0c769e: /* original 430b, guest PC 0x0c0c769e */
if(!s->budget--) { s->failed_pc=0x0c0c769eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c76a2u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c76a2u) { target=s->pc; goto dispatch; }
goto P_0c0c76a2;
P_0c0c76a0: /* original 64b3, guest PC 0x0c0c76a0 */
if(!s->budget--) { s->failed_pc=0x0c0c76a0u; return 0; }
r[4]=r[11];
goto P_0c0c76a2;
P_0c0c76a2: /* original 9054, guest PC 0x0c0c76a2 */
if(!s->budget--) { s->failed_pc=0x0c0c76a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c774eu,2);
goto P_0c0c76a4;
P_0c0c76a4: /* original e400, guest PC 0x0c0c76a4 */
if(!s->budget--) { s->failed_pc=0x0c0c76a4u; return 0; }
r[4]=0x00000000u;
goto P_0c0c76a6;
P_0c0c76a6: /* original 4f26, guest PC 0x0c0c76a6 */
if(!s->budget--) { s->failed_pc=0x0c0c76a6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c76a8;
P_0c0c76a8: /* original 0a46, guest PC 0x0c0c76a8 */
if(!s->budget--) { s->failed_pc=0x0c0c76a8u; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c0c76aa;
P_0c0c76aa: /* original 70f8, guest PC 0x0c0c76aa */
if(!s->budget--) { s->failed_pc=0x0c0c76aau; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c76ac;
P_0c0c76ac: /* original 0a46, guest PC 0x0c0c76ac */
if(!s->budget--) { s->failed_pc=0x0c0c76acu; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c0c76ae;
P_0c0c76ae: /* original 7004, guest PC 0x0c0c76ae */
if(!s->budget--) { s->failed_pc=0x0c0c76aeu; return 0; }
r[0]+=0x00000004u;
goto P_0c0c76b0;
P_0c0c76b0: /* original 0a46, guest PC 0x0c0c76b0 */
if(!s->budget--) { s->failed_pc=0x0c0c76b0u; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c0c76b2;
P_0c0c76b2: /* original 69f6, guest PC 0x0c0c76b2 */
if(!s->budget--) { s->failed_pc=0x0c0c76b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c76b4;
P_0c0c76b4: /* original 6af6, guest PC 0x0c0c76b4 */
if(!s->budget--) { s->failed_pc=0x0c0c76b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c76b6;
P_0c0c76b6: /* original 6bf6, guest PC 0x0c0c76b6 */
if(!s->budget--) { s->failed_pc=0x0c0c76b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c76b8;
P_0c0c76b8: /* original 6cf6, guest PC 0x0c0c76b8 */
if(!s->budget--) { s->failed_pc=0x0c0c76b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c76ba;
P_0c0c76ba: /* original 6df6, guest PC 0x0c0c76ba */
if(!s->budget--) { s->failed_pc=0x0c0c76bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c76bc;
P_0c0c76bc: /* original 000b, guest PC 0x0c0c76bc */
if(!s->budget--) { s->failed_pc=0x0c0c76bcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c76be: /* original 6ef6, guest PC 0x0c0c76be */
if(!s->budget--) { s->failed_pc=0x0c0c76beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c76c0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
