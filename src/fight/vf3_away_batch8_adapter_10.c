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
int vf3_away_batch8_adapter_10(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c060d14u: goto P_0c060d14;
case 0x0c060d16u: goto P_0c060d16;
case 0x0c060d18u: goto P_0c060d18;
case 0x0c060d1au: goto P_0c060d1a;
case 0x0c060d1cu: goto P_0c060d1c;
case 0x0c060d1eu: goto P_0c060d1e;
case 0x0c060d20u: goto P_0c060d20;
case 0x0c060d22u: goto P_0c060d22;
case 0x0c060d24u: goto P_0c060d24;
case 0x0c060d26u: goto P_0c060d26;
case 0x0c060d28u: goto P_0c060d28;
case 0x0c060d2au: goto P_0c060d2a;
case 0x0c060d2cu: goto P_0c060d2c;
case 0x0c060d2eu: goto P_0c060d2e;
case 0x0c060d30u: goto P_0c060d30;
case 0x0c060d32u: goto P_0c060d32;
case 0x0c060d34u: goto P_0c060d34;
case 0x0c060d36u: goto P_0c060d36;
case 0x0c060d38u: goto P_0c060d38;
case 0x0c060d3au: goto P_0c060d3a;
case 0x0c060d3cu: goto P_0c060d3c;
case 0x0c060d3eu: goto P_0c060d3e;
case 0x0c060d40u: goto P_0c060d40;
case 0x0c060d42u: goto P_0c060d42;
case 0x0c060d44u: goto P_0c060d44;
case 0x0c060d46u: goto P_0c060d46;
case 0x0c060d48u: goto P_0c060d48;
case 0x0c060d4au: goto P_0c060d4a;
case 0x0c060d78u: goto P_0c060d78;
case 0x0c060d7au: goto P_0c060d7a;
case 0x0c060d7cu: goto P_0c060d7c;
case 0x0c060d7eu: goto P_0c060d7e;
case 0x0c060d80u: goto P_0c060d80;
case 0x0c060d82u: goto P_0c060d82;
case 0x0c060d84u: goto P_0c060d84;
case 0x0c060d86u: goto P_0c060d86;
case 0x0c060d88u: goto P_0c060d88;
case 0x0c060d8au: goto P_0c060d8a;
case 0x0c060d8cu: goto P_0c060d8c;
case 0x0c060d8eu: goto P_0c060d8e;
case 0x0c060d90u: goto P_0c060d90;
case 0x0c060d92u: goto P_0c060d92;
case 0x0c060d94u: goto P_0c060d94;
case 0x0c060d96u: goto P_0c060d96;
case 0x0c060d98u: goto P_0c060d98;
case 0x0c060d9au: goto P_0c060d9a;
case 0x0c060d9cu: goto P_0c060d9c;
case 0x0c060d9eu: goto P_0c060d9e;
case 0x0c060da0u: goto P_0c060da0;
case 0x0c060da2u: goto P_0c060da2;
case 0x0c060da4u: goto P_0c060da4;
case 0x0c060da6u: goto P_0c060da6;
case 0x0c060da8u: goto P_0c060da8;
case 0x0c060daau: goto P_0c060daa;
case 0x0c060dacu: goto P_0c060dac;
case 0x0c060daeu: goto P_0c060dae;
case 0x0c060db0u: goto P_0c060db0;
case 0x0c060db2u: goto P_0c060db2;
case 0x0c060db4u: goto P_0c060db4;
case 0x0c060db6u: goto P_0c060db6;
case 0x0c060db8u: goto P_0c060db8;
case 0x0c060dbau: goto P_0c060dba;
case 0x0c060dbcu: goto P_0c060dbc;
case 0x0c060dbeu: goto P_0c060dbe;
case 0x0c060dc0u: goto P_0c060dc0;
case 0x0c060dc2u: goto P_0c060dc2;
case 0x0c060dc4u: goto P_0c060dc4;
case 0x0c060dc6u: goto P_0c060dc6;
case 0x0c060dc8u: goto P_0c060dc8;
case 0x0c060dcau: goto P_0c060dca;
case 0x0c060dccu: goto P_0c060dcc;
case 0x0c060dceu: goto P_0c060dce;
case 0x0c060dd0u: goto P_0c060dd0;
case 0x0c060dd2u: goto P_0c060dd2;
case 0x0c060dd4u: goto P_0c060dd4;
case 0x0c060dd6u: goto P_0c060dd6;
case 0x0c060dd8u: goto P_0c060dd8;
case 0x0c060ddau: goto P_0c060dda;
case 0x0c060ddcu: goto P_0c060ddc;
case 0x0c060ddeu: goto P_0c060dde;
case 0x0c060de0u: goto P_0c060de0;
case 0x0c060de2u: goto P_0c060de2;
case 0x0c060de4u: goto P_0c060de4;
case 0x0c060de6u: goto P_0c060de6;
case 0x0c060de8u: goto P_0c060de8;
case 0x0c060deau: goto P_0c060dea;
case 0x0c060decu: goto P_0c060dec;
case 0x0c060deeu: goto P_0c060dee;
case 0x0c060df0u: goto P_0c060df0;
case 0x0c060df2u: goto P_0c060df2;
case 0x0c060df4u: goto P_0c060df4;
case 0x0c060df6u: goto P_0c060df6;
case 0x0c060df8u: goto P_0c060df8;
case 0x0c060dfau: goto P_0c060dfa;
case 0x0c060dfcu: goto P_0c060dfc;
case 0x0c060dfeu: goto P_0c060dfe;
case 0x0c060e00u: goto P_0c060e00;
case 0x0c060e02u: goto P_0c060e02;
case 0x0c060e04u: goto P_0c060e04;
case 0x0c060e06u: goto P_0c060e06;
case 0x0c060e08u: goto P_0c060e08;
case 0x0c060e0au: goto P_0c060e0a;
case 0x0c060e0cu: goto P_0c060e0c;
case 0x0c060e0eu: goto P_0c060e0e;
case 0x0c060e10u: goto P_0c060e10;
case 0x0c060e12u: goto P_0c060e12;
case 0x0c060e14u: goto P_0c060e14;
case 0x0c060e16u: goto P_0c060e16;
case 0x0c060e18u: goto P_0c060e18;
case 0x0c060e1au: goto P_0c060e1a;
case 0x0c060e1cu: goto P_0c060e1c;
case 0x0c060e1eu: goto P_0c060e1e;
case 0x0c060e20u: goto P_0c060e20;
case 0x0c060e22u: goto P_0c060e22;
case 0x0c060e24u: goto P_0c060e24;
case 0x0c060f28u: goto P_0c060f28;
case 0x0c060f2au: goto P_0c060f2a;
case 0x0c060f2cu: goto P_0c060f2c;
case 0x0c060f2eu: goto P_0c060f2e;
case 0x0c060f30u: goto P_0c060f30;
case 0x0c060f32u: goto P_0c060f32;
case 0x0c060f34u: goto P_0c060f34;
case 0x0c060f36u: goto P_0c060f36;
case 0x0c060f38u: goto P_0c060f38;
case 0x0c060f3au: goto P_0c060f3a;
case 0x0c060f3cu: goto P_0c060f3c;
case 0x0c060f3eu: goto P_0c060f3e;
case 0x0c060f40u: goto P_0c060f40;
case 0x0c060f42u: goto P_0c060f42;
case 0x0c060f44u: goto P_0c060f44;
case 0x0c060f46u: goto P_0c060f46;
case 0x0c060f48u: goto P_0c060f48;
case 0x0c060f4au: goto P_0c060f4a;
case 0x0c060f4cu: goto P_0c060f4c;
case 0x0c060f4eu: goto P_0c060f4e;
case 0x0c060f50u: goto P_0c060f50;
case 0x0c060f52u: goto P_0c060f52;
case 0x0c060f54u: goto P_0c060f54;
case 0x0c060f56u: goto P_0c060f56;
case 0x0c060f58u: goto P_0c060f58;
case 0x0c060f5au: goto P_0c060f5a;
case 0x0c060f5cu: goto P_0c060f5c;
case 0x0c060f5eu: goto P_0c060f5e;
case 0x0c060f60u: goto P_0c060f60;
case 0x0c060f62u: goto P_0c060f62;
case 0x0c060f64u: goto P_0c060f64;
case 0x0c060f66u: goto P_0c060f66;
case 0x0c060f68u: goto P_0c060f68;
case 0x0c060f6au: goto P_0c060f6a;
case 0x0c060f6cu: goto P_0c060f6c;
case 0x0c060f6eu: goto P_0c060f6e;
case 0x0c060f70u: goto P_0c060f70;
case 0x0c060f72u: goto P_0c060f72;
case 0x0c060f74u: goto P_0c060f74;
case 0x0c060f76u: goto P_0c060f76;
case 0x0c060f78u: goto P_0c060f78;
case 0x0c060f7au: goto P_0c060f7a;
case 0x0c060f7cu: goto P_0c060f7c;
case 0x0c060f7eu: goto P_0c060f7e;
case 0x0c060f80u: goto P_0c060f80;
case 0x0c060f82u: goto P_0c060f82;
case 0x0c060f84u: goto P_0c060f84;
case 0x0c060f86u: goto P_0c060f86;
case 0x0c060f88u: goto P_0c060f88;
case 0x0c060f8au: goto P_0c060f8a;
case 0x0c060f8cu: goto P_0c060f8c;
case 0x0c060f8eu: goto P_0c060f8e;
case 0x0c060f90u: goto P_0c060f90;
case 0x0c060f92u: goto P_0c060f92;
case 0x0c060f94u: goto P_0c060f94;
case 0x0c060f96u: goto P_0c060f96;
case 0x0c060f98u: goto P_0c060f98;
case 0x0c060f9au: goto P_0c060f9a;
case 0x0c060f9cu: goto P_0c060f9c;
case 0x0c060f9eu: goto P_0c060f9e;
case 0x0c060fa0u: goto P_0c060fa0;
case 0x0c060fa2u: goto P_0c060fa2;
case 0x0c060fa4u: goto P_0c060fa4;
case 0x0c060fa6u: goto P_0c060fa6;
case 0x0c060fa8u: goto P_0c060fa8;
case 0x0c060faau: goto P_0c060faa;
case 0x0c060facu: goto P_0c060fac;
case 0x0c060faeu: goto P_0c060fae;
case 0x0c060fb0u: goto P_0c060fb0;
case 0x0c060fb2u: goto P_0c060fb2;
case 0x0c060fb4u: goto P_0c060fb4;
case 0x0c060fb6u: goto P_0c060fb6;
case 0x0c060fb8u: goto P_0c060fb8;
case 0x0c060fbau: goto P_0c060fba;
case 0x0c060fbcu: goto P_0c060fbc;
case 0x0c060fbeu: goto P_0c060fbe;
case 0x0c060fc0u: goto P_0c060fc0;
case 0x0c060fc2u: goto P_0c060fc2;
case 0x0c060fc4u: goto P_0c060fc4;
case 0x0c060fc6u: goto P_0c060fc6;
case 0x0c060fc8u: goto P_0c060fc8;
case 0x0c060fcau: goto P_0c060fca;
case 0x0c060fccu: goto P_0c060fcc;
case 0x0c060fceu: goto P_0c060fce;
case 0x0c060fd0u: goto P_0c060fd0;
case 0x0c060fd2u: goto P_0c060fd2;
case 0x0c060fd4u: goto P_0c060fd4;
case 0x0c060fd6u: goto P_0c060fd6;
case 0x0c060fd8u: goto P_0c060fd8;
case 0x0c060fdau: goto P_0c060fda;
case 0x0c060fdcu: goto P_0c060fdc;
case 0x0c060fdeu: goto P_0c060fde;
case 0x0c060fe0u: goto P_0c060fe0;
case 0x0c060fe2u: goto P_0c060fe2;
case 0x0c060fe4u: goto P_0c060fe4;
case 0x0c060fe6u: goto P_0c060fe6;
case 0x0c060fe8u: goto P_0c060fe8;
case 0x0c060feau: goto P_0c060fea;
case 0x0c060fecu: goto P_0c060fec;
case 0x0c060feeu: goto P_0c060fee;
case 0x0c060ff0u: goto P_0c060ff0;
case 0x0c060ff2u: goto P_0c060ff2;
case 0x0c060ff4u: goto P_0c060ff4;
case 0x0c060ff6u: goto P_0c060ff6;
case 0x0c060ff8u: goto P_0c060ff8;
case 0x0c060ffau: goto P_0c060ffa;
case 0x0c060ffcu: goto P_0c060ffc;
case 0x0c060ffeu: goto P_0c060ffe;
case 0x0c061000u: goto P_0c061000;
case 0x0c061002u: goto P_0c061002;
case 0x0c061004u: goto P_0c061004;
case 0x0c061006u: goto P_0c061006;
case 0x0c061008u: goto P_0c061008;
case 0x0c06100au: goto P_0c06100a;
case 0x0c06100cu: goto P_0c06100c;
case 0x0c061054u: goto P_0c061054;
case 0x0c061056u: goto P_0c061056;
case 0x0c061058u: goto P_0c061058;
case 0x0c06105au: goto P_0c06105a;
case 0x0c06105cu: goto P_0c06105c;
case 0x0c06105eu: goto P_0c06105e;
case 0x0c061060u: goto P_0c061060;
case 0x0c061062u: goto P_0c061062;
case 0x0c061064u: goto P_0c061064;
case 0x0c061066u: goto P_0c061066;
case 0x0c061068u: goto P_0c061068;
case 0x0c06106au: goto P_0c06106a;
case 0x0c06106cu: goto P_0c06106c;
case 0x0c06106eu: goto P_0c06106e;
case 0x0c061070u: goto P_0c061070;
case 0x0c061072u: goto P_0c061072;
case 0x0c061074u: goto P_0c061074;
case 0x0c061076u: goto P_0c061076;
case 0x0c061078u: goto P_0c061078;
case 0x0c06107au: goto P_0c06107a;
case 0x0c06107cu: goto P_0c06107c;
case 0x0c06107eu: goto P_0c06107e;
case 0x0c061080u: goto P_0c061080;
case 0x0c061082u: goto P_0c061082;
case 0x0c061084u: goto P_0c061084;
case 0x0c061086u: goto P_0c061086;
case 0x0c061088u: goto P_0c061088;
case 0x0c06108au: goto P_0c06108a;
case 0x0c06108cu: goto P_0c06108c;
case 0x0c06108eu: goto P_0c06108e;
case 0x0c061090u: goto P_0c061090;
case 0x0c061092u: goto P_0c061092;
case 0x0c061094u: goto P_0c061094;
case 0x0c061096u: goto P_0c061096;
case 0x0c061098u: goto P_0c061098;
case 0x0c06109au: goto P_0c06109a;
case 0x0c06109cu: goto P_0c06109c;
case 0x0c06109eu: goto P_0c06109e;
case 0x0c0610a0u: goto P_0c0610a0;
case 0x0c0610a2u: goto P_0c0610a2;
case 0x0c0610a4u: goto P_0c0610a4;
case 0x0c0610a6u: goto P_0c0610a6;
case 0x0c0610a8u: goto P_0c0610a8;
case 0x0c0610aau: goto P_0c0610aa;
case 0x0c0610acu: goto P_0c0610ac;
case 0x0c0610aeu: goto P_0c0610ae;
case 0x0c0610b0u: goto P_0c0610b0;
case 0x0c0610b2u: goto P_0c0610b2;
case 0x0c0610b4u: goto P_0c0610b4;
case 0x0c0610b6u: goto P_0c0610b6;
case 0x0c0610b8u: goto P_0c0610b8;
case 0x0c0610bau: goto P_0c0610ba;
case 0x0c0610bcu: goto P_0c0610bc;
case 0x0c0610beu: goto P_0c0610be;
case 0x0c0610c0u: goto P_0c0610c0;
case 0x0c0610c2u: goto P_0c0610c2;
case 0x0c0610c4u: goto P_0c0610c4;
case 0x0c0610c6u: goto P_0c0610c6;
case 0x0c0610c8u: goto P_0c0610c8;
case 0x0c0610cau: goto P_0c0610ca;
case 0x0c0610ccu: goto P_0c0610cc;
case 0x0c0610ceu: goto P_0c0610ce;
case 0x0c0610d0u: goto P_0c0610d0;
case 0x0c0610d2u: goto P_0c0610d2;
case 0x0c0610d4u: goto P_0c0610d4;
case 0x0c0610d6u: goto P_0c0610d6;
case 0x0c0610d8u: goto P_0c0610d8;
case 0x0c0610dau: goto P_0c0610da;
case 0x0c0610dcu: goto P_0c0610dc;
case 0x0c0610deu: goto P_0c0610de;
case 0x0c0610e0u: goto P_0c0610e0;
case 0x0c0610e2u: goto P_0c0610e2;
case 0x0c0610e4u: goto P_0c0610e4;
case 0x0c0610e6u: goto P_0c0610e6;
case 0x0c0610e8u: goto P_0c0610e8;
case 0x0c0610eau: goto P_0c0610ea;
case 0x0c0610ecu: goto P_0c0610ec;
case 0x0c0610eeu: goto P_0c0610ee;
case 0x0c0610f0u: goto P_0c0610f0;
case 0x0c0610f2u: goto P_0c0610f2;
case 0x0c0610f4u: goto P_0c0610f4;
case 0x0c0610f6u: goto P_0c0610f6;
case 0x0c0610f8u: goto P_0c0610f8;
case 0x0c0610fau: goto P_0c0610fa;
case 0x0c0610fcu: goto P_0c0610fc;
case 0x0c0610feu: goto P_0c0610fe;
case 0x0c061100u: goto P_0c061100;
case 0x0c061102u: goto P_0c061102;
case 0x0c061104u: goto P_0c061104;
case 0x0c061106u: goto P_0c061106;
case 0x0c061108u: goto P_0c061108;
case 0x0c06110au: goto P_0c06110a;
case 0x0c06110cu: goto P_0c06110c;
case 0x0c06110eu: goto P_0c06110e;
case 0x0c061110u: goto P_0c061110;
case 0x0c061112u: goto P_0c061112;
case 0x0c061114u: goto P_0c061114;
case 0x0c061116u: goto P_0c061116;
case 0x0c061118u: goto P_0c061118;
case 0x0c06111au: goto P_0c06111a;
case 0x0c06111cu: goto P_0c06111c;
case 0x0c06111eu: goto P_0c06111e;
case 0x0c061120u: goto P_0c061120;
case 0x0c061122u: goto P_0c061122;
case 0x0c061124u: goto P_0c061124;
case 0x0c061126u: goto P_0c061126;
case 0x0c061128u: goto P_0c061128;
case 0x0c06112au: goto P_0c06112a;
case 0x0c06112cu: goto P_0c06112c;
case 0x0c06112eu: goto P_0c06112e;
case 0x0c061130u: goto P_0c061130;
case 0x0c061132u: goto P_0c061132;
case 0x0c061134u: goto P_0c061134;
case 0x0c061136u: goto P_0c061136;
case 0x0c061138u: goto P_0c061138;
case 0x0c06113au: goto P_0c06113a;
case 0x0c06113cu: goto P_0c06113c;
case 0x0c06113eu: goto P_0c06113e;
case 0x0c061140u: goto P_0c061140;
default: return vf3_matrix_family(target,s,ram);
}
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
goto P_0c060d1e;
P_0c060d1e: /* original 2fe6, guest PC 0x0c060d1e */
if(!s->budget--) { s->failed_pc=0x0c060d1eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060d20;
P_0c060d20: /* original 2fd6, guest PC 0x0c060d20 */
if(!s->budget--) { s->failed_pc=0x0c060d20u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060d22;
P_0c060d22: /* original 6e43, guest PC 0x0c060d22 */
if(!s->budget--) { s->failed_pc=0x0c060d22u; return 0; }
r[14]=r[4];
goto P_0c060d24;
P_0c060d24: /* original 2fc6, guest PC 0x0c060d24 */
if(!s->budget--) { s->failed_pc=0x0c060d24u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060d26;
P_0c060d26: /* original 6d43, guest PC 0x0c060d26 */
if(!s->budget--) { s->failed_pc=0x0c060d26u; return 0; }
r[13]=r[4];
goto P_0c060d28;
P_0c060d28: /* original 4f22, guest PC 0x0c060d28 */
if(!s->budget--) { s->failed_pc=0x0c060d28u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c060d2a;
P_0c060d2a: /* original 3d5c, guest PC 0x0c060d2a */
if(!s->budget--) { s->failed_pc=0x0c060d2au; return 0; }
r[13]+=r[5];
goto P_0c060d2c;
P_0c060d2c: /* original dc3f, guest PC 0x0c060d2c */
if(!s->budget--) { s->failed_pc=0x0c060d2cu; return 0; }
r[12]=read(ram,0x0c060e2cu,4);
goto P_0c060d2e;
P_0c060d2e: /* original 3ed6, guest PC 0x0c060d2e */
if(!s->budget--) { s->failed_pc=0x0c060d2eu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[13])!=0);
goto P_0c060d30;
P_0c060d30: /* original 8904, guest PC 0x0c060d30 */
if(!s->budget--) { s->failed_pc=0x0c060d30u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060d3c; }
goto P_0c060d32;
P_0c060d32: /* original 4c0b, guest PC 0x0c060d32 */
if(!s->budget--) { s->failed_pc=0x0c060d32u; return 0; }
target=r[12];
r[16]=code_base|0x0c060d36u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060d36u) { target=s->pc; goto dispatch; }
goto P_0c060d36;
P_0c060d34: /* original 64e3, guest PC 0x0c060d34 */
if(!s->budget--) { s->failed_pc=0x0c060d34u; return 0; }
r[4]=r[14];
goto P_0c060d36;
P_0c060d36: /* original 7e20, guest PC 0x0c060d36 */
if(!s->budget--) { s->failed_pc=0x0c060d36u; return 0; }
r[14]+=0x00000020u;
goto P_0c060d38;
P_0c060d38: /* original 3ed6, guest PC 0x0c060d38 */
if(!s->budget--) { s->failed_pc=0x0c060d38u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[13])!=0);
goto P_0c060d3a;
P_0c060d3a: /* original 8bfa, guest PC 0x0c060d3a */
if(!s->budget--) { s->failed_pc=0x0c060d3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060d32; }
goto P_0c060d3c;
P_0c060d3c: /* original 4f26, guest PC 0x0c060d3c */
if(!s->budget--) { s->failed_pc=0x0c060d3cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c060d3e;
P_0c060d3e: /* original 6cf6, guest PC 0x0c060d3e */
if(!s->budget--) { s->failed_pc=0x0c060d3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c060d40;
P_0c060d40: /* original 6df6, guest PC 0x0c060d40 */
if(!s->budget--) { s->failed_pc=0x0c060d40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c060d42;
P_0c060d42: /* original 000b, guest PC 0x0c060d42 */
if(!s->budget--) { s->failed_pc=0x0c060d42u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c060d44: /* original 6ef6, guest PC 0x0c060d44 */
if(!s->budget--) { s->failed_pc=0x0c060d44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c060d46;
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
P_0c060d78: /* original 2fe6, guest PC 0x0c060d78 */
if(!s->budget--) { s->failed_pc=0x0c060d78u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060d7a;
P_0c060d7a: /* original 0002, guest PC 0x0c060d7a */
if(!s->budget--) { s->failed_pc=0x0c060d7au; return 0; }
r[0]=r[17];
goto P_0c060d7c;
P_0c060d7c: /* original 2fd6, guest PC 0x0c060d7c */
if(!s->budget--) { s->failed_pc=0x0c060d7cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060d7e;
P_0c060d7e: /* original 6e53, guest PC 0x0c060d7e */
if(!s->budget--) { s->failed_pc=0x0c060d7eu; return 0; }
r[14]=r[5];
goto P_0c060d80;
P_0c060d80: /* original 2fc6, guest PC 0x0c060d80 */
if(!s->budget--) { s->failed_pc=0x0c060d80u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060d82;
P_0c060d82: /* original 6d43, guest PC 0x0c060d82 */
if(!s->budget--) { s->failed_pc=0x0c060d82u; return 0; }
r[13]=r[4];
goto P_0c060d84;
P_0c060d84: /* original 2fb6, guest PC 0x0c060d84 */
if(!s->budget--) { s->failed_pc=0x0c060d84u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060d86;
P_0c060d86: /* original 4009, guest PC 0x0c060d86 */
if(!s->budget--) { s->failed_pc=0x0c060d86u; return 0; }
r[0]>>=2;
goto P_0c060d88;
P_0c060d88: /* original 2fa6, guest PC 0x0c060d88 */
if(!s->budget--) { s->failed_pc=0x0c060d88u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060d8a;
P_0c060d8a: /* original 63d3, guest PC 0x0c060d8a */
if(!s->budget--) { s->failed_pc=0x0c060d8au; return 0; }
r[3]=r[13];
goto P_0c060d8c;
P_0c060d8c: /* original 2f96, guest PC 0x0c060d8c */
if(!s->budget--) { s->failed_pc=0x0c060d8cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060d8e;
P_0c060d8e: /* original 6a63, guest PC 0x0c060d8e */
if(!s->budget--) { s->failed_pc=0x0c060d8eu; return 0; }
r[10]=r[6];
goto P_0c060d90;
P_0c060d90: /* original 2f86, guest PC 0x0c060d90 */
if(!s->budget--) { s->failed_pc=0x0c060d90u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060d92;
P_0c060d92: /* original 4009, guest PC 0x0c060d92 */
if(!s->budget--) { s->failed_pc=0x0c060d92u; return 0; }
r[0]>>=2;
goto P_0c060d94;
P_0c060d94: /* original 4f22, guest PC 0x0c060d94 */
if(!s->budget--) { s->failed_pc=0x0c060d94u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c060d96;
P_0c060d96: /* original e91f, guest PC 0x0c060d96 */
if(!s->budget--) { s->failed_pc=0x0c060d96u; return 0; }
r[9]=0x0000001fu;
goto P_0c060d98;
P_0c060d98: /* original 7ffc, guest PC 0x0c060d98 */
if(!s->budget--) { s->failed_pc=0x0c060d98u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c060d9a;
P_0c060d9a: /* original c90f, guest PC 0x0c060d9a */
if(!s->budget--) { s->failed_pc=0x0c060d9au; return 0; }
r[0]&=15u;
goto P_0c060d9c;
P_0c060d9c: /* original 2398, guest PC 0x0c060d9c */
if(!s->budget--) { s->failed_pc=0x0c060d9cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c060d9e;
P_0c060d9e: /* original 8f31, guest PC 0x0c060d9e */
if(!s->budget--) { s->failed_pc=0x0c060d9eu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c060e04; }
goto P_0c060da2;
P_0c060da0: /* original 6403, guest PC 0x0c060da0 */
if(!s->budget--) { s->failed_pc=0x0c060da0u; return 0; }
r[4]=r[0];
goto P_0c060da2;
P_0c060da2: /* original 61e3, guest PC 0x0c060da2 */
if(!s->budget--) { s->failed_pc=0x0c060da2u; return 0; }
r[1]=r[14];
goto P_0c060da4;
P_0c060da4: /* original 2198, guest PC 0x0c060da4 */
if(!s->budget--) { s->failed_pc=0x0c060da4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[9])==0)!=0);
goto P_0c060da6;
P_0c060da6: /* original 8b2d, guest PC 0x0c060da6 */
if(!s->budget--) { s->failed_pc=0x0c060da6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060e04; }
goto P_0c060da8;
P_0c060da8: /* original 2448, guest PC 0x0c060da8 */
if(!s->budget--) { s->failed_pc=0x0c060da8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c060daa;
P_0c060daa: /* original 8b2b, guest PC 0x0c060daa */
if(!s->budget--) { s->failed_pc=0x0c060daau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060e04; }
goto P_0c060dac;
P_0c060dac: /* original 65a3, guest PC 0x0c060dac */
if(!s->budget--) { s->failed_pc=0x0c060dacu; return 0; }
r[5]=r[10];
goto P_0c060dae;
P_0c060dae: /* original bfb6, guest PC 0x0c060dae */
if(!s->budget--) { s->failed_pc=0x0c060daeu; return 0; }
target=code_base|0x0c060d1eu; r[16]=code_base|0x0c060db2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060db2u) { target=s->pc; goto dispatch; }
goto P_0c060db2;
P_0c060db0: /* original 64e3, guest PC 0x0c060db0 */
if(!s->budget--) { s->failed_pc=0x0c060db0u; return 0; }
r[4]=r[14];
goto P_0c060db2;
P_0c060db2: /* original ece0, guest PC 0x0c060db2 */
if(!s->budget--) { s->failed_pc=0x0c060db2u; return 0; }
r[12]=0xffffffe0u;
goto P_0c060db4;
P_0c060db4: /* original d820, guest PC 0x0c060db4 */
if(!s->budget--) { s->failed_pc=0x0c060db4u; return 0; }
r[8]=read(ram,0x0c060e38u,4);
goto P_0c060db6;
P_0c060db6: /* original 2ca9, guest PC 0x0c060db6 */
if(!s->budget--) { s->failed_pc=0x0c060db6u; return 0; }
r[12]&=r[10];
goto P_0c060db8;
P_0c060db8: /* original 9b35, guest PC 0x0c060db8 */
if(!s->budget--) { s->failed_pc=0x0c060db8u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060e26u,2);
goto P_0c060dba;
P_0c060dba: /* original 38dc, guest PC 0x0c060dba */
if(!s->budget--) { s->failed_pc=0x0c060dbau; return 0; }
r[8]+=r[13];
goto P_0c060dbc;
P_0c060dbc: /* original d21f, guest PC 0x0c060dbc */
if(!s->budget--) { s->failed_pc=0x0c060dbcu; return 0; }
r[2]=read(ram,0x0c060e3cu,4);
goto P_0c060dbe;
P_0c060dbe: /* original 63f3, guest PC 0x0c060dbe */
if(!s->budget--) { s->failed_pc=0x0c060dbeu; return 0; }
r[3]=r[15];
goto P_0c060dc0;
P_0c060dc0: /* original 2f36, guest PC 0x0c060dc0 */
if(!s->budget--) { s->failed_pc=0x0c060dc0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060dc2;
P_0c060dc2: /* original e718, guest PC 0x0c060dc2 */
if(!s->budget--) { s->failed_pc=0x0c060dc2u; return 0; }
r[7]=0x00000018u;
goto P_0c060dc4;
P_0c060dc4: /* original 66c3, guest PC 0x0c060dc4 */
if(!s->budget--) { s->failed_pc=0x0c060dc4u; return 0; }
r[6]=r[12];
goto P_0c060dc6;
P_0c060dc6: /* original 65e3, guest PC 0x0c060dc6 */
if(!s->budget--) { s->failed_pc=0x0c060dc6u; return 0; }
r[5]=r[14];
goto P_0c060dc8;
P_0c060dc8: /* original 420b, guest PC 0x0c060dc8 */
if(!s->budget--) { s->failed_pc=0x0c060dc8u; return 0; }
target=r[2];
r[16]=code_base|0x0c060dccu;
r[4]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060dccu) { target=s->pc; goto dispatch; }
goto P_0c060dcc;
P_0c060dca: /* original 6483, guest PC 0x0c060dca */
if(!s->budget--) { s->failed_pc=0x0c060dcau; return 0; }
r[4]=r[8];
goto P_0c060dcc;
P_0c060dcc: /* original 30b0, guest PC 0x0c060dcc */
if(!s->budget--) { s->failed_pc=0x0c060dccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[11])!=0);
goto P_0c060dce;
P_0c060dce: /* original 8df5, guest PC 0x0c060dce */
if(!s->budget--) { s->failed_pc=0x0c060dceu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c060dbc; }
goto P_0c060dd2;
P_0c060dd0: /* original 7f04, guest PC 0x0c060dd0 */
if(!s->budget--) { s->failed_pc=0x0c060dd0u; return 0; }
r[15]+=0x00000004u;
goto P_0c060dd2;
P_0c060dd2: /* original 62f2, guest PC 0x0c060dd2 */
if(!s->budget--) { s->failed_pc=0x0c060dd2u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c060dd4;
P_0c060dd4: /* original d11a, guest PC 0x0c060dd4 */
if(!s->budget--) { s->failed_pc=0x0c060dd4u; return 0; }
r[1]=read(ram,0x0c060e40u,4);
goto P_0c060dd6;
P_0c060dd6: /* original 6322, guest PC 0x0c060dd6 */
if(!s->budget--) { s->failed_pc=0x0c060dd6u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c060dd8;
P_0c060dd8: /* original 2132, guest PC 0x0c060dd8 */
if(!s->budget--) { s->failed_pc=0x0c060dd8u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c060dda;
P_0c060dda: /* original 66a3, guest PC 0x0c060dda */
if(!s->budget--) { s->failed_pc=0x0c060ddau; return 0; }
r[6]=r[10];
goto P_0c060ddc;
P_0c060ddc: /* original 2699, guest PC 0x0c060ddc */
if(!s->budget--) { s->failed_pc=0x0c060ddcu; return 0; }
r[6]&=r[9];
goto P_0c060dde;
P_0c060dde: /* original 2668, guest PC 0x0c060dde */
if(!s->budget--) { s->failed_pc=0x0c060ddeu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c060de0;
P_0c060de0: /* original 8906, guest PC 0x0c060de0 */
if(!s->budget--) { s->failed_pc=0x0c060de0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060df0; }
goto P_0c060de2;
P_0c060de2: /* original 3dcc, guest PC 0x0c060de2 */
if(!s->budget--) { s->failed_pc=0x0c060de2u; return 0; }
r[13]+=r[12];
goto P_0c060de4;
P_0c060de4: /* original d417, guest PC 0x0c060de4 */
if(!s->budget--) { s->failed_pc=0x0c060de4u; return 0; }
r[4]=read(ram,0x0c060e44u,4);
goto P_0c060de6;
P_0c060de6: /* original 3ecc, guest PC 0x0c060de6 */
if(!s->budget--) { s->failed_pc=0x0c060de6u; return 0; }
r[14]+=r[12];
goto P_0c060de8;
P_0c060de8: /* original d212, guest PC 0x0c060de8 */
if(!s->budget--) { s->failed_pc=0x0c060de8u; return 0; }
r[2]=read(ram,0x0c060e34u,4);
goto P_0c060dea;
P_0c060dea: /* original 65e3, guest PC 0x0c060dea */
if(!s->budget--) { s->failed_pc=0x0c060deau; return 0; }
r[5]=r[14];
goto P_0c060dec;
P_0c060dec: /* original 420b, guest PC 0x0c060dec */
if(!s->budget--) { s->failed_pc=0x0c060decu; return 0; }
target=r[2];
r[16]=code_base|0x0c060df0u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060df0u) { target=s->pc; goto dispatch; }
goto P_0c060df0;
P_0c060dee: /* original 34dc, guest PC 0x0c060dee */
if(!s->budget--) { s->failed_pc=0x0c060deeu; return 0; }
r[4]+=r[13];
goto P_0c060df0;
P_0c060df0: /* original d315, guest PC 0x0c060df0 */
if(!s->budget--) { s->failed_pc=0x0c060df0u; return 0; }
r[3]=read(ram,0x0c060e48u,4);
goto P_0c060df2;
P_0c060df2: /* original 6032, guest PC 0x0c060df2 */
if(!s->budget--) { s->failed_pc=0x0c060df2u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060df4;
P_0c060df4: /* original 8801, guest PC 0x0c060df4 */
if(!s->budget--) { s->failed_pc=0x0c060df4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c060df6;
P_0c060df6: /* original 8b0b, guest PC 0x0c060df6 */
if(!s->budget--) { s->failed_pc=0x0c060df6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060e10; }
goto P_0c060df8;
P_0c060df8: /* original d111, guest PC 0x0c060df8 */
if(!s->budget--) { s->failed_pc=0x0c060df8u; return 0; }
r[1]=read(ram,0x0c060e40u,4);
goto P_0c060dfa;
P_0c060dfa: /* original d214, guest PC 0x0c060dfa */
if(!s->budget--) { s->failed_pc=0x0c060dfau; return 0; }
r[2]=read(ram,0x0c060e4cu,4);
goto P_0c060dfc;
P_0c060dfc: /* original 420b, guest PC 0x0c060dfc */
if(!s->budget--) { s->failed_pc=0x0c060dfcu; return 0; }
target=r[2];
r[16]=code_base|0x0c060e00u;
tmp=read(ram,r[1],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060e00u) { target=s->pc; goto dispatch; }
goto P_0c060e00;
P_0c060dfe: /* original 6412, guest PC 0x0c060dfe */
if(!s->budget--) { s->failed_pc=0x0c060dfeu; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c060e00;
P_0c060e00: /* original a006, guest PC 0x0c060e00 */
if(!s->budget--) { s->failed_pc=0x0c060e00u; return 0; }
goto P_0c060e10;
P_0c060e02: /* original 0009, guest PC 0x0c060e02 */
if(!s->budget--) { s->failed_pc=0x0c060e02u; return 0; }
goto P_0c060e04;
P_0c060e04: /* original d40f, guest PC 0x0c060e04 */
if(!s->budget--) { s->failed_pc=0x0c060e04u; return 0; }
r[4]=read(ram,0x0c060e44u,4);
goto P_0c060e06;
P_0c060e06: /* original 66a3, guest PC 0x0c060e06 */
if(!s->budget--) { s->failed_pc=0x0c060e06u; return 0; }
r[6]=r[10];
goto P_0c060e08;
P_0c060e08: /* original d20a, guest PC 0x0c060e08 */
if(!s->budget--) { s->failed_pc=0x0c060e08u; return 0; }
r[2]=read(ram,0x0c060e34u,4);
goto P_0c060e0a;
P_0c060e0a: /* original 65e3, guest PC 0x0c060e0a */
if(!s->budget--) { s->failed_pc=0x0c060e0au; return 0; }
r[5]=r[14];
goto P_0c060e0c;
P_0c060e0c: /* original 420b, guest PC 0x0c060e0c */
if(!s->budget--) { s->failed_pc=0x0c060e0cu; return 0; }
target=r[2];
r[16]=code_base|0x0c060e10u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060e10u) { target=s->pc; goto dispatch; }
goto P_0c060e10;
P_0c060e0e: /* original 34dc, guest PC 0x0c060e0e */
if(!s->budget--) { s->failed_pc=0x0c060e0eu; return 0; }
r[4]+=r[13];
goto P_0c060e10;
P_0c060e10: /* original e001, guest PC 0x0c060e10 */
if(!s->budget--) { s->failed_pc=0x0c060e10u; return 0; }
r[0]=0x00000001u;
goto P_0c060e12;
P_0c060e12: /* original 7f04, guest PC 0x0c060e12 */
if(!s->budget--) { s->failed_pc=0x0c060e12u; return 0; }
r[15]+=0x00000004u;
goto P_0c060e14;
P_0c060e14: /* original 4f26, guest PC 0x0c060e14 */
if(!s->budget--) { s->failed_pc=0x0c060e14u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c060e16;
P_0c060e16: /* original 68f6, guest PC 0x0c060e16 */
if(!s->budget--) { s->failed_pc=0x0c060e16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c060e18;
P_0c060e18: /* original 69f6, guest PC 0x0c060e18 */
if(!s->budget--) { s->failed_pc=0x0c060e18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c060e1a;
P_0c060e1a: /* original 6af6, guest PC 0x0c060e1a */
if(!s->budget--) { s->failed_pc=0x0c060e1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c060e1c;
P_0c060e1c: /* original 6bf6, guest PC 0x0c060e1c */
if(!s->budget--) { s->failed_pc=0x0c060e1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c060e1e;
P_0c060e1e: /* original 6cf6, guest PC 0x0c060e1e */
if(!s->budget--) { s->failed_pc=0x0c060e1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c060e20;
P_0c060e20: /* original 6df6, guest PC 0x0c060e20 */
if(!s->budget--) { s->failed_pc=0x0c060e20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c060e22;
P_0c060e22: /* original 000b, guest PC 0x0c060e22 */
if(!s->budget--) { s->failed_pc=0x0c060e22u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c060e24: /* original 6ef6, guest PC 0x0c060e24 */
if(!s->budget--) { s->failed_pc=0x0c060e24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c060e26u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c060e26u; return 0; } return 1;
P_0c060f28: /* original 2fe6, guest PC 0x0c060f28 */
if(!s->budget--) { s->failed_pc=0x0c060f28u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060f2a;
P_0c060f2a: /* original 2fd6, guest PC 0x0c060f2a */
if(!s->budget--) { s->failed_pc=0x0c060f2au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060f2c;
P_0c060f2c: /* original 4f22, guest PC 0x0c060f2c */
if(!s->budget--) { s->failed_pc=0x0c060f2cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c060f2e;
P_0c060f2e: /* original dd38, guest PC 0x0c060f2e */
if(!s->budget--) { s->failed_pc=0x0c060f2eu; return 0; }
r[13]=read(ram,0x0c061010u,4);
goto P_0c060f30;
P_0c060f30: /* original 54d2, guest PC 0x0c060f30 */
if(!s->budget--) { s->failed_pc=0x0c060f30u; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c060f32;
P_0c060f32: /* original 2448, guest PC 0x0c060f32 */
if(!s->budget--) { s->failed_pc=0x0c060f32u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c060f34;
P_0c060f34: /* original 8905, guest PC 0x0c060f34 */
if(!s->budget--) { s->failed_pc=0x0c060f34u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060f42; }
goto P_0c060f36;
P_0c060f36: /* original d237, guest PC 0x0c060f36 */
if(!s->budget--) { s->failed_pc=0x0c060f36u; return 0; }
r[2]=read(ram,0x0c061014u,4);
goto P_0c060f38;
P_0c060f38: /* original 420b, guest PC 0x0c060f38 */
if(!s->budget--) { s->failed_pc=0x0c060f38u; return 0; }
target=r[2];
r[16]=code_base|0x0c060f3cu;
r[14]=read(ram,r[4]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060f3cu) { target=s->pc; goto dispatch; }
goto P_0c060f3c;
P_0c060f3a: /* original 5e42, guest PC 0x0c060f3a */
if(!s->budget--) { s->failed_pc=0x0c060f3au; return 0; }
r[14]=read(ram,r[4]+8,4);
goto P_0c060f3c;
P_0c060f3c: /* original 64e3, guest PC 0x0c060f3c */
if(!s->budget--) { s->failed_pc=0x0c060f3cu; return 0; }
r[4]=r[14];
goto P_0c060f3e;
P_0c060f3e: /* original 2448, guest PC 0x0c060f3e */
if(!s->budget--) { s->failed_pc=0x0c060f3eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c060f40;
P_0c060f40: /* original 8bf9, guest PC 0x0c060f40 */
if(!s->budget--) { s->failed_pc=0x0c060f40u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060f36; }
goto P_0c060f42;
P_0c060f42: /* original 64d2, guest PC 0x0c060f42 */
if(!s->budget--) { s->failed_pc=0x0c060f42u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c060f44;
P_0c060f44: /* original 2448, guest PC 0x0c060f44 */
if(!s->budget--) { s->failed_pc=0x0c060f44u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c060f46;
P_0c060f46: /* original 8905, guest PC 0x0c060f46 */
if(!s->budget--) { s->failed_pc=0x0c060f46u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060f54; }
goto P_0c060f48;
P_0c060f48: /* original d332, guest PC 0x0c060f48 */
if(!s->budget--) { s->failed_pc=0x0c060f48u; return 0; }
r[3]=read(ram,0x0c061014u,4);
goto P_0c060f4a;
P_0c060f4a: /* original 430b, guest PC 0x0c060f4a */
if(!s->budget--) { s->failed_pc=0x0c060f4au; return 0; }
target=r[3];
r[16]=code_base|0x0c060f4eu;
r[14]=read(ram,r[4]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060f4eu) { target=s->pc; goto dispatch; }
goto P_0c060f4e;
P_0c060f4c: /* original 5e42, guest PC 0x0c060f4c */
if(!s->budget--) { s->failed_pc=0x0c060f4cu; return 0; }
r[14]=read(ram,r[4]+8,4);
goto P_0c060f4e;
P_0c060f4e: /* original 64e3, guest PC 0x0c060f4e */
if(!s->budget--) { s->failed_pc=0x0c060f4eu; return 0; }
r[4]=r[14];
goto P_0c060f50;
P_0c060f50: /* original 2448, guest PC 0x0c060f50 */
if(!s->budget--) { s->failed_pc=0x0c060f50u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c060f52;
P_0c060f52: /* original 8bf9, guest PC 0x0c060f52 */
if(!s->budget--) { s->failed_pc=0x0c060f52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060f48; }
goto P_0c060f54;
P_0c060f54: /* original 54d7, guest PC 0x0c060f54 */
if(!s->budget--) { s->failed_pc=0x0c060f54u; return 0; }
r[4]=read(ram,r[13]+28,4);
goto P_0c060f56;
P_0c060f56: /* original 2448, guest PC 0x0c060f56 */
if(!s->budget--) { s->failed_pc=0x0c060f56u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c060f58;
P_0c060f58: /* original 8905, guest PC 0x0c060f58 */
if(!s->budget--) { s->failed_pc=0x0c060f58u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060f66; }
goto P_0c060f5a;
P_0c060f5a: /* original d22e, guest PC 0x0c060f5a */
if(!s->budget--) { s->failed_pc=0x0c060f5au; return 0; }
r[2]=read(ram,0x0c061014u,4);
goto P_0c060f5c;
P_0c060f5c: /* original 420b, guest PC 0x0c060f5c */
if(!s->budget--) { s->failed_pc=0x0c060f5cu; return 0; }
target=r[2];
r[16]=code_base|0x0c060f60u;
r[14]=read(ram,r[4]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060f60u) { target=s->pc; goto dispatch; }
goto P_0c060f60;
P_0c060f5e: /* original 5e42, guest PC 0x0c060f5e */
if(!s->budget--) { s->failed_pc=0x0c060f5eu; return 0; }
r[14]=read(ram,r[4]+8,4);
goto P_0c060f60;
P_0c060f60: /* original 64e3, guest PC 0x0c060f60 */
if(!s->budget--) { s->failed_pc=0x0c060f60u; return 0; }
r[4]=r[14];
goto P_0c060f62;
P_0c060f62: /* original 2448, guest PC 0x0c060f62 */
if(!s->budget--) { s->failed_pc=0x0c060f62u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c060f64;
P_0c060f64: /* original 8bf9, guest PC 0x0c060f64 */
if(!s->budget--) { s->failed_pc=0x0c060f64u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060f5a; }
goto P_0c060f66;
P_0c060f66: /* original 54d5, guest PC 0x0c060f66 */
if(!s->budget--) { s->failed_pc=0x0c060f66u; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c060f68;
P_0c060f68: /* original 2448, guest PC 0x0c060f68 */
if(!s->budget--) { s->failed_pc=0x0c060f68u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c060f6a;
P_0c060f6a: /* original 8905, guest PC 0x0c060f6a */
if(!s->budget--) { s->failed_pc=0x0c060f6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060f78; }
goto P_0c060f6c;
P_0c060f6c: /* original d329, guest PC 0x0c060f6c */
if(!s->budget--) { s->failed_pc=0x0c060f6cu; return 0; }
r[3]=read(ram,0x0c061014u,4);
goto P_0c060f6e;
P_0c060f6e: /* original 430b, guest PC 0x0c060f6e */
if(!s->budget--) { s->failed_pc=0x0c060f6eu; return 0; }
target=r[3];
r[16]=code_base|0x0c060f72u;
r[14]=read(ram,r[4]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060f72u) { target=s->pc; goto dispatch; }
goto P_0c060f72;
P_0c060f70: /* original 5e42, guest PC 0x0c060f70 */
if(!s->budget--) { s->failed_pc=0x0c060f70u; return 0; }
r[14]=read(ram,r[4]+8,4);
goto P_0c060f72;
P_0c060f72: /* original 64e3, guest PC 0x0c060f72 */
if(!s->budget--) { s->failed_pc=0x0c060f72u; return 0; }
r[4]=r[14];
goto P_0c060f74;
P_0c060f74: /* original 2448, guest PC 0x0c060f74 */
if(!s->budget--) { s->failed_pc=0x0c060f74u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c060f76;
P_0c060f76: /* original 8bf9, guest PC 0x0c060f76 */
if(!s->budget--) { s->failed_pc=0x0c060f76u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060f6c; }
goto P_0c060f78;
P_0c060f78: /* original 9649, guest PC 0x0c060f78 */
if(!s->budget--) { s->failed_pc=0x0c060f78u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06100eu,2);
goto P_0c060f7a;
P_0c060f7a: /* original e500, guest PC 0x0c060f7a */
if(!s->budget--) { s->failed_pc=0x0c060f7au; return 0; }
r[5]=0x00000000u;
goto P_0c060f7c;
P_0c060f7c: /* original d426, guest PC 0x0c060f7c */
if(!s->budget--) { s->failed_pc=0x0c060f7cu; return 0; }
r[4]=read(ram,0x0c061018u,4);
goto P_0c060f7e;
P_0c060f7e: /* original 6e53, guest PC 0x0c060f7e */
if(!s->budget--) { s->failed_pc=0x0c060f7eu; return 0; }
r[14]=r[5];
goto P_0c060f80;
P_0c060f80: /* original 24e1, guest PC 0x0c060f80 */
if(!s->budget--) { s->failed_pc=0x0c060f80u; return 0; }
write(ram,r[4],r[14],2);
goto P_0c060f82;
P_0c060f82: /* original 7501, guest PC 0x0c060f82 */
if(!s->budget--) { s->failed_pc=0x0c060f82u; return 0; }
r[5]+=0x00000001u;
goto P_0c060f84;
P_0c060f84: /* original 3563, guest PC 0x0c060f84 */
if(!s->budget--) { s->failed_pc=0x0c060f84u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c060f86;
P_0c060f86: /* original 8ffb, guest PC 0x0c060f86 */
if(!s->budget--) { s->failed_pc=0x0c060f86u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000018u;
if(!cond) { goto P_0c060f80; }
goto P_0c060f8a;
P_0c060f88: /* original 7418, guest PC 0x0c060f88 */
if(!s->budget--) { s->failed_pc=0x0c060f88u; return 0; }
r[4]+=0x00000018u;
goto P_0c060f8a;
P_0c060f8a: /* original 64d3, guest PC 0x0c060f8a */
if(!s->budget--) { s->failed_pc=0x0c060f8au; return 0; }
r[4]=r[13];
goto P_0c060f8c;
P_0c060f8c: /* original 24e2, guest PC 0x0c060f8c */
if(!s->budget--) { s->failed_pc=0x0c060f8cu; return 0; }
write(ram,r[4],r[14],4);
goto P_0c060f8e;
P_0c060f8e: /* original e200, guest PC 0x0c060f8e */
if(!s->budget--) { s->failed_pc=0x0c060f8eu; return 0; }
r[2]=0x00000000u;
goto P_0c060f90;
P_0c060f90: /* original 14e1, guest PC 0x0c060f90 */
if(!s->budget--) { s->failed_pc=0x0c060f90u; return 0; }
write(ram,r[4]+4,r[14],4);
goto P_0c060f92;
P_0c060f92: /* original 6323, guest PC 0x0c060f92 */
if(!s->budget--) { s->failed_pc=0x0c060f92u; return 0; }
r[3]=r[2];
goto P_0c060f94;
P_0c060f94: /* original 14e2, guest PC 0x0c060f94 */
if(!s->budget--) { s->failed_pc=0x0c060f94u; return 0; }
write(ram,r[4]+8,r[14],4);
goto P_0c060f96;
P_0c060f96: /* original 14e3, guest PC 0x0c060f96 */
if(!s->budget--) { s->failed_pc=0x0c060f96u; return 0; }
write(ram,r[4]+12,r[14],4);
goto P_0c060f98;
P_0c060f98: /* original 1424, guest PC 0x0c060f98 */
if(!s->budget--) { s->failed_pc=0x0c060f98u; return 0; }
write(ram,r[4]+16,r[2],4);
goto P_0c060f9a;
P_0c060f9a: /* original 7414, guest PC 0x0c060f9a */
if(!s->budget--) { s->failed_pc=0x0c060f9au; return 0; }
r[4]+=0x00000014u;
goto P_0c060f9c;
P_0c060f9c: /* original 24e2, guest PC 0x0c060f9c */
if(!s->budget--) { s->failed_pc=0x0c060f9cu; return 0; }
write(ram,r[4],r[14],4);
goto P_0c060f9e;
P_0c060f9e: /* original 14e1, guest PC 0x0c060f9e */
if(!s->budget--) { s->failed_pc=0x0c060f9eu; return 0; }
write(ram,r[4]+4,r[14],4);
goto P_0c060fa0;
P_0c060fa0: /* original 14e2, guest PC 0x0c060fa0 */
if(!s->budget--) { s->failed_pc=0x0c060fa0u; return 0; }
write(ram,r[4]+8,r[14],4);
goto P_0c060fa2;
P_0c060fa2: /* original 14e3, guest PC 0x0c060fa2 */
if(!s->budget--) { s->failed_pc=0x0c060fa2u; return 0; }
write(ram,r[4]+12,r[14],4);
goto P_0c060fa4;
P_0c060fa4: /* original 1424, guest PC 0x0c060fa4 */
if(!s->budget--) { s->failed_pc=0x0c060fa4u; return 0; }
write(ram,r[4]+16,r[2],4);
goto P_0c060fa6;
P_0c060fa6: /* original d21d, guest PC 0x0c060fa6 */
if(!s->budget--) { s->failed_pc=0x0c060fa6u; return 0; }
r[2]=read(ram,0x0c06101cu,4);
goto P_0c060fa8;
P_0c060fa8: /* original 6422, guest PC 0x0c060fa8 */
if(!s->budget--) { s->failed_pc=0x0c060fa8u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c060faa;
P_0c060faa: /* original 2448, guest PC 0x0c060faa */
if(!s->budget--) { s->failed_pc=0x0c060faau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c060fac;
P_0c060fac: /* original 8905, guest PC 0x0c060fac */
if(!s->budget--) { s->failed_pc=0x0c060facu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060fba; }
goto P_0c060fae;
P_0c060fae: /* original d21c, guest PC 0x0c060fae */
if(!s->budget--) { s->failed_pc=0x0c060faeu; return 0; }
r[2]=read(ram,0x0c061020u,4);
goto P_0c060fb0;
P_0c060fb0: /* original 420b, guest PC 0x0c060fb0 */
if(!s->budget--) { s->failed_pc=0x0c060fb0u; return 0; }
target=r[2];
r[16]=code_base|0x0c060fb4u;
r[13]=read(ram,r[4]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060fb4u) { target=s->pc; goto dispatch; }
goto P_0c060fb4;
P_0c060fb2: /* original 5d41, guest PC 0x0c060fb2 */
if(!s->budget--) { s->failed_pc=0x0c060fb2u; return 0; }
r[13]=read(ram,r[4]+4,4);
goto P_0c060fb4;
P_0c060fb4: /* original 64d3, guest PC 0x0c060fb4 */
if(!s->budget--) { s->failed_pc=0x0c060fb4u; return 0; }
r[4]=r[13];
goto P_0c060fb6;
P_0c060fb6: /* original 2448, guest PC 0x0c060fb6 */
if(!s->budget--) { s->failed_pc=0x0c060fb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c060fb8;
P_0c060fb8: /* original 8bf9, guest PC 0x0c060fb8 */
if(!s->budget--) { s->failed_pc=0x0c060fb8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060fae; }
goto P_0c060fba;
P_0c060fba: /* original e000, guest PC 0x0c060fba */
if(!s->budget--) { s->failed_pc=0x0c060fbau; return 0; }
r[0]=0x00000000u;
goto P_0c060fbc;
P_0c060fbc: /* original d217, guest PC 0x0c060fbc */
if(!s->budget--) { s->failed_pc=0x0c060fbcu; return 0; }
r[2]=read(ram,0x0c06101cu,4);
goto P_0c060fbe;
P_0c060fbe: /* original 22e2, guest PC 0x0c060fbe */
if(!s->budget--) { s->failed_pc=0x0c060fbeu; return 0; }
write(ram,r[2],r[14],4);
goto P_0c060fc0;
P_0c060fc0: /* original 4f26, guest PC 0x0c060fc0 */
if(!s->budget--) { s->failed_pc=0x0c060fc0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c060fc2;
P_0c060fc2: /* original 6df6, guest PC 0x0c060fc2 */
if(!s->budget--) { s->failed_pc=0x0c060fc2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c060fc4;
P_0c060fc4: /* original 000b, guest PC 0x0c060fc4 */
if(!s->budget--) { s->failed_pc=0x0c060fc4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c060fc6: /* original 6ef6, guest PC 0x0c060fc6 */
if(!s->budget--) { s->failed_pc=0x0c060fc6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c060fc8;
P_0c060fc8: /* original 2fe6, guest PC 0x0c060fc8 */
if(!s->budget--) { s->failed_pc=0x0c060fc8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060fca;
P_0c060fca: /* original 2fd6, guest PC 0x0c060fca */
if(!s->budget--) { s->failed_pc=0x0c060fcau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060fcc;
P_0c060fcc: /* original 2fc6, guest PC 0x0c060fcc */
if(!s->budget--) { s->failed_pc=0x0c060fccu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060fce;
P_0c060fce: /* original 2fb6, guest PC 0x0c060fce */
if(!s->budget--) { s->failed_pc=0x0c060fceu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060fd0;
P_0c060fd0: /* original 2fa6, guest PC 0x0c060fd0 */
if(!s->budget--) { s->failed_pc=0x0c060fd0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060fd2;
P_0c060fd2: /* original 2f96, guest PC 0x0c060fd2 */
if(!s->budget--) { s->failed_pc=0x0c060fd2u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060fd4;
P_0c060fd4: /* original 2f86, guest PC 0x0c060fd4 */
if(!s->budget--) { s->failed_pc=0x0c060fd4u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060fd6;
P_0c060fd6: /* original 4f22, guest PC 0x0c060fd6 */
if(!s->budget--) { s->failed_pc=0x0c060fd6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c060fd8;
P_0c060fd8: /* original da12, guest PC 0x0c060fd8 */
if(!s->budget--) { s->failed_pc=0x0c060fd8u; return 0; }
r[10]=read(ram,0x0c061024u,4);
goto P_0c060fda;
P_0c060fda: /* original db13, guest PC 0x0c060fda */
if(!s->budget--) { s->failed_pc=0x0c060fdau; return 0; }
r[11]=read(ram,0x0c061028u,4);
goto P_0c060fdc;
P_0c060fdc: /* original dc0c, guest PC 0x0c060fdc */
if(!s->budget--) { s->failed_pc=0x0c060fdcu; return 0; }
r[12]=read(ram,0x0c061010u,4);
goto P_0c060fde;
P_0c060fde: /* original dd13, guest PC 0x0c060fde */
if(!s->budget--) { s->failed_pc=0x0c060fdeu; return 0; }
r[13]=read(ram,0x0c06102cu,4);
goto P_0c060fe0;
P_0c060fe0: /* original d813, guest PC 0x0c060fe0 */
if(!s->budget--) { s->failed_pc=0x0c060fe0u; return 0; }
r[8]=read(ram,0x0c061030u,4);
goto P_0c060fe2;
P_0c060fe2: /* original de14, guest PC 0x0c060fe2 */
if(!s->budget--) { s->failed_pc=0x0c060fe2u; return 0; }
r[14]=read(ram,0x0c061034u,4);
goto P_0c060fe4;
P_0c060fe4: /* original d314, guest PC 0x0c060fe4 */
if(!s->budget--) { s->failed_pc=0x0c060fe4u; return 0; }
r[3]=read(ram,0x0c061038u,4);
goto P_0c060fe6;
P_0c060fe6: /* original 6032, guest PC 0x0c060fe6 */
if(!s->budget--) { s->failed_pc=0x0c060fe6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060fe8;
P_0c060fe8: /* original 8801, guest PC 0x0c060fe8 */
if(!s->budget--) { s->failed_pc=0x0c060fe8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c060fea;
P_0c060fea: /* original 8f56, guest PC 0x0c060fea */
if(!s->budget--) { s->failed_pc=0x0c060feau; return 0; }
cond=r[17]&1u;
r[9]=0x00000000u;
if(!cond) { goto P_0c06109a; }
goto P_0c060fee;
P_0c060fec: /* original e900, guest PC 0x0c060fec */
if(!s->budget--) { s->failed_pc=0x0c060fecu; return 0; }
r[9]=0x00000000u;
goto P_0c060fee;
P_0c060fee: /* original d513, guest PC 0x0c060fee */
if(!s->budget--) { s->failed_pc=0x0c060feeu; return 0; }
r[5]=read(ram,0x0c06103cu,4);
goto P_0c060ff0;
P_0c060ff0: /* original d413, guest PC 0x0c060ff0 */
if(!s->budget--) { s->failed_pc=0x0c060ff0u; return 0; }
r[4]=read(ram,0x0c061040u,4);
goto P_0c060ff2;
P_0c060ff2: /* original d114, guest PC 0x0c060ff2 */
if(!s->budget--) { s->failed_pc=0x0c060ff2u; return 0; }
r[1]=read(ram,0x0c061044u,4);
goto P_0c060ff4;
P_0c060ff4: /* original 410b, guest PC 0x0c060ff4 */
if(!s->budget--) { s->failed_pc=0x0c060ff4u; return 0; }
target=r[1];
r[16]=code_base|0x0c060ff8u;
r[6]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060ff8u) { target=s->pc; goto dispatch; }
goto P_0c060ff8;
P_0c060ff6: /* original e600, guest PC 0x0c060ff6 */
if(!s->budget--) { s->failed_pc=0x0c060ff6u; return 0; }
r[6]=0x00000000u;
goto P_0c060ff8;
P_0c060ff8: /* original 8801, guest PC 0x0c060ff8 */
if(!s->budget--) { s->failed_pc=0x0c060ff8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c060ffa;
P_0c060ffa: /* original 8b2b, guest PC 0x0c060ffa */
if(!s->budget--) { s->failed_pc=0x0c060ffau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061054; }
goto P_0c060ffc;
P_0c060ffc: /* original d212, guest PC 0x0c060ffc */
if(!s->budget--) { s->failed_pc=0x0c060ffcu; return 0; }
r[2]=read(ram,0x0c061048u,4);
goto P_0c060ffe;
P_0c060ffe: /* original 2282, guest PC 0x0c060ffe */
if(!s->budget--) { s->failed_pc=0x0c060ffeu; return 0; }
write(ram,r[2],r[8],4);
goto P_0c061000;
P_0c061000: /* original d312, guest PC 0x0c061000 */
if(!s->budget--) { s->failed_pc=0x0c061000u; return 0; }
r[3]=read(ram,0x0c06104cu,4);
goto P_0c061002;
P_0c061002: /* original 2382, guest PC 0x0c061002 */
if(!s->budget--) { s->failed_pc=0x0c061002u; return 0; }
write(ram,r[3],r[8],4);
goto P_0c061004;
P_0c061004: /* original 2a92, guest PC 0x0c061004 */
if(!s->budget--) { s->failed_pc=0x0c061004u; return 0; }
write(ram,r[10],r[9],4);
goto P_0c061006;
P_0c061006: /* original 2d82, guest PC 0x0c061006 */
if(!s->budget--) { s->failed_pc=0x0c061006u; return 0; }
write(ram,r[13],r[8],4);
goto P_0c061008;
P_0c061008: /* original d111, guest PC 0x0c061008 */
if(!s->budget--) { s->failed_pc=0x0c061008u; return 0; }
r[1]=read(ram,0x0c061050u,4);
goto P_0c06100a;
P_0c06100a: /* original a02b, guest PC 0x0c06100a */
if(!s->budget--) { s->failed_pc=0x0c06100au; return 0; }
write(ram,r[1],r[8],4);
goto P_0c061064;
P_0c06100c: /* original 2182, guest PC 0x0c06100c */
if(!s->budget--) { s->failed_pc=0x0c06100cu; return 0; }
write(ram,r[1],r[8],4);
if(!vf3_matrix_family(0x0c06100eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06100eu; return 0; } return 1;
P_0c061054: /* original d23b, guest PC 0x0c061054 */
if(!s->budget--) { s->failed_pc=0x0c061054u; return 0; }
r[2]=read(ram,0x0c061144u,4);
goto P_0c061056;
P_0c061056: /* original 22e2, guest PC 0x0c061056 */
if(!s->budget--) { s->failed_pc=0x0c061056u; return 0; }
write(ram,r[2],r[14],4);
goto P_0c061058;
P_0c061058: /* original d33b, guest PC 0x0c061058 */
if(!s->budget--) { s->failed_pc=0x0c061058u; return 0; }
r[3]=read(ram,0x0c061148u,4);
goto P_0c06105a;
P_0c06105a: /* original 23e2, guest PC 0x0c06105a */
if(!s->budget--) { s->failed_pc=0x0c06105au; return 0; }
write(ram,r[3],r[14],4);
goto P_0c06105c;
P_0c06105c: /* original 2a92, guest PC 0x0c06105c */
if(!s->budget--) { s->failed_pc=0x0c06105cu; return 0; }
write(ram,r[10],r[9],4);
goto P_0c06105e;
P_0c06105e: /* original 2de2, guest PC 0x0c06105e */
if(!s->budget--) { s->failed_pc=0x0c06105eu; return 0; }
write(ram,r[13],r[14],4);
goto P_0c061060;
P_0c061060: /* original d13a, guest PC 0x0c061060 */
if(!s->budget--) { s->failed_pc=0x0c061060u; return 0; }
r[1]=read(ram,0x0c06114cu,4);
goto P_0c061062;
P_0c061062: /* original 21e2, guest PC 0x0c061062 */
if(!s->budget--) { s->failed_pc=0x0c061062u; return 0; }
write(ram,r[1],r[14],4);
goto P_0c061064;
P_0c061064: /* original 2b92, guest PC 0x0c061064 */
if(!s->budget--) { s->failed_pc=0x0c061064u; return 0; }
write(ram,r[11],r[9],4);
goto P_0c061066;
P_0c061066: /* original 946c, guest PC 0x0c061066 */
if(!s->budget--) { s->failed_pc=0x0c061066u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c061142u,2);
goto P_0c061068;
P_0c061068: /* original d339, guest PC 0x0c061068 */
if(!s->budget--) { s->failed_pc=0x0c061068u; return 0; }
r[3]=read(ram,0x0c061150u,4);
goto P_0c06106a;
P_0c06106a: /* original 430b, guest PC 0x0c06106a */
if(!s->budget--) { s->failed_pc=0x0c06106au; return 0; }
target=r[3];
r[16]=code_base|0x0c06106eu;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06106eu) { target=s->pc; goto dispatch; }
goto P_0c06106e;
P_0c06106c: /* original e500, guest PC 0x0c06106c */
if(!s->budget--) { s->failed_pc=0x0c06106cu; return 0; }
r[5]=0x00000000u;
goto P_0c06106e;
P_0c06106e: /* original bf5b, guest PC 0x0c06106e */
if(!s->budget--) { s->failed_pc=0x0c06106eu; return 0; }
target=code_base|0x0c060f28u; r[16]=code_base|0x0c061072u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c061072u) { target=s->pc; goto dispatch; }
goto P_0c061072;
P_0c061070: /* original 0009, guest PC 0x0c061070 */
if(!s->budget--) { s->failed_pc=0x0c061070u; return 0; }
goto P_0c061072;
P_0c061072: /* original 63d2, guest PC 0x0c061072 */
if(!s->budget--) { s->failed_pc=0x0c061072u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c061074;
P_0c061074: /* original 1c34, guest PC 0x0c061074 */
if(!s->budget--) { s->failed_pc=0x0c061074u; return 0; }
write(ram,r[12]+16,r[3],4);
goto P_0c061076;
P_0c061076: /* original 62b2, guest PC 0x0c061076 */
if(!s->budget--) { s->failed_pc=0x0c061076u; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c061078;
P_0c061078: /* original d336, guest PC 0x0c061078 */
if(!s->budget--) { s->failed_pc=0x0c061078u; return 0; }
r[3]=read(ram,0x0c061154u,4);
goto P_0c06107a;
P_0c06107a: /* original 430b, guest PC 0x0c06107a */
if(!s->budget--) { s->failed_pc=0x0c06107au; return 0; }
target=r[3];
r[16]=code_base|0x0c06107eu;
write(ram,r[12]+36,r[2],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06107eu) { target=s->pc; goto dispatch; }
goto P_0c06107e;
P_0c06107c: /* original 1c29, guest PC 0x0c06107c */
if(!s->budget--) { s->failed_pc=0x0c06107cu; return 0; }
write(ram,r[12]+36,r[2],4);
goto P_0c06107e;
P_0c06107e: /* original 6403, guest PC 0x0c06107e */
if(!s->budget--) { s->failed_pc=0x0c06107eu; return 0; }
r[4]=r[0];
goto P_0c061080;
P_0c061080: /* original 2448, guest PC 0x0c061080 */
if(!s->budget--) { s->failed_pc=0x0c061080u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c061082;
P_0c061082: /* original 8945, guest PC 0x0c061082 */
if(!s->budget--) { s->failed_pc=0x0c061082u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061110; }
goto P_0c061084;
P_0c061084: /* original 63a2, guest PC 0x0c061084 */
if(!s->budget--) { s->failed_pc=0x0c061084u; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c061086;
P_0c061086: /* original 65c3, guest PC 0x0c061086 */
if(!s->budget--) { s->failed_pc=0x0c061086u; return 0; }
r[5]=r[12];
goto P_0c061088;
P_0c061088: /* original 1433, guest PC 0x0c061088 */
if(!s->budget--) { s->failed_pc=0x0c061088u; return 0; }
write(ram,r[4]+12,r[3],4);
goto P_0c06108a;
P_0c06108a: /* original 62d2, guest PC 0x0c06108a */
if(!s->budget--) { s->failed_pc=0x0c06108au; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c06108c;
P_0c06108c: /* original 1424, guest PC 0x0c06108c */
if(!s->budget--) { s->failed_pc=0x0c06108cu; return 0; }
write(ram,r[4]+16,r[2],4);
goto P_0c06108e;
P_0c06108e: /* original 5352, guest PC 0x0c06108e */
if(!s->budget--) { s->failed_pc=0x0c06108eu; return 0; }
r[3]=read(ram,r[5]+8,4);
goto P_0c061090;
P_0c061090: /* original 1432, guest PC 0x0c061090 */
if(!s->budget--) { s->failed_pc=0x0c061090u; return 0; }
write(ram,r[4]+8,r[3],4);
goto P_0c061092;
P_0c061092: /* original 1542, guest PC 0x0c061092 */
if(!s->budget--) { s->failed_pc=0x0c061092u; return 0; }
write(ram,r[5]+8,r[4],4);
goto P_0c061094;
P_0c061094: /* original 5253, guest PC 0x0c061094 */
if(!s->budget--) { s->failed_pc=0x0c061094u; return 0; }
r[2]=read(ram,r[5]+12,4);
goto P_0c061096;
P_0c061096: /* original a049, guest PC 0x0c061096 */
if(!s->budget--) { s->failed_pc=0x0c061096u; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c06112c;
P_0c061098: /* original 1421, guest PC 0x0c061098 */
if(!s->budget--) { s->failed_pc=0x0c061098u; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c06109a;
P_0c06109a: /* original d52f, guest PC 0x0c06109a */
if(!s->budget--) { s->failed_pc=0x0c06109au; return 0; }
r[5]=read(ram,0x0c061158u,4);
goto P_0c06109c;
P_0c06109c: /* original d42f, guest PC 0x0c06109c */
if(!s->budget--) { s->failed_pc=0x0c06109cu; return 0; }
r[4]=read(ram,0x0c06115cu,4);
goto P_0c06109e;
P_0c06109e: /* original d230, guest PC 0x0c06109e */
if(!s->budget--) { s->failed_pc=0x0c06109eu; return 0; }
r[2]=read(ram,0x0c061160u,4);
goto P_0c0610a0;
P_0c0610a0: /* original 420b, guest PC 0x0c0610a0 */
if(!s->budget--) { s->failed_pc=0x0c0610a0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0610a4u;
r[6]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0610a4u) { target=s->pc; goto dispatch; }
goto P_0c0610a4;
P_0c0610a2: /* original e600, guest PC 0x0c0610a2 */
if(!s->budget--) { s->failed_pc=0x0c0610a2u; return 0; }
r[6]=0x00000000u;
goto P_0c0610a4;
P_0c0610a4: /* original 8801, guest PC 0x0c0610a4 */
if(!s->budget--) { s->failed_pc=0x0c0610a4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0610a6;
P_0c0610a6: /* original 8f0a, guest PC 0x0c0610a6 */
if(!s->budget--) { s->failed_pc=0x0c0610a6u; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(!cond) { goto P_0c0610be; }
goto P_0c0610aa;
P_0c0610a8: /* original e500, guest PC 0x0c0610a8 */
if(!s->budget--) { s->failed_pc=0x0c0610a8u; return 0; }
r[5]=0x00000000u;
goto P_0c0610aa;
P_0c0610aa: /* original d226, guest PC 0x0c0610aa */
if(!s->budget--) { s->failed_pc=0x0c0610aau; return 0; }
r[2]=read(ram,0x0c061144u,4);
goto P_0c0610ac;
P_0c0610ac: /* original 2282, guest PC 0x0c0610ac */
if(!s->budget--) { s->failed_pc=0x0c0610acu; return 0; }
write(ram,r[2],r[8],4);
goto P_0c0610ae;
P_0c0610ae: /* original d326, guest PC 0x0c0610ae */
if(!s->budget--) { s->failed_pc=0x0c0610aeu; return 0; }
r[3]=read(ram,0x0c061148u,4);
goto P_0c0610b0;
P_0c0610b0: /* original d126, guest PC 0x0c0610b0 */
if(!s->budget--) { s->failed_pc=0x0c0610b0u; return 0; }
r[1]=read(ram,0x0c06114cu,4);
goto P_0c0610b2;
P_0c0610b2: /* original 23e2, guest PC 0x0c0610b2 */
if(!s->budget--) { s->failed_pc=0x0c0610b2u; return 0; }
write(ram,r[3],r[14],4);
goto P_0c0610b4;
P_0c0610b4: /* original 2a92, guest PC 0x0c0610b4 */
if(!s->budget--) { s->failed_pc=0x0c0610b4u; return 0; }
write(ram,r[10],r[9],4);
goto P_0c0610b6;
P_0c0610b6: /* original 2de2, guest PC 0x0c0610b6 */
if(!s->budget--) { s->failed_pc=0x0c0610b6u; return 0; }
write(ram,r[13],r[14],4);
goto P_0c0610b8;
P_0c0610b8: /* original 21e2, guest PC 0x0c0610b8 */
if(!s->budget--) { s->failed_pc=0x0c0610b8u; return 0; }
write(ram,r[1],r[14],4);
goto P_0c0610ba;
P_0c0610ba: /* original a00a, guest PC 0x0c0610ba */
if(!s->budget--) { s->failed_pc=0x0c0610bau; return 0; }
write(ram,r[11],r[14],4);
goto P_0c0610d2;
P_0c0610bc: /* original 2be2, guest PC 0x0c0610bc */
if(!s->budget--) { s->failed_pc=0x0c0610bcu; return 0; }
write(ram,r[11],r[14],4);
goto P_0c0610be;
P_0c0610be: /* original d221, guest PC 0x0c0610be */
if(!s->budget--) { s->failed_pc=0x0c0610beu; return 0; }
r[2]=read(ram,0x0c061144u,4);
goto P_0c0610c0;
P_0c0610c0: /* original 22e2, guest PC 0x0c0610c0 */
if(!s->budget--) { s->failed_pc=0x0c0610c0u; return 0; }
write(ram,r[2],r[14],4);
goto P_0c0610c2;
P_0c0610c2: /* original d428, guest PC 0x0c0610c2 */
if(!s->budget--) { s->failed_pc=0x0c0610c2u; return 0; }
r[4]=read(ram,0x0c061164u,4);
goto P_0c0610c4;
P_0c0610c4: /* original d320, guest PC 0x0c0610c4 */
if(!s->budget--) { s->failed_pc=0x0c0610c4u; return 0; }
r[3]=read(ram,0x0c061148u,4);
goto P_0c0610c6;
P_0c0610c6: /* original 2342, guest PC 0x0c0610c6 */
if(!s->budget--) { s->failed_pc=0x0c0610c6u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0610c8;
P_0c0610c8: /* original 2a92, guest PC 0x0c0610c8 */
if(!s->budget--) { s->failed_pc=0x0c0610c8u; return 0; }
write(ram,r[10],r[9],4);
goto P_0c0610ca;
P_0c0610ca: /* original 2d42, guest PC 0x0c0610ca */
if(!s->budget--) { s->failed_pc=0x0c0610cau; return 0; }
write(ram,r[13],r[4],4);
goto P_0c0610cc;
P_0c0610cc: /* original d11f, guest PC 0x0c0610cc */
if(!s->budget--) { s->failed_pc=0x0c0610ccu; return 0; }
r[1]=read(ram,0x0c06114cu,4);
goto P_0c0610ce;
P_0c0610ce: /* original 2142, guest PC 0x0c0610ce */
if(!s->budget--) { s->failed_pc=0x0c0610ceu; return 0; }
write(ram,r[1],r[4],4);
goto P_0c0610d0;
P_0c0610d0: /* original 2b42, guest PC 0x0c0610d0 */
if(!s->budget--) { s->failed_pc=0x0c0610d0u; return 0; }
write(ram,r[11],r[4],4);
goto P_0c0610d2;
P_0c0610d2: /* original 9436, guest PC 0x0c0610d2 */
if(!s->budget--) { s->failed_pc=0x0c0610d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c061142u,2);
goto P_0c0610d4;
P_0c0610d4: /* original d31e, guest PC 0x0c0610d4 */
if(!s->budget--) { s->failed_pc=0x0c0610d4u; return 0; }
r[3]=read(ram,0x0c061150u,4);
goto P_0c0610d6;
P_0c0610d6: /* original 430b, guest PC 0x0c0610d6 */
if(!s->budget--) { s->failed_pc=0x0c0610d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0610dau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0610dau) { target=s->pc; goto dispatch; }
goto P_0c0610da;
P_0c0610d8: /* original 0009, guest PC 0x0c0610d8 */
if(!s->budget--) { s->failed_pc=0x0c0610d8u; return 0; }
goto P_0c0610da;
P_0c0610da: /* original bf25, guest PC 0x0c0610da */
if(!s->budget--) { s->failed_pc=0x0c0610dau; return 0; }
target=code_base|0x0c060f28u; r[16]=code_base|0x0c0610deu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0610deu) { target=s->pc; goto dispatch; }
goto P_0c0610de;
P_0c0610dc: /* original 0009, guest PC 0x0c0610dc */
if(!s->budget--) { s->failed_pc=0x0c0610dcu; return 0; }
goto P_0c0610de;
P_0c0610de: /* original 63d2, guest PC 0x0c0610de */
if(!s->budget--) { s->failed_pc=0x0c0610deu; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0610e0;
P_0c0610e0: /* original 1c34, guest PC 0x0c0610e0 */
if(!s->budget--) { s->failed_pc=0x0c0610e0u; return 0; }
write(ram,r[12]+16,r[3],4);
goto P_0c0610e2;
P_0c0610e2: /* original 62b2, guest PC 0x0c0610e2 */
if(!s->budget--) { s->failed_pc=0x0c0610e2u; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c0610e4;
P_0c0610e4: /* original d31b, guest PC 0x0c0610e4 */
if(!s->budget--) { s->failed_pc=0x0c0610e4u; return 0; }
r[3]=read(ram,0x0c061154u,4);
goto P_0c0610e6;
P_0c0610e6: /* original 430b, guest PC 0x0c0610e6 */
if(!s->budget--) { s->failed_pc=0x0c0610e6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0610eau;
write(ram,r[12]+36,r[2],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0610eau) { target=s->pc; goto dispatch; }
goto P_0c0610ea;
P_0c0610e8: /* original 1c29, guest PC 0x0c0610e8 */
if(!s->budget--) { s->failed_pc=0x0c0610e8u; return 0; }
write(ram,r[12]+36,r[2],4);
goto P_0c0610ea;
P_0c0610ea: /* original 6403, guest PC 0x0c0610ea */
if(!s->budget--) { s->failed_pc=0x0c0610eau; return 0; }
r[4]=r[0];
goto P_0c0610ec;
P_0c0610ec: /* original 2448, guest PC 0x0c0610ec */
if(!s->budget--) { s->failed_pc=0x0c0610ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0610ee;
P_0c0610ee: /* original 890f, guest PC 0x0c0610ee */
if(!s->budget--) { s->failed_pc=0x0c0610eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061110; }
goto P_0c0610f0;
P_0c0610f0: /* original 62a2, guest PC 0x0c0610f0 */
if(!s->budget--) { s->failed_pc=0x0c0610f0u; return 0; }
tmp=read(ram,r[10],4);
r[2]=tmp;
goto P_0c0610f2;
P_0c0610f2: /* original 65c3, guest PC 0x0c0610f2 */
if(!s->budget--) { s->failed_pc=0x0c0610f2u; return 0; }
r[5]=r[12];
goto P_0c0610f4;
P_0c0610f4: /* original 1423, guest PC 0x0c0610f4 */
if(!s->budget--) { s->failed_pc=0x0c0610f4u; return 0; }
write(ram,r[4]+12,r[2],4);
goto P_0c0610f6;
P_0c0610f6: /* original 63d2, guest PC 0x0c0610f6 */
if(!s->budget--) { s->failed_pc=0x0c0610f6u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0610f8;
P_0c0610f8: /* original 1434, guest PC 0x0c0610f8 */
if(!s->budget--) { s->failed_pc=0x0c0610f8u; return 0; }
write(ram,r[4]+16,r[3],4);
goto P_0c0610fa;
P_0c0610fa: /* original 5252, guest PC 0x0c0610fa */
if(!s->budget--) { s->failed_pc=0x0c0610fau; return 0; }
r[2]=read(ram,r[5]+8,4);
goto P_0c0610fc;
P_0c0610fc: /* original 1422, guest PC 0x0c0610fc */
if(!s->budget--) { s->failed_pc=0x0c0610fcu; return 0; }
write(ram,r[4]+8,r[2],4);
goto P_0c0610fe;
P_0c0610fe: /* original 1542, guest PC 0x0c0610fe */
if(!s->budget--) { s->failed_pc=0x0c0610feu; return 0; }
write(ram,r[5]+8,r[4],4);
goto P_0c061100;
P_0c061100: /* original 5353, guest PC 0x0c061100 */
if(!s->budget--) { s->failed_pc=0x0c061100u; return 0; }
r[3]=read(ram,r[5]+12,4);
goto P_0c061102;
P_0c061102: /* original 1431, guest PC 0x0c061102 */
if(!s->budget--) { s->failed_pc=0x0c061102u; return 0; }
write(ram,r[4]+4,r[3],4);
goto P_0c061104;
P_0c061104: /* original d213, guest PC 0x0c061104 */
if(!s->budget--) { s->failed_pc=0x0c061104u; return 0; }
r[2]=read(ram,0x0c061154u,4);
goto P_0c061106;
P_0c061106: /* original 420b, guest PC 0x0c061106 */
if(!s->budget--) { s->failed_pc=0x0c061106u; return 0; }
target=r[2];
r[16]=code_base|0x0c06110au;
write(ram,r[5]+12,r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06110au) { target=s->pc; goto dispatch; }
goto P_0c06110a;
P_0c061108: /* original 1543, guest PC 0x0c061108 */
if(!s->budget--) { s->failed_pc=0x0c061108u; return 0; }
write(ram,r[5]+12,r[4],4);
goto P_0c06110a;
P_0c06110a: /* original 6403, guest PC 0x0c06110a */
if(!s->budget--) { s->failed_pc=0x0c06110au; return 0; }
r[4]=r[0];
goto P_0c06110c;
P_0c06110c: /* original 2448, guest PC 0x0c06110c */
if(!s->budget--) { s->failed_pc=0x0c06110cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06110e;
P_0c06110e: /* original 8b01, guest PC 0x0c06110e */
if(!s->budget--) { s->failed_pc=0x0c06110eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061114; }
goto P_0c061110;
P_0c061110: /* original a00e, guest PC 0x0c061110 */
if(!s->budget--) { s->failed_pc=0x0c061110u; return 0; }
r[0]=0x00000003u;
goto P_0c061130;
P_0c061112: /* original e003, guest PC 0x0c061112 */
if(!s->budget--) { s->failed_pc=0x0c061112u; return 0; }
r[0]=0x00000003u;
goto P_0c061114;
P_0c061114: /* original d30d, guest PC 0x0c061114 */
if(!s->budget--) { s->failed_pc=0x0c061114u; return 0; }
r[3]=read(ram,0x0c06114cu,4);
goto P_0c061116;
P_0c061116: /* original 65c3, guest PC 0x0c061116 */
if(!s->budget--) { s->failed_pc=0x0c061116u; return 0; }
r[5]=r[12];
goto P_0c061118;
P_0c061118: /* original 6232, guest PC 0x0c061118 */
if(!s->budget--) { s->failed_pc=0x0c061118u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c06111a;
P_0c06111a: /* original 7514, guest PC 0x0c06111a */
if(!s->budget--) { s->failed_pc=0x0c06111au; return 0; }
r[5]+=0x00000014u;
goto P_0c06111c;
P_0c06111c: /* original 1423, guest PC 0x0c06111c */
if(!s->budget--) { s->failed_pc=0x0c06111cu; return 0; }
write(ram,r[4]+12,r[2],4);
goto P_0c06111e;
P_0c06111e: /* original 61b2, guest PC 0x0c06111e */
if(!s->budget--) { s->failed_pc=0x0c06111eu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c061120;
P_0c061120: /* original 1414, guest PC 0x0c061120 */
if(!s->budget--) { s->failed_pc=0x0c061120u; return 0; }
write(ram,r[4]+16,r[1],4);
goto P_0c061122;
P_0c061122: /* original 5252, guest PC 0x0c061122 */
if(!s->budget--) { s->failed_pc=0x0c061122u; return 0; }
r[2]=read(ram,r[5]+8,4);
goto P_0c061124;
P_0c061124: /* original 1422, guest PC 0x0c061124 */
if(!s->budget--) { s->failed_pc=0x0c061124u; return 0; }
write(ram,r[4]+8,r[2],4);
goto P_0c061126;
P_0c061126: /* original 1542, guest PC 0x0c061126 */
if(!s->budget--) { s->failed_pc=0x0c061126u; return 0; }
write(ram,r[5]+8,r[4],4);
goto P_0c061128;
P_0c061128: /* original 5153, guest PC 0x0c061128 */
if(!s->budget--) { s->failed_pc=0x0c061128u; return 0; }
r[1]=read(ram,r[5]+12,4);
goto P_0c06112a;
P_0c06112a: /* original 1411, guest PC 0x0c06112a */
if(!s->budget--) { s->failed_pc=0x0c06112au; return 0; }
write(ram,r[4]+4,r[1],4);
goto P_0c06112c;
P_0c06112c: /* original 1543, guest PC 0x0c06112c */
if(!s->budget--) { s->failed_pc=0x0c06112cu; return 0; }
write(ram,r[5]+12,r[4],4);
goto P_0c06112e;
P_0c06112e: /* original e000, guest PC 0x0c06112e */
if(!s->budget--) { s->failed_pc=0x0c06112eu; return 0; }
r[0]=0x00000000u;
goto P_0c061130;
P_0c061130: /* original 4f26, guest PC 0x0c061130 */
if(!s->budget--) { s->failed_pc=0x0c061130u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c061132;
P_0c061132: /* original 68f6, guest PC 0x0c061132 */
if(!s->budget--) { s->failed_pc=0x0c061132u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c061134;
P_0c061134: /* original 69f6, guest PC 0x0c061134 */
if(!s->budget--) { s->failed_pc=0x0c061134u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c061136;
P_0c061136: /* original 6af6, guest PC 0x0c061136 */
if(!s->budget--) { s->failed_pc=0x0c061136u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c061138;
P_0c061138: /* original 6bf6, guest PC 0x0c061138 */
if(!s->budget--) { s->failed_pc=0x0c061138u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06113a;
P_0c06113a: /* original 6cf6, guest PC 0x0c06113a */
if(!s->budget--) { s->failed_pc=0x0c06113au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06113c;
P_0c06113c: /* original 6df6, guest PC 0x0c06113c */
if(!s->budget--) { s->failed_pc=0x0c06113cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06113e;
P_0c06113e: /* original 000b, guest PC 0x0c06113e */
if(!s->budget--) { s->failed_pc=0x0c06113eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c061140: /* original 6ef6, guest PC 0x0c061140 */
if(!s->budget--) { s->failed_pc=0x0c061140u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c061142u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c061142u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
