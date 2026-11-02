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
int vf3_away_batch3_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042240u: goto P_0c042240;
case 0x0c042242u: goto P_0c042242;
case 0x0c042244u: goto P_0c042244;
case 0x0c042246u: goto P_0c042246;
case 0x0c042248u: goto P_0c042248;
case 0x0c04224au: goto P_0c04224a;
case 0x0c04224cu: goto P_0c04224c;
case 0x0c04224eu: goto P_0c04224e;
case 0x0c042250u: goto P_0c042250;
case 0x0c042252u: goto P_0c042252;
case 0x0c042254u: goto P_0c042254;
case 0x0c042256u: goto P_0c042256;
case 0x0c042258u: goto P_0c042258;
case 0x0c04225au: goto P_0c04225a;
case 0x0c04225cu: goto P_0c04225c;
case 0x0c04225eu: goto P_0c04225e;
case 0x0c042260u: goto P_0c042260;
case 0x0c042262u: goto P_0c042262;
case 0x0c042264u: goto P_0c042264;
case 0x0c042266u: goto P_0c042266;
case 0x0c042268u: goto P_0c042268;
case 0x0c04226au: goto P_0c04226a;
case 0x0c04226cu: goto P_0c04226c;
case 0x0c04226eu: goto P_0c04226e;
case 0x0c042270u: goto P_0c042270;
case 0x0c042272u: goto P_0c042272;
case 0x0c042274u: goto P_0c042274;
case 0x0c042276u: goto P_0c042276;
case 0x0c042278u: goto P_0c042278;
case 0x0c04227au: goto P_0c04227a;
case 0x0c04227cu: goto P_0c04227c;
case 0x0c042280u: goto P_0c042280;
case 0x0c042282u: goto P_0c042282;
case 0x0c042284u: goto P_0c042284;
case 0x0c042286u: goto P_0c042286;
case 0x0c042288u: goto P_0c042288;
case 0x0c04228au: goto P_0c04228a;
case 0x0c04228cu: goto P_0c04228c;
case 0x0c04228eu: goto P_0c04228e;
case 0x0c042290u: goto P_0c042290;
case 0x0c042292u: goto P_0c042292;
case 0x0c042294u: goto P_0c042294;
case 0x0c042296u: goto P_0c042296;
case 0x0c042298u: goto P_0c042298;
case 0x0c04229au: goto P_0c04229a;
case 0x0c04229cu: goto P_0c04229c;
case 0x0c04229eu: goto P_0c04229e;
case 0x0c0422a0u: goto P_0c0422a0;
case 0x0c0422a2u: goto P_0c0422a2;
case 0x0c0422a4u: goto P_0c0422a4;
case 0x0c0422a6u: goto P_0c0422a6;
case 0x0c0422a8u: goto P_0c0422a8;
case 0x0c0422aau: goto P_0c0422aa;
case 0x0c0422acu: goto P_0c0422ac;
case 0x0c0422aeu: goto P_0c0422ae;
case 0x0c0422b0u: goto P_0c0422b0;
case 0x0c0422b2u: goto P_0c0422b2;
case 0x0c0422b4u: goto P_0c0422b4;
case 0x0c0422b6u: goto P_0c0422b6;
case 0x0c0422b8u: goto P_0c0422b8;
case 0x0c0422bau: goto P_0c0422ba;
case 0x0c0422bcu: goto P_0c0422bc;
case 0x0c0422beu: goto P_0c0422be;
case 0x0c0422c0u: goto P_0c0422c0;
case 0x0c0422c2u: goto P_0c0422c2;
case 0x0c0422c4u: goto P_0c0422c4;
case 0x0c0422c6u: goto P_0c0422c6;
case 0x0c0422d0u: goto P_0c0422d0;
case 0x0c0422d2u: goto P_0c0422d2;
case 0x0c0422d4u: goto P_0c0422d4;
case 0x0c0422d6u: goto P_0c0422d6;
case 0x0c0422d8u: goto P_0c0422d8;
case 0x0c0422dau: goto P_0c0422da;
case 0x0c0422dcu: goto P_0c0422dc;
case 0x0c0422deu: goto P_0c0422de;
case 0x0c0422e0u: goto P_0c0422e0;
case 0x0c0422e2u: goto P_0c0422e2;
case 0x0c0422e4u: goto P_0c0422e4;
case 0x0c0422e6u: goto P_0c0422e6;
case 0x0c0422e8u: goto P_0c0422e8;
case 0x0c0422eau: goto P_0c0422ea;
case 0x0c0422ecu: goto P_0c0422ec;
case 0x0c0422eeu: goto P_0c0422ee;
case 0x0c0422f0u: goto P_0c0422f0;
case 0x0c0422f2u: goto P_0c0422f2;
case 0x0c0422f4u: goto P_0c0422f4;
case 0x0c0422f6u: goto P_0c0422f6;
case 0x0c0422f8u: goto P_0c0422f8;
case 0x0c0422fau: goto P_0c0422fa;
case 0x0c0422fcu: goto P_0c0422fc;
case 0x0c0422feu: goto P_0c0422fe;
case 0x0c042300u: goto P_0c042300;
case 0x0c042302u: goto P_0c042302;
case 0x0c042304u: goto P_0c042304;
case 0x0c042306u: goto P_0c042306;
case 0x0c042308u: goto P_0c042308;
case 0x0c04230au: goto P_0c04230a;
case 0x0c04230cu: goto P_0c04230c;
case 0x0c04230eu: goto P_0c04230e;
case 0x0c042310u: goto P_0c042310;
case 0x0c042312u: goto P_0c042312;
case 0x0c042314u: goto P_0c042314;
case 0x0c042316u: goto P_0c042316;
case 0x0c042318u: goto P_0c042318;
case 0x0c04231au: goto P_0c04231a;
case 0x0c04231cu: goto P_0c04231c;
case 0x0c04231eu: goto P_0c04231e;
case 0x0c042320u: goto P_0c042320;
case 0x0c042322u: goto P_0c042322;
case 0x0c042324u: goto P_0c042324;
case 0x0c042326u: goto P_0c042326;
case 0x0c0423b0u: goto P_0c0423b0;
case 0x0c0423b2u: goto P_0c0423b2;
case 0x0c0423b4u: goto P_0c0423b4;
case 0x0c0423b6u: goto P_0c0423b6;
case 0x0c0423b8u: goto P_0c0423b8;
case 0x0c0423bau: goto P_0c0423ba;
case 0x0c0423bcu: goto P_0c0423bc;
case 0x0c0423beu: goto P_0c0423be;
case 0x0c0423c0u: goto P_0c0423c0;
case 0x0c0423c2u: goto P_0c0423c2;
case 0x0c0423c4u: goto P_0c0423c4;
case 0x0c0423c6u: goto P_0c0423c6;
case 0x0c0423c8u: goto P_0c0423c8;
case 0x0c0423cau: goto P_0c0423ca;
case 0x0c0423ccu: goto P_0c0423cc;
case 0x0c0423ceu: goto P_0c0423ce;
case 0x0c0423d0u: goto P_0c0423d0;
case 0x0c0423d2u: goto P_0c0423d2;
case 0x0c0423d4u: goto P_0c0423d4;
case 0x0c0423d6u: goto P_0c0423d6;
case 0x0c0423d8u: goto P_0c0423d8;
case 0x0c0423dau: goto P_0c0423da;
case 0x0c0423dcu: goto P_0c0423dc;
case 0x0c0423deu: goto P_0c0423de;
case 0x0c0423e0u: goto P_0c0423e0;
case 0x0c0423e2u: goto P_0c0423e2;
case 0x0c0423e4u: goto P_0c0423e4;
case 0x0c0423e6u: goto P_0c0423e6;
case 0x0c0423e8u: goto P_0c0423e8;
case 0x0c0423eau: goto P_0c0423ea;
case 0x0c0423ecu: goto P_0c0423ec;
case 0x0c0423eeu: goto P_0c0423ee;
case 0x0c0423f0u: goto P_0c0423f0;
case 0x0c0423f2u: goto P_0c0423f2;
case 0x0c0423f4u: goto P_0c0423f4;
case 0x0c0423f6u: goto P_0c0423f6;
case 0x0c0423f8u: goto P_0c0423f8;
case 0x0c0423fau: goto P_0c0423fa;
case 0x0c0423fcu: goto P_0c0423fc;
case 0x0c0423feu: goto P_0c0423fe;
case 0x0c042400u: goto P_0c042400;
case 0x0c042402u: goto P_0c042402;
case 0x0c042404u: goto P_0c042404;
case 0x0c042406u: goto P_0c042406;
case 0x0c042408u: goto P_0c042408;
case 0x0c04240au: goto P_0c04240a;
case 0x0c04240cu: goto P_0c04240c;
case 0x0c04240eu: goto P_0c04240e;
case 0x0c042410u: goto P_0c042410;
case 0x0c042412u: goto P_0c042412;
case 0x0c042414u: goto P_0c042414;
case 0x0c042416u: goto P_0c042416;
case 0x0c042418u: goto P_0c042418;
case 0x0c04241au: goto P_0c04241a;
case 0x0c04241cu: goto P_0c04241c;
case 0x0c04241eu: goto P_0c04241e;
case 0x0c042420u: goto P_0c042420;
case 0x0c042422u: goto P_0c042422;
case 0x0c042424u: goto P_0c042424;
case 0x0c042426u: goto P_0c042426;
case 0x0c042428u: goto P_0c042428;
case 0x0c04242au: goto P_0c04242a;
case 0x0c04242cu: goto P_0c04242c;
case 0x0c04242eu: goto P_0c04242e;
case 0x0c042430u: goto P_0c042430;
case 0x0c042432u: goto P_0c042432;
case 0x0c042434u: goto P_0c042434;
case 0x0c042436u: goto P_0c042436;
case 0x0c042438u: goto P_0c042438;
case 0x0c04243au: goto P_0c04243a;
case 0x0c04243cu: goto P_0c04243c;
case 0x0c04243eu: goto P_0c04243e;
case 0x0c042440u: goto P_0c042440;
case 0x0c042442u: goto P_0c042442;
case 0x0c042444u: goto P_0c042444;
case 0x0c042446u: goto P_0c042446;
case 0x0c042448u: goto P_0c042448;
case 0x0c04244au: goto P_0c04244a;
case 0x0c04244cu: goto P_0c04244c;
case 0x0c04244eu: goto P_0c04244e;
case 0x0c042450u: goto P_0c042450;
case 0x0c042460u: goto P_0c042460;
case 0x0c042462u: goto P_0c042462;
case 0x0c042464u: goto P_0c042464;
case 0x0c042466u: goto P_0c042466;
case 0x0c042468u: goto P_0c042468;
case 0x0c04246au: goto P_0c04246a;
case 0x0c04246cu: goto P_0c04246c;
case 0x0c04246eu: goto P_0c04246e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c042240: /* original 2fe6, guest PC 0x0c042240 */
if(!s->budget--) { s->failed_pc=0x0c042240u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042242;
P_0c042242: /* original 741f, guest PC 0x0c042242 */
if(!s->budget--) { s->failed_pc=0x0c042242u; return 0; }
r[4]+=0x0000001fu;
goto P_0c042244;
P_0c042244: /* original 2fd6, guest PC 0x0c042244 */
if(!s->budget--) { s->failed_pc=0x0c042244u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042246;
P_0c042246: /* original e3e0, guest PC 0x0c042246 */
if(!s->budget--) { s->failed_pc=0x0c042246u; return 0; }
r[3]=0xffffffe0u;
goto P_0c042248;
P_0c042248: /* original 2fc6, guest PC 0x0c042248 */
if(!s->budget--) { s->failed_pc=0x0c042248u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04224a;
P_0c04224a: /* original 2439, guest PC 0x0c04224a */
if(!s->budget--) { s->failed_pc=0x0c04224au; return 0; }
r[4]&=r[3];
goto P_0c04224c;
P_0c04224c: /* original 2fb6, guest PC 0x0c04224c */
if(!s->budget--) { s->failed_pc=0x0c04224cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04224e;
P_0c04224e: /* original 6243, guest PC 0x0c04224e */
if(!s->budget--) { s->failed_pc=0x0c04224eu; return 0; }
r[2]=r[4];
goto P_0c042250;
P_0c042250: /* original 2fa6, guest PC 0x0c042250 */
if(!s->budget--) { s->failed_pc=0x0c042250u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042252;
P_0c042252: /* original 2228, guest PC 0x0c042252 */
if(!s->budget--) { s->failed_pc=0x0c042252u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c042254;
P_0c042254: /* original 2f96, guest PC 0x0c042254 */
if(!s->budget--) { s->failed_pc=0x0c042254u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042256;
P_0c042256: /* original 2f86, guest PC 0x0c042256 */
if(!s->budget--) { s->failed_pc=0x0c042256u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042258;
P_0c042258: /* original 4f22, guest PC 0x0c042258 */
if(!s->budget--) { s->failed_pc=0x0c042258u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04225a;
P_0c04225a: /* original dc34, guest PC 0x0c04225a */
if(!s->budget--) { s->failed_pc=0x0c04225au; return 0; }
r[12]=read(ram,0x0c04232cu,4);
goto P_0c04225c;
P_0c04225c: /* original 8d5b, guest PC 0x0c04225c */
if(!s->budget--) { s->failed_pc=0x0c04225cu; return 0; }
cond=r[17]&1u;
write(ram,r[12],r[4],4);
if(cond) { goto P_0c042316; }
goto P_0c042260;
P_0c04225e: /* original 2c42, guest PC 0x0c04225e */
if(!s->budget--) { s->failed_pc=0x0c04225eu; return 0; }
write(ram,r[12],r[4],4);
goto P_0c042260;
P_0c042260: /* original d234, guest PC 0x0c042260 */
if(!s->budget--) { s->failed_pc=0x0c042260u; return 0; }
r[2]=read(ram,0x0c042334u,4);
goto P_0c042262;
P_0c042262: /* original ee00, guest PC 0x0c042262 */
if(!s->budget--) { s->failed_pc=0x0c042262u; return 0; }
r[14]=0x00000000u;
goto P_0c042264;
P_0c042264: /* original d432, guest PC 0x0c042264 */
if(!s->budget--) { s->failed_pc=0x0c042264u; return 0; }
r[4]=read(ram,0x0c042330u,4);
goto P_0c042266;
P_0c042266: /* original 6be3, guest PC 0x0c042266 */
if(!s->budget--) { s->failed_pc=0x0c042266u; return 0; }
r[11]=r[14];
goto P_0c042268;
P_0c042268: /* original 2422, guest PC 0x0c042268 */
if(!s->budget--) { s->failed_pc=0x0c042268u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c04226a;
P_0c04226a: /* original d133, guest PC 0x0c04226a */
if(!s->budget--) { s->failed_pc=0x0c04226au; return 0; }
r[1]=read(ram,0x0c042338u,4);
goto P_0c04226c;
P_0c04226c: /* original 1411, guest PC 0x0c04226c */
if(!s->budget--) { s->failed_pc=0x0c04226cu; return 0; }
write(ram,r[4]+4,r[1],4);
goto P_0c04226e;
P_0c04226e: /* original e1ff, guest PC 0x0c04226e */
if(!s->budget--) { s->failed_pc=0x0c04226eu; return 0; }
r[1]=0xffffffffu;
goto P_0c042270;
P_0c042270: /* original d232, guest PC 0x0c042270 */
if(!s->budget--) { s->failed_pc=0x0c042270u; return 0; }
r[2]=read(ram,0x0c04233cu,4);
goto P_0c042272;
P_0c042272: /* original 1422, guest PC 0x0c042272 */
if(!s->budget--) { s->failed_pc=0x0c042272u; return 0; }
write(ram,r[4]+8,r[2],4);
goto P_0c042274;
P_0c042274: /* original 1414, guest PC 0x0c042274 */
if(!s->budget--) { s->failed_pc=0x0c042274u; return 0; }
write(ram,r[4]+16,r[1],4);
goto P_0c042276;
P_0c042276: /* original d832, guest PC 0x0c042276 */
if(!s->budget--) { s->failed_pc=0x0c042276u; return 0; }
r[8]=read(ram,0x0c042340u,4);
goto P_0c042278;
P_0c042278: /* original 9a56, guest PC 0x0c042278 */
if(!s->budget--) { s->failed_pc=0x0c042278u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042328u,2);
goto P_0c04227a;
P_0c04227a: /* original a02a, guest PC 0x0c04227a */
if(!s->budget--) { s->failed_pc=0x0c04227au; return 0; }
r[9]=0x00000003u;
goto P_0c0422d2;
P_0c04227c: /* original e903, guest PC 0x0c04227c */
if(!s->budget--) { s->failed_pc=0x0c04227cu; return 0; }
r[9]=0x00000003u;
if(!vf3_matrix_family(0x0c04227eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04227eu; return 0; } return 1;
P_0c042280: /* original 64b3, guest PC 0x0c042280 */
if(!s->budget--) { s->failed_pc=0x0c042280u; return 0; }
r[4]=r[11];
goto P_0c042282;
P_0c042282: /* original 63b3, guest PC 0x0c042282 */
if(!s->budget--) { s->failed_pc=0x0c042282u; return 0; }
r[3]=r[11];
goto P_0c042284;
P_0c042284: /* original 4408, guest PC 0x0c042284 */
if(!s->budget--) { s->failed_pc=0x0c042284u; return 0; }
r[4]<<=2;
goto P_0c042286;
P_0c042286: /* original d22f, guest PC 0x0c042286 */
if(!s->budget--) { s->failed_pc=0x0c042286u; return 0; }
r[2]=read(ram,0x0c042344u,4);
goto P_0c042288;
P_0c042288: /* original 343c, guest PC 0x0c042288 */
if(!s->budget--) { s->failed_pc=0x0c042288u; return 0; }
r[4]+=r[3];
goto P_0c04228a;
P_0c04228a: /* original 974e, guest PC 0x0c04228a */
if(!s->budget--) { s->failed_pc=0x0c04228au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04232au,2);
goto P_0c04228c;
P_0c04228c: /* original 4408, guest PC 0x0c04228c */
if(!s->budget--) { s->failed_pc=0x0c04228cu; return 0; }
r[4]<<=2;
goto P_0c04228e;
P_0c04228e: /* original 65a3, guest PC 0x0c04228e */
if(!s->budget--) { s->failed_pc=0x0c04228eu; return 0; }
r[5]=r[10];
goto P_0c042290;
P_0c042290: /* original 4400, guest PC 0x0c042290 */
if(!s->budget--) { s->failed_pc=0x0c042290u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c042292;
P_0c042292: /* original 66a3, guest PC 0x0c042292 */
if(!s->budget--) { s->failed_pc=0x0c042292u; return 0; }
r[6]=r[10];
goto P_0c042294;
P_0c042294: /* original 644e, guest PC 0x0c042294 */
if(!s->budget--) { s->failed_pc=0x0c042294u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c042296;
P_0c042296: /* original 420b, guest PC 0x0c042296 */
if(!s->budget--) { s->failed_pc=0x0c042296u; return 0; }
target=r[2];
r[16]=code_base|0x0c04229au;
r[4]+=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04229au) { target=s->pc; goto dispatch; }
goto P_0c04229a;
P_0c042298: /* original 348c, guest PC 0x0c042298 */
if(!s->budget--) { s->failed_pc=0x0c042298u; return 0; }
r[4]+=r[8];
goto P_0c04229a;
P_0c04229a: /* original 6d03, guest PC 0x0c04229a */
if(!s->budget--) { s->failed_pc=0x0c04229au; return 0; }
r[13]=r[0];
goto P_0c04229c;
P_0c04229c: /* original 2dd8, guest PC 0x0c04229c */
if(!s->budget--) { s->failed_pc=0x0c04229cu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c04229e;
P_0c04229e: /* original 8917, guest PC 0x0c04229e */
if(!s->budget--) { s->failed_pc=0x0c04229eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0422d0; }
goto P_0c0422a0;
P_0c0422a0: /* original 7bff, guest PC 0x0c0422a0 */
if(!s->budget--) { s->failed_pc=0x0c0422a0u; return 0; }
r[11]+=0xffffffffu;
goto P_0c0422a2;
P_0c0422a2: /* original 2ce2, guest PC 0x0c0422a2 */
if(!s->budget--) { s->failed_pc=0x0c0422a2u; return 0; }
write(ram,r[12],r[14],4);
goto P_0c0422a4;
P_0c0422a4: /* original 4b15, guest PC 0x0c0422a4 */
if(!s->budget--) { s->failed_pc=0x0c0422a4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>0)!=0);
goto P_0c0422a6;
P_0c0422a6: /* original 8f31, guest PC 0x0c0422a6 */
if(!s->budget--) { s->failed_pc=0x0c0422a6u; return 0; }
cond=r[17]&1u;
r[12]=r[14];
if(!cond) { goto P_0c04230c; }
goto P_0c0422aa;
P_0c0422a8: /* original 6ce3, guest PC 0x0c0422a8 */
if(!s->budget--) { s->failed_pc=0x0c0422a8u; return 0; }
r[12]=r[14];
goto P_0c0422aa;
P_0c0422aa: /* original 64c3, guest PC 0x0c0422aa */
if(!s->budget--) { s->failed_pc=0x0c0422aau; return 0; }
r[4]=r[12];
goto P_0c0422ac;
P_0c0422ac: /* original 4408, guest PC 0x0c0422ac */
if(!s->budget--) { s->failed_pc=0x0c0422acu; return 0; }
r[4]<<=2;
goto P_0c0422ae;
P_0c0422ae: /* original 63c3, guest PC 0x0c0422ae */
if(!s->budget--) { s->failed_pc=0x0c0422aeu; return 0; }
r[3]=r[12];
goto P_0c0422b0;
P_0c0422b0: /* original 343c, guest PC 0x0c0422b0 */
if(!s->budget--) { s->failed_pc=0x0c0422b0u; return 0; }
r[4]+=r[3];
goto P_0c0422b2;
P_0c0422b2: /* original 4408, guest PC 0x0c0422b2 */
if(!s->budget--) { s->failed_pc=0x0c0422b2u; return 0; }
r[4]<<=2;
goto P_0c0422b4;
P_0c0422b4: /* original d224, guest PC 0x0c0422b4 */
if(!s->budget--) { s->failed_pc=0x0c0422b4u; return 0; }
r[2]=read(ram,0x0c042348u,4);
goto P_0c0422b6;
P_0c0422b6: /* original 4400, guest PC 0x0c0422b6 */
if(!s->budget--) { s->failed_pc=0x0c0422b6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0422b8;
P_0c0422b8: /* original 644e, guest PC 0x0c0422b8 */
if(!s->budget--) { s->failed_pc=0x0c0422b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0422ba;
P_0c0422ba: /* original 420b, guest PC 0x0c0422ba */
if(!s->budget--) { s->failed_pc=0x0c0422bau; return 0; }
target=r[2];
r[16]=code_base|0x0c0422beu;
r[4]+=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0422beu) { target=s->pc; goto dispatch; }
goto P_0c0422be;
P_0c0422bc: /* original 348c, guest PC 0x0c0422bc */
if(!s->budget--) { s->failed_pc=0x0c0422bcu; return 0; }
r[4]+=r[8];
goto P_0c0422be;
P_0c0422be: /* original 7c01, guest PC 0x0c0422be */
if(!s->budget--) { s->failed_pc=0x0c0422beu; return 0; }
r[12]+=0x00000001u;
goto P_0c0422c0;
P_0c0422c0: /* original 3cb3, guest PC 0x0c0422c0 */
if(!s->budget--) { s->failed_pc=0x0c0422c0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[11])!=0);
goto P_0c0422c2;
P_0c0422c2: /* original 8bf2, guest PC 0x0c0422c2 */
if(!s->budget--) { s->failed_pc=0x0c0422c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0422aa; }
goto P_0c0422c4;
P_0c0422c4: /* original a022, guest PC 0x0c0422c4 */
if(!s->budget--) { s->failed_pc=0x0c0422c4u; return 0; }
goto P_0c04230c;
P_0c0422c6: /* original 0009, guest PC 0x0c0422c6 */
if(!s->budget--) { s->failed_pc=0x0c0422c6u; return 0; }
if(!vf3_matrix_family(0x0c0422c8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0422c8u; return 0; } return 1;
P_0c0422d0: /* original 7b01, guest PC 0x0c0422d0 */
if(!s->budget--) { s->failed_pc=0x0c0422d0u; return 0; }
r[11]+=0x00000001u;
goto P_0c0422d2;
P_0c0422d2: /* original 3b93, guest PC 0x0c0422d2 */
if(!s->budget--) { s->failed_pc=0x0c0422d2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[9])!=0);
goto P_0c0422d4;
P_0c0422d4: /* original 8bd4, guest PC 0x0c0422d4 */
if(!s->budget--) { s->failed_pc=0x0c0422d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042280; }
goto P_0c0422d6;
P_0c0422d6: /* original d21d, guest PC 0x0c0422d6 */
if(!s->budget--) { s->failed_pc=0x0c0422d6u; return 0; }
r[2]=read(ram,0x0c04234cu,4);
goto P_0c0422d8;
P_0c0422d8: /* original 420b, guest PC 0x0c0422d8 */
if(!s->budget--) { s->failed_pc=0x0c0422d8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0422dcu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0422dcu) { target=s->pc; goto dispatch; }
goto P_0c0422dc;
P_0c0422da: /* original e400, guest PC 0x0c0422da */
if(!s->budget--) { s->failed_pc=0x0c0422dau; return 0; }
r[4]=0x00000000u;
goto P_0c0422dc;
P_0c0422dc: /* original d31c, guest PC 0x0c0422dc */
if(!s->budget--) { s->failed_pc=0x0c0422dcu; return 0; }
r[3]=read(ram,0x0c042350u,4);
goto P_0c0422de;
P_0c0422de: /* original 2302, guest PC 0x0c0422de */
if(!s->budget--) { s->failed_pc=0x0c0422deu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c0422e0;
P_0c0422e0: /* original d71c, guest PC 0x0c0422e0 */
if(!s->budget--) { s->failed_pc=0x0c0422e0u; return 0; }
r[7]=read(ram,0x0c042354u,4);
goto P_0c0422e2;
P_0c0422e2: /* original d51d, guest PC 0x0c0422e2 */
if(!s->budget--) { s->failed_pc=0x0c0422e2u; return 0; }
r[5]=read(ram,0x0c042358u,4);
goto P_0c0422e4;
P_0c0422e4: /* original 6673, guest PC 0x0c0422e4 */
if(!s->budget--) { s->failed_pc=0x0c0422e4u; return 0; }
r[6]=r[7];
goto P_0c0422e6;
P_0c0422e6: /* original 76f1, guest PC 0x0c0422e6 */
if(!s->budget--) { s->failed_pc=0x0c0422e6u; return 0; }
r[6]+=0xfffffff1u;
goto P_0c0422e8;
P_0c0422e8: /* original b062, guest PC 0x0c0422e8 */
if(!s->budget--) { s->failed_pc=0x0c0422e8u; return 0; }
target=code_base|0x0c0423b0u; r[16]=code_base|0x0c0422ecu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0422ecu) { target=s->pc; goto dispatch; }
goto P_0c0422ec;
P_0c0422ea: /* original e400, guest PC 0x0c0422ea */
if(!s->budget--) { s->failed_pc=0x0c0422eau; return 0; }
r[4]=0x00000000u;
goto P_0c0422ec;
P_0c0422ec: /* original e500, guest PC 0x0c0422ec */
if(!s->budget--) { s->failed_pc=0x0c0422ecu; return 0; }
r[5]=0x00000000u;
goto P_0c0422ee;
P_0c0422ee: /* original b0b7, guest PC 0x0c0422ee */
if(!s->budget--) { s->failed_pc=0x0c0422eeu; return 0; }
target=code_base|0x0c042460u; r[16]=code_base|0x0c0422f2u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0422f2u) { target=s->pc; goto dispatch; }
goto P_0c0422f2;
P_0c0422f0: /* original e403, guest PC 0x0c0422f0 */
if(!s->budget--) { s->failed_pc=0x0c0422f0u; return 0; }
r[4]=0x00000003u;
goto P_0c0422f2;
P_0c0422f2: /* original b0cd, guest PC 0x0c0422f2 */
if(!s->budget--) { s->failed_pc=0x0c0422f2u; return 0; }
target=code_base|0x0c042490u; r[16]=code_base|0x0c0422f6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0422f6u) { target=s->pc; goto dispatch; }
goto P_0c0422f6;
P_0c0422f4: /* original 0009, guest PC 0x0c0422f4 */
if(!s->budget--) { s->failed_pc=0x0c0422f4u; return 0; }
goto P_0c0422f6;
P_0c0422f6: /* original d319, guest PC 0x0c0422f6 */
if(!s->budget--) { s->failed_pc=0x0c0422f6u; return 0; }
r[3]=read(ram,0x0c04235cu,4);
goto P_0c0422f8;
P_0c0422f8: /* original eb00, guest PC 0x0c0422f8 */
if(!s->budget--) { s->failed_pc=0x0c0422f8u; return 0; }
r[11]=0x00000000u;
goto P_0c0422fa;
P_0c0422fa: /* original ea03, guest PC 0x0c0422fa */
if(!s->budget--) { s->failed_pc=0x0c0422fau; return 0; }
r[10]=0x00000003u;
goto P_0c0422fc;
P_0c0422fc: /* original 23e0, guest PC 0x0c0422fc */
if(!s->budget--) { s->failed_pc=0x0c0422fcu; return 0; }
write(ram,r[3],r[14],1);
goto P_0c0422fe;
P_0c0422fe: /* original b39f, guest PC 0x0c0422fe */
if(!s->budget--) { s->failed_pc=0x0c0422feu; return 0; }
target=code_base|0x0c042a40u; r[16]=code_base|0x0c042302u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c042302u) { target=s->pc; goto dispatch; }
goto P_0c042302;
P_0c042300: /* original 64a3, guest PC 0x0c042300 */
if(!s->budget--) { s->failed_pc=0x0c042300u; return 0; }
r[4]=r[10];
goto P_0c042302;
P_0c042302: /* original 6d03, guest PC 0x0c042302 */
if(!s->budget--) { s->failed_pc=0x0c042302u; return 0; }
r[13]=r[0];
goto P_0c042304;
P_0c042304: /* original 2dd8, guest PC 0x0c042304 */
if(!s->budget--) { s->failed_pc=0x0c042304u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c042306;
P_0c042306: /* original 8d03, guest PC 0x0c042306 */
if(!s->budget--) { s->failed_pc=0x0c042306u; return 0; }
cond=r[17]&1u;
r[10]=r[14];
if(cond) { goto P_0c042310; }
goto P_0c04230a;
P_0c042308: /* original 6ae3, guest PC 0x0c042308 */
if(!s->budget--) { s->failed_pc=0x0c042308u; return 0; }
r[10]=r[14];
goto P_0c04230a;
P_0c04230a: /* original 2ce2, guest PC 0x0c04230a */
if(!s->budget--) { s->failed_pc=0x0c04230au; return 0; }
write(ram,r[12],r[14],4);
goto P_0c04230c;
P_0c04230c: /* original a003, guest PC 0x0c04230c */
if(!s->budget--) { s->failed_pc=0x0c04230cu; return 0; }
r[0]=r[13];
goto P_0c042316;
P_0c04230e: /* original 60d3, guest PC 0x0c04230e */
if(!s->budget--) { s->failed_pc=0x0c04230eu; return 0; }
r[0]=r[13];
goto P_0c042310;
P_0c042310: /* original 7b01, guest PC 0x0c042310 */
if(!s->budget--) { s->failed_pc=0x0c042310u; return 0; }
r[11]+=0x00000001u;
goto P_0c042312;
P_0c042312: /* original 3b93, guest PC 0x0c042312 */
if(!s->budget--) { s->failed_pc=0x0c042312u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[9])!=0);
goto P_0c042314;
P_0c042314: /* original 8bf3, guest PC 0x0c042314 */
if(!s->budget--) { s->failed_pc=0x0c042314u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0422fe; }
goto P_0c042316;
P_0c042316: /* original 4f26, guest PC 0x0c042316 */
if(!s->budget--) { s->failed_pc=0x0c042316u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c042318;
P_0c042318: /* original 68f6, guest PC 0x0c042318 */
if(!s->budget--) { s->failed_pc=0x0c042318u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04231a;
P_0c04231a: /* original 69f6, guest PC 0x0c04231a */
if(!s->budget--) { s->failed_pc=0x0c04231au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04231c;
P_0c04231c: /* original 6af6, guest PC 0x0c04231c */
if(!s->budget--) { s->failed_pc=0x0c04231cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04231e;
P_0c04231e: /* original 6bf6, guest PC 0x0c04231e */
if(!s->budget--) { s->failed_pc=0x0c04231eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c042320;
P_0c042320: /* original 6cf6, guest PC 0x0c042320 */
if(!s->budget--) { s->failed_pc=0x0c042320u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c042322;
P_0c042322: /* original 6df6, guest PC 0x0c042322 */
if(!s->budget--) { s->failed_pc=0x0c042322u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c042324;
P_0c042324: /* original 000b, guest PC 0x0c042324 */
if(!s->budget--) { s->failed_pc=0x0c042324u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c042326: /* original 6ef6, guest PC 0x0c042326 */
if(!s->budget--) { s->failed_pc=0x0c042326u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c042328u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042328u; return 0; } return 1;
P_0c0423b0: /* original 2fe6, guest PC 0x0c0423b0 */
if(!s->budget--) { s->failed_pc=0x0c0423b0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0423b2;
P_0c0423b2: /* original 2fd6, guest PC 0x0c0423b2 */
if(!s->budget--) { s->failed_pc=0x0c0423b2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0423b4;
P_0c0423b4: /* original 2fc6, guest PC 0x0c0423b4 */
if(!s->budget--) { s->failed_pc=0x0c0423b4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0423b6;
P_0c0423b6: /* original 2fb6, guest PC 0x0c0423b6 */
if(!s->budget--) { s->failed_pc=0x0c0423b6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0423b8;
P_0c0423b8: /* original 2fa6, guest PC 0x0c0423b8 */
if(!s->budget--) { s->failed_pc=0x0c0423b8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0423ba;
P_0c0423ba: /* original 2f96, guest PC 0x0c0423ba */
if(!s->budget--) { s->failed_pc=0x0c0423bau; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0423bc;
P_0c0423bc: /* original 2f86, guest PC 0x0c0423bc */
if(!s->budget--) { s->failed_pc=0x0c0423bcu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0423be;
P_0c0423be: /* original d12c, guest PC 0x0c0423be */
if(!s->budget--) { s->failed_pc=0x0c0423beu; return 0; }
r[1]=read(ram,0x0c042470u,4);
goto P_0c0423c0;
P_0c0423c0: /* original 7ff4, guest PC 0x0c0423c0 */
if(!s->budget--) { s->failed_pc=0x0c0423c0u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0423c2;
P_0c0423c2: /* original 6e12, guest PC 0x0c0423c2 */
if(!s->budget--) { s->failed_pc=0x0c0423c2u; return 0; }
tmp=read(ram,r[1],4);
r[14]=tmp;
goto P_0c0423c4;
P_0c0423c4: /* original 2ee8, guest PC 0x0c0423c4 */
if(!s->budget--) { s->failed_pc=0x0c0423c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0423c6;
P_0c0423c6: /* original 893b, guest PC 0x0c0423c6 */
if(!s->budget--) { s->failed_pc=0x0c0423c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042440; }
goto P_0c0423c8;
P_0c0423c8: /* original 6df3, guest PC 0x0c0423c8 */
if(!s->budget--) { s->failed_pc=0x0c0423c8u; return 0; }
r[13]=r[15];
goto P_0c0423ca;
P_0c0423ca: /* original dc2c, guest PC 0x0c0423ca */
if(!s->budget--) { s->failed_pc=0x0c0423cau; return 0; }
r[12]=read(ram,0x0c04247cu,4);
goto P_0c0423cc;
P_0c0423cc: /* original 7d04, guest PC 0x0c0423cc */
if(!s->budget--) { s->failed_pc=0x0c0423ccu; return 0; }
r[13]+=0x00000004u;
goto P_0c0423ce;
P_0c0423ce: /* original 2d41, guest PC 0x0c0423ce */
if(!s->budget--) { s->failed_pc=0x0c0423ceu; return 0; }
write(ram,r[13],r[4],2);
goto P_0c0423d0;
P_0c0423d0: /* original 2c41, guest PC 0x0c0423d0 */
if(!s->budget--) { s->failed_pc=0x0c0423d0u; return 0; }
write(ram,r[12],r[4],2);
goto P_0c0423d2;
P_0c0423d2: /* original 6053, guest PC 0x0c0423d2 */
if(!s->budget--) { s->failed_pc=0x0c0423d2u; return 0; }
r[0]=r[5];
goto P_0c0423d4;
P_0c0423d4: /* original 0009, guest PC 0x0c0423d4 */
if(!s->budget--) { s->failed_pc=0x0c0423d4u; return 0; }
goto P_0c0423d6;
P_0c0423d6: /* original 81d1, guest PC 0x0c0423d6 */
if(!s->budget--) { s->failed_pc=0x0c0423d6u; return 0; }
write(ram,r[13]+2,r[0],2);
goto P_0c0423d8;
P_0c0423d8: /* original 81c1, guest PC 0x0c0423d8 */
if(!s->budget--) { s->failed_pc=0x0c0423d8u; return 0; }
write(ram,r[12]+2,r[0],2);
goto P_0c0423da;
P_0c0423da: /* original 6063, guest PC 0x0c0423da */
if(!s->budget--) { s->failed_pc=0x0c0423dau; return 0; }
r[0]=r[6];
goto P_0c0423dc;
P_0c0423dc: /* original 0009, guest PC 0x0c0423dc */
if(!s->budget--) { s->failed_pc=0x0c0423dcu; return 0; }
goto P_0c0423de;
P_0c0423de: /* original 81d2, guest PC 0x0c0423de */
if(!s->budget--) { s->failed_pc=0x0c0423deu; return 0; }
write(ram,r[13]+4,r[0],2);
goto P_0c0423e0;
P_0c0423e0: /* original 81c2, guest PC 0x0c0423e0 */
if(!s->budget--) { s->failed_pc=0x0c0423e0u; return 0; }
write(ram,r[12]+4,r[0],2);
goto P_0c0423e2;
P_0c0423e2: /* original 6073, guest PC 0x0c0423e2 */
if(!s->budget--) { s->failed_pc=0x0c0423e2u; return 0; }
r[0]=r[7];
goto P_0c0423e4;
P_0c0423e4: /* original 0009, guest PC 0x0c0423e4 */
if(!s->budget--) { s->failed_pc=0x0c0423e4u; return 0; }
goto P_0c0423e6;
P_0c0423e6: /* original e500, guest PC 0x0c0423e6 */
if(!s->budget--) { s->failed_pc=0x0c0423e6u; return 0; }
r[5]=0x00000000u;
goto P_0c0423e8;
P_0c0423e8: /* original 81d3, guest PC 0x0c0423e8 */
if(!s->budget--) { s->failed_pc=0x0c0423e8u; return 0; }
write(ram,r[13]+6,r[0],2);
goto P_0c0423ea;
P_0c0423ea: /* original e404, guest PC 0x0c0423ea */
if(!s->budget--) { s->failed_pc=0x0c0423eau; return 0; }
r[4]=0x00000004u;
goto P_0c0423ec;
P_0c0423ec: /* original 6853, guest PC 0x0c0423ec */
if(!s->budget--) { s->failed_pc=0x0c0423ecu; return 0; }
r[8]=r[5];
goto P_0c0423ee;
P_0c0423ee: /* original 81c3, guest PC 0x0c0423ee */
if(!s->budget--) { s->failed_pc=0x0c0423eeu; return 0; }
write(ram,r[12]+6,r[0],2);
goto P_0c0423f0;
P_0c0423f0: /* original 6383, guest PC 0x0c0423f0 */
if(!s->budget--) { s->failed_pc=0x0c0423f0u; return 0; }
r[3]=r[8];
goto P_0c0423f2;
P_0c0423f2: /* original 4300, guest PC 0x0c0423f2 */
if(!s->budget--) { s->failed_pc=0x0c0423f2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0423f4;
P_0c0423f4: /* original 33dc, guest PC 0x0c0423f4 */
if(!s->budget--) { s->failed_pc=0x0c0423f4u; return 0; }
r[3]+=r[13];
goto P_0c0423f6;
P_0c0423f6: /* original 6c53, guest PC 0x0c0423f6 */
if(!s->budget--) { s->failed_pc=0x0c0423f6u; return 0; }
r[12]=r[5];
goto P_0c0423f8;
P_0c0423f8: /* original 2f32, guest PC 0x0c0423f8 */
if(!s->budget--) { s->failed_pc=0x0c0423f8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0423fa;
P_0c0423fa: /* original 69c3, guest PC 0x0c0423fa */
if(!s->budget--) { s->failed_pc=0x0c0423fau; return 0; }
r[9]=r[12];
goto P_0c0423fc;
P_0c0423fc: /* original 4900, guest PC 0x0c0423fc */
if(!s->budget--) { s->failed_pc=0x0c0423fcu; return 0; }
r[17]=(r[17]&~1u)|((r[9]>>31)!=0);
r[9]<<=1;
goto P_0c0423fe;
P_0c0423fe: /* original 39dc, guest PC 0x0c0423fe */
if(!s->budget--) { s->failed_pc=0x0c0423feu; return 0; }
r[9]+=r[13];
goto P_0c042400;
P_0c042400: /* original 6653, guest PC 0x0c042400 */
if(!s->budget--) { s->failed_pc=0x0c042400u; return 0; }
r[6]=r[5];
goto P_0c042402;
P_0c042402: /* original 6b63, guest PC 0x0c042402 */
if(!s->budget--) { s->failed_pc=0x0c042402u; return 0; }
r[11]=r[6];
goto P_0c042404;
P_0c042404: /* original 4b00, guest PC 0x0c042404 */
if(!s->budget--) { s->failed_pc=0x0c042404u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c042406;
P_0c042406: /* original ea00, guest PC 0x0c042406 */
if(!s->budget--) { s->failed_pc=0x0c042406u; return 0; }
r[10]=0x00000000u;
goto P_0c042408;
P_0c042408: /* original 6753, guest PC 0x0c042408 */
if(!s->budget--) { s->failed_pc=0x0c042408u; return 0; }
r[7]=r[5];
goto P_0c04240a;
P_0c04240a: /* original 3bdc, guest PC 0x0c04240a */
if(!s->budget--) { s->failed_pc=0x0c04240au; return 0; }
r[11]+=r[13];
goto P_0c04240c;
P_0c04240c: /* original 3adc, guest PC 0x0c04240c */
if(!s->budget--) { s->failed_pc=0x0c04240cu; return 0; }
r[10]+=r[13];
goto P_0c04240e;
P_0c04240e: /* original 62a5, guest PC 0x0c04240e */
if(!s->budget--) { s->failed_pc=0x0c04240eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[10],2);
r[10]+=2;
r[2]=tmp;
goto P_0c042410;
P_0c042410: /* original 7701, guest PC 0x0c042410 */
if(!s->budget--) { s->failed_pc=0x0c042410u; return 0; }
r[7]+=0x00000001u;
goto P_0c042412;
P_0c042412: /* original 3743, guest PC 0x0c042412 */
if(!s->budget--) { s->failed_pc=0x0c042412u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[4])!=0);
goto P_0c042414;
P_0c042414: /* original 2e21, guest PC 0x0c042414 */
if(!s->budget--) { s->failed_pc=0x0c042414u; return 0; }
write(ram,r[14],r[2],2);
goto P_0c042416;
P_0c042416: /* original 7e02, guest PC 0x0c042416 */
if(!s->budget--) { s->failed_pc=0x0c042416u; return 0; }
r[14]+=0x00000002u;
goto P_0c042418;
P_0c042418: /* original 62b1, guest PC 0x0c042418 */
if(!s->budget--) { s->failed_pc=0x0c042418u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[11],2);
r[2]=tmp;
goto P_0c04241a;
P_0c04241a: /* original 2e21, guest PC 0x0c04241a */
if(!s->budget--) { s->failed_pc=0x0c04241au; return 0; }
write(ram,r[14],r[2],2);
goto P_0c04241c;
P_0c04241c: /* original 7e02, guest PC 0x0c04241c */
if(!s->budget--) { s->failed_pc=0x0c04241cu; return 0; }
r[14]+=0x00000002u;
goto P_0c04241e;
P_0c04241e: /* original 6291, guest PC 0x0c04241e */
if(!s->budget--) { s->failed_pc=0x0c04241eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[9],2);
r[2]=tmp;
goto P_0c042420;
P_0c042420: /* original 2e21, guest PC 0x0c042420 */
if(!s->budget--) { s->failed_pc=0x0c042420u; return 0; }
write(ram,r[14],r[2],2);
goto P_0c042422;
P_0c042422: /* original 7e02, guest PC 0x0c042422 */
if(!s->budget--) { s->failed_pc=0x0c042422u; return 0; }
r[14]+=0x00000002u;
goto P_0c042424;
P_0c042424: /* original 62f2, guest PC 0x0c042424 */
if(!s->budget--) { s->failed_pc=0x0c042424u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c042426;
P_0c042426: /* original 6121, guest PC 0x0c042426 */
if(!s->budget--) { s->failed_pc=0x0c042426u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[1]=tmp;
goto P_0c042428;
P_0c042428: /* original 2e11, guest PC 0x0c042428 */
if(!s->budget--) { s->failed_pc=0x0c042428u; return 0; }
write(ram,r[14],r[1],2);
goto P_0c04242a;
P_0c04242a: /* original 8ff0, guest PC 0x0c04242a */
if(!s->budget--) { s->failed_pc=0x0c04242au; return 0; }
cond=r[17]&1u;
r[14]+=0x00000002u;
if(!cond) { goto P_0c04240e; }
goto P_0c04242e;
P_0c04242c: /* original 7e02, guest PC 0x0c04242c */
if(!s->budget--) { s->failed_pc=0x0c04242cu; return 0; }
r[14]+=0x00000002u;
goto P_0c04242e;
P_0c04242e: /* original 7601, guest PC 0x0c04242e */
if(!s->budget--) { s->failed_pc=0x0c04242eu; return 0; }
r[6]+=0x00000001u;
goto P_0c042430;
P_0c042430: /* original 3643, guest PC 0x0c042430 */
if(!s->budget--) { s->failed_pc=0x0c042430u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[4])!=0);
goto P_0c042432;
P_0c042432: /* original 8be6, guest PC 0x0c042432 */
if(!s->budget--) { s->failed_pc=0x0c042432u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042402; }
goto P_0c042434;
P_0c042434: /* original 7c01, guest PC 0x0c042434 */
if(!s->budget--) { s->failed_pc=0x0c042434u; return 0; }
r[12]+=0x00000001u;
goto P_0c042436;
P_0c042436: /* original 3c43, guest PC 0x0c042436 */
if(!s->budget--) { s->failed_pc=0x0c042436u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[4])!=0);
goto P_0c042438;
P_0c042438: /* original 8bdf, guest PC 0x0c042438 */
if(!s->budget--) { s->failed_pc=0x0c042438u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0423fa; }
goto P_0c04243a;
P_0c04243a: /* original 7801, guest PC 0x0c04243a */
if(!s->budget--) { s->failed_pc=0x0c04243au; return 0; }
r[8]+=0x00000001u;
goto P_0c04243c;
P_0c04243c: /* original 3843, guest PC 0x0c04243c */
if(!s->budget--) { s->failed_pc=0x0c04243cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[4])!=0);
goto P_0c04243e;
P_0c04243e: /* original 8bd7, guest PC 0x0c04243e */
if(!s->budget--) { s->failed_pc=0x0c04243eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0423f0; }
goto P_0c042440;
P_0c042440: /* original 7f0c, guest PC 0x0c042440 */
if(!s->budget--) { s->failed_pc=0x0c042440u; return 0; }
r[15]+=0x0000000cu;
goto P_0c042442;
P_0c042442: /* original 68f6, guest PC 0x0c042442 */
if(!s->budget--) { s->failed_pc=0x0c042442u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c042444;
P_0c042444: /* original 69f6, guest PC 0x0c042444 */
if(!s->budget--) { s->failed_pc=0x0c042444u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c042446;
P_0c042446: /* original 6af6, guest PC 0x0c042446 */
if(!s->budget--) { s->failed_pc=0x0c042446u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c042448;
P_0c042448: /* original 6bf6, guest PC 0x0c042448 */
if(!s->budget--) { s->failed_pc=0x0c042448u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04244a;
P_0c04244a: /* original 6cf6, guest PC 0x0c04244a */
if(!s->budget--) { s->failed_pc=0x0c04244au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04244c;
P_0c04244c: /* original 6df6, guest PC 0x0c04244c */
if(!s->budget--) { s->failed_pc=0x0c04244cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04244e;
P_0c04244e: /* original 000b, guest PC 0x0c04244e */
if(!s->budget--) { s->failed_pc=0x0c04244eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c042450: /* original 6ef6, guest PC 0x0c042450 */
if(!s->budget--) { s->failed_pc=0x0c042450u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c042452u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042452u; return 0; } return 1;
P_0c042460: /* original d207, guest PC 0x0c042460 */
if(!s->budget--) { s->failed_pc=0x0c042460u; return 0; }
r[2]=read(ram,0x0c042480u,4);
goto P_0c042462;
P_0c042462: /* original e303, guest PC 0x0c042462 */
if(!s->budget--) { s->failed_pc=0x0c042462u; return 0; }
r[3]=0x00000003u;
goto P_0c042464;
P_0c042464: /* original 2439, guest PC 0x0c042464 */
if(!s->budget--) { s->failed_pc=0x0c042464u; return 0; }
r[4]&=r[3];
goto P_0c042466;
P_0c042466: /* original 2539, guest PC 0x0c042466 */
if(!s->budget--) { s->failed_pc=0x0c042466u; return 0; }
r[5]&=r[3];
goto P_0c042468;
P_0c042468: /* original 2240, guest PC 0x0c042468 */
if(!s->budget--) { s->failed_pc=0x0c042468u; return 0; }
write(ram,r[2],r[4],1);
goto P_0c04246a;
P_0c04246a: /* original d106, guest PC 0x0c04246a */
if(!s->budget--) { s->failed_pc=0x0c04246au; return 0; }
r[1]=read(ram,0x0c042484u,4);
goto P_0c04246c;
P_0c04246c: /* original 000b, guest PC 0x0c04246c */
if(!s->budget--) { s->failed_pc=0x0c04246cu; return 0; }
target=r[16];
write(ram,r[1],r[5],1);
s->pc=target; return ram->oob==0;
P_0c04246e: /* original 2150, guest PC 0x0c04246e */
if(!s->budget--) { s->failed_pc=0x0c04246eu; return 0; }
write(ram,r[1],r[5],1);
if(!vf3_matrix_family(0x0c042470u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042470u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
