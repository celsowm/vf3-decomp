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
int vf3_away_batch3_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c036316u: goto P_0c036316;
case 0x0c036318u: goto P_0c036318;
case 0x0c03631au: goto P_0c03631a;
case 0x0c03631cu: goto P_0c03631c;
case 0x0c03631eu: goto P_0c03631e;
case 0x0c036320u: goto P_0c036320;
case 0x0c036322u: goto P_0c036322;
case 0x0c036324u: goto P_0c036324;
case 0x0c036326u: goto P_0c036326;
case 0x0c036328u: goto P_0c036328;
case 0x0c03632au: goto P_0c03632a;
case 0x0c03632cu: goto P_0c03632c;
case 0x0c03632eu: goto P_0c03632e;
case 0x0c036330u: goto P_0c036330;
case 0x0c036332u: goto P_0c036332;
case 0x0c036334u: goto P_0c036334;
case 0x0c036336u: goto P_0c036336;
case 0x0c036338u: goto P_0c036338;
case 0x0c03633au: goto P_0c03633a;
case 0x0c03633cu: goto P_0c03633c;
case 0x0c03633eu: goto P_0c03633e;
case 0x0c036340u: goto P_0c036340;
case 0x0c036342u: goto P_0c036342;
case 0x0c036344u: goto P_0c036344;
case 0x0c036346u: goto P_0c036346;
case 0x0c036348u: goto P_0c036348;
case 0x0c03634au: goto P_0c03634a;
case 0x0c03634cu: goto P_0c03634c;
case 0x0c03634eu: goto P_0c03634e;
case 0x0c036350u: goto P_0c036350;
case 0x0c036352u: goto P_0c036352;
case 0x0c036354u: goto P_0c036354;
case 0x0c036356u: goto P_0c036356;
case 0x0c036358u: goto P_0c036358;
case 0x0c03635au: goto P_0c03635a;
case 0x0c03635cu: goto P_0c03635c;
case 0x0c03635eu: goto P_0c03635e;
case 0x0c036360u: goto P_0c036360;
case 0x0c036362u: goto P_0c036362;
case 0x0c036364u: goto P_0c036364;
case 0x0c036366u: goto P_0c036366;
case 0x0c036368u: goto P_0c036368;
case 0x0c03636au: goto P_0c03636a;
case 0x0c03636cu: goto P_0c03636c;
case 0x0c03636eu: goto P_0c03636e;
case 0x0c036370u: goto P_0c036370;
case 0x0c036372u: goto P_0c036372;
case 0x0c036374u: goto P_0c036374;
case 0x0c036376u: goto P_0c036376;
case 0x0c036378u: goto P_0c036378;
case 0x0c03637au: goto P_0c03637a;
case 0x0c03637cu: goto P_0c03637c;
case 0x0c03637eu: goto P_0c03637e;
case 0x0c036380u: goto P_0c036380;
case 0x0c036382u: goto P_0c036382;
case 0x0c036384u: goto P_0c036384;
case 0x0c036386u: goto P_0c036386;
case 0x0c036388u: goto P_0c036388;
case 0x0c03638au: goto P_0c03638a;
case 0x0c03638cu: goto P_0c03638c;
case 0x0c03638eu: goto P_0c03638e;
case 0x0c036390u: goto P_0c036390;
case 0x0c036392u: goto P_0c036392;
case 0x0c036394u: goto P_0c036394;
case 0x0c036396u: goto P_0c036396;
case 0x0c036398u: goto P_0c036398;
case 0x0c03639au: goto P_0c03639a;
case 0x0c03639cu: goto P_0c03639c;
case 0x0c03639eu: goto P_0c03639e;
case 0x0c0363a0u: goto P_0c0363a0;
case 0x0c0363a2u: goto P_0c0363a2;
case 0x0c0363a4u: goto P_0c0363a4;
case 0x0c0363a6u: goto P_0c0363a6;
case 0x0c0363a8u: goto P_0c0363a8;
case 0x0c0363aau: goto P_0c0363aa;
case 0x0c0363acu: goto P_0c0363ac;
case 0x0c0363aeu: goto P_0c0363ae;
case 0x0c0363b0u: goto P_0c0363b0;
case 0x0c0363b2u: goto P_0c0363b2;
case 0x0c0363b4u: goto P_0c0363b4;
case 0x0c0363b6u: goto P_0c0363b6;
case 0x0c0363b8u: goto P_0c0363b8;
case 0x0c0363bau: goto P_0c0363ba;
case 0x0c0363bcu: goto P_0c0363bc;
case 0x0c0363beu: goto P_0c0363be;
case 0x0c0363c0u: goto P_0c0363c0;
case 0x0c0363c2u: goto P_0c0363c2;
case 0x0c0363c4u: goto P_0c0363c4;
case 0x0c0363c6u: goto P_0c0363c6;
case 0x0c0363c8u: goto P_0c0363c8;
case 0x0c0363cau: goto P_0c0363ca;
case 0x0c0363ccu: goto P_0c0363cc;
case 0x0c0363ceu: goto P_0c0363ce;
case 0x0c0363d0u: goto P_0c0363d0;
case 0x0c0363d2u: goto P_0c0363d2;
case 0x0c0363d4u: goto P_0c0363d4;
case 0x0c0363d6u: goto P_0c0363d6;
case 0x0c0363d8u: goto P_0c0363d8;
case 0x0c0363dau: goto P_0c0363da;
case 0x0c0363dcu: goto P_0c0363dc;
case 0x0c0363deu: goto P_0c0363de;
case 0x0c036404u: goto P_0c036404;
case 0x0c036406u: goto P_0c036406;
case 0x0c036408u: goto P_0c036408;
case 0x0c03640au: goto P_0c03640a;
case 0x0c03640cu: goto P_0c03640c;
case 0x0c03640eu: goto P_0c03640e;
case 0x0c036410u: goto P_0c036410;
case 0x0c036412u: goto P_0c036412;
case 0x0c036414u: goto P_0c036414;
case 0x0c036416u: goto P_0c036416;
case 0x0c036418u: goto P_0c036418;
case 0x0c03641au: goto P_0c03641a;
case 0x0c03641cu: goto P_0c03641c;
case 0x0c03641eu: goto P_0c03641e;
case 0x0c036420u: goto P_0c036420;
case 0x0c036422u: goto P_0c036422;
case 0x0c036424u: goto P_0c036424;
case 0x0c036426u: goto P_0c036426;
case 0x0c036428u: goto P_0c036428;
case 0x0c03642au: goto P_0c03642a;
case 0x0c03642cu: goto P_0c03642c;
case 0x0c03642eu: goto P_0c03642e;
case 0x0c036430u: goto P_0c036430;
case 0x0c036432u: goto P_0c036432;
case 0x0c036434u: goto P_0c036434;
case 0x0c036436u: goto P_0c036436;
case 0x0c036438u: goto P_0c036438;
case 0x0c03643au: goto P_0c03643a;
case 0x0c03643cu: goto P_0c03643c;
case 0x0c03643eu: goto P_0c03643e;
case 0x0c036440u: goto P_0c036440;
case 0x0c036442u: goto P_0c036442;
case 0x0c036444u: goto P_0c036444;
case 0x0c036446u: goto P_0c036446;
case 0x0c036448u: goto P_0c036448;
case 0x0c03644au: goto P_0c03644a;
case 0x0c03644cu: goto P_0c03644c;
case 0x0c03644eu: goto P_0c03644e;
case 0x0c036450u: goto P_0c036450;
case 0x0c036452u: goto P_0c036452;
case 0x0c036454u: goto P_0c036454;
case 0x0c036456u: goto P_0c036456;
case 0x0c036458u: goto P_0c036458;
case 0x0c03645au: goto P_0c03645a;
case 0x0c03645cu: goto P_0c03645c;
case 0x0c03645eu: goto P_0c03645e;
case 0x0c036460u: goto P_0c036460;
case 0x0c036462u: goto P_0c036462;
case 0x0c036464u: goto P_0c036464;
case 0x0c036466u: goto P_0c036466;
case 0x0c036468u: goto P_0c036468;
case 0x0c03646au: goto P_0c03646a;
case 0x0c03646cu: goto P_0c03646c;
case 0x0c03646eu: goto P_0c03646e;
case 0x0c036470u: goto P_0c036470;
case 0x0c036472u: goto P_0c036472;
case 0x0c036474u: goto P_0c036474;
case 0x0c036476u: goto P_0c036476;
case 0x0c036478u: goto P_0c036478;
case 0x0c03647au: goto P_0c03647a;
case 0x0c03647cu: goto P_0c03647c;
case 0x0c03647eu: goto P_0c03647e;
case 0x0c036480u: goto P_0c036480;
case 0x0c036482u: goto P_0c036482;
case 0x0c036484u: goto P_0c036484;
case 0x0c036486u: goto P_0c036486;
case 0x0c036488u: goto P_0c036488;
case 0x0c03648au: goto P_0c03648a;
case 0x0c03648cu: goto P_0c03648c;
case 0x0c03648eu: goto P_0c03648e;
case 0x0c036490u: goto P_0c036490;
case 0x0c036492u: goto P_0c036492;
case 0x0c036494u: goto P_0c036494;
case 0x0c036496u: goto P_0c036496;
case 0x0c036498u: goto P_0c036498;
case 0x0c03649au: goto P_0c03649a;
case 0x0c03649cu: goto P_0c03649c;
case 0x0c03649eu: goto P_0c03649e;
case 0x0c0364a0u: goto P_0c0364a0;
case 0x0c0364a2u: goto P_0c0364a2;
case 0x0c0364a4u: goto P_0c0364a4;
case 0x0c0364a6u: goto P_0c0364a6;
case 0x0c0364a8u: goto P_0c0364a8;
case 0x0c0364aau: goto P_0c0364aa;
case 0x0c0364acu: goto P_0c0364ac;
case 0x0c0364aeu: goto P_0c0364ae;
case 0x0c0364b0u: goto P_0c0364b0;
case 0x0c0364b2u: goto P_0c0364b2;
case 0x0c0364b4u: goto P_0c0364b4;
case 0x0c0364b6u: goto P_0c0364b6;
case 0x0c03658cu: goto P_0c03658c;
case 0x0c03658eu: goto P_0c03658e;
case 0x0c036590u: goto P_0c036590;
case 0x0c036592u: goto P_0c036592;
case 0x0c036594u: goto P_0c036594;
case 0x0c036596u: goto P_0c036596;
case 0x0c036598u: goto P_0c036598;
case 0x0c03659au: goto P_0c03659a;
case 0x0c03659cu: goto P_0c03659c;
case 0x0c03659eu: goto P_0c03659e;
case 0x0c0365a0u: goto P_0c0365a0;
case 0x0c0365a2u: goto P_0c0365a2;
case 0x0c0365a4u: goto P_0c0365a4;
case 0x0c0365a6u: goto P_0c0365a6;
case 0x0c0365a8u: goto P_0c0365a8;
case 0x0c0365aau: goto P_0c0365aa;
case 0x0c0365acu: goto P_0c0365ac;
case 0x0c0365aeu: goto P_0c0365ae;
case 0x0c0365b0u: goto P_0c0365b0;
case 0x0c0365b2u: goto P_0c0365b2;
case 0x0c0365b4u: goto P_0c0365b4;
case 0x0c0365b6u: goto P_0c0365b6;
case 0x0c0365b8u: goto P_0c0365b8;
case 0x0c0365bau: goto P_0c0365ba;
case 0x0c0365bcu: goto P_0c0365bc;
case 0x0c0365beu: goto P_0c0365be;
case 0x0c0365c0u: goto P_0c0365c0;
case 0x0c0365c2u: goto P_0c0365c2;
case 0x0c0365c4u: goto P_0c0365c4;
case 0x0c0365c6u: goto P_0c0365c6;
case 0x0c0365c8u: goto P_0c0365c8;
case 0x0c0365cau: goto P_0c0365ca;
case 0x0c0365ccu: goto P_0c0365cc;
case 0x0c0365ceu: goto P_0c0365ce;
case 0x0c0365d0u: goto P_0c0365d0;
case 0x0c0365d2u: goto P_0c0365d2;
default: return vf3_matrix_family(target,s,ram);
}
P_0c036316: /* original e000, guest PC 0x0c036316 */
if(!s->budget--) { s->failed_pc=0x0c036316u; return 0; }
r[0]=0x00000000u;
goto P_0c036318;
P_0c036318: /* original 4f26, guest PC 0x0c036318 */
if(!s->budget--) { s->failed_pc=0x0c036318u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03631a;
P_0c03631a: /* original 000b, guest PC 0x0c03631a */
if(!s->budget--) { s->failed_pc=0x0c03631au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03631c: /* original 0009, guest PC 0x0c03631c */
if(!s->budget--) { s->failed_pc=0x0c03631cu; return 0; }
goto P_0c03631e;
P_0c03631e: /* original d235, guest PC 0x0c03631e */
if(!s->budget--) { s->failed_pc=0x0c03631eu; return 0; }
r[2]=read(ram,0x0c0363f4u,4);
goto P_0c036320;
P_0c036320: /* original e101, guest PC 0x0c036320 */
if(!s->budget--) { s->failed_pc=0x0c036320u; return 0; }
r[1]=0x00000001u;
goto P_0c036322;
P_0c036322: /* original 905d, guest PC 0x0c036322 */
if(!s->budget--) { s->failed_pc=0x0c036322u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0363e0u,2);
goto P_0c036324;
P_0c036324: /* original 6322, guest PC 0x0c036324 */
if(!s->budget--) { s->failed_pc=0x0c036324u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c036326;
P_0c036326: /* original e200, guest PC 0x0c036326 */
if(!s->budget--) { s->failed_pc=0x0c036326u; return 0; }
r[2]=0x00000000u;
goto P_0c036328;
P_0c036328: /* original 0316, guest PC 0x0c036328 */
if(!s->budget--) { s->failed_pc=0x0c036328u; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c03632a;
P_0c03632a: /* original d130, guest PC 0x0c03632a */
if(!s->budget--) { s->failed_pc=0x0c03632au; return 0; }
r[1]=read(ram,0x0c0363ecu,4);
goto P_0c03632c;
P_0c03632c: /* original 6312, guest PC 0x0c03632c */
if(!s->budget--) { s->failed_pc=0x0c03632cu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c03632e;
P_0c03632e: /* original 2320, guest PC 0x0c03632e */
if(!s->budget--) { s->failed_pc=0x0c03632eu; return 0; }
write(ram,r[3],r[2],1);
goto P_0c036330;
P_0c036330: /* original 000b, guest PC 0x0c036330 */
if(!s->budget--) { s->failed_pc=0x0c036330u; return 0; }
target=r[16];
r[0]=r[2];
s->pc=target; return ram->oob==0;
P_0c036332: /* original 6023, guest PC 0x0c036332 */
if(!s->budget--) { s->failed_pc=0x0c036332u; return 0; }
r[0]=r[2];
goto P_0c036334;
P_0c036334: /* original d22f, guest PC 0x0c036334 */
if(!s->budget--) { s->failed_pc=0x0c036334u; return 0; }
r[2]=read(ram,0x0c0363f4u,4);
goto P_0c036336;
P_0c036336: /* original 9054, guest PC 0x0c036336 */
if(!s->budget--) { s->failed_pc=0x0c036336u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0363e2u,2);
goto P_0c036338;
P_0c036338: /* original 6322, guest PC 0x0c036338 */
if(!s->budget--) { s->failed_pc=0x0c036338u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03633a;
P_0c03633a: /* original 013e, guest PC 0x0c03633a */
if(!s->budget--) { s->failed_pc=0x0c03633au; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c03633c;
P_0c03633c: /* original 2118, guest PC 0x0c03633c */
if(!s->budget--) { s->failed_pc=0x0c03633cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c03633e;
P_0c03633e: /* original 8901, guest PC 0x0c03633e */
if(!s->budget--) { s->failed_pc=0x0c03633eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036344; }
goto P_0c036340;
P_0c036340: /* original a041, guest PC 0x0c036340 */
if(!s->budget--) { s->failed_pc=0x0c036340u; return 0; }
goto P_0c0363c6;
P_0c036342: /* original 0009, guest PC 0x0c036342 */
if(!s->budget--) { s->failed_pc=0x0c036342u; return 0; }
goto P_0c036344;
P_0c036344: /* original 2fe6, guest PC 0x0c036344 */
if(!s->budget--) { s->failed_pc=0x0c036344u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036346;
P_0c036346: /* original 2fd6, guest PC 0x0c036346 */
if(!s->budget--) { s->failed_pc=0x0c036346u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036348;
P_0c036348: /* original 2fc6, guest PC 0x0c036348 */
if(!s->budget--) { s->failed_pc=0x0c036348u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03634a;
P_0c03634a: /* original 2fb6, guest PC 0x0c03634a */
if(!s->budget--) { s->failed_pc=0x0c03634au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03634c;
P_0c03634c: /* original 2fa6, guest PC 0x0c03634c */
if(!s->budget--) { s->failed_pc=0x0c03634cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03634e;
P_0c03634e: /* original 2f96, guest PC 0x0c03634e */
if(!s->budget--) { s->failed_pc=0x0c03634eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036350;
P_0c036350: /* original e906, guest PC 0x0c036350 */
if(!s->budget--) { s->failed_pc=0x0c036350u; return 0; }
r[9]=0x00000006u;
goto P_0c036352;
P_0c036352: /* original 2f86, guest PC 0x0c036352 */
if(!s->budget--) { s->failed_pc=0x0c036352u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036354;
P_0c036354: /* original e800, guest PC 0x0c036354 */
if(!s->budget--) { s->failed_pc=0x0c036354u; return 0; }
r[8]=0x00000000u;
goto P_0c036356;
P_0c036356: /* original 4f22, guest PC 0x0c036356 */
if(!s->budget--) { s->failed_pc=0x0c036356u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c036358;
P_0c036358: /* original da26, guest PC 0x0c036358 */
if(!s->budget--) { s->failed_pc=0x0c036358u; return 0; }
r[10]=read(ram,0x0c0363f4u,4);
goto P_0c03635a;
P_0c03635a: /* original a027, guest PC 0x0c03635a */
if(!s->budget--) { s->failed_pc=0x0c03635au; return 0; }
r[14]=r[8];
goto P_0c0363ac;
P_0c03635c: /* original 6e83, guest PC 0x0c03635c */
if(!s->budget--) { s->failed_pc=0x0c03635cu; return 0; }
r[14]=r[8];
goto P_0c03635e;
P_0c03635e: /* original d026, guest PC 0x0c03635e */
if(!s->budget--) { s->failed_pc=0x0c03635eu; return 0; }
r[0]=read(ram,0x0c0363f8u,4);
goto P_0c036360;
P_0c036360: /* original 63e3, guest PC 0x0c036360 */
if(!s->budget--) { s->failed_pc=0x0c036360u; return 0; }
r[3]=r[14];
goto P_0c036362;
P_0c036362: /* original 4308, guest PC 0x0c036362 */
if(!s->budget--) { s->failed_pc=0x0c036362u; return 0; }
r[3]<<=2;
goto P_0c036364;
P_0c036364: /* original 913e, guest PC 0x0c036364 */
if(!s->budget--) { s->failed_pc=0x0c036364u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0363e4u,2);
goto P_0c036366;
P_0c036366: /* original 023e, guest PC 0x0c036366 */
if(!s->budget--) { s->failed_pc=0x0c036366u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c036368;
P_0c036368: /* original 60a2, guest PC 0x0c036368 */
if(!s->budget--) { s->failed_pc=0x0c036368u; return 0; }
tmp=read(ram,r[10],4);
r[0]=tmp;
goto P_0c03636a;
P_0c03636a: /* original 310c, guest PC 0x0c03636a */
if(!s->budget--) { s->failed_pc=0x0c03636au; return 0; }
r[1]+=r[0];
goto P_0c03636c;
P_0c03636c: /* original 321c, guest PC 0x0c03636c */
if(!s->budget--) { s->failed_pc=0x0c03636cu; return 0; }
r[2]+=r[1];
goto P_0c03636e;
P_0c03636e: /* original 6320, guest PC 0x0c03636e */
if(!s->budget--) { s->failed_pc=0x0c03636eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c036370;
P_0c036370: /* original 2338, guest PC 0x0c036370 */
if(!s->budget--) { s->failed_pc=0x0c036370u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c036372;
P_0c036372: /* original 891a, guest PC 0x0c036372 */
if(!s->budget--) { s->failed_pc=0x0c036372u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0363aa; }
goto P_0c036374;
P_0c036374: /* original d221, guest PC 0x0c036374 */
if(!s->budget--) { s->failed_pc=0x0c036374u; return 0; }
r[2]=read(ram,0x0c0363fcu,4);
goto P_0c036376;
P_0c036376: /* original 420b, guest PC 0x0c036376 */
if(!s->budget--) { s->failed_pc=0x0c036376u; return 0; }
target=r[2];
r[16]=code_base|0x0c03637au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03637au) { target=s->pc; goto dispatch; }
goto P_0c03637a;
P_0c036378: /* original 64e3, guest PC 0x0c036378 */
if(!s->budget--) { s->failed_pc=0x0c036378u; return 0; }
r[4]=r[14];
goto P_0c03637a;
P_0c03637a: /* original 63e3, guest PC 0x0c03637a */
if(!s->budget--) { s->failed_pc=0x0c03637au; return 0; }
r[3]=r[14];
goto P_0c03637c;
P_0c03637c: /* original 64e3, guest PC 0x0c03637c */
if(!s->budget--) { s->failed_pc=0x0c03637cu; return 0; }
r[4]=r[14];
goto P_0c03637e;
P_0c03637e: /* original 4308, guest PC 0x0c03637e */
if(!s->budget--) { s->failed_pc=0x0c03637eu; return 0; }
r[3]<<=2;
goto P_0c036380;
P_0c036380: /* original 6b83, guest PC 0x0c036380 */
if(!s->budget--) { s->failed_pc=0x0c036380u; return 0; }
r[11]=r[8];
goto P_0c036382;
P_0c036382: /* original 4400, guest PC 0x0c036382 */
if(!s->budget--) { s->failed_pc=0x0c036382u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c036384;
P_0c036384: /* original 343c, guest PC 0x0c036384 */
if(!s->budget--) { s->failed_pc=0x0c036384u; return 0; }
r[4]+=r[3];
goto P_0c036386;
P_0c036386: /* original 6c43, guest PC 0x0c036386 */
if(!s->budget--) { s->failed_pc=0x0c036386u; return 0; }
r[12]=r[4];
goto P_0c036388;
P_0c036388: /* original 6d43, guest PC 0x0c036388 */
if(!s->budget--) { s->failed_pc=0x0c036388u; return 0; }
r[13]=r[4];
goto P_0c03638a;
P_0c03638a: /* original 932b, guest PC 0x0c03638a */
if(!s->budget--) { s->failed_pc=0x0c03638au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0363e4u,2);
goto P_0c03638c;
P_0c03638c: /* original 60a2, guest PC 0x0c03638c */
if(!s->budget--) { s->failed_pc=0x0c03638cu; return 0; }
tmp=read(ram,r[10],4);
r[0]=tmp;
goto P_0c03638e;
P_0c03638e: /* original 330c, guest PC 0x0c03638e */
if(!s->budget--) { s->failed_pc=0x0c03638eu; return 0; }
r[3]+=r[0];
goto P_0c036390;
P_0c036390: /* original 33cc, guest PC 0x0c036390 */
if(!s->budget--) { s->failed_pc=0x0c036390u; return 0; }
r[3]+=r[12];
goto P_0c036392;
P_0c036392: /* original 6230, guest PC 0x0c036392 */
if(!s->budget--) { s->failed_pc=0x0c036392u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c036394;
P_0c036394: /* original 2228, guest PC 0x0c036394 */
if(!s->budget--) { s->failed_pc=0x0c036394u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c036396;
P_0c036396: /* original 8903, guest PC 0x0c036396 */
if(!s->budget--) { s->failed_pc=0x0c036396u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0363a0; }
goto P_0c036398;
P_0c036398: /* original d319, guest PC 0x0c036398 */
if(!s->budget--) { s->failed_pc=0x0c036398u; return 0; }
r[3]=read(ram,0x0c036400u,4);
goto P_0c03639a;
P_0c03639a: /* original 65e3, guest PC 0x0c03639a */
if(!s->budget--) { s->failed_pc=0x0c03639au; return 0; }
r[5]=r[14];
goto P_0c03639c;
P_0c03639c: /* original 430b, guest PC 0x0c03639c */
if(!s->budget--) { s->failed_pc=0x0c03639cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0363a0u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0363a0u) { target=s->pc; goto dispatch; }
goto P_0c0363a0;
P_0c03639e: /* original 64d3, guest PC 0x0c03639e */
if(!s->budget--) { s->failed_pc=0x0c03639eu; return 0; }
r[4]=r[13];
goto P_0c0363a0;
P_0c0363a0: /* original 7b01, guest PC 0x0c0363a0 */
if(!s->budget--) { s->failed_pc=0x0c0363a0u; return 0; }
r[11]+=0x00000001u;
goto P_0c0363a2;
P_0c0363a2: /* original 3b93, guest PC 0x0c0363a2 */
if(!s->budget--) { s->failed_pc=0x0c0363a2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[9])!=0);
goto P_0c0363a4;
P_0c0363a4: /* original 7d01, guest PC 0x0c0363a4 */
if(!s->budget--) { s->failed_pc=0x0c0363a4u; return 0; }
r[13]+=0x00000001u;
goto P_0c0363a6;
P_0c0363a6: /* original 8ff0, guest PC 0x0c0363a6 */
if(!s->budget--) { s->failed_pc=0x0c0363a6u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(!cond) { goto P_0c03638a; }
goto P_0c0363aa;
P_0c0363a8: /* original 7c01, guest PC 0x0c0363a8 */
if(!s->budget--) { s->failed_pc=0x0c0363a8u; return 0; }
r[12]+=0x00000001u;
goto P_0c0363aa;
P_0c0363aa: /* original 7e01, guest PC 0x0c0363aa */
if(!s->budget--) { s->failed_pc=0x0c0363aau; return 0; }
r[14]+=0x00000001u;
goto P_0c0363ac;
P_0c0363ac: /* original e304, guest PC 0x0c0363ac */
if(!s->budget--) { s->failed_pc=0x0c0363acu; return 0; }
r[3]=0x00000004u;
goto P_0c0363ae;
P_0c0363ae: /* original 3e33, guest PC 0x0c0363ae */
if(!s->budget--) { s->failed_pc=0x0c0363aeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c0363b0;
P_0c0363b0: /* original 8bd5, guest PC 0x0c0363b0 */
if(!s->budget--) { s->failed_pc=0x0c0363b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03635e; }
goto P_0c0363b2;
P_0c0363b2: /* original 4f26, guest PC 0x0c0363b2 */
if(!s->budget--) { s->failed_pc=0x0c0363b2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0363b4;
P_0c0363b4: /* original e000, guest PC 0x0c0363b4 */
if(!s->budget--) { s->failed_pc=0x0c0363b4u; return 0; }
r[0]=0x00000000u;
goto P_0c0363b6;
P_0c0363b6: /* original 68f6, guest PC 0x0c0363b6 */
if(!s->budget--) { s->failed_pc=0x0c0363b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0363b8;
P_0c0363b8: /* original 69f6, guest PC 0x0c0363b8 */
if(!s->budget--) { s->failed_pc=0x0c0363b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0363ba;
P_0c0363ba: /* original 6af6, guest PC 0x0c0363ba */
if(!s->budget--) { s->failed_pc=0x0c0363bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0363bc;
P_0c0363bc: /* original 6bf6, guest PC 0x0c0363bc */
if(!s->budget--) { s->failed_pc=0x0c0363bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0363be;
P_0c0363be: /* original 6cf6, guest PC 0x0c0363be */
if(!s->budget--) { s->failed_pc=0x0c0363beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0363c0;
P_0c0363c0: /* original 6df6, guest PC 0x0c0363c0 */
if(!s->budget--) { s->failed_pc=0x0c0363c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0363c2;
P_0c0363c2: /* original 000b, guest PC 0x0c0363c2 */
if(!s->budget--) { s->failed_pc=0x0c0363c2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0363c4: /* original 6ef6, guest PC 0x0c0363c4 */
if(!s->budget--) { s->failed_pc=0x0c0363c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0363c6;
P_0c0363c6: /* original 2fe6, guest PC 0x0c0363c6 */
if(!s->budget--) { s->failed_pc=0x0c0363c6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0363c8;
P_0c0363c8: /* original 2fd6, guest PC 0x0c0363c8 */
if(!s->budget--) { s->failed_pc=0x0c0363c8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0363ca;
P_0c0363ca: /* original 2fc6, guest PC 0x0c0363ca */
if(!s->budget--) { s->failed_pc=0x0c0363cau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0363cc;
P_0c0363cc: /* original 2fb6, guest PC 0x0c0363cc */
if(!s->budget--) { s->failed_pc=0x0c0363ccu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0363ce;
P_0c0363ce: /* original 2fa6, guest PC 0x0c0363ce */
if(!s->budget--) { s->failed_pc=0x0c0363ceu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0363d0;
P_0c0363d0: /* original 2f96, guest PC 0x0c0363d0 */
if(!s->budget--) { s->failed_pc=0x0c0363d0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0363d2;
P_0c0363d2: /* original e906, guest PC 0x0c0363d2 */
if(!s->budget--) { s->failed_pc=0x0c0363d2u; return 0; }
r[9]=0x00000006u;
goto P_0c0363d4;
P_0c0363d4: /* original 2f86, guest PC 0x0c0363d4 */
if(!s->budget--) { s->failed_pc=0x0c0363d4u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0363d6;
P_0c0363d6: /* original e801, guest PC 0x0c0363d6 */
if(!s->budget--) { s->failed_pc=0x0c0363d6u; return 0; }
r[8]=0x00000001u;
goto P_0c0363d8;
P_0c0363d8: /* original 4f22, guest PC 0x0c0363d8 */
if(!s->budget--) { s->failed_pc=0x0c0363d8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0363da;
P_0c0363da: /* original db06, guest PC 0x0c0363da */
if(!s->budget--) { s->failed_pc=0x0c0363dau; return 0; }
r[11]=read(ram,0x0c0363f4u,4);
goto P_0c0363dc;
P_0c0363dc: /* original a055, guest PC 0x0c0363dc */
if(!s->budget--) { s->failed_pc=0x0c0363dcu; return 0; }
r[14]=0x00000000u;
goto P_0c03648a;
P_0c0363de: /* original ee00, guest PC 0x0c0363de */
if(!s->budget--) { s->failed_pc=0x0c0363deu; return 0; }
r[14]=0x00000000u;
if(!vf3_matrix_family(0x0c0363e0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0363e0u; return 0; } return 1;
P_0c036404: /* original d035, guest PC 0x0c036404 */
if(!s->budget--) { s->failed_pc=0x0c036404u; return 0; }
r[0]=read(ram,0x0c0364dcu,4);
goto P_0c036406;
P_0c036406: /* original 62e3, guest PC 0x0c036406 */
if(!s->budget--) { s->failed_pc=0x0c036406u; return 0; }
r[2]=r[14];
goto P_0c036408;
P_0c036408: /* original 9166, guest PC 0x0c036408 */
if(!s->budget--) { s->failed_pc=0x0c036408u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0364d8u,2);
goto P_0c03640a;
P_0c03640a: /* original 4208, guest PC 0x0c03640a */
if(!s->budget--) { s->failed_pc=0x0c03640au; return 0; }
r[2]<<=2;
goto P_0c03640c;
P_0c03640c: /* original 6db2, guest PC 0x0c03640c */
if(!s->budget--) { s->failed_pc=0x0c03640cu; return 0; }
tmp=read(ram,r[11],4);
r[13]=tmp;
goto P_0c03640e;
P_0c03640e: /* original 032e, guest PC 0x0c03640e */
if(!s->budget--) { s->failed_pc=0x0c03640eu; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c036410;
P_0c036410: /* original 31dc, guest PC 0x0c036410 */
if(!s->budget--) { s->failed_pc=0x0c036410u; return 0; }
r[1]+=r[13];
goto P_0c036412;
P_0c036412: /* original 331c, guest PC 0x0c036412 */
if(!s->budget--) { s->failed_pc=0x0c036412u; return 0; }
r[3]+=r[1];
goto P_0c036414;
P_0c036414: /* original 6230, guest PC 0x0c036414 */
if(!s->budget--) { s->failed_pc=0x0c036414u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c036416;
P_0c036416: /* original 2228, guest PC 0x0c036416 */
if(!s->budget--) { s->failed_pc=0x0c036416u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c036418;
P_0c036418: /* original 8936, guest PC 0x0c036418 */
if(!s->budget--) { s->failed_pc=0x0c036418u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036488; }
goto P_0c03641a;
P_0c03641a: /* original 935e, guest PC 0x0c03641a */
if(!s->budget--) { s->failed_pc=0x0c03641au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0364dau,2);
goto P_0c03641c;
P_0c03641c: /* original 6083, guest PC 0x0c03641c */
if(!s->budget--) { s->failed_pc=0x0c03641cu; return 0; }
r[0]=r[8];
goto P_0c03641e;
P_0c03641e: /* original 40ec, guest PC 0x0c03641e */
if(!s->budget--) { s->failed_pc=0x0c03641eu; return 0; }
r[0]=(r[14]&0x80000000u)?((r[14]&31u)?(uint32_t)((int32_t)r[0]>>((-r[14])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[14]&31u);
goto P_0c036420;
P_0c036420: /* original 33dc, guest PC 0x0c036420 */
if(!s->budget--) { s->failed_pc=0x0c036420u; return 0; }
r[3]+=r[13];
goto P_0c036422;
P_0c036422: /* original 6332, guest PC 0x0c036422 */
if(!s->budget--) { s->failed_pc=0x0c036422u; return 0; }
tmp=read(ram,r[3],4);
r[3]=tmp;
goto P_0c036424;
P_0c036424: /* original 2038, guest PC 0x0c036424 */
if(!s->budget--) { s->failed_pc=0x0c036424u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[3])==0)!=0);
goto P_0c036426;
P_0c036426: /* original 890c, guest PC 0x0c036426 */
if(!s->budget--) { s->failed_pc=0x0c036426u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036442; }
goto P_0c036428;
P_0c036428: /* original 2fe6, guest PC 0x0c036428 */
if(!s->budget--) { s->failed_pc=0x0c036428u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03642a;
P_0c03642a: /* original 9056, guest PC 0x0c03642a */
if(!s->budget--) { s->failed_pc=0x0c03642au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0364dau,2);
goto P_0c03642c;
P_0c03642c: /* original 03de, guest PC 0x0c03642c */
if(!s->budget--) { s->failed_pc=0x0c03642cu; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c03642e;
P_0c03642e: /* original 2f36, guest PC 0x0c03642e */
if(!s->budget--) { s->failed_pc=0x0c03642eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036430;
P_0c036430: /* original d22b, guest PC 0x0c036430 */
if(!s->budget--) { s->failed_pc=0x0c036430u; return 0; }
r[2]=read(ram,0x0c0364e0u,4);
goto P_0c036432;
P_0c036432: /* original b0ab, guest PC 0x0c036432 */
if(!s->budget--) { s->failed_pc=0x0c036432u; return 0; }
target=code_base|0x0c03658cu; r[16]=code_base|0x0c036436u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036436u) { target=s->pc; goto dispatch; }
goto P_0c036436;
P_0c036434: /* original 2f26, guest PC 0x0c036434 */
if(!s->budget--) { s->failed_pc=0x0c036434u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036436;
P_0c036436: /* original d22b, guest PC 0x0c036436 */
if(!s->budget--) { s->failed_pc=0x0c036436u; return 0; }
r[2]=read(ram,0x0c0364e4u,4);
goto P_0c036438;
P_0c036438: /* original 7f0c, guest PC 0x0c036438 */
if(!s->budget--) { s->failed_pc=0x0c036438u; return 0; }
r[15]+=0x0000000cu;
goto P_0c03643a;
P_0c03643a: /* original 420b, guest PC 0x0c03643a */
if(!s->budget--) { s->failed_pc=0x0c03643au; return 0; }
target=r[2];
r[16]=code_base|0x0c03643eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03643eu) { target=s->pc; goto dispatch; }
goto P_0c03643e;
P_0c03643c: /* original 64e3, guest PC 0x0c03643c */
if(!s->budget--) { s->failed_pc=0x0c03643cu; return 0; }
r[4]=r[14];
goto P_0c03643e;
P_0c03643e: /* original a00b, guest PC 0x0c03643e */
if(!s->budget--) { s->failed_pc=0x0c03643eu; return 0; }
goto P_0c036458;
P_0c036440: /* original 0009, guest PC 0x0c036440 */
if(!s->budget--) { s->failed_pc=0x0c036440u; return 0; }
goto P_0c036442;
P_0c036442: /* original 2fe6, guest PC 0x0c036442 */
if(!s->budget--) { s->failed_pc=0x0c036442u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036444;
P_0c036444: /* original 9049, guest PC 0x0c036444 */
if(!s->budget--) { s->failed_pc=0x0c036444u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0364dau,2);
goto P_0c036446;
P_0c036446: /* original 02de, guest PC 0x0c036446 */
if(!s->budget--) { s->failed_pc=0x0c036446u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c036448;
P_0c036448: /* original 2f26, guest PC 0x0c036448 */
if(!s->budget--) { s->failed_pc=0x0c036448u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03644a;
P_0c03644a: /* original d327, guest PC 0x0c03644a */
if(!s->budget--) { s->failed_pc=0x0c03644au; return 0; }
r[3]=read(ram,0x0c0364e8u,4);
goto P_0c03644c;
P_0c03644c: /* original b09e, guest PC 0x0c03644c */
if(!s->budget--) { s->failed_pc=0x0c03644cu; return 0; }
target=code_base|0x0c03658cu; r[16]=code_base|0x0c036450u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036450u) { target=s->pc; goto dispatch; }
goto P_0c036450;
P_0c03644e: /* original 2f36, guest PC 0x0c03644e */
if(!s->budget--) { s->failed_pc=0x0c03644eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036450;
P_0c036450: /* original d326, guest PC 0x0c036450 */
if(!s->budget--) { s->failed_pc=0x0c036450u; return 0; }
r[3]=read(ram,0x0c0364ecu,4);
goto P_0c036452;
P_0c036452: /* original 7f0c, guest PC 0x0c036452 */
if(!s->budget--) { s->failed_pc=0x0c036452u; return 0; }
r[15]+=0x0000000cu;
goto P_0c036454;
P_0c036454: /* original 430b, guest PC 0x0c036454 */
if(!s->budget--) { s->failed_pc=0x0c036454u; return 0; }
target=r[3];
r[16]=code_base|0x0c036458u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036458u) { target=s->pc; goto dispatch; }
goto P_0c036458;
P_0c036456: /* original 64e3, guest PC 0x0c036456 */
if(!s->budget--) { s->failed_pc=0x0c036456u; return 0; }
r[4]=r[14];
goto P_0c036458;
P_0c036458: /* original 63e3, guest PC 0x0c036458 */
if(!s->budget--) { s->failed_pc=0x0c036458u; return 0; }
r[3]=r[14];
goto P_0c03645a;
P_0c03645a: /* original 64e3, guest PC 0x0c03645a */
if(!s->budget--) { s->failed_pc=0x0c03645au; return 0; }
r[4]=r[14];
goto P_0c03645c;
P_0c03645c: /* original 4308, guest PC 0x0c03645c */
if(!s->budget--) { s->failed_pc=0x0c03645cu; return 0; }
r[3]<<=2;
goto P_0c03645e;
P_0c03645e: /* original 4400, guest PC 0x0c03645e */
if(!s->budget--) { s->failed_pc=0x0c03645eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c036460;
P_0c036460: /* original 343c, guest PC 0x0c036460 */
if(!s->budget--) { s->failed_pc=0x0c036460u; return 0; }
r[4]+=r[3];
goto P_0c036462;
P_0c036462: /* original 6d43, guest PC 0x0c036462 */
if(!s->budget--) { s->failed_pc=0x0c036462u; return 0; }
r[13]=r[4];
goto P_0c036464;
P_0c036464: /* original 6c43, guest PC 0x0c036464 */
if(!s->budget--) { s->failed_pc=0x0c036464u; return 0; }
r[12]=r[4];
goto P_0c036466;
P_0c036466: /* original ea00, guest PC 0x0c036466 */
if(!s->budget--) { s->failed_pc=0x0c036466u; return 0; }
r[10]=0x00000000u;
goto P_0c036468;
P_0c036468: /* original 9336, guest PC 0x0c036468 */
if(!s->budget--) { s->failed_pc=0x0c036468u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0364d8u,2);
goto P_0c03646a;
P_0c03646a: /* original 60b2, guest PC 0x0c03646a */
if(!s->budget--) { s->failed_pc=0x0c03646au; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c03646c;
P_0c03646c: /* original 330c, guest PC 0x0c03646c */
if(!s->budget--) { s->failed_pc=0x0c03646cu; return 0; }
r[3]+=r[0];
goto P_0c03646e;
P_0c03646e: /* original 33dc, guest PC 0x0c03646e */
if(!s->budget--) { s->failed_pc=0x0c03646eu; return 0; }
r[3]+=r[13];
goto P_0c036470;
P_0c036470: /* original 6230, guest PC 0x0c036470 */
if(!s->budget--) { s->failed_pc=0x0c036470u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c036472;
P_0c036472: /* original 2228, guest PC 0x0c036472 */
if(!s->budget--) { s->failed_pc=0x0c036472u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c036474;
P_0c036474: /* original 8903, guest PC 0x0c036474 */
if(!s->budget--) { s->failed_pc=0x0c036474u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03647e; }
goto P_0c036476;
P_0c036476: /* original d31e, guest PC 0x0c036476 */
if(!s->budget--) { s->failed_pc=0x0c036476u; return 0; }
r[3]=read(ram,0x0c0364f0u,4);
goto P_0c036478;
P_0c036478: /* original 65e3, guest PC 0x0c036478 */
if(!s->budget--) { s->failed_pc=0x0c036478u; return 0; }
r[5]=r[14];
goto P_0c03647a;
P_0c03647a: /* original 430b, guest PC 0x0c03647a */
if(!s->budget--) { s->failed_pc=0x0c03647au; return 0; }
target=r[3];
r[16]=code_base|0x0c03647eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03647eu) { target=s->pc; goto dispatch; }
goto P_0c03647e;
P_0c03647c: /* original 64c3, guest PC 0x0c03647c */
if(!s->budget--) { s->failed_pc=0x0c03647cu; return 0; }
r[4]=r[12];
goto P_0c03647e;
P_0c03647e: /* original 7a01, guest PC 0x0c03647e */
if(!s->budget--) { s->failed_pc=0x0c03647eu; return 0; }
r[10]+=0x00000001u;
goto P_0c036480;
P_0c036480: /* original 3a93, guest PC 0x0c036480 */
if(!s->budget--) { s->failed_pc=0x0c036480u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[9])!=0);
goto P_0c036482;
P_0c036482: /* original 7c01, guest PC 0x0c036482 */
if(!s->budget--) { s->failed_pc=0x0c036482u; return 0; }
r[12]+=0x00000001u;
goto P_0c036484;
P_0c036484: /* original 8ff0, guest PC 0x0c036484 */
if(!s->budget--) { s->failed_pc=0x0c036484u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000001u;
if(!cond) { goto P_0c036468; }
goto P_0c036488;
P_0c036486: /* original 7d01, guest PC 0x0c036486 */
if(!s->budget--) { s->failed_pc=0x0c036486u; return 0; }
r[13]+=0x00000001u;
goto P_0c036488;
P_0c036488: /* original 7e01, guest PC 0x0c036488 */
if(!s->budget--) { s->failed_pc=0x0c036488u; return 0; }
r[14]+=0x00000001u;
goto P_0c03648a;
P_0c03648a: /* original e304, guest PC 0x0c03648a */
if(!s->budget--) { s->failed_pc=0x0c03648au; return 0; }
r[3]=0x00000004u;
goto P_0c03648c;
P_0c03648c: /* original 3e33, guest PC 0x0c03648c */
if(!s->budget--) { s->failed_pc=0x0c03648cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c03648e;
P_0c03648e: /* original 8bb9, guest PC 0x0c03648e */
if(!s->budget--) { s->failed_pc=0x0c03648eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c036404; }
goto P_0c036490;
P_0c036490: /* original 4f26, guest PC 0x0c036490 */
if(!s->budget--) { s->failed_pc=0x0c036490u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c036492;
P_0c036492: /* original d418, guest PC 0x0c036492 */
if(!s->budget--) { s->failed_pc=0x0c036492u; return 0; }
r[4]=read(ram,0x0c0364f4u,4);
goto P_0c036494;
P_0c036494: /* original 2482, guest PC 0x0c036494 */
if(!s->budget--) { s->failed_pc=0x0c036494u; return 0; }
write(ram,r[4],r[8],4);
goto P_0c036496;
P_0c036496: /* original 63b2, guest PC 0x0c036496 */
if(!s->budget--) { s->failed_pc=0x0c036496u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c036498;
P_0c036498: /* original 901f, guest PC 0x0c036498 */
if(!s->budget--) { s->failed_pc=0x0c036498u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0364dau,2);
goto P_0c03649a;
P_0c03649a: /* original 023e, guest PC 0x0c03649a */
if(!s->budget--) { s->failed_pc=0x0c03649au; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c03649c;
P_0c03649c: /* original 7004, guest PC 0x0c03649c */
if(!s->budget--) { s->failed_pc=0x0c03649cu; return 0; }
r[0]+=0x00000004u;
goto P_0c03649e;
P_0c03649e: /* original 1421, guest PC 0x0c03649e */
if(!s->budget--) { s->failed_pc=0x0c03649eu; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c0364a0;
P_0c0364a0: /* original 63b2, guest PC 0x0c0364a0 */
if(!s->budget--) { s->failed_pc=0x0c0364a0u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c0364a2;
P_0c0364a2: /* original 023e, guest PC 0x0c0364a2 */
if(!s->budget--) { s->failed_pc=0x0c0364a2u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0364a4;
P_0c0364a4: /* original e000, guest PC 0x0c0364a4 */
if(!s->budget--) { s->failed_pc=0x0c0364a4u; return 0; }
r[0]=0x00000000u;
goto P_0c0364a6;
P_0c0364a6: /* original 1422, guest PC 0x0c0364a6 */
if(!s->budget--) { s->failed_pc=0x0c0364a6u; return 0; }
write(ram,r[4]+8,r[2],4);
goto P_0c0364a8;
P_0c0364a8: /* original 68f6, guest PC 0x0c0364a8 */
if(!s->budget--) { s->failed_pc=0x0c0364a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0364aa;
P_0c0364aa: /* original 69f6, guest PC 0x0c0364aa */
if(!s->budget--) { s->failed_pc=0x0c0364aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0364ac;
P_0c0364ac: /* original 6af6, guest PC 0x0c0364ac */
if(!s->budget--) { s->failed_pc=0x0c0364acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0364ae;
P_0c0364ae: /* original 6bf6, guest PC 0x0c0364ae */
if(!s->budget--) { s->failed_pc=0x0c0364aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0364b0;
P_0c0364b0: /* original 6cf6, guest PC 0x0c0364b0 */
if(!s->budget--) { s->failed_pc=0x0c0364b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0364b2;
P_0c0364b2: /* original 6df6, guest PC 0x0c0364b2 */
if(!s->budget--) { s->failed_pc=0x0c0364b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0364b4;
P_0c0364b4: /* original 000b, guest PC 0x0c0364b4 */
if(!s->budget--) { s->failed_pc=0x0c0364b4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0364b6: /* original 6ef6, guest PC 0x0c0364b6 */
if(!s->budget--) { s->failed_pc=0x0c0364b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0364b8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0364b8u; return 0; } return 1;
P_0c03658c: /* original 2fe6, guest PC 0x0c03658c */
if(!s->budget--) { s->failed_pc=0x0c03658cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03658e;
P_0c03658e: /* original d22d, guest PC 0x0c03658e */
if(!s->budget--) { s->failed_pc=0x0c03658eu; return 0; }
r[2]=read(ram,0x0c036644u,4);
goto P_0c036590;
P_0c036590: /* original 904f, guest PC 0x0c036590 */
if(!s->budget--) { s->failed_pc=0x0c036590u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036632u,2);
goto P_0c036592;
P_0c036592: /* original 6322, guest PC 0x0c036592 */
if(!s->budget--) { s->failed_pc=0x0c036592u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c036594;
P_0c036594: /* original 4f22, guest PC 0x0c036594 */
if(!s->budget--) { s->failed_pc=0x0c036594u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c036596;
P_0c036596: /* original 013e, guest PC 0x0c036596 */
if(!s->budget--) { s->failed_pc=0x0c036596u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c036598;
P_0c036598: /* original 2118, guest PC 0x0c036598 */
if(!s->budget--) { s->failed_pc=0x0c036598u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c03659a;
P_0c03659a: /* original 8918, guest PC 0x0c03659a */
if(!s->budget--) { s->failed_pc=0x0c03659au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0365ce; }
goto P_0c03659c;
P_0c03659c: /* original 60f3, guest PC 0x0c03659c */
if(!s->budget--) { s->failed_pc=0x0c03659cu; return 0; }
r[0]=r[15];
goto P_0c03659e;
P_0c03659e: /* original 7008, guest PC 0x0c03659e */
if(!s->budget--) { s->failed_pc=0x0c03659eu; return 0; }
r[0]+=0x00000008u;
goto P_0c0365a0;
P_0c0365a0: /* original e503, guest PC 0x0c0365a0 */
if(!s->budget--) { s->failed_pc=0x0c0365a0u; return 0; }
r[5]=0x00000003u;
goto P_0c0365a2;
P_0c0365a2: /* original 7004, guest PC 0x0c0365a2 */
if(!s->budget--) { s->failed_pc=0x0c0365a2u; return 0; }
r[0]+=0x00000004u;
goto P_0c0365a4;
P_0c0365a4: /* original 2508, guest PC 0x0c0365a4 */
if(!s->budget--) { s->failed_pc=0x0c0365a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[0])==0)!=0);
goto P_0c0365a6;
P_0c0365a6: /* original 8903, guest PC 0x0c0365a6 */
if(!s->budget--) { s->failed_pc=0x0c0365a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0365b0; }
goto P_0c0365a8;
P_0c0365a8: /* original 65f3, guest PC 0x0c0365a8 */
if(!s->budget--) { s->failed_pc=0x0c0365a8u; return 0; }
r[5]=r[15];
goto P_0c0365aa;
P_0c0365aa: /* original 7508, guest PC 0x0c0365aa */
if(!s->budget--) { s->failed_pc=0x0c0365aau; return 0; }
r[5]+=0x00000008u;
goto P_0c0365ac;
P_0c0365ac: /* original a003, guest PC 0x0c0365ac */
if(!s->budget--) { s->failed_pc=0x0c0365acu; return 0; }
r[5]+=0x00000008u;
goto P_0c0365b6;
P_0c0365ae: /* original 7508, guest PC 0x0c0365ae */
if(!s->budget--) { s->failed_pc=0x0c0365aeu; return 0; }
r[5]+=0x00000008u;
goto P_0c0365b0;
P_0c0365b0: /* original 65f3, guest PC 0x0c0365b0 */
if(!s->budget--) { s->failed_pc=0x0c0365b0u; return 0; }
r[5]=r[15];
goto P_0c0365b2;
P_0c0365b2: /* original 7508, guest PC 0x0c0365b2 */
if(!s->budget--) { s->failed_pc=0x0c0365b2u; return 0; }
r[5]+=0x00000008u;
goto P_0c0365b4;
P_0c0365b4: /* original 7504, guest PC 0x0c0365b4 */
if(!s->budget--) { s->failed_pc=0x0c0365b4u; return 0; }
r[5]+=0x00000004u;
goto P_0c0365b6;
P_0c0365b6: /* original d325, guest PC 0x0c0365b6 */
if(!s->budget--) { s->failed_pc=0x0c0365b6u; return 0; }
r[3]=read(ram,0x0c03664cu,4);
goto P_0c0365b8;
P_0c0365b8: /* original 6653, guest PC 0x0c0365b8 */
if(!s->budget--) { s->failed_pc=0x0c0365b8u; return 0; }
r[6]=r[5];
goto P_0c0365ba;
P_0c0365ba: /* original d423, guest PC 0x0c0365ba */
if(!s->budget--) { s->failed_pc=0x0c0365bau; return 0; }
r[4]=read(ram,0x0c036648u,4);
goto P_0c0365bc;
P_0c0365bc: /* original 430b, guest PC 0x0c0365bc */
if(!s->budget--) { s->failed_pc=0x0c0365bcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0365c0u;
r[5]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0365c0u) { target=s->pc; goto dispatch; }
goto P_0c0365c0;
P_0c0365be: /* original 55f2, guest PC 0x0c0365be */
if(!s->budget--) { s->failed_pc=0x0c0365beu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0365c0;
P_0c0365c0: /* original d223, guest PC 0x0c0365c0 */
if(!s->budget--) { s->failed_pc=0x0c0365c0u; return 0; }
r[2]=read(ram,0x0c036650u,4);
goto P_0c0365c2;
P_0c0365c2: /* original 6e22, guest PC 0x0c0365c2 */
if(!s->budget--) { s->failed_pc=0x0c0365c2u; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c0365c4;
P_0c0365c4: /* original 2ee8, guest PC 0x0c0365c4 */
if(!s->budget--) { s->failed_pc=0x0c0365c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0365c6;
P_0c0365c6: /* original 8902, guest PC 0x0c0365c6 */
if(!s->budget--) { s->failed_pc=0x0c0365c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0365ce; }
goto P_0c0365c8;
P_0c0365c8: /* original d41f, guest PC 0x0c0365c8 */
if(!s->budget--) { s->failed_pc=0x0c0365c8u; return 0; }
r[4]=read(ram,0x0c036648u,4);
goto P_0c0365ca;
P_0c0365ca: /* original 4e0b, guest PC 0x0c0365ca */
if(!s->budget--) { s->failed_pc=0x0c0365cau; return 0; }
target=r[14];
r[16]=code_base|0x0c0365ceu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0365ceu) { target=s->pc; goto dispatch; }
goto P_0c0365ce;
P_0c0365cc: /* original 0009, guest PC 0x0c0365cc */
if(!s->budget--) { s->failed_pc=0x0c0365ccu; return 0; }
goto P_0c0365ce;
P_0c0365ce: /* original 4f26, guest PC 0x0c0365ce */
if(!s->budget--) { s->failed_pc=0x0c0365ceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0365d0;
P_0c0365d0: /* original 000b, guest PC 0x0c0365d0 */
if(!s->budget--) { s->failed_pc=0x0c0365d0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0365d2: /* original 6ef6, guest PC 0x0c0365d2 */
if(!s->budget--) { s->failed_pc=0x0c0365d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0365d4u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
