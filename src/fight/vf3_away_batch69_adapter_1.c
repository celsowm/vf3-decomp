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
int vf3_away_batch69_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c035ca4u: goto P_0c035ca4;
case 0x0c035ca6u: goto P_0c035ca6;
case 0x0c035ca8u: goto P_0c035ca8;
case 0x0c035caau: goto P_0c035caa;
case 0x0c035cacu: goto P_0c035cac;
case 0x0c035caeu: goto P_0c035cae;
case 0x0c035cb0u: goto P_0c035cb0;
case 0x0c035cb2u: goto P_0c035cb2;
case 0x0c035cb4u: goto P_0c035cb4;
case 0x0c035cb6u: goto P_0c035cb6;
case 0x0c035cb8u: goto P_0c035cb8;
case 0x0c035ce8u: goto P_0c035ce8;
case 0x0c035ceau: goto P_0c035cea;
case 0x0c035cecu: goto P_0c035cec;
case 0x0c035ceeu: goto P_0c035cee;
case 0x0c035cf0u: goto P_0c035cf0;
case 0x0c035cf2u: goto P_0c035cf2;
case 0x0c035cf4u: goto P_0c035cf4;
case 0x0c035cf6u: goto P_0c035cf6;
case 0x0c035cf8u: goto P_0c035cf8;
case 0x0c035cfau: goto P_0c035cfa;
case 0x0c035cfcu: goto P_0c035cfc;
case 0x0c035cfeu: goto P_0c035cfe;
case 0x0c036e78u: goto P_0c036e78;
case 0x0c036e7au: goto P_0c036e7a;
case 0x0c036e7cu: goto P_0c036e7c;
case 0x0c036e7eu: goto P_0c036e7e;
case 0x0c036e80u: goto P_0c036e80;
case 0x0c036e82u: goto P_0c036e82;
case 0x0c036e84u: goto P_0c036e84;
case 0x0c036e86u: goto P_0c036e86;
case 0x0c036e88u: goto P_0c036e88;
case 0x0c036e8au: goto P_0c036e8a;
case 0x0c036e8cu: goto P_0c036e8c;
case 0x0c036e8eu: goto P_0c036e8e;
case 0x0c036e90u: goto P_0c036e90;
case 0x0c036e92u: goto P_0c036e92;
case 0x0c036e94u: goto P_0c036e94;
case 0x0c036e96u: goto P_0c036e96;
case 0x0c036e98u: goto P_0c036e98;
case 0x0c036e9au: goto P_0c036e9a;
case 0x0c036e9cu: goto P_0c036e9c;
case 0x0c036e9eu: goto P_0c036e9e;
case 0x0c036ea0u: goto P_0c036ea0;
case 0x0c036ea2u: goto P_0c036ea2;
case 0x0c036ea4u: goto P_0c036ea4;
case 0x0c036ea6u: goto P_0c036ea6;
case 0x0c036ea8u: goto P_0c036ea8;
case 0x0c036eaau: goto P_0c036eaa;
case 0x0c036eacu: goto P_0c036eac;
case 0x0c036eaeu: goto P_0c036eae;
case 0x0c036eb0u: goto P_0c036eb0;
case 0x0c036eb2u: goto P_0c036eb2;
case 0x0c036eb4u: goto P_0c036eb4;
case 0x0c036eb6u: goto P_0c036eb6;
case 0x0c036eb8u: goto P_0c036eb8;
case 0x0c036ebau: goto P_0c036eba;
case 0x0c036ebcu: goto P_0c036ebc;
case 0x0c036ebeu: goto P_0c036ebe;
case 0x0c036ec0u: goto P_0c036ec0;
case 0x0c036ec2u: goto P_0c036ec2;
case 0x0c036ec4u: goto P_0c036ec4;
case 0x0c036ec6u: goto P_0c036ec6;
case 0x0c036ec8u: goto P_0c036ec8;
case 0x0c036ecau: goto P_0c036eca;
case 0x0c036eccu: goto P_0c036ecc;
case 0x0c036eceu: goto P_0c036ece;
case 0x0c036ed0u: goto P_0c036ed0;
case 0x0c036ed2u: goto P_0c036ed2;
case 0x0c036ed4u: goto P_0c036ed4;
case 0x0c036ed6u: goto P_0c036ed6;
case 0x0c036ed8u: goto P_0c036ed8;
case 0x0c036edau: goto P_0c036eda;
case 0x0c036edcu: goto P_0c036edc;
case 0x0c036edeu: goto P_0c036ede;
case 0x0c036ee0u: goto P_0c036ee0;
case 0x0c036ee2u: goto P_0c036ee2;
case 0x0c036ee4u: goto P_0c036ee4;
case 0x0c036ee6u: goto P_0c036ee6;
case 0x0c036ee8u: goto P_0c036ee8;
case 0x0c036eeau: goto P_0c036eea;
case 0x0c036eecu: goto P_0c036eec;
case 0x0c036eeeu: goto P_0c036eee;
case 0x0c036ef0u: goto P_0c036ef0;
case 0x0c036ef2u: goto P_0c036ef2;
case 0x0c036ef4u: goto P_0c036ef4;
case 0x0c036ef6u: goto P_0c036ef6;
case 0x0c036ef8u: goto P_0c036ef8;
case 0x0c036efau: goto P_0c036efa;
case 0x0c036efcu: goto P_0c036efc;
case 0x0c036efeu: goto P_0c036efe;
case 0x0c036f00u: goto P_0c036f00;
case 0x0c036f02u: goto P_0c036f02;
case 0x0c036f04u: goto P_0c036f04;
case 0x0c036f06u: goto P_0c036f06;
case 0x0c036f20u: goto P_0c036f20;
case 0x0c036f22u: goto P_0c036f22;
case 0x0c036f24u: goto P_0c036f24;
case 0x0c036f26u: goto P_0c036f26;
case 0x0c036f28u: goto P_0c036f28;
case 0x0c036f2au: goto P_0c036f2a;
case 0x0c036f2cu: goto P_0c036f2c;
case 0x0c036f2eu: goto P_0c036f2e;
case 0x0c036f30u: goto P_0c036f30;
case 0x0c036f32u: goto P_0c036f32;
case 0x0c036f34u: goto P_0c036f34;
case 0x0c036f36u: goto P_0c036f36;
case 0x0c036f38u: goto P_0c036f38;
case 0x0c036f3au: goto P_0c036f3a;
case 0x0c036f3cu: goto P_0c036f3c;
case 0x0c036f3eu: goto P_0c036f3e;
case 0x0c036f40u: goto P_0c036f40;
case 0x0c036f42u: goto P_0c036f42;
case 0x0c036f44u: goto P_0c036f44;
case 0x0c036f46u: goto P_0c036f46;
case 0x0c036f48u: goto P_0c036f48;
case 0x0c036f4au: goto P_0c036f4a;
case 0x0c036f4cu: goto P_0c036f4c;
case 0x0c036f4eu: goto P_0c036f4e;
case 0x0c036f50u: goto P_0c036f50;
case 0x0c036f52u: goto P_0c036f52;
case 0x0c036f54u: goto P_0c036f54;
case 0x0c036f56u: goto P_0c036f56;
case 0x0c036f58u: goto P_0c036f58;
case 0x0c036f5au: goto P_0c036f5a;
case 0x0c036f5cu: goto P_0c036f5c;
case 0x0c036f5eu: goto P_0c036f5e;
case 0x0c036f60u: goto P_0c036f60;
case 0x0c036f62u: goto P_0c036f62;
case 0x0c036f64u: goto P_0c036f64;
case 0x0c036f66u: goto P_0c036f66;
case 0x0c036f68u: goto P_0c036f68;
case 0x0c036f6au: goto P_0c036f6a;
case 0x0c036f6cu: goto P_0c036f6c;
case 0x0c036f6eu: goto P_0c036f6e;
case 0x0c036f70u: goto P_0c036f70;
case 0x0c036f72u: goto P_0c036f72;
case 0x0c036f74u: goto P_0c036f74;
case 0x0c036f76u: goto P_0c036f76;
case 0x0c036f78u: goto P_0c036f78;
case 0x0c036f7au: goto P_0c036f7a;
case 0x0c036f7cu: goto P_0c036f7c;
case 0x0c036f7eu: goto P_0c036f7e;
case 0x0c036f80u: goto P_0c036f80;
case 0x0c036f82u: goto P_0c036f82;
case 0x0c036f84u: goto P_0c036f84;
case 0x0c036f86u: goto P_0c036f86;
case 0x0c036f88u: goto P_0c036f88;
case 0x0c036f8au: goto P_0c036f8a;
case 0x0c036f8cu: goto P_0c036f8c;
case 0x0c036f8eu: goto P_0c036f8e;
case 0x0c036f90u: goto P_0c036f90;
case 0x0c036f92u: goto P_0c036f92;
case 0x0c036f94u: goto P_0c036f94;
case 0x0c036f96u: goto P_0c036f96;
case 0x0c036f98u: goto P_0c036f98;
case 0x0c036f9au: goto P_0c036f9a;
case 0x0c036f9cu: goto P_0c036f9c;
case 0x0c036f9eu: goto P_0c036f9e;
case 0x0c036fa0u: goto P_0c036fa0;
case 0x0c036fa2u: goto P_0c036fa2;
case 0x0c036fa4u: goto P_0c036fa4;
case 0x0c036fa6u: goto P_0c036fa6;
case 0x0c036fa8u: goto P_0c036fa8;
case 0x0c036faau: goto P_0c036faa;
case 0x0c036facu: goto P_0c036fac;
case 0x0c036faeu: goto P_0c036fae;
case 0x0c036fb0u: goto P_0c036fb0;
case 0x0c036fb2u: goto P_0c036fb2;
case 0x0c036fb4u: goto P_0c036fb4;
case 0x0c0371e6u: goto P_0c0371e6;
case 0x0c0371e8u: goto P_0c0371e8;
case 0x0c0371eau: goto P_0c0371ea;
case 0x0c038600u: goto P_0c038600;
case 0x0c038602u: goto P_0c038602;
case 0x0c038604u: goto P_0c038604;
case 0x0c038606u: goto P_0c038606;
case 0x0c038608u: goto P_0c038608;
case 0x0c03860au: goto P_0c03860a;
case 0x0c03860cu: goto P_0c03860c;
case 0x0c03860eu: goto P_0c03860e;
case 0x0c038610u: goto P_0c038610;
case 0x0c038612u: goto P_0c038612;
case 0x0c038614u: goto P_0c038614;
case 0x0c038616u: goto P_0c038616;
case 0x0c038618u: goto P_0c038618;
case 0x0c03861au: goto P_0c03861a;
case 0x0c03861cu: goto P_0c03861c;
case 0x0c03861eu: goto P_0c03861e;
case 0x0c038620u: goto P_0c038620;
case 0x0c038622u: goto P_0c038622;
case 0x0c038624u: goto P_0c038624;
case 0x0c038626u: goto P_0c038626;
case 0x0c038628u: goto P_0c038628;
case 0x0c03862au: goto P_0c03862a;
case 0x0c03862cu: goto P_0c03862c;
case 0x0c03862eu: goto P_0c03862e;
case 0x0c038630u: goto P_0c038630;
case 0x0c038632u: goto P_0c038632;
case 0x0c038634u: goto P_0c038634;
case 0x0c038636u: goto P_0c038636;
case 0x0c038638u: goto P_0c038638;
case 0x0c03863au: goto P_0c03863a;
case 0x0c03863cu: goto P_0c03863c;
case 0x0c03863eu: goto P_0c03863e;
case 0x0c038640u: goto P_0c038640;
case 0x0c038642u: goto P_0c038642;
case 0x0c038644u: goto P_0c038644;
case 0x0c038646u: goto P_0c038646;
case 0x0c038648u: goto P_0c038648;
case 0x0c03864au: goto P_0c03864a;
case 0x0c03864cu: goto P_0c03864c;
case 0x0c03864eu: goto P_0c03864e;
case 0x0c038650u: goto P_0c038650;
case 0x0c038652u: goto P_0c038652;
case 0x0c038654u: goto P_0c038654;
case 0x0c038656u: goto P_0c038656;
case 0x0c038658u: goto P_0c038658;
case 0x0c03865au: goto P_0c03865a;
case 0x0c03865cu: goto P_0c03865c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c035ca4: /* original 2fe6, guest PC 0x0c035ca4 */
if(!s->budget--) { s->failed_pc=0x0c035ca4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035ca6;
P_0c035ca6: /* original d32e, guest PC 0x0c035ca6 */
if(!s->budget--) { s->failed_pc=0x0c035ca6u; return 0; }
r[3]=read(ram,0x0c035d60u,4);
goto P_0c035ca8;
P_0c035ca8: /* original 6e32, guest PC 0x0c035ca8 */
if(!s->budget--) { s->failed_pc=0x0c035ca8u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c035caa;
P_0c035caa: /* original 2ee8, guest PC 0x0c035caa */
if(!s->budget--) { s->failed_pc=0x0c035caau; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c035cac;
P_0c035cac: /* original 8902, guest PC 0x0c035cac */
if(!s->budget--) { s->failed_pc=0x0c035cacu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035cb4; }
goto P_0c035cae;
P_0c035cae: /* original 50ec, guest PC 0x0c035cae */
if(!s->budget--) { s->failed_pc=0x0c035caeu; return 0; }
r[0]=read(ram,r[14]+48,4);
goto P_0c035cb0;
P_0c035cb0: /* original 402b, guest PC 0x0c035cb0 */
if(!s->budget--) { s->failed_pc=0x0c035cb0u; return 0; }
target=r[0];
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
P_0c035cb2: /* original 6ef6, guest PC 0x0c035cb2 */
if(!s->budget--) { s->failed_pc=0x0c035cb2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c035cb4;
P_0c035cb4: /* original e000, guest PC 0x0c035cb4 */
if(!s->budget--) { s->failed_pc=0x0c035cb4u; return 0; }
r[0]=0x00000000u;
goto P_0c035cb6;
P_0c035cb6: /* original 000b, guest PC 0x0c035cb6 */
if(!s->budget--) { s->failed_pc=0x0c035cb6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c035cb8: /* original 6ef6, guest PC 0x0c035cb8 */
if(!s->budget--) { s->failed_pc=0x0c035cb8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c035cbau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c035cbau; return 0; } return 1;
P_0c035ce8: /* original 2fe6, guest PC 0x0c035ce8 */
if(!s->budget--) { s->failed_pc=0x0c035ce8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035cea;
P_0c035cea: /* original d31d, guest PC 0x0c035cea */
if(!s->budget--) { s->failed_pc=0x0c035ceau; return 0; }
r[3]=read(ram,0x0c035d60u,4);
goto P_0c035cec;
P_0c035cec: /* original 6e32, guest PC 0x0c035cec */
if(!s->budget--) { s->failed_pc=0x0c035cecu; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c035cee;
P_0c035cee: /* original 2ee8, guest PC 0x0c035cee */
if(!s->budget--) { s->failed_pc=0x0c035ceeu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c035cf0;
P_0c035cf0: /* original 8903, guest PC 0x0c035cf0 */
if(!s->budget--) { s->failed_pc=0x0c035cf0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035cfa; }
goto P_0c035cf2;
P_0c035cf2: /* original e050, guest PC 0x0c035cf2 */
if(!s->budget--) { s->failed_pc=0x0c035cf2u; return 0; }
r[0]=0x00000050u;
goto P_0c035cf4;
P_0c035cf4: /* original 00ee, guest PC 0x0c035cf4 */
if(!s->budget--) { s->failed_pc=0x0c035cf4u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c035cf6;
P_0c035cf6: /* original 402b, guest PC 0x0c035cf6 */
if(!s->budget--) { s->failed_pc=0x0c035cf6u; return 0; }
target=r[0];
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
P_0c035cf8: /* original 6ef6, guest PC 0x0c035cf8 */
if(!s->budget--) { s->failed_pc=0x0c035cf8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c035cfa;
P_0c035cfa: /* original e000, guest PC 0x0c035cfa */
if(!s->budget--) { s->failed_pc=0x0c035cfau; return 0; }
r[0]=0x00000000u;
goto P_0c035cfc;
P_0c035cfc: /* original 000b, guest PC 0x0c035cfc */
if(!s->budget--) { s->failed_pc=0x0c035cfcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c035cfe: /* original 6ef6, guest PC 0x0c035cfe */
if(!s->budget--) { s->failed_pc=0x0c035cfeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c035d00u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c035d00u; return 0; } return 1;
P_0c036e78: /* original 2fe6, guest PC 0x0c036e78 */
if(!s->budget--) { s->failed_pc=0x0c036e78u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036e7a;
P_0c036e7a: /* original 2fd6, guest PC 0x0c036e7a */
if(!s->budget--) { s->failed_pc=0x0c036e7au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036e7c;
P_0c036e7c: /* original 2fc6, guest PC 0x0c036e7c */
if(!s->budget--) { s->failed_pc=0x0c036e7cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036e7e;
P_0c036e7e: /* original 2fb6, guest PC 0x0c036e7e */
if(!s->budget--) { s->failed_pc=0x0c036e7eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036e80;
P_0c036e80: /* original 4f22, guest PC 0x0c036e80 */
if(!s->budget--) { s->failed_pc=0x0c036e80u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c036e82;
P_0c036e82: /* original 0e02, guest PC 0x0c036e82 */
if(!s->budget--) { s->failed_pc=0x0c036e82u; return 0; }
r[14]=r[17];
goto P_0c036e84;
P_0c036e84: /* original 7ffc, guest PC 0x0c036e84 */
if(!s->budget--) { s->failed_pc=0x0c036e84u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c036e86;
P_0c036e86: /* original 2f42, guest PC 0x0c036e86 */
if(!s->budget--) { s->failed_pc=0x0c036e86u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c036e88;
P_0c036e88: /* original 933e, guest PC 0x0c036e88 */
if(!s->budget--) { s->failed_pc=0x0c036e88u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036f08u,2);
goto P_0c036e8a;
P_0c036e8a: /* original 23eb, guest PC 0x0c036e8a */
if(!s->budget--) { s->failed_pc=0x0c036e8au; return 0; }
r[3]|=r[14];
goto P_0c036e8c;
P_0c036e8c: /* original 430e, guest PC 0x0c036e8c */
if(!s->budget--) { s->failed_pc=0x0c036e8cu; return 0; }
r[17]=r[3];
goto P_0c036e8e;
P_0c036e8e: /* original dc21, guest PC 0x0c036e8e */
if(!s->budget--) { s->failed_pc=0x0c036e8eu; return 0; }
r[12]=read(ram,0x0c036f14u,4);
goto P_0c036e90;
P_0c036e90: /* original 6dc2, guest PC 0x0c036e90 */
if(!s->budget--) { s->failed_pc=0x0c036e90u; return 0; }
tmp=read(ram,r[12],4);
r[13]=tmp;
goto P_0c036e92;
P_0c036e92: /* original 923a, guest PC 0x0c036e92 */
if(!s->budget--) { s->failed_pc=0x0c036e92u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036f0au,2);
goto P_0c036e94;
P_0c036e94: /* original db20, guest PC 0x0c036e94 */
if(!s->budget--) { s->failed_pc=0x0c036e94u; return 0; }
r[11]=read(ram,0x0c036f18u,4);
goto P_0c036e96;
P_0c036e96: /* original 22d8, guest PC 0x0c036e96 */
if(!s->budget--) { s->failed_pc=0x0c036e96u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c036e98;
P_0c036e98: /* original 8903, guest PC 0x0c036e98 */
if(!s->budget--) { s->failed_pc=0x0c036e98u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036ea2; }
goto P_0c036e9a;
P_0c036e9a: /* original d120, guest PC 0x0c036e9a */
if(!s->budget--) { s->failed_pc=0x0c036e9au; return 0; }
r[1]=read(ram,0x0c036f1cu,4);
goto P_0c036e9c;
P_0c036e9c: /* original 21bb, guest PC 0x0c036e9c */
if(!s->budget--) { s->failed_pc=0x0c036e9cu; return 0; }
r[1]|=r[11];
goto P_0c036e9e;
P_0c036e9e: /* original 410b, guest PC 0x0c036e9e */
if(!s->budget--) { s->failed_pc=0x0c036e9eu; return 0; }
target=r[1];
r[16]=code_base|0x0c036ea2u;
r[4]=0x00000030u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036ea2u) { target=s->pc; goto dispatch; }
goto P_0c036ea2;
P_0c036ea0: /* original e430, guest PC 0x0c036ea0 */
if(!s->budget--) { s->failed_pc=0x0c036ea0u; return 0; }
r[4]=0x00000030u;
goto P_0c036ea2;
P_0c036ea2: /* original 9033, guest PC 0x0c036ea2 */
if(!s->budget--) { s->failed_pc=0x0c036ea2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036f0cu,2);
goto P_0c036ea4;
P_0c036ea4: /* original 20d9, guest PC 0x0c036ea4 */
if(!s->budget--) { s->failed_pc=0x0c036ea4u; return 0; }
r[0]&=r[13];
goto P_0c036ea6;
P_0c036ea6: /* original 8801, guest PC 0x0c036ea6 */
if(!s->budget--) { s->failed_pc=0x0c036ea6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c036ea8;
P_0c036ea8: /* original 8909, guest PC 0x0c036ea8 */
if(!s->budget--) { s->failed_pc=0x0c036ea8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036ebe; }
goto P_0c036eaa;
P_0c036eaa: /* original 8821, guest PC 0x0c036eaa */
if(!s->budget--) { s->failed_pc=0x0c036eaau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000021u)!=0);
goto P_0c036eac;
P_0c036eac: /* original 890b, guest PC 0x0c036eac */
if(!s->budget--) { s->failed_pc=0x0c036eacu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036ec6; }
goto P_0c036eae;
P_0c036eae: /* original 912e, guest PC 0x0c036eae */
if(!s->budget--) { s->failed_pc=0x0c036eaeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036f0eu,2);
goto P_0c036eb0;
P_0c036eb0: /* original 3010, guest PC 0x0c036eb0 */
if(!s->budget--) { s->failed_pc=0x0c036eb0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c036eb2;
P_0c036eb2: /* original 8904, guest PC 0x0c036eb2 */
if(!s->budget--) { s->failed_pc=0x0c036eb2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036ebe; }
goto P_0c036eb4;
P_0c036eb4: /* original 912a, guest PC 0x0c036eb4 */
if(!s->budget--) { s->failed_pc=0x0c036eb4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036f0cu,2);
goto P_0c036eb6;
P_0c036eb6: /* original 3010, guest PC 0x0c036eb6 */
if(!s->budget--) { s->failed_pc=0x0c036eb6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c036eb8;
P_0c036eb8: /* original 8905, guest PC 0x0c036eb8 */
if(!s->budget--) { s->failed_pc=0x0c036eb8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036ec6; }
goto P_0c036eba;
P_0c036eba: /* original a009, guest PC 0x0c036eba */
if(!s->budget--) { s->failed_pc=0x0c036ebau; return 0; }
goto P_0c036ed0;
P_0c036ebc: /* original 0009, guest PC 0x0c036ebc */
if(!s->budget--) { s->failed_pc=0x0c036ebcu; return 0; }
goto P_0c036ebe;
P_0c036ebe: /* original d317, guest PC 0x0c036ebe */
if(!s->budget--) { s->failed_pc=0x0c036ebeu; return 0; }
r[3]=read(ram,0x0c036f1cu,4);
goto P_0c036ec0;
P_0c036ec0: /* original 2b3b, guest PC 0x0c036ec0 */
if(!s->budget--) { s->failed_pc=0x0c036ec0u; return 0; }
r[11]|=r[3];
goto P_0c036ec2;
P_0c036ec2: /* original a003, guest PC 0x0c036ec2 */
if(!s->budget--) { s->failed_pc=0x0c036ec2u; return 0; }
r[4]=0x0000000fu;
goto P_0c036ecc;
P_0c036ec4: /* original e40f, guest PC 0x0c036ec4 */
if(!s->budget--) { s->failed_pc=0x0c036ec4u; return 0; }
r[4]=0x0000000fu;
goto P_0c036ec6;
P_0c036ec6: /* original d315, guest PC 0x0c036ec6 */
if(!s->budget--) { s->failed_pc=0x0c036ec6u; return 0; }
r[3]=read(ram,0x0c036f1cu,4);
goto P_0c036ec8;
P_0c036ec8: /* original e405, guest PC 0x0c036ec8 */
if(!s->budget--) { s->failed_pc=0x0c036ec8u; return 0; }
r[4]=0x00000005u;
goto P_0c036eca;
P_0c036eca: /* original 2b3b, guest PC 0x0c036eca */
if(!s->budget--) { s->failed_pc=0x0c036ecau; return 0; }
r[11]|=r[3];
goto P_0c036ecc;
P_0c036ecc: /* original 4b0b, guest PC 0x0c036ecc */
if(!s->budget--) { s->failed_pc=0x0c036eccu; return 0; }
target=r[11];
r[16]=code_base|0x0c036ed0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036ed0u) { target=s->pc; goto dispatch; }
goto P_0c036ed0;
P_0c036ece: /* original 0009, guest PC 0x0c036ece */
if(!s->budget--) { s->failed_pc=0x0c036eceu; return 0; }
goto P_0c036ed0;
P_0c036ed0: /* original 931e, guest PC 0x0c036ed0 */
if(!s->budget--) { s->failed_pc=0x0c036ed0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036f10u,2);
goto P_0c036ed2;
P_0c036ed2: /* original 2c32, guest PC 0x0c036ed2 */
if(!s->budget--) { s->failed_pc=0x0c036ed2u; return 0; }
write(ram,r[12],r[3],4);
goto P_0c036ed4;
P_0c036ed4: /* original 0009, guest PC 0x0c036ed4 */
if(!s->budget--) { s->failed_pc=0x0c036ed4u; return 0; }
goto P_0c036ed6;
P_0c036ed6: /* original 0009, guest PC 0x0c036ed6 */
if(!s->budget--) { s->failed_pc=0x0c036ed6u; return 0; }
goto P_0c036ed8;
P_0c036ed8: /* original 0009, guest PC 0x0c036ed8 */
if(!s->budget--) { s->failed_pc=0x0c036ed8u; return 0; }
goto P_0c036eda;
P_0c036eda: /* original 0009, guest PC 0x0c036eda */
if(!s->budget--) { s->failed_pc=0x0c036edau; return 0; }
goto P_0c036edc;
P_0c036edc: /* original 0009, guest PC 0x0c036edc */
if(!s->budget--) { s->failed_pc=0x0c036edcu; return 0; }
goto P_0c036ede;
P_0c036ede: /* original 0009, guest PC 0x0c036ede */
if(!s->budget--) { s->failed_pc=0x0c036edeu; return 0; }
goto P_0c036ee0;
P_0c036ee0: /* original 0009, guest PC 0x0c036ee0 */
if(!s->budget--) { s->failed_pc=0x0c036ee0u; return 0; }
goto P_0c036ee2;
P_0c036ee2: /* original 0009, guest PC 0x0c036ee2 */
if(!s->budget--) { s->failed_pc=0x0c036ee2u; return 0; }
goto P_0c036ee4;
P_0c036ee4: /* original 61f2, guest PC 0x0c036ee4 */
if(!s->budget--) { s->failed_pc=0x0c036ee4u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c036ee6;
P_0c036ee6: /* original 2c12, guest PC 0x0c036ee6 */
if(!s->budget--) { s->failed_pc=0x0c036ee6u; return 0; }
write(ram,r[12],r[1],4);
goto P_0c036ee8;
P_0c036ee8: /* original 0009, guest PC 0x0c036ee8 */
if(!s->budget--) { s->failed_pc=0x0c036ee8u; return 0; }
goto P_0c036eea;
P_0c036eea: /* original 0009, guest PC 0x0c036eea */
if(!s->budget--) { s->failed_pc=0x0c036eeau; return 0; }
goto P_0c036eec;
P_0c036eec: /* original 0009, guest PC 0x0c036eec */
if(!s->budget--) { s->failed_pc=0x0c036eecu; return 0; }
goto P_0c036eee;
P_0c036eee: /* original 0009, guest PC 0x0c036eee */
if(!s->budget--) { s->failed_pc=0x0c036eeeu; return 0; }
goto P_0c036ef0;
P_0c036ef0: /* original 0009, guest PC 0x0c036ef0 */
if(!s->budget--) { s->failed_pc=0x0c036ef0u; return 0; }
goto P_0c036ef2;
P_0c036ef2: /* original 0009, guest PC 0x0c036ef2 */
if(!s->budget--) { s->failed_pc=0x0c036ef2u; return 0; }
goto P_0c036ef4;
P_0c036ef4: /* original 0009, guest PC 0x0c036ef4 */
if(!s->budget--) { s->failed_pc=0x0c036ef4u; return 0; }
goto P_0c036ef6;
P_0c036ef6: /* original 0009, guest PC 0x0c036ef6 */
if(!s->budget--) { s->failed_pc=0x0c036ef6u; return 0; }
goto P_0c036ef8;
P_0c036ef8: /* original 4e0e, guest PC 0x0c036ef8 */
if(!s->budget--) { s->failed_pc=0x0c036ef8u; return 0; }
r[17]=r[14];
goto P_0c036efa;
P_0c036efa: /* original 7f04, guest PC 0x0c036efa */
if(!s->budget--) { s->failed_pc=0x0c036efau; return 0; }
r[15]+=0x00000004u;
goto P_0c036efc;
P_0c036efc: /* original 4f26, guest PC 0x0c036efc */
if(!s->budget--) { s->failed_pc=0x0c036efcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c036efe;
P_0c036efe: /* original 6bf6, guest PC 0x0c036efe */
if(!s->budget--) { s->failed_pc=0x0c036efeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c036f00;
P_0c036f00: /* original 6cf6, guest PC 0x0c036f00 */
if(!s->budget--) { s->failed_pc=0x0c036f00u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c036f02;
P_0c036f02: /* original 6df6, guest PC 0x0c036f02 */
if(!s->budget--) { s->failed_pc=0x0c036f02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c036f04;
P_0c036f04: /* original 000b, guest PC 0x0c036f04 */
if(!s->budget--) { s->failed_pc=0x0c036f04u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c036f06: /* original 6ef6, guest PC 0x0c036f06 */
if(!s->budget--) { s->failed_pc=0x0c036f06u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c036f08u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c036f08u; return 0; } return 1;
P_0c036f20: /* original 0102, guest PC 0x0c036f20 */
if(!s->budget--) { s->failed_pc=0x0c036f20u; return 0; }
r[1]=r[17];
goto P_0c036f22;
P_0c036f22: /* original 936f, guest PC 0x0c036f22 */
if(!s->budget--) { s->failed_pc=0x0c036f22u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c037004u,2);
goto P_0c036f24;
P_0c036f24: /* original 231b, guest PC 0x0c036f24 */
if(!s->budget--) { s->failed_pc=0x0c036f24u; return 0; }
r[3]|=r[1];
goto P_0c036f26;
P_0c036f26: /* original 430e, guest PC 0x0c036f26 */
if(!s->budget--) { s->failed_pc=0x0c036f26u; return 0; }
r[17]=r[3];
goto P_0c036f28;
P_0c036f28: /* original e201, guest PC 0x0c036f28 */
if(!s->budget--) { s->failed_pc=0x0c036f28u; return 0; }
r[2]=0x00000001u;
goto P_0c036f2a;
P_0c036f2a: /* original d737, guest PC 0x0c036f2a */
if(!s->budget--) { s->failed_pc=0x0c036f2au; return 0; }
r[7]=read(ram,0x0c037008u,4);
goto P_0c036f2c;
P_0c036f2c: /* original 2248, guest PC 0x0c036f2c */
if(!s->budget--) { s->failed_pc=0x0c036f2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c036f2e;
P_0c036f2e: /* original 8d07, guest PC 0x0c036f2e */
if(!s->budget--) { s->failed_pc=0x0c036f2eu; return 0; }
cond=r[17]&1u;
r[5]=0xfffffffcu;
if(cond) { goto P_0c036f40; }
goto P_0c036f32;
P_0c036f30: /* original e5fc, guest PC 0x0c036f30 */
if(!s->budget--) { s->failed_pc=0x0c036f30u; return 0; }
r[5]=0xfffffffcu;
goto P_0c036f32;
P_0c036f32: /* original d636, guest PC 0x0c036f32 */
if(!s->budget--) { s->failed_pc=0x0c036f32u; return 0; }
r[6]=read(ram,0x0c03700cu,4);
goto P_0c036f34;
P_0c036f34: /* original 6262, guest PC 0x0c036f34 */
if(!s->budget--) { s->failed_pc=0x0c036f34u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c036f36;
P_0c036f36: /* original 2259, guest PC 0x0c036f36 */
if(!s->budget--) { s->failed_pc=0x0c036f36u; return 0; }
r[2]&=r[5];
goto P_0c036f38;
P_0c036f38: /* original 2622, guest PC 0x0c036f38 */
if(!s->budget--) { s->failed_pc=0x0c036f38u; return 0; }
write(ram,r[6],r[2],4);
goto P_0c036f3a;
P_0c036f3a: /* original 7620, guest PC 0x0c036f3a */
if(!s->budget--) { s->failed_pc=0x0c036f3au; return 0; }
r[6]+=0x00000020u;
goto P_0c036f3c;
P_0c036f3c: /* original 3672, guest PC 0x0c036f3c */
if(!s->budget--) { s->failed_pc=0x0c036f3cu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[7])!=0);
goto P_0c036f3e;
P_0c036f3e: /* original 8bf9, guest PC 0x0c036f3e */
if(!s->budget--) { s->failed_pc=0x0c036f3eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c036f34; }
goto P_0c036f40;
P_0c036f40: /* original e202, guest PC 0x0c036f40 */
if(!s->budget--) { s->failed_pc=0x0c036f40u; return 0; }
r[2]=0x00000002u;
goto P_0c036f42;
P_0c036f42: /* original d033, guest PC 0x0c036f42 */
if(!s->budget--) { s->failed_pc=0x0c036f42u; return 0; }
r[0]=read(ram,0x0c037010u,4);
goto P_0c036f44;
P_0c036f44: /* original 2248, guest PC 0x0c036f44 */
if(!s->budget--) { s->failed_pc=0x0c036f44u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c036f46;
P_0c036f46: /* original 8906, guest PC 0x0c036f46 */
if(!s->budget--) { s->failed_pc=0x0c036f46u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036f56; }
goto P_0c036f48;
P_0c036f48: /* original 6673, guest PC 0x0c036f48 */
if(!s->budget--) { s->failed_pc=0x0c036f48u; return 0; }
r[6]=r[7];
goto P_0c036f4a;
P_0c036f4a: /* original 6262, guest PC 0x0c036f4a */
if(!s->budget--) { s->failed_pc=0x0c036f4au; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c036f4c;
P_0c036f4c: /* original 2259, guest PC 0x0c036f4c */
if(!s->budget--) { s->failed_pc=0x0c036f4cu; return 0; }
r[2]&=r[5];
goto P_0c036f4e;
P_0c036f4e: /* original 2622, guest PC 0x0c036f4e */
if(!s->budget--) { s->failed_pc=0x0c036f4eu; return 0; }
write(ram,r[6],r[2],4);
goto P_0c036f50;
P_0c036f50: /* original 7620, guest PC 0x0c036f50 */
if(!s->budget--) { s->failed_pc=0x0c036f50u; return 0; }
r[6]+=0x00000020u;
goto P_0c036f52;
P_0c036f52: /* original 3602, guest PC 0x0c036f52 */
if(!s->budget--) { s->failed_pc=0x0c036f52u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[0])!=0);
goto P_0c036f54;
P_0c036f54: /* original 8bf9, guest PC 0x0c036f54 */
if(!s->budget--) { s->failed_pc=0x0c036f54u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c036f4a; }
goto P_0c036f56;
P_0c036f56: /* original e204, guest PC 0x0c036f56 */
if(!s->budget--) { s->failed_pc=0x0c036f56u; return 0; }
r[2]=0x00000004u;
goto P_0c036f58;
P_0c036f58: /* original d72e, guest PC 0x0c036f58 */
if(!s->budget--) { s->failed_pc=0x0c036f58u; return 0; }
r[7]=read(ram,0x0c037014u,4);
goto P_0c036f5a;
P_0c036f5a: /* original 2248, guest PC 0x0c036f5a */
if(!s->budget--) { s->failed_pc=0x0c036f5au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c036f5c;
P_0c036f5c: /* original 8906, guest PC 0x0c036f5c */
if(!s->budget--) { s->failed_pc=0x0c036f5cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036f6c; }
goto P_0c036f5e;
P_0c036f5e: /* original 6603, guest PC 0x0c036f5e */
if(!s->budget--) { s->failed_pc=0x0c036f5eu; return 0; }
r[6]=r[0];
goto P_0c036f60;
P_0c036f60: /* original 6262, guest PC 0x0c036f60 */
if(!s->budget--) { s->failed_pc=0x0c036f60u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c036f62;
P_0c036f62: /* original 2259, guest PC 0x0c036f62 */
if(!s->budget--) { s->failed_pc=0x0c036f62u; return 0; }
r[2]&=r[5];
goto P_0c036f64;
P_0c036f64: /* original 2622, guest PC 0x0c036f64 */
if(!s->budget--) { s->failed_pc=0x0c036f64u; return 0; }
write(ram,r[6],r[2],4);
goto P_0c036f66;
P_0c036f66: /* original 7620, guest PC 0x0c036f66 */
if(!s->budget--) { s->failed_pc=0x0c036f66u; return 0; }
r[6]+=0x00000020u;
goto P_0c036f68;
P_0c036f68: /* original 3672, guest PC 0x0c036f68 */
if(!s->budget--) { s->failed_pc=0x0c036f68u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[7])!=0);
goto P_0c036f6a;
P_0c036f6a: /* original 8bf9, guest PC 0x0c036f6a */
if(!s->budget--) { s->failed_pc=0x0c036f6au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c036f60; }
goto P_0c036f6c;
P_0c036f6c: /* original e208, guest PC 0x0c036f6c */
if(!s->budget--) { s->failed_pc=0x0c036f6cu; return 0; }
r[2]=0x00000008u;
goto P_0c036f6e;
P_0c036f6e: /* original 2248, guest PC 0x0c036f6e */
if(!s->budget--) { s->failed_pc=0x0c036f6eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c036f70;
P_0c036f70: /* original 8907, guest PC 0x0c036f70 */
if(!s->budget--) { s->failed_pc=0x0c036f70u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036f82; }
goto P_0c036f72;
P_0c036f72: /* original 6673, guest PC 0x0c036f72 */
if(!s->budget--) { s->failed_pc=0x0c036f72u; return 0; }
r[6]=r[7];
goto P_0c036f74;
P_0c036f74: /* original d728, guest PC 0x0c036f74 */
if(!s->budget--) { s->failed_pc=0x0c036f74u; return 0; }
r[7]=read(ram,0x0c037018u,4);
goto P_0c036f76;
P_0c036f76: /* original 6262, guest PC 0x0c036f76 */
if(!s->budget--) { s->failed_pc=0x0c036f76u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c036f78;
P_0c036f78: /* original 2259, guest PC 0x0c036f78 */
if(!s->budget--) { s->failed_pc=0x0c036f78u; return 0; }
r[2]&=r[5];
goto P_0c036f7a;
P_0c036f7a: /* original 2622, guest PC 0x0c036f7a */
if(!s->budget--) { s->failed_pc=0x0c036f7au; return 0; }
write(ram,r[6],r[2],4);
goto P_0c036f7c;
P_0c036f7c: /* original 7620, guest PC 0x0c036f7c */
if(!s->budget--) { s->failed_pc=0x0c036f7cu; return 0; }
r[6]+=0x00000020u;
goto P_0c036f7e;
P_0c036f7e: /* original 3672, guest PC 0x0c036f7e */
if(!s->budget--) { s->failed_pc=0x0c036f7eu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[7])!=0);
goto P_0c036f80;
P_0c036f80: /* original 8bf9, guest PC 0x0c036f80 */
if(!s->budget--) { s->failed_pc=0x0c036f80u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c036f76; }
goto P_0c036f82;
P_0c036f82: /* original e210, guest PC 0x0c036f82 */
if(!s->budget--) { s->failed_pc=0x0c036f82u; return 0; }
r[2]=0x00000010u;
goto P_0c036f84;
P_0c036f84: /* original d725, guest PC 0x0c036f84 */
if(!s->budget--) { s->failed_pc=0x0c036f84u; return 0; }
r[7]=read(ram,0x0c03701cu,4);
goto P_0c036f86;
P_0c036f86: /* original 2248, guest PC 0x0c036f86 */
if(!s->budget--) { s->failed_pc=0x0c036f86u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c036f88;
P_0c036f88: /* original 8d07, guest PC 0x0c036f88 */
if(!s->budget--) { s->failed_pc=0x0c036f88u; return 0; }
cond=r[17]&1u;
r[5]=0xfffffffeu;
if(cond) { goto P_0c036f9a; }
goto P_0c036f8c;
P_0c036f8a: /* original e5fe, guest PC 0x0c036f8a */
if(!s->budget--) { s->failed_pc=0x0c036f8au; return 0; }
r[5]=0xfffffffeu;
goto P_0c036f8c;
P_0c036f8c: /* original d624, guest PC 0x0c036f8c */
if(!s->budget--) { s->failed_pc=0x0c036f8cu; return 0; }
r[6]=read(ram,0x0c037020u,4);
goto P_0c036f8e;
P_0c036f8e: /* original 6262, guest PC 0x0c036f8e */
if(!s->budget--) { s->failed_pc=0x0c036f8eu; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c036f90;
P_0c036f90: /* original 2259, guest PC 0x0c036f90 */
if(!s->budget--) { s->failed_pc=0x0c036f90u; return 0; }
r[2]&=r[5];
goto P_0c036f92;
P_0c036f92: /* original 2622, guest PC 0x0c036f92 */
if(!s->budget--) { s->failed_pc=0x0c036f92u; return 0; }
write(ram,r[6],r[2],4);
goto P_0c036f94;
P_0c036f94: /* original 7620, guest PC 0x0c036f94 */
if(!s->budget--) { s->failed_pc=0x0c036f94u; return 0; }
r[6]+=0x00000020u;
goto P_0c036f96;
P_0c036f96: /* original 3672, guest PC 0x0c036f96 */
if(!s->budget--) { s->failed_pc=0x0c036f96u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[7])!=0);
goto P_0c036f98;
P_0c036f98: /* original 8bf9, guest PC 0x0c036f98 */
if(!s->budget--) { s->failed_pc=0x0c036f98u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c036f8e; }
goto P_0c036f9a;
P_0c036f9a: /* original e220, guest PC 0x0c036f9a */
if(!s->budget--) { s->failed_pc=0x0c036f9au; return 0; }
r[2]=0x00000020u;
goto P_0c036f9c;
P_0c036f9c: /* original 2428, guest PC 0x0c036f9c */
if(!s->budget--) { s->failed_pc=0x0c036f9cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c036f9e;
P_0c036f9e: /* original 8907, guest PC 0x0c036f9e */
if(!s->budget--) { s->failed_pc=0x0c036f9eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036fb0; }
goto P_0c036fa0;
P_0c036fa0: /* original d620, guest PC 0x0c036fa0 */
if(!s->budget--) { s->failed_pc=0x0c036fa0u; return 0; }
r[6]=read(ram,0x0c037024u,4);
goto P_0c036fa2;
P_0c036fa2: /* original 6473, guest PC 0x0c036fa2 */
if(!s->budget--) { s->failed_pc=0x0c036fa2u; return 0; }
r[4]=r[7];
goto P_0c036fa4;
P_0c036fa4: /* original 6242, guest PC 0x0c036fa4 */
if(!s->budget--) { s->failed_pc=0x0c036fa4u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c036fa6;
P_0c036fa6: /* original 2259, guest PC 0x0c036fa6 */
if(!s->budget--) { s->failed_pc=0x0c036fa6u; return 0; }
r[2]&=r[5];
goto P_0c036fa8;
P_0c036fa8: /* original 2422, guest PC 0x0c036fa8 */
if(!s->budget--) { s->failed_pc=0x0c036fa8u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c036faa;
P_0c036faa: /* original 7420, guest PC 0x0c036faa */
if(!s->budget--) { s->failed_pc=0x0c036faau; return 0; }
r[4]+=0x00000020u;
goto P_0c036fac;
P_0c036fac: /* original 3462, guest PC 0x0c036fac */
if(!s->budget--) { s->failed_pc=0x0c036facu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[6])!=0);
goto P_0c036fae;
P_0c036fae: /* original 8bf9, guest PC 0x0c036fae */
if(!s->budget--) { s->failed_pc=0x0c036faeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c036fa4; }
goto P_0c036fb0;
P_0c036fb0: /* original 410e, guest PC 0x0c036fb0 */
if(!s->budget--) { s->failed_pc=0x0c036fb0u; return 0; }
r[17]=r[1];
goto P_0c036fb2;
P_0c036fb2: /* original 000b, guest PC 0x0c036fb2 */
if(!s->budget--) { s->failed_pc=0x0c036fb2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c036fb4: /* original 0009, guest PC 0x0c036fb4 */
if(!s->budget--) { s->failed_pc=0x0c036fb4u; return 0; }
if(!vf3_matrix_family(0x0c036fb6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c036fb6u; return 0; } return 1;
P_0c0371e6: /* original d313, guest PC 0x0c0371e6 */
if(!s->budget--) { s->failed_pc=0x0c0371e6u; return 0; }
r[3]=read(ram,0x0c037234u,4);
goto P_0c0371e8;
P_0c0371e8: /* original 432b, guest PC 0x0c0371e8 */
if(!s->budget--) { s->failed_pc=0x0c0371e8u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0463eau: return vf3_matrix_family(0x0c0463eau,s,ram);
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
P_0c0371ea: /* original 0009, guest PC 0x0c0371ea */
if(!s->budget--) { s->failed_pc=0x0c0371eau; return 0; }
if(!vf3_matrix_family(0x0c0371ecu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0371ecu; return 0; } return 1;
P_0c038600: /* original 2fe6, guest PC 0x0c038600 */
if(!s->budget--) { s->failed_pc=0x0c038600u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038602;
P_0c038602: /* original 6e43, guest PC 0x0c038602 */
if(!s->budget--) { s->failed_pc=0x0c038602u; return 0; }
r[14]=r[4];
goto P_0c038604;
P_0c038604: /* original 2fd6, guest PC 0x0c038604 */
if(!s->budget--) { s->failed_pc=0x0c038604u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038606;
P_0c038606: /* original ed3c, guest PC 0x0c038606 */
if(!s->budget--) { s->failed_pc=0x0c038606u; return 0; }
r[13]=0x0000003cu;
goto P_0c038608;
P_0c038608: /* original 4f22, guest PC 0x0c038608 */
if(!s->budget--) { s->failed_pc=0x0c038608u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03860a;
P_0c03860a: /* original 4f12, guest PC 0x0c03860a */
if(!s->budget--) { s->failed_pc=0x0c03860au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03860c;
P_0c03860c: /* original 05d7, guest PC 0x0c03860c */
if(!s->budget--) { s->failed_pc=0x0c03860cu; return 0; }
r[19]=r[5]*r[13];
goto P_0c03860e;
P_0c03860e: /* original 7ff8, guest PC 0x0c03860e */
if(!s->budget--) { s->failed_pc=0x0c03860eu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c038610;
P_0c038610: /* original 2f62, guest PC 0x0c038610 */
if(!s->budget--) { s->failed_pc=0x0c038610u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c038612;
P_0c038612: /* original 0d1a, guest PC 0x0c038612 */
if(!s->budget--) { s->failed_pc=0x0c038612u; return 0; }
r[13]=r[19];
goto P_0c038614;
P_0c038614: /* original 1fd1, guest PC 0x0c038614 */
if(!s->budget--) { s->failed_pc=0x0c038614u; return 0; }
write(ram,r[15]+4,r[13],4);
goto P_0c038616;
P_0c038616: /* original d284, guest PC 0x0c038616 */
if(!s->budget--) { s->failed_pc=0x0c038616u; return 0; }
r[2]=read(ram,0x0c038828u,4);
goto P_0c038618;
P_0c038618: /* original d484, guest PC 0x0c038618 */
if(!s->budget--) { s->failed_pc=0x0c038618u; return 0; }
r[4]=read(ram,0x0c03882cu,4);
goto P_0c03861a;
P_0c03861a: /* original 6322, guest PC 0x0c03861a */
if(!s->budget--) { s->failed_pc=0x0c03861au; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03861c;
P_0c03861c: /* original 6142, guest PC 0x0c03861c */
if(!s->budget--) { s->failed_pc=0x0c03861cu; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c03861e;
P_0c03861e: /* original 3d3c, guest PC 0x0c03861e */
if(!s->budget--) { s->failed_pc=0x0c03861eu; return 0; }
r[13]+=r[3];
goto P_0c038620;
P_0c038620: /* original 7101, guest PC 0x0c038620 */
if(!s->budget--) { s->failed_pc=0x0c038620u; return 0; }
r[1]+=0x00000001u;
goto P_0c038622;
P_0c038622: /* original 2412, guest PC 0x0c038622 */
if(!s->budget--) { s->failed_pc=0x0c038622u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c038624;
P_0c038624: /* original 85e1, guest PC 0x0c038624 */
if(!s->budget--) { s->failed_pc=0x0c038624u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c038626;
P_0c038626: /* original 57e1, guest PC 0x0c038626 */
if(!s->budget--) { s->failed_pc=0x0c038626u; return 0; }
r[7]=read(ram,r[14]+4,4);
goto P_0c038628;
P_0c038628: /* original 65e1, guest PC 0x0c038628 */
if(!s->budget--) { s->failed_pc=0x0c038628u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[5]=tmp;
goto P_0c03862a;
P_0c03862a: /* original 6603, guest PC 0x0c03862a */
if(!s->budget--) { s->failed_pc=0x0c03862au; return 0; }
r[6]=r[0];
goto P_0c03862c;
P_0c03862c: /* original d380, guest PC 0x0c03862c */
if(!s->budget--) { s->failed_pc=0x0c03862cu; return 0; }
r[3]=read(ram,0x0c038830u,4);
goto P_0c03862e;
P_0c03862e: /* original 430b, guest PC 0x0c03862e */
if(!s->budget--) { s->failed_pc=0x0c03862eu; return 0; }
target=r[3];
r[16]=code_base|0x0c038632u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c038632u) { target=s->pc; goto dispatch; }
goto P_0c038632;
P_0c038630: /* original 64d3, guest PC 0x0c038630 */
if(!s->budget--) { s->failed_pc=0x0c038630u; return 0; }
r[4]=r[13];
goto P_0c038632;
P_0c038632: /* original 6403, guest PC 0x0c038632 */
if(!s->budget--) { s->failed_pc=0x0c038632u; return 0; }
r[4]=r[0];
goto P_0c038634;
P_0c038634: /* original 2448, guest PC 0x0c038634 */
if(!s->budget--) { s->failed_pc=0x0c038634u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c038636;
P_0c038636: /* original 8f0b, guest PC 0x0c038636 */
if(!s->budget--) { s->failed_pc=0x0c038636u; return 0; }
cond=r[17]&1u;
write(ram,r[13]+40,r[0],4);
if(!cond) { goto P_0c038650; }
goto P_0c03863a;
P_0c038638: /* original 1d0a, guest PC 0x0c038638 */
if(!s->budget--) { s->failed_pc=0x0c038638u; return 0; }
write(ram,r[13]+40,r[0],4);
goto P_0c03863a;
P_0c03863a: /* original d27b, guest PC 0x0c03863a */
if(!s->budget--) { s->failed_pc=0x0c03863au; return 0; }
r[2]=read(ram,0x0c038828u,4);
goto P_0c03863c;
P_0c03863c: /* original e700, guest PC 0x0c03863c */
if(!s->budget--) { s->failed_pc=0x0c03863cu; return 0; }
r[7]=0x00000000u;
goto P_0c03863e;
P_0c03863e: /* original 54f1, guest PC 0x0c03863e */
if(!s->budget--) { s->failed_pc=0x0c03863eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c038640;
P_0c038640: /* original 6322, guest PC 0x0c038640 */
if(!s->budget--) { s->failed_pc=0x0c038640u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c038642;
P_0c038642: /* original 65f2, guest PC 0x0c038642 */
if(!s->budget--) { s->failed_pc=0x0c038642u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c038644;
P_0c038644: /* original 343c, guest PC 0x0c038644 */
if(!s->budget--) { s->failed_pc=0x0c038644u; return 0; }
r[4]+=r[3];
goto P_0c038646;
P_0c038646: /* original d37b, guest PC 0x0c038646 */
if(!s->budget--) { s->failed_pc=0x0c038646u; return 0; }
r[3]=read(ram,0x0c038834u,4);
goto P_0c038648;
P_0c038648: /* original 430b, guest PC 0x0c038648 */
if(!s->budget--) { s->failed_pc=0x0c038648u; return 0; }
target=r[3];
r[16]=code_base|0x0c03864cu;
r[6]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03864cu) { target=s->pc; goto dispatch; }
goto P_0c03864c;
P_0c03864a: /* original 6673, guest PC 0x0c03864a */
if(!s->budget--) { s->failed_pc=0x0c03864au; return 0; }
r[6]=r[7];
goto P_0c03864c;
P_0c03864c: /* original a001, guest PC 0x0c03864c */
if(!s->budget--) { s->failed_pc=0x0c03864cu; return 0; }
r[0]=0x00000000u;
goto P_0c038652;
P_0c03864e: /* original e000, guest PC 0x0c03864e */
if(!s->budget--) { s->failed_pc=0x0c03864eu; return 0; }
r[0]=0x00000000u;
goto P_0c038650;
P_0c038650: /* original e001, guest PC 0x0c038650 */
if(!s->budget--) { s->failed_pc=0x0c038650u; return 0; }
r[0]=0x00000001u;
goto P_0c038652;
P_0c038652: /* original 7f08, guest PC 0x0c038652 */
if(!s->budget--) { s->failed_pc=0x0c038652u; return 0; }
r[15]+=0x00000008u;
goto P_0c038654;
P_0c038654: /* original 4f16, guest PC 0x0c038654 */
if(!s->budget--) { s->failed_pc=0x0c038654u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c038656;
P_0c038656: /* original 4f26, guest PC 0x0c038656 */
if(!s->budget--) { s->failed_pc=0x0c038656u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c038658;
P_0c038658: /* original 6df6, guest PC 0x0c038658 */
if(!s->budget--) { s->failed_pc=0x0c038658u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03865a;
P_0c03865a: /* original 000b, guest PC 0x0c03865a */
if(!s->budget--) { s->failed_pc=0x0c03865au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03865c: /* original 6ef6, guest PC 0x0c03865c */
if(!s->budget--) { s->failed_pc=0x0c03865cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03865eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03865eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
