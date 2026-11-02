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
int vf3_away_batch20_adapter_49(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a8d58u: goto P_0c0a8d58;
case 0x0c0a8d5au: goto P_0c0a8d5a;
case 0x0c0a8d5cu: goto P_0c0a8d5c;
case 0x0c0a8d5eu: goto P_0c0a8d5e;
case 0x0c0a8d60u: goto P_0c0a8d60;
case 0x0c0a8d62u: goto P_0c0a8d62;
case 0x0c0a8d64u: goto P_0c0a8d64;
case 0x0c0a8d66u: goto P_0c0a8d66;
case 0x0c0a8d68u: goto P_0c0a8d68;
case 0x0c0a8d6au: goto P_0c0a8d6a;
case 0x0c0a8d6cu: goto P_0c0a8d6c;
case 0x0c0a8d6eu: goto P_0c0a8d6e;
case 0x0c0a8d70u: goto P_0c0a8d70;
case 0x0c0a8d72u: goto P_0c0a8d72;
case 0x0c0a8d74u: goto P_0c0a8d74;
case 0x0c0a8d76u: goto P_0c0a8d76;
case 0x0c0a8d78u: goto P_0c0a8d78;
case 0x0c0a8d7au: goto P_0c0a8d7a;
case 0x0c0a8d7cu: goto P_0c0a8d7c;
case 0x0c0a8d7eu: goto P_0c0a8d7e;
case 0x0c0a8d80u: goto P_0c0a8d80;
case 0x0c0a8d82u: goto P_0c0a8d82;
case 0x0c0a8d84u: goto P_0c0a8d84;
case 0x0c0a8d86u: goto P_0c0a8d86;
case 0x0c0a8d88u: goto P_0c0a8d88;
case 0x0c0a8d8au: goto P_0c0a8d8a;
case 0x0c0a8d8cu: goto P_0c0a8d8c;
case 0x0c0a8d8eu: goto P_0c0a8d8e;
case 0x0c0a8d90u: goto P_0c0a8d90;
case 0x0c0a8d92u: goto P_0c0a8d92;
case 0x0c0a8d94u: goto P_0c0a8d94;
case 0x0c0a8d96u: goto P_0c0a8d96;
case 0x0c0a8d98u: goto P_0c0a8d98;
case 0x0c0a8d9au: goto P_0c0a8d9a;
case 0x0c0a8d9cu: goto P_0c0a8d9c;
case 0x0c0a8d9eu: goto P_0c0a8d9e;
case 0x0c0a8da0u: goto P_0c0a8da0;
case 0x0c0a8da2u: goto P_0c0a8da2;
case 0x0c0a8da4u: goto P_0c0a8da4;
case 0x0c0a8da6u: goto P_0c0a8da6;
case 0x0c0a8da8u: goto P_0c0a8da8;
case 0x0c0a8daau: goto P_0c0a8daa;
case 0x0c0a8dacu: goto P_0c0a8dac;
case 0x0c0a8daeu: goto P_0c0a8dae;
case 0x0c0a8db0u: goto P_0c0a8db0;
case 0x0c0a8db2u: goto P_0c0a8db2;
case 0x0c0a8db4u: goto P_0c0a8db4;
case 0x0c0a8db6u: goto P_0c0a8db6;
case 0x0c0a8db8u: goto P_0c0a8db8;
case 0x0c0a8dbau: goto P_0c0a8dba;
case 0x0c0a8dbcu: goto P_0c0a8dbc;
case 0x0c0a8dbeu: goto P_0c0a8dbe;
case 0x0c0a8dc0u: goto P_0c0a8dc0;
case 0x0c0a8dc2u: goto P_0c0a8dc2;
case 0x0c0a8dc4u: goto P_0c0a8dc4;
case 0x0c0a8dc6u: goto P_0c0a8dc6;
case 0x0c0a8dc8u: goto P_0c0a8dc8;
case 0x0c0a8dcau: goto P_0c0a8dca;
case 0x0c0a8dccu: goto P_0c0a8dcc;
case 0x0c0a8dceu: goto P_0c0a8dce;
case 0x0c0a8dd0u: goto P_0c0a8dd0;
case 0x0c0a8dd2u: goto P_0c0a8dd2;
case 0x0c0a8dd4u: goto P_0c0a8dd4;
case 0x0c0a8dd6u: goto P_0c0a8dd6;
case 0x0c0a8dd8u: goto P_0c0a8dd8;
case 0x0c0a8ddau: goto P_0c0a8dda;
case 0x0c0a8ddcu: goto P_0c0a8ddc;
case 0x0c0a8ddeu: goto P_0c0a8dde;
case 0x0c0a8de0u: goto P_0c0a8de0;
case 0x0c0a8de2u: goto P_0c0a8de2;
case 0x0c0a8de4u: goto P_0c0a8de4;
case 0x0c0a8de6u: goto P_0c0a8de6;
case 0x0c0a8de8u: goto P_0c0a8de8;
case 0x0c0a8deau: goto P_0c0a8dea;
case 0x0c0a8decu: goto P_0c0a8dec;
case 0x0c0a8deeu: goto P_0c0a8dee;
case 0x0c0a8df0u: goto P_0c0a8df0;
case 0x0c0a8df2u: goto P_0c0a8df2;
case 0x0c0a8df4u: goto P_0c0a8df4;
case 0x0c0a8df6u: goto P_0c0a8df6;
case 0x0c0a8df8u: goto P_0c0a8df8;
case 0x0c0a8dfau: goto P_0c0a8dfa;
case 0x0c0a8dfcu: goto P_0c0a8dfc;
case 0x0c0a8dfeu: goto P_0c0a8dfe;
case 0x0c0a8f10u: goto P_0c0a8f10;
case 0x0c0a8f12u: goto P_0c0a8f12;
case 0x0c0a8f14u: goto P_0c0a8f14;
case 0x0c0a8f16u: goto P_0c0a8f16;
case 0x0c0a8f18u: goto P_0c0a8f18;
case 0x0c0a8f1au: goto P_0c0a8f1a;
case 0x0c0a8f1cu: goto P_0c0a8f1c;
case 0x0c0a8f1eu: goto P_0c0a8f1e;
case 0x0c0a8f20u: goto P_0c0a8f20;
case 0x0c0a8f22u: goto P_0c0a8f22;
case 0x0c0a8f24u: goto P_0c0a8f24;
case 0x0c0a8f26u: goto P_0c0a8f26;
case 0x0c0a8f28u: goto P_0c0a8f28;
case 0x0c0a8f2au: goto P_0c0a8f2a;
case 0x0c0a8f2cu: goto P_0c0a8f2c;
case 0x0c0a8f2eu: goto P_0c0a8f2e;
case 0x0c0a8f30u: goto P_0c0a8f30;
case 0x0c0a8f32u: goto P_0c0a8f32;
case 0x0c0a8f34u: goto P_0c0a8f34;
case 0x0c0a8f36u: goto P_0c0a8f36;
case 0x0c0a8f38u: goto P_0c0a8f38;
case 0x0c0a8f3au: goto P_0c0a8f3a;
case 0x0c0a8f3cu: goto P_0c0a8f3c;
case 0x0c0a8f3eu: goto P_0c0a8f3e;
case 0x0c0a8f40u: goto P_0c0a8f40;
case 0x0c0a8f42u: goto P_0c0a8f42;
case 0x0c0a8f44u: goto P_0c0a8f44;
case 0x0c0a8f46u: goto P_0c0a8f46;
case 0x0c0a8f48u: goto P_0c0a8f48;
case 0x0c0a8f4au: goto P_0c0a8f4a;
case 0x0c0a8f8cu: goto P_0c0a8f8c;
case 0x0c0a8f8eu: goto P_0c0a8f8e;
case 0x0c0a8f90u: goto P_0c0a8f90;
case 0x0c0a8f92u: goto P_0c0a8f92;
case 0x0c0a8f94u: goto P_0c0a8f94;
case 0x0c0a8f96u: goto P_0c0a8f96;
case 0x0c0a8f98u: goto P_0c0a8f98;
case 0x0c0a8f9au: goto P_0c0a8f9a;
case 0x0c0a8f9cu: goto P_0c0a8f9c;
case 0x0c0a8f9eu: goto P_0c0a8f9e;
case 0x0c0a8fa0u: goto P_0c0a8fa0;
case 0x0c0a8fa2u: goto P_0c0a8fa2;
case 0x0c0a8fa4u: goto P_0c0a8fa4;
case 0x0c0a8fa6u: goto P_0c0a8fa6;
case 0x0c0a8fa8u: goto P_0c0a8fa8;
case 0x0c0a8faau: goto P_0c0a8faa;
case 0x0c0a8facu: goto P_0c0a8fac;
case 0x0c0a8faeu: goto P_0c0a8fae;
case 0x0c0a8fb0u: goto P_0c0a8fb0;
case 0x0c0a8fb2u: goto P_0c0a8fb2;
case 0x0c0a8fb4u: goto P_0c0a8fb4;
case 0x0c0a8fb6u: goto P_0c0a8fb6;
case 0x0c0a8fb8u: goto P_0c0a8fb8;
case 0x0c0a8fbau: goto P_0c0a8fba;
case 0x0c0a8fbcu: goto P_0c0a8fbc;
case 0x0c0a8fbeu: goto P_0c0a8fbe;
case 0x0c0a8fc0u: goto P_0c0a8fc0;
case 0x0c0a8fc2u: goto P_0c0a8fc2;
case 0x0c0a8fc4u: goto P_0c0a8fc4;
case 0x0c0a8fc6u: goto P_0c0a8fc6;
case 0x0c0a8fc8u: goto P_0c0a8fc8;
case 0x0c0a8fcau: goto P_0c0a8fca;
case 0x0c0a8fccu: goto P_0c0a8fcc;
case 0x0c0a8fceu: goto P_0c0a8fce;
case 0x0c0a8fd0u: goto P_0c0a8fd0;
case 0x0c0a8fd2u: goto P_0c0a8fd2;
case 0x0c0a8fd4u: goto P_0c0a8fd4;
case 0x0c0a8fd6u: goto P_0c0a8fd6;
case 0x0c0a8fd8u: goto P_0c0a8fd8;
case 0x0c0a8fdau: goto P_0c0a8fda;
case 0x0c0a8fdcu: goto P_0c0a8fdc;
case 0x0c0a8fdeu: goto P_0c0a8fde;
case 0x0c0a8fe0u: goto P_0c0a8fe0;
case 0x0c0a8fe2u: goto P_0c0a8fe2;
case 0x0c0a8fe4u: goto P_0c0a8fe4;
case 0x0c0a8fe6u: goto P_0c0a8fe6;
case 0x0c0a8fe8u: goto P_0c0a8fe8;
case 0x0c0a8feau: goto P_0c0a8fea;
case 0x0c0a8fecu: goto P_0c0a8fec;
case 0x0c0a8feeu: goto P_0c0a8fee;
case 0x0c0a8ff0u: goto P_0c0a8ff0;
case 0x0c0a8ff2u: goto P_0c0a8ff2;
case 0x0c0a8ff4u: goto P_0c0a8ff4;
case 0x0c0a8ff6u: goto P_0c0a8ff6;
case 0x0c0a8ff8u: goto P_0c0a8ff8;
case 0x0c0a8ffau: goto P_0c0a8ffa;
case 0x0c0a8ffcu: goto P_0c0a8ffc;
case 0x0c0a8ffeu: goto P_0c0a8ffe;
case 0x0c0a9000u: goto P_0c0a9000;
case 0x0c0a9002u: goto P_0c0a9002;
case 0x0c0a9004u: goto P_0c0a9004;
case 0x0c0a9006u: goto P_0c0a9006;
case 0x0c0a9008u: goto P_0c0a9008;
case 0x0c0a900au: goto P_0c0a900a;
case 0x0c0a900cu: goto P_0c0a900c;
case 0x0c0a900eu: goto P_0c0a900e;
case 0x0c0a9010u: goto P_0c0a9010;
case 0x0c0a9012u: goto P_0c0a9012;
case 0x0c0a9014u: goto P_0c0a9014;
case 0x0c0a9016u: goto P_0c0a9016;
case 0x0c0a9018u: goto P_0c0a9018;
case 0x0c0a901au: goto P_0c0a901a;
case 0x0c0a901cu: goto P_0c0a901c;
case 0x0c0a901eu: goto P_0c0a901e;
case 0x0c0a9020u: goto P_0c0a9020;
case 0x0c0a9022u: goto P_0c0a9022;
case 0x0c0a9024u: goto P_0c0a9024;
case 0x0c0a9026u: goto P_0c0a9026;
case 0x0c0a9028u: goto P_0c0a9028;
case 0x0c0a902au: goto P_0c0a902a;
case 0x0c0a902cu: goto P_0c0a902c;
case 0x0c0a902eu: goto P_0c0a902e;
case 0x0c0a9030u: goto P_0c0a9030;
case 0x0c0a9032u: goto P_0c0a9032;
case 0x0c0a9034u: goto P_0c0a9034;
case 0x0c0a9036u: goto P_0c0a9036;
case 0x0c0a9038u: goto P_0c0a9038;
case 0x0c0a903au: goto P_0c0a903a;
case 0x0c0a903cu: goto P_0c0a903c;
case 0x0c0a903eu: goto P_0c0a903e;
case 0x0c0a9040u: goto P_0c0a9040;
case 0x0c0a9042u: goto P_0c0a9042;
case 0x0c0a9044u: goto P_0c0a9044;
case 0x0c0a9046u: goto P_0c0a9046;
case 0x0c0a9048u: goto P_0c0a9048;
case 0x0c0a904au: goto P_0c0a904a;
case 0x0c0a904cu: goto P_0c0a904c;
case 0x0c0a904eu: goto P_0c0a904e;
case 0x0c0a9050u: goto P_0c0a9050;
case 0x0c0a9052u: goto P_0c0a9052;
case 0x0c0a9054u: goto P_0c0a9054;
case 0x0c0a9056u: goto P_0c0a9056;
case 0x0c0a9058u: goto P_0c0a9058;
case 0x0c0a905au: goto P_0c0a905a;
case 0x0c0a905cu: goto P_0c0a905c;
case 0x0c0a905eu: goto P_0c0a905e;
case 0x0c0a9060u: goto P_0c0a9060;
case 0x0c0a9062u: goto P_0c0a9062;
case 0x0c0a9064u: goto P_0c0a9064;
case 0x0c0a9066u: goto P_0c0a9066;
case 0x0c0a9068u: goto P_0c0a9068;
case 0x0c0a906au: goto P_0c0a906a;
case 0x0c0a906cu: goto P_0c0a906c;
case 0x0c0a9088u: goto P_0c0a9088;
case 0x0c0a908au: goto P_0c0a908a;
case 0x0c0a908cu: goto P_0c0a908c;
case 0x0c0a908eu: goto P_0c0a908e;
case 0x0c0a9090u: goto P_0c0a9090;
case 0x0c0a9092u: goto P_0c0a9092;
case 0x0c0a9094u: goto P_0c0a9094;
case 0x0c0a9096u: goto P_0c0a9096;
case 0x0c0a9098u: goto P_0c0a9098;
case 0x0c0a909au: goto P_0c0a909a;
case 0x0c0a909cu: goto P_0c0a909c;
case 0x0c0a909eu: goto P_0c0a909e;
case 0x0c0a90a0u: goto P_0c0a90a0;
case 0x0c0a90a2u: goto P_0c0a90a2;
case 0x0c0a90a4u: goto P_0c0a90a4;
case 0x0c0a90a6u: goto P_0c0a90a6;
case 0x0c0a90a8u: goto P_0c0a90a8;
case 0x0c0a90aau: goto P_0c0a90aa;
case 0x0c0a90acu: goto P_0c0a90ac;
case 0x0c0a90aeu: goto P_0c0a90ae;
case 0x0c0a90b0u: goto P_0c0a90b0;
case 0x0c0a90b2u: goto P_0c0a90b2;
case 0x0c0a90b4u: goto P_0c0a90b4;
case 0x0c0a90b6u: goto P_0c0a90b6;
case 0x0c0a90b8u: goto P_0c0a90b8;
case 0x0c0a90bau: goto P_0c0a90ba;
case 0x0c0a90bcu: goto P_0c0a90bc;
case 0x0c0a90beu: goto P_0c0a90be;
case 0x0c0a90c0u: goto P_0c0a90c0;
case 0x0c0a90c2u: goto P_0c0a90c2;
case 0x0c0a90c4u: goto P_0c0a90c4;
case 0x0c0a90c6u: goto P_0c0a90c6;
case 0x0c0a90c8u: goto P_0c0a90c8;
case 0x0c0a90cau: goto P_0c0a90ca;
case 0x0c0a90ccu: goto P_0c0a90cc;
case 0x0c0a90ceu: goto P_0c0a90ce;
case 0x0c0a90d0u: goto P_0c0a90d0;
case 0x0c0a90d2u: goto P_0c0a90d2;
case 0x0c0a90d4u: goto P_0c0a90d4;
case 0x0c0a90d6u: goto P_0c0a90d6;
case 0x0c0a90d8u: goto P_0c0a90d8;
case 0x0c0a90dau: goto P_0c0a90da;
case 0x0c0a90dcu: goto P_0c0a90dc;
case 0x0c0a90deu: goto P_0c0a90de;
case 0x0c0a90e0u: goto P_0c0a90e0;
case 0x0c0a90e2u: goto P_0c0a90e2;
case 0x0c0a90e4u: goto P_0c0a90e4;
case 0x0c0a90e6u: goto P_0c0a90e6;
case 0x0c0a90e8u: goto P_0c0a90e8;
case 0x0c0a90eau: goto P_0c0a90ea;
case 0x0c0a90ecu: goto P_0c0a90ec;
case 0x0c0a90eeu: goto P_0c0a90ee;
case 0x0c0a90f0u: goto P_0c0a90f0;
case 0x0c0a90f2u: goto P_0c0a90f2;
case 0x0c0a90f4u: goto P_0c0a90f4;
case 0x0c0a90f6u: goto P_0c0a90f6;
case 0x0c0a90f8u: goto P_0c0a90f8;
case 0x0c0a90fau: goto P_0c0a90fa;
case 0x0c0a90fcu: goto P_0c0a90fc;
case 0x0c0a90feu: goto P_0c0a90fe;
case 0x0c0a9100u: goto P_0c0a9100;
case 0x0c0a9102u: goto P_0c0a9102;
case 0x0c0a9104u: goto P_0c0a9104;
case 0x0c0a9106u: goto P_0c0a9106;
case 0x0c0a9108u: goto P_0c0a9108;
case 0x0c0a910au: goto P_0c0a910a;
case 0x0c0a910cu: goto P_0c0a910c;
case 0x0c0a910eu: goto P_0c0a910e;
case 0x0c0a9110u: goto P_0c0a9110;
case 0x0c0a9112u: goto P_0c0a9112;
case 0x0c0a9114u: goto P_0c0a9114;
case 0x0c0a9116u: goto P_0c0a9116;
case 0x0c0a9118u: goto P_0c0a9118;
case 0x0c0a911au: goto P_0c0a911a;
case 0x0c0a911cu: goto P_0c0a911c;
case 0x0c0a911eu: goto P_0c0a911e;
case 0x0c0a9120u: goto P_0c0a9120;
case 0x0c0a9122u: goto P_0c0a9122;
case 0x0c0a9124u: goto P_0c0a9124;
case 0x0c0a9126u: goto P_0c0a9126;
case 0x0c0a9128u: goto P_0c0a9128;
case 0x0c0a912au: goto P_0c0a912a;
case 0x0c0a912cu: goto P_0c0a912c;
case 0x0c0a912eu: goto P_0c0a912e;
case 0x0c0a9130u: goto P_0c0a9130;
case 0x0c0a9132u: goto P_0c0a9132;
case 0x0c0a9134u: goto P_0c0a9134;
case 0x0c0a9136u: goto P_0c0a9136;
case 0x0c0a9138u: goto P_0c0a9138;
case 0x0c0a913au: goto P_0c0a913a;
case 0x0c0a913cu: goto P_0c0a913c;
case 0x0c0a913eu: goto P_0c0a913e;
case 0x0c0a9140u: goto P_0c0a9140;
case 0x0c0a9142u: goto P_0c0a9142;
case 0x0c0a9144u: goto P_0c0a9144;
case 0x0c0a9146u: goto P_0c0a9146;
case 0x0c0a9148u: goto P_0c0a9148;
case 0x0c0a914au: goto P_0c0a914a;
case 0x0c0a914cu: goto P_0c0a914c;
case 0x0c0a914eu: goto P_0c0a914e;
case 0x0c0a9150u: goto P_0c0a9150;
case 0x0c0a9152u: goto P_0c0a9152;
case 0x0c0a9154u: goto P_0c0a9154;
case 0x0c0a9156u: goto P_0c0a9156;
case 0x0c0a9158u: goto P_0c0a9158;
case 0x0c0a915au: goto P_0c0a915a;
case 0x0c0a915cu: goto P_0c0a915c;
case 0x0c0a915eu: goto P_0c0a915e;
case 0x0c0a9160u: goto P_0c0a9160;
case 0x0c0a9162u: goto P_0c0a9162;
case 0x0c0a9164u: goto P_0c0a9164;
case 0x0c0a9166u: goto P_0c0a9166;
case 0x0c0a9168u: goto P_0c0a9168;
case 0x0c0a916au: goto P_0c0a916a;
case 0x0c0a916cu: goto P_0c0a916c;
case 0x0c0a916eu: goto P_0c0a916e;
case 0x0c0a9170u: goto P_0c0a9170;
case 0x0c0a9172u: goto P_0c0a9172;
case 0x0c0a9174u: goto P_0c0a9174;
case 0x0c0a9176u: goto P_0c0a9176;
case 0x0c0a9178u: goto P_0c0a9178;
case 0x0c0a917au: goto P_0c0a917a;
case 0x0c0a917cu: goto P_0c0a917c;
case 0x0c0a917eu: goto P_0c0a917e;
case 0x0c0a9180u: goto P_0c0a9180;
case 0x0c0a9182u: goto P_0c0a9182;
case 0x0c0a9184u: goto P_0c0a9184;
case 0x0c0a9186u: goto P_0c0a9186;
case 0x0c0a9188u: goto P_0c0a9188;
case 0x0c0a918au: goto P_0c0a918a;
case 0x0c0a918cu: goto P_0c0a918c;
case 0x0c0a918eu: goto P_0c0a918e;
case 0x0c0a9190u: goto P_0c0a9190;
case 0x0c0a9192u: goto P_0c0a9192;
case 0x0c0a9194u: goto P_0c0a9194;
case 0x0c0a9196u: goto P_0c0a9196;
case 0x0c0a9198u: goto P_0c0a9198;
case 0x0c0a919au: goto P_0c0a919a;
case 0x0c0a91c0u: goto P_0c0a91c0;
case 0x0c0a91c2u: goto P_0c0a91c2;
case 0x0c0a91c4u: goto P_0c0a91c4;
case 0x0c0a91c6u: goto P_0c0a91c6;
case 0x0c0a91c8u: goto P_0c0a91c8;
case 0x0c0a91cau: goto P_0c0a91ca;
case 0x0c0a91ccu: goto P_0c0a91cc;
case 0x0c0a91ceu: goto P_0c0a91ce;
case 0x0c0a91d0u: goto P_0c0a91d0;
case 0x0c0a91d2u: goto P_0c0a91d2;
case 0x0c0a91d4u: goto P_0c0a91d4;
case 0x0c0a91d6u: goto P_0c0a91d6;
case 0x0c0a91d8u: goto P_0c0a91d8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a8d58: /* original e004, guest PC 0x0c0a8d58 */
if(!s->budget--) { s->failed_pc=0x0c0a8d58u; return 0; }
r[0]=0x00000004u;
goto P_0c0a8d5a;
P_0c0a8d5a: /* original 2fe6, guest PC 0x0c0a8d5a */
if(!s->budget--) { s->failed_pc=0x0c0a8d5au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8d5c;
P_0c0a8d5c: /* original 4f22, guest PC 0x0c0a8d5c */
if(!s->budget--) { s->failed_pc=0x0c0a8d5cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a8d5e;
P_0c0a8d5e: /* original 6e43, guest PC 0x0c0a8d5e */
if(!s->budget--) { s->failed_pc=0x0c0a8d5eu; return 0; }
r[14]=r[4];
goto P_0c0a8d60;
P_0c0a8d60: /* original 6262, guest PC 0x0c0a8d60 */
if(!s->budget--) { s->failed_pc=0x0c0a8d60u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c0a8d62;
P_0c0a8d62: /* original e3fe, guest PC 0x0c0a8d62 */
if(!s->budget--) { s->failed_pc=0x0c0a8d62u; return 0; }
r[3]=0xfffffffeu;
goto P_0c0a8d64;
P_0c0a8d64: /* original 7ff8, guest PC 0x0c0a8d64 */
if(!s->budget--) { s->failed_pc=0x0c0a8d64u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a8d66;
P_0c0a8d66: /* original 2239, guest PC 0x0c0a8d66 */
if(!s->budget--) { s->failed_pc=0x0c0a8d66u; return 0; }
r[2]&=r[3];
goto P_0c0a8d68;
P_0c0a8d68: /* original 2e22, guest PC 0x0c0a8d68 */
if(!s->budget--) { s->failed_pc=0x0c0a8d68u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0a8d6a;
P_0c0a8d6a: /* original f466, guest PC 0x0c0a8d6a */
if(!s->budget--) { s->failed_pc=0x0c0a8d6au; return 0; }
vf3_matrix_load(s,ram,4,r[6]+r[0]);
goto P_0c0a8d6c;
P_0c0a8d6c: /* original e008, guest PC 0x0c0a8d6c */
if(!s->budget--) { s->failed_pc=0x0c0a8d6cu; return 0; }
r[0]=0x00000008u;
goto P_0c0a8d6e;
P_0c0a8d6e: /* original f566, guest PC 0x0c0a8d6e */
if(!s->budget--) { s->failed_pc=0x0c0a8d6eu; return 0; }
vf3_matrix_load(s,ram,5,r[6]+r[0]);
goto P_0c0a8d70;
P_0c0a8d70: /* original e00c, guest PC 0x0c0a8d70 */
if(!s->budget--) { s->failed_pc=0x0c0a8d70u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a8d72;
P_0c0a8d72: /* original f666, guest PC 0x0c0a8d72 */
if(!s->budget--) { s->failed_pc=0x0c0a8d72u; return 0; }
vf3_matrix_load(s,ram,6,r[6]+r[0]);
goto P_0c0a8d74;
P_0c0a8d74: /* original 856a, guest PC 0x0c0a8d74 */
if(!s->budget--) { s->failed_pc=0x0c0a8d74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+20,2);
goto P_0c0a8d76;
P_0c0a8d76: /* original 5464, guest PC 0x0c0a8d76 */
if(!s->budget--) { s->failed_pc=0x0c0a8d76u; return 0; }
r[4]=read(ram,r[6]+16,4);
goto P_0c0a8d78;
P_0c0a8d78: /* original 6703, guest PC 0x0c0a8d78 */
if(!s->budget--) { s->failed_pc=0x0c0a8d78u; return 0; }
r[7]=r[0];
goto P_0c0a8d7a;
P_0c0a8d7a: /* original 856c, guest PC 0x0c0a8d7a */
if(!s->budget--) { s->failed_pc=0x0c0a8d7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+24,2);
goto P_0c0a8d7c;
P_0c0a8d7c: /* original 2f01, guest PC 0x0c0a8d7c */
if(!s->budget--) { s->failed_pc=0x0c0a8d7cu; return 0; }
write(ram,r[15],r[0],2);
goto P_0c0a8d7e;
P_0c0a8d7e: /* original e010, guest PC 0x0c0a8d7e */
if(!s->budget--) { s->failed_pc=0x0c0a8d7eu; return 0; }
r[0]=0x00000010u;
goto P_0c0a8d80;
P_0c0a8d80: /* original 5267, guest PC 0x0c0a8d80 */
if(!s->budget--) { s->failed_pc=0x0c0a8d80u; return 0; }
r[2]=read(ram,r[6]+28,4);
goto P_0c0a8d82;
P_0c0a8d82: /* original 1f21, guest PC 0x0c0a8d82 */
if(!s->budget--) { s->failed_pc=0x0c0a8d82u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a8d84;
P_0c0a8d84: /* original fe47, guest PC 0x0c0a8d84 */
if(!s->budget--) { s->failed_pc=0x0c0a8d84u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a8d86;
P_0c0a8d86: /* original e014, guest PC 0x0c0a8d86 */
if(!s->budget--) { s->failed_pc=0x0c0a8d86u; return 0; }
r[0]=0x00000014u;
goto P_0c0a8d88;
P_0c0a8d88: /* original fe57, guest PC 0x0c0a8d88 */
if(!s->budget--) { s->failed_pc=0x0c0a8d88u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a8d8a;
P_0c0a8d8a: /* original e018, guest PC 0x0c0a8d8a */
if(!s->budget--) { s->failed_pc=0x0c0a8d8au; return 0; }
r[0]=0x00000018u;
goto P_0c0a8d8c;
P_0c0a8d8c: /* original fe67, guest PC 0x0c0a8d8c */
if(!s->budget--) { s->failed_pc=0x0c0a8d8cu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c0a8d8e;
P_0c0a8d8e: /* original e048, guest PC 0x0c0a8d8e */
if(!s->budget--) { s->failed_pc=0x0c0a8d8eu; return 0; }
r[0]=0x00000048u;
goto P_0c0a8d90;
P_0c0a8d90: /* original 0e46, guest PC 0x0c0a8d90 */
if(!s->budget--) { s->failed_pc=0x0c0a8d90u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0a8d92;
P_0c0a8d92: /* original 6073, guest PC 0x0c0a8d92 */
if(!s->budget--) { s->failed_pc=0x0c0a8d92u; return 0; }
r[0]=r[7];
goto P_0c0a8d94;
P_0c0a8d94: /* original 81ef, guest PC 0x0c0a8d94 */
if(!s->budget--) { s->failed_pc=0x0c0a8d94u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0a8d96;
P_0c0a8d96: /* original 62f1, guest PC 0x0c0a8d96 */
if(!s->budget--) { s->failed_pc=0x0c0a8d96u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[2]=tmp;
goto P_0c0a8d98;
P_0c0a8d98: /* original e03e, guest PC 0x0c0a8d98 */
if(!s->budget--) { s->failed_pc=0x0c0a8d98u; return 0; }
r[0]=0x0000003eu;
goto P_0c0a8d9a;
P_0c0a8d9a: /* original 0e25, guest PC 0x0c0a8d9a */
if(!s->budget--) { s->failed_pc=0x0c0a8d9au; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0a8d9c;
P_0c0a8d9c: /* original 9030, guest PC 0x0c0a8d9c */
if(!s->budget--) { s->failed_pc=0x0c0a8d9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8e00u,2);
goto P_0c0a8d9e;
P_0c0a8d9e: /* original 51f1, guest PC 0x0c0a8d9e */
if(!s->budget--) { s->failed_pc=0x0c0a8d9eu; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0a8da0;
P_0c0a8da0: /* original 0e16, guest PC 0x0c0a8da0 */
if(!s->budget--) { s->failed_pc=0x0c0a8da0u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c0a8da2;
P_0c0a8da2: /* original e03c, guest PC 0x0c0a8da2 */
if(!s->budget--) { s->failed_pc=0x0c0a8da2u; return 0; }
r[0]=0x0000003cu;
goto P_0c0a8da4;
P_0c0a8da4: /* original 07ed, guest PC 0x0c0a8da4 */
if(!s->budget--) { s->failed_pc=0x0c0a8da4u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a8da6;
P_0c0a8da6: /* original 856b, guest PC 0x0c0a8da6 */
if(!s->budget--) { s->failed_pc=0x0c0a8da6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+22,2);
goto P_0c0a8da8;
P_0c0a8da8: /* original 6403, guest PC 0x0c0a8da8 */
if(!s->budget--) { s->failed_pc=0x0c0a8da8u; return 0; }
r[4]=r[0];
goto P_0c0a8daa;
P_0c0a8daa: /* original 664f, guest PC 0x0c0a8daa */
if(!s->budget--) { s->failed_pc=0x0c0a8daau; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0a8dac;
P_0c0a8dac: /* original 2668, guest PC 0x0c0a8dac */
if(!s->budget--) { s->failed_pc=0x0c0a8dacu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0a8dae;
P_0c0a8dae: /* original e03c, guest PC 0x0c0a8dae */
if(!s->budget--) { s->failed_pc=0x0c0a8daeu; return 0; }
r[0]=0x0000003cu;
goto P_0c0a8db0;
P_0c0a8db0: /* original 8d22, guest PC 0x0c0a8db0 */
if(!s->budget--) { s->failed_pc=0x0c0a8db0u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],2);
if(cond) { goto P_0c0a8df8; }
goto P_0c0a8db4;
P_0c0a8db2: /* original 0e45, guest PC 0x0c0a8db2 */
if(!s->budget--) { s->failed_pc=0x0c0a8db2u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a8db4;
P_0c0a8db4: /* original 677f, guest PC 0x0c0a8db4 */
if(!s->budget--) { s->failed_pc=0x0c0a8db4u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)r[7];
goto P_0c0a8db6;
P_0c0a8db6: /* original 3760, guest PC 0x0c0a8db6 */
if(!s->budget--) { s->failed_pc=0x0c0a8db6u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[6])!=0);
goto P_0c0a8db8;
P_0c0a8db8: /* original 8b06, guest PC 0x0c0a8db8 */
if(!s->budget--) { s->failed_pc=0x0c0a8db8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8dc8; }
goto P_0c0a8dba;
P_0c0a8dba: /* original e03e, guest PC 0x0c0a8dba */
if(!s->budget--) { s->failed_pc=0x0c0a8dbau; return 0; }
r[0]=0x0000003eu;
goto P_0c0a8dbc;
P_0c0a8dbc: /* original 04ed, guest PC 0x0c0a8dbc */
if(!s->budget--) { s->failed_pc=0x0c0a8dbcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a8dbe;
P_0c0a8dbe: /* original 604f, guest PC 0x0c0a8dbe */
if(!s->budget--) { s->failed_pc=0x0c0a8dbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0a8dc0;
P_0c0a8dc0: /* original 8801, guest PC 0x0c0a8dc0 */
if(!s->budget--) { s->failed_pc=0x0c0a8dc0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a8dc2;
P_0c0a8dc2: /* original 890b, guest PC 0x0c0a8dc2 */
if(!s->budget--) { s->failed_pc=0x0c0a8dc2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8ddc; }
goto P_0c0a8dc4;
P_0c0a8dc4: /* original a00f, guest PC 0x0c0a8dc4 */
if(!s->budget--) { s->failed_pc=0x0c0a8dc4u; return 0; }
goto P_0c0a8de6;
P_0c0a8dc6: /* original 0009, guest PC 0x0c0a8dc6 */
if(!s->budget--) { s->failed_pc=0x0c0a8dc6u; return 0; }
goto P_0c0a8dc8;
P_0c0a8dc8: /* original 02ed, guest PC 0x0c0a8dc8 */
if(!s->budget--) { s->failed_pc=0x0c0a8dc8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a8dca;
P_0c0a8dca: /* original 622d, guest PC 0x0c0a8dca */
if(!s->budget--) { s->failed_pc=0x0c0a8dcau; return 0; }
r[2]=r[2]&65535u;
goto P_0c0a8dcc;
P_0c0a8dcc: /* original 6623, guest PC 0x0c0a8dcc */
if(!s->budget--) { s->failed_pc=0x0c0a8dccu; return 0; }
r[6]=r[2];
goto P_0c0a8dce;
P_0c0a8dce: /* original 2f22, guest PC 0x0c0a8dce */
if(!s->budget--) { s->failed_pc=0x0c0a8dceu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a8dd0;
P_0c0a8dd0: /* original d30c, guest PC 0x0c0a8dd0 */
if(!s->budget--) { s->failed_pc=0x0c0a8dd0u; return 0; }
r[3]=read(ram,0x0c0a8e04u,4);
goto P_0c0a8dd2;
P_0c0a8dd2: /* original 430b, guest PC 0x0c0a8dd2 */
if(!s->budget--) { s->failed_pc=0x0c0a8dd2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8dd6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8dd6u) { target=s->pc; goto dispatch; }
goto P_0c0a8dd6;
P_0c0a8dd4: /* original 64e3, guest PC 0x0c0a8dd4 */
if(!s->budget--) { s->failed_pc=0x0c0a8dd4u; return 0; }
r[4]=r[14];
goto P_0c0a8dd6;
P_0c0a8dd6: /* original d20c, guest PC 0x0c0a8dd6 */
if(!s->budget--) { s->failed_pc=0x0c0a8dd6u; return 0; }
r[2]=read(ram,0x0c0a8e08u,4);
goto P_0c0a8dd8;
P_0c0a8dd8: /* original 420b, guest PC 0x0c0a8dd8 */
if(!s->budget--) { s->failed_pc=0x0c0a8dd8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a8ddcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8ddcu) { target=s->pc; goto dispatch; }
goto P_0c0a8ddc;
P_0c0a8dda: /* original 64e3, guest PC 0x0c0a8dda */
if(!s->budget--) { s->failed_pc=0x0c0a8ddau; return 0; }
r[4]=r[14];
goto P_0c0a8ddc;
P_0c0a8ddc: /* original d30b, guest PC 0x0c0a8ddc */
if(!s->budget--) { s->failed_pc=0x0c0a8ddcu; return 0; }
r[3]=read(ram,0x0c0a8e0cu,4);
goto P_0c0a8dde;
P_0c0a8dde: /* original 430b, guest PC 0x0c0a8dde */
if(!s->budget--) { s->failed_pc=0x0c0a8ddeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8de2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8de2u) { target=s->pc; goto dispatch; }
goto P_0c0a8de2;
P_0c0a8de0: /* original 64e3, guest PC 0x0c0a8de0 */
if(!s->budget--) { s->failed_pc=0x0c0a8de0u; return 0; }
r[4]=r[14];
goto P_0c0a8de2;
P_0c0a8de2: /* original a003, guest PC 0x0c0a8de2 */
if(!s->budget--) { s->failed_pc=0x0c0a8de2u; return 0; }
goto P_0c0a8dec;
P_0c0a8de4: /* original 0009, guest PC 0x0c0a8de4 */
if(!s->budget--) { s->failed_pc=0x0c0a8de4u; return 0; }
goto P_0c0a8de6;
P_0c0a8de6: /* original d30a, guest PC 0x0c0a8de6 */
if(!s->budget--) { s->failed_pc=0x0c0a8de6u; return 0; }
r[3]=read(ram,0x0c0a8e10u,4);
goto P_0c0a8de8;
P_0c0a8de8: /* original 430b, guest PC 0x0c0a8de8 */
if(!s->budget--) { s->failed_pc=0x0c0a8de8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8decu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8decu) { target=s->pc; goto dispatch; }
goto P_0c0a8dec;
P_0c0a8dea: /* original 64e3, guest PC 0x0c0a8dea */
if(!s->budget--) { s->failed_pc=0x0c0a8deau; return 0; }
r[4]=r[14];
goto P_0c0a8dec;
P_0c0a8dec: /* original 7f08, guest PC 0x0c0a8dec */
if(!s->budget--) { s->failed_pc=0x0c0a8decu; return 0; }
r[15]+=0x00000008u;
goto P_0c0a8dee;
P_0c0a8dee: /* original d209, guest PC 0x0c0a8dee */
if(!s->budget--) { s->failed_pc=0x0c0a8deeu; return 0; }
r[2]=read(ram,0x0c0a8e14u,4);
goto P_0c0a8df0;
P_0c0a8df0: /* original 4f26, guest PC 0x0c0a8df0 */
if(!s->budget--) { s->failed_pc=0x0c0a8df0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8df2;
P_0c0a8df2: /* original 64e3, guest PC 0x0c0a8df2 */
if(!s->budget--) { s->failed_pc=0x0c0a8df2u; return 0; }
r[4]=r[14];
goto P_0c0a8df4;
P_0c0a8df4: /* original 422b, guest PC 0x0c0a8df4 */
if(!s->budget--) { s->failed_pc=0x0c0a8df4u; return 0; }
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
P_0c0a8df6: /* original 6ef6, guest PC 0x0c0a8df6 */
if(!s->budget--) { s->failed_pc=0x0c0a8df6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a8df8;
P_0c0a8df8: /* original 7f08, guest PC 0x0c0a8df8 */
if(!s->budget--) { s->failed_pc=0x0c0a8df8u; return 0; }
r[15]+=0x00000008u;
goto P_0c0a8dfa;
P_0c0a8dfa: /* original 4f26, guest PC 0x0c0a8dfa */
if(!s->budget--) { s->failed_pc=0x0c0a8dfau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8dfc;
P_0c0a8dfc: /* original 000b, guest PC 0x0c0a8dfc */
if(!s->budget--) { s->failed_pc=0x0c0a8dfcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a8dfe: /* original 6ef6, guest PC 0x0c0a8dfe */
if(!s->budget--) { s->failed_pc=0x0c0a8dfeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a8e00u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a8e00u; return 0; } return 1;
P_0c0a8f10: /* original c71d, guest PC 0x0c0a8f10 */
if(!s->budget--) { s->failed_pc=0x0c0a8f10u; return 0; }
r[0]=code_base|0x000a8f88u;
goto P_0c0a8f12;
P_0c0a8f12: /* original f558, guest PC 0x0c0a8f12 */
if(!s->budget--) { s->failed_pc=0x0c0a8f12u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
goto P_0c0a8f14;
P_0c0a8f14: /* original f408, guest PC 0x0c0a8f14 */
if(!s->budget--) { s->failed_pc=0x0c0a8f14u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0a8f16;
P_0c0a8f16: /* original e010, guest PC 0x0c0a8f16 */
if(!s->budget--) { s->failed_pc=0x0c0a8f16u; return 0; }
r[0]=0x00000010u;
goto P_0c0a8f18;
P_0c0a8f18: /* original f346, guest PC 0x0c0a8f18 */
if(!s->budget--) { s->failed_pc=0x0c0a8f18u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a8f1a;
P_0c0a8f1a: /* original e014, guest PC 0x0c0a8f1a */
if(!s->budget--) { s->failed_pc=0x0c0a8f1au; return 0; }
r[0]=0x00000014u;
goto P_0c0a8f1c;
P_0c0a8f1c: /* original f64c, guest PC 0x0c0a8f1c */
if(!s->budget--) { s->failed_pc=0x0c0a8f1cu; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c0a8f1e;
P_0c0a8f1e: /* original f530, guest PC 0x0c0a8f1e */
if(!s->budget--) { s->failed_pc=0x0c0a8f1eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0a8f20;
P_0c0a8f20: /* original f346, guest PC 0x0c0a8f20 */
if(!s->budget--) { s->failed_pc=0x0c0a8f20u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a8f22;
P_0c0a8f22: /* original f74c, guest PC 0x0c0a8f22 */
if(!s->budget--) { s->failed_pc=0x0c0a8f22u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c0a8f24;
P_0c0a8f24: /* original e018, guest PC 0x0c0a8f24 */
if(!s->budget--) { s->failed_pc=0x0c0a8f24u; return 0; }
r[0]=0x00000018u;
goto P_0c0a8f26;
P_0c0a8f26: /* original f652, guest PC 0x0c0a8f26 */
if(!s->budget--) { s->failed_pc=0x0c0a8f26u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c0a8f28;
P_0c0a8f28: /* original f568, guest PC 0x0c0a8f28 */
if(!s->budget--) { s->failed_pc=0x0c0a8f28u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0a8f2a;
P_0c0a8f2a: /* original f530, guest PC 0x0c0a8f2a */
if(!s->budget--) { s->failed_pc=0x0c0a8f2au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0a8f2c;
P_0c0a8f2c: /* original f346, guest PC 0x0c0a8f2c */
if(!s->budget--) { s->failed_pc=0x0c0a8f2cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a8f2e;
P_0c0a8f2e: /* original f752, guest PC 0x0c0a8f2e */
if(!s->budget--) { s->failed_pc=0x0c0a8f2eu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'*');
goto P_0c0a8f30;
P_0c0a8f30: /* original f578, guest PC 0x0c0a8f30 */
if(!s->budget--) { s->failed_pc=0x0c0a8f30u; return 0; }
vf3_matrix_load(s,ram,5,r[7]);
goto P_0c0a8f32;
P_0c0a8f32: /* original f56a, guest PC 0x0c0a8f32 */
if(!s->budget--) { s->failed_pc=0x0c0a8f32u; return 0; }
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c0a8f34;
P_0c0a8f34: /* original f530, guest PC 0x0c0a8f34 */
if(!s->budget--) { s->failed_pc=0x0c0a8f34u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0a8f36;
P_0c0a8f36: /* original f67a, guest PC 0x0c0a8f36 */
if(!s->budget--) { s->failed_pc=0x0c0a8f36u; return 0; }
vf3_matrix_store(s,ram,7,r[6]);
goto P_0c0a8f38;
P_0c0a8f38: /* original f452, guest PC 0x0c0a8f38 */
if(!s->budget--) { s->failed_pc=0x0c0a8f38u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c0a8f3a;
P_0c0a8f3a: /* original 000b, guest PC 0x0c0a8f3a */
if(!s->budget--) { s->failed_pc=0x0c0a8f3au; return 0; }
target=r[16];
vf3_matrix_store(s,ram,4,r[7]);
s->pc=target; return ram->oob==0;
P_0c0a8f3c: /* original f74a, guest PC 0x0c0a8f3c */
if(!s->budget--) { s->failed_pc=0x0c0a8f3cu; return 0; }
vf3_matrix_store(s,ram,4,r[7]);
goto P_0c0a8f3e;
P_0c0a8f3e: /* original 854f, guest PC 0x0c0a8f3e */
if(!s->budget--) { s->failed_pc=0x0c0a8f3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+30,2);
goto P_0c0a8f40;
P_0c0a8f40: /* original 655f, guest PC 0x0c0a8f40 */
if(!s->budget--) { s->failed_pc=0x0c0a8f40u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c0a8f42;
P_0c0a8f42: /* original 6403, guest PC 0x0c0a8f42 */
if(!s->budget--) { s->failed_pc=0x0c0a8f42u; return 0; }
r[4]=r[0];
goto P_0c0a8f44;
P_0c0a8f44: /* original 345c, guest PC 0x0c0a8f44 */
if(!s->budget--) { s->failed_pc=0x0c0a8f44u; return 0; }
r[4]+=r[5];
goto P_0c0a8f46;
P_0c0a8f46: /* original 4421, guest PC 0x0c0a8f46 */
if(!s->budget--) { s->failed_pc=0x0c0a8f46u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]=(uint32_t)((int32_t)r[4]>>1);
goto P_0c0a8f48;
P_0c0a8f48: /* original 000b, guest PC 0x0c0a8f48 */
if(!s->budget--) { s->failed_pc=0x0c0a8f48u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c0a8f4a: /* original 6043, guest PC 0x0c0a8f4a */
if(!s->budget--) { s->failed_pc=0x0c0a8f4au; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c0a8f4cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a8f4cu; return 0; } return 1;
P_0c0a8f8c: /* original 2fe6, guest PC 0x0c0a8f8c */
if(!s->budget--) { s->failed_pc=0x0c0a8f8cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8f8e;
P_0c0a8f8e: /* original 6e53, guest PC 0x0c0a8f8e */
if(!s->budget--) { s->failed_pc=0x0c0a8f8eu; return 0; }
r[14]=r[5];
goto P_0c0a8f90;
P_0c0a8f90: /* original 2fd6, guest PC 0x0c0a8f90 */
if(!s->budget--) { s->failed_pc=0x0c0a8f90u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8f92;
P_0c0a8f92: /* original 6d43, guest PC 0x0c0a8f92 */
if(!s->budget--) { s->failed_pc=0x0c0a8f92u; return 0; }
r[13]=r[4];
goto P_0c0a8f94;
P_0c0a8f94: /* original 906b, guest PC 0x0c0a8f94 */
if(!s->budget--) { s->failed_pc=0x0c0a8f94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a906eu,2);
goto P_0c0a8f96;
P_0c0a8f96: /* original e700, guest PC 0x0c0a8f96 */
if(!s->budget--) { s->failed_pc=0x0c0a8f96u; return 0; }
r[7]=0x00000000u;
goto P_0c0a8f98;
P_0c0a8f98: /* original 4f22, guest PC 0x0c0a8f98 */
if(!s->budget--) { s->failed_pc=0x0c0a8f98u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a8f9a;
P_0c0a8f9a: /* original 04ee, guest PC 0x0c0a8f9a */
if(!s->budget--) { s->failed_pc=0x0c0a8f9au; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0a8f9c;
P_0c0a8f9c: /* original e024, guest PC 0x0c0a8f9c */
if(!s->budget--) { s->failed_pc=0x0c0a8f9cu; return 0; }
r[0]=0x00000024u;
goto P_0c0a8f9e;
P_0c0a8f9e: /* original 00dd, guest PC 0x0c0a8f9e */
if(!s->budget--) { s->failed_pc=0x0c0a8f9eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a8fa0;
P_0c0a8fa0: /* original 7ff0, guest PC 0x0c0a8fa0 */
if(!s->budget--) { s->failed_pc=0x0c0a8fa0u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0a8fa2;
P_0c0a8fa2: /* original 81f6, guest PC 0x0c0a8fa2 */
if(!s->budget--) { s->failed_pc=0x0c0a8fa2u; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c0a8fa4;
P_0c0a8fa4: /* original e03e, guest PC 0x0c0a8fa4 */
if(!s->budget--) { s->failed_pc=0x0c0a8fa4u; return 0; }
r[0]=0x0000003eu;
goto P_0c0a8fa6;
P_0c0a8fa6: /* original 0e45, guest PC 0x0c0a8fa6 */
if(!s->budget--) { s->failed_pc=0x0c0a8fa6u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a8fa8;
P_0c0a8fa8: /* original 85f6, guest PC 0x0c0a8fa8 */
if(!s->budget--) { s->failed_pc=0x0c0a8fa8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c0a8faa;
P_0c0a8faa: /* original 6503, guest PC 0x0c0a8faa */
if(!s->budget--) { s->failed_pc=0x0c0a8faau; return 0; }
r[5]=r[0];
goto P_0c0a8fac;
P_0c0a8fac: /* original 3450, guest PC 0x0c0a8fac */
if(!s->budget--) { s->failed_pc=0x0c0a8facu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c0a8fae;
P_0c0a8fae: /* original 8d01, guest PC 0x0c0a8fae */
if(!s->budget--) { s->failed_pc=0x0c0a8faeu; return 0; }
cond=r[17]&1u;
r[6]=r[7];
if(cond) { goto P_0c0a8fb4; }
goto P_0c0a8fb2;
P_0c0a8fb0: /* original 6673, guest PC 0x0c0a8fb0 */
if(!s->budget--) { s->failed_pc=0x0c0a8fb0u; return 0; }
r[6]=r[7];
goto P_0c0a8fb2;
P_0c0a8fb2: /* original 965d, guest PC 0x0c0a8fb2 */
if(!s->budget--) { s->failed_pc=0x0c0a8fb2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9070u,2);
goto P_0c0a8fb4;
P_0c0a8fb4: /* original 3457, guest PC 0x0c0a8fb4 */
if(!s->budget--) { s->failed_pc=0x0c0a8fb4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[5])!=0);
goto P_0c0a8fb6;
P_0c0a8fb6: /* original e040, guest PC 0x0c0a8fb6 */
if(!s->budget--) { s->failed_pc=0x0c0a8fb6u; return 0; }
r[0]=0x00000040u;
goto P_0c0a8fb8;
P_0c0a8fb8: /* original 8d06, guest PC 0x0c0a8fb8 */
if(!s->budget--) { s->failed_pc=0x0c0a8fb8u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[6],2);
if(cond) { goto P_0c0a8fc8; }
goto P_0c0a8fbc;
P_0c0a8fba: /* original 0e65, guest PC 0x0c0a8fba */
if(!s->budget--) { s->failed_pc=0x0c0a8fbau; return 0; }
write(ram,r[14]+r[0],r[6],2);
goto P_0c0a8fbc;
P_0c0a8fbc: /* original e03c, guest PC 0x0c0a8fbc */
if(!s->budget--) { s->failed_pc=0x0c0a8fbcu; return 0; }
r[0]=0x0000003cu;
goto P_0c0a8fbe;
P_0c0a8fbe: /* original 05ed, guest PC 0x0c0a8fbe */
if(!s->budget--) { s->failed_pc=0x0c0a8fbeu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a8fc0;
P_0c0a8fc0: /* original e022, guest PC 0x0c0a8fc0 */
if(!s->budget--) { s->failed_pc=0x0c0a8fc0u; return 0; }
r[0]=0x00000022u;
goto P_0c0a8fc2;
P_0c0a8fc2: /* original 04dd, guest PC 0x0c0a8fc2 */
if(!s->budget--) { s->failed_pc=0x0c0a8fc2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a8fc4;
P_0c0a8fc4: /* original 3540, guest PC 0x0c0a8fc4 */
if(!s->budget--) { s->failed_pc=0x0c0a8fc4u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[4])!=0);
goto P_0c0a8fc6;
P_0c0a8fc6: /* original 8902, guest PC 0x0c0a8fc6 */
if(!s->budget--) { s->failed_pc=0x0c0a8fc6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8fce; }
goto P_0c0a8fc8;
P_0c0a8fc8: /* original e040, guest PC 0x0c0a8fc8 */
if(!s->budget--) { s->failed_pc=0x0c0a8fc8u; return 0; }
r[0]=0x00000040u;
goto P_0c0a8fca;
P_0c0a8fca: /* original a029, guest PC 0x0c0a8fca */
if(!s->budget--) { s->failed_pc=0x0c0a8fcau; return 0; }
write(ram,r[14]+r[0],r[7],2);
goto P_0c0a9020;
P_0c0a8fcc: /* original 0e75, guest PC 0x0c0a8fcc */
if(!s->budget--) { s->failed_pc=0x0c0a8fccu; return 0; }
write(ram,r[14]+r[0],r[7],2);
goto P_0c0a8fce;
P_0c0a8fce: /* original d62a, guest PC 0x0c0a8fce */
if(!s->budget--) { s->failed_pc=0x0c0a8fceu; return 0; }
r[6]=read(ram,0x0c0a9078u,4);
goto P_0c0a8fd0;
P_0c0a8fd0: /* original 65d2, guest PC 0x0c0a8fd0 */
if(!s->budget--) { s->failed_pc=0x0c0a8fd0u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0a8fd2;
P_0c0a8fd2: /* original 64e2, guest PC 0x0c0a8fd2 */
if(!s->budget--) { s->failed_pc=0x0c0a8fd2u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0a8fd4;
P_0c0a8fd4: /* original 2569, guest PC 0x0c0a8fd4 */
if(!s->budget--) { s->failed_pc=0x0c0a8fd4u; return 0; }
r[5]&=r[6];
goto P_0c0a8fd6;
P_0c0a8fd6: /* original 2469, guest PC 0x0c0a8fd6 */
if(!s->budget--) { s->failed_pc=0x0c0a8fd6u; return 0; }
r[4]&=r[6];
goto P_0c0a8fd8;
P_0c0a8fd8: /* original 3450, guest PC 0x0c0a8fd8 */
if(!s->budget--) { s->failed_pc=0x0c0a8fd8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c0a8fda;
P_0c0a8fda: /* original 8b21, guest PC 0x0c0a8fda */
if(!s->budget--) { s->failed_pc=0x0c0a8fdau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9020; }
goto P_0c0a8fdc;
P_0c0a8fdc: /* original e004, guest PC 0x0c0a8fdc */
if(!s->budget--) { s->failed_pc=0x0c0a8fdcu; return 0; }
r[0]=0x00000004u;
goto P_0c0a8fde;
P_0c0a8fde: /* original 65f3, guest PC 0x0c0a8fde */
if(!s->budget--) { s->failed_pc=0x0c0a8fdeu; return 0; }
r[5]=r[15];
goto P_0c0a8fe0;
P_0c0a8fe0: /* original f3d6, guest PC 0x0c0a8fe0 */
if(!s->budget--) { s->failed_pc=0x0c0a8fe0u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0a8fe2;
P_0c0a8fe2: /* original e008, guest PC 0x0c0a8fe2 */
if(!s->budget--) { s->failed_pc=0x0c0a8fe2u; return 0; }
r[0]=0x00000008u;
goto P_0c0a8fe4;
P_0c0a8fe4: /* original 66f3, guest PC 0x0c0a8fe4 */
if(!s->budget--) { s->failed_pc=0x0c0a8fe4u; return 0; }
r[6]=r[15];
goto P_0c0a8fe6;
P_0c0a8fe6: /* original 7508, guest PC 0x0c0a8fe6 */
if(!s->budget--) { s->failed_pc=0x0c0a8fe6u; return 0; }
r[5]+=0x00000008u;
goto P_0c0a8fe8;
P_0c0a8fe8: /* original ff37, guest PC 0x0c0a8fe8 */
if(!s->budget--) { s->failed_pc=0x0c0a8fe8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a8fea;
P_0c0a8fea: /* original e008, guest PC 0x0c0a8fea */
if(!s->budget--) { s->failed_pc=0x0c0a8feau; return 0; }
r[0]=0x00000008u;
goto P_0c0a8fec;
P_0c0a8fec: /* original f3d6, guest PC 0x0c0a8fec */
if(!s->budget--) { s->failed_pc=0x0c0a8fecu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0a8fee;
P_0c0a8fee: /* original e004, guest PC 0x0c0a8fee */
if(!s->budget--) { s->failed_pc=0x0c0a8feeu; return 0; }
r[0]=0x00000004u;
goto P_0c0a8ff0;
P_0c0a8ff0: /* original 7604, guest PC 0x0c0a8ff0 */
if(!s->budget--) { s->failed_pc=0x0c0a8ff0u; return 0; }
r[6]+=0x00000004u;
goto P_0c0a8ff2;
P_0c0a8ff2: /* original 67f3, guest PC 0x0c0a8ff2 */
if(!s->budget--) { s->failed_pc=0x0c0a8ff2u; return 0; }
r[7]=r[15];
goto P_0c0a8ff4;
P_0c0a8ff4: /* original ff37, guest PC 0x0c0a8ff4 */
if(!s->budget--) { s->failed_pc=0x0c0a8ff4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a8ff6;
P_0c0a8ff6: /* original e00c, guest PC 0x0c0a8ff6 */
if(!s->budget--) { s->failed_pc=0x0c0a8ff6u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a8ff8;
P_0c0a8ff8: /* original f3d6, guest PC 0x0c0a8ff8 */
if(!s->budget--) { s->failed_pc=0x0c0a8ff8u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0a8ffa;
P_0c0a8ffa: /* original ff3a, guest PC 0x0c0a8ffa */
if(!s->budget--) { s->failed_pc=0x0c0a8ffau; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0a8ffc;
P_0c0a8ffc: /* original bf88, guest PC 0x0c0a8ffc */
if(!s->budget--) { s->failed_pc=0x0c0a8ffcu; return 0; }
target=code_base|0x0c0a8f10u; r[16]=code_base|0x0c0a9000u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9000u) { target=s->pc; goto dispatch; }
goto P_0c0a9000;
P_0c0a8ffe: /* original 64e3, guest PC 0x0c0a8ffe */
if(!s->budget--) { s->failed_pc=0x0c0a8ffeu; return 0; }
r[4]=r[14];
goto P_0c0a9000;
P_0c0a9000: /* original e008, guest PC 0x0c0a9000 */
if(!s->budget--) { s->failed_pc=0x0c0a9000u; return 0; }
r[0]=0x00000008u;
goto P_0c0a9002;
P_0c0a9002: /* original f6f8, guest PC 0x0c0a9002 */
if(!s->budget--) { s->failed_pc=0x0c0a9002u; return 0; }
vf3_matrix_load(s,ram,6,r[15]);
goto P_0c0a9004;
P_0c0a9004: /* original f4f6, guest PC 0x0c0a9004 */
if(!s->budget--) { s->failed_pc=0x0c0a9004u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0a9006;
P_0c0a9006: /* original e004, guest PC 0x0c0a9006 */
if(!s->budget--) { s->failed_pc=0x0c0a9006u; return 0; }
r[0]=0x00000004u;
goto P_0c0a9008;
P_0c0a9008: /* original f5f6, guest PC 0x0c0a9008 */
if(!s->budget--) { s->failed_pc=0x0c0a9008u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0a900a;
P_0c0a900a: /* original e010, guest PC 0x0c0a900a */
if(!s->budget--) { s->failed_pc=0x0c0a900au; return 0; }
r[0]=0x00000010u;
goto P_0c0a900c;
P_0c0a900c: /* original fe47, guest PC 0x0c0a900c */
if(!s->budget--) { s->failed_pc=0x0c0a900cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a900e;
P_0c0a900e: /* original e014, guest PC 0x0c0a900e */
if(!s->budget--) { s->failed_pc=0x0c0a900eu; return 0; }
r[0]=0x00000014u;
goto P_0c0a9010;
P_0c0a9010: /* original fe57, guest PC 0x0c0a9010 */
if(!s->budget--) { s->failed_pc=0x0c0a9010u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a9012;
P_0c0a9012: /* original e018, guest PC 0x0c0a9012 */
if(!s->budget--) { s->failed_pc=0x0c0a9012u; return 0; }
r[0]=0x00000018u;
goto P_0c0a9014;
P_0c0a9014: /* original fe67, guest PC 0x0c0a9014 */
if(!s->budget--) { s->failed_pc=0x0c0a9014u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c0a9016;
P_0c0a9016: /* original e020, guest PC 0x0c0a9016 */
if(!s->budget--) { s->failed_pc=0x0c0a9016u; return 0; }
r[0]=0x00000020u;
goto P_0c0a9018;
P_0c0a9018: /* original 05dd, guest PC 0x0c0a9018 */
if(!s->budget--) { s->failed_pc=0x0c0a9018u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a901a;
P_0c0a901a: /* original bf90, guest PC 0x0c0a901a */
if(!s->budget--) { s->failed_pc=0x0c0a901au; return 0; }
target=code_base|0x0c0a8f3eu; r[16]=code_base|0x0c0a901eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a901eu) { target=s->pc; goto dispatch; }
goto P_0c0a901e;
P_0c0a901c: /* original 64e3, guest PC 0x0c0a901c */
if(!s->budget--) { s->failed_pc=0x0c0a901cu; return 0; }
r[4]=r[14];
goto P_0c0a901e;
P_0c0a901e: /* original 81ef, guest PC 0x0c0a901e */
if(!s->budget--) { s->failed_pc=0x0c0a901eu; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0a9020;
P_0c0a9020: /* original d216, guest PC 0x0c0a9020 */
if(!s->budget--) { s->failed_pc=0x0c0a9020u; return 0; }
r[2]=read(ram,0x0c0a907cu,4);
goto P_0c0a9022;
P_0c0a9022: /* original 420b, guest PC 0x0c0a9022 */
if(!s->budget--) { s->failed_pc=0x0c0a9022u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a9026u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9026u) { target=s->pc; goto dispatch; }
goto P_0c0a9026;
P_0c0a9024: /* original 64e3, guest PC 0x0c0a9024 */
if(!s->budget--) { s->failed_pc=0x0c0a9024u; return 0; }
r[4]=r[14];
goto P_0c0a9026;
P_0c0a9026: /* original d316, guest PC 0x0c0a9026 */
if(!s->budget--) { s->failed_pc=0x0c0a9026u; return 0; }
r[3]=read(ram,0x0c0a9080u,4);
goto P_0c0a9028;
P_0c0a9028: /* original 430b, guest PC 0x0c0a9028 */
if(!s->budget--) { s->failed_pc=0x0c0a9028u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a902cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a902cu) { target=s->pc; goto dispatch; }
goto P_0c0a902c;
P_0c0a902a: /* original 64e3, guest PC 0x0c0a902a */
if(!s->budget--) { s->failed_pc=0x0c0a902au; return 0; }
r[4]=r[14];
goto P_0c0a902c;
P_0c0a902c: /* original 7f10, guest PC 0x0c0a902c */
if(!s->budget--) { s->failed_pc=0x0c0a902cu; return 0; }
r[15]+=0x00000010u;
goto P_0c0a902e;
P_0c0a902e: /* original 4f26, guest PC 0x0c0a902e */
if(!s->budget--) { s->failed_pc=0x0c0a902eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9030;
P_0c0a9030: /* original 6df6, guest PC 0x0c0a9030 */
if(!s->budget--) { s->failed_pc=0x0c0a9030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a9032;
P_0c0a9032: /* original 000b, guest PC 0x0c0a9032 */
if(!s->budget--) { s->failed_pc=0x0c0a9032u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a9034: /* original 6ef6, guest PC 0x0c0a9034 */
if(!s->budget--) { s->failed_pc=0x0c0a9034u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a9036;
P_0c0a9036: /* original 2fe6, guest PC 0x0c0a9036 */
if(!s->budget--) { s->failed_pc=0x0c0a9036u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a9038;
P_0c0a9038: /* original 2fd6, guest PC 0x0c0a9038 */
if(!s->budget--) { s->failed_pc=0x0c0a9038u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a903a;
P_0c0a903a: /* original 6d43, guest PC 0x0c0a903a */
if(!s->budget--) { s->failed_pc=0x0c0a903au; return 0; }
r[13]=r[4];
goto P_0c0a903c;
P_0c0a903c: /* original 2fc6, guest PC 0x0c0a903c */
if(!s->budget--) { s->failed_pc=0x0c0a903cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a903e;
P_0c0a903e: /* original 2fb6, guest PC 0x0c0a903e */
if(!s->budget--) { s->failed_pc=0x0c0a903eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a9040;
P_0c0a9040: /* original 4f22, guest PC 0x0c0a9040 */
if(!s->budget--) { s->failed_pc=0x0c0a9040u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a9042;
P_0c0a9042: /* original 7fe8, guest PC 0x0c0a9042 */
if(!s->budget--) { s->failed_pc=0x0c0a9042u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0a9044;
P_0c0a9044: /* original 1f61, guest PC 0x0c0a9044 */
if(!s->budget--) { s->failed_pc=0x0c0a9044u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0a9046;
P_0c0a9046: /* original db0f, guest PC 0x0c0a9046 */
if(!s->budget--) { s->failed_pc=0x0c0a9046u; return 0; }
r[11]=read(ram,0x0c0a9084u,4);
goto P_0c0a9048;
P_0c0a9048: /* original 9313, guest PC 0x0c0a9048 */
if(!s->budget--) { s->failed_pc=0x0c0a9048u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9072u,2);
goto P_0c0a904a;
P_0c0a904a: /* original 5cb2, guest PC 0x0c0a904a */
if(!s->budget--) { s->failed_pc=0x0c0a904au; return 0; }
r[12]=read(ram,r[11]+8,4);
goto P_0c0a904c;
P_0c0a904c: /* original 23c8, guest PC 0x0c0a904c */
if(!s->budget--) { s->failed_pc=0x0c0a904cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0a904e;
P_0c0a904e: /* original 8d1b, guest PC 0x0c0a904e */
if(!s->budget--) { s->failed_pc=0x0c0a904eu; return 0; }
cond=r[17]&1u;
r[14]=r[5];
if(cond) { goto P_0c0a9088; }
goto P_0c0a9052;
P_0c0a9050: /* original 6e53, guest PC 0x0c0a9050 */
if(!s->budget--) { s->failed_pc=0x0c0a9050u; return 0; }
r[14]=r[5];
goto P_0c0a9052;
P_0c0a9052: /* original e040, guest PC 0x0c0a9052 */
if(!s->budget--) { s->failed_pc=0x0c0a9052u; return 0; }
r[0]=0x00000040u;
goto P_0c0a9054;
P_0c0a9054: /* original e100, guest PC 0x0c0a9054 */
if(!s->budget--) { s->failed_pc=0x0c0a9054u; return 0; }
r[1]=0x00000000u;
goto P_0c0a9056;
P_0c0a9056: /* original 0e15, guest PC 0x0c0a9056 */
if(!s->budget--) { s->failed_pc=0x0c0a9056u; return 0; }
write(ram,r[14]+r[0],r[1],2);
goto P_0c0a9058;
P_0c0a9058: /* original e301, guest PC 0x0c0a9058 */
if(!s->budget--) { s->failed_pc=0x0c0a9058u; return 0; }
r[3]=0x00000001u;
goto P_0c0a905a;
P_0c0a905a: /* original 900b, guest PC 0x0c0a905a */
if(!s->budget--) { s->failed_pc=0x0c0a905au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9074u,2);
goto P_0c0a905c;
P_0c0a905c: /* original 0cbd, guest PC 0x0c0a905c */
if(!s->budget--) { s->failed_pc=0x0c0a905cu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c0a905e;
P_0c0a905e: /* original 23c8, guest PC 0x0c0a905e */
if(!s->budget--) { s->failed_pc=0x0c0a905eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0a9060;
P_0c0a9060: /* original 8912, guest PC 0x0c0a9060 */
if(!s->budget--) { s->failed_pc=0x0c0a9060u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9088; }
goto P_0c0a9062;
P_0c0a9062: /* original 56f1, guest PC 0x0c0a9062 */
if(!s->budget--) { s->failed_pc=0x0c0a9062u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c0a9064;
P_0c0a9064: /* original 65e3, guest PC 0x0c0a9064 */
if(!s->budget--) { s->failed_pc=0x0c0a9064u; return 0; }
r[5]=r[14];
goto P_0c0a9066;
P_0c0a9066: /* original bf91, guest PC 0x0c0a9066 */
if(!s->budget--) { s->failed_pc=0x0c0a9066u; return 0; }
target=code_base|0x0c0a8f8cu; r[16]=code_base|0x0c0a906au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a906au) { target=s->pc; goto dispatch; }
goto P_0c0a906a;
P_0c0a9068: /* original 64d3, guest PC 0x0c0a9068 */
if(!s->budget--) { s->failed_pc=0x0c0a9068u; return 0; }
r[4]=r[13];
goto P_0c0a906a;
P_0c0a906a: /* original a0af, guest PC 0x0c0a906a */
if(!s->budget--) { s->failed_pc=0x0c0a906au; return 0; }
goto P_0c0a91cc;
P_0c0a906c: /* original 0009, guest PC 0x0c0a906c */
if(!s->budget--) { s->failed_pc=0x0c0a906cu; return 0; }
if(!vf3_matrix_family(0x0c0a906eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a906eu; return 0; } return 1;
P_0c0a9088: /* original e004, guest PC 0x0c0a9088 */
if(!s->budget--) { s->failed_pc=0x0c0a9088u; return 0; }
r[0]=0x00000004u;
goto P_0c0a908a;
P_0c0a908a: /* original 64d2, guest PC 0x0c0a908a */
if(!s->budget--) { s->failed_pc=0x0c0a908au; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a908c;
P_0c0a908c: /* original e3fe, guest PC 0x0c0a908c */
if(!s->budget--) { s->failed_pc=0x0c0a908cu; return 0; }
r[3]=0xfffffffeu;
goto P_0c0a908e;
P_0c0a908e: /* original 2439, guest PC 0x0c0a908e */
if(!s->budget--) { s->failed_pc=0x0c0a908eu; return 0; }
r[4]&=r[3];
goto P_0c0a9090;
P_0c0a9090: /* original 2e42, guest PC 0x0c0a9090 */
if(!s->budget--) { s->failed_pc=0x0c0a9090u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0a9092;
P_0c0a9092: /* original f5d6, guest PC 0x0c0a9092 */
if(!s->budget--) { s->failed_pc=0x0c0a9092u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c0a9094;
P_0c0a9094: /* original e008, guest PC 0x0c0a9094 */
if(!s->budget--) { s->failed_pc=0x0c0a9094u; return 0; }
r[0]=0x00000008u;
goto P_0c0a9096;
P_0c0a9096: /* original f6d6, guest PC 0x0c0a9096 */
if(!s->budget--) { s->failed_pc=0x0c0a9096u; return 0; }
vf3_matrix_load(s,ram,6,r[13]+r[0]);
goto P_0c0a9098;
P_0c0a9098: /* original e00c, guest PC 0x0c0a9098 */
if(!s->budget--) { s->failed_pc=0x0c0a9098u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a909a;
P_0c0a909a: /* original f4d6, guest PC 0x0c0a909a */
if(!s->budget--) { s->failed_pc=0x0c0a909au; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c0a909c;
P_0c0a909c: /* original e020, guest PC 0x0c0a909c */
if(!s->budget--) { s->failed_pc=0x0c0a909cu; return 0; }
r[0]=0x00000020u;
goto P_0c0a909e;
P_0c0a909e: /* original 00dd, guest PC 0x0c0a909e */
if(!s->budget--) { s->failed_pc=0x0c0a909eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a90a0;
P_0c0a90a0: /* original 81f4, guest PC 0x0c0a90a0 */
if(!s->budget--) { s->failed_pc=0x0c0a90a0u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c0a90a2;
P_0c0a90a2: /* original e024, guest PC 0x0c0a90a2 */
if(!s->budget--) { s->failed_pc=0x0c0a90a2u; return 0; }
r[0]=0x00000024u;
goto P_0c0a90a4;
P_0c0a90a4: /* original 04dd, guest PC 0x0c0a90a4 */
if(!s->budget--) { s->failed_pc=0x0c0a90a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a90a6;
P_0c0a90a6: /* original e038, guest PC 0x0c0a90a6 */
if(!s->budget--) { s->failed_pc=0x0c0a90a6u; return 0; }
r[0]=0x00000038u;
goto P_0c0a90a8;
P_0c0a90a8: /* original 52dc, guest PC 0x0c0a90a8 */
if(!s->budget--) { s->failed_pc=0x0c0a90a8u; return 0; }
r[2]=read(ram,r[13]+48,4);
goto P_0c0a90aa;
P_0c0a90aa: /* original 56db, guest PC 0x0c0a90aa */
if(!s->budget--) { s->failed_pc=0x0c0a90aau; return 0; }
r[6]=read(ram,r[13]+44,4);
goto P_0c0a90ac;
P_0c0a90ac: /* original 55d4, guest PC 0x0c0a90ac */
if(!s->budget--) { s->failed_pc=0x0c0a90acu; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0a90ae;
P_0c0a90ae: /* original 57d7, guest PC 0x0c0a90ae */
if(!s->budget--) { s->failed_pc=0x0c0a90aeu; return 0; }
r[7]=read(ram,r[13]+28,4);
goto P_0c0a90b0;
P_0c0a90b0: /* original 2f22, guest PC 0x0c0a90b0 */
if(!s->budget--) { s->failed_pc=0x0c0a90b0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a90b2;
P_0c0a90b2: /* original 01dc, guest PC 0x0c0a90b2 */
if(!s->budget--) { s->failed_pc=0x0c0a90b2u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a90b4;
P_0c0a90b4: /* original e014, guest PC 0x0c0a90b4 */
if(!s->budget--) { s->failed_pc=0x0c0a90b4u; return 0; }
r[0]=0x00000014u;
goto P_0c0a90b6;
P_0c0a90b6: /* original 0f14, guest PC 0x0c0a90b6 */
if(!s->budget--) { s->failed_pc=0x0c0a90b6u; return 0; }
write(ram,r[15]+r[0],r[1],1);
goto P_0c0a90b8;
P_0c0a90b8: /* original e02a, guest PC 0x0c0a90b8 */
if(!s->budget--) { s->failed_pc=0x0c0a90b8u; return 0; }
r[0]=0x0000002au;
goto P_0c0a90ba;
P_0c0a90ba: /* original 00dd, guest PC 0x0c0a90ba */
if(!s->budget--) { s->failed_pc=0x0c0a90bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a90bc;
P_0c0a90bc: /* original 81f8, guest PC 0x0c0a90bc */
if(!s->budget--) { s->failed_pc=0x0c0a90bcu; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c0a90be;
P_0c0a90be: /* original e03a, guest PC 0x0c0a90be */
if(!s->budget--) { s->failed_pc=0x0c0a90beu; return 0; }
r[0]=0x0000003au;
goto P_0c0a90c0;
P_0c0a90c0: /* original 00dc, guest PC 0x0c0a90c0 */
if(!s->budget--) { s->failed_pc=0x0c0a90c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a90c2;
P_0c0a90c2: /* original 80fc, guest PC 0x0c0a90c2 */
if(!s->budget--) { s->failed_pc=0x0c0a90c2u; return 0; }
write(ram,r[15]+12,r[0],1);
goto P_0c0a90c4;
P_0c0a90c4: /* original e010, guest PC 0x0c0a90c4 */
if(!s->budget--) { s->failed_pc=0x0c0a90c4u; return 0; }
r[0]=0x00000010u;
goto P_0c0a90c6;
P_0c0a90c6: /* original fe57, guest PC 0x0c0a90c6 */
if(!s->budget--) { s->failed_pc=0x0c0a90c6u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a90c8;
P_0c0a90c8: /* original e014, guest PC 0x0c0a90c8 */
if(!s->budget--) { s->failed_pc=0x0c0a90c8u; return 0; }
r[0]=0x00000014u;
goto P_0c0a90ca;
P_0c0a90ca: /* original fe67, guest PC 0x0c0a90ca */
if(!s->budget--) { s->failed_pc=0x0c0a90cau; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c0a90cc;
P_0c0a90cc: /* original e018, guest PC 0x0c0a90cc */
if(!s->budget--) { s->failed_pc=0x0c0a90ccu; return 0; }
r[0]=0x00000018u;
goto P_0c0a90ce;
P_0c0a90ce: /* original fe47, guest PC 0x0c0a90ce */
if(!s->budget--) { s->failed_pc=0x0c0a90ceu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a90d0;
P_0c0a90d0: /* original 85f4, guest PC 0x0c0a90d0 */
if(!s->budget--) { s->failed_pc=0x0c0a90d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c0a90d2;
P_0c0a90d2: /* original 81ef, guest PC 0x0c0a90d2 */
if(!s->budget--) { s->failed_pc=0x0c0a90d2u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0a90d4;
P_0c0a90d4: /* original e03e, guest PC 0x0c0a90d4 */
if(!s->budget--) { s->failed_pc=0x0c0a90d4u; return 0; }
r[0]=0x0000003eu;
goto P_0c0a90d6;
P_0c0a90d6: /* original 0e45, guest PC 0x0c0a90d6 */
if(!s->budget--) { s->failed_pc=0x0c0a90d6u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a90d8;
P_0c0a90d8: /* original 9060, guest PC 0x0c0a90d8 */
if(!s->budget--) { s->failed_pc=0x0c0a90d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a919cu,2);
goto P_0c0a90da;
P_0c0a90da: /* original 0e46, guest PC 0x0c0a90da */
if(!s->budget--) { s->failed_pc=0x0c0a90dau; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0a90dc;
P_0c0a90dc: /* original e048, guest PC 0x0c0a90dc */
if(!s->budget--) { s->failed_pc=0x0c0a90dcu; return 0; }
r[0]=0x00000048u;
goto P_0c0a90de;
P_0c0a90de: /* original 0e56, guest PC 0x0c0a90de */
if(!s->budget--) { s->failed_pc=0x0c0a90deu; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c0a90e0;
P_0c0a90e0: /* original 905d, guest PC 0x0c0a90e0 */
if(!s->budget--) { s->failed_pc=0x0c0a90e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a919eu,2);
goto P_0c0a90e2;
P_0c0a90e2: /* original 0e66, guest PC 0x0c0a90e2 */
if(!s->budget--) { s->failed_pc=0x0c0a90e2u; return 0; }
write(ram,r[14]+r[0],r[6],4);
goto P_0c0a90e4;
P_0c0a90e4: /* original 905c, guest PC 0x0c0a90e4 */
if(!s->budget--) { s->failed_pc=0x0c0a90e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91a0u,2);
goto P_0c0a90e6;
P_0c0a90e6: /* original 0e76, guest PC 0x0c0a90e6 */
if(!s->budget--) { s->failed_pc=0x0c0a90e6u; return 0; }
write(ram,r[14]+r[0],r[7],4);
goto P_0c0a90e8;
P_0c0a90e8: /* original 905b, guest PC 0x0c0a90e8 */
if(!s->budget--) { s->failed_pc=0x0c0a90e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91a2u,2);
goto P_0c0a90ea;
P_0c0a90ea: /* original 62f2, guest PC 0x0c0a90ea */
if(!s->budget--) { s->failed_pc=0x0c0a90eau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a90ec;
P_0c0a90ec: /* original 0e26, guest PC 0x0c0a90ec */
if(!s->budget--) { s->failed_pc=0x0c0a90ecu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0a90ee;
P_0c0a90ee: /* original e014, guest PC 0x0c0a90ee */
if(!s->budget--) { s->failed_pc=0x0c0a90eeu; return 0; }
r[0]=0x00000014u;
goto P_0c0a90f0;
P_0c0a90f0: /* original 01fc, guest PC 0x0c0a90f0 */
if(!s->budget--) { s->failed_pc=0x0c0a90f0u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c0a90f2;
P_0c0a90f2: /* original e246, guest PC 0x0c0a90f2 */
if(!s->budget--) { s->failed_pc=0x0c0a90f2u; return 0; }
r[2]=0x00000046u;
goto P_0c0a90f4;
P_0c0a90f4: /* original 9056, guest PC 0x0c0a90f4 */
if(!s->budget--) { s->failed_pc=0x0c0a90f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91a4u,2);
goto P_0c0a90f6;
P_0c0a90f6: /* original 32ec, guest PC 0x0c0a90f6 */
if(!s->budget--) { s->failed_pc=0x0c0a90f6u; return 0; }
r[2]+=r[14];
goto P_0c0a90f8;
P_0c0a90f8: /* original 0e14, guest PC 0x0c0a90f8 */
if(!s->budget--) { s->failed_pc=0x0c0a90f8u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c0a90fa;
P_0c0a90fa: /* original 85f8, guest PC 0x0c0a90fa */
if(!s->budget--) { s->failed_pc=0x0c0a90fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c0a90fc;
P_0c0a90fc: /* original 2201, guest PC 0x0c0a90fc */
if(!s->budget--) { s->failed_pc=0x0c0a90fcu; return 0; }
write(ram,r[2],r[0],2);
goto P_0c0a90fe;
P_0c0a90fe: /* original 9152, guest PC 0x0c0a90fe */
if(!s->budget--) { s->failed_pc=0x0c0a90feu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91a6u,2);
goto P_0c0a9100;
P_0c0a9100: /* original 84fc, guest PC 0x0c0a9100 */
if(!s->budget--) { s->failed_pc=0x0c0a9100u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+12,1);
goto P_0c0a9102;
P_0c0a9102: /* original 31bc, guest PC 0x0c0a9102 */
if(!s->budget--) { s->failed_pc=0x0c0a9102u; return 0; }
r[1]+=r[11];
goto P_0c0a9104;
P_0c0a9104: /* original 2100, guest PC 0x0c0a9104 */
if(!s->budget--) { s->failed_pc=0x0c0a9104u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0a9106;
P_0c0a9106: /* original e061, guest PC 0x0c0a9106 */
if(!s->budget--) { s->failed_pc=0x0c0a9106u; return 0; }
r[0]=0x00000061u;
goto P_0c0a9108;
P_0c0a9108: /* original 04ec, guest PC 0x0c0a9108 */
if(!s->budget--) { s->failed_pc=0x0c0a9108u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a910a;
P_0c0a910a: /* original 604e, guest PC 0x0c0a910a */
if(!s->budget--) { s->failed_pc=0x0c0a910au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0a910c;
P_0c0a910c: /* original 8808, guest PC 0x0c0a910c */
if(!s->budget--) { s->failed_pc=0x0c0a910cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0a910e;
P_0c0a910e: /* original 8b03, guest PC 0x0c0a910e */
if(!s->budget--) { s->failed_pc=0x0c0a910eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9118; }
goto P_0c0a9110;
P_0c0a9110: /* original e039, guest PC 0x0c0a9110 */
if(!s->budget--) { s->failed_pc=0x0c0a9110u; return 0; }
r[0]=0x00000039u;
goto P_0c0a9112;
P_0c0a9112: /* original 04dc, guest PC 0x0c0a9112 */
if(!s->budget--) { s->failed_pc=0x0c0a9112u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a9114;
P_0c0a9114: /* original 9048, guest PC 0x0c0a9114 */
if(!s->budget--) { s->failed_pc=0x0c0a9114u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91a8u,2);
goto P_0c0a9116;
P_0c0a9116: /* original 0e44, guest PC 0x0c0a9116 */
if(!s->budget--) { s->failed_pc=0x0c0a9116u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a9118;
P_0c0a9118: /* original 54d5, guest PC 0x0c0a9118 */
if(!s->budget--) { s->failed_pc=0x0c0a9118u; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c0a911a;
P_0c0a911a: /* original 2448, guest PC 0x0c0a911a */
if(!s->budget--) { s->failed_pc=0x0c0a911au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a911c;
P_0c0a911c: /* original 8902, guest PC 0x0c0a911c */
if(!s->budget--) { s->failed_pc=0x0c0a911cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9124; }
goto P_0c0a911e;
P_0c0a911e: /* original d224, guest PC 0x0c0a911e */
if(!s->budget--) { s->failed_pc=0x0c0a911eu; return 0; }
r[2]=read(ram,0x0c0a91b0u,4);
goto P_0c0a9120;
P_0c0a9120: /* original 420b, guest PC 0x0c0a9120 */
if(!s->budget--) { s->failed_pc=0x0c0a9120u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a9124u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9124u) { target=s->pc; goto dispatch; }
goto P_0c0a9124;
P_0c0a9122: /* original 0009, guest PC 0x0c0a9122 */
if(!s->budget--) { s->failed_pc=0x0c0a9122u; return 0; }
goto P_0c0a9124;
P_0c0a9124: /* original 54d6, guest PC 0x0c0a9124 */
if(!s->budget--) { s->failed_pc=0x0c0a9124u; return 0; }
r[4]=read(ram,r[13]+24,4);
goto P_0c0a9126;
P_0c0a9126: /* original 2448, guest PC 0x0c0a9126 */
if(!s->budget--) { s->failed_pc=0x0c0a9126u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a9128;
P_0c0a9128: /* original 8902, guest PC 0x0c0a9128 */
if(!s->budget--) { s->failed_pc=0x0c0a9128u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9130; }
goto P_0c0a912a;
P_0c0a912a: /* original d221, guest PC 0x0c0a912a */
if(!s->budget--) { s->failed_pc=0x0c0a912au; return 0; }
r[2]=read(ram,0x0c0a91b0u,4);
goto P_0c0a912c;
P_0c0a912c: /* original 420b, guest PC 0x0c0a912c */
if(!s->budget--) { s->failed_pc=0x0c0a912cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a9130u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9130u) { target=s->pc; goto dispatch; }
goto P_0c0a9130;
P_0c0a912e: /* original 0009, guest PC 0x0c0a912e */
if(!s->budget--) { s->failed_pc=0x0c0a912eu; return 0; }
goto P_0c0a9130;
P_0c0a9130: /* original e03c, guest PC 0x0c0a9130 */
if(!s->budget--) { s->failed_pc=0x0c0a9130u; return 0; }
r[0]=0x0000003cu;
goto P_0c0a9132;
P_0c0a9132: /* original 06ed, guest PC 0x0c0a9132 */
if(!s->budget--) { s->failed_pc=0x0c0a9132u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9134;
P_0c0a9134: /* original e022, guest PC 0x0c0a9134 */
if(!s->budget--) { s->failed_pc=0x0c0a9134u; return 0; }
r[0]=0x00000022u;
goto P_0c0a9136;
P_0c0a9136: /* original 04dd, guest PC 0x0c0a9136 */
if(!s->budget--) { s->failed_pc=0x0c0a9136u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a9138;
P_0c0a9138: /* original e03c, guest PC 0x0c0a9138 */
if(!s->budget--) { s->failed_pc=0x0c0a9138u; return 0; }
r[0]=0x0000003cu;
goto P_0c0a913a;
P_0c0a913a: /* original 654f, guest PC 0x0c0a913a */
if(!s->budget--) { s->failed_pc=0x0c0a913au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0a913c;
P_0c0a913c: /* original 2558, guest PC 0x0c0a913c */
if(!s->budget--) { s->failed_pc=0x0c0a913cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0a913e;
P_0c0a913e: /* original 8d45, guest PC 0x0c0a913e */
if(!s->budget--) { s->failed_pc=0x0c0a913eu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],2);
if(cond) { goto P_0c0a91cc; }
goto P_0c0a9142;
P_0c0a9140: /* original 0e45, guest PC 0x0c0a9140 */
if(!s->budget--) { s->failed_pc=0x0c0a9140u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9142;
P_0c0a9142: /* original 666f, guest PC 0x0c0a9142 */
if(!s->budget--) { s->failed_pc=0x0c0a9142u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c0a9144;
P_0c0a9144: /* original 3560, guest PC 0x0c0a9144 */
if(!s->budget--) { s->failed_pc=0x0c0a9144u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c0a9146;
P_0c0a9146: /* original 8b19, guest PC 0x0c0a9146 */
if(!s->budget--) { s->failed_pc=0x0c0a9146u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a917c; }
goto P_0c0a9148;
P_0c0a9148: /* original 902f, guest PC 0x0c0a9148 */
if(!s->budget--) { s->failed_pc=0x0c0a9148u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91aau,2);
goto P_0c0a914a;
P_0c0a914a: /* original 7cfd, guest PC 0x0c0a914a */
if(!s->budget--) { s->failed_pc=0x0c0a914au; return 0; }
r[12]+=0xfffffffdu;
goto P_0c0a914c;
P_0c0a914c: /* original 63c3, guest PC 0x0c0a914c */
if(!s->budget--) { s->failed_pc=0x0c0a914cu; return 0; }
r[3]=r[12];
goto P_0c0a914e;
P_0c0a914e: /* original e503, guest PC 0x0c0a914e */
if(!s->budget--) { s->failed_pc=0x0c0a914eu; return 0; }
r[5]=0x00000003u;
goto P_0c0a9150;
P_0c0a9150: /* original 04bc, guest PC 0x0c0a9150 */
if(!s->budget--) { s->failed_pc=0x0c0a9150u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0a9152;
P_0c0a9152: /* original 3353, guest PC 0x0c0a9152 */
if(!s->budget--) { s->failed_pc=0x0c0a9152u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[5])!=0);
goto P_0c0a9154;
P_0c0a9154: /* original 8d03, guest PC 0x0c0a9154 */
if(!s->budget--) { s->failed_pc=0x0c0a9154u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[12],4);
if(cond) { goto P_0c0a915e; }
goto P_0c0a9158;
P_0c0a9156: /* original 2fc2, guest PC 0x0c0a9156 */
if(!s->budget--) { s->failed_pc=0x0c0a9156u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c0a9158;
P_0c0a9158: /* original 9027, guest PC 0x0c0a9158 */
if(!s->budget--) { s->failed_pc=0x0c0a9158u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91aau,2);
goto P_0c0a915a;
P_0c0a915a: /* original 7401, guest PC 0x0c0a915a */
if(!s->budget--) { s->failed_pc=0x0c0a915au; return 0; }
r[4]+=0x00000001u;
goto P_0c0a915c;
P_0c0a915c: /* original 0b44, guest PC 0x0c0a915c */
if(!s->budget--) { s->failed_pc=0x0c0a915cu; return 0; }
write(ram,r[11]+r[0],r[4],1);
goto P_0c0a915e;
P_0c0a915e: /* original 63f2, guest PC 0x0c0a915e */
if(!s->budget--) { s->failed_pc=0x0c0a915eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a9160;
P_0c0a9160: /* original 3353, guest PC 0x0c0a9160 */
if(!s->budget--) { s->failed_pc=0x0c0a9160u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[5])!=0);
goto P_0c0a9162;
P_0c0a9162: /* original 8903, guest PC 0x0c0a9162 */
if(!s->budget--) { s->failed_pc=0x0c0a9162u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a916c; }
goto P_0c0a9164;
P_0c0a9164: /* original 9022, guest PC 0x0c0a9164 */
if(!s->budget--) { s->failed_pc=0x0c0a9164u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91acu,2);
goto P_0c0a9166;
P_0c0a9166: /* original e101, guest PC 0x0c0a9166 */
if(!s->budget--) { s->failed_pc=0x0c0a9166u; return 0; }
r[1]=0x00000001u;
goto P_0c0a9168;
P_0c0a9168: /* original a008, guest PC 0x0c0a9168 */
if(!s->budget--) { s->failed_pc=0x0c0a9168u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c0a917c;
P_0c0a916a: /* original 0e14, guest PC 0x0c0a916a */
if(!s->budget--) { s->failed_pc=0x0c0a916au; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c0a916c;
P_0c0a916c: /* original e03e, guest PC 0x0c0a916c */
if(!s->budget--) { s->failed_pc=0x0c0a916cu; return 0; }
r[0]=0x0000003eu;
goto P_0c0a916e;
P_0c0a916e: /* original 04ed, guest PC 0x0c0a916e */
if(!s->budget--) { s->failed_pc=0x0c0a916eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9170;
P_0c0a9170: /* original 604d, guest PC 0x0c0a9170 */
if(!s->budget--) { s->failed_pc=0x0c0a9170u; return 0; }
r[0]=r[4]&65535u;
goto P_0c0a9172;
P_0c0a9172: /* original 8801, guest PC 0x0c0a9172 */
if(!s->budget--) { s->failed_pc=0x0c0a9172u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a9174;
P_0c0a9174: /* original 8d0d, guest PC 0x0c0a9174 */
if(!s->budget--) { s->failed_pc=0x0c0a9174u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0a9192; }
goto P_0c0a9178;
P_0c0a9176: /* original 6403, guest PC 0x0c0a9176 */
if(!s->budget--) { s->failed_pc=0x0c0a9176u; return 0; }
r[4]=r[0];
goto P_0c0a9178;
P_0c0a9178: /* original a022, guest PC 0x0c0a9178 */
if(!s->budget--) { s->failed_pc=0x0c0a9178u; return 0; }
goto P_0c0a91c0;
P_0c0a917a: /* original 0009, guest PC 0x0c0a917a */
if(!s->budget--) { s->failed_pc=0x0c0a917au; return 0; }
goto P_0c0a917c;
P_0c0a917c: /* original e03c, guest PC 0x0c0a917c */
if(!s->budget--) { s->failed_pc=0x0c0a917cu; return 0; }
r[0]=0x0000003cu;
goto P_0c0a917e;
P_0c0a917e: /* original 02ed, guest PC 0x0c0a917e */
if(!s->budget--) { s->failed_pc=0x0c0a917eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9180;
P_0c0a9180: /* original 2f21, guest PC 0x0c0a9180 */
if(!s->budget--) { s->failed_pc=0x0c0a9180u; return 0; }
write(ram,r[15],r[2],2);
goto P_0c0a9182;
P_0c0a9182: /* original 55f1, guest PC 0x0c0a9182 */
if(!s->budget--) { s->failed_pc=0x0c0a9182u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0a9184;
P_0c0a9184: /* original 66f1, guest PC 0x0c0a9184 */
if(!s->budget--) { s->failed_pc=0x0c0a9184u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[6]=tmp;
goto P_0c0a9186;
P_0c0a9186: /* original d30b, guest PC 0x0c0a9186 */
if(!s->budget--) { s->failed_pc=0x0c0a9186u; return 0; }
r[3]=read(ram,0x0c0a91b4u,4);
goto P_0c0a9188;
P_0c0a9188: /* original 430b, guest PC 0x0c0a9188 */
if(!s->budget--) { s->failed_pc=0x0c0a9188u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a918cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a918cu) { target=s->pc; goto dispatch; }
goto P_0c0a918c;
P_0c0a918a: /* original 64e3, guest PC 0x0c0a918a */
if(!s->budget--) { s->failed_pc=0x0c0a918au; return 0; }
r[4]=r[14];
goto P_0c0a918c;
P_0c0a918c: /* original d20a, guest PC 0x0c0a918c */
if(!s->budget--) { s->failed_pc=0x0c0a918cu; return 0; }
r[2]=read(ram,0x0c0a91b8u,4);
goto P_0c0a918e;
P_0c0a918e: /* original 420b, guest PC 0x0c0a918e */
if(!s->budget--) { s->failed_pc=0x0c0a918eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a9192u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9192u) { target=s->pc; goto dispatch; }
goto P_0c0a9192;
P_0c0a9190: /* original 64e3, guest PC 0x0c0a9190 */
if(!s->budget--) { s->failed_pc=0x0c0a9190u; return 0; }
r[4]=r[14];
goto P_0c0a9192;
P_0c0a9192: /* original d30a, guest PC 0x0c0a9192 */
if(!s->budget--) { s->failed_pc=0x0c0a9192u; return 0; }
r[3]=read(ram,0x0c0a91bcu,4);
goto P_0c0a9194;
P_0c0a9194: /* original 430b, guest PC 0x0c0a9194 */
if(!s->budget--) { s->failed_pc=0x0c0a9194u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9198u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9198u) { target=s->pc; goto dispatch; }
goto P_0c0a9198;
P_0c0a9196: /* original 64e3, guest PC 0x0c0a9196 */
if(!s->budget--) { s->failed_pc=0x0c0a9196u; return 0; }
r[4]=r[14];
goto P_0c0a9198;
P_0c0a9198: /* original a015, guest PC 0x0c0a9198 */
if(!s->budget--) { s->failed_pc=0x0c0a9198u; return 0; }
goto P_0c0a91c6;
P_0c0a919a: /* original 0009, guest PC 0x0c0a919a */
if(!s->budget--) { s->failed_pc=0x0c0a919au; return 0; }
if(!vf3_matrix_family(0x0c0a919cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a919cu; return 0; } return 1;
P_0c0a91c0: /* original d335, guest PC 0x0c0a91c0 */
if(!s->budget--) { s->failed_pc=0x0c0a91c0u; return 0; }
r[3]=read(ram,0x0c0a9298u,4);
goto P_0c0a91c2;
P_0c0a91c2: /* original 430b, guest PC 0x0c0a91c2 */
if(!s->budget--) { s->failed_pc=0x0c0a91c2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a91c6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a91c6u) { target=s->pc; goto dispatch; }
goto P_0c0a91c6;
P_0c0a91c4: /* original 64e3, guest PC 0x0c0a91c4 */
if(!s->budget--) { s->failed_pc=0x0c0a91c4u; return 0; }
r[4]=r[14];
goto P_0c0a91c6;
P_0c0a91c6: /* original d235, guest PC 0x0c0a91c6 */
if(!s->budget--) { s->failed_pc=0x0c0a91c6u; return 0; }
r[2]=read(ram,0x0c0a929cu,4);
goto P_0c0a91c8;
P_0c0a91c8: /* original 420b, guest PC 0x0c0a91c8 */
if(!s->budget--) { s->failed_pc=0x0c0a91c8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a91ccu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a91ccu) { target=s->pc; goto dispatch; }
goto P_0c0a91cc;
P_0c0a91ca: /* original 64e3, guest PC 0x0c0a91ca */
if(!s->budget--) { s->failed_pc=0x0c0a91cau; return 0; }
r[4]=r[14];
goto P_0c0a91cc;
P_0c0a91cc: /* original 7f18, guest PC 0x0c0a91cc */
if(!s->budget--) { s->failed_pc=0x0c0a91ccu; return 0; }
r[15]+=0x00000018u;
goto P_0c0a91ce;
P_0c0a91ce: /* original 4f26, guest PC 0x0c0a91ce */
if(!s->budget--) { s->failed_pc=0x0c0a91ceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a91d0;
P_0c0a91d0: /* original 6bf6, guest PC 0x0c0a91d0 */
if(!s->budget--) { s->failed_pc=0x0c0a91d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a91d2;
P_0c0a91d2: /* original 6cf6, guest PC 0x0c0a91d2 */
if(!s->budget--) { s->failed_pc=0x0c0a91d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a91d4;
P_0c0a91d4: /* original 6df6, guest PC 0x0c0a91d4 */
if(!s->budget--) { s->failed_pc=0x0c0a91d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a91d6;
P_0c0a91d6: /* original 000b, guest PC 0x0c0a91d6 */
if(!s->budget--) { s->failed_pc=0x0c0a91d6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a91d8: /* original 6ef6, guest PC 0x0c0a91d8 */
if(!s->budget--) { s->failed_pc=0x0c0a91d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a91dau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a91dau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
