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
int vf3_away_batch33_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07b71cu: goto P_0c07b71c;
case 0x0c07b71eu: goto P_0c07b71e;
case 0x0c0a7f14u: goto P_0c0a7f14;
case 0x0c0a7f16u: goto P_0c0a7f16;
case 0x0c0a7f18u: goto P_0c0a7f18;
case 0x0c0a7f1au: goto P_0c0a7f1a;
case 0x0c0a7f1cu: goto P_0c0a7f1c;
case 0x0c0a7f1eu: goto P_0c0a7f1e;
case 0x0c0a7f20u: goto P_0c0a7f20;
case 0x0c0a7f22u: goto P_0c0a7f22;
case 0x0c0a7f24u: goto P_0c0a7f24;
case 0x0c0a7f26u: goto P_0c0a7f26;
case 0x0c0a7f28u: goto P_0c0a7f28;
case 0x0c0a7f2au: goto P_0c0a7f2a;
case 0x0c0a7f2cu: goto P_0c0a7f2c;
case 0x0c0a7f2eu: goto P_0c0a7f2e;
case 0x0c0a7f30u: goto P_0c0a7f30;
case 0x0c0a7f32u: goto P_0c0a7f32;
case 0x0c0a7f34u: goto P_0c0a7f34;
case 0x0c0a7f36u: goto P_0c0a7f36;
case 0x0c0a7f38u: goto P_0c0a7f38;
case 0x0c0a7f3au: goto P_0c0a7f3a;
case 0x0c0a7f3cu: goto P_0c0a7f3c;
case 0x0c0a7f3eu: goto P_0c0a7f3e;
case 0x0c0a7f40u: goto P_0c0a7f40;
case 0x0c0a7f42u: goto P_0c0a7f42;
case 0x0c0a7f44u: goto P_0c0a7f44;
case 0x0c0a7f46u: goto P_0c0a7f46;
case 0x0c0a7f48u: goto P_0c0a7f48;
case 0x0c0a7f4au: goto P_0c0a7f4a;
case 0x0c0a7f4cu: goto P_0c0a7f4c;
case 0x0c0a7f4eu: goto P_0c0a7f4e;
case 0x0c0a7f50u: goto P_0c0a7f50;
case 0x0c0a7f52u: goto P_0c0a7f52;
case 0x0c0a7f54u: goto P_0c0a7f54;
case 0x0c0a81eeu: goto P_0c0a81ee;
case 0x0c0a81f0u: goto P_0c0a81f0;
case 0x0c0a81f2u: goto P_0c0a81f2;
case 0x0c0a81f4u: goto P_0c0a81f4;
case 0x0c0a81f6u: goto P_0c0a81f6;
case 0x0c0a81f8u: goto P_0c0a81f8;
case 0x0c0a81fau: goto P_0c0a81fa;
case 0x0c0a81fcu: goto P_0c0a81fc;
case 0x0c0a81feu: goto P_0c0a81fe;
case 0x0c0a8200u: goto P_0c0a8200;
case 0x0c0a8202u: goto P_0c0a8202;
case 0x0c0a8204u: goto P_0c0a8204;
case 0x0c0a8206u: goto P_0c0a8206;
case 0x0c0a8208u: goto P_0c0a8208;
case 0x0c0a820au: goto P_0c0a820a;
case 0x0c0a820cu: goto P_0c0a820c;
case 0x0c0a820eu: goto P_0c0a820e;
case 0x0c0a8210u: goto P_0c0a8210;
case 0x0c0a8212u: goto P_0c0a8212;
case 0x0c0a8214u: goto P_0c0a8214;
case 0x0c0a8216u: goto P_0c0a8216;
case 0x0c0a8218u: goto P_0c0a8218;
case 0x0c0a821au: goto P_0c0a821a;
case 0x0c0a821cu: goto P_0c0a821c;
case 0x0c0a821eu: goto P_0c0a821e;
case 0x0c0a8220u: goto P_0c0a8220;
case 0x0c0a8222u: goto P_0c0a8222;
case 0x0c0a8224u: goto P_0c0a8224;
case 0x0c0a8226u: goto P_0c0a8226;
case 0x0c0a8228u: goto P_0c0a8228;
case 0x0c0a822au: goto P_0c0a822a;
case 0x0c0a822cu: goto P_0c0a822c;
case 0x0c0a822eu: goto P_0c0a822e;
case 0x0c0a8230u: goto P_0c0a8230;
case 0x0c0a8232u: goto P_0c0a8232;
case 0x0c0a8234u: goto P_0c0a8234;
case 0x0c0a8236u: goto P_0c0a8236;
case 0x0c0a8238u: goto P_0c0a8238;
case 0x0c0a823au: goto P_0c0a823a;
case 0x0c0a823cu: goto P_0c0a823c;
case 0x0c0a823eu: goto P_0c0a823e;
case 0x0c0a8240u: goto P_0c0a8240;
case 0x0c0a8242u: goto P_0c0a8242;
case 0x0c0a8244u: goto P_0c0a8244;
case 0x0c0a8246u: goto P_0c0a8246;
case 0x0c0a8248u: goto P_0c0a8248;
case 0x0c0a824au: goto P_0c0a824a;
case 0x0c0a824cu: goto P_0c0a824c;
case 0x0c0a824eu: goto P_0c0a824e;
case 0x0c0a8250u: goto P_0c0a8250;
case 0x0c0a8252u: goto P_0c0a8252;
case 0x0c0a8254u: goto P_0c0a8254;
case 0x0c0a8256u: goto P_0c0a8256;
case 0x0c0a8258u: goto P_0c0a8258;
case 0x0c0a825au: goto P_0c0a825a;
case 0x0c0a825cu: goto P_0c0a825c;
case 0x0c0a825eu: goto P_0c0a825e;
case 0x0c0a8260u: goto P_0c0a8260;
case 0x0c0a8262u: goto P_0c0a8262;
case 0x0c0a8264u: goto P_0c0a8264;
case 0x0c0a8266u: goto P_0c0a8266;
case 0x0c0a8268u: goto P_0c0a8268;
case 0x0c0a826au: goto P_0c0a826a;
case 0x0c0a826cu: goto P_0c0a826c;
case 0x0c0a826eu: goto P_0c0a826e;
case 0x0c0a8270u: goto P_0c0a8270;
case 0x0c0a8272u: goto P_0c0a8272;
case 0x0c0a8274u: goto P_0c0a8274;
case 0x0c0a8276u: goto P_0c0a8276;
case 0x0c0a8278u: goto P_0c0a8278;
case 0x0c0a827au: goto P_0c0a827a;
case 0x0c0a827cu: goto P_0c0a827c;
case 0x0c0a827eu: goto P_0c0a827e;
case 0x0c0a8280u: goto P_0c0a8280;
case 0x0c0a8282u: goto P_0c0a8282;
case 0x0c0a8284u: goto P_0c0a8284;
case 0x0c0a8286u: goto P_0c0a8286;
case 0x0c0a8288u: goto P_0c0a8288;
case 0x0c0a828au: goto P_0c0a828a;
case 0x0c0a828cu: goto P_0c0a828c;
case 0x0c0a828eu: goto P_0c0a828e;
case 0x0c0a8290u: goto P_0c0a8290;
case 0x0c0a8292u: goto P_0c0a8292;
case 0x0c0a8294u: goto P_0c0a8294;
case 0x0c0a8296u: goto P_0c0a8296;
case 0x0c0a8298u: goto P_0c0a8298;
case 0x0c0a829au: goto P_0c0a829a;
case 0x0c0c10a2u: goto P_0c0c10a2;
case 0x0c0c10a4u: goto P_0c0c10a4;
case 0x0c0c10a6u: goto P_0c0c10a6;
case 0x0c0c10a8u: goto P_0c0c10a8;
case 0x0c0c10aau: goto P_0c0c10aa;
case 0x0c0c10acu: goto P_0c0c10ac;
case 0x0c0c10aeu: goto P_0c0c10ae;
case 0x0c0c10b0u: goto P_0c0c10b0;
case 0x0c0c10b2u: goto P_0c0c10b2;
case 0x0c0c10b4u: goto P_0c0c10b4;
case 0x0c0c10b6u: goto P_0c0c10b6;
case 0x0c0c10b8u: goto P_0c0c10b8;
case 0x0c0c10bau: goto P_0c0c10ba;
case 0x0c0c10bcu: goto P_0c0c10bc;
case 0x0c0c10beu: goto P_0c0c10be;
case 0x0c0c10c0u: goto P_0c0c10c0;
case 0x0c0c10c2u: goto P_0c0c10c2;
case 0x0c0c10c4u: goto P_0c0c10c4;
case 0x0c0c10c6u: goto P_0c0c10c6;
case 0x0c0c10c8u: goto P_0c0c10c8;
case 0x0c0c10cau: goto P_0c0c10ca;
case 0x0c0c10ccu: goto P_0c0c10cc;
case 0x0c0c10ceu: goto P_0c0c10ce;
case 0x0c0c10d0u: goto P_0c0c10d0;
case 0x0c0c10d2u: goto P_0c0c10d2;
case 0x0c0c10d4u: goto P_0c0c10d4;
case 0x0c0c10d6u: goto P_0c0c10d6;
case 0x0c0c10d8u: goto P_0c0c10d8;
case 0x0c0c10dau: goto P_0c0c10da;
case 0x0c0c10dcu: goto P_0c0c10dc;
case 0x0c0c10deu: goto P_0c0c10de;
case 0x0c0c10e0u: goto P_0c0c10e0;
case 0x0c0c10e2u: goto P_0c0c10e2;
case 0x0c0c10e4u: goto P_0c0c10e4;
case 0x0c0c10e6u: goto P_0c0c10e6;
case 0x0c0c10e8u: goto P_0c0c10e8;
case 0x0c0c10eau: goto P_0c0c10ea;
case 0x0c0c10ecu: goto P_0c0c10ec;
case 0x0c0c10eeu: goto P_0c0c10ee;
case 0x0c0c10f0u: goto P_0c0c10f0;
case 0x0c0c10f2u: goto P_0c0c10f2;
case 0x0c0c10f4u: goto P_0c0c10f4;
case 0x0c0c10f6u: goto P_0c0c10f6;
case 0x0c0c10f8u: goto P_0c0c10f8;
case 0x0c0c10fau: goto P_0c0c10fa;
case 0x0c0c10fcu: goto P_0c0c10fc;
case 0x0c0c10feu: goto P_0c0c10fe;
case 0x0c0c1100u: goto P_0c0c1100;
case 0x0c0c1102u: goto P_0c0c1102;
case 0x0c0c1104u: goto P_0c0c1104;
case 0x0c0c1106u: goto P_0c0c1106;
case 0x0c0c1108u: goto P_0c0c1108;
case 0x0c0c110au: goto P_0c0c110a;
case 0x0c0c110cu: goto P_0c0c110c;
case 0x0c0c110eu: goto P_0c0c110e;
case 0x0c0c1110u: goto P_0c0c1110;
case 0x0c0c1112u: goto P_0c0c1112;
case 0x0c0c1114u: goto P_0c0c1114;
case 0x0c0c1116u: goto P_0c0c1116;
case 0x0c0c1118u: goto P_0c0c1118;
case 0x0c0c111au: goto P_0c0c111a;
case 0x0c0c111cu: goto P_0c0c111c;
case 0x0c0c111eu: goto P_0c0c111e;
case 0x0c0c1120u: goto P_0c0c1120;
case 0x0c0c1122u: goto P_0c0c1122;
case 0x0c0c1124u: goto P_0c0c1124;
case 0x0c0c1126u: goto P_0c0c1126;
case 0x0c0c1128u: goto P_0c0c1128;
case 0x0c0c112au: goto P_0c0c112a;
case 0x0c0c112cu: goto P_0c0c112c;
case 0x0c0c112eu: goto P_0c0c112e;
case 0x0c0c1130u: goto P_0c0c1130;
case 0x0c0c1132u: goto P_0c0c1132;
case 0x0c0c1134u: goto P_0c0c1134;
case 0x0c0c1136u: goto P_0c0c1136;
case 0x0c0c1138u: goto P_0c0c1138;
case 0x0c0c113au: goto P_0c0c113a;
case 0x0c0c113cu: goto P_0c0c113c;
case 0x0c0c113eu: goto P_0c0c113e;
case 0x0c0c1140u: goto P_0c0c1140;
case 0x0c0c1142u: goto P_0c0c1142;
case 0x0c0c1144u: goto P_0c0c1144;
case 0x0c0c1146u: goto P_0c0c1146;
case 0x0c0c1148u: goto P_0c0c1148;
case 0x0c0c114au: goto P_0c0c114a;
case 0x0c0c114cu: goto P_0c0c114c;
case 0x0c0c114eu: goto P_0c0c114e;
case 0x0c0c1150u: goto P_0c0c1150;
case 0x0c0c1152u: goto P_0c0c1152;
case 0x0c0c1154u: goto P_0c0c1154;
case 0x0c0c1156u: goto P_0c0c1156;
case 0x0c0c1158u: goto P_0c0c1158;
case 0x0c0c115au: goto P_0c0c115a;
case 0x0c0c115cu: goto P_0c0c115c;
case 0x0c0c115eu: goto P_0c0c115e;
case 0x0c0c1160u: goto P_0c0c1160;
case 0x0c0c1162u: goto P_0c0c1162;
case 0x0c0c1164u: goto P_0c0c1164;
case 0x0c0c1166u: goto P_0c0c1166;
case 0x0c0c1168u: goto P_0c0c1168;
case 0x0c0c116au: goto P_0c0c116a;
case 0x0c0c116cu: goto P_0c0c116c;
case 0x0c0c116eu: goto P_0c0c116e;
case 0x0c0c1170u: goto P_0c0c1170;
case 0x0c0c1172u: goto P_0c0c1172;
case 0x0c0c1174u: goto P_0c0c1174;
case 0x0c0c1176u: goto P_0c0c1176;
case 0x0c0c1178u: goto P_0c0c1178;
case 0x0c0c117au: goto P_0c0c117a;
case 0x0c0c117cu: goto P_0c0c117c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07b71c: /* original 000b, guest PC 0x0c07b71c */
if(!s->budget--) { s->failed_pc=0x0c07b71cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07b71e: /* original 0009, guest PC 0x0c07b71e */
if(!s->budget--) { s->failed_pc=0x0c07b71eu; return 0; }
if(!vf3_matrix_family(0x0c07b720u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b720u; return 0; } return 1;
P_0c0a7f14: /* original 2fe6, guest PC 0x0c0a7f14 */
if(!s->budget--) { s->failed_pc=0x0c0a7f14u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f16;
P_0c0a7f16: /* original d324, guest PC 0x0c0a7f16 */
if(!s->budget--) { s->failed_pc=0x0c0a7f16u; return 0; }
r[3]=read(ram,0x0c0a7fa8u,4);
goto P_0c0a7f18;
P_0c0a7f18: /* original 4f12, guest PC 0x0c0a7f18 */
if(!s->budget--) { s->failed_pc=0x0c0a7f18u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a7f1a;
P_0c0a7f1a: /* original 6632, guest PC 0x0c0a7f1a */
if(!s->budget--) { s->failed_pc=0x0c0a7f1au; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c0a7f1c;
P_0c0a7f1c: /* original 856d, guest PC 0x0c0a7f1c */
if(!s->budget--) { s->failed_pc=0x0c0a7f1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+26,2);
goto P_0c0a7f1e;
P_0c0a7f1e: /* original 670d, guest PC 0x0c0a7f1e */
if(!s->budget--) { s->failed_pc=0x0c0a7f1eu; return 0; }
r[7]=r[0]&65535u;
goto P_0c0a7f20;
P_0c0a7f20: /* original a012, guest PC 0x0c0a7f20 */
if(!s->budget--) { s->failed_pc=0x0c0a7f20u; return 0; }
r[14]=0x0000001fu;
goto P_0c0a7f48;
P_0c0a7f22: /* original ee1f, guest PC 0x0c0a7f22 */
if(!s->budget--) { s->failed_pc=0x0c0a7f22u; return 0; }
r[14]=0x0000001fu;
goto P_0c0a7f24;
P_0c0a7f24: /* original 856b, guest PC 0x0c0a7f24 */
if(!s->budget--) { s->failed_pc=0x0c0a7f24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+22,2);
goto P_0c0a7f26;
P_0c0a7f26: /* original 600d, guest PC 0x0c0a7f26 */
if(!s->budget--) { s->failed_pc=0x0c0a7f26u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a7f28;
P_0c0a7f28: /* original 3500, guest PC 0x0c0a7f28 */
if(!s->budget--) { s->failed_pc=0x0c0a7f28u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[0])!=0);
goto P_0c0a7f2a;
P_0c0a7f2a: /* original 8910, guest PC 0x0c0a7f2a */
if(!s->budget--) { s->failed_pc=0x0c0a7f2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7f4e; }
goto P_0c0a7f2c;
P_0c0a7f2c: /* original e334, guest PC 0x0c0a7f2c */
if(!s->budget--) { s->failed_pc=0x0c0a7f2cu; return 0; }
r[3]=0x00000034u;
goto P_0c0a7f2e;
P_0c0a7f2e: /* original 6263, guest PC 0x0c0a7f2e */
if(!s->budget--) { s->failed_pc=0x0c0a7f2eu; return 0; }
r[2]=r[6];
goto P_0c0a7f30;
P_0c0a7f30: /* original 253f, guest PC 0x0c0a7f30 */
if(!s->budget--) { s->failed_pc=0x0c0a7f30u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[5]*(int32_t)(int16_t)r[3]);
goto P_0c0a7f32;
P_0c0a7f32: /* original 721c, guest PC 0x0c0a7f32 */
if(!s->budget--) { s->failed_pc=0x0c0a7f32u; return 0; }
r[2]+=0x0000001cu;
goto P_0c0a7f34;
P_0c0a7f34: /* original e030, guest PC 0x0c0a7f34 */
if(!s->budget--) { s->failed_pc=0x0c0a7f34u; return 0; }
r[0]=0x00000030u;
goto P_0c0a7f36;
P_0c0a7f36: /* original 051a, guest PC 0x0c0a7f36 */
if(!s->budget--) { s->failed_pc=0x0c0a7f36u; return 0; }
r[5]=r[19];
goto P_0c0a7f38;
P_0c0a7f38: /* original 655f, guest PC 0x0c0a7f38 */
if(!s->budget--) { s->failed_pc=0x0c0a7f38u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c0a7f3a;
P_0c0a7f3a: /* original 352c, guest PC 0x0c0a7f3a */
if(!s->budget--) { s->failed_pc=0x0c0a7f3au; return 0; }
r[5]+=r[2];
goto P_0c0a7f3c;
P_0c0a7f3c: /* original 015d, guest PC 0x0c0a7f3c */
if(!s->budget--) { s->failed_pc=0x0c0a7f3cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0a7f3e;
P_0c0a7f3e: /* original 3140, guest PC 0x0c0a7f3e */
if(!s->budget--) { s->failed_pc=0x0c0a7f3eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[4])!=0);
goto P_0c0a7f40;
P_0c0a7f40: /* original 8b01, guest PC 0x0c0a7f40 */
if(!s->budget--) { s->failed_pc=0x0c0a7f40u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7f46; }
goto P_0c0a7f42;
P_0c0a7f42: /* original a005, guest PC 0x0c0a7f42 */
if(!s->budget--) { s->failed_pc=0x0c0a7f42u; return 0; }
r[0]=0x00000001u;
goto P_0c0a7f50;
P_0c0a7f44: /* original e001, guest PC 0x0c0a7f44 */
if(!s->budget--) { s->failed_pc=0x0c0a7f44u; return 0; }
r[0]=0x00000001u;
goto P_0c0a7f46;
P_0c0a7f46: /* original 77ff, guest PC 0x0c0a7f46 */
if(!s->budget--) { s->failed_pc=0x0c0a7f46u; return 0; }
r[7]+=0xffffffffu;
goto P_0c0a7f48;
P_0c0a7f48: /* original 6573, guest PC 0x0c0a7f48 */
if(!s->budget--) { s->failed_pc=0x0c0a7f48u; return 0; }
r[5]=r[7];
goto P_0c0a7f4a;
P_0c0a7f4a: /* original afeb, guest PC 0x0c0a7f4a */
if(!s->budget--) { s->failed_pc=0x0c0a7f4au; return 0; }
r[5]&=r[14];
goto P_0c0a7f24;
P_0c0a7f4c: /* original 25e9, guest PC 0x0c0a7f4c */
if(!s->budget--) { s->failed_pc=0x0c0a7f4cu; return 0; }
r[5]&=r[14];
goto P_0c0a7f4e;
P_0c0a7f4e: /* original e000, guest PC 0x0c0a7f4e */
if(!s->budget--) { s->failed_pc=0x0c0a7f4eu; return 0; }
r[0]=0x00000000u;
goto P_0c0a7f50;
P_0c0a7f50: /* original 4f16, guest PC 0x0c0a7f50 */
if(!s->budget--) { s->failed_pc=0x0c0a7f50u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7f52;
P_0c0a7f52: /* original 000b, guest PC 0x0c0a7f52 */
if(!s->budget--) { s->failed_pc=0x0c0a7f52u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a7f54: /* original 6ef6, guest PC 0x0c0a7f54 */
if(!s->budget--) { s->failed_pc=0x0c0a7f54u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a7f56u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7f56u; return 0; } return 1;
P_0c0a81ee: /* original 2fe6, guest PC 0x0c0a81ee */
if(!s->budget--) { s->failed_pc=0x0c0a81eeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f0;
P_0c0a81f0: /* original 2fd6, guest PC 0x0c0a81f0 */
if(!s->budget--) { s->failed_pc=0x0c0a81f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f2;
P_0c0a81f2: /* original 2fc6, guest PC 0x0c0a81f2 */
if(!s->budget--) { s->failed_pc=0x0c0a81f2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f4;
P_0c0a81f4: /* original 2fb6, guest PC 0x0c0a81f4 */
if(!s->budget--) { s->failed_pc=0x0c0a81f4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f6;
P_0c0a81f6: /* original 6b43, guest PC 0x0c0a81f6 */
if(!s->budget--) { s->failed_pc=0x0c0a81f6u; return 0; }
r[11]=r[4];
goto P_0c0a81f8;
P_0c0a81f8: /* original 2fa6, guest PC 0x0c0a81f8 */
if(!s->budget--) { s->failed_pc=0x0c0a81f8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81fa;
P_0c0a81fa: /* original eaff, guest PC 0x0c0a81fa */
if(!s->budget--) { s->failed_pc=0x0c0a81fau; return 0; }
r[10]=0xffffffffu;
goto P_0c0a81fc;
P_0c0a81fc: /* original 4f22, guest PC 0x0c0a81fc */
if(!s->budget--) { s->failed_pc=0x0c0a81fcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a81fe;
P_0c0a81fe: /* original 4f12, guest PC 0x0c0a81fe */
if(!s->budget--) { s->failed_pc=0x0c0a81feu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a8200;
P_0c0a8200: /* original 7ff0, guest PC 0x0c0a8200 */
if(!s->budget--) { s->failed_pc=0x0c0a8200u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0a8202;
P_0c0a8202: /* original 1f51, guest PC 0x0c0a8202 */
if(!s->budget--) { s->failed_pc=0x0c0a8202u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0a8204;
P_0c0a8204: /* original 2f62, guest PC 0x0c0a8204 */
if(!s->budget--) { s->failed_pc=0x0c0a8204u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0a8206;
P_0c0a8206: /* original 1f72, guest PC 0x0c0a8206 */
if(!s->budget--) { s->failed_pc=0x0c0a8206u; return 0; }
write(ram,r[15]+8,r[7],4);
goto P_0c0a8208;
P_0c0a8208: /* original d32a, guest PC 0x0c0a8208 */
if(!s->budget--) { s->failed_pc=0x0c0a8208u; return 0; }
r[3]=read(ram,0x0c0a82b4u,4);
goto P_0c0a820a;
P_0c0a820a: /* original 9249, guest PC 0x0c0a820a */
if(!s->budget--) { s->failed_pc=0x0c0a820au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a82a0u,2);
goto P_0c0a820c;
P_0c0a820c: /* original 6e32, guest PC 0x0c0a820c */
if(!s->budget--) { s->failed_pc=0x0c0a820cu; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c0a820e;
P_0c0a820e: /* original 3b23, guest PC 0x0c0a820e */
if(!s->budget--) { s->failed_pc=0x0c0a820eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[2])!=0);
goto P_0c0a8210;
P_0c0a8210: /* original 8f03, guest PC 0x0c0a8210 */
if(!s->budget--) { s->failed_pc=0x0c0a8210u; return 0; }
cond=r[17]&1u;
r[12]=r[10];
if(!cond) { goto P_0c0a821a; }
goto P_0c0a8214;
P_0c0a8212: /* original 6ca3, guest PC 0x0c0a8212 */
if(!s->budget--) { s->failed_pc=0x0c0a8212u; return 0; }
r[12]=r[10];
goto P_0c0a8214;
P_0c0a8214: /* original dc28, guest PC 0x0c0a8214 */
if(!s->budget--) { s->failed_pc=0x0c0a8214u; return 0; }
r[12]=read(ram,0x0c0a82b8u,4);
goto P_0c0a8216;
P_0c0a8216: /* original a037, guest PC 0x0c0a8216 */
if(!s->budget--) { s->failed_pc=0x0c0a8216u; return 0; }
goto P_0c0a8288;
P_0c0a8218: /* original 0009, guest PC 0x0c0a8218 */
if(!s->budget--) { s->failed_pc=0x0c0a8218u; return 0; }
goto P_0c0a821a;
P_0c0a821a: /* original d028, guest PC 0x0c0a821a */
if(!s->budget--) { s->failed_pc=0x0c0a821au; return 0; }
r[0]=read(ram,0x0c0a82bcu,4);
goto P_0c0a821c;
P_0c0a821c: /* original 63b3, guest PC 0x0c0a821c */
if(!s->budget--) { s->failed_pc=0x0c0a821cu; return 0; }
r[3]=r[11];
goto P_0c0a821e;
P_0c0a821e: /* original 4308, guest PC 0x0c0a821e */
if(!s->budget--) { s->failed_pc=0x0c0a821eu; return 0; }
r[3]<<=2;
goto P_0c0a8220;
P_0c0a8220: /* original 023e, guest PC 0x0c0a8220 */
if(!s->budget--) { s->failed_pc=0x0c0a8220u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0a8222;
P_0c0a8222: /* original 1f23, guest PC 0x0c0a8222 */
if(!s->budget--) { s->failed_pc=0x0c0a8222u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0a8224;
P_0c0a8224: /* original 63f2, guest PC 0x0c0a8224 */
if(!s->budget--) { s->failed_pc=0x0c0a8224u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a8226;
P_0c0a8226: /* original 2338, guest PC 0x0c0a8226 */
if(!s->budget--) { s->failed_pc=0x0c0a8226u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a8228;
P_0c0a8228: /* original 892e, guest PC 0x0c0a8228 */
if(!s->budget--) { s->failed_pc=0x0c0a8228u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8288; }
goto P_0c0a822a;
P_0c0a822a: /* original 50f1, guest PC 0x0c0a822a */
if(!s->budget--) { s->failed_pc=0x0c0a822au; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0a822c;
P_0c0a822c: /* original c803, guest PC 0x0c0a822c */
if(!s->budget--) { s->failed_pc=0x0c0a822cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&3u)==0)!=0);
goto P_0c0a822e;
P_0c0a822e: /* original 8b2b, guest PC 0x0c0a822e */
if(!s->budget--) { s->failed_pc=0x0c0a822eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8288; }
goto P_0c0a8230;
P_0c0a8230: /* original 85ed, guest PC 0x0c0a8230 */
if(!s->budget--) { s->failed_pc=0x0c0a8230u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+26,2);
goto P_0c0a8232;
P_0c0a8232: /* original ed1f, guest PC 0x0c0a8232 */
if(!s->budget--) { s->failed_pc=0x0c0a8232u; return 0; }
r[13]=0x0000001fu;
goto P_0c0a8234;
P_0c0a8234: /* original 600d, guest PC 0x0c0a8234 */
if(!s->budget--) { s->failed_pc=0x0c0a8234u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a8236;
P_0c0a8236: /* original 7001, guest PC 0x0c0a8236 */
if(!s->budget--) { s->failed_pc=0x0c0a8236u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a8238;
P_0c0a8238: /* original 2d09, guest PC 0x0c0a8238 */
if(!s->budget--) { s->failed_pc=0x0c0a8238u; return 0; }
r[13]&=r[0];
goto P_0c0a823a;
P_0c0a823a: /* original 85eb, guest PC 0x0c0a823a */
if(!s->budget--) { s->failed_pc=0x0c0a823au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a823c;
P_0c0a823c: /* original 600d, guest PC 0x0c0a823c */
if(!s->budget--) { s->failed_pc=0x0c0a823cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a823e;
P_0c0a823e: /* original 3d00, guest PC 0x0c0a823e */
if(!s->budget--) { s->failed_pc=0x0c0a823eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[0])!=0);
goto P_0c0a8240;
P_0c0a8240: /* original 8922, guest PC 0x0c0a8240 */
if(!s->budget--) { s->failed_pc=0x0c0a8240u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8288; }
goto P_0c0a8242;
P_0c0a8242: /* original be67, guest PC 0x0c0a8242 */
if(!s->budget--) { s->failed_pc=0x0c0a8242u; return 0; }
target=code_base|0x0c0a7f14u; r[16]=code_base|0x0c0a8246u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8246u) { target=s->pc; goto dispatch; }
goto P_0c0a8246;
P_0c0a8244: /* original 64b3, guest PC 0x0c0a8244 */
if(!s->budget--) { s->failed_pc=0x0c0a8244u; return 0; }
r[4]=r[11];
goto P_0c0a8246;
P_0c0a8246: /* original 2008, guest PC 0x0c0a8246 */
if(!s->budget--) { s->failed_pc=0x0c0a8246u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a8248;
P_0c0a8248: /* original 8b1e, guest PC 0x0c0a8248 */
if(!s->budget--) { s->failed_pc=0x0c0a8248u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8288; }
goto P_0c0a824a;
P_0c0a824a: /* original e434, guest PC 0x0c0a824a */
if(!s->budget--) { s->failed_pc=0x0c0a824au; return 0; }
r[4]=0x00000034u;
goto P_0c0a824c;
P_0c0a824c: /* original 63e3, guest PC 0x0c0a824c */
if(!s->budget--) { s->failed_pc=0x0c0a824cu; return 0; }
r[3]=r[14];
goto P_0c0a824e;
P_0c0a824e: /* original 2d4f, guest PC 0x0c0a824e */
if(!s->budget--) { s->failed_pc=0x0c0a824eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[4]);
goto P_0c0a8250;
P_0c0a8250: /* original 731c, guest PC 0x0c0a8250 */
if(!s->budget--) { s->failed_pc=0x0c0a8250u; return 0; }
r[3]+=0x0000001cu;
goto P_0c0a8252;
P_0c0a8252: /* original 60d3, guest PC 0x0c0a8252 */
if(!s->budget--) { s->failed_pc=0x0c0a8252u; return 0; }
r[0]=r[13];
goto P_0c0a8254;
P_0c0a8254: /* original 81ed, guest PC 0x0c0a8254 */
if(!s->budget--) { s->failed_pc=0x0c0a8254u; return 0; }
write(ram,r[14]+26,r[0],2);
goto P_0c0a8256;
P_0c0a8256: /* original e030, guest PC 0x0c0a8256 */
if(!s->budget--) { s->failed_pc=0x0c0a8256u; return 0; }
r[0]=0x00000030u;
goto P_0c0a8258;
P_0c0a8258: /* original 62f2, guest PC 0x0c0a8258 */
if(!s->budget--) { s->failed_pc=0x0c0a8258u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a825a;
P_0c0a825a: /* original 6cd3, guest PC 0x0c0a825a */
if(!s->budget--) { s->failed_pc=0x0c0a825au; return 0; }
r[12]=r[13];
goto P_0c0a825c;
P_0c0a825c: /* original 041a, guest PC 0x0c0a825c */
if(!s->budget--) { s->failed_pc=0x0c0a825cu; return 0; }
r[4]=r[19];
goto P_0c0a825e;
P_0c0a825e: /* original 644f, guest PC 0x0c0a825e */
if(!s->budget--) { s->failed_pc=0x0c0a825eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0a8260;
P_0c0a8260: /* original 343c, guest PC 0x0c0a8260 */
if(!s->budget--) { s->failed_pc=0x0c0a8260u; return 0; }
r[4]+=r[3];
goto P_0c0a8262;
P_0c0a8262: /* original 6323, guest PC 0x0c0a8262 */
if(!s->budget--) { s->failed_pc=0x0c0a8262u; return 0; }
r[3]=r[2];
goto P_0c0a8264;
P_0c0a8264: /* original 2422, guest PC 0x0c0a8264 */
if(!s->budget--) { s->failed_pc=0x0c0a8264u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c0a8266;
P_0c0a8266: /* original e200, guest PC 0x0c0a8266 */
if(!s->budget--) { s->failed_pc=0x0c0a8266u; return 0; }
r[2]=0x00000000u;
goto P_0c0a8268;
P_0c0a8268: /* original 2322, guest PC 0x0c0a8268 */
if(!s->budget--) { s->failed_pc=0x0c0a8268u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0a826a;
P_0c0a826a: /* original 53f1, guest PC 0x0c0a826a */
if(!s->budget--) { s->failed_pc=0x0c0a826au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a826c;
P_0c0a826c: /* original 1431, guest PC 0x0c0a826c */
if(!s->budget--) { s->failed_pc=0x0c0a826cu; return 0; }
write(ram,r[4]+4,r[3],4);
goto P_0c0a826e;
P_0c0a826e: /* original 14a7, guest PC 0x0c0a826e */
if(!s->budget--) { s->failed_pc=0x0c0a826eu; return 0; }
write(ram,r[4]+28,r[10],4);
goto P_0c0a8270;
P_0c0a8270: /* original 14a2, guest PC 0x0c0a8270 */
if(!s->budget--) { s->failed_pc=0x0c0a8270u; return 0; }
write(ram,r[4]+8,r[10],4);
goto P_0c0a8272;
P_0c0a8272: /* original 53f3, guest PC 0x0c0a8272 */
if(!s->budget--) { s->failed_pc=0x0c0a8272u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0a8274;
P_0c0a8274: /* original 1434, guest PC 0x0c0a8274 */
if(!s->budget--) { s->failed_pc=0x0c0a8274u; return 0; }
write(ram,r[4]+16,r[3],4);
goto P_0c0a8276;
P_0c0a8276: /* original 52f2, guest PC 0x0c0a8276 */
if(!s->budget--) { s->failed_pc=0x0c0a8276u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0a8278;
P_0c0a8278: /* original 1425, guest PC 0x0c0a8278 */
if(!s->budget--) { s->failed_pc=0x0c0a8278u; return 0; }
write(ram,r[4]+20,r[2],4);
goto P_0c0a827a;
P_0c0a827a: /* original 53fb, guest PC 0x0c0a827a */
if(!s->budget--) { s->failed_pc=0x0c0a827au; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c0a827c;
P_0c0a827c: /* original 1436, guest PC 0x0c0a827c */
if(!s->budget--) { s->failed_pc=0x0c0a827cu; return 0; }
write(ram,r[4]+24,r[3],4);
goto P_0c0a827e;
P_0c0a827e: /* original 52fc, guest PC 0x0c0a827e */
if(!s->budget--) { s->failed_pc=0x0c0a827eu; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c0a8280;
P_0c0a8280: /* original 142a, guest PC 0x0c0a8280 */
if(!s->budget--) { s->failed_pc=0x0c0a8280u; return 0; }
write(ram,r[4]+40,r[2],4);
goto P_0c0a8282;
P_0c0a8282: /* original 53fd, guest PC 0x0c0a8282 */
if(!s->budget--) { s->failed_pc=0x0c0a8282u; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c0a8284;
P_0c0a8284: /* original 143b, guest PC 0x0c0a8284 */
if(!s->budget--) { s->failed_pc=0x0c0a8284u; return 0; }
write(ram,r[4]+44,r[3],4);
goto P_0c0a8286;
P_0c0a8286: /* original 04b5, guest PC 0x0c0a8286 */
if(!s->budget--) { s->failed_pc=0x0c0a8286u; return 0; }
write(ram,r[4]+r[0],r[11],2);
goto P_0c0a8288;
P_0c0a8288: /* original 7f10, guest PC 0x0c0a8288 */
if(!s->budget--) { s->failed_pc=0x0c0a8288u; return 0; }
r[15]+=0x00000010u;
goto P_0c0a828a;
P_0c0a828a: /* original 60c3, guest PC 0x0c0a828a */
if(!s->budget--) { s->failed_pc=0x0c0a828au; return 0; }
r[0]=r[12];
goto P_0c0a828c;
P_0c0a828c: /* original 4f16, guest PC 0x0c0a828c */
if(!s->budget--) { s->failed_pc=0x0c0a828cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a828e;
P_0c0a828e: /* original 4f26, guest PC 0x0c0a828e */
if(!s->budget--) { s->failed_pc=0x0c0a828eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8290;
P_0c0a8290: /* original 6af6, guest PC 0x0c0a8290 */
if(!s->budget--) { s->failed_pc=0x0c0a8290u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a8292;
P_0c0a8292: /* original 6bf6, guest PC 0x0c0a8292 */
if(!s->budget--) { s->failed_pc=0x0c0a8292u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8294;
P_0c0a8294: /* original 6cf6, guest PC 0x0c0a8294 */
if(!s->budget--) { s->failed_pc=0x0c0a8294u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8296;
P_0c0a8296: /* original 6df6, guest PC 0x0c0a8296 */
if(!s->budget--) { s->failed_pc=0x0c0a8296u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8298;
P_0c0a8298: /* original 000b, guest PC 0x0c0a8298 */
if(!s->budget--) { s->failed_pc=0x0c0a8298u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a829a: /* original 6ef6, guest PC 0x0c0a829a */
if(!s->budget--) { s->failed_pc=0x0c0a829au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a829cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a829cu; return 0; } return 1;
P_0c0c10a2: /* original 2fe6, guest PC 0x0c0c10a2 */
if(!s->budget--) { s->failed_pc=0x0c0c10a2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c10a4;
P_0c0c10a4: /* original e600, guest PC 0x0c0c10a4 */
if(!s->budget--) { s->failed_pc=0x0c0c10a4u; return 0; }
r[6]=0x00000000u;
goto P_0c0c10a6;
P_0c0c10a6: /* original 2fd6, guest PC 0x0c0c10a6 */
if(!s->budget--) { s->failed_pc=0x0c0c10a6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c10a8;
P_0c0c10a8: /* original d54d, guest PC 0x0c0c10a8 */
if(!s->budget--) { s->failed_pc=0x0c0c10a8u; return 0; }
r[5]=read(ram,0x0c0c11e0u,4);
goto P_0c0c10aa;
P_0c0c10aa: /* original 7ff0, guest PC 0x0c0c10aa */
if(!s->budget--) { s->failed_pc=0x0c0c10aau; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0c10ac;
P_0c0c10ac: /* original 6353, guest PC 0x0c0c10ac */
if(!s->budget--) { s->failed_pc=0x0c0c10acu; return 0; }
r[3]=r[5];
goto P_0c0c10ae;
P_0c0c10ae: /* original 7358, guest PC 0x0c0c10ae */
if(!s->budget--) { s->failed_pc=0x0c0c10aeu; return 0; }
r[3]+=0x00000058u;
goto P_0c0c10b0;
P_0c0c10b0: /* original 6253, guest PC 0x0c0c10b0 */
if(!s->budget--) { s->failed_pc=0x0c0c10b0u; return 0; }
r[2]=r[5];
goto P_0c0c10b2;
P_0c0c10b2: /* original 722c, guest PC 0x0c0c10b2 */
if(!s->budget--) { s->failed_pc=0x0c0c10b2u; return 0; }
r[2]+=0x0000002cu;
goto P_0c0c10b4;
P_0c0c10b4: /* original 2f52, guest PC 0x0c0c10b4 */
if(!s->budget--) { s->failed_pc=0x0c0c10b4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c10b6;
P_0c0c10b6: /* original 1f31, guest PC 0x0c0c10b6 */
if(!s->budget--) { s->failed_pc=0x0c0c10b6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c10b8;
P_0c0c10b8: /* original 1f23, guest PC 0x0c0c10b8 */
if(!s->budget--) { s->failed_pc=0x0c0c10b8u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0c10ba;
P_0c0c10ba: /* original 9388, guest PC 0x0c0c10ba */
if(!s->budget--) { s->failed_pc=0x0c0c10bau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11ceu,2);
goto P_0c0c10bc;
P_0c0c10bc: /* original 335c, guest PC 0x0c0c10bc */
if(!s->budget--) { s->failed_pc=0x0c0c10bcu; return 0; }
r[3]+=r[5];
goto P_0c0c10be;
P_0c0c10be: /* original 1f32, guest PC 0x0c0c10be */
if(!s->budget--) { s->failed_pc=0x0c0c10beu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0c10c0;
P_0c0c10c0: /* original 9286, guest PC 0x0c0c10c0 */
if(!s->budget--) { s->failed_pc=0x0c0c10c0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11d0u,2);
goto P_0c0c10c2;
P_0c0c10c2: /* original 2248, guest PC 0x0c0c10c2 */
if(!s->budget--) { s->failed_pc=0x0c0c10c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0c10c4;
P_0c0c10c4: /* original 8d03, guest PC 0x0c0c10c4 */
if(!s->budget--) { s->failed_pc=0x0c0c10c4u; return 0; }
cond=r[17]&1u;
r[5]=0x00000004u;
if(cond) { goto P_0c0c10ce; }
goto P_0c0c10c8;
P_0c0c10c6: /* original e504, guest PC 0x0c0c10c6 */
if(!s->budget--) { s->failed_pc=0x0c0c10c6u; return 0; }
r[5]=0x00000004u;
goto P_0c0c10c8;
P_0c0c10c8: /* original 6763, guest PC 0x0c0c10c8 */
if(!s->budget--) { s->failed_pc=0x0c0c10c8u; return 0; }
r[7]=r[6];
goto P_0c0c10ca;
P_0c0c10ca: /* original a002, guest PC 0x0c0c10ca */
if(!s->budget--) { s->failed_pc=0x0c0c10cau; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10d2;
P_0c0c10cc: /* original 7601, guest PC 0x0c0c10cc */
if(!s->budget--) { s->failed_pc=0x0c0c10ccu; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10ce;
P_0c0c10ce: /* original 6753, guest PC 0x0c0c10ce */
if(!s->budget--) { s->failed_pc=0x0c0c10ceu; return 0; }
r[7]=r[5];
goto P_0c0c10d0;
P_0c0c10d0: /* original 7501, guest PC 0x0c0c10d0 */
if(!s->budget--) { s->failed_pc=0x0c0c10d0u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c10d2;
P_0c0c10d2: /* original 937e, guest PC 0x0c0c10d2 */
if(!s->budget--) { s->failed_pc=0x0c0c10d2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11d2u,2);
goto P_0c0c10d4;
P_0c0c10d4: /* original 2348, guest PC 0x0c0c10d4 */
if(!s->budget--) { s->failed_pc=0x0c0c10d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0c10d6;
P_0c0c10d6: /* original 8902, guest PC 0x0c0c10d6 */
if(!s->budget--) { s->failed_pc=0x0c0c10d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c10de; }
goto P_0c0c10d8;
P_0c0c10d8: /* original 6d63, guest PC 0x0c0c10d8 */
if(!s->budget--) { s->failed_pc=0x0c0c10d8u; return 0; }
r[13]=r[6];
goto P_0c0c10da;
P_0c0c10da: /* original a002, guest PC 0x0c0c10da */
if(!s->budget--) { s->failed_pc=0x0c0c10dau; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10e2;
P_0c0c10dc: /* original 7601, guest PC 0x0c0c10dc */
if(!s->budget--) { s->failed_pc=0x0c0c10dcu; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10de;
P_0c0c10de: /* original 6d53, guest PC 0x0c0c10de */
if(!s->budget--) { s->failed_pc=0x0c0c10deu; return 0; }
r[13]=r[5];
goto P_0c0c10e0;
P_0c0c10e0: /* original 7501, guest PC 0x0c0c10e0 */
if(!s->budget--) { s->failed_pc=0x0c0c10e0u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c10e2;
P_0c0c10e2: /* original 9277, guest PC 0x0c0c10e2 */
if(!s->budget--) { s->failed_pc=0x0c0c10e2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11d4u,2);
goto P_0c0c10e4;
P_0c0c10e4: /* original 2248, guest PC 0x0c0c10e4 */
if(!s->budget--) { s->failed_pc=0x0c0c10e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0c10e6;
P_0c0c10e6: /* original 8902, guest PC 0x0c0c10e6 */
if(!s->budget--) { s->failed_pc=0x0c0c10e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c10ee; }
goto P_0c0c10e8;
P_0c0c10e8: /* original 6e63, guest PC 0x0c0c10e8 */
if(!s->budget--) { s->failed_pc=0x0c0c10e8u; return 0; }
r[14]=r[6];
goto P_0c0c10ea;
P_0c0c10ea: /* original a002, guest PC 0x0c0c10ea */
if(!s->budget--) { s->failed_pc=0x0c0c10eau; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10f2;
P_0c0c10ec: /* original 7601, guest PC 0x0c0c10ec */
if(!s->budget--) { s->failed_pc=0x0c0c10ecu; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10ee;
P_0c0c10ee: /* original 6e53, guest PC 0x0c0c10ee */
if(!s->budget--) { s->failed_pc=0x0c0c10eeu; return 0; }
r[14]=r[5];
goto P_0c0c10f0;
P_0c0c10f0: /* original 7501, guest PC 0x0c0c10f0 */
if(!s->budget--) { s->failed_pc=0x0c0c10f0u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c10f2;
P_0c0c10f2: /* original 9370, guest PC 0x0c0c10f2 */
if(!s->budget--) { s->failed_pc=0x0c0c10f2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11d6u,2);
goto P_0c0c10f4;
P_0c0c10f4: /* original 2438, guest PC 0x0c0c10f4 */
if(!s->budget--) { s->failed_pc=0x0c0c10f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c10f6;
P_0c0c10f6: /* original 8901, guest PC 0x0c0c10f6 */
if(!s->budget--) { s->failed_pc=0x0c0c10f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c10fc; }
goto P_0c0c10f8;
P_0c0c10f8: /* original a001, guest PC 0x0c0c10f8 */
if(!s->budget--) { s->failed_pc=0x0c0c10f8u; return 0; }
r[4]=r[6];
goto P_0c0c10fe;
P_0c0c10fa: /* original 6463, guest PC 0x0c0c10fa */
if(!s->budget--) { s->failed_pc=0x0c0c10fau; return 0; }
r[4]=r[6];
goto P_0c0c10fc;
P_0c0c10fc: /* original 6453, guest PC 0x0c0c10fc */
if(!s->budget--) { s->failed_pc=0x0c0c10fcu; return 0; }
r[4]=r[5];
goto P_0c0c10fe;
P_0c0c10fe: /* original 63f2, guest PC 0x0c0c10fe */
if(!s->budget--) { s->failed_pc=0x0c0c10feu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c1100;
P_0c0c1100: /* original e026, guest PC 0x0c0c1100 */
if(!s->budget--) { s->failed_pc=0x0c0c1100u; return 0; }
r[0]=0x00000026u;
goto P_0c0c1102;
P_0c0c1102: /* original 0375, guest PC 0x0c0c1102 */
if(!s->budget--) { s->failed_pc=0x0c0c1102u; return 0; }
write(ram,r[3]+r[0],r[7],2);
goto P_0c0c1104;
P_0c0c1104: /* original e026, guest PC 0x0c0c1104 */
if(!s->budget--) { s->failed_pc=0x0c0c1104u; return 0; }
r[0]=0x00000026u;
goto P_0c0c1106;
P_0c0c1106: /* original 53f3, guest PC 0x0c0c1106 */
if(!s->budget--) { s->failed_pc=0x0c0c1106u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0c1108;
P_0c0c1108: /* original 03d5, guest PC 0x0c0c1108 */
if(!s->budget--) { s->failed_pc=0x0c0c1108u; return 0; }
write(ram,r[3]+r[0],r[13],2);
goto P_0c0c110a;
P_0c0c110a: /* original e026, guest PC 0x0c0c110a */
if(!s->budget--) { s->failed_pc=0x0c0c110au; return 0; }
r[0]=0x00000026u;
goto P_0c0c110c;
P_0c0c110c: /* original 53f1, guest PC 0x0c0c110c */
if(!s->budget--) { s->failed_pc=0x0c0c110cu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c110e;
P_0c0c110e: /* original 03e5, guest PC 0x0c0c110e */
if(!s->budget--) { s->failed_pc=0x0c0c110eu; return 0; }
write(ram,r[3]+r[0],r[14],2);
goto P_0c0c1110;
P_0c0c1110: /* original e026, guest PC 0x0c0c1110 */
if(!s->budget--) { s->failed_pc=0x0c0c1110u; return 0; }
r[0]=0x00000026u;
goto P_0c0c1112;
P_0c0c1112: /* original 53f2, guest PC 0x0c0c1112 */
if(!s->budget--) { s->failed_pc=0x0c0c1112u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c1114;
P_0c0c1114: /* original 7f10, guest PC 0x0c0c1114 */
if(!s->budget--) { s->failed_pc=0x0c0c1114u; return 0; }
r[15]+=0x00000010u;
goto P_0c0c1116;
P_0c0c1116: /* original 0345, guest PC 0x0c0c1116 */
if(!s->budget--) { s->failed_pc=0x0c0c1116u; return 0; }
write(ram,r[3]+r[0],r[4],2);
goto P_0c0c1118;
P_0c0c1118: /* original 6df6, guest PC 0x0c0c1118 */
if(!s->budget--) { s->failed_pc=0x0c0c1118u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c111a;
P_0c0c111a: /* original 000b, guest PC 0x0c0c111a */
if(!s->budget--) { s->failed_pc=0x0c0c111au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c111c: /* original 6ef6, guest PC 0x0c0c111c */
if(!s->budget--) { s->failed_pc=0x0c0c111cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c111e;
P_0c0c111e: /* original 4f22, guest PC 0x0c0c111e */
if(!s->budget--) { s->failed_pc=0x0c0c111eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c1120;
P_0c0c1120: /* original e022, guest PC 0x0c0c1120 */
if(!s->budget--) { s->failed_pc=0x0c0c1120u; return 0; }
r[0]=0x00000022u;
goto P_0c0c1122;
P_0c0c1122: /* original 7ff0, guest PC 0x0c0c1122 */
if(!s->budget--) { s->failed_pc=0x0c0c1122u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0c1124;
P_0c0c1124: /* original 2f52, guest PC 0x0c0c1124 */
if(!s->budget--) { s->failed_pc=0x0c0c1124u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c1126;
P_0c0c1126: /* original 1f61, guest PC 0x0c0c1126 */
if(!s->budget--) { s->failed_pc=0x0c0c1126u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0c1128;
P_0c0c1128: /* original d52d, guest PC 0x0c0c1128 */
if(!s->budget--) { s->failed_pc=0x0c0c1128u; return 0; }
r[5]=read(ram,0x0c0c11e0u,4);
goto P_0c0c112a;
P_0c0c112a: /* original 6353, guest PC 0x0c0c112a */
if(!s->budget--) { s->failed_pc=0x0c0c112au; return 0; }
r[3]=r[5];
goto P_0c0c112c;
P_0c0c112c: /* original 7358, guest PC 0x0c0c112c */
if(!s->budget--) { s->failed_pc=0x0c0c112cu; return 0; }
r[3]+=0x00000058u;
goto P_0c0c112e;
P_0c0c112e: /* original 1f32, guest PC 0x0c0c112e */
if(!s->budget--) { s->failed_pc=0x0c0c112eu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0c1130;
P_0c0c1130: /* original 6753, guest PC 0x0c0c1130 */
if(!s->budget--) { s->failed_pc=0x0c0c1130u; return 0; }
r[7]=r[5];
goto P_0c0c1132;
P_0c0c1132: /* original 6273, guest PC 0x0c0c1132 */
if(!s->budget--) { s->failed_pc=0x0c0c1132u; return 0; }
r[2]=r[7];
goto P_0c0c1134;
P_0c0c1134: /* original 722c, guest PC 0x0c0c1134 */
if(!s->budget--) { s->failed_pc=0x0c0c1134u; return 0; }
r[2]+=0x0000002cu;
goto P_0c0c1136;
P_0c0c1136: /* original 1f23, guest PC 0x0c0c1136 */
if(!s->budget--) { s->failed_pc=0x0c0c1136u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0c1138;
P_0c0c1138: /* original 9649, guest PC 0x0c0c1138 */
if(!s->budget--) { s->failed_pc=0x0c0c1138u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11ceu,2);
goto P_0c0c113a;
P_0c0c113a: /* original 037d, guest PC 0x0c0c113a */
if(!s->budget--) { s->failed_pc=0x0c0c113au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+r[0],2);
goto P_0c0c113c;
P_0c0c113c: /* original 365c, guest PC 0x0c0c113c */
if(!s->budget--) { s->failed_pc=0x0c0c113cu; return 0; }
r[6]+=r[5];
goto P_0c0c113e;
P_0c0c113e: /* original d529, guest PC 0x0c0c113e */
if(!s->budget--) { s->failed_pc=0x0c0c113eu; return 0; }
r[5]=read(ram,0x0c0c11e4u,4);
goto P_0c0c1140;
P_0c0c1140: /* original 2359, guest PC 0x0c0c1140 */
if(!s->budget--) { s->failed_pc=0x0c0c1140u; return 0; }
r[3]&=r[5];
goto P_0c0c1142;
P_0c0c1142: /* original 0735, guest PC 0x0c0c1142 */
if(!s->budget--) { s->failed_pc=0x0c0c1142u; return 0; }
write(ram,r[7]+r[0],r[3],2);
goto P_0c0c1144;
P_0c0c1144: /* original e022, guest PC 0x0c0c1144 */
if(!s->budget--) { s->failed_pc=0x0c0c1144u; return 0; }
r[0]=0x00000022u;
goto P_0c0c1146;
P_0c0c1146: /* original 53f2, guest PC 0x0c0c1146 */
if(!s->budget--) { s->failed_pc=0x0c0c1146u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c1148;
P_0c0c1148: /* original 023d, guest PC 0x0c0c1148 */
if(!s->budget--) { s->failed_pc=0x0c0c1148u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c114a;
P_0c0c114a: /* original 2259, guest PC 0x0c0c114a */
if(!s->budget--) { s->failed_pc=0x0c0c114au; return 0; }
r[2]&=r[5];
goto P_0c0c114c;
P_0c0c114c: /* original 0325, guest PC 0x0c0c114c */
if(!s->budget--) { s->failed_pc=0x0c0c114cu; return 0; }
write(ram,r[3]+r[0],r[2],2);
goto P_0c0c114e;
P_0c0c114e: /* original e022, guest PC 0x0c0c114e */
if(!s->budget--) { s->failed_pc=0x0c0c114eu; return 0; }
r[0]=0x00000022u;
goto P_0c0c1150;
P_0c0c1150: /* original 53f3, guest PC 0x0c0c1150 */
if(!s->budget--) { s->failed_pc=0x0c0c1150u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0c1152;
P_0c0c1152: /* original 023d, guest PC 0x0c0c1152 */
if(!s->budget--) { s->failed_pc=0x0c0c1152u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c1154;
P_0c0c1154: /* original 2259, guest PC 0x0c0c1154 */
if(!s->budget--) { s->failed_pc=0x0c0c1154u; return 0; }
r[2]&=r[5];
goto P_0c0c1156;
P_0c0c1156: /* original 0325, guest PC 0x0c0c1156 */
if(!s->budget--) { s->failed_pc=0x0c0c1156u; return 0; }
write(ram,r[3]+r[0],r[2],2);
goto P_0c0c1158;
P_0c0c1158: /* original 036d, guest PC 0x0c0c1158 */
if(!s->budget--) { s->failed_pc=0x0c0c1158u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
goto P_0c0c115a;
P_0c0c115a: /* original 2359, guest PC 0x0c0c115a */
if(!s->budget--) { s->failed_pc=0x0c0c115au; return 0; }
r[3]&=r[5];
goto P_0c0c115c;
P_0c0c115c: /* original bfa1, guest PC 0x0c0c115c */
if(!s->budget--) { s->failed_pc=0x0c0c115cu; return 0; }
target=code_base|0x0c0c10a2u; r[16]=code_base|0x0c0c1160u;
write(ram,r[6]+r[0],r[3],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c1160u) { target=s->pc; goto dispatch; }
goto P_0c0c1160;
P_0c0c115e: /* original 0635, guest PC 0x0c0c115e */
if(!s->budget--) { s->failed_pc=0x0c0c115eu; return 0; }
write(ram,r[6]+r[0],r[3],2);
goto P_0c0c1160;
P_0c0c1160: /* original 63f2, guest PC 0x0c0c1160 */
if(!s->budget--) { s->failed_pc=0x0c0c1160u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c1162;
P_0c0c1162: /* original e022, guest PC 0x0c0c1162 */
if(!s->budget--) { s->failed_pc=0x0c0c1162u; return 0; }
r[0]=0x00000022u;
goto P_0c0c1164;
P_0c0c1164: /* original e202, guest PC 0x0c0c1164 */
if(!s->budget--) { s->failed_pc=0x0c0c1164u; return 0; }
r[2]=0x00000002u;
goto P_0c0c1166;
P_0c0c1166: /* original 013d, guest PC 0x0c0c1166 */
if(!s->budget--) { s->failed_pc=0x0c0c1166u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c1168;
P_0c0c1168: /* original 212b, guest PC 0x0c0c1168 */
if(!s->budget--) { s->failed_pc=0x0c0c1168u; return 0; }
r[1]|=r[2];
goto P_0c0c116a;
P_0c0c116a: /* original 0315, guest PC 0x0c0c116a */
if(!s->budget--) { s->failed_pc=0x0c0c116au; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c0c116c;
P_0c0c116c: /* original e022, guest PC 0x0c0c116c */
if(!s->budget--) { s->failed_pc=0x0c0c116cu; return 0; }
r[0]=0x00000022u;
goto P_0c0c116e;
P_0c0c116e: /* original 53f1, guest PC 0x0c0c116e */
if(!s->budget--) { s->failed_pc=0x0c0c116eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c1170;
P_0c0c1170: /* original 7f10, guest PC 0x0c0c1170 */
if(!s->budget--) { s->failed_pc=0x0c0c1170u; return 0; }
r[15]+=0x00000010u;
goto P_0c0c1172;
P_0c0c1172: /* original 4f26, guest PC 0x0c0c1172 */
if(!s->budget--) { s->failed_pc=0x0c0c1172u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c1174;
P_0c0c1174: /* original 013d, guest PC 0x0c0c1174 */
if(!s->budget--) { s->failed_pc=0x0c0c1174u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c1176;
P_0c0c1176: /* original 212b, guest PC 0x0c0c1176 */
if(!s->budget--) { s->failed_pc=0x0c0c1176u; return 0; }
r[1]|=r[2];
goto P_0c0c1178;
P_0c0c1178: /* original 0315, guest PC 0x0c0c1178 */
if(!s->budget--) { s->failed_pc=0x0c0c1178u; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c0c117a;
P_0c0c117a: /* original 000b, guest PC 0x0c0c117a */
if(!s->budget--) { s->failed_pc=0x0c0c117au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c117c: /* original 0009, guest PC 0x0c0c117c */
if(!s->budget--) { s->failed_pc=0x0c0c117cu; return 0; }
if(!vf3_matrix_family(0x0c0c117eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c117eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
