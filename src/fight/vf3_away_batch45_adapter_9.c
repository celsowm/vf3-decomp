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
int vf3_away_batch45_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a058cu: goto P_0c0a058c;
case 0x0c0a058eu: goto P_0c0a058e;
case 0x0c0a0590u: goto P_0c0a0590;
case 0x0c0a0592u: goto P_0c0a0592;
case 0x0c0a0594u: goto P_0c0a0594;
case 0x0c0a0596u: goto P_0c0a0596;
case 0x0c0a0598u: goto P_0c0a0598;
case 0x0c0a059au: goto P_0c0a059a;
case 0x0c0a059cu: goto P_0c0a059c;
case 0x0c0a059eu: goto P_0c0a059e;
case 0x0c0a05a0u: goto P_0c0a05a0;
case 0x0c0a05a2u: goto P_0c0a05a2;
case 0x0c0a05a4u: goto P_0c0a05a4;
case 0x0c0a05a6u: goto P_0c0a05a6;
case 0x0c0a05a8u: goto P_0c0a05a8;
case 0x0c0a05aau: goto P_0c0a05aa;
case 0x0c0a05acu: goto P_0c0a05ac;
case 0x0c0a05aeu: goto P_0c0a05ae;
case 0x0c0a05b0u: goto P_0c0a05b0;
case 0x0c0a05b2u: goto P_0c0a05b2;
case 0x0c0a05b4u: goto P_0c0a05b4;
case 0x0c0a05b6u: goto P_0c0a05b6;
case 0x0c0a05b8u: goto P_0c0a05b8;
case 0x0c0a05bau: goto P_0c0a05ba;
case 0x0c0a05bcu: goto P_0c0a05bc;
case 0x0c0a05beu: goto P_0c0a05be;
case 0x0c0a05c0u: goto P_0c0a05c0;
case 0x0c0a05c2u: goto P_0c0a05c2;
case 0x0c0a05c4u: goto P_0c0a05c4;
case 0x0c0a05c6u: goto P_0c0a05c6;
case 0x0c0a05c8u: goto P_0c0a05c8;
case 0x0c0a05cau: goto P_0c0a05ca;
case 0x0c0a05ccu: goto P_0c0a05cc;
case 0x0c0a05fcu: goto P_0c0a05fc;
case 0x0c0a05feu: goto P_0c0a05fe;
case 0x0c0a0600u: goto P_0c0a0600;
case 0x0c0a0602u: goto P_0c0a0602;
case 0x0c0a0604u: goto P_0c0a0604;
case 0x0c0a0606u: goto P_0c0a0606;
case 0x0c0a0608u: goto P_0c0a0608;
case 0x0c0a060au: goto P_0c0a060a;
case 0x0c0a060cu: goto P_0c0a060c;
case 0x0c0a060eu: goto P_0c0a060e;
case 0x0c0a0610u: goto P_0c0a0610;
case 0x0c0a0612u: goto P_0c0a0612;
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
case 0x0c0c11f4u: goto P_0c0c11f4;
case 0x0c0c11f6u: goto P_0c0c11f6;
case 0x0c0c11f8u: goto P_0c0c11f8;
case 0x0c0c11fau: goto P_0c0c11fa;
case 0x0c0c11fcu: goto P_0c0c11fc;
case 0x0c0c11feu: goto P_0c0c11fe;
case 0x0c0c1200u: goto P_0c0c1200;
case 0x0c0c1202u: goto P_0c0c1202;
case 0x0c0c1204u: goto P_0c0c1204;
case 0x0c0c1206u: goto P_0c0c1206;
case 0x0c0c1208u: goto P_0c0c1208;
case 0x0c0c120au: goto P_0c0c120a;
case 0x0c0c120cu: goto P_0c0c120c;
case 0x0c0c120eu: goto P_0c0c120e;
case 0x0c0c1210u: goto P_0c0c1210;
case 0x0c0c1212u: goto P_0c0c1212;
case 0x0c0c1214u: goto P_0c0c1214;
case 0x0c0c1216u: goto P_0c0c1216;
case 0x0c0c1218u: goto P_0c0c1218;
case 0x0c0c121au: goto P_0c0c121a;
case 0x0c0c121cu: goto P_0c0c121c;
case 0x0c0c121eu: goto P_0c0c121e;
case 0x0c0c1220u: goto P_0c0c1220;
case 0x0c0c1222u: goto P_0c0c1222;
case 0x0c0c1224u: goto P_0c0c1224;
case 0x0c0c1226u: goto P_0c0c1226;
case 0x0c0c1228u: goto P_0c0c1228;
case 0x0c0c122au: goto P_0c0c122a;
case 0x0c0c122cu: goto P_0c0c122c;
case 0x0c0c122eu: goto P_0c0c122e;
case 0x0c0c1230u: goto P_0c0c1230;
case 0x0c0c1232u: goto P_0c0c1232;
case 0x0c0c1234u: goto P_0c0c1234;
case 0x0c0c1236u: goto P_0c0c1236;
case 0x0c0c1238u: goto P_0c0c1238;
case 0x0c0c123au: goto P_0c0c123a;
case 0x0c0c123cu: goto P_0c0c123c;
case 0x0c0c123eu: goto P_0c0c123e;
case 0x0c0c1240u: goto P_0c0c1240;
case 0x0c0c1242u: goto P_0c0c1242;
case 0x0c0c1244u: goto P_0c0c1244;
case 0x0c0c1246u: goto P_0c0c1246;
case 0x0c0c1248u: goto P_0c0c1248;
case 0x0c0c124au: goto P_0c0c124a;
case 0x0c0c124cu: goto P_0c0c124c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a058c: /* original 2fe6, guest PC 0x0c0a058c */
if(!s->budget--) { s->failed_pc=0x0c0a058cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a058e;
P_0c0a058e: /* original 4f22, guest PC 0x0c0a058e */
if(!s->budget--) { s->failed_pc=0x0c0a058eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a0590;
P_0c0a0590: /* original 7ff8, guest PC 0x0c0a0590 */
if(!s->budget--) { s->failed_pc=0x0c0a0590u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a0592;
P_0c0a0592: /* original 2f42, guest PC 0x0c0a0592 */
if(!s->budget--) { s->failed_pc=0x0c0a0592u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a0594;
P_0c0a0594: /* original 1f61, guest PC 0x0c0a0594 */
if(!s->budget--) { s->failed_pc=0x0c0a0594u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0a0596;
P_0c0a0596: /* original d312, guest PC 0x0c0a0596 */
if(!s->budget--) { s->failed_pc=0x0c0a0596u; return 0; }
r[3]=read(ram,0x0c0a05e0u,4);
goto P_0c0a0598;
P_0c0a0598: /* original 430b, guest PC 0x0c0a0598 */
if(!s->budget--) { s->failed_pc=0x0c0a0598u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a059cu;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a059cu) { target=s->pc; goto dispatch; }
goto P_0c0a059c;
P_0c0a059a: /* original 6463, guest PC 0x0c0a059a */
if(!s->budget--) { s->failed_pc=0x0c0a059au; return 0; }
r[4]=r[6];
goto P_0c0a059c;
P_0c0a059c: /* original d215, guest PC 0x0c0a059c */
if(!s->budget--) { s->failed_pc=0x0c0a059cu; return 0; }
r[2]=read(ram,0x0c0a05f4u,4);
goto P_0c0a059e;
P_0c0a059e: /* original e40d, guest PC 0x0c0a059e */
if(!s->budget--) { s->failed_pc=0x0c0a059eu; return 0; }
r[4]=0x0000000du;
goto P_0c0a05a0;
P_0c0a05a0: /* original 610c, guest PC 0x0c0a05a0 */
if(!s->budget--) { s->failed_pc=0x0c0a05a0u; return 0; }
r[1]=r[0]&255u;
goto P_0c0a05a2;
P_0c0a05a2: /* original 420b, guest PC 0x0c0a05a2 */
if(!s->budget--) { s->failed_pc=0x0c0a05a2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a05a6u;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a05a6u) { target=s->pc; goto dispatch; }
goto P_0c0a05a6;
P_0c0a05a4: /* original 6043, guest PC 0x0c0a05a4 */
if(!s->budget--) { s->failed_pc=0x0c0a05a4u; return 0; }
r[0]=r[4];
goto P_0c0a05a6;
P_0c0a05a6: /* original 64f2, guest PC 0x0c0a05a6 */
if(!s->budget--) { s->failed_pc=0x0c0a05a6u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a05a8;
P_0c0a05a8: /* original e307, guest PC 0x0c0a05a8 */
if(!s->budget--) { s->failed_pc=0x0c0a05a8u; return 0; }
r[3]=0x00000007u;
goto P_0c0a05aa;
P_0c0a05aa: /* original 6503, guest PC 0x0c0a05aa */
if(!s->budget--) { s->failed_pc=0x0c0a05aau; return 0; }
r[5]=r[0];
goto P_0c0a05ac;
P_0c0a05ac: /* original 6053, guest PC 0x0c0a05ac */
if(!s->budget--) { s->failed_pc=0x0c0a05acu; return 0; }
r[0]=r[5];
goto P_0c0a05ae;
P_0c0a05ae: /* original 740c, guest PC 0x0c0a05ae */
if(!s->budget--) { s->failed_pc=0x0c0a05aeu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a05b0;
P_0c0a05b0: /* original 8809, guest PC 0x0c0a05b0 */
if(!s->budget--) { s->failed_pc=0x0c0a05b0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0a05b2;
P_0c0a05b2: /* original e254, guest PC 0x0c0a05b2 */
if(!s->budget--) { s->failed_pc=0x0c0a05b2u; return 0; }
r[2]=0x00000054u;
goto P_0c0a05b4;
P_0c0a05b4: /* original 6e53, guest PC 0x0c0a05b4 */
if(!s->budget--) { s->failed_pc=0x0c0a05b4u; return 0; }
r[14]=r[5];
goto P_0c0a05b6;
P_0c0a05b6: /* original 443c, guest PC 0x0c0a05b6 */
if(!s->budget--) { s->failed_pc=0x0c0a05b6u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c0a05b8;
P_0c0a05b8: /* original 242b, guest PC 0x0c0a05b8 */
if(!s->budget--) { s->failed_pc=0x0c0a05b8u; return 0; }
r[4]|=r[2];
goto P_0c0a05ba;
P_0c0a05ba: /* original 8f1f, guest PC 0x0c0a05ba */
if(!s->budget--) { s->failed_pc=0x0c0a05bau; return 0; }
cond=r[17]&1u;
r[14]<<=2;
if(!cond) { goto P_0c0a05fc; }
goto P_0c0a05be;
P_0c0a05bc: /* original 4e08, guest PC 0x0c0a05bc */
if(!s->budget--) { s->failed_pc=0x0c0a05bcu; return 0; }
r[14]<<=2;
goto P_0c0a05be;
P_0c0a05be: /* original 7f08, guest PC 0x0c0a05be */
if(!s->budget--) { s->failed_pc=0x0c0a05beu; return 0; }
r[15]+=0x00000008u;
goto P_0c0a05c0;
P_0c0a05c0: /* original d00d, guest PC 0x0c0a05c0 */
if(!s->budget--) { s->failed_pc=0x0c0a05c0u; return 0; }
r[0]=read(ram,0x0c0a05f8u,4);
goto P_0c0a05c2;
P_0c0a05c2: /* original 4f26, guest PC 0x0c0a05c2 */
if(!s->budget--) { s->failed_pc=0x0c0a05c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a05c4;
P_0c0a05c4: /* original d307, guest PC 0x0c0a05c4 */
if(!s->budget--) { s->failed_pc=0x0c0a05c4u; return 0; }
r[3]=read(ram,0x0c0a05e4u,4);
goto P_0c0a05c6;
P_0c0a05c6: /* original e601, guest PC 0x0c0a05c6 */
if(!s->budget--) { s->failed_pc=0x0c0a05c6u; return 0; }
r[6]=0x00000001u;
goto P_0c0a05c8;
P_0c0a05c8: /* original 05ee, guest PC 0x0c0a05c8 */
if(!s->budget--) { s->failed_pc=0x0c0a05c8u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0a05ca;
P_0c0a05ca: /* original 432b, guest PC 0x0c0a05ca */
if(!s->budget--) { s->failed_pc=0x0c0a05cau; return 0; }
target=r[3];
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
P_0c0a05cc: /* original 6ef6, guest PC 0x0c0a05cc */
if(!s->budget--) { s->failed_pc=0x0c0a05ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a05ceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a05ceu; return 0; } return 1;
P_0c0a05fc: /* original d63f, guest PC 0x0c0a05fc */
if(!s->budget--) { s->failed_pc=0x0c0a05fcu; return 0; }
r[6]=read(ram,0x0c0a06fcu,4);
goto P_0c0a05fe;
P_0c0a05fe: /* original e100, guest PC 0x0c0a05fe */
if(!s->budget--) { s->failed_pc=0x0c0a05feu; return 0; }
r[1]=0x00000000u;
goto P_0c0a0600;
P_0c0a0600: /* original 2f16, guest PC 0x0c0a0600 */
if(!s->budget--) { s->failed_pc=0x0c0a0600u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0602;
P_0c0a0602: /* original 6713, guest PC 0x0c0a0602 */
if(!s->budget--) { s->failed_pc=0x0c0a0602u; return 0; }
r[7]=r[1];
goto P_0c0a0604;
P_0c0a0604: /* original d33f, guest PC 0x0c0a0604 */
if(!s->budget--) { s->failed_pc=0x0c0a0604u; return 0; }
r[3]=read(ram,0x0c0a0704u,4);
goto P_0c0a0606;
P_0c0a0606: /* original d03e, guest PC 0x0c0a0606 */
if(!s->budget--) { s->failed_pc=0x0c0a0606u; return 0; }
r[0]=read(ram,0x0c0a0700u,4);
goto P_0c0a0608;
P_0c0a0608: /* original 430b, guest PC 0x0c0a0608 */
if(!s->budget--) { s->failed_pc=0x0c0a0608u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a060cu;
r[5]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a060cu) { target=s->pc; goto dispatch; }
goto P_0c0a060c;
P_0c0a060a: /* original 05ee, guest PC 0x0c0a060a */
if(!s->budget--) { s->failed_pc=0x0c0a060au; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0a060c;
P_0c0a060c: /* original 7f0c, guest PC 0x0c0a060c */
if(!s->budget--) { s->failed_pc=0x0c0a060cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a060e;
P_0c0a060e: /* original 4f26, guest PC 0x0c0a060e */
if(!s->budget--) { s->failed_pc=0x0c0a060eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a0610;
P_0c0a0610: /* original 000b, guest PC 0x0c0a0610 */
if(!s->budget--) { s->failed_pc=0x0c0a0610u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a0612: /* original 6ef6, guest PC 0x0c0a0612 */
if(!s->budget--) { s->failed_pc=0x0c0a0612u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a0614u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a0614u; return 0; } return 1;
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
P_0c0c11f4: /* original 7ff4, guest PC 0x0c0c11f4 */
if(!s->budget--) { s->failed_pc=0x0c0c11f4u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0c11f6;
P_0c0c11f6: /* original 6763, guest PC 0x0c0c11f6 */
if(!s->budget--) { s->failed_pc=0x0c0c11f6u; return 0; }
r[7]=r[6];
goto P_0c0c11f8;
P_0c0c11f8: /* original 1f41, guest PC 0x0c0c11f8 */
if(!s->budget--) { s->failed_pc=0x0c0c11f8u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0c11fa;
P_0c0c11fa: /* original 2f52, guest PC 0x0c0c11fa */
if(!s->budget--) { s->failed_pc=0x0c0c11fau; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c11fc;
P_0c0c11fc: /* original 1f62, guest PC 0x0c0c11fc */
if(!s->budget--) { s->failed_pc=0x0c0c11fcu; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c0c11fe;
P_0c0c11fe: /* original 55f1, guest PC 0x0c0c11fe */
if(!s->budget--) { s->failed_pc=0x0c0c11feu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0c1200;
P_0c0c1200: /* original 66f2, guest PC 0x0c0c1200 */
if(!s->budget--) { s->failed_pc=0x0c0c1200u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c0c1202;
P_0c0c1202: /* original d438, guest PC 0x0c0c1202 */
if(!s->budget--) { s->failed_pc=0x0c0c1202u; return 0; }
r[4]=read(ram,0x0c0c12e4u,4);
goto P_0c0c1204;
P_0c0c1204: /* original a2a6, guest PC 0x0c0c1204 */
if(!s->budget--) { s->failed_pc=0x0c0c1204u; return 0; }
r[15]+=0x0000000cu;
return vf3_matrix_family(0x0c0c1754u,s,ram);
P_0c0c1206: /* original 7f0c, guest PC 0x0c0c1206 */
if(!s->budget--) { s->failed_pc=0x0c0c1206u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0c1208;
P_0c0c1208: /* original 2fe6, guest PC 0x0c0c1208 */
if(!s->budget--) { s->failed_pc=0x0c0c1208u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c120a;
P_0c0c120a: /* original e603, guest PC 0x0c0c120a */
if(!s->budget--) { s->failed_pc=0x0c0c120au; return 0; }
r[6]=0x00000003u;
goto P_0c0c120c;
P_0c0c120c: /* original 4f22, guest PC 0x0c0c120c */
if(!s->budget--) { s->failed_pc=0x0c0c120cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c120e;
P_0c0c120e: /* original 9063, guest PC 0x0c0c120e */
if(!s->budget--) { s->failed_pc=0x0c0c120eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12d8u,2);
goto P_0c0c1210;
P_0c0c1210: /* original 3f0c, guest PC 0x0c0c1210 */
if(!s->budget--) { s->failed_pc=0x0c0c1210u; return 0; }
r[15]+=r[0];
goto P_0c0c1212;
P_0c0c1212: /* original 2f42, guest PC 0x0c0c1212 */
if(!s->budget--) { s->failed_pc=0x0c0c1212u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c1214;
P_0c0c1214: /* original 6ef3, guest PC 0x0c0c1214 */
if(!s->budget--) { s->failed_pc=0x0c0c1214u; return 0; }
r[14]=r[15];
goto P_0c0c1216;
P_0c0c1216: /* original 9060, guest PC 0x0c0c1216 */
if(!s->budget--) { s->failed_pc=0x0c0c1216u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12dau,2);
goto P_0c0c1218;
P_0c0c1218: /* original 30fc, guest PC 0x0c0c1218 */
if(!s->budget--) { s->failed_pc=0x0c0c1218u; return 0; }
r[0]+=r[15];
goto P_0c0c121a;
P_0c0c121a: /* original 7004, guest PC 0x0c0c121a */
if(!s->budget--) { s->failed_pc=0x0c0c121au; return 0; }
r[0]+=0x00000004u;
goto P_0c0c121c;
P_0c0c121c: /* original 2608, guest PC 0x0c0c121c */
if(!s->budget--) { s->failed_pc=0x0c0c121cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[0])==0)!=0);
goto P_0c0c121e;
P_0c0c121e: /* original 8d04, guest PC 0x0c0c121e */
if(!s->budget--) { s->failed_pc=0x0c0c121eu; return 0; }
cond=r[17]&1u;
r[14]+=0x00000004u;
if(cond) { goto P_0c0c122a; }
goto P_0c0c1222;
P_0c0c1220: /* original 7e04, guest PC 0x0c0c1220 */
if(!s->budget--) { s->failed_pc=0x0c0c1220u; return 0; }
r[14]+=0x00000004u;
goto P_0c0c1222;
P_0c0c1222: /* original 965a, guest PC 0x0c0c1222 */
if(!s->budget--) { s->failed_pc=0x0c0c1222u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12dau,2);
goto P_0c0c1224;
P_0c0c1224: /* original 36fc, guest PC 0x0c0c1224 */
if(!s->budget--) { s->failed_pc=0x0c0c1224u; return 0; }
r[6]+=r[15];
goto P_0c0c1226;
P_0c0c1226: /* original a003, guest PC 0x0c0c1226 */
if(!s->budget--) { s->failed_pc=0x0c0c1226u; return 0; }
r[6]+=0x00000008u;
goto P_0c0c1230;
P_0c0c1228: /* original 7608, guest PC 0x0c0c1228 */
if(!s->budget--) { s->failed_pc=0x0c0c1228u; return 0; }
r[6]+=0x00000008u;
goto P_0c0c122a;
P_0c0c122a: /* original 9656, guest PC 0x0c0c122a */
if(!s->budget--) { s->failed_pc=0x0c0c122au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12dau,2);
goto P_0c0c122c;
P_0c0c122c: /* original 36fc, guest PC 0x0c0c122c */
if(!s->budget--) { s->failed_pc=0x0c0c122cu; return 0; }
r[6]+=r[15];
goto P_0c0c122e;
P_0c0c122e: /* original 7604, guest PC 0x0c0c122e */
if(!s->budget--) { s->failed_pc=0x0c0c122eu; return 0; }
r[6]+=0x00000004u;
goto P_0c0c1230;
P_0c0c1230: /* original 9053, guest PC 0x0c0c1230 */
if(!s->budget--) { s->failed_pc=0x0c0c1230u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12dau,2);
goto P_0c0c1232;
P_0c0c1232: /* original d32d, guest PC 0x0c0c1232 */
if(!s->budget--) { s->failed_pc=0x0c0c1232u; return 0; }
r[3]=read(ram,0x0c0c12e8u,4);
goto P_0c0c1234;
P_0c0c1234: /* original 05fe, guest PC 0x0c0c1234 */
if(!s->budget--) { s->failed_pc=0x0c0c1234u; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c0c1236;
P_0c0c1236: /* original 430b, guest PC 0x0c0c1236 */
if(!s->budget--) { s->failed_pc=0x0c0c1236u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c123au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c123au) { target=s->pc; goto dispatch; }
goto P_0c0c123a;
P_0c0c1238: /* original 64e3, guest PC 0x0c0c1238 */
if(!s->budget--) { s->failed_pc=0x0c0c1238u; return 0; }
r[4]=r[14];
goto P_0c0c123a;
P_0c0c123a: /* original d42a, guest PC 0x0c0c123a */
if(!s->budget--) { s->failed_pc=0x0c0c123au; return 0; }
r[4]=read(ram,0x0c0c12e4u,4);
goto P_0c0c123c;
P_0c0c123c: /* original 66e3, guest PC 0x0c0c123c */
if(!s->budget--) { s->failed_pc=0x0c0c123cu; return 0; }
r[6]=r[14];
goto P_0c0c123e;
P_0c0c123e: /* original e701, guest PC 0x0c0c123e */
if(!s->budget--) { s->failed_pc=0x0c0c123eu; return 0; }
r[7]=0x00000001u;
goto P_0c0c1240;
P_0c0c1240: /* original b288, guest PC 0x0c0c1240 */
if(!s->budget--) { s->failed_pc=0x0c0c1240u; return 0; }
target=code_base|0x0c0c1754u; r[16]=code_base|0x0c0c1244u;
tmp=read(ram,r[15],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c1244u) { target=s->pc; goto dispatch; }
goto P_0c0c1244;
P_0c0c1242: /* original 65f2, guest PC 0x0c0c1242 */
if(!s->budget--) { s->failed_pc=0x0c0c1242u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0c1244;
P_0c0c1244: /* original 914a, guest PC 0x0c0c1244 */
if(!s->budget--) { s->failed_pc=0x0c0c1244u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12dcu,2);
goto P_0c0c1246;
P_0c0c1246: /* original 3f1c, guest PC 0x0c0c1246 */
if(!s->budget--) { s->failed_pc=0x0c0c1246u; return 0; }
r[15]+=r[1];
goto P_0c0c1248;
P_0c0c1248: /* original 4f26, guest PC 0x0c0c1248 */
if(!s->budget--) { s->failed_pc=0x0c0c1248u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c124a;
P_0c0c124a: /* original 000b, guest PC 0x0c0c124a */
if(!s->budget--) { s->failed_pc=0x0c0c124au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c124c: /* original 6ef6, guest PC 0x0c0c124c */
if(!s->budget--) { s->failed_pc=0x0c0c124cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c124eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
