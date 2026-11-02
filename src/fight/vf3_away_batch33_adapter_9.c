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
int vf3_away_batch33_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c0c6742u: goto P_0c0c6742;
case 0x0c0c6744u: goto P_0c0c6744;
case 0x0c0c6746u: goto P_0c0c6746;
case 0x0c0c6748u: goto P_0c0c6748;
default: return vf3_matrix_family(target,s,ram);
}
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
P_0c0c6742: /* original 9049, guest PC 0x0c0c6742 */
if(!s->budget--) { s->failed_pc=0x0c0c6742u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c67d8u,2);
goto P_0c0c6744;
P_0c0c6744: /* original d426, guest PC 0x0c0c6744 */
if(!s->budget--) { s->failed_pc=0x0c0c6744u; return 0; }
r[4]=read(ram,0x0c0c67e0u,4);
goto P_0c0c6746;
P_0c0c6746: /* original 000b, guest PC 0x0c0c6746 */
if(!s->budget--) { s->failed_pc=0x0c0c6746u; return 0; }
target=r[16];
r[0]=read(ram,r[4]+r[0],4);
s->pc=target; return ram->oob==0;
P_0c0c6748: /* original 004e, guest PC 0x0c0c6748 */
if(!s->budget--) { s->failed_pc=0x0c0c6748u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
if(!vf3_matrix_family(0x0c0c674au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c674au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
