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
int vf3_away_batch114_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
unsupported: s->failed_pc=target; return 0;
}
