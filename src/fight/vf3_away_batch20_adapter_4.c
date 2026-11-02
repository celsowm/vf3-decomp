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
int vf3_away_batch20_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03f2d0u: goto P_0c03f2d0;
case 0x0c03f2d2u: goto P_0c03f2d2;
case 0x0c03f2d4u: goto P_0c03f2d4;
case 0x0c03f2d6u: goto P_0c03f2d6;
case 0x0c03f2d8u: goto P_0c03f2d8;
case 0x0c03f2dau: goto P_0c03f2da;
case 0x0c03f2dcu: goto P_0c03f2dc;
case 0x0c03f2deu: goto P_0c03f2de;
case 0x0c03f2e0u: goto P_0c03f2e0;
case 0x0c03f2e2u: goto P_0c03f2e2;
case 0x0c03f2e4u: goto P_0c03f2e4;
case 0x0c03f2e6u: goto P_0c03f2e6;
case 0x0c03f2e8u: goto P_0c03f2e8;
case 0x0c03f2eau: goto P_0c03f2ea;
case 0x0c03f2ecu: goto P_0c03f2ec;
case 0x0c03f2eeu: goto P_0c03f2ee;
case 0x0c03f2f0u: goto P_0c03f2f0;
case 0x0c03f350u: goto P_0c03f350;
case 0x0c03f352u: goto P_0c03f352;
case 0x0c03f354u: goto P_0c03f354;
case 0x0c03f356u: goto P_0c03f356;
case 0x0c03f358u: goto P_0c03f358;
case 0x0c03f35au: goto P_0c03f35a;
case 0x0c03f35cu: goto P_0c03f35c;
case 0x0c03f35eu: goto P_0c03f35e;
case 0x0c03f360u: goto P_0c03f360;
case 0x0c03f362u: goto P_0c03f362;
case 0x0c03f364u: goto P_0c03f364;
case 0x0c03f366u: goto P_0c03f366;
case 0x0c03f368u: goto P_0c03f368;
case 0x0c03f36au: goto P_0c03f36a;
case 0x0c03f36cu: goto P_0c03f36c;
case 0x0c03f36eu: goto P_0c03f36e;
case 0x0c03f370u: goto P_0c03f370;
case 0x0c03f372u: goto P_0c03f372;
case 0x0c03f374u: goto P_0c03f374;
case 0x0c03f376u: goto P_0c03f376;
case 0x0c03f378u: goto P_0c03f378;
case 0x0c03f37au: goto P_0c03f37a;
case 0x0c03f37cu: goto P_0c03f37c;
case 0x0c03f37eu: goto P_0c03f37e;
case 0x0c03f380u: goto P_0c03f380;
case 0x0c03f390u: goto P_0c03f390;
case 0x0c03f392u: goto P_0c03f392;
case 0x0c03f394u: goto P_0c03f394;
case 0x0c03f396u: goto P_0c03f396;
case 0x0c03f398u: goto P_0c03f398;
case 0x0c03f39au: goto P_0c03f39a;
case 0x0c03f39cu: goto P_0c03f39c;
case 0x0c03f39eu: goto P_0c03f39e;
case 0x0c03f3a0u: goto P_0c03f3a0;
case 0x0c03f3a2u: goto P_0c03f3a2;
case 0x0c03f3b0u: goto P_0c03f3b0;
case 0x0c03f3b2u: goto P_0c03f3b2;
case 0x0c03f3b4u: goto P_0c03f3b4;
case 0x0c03f3b6u: goto P_0c03f3b6;
case 0x0c03f3b8u: goto P_0c03f3b8;
case 0x0c03f3bau: goto P_0c03f3ba;
case 0x0c03f3bcu: goto P_0c03f3bc;
case 0x0c03f3beu: goto P_0c03f3be;
case 0x0c03f3c0u: goto P_0c03f3c0;
case 0x0c03f3c2u: goto P_0c03f3c2;
case 0x0c03f3c4u: goto P_0c03f3c4;
case 0x0c03f3c6u: goto P_0c03f3c6;
case 0x0c03f3c8u: goto P_0c03f3c8;
case 0x0c03f3cau: goto P_0c03f3ca;
case 0x0c03f3ccu: goto P_0c03f3cc;
case 0x0c03f3ceu: goto P_0c03f3ce;
case 0x0c03f3d0u: goto P_0c03f3d0;
case 0x0c03f3d2u: goto P_0c03f3d2;
case 0x0c03f3d4u: goto P_0c03f3d4;
case 0x0c03f3d6u: goto P_0c03f3d6;
case 0x0c03f3d8u: goto P_0c03f3d8;
case 0x0c03f3dau: goto P_0c03f3da;
case 0x0c040f1eu: goto P_0c040f1e;
case 0x0c040f20u: goto P_0c040f20;
case 0x0c040f22u: goto P_0c040f22;
case 0x0c040f24u: goto P_0c040f24;
case 0x0c040f26u: goto P_0c040f26;
case 0x0c040f28u: goto P_0c040f28;
case 0x0c040f2au: goto P_0c040f2a;
case 0x0c040f2cu: goto P_0c040f2c;
case 0x0c040f2eu: goto P_0c040f2e;
case 0x0c040f30u: goto P_0c040f30;
case 0x0c040f32u: goto P_0c040f32;
case 0x0c040f34u: goto P_0c040f34;
case 0x0c040f36u: goto P_0c040f36;
case 0x0c040f38u: goto P_0c040f38;
case 0x0c040f3au: goto P_0c040f3a;
case 0x0c040f3cu: goto P_0c040f3c;
case 0x0c040f3eu: goto P_0c040f3e;
case 0x0c040f40u: goto P_0c040f40;
case 0x0c040f42u: goto P_0c040f42;
case 0x0c040f44u: goto P_0c040f44;
case 0x0c040f46u: goto P_0c040f46;
case 0x0c040f48u: goto P_0c040f48;
case 0x0c040f4au: goto P_0c040f4a;
case 0x0c040f4cu: goto P_0c040f4c;
case 0x0c040f4eu: goto P_0c040f4e;
case 0x0c040f50u: goto P_0c040f50;
case 0x0c040f52u: goto P_0c040f52;
case 0x0c040f54u: goto P_0c040f54;
case 0x0c040f56u: goto P_0c040f56;
case 0x0c040f58u: goto P_0c040f58;
case 0x0c040f5au: goto P_0c040f5a;
case 0x0c040f5cu: goto P_0c040f5c;
case 0x0c040f5eu: goto P_0c040f5e;
case 0x0c040f60u: goto P_0c040f60;
case 0x0c040f62u: goto P_0c040f62;
case 0x0c040f64u: goto P_0c040f64;
case 0x0c040f66u: goto P_0c040f66;
case 0x0c042460u: goto P_0c042460;
case 0x0c042462u: goto P_0c042462;
case 0x0c042464u: goto P_0c042464;
case 0x0c042466u: goto P_0c042466;
case 0x0c042468u: goto P_0c042468;
case 0x0c04246au: goto P_0c04246a;
case 0x0c04246cu: goto P_0c04246c;
case 0x0c04246eu: goto P_0c04246e;
case 0x0c042490u: goto P_0c042490;
case 0x0c042492u: goto P_0c042492;
case 0x0c042494u: goto P_0c042494;
case 0x0c042496u: goto P_0c042496;
case 0x0c042498u: goto P_0c042498;
case 0x0c04249au: goto P_0c04249a;
case 0x0c04249cu: goto P_0c04249c;
case 0x0c04249eu: goto P_0c04249e;
case 0x0c0424a0u: goto P_0c0424a0;
case 0x0c0424a2u: goto P_0c0424a2;
case 0x0c0424a4u: goto P_0c0424a4;
case 0x0c0424a6u: goto P_0c0424a6;
case 0x0c0424a8u: goto P_0c0424a8;
case 0x0c0424aau: goto P_0c0424aa;
case 0x0c0424acu: goto P_0c0424ac;
case 0x0c0424aeu: goto P_0c0424ae;
case 0x0c0424b0u: goto P_0c0424b0;
case 0x0c0424b2u: goto P_0c0424b2;
case 0x0c0424b4u: goto P_0c0424b4;
case 0x0c0424b6u: goto P_0c0424b6;
case 0x0c0424d0u: goto P_0c0424d0;
case 0x0c0424d2u: goto P_0c0424d2;
case 0x0c0424d4u: goto P_0c0424d4;
case 0x0c0424d6u: goto P_0c0424d6;
case 0x0c0424d8u: goto P_0c0424d8;
case 0x0c0424dau: goto P_0c0424da;
case 0x0c0424dcu: goto P_0c0424dc;
case 0x0c0424deu: goto P_0c0424de;
case 0x0c0424e0u: goto P_0c0424e0;
case 0x0c0424e2u: goto P_0c0424e2;
case 0x0c0424e4u: goto P_0c0424e4;
case 0x0c0424e6u: goto P_0c0424e6;
case 0x0c0424e8u: goto P_0c0424e8;
case 0x0c0424eau: goto P_0c0424ea;
case 0x0c0424ecu: goto P_0c0424ec;
case 0x0c0424eeu: goto P_0c0424ee;
case 0x0c0424f0u: goto P_0c0424f0;
case 0x0c0424f2u: goto P_0c0424f2;
case 0x0c0424f4u: goto P_0c0424f4;
case 0x0c0424f6u: goto P_0c0424f6;
case 0x0c0424f8u: goto P_0c0424f8;
case 0x0c0424fau: goto P_0c0424fa;
case 0x0c0424fcu: goto P_0c0424fc;
case 0x0c0424feu: goto P_0c0424fe;
case 0x0c042500u: goto P_0c042500;
case 0x0c042502u: goto P_0c042502;
case 0x0c042504u: goto P_0c042504;
case 0x0c042506u: goto P_0c042506;
case 0x0c042508u: goto P_0c042508;
case 0x0c04250au: goto P_0c04250a;
case 0x0c04250cu: goto P_0c04250c;
case 0x0c04250eu: goto P_0c04250e;
case 0x0c042510u: goto P_0c042510;
case 0x0c042512u: goto P_0c042512;
case 0x0c042514u: goto P_0c042514;
case 0x0c042516u: goto P_0c042516;
case 0x0c042518u: goto P_0c042518;
case 0x0c04251au: goto P_0c04251a;
case 0x0c04251cu: goto P_0c04251c;
case 0x0c04251eu: goto P_0c04251e;
case 0x0c042520u: goto P_0c042520;
case 0x0c042522u: goto P_0c042522;
case 0x0c042524u: goto P_0c042524;
case 0x0c042526u: goto P_0c042526;
case 0x0c042528u: goto P_0c042528;
case 0x0c04252au: goto P_0c04252a;
case 0x0c04252cu: goto P_0c04252c;
case 0x0c04252eu: goto P_0c04252e;
case 0x0c042530u: goto P_0c042530;
case 0x0c042532u: goto P_0c042532;
case 0x0c042534u: goto P_0c042534;
case 0x0c042536u: goto P_0c042536;
case 0x0c042538u: goto P_0c042538;
case 0x0c04253au: goto P_0c04253a;
case 0x0c04253cu: goto P_0c04253c;
case 0x0c04253eu: goto P_0c04253e;
case 0x0c042540u: goto P_0c042540;
case 0x0c042542u: goto P_0c042542;
case 0x0c042544u: goto P_0c042544;
case 0x0c042546u: goto P_0c042546;
case 0x0c042548u: goto P_0c042548;
case 0x0c04254au: goto P_0c04254a;
case 0x0c04254cu: goto P_0c04254c;
case 0x0c04254eu: goto P_0c04254e;
case 0x0c042550u: goto P_0c042550;
case 0x0c042552u: goto P_0c042552;
case 0x0c042554u: goto P_0c042554;
case 0x0c042556u: goto P_0c042556;
case 0x0c042558u: goto P_0c042558;
case 0x0c04255au: goto P_0c04255a;
case 0x0c04255cu: goto P_0c04255c;
case 0x0c04255eu: goto P_0c04255e;
case 0x0c042560u: goto P_0c042560;
case 0x0c042562u: goto P_0c042562;
case 0x0c042564u: goto P_0c042564;
case 0x0c042566u: goto P_0c042566;
case 0x0c042568u: goto P_0c042568;
case 0x0c04256au: goto P_0c04256a;
case 0x0c04256cu: goto P_0c04256c;
case 0x0c04256eu: goto P_0c04256e;
case 0x0c042570u: goto P_0c042570;
case 0x0c042572u: goto P_0c042572;
case 0x0c042574u: goto P_0c042574;
case 0x0c042576u: goto P_0c042576;
case 0x0c042578u: goto P_0c042578;
case 0x0c04257au: goto P_0c04257a;
case 0x0c04257cu: goto P_0c04257c;
case 0x0c04257eu: goto P_0c04257e;
case 0x0c042580u: goto P_0c042580;
case 0x0c042582u: goto P_0c042582;
case 0x0c042584u: goto P_0c042584;
case 0x0c042586u: goto P_0c042586;
case 0x0c042588u: goto P_0c042588;
case 0x0c04258au: goto P_0c04258a;
case 0x0c04258cu: goto P_0c04258c;
case 0x0c04258eu: goto P_0c04258e;
case 0x0c042590u: goto P_0c042590;
case 0x0c042592u: goto P_0c042592;
case 0x0c042594u: goto P_0c042594;
case 0x0c042596u: goto P_0c042596;
case 0x0c042598u: goto P_0c042598;
case 0x0c04259au: goto P_0c04259a;
case 0x0c04259cu: goto P_0c04259c;
case 0x0c04259eu: goto P_0c04259e;
case 0x0c0425a0u: goto P_0c0425a0;
case 0x0c0425a2u: goto P_0c0425a2;
case 0x0c0425a4u: goto P_0c0425a4;
case 0x0c0425a6u: goto P_0c0425a6;
case 0x0c0425a8u: goto P_0c0425a8;
case 0x0c0425aau: goto P_0c0425aa;
case 0x0c0425acu: goto P_0c0425ac;
case 0x0c0425aeu: goto P_0c0425ae;
case 0x0c0425b0u: goto P_0c0425b0;
case 0x0c0425b2u: goto P_0c0425b2;
case 0x0c0425b4u: goto P_0c0425b4;
case 0x0c0425b6u: goto P_0c0425b6;
case 0x0c0425b8u: goto P_0c0425b8;
case 0x0c0425bau: goto P_0c0425ba;
case 0x0c0425bcu: goto P_0c0425bc;
case 0x0c0425beu: goto P_0c0425be;
case 0x0c0425c0u: goto P_0c0425c0;
case 0x0c0425c2u: goto P_0c0425c2;
case 0x0c0425c4u: goto P_0c0425c4;
case 0x0c0425c6u: goto P_0c0425c6;
case 0x0c0425c8u: goto P_0c0425c8;
case 0x0c0425cau: goto P_0c0425ca;
case 0x0c0425ccu: goto P_0c0425cc;
case 0x0c0425ceu: goto P_0c0425ce;
case 0x0c0425d0u: goto P_0c0425d0;
case 0x0c0425d2u: goto P_0c0425d2;
case 0x0c0425d4u: goto P_0c0425d4;
case 0x0c0425d6u: goto P_0c0425d6;
case 0x0c0425d8u: goto P_0c0425d8;
case 0x0c0425dau: goto P_0c0425da;
case 0x0c0425dcu: goto P_0c0425dc;
case 0x0c0425deu: goto P_0c0425de;
case 0x0c0425e0u: goto P_0c0425e0;
case 0x0c0425e2u: goto P_0c0425e2;
case 0x0c0425e4u: goto P_0c0425e4;
case 0x0c0425e6u: goto P_0c0425e6;
case 0x0c0425e8u: goto P_0c0425e8;
case 0x0c0425eau: goto P_0c0425ea;
case 0x0c0425ecu: goto P_0c0425ec;
case 0x0c0425eeu: goto P_0c0425ee;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03f2d0: /* original 2fe6, guest PC 0x0c03f2d0 */
if(!s->budget--) { s->failed_pc=0x0c03f2d0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f2d2;
P_0c03f2d2: /* original 2fd6, guest PC 0x0c03f2d2 */
if(!s->budget--) { s->failed_pc=0x0c03f2d2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f2d4;
P_0c03f2d4: /* original 2fc6, guest PC 0x0c03f2d4 */
if(!s->budget--) { s->failed_pc=0x0c03f2d4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f2d6;
P_0c03f2d6: /* original 2fb6, guest PC 0x0c03f2d6 */
if(!s->budget--) { s->failed_pc=0x0c03f2d6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f2d8;
P_0c03f2d8: /* original 2fa6, guest PC 0x0c03f2d8 */
if(!s->budget--) { s->failed_pc=0x0c03f2d8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f2da;
P_0c03f2da: /* original 2f96, guest PC 0x0c03f2da */
if(!s->budget--) { s->failed_pc=0x0c03f2dau; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f2dc;
P_0c03f2dc: /* original 2f86, guest PC 0x0c03f2dc */
if(!s->budget--) { s->failed_pc=0x0c03f2dcu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f2de;
P_0c03f2de: /* original 6342, guest PC 0x0c03f2de */
if(!s->budget--) { s->failed_pc=0x0c03f2deu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c03f2e0;
P_0c03f2e0: /* original 4f22, guest PC 0x0c03f2e0 */
if(!s->budget--) { s->failed_pc=0x0c03f2e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f2e2;
P_0c03f2e2: /* original 4311, guest PC 0x0c03f2e2 */
if(!s->budget--) { s->failed_pc=0x0c03f2e2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c03f2e4;
P_0c03f2e4: /* original 8f03, guest PC 0x0c03f2e4 */
if(!s->budget--) { s->failed_pc=0x0c03f2e4u; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(!cond) { goto P_0c03f2ee; }
goto P_0c03f2e8;
P_0c03f2e6: /* original ec00, guest PC 0x0c03f2e6 */
if(!s->budget--) { s->failed_pc=0x0c03f2e6u; return 0; }
r[12]=0x00000000u;
goto P_0c03f2e8;
P_0c03f2e8: /* original 5146, guest PC 0x0c03f2e8 */
if(!s->budget--) { s->failed_pc=0x0c03f2e8u; return 0; }
r[1]=read(ram,r[4]+24,4);
goto P_0c03f2ea;
P_0c03f2ea: /* original 2118, guest PC 0x0c03f2ea */
if(!s->budget--) { s->failed_pc=0x0c03f2eau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c03f2ec;
P_0c03f2ec: /* original 8b30, guest PC 0x0c03f2ec */
if(!s->budget--) { s->failed_pc=0x0c03f2ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f350; }
goto P_0c03f2ee;
P_0c03f2ee: /* original a06c, guest PC 0x0c03f2ee */
if(!s->budget--) { s->failed_pc=0x0c03f2eeu; return 0; }
r[0]=0x00000000u;
goto P_0c03f3ca;
P_0c03f2f0: /* original e000, guest PC 0x0c03f2f0 */
if(!s->budget--) { s->failed_pc=0x0c03f2f0u; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c03f2f2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f2f2u; return 0; } return 1;
P_0c03f350: /* original da65, guest PC 0x0c03f350 */
if(!s->budget--) { s->failed_pc=0x0c03f350u; return 0; }
r[10]=read(ram,0x0c03f4e8u,4);
goto P_0c03f352;
P_0c03f352: /* original 6d43, guest PC 0x0c03f352 */
if(!s->budget--) { s->failed_pc=0x0c03f352u; return 0; }
r[13]=r[4];
goto P_0c03f354;
P_0c03f354: /* original e901, guest PC 0x0c03f354 */
if(!s->budget--) { s->failed_pc=0x0c03f354u; return 0; }
r[9]=0x00000001u;
goto P_0c03f356;
P_0c03f356: /* original 7d18, guest PC 0x0c03f356 */
if(!s->budget--) { s->failed_pc=0x0c03f356u; return 0; }
r[13]+=0x00000018u;
goto P_0c03f358;
P_0c03f358: /* original e8ff, guest PC 0x0c03f358 */
if(!s->budget--) { s->failed_pc=0x0c03f358u; return 0; }
r[8]=0xffffffffu;
goto P_0c03f35a;
P_0c03f35a: /* original 6ed3, guest PC 0x0c03f35a */
if(!s->budget--) { s->failed_pc=0x0c03f35au; return 0; }
r[14]=r[13];
goto P_0c03f35c;
P_0c03f35c: /* original 55e8, guest PC 0x0c03f35c */
if(!s->budget--) { s->failed_pc=0x0c03f35cu; return 0; }
r[5]=read(ram,r[14]+32,4);
goto P_0c03f35e;
P_0c03f35e: /* original 4511, guest PC 0x0c03f35e */
if(!s->budget--) { s->failed_pc=0x0c03f35eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c03f360;
P_0c03f360: /* original 8f17, guest PC 0x0c03f360 */
if(!s->budget--) { s->failed_pc=0x0c03f360u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000050u;
if(!cond) { goto P_0c03f392; }
goto P_0c03f364;
P_0c03f362: /* original 7d50, guest PC 0x0c03f362 */
if(!s->budget--) { s->failed_pc=0x0c03f362u; return 0; }
r[13]+=0x00000050u;
goto P_0c03f364;
P_0c03f364: /* original d261, guest PC 0x0c03f364 */
if(!s->budget--) { s->failed_pc=0x0c03f364u; return 0; }
r[2]=read(ram,0x0c03f4ecu,4);
goto P_0c03f366;
P_0c03f366: /* original d062, guest PC 0x0c03f366 */
if(!s->budget--) { s->failed_pc=0x0c03f366u; return 0; }
r[0]=read(ram,0x0c03f4f0u,4);
goto P_0c03f368;
P_0c03f368: /* original 6322, guest PC 0x0c03f368 */
if(!s->budget--) { s->failed_pc=0x0c03f368u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f36a;
P_0c03f36a: /* original 6102, guest PC 0x0c03f36a */
if(!s->budget--) { s->failed_pc=0x0c03f36au; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c03f36c;
P_0c03f36c: /* original 353c, guest PC 0x0c03f36c */
if(!s->budget--) { s->failed_pc=0x0c03f36cu; return 0; }
r[5]+=r[3];
goto P_0c03f36e;
P_0c03f36e: /* original 6453, guest PC 0x0c03f36e */
if(!s->budget--) { s->failed_pc=0x0c03f36eu; return 0; }
r[4]=r[5];
goto P_0c03f370;
P_0c03f370: /* original 4408, guest PC 0x0c03f370 */
if(!s->budget--) { s->failed_pc=0x0c03f370u; return 0; }
r[4]<<=2;
goto P_0c03f372;
P_0c03f372: /* original 4400, guest PC 0x0c03f372 */
if(!s->budget--) { s->failed_pc=0x0c03f372u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c03f374;
P_0c03f374: /* original 341c, guest PC 0x0c03f374 */
if(!s->budget--) { s->failed_pc=0x0c03f374u; return 0; }
r[4]+=r[1];
goto P_0c03f376;
P_0c03f376: /* original 6342, guest PC 0x0c03f376 */
if(!s->budget--) { s->failed_pc=0x0c03f376u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c03f378;
P_0c03f378: /* original 2338, guest PC 0x0c03f378 */
if(!s->budget--) { s->failed_pc=0x0c03f378u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03f37a;
P_0c03f37a: /* original 8b09, guest PC 0x0c03f37a */
if(!s->budget--) { s->failed_pc=0x0c03f37au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f390; }
goto P_0c03f37c;
P_0c03f37c: /* original 6c93, guest PC 0x0c03f37c */
if(!s->budget--) { s->failed_pc=0x0c03f37cu; return 0; }
r[12]=r[9];
goto P_0c03f37e;
P_0c03f37e: /* original a008, guest PC 0x0c03f37e */
if(!s->budget--) { s->failed_pc=0x0c03f37eu; return 0; }
r[5]=r[8];
goto P_0c03f392;
P_0c03f380: /* original 6583, guest PC 0x0c03f380 */
if(!s->budget--) { s->failed_pc=0x0c03f380u; return 0; }
r[5]=r[8];
if(!vf3_matrix_family(0x0c03f382u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f382u; return 0; } return 1;
P_0c03f390: /* original 5541, guest PC 0x0c03f390 */
if(!s->budget--) { s->failed_pc=0x0c03f390u; return 0; }
r[5]=read(ram,r[4]+4,4);
goto P_0c03f392;
P_0c03f392: /* original 5be3, guest PC 0x0c03f392 */
if(!s->budget--) { s->failed_pc=0x0c03f392u; return 0; }
r[11]=read(ram,r[14]+12,4);
goto P_0c03f394;
P_0c03f394: /* original 4511, guest PC 0x0c03f394 */
if(!s->budget--) { s->failed_pc=0x0c03f394u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c03f396;
P_0c03f396: /* original 8f0b, guest PC 0x0c03f396 */
if(!s->budget--) { s->failed_pc=0x0c03f396u; return 0; }
cond=r[17]&1u;
r[11]&=r[10];
if(!cond) { goto P_0c03f3b0; }
goto P_0c03f39a;
P_0c03f398: /* original 2ba9, guest PC 0x0c03f398 */
if(!s->budget--) { s->failed_pc=0x0c03f398u; return 0; }
r[11]&=r[10];
goto P_0c03f39a;
P_0c03f39a: /* original d356, guest PC 0x0c03f39a */
if(!s->budget--) { s->failed_pc=0x0c03f39au; return 0; }
r[3]=read(ram,0x0c03f4f4u,4);
goto P_0c03f39c;
P_0c03f39c: /* original 430b, guest PC 0x0c03f39c */
if(!s->budget--) { s->failed_pc=0x0c03f39cu; return 0; }
target=r[3];
r[16]=code_base|0x0c03f3a0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f3a0u) { target=s->pc; goto dispatch; }
goto P_0c03f3a0;
P_0c03f39e: /* original 64e3, guest PC 0x0c03f39e */
if(!s->budget--) { s->failed_pc=0x0c03f39eu; return 0; }
r[4]=r[14];
goto P_0c03f3a0;
P_0c03f3a0: /* original a009, guest PC 0x0c03f3a0 */
if(!s->budget--) { s->failed_pc=0x0c03f3a0u; return 0; }
goto P_0c03f3b6;
P_0c03f3a2: /* original 0009, guest PC 0x0c03f3a2 */
if(!s->budget--) { s->failed_pc=0x0c03f3a2u; return 0; }
if(!vf3_matrix_family(0x0c03f3a4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f3a4u; return 0; } return 1;
P_0c03f3b0: /* original d351, guest PC 0x0c03f3b0 */
if(!s->budget--) { s->failed_pc=0x0c03f3b0u; return 0; }
r[3]=read(ram,0x0c03f4f8u,4);
goto P_0c03f3b2;
P_0c03f3b2: /* original 430b, guest PC 0x0c03f3b2 */
if(!s->budget--) { s->failed_pc=0x0c03f3b2u; return 0; }
target=r[3];
r[16]=code_base|0x0c03f3b6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f3b6u) { target=s->pc; goto dispatch; }
goto P_0c03f3b6;
P_0c03f3b4: /* original 64e3, guest PC 0x0c03f3b4 */
if(!s->budget--) { s->failed_pc=0x0c03f3b4u; return 0; }
r[4]=r[14];
goto P_0c03f3b6;
P_0c03f3b6: /* original e04c, guest PC 0x0c03f3b6 */
if(!s->budget--) { s->failed_pc=0x0c03f3b6u; return 0; }
r[0]=0x0000004cu;
goto P_0c03f3b8;
P_0c03f3b8: /* original 52e3, guest PC 0x0c03f3b8 */
if(!s->budget--) { s->failed_pc=0x0c03f3b8u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c03f3ba;
P_0c03f3ba: /* original 22bb, guest PC 0x0c03f3ba */
if(!s->budget--) { s->failed_pc=0x0c03f3bau; return 0; }
r[2]|=r[11];
goto P_0c03f3bc;
P_0c03f3bc: /* original 1e23, guest PC 0x0c03f3bc */
if(!s->budget--) { s->failed_pc=0x0c03f3bcu; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c03f3be;
P_0c03f3be: /* original 03ee, guest PC 0x0c03f3be */
if(!s->budget--) { s->failed_pc=0x0c03f3beu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c03f3c0;
P_0c03f3c0: /* original 3d3c, guest PC 0x0c03f3c0 */
if(!s->budget--) { s->failed_pc=0x0c03f3c0u; return 0; }
r[13]+=r[3];
goto P_0c03f3c2;
P_0c03f3c2: /* original 64d2, guest PC 0x0c03f3c2 */
if(!s->budget--) { s->failed_pc=0x0c03f3c2u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c03f3c4;
P_0c03f3c4: /* original 2448, guest PC 0x0c03f3c4 */
if(!s->budget--) { s->failed_pc=0x0c03f3c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03f3c6;
P_0c03f3c6: /* original 8bc8, guest PC 0x0c03f3c6 */
if(!s->budget--) { s->failed_pc=0x0c03f3c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f35a; }
goto P_0c03f3c8;
P_0c03f3c8: /* original 60c3, guest PC 0x0c03f3c8 */
if(!s->budget--) { s->failed_pc=0x0c03f3c8u; return 0; }
r[0]=r[12];
goto P_0c03f3ca;
P_0c03f3ca: /* original 4f26, guest PC 0x0c03f3ca */
if(!s->budget--) { s->failed_pc=0x0c03f3cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f3cc;
P_0c03f3cc: /* original 68f6, guest PC 0x0c03f3cc */
if(!s->budget--) { s->failed_pc=0x0c03f3ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03f3ce;
P_0c03f3ce: /* original 69f6, guest PC 0x0c03f3ce */
if(!s->budget--) { s->failed_pc=0x0c03f3ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03f3d0;
P_0c03f3d0: /* original 6af6, guest PC 0x0c03f3d0 */
if(!s->budget--) { s->failed_pc=0x0c03f3d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03f3d2;
P_0c03f3d2: /* original 6bf6, guest PC 0x0c03f3d2 */
if(!s->budget--) { s->failed_pc=0x0c03f3d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03f3d4;
P_0c03f3d4: /* original 6cf6, guest PC 0x0c03f3d4 */
if(!s->budget--) { s->failed_pc=0x0c03f3d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03f3d6;
P_0c03f3d6: /* original 6df6, guest PC 0x0c03f3d6 */
if(!s->budget--) { s->failed_pc=0x0c03f3d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03f3d8;
P_0c03f3d8: /* original 000b, guest PC 0x0c03f3d8 */
if(!s->budget--) { s->failed_pc=0x0c03f3d8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03f3da: /* original 6ef6, guest PC 0x0c03f3da */
if(!s->budget--) { s->failed_pc=0x0c03f3dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03f3dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f3dcu; return 0; } return 1;
P_0c040f1e: /* original 7ffc, guest PC 0x0c040f1e */
if(!s->budget--) { s->failed_pc=0x0c040f1eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c040f20;
P_0c040f20: /* original 2f42, guest PC 0x0c040f20 */
if(!s->budget--) { s->failed_pc=0x0c040f20u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c040f22;
P_0c040f22: /* original 60f2, guest PC 0x0c040f22 */
if(!s->budget--) { s->failed_pc=0x0c040f22u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c040f24;
P_0c040f24: /* original c880, guest PC 0x0c040f24 */
if(!s->budget--) { s->failed_pc=0x0c040f24u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c040f26;
P_0c040f26: /* original 8b03, guest PC 0x0c040f26 */
if(!s->budget--) { s->failed_pc=0x0c040f26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040f30; }
goto P_0c040f28;
P_0c040f28: /* original e0fe, guest PC 0x0c040f28 */
if(!s->budget--) { s->failed_pc=0x0c040f28u; return 0; }
r[0]=0xfffffffeu;
goto P_0c040f2a;
P_0c040f2a: /* original 7f04, guest PC 0x0c040f2a */
if(!s->budget--) { s->failed_pc=0x0c040f2au; return 0; }
r[15]+=0x00000004u;
goto P_0c040f2c;
P_0c040f2c: /* original 000b, guest PC 0x0c040f2c */
if(!s->budget--) { s->failed_pc=0x0c040f2cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f2e: /* original 0009, guest PC 0x0c040f2e */
if(!s->budget--) { s->failed_pc=0x0c040f2eu; return 0; }
goto P_0c040f30;
P_0c040f30: /* original d30d, guest PC 0x0c040f30 */
if(!s->budget--) { s->failed_pc=0x0c040f30u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f32;
P_0c040f32: /* original 6232, guest PC 0x0c040f32 */
if(!s->budget--) { s->failed_pc=0x0c040f32u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c040f34;
P_0c040f34: /* original 6122, guest PC 0x0c040f34 */
if(!s->budget--) { s->failed_pc=0x0c040f34u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c040f36;
P_0c040f36: /* original 2118, guest PC 0x0c040f36 */
if(!s->budget--) { s->failed_pc=0x0c040f36u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c040f38;
P_0c040f38: /* original 8903, guest PC 0x0c040f38 */
if(!s->budget--) { s->failed_pc=0x0c040f38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040f42; }
goto P_0c040f3a;
P_0c040f3a: /* original e0ff, guest PC 0x0c040f3a */
if(!s->budget--) { s->failed_pc=0x0c040f3au; return 0; }
r[0]=0xffffffffu;
goto P_0c040f3c;
P_0c040f3c: /* original 7f04, guest PC 0x0c040f3c */
if(!s->budget--) { s->failed_pc=0x0c040f3cu; return 0; }
r[15]+=0x00000004u;
goto P_0c040f3e;
P_0c040f3e: /* original 000b, guest PC 0x0c040f3e */
if(!s->budget--) { s->failed_pc=0x0c040f3eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f40: /* original 0009, guest PC 0x0c040f40 */
if(!s->budget--) { s->failed_pc=0x0c040f40u; return 0; }
goto P_0c040f42;
P_0c040f42: /* original d309, guest PC 0x0c040f42 */
if(!s->budget--) { s->failed_pc=0x0c040f42u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f44;
P_0c040f44: /* original 6232, guest PC 0x0c040f44 */
if(!s->budget--) { s->failed_pc=0x0c040f44u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c040f46;
P_0c040f46: /* original 7204, guest PC 0x0c040f46 */
if(!s->budget--) { s->failed_pc=0x0c040f46u; return 0; }
r[2]+=0x00000004u;
goto P_0c040f48;
P_0c040f48: /* original 2322, guest PC 0x0c040f48 */
if(!s->budget--) { s->failed_pc=0x0c040f48u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c040f4a;
P_0c040f4a: /* original 72fc, guest PC 0x0c040f4a */
if(!s->budget--) { s->failed_pc=0x0c040f4au; return 0; }
r[2]+=0xfffffffcu;
goto P_0c040f4c;
P_0c040f4c: /* original 63f2, guest PC 0x0c040f4c */
if(!s->budget--) { s->failed_pc=0x0c040f4cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c040f4e;
P_0c040f4e: /* original 2232, guest PC 0x0c040f4e */
if(!s->budget--) { s->failed_pc=0x0c040f4eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c040f50;
P_0c040f50: /* original d206, guest PC 0x0c040f50 */
if(!s->budget--) { s->failed_pc=0x0c040f50u; return 0; }
r[2]=read(ram,0x0c040f6cu,4);
goto P_0c040f52;
P_0c040f52: /* original d305, guest PC 0x0c040f52 */
if(!s->budget--) { s->failed_pc=0x0c040f52u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f54;
P_0c040f54: /* original 6132, guest PC 0x0c040f54 */
if(!s->budget--) { s->failed_pc=0x0c040f54u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c040f56;
P_0c040f56: /* original 3120, guest PC 0x0c040f56 */
if(!s->budget--) { s->failed_pc=0x0c040f56u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c040f58;
P_0c040f58: /* original 8b02, guest PC 0x0c040f58 */
if(!s->budget--) { s->failed_pc=0x0c040f58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040f60; }
goto P_0c040f5a;
P_0c040f5a: /* original d305, guest PC 0x0c040f5a */
if(!s->budget--) { s->failed_pc=0x0c040f5au; return 0; }
r[3]=read(ram,0x0c040f70u,4);
goto P_0c040f5c;
P_0c040f5c: /* original d002, guest PC 0x0c040f5c */
if(!s->budget--) { s->failed_pc=0x0c040f5cu; return 0; }
r[0]=read(ram,0x0c040f68u,4);
goto P_0c040f5e;
P_0c040f5e: /* original 2032, guest PC 0x0c040f5e */
if(!s->budget--) { s->failed_pc=0x0c040f5eu; return 0; }
write(ram,r[0],r[3],4);
goto P_0c040f60;
P_0c040f60: /* original e000, guest PC 0x0c040f60 */
if(!s->budget--) { s->failed_pc=0x0c040f60u; return 0; }
r[0]=0x00000000u;
goto P_0c040f62;
P_0c040f62: /* original 7f04, guest PC 0x0c040f62 */
if(!s->budget--) { s->failed_pc=0x0c040f62u; return 0; }
r[15]+=0x00000004u;
goto P_0c040f64;
P_0c040f64: /* original 000b, guest PC 0x0c040f64 */
if(!s->budget--) { s->failed_pc=0x0c040f64u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f66: /* original 0009, guest PC 0x0c040f66 */
if(!s->budget--) { s->failed_pc=0x0c040f66u; return 0; }
if(!vf3_matrix_family(0x0c040f68u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040f68u; return 0; } return 1;
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
P_0c042490: /* original d30a, guest PC 0x0c042490 */
if(!s->budget--) { s->failed_pc=0x0c042490u; return 0; }
r[3]=read(ram,0x0c0424bcu,4);
goto P_0c042492;
P_0c042492: /* original d20b, guest PC 0x0c042492 */
if(!s->budget--) { s->failed_pc=0x0c042492u; return 0; }
r[2]=read(ram,0x0c0424c0u,4);
goto P_0c042494;
P_0c042494: /* original 6530, guest PC 0x0c042494 */
if(!s->budget--) { s->failed_pc=0x0c042494u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[5]=tmp;
goto P_0c042496;
P_0c042496: /* original d10b, guest PC 0x0c042496 */
if(!s->budget--) { s->failed_pc=0x0c042496u; return 0; }
r[1]=read(ram,0x0c0424c4u,4);
goto P_0c042498;
P_0c042498: /* original 4f12, guest PC 0x0c042498 */
if(!s->budget--) { s->failed_pc=0x0c042498u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04249a;
P_0c04249a: /* original 0527, guest PC 0x0c04249a */
if(!s->budget--) { s->failed_pc=0x0c04249au; return 0; }
r[19]=r[5]*r[2];
goto P_0c04249c;
P_0c04249c: /* original 6412, guest PC 0x0c04249c */
if(!s->budget--) { s->failed_pc=0x0c04249cu; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c04249e;
P_0c04249e: /* original 2448, guest PC 0x0c04249e */
if(!s->budget--) { s->failed_pc=0x0c04249eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0424a0;
P_0c0424a0: /* original 8d08, guest PC 0x0c0424a0 */
if(!s->budget--) { s->failed_pc=0x0c0424a0u; return 0; }
cond=r[17]&1u;
r[5]=r[19];
if(cond) { goto P_0c0424b4; }
goto P_0c0424a4;
P_0c0424a2: /* original 051a, guest PC 0x0c0424a2 */
if(!s->budget--) { s->failed_pc=0x0c0424a2u; return 0; }
r[5]=r[19];
goto P_0c0424a4;
P_0c0424a4: /* original 9608, guest PC 0x0c0424a4 */
if(!s->budget--) { s->failed_pc=0x0c0424a4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0424b8u,2);
goto P_0c0424a6;
P_0c0424a6: /* original 364c, guest PC 0x0c0424a6 */
if(!s->budget--) { s->failed_pc=0x0c0424a6u; return 0; }
r[6]+=r[4];
goto P_0c0424a8;
P_0c0424a8: /* original d407, guest PC 0x0c0424a8 */
if(!s->budget--) { s->failed_pc=0x0c0424a8u; return 0; }
r[4]=read(ram,0x0c0424c8u,4);
goto P_0c0424aa;
P_0c0424aa: /* original 74ff, guest PC 0x0c0424aa */
if(!s->budget--) { s->failed_pc=0x0c0424aau; return 0; }
r[4]+=0xffffffffu;
goto P_0c0424ac;
P_0c0424ac: /* original 2652, guest PC 0x0c0424ac */
if(!s->budget--) { s->failed_pc=0x0c0424acu; return 0; }
write(ram,r[6],r[5],4);
goto P_0c0424ae;
P_0c0424ae: /* original 4411, guest PC 0x0c0424ae */
if(!s->budget--) { s->failed_pc=0x0c0424aeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0424b0;
P_0c0424b0: /* original 8dfb, guest PC 0x0c0424b0 */
if(!s->budget--) { s->failed_pc=0x0c0424b0u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000004u;
if(cond) { goto P_0c0424aa; }
goto P_0c0424b4;
P_0c0424b2: /* original 7604, guest PC 0x0c0424b2 */
if(!s->budget--) { s->failed_pc=0x0c0424b2u; return 0; }
r[6]+=0x00000004u;
goto P_0c0424b4;
P_0c0424b4: /* original 000b, guest PC 0x0c0424b4 */
if(!s->budget--) { s->failed_pc=0x0c0424b4u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c0424b6: /* original 4f16, guest PC 0x0c0424b6 */
if(!s->budget--) { s->failed_pc=0x0c0424b6u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c0424b8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0424b8u; return 0; } return 1;
P_0c0424d0: /* original 2fe6, guest PC 0x0c0424d0 */
if(!s->budget--) { s->failed_pc=0x0c0424d0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0424d2;
P_0c0424d2: /* original 2fd6, guest PC 0x0c0424d2 */
if(!s->budget--) { s->failed_pc=0x0c0424d2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0424d4;
P_0c0424d4: /* original 2fc6, guest PC 0x0c0424d4 */
if(!s->budget--) { s->failed_pc=0x0c0424d4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0424d6;
P_0c0424d6: /* original d24a, guest PC 0x0c0424d6 */
if(!s->budget--) { s->failed_pc=0x0c0424d6u; return 0; }
r[2]=read(ram,0x0c042600u,4);
goto P_0c0424d8;
P_0c0424d8: /* original 4f22, guest PC 0x0c0424d8 */
if(!s->budget--) { s->failed_pc=0x0c0424d8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0424da;
P_0c0424da: /* original 6322, guest PC 0x0c0424da */
if(!s->budget--) { s->failed_pc=0x0c0424dau; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0424dc;
P_0c0424dc: /* original 2338, guest PC 0x0c0424dc */
if(!s->budget--) { s->failed_pc=0x0c0424dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0424de;
P_0c0424de: /* original 8b01, guest PC 0x0c0424de */
if(!s->budget--) { s->failed_pc=0x0c0424deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0424e4; }
goto P_0c0424e0;
P_0c0424e0: /* original a081, guest PC 0x0c0424e0 */
if(!s->budget--) { s->failed_pc=0x0c0424e0u; return 0; }
goto P_0c0425e6;
P_0c0424e2: /* original 0009, guest PC 0x0c0424e2 */
if(!s->budget--) { s->failed_pc=0x0c0424e2u; return 0; }
goto P_0c0424e4;
P_0c0424e4: /* original d049, guest PC 0x0c0424e4 */
if(!s->budget--) { s->failed_pc=0x0c0424e4u; return 0; }
r[0]=read(ram,0x0c04260cu,4);
goto P_0c0424e6;
P_0c0424e6: /* original d148, guest PC 0x0c0424e6 */
if(!s->budget--) { s->failed_pc=0x0c0424e6u; return 0; }
r[1]=read(ram,0x0c042608u,4);
goto P_0c0424e8;
P_0c0424e8: /* original 6700, guest PC 0x0c0424e8 */
if(!s->budget--) { s->failed_pc=0x0c0424e8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[0],1);
r[7]=tmp;
goto P_0c0424ea;
P_0c0424ea: /* original e001, guest PC 0x0c0424ea */
if(!s->budget--) { s->failed_pc=0x0c0424eau; return 0; }
r[0]=0x00000001u;
goto P_0c0424ec;
P_0c0424ec: /* original 6312, guest PC 0x0c0424ec */
if(!s->budget--) { s->failed_pc=0x0c0424ecu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c0424ee;
P_0c0424ee: /* original e11b, guest PC 0x0c0424ee */
if(!s->budget--) { s->failed_pc=0x0c0424eeu; return 0; }
r[1]=0x0000001bu;
goto P_0c0424f0;
P_0c0424f0: /* original 6273, guest PC 0x0c0424f0 */
if(!s->budget--) { s->failed_pc=0x0c0424f0u; return 0; }
r[2]=r[7];
goto P_0c0424f2;
P_0c0424f2: /* original 4708, guest PC 0x0c0424f2 */
if(!s->budget--) { s->failed_pc=0x0c0424f2u; return 0; }
r[7]<<=2;
goto P_0c0424f4;
P_0c0424f4: /* original 372c, guest PC 0x0c0424f4 */
if(!s->budget--) { s->failed_pc=0x0c0424f4u; return 0; }
r[7]+=r[2];
goto P_0c0424f6;
P_0c0424f6: /* original 5632, guest PC 0x0c0424f6 */
if(!s->budget--) { s->failed_pc=0x0c0424f6u; return 0; }
r[6]=read(ram,r[3]+8,4);
goto P_0c0424f8;
P_0c0424f8: /* original 4708, guest PC 0x0c0424f8 */
if(!s->budget--) { s->failed_pc=0x0c0424f8u; return 0; }
r[7]<<=2;
goto P_0c0424fa;
P_0c0424fa: /* original d345, guest PC 0x0c0424fa */
if(!s->budget--) { s->failed_pc=0x0c0424fau; return 0; }
r[3]=read(ram,0x0c042610u,4);
goto P_0c0424fc;
P_0c0424fc: /* original 4700, guest PC 0x0c0424fc */
if(!s->budget--) { s->failed_pc=0x0c0424fcu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c0424fe;
P_0c0424fe: /* original d441, guest PC 0x0c0424fe */
if(!s->budget--) { s->failed_pc=0x0c0424feu; return 0; }
r[4]=read(ram,0x0c042604u,4);
goto P_0c042500;
P_0c042500: /* original 677e, guest PC 0x0c042500 */
if(!s->budget--) { s->failed_pc=0x0c042500u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)r[7];
goto P_0c042502;
P_0c042502: /* original 373c, guest PC 0x0c042502 */
if(!s->budget--) { s->failed_pc=0x0c042502u; return 0; }
r[7]+=r[3];
goto P_0c042504;
P_0c042504: /* original 5576, guest PC 0x0c042504 */
if(!s->budget--) { s->failed_pc=0x0c042504u; return 0; }
r[5]=read(ram,r[7]+24,4);
goto P_0c042506;
P_0c042506: /* original e208, guest PC 0x0c042506 */
if(!s->budget--) { s->failed_pc=0x0c042506u; return 0; }
r[2]=0x00000008u;
goto P_0c042508;
P_0c042508: /* original 5372, guest PC 0x0c042508 */
if(!s->budget--) { s->failed_pc=0x0c042508u; return 0; }
r[3]=read(ram,r[7]+8,4);
goto P_0c04250a;
P_0c04250a: /* original 2059, guest PC 0x0c04250a */
if(!s->budget--) { s->failed_pc=0x0c04250au; return 0; }
r[0]&=r[5];
goto P_0c04250c;
P_0c04250c: /* original 2259, guest PC 0x0c04250c */
if(!s->budget--) { s->failed_pc=0x0c04250cu; return 0; }
r[2]&=r[5];
goto P_0c04250e;
P_0c04250e: /* original c901, guest PC 0x0c04250e */
if(!s->budget--) { s->failed_pc=0x0c04250eu; return 0; }
r[0]&=1u;
goto P_0c042510;
P_0c042510: /* original 421d, guest PC 0x0c042510 */
if(!s->budget--) { s->failed_pc=0x0c042510u; return 0; }
r[2]=(r[1]&0x80000000u)?((r[1]&31u)?r[2]>>((-r[1])&31u):0):r[2]<<(r[1]&31u);
goto P_0c042512;
P_0c042512: /* original 4005, guest PC 0x0c042512 */
if(!s->budget--) { s->failed_pc=0x0c042512u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1u)!=0);
r[0]=(r[0]>>1)|(r[0]<<31);
goto P_0c042514;
P_0c042514: /* original 202b, guest PC 0x0c042514 */
if(!s->budget--) { s->failed_pc=0x0c042514u; return 0; }
r[0]|=r[2];
goto P_0c042516;
P_0c042516: /* original d23f, guest PC 0x0c042516 */
if(!s->budget--) { s->failed_pc=0x0c042516u; return 0; }
r[2]=read(ram,0x0c042614u,4);
goto P_0c042518;
P_0c042518: /* original 2329, guest PC 0x0c042518 */
if(!s->budget--) { s->failed_pc=0x0c042518u; return 0; }
r[3]&=r[2];
goto P_0c04251a;
P_0c04251a: /* original 203b, guest PC 0x0c04251a */
if(!s->budget--) { s->failed_pc=0x0c04251au; return 0; }
r[0]|=r[3];
goto P_0c04251c;
P_0c04251c: /* original 6303, guest PC 0x0c04251c */
if(!s->budget--) { s->failed_pc=0x0c04251cu; return 0; }
r[3]=r[0];
goto P_0c04251e;
P_0c04251e: /* original 6057, guest PC 0x0c04251e */
if(!s->budget--) { s->failed_pc=0x0c04251eu; return 0; }
r[0]=~r[5];
goto P_0c042520;
P_0c042520: /* original c904, guest PC 0x0c042520 */
if(!s->budget--) { s->failed_pc=0x0c042520u; return 0; }
r[0]&=4u;
goto P_0c042522;
P_0c042522: /* original 4028, guest PC 0x0c042522 */
if(!s->budget--) { s->failed_pc=0x0c042522u; return 0; }
r[0]<<=16;
goto P_0c042524;
P_0c042524: /* original 4018, guest PC 0x0c042524 */
if(!s->budget--) { s->failed_pc=0x0c042524u; return 0; }
r[0]<<=8;
goto P_0c042526;
P_0c042526: /* original 230b, guest PC 0x0c042526 */
if(!s->budget--) { s->failed_pc=0x0c042526u; return 0; }
r[3]|=r[0];
goto P_0c042528;
P_0c042528: /* original e010, guest PC 0x0c042528 */
if(!s->budget--) { s->failed_pc=0x0c042528u; return 0; }
r[0]=0x00000010u;
goto P_0c04252a;
P_0c04252a: /* original e215, guest PC 0x0c04252a */
if(!s->budget--) { s->failed_pc=0x0c04252au; return 0; }
r[2]=0x00000015u;
goto P_0c04252c;
P_0c04252c: /* original 2059, guest PC 0x0c04252c */
if(!s->budget--) { s->failed_pc=0x0c04252cu; return 0; }
r[0]&=r[5];
goto P_0c04252e;
P_0c04252e: /* original 402d, guest PC 0x0c04252e */
if(!s->budget--) { s->failed_pc=0x0c04252eu; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?r[0]>>((-r[2])&31u):0):r[0]<<(r[2]&31u);
goto P_0c042530;
P_0c042530: /* original 230b, guest PC 0x0c042530 */
if(!s->budget--) { s->failed_pc=0x0c042530u; return 0; }
r[3]|=r[0];
goto P_0c042532;
P_0c042532: /* original 5077, guest PC 0x0c042532 */
if(!s->budget--) { s->failed_pc=0x0c042532u; return 0; }
r[0]=read(ram,r[7]+28,4);
goto P_0c042534;
P_0c042534: /* original 4009, guest PC 0x0c042534 */
if(!s->budget--) { s->failed_pc=0x0c042534u; return 0; }
r[0]>>=2;
goto P_0c042536;
P_0c042536: /* original 4001, guest PC 0x0c042536 */
if(!s->budget--) { s->failed_pc=0x0c042536u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c042538;
P_0c042538: /* original 230b, guest PC 0x0c042538 */
if(!s->budget--) { s->failed_pc=0x0c042538u; return 0; }
r[3]|=r[0];
goto P_0c04253a;
P_0c04253a: /* original 1433, guest PC 0x0c04253a */
if(!s->budget--) { s->failed_pc=0x0c04253au; return 0; }
write(ram,r[4]+12,r[3],4);
goto P_0c04253c;
P_0c04253c: /* original 6363, guest PC 0x0c04253c */
if(!s->budget--) { s->failed_pc=0x0c04253cu; return 0; }
r[3]=r[6];
goto P_0c04253e;
P_0c04253e: /* original d036, guest PC 0x0c04253e */
if(!s->budget--) { s->failed_pc=0x0c04253eu; return 0; }
r[0]=read(ram,0x0c042618u,4);
goto P_0c042540;
P_0c042540: /* original 4329, guest PC 0x0c042540 */
if(!s->budget--) { s->failed_pc=0x0c042540u; return 0; }
r[3]>>=16;
goto P_0c042542;
P_0c042542: /* original 4319, guest PC 0x0c042542 */
if(!s->budget--) { s->failed_pc=0x0c042542u; return 0; }
r[3]>>=8;
goto P_0c042544;
P_0c042544: /* original 2032, guest PC 0x0c042544 */
if(!s->budget--) { s->failed_pc=0x0c042544u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c042546;
P_0c042546: /* original d235, guest PC 0x0c042546 */
if(!s->budget--) { s->failed_pc=0x0c042546u; return 0; }
r[2]=read(ram,0x0c04261cu,4);
goto P_0c042548;
P_0c042548: /* original 2232, guest PC 0x0c042548 */
if(!s->budget--) { s->failed_pc=0x0c042548u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c04254a;
P_0c04254a: /* original de35, guest PC 0x0c04254a */
if(!s->budget--) { s->failed_pc=0x0c04254au; return 0; }
r[14]=read(ram,0x0c042620u,4);
goto P_0c04254c;
P_0c04254c: /* original d335, guest PC 0x0c04254c */
if(!s->budget--) { s->failed_pc=0x0c04254cu; return 0; }
r[3]=read(ram,0x0c042624u,4);
goto P_0c04254e;
P_0c04254e: /* original 6242, guest PC 0x0c04254e */
if(!s->budget--) { s->failed_pc=0x0c04254eu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c042550;
P_0c042550: /* original 2e69, guest PC 0x0c042550 */
if(!s->budget--) { s->failed_pc=0x0c042550u; return 0; }
r[14]&=r[6];
goto P_0c042552;
P_0c042552: /* original 2e3b, guest PC 0x0c042552 */
if(!s->budget--) { s->failed_pc=0x0c042552u; return 0; }
r[14]|=r[3];
goto P_0c042554;
P_0c042554: /* original 2e22, guest PC 0x0c042554 */
if(!s->budget--) { s->failed_pc=0x0c042554u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c042556;
P_0c042556: /* original 5141, guest PC 0x0c042556 */
if(!s->budget--) { s->failed_pc=0x0c042556u; return 0; }
r[1]=read(ram,r[4]+4,4);
goto P_0c042558;
P_0c042558: /* original 1e11, guest PC 0x0c042558 */
if(!s->budget--) { s->failed_pc=0x0c042558u; return 0; }
write(ram,r[14]+4,r[1],4);
goto P_0c04255a;
P_0c04255a: /* original 5242, guest PC 0x0c04255a */
if(!s->budget--) { s->failed_pc=0x0c04255au; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c04255c;
P_0c04255c: /* original 1e22, guest PC 0x0c04255c */
if(!s->budget--) { s->failed_pc=0x0c04255cu; return 0; }
write(ram,r[14]+8,r[2],4);
goto P_0c04255e;
P_0c04255e: /* original 5143, guest PC 0x0c04255e */
if(!s->budget--) { s->failed_pc=0x0c04255eu; return 0; }
r[1]=read(ram,r[4]+12,4);
goto P_0c042560;
P_0c042560: /* original 1e13, guest PC 0x0c042560 */
if(!s->budget--) { s->failed_pc=0x0c042560u; return 0; }
write(ram,r[14]+12,r[1],4);
goto P_0c042562;
P_0c042562: /* original 5244, guest PC 0x0c042562 */
if(!s->budget--) { s->failed_pc=0x0c042562u; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c042564;
P_0c042564: /* original 1e24, guest PC 0x0c042564 */
if(!s->budget--) { s->failed_pc=0x0c042564u; return 0; }
write(ram,r[14]+16,r[2],4);
goto P_0c042566;
P_0c042566: /* original dd30, guest PC 0x0c042566 */
if(!s->budget--) { s->failed_pc=0x0c042566u; return 0; }
r[13]=read(ram,0x0c042628u,4);
goto P_0c042568;
P_0c042568: /* original 4d0b, guest PC 0x0c042568 */
if(!s->budget--) { s->failed_pc=0x0c042568u; return 0; }
target=r[13];
r[16]=code_base|0x0c04256cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04256cu) { target=s->pc; goto dispatch; }
goto P_0c04256c;
P_0c04256a: /* original 64e3, guest PC 0x0c04256a */
if(!s->budget--) { s->failed_pc=0x0c04256au; return 0; }
r[4]=r[14];
goto P_0c04256c;
P_0c04256c: /* original c72f, guest PC 0x0c04256c */
if(!s->budget--) { s->failed_pc=0x0c04256cu; return 0; }
r[0]=code_base|0x0004262cu;
goto P_0c04256e;
P_0c04256e: /* original 7e20, guest PC 0x0c04256e */
if(!s->budget--) { s->failed_pc=0x0c04256eu; return 0; }
r[14]+=0x00000020u;
goto P_0c042570;
P_0c042570: /* original e3ff, guest PC 0x0c042570 */
if(!s->budget--) { s->failed_pc=0x0c042570u; return 0; }
r[3]=0xffffffffu;
goto P_0c042572;
P_0c042572: /* original 2e32, guest PC 0x0c042572 */
if(!s->budget--) { s->failed_pc=0x0c042572u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c042574;
P_0c042574: /* original f308, guest PC 0x0c042574 */
if(!s->budget--) { s->failed_pc=0x0c042574u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c042576;
P_0c042576: /* original e004, guest PC 0x0c042576 */
if(!s->budget--) { s->failed_pc=0x0c042576u; return 0; }
r[0]=0x00000004u;
goto P_0c042578;
P_0c042578: /* original fe37, guest PC 0x0c042578 */
if(!s->budget--) { s->failed_pc=0x0c042578u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c04257a;
P_0c04257a: /* original e008, guest PC 0x0c04257a */
if(!s->budget--) { s->failed_pc=0x0c04257au; return 0; }
r[0]=0x00000008u;
goto P_0c04257c;
P_0c04257c: /* original f48d, guest PC 0x0c04257c */
if(!s->budget--) { s->failed_pc=0x0c04257cu; return 0; }
fr[4]=0;
goto P_0c04257e;
P_0c04257e: /* original fe47, guest PC 0x0c04257e */
if(!s->budget--) { s->failed_pc=0x0c04257eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c042580;
P_0c042580: /* original e00c, guest PC 0x0c042580 */
if(!s->budget--) { s->failed_pc=0x0c042580u; return 0; }
r[0]=0x0000000cu;
goto P_0c042582;
P_0c042582: /* original dc2b, guest PC 0x0c042582 */
if(!s->budget--) { s->failed_pc=0x0c042582u; return 0; }
r[12]=read(ram,0x0c042630u,4);
goto P_0c042584;
P_0c042584: /* original f3c8, guest PC 0x0c042584 */
if(!s->budget--) { s->failed_pc=0x0c042584u; return 0; }
vf3_matrix_load(s,ram,3,r[12]);
goto P_0c042586;
P_0c042586: /* original fe37, guest PC 0x0c042586 */
if(!s->budget--) { s->failed_pc=0x0c042586u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c042588;
P_0c042588: /* original c72a, guest PC 0x0c042588 */
if(!s->budget--) { s->failed_pc=0x0c042588u; return 0; }
r[0]=code_base|0x00042634u;
goto P_0c04258a;
P_0c04258a: /* original f508, guest PC 0x0c04258a */
if(!s->budget--) { s->failed_pc=0x0c04258au; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c04258c;
P_0c04258c: /* original e010, guest PC 0x0c04258c */
if(!s->budget--) { s->failed_pc=0x0c04258cu; return 0; }
r[0]=0x00000010u;
goto P_0c04258e;
P_0c04258e: /* original fe57, guest PC 0x0c04258e */
if(!s->budget--) { s->failed_pc=0x0c04258eu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c042590;
P_0c042590: /* original e014, guest PC 0x0c042590 */
if(!s->budget--) { s->failed_pc=0x0c042590u; return 0; }
r[0]=0x00000014u;
goto P_0c042592;
P_0c042592: /* original fe47, guest PC 0x0c042592 */
if(!s->budget--) { s->failed_pc=0x0c042592u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c042594;
P_0c042594: /* original e018, guest PC 0x0c042594 */
if(!s->budget--) { s->failed_pc=0x0c042594u; return 0; }
r[0]=0x00000018u;
goto P_0c042596;
P_0c042596: /* original f3c8, guest PC 0x0c042596 */
if(!s->budget--) { s->failed_pc=0x0c042596u; return 0; }
vf3_matrix_load(s,ram,3,r[12]);
goto P_0c042598;
P_0c042598: /* original fe37, guest PC 0x0c042598 */
if(!s->budget--) { s->failed_pc=0x0c042598u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c04259a;
P_0c04259a: /* original e01c, guest PC 0x0c04259a */
if(!s->budget--) { s->failed_pc=0x0c04259au; return 0; }
r[0]=0x0000001cu;
goto P_0c04259c;
P_0c04259c: /* original fe57, guest PC 0x0c04259c */
if(!s->budget--) { s->failed_pc=0x0c04259cu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c04259e;
P_0c04259e: /* original 4d0b, guest PC 0x0c04259e */
if(!s->budget--) { s->failed_pc=0x0c04259eu; return 0; }
target=r[13];
r[16]=code_base|0x0c0425a2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0425a2u) { target=s->pc; goto dispatch; }
goto P_0c0425a2;
P_0c0425a0: /* original 64e3, guest PC 0x0c0425a0 */
if(!s->budget--) { s->failed_pc=0x0c0425a0u; return 0; }
r[4]=r[14];
goto P_0c0425a2;
P_0c0425a2: /* original c725, guest PC 0x0c0425a2 */
if(!s->budget--) { s->failed_pc=0x0c0425a2u; return 0; }
r[0]=code_base|0x00042638u;
goto P_0c0425a4;
P_0c0425a4: /* original f408, guest PC 0x0c0425a4 */
if(!s->budget--) { s->failed_pc=0x0c0425a4u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0425a6;
P_0c0425a6: /* original e004, guest PC 0x0c0425a6 */
if(!s->budget--) { s->failed_pc=0x0c0425a6u; return 0; }
r[0]=0x00000004u;
goto P_0c0425a8;
P_0c0425a8: /* original 7e20, guest PC 0x0c0425a8 */
if(!s->budget--) { s->failed_pc=0x0c0425a8u; return 0; }
r[14]+=0x00000020u;
goto P_0c0425aa;
P_0c0425aa: /* original e200, guest PC 0x0c0425aa */
if(!s->budget--) { s->failed_pc=0x0c0425aau; return 0; }
r[2]=0x00000000u;
goto P_0c0425ac;
P_0c0425ac: /* original fe4a, guest PC 0x0c0425ac */
if(!s->budget--) { s->failed_pc=0x0c0425acu; return 0; }
vf3_matrix_store(s,ram,4,r[14]);
goto P_0c0425ae;
P_0c0425ae: /* original f3c8, guest PC 0x0c0425ae */
if(!s->budget--) { s->failed_pc=0x0c0425aeu; return 0; }
vf3_matrix_load(s,ram,3,r[12]);
goto P_0c0425b0;
P_0c0425b0: /* original fe37, guest PC 0x0c0425b0 */
if(!s->budget--) { s->failed_pc=0x0c0425b0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0425b2;
P_0c0425b2: /* original c71e, guest PC 0x0c0425b2 */
if(!s->budget--) { s->failed_pc=0x0c0425b2u; return 0; }
r[0]=code_base|0x0004262cu;
goto P_0c0425b4;
P_0c0425b4: /* original f308, guest PC 0x0c0425b4 */
if(!s->budget--) { s->failed_pc=0x0c0425b4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0425b6;
P_0c0425b6: /* original e008, guest PC 0x0c0425b6 */
if(!s->budget--) { s->failed_pc=0x0c0425b6u; return 0; }
r[0]=0x00000008u;
goto P_0c0425b8;
P_0c0425b8: /* original fe37, guest PC 0x0c0425b8 */
if(!s->budget--) { s->failed_pc=0x0c0425b8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0425ba;
P_0c0425ba: /* original e00c, guest PC 0x0c0425ba */
if(!s->budget--) { s->failed_pc=0x0c0425bau; return 0; }
r[0]=0x0000000cu;
goto P_0c0425bc;
P_0c0425bc: /* original fe47, guest PC 0x0c0425bc */
if(!s->budget--) { s->failed_pc=0x0c0425bcu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0425be;
P_0c0425be: /* original d31f, guest PC 0x0c0425be */
if(!s->budget--) { s->failed_pc=0x0c0425beu; return 0; }
r[3]=read(ram,0x0c04263cu,4);
goto P_0c0425c0;
P_0c0425c0: /* original 1e34, guest PC 0x0c0425c0 */
if(!s->budget--) { s->failed_pc=0x0c0425c0u; return 0; }
write(ram,r[14]+16,r[3],4);
goto P_0c0425c2;
P_0c0425c2: /* original 1e25, guest PC 0x0c0425c2 */
if(!s->budget--) { s->failed_pc=0x0c0425c2u; return 0; }
write(ram,r[14]+20,r[2],4);
goto P_0c0425c4;
P_0c0425c4: /* original d31e, guest PC 0x0c0425c4 */
if(!s->budget--) { s->failed_pc=0x0c0425c4u; return 0; }
r[3]=read(ram,0x0c042640u,4);
goto P_0c0425c6;
P_0c0425c6: /* original 1e36, guest PC 0x0c0425c6 */
if(!s->budget--) { s->failed_pc=0x0c0425c6u; return 0; }
write(ram,r[14]+24,r[3],4);
goto P_0c0425c8;
P_0c0425c8: /* original d21e, guest PC 0x0c0425c8 */
if(!s->budget--) { s->failed_pc=0x0c0425c8u; return 0; }
r[2]=read(ram,0x0c042644u,4);
goto P_0c0425ca;
P_0c0425ca: /* original 1e27, guest PC 0x0c0425ca */
if(!s->budget--) { s->failed_pc=0x0c0425cau; return 0; }
write(ram,r[14]+28,r[2],4);
goto P_0c0425cc;
P_0c0425cc: /* original 4d0b, guest PC 0x0c0425cc */
if(!s->budget--) { s->failed_pc=0x0c0425ccu; return 0; }
target=r[13];
r[16]=code_base|0x0c0425d0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0425d0u) { target=s->pc; goto dispatch; }
goto P_0c0425d0;
P_0c0425ce: /* original 64e3, guest PC 0x0c0425ce */
if(!s->budget--) { s->failed_pc=0x0c0425ceu; return 0; }
r[4]=r[14];
goto P_0c0425d0;
P_0c0425d0: /* original d30d, guest PC 0x0c0425d0 */
if(!s->budget--) { s->failed_pc=0x0c0425d0u; return 0; }
r[3]=read(ram,0x0c042608u,4);
goto P_0c0425d2;
P_0c0425d2: /* original 7e20, guest PC 0x0c0425d2 */
if(!s->budget--) { s->failed_pc=0x0c0425d2u; return 0; }
r[14]+=0x00000020u;
goto P_0c0425d4;
P_0c0425d4: /* original d012, guest PC 0x0c0425d4 */
if(!s->budget--) { s->failed_pc=0x0c0425d4u; return 0; }
r[0]=read(ram,0x0c042620u,4);
goto P_0c0425d6;
P_0c0425d6: /* original 6432, guest PC 0x0c0425d6 */
if(!s->budget--) { s->failed_pc=0x0c0425d6u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0425d8;
P_0c0425d8: /* original d21b, guest PC 0x0c0425d8 */
if(!s->budget--) { s->failed_pc=0x0c0425d8u; return 0; }
r[2]=read(ram,0x0c042648u,4);
goto P_0c0425da;
P_0c0425da: /* original 2e09, guest PC 0x0c0425da */
if(!s->budget--) { s->failed_pc=0x0c0425dau; return 0; }
r[14]&=r[0];
goto P_0c0425dc;
P_0c0425dc: /* original 7408, guest PC 0x0c0425dc */
if(!s->budget--) { s->failed_pc=0x0c0425dcu; return 0; }
r[4]+=0x00000008u;
goto P_0c0425de;
P_0c0425de: /* original 6142, guest PC 0x0c0425de */
if(!s->budget--) { s->failed_pc=0x0c0425deu; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c0425e0;
P_0c0425e0: /* original 2129, guest PC 0x0c0425e0 */
if(!s->budget--) { s->failed_pc=0x0c0425e0u; return 0; }
r[1]&=r[2];
goto P_0c0425e2;
P_0c0425e2: /* original 21eb, guest PC 0x0c0425e2 */
if(!s->budget--) { s->failed_pc=0x0c0425e2u; return 0; }
r[1]|=r[14];
goto P_0c0425e4;
P_0c0425e4: /* original 2412, guest PC 0x0c0425e4 */
if(!s->budget--) { s->failed_pc=0x0c0425e4u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c0425e6;
P_0c0425e6: /* original 4f26, guest PC 0x0c0425e6 */
if(!s->budget--) { s->failed_pc=0x0c0425e6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0425e8;
P_0c0425e8: /* original 6cf6, guest PC 0x0c0425e8 */
if(!s->budget--) { s->failed_pc=0x0c0425e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0425ea;
P_0c0425ea: /* original 6df6, guest PC 0x0c0425ea */
if(!s->budget--) { s->failed_pc=0x0c0425eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0425ec;
P_0c0425ec: /* original 000b, guest PC 0x0c0425ec */
if(!s->budget--) { s->failed_pc=0x0c0425ecu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0425ee: /* original 6ef6, guest PC 0x0c0425ee */
if(!s->budget--) { s->failed_pc=0x0c0425eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0425f0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
