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
int vf3_away_batch72_adapter_33(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c0c1184u: goto P_0c0c1184;
case 0x0c0c1186u: goto P_0c0c1186;
case 0x0c0c1188u: goto P_0c0c1188;
case 0x0c0c118au: goto P_0c0c118a;
case 0x0c0c118cu: goto P_0c0c118c;
case 0x0c0c118eu: goto P_0c0c118e;
case 0x0c0c1190u: goto P_0c0c1190;
case 0x0c0c124eu: goto P_0c0c124e;
case 0x0c0c1250u: goto P_0c0c1250;
case 0x0c0c1252u: goto P_0c0c1252;
case 0x0c0c1254u: goto P_0c0c1254;
case 0x0c0c1256u: goto P_0c0c1256;
case 0x0c0c1258u: goto P_0c0c1258;
case 0x0c0c125au: goto P_0c0c125a;
case 0x0c0c125cu: goto P_0c0c125c;
case 0x0c0c125eu: goto P_0c0c125e;
case 0x0c0c1260u: goto P_0c0c1260;
case 0x0c0c1262u: goto P_0c0c1262;
case 0x0c0c1264u: goto P_0c0c1264;
case 0x0c0c1266u: goto P_0c0c1266;
case 0x0c0c1268u: goto P_0c0c1268;
case 0x0c0c126au: goto P_0c0c126a;
case 0x0c0c126cu: goto P_0c0c126c;
case 0x0c0c126eu: goto P_0c0c126e;
case 0x0c0c1270u: goto P_0c0c1270;
case 0x0c0c1272u: goto P_0c0c1272;
case 0x0c0c1274u: goto P_0c0c1274;
case 0x0c0c1276u: goto P_0c0c1276;
case 0x0c0c1278u: goto P_0c0c1278;
case 0x0c0c127au: goto P_0c0c127a;
case 0x0c0c127cu: goto P_0c0c127c;
case 0x0c0c127eu: goto P_0c0c127e;
case 0x0c0c1280u: goto P_0c0c1280;
case 0x0c0c1282u: goto P_0c0c1282;
case 0x0c0c1284u: goto P_0c0c1284;
case 0x0c0c1286u: goto P_0c0c1286;
case 0x0c0c1288u: goto P_0c0c1288;
case 0x0c0c128au: goto P_0c0c128a;
case 0x0c0c128cu: goto P_0c0c128c;
case 0x0c0c128eu: goto P_0c0c128e;
case 0x0c0c1290u: goto P_0c0c1290;
case 0x0c0c1292u: goto P_0c0c1292;
case 0x0c0c1294u: goto P_0c0c1294;
case 0x0c0c1296u: goto P_0c0c1296;
case 0x0c0c1298u: goto P_0c0c1298;
case 0x0c0c129au: goto P_0c0c129a;
case 0x0c0c129cu: goto P_0c0c129c;
case 0x0c0c129eu: goto P_0c0c129e;
case 0x0c0c12a0u: goto P_0c0c12a0;
case 0x0c0c12a2u: goto P_0c0c12a2;
case 0x0c0c12a4u: goto P_0c0c12a4;
case 0x0c0c12a6u: goto P_0c0c12a6;
case 0x0c0c12a8u: goto P_0c0c12a8;
case 0x0c0c12aau: goto P_0c0c12aa;
case 0x0c0c12acu: goto P_0c0c12ac;
case 0x0c0c12aeu: goto P_0c0c12ae;
case 0x0c0c12b0u: goto P_0c0c12b0;
case 0x0c0c12b2u: goto P_0c0c12b2;
case 0x0c0c12b4u: goto P_0c0c12b4;
case 0x0c0c12b6u: goto P_0c0c12b6;
case 0x0c0c12b8u: goto P_0c0c12b8;
case 0x0c0c12bau: goto P_0c0c12ba;
case 0x0c0c12bcu: goto P_0c0c12bc;
case 0x0c0c12beu: goto P_0c0c12be;
case 0x0c0c12c0u: goto P_0c0c12c0;
case 0x0c0c12c2u: goto P_0c0c12c2;
case 0x0c0c12c4u: goto P_0c0c12c4;
case 0x0c0c12c6u: goto P_0c0c12c6;
case 0x0c0c12c8u: goto P_0c0c12c8;
case 0x0c0c12cau: goto P_0c0c12ca;
case 0x0c0c12ccu: goto P_0c0c12cc;
case 0x0c0c12ceu: goto P_0c0c12ce;
case 0x0c0c12d0u: goto P_0c0c12d0;
case 0x0c0c12d2u: goto P_0c0c12d2;
case 0x0c0c12d4u: goto P_0c0c12d4;
case 0x0c0c12d6u: goto P_0c0c12d6;
case 0x0c0c1836u: goto P_0c0c1836;
case 0x0c0c1838u: goto P_0c0c1838;
case 0x0c0c183au: goto P_0c0c183a;
case 0x0c0c183cu: goto P_0c0c183c;
case 0x0c0c183eu: goto P_0c0c183e;
case 0x0c0c1840u: goto P_0c0c1840;
case 0x0c0c1842u: goto P_0c0c1842;
case 0x0c0c1844u: goto P_0c0c1844;
case 0x0c0c1846u: goto P_0c0c1846;
case 0x0c0c1848u: goto P_0c0c1848;
case 0x0c0c184au: goto P_0c0c184a;
case 0x0c0c184cu: goto P_0c0c184c;
case 0x0c0c184eu: goto P_0c0c184e;
case 0x0c0c1850u: goto P_0c0c1850;
case 0x0c0c1852u: goto P_0c0c1852;
case 0x0c0c1854u: goto P_0c0c1854;
case 0x0c0c1856u: goto P_0c0c1856;
case 0x0c0c1858u: goto P_0c0c1858;
case 0x0c0c185au: goto P_0c0c185a;
case 0x0c0c185cu: goto P_0c0c185c;
case 0x0c0c185eu: goto P_0c0c185e;
case 0x0c0c1860u: goto P_0c0c1860;
case 0x0c0c1862u: goto P_0c0c1862;
case 0x0c0c1864u: goto P_0c0c1864;
case 0x0c0c1866u: goto P_0c0c1866;
case 0x0c0c1868u: goto P_0c0c1868;
case 0x0c0c186au: goto P_0c0c186a;
case 0x0c0c186cu: goto P_0c0c186c;
case 0x0c0c186eu: goto P_0c0c186e;
case 0x0c0c1870u: goto P_0c0c1870;
case 0x0c0c1872u: goto P_0c0c1872;
case 0x0c0c1874u: goto P_0c0c1874;
case 0x0c0c1876u: goto P_0c0c1876;
case 0x0c0c1878u: goto P_0c0c1878;
case 0x0c0c187au: goto P_0c0c187a;
case 0x0c0c187cu: goto P_0c0c187c;
case 0x0c0c187eu: goto P_0c0c187e;
case 0x0c0c1880u: goto P_0c0c1880;
case 0x0c0c1882u: goto P_0c0c1882;
case 0x0c0c1884u: goto P_0c0c1884;
case 0x0c0c1886u: goto P_0c0c1886;
case 0x0c0c1888u: goto P_0c0c1888;
case 0x0c0c188au: goto P_0c0c188a;
case 0x0c0c188cu: goto P_0c0c188c;
case 0x0c0c188eu: goto P_0c0c188e;
case 0x0c0c1890u: goto P_0c0c1890;
case 0x0c0c1892u: goto P_0c0c1892;
case 0x0c0c1894u: goto P_0c0c1894;
case 0x0c0c1896u: goto P_0c0c1896;
case 0x0c0c1898u: goto P_0c0c1898;
case 0x0c0c189au: goto P_0c0c189a;
case 0x0c0c189cu: goto P_0c0c189c;
case 0x0c0c189eu: goto P_0c0c189e;
case 0x0c0c18a0u: goto P_0c0c18a0;
case 0x0c0c18a2u: goto P_0c0c18a2;
case 0x0c0c18a4u: goto P_0c0c18a4;
case 0x0c0c18a6u: goto P_0c0c18a6;
case 0x0c0c18a8u: goto P_0c0c18a8;
case 0x0c0c18aau: goto P_0c0c18aa;
case 0x0c0c18acu: goto P_0c0c18ac;
case 0x0c0c18aeu: goto P_0c0c18ae;
case 0x0c0c18b0u: goto P_0c0c18b0;
case 0x0c0c18b2u: goto P_0c0c18b2;
case 0x0c0c18b4u: goto P_0c0c18b4;
case 0x0c0c18b6u: goto P_0c0c18b6;
case 0x0c0c18b8u: goto P_0c0c18b8;
case 0x0c0c18bau: goto P_0c0c18ba;
case 0x0c0c18bcu: goto P_0c0c18bc;
case 0x0c0c18beu: goto P_0c0c18be;
case 0x0c0c1a62u: goto P_0c0c1a62;
case 0x0c0c1a64u: goto P_0c0c1a64;
case 0x0c0c27aau: goto P_0c0c27aa;
case 0x0c0c27acu: goto P_0c0c27ac;
case 0x0c0c27aeu: goto P_0c0c27ae;
case 0x0c0c27b0u: goto P_0c0c27b0;
case 0x0c0c27b2u: goto P_0c0c27b2;
case 0x0c0c27b4u: goto P_0c0c27b4;
case 0x0c0c27b6u: goto P_0c0c27b6;
case 0x0c0c27b8u: goto P_0c0c27b8;
case 0x0c0c27bau: goto P_0c0c27ba;
case 0x0c0c27bcu: goto P_0c0c27bc;
case 0x0c0c27beu: goto P_0c0c27be;
case 0x0c0c27c0u: goto P_0c0c27c0;
case 0x0c0c27c2u: goto P_0c0c27c2;
case 0x0c0c27c4u: goto P_0c0c27c4;
case 0x0c0c27c6u: goto P_0c0c27c6;
case 0x0c0c27c8u: goto P_0c0c27c8;
case 0x0c0c27cau: goto P_0c0c27ca;
case 0x0c0c27ccu: goto P_0c0c27cc;
case 0x0c0c27ceu: goto P_0c0c27ce;
case 0x0c0c27d0u: goto P_0c0c27d0;
case 0x0c0c27d2u: goto P_0c0c27d2;
case 0x0c0c27d4u: goto P_0c0c27d4;
case 0x0c0c27d6u: goto P_0c0c27d6;
case 0x0c0c27d8u: goto P_0c0c27d8;
case 0x0c0c27dau: goto P_0c0c27da;
case 0x0c0c27dcu: goto P_0c0c27dc;
case 0x0c0c27deu: goto P_0c0c27de;
case 0x0c0c27e0u: goto P_0c0c27e0;
case 0x0c0c27e2u: goto P_0c0c27e2;
case 0x0c0c27e4u: goto P_0c0c27e4;
case 0x0c0c27e6u: goto P_0c0c27e6;
case 0x0c0c27e8u: goto P_0c0c27e8;
case 0x0c0c27eau: goto P_0c0c27ea;
case 0x0c0c27ecu: goto P_0c0c27ec;
case 0x0c0c27eeu: goto P_0c0c27ee;
case 0x0c0c27f0u: goto P_0c0c27f0;
case 0x0c0c27f2u: goto P_0c0c27f2;
case 0x0c0c27f4u: goto P_0c0c27f4;
case 0x0c0c27f6u: goto P_0c0c27f6;
case 0x0c0c27f8u: goto P_0c0c27f8;
case 0x0c0c27fau: goto P_0c0c27fa;
case 0x0c0c27fcu: goto P_0c0c27fc;
case 0x0c0c27feu: goto P_0c0c27fe;
case 0x0c0c2800u: goto P_0c0c2800;
case 0x0c0c2802u: goto P_0c0c2802;
case 0x0c0c2804u: goto P_0c0c2804;
case 0x0c0c2806u: goto P_0c0c2806;
case 0x0c0c2808u: goto P_0c0c2808;
default: return vf3_matrix_family(target,s,ram);
}
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
P_0c0c1184: /* original 4f22, guest PC 0x0c0c1184 */
if(!s->budget--) { s->failed_pc=0x0c0c1184u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c1186;
P_0c0c1186: /* original 0546, guest PC 0x0c0c1186 */
if(!s->budget--) { s->failed_pc=0x0c0c1186u; return 0; }
write(ram,r[5]+r[0],r[4],4);
goto P_0c0c1188;
P_0c0c1188: /* original 7004, guest PC 0x0c0c1188 */
if(!s->budget--) { s->failed_pc=0x0c0c1188u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c118a;
P_0c0c118a: /* original b46a, guest PC 0x0c0c118a */
if(!s->budget--) { s->failed_pc=0x0c0c118au; return 0; }
target=code_base|0x0c0c1a62u; r[16]=code_base|0x0c0c118eu;
write(ram,r[5]+r[0],r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c118eu) { target=s->pc; goto dispatch; }
goto P_0c0c118e;
P_0c0c118c: /* original 0546, guest PC 0x0c0c118c */
if(!s->budget--) { s->failed_pc=0x0c0c118cu; return 0; }
write(ram,r[5]+r[0],r[4],4);
goto P_0c0c118e;
P_0c0c118e: /* original af85, guest PC 0x0c0c118e */
if(!s->budget--) { s->failed_pc=0x0c0c118eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0c109cu,s,ram);
P_0c0c1190: /* original 4f26, guest PC 0x0c0c1190 */
if(!s->budget--) { s->failed_pc=0x0c0c1190u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c0c1192u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c1192u; return 0; } return 1;
P_0c0c124e: /* original e100, guest PC 0x0c0c124e */
if(!s->budget--) { s->failed_pc=0x0c0c124eu; return 0; }
r[1]=0x00000000u;
goto P_0c0c1250;
P_0c0c1250: /* original d324, guest PC 0x0c0c1250 */
if(!s->budget--) { s->failed_pc=0x0c0c1250u; return 0; }
r[3]=read(ram,0x0c0c12e4u,4);
goto P_0c0c1252;
P_0c0c1252: /* original e022, guest PC 0x0c0c1252 */
if(!s->budget--) { s->failed_pc=0x0c0c1252u; return 0; }
r[0]=0x00000022u;
goto P_0c0c1254;
P_0c0c1254: /* original 7ffc, guest PC 0x0c0c1254 */
if(!s->budget--) { s->failed_pc=0x0c0c1254u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c1256;
P_0c0c1256: /* original 2f32, guest PC 0x0c0c1256 */
if(!s->budget--) { s->failed_pc=0x0c0c1256u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c1258;
P_0c0c1258: /* original 0415, guest PC 0x0c0c1258 */
if(!s->budget--) { s->failed_pc=0x0c0c1258u; return 0; }
write(ram,r[4]+r[0],r[1],2);
goto P_0c0c125a;
P_0c0c125a: /* original 6063, guest PC 0x0c0c125a */
if(!s->budget--) { s->failed_pc=0x0c0c125au; return 0; }
r[0]=r[6];
goto P_0c0c125c;
P_0c0c125c: /* original 1474, guest PC 0x0c0c125c */
if(!s->budget--) { s->failed_pc=0x0c0c125cu; return 0; }
write(ram,r[4]+16,r[7],4);
goto P_0c0c125e;
P_0c0c125e: /* original 53f1, guest PC 0x0c0c125e */
if(!s->budget--) { s->failed_pc=0x0c0c125eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c1260;
P_0c0c1260: /* original 1433, guest PC 0x0c0c1260 */
if(!s->budget--) { s->failed_pc=0x0c0c1260u; return 0; }
write(ram,r[4]+12,r[3],4);
goto P_0c0c1262;
P_0c0c1262: /* original 2451, guest PC 0x0c0c1262 */
if(!s->budget--) { s->failed_pc=0x0c0c1262u; return 0; }
write(ram,r[4],r[5],2);
goto P_0c0c1264;
P_0c0c1264: /* original 8141, guest PC 0x0c0c1264 */
if(!s->budget--) { s->failed_pc=0x0c0c1264u; return 0; }
write(ram,r[4]+2,r[0],2);
goto P_0c0c1266;
P_0c0c1266: /* original e040, guest PC 0x0c0c1266 */
if(!s->budget--) { s->failed_pc=0x0c0c1266u; return 0; }
r[0]=0x00000040u;
goto P_0c0c1268;
P_0c0c1268: /* original 53f2, guest PC 0x0c0c1268 */
if(!s->budget--) { s->failed_pc=0x0c0c1268u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c126a;
P_0c0c126a: /* original 1436, guest PC 0x0c0c126a */
if(!s->budget--) { s->failed_pc=0x0c0c126au; return 0; }
write(ram,r[4]+24,r[3],4);
goto P_0c0c126c;
P_0c0c126c: /* original 52f3, guest PC 0x0c0c126c */
if(!s->budget--) { s->failed_pc=0x0c0c126cu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0c126e;
P_0c0c126e: /* original 1427, guest PC 0x0c0c126e */
if(!s->budget--) { s->failed_pc=0x0c0c126eu; return 0; }
write(ram,r[4]+28,r[2],4);
goto P_0c0c1270;
P_0c0c1270: /* original 8142, guest PC 0x0c0c1270 */
if(!s->budget--) { s->failed_pc=0x0c0c1270u; return 0; }
write(ram,r[4]+4,r[0],2);
goto P_0c0c1272;
P_0c0c1272: /* original e030, guest PC 0x0c0c1272 */
if(!s->budget--) { s->failed_pc=0x0c0c1272u; return 0; }
r[0]=0x00000030u;
goto P_0c0c1274;
P_0c0c1274: /* original 8143, guest PC 0x0c0c1274 */
if(!s->budget--) { s->failed_pc=0x0c0c1274u; return 0; }
write(ram,r[4]+6,r[0],2);
goto P_0c0c1276;
P_0c0c1276: /* original e03e, guest PC 0x0c0c1276 */
if(!s->budget--) { s->failed_pc=0x0c0c1276u; return 0; }
r[0]=0x0000003eu;
goto P_0c0c1278;
P_0c0c1278: /* original 8144, guest PC 0x0c0c1278 */
if(!s->budget--) { s->failed_pc=0x0c0c1278u; return 0; }
write(ram,r[4]+8,r[0],2);
goto P_0c0c127a;
P_0c0c127a: /* original e02e, guest PC 0x0c0c127a */
if(!s->budget--) { s->failed_pc=0x0c0c127au; return 0; }
r[0]=0x0000002eu;
goto P_0c0c127c;
P_0c0c127c: /* original 8145, guest PC 0x0c0c127c */
if(!s->budget--) { s->failed_pc=0x0c0c127cu; return 0; }
write(ram,r[4]+10,r[0],2);
goto P_0c0c127e;
P_0c0c127e: /* original 6013, guest PC 0x0c0c127e */
if(!s->budget--) { s->failed_pc=0x0c0c127eu; return 0; }
r[0]=r[1];
goto P_0c0c1280;
P_0c0c1280: /* original 814a, guest PC 0x0c0c1280 */
if(!s->budget--) { s->failed_pc=0x0c0c1280u; return 0; }
write(ram,r[4]+20,r[0],2);
goto P_0c0c1282;
P_0c0c1282: /* original 814b, guest PC 0x0c0c1282 */
if(!s->budget--) { s->failed_pc=0x0c0c1282u; return 0; }
write(ram,r[4]+22,r[0],2);
goto P_0c0c1284;
P_0c0c1284: /* original e020, guest PC 0x0c0c1284 */
if(!s->budget--) { s->failed_pc=0x0c0c1284u; return 0; }
r[0]=0x00000020u;
goto P_0c0c1286;
P_0c0c1286: /* original 932a, guest PC 0x0c0c1286 */
if(!s->budget--) { s->failed_pc=0x0c0c1286u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12deu,2);
goto P_0c0c1288;
P_0c0c1288: /* original 0435, guest PC 0x0c0c1288 */
if(!s->budget--) { s->failed_pc=0x0c0c1288u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c0c128a;
P_0c0c128a: /* original e3ff, guest PC 0x0c0c128a */
if(!s->budget--) { s->failed_pc=0x0c0c128au; return 0; }
r[3]=0xffffffffu;
goto P_0c0c128c;
P_0c0c128c: /* original 62f2, guest PC 0x0c0c128c */
if(!s->budget--) { s->failed_pc=0x0c0c128cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c128e;
P_0c0c128e: /* original 9027, guest PC 0x0c0c128e */
if(!s->budget--) { s->failed_pc=0x0c0c128eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12e0u,2);
goto P_0c0c1290;
P_0c0c1290: /* original 0236, guest PC 0x0c0c1290 */
if(!s->budget--) { s->failed_pc=0x0c0c1290u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0c1292;
P_0c0c1292: /* original a000, guest PC 0x0c0c1292 */
if(!s->budget--) { s->failed_pc=0x0c0c1292u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c1296;
P_0c0c1294: /* original 7f04, guest PC 0x0c0c1294 */
if(!s->budget--) { s->failed_pc=0x0c0c1294u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c1296;
P_0c0c1296: /* original 2fe6, guest PC 0x0c0c1296 */
if(!s->budget--) { s->failed_pc=0x0c0c1296u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1298;
P_0c0c1298: /* original 6e43, guest PC 0x0c0c1298 */
if(!s->budget--) { s->failed_pc=0x0c0c1298u; return 0; }
r[14]=r[4];
goto P_0c0c129a;
P_0c0c129a: /* original 2fd6, guest PC 0x0c0c129a */
if(!s->budget--) { s->failed_pc=0x0c0c129au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c129c;
P_0c0c129c: /* original ed00, guest PC 0x0c0c129c */
if(!s->budget--) { s->failed_pc=0x0c0c129cu; return 0; }
r[13]=0x00000000u;
goto P_0c0c129e;
P_0c0c129e: /* original 2fc6, guest PC 0x0c0c129e */
if(!s->budget--) { s->failed_pc=0x0c0c129eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c12a0;
P_0c0c12a0: /* original ec78, guest PC 0x0c0c12a0 */
if(!s->budget--) { s->failed_pc=0x0c0c12a0u; return 0; }
r[12]=0x00000078u;
goto P_0c0c12a2;
P_0c0c12a2: /* original 2fb6, guest PC 0x0c0c12a2 */
if(!s->budget--) { s->failed_pc=0x0c0c12a2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c12a4;
P_0c0c12a4: /* original 4f22, guest PC 0x0c0c12a4 */
if(!s->budget--) { s->failed_pc=0x0c0c12a4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c12a6;
P_0c0c12a6: /* original 7ffc, guest PC 0x0c0c12a6 */
if(!s->budget--) { s->failed_pc=0x0c0c12a6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c12a8;
P_0c0c12a8: /* original 2f42, guest PC 0x0c0c12a8 */
if(!s->budget--) { s->failed_pc=0x0c0c12a8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c12aa;
P_0c0c12aa: /* original 5ee3, guest PC 0x0c0c12aa */
if(!s->budget--) { s->failed_pc=0x0c0c12aau; return 0; }
r[14]=read(ram,r[14]+12,4);
goto P_0c0c12ac;
P_0c0c12ac: /* original db0f, guest PC 0x0c0c12ac */
if(!s->budget--) { s->failed_pc=0x0c0c12acu; return 0; }
r[11]=read(ram,0x0c0c12ecu,4);
goto P_0c0c12ae;
P_0c0c12ae: /* original e500, guest PC 0x0c0c12ae */
if(!s->budget--) { s->failed_pc=0x0c0c12aeu; return 0; }
r[5]=0x00000000u;
goto P_0c0c12b0;
P_0c0c12b0: /* original e644, guest PC 0x0c0c12b0 */
if(!s->budget--) { s->failed_pc=0x0c0c12b0u; return 0; }
r[6]=0x00000044u;
goto P_0c0c12b2;
P_0c0c12b2: /* original 4b0b, guest PC 0x0c0c12b2 */
if(!s->budget--) { s->failed_pc=0x0c0c12b2u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c12b6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c12b6u) { target=s->pc; goto dispatch; }
goto P_0c0c12b6;
P_0c0c12b4: /* original 64e3, guest PC 0x0c0c12b4 */
if(!s->budget--) { s->failed_pc=0x0c0c12b4u; return 0; }
r[4]=r[14];
goto P_0c0c12b6;
P_0c0c12b6: /* original 7d01, guest PC 0x0c0c12b6 */
if(!s->budget--) { s->failed_pc=0x0c0c12b6u; return 0; }
r[13]+=0x00000001u;
goto P_0c0c12b8;
P_0c0c12b8: /* original 3dc2, guest PC 0x0c0c12b8 */
if(!s->budget--) { s->failed_pc=0x0c0c12b8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[12])!=0);
goto P_0c0c12ba;
P_0c0c12ba: /* original 8ff8, guest PC 0x0c0c12ba */
if(!s->budget--) { s->failed_pc=0x0c0c12bau; return 0; }
cond=r[17]&1u;
r[14]+=0x00000044u;
if(!cond) { goto P_0c0c12ae; }
goto P_0c0c12be;
P_0c0c12bc: /* original 7e44, guest PC 0x0c0c12bc */
if(!s->budget--) { s->failed_pc=0x0c0c12bcu; return 0; }
r[14]+=0x00000044u;
goto P_0c0c12be;
P_0c0c12be: /* original 63f2, guest PC 0x0c0c12be */
if(!s->budget--) { s->failed_pc=0x0c0c12beu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c12c0;
P_0c0c12c0: /* original 7f04, guest PC 0x0c0c12c0 */
if(!s->budget--) { s->failed_pc=0x0c0c12c0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c12c2;
P_0c0c12c2: /* original 4f26, guest PC 0x0c0c12c2 */
if(!s->budget--) { s->failed_pc=0x0c0c12c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c12c4;
P_0c0c12c4: /* original e022, guest PC 0x0c0c12c4 */
if(!s->budget--) { s->failed_pc=0x0c0c12c4u; return 0; }
r[0]=0x00000022u;
goto P_0c0c12c6;
P_0c0c12c6: /* original 013d, guest PC 0x0c0c12c6 */
if(!s->budget--) { s->failed_pc=0x0c0c12c6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c12c8;
P_0c0c12c8: /* original e201, guest PC 0x0c0c12c8 */
if(!s->budget--) { s->failed_pc=0x0c0c12c8u; return 0; }
r[2]=0x00000001u;
goto P_0c0c12ca;
P_0c0c12ca: /* original 212b, guest PC 0x0c0c12ca */
if(!s->budget--) { s->failed_pc=0x0c0c12cau; return 0; }
r[1]|=r[2];
goto P_0c0c12cc;
P_0c0c12cc: /* original 0315, guest PC 0x0c0c12cc */
if(!s->budget--) { s->failed_pc=0x0c0c12ccu; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c0c12ce;
P_0c0c12ce: /* original 6bf6, guest PC 0x0c0c12ce */
if(!s->budget--) { s->failed_pc=0x0c0c12ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c12d0;
P_0c0c12d0: /* original 6cf6, guest PC 0x0c0c12d0 */
if(!s->budget--) { s->failed_pc=0x0c0c12d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c12d2;
P_0c0c12d2: /* original 6df6, guest PC 0x0c0c12d2 */
if(!s->budget--) { s->failed_pc=0x0c0c12d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c12d4;
P_0c0c12d4: /* original 000b, guest PC 0x0c0c12d4 */
if(!s->budget--) { s->failed_pc=0x0c0c12d4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c12d6: /* original 6ef6, guest PC 0x0c0c12d6 */
if(!s->budget--) { s->failed_pc=0x0c0c12d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c12d8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c12d8u; return 0; } return 1;
P_0c0c1836: /* original 2fe6, guest PC 0x0c0c1836 */
if(!s->budget--) { s->failed_pc=0x0c0c1836u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1838;
P_0c0c1838: /* original 6053, guest PC 0x0c0c1838 */
if(!s->budget--) { s->failed_pc=0x0c0c1838u; return 0; }
r[0]=r[5];
goto P_0c0c183a;
P_0c0c183a: /* original 2fc6, guest PC 0x0c0c183a */
if(!s->budget--) { s->failed_pc=0x0c0c183au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c183c;
P_0c0c183c: /* original e3f9, guest PC 0x0c0c183c */
if(!s->budget--) { s->failed_pc=0x0c0c183cu; return 0; }
r[3]=0xfffffff9u;
goto P_0c0c183e;
P_0c0c183e: /* original 2fb6, guest PC 0x0c0c183e */
if(!s->budget--) { s->failed_pc=0x0c0c183eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1840;
P_0c0c1840: /* original ec3f, guest PC 0x0c0c1840 */
if(!s->budget--) { s->failed_pc=0x0c0c1840u; return 0; }
r[12]=0x0000003fu;
goto P_0c0c1842;
P_0c0c1842: /* original 2fa6, guest PC 0x0c0c1842 */
if(!s->budget--) { s->failed_pc=0x0c0c1842u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1844;
P_0c0c1844: /* original eb3f, guest PC 0x0c0c1844 */
if(!s->budget--) { s->failed_pc=0x0c0c1844u; return 0; }
r[11]=0x0000003fu;
goto P_0c0c1846;
P_0c0c1846: /* original 453d, guest PC 0x0c0c1846 */
if(!s->budget--) { s->failed_pc=0x0c0c1846u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c0c1848;
P_0c0c1848: /* original 2f96, guest PC 0x0c0c1848 */
if(!s->budget--) { s->failed_pc=0x0c0c1848u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c184a;
P_0c0c184a: /* original 4001, guest PC 0x0c0c184a */
if(!s->budget--) { s->failed_pc=0x0c0c184au; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c0c184c;
P_0c0c184c: /* original 2f86, guest PC 0x0c0c184c */
if(!s->budget--) { s->failed_pc=0x0c0c184cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c184e;
P_0c0c184e: /* original 2b59, guest PC 0x0c0c184e */
if(!s->budget--) { s->failed_pc=0x0c0c184eu; return 0; }
r[11]&=r[5];
goto P_0c0c1850;
P_0c0c1850: /* original 5e43, guest PC 0x0c0c1850 */
if(!s->budget--) { s->failed_pc=0x0c0c1850u; return 0; }
r[14]=read(ram,r[4]+12,4);
goto P_0c0c1852;
P_0c0c1852: /* original 2c09, guest PC 0x0c0c1852 */
if(!s->budget--) { s->failed_pc=0x0c0c1852u; return 0; }
r[12]&=r[0];
goto P_0c0c1854;
P_0c0c1854: /* original e801, guest PC 0x0c0c1854 */
if(!s->budget--) { s->failed_pc=0x0c0c1854u; return 0; }
r[8]=0x00000001u;
goto P_0c0c1856;
P_0c0c1856: /* original ea00, guest PC 0x0c0c1856 */
if(!s->budget--) { s->failed_pc=0x0c0c1856u; return 0; }
r[10]=0x00000000u;
goto P_0c0c1858;
P_0c0c1858: /* original 36cc, guest PC 0x0c0c1858 */
if(!s->budget--) { s->failed_pc=0x0c0c1858u; return 0; }
r[6]+=r[12];
goto P_0c0c185a;
P_0c0c185a: /* original 37bc, guest PC 0x0c0c185a */
if(!s->budget--) { s->failed_pc=0x0c0c185au; return 0; }
r[7]+=r[11];
goto P_0c0c185c;
P_0c0c185c: /* original a021, guest PC 0x0c0c185c */
if(!s->budget--) { s->failed_pc=0x0c0c185cu; return 0; }
r[9]=r[10];
goto P_0c0c18a2;
P_0c0c185e: /* original 69a3, guest PC 0x0c0c185e */
if(!s->budget--) { s->failed_pc=0x0c0c185eu; return 0; }
r[9]=r[10];
goto P_0c0c1860;
P_0c0c1860: /* original 63e1, guest PC 0x0c0c1860 */
if(!s->budget--) { s->failed_pc=0x0c0c1860u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[3]=tmp;
goto P_0c0c1862;
P_0c0c1862: /* original 633d, guest PC 0x0c0c1862 */
if(!s->budget--) { s->failed_pc=0x0c0c1862u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c1864;
P_0c0c1864: /* original 2388, guest PC 0x0c0c1864 */
if(!s->budget--) { s->failed_pc=0x0c0c1864u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0c1866;
P_0c0c1866: /* original 891a, guest PC 0x0c0c1866 */
if(!s->budget--) { s->failed_pc=0x0c0c1866u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c1868;
P_0c0c1868: /* original 85e3, guest PC 0x0c0c1868 */
if(!s->budget--) { s->failed_pc=0x0c0c1868u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+6,2);
goto P_0c0c186a;
P_0c0c186a: /* original 610d, guest PC 0x0c0c186a */
if(!s->budget--) { s->failed_pc=0x0c0c186au; return 0; }
r[1]=r[0]&65535u;
goto P_0c0c186c;
P_0c0c186c: /* original 85e4, guest PC 0x0c0c186c */
if(!s->budget--) { s->failed_pc=0x0c0c186cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+8,2);
goto P_0c0c186e;
P_0c0c186e: /* original 3c17, guest PC 0x0c0c186e */
if(!s->budget--) { s->failed_pc=0x0c0c186eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>(int32_t)r[1])!=0);
goto P_0c0c1870;
P_0c0c1870: /* original 8d15, guest PC 0x0c0c1870 */
if(!s->budget--) { s->failed_pc=0x0c0c1870u; return 0; }
cond=r[17]&1u;
r[5]=r[0]&65535u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c1874;
P_0c0c1872: /* original 650d, guest PC 0x0c0c1872 */
if(!s->budget--) { s->failed_pc=0x0c0c1872u; return 0; }
r[5]=r[0]&65535u;
goto P_0c0c1874;
P_0c0c1874: /* original 3166, guest PC 0x0c0c1874 */
if(!s->budget--) { s->failed_pc=0x0c0c1874u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[6])!=0);
goto P_0c0c1876;
P_0c0c1876: /* original 8912, guest PC 0x0c0c1876 */
if(!s->budget--) { s->failed_pc=0x0c0c1876u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c1878;
P_0c0c1878: /* original 3b57, guest PC 0x0c0c1878 */
if(!s->budget--) { s->failed_pc=0x0c0c1878u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>(int32_t)r[5])!=0);
goto P_0c0c187a;
P_0c0c187a: /* original 8910, guest PC 0x0c0c187a */
if(!s->budget--) { s->failed_pc=0x0c0c187au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c187c;
P_0c0c187c: /* original 3576, guest PC 0x0c0c187c */
if(!s->budget--) { s->failed_pc=0x0c0c187cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[7])!=0);
goto P_0c0c187e;
P_0c0c187e: /* original 890e, guest PC 0x0c0c187e */
if(!s->budget--) { s->failed_pc=0x0c0c187eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c1880;
P_0c0c1880: /* original 85e5, guest PC 0x0c0c1880 */
if(!s->budget--) { s->failed_pc=0x0c0c1880u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+10,2);
goto P_0c0c1882;
P_0c0c1882: /* original 600d, guest PC 0x0c0c1882 */
if(!s->budget--) { s->failed_pc=0x0c0c1882u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c1884;
P_0c0c1884: /* original 310c, guest PC 0x0c0c1884 */
if(!s->budget--) { s->failed_pc=0x0c0c1884u; return 0; }
r[1]+=r[0];
goto P_0c0c1886;
P_0c0c1886: /* original 85e6, guest PC 0x0c0c1886 */
if(!s->budget--) { s->failed_pc=0x0c0c1886u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c0c1888;
P_0c0c1888: /* original 3c17, guest PC 0x0c0c1888 */
if(!s->budget--) { s->failed_pc=0x0c0c1888u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>(int32_t)r[1])!=0);
goto P_0c0c188a;
P_0c0c188a: /* original 600d, guest PC 0x0c0c188a */
if(!s->budget--) { s->failed_pc=0x0c0c188au; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c188c;
P_0c0c188c: /* original 8d07, guest PC 0x0c0c188c */
if(!s->budget--) { s->failed_pc=0x0c0c188cu; return 0; }
cond=r[17]&1u;
r[5]+=r[0];
if(cond) { goto P_0c0c189e; }
goto P_0c0c1890;
P_0c0c188e: /* original 350c, guest PC 0x0c0c188e */
if(!s->budget--) { s->failed_pc=0x0c0c188eu; return 0; }
r[5]+=r[0];
goto P_0c0c1890;
P_0c0c1890: /* original 3166, guest PC 0x0c0c1890 */
if(!s->budget--) { s->failed_pc=0x0c0c1890u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[6])!=0);
goto P_0c0c1892;
P_0c0c1892: /* original 8904, guest PC 0x0c0c1892 */
if(!s->budget--) { s->failed_pc=0x0c0c1892u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c1894;
P_0c0c1894: /* original 3b57, guest PC 0x0c0c1894 */
if(!s->budget--) { s->failed_pc=0x0c0c1894u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>(int32_t)r[5])!=0);
goto P_0c0c1896;
P_0c0c1896: /* original 8902, guest PC 0x0c0c1896 */
if(!s->budget--) { s->failed_pc=0x0c0c1896u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c1898;
P_0c0c1898: /* original 3576, guest PC 0x0c0c1898 */
if(!s->budget--) { s->failed_pc=0x0c0c1898u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[7])!=0);
goto P_0c0c189a;
P_0c0c189a: /* original 8900, guest PC 0x0c0c189a */
if(!s->budget--) { s->failed_pc=0x0c0c189au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c189c;
P_0c0c189c: /* original 2ea1, guest PC 0x0c0c189c */
if(!s->budget--) { s->failed_pc=0x0c0c189cu; return 0; }
write(ram,r[14],r[10],2);
goto P_0c0c189e;
P_0c0c189e: /* original 7e44, guest PC 0x0c0c189e */
if(!s->budget--) { s->failed_pc=0x0c0c189eu; return 0; }
r[14]+=0x00000044u;
goto P_0c0c18a0;
P_0c0c18a0: /* original 7901, guest PC 0x0c0c18a0 */
if(!s->budget--) { s->failed_pc=0x0c0c18a0u; return 0; }
r[9]+=0x00000001u;
goto P_0c0c18a2;
P_0c0c18a2: /* original e278, guest PC 0x0c0c18a2 */
if(!s->budget--) { s->failed_pc=0x0c0c18a2u; return 0; }
r[2]=0x00000078u;
goto P_0c0c18a4;
P_0c0c18a4: /* original 3922, guest PC 0x0c0c18a4 */
if(!s->budget--) { s->failed_pc=0x0c0c18a4u; return 0; }
r[17]=(r[17]&~1u)|((r[9]>=r[2])!=0);
goto P_0c0c18a6;
P_0c0c18a6: /* original 8bdb, guest PC 0x0c0c18a6 */
if(!s->budget--) { s->failed_pc=0x0c0c18a6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1860; }
goto P_0c0c18a8;
P_0c0c18a8: /* original e022, guest PC 0x0c0c18a8 */
if(!s->budget--) { s->failed_pc=0x0c0c18a8u; return 0; }
r[0]=0x00000022u;
goto P_0c0c18aa;
P_0c0c18aa: /* original 024d, guest PC 0x0c0c18aa */
if(!s->budget--) { s->failed_pc=0x0c0c18aau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c18ac;
P_0c0c18ac: /* original e301, guest PC 0x0c0c18ac */
if(!s->budget--) { s->failed_pc=0x0c0c18acu; return 0; }
r[3]=0x00000001u;
goto P_0c0c18ae;
P_0c0c18ae: /* original 223b, guest PC 0x0c0c18ae */
if(!s->budget--) { s->failed_pc=0x0c0c18aeu; return 0; }
r[2]|=r[3];
goto P_0c0c18b0;
P_0c0c18b0: /* original 0425, guest PC 0x0c0c18b0 */
if(!s->budget--) { s->failed_pc=0x0c0c18b0u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0c18b2;
P_0c0c18b2: /* original 68f6, guest PC 0x0c0c18b2 */
if(!s->budget--) { s->failed_pc=0x0c0c18b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c18b4;
P_0c0c18b4: /* original 69f6, guest PC 0x0c0c18b4 */
if(!s->budget--) { s->failed_pc=0x0c0c18b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c18b6;
P_0c0c18b6: /* original 6af6, guest PC 0x0c0c18b6 */
if(!s->budget--) { s->failed_pc=0x0c0c18b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c18b8;
P_0c0c18b8: /* original 6bf6, guest PC 0x0c0c18b8 */
if(!s->budget--) { s->failed_pc=0x0c0c18b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c18ba;
P_0c0c18ba: /* original 6cf6, guest PC 0x0c0c18ba */
if(!s->budget--) { s->failed_pc=0x0c0c18bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c18bc;
P_0c0c18bc: /* original 000b, guest PC 0x0c0c18bc */
if(!s->budget--) { s->failed_pc=0x0c0c18bcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c18be: /* original 6ef6, guest PC 0x0c0c18be */
if(!s->budget--) { s->failed_pc=0x0c0c18beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c18c0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c18c0u; return 0; } return 1;
P_0c0c1a62: /* original 000b, guest PC 0x0c0c1a62 */
if(!s->budget--) { s->failed_pc=0x0c0c1a62u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c1a64: /* original 0009, guest PC 0x0c0c1a64 */
if(!s->budget--) { s->failed_pc=0x0c0c1a64u; return 0; }
if(!vf3_matrix_family(0x0c0c1a66u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c1a66u; return 0; } return 1;
P_0c0c27aa: /* original 2fe6, guest PC 0x0c0c27aa */
if(!s->budget--) { s->failed_pc=0x0c0c27aau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c27ac;
P_0c0c27ac: /* original d324, guest PC 0x0c0c27ac */
if(!s->budget--) { s->failed_pc=0x0c0c27acu; return 0; }
r[3]=read(ram,0x0c0c2840u,4);
goto P_0c0c27ae;
P_0c0c27ae: /* original 4f22, guest PC 0x0c0c27ae */
if(!s->budget--) { s->failed_pc=0x0c0c27aeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c27b0;
P_0c0c27b0: /* original d224, guest PC 0x0c0c27b0 */
if(!s->budget--) { s->failed_pc=0x0c0c27b0u; return 0; }
r[2]=read(ram,0x0c0c2844u,4);
goto P_0c0c27b2;
P_0c0c27b2: /* original 6532, guest PC 0x0c0c27b2 */
if(!s->budget--) { s->failed_pc=0x0c0c27b2u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c0c27b4;
P_0c0c27b4: /* original 420b, guest PC 0x0c0c27b4 */
if(!s->budget--) { s->failed_pc=0x0c0c27b4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c27b8u;
r[4]=0x0000001du;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c27b8u) { target=s->pc; goto dispatch; }
goto P_0c0c27b8;
P_0c0c27b6: /* original e41d, guest PC 0x0c0c27b6 */
if(!s->budget--) { s->failed_pc=0x0c0c27b6u; return 0; }
r[4]=0x0000001du;
goto P_0c0c27b8;
P_0c0c27b8: /* original de1c, guest PC 0x0c0c27b8 */
if(!s->budget--) { s->failed_pc=0x0c0c27b8u; return 0; }
r[14]=read(ram,0x0c0c282cu,4);
goto P_0c0c27ba;
P_0c0c27ba: /* original 942f, guest PC 0x0c0c27ba */
if(!s->budget--) { s->failed_pc=0x0c0c27bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c281cu,2);
goto P_0c0c27bc;
P_0c0c27bc: /* original d31c, guest PC 0x0c0c27bc */
if(!s->budget--) { s->failed_pc=0x0c0c27bcu; return 0; }
r[3]=read(ram,0x0c0c2830u,4);
goto P_0c0c27be;
P_0c0c27be: /* original 66e3, guest PC 0x0c0c27be */
if(!s->budget--) { s->failed_pc=0x0c0c27beu; return 0; }
r[6]=r[14];
goto P_0c0c27c0;
P_0c0c27c0: /* original 7658, guest PC 0x0c0c27c0 */
if(!s->budget--) { s->failed_pc=0x0c0c27c0u; return 0; }
r[6]+=0x00000058u;
goto P_0c0c27c2;
P_0c0c27c2: /* original 430b, guest PC 0x0c0c27c2 */
if(!s->budget--) { s->failed_pc=0x0c0c27c2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c27c6u;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c27c6u) { target=s->pc; goto dispatch; }
goto P_0c0c27c6;
P_0c0c27c4: /* original 65e3, guest PC 0x0c0c27c4 */
if(!s->budget--) { s->failed_pc=0x0c0c27c4u; return 0; }
r[5]=r[14];
goto P_0c0c27c6;
P_0c0c27c6: /* original d220, guest PC 0x0c0c27c6 */
if(!s->budget--) { s->failed_pc=0x0c0c27c6u; return 0; }
r[2]=read(ram,0x0c0c2848u,4);
goto P_0c0c27c8;
P_0c0c27c8: /* original 420b, guest PC 0x0c0c27c8 */
if(!s->budget--) { s->failed_pc=0x0c0c27c8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c27ccu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c27ccu) { target=s->pc; goto dispatch; }
goto P_0c0c27cc;
P_0c0c27ca: /* original 64e3, guest PC 0x0c0c27ca */
if(!s->budget--) { s->failed_pc=0x0c0c27cau; return 0; }
r[4]=r[14];
goto P_0c0c27cc;
P_0c0c27cc: /* original e300, guest PC 0x0c0c27cc */
if(!s->budget--) { s->failed_pc=0x0c0c27ccu; return 0; }
r[3]=0x00000000u;
goto P_0c0c27ce;
P_0c0c27ce: /* original 64e3, guest PC 0x0c0c27ce */
if(!s->budget--) { s->failed_pc=0x0c0c27ceu; return 0; }
r[4]=r[14];
goto P_0c0c27d0;
P_0c0c27d0: /* original 6533, guest PC 0x0c0c27d0 */
if(!s->budget--) { s->failed_pc=0x0c0c27d0u; return 0; }
r[5]=r[3];
goto P_0c0c27d2;
P_0c0c27d2: /* original e63f, guest PC 0x0c0c27d2 */
if(!s->budget--) { s->failed_pc=0x0c0c27d2u; return 0; }
r[6]=0x0000003fu;
goto P_0c0c27d4;
P_0c0c27d4: /* original 2f36, guest PC 0x0c0c27d4 */
if(!s->budget--) { s->failed_pc=0x0c0c27d4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c27d6;
P_0c0c27d6: /* original e731, guest PC 0x0c0c27d6 */
if(!s->budget--) { s->failed_pc=0x0c0c27d6u; return 0; }
r[7]=0x00000031u;
goto P_0c0c27d8;
P_0c0c27d8: /* original b82d, guest PC 0x0c0c27d8 */
if(!s->budget--) { s->failed_pc=0x0c0c27d8u; return 0; }
target=code_base|0x0c0c1836u; r[16]=code_base|0x0c0c27dcu;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c27dcu) { target=s->pc; goto dispatch; }
goto P_0c0c27dc;
P_0c0c27da: /* original 7458, guest PC 0x0c0c27da */
if(!s->budget--) { s->failed_pc=0x0c0c27dau; return 0; }
r[4]+=0x00000058u;
goto P_0c0c27dc;
P_0c0c27dc: /* original 901f, guest PC 0x0c0c27dc */
if(!s->budget--) { s->failed_pc=0x0c0c27dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c281eu,2);
goto P_0c0c27de;
P_0c0c27de: /* original e400, guest PC 0x0c0c27de */
if(!s->budget--) { s->failed_pc=0x0c0c27deu; return 0; }
r[4]=0x00000000u;
goto P_0c0c27e0;
P_0c0c27e0: /* original e32f, guest PC 0x0c0c27e0 */
if(!s->budget--) { s->failed_pc=0x0c0c27e0u; return 0; }
r[3]=0x0000002fu;
goto P_0c0c27e2;
P_0c0c27e2: /* original 0e46, guest PC 0x0c0c27e2 */
if(!s->budget--) { s->failed_pc=0x0c0c27e2u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c27e4;
P_0c0c27e4: /* original 7f04, guest PC 0x0c0c27e4 */
if(!s->budget--) { s->failed_pc=0x0c0c27e4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c27e6;
P_0c0c27e6: /* original 901b, guest PC 0x0c0c27e6 */
if(!s->budget--) { s->failed_pc=0x0c0c27e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2820u,2);
goto P_0c0c27e8;
P_0c0c27e8: /* original 0e46, guest PC 0x0c0c27e8 */
if(!s->budget--) { s->failed_pc=0x0c0c27e8u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c27ea;
P_0c0c27ea: /* original 901a, guest PC 0x0c0c27ea */
if(!s->budget--) { s->failed_pc=0x0c0c27eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2822u,2);
goto P_0c0c27ec;
P_0c0c27ec: /* original 0e35, guest PC 0x0c0c27ec */
if(!s->budget--) { s->failed_pc=0x0c0c27ecu; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0c27ee;
P_0c0c27ee: /* original d317, guest PC 0x0c0c27ee */
if(!s->budget--) { s->failed_pc=0x0c0c27eeu; return 0; }
r[3]=read(ram,0x0c0c284cu,4);
goto P_0c0c27f0;
P_0c0c27f0: /* original 430b, guest PC 0x0c0c27f0 */
if(!s->budget--) { s->failed_pc=0x0c0c27f0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c27f4u;
r[4]=0x00000015u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c27f4u) { target=s->pc; goto dispatch; }
goto P_0c0c27f4;
P_0c0c27f2: /* original e415, guest PC 0x0c0c27f2 */
if(!s->budget--) { s->failed_pc=0x0c0c27f2u; return 0; }
r[4]=0x00000015u;
goto P_0c0c27f4;
P_0c0c27f4: /* original d317, guest PC 0x0c0c27f4 */
if(!s->budget--) { s->failed_pc=0x0c0c27f4u; return 0; }
r[3]=read(ram,0x0c0c2854u,4);
goto P_0c0c27f6;
P_0c0c27f6: /* original d416, guest PC 0x0c0c27f6 */
if(!s->budget--) { s->failed_pc=0x0c0c27f6u; return 0; }
r[4]=read(ram,0x0c0c2850u,4);
goto P_0c0c27f8;
P_0c0c27f8: /* original d211, guest PC 0x0c0c27f8 */
if(!s->budget--) { s->failed_pc=0x0c0c27f8u; return 0; }
r[2]=read(ram,0x0c0c2840u,4);
goto P_0c0c27fa;
P_0c0c27fa: /* original 430b, guest PC 0x0c0c27fa */
if(!s->budget--) { s->failed_pc=0x0c0c27fau; return 0; }
target=r[3];
r[16]=code_base|0x0c0c27feu;
tmp=read(ram,r[2],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c27feu) { target=s->pc; goto dispatch; }
goto P_0c0c27fe;
P_0c0c27fc: /* original 6522, guest PC 0x0c0c27fc */
if(!s->budget--) { s->failed_pc=0x0c0c27fcu; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c0c27fe;
P_0c0c27fe: /* original 4f26, guest PC 0x0c0c27fe */
if(!s->budget--) { s->failed_pc=0x0c0c27feu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c2800;
P_0c0c2800: /* original d215, guest PC 0x0c0c2800 */
if(!s->budget--) { s->failed_pc=0x0c0c2800u; return 0; }
r[2]=read(ram,0x0c0c2858u,4);
goto P_0c0c2802;
P_0c0c2802: /* original e315, guest PC 0x0c0c2802 */
if(!s->budget--) { s->failed_pc=0x0c0c2802u; return 0; }
r[3]=0x00000015u;
goto P_0c0c2804;
P_0c0c2804: /* original 2231, guest PC 0x0c0c2804 */
if(!s->budget--) { s->failed_pc=0x0c0c2804u; return 0; }
write(ram,r[2],r[3],2);
goto P_0c0c2806;
P_0c0c2806: /* original 000b, guest PC 0x0c0c2806 */
if(!s->budget--) { s->failed_pc=0x0c0c2806u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c2808: /* original 6ef6, guest PC 0x0c0c2808 */
if(!s->budget--) { s->failed_pc=0x0c0c2808u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c280au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c280au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
