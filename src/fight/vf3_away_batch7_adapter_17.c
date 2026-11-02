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
int vf3_away_batch7_adapter_17(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05fcc4u: goto P_0c05fcc4;
case 0x0c05fcc6u: goto P_0c05fcc6;
case 0x0c05fcc8u: goto P_0c05fcc8;
case 0x0c05fccau: goto P_0c05fcca;
case 0x0c05fcccu: goto P_0c05fccc;
case 0x0c05fcceu: goto P_0c05fcce;
case 0x0c060d14u: goto P_0c060d14;
case 0x0c060d16u: goto P_0c060d16;
case 0x0c060d18u: goto P_0c060d18;
case 0x0c060d1au: goto P_0c060d1a;
case 0x0c060d1cu: goto P_0c060d1c;
case 0x0c060d46u: goto P_0c060d46;
case 0x0c060d48u: goto P_0c060d48;
case 0x0c060d4au: goto P_0c060d4a;
case 0x0c061168u: goto P_0c061168;
case 0x0c06116au: goto P_0c06116a;
case 0x0c06116cu: goto P_0c06116c;
case 0x0c06116eu: goto P_0c06116e;
case 0x0c061170u: goto P_0c061170;
case 0x0c061172u: goto P_0c061172;
case 0x0c061174u: goto P_0c061174;
case 0x0c061176u: goto P_0c061176;
case 0x0c061178u: goto P_0c061178;
case 0x0c06117au: goto P_0c06117a;
case 0x0c06117cu: goto P_0c06117c;
case 0x0c06117eu: goto P_0c06117e;
case 0x0c061180u: goto P_0c061180;
case 0x0c061182u: goto P_0c061182;
case 0x0c061184u: goto P_0c061184;
case 0x0c061186u: goto P_0c061186;
case 0x0c061188u: goto P_0c061188;
case 0x0c06118au: goto P_0c06118a;
case 0x0c06118cu: goto P_0c06118c;
case 0x0c06118eu: goto P_0c06118e;
case 0x0c061190u: goto P_0c061190;
case 0x0c061192u: goto P_0c061192;
case 0x0c061194u: goto P_0c061194;
case 0x0c061196u: goto P_0c061196;
case 0x0c061198u: goto P_0c061198;
case 0x0c06119au: goto P_0c06119a;
case 0x0c06119cu: goto P_0c06119c;
case 0x0c06119eu: goto P_0c06119e;
case 0x0c0611a0u: goto P_0c0611a0;
case 0x0c0611a2u: goto P_0c0611a2;
case 0x0c0611a4u: goto P_0c0611a4;
case 0x0c0611a6u: goto P_0c0611a6;
case 0x0c0611a8u: goto P_0c0611a8;
case 0x0c0611aau: goto P_0c0611aa;
case 0x0c0611acu: goto P_0c0611ac;
case 0x0c0611aeu: goto P_0c0611ae;
case 0x0c0611b0u: goto P_0c0611b0;
case 0x0c0611b2u: goto P_0c0611b2;
case 0x0c0611b4u: goto P_0c0611b4;
case 0x0c0611b6u: goto P_0c0611b6;
case 0x0c0611b8u: goto P_0c0611b8;
case 0x0c0611bau: goto P_0c0611ba;
case 0x0c0611bcu: goto P_0c0611bc;
case 0x0c0611beu: goto P_0c0611be;
case 0x0c0611c0u: goto P_0c0611c0;
case 0x0c0611c2u: goto P_0c0611c2;
case 0x0c0611c4u: goto P_0c0611c4;
case 0x0c0611c6u: goto P_0c0611c6;
case 0x0c0611c8u: goto P_0c0611c8;
case 0x0c0611cau: goto P_0c0611ca;
case 0x0c0611ccu: goto P_0c0611cc;
case 0x0c0611ceu: goto P_0c0611ce;
case 0x0c0611d0u: goto P_0c0611d0;
case 0x0c0611d2u: goto P_0c0611d2;
case 0x0c0611d4u: goto P_0c0611d4;
case 0x0c0611d6u: goto P_0c0611d6;
case 0x0c0611d8u: goto P_0c0611d8;
case 0x0c0611dau: goto P_0c0611da;
case 0x0c0611dcu: goto P_0c0611dc;
case 0x0c0611deu: goto P_0c0611de;
case 0x0c0611e0u: goto P_0c0611e0;
case 0x0c0611e2u: goto P_0c0611e2;
case 0x0c0611e4u: goto P_0c0611e4;
case 0x0c0611e6u: goto P_0c0611e6;
case 0x0c0611e8u: goto P_0c0611e8;
case 0x0c0611eau: goto P_0c0611ea;
case 0x0c0611ecu: goto P_0c0611ec;
case 0x0c0611eeu: goto P_0c0611ee;
case 0x0c0611f0u: goto P_0c0611f0;
case 0x0c0611f2u: goto P_0c0611f2;
case 0x0c0611f4u: goto P_0c0611f4;
case 0x0c0611f6u: goto P_0c0611f6;
case 0x0c0611f8u: goto P_0c0611f8;
case 0x0c0611fau: goto P_0c0611fa;
case 0x0c061e70u: goto P_0c061e70;
case 0x0c061e72u: goto P_0c061e72;
case 0x0c061e74u: goto P_0c061e74;
case 0x0c061e76u: goto P_0c061e76;
case 0x0c061e78u: goto P_0c061e78;
case 0x0c061e7au: goto P_0c061e7a;
case 0x0c061e7cu: goto P_0c061e7c;
case 0x0c061e7eu: goto P_0c061e7e;
case 0x0c061e80u: goto P_0c061e80;
case 0x0c061e82u: goto P_0c061e82;
case 0x0c061e84u: goto P_0c061e84;
case 0x0c061e86u: goto P_0c061e86;
case 0x0c061e88u: goto P_0c061e88;
case 0x0c061e8au: goto P_0c061e8a;
case 0x0c061e8cu: goto P_0c061e8c;
case 0x0c061e8eu: goto P_0c061e8e;
case 0x0c061e90u: goto P_0c061e90;
case 0x0c061e92u: goto P_0c061e92;
case 0x0c061e94u: goto P_0c061e94;
case 0x0c061e96u: goto P_0c061e96;
case 0x0c061e98u: goto P_0c061e98;
case 0x0c061e9au: goto P_0c061e9a;
case 0x0c061e9cu: goto P_0c061e9c;
case 0x0c061e9eu: goto P_0c061e9e;
case 0x0c061ea0u: goto P_0c061ea0;
case 0x0c061ea2u: goto P_0c061ea2;
case 0x0c061ea4u: goto P_0c061ea4;
case 0x0c061ea6u: goto P_0c061ea6;
case 0x0c061ea8u: goto P_0c061ea8;
case 0x0c061eaau: goto P_0c061eaa;
case 0x0c061eacu: goto P_0c061eac;
case 0x0c061eaeu: goto P_0c061eae;
case 0x0c061eb0u: goto P_0c061eb0;
case 0x0c061eb2u: goto P_0c061eb2;
case 0x0c061eb4u: goto P_0c061eb4;
case 0x0c061eb6u: goto P_0c061eb6;
case 0x0c061eb8u: goto P_0c061eb8;
case 0x0c061ebau: goto P_0c061eba;
case 0x0c061ebcu: goto P_0c061ebc;
case 0x0c061ebeu: goto P_0c061ebe;
case 0x0c061eccu: goto P_0c061ecc;
case 0x0c061eceu: goto P_0c061ece;
case 0x0c061ed0u: goto P_0c061ed0;
case 0x0c061ed2u: goto P_0c061ed2;
case 0x0c061ed4u: goto P_0c061ed4;
case 0x0c061ed6u: goto P_0c061ed6;
case 0x0c061ed8u: goto P_0c061ed8;
case 0x0c061edau: goto P_0c061eda;
case 0x0c061edcu: goto P_0c061edc;
case 0x0c061edeu: goto P_0c061ede;
case 0x0c061ee0u: goto P_0c061ee0;
case 0x0c061ee2u: goto P_0c061ee2;
case 0x0c061ee4u: goto P_0c061ee4;
case 0x0c061ee6u: goto P_0c061ee6;
case 0x0c061ee8u: goto P_0c061ee8;
case 0x0c061eeau: goto P_0c061eea;
case 0x0c061eecu: goto P_0c061eec;
case 0x0c061eeeu: goto P_0c061eee;
case 0x0c061ef0u: goto P_0c061ef0;
case 0x0c061ef2u: goto P_0c061ef2;
case 0x0c061ef4u: goto P_0c061ef4;
case 0x0c061ef6u: goto P_0c061ef6;
case 0x0c061ef8u: goto P_0c061ef8;
case 0x0c061efau: goto P_0c061efa;
case 0x0c061efcu: goto P_0c061efc;
case 0x0c061efeu: goto P_0c061efe;
case 0x0c061f00u: goto P_0c061f00;
case 0x0c061f02u: goto P_0c061f02;
case 0x0c061f04u: goto P_0c061f04;
case 0x0c061f06u: goto P_0c061f06;
case 0x0c061f08u: goto P_0c061f08;
case 0x0c061f0au: goto P_0c061f0a;
case 0x0c061f0cu: goto P_0c061f0c;
case 0x0c061f0eu: goto P_0c061f0e;
case 0x0c061f10u: goto P_0c061f10;
case 0x0c061f12u: goto P_0c061f12;
case 0x0c061f14u: goto P_0c061f14;
case 0x0c061f16u: goto P_0c061f16;
case 0x0c061f18u: goto P_0c061f18;
case 0x0c061f1au: goto P_0c061f1a;
case 0x0c061f1cu: goto P_0c061f1c;
case 0x0c061f1eu: goto P_0c061f1e;
case 0x0c061f20u: goto P_0c061f20;
case 0x0c061f22u: goto P_0c061f22;
case 0x0c061f24u: goto P_0c061f24;
case 0x0c061f26u: goto P_0c061f26;
case 0x0c061f28u: goto P_0c061f28;
case 0x0c061f2au: goto P_0c061f2a;
case 0x0c061f2cu: goto P_0c061f2c;
case 0x0c061f2eu: goto P_0c061f2e;
case 0x0c061f30u: goto P_0c061f30;
case 0x0c061f32u: goto P_0c061f32;
case 0x0c061f34u: goto P_0c061f34;
case 0x0c061f36u: goto P_0c061f36;
case 0x0c061f38u: goto P_0c061f38;
case 0x0c061f3au: goto P_0c061f3a;
case 0x0c061f3cu: goto P_0c061f3c;
case 0x0c061f3eu: goto P_0c061f3e;
case 0x0c061f40u: goto P_0c061f40;
case 0x0c061f42u: goto P_0c061f42;
case 0x0c061f44u: goto P_0c061f44;
case 0x0c061f46u: goto P_0c061f46;
case 0x0c061f48u: goto P_0c061f48;
case 0x0c061f4au: goto P_0c061f4a;
case 0x0c061f4cu: goto P_0c061f4c;
case 0x0c061f4eu: goto P_0c061f4e;
case 0x0c061f50u: goto P_0c061f50;
case 0x0c061f52u: goto P_0c061f52;
case 0x0c061f54u: goto P_0c061f54;
case 0x0c061f56u: goto P_0c061f56;
case 0x0c061f58u: goto P_0c061f58;
case 0x0c061f5au: goto P_0c061f5a;
case 0x0c061f5cu: goto P_0c061f5c;
case 0x0c061f5eu: goto P_0c061f5e;
case 0x0c061f60u: goto P_0c061f60;
case 0x0c061f62u: goto P_0c061f62;
case 0x0c061f64u: goto P_0c061f64;
case 0x0c061f66u: goto P_0c061f66;
case 0x0c061f68u: goto P_0c061f68;
case 0x0c061f6au: goto P_0c061f6a;
case 0x0c061f6cu: goto P_0c061f6c;
case 0x0c061f6eu: goto P_0c061f6e;
case 0x0c061f70u: goto P_0c061f70;
case 0x0c061f72u: goto P_0c061f72;
case 0x0c061f74u: goto P_0c061f74;
case 0x0c061f76u: goto P_0c061f76;
case 0x0c061f78u: goto P_0c061f78;
case 0x0c061f7au: goto P_0c061f7a;
case 0x0c061f7cu: goto P_0c061f7c;
case 0x0c061f7eu: goto P_0c061f7e;
case 0x0c061f80u: goto P_0c061f80;
case 0x0c061f82u: goto P_0c061f82;
case 0x0c061f84u: goto P_0c061f84;
case 0x0c061f86u: goto P_0c061f86;
case 0x0c061f88u: goto P_0c061f88;
case 0x0c061f8au: goto P_0c061f8a;
case 0x0c061f8cu: goto P_0c061f8c;
case 0x0c061f8eu: goto P_0c061f8e;
case 0x0c061f90u: goto P_0c061f90;
case 0x0c061f92u: goto P_0c061f92;
case 0x0c061f94u: goto P_0c061f94;
case 0x0c061f96u: goto P_0c061f96;
case 0x0c061f98u: goto P_0c061f98;
case 0x0c061f9au: goto P_0c061f9a;
case 0x0c061f9cu: goto P_0c061f9c;
case 0x0c061f9eu: goto P_0c061f9e;
case 0x0c061fa0u: goto P_0c061fa0;
case 0x0c061fa2u: goto P_0c061fa2;
case 0x0c061fa4u: goto P_0c061fa4;
case 0x0c061fa6u: goto P_0c061fa6;
case 0x0c061fa8u: goto P_0c061fa8;
case 0x0c061faau: goto P_0c061faa;
case 0x0c061facu: goto P_0c061fac;
case 0x0c061faeu: goto P_0c061fae;
case 0x0c061fb0u: goto P_0c061fb0;
case 0x0c061fb2u: goto P_0c061fb2;
case 0x0c061fb4u: goto P_0c061fb4;
case 0x0c061fb6u: goto P_0c061fb6;
case 0x0c061fb8u: goto P_0c061fb8;
case 0x0c061fbau: goto P_0c061fba;
case 0x0c061fbcu: goto P_0c061fbc;
case 0x0c061fbeu: goto P_0c061fbe;
case 0x0c061fc0u: goto P_0c061fc0;
case 0x0c061fc2u: goto P_0c061fc2;
case 0x0c061fc4u: goto P_0c061fc4;
case 0x0c061fc6u: goto P_0c061fc6;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05fcc4: /* original d330, guest PC 0x0c05fcc4 */
if(!s->budget--) { s->failed_pc=0x0c05fcc4u; return 0; }
r[3]=read(ram,0x0c05fd88u,4);
goto P_0c05fcc6;
P_0c05fcc6: /* original 7ffc, guest PC 0x0c05fcc6 */
if(!s->budget--) { s->failed_pc=0x0c05fcc6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05fcc8;
P_0c05fcc8: /* original 2f42, guest PC 0x0c05fcc8 */
if(!s->budget--) { s->failed_pc=0x0c05fcc8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c05fcca;
P_0c05fcca: /* original 6232, guest PC 0x0c05fcca */
if(!s->budget--) { s->failed_pc=0x0c05fccau; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c05fccc;
P_0c05fccc: /* original 422b, guest PC 0x0c05fccc */
if(!s->budget--) { s->failed_pc=0x0c05fcccu; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c05fcce: /* original 7f04, guest PC 0x0c05fcce */
if(!s->budget--) { s->failed_pc=0x0c05fcceu; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c05fcd0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05fcd0u; return 0; } return 1;
P_0c060d14: /* original d344, guest PC 0x0c060d14 */
if(!s->budget--) { s->failed_pc=0x0c060d14u; return 0; }
r[3]=read(ram,0x0c060e28u,4);
goto P_0c060d16;
P_0c060d16: /* original 343c, guest PC 0x0c060d16 */
if(!s->budget--) { s->failed_pc=0x0c060d16u; return 0; }
r[4]+=r[3];
goto P_0c060d18;
P_0c060d18: /* original 2452, guest PC 0x0c060d18 */
if(!s->budget--) { s->failed_pc=0x0c060d18u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c060d1a;
P_0c060d1a: /* original 000b, guest PC 0x0c060d1a */
if(!s->budget--) { s->failed_pc=0x0c060d1au; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c060d1c: /* original e001, guest PC 0x0c060d1c */
if(!s->budget--) { s->failed_pc=0x0c060d1cu; return 0; }
r[0]=0x00000001u;
if(!vf3_matrix_family(0x0c060d1eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c060d1eu; return 0; } return 1;
P_0c060d46: /* original d038, guest PC 0x0c060d46 */
if(!s->budget--) { s->failed_pc=0x0c060d46u; return 0; }
r[0]=read(ram,0x0c060e28u,4);
goto P_0c060d48;
P_0c060d48: /* original 000b, guest PC 0x0c060d48 */
if(!s->budget--) { s->failed_pc=0x0c060d48u; return 0; }
target=r[16];
r[0]=read(ram,r[4]+r[0],4);
s->pc=target; return ram->oob==0;
P_0c060d4a: /* original 004e, guest PC 0x0c060d4a */
if(!s->budget--) { s->failed_pc=0x0c060d4au; return 0; }
r[0]=read(ram,r[4]+r[0],4);
if(!vf3_matrix_family(0x0c060d4cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c060d4cu; return 0; } return 1;
P_0c061168: /* original 2fe6, guest PC 0x0c061168 */
if(!s->budget--) { s->failed_pc=0x0c061168u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06116a;
P_0c06116a: /* original 6143, guest PC 0x0c06116a */
if(!s->budget--) { s->failed_pc=0x0c06116au; return 0; }
r[1]=r[4];
goto P_0c06116c;
P_0c06116c: /* original d347, guest PC 0x0c06116c */
if(!s->budget--) { s->failed_pc=0x0c06116cu; return 0; }
r[3]=read(ram,0x0c06128cu,4);
goto P_0c06116e;
P_0c06116e: /* original 6e53, guest PC 0x0c06116e */
if(!s->budget--) { s->failed_pc=0x0c06116eu; return 0; }
r[14]=r[5];
goto P_0c061170;
P_0c061170: /* original 2fd6, guest PC 0x0c061170 */
if(!s->budget--) { s->failed_pc=0x0c061170u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c061172;
P_0c061172: /* original 6d43, guest PC 0x0c061172 */
if(!s->budget--) { s->failed_pc=0x0c061172u; return 0; }
r[13]=r[4];
goto P_0c061174;
P_0c061174: /* original 2fc6, guest PC 0x0c061174 */
if(!s->budget--) { s->failed_pc=0x0c061174u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c061176;
P_0c061176: /* original 2fb6, guest PC 0x0c061176 */
if(!s->budget--) { s->failed_pc=0x0c061176u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c061178;
P_0c061178: /* original 2fa6, guest PC 0x0c061178 */
if(!s->budget--) { s->failed_pc=0x0c061178u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06117a;
P_0c06117a: /* original 4f22, guest PC 0x0c06117a */
if(!s->budget--) { s->failed_pc=0x0c06117au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06117c;
P_0c06117c: /* original da41, guest PC 0x0c06117c */
if(!s->budget--) { s->failed_pc=0x0c06117cu; return 0; }
r[10]=read(ram,0x0c061284u,4);
goto P_0c06117e;
P_0c06117e: /* original db42, guest PC 0x0c06117e */
if(!s->budget--) { s->failed_pc=0x0c06117eu; return 0; }
r[11]=read(ram,0x0c061288u,4);
goto P_0c061180;
P_0c061180: /* original 430b, guest PC 0x0c061180 */
if(!s->budget--) { s->failed_pc=0x0c061180u; return 0; }
target=r[3];
r[16]=code_base|0x0c061184u;
r[0]=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c061184u) { target=s->pc; goto dispatch; }
goto P_0c061184;
P_0c061182: /* original e020, guest PC 0x0c061182 */
if(!s->budget--) { s->failed_pc=0x0c061182u; return 0; }
r[0]=0x00000020u;
goto P_0c061184;
P_0c061184: /* original 6403, guest PC 0x0c061184 */
if(!s->budget--) { s->failed_pc=0x0c061184u; return 0; }
r[4]=r[0];
goto P_0c061186;
P_0c061186: /* original 2448, guest PC 0x0c061186 */
if(!s->budget--) { s->failed_pc=0x0c061186u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c061188;
P_0c061188: /* original 8902, guest PC 0x0c061188 */
if(!s->budget--) { s->failed_pc=0x0c061188u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061190; }
goto P_0c06118a;
P_0c06118a: /* original e320, guest PC 0x0c06118a */
if(!s->budget--) { s->failed_pc=0x0c06118au; return 0; }
r[3]=0x00000020u;
goto P_0c06118c;
P_0c06118c: /* original 3348, guest PC 0x0c06118c */
if(!s->budget--) { s->failed_pc=0x0c06118cu; return 0; }
r[3]-=r[4];
goto P_0c06118e;
P_0c06118e: /* original 3d3c, guest PC 0x0c06118e */
if(!s->budget--) { s->failed_pc=0x0c06118eu; return 0; }
r[13]+=r[3];
goto P_0c061190;
P_0c061190: /* original 62a2, guest PC 0x0c061190 */
if(!s->budget--) { s->failed_pc=0x0c061190u; return 0; }
tmp=read(ram,r[10],4);
r[2]=tmp;
goto P_0c061192;
P_0c061192: /* original 32d0, guest PC 0x0c061192 */
if(!s->budget--) { s->failed_pc=0x0c061192u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[13])!=0);
goto P_0c061194;
P_0c061194: /* original 8920, guest PC 0x0c061194 */
if(!s->budget--) { s->failed_pc=0x0c061194u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0611d8; }
goto P_0c061196;
P_0c061196: /* original 65d3, guest PC 0x0c061196 */
if(!s->budget--) { s->failed_pc=0x0c061196u; return 0; }
r[5]=r[13];
goto P_0c061198;
P_0c061198: /* original d23d, guest PC 0x0c061198 */
if(!s->budget--) { s->failed_pc=0x0c061198u; return 0; }
r[2]=read(ram,0x0c061290u,4);
goto P_0c06119a;
P_0c06119a: /* original 4500, guest PC 0x0c06119a */
if(!s->budget--) { s->failed_pc=0x0c06119au; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c06119c;
P_0c06119c: /* original 6022, guest PC 0x0c06119c */
if(!s->budget--) { s->failed_pc=0x0c06119cu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c06119e;
P_0c06119e: /* original c804, guest PC 0x0c06119e */
if(!s->budget--) { s->failed_pc=0x0c06119eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0611a0;
P_0c0611a0: /* original 8908, guest PC 0x0c0611a0 */
if(!s->budget--) { s->failed_pc=0x0c0611a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0611b4; }
goto P_0c0611a2;
P_0c0611a2: /* original d43c, guest PC 0x0c0611a2 */
if(!s->budget--) { s->failed_pc=0x0c0611a2u; return 0; }
r[4]=read(ram,0x0c061294u,4);
goto P_0c0611a4;
P_0c0611a4: /* original 5149, guest PC 0x0c0611a4 */
if(!s->budget--) { s->failed_pc=0x0c0611a4u; return 0; }
r[1]=read(ram,r[4]+36,4);
goto P_0c0611a6;
P_0c0611a6: /* original 5344, guest PC 0x0c0611a6 */
if(!s->budget--) { s->failed_pc=0x0c0611a6u; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c0611a8;
P_0c0611a8: /* original 3312, guest PC 0x0c0611a8 */
if(!s->budget--) { s->failed_pc=0x0c0611a8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[1])!=0);
goto P_0c0611aa;
P_0c0611aa: /* original 8903, guest PC 0x0c0611aa */
if(!s->budget--) { s->failed_pc=0x0c0611aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0611b4; }
goto P_0c0611ac;
P_0c0611ac: /* original e708, guest PC 0x0c0611ac */
if(!s->budget--) { s->failed_pc=0x0c0611acu; return 0; }
r[7]=0x00000008u;
goto P_0c0611ae;
P_0c0611ae: /* original 66e3, guest PC 0x0c0611ae */
if(!s->budget--) { s->failed_pc=0x0c0611aeu; return 0; }
r[6]=r[14];
goto P_0c0611b0;
P_0c0611b0: /* original a003, guest PC 0x0c0611b0 */
if(!s->budget--) { s->failed_pc=0x0c0611b0u; return 0; }
r[4]=0x00000001u;
goto P_0c0611ba;
P_0c0611b2: /* original e401, guest PC 0x0c0611b2 */
if(!s->budget--) { s->failed_pc=0x0c0611b2u; return 0; }
r[4]=0x00000001u;
goto P_0c0611b4;
P_0c0611b4: /* original e708, guest PC 0x0c0611b4 */
if(!s->budget--) { s->failed_pc=0x0c0611b4u; return 0; }
r[7]=0x00000008u;
goto P_0c0611b6;
P_0c0611b6: /* original 66e3, guest PC 0x0c0611b6 */
if(!s->budget--) { s->failed_pc=0x0c0611b6u; return 0; }
r[6]=r[14];
goto P_0c0611b8;
P_0c0611b8: /* original e400, guest PC 0x0c0611b8 */
if(!s->budget--) { s->failed_pc=0x0c0611b8u; return 0; }
r[4]=0x00000000u;
goto P_0c0611ba;
P_0c0611ba: /* original b659, guest PC 0x0c0611ba */
if(!s->budget--) { s->failed_pc=0x0c0611bau; return 0; }
target=code_base|0x0c061e70u; r[16]=code_base|0x0c0611beu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0611beu) { target=s->pc; goto dispatch; }
goto P_0c0611be;
P_0c0611bc: /* original 0009, guest PC 0x0c0611bc */
if(!s->budget--) { s->failed_pc=0x0c0611bcu; return 0; }
goto P_0c0611be;
P_0c0611be: /* original 6c03, guest PC 0x0c0611be */
if(!s->budget--) { s->failed_pc=0x0c0611beu; return 0; }
r[12]=r[0];
goto P_0c0611c0;
P_0c0611c0: /* original 2cc8, guest PC 0x0c0611c0 */
if(!s->budget--) { s->failed_pc=0x0c0611c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0611c2;
P_0c0611c2: /* original 8b07, guest PC 0x0c0611c2 */
if(!s->budget--) { s->failed_pc=0x0c0611c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0611d4; }
goto P_0c0611c4;
P_0c0611c4: /* original 2ad2, guest PC 0x0c0611c4 */
if(!s->budget--) { s->failed_pc=0x0c0611c4u; return 0; }
write(ram,r[10],r[13],4);
goto P_0c0611c6;
P_0c0611c6: /* original 53e7, guest PC 0x0c0611c6 */
if(!s->budget--) { s->failed_pc=0x0c0611c6u; return 0; }
r[3]=read(ram,r[14]+28,4);
goto P_0c0611c8;
P_0c0611c8: /* original d233, guest PC 0x0c0611c8 */
if(!s->budget--) { s->failed_pc=0x0c0611c8u; return 0; }
r[2]=read(ram,0x0c061298u,4);
goto P_0c0611ca;
P_0c0611ca: /* original 2b32, guest PC 0x0c0611ca */
if(!s->budget--) { s->failed_pc=0x0c0611cau; return 0; }
write(ram,r[11],r[3],4);
goto P_0c0611cc;
P_0c0611cc: /* original 54e7, guest PC 0x0c0611cc */
if(!s->budget--) { s->failed_pc=0x0c0611ccu; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c0611ce;
P_0c0611ce: /* original 420b, guest PC 0x0c0611ce */
if(!s->budget--) { s->failed_pc=0x0c0611ceu; return 0; }
target=r[2];
r[16]=code_base|0x0c0611d2u;
write(ram,r[14]+20,r[13],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0611d2u) { target=s->pc; goto dispatch; }
goto P_0c0611d2;
P_0c0611d0: /* original 1ed5, guest PC 0x0c0611d0 */
if(!s->budget--) { s->failed_pc=0x0c0611d0u; return 0; }
write(ram,r[14]+20,r[13],4);
goto P_0c0611d2;
P_0c0611d2: /* original 1e07, guest PC 0x0c0611d2 */
if(!s->budget--) { s->failed_pc=0x0c0611d2u; return 0; }
write(ram,r[14]+28,r[0],4);
goto P_0c0611d4;
P_0c0611d4: /* original a00b, guest PC 0x0c0611d4 */
if(!s->budget--) { s->failed_pc=0x0c0611d4u; return 0; }
r[0]=r[12];
goto P_0c0611ee;
P_0c0611d6: /* original 60c3, guest PC 0x0c0611d6 */
if(!s->budget--) { s->failed_pc=0x0c0611d6u; return 0; }
r[0]=r[12];
goto P_0c0611d8;
P_0c0611d8: /* original 1ed5, guest PC 0x0c0611d8 */
if(!s->budget--) { s->failed_pc=0x0c0611d8u; return 0; }
write(ram,r[14]+20,r[13],4);
goto P_0c0611da;
P_0c0611da: /* original 64b2, guest PC 0x0c0611da */
if(!s->budget--) { s->failed_pc=0x0c0611dau; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c0611dc;
P_0c0611dc: /* original d22e, guest PC 0x0c0611dc */
if(!s->budget--) { s->failed_pc=0x0c0611dcu; return 0; }
r[2]=read(ram,0x0c061298u,4);
goto P_0c0611de;
P_0c0611de: /* original 420b, guest PC 0x0c0611de */
if(!s->budget--) { s->failed_pc=0x0c0611deu; return 0; }
target=r[2];
r[16]=code_base|0x0c0611e2u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0611e2u) { target=s->pc; goto dispatch; }
goto P_0c0611e2;
P_0c0611e0: /* original 7404, guest PC 0x0c0611e0 */
if(!s->budget--) { s->failed_pc=0x0c0611e0u; return 0; }
r[4]+=0x00000004u;
goto P_0c0611e2;
P_0c0611e2: /* original e400, guest PC 0x0c0611e2 */
if(!s->budget--) { s->failed_pc=0x0c0611e2u; return 0; }
r[4]=0x00000000u;
goto P_0c0611e4;
P_0c0611e4: /* original 1e07, guest PC 0x0c0611e4 */
if(!s->budget--) { s->failed_pc=0x0c0611e4u; return 0; }
write(ram,r[14]+28,r[0],4);
goto P_0c0611e6;
P_0c0611e6: /* original 2a42, guest PC 0x0c0611e6 */
if(!s->budget--) { s->failed_pc=0x0c0611e6u; return 0; }
write(ram,r[10],r[4],4);
goto P_0c0611e8;
P_0c0611e8: /* original 2b42, guest PC 0x0c0611e8 */
if(!s->budget--) { s->failed_pc=0x0c0611e8u; return 0; }
write(ram,r[11],r[4],4);
goto P_0c0611ea;
P_0c0611ea: /* original 6043, guest PC 0x0c0611ea */
if(!s->budget--) { s->failed_pc=0x0c0611eau; return 0; }
r[0]=r[4];
goto P_0c0611ec;
P_0c0611ec: /* original 0009, guest PC 0x0c0611ec */
if(!s->budget--) { s->failed_pc=0x0c0611ecu; return 0; }
goto P_0c0611ee;
P_0c0611ee: /* original 4f26, guest PC 0x0c0611ee */
if(!s->budget--) { s->failed_pc=0x0c0611eeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0611f0;
P_0c0611f0: /* original 6af6, guest PC 0x0c0611f0 */
if(!s->budget--) { s->failed_pc=0x0c0611f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0611f2;
P_0c0611f2: /* original 6bf6, guest PC 0x0c0611f2 */
if(!s->budget--) { s->failed_pc=0x0c0611f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0611f4;
P_0c0611f4: /* original 6cf6, guest PC 0x0c0611f4 */
if(!s->budget--) { s->failed_pc=0x0c0611f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0611f6;
P_0c0611f6: /* original 6df6, guest PC 0x0c0611f6 */
if(!s->budget--) { s->failed_pc=0x0c0611f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0611f8;
P_0c0611f8: /* original 000b, guest PC 0x0c0611f8 */
if(!s->budget--) { s->failed_pc=0x0c0611f8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0611fa: /* original 6ef6, guest PC 0x0c0611fa */
if(!s->budget--) { s->failed_pc=0x0c0611fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0611fcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0611fcu; return 0; } return 1;
P_0c061e70: /* original 2fe6, guest PC 0x0c061e70 */
if(!s->budget--) { s->failed_pc=0x0c061e70u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c061e72;
P_0c061e72: /* original 6153, guest PC 0x0c061e72 */
if(!s->budget--) { s->failed_pc=0x0c061e72u; return 0; }
r[1]=r[5];
goto P_0c061e74;
P_0c061e74: /* original d313, guest PC 0x0c061e74 */
if(!s->budget--) { s->failed_pc=0x0c061e74u; return 0; }
r[3]=read(ram,0x0c061ec4u,4);
goto P_0c061e76;
P_0c061e76: /* original 2fd6, guest PC 0x0c061e76 */
if(!s->budget--) { s->failed_pc=0x0c061e76u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c061e78;
P_0c061e78: /* original 2fc6, guest PC 0x0c061e78 */
if(!s->budget--) { s->failed_pc=0x0c061e78u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c061e7a;
P_0c061e7a: /* original 6c53, guest PC 0x0c061e7a */
if(!s->budget--) { s->failed_pc=0x0c061e7au; return 0; }
r[12]=r[5];
goto P_0c061e7c;
P_0c061e7c: /* original 2fb6, guest PC 0x0c061e7c */
if(!s->budget--) { s->failed_pc=0x0c061e7cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c061e7e;
P_0c061e7e: /* original 2fa6, guest PC 0x0c061e7e */
if(!s->budget--) { s->failed_pc=0x0c061e7eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c061e80;
P_0c061e80: /* original 2f96, guest PC 0x0c061e80 */
if(!s->budget--) { s->failed_pc=0x0c061e80u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c061e82;
P_0c061e82: /* original 6963, guest PC 0x0c061e82 */
if(!s->budget--) { s->failed_pc=0x0c061e82u; return 0; }
r[9]=r[6];
goto P_0c061e84;
P_0c061e84: /* original 2f86, guest PC 0x0c061e84 */
if(!s->budget--) { s->failed_pc=0x0c061e84u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c061e86;
P_0c061e86: /* original 4f22, guest PC 0x0c061e86 */
if(!s->budget--) { s->failed_pc=0x0c061e86u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c061e88;
P_0c061e88: /* original 7ffc, guest PC 0x0c061e88 */
if(!s->budget--) { s->failed_pc=0x0c061e88u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c061e8a;
P_0c061e8a: /* original 430b, guest PC 0x0c061e8a */
if(!s->budget--) { s->failed_pc=0x0c061e8au; return 0; }
target=r[3];
r[16]=code_base|0x0c061e8eu;
r[0]=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c061e8eu) { target=s->pc; goto dispatch; }
goto P_0c061e8e;
P_0c061e8c: /* original e020, guest PC 0x0c061e8c */
if(!s->budget--) { s->failed_pc=0x0c061e8cu; return 0; }
r[0]=0x00000020u;
goto P_0c061e8e;
P_0c061e8e: /* original 6503, guest PC 0x0c061e8e */
if(!s->budget--) { s->failed_pc=0x0c061e8eu; return 0; }
r[5]=r[0];
goto P_0c061e90;
P_0c061e90: /* original 2558, guest PC 0x0c061e90 */
if(!s->budget--) { s->failed_pc=0x0c061e90u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c061e92;
P_0c061e92: /* original 8d03, guest PC 0x0c061e92 */
if(!s->budget--) { s->failed_pc=0x0c061e92u; return 0; }
cond=r[17]&1u;
r[14]=0x00000000u;
if(cond) { goto P_0c061e9c; }
goto P_0c061e96;
P_0c061e94: /* original ee00, guest PC 0x0c061e94 */
if(!s->budget--) { s->failed_pc=0x0c061e94u; return 0; }
r[14]=0x00000000u;
goto P_0c061e96;
P_0c061e96: /* original e320, guest PC 0x0c061e96 */
if(!s->budget--) { s->failed_pc=0x0c061e96u; return 0; }
r[3]=0x00000020u;
goto P_0c061e98;
P_0c061e98: /* original 3358, guest PC 0x0c061e98 */
if(!s->budget--) { s->failed_pc=0x0c061e98u; return 0; }
r[3]-=r[5];
goto P_0c061e9a;
P_0c061e9a: /* original 3c3c, guest PC 0x0c061e9a */
if(!s->budget--) { s->failed_pc=0x0c061e9au; return 0; }
r[12]+=r[3];
goto P_0c061e9c;
P_0c061e9c: /* original db0a, guest PC 0x0c061e9c */
if(!s->budget--) { s->failed_pc=0x0c061e9cu; return 0; }
r[11]=read(ram,0x0c061ec8u,4);
goto P_0c061e9e;
P_0c061e9e: /* original 6a43, guest PC 0x0c061e9e */
if(!s->budget--) { s->failed_pc=0x0c061e9eu; return 0; }
r[10]=r[4];
goto P_0c061ea0;
P_0c061ea0: /* original 6343, guest PC 0x0c061ea0 */
if(!s->budget--) { s->failed_pc=0x0c061ea0u; return 0; }
r[3]=r[4];
goto P_0c061ea2;
P_0c061ea2: /* original 4a08, guest PC 0x0c061ea2 */
if(!s->budget--) { s->failed_pc=0x0c061ea2u; return 0; }
r[10]<<=2;
goto P_0c061ea4;
P_0c061ea4: /* original 3a3c, guest PC 0x0c061ea4 */
if(!s->budget--) { s->failed_pc=0x0c061ea4u; return 0; }
r[10]+=r[3];
goto P_0c061ea6;
P_0c061ea6: /* original 4a08, guest PC 0x0c061ea6 */
if(!s->budget--) { s->failed_pc=0x0c061ea6u; return 0; }
r[10]<<=2;
goto P_0c061ea8;
P_0c061ea8: /* original 6aae, guest PC 0x0c061ea8 */
if(!s->budget--) { s->failed_pc=0x0c061ea8u; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)r[10];
goto P_0c061eaa;
P_0c061eaa: /* original 62a3, guest PC 0x0c061eaa */
if(!s->budget--) { s->failed_pc=0x0c061eaau; return 0; }
r[2]=r[10];
goto P_0c061eac;
P_0c061eac: /* original 32bc, guest PC 0x0c061eac */
if(!s->budget--) { s->failed_pc=0x0c061eacu; return 0; }
r[2]+=r[11];
goto P_0c061eae;
P_0c061eae: /* original 5422, guest PC 0x0c061eae */
if(!s->budget--) { s->failed_pc=0x0c061eaeu; return 0; }
r[4]=read(ram,r[2]+8,4);
goto P_0c061eb0;
P_0c061eb0: /* original 2448, guest PC 0x0c061eb0 */
if(!s->budget--) { s->failed_pc=0x0c061eb0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c061eb2;
P_0c061eb2: /* original 890e, guest PC 0x0c061eb2 */
if(!s->budget--) { s->failed_pc=0x0c061eb2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061ed2; }
goto P_0c061eb4;
P_0c061eb4: /* original 5144, guest PC 0x0c061eb4 */
if(!s->budget--) { s->failed_pc=0x0c061eb4u; return 0; }
r[1]=read(ram,r[4]+16,4);
goto P_0c061eb6;
P_0c061eb6: /* original 31c3, guest PC 0x0c061eb6 */
if(!s->budget--) { s->failed_pc=0x0c061eb6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[12])!=0);
goto P_0c061eb8;
P_0c061eb8: /* original 8b08, guest PC 0x0c061eb8 */
if(!s->budget--) { s->failed_pc=0x0c061eb8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061ecc; }
goto P_0c061eba;
P_0c061eba: /* original 6e43, guest PC 0x0c061eba */
if(!s->budget--) { s->failed_pc=0x0c061ebau; return 0; }
r[14]=r[4];
goto P_0c061ebc;
P_0c061ebc: /* original a007, guest PC 0x0c061ebc */
if(!s->budget--) { s->failed_pc=0x0c061ebcu; return 0; }
r[4]=0x00000000u;
goto P_0c061ece;
P_0c061ebe: /* original e400, guest PC 0x0c061ebe */
if(!s->budget--) { s->failed_pc=0x0c061ebeu; return 0; }
r[4]=0x00000000u;
if(!vf3_matrix_family(0x0c061ec0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c061ec0u; return 0; } return 1;
P_0c061ecc: /* original 5442, guest PC 0x0c061ecc */
if(!s->budget--) { s->failed_pc=0x0c061eccu; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c061ece;
P_0c061ece: /* original 2448, guest PC 0x0c061ece */
if(!s->budget--) { s->failed_pc=0x0c061eceu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c061ed0;
P_0c061ed0: /* original 8bf0, guest PC 0x0c061ed0 */
if(!s->budget--) { s->failed_pc=0x0c061ed0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061eb4; }
goto P_0c061ed2;
P_0c061ed2: /* original 2ee8, guest PC 0x0c061ed2 */
if(!s->budget--) { s->failed_pc=0x0c061ed2u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c061ed4;
P_0c061ed4: /* original 8963, guest PC 0x0c061ed4 */
if(!s->budget--) { s->failed_pc=0x0c061ed4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061f9e; }
goto P_0c061ed6;
P_0c061ed6: /* original 52e4, guest PC 0x0c061ed6 */
if(!s->budget--) { s->failed_pc=0x0c061ed6u; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c061ed8;
P_0c061ed8: /* original 32c0, guest PC 0x0c061ed8 */
if(!s->budget--) { s->failed_pc=0x0c061ed8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[12])!=0);
goto P_0c061eda;
P_0c061eda: /* original 8f31, guest PC 0x0c061eda */
if(!s->budget--) { s->failed_pc=0x0c061edau; return 0; }
cond=r[17]&1u;
r[8]=(uint32_t)(int32_t)(int16_t)r[7];
if(!cond) { goto P_0c061f40; }
goto P_0c061ede;
P_0c061edc: /* original 687f, guest PC 0x0c061edc */
if(!s->budget--) { s->failed_pc=0x0c061edcu; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)r[7];
goto P_0c061ede;
P_0c061ede: /* original 66e3, guest PC 0x0c061ede */
if(!s->budget--) { s->failed_pc=0x0c061edeu; return 0; }
r[6]=r[14];
goto P_0c061ee0;
P_0c061ee0: /* original 6da3, guest PC 0x0c061ee0 */
if(!s->budget--) { s->failed_pc=0x0c061ee0u; return 0; }
r[13]=r[10];
goto P_0c061ee2;
P_0c061ee2: /* original 3dbc, guest PC 0x0c061ee2 */
if(!s->budget--) { s->failed_pc=0x0c061ee2u; return 0; }
r[13]+=r[11];
goto P_0c061ee4;
P_0c061ee4: /* original 65d3, guest PC 0x0c061ee4 */
if(!s->budget--) { s->failed_pc=0x0c061ee4u; return 0; }
r[5]=r[13];
goto P_0c061ee6;
P_0c061ee6: /* original 750c, guest PC 0x0c061ee6 */
if(!s->budget--) { s->failed_pc=0x0c061ee6u; return 0; }
r[5]+=0x0000000cu;
goto P_0c061ee8;
P_0c061ee8: /* original 64d3, guest PC 0x0c061ee8 */
if(!s->budget--) { s->failed_pc=0x0c061ee8u; return 0; }
r[4]=r[13];
goto P_0c061eea;
P_0c061eea: /* original b31b, guest PC 0x0c061eea */
if(!s->budget--) { s->failed_pc=0x0c061eeau; return 0; }
target=code_base|0x0c062524u; r[16]=code_base|0x0c061eeeu;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c061eeeu) { target=s->pc; goto dispatch; }
goto P_0c061eee;
P_0c061eec: /* original 7408, guest PC 0x0c061eec */
if(!s->budget--) { s->failed_pc=0x0c061eecu; return 0; }
r[4]+=0x00000008u;
goto P_0c061eee;
P_0c061eee: /* original 66e3, guest PC 0x0c061eee */
if(!s->budget--) { s->failed_pc=0x0c061eeeu; return 0; }
r[6]=r[14];
goto P_0c061ef0;
P_0c061ef0: /* original 65d3, guest PC 0x0c061ef0 */
if(!s->budget--) { s->failed_pc=0x0c061ef0u; return 0; }
r[5]=r[13];
goto P_0c061ef2;
P_0c061ef2: /* original 7504, guest PC 0x0c061ef2 */
if(!s->budget--) { s->failed_pc=0x0c061ef2u; return 0; }
r[5]+=0x00000004u;
goto P_0c061ef4;
P_0c061ef4: /* original b2f6, guest PC 0x0c061ef4 */
if(!s->budget--) { s->failed_pc=0x0c061ef4u; return 0; }
target=code_base|0x0c0624e4u; r[16]=code_base|0x0c061ef8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c061ef8u) { target=s->pc; goto dispatch; }
goto P_0c061ef8;
P_0c061ef6: /* original 64d3, guest PC 0x0c061ef6 */
if(!s->budget--) { s->failed_pc=0x0c061ef6u; return 0; }
r[4]=r[13];
goto P_0c061ef8;
P_0c061ef8: /* original e201, guest PC 0x0c061ef8 */
if(!s->budget--) { s->failed_pc=0x0c061ef8u; return 0; }
r[2]=0x00000001u;
goto P_0c061efa;
P_0c061efa: /* original 6083, guest PC 0x0c061efa */
if(!s->budget--) { s->failed_pc=0x0c061efau; return 0; }
r[0]=r[8];
goto P_0c061efc;
P_0c061efc: /* original 0009, guest PC 0x0c061efc */
if(!s->budget--) { s->failed_pc=0x0c061efcu; return 0; }
goto P_0c061efe;
P_0c061efe: /* original 8808, guest PC 0x0c061efe */
if(!s->budget--) { s->failed_pc=0x0c061efeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c061f00;
P_0c061f00: /* original 8d05, guest PC 0x0c061f00 */
if(!s->budget--) { s->failed_pc=0x0c061f00u; return 0; }
cond=r[17]&1u;
write(ram,r[14],r[2],2);
if(cond) { goto P_0c061f0e; }
goto P_0c061f04;
P_0c061f02: /* original 2e21, guest PC 0x0c061f02 */
if(!s->budget--) { s->failed_pc=0x0c061f02u; return 0; }
write(ram,r[14],r[2],2);
goto P_0c061f04;
P_0c061f04: /* original 9160, guest PC 0x0c061f04 */
if(!s->budget--) { s->failed_pc=0x0c061f04u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c061fc8u,2);
goto P_0c061f06;
P_0c061f06: /* original 3010, guest PC 0x0c061f06 */
if(!s->budget--) { s->failed_pc=0x0c061f06u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c061f08;
P_0c061f08: /* original 8911, guest PC 0x0c061f08 */
if(!s->budget--) { s->failed_pc=0x0c061f08u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061f2e; }
goto P_0c061f0a;
P_0c061f0a: /* original a048, guest PC 0x0c061f0a */
if(!s->budget--) { s->failed_pc=0x0c061f0au; return 0; }
goto P_0c061f9e;
P_0c061f0c: /* original 0009, guest PC 0x0c061f0c */
if(!s->budget--) { s->failed_pc=0x0c061f0cu; return 0; }
goto P_0c061f0e;
P_0c061f0e: /* original 6493, guest PC 0x0c061f0e */
if(!s->budget--) { s->failed_pc=0x0c061f0eu; return 0; }
r[4]=r[9];
goto P_0c061f10;
P_0c061f10: /* original 53e3, guest PC 0x0c061f10 */
if(!s->budget--) { s->failed_pc=0x0c061f10u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c061f12;
P_0c061f12: /* original 1437, guest PC 0x0c061f12 */
if(!s->budget--) { s->failed_pc=0x0c061f12u; return 0; }
write(ram,r[4]+28,r[3],4);
goto P_0c061f14;
P_0c061f14: /* original 1e45, guest PC 0x0c061f14 */
if(!s->budget--) { s->failed_pc=0x0c061f14u; return 0; }
write(ram,r[14]+20,r[4],4);
goto P_0c061f16;
P_0c061f16: /* original 60e1, guest PC 0x0c061f16 */
if(!s->budget--) { s->failed_pc=0x0c061f16u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c061f18;
P_0c061f18: /* original cb08, guest PC 0x0c061f18 */
if(!s->budget--) { s->failed_pc=0x0c061f18u; return 0; }
r[0]|=8u;
goto P_0c061f1a;
P_0c061f1a: /* original 2e01, guest PC 0x0c061f1a */
if(!s->budget--) { s->failed_pc=0x0c061f1au; return 0; }
write(ram,r[14],r[0],2);
goto P_0c061f1c;
P_0c061f1c: /* original 60e1, guest PC 0x0c061f1c */
if(!s->budget--) { s->failed_pc=0x0c061f1cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c061f1e;
P_0c061f1e: /* original 3abc, guest PC 0x0c061f1e */
if(!s->budget--) { s->failed_pc=0x0c061f1eu; return 0; }
r[10]+=r[11];
goto P_0c061f20;
P_0c061f20: /* original cb04, guest PC 0x0c061f20 */
if(!s->budget--) { s->failed_pc=0x0c061f20u; return 0; }
r[0]|=4u;
goto P_0c061f22;
P_0c061f22: /* original 2e01, guest PC 0x0c061f22 */
if(!s->budget--) { s->failed_pc=0x0c061f22u; return 0; }
write(ram,r[14],r[0],2);
goto P_0c061f24;
P_0c061f24: /* original 53e4, guest PC 0x0c061f24 */
if(!s->budget--) { s->failed_pc=0x0c061f24u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c061f26;
P_0c061f26: /* original 52a4, guest PC 0x0c061f26 */
if(!s->budget--) { s->failed_pc=0x0c061f26u; return 0; }
r[2]=read(ram,r[10]+16,4);
goto P_0c061f28;
P_0c061f28: /* original 3238, guest PC 0x0c061f28 */
if(!s->budget--) { s->failed_pc=0x0c061f28u; return 0; }
r[2]-=r[3];
goto P_0c061f2a;
P_0c061f2a: /* original a042, guest PC 0x0c061f2a */
if(!s->budget--) { s->failed_pc=0x0c061f2au; return 0; }
write(ram,r[10]+16,r[2],4);
goto P_0c061fb2;
P_0c061f2c: /* original 1a24, guest PC 0x0c061f2c */
if(!s->budget--) { s->failed_pc=0x0c061f2cu; return 0; }
write(ram,r[10]+16,r[2],4);
goto P_0c061f2e;
P_0c061f2e: /* original 6493, guest PC 0x0c061f2e */
if(!s->budget--) { s->failed_pc=0x0c061f2eu; return 0; }
r[4]=r[9];
goto P_0c061f30;
P_0c061f30: /* original 53e3, guest PC 0x0c061f30 */
if(!s->budget--) { s->failed_pc=0x0c061f30u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c061f32;
P_0c061f32: /* original 2432, guest PC 0x0c061f32 */
if(!s->budget--) { s->failed_pc=0x0c061f32u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c061f34;
P_0c061f34: /* original 1e45, guest PC 0x0c061f34 */
if(!s->budget--) { s->failed_pc=0x0c061f34u; return 0; }
write(ram,r[14]+20,r[4],4);
goto P_0c061f36;
P_0c061f36: /* original 9347, guest PC 0x0c061f36 */
if(!s->budget--) { s->failed_pc=0x0c061f36u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c061fc8u,2);
goto P_0c061f38;
P_0c061f38: /* original 62e1, guest PC 0x0c061f38 */
if(!s->budget--) { s->failed_pc=0x0c061f38u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c061f3a;
P_0c061f3a: /* original 223b, guest PC 0x0c061f3a */
if(!s->budget--) { s->failed_pc=0x0c061f3au; return 0; }
r[2]|=r[3];
goto P_0c061f3c;
P_0c061f3c: /* original afee, guest PC 0x0c061f3c */
if(!s->budget--) { s->failed_pc=0x0c061f3cu; return 0; }
write(ram,r[14],r[2],2);
goto P_0c061f1c;
P_0c061f3e: /* original 2e21, guest PC 0x0c061f3e */
if(!s->budget--) { s->failed_pc=0x0c061f3eu; return 0; }
write(ram,r[14],r[2],2);
goto P_0c061f40;
P_0c061f40: /* original b2a6, guest PC 0x0c061f40 */
if(!s->budget--) { s->failed_pc=0x0c061f40u; return 0; }
target=code_base|0x0c062490u; r[16]=code_base|0x0c061f44u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c061f44u) { target=s->pc; goto dispatch; }
goto P_0c061f44;
P_0c061f42: /* original 0009, guest PC 0x0c061f42 */
if(!s->budget--) { s->failed_pc=0x0c061f42u; return 0; }
goto P_0c061f44;
P_0c061f44: /* original 6d03, guest PC 0x0c061f44 */
if(!s->budget--) { s->failed_pc=0x0c061f44u; return 0; }
r[13]=r[0];
goto P_0c061f46;
P_0c061f46: /* original 2dd8, guest PC 0x0c061f46 */
if(!s->budget--) { s->failed_pc=0x0c061f46u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c061f48;
P_0c061f48: /* original 8929, guest PC 0x0c061f48 */
if(!s->budget--) { s->failed_pc=0x0c061f48u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061f9e; }
goto P_0c061f4a;
P_0c061f4a: /* original 66d3, guest PC 0x0c061f4a */
if(!s->budget--) { s->failed_pc=0x0c061f4au; return 0; }
r[6]=r[13];
goto P_0c061f4c;
P_0c061f4c: /* original 52e3, guest PC 0x0c061f4c */
if(!s->budget--) { s->failed_pc=0x0c061f4cu; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c061f4e;
P_0c061f4e: /* original 65a3, guest PC 0x0c061f4e */
if(!s->budget--) { s->failed_pc=0x0c061f4eu; return 0; }
r[5]=r[10];
goto P_0c061f50;
P_0c061f50: /* original 1d23, guest PC 0x0c061f50 */
if(!s->budget--) { s->failed_pc=0x0c061f50u; return 0; }
write(ram,r[13]+12,r[2],4);
goto P_0c061f52;
P_0c061f52: /* original 35bc, guest PC 0x0c061f52 */
if(!s->budget--) { s->failed_pc=0x0c061f52u; return 0; }
r[5]+=r[11];
goto P_0c061f54;
P_0c061f54: /* original 1dc4, guest PC 0x0c061f54 */
if(!s->budget--) { s->failed_pc=0x0c061f54u; return 0; }
write(ram,r[13]+16,r[12],4);
goto P_0c061f56;
P_0c061f56: /* original 54e4, guest PC 0x0c061f56 */
if(!s->budget--) { s->failed_pc=0x0c061f56u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c061f58;
P_0c061f58: /* original 34c8, guest PC 0x0c061f58 */
if(!s->budget--) { s->failed_pc=0x0c061f58u; return 0; }
r[4]-=r[12];
goto P_0c061f5a;
P_0c061f5a: /* original 1e44, guest PC 0x0c061f5a */
if(!s->budget--) { s->failed_pc=0x0c061f5au; return 0; }
write(ram,r[14]+16,r[4],4);
goto P_0c061f5c;
P_0c061f5c: /* original 53e3, guest PC 0x0c061f5c */
if(!s->budget--) { s->failed_pc=0x0c061f5cu; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c061f5e;
P_0c061f5e: /* original 3c3c, guest PC 0x0c061f5e */
if(!s->budget--) { s->failed_pc=0x0c061f5eu; return 0; }
r[12]+=r[3];
goto P_0c061f60;
P_0c061f60: /* original 1ec3, guest PC 0x0c061f60 */
if(!s->budget--) { s->failed_pc=0x0c061f60u; return 0; }
write(ram,r[14]+12,r[12],4);
goto P_0c061f62;
P_0c061f62: /* original 2f52, guest PC 0x0c061f62 */
if(!s->budget--) { s->failed_pc=0x0c061f62u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c061f64;
P_0c061f64: /* original 7504, guest PC 0x0c061f64 */
if(!s->budget--) { s->failed_pc=0x0c061f64u; return 0; }
r[5]+=0x00000004u;
goto P_0c061f66;
P_0c061f66: /* original b2bd, guest PC 0x0c061f66 */
if(!s->budget--) { s->failed_pc=0x0c061f66u; return 0; }
target=code_base|0x0c0624e4u; r[16]=code_base|0x0c061f6au;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c061f6au) { target=s->pc; goto dispatch; }
goto P_0c061f6a;
P_0c061f68: /* original 64f2, guest PC 0x0c061f68 */
if(!s->budget--) { s->failed_pc=0x0c061f68u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c061f6a;
P_0c061f6a: /* original 6083, guest PC 0x0c061f6a */
if(!s->budget--) { s->failed_pc=0x0c061f6au; return 0; }
r[0]=r[8];
goto P_0c061f6c;
P_0c061f6c: /* original 0009, guest PC 0x0c061f6c */
if(!s->budget--) { s->failed_pc=0x0c061f6cu; return 0; }
goto P_0c061f6e;
P_0c061f6e: /* original 8808, guest PC 0x0c061f6e */
if(!s->budget--) { s->failed_pc=0x0c061f6eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c061f70;
P_0c061f70: /* original 8904, guest PC 0x0c061f70 */
if(!s->budget--) { s->failed_pc=0x0c061f70u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061f7c; }
goto P_0c061f72;
P_0c061f72: /* original 9129, guest PC 0x0c061f72 */
if(!s->budget--) { s->failed_pc=0x0c061f72u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c061fc8u,2);
goto P_0c061f74;
P_0c061f74: /* original 3010, guest PC 0x0c061f74 */
if(!s->budget--) { s->failed_pc=0x0c061f74u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c061f76;
P_0c061f76: /* original 8909, guest PC 0x0c061f76 */
if(!s->budget--) { s->failed_pc=0x0c061f76u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061f8c; }
goto P_0c061f78;
P_0c061f78: /* original a011, guest PC 0x0c061f78 */
if(!s->budget--) { s->failed_pc=0x0c061f78u; return 0; }
goto P_0c061f9e;
P_0c061f7a: /* original 0009, guest PC 0x0c061f7a */
if(!s->budget--) { s->failed_pc=0x0c061f7au; return 0; }
goto P_0c061f7c;
P_0c061f7c: /* original 52d3, guest PC 0x0c061f7c */
if(!s->budget--) { s->failed_pc=0x0c061f7cu; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c061f7e;
P_0c061f7e: /* original 6493, guest PC 0x0c061f7e */
if(!s->budget--) { s->failed_pc=0x0c061f7eu; return 0; }
r[4]=r[9];
goto P_0c061f80;
P_0c061f80: /* original 1427, guest PC 0x0c061f80 */
if(!s->budget--) { s->failed_pc=0x0c061f80u; return 0; }
write(ram,r[4]+28,r[2],4);
goto P_0c061f82;
P_0c061f82: /* original 1d45, guest PC 0x0c061f82 */
if(!s->budget--) { s->failed_pc=0x0c061f82u; return 0; }
write(ram,r[13]+20,r[4],4);
goto P_0c061f84;
P_0c061f84: /* original 60d1, guest PC 0x0c061f84 */
if(!s->budget--) { s->failed_pc=0x0c061f84u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[0]=tmp;
goto P_0c061f86;
P_0c061f86: /* original cb08, guest PC 0x0c061f86 */
if(!s->budget--) { s->failed_pc=0x0c061f86u; return 0; }
r[0]|=8u;
goto P_0c061f88;
P_0c061f88: /* original a00b, guest PC 0x0c061f88 */
if(!s->budget--) { s->failed_pc=0x0c061f88u; return 0; }
write(ram,r[13],r[0],2);
goto P_0c061fa2;
P_0c061f8a: /* original 2d01, guest PC 0x0c061f8a */
if(!s->budget--) { s->failed_pc=0x0c061f8au; return 0; }
write(ram,r[13],r[0],2);
goto P_0c061f8c;
P_0c061f8c: /* original 52d3, guest PC 0x0c061f8c */
if(!s->budget--) { s->failed_pc=0x0c061f8cu; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c061f8e;
P_0c061f8e: /* original 6493, guest PC 0x0c061f8e */
if(!s->budget--) { s->failed_pc=0x0c061f8eu; return 0; }
r[4]=r[9];
goto P_0c061f90;
P_0c061f90: /* original 931a, guest PC 0x0c061f90 */
if(!s->budget--) { s->failed_pc=0x0c061f90u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c061fc8u,2);
goto P_0c061f92;
P_0c061f92: /* original 2422, guest PC 0x0c061f92 */
if(!s->budget--) { s->failed_pc=0x0c061f92u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c061f94;
P_0c061f94: /* original 1d45, guest PC 0x0c061f94 */
if(!s->budget--) { s->failed_pc=0x0c061f94u; return 0; }
write(ram,r[13]+20,r[4],4);
goto P_0c061f96;
P_0c061f96: /* original 62d1, guest PC 0x0c061f96 */
if(!s->budget--) { s->failed_pc=0x0c061f96u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[2]=tmp;
goto P_0c061f98;
P_0c061f98: /* original 223b, guest PC 0x0c061f98 */
if(!s->budget--) { s->failed_pc=0x0c061f98u; return 0; }
r[2]|=r[3];
goto P_0c061f9a;
P_0c061f9a: /* original a002, guest PC 0x0c061f9a */
if(!s->budget--) { s->failed_pc=0x0c061f9au; return 0; }
write(ram,r[13],r[2],2);
goto P_0c061fa2;
P_0c061f9c: /* original 2d21, guest PC 0x0c061f9c */
if(!s->budget--) { s->failed_pc=0x0c061f9cu; return 0; }
write(ram,r[13],r[2],2);
goto P_0c061f9e;
P_0c061f9e: /* original a009, guest PC 0x0c061f9e */
if(!s->budget--) { s->failed_pc=0x0c061f9eu; return 0; }
r[0]=0x00000003u;
goto P_0c061fb4;
P_0c061fa0: /* original e003, guest PC 0x0c061fa0 */
if(!s->budget--) { s->failed_pc=0x0c061fa0u; return 0; }
r[0]=0x00000003u;
goto P_0c061fa2;
P_0c061fa2: /* original 3abc, guest PC 0x0c061fa2 */
if(!s->budget--) { s->failed_pc=0x0c061fa2u; return 0; }
r[10]+=r[11];
goto P_0c061fa4;
P_0c061fa4: /* original 60d1, guest PC 0x0c061fa4 */
if(!s->budget--) { s->failed_pc=0x0c061fa4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[0]=tmp;
goto P_0c061fa6;
P_0c061fa6: /* original cb04, guest PC 0x0c061fa6 */
if(!s->budget--) { s->failed_pc=0x0c061fa6u; return 0; }
r[0]|=4u;
goto P_0c061fa8;
P_0c061fa8: /* original 2d01, guest PC 0x0c061fa8 */
if(!s->budget--) { s->failed_pc=0x0c061fa8u; return 0; }
write(ram,r[13],r[0],2);
goto P_0c061faa;
P_0c061faa: /* original 53d4, guest PC 0x0c061faa */
if(!s->budget--) { s->failed_pc=0x0c061faau; return 0; }
r[3]=read(ram,r[13]+16,4);
goto P_0c061fac;
P_0c061fac: /* original 52a4, guest PC 0x0c061fac */
if(!s->budget--) { s->failed_pc=0x0c061facu; return 0; }
r[2]=read(ram,r[10]+16,4);
goto P_0c061fae;
P_0c061fae: /* original 3238, guest PC 0x0c061fae */
if(!s->budget--) { s->failed_pc=0x0c061faeu; return 0; }
r[2]-=r[3];
goto P_0c061fb0;
P_0c061fb0: /* original 1a24, guest PC 0x0c061fb0 */
if(!s->budget--) { s->failed_pc=0x0c061fb0u; return 0; }
write(ram,r[10]+16,r[2],4);
goto P_0c061fb2;
P_0c061fb2: /* original e000, guest PC 0x0c061fb2 */
if(!s->budget--) { s->failed_pc=0x0c061fb2u; return 0; }
r[0]=0x00000000u;
goto P_0c061fb4;
P_0c061fb4: /* original 7f04, guest PC 0x0c061fb4 */
if(!s->budget--) { s->failed_pc=0x0c061fb4u; return 0; }
r[15]+=0x00000004u;
goto P_0c061fb6;
P_0c061fb6: /* original 4f26, guest PC 0x0c061fb6 */
if(!s->budget--) { s->failed_pc=0x0c061fb6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c061fb8;
P_0c061fb8: /* original 68f6, guest PC 0x0c061fb8 */
if(!s->budget--) { s->failed_pc=0x0c061fb8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c061fba;
P_0c061fba: /* original 69f6, guest PC 0x0c061fba */
if(!s->budget--) { s->failed_pc=0x0c061fbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c061fbc;
P_0c061fbc: /* original 6af6, guest PC 0x0c061fbc */
if(!s->budget--) { s->failed_pc=0x0c061fbcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c061fbe;
P_0c061fbe: /* original 6bf6, guest PC 0x0c061fbe */
if(!s->budget--) { s->failed_pc=0x0c061fbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c061fc0;
P_0c061fc0: /* original 6cf6, guest PC 0x0c061fc0 */
if(!s->budget--) { s->failed_pc=0x0c061fc0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c061fc2;
P_0c061fc2: /* original 6df6, guest PC 0x0c061fc2 */
if(!s->budget--) { s->failed_pc=0x0c061fc2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c061fc4;
P_0c061fc4: /* original 000b, guest PC 0x0c061fc4 */
if(!s->budget--) { s->failed_pc=0x0c061fc4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c061fc6: /* original 6ef6, guest PC 0x0c061fc6 */
if(!s->budget--) { s->failed_pc=0x0c061fc6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c061fc8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c061fc8u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
