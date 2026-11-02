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
int vf3_away_batch65_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c092e54u: goto P_0c092e54;
case 0x0c092e56u: goto P_0c092e56;
case 0x0c092e58u: goto P_0c092e58;
case 0x0c092e5au: goto P_0c092e5a;
case 0x0c092e5cu: goto P_0c092e5c;
case 0x0c092e5eu: goto P_0c092e5e;
case 0x0c092e60u: goto P_0c092e60;
case 0x0c092e62u: goto P_0c092e62;
case 0x0c092e64u: goto P_0c092e64;
case 0x0c092e66u: goto P_0c092e66;
case 0x0c092e68u: goto P_0c092e68;
case 0x0c092e6au: goto P_0c092e6a;
case 0x0c092e6cu: goto P_0c092e6c;
case 0x0c092e6eu: goto P_0c092e6e;
case 0x0c092e70u: goto P_0c092e70;
case 0x0c092e72u: goto P_0c092e72;
case 0x0c092e74u: goto P_0c092e74;
case 0x0c092e76u: goto P_0c092e76;
case 0x0c092e78u: goto P_0c092e78;
case 0x0c092e7au: goto P_0c092e7a;
case 0x0c092e7cu: goto P_0c092e7c;
case 0x0c092e7eu: goto P_0c092e7e;
case 0x0c092e80u: goto P_0c092e80;
case 0x0c092e82u: goto P_0c092e82;
case 0x0c092e84u: goto P_0c092e84;
case 0x0c092e86u: goto P_0c092e86;
case 0x0c092e88u: goto P_0c092e88;
case 0x0c092e8au: goto P_0c092e8a;
case 0x0c092e8cu: goto P_0c092e8c;
case 0x0c092e8eu: goto P_0c092e8e;
case 0x0c092e90u: goto P_0c092e90;
case 0x0c092e92u: goto P_0c092e92;
case 0x0c092e94u: goto P_0c092e94;
case 0x0c092ea4u: goto P_0c092ea4;
case 0x0c092ea6u: goto P_0c092ea6;
case 0x0c092ea8u: goto P_0c092ea8;
case 0x0c092eaau: goto P_0c092eaa;
case 0x0c092eacu: goto P_0c092eac;
case 0x0c092eaeu: goto P_0c092eae;
case 0x0c092eb0u: goto P_0c092eb0;
case 0x0c092eb2u: goto P_0c092eb2;
case 0x0c092eb4u: goto P_0c092eb4;
case 0x0c092eb6u: goto P_0c092eb6;
case 0x0c092eb8u: goto P_0c092eb8;
case 0x0c092ebau: goto P_0c092eba;
case 0x0c092ebcu: goto P_0c092ebc;
case 0x0c092ebeu: goto P_0c092ebe;
case 0x0c092ec0u: goto P_0c092ec0;
case 0x0c092ec2u: goto P_0c092ec2;
case 0x0c092ec4u: goto P_0c092ec4;
case 0x0c092ec6u: goto P_0c092ec6;
case 0x0c092ec8u: goto P_0c092ec8;
case 0x0c092ecau: goto P_0c092eca;
case 0x0c092eccu: goto P_0c092ecc;
case 0x0c092eceu: goto P_0c092ece;
case 0x0c092ed0u: goto P_0c092ed0;
case 0x0c092ed2u: goto P_0c092ed2;
case 0x0c092ed4u: goto P_0c092ed4;
case 0x0c092ed6u: goto P_0c092ed6;
case 0x0c092ed8u: goto P_0c092ed8;
case 0x0c092edau: goto P_0c092eda;
case 0x0c092edcu: goto P_0c092edc;
case 0x0c092edeu: goto P_0c092ede;
case 0x0c092ee0u: goto P_0c092ee0;
case 0x0c092ee2u: goto P_0c092ee2;
case 0x0c092ee4u: goto P_0c092ee4;
case 0x0c092ee6u: goto P_0c092ee6;
case 0x0c092ee8u: goto P_0c092ee8;
case 0x0c092eeau: goto P_0c092eea;
case 0x0c092eecu: goto P_0c092eec;
case 0x0c092eeeu: goto P_0c092eee;
case 0x0c092ef0u: goto P_0c092ef0;
case 0x0c092ef2u: goto P_0c092ef2;
case 0x0c092ef4u: goto P_0c092ef4;
case 0x0c092f00u: goto P_0c092f00;
case 0x0c092f02u: goto P_0c092f02;
case 0x0c092f04u: goto P_0c092f04;
case 0x0c092f06u: goto P_0c092f06;
case 0x0c092f08u: goto P_0c092f08;
case 0x0c092f0au: goto P_0c092f0a;
case 0x0c092f0cu: goto P_0c092f0c;
case 0x0c092f0eu: goto P_0c092f0e;
case 0x0c092f10u: goto P_0c092f10;
case 0x0c092f12u: goto P_0c092f12;
case 0x0c092f14u: goto P_0c092f14;
case 0x0c092f16u: goto P_0c092f16;
case 0x0c092f18u: goto P_0c092f18;
case 0x0c092f1au: goto P_0c092f1a;
case 0x0c092f1cu: goto P_0c092f1c;
case 0x0c092f1eu: goto P_0c092f1e;
case 0x0c092f20u: goto P_0c092f20;
case 0x0c092f22u: goto P_0c092f22;
case 0x0c092f24u: goto P_0c092f24;
case 0x0c092f26u: goto P_0c092f26;
case 0x0c092f28u: goto P_0c092f28;
case 0x0c092f2au: goto P_0c092f2a;
case 0x0c092f2cu: goto P_0c092f2c;
case 0x0c092f2eu: goto P_0c092f2e;
case 0x0c092f30u: goto P_0c092f30;
case 0x0c092f32u: goto P_0c092f32;
case 0x0c092f34u: goto P_0c092f34;
case 0x0c092f36u: goto P_0c092f36;
case 0x0c092f38u: goto P_0c092f38;
case 0x0c092f3au: goto P_0c092f3a;
case 0x0c092f3cu: goto P_0c092f3c;
case 0x0c092f3eu: goto P_0c092f3e;
case 0x0c092f40u: goto P_0c092f40;
case 0x0c092f42u: goto P_0c092f42;
case 0x0c092f44u: goto P_0c092f44;
case 0x0c092f46u: goto P_0c092f46;
case 0x0c092f48u: goto P_0c092f48;
case 0x0c092f4au: goto P_0c092f4a;
case 0x0c092f4cu: goto P_0c092f4c;
case 0x0c092f4eu: goto P_0c092f4e;
case 0x0c092f50u: goto P_0c092f50;
case 0x0c092f52u: goto P_0c092f52;
case 0x0c092f54u: goto P_0c092f54;
case 0x0c092f56u: goto P_0c092f56;
case 0x0c092f58u: goto P_0c092f58;
case 0x0c092f5au: goto P_0c092f5a;
case 0x0c092f5cu: goto P_0c092f5c;
case 0x0c092f5eu: goto P_0c092f5e;
case 0x0c092f60u: goto P_0c092f60;
case 0x0c092f62u: goto P_0c092f62;
case 0x0c092f64u: goto P_0c092f64;
case 0x0c092f66u: goto P_0c092f66;
case 0x0c092f68u: goto P_0c092f68;
case 0x0c092f6au: goto P_0c092f6a;
case 0x0c092f6cu: goto P_0c092f6c;
case 0x0c092f6eu: goto P_0c092f6e;
case 0x0c092f70u: goto P_0c092f70;
case 0x0c092f72u: goto P_0c092f72;
case 0x0c092f74u: goto P_0c092f74;
case 0x0c092f76u: goto P_0c092f76;
case 0x0c092f78u: goto P_0c092f78;
case 0x0c092f7au: goto P_0c092f7a;
case 0x0c092f7cu: goto P_0c092f7c;
case 0x0c092f7eu: goto P_0c092f7e;
case 0x0c092f80u: goto P_0c092f80;
case 0x0c092f82u: goto P_0c092f82;
case 0x0c092f84u: goto P_0c092f84;
case 0x0c092f86u: goto P_0c092f86;
case 0x0c092f88u: goto P_0c092f88;
case 0x0c092f8au: goto P_0c092f8a;
case 0x0c092f8cu: goto P_0c092f8c;
case 0x0c092f8eu: goto P_0c092f8e;
case 0x0c092f90u: goto P_0c092f90;
case 0x0c092f92u: goto P_0c092f92;
case 0x0c092f94u: goto P_0c092f94;
case 0x0c092f96u: goto P_0c092f96;
case 0x0c092f98u: goto P_0c092f98;
case 0x0c092f9au: goto P_0c092f9a;
case 0x0c092f9cu: goto P_0c092f9c;
case 0x0c092f9eu: goto P_0c092f9e;
case 0x0c092fa0u: goto P_0c092fa0;
case 0x0c092fa2u: goto P_0c092fa2;
case 0x0c092fa4u: goto P_0c092fa4;
case 0x0c092fa6u: goto P_0c092fa6;
case 0x0c092fa8u: goto P_0c092fa8;
case 0x0c092faau: goto P_0c092faa;
case 0x0c092facu: goto P_0c092fac;
case 0x0c092faeu: goto P_0c092fae;
case 0x0c092fb0u: goto P_0c092fb0;
case 0x0c092fb2u: goto P_0c092fb2;
case 0x0c092fb4u: goto P_0c092fb4;
case 0x0c092fb6u: goto P_0c092fb6;
case 0x0c092fb8u: goto P_0c092fb8;
case 0x0c092fbau: goto P_0c092fba;
case 0x0c092fbcu: goto P_0c092fbc;
case 0x0c092fbeu: goto P_0c092fbe;
case 0x0c092fc0u: goto P_0c092fc0;
case 0x0c092fc2u: goto P_0c092fc2;
case 0x0c092fc4u: goto P_0c092fc4;
case 0x0c092fc6u: goto P_0c092fc6;
case 0x0c092fc8u: goto P_0c092fc8;
case 0x0c092fcau: goto P_0c092fca;
case 0x0c092fccu: goto P_0c092fcc;
case 0x0c092fceu: goto P_0c092fce;
case 0x0c092fd0u: goto P_0c092fd0;
case 0x0c092fd2u: goto P_0c092fd2;
case 0x0c092fd4u: goto P_0c092fd4;
case 0x0c092fd6u: goto P_0c092fd6;
case 0x0c092fd8u: goto P_0c092fd8;
case 0x0c092fdau: goto P_0c092fda;
case 0x0c092fdcu: goto P_0c092fdc;
case 0x0c092fdeu: goto P_0c092fde;
case 0x0c092fe0u: goto P_0c092fe0;
case 0x0c092fe2u: goto P_0c092fe2;
case 0x0c092fe4u: goto P_0c092fe4;
case 0x0c092fe6u: goto P_0c092fe6;
case 0x0c092fe8u: goto P_0c092fe8;
case 0x0c092feau: goto P_0c092fea;
case 0x0c092fecu: goto P_0c092fec;
case 0x0c092feeu: goto P_0c092fee;
case 0x0c092ff0u: goto P_0c092ff0;
case 0x0c092ff2u: goto P_0c092ff2;
case 0x0c092ff4u: goto P_0c092ff4;
case 0x0c092ff6u: goto P_0c092ff6;
case 0x0c092ff8u: goto P_0c092ff8;
case 0x0c092ffau: goto P_0c092ffa;
case 0x0c092ffcu: goto P_0c092ffc;
case 0x0c092ffeu: goto P_0c092ffe;
case 0x0c093000u: goto P_0c093000;
case 0x0c093002u: goto P_0c093002;
case 0x0c093004u: goto P_0c093004;
case 0x0c093006u: goto P_0c093006;
case 0x0c093008u: goto P_0c093008;
case 0x0c09300au: goto P_0c09300a;
case 0x0c09300cu: goto P_0c09300c;
case 0x0c09300eu: goto P_0c09300e;
case 0x0c093010u: goto P_0c093010;
case 0x0c093012u: goto P_0c093012;
case 0x0c093014u: goto P_0c093014;
case 0x0c093016u: goto P_0c093016;
case 0x0c093018u: goto P_0c093018;
case 0x0c09301au: goto P_0c09301a;
case 0x0c09301cu: goto P_0c09301c;
case 0x0c09301eu: goto P_0c09301e;
case 0x0c093020u: goto P_0c093020;
case 0x0c093022u: goto P_0c093022;
case 0x0c093024u: goto P_0c093024;
case 0x0c093026u: goto P_0c093026;
case 0x0c093028u: goto P_0c093028;
default: return vf3_matrix_family(target,s,ram);
}
P_0c092e54: /* original 2fe6, guest PC 0x0c092e54 */
if(!s->budget--) { s->failed_pc=0x0c092e54u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c092e56;
P_0c092e56: /* original e308, guest PC 0x0c092e56 */
if(!s->budget--) { s->failed_pc=0x0c092e56u; return 0; }
r[3]=0x00000008u;
goto P_0c092e58;
P_0c092e58: /* original 2fd6, guest PC 0x0c092e58 */
if(!s->budget--) { s->failed_pc=0x0c092e58u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c092e5a;
P_0c092e5a: /* original 2638, guest PC 0x0c092e5a */
if(!s->budget--) { s->failed_pc=0x0c092e5au; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c092e5c;
P_0c092e5c: /* original 7ff4, guest PC 0x0c092e5c */
if(!s->budget--) { s->failed_pc=0x0c092e5cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c092e5e;
P_0c092e5e: /* original 6e43, guest PC 0x0c092e5e */
if(!s->budget--) { s->failed_pc=0x0c092e5eu; return 0; }
r[14]=r[4];
goto P_0c092e60;
P_0c092e60: /* original 8d03, guest PC 0x0c092e60 */
if(!s->budget--) { s->failed_pc=0x0c092e60u; return 0; }
cond=r[17]&1u;
r[13]=r[7];
if(cond) { goto P_0c092e6a; }
goto P_0c092e64;
P_0c092e62: /* original 6d73, guest PC 0x0c092e62 */
if(!s->budget--) { s->failed_pc=0x0c092e62u; return 0; }
r[13]=r[7];
goto P_0c092e64;
P_0c092e64: /* original d20e, guest PC 0x0c092e64 */
if(!s->budget--) { s->failed_pc=0x0c092e64u; return 0; }
r[2]=read(ram,0x0c092ea0u,4);
goto P_0c092e66;
P_0c092e66: /* original 422b, guest PC 0x0c092e66 */
if(!s->budget--) { s->failed_pc=0x0c092e66u; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c092f14u: goto P_0c092f14;
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
P_0c092e68: /* original 0009, guest PC 0x0c092e68 */
if(!s->budget--) { s->failed_pc=0x0c092e68u; return 0; }
goto P_0c092e6a;
P_0c092e6a: /* original 6051, guest PC 0x0c092e6a */
if(!s->budget--) { s->failed_pc=0x0c092e6au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[0]=tmp;
goto P_0c092e6c;
P_0c092e6c: /* original c810, guest PC 0x0c092e6c */
if(!s->budget--) { s->failed_pc=0x0c092e6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c092e6e;
P_0c092e6e: /* original 890c, guest PC 0x0c092e6e */
if(!s->budget--) { s->failed_pc=0x0c092e6eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c092e8a; }
goto P_0c092e70;
P_0c092e70: /* original f3d8, guest PC 0x0c092e70 */
if(!s->budget--) { s->failed_pc=0x0c092e70u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c092e72;
P_0c092e72: /* original e05c, guest PC 0x0c092e72 */
if(!s->budget--) { s->failed_pc=0x0c092e72u; return 0; }
r[0]=0x0000005cu;
goto P_0c092e74;
P_0c092e74: /* original fe37, guest PC 0x0c092e74 */
if(!s->budget--) { s->failed_pc=0x0c092e74u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c092e76;
P_0c092e76: /* original e004, guest PC 0x0c092e76 */
if(!s->budget--) { s->failed_pc=0x0c092e76u; return 0; }
r[0]=0x00000004u;
goto P_0c092e78;
P_0c092e78: /* original f3d6, guest PC 0x0c092e78 */
if(!s->budget--) { s->failed_pc=0x0c092e78u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c092e7a;
P_0c092e7a: /* original e060, guest PC 0x0c092e7a */
if(!s->budget--) { s->failed_pc=0x0c092e7au; return 0; }
r[0]=0x00000060u;
goto P_0c092e7c;
P_0c092e7c: /* original fe37, guest PC 0x0c092e7c */
if(!s->budget--) { s->failed_pc=0x0c092e7cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c092e7e;
P_0c092e7e: /* original e008, guest PC 0x0c092e7e */
if(!s->budget--) { s->failed_pc=0x0c092e7eu; return 0; }
r[0]=0x00000008u;
goto P_0c092e80;
P_0c092e80: /* original d107, guest PC 0x0c092e80 */
if(!s->budget--) { s->failed_pc=0x0c092e80u; return 0; }
r[1]=read(ram,0x0c092ea0u,4);
goto P_0c092e82;
P_0c092e82: /* original f3d6, guest PC 0x0c092e82 */
if(!s->budget--) { s->failed_pc=0x0c092e82u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c092e84;
P_0c092e84: /* original e064, guest PC 0x0c092e84 */
if(!s->budget--) { s->failed_pc=0x0c092e84u; return 0; }
r[0]=0x00000064u;
goto P_0c092e86;
P_0c092e86: /* original 412b, guest PC 0x0c092e86 */
if(!s->budget--) { s->failed_pc=0x0c092e86u; return 0; }
target=r[1];
vf3_matrix_store(s,ram,3,r[14]+r[0]);
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
P_0c092e88: /* original fe37, guest PC 0x0c092e88 */
if(!s->budget--) { s->failed_pc=0x0c092e88u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c092e8a;
P_0c092e8a: /* original 65e3, guest PC 0x0c092e8a */
if(!s->budget--) { s->failed_pc=0x0c092e8au; return 0; }
r[5]=r[14];
goto P_0c092e8c;
P_0c092e8c: /* original 64f3, guest PC 0x0c092e8c */
if(!s->budget--) { s->failed_pc=0x0c092e8cu; return 0; }
r[4]=r[15];
goto P_0c092e8e;
P_0c092e8e: /* original 755c, guest PC 0x0c092e8e */
if(!s->budget--) { s->failed_pc=0x0c092e8eu; return 0; }
r[5]+=0x0000005cu;
goto P_0c092e90;
P_0c092e90: /* original 66d3, guest PC 0x0c092e90 */
if(!s->budget--) { s->failed_pc=0x0c092e90u; return 0; }
r[6]=r[13];
goto P_0c092e92;
P_0c092e92: /* original a007, guest PC 0x0c092e92 */
if(!s->budget--) { s->failed_pc=0x0c092e92u; return 0; }
goto P_0c092ea4;
P_0c092e94: /* original 0009, guest PC 0x0c092e94 */
if(!s->budget--) { s->failed_pc=0x0c092e94u; return 0; }
if(!vf3_matrix_family(0x0c092e96u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c092e96u; return 0; } return 1;
P_0c092ea4: /* original f059, guest PC 0x0c092ea4 */
if(!s->budget--) { s->failed_pc=0x0c092ea4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092ea6;
P_0c092ea6: /* original f369, guest PC 0x0c092ea6 */
if(!s->budget--) { s->failed_pc=0x0c092ea6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c092ea8;
P_0c092ea8: /* original f159, guest PC 0x0c092ea8 */
if(!s->budget--) { s->failed_pc=0x0c092ea8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092eaa;
P_0c092eaa: /* original f469, guest PC 0x0c092eaa */
if(!s->budget--) { s->failed_pc=0x0c092eaau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c092eac;
P_0c092eac: /* original f259, guest PC 0x0c092eac */
if(!s->budget--) { s->failed_pc=0x0c092eacu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092eae;
P_0c092eae: /* original f569, guest PC 0x0c092eae */
if(!s->budget--) { s->failed_pc=0x0c092eaeu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c092eb0;
P_0c092eb0: /* original 740c, guest PC 0x0c092eb0 */
if(!s->budget--) { s->failed_pc=0x0c092eb0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c092eb2;
P_0c092eb2: /* original f030, guest PC 0x0c092eb2 */
if(!s->budget--) { s->failed_pc=0x0c092eb2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c092eb4;
P_0c092eb4: /* original f250, guest PC 0x0c092eb4 */
if(!s->budget--) { s->failed_pc=0x0c092eb4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c092eb6;
P_0c092eb6: /* original f140, guest PC 0x0c092eb6 */
if(!s->budget--) { s->failed_pc=0x0c092eb6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c092eb8;
P_0c092eb8: /* original f42b, guest PC 0x0c092eb8 */
if(!s->budget--) { s->failed_pc=0x0c092eb8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c092eba;
P_0c092eba: /* original f41b, guest PC 0x0c092eba */
if(!s->budget--) { s->failed_pc=0x0c092ebau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c092ebc;
P_0c092ebc: /* original f40b, guest PC 0x0c092ebc */
if(!s->budget--) { s->failed_pc=0x0c092ebcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c092ebe;
P_0c092ebe: /* original 0009, guest PC 0x0c092ebe */
if(!s->budget--) { s->failed_pc=0x0c092ebeu; return 0; }
goto P_0c092ec0;
P_0c092ec0: /* original 64f3, guest PC 0x0c092ec0 */
if(!s->budget--) { s->failed_pc=0x0c092ec0u; return 0; }
r[4]=r[15];
goto P_0c092ec2;
P_0c092ec2: /* original f049, guest PC 0x0c092ec2 */
if(!s->budget--) { s->failed_pc=0x0c092ec2u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c092ec4;
P_0c092ec4: /* original f149, guest PC 0x0c092ec4 */
if(!s->budget--) { s->failed_pc=0x0c092ec4u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c092ec6;
P_0c092ec6: /* original f248, guest PC 0x0c092ec6 */
if(!s->budget--) { s->failed_pc=0x0c092ec6u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
goto P_0c092ec8;
P_0c092ec8: /* original f38d, guest PC 0x0c092ec8 */
if(!s->budget--) { s->failed_pc=0x0c092ec8u; return 0; }
fr[3]=0;
goto P_0c092eca;
P_0c092eca: /* original f0ed, guest PC 0x0c092eca */
if(!s->budget--) { s->failed_pc=0x0c092ecau; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c092ecc;
P_0c092ecc: /* original f03c, guest PC 0x0c092ecc */
if(!s->budget--) { s->failed_pc=0x0c092eccu; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c092ece;
P_0c092ece: /* original 0009, guest PC 0x0c092ece */
if(!s->budget--) { s->failed_pc=0x0c092eceu; return 0; }
goto P_0c092ed0;
P_0c092ed0: /* original f38d, guest PC 0x0c092ed0 */
if(!s->budget--) { s->failed_pc=0x0c092ed0u; return 0; }
fr[3]=0;
goto P_0c092ed2;
P_0c092ed2: /* original f40c, guest PC 0x0c092ed2 */
if(!s->budget--) { s->failed_pc=0x0c092ed2u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c092ed4;
P_0c092ed4: /* original f434, guest PC 0x0c092ed4 */
if(!s->budget--) { s->failed_pc=0x0c092ed4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c092ed6;
P_0c092ed6: /* original 8b02, guest PC 0x0c092ed6 */
if(!s->budget--) { s->failed_pc=0x0c092ed6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c092ede; }
goto P_0c092ed8;
P_0c092ed8: /* original d307, guest PC 0x0c092ed8 */
if(!s->budget--) { s->failed_pc=0x0c092ed8u; return 0; }
r[3]=read(ram,0x0c092ef8u,4);
goto P_0c092eda;
P_0c092eda: /* original 432b, guest PC 0x0c092eda */
if(!s->budget--) { s->failed_pc=0x0c092edau; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c092f14u: goto P_0c092f14;
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
P_0c092edc: /* original 0009, guest PC 0x0c092edc */
if(!s->budget--) { s->failed_pc=0x0c092edcu; return 0; }
goto P_0c092ede;
P_0c092ede: /* original c707, guest PC 0x0c092ede */
if(!s->budget--) { s->failed_pc=0x0c092edeu; return 0; }
r[0]=code_base|0x00092efcu;
goto P_0c092ee0;
P_0c092ee0: /* original f308, guest PC 0x0c092ee0 */
if(!s->budget--) { s->failed_pc=0x0c092ee0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c092ee2;
P_0c092ee2: /* original f345, guest PC 0x0c092ee2 */
if(!s->budget--) { s->failed_pc=0x0c092ee2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c092ee4;
P_0c092ee4: /* original 8b01, guest PC 0x0c092ee4 */
if(!s->budget--) { s->failed_pc=0x0c092ee4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c092eea; }
goto P_0c092ee6;
P_0c092ee6: /* original a001, guest PC 0x0c092ee6 */
if(!s->budget--) { s->failed_pc=0x0c092ee6u; return 0; }
fr[4]=0;
goto P_0c092eec;
P_0c092ee8: /* original f48d, guest PC 0x0c092ee8 */
if(!s->budget--) { s->failed_pc=0x0c092ee8u; return 0; }
fr[4]=0;
goto P_0c092eea;
P_0c092eea: /* original f47d, guest PC 0x0c092eea */
if(!s->budget--) { s->failed_pc=0x0c092eeau; return 0; }
if(!vf3_fpu_fsrra(fr[4],r[18],&fr[4])) goto unsupported;
goto P_0c092eec;
P_0c092eec: /* original 64e3, guest PC 0x0c092eec */
if(!s->budget--) { s->failed_pc=0x0c092eecu; return 0; }
r[4]=r[14];
goto P_0c092eee;
P_0c092eee: /* original 745c, guest PC 0x0c092eee */
if(!s->budget--) { s->failed_pc=0x0c092eeeu; return 0; }
r[4]+=0x0000005cu;
goto P_0c092ef0;
P_0c092ef0: /* original 65f3, guest PC 0x0c092ef0 */
if(!s->budget--) { s->failed_pc=0x0c092ef0u; return 0; }
r[5]=r[15];
goto P_0c092ef2;
P_0c092ef2: /* original a005, guest PC 0x0c092ef2 */
if(!s->budget--) { s->failed_pc=0x0c092ef2u; return 0; }
goto P_0c092f00;
P_0c092ef4: /* original 0009, guest PC 0x0c092ef4 */
if(!s->budget--) { s->failed_pc=0x0c092ef4u; return 0; }
if(!vf3_matrix_family(0x0c092ef6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c092ef6u; return 0; } return 1;
P_0c092f00: /* original f059, guest PC 0x0c092f00 */
if(!s->budget--) { s->failed_pc=0x0c092f00u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092f02;
P_0c092f02: /* original f159, guest PC 0x0c092f02 */
if(!s->budget--) { s->failed_pc=0x0c092f02u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092f04;
P_0c092f04: /* original f259, guest PC 0x0c092f04 */
if(!s->budget--) { s->failed_pc=0x0c092f04u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092f06;
P_0c092f06: /* original 740c, guest PC 0x0c092f06 */
if(!s->budget--) { s->failed_pc=0x0c092f06u; return 0; }
r[4]+=0x0000000cu;
goto P_0c092f08;
P_0c092f08: /* original f242, guest PC 0x0c092f08 */
if(!s->budget--) { s->failed_pc=0x0c092f08u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c092f0a;
P_0c092f0a: /* original f142, guest PC 0x0c092f0a */
if(!s->budget--) { s->failed_pc=0x0c092f0au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c092f0c;
P_0c092f0c: /* original f042, guest PC 0x0c092f0c */
if(!s->budget--) { s->failed_pc=0x0c092f0cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c092f0e;
P_0c092f0e: /* original f42b, guest PC 0x0c092f0e */
if(!s->budget--) { s->failed_pc=0x0c092f0eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c092f10;
P_0c092f10: /* original f41b, guest PC 0x0c092f10 */
if(!s->budget--) { s->failed_pc=0x0c092f10u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c092f12;
P_0c092f12: /* original f40b, guest PC 0x0c092f12 */
if(!s->budget--) { s->failed_pc=0x0c092f12u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c092f14;
P_0c092f14: /* original 7f0c, guest PC 0x0c092f14 */
if(!s->budget--) { s->failed_pc=0x0c092f14u; return 0; }
r[15]+=0x0000000cu;
goto P_0c092f16;
P_0c092f16: /* original 6df6, guest PC 0x0c092f16 */
if(!s->budget--) { s->failed_pc=0x0c092f16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c092f18;
P_0c092f18: /* original 000b, guest PC 0x0c092f18 */
if(!s->budget--) { s->failed_pc=0x0c092f18u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c092f1a: /* original 6ef6, guest PC 0x0c092f1a */
if(!s->budget--) { s->failed_pc=0x0c092f1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c092f1c;
P_0c092f1c: /* original 2fe6, guest PC 0x0c092f1c */
if(!s->budget--) { s->failed_pc=0x0c092f1cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c092f1e;
P_0c092f1e: /* original e050, guest PC 0x0c092f1e */
if(!s->budget--) { s->failed_pc=0x0c092f1eu; return 0; }
r[0]=0x00000050u;
goto P_0c092f20;
P_0c092f20: /* original 6372, guest PC 0x0c092f20 */
if(!s->budget--) { s->failed_pc=0x0c092f20u; return 0; }
tmp=read(ram,r[7],4);
r[3]=tmp;
goto P_0c092f22;
P_0c092f22: /* original 5ef3, guest PC 0x0c092f22 */
if(!s->budget--) { s->failed_pc=0x0c092f22u; return 0; }
r[14]=read(ram,r[15]+12,4);
goto P_0c092f24;
P_0c092f24: /* original 2338, guest PC 0x0c092f24 */
if(!s->budget--) { s->failed_pc=0x0c092f24u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c092f26;
P_0c092f26: /* original 8f02, guest PC 0x0c092f26 */
if(!s->budget--) { s->failed_pc=0x0c092f26u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[4]+r[0]);
if(!cond) { goto P_0c092f2e; }
goto P_0c092f2a;
P_0c092f28: /* original f446, guest PC 0x0c092f28 */
if(!s->budget--) { s->failed_pc=0x0c092f28u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c092f2a;
P_0c092f2a: /* original a07c, guest PC 0x0c092f2a */
if(!s->budget--) { s->failed_pc=0x0c092f2au; return 0; }
goto P_0c093026;
P_0c092f2c: /* original 0009, guest PC 0x0c092f2c */
if(!s->budget--) { s->failed_pc=0x0c092f2cu; return 0; }
goto P_0c092f2e;
P_0c092f2e: /* original f38d, guest PC 0x0c092f2e */
if(!s->budget--) { s->failed_pc=0x0c092f2eu; return 0; }
fr[3]=0;
goto P_0c092f30;
P_0c092f30: /* original f434, guest PC 0x0c092f30 */
if(!s->budget--) { s->failed_pc=0x0c092f30u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c092f32;
P_0c092f32: /* original 8978, guest PC 0x0c092f32 */
if(!s->budget--) { s->failed_pc=0x0c092f32u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093026; }
goto P_0c092f34;
P_0c092f34: /* original 6372, guest PC 0x0c092f34 */
if(!s->budget--) { s->failed_pc=0x0c092f34u; return 0; }
tmp=read(ram,r[7],4);
r[3]=tmp;
goto P_0c092f36;
P_0c092f36: /* original e004, guest PC 0x0c092f36 */
if(!s->budget--) { s->failed_pc=0x0c092f36u; return 0; }
r[0]=0x00000004u;
goto P_0c092f38;
P_0c092f38: /* original 7304, guest PC 0x0c092f38 */
if(!s->budget--) { s->failed_pc=0x0c092f38u; return 0; }
r[3]+=0x00000004u;
goto P_0c092f3a;
P_0c092f3a: /* original 2732, guest PC 0x0c092f3a */
if(!s->budget--) { s->failed_pc=0x0c092f3au; return 0; }
write(ram,r[7],r[3],4);
goto P_0c092f3c;
P_0c092f3c: /* original f338, guest PC 0x0c092f3c */
if(!s->budget--) { s->failed_pc=0x0c092f3cu; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c092f3e;
P_0c092f3e: /* original 53f1, guest PC 0x0c092f3e */
if(!s->budget--) { s->failed_pc=0x0c092f3eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c092f40;
P_0c092f40: /* original f342, guest PC 0x0c092f40 */
if(!s->budget--) { s->failed_pc=0x0c092f40u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c092f42;
P_0c092f42: /* original f236, guest PC 0x0c092f42 */
if(!s->budget--) { s->failed_pc=0x0c092f42u; return 0; }
vf3_matrix_load(s,ram,2,r[3]+r[0]);
goto P_0c092f44;
P_0c092f44: /* original e044, guest PC 0x0c092f44 */
if(!s->budget--) { s->failed_pc=0x0c092f44u; return 0; }
r[0]=0x00000044u;
goto P_0c092f46;
P_0c092f46: /* original f846, guest PC 0x0c092f46 */
if(!s->budget--) { s->failed_pc=0x0c092f46u; return 0; }
vf3_matrix_load(s,ram,8,r[4]+r[0]);
goto P_0c092f48;
P_0c092f48: /* original e04c, guest PC 0x0c092f48 */
if(!s->budget--) { s->failed_pc=0x0c092f48u; return 0; }
r[0]=0x0000004cu;
goto P_0c092f4a;
P_0c092f4a: /* original fa46, guest PC 0x0c092f4a */
if(!s->budget--) { s->failed_pc=0x0c092f4au; return 0; }
vf3_matrix_load(s,ram,10,r[4]+r[0]);
goto P_0c092f4c;
P_0c092f4c: /* original c74f, guest PC 0x0c092f4c */
if(!s->budget--) { s->failed_pc=0x0c092f4cu; return 0; }
r[0]=code_base|0x0009308cu;
goto P_0c092f4e;
P_0c092f4e: /* original f908, guest PC 0x0c092f4e */
if(!s->budget--) { s->failed_pc=0x0c092f4eu; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c092f50;
P_0c092f50: /* original f53c, guest PC 0x0c092f50 */
if(!s->budget--) { s->failed_pc=0x0c092f50u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c092f52;
P_0c092f52: /* original f521, guest PC 0x0c092f52 */
if(!s->budget--) { s->failed_pc=0x0c092f52u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'-');
goto P_0c092f54;
P_0c092f54: /* original 8548, guest PC 0x0c092f54 */
if(!s->budget--) { s->failed_pc=0x0c092f54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+16,2);
goto P_0c092f56;
P_0c092f56: /* original 600d, guest PC 0x0c092f56 */
if(!s->budget--) { s->failed_pc=0x0c092f56u; return 0; }
r[0]=r[0]&65535u;
goto P_0c092f58;
P_0c092f58: /* original c801, guest PC 0x0c092f58 */
if(!s->budget--) { s->failed_pc=0x0c092f58u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c092f5a;
P_0c092f5a: /* original 8d2a, guest PC 0x0c092f5a */
if(!s->budget--) { s->failed_pc=0x0c092f5au; return 0; }
cond=r[17]&1u;
fr[7]=0x3f800000u;
if(cond) { goto P_0c092fb2; }
goto P_0c092f5e;
P_0c092f5c: /* original f79d, guest PC 0x0c092f5c */
if(!s->budget--) { s->failed_pc=0x0c092f5cu; return 0; }
fr[7]=0x3f800000u;
goto P_0c092f5e;
P_0c092f5e: /* original e010, guest PC 0x0c092f5e */
if(!s->budget--) { s->failed_pc=0x0c092f5eu; return 0; }
r[0]=0x00000010u;
goto P_0c092f60;
P_0c092f60: /* original f47c, guest PC 0x0c092f60 */
if(!s->budget--) { s->failed_pc=0x0c092f60u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c092f62;
P_0c092f62: /* original f366, guest PC 0x0c092f62 */
if(!s->budget--) { s->failed_pc=0x0c092f62u; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c092f64;
P_0c092f64: /* original e004, guest PC 0x0c092f64 */
if(!s->budget--) { s->failed_pc=0x0c092f64u; return 0; }
r[0]=0x00000004u;
goto P_0c092f66;
P_0c092f66: /* original f666, guest PC 0x0c092f66 */
if(!s->budget--) { s->failed_pc=0x0c092f66u; return 0; }
vf3_matrix_load(s,ram,6,r[6]+r[0]);
goto P_0c092f68;
P_0c092f68: /* original fb7c, guest PC 0x0c092f68 */
if(!s->budget--) { s->failed_pc=0x0c092f68u; return 0; }
vf3_matrix_move(s,11,7);
goto P_0c092f6a;
P_0c092f6a: /* original f631, guest PC 0x0c092f6a */
if(!s->budget--) { s->failed_pc=0x0c092f6au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c092f6c;
P_0c092f6c: /* original f37c, guest PC 0x0c092f6c */
if(!s->budget--) { s->failed_pc=0x0c092f6cu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c092f6e;
P_0c092f6e: /* original f06c, guest PC 0x0c092f6e */
if(!s->budget--) { s->failed_pc=0x0c092f6eu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c092f70;
P_0c092f70: /* original f45e, guest PC 0x0c092f70 */
if(!s->budget--) { s->failed_pc=0x0c092f70u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[5],fr[4],r[18]);
goto P_0c092f72;
P_0c092f72: /* original f05c, guest PC 0x0c092f72 */
if(!s->budget--) { s->failed_pc=0x0c092f72u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c092f74;
P_0c092f74: /* original fb5e, guest PC 0x0c092f74 */
if(!s->budget--) { s->failed_pc=0x0c092f74u; return 0; }
fr[11]=vf3_fpu_mac(fr[0],fr[5],fr[11],r[18]);
goto P_0c092f76;
P_0c092f76: /* original f06c, guest PC 0x0c092f76 */
if(!s->budget--) { s->failed_pc=0x0c092f76u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c092f78;
P_0c092f78: /* original f36e, guest PC 0x0c092f78 */
if(!s->budget--) { s->failed_pc=0x0c092f78u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[6],fr[3],r[18]);
goto P_0c092f7a;
P_0c092f7a: /* original f9b5, guest PC 0x0c092f7a */
if(!s->budget--) { s->failed_pc=0x0c092f7au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[11]))!=0);
goto P_0c092f7c;
P_0c092f7c: /* original 8f02, guest PC 0x0c092f7c */
if(!s->budget--) { s->failed_pc=0x0c092f7cu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,6,3);
if(!cond) { goto P_0c092f84; }
goto P_0c092f80;
P_0c092f7e: /* original f63c, guest PC 0x0c092f7e */
if(!s->budget--) { s->failed_pc=0x0c092f7eu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c092f80;
P_0c092f80: /* original a002, guest PC 0x0c092f80 */
if(!s->budget--) { s->failed_pc=0x0c092f80u; return 0; }
fr[2]=0;
goto P_0c092f88;
P_0c092f82: /* original f28d, guest PC 0x0c092f82 */
if(!s->budget--) { s->failed_pc=0x0c092f82u; return 0; }
fr[2]=0;
goto P_0c092f84;
P_0c092f84: /* original f2bc, guest PC 0x0c092f84 */
if(!s->budget--) { s->failed_pc=0x0c092f84u; return 0; }
vf3_matrix_move(s,2,11);
goto P_0c092f86;
P_0c092f86: /* original f27d, guest PC 0x0c092f86 */
if(!s->budget--) { s->failed_pc=0x0c092f86u; return 0; }
if(!vf3_fpu_fsrra(fr[2],r[18],&fr[2])) goto unsupported;
goto P_0c092f88;
P_0c092f88: /* original f965, guest PC 0x0c092f88 */
if(!s->budget--) { s->failed_pc=0x0c092f88u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[6]))!=0);
goto P_0c092f8a;
P_0c092f8a: /* original 8f02, guest PC 0x0c092f8a */
if(!s->budget--) { s->failed_pc=0x0c092f8au; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'*');
if(!cond) { goto P_0c092f92; }
goto P_0c092f8e;
P_0c092f8c: /* original f422, guest PC 0x0c092f8c */
if(!s->budget--) { s->failed_pc=0x0c092f8cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'*');
goto P_0c092f8e;
P_0c092f8e: /* original a002, guest PC 0x0c092f8e */
if(!s->budget--) { s->failed_pc=0x0c092f8eu; return 0; }
fr[3]=0;
goto P_0c092f96;
P_0c092f90: /* original f38d, guest PC 0x0c092f90 */
if(!s->budget--) { s->failed_pc=0x0c092f90u; return 0; }
fr[3]=0;
goto P_0c092f92;
P_0c092f92: /* original f36c, guest PC 0x0c092f92 */
if(!s->budget--) { s->failed_pc=0x0c092f92u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c092f94;
P_0c092f94: /* original f37d, guest PC 0x0c092f94 */
if(!s->budget--) { s->failed_pc=0x0c092f94u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c092f96;
P_0c092f96: /* original f432, guest PC 0x0c092f96 */
if(!s->budget--) { s->failed_pc=0x0c092f96u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c092f98;
P_0c092f98: /* original f34c, guest PC 0x0c092f98 */
if(!s->budget--) { s->failed_pc=0x0c092f98u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c092f9a;
P_0c092f9a: /* original f342, guest PC 0x0c092f9a */
if(!s->budget--) { s->failed_pc=0x0c092f9au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c092f9c;
P_0c092f9c: /* original f47c, guest PC 0x0c092f9c */
if(!s->budget--) { s->failed_pc=0x0c092f9cu; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c092f9e;
P_0c092f9e: /* original f431, guest PC 0x0c092f9e */
if(!s->budget--) { s->failed_pc=0x0c092f9eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c092fa0;
P_0c092fa0: /* original f945, guest PC 0x0c092fa0 */
if(!s->budget--) { s->failed_pc=0x0c092fa0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[4]))!=0);
goto P_0c092fa2;
P_0c092fa2: /* original 8b01, guest PC 0x0c092fa2 */
if(!s->budget--) { s->failed_pc=0x0c092fa2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c092fa8; }
goto P_0c092fa4;
P_0c092fa4: /* original a002, guest PC 0x0c092fa4 */
if(!s->budget--) { s->failed_pc=0x0c092fa4u; return 0; }
fr[6]=0;
goto P_0c092fac;
P_0c092fa6: /* original f68d, guest PC 0x0c092fa6 */
if(!s->budget--) { s->failed_pc=0x0c092fa6u; return 0; }
fr[6]=0;
goto P_0c092fa8;
P_0c092fa8: /* original f64c, guest PC 0x0c092fa8 */
if(!s->budget--) { s->failed_pc=0x0c092fa8u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c092faa;
P_0c092faa: /* original f66d, guest PC 0x0c092faa */
if(!s->budget--) { s->failed_pc=0x0c092faau; return 0; }
fr[6]=vf3_fpu_sqrt(fr[6],r[18]);
goto P_0c092fac;
P_0c092fac: /* original f862, guest PC 0x0c092fac */
if(!s->budget--) { s->failed_pc=0x0c092facu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'*');
goto P_0c092fae;
P_0c092fae: /* original a028, guest PC 0x0c092fae */
if(!s->budget--) { s->failed_pc=0x0c092faeu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c093002;
P_0c092fb0: /* original f562, guest PC 0x0c092fb0 */
if(!s->budget--) { s->failed_pc=0x0c092fb0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c092fb2;
P_0c092fb2: /* original e048, guest PC 0x0c092fb2 */
if(!s->budget--) { s->failed_pc=0x0c092fb2u; return 0; }
r[0]=0x00000048u;
goto P_0c092fb4;
P_0c092fb4: /* original d336, guest PC 0x0c092fb4 */
if(!s->budget--) { s->failed_pc=0x0c092fb4u; return 0; }
r[3]=read(ram,0x0c093090u,4);
goto P_0c092fb6;
P_0c092fb6: /* original 025e, guest PC 0x0c092fb6 */
if(!s->budget--) { s->failed_pc=0x0c092fb6u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c092fb8;
P_0c092fb8: /* original 2238, guest PC 0x0c092fb8 */
if(!s->budget--) { s->failed_pc=0x0c092fb8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c092fba;
P_0c092fba: /* original 8b34, guest PC 0x0c092fba */
if(!s->budget--) { s->failed_pc=0x0c092fbau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c093026; }
goto P_0c092fbc;
P_0c092fbc: /* original e014, guest PC 0x0c092fbc */
if(!s->budget--) { s->failed_pc=0x0c092fbcu; return 0; }
r[0]=0x00000014u;
goto P_0c092fbe;
P_0c092fbe: /* original f268, guest PC 0x0c092fbe */
if(!s->budget--) { s->failed_pc=0x0c092fbeu; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c092fc0;
P_0c092fc0: /* original f066, guest PC 0x0c092fc0 */
if(!s->budget--) { s->failed_pc=0x0c092fc0u; return 0; }
vf3_matrix_load(s,ram,0,r[6]+r[0]);
goto P_0c092fc2;
P_0c092fc2: /* original e008, guest PC 0x0c092fc2 */
if(!s->budget--) { s->failed_pc=0x0c092fc2u; return 0; }
r[0]=0x00000008u;
goto P_0c092fc4;
P_0c092fc4: /* original f366, guest PC 0x0c092fc4 */
if(!s->budget--) { s->failed_pc=0x0c092fc4u; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c092fc6;
P_0c092fc6: /* original e00c, guest PC 0x0c092fc6 */
if(!s->budget--) { s->failed_pc=0x0c092fc6u; return 0; }
r[0]=0x0000000cu;
goto P_0c092fc8;
P_0c092fc8: /* original f301, guest PC 0x0c092fc8 */
if(!s->budget--) { s->failed_pc=0x0c092fc8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'-');
goto P_0c092fca;
P_0c092fca: /* original f066, guest PC 0x0c092fca */
if(!s->budget--) { s->failed_pc=0x0c092fcau; return 0; }
vf3_matrix_load(s,ram,0,r[6]+r[0]);
goto P_0c092fcc;
P_0c092fcc: /* original e054, guest PC 0x0c092fcc */
if(!s->budget--) { s->failed_pc=0x0c092fccu; return 0; }
r[0]=0x00000054u;
goto P_0c092fce;
P_0c092fce: /* original f201, guest PC 0x0c092fce */
if(!s->budget--) { s->failed_pc=0x0c092fceu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[0],r[18],'-');
goto P_0c092fd0;
P_0c092fd0: /* original f0ac, guest PC 0x0c092fd0 */
if(!s->budget--) { s->failed_pc=0x0c092fd0u; return 0; }
vf3_matrix_move(s,0,10);
goto P_0c092fd2;
P_0c092fd2: /* original f282, guest PC 0x0c092fd2 */
if(!s->budget--) { s->failed_pc=0x0c092fd2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[8],r[18],'*');
goto P_0c092fd4;
P_0c092fd4: /* original f23e, guest PC 0x0c092fd4 */
if(!s->budget--) { s->failed_pc=0x0c092fd4u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[3],fr[2],r[18]);
goto P_0c092fd6;
P_0c092fd6: /* original f346, guest PC 0x0c092fd6 */
if(!s->budget--) { s->failed_pc=0x0c092fd6u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c092fd8;
P_0c092fd8: /* original e028, guest PC 0x0c092fd8 */
if(!s->budget--) { s->failed_pc=0x0c092fd8u; return 0; }
r[0]=0x00000028u;
goto P_0c092fda;
P_0c092fda: /* original f42c, guest PC 0x0c092fda */
if(!s->budget--) { s->failed_pc=0x0c092fdau; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c092fdc;
P_0c092fdc: /* original f266, guest PC 0x0c092fdc */
if(!s->budget--) { s->failed_pc=0x0c092fdcu; return 0; }
vf3_matrix_load(s,ram,2,r[6]+r[0]);
goto P_0c092fde;
P_0c092fde: /* original f232, guest PC 0x0c092fde */
if(!s->budget--) { s->failed_pc=0x0c092fdeu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c092fe0;
P_0c092fe0: /* original f422, guest PC 0x0c092fe0 */
if(!s->budget--) { s->failed_pc=0x0c092fe0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'*');
goto P_0c092fe2;
P_0c092fe2: /* original f28d, guest PC 0x0c092fe2 */
if(!s->budget--) { s->failed_pc=0x0c092fe2u; return 0; }
fr[2]=0;
goto P_0c092fe4;
P_0c092fe4: /* original f442, guest PC 0x0c092fe4 */
if(!s->budget--) { s->failed_pc=0x0c092fe4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[4],r[18],'*');
goto P_0c092fe6;
P_0c092fe6: /* original f34c, guest PC 0x0c092fe6 */
if(!s->budget--) { s->failed_pc=0x0c092fe6u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c092fe8;
P_0c092fe8: /* original f47c, guest PC 0x0c092fe8 */
if(!s->budget--) { s->failed_pc=0x0c092fe8u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c092fea;
P_0c092fea: /* original f431, guest PC 0x0c092fea */
if(!s->budget--) { s->failed_pc=0x0c092feau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c092fec;
P_0c092fec: /* original f425, guest PC 0x0c092fec */
if(!s->budget--) { s->failed_pc=0x0c092fecu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c092fee;
P_0c092fee: /* original 8901, guest PC 0x0c092fee */
if(!s->budget--) { s->failed_pc=0x0c092feeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c092ff4; }
goto P_0c092ff0;
P_0c092ff0: /* original a006, guest PC 0x0c092ff0 */
if(!s->budget--) { s->failed_pc=0x0c092ff0u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c093000;
P_0c092ff2: /* original f67c, guest PC 0x0c092ff2 */
if(!s->budget--) { s->failed_pc=0x0c092ff2u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c092ff4;
P_0c092ff4: /* original f945, guest PC 0x0c092ff4 */
if(!s->budget--) { s->failed_pc=0x0c092ff4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[4]))!=0);
goto P_0c092ff6;
P_0c092ff6: /* original 8b01, guest PC 0x0c092ff6 */
if(!s->budget--) { s->failed_pc=0x0c092ff6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c092ffc; }
goto P_0c092ff8;
P_0c092ff8: /* original a002, guest PC 0x0c092ff8 */
if(!s->budget--) { s->failed_pc=0x0c092ff8u; return 0; }
fr[6]=0;
goto P_0c093000;
P_0c092ffa: /* original f68d, guest PC 0x0c092ffa */
if(!s->budget--) { s->failed_pc=0x0c092ffau; return 0; }
fr[6]=0;
goto P_0c092ffc;
P_0c092ffc: /* original f64c, guest PC 0x0c092ffc */
if(!s->budget--) { s->failed_pc=0x0c092ffcu; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c092ffe;
P_0c092ffe: /* original f66d, guest PC 0x0c092ffe */
if(!s->budget--) { s->failed_pc=0x0c092ffeu; return 0; }
fr[6]=vf3_fpu_sqrt(fr[6],r[18]);
goto P_0c093000;
P_0c093000: /* original f862, guest PC 0x0c093000 */
if(!s->budget--) { s->failed_pc=0x0c093000u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'*');
goto P_0c093002;
P_0c093002: /* original 53f2, guest PC 0x0c093002 */
if(!s->budget--) { s->failed_pc=0x0c093002u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c093004;
P_0c093004: /* original e004, guest PC 0x0c093004 */
if(!s->budget--) { s->failed_pc=0x0c093004u; return 0; }
r[0]=0x00000004u;
goto P_0c093006;
P_0c093006: /* original fa62, guest PC 0x0c093006 */
if(!s->budget--) { s->failed_pc=0x0c093006u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[6],r[18],'*');
goto P_0c093008;
P_0c093008: /* original 6232, guest PC 0x0c093008 */
if(!s->budget--) { s->failed_pc=0x0c093008u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c09300a;
P_0c09300a: /* original f426, guest PC 0x0c09300a */
if(!s->budget--) { s->failed_pc=0x0c09300au; return 0; }
vf3_matrix_load(s,ram,4,r[2]+r[0]);
goto P_0c09300c;
P_0c09300c: /* original 7204, guest PC 0x0c09300c */
if(!s->budget--) { s->failed_pc=0x0c09300cu; return 0; }
r[2]+=0x00000004u;
goto P_0c09300e;
P_0c09300e: /* original 2322, guest PC 0x0c09300e */
if(!s->budget--) { s->failed_pc=0x0c09300eu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c093010;
P_0c093010: /* original f04c, guest PC 0x0c093010 */
if(!s->budget--) { s->failed_pc=0x0c093010u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c093012;
P_0c093012: /* original f3e8, guest PC 0x0c093012 */
if(!s->budget--) { s->failed_pc=0x0c093012u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c093014;
P_0c093014: /* original f38e, guest PC 0x0c093014 */
if(!s->budget--) { s->failed_pc=0x0c093014u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[8],fr[3],r[18]);
goto P_0c093016;
P_0c093016: /* original fe3a, guest PC 0x0c093016 */
if(!s->budget--) { s->failed_pc=0x0c093016u; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c093018;
P_0c093018: /* original f2e6, guest PC 0x0c093018 */
if(!s->budget--) { s->failed_pc=0x0c093018u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c09301a;
P_0c09301a: /* original f25e, guest PC 0x0c09301a */
if(!s->budget--) { s->failed_pc=0x0c09301au; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[5],fr[2],r[18]);
goto P_0c09301c;
P_0c09301c: /* original fe27, guest PC 0x0c09301c */
if(!s->budget--) { s->failed_pc=0x0c09301cu; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c09301e;
P_0c09301e: /* original e008, guest PC 0x0c09301e */
if(!s->budget--) { s->failed_pc=0x0c09301eu; return 0; }
r[0]=0x00000008u;
goto P_0c093020;
P_0c093020: /* original f3e6, guest PC 0x0c093020 */
if(!s->budget--) { s->failed_pc=0x0c093020u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c093022;
P_0c093022: /* original f3ae, guest PC 0x0c093022 */
if(!s->budget--) { s->failed_pc=0x0c093022u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[10],fr[3],r[18]);
goto P_0c093024;
P_0c093024: /* original fe37, guest PC 0x0c093024 */
if(!s->budget--) { s->failed_pc=0x0c093024u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c093026;
P_0c093026: /* original 000b, guest PC 0x0c093026 */
if(!s->budget--) { s->failed_pc=0x0c093026u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c093028: /* original 6ef6, guest PC 0x0c093028 */
if(!s->budget--) { s->failed_pc=0x0c093028u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09302au,s,ram);
unsupported: s->failed_pc=target; return 0;
}
