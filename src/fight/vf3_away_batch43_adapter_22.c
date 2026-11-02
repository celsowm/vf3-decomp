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
int vf3_away_batch43_adapter_22(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c080e04u: goto P_0c080e04;
case 0x0c080e06u: goto P_0c080e06;
case 0x0c080e08u: goto P_0c080e08;
case 0x0c080e0au: goto P_0c080e0a;
case 0x0c080e0cu: goto P_0c080e0c;
case 0x0c080e0eu: goto P_0c080e0e;
case 0x0c080e10u: goto P_0c080e10;
case 0x0c080e12u: goto P_0c080e12;
case 0x0c080e14u: goto P_0c080e14;
case 0x0c080e16u: goto P_0c080e16;
case 0x0c080e18u: goto P_0c080e18;
case 0x0c080e1au: goto P_0c080e1a;
case 0x0c080e1cu: goto P_0c080e1c;
case 0x0c080e1eu: goto P_0c080e1e;
case 0x0c080e20u: goto P_0c080e20;
case 0x0c080e22u: goto P_0c080e22;
case 0x0c080e24u: goto P_0c080e24;
case 0x0c080e26u: goto P_0c080e26;
case 0x0c080e28u: goto P_0c080e28;
case 0x0c080e2au: goto P_0c080e2a;
case 0x0c080e2cu: goto P_0c080e2c;
case 0x0c080e2eu: goto P_0c080e2e;
case 0x0c080e30u: goto P_0c080e30;
case 0x0c080e32u: goto P_0c080e32;
case 0x0c080e34u: goto P_0c080e34;
case 0x0c080e36u: goto P_0c080e36;
case 0x0c080e38u: goto P_0c080e38;
case 0x0c080e3au: goto P_0c080e3a;
case 0x0c080e3cu: goto P_0c080e3c;
case 0x0c080e3eu: goto P_0c080e3e;
case 0x0c080e40u: goto P_0c080e40;
case 0x0c080e42u: goto P_0c080e42;
case 0x0c080e44u: goto P_0c080e44;
case 0x0c080e46u: goto P_0c080e46;
case 0x0c080e48u: goto P_0c080e48;
case 0x0c080e4au: goto P_0c080e4a;
case 0x0c080e4cu: goto P_0c080e4c;
case 0x0c080e4eu: goto P_0c080e4e;
case 0x0c080e50u: goto P_0c080e50;
case 0x0c080e52u: goto P_0c080e52;
case 0x0c080e54u: goto P_0c080e54;
case 0x0c080e56u: goto P_0c080e56;
case 0x0c080e58u: goto P_0c080e58;
case 0x0c080e5au: goto P_0c080e5a;
case 0x0c080e64u: goto P_0c080e64;
case 0x0c080e66u: goto P_0c080e66;
case 0x0c080e68u: goto P_0c080e68;
case 0x0c080e6au: goto P_0c080e6a;
case 0x0c080e6cu: goto P_0c080e6c;
case 0x0c080e6eu: goto P_0c080e6e;
case 0x0c080e70u: goto P_0c080e70;
case 0x0c080e72u: goto P_0c080e72;
case 0x0c080e74u: goto P_0c080e74;
case 0x0c080e76u: goto P_0c080e76;
case 0x0c080e78u: goto P_0c080e78;
case 0x0c080e7au: goto P_0c080e7a;
case 0x0c080e7cu: goto P_0c080e7c;
case 0x0c080e7eu: goto P_0c080e7e;
case 0x0c080e80u: goto P_0c080e80;
case 0x0c080e82u: goto P_0c080e82;
case 0x0c080e84u: goto P_0c080e84;
case 0x0c080e86u: goto P_0c080e86;
case 0x0c080e88u: goto P_0c080e88;
case 0x0c080e8au: goto P_0c080e8a;
case 0x0c080e8cu: goto P_0c080e8c;
case 0x0c080e8eu: goto P_0c080e8e;
case 0x0c080e90u: goto P_0c080e90;
case 0x0c080e92u: goto P_0c080e92;
case 0x0c080e94u: goto P_0c080e94;
case 0x0c080e96u: goto P_0c080e96;
case 0x0c080e98u: goto P_0c080e98;
case 0x0c080e9au: goto P_0c080e9a;
case 0x0c080e9cu: goto P_0c080e9c;
case 0x0c080e9eu: goto P_0c080e9e;
case 0x0c080ea0u: goto P_0c080ea0;
case 0x0c080ea2u: goto P_0c080ea2;
case 0x0c080ea4u: goto P_0c080ea4;
case 0x0c080ea6u: goto P_0c080ea6;
case 0x0c080ea8u: goto P_0c080ea8;
case 0x0c080eaau: goto P_0c080eaa;
case 0x0c080eacu: goto P_0c080eac;
case 0x0c080eaeu: goto P_0c080eae;
case 0x0c080eb0u: goto P_0c080eb0;
case 0x0c080eb2u: goto P_0c080eb2;
case 0x0c080eb4u: goto P_0c080eb4;
case 0x0c080eb6u: goto P_0c080eb6;
case 0x0c080eb8u: goto P_0c080eb8;
case 0x0c080ebau: goto P_0c080eba;
case 0x0c080ebcu: goto P_0c080ebc;
case 0x0c080ebeu: goto P_0c080ebe;
case 0x0c080ec0u: goto P_0c080ec0;
case 0x0c080ec2u: goto P_0c080ec2;
case 0x0c080ec4u: goto P_0c080ec4;
case 0x0c080ec6u: goto P_0c080ec6;
case 0x0c080ec8u: goto P_0c080ec8;
case 0x0c080ecau: goto P_0c080eca;
case 0x0c080eccu: goto P_0c080ecc;
case 0x0c080eceu: goto P_0c080ece;
case 0x0c080ed0u: goto P_0c080ed0;
case 0x0c080ed2u: goto P_0c080ed2;
case 0x0c080ed4u: goto P_0c080ed4;
case 0x0c080f04u: goto P_0c080f04;
case 0x0c080f06u: goto P_0c080f06;
case 0x0c080f08u: goto P_0c080f08;
case 0x0c080f0au: goto P_0c080f0a;
case 0x0c080f0cu: goto P_0c080f0c;
case 0x0c080f0eu: goto P_0c080f0e;
case 0x0c080f10u: goto P_0c080f10;
case 0x0c080f12u: goto P_0c080f12;
case 0x0c080f14u: goto P_0c080f14;
case 0x0c080f16u: goto P_0c080f16;
case 0x0c080f18u: goto P_0c080f18;
case 0x0c080f1au: goto P_0c080f1a;
case 0x0c080f1cu: goto P_0c080f1c;
case 0x0c080f1eu: goto P_0c080f1e;
case 0x0c080f20u: goto P_0c080f20;
case 0x0c080f22u: goto P_0c080f22;
case 0x0c080f24u: goto P_0c080f24;
case 0x0c080f26u: goto P_0c080f26;
case 0x0c080f28u: goto P_0c080f28;
case 0x0c080f2au: goto P_0c080f2a;
case 0x0c080f2cu: goto P_0c080f2c;
case 0x0c080f2eu: goto P_0c080f2e;
case 0x0c080f30u: goto P_0c080f30;
case 0x0c080f32u: goto P_0c080f32;
case 0x0c080f34u: goto P_0c080f34;
case 0x0c080f36u: goto P_0c080f36;
case 0x0c080f38u: goto P_0c080f38;
case 0x0c080f3au: goto P_0c080f3a;
case 0x0c080f3cu: goto P_0c080f3c;
case 0x0c080f3eu: goto P_0c080f3e;
case 0x0c080f40u: goto P_0c080f40;
case 0x0c080f42u: goto P_0c080f42;
case 0x0c080f44u: goto P_0c080f44;
case 0x0c080f46u: goto P_0c080f46;
case 0x0c080f48u: goto P_0c080f48;
case 0x0c080f4au: goto P_0c080f4a;
case 0x0c080f4cu: goto P_0c080f4c;
case 0x0c080f4eu: goto P_0c080f4e;
case 0x0c080f50u: goto P_0c080f50;
case 0x0c080f52u: goto P_0c080f52;
case 0x0c080f54u: goto P_0c080f54;
case 0x0c080f56u: goto P_0c080f56;
case 0x0c080f58u: goto P_0c080f58;
case 0x0c080f5au: goto P_0c080f5a;
case 0x0c080f5cu: goto P_0c080f5c;
case 0x0c080f5eu: goto P_0c080f5e;
case 0x0c080f60u: goto P_0c080f60;
case 0x0c080f62u: goto P_0c080f62;
case 0x0c080f64u: goto P_0c080f64;
case 0x0c080f66u: goto P_0c080f66;
case 0x0c080f68u: goto P_0c080f68;
case 0x0c080f6au: goto P_0c080f6a;
case 0x0c080f6cu: goto P_0c080f6c;
case 0x0c080f6eu: goto P_0c080f6e;
case 0x0c080f70u: goto P_0c080f70;
case 0x0c080f72u: goto P_0c080f72;
case 0x0c080f74u: goto P_0c080f74;
case 0x0c080f76u: goto P_0c080f76;
case 0x0c080f78u: goto P_0c080f78;
case 0x0c080f7au: goto P_0c080f7a;
case 0x0c080f7cu: goto P_0c080f7c;
case 0x0c080f7eu: goto P_0c080f7e;
case 0x0c080f80u: goto P_0c080f80;
case 0x0c080f82u: goto P_0c080f82;
case 0x0c080f84u: goto P_0c080f84;
case 0x0c080f86u: goto P_0c080f86;
case 0x0c080f88u: goto P_0c080f88;
case 0x0c080f8au: goto P_0c080f8a;
case 0x0c080f8cu: goto P_0c080f8c;
case 0x0c080f8eu: goto P_0c080f8e;
case 0x0c080f90u: goto P_0c080f90;
case 0x0c080f92u: goto P_0c080f92;
case 0x0c080f94u: goto P_0c080f94;
case 0x0c080f96u: goto P_0c080f96;
case 0x0c080f98u: goto P_0c080f98;
case 0x0c080f9au: goto P_0c080f9a;
case 0x0c080f9cu: goto P_0c080f9c;
case 0x0c080f9eu: goto P_0c080f9e;
case 0x0c080fa0u: goto P_0c080fa0;
case 0x0c080fa2u: goto P_0c080fa2;
case 0x0c080fa4u: goto P_0c080fa4;
case 0x0c080fa6u: goto P_0c080fa6;
case 0x0c080fa8u: goto P_0c080fa8;
case 0x0c080faau: goto P_0c080faa;
case 0x0c080facu: goto P_0c080fac;
case 0x0c080faeu: goto P_0c080fae;
case 0x0c080fb0u: goto P_0c080fb0;
case 0x0c080fb2u: goto P_0c080fb2;
case 0x0c080fb4u: goto P_0c080fb4;
case 0x0c080fb6u: goto P_0c080fb6;
case 0x0c080fb8u: goto P_0c080fb8;
case 0x0c080fbau: goto P_0c080fba;
case 0x0c080fbcu: goto P_0c080fbc;
case 0x0c080fbeu: goto P_0c080fbe;
case 0x0c080fc0u: goto P_0c080fc0;
case 0x0c080fc2u: goto P_0c080fc2;
case 0x0c080fc4u: goto P_0c080fc4;
case 0x0c080fc6u: goto P_0c080fc6;
case 0x0c080fc8u: goto P_0c080fc8;
case 0x0c080fcau: goto P_0c080fca;
case 0x0c080fccu: goto P_0c080fcc;
case 0x0c080fceu: goto P_0c080fce;
case 0x0c080fd0u: goto P_0c080fd0;
case 0x0c080fd2u: goto P_0c080fd2;
case 0x0c080fd4u: goto P_0c080fd4;
case 0x0c080fd6u: goto P_0c080fd6;
case 0x0c080fd8u: goto P_0c080fd8;
case 0x0c080fdau: goto P_0c080fda;
case 0x0c080fdcu: goto P_0c080fdc;
case 0x0c080fdeu: goto P_0c080fde;
case 0x0c080fe0u: goto P_0c080fe0;
case 0x0c080fe2u: goto P_0c080fe2;
case 0x0c080fe4u: goto P_0c080fe4;
case 0x0c080fe6u: goto P_0c080fe6;
case 0x0c080fe8u: goto P_0c080fe8;
case 0x0c080feau: goto P_0c080fea;
case 0x0c080fecu: goto P_0c080fec;
case 0x0c080feeu: goto P_0c080fee;
case 0x0c080ff0u: goto P_0c080ff0;
case 0x0c080ff2u: goto P_0c080ff2;
case 0x0c080ff4u: goto P_0c080ff4;
case 0x0c080ff6u: goto P_0c080ff6;
case 0x0c080ff8u: goto P_0c080ff8;
case 0x0c080ffau: goto P_0c080ffa;
case 0x0c080ffcu: goto P_0c080ffc;
case 0x0c080ffeu: goto P_0c080ffe;
case 0x0c081000u: goto P_0c081000;
case 0x0c081002u: goto P_0c081002;
case 0x0c081004u: goto P_0c081004;
case 0x0c081006u: goto P_0c081006;
case 0x0c081008u: goto P_0c081008;
case 0x0c08100au: goto P_0c08100a;
case 0x0c08100cu: goto P_0c08100c;
case 0x0c08100eu: goto P_0c08100e;
case 0x0c081010u: goto P_0c081010;
case 0x0c081012u: goto P_0c081012;
case 0x0c081014u: goto P_0c081014;
case 0x0c081016u: goto P_0c081016;
case 0x0c081018u: goto P_0c081018;
case 0x0c08101au: goto P_0c08101a;
case 0x0c08101cu: goto P_0c08101c;
case 0x0c08101eu: goto P_0c08101e;
case 0x0c081020u: goto P_0c081020;
case 0x0c081022u: goto P_0c081022;
case 0x0c081024u: goto P_0c081024;
case 0x0c081026u: goto P_0c081026;
case 0x0c081028u: goto P_0c081028;
case 0x0c08102au: goto P_0c08102a;
case 0x0c08102cu: goto P_0c08102c;
case 0x0c08102eu: goto P_0c08102e;
case 0x0c081030u: goto P_0c081030;
case 0x0c081032u: goto P_0c081032;
case 0x0c081034u: goto P_0c081034;
case 0x0c081036u: goto P_0c081036;
case 0x0c081038u: goto P_0c081038;
case 0x0c08103au: goto P_0c08103a;
case 0x0c08103cu: goto P_0c08103c;
case 0x0c08103eu: goto P_0c08103e;
case 0x0c081040u: goto P_0c081040;
case 0x0c081042u: goto P_0c081042;
case 0x0c081044u: goto P_0c081044;
case 0x0c081046u: goto P_0c081046;
case 0x0c081048u: goto P_0c081048;
case 0x0c08104au: goto P_0c08104a;
case 0x0c08104cu: goto P_0c08104c;
case 0x0c08104eu: goto P_0c08104e;
case 0x0c081050u: goto P_0c081050;
case 0x0c081052u: goto P_0c081052;
case 0x0c081054u: goto P_0c081054;
case 0x0c081056u: goto P_0c081056;
case 0x0c081058u: goto P_0c081058;
case 0x0c08105au: goto P_0c08105a;
case 0x0c08105cu: goto P_0c08105c;
case 0x0c08105eu: goto P_0c08105e;
case 0x0c081060u: goto P_0c081060;
case 0x0c081062u: goto P_0c081062;
case 0x0c081064u: goto P_0c081064;
case 0x0c081066u: goto P_0c081066;
case 0x0c081068u: goto P_0c081068;
case 0x0c08106au: goto P_0c08106a;
case 0x0c08106cu: goto P_0c08106c;
case 0x0c08106eu: goto P_0c08106e;
case 0x0c081070u: goto P_0c081070;
case 0x0c081072u: goto P_0c081072;
case 0x0c081074u: goto P_0c081074;
case 0x0c081076u: goto P_0c081076;
case 0x0c081078u: goto P_0c081078;
case 0x0c08107au: goto P_0c08107a;
case 0x0c08107cu: goto P_0c08107c;
case 0x0c08107eu: goto P_0c08107e;
case 0x0c081080u: goto P_0c081080;
default: return vf3_matrix_family(target,s,ram);
}
P_0c080e04: /* original 2fe6, guest PC 0x0c080e04 */
if(!s->budget--) { s->failed_pc=0x0c080e04u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080e06;
P_0c080e06: /* original d339, guest PC 0x0c080e06 */
if(!s->budget--) { s->failed_pc=0x0c080e06u; return 0; }
r[3]=read(ram,0x0c080eecu,4);
goto P_0c080e08;
P_0c080e08: /* original 4f22, guest PC 0x0c080e08 */
if(!s->budget--) { s->failed_pc=0x0c080e08u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c080e0a;
P_0c080e0a: /* original 6432, guest PC 0x0c080e0a */
if(!s->budget--) { s->failed_pc=0x0c080e0au; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c080e0c;
P_0c080e0c: /* original d238, guest PC 0x0c080e0c */
if(!s->budget--) { s->failed_pc=0x0c080e0cu; return 0; }
r[2]=read(ram,0x0c080ef0u,4);
goto P_0c080e0e;
P_0c080e0e: /* original de36, guest PC 0x0c080e0e */
if(!s->budget--) { s->failed_pc=0x0c080e0eu; return 0; }
r[14]=read(ram,0x0c080ee8u,4);
goto P_0c080e10;
P_0c080e10: /* original 7ffc, guest PC 0x0c080e10 */
if(!s->budget--) { s->failed_pc=0x0c080e10u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c080e12;
P_0c080e12: /* original 2428, guest PC 0x0c080e12 */
if(!s->budget--) { s->failed_pc=0x0c080e12u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c080e14;
P_0c080e14: /* original 890c, guest PC 0x0c080e14 */
if(!s->budget--) { s->failed_pc=0x0c080e14u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c080e30; }
goto P_0c080e16;
P_0c080e16: /* original e000, guest PC 0x0c080e16 */
if(!s->budget--) { s->failed_pc=0x0c080e16u; return 0; }
r[0]=0x00000000u;
goto P_0c080e18;
P_0c080e18: /* original 2f06, guest PC 0x0c080e18 */
if(!s->budget--) { s->failed_pc=0x0c080e18u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080e1a;
P_0c080e1a: /* original 6703, guest PC 0x0c080e1a */
if(!s->budget--) { s->failed_pc=0x0c080e1au; return 0; }
r[7]=r[0];
goto P_0c080e1c;
P_0c080e1c: /* original 945c, guest PC 0x0c080e1c */
if(!s->budget--) { s->failed_pc=0x0c080e1cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080ed8u,2);
goto P_0c080e1e;
P_0c080e1e: /* original 955a, guest PC 0x0c080e1e */
if(!s->budget--) { s->failed_pc=0x0c080e1eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080ed6u,2);
goto P_0c080e20;
P_0c080e20: /* original d334, guest PC 0x0c080e20 */
if(!s->budget--) { s->failed_pc=0x0c080e20u; return 0; }
r[3]=read(ram,0x0c080ef4u,4);
goto P_0c080e22;
P_0c080e22: /* original 430b, guest PC 0x0c080e22 */
if(!s->budget--) { s->failed_pc=0x0c080e22u; return 0; }
target=r[3];
r[16]=code_base|0x0c080e26u;
r[6]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080e26u) { target=s->pc; goto dispatch; }
goto P_0c080e26;
P_0c080e24: /* original 66e3, guest PC 0x0c080e24 */
if(!s->budget--) { s->failed_pc=0x0c080e24u; return 0; }
r[6]=r[14];
goto P_0c080e26;
P_0c080e26: /* original 7f04, guest PC 0x0c080e26 */
if(!s->budget--) { s->failed_pc=0x0c080e26u; return 0; }
r[15]+=0x00000004u;
goto P_0c080e28;
P_0c080e28: /* original 7f04, guest PC 0x0c080e28 */
if(!s->budget--) { s->failed_pc=0x0c080e28u; return 0; }
r[15]+=0x00000004u;
goto P_0c080e2a;
P_0c080e2a: /* original 4f26, guest PC 0x0c080e2a */
if(!s->budget--) { s->failed_pc=0x0c080e2au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c080e2c;
P_0c080e2c: /* original 000b, guest PC 0x0c080e2c */
if(!s->budget--) { s->failed_pc=0x0c080e2cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c080e2e: /* original 6ef6, guest PC 0x0c080e2e */
if(!s->budget--) { s->failed_pc=0x0c080e2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c080e30;
P_0c080e30: /* original e200, guest PC 0x0c080e30 */
if(!s->budget--) { s->failed_pc=0x0c080e30u; return 0; }
r[2]=0x00000000u;
goto P_0c080e32;
P_0c080e32: /* original 2f26, guest PC 0x0c080e32 */
if(!s->budget--) { s->failed_pc=0x0c080e32u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080e34;
P_0c080e34: /* original 6723, guest PC 0x0c080e34 */
if(!s->budget--) { s->failed_pc=0x0c080e34u; return 0; }
r[7]=r[2];
goto P_0c080e36;
P_0c080e36: /* original 9451, guest PC 0x0c080e36 */
if(!s->budget--) { s->failed_pc=0x0c080e36u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080edcu,2);
goto P_0c080e38;
P_0c080e38: /* original 954f, guest PC 0x0c080e38 */
if(!s->budget--) { s->failed_pc=0x0c080e38u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080edau,2);
goto P_0c080e3a;
P_0c080e3a: /* original d32e, guest PC 0x0c080e3a */
if(!s->budget--) { s->failed_pc=0x0c080e3au; return 0; }
r[3]=read(ram,0x0c080ef4u,4);
goto P_0c080e3c;
P_0c080e3c: /* original 430b, guest PC 0x0c080e3c */
if(!s->budget--) { s->failed_pc=0x0c080e3cu; return 0; }
target=r[3];
r[16]=code_base|0x0c080e40u;
r[6]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080e40u) { target=s->pc; goto dispatch; }
goto P_0c080e40;
P_0c080e3e: /* original 66e3, guest PC 0x0c080e3e */
if(!s->budget--) { s->failed_pc=0x0c080e3eu; return 0; }
r[6]=r[14];
goto P_0c080e40;
P_0c080e40: /* original d32d, guest PC 0x0c080e40 */
if(!s->budget--) { s->failed_pc=0x0c080e40u; return 0; }
r[3]=read(ram,0x0c080ef8u,4);
goto P_0c080e42;
P_0c080e42: /* original 64e3, guest PC 0x0c080e42 */
if(!s->budget--) { s->failed_pc=0x0c080e42u; return 0; }
r[4]=r[14];
goto P_0c080e44;
P_0c080e44: /* original 6230, guest PC 0x0c080e44 */
if(!s->budget--) { s->failed_pc=0x0c080e44u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c080e46;
P_0c080e46: /* original 6023, guest PC 0x0c080e46 */
if(!s->budget--) { s->failed_pc=0x0c080e46u; return 0; }
r[0]=r[2];
goto P_0c080e48;
P_0c080e48: /* original 80f4, guest PC 0x0c080e48 */
if(!s->budget--) { s->failed_pc=0x0c080e48u; return 0; }
write(ram,r[15]+4,r[0],1);
goto P_0c080e4a;
P_0c080e4a: /* original 84f4, guest PC 0x0c080e4a */
if(!s->budget--) { s->failed_pc=0x0c080e4au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c080e4c;
P_0c080e4c: /* original 7f08, guest PC 0x0c080e4c */
if(!s->budget--) { s->failed_pc=0x0c080e4cu; return 0; }
r[15]+=0x00000008u;
goto P_0c080e4e;
P_0c080e4e: /* original 4f26, guest PC 0x0c080e4e */
if(!s->budget--) { s->failed_pc=0x0c080e4eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c080e50;
P_0c080e50: /* original 9546, guest PC 0x0c080e50 */
if(!s->budget--) { s->failed_pc=0x0c080e50u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080ee0u,2);
goto P_0c080e52;
P_0c080e52: /* original 6603, guest PC 0x0c080e52 */
if(!s->budget--) { s->failed_pc=0x0c080e52u; return 0; }
r[6]=r[0];
goto P_0c080e54;
P_0c080e54: /* original 9743, guest PC 0x0c080e54 */
if(!s->budget--) { s->failed_pc=0x0c080e54u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080edeu,2);
goto P_0c080e56;
P_0c080e56: /* original d229, guest PC 0x0c080e56 */
if(!s->budget--) { s->failed_pc=0x0c080e56u; return 0; }
r[2]=read(ram,0x0c080efcu,4);
goto P_0c080e58;
P_0c080e58: /* original 422b, guest PC 0x0c080e58 */
if(!s->budget--) { s->failed_pc=0x0c080e58u; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0c15e8u: return vf3_matrix_family(0x0c0c15e8u,s,ram);
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
P_0c080e5a: /* original 6ef6, guest PC 0x0c080e5a */
if(!s->budget--) { s->failed_pc=0x0c080e5au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c080e5cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c080e5cu; return 0; } return 1;
P_0c080e64: /* original 2fe6, guest PC 0x0c080e64 */
if(!s->budget--) { s->failed_pc=0x0c080e64u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080e66;
P_0c080e66: /* original e029, guest PC 0x0c080e66 */
if(!s->budget--) { s->failed_pc=0x0c080e66u; return 0; }
r[0]=0x00000029u;
goto P_0c080e68;
P_0c080e68: /* original 2fd6, guest PC 0x0c080e68 */
if(!s->budget--) { s->failed_pc=0x0c080e68u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080e6a;
P_0c080e6a: /* original 2fc6, guest PC 0x0c080e6a */
if(!s->budget--) { s->failed_pc=0x0c080e6au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080e6c;
P_0c080e6c: /* original 2fb6, guest PC 0x0c080e6c */
if(!s->budget--) { s->failed_pc=0x0c080e6cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080e6e;
P_0c080e6e: /* original 2fa6, guest PC 0x0c080e6e */
if(!s->budget--) { s->failed_pc=0x0c080e6eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080e70;
P_0c080e70: /* original 2f96, guest PC 0x0c080e70 */
if(!s->budget--) { s->failed_pc=0x0c080e70u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080e72;
P_0c080e72: /* original 2f86, guest PC 0x0c080e72 */
if(!s->budget--) { s->failed_pc=0x0c080e72u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080e74;
P_0c080e74: /* original 4f22, guest PC 0x0c080e74 */
if(!s->budget--) { s->failed_pc=0x0c080e74u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c080e76;
P_0c080e76: /* original da22, guest PC 0x0c080e76 */
if(!s->budget--) { s->failed_pc=0x0c080e76u; return 0; }
r[10]=read(ram,0x0c080f00u,4);
goto P_0c080e78;
P_0c080e78: /* original d51b, guest PC 0x0c080e78 */
if(!s->budget--) { s->failed_pc=0x0c080e78u; return 0; }
r[5]=read(ram,0x0c080ee8u,4);
goto P_0c080e7a;
P_0c080e7a: /* original 04ac, guest PC 0x0c080e7a */
if(!s->budget--) { s->failed_pc=0x0c080e7au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c080e7c;
P_0c080e7c: /* original 4f12, guest PC 0x0c080e7c */
if(!s->budget--) { s->failed_pc=0x0c080e7cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c080e7e;
P_0c080e7e: /* original 604c, guest PC 0x0c080e7e */
if(!s->budget--) { s->failed_pc=0x0c080e7eu; return 0; }
r[0]=r[4]&255u;
goto P_0c080e80;
P_0c080e80: /* original 8803, guest PC 0x0c080e80 */
if(!s->budget--) { s->failed_pc=0x0c080e80u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c080e82;
P_0c080e82: /* original 7fec, guest PC 0x0c080e82 */
if(!s->budget--) { s->failed_pc=0x0c080e82u; return 0; }
r[15]+=0xffffffecu;
goto P_0c080e84;
P_0c080e84: /* original 8f02, guest PC 0x0c080e84 */
if(!s->budget--) { s->failed_pc=0x0c080e84u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c080e8c; }
goto P_0c080e88;
P_0c080e86: /* original 6403, guest PC 0x0c080e86 */
if(!s->budget--) { s->failed_pc=0x0c080e86u; return 0; }
r[4]=r[0];
goto P_0c080e88;
P_0c080e88: /* original a0f0, guest PC 0x0c080e88 */
if(!s->budget--) { s->failed_pc=0x0c080e88u; return 0; }
goto P_0c08106c;
P_0c080e8a: /* original 0009, guest PC 0x0c080e8a */
if(!s->budget--) { s->failed_pc=0x0c080e8au; return 0; }
goto P_0c080e8c;
P_0c080e8c: /* original 2448, guest PC 0x0c080e8c */
if(!s->budget--) { s->failed_pc=0x0c080e8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c080e8e;
P_0c080e8e: /* original 8b01, guest PC 0x0c080e8e */
if(!s->budget--) { s->failed_pc=0x0c080e8eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c080e94; }
goto P_0c080e90;
P_0c080e90: /* original a0ec, guest PC 0x0c080e90 */
if(!s->budget--) { s->failed_pc=0x0c080e90u; return 0; }
goto P_0c08106c;
P_0c080e92: /* original 0009, guest PC 0x0c080e92 */
if(!s->budget--) { s->failed_pc=0x0c080e92u; return 0; }
goto P_0c080e94;
P_0c080e94: /* original 6043, guest PC 0x0c080e94 */
if(!s->budget--) { s->failed_pc=0x0c080e94u; return 0; }
r[0]=r[4];
goto P_0c080e96;
P_0c080e96: /* original 8801, guest PC 0x0c080e96 */
if(!s->budget--) { s->failed_pc=0x0c080e96u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c080e98;
P_0c080e98: /* original 8f01, guest PC 0x0c080e98 */
if(!s->budget--) { s->failed_pc=0x0c080e98u; return 0; }
cond=r[17]&1u;
r[13]=0x00000002u;
if(!cond) { goto P_0c080e9e; }
goto P_0c080e9c;
P_0c080e9a: /* original ed02, guest PC 0x0c080e9a */
if(!s->budget--) { s->failed_pc=0x0c080e9au; return 0; }
r[13]=0x00000002u;
goto P_0c080e9c;
P_0c080e9c: /* original ed2e, guest PC 0x0c080e9c */
if(!s->budget--) { s->failed_pc=0x0c080e9cu; return 0; }
r[13]=0x0000002eu;
goto P_0c080e9e;
P_0c080e9e: /* original e02b, guest PC 0x0c080e9e */
if(!s->budget--) { s->failed_pc=0x0c080e9eu; return 0; }
r[0]=0x0000002bu;
goto P_0c080ea0;
P_0c080ea0: /* original 6e53, guest PC 0x0c080ea0 */
if(!s->budget--) { s->failed_pc=0x0c080ea0u; return 0; }
r[14]=r[5];
goto P_0c080ea2;
P_0c080ea2: /* original 02ac, guest PC 0x0c080ea2 */
if(!s->budget--) { s->failed_pc=0x0c080ea2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c080ea4;
P_0c080ea4: /* original 65d3, guest PC 0x0c080ea4 */
if(!s->budget--) { s->failed_pc=0x0c080ea4u; return 0; }
r[5]=r[13];
goto P_0c080ea6;
P_0c080ea6: /* original 7502, guest PC 0x0c080ea6 */
if(!s->budget--) { s->failed_pc=0x0c080ea6u; return 0; }
r[5]+=0x00000002u;
goto P_0c080ea8;
P_0c080ea8: /* original 6023, guest PC 0x0c080ea8 */
if(!s->budget--) { s->failed_pc=0x0c080ea8u; return 0; }
r[0]=r[2];
goto P_0c080eaa;
P_0c080eaa: /* original 8809, guest PC 0x0c080eaa */
if(!s->budget--) { s->failed_pc=0x0c080eaau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c080eac;
P_0c080eac: /* original 2f22, guest PC 0x0c080eac */
if(!s->budget--) { s->failed_pc=0x0c080eacu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c080eae;
P_0c080eae: /* original 1f53, guest PC 0x0c080eae */
if(!s->budget--) { s->failed_pc=0x0c080eaeu; return 0; }
write(ram,r[15]+12,r[5],4);
goto P_0c080eb0;
P_0c080eb0: /* original 9c17, guest PC 0x0c080eb0 */
if(!s->budget--) { s->failed_pc=0x0c080eb0u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080ee2u,2);
goto P_0c080eb2;
P_0c080eb2: /* original d910, guest PC 0x0c080eb2 */
if(!s->budget--) { s->failed_pc=0x0c080eb2u; return 0; }
r[9]=read(ram,0x0c080ef4u,4);
goto P_0c080eb4;
P_0c080eb4: /* original 8f26, guest PC 0x0c080eb4 */
if(!s->budget--) { s->failed_pc=0x0c080eb4u; return 0; }
cond=r[17]&1u;
r[8]=0x00000000u;
if(!cond) { goto P_0c080f04; }
goto P_0c080eb8;
P_0c080eb6: /* original e800, guest PC 0x0c080eb6 */
if(!s->budget--) { s->failed_pc=0x0c080eb6u; return 0; }
r[8]=0x00000000u;
goto P_0c080eb8;
P_0c080eb8: /* original 6043, guest PC 0x0c080eb8 */
if(!s->budget--) { s->failed_pc=0x0c080eb8u; return 0; }
r[0]=r[4];
goto P_0c080eba;
P_0c080eba: /* original 8801, guest PC 0x0c080eba */
if(!s->budget--) { s->failed_pc=0x0c080ebau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c080ebc;
P_0c080ebc: /* original 8b00, guest PC 0x0c080ebc */
if(!s->budget--) { s->failed_pc=0x0c080ebcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c080ec0; }
goto P_0c080ebe;
P_0c080ebe: /* original 75fa, guest PC 0x0c080ebe */
if(!s->budget--) { s->failed_pc=0x0c080ebeu; return 0; }
r[5]+=0xfffffffau;
goto P_0c080ec0;
P_0c080ec0: /* original 4500, guest PC 0x0c080ec0 */
if(!s->budget--) { s->failed_pc=0x0c080ec0u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c080ec2;
P_0c080ec2: /* original 66e3, guest PC 0x0c080ec2 */
if(!s->budget--) { s->failed_pc=0x0c080ec2u; return 0; }
r[6]=r[14];
goto P_0c080ec4;
P_0c080ec4: /* original 25cb, guest PC 0x0c080ec4 */
if(!s->budget--) { s->failed_pc=0x0c080ec4u; return 0; }
r[5]|=r[12];
goto P_0c080ec6;
P_0c080ec6: /* original 1f53, guest PC 0x0c080ec6 */
if(!s->budget--) { s->failed_pc=0x0c080ec6u; return 0; }
write(ram,r[15]+12,r[5],4);
goto P_0c080ec8;
P_0c080ec8: /* original e700, guest PC 0x0c080ec8 */
if(!s->budget--) { s->failed_pc=0x0c080ec8u; return 0; }
r[7]=0x00000000u;
goto P_0c080eca;
P_0c080eca: /* original 2f86, guest PC 0x0c080eca */
if(!s->budget--) { s->failed_pc=0x0c080ecau; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080ecc;
P_0c080ecc: /* original 950a, guest PC 0x0c080ecc */
if(!s->budget--) { s->failed_pc=0x0c080eccu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080ee4u,2);
goto P_0c080ece;
P_0c080ece: /* original 490b, guest PC 0x0c080ece */
if(!s->budget--) { s->failed_pc=0x0c080eceu; return 0; }
target=r[9];
r[16]=code_base|0x0c080ed2u;
r[4]=read(ram,r[15]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080ed2u) { target=s->pc; goto dispatch; }
goto P_0c080ed2;
P_0c080ed0: /* original 54f4, guest PC 0x0c080ed0 */
if(!s->budget--) { s->failed_pc=0x0c080ed0u; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c080ed2;
P_0c080ed2: /* original a0cb, guest PC 0x0c080ed2 */
if(!s->budget--) { s->failed_pc=0x0c080ed2u; return 0; }
r[15]+=0x00000004u;
goto P_0c08106c;
P_0c080ed4: /* original 7f04, guest PC 0x0c080ed4 */
if(!s->budget--) { s->failed_pc=0x0c080ed4u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c080ed6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c080ed6u; return 0; } return 1;
P_0c080f04: /* original 4500, guest PC 0x0c080f04 */
if(!s->budget--) { s->failed_pc=0x0c080f04u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c080f06;
P_0c080f06: /* original 66e3, guest PC 0x0c080f06 */
if(!s->budget--) { s->failed_pc=0x0c080f06u; return 0; }
r[6]=r[14];
goto P_0c080f08;
P_0c080f08: /* original 25cb, guest PC 0x0c080f08 */
if(!s->budget--) { s->failed_pc=0x0c080f08u; return 0; }
r[5]|=r[12];
goto P_0c080f0a;
P_0c080f0a: /* original 1f51, guest PC 0x0c080f0a */
if(!s->budget--) { s->failed_pc=0x0c080f0au; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c080f0c;
P_0c080f0c: /* original e700, guest PC 0x0c080f0c */
if(!s->budget--) { s->failed_pc=0x0c080f0cu; return 0; }
r[7]=0x00000000u;
goto P_0c080f0e;
P_0c080f0e: /* original 2f86, guest PC 0x0c080f0e */
if(!s->budget--) { s->failed_pc=0x0c080f0eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080f10;
P_0c080f10: /* original 95b7, guest PC 0x0c080f10 */
if(!s->budget--) { s->failed_pc=0x0c080f10u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081082u,2);
goto P_0c080f12;
P_0c080f12: /* original 490b, guest PC 0x0c080f12 */
if(!s->budget--) { s->failed_pc=0x0c080f12u; return 0; }
target=r[9];
r[16]=code_base|0x0c080f16u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080f16u) { target=s->pc; goto dispatch; }
goto P_0c080f16;
P_0c080f14: /* original 54f2, guest PC 0x0c080f14 */
if(!s->budget--) { s->failed_pc=0x0c080f14u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c080f16;
P_0c080f16: /* original e50a, guest PC 0x0c080f16 */
if(!s->budget--) { s->failed_pc=0x0c080f16u; return 0; }
r[5]=0x0000000au;
goto P_0c080f18;
P_0c080f18: /* original 7f04, guest PC 0x0c080f18 */
if(!s->budget--) { s->failed_pc=0x0c080f18u; return 0; }
r[15]+=0x00000004u;
goto P_0c080f1a;
P_0c080f1a: /* original b0bd, guest PC 0x0c080f1a */
if(!s->budget--) { s->failed_pc=0x0c080f1au; return 0; }
target=code_base|0x0c081098u; r[16]=code_base|0x0c080f1eu;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080f1eu) { target=s->pc; goto dispatch; }
goto P_0c080f1e;
P_0c080f1c: /* original 64f3, guest PC 0x0c080f1c */
if(!s->budget--) { s->failed_pc=0x0c080f1cu; return 0; }
r[4]=r[15];
goto P_0c080f1e;
P_0c080f1e: /* original 64d3, guest PC 0x0c080f1e */
if(!s->budget--) { s->failed_pc=0x0c080f1eu; return 0; }
r[4]=r[13];
goto P_0c080f20;
P_0c080f20: /* original 740c, guest PC 0x0c080f20 */
if(!s->budget--) { s->failed_pc=0x0c080f20u; return 0; }
r[4]+=0x0000000cu;
goto P_0c080f22;
P_0c080f22: /* original 1f01, guest PC 0x0c080f22 */
if(!s->budget--) { s->failed_pc=0x0c080f22u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c080f24;
P_0c080f24: /* original 1f42, guest PC 0x0c080f24 */
if(!s->budget--) { s->failed_pc=0x0c080f24u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c080f26;
P_0c080f26: /* original 63f2, guest PC 0x0c080f26 */
if(!s->budget--) { s->failed_pc=0x0c080f26u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c080f28;
P_0c080f28: /* original 2338, guest PC 0x0c080f28 */
if(!s->budget--) { s->failed_pc=0x0c080f28u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c080f2a;
P_0c080f2a: /* original 8b01, guest PC 0x0c080f2a */
if(!s->budget--) { s->failed_pc=0x0c080f2au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c080f30; }
goto P_0c080f2c;
P_0c080f2c: /* original 64d3, guest PC 0x0c080f2c */
if(!s->budget--) { s->failed_pc=0x0c080f2cu; return 0; }
r[4]=r[13];
goto P_0c080f2e;
P_0c080f2e: /* original 740b, guest PC 0x0c080f2e */
if(!s->budget--) { s->failed_pc=0x0c080f2eu; return 0; }
r[4]+=0x0000000bu;
goto P_0c080f30;
P_0c080f30: /* original 4400, guest PC 0x0c080f30 */
if(!s->budget--) { s->failed_pc=0x0c080f30u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c080f32;
P_0c080f32: /* original 24cb, guest PC 0x0c080f32 */
if(!s->budget--) { s->failed_pc=0x0c080f32u; return 0; }
r[4]|=r[12];
goto P_0c080f34;
P_0c080f34: /* original 6543, guest PC 0x0c080f34 */
if(!s->budget--) { s->failed_pc=0x0c080f34u; return 0; }
r[5]=r[4];
goto P_0c080f36;
P_0c080f36: /* original 1f44, guest PC 0x0c080f36 */
if(!s->budget--) { s->failed_pc=0x0c080f36u; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c080f38;
P_0c080f38: /* original 97a4, guest PC 0x0c080f38 */
if(!s->budget--) { s->failed_pc=0x0c080f38u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081084u,2);
goto P_0c080f3a;
P_0c080f3a: /* original 56f1, guest PC 0x0c080f3a */
if(!s->budget--) { s->failed_pc=0x0c080f3au; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c080f3c;
P_0c080f3c: /* original db55, guest PC 0x0c080f3c */
if(!s->budget--) { s->failed_pc=0x0c080f3cu; return 0; }
r[11]=read(ram,0x0c081094u,4);
goto P_0c080f3e;
P_0c080f3e: /* original 4b0b, guest PC 0x0c080f3e */
if(!s->budget--) { s->failed_pc=0x0c080f3eu; return 0; }
target=r[11];
r[16]=code_base|0x0c080f42u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080f42u) { target=s->pc; goto dispatch; }
goto P_0c080f42;
P_0c080f40: /* original 64e3, guest PC 0x0c080f40 */
if(!s->budget--) { s->failed_pc=0x0c080f40u; return 0; }
r[4]=r[14];
goto P_0c080f42;
P_0c080f42: /* original 63d3, guest PC 0x0c080f42 */
if(!s->budget--) { s->failed_pc=0x0c080f42u; return 0; }
r[3]=r[13];
goto P_0c080f44;
P_0c080f44: /* original 730a, guest PC 0x0c080f44 */
if(!s->budget--) { s->failed_pc=0x0c080f44u; return 0; }
r[3]+=0x0000000au;
goto P_0c080f46;
P_0c080f46: /* original 1f31, guest PC 0x0c080f46 */
if(!s->budget--) { s->failed_pc=0x0c080f46u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c080f48;
P_0c080f48: /* original 62f2, guest PC 0x0c080f48 */
if(!s->budget--) { s->failed_pc=0x0c080f48u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c080f4a;
P_0c080f4a: /* original 2228, guest PC 0x0c080f4a */
if(!s->budget--) { s->failed_pc=0x0c080f4au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c080f4c;
P_0c080f4c: /* original 8909, guest PC 0x0c080f4c */
if(!s->budget--) { s->failed_pc=0x0c080f4cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c080f62; }
goto P_0c080f4e;
P_0c080f4e: /* original 6233, guest PC 0x0c080f4e */
if(!s->budget--) { s->failed_pc=0x0c080f4eu; return 0; }
r[2]=r[3];
goto P_0c080f50;
P_0c080f50: /* original 4200, guest PC 0x0c080f50 */
if(!s->budget--) { s->failed_pc=0x0c080f50u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c080f52;
P_0c080f52: /* original 22cb, guest PC 0x0c080f52 */
if(!s->budget--) { s->failed_pc=0x0c080f52u; return 0; }
r[2]|=r[12];
goto P_0c080f54;
P_0c080f54: /* original 1f31, guest PC 0x0c080f54 */
if(!s->budget--) { s->failed_pc=0x0c080f54u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c080f56;
P_0c080f56: /* original 6523, guest PC 0x0c080f56 */
if(!s->budget--) { s->failed_pc=0x0c080f56u; return 0; }
r[5]=r[2];
goto P_0c080f58;
P_0c080f58: /* original 1f24, guest PC 0x0c080f58 */
if(!s->budget--) { s->failed_pc=0x0c080f58u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c080f5a;
P_0c080f5a: /* original 9793, guest PC 0x0c080f5a */
if(!s->budget--) { s->failed_pc=0x0c080f5au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081084u,2);
goto P_0c080f5c;
P_0c080f5c: /* original 66f2, guest PC 0x0c080f5c */
if(!s->budget--) { s->failed_pc=0x0c080f5cu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c080f5e;
P_0c080f5e: /* original 4b0b, guest PC 0x0c080f5e */
if(!s->budget--) { s->failed_pc=0x0c080f5eu; return 0; }
target=r[11];
r[16]=code_base|0x0c080f62u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080f62u) { target=s->pc; goto dispatch; }
goto P_0c080f62;
P_0c080f60: /* original 64e3, guest PC 0x0c080f60 */
if(!s->budget--) { s->failed_pc=0x0c080f60u; return 0; }
r[4]=r[14];
goto P_0c080f62;
P_0c080f62: /* original 9390, guest PC 0x0c080f62 */
if(!s->budget--) { s->failed_pc=0x0c080f62u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081086u,2);
goto P_0c080f64;
P_0c080f64: /* original 64d3, guest PC 0x0c080f64 */
if(!s->budget--) { s->failed_pc=0x0c080f64u; return 0; }
r[4]=r[13];
goto P_0c080f66;
P_0c080f66: /* original 4400, guest PC 0x0c080f66 */
if(!s->budget--) { s->failed_pc=0x0c080f66u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c080f68;
P_0c080f68: /* original 66e3, guest PC 0x0c080f68 */
if(!s->budget--) { s->failed_pc=0x0c080f68u; return 0; }
r[6]=r[14];
goto P_0c080f6a;
P_0c080f6a: /* original 243b, guest PC 0x0c080f6a */
if(!s->budget--) { s->failed_pc=0x0c080f6au; return 0; }
r[4]|=r[3];
goto P_0c080f6c;
P_0c080f6c: /* original 1f44, guest PC 0x0c080f6c */
if(!s->budget--) { s->failed_pc=0x0c080f6cu; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c080f6e;
P_0c080f6e: /* original e700, guest PC 0x0c080f6e */
if(!s->budget--) { s->failed_pc=0x0c080f6eu; return 0; }
r[7]=0x00000000u;
goto P_0c080f70;
P_0c080f70: /* original 2f86, guest PC 0x0c080f70 */
if(!s->budget--) { s->failed_pc=0x0c080f70u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080f72;
P_0c080f72: /* original 9589, guest PC 0x0c080f72 */
if(!s->budget--) { s->failed_pc=0x0c080f72u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081088u,2);
goto P_0c080f74;
P_0c080f74: /* original 490b, guest PC 0x0c080f74 */
if(!s->budget--) { s->failed_pc=0x0c080f74u; return 0; }
target=r[9];
r[16]=code_base|0x0c080f78u;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080f78u) { target=s->pc; goto dispatch; }
goto P_0c080f78;
P_0c080f76: /* original 54f5, guest PC 0x0c080f76 */
if(!s->budget--) { s->failed_pc=0x0c080f76u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c080f78;
P_0c080f78: /* original 64d3, guest PC 0x0c080f78 */
if(!s->budget--) { s->failed_pc=0x0c080f78u; return 0; }
r[4]=r[13];
goto P_0c080f7a;
P_0c080f7a: /* original 9c86, guest PC 0x0c080f7a */
if(!s->budget--) { s->failed_pc=0x0c080f7au; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08108au,2);
goto P_0c080f7c;
P_0c080f7c: /* original 7409, guest PC 0x0c080f7c */
if(!s->budget--) { s->failed_pc=0x0c080f7cu; return 0; }
r[4]+=0x00000009u;
goto P_0c080f7e;
P_0c080f7e: /* original 66e3, guest PC 0x0c080f7e */
if(!s->budget--) { s->failed_pc=0x0c080f7eu; return 0; }
r[6]=r[14];
goto P_0c080f80;
P_0c080f80: /* original 4400, guest PC 0x0c080f80 */
if(!s->budget--) { s->failed_pc=0x0c080f80u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c080f82;
P_0c080f82: /* original 24cb, guest PC 0x0c080f82 */
if(!s->budget--) { s->failed_pc=0x0c080f82u; return 0; }
r[4]|=r[12];
goto P_0c080f84;
P_0c080f84: /* original 1f45, guest PC 0x0c080f84 */
if(!s->budget--) { s->failed_pc=0x0c080f84u; return 0; }
write(ram,r[15]+20,r[4],4);
goto P_0c080f86;
P_0c080f86: /* original e700, guest PC 0x0c080f86 */
if(!s->budget--) { s->failed_pc=0x0c080f86u; return 0; }
r[7]=0x00000000u;
goto P_0c080f88;
P_0c080f88: /* original 2f86, guest PC 0x0c080f88 */
if(!s->budget--) { s->failed_pc=0x0c080f88u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080f8a;
P_0c080f8a: /* original 957f, guest PC 0x0c080f8a */
if(!s->budget--) { s->failed_pc=0x0c080f8au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08108cu,2);
goto P_0c080f8c;
P_0c080f8c: /* original 490b, guest PC 0x0c080f8c */
if(!s->budget--) { s->failed_pc=0x0c080f8cu; return 0; }
target=r[9];
r[16]=code_base|0x0c080f90u;
r[4]=read(ram,r[15]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080f90u) { target=s->pc; goto dispatch; }
goto P_0c080f90;
P_0c080f8e: /* original 54f6, guest PC 0x0c080f8e */
if(!s->budget--) { s->failed_pc=0x0c080f8eu; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c080f90;
P_0c080f90: /* original 53ad, guest PC 0x0c080f90 */
if(!s->budget--) { s->failed_pc=0x0c080f90u; return 0; }
r[3]=read(ram,r[10]+52,4);
goto P_0c080f92;
P_0c080f92: /* original 7f08, guest PC 0x0c080f92 */
if(!s->budget--) { s->failed_pc=0x0c080f92u; return 0; }
r[15]+=0x00000008u;
goto P_0c080f94;
P_0c080f94: /* original e50a, guest PC 0x0c080f94 */
if(!s->budget--) { s->failed_pc=0x0c080f94u; return 0; }
r[5]=0x0000000au;
goto P_0c080f96;
P_0c080f96: /* original 2f32, guest PC 0x0c080f96 */
if(!s->budget--) { s->failed_pc=0x0c080f96u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c080f98;
P_0c080f98: /* original 54ae, guest PC 0x0c080f98 */
if(!s->budget--) { s->failed_pc=0x0c080f98u; return 0; }
r[4]=read(ram,r[10]+56,4);
goto P_0c080f9a;
P_0c080f9a: /* original 343c, guest PC 0x0c080f9a */
if(!s->budget--) { s->failed_pc=0x0c080f9au; return 0; }
r[4]+=r[3];
goto P_0c080f9c;
P_0c080f9c: /* original 6243, guest PC 0x0c080f9c */
if(!s->budget--) { s->failed_pc=0x0c080f9cu; return 0; }
r[2]=r[4];
goto P_0c080f9e;
P_0c080f9e: /* original e364, guest PC 0x0c080f9e */
if(!s->budget--) { s->failed_pc=0x0c080f9eu; return 0; }
r[3]=0x00000064u;
goto P_0c080fa0;
P_0c080fa0: /* original 0237, guest PC 0x0c080fa0 */
if(!s->budget--) { s->failed_pc=0x0c080fa0u; return 0; }
r[19]=r[2]*r[3];
goto P_0c080fa2;
P_0c080fa2: /* original e2fa, guest PC 0x0c080fa2 */
if(!s->budget--) { s->failed_pc=0x0c080fa2u; return 0; }
r[2]=0xfffffffau;
goto P_0c080fa4;
P_0c080fa4: /* original 031a, guest PC 0x0c080fa4 */
if(!s->budget--) { s->failed_pc=0x0c080fa4u; return 0; }
r[3]=r[19];
goto P_0c080fa6;
P_0c080fa6: /* original 432c, guest PC 0x0c080fa6 */
if(!s->budget--) { s->failed_pc=0x0c080fa6u; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c080fa8;
P_0c080fa8: /* original 2f32, guest PC 0x0c080fa8 */
if(!s->budget--) { s->failed_pc=0x0c080fa8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c080faa;
P_0c080faa: /* original b075, guest PC 0x0c080faa */
if(!s->budget--) { s->failed_pc=0x0c080faau; return 0; }
target=code_base|0x0c081098u; r[16]=code_base|0x0c080faeu;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080faeu) { target=s->pc; goto dispatch; }
goto P_0c080fae;
P_0c080fac: /* original 64f3, guest PC 0x0c080fac */
if(!s->budget--) { s->failed_pc=0x0c080facu; return 0; }
r[4]=r[15];
goto P_0c080fae;
P_0c080fae: /* original 1f04, guest PC 0x0c080fae */
if(!s->budget--) { s->failed_pc=0x0c080faeu; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c080fb0;
P_0c080fb0: /* original 53f2, guest PC 0x0c080fb0 */
if(!s->budget--) { s->failed_pc=0x0c080fb0u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c080fb2;
P_0c080fb2: /* original 4300, guest PC 0x0c080fb2 */
if(!s->budget--) { s->failed_pc=0x0c080fb2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c080fb4;
P_0c080fb4: /* original 23cb, guest PC 0x0c080fb4 */
if(!s->budget--) { s->failed_pc=0x0c080fb4u; return 0; }
r[3]|=r[12];
goto P_0c080fb6;
P_0c080fb6: /* original 6533, guest PC 0x0c080fb6 */
if(!s->budget--) { s->failed_pc=0x0c080fb6u; return 0; }
r[5]=r[3];
goto P_0c080fb8;
P_0c080fb8: /* original 1f32, guest PC 0x0c080fb8 */
if(!s->budget--) { s->failed_pc=0x0c080fb8u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c080fba;
P_0c080fba: /* original 9a68, guest PC 0x0c080fba */
if(!s->budget--) { s->failed_pc=0x0c080fbau; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08108eu,2);
goto P_0c080fbc;
P_0c080fbc: /* original 56f4, guest PC 0x0c080fbc */
if(!s->budget--) { s->failed_pc=0x0c080fbcu; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c080fbe;
P_0c080fbe: /* original 67a3, guest PC 0x0c080fbe */
if(!s->budget--) { s->failed_pc=0x0c080fbeu; return 0; }
r[7]=r[10];
goto P_0c080fc0;
P_0c080fc0: /* original 4b0b, guest PC 0x0c080fc0 */
if(!s->budget--) { s->failed_pc=0x0c080fc0u; return 0; }
target=r[11];
r[16]=code_base|0x0c080fc4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080fc4u) { target=s->pc; goto dispatch; }
goto P_0c080fc4;
P_0c080fc2: /* original 64e3, guest PC 0x0c080fc2 */
if(!s->budget--) { s->failed_pc=0x0c080fc2u; return 0; }
r[4]=r[14];
goto P_0c080fc4;
P_0c080fc4: /* original e50a, guest PC 0x0c080fc4 */
if(!s->budget--) { s->failed_pc=0x0c080fc4u; return 0; }
r[5]=0x0000000au;
goto P_0c080fc6;
P_0c080fc6: /* original b067, guest PC 0x0c080fc6 */
if(!s->budget--) { s->failed_pc=0x0c080fc6u; return 0; }
target=code_base|0x0c081098u; r[16]=code_base|0x0c080fcau;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080fcau) { target=s->pc; goto dispatch; }
goto P_0c080fca;
P_0c080fc8: /* original 64f3, guest PC 0x0c080fc8 */
if(!s->budget--) { s->failed_pc=0x0c080fc8u; return 0; }
r[4]=r[15];
goto P_0c080fca;
P_0c080fca: /* original 1f02, guest PC 0x0c080fca */
if(!s->budget--) { s->failed_pc=0x0c080fcau; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c080fcc;
P_0c080fcc: /* original 67a3, guest PC 0x0c080fcc */
if(!s->budget--) { s->failed_pc=0x0c080fccu; return 0; }
r[7]=r[10];
goto P_0c080fce;
P_0c080fce: /* original 53f1, guest PC 0x0c080fce */
if(!s->budget--) { s->failed_pc=0x0c080fceu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c080fd0;
P_0c080fd0: /* original 4300, guest PC 0x0c080fd0 */
if(!s->budget--) { s->failed_pc=0x0c080fd0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c080fd2;
P_0c080fd2: /* original 23cb, guest PC 0x0c080fd2 */
if(!s->budget--) { s->failed_pc=0x0c080fd2u; return 0; }
r[3]|=r[12];
goto P_0c080fd4;
P_0c080fd4: /* original 6533, guest PC 0x0c080fd4 */
if(!s->budget--) { s->failed_pc=0x0c080fd4u; return 0; }
r[5]=r[3];
goto P_0c080fd6;
P_0c080fd6: /* original 1f31, guest PC 0x0c080fd6 */
if(!s->budget--) { s->failed_pc=0x0c080fd6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c080fd8;
P_0c080fd8: /* original 56f2, guest PC 0x0c080fd8 */
if(!s->budget--) { s->failed_pc=0x0c080fd8u; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c080fda;
P_0c080fda: /* original 4b0b, guest PC 0x0c080fda */
if(!s->budget--) { s->failed_pc=0x0c080fdau; return 0; }
target=r[11];
r[16]=code_base|0x0c080fdeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080fdeu) { target=s->pc; goto dispatch; }
goto P_0c080fde;
P_0c080fdc: /* original 64e3, guest PC 0x0c080fdc */
if(!s->budget--) { s->failed_pc=0x0c080fdcu; return 0; }
r[4]=r[14];
goto P_0c080fde;
P_0c080fde: /* original e50a, guest PC 0x0c080fde */
if(!s->budget--) { s->failed_pc=0x0c080fdeu; return 0; }
r[5]=0x0000000au;
goto P_0c080fe0;
P_0c080fe0: /* original b05a, guest PC 0x0c080fe0 */
if(!s->budget--) { s->failed_pc=0x0c080fe0u; return 0; }
target=code_base|0x0c081098u; r[16]=code_base|0x0c080fe4u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080fe4u) { target=s->pc; goto dispatch; }
goto P_0c080fe4;
P_0c080fe2: /* original 64f3, guest PC 0x0c080fe2 */
if(!s->budget--) { s->failed_pc=0x0c080fe2u; return 0; }
r[4]=r[15];
goto P_0c080fe4;
P_0c080fe4: /* original 64d3, guest PC 0x0c080fe4 */
if(!s->budget--) { s->failed_pc=0x0c080fe4u; return 0; }
r[4]=r[13];
goto P_0c080fe6;
P_0c080fe6: /* original 7407, guest PC 0x0c080fe6 */
if(!s->budget--) { s->failed_pc=0x0c080fe6u; return 0; }
r[4]+=0x00000007u;
goto P_0c080fe8;
P_0c080fe8: /* original 4400, guest PC 0x0c080fe8 */
if(!s->budget--) { s->failed_pc=0x0c080fe8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c080fea;
P_0c080fea: /* original 1f01, guest PC 0x0c080fea */
if(!s->budget--) { s->failed_pc=0x0c080feau; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c080fec;
P_0c080fec: /* original 24cb, guest PC 0x0c080fec */
if(!s->budget--) { s->failed_pc=0x0c080fecu; return 0; }
r[4]|=r[12];
goto P_0c080fee;
P_0c080fee: /* original 67a3, guest PC 0x0c080fee */
if(!s->budget--) { s->failed_pc=0x0c080feeu; return 0; }
r[7]=r[10];
goto P_0c080ff0;
P_0c080ff0: /* original 6543, guest PC 0x0c080ff0 */
if(!s->budget--) { s->failed_pc=0x0c080ff0u; return 0; }
r[5]=r[4];
goto P_0c080ff2;
P_0c080ff2: /* original 1f42, guest PC 0x0c080ff2 */
if(!s->budget--) { s->failed_pc=0x0c080ff2u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c080ff4;
P_0c080ff4: /* original 56f1, guest PC 0x0c080ff4 */
if(!s->budget--) { s->failed_pc=0x0c080ff4u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c080ff6;
P_0c080ff6: /* original 4b0b, guest PC 0x0c080ff6 */
if(!s->budget--) { s->failed_pc=0x0c080ff6u; return 0; }
target=r[11];
r[16]=code_base|0x0c080ffau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080ffau) { target=s->pc; goto dispatch; }
goto P_0c080ffa;
P_0c080ff8: /* original 64e3, guest PC 0x0c080ff8 */
if(!s->budget--) { s->failed_pc=0x0c080ff8u; return 0; }
r[4]=r[14];
goto P_0c080ffa;
P_0c080ffa: /* original 63f2, guest PC 0x0c080ffa */
if(!s->budget--) { s->failed_pc=0x0c080ffau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c080ffc;
P_0c080ffc: /* original 2338, guest PC 0x0c080ffc */
if(!s->budget--) { s->failed_pc=0x0c080ffcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c080ffe;
P_0c080ffe: /* original 8935, guest PC 0x0c080ffe */
if(!s->budget--) { s->failed_pc=0x0c080ffeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08106c; }
goto P_0c081000;
P_0c081000: /* original e506, guest PC 0x0c081000 */
if(!s->budget--) { s->failed_pc=0x0c081000u; return 0; }
r[5]=0x00000006u;
goto P_0c081002;
P_0c081002: /* original b049, guest PC 0x0c081002 */
if(!s->budget--) { s->failed_pc=0x0c081002u; return 0; }
target=code_base|0x0c081098u; r[16]=code_base|0x0c081006u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081006u) { target=s->pc; goto dispatch; }
goto P_0c081006;
P_0c081004: /* original 64f3, guest PC 0x0c081004 */
if(!s->budget--) { s->failed_pc=0x0c081004u; return 0; }
r[4]=r[15];
goto P_0c081006;
P_0c081006: /* original 64d3, guest PC 0x0c081006 */
if(!s->budget--) { s->failed_pc=0x0c081006u; return 0; }
r[4]=r[13];
goto P_0c081008;
P_0c081008: /* original 7405, guest PC 0x0c081008 */
if(!s->budget--) { s->failed_pc=0x0c081008u; return 0; }
r[4]+=0x00000005u;
goto P_0c08100a;
P_0c08100a: /* original 4400, guest PC 0x0c08100a */
if(!s->budget--) { s->failed_pc=0x0c08100au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08100c;
P_0c08100c: /* original 1f01, guest PC 0x0c08100c */
if(!s->budget--) { s->failed_pc=0x0c08100cu; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c08100e;
P_0c08100e: /* original 24cb, guest PC 0x0c08100e */
if(!s->budget--) { s->failed_pc=0x0c08100eu; return 0; }
r[4]|=r[12];
goto P_0c081010;
P_0c081010: /* original 67a3, guest PC 0x0c081010 */
if(!s->budget--) { s->failed_pc=0x0c081010u; return 0; }
r[7]=r[10];
goto P_0c081012;
P_0c081012: /* original 6543, guest PC 0x0c081012 */
if(!s->budget--) { s->failed_pc=0x0c081012u; return 0; }
r[5]=r[4];
goto P_0c081014;
P_0c081014: /* original 1f42, guest PC 0x0c081014 */
if(!s->budget--) { s->failed_pc=0x0c081014u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c081016;
P_0c081016: /* original 56f1, guest PC 0x0c081016 */
if(!s->budget--) { s->failed_pc=0x0c081016u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c081018;
P_0c081018: /* original 4b0b, guest PC 0x0c081018 */
if(!s->budget--) { s->failed_pc=0x0c081018u; return 0; }
target=r[11];
r[16]=code_base|0x0c08101cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08101cu) { target=s->pc; goto dispatch; }
goto P_0c08101c;
P_0c08101a: /* original 64e3, guest PC 0x0c08101a */
if(!s->budget--) { s->failed_pc=0x0c08101au; return 0; }
r[4]=r[14];
goto P_0c08101c;
P_0c08101c: /* original 63f2, guest PC 0x0c08101c */
if(!s->budget--) { s->failed_pc=0x0c08101cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c08101e;
P_0c08101e: /* original 2338, guest PC 0x0c08101e */
if(!s->budget--) { s->failed_pc=0x0c08101eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c081020;
P_0c081020: /* original 8924, guest PC 0x0c081020 */
if(!s->budget--) { s->failed_pc=0x0c081020u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08106c; }
goto P_0c081022;
P_0c081022: /* original 64d3, guest PC 0x0c081022 */
if(!s->budget--) { s->failed_pc=0x0c081022u; return 0; }
r[4]=r[13];
goto P_0c081024;
P_0c081024: /* original 7404, guest PC 0x0c081024 */
if(!s->budget--) { s->failed_pc=0x0c081024u; return 0; }
r[4]+=0x00000004u;
goto P_0c081026;
P_0c081026: /* original 4400, guest PC 0x0c081026 */
if(!s->budget--) { s->failed_pc=0x0c081026u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c081028;
P_0c081028: /* original 66e3, guest PC 0x0c081028 */
if(!s->budget--) { s->failed_pc=0x0c081028u; return 0; }
r[6]=r[14];
goto P_0c08102a;
P_0c08102a: /* original 24cb, guest PC 0x0c08102a */
if(!s->budget--) { s->failed_pc=0x0c08102au; return 0; }
r[4]|=r[12];
goto P_0c08102c;
P_0c08102c: /* original 1f41, guest PC 0x0c08102c */
if(!s->budget--) { s->failed_pc=0x0c08102cu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c08102e;
P_0c08102e: /* original e700, guest PC 0x0c08102e */
if(!s->budget--) { s->failed_pc=0x0c08102eu; return 0; }
r[7]=0x00000000u;
goto P_0c081030;
P_0c081030: /* original 2f86, guest PC 0x0c081030 */
if(!s->budget--) { s->failed_pc=0x0c081030u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c081032;
P_0c081032: /* original 952d, guest PC 0x0c081032 */
if(!s->budget--) { s->failed_pc=0x0c081032u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081090u,2);
goto P_0c081034;
P_0c081034: /* original 490b, guest PC 0x0c081034 */
if(!s->budget--) { s->failed_pc=0x0c081034u; return 0; }
target=r[9];
r[16]=code_base|0x0c081038u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081038u) { target=s->pc; goto dispatch; }
goto P_0c081038;
P_0c081036: /* original 54f2, guest PC 0x0c081036 */
if(!s->budget--) { s->failed_pc=0x0c081036u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c081038;
P_0c081038: /* original e50a, guest PC 0x0c081038 */
if(!s->budget--) { s->failed_pc=0x0c081038u; return 0; }
r[5]=0x0000000au;
goto P_0c08103a;
P_0c08103a: /* original 7f04, guest PC 0x0c08103a */
if(!s->budget--) { s->failed_pc=0x0c08103au; return 0; }
r[15]+=0x00000004u;
goto P_0c08103c;
P_0c08103c: /* original b02c, guest PC 0x0c08103c */
if(!s->budget--) { s->failed_pc=0x0c08103cu; return 0; }
target=code_base|0x0c081098u; r[16]=code_base|0x0c081040u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081040u) { target=s->pc; goto dispatch; }
goto P_0c081040;
P_0c08103e: /* original 64f3, guest PC 0x0c08103e */
if(!s->budget--) { s->failed_pc=0x0c08103eu; return 0; }
r[4]=r[15];
goto P_0c081040;
P_0c081040: /* original 1f01, guest PC 0x0c081040 */
if(!s->budget--) { s->failed_pc=0x0c081040u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c081042;
P_0c081042: /* original 67a3, guest PC 0x0c081042 */
if(!s->budget--) { s->failed_pc=0x0c081042u; return 0; }
r[7]=r[10];
goto P_0c081044;
P_0c081044: /* original 53f3, guest PC 0x0c081044 */
if(!s->budget--) { s->failed_pc=0x0c081044u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c081046;
P_0c081046: /* original 4300, guest PC 0x0c081046 */
if(!s->budget--) { s->failed_pc=0x0c081046u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c081048;
P_0c081048: /* original 23cb, guest PC 0x0c081048 */
if(!s->budget--) { s->failed_pc=0x0c081048u; return 0; }
r[3]|=r[12];
goto P_0c08104a;
P_0c08104a: /* original 6533, guest PC 0x0c08104a */
if(!s->budget--) { s->failed_pc=0x0c08104au; return 0; }
r[5]=r[3];
goto P_0c08104c;
P_0c08104c: /* original 1f33, guest PC 0x0c08104c */
if(!s->budget--) { s->failed_pc=0x0c08104cu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c08104e;
P_0c08104e: /* original 56f1, guest PC 0x0c08104e */
if(!s->budget--) { s->failed_pc=0x0c08104eu; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c081050;
P_0c081050: /* original 4b0b, guest PC 0x0c081050 */
if(!s->budget--) { s->failed_pc=0x0c081050u; return 0; }
target=r[11];
r[16]=code_base|0x0c081054u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081054u) { target=s->pc; goto dispatch; }
goto P_0c081054;
P_0c081052: /* original 64e3, guest PC 0x0c081052 */
if(!s->budget--) { s->failed_pc=0x0c081052u; return 0; }
r[4]=r[14];
goto P_0c081054;
P_0c081054: /* original 63f2, guest PC 0x0c081054 */
if(!s->budget--) { s->failed_pc=0x0c081054u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c081056;
P_0c081056: /* original 2338, guest PC 0x0c081056 */
if(!s->budget--) { s->failed_pc=0x0c081056u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c081058;
P_0c081058: /* original 8908, guest PC 0x0c081058 */
if(!s->budget--) { s->failed_pc=0x0c081058u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08106c; }
goto P_0c08105a;
P_0c08105a: /* original 64d3, guest PC 0x0c08105a */
if(!s->budget--) { s->failed_pc=0x0c08105au; return 0; }
r[4]=r[13];
goto P_0c08105c;
P_0c08105c: /* original 4400, guest PC 0x0c08105c */
if(!s->budget--) { s->failed_pc=0x0c08105cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08105e;
P_0c08105e: /* original 24cb, guest PC 0x0c08105e */
if(!s->budget--) { s->failed_pc=0x0c08105eu; return 0; }
r[4]|=r[12];
goto P_0c081060;
P_0c081060: /* original 67a3, guest PC 0x0c081060 */
if(!s->budget--) { s->failed_pc=0x0c081060u; return 0; }
r[7]=r[10];
goto P_0c081062;
P_0c081062: /* original 6543, guest PC 0x0c081062 */
if(!s->budget--) { s->failed_pc=0x0c081062u; return 0; }
r[5]=r[4];
goto P_0c081064;
P_0c081064: /* original 1f43, guest PC 0x0c081064 */
if(!s->budget--) { s->failed_pc=0x0c081064u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c081066;
P_0c081066: /* original 66f2, guest PC 0x0c081066 */
if(!s->budget--) { s->failed_pc=0x0c081066u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c081068;
P_0c081068: /* original 4b0b, guest PC 0x0c081068 */
if(!s->budget--) { s->failed_pc=0x0c081068u; return 0; }
target=r[11];
r[16]=code_base|0x0c08106cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08106cu) { target=s->pc; goto dispatch; }
goto P_0c08106c;
P_0c08106a: /* original 64e3, guest PC 0x0c08106a */
if(!s->budget--) { s->failed_pc=0x0c08106au; return 0; }
r[4]=r[14];
goto P_0c08106c;
P_0c08106c: /* original 7f14, guest PC 0x0c08106c */
if(!s->budget--) { s->failed_pc=0x0c08106cu; return 0; }
r[15]+=0x00000014u;
goto P_0c08106e;
P_0c08106e: /* original 4f16, guest PC 0x0c08106e */
if(!s->budget--) { s->failed_pc=0x0c08106eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c081070;
P_0c081070: /* original 4f26, guest PC 0x0c081070 */
if(!s->budget--) { s->failed_pc=0x0c081070u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c081072;
P_0c081072: /* original 68f6, guest PC 0x0c081072 */
if(!s->budget--) { s->failed_pc=0x0c081072u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c081074;
P_0c081074: /* original 69f6, guest PC 0x0c081074 */
if(!s->budget--) { s->failed_pc=0x0c081074u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c081076;
P_0c081076: /* original 6af6, guest PC 0x0c081076 */
if(!s->budget--) { s->failed_pc=0x0c081076u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c081078;
P_0c081078: /* original 6bf6, guest PC 0x0c081078 */
if(!s->budget--) { s->failed_pc=0x0c081078u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08107a;
P_0c08107a: /* original 6cf6, guest PC 0x0c08107a */
if(!s->budget--) { s->failed_pc=0x0c08107au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08107c;
P_0c08107c: /* original 6df6, guest PC 0x0c08107c */
if(!s->budget--) { s->failed_pc=0x0c08107cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08107e;
P_0c08107e: /* original 000b, guest PC 0x0c08107e */
if(!s->budget--) { s->failed_pc=0x0c08107eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c081080: /* original 6ef6, guest PC 0x0c081080 */
if(!s->budget--) { s->failed_pc=0x0c081080u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c081082u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c081082u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
