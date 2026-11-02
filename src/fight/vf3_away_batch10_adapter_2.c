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
int vf3_away_batch10_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03c200u: goto P_0c03c200;
case 0x0c03c202u: goto P_0c03c202;
case 0x0c03c204u: goto P_0c03c204;
case 0x0c03c206u: goto P_0c03c206;
case 0x0c03c208u: goto P_0c03c208;
case 0x0c03c5b0u: goto P_0c03c5b0;
case 0x0c03c5b2u: goto P_0c03c5b2;
case 0x0c03c5b4u: goto P_0c03c5b4;
case 0x0c03c5b6u: goto P_0c03c5b6;
case 0x0c03c5b8u: goto P_0c03c5b8;
case 0x0c03c5bau: goto P_0c03c5ba;
case 0x0c03c5bcu: goto P_0c03c5bc;
case 0x0c03c5beu: goto P_0c03c5be;
case 0x0c03c5c0u: goto P_0c03c5c0;
case 0x0c03c5c2u: goto P_0c03c5c2;
case 0x0c03c5c4u: goto P_0c03c5c4;
case 0x0c03c5c6u: goto P_0c03c5c6;
case 0x0c03c5c8u: goto P_0c03c5c8;
case 0x0c03c5cau: goto P_0c03c5ca;
case 0x0c03c5ccu: goto P_0c03c5cc;
case 0x0c03c5ceu: goto P_0c03c5ce;
case 0x0c03c5d0u: goto P_0c03c5d0;
case 0x0c03c5d2u: goto P_0c03c5d2;
case 0x0c03c5d4u: goto P_0c03c5d4;
case 0x0c03c5d6u: goto P_0c03c5d6;
case 0x0c03c5d8u: goto P_0c03c5d8;
case 0x0c03c5dau: goto P_0c03c5da;
case 0x0c03c5dcu: goto P_0c03c5dc;
case 0x0c03c5deu: goto P_0c03c5de;
case 0x0c03c5e0u: goto P_0c03c5e0;
case 0x0c03c5e2u: goto P_0c03c5e2;
case 0x0c03c5e4u: goto P_0c03c5e4;
case 0x0c03c5e6u: goto P_0c03c5e6;
case 0x0c03c5e8u: goto P_0c03c5e8;
case 0x0c03c5eau: goto P_0c03c5ea;
case 0x0c03cb70u: goto P_0c03cb70;
case 0x0c03cb72u: goto P_0c03cb72;
case 0x0c03cb74u: goto P_0c03cb74;
case 0x0c03cb76u: goto P_0c03cb76;
case 0x0c03cb78u: goto P_0c03cb78;
case 0x0c03cb7au: goto P_0c03cb7a;
case 0x0c03cb7cu: goto P_0c03cb7c;
case 0x0c03cb7eu: goto P_0c03cb7e;
case 0x0c03cb80u: goto P_0c03cb80;
case 0x0c03cb82u: goto P_0c03cb82;
case 0x0c03cb84u: goto P_0c03cb84;
case 0x0c03cb86u: goto P_0c03cb86;
case 0x0c03cb88u: goto P_0c03cb88;
case 0x0c03cb8au: goto P_0c03cb8a;
case 0x0c03cb8cu: goto P_0c03cb8c;
case 0x0c03cb8eu: goto P_0c03cb8e;
case 0x0c03cb90u: goto P_0c03cb90;
case 0x0c03cb92u: goto P_0c03cb92;
case 0x0c03cb94u: goto P_0c03cb94;
case 0x0c03cb96u: goto P_0c03cb96;
case 0x0c03cb98u: goto P_0c03cb98;
case 0x0c03cb9au: goto P_0c03cb9a;
case 0x0c03cb9cu: goto P_0c03cb9c;
case 0x0c03cb9eu: goto P_0c03cb9e;
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
case 0x0c03d260u: goto P_0c03d260;
case 0x0c03d262u: goto P_0c03d262;
case 0x0c03d264u: goto P_0c03d264;
case 0x0c03d266u: goto P_0c03d266;
case 0x0c03d268u: goto P_0c03d268;
case 0x0c03d26au: goto P_0c03d26a;
case 0x0c03d26cu: goto P_0c03d26c;
case 0x0c03d26eu: goto P_0c03d26e;
case 0x0c03d270u: goto P_0c03d270;
case 0x0c03d272u: goto P_0c03d272;
case 0x0c03d274u: goto P_0c03d274;
case 0x0c03d276u: goto P_0c03d276;
case 0x0c03d278u: goto P_0c03d278;
case 0x0c03d27au: goto P_0c03d27a;
case 0x0c03d27cu: goto P_0c03d27c;
case 0x0c03d27eu: goto P_0c03d27e;
case 0x0c03dd00u: goto P_0c03dd00;
case 0x0c03dd02u: goto P_0c03dd02;
case 0x0c03dd04u: goto P_0c03dd04;
case 0x0c03dd06u: goto P_0c03dd06;
case 0x0c03dd08u: goto P_0c03dd08;
case 0x0c03dd30u: goto P_0c03dd30;
case 0x0c03dd32u: goto P_0c03dd32;
case 0x0c03dd34u: goto P_0c03dd34;
case 0x0c03dd36u: goto P_0c03dd36;
case 0x0c03dd38u: goto P_0c03dd38;
case 0x0c03dd3au: goto P_0c03dd3a;
case 0x0c03dd3cu: goto P_0c03dd3c;
case 0x0c03dd3eu: goto P_0c03dd3e;
case 0x0c03dd40u: goto P_0c03dd40;
case 0x0c03dd42u: goto P_0c03dd42;
case 0x0c03dd44u: goto P_0c03dd44;
case 0x0c03dd46u: goto P_0c03dd46;
case 0x0c03dd48u: goto P_0c03dd48;
case 0x0c03dd4au: goto P_0c03dd4a;
case 0x0c03dd4cu: goto P_0c03dd4c;
case 0x0c03dd4eu: goto P_0c03dd4e;
case 0x0c03dd50u: goto P_0c03dd50;
case 0x0c03dd52u: goto P_0c03dd52;
case 0x0c03dd54u: goto P_0c03dd54;
case 0x0c03dd56u: goto P_0c03dd56;
case 0x0c03dd58u: goto P_0c03dd58;
case 0x0c03dd5au: goto P_0c03dd5a;
case 0x0c03dd5cu: goto P_0c03dd5c;
case 0x0c03dd5eu: goto P_0c03dd5e;
case 0x0c03dd60u: goto P_0c03dd60;
case 0x0c03dd62u: goto P_0c03dd62;
case 0x0c03dd64u: goto P_0c03dd64;
case 0x0c03dd66u: goto P_0c03dd66;
case 0x0c03dd68u: goto P_0c03dd68;
case 0x0c03dd6au: goto P_0c03dd6a;
case 0x0c03dd6cu: goto P_0c03dd6c;
case 0x0c03dd6eu: goto P_0c03dd6e;
case 0x0c03dd70u: goto P_0c03dd70;
case 0x0c03dd72u: goto P_0c03dd72;
case 0x0c03dd74u: goto P_0c03dd74;
case 0x0c03dd76u: goto P_0c03dd76;
case 0x0c03dd78u: goto P_0c03dd78;
case 0x0c03dd7au: goto P_0c03dd7a;
case 0x0c03dd7cu: goto P_0c03dd7c;
case 0x0c03dd7eu: goto P_0c03dd7e;
case 0x0c03dd80u: goto P_0c03dd80;
case 0x0c03dd82u: goto P_0c03dd82;
case 0x0c03dd84u: goto P_0c03dd84;
case 0x0c03dd86u: goto P_0c03dd86;
case 0x0c03dd88u: goto P_0c03dd88;
case 0x0c03dd8au: goto P_0c03dd8a;
case 0x0c03dd8cu: goto P_0c03dd8c;
case 0x0c03dd8eu: goto P_0c03dd8e;
case 0x0c03dd90u: goto P_0c03dd90;
case 0x0c03dd92u: goto P_0c03dd92;
case 0x0c03dd94u: goto P_0c03dd94;
case 0x0c03dd96u: goto P_0c03dd96;
case 0x0c03e680u: goto P_0c03e680;
case 0x0c03e682u: goto P_0c03e682;
case 0x0c03e684u: goto P_0c03e684;
case 0x0c03e686u: goto P_0c03e686;
case 0x0c03e688u: goto P_0c03e688;
case 0x0c03e68au: goto P_0c03e68a;
case 0x0c03e68cu: goto P_0c03e68c;
case 0x0c03e68eu: goto P_0c03e68e;
case 0x0c03e690u: goto P_0c03e690;
case 0x0c03e692u: goto P_0c03e692;
case 0x0c03e694u: goto P_0c03e694;
case 0x0c03e696u: goto P_0c03e696;
case 0x0c03e698u: goto P_0c03e698;
case 0x0c03e69au: goto P_0c03e69a;
case 0x0c03e69cu: goto P_0c03e69c;
case 0x0c03e69eu: goto P_0c03e69e;
case 0x0c03e6a0u: goto P_0c03e6a0;
case 0x0c03e6a2u: goto P_0c03e6a2;
case 0x0c03e6a4u: goto P_0c03e6a4;
case 0x0c03e6a6u: goto P_0c03e6a6;
case 0x0c03e6a8u: goto P_0c03e6a8;
case 0x0c03ecb0u: goto P_0c03ecb0;
case 0x0c03ecb2u: goto P_0c03ecb2;
case 0x0c03ecb4u: goto P_0c03ecb4;
case 0x0c03ecb6u: goto P_0c03ecb6;
case 0x0c03ecb8u: goto P_0c03ecb8;
case 0x0c03ecbau: goto P_0c03ecba;
case 0x0c03ecbcu: goto P_0c03ecbc;
case 0x0c03ecbeu: goto P_0c03ecbe;
case 0x0c03ecc0u: goto P_0c03ecc0;
case 0x0c03ecc2u: goto P_0c03ecc2;
case 0x0c03ecc4u: goto P_0c03ecc4;
case 0x0c03ecc6u: goto P_0c03ecc6;
case 0x0c03ecc8u: goto P_0c03ecc8;
case 0x0c03eccau: goto P_0c03ecca;
case 0x0c03ed60u: goto P_0c03ed60;
case 0x0c03ed62u: goto P_0c03ed62;
case 0x0c03ed64u: goto P_0c03ed64;
case 0x0c03ed66u: goto P_0c03ed66;
case 0x0c03ed68u: goto P_0c03ed68;
case 0x0c03ed6au: goto P_0c03ed6a;
case 0x0c03ed6cu: goto P_0c03ed6c;
case 0x0c03ed6eu: goto P_0c03ed6e;
case 0x0c03ed70u: goto P_0c03ed70;
case 0x0c03ed72u: goto P_0c03ed72;
case 0x0c03ed74u: goto P_0c03ed74;
case 0x0c03ed76u: goto P_0c03ed76;
case 0x0c03ed78u: goto P_0c03ed78;
case 0x0c03ed7au: goto P_0c03ed7a;
case 0x0c03ed7cu: goto P_0c03ed7c;
default: return vf3_matrix_family(target,s,ram);
}
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
P_0c03c5b0: /* original fbfd, guest PC 0x0c03c5b0 */
if(!s->budget--) { s->failed_pc=0x0c03c5b0u; return 0; }
vf3_matrix_swap(s);
goto P_0c03c5b2;
P_0c03c5b2: /* original f38d, guest PC 0x0c03c5b2 */
if(!s->budget--) { s->failed_pc=0x0c03c5b2u; return 0; }
fr[3]=0;
goto P_0c03c5b4;
P_0c03c5b4: /* original fbb1, guest PC 0x0c03c5b4 */
if(!s->budget--) { s->failed_pc=0x0c03c5b4u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'-');
goto P_0c03c5b6;
P_0c03c5b6: /* original f78d, guest PC 0x0c03c5b6 */
if(!s->budget--) { s->failed_pc=0x0c03c5b6u; return 0; }
fr[7]=0;
goto P_0c03c5b8;
P_0c03c5b8: /* original ff9d, guest PC 0x0c03c5b8 */
if(!s->budget--) { s->failed_pc=0x0c03c5b8u; return 0; }
fr[15]=0x3f800000u;
goto P_0c03c5ba;
P_0c03c5ba: /* original f11d, guest PC 0x0c03c5ba */
if(!s->budget--) { s->failed_pc=0x0c03c5bau; return 0; }
r[53]=fr[1];
goto P_0c03c5bc;
P_0c03c5bc: /* original f3ed, guest PC 0x0c03c5bc */
if(!s->budget--) { s->failed_pc=0x0c03c5bcu; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c03c5be;
P_0c03c5be: /* original f14c, guest PC 0x0c03c5be */
if(!s->budget--) { s->failed_pc=0x0c03c5beu; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c03c5c0;
P_0c03c5c0: /* original f7ed, guest PC 0x0c03c5c0 */
if(!s->budget--) { s->failed_pc=0x0c03c5c0u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c03c5c2;
P_0c03c5c2: /* original f40d, guest PC 0x0c03c5c2 */
if(!s->budget--) { s->failed_pc=0x0c03c5c2u; return 0; }
fr[4]=r[53];
goto P_0c03c5c4;
P_0c03c5c4: /* original fbed, guest PC 0x0c03c5c4 */
if(!s->budget--) { s->failed_pc=0x0c03c5c4u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+8,r[18],fr+11)) goto unsupported;
goto P_0c03c5c6;
P_0c03c5c6: /* original fc8d, guest PC 0x0c03c5c6 */
if(!s->budget--) { s->failed_pc=0x0c03c5c6u; return 0; }
fr[12]=0;
goto P_0c03c5c8;
P_0c03c5c8: /* original fee1, guest PC 0x0c03c5c8 */
if(!s->budget--) { s->failed_pc=0x0c03c5c8u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[14],r[18],'-');
goto P_0c03c5ca;
P_0c03c5ca: /* original fc31, guest PC 0x0c03c5ca */
if(!s->budget--) { s->failed_pc=0x0c03c5cau; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'-');
goto P_0c03c5cc;
P_0c03c5cc: /* original fd8d, guest PC 0x0c03c5cc */
if(!s->budget--) { s->failed_pc=0x0c03c5ccu; return 0; }
fr[13]=0;
goto P_0c03c5ce;
P_0c03c5ce: /* original fd71, guest PC 0x0c03c5ce */
if(!s->budget--) { s->failed_pc=0x0c03c5ceu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[7],r[18],'-');
goto P_0c03c5d0;
P_0c03c5d0: /* original f21d, guest PC 0x0c03c5d0 */
if(!s->budget--) { s->failed_pc=0x0c03c5d0u; return 0; }
r[53]=fr[2];
goto P_0c03c5d2;
P_0c03c5d2: /* original feb1, guest PC 0x0c03c5d2 */
if(!s->budget--) { s->failed_pc=0x0c03c5d2u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[11],r[18],'-');
goto P_0c03c5d4;
P_0c03c5d4: /* original f28c, guest PC 0x0c03c5d4 */
if(!s->budget--) { s->failed_pc=0x0c03c5d4u; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c03c5d6;
P_0c03c5d6: /* original f331, guest PC 0x0c03c5d6 */
if(!s->budget--) { s->failed_pc=0x0c03c5d6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[3],r[18],'-');
goto P_0c03c5d8;
P_0c03c5d8: /* original f80d, guest PC 0x0c03c5d8 */
if(!s->budget--) { s->failed_pc=0x0c03c5d8u; return 0; }
fr[8]=r[53];
goto P_0c03c5da;
P_0c03c5da: /* original f771, guest PC 0x0c03c5da */
if(!s->budget--) { s->failed_pc=0x0c03c5dau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[7],r[18],'-');
goto P_0c03c5dc;
P_0c03c5dc: /* original f61d, guest PC 0x0c03c5dc */
if(!s->budget--) { s->failed_pc=0x0c03c5dcu; return 0; }
r[53]=fr[6];
goto P_0c03c5de;
P_0c03c5de: /* original fbb1, guest PC 0x0c03c5de */
if(!s->budget--) { s->failed_pc=0x0c03c5deu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'-');
goto P_0c03c5e0;
P_0c03c5e0: /* original f69c, guest PC 0x0c03c5e0 */
if(!s->budget--) { s->failed_pc=0x0c03c5e0u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c03c5e2;
P_0c03c5e2: /* original f90d, guest PC 0x0c03c5e2 */
if(!s->budget--) { s->failed_pc=0x0c03c5e2u; return 0; }
fr[9]=r[53];
goto P_0c03c5e4;
P_0c03c5e4: /* original fbfd, guest PC 0x0c03c5e4 */
if(!s->budget--) { s->failed_pc=0x0c03c5e4u; return 0; }
vf3_matrix_swap(s);
goto P_0c03c5e6;
P_0c03c5e6: /* original 0009, guest PC 0x0c03c5e6 */
if(!s->budget--) { s->failed_pc=0x0c03c5e6u; return 0; }
goto P_0c03c5e8;
P_0c03c5e8: /* original 000b, guest PC 0x0c03c5e8 */
if(!s->budget--) { s->failed_pc=0x0c03c5e8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03c5ea: /* original 0009, guest PC 0x0c03c5ea */
if(!s->budget--) { s->failed_pc=0x0c03c5eau; return 0; }
if(!vf3_matrix_family(0x0c03c5ecu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03c5ecu; return 0; } return 1;
P_0c03cb70: /* original ff6b, guest PC 0x0c03cb70 */
if(!s->budget--) { s->failed_pc=0x0c03cb70u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[15]);
goto P_0c03cb72;
P_0c03cb72: /* original ff5b, guest PC 0x0c03cb72 */
if(!s->budget--) { s->failed_pc=0x0c03cb72u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[15]);
goto P_0c03cb74;
P_0c03cb74: /* original ff4b, guest PC 0x0c03cb74 */
if(!s->budget--) { s->failed_pc=0x0c03cb74u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c03cb76;
P_0c03cb76: /* original fbfd, guest PC 0x0c03cb76 */
if(!s->budget--) { s->failed_pc=0x0c03cb76u; return 0; }
vf3_matrix_swap(s);
goto P_0c03cb78;
P_0c03cb78: /* original ff1d, guest PC 0x0c03cb78 */
if(!s->budget--) { s->failed_pc=0x0c03cb78u; return 0; }
r[53]=fr[15];
goto P_0c03cb7a;
P_0c03cb7a: /* original fff9, guest PC 0x0c03cb7a */
if(!s->budget--) { s->failed_pc=0x0c03cb7au; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03cb7c;
P_0c03cb7c: /* original f0f2, guest PC 0x0c03cb7c */
if(!s->budget--) { s->failed_pc=0x0c03cb7cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c03cb7e;
P_0c03cb7e: /* original f1f2, guest PC 0x0c03cb7e */
if(!s->budget--) { s->failed_pc=0x0c03cb7eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[15],r[18],'*');
goto P_0c03cb80;
P_0c03cb80: /* original f2f2, guest PC 0x0c03cb80 */
if(!s->budget--) { s->failed_pc=0x0c03cb80u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[15],r[18],'*');
goto P_0c03cb82;
P_0c03cb82: /* original f3f2, guest PC 0x0c03cb82 */
if(!s->budget--) { s->failed_pc=0x0c03cb82u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c03cb84;
P_0c03cb84: /* original fff9, guest PC 0x0c03cb84 */
if(!s->budget--) { s->failed_pc=0x0c03cb84u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03cb86;
P_0c03cb86: /* original f4f2, guest PC 0x0c03cb86 */
if(!s->budget--) { s->failed_pc=0x0c03cb86u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c03cb88;
P_0c03cb88: /* original f5f2, guest PC 0x0c03cb88 */
if(!s->budget--) { s->failed_pc=0x0c03cb88u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[15],r[18],'*');
goto P_0c03cb8a;
P_0c03cb8a: /* original f6f2, guest PC 0x0c03cb8a */
if(!s->budget--) { s->failed_pc=0x0c03cb8au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[15],r[18],'*');
goto P_0c03cb8c;
P_0c03cb8c: /* original f7f2, guest PC 0x0c03cb8c */
if(!s->budget--) { s->failed_pc=0x0c03cb8cu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[15],r[18],'*');
goto P_0c03cb8e;
P_0c03cb8e: /* original fff9, guest PC 0x0c03cb8e */
if(!s->budget--) { s->failed_pc=0x0c03cb8eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03cb90;
P_0c03cb90: /* original f8f2, guest PC 0x0c03cb90 */
if(!s->budget--) { s->failed_pc=0x0c03cb90u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[15],r[18],'*');
goto P_0c03cb92;
P_0c03cb92: /* original f9f2, guest PC 0x0c03cb92 */
if(!s->budget--) { s->failed_pc=0x0c03cb92u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[15],r[18],'*');
goto P_0c03cb94;
P_0c03cb94: /* original faf2, guest PC 0x0c03cb94 */
if(!s->budget--) { s->failed_pc=0x0c03cb94u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[15],r[18],'*');
goto P_0c03cb96;
P_0c03cb96: /* original fbf2, guest PC 0x0c03cb96 */
if(!s->budget--) { s->failed_pc=0x0c03cb96u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[15],r[18],'*');
goto P_0c03cb98;
P_0c03cb98: /* original ff0d, guest PC 0x0c03cb98 */
if(!s->budget--) { s->failed_pc=0x0c03cb98u; return 0; }
fr[15]=r[53];
goto P_0c03cb9a;
P_0c03cb9a: /* original fbfd, guest PC 0x0c03cb9a */
if(!s->budget--) { s->failed_pc=0x0c03cb9au; return 0; }
vf3_matrix_swap(s);
goto P_0c03cb9c;
P_0c03cb9c: /* original 000b, guest PC 0x0c03cb9c */
if(!s->budget--) { s->failed_pc=0x0c03cb9cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03cb9e: /* original 0009, guest PC 0x0c03cb9e */
if(!s->budget--) { s->failed_pc=0x0c03cb9eu; return 0; }
if(!vf3_matrix_family(0x0c03cba0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03cba0u; return 0; } return 1;
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
P_0c03d260: /* original 4f22, guest PC 0x0c03d260 */
if(!s->budget--) { s->failed_pc=0x0c03d260u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03d262;
P_0c03d262: /* original d347, guest PC 0x0c03d262 */
if(!s->budget--) { s->failed_pc=0x0c03d262u; return 0; }
r[3]=read(ram,0x0c03d380u,4);
goto P_0c03d264;
P_0c03d264: /* original d445, guest PC 0x0c03d264 */
if(!s->budget--) { s->failed_pc=0x0c03d264u; return 0; }
r[4]=read(ram,0x0c03d37cu,4);
goto P_0c03d266;
P_0c03d266: /* original 430b, guest PC 0x0c03d266 */
if(!s->budget--) { s->failed_pc=0x0c03d266u; return 0; }
target=r[3];
r[16]=code_base|0x0c03d26au;
r[4]=read(ram,r[4]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d26au) { target=s->pc; goto dispatch; }
goto P_0c03d26a;
P_0c03d268: /* original 5442, guest PC 0x0c03d268 */
if(!s->budget--) { s->failed_pc=0x0c03d268u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c03d26a;
P_0c03d26a: /* original d246, guest PC 0x0c03d26a */
if(!s->budget--) { s->failed_pc=0x0c03d26au; return 0; }
r[2]=read(ram,0x0c03d384u,4);
goto P_0c03d26c;
P_0c03d26c: /* original 420b, guest PC 0x0c03d26c */
if(!s->budget--) { s->failed_pc=0x0c03d26cu; return 0; }
target=r[2];
r[16]=code_base|0x0c03d270u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d270u) { target=s->pc; goto dispatch; }
goto P_0c03d270;
P_0c03d26e: /* original 0009, guest PC 0x0c03d26e */
if(!s->budget--) { s->failed_pc=0x0c03d26eu; return 0; }
goto P_0c03d270;
P_0c03d270: /* original d346, guest PC 0x0c03d270 */
if(!s->budget--) { s->failed_pc=0x0c03d270u; return 0; }
r[3]=read(ram,0x0c03d38cu,4);
goto P_0c03d272;
P_0c03d272: /* original d445, guest PC 0x0c03d272 */
if(!s->budget--) { s->failed_pc=0x0c03d272u; return 0; }
r[4]=read(ram,0x0c03d388u,4);
goto P_0c03d274;
P_0c03d274: /* original 430b, guest PC 0x0c03d274 */
if(!s->budget--) { s->failed_pc=0x0c03d274u; return 0; }
target=r[3];
r[16]=code_base|0x0c03d278u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d278u) { target=s->pc; goto dispatch; }
goto P_0c03d278;
P_0c03d276: /* original 0009, guest PC 0x0c03d276 */
if(!s->budget--) { s->failed_pc=0x0c03d276u; return 0; }
goto P_0c03d278;
P_0c03d278: /* original d245, guest PC 0x0c03d278 */
if(!s->budget--) { s->failed_pc=0x0c03d278u; return 0; }
r[2]=read(ram,0x0c03d390u,4);
goto P_0c03d27a;
P_0c03d27a: /* original e401, guest PC 0x0c03d27a */
if(!s->budget--) { s->failed_pc=0x0c03d27au; return 0; }
r[4]=0x00000001u;
goto P_0c03d27c;
P_0c03d27c: /* original 422b, guest PC 0x0c03d27c */
if(!s->budget--) { s->failed_pc=0x0c03d27cu; return 0; }
target=r[2];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c03d27e: /* original 4f26, guest PC 0x0c03d27e */
if(!s->budget--) { s->failed_pc=0x0c03d27eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c03d280u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03d280u; return 0; } return 1;
P_0c03dd00: /* original d407, guest PC 0x0c03dd00 */
if(!s->budget--) { s->failed_pc=0x0c03dd00u; return 0; }
r[4]=read(ram,0x0c03dd20u,4);
goto P_0c03dd02;
P_0c03dd02: /* original d502, guest PC 0x0c03dd02 */
if(!s->budget--) { s->failed_pc=0x0c03dd02u; return 0; }
r[5]=read(ram,0x0c03dd0cu,4);
goto P_0c03dd04;
P_0c03dd04: /* original 5442, guest PC 0x0c03dd04 */
if(!s->budget--) { s->failed_pc=0x0c03dd04u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c03dd06;
P_0c03dd06: /* original a013, guest PC 0x0c03dd06 */
if(!s->budget--) { s->failed_pc=0x0c03dd06u; return 0; }
goto P_0c03dd30;
P_0c03dd08: /* original 0009, guest PC 0x0c03dd08 */
if(!s->budget--) { s->failed_pc=0x0c03dd08u; return 0; }
if(!vf3_matrix_family(0x0c03dd0au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03dd0au; return 0; } return 1;
P_0c03dd30: /* original fffb, guest PC 0x0c03dd30 */
if(!s->budget--) { s->failed_pc=0x0c03dd30u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c03dd32;
P_0c03dd32: /* original ffeb, guest PC 0x0c03dd32 */
if(!s->budget--) { s->failed_pc=0x0c03dd32u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c03dd34;
P_0c03dd34: /* original ffdb, guest PC 0x0c03dd34 */
if(!s->budget--) { s->failed_pc=0x0c03dd34u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c03dd36;
P_0c03dd36: /* original ffcb, guest PC 0x0c03dd36 */
if(!s->budget--) { s->failed_pc=0x0c03dd36u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c03dd38;
P_0c03dd38: /* original f3fd, guest PC 0x0c03dd38 */
if(!s->budget--) { s->failed_pc=0x0c03dd38u; return 0; }
r[18]^=0x100000u;
goto P_0c03dd3a;
P_0c03dd3a: /* original f049, guest PC 0x0c03dd3a */
if(!s->budget--) { s->failed_pc=0x0c03dd3au; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd3c;
P_0c03dd3c: /* original f249, guest PC 0x0c03dd3c */
if(!s->budget--) { s->failed_pc=0x0c03dd3cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd3e;
P_0c03dd3e: /* original f449, guest PC 0x0c03dd3e */
if(!s->budget--) { s->failed_pc=0x0c03dd3eu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd40;
P_0c03dd40: /* original f649, guest PC 0x0c03dd40 */
if(!s->budget--) { s->failed_pc=0x0c03dd40u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd42;
P_0c03dd42: /* original f849, guest PC 0x0c03dd42 */
if(!s->budget--) { s->failed_pc=0x0c03dd42u; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd44;
P_0c03dd44: /* original fa49, guest PC 0x0c03dd44 */
if(!s->budget--) { s->failed_pc=0x0c03dd44u; return 0; }
vf3_matrix_load(s,ram,10,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd46;
P_0c03dd46: /* original fc49, guest PC 0x0c03dd46 */
if(!s->budget--) { s->failed_pc=0x0c03dd46u; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd48;
P_0c03dd48: /* original fe49, guest PC 0x0c03dd48 */
if(!s->budget--) { s->failed_pc=0x0c03dd48u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd4a;
P_0c03dd4a: /* original f3fd, guest PC 0x0c03dd4a */
if(!s->budget--) { s->failed_pc=0x0c03dd4au; return 0; }
r[18]^=0x100000u;
goto P_0c03dd4c;
P_0c03dd4c: /* original fbfd, guest PC 0x0c03dd4c */
if(!s->budget--) { s->failed_pc=0x0c03dd4cu; return 0; }
vf3_matrix_swap(s);
goto P_0c03dd4e;
P_0c03dd4e: /* original 6453, guest PC 0x0c03dd4e */
if(!s->budget--) { s->failed_pc=0x0c03dd4eu; return 0; }
r[4]=r[5];
goto P_0c03dd50;
P_0c03dd50: /* original 0483, guest PC 0x0c03dd50 */
if(!s->budget--) { s->failed_pc=0x0c03dd50u; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c03dd52;
P_0c03dd52: /* original f1fd, guest PC 0x0c03dd52 */
if(!s->budget--) { s->failed_pc=0x0c03dd52u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c03dd54;
P_0c03dd54: /* original 7420, guest PC 0x0c03dd54 */
if(!s->budget--) { s->failed_pc=0x0c03dd54u; return 0; }
r[4]+=0x00000020u;
goto P_0c03dd56;
P_0c03dd56: /* original f5fd, guest PC 0x0c03dd56 */
if(!s->budget--) { s->failed_pc=0x0c03dd56u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c03dd58;
P_0c03dd58: /* original f9fd, guest PC 0x0c03dd58 */
if(!s->budget--) { s->failed_pc=0x0c03dd58u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+8,r[18],fr+8)) goto unsupported;
goto P_0c03dd5a;
P_0c03dd5a: /* original fdfd, guest PC 0x0c03dd5a */
if(!s->budget--) { s->failed_pc=0x0c03dd5au; return 0; }
if(!vf3_fpu_ftrv(xf,fr+12,r[18],fr+12)) goto unsupported;
goto P_0c03dd5c;
P_0c03dd5c: /* original 0483, guest PC 0x0c03dd5c */
if(!s->budget--) { s->failed_pc=0x0c03dd5cu; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c03dd5e;
P_0c03dd5e: /* original fbfd, guest PC 0x0c03dd5e */
if(!s->budget--) { s->failed_pc=0x0c03dd5eu; return 0; }
vf3_matrix_swap(s);
goto P_0c03dd60;
P_0c03dd60: /* original f059, guest PC 0x0c03dd60 */
if(!s->budget--) { s->failed_pc=0x0c03dd60u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd62;
P_0c03dd62: /* original f159, guest PC 0x0c03dd62 */
if(!s->budget--) { s->failed_pc=0x0c03dd62u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd64;
P_0c03dd64: /* original f259, guest PC 0x0c03dd64 */
if(!s->budget--) { s->failed_pc=0x0c03dd64u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd66;
P_0c03dd66: /* original f359, guest PC 0x0c03dd66 */
if(!s->budget--) { s->failed_pc=0x0c03dd66u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd68;
P_0c03dd68: /* original f459, guest PC 0x0c03dd68 */
if(!s->budget--) { s->failed_pc=0x0c03dd68u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd6a;
P_0c03dd6a: /* original f559, guest PC 0x0c03dd6a */
if(!s->budget--) { s->failed_pc=0x0c03dd6au; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd6c;
P_0c03dd6c: /* original f659, guest PC 0x0c03dd6c */
if(!s->budget--) { s->failed_pc=0x0c03dd6cu; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd6e;
P_0c03dd6e: /* original f759, guest PC 0x0c03dd6e */
if(!s->budget--) { s->failed_pc=0x0c03dd6eu; return 0; }
vf3_matrix_load(s,ram,7,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd70;
P_0c03dd70: /* original f859, guest PC 0x0c03dd70 */
if(!s->budget--) { s->failed_pc=0x0c03dd70u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd72;
P_0c03dd72: /* original f959, guest PC 0x0c03dd72 */
if(!s->budget--) { s->failed_pc=0x0c03dd72u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd74;
P_0c03dd74: /* original fa59, guest PC 0x0c03dd74 */
if(!s->budget--) { s->failed_pc=0x0c03dd74u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd76;
P_0c03dd76: /* original fb59, guest PC 0x0c03dd76 */
if(!s->budget--) { s->failed_pc=0x0c03dd76u; return 0; }
vf3_matrix_load(s,ram,11,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd78;
P_0c03dd78: /* original fc59, guest PC 0x0c03dd78 */
if(!s->budget--) { s->failed_pc=0x0c03dd78u; return 0; }
vf3_matrix_load(s,ram,12,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd7a;
P_0c03dd7a: /* original fd59, guest PC 0x0c03dd7a */
if(!s->budget--) { s->failed_pc=0x0c03dd7au; return 0; }
vf3_matrix_load(s,ram,13,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd7c;
P_0c03dd7c: /* original fe59, guest PC 0x0c03dd7c */
if(!s->budget--) { s->failed_pc=0x0c03dd7cu; return 0; }
vf3_matrix_load(s,ram,14,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd7e;
P_0c03dd7e: /* original ff59, guest PC 0x0c03dd7e */
if(!s->budget--) { s->failed_pc=0x0c03dd7eu; return 0; }
vf3_matrix_load(s,ram,15,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd80;
P_0c03dd80: /* original fbfd, guest PC 0x0c03dd80 */
if(!s->budget--) { s->failed_pc=0x0c03dd80u; return 0; }
vf3_matrix_swap(s);
goto P_0c03dd82;
P_0c03dd82: /* original f1fd, guest PC 0x0c03dd82 */
if(!s->budget--) { s->failed_pc=0x0c03dd82u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c03dd84;
P_0c03dd84: /* original f5fd, guest PC 0x0c03dd84 */
if(!s->budget--) { s->failed_pc=0x0c03dd84u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c03dd86;
P_0c03dd86: /* original f9fd, guest PC 0x0c03dd86 */
if(!s->budget--) { s->failed_pc=0x0c03dd86u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+8,r[18],fr+8)) goto unsupported;
goto P_0c03dd88;
P_0c03dd88: /* original fdfd, guest PC 0x0c03dd88 */
if(!s->budget--) { s->failed_pc=0x0c03dd88u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+12,r[18],fr+12)) goto unsupported;
goto P_0c03dd8a;
P_0c03dd8a: /* original fbfd, guest PC 0x0c03dd8a */
if(!s->budget--) { s->failed_pc=0x0c03dd8au; return 0; }
vf3_matrix_swap(s);
goto P_0c03dd8c;
P_0c03dd8c: /* original fcf9, guest PC 0x0c03dd8c */
if(!s->budget--) { s->failed_pc=0x0c03dd8cu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd8e;
P_0c03dd8e: /* original fdf9, guest PC 0x0c03dd8e */
if(!s->budget--) { s->failed_pc=0x0c03dd8eu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd90;
P_0c03dd90: /* original fef9, guest PC 0x0c03dd90 */
if(!s->budget--) { s->failed_pc=0x0c03dd90u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd92;
P_0c03dd92: /* original fff9, guest PC 0x0c03dd92 */
if(!s->budget--) { s->failed_pc=0x0c03dd92u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd94;
P_0c03dd94: /* original 000b, guest PC 0x0c03dd94 */
if(!s->budget--) { s->failed_pc=0x0c03dd94u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03dd96: /* original 0009, guest PC 0x0c03dd96 */
if(!s->budget--) { s->failed_pc=0x0c03dd96u; return 0; }
if(!vf3_matrix_family(0x0c03dd98u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03dd98u; return 0; } return 1;
P_0c03e680: /* original 2fe6, guest PC 0x0c03e680 */
if(!s->budget--) { s->failed_pc=0x0c03e680u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e682;
P_0c03e682: /* original e044, guest PC 0x0c03e682 */
if(!s->budget--) { s->failed_pc=0x0c03e682u; return 0; }
r[0]=0x00000044u;
goto P_0c03e684;
P_0c03e684: /* original 9e57, guest PC 0x0c03e684 */
if(!s->budget--) { s->failed_pc=0x0c03e684u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e736u,2);
goto P_0c03e686;
P_0c03e686: /* original 4f12, guest PC 0x0c03e686 */
if(!s->budget--) { s->failed_pc=0x0c03e686u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03e688;
P_0c03e688: /* original 24ef, guest PC 0x0c03e688 */
if(!s->budget--) { s->failed_pc=0x0c03e688u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[14]);
goto P_0c03e68a;
P_0c03e68a: /* original d32c, guest PC 0x0c03e68a */
if(!s->budget--) { s->failed_pc=0x0c03e68au; return 0; }
r[3]=read(ram,0x0c03e73cu,4);
goto P_0c03e68c;
P_0c03e68c: /* original 0e1a, guest PC 0x0c03e68c */
if(!s->budget--) { s->failed_pc=0x0c03e68cu; return 0; }
r[14]=r[19];
goto P_0c03e68e;
P_0c03e68e: /* original 4f16, guest PC 0x0c03e68e */
if(!s->budget--) { s->failed_pc=0x0c03e68eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c03e690;
P_0c03e690: /* original 6eef, guest PC 0x0c03e690 */
if(!s->budget--) { s->failed_pc=0x0c03e690u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c03e692;
P_0c03e692: /* original 3e3c, guest PC 0x0c03e692 */
if(!s->budget--) { s->failed_pc=0x0c03e692u; return 0; }
r[14]+=r[3];
goto P_0c03e694;
P_0c03e694: /* original 62e3, guest PC 0x0c03e694 */
if(!s->budget--) { s->failed_pc=0x0c03e694u; return 0; }
r[2]=r[14];
goto P_0c03e696;
P_0c03e696: /* original 7240, guest PC 0x0c03e696 */
if(!s->budget--) { s->failed_pc=0x0c03e696u; return 0; }
r[2]+=0x00000040u;
goto P_0c03e698;
P_0c03e698: /* original f24a, guest PC 0x0c03e698 */
if(!s->budget--) { s->failed_pc=0x0c03e698u; return 0; }
vf3_matrix_store(s,ram,4,r[2]);
goto P_0c03e69a;
P_0c03e69a: /* original 64e3, guest PC 0x0c03e69a */
if(!s->budget--) { s->failed_pc=0x0c03e69au; return 0; }
r[4]=r[14];
goto P_0c03e69c;
P_0c03e69c: /* original fe57, guest PC 0x0c03e69c */
if(!s->budget--) { s->failed_pc=0x0c03e69cu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c03e69e;
P_0c03e69e: /* original e048, guest PC 0x0c03e69e */
if(!s->budget--) { s->failed_pc=0x0c03e69eu; return 0; }
r[0]=0x00000048u;
goto P_0c03e6a0;
P_0c03e6a0: /* original fe67, guest PC 0x0c03e6a0 */
if(!s->budget--) { s->failed_pc=0x0c03e6a0u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c03e6a2;
P_0c03e6a2: /* original 7440, guest PC 0x0c03e6a2 */
if(!s->budget--) { s->failed_pc=0x0c03e6a2u; return 0; }
r[4]+=0x00000040u;
goto P_0c03e6a4;
P_0c03e6a4: /* original d22a, guest PC 0x0c03e6a4 */
if(!s->budget--) { s->failed_pc=0x0c03e6a4u; return 0; }
r[2]=read(ram,0x0c03e750u,4);
goto P_0c03e6a6;
P_0c03e6a6: /* original 422b, guest PC 0x0c03e6a6 */
if(!s->budget--) { s->failed_pc=0x0c03e6a6u; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c03d040u: goto P_0c03d040;
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
P_0c03e6a8: /* original 6ef6, guest PC 0x0c03e6a8 */
if(!s->budget--) { s->failed_pc=0x0c03e6a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03e6aau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e6aau; return 0; } return 1;
P_0c03ecb0: /* original 4f22, guest PC 0x0c03ecb0 */
if(!s->budget--) { s->failed_pc=0x0c03ecb0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03ecb2;
P_0c03ecb2: /* original 7ffc, guest PC 0x0c03ecb2 */
if(!s->budget--) { s->failed_pc=0x0c03ecb2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03ecb4;
P_0c03ecb4: /* original 2f42, guest PC 0x0c03ecb4 */
if(!s->budget--) { s->failed_pc=0x0c03ecb4u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c03ecb6;
P_0c03ecb6: /* original d366, guest PC 0x0c03ecb6 */
if(!s->budget--) { s->failed_pc=0x0c03ecb6u; return 0; }
r[3]=read(ram,0x0c03ee50u,4);
goto P_0c03ecb8;
P_0c03ecb8: /* original f58d, guest PC 0x0c03ecb8 */
if(!s->budget--) { s->failed_pc=0x0c03ecb8u; return 0; }
fr[5]=0;
goto P_0c03ecba;
P_0c03ecba: /* original 430b, guest PC 0x0c03ecba */
if(!s->budget--) { s->failed_pc=0x0c03ecbau; return 0; }
target=r[3];
r[16]=code_base|0x0c03ecbeu;
fr[4]=0;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03ecbeu) { target=s->pc; goto dispatch; }
goto P_0c03ecbe;
P_0c03ecbc: /* original f48d, guest PC 0x0c03ecbc */
if(!s->budget--) { s->failed_pc=0x0c03ecbcu; return 0; }
fr[4]=0;
goto P_0c03ecbe;
P_0c03ecbe: /* original b0bf, guest PC 0x0c03ecbe */
if(!s->budget--) { s->failed_pc=0x0c03ecbeu; return 0; }
target=code_base|0x0c03ee40u; r[16]=code_base|0x0c03ecc2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03ecc2u) { target=s->pc; goto dispatch; }
goto P_0c03ecc2;
P_0c03ecc0: /* original 0009, guest PC 0x0c03ecc0 */
if(!s->budget--) { s->failed_pc=0x0c03ecc0u; return 0; }
goto P_0c03ecc2;
P_0c03ecc2: /* original d364, guest PC 0x0c03ecc2 */
if(!s->budget--) { s->failed_pc=0x0c03ecc2u; return 0; }
r[3]=read(ram,0x0c03ee54u,4);
goto P_0c03ecc4;
P_0c03ecc4: /* original 64f2, guest PC 0x0c03ecc4 */
if(!s->budget--) { s->failed_pc=0x0c03ecc4u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c03ecc6;
P_0c03ecc6: /* original 7f04, guest PC 0x0c03ecc6 */
if(!s->budget--) { s->failed_pc=0x0c03ecc6u; return 0; }
r[15]+=0x00000004u;
goto P_0c03ecc8;
P_0c03ecc8: /* original 432b, guest PC 0x0c03ecc8 */
if(!s->budget--) { s->failed_pc=0x0c03ecc8u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c03ecca: /* original 4f26, guest PC 0x0c03ecca */
if(!s->budget--) { s->failed_pc=0x0c03eccau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c03ecccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03ecccu; return 0; } return 1;
P_0c03ed60: /* original e004, guest PC 0x0c03ed60 */
if(!s->budget--) { s->failed_pc=0x0c03ed60u; return 0; }
r[0]=0x00000004u;
goto P_0c03ed62;
P_0c03ed62: /* original d540, guest PC 0x0c03ed62 */
if(!s->budget--) { s->failed_pc=0x0c03ed62u; return 0; }
r[5]=read(ram,0x0c03ee64u,4);
goto P_0c03ed64;
P_0c03ed64: /* original f348, guest PC 0x0c03ed64 */
if(!s->budget--) { s->failed_pc=0x0c03ed64u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c03ed66;
P_0c03ed66: /* original f53a, guest PC 0x0c03ed66 */
if(!s->budget--) { s->failed_pc=0x0c03ed66u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c03ed68;
P_0c03ed68: /* original f246, guest PC 0x0c03ed68 */
if(!s->budget--) { s->failed_pc=0x0c03ed68u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c03ed6a;
P_0c03ed6a: /* original f527, guest PC 0x0c03ed6a */
if(!s->budget--) { s->failed_pc=0x0c03ed6au; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c03ed6c;
P_0c03ed6c: /* original e008, guest PC 0x0c03ed6c */
if(!s->budget--) { s->failed_pc=0x0c03ed6cu; return 0; }
r[0]=0x00000008u;
goto P_0c03ed6e;
P_0c03ed6e: /* original f346, guest PC 0x0c03ed6e */
if(!s->budget--) { s->failed_pc=0x0c03ed6eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c03ed70;
P_0c03ed70: /* original f537, guest PC 0x0c03ed70 */
if(!s->budget--) { s->failed_pc=0x0c03ed70u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c03ed72;
P_0c03ed72: /* original f246, guest PC 0x0c03ed72 */
if(!s->budget--) { s->failed_pc=0x0c03ed72u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c03ed74;
P_0c03ed74: /* original e00c, guest PC 0x0c03ed74 */
if(!s->budget--) { s->failed_pc=0x0c03ed74u; return 0; }
r[0]=0x0000000cu;
goto P_0c03ed76;
P_0c03ed76: /* original f39d, guest PC 0x0c03ed76 */
if(!s->budget--) { s->failed_pc=0x0c03ed76u; return 0; }
fr[3]=0x3f800000u;
goto P_0c03ed78;
P_0c03ed78: /* original f230, guest PC 0x0c03ed78 */
if(!s->budget--) { s->failed_pc=0x0c03ed78u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c03ed7a;
P_0c03ed7a: /* original 000b, guest PC 0x0c03ed7a */
if(!s->budget--) { s->failed_pc=0x0c03ed7au; return 0; }
target=r[16];
vf3_matrix_store(s,ram,2,r[5]+r[0]);
s->pc=target; return ram->oob==0;
P_0c03ed7c: /* original f527, guest PC 0x0c03ed7c */
if(!s->budget--) { s->failed_pc=0x0c03ed7cu; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
if(!vf3_matrix_family(0x0c03ed7eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03ed7eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
