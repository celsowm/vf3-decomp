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
int vf3_away_batch175_adapter_33(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c0c434cu: goto P_0c0c434c;
case 0x0c0c434eu: goto P_0c0c434e;
case 0x0c0c4350u: goto P_0c0c4350;
case 0x0c0c4352u: goto P_0c0c4352;
case 0x0c0c4354u: goto P_0c0c4354;
case 0x0c0c4356u: goto P_0c0c4356;
case 0x0c0c4358u: goto P_0c0c4358;
case 0x0c0c435au: goto P_0c0c435a;
case 0x0c0c435cu: goto P_0c0c435c;
case 0x0c0c435eu: goto P_0c0c435e;
case 0x0c0c4360u: goto P_0c0c4360;
case 0x0c0c4362u: goto P_0c0c4362;
case 0x0c0c4364u: goto P_0c0c4364;
case 0x0c0c4366u: goto P_0c0c4366;
case 0x0c0c4368u: goto P_0c0c4368;
case 0x0c0c436au: goto P_0c0c436a;
case 0x0c0c436cu: goto P_0c0c436c;
case 0x0c0c436eu: goto P_0c0c436e;
case 0x0c0c4370u: goto P_0c0c4370;
case 0x0c0c4372u: goto P_0c0c4372;
case 0x0c0c4374u: goto P_0c0c4374;
case 0x0c0c4376u: goto P_0c0c4376;
case 0x0c0c4378u: goto P_0c0c4378;
case 0x0c0c437au: goto P_0c0c437a;
case 0x0c0c5c94u: goto P_0c0c5c94;
case 0x0c0c5c96u: goto P_0c0c5c96;
case 0x0c0c5c98u: goto P_0c0c5c98;
case 0x0c0c5c9au: goto P_0c0c5c9a;
case 0x0c0c5c9cu: goto P_0c0c5c9c;
case 0x0c0c5c9eu: goto P_0c0c5c9e;
case 0x0c0c5ca0u: goto P_0c0c5ca0;
case 0x0c0c5ca2u: goto P_0c0c5ca2;
case 0x0c0c5ca4u: goto P_0c0c5ca4;
case 0x0c0c5ca6u: goto P_0c0c5ca6;
case 0x0c0c5ca8u: goto P_0c0c5ca8;
case 0x0c0c5caau: goto P_0c0c5caa;
case 0x0c0c5cacu: goto P_0c0c5cac;
case 0x0c0c5caeu: goto P_0c0c5cae;
case 0x0c0c5cb0u: goto P_0c0c5cb0;
case 0x0c0c5cf4u: goto P_0c0c5cf4;
case 0x0c0c5cf6u: goto P_0c0c5cf6;
case 0x0c0c5cf8u: goto P_0c0c5cf8;
case 0x0c0c5cfau: goto P_0c0c5cfa;
case 0x0c0c5cfcu: goto P_0c0c5cfc;
case 0x0c0c5cfeu: goto P_0c0c5cfe;
case 0x0c0c5d00u: goto P_0c0c5d00;
case 0x0c0c5d02u: goto P_0c0c5d02;
case 0x0c0c5d04u: goto P_0c0c5d04;
case 0x0c0c5d06u: goto P_0c0c5d06;
case 0x0c0c5d08u: goto P_0c0c5d08;
case 0x0c0c5d0au: goto P_0c0c5d0a;
case 0x0c0c5d0cu: goto P_0c0c5d0c;
case 0x0c0c5d0eu: goto P_0c0c5d0e;
case 0x0c0c5d10u: goto P_0c0c5d10;
case 0x0c0c5d12u: goto P_0c0c5d12;
case 0x0c0c5d14u: goto P_0c0c5d14;
case 0x0c0c5d16u: goto P_0c0c5d16;
case 0x0c0c5d18u: goto P_0c0c5d18;
case 0x0c0c5d1au: goto P_0c0c5d1a;
case 0x0c0c5d1cu: goto P_0c0c5d1c;
case 0x0c0c5d1eu: goto P_0c0c5d1e;
case 0x0c0c5d20u: goto P_0c0c5d20;
case 0x0c0c5d22u: goto P_0c0c5d22;
case 0x0c0c5d24u: goto P_0c0c5d24;
case 0x0c0c5d26u: goto P_0c0c5d26;
case 0x0c0c5d28u: goto P_0c0c5d28;
case 0x0c0c5d2au: goto P_0c0c5d2a;
case 0x0c0c5d2cu: goto P_0c0c5d2c;
case 0x0c0c5d2eu: goto P_0c0c5d2e;
case 0x0c0c5d30u: goto P_0c0c5d30;
case 0x0c0c5d32u: goto P_0c0c5d32;
case 0x0c0c5d34u: goto P_0c0c5d34;
case 0x0c0c5d36u: goto P_0c0c5d36;
case 0x0c0c5d38u: goto P_0c0c5d38;
case 0x0c0c5d3au: goto P_0c0c5d3a;
case 0x0c0c5d3cu: goto P_0c0c5d3c;
case 0x0c0c5d3eu: goto P_0c0c5d3e;
case 0x0c0c5d40u: goto P_0c0c5d40;
case 0x0c0c5d42u: goto P_0c0c5d42;
case 0x0c0c5d44u: goto P_0c0c5d44;
case 0x0c0c5d46u: goto P_0c0c5d46;
case 0x0c0c5d48u: goto P_0c0c5d48;
case 0x0c0c5d4au: goto P_0c0c5d4a;
case 0x0c0c5d4cu: goto P_0c0c5d4c;
case 0x0c0c5d4eu: goto P_0c0c5d4e;
case 0x0c0c5d50u: goto P_0c0c5d50;
case 0x0c0c5d52u: goto P_0c0c5d52;
case 0x0c0c5d54u: goto P_0c0c5d54;
case 0x0c0c5d56u: goto P_0c0c5d56;
case 0x0c0c5d58u: goto P_0c0c5d58;
case 0x0c0c5d5au: goto P_0c0c5d5a;
case 0x0c0c5d5cu: goto P_0c0c5d5c;
case 0x0c0c5d5eu: goto P_0c0c5d5e;
case 0x0c0c5d60u: goto P_0c0c5d60;
case 0x0c0c5d62u: goto P_0c0c5d62;
case 0x0c0c5d64u: goto P_0c0c5d64;
case 0x0c0c5d66u: goto P_0c0c5d66;
case 0x0c0c5d68u: goto P_0c0c5d68;
case 0x0c0c5d6au: goto P_0c0c5d6a;
case 0x0c0c5d6cu: goto P_0c0c5d6c;
case 0x0c0c5d6eu: goto P_0c0c5d6e;
case 0x0c0c5d70u: goto P_0c0c5d70;
case 0x0c0c5d72u: goto P_0c0c5d72;
case 0x0c0c5d74u: goto P_0c0c5d74;
case 0x0c0c5d76u: goto P_0c0c5d76;
case 0x0c0c5d78u: goto P_0c0c5d78;
case 0x0c0c5d7au: goto P_0c0c5d7a;
case 0x0c0c5d7cu: goto P_0c0c5d7c;
case 0x0c0c5d7eu: goto P_0c0c5d7e;
case 0x0c0c5d80u: goto P_0c0c5d80;
case 0x0c0c5d82u: goto P_0c0c5d82;
case 0x0c0c5d84u: goto P_0c0c5d84;
case 0x0c0c5d86u: goto P_0c0c5d86;
case 0x0c0c5d88u: goto P_0c0c5d88;
case 0x0c0c5d8au: goto P_0c0c5d8a;
case 0x0c0c5d8cu: goto P_0c0c5d8c;
case 0x0c0c5d8eu: goto P_0c0c5d8e;
case 0x0c0c5d90u: goto P_0c0c5d90;
case 0x0c0c5d92u: goto P_0c0c5d92;
case 0x0c0c5d94u: goto P_0c0c5d94;
case 0x0c0c5d96u: goto P_0c0c5d96;
case 0x0c0c5d98u: goto P_0c0c5d98;
case 0x0c0c5d9au: goto P_0c0c5d9a;
case 0x0c0c5d9cu: goto P_0c0c5d9c;
case 0x0c0c5d9eu: goto P_0c0c5d9e;
case 0x0c0c5da0u: goto P_0c0c5da0;
case 0x0c0c5da2u: goto P_0c0c5da2;
case 0x0c0c5da4u: goto P_0c0c5da4;
case 0x0c0c5da6u: goto P_0c0c5da6;
case 0x0c0c5da8u: goto P_0c0c5da8;
case 0x0c0c5daau: goto P_0c0c5daa;
case 0x0c0c5dacu: goto P_0c0c5dac;
case 0x0c0c5daeu: goto P_0c0c5dae;
case 0x0c0c5db0u: goto P_0c0c5db0;
case 0x0c0c5db2u: goto P_0c0c5db2;
case 0x0c0c5db4u: goto P_0c0c5db4;
case 0x0c0c5db6u: goto P_0c0c5db6;
case 0x0c0c5db8u: goto P_0c0c5db8;
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
P_0c0c434c: /* original d740, guest PC 0x0c0c434c */
if(!s->budget--) { s->failed_pc=0x0c0c434cu; return 0; }
r[7]=read(ram,0x0c0c4450u,4);
goto P_0c0c434e;
P_0c0c434e: /* original e302, guest PC 0x0c0c434e */
if(!s->budget--) { s->failed_pc=0x0c0c434eu; return 0; }
r[3]=0x00000002u;
goto P_0c0c4350;
P_0c0c4350: /* original d53e, guest PC 0x0c0c4350 */
if(!s->budget--) { s->failed_pc=0x0c0c4350u; return 0; }
r[5]=read(ram,0x0c0c444cu,4);
goto P_0c0c4352;
P_0c0c4352: /* original 567a, guest PC 0x0c0c4352 */
if(!s->budget--) { s->failed_pc=0x0c0c4352u; return 0; }
r[6]=read(ram,r[7]+40,4);
goto P_0c0c4354;
P_0c0c4354: /* original 6662, guest PC 0x0c0c4354 */
if(!s->budget--) { s->failed_pc=0x0c0c4354u; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c0c4356;
P_0c0c4356: /* original 2368, guest PC 0x0c0c4356 */
if(!s->budget--) { s->failed_pc=0x0c0c4356u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0c4358;
P_0c0c4358: /* original 8f03, guest PC 0x0c0c4358 */
if(!s->budget--) { s->failed_pc=0x0c0c4358u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(!cond) { goto P_0c0c4362; }
goto P_0c0c435c;
P_0c0c435a: /* original e400, guest PC 0x0c0c435a */
if(!s->budget--) { s->failed_pc=0x0c0c435au; return 0; }
r[4]=0x00000000u;
goto P_0c0c435c;
P_0c0c435c: /* original e204, guest PC 0x0c0c435c */
if(!s->budget--) { s->failed_pc=0x0c0c435cu; return 0; }
r[2]=0x00000004u;
goto P_0c0c435e;
P_0c0c435e: /* original 2628, guest PC 0x0c0c435e */
if(!s->budget--) { s->failed_pc=0x0c0c435eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c0c4360;
P_0c0c4360: /* original 8900, guest PC 0x0c0c4360 */
if(!s->budget--) { s->failed_pc=0x0c0c4360u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4364; }
goto P_0c0c4362;
P_0c0c4362: /* original e401, guest PC 0x0c0c4362 */
if(!s->budget--) { s->failed_pc=0x0c0c4362u; return 0; }
r[4]=0x00000001u;
goto P_0c0c4364;
P_0c0c4364: /* original 567b, guest PC 0x0c0c4364 */
if(!s->budget--) { s->failed_pc=0x0c0c4364u; return 0; }
r[6]=read(ram,r[7]+44,4);
goto P_0c0c4366;
P_0c0c4366: /* original e302, guest PC 0x0c0c4366 */
if(!s->budget--) { s->failed_pc=0x0c0c4366u; return 0; }
r[3]=0x00000002u;
goto P_0c0c4368;
P_0c0c4368: /* original 6662, guest PC 0x0c0c4368 */
if(!s->budget--) { s->failed_pc=0x0c0c4368u; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c0c436a;
P_0c0c436a: /* original 2368, guest PC 0x0c0c436a */
if(!s->budget--) { s->failed_pc=0x0c0c436au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0c436c;
P_0c0c436c: /* original 8f03, guest PC 0x0c0c436c */
if(!s->budget--) { s->failed_pc=0x0c0c436cu; return 0; }
cond=r[17]&1u;
r[0]=0x00000029u;
if(!cond) { goto P_0c0c4376; }
goto P_0c0c4370;
P_0c0c436e: /* original e029, guest PC 0x0c0c436e */
if(!s->budget--) { s->failed_pc=0x0c0c436eu; return 0; }
r[0]=0x00000029u;
goto P_0c0c4370;
P_0c0c4370: /* original e204, guest PC 0x0c0c4370 */
if(!s->budget--) { s->failed_pc=0x0c0c4370u; return 0; }
r[2]=0x00000004u;
goto P_0c0c4372;
P_0c0c4372: /* original 2628, guest PC 0x0c0c4372 */
if(!s->budget--) { s->failed_pc=0x0c0c4372u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c0c4374;
P_0c0c4374: /* original 8900, guest PC 0x0c0c4374 */
if(!s->budget--) { s->failed_pc=0x0c0c4374u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4378; }
goto P_0c0c4376;
P_0c0c4376: /* original 7402, guest PC 0x0c0c4376 */
if(!s->budget--) { s->failed_pc=0x0c0c4376u; return 0; }
r[4]+=0x00000002u;
goto P_0c0c4378;
P_0c0c4378: /* original 000b, guest PC 0x0c0c4378 */
if(!s->budget--) { s->failed_pc=0x0c0c4378u; return 0; }
target=r[16];
write(ram,r[5]+r[0],r[4],1);
s->pc=target; return ram->oob==0;
P_0c0c437a: /* original 0544, guest PC 0x0c0c437a */
if(!s->budget--) { s->failed_pc=0x0c0c437au; return 0; }
write(ram,r[5]+r[0],r[4],1);
if(!vf3_matrix_family(0x0c0c437cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c437cu; return 0; } return 1;
P_0c0c5c94: /* original 2fe6, guest PC 0x0c0c5c94 */
if(!s->budget--) { s->failed_pc=0x0c0c5c94u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5c96;
P_0c0c5c96: /* original 6043, guest PC 0x0c0c5c96 */
if(!s->budget--) { s->failed_pc=0x0c0c5c96u; return 0; }
r[0]=r[4];
goto P_0c0c5c98;
P_0c0c5c98: /* original 2fd6, guest PC 0x0c0c5c98 */
if(!s->budget--) { s->failed_pc=0x0c0c5c98u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5c9a;
P_0c0c5c9a: /* original 88ff, guest PC 0x0c0c5c9a */
if(!s->budget--) { s->failed_pc=0x0c0c5c9au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c5c9c;
P_0c0c5c9c: /* original 2fc6, guest PC 0x0c0c5c9c */
if(!s->budget--) { s->failed_pc=0x0c0c5c9cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5c9e;
P_0c0c5c9e: /* original 6d43, guest PC 0x0c0c5c9e */
if(!s->budget--) { s->failed_pc=0x0c0c5c9eu; return 0; }
r[13]=r[4];
goto P_0c0c5ca0;
P_0c0c5ca0: /* original 2fb6, guest PC 0x0c0c5ca0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5ca2;
P_0c0c5ca2: /* original 4f22, guest PC 0x0c0c5ca2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5ca4;
P_0c0c5ca4: /* original 8d03, guest PC 0x0c0c5ca4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca4u; return 0; }
cond=r[17]&1u;
r[11]=r[5];
if(cond) { goto P_0c0c5cae; }
goto P_0c0c5ca8;
P_0c0c5ca6: /* original 6b53, guest PC 0x0c0c5ca6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca6u; return 0; }
r[11]=r[5];
goto P_0c0c5ca8;
P_0c0c5ca8: /* original 930d, guest PC 0x0c0c5ca8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5cc6u,2);
goto P_0c0c5caa;
P_0c0c5caa: /* original 3d30, guest PC 0x0c0c5caa */
if(!s->budget--) { s->failed_pc=0x0c0c5caau; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0c5cac;
P_0c0c5cac: /* original 8b22, guest PC 0x0c0c5cac */
if(!s->budget--) { s->failed_pc=0x0c0c5cacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5cf4; }
goto P_0c0c5cae;
P_0c0c5cae: /* original a064, guest PC 0x0c0c5cae */
if(!s->budget--) { s->failed_pc=0x0c0c5caeu; return 0; }
r[0]=0xffffffffu;
goto P_0c0c5d7a;
P_0c0c5cb0: /* original e0ff, guest PC 0x0c0c5cb0 */
if(!s->budget--) { s->failed_pc=0x0c0c5cb0u; return 0; }
r[0]=0xffffffffu;
if(!vf3_matrix_family(0x0c0c5cb2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5cb2u; return 0; } return 1;
P_0c0c5cf4: /* original 9381, guest PC 0x0c0c5cf4 */
if(!s->budget--) { s->failed_pc=0x0c0c5cf4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5dfau,2);
goto P_0c0c5cf6;
P_0c0c5cf6: /* original de43, guest PC 0x0c0c5cf6 */
if(!s->budget--) { s->failed_pc=0x0c0c5cf6u; return 0; }
r[14]=read(ram,0x0c0c5e04u,4);
goto P_0c0c5cf8;
P_0c0c5cf8: /* original 3d30, guest PC 0x0c0c5cf8 */
if(!s->budget--) { s->failed_pc=0x0c0c5cf8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0c5cfa;
P_0c0c5cfa: /* original 8905, guest PC 0x0c0c5cfa */
if(!s->budget--) { s->failed_pc=0x0c0c5cfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5d08; }
goto P_0c0c5cfc;
P_0c0c5cfc: /* original 917e, guest PC 0x0c0c5cfc */
if(!s->budget--) { s->failed_pc=0x0c0c5cfcu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5dfcu,2);
goto P_0c0c5cfe;
P_0c0c5cfe: /* original 3d10, guest PC 0x0c0c5cfe */
if(!s->budget--) { s->failed_pc=0x0c0c5cfeu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c0c5d00;
P_0c0c5d00: /* original 8902, guest PC 0x0c0c5d00 */
if(!s->budget--) { s->failed_pc=0x0c0c5d00u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5d08; }
goto P_0c0c5d02;
P_0c0c5d02: /* original 907c, guest PC 0x0c0c5d02 */
if(!s->budget--) { s->failed_pc=0x0c0c5d02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5dfeu,2);
goto P_0c0c5d04;
P_0c0c5d04: /* original 3d00, guest PC 0x0c0c5d04 */
if(!s->budget--) { s->failed_pc=0x0c0c5d04u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[0])!=0);
goto P_0c0c5d06;
P_0c0c5d06: /* original 8b07, guest PC 0x0c0c5d06 */
if(!s->budget--) { s->failed_pc=0x0c0c5d06u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5d18; }
goto P_0c0c5d08;
P_0c0c5d08: /* original 65d3, guest PC 0x0c0c5d08 */
if(!s->budget--) { s->failed_pc=0x0c0c5d08u; return 0; }
r[5]=r[13];
goto P_0c0c5d0a;
P_0c0c5d0a: /* original 66b3, guest PC 0x0c0c5d0a */
if(!s->budget--) { s->failed_pc=0x0c0c5d0au; return 0; }
r[6]=r[11];
goto P_0c0c5d0c;
P_0c0c5d0c: /* original 4e0b, guest PC 0x0c0c5d0c */
if(!s->budget--) { s->failed_pc=0x0c0c5d0cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d10u;
r[4]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d10u) { target=s->pc; goto dispatch; }
goto P_0c0c5d10;
P_0c0c5d0e: /* original e404, guest PC 0x0c0c5d0e */
if(!s->budget--) { s->failed_pc=0x0c0c5d0eu; return 0; }
r[4]=0x00000004u;
goto P_0c0c5d10;
P_0c0c5d10: /* original 65d3, guest PC 0x0c0c5d10 */
if(!s->budget--) { s->failed_pc=0x0c0c5d10u; return 0; }
r[5]=r[13];
goto P_0c0c5d12;
P_0c0c5d12: /* original 66b3, guest PC 0x0c0c5d12 */
if(!s->budget--) { s->failed_pc=0x0c0c5d12u; return 0; }
r[6]=r[11];
goto P_0c0c5d14;
P_0c0c5d14: /* original a02f, guest PC 0x0c0c5d14 */
if(!s->budget--) { s->failed_pc=0x0c0c5d14u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d76;
P_0c0c5d16: /* original e403, guest PC 0x0c0c5d16 */
if(!s->budget--) { s->failed_pc=0x0c0c5d16u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d18;
P_0c0c5d18: /* original d33c, guest PC 0x0c0c5d18 */
if(!s->budget--) { s->failed_pc=0x0c0c5d18u; return 0; }
r[3]=read(ram,0x0c0c5e0cu,4);
goto P_0c0c5d1a;
P_0c0c5d1a: /* original dc3b, guest PC 0x0c0c5d1a */
if(!s->budget--) { s->failed_pc=0x0c0c5d1au; return 0; }
r[12]=read(ram,0x0c0c5e08u,4);
goto P_0c0c5d1c;
P_0c0c5d1c: /* original 3d30, guest PC 0x0c0c5d1c */
if(!s->budget--) { s->failed_pc=0x0c0c5d1cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0c5d1e;
P_0c0c5d1e: /* original 8b0b, guest PC 0x0c0c5d1e */
if(!s->budget--) { s->failed_pc=0x0c0c5d1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5d38; }
goto P_0c0c5d20;
P_0c0c5d20: /* original 65c3, guest PC 0x0c0c5d20 */
if(!s->budget--) { s->failed_pc=0x0c0c5d20u; return 0; }
r[5]=r[12];
goto P_0c0c5d22;
P_0c0c5d22: /* original e600, guest PC 0x0c0c5d22 */
if(!s->budget--) { s->failed_pc=0x0c0c5d22u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d24;
P_0c0c5d24: /* original 4e0b, guest PC 0x0c0c5d24 */
if(!s->budget--) { s->failed_pc=0x0c0c5d24u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d28u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d28u) { target=s->pc; goto dispatch; }
goto P_0c0c5d28;
P_0c0c5d26: /* original e401, guest PC 0x0c0c5d26 */
if(!s->budget--) { s->failed_pc=0x0c0c5d26u; return 0; }
r[4]=0x00000001u;
goto P_0c0c5d28;
P_0c0c5d28: /* original 65c3, guest PC 0x0c0c5d28 */
if(!s->budget--) { s->failed_pc=0x0c0c5d28u; return 0; }
r[5]=r[12];
goto P_0c0c5d2a;
P_0c0c5d2a: /* original e600, guest PC 0x0c0c5d2a */
if(!s->budget--) { s->failed_pc=0x0c0c5d2au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d2c;
P_0c0c5d2c: /* original 4e0b, guest PC 0x0c0c5d2c */
if(!s->budget--) { s->failed_pc=0x0c0c5d2cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d30u;
r[4]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d30u) { target=s->pc; goto dispatch; }
goto P_0c0c5d30;
P_0c0c5d2e: /* original e402, guest PC 0x0c0c5d2e */
if(!s->budget--) { s->failed_pc=0x0c0c5d2eu; return 0; }
r[4]=0x00000002u;
goto P_0c0c5d30;
P_0c0c5d30: /* original 65c3, guest PC 0x0c0c5d30 */
if(!s->budget--) { s->failed_pc=0x0c0c5d30u; return 0; }
r[5]=r[12];
goto P_0c0c5d32;
P_0c0c5d32: /* original e600, guest PC 0x0c0c5d32 */
if(!s->budget--) { s->failed_pc=0x0c0c5d32u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d34;
P_0c0c5d34: /* original a00a, guest PC 0x0c0c5d34 */
if(!s->budget--) { s->failed_pc=0x0c0c5d34u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d4c;
P_0c0c5d36: /* original e403, guest PC 0x0c0c5d36 */
if(!s->budget--) { s->failed_pc=0x0c0c5d36u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d38;
P_0c0c5d38: /* original d135, guest PC 0x0c0c5d38 */
if(!s->budget--) { s->failed_pc=0x0c0c5d38u; return 0; }
r[1]=read(ram,0x0c0c5e10u,4);
goto P_0c0c5d3a;
P_0c0c5d3a: /* original 3d10, guest PC 0x0c0c5d3a */
if(!s->budget--) { s->failed_pc=0x0c0c5d3au; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c0c5d3c;
P_0c0c5d3c: /* original 8b18, guest PC 0x0c0c5d3c */
if(!s->budget--) { s->failed_pc=0x0c0c5d3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5d70; }
goto P_0c0c5d3e;
P_0c0c5d3e: /* original 65c3, guest PC 0x0c0c5d3e */
if(!s->budget--) { s->failed_pc=0x0c0c5d3eu; return 0; }
r[5]=r[12];
goto P_0c0c5d40;
P_0c0c5d40: /* original e600, guest PC 0x0c0c5d40 */
if(!s->budget--) { s->failed_pc=0x0c0c5d40u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d42;
P_0c0c5d42: /* original 4e0b, guest PC 0x0c0c5d42 */
if(!s->budget--) { s->failed_pc=0x0c0c5d42u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d46u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d46u) { target=s->pc; goto dispatch; }
goto P_0c0c5d46;
P_0c0c5d44: /* original e401, guest PC 0x0c0c5d44 */
if(!s->budget--) { s->failed_pc=0x0c0c5d44u; return 0; }
r[4]=0x00000001u;
goto P_0c0c5d46;
P_0c0c5d46: /* original e402, guest PC 0x0c0c5d46 */
if(!s->budget--) { s->failed_pc=0x0c0c5d46u; return 0; }
r[4]=0x00000002u;
goto P_0c0c5d48;
P_0c0c5d48: /* original 65c3, guest PC 0x0c0c5d48 */
if(!s->budget--) { s->failed_pc=0x0c0c5d48u; return 0; }
r[5]=r[12];
goto P_0c0c5d4a;
P_0c0c5d4a: /* original e600, guest PC 0x0c0c5d4a */
if(!s->budget--) { s->failed_pc=0x0c0c5d4au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d4c;
P_0c0c5d4c: /* original 4e0b, guest PC 0x0c0c5d4c */
if(!s->budget--) { s->failed_pc=0x0c0c5d4cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d50u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d50u) { target=s->pc; goto dispatch; }
goto P_0c0c5d50;
P_0c0c5d4e: /* original 0009, guest PC 0x0c0c5d4e */
if(!s->budget--) { s->failed_pc=0x0c0c5d4eu; return 0; }
goto P_0c0c5d50;
P_0c0c5d50: /* original 65c3, guest PC 0x0c0c5d50 */
if(!s->budget--) { s->failed_pc=0x0c0c5d50u; return 0; }
r[5]=r[12];
goto P_0c0c5d52;
P_0c0c5d52: /* original e600, guest PC 0x0c0c5d52 */
if(!s->budget--) { s->failed_pc=0x0c0c5d52u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d54;
P_0c0c5d54: /* original 4e0b, guest PC 0x0c0c5d54 */
if(!s->budget--) { s->failed_pc=0x0c0c5d54u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d58u;
r[4]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d58u) { target=s->pc; goto dispatch; }
goto P_0c0c5d58;
P_0c0c5d56: /* original e404, guest PC 0x0c0c5d56 */
if(!s->budget--) { s->failed_pc=0x0c0c5d56u; return 0; }
r[4]=0x00000004u;
goto P_0c0c5d58;
P_0c0c5d58: /* original 65c3, guest PC 0x0c0c5d58 */
if(!s->budget--) { s->failed_pc=0x0c0c5d58u; return 0; }
r[5]=r[12];
goto P_0c0c5d5a;
P_0c0c5d5a: /* original e600, guest PC 0x0c0c5d5a */
if(!s->budget--) { s->failed_pc=0x0c0c5d5au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d5c;
P_0c0c5d5c: /* original 4e0b, guest PC 0x0c0c5d5c */
if(!s->budget--) { s->failed_pc=0x0c0c5d5cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d60u;
r[4]=0x00000005u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d60u) { target=s->pc; goto dispatch; }
goto P_0c0c5d60;
P_0c0c5d5e: /* original e405, guest PC 0x0c0c5d5e */
if(!s->budget--) { s->failed_pc=0x0c0c5d5eu; return 0; }
r[4]=0x00000005u;
goto P_0c0c5d60;
P_0c0c5d60: /* original 65c3, guest PC 0x0c0c5d60 */
if(!s->budget--) { s->failed_pc=0x0c0c5d60u; return 0; }
r[5]=r[12];
goto P_0c0c5d62;
P_0c0c5d62: /* original e600, guest PC 0x0c0c5d62 */
if(!s->budget--) { s->failed_pc=0x0c0c5d62u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d64;
P_0c0c5d64: /* original 4e0b, guest PC 0x0c0c5d64 */
if(!s->budget--) { s->failed_pc=0x0c0c5d64u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d68u;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d68u) { target=s->pc; goto dispatch; }
goto P_0c0c5d68;
P_0c0c5d66: /* original e406, guest PC 0x0c0c5d66 */
if(!s->budget--) { s->failed_pc=0x0c0c5d66u; return 0; }
r[4]=0x00000006u;
goto P_0c0c5d68;
P_0c0c5d68: /* original 65c3, guest PC 0x0c0c5d68 */
if(!s->budget--) { s->failed_pc=0x0c0c5d68u; return 0; }
r[5]=r[12];
goto P_0c0c5d6a;
P_0c0c5d6a: /* original e600, guest PC 0x0c0c5d6a */
if(!s->budget--) { s->failed_pc=0x0c0c5d6au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d6c;
P_0c0c5d6c: /* original a003, guest PC 0x0c0c5d6c */
if(!s->budget--) { s->failed_pc=0x0c0c5d6cu; return 0; }
r[4]=0x00000007u;
goto P_0c0c5d76;
P_0c0c5d6e: /* original e407, guest PC 0x0c0c5d6e */
if(!s->budget--) { s->failed_pc=0x0c0c5d6eu; return 0; }
r[4]=0x00000007u;
goto P_0c0c5d70;
P_0c0c5d70: /* original e400, guest PC 0x0c0c5d70 */
if(!s->budget--) { s->failed_pc=0x0c0c5d70u; return 0; }
r[4]=0x00000000u;
goto P_0c0c5d72;
P_0c0c5d72: /* original 65d3, guest PC 0x0c0c5d72 */
if(!s->budget--) { s->failed_pc=0x0c0c5d72u; return 0; }
r[5]=r[13];
goto P_0c0c5d74;
P_0c0c5d74: /* original 66b3, guest PC 0x0c0c5d74 */
if(!s->budget--) { s->failed_pc=0x0c0c5d74u; return 0; }
r[6]=r[11];
goto P_0c0c5d76;
P_0c0c5d76: /* original 4e0b, guest PC 0x0c0c5d76 */
if(!s->budget--) { s->failed_pc=0x0c0c5d76u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d7au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d7au) { target=s->pc; goto dispatch; }
goto P_0c0c5d7a;
P_0c0c5d78: /* original 0009, guest PC 0x0c0c5d78 */
if(!s->budget--) { s->failed_pc=0x0c0c5d78u; return 0; }
goto P_0c0c5d7a;
P_0c0c5d7a: /* original 4f26, guest PC 0x0c0c5d7a */
if(!s->budget--) { s->failed_pc=0x0c0c5d7au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5d7c;
P_0c0c5d7c: /* original 6bf6, guest PC 0x0c0c5d7c */
if(!s->budget--) { s->failed_pc=0x0c0c5d7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c5d7e;
P_0c0c5d7e: /* original 6cf6, guest PC 0x0c0c5d7e */
if(!s->budget--) { s->failed_pc=0x0c0c5d7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c5d80;
P_0c0c5d80: /* original 6df6, guest PC 0x0c0c5d80 */
if(!s->budget--) { s->failed_pc=0x0c0c5d80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c5d82;
P_0c0c5d82: /* original 000b, guest PC 0x0c0c5d82 */
if(!s->budget--) { s->failed_pc=0x0c0c5d82u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5d84: /* original 6ef6, guest PC 0x0c0c5d84 */
if(!s->budget--) { s->failed_pc=0x0c0c5d84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c5d86;
P_0c0c5d86: /* original 4f22, guest PC 0x0c0c5d86 */
if(!s->budget--) { s->failed_pc=0x0c0c5d86u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5d88;
P_0c0c5d88: /* original 7ff8, guest PC 0x0c0c5d88 */
if(!s->budget--) { s->failed_pc=0x0c0c5d88u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c5d8a;
P_0c0c5d8a: /* original 2f42, guest PC 0x0c0c5d8a */
if(!s->budget--) { s->failed_pc=0x0c0c5d8au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c5d8c;
P_0c0c5d8c: /* original d421, guest PC 0x0c0c5d8c */
if(!s->budget--) { s->failed_pc=0x0c0c5d8cu; return 0; }
r[4]=read(ram,0x0c0c5e14u,4);
goto P_0c0c5d8e;
P_0c0c5d8e: /* original d322, guest PC 0x0c0c5d8e */
if(!s->budget--) { s->failed_pc=0x0c0c5d8eu; return 0; }
r[3]=read(ram,0x0c0c5e18u,4);
goto P_0c0c5d90;
P_0c0c5d90: /* original 1f31, guest PC 0x0c0c5d90 */
if(!s->budget--) { s->failed_pc=0x0c0c5d90u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c5d92;
P_0c0c5d92: /* original 8448, guest PC 0x0c0c5d92 */
if(!s->budget--) { s->failed_pc=0x0c0c5d92u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c0c5d94;
P_0c0c5d94: /* original 600c, guest PC 0x0c0c5d94 */
if(!s->budget--) { s->failed_pc=0x0c0c5d94u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c5d96;
P_0c0c5d96: /* original 8803, guest PC 0x0c0c5d96 */
if(!s->budget--) { s->failed_pc=0x0c0c5d96u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c5d98;
P_0c0c5d98: /* original 8f07, guest PC 0x0c0c5d98 */
if(!s->budget--) { s->failed_pc=0x0c0c5d98u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c0c5daa; }
goto P_0c0c5d9c;
P_0c0c5d9a: /* original 6403, guest PC 0x0c0c5d9a */
if(!s->budget--) { s->failed_pc=0x0c0c5d9au; return 0; }
r[4]=r[0];
goto P_0c0c5d9c;
P_0c0c5d9c: /* original d31f, guest PC 0x0c0c5d9c */
if(!s->budget--) { s->failed_pc=0x0c0c5d9cu; return 0; }
r[3]=read(ram,0x0c0c5e1cu,4);
goto P_0c0c5d9e;
P_0c0c5d9e: /* original 54f1, guest PC 0x0c0c5d9e */
if(!s->budget--) { s->failed_pc=0x0c0c5d9eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c5da0;
P_0c0c5da0: /* original 430b, guest PC 0x0c0c5da0 */
if(!s->budget--) { s->failed_pc=0x0c0c5da0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5da4u;
r[4]+=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5da4u) { target=s->pc; goto dispatch; }
goto P_0c0c5da4;
P_0c0c5da2: /* original 7403, guest PC 0x0c0c5da2 */
if(!s->budget--) { s->failed_pc=0x0c0c5da2u; return 0; }
r[4]+=0x00000003u;
goto P_0c0c5da4;
P_0c0c5da4: /* original 640c, guest PC 0x0c0c5da4 */
if(!s->budget--) { s->failed_pc=0x0c0c5da4u; return 0; }
r[4]=r[0]&255u;
goto P_0c0c5da6;
P_0c0c5da6: /* original 2448, guest PC 0x0c0c5da6 */
if(!s->budget--) { s->failed_pc=0x0c0c5da6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c5da8;
P_0c0c5da8: /* original 8b03, guest PC 0x0c0c5da8 */
if(!s->budget--) { s->failed_pc=0x0c0c5da8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5db2; }
goto P_0c0c5daa;
P_0c0c5daa: /* original 64f2, guest PC 0x0c0c5daa */
if(!s->budget--) { s->failed_pc=0x0c0c5daau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c5dac;
P_0c0c5dac: /* original 7f08, guest PC 0x0c0c5dac */
if(!s->budget--) { s->failed_pc=0x0c0c5dacu; return 0; }
r[15]+=0x00000008u;
goto P_0c0c5dae;
P_0c0c5dae: /* original a004, guest PC 0x0c0c5dae */
if(!s->budget--) { s->failed_pc=0x0c0c5daeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0c5dbau,s,ram);
P_0c0c5db0: /* original 4f26, guest PC 0x0c0c5db0 */
if(!s->budget--) { s->failed_pc=0x0c0c5db0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5db2;
P_0c0c5db2: /* original 7f08, guest PC 0x0c0c5db2 */
if(!s->budget--) { s->failed_pc=0x0c0c5db2u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c5db4;
P_0c0c5db4: /* original 4f26, guest PC 0x0c0c5db4 */
if(!s->budget--) { s->failed_pc=0x0c0c5db4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5db6;
P_0c0c5db6: /* original 000b, guest PC 0x0c0c5db6 */
if(!s->budget--) { s->failed_pc=0x0c0c5db6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c5db8: /* original 0009, guest PC 0x0c0c5db8 */
if(!s->budget--) { s->failed_pc=0x0c0c5db8u; return 0; }
return vf3_matrix_family(0x0c0c5dbau,s,ram);
unsupported: s->failed_pc=target; return 0;
}
