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
int vf3_away_batch127_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a0f28u: goto P_0c0a0f28;
case 0x0c0a0f2au: goto P_0c0a0f2a;
case 0x0c0a0f2cu: goto P_0c0a0f2c;
case 0x0c0a0f2eu: goto P_0c0a0f2e;
case 0x0c0a0f30u: goto P_0c0a0f30;
case 0x0c0a0f32u: goto P_0c0a0f32;
case 0x0c0a0f34u: goto P_0c0a0f34;
case 0x0c0a0f36u: goto P_0c0a0f36;
case 0x0c0a0f38u: goto P_0c0a0f38;
case 0x0c0a0f3au: goto P_0c0a0f3a;
case 0x0c0a0f3cu: goto P_0c0a0f3c;
case 0x0c0a0f3eu: goto P_0c0a0f3e;
case 0x0c0a0f40u: goto P_0c0a0f40;
case 0x0c0a0f42u: goto P_0c0a0f42;
case 0x0c0a0f44u: goto P_0c0a0f44;
case 0x0c0a0f46u: goto P_0c0a0f46;
case 0x0c0a0f48u: goto P_0c0a0f48;
case 0x0c0a0f4au: goto P_0c0a0f4a;
case 0x0c0a0f4cu: goto P_0c0a0f4c;
case 0x0c0a0f4eu: goto P_0c0a0f4e;
case 0x0c0a0f50u: goto P_0c0a0f50;
case 0x0c0a0f52u: goto P_0c0a0f52;
case 0x0c0a0f54u: goto P_0c0a0f54;
case 0x0c0a0f56u: goto P_0c0a0f56;
case 0x0c0a0f58u: goto P_0c0a0f58;
case 0x0c0a0f5au: goto P_0c0a0f5a;
case 0x0c0a0f5cu: goto P_0c0a0f5c;
case 0x0c0a0f5eu: goto P_0c0a0f5e;
case 0x0c0a0f60u: goto P_0c0a0f60;
case 0x0c0a0f62u: goto P_0c0a0f62;
case 0x0c0a0f64u: goto P_0c0a0f64;
case 0x0c0a0f66u: goto P_0c0a0f66;
case 0x0c0a0f68u: goto P_0c0a0f68;
case 0x0c0a0f6au: goto P_0c0a0f6a;
case 0x0c0a0f6cu: goto P_0c0a0f6c;
case 0x0c0a0f6eu: goto P_0c0a0f6e;
case 0x0c0a0f70u: goto P_0c0a0f70;
case 0x0c0a0f72u: goto P_0c0a0f72;
case 0x0c0a0f74u: goto P_0c0a0f74;
case 0x0c0a0f76u: goto P_0c0a0f76;
case 0x0c0a0f78u: goto P_0c0a0f78;
case 0x0c0a0f7au: goto P_0c0a0f7a;
case 0x0c0a0f7cu: goto P_0c0a0f7c;
case 0x0c0a0f7eu: goto P_0c0a0f7e;
case 0x0c0a0f80u: goto P_0c0a0f80;
case 0x0c0a0f82u: goto P_0c0a0f82;
case 0x0c0a0f84u: goto P_0c0a0f84;
case 0x0c0a0f86u: goto P_0c0a0f86;
case 0x0c0a0f88u: goto P_0c0a0f88;
case 0x0c0a0f8au: goto P_0c0a0f8a;
case 0x0c0a0f8cu: goto P_0c0a0f8c;
case 0x0c0a0f8eu: goto P_0c0a0f8e;
case 0x0c0a0f90u: goto P_0c0a0f90;
case 0x0c0a0f92u: goto P_0c0a0f92;
case 0x0c0a0f94u: goto P_0c0a0f94;
case 0x0c0a0f96u: goto P_0c0a0f96;
case 0x0c0a0f98u: goto P_0c0a0f98;
case 0x0c0a0f9au: goto P_0c0a0f9a;
case 0x0c0a0f9cu: goto P_0c0a0f9c;
case 0x0c0a0f9eu: goto P_0c0a0f9e;
case 0x0c0a0fc4u: goto P_0c0a0fc4;
case 0x0c0a0fc6u: goto P_0c0a0fc6;
case 0x0c0a0fc8u: goto P_0c0a0fc8;
case 0x0c0a0fcau: goto P_0c0a0fca;
case 0x0c0a0fccu: goto P_0c0a0fcc;
case 0x0c0a0fceu: goto P_0c0a0fce;
case 0x0c0a0fd0u: goto P_0c0a0fd0;
case 0x0c0a0fd2u: goto P_0c0a0fd2;
case 0x0c0a0fd4u: goto P_0c0a0fd4;
case 0x0c0a0fd6u: goto P_0c0a0fd6;
case 0x0c0a0fd8u: goto P_0c0a0fd8;
case 0x0c0a0fdau: goto P_0c0a0fda;
case 0x0c0a0fdcu: goto P_0c0a0fdc;
case 0x0c0a0fdeu: goto P_0c0a0fde;
case 0x0c0a0fe0u: goto P_0c0a0fe0;
case 0x0c0a0fe2u: goto P_0c0a0fe2;
case 0x0c0a0fe4u: goto P_0c0a0fe4;
case 0x0c0a0fe6u: goto P_0c0a0fe6;
case 0x0c0a0fe8u: goto P_0c0a0fe8;
case 0x0c0a0feau: goto P_0c0a0fea;
case 0x0c0a0fecu: goto P_0c0a0fec;
case 0x0c0a0feeu: goto P_0c0a0fee;
case 0x0c0a0ff0u: goto P_0c0a0ff0;
case 0x0c0a0ff2u: goto P_0c0a0ff2;
case 0x0c0a0ff4u: goto P_0c0a0ff4;
case 0x0c0a0ff6u: goto P_0c0a0ff6;
case 0x0c0a0ff8u: goto P_0c0a0ff8;
case 0x0c0a0ffau: goto P_0c0a0ffa;
case 0x0c0a0ffcu: goto P_0c0a0ffc;
case 0x0c0a0ffeu: goto P_0c0a0ffe;
case 0x0c0a1000u: goto P_0c0a1000;
case 0x0c0a1002u: goto P_0c0a1002;
case 0x0c0a1004u: goto P_0c0a1004;
case 0x0c0a1006u: goto P_0c0a1006;
case 0x0c0a1008u: goto P_0c0a1008;
case 0x0c0a100au: goto P_0c0a100a;
case 0x0c0a100cu: goto P_0c0a100c;
case 0x0c0a100eu: goto P_0c0a100e;
case 0x0c0a1010u: goto P_0c0a1010;
case 0x0c0a1012u: goto P_0c0a1012;
case 0x0c0a1014u: goto P_0c0a1014;
case 0x0c0a1016u: goto P_0c0a1016;
case 0x0c0a1018u: goto P_0c0a1018;
case 0x0c0a101au: goto P_0c0a101a;
case 0x0c0a101cu: goto P_0c0a101c;
case 0x0c0a101eu: goto P_0c0a101e;
case 0x0c0a1020u: goto P_0c0a1020;
case 0x0c0a1022u: goto P_0c0a1022;
case 0x0c0a1024u: goto P_0c0a1024;
case 0x0c0a1026u: goto P_0c0a1026;
case 0x0c0a1028u: goto P_0c0a1028;
case 0x0c0a102au: goto P_0c0a102a;
case 0x0c0a102cu: goto P_0c0a102c;
case 0x0c0a102eu: goto P_0c0a102e;
case 0x0c0a1030u: goto P_0c0a1030;
case 0x0c0a1032u: goto P_0c0a1032;
case 0x0c0a1034u: goto P_0c0a1034;
case 0x0c0a1036u: goto P_0c0a1036;
case 0x0c0a1038u: goto P_0c0a1038;
case 0x0c0a103au: goto P_0c0a103a;
case 0x0c0a103cu: goto P_0c0a103c;
case 0x0c0a103eu: goto P_0c0a103e;
case 0x0c0a1040u: goto P_0c0a1040;
case 0x0c0a1042u: goto P_0c0a1042;
case 0x0c0a1044u: goto P_0c0a1044;
case 0x0c0a1046u: goto P_0c0a1046;
case 0x0c0a1048u: goto P_0c0a1048;
case 0x0c0a104au: goto P_0c0a104a;
case 0x0c0a104cu: goto P_0c0a104c;
case 0x0c0a104eu: goto P_0c0a104e;
case 0x0c0a1050u: goto P_0c0a1050;
case 0x0c0a1052u: goto P_0c0a1052;
case 0x0c0a1054u: goto P_0c0a1054;
case 0x0c0a1056u: goto P_0c0a1056;
case 0x0c0a1058u: goto P_0c0a1058;
case 0x0c0a105au: goto P_0c0a105a;
case 0x0c0a105cu: goto P_0c0a105c;
case 0x0c0a105eu: goto P_0c0a105e;
case 0x0c0a1060u: goto P_0c0a1060;
case 0x0c0a1062u: goto P_0c0a1062;
case 0x0c0a1064u: goto P_0c0a1064;
case 0x0c0a1066u: goto P_0c0a1066;
case 0x0c0a1068u: goto P_0c0a1068;
case 0x0c0a106au: goto P_0c0a106a;
case 0x0c0a106cu: goto P_0c0a106c;
case 0x0c0a106eu: goto P_0c0a106e;
case 0x0c0a1070u: goto P_0c0a1070;
case 0x0c0a1072u: goto P_0c0a1072;
case 0x0c0a1074u: goto P_0c0a1074;
case 0x0c0a1076u: goto P_0c0a1076;
case 0x0c0a1078u: goto P_0c0a1078;
case 0x0c0a10acu: goto P_0c0a10ac;
case 0x0c0a10aeu: goto P_0c0a10ae;
case 0x0c0a10b0u: goto P_0c0a10b0;
case 0x0c0a10b2u: goto P_0c0a10b2;
case 0x0c0a10b4u: goto P_0c0a10b4;
case 0x0c0a10b6u: goto P_0c0a10b6;
case 0x0c0a10b8u: goto P_0c0a10b8;
case 0x0c0a10bau: goto P_0c0a10ba;
case 0x0c0a10bcu: goto P_0c0a10bc;
case 0x0c0a10beu: goto P_0c0a10be;
case 0x0c0a10c0u: goto P_0c0a10c0;
case 0x0c0a10c2u: goto P_0c0a10c2;
case 0x0c0a10c4u: goto P_0c0a10c4;
case 0x0c0a10c6u: goto P_0c0a10c6;
case 0x0c0a10c8u: goto P_0c0a10c8;
case 0x0c0a10cau: goto P_0c0a10ca;
case 0x0c0a10ccu: goto P_0c0a10cc;
case 0x0c0a10ceu: goto P_0c0a10ce;
case 0x0c0a10d0u: goto P_0c0a10d0;
case 0x0c0a10d2u: goto P_0c0a10d2;
case 0x0c0a10d4u: goto P_0c0a10d4;
case 0x0c0a10d6u: goto P_0c0a10d6;
case 0x0c0a10d8u: goto P_0c0a10d8;
case 0x0c0a10dau: goto P_0c0a10da;
case 0x0c0a10dcu: goto P_0c0a10dc;
case 0x0c0a10deu: goto P_0c0a10de;
case 0x0c0a10e0u: goto P_0c0a10e0;
case 0x0c0a10e2u: goto P_0c0a10e2;
case 0x0c0a10e4u: goto P_0c0a10e4;
case 0x0c0a10e6u: goto P_0c0a10e6;
case 0x0c0a10e8u: goto P_0c0a10e8;
case 0x0c0a10eau: goto P_0c0a10ea;
case 0x0c0a10ecu: goto P_0c0a10ec;
case 0x0c0a10eeu: goto P_0c0a10ee;
case 0x0c0a10f0u: goto P_0c0a10f0;
case 0x0c0a10f2u: goto P_0c0a10f2;
case 0x0c0a10f4u: goto P_0c0a10f4;
case 0x0c0a10f6u: goto P_0c0a10f6;
case 0x0c0a10f8u: goto P_0c0a10f8;
case 0x0c0a10fau: goto P_0c0a10fa;
case 0x0c0a10fcu: goto P_0c0a10fc;
case 0x0c0a10feu: goto P_0c0a10fe;
case 0x0c0a1100u: goto P_0c0a1100;
case 0x0c0a1102u: goto P_0c0a1102;
case 0x0c0a1104u: goto P_0c0a1104;
case 0x0c0a1106u: goto P_0c0a1106;
case 0x0c0a1108u: goto P_0c0a1108;
case 0x0c0a110au: goto P_0c0a110a;
case 0x0c0a110cu: goto P_0c0a110c;
case 0x0c0a110eu: goto P_0c0a110e;
case 0x0c0a1110u: goto P_0c0a1110;
case 0x0c0a1112u: goto P_0c0a1112;
case 0x0c0a1114u: goto P_0c0a1114;
case 0x0c0a1116u: goto P_0c0a1116;
case 0x0c0a1118u: goto P_0c0a1118;
case 0x0c0a111au: goto P_0c0a111a;
case 0x0c0a111cu: goto P_0c0a111c;
case 0x0c0a111eu: goto P_0c0a111e;
case 0x0c0a1120u: goto P_0c0a1120;
case 0x0c0a1122u: goto P_0c0a1122;
case 0x0c0a1124u: goto P_0c0a1124;
case 0x0c0a1126u: goto P_0c0a1126;
case 0x0c0a1128u: goto P_0c0a1128;
case 0x0c0a112au: goto P_0c0a112a;
case 0x0c0a112cu: goto P_0c0a112c;
case 0x0c0a112eu: goto P_0c0a112e;
case 0x0c0a1130u: goto P_0c0a1130;
case 0x0c0a1132u: goto P_0c0a1132;
case 0x0c0a1134u: goto P_0c0a1134;
case 0x0c0a1136u: goto P_0c0a1136;
case 0x0c0a1138u: goto P_0c0a1138;
case 0x0c0a113au: goto P_0c0a113a;
case 0x0c0a113cu: goto P_0c0a113c;
case 0x0c0a113eu: goto P_0c0a113e;
case 0x0c0a1140u: goto P_0c0a1140;
case 0x0c0a1142u: goto P_0c0a1142;
case 0x0c0a1144u: goto P_0c0a1144;
case 0x0c0a1146u: goto P_0c0a1146;
case 0x0c0a1148u: goto P_0c0a1148;
case 0x0c0a114au: goto P_0c0a114a;
case 0x0c0a114cu: goto P_0c0a114c;
case 0x0c0a114eu: goto P_0c0a114e;
case 0x0c0a1150u: goto P_0c0a1150;
case 0x0c0a1152u: goto P_0c0a1152;
case 0x0c0a1154u: goto P_0c0a1154;
case 0x0c0a1156u: goto P_0c0a1156;
case 0x0c0a1158u: goto P_0c0a1158;
case 0x0c0a115au: goto P_0c0a115a;
case 0x0c0a115cu: goto P_0c0a115c;
case 0x0c0a115eu: goto P_0c0a115e;
case 0x0c0a1160u: goto P_0c0a1160;
case 0x0c0a1162u: goto P_0c0a1162;
case 0x0c0a1164u: goto P_0c0a1164;
case 0x0c0a1166u: goto P_0c0a1166;
case 0x0c0a1168u: goto P_0c0a1168;
case 0x0c0a116au: goto P_0c0a116a;
case 0x0c0a116cu: goto P_0c0a116c;
case 0x0c0a116eu: goto P_0c0a116e;
case 0x0c0a1170u: goto P_0c0a1170;
case 0x0c0a1172u: goto P_0c0a1172;
case 0x0c0a1174u: goto P_0c0a1174;
case 0x0c0a1176u: goto P_0c0a1176;
case 0x0c0a1178u: goto P_0c0a1178;
case 0x0c0a117au: goto P_0c0a117a;
case 0x0c0a117cu: goto P_0c0a117c;
case 0x0c0a117eu: goto P_0c0a117e;
case 0x0c0a11acu: goto P_0c0a11ac;
case 0x0c0a11aeu: goto P_0c0a11ae;
case 0x0c0a11b0u: goto P_0c0a11b0;
case 0x0c0a11b2u: goto P_0c0a11b2;
case 0x0c0a11b4u: goto P_0c0a11b4;
case 0x0c0a11b6u: goto P_0c0a11b6;
case 0x0c0a11b8u: goto P_0c0a11b8;
case 0x0c0a11bau: goto P_0c0a11ba;
case 0x0c0a11bcu: goto P_0c0a11bc;
case 0x0c0a11beu: goto P_0c0a11be;
case 0x0c0a11c0u: goto P_0c0a11c0;
case 0x0c0a11c2u: goto P_0c0a11c2;
case 0x0c0a11c4u: goto P_0c0a11c4;
case 0x0c0a11c6u: goto P_0c0a11c6;
case 0x0c0a11c8u: goto P_0c0a11c8;
case 0x0c0a11cau: goto P_0c0a11ca;
case 0x0c0a11ccu: goto P_0c0a11cc;
case 0x0c0a11ceu: goto P_0c0a11ce;
case 0x0c0a11d0u: goto P_0c0a11d0;
case 0x0c0a11d2u: goto P_0c0a11d2;
case 0x0c0a11d4u: goto P_0c0a11d4;
case 0x0c0a11d6u: goto P_0c0a11d6;
case 0x0c0a11d8u: goto P_0c0a11d8;
case 0x0c0a11dau: goto P_0c0a11da;
case 0x0c0a11dcu: goto P_0c0a11dc;
case 0x0c0a11deu: goto P_0c0a11de;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a0f28: /* original 2fe6, guest PC 0x0c0a0f28 */
if(!s->budget--) { s->failed_pc=0x0c0a0f28u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0f2a;
P_0c0a0f2a: /* original 2fd6, guest PC 0x0c0a0f2a */
if(!s->budget--) { s->failed_pc=0x0c0a0f2au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0f2c;
P_0c0a0f2c: /* original 2fc6, guest PC 0x0c0a0f2c */
if(!s->budget--) { s->failed_pc=0x0c0a0f2cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0f2e;
P_0c0a0f2e: /* original 2fb6, guest PC 0x0c0a0f2e */
if(!s->budget--) { s->failed_pc=0x0c0a0f2eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0f30;
P_0c0a0f30: /* original 2fa6, guest PC 0x0c0a0f30 */
if(!s->budget--) { s->failed_pc=0x0c0a0f30u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0f32;
P_0c0a0f32: /* original 2f96, guest PC 0x0c0a0f32 */
if(!s->budget--) { s->failed_pc=0x0c0a0f32u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0f34;
P_0c0a0f34: /* original 2f86, guest PC 0x0c0a0f34 */
if(!s->budget--) { s->failed_pc=0x0c0a0f34u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0f36;
P_0c0a0f36: /* original fffb, guest PC 0x0c0a0f36 */
if(!s->budget--) { s->failed_pc=0x0c0a0f36u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0a0f38;
P_0c0a0f38: /* original ffeb, guest PC 0x0c0a0f38 */
if(!s->budget--) { s->failed_pc=0x0c0a0f38u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0a0f3a;
P_0c0a0f3a: /* original 4f22, guest PC 0x0c0a0f3a */
if(!s->budget--) { s->failed_pc=0x0c0a0f3au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a0f3c;
P_0c0a0f3c: /* original d11c, guest PC 0x0c0a0f3c */
if(!s->budget--) { s->failed_pc=0x0c0a0f3cu; return 0; }
r[1]=read(ram,0x0c0a0fb0u,4);
goto P_0c0a0f3e;
P_0c0a0f3e: /* original d31b, guest PC 0x0c0a0f3e */
if(!s->budget--) { s->failed_pc=0x0c0a0f3eu; return 0; }
r[3]=read(ram,0x0c0a0facu,4);
goto P_0c0a0f40;
P_0c0a0f40: /* original 4f12, guest PC 0x0c0a0f40 */
if(!s->budget--) { s->failed_pc=0x0c0a0f40u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a0f42;
P_0c0a0f42: /* original 6212, guest PC 0x0c0a0f42 */
if(!s->budget--) { s->failed_pc=0x0c0a0f42u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0a0f44;
P_0c0a0f44: /* original dd17, guest PC 0x0c0a0f44 */
if(!s->budget--) { s->failed_pc=0x0c0a0f44u; return 0; }
r[13]=read(ram,0x0c0a0fa4u,4);
goto P_0c0a0f46;
P_0c0a0f46: /* original d718, guest PC 0x0c0a0f46 */
if(!s->budget--) { s->failed_pc=0x0c0a0f46u; return 0; }
r[7]=read(ram,0x0c0a0fa8u,4);
goto P_0c0a0f48;
P_0c0a0f48: /* original 2238, guest PC 0x0c0a0f48 */
if(!s->budget--) { s->failed_pc=0x0c0a0f48u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0a0f4a;
P_0c0a0f4a: /* original 7ff0, guest PC 0x0c0a0f4a */
if(!s->budget--) { s->failed_pc=0x0c0a0f4au; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0a0f4c;
P_0c0a0f4c: /* original 8d02, guest PC 0x0c0a0f4c */
if(!s->budget--) { s->failed_pc=0x0c0a0f4cu; return 0; }
cond=r[17]&1u;
r[8]=0x00000000u;
if(cond) { goto P_0c0a0f54; }
goto P_0c0a0f50;
P_0c0a0f4e: /* original e800, guest PC 0x0c0a0f4e */
if(!s->budget--) { s->failed_pc=0x0c0a0f4eu; return 0; }
r[8]=0x00000000u;
goto P_0c0a0f50;
P_0c0a0f50: /* original a139, guest PC 0x0c0a0f50 */
if(!s->budget--) { s->failed_pc=0x0c0a0f50u; return 0; }
goto P_0c0a11c6;
P_0c0a0f52: /* original 0009, guest PC 0x0c0a0f52 */
if(!s->budget--) { s->failed_pc=0x0c0a0f52u; return 0; }
goto P_0c0a0f54;
P_0c0a0f54: /* original 9024, guest PC 0x0c0a0f54 */
if(!s->budget--) { s->failed_pc=0x0c0a0f54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0fa0u,2);
goto P_0c0a0f56;
P_0c0a0f56: /* original d617, guest PC 0x0c0a0f56 */
if(!s->budget--) { s->failed_pc=0x0c0a0f56u; return 0; }
r[6]=read(ram,0x0c0a0fb4u,4);
goto P_0c0a0f58;
P_0c0a0f58: /* original 03dc, guest PC 0x0c0a0f58 */
if(!s->budget--) { s->failed_pc=0x0c0a0f58u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a0f5a;
P_0c0a0f5a: /* original 5564, guest PC 0x0c0a0f5a */
if(!s->budget--) { s->failed_pc=0x0c0a0f5au; return 0; }
r[5]=read(ram,r[6]+16,4);
goto P_0c0a0f5c;
P_0c0a0f5c: /* original 2338, guest PC 0x0c0a0f5c */
if(!s->budget--) { s->failed_pc=0x0c0a0f5cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a0f5e;
P_0c0a0f5e: /* original 8f04, guest PC 0x0c0a0f5e */
if(!s->budget--) { s->failed_pc=0x0c0a0f5eu; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[6]+20,4);
if(!cond) { goto P_0c0a0f6a; }
goto P_0c0a0f62;
P_0c0a0f60: /* original 5465, guest PC 0x0c0a0f60 */
if(!s->budget--) { s->failed_pc=0x0c0a0f60u; return 0; }
r[4]=read(ram,r[6]+20,4);
goto P_0c0a0f62;
P_0c0a0f62: /* original d115, guest PC 0x0c0a0f62 */
if(!s->budget--) { s->failed_pc=0x0c0a0f62u; return 0; }
r[1]=read(ram,0x0c0a0fb8u,4);
goto P_0c0a0f64;
P_0c0a0f64: /* original 1f11, guest PC 0x0c0a0f64 */
if(!s->budget--) { s->failed_pc=0x0c0a0f64u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0a0f66;
P_0c0a0f66: /* original a002, guest PC 0x0c0a0f66 */
if(!s->budget--) { s->failed_pc=0x0c0a0f66u; return 0; }
r[14]=r[5];
goto P_0c0a0f6e;
P_0c0a0f68: /* original 6e53, guest PC 0x0c0a0f68 */
if(!s->budget--) { s->failed_pc=0x0c0a0f68u; return 0; }
r[14]=r[5];
goto P_0c0a0f6a;
P_0c0a0f6a: /* original 6e43, guest PC 0x0c0a0f6a */
if(!s->budget--) { s->failed_pc=0x0c0a0f6au; return 0; }
r[14]=r[4];
goto P_0c0a0f6c;
P_0c0a0f6c: /* original 1f81, guest PC 0x0c0a0f6c */
if(!s->budget--) { s->failed_pc=0x0c0a0f6cu; return 0; }
write(ram,r[15]+4,r[8],4);
goto P_0c0a0f6e;
P_0c0a0f6e: /* original 6272, guest PC 0x0c0a0f6e */
if(!s->budget--) { s->failed_pc=0x0c0a0f6eu; return 0; }
tmp=read(ram,r[7],4);
r[2]=tmp;
goto P_0c0a0f70;
P_0c0a0f70: /* original d312, guest PC 0x0c0a0f70 */
if(!s->budget--) { s->failed_pc=0x0c0a0f70u; return 0; }
r[3]=read(ram,0x0c0a0fbcu,4);
goto P_0c0a0f72;
P_0c0a0f72: /* original 2238, guest PC 0x0c0a0f72 */
if(!s->budget--) { s->failed_pc=0x0c0a0f72u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0a0f74;
P_0c0a0f74: /* original 8b26, guest PC 0x0c0a0f74 */
if(!s->budget--) { s->failed_pc=0x0c0a0f74u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a0fc4; }
goto P_0c0a0f76;
P_0c0a0f76: /* original e046, guest PC 0x0c0a0f76 */
if(!s->budget--) { s->failed_pc=0x0c0a0f76u; return 0; }
r[0]=0x00000046u;
goto P_0c0a0f78;
P_0c0a0f78: /* original 05ed, guest PC 0x0c0a0f78 */
if(!s->budget--) { s->failed_pc=0x0c0a0f78u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a0f7a;
P_0c0a0f7a: /* original 9012, guest PC 0x0c0a0f7a */
if(!s->budget--) { s->failed_pc=0x0c0a0f7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0fa2u,2);
goto P_0c0a0f7c;
P_0c0a0f7c: /* original 655d, guest PC 0x0c0a0f7c */
if(!s->budget--) { s->failed_pc=0x0c0a0f7cu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0a0f7e;
P_0c0a0f7e: /* original 04ed, guest PC 0x0c0a0f7e */
if(!s->budget--) { s->failed_pc=0x0c0a0f7eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a0f80;
P_0c0a0f80: /* original 2558, guest PC 0x0c0a0f80 */
if(!s->budget--) { s->failed_pc=0x0c0a0f80u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0a0f82;
P_0c0a0f82: /* original 8d0b, guest PC 0x0c0a0f82 */
if(!s->budget--) { s->failed_pc=0x0c0a0f82u; return 0; }
cond=r[17]&1u;
r[6]=0x00000019u;
if(cond) { goto P_0c0a0f9c; }
goto P_0c0a0f86;
P_0c0a0f84: /* original e619, guest PC 0x0c0a0f84 */
if(!s->budget--) { s->failed_pc=0x0c0a0f84u; return 0; }
r[6]=0x00000019u;
goto P_0c0a0f86;
P_0c0a0f86: /* original 0567, guest PC 0x0c0a0f86 */
if(!s->budget--) { s->failed_pc=0x0c0a0f86u; return 0; }
r[19]=r[5]*r[6];
goto P_0c0a0f88;
P_0c0a0f88: /* original d30d, guest PC 0x0c0a0f88 */
if(!s->budget--) { s->failed_pc=0x0c0a0f88u; return 0; }
r[3]=read(ram,0x0c0a0fc0u,4);
goto P_0c0a0f8a;
P_0c0a0f8a: /* original 051a, guest PC 0x0c0a0f8a */
if(!s->budget--) { s->failed_pc=0x0c0a0f8au; return 0; }
r[5]=r[19];
goto P_0c0a0f8c;
P_0c0a0f8c: /* original 6153, guest PC 0x0c0a0f8c */
if(!s->budget--) { s->failed_pc=0x0c0a0f8cu; return 0; }
r[1]=r[5];
goto P_0c0a0f8e;
P_0c0a0f8e: /* original 430b, guest PC 0x0c0a0f8e */
if(!s->budget--) { s->failed_pc=0x0c0a0f8eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a0f92u;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0f92u) { target=s->pc; goto dispatch; }
goto P_0c0a0f92;
P_0c0a0f90: /* original 6043, guest PC 0x0c0a0f90 */
if(!s->budget--) { s->failed_pc=0x0c0a0f90u; return 0; }
r[0]=r[4];
goto P_0c0a0f92;
P_0c0a0f92: /* original 6263, guest PC 0x0c0a0f92 */
if(!s->budget--) { s->failed_pc=0x0c0a0f92u; return 0; }
r[2]=r[6];
goto P_0c0a0f94;
P_0c0a0f94: /* original 6403, guest PC 0x0c0a0f94 */
if(!s->budget--) { s->failed_pc=0x0c0a0f94u; return 0; }
r[4]=r[0];
goto P_0c0a0f96;
P_0c0a0f96: /* original 3248, guest PC 0x0c0a0f96 */
if(!s->budget--) { s->failed_pc=0x0c0a0f96u; return 0; }
r[2]-=r[4];
goto P_0c0a0f98;
P_0c0a0f98: /* original a016, guest PC 0x0c0a0f98 */
if(!s->budget--) { s->failed_pc=0x0c0a0f98u; return 0; }
r[4]=r[2];
goto P_0c0a0fc8;
P_0c0a0f9a: /* original 6423, guest PC 0x0c0a0f9a */
if(!s->budget--) { s->failed_pc=0x0c0a0f9au; return 0; }
r[4]=r[2];
goto P_0c0a0f9c;
P_0c0a0f9c: /* original a014, guest PC 0x0c0a0f9c */
if(!s->budget--) { s->failed_pc=0x0c0a0f9cu; return 0; }
r[4]=0x0000001fu;
goto P_0c0a0fc8;
P_0c0a0f9e: /* original e41f, guest PC 0x0c0a0f9e */
if(!s->budget--) { s->failed_pc=0x0c0a0f9eu; return 0; }
r[4]=0x0000001fu;
if(!vf3_matrix_family(0x0c0a0fa0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a0fa0u; return 0; } return 1;
P_0c0a0fc4: /* original 9059, guest PC 0x0c0a0fc4 */
if(!s->budget--) { s->failed_pc=0x0c0a0fc4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a107au,2);
goto P_0c0a0fc6;
P_0c0a0fc6: /* original 04dc, guest PC 0x0c0a0fc6 */
if(!s->budget--) { s->failed_pc=0x0c0a0fc6u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a0fc8;
P_0c0a0fc8: /* original d62e, guest PC 0x0c0a0fc8 */
if(!s->budget--) { s->failed_pc=0x0c0a0fc8u; return 0; }
r[6]=read(ram,0x0c0a1084u,4);
goto P_0c0a0fca;
P_0c0a0fca: /* original 4400, guest PC 0x0c0a0fca */
if(!s->budget--) { s->failed_pc=0x0c0a0fcau; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a0fcc;
P_0c0a0fcc: /* original 63e3, guest PC 0x0c0a0fcc */
if(!s->budget--) { s->failed_pc=0x0c0a0fccu; return 0; }
r[3]=r[14];
goto P_0c0a0fce;
P_0c0a0fce: /* original 736c, guest PC 0x0c0a0fce */
if(!s->budget--) { s->failed_pc=0x0c0a0fceu; return 0; }
r[3]+=0x0000006cu;
goto P_0c0a0fd0;
P_0c0a0fd0: /* original 364c, guest PC 0x0c0a0fd0 */
if(!s->budget--) { s->failed_pc=0x0c0a0fd0u; return 0; }
r[6]+=r[4];
goto P_0c0a0fd2;
P_0c0a0fd2: /* original 6661, guest PC 0x0c0a0fd2 */
if(!s->budget--) { s->failed_pc=0x0c0a0fd2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[6]=tmp;
goto P_0c0a0fd4;
P_0c0a0fd4: /* original e712, guest PC 0x0c0a0fd4 */
if(!s->budget--) { s->failed_pc=0x0c0a0fd4u; return 0; }
r[7]=0x00000012u;
goto P_0c0a0fd6;
P_0c0a0fd6: /* original 2f32, guest PC 0x0c0a0fd6 */
if(!s->budget--) { s->failed_pc=0x0c0a0fd6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a0fd8;
P_0c0a0fd8: /* original e500, guest PC 0x0c0a0fd8 */
if(!s->budget--) { s->failed_pc=0x0c0a0fd8u; return 0; }
r[5]=0x00000000u;
goto P_0c0a0fda;
P_0c0a0fda: /* original 6473, guest PC 0x0c0a0fda */
if(!s->budget--) { s->failed_pc=0x0c0a0fdau; return 0; }
r[4]=r[7];
goto P_0c0a0fdc;
P_0c0a0fdc: /* original 666d, guest PC 0x0c0a0fdc */
if(!s->budget--) { s->failed_pc=0x0c0a0fdcu; return 0; }
r[6]=r[6]&65535u;
goto P_0c0a0fde;
P_0c0a0fde: /* original 6353, guest PC 0x0c0a0fde */
if(!s->budget--) { s->failed_pc=0x0c0a0fdeu; return 0; }
r[3]=r[5];
goto P_0c0a0fe0;
P_0c0a0fe0: /* original 60f2, guest PC 0x0c0a0fe0 */
if(!s->budget--) { s->failed_pc=0x0c0a0fe0u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0a0fe2;
P_0c0a0fe2: /* original 4308, guest PC 0x0c0a0fe2 */
if(!s->budget--) { s->failed_pc=0x0c0a0fe2u; return 0; }
r[3]<<=2;
goto P_0c0a0fe4;
P_0c0a0fe4: /* original 4410, guest PC 0x0c0a0fe4 */
if(!s->budget--) { s->failed_pc=0x0c0a0fe4u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c0a0fe6;
P_0c0a0fe6: /* original 0366, guest PC 0x0c0a0fe6 */
if(!s->budget--) { s->failed_pc=0x0c0a0fe6u; return 0; }
write(ram,r[3]+r[0],r[6],4);
goto P_0c0a0fe8;
P_0c0a0fe8: /* original 8ff9, guest PC 0x0c0a0fe8 */
if(!s->budget--) { s->failed_pc=0x0c0a0fe8u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000001u;
if(!cond) { goto P_0c0a0fde; }
goto P_0c0a0fec;
P_0c0a0fea: /* original 7501, guest PC 0x0c0a0fea */
if(!s->budget--) { s->failed_pc=0x0c0a0feau; return 0; }
r[5]+=0x00000001u;
goto P_0c0a0fec;
P_0c0a0fec: /* original dc26, guest PC 0x0c0a0fec */
if(!s->budget--) { s->failed_pc=0x0c0a0fecu; return 0; }
r[12]=read(ram,0x0c0a1088u,4);
goto P_0c0a0fee;
P_0c0a0fee: /* original 2f72, guest PC 0x0c0a0fee */
if(!s->budget--) { s->failed_pc=0x0c0a0feeu; return 0; }
write(ram,r[15],r[7],4);
goto P_0c0a0ff0;
P_0c0a0ff0: /* original 9a44, guest PC 0x0c0a0ff0 */
if(!s->budget--) { s->failed_pc=0x0c0a0ff0u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a107cu,2);
goto P_0c0a0ff2;
P_0c0a0ff2: /* original d326, guest PC 0x0c0a0ff2 */
if(!s->budget--) { s->failed_pc=0x0c0a0ff2u; return 0; }
r[3]=read(ram,0x0c0a108cu,4);
goto P_0c0a0ff4;
P_0c0a0ff4: /* original 3aec, guest PC 0x0c0a0ff4 */
if(!s->budget--) { s->failed_pc=0x0c0a0ff4u; return 0; }
r[10]+=r[14];
goto P_0c0a0ff6;
P_0c0a0ff6: /* original 430b, guest PC 0x0c0a0ff6 */
if(!s->budget--) { s->failed_pc=0x0c0a0ff6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a0ffau;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0ffau) { target=s->pc; goto dispatch; }
goto P_0c0a0ffa;
P_0c0a0ff8: /* original e400, guest PC 0x0c0a0ff8 */
if(!s->budget--) { s->failed_pc=0x0c0a0ff8u; return 0; }
r[4]=0x00000000u;
goto P_0c0a0ffa;
P_0c0a0ffa: /* original e004, guest PC 0x0c0a0ffa */
if(!s->budget--) { s->failed_pc=0x0c0a0ffau; return 0; }
r[0]=0x00000004u;
goto P_0c0a0ffc;
P_0c0a0ffc: /* original fec6, guest PC 0x0c0a0ffc */
if(!s->budget--) { s->failed_pc=0x0c0a0ffcu; return 0; }
vf3_matrix_load(s,ram,14,r[12]+r[0]);
goto P_0c0a0ffe;
P_0c0a0ffe: /* original c724, guest PC 0x0c0a0ffe */
if(!s->budget--) { s->failed_pc=0x0c0a0ffeu; return 0; }
r[0]=code_base|0x000a1090u;
goto P_0c0a1000;
P_0c0a1000: /* original f308, guest PC 0x0c0a1000 */
if(!s->budget--) { s->failed_pc=0x0c0a1000u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0a1002;
P_0c0a1002: /* original e00c, guest PC 0x0c0a1002 */
if(!s->budget--) { s->failed_pc=0x0c0a1002u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a1004;
P_0c0a1004: /* original f2ec, guest PC 0x0c0a1004 */
if(!s->budget--) { s->failed_pc=0x0c0a1004u; return 0; }
vf3_matrix_move(s,2,14);
goto P_0c0a1006;
P_0c0a1006: /* original f232, guest PC 0x0c0a1006 */
if(!s->budget--) { s->failed_pc=0x0c0a1006u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0a1008;
P_0c0a1008: /* original ff27, guest PC 0x0c0a1008 */
if(!s->budget--) { s->failed_pc=0x0c0a1008u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0a100a;
P_0c0a100a: /* original c722, guest PC 0x0c0a100a */
if(!s->budget--) { s->failed_pc=0x0c0a100au; return 0; }
r[0]=code_base|0x000a1094u;
goto P_0c0a100c;
P_0c0a100c: /* original f108, guest PC 0x0c0a100c */
if(!s->budget--) { s->failed_pc=0x0c0a100cu; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c0a100e;
P_0c0a100e: /* original e008, guest PC 0x0c0a100e */
if(!s->budget--) { s->failed_pc=0x0c0a100eu; return 0; }
r[0]=0x00000008u;
goto P_0c0a1010;
P_0c0a1010: /* original ff17, guest PC 0x0c0a1010 */
if(!s->budget--) { s->failed_pc=0x0c0a1010u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0a1012;
P_0c0a1012: /* original d321, guest PC 0x0c0a1012 */
if(!s->budget--) { s->failed_pc=0x0c0a1012u; return 0; }
r[3]=read(ram,0x0c0a1098u,4);
goto P_0c0a1014;
P_0c0a1014: /* original 430b, guest PC 0x0c0a1014 */
if(!s->budget--) { s->failed_pc=0x0c0a1014u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a1018u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a1018u) { target=s->pc; goto dispatch; }
goto P_0c0a1018;
P_0c0a1016: /* original 64a3, guest PC 0x0c0a1016 */
if(!s->budget--) { s->failed_pc=0x0c0a1016u; return 0; }
r[4]=r[10];
goto P_0c0a1018;
P_0c0a1018: /* original 60c0, guest PC 0x0c0a1018 */
if(!s->budget--) { s->failed_pc=0x0c0a1018u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[0]=tmp;
goto P_0c0a101a;
P_0c0a101a: /* original 9b30, guest PC 0x0c0a101a */
if(!s->budget--) { s->failed_pc=0x0c0a101au; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a107eu,2);
goto P_0c0a101c;
P_0c0a101c: /* original d91f, guest PC 0x0c0a101c */
if(!s->budget--) { s->failed_pc=0x0c0a101cu; return 0; }
r[9]=read(ram,0x0c0a109cu,4);
goto P_0c0a101e;
P_0c0a101e: /* original 8800, guest PC 0x0c0a101e */
if(!s->budget--) { s->failed_pc=0x0c0a101eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0a1020;
P_0c0a1020: /* original 8d0e, guest PC 0x0c0a1020 */
if(!s->budget--) { s->failed_pc=0x0c0a1020u; return 0; }
cond=r[17]&1u;
fr[15]=0;
if(cond) { goto P_0c0a1040; }
goto P_0c0a1024;
P_0c0a1022: /* original ff8d, guest PC 0x0c0a1022 */
if(!s->budget--) { s->failed_pc=0x0c0a1022u; return 0; }
fr[15]=0;
goto P_0c0a1024;
P_0c0a1024: /* original 8801, guest PC 0x0c0a1024 */
if(!s->budget--) { s->failed_pc=0x0c0a1024u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a1026;
P_0c0a1026: /* original 8913, guest PC 0x0c0a1026 */
if(!s->budget--) { s->failed_pc=0x0c0a1026u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1050; }
goto P_0c0a1028;
P_0c0a1028: /* original 8802, guest PC 0x0c0a1028 */
if(!s->budget--) { s->failed_pc=0x0c0a1028u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a102a;
P_0c0a102a: /* original 8911, guest PC 0x0c0a102a */
if(!s->budget--) { s->failed_pc=0x0c0a102au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1050; }
goto P_0c0a102c;
P_0c0a102c: /* original 8803, guest PC 0x0c0a102c */
if(!s->budget--) { s->failed_pc=0x0c0a102cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0a102e;
P_0c0a102e: /* original 8913, guest PC 0x0c0a102e */
if(!s->budget--) { s->failed_pc=0x0c0a102eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1058; }
goto P_0c0a1030;
P_0c0a1030: /* original 8804, guest PC 0x0c0a1030 */
if(!s->budget--) { s->failed_pc=0x0c0a1030u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0a1032;
P_0c0a1032: /* original 8915, guest PC 0x0c0a1032 */
if(!s->budget--) { s->failed_pc=0x0c0a1032u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1060; }
goto P_0c0a1034;
P_0c0a1034: /* original 8805, guest PC 0x0c0a1034 */
if(!s->budget--) { s->failed_pc=0x0c0a1034u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0a1036;
P_0c0a1036: /* original 8919, guest PC 0x0c0a1036 */
if(!s->budget--) { s->failed_pc=0x0c0a1036u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a106c; }
goto P_0c0a1038;
P_0c0a1038: /* original 8806, guest PC 0x0c0a1038 */
if(!s->budget--) { s->failed_pc=0x0c0a1038u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0a103a;
P_0c0a103a: /* original 8937, guest PC 0x0c0a103a */
if(!s->budget--) { s->failed_pc=0x0c0a103au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a10ac; }
goto P_0c0a103c;
P_0c0a103c: /* original a03f, guest PC 0x0c0a103c */
if(!s->budget--) { s->failed_pc=0x0c0a103cu; return 0; }
goto P_0c0a10be;
P_0c0a103e: /* original 0009, guest PC 0x0c0a103e */
if(!s->budget--) { s->failed_pc=0x0c0a103eu; return 0; }
goto P_0c0a1040;
P_0c0a1040: /* original d217, guest PC 0x0c0a1040 */
if(!s->budget--) { s->failed_pc=0x0c0a1040u; return 0; }
r[2]=read(ram,0x0c0a10a0u,4);
goto P_0c0a1042;
P_0c0a1042: /* original 941d, guest PC 0x0c0a1042 */
if(!s->budget--) { s->failed_pc=0x0c0a1042u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a1080u,2);
goto P_0c0a1044;
P_0c0a1044: /* original 420b, guest PC 0x0c0a1044 */
if(!s->budget--) { s->failed_pc=0x0c0a1044u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a1048u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a1048u) { target=s->pc; goto dispatch; }
goto P_0c0a1048;
P_0c0a1046: /* original 0009, guest PC 0x0c0a1046 */
if(!s->budget--) { s->failed_pc=0x0c0a1046u; return 0; }
goto P_0c0a1048;
P_0c0a1048: /* original c716, guest PC 0x0c0a1048 */
if(!s->budget--) { s->failed_pc=0x0c0a1048u; return 0; }
r[0]=code_base|0x000a10a4u;
goto P_0c0a104a;
P_0c0a104a: /* original f6fc, guest PC 0x0c0a104a */
if(!s->budget--) { s->failed_pc=0x0c0a104au; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0a104c;
P_0c0a104c: /* original a034, guest PC 0x0c0a104c */
if(!s->budget--) { s->failed_pc=0x0c0a104cu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0a10b8;
P_0c0a104e: /* original f508, guest PC 0x0c0a104e */
if(!s->budget--) { s->failed_pc=0x0c0a104eu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0a1050;
P_0c0a1050: /* original 490b, guest PC 0x0c0a1050 */
if(!s->budget--) { s->failed_pc=0x0c0a1050u; return 0; }
target=r[9];
r[16]=code_base|0x0c0a1054u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a1054u) { target=s->pc; goto dispatch; }
goto P_0c0a1054;
P_0c0a1052: /* original 64b3, guest PC 0x0c0a1052 */
if(!s->budget--) { s->failed_pc=0x0c0a1052u; return 0; }
r[4]=r[11];
goto P_0c0a1054;
P_0c0a1054: /* original a02d, guest PC 0x0c0a1054 */
if(!s->budget--) { s->failed_pc=0x0c0a1054u; return 0; }
goto P_0c0a10b2;
P_0c0a1056: /* original 0009, guest PC 0x0c0a1056 */
if(!s->budget--) { s->failed_pc=0x0c0a1056u; return 0; }
goto P_0c0a1058;
P_0c0a1058: /* original 490b, guest PC 0x0c0a1058 */
if(!s->budget--) { s->failed_pc=0x0c0a1058u; return 0; }
target=r[9];
r[16]=code_base|0x0c0a105cu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a105cu) { target=s->pc; goto dispatch; }
goto P_0c0a105c;
P_0c0a105a: /* original 64b3, guest PC 0x0c0a105a */
if(!s->budget--) { s->failed_pc=0x0c0a105au; return 0; }
r[4]=r[11];
goto P_0c0a105c;
P_0c0a105c: /* original a029, guest PC 0x0c0a105c */
if(!s->budget--) { s->failed_pc=0x0c0a105cu; return 0; }
goto P_0c0a10b2;
P_0c0a105e: /* original 0009, guest PC 0x0c0a105e */
if(!s->budget--) { s->failed_pc=0x0c0a105eu; return 0; }
goto P_0c0a1060;
P_0c0a1060: /* original d311, guest PC 0x0c0a1060 */
if(!s->budget--) { s->failed_pc=0x0c0a1060u; return 0; }
r[3]=read(ram,0x0c0a10a8u,4);
goto P_0c0a1062;
P_0c0a1062: /* original 54f1, guest PC 0x0c0a1062 */
if(!s->budget--) { s->failed_pc=0x0c0a1062u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0a1064;
P_0c0a1064: /* original 430b, guest PC 0x0c0a1064 */
if(!s->budget--) { s->failed_pc=0x0c0a1064u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a1068u;
r[4]=0u-r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a1068u) { target=s->pc; goto dispatch; }
goto P_0c0a1068;
P_0c0a1066: /* original 644b, guest PC 0x0c0a1066 */
if(!s->budget--) { s->failed_pc=0x0c0a1066u; return 0; }
r[4]=0u-r[4];
goto P_0c0a1068;
P_0c0a1068: /* original a029, guest PC 0x0c0a1068 */
if(!s->budget--) { s->failed_pc=0x0c0a1068u; return 0; }
goto P_0c0a10be;
P_0c0a106a: /* original 0009, guest PC 0x0c0a106a */
if(!s->budget--) { s->failed_pc=0x0c0a106au; return 0; }
goto P_0c0a106c;
P_0c0a106c: /* original 9408, guest PC 0x0c0a106c */
if(!s->budget--) { s->failed_pc=0x0c0a106cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a1080u,2);
goto P_0c0a106e;
P_0c0a106e: /* original 490b, guest PC 0x0c0a106e */
if(!s->budget--) { s->failed_pc=0x0c0a106eu; return 0; }
target=r[9];
r[16]=code_base|0x0c0a1072u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a1072u) { target=s->pc; goto dispatch; }
goto P_0c0a1072;
P_0c0a1070: /* original 0009, guest PC 0x0c0a1070 */
if(!s->budget--) { s->failed_pc=0x0c0a1070u; return 0; }
goto P_0c0a1072;
P_0c0a1072: /* original e008, guest PC 0x0c0a1072 */
if(!s->budget--) { s->failed_pc=0x0c0a1072u; return 0; }
r[0]=0x00000008u;
goto P_0c0a1074;
P_0c0a1074: /* original f6fc, guest PC 0x0c0a1074 */
if(!s->budget--) { s->failed_pc=0x0c0a1074u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0a1076;
P_0c0a1076: /* original a01f, guest PC 0x0c0a1076 */
if(!s->budget--) { s->failed_pc=0x0c0a1076u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0a10b8;
P_0c0a1078: /* original f5f6, guest PC 0x0c0a1078 */
if(!s->budget--) { s->failed_pc=0x0c0a1078u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
if(!vf3_matrix_family(0x0c0a107au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a107au; return 0; } return 1;
P_0c0a10ac: /* original d337, guest PC 0x0c0a10ac */
if(!s->budget--) { s->failed_pc=0x0c0a10acu; return 0; }
r[3]=read(ram,0x0c0a118cu,4);
goto P_0c0a10ae;
P_0c0a10ae: /* original 430b, guest PC 0x0c0a10ae */
if(!s->budget--) { s->failed_pc=0x0c0a10aeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a10b2u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a10b2u) { target=s->pc; goto dispatch; }
goto P_0c0a10b2;
P_0c0a10b0: /* original 64b3, guest PC 0x0c0a10b0 */
if(!s->budget--) { s->failed_pc=0x0c0a10b0u; return 0; }
r[4]=r[11];
goto P_0c0a10b2;
P_0c0a10b2: /* original e00c, guest PC 0x0c0a10b2 */
if(!s->budget--) { s->failed_pc=0x0c0a10b2u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a10b4;
P_0c0a10b4: /* original f6fc, guest PC 0x0c0a10b4 */
if(!s->budget--) { s->failed_pc=0x0c0a10b4u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0a10b6;
P_0c0a10b6: /* original f5f6, guest PC 0x0c0a10b6 */
if(!s->budget--) { s->failed_pc=0x0c0a10b6u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0a10b8;
P_0c0a10b8: /* original d335, guest PC 0x0c0a10b8 */
if(!s->budget--) { s->failed_pc=0x0c0a10b8u; return 0; }
r[3]=read(ram,0x0c0a1190u,4);
goto P_0c0a10ba;
P_0c0a10ba: /* original 430b, guest PC 0x0c0a10ba */
if(!s->budget--) { s->failed_pc=0x0c0a10bau; return 0; }
target=r[3];
r[16]=code_base|0x0c0a10beu;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a10beu) { target=s->pc; goto dispatch; }
goto P_0c0a10be;
P_0c0a10bc: /* original f4fc, guest PC 0x0c0a10bc */
if(!s->budget--) { s->failed_pc=0x0c0a10bcu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0a10be;
P_0c0a10be: /* original d335, guest PC 0x0c0a10be */
if(!s->budget--) { s->failed_pc=0x0c0a10beu; return 0; }
r[3]=read(ram,0x0c0a1194u,4);
goto P_0c0a10c0;
P_0c0a10c0: /* original 430b, guest PC 0x0c0a10c0 */
if(!s->budget--) { s->failed_pc=0x0c0a10c0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a10c4u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a10c4u) { target=s->pc; goto dispatch; }
goto P_0c0a10c4;
P_0c0a10c2: /* original 54f1, guest PC 0x0c0a10c2 */
if(!s->budget--) { s->failed_pc=0x0c0a10c2u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0a10c4;
P_0c0a10c4: /* original d234, guest PC 0x0c0a10c4 */
if(!s->budget--) { s->failed_pc=0x0c0a10c4u; return 0; }
r[2]=read(ram,0x0c0a1198u,4);
goto P_0c0a10c6;
P_0c0a10c6: /* original f5ec, guest PC 0x0c0a10c6 */
if(!s->budget--) { s->failed_pc=0x0c0a10c6u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0a10c8;
P_0c0a10c8: /* original f6ec, guest PC 0x0c0a10c8 */
if(!s->budget--) { s->failed_pc=0x0c0a10c8u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c0a10ca;
P_0c0a10ca: /* original 420b, guest PC 0x0c0a10ca */
if(!s->budget--) { s->failed_pc=0x0c0a10cau; return 0; }
target=r[2];
r[16]=code_base|0x0c0a10ceu;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a10ceu) { target=s->pc; goto dispatch; }
goto P_0c0a10ce;
P_0c0a10cc: /* original f4ec, guest PC 0x0c0a10cc */
if(!s->budget--) { s->failed_pc=0x0c0a10ccu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0a10ce;
P_0c0a10ce: /* original d333, guest PC 0x0c0a10ce */
if(!s->budget--) { s->failed_pc=0x0c0a10ceu; return 0; }
r[3]=read(ram,0x0c0a119cu,4);
goto P_0c0a10d0;
P_0c0a10d0: /* original 430b, guest PC 0x0c0a10d0 */
if(!s->budget--) { s->failed_pc=0x0c0a10d0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a10d4u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a10d4u) { target=s->pc; goto dispatch; }
goto P_0c0a10d4;
P_0c0a10d2: /* original 64a3, guest PC 0x0c0a10d2 */
if(!s->budget--) { s->failed_pc=0x0c0a10d2u; return 0; }
r[4]=r[10];
goto P_0c0a10d4;
P_0c0a10d4: /* original 62f2, guest PC 0x0c0a10d4 */
if(!s->budget--) { s->failed_pc=0x0c0a10d4u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a10d6;
P_0c0a10d6: /* original 7a40, guest PC 0x0c0a10d6 */
if(!s->budget--) { s->failed_pc=0x0c0a10d6u; return 0; }
r[10]+=0x00000040u;
goto P_0c0a10d8;
P_0c0a10d8: /* original 7c0c, guest PC 0x0c0a10d8 */
if(!s->budget--) { s->failed_pc=0x0c0a10d8u; return 0; }
r[12]+=0x0000000cu;
goto P_0c0a10da;
P_0c0a10da: /* original 72ff, guest PC 0x0c0a10da */
if(!s->budget--) { s->failed_pc=0x0c0a10dau; return 0; }
r[2]+=0xffffffffu;
goto P_0c0a10dc;
P_0c0a10dc: /* original 2228, guest PC 0x0c0a10dc */
if(!s->budget--) { s->failed_pc=0x0c0a10dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a10de;
P_0c0a10de: /* original 8f8c, guest PC 0x0c0a10de */
if(!s->budget--) { s->failed_pc=0x0c0a10deu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[2],4);
if(!cond) { goto P_0c0a0ffa; }
goto P_0c0a10e2;
P_0c0a10e0: /* original 2f22, guest PC 0x0c0a10e0 */
if(!s->budget--) { s->failed_pc=0x0c0a10e0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a10e2;
P_0c0a10e2: /* original d32f, guest PC 0x0c0a10e2 */
if(!s->budget--) { s->failed_pc=0x0c0a10e2u; return 0; }
r[3]=read(ram,0x0c0a11a0u,4);
goto P_0c0a10e4;
P_0c0a10e4: /* original 430b, guest PC 0x0c0a10e4 */
if(!s->budget--) { s->failed_pc=0x0c0a10e4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a10e8u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a10e8u) { target=s->pc; goto dispatch; }
goto P_0c0a10e8;
P_0c0a10e6: /* original e401, guest PC 0x0c0a10e6 */
if(!s->budget--) { s->failed_pc=0x0c0a10e6u; return 0; }
r[4]=0x00000001u;
goto P_0c0a10e8;
P_0c0a10e8: /* original e048, guest PC 0x0c0a10e8 */
if(!s->budget--) { s->failed_pc=0x0c0a10e8u; return 0; }
r[0]=0x00000048u;
goto P_0c0a10ea;
P_0c0a10ea: /* original 9349, guest PC 0x0c0a10ea */
if(!s->budget--) { s->failed_pc=0x0c0a10eau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a1180u,2);
goto P_0c0a10ec;
P_0c0a10ec: /* original 04ee, guest PC 0x0c0a10ec */
if(!s->budget--) { s->failed_pc=0x0c0a10ecu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0a10ee;
P_0c0a10ee: /* original 2438, guest PC 0x0c0a10ee */
if(!s->budget--) { s->failed_pc=0x0c0a10eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0a10f0;
P_0c0a10f0: /* original 8b67, guest PC 0x0c0a10f0 */
if(!s->budget--) { s->failed_pc=0x0c0a10f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a11c2; }
goto P_0c0a10f2;
P_0c0a10f2: /* original 9046, guest PC 0x0c0a10f2 */
if(!s->budget--) { s->failed_pc=0x0c0a10f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a1182u,2);
goto P_0c0a10f4;
P_0c0a10f4: /* original 00dc, guest PC 0x0c0a10f4 */
if(!s->budget--) { s->failed_pc=0x0c0a10f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a10f6;
P_0c0a10f6: /* original 600c, guest PC 0x0c0a10f6 */
if(!s->budget--) { s->failed_pc=0x0c0a10f6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0a10f8;
P_0c0a10f8: /* original 8800, guest PC 0x0c0a10f8 */
if(!s->budget--) { s->failed_pc=0x0c0a10f8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0a10fa;
P_0c0a10fa: /* original 8907, guest PC 0x0c0a10fa */
if(!s->budget--) { s->failed_pc=0x0c0a10fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a110c; }
goto P_0c0a10fc;
P_0c0a10fc: /* original 8801, guest PC 0x0c0a10fc */
if(!s->budget--) { s->failed_pc=0x0c0a10fcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a10fe;
P_0c0a10fe: /* original 8924, guest PC 0x0c0a10fe */
if(!s->budget--) { s->failed_pc=0x0c0a10feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a114a; }
goto P_0c0a1100;
P_0c0a1100: /* original 8802, guest PC 0x0c0a1100 */
if(!s->budget--) { s->failed_pc=0x0c0a1100u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a1102;
P_0c0a1102: /* original 892c, guest PC 0x0c0a1102 */
if(!s->budget--) { s->failed_pc=0x0c0a1102u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a115e; }
goto P_0c0a1104;
P_0c0a1104: /* original 8803, guest PC 0x0c0a1104 */
if(!s->budget--) { s->failed_pc=0x0c0a1104u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0a1106;
P_0c0a1106: /* original 8951, guest PC 0x0c0a1106 */
if(!s->budget--) { s->failed_pc=0x0c0a1106u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a11ac; }
goto P_0c0a1108;
P_0c0a1108: /* original a05d, guest PC 0x0c0a1108 */
if(!s->budget--) { s->failed_pc=0x0c0a1108u; return 0; }
goto P_0c0a11c6;
P_0c0a110a: /* original 0009, guest PC 0x0c0a110a */
if(!s->budget--) { s->failed_pc=0x0c0a110au; return 0; }
goto P_0c0a110c;
P_0c0a110c: /* original e048, guest PC 0x0c0a110c */
if(!s->budget--) { s->failed_pc=0x0c0a110cu; return 0; }
r[0]=0x00000048u;
goto P_0c0a110e;
P_0c0a110e: /* original 05ee, guest PC 0x0c0a110e */
if(!s->budget--) { s->failed_pc=0x0c0a110eu; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0a1110;
P_0c0a1110: /* original 9038, guest PC 0x0c0a1110 */
if(!s->budget--) { s->failed_pc=0x0c0a1110u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a1184u,2);
goto P_0c0a1112;
P_0c0a1112: /* original 03ed, guest PC 0x0c0a1112 */
if(!s->budget--) { s->failed_pc=0x0c0a1112u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a1114;
P_0c0a1114: /* original e03e, guest PC 0x0c0a1114 */
if(!s->budget--) { s->failed_pc=0x0c0a1114u; return 0; }
r[0]=0x0000003eu;
goto P_0c0a1116;
P_0c0a1116: /* original 633d, guest PC 0x0c0a1116 */
if(!s->budget--) { s->failed_pc=0x0c0a1116u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a1118;
P_0c0a1118: /* original 1f31, guest PC 0x0c0a1118 */
if(!s->budget--) { s->failed_pc=0x0c0a1118u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0a111a;
P_0c0a111a: /* original 07ed, guest PC 0x0c0a111a */
if(!s->budget--) { s->failed_pc=0x0c0a111au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a111c;
P_0c0a111c: /* original 9033, guest PC 0x0c0a111c */
if(!s->budget--) { s->failed_pc=0x0c0a111cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a1186u,2);
goto P_0c0a111e;
P_0c0a111e: /* original d321, guest PC 0x0c0a111e */
if(!s->budget--) { s->failed_pc=0x0c0a111eu; return 0; }
r[3]=read(ram,0x0c0a11a4u,4);
goto P_0c0a1120;
P_0c0a1120: /* original 677d, guest PC 0x0c0a1120 */
if(!s->budget--) { s->failed_pc=0x0c0a1120u; return 0; }
r[7]=r[7]&65535u;
goto P_0c0a1122;
P_0c0a1122: /* original 06ec, guest PC 0x0c0a1122 */
if(!s->budget--) { s->failed_pc=0x0c0a1122u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a1124;
P_0c0a1124: /* original 2358, guest PC 0x0c0a1124 */
if(!s->budget--) { s->failed_pc=0x0c0a1124u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0a1126;
P_0c0a1126: /* original 8d4e, guest PC 0x0c0a1126 */
if(!s->budget--) { s->failed_pc=0x0c0a1126u; return 0; }
cond=r[17]&1u;
r[6]=r[6]&255u;
if(cond) { goto P_0c0a11c6; }
goto P_0c0a112a;
P_0c0a1128: /* original 666c, guest PC 0x0c0a1128 */
if(!s->budget--) { s->failed_pc=0x0c0a1128u; return 0; }
r[6]=r[6]&255u;
goto P_0c0a112a;
P_0c0a112a: /* original 932d, guest PC 0x0c0a112a */
if(!s->budget--) { s->failed_pc=0x0c0a112au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a1188u,2);
goto P_0c0a112c;
P_0c0a112c: /* original 2538, guest PC 0x0c0a112c */
if(!s->budget--) { s->failed_pc=0x0c0a112cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0a112e;
P_0c0a112e: /* original 8d06, guest PC 0x0c0a112e */
if(!s->budget--) { s->failed_pc=0x0c0a112eu; return 0; }
cond=r[17]&1u;
r[4]=0x00000008u;
if(cond) { goto P_0c0a113e; }
goto P_0c0a1132;
P_0c0a1130: /* original e408, guest PC 0x0c0a1130 */
if(!s->budget--) { s->failed_pc=0x0c0a1130u; return 0; }
r[4]=0x00000008u;
goto P_0c0a1132;
P_0c0a1132: /* original 53f1, guest PC 0x0c0a1132 */
if(!s->budget--) { s->failed_pc=0x0c0a1132u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a1134;
P_0c0a1134: /* original 3730, guest PC 0x0c0a1134 */
if(!s->budget--) { s->failed_pc=0x0c0a1134u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[3])!=0);
goto P_0c0a1136;
P_0c0a1136: /* original 8f46, guest PC 0x0c0a1136 */
if(!s->budget--) { s->failed_pc=0x0c0a1136u; return 0; }
cond=r[17]&1u;
r[4]=r[8];
if(!cond) { goto P_0c0a11c6; }
goto P_0c0a113a;
P_0c0a1138: /* original 6483, guest PC 0x0c0a1138 */
if(!s->budget--) { s->failed_pc=0x0c0a1138u; return 0; }
r[4]=r[8];
goto P_0c0a113a;
P_0c0a113a: /* original 2668, guest PC 0x0c0a113a */
if(!s->budget--) { s->failed_pc=0x0c0a113au; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0a113c;
P_0c0a113c: /* original 8943, guest PC 0x0c0a113c */
if(!s->budget--) { s->failed_pc=0x0c0a113cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a11c6; }
goto P_0c0a113e;
P_0c0a113e: /* original 9020, guest PC 0x0c0a113e */
if(!s->budget--) { s->failed_pc=0x0c0a113eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a1182u,2);
goto P_0c0a1140;
P_0c0a1140: /* original e201, guest PC 0x0c0a1140 */
if(!s->budget--) { s->failed_pc=0x0c0a1140u; return 0; }
r[2]=0x00000001u;
goto P_0c0a1142;
P_0c0a1142: /* original 0d24, guest PC 0x0c0a1142 */
if(!s->budget--) { s->failed_pc=0x0c0a1142u; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c0a1144;
P_0c0a1144: /* original 70fe, guest PC 0x0c0a1144 */
if(!s->budget--) { s->failed_pc=0x0c0a1144u; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0a1146;
P_0c0a1146: /* original a03e, guest PC 0x0c0a1146 */
if(!s->budget--) { s->failed_pc=0x0c0a1146u; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c0a11c6;
P_0c0a1148: /* original 0d45, guest PC 0x0c0a1148 */
if(!s->budget--) { s->failed_pc=0x0c0a1148u; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c0a114a;
P_0c0a114a: /* original 901e, guest PC 0x0c0a114a */
if(!s->budget--) { s->failed_pc=0x0c0a114au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a118au,2);
goto P_0c0a114c;
P_0c0a114c: /* original 04dd, guest PC 0x0c0a114c */
if(!s->budget--) { s->failed_pc=0x0c0a114cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a114e;
P_0c0a114e: /* original 2448, guest PC 0x0c0a114e */
if(!s->budget--) { s->failed_pc=0x0c0a114eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a1150;
P_0c0a1150: /* original 8901, guest PC 0x0c0a1150 */
if(!s->budget--) { s->failed_pc=0x0c0a1150u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1156; }
goto P_0c0a1152;
P_0c0a1152: /* original aff8, guest PC 0x0c0a1152 */
if(!s->budget--) { s->failed_pc=0x0c0a1152u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0a1146;
P_0c0a1154: /* original 74ff, guest PC 0x0c0a1154 */
if(!s->budget--) { s->failed_pc=0x0c0a1154u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0a1156;
P_0c0a1156: /* original bb45, guest PC 0x0c0a1156 */
if(!s->budget--) { s->failed_pc=0x0c0a1156u; return 0; }
target=code_base|0x0c0a07e4u; r[16]=code_base|0x0c0a115au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a115au) { target=s->pc; goto dispatch; }
goto P_0c0a115a;
P_0c0a1158: /* original 64e3, guest PC 0x0c0a1158 */
if(!s->budget--) { s->failed_pc=0x0c0a1158u; return 0; }
r[4]=r[14];
goto P_0c0a115a;
P_0c0a115a: /* original a00b, guest PC 0x0c0a115a */
if(!s->budget--) { s->failed_pc=0x0c0a115au; return 0; }
r[3]=0x00000002u;
goto P_0c0a1174;
P_0c0a115c: /* original e302, guest PC 0x0c0a115c */
if(!s->budget--) { s->failed_pc=0x0c0a115cu; return 0; }
r[3]=0x00000002u;
goto P_0c0a115e;
P_0c0a115e: /* original bcc5, guest PC 0x0c0a115e */
if(!s->budget--) { s->failed_pc=0x0c0a115eu; return 0; }
target=code_base|0x0c0a0aecu; r[16]=code_base|0x0c0a1162u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a1162u) { target=s->pc; goto dispatch; }
goto P_0c0a1162;
P_0c0a1160: /* original 0009, guest PC 0x0c0a1160 */
if(!s->budget--) { s->failed_pc=0x0c0a1160u; return 0; }
goto P_0c0a1162;
P_0c0a1162: /* original e048, guest PC 0x0c0a1162 */
if(!s->budget--) { s->failed_pc=0x0c0a1162u; return 0; }
r[0]=0x00000048u;
goto P_0c0a1164;
P_0c0a1164: /* original d30f, guest PC 0x0c0a1164 */
if(!s->budget--) { s->failed_pc=0x0c0a1164u; return 0; }
r[3]=read(ram,0x0c0a11a4u,4);
goto P_0c0a1166;
P_0c0a1166: /* original 04ee, guest PC 0x0c0a1166 */
if(!s->budget--) { s->failed_pc=0x0c0a1166u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0a1168;
P_0c0a1168: /* original 2348, guest PC 0x0c0a1168 */
if(!s->budget--) { s->failed_pc=0x0c0a1168u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0a116a;
P_0c0a116a: /* original 8b2c, guest PC 0x0c0a116a */
if(!s->budget--) { s->failed_pc=0x0c0a116au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a11c6; }
goto P_0c0a116c;
P_0c0a116c: /* original d20e, guest PC 0x0c0a116c */
if(!s->budget--) { s->failed_pc=0x0c0a116cu; return 0; }
r[2]=read(ram,0x0c0a11a8u,4);
goto P_0c0a116e;
P_0c0a116e: /* original 2428, guest PC 0x0c0a116e */
if(!s->budget--) { s->failed_pc=0x0c0a116eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0a1170;
P_0c0a1170: /* original 8929, guest PC 0x0c0a1170 */
if(!s->budget--) { s->failed_pc=0x0c0a1170u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a11c6; }
goto P_0c0a1172;
P_0c0a1172: /* original e303, guest PC 0x0c0a1172 */
if(!s->budget--) { s->failed_pc=0x0c0a1172u; return 0; }
r[3]=0x00000003u;
goto P_0c0a1174;
P_0c0a1174: /* original 9005, guest PC 0x0c0a1174 */
if(!s->budget--) { s->failed_pc=0x0c0a1174u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a1182u,2);
goto P_0c0a1176;
P_0c0a1176: /* original e230, guest PC 0x0c0a1176 */
if(!s->budget--) { s->failed_pc=0x0c0a1176u; return 0; }
r[2]=0x00000030u;
goto P_0c0a1178;
P_0c0a1178: /* original 0d34, guest PC 0x0c0a1178 */
if(!s->budget--) { s->failed_pc=0x0c0a1178u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c0a117a;
P_0c0a117a: /* original 70fe, guest PC 0x0c0a117a */
if(!s->budget--) { s->failed_pc=0x0c0a117au; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0a117c;
P_0c0a117c: /* original a023, guest PC 0x0c0a117c */
if(!s->budget--) { s->failed_pc=0x0c0a117cu; return 0; }
write(ram,r[13]+r[0],r[2],2);
goto P_0c0a11c6;
P_0c0a117e: /* original 0d25, guest PC 0x0c0a117e */
if(!s->budget--) { s->failed_pc=0x0c0a117eu; return 0; }
write(ram,r[13]+r[0],r[2],2);
if(!vf3_matrix_family(0x0c0a1180u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a1180u; return 0; } return 1;
P_0c0a11ac: /* original bdc1, guest PC 0x0c0a11ac */
if(!s->budget--) { s->failed_pc=0x0c0a11acu; return 0; }
target=code_base|0x0c0a0d32u; r[16]=code_base|0x0c0a11b0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a11b0u) { target=s->pc; goto dispatch; }
goto P_0c0a11b0;
P_0c0a11ae: /* original 0009, guest PC 0x0c0a11ae */
if(!s->budget--) { s->failed_pc=0x0c0a11aeu; return 0; }
goto P_0c0a11b0;
P_0c0a11b0: /* original 9016, guest PC 0x0c0a11b0 */
if(!s->budget--) { s->failed_pc=0x0c0a11b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a11e0u,2);
goto P_0c0a11b2;
P_0c0a11b2: /* original 05dd, guest PC 0x0c0a11b2 */
if(!s->budget--) { s->failed_pc=0x0c0a11b2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a11b4;
P_0c0a11b4: /* original e048, guest PC 0x0c0a11b4 */
if(!s->budget--) { s->failed_pc=0x0c0a11b4u; return 0; }
r[0]=0x00000048u;
goto P_0c0a11b6;
P_0c0a11b6: /* original 2558, guest PC 0x0c0a11b6 */
if(!s->budget--) { s->failed_pc=0x0c0a11b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0a11b8;
P_0c0a11b8: /* original 8d03, guest PC 0x0c0a11b8 */
if(!s->budget--) { s->failed_pc=0x0c0a11b8u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[14]+r[0],4);
if(cond) { goto P_0c0a11c2; }
goto P_0c0a11bc;
P_0c0a11ba: /* original 04ee, guest PC 0x0c0a11ba */
if(!s->budget--) { s->failed_pc=0x0c0a11bau; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0a11bc;
P_0c0a11bc: /* original d309, guest PC 0x0c0a11bc */
if(!s->budget--) { s->failed_pc=0x0c0a11bcu; return 0; }
r[3]=read(ram,0x0c0a11e4u,4);
goto P_0c0a11be;
P_0c0a11be: /* original 2438, guest PC 0x0c0a11be */
if(!s->budget--) { s->failed_pc=0x0c0a11beu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0a11c0;
P_0c0a11c0: /* original 8901, guest PC 0x0c0a11c0 */
if(!s->budget--) { s->failed_pc=0x0c0a11c0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a11c6; }
goto P_0c0a11c2;
P_0c0a11c2: /* original 900e, guest PC 0x0c0a11c2 */
if(!s->budget--) { s->failed_pc=0x0c0a11c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a11e2u,2);
goto P_0c0a11c4;
P_0c0a11c4: /* original 0d84, guest PC 0x0c0a11c4 */
if(!s->budget--) { s->failed_pc=0x0c0a11c4u; return 0; }
write(ram,r[13]+r[0],r[8],1);
goto P_0c0a11c6;
P_0c0a11c6: /* original 7f10, guest PC 0x0c0a11c6 */
if(!s->budget--) { s->failed_pc=0x0c0a11c6u; return 0; }
r[15]+=0x00000010u;
goto P_0c0a11c8;
P_0c0a11c8: /* original 4f16, guest PC 0x0c0a11c8 */
if(!s->budget--) { s->failed_pc=0x0c0a11c8u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a11ca;
P_0c0a11ca: /* original 4f26, guest PC 0x0c0a11ca */
if(!s->budget--) { s->failed_pc=0x0c0a11cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a11cc;
P_0c0a11cc: /* original fef9, guest PC 0x0c0a11cc */
if(!s->budget--) { s->failed_pc=0x0c0a11ccu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a11ce;
P_0c0a11ce: /* original fff9, guest PC 0x0c0a11ce */
if(!s->budget--) { s->failed_pc=0x0c0a11ceu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a11d0;
P_0c0a11d0: /* original 68f6, guest PC 0x0c0a11d0 */
if(!s->budget--) { s->failed_pc=0x0c0a11d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a11d2;
P_0c0a11d2: /* original 69f6, guest PC 0x0c0a11d2 */
if(!s->budget--) { s->failed_pc=0x0c0a11d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a11d4;
P_0c0a11d4: /* original 6af6, guest PC 0x0c0a11d4 */
if(!s->budget--) { s->failed_pc=0x0c0a11d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a11d6;
P_0c0a11d6: /* original 6bf6, guest PC 0x0c0a11d6 */
if(!s->budget--) { s->failed_pc=0x0c0a11d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a11d8;
P_0c0a11d8: /* original 6cf6, guest PC 0x0c0a11d8 */
if(!s->budget--) { s->failed_pc=0x0c0a11d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a11da;
P_0c0a11da: /* original 6df6, guest PC 0x0c0a11da */
if(!s->budget--) { s->failed_pc=0x0c0a11dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a11dc;
P_0c0a11dc: /* original 000b, guest PC 0x0c0a11dc */
if(!s->budget--) { s->failed_pc=0x0c0a11dcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a11de: /* original 6ef6, guest PC 0x0c0a11de */
if(!s->budget--) { s->failed_pc=0x0c0a11deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a11e0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a11e0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
