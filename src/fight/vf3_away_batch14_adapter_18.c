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
int vf3_away_batch14_adapter_18(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c088d06u: goto P_0c088d06;
case 0x0c088d08u: goto P_0c088d08;
case 0x0c088d0au: goto P_0c088d0a;
case 0x0c088d0cu: goto P_0c088d0c;
case 0x0c088d0eu: goto P_0c088d0e;
case 0x0c088d10u: goto P_0c088d10;
case 0x0c088d12u: goto P_0c088d12;
case 0x0c088d14u: goto P_0c088d14;
case 0x0c088d16u: goto P_0c088d16;
case 0x0c088d18u: goto P_0c088d18;
case 0x0c088d1au: goto P_0c088d1a;
case 0x0c088d1cu: goto P_0c088d1c;
case 0x0c088d1eu: goto P_0c088d1e;
case 0x0c088d20u: goto P_0c088d20;
case 0x0c088d22u: goto P_0c088d22;
case 0x0c088d24u: goto P_0c088d24;
case 0x0c088d26u: goto P_0c088d26;
case 0x0c088d28u: goto P_0c088d28;
case 0x0c088d2au: goto P_0c088d2a;
case 0x0c088d2cu: goto P_0c088d2c;
case 0x0c088d2eu: goto P_0c088d2e;
case 0x0c088d30u: goto P_0c088d30;
case 0x0c088d32u: goto P_0c088d32;
case 0x0c088d34u: goto P_0c088d34;
case 0x0c088d36u: goto P_0c088d36;
case 0x0c088d38u: goto P_0c088d38;
case 0x0c088d3au: goto P_0c088d3a;
case 0x0c088d3cu: goto P_0c088d3c;
case 0x0c088d3eu: goto P_0c088d3e;
case 0x0c088d40u: goto P_0c088d40;
case 0x0c088d42u: goto P_0c088d42;
case 0x0c088d44u: goto P_0c088d44;
case 0x0c088d46u: goto P_0c088d46;
case 0x0c088d48u: goto P_0c088d48;
case 0x0c088d4au: goto P_0c088d4a;
case 0x0c088d4cu: goto P_0c088d4c;
case 0x0c088d4eu: goto P_0c088d4e;
case 0x0c088d50u: goto P_0c088d50;
case 0x0c088d52u: goto P_0c088d52;
case 0x0c088d54u: goto P_0c088d54;
case 0x0c088d56u: goto P_0c088d56;
case 0x0c088d58u: goto P_0c088d58;
case 0x0c088d5au: goto P_0c088d5a;
case 0x0c088d5cu: goto P_0c088d5c;
case 0x0c088d5eu: goto P_0c088d5e;
case 0x0c088d60u: goto P_0c088d60;
case 0x0c088d62u: goto P_0c088d62;
case 0x0c088d64u: goto P_0c088d64;
case 0x0c088d66u: goto P_0c088d66;
case 0x0c088d68u: goto P_0c088d68;
case 0x0c088d6au: goto P_0c088d6a;
case 0x0c088d6cu: goto P_0c088d6c;
case 0x0c088d6eu: goto P_0c088d6e;
case 0x0c088d70u: goto P_0c088d70;
case 0x0c088d72u: goto P_0c088d72;
case 0x0c088d74u: goto P_0c088d74;
case 0x0c088d76u: goto P_0c088d76;
case 0x0c088d78u: goto P_0c088d78;
case 0x0c088d7au: goto P_0c088d7a;
case 0x0c088d7cu: goto P_0c088d7c;
case 0x0c088d7eu: goto P_0c088d7e;
case 0x0c088d80u: goto P_0c088d80;
case 0x0c088d82u: goto P_0c088d82;
case 0x0c088d84u: goto P_0c088d84;
case 0x0c088d86u: goto P_0c088d86;
case 0x0c088d88u: goto P_0c088d88;
case 0x0c088d8au: goto P_0c088d8a;
case 0x0c088d8cu: goto P_0c088d8c;
case 0x0c088d8eu: goto P_0c088d8e;
case 0x0c088d90u: goto P_0c088d90;
case 0x0c088d92u: goto P_0c088d92;
case 0x0c088d94u: goto P_0c088d94;
case 0x0c088d96u: goto P_0c088d96;
case 0x0c088dbcu: goto P_0c088dbc;
case 0x0c088dbeu: goto P_0c088dbe;
case 0x0c088dc0u: goto P_0c088dc0;
case 0x0c088dc2u: goto P_0c088dc2;
case 0x0c088dc4u: goto P_0c088dc4;
case 0x0c088dc6u: goto P_0c088dc6;
case 0x0c088dc8u: goto P_0c088dc8;
case 0x0c088dcau: goto P_0c088dca;
case 0x0c088dccu: goto P_0c088dcc;
case 0x0c088dceu: goto P_0c088dce;
case 0x0c088dd0u: goto P_0c088dd0;
case 0x0c088dd2u: goto P_0c088dd2;
case 0x0c088dd4u: goto P_0c088dd4;
case 0x0c088dd6u: goto P_0c088dd6;
case 0x0c088dd8u: goto P_0c088dd8;
case 0x0c088ddau: goto P_0c088dda;
case 0x0c088ddcu: goto P_0c088ddc;
case 0x0c088ddeu: goto P_0c088dde;
case 0x0c088de0u: goto P_0c088de0;
case 0x0c088de2u: goto P_0c088de2;
case 0x0c088de4u: goto P_0c088de4;
case 0x0c088de6u: goto P_0c088de6;
case 0x0c088de8u: goto P_0c088de8;
case 0x0c088deau: goto P_0c088dea;
case 0x0c088decu: goto P_0c088dec;
case 0x0c088deeu: goto P_0c088dee;
case 0x0c088df0u: goto P_0c088df0;
case 0x0c088df2u: goto P_0c088df2;
case 0x0c088df4u: goto P_0c088df4;
case 0x0c088df6u: goto P_0c088df6;
case 0x0c088df8u: goto P_0c088df8;
case 0x0c088dfau: goto P_0c088dfa;
case 0x0c088dfcu: goto P_0c088dfc;
case 0x0c088dfeu: goto P_0c088dfe;
case 0x0c088e00u: goto P_0c088e00;
case 0x0c088e02u: goto P_0c088e02;
case 0x0c088e04u: goto P_0c088e04;
case 0x0c088e06u: goto P_0c088e06;
case 0x0c088e08u: goto P_0c088e08;
case 0x0c088e0au: goto P_0c088e0a;
case 0x0c088e0cu: goto P_0c088e0c;
case 0x0c088e0eu: goto P_0c088e0e;
case 0x0c088e10u: goto P_0c088e10;
case 0x0c088e12u: goto P_0c088e12;
case 0x0c088e14u: goto P_0c088e14;
case 0x0c088e16u: goto P_0c088e16;
case 0x0c088e18u: goto P_0c088e18;
case 0x0c088e1au: goto P_0c088e1a;
case 0x0c088e1cu: goto P_0c088e1c;
case 0x0c088e1eu: goto P_0c088e1e;
case 0x0c088e20u: goto P_0c088e20;
case 0x0c088e22u: goto P_0c088e22;
case 0x0c088e24u: goto P_0c088e24;
case 0x0c088e26u: goto P_0c088e26;
case 0x0c088e28u: goto P_0c088e28;
case 0x0c088e2au: goto P_0c088e2a;
case 0x0c088e2cu: goto P_0c088e2c;
case 0x0c088e2eu: goto P_0c088e2e;
case 0x0c088e30u: goto P_0c088e30;
case 0x0c088e32u: goto P_0c088e32;
case 0x0c088e34u: goto P_0c088e34;
case 0x0c088e36u: goto P_0c088e36;
case 0x0c088e38u: goto P_0c088e38;
case 0x0c088e3au: goto P_0c088e3a;
case 0x0c088e3cu: goto P_0c088e3c;
case 0x0c088e3eu: goto P_0c088e3e;
case 0x0c088e40u: goto P_0c088e40;
case 0x0c088e42u: goto P_0c088e42;
case 0x0c088e44u: goto P_0c088e44;
case 0x0c088e46u: goto P_0c088e46;
case 0x0c088e48u: goto P_0c088e48;
case 0x0c088e4au: goto P_0c088e4a;
case 0x0c088e4cu: goto P_0c088e4c;
case 0x0c088e4eu: goto P_0c088e4e;
case 0x0c088e50u: goto P_0c088e50;
case 0x0c088e52u: goto P_0c088e52;
case 0x0c088e54u: goto P_0c088e54;
case 0x0c088e56u: goto P_0c088e56;
case 0x0c088e58u: goto P_0c088e58;
case 0x0c088e5au: goto P_0c088e5a;
case 0x0c088e5cu: goto P_0c088e5c;
case 0x0c088e5eu: goto P_0c088e5e;
case 0x0c088e60u: goto P_0c088e60;
case 0x0c088e62u: goto P_0c088e62;
case 0x0c088e64u: goto P_0c088e64;
case 0x0c088e66u: goto P_0c088e66;
case 0x0c088e68u: goto P_0c088e68;
case 0x0c088e6au: goto P_0c088e6a;
case 0x0c088e6cu: goto P_0c088e6c;
case 0x0c088e6eu: goto P_0c088e6e;
case 0x0c088e70u: goto P_0c088e70;
case 0x0c088e72u: goto P_0c088e72;
case 0x0c088e74u: goto P_0c088e74;
case 0x0c088e76u: goto P_0c088e76;
case 0x0c088e78u: goto P_0c088e78;
case 0x0c088e7au: goto P_0c088e7a;
case 0x0c088e7cu: goto P_0c088e7c;
case 0x0c088e7eu: goto P_0c088e7e;
case 0x0c088e80u: goto P_0c088e80;
case 0x0c088e82u: goto P_0c088e82;
case 0x0c088e84u: goto P_0c088e84;
case 0x0c088e86u: goto P_0c088e86;
case 0x0c088e88u: goto P_0c088e88;
case 0x0c088e8au: goto P_0c088e8a;
case 0x0c088e8cu: goto P_0c088e8c;
case 0x0c088e8eu: goto P_0c088e8e;
case 0x0c088e90u: goto P_0c088e90;
case 0x0c088e92u: goto P_0c088e92;
case 0x0c088e94u: goto P_0c088e94;
case 0x0c088e96u: goto P_0c088e96;
case 0x0c088e98u: goto P_0c088e98;
case 0x0c088e9au: goto P_0c088e9a;
case 0x0c088e9cu: goto P_0c088e9c;
case 0x0c088e9eu: goto P_0c088e9e;
case 0x0c088ea0u: goto P_0c088ea0;
case 0x0c088ea2u: goto P_0c088ea2;
case 0x0c088ea4u: goto P_0c088ea4;
case 0x0c088ea6u: goto P_0c088ea6;
case 0x0c088ea8u: goto P_0c088ea8;
case 0x0c088eaau: goto P_0c088eaa;
case 0x0c088eacu: goto P_0c088eac;
case 0x0c088eaeu: goto P_0c088eae;
case 0x0c088eb0u: goto P_0c088eb0;
case 0x0c088eb2u: goto P_0c088eb2;
case 0x0c088eb4u: goto P_0c088eb4;
case 0x0c088eb6u: goto P_0c088eb6;
case 0x0c088eb8u: goto P_0c088eb8;
case 0x0c088ebau: goto P_0c088eba;
case 0x0c088ebcu: goto P_0c088ebc;
case 0x0c088ebeu: goto P_0c088ebe;
case 0x0c088ec0u: goto P_0c088ec0;
case 0x0c088ec2u: goto P_0c088ec2;
case 0x0c088ec4u: goto P_0c088ec4;
case 0x0c088ec6u: goto P_0c088ec6;
case 0x0c088ec8u: goto P_0c088ec8;
case 0x0c088ef0u: goto P_0c088ef0;
case 0x0c088ef2u: goto P_0c088ef2;
case 0x0c088ef4u: goto P_0c088ef4;
case 0x0c088ef6u: goto P_0c088ef6;
case 0x0c088ef8u: goto P_0c088ef8;
case 0x0c088efau: goto P_0c088efa;
case 0x0c088efcu: goto P_0c088efc;
case 0x0c088efeu: goto P_0c088efe;
case 0x0c088f00u: goto P_0c088f00;
case 0x0c088f02u: goto P_0c088f02;
case 0x0c088f04u: goto P_0c088f04;
case 0x0c088f06u: goto P_0c088f06;
case 0x0c088f08u: goto P_0c088f08;
case 0x0c088f0au: goto P_0c088f0a;
case 0x0c088f0cu: goto P_0c088f0c;
case 0x0c088f0eu: goto P_0c088f0e;
case 0x0c088f10u: goto P_0c088f10;
case 0x0c088f12u: goto P_0c088f12;
case 0x0c088f14u: goto P_0c088f14;
case 0x0c088f16u: goto P_0c088f16;
case 0x0c088f18u: goto P_0c088f18;
case 0x0c088f1au: goto P_0c088f1a;
case 0x0c088f1cu: goto P_0c088f1c;
case 0x0c088f1eu: goto P_0c088f1e;
case 0x0c088f20u: goto P_0c088f20;
case 0x0c088f22u: goto P_0c088f22;
case 0x0c088f24u: goto P_0c088f24;
case 0x0c088f26u: goto P_0c088f26;
case 0x0c088f28u: goto P_0c088f28;
case 0x0c088f2au: goto P_0c088f2a;
case 0x0c088f2cu: goto P_0c088f2c;
case 0x0c088f2eu: goto P_0c088f2e;
case 0x0c088f30u: goto P_0c088f30;
case 0x0c088f32u: goto P_0c088f32;
case 0x0c088f34u: goto P_0c088f34;
case 0x0c088f36u: goto P_0c088f36;
case 0x0c088f38u: goto P_0c088f38;
case 0x0c088f3au: goto P_0c088f3a;
case 0x0c088f3cu: goto P_0c088f3c;
case 0x0c088f3eu: goto P_0c088f3e;
case 0x0c088f40u: goto P_0c088f40;
case 0x0c088f42u: goto P_0c088f42;
case 0x0c088f44u: goto P_0c088f44;
case 0x0c088f46u: goto P_0c088f46;
case 0x0c088f48u: goto P_0c088f48;
case 0x0c088f4au: goto P_0c088f4a;
case 0x0c088f4cu: goto P_0c088f4c;
case 0x0c088f4eu: goto P_0c088f4e;
case 0x0c088f50u: goto P_0c088f50;
case 0x0c088f52u: goto P_0c088f52;
case 0x0c088f54u: goto P_0c088f54;
case 0x0c088f56u: goto P_0c088f56;
case 0x0c088f58u: goto P_0c088f58;
case 0x0c088f5au: goto P_0c088f5a;
case 0x0c088f5cu: goto P_0c088f5c;
case 0x0c088f5eu: goto P_0c088f5e;
case 0x0c088f60u: goto P_0c088f60;
case 0x0c088f62u: goto P_0c088f62;
case 0x0c088f64u: goto P_0c088f64;
case 0x0c088f66u: goto P_0c088f66;
case 0x0c088f68u: goto P_0c088f68;
case 0x0c088f6au: goto P_0c088f6a;
case 0x0c088f6cu: goto P_0c088f6c;
case 0x0c088f6eu: goto P_0c088f6e;
case 0x0c088f70u: goto P_0c088f70;
case 0x0c088f72u: goto P_0c088f72;
case 0x0c088f74u: goto P_0c088f74;
case 0x0c088f76u: goto P_0c088f76;
case 0x0c088f78u: goto P_0c088f78;
case 0x0c088f7au: goto P_0c088f7a;
case 0x0c088f7cu: goto P_0c088f7c;
case 0x0c088f7eu: goto P_0c088f7e;
case 0x0c088f80u: goto P_0c088f80;
case 0x0c088f82u: goto P_0c088f82;
case 0x0c088f84u: goto P_0c088f84;
case 0x0c088f86u: goto P_0c088f86;
case 0x0c088f88u: goto P_0c088f88;
case 0x0c088f8au: goto P_0c088f8a;
case 0x0c088f8cu: goto P_0c088f8c;
case 0x0c088f8eu: goto P_0c088f8e;
case 0x0c088f90u: goto P_0c088f90;
case 0x0c088f92u: goto P_0c088f92;
case 0x0c088f94u: goto P_0c088f94;
case 0x0c088f96u: goto P_0c088f96;
case 0x0c088f98u: goto P_0c088f98;
case 0x0c088f9au: goto P_0c088f9a;
case 0x0c088f9cu: goto P_0c088f9c;
case 0x0c088f9eu: goto P_0c088f9e;
case 0x0c088fa0u: goto P_0c088fa0;
case 0x0c088fa2u: goto P_0c088fa2;
case 0x0c088fa4u: goto P_0c088fa4;
case 0x0c088fa6u: goto P_0c088fa6;
case 0x0c088fa8u: goto P_0c088fa8;
case 0x0c088faau: goto P_0c088faa;
case 0x0c088facu: goto P_0c088fac;
case 0x0c088faeu: goto P_0c088fae;
case 0x0c088fb0u: goto P_0c088fb0;
case 0x0c088fb2u: goto P_0c088fb2;
case 0x0c088fb4u: goto P_0c088fb4;
case 0x0c088fb6u: goto P_0c088fb6;
case 0x0c088fb8u: goto P_0c088fb8;
case 0x0c088fbau: goto P_0c088fba;
case 0x0c088fbcu: goto P_0c088fbc;
case 0x0c088fbeu: goto P_0c088fbe;
case 0x0c088fc0u: goto P_0c088fc0;
case 0x0c088fc2u: goto P_0c088fc2;
case 0x0c088fc4u: goto P_0c088fc4;
case 0x0c088fc6u: goto P_0c088fc6;
case 0x0c088fc8u: goto P_0c088fc8;
case 0x0c088fcau: goto P_0c088fca;
case 0x0c088fccu: goto P_0c088fcc;
case 0x0c088fceu: goto P_0c088fce;
default: return vf3_matrix_family(target,s,ram);
}
P_0c088d06: /* original 2fe6, guest PC 0x0c088d06 */
if(!s->budget--) { s->failed_pc=0x0c088d06u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088d08;
P_0c088d08: /* original 2fd6, guest PC 0x0c088d08 */
if(!s->budget--) { s->failed_pc=0x0c088d08u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088d0a;
P_0c088d0a: /* original 2fc6, guest PC 0x0c088d0a */
if(!s->budget--) { s->failed_pc=0x0c088d0au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088d0c;
P_0c088d0c: /* original fffb, guest PC 0x0c088d0c */
if(!s->budget--) { s->failed_pc=0x0c088d0cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c088d0e;
P_0c088d0e: /* original d128, guest PC 0x0c088d0e */
if(!s->budget--) { s->failed_pc=0x0c088d0eu; return 0; }
r[1]=read(ram,0x0c088db0u,4);
goto P_0c088d10;
P_0c088d10: /* original 4f22, guest PC 0x0c088d10 */
if(!s->budget--) { s->failed_pc=0x0c088d10u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c088d12;
P_0c088d12: /* original 6212, guest PC 0x0c088d12 */
if(!s->budget--) { s->failed_pc=0x0c088d12u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c088d14;
P_0c088d14: /* original d325, guest PC 0x0c088d14 */
if(!s->budget--) { s->failed_pc=0x0c088d14u; return 0; }
r[3]=read(ram,0x0c088dacu,4);
goto P_0c088d16;
P_0c088d16: /* original 7ffc, guest PC 0x0c088d16 */
if(!s->budget--) { s->failed_pc=0x0c088d16u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c088d18;
P_0c088d18: /* original 2238, guest PC 0x0c088d18 */
if(!s->budget--) { s->failed_pc=0x0c088d18u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c088d1a;
P_0c088d1a: /* original 8b36, guest PC 0x0c088d1a */
if(!s->budget--) { s->failed_pc=0x0c088d1au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c088d8a; }
goto P_0c088d1c;
P_0c088d1c: /* original 6e43, guest PC 0x0c088d1c */
if(!s->budget--) { s->failed_pc=0x0c088d1cu; return 0; }
r[14]=r[4];
goto P_0c088d1e;
P_0c088d1e: /* original 84e3, guest PC 0x0c088d1e */
if(!s->budget--) { s->failed_pc=0x0c088d1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+3,1);
goto P_0c088d20;
P_0c088d20: /* original 6403, guest PC 0x0c088d20 */
if(!s->budget--) { s->failed_pc=0x0c088d20u; return 0; }
r[4]=r[0];
goto P_0c088d22;
P_0c088d22: /* original 74ff, guest PC 0x0c088d22 */
if(!s->budget--) { s->failed_pc=0x0c088d22u; return 0; }
r[4]+=0xffffffffu;
goto P_0c088d24;
P_0c088d24: /* original 634e, guest PC 0x0c088d24 */
if(!s->budget--) { s->failed_pc=0x0c088d24u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c088d26;
P_0c088d26: /* original 4311, guest PC 0x0c088d26 */
if(!s->budget--) { s->failed_pc=0x0c088d26u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c088d28;
P_0c088d28: /* original 8907, guest PC 0x0c088d28 */
if(!s->budget--) { s->failed_pc=0x0c088d28u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088d3a; }
goto P_0c088d2a;
P_0c088d2a: /* original 84e2, guest PC 0x0c088d2a */
if(!s->budget--) { s->failed_pc=0x0c088d2au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c088d2c;
P_0c088d2c: /* original e31f, guest PC 0x0c088d2c */
if(!s->budget--) { s->failed_pc=0x0c088d2cu; return 0; }
r[3]=0x0000001fu;
goto P_0c088d2e;
P_0c088d2e: /* original e402, guest PC 0x0c088d2e */
if(!s->budget--) { s->failed_pc=0x0c088d2eu; return 0; }
r[4]=0x00000002u;
goto P_0c088d30;
P_0c088d30: /* original 6503, guest PC 0x0c088d30 */
if(!s->budget--) { s->failed_pc=0x0c088d30u; return 0; }
r[5]=r[0];
goto P_0c088d32;
P_0c088d32: /* original 7501, guest PC 0x0c088d32 */
if(!s->budget--) { s->failed_pc=0x0c088d32u; return 0; }
r[5]+=0x00000001u;
goto P_0c088d34;
P_0c088d34: /* original 2539, guest PC 0x0c088d34 */
if(!s->budget--) { s->failed_pc=0x0c088d34u; return 0; }
r[5]&=r[3];
goto P_0c088d36;
P_0c088d36: /* original 6053, guest PC 0x0c088d36 */
if(!s->budget--) { s->failed_pc=0x0c088d36u; return 0; }
r[0]=r[5];
goto P_0c088d38;
P_0c088d38: /* original 80e2, guest PC 0x0c088d38 */
if(!s->budget--) { s->failed_pc=0x0c088d38u; return 0; }
write(ram,r[14]+2,r[0],1);
goto P_0c088d3a;
P_0c088d3a: /* original 6043, guest PC 0x0c088d3a */
if(!s->budget--) { s->failed_pc=0x0c088d3au; return 0; }
r[0]=r[4];
goto P_0c088d3c;
P_0c088d3c: /* original 80e3, guest PC 0x0c088d3c */
if(!s->budget--) { s->failed_pc=0x0c088d3cu; return 0; }
write(ram,r[14]+3,r[0],1);
goto P_0c088d3e;
P_0c088d3e: /* original 64e0, guest PC 0x0c088d3e */
if(!s->budget--) { s->failed_pc=0x0c088d3eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[4]=tmp;
goto P_0c088d40;
P_0c088d40: /* original e30f, guest PC 0x0c088d40 */
if(!s->budget--) { s->failed_pc=0x0c088d40u; return 0; }
r[3]=0x0000000fu;
goto P_0c088d42;
P_0c088d42: /* original 7401, guest PC 0x0c088d42 */
if(!s->budget--) { s->failed_pc=0x0c088d42u; return 0; }
r[4]+=0x00000001u;
goto P_0c088d44;
P_0c088d44: /* original 2439, guest PC 0x0c088d44 */
if(!s->budget--) { s->failed_pc=0x0c088d44u; return 0; }
r[4]&=r[3];
goto P_0c088d46;
P_0c088d46: /* original 2e40, guest PC 0x0c088d46 */
if(!s->budget--) { s->failed_pc=0x0c088d46u; return 0; }
write(ram,r[14],r[4],1);
goto P_0c088d48;
P_0c088d48: /* original 85e6, guest PC 0x0c088d48 */
if(!s->budget--) { s->failed_pc=0x0c088d48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c088d4a;
P_0c088d4a: /* original 9127, guest PC 0x0c088d4a */
if(!s->budget--) { s->failed_pc=0x0c088d4au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c088d9cu,2);
goto P_0c088d4c;
P_0c088d4c: /* original 6d03, guest PC 0x0c088d4c */
if(!s->budget--) { s->failed_pc=0x0c088d4cu; return 0; }
r[13]=r[0];
goto P_0c088d4e;
P_0c088d4e: /* original 85e7, guest PC 0x0c088d4e */
if(!s->budget--) { s->failed_pc=0x0c088d4eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c088d50;
P_0c088d50: /* original 9223, guest PC 0x0c088d50 */
if(!s->budget--) { s->failed_pc=0x0c088d50u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c088d9au,2);
goto P_0c088d52;
P_0c088d52: /* original 6c03, guest PC 0x0c088d52 */
if(!s->budget--) { s->failed_pc=0x0c088d52u; return 0; }
r[12]=r[0];
goto P_0c088d54;
P_0c088d54: /* original c717, guest PC 0x0c088d54 */
if(!s->budget--) { s->failed_pc=0x0c088d54u; return 0; }
r[0]=code_base|0x00088db4u;
goto P_0c088d56;
P_0c088d56: /* original d318, guest PC 0x0c088d56 */
if(!s->budget--) { s->failed_pc=0x0c088d56u; return 0; }
r[3]=read(ram,0x0c088db8u,4);
goto P_0c088d58;
P_0c088d58: /* original 3c1c, guest PC 0x0c088d58 */
if(!s->budget--) { s->failed_pc=0x0c088d58u; return 0; }
r[12]+=r[1];
goto P_0c088d5a;
P_0c088d5a: /* original ff08, guest PC 0x0c088d5a */
if(!s->budget--) { s->failed_pc=0x0c088d5au; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c088d5c;
P_0c088d5c: /* original 3d2c, guest PC 0x0c088d5c */
if(!s->budget--) { s->failed_pc=0x0c088d5cu; return 0; }
r[13]+=r[2];
goto P_0c088d5e;
P_0c088d5e: /* original 430b, guest PC 0x0c088d5e */
if(!s->budget--) { s->failed_pc=0x0c088d5eu; return 0; }
target=r[3];
r[16]=code_base|0x0c088d62u;
r[4]=(uint32_t)(int32_t)(int16_t)r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088d62u) { target=s->pc; goto dispatch; }
goto P_0c088d62;
P_0c088d60: /* original 64df, guest PC 0x0c088d60 */
if(!s->budget--) { s->failed_pc=0x0c088d60u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c088d62;
P_0c088d62: /* original f40c, guest PC 0x0c088d62 */
if(!s->budget--) { s->failed_pc=0x0c088d62u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c088d64;
P_0c088d64: /* original f4f2, guest PC 0x0c088d64 */
if(!s->budget--) { s->failed_pc=0x0c088d64u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c088d66;
P_0c088d66: /* original f43d, guest PC 0x0c088d66 */
if(!s->budget--) { s->failed_pc=0x0c088d66u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c088d68;
P_0c088d68: /* original 025a, guest PC 0x0c088d68 */
if(!s->budget--) { s->failed_pc=0x0c088d68u; return 0; }
r[2]=r[53];
goto P_0c088d6a;
P_0c088d6a: /* original 2f21, guest PC 0x0c088d6a */
if(!s->budget--) { s->failed_pc=0x0c088d6au; return 0; }
write(ram,r[15],r[2],2);
goto P_0c088d6c;
P_0c088d6c: /* original d312, guest PC 0x0c088d6c */
if(!s->budget--) { s->failed_pc=0x0c088d6cu; return 0; }
r[3]=read(ram,0x0c088db8u,4);
goto P_0c088d6e;
P_0c088d6e: /* original 430b, guest PC 0x0c088d6e */
if(!s->budget--) { s->failed_pc=0x0c088d6eu; return 0; }
target=r[3];
r[16]=code_base|0x0c088d72u;
r[4]=(uint32_t)(int32_t)(int16_t)r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088d72u) { target=s->pc; goto dispatch; }
goto P_0c088d72;
P_0c088d70: /* original 64cf, guest PC 0x0c088d70 */
if(!s->budget--) { s->failed_pc=0x0c088d70u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c088d72;
P_0c088d72: /* original f40c, guest PC 0x0c088d72 */
if(!s->budget--) { s->failed_pc=0x0c088d72u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c088d74;
P_0c088d74: /* original f4f2, guest PC 0x0c088d74 */
if(!s->budget--) { s->failed_pc=0x0c088d74u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c088d76;
P_0c088d76: /* original 60d3, guest PC 0x0c088d76 */
if(!s->budget--) { s->failed_pc=0x0c088d76u; return 0; }
r[0]=r[13];
goto P_0c088d78;
P_0c088d78: /* original f43d, guest PC 0x0c088d78 */
if(!s->budget--) { s->failed_pc=0x0c088d78u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c088d7a;
P_0c088d7a: /* original 045a, guest PC 0x0c088d7a */
if(!s->budget--) { s->failed_pc=0x0c088d7au; return 0; }
r[4]=r[53];
goto P_0c088d7c;
P_0c088d7c: /* original 81e6, guest PC 0x0c088d7c */
if(!s->budget--) { s->failed_pc=0x0c088d7cu; return 0; }
write(ram,r[14]+12,r[0],2);
goto P_0c088d7e;
P_0c088d7e: /* original 60c3, guest PC 0x0c088d7e */
if(!s->budget--) { s->failed_pc=0x0c088d7eu; return 0; }
r[0]=r[12];
goto P_0c088d80;
P_0c088d80: /* original 81e7, guest PC 0x0c088d80 */
if(!s->budget--) { s->failed_pc=0x0c088d80u; return 0; }
write(ram,r[14]+14,r[0],2);
goto P_0c088d82;
P_0c088d82: /* original 60f1, guest PC 0x0c088d82 */
if(!s->budget--) { s->failed_pc=0x0c088d82u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[0]=tmp;
goto P_0c088d84;
P_0c088d84: /* original 81e3, guest PC 0x0c088d84 */
if(!s->budget--) { s->failed_pc=0x0c088d84u; return 0; }
write(ram,r[14]+6,r[0],2);
goto P_0c088d86;
P_0c088d86: /* original 6043, guest PC 0x0c088d86 */
if(!s->budget--) { s->failed_pc=0x0c088d86u; return 0; }
r[0]=r[4];
goto P_0c088d88;
P_0c088d88: /* original 81e4, guest PC 0x0c088d88 */
if(!s->budget--) { s->failed_pc=0x0c088d88u; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c088d8a;
P_0c088d8a: /* original 7f04, guest PC 0x0c088d8a */
if(!s->budget--) { s->failed_pc=0x0c088d8au; return 0; }
r[15]+=0x00000004u;
goto P_0c088d8c;
P_0c088d8c: /* original 4f26, guest PC 0x0c088d8c */
if(!s->budget--) { s->failed_pc=0x0c088d8cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c088d8e;
P_0c088d8e: /* original fff9, guest PC 0x0c088d8e */
if(!s->budget--) { s->failed_pc=0x0c088d8eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088d90;
P_0c088d90: /* original 6cf6, guest PC 0x0c088d90 */
if(!s->budget--) { s->failed_pc=0x0c088d90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c088d92;
P_0c088d92: /* original 6df6, guest PC 0x0c088d92 */
if(!s->budget--) { s->failed_pc=0x0c088d92u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c088d94;
P_0c088d94: /* original 000b, guest PC 0x0c088d94 */
if(!s->budget--) { s->failed_pc=0x0c088d94u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c088d96: /* original 6ef6, guest PC 0x0c088d96 */
if(!s->budget--) { s->failed_pc=0x0c088d96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c088d98u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c088d98u; return 0; } return 1;
P_0c088dbc: /* original 2fe6, guest PC 0x0c088dbc */
if(!s->budget--) { s->failed_pc=0x0c088dbcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088dbe;
P_0c088dbe: /* original 2fd6, guest PC 0x0c088dbe */
if(!s->budget--) { s->failed_pc=0x0c088dbeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088dc0;
P_0c088dc0: /* original 6d43, guest PC 0x0c088dc0 */
if(!s->budget--) { s->failed_pc=0x0c088dc0u; return 0; }
r[13]=r[4];
goto P_0c088dc2;
P_0c088dc2: /* original 2fc6, guest PC 0x0c088dc2 */
if(!s->budget--) { s->failed_pc=0x0c088dc2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088dc4;
P_0c088dc4: /* original 2fb6, guest PC 0x0c088dc4 */
if(!s->budget--) { s->failed_pc=0x0c088dc4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088dc6;
P_0c088dc6: /* original 2fa6, guest PC 0x0c088dc6 */
if(!s->budget--) { s->failed_pc=0x0c088dc6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088dc8;
P_0c088dc8: /* original 2f96, guest PC 0x0c088dc8 */
if(!s->budget--) { s->failed_pc=0x0c088dc8u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088dca;
P_0c088dca: /* original 2f86, guest PC 0x0c088dca */
if(!s->budget--) { s->failed_pc=0x0c088dcau; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088dcc;
P_0c088dcc: /* original fffb, guest PC 0x0c088dcc */
if(!s->budget--) { s->failed_pc=0x0c088dccu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c088dce;
P_0c088dce: /* original ffeb, guest PC 0x0c088dce */
if(!s->budget--) { s->failed_pc=0x0c088dceu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c088dd0;
P_0c088dd0: /* original ffdb, guest PC 0x0c088dd0 */
if(!s->budget--) { s->failed_pc=0x0c088dd0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c088dd2;
P_0c088dd2: /* original ffcb, guest PC 0x0c088dd2 */
if(!s->budget--) { s->failed_pc=0x0c088dd2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c088dd4;
P_0c088dd4: /* original 4f22, guest PC 0x0c088dd4 */
if(!s->budget--) { s->failed_pc=0x0c088dd4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c088dd6;
P_0c088dd6: /* original 7ff0, guest PC 0x0c088dd6 */
if(!s->budget--) { s->failed_pc=0x0c088dd6u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c088dd8;
P_0c088dd8: /* original 1f43, guest PC 0x0c088dd8 */
if(!s->budget--) { s->failed_pc=0x0c088dd8u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c088dda;
P_0c088dda: /* original d33c, guest PC 0x0c088dda */
if(!s->budget--) { s->failed_pc=0x0c088ddau; return 0; }
r[3]=read(ram,0x0c088eccu,4);
goto P_0c088ddc;
P_0c088ddc: /* original 430b, guest PC 0x0c088ddc */
if(!s->budget--) { s->failed_pc=0x0c088ddcu; return 0; }
target=r[3];
r[16]=code_base|0x0c088de0u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088de0u) { target=s->pc; goto dispatch; }
goto P_0c088de0;
P_0c088dde: /* original e400, guest PC 0x0c088dde */
if(!s->budget--) { s->failed_pc=0x0c088ddeu; return 0; }
r[4]=0x00000000u;
goto P_0c088de0;
P_0c088de0: /* original 84d2, guest PC 0x0c088de0 */
if(!s->budget--) { s->failed_pc=0x0c088de0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+2,1);
goto P_0c088de2;
P_0c088de2: /* original e808, guest PC 0x0c088de2 */
if(!s->budget--) { s->failed_pc=0x0c088de2u; return 0; }
r[8]=0x00000008u;
goto P_0c088de4;
P_0c088de4: /* original 80f8, guest PC 0x0c088de4 */
if(!s->budget--) { s->failed_pc=0x0c088de4u; return 0; }
write(ram,r[15]+8,r[0],1);
goto P_0c088de6;
P_0c088de6: /* original 84f8, guest PC 0x0c088de6 */
if(!s->budget--) { s->failed_pc=0x0c088de6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+8,1);
goto P_0c088de8;
P_0c088de8: /* original de39, guest PC 0x0c088de8 */
if(!s->budget--) { s->failed_pc=0x0c088de8u; return 0; }
r[14]=read(ram,0x0c088ed0u,4);
goto P_0c088dea;
P_0c088dea: /* original 4008, guest PC 0x0c088dea */
if(!s->budget--) { s->failed_pc=0x0c088deau; return 0; }
r[0]<<=2;
goto P_0c088dec;
P_0c088dec: /* original 2f02, guest PC 0x0c088dec */
if(!s->budget--) { s->failed_pc=0x0c088decu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c088dee;
P_0c088dee: /* original da3a, guest PC 0x0c088dee */
if(!s->budget--) { s->failed_pc=0x0c088deeu; return 0; }
r[10]=read(ram,0x0c088ed8u,4);
goto P_0c088df0;
P_0c088df0: /* original db3a, guest PC 0x0c088df0 */
if(!s->budget--) { s->failed_pc=0x0c088df0u; return 0; }
r[11]=read(ram,0x0c088edcu,4);
goto P_0c088df2;
P_0c088df2: /* original dc3b, guest PC 0x0c088df2 */
if(!s->budget--) { s->failed_pc=0x0c088df2u; return 0; }
r[12]=read(ram,0x0c088ee0u,4);
goto P_0c088df4;
P_0c088df4: /* original d937, guest PC 0x0c088df4 */
if(!s->budget--) { s->failed_pc=0x0c088df4u; return 0; }
r[9]=read(ram,0x0c088ed4u,4);
goto P_0c088df6;
P_0c088df6: /* original ff9d, guest PC 0x0c088df6 */
if(!s->budget--) { s->failed_pc=0x0c088df6u; return 0; }
fr[15]=0x3f800000u;
goto P_0c088df8;
P_0c088df8: /* original e004, guest PC 0x0c088df8 */
if(!s->budget--) { s->failed_pc=0x0c088df8u; return 0; }
r[0]=0x00000004u;
goto P_0c088dfa;
P_0c088dfa: /* original 63f2, guest PC 0x0c088dfa */
if(!s->budget--) { s->failed_pc=0x0c088dfau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c088dfc;
P_0c088dfc: /* original f3e6, guest PC 0x0c088dfc */
if(!s->budget--) { s->failed_pc=0x0c088dfcu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c088dfe;
P_0c088dfe: /* original 50e4, guest PC 0x0c088dfe */
if(!s->budget--) { s->failed_pc=0x0c088dfeu; return 0; }
r[0]=read(ram,r[14]+16,4);
goto P_0c088e00;
P_0c088e00: /* original f3f2, guest PC 0x0c088e00 */
if(!s->budget--) { s->failed_pc=0x0c088e00u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c088e02;
P_0c088e02: /* original fee8, guest PC 0x0c088e02 */
if(!s->budget--) { s->failed_pc=0x0c088e02u; return 0; }
vf3_matrix_load(s,ram,14,r[14]);
goto P_0c088e04;
P_0c088e04: /* original fc3c, guest PC 0x0c088e04 */
if(!s->budget--) { s->failed_pc=0x0c088e04u; return 0; }
vf3_matrix_move(s,12,3);
goto P_0c088e06;
P_0c088e06: /* original fc4d, guest PC 0x0c088e06 */
if(!s->budget--) { s->failed_pc=0x0c088e06u; return 0; }
fr[12]^=0x80000000u;
goto P_0c088e08;
P_0c088e08: /* original 4a0b, guest PC 0x0c088e08 */
if(!s->budget--) { s->failed_pc=0x0c088e08u; return 0; }
target=r[10];
r[16]=code_base|0x0c088e0cu;
vf3_matrix_load(s,ram,13,r[3]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088e0cu) { target=s->pc; goto dispatch; }
goto P_0c088e0c;
P_0c088e0a: /* original fd36, guest PC 0x0c088e0a */
if(!s->budget--) { s->failed_pc=0x0c088e0au; return 0; }
vf3_matrix_load(s,ram,13,r[3]+r[0]);
goto P_0c088e0c;
P_0c088e0c: /* original f5dc, guest PC 0x0c088e0c */
if(!s->budget--) { s->failed_pc=0x0c088e0cu; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c088e0e;
P_0c088e0e: /* original f6cc, guest PC 0x0c088e0e */
if(!s->budget--) { s->failed_pc=0x0c088e0eu; return 0; }
vf3_matrix_move(s,6,12);
goto P_0c088e10;
P_0c088e10: /* original 4b0b, guest PC 0x0c088e10 */
if(!s->budget--) { s->failed_pc=0x0c088e10u; return 0; }
target=r[11];
r[16]=code_base|0x0c088e14u;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088e14u) { target=s->pc; goto dispatch; }
goto P_0c088e14;
P_0c088e12: /* original f4ec, guest PC 0x0c088e12 */
if(!s->budget--) { s->failed_pc=0x0c088e12u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c088e14;
P_0c088e14: /* original 53e3, guest PC 0x0c088e14 */
if(!s->budget--) { s->failed_pc=0x0c088e14u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c088e16;
P_0c088e16: /* original 2338, guest PC 0x0c088e16 */
if(!s->budget--) { s->failed_pc=0x0c088e16u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c088e18;
P_0c088e18: /* original 8b02, guest PC 0x0c088e18 */
if(!s->budget--) { s->failed_pc=0x0c088e18u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c088e20; }
goto P_0c088e1a;
P_0c088e1a: /* original 85d2, guest PC 0x0c088e1a */
if(!s->budget--) { s->failed_pc=0x0c088e1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+4,2);
goto P_0c088e1c;
P_0c088e1c: /* original a002, guest PC 0x0c088e1c */
if(!s->budget--) { s->failed_pc=0x0c088e1cu; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c088e24;
P_0c088e1e: /* original 81f2, guest PC 0x0c088e1e */
if(!s->budget--) { s->failed_pc=0x0c088e1eu; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c088e20;
P_0c088e20: /* original 85d3, guest PC 0x0c088e20 */
if(!s->budget--) { s->failed_pc=0x0c088e20u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+6,2);
goto P_0c088e22;
P_0c088e22: /* original 81f2, guest PC 0x0c088e22 */
if(!s->budget--) { s->failed_pc=0x0c088e22u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c088e24;
P_0c088e24: /* original 85f2, guest PC 0x0c088e24 */
if(!s->budget--) { s->failed_pc=0x0c088e24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c088e26;
P_0c088e26: /* original 490b, guest PC 0x0c088e26 */
if(!s->budget--) { s->failed_pc=0x0c088e26u; return 0; }
target=r[9];
r[16]=code_base|0x0c088e2au;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088e2au) { target=s->pc; goto dispatch; }
goto P_0c088e2a;
P_0c088e28: /* original 6403, guest PC 0x0c088e28 */
if(!s->budget--) { s->failed_pc=0x0c088e28u; return 0; }
r[4]=r[0];
goto P_0c088e2a;
P_0c088e2a: /* original 4c0b, guest PC 0x0c088e2a */
if(!s->budget--) { s->failed_pc=0x0c088e2au; return 0; }
target=r[12];
r[16]=code_base|0x0c088e2eu;
r[4]=read(ram,r[14]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088e2eu) { target=s->pc; goto dispatch; }
goto P_0c088e2e;
P_0c088e2c: /* original 54e2, guest PC 0x0c088e2c */
if(!s->budget--) { s->failed_pc=0x0c088e2cu; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c088e2e;
P_0c088e2e: /* original 4810, guest PC 0x0c088e2e */
if(!s->budget--) { s->failed_pc=0x0c088e2eu; return 0; }
--r[8];
r[17]=(r[17]&~1u)|((r[8]==0)!=0);
goto P_0c088e30;
P_0c088e30: /* original 8fe2, guest PC 0x0c088e30 */
if(!s->budget--) { s->failed_pc=0x0c088e30u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000014u;
if(!cond) { goto P_0c088df8; }
goto P_0c088e34;
P_0c088e32: /* original 7e14, guest PC 0x0c088e32 */
if(!s->budget--) { s->failed_pc=0x0c088e32u; return 0; }
r[14]+=0x00000014u;
goto P_0c088e34;
P_0c088e34: /* original de2b, guest PC 0x0c088e34 */
if(!s->budget--) { s->failed_pc=0x0c088e34u; return 0; }
r[14]=read(ram,0x0c088ee4u,4);
goto P_0c088e36;
P_0c088e36: /* original e802, guest PC 0x0c088e36 */
if(!s->budget--) { s->failed_pc=0x0c088e36u; return 0; }
r[8]=0x00000002u;
goto P_0c088e38;
P_0c088e38: /* original e004, guest PC 0x0c088e38 */
if(!s->budget--) { s->failed_pc=0x0c088e38u; return 0; }
r[0]=0x00000004u;
goto P_0c088e3a;
P_0c088e3a: /* original 63f2, guest PC 0x0c088e3a */
if(!s->budget--) { s->failed_pc=0x0c088e3au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c088e3c;
P_0c088e3c: /* original f3e6, guest PC 0x0c088e3c */
if(!s->budget--) { s->failed_pc=0x0c088e3cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c088e3e;
P_0c088e3e: /* original 50e4, guest PC 0x0c088e3e */
if(!s->budget--) { s->failed_pc=0x0c088e3eu; return 0; }
r[0]=read(ram,r[14]+16,4);
goto P_0c088e40;
P_0c088e40: /* original f3f2, guest PC 0x0c088e40 */
if(!s->budget--) { s->failed_pc=0x0c088e40u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c088e42;
P_0c088e42: /* original fee8, guest PC 0x0c088e42 */
if(!s->budget--) { s->failed_pc=0x0c088e42u; return 0; }
vf3_matrix_load(s,ram,14,r[14]);
goto P_0c088e44;
P_0c088e44: /* original fc3c, guest PC 0x0c088e44 */
if(!s->budget--) { s->failed_pc=0x0c088e44u; return 0; }
vf3_matrix_move(s,12,3);
goto P_0c088e46;
P_0c088e46: /* original fc4d, guest PC 0x0c088e46 */
if(!s->budget--) { s->failed_pc=0x0c088e46u; return 0; }
fr[12]^=0x80000000u;
goto P_0c088e48;
P_0c088e48: /* original 4a0b, guest PC 0x0c088e48 */
if(!s->budget--) { s->failed_pc=0x0c088e48u; return 0; }
target=r[10];
r[16]=code_base|0x0c088e4cu;
vf3_matrix_load(s,ram,13,r[3]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088e4cu) { target=s->pc; goto dispatch; }
goto P_0c088e4c;
P_0c088e4a: /* original fd36, guest PC 0x0c088e4a */
if(!s->budget--) { s->failed_pc=0x0c088e4au; return 0; }
vf3_matrix_load(s,ram,13,r[3]+r[0]);
goto P_0c088e4c;
P_0c088e4c: /* original f5dc, guest PC 0x0c088e4c */
if(!s->budget--) { s->failed_pc=0x0c088e4cu; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c088e4e;
P_0c088e4e: /* original f6cc, guest PC 0x0c088e4e */
if(!s->budget--) { s->failed_pc=0x0c088e4eu; return 0; }
vf3_matrix_move(s,6,12);
goto P_0c088e50;
P_0c088e50: /* original 4b0b, guest PC 0x0c088e50 */
if(!s->budget--) { s->failed_pc=0x0c088e50u; return 0; }
target=r[11];
r[16]=code_base|0x0c088e54u;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088e54u) { target=s->pc; goto dispatch; }
goto P_0c088e54;
P_0c088e52: /* original f4ec, guest PC 0x0c088e52 */
if(!s->budget--) { s->failed_pc=0x0c088e52u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c088e54;
P_0c088e54: /* original 53e3, guest PC 0x0c088e54 */
if(!s->budget--) { s->failed_pc=0x0c088e54u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c088e56;
P_0c088e56: /* original 2338, guest PC 0x0c088e56 */
if(!s->budget--) { s->failed_pc=0x0c088e56u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c088e58;
P_0c088e58: /* original 8b02, guest PC 0x0c088e58 */
if(!s->budget--) { s->failed_pc=0x0c088e58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c088e60; }
goto P_0c088e5a;
P_0c088e5a: /* original 85d2, guest PC 0x0c088e5a */
if(!s->budget--) { s->failed_pc=0x0c088e5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+4,2);
goto P_0c088e5c;
P_0c088e5c: /* original a002, guest PC 0x0c088e5c */
if(!s->budget--) { s->failed_pc=0x0c088e5cu; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c088e64;
P_0c088e5e: /* original 81f2, guest PC 0x0c088e5e */
if(!s->budget--) { s->failed_pc=0x0c088e5eu; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c088e60;
P_0c088e60: /* original 85d3, guest PC 0x0c088e60 */
if(!s->budget--) { s->failed_pc=0x0c088e60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+6,2);
goto P_0c088e62;
P_0c088e62: /* original 81f2, guest PC 0x0c088e62 */
if(!s->budget--) { s->failed_pc=0x0c088e62u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c088e64;
P_0c088e64: /* original 85f2, guest PC 0x0c088e64 */
if(!s->budget--) { s->failed_pc=0x0c088e64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c088e66;
P_0c088e66: /* original 490b, guest PC 0x0c088e66 */
if(!s->budget--) { s->failed_pc=0x0c088e66u; return 0; }
target=r[9];
r[16]=code_base|0x0c088e6au;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088e6au) { target=s->pc; goto dispatch; }
goto P_0c088e6a;
P_0c088e68: /* original 6403, guest PC 0x0c088e68 */
if(!s->budget--) { s->failed_pc=0x0c088e68u; return 0; }
r[4]=r[0];
goto P_0c088e6a;
P_0c088e6a: /* original 4c0b, guest PC 0x0c088e6a */
if(!s->budget--) { s->failed_pc=0x0c088e6au; return 0; }
target=r[12];
r[16]=code_base|0x0c088e6eu;
r[4]=read(ram,r[14]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088e6eu) { target=s->pc; goto dispatch; }
goto P_0c088e6e;
P_0c088e6c: /* original 54e2, guest PC 0x0c088e6c */
if(!s->budget--) { s->failed_pc=0x0c088e6cu; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c088e6e;
P_0c088e6e: /* original 4810, guest PC 0x0c088e6e */
if(!s->budget--) { s->failed_pc=0x0c088e6eu; return 0; }
--r[8];
r[17]=(r[17]&~1u)|((r[8]==0)!=0);
goto P_0c088e70;
P_0c088e70: /* original 8fe2, guest PC 0x0c088e70 */
if(!s->budget--) { s->failed_pc=0x0c088e70u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000014u;
if(!cond) { goto P_0c088e38; }
goto P_0c088e74;
P_0c088e72: /* original 7e14, guest PC 0x0c088e72 */
if(!s->budget--) { s->failed_pc=0x0c088e72u; return 0; }
r[14]+=0x00000014u;
goto P_0c088e74;
P_0c088e74: /* original 84f8, guest PC 0x0c088e74 */
if(!s->budget--) { s->failed_pc=0x0c088e74u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+8,1);
goto P_0c088e76;
P_0c088e76: /* original 9428, guest PC 0x0c088e76 */
if(!s->budget--) { s->failed_pc=0x0c088e76u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c088ecau,2);
goto P_0c088e78;
P_0c088e78: /* original d31b, guest PC 0x0c088e78 */
if(!s->budget--) { s->failed_pc=0x0c088e78u; return 0; }
r[3]=read(ram,0x0c088ee8u,4);
goto P_0c088e7a;
P_0c088e7a: /* original 6903, guest PC 0x0c088e7a */
if(!s->budget--) { s->failed_pc=0x0c088e7au; return 0; }
r[9]=r[0];
goto P_0c088e7c;
P_0c088e7c: /* original 430b, guest PC 0x0c088e7c */
if(!s->budget--) { s->failed_pc=0x0c088e7cu; return 0; }
target=r[3];
r[16]=code_base|0x0c088e80u;
r[4]+=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088e80u) { target=s->pc; goto dispatch; }
goto P_0c088e80;
P_0c088e7e: /* original 349c, guest PC 0x0c088e7e */
if(!s->budget--) { s->failed_pc=0x0c088e7eu; return 0; }
r[4]+=r[9];
goto P_0c088e80;
P_0c088e80: /* original 5ef3, guest PC 0x0c088e80 */
if(!s->budget--) { s->failed_pc=0x0c088e80u; return 0; }
r[14]=read(ram,r[15]+12,4);
goto P_0c088e82;
P_0c088e82: /* original ed1f, guest PC 0x0c088e82 */
if(!s->budget--) { s->failed_pc=0x0c088e82u; return 0; }
r[13]=0x0000001fu;
goto P_0c088e84;
P_0c088e84: /* original fd8d, guest PC 0x0c088e84 */
if(!s->budget--) { s->failed_pc=0x0c088e84u; return 0; }
fr[13]=0;
goto P_0c088e86;
P_0c088e86: /* original 7e10, guest PC 0x0c088e86 */
if(!s->budget--) { s->failed_pc=0x0c088e86u; return 0; }
r[14]+=0x00000010u;
goto P_0c088e88;
P_0c088e88: /* original e004, guest PC 0x0c088e88 */
if(!s->budget--) { s->failed_pc=0x0c088e88u; return 0; }
r[0]=0x00000004u;
goto P_0c088e8a;
P_0c088e8a: /* original fce8, guest PC 0x0c088e8a */
if(!s->budget--) { s->failed_pc=0x0c088e8au; return 0; }
vf3_matrix_load(s,ram,12,r[14]);
goto P_0c088e8c;
P_0c088e8c: /* original f3e6, guest PC 0x0c088e8c */
if(!s->budget--) { s->failed_pc=0x0c088e8cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c088e8e;
P_0c088e8e: /* original f3f2, guest PC 0x0c088e8e */
if(!s->budget--) { s->failed_pc=0x0c088e8eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c088e90;
P_0c088e90: /* original fe3c, guest PC 0x0c088e90 */
if(!s->budget--) { s->failed_pc=0x0c088e90u; return 0; }
vf3_matrix_move(s,14,3);
goto P_0c088e92;
P_0c088e92: /* original 4a0b, guest PC 0x0c088e92 */
if(!s->budget--) { s->failed_pc=0x0c088e92u; return 0; }
target=r[10];
r[16]=code_base|0x0c088e96u;
fr[14]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088e96u) { target=s->pc; goto dispatch; }
goto P_0c088e96;
P_0c088e94: /* original fe4d, guest PC 0x0c088e94 */
if(!s->budget--) { s->failed_pc=0x0c088e94u; return 0; }
fr[14]^=0x80000000u;
goto P_0c088e96;
P_0c088e96: /* original f5dc, guest PC 0x0c088e96 */
if(!s->budget--) { s->failed_pc=0x0c088e96u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c088e98;
P_0c088e98: /* original f6ec, guest PC 0x0c088e98 */
if(!s->budget--) { s->failed_pc=0x0c088e98u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c088e9a;
P_0c088e9a: /* original 4b0b, guest PC 0x0c088e9a */
if(!s->budget--) { s->failed_pc=0x0c088e9au; return 0; }
target=r[11];
r[16]=code_base|0x0c088e9eu;
vf3_matrix_move(s,4,12);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088e9eu) { target=s->pc; goto dispatch; }
goto P_0c088e9e;
P_0c088e9c: /* original f4cc, guest PC 0x0c088e9c */
if(!s->budget--) { s->failed_pc=0x0c088e9cu; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c088e9e;
P_0c088e9e: /* original 54e2, guest PC 0x0c088e9e */
if(!s->budget--) { s->failed_pc=0x0c088e9eu; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c088ea0;
P_0c088ea0: /* original 4c0b, guest PC 0x0c088ea0 */
if(!s->budget--) { s->failed_pc=0x0c088ea0u; return 0; }
target=r[12];
r[16]=code_base|0x0c088ea4u;
r[4]+=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088ea4u) { target=s->pc; goto dispatch; }
goto P_0c088ea4;
P_0c088ea2: /* original 349c, guest PC 0x0c088ea2 */
if(!s->budget--) { s->failed_pc=0x0c088ea2u; return 0; }
r[4]+=r[9];
goto P_0c088ea4;
P_0c088ea4: /* original 4d10, guest PC 0x0c088ea4 */
if(!s->budget--) { s->failed_pc=0x0c088ea4u; return 0; }
--r[13];
r[17]=(r[17]&~1u)|((r[13]==0)!=0);
goto P_0c088ea6;
P_0c088ea6: /* original 8fef, guest PC 0x0c088ea6 */
if(!s->budget--) { s->failed_pc=0x0c088ea6u; return 0; }
cond=r[17]&1u;
r[14]+=0x0000000cu;
if(!cond) { goto P_0c088e88; }
goto P_0c088eaa;
P_0c088ea8: /* original 7e0c, guest PC 0x0c088ea8 */
if(!s->budget--) { s->failed_pc=0x0c088ea8u; return 0; }
r[14]+=0x0000000cu;
goto P_0c088eaa;
P_0c088eaa: /* original 7f10, guest PC 0x0c088eaa */
if(!s->budget--) { s->failed_pc=0x0c088eaau; return 0; }
r[15]+=0x00000010u;
goto P_0c088eac;
P_0c088eac: /* original d20f, guest PC 0x0c088eac */
if(!s->budget--) { s->failed_pc=0x0c088eacu; return 0; }
r[2]=read(ram,0x0c088eecu,4);
goto P_0c088eae;
P_0c088eae: /* original 4f26, guest PC 0x0c088eae */
if(!s->budget--) { s->failed_pc=0x0c088eaeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c088eb0;
P_0c088eb0: /* original e401, guest PC 0x0c088eb0 */
if(!s->budget--) { s->failed_pc=0x0c088eb0u; return 0; }
r[4]=0x00000001u;
goto P_0c088eb2;
P_0c088eb2: /* original fcf9, guest PC 0x0c088eb2 */
if(!s->budget--) { s->failed_pc=0x0c088eb2u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088eb4;
P_0c088eb4: /* original fdf9, guest PC 0x0c088eb4 */
if(!s->budget--) { s->failed_pc=0x0c088eb4u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088eb6;
P_0c088eb6: /* original fef9, guest PC 0x0c088eb6 */
if(!s->budget--) { s->failed_pc=0x0c088eb6u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088eb8;
P_0c088eb8: /* original fff9, guest PC 0x0c088eb8 */
if(!s->budget--) { s->failed_pc=0x0c088eb8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088eba;
P_0c088eba: /* original 68f6, guest PC 0x0c088eba */
if(!s->budget--) { s->failed_pc=0x0c088ebau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c088ebc;
P_0c088ebc: /* original 69f6, guest PC 0x0c088ebc */
if(!s->budget--) { s->failed_pc=0x0c088ebcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c088ebe;
P_0c088ebe: /* original 6af6, guest PC 0x0c088ebe */
if(!s->budget--) { s->failed_pc=0x0c088ebeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c088ec0;
P_0c088ec0: /* original 6bf6, guest PC 0x0c088ec0 */
if(!s->budget--) { s->failed_pc=0x0c088ec0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c088ec2;
P_0c088ec2: /* original 6cf6, guest PC 0x0c088ec2 */
if(!s->budget--) { s->failed_pc=0x0c088ec2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c088ec4;
P_0c088ec4: /* original 6df6, guest PC 0x0c088ec4 */
if(!s->budget--) { s->failed_pc=0x0c088ec4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c088ec6;
P_0c088ec6: /* original 422b, guest PC 0x0c088ec6 */
if(!s->budget--) { s->failed_pc=0x0c088ec6u; return 0; }
target=r[2];
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
P_0c088ec8: /* original 6ef6, guest PC 0x0c088ec8 */
if(!s->budget--) { s->failed_pc=0x0c088ec8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c088ecau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c088ecau; return 0; } return 1;
P_0c088ef0: /* original 2fe6, guest PC 0x0c088ef0 */
if(!s->budget--) { s->failed_pc=0x0c088ef0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088ef2;
P_0c088ef2: /* original 2fd6, guest PC 0x0c088ef2 */
if(!s->budget--) { s->failed_pc=0x0c088ef2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088ef4;
P_0c088ef4: /* original 6d43, guest PC 0x0c088ef4 */
if(!s->budget--) { s->failed_pc=0x0c088ef4u; return 0; }
r[13]=r[4];
goto P_0c088ef6;
P_0c088ef6: /* original fffb, guest PC 0x0c088ef6 */
if(!s->budget--) { s->failed_pc=0x0c088ef6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c088ef8;
P_0c088ef8: /* original 4f22, guest PC 0x0c088ef8 */
if(!s->budget--) { s->failed_pc=0x0c088ef8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c088efa;
P_0c088efa: /* original 60d2, guest PC 0x0c088efa */
if(!s->budget--) { s->failed_pc=0x0c088efau; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c088efc;
P_0c088efc: /* original 88ff, guest PC 0x0c088efc */
if(!s->budget--) { s->failed_pc=0x0c088efcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c088efe;
P_0c088efe: /* original 7ffc, guest PC 0x0c088efe */
if(!s->budget--) { s->failed_pc=0x0c088efeu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c088f00;
P_0c088f00: /* original 8d60, guest PC 0x0c088f00 */
if(!s->budget--) { s->failed_pc=0x0c088f00u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c088fc4; }
goto P_0c088f04;
P_0c088f02: /* original 6403, guest PC 0x0c088f02 */
if(!s->budget--) { s->failed_pc=0x0c088f02u; return 0; }
r[4]=r[0];
goto P_0c088f04;
P_0c088f04: /* original c732, guest PC 0x0c088f04 */
if(!s->budget--) { s->failed_pc=0x0c088f04u; return 0; }
r[0]=code_base|0x00088fd0u;
goto P_0c088f06;
P_0c088f06: /* original 6e43, guest PC 0x0c088f06 */
if(!s->budget--) { s->failed_pc=0x0c088f06u; return 0; }
r[14]=r[4];
goto P_0c088f08;
P_0c088f08: /* original ff08, guest PC 0x0c088f08 */
if(!s->budget--) { s->failed_pc=0x0c088f08u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c088f0a;
P_0c088f0a: /* original c732, guest PC 0x0c088f0a */
if(!s->budget--) { s->failed_pc=0x0c088f0au; return 0; }
r[0]=code_base|0x00088fd4u;
goto P_0c088f0c;
P_0c088f0c: /* original f308, guest PC 0x0c088f0c */
if(!s->budget--) { s->failed_pc=0x0c088f0cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c088f0e;
P_0c088f0e: /* original ff3a, guest PC 0x0c088f0e */
if(!s->budget--) { s->failed_pc=0x0c088f0eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c088f10;
P_0c088f10: /* original e024, guest PC 0x0c088f10 */
if(!s->budget--) { s->failed_pc=0x0c088f10u; return 0; }
r[0]=0x00000024u;
goto P_0c088f12;
P_0c088f12: /* original 04ed, guest PC 0x0c088f12 */
if(!s->budget--) { s->failed_pc=0x0c088f12u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c088f14;
P_0c088f14: /* original 74ff, guest PC 0x0c088f14 */
if(!s->budget--) { s->failed_pc=0x0c088f14u; return 0; }
r[4]+=0xffffffffu;
goto P_0c088f16;
P_0c088f16: /* original 4415, guest PC 0x0c088f16 */
if(!s->budget--) { s->failed_pc=0x0c088f16u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c088f18;
P_0c088f18: /* original 8905, guest PC 0x0c088f18 */
if(!s->budget--) { s->failed_pc=0x0c088f18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088f26; }
goto P_0c088f1a;
P_0c088f1a: /* original d22f, guest PC 0x0c088f1a */
if(!s->budget--) { s->failed_pc=0x0c088f1au; return 0; }
r[2]=read(ram,0x0c088fd8u,4);
goto P_0c088f1c;
P_0c088f1c: /* original 65e3, guest PC 0x0c088f1c */
if(!s->budget--) { s->failed_pc=0x0c088f1cu; return 0; }
r[5]=r[14];
goto P_0c088f1e;
P_0c088f1e: /* original 420b, guest PC 0x0c088f1e */
if(!s->budget--) { s->failed_pc=0x0c088f1eu; return 0; }
target=r[2];
r[16]=code_base|0x0c088f22u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088f22u) { target=s->pc; goto dispatch; }
goto P_0c088f22;
P_0c088f20: /* original 64d3, guest PC 0x0c088f20 */
if(!s->budget--) { s->failed_pc=0x0c088f20u; return 0; }
r[4]=r[13];
goto P_0c088f22;
P_0c088f22: /* original a049, guest PC 0x0c088f22 */
if(!s->budget--) { s->failed_pc=0x0c088f22u; return 0; }
r[14]=r[0];
goto P_0c088fb8;
P_0c088f24: /* original 6e03, guest PC 0x0c088f24 */
if(!s->budget--) { s->failed_pc=0x0c088f24u; return 0; }
r[14]=r[0];
goto P_0c088f26;
P_0c088f26: /* original 0e45, guest PC 0x0c088f26 */
if(!s->budget--) { s->failed_pc=0x0c088f26u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c088f28;
P_0c088f28: /* original e026, guest PC 0x0c088f28 */
if(!s->budget--) { s->failed_pc=0x0c088f28u; return 0; }
r[0]=0x00000026u;
goto P_0c088f2a;
P_0c088f2a: /* original 00ec, guest PC 0x0c088f2a */
if(!s->budget--) { s->failed_pc=0x0c088f2au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c088f2c;
P_0c088f2c: /* original c880, guest PC 0x0c088f2c */
if(!s->budget--) { s->failed_pc=0x0c088f2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c088f2e;
P_0c088f2e: /* original 8912, guest PC 0x0c088f2e */
if(!s->budget--) { s->failed_pc=0x0c088f2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088f56; }
goto P_0c088f30;
P_0c088f30: /* original d32a, guest PC 0x0c088f30 */
if(!s->budget--) { s->failed_pc=0x0c088f30u; return 0; }
r[3]=read(ram,0x0c088fdcu,4);
goto P_0c088f32;
P_0c088f32: /* original 55da, guest PC 0x0c088f32 */
if(!s->budget--) { s->failed_pc=0x0c088f32u; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c088f34;
P_0c088f34: /* original 430b, guest PC 0x0c088f34 */
if(!s->budget--) { s->failed_pc=0x0c088f34u; return 0; }
target=r[3];
r[16]=code_base|0x0c088f38u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088f38u) { target=s->pc; goto dispatch; }
goto P_0c088f38;
P_0c088f36: /* original 64e3, guest PC 0x0c088f36 */
if(!s->budget--) { s->failed_pc=0x0c088f36u; return 0; }
r[4]=r[14];
goto P_0c088f38;
P_0c088f38: /* original e118, guest PC 0x0c088f38 */
if(!s->budget--) { s->failed_pc=0x0c088f38u; return 0; }
r[1]=0x00000018u;
goto P_0c088f3a;
P_0c088f3a: /* original 31ec, guest PC 0x0c088f3a */
if(!s->budget--) { s->failed_pc=0x0c088f3au; return 0; }
r[1]+=r[14];
goto P_0c088f3c;
P_0c088f3c: /* original e00c, guest PC 0x0c088f3c */
if(!s->budget--) { s->failed_pc=0x0c088f3cu; return 0; }
r[0]=0x0000000cu;
goto P_0c088f3e;
P_0c088f3e: /* original f318, guest PC 0x0c088f3e */
if(!s->budget--) { s->failed_pc=0x0c088f3eu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c088f40;
P_0c088f40: /* original f2e6, guest PC 0x0c088f40 */
if(!s->budget--) { s->failed_pc=0x0c088f40u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c088f42;
P_0c088f42: /* original e120, guest PC 0x0c088f42 */
if(!s->budget--) { s->failed_pc=0x0c088f42u; return 0; }
r[1]=0x00000020u;
goto P_0c088f44;
P_0c088f44: /* original 31ec, guest PC 0x0c088f44 */
if(!s->budget--) { s->failed_pc=0x0c088f44u; return 0; }
r[1]+=r[14];
goto P_0c088f46;
P_0c088f46: /* original f230, guest PC 0x0c088f46 */
if(!s->budget--) { s->failed_pc=0x0c088f46u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c088f48;
P_0c088f48: /* original fe27, guest PC 0x0c088f48 */
if(!s->budget--) { s->failed_pc=0x0c088f48u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c088f4a;
P_0c088f4a: /* original e014, guest PC 0x0c088f4a */
if(!s->budget--) { s->failed_pc=0x0c088f4au; return 0; }
r[0]=0x00000014u;
goto P_0c088f4c;
P_0c088f4c: /* original f2e6, guest PC 0x0c088f4c */
if(!s->budget--) { s->failed_pc=0x0c088f4cu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c088f4e;
P_0c088f4e: /* original f318, guest PC 0x0c088f4e */
if(!s->budget--) { s->failed_pc=0x0c088f4eu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c088f50;
P_0c088f50: /* original f230, guest PC 0x0c088f50 */
if(!s->budget--) { s->failed_pc=0x0c088f50u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c088f52;
P_0c088f52: /* original a031, guest PC 0x0c088f52 */
if(!s->budget--) { s->failed_pc=0x0c088f52u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c088fb8;
P_0c088f54: /* original fe27, guest PC 0x0c088f54 */
if(!s->budget--) { s->failed_pc=0x0c088f54u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c088f56;
P_0c088f56: /* original d221, guest PC 0x0c088f56 */
if(!s->budget--) { s->failed_pc=0x0c088f56u; return 0; }
r[2]=read(ram,0x0c088fdcu,4);
goto P_0c088f58;
P_0c088f58: /* original 55d9, guest PC 0x0c088f58 */
if(!s->budget--) { s->failed_pc=0x0c088f58u; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c088f5a;
P_0c088f5a: /* original 420b, guest PC 0x0c088f5a */
if(!s->budget--) { s->failed_pc=0x0c088f5au; return 0; }
target=r[2];
r[16]=code_base|0x0c088f5eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088f5eu) { target=s->pc; goto dispatch; }
goto P_0c088f5e;
P_0c088f5c: /* original 64e3, guest PC 0x0c088f5c */
if(!s->budget--) { s->failed_pc=0x0c088f5cu; return 0; }
r[4]=r[14];
goto P_0c088f5e;
P_0c088f5e: /* original e020, guest PC 0x0c088f5e */
if(!s->budget--) { s->failed_pc=0x0c088f5eu; return 0; }
r[0]=0x00000020u;
goto P_0c088f60;
P_0c088f60: /* original f38d, guest PC 0x0c088f60 */
if(!s->budget--) { s->failed_pc=0x0c088f60u; return 0; }
fr[3]=0;
goto P_0c088f62;
P_0c088f62: /* original f5d6, guest PC 0x0c088f62 */
if(!s->budget--) { s->failed_pc=0x0c088f62u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c088f64;
P_0c088f64: /* original e00c, guest PC 0x0c088f64 */
if(!s->budget--) { s->failed_pc=0x0c088f64u; return 0; }
r[0]=0x0000000cu;
goto P_0c088f66;
P_0c088f66: /* original f6e6, guest PC 0x0c088f66 */
if(!s->budget--) { s->failed_pc=0x0c088f66u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c088f68;
P_0c088f68: /* original e018, guest PC 0x0c088f68 */
if(!s->budget--) { s->failed_pc=0x0c088f68u; return 0; }
r[0]=0x00000018u;
goto P_0c088f6a;
P_0c088f6a: /* original f4e6, guest PC 0x0c088f6a */
if(!s->budget--) { s->failed_pc=0x0c088f6au; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c088f6c;
P_0c088f6c: /* original f345, guest PC 0x0c088f6c */
if(!s->budget--) { s->failed_pc=0x0c088f6cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c088f6e;
P_0c088f6e: /* original 8d01, guest PC 0x0c088f6e */
if(!s->budget--) { s->failed_pc=0x0c088f6eu; return 0; }
cond=r[17]&1u;
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'+');
if(cond) { goto P_0c088f74; }
goto P_0c088f72;
P_0c088f70: /* original f640, guest PC 0x0c088f70 */
if(!s->budget--) { s->failed_pc=0x0c088f70u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'+');
goto P_0c088f72;
P_0c088f72: /* original f54d, guest PC 0x0c088f72 */
if(!s->budget--) { s->failed_pc=0x0c088f72u; return 0; }
fr[5]^=0x80000000u;
goto P_0c088f74;
P_0c088f74: /* original f450, guest PC 0x0c088f74 */
if(!s->budget--) { s->failed_pc=0x0c088f74u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c088f76;
P_0c088f76: /* original e00c, guest PC 0x0c088f76 */
if(!s->budget--) { s->failed_pc=0x0c088f76u; return 0; }
r[0]=0x0000000cu;
goto P_0c088f78;
P_0c088f78: /* original fe67, guest PC 0x0c088f78 */
if(!s->budget--) { s->failed_pc=0x0c088f78u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c088f7a;
P_0c088f7a: /* original e018, guest PC 0x0c088f7a */
if(!s->budget--) { s->failed_pc=0x0c088f7au; return 0; }
r[0]=0x00000018u;
goto P_0c088f7c;
P_0c088f7c: /* original fe47, guest PC 0x0c088f7c */
if(!s->budget--) { s->failed_pc=0x0c088f7cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c088f7e;
P_0c088f7e: /* original e020, guest PC 0x0c088f7e */
if(!s->budget--) { s->failed_pc=0x0c088f7eu; return 0; }
r[0]=0x00000020u;
goto P_0c088f80;
P_0c088f80: /* original f5d6, guest PC 0x0c088f80 */
if(!s->budget--) { s->failed_pc=0x0c088f80u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c088f82;
P_0c088f82: /* original e014, guest PC 0x0c088f82 */
if(!s->budget--) { s->failed_pc=0x0c088f82u; return 0; }
r[0]=0x00000014u;
goto P_0c088f84;
P_0c088f84: /* original f6e6, guest PC 0x0c088f84 */
if(!s->budget--) { s->failed_pc=0x0c088f84u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c088f86;
P_0c088f86: /* original e020, guest PC 0x0c088f86 */
if(!s->budget--) { s->failed_pc=0x0c088f86u; return 0; }
r[0]=0x00000020u;
goto P_0c088f88;
P_0c088f88: /* original f4e6, guest PC 0x0c088f88 */
if(!s->budget--) { s->failed_pc=0x0c088f88u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c088f8a;
P_0c088f8a: /* original f38d, guest PC 0x0c088f8a */
if(!s->budget--) { s->failed_pc=0x0c088f8au; return 0; }
fr[3]=0;
goto P_0c088f8c;
P_0c088f8c: /* original f345, guest PC 0x0c088f8c */
if(!s->budget--) { s->failed_pc=0x0c088f8cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c088f8e;
P_0c088f8e: /* original 8d01, guest PC 0x0c088f8e */
if(!s->budget--) { s->failed_pc=0x0c088f8eu; return 0; }
cond=r[17]&1u;
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'+');
if(cond) { goto P_0c088f94; }
goto P_0c088f92;
P_0c088f90: /* original f640, guest PC 0x0c088f90 */
if(!s->budget--) { s->failed_pc=0x0c088f90u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'+');
goto P_0c088f92;
P_0c088f92: /* original f54d, guest PC 0x0c088f92 */
if(!s->budget--) { s->failed_pc=0x0c088f92u; return 0; }
fr[5]^=0x80000000u;
goto P_0c088f94;
P_0c088f94: /* original f450, guest PC 0x0c088f94 */
if(!s->budget--) { s->failed_pc=0x0c088f94u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c088f96;
P_0c088f96: /* original e014, guest PC 0x0c088f96 */
if(!s->budget--) { s->failed_pc=0x0c088f96u; return 0; }
r[0]=0x00000014u;
goto P_0c088f98;
P_0c088f98: /* original fe67, guest PC 0x0c088f98 */
if(!s->budget--) { s->failed_pc=0x0c088f98u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c088f9a;
P_0c088f9a: /* original e020, guest PC 0x0c088f9a */
if(!s->budget--) { s->failed_pc=0x0c088f9au; return 0; }
r[0]=0x00000020u;
goto P_0c088f9c;
P_0c088f9c: /* original fe47, guest PC 0x0c088f9c */
if(!s->budget--) { s->failed_pc=0x0c088f9cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c088f9e;
P_0c088f9e: /* original e01c, guest PC 0x0c088f9e */
if(!s->budget--) { s->failed_pc=0x0c088f9eu; return 0; }
r[0]=0x0000001cu;
goto P_0c088fa0;
P_0c088fa0: /* original f4e6, guest PC 0x0c088fa0 */
if(!s->budget--) { s->failed_pc=0x0c088fa0u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c088fa2;
P_0c088fa2: /* original e010, guest PC 0x0c088fa2 */
if(!s->budget--) { s->failed_pc=0x0c088fa2u; return 0; }
r[0]=0x00000010u;
goto P_0c088fa4;
P_0c088fa4: /* original f5e6, guest PC 0x0c088fa4 */
if(!s->budget--) { s->failed_pc=0x0c088fa4u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c088fa6;
P_0c088fa6: /* original f540, guest PC 0x0c088fa6 */
if(!s->budget--) { s->failed_pc=0x0c088fa6u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'+');
goto P_0c088fa8;
P_0c088fa8: /* original f4f0, guest PC 0x0c088fa8 */
if(!s->budget--) { s->failed_pc=0x0c088fa8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'+');
goto P_0c088faa;
P_0c088faa: /* original fe57, guest PC 0x0c088faa */
if(!s->budget--) { s->failed_pc=0x0c088faau; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c088fac;
P_0c088fac: /* original f3f8, guest PC 0x0c088fac */
if(!s->budget--) { s->failed_pc=0x0c088facu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c088fae;
P_0c088fae: /* original f435, guest PC 0x0c088fae */
if(!s->budget--) { s->failed_pc=0x0c088faeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c088fb0;
P_0c088fb0: /* original 8d01, guest PC 0x0c088fb0 */
if(!s->budget--) { s->failed_pc=0x0c088fb0u; return 0; }
cond=r[17]&1u;
r[0]=0x0000001cu;
if(cond) { goto P_0c088fb6; }
goto P_0c088fb4;
P_0c088fb2: /* original e01c, guest PC 0x0c088fb2 */
if(!s->budget--) { s->failed_pc=0x0c088fb2u; return 0; }
r[0]=0x0000001cu;
goto P_0c088fb4;
P_0c088fb4: /* original f4f1, guest PC 0x0c088fb4 */
if(!s->budget--) { s->failed_pc=0x0c088fb4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
goto P_0c088fb6;
P_0c088fb6: /* original fe47, guest PC 0x0c088fb6 */
if(!s->budget--) { s->failed_pc=0x0c088fb6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c088fb8;
P_0c088fb8: /* original 60e2, guest PC 0x0c088fb8 */
if(!s->budget--) { s->failed_pc=0x0c088fb8u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c088fba;
P_0c088fba: /* original 88ff, guest PC 0x0c088fba */
if(!s->budget--) { s->failed_pc=0x0c088fbau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c088fbc;
P_0c088fbc: /* original 8d02, guest PC 0x0c088fbc */
if(!s->budget--) { s->failed_pc=0x0c088fbcu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c088fc4; }
goto P_0c088fc0;
P_0c088fbe: /* original 6403, guest PC 0x0c088fbe */
if(!s->budget--) { s->failed_pc=0x0c088fbeu; return 0; }
r[4]=r[0];
goto P_0c088fc0;
P_0c088fc0: /* original afa6, guest PC 0x0c088fc0 */
if(!s->budget--) { s->failed_pc=0x0c088fc0u; return 0; }
r[14]=r[4];
goto P_0c088f10;
P_0c088fc2: /* original 6e43, guest PC 0x0c088fc2 */
if(!s->budget--) { s->failed_pc=0x0c088fc2u; return 0; }
r[14]=r[4];
goto P_0c088fc4;
P_0c088fc4: /* original 7f04, guest PC 0x0c088fc4 */
if(!s->budget--) { s->failed_pc=0x0c088fc4u; return 0; }
r[15]+=0x00000004u;
goto P_0c088fc6;
P_0c088fc6: /* original 4f26, guest PC 0x0c088fc6 */
if(!s->budget--) { s->failed_pc=0x0c088fc6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c088fc8;
P_0c088fc8: /* original fff9, guest PC 0x0c088fc8 */
if(!s->budget--) { s->failed_pc=0x0c088fc8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088fca;
P_0c088fca: /* original 6df6, guest PC 0x0c088fca */
if(!s->budget--) { s->failed_pc=0x0c088fcau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c088fcc;
P_0c088fcc: /* original 000b, guest PC 0x0c088fcc */
if(!s->budget--) { s->failed_pc=0x0c088fccu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c088fce: /* original 6ef6, guest PC 0x0c088fce */
if(!s->budget--) { s->failed_pc=0x0c088fceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c088fd0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c088fd0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
