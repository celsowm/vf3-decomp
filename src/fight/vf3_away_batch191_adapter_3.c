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
int vf3_away_batch191_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0692a6u: goto P_0c0692a6;
case 0x0c0692a8u: goto P_0c0692a8;
case 0x0c0692aau: goto P_0c0692aa;
case 0x0c0692acu: goto P_0c0692ac;
case 0x0c0692aeu: goto P_0c0692ae;
case 0x0c0692b0u: goto P_0c0692b0;
case 0x0c0692b2u: goto P_0c0692b2;
case 0x0c0692b4u: goto P_0c0692b4;
case 0x0c0692b6u: goto P_0c0692b6;
case 0x0c0692b8u: goto P_0c0692b8;
case 0x0c0692bau: goto P_0c0692ba;
case 0x0c0692bcu: goto P_0c0692bc;
case 0x0c0692beu: goto P_0c0692be;
case 0x0c0692c0u: goto P_0c0692c0;
case 0x0c0692c2u: goto P_0c0692c2;
case 0x0c0692c4u: goto P_0c0692c4;
case 0x0c0692c6u: goto P_0c0692c6;
case 0x0c0692c8u: goto P_0c0692c8;
case 0x0c0692cau: goto P_0c0692ca;
case 0x0c0692ccu: goto P_0c0692cc;
case 0x0c0692ceu: goto P_0c0692ce;
case 0x0c0692d0u: goto P_0c0692d0;
case 0x0c0692d2u: goto P_0c0692d2;
case 0x0c0692d4u: goto P_0c0692d4;
case 0x0c0692d6u: goto P_0c0692d6;
case 0x0c0692d8u: goto P_0c0692d8;
case 0x0c0692dau: goto P_0c0692da;
case 0x0c0692dcu: goto P_0c0692dc;
case 0x0c0692deu: goto P_0c0692de;
case 0x0c0692e0u: goto P_0c0692e0;
case 0x0c0692e2u: goto P_0c0692e2;
case 0x0c0692e4u: goto P_0c0692e4;
case 0x0c0692e6u: goto P_0c0692e6;
case 0x0c0692e8u: goto P_0c0692e8;
case 0x0c0692eau: goto P_0c0692ea;
case 0x0c0692ecu: goto P_0c0692ec;
case 0x0c0692eeu: goto P_0c0692ee;
case 0x0c0692f0u: goto P_0c0692f0;
case 0x0c0692f2u: goto P_0c0692f2;
case 0x0c0692f4u: goto P_0c0692f4;
case 0x0c0692f6u: goto P_0c0692f6;
case 0x0c0692f8u: goto P_0c0692f8;
case 0x0c0692fau: goto P_0c0692fa;
case 0x0c0692fcu: goto P_0c0692fc;
case 0x0c0692feu: goto P_0c0692fe;
case 0x0c069300u: goto P_0c069300;
case 0x0c069302u: goto P_0c069302;
case 0x0c069304u: goto P_0c069304;
case 0x0c069306u: goto P_0c069306;
case 0x0c069308u: goto P_0c069308;
case 0x0c06930au: goto P_0c06930a;
case 0x0c06930cu: goto P_0c06930c;
case 0x0c06930eu: goto P_0c06930e;
case 0x0c069310u: goto P_0c069310;
case 0x0c069312u: goto P_0c069312;
case 0x0c069314u: goto P_0c069314;
case 0x0c069316u: goto P_0c069316;
case 0x0c069318u: goto P_0c069318;
case 0x0c06931au: goto P_0c06931a;
case 0x0c06931cu: goto P_0c06931c;
case 0x0c06931eu: goto P_0c06931e;
case 0x0c069320u: goto P_0c069320;
case 0x0c069322u: goto P_0c069322;
case 0x0c069324u: goto P_0c069324;
case 0x0c069326u: goto P_0c069326;
case 0x0c069328u: goto P_0c069328;
case 0x0c06932au: goto P_0c06932a;
case 0x0c06932cu: goto P_0c06932c;
case 0x0c06932eu: goto P_0c06932e;
case 0x0c069330u: goto P_0c069330;
case 0x0c069332u: goto P_0c069332;
case 0x0c069334u: goto P_0c069334;
case 0x0c069336u: goto P_0c069336;
case 0x0c069338u: goto P_0c069338;
case 0x0c06933au: goto P_0c06933a;
case 0x0c06933cu: goto P_0c06933c;
case 0x0c06933eu: goto P_0c06933e;
case 0x0c069340u: goto P_0c069340;
case 0x0c069342u: goto P_0c069342;
case 0x0c069344u: goto P_0c069344;
case 0x0c069346u: goto P_0c069346;
case 0x0c069348u: goto P_0c069348;
case 0x0c06934au: goto P_0c06934a;
case 0x0c06934cu: goto P_0c06934c;
case 0x0c06934eu: goto P_0c06934e;
case 0x0c069350u: goto P_0c069350;
case 0x0c069352u: goto P_0c069352;
case 0x0c069354u: goto P_0c069354;
case 0x0c069356u: goto P_0c069356;
case 0x0c069358u: goto P_0c069358;
case 0x0c06935au: goto P_0c06935a;
case 0x0c06935cu: goto P_0c06935c;
case 0x0c06935eu: goto P_0c06935e;
case 0x0c069360u: goto P_0c069360;
case 0x0c069362u: goto P_0c069362;
case 0x0c069364u: goto P_0c069364;
case 0x0c069366u: goto P_0c069366;
case 0x0c069368u: goto P_0c069368;
case 0x0c06936au: goto P_0c06936a;
case 0x0c06936cu: goto P_0c06936c;
case 0x0c06936eu: goto P_0c06936e;
case 0x0c069370u: goto P_0c069370;
case 0x0c069372u: goto P_0c069372;
case 0x0c069374u: goto P_0c069374;
case 0x0c069376u: goto P_0c069376;
case 0x0c069378u: goto P_0c069378;
case 0x0c06937au: goto P_0c06937a;
case 0x0c06937cu: goto P_0c06937c;
case 0x0c06938cu: goto P_0c06938c;
case 0x0c06938eu: goto P_0c06938e;
case 0x0c069390u: goto P_0c069390;
case 0x0c069392u: goto P_0c069392;
case 0x0c069394u: goto P_0c069394;
case 0x0c069396u: goto P_0c069396;
case 0x0c069398u: goto P_0c069398;
case 0x0c06939au: goto P_0c06939a;
case 0x0c06939cu: goto P_0c06939c;
case 0x0c06939eu: goto P_0c06939e;
case 0x0c0693a0u: goto P_0c0693a0;
case 0x0c0693a2u: goto P_0c0693a2;
case 0x0c0693a4u: goto P_0c0693a4;
case 0x0c0693a6u: goto P_0c0693a6;
case 0x0c0693a8u: goto P_0c0693a8;
case 0x0c0693aau: goto P_0c0693aa;
case 0x0c0693acu: goto P_0c0693ac;
case 0x0c0693aeu: goto P_0c0693ae;
case 0x0c0693b0u: goto P_0c0693b0;
case 0x0c0693b2u: goto P_0c0693b2;
case 0x0c0693b4u: goto P_0c0693b4;
case 0x0c0693b6u: goto P_0c0693b6;
case 0x0c0693b8u: goto P_0c0693b8;
case 0x0c0693bau: goto P_0c0693ba;
case 0x0c0693bcu: goto P_0c0693bc;
case 0x0c0693beu: goto P_0c0693be;
case 0x0c0693c0u: goto P_0c0693c0;
case 0x0c0693c2u: goto P_0c0693c2;
case 0x0c0693c4u: goto P_0c0693c4;
case 0x0c0693c6u: goto P_0c0693c6;
case 0x0c0693c8u: goto P_0c0693c8;
case 0x0c0693cau: goto P_0c0693ca;
case 0x0c0693ccu: goto P_0c0693cc;
case 0x0c0693ceu: goto P_0c0693ce;
case 0x0c0693d0u: goto P_0c0693d0;
case 0x0c0693d2u: goto P_0c0693d2;
case 0x0c0693d4u: goto P_0c0693d4;
case 0x0c0693d6u: goto P_0c0693d6;
case 0x0c0693d8u: goto P_0c0693d8;
case 0x0c0693dau: goto P_0c0693da;
case 0x0c0693dcu: goto P_0c0693dc;
case 0x0c0693deu: goto P_0c0693de;
case 0x0c0693e0u: goto P_0c0693e0;
case 0x0c0693e2u: goto P_0c0693e2;
case 0x0c0693e4u: goto P_0c0693e4;
case 0x0c0693e6u: goto P_0c0693e6;
case 0x0c0693e8u: goto P_0c0693e8;
case 0x0c0693eau: goto P_0c0693ea;
case 0x0c0693ecu: goto P_0c0693ec;
case 0x0c0693eeu: goto P_0c0693ee;
case 0x0c0693f0u: goto P_0c0693f0;
case 0x0c0693f2u: goto P_0c0693f2;
case 0x0c0693f4u: goto P_0c0693f4;
case 0x0c0693f6u: goto P_0c0693f6;
case 0x0c0693f8u: goto P_0c0693f8;
case 0x0c0693fau: goto P_0c0693fa;
case 0x0c0693fcu: goto P_0c0693fc;
case 0x0c0693feu: goto P_0c0693fe;
case 0x0c069400u: goto P_0c069400;
case 0x0c069402u: goto P_0c069402;
case 0x0c069404u: goto P_0c069404;
case 0x0c069406u: goto P_0c069406;
case 0x0c069408u: goto P_0c069408;
case 0x0c06940au: goto P_0c06940a;
case 0x0c06940cu: goto P_0c06940c;
case 0x0c06940eu: goto P_0c06940e;
case 0x0c069410u: goto P_0c069410;
case 0x0c069412u: goto P_0c069412;
case 0x0c069414u: goto P_0c069414;
case 0x0c069416u: goto P_0c069416;
case 0x0c069418u: goto P_0c069418;
case 0x0c06941au: goto P_0c06941a;
case 0x0c06941cu: goto P_0c06941c;
case 0x0c06941eu: goto P_0c06941e;
case 0x0c069420u: goto P_0c069420;
case 0x0c069422u: goto P_0c069422;
case 0x0c069424u: goto P_0c069424;
case 0x0c069426u: goto P_0c069426;
case 0x0c069428u: goto P_0c069428;
case 0x0c06942au: goto P_0c06942a;
case 0x0c06942cu: goto P_0c06942c;
case 0x0c06942eu: goto P_0c06942e;
case 0x0c069430u: goto P_0c069430;
case 0x0c069432u: goto P_0c069432;
case 0x0c069434u: goto P_0c069434;
case 0x0c069436u: goto P_0c069436;
case 0x0c069438u: goto P_0c069438;
case 0x0c06943au: goto P_0c06943a;
case 0x0c06943cu: goto P_0c06943c;
case 0x0c06943eu: goto P_0c06943e;
case 0x0c069440u: goto P_0c069440;
case 0x0c069442u: goto P_0c069442;
case 0x0c069444u: goto P_0c069444;
case 0x0c069446u: goto P_0c069446;
case 0x0c069448u: goto P_0c069448;
case 0x0c06944au: goto P_0c06944a;
case 0x0c06944cu: goto P_0c06944c;
case 0x0c06944eu: goto P_0c06944e;
case 0x0c069450u: goto P_0c069450;
case 0x0c069452u: goto P_0c069452;
case 0x0c069454u: goto P_0c069454;
case 0x0c069456u: goto P_0c069456;
case 0x0c069458u: goto P_0c069458;
case 0x0c06945au: goto P_0c06945a;
case 0x0c06945cu: goto P_0c06945c;
case 0x0c06945eu: goto P_0c06945e;
case 0x0c069460u: goto P_0c069460;
case 0x0c069462u: goto P_0c069462;
case 0x0c069464u: goto P_0c069464;
case 0x0c069466u: goto P_0c069466;
case 0x0c069468u: goto P_0c069468;
case 0x0c06946au: goto P_0c06946a;
case 0x0c06946cu: goto P_0c06946c;
case 0x0c06946eu: goto P_0c06946e;
case 0x0c069470u: goto P_0c069470;
case 0x0c069472u: goto P_0c069472;
case 0x0c069474u: goto P_0c069474;
case 0x0c069476u: goto P_0c069476;
case 0x0c069478u: goto P_0c069478;
case 0x0c06947au: goto P_0c06947a;
case 0x0c06947cu: goto P_0c06947c;
case 0x0c06947eu: goto P_0c06947e;
case 0x0c069480u: goto P_0c069480;
case 0x0c069482u: goto P_0c069482;
case 0x0c069484u: goto P_0c069484;
case 0x0c069486u: goto P_0c069486;
case 0x0c069488u: goto P_0c069488;
case 0x0c06948au: goto P_0c06948a;
case 0x0c06948cu: goto P_0c06948c;
case 0x0c06948eu: goto P_0c06948e;
case 0x0c069490u: goto P_0c069490;
case 0x0c069492u: goto P_0c069492;
case 0x0c069494u: goto P_0c069494;
case 0x0c0694b0u: goto P_0c0694b0;
case 0x0c0694b2u: goto P_0c0694b2;
case 0x0c0694b4u: goto P_0c0694b4;
case 0x0c0694b6u: goto P_0c0694b6;
case 0x0c0694b8u: goto P_0c0694b8;
case 0x0c0694bau: goto P_0c0694ba;
case 0x0c0694bcu: goto P_0c0694bc;
case 0x0c0694beu: goto P_0c0694be;
case 0x0c0694c0u: goto P_0c0694c0;
case 0x0c0694c2u: goto P_0c0694c2;
case 0x0c0694c4u: goto P_0c0694c4;
case 0x0c0694c6u: goto P_0c0694c6;
case 0x0c0694c8u: goto P_0c0694c8;
case 0x0c0694cau: goto P_0c0694ca;
case 0x0c0694ccu: goto P_0c0694cc;
case 0x0c0694ceu: goto P_0c0694ce;
case 0x0c0694d0u: goto P_0c0694d0;
case 0x0c0694d2u: goto P_0c0694d2;
case 0x0c0694d4u: goto P_0c0694d4;
case 0x0c0694d6u: goto P_0c0694d6;
case 0x0c0694d8u: goto P_0c0694d8;
case 0x0c0694dau: goto P_0c0694da;
case 0x0c0694dcu: goto P_0c0694dc;
case 0x0c0694deu: goto P_0c0694de;
case 0x0c0694e0u: goto P_0c0694e0;
case 0x0c0694e2u: goto P_0c0694e2;
case 0x0c0694e4u: goto P_0c0694e4;
case 0x0c0694e6u: goto P_0c0694e6;
case 0x0c0694e8u: goto P_0c0694e8;
case 0x0c0694eau: goto P_0c0694ea;
case 0x0c0694ecu: goto P_0c0694ec;
case 0x0c0694eeu: goto P_0c0694ee;
case 0x0c0694f0u: goto P_0c0694f0;
case 0x0c0694f2u: goto P_0c0694f2;
case 0x0c0694f4u: goto P_0c0694f4;
case 0x0c0694f6u: goto P_0c0694f6;
case 0x0c0694f8u: goto P_0c0694f8;
case 0x0c0694fau: goto P_0c0694fa;
case 0x0c0694fcu: goto P_0c0694fc;
case 0x0c0694feu: goto P_0c0694fe;
case 0x0c069500u: goto P_0c069500;
case 0x0c069502u: goto P_0c069502;
case 0x0c069504u: goto P_0c069504;
case 0x0c069506u: goto P_0c069506;
case 0x0c069508u: goto P_0c069508;
case 0x0c06950au: goto P_0c06950a;
case 0x0c06950cu: goto P_0c06950c;
case 0x0c06950eu: goto P_0c06950e;
case 0x0c069510u: goto P_0c069510;
case 0x0c069512u: goto P_0c069512;
case 0x0c069514u: goto P_0c069514;
case 0x0c069516u: goto P_0c069516;
case 0x0c069518u: goto P_0c069518;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0692a6: /* original 2fe6, guest PC 0x0c0692a6 */
if(!s->budget--) { s->failed_pc=0x0c0692a6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0692a8;
P_0c0692a8: /* original e004, guest PC 0x0c0692a8 */
if(!s->budget--) { s->failed_pc=0x0c0692a8u; return 0; }
r[0]=0x00000004u;
goto P_0c0692aa;
P_0c0692aa: /* original ffeb, guest PC 0x0c0692aa */
if(!s->budget--) { s->failed_pc=0x0c0692aau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0692ac;
P_0c0692ac: /* original d335, guest PC 0x0c0692ac */
if(!s->budget--) { s->failed_pc=0x0c0692acu; return 0; }
r[3]=read(ram,0x0c069384u,4);
goto P_0c0692ae;
P_0c0692ae: /* original 7ff4, guest PC 0x0c0692ae */
if(!s->budget--) { s->failed_pc=0x0c0692aeu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0692b0;
P_0c0692b0: /* original 5441, guest PC 0x0c0692b0 */
if(!s->budget--) { s->failed_pc=0x0c0692b0u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0692b2;
P_0c0692b2: /* original 6e32, guest PC 0x0c0692b2 */
if(!s->budget--) { s->failed_pc=0x0c0692b2u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c0692b4;
P_0c0692b4: /* original ff4a, guest PC 0x0c0692b4 */
if(!s->budget--) { s->failed_pc=0x0c0692b4u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c0692b6;
P_0c0692b6: /* original 34ec, guest PC 0x0c0692b6 */
if(!s->budget--) { s->failed_pc=0x0c0692b6u; return 0; }
r[4]+=r[14];
goto P_0c0692b8;
P_0c0692b8: /* original ff57, guest PC 0x0c0692b8 */
if(!s->budget--) { s->failed_pc=0x0c0692b8u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0692ba;
P_0c0692ba: /* original 5241, guest PC 0x0c0692ba */
if(!s->budget--) { s->failed_pc=0x0c0692bau; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c0692bc;
P_0c0692bc: /* original 6073, guest PC 0x0c0692bc */
if(!s->budget--) { s->failed_pc=0x0c0692bcu; return 0; }
r[0]=r[7];
goto P_0c0692be;
P_0c0692be: /* original 8804, guest PC 0x0c0692be */
if(!s->budget--) { s->failed_pc=0x0c0692beu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0692c0;
P_0c0692c0: /* original 1f22, guest PC 0x0c0692c0 */
if(!s->budget--) { s->failed_pc=0x0c0692c0u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0692c2;
P_0c0692c2: /* original 8902, guest PC 0x0c0692c2 */
if(!s->budget--) { s->failed_pc=0x0c0692c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0692ca; }
goto P_0c0692c4;
P_0c0692c4: /* original 5342, guest PC 0x0c0692c4 */
if(!s->budget--) { s->failed_pc=0x0c0692c4u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c0692c6;
P_0c0692c6: /* original a002, guest PC 0x0c0692c6 */
if(!s->budget--) { s->failed_pc=0x0c0692c6u; return 0; }
r[2]=read(ram,r[4]+12,4);
goto P_0c0692ce;
P_0c0692c8: /* original 5243, guest PC 0x0c0692c8 */
if(!s->budget--) { s->failed_pc=0x0c0692c8u; return 0; }
r[2]=read(ram,r[4]+12,4);
goto P_0c0692ca;
P_0c0692ca: /* original 5244, guest PC 0x0c0692ca */
if(!s->budget--) { s->failed_pc=0x0c0692cau; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c0692cc;
P_0c0692cc: /* original 5343, guest PC 0x0c0692cc */
if(!s->budget--) { s->failed_pc=0x0c0692ccu; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c0692ce;
P_0c0692ce: /* original 57f2, guest PC 0x0c0692ce */
if(!s->budget--) { s->failed_pc=0x0c0692ceu; return 0; }
r[7]=read(ram,r[15]+8,4);
goto P_0c0692d0;
P_0c0692d0: /* original e004, guest PC 0x0c0692d0 */
if(!s->budget--) { s->failed_pc=0x0c0692d0u; return 0; }
r[0]=0x00000004u;
goto P_0c0692d2;
P_0c0692d2: /* original 33ec, guest PC 0x0c0692d2 */
if(!s->budget--) { s->failed_pc=0x0c0692d2u; return 0; }
r[3]+=r[14];
goto P_0c0692d4;
P_0c0692d4: /* original 37ec, guest PC 0x0c0692d4 */
if(!s->budget--) { s->failed_pc=0x0c0692d4u; return 0; }
r[7]+=r[14];
goto P_0c0692d6;
P_0c0692d6: /* original f038, guest PC 0x0c0692d6 */
if(!s->budget--) { s->failed_pc=0x0c0692d6u; return 0; }
vf3_matrix_load(s,ram,0,r[3]);
goto P_0c0692d8;
P_0c0692d8: /* original f276, guest PC 0x0c0692d8 */
if(!s->budget--) { s->failed_pc=0x0c0692d8u; return 0; }
vf3_matrix_load(s,ram,2,r[7]+r[0]);
goto P_0c0692da;
P_0c0692da: /* original e008, guest PC 0x0c0692da */
if(!s->budget--) { s->failed_pc=0x0c0692dau; return 0; }
r[0]=0x00000008u;
goto P_0c0692dc;
P_0c0692dc: /* original f176, guest PC 0x0c0692dc */
if(!s->budget--) { s->failed_pc=0x0c0692dcu; return 0; }
vf3_matrix_load(s,ram,1,r[7]+r[0]);
goto P_0c0692de;
P_0c0692de: /* original e004, guest PC 0x0c0692de */
if(!s->budget--) { s->failed_pc=0x0c0692deu; return 0; }
r[0]=0x00000004u;
goto P_0c0692e0;
P_0c0692e0: /* original f436, guest PC 0x0c0692e0 */
if(!s->budget--) { s->failed_pc=0x0c0692e0u; return 0; }
vf3_matrix_load(s,ram,4,r[3]+r[0]);
goto P_0c0692e2;
P_0c0692e2: /* original e008, guest PC 0x0c0692e2 */
if(!s->budget--) { s->failed_pc=0x0c0692e2u; return 0; }
r[0]=0x00000008u;
goto P_0c0692e4;
P_0c0692e4: /* original 32ec, guest PC 0x0c0692e4 */
if(!s->budget--) { s->failed_pc=0x0c0692e4u; return 0; }
r[2]+=r[14];
goto P_0c0692e6;
P_0c0692e6: /* original fb36, guest PC 0x0c0692e6 */
if(!s->budget--) { s->failed_pc=0x0c0692e6u; return 0; }
vf3_matrix_load(s,ram,11,r[3]+r[0]);
goto P_0c0692e8;
P_0c0692e8: /* original e004, guest PC 0x0c0692e8 */
if(!s->budget--) { s->failed_pc=0x0c0692e8u; return 0; }
r[0]=0x00000004u;
goto P_0c0692ea;
P_0c0692ea: /* original 6e23, guest PC 0x0c0692ea */
if(!s->budget--) { s->failed_pc=0x0c0692eau; return 0; }
r[14]=r[2];
goto P_0c0692ec;
P_0c0692ec: /* original f9e6, guest PC 0x0c0692ec */
if(!s->budget--) { s->failed_pc=0x0c0692ecu; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c0692ee;
P_0c0692ee: /* original e008, guest PC 0x0c0692ee */
if(!s->budget--) { s->failed_pc=0x0c0692eeu; return 0; }
r[0]=0x00000008u;
goto P_0c0692f0;
P_0c0692f0: /* original fe78, guest PC 0x0c0692f0 */
if(!s->budget--) { s->failed_pc=0x0c0692f0u; return 0; }
vf3_matrix_load(s,ram,14,r[7]);
goto P_0c0692f2;
P_0c0692f2: /* original fb11, guest PC 0x0c0692f2 */
if(!s->budget--) { s->failed_pc=0x0c0692f2u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[1],r[18],'-');
goto P_0c0692f4;
P_0c0692f4: /* original f8e6, guest PC 0x0c0692f4 */
if(!s->budget--) { s->failed_pc=0x0c0692f4u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0692f6;
P_0c0692f6: /* original f421, guest PC 0x0c0692f6 */
if(!s->budget--) { s->failed_pc=0x0c0692f6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'-');
goto P_0c0692f8;
P_0c0692f8: /* original fae8, guest PC 0x0c0692f8 */
if(!s->budget--) { s->failed_pc=0x0c0692f8u; return 0; }
vf3_matrix_load(s,ram,10,r[14]);
goto P_0c0692fa;
P_0c0692fa: /* original f0e1, guest PC 0x0c0692fa */
if(!s->budget--) { s->failed_pc=0x0c0692fau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[14],r[18],'-');
goto P_0c0692fc;
P_0c0692fc: /* original f811, guest PC 0x0c0692fc */
if(!s->budget--) { s->failed_pc=0x0c0692fcu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[1],r[18],'-');
goto P_0c0692fe;
P_0c0692fe: /* original f921, guest PC 0x0c0692fe */
if(!s->budget--) { s->failed_pc=0x0c0692feu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[2],r[18],'-');
goto P_0c069300;
P_0c069300: /* original f5bc, guest PC 0x0c069300 */
if(!s->budget--) { s->failed_pc=0x0c069300u; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c069302;
P_0c069302: /* original fae1, guest PC 0x0c069302 */
if(!s->budget--) { s->failed_pc=0x0c069302u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[14],r[18],'-');
goto P_0c069304;
P_0c069304: /* original f74c, guest PC 0x0c069304 */
if(!s->budget--) { s->failed_pc=0x0c069304u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c069306;
P_0c069306: /* original f60c, guest PC 0x0c069306 */
if(!s->budget--) { s->failed_pc=0x0c069306u; return 0; }
vf3_matrix_move(s,6,0);
goto P_0c069308;
P_0c069308: /* original f782, guest PC 0x0c069308 */
if(!s->budget--) { s->failed_pc=0x0c069308u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[8],r[18],'*');
goto P_0c06930a;
P_0c06930a: /* original f692, guest PC 0x0c06930a */
if(!s->budget--) { s->failed_pc=0x0c06930au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[9],r[18],'*');
goto P_0c06930c;
P_0c06930c: /* original f5a2, guest PC 0x0c06930c */
if(!s->budget--) { s->failed_pc=0x0c06930cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[10],r[18],'*');
goto P_0c06930e;
P_0c06930e: /* original fb92, guest PC 0x0c06930e */
if(!s->budget--) { s->failed_pc=0x0c06930eu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[9],r[18],'*');
goto P_0c069310;
P_0c069310: /* original f37c, guest PC 0x0c069310 */
if(!s->budget--) { s->failed_pc=0x0c069310u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c069312;
P_0c069312: /* original f082, guest PC 0x0c069312 */
if(!s->budget--) { s->failed_pc=0x0c069312u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[8],r[18],'*');
goto P_0c069314;
P_0c069314: /* original e004, guest PC 0x0c069314 */
if(!s->budget--) { s->failed_pc=0x0c069314u; return 0; }
r[0]=0x00000004u;
goto P_0c069316;
P_0c069316: /* original f4a2, guest PC 0x0c069316 */
if(!s->budget--) { s->failed_pc=0x0c069316u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[10],r[18],'*');
goto P_0c069318;
P_0c069318: /* original f7bc, guest PC 0x0c069318 */
if(!s->budget--) { s->failed_pc=0x0c069318u; return 0; }
vf3_matrix_move(s,7,11);
goto P_0c06931a;
P_0c06931a: /* original f731, guest PC 0x0c06931a */
if(!s->budget--) { s->failed_pc=0x0c06931au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c06931c;
P_0c06931c: /* original f35c, guest PC 0x0c06931c */
if(!s->budget--) { s->failed_pc=0x0c06931cu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c06931e;
P_0c06931e: /* original f50c, guest PC 0x0c06931e */
if(!s->budget--) { s->failed_pc=0x0c06931eu; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c069320;
P_0c069320: /* original f531, guest PC 0x0c069320 */
if(!s->budget--) { s->failed_pc=0x0c069320u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c069322;
P_0c069322: /* original f36c, guest PC 0x0c069322 */
if(!s->budget--) { s->failed_pc=0x0c069322u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c069324;
P_0c069324: /* original f07c, guest PC 0x0c069324 */
if(!s->budget--) { s->failed_pc=0x0c069324u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c069326;
P_0c069326: /* original f64c, guest PC 0x0c069326 */
if(!s->budget--) { s->failed_pc=0x0c069326u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c069328;
P_0c069328: /* original f631, guest PC 0x0c069328 */
if(!s->budget--) { s->failed_pc=0x0c069328u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c06932a;
P_0c06932a: /* original f252, guest PC 0x0c06932a */
if(!s->budget--) { s->failed_pc=0x0c06932au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'*');
goto P_0c06932c;
P_0c06932c: /* original f54d, guest PC 0x0c06932c */
if(!s->budget--) { s->failed_pc=0x0c06932cu; return 0; }
fr[5]^=0x80000000u;
goto P_0c06932e;
P_0c06932e: /* original f2ee, guest PC 0x0c06932e */
if(!s->budget--) { s->failed_pc=0x0c06932eu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[14],fr[2],r[18]);
goto P_0c069330;
P_0c069330: /* original f06c, guest PC 0x0c069330 */
if(!s->budget--) { s->failed_pc=0x0c069330u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c069332;
P_0c069332: /* original f42c, guest PC 0x0c069332 */
if(!s->budget--) { s->failed_pc=0x0c069332u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c069334;
P_0c069334: /* original f41e, guest PC 0x0c069334 */
if(!s->budget--) { s->failed_pc=0x0c069334u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[1],fr[4],r[18]);
goto P_0c069336;
P_0c069336: /* original f2f8, guest PC 0x0c069336 */
if(!s->budget--) { s->failed_pc=0x0c069336u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c069338;
P_0c069338: /* original f272, guest PC 0x0c069338 */
if(!s->budget--) { s->failed_pc=0x0c069338u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c06933a;
P_0c06933a: /* original f34c, guest PC 0x0c06933a */
if(!s->budget--) { s->failed_pc=0x0c06933au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c06933c;
P_0c06933c: /* original f42c, guest PC 0x0c06933c */
if(!s->budget--) { s->failed_pc=0x0c06933cu; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c06933e;
P_0c06933e: /* original f431, guest PC 0x0c06933e */
if(!s->budget--) { s->failed_pc=0x0c06933eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c069340;
P_0c069340: /* original f3f6, guest PC 0x0c069340 */
if(!s->budget--) { s->failed_pc=0x0c069340u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c069342;
P_0c069342: /* original e014, guest PC 0x0c069342 */
if(!s->budget--) { s->failed_pc=0x0c069342u; return 0; }
r[0]=0x00000014u;
goto P_0c069344;
P_0c069344: /* original f24c, guest PC 0x0c069344 */
if(!s->budget--) { s->failed_pc=0x0c069344u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c069346;
P_0c069346: /* original f23e, guest PC 0x0c069346 */
if(!s->budget--) { s->failed_pc=0x0c069346u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[3],fr[2],r[18]);
goto P_0c069348;
P_0c069348: /* original f42c, guest PC 0x0c069348 */
if(!s->budget--) { s->failed_pc=0x0c069348u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c06934a;
P_0c06934a: /* original f453, guest PC 0x0c06934a */
if(!s->budget--) { s->failed_pc=0x0c06934au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'/');
goto P_0c06934c;
P_0c06934c: /* original f54a, guest PC 0x0c06934c */
if(!s->budget--) { s->failed_pc=0x0c06934cu; return 0; }
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c06934e;
P_0c06934e: /* original f346, guest PC 0x0c06934e */
if(!s->budget--) { s->failed_pc=0x0c06934eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c069350;
P_0c069350: /* original e018, guest PC 0x0c069350 */
if(!s->budget--) { s->failed_pc=0x0c069350u; return 0; }
r[0]=0x00000018u;
goto P_0c069352;
P_0c069352: /* original e103, guest PC 0x0c069352 */
if(!s->budget--) { s->failed_pc=0x0c069352u; return 0; }
r[1]=0x00000003u;
goto P_0c069354;
P_0c069354: /* original f63a, guest PC 0x0c069354 */
if(!s->budget--) { s->failed_pc=0x0c069354u; return 0; }
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c069356;
P_0c069356: /* original 7f0c, guest PC 0x0c069356 */
if(!s->budget--) { s->failed_pc=0x0c069356u; return 0; }
r[15]+=0x0000000cu;
goto P_0c069358;
P_0c069358: /* original f346, guest PC 0x0c069358 */
if(!s->budget--) { s->failed_pc=0x0c069358u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06935a;
P_0c06935a: /* original e004, guest PC 0x0c06935a */
if(!s->budget--) { s->failed_pc=0x0c06935au; return 0; }
r[0]=0x00000004u;
goto P_0c06935c;
P_0c06935c: /* original f637, guest PC 0x0c06935c */
if(!s->budget--) { s->failed_pc=0x0c06935cu; return 0; }
vf3_matrix_store(s,ram,3,r[6]+r[0]);
goto P_0c06935e;
P_0c06935e: /* original e01c, guest PC 0x0c06935e */
if(!s->budget--) { s->failed_pc=0x0c06935eu; return 0; }
r[0]=0x0000001cu;
goto P_0c069360;
P_0c069360: /* original f346, guest PC 0x0c069360 */
if(!s->budget--) { s->failed_pc=0x0c069360u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c069362;
P_0c069362: /* original e008, guest PC 0x0c069362 */
if(!s->budget--) { s->failed_pc=0x0c069362u; return 0; }
r[0]=0x00000008u;
goto P_0c069364;
P_0c069364: /* original f637, guest PC 0x0c069364 */
if(!s->budget--) { s->failed_pc=0x0c069364u; return 0; }
vf3_matrix_store(s,ram,3,r[6]+r[0]);
goto P_0c069366;
P_0c069366: /* original 6442, guest PC 0x0c069366 */
if(!s->budget--) { s->failed_pc=0x0c069366u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c069368;
P_0c069368: /* original d207, guest PC 0x0c069368 */
if(!s->budget--) { s->failed_pc=0x0c069368u; return 0; }
r[2]=read(ram,0x0c069388u,4);
goto P_0c06936a;
P_0c06936a: /* original 6343, guest PC 0x0c06936a */
if(!s->budget--) { s->failed_pc=0x0c06936au; return 0; }
r[3]=r[4];
goto P_0c06936c;
P_0c06936c: /* original 4300, guest PC 0x0c06936c */
if(!s->budget--) { s->failed_pc=0x0c06936cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c06936e;
P_0c06936e: /* original 2149, guest PC 0x0c06936e */
if(!s->budget--) { s->failed_pc=0x0c06936eu; return 0; }
r[1]&=r[4];
goto P_0c069370;
P_0c069370: /* original fef9, guest PC 0x0c069370 */
if(!s->budget--) { s->failed_pc=0x0c069370u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c069372;
P_0c069372: /* original 2329, guest PC 0x0c069372 */
if(!s->budget--) { s->failed_pc=0x0c069372u; return 0; }
r[3]&=r[2];
goto P_0c069374;
P_0c069374: /* original 6433, guest PC 0x0c069374 */
if(!s->budget--) { s->failed_pc=0x0c069374u; return 0; }
r[4]=r[3];
goto P_0c069376;
P_0c069376: /* original 241b, guest PC 0x0c069376 */
if(!s->budget--) { s->failed_pc=0x0c069376u; return 0; }
r[4]|=r[1];
goto P_0c069378;
P_0c069378: /* original 6043, guest PC 0x0c069378 */
if(!s->budget--) { s->failed_pc=0x0c069378u; return 0; }
r[0]=r[4];
goto P_0c06937a;
P_0c06937a: /* original 000b, guest PC 0x0c06937a */
if(!s->budget--) { s->failed_pc=0x0c06937au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06937c: /* original 6ef6, guest PC 0x0c06937c */
if(!s->budget--) { s->failed_pc=0x0c06937cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06937eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06937eu; return 0; } return 1;
P_0c06938c: /* original 2fe6, guest PC 0x0c06938c */
if(!s->budget--) { s->failed_pc=0x0c06938cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06938e;
P_0c06938e: /* original e004, guest PC 0x0c06938e */
if(!s->budget--) { s->failed_pc=0x0c06938eu; return 0; }
r[0]=0x00000004u;
goto P_0c069390;
P_0c069390: /* original 2fd6, guest PC 0x0c069390 */
if(!s->budget--) { s->failed_pc=0x0c069390u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c069392;
P_0c069392: /* original 6d43, guest PC 0x0c069392 */
if(!s->budget--) { s->failed_pc=0x0c069392u; return 0; }
r[13]=r[4];
goto P_0c069394;
P_0c069394: /* original 2fc6, guest PC 0x0c069394 */
if(!s->budget--) { s->failed_pc=0x0c069394u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c069396;
P_0c069396: /* original ec0f, guest PC 0x0c069396 */
if(!s->budget--) { s->failed_pc=0x0c069396u; return 0; }
r[12]=0x0000000fu;
goto P_0c069398;
P_0c069398: /* original 2fb6, guest PC 0x0c069398 */
if(!s->budget--) { s->failed_pc=0x0c069398u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06939a;
P_0c06939a: /* original 6b53, guest PC 0x0c06939a */
if(!s->budget--) { s->failed_pc=0x0c06939au; return 0; }
r[11]=r[5];
goto P_0c06939c;
P_0c06939c: /* original fffb, guest PC 0x0c06939c */
if(!s->budget--) { s->failed_pc=0x0c06939cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06939e;
P_0c06939e: /* original 4f22, guest PC 0x0c06939e */
if(!s->budget--) { s->failed_pc=0x0c06939eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0693a0;
P_0c0693a0: /* original 7fd8, guest PC 0x0c0693a0 */
if(!s->budget--) { s->failed_pc=0x0c0693a0u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c0693a2;
P_0c0693a2: /* original 66f3, guest PC 0x0c0693a2 */
if(!s->budget--) { s->failed_pc=0x0c0693a2u; return 0; }
r[6]=r[15];
goto P_0c0693a4;
P_0c0693a4: /* original 65f3, guest PC 0x0c0693a4 */
if(!s->budget--) { s->failed_pc=0x0c0693a4u; return 0; }
r[5]=r[15];
goto P_0c0693a6;
P_0c0693a6: /* original 7604, guest PC 0x0c0693a6 */
if(!s->budget--) { s->failed_pc=0x0c0693a6u; return 0; }
r[6]+=0x00000004u;
goto P_0c0693a8;
P_0c0693a8: /* original ff4a, guest PC 0x0c0693a8 */
if(!s->budget--) { s->failed_pc=0x0c0693a8u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c0693aa;
P_0c0693aa: /* original ff57, guest PC 0x0c0693aa */
if(!s->budget--) { s->failed_pc=0x0c0693aau; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0693ac;
P_0c0693ac: /* original d33a, guest PC 0x0c0693ac */
if(!s->budget--) { s->failed_pc=0x0c0693acu; return 0; }
r[3]=read(ram,0x0c069498u,4);
goto P_0c0693ae;
P_0c0693ae: /* original 6030, guest PC 0x0c0693ae */
if(!s->budget--) { s->failed_pc=0x0c0693aeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0693b0;
P_0c0693b0: /* original 600c, guest PC 0x0c0693b0 */
if(!s->budget--) { s->failed_pc=0x0c0693b0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0693b2;
P_0c0693b2: /* original 2c09, guest PC 0x0c0693b2 */
if(!s->budget--) { s->failed_pc=0x0c0693b2u; return 0; }
r[12]&=r[0];
goto P_0c0693b4;
P_0c0693b4: /* original bcce, guest PC 0x0c0693b4 */
if(!s->budget--) { s->failed_pc=0x0c0693b4u; return 0; }
target=code_base|0x0c068d54u; r[16]=code_base|0x0c0693b8u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0693b8u) { target=s->pc; goto dispatch; }
goto P_0c0693b8;
P_0c0693b6: /* original 64c3, guest PC 0x0c0693b6 */
if(!s->budget--) { s->failed_pc=0x0c0693b6u; return 0; }
r[4]=r[12];
goto P_0c0693b8;
P_0c0693b8: /* original 906d, guest PC 0x0c0693b8 */
if(!s->budget--) { s->failed_pc=0x0c0693b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069496u,2);
goto P_0c0693ba;
P_0c0693ba: /* original d538, guest PC 0x0c0693ba */
if(!s->budget--) { s->failed_pc=0x0c0693bau; return 0; }
r[5]=read(ram,0x0c06949cu,4);
goto P_0c0693bc;
P_0c0693bc: /* original 035e, guest PC 0x0c0693bc */
if(!s->budget--) { s->failed_pc=0x0c0693bcu; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c0693be;
P_0c0693be: /* original 2338, guest PC 0x0c0693be */
if(!s->budget--) { s->failed_pc=0x0c0693beu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0693c0;
P_0c0693c0: /* original 8b07, guest PC 0x0c0693c0 */
if(!s->budget--) { s->failed_pc=0x0c0693c0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0693d2; }
goto P_0c0693c2;
P_0c0693c2: /* original e004, guest PC 0x0c0693c2 */
if(!s->budget--) { s->failed_pc=0x0c0693c2u; return 0; }
r[0]=0x00000004u;
goto P_0c0693c4;
P_0c0693c4: /* original 64b3, guest PC 0x0c0693c4 */
if(!s->budget--) { s->failed_pc=0x0c0693c4u; return 0; }
r[4]=r[11];
goto P_0c0693c6;
P_0c0693c6: /* original f5f6, guest PC 0x0c0693c6 */
if(!s->budget--) { s->failed_pc=0x0c0693c6u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0693c8;
P_0c0693c8: /* original bd0c, guest PC 0x0c0693c8 */
if(!s->budget--) { s->failed_pc=0x0c0693c8u; return 0; }
target=code_base|0x0c068de4u; r[16]=code_base|0x0c0693ccu;
vf3_matrix_load(s,ram,4,r[15]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0693ccu) { target=s->pc; goto dispatch; }
goto P_0c0693cc;
P_0c0693ca: /* original f4f8, guest PC 0x0c0693ca */
if(!s->budget--) { s->failed_pc=0x0c0693cau; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0693cc;
P_0c0693cc: /* original fd0a, guest PC 0x0c0693cc */
if(!s->budget--) { s->failed_pc=0x0c0693ccu; return 0; }
vf3_matrix_store(s,ram,0,r[13]);
goto P_0c0693ce;
P_0c0693ce: /* original a09c, guest PC 0x0c0693ce */
if(!s->budget--) { s->failed_pc=0x0c0693ceu; return 0; }
r[0]=0x00000000u;
goto P_0c06950a;
P_0c0693d0: /* original e000, guest PC 0x0c0693d0 */
if(!s->budget--) { s->failed_pc=0x0c0693d0u; return 0; }
r[0]=0x00000000u;
goto P_0c0693d2;
P_0c0693d2: /* original c733, guest PC 0x0c0693d2 */
if(!s->budget--) { s->failed_pc=0x0c0693d2u; return 0; }
r[0]=code_base|0x000694a0u;
goto P_0c0693d4;
P_0c0693d4: /* original f3f8, guest PC 0x0c0693d4 */
if(!s->budget--) { s->failed_pc=0x0c0693d4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0693d6;
P_0c0693d6: /* original f408, guest PC 0x0c0693d6 */
if(!s->budget--) { s->failed_pc=0x0c0693d6u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0693d8;
P_0c0693d8: /* original f435, guest PC 0x0c0693d8 */
if(!s->budget--) { s->failed_pc=0x0c0693d8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c0693da;
P_0c0693da: /* original 8f0c, guest PC 0x0c0693da */
if(!s->budget--) { s->failed_pc=0x0c0693dau; return 0; }
cond=r[17]&1u;
fr[15]=0;
if(!cond) { goto P_0c0693f6; }
goto P_0c0693de;
P_0c0693dc: /* original ff8d, guest PC 0x0c0693dc */
if(!s->budget--) { s->failed_pc=0x0c0693dcu; return 0; }
fr[15]=0;
goto P_0c0693de;
P_0c0693de: /* original e004, guest PC 0x0c0693de */
if(!s->budget--) { s->failed_pc=0x0c0693deu; return 0; }
r[0]=0x00000004u;
goto P_0c0693e0;
P_0c0693e0: /* original f2f6, guest PC 0x0c0693e0 */
if(!s->budget--) { s->failed_pc=0x0c0693e0u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0693e2;
P_0c0693e2: /* original f425, guest PC 0x0c0693e2 */
if(!s->budget--) { s->failed_pc=0x0c0693e2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c0693e4;
P_0c0693e4: /* original 8b07, guest PC 0x0c0693e4 */
if(!s->budget--) { s->failed_pc=0x0c0693e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0693f6; }
goto P_0c0693e6;
P_0c0693e6: /* original c72f, guest PC 0x0c0693e6 */
if(!s->budget--) { s->failed_pc=0x0c0693e6u; return 0; }
r[0]=code_base|0x000694a4u;
goto P_0c0693e8;
P_0c0693e8: /* original f108, guest PC 0x0c0693e8 */
if(!s->budget--) { s->failed_pc=0x0c0693e8u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c0693ea;
P_0c0693ea: /* original f315, guest PC 0x0c0693ea */
if(!s->budget--) { s->failed_pc=0x0c0693eau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[1]))!=0);
goto P_0c0693ec;
P_0c0693ec: /* original 8b03, guest PC 0x0c0693ec */
if(!s->budget--) { s->failed_pc=0x0c0693ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0693f6; }
goto P_0c0693ee;
P_0c0693ee: /* original c72d, guest PC 0x0c0693ee */
if(!s->budget--) { s->failed_pc=0x0c0693eeu; return 0; }
r[0]=code_base|0x000694a4u;
goto P_0c0693f0;
P_0c0693f0: /* original f308, guest PC 0x0c0693f0 */
if(!s->budget--) { s->failed_pc=0x0c0693f0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0693f2;
P_0c0693f2: /* original f235, guest PC 0x0c0693f2 */
if(!s->budget--) { s->failed_pc=0x0c0693f2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0693f4;
P_0c0693f4: /* original 8902, guest PC 0x0c0693f4 */
if(!s->budget--) { s->failed_pc=0x0c0693f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0693fc; }
goto P_0c0693f6;
P_0c0693f6: /* original fdfa, guest PC 0x0c0693f6 */
if(!s->budget--) { s->failed_pc=0x0c0693f6u; return 0; }
vf3_matrix_store(s,ram,15,r[13]);
goto P_0c0693f8;
P_0c0693f8: /* original a05c, guest PC 0x0c0693f8 */
if(!s->budget--) { s->failed_pc=0x0c0693f8u; return 0; }
r[14]=0x00000001u;
goto P_0c0694b4;
P_0c0693fa: /* original ee01, guest PC 0x0c0693fa */
if(!s->budget--) { s->failed_pc=0x0c0693fau; return 0; }
r[14]=0x00000001u;
goto P_0c0693fc;
P_0c0693fc: /* original c72a, guest PC 0x0c0693fc */
if(!s->budget--) { s->failed_pc=0x0c0693fcu; return 0; }
r[0]=code_base|0x000694a8u;
goto P_0c0693fe;
P_0c0693fe: /* original f3f8, guest PC 0x0c0693fe */
if(!s->budget--) { s->failed_pc=0x0c0693feu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c069400;
P_0c069400: /* original f408, guest PC 0x0c069400 */
if(!s->budget--) { s->failed_pc=0x0c069400u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c069402;
P_0c069402: /* original e00c, guest PC 0x0c069402 */
if(!s->budget--) { s->failed_pc=0x0c069402u; return 0; }
r[0]=0x0000000cu;
goto P_0c069404;
P_0c069404: /* original ff37, guest PC 0x0c069404 */
if(!s->budget--) { s->failed_pc=0x0c069404u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c069406;
P_0c069406: /* original e004, guest PC 0x0c069406 */
if(!s->budget--) { s->failed_pc=0x0c069406u; return 0; }
r[0]=0x00000004u;
goto P_0c069408;
P_0c069408: /* original f3f6, guest PC 0x0c069408 */
if(!s->budget--) { s->failed_pc=0x0c069408u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06940a;
P_0c06940a: /* original e008, guest PC 0x0c06940a */
if(!s->budget--) { s->failed_pc=0x0c06940au; return 0; }
r[0]=0x00000008u;
goto P_0c06940c;
P_0c06940c: /* original e71f, guest PC 0x0c06940c */
if(!s->budget--) { s->failed_pc=0x0c06940cu; return 0; }
r[7]=0x0000001fu;
goto P_0c06940e;
P_0c06940e: /* original ff37, guest PC 0x0c06940e */
if(!s->budget--) { s->failed_pc=0x0c06940eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c069410;
P_0c069410: /* original e00c, guest PC 0x0c069410 */
if(!s->budget--) { s->failed_pc=0x0c069410u; return 0; }
r[0]=0x0000000cu;
goto P_0c069412;
P_0c069412: /* original f5f6, guest PC 0x0c069412 */
if(!s->budget--) { s->failed_pc=0x0c069412u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c069414;
P_0c069414: /* original e008, guest PC 0x0c069414 */
if(!s->budget--) { s->failed_pc=0x0c069414u; return 0; }
r[0]=0x00000008u;
goto P_0c069416;
P_0c069416: /* original f34c, guest PC 0x0c069416 */
if(!s->budget--) { s->failed_pc=0x0c069416u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c069418;
P_0c069418: /* original f540, guest PC 0x0c069418 */
if(!s->budget--) { s->failed_pc=0x0c069418u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'+');
goto P_0c06941a;
P_0c06941a: /* original f4f6, guest PC 0x0c06941a */
if(!s->budget--) { s->failed_pc=0x0c06941au; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c06941c;
P_0c06941c: /* original 903b, guest PC 0x0c06941c */
if(!s->budget--) { s->failed_pc=0x0c06941cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069496u,2);
goto P_0c06941e;
P_0c06941e: /* original f430, guest PC 0x0c06941e */
if(!s->budget--) { s->failed_pc=0x0c06941eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c069420;
P_0c069420: /* original 035e, guest PC 0x0c069420 */
if(!s->budget--) { s->failed_pc=0x0c069420u; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c069422;
P_0c069422: /* original f53d, guest PC 0x0c069422 */
if(!s->budget--) { s->failed_pc=0x0c069422u; return 0; }
r[53]=truncate_float(fr[5]);
goto P_0c069424;
P_0c069424: /* original 045a, guest PC 0x0c069424 */
if(!s->budget--) { s->failed_pc=0x0c069424u; return 0; }
r[4]=r[53];
goto P_0c069426;
P_0c069426: /* original f43d, guest PC 0x0c069426 */
if(!s->budget--) { s->failed_pc=0x0c069426u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c069428;
P_0c069428: /* original 2479, guest PC 0x0c069428 */
if(!s->budget--) { s->failed_pc=0x0c069428u; return 0; }
r[4]&=r[7];
goto P_0c06942a;
P_0c06942a: /* original 065a, guest PC 0x0c06942a */
if(!s->budget--) { s->failed_pc=0x0c06942au; return 0; }
r[6]=r[53];
goto P_0c06942c;
P_0c06942c: /* original 2679, guest PC 0x0c06942c */
if(!s->budget--) { s->failed_pc=0x0c06942cu; return 0; }
r[6]&=r[7];
goto P_0c06942e;
P_0c06942e: /* original 4608, guest PC 0x0c06942e */
if(!s->budget--) { s->failed_pc=0x0c06942eu; return 0; }
r[6]<<=2;
goto P_0c069430;
P_0c069430: /* original 4608, guest PC 0x0c069430 */
if(!s->budget--) { s->failed_pc=0x0c069430u; return 0; }
r[6]<<=2;
goto P_0c069432;
P_0c069432: /* original 4600, guest PC 0x0c069432 */
if(!s->budget--) { s->failed_pc=0x0c069432u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c069434;
P_0c069434: /* original 246b, guest PC 0x0c069434 */
if(!s->budget--) { s->failed_pc=0x0c069434u; return 0; }
r[4]|=r[6];
goto P_0c069436;
P_0c069436: /* original 4408, guest PC 0x0c069436 */
if(!s->budget--) { s->failed_pc=0x0c069436u; return 0; }
r[4]<<=2;
goto P_0c069438;
P_0c069438: /* original 343c, guest PC 0x0c069438 */
if(!s->budget--) { s->failed_pc=0x0c069438u; return 0; }
r[4]+=r[3];
goto P_0c06943a;
P_0c06943a: /* original 6442, guest PC 0x0c06943a */
if(!s->budget--) { s->failed_pc=0x0c06943au; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c06943c;
P_0c06943c: /* original 6043, guest PC 0x0c06943c */
if(!s->budget--) { s->failed_pc=0x0c06943cu; return 0; }
r[0]=r[4];
goto P_0c06943e;
P_0c06943e: /* original 88ff, guest PC 0x0c06943e */
if(!s->budget--) { s->failed_pc=0x0c06943eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c069440;
P_0c069440: /* original 8936, guest PC 0x0c069440 */
if(!s->budget--) { s->failed_pc=0x0c069440u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0694b0; }
goto P_0c069442;
P_0c069442: /* original d21a, guest PC 0x0c069442 */
if(!s->budget--) { s->failed_pc=0x0c069442u; return 0; }
r[2]=read(ram,0x0c0694acu,4);
goto P_0c069444;
P_0c069444: /* original 6322, guest PC 0x0c069444 */
if(!s->budget--) { s->failed_pc=0x0c069444u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c069446;
P_0c069446: /* original 343c, guest PC 0x0c069446 */
if(!s->budget--) { s->failed_pc=0x0c069446u; return 0; }
r[4]+=r[3];
goto P_0c069448;
P_0c069448: /* original 6e43, guest PC 0x0c069448 */
if(!s->budget--) { s->failed_pc=0x0c069448u; return 0; }
r[14]=r[4];
goto P_0c06944a;
P_0c06944a: /* original 60e2, guest PC 0x0c06944a */
if(!s->budget--) { s->failed_pc=0x0c06944au; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c06944c;
P_0c06944c: /* original 88ff, guest PC 0x0c06944c */
if(!s->budget--) { s->failed_pc=0x0c06944cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c06944e;
P_0c06944e: /* original 8d2f, guest PC 0x0c06944e */
if(!s->budget--) { s->failed_pc=0x0c06944eu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0694b0; }
goto P_0c069452;
P_0c069450: /* original 6403, guest PC 0x0c069450 */
if(!s->budget--) { s->failed_pc=0x0c069450u; return 0; }
r[4]=r[0];
goto P_0c069452;
P_0c069452: /* original e008, guest PC 0x0c069452 */
if(!s->budget--) { s->failed_pc=0x0c069452u; return 0; }
r[0]=0x00000008u;
goto P_0c069454;
P_0c069454: /* original f5f6, guest PC 0x0c069454 */
if(!s->budget--) { s->failed_pc=0x0c069454u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c069456;
P_0c069456: /* original e00c, guest PC 0x0c069456 */
if(!s->budget--) { s->failed_pc=0x0c069456u; return 0; }
r[0]=0x0000000cu;
goto P_0c069458;
P_0c069458: /* original f4f6, guest PC 0x0c069458 */
if(!s->budget--) { s->failed_pc=0x0c069458u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c06945a;
P_0c06945a: /* original bdc3, guest PC 0x0c06945a */
if(!s->budget--) { s->failed_pc=0x0c06945au; return 0; }
target=code_base|0x0c068fe4u; r[16]=code_base|0x0c06945eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06945eu) { target=s->pc; goto dispatch; }
goto P_0c06945e;
P_0c06945c: /* original 64e3, guest PC 0x0c06945c */
if(!s->budget--) { s->failed_pc=0x0c06945cu; return 0; }
r[4]=r[14];
goto P_0c06945e;
P_0c06945e: /* original 6703, guest PC 0x0c06945e */
if(!s->budget--) { s->failed_pc=0x0c06945eu; return 0; }
r[7]=r[0];
goto P_0c069460;
P_0c069460: /* original 2778, guest PC 0x0c069460 */
if(!s->budget--) { s->failed_pc=0x0c069460u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c069462;
P_0c069462: /* original 8916, guest PC 0x0c069462 */
if(!s->budget--) { s->failed_pc=0x0c069462u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069492; }
goto P_0c069464;
P_0c069464: /* original e008, guest PC 0x0c069464 */
if(!s->budget--) { s->failed_pc=0x0c069464u; return 0; }
r[0]=0x00000008u;
goto P_0c069466;
P_0c069466: /* original 66f3, guest PC 0x0c069466 */
if(!s->budget--) { s->failed_pc=0x0c069466u; return 0; }
r[6]=r[15];
goto P_0c069468;
P_0c069468: /* original f5f6, guest PC 0x0c069468 */
if(!s->budget--) { s->failed_pc=0x0c069468u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c06946a;
P_0c06946a: /* original e00c, guest PC 0x0c06946a */
if(!s->budget--) { s->failed_pc=0x0c06946au; return 0; }
r[0]=0x0000000cu;
goto P_0c06946c;
P_0c06946c: /* original f4f6, guest PC 0x0c06946c */
if(!s->budget--) { s->failed_pc=0x0c06946cu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c06946e;
P_0c06946e: /* original 761c, guest PC 0x0c06946e */
if(!s->budget--) { s->failed_pc=0x0c06946eu; return 0; }
r[6]+=0x0000001cu;
goto P_0c069470;
P_0c069470: /* original 65d3, guest PC 0x0c069470 */
if(!s->budget--) { s->failed_pc=0x0c069470u; return 0; }
r[5]=r[13];
goto P_0c069472;
P_0c069472: /* original bf18, guest PC 0x0c069472 */
if(!s->budget--) { s->failed_pc=0x0c069472u; return 0; }
target=code_base|0x0c0692a6u; r[16]=code_base|0x0c069476u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069476u) { target=s->pc; goto dispatch; }
goto P_0c069476;
P_0c069474: /* original 64e3, guest PC 0x0c069474 */
if(!s->budget--) { s->failed_pc=0x0c069474u; return 0; }
r[4]=r[14];
goto P_0c069476;
P_0c069476: /* original 6e03, guest PC 0x0c069476 */
if(!s->budget--) { s->failed_pc=0x0c069476u; return 0; }
r[14]=r[0];
goto P_0c069478;
P_0c069478: /* original e01c, guest PC 0x0c069478 */
if(!s->budget--) { s->failed_pc=0x0c069478u; return 0; }
r[0]=0x0000001cu;
goto P_0c06947a;
P_0c06947a: /* original f3f6, guest PC 0x0c06947a */
if(!s->budget--) { s->failed_pc=0x0c06947au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06947c;
P_0c06947c: /* original e014, guest PC 0x0c06947c */
if(!s->budget--) { s->failed_pc=0x0c06947cu; return 0; }
r[0]=0x00000014u;
goto P_0c06947e;
P_0c06947e: /* original ff37, guest PC 0x0c06947e */
if(!s->budget--) { s->failed_pc=0x0c06947eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c069480;
P_0c069480: /* original e020, guest PC 0x0c069480 */
if(!s->budget--) { s->failed_pc=0x0c069480u; return 0; }
r[0]=0x00000020u;
goto P_0c069482;
P_0c069482: /* original f3f6, guest PC 0x0c069482 */
if(!s->budget--) { s->failed_pc=0x0c069482u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c069484;
P_0c069484: /* original e018, guest PC 0x0c069484 */
if(!s->budget--) { s->failed_pc=0x0c069484u; return 0; }
r[0]=0x00000018u;
goto P_0c069486;
P_0c069486: /* original ff37, guest PC 0x0c069486 */
if(!s->budget--) { s->failed_pc=0x0c069486u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c069488;
P_0c069488: /* original e024, guest PC 0x0c069488 */
if(!s->budget--) { s->failed_pc=0x0c069488u; return 0; }
r[0]=0x00000024u;
goto P_0c06948a;
P_0c06948a: /* original f3f6, guest PC 0x0c06948a */
if(!s->budget--) { s->failed_pc=0x0c06948au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06948c;
P_0c06948c: /* original e010, guest PC 0x0c06948c */
if(!s->budget--) { s->failed_pc=0x0c06948cu; return 0; }
r[0]=0x00000010u;
goto P_0c06948e;
P_0c06948e: /* original a018, guest PC 0x0c06948e */
if(!s->budget--) { s->failed_pc=0x0c06948eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0694c2;
P_0c069490: /* original ff37, guest PC 0x0c069490 */
if(!s->budget--) { s->failed_pc=0x0c069490u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c069492;
P_0c069492: /* original afda, guest PC 0x0c069492 */
if(!s->budget--) { s->failed_pc=0x0c069492u; return 0; }
r[14]+=0x00000008u;
goto P_0c06944a;
P_0c069494: /* original 7e08, guest PC 0x0c069494 */
if(!s->budget--) { s->failed_pc=0x0c069494u; return 0; }
r[14]+=0x00000008u;
if(!vf3_matrix_family(0x0c069496u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c069496u; return 0; } return 1;
P_0c0694b0: /* original fdfa, guest PC 0x0c0694b0 */
if(!s->budget--) { s->failed_pc=0x0c0694b0u; return 0; }
vf3_matrix_store(s,ram,15,r[13]);
goto P_0c0694b2;
P_0c0694b2: /* original ee02, guest PC 0x0c0694b2 */
if(!s->budget--) { s->failed_pc=0x0c0694b2u; return 0; }
r[14]=0x00000002u;
goto P_0c0694b4;
P_0c0694b4: /* original e018, guest PC 0x0c0694b4 */
if(!s->budget--) { s->failed_pc=0x0c0694b4u; return 0; }
r[0]=0x00000018u;
goto P_0c0694b6;
P_0c0694b6: /* original f39d, guest PC 0x0c0694b6 */
if(!s->budget--) { s->failed_pc=0x0c0694b6u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0694b8;
P_0c0694b8: /* original ff37, guest PC 0x0c0694b8 */
if(!s->budget--) { s->failed_pc=0x0c0694b8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0694ba;
P_0c0694ba: /* original e010, guest PC 0x0c0694ba */
if(!s->budget--) { s->failed_pc=0x0c0694bau; return 0; }
r[0]=0x00000010u;
goto P_0c0694bc;
P_0c0694bc: /* original fff7, guest PC 0x0c0694bc */
if(!s->budget--) { s->failed_pc=0x0c0694bcu; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0694be;
P_0c0694be: /* original e014, guest PC 0x0c0694be */
if(!s->budget--) { s->failed_pc=0x0c0694beu; return 0; }
r[0]=0x00000014u;
goto P_0c0694c0;
P_0c0694c0: /* original fff7, guest PC 0x0c0694c0 */
if(!s->budget--) { s->failed_pc=0x0c0694c0u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0694c2;
P_0c0694c2: /* original 60c3, guest PC 0x0c0694c2 */
if(!s->budget--) { s->failed_pc=0x0c0694c2u; return 0; }
r[0]=r[12];
goto P_0c0694c4;
P_0c0694c4: /* original 880d, guest PC 0x0c0694c4 */
if(!s->budget--) { s->failed_pc=0x0c0694c4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0694c6;
P_0c0694c6: /* original 8b02, guest PC 0x0c0694c6 */
if(!s->budget--) { s->failed_pc=0x0c0694c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0694ce; }
goto P_0c0694c8;
P_0c0694c8: /* original e204, guest PC 0x0c0694c8 */
if(!s->budget--) { s->failed_pc=0x0c0694c8u; return 0; }
r[2]=0x00000004u;
goto P_0c0694ca;
P_0c0694ca: /* original a012, guest PC 0x0c0694ca */
if(!s->budget--) { s->failed_pc=0x0c0694cau; return 0; }
r[14]|=r[2];
goto P_0c0694f2;
P_0c0694cc: /* original 2e2b, guest PC 0x0c0694cc */
if(!s->budget--) { s->failed_pc=0x0c0694ccu; return 0; }
r[14]|=r[2];
goto P_0c0694ce;
P_0c0694ce: /* original 880b, guest PC 0x0c0694ce */
if(!s->budget--) { s->failed_pc=0x0c0694ceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0694d0;
P_0c0694d0: /* original 8b0f, guest PC 0x0c0694d0 */
if(!s->budget--) { s->failed_pc=0x0c0694d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0694f2; }
goto P_0c0694d2;
P_0c0694d2: /* original 63f3, guest PC 0x0c0694d2 */
if(!s->budget--) { s->failed_pc=0x0c0694d2u; return 0; }
r[3]=r[15];
goto P_0c0694d4;
P_0c0694d4: /* original 7310, guest PC 0x0c0694d4 */
if(!s->budget--) { s->failed_pc=0x0c0694d4u; return 0; }
r[3]+=0x00000010u;
goto P_0c0694d6;
P_0c0694d6: /* original 2f36, guest PC 0x0c0694d6 */
if(!s->budget--) { s->failed_pc=0x0c0694d6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0694d8;
P_0c0694d8: /* original 65d3, guest PC 0x0c0694d8 */
if(!s->budget--) { s->failed_pc=0x0c0694d8u; return 0; }
r[5]=r[13];
goto P_0c0694da;
P_0c0694da: /* original 62f3, guest PC 0x0c0694da */
if(!s->budget--) { s->failed_pc=0x0c0694dau; return 0; }
r[2]=r[15];
goto P_0c0694dc;
P_0c0694dc: /* original 721c, guest PC 0x0c0694dc */
if(!s->budget--) { s->failed_pc=0x0c0694dcu; return 0; }
r[2]+=0x0000001cu;
goto P_0c0694de;
P_0c0694de: /* original 2f26, guest PC 0x0c0694de */
if(!s->budget--) { s->failed_pc=0x0c0694deu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0694e0;
P_0c0694e0: /* original 66f3, guest PC 0x0c0694e0 */
if(!s->budget--) { s->failed_pc=0x0c0694e0u; return 0; }
r[6]=r[15];
goto P_0c0694e2;
P_0c0694e2: /* original d348, guest PC 0x0c0694e2 */
if(!s->budget--) { s->failed_pc=0x0c0694e2u; return 0; }
r[3]=read(ram,0x0c069604u,4);
goto P_0c0694e4;
P_0c0694e4: /* original 67f3, guest PC 0x0c0694e4 */
if(!s->budget--) { s->failed_pc=0x0c0694e4u; return 0; }
r[7]=r[15];
goto P_0c0694e6;
P_0c0694e6: /* original 64f3, guest PC 0x0c0694e6 */
if(!s->budget--) { s->failed_pc=0x0c0694e6u; return 0; }
r[4]=r[15];
goto P_0c0694e8;
P_0c0694e8: /* original 771c, guest PC 0x0c0694e8 */
if(!s->budget--) { s->failed_pc=0x0c0694e8u; return 0; }
r[7]+=0x0000001cu;
goto P_0c0694ea;
P_0c0694ea: /* original 7610, guest PC 0x0c0694ea */
if(!s->budget--) { s->failed_pc=0x0c0694eau; return 0; }
r[6]+=0x00000010u;
goto P_0c0694ec;
P_0c0694ec: /* original 430b, guest PC 0x0c0694ec */
if(!s->budget--) { s->failed_pc=0x0c0694ecu; return 0; }
target=r[3];
r[16]=code_base|0x0c0694f0u;
r[4]+=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0694f0u) { target=s->pc; goto dispatch; }
goto P_0c0694f0;
P_0c0694ee: /* original 7414, guest PC 0x0c0694ee */
if(!s->budget--) { s->failed_pc=0x0c0694eeu; return 0; }
r[4]+=0x00000014u;
goto P_0c0694f0;
P_0c0694f0: /* original 7f08, guest PC 0x0c0694f0 */
if(!s->budget--) { s->failed_pc=0x0c0694f0u; return 0; }
r[15]+=0x00000008u;
goto P_0c0694f2;
P_0c0694f2: /* original e014, guest PC 0x0c0694f2 */
if(!s->budget--) { s->failed_pc=0x0c0694f2u; return 0; }
r[0]=0x00000014u;
goto P_0c0694f4;
P_0c0694f4: /* original f3f6, guest PC 0x0c0694f4 */
if(!s->budget--) { s->failed_pc=0x0c0694f4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0694f6;
P_0c0694f6: /* original e018, guest PC 0x0c0694f6 */
if(!s->budget--) { s->failed_pc=0x0c0694f6u; return 0; }
r[0]=0x00000018u;
goto P_0c0694f8;
P_0c0694f8: /* original fb3a, guest PC 0x0c0694f8 */
if(!s->budget--) { s->failed_pc=0x0c0694f8u; return 0; }
vf3_matrix_store(s,ram,3,r[11]);
goto P_0c0694fa;
P_0c0694fa: /* original f3f6, guest PC 0x0c0694fa */
if(!s->budget--) { s->failed_pc=0x0c0694fau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0694fc;
P_0c0694fc: /* original e004, guest PC 0x0c0694fc */
if(!s->budget--) { s->failed_pc=0x0c0694fcu; return 0; }
r[0]=0x00000004u;
goto P_0c0694fe;
P_0c0694fe: /* original fb37, guest PC 0x0c0694fe */
if(!s->budget--) { s->failed_pc=0x0c0694feu; return 0; }
vf3_matrix_store(s,ram,3,r[11]+r[0]);
goto P_0c069500;
P_0c069500: /* original e010, guest PC 0x0c069500 */
if(!s->budget--) { s->failed_pc=0x0c069500u; return 0; }
r[0]=0x00000010u;
goto P_0c069502;
P_0c069502: /* original f3f6, guest PC 0x0c069502 */
if(!s->budget--) { s->failed_pc=0x0c069502u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c069504;
P_0c069504: /* original e008, guest PC 0x0c069504 */
if(!s->budget--) { s->failed_pc=0x0c069504u; return 0; }
r[0]=0x00000008u;
goto P_0c069506;
P_0c069506: /* original fb37, guest PC 0x0c069506 */
if(!s->budget--) { s->failed_pc=0x0c069506u; return 0; }
vf3_matrix_store(s,ram,3,r[11]+r[0]);
goto P_0c069508;
P_0c069508: /* original 60e3, guest PC 0x0c069508 */
if(!s->budget--) { s->failed_pc=0x0c069508u; return 0; }
r[0]=r[14];
goto P_0c06950a;
P_0c06950a: /* original 7f28, guest PC 0x0c06950a */
if(!s->budget--) { s->failed_pc=0x0c06950au; return 0; }
r[15]+=0x00000028u;
goto P_0c06950c;
P_0c06950c: /* original 4f26, guest PC 0x0c06950c */
if(!s->budget--) { s->failed_pc=0x0c06950cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06950e;
P_0c06950e: /* original fff9, guest PC 0x0c06950e */
if(!s->budget--) { s->failed_pc=0x0c06950eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c069510;
P_0c069510: /* original 6bf6, guest PC 0x0c069510 */
if(!s->budget--) { s->failed_pc=0x0c069510u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c069512;
P_0c069512: /* original 6cf6, guest PC 0x0c069512 */
if(!s->budget--) { s->failed_pc=0x0c069512u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c069514;
P_0c069514: /* original 6df6, guest PC 0x0c069514 */
if(!s->budget--) { s->failed_pc=0x0c069514u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c069516;
P_0c069516: /* original 000b, guest PC 0x0c069516 */
if(!s->budget--) { s->failed_pc=0x0c069516u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c069518: /* original 6ef6, guest PC 0x0c069518 */
if(!s->budget--) { s->failed_pc=0x0c069518u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06951au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06951au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
