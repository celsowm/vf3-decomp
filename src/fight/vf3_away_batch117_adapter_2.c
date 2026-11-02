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
int vf3_away_batch117_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c038cb0u: goto P_0c038cb0;
case 0x0c038cb2u: goto P_0c038cb2;
case 0x0c038cb4u: goto P_0c038cb4;
case 0x0c038cb6u: goto P_0c038cb6;
case 0x0c038cb8u: goto P_0c038cb8;
case 0x0c038cbau: goto P_0c038cba;
case 0x0c038cbcu: goto P_0c038cbc;
case 0x0c038cbeu: goto P_0c038cbe;
case 0x0c038cc0u: goto P_0c038cc0;
case 0x0c038cc2u: goto P_0c038cc2;
case 0x0c038cc4u: goto P_0c038cc4;
case 0x0c038cc6u: goto P_0c038cc6;
case 0x0c038cc8u: goto P_0c038cc8;
case 0x0c038ccau: goto P_0c038cca;
case 0x0c038cccu: goto P_0c038ccc;
case 0x0c038cceu: goto P_0c038cce;
case 0x0c038cd0u: goto P_0c038cd0;
case 0x0c038cd2u: goto P_0c038cd2;
case 0x0c038cd4u: goto P_0c038cd4;
case 0x0c038cd6u: goto P_0c038cd6;
case 0x0c038cd8u: goto P_0c038cd8;
case 0x0c038ce0u: goto P_0c038ce0;
case 0x0c038ce2u: goto P_0c038ce2;
case 0x0c038ce4u: goto P_0c038ce4;
case 0x0c038fe0u: goto P_0c038fe0;
case 0x0c038fe2u: goto P_0c038fe2;
case 0x0c038fe4u: goto P_0c038fe4;
case 0x0c038fe6u: goto P_0c038fe6;
case 0x0c038fe8u: goto P_0c038fe8;
case 0x0c038feau: goto P_0c038fea;
case 0x0c038fecu: goto P_0c038fec;
case 0x0c038feeu: goto P_0c038fee;
case 0x0c038ff0u: goto P_0c038ff0;
case 0x0c038ff2u: goto P_0c038ff2;
case 0x0c038ff4u: goto P_0c038ff4;
case 0x0c038ff6u: goto P_0c038ff6;
case 0x0c038ff8u: goto P_0c038ff8;
case 0x0c038ffau: goto P_0c038ffa;
case 0x0c038ffcu: goto P_0c038ffc;
case 0x0c038ffeu: goto P_0c038ffe;
case 0x0c039000u: goto P_0c039000;
case 0x0c039002u: goto P_0c039002;
case 0x0c039004u: goto P_0c039004;
case 0x0c039006u: goto P_0c039006;
case 0x0c039008u: goto P_0c039008;
case 0x0c03900au: goto P_0c03900a;
case 0x0c03900cu: goto P_0c03900c;
case 0x0c03900eu: goto P_0c03900e;
case 0x0c039010u: goto P_0c039010;
case 0x0c039012u: goto P_0c039012;
case 0x0c039014u: goto P_0c039014;
case 0x0c039016u: goto P_0c039016;
case 0x0c039018u: goto P_0c039018;
case 0x0c03901au: goto P_0c03901a;
case 0x0c03901cu: goto P_0c03901c;
case 0x0c03901eu: goto P_0c03901e;
case 0x0c039020u: goto P_0c039020;
case 0x0c039022u: goto P_0c039022;
case 0x0c039024u: goto P_0c039024;
case 0x0c039030u: goto P_0c039030;
case 0x0c039032u: goto P_0c039032;
case 0x0c039034u: goto P_0c039034;
case 0x0c039036u: goto P_0c039036;
case 0x0c039038u: goto P_0c039038;
case 0x0c03903au: goto P_0c03903a;
case 0x0c03903cu: goto P_0c03903c;
case 0x0c03903eu: goto P_0c03903e;
case 0x0c039040u: goto P_0c039040;
case 0x0c039042u: goto P_0c039042;
case 0x0c039044u: goto P_0c039044;
case 0x0c039046u: goto P_0c039046;
case 0x0c039048u: goto P_0c039048;
case 0x0c03904au: goto P_0c03904a;
case 0x0c03904cu: goto P_0c03904c;
case 0x0c03904eu: goto P_0c03904e;
case 0x0c039050u: goto P_0c039050;
case 0x0c039052u: goto P_0c039052;
case 0x0c039054u: goto P_0c039054;
case 0x0c039056u: goto P_0c039056;
case 0x0c039058u: goto P_0c039058;
case 0x0c03905au: goto P_0c03905a;
case 0x0c03905cu: goto P_0c03905c;
case 0x0c03905eu: goto P_0c03905e;
case 0x0c039060u: goto P_0c039060;
case 0x0c039062u: goto P_0c039062;
case 0x0c039064u: goto P_0c039064;
case 0x0c039066u: goto P_0c039066;
case 0x0c039068u: goto P_0c039068;
case 0x0c03906au: goto P_0c03906a;
case 0x0c03906cu: goto P_0c03906c;
case 0x0c03906eu: goto P_0c03906e;
case 0x0c039070u: goto P_0c039070;
case 0x0c039072u: goto P_0c039072;
case 0x0c039074u: goto P_0c039074;
case 0x0c039076u: goto P_0c039076;
case 0x0c039078u: goto P_0c039078;
case 0x0c03907au: goto P_0c03907a;
case 0x0c03907cu: goto P_0c03907c;
case 0x0c03907eu: goto P_0c03907e;
case 0x0c03a140u: goto P_0c03a140;
case 0x0c03a142u: goto P_0c03a142;
case 0x0c03a144u: goto P_0c03a144;
case 0x0c03a146u: goto P_0c03a146;
case 0x0c03a148u: goto P_0c03a148;
case 0x0c03a14au: goto P_0c03a14a;
case 0x0c03a14cu: goto P_0c03a14c;
case 0x0c03a14eu: goto P_0c03a14e;
case 0x0c03a150u: goto P_0c03a150;
case 0x0c03a152u: goto P_0c03a152;
case 0x0c03a154u: goto P_0c03a154;
case 0x0c03a156u: goto P_0c03a156;
case 0x0c03a6e0u: goto P_0c03a6e0;
case 0x0c03a6e2u: goto P_0c03a6e2;
case 0x0c03a6e4u: goto P_0c03a6e4;
case 0x0c03a6e6u: goto P_0c03a6e6;
case 0x0c03a6e8u: goto P_0c03a6e8;
case 0x0c03a6eau: goto P_0c03a6ea;
case 0x0c03a6ecu: goto P_0c03a6ec;
case 0x0c03a6eeu: goto P_0c03a6ee;
case 0x0c03a6f0u: goto P_0c03a6f0;
case 0x0c03a6f2u: goto P_0c03a6f2;
case 0x0c03a6f4u: goto P_0c03a6f4;
case 0x0c03a6f6u: goto P_0c03a6f6;
case 0x0c03a6f8u: goto P_0c03a6f8;
case 0x0c03a6fau: goto P_0c03a6fa;
case 0x0c03a6fcu: goto P_0c03a6fc;
case 0x0c03a6feu: goto P_0c03a6fe;
case 0x0c03a700u: goto P_0c03a700;
case 0x0c03a702u: goto P_0c03a702;
case 0x0c03a704u: goto P_0c03a704;
case 0x0c03a706u: goto P_0c03a706;
case 0x0c03a708u: goto P_0c03a708;
case 0x0c03a70au: goto P_0c03a70a;
case 0x0c03a70cu: goto P_0c03a70c;
case 0x0c03a70eu: goto P_0c03a70e;
case 0x0c03a710u: goto P_0c03a710;
case 0x0c03a712u: goto P_0c03a712;
case 0x0c03a714u: goto P_0c03a714;
case 0x0c03a716u: goto P_0c03a716;
case 0x0c03a718u: goto P_0c03a718;
case 0x0c03a71au: goto P_0c03a71a;
case 0x0c03a71cu: goto P_0c03a71c;
case 0x0c03a71eu: goto P_0c03a71e;
case 0x0c03a720u: goto P_0c03a720;
case 0x0c03a722u: goto P_0c03a722;
case 0x0c03a724u: goto P_0c03a724;
case 0x0c03a726u: goto P_0c03a726;
case 0x0c03a728u: goto P_0c03a728;
case 0x0c03a72au: goto P_0c03a72a;
case 0x0c03a72cu: goto P_0c03a72c;
case 0x0c03a72eu: goto P_0c03a72e;
case 0x0c03a730u: goto P_0c03a730;
case 0x0c03a732u: goto P_0c03a732;
case 0x0c03a734u: goto P_0c03a734;
case 0x0c03a736u: goto P_0c03a736;
case 0x0c03a738u: goto P_0c03a738;
case 0x0c03a73au: goto P_0c03a73a;
case 0x0c03a73cu: goto P_0c03a73c;
case 0x0c03a73eu: goto P_0c03a73e;
case 0x0c03a740u: goto P_0c03a740;
case 0x0c03a742u: goto P_0c03a742;
case 0x0c03a744u: goto P_0c03a744;
case 0x0c03a746u: goto P_0c03a746;
case 0x0c03a748u: goto P_0c03a748;
case 0x0c03a74au: goto P_0c03a74a;
case 0x0c03a750u: goto P_0c03a750;
case 0x0c03a752u: goto P_0c03a752;
case 0x0c03a754u: goto P_0c03a754;
case 0x0c03a756u: goto P_0c03a756;
case 0x0c03b300u: goto P_0c03b300;
case 0x0c03b302u: goto P_0c03b302;
case 0x0c03b304u: goto P_0c03b304;
case 0x0c03b306u: goto P_0c03b306;
case 0x0c03b308u: goto P_0c03b308;
case 0x0c03b30au: goto P_0c03b30a;
case 0x0c03b30cu: goto P_0c03b30c;
case 0x0c03b30eu: goto P_0c03b30e;
case 0x0c03b310u: goto P_0c03b310;
case 0x0c03b312u: goto P_0c03b312;
case 0x0c03b314u: goto P_0c03b314;
case 0x0c03b316u: goto P_0c03b316;
case 0x0c03b318u: goto P_0c03b318;
case 0x0c03b31au: goto P_0c03b31a;
case 0x0c03b31cu: goto P_0c03b31c;
case 0x0c03b31eu: goto P_0c03b31e;
case 0x0c03b320u: goto P_0c03b320;
case 0x0c03b322u: goto P_0c03b322;
case 0x0c03b324u: goto P_0c03b324;
case 0x0c03b326u: goto P_0c03b326;
case 0x0c03b328u: goto P_0c03b328;
case 0x0c03b32au: goto P_0c03b32a;
case 0x0c03b32cu: goto P_0c03b32c;
case 0x0c03b32eu: goto P_0c03b32e;
case 0x0c03b330u: goto P_0c03b330;
case 0x0c03b332u: goto P_0c03b332;
case 0x0c03b334u: goto P_0c03b334;
case 0x0c03b336u: goto P_0c03b336;
case 0x0c03b338u: goto P_0c03b338;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c038cb0: /* original 4f22, guest PC 0x0c038cb0 */
if(!s->budget--) { s->failed_pc=0x0c038cb0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c038cb2;
P_0c038cb2: /* original d118, guest PC 0x0c038cb2 */
if(!s->budget--) { s->failed_pc=0x0c038cb2u; return 0; }
r[1]=read(ram,0x0c038d14u,4);
goto P_0c038cb4;
P_0c038cb4: /* original e301, guest PC 0x0c038cb4 */
if(!s->budget--) { s->failed_pc=0x0c038cb4u; return 0; }
r[3]=0x00000001u;
goto P_0c038cb6;
P_0c038cb6: /* original d218, guest PC 0x0c038cb6 */
if(!s->budget--) { s->failed_pc=0x0c038cb6u; return 0; }
r[2]=read(ram,0x0c038d18u,4);
goto P_0c038cb8;
P_0c038cb8: /* original 420b, guest PC 0x0c038cb8 */
if(!s->budget--) { s->failed_pc=0x0c038cb8u; return 0; }
target=r[2];
r[16]=code_base|0x0c038cbcu;
write(ram,r[1],r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c038cbcu) { target=s->pc; goto dispatch; }
goto P_0c038cbc;
P_0c038cba: /* original 2132, guest PC 0x0c038cba */
if(!s->budget--) { s->failed_pc=0x0c038cbau; return 0; }
write(ram,r[1],r[3],4);
goto P_0c038cbc;
P_0c038cbc: /* original d317, guest PC 0x0c038cbc */
if(!s->budget--) { s->failed_pc=0x0c038cbcu; return 0; }
r[3]=read(ram,0x0c038d1cu,4);
goto P_0c038cbe;
P_0c038cbe: /* original e000, guest PC 0x0c038cbe */
if(!s->budget--) { s->failed_pc=0x0c038cbeu; return 0; }
r[0]=0x00000000u;
goto P_0c038cc0;
P_0c038cc0: /* original d214, guest PC 0x0c038cc0 */
if(!s->budget--) { s->failed_pc=0x0c038cc0u; return 0; }
r[2]=read(ram,0x0c038d14u,4);
goto P_0c038cc2;
P_0c038cc2: /* original 430b, guest PC 0x0c038cc2 */
if(!s->budget--) { s->failed_pc=0x0c038cc2u; return 0; }
target=r[3];
r[16]=code_base|0x0c038cc6u;
write(ram,r[2],r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c038cc6u) { target=s->pc; goto dispatch; }
goto P_0c038cc6;
P_0c038cc4: /* original 2202, guest PC 0x0c038cc4 */
if(!s->budget--) { s->failed_pc=0x0c038cc4u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c038cc6;
P_0c038cc6: /* original d416, guest PC 0x0c038cc6 */
if(!s->budget--) { s->failed_pc=0x0c038cc6u; return 0; }
r[4]=read(ram,0x0c038d20u,4);
goto P_0c038cc8;
P_0c038cc8: /* original 6240, guest PC 0x0c038cc8 */
if(!s->budget--) { s->failed_pc=0x0c038cc8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c038cca;
P_0c038cca: /* original 2228, guest PC 0x0c038cca */
if(!s->budget--) { s->failed_pc=0x0c038ccau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c038ccc;
P_0c038ccc: /* original 8908, guest PC 0x0c038ccc */
if(!s->budget--) { s->failed_pc=0x0c038cccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c038ce0; }
goto P_0c038cce;
P_0c038cce: /* original e100, guest PC 0x0c038cce */
if(!s->budget--) { s->failed_pc=0x0c038cceu; return 0; }
r[1]=0x00000000u;
goto P_0c038cd0;
P_0c038cd0: /* original 2410, guest PC 0x0c038cd0 */
if(!s->budget--) { s->failed_pc=0x0c038cd0u; return 0; }
write(ram,r[4],r[1],1);
goto P_0c038cd2;
P_0c038cd2: /* original d315, guest PC 0x0c038cd2 */
if(!s->budget--) { s->failed_pc=0x0c038cd2u; return 0; }
r[3]=read(ram,0x0c038d28u,4);
goto P_0c038cd4;
P_0c038cd4: /* original d413, guest PC 0x0c038cd4 */
if(!s->budget--) { s->failed_pc=0x0c038cd4u; return 0; }
r[4]=read(ram,0x0c038d24u,4);
goto P_0c038cd6;
P_0c038cd6: /* original 432b, guest PC 0x0c038cd6 */
if(!s->budget--) { s->failed_pc=0x0c038cd6u; return 0; }
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
P_0c038cd8: /* original 4f26, guest PC 0x0c038cd8 */
if(!s->budget--) { s->failed_pc=0x0c038cd8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c038cdau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038cdau; return 0; } return 1;
P_0c038ce0: /* original 4f26, guest PC 0x0c038ce0 */
if(!s->budget--) { s->failed_pc=0x0c038ce0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c038ce2;
P_0c038ce2: /* original 000b, guest PC 0x0c038ce2 */
if(!s->budget--) { s->failed_pc=0x0c038ce2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c038ce4: /* original 0009, guest PC 0x0c038ce4 */
if(!s->budget--) { s->failed_pc=0x0c038ce4u; return 0; }
if(!vf3_matrix_family(0x0c038ce6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038ce6u; return 0; } return 1;
P_0c038fe0: /* original 2fc6, guest PC 0x0c038fe0 */
if(!s->budget--) { s->failed_pc=0x0c038fe0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038fe2;
P_0c038fe2: /* original e004, guest PC 0x0c038fe2 */
if(!s->budget--) { s->failed_pc=0x0c038fe2u; return 0; }
r[0]=0x00000004u;
goto P_0c038fe4;
P_0c038fe4: /* original 4f22, guest PC 0x0c038fe4 */
if(!s->budget--) { s->failed_pc=0x0c038fe4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c038fe6;
P_0c038fe6: /* original d74c, guest PC 0x0c038fe6 */
if(!s->budget--) { s->failed_pc=0x0c038fe6u; return 0; }
r[7]=read(ram,0x0c039118u,4);
goto P_0c038fe8;
P_0c038fe8: /* original 7f94, guest PC 0x0c038fe8 */
if(!s->budget--) { s->failed_pc=0x0c038fe8u; return 0; }
r[15]+=0xffffff94u;
goto P_0c038fea;
P_0c038fea: /* original 2742, guest PC 0x0c038fea */
if(!s->budget--) { s->failed_pc=0x0c038feau; return 0; }
write(ram,r[7],r[4],4);
goto P_0c038fec;
P_0c038fec: /* original 1751, guest PC 0x0c038fec */
if(!s->budget--) { s->failed_pc=0x0c038fecu; return 0; }
write(ram,r[7]+4,r[5],4);
goto P_0c038fee;
P_0c038fee: /* original 1762, guest PC 0x0c038fee */
if(!s->budget--) { s->failed_pc=0x0c038feeu; return 0; }
write(ram,r[7]+8,r[6],4);
goto P_0c038ff0;
P_0c038ff0: /* original 67f3, guest PC 0x0c038ff0 */
if(!s->budget--) { s->failed_pc=0x0c038ff0u; return 0; }
r[7]=r[15];
goto P_0c038ff2;
P_0c038ff2: /* original 770c, guest PC 0x0c038ff2 */
if(!s->budget--) { s->failed_pc=0x0c038ff2u; return 0; }
r[7]+=0x0000000cu;
goto P_0c038ff4;
P_0c038ff4: /* original d349, guest PC 0x0c038ff4 */
if(!s->budget--) { s->failed_pc=0x0c038ff4u; return 0; }
r[3]=read(ram,0x0c03911cu,4);
goto P_0c038ff6;
P_0c038ff6: /* original 6273, guest PC 0x0c038ff6 */
if(!s->budget--) { s->failed_pc=0x0c038ff6u; return 0; }
r[2]=r[7];
goto P_0c038ff8;
P_0c038ff8: /* original 6123, guest PC 0x0c038ff8 */
if(!s->budget--) { s->failed_pc=0x0c038ff8u; return 0; }
r[1]=r[2];
goto P_0c038ffa;
P_0c038ffa: /* original 7120, guest PC 0x0c038ffa */
if(!s->budget--) { s->failed_pc=0x0c038ffau; return 0; }
r[1]+=0x00000020u;
goto P_0c038ffc;
P_0c038ffc: /* original 2232, guest PC 0x0c038ffc */
if(!s->budget--) { s->failed_pc=0x0c038ffcu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c038ffe;
P_0c038ffe: /* original f48d, guest PC 0x0c038ffe */
if(!s->budget--) { s->failed_pc=0x0c038ffeu; return 0; }
fr[4]=0;
goto P_0c039000;
P_0c039000: /* original f247, guest PC 0x0c039000 */
if(!s->budget--) { s->failed_pc=0x0c039000u; return 0; }
vf3_matrix_store(s,ram,4,r[2]+r[0]);
goto P_0c039002;
P_0c039002: /* original e008, guest PC 0x0c039002 */
if(!s->budget--) { s->failed_pc=0x0c039002u; return 0; }
r[0]=0x00000008u;
goto P_0c039004;
P_0c039004: /* original f247, guest PC 0x0c039004 */
if(!s->budget--) { s->failed_pc=0x0c039004u; return 0; }
vf3_matrix_store(s,ram,4,r[2]+r[0]);
goto P_0c039006;
P_0c039006: /* original c746, guest PC 0x0c039006 */
if(!s->budget--) { s->failed_pc=0x0c039006u; return 0; }
r[0]=code_base|0x00039120u;
goto P_0c039008;
P_0c039008: /* original f508, guest PC 0x0c039008 */
if(!s->budget--) { s->failed_pc=0x0c039008u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c03900a;
P_0c03900a: /* original e00c, guest PC 0x0c03900a */
if(!s->budget--) { s->failed_pc=0x0c03900au; return 0; }
r[0]=0x0000000cu;
goto P_0c03900c;
P_0c03900c: /* original f257, guest PC 0x0c03900c */
if(!s->budget--) { s->failed_pc=0x0c03900cu; return 0; }
vf3_matrix_store(s,ram,5,r[2]+r[0]);
goto P_0c03900e;
P_0c03900e: /* original 1244, guest PC 0x0c03900e */
if(!s->budget--) { s->failed_pc=0x0c03900eu; return 0; }
write(ram,r[2]+16,r[4],4);
goto P_0c039010;
P_0c039010: /* original 1246, guest PC 0x0c039010 */
if(!s->budget--) { s->failed_pc=0x0c039010u; return 0; }
write(ram,r[2]+24,r[4],4);
goto P_0c039012;
P_0c039012: /* original 2132, guest PC 0x0c039012 */
if(!s->budget--) { s->failed_pc=0x0c039012u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c039014;
P_0c039014: /* original dc43, guest PC 0x0c039014 */
if(!s->budget--) { s->failed_pc=0x0c039014u; return 0; }
r[12]=read(ram,0x0c039124u,4);
goto P_0c039016;
P_0c039016: /* original 85c2, guest PC 0x0c039016 */
if(!s->budget--) { s->failed_pc=0x0c039016u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+4,2);
goto P_0c039018;
P_0c039018: /* original 6403, guest PC 0x0c039018 */
if(!s->budget--) { s->failed_pc=0x0c039018u; return 0; }
r[4]=r[0];
goto P_0c03901a;
P_0c03901a: /* original 85c5, guest PC 0x0c03901a */
if(!s->budget--) { s->failed_pc=0x0c03901au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+10,2);
goto P_0c03901c;
P_0c03901c: /* original 2008, guest PC 0x0c03901c */
if(!s->budget--) { s->failed_pc=0x0c03901cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c03901e;
P_0c03901e: /* original 8907, guest PC 0x0c03901e */
if(!s->budget--) { s->failed_pc=0x0c03901eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c039030; }
goto P_0c039020;
P_0c039020: /* original 644f, guest PC 0x0c039020 */
if(!s->budget--) { s->failed_pc=0x0c039020u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c039022;
P_0c039022: /* original a006, guest PC 0x0c039022 */
if(!s->budget--) { s->failed_pc=0x0c039022u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c039032;
P_0c039024: /* original 4400, guest PC 0x0c039024 */
if(!s->budget--) { s->failed_pc=0x0c039024u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
if(!vf3_matrix_family(0x0c039026u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c039026u; return 0; } return 1;
P_0c039030: /* original 644f, guest PC 0x0c039030 */
if(!s->budget--) { s->failed_pc=0x0c039030u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c039032;
P_0c039032: /* original 445a, guest PC 0x0c039032 */
if(!s->budget--) { s->failed_pc=0x0c039032u; return 0; }
r[53]=r[4];
goto P_0c039034;
P_0c039034: /* original e004, guest PC 0x0c039034 */
if(!s->budget--) { s->failed_pc=0x0c039034u; return 0; }
r[0]=0x00000004u;
goto P_0c039036;
P_0c039036: /* original 6473, guest PC 0x0c039036 */
if(!s->budget--) { s->failed_pc=0x0c039036u; return 0; }
r[4]=r[7];
goto P_0c039038;
P_0c039038: /* original 7440, guest PC 0x0c039038 */
if(!s->budget--) { s->failed_pc=0x0c039038u; return 0; }
r[4]+=0x00000040u;
goto P_0c03903a;
P_0c03903a: /* original f32d, guest PC 0x0c03903a */
if(!s->budget--) { s->failed_pc=0x0c03903au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03903c;
P_0c03903c: /* original f137, guest PC 0x0c03903c */
if(!s->budget--) { s->failed_pc=0x0c03903cu; return 0; }
vf3_matrix_store(s,ram,3,r[1]+r[0]);
goto P_0c03903e;
P_0c03903e: /* original e008, guest PC 0x0c03903e */
if(!s->budget--) { s->failed_pc=0x0c03903eu; return 0; }
r[0]=0x00000008u;
goto P_0c039040;
P_0c039040: /* original f147, guest PC 0x0c039040 */
if(!s->budget--) { s->failed_pc=0x0c039040u; return 0; }
vf3_matrix_store(s,ram,4,r[1]+r[0]);
goto P_0c039042;
P_0c039042: /* original e00c, guest PC 0x0c039042 */
if(!s->budget--) { s->failed_pc=0x0c039042u; return 0; }
r[0]=0x0000000cu;
goto P_0c039044;
P_0c039044: /* original f157, guest PC 0x0c039044 */
if(!s->budget--) { s->failed_pc=0x0c039044u; return 0; }
vf3_matrix_store(s,ram,5,r[1]+r[0]);
goto P_0c039046;
P_0c039046: /* original e004, guest PC 0x0c039046 */
if(!s->budget--) { s->failed_pc=0x0c039046u; return 0; }
r[0]=0x00000004u;
goto P_0c039048;
P_0c039048: /* original 1154, guest PC 0x0c039048 */
if(!s->budget--) { s->failed_pc=0x0c039048u; return 0; }
write(ram,r[1]+16,r[5],4);
goto P_0c03904a;
P_0c03904a: /* original 1156, guest PC 0x0c03904a */
if(!s->budget--) { s->failed_pc=0x0c03904au; return 0; }
write(ram,r[1]+24,r[5],4);
goto P_0c03904c;
P_0c03904c: /* original e500, guest PC 0x0c03904c */
if(!s->budget--) { s->failed_pc=0x0c03904cu; return 0; }
r[5]=0x00000000u;
goto P_0c03904e;
P_0c03904e: /* original d336, guest PC 0x0c03904e */
if(!s->budget--) { s->failed_pc=0x0c03904eu; return 0; }
r[3]=read(ram,0x0c039128u,4);
goto P_0c039050;
P_0c039050: /* original 2432, guest PC 0x0c039050 */
if(!s->budget--) { s->failed_pc=0x0c039050u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c039052;
P_0c039052: /* original f447, guest PC 0x0c039052 */
if(!s->budget--) { s->failed_pc=0x0c039052u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c039054;
P_0c039054: /* original 85c3, guest PC 0x0c039054 */
if(!s->budget--) { s->failed_pc=0x0c039054u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+6,2);
goto P_0c039056;
P_0c039056: /* original 6cf3, guest PC 0x0c039056 */
if(!s->budget--) { s->failed_pc=0x0c039056u; return 0; }
r[12]=r[15];
goto P_0c039058;
P_0c039058: /* original 6303, guest PC 0x0c039058 */
if(!s->budget--) { s->failed_pc=0x0c039058u; return 0; }
r[3]=r[0];
goto P_0c03905a;
P_0c03905a: /* original 435a, guest PC 0x0c03905a */
if(!s->budget--) { s->failed_pc=0x0c03905au; return 0; }
r[53]=r[3];
goto P_0c03905c;
P_0c03905c: /* original e008, guest PC 0x0c03905c */
if(!s->budget--) { s->failed_pc=0x0c03905cu; return 0; }
r[0]=0x00000008u;
goto P_0c03905e;
P_0c03905e: /* original f32d, guest PC 0x0c03905e */
if(!s->budget--) { s->failed_pc=0x0c03905eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c039060;
P_0c039060: /* original f437, guest PC 0x0c039060 */
if(!s->budget--) { s->failed_pc=0x0c039060u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c039062;
P_0c039062: /* original e00c, guest PC 0x0c039062 */
if(!s->budget--) { s->failed_pc=0x0c039062u; return 0; }
r[0]=0x0000000cu;
goto P_0c039064;
P_0c039064: /* original f457, guest PC 0x0c039064 */
if(!s->budget--) { s->failed_pc=0x0c039064u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c039066;
P_0c039066: /* original 1464, guest PC 0x0c039066 */
if(!s->budget--) { s->failed_pc=0x0c039066u; return 0; }
write(ram,r[4]+16,r[6],4);
goto P_0c039068;
P_0c039068: /* original 1466, guest PC 0x0c039068 */
if(!s->budget--) { s->failed_pc=0x0c039068u; return 0; }
write(ram,r[4]+24,r[6],4);
goto P_0c03906a;
P_0c03906a: /* original e620, guest PC 0x0c03906a */
if(!s->budget--) { s->failed_pc=0x0c03906au; return 0; }
r[6]=0x00000020u;
goto P_0c03906c;
P_0c03906c: /* original 2c22, guest PC 0x0c03906c */
if(!s->budget--) { s->failed_pc=0x0c03906cu; return 0; }
write(ram,r[12],r[2],4);
goto P_0c03906e;
P_0c03906e: /* original 1c11, guest PC 0x0c03906e */
if(!s->budget--) { s->failed_pc=0x0c03906eu; return 0; }
write(ram,r[12]+4,r[1],4);
goto P_0c039070;
P_0c039070: /* original 1c42, guest PC 0x0c039070 */
if(!s->budget--) { s->failed_pc=0x0c039070u; return 0; }
write(ram,r[12]+8,r[4],4);
goto P_0c039072;
P_0c039072: /* original d32e, guest PC 0x0c039072 */
if(!s->budget--) { s->failed_pc=0x0c039072u; return 0; }
r[3]=read(ram,0x0c03912cu,4);
goto P_0c039074;
P_0c039074: /* original 430b, guest PC 0x0c039074 */
if(!s->budget--) { s->failed_pc=0x0c039074u; return 0; }
target=r[3];
r[16]=code_base|0x0c039078u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c039078u) { target=s->pc; goto dispatch; }
goto P_0c039078;
P_0c039076: /* original 64c3, guest PC 0x0c039076 */
if(!s->budget--) { s->failed_pc=0x0c039076u; return 0; }
r[4]=r[12];
goto P_0c039078;
P_0c039078: /* original 7f6c, guest PC 0x0c039078 */
if(!s->budget--) { s->failed_pc=0x0c039078u; return 0; }
r[15]+=0x0000006cu;
goto P_0c03907a;
P_0c03907a: /* original 4f26, guest PC 0x0c03907a */
if(!s->budget--) { s->failed_pc=0x0c03907au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03907c;
P_0c03907c: /* original 000b, guest PC 0x0c03907c */
if(!s->budget--) { s->failed_pc=0x0c03907cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
s->pc=target; return ram->oob==0;
P_0c03907e: /* original 6cf6, guest PC 0x0c03907e */
if(!s->budget--) { s->failed_pc=0x0c03907eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
if(!vf3_matrix_family(0x0c039080u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c039080u; return 0; } return 1;
P_0c03a140: /* original 2fe6, guest PC 0x0c03a140 */
if(!s->budget--) { s->failed_pc=0x0c03a140u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03a142;
P_0c03a142: /* original 6e4d, guest PC 0x0c03a142 */
if(!s->budget--) { s->failed_pc=0x0c03a142u; return 0; }
r[14]=r[4]&65535u;
goto P_0c03a144;
P_0c03a144: /* original d337, guest PC 0x0c03a144 */
if(!s->budget--) { s->failed_pc=0x0c03a144u; return 0; }
r[3]=read(ram,0x0c03a224u,4);
goto P_0c03a146;
P_0c03a146: /* original 3e37, guest PC 0x0c03a146 */
if(!s->budget--) { s->failed_pc=0x0c03a146u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[3])!=0);
goto P_0c03a148;
P_0c03a148: /* original 8b02, guest PC 0x0c03a148 */
if(!s->budget--) { s->failed_pc=0x0c03a148u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a150; }
goto P_0c03a14a;
P_0c03a14a: /* original d137, guest PC 0x0c03a14a */
if(!s->budget--) { s->failed_pc=0x0c03a14au; return 0; }
r[1]=read(ram,0x0c03a228u,4);
goto P_0c03a14c;
P_0c03a14c: /* original 31e8, guest PC 0x0c03a14c */
if(!s->budget--) { s->failed_pc=0x0c03a14cu; return 0; }
r[1]-=r[14];
goto P_0c03a14e;
P_0c03a14e: /* original 6e13, guest PC 0x0c03a14e */
if(!s->budget--) { s->failed_pc=0x0c03a14eu; return 0; }
r[14]=r[1];
goto P_0c03a150;
P_0c03a150: /* original 9466, guest PC 0x0c03a150 */
if(!s->budget--) { s->failed_pc=0x0c03a150u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03a220u,2);
goto P_0c03a152;
P_0c03a152: /* original 34e8, guest PC 0x0c03a152 */
if(!s->budget--) { s->failed_pc=0x0c03a152u; return 0; }
r[4]-=r[14];
goto P_0c03a154;
P_0c03a154: /* original a2c4, guest PC 0x0c03a154 */
if(!s->budget--) { s->failed_pc=0x0c03a154u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c03a6e0;
P_0c03a156: /* original 6ef6, guest PC 0x0c03a156 */
if(!s->budget--) { s->failed_pc=0x0c03a156u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03a158u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a158u; return 0; } return 1;
P_0c03a6e0: /* original 644d, guest PC 0x0c03a6e0 */
if(!s->budget--) { s->failed_pc=0x0c03a6e0u; return 0; }
r[4]=r[4]&65535u;
goto P_0c03a6e2;
P_0c03a6e2: /* original 445a, guest PC 0x0c03a6e2 */
if(!s->budget--) { s->failed_pc=0x0c03a6e2u; return 0; }
r[53]=r[4];
goto P_0c03a6e4;
P_0c03a6e4: /* original c78d, guest PC 0x0c03a6e4 */
if(!s->budget--) { s->failed_pc=0x0c03a6e4u; return 0; }
r[0]=code_base|0x0003a91cu;
goto P_0c03a6e6;
P_0c03a6e6: /* original f708, guest PC 0x0c03a6e6 */
if(!s->budget--) { s->failed_pc=0x0c03a6e6u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c03a6e8;
P_0c03a6e8: /* original c78d, guest PC 0x0c03a6e8 */
if(!s->budget--) { s->failed_pc=0x0c03a6e8u; return 0; }
r[0]=code_base|0x0003a920u;
goto P_0c03a6ea;
P_0c03a6ea: /* original f208, guest PC 0x0c03a6ea */
if(!s->budget--) { s->failed_pc=0x0c03a6eau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03a6ec;
P_0c03a6ec: /* original c78d, guest PC 0x0c03a6ec */
if(!s->budget--) { s->failed_pc=0x0c03a6ecu; return 0; }
r[0]=code_base|0x0003a924u;
goto P_0c03a6ee;
P_0c03a6ee: /* original f32d, guest PC 0x0c03a6ee */
if(!s->budget--) { s->failed_pc=0x0c03a6eeu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a6f0;
P_0c03a6f0: /* original f108, guest PC 0x0c03a6f0 */
if(!s->budget--) { s->failed_pc=0x0c03a6f0u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c03a6f2;
P_0c03a6f2: /* original c78d, guest PC 0x0c03a6f2 */
if(!s->budget--) { s->failed_pc=0x0c03a6f2u; return 0; }
r[0]=code_base|0x0003a928u;
goto P_0c03a6f4;
P_0c03a6f4: /* original f508, guest PC 0x0c03a6f4 */
if(!s->budget--) { s->failed_pc=0x0c03a6f4u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c03a6f6;
P_0c03a6f6: /* original c78d, guest PC 0x0c03a6f6 */
if(!s->budget--) { s->failed_pc=0x0c03a6f6u; return 0; }
r[0]=code_base|0x0003a92cu;
goto P_0c03a6f8;
P_0c03a6f8: /* original f008, guest PC 0x0c03a6f8 */
if(!s->budget--) { s->failed_pc=0x0c03a6f8u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c03a6fa;
P_0c03a6fa: /* original e40b, guest PC 0x0c03a6fa */
if(!s->budget--) { s->failed_pc=0x0c03a6fau; return 0; }
r[4]=0x0000000bu;
goto P_0c03a6fc;
P_0c03a6fc: /* original e503, guest PC 0x0c03a6fc */
if(!s->budget--) { s->failed_pc=0x0c03a6fcu; return 0; }
r[5]=0x00000003u;
goto P_0c03a6fe;
P_0c03a6fe: /* original f322, guest PC 0x0c03a6fe */
if(!s->budget--) { s->failed_pc=0x0c03a6feu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c03a700;
P_0c03a700: /* original f313, guest PC 0x0c03a700 */
if(!s->budget--) { s->failed_pc=0x0c03a700u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'/');
goto P_0c03a702;
P_0c03a702: /* original f43c, guest PC 0x0c03a702 */
if(!s->budget--) { s->failed_pc=0x0c03a702u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c03a704;
P_0c03a704: /* original f473, guest PC 0x0c03a704 */
if(!s->budget--) { s->failed_pc=0x0c03a704u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'/');
goto P_0c03a706;
P_0c03a706: /* original f34c, guest PC 0x0c03a706 */
if(!s->budget--) { s->failed_pc=0x0c03a706u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03a708;
P_0c03a708: /* original f353, guest PC 0x0c03a708 */
if(!s->budget--) { s->failed_pc=0x0c03a708u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'/');
goto P_0c03a70a;
P_0c03a70a: /* original f300, guest PC 0x0c03a70a */
if(!s->budget--) { s->failed_pc=0x0c03a70au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'+');
goto P_0c03a70c;
P_0c03a70c: /* original f33d, guest PC 0x0c03a70c */
if(!s->budget--) { s->failed_pc=0x0c03a70cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03a70e;
P_0c03a70e: /* original 065a, guest PC 0x0c03a70e */
if(!s->budget--) { s->failed_pc=0x0c03a70eu; return 0; }
r[6]=r[53];
goto P_0c03a710;
P_0c03a710: /* original 465a, guest PC 0x0c03a710 */
if(!s->budget--) { s->failed_pc=0x0c03a710u; return 0; }
r[53]=r[6];
goto P_0c03a712;
P_0c03a712: /* original f32d, guest PC 0x0c03a712 */
if(!s->budget--) { s->failed_pc=0x0c03a712u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a714;
P_0c03a714: /* original f352, guest PC 0x0c03a714 */
if(!s->budget--) { s->failed_pc=0x0c03a714u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03a716;
P_0c03a716: /* original f58d, guest PC 0x0c03a716 */
if(!s->budget--) { s->failed_pc=0x0c03a716u; return 0; }
fr[5]=0;
goto P_0c03a718;
P_0c03a718: /* original f431, guest PC 0x0c03a718 */
if(!s->budget--) { s->failed_pc=0x0c03a718u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c03a71a;
P_0c03a71a: /* original f64c, guest PC 0x0c03a71a */
if(!s->budget--) { s->failed_pc=0x0c03a71au; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c03a71c;
P_0c03a71c: /* original f642, guest PC 0x0c03a71c */
if(!s->budget--) { s->failed_pc=0x0c03a71cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c03a71e;
P_0c03a71e: /* original 445a, guest PC 0x0c03a71e */
if(!s->budget--) { s->failed_pc=0x0c03a71eu; return 0; }
r[53]=r[4];
goto P_0c03a720;
P_0c03a720: /* original 74fe, guest PC 0x0c03a720 */
if(!s->budget--) { s->failed_pc=0x0c03a720u; return 0; }
r[4]+=0xfffffffeu;
goto P_0c03a722;
P_0c03a722: /* original 3453, guest PC 0x0c03a722 */
if(!s->budget--) { s->failed_pc=0x0c03a722u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c03a724;
P_0c03a724: /* original f22d, guest PC 0x0c03a724 */
if(!s->budget--) { s->failed_pc=0x0c03a724u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a726;
P_0c03a726: /* original f251, guest PC 0x0c03a726 */
if(!s->budget--) { s->failed_pc=0x0c03a726u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c03a728;
P_0c03a728: /* original f56c, guest PC 0x0c03a728 */
if(!s->budget--) { s->failed_pc=0x0c03a728u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c03a72a;
P_0c03a72a: /* original 8df8, guest PC 0x0c03a72a */
if(!s->budget--) { s->failed_pc=0x0c03a72au; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
if(cond) { goto P_0c03a71e; }
goto P_0c03a72e;
P_0c03a72c: /* original f523, guest PC 0x0c03a72c */
if(!s->budget--) { s->failed_pc=0x0c03a72cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
goto P_0c03a72e;
P_0c03a72e: /* original f69d, guest PC 0x0c03a72e */
if(!s->budget--) { s->failed_pc=0x0c03a72eu; return 0; }
fr[6]=0x3f800000u;
goto P_0c03a730;
P_0c03a730: /* original e301, guest PC 0x0c03a730 */
if(!s->budget--) { s->failed_pc=0x0c03a730u; return 0; }
r[3]=0x00000001u;
goto P_0c03a732;
P_0c03a732: /* original f36c, guest PC 0x0c03a732 */
if(!s->budget--) { s->failed_pc=0x0c03a732u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c03a734;
P_0c03a734: /* original f351, guest PC 0x0c03a734 */
if(!s->budget--) { s->failed_pc=0x0c03a734u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c03a736;
P_0c03a736: /* original 2638, guest PC 0x0c03a736 */
if(!s->budget--) { s->failed_pc=0x0c03a736u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c03a738;
P_0c03a738: /* original f433, guest PC 0x0c03a738 */
if(!s->budget--) { s->failed_pc=0x0c03a738u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c03a73a;
P_0c03a73a: /* original f24c, guest PC 0x0c03a73a */
if(!s->budget--) { s->failed_pc=0x0c03a73au; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03a73c;
P_0c03a73c: /* original f272, guest PC 0x0c03a73c */
if(!s->budget--) { s->failed_pc=0x0c03a73cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c03a73e;
P_0c03a73e: /* original f04c, guest PC 0x0c03a73e */
if(!s->budget--) { s->failed_pc=0x0c03a73eu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c03a740;
P_0c03a740: /* original f64e, guest PC 0x0c03a740 */
if(!s->budget--) { s->failed_pc=0x0c03a740u; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[4],fr[6],r[18]);
goto P_0c03a742;
P_0c03a742: /* original f42c, guest PC 0x0c03a742 */
if(!s->budget--) { s->failed_pc=0x0c03a742u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c03a744;
P_0c03a744: /* original 8f04, guest PC 0x0c03a744 */
if(!s->budget--) { s->failed_pc=0x0c03a744u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
if(!cond) { goto P_0c03a750; }
goto P_0c03a748;
P_0c03a746: /* original f463, guest PC 0x0c03a746 */
if(!s->budget--) { s->failed_pc=0x0c03a746u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
goto P_0c03a748;
P_0c03a748: /* original 000b, guest PC 0x0c03a748 */
if(!s->budget--) { s->failed_pc=0x0c03a748u; return 0; }
target=r[16];
vf3_matrix_move(s,0,4);
s->pc=target; return ram->oob==0;
P_0c03a74a: /* original f04c, guest PC 0x0c03a74a */
if(!s->budget--) { s->failed_pc=0x0c03a74au; return 0; }
vf3_matrix_move(s,0,4);
if(!vf3_matrix_family(0x0c03a74cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a74cu; return 0; } return 1;
P_0c03a750: /* original f04c, guest PC 0x0c03a750 */
if(!s->budget--) { s->failed_pc=0x0c03a750u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c03a752;
P_0c03a752: /* original f04d, guest PC 0x0c03a752 */
if(!s->budget--) { s->failed_pc=0x0c03a752u; return 0; }
fr[0]^=0x80000000u;
goto P_0c03a754;
P_0c03a754: /* original 000b, guest PC 0x0c03a754 */
if(!s->budget--) { s->failed_pc=0x0c03a754u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03a756: /* original 0009, guest PC 0x0c03a756 */
if(!s->budget--) { s->failed_pc=0x0c03a756u; return 0; }
if(!vf3_matrix_family(0x0c03a758u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a758u; return 0; } return 1;
P_0c03b300: /* original 2fe6, guest PC 0x0c03b300 */
if(!s->budget--) { s->failed_pc=0x0c03b300u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03b302;
P_0c03b302: /* original 6743, guest PC 0x0c03b302 */
if(!s->budget--) { s->failed_pc=0x0c03b302u; return 0; }
r[7]=r[4];
goto P_0c03b304;
P_0c03b304: /* original 4f22, guest PC 0x0c03b304 */
if(!s->budget--) { s->failed_pc=0x0c03b304u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03b306;
P_0c03b306: /* original 4729, guest PC 0x0c03b306 */
if(!s->budget--) { s->failed_pc=0x0c03b306u; return 0; }
r[7]>>=16;
goto P_0c03b308;
P_0c03b308: /* original 6543, guest PC 0x0c03b308 */
if(!s->budget--) { s->failed_pc=0x0c03b308u; return 0; }
r[5]=r[4];
goto P_0c03b30a;
P_0c03b30a: /* original 4719, guest PC 0x0c03b30a */
if(!s->budget--) { s->failed_pc=0x0c03b30au; return 0; }
r[7]>>=8;
goto P_0c03b30c;
P_0c03b30c: /* original 6643, guest PC 0x0c03b30c */
if(!s->budget--) { s->failed_pc=0x0c03b30cu; return 0; }
r[6]=r[4];
goto P_0c03b30e;
P_0c03b30e: /* original 677e, guest PC 0x0c03b30e */
if(!s->budget--) { s->failed_pc=0x0c03b30eu; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)r[7];
goto P_0c03b310;
P_0c03b310: /* original 7ffc, guest PC 0x0c03b310 */
if(!s->budget--) { s->failed_pc=0x0c03b310u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03b312;
P_0c03b312: /* original 6073, guest PC 0x0c03b312 */
if(!s->budget--) { s->failed_pc=0x0c03b312u; return 0; }
r[0]=r[7];
goto P_0c03b314;
P_0c03b314: /* original 6ef3, guest PC 0x0c03b314 */
if(!s->budget--) { s->failed_pc=0x0c03b314u; return 0; }
r[14]=r[15];
goto P_0c03b316;
P_0c03b316: /* original 4529, guest PC 0x0c03b316 */
if(!s->budget--) { s->failed_pc=0x0c03b316u; return 0; }
r[5]>>=16;
goto P_0c03b318;
P_0c03b318: /* original 80e3, guest PC 0x0c03b318 */
if(!s->budget--) { s->failed_pc=0x0c03b318u; return 0; }
write(ram,r[14]+3,r[0],1);
goto P_0c03b31a;
P_0c03b31a: /* original 655f, guest PC 0x0c03b31a */
if(!s->budget--) { s->failed_pc=0x0c03b31au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c03b31c;
P_0c03b31c: /* original 6053, guest PC 0x0c03b31c */
if(!s->budget--) { s->failed_pc=0x0c03b31cu; return 0; }
r[0]=r[5];
goto P_0c03b31e;
P_0c03b31e: /* original e3f8, guest PC 0x0c03b31e */
if(!s->budget--) { s->failed_pc=0x0c03b31eu; return 0; }
r[3]=0xfffffff8u;
goto P_0c03b320;
P_0c03b320: /* original 80e2, guest PC 0x0c03b320 */
if(!s->budget--) { s->failed_pc=0x0c03b320u; return 0; }
write(ram,r[14]+2,r[0],1);
goto P_0c03b322;
P_0c03b322: /* original 463c, guest PC 0x0c03b322 */
if(!s->budget--) { s->failed_pc=0x0c03b322u; return 0; }
r[6]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[6]>>((-r[3])&31u)):((int32_t)r[6]<0?0xffffffffu:0)):r[6]<<(r[3]&31u);
goto P_0c03b324;
P_0c03b324: /* original 6063, guest PC 0x0c03b324 */
if(!s->budget--) { s->failed_pc=0x0c03b324u; return 0; }
r[0]=r[6];
goto P_0c03b326;
P_0c03b326: /* original 80e1, guest PC 0x0c03b326 */
if(!s->budget--) { s->failed_pc=0x0c03b326u; return 0; }
write(ram,r[14]+1,r[0],1);
goto P_0c03b328;
P_0c03b328: /* original 2e40, guest PC 0x0c03b328 */
if(!s->budget--) { s->failed_pc=0x0c03b328u; return 0; }
write(ram,r[14],r[4],1);
goto P_0c03b32a;
P_0c03b32a: /* original 63e2, guest PC 0x0c03b32a */
if(!s->budget--) { s->failed_pc=0x0c03b32au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03b32c;
P_0c03b32c: /* original d21e, guest PC 0x0c03b32c */
if(!s->budget--) { s->failed_pc=0x0c03b32cu; return 0; }
r[2]=read(ram,0x0c03b3a8u,4);
goto P_0c03b32e;
P_0c03b32e: /* original 420b, guest PC 0x0c03b32e */
if(!s->budget--) { s->failed_pc=0x0c03b32eu; return 0; }
target=r[2];
r[16]=code_base|0x0c03b332u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03b332u) { target=s->pc; goto dispatch; }
goto P_0c03b332;
P_0c03b330: /* original 2f36, guest PC 0x0c03b330 */
if(!s->budget--) { s->failed_pc=0x0c03b330u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03b332;
P_0c03b332: /* original 7f08, guest PC 0x0c03b332 */
if(!s->budget--) { s->failed_pc=0x0c03b332u; return 0; }
r[15]+=0x00000008u;
goto P_0c03b334;
P_0c03b334: /* original 4f26, guest PC 0x0c03b334 */
if(!s->budget--) { s->failed_pc=0x0c03b334u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03b336;
P_0c03b336: /* original 000b, guest PC 0x0c03b336 */
if(!s->budget--) { s->failed_pc=0x0c03b336u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03b338: /* original 6ef6, guest PC 0x0c03b338 */
if(!s->budget--) { s->failed_pc=0x0c03b338u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03b33au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03b33au; return 0; } return 1;
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
unsupported: s->failed_pc=target; return 0;
}
