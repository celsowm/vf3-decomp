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
int vf3_away_batch49_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c083de4u: goto P_0c083de4;
case 0x0c083de6u: goto P_0c083de6;
case 0x0c083de8u: goto P_0c083de8;
case 0x0c083deau: goto P_0c083dea;
case 0x0c083decu: goto P_0c083dec;
case 0x0c083deeu: goto P_0c083dee;
case 0x0c083df0u: goto P_0c083df0;
case 0x0c083df2u: goto P_0c083df2;
case 0x0c083df4u: goto P_0c083df4;
case 0x0c083df6u: goto P_0c083df6;
case 0x0c083df8u: goto P_0c083df8;
case 0x0c083dfau: goto P_0c083dfa;
case 0x0c083dfcu: goto P_0c083dfc;
case 0x0c083dfeu: goto P_0c083dfe;
case 0x0c083e00u: goto P_0c083e00;
case 0x0c083e02u: goto P_0c083e02;
case 0x0c083e04u: goto P_0c083e04;
case 0x0c083e06u: goto P_0c083e06;
case 0x0c083e08u: goto P_0c083e08;
case 0x0c083e0au: goto P_0c083e0a;
case 0x0c083e0cu: goto P_0c083e0c;
case 0x0c083e0eu: goto P_0c083e0e;
case 0x0c083e10u: goto P_0c083e10;
case 0x0c083e12u: goto P_0c083e12;
case 0x0c083e14u: goto P_0c083e14;
case 0x0c083e16u: goto P_0c083e16;
case 0x0c083e18u: goto P_0c083e18;
case 0x0c083e1au: goto P_0c083e1a;
case 0x0c083e1cu: goto P_0c083e1c;
case 0x0c083e1eu: goto P_0c083e1e;
case 0x0c083e20u: goto P_0c083e20;
case 0x0c083e22u: goto P_0c083e22;
case 0x0c083e24u: goto P_0c083e24;
case 0x0c083e26u: goto P_0c083e26;
case 0x0c083e28u: goto P_0c083e28;
case 0x0c083e2au: goto P_0c083e2a;
case 0x0c083e2cu: goto P_0c083e2c;
case 0x0c083e2eu: goto P_0c083e2e;
case 0x0c083e30u: goto P_0c083e30;
case 0x0c083e32u: goto P_0c083e32;
case 0x0c083e34u: goto P_0c083e34;
case 0x0c083e36u: goto P_0c083e36;
case 0x0c083e38u: goto P_0c083e38;
case 0x0c083e3au: goto P_0c083e3a;
case 0x0c083e3cu: goto P_0c083e3c;
case 0x0c083e3eu: goto P_0c083e3e;
case 0x0c083e40u: goto P_0c083e40;
case 0x0c083e42u: goto P_0c083e42;
case 0x0c083e44u: goto P_0c083e44;
case 0x0c083e46u: goto P_0c083e46;
case 0x0c083e48u: goto P_0c083e48;
case 0x0c083e4au: goto P_0c083e4a;
case 0x0c083e4cu: goto P_0c083e4c;
case 0x0c083e4eu: goto P_0c083e4e;
case 0x0c083e50u: goto P_0c083e50;
case 0x0c083e52u: goto P_0c083e52;
case 0x0c083e54u: goto P_0c083e54;
case 0x0c083e56u: goto P_0c083e56;
case 0x0c083e58u: goto P_0c083e58;
case 0x0c083e5au: goto P_0c083e5a;
case 0x0c083e5cu: goto P_0c083e5c;
case 0x0c083e5eu: goto P_0c083e5e;
case 0x0c083e60u: goto P_0c083e60;
case 0x0c083e62u: goto P_0c083e62;
case 0x0c083e64u: goto P_0c083e64;
case 0x0c083e66u: goto P_0c083e66;
case 0x0c083e68u: goto P_0c083e68;
case 0x0c083e6au: goto P_0c083e6a;
case 0x0c083e6cu: goto P_0c083e6c;
case 0x0c083e6eu: goto P_0c083e6e;
case 0x0c083e70u: goto P_0c083e70;
case 0x0c083e72u: goto P_0c083e72;
case 0x0c083e74u: goto P_0c083e74;
case 0x0c083e76u: goto P_0c083e76;
case 0x0c083e78u: goto P_0c083e78;
case 0x0c083e7au: goto P_0c083e7a;
case 0x0c083e7cu: goto P_0c083e7c;
case 0x0c083e7eu: goto P_0c083e7e;
case 0x0c083e80u: goto P_0c083e80;
case 0x0c083e82u: goto P_0c083e82;
case 0x0c083e84u: goto P_0c083e84;
case 0x0c083e86u: goto P_0c083e86;
case 0x0c083e88u: goto P_0c083e88;
case 0x0c083e8au: goto P_0c083e8a;
case 0x0c083e8cu: goto P_0c083e8c;
case 0x0c083e8eu: goto P_0c083e8e;
case 0x0c083e90u: goto P_0c083e90;
case 0x0c083e92u: goto P_0c083e92;
case 0x0c083e94u: goto P_0c083e94;
case 0x0c083e96u: goto P_0c083e96;
case 0x0c083e98u: goto P_0c083e98;
case 0x0c083e9au: goto P_0c083e9a;
case 0x0c083e9cu: goto P_0c083e9c;
case 0x0c083e9eu: goto P_0c083e9e;
case 0x0c083ea0u: goto P_0c083ea0;
case 0x0c083ea2u: goto P_0c083ea2;
case 0x0c083ea4u: goto P_0c083ea4;
case 0x0c083ea6u: goto P_0c083ea6;
case 0x0c083ea8u: goto P_0c083ea8;
case 0x0c083eaau: goto P_0c083eaa;
case 0x0c083ed8u: goto P_0c083ed8;
case 0x0c083edau: goto P_0c083eda;
case 0x0c083edcu: goto P_0c083edc;
case 0x0c083edeu: goto P_0c083ede;
case 0x0c083ee0u: goto P_0c083ee0;
case 0x0c083ee2u: goto P_0c083ee2;
case 0x0c083ee4u: goto P_0c083ee4;
case 0x0c083ee6u: goto P_0c083ee6;
case 0x0c083ee8u: goto P_0c083ee8;
case 0x0c083eeau: goto P_0c083eea;
case 0x0c083eecu: goto P_0c083eec;
case 0x0c083eeeu: goto P_0c083eee;
case 0x0c083ef0u: goto P_0c083ef0;
case 0x0c083ef2u: goto P_0c083ef2;
case 0x0c083ef4u: goto P_0c083ef4;
case 0x0c083ef6u: goto P_0c083ef6;
case 0x0c083ef8u: goto P_0c083ef8;
case 0x0c083efau: goto P_0c083efa;
case 0x0c083efcu: goto P_0c083efc;
case 0x0c083efeu: goto P_0c083efe;
case 0x0c083f00u: goto P_0c083f00;
case 0x0c083f02u: goto P_0c083f02;
case 0x0c083f04u: goto P_0c083f04;
case 0x0c083f06u: goto P_0c083f06;
case 0x0c083f08u: goto P_0c083f08;
case 0x0c083f0au: goto P_0c083f0a;
case 0x0c083f0cu: goto P_0c083f0c;
case 0x0c083f0eu: goto P_0c083f0e;
case 0x0c083f10u: goto P_0c083f10;
case 0x0c083f12u: goto P_0c083f12;
case 0x0c083f14u: goto P_0c083f14;
case 0x0c083f16u: goto P_0c083f16;
case 0x0c083f18u: goto P_0c083f18;
case 0x0c083f1au: goto P_0c083f1a;
case 0x0c083f1cu: goto P_0c083f1c;
case 0x0c083f1eu: goto P_0c083f1e;
case 0x0c083f20u: goto P_0c083f20;
case 0x0c083f22u: goto P_0c083f22;
case 0x0c083f24u: goto P_0c083f24;
case 0x0c083f26u: goto P_0c083f26;
case 0x0c083f28u: goto P_0c083f28;
case 0x0c083f2au: goto P_0c083f2a;
case 0x0c083f2cu: goto P_0c083f2c;
case 0x0c083f2eu: goto P_0c083f2e;
case 0x0c083f30u: goto P_0c083f30;
case 0x0c083f32u: goto P_0c083f32;
case 0x0c083f34u: goto P_0c083f34;
case 0x0c083f36u: goto P_0c083f36;
case 0x0c083f38u: goto P_0c083f38;
case 0x0c083f3au: goto P_0c083f3a;
case 0x0c083f3cu: goto P_0c083f3c;
case 0x0c083f3eu: goto P_0c083f3e;
case 0x0c083f40u: goto P_0c083f40;
case 0x0c083f42u: goto P_0c083f42;
case 0x0c083f44u: goto P_0c083f44;
case 0x0c083f46u: goto P_0c083f46;
case 0x0c083f48u: goto P_0c083f48;
case 0x0c083f4au: goto P_0c083f4a;
case 0x0c083f4cu: goto P_0c083f4c;
case 0x0c083f4eu: goto P_0c083f4e;
case 0x0c083f50u: goto P_0c083f50;
case 0x0c083f52u: goto P_0c083f52;
case 0x0c083f54u: goto P_0c083f54;
case 0x0c083f56u: goto P_0c083f56;
case 0x0c083f58u: goto P_0c083f58;
case 0x0c083f5au: goto P_0c083f5a;
case 0x0c083f5cu: goto P_0c083f5c;
case 0x0c083f5eu: goto P_0c083f5e;
case 0x0c083f60u: goto P_0c083f60;
case 0x0c083f62u: goto P_0c083f62;
case 0x0c083f64u: goto P_0c083f64;
case 0x0c083f66u: goto P_0c083f66;
case 0x0c083f68u: goto P_0c083f68;
case 0x0c083f6au: goto P_0c083f6a;
case 0x0c083f6cu: goto P_0c083f6c;
case 0x0c083f6eu: goto P_0c083f6e;
case 0x0c083f70u: goto P_0c083f70;
case 0x0c083f72u: goto P_0c083f72;
case 0x0c083f74u: goto P_0c083f74;
case 0x0c083f76u: goto P_0c083f76;
case 0x0c083f78u: goto P_0c083f78;
case 0x0c083f7au: goto P_0c083f7a;
case 0x0c083f7cu: goto P_0c083f7c;
case 0x0c083f7eu: goto P_0c083f7e;
case 0x0c083f80u: goto P_0c083f80;
case 0x0c083f82u: goto P_0c083f82;
case 0x0c083f84u: goto P_0c083f84;
case 0x0c083f86u: goto P_0c083f86;
case 0x0c083f88u: goto P_0c083f88;
case 0x0c083f8au: goto P_0c083f8a;
case 0x0c083f8cu: goto P_0c083f8c;
case 0x0c083f8eu: goto P_0c083f8e;
case 0x0c083f90u: goto P_0c083f90;
case 0x0c083f92u: goto P_0c083f92;
case 0x0c083f94u: goto P_0c083f94;
case 0x0c083f96u: goto P_0c083f96;
case 0x0c083f98u: goto P_0c083f98;
case 0x0c083f9au: goto P_0c083f9a;
case 0x0c083f9cu: goto P_0c083f9c;
case 0x0c083f9eu: goto P_0c083f9e;
case 0x0c083fa0u: goto P_0c083fa0;
case 0x0c083fa2u: goto P_0c083fa2;
case 0x0c083fa4u: goto P_0c083fa4;
case 0x0c083fa6u: goto P_0c083fa6;
case 0x0c083fa8u: goto P_0c083fa8;
case 0x0c083faau: goto P_0c083faa;
case 0x0c083facu: goto P_0c083fac;
case 0x0c083faeu: goto P_0c083fae;
case 0x0c083fb0u: goto P_0c083fb0;
case 0x0c083fb2u: goto P_0c083fb2;
case 0x0c083fb4u: goto P_0c083fb4;
case 0x0c083fb6u: goto P_0c083fb6;
case 0x0c083fb8u: goto P_0c083fb8;
case 0x0c083fbau: goto P_0c083fba;
case 0x0c083fbcu: goto P_0c083fbc;
case 0x0c083fbeu: goto P_0c083fbe;
case 0x0c083fc0u: goto P_0c083fc0;
case 0x0c083fc2u: goto P_0c083fc2;
case 0x0c083fc4u: goto P_0c083fc4;
case 0x0c083fc6u: goto P_0c083fc6;
case 0x0c083fc8u: goto P_0c083fc8;
case 0x0c083fcau: goto P_0c083fca;
case 0x0c083fccu: goto P_0c083fcc;
case 0x0c083fceu: goto P_0c083fce;
case 0x0c083fd0u: goto P_0c083fd0;
case 0x0c083fd2u: goto P_0c083fd2;
case 0x0c083fd4u: goto P_0c083fd4;
case 0x0c083fd6u: goto P_0c083fd6;
case 0x0c083fd8u: goto P_0c083fd8;
case 0x0c083fdau: goto P_0c083fda;
case 0x0c083fdcu: goto P_0c083fdc;
case 0x0c083fdeu: goto P_0c083fde;
case 0x0c083fe0u: goto P_0c083fe0;
case 0x0c083fe2u: goto P_0c083fe2;
case 0x0c083fe4u: goto P_0c083fe4;
case 0x0c083fe6u: goto P_0c083fe6;
case 0x0c083fe8u: goto P_0c083fe8;
case 0x0c083feau: goto P_0c083fea;
case 0x0c083fecu: goto P_0c083fec;
case 0x0c083feeu: goto P_0c083fee;
case 0x0c083ff0u: goto P_0c083ff0;
case 0x0c083ff2u: goto P_0c083ff2;
case 0x0c083ff4u: goto P_0c083ff4;
case 0x0c083ff6u: goto P_0c083ff6;
case 0x0c083ff8u: goto P_0c083ff8;
case 0x0c083ffau: goto P_0c083ffa;
case 0x0c083ffcu: goto P_0c083ffc;
case 0x0c083ffeu: goto P_0c083ffe;
case 0x0c084000u: goto P_0c084000;
case 0x0c084002u: goto P_0c084002;
case 0x0c084004u: goto P_0c084004;
case 0x0c084006u: goto P_0c084006;
default: return vf3_matrix_family(target,s,ram);
}
P_0c083de4: /* original 2fe6, guest PC 0x0c083de4 */
if(!s->budget--) { s->failed_pc=0x0c083de4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083de6;
P_0c083de6: /* original 2fd6, guest PC 0x0c083de6 */
if(!s->budget--) { s->failed_pc=0x0c083de6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083de8;
P_0c083de8: /* original 2fc6, guest PC 0x0c083de8 */
if(!s->budget--) { s->failed_pc=0x0c083de8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083dea;
P_0c083dea: /* original 2fb6, guest PC 0x0c083dea */
if(!s->budget--) { s->failed_pc=0x0c083deau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083dec;
P_0c083dec: /* original 2fa6, guest PC 0x0c083dec */
if(!s->budget--) { s->failed_pc=0x0c083decu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083dee;
P_0c083dee: /* original 2f96, guest PC 0x0c083dee */
if(!s->budget--) { s->failed_pc=0x0c083deeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083df0;
P_0c083df0: /* original 2f86, guest PC 0x0c083df0 */
if(!s->budget--) { s->failed_pc=0x0c083df0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083df2;
P_0c083df2: /* original fffb, guest PC 0x0c083df2 */
if(!s->budget--) { s->failed_pc=0x0c083df2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c083df4;
P_0c083df4: /* original 4f22, guest PC 0x0c083df4 */
if(!s->budget--) { s->failed_pc=0x0c083df4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c083df6;
P_0c083df6: /* original 9a59, guest PC 0x0c083df6 */
if(!s->budget--) { s->failed_pc=0x0c083df6u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c083eacu,2);
goto P_0c083df8;
P_0c083df8: /* original d32e, guest PC 0x0c083df8 */
if(!s->budget--) { s->failed_pc=0x0c083df8u; return 0; }
r[3]=read(ram,0x0c083eb4u,4);
goto P_0c083dfa;
P_0c083dfa: /* original 4f12, guest PC 0x0c083dfa */
if(!s->budget--) { s->failed_pc=0x0c083dfau; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c083dfc;
P_0c083dfc: /* original d42c, guest PC 0x0c083dfc */
if(!s->budget--) { s->failed_pc=0x0c083dfcu; return 0; }
r[4]=read(ram,0x0c083eb0u,4);
goto P_0c083dfe;
P_0c083dfe: /* original 7ffc, guest PC 0x0c083dfe */
if(!s->budget--) { s->failed_pc=0x0c083dfeu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c083e00;
P_0c083e00: /* original 2f32, guest PC 0x0c083e00 */
if(!s->budget--) { s->failed_pc=0x0c083e00u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c083e02;
P_0c083e02: /* original 3a4c, guest PC 0x0c083e02 */
if(!s->budget--) { s->failed_pc=0x0c083e02u; return 0; }
r[10]+=r[4];
goto P_0c083e04;
P_0c083e04: /* original d32d, guest PC 0x0c083e04 */
if(!s->budget--) { s->failed_pc=0x0c083e04u; return 0; }
r[3]=read(ram,0x0c083ebcu,4);
goto P_0c083e06;
P_0c083e06: /* original d42c, guest PC 0x0c083e06 */
if(!s->budget--) { s->failed_pc=0x0c083e06u; return 0; }
r[4]=read(ram,0x0c083eb8u,4);
goto P_0c083e08;
P_0c083e08: /* original 430b, guest PC 0x0c083e08 */
if(!s->budget--) { s->failed_pc=0x0c083e08u; return 0; }
target=r[3];
r[16]=code_base|0x0c083e0cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083e0cu) { target=s->pc; goto dispatch; }
goto P_0c083e0c;
P_0c083e0a: /* original 0009, guest PC 0x0c083e0a */
if(!s->budget--) { s->failed_pc=0x0c083e0au; return 0; }
goto P_0c083e0c;
P_0c083e0c: /* original d22b, guest PC 0x0c083e0c */
if(!s->budget--) { s->failed_pc=0x0c083e0cu; return 0; }
r[2]=read(ram,0x0c083ebcu,4);
goto P_0c083e0e;
P_0c083e0e: /* original d42c, guest PC 0x0c083e0e */
if(!s->budget--) { s->failed_pc=0x0c083e0eu; return 0; }
r[4]=read(ram,0x0c083ec0u,4);
goto P_0c083e10;
P_0c083e10: /* original 420b, guest PC 0x0c083e10 */
if(!s->budget--) { s->failed_pc=0x0c083e10u; return 0; }
target=r[2];
r[16]=code_base|0x0c083e14u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083e14u) { target=s->pc; goto dispatch; }
goto P_0c083e14;
P_0c083e12: /* original 0009, guest PC 0x0c083e12 */
if(!s->budget--) { s->failed_pc=0x0c083e12u; return 0; }
goto P_0c083e14;
P_0c083e14: /* original bfa7, guest PC 0x0c083e14 */
if(!s->budget--) { s->failed_pc=0x0c083e14u; return 0; }
target=code_base|0x0c083d66u; r[16]=code_base|0x0c083e18u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083e18u) { target=s->pc; goto dispatch; }
goto P_0c083e18;
P_0c083e16: /* original 64f2, guest PC 0x0c083e16 */
if(!s->budget--) { s->failed_pc=0x0c083e16u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c083e18;
P_0c083e18: /* original d92a, guest PC 0x0c083e18 */
if(!s->budget--) { s->failed_pc=0x0c083e18u; return 0; }
r[9]=read(ram,0x0c083ec4u,4);
goto P_0c083e1a;
P_0c083e1a: /* original ec00, guest PC 0x0c083e1a */
if(!s->budget--) { s->failed_pc=0x0c083e1au; return 0; }
r[12]=0x00000000u;
goto P_0c083e1c;
P_0c083e1c: /* original ed0d, guest PC 0x0c083e1c */
if(!s->budget--) { s->failed_pc=0x0c083e1cu; return 0; }
r[13]=0x0000000du;
goto P_0c083e1e;
P_0c083e1e: /* original 0cd7, guest PC 0x0c083e1e */
if(!s->budget--) { s->failed_pc=0x0c083e1eu; return 0; }
r[19]=r[12]*r[13];
goto P_0c083e20;
P_0c083e20: /* original 68c3, guest PC 0x0c083e20 */
if(!s->budget--) { s->failed_pc=0x0c083e20u; return 0; }
r[8]=r[12];
goto P_0c083e22;
P_0c083e22: /* original 4800, guest PC 0x0c083e22 */
if(!s->budget--) { s->failed_pc=0x0c083e22u; return 0; }
r[17]=(r[17]&~1u)|((r[8]>>31)!=0);
r[8]<<=1;
goto P_0c083e24;
P_0c083e24: /* original 63c3, guest PC 0x0c083e24 */
if(!s->budget--) { s->failed_pc=0x0c083e24u; return 0; }
r[3]=r[12];
goto P_0c083e26;
P_0c083e26: /* original 383c, guest PC 0x0c083e26 */
if(!s->budget--) { s->failed_pc=0x0c083e26u; return 0; }
r[8]+=r[3];
goto P_0c083e28;
P_0c083e28: /* original e307, guest PC 0x0c083e28 */
if(!s->budget--) { s->failed_pc=0x0c083e28u; return 0; }
r[3]=0x00000007u;
goto P_0c083e2a;
P_0c083e2a: /* original 021a, guest PC 0x0c083e2a */
if(!s->budget--) { s->failed_pc=0x0c083e2au; return 0; }
r[2]=r[19];
goto P_0c083e2c;
P_0c083e2c: /* original 7808, guest PC 0x0c083e2c */
if(!s->budget--) { s->failed_pc=0x0c083e2cu; return 0; }
r[8]+=0x00000008u;
goto P_0c083e2e;
P_0c083e2e: /* original ee00, guest PC 0x0c083e2e */
if(!s->budget--) { s->failed_pc=0x0c083e2eu; return 0; }
r[14]=0x00000000u;
goto P_0c083e30;
P_0c083e30: /* original 483c, guest PC 0x0c083e30 */
if(!s->budget--) { s->failed_pc=0x0c083e30u; return 0; }
r[8]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[8]>>((-r[3])&31u)):((int32_t)r[8]<0?0xffffffffu:0)):r[8]<<(r[3]&31u);
goto P_0c083e32;
P_0c083e32: /* original a02a, guest PC 0x0c083e32 */
if(!s->budget--) { s->failed_pc=0x0c083e32u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c083e8a;
P_0c083e34: /* original 2f22, guest PC 0x0c083e34 */
if(!s->budget--) { s->failed_pc=0x0c083e34u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c083e36;
P_0c083e36: /* original 6be3, guest PC 0x0c083e36 */
if(!s->budget--) { s->failed_pc=0x0c083e36u; return 0; }
r[11]=r[14];
goto P_0c083e38;
P_0c083e38: /* original 4b08, guest PC 0x0c083e38 */
if(!s->budget--) { s->failed_pc=0x0c083e38u; return 0; }
r[11]<<=2;
goto P_0c083e3a;
P_0c083e3a: /* original 7b07, guest PC 0x0c083e3a */
if(!s->budget--) { s->failed_pc=0x0c083e3au; return 0; }
r[11]+=0x00000007u;
goto P_0c083e3c;
P_0c083e3c: /* original 4b00, guest PC 0x0c083e3c */
if(!s->budget--) { s->failed_pc=0x0c083e3cu; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c083e3e;
P_0c083e3e: /* original 3ce0, guest PC 0x0c083e3e */
if(!s->budget--) { s->failed_pc=0x0c083e3eu; return 0; }
r[17]=(r[17]&~1u)|((r[12]==r[14])!=0);
goto P_0c083e40;
P_0c083e40: /* original 8d22, guest PC 0x0c083e40 */
if(!s->budget--) { s->failed_pc=0x0c083e40u; return 0; }
cond=r[17]&1u;
r[11]|=r[8];
if(cond) { goto P_0c083e88; }
goto P_0c083e44;
P_0c083e42: /* original 2b8b, guest PC 0x0c083e42 */
if(!s->budget--) { s->failed_pc=0x0c083e42u; return 0; }
r[11]|=r[8];
goto P_0c083e44;
P_0c083e44: /* original 64f2, guest PC 0x0c083e44 */
if(!s->budget--) { s->failed_pc=0x0c083e44u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c083e46;
P_0c083e46: /* original 63a3, guest PC 0x0c083e46 */
if(!s->budget--) { s->failed_pc=0x0c083e46u; return 0; }
r[3]=r[10];
goto P_0c083e48;
P_0c083e48: /* original 34ec, guest PC 0x0c083e48 */
if(!s->budget--) { s->failed_pc=0x0c083e48u; return 0; }
r[4]+=r[14];
goto P_0c083e4a;
P_0c083e4a: /* original 4408, guest PC 0x0c083e4a */
if(!s->budget--) { s->failed_pc=0x0c083e4au; return 0; }
r[4]<<=2;
goto P_0c083e4c;
P_0c083e4c: /* original 490b, guest PC 0x0c083e4c */
if(!s->budget--) { s->failed_pc=0x0c083e4cu; return 0; }
target=r[9];
r[16]=code_base|0x0c083e50u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083e50u) { target=s->pc; goto dispatch; }
goto P_0c083e50;
P_0c083e4e: /* original 343c, guest PC 0x0c083e4e */
if(!s->budget--) { s->failed_pc=0x0c083e4eu; return 0; }
r[4]+=r[3];
goto P_0c083e50;
P_0c083e50: /* original 0ed7, guest PC 0x0c083e50 */
if(!s->budget--) { s->failed_pc=0x0c083e50u; return 0; }
r[19]=r[14]*r[13];
goto P_0c083e52;
P_0c083e52: /* original 63a3, guest PC 0x0c083e52 */
if(!s->budget--) { s->failed_pc=0x0c083e52u; return 0; }
r[3]=r[10];
goto P_0c083e54;
P_0c083e54: /* original ff0c, guest PC 0x0c083e54 */
if(!s->budget--) { s->failed_pc=0x0c083e54u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c083e56;
P_0c083e56: /* original 041a, guest PC 0x0c083e56 */
if(!s->budget--) { s->failed_pc=0x0c083e56u; return 0; }
r[4]=r[19];
goto P_0c083e58;
P_0c083e58: /* original 34cc, guest PC 0x0c083e58 */
if(!s->budget--) { s->failed_pc=0x0c083e58u; return 0; }
r[4]+=r[12];
goto P_0c083e5a;
P_0c083e5a: /* original 4408, guest PC 0x0c083e5a */
if(!s->budget--) { s->failed_pc=0x0c083e5au; return 0; }
r[4]<<=2;
goto P_0c083e5c;
P_0c083e5c: /* original 490b, guest PC 0x0c083e5c */
if(!s->budget--) { s->failed_pc=0x0c083e5cu; return 0; }
target=r[9];
r[16]=code_base|0x0c083e60u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083e60u) { target=s->pc; goto dispatch; }
goto P_0c083e60;
P_0c083e5e: /* original 343c, guest PC 0x0c083e5e */
if(!s->budget--) { s->failed_pc=0x0c083e5eu; return 0; }
r[4]+=r[3];
goto P_0c083e60;
P_0c083e60: /* original f40c, guest PC 0x0c083e60 */
if(!s->budget--) { s->failed_pc=0x0c083e60u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c083e62;
P_0c083e62: /* original ff44, guest PC 0x0c083e62 */
if(!s->budget--) { s->failed_pc=0x0c083e62u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])==as_float(fr[4]))!=0);
goto P_0c083e64;
P_0c083e64: /* original 8b09, guest PC 0x0c083e64 */
if(!s->budget--) { s->failed_pc=0x0c083e64u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083e7a; }
goto P_0c083e66;
P_0c083e66: /* original f38d, guest PC 0x0c083e66 */
if(!s->budget--) { s->failed_pc=0x0c083e66u; return 0; }
fr[3]=0;
goto P_0c083e68;
P_0c083e68: /* original f3f4, guest PC 0x0c083e68 */
if(!s->budget--) { s->failed_pc=0x0c083e68u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])==as_float(fr[15]))!=0);
goto P_0c083e6a;
P_0c083e6a: /* original 8b06, guest PC 0x0c083e6a */
if(!s->budget--) { s->failed_pc=0x0c083e6au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083e7a; }
goto P_0c083e6c;
P_0c083e6c: /* original d217, guest PC 0x0c083e6c */
if(!s->budget--) { s->failed_pc=0x0c083e6cu; return 0; }
r[2]=read(ram,0x0c083eccu,4);
goto P_0c083e6e;
P_0c083e6e: /* original e601, guest PC 0x0c083e6e */
if(!s->budget--) { s->failed_pc=0x0c083e6eu; return 0; }
r[6]=0x00000001u;
goto P_0c083e70;
P_0c083e70: /* original d515, guest PC 0x0c083e70 */
if(!s->budget--) { s->failed_pc=0x0c083e70u; return 0; }
r[5]=read(ram,0x0c083ec8u,4);
goto P_0c083e72;
P_0c083e72: /* original 420b, guest PC 0x0c083e72 */
if(!s->budget--) { s->failed_pc=0x0c083e72u; return 0; }
target=r[2];
r[16]=code_base|0x0c083e76u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083e76u) { target=s->pc; goto dispatch; }
goto P_0c083e76;
P_0c083e74: /* original 64b3, guest PC 0x0c083e74 */
if(!s->budget--) { s->failed_pc=0x0c083e74u; return 0; }
r[4]=r[11];
goto P_0c083e76;
P_0c083e76: /* original a007, guest PC 0x0c083e76 */
if(!s->budget--) { s->failed_pc=0x0c083e76u; return 0; }
goto P_0c083e88;
P_0c083e78: /* original 0009, guest PC 0x0c083e78 */
if(!s->budget--) { s->failed_pc=0x0c083e78u; return 0; }
goto P_0c083e7a;
P_0c083e7a: /* original fffb, guest PC 0x0c083e7a */
if(!s->budget--) { s->failed_pc=0x0c083e7au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c083e7c;
P_0c083e7c: /* original d214, guest PC 0x0c083e7c */
if(!s->budget--) { s->failed_pc=0x0c083e7cu; return 0; }
r[2]=read(ram,0x0c083ed0u,4);
goto P_0c083e7e;
P_0c083e7e: /* original 2f26, guest PC 0x0c083e7e */
if(!s->budget--) { s->failed_pc=0x0c083e7eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083e80;
P_0c083e80: /* original d314, guest PC 0x0c083e80 */
if(!s->budget--) { s->failed_pc=0x0c083e80u; return 0; }
r[3]=read(ram,0x0c083ed4u,4);
goto P_0c083e82;
P_0c083e82: /* original 430b, guest PC 0x0c083e82 */
if(!s->budget--) { s->failed_pc=0x0c083e82u; return 0; }
target=r[3];
r[16]=code_base|0x0c083e86u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083e86u) { target=s->pc; goto dispatch; }
goto P_0c083e86;
P_0c083e84: /* original 64b3, guest PC 0x0c083e84 */
if(!s->budget--) { s->failed_pc=0x0c083e84u; return 0; }
r[4]=r[11];
goto P_0c083e86;
P_0c083e86: /* original 7f08, guest PC 0x0c083e86 */
if(!s->budget--) { s->failed_pc=0x0c083e86u; return 0; }
r[15]+=0x00000008u;
goto P_0c083e88;
P_0c083e88: /* original 7e01, guest PC 0x0c083e88 */
if(!s->budget--) { s->failed_pc=0x0c083e88u; return 0; }
r[14]+=0x00000001u;
goto P_0c083e8a;
P_0c083e8a: /* original 3ed3, guest PC 0x0c083e8a */
if(!s->budget--) { s->failed_pc=0x0c083e8au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[13])!=0);
goto P_0c083e8c;
P_0c083e8c: /* original 8bd3, guest PC 0x0c083e8c */
if(!s->budget--) { s->failed_pc=0x0c083e8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083e36; }
goto P_0c083e8e;
P_0c083e8e: /* original 7c01, guest PC 0x0c083e8e */
if(!s->budget--) { s->failed_pc=0x0c083e8eu; return 0; }
r[12]+=0x00000001u;
goto P_0c083e90;
P_0c083e90: /* original 3cd3, guest PC 0x0c083e90 */
if(!s->budget--) { s->failed_pc=0x0c083e90u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[13])!=0);
goto P_0c083e92;
P_0c083e92: /* original 8bc4, guest PC 0x0c083e92 */
if(!s->budget--) { s->failed_pc=0x0c083e92u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c083e1e; }
goto P_0c083e94;
P_0c083e94: /* original 7f04, guest PC 0x0c083e94 */
if(!s->budget--) { s->failed_pc=0x0c083e94u; return 0; }
r[15]+=0x00000004u;
goto P_0c083e96;
P_0c083e96: /* original 4f16, guest PC 0x0c083e96 */
if(!s->budget--) { s->failed_pc=0x0c083e96u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c083e98;
P_0c083e98: /* original 4f26, guest PC 0x0c083e98 */
if(!s->budget--) { s->failed_pc=0x0c083e98u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c083e9a;
P_0c083e9a: /* original fff9, guest PC 0x0c083e9a */
if(!s->budget--) { s->failed_pc=0x0c083e9au; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c083e9c;
P_0c083e9c: /* original 68f6, guest PC 0x0c083e9c */
if(!s->budget--) { s->failed_pc=0x0c083e9cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c083e9e;
P_0c083e9e: /* original 69f6, guest PC 0x0c083e9e */
if(!s->budget--) { s->failed_pc=0x0c083e9eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c083ea0;
P_0c083ea0: /* original 6af6, guest PC 0x0c083ea0 */
if(!s->budget--) { s->failed_pc=0x0c083ea0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c083ea2;
P_0c083ea2: /* original 6bf6, guest PC 0x0c083ea2 */
if(!s->budget--) { s->failed_pc=0x0c083ea2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c083ea4;
P_0c083ea4: /* original 6cf6, guest PC 0x0c083ea4 */
if(!s->budget--) { s->failed_pc=0x0c083ea4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c083ea6;
P_0c083ea6: /* original 6df6, guest PC 0x0c083ea6 */
if(!s->budget--) { s->failed_pc=0x0c083ea6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c083ea8;
P_0c083ea8: /* original 000b, guest PC 0x0c083ea8 */
if(!s->budget--) { s->failed_pc=0x0c083ea8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c083eaa: /* original 6ef6, guest PC 0x0c083eaa */
if(!s->budget--) { s->failed_pc=0x0c083eaau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c083eacu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c083eacu; return 0; } return 1;
P_0c083ed8: /* original 2fe6, guest PC 0x0c083ed8 */
if(!s->budget--) { s->failed_pc=0x0c083ed8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083eda;
P_0c083eda: /* original 2fd6, guest PC 0x0c083eda */
if(!s->budget--) { s->failed_pc=0x0c083edau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083edc;
P_0c083edc: /* original 2fc6, guest PC 0x0c083edc */
if(!s->budget--) { s->failed_pc=0x0c083edcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083ede;
P_0c083ede: /* original 2fb6, guest PC 0x0c083ede */
if(!s->budget--) { s->failed_pc=0x0c083edeu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083ee0;
P_0c083ee0: /* original 2fa6, guest PC 0x0c083ee0 */
if(!s->budget--) { s->failed_pc=0x0c083ee0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083ee2;
P_0c083ee2: /* original 2f96, guest PC 0x0c083ee2 */
if(!s->budget--) { s->failed_pc=0x0c083ee2u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083ee4;
P_0c083ee4: /* original 2f86, guest PC 0x0c083ee4 */
if(!s->budget--) { s->failed_pc=0x0c083ee4u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083ee6;
P_0c083ee6: /* original fffb, guest PC 0x0c083ee6 */
if(!s->budget--) { s->failed_pc=0x0c083ee6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c083ee8;
P_0c083ee8: /* original ffeb, guest PC 0x0c083ee8 */
if(!s->budget--) { s->failed_pc=0x0c083ee8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c083eea;
P_0c083eea: /* original ffdb, guest PC 0x0c083eea */
if(!s->budget--) { s->failed_pc=0x0c083eeau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c083eec;
P_0c083eec: /* original 4f22, guest PC 0x0c083eec */
if(!s->budget--) { s->failed_pc=0x0c083eecu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c083eee;
P_0c083eee: /* original 9d8b, guest PC 0x0c083eee */
if(!s->budget--) { s->failed_pc=0x0c083eeeu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084008u,2);
goto P_0c083ef0;
P_0c083ef0: /* original d34a, guest PC 0x0c083ef0 */
if(!s->budget--) { s->failed_pc=0x0c083ef0u; return 0; }
r[3]=read(ram,0x0c08401cu,4);
goto P_0c083ef2;
P_0c083ef2: /* original d449, guest PC 0x0c083ef2 */
if(!s->budget--) { s->failed_pc=0x0c083ef2u; return 0; }
r[4]=read(ram,0x0c084018u,4);
goto P_0c083ef4;
P_0c083ef4: /* original 7fec, guest PC 0x0c083ef4 */
if(!s->budget--) { s->failed_pc=0x0c083ef4u; return 0; }
r[15]+=0xffffffecu;
goto P_0c083ef6;
P_0c083ef6: /* original 1f32, guest PC 0x0c083ef6 */
if(!s->budget--) { s->failed_pc=0x0c083ef6u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c083ef8;
P_0c083ef8: /* original 3d4c, guest PC 0x0c083ef8 */
if(!s->budget--) { s->failed_pc=0x0c083ef8u; return 0; }
r[13]+=r[4];
goto P_0c083efa;
P_0c083efa: /* original d34a, guest PC 0x0c083efa */
if(!s->budget--) { s->failed_pc=0x0c083efau; return 0; }
r[3]=read(ram,0x0c084024u,4);
goto P_0c083efc;
P_0c083efc: /* original d448, guest PC 0x0c083efc */
if(!s->budget--) { s->failed_pc=0x0c083efcu; return 0; }
r[4]=read(ram,0x0c084020u,4);
goto P_0c083efe;
P_0c083efe: /* original 430b, guest PC 0x0c083efe */
if(!s->budget--) { s->failed_pc=0x0c083efeu; return 0; }
target=r[3];
r[16]=code_base|0x0c083f02u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083f02u) { target=s->pc; goto dispatch; }
goto P_0c083f02;
P_0c083f00: /* original 0009, guest PC 0x0c083f00 */
if(!s->budget--) { s->failed_pc=0x0c083f00u; return 0; }
goto P_0c083f02;
P_0c083f02: /* original d248, guest PC 0x0c083f02 */
if(!s->budget--) { s->failed_pc=0x0c083f02u; return 0; }
r[2]=read(ram,0x0c084024u,4);
goto P_0c083f04;
P_0c083f04: /* original d448, guest PC 0x0c083f04 */
if(!s->budget--) { s->failed_pc=0x0c083f04u; return 0; }
r[4]=read(ram,0x0c084028u,4);
goto P_0c083f06;
P_0c083f06: /* original 420b, guest PC 0x0c083f06 */
if(!s->budget--) { s->failed_pc=0x0c083f06u; return 0; }
target=r[2];
r[16]=code_base|0x0c083f0au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083f0au) { target=s->pc; goto dispatch; }
goto P_0c083f0a;
P_0c083f08: /* original 0009, guest PC 0x0c083f08 */
if(!s->budget--) { s->failed_pc=0x0c083f08u; return 0; }
goto P_0c083f0a;
P_0c083f0a: /* original bf2c, guest PC 0x0c083f0a */
if(!s->budget--) { s->failed_pc=0x0c083f0au; return 0; }
target=code_base|0x0c083d66u; r[16]=code_base|0x0c083f0eu;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083f0eu) { target=s->pc; goto dispatch; }
goto P_0c083f0e;
P_0c083f0c: /* original 54f2, guest PC 0x0c083f0c */
if(!s->budget--) { s->failed_pc=0x0c083f0cu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c083f0e;
P_0c083f0e: /* original e400, guest PC 0x0c083f0e */
if(!s->budget--) { s->failed_pc=0x0c083f0eu; return 0; }
r[4]=0x00000000u;
goto P_0c083f10;
P_0c083f10: /* original e901, guest PC 0x0c083f10 */
if(!s->budget--) { s->failed_pc=0x0c083f10u; return 0; }
r[9]=0x00000001u;
goto P_0c083f12;
P_0c083f12: /* original 1f43, guest PC 0x0c083f12 */
if(!s->budget--) { s->failed_pc=0x0c083f12u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c083f14;
P_0c083f14: /* original 9879, guest PC 0x0c083f14 */
if(!s->budget--) { s->failed_pc=0x0c083f14u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08400au,2);
goto P_0c083f16;
P_0c083f16: /* original 1f42, guest PC 0x0c083f16 */
if(!s->budget--) { s->failed_pc=0x0c083f16u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c083f18;
P_0c083f18: /* original db45, guest PC 0x0c083f18 */
if(!s->budget--) { s->failed_pc=0x0c083f18u; return 0; }
r[11]=read(ram,0x0c084030u,4);
goto P_0c083f1a;
P_0c083f1a: /* original 38dc, guest PC 0x0c083f1a */
if(!s->budget--) { s->failed_pc=0x0c083f1au; return 0; }
r[8]+=r[13];
goto P_0c083f1c;
P_0c083f1c: /* original da43, guest PC 0x0c083f1c */
if(!s->budget--) { s->failed_pc=0x0c083f1cu; return 0; }
r[10]=read(ram,0x0c08402cu,4);
goto P_0c083f1e;
P_0c083f1e: /* original dc45, guest PC 0x0c083f1e */
if(!s->budget--) { s->failed_pc=0x0c083f1eu; return 0; }
r[12]=read(ram,0x0c084034u,4);
goto P_0c083f20;
P_0c083f20: /* original 54f2, guest PC 0x0c083f20 */
if(!s->budget--) { s->failed_pc=0x0c083f20u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c083f22;
P_0c083f22: /* original e307, guest PC 0x0c083f22 */
if(!s->budget--) { s->failed_pc=0x0c083f22u; return 0; }
r[3]=0x00000007u;
goto P_0c083f24;
P_0c083f24: /* original 6593, guest PC 0x0c083f24 */
if(!s->budget--) { s->failed_pc=0x0c083f24u; return 0; }
r[5]=r[9];
goto P_0c083f26;
P_0c083f26: /* original ee06, guest PC 0x0c083f26 */
if(!s->budget--) { s->failed_pc=0x0c083f26u; return 0; }
r[14]=0x00000006u;
goto P_0c083f28;
P_0c083f28: /* original 7408, guest PC 0x0c083f28 */
if(!s->budget--) { s->failed_pc=0x0c083f28u; return 0; }
r[4]+=0x00000008u;
goto P_0c083f2a;
P_0c083f2a: /* original 443c, guest PC 0x0c083f2a */
if(!s->budget--) { s->failed_pc=0x0c083f2au; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c083f2c;
P_0c083f2c: /* original 1f44, guest PC 0x0c083f2c */
if(!s->budget--) { s->failed_pc=0x0c083f2cu; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c083f2e;
P_0c083f2e: /* original 2e4b, guest PC 0x0c083f2e */
if(!s->budget--) { s->failed_pc=0x0c083f2eu; return 0; }
r[14]|=r[4];
goto P_0c083f30;
P_0c083f30: /* original 2f56, guest PC 0x0c083f30 */
if(!s->budget--) { s->failed_pc=0x0c083f30u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083f32;
P_0c083f32: /* original d241, guest PC 0x0c083f32 */
if(!s->budget--) { s->failed_pc=0x0c083f32u; return 0; }
r[2]=read(ram,0x0c084038u,4);
goto P_0c083f34;
P_0c083f34: /* original 2f26, guest PC 0x0c083f34 */
if(!s->budget--) { s->failed_pc=0x0c083f34u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083f36;
P_0c083f36: /* original 4a0b, guest PC 0x0c083f36 */
if(!s->budget--) { s->failed_pc=0x0c083f36u; return 0; }
target=r[10];
r[16]=code_base|0x0c083f3au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083f3au) { target=s->pc; goto dispatch; }
goto P_0c083f3a;
P_0c083f38: /* original 64e3, guest PC 0x0c083f38 */
if(!s->budget--) { s->failed_pc=0x0c083f38u; return 0; }
r[4]=r[14];
goto P_0c083f3a;
P_0c083f3a: /* original d340, guest PC 0x0c083f3a */
if(!s->budget--) { s->failed_pc=0x0c083f3au; return 0; }
r[3]=read(ram,0x0c08403cu,4);
goto P_0c083f3c;
P_0c083f3c: /* original 7f08, guest PC 0x0c083f3c */
if(!s->budget--) { s->failed_pc=0x0c083f3cu; return 0; }
r[15]+=0x00000008u;
goto P_0c083f3e;
P_0c083f3e: /* original 430b, guest PC 0x0c083f3e */
if(!s->budget--) { s->failed_pc=0x0c083f3eu; return 0; }
target=r[3];
r[16]=code_base|0x0c083f42u;
r[4]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083f42u) { target=s->pc; goto dispatch; }
goto P_0c083f42;
P_0c083f40: /* original 6483, guest PC 0x0c083f40 */
if(!s->budget--) { s->failed_pc=0x0c083f40u; return 0; }
r[4]=r[8];
goto P_0c083f42;
P_0c083f42: /* original 600c, guest PC 0x0c083f42 */
if(!s->budget--) { s->failed_pc=0x0c083f42u; return 0; }
r[0]=r[0]&255u;
goto P_0c083f44;
P_0c083f44: /* original 2f02, guest PC 0x0c083f44 */
if(!s->budget--) { s->failed_pc=0x0c083f44u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c083f46;
P_0c083f46: /* original e601, guest PC 0x0c083f46 */
if(!s->budget--) { s->failed_pc=0x0c083f46u; return 0; }
r[6]=0x00000001u;
goto P_0c083f48;
P_0c083f48: /* original 50f4, guest PC 0x0c083f48 */
if(!s->budget--) { s->failed_pc=0x0c083f48u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c083f4a;
P_0c083f4a: /* original cb10, guest PC 0x0c083f4a */
if(!s->budget--) { s->failed_pc=0x0c083f4au; return 0; }
r[0]|=16u;
goto P_0c083f4c;
P_0c083f4c: /* original 1f01, guest PC 0x0c083f4c */
if(!s->budget--) { s->failed_pc=0x0c083f4cu; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c083f4e;
P_0c083f4e: /* original 6ef2, guest PC 0x0c083f4e */
if(!s->budget--) { s->failed_pc=0x0c083f4eu; return 0; }
tmp=read(ram,r[15],4);
r[14]=tmp;
goto P_0c083f50;
P_0c083f50: /* original d03b, guest PC 0x0c083f50 */
if(!s->budget--) { s->failed_pc=0x0c083f50u; return 0; }
r[0]=read(ram,0x0c084040u,4);
goto P_0c083f52;
P_0c083f52: /* original 54f1, guest PC 0x0c083f52 */
if(!s->budget--) { s->failed_pc=0x0c083f52u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c083f54;
P_0c083f54: /* original 4e08, guest PC 0x0c083f54 */
if(!s->budget--) { s->failed_pc=0x0c083f54u; return 0; }
r[14]<<=2;
goto P_0c083f56;
P_0c083f56: /* original d33b, guest PC 0x0c083f56 */
if(!s->budget--) { s->failed_pc=0x0c083f56u; return 0; }
r[3]=read(ram,0x0c084044u,4);
goto P_0c083f58;
P_0c083f58: /* original 430b, guest PC 0x0c083f58 */
if(!s->budget--) { s->failed_pc=0x0c083f58u; return 0; }
target=r[3];
r[16]=code_base|0x0c083f5cu;
r[5]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083f5cu) { target=s->pc; goto dispatch; }
goto P_0c083f5c;
P_0c083f5a: /* original 05ee, guest PC 0x0c083f5a */
if(!s->budget--) { s->failed_pc=0x0c083f5au; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c083f5c;
P_0c083f5c: /* original 9456, guest PC 0x0c083f5c */
if(!s->budget--) { s->failed_pc=0x0c083f5cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08400cu,2);
goto P_0c083f5e;
P_0c083f5e: /* original 34dc, guest PC 0x0c083f5e */
if(!s->budget--) { s->failed_pc=0x0c083f5eu; return 0; }
r[4]+=r[13];
goto P_0c083f60;
P_0c083f60: /* original 4c0b, guest PC 0x0c083f60 */
if(!s->budget--) { s->failed_pc=0x0c083f60u; return 0; }
target=r[12];
r[16]=code_base|0x0c083f64u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083f64u) { target=s->pc; goto dispatch; }
goto P_0c083f64;
P_0c083f62: /* original 34ec, guest PC 0x0c083f62 */
if(!s->budget--) { s->failed_pc=0x0c083f62u; return 0; }
r[4]+=r[14];
goto P_0c083f64;
P_0c083f64: /* original 9453, guest PC 0x0c083f64 */
if(!s->budget--) { s->failed_pc=0x0c083f64u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08400eu,2);
goto P_0c083f66;
P_0c083f66: /* original fd0c, guest PC 0x0c083f66 */
if(!s->budget--) { s->failed_pc=0x0c083f66u; return 0; }
vf3_matrix_move(s,13,0);
goto P_0c083f68;
P_0c083f68: /* original 34dc, guest PC 0x0c083f68 */
if(!s->budget--) { s->failed_pc=0x0c083f68u; return 0; }
r[4]+=r[13];
goto P_0c083f6a;
P_0c083f6a: /* original 4c0b, guest PC 0x0c083f6a */
if(!s->budget--) { s->failed_pc=0x0c083f6au; return 0; }
target=r[12];
r[16]=code_base|0x0c083f6eu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083f6eu) { target=s->pc; goto dispatch; }
goto P_0c083f6e;
P_0c083f6c: /* original 34ec, guest PC 0x0c083f6c */
if(!s->budget--) { s->failed_pc=0x0c083f6cu; return 0; }
r[4]+=r[14];
goto P_0c083f6e;
P_0c083f6e: /* original 944f, guest PC 0x0c083f6e */
if(!s->budget--) { s->failed_pc=0x0c083f6eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084010u,2);
goto P_0c083f70;
P_0c083f70: /* original ff0c, guest PC 0x0c083f70 */
if(!s->budget--) { s->failed_pc=0x0c083f70u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c083f72;
P_0c083f72: /* original 34dc, guest PC 0x0c083f72 */
if(!s->budget--) { s->failed_pc=0x0c083f72u; return 0; }
r[4]+=r[13];
goto P_0c083f74;
P_0c083f74: /* original 4c0b, guest PC 0x0c083f74 */
if(!s->budget--) { s->failed_pc=0x0c083f74u; return 0; }
target=r[12];
r[16]=code_base|0x0c083f78u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083f78u) { target=s->pc; goto dispatch; }
goto P_0c083f78;
P_0c083f76: /* original 34ec, guest PC 0x0c083f76 */
if(!s->budget--) { s->failed_pc=0x0c083f76u; return 0; }
r[4]+=r[14];
goto P_0c083f78;
P_0c083f78: /* original 944b, guest PC 0x0c083f78 */
if(!s->budget--) { s->failed_pc=0x0c083f78u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084012u,2);
goto P_0c083f7a;
P_0c083f7a: /* original fe0c, guest PC 0x0c083f7a */
if(!s->budget--) { s->failed_pc=0x0c083f7au; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c083f7c;
P_0c083f7c: /* original 34dc, guest PC 0x0c083f7c */
if(!s->budget--) { s->failed_pc=0x0c083f7cu; return 0; }
r[4]+=r[13];
goto P_0c083f7e;
P_0c083f7e: /* original 4b0b, guest PC 0x0c083f7e */
if(!s->budget--) { s->failed_pc=0x0c083f7eu; return 0; }
target=r[11];
r[16]=code_base|0x0c083f82u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083f82u) { target=s->pc; goto dispatch; }
goto P_0c083f82;
P_0c083f80: /* original 34ec, guest PC 0x0c083f80 */
if(!s->budget--) { s->failed_pc=0x0c083f80u; return 0; }
r[4]+=r[14];
goto P_0c083f82;
P_0c083f82: /* original 2f02, guest PC 0x0c083f82 */
if(!s->budget--) { s->failed_pc=0x0c083f82u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c083f84;
P_0c083f84: /* original 9446, guest PC 0x0c083f84 */
if(!s->budget--) { s->failed_pc=0x0c083f84u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084014u,2);
goto P_0c083f86;
P_0c083f86: /* original 34dc, guest PC 0x0c083f86 */
if(!s->budget--) { s->failed_pc=0x0c083f86u; return 0; }
r[4]+=r[13];
goto P_0c083f88;
P_0c083f88: /* original 4b0b, guest PC 0x0c083f88 */
if(!s->budget--) { s->failed_pc=0x0c083f88u; return 0; }
target=r[11];
r[16]=code_base|0x0c083f8cu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083f8cu) { target=s->pc; goto dispatch; }
goto P_0c083f8c;
P_0c083f8a: /* original 34ec, guest PC 0x0c083f8a */
if(!s->budget--) { s->failed_pc=0x0c083f8au; return 0; }
r[4]+=r[14];
goto P_0c083f8c;
P_0c083f8c: /* original 1f01, guest PC 0x0c083f8c */
if(!s->budget--) { s->failed_pc=0x0c083f8cu; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c083f8e;
P_0c083f8e: /* original 9442, guest PC 0x0c083f8e */
if(!s->budget--) { s->failed_pc=0x0c083f8eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084016u,2);
goto P_0c083f90;
P_0c083f90: /* original 34dc, guest PC 0x0c083f90 */
if(!s->budget--) { s->failed_pc=0x0c083f90u; return 0; }
r[4]+=r[13];
goto P_0c083f92;
P_0c083f92: /* original 4b0b, guest PC 0x0c083f92 */
if(!s->budget--) { s->failed_pc=0x0c083f92u; return 0; }
target=r[11];
r[16]=code_base|0x0c083f96u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083f96u) { target=s->pc; goto dispatch; }
goto P_0c083f96;
P_0c083f94: /* original 34ec, guest PC 0x0c083f94 */
if(!s->budget--) { s->failed_pc=0x0c083f94u; return 0; }
r[4]+=r[14];
goto P_0c083f96;
P_0c083f96: /* original f38d, guest PC 0x0c083f96 */
if(!s->budget--) { s->failed_pc=0x0c083f96u; return 0; }
fr[3]=0;
goto P_0c083f98;
P_0c083f98: /* original f3f4, guest PC 0x0c083f98 */
if(!s->budget--) { s->failed_pc=0x0c083f98u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])==as_float(fr[15]))!=0);
goto P_0c083f9a;
P_0c083f9a: /* original 6703, guest PC 0x0c083f9a */
if(!s->budget--) { s->failed_pc=0x0c083f9au; return 0; }
r[7]=r[0];
goto P_0c083f9c;
P_0c083f9c: /* original 50f4, guest PC 0x0c083f9c */
if(!s->budget--) { s->failed_pc=0x0c083f9cu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c083f9e;
P_0c083f9e: /* original cb22, guest PC 0x0c083f9e */
if(!s->budget--) { s->failed_pc=0x0c083f9eu; return 0; }
r[0]|=34u;
goto P_0c083fa0;
P_0c083fa0: /* original 8d0e, guest PC 0x0c083fa0 */
if(!s->budget--) { s->failed_pc=0x0c083fa0u; return 0; }
cond=r[17]&1u;
r[14]=r[0];
if(cond) { goto P_0c083fc0; }
goto P_0c083fa4;
P_0c083fa2: /* original 6e03, guest PC 0x0c083fa2 */
if(!s->budget--) { s->failed_pc=0x0c083fa2u; return 0; }
r[14]=r[0];
goto P_0c083fa4;
P_0c083fa4: /* original 2f76, guest PC 0x0c083fa4 */
if(!s->budget--) { s->failed_pc=0x0c083fa4u; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083fa6;
P_0c083fa6: /* original 52f2, guest PC 0x0c083fa6 */
if(!s->budget--) { s->failed_pc=0x0c083fa6u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c083fa8;
P_0c083fa8: /* original 2f26, guest PC 0x0c083fa8 */
if(!s->budget--) { s->failed_pc=0x0c083fa8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083faa;
P_0c083faa: /* original 53f2, guest PC 0x0c083faa */
if(!s->budget--) { s->failed_pc=0x0c083faau; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c083fac;
P_0c083fac: /* original 2f36, guest PC 0x0c083fac */
if(!s->budget--) { s->failed_pc=0x0c083facu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083fae;
P_0c083fae: /* original ffeb, guest PC 0x0c083fae */
if(!s->budget--) { s->failed_pc=0x0c083faeu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c083fb0;
P_0c083fb0: /* original fffb, guest PC 0x0c083fb0 */
if(!s->budget--) { s->failed_pc=0x0c083fb0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c083fb2;
P_0c083fb2: /* original ffdb, guest PC 0x0c083fb2 */
if(!s->budget--) { s->failed_pc=0x0c083fb2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c083fb4;
P_0c083fb4: /* original d324, guest PC 0x0c083fb4 */
if(!s->budget--) { s->failed_pc=0x0c083fb4u; return 0; }
r[3]=read(ram,0x0c084048u,4);
goto P_0c083fb6;
P_0c083fb6: /* original 2f36, guest PC 0x0c083fb6 */
if(!s->budget--) { s->failed_pc=0x0c083fb6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083fb8;
P_0c083fb8: /* original 4a0b, guest PC 0x0c083fb8 */
if(!s->budget--) { s->failed_pc=0x0c083fb8u; return 0; }
target=r[10];
r[16]=code_base|0x0c083fbcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083fbcu) { target=s->pc; goto dispatch; }
goto P_0c083fbc;
P_0c083fba: /* original 64e3, guest PC 0x0c083fba */
if(!s->budget--) { s->failed_pc=0x0c083fbau; return 0; }
r[4]=r[14];
goto P_0c083fbc;
P_0c083fbc: /* original a00c, guest PC 0x0c083fbc */
if(!s->budget--) { s->failed_pc=0x0c083fbcu; return 0; }
r[15]+=0x0000001cu;
goto P_0c083fd8;
P_0c083fbe: /* original 7f1c, guest PC 0x0c083fbe */
if(!s->budget--) { s->failed_pc=0x0c083fbeu; return 0; }
r[15]+=0x0000001cu;
goto P_0c083fc0;
P_0c083fc0: /* original 2f76, guest PC 0x0c083fc0 */
if(!s->budget--) { s->failed_pc=0x0c083fc0u; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083fc2;
P_0c083fc2: /* original 53f2, guest PC 0x0c083fc2 */
if(!s->budget--) { s->failed_pc=0x0c083fc2u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c083fc4;
P_0c083fc4: /* original 2f36, guest PC 0x0c083fc4 */
if(!s->budget--) { s->failed_pc=0x0c083fc4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083fc6;
P_0c083fc6: /* original 52f2, guest PC 0x0c083fc6 */
if(!s->budget--) { s->failed_pc=0x0c083fc6u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c083fc8;
P_0c083fc8: /* original 2f26, guest PC 0x0c083fc8 */
if(!s->budget--) { s->failed_pc=0x0c083fc8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083fca;
P_0c083fca: /* original ffeb, guest PC 0x0c083fca */
if(!s->budget--) { s->failed_pc=0x0c083fcau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c083fcc;
P_0c083fcc: /* original fffb, guest PC 0x0c083fcc */
if(!s->budget--) { s->failed_pc=0x0c083fccu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c083fce;
P_0c083fce: /* original d31f, guest PC 0x0c083fce */
if(!s->budget--) { s->failed_pc=0x0c083fceu; return 0; }
r[3]=read(ram,0x0c08404cu,4);
goto P_0c083fd0;
P_0c083fd0: /* original 2f36, guest PC 0x0c083fd0 */
if(!s->budget--) { s->failed_pc=0x0c083fd0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c083fd2;
P_0c083fd2: /* original 4a0b, guest PC 0x0c083fd2 */
if(!s->budget--) { s->failed_pc=0x0c083fd2u; return 0; }
target=r[10];
r[16]=code_base|0x0c083fd6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c083fd6u) { target=s->pc; goto dispatch; }
goto P_0c083fd6;
P_0c083fd4: /* original 64e3, guest PC 0x0c083fd4 */
if(!s->budget--) { s->failed_pc=0x0c083fd4u; return 0; }
r[4]=r[14];
goto P_0c083fd6;
P_0c083fd6: /* original 7f18, guest PC 0x0c083fd6 */
if(!s->budget--) { s->failed_pc=0x0c083fd6u; return 0; }
r[15]+=0x00000018u;
goto P_0c083fd8;
P_0c083fd8: /* original 52f3, guest PC 0x0c083fd8 */
if(!s->budget--) { s->failed_pc=0x0c083fd8u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c083fda;
P_0c083fda: /* original e10d, guest PC 0x0c083fda */
if(!s->budget--) { s->failed_pc=0x0c083fdau; return 0; }
r[1]=0x0000000du;
goto P_0c083fdc;
P_0c083fdc: /* original 7801, guest PC 0x0c083fdc */
if(!s->budget--) { s->failed_pc=0x0c083fdcu; return 0; }
r[8]+=0x00000001u;
goto P_0c083fde;
P_0c083fde: /* original 7201, guest PC 0x0c083fde */
if(!s->budget--) { s->failed_pc=0x0c083fdeu; return 0; }
r[2]+=0x00000001u;
goto P_0c083fe0;
P_0c083fe0: /* original 1f23, guest PC 0x0c083fe0 */
if(!s->budget--) { s->failed_pc=0x0c083fe0u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c083fe2;
P_0c083fe2: /* original 3213, guest PC 0x0c083fe2 */
if(!s->budget--) { s->failed_pc=0x0c083fe2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[1])!=0);
goto P_0c083fe4;
P_0c083fe4: /* original 53f2, guest PC 0x0c083fe4 */
if(!s->budget--) { s->failed_pc=0x0c083fe4u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c083fe6;
P_0c083fe6: /* original 7303, guest PC 0x0c083fe6 */
if(!s->budget--) { s->failed_pc=0x0c083fe6u; return 0; }
r[3]+=0x00000003u;
goto P_0c083fe8;
P_0c083fe8: /* original 1f32, guest PC 0x0c083fe8 */
if(!s->budget--) { s->failed_pc=0x0c083fe8u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c083fea;
P_0c083fea: /* original 8f99, guest PC 0x0c083fea */
if(!s->budget--) { s->failed_pc=0x0c083feau; return 0; }
cond=r[17]&1u;
r[9]+=0x00000001u;
if(!cond) { goto P_0c083f20; }
goto P_0c083fee;
P_0c083fec: /* original 7901, guest PC 0x0c083fec */
if(!s->budget--) { s->failed_pc=0x0c083fecu; return 0; }
r[9]+=0x00000001u;
goto P_0c083fee;
P_0c083fee: /* original 7f14, guest PC 0x0c083fee */
if(!s->budget--) { s->failed_pc=0x0c083feeu; return 0; }
r[15]+=0x00000014u;
goto P_0c083ff0;
P_0c083ff0: /* original 4f26, guest PC 0x0c083ff0 */
if(!s->budget--) { s->failed_pc=0x0c083ff0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c083ff2;
P_0c083ff2: /* original fdf9, guest PC 0x0c083ff2 */
if(!s->budget--) { s->failed_pc=0x0c083ff2u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c083ff4;
P_0c083ff4: /* original fef9, guest PC 0x0c083ff4 */
if(!s->budget--) { s->failed_pc=0x0c083ff4u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c083ff6;
P_0c083ff6: /* original fff9, guest PC 0x0c083ff6 */
if(!s->budget--) { s->failed_pc=0x0c083ff6u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c083ff8;
P_0c083ff8: /* original 68f6, guest PC 0x0c083ff8 */
if(!s->budget--) { s->failed_pc=0x0c083ff8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c083ffa;
P_0c083ffa: /* original 69f6, guest PC 0x0c083ffa */
if(!s->budget--) { s->failed_pc=0x0c083ffau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c083ffc;
P_0c083ffc: /* original 6af6, guest PC 0x0c083ffc */
if(!s->budget--) { s->failed_pc=0x0c083ffcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c083ffe;
P_0c083ffe: /* original 6bf6, guest PC 0x0c083ffe */
if(!s->budget--) { s->failed_pc=0x0c083ffeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c084000;
P_0c084000: /* original 6cf6, guest PC 0x0c084000 */
if(!s->budget--) { s->failed_pc=0x0c084000u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c084002;
P_0c084002: /* original 6df6, guest PC 0x0c084002 */
if(!s->budget--) { s->failed_pc=0x0c084002u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c084004;
P_0c084004: /* original 000b, guest PC 0x0c084004 */
if(!s->budget--) { s->failed_pc=0x0c084004u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c084006: /* original 6ef6, guest PC 0x0c084006 */
if(!s->budget--) { s->failed_pc=0x0c084006u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c084008u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c084008u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
