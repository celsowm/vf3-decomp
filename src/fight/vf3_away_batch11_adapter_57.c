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
int vf3_away_batch11_adapter_57(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c6e7eu: goto P_0c0c6e7e;
case 0x0c0c6e80u: goto P_0c0c6e80;
case 0x0c0c6e82u: goto P_0c0c6e82;
case 0x0c0c6e84u: goto P_0c0c6e84;
case 0x0c0c6e86u: goto P_0c0c6e86;
case 0x0c0c6e88u: goto P_0c0c6e88;
case 0x0c0c6e8au: goto P_0c0c6e8a;
case 0x0c0c6e8cu: goto P_0c0c6e8c;
case 0x0c0c6e8eu: goto P_0c0c6e8e;
case 0x0c0c6e90u: goto P_0c0c6e90;
case 0x0c0c6e92u: goto P_0c0c6e92;
case 0x0c0c6e94u: goto P_0c0c6e94;
case 0x0c0c6e96u: goto P_0c0c6e96;
case 0x0c0c6e98u: goto P_0c0c6e98;
case 0x0c0c6e9au: goto P_0c0c6e9a;
case 0x0c0c6e9cu: goto P_0c0c6e9c;
case 0x0c0c6e9eu: goto P_0c0c6e9e;
case 0x0c0c6ea0u: goto P_0c0c6ea0;
case 0x0c0c6ea2u: goto P_0c0c6ea2;
case 0x0c0c6ea4u: goto P_0c0c6ea4;
case 0x0c0c6ea6u: goto P_0c0c6ea6;
case 0x0c0c6ea8u: goto P_0c0c6ea8;
case 0x0c0c6eaau: goto P_0c0c6eaa;
case 0x0c0c6eacu: goto P_0c0c6eac;
case 0x0c0c6eaeu: goto P_0c0c6eae;
case 0x0c0c6eb0u: goto P_0c0c6eb0;
case 0x0c0c6eb2u: goto P_0c0c6eb2;
case 0x0c0c6eb4u: goto P_0c0c6eb4;
case 0x0c0c6eb6u: goto P_0c0c6eb6;
case 0x0c0c6eb8u: goto P_0c0c6eb8;
case 0x0c0c6ebau: goto P_0c0c6eba;
case 0x0c0c6ebcu: goto P_0c0c6ebc;
case 0x0c0c6ebeu: goto P_0c0c6ebe;
case 0x0c0c6ec0u: goto P_0c0c6ec0;
case 0x0c0c6ec2u: goto P_0c0c6ec2;
case 0x0c0c6ec4u: goto P_0c0c6ec4;
case 0x0c0c6ec6u: goto P_0c0c6ec6;
case 0x0c0c6ec8u: goto P_0c0c6ec8;
case 0x0c0c6ecau: goto P_0c0c6eca;
case 0x0c0c6eccu: goto P_0c0c6ecc;
case 0x0c0c6eceu: goto P_0c0c6ece;
case 0x0c0c6ed0u: goto P_0c0c6ed0;
case 0x0c0c6ed2u: goto P_0c0c6ed2;
case 0x0c0c6ed4u: goto P_0c0c6ed4;
case 0x0c0c6ed6u: goto P_0c0c6ed6;
case 0x0c0c6ed8u: goto P_0c0c6ed8;
case 0x0c0c6edau: goto P_0c0c6eda;
case 0x0c0c6edcu: goto P_0c0c6edc;
case 0x0c0c6edeu: goto P_0c0c6ede;
case 0x0c0c6ee0u: goto P_0c0c6ee0;
case 0x0c0c6ee2u: goto P_0c0c6ee2;
case 0x0c0c6ee4u: goto P_0c0c6ee4;
case 0x0c0c6ee6u: goto P_0c0c6ee6;
case 0x0c0c6ee8u: goto P_0c0c6ee8;
case 0x0c0c6eeau: goto P_0c0c6eea;
case 0x0c0c6eecu: goto P_0c0c6eec;
case 0x0c0c6f1cu: goto P_0c0c6f1c;
case 0x0c0c6f1eu: goto P_0c0c6f1e;
case 0x0c0c6f20u: goto P_0c0c6f20;
case 0x0c0c6f22u: goto P_0c0c6f22;
case 0x0c0c6f24u: goto P_0c0c6f24;
case 0x0c0c6f26u: goto P_0c0c6f26;
case 0x0c0c6f28u: goto P_0c0c6f28;
case 0x0c0c6f2au: goto P_0c0c6f2a;
case 0x0c0c6f2cu: goto P_0c0c6f2c;
case 0x0c0c6f2eu: goto P_0c0c6f2e;
case 0x0c0c6f30u: goto P_0c0c6f30;
case 0x0c0c6f32u: goto P_0c0c6f32;
case 0x0c0c6f34u: goto P_0c0c6f34;
case 0x0c0c6f36u: goto P_0c0c6f36;
case 0x0c0c6f38u: goto P_0c0c6f38;
case 0x0c0c6f3au: goto P_0c0c6f3a;
case 0x0c0c6f3cu: goto P_0c0c6f3c;
case 0x0c0c6f3eu: goto P_0c0c6f3e;
case 0x0c0c6f40u: goto P_0c0c6f40;
case 0x0c0c6f42u: goto P_0c0c6f42;
case 0x0c0c6f44u: goto P_0c0c6f44;
case 0x0c0c6f46u: goto P_0c0c6f46;
case 0x0c0c6f48u: goto P_0c0c6f48;
case 0x0c0c6f4au: goto P_0c0c6f4a;
case 0x0c0c6f4cu: goto P_0c0c6f4c;
case 0x0c0c6f4eu: goto P_0c0c6f4e;
case 0x0c0c6f50u: goto P_0c0c6f50;
case 0x0c0c6f52u: goto P_0c0c6f52;
case 0x0c0c6f54u: goto P_0c0c6f54;
case 0x0c0c6f56u: goto P_0c0c6f56;
case 0x0c0c6f58u: goto P_0c0c6f58;
case 0x0c0c6f5au: goto P_0c0c6f5a;
case 0x0c0c6f5cu: goto P_0c0c6f5c;
case 0x0c0c6f5eu: goto P_0c0c6f5e;
case 0x0c0c6f60u: goto P_0c0c6f60;
case 0x0c0c6f62u: goto P_0c0c6f62;
case 0x0c0c6f64u: goto P_0c0c6f64;
case 0x0c0c6f66u: goto P_0c0c6f66;
case 0x0c0c6f68u: goto P_0c0c6f68;
case 0x0c0c6f6au: goto P_0c0c6f6a;
case 0x0c0c6f6cu: goto P_0c0c6f6c;
case 0x0c0c6f6eu: goto P_0c0c6f6e;
case 0x0c0c6f70u: goto P_0c0c6f70;
case 0x0c0c6f72u: goto P_0c0c6f72;
case 0x0c0c6f74u: goto P_0c0c6f74;
case 0x0c0c6f76u: goto P_0c0c6f76;
case 0x0c0c6f78u: goto P_0c0c6f78;
case 0x0c0c6f7au: goto P_0c0c6f7a;
case 0x0c0c6f7cu: goto P_0c0c6f7c;
case 0x0c0c6f7eu: goto P_0c0c6f7e;
case 0x0c0c6f80u: goto P_0c0c6f80;
case 0x0c0c6f82u: goto P_0c0c6f82;
case 0x0c0c6f84u: goto P_0c0c6f84;
case 0x0c0c6f86u: goto P_0c0c6f86;
case 0x0c0c6f88u: goto P_0c0c6f88;
case 0x0c0c6f8au: goto P_0c0c6f8a;
case 0x0c0c6f8cu: goto P_0c0c6f8c;
case 0x0c0c6f8eu: goto P_0c0c6f8e;
case 0x0c0c6f90u: goto P_0c0c6f90;
case 0x0c0c6f92u: goto P_0c0c6f92;
case 0x0c0c6f94u: goto P_0c0c6f94;
case 0x0c0c6f96u: goto P_0c0c6f96;
case 0x0c0c6f98u: goto P_0c0c6f98;
case 0x0c0c6f9au: goto P_0c0c6f9a;
case 0x0c0c6f9cu: goto P_0c0c6f9c;
case 0x0c0c6f9eu: goto P_0c0c6f9e;
case 0x0c0c6fa0u: goto P_0c0c6fa0;
case 0x0c0c6fa2u: goto P_0c0c6fa2;
case 0x0c0c6fa4u: goto P_0c0c6fa4;
case 0x0c0c6fa6u: goto P_0c0c6fa6;
case 0x0c0c6fa8u: goto P_0c0c6fa8;
case 0x0c0c6faau: goto P_0c0c6faa;
case 0x0c0c6facu: goto P_0c0c6fac;
case 0x0c0c6faeu: goto P_0c0c6fae;
case 0x0c0c6fb0u: goto P_0c0c6fb0;
case 0x0c0c6fb2u: goto P_0c0c6fb2;
case 0x0c0c6fb4u: goto P_0c0c6fb4;
case 0x0c0c6fb6u: goto P_0c0c6fb6;
case 0x0c0c6fb8u: goto P_0c0c6fb8;
case 0x0c0c6fbau: goto P_0c0c6fba;
case 0x0c0c6fbcu: goto P_0c0c6fbc;
case 0x0c0c6fbeu: goto P_0c0c6fbe;
case 0x0c0c6fc0u: goto P_0c0c6fc0;
case 0x0c0c6fc2u: goto P_0c0c6fc2;
case 0x0c0c6fc4u: goto P_0c0c6fc4;
case 0x0c0c6fc6u: goto P_0c0c6fc6;
case 0x0c0c6fc8u: goto P_0c0c6fc8;
case 0x0c0c6fcau: goto P_0c0c6fca;
case 0x0c0c6fccu: goto P_0c0c6fcc;
case 0x0c0c6fceu: goto P_0c0c6fce;
case 0x0c0c6fd0u: goto P_0c0c6fd0;
case 0x0c0c6fd2u: goto P_0c0c6fd2;
case 0x0c0c6fd4u: goto P_0c0c6fd4;
case 0x0c0c6fd6u: goto P_0c0c6fd6;
case 0x0c0c6fd8u: goto P_0c0c6fd8;
case 0x0c0c6fdau: goto P_0c0c6fda;
case 0x0c0c6fdcu: goto P_0c0c6fdc;
case 0x0c0c6fdeu: goto P_0c0c6fde;
case 0x0c0c6fe0u: goto P_0c0c6fe0;
case 0x0c0c6fe2u: goto P_0c0c6fe2;
case 0x0c0c6fe4u: goto P_0c0c6fe4;
case 0x0c0c6fe6u: goto P_0c0c6fe6;
case 0x0c0c6fe8u: goto P_0c0c6fe8;
case 0x0c0c6feau: goto P_0c0c6fea;
case 0x0c0c6fecu: goto P_0c0c6fec;
case 0x0c0c6feeu: goto P_0c0c6fee;
case 0x0c0c6ff0u: goto P_0c0c6ff0;
case 0x0c0c6ff2u: goto P_0c0c6ff2;
case 0x0c0c6ff4u: goto P_0c0c6ff4;
case 0x0c0c6ff6u: goto P_0c0c6ff6;
case 0x0c0c6ff8u: goto P_0c0c6ff8;
case 0x0c0c6ffau: goto P_0c0c6ffa;
case 0x0c0c6ffcu: goto P_0c0c6ffc;
case 0x0c0c6ffeu: goto P_0c0c6ffe;
case 0x0c0c7000u: goto P_0c0c7000;
case 0x0c0c7002u: goto P_0c0c7002;
case 0x0c0c7004u: goto P_0c0c7004;
case 0x0c0c7006u: goto P_0c0c7006;
case 0x0c0c7008u: goto P_0c0c7008;
case 0x0c0c700au: goto P_0c0c700a;
case 0x0c0c700cu: goto P_0c0c700c;
case 0x0c0c700eu: goto P_0c0c700e;
case 0x0c0c7010u: goto P_0c0c7010;
case 0x0c0c7012u: goto P_0c0c7012;
case 0x0c0c7014u: goto P_0c0c7014;
case 0x0c0c7016u: goto P_0c0c7016;
case 0x0c0c7018u: goto P_0c0c7018;
case 0x0c0c701au: goto P_0c0c701a;
case 0x0c0c701cu: goto P_0c0c701c;
case 0x0c0c701eu: goto P_0c0c701e;
case 0x0c0c7020u: goto P_0c0c7020;
case 0x0c0c7022u: goto P_0c0c7022;
case 0x0c0c7050u: goto P_0c0c7050;
case 0x0c0c7052u: goto P_0c0c7052;
case 0x0c0c7054u: goto P_0c0c7054;
case 0x0c0c7056u: goto P_0c0c7056;
case 0x0c0c7058u: goto P_0c0c7058;
case 0x0c0c705au: goto P_0c0c705a;
case 0x0c0c705cu: goto P_0c0c705c;
case 0x0c0c705eu: goto P_0c0c705e;
case 0x0c0c7060u: goto P_0c0c7060;
case 0x0c0c7062u: goto P_0c0c7062;
case 0x0c0c7064u: goto P_0c0c7064;
case 0x0c0c7066u: goto P_0c0c7066;
case 0x0c0c7068u: goto P_0c0c7068;
case 0x0c0c706au: goto P_0c0c706a;
case 0x0c0c706cu: goto P_0c0c706c;
case 0x0c0c706eu: goto P_0c0c706e;
case 0x0c0c7070u: goto P_0c0c7070;
case 0x0c0c7072u: goto P_0c0c7072;
case 0x0c0c7074u: goto P_0c0c7074;
case 0x0c0c7076u: goto P_0c0c7076;
case 0x0c0c7078u: goto P_0c0c7078;
case 0x0c0c707au: goto P_0c0c707a;
case 0x0c0c707cu: goto P_0c0c707c;
case 0x0c0c707eu: goto P_0c0c707e;
case 0x0c0c7080u: goto P_0c0c7080;
case 0x0c0c7082u: goto P_0c0c7082;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c6e7e: /* original 4f22, guest PC 0x0c0c6e7e */
if(!s->budget--) { s->failed_pc=0x0c0c6e7eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c6e80;
P_0c0c6e80: /* original 7ff8, guest PC 0x0c0c6e80 */
if(!s->budget--) { s->failed_pc=0x0c0c6e80u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c6e82;
P_0c0c6e82: /* original 1f41, guest PC 0x0c0c6e82 */
if(!s->budget--) { s->failed_pc=0x0c0c6e82u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0c6e84;
P_0c0c6e84: /* original 2f52, guest PC 0x0c0c6e84 */
if(!s->budget--) { s->failed_pc=0x0c0c6e84u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c6e86;
P_0c0c6e86: /* original d121, guest PC 0x0c0c6e86 */
if(!s->budget--) { s->failed_pc=0x0c0c6e86u; return 0; }
r[1]=read(ram,0x0c0c6f0cu,4);
goto P_0c0c6e88;
P_0c0c6e88: /* original d31f, guest PC 0x0c0c6e88 */
if(!s->budget--) { s->failed_pc=0x0c0c6e88u; return 0; }
r[3]=read(ram,0x0c0c6f08u,4);
goto P_0c0c6e8a;
P_0c0c6e8a: /* original 6212, guest PC 0x0c0c6e8a */
if(!s->budget--) { s->failed_pc=0x0c0c6e8au; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0c6e8c;
P_0c0c6e8c: /* original 2238, guest PC 0x0c0c6e8c */
if(!s->budget--) { s->failed_pc=0x0c0c6e8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c6e8e;
P_0c0c6e8e: /* original 8b09, guest PC 0x0c0c6e8e */
if(!s->budget--) { s->failed_pc=0x0c0c6e8eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6ea4; }
goto P_0c0c6e90;
P_0c0c6e90: /* original b00c, guest PC 0x0c0c6e90 */
if(!s->budget--) { s->failed_pc=0x0c0c6e90u; return 0; }
target=code_base|0x0c0c6eacu; r[16]=code_base|0x0c0c6e94u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6e94u) { target=s->pc; goto dispatch; }
goto P_0c0c6e94;
P_0c0c6e92: /* original 54f1, guest PC 0x0c0c6e92 */
if(!s->budget--) { s->failed_pc=0x0c0c6e92u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c6e94;
P_0c0c6e94: /* original d31e, guest PC 0x0c0c6e94 */
if(!s->budget--) { s->failed_pc=0x0c0c6e94u; return 0; }
r[3]=read(ram,0x0c0c6f10u,4);
goto P_0c0c6e96;
P_0c0c6e96: /* original 430b, guest PC 0x0c0c6e96 */
if(!s->budget--) { s->failed_pc=0x0c0c6e96u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6e9au;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6e9au) { target=s->pc; goto dispatch; }
goto P_0c0c6e9a;
P_0c0c6e98: /* original 54f1, guest PC 0x0c0c6e98 */
if(!s->budget--) { s->failed_pc=0x0c0c6e98u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c6e9a;
P_0c0c6e9a: /* original b007, guest PC 0x0c0c6e9a */
if(!s->budget--) { s->failed_pc=0x0c0c6e9au; return 0; }
target=code_base|0x0c0c6eacu; r[16]=code_base|0x0c0c6e9eu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6e9eu) { target=s->pc; goto dispatch; }
goto P_0c0c6e9e;
P_0c0c6e9c: /* original 64f2, guest PC 0x0c0c6e9c */
if(!s->budget--) { s->failed_pc=0x0c0c6e9cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c6e9e;
P_0c0c6e9e: /* original d31c, guest PC 0x0c0c6e9e */
if(!s->budget--) { s->failed_pc=0x0c0c6e9eu; return 0; }
r[3]=read(ram,0x0c0c6f10u,4);
goto P_0c0c6ea0;
P_0c0c6ea0: /* original 430b, guest PC 0x0c0c6ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c6ea0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6ea4u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6ea4u) { target=s->pc; goto dispatch; }
goto P_0c0c6ea4;
P_0c0c6ea2: /* original 64f2, guest PC 0x0c0c6ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c6ea2u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c6ea4;
P_0c0c6ea4: /* original 7f08, guest PC 0x0c0c6ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c6ea4u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c6ea6;
P_0c0c6ea6: /* original 4f26, guest PC 0x0c0c6ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c6ea6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c6ea8;
P_0c0c6ea8: /* original 000b, guest PC 0x0c0c6ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c6ea8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c6eaa: /* original 0009, guest PC 0x0c0c6eaa */
if(!s->budget--) { s->failed_pc=0x0c0c6eaau; return 0; }
goto P_0c0c6eac;
P_0c0c6eac: /* original 2fe6, guest PC 0x0c0c6eac */
if(!s->budget--) { s->failed_pc=0x0c0c6eacu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6eae;
P_0c0c6eae: /* original 6e43, guest PC 0x0c0c6eae */
if(!s->budget--) { s->failed_pc=0x0c0c6eaeu; return 0; }
r[14]=r[4];
goto P_0c0c6eb0;
P_0c0c6eb0: /* original 2fd6, guest PC 0x0c0c6eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c6eb0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6eb2;
P_0c0c6eb2: /* original e320, guest PC 0x0c0c6eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c6eb2u; return 0; }
r[3]=0x00000020u;
goto P_0c0c6eb4;
P_0c0c6eb4: /* original 2fc6, guest PC 0x0c0c6eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c6eb4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6eb6;
P_0c0c6eb6: /* original e700, guest PC 0x0c0c6eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c6eb6u; return 0; }
r[7]=0x00000000u;
goto P_0c0c6eb8;
P_0c0c6eb8: /* original 2fb6, guest PC 0x0c0c6eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c6eb8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6eba;
P_0c0c6eba: /* original 2fa6, guest PC 0x0c0c6eba */
if(!s->budget--) { s->failed_pc=0x0c0c6ebau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6ebc;
P_0c0c6ebc: /* original 2f96, guest PC 0x0c0c6ebc */
if(!s->budget--) { s->failed_pc=0x0c0c6ebcu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6ebe;
P_0c0c6ebe: /* original 2f86, guest PC 0x0c0c6ebe */
if(!s->budget--) { s->failed_pc=0x0c0c6ebeu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6ec0;
P_0c0c6ec0: /* original fffb, guest PC 0x0c0c6ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c6ec0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c6ec2;
P_0c0c6ec2: /* original 9016, guest PC 0x0c0c6ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c6ec2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6ef2u,2);
goto P_0c0c6ec4;
P_0c0c6ec4: /* original 4f22, guest PC 0x0c0c6ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c6ec4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c6ec6;
P_0c0c6ec6: /* original 0dec, guest PC 0x0c0c6ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c6ec6u; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c6ec8;
P_0c0c6ec8: /* original e014, guest PC 0x0c0c6ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c6ec8u; return 0; }
r[0]=0x00000014u;
goto P_0c0c6eca;
P_0c0c6eca: /* original ffe6, guest PC 0x0c0c6eca */
if(!s->budget--) { s->failed_pc=0x0c0c6ecau; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0c6ecc;
P_0c0c6ecc: /* original 9012, guest PC 0x0c0c6ecc */
if(!s->budget--) { s->failed_pc=0x0c0c6eccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6ef4u,2);
goto P_0c0c6ece;
P_0c0c6ece: /* original 6ddc, guest PC 0x0c0c6ece */
if(!s->budget--) { s->failed_pc=0x0c0c6eceu; return 0; }
r[13]=r[13]&255u;
goto P_0c0c6ed0;
P_0c0c6ed0: /* original d510, guest PC 0x0c0c6ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c6ed0u; return 0; }
r[5]=read(ram,0x0c0c6f14u,4);
goto P_0c0c6ed2;
P_0c0c6ed2: /* original 23d8, guest PC 0x0c0c6ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c6ed2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c6ed4;
P_0c0c6ed4: /* original 66e2, guest PC 0x0c0c6ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c6ed4u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c0c6ed6;
P_0c0c6ed6: /* original 0cee, guest PC 0x0c0c6ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c6ed6u; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c0c6ed8;
P_0c0c6ed8: /* original 8d02, guest PC 0x0c0c6ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c6ed8u; return 0; }
cond=r[17]&1u;
r[4]=0x00000001u;
if(cond) { goto P_0c0c6ee0; }
goto P_0c0c6edc;
P_0c0c6eda: /* original e401, guest PC 0x0c0c6eda */
if(!s->budget--) { s->failed_pc=0x0c0c6edau; return 0; }
r[4]=0x00000001u;
goto P_0c0c6edc;
P_0c0c6edc: /* original a001, guest PC 0x0c0c6edc */
if(!s->budget--) { s->failed_pc=0x0c0c6edcu; return 0; }
write(ram,r[5]+28,r[4],4);
goto P_0c0c6ee2;
P_0c0c6ede: /* original 1547, guest PC 0x0c0c6ede */
if(!s->budget--) { s->failed_pc=0x0c0c6edeu; return 0; }
write(ram,r[5]+28,r[4],4);
goto P_0c0c6ee0;
P_0c0c6ee0: /* original 1577, guest PC 0x0c0c6ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c6ee0u; return 0; }
write(ram,r[5]+28,r[7],4);
goto P_0c0c6ee2;
P_0c0c6ee2: /* original d20d, guest PC 0x0c0c6ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c6ee2u; return 0; }
r[2]=read(ram,0x0c0c6f18u,4);
goto P_0c0c6ee4;
P_0c0c6ee4: /* original 2628, guest PC 0x0c0c6ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c6ee4u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c0c6ee6;
P_0c0c6ee6: /* original 8d19, guest PC 0x0c0c6ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c6ee6u; return 0; }
cond=r[17]&1u;
r[9]=r[12];
if(cond) { goto P_0c0c6f1c; }
goto P_0c0c6eea;
P_0c0c6ee8: /* original 69c3, guest PC 0x0c0c6ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c6ee8u; return 0; }
r[9]=r[12];
goto P_0c0c6eea;
P_0c0c6eea: /* original a018, guest PC 0x0c0c6eea */
if(!s->budget--) { s->failed_pc=0x0c0c6eeau; return 0; }
write(ram,r[5]+24,r[4],4);
goto P_0c0c6f1e;
P_0c0c6eec: /* original 1546, guest PC 0x0c0c6eec */
if(!s->budget--) { s->failed_pc=0x0c0c6eecu; return 0; }
write(ram,r[5]+24,r[4],4);
if(!vf3_matrix_family(0x0c0c6eeeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c6eeeu; return 0; } return 1;
P_0c0c6f1c: /* original 1576, guest PC 0x0c0c6f1c */
if(!s->budget--) { s->failed_pc=0x0c0c6f1cu; return 0; }
write(ram,r[5]+24,r[7],4);
goto P_0c0c6f1e;
P_0c0c6f1e: /* original 9b82, guest PC 0x0c0c6f1e */
if(!s->budget--) { s->failed_pc=0x0c0c6f1eu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7026u,2);
goto P_0c0c6f20;
P_0c0c6f20: /* original 24d8, guest PC 0x0c0c6f20 */
if(!s->budget--) { s->failed_pc=0x0c0c6f20u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[13])==0)!=0);
goto P_0c0c6f22;
P_0c0c6f22: /* original 987f, guest PC 0x0c0c6f22 */
if(!s->budget--) { s->failed_pc=0x0c0c6f22u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7024u,2);
goto P_0c0c6f24;
P_0c0c6f24: /* original 7958, guest PC 0x0c0c6f24 */
if(!s->budget--) { s->failed_pc=0x0c0c6f24u; return 0; }
r[9]+=0x00000058u;
goto P_0c0c6f26;
P_0c0c6f26: /* original 9a7f, guest PC 0x0c0c6f26 */
if(!s->budget--) { s->failed_pc=0x0c0c6f26u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7028u,2);
goto P_0c0c6f28;
P_0c0c6f28: /* original 3bcc, guest PC 0x0c0c6f28 */
if(!s->budget--) { s->failed_pc=0x0c0c6f28u; return 0; }
r[11]+=r[12];
goto P_0c0c6f2a;
P_0c0c6f2a: /* original 38cc, guest PC 0x0c0c6f2a */
if(!s->budget--) { s->failed_pc=0x0c0c6f2au; return 0; }
r[8]+=r[12];
goto P_0c0c6f2c;
P_0c0c6f2c: /* original 8f32, guest PC 0x0c0c6f2c */
if(!s->budget--) { s->failed_pc=0x0c0c6f2cu; return 0; }
cond=r[17]&1u;
r[10]+=r[12];
if(!cond) { goto P_0c0c6f94; }
goto P_0c0c6f30;
P_0c0c6f2e: /* original 3acc, guest PC 0x0c0c6f2e */
if(!s->budget--) { s->failed_pc=0x0c0c6f2eu; return 0; }
r[10]+=r[12];
goto P_0c0c6f30;
P_0c0c6f30: /* original e308, guest PC 0x0c0c6f30 */
if(!s->budget--) { s->failed_pc=0x0c0c6f30u; return 0; }
r[3]=0x00000008u;
goto P_0c0c6f32;
P_0c0c6f32: /* original 23d8, guest PC 0x0c0c6f32 */
if(!s->budget--) { s->failed_pc=0x0c0c6f32u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c6f34;
P_0c0c6f34: /* original 8908, guest PC 0x0c0c6f34 */
if(!s->budget--) { s->failed_pc=0x0c0c6f34u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6f48; }
goto P_0c0c6f36;
P_0c0c6f36: /* original 9078, guest PC 0x0c0c6f36 */
if(!s->budget--) { s->failed_pc=0x0c0c6f36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c702au,2);
goto P_0c0c6f38;
P_0c0c6f38: /* original 6593, guest PC 0x0c0c6f38 */
if(!s->budget--) { s->failed_pc=0x0c0c6f38u; return 0; }
r[5]=r[9];
goto P_0c0c6f3a;
P_0c0c6f3a: /* original 9478, guest PC 0x0c0c6f3a */
if(!s->budget--) { s->failed_pc=0x0c0c6f3au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c702eu,2);
goto P_0c0c6f3c;
P_0c0c6f3c: /* original 9676, guest PC 0x0c0c6f3c */
if(!s->budget--) { s->failed_pc=0x0c0c6f3cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c702cu,2);
goto P_0c0c6f3e;
P_0c0c6f3e: /* original f4e6, guest PC 0x0c0c6f3e */
if(!s->budget--) { s->failed_pc=0x0c0c6f3eu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c6f40;
P_0c0c6f40: /* original 34ec, guest PC 0x0c0c6f40 */
if(!s->budget--) { s->failed_pc=0x0c0c6f40u; return 0; }
r[4]+=r[14];
goto P_0c0c6f42;
P_0c0c6f42: /* original 36ec, guest PC 0x0c0c6f42 */
if(!s->budget--) { s->failed_pc=0x0c0c6f42u; return 0; }
r[6]+=r[14];
goto P_0c0c6f44;
P_0c0c6f44: /* original b084, guest PC 0x0c0c6f44 */
if(!s->budget--) { s->failed_pc=0x0c0c6f44u; return 0; }
target=code_base|0x0c0c7050u; r[16]=code_base|0x0c0c6f48u;
vf3_matrix_move(s,5,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6f48u) { target=s->pc; goto dispatch; }
goto P_0c0c6f48;
P_0c0c6f46: /* original f5fc, guest PC 0x0c0c6f46 */
if(!s->budget--) { s->failed_pc=0x0c0c6f46u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c6f48;
P_0c0c6f48: /* original e210, guest PC 0x0c0c6f48 */
if(!s->budget--) { s->failed_pc=0x0c0c6f48u; return 0; }
r[2]=0x00000010u;
goto P_0c0c6f4a;
P_0c0c6f4a: /* original 22d8, guest PC 0x0c0c6f4a */
if(!s->budget--) { s->failed_pc=0x0c0c6f4au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0c6f4c;
P_0c0c6f4c: /* original 8908, guest PC 0x0c0c6f4c */
if(!s->budget--) { s->failed_pc=0x0c0c6f4cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6f60; }
goto P_0c0c6f4e;
P_0c0c6f4e: /* original 906f, guest PC 0x0c0c6f4e */
if(!s->budget--) { s->failed_pc=0x0c0c6f4eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7030u,2);
goto P_0c0c6f50;
P_0c0c6f50: /* original 6583, guest PC 0x0c0c6f50 */
if(!s->budget--) { s->failed_pc=0x0c0c6f50u; return 0; }
r[5]=r[8];
goto P_0c0c6f52;
P_0c0c6f52: /* original 946f, guest PC 0x0c0c6f52 */
if(!s->budget--) { s->failed_pc=0x0c0c6f52u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7034u,2);
goto P_0c0c6f54;
P_0c0c6f54: /* original 966d, guest PC 0x0c0c6f54 */
if(!s->budget--) { s->failed_pc=0x0c0c6f54u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7032u,2);
goto P_0c0c6f56;
P_0c0c6f56: /* original f4e6, guest PC 0x0c0c6f56 */
if(!s->budget--) { s->failed_pc=0x0c0c6f56u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c6f58;
P_0c0c6f58: /* original 34ec, guest PC 0x0c0c6f58 */
if(!s->budget--) { s->failed_pc=0x0c0c6f58u; return 0; }
r[4]+=r[14];
goto P_0c0c6f5a;
P_0c0c6f5a: /* original 36ec, guest PC 0x0c0c6f5a */
if(!s->budget--) { s->failed_pc=0x0c0c6f5au; return 0; }
r[6]+=r[14];
goto P_0c0c6f5c;
P_0c0c6f5c: /* original b078, guest PC 0x0c0c6f5c */
if(!s->budget--) { s->failed_pc=0x0c0c6f5cu; return 0; }
target=code_base|0x0c0c7050u; r[16]=code_base|0x0c0c6f60u;
vf3_matrix_move(s,5,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6f60u) { target=s->pc; goto dispatch; }
goto P_0c0c6f60;
P_0c0c6f5e: /* original f5fc, guest PC 0x0c0c6f5e */
if(!s->budget--) { s->failed_pc=0x0c0c6f5eu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c6f60;
P_0c0c6f60: /* original e202, guest PC 0x0c0c6f60 */
if(!s->budget--) { s->failed_pc=0x0c0c6f60u; return 0; }
r[2]=0x00000002u;
goto P_0c0c6f62;
P_0c0c6f62: /* original 22d8, guest PC 0x0c0c6f62 */
if(!s->budget--) { s->failed_pc=0x0c0c6f62u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0c6f64;
P_0c0c6f64: /* original 8908, guest PC 0x0c0c6f64 */
if(!s->budget--) { s->failed_pc=0x0c0c6f64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6f78; }
goto P_0c0c6f66;
P_0c0c6f66: /* original 9066, guest PC 0x0c0c6f66 */
if(!s->budget--) { s->failed_pc=0x0c0c6f66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7036u,2);
goto P_0c0c6f68;
P_0c0c6f68: /* original 65b3, guest PC 0x0c0c6f68 */
if(!s->budget--) { s->failed_pc=0x0c0c6f68u; return 0; }
r[5]=r[11];
goto P_0c0c6f6a;
P_0c0c6f6a: /* original 9466, guest PC 0x0c0c6f6a */
if(!s->budget--) { s->failed_pc=0x0c0c6f6au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c703au,2);
goto P_0c0c6f6c;
P_0c0c6f6c: /* original 9664, guest PC 0x0c0c6f6c */
if(!s->budget--) { s->failed_pc=0x0c0c6f6cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7038u,2);
goto P_0c0c6f6e;
P_0c0c6f6e: /* original f4e6, guest PC 0x0c0c6f6e */
if(!s->budget--) { s->failed_pc=0x0c0c6f6eu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c6f70;
P_0c0c6f70: /* original 34ec, guest PC 0x0c0c6f70 */
if(!s->budget--) { s->failed_pc=0x0c0c6f70u; return 0; }
r[4]+=r[14];
goto P_0c0c6f72;
P_0c0c6f72: /* original 36ec, guest PC 0x0c0c6f72 */
if(!s->budget--) { s->failed_pc=0x0c0c6f72u; return 0; }
r[6]+=r[14];
goto P_0c0c6f74;
P_0c0c6f74: /* original b06c, guest PC 0x0c0c6f74 */
if(!s->budget--) { s->failed_pc=0x0c0c6f74u; return 0; }
target=code_base|0x0c0c7050u; r[16]=code_base|0x0c0c6f78u;
vf3_matrix_move(s,5,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6f78u) { target=s->pc; goto dispatch; }
goto P_0c0c6f78;
P_0c0c6f76: /* original f5fc, guest PC 0x0c0c6f76 */
if(!s->budget--) { s->failed_pc=0x0c0c6f76u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c6f78;
P_0c0c6f78: /* original e204, guest PC 0x0c0c6f78 */
if(!s->budget--) { s->failed_pc=0x0c0c6f78u; return 0; }
r[2]=0x00000004u;
goto P_0c0c6f7a;
P_0c0c6f7a: /* original 2d28, guest PC 0x0c0c6f7a */
if(!s->budget--) { s->failed_pc=0x0c0c6f7au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[2])==0)!=0);
goto P_0c0c6f7c;
P_0c0c6f7c: /* original 8948, guest PC 0x0c0c6f7c */
if(!s->budget--) { s->failed_pc=0x0c0c6f7cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7010; }
goto P_0c0c6f7e;
P_0c0c6f7e: /* original 905d, guest PC 0x0c0c6f7e */
if(!s->budget--) { s->failed_pc=0x0c0c6f7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c703cu,2);
goto P_0c0c6f80;
P_0c0c6f80: /* original 65a3, guest PC 0x0c0c6f80 */
if(!s->budget--) { s->failed_pc=0x0c0c6f80u; return 0; }
r[5]=r[10];
goto P_0c0c6f82;
P_0c0c6f82: /* original 945d, guest PC 0x0c0c6f82 */
if(!s->budget--) { s->failed_pc=0x0c0c6f82u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7040u,2);
goto P_0c0c6f84;
P_0c0c6f84: /* original 965b, guest PC 0x0c0c6f84 */
if(!s->budget--) { s->failed_pc=0x0c0c6f84u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c703eu,2);
goto P_0c0c6f86;
P_0c0c6f86: /* original f4e6, guest PC 0x0c0c6f86 */
if(!s->budget--) { s->failed_pc=0x0c0c6f86u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c6f88;
P_0c0c6f88: /* original 34ec, guest PC 0x0c0c6f88 */
if(!s->budget--) { s->failed_pc=0x0c0c6f88u; return 0; }
r[4]+=r[14];
goto P_0c0c6f8a;
P_0c0c6f8a: /* original 36ec, guest PC 0x0c0c6f8a */
if(!s->budget--) { s->failed_pc=0x0c0c6f8au; return 0; }
r[6]+=r[14];
goto P_0c0c6f8c;
P_0c0c6f8c: /* original b060, guest PC 0x0c0c6f8c */
if(!s->budget--) { s->failed_pc=0x0c0c6f8cu; return 0; }
target=code_base|0x0c0c7050u; r[16]=code_base|0x0c0c6f90u;
vf3_matrix_move(s,5,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6f90u) { target=s->pc; goto dispatch; }
goto P_0c0c6f90;
P_0c0c6f8e: /* original f5fc, guest PC 0x0c0c6f8e */
if(!s->budget--) { s->failed_pc=0x0c0c6f8eu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c6f90;
P_0c0c6f90: /* original a03e, guest PC 0x0c0c6f90 */
if(!s->budget--) { s->failed_pc=0x0c0c6f90u; return 0; }
goto P_0c0c7010;
P_0c0c6f92: /* original 0009, guest PC 0x0c0c6f92 */
if(!s->budget--) { s->failed_pc=0x0c0c6f92u; return 0; }
goto P_0c0c6f94;
P_0c0c6f94: /* original 9355, guest PC 0x0c0c6f94 */
if(!s->budget--) { s->failed_pc=0x0c0c6f94u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7042u,2);
goto P_0c0c6f96;
P_0c0c6f96: /* original 23d8, guest PC 0x0c0c6f96 */
if(!s->budget--) { s->failed_pc=0x0c0c6f96u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c6f98;
P_0c0c6f98: /* original 8b13, guest PC 0x0c0c6f98 */
if(!s->budget--) { s->failed_pc=0x0c0c6f98u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6fc2; }
goto P_0c0c6f9a;
P_0c0c6f9a: /* original 9053, guest PC 0x0c0c6f9a */
if(!s->budget--) { s->failed_pc=0x0c0c6f9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7044u,2);
goto P_0c0c6f9c;
P_0c0c6f9c: /* original 65c3, guest PC 0x0c0c6f9c */
if(!s->budget--) { s->failed_pc=0x0c0c6f9cu; return 0; }
r[5]=r[12];
goto P_0c0c6f9e;
P_0c0c6f9e: /* original 9453, guest PC 0x0c0c6f9e */
if(!s->budget--) { s->failed_pc=0x0c0c6f9eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7048u,2);
goto P_0c0c6fa0;
P_0c0c6fa0: /* original 751c, guest PC 0x0c0c6fa0 */
if(!s->budget--) { s->failed_pc=0x0c0c6fa0u; return 0; }
r[5]+=0x0000001cu;
goto P_0c0c6fa2;
P_0c0c6fa2: /* original 9650, guest PC 0x0c0c6fa2 */
if(!s->budget--) { s->failed_pc=0x0c0c6fa2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7046u,2);
goto P_0c0c6fa4;
P_0c0c6fa4: /* original f4e6, guest PC 0x0c0c6fa4 */
if(!s->budget--) { s->failed_pc=0x0c0c6fa4u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c6fa6;
P_0c0c6fa6: /* original 34ec, guest PC 0x0c0c6fa6 */
if(!s->budget--) { s->failed_pc=0x0c0c6fa6u; return 0; }
r[4]+=r[14];
goto P_0c0c6fa8;
P_0c0c6fa8: /* original 36ec, guest PC 0x0c0c6fa8 */
if(!s->budget--) { s->failed_pc=0x0c0c6fa8u; return 0; }
r[6]+=r[14];
goto P_0c0c6faa;
P_0c0c6faa: /* original b051, guest PC 0x0c0c6faa */
if(!s->budget--) { s->failed_pc=0x0c0c6faau; return 0; }
target=code_base|0x0c0c7050u; r[16]=code_base|0x0c0c6faeu;
vf3_matrix_move(s,5,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6faeu) { target=s->pc; goto dispatch; }
goto P_0c0c6fae;
P_0c0c6fac: /* original f5fc, guest PC 0x0c0c6fac */
if(!s->budget--) { s->failed_pc=0x0c0c6facu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c6fae;
P_0c0c6fae: /* original 904c, guest PC 0x0c0c6fae */
if(!s->budget--) { s->failed_pc=0x0c0c6faeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c704au,2);
goto P_0c0c6fb0;
P_0c0c6fb0: /* original 65c3, guest PC 0x0c0c6fb0 */
if(!s->budget--) { s->failed_pc=0x0c0c6fb0u; return 0; }
r[5]=r[12];
goto P_0c0c6fb2;
P_0c0c6fb2: /* original 944c, guest PC 0x0c0c6fb2 */
if(!s->budget--) { s->failed_pc=0x0c0c6fb2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c704eu,2);
goto P_0c0c6fb4;
P_0c0c6fb4: /* original 7504, guest PC 0x0c0c6fb4 */
if(!s->budget--) { s->failed_pc=0x0c0c6fb4u; return 0; }
r[5]+=0x00000004u;
goto P_0c0c6fb6;
P_0c0c6fb6: /* original 9649, guest PC 0x0c0c6fb6 */
if(!s->budget--) { s->failed_pc=0x0c0c6fb6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c704cu,2);
goto P_0c0c6fb8;
P_0c0c6fb8: /* original f4e6, guest PC 0x0c0c6fb8 */
if(!s->budget--) { s->failed_pc=0x0c0c6fb8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c6fba;
P_0c0c6fba: /* original 34ec, guest PC 0x0c0c6fba */
if(!s->budget--) { s->failed_pc=0x0c0c6fbau; return 0; }
r[4]+=r[14];
goto P_0c0c6fbc;
P_0c0c6fbc: /* original 36ec, guest PC 0x0c0c6fbc */
if(!s->budget--) { s->failed_pc=0x0c0c6fbcu; return 0; }
r[6]+=r[14];
goto P_0c0c6fbe;
P_0c0c6fbe: /* original b047, guest PC 0x0c0c6fbe */
if(!s->budget--) { s->failed_pc=0x0c0c6fbeu; return 0; }
target=code_base|0x0c0c7050u; r[16]=code_base|0x0c0c6fc2u;
vf3_matrix_move(s,5,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6fc2u) { target=s->pc; goto dispatch; }
goto P_0c0c6fc2;
P_0c0c6fc0: /* original f5fc, guest PC 0x0c0c6fc0 */
if(!s->budget--) { s->failed_pc=0x0c0c6fc0u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c6fc2;
P_0c0c6fc2: /* original 9032, guest PC 0x0c0c6fc2 */
if(!s->budget--) { s->failed_pc=0x0c0c6fc2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c702au,2);
goto P_0c0c6fc4;
P_0c0c6fc4: /* original 6593, guest PC 0x0c0c6fc4 */
if(!s->budget--) { s->failed_pc=0x0c0c6fc4u; return 0; }
r[5]=r[9];
goto P_0c0c6fc6;
P_0c0c6fc6: /* original 9432, guest PC 0x0c0c6fc6 */
if(!s->budget--) { s->failed_pc=0x0c0c6fc6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c702eu,2);
goto P_0c0c6fc8;
P_0c0c6fc8: /* original 9630, guest PC 0x0c0c6fc8 */
if(!s->budget--) { s->failed_pc=0x0c0c6fc8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c702cu,2);
goto P_0c0c6fca;
P_0c0c6fca: /* original f4e6, guest PC 0x0c0c6fca */
if(!s->budget--) { s->failed_pc=0x0c0c6fcau; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c6fcc;
P_0c0c6fcc: /* original 34ec, guest PC 0x0c0c6fcc */
if(!s->budget--) { s->failed_pc=0x0c0c6fccu; return 0; }
r[4]+=r[14];
goto P_0c0c6fce;
P_0c0c6fce: /* original 36ec, guest PC 0x0c0c6fce */
if(!s->budget--) { s->failed_pc=0x0c0c6fceu; return 0; }
r[6]+=r[14];
goto P_0c0c6fd0;
P_0c0c6fd0: /* original b03e, guest PC 0x0c0c6fd0 */
if(!s->budget--) { s->failed_pc=0x0c0c6fd0u; return 0; }
target=code_base|0x0c0c7050u; r[16]=code_base|0x0c0c6fd4u;
vf3_matrix_move(s,5,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6fd4u) { target=s->pc; goto dispatch; }
goto P_0c0c6fd4;
P_0c0c6fd2: /* original f5fc, guest PC 0x0c0c6fd2 */
if(!s->budget--) { s->failed_pc=0x0c0c6fd2u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c6fd4;
P_0c0c6fd4: /* original 902c, guest PC 0x0c0c6fd4 */
if(!s->budget--) { s->failed_pc=0x0c0c6fd4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7030u,2);
goto P_0c0c6fd6;
P_0c0c6fd6: /* original 6583, guest PC 0x0c0c6fd6 */
if(!s->budget--) { s->failed_pc=0x0c0c6fd6u; return 0; }
r[5]=r[8];
goto P_0c0c6fd8;
P_0c0c6fd8: /* original 942c, guest PC 0x0c0c6fd8 */
if(!s->budget--) { s->failed_pc=0x0c0c6fd8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7034u,2);
goto P_0c0c6fda;
P_0c0c6fda: /* original 962a, guest PC 0x0c0c6fda */
if(!s->budget--) { s->failed_pc=0x0c0c6fdau; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7032u,2);
goto P_0c0c6fdc;
P_0c0c6fdc: /* original f4e6, guest PC 0x0c0c6fdc */
if(!s->budget--) { s->failed_pc=0x0c0c6fdcu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c6fde;
P_0c0c6fde: /* original 34ec, guest PC 0x0c0c6fde */
if(!s->budget--) { s->failed_pc=0x0c0c6fdeu; return 0; }
r[4]+=r[14];
goto P_0c0c6fe0;
P_0c0c6fe0: /* original 36ec, guest PC 0x0c0c6fe0 */
if(!s->budget--) { s->failed_pc=0x0c0c6fe0u; return 0; }
r[6]+=r[14];
goto P_0c0c6fe2;
P_0c0c6fe2: /* original b035, guest PC 0x0c0c6fe2 */
if(!s->budget--) { s->failed_pc=0x0c0c6fe2u; return 0; }
target=code_base|0x0c0c7050u; r[16]=code_base|0x0c0c6fe6u;
vf3_matrix_move(s,5,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6fe6u) { target=s->pc; goto dispatch; }
goto P_0c0c6fe6;
P_0c0c6fe4: /* original f5fc, guest PC 0x0c0c6fe4 */
if(!s->budget--) { s->failed_pc=0x0c0c6fe4u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c6fe6;
P_0c0c6fe6: /* original e240, guest PC 0x0c0c6fe6 */
if(!s->budget--) { s->failed_pc=0x0c0c6fe6u; return 0; }
r[2]=0x00000040u;
goto P_0c0c6fe8;
P_0c0c6fe8: /* original 2d28, guest PC 0x0c0c6fe8 */
if(!s->budget--) { s->failed_pc=0x0c0c6fe8u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[2])==0)!=0);
goto P_0c0c6fea;
P_0c0c6fea: /* original 8b11, guest PC 0x0c0c6fea */
if(!s->budget--) { s->failed_pc=0x0c0c6feau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7010; }
goto P_0c0c6fec;
P_0c0c6fec: /* original 9023, guest PC 0x0c0c6fec */
if(!s->budget--) { s->failed_pc=0x0c0c6fecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7036u,2);
goto P_0c0c6fee;
P_0c0c6fee: /* original 65b3, guest PC 0x0c0c6fee */
if(!s->budget--) { s->failed_pc=0x0c0c6feeu; return 0; }
r[5]=r[11];
goto P_0c0c6ff0;
P_0c0c6ff0: /* original 9423, guest PC 0x0c0c6ff0 */
if(!s->budget--) { s->failed_pc=0x0c0c6ff0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c703au,2);
goto P_0c0c6ff2;
P_0c0c6ff2: /* original 9621, guest PC 0x0c0c6ff2 */
if(!s->budget--) { s->failed_pc=0x0c0c6ff2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7038u,2);
goto P_0c0c6ff4;
P_0c0c6ff4: /* original f4e6, guest PC 0x0c0c6ff4 */
if(!s->budget--) { s->failed_pc=0x0c0c6ff4u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c6ff6;
P_0c0c6ff6: /* original 34ec, guest PC 0x0c0c6ff6 */
if(!s->budget--) { s->failed_pc=0x0c0c6ff6u; return 0; }
r[4]+=r[14];
goto P_0c0c6ff8;
P_0c0c6ff8: /* original 36ec, guest PC 0x0c0c6ff8 */
if(!s->budget--) { s->failed_pc=0x0c0c6ff8u; return 0; }
r[6]+=r[14];
goto P_0c0c6ffa;
P_0c0c6ffa: /* original b029, guest PC 0x0c0c6ffa */
if(!s->budget--) { s->failed_pc=0x0c0c6ffau; return 0; }
target=code_base|0x0c0c7050u; r[16]=code_base|0x0c0c6ffeu;
vf3_matrix_move(s,5,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6ffeu) { target=s->pc; goto dispatch; }
goto P_0c0c6ffe;
P_0c0c6ffc: /* original f5fc, guest PC 0x0c0c6ffc */
if(!s->budget--) { s->failed_pc=0x0c0c6ffcu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c6ffe;
P_0c0c6ffe: /* original 901d, guest PC 0x0c0c6ffe */
if(!s->budget--) { s->failed_pc=0x0c0c6ffeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c703cu,2);
goto P_0c0c7000;
P_0c0c7000: /* original 65a3, guest PC 0x0c0c7000 */
if(!s->budget--) { s->failed_pc=0x0c0c7000u; return 0; }
r[5]=r[10];
goto P_0c0c7002;
P_0c0c7002: /* original 941d, guest PC 0x0c0c7002 */
if(!s->budget--) { s->failed_pc=0x0c0c7002u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7040u,2);
goto P_0c0c7004;
P_0c0c7004: /* original 961b, guest PC 0x0c0c7004 */
if(!s->budget--) { s->failed_pc=0x0c0c7004u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c703eu,2);
goto P_0c0c7006;
P_0c0c7006: /* original f4e6, guest PC 0x0c0c7006 */
if(!s->budget--) { s->failed_pc=0x0c0c7006u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c7008;
P_0c0c7008: /* original 34ec, guest PC 0x0c0c7008 */
if(!s->budget--) { s->failed_pc=0x0c0c7008u; return 0; }
r[4]+=r[14];
goto P_0c0c700a;
P_0c0c700a: /* original 36ec, guest PC 0x0c0c700a */
if(!s->budget--) { s->failed_pc=0x0c0c700au; return 0; }
r[6]+=r[14];
goto P_0c0c700c;
P_0c0c700c: /* original b020, guest PC 0x0c0c700c */
if(!s->budget--) { s->failed_pc=0x0c0c700cu; return 0; }
target=code_base|0x0c0c7050u; r[16]=code_base|0x0c0c7010u;
vf3_matrix_move(s,5,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7010u) { target=s->pc; goto dispatch; }
goto P_0c0c7010;
P_0c0c700e: /* original f5fc, guest PC 0x0c0c700e */
if(!s->budget--) { s->failed_pc=0x0c0c700eu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c7010;
P_0c0c7010: /* original 4f26, guest PC 0x0c0c7010 */
if(!s->budget--) { s->failed_pc=0x0c0c7010u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7012;
P_0c0c7012: /* original fff9, guest PC 0x0c0c7012 */
if(!s->budget--) { s->failed_pc=0x0c0c7012u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c7014;
P_0c0c7014: /* original 68f6, guest PC 0x0c0c7014 */
if(!s->budget--) { s->failed_pc=0x0c0c7014u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c7016;
P_0c0c7016: /* original 69f6, guest PC 0x0c0c7016 */
if(!s->budget--) { s->failed_pc=0x0c0c7016u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c7018;
P_0c0c7018: /* original 6af6, guest PC 0x0c0c7018 */
if(!s->budget--) { s->failed_pc=0x0c0c7018u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c701a;
P_0c0c701a: /* original 6bf6, guest PC 0x0c0c701a */
if(!s->budget--) { s->failed_pc=0x0c0c701au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c701c;
P_0c0c701c: /* original 6cf6, guest PC 0x0c0c701c */
if(!s->budget--) { s->failed_pc=0x0c0c701cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c701e;
P_0c0c701e: /* original 6df6, guest PC 0x0c0c701e */
if(!s->budget--) { s->failed_pc=0x0c0c701eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c7020;
P_0c0c7020: /* original 000b, guest PC 0x0c0c7020 */
if(!s->budget--) { s->failed_pc=0x0c0c7020u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c7022: /* original 6ef6, guest PC 0x0c0c7022 */
if(!s->budget--) { s->failed_pc=0x0c0c7022u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c7024u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c7024u; return 0; } return 1;
P_0c0c7050: /* original d727, guest PC 0x0c0c7050 */
if(!s->budget--) { s->failed_pc=0x0c0c7050u; return 0; }
r[7]=read(ram,0x0c0c70f0u,4);
goto P_0c0c7052;
P_0c0c7052: /* original f64c, guest PC 0x0c0c7052 */
if(!s->budget--) { s->failed_pc=0x0c0c7052u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c0c7054;
P_0c0c7054: /* original 5377, guest PC 0x0c0c7054 */
if(!s->budget--) { s->failed_pc=0x0c0c7054u; return 0; }
r[3]=read(ram,r[7]+28,4);
goto P_0c0c7056;
P_0c0c7056: /* original 2338, guest PC 0x0c0c7056 */
if(!s->budget--) { s->failed_pc=0x0c0c7056u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c7058;
P_0c0c7058: /* original 8f02, guest PC 0x0c0c7058 */
if(!s->budget--) { s->failed_pc=0x0c0c7058u; return 0; }
cond=r[17]&1u;
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'-');
if(!cond) { goto P_0c0c7060; }
goto P_0c0c705c;
P_0c0c705a: /* original f651, guest PC 0x0c0c705a */
if(!s->budget--) { s->failed_pc=0x0c0c705au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'-');
goto P_0c0c705c;
P_0c0c705c: /* original a00f, guest PC 0x0c0c705c */
if(!s->budget--) { s->failed_pc=0x0c0c705cu; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0c707e;
P_0c0c705e: /* original f46c, guest PC 0x0c0c705e */
if(!s->budget--) { s->failed_pc=0x0c0c705eu; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0c7060;
P_0c0c7060: /* original 5376, guest PC 0x0c0c7060 */
if(!s->budget--) { s->failed_pc=0x0c0c7060u; return 0; }
r[3]=read(ram,r[7]+24,4);
goto P_0c0c7062;
P_0c0c7062: /* original 2338, guest PC 0x0c0c7062 */
if(!s->budget--) { s->failed_pc=0x0c0c7062u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c7064;
P_0c0c7064: /* original 8b05, guest PC 0x0c0c7064 */
if(!s->budget--) { s->failed_pc=0x0c0c7064u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7072; }
goto P_0c0c7066;
P_0c0c7066: /* original f38d, guest PC 0x0c0c7066 */
if(!s->budget--) { s->failed_pc=0x0c0c7066u; return 0; }
fr[3]=0;
goto P_0c0c7068;
P_0c0c7068: /* original f355, guest PC 0x0c0c7068 */
if(!s->budget--) { s->failed_pc=0x0c0c7068u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c0c706a;
P_0c0c706a: /* original 8f09, guest PC 0x0c0c706a */
if(!s->budget--) { s->failed_pc=0x0c0c706au; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,6);
if(!cond) { goto P_0c0c7080; }
goto P_0c0c706e;
P_0c0c706c: /* original f46c, guest PC 0x0c0c706c */
if(!s->budget--) { s->failed_pc=0x0c0c706cu; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0c706e;
P_0c0c706e: /* original a006, guest PC 0x0c0c706e */
if(!s->budget--) { s->failed_pc=0x0c0c706eu; return 0; }
goto P_0c0c707e;
P_0c0c7070: /* original 0009, guest PC 0x0c0c7070 */
if(!s->budget--) { s->failed_pc=0x0c0c7070u; return 0; }
goto P_0c0c7072;
P_0c0c7072: /* original f668, guest PC 0x0c0c7072 */
if(!s->budget--) { s->failed_pc=0x0c0c7072u; return 0; }
vf3_matrix_load(s,ram,6,r[6]);
goto P_0c0c7074;
P_0c0c7074: /* original f558, guest PC 0x0c0c7074 */
if(!s->budget--) { s->failed_pc=0x0c0c7074u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
goto P_0c0c7076;
P_0c0c7076: /* original f561, guest PC 0x0c0c7076 */
if(!s->budget--) { s->failed_pc=0x0c0c7076u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c0c7078;
P_0c0c7078: /* original f545, guest PC 0x0c0c7078 */
if(!s->budget--) { s->failed_pc=0x0c0c7078u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c0c707a;
P_0c0c707a: /* original 8901, guest PC 0x0c0c707a */
if(!s->budget--) { s->failed_pc=0x0c0c707au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7080; }
goto P_0c0c707c;
P_0c0c707c: /* original f451, guest PC 0x0c0c707c */
if(!s->budget--) { s->failed_pc=0x0c0c707cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c0c707e;
P_0c0c707e: /* original f44a, guest PC 0x0c0c707e */
if(!s->budget--) { s->failed_pc=0x0c0c707eu; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c0c7080;
P_0c0c7080: /* original 000b, guest PC 0x0c0c7080 */
if(!s->budget--) { s->failed_pc=0x0c0c7080u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c7082: /* original 0009, guest PC 0x0c0c7082 */
if(!s->budget--) { s->failed_pc=0x0c0c7082u; return 0; }
if(!vf3_matrix_family(0x0c0c7084u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c7084u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
