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
int vf3_away_batch120_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c040392u: goto P_0c040392;
case 0x0c040394u: goto P_0c040394;
case 0x0c040396u: goto P_0c040396;
case 0x0c040398u: goto P_0c040398;
case 0x0c04039au: goto P_0c04039a;
case 0x0c04039cu: goto P_0c04039c;
case 0x0c04039eu: goto P_0c04039e;
case 0x0c0403a0u: goto P_0c0403a0;
case 0x0c0403a2u: goto P_0c0403a2;
case 0x0c0403a4u: goto P_0c0403a4;
case 0x0c0403a6u: goto P_0c0403a6;
case 0x0c0403a8u: goto P_0c0403a8;
case 0x0c0403aau: goto P_0c0403aa;
case 0x0c0403acu: goto P_0c0403ac;
case 0x0c0403aeu: goto P_0c0403ae;
case 0x0c0403b0u: goto P_0c0403b0;
case 0x0c0403b2u: goto P_0c0403b2;
case 0x0c0403b4u: goto P_0c0403b4;
case 0x0c0403c0u: goto P_0c0403c0;
case 0x0c0403c2u: goto P_0c0403c2;
case 0x0c0403c4u: goto P_0c0403c4;
case 0x0c0403c6u: goto P_0c0403c6;
case 0x0c0403c8u: goto P_0c0403c8;
case 0x0c0403cau: goto P_0c0403ca;
case 0x0c0403ccu: goto P_0c0403cc;
case 0x0c0403ceu: goto P_0c0403ce;
case 0x0c0403d0u: goto P_0c0403d0;
case 0x0c0403d2u: goto P_0c0403d2;
case 0x0c0403d4u: goto P_0c0403d4;
case 0x0c0403d6u: goto P_0c0403d6;
case 0x0c0403d8u: goto P_0c0403d8;
case 0x0c0403dau: goto P_0c0403da;
case 0x0c0403dcu: goto P_0c0403dc;
case 0x0c0403deu: goto P_0c0403de;
case 0x0c0403e0u: goto P_0c0403e0;
case 0x0c0403e2u: goto P_0c0403e2;
case 0x0c0403e4u: goto P_0c0403e4;
case 0x0c0403e6u: goto P_0c0403e6;
case 0x0c0403e8u: goto P_0c0403e8;
case 0x0c0403eau: goto P_0c0403ea;
case 0x0c0403ecu: goto P_0c0403ec;
case 0x0c0403eeu: goto P_0c0403ee;
case 0x0c0403f0u: goto P_0c0403f0;
case 0x0c0403f2u: goto P_0c0403f2;
case 0x0c0403f4u: goto P_0c0403f4;
case 0x0c0403f6u: goto P_0c0403f6;
case 0x0c0403f8u: goto P_0c0403f8;
case 0x0c0403fau: goto P_0c0403fa;
case 0x0c0403fcu: goto P_0c0403fc;
case 0x0c0403feu: goto P_0c0403fe;
case 0x0c040400u: goto P_0c040400;
case 0x0c040410u: goto P_0c040410;
case 0x0c040412u: goto P_0c040412;
case 0x0c040414u: goto P_0c040414;
case 0x0c040416u: goto P_0c040416;
case 0x0c040418u: goto P_0c040418;
case 0x0c04041au: goto P_0c04041a;
case 0x0c04041cu: goto P_0c04041c;
case 0x0c04041eu: goto P_0c04041e;
case 0x0c040420u: goto P_0c040420;
case 0x0c040422u: goto P_0c040422;
case 0x0c040424u: goto P_0c040424;
case 0x0c040426u: goto P_0c040426;
case 0x0c040428u: goto P_0c040428;
case 0x0c04042au: goto P_0c04042a;
case 0x0c04042cu: goto P_0c04042c;
case 0x0c04042eu: goto P_0c04042e;
case 0x0c040430u: goto P_0c040430;
case 0x0c040432u: goto P_0c040432;
case 0x0c040434u: goto P_0c040434;
case 0x0c040436u: goto P_0c040436;
case 0x0c040438u: goto P_0c040438;
case 0x0c04043au: goto P_0c04043a;
case 0x0c04043cu: goto P_0c04043c;
case 0x0c04043eu: goto P_0c04043e;
case 0x0c040440u: goto P_0c040440;
case 0x0c040442u: goto P_0c040442;
case 0x0c040444u: goto P_0c040444;
case 0x0c040446u: goto P_0c040446;
case 0x0c040448u: goto P_0c040448;
case 0x0c04044au: goto P_0c04044a;
case 0x0c04044cu: goto P_0c04044c;
case 0x0c04044eu: goto P_0c04044e;
case 0x0c040450u: goto P_0c040450;
case 0x0c040452u: goto P_0c040452;
case 0x0c040454u: goto P_0c040454;
case 0x0c040456u: goto P_0c040456;
case 0x0c040458u: goto P_0c040458;
case 0x0c04045au: goto P_0c04045a;
case 0x0c04045cu: goto P_0c04045c;
case 0x0c04045eu: goto P_0c04045e;
case 0x0c040460u: goto P_0c040460;
case 0x0c040462u: goto P_0c040462;
case 0x0c040464u: goto P_0c040464;
case 0x0c040466u: goto P_0c040466;
case 0x0c040468u: goto P_0c040468;
case 0x0c04046au: goto P_0c04046a;
case 0x0c04046cu: goto P_0c04046c;
case 0x0c04046eu: goto P_0c04046e;
case 0x0c040470u: goto P_0c040470;
case 0x0c040472u: goto P_0c040472;
case 0x0c040474u: goto P_0c040474;
case 0x0c040476u: goto P_0c040476;
case 0x0c040478u: goto P_0c040478;
case 0x0c04047au: goto P_0c04047a;
case 0x0c04047cu: goto P_0c04047c;
case 0x0c04047eu: goto P_0c04047e;
case 0x0c040480u: goto P_0c040480;
case 0x0c040482u: goto P_0c040482;
case 0x0c0406b2u: goto P_0c0406b2;
case 0x0c0406b4u: goto P_0c0406b4;
case 0x0c0406b6u: goto P_0c0406b6;
case 0x0c0406b8u: goto P_0c0406b8;
case 0x0c0406bau: goto P_0c0406ba;
case 0x0c0406bcu: goto P_0c0406bc;
case 0x0c0406beu: goto P_0c0406be;
case 0x0c0406c0u: goto P_0c0406c0;
case 0x0c0406c2u: goto P_0c0406c2;
case 0x0c0406c4u: goto P_0c0406c4;
case 0x0c0406c6u: goto P_0c0406c6;
case 0x0c0406c8u: goto P_0c0406c8;
case 0x0c0406cau: goto P_0c0406ca;
case 0x0c0406ccu: goto P_0c0406cc;
case 0x0c0406ceu: goto P_0c0406ce;
case 0x0c0406d0u: goto P_0c0406d0;
case 0x0c0406d2u: goto P_0c0406d2;
case 0x0c0406d4u: goto P_0c0406d4;
case 0x0c0406d6u: goto P_0c0406d6;
case 0x0c0406d8u: goto P_0c0406d8;
case 0x0c0406dau: goto P_0c0406da;
case 0x0c0406dcu: goto P_0c0406dc;
case 0x0c0406deu: goto P_0c0406de;
case 0x0c0406e0u: goto P_0c0406e0;
case 0x0c0406e2u: goto P_0c0406e2;
case 0x0c0406e4u: goto P_0c0406e4;
case 0x0c0406e6u: goto P_0c0406e6;
case 0x0c0406e8u: goto P_0c0406e8;
case 0x0c0406eau: goto P_0c0406ea;
case 0x0c0406ecu: goto P_0c0406ec;
case 0x0c0406eeu: goto P_0c0406ee;
case 0x0c0406f0u: goto P_0c0406f0;
case 0x0c0406f2u: goto P_0c0406f2;
case 0x0c0406f4u: goto P_0c0406f4;
case 0x0c0406f6u: goto P_0c0406f6;
case 0x0c0406f8u: goto P_0c0406f8;
case 0x0c0406fau: goto P_0c0406fa;
case 0x0c0406fcu: goto P_0c0406fc;
case 0x0c0406feu: goto P_0c0406fe;
case 0x0c040700u: goto P_0c040700;
case 0x0c040702u: goto P_0c040702;
case 0x0c040704u: goto P_0c040704;
case 0x0c040706u: goto P_0c040706;
case 0x0c040708u: goto P_0c040708;
case 0x0c04070au: goto P_0c04070a;
case 0x0c040714u: goto P_0c040714;
case 0x0c040716u: goto P_0c040716;
case 0x0c040718u: goto P_0c040718;
case 0x0c04071au: goto P_0c04071a;
case 0x0c04071cu: goto P_0c04071c;
case 0x0c04071eu: goto P_0c04071e;
case 0x0c040720u: goto P_0c040720;
case 0x0c040722u: goto P_0c040722;
case 0x0c040724u: goto P_0c040724;
case 0x0c040726u: goto P_0c040726;
case 0x0c040728u: goto P_0c040728;
case 0x0c04072au: goto P_0c04072a;
case 0x0c04072cu: goto P_0c04072c;
case 0x0c04072eu: goto P_0c04072e;
case 0x0c040730u: goto P_0c040730;
case 0x0c040732u: goto P_0c040732;
case 0x0c040734u: goto P_0c040734;
case 0x0c040736u: goto P_0c040736;
case 0x0c040738u: goto P_0c040738;
case 0x0c04073au: goto P_0c04073a;
case 0x0c04073cu: goto P_0c04073c;
case 0x0c04073eu: goto P_0c04073e;
case 0x0c040740u: goto P_0c040740;
case 0x0c040742u: goto P_0c040742;
case 0x0c040744u: goto P_0c040744;
case 0x0c040746u: goto P_0c040746;
case 0x0c040748u: goto P_0c040748;
case 0x0c04074au: goto P_0c04074a;
case 0x0c04074cu: goto P_0c04074c;
case 0x0c04074eu: goto P_0c04074e;
case 0x0c040750u: goto P_0c040750;
case 0x0c040752u: goto P_0c040752;
case 0x0c040754u: goto P_0c040754;
case 0x0c040756u: goto P_0c040756;
case 0x0c040758u: goto P_0c040758;
case 0x0c04075au: goto P_0c04075a;
case 0x0c04075cu: goto P_0c04075c;
case 0x0c04075eu: goto P_0c04075e;
case 0x0c040760u: goto P_0c040760;
case 0x0c040762u: goto P_0c040762;
case 0x0c040764u: goto P_0c040764;
case 0x0c040766u: goto P_0c040766;
case 0x0c040768u: goto P_0c040768;
case 0x0c04076au: goto P_0c04076a;
case 0x0c04076cu: goto P_0c04076c;
case 0x0c04076eu: goto P_0c04076e;
case 0x0c040770u: goto P_0c040770;
case 0x0c040772u: goto P_0c040772;
case 0x0c040774u: goto P_0c040774;
case 0x0c040776u: goto P_0c040776;
case 0x0c040778u: goto P_0c040778;
case 0x0c04077au: goto P_0c04077a;
case 0x0c04077cu: goto P_0c04077c;
case 0x0c04077eu: goto P_0c04077e;
case 0x0c040780u: goto P_0c040780;
case 0x0c040782u: goto P_0c040782;
case 0x0c040784u: goto P_0c040784;
case 0x0c040786u: goto P_0c040786;
case 0x0c040788u: goto P_0c040788;
case 0x0c04078au: goto P_0c04078a;
case 0x0c04078cu: goto P_0c04078c;
case 0x0c04078eu: goto P_0c04078e;
case 0x0c040790u: goto P_0c040790;
case 0x0c040792u: goto P_0c040792;
case 0x0c040794u: goto P_0c040794;
case 0x0c040796u: goto P_0c040796;
case 0x0c040798u: goto P_0c040798;
case 0x0c04079au: goto P_0c04079a;
case 0x0c04079cu: goto P_0c04079c;
case 0x0c04079eu: goto P_0c04079e;
case 0x0c0407b0u: goto P_0c0407b0;
case 0x0c0407b2u: goto P_0c0407b2;
case 0x0c0407b4u: goto P_0c0407b4;
case 0x0c0407b6u: goto P_0c0407b6;
case 0x0c0407b8u: goto P_0c0407b8;
case 0x0c0407bau: goto P_0c0407ba;
case 0x0c0407bcu: goto P_0c0407bc;
case 0x0c0407beu: goto P_0c0407be;
case 0x0c0407c0u: goto P_0c0407c0;
case 0x0c0407c2u: goto P_0c0407c2;
case 0x0c0407c4u: goto P_0c0407c4;
case 0x0c0407c6u: goto P_0c0407c6;
case 0x0c0407c8u: goto P_0c0407c8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c040392: /* original 60f2, guest PC 0x0c040392 */
if(!s->budget--) { s->failed_pc=0x0c040392u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c040394;
P_0c040394: /* original 6303, guest PC 0x0c040394 */
if(!s->budget--) { s->failed_pc=0x0c040394u; return 0; }
r[3]=r[0];
goto P_0c040396;
P_0c040396: /* original 4000, guest PC 0x0c040396 */
if(!s->budget--) { s->failed_pc=0x0c040396u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c040398;
P_0c040398: /* original 303c, guest PC 0x0c040398 */
if(!s->budget--) { s->failed_pc=0x0c040398u; return 0; }
r[0]+=r[3];
goto P_0c04039a;
P_0c04039a: /* original 4008, guest PC 0x0c04039a */
if(!s->budget--) { s->failed_pc=0x0c04039au; return 0; }
r[0]<<=2;
goto P_0c04039c;
P_0c04039c: /* original 600e, guest PC 0x0c04039c */
if(!s->budget--) { s->failed_pc=0x0c04039cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c04039e;
P_0c04039e: /* original d107, guest PC 0x0c04039e */
if(!s->budget--) { s->failed_pc=0x0c04039eu; return 0; }
r[1]=read(ram,0x0c0403bcu,4);
goto P_0c0403a0;
P_0c0403a0: /* original 001e, guest PC 0x0c0403a0 */
if(!s->budget--) { s->failed_pc=0x0c0403a0u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c0403a2;
P_0c0403a2: /* original 88ff, guest PC 0x0c0403a2 */
if(!s->budget--) { s->failed_pc=0x0c0403a2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0403a4;
P_0c0403a4: /* original 8b03, guest PC 0x0c0403a4 */
if(!s->budget--) { s->failed_pc=0x0c0403a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0403ae; }
goto P_0c0403a6;
P_0c0403a6: /* original e0fe, guest PC 0x0c0403a6 */
if(!s->budget--) { s->failed_pc=0x0c0403a6u; return 0; }
r[0]=0xfffffffeu;
goto P_0c0403a8;
P_0c0403a8: /* original 7f04, guest PC 0x0c0403a8 */
if(!s->budget--) { s->failed_pc=0x0c0403a8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0403aa;
P_0c0403aa: /* original 000b, guest PC 0x0c0403aa */
if(!s->budget--) { s->failed_pc=0x0c0403aau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0403ac: /* original 0009, guest PC 0x0c0403ac */
if(!s->budget--) { s->failed_pc=0x0c0403acu; return 0; }
goto P_0c0403ae;
P_0c0403ae: /* original e000, guest PC 0x0c0403ae */
if(!s->budget--) { s->failed_pc=0x0c0403aeu; return 0; }
r[0]=0x00000000u;
goto P_0c0403b0;
P_0c0403b0: /* original 7f04, guest PC 0x0c0403b0 */
if(!s->budget--) { s->failed_pc=0x0c0403b0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0403b2;
P_0c0403b2: /* original 000b, guest PC 0x0c0403b2 */
if(!s->budget--) { s->failed_pc=0x0c0403b2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0403b4: /* original 0009, guest PC 0x0c0403b4 */
if(!s->budget--) { s->failed_pc=0x0c0403b4u; return 0; }
if(!vf3_matrix_family(0x0c0403b6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0403b6u; return 0; } return 1;
P_0c0403c0: /* original 7fe8, guest PC 0x0c0403c0 */
if(!s->budget--) { s->failed_pc=0x0c0403c0u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0403c2;
P_0c0403c2: /* original 1f45, guest PC 0x0c0403c2 */
if(!s->budget--) { s->failed_pc=0x0c0403c2u; return 0; }
write(ram,r[15]+20,r[4],4);
goto P_0c0403c4;
P_0c0403c4: /* original 1f54, guest PC 0x0c0403c4 */
if(!s->budget--) { s->failed_pc=0x0c0403c4u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c0403c6;
P_0c0403c6: /* original 1f63, guest PC 0x0c0403c6 */
if(!s->budget--) { s->failed_pc=0x0c0403c6u; return 0; }
write(ram,r[15]+12,r[6],4);
goto P_0c0403c8;
P_0c0403c8: /* original d20e, guest PC 0x0c0403c8 */
if(!s->budget--) { s->failed_pc=0x0c0403c8u; return 0; }
r[2]=read(ram,0x0c040404u,4);
goto P_0c0403ca;
P_0c0403ca: /* original 53f4, guest PC 0x0c0403ca */
if(!s->budget--) { s->failed_pc=0x0c0403cau; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c0403cc;
P_0c0403cc: /* original 6122, guest PC 0x0c0403cc */
if(!s->budget--) { s->failed_pc=0x0c0403ccu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0403ce;
P_0c0403ce: /* original 3138, guest PC 0x0c0403ce */
if(!s->budget--) { s->failed_pc=0x0c0403ceu; return 0; }
r[1]-=r[3];
goto P_0c0403d0;
P_0c0403d0: /* original 2212, guest PC 0x0c0403d0 */
if(!s->budget--) { s->failed_pc=0x0c0403d0u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c0403d2;
P_0c0403d2: /* original 52f5, guest PC 0x0c0403d2 */
if(!s->budget--) { s->failed_pc=0x0c0403d2u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c0403d4;
P_0c0403d4: /* original 6023, guest PC 0x0c0403d4 */
if(!s->budget--) { s->failed_pc=0x0c0403d4u; return 0; }
r[0]=r[2];
goto P_0c0403d6;
P_0c0403d6: /* original 0009, guest PC 0x0c0403d6 */
if(!s->budget--) { s->failed_pc=0x0c0403d6u; return 0; }
goto P_0c0403d8;
P_0c0403d8: /* original 4200, guest PC 0x0c0403d8 */
if(!s->budget--) { s->failed_pc=0x0c0403d8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0403da;
P_0c0403da: /* original 320c, guest PC 0x0c0403da */
if(!s->budget--) { s->failed_pc=0x0c0403dau; return 0; }
r[2]+=r[0];
goto P_0c0403dc;
P_0c0403dc: /* original 4208, guest PC 0x0c0403dc */
if(!s->budget--) { s->failed_pc=0x0c0403dcu; return 0; }
r[2]<<=2;
goto P_0c0403de;
P_0c0403de: /* original 622e, guest PC 0x0c0403de */
if(!s->budget--) { s->failed_pc=0x0c0403deu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[2];
goto P_0c0403e0;
P_0c0403e0: /* original e3ff, guest PC 0x0c0403e0 */
if(!s->budget--) { s->failed_pc=0x0c0403e0u; return 0; }
r[3]=0xffffffffu;
goto P_0c0403e2;
P_0c0403e2: /* original d009, guest PC 0x0c0403e2 */
if(!s->budget--) { s->failed_pc=0x0c0403e2u; return 0; }
r[0]=read(ram,0x0c040408u,4);
goto P_0c0403e4;
P_0c0403e4: /* original 0236, guest PC 0x0c0403e4 */
if(!s->budget--) { s->failed_pc=0x0c0403e4u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0403e6;
P_0c0403e6: /* original 52f5, guest PC 0x0c0403e6 */
if(!s->budget--) { s->failed_pc=0x0c0403e6u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c0403e8;
P_0c0403e8: /* original 4208, guest PC 0x0c0403e8 */
if(!s->budget--) { s->failed_pc=0x0c0403e8u; return 0; }
r[2]<<=2;
goto P_0c0403ea;
P_0c0403ea: /* original d308, guest PC 0x0c0403ea */
if(!s->budget--) { s->failed_pc=0x0c0403eau; return 0; }
r[3]=read(ram,0x0c04040cu,4);
goto P_0c0403ec;
P_0c0403ec: /* original 323c, guest PC 0x0c0403ec */
if(!s->budget--) { s->failed_pc=0x0c0403ecu; return 0; }
r[2]+=r[3];
goto P_0c0403ee;
P_0c0403ee: /* original e1ff, guest PC 0x0c0403ee */
if(!s->budget--) { s->failed_pc=0x0c0403eeu; return 0; }
r[1]=0xffffffffu;
goto P_0c0403f0;
P_0c0403f0: /* original 2212, guest PC 0x0c0403f0 */
if(!s->budget--) { s->failed_pc=0x0c0403f0u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c0403f2;
P_0c0403f2: /* original e200, guest PC 0x0c0403f2 */
if(!s->budget--) { s->failed_pc=0x0c0403f2u; return 0; }
r[2]=0x00000000u;
goto P_0c0403f4;
P_0c0403f4: /* original 1f22, guest PC 0x0c0403f4 */
if(!s->budget--) { s->failed_pc=0x0c0403f4u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0403f6;
P_0c0403f6: /* original 2f22, guest PC 0x0c0403f6 */
if(!s->budget--) { s->failed_pc=0x0c0403f6u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0403f8;
P_0c0403f8: /* original 51f5, guest PC 0x0c0403f8 */
if(!s->budget--) { s->failed_pc=0x0c0403f8u; return 0; }
r[1]=read(ram,r[15]+20,4);
goto P_0c0403fa;
P_0c0403fa: /* original 7101, guest PC 0x0c0403fa */
if(!s->budget--) { s->failed_pc=0x0c0403fau; return 0; }
r[1]+=0x00000001u;
goto P_0c0403fc;
P_0c0403fc: /* original 1f11, guest PC 0x0c0403fc */
if(!s->budget--) { s->failed_pc=0x0c0403fcu; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0403fe;
P_0c0403fe: /* original a036, guest PC 0x0c0403fe */
if(!s->budget--) { s->failed_pc=0x0c0403feu; return 0; }
goto P_0c04046e;
P_0c040400: /* original 0009, guest PC 0x0c040400 */
if(!s->budget--) { s->failed_pc=0x0c040400u; return 0; }
if(!vf3_matrix_family(0x0c040402u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040402u; return 0; } return 1;
P_0c040410: /* original 84f4, guest PC 0x0c040410 */
if(!s->budget--) { s->failed_pc=0x0c040410u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c040412;
P_0c040412: /* original 6303, guest PC 0x0c040412 */
if(!s->budget--) { s->failed_pc=0x0c040412u; return 0; }
r[3]=r[0];
goto P_0c040414;
P_0c040414: /* original 4000, guest PC 0x0c040414 */
if(!s->budget--) { s->failed_pc=0x0c040414u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c040416;
P_0c040416: /* original 303c, guest PC 0x0c040416 */
if(!s->budget--) { s->failed_pc=0x0c040416u; return 0; }
r[0]+=r[3];
goto P_0c040418;
P_0c040418: /* original 4008, guest PC 0x0c040418 */
if(!s->budget--) { s->failed_pc=0x0c040418u; return 0; }
r[0]<<=2;
goto P_0c04041a;
P_0c04041a: /* original 600e, guest PC 0x0c04041a */
if(!s->budget--) { s->failed_pc=0x0c04041au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c04041c;
P_0c04041c: /* original d11b, guest PC 0x0c04041c */
if(!s->budget--) { s->failed_pc=0x0c04041cu; return 0; }
r[1]=read(ram,0x0c04048cu,4);
goto P_0c04041e;
P_0c04041e: /* original 001e, guest PC 0x0c04041e */
if(!s->budget--) { s->failed_pc=0x0c04041eu; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c040420;
P_0c040420: /* original 88ff, guest PC 0x0c040420 */
if(!s->budget--) { s->failed_pc=0x0c040420u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c040422;
P_0c040422: /* original 8921, guest PC 0x0c040422 */
if(!s->budget--) { s->failed_pc=0x0c040422u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040468; }
goto P_0c040424;
P_0c040424: /* original 62f2, guest PC 0x0c040424 */
if(!s->budget--) { s->failed_pc=0x0c040424u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c040426;
P_0c040426: /* original 2228, guest PC 0x0c040426 */
if(!s->budget--) { s->failed_pc=0x0c040426u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c040428;
P_0c040428: /* original 8b08, guest PC 0x0c040428 */
if(!s->budget--) { s->failed_pc=0x0c040428u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04043c; }
goto P_0c04042a;
P_0c04042a: /* original 53f1, guest PC 0x0c04042a */
if(!s->budget--) { s->failed_pc=0x0c04042au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c04042c;
P_0c04042c: /* original 6233, guest PC 0x0c04042c */
if(!s->budget--) { s->failed_pc=0x0c04042cu; return 0; }
r[2]=r[3];
goto P_0c04042e;
P_0c04042e: /* original 4300, guest PC 0x0c04042e */
if(!s->budget--) { s->failed_pc=0x0c04042eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c040430;
P_0c040430: /* original 332c, guest PC 0x0c040430 */
if(!s->budget--) { s->failed_pc=0x0c040430u; return 0; }
r[3]+=r[2];
goto P_0c040432;
P_0c040432: /* original 4308, guest PC 0x0c040432 */
if(!s->budget--) { s->failed_pc=0x0c040432u; return 0; }
r[3]<<=2;
goto P_0c040434;
P_0c040434: /* original 633e, guest PC 0x0c040434 */
if(!s->budget--) { s->failed_pc=0x0c040434u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c040436;
P_0c040436: /* original d016, guest PC 0x0c040436 */
if(!s->budget--) { s->failed_pc=0x0c040436u; return 0; }
r[0]=read(ram,0x0c040490u,4);
goto P_0c040438;
P_0c040438: /* original 003e, guest PC 0x0c040438 */
if(!s->budget--) { s->failed_pc=0x0c040438u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c04043a;
P_0c04043a: /* original 2f02, guest PC 0x0c04043a */
if(!s->budget--) { s->failed_pc=0x0c04043au; return 0; }
write(ram,r[15],r[0],4);
goto P_0c04043c;
P_0c04043c: /* original 53f1, guest PC 0x0c04043c */
if(!s->budget--) { s->failed_pc=0x0c04043cu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c04043e;
P_0c04043e: /* original 6233, guest PC 0x0c04043e */
if(!s->budget--) { s->failed_pc=0x0c04043eu; return 0; }
r[2]=r[3];
goto P_0c040440;
P_0c040440: /* original 4300, guest PC 0x0c040440 */
if(!s->budget--) { s->failed_pc=0x0c040440u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c040442;
P_0c040442: /* original 332c, guest PC 0x0c040442 */
if(!s->budget--) { s->failed_pc=0x0c040442u; return 0; }
r[3]+=r[2];
goto P_0c040444;
P_0c040444: /* original 4308, guest PC 0x0c040444 */
if(!s->budget--) { s->failed_pc=0x0c040444u; return 0; }
r[3]<<=2;
goto P_0c040446;
P_0c040446: /* original 633e, guest PC 0x0c040446 */
if(!s->budget--) { s->failed_pc=0x0c040446u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c040448;
P_0c040448: /* original d012, guest PC 0x0c040448 */
if(!s->budget--) { s->failed_pc=0x0c040448u; return 0; }
r[0]=read(ram,0x0c040494u,4);
goto P_0c04044a;
P_0c04044a: /* original 033e, guest PC 0x0c04044a */
if(!s->budget--) { s->failed_pc=0x0c04044au; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c04044c;
P_0c04044c: /* original 52f2, guest PC 0x0c04044c */
if(!s->budget--) { s->failed_pc=0x0c04044cu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c04044e;
P_0c04044e: /* original 323c, guest PC 0x0c04044e */
if(!s->budget--) { s->failed_pc=0x0c04044eu; return 0; }
r[2]+=r[3];
goto P_0c040450;
P_0c040450: /* original 1f22, guest PC 0x0c040450 */
if(!s->budget--) { s->failed_pc=0x0c040450u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c040452;
P_0c040452: /* original 51f1, guest PC 0x0c040452 */
if(!s->budget--) { s->failed_pc=0x0c040452u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c040454;
P_0c040454: /* original 6313, guest PC 0x0c040454 */
if(!s->budget--) { s->failed_pc=0x0c040454u; return 0; }
r[3]=r[1];
goto P_0c040456;
P_0c040456: /* original 4100, guest PC 0x0c040456 */
if(!s->budget--) { s->failed_pc=0x0c040456u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c040458;
P_0c040458: /* original 313c, guest PC 0x0c040458 */
if(!s->budget--) { s->failed_pc=0x0c040458u; return 0; }
r[1]+=r[3];
goto P_0c04045a;
P_0c04045a: /* original 4108, guest PC 0x0c04045a */
if(!s->budget--) { s->failed_pc=0x0c04045au; return 0; }
r[1]<<=2;
goto P_0c04045c;
P_0c04045c: /* original 611e, guest PC 0x0c04045c */
if(!s->budget--) { s->failed_pc=0x0c04045cu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)r[1];
goto P_0c04045e;
P_0c04045e: /* original d00c, guest PC 0x0c04045e */
if(!s->budget--) { s->failed_pc=0x0c04045eu; return 0; }
r[0]=read(ram,0x0c040490u,4);
goto P_0c040460;
P_0c040460: /* original 53f4, guest PC 0x0c040460 */
if(!s->budget--) { s->failed_pc=0x0c040460u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c040462;
P_0c040462: /* original 021e, guest PC 0x0c040462 */
if(!s->budget--) { s->failed_pc=0x0c040462u; return 0; }
r[2]=read(ram,r[1]+r[0],4);
goto P_0c040464;
P_0c040464: /* original 3238, guest PC 0x0c040464 */
if(!s->budget--) { s->failed_pc=0x0c040464u; return 0; }
r[2]-=r[3];
goto P_0c040466;
P_0c040466: /* original 0126, guest PC 0x0c040466 */
if(!s->budget--) { s->failed_pc=0x0c040466u; return 0; }
write(ram,r[1]+r[0],r[2],4);
goto P_0c040468;
P_0c040468: /* original 51f1, guest PC 0x0c040468 */
if(!s->budget--) { s->failed_pc=0x0c040468u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c04046a;
P_0c04046a: /* original 7101, guest PC 0x0c04046a */
if(!s->budget--) { s->failed_pc=0x0c04046au; return 0; }
r[1]+=0x00000001u;
goto P_0c04046c;
P_0c04046c: /* original 1f11, guest PC 0x0c04046c */
if(!s->budget--) { s->failed_pc=0x0c04046cu; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c04046e;
P_0c04046e: /* original e308, guest PC 0x0c04046e */
if(!s->budget--) { s->failed_pc=0x0c04046eu; return 0; }
r[3]=0x00000008u;
goto P_0c040470;
P_0c040470: /* original 52f1, guest PC 0x0c040470 */
if(!s->budget--) { s->failed_pc=0x0c040470u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c040472;
P_0c040472: /* original 3233, guest PC 0x0c040472 */
if(!s->budget--) { s->failed_pc=0x0c040472u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c040474;
P_0c040474: /* original 8bcc, guest PC 0x0c040474 */
if(!s->budget--) { s->failed_pc=0x0c040474u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040410; }
goto P_0c040476;
P_0c040476: /* original 53f3, guest PC 0x0c040476 */
if(!s->budget--) { s->failed_pc=0x0c040476u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c040478;
P_0c040478: /* original 52f2, guest PC 0x0c040478 */
if(!s->budget--) { s->failed_pc=0x0c040478u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c04047a;
P_0c04047a: /* original 2322, guest PC 0x0c04047a */
if(!s->budget--) { s->failed_pc=0x0c04047au; return 0; }
write(ram,r[3],r[2],4);
goto P_0c04047c;
P_0c04047c: /* original 60f2, guest PC 0x0c04047c */
if(!s->budget--) { s->failed_pc=0x0c04047cu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c04047e;
P_0c04047e: /* original 7f18, guest PC 0x0c04047e */
if(!s->budget--) { s->failed_pc=0x0c04047eu; return 0; }
r[15]+=0x00000018u;
goto P_0c040480;
P_0c040480: /* original 000b, guest PC 0x0c040480 */
if(!s->budget--) { s->failed_pc=0x0c040480u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040482: /* original 0009, guest PC 0x0c040482 */
if(!s->budget--) { s->failed_pc=0x0c040482u; return 0; }
if(!vf3_matrix_family(0x0c040484u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040484u; return 0; } return 1;
P_0c0406b2: /* original 2fe6, guest PC 0x0c0406b2 */
if(!s->budget--) { s->failed_pc=0x0c0406b2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0406b4;
P_0c0406b4: /* original 2fd6, guest PC 0x0c0406b4 */
if(!s->budget--) { s->failed_pc=0x0c0406b4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0406b6;
P_0c0406b6: /* original 2fc6, guest PC 0x0c0406b6 */
if(!s->budget--) { s->failed_pc=0x0c0406b6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0406b8;
P_0c0406b8: /* original 4f22, guest PC 0x0c0406b8 */
if(!s->budget--) { s->failed_pc=0x0c0406b8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0406ba;
P_0c0406ba: /* original 7fe4, guest PC 0x0c0406ba */
if(!s->budget--) { s->failed_pc=0x0c0406bau; return 0; }
r[15]+=0xffffffe4u;
goto P_0c0406bc;
P_0c0406bc: /* original 1f46, guest PC 0x0c0406bc */
if(!s->budget--) { s->failed_pc=0x0c0406bcu; return 0; }
write(ram,r[15]+24,r[4],4);
goto P_0c0406be;
P_0c0406be: /* original 1f55, guest PC 0x0c0406be */
if(!s->budget--) { s->failed_pc=0x0c0406beu; return 0; }
write(ram,r[15]+20,r[5],4);
goto P_0c0406c0;
P_0c0406c0: /* original 55f5, guest PC 0x0c0406c0 */
if(!s->budget--) { s->failed_pc=0x0c0406c0u; return 0; }
r[5]=read(ram,r[15]+20,4);
goto P_0c0406c2;
P_0c0406c2: /* original 54f6, guest PC 0x0c0406c2 */
if(!s->budget--) { s->failed_pc=0x0c0406c2u; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c0406c4;
P_0c0406c4: /* original bd46, guest PC 0x0c0406c4 */
if(!s->budget--) { s->failed_pc=0x0c0406c4u; return 0; }
target=code_base|0x0c040154u; r[16]=code_base|0x0c0406c8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0406c8u) { target=s->pc; goto dispatch; }
goto P_0c0406c8;
P_0c0406c6: /* original 0009, guest PC 0x0c0406c6 */
if(!s->budget--) { s->failed_pc=0x0c0406c6u; return 0; }
goto P_0c0406c8;
P_0c0406c8: /* original 1f01, guest PC 0x0c0406c8 */
if(!s->budget--) { s->failed_pc=0x0c0406c8u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0406ca;
P_0c0406ca: /* original 2008, guest PC 0x0c0406ca */
if(!s->budget--) { s->failed_pc=0x0c0406cau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0406cc;
P_0c0406cc: /* original 8901, guest PC 0x0c0406cc */
if(!s->budget--) { s->failed_pc=0x0c0406ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0406d2; }
goto P_0c0406ce;
P_0c0406ce: /* original a075, guest PC 0x0c0406ce */
if(!s->budget--) { s->failed_pc=0x0c0406ceu; return 0; }
goto P_0c0407bc;
P_0c0406d0: /* original 0009, guest PC 0x0c0406d0 */
if(!s->budget--) { s->failed_pc=0x0c0406d0u; return 0; }
goto P_0c0406d2;
P_0c0406d2: /* original 52f6, guest PC 0x0c0406d2 */
if(!s->budget--) { s->failed_pc=0x0c0406d2u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c0406d4;
P_0c0406d4: /* original 5322, guest PC 0x0c0406d4 */
if(!s->budget--) { s->failed_pc=0x0c0406d4u; return 0; }
r[3]=read(ram,r[2]+8,4);
goto P_0c0406d6;
P_0c0406d6: /* original 1f33, guest PC 0x0c0406d6 */
if(!s->budget--) { s->failed_pc=0x0c0406d6u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0406d8;
P_0c0406d8: /* original 5121, guest PC 0x0c0406d8 */
if(!s->budget--) { s->failed_pc=0x0c0406d8u; return 0; }
r[1]=read(ram,r[2]+4,4);
goto P_0c0406da;
P_0c0406da: /* original 1f12, guest PC 0x0c0406da */
if(!s->budget--) { s->failed_pc=0x0c0406dau; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c0406dc;
P_0c0406dc: /* original 67f3, guest PC 0x0c0406dc */
if(!s->budget--) { s->failed_pc=0x0c0406dcu; return 0; }
r[7]=r[15];
goto P_0c0406de;
P_0c0406de: /* original 56f3, guest PC 0x0c0406de */
if(!s->budget--) { s->failed_pc=0x0c0406deu; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c0406e0;
P_0c0406e0: /* original 55f2, guest PC 0x0c0406e0 */
if(!s->budget--) { s->failed_pc=0x0c0406e0u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0406e2;
P_0c0406e2: /* original 54f5, guest PC 0x0c0406e2 */
if(!s->budget--) { s->failed_pc=0x0c0406e2u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c0406e4;
P_0c0406e4: /* original bd9d, guest PC 0x0c0406e4 */
if(!s->budget--) { s->failed_pc=0x0c0406e4u; return 0; }
target=code_base|0x0c040222u; r[16]=code_base|0x0c0406e8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0406e8u) { target=s->pc; goto dispatch; }
goto P_0c0406e8;
P_0c0406e6: /* original 0009, guest PC 0x0c0406e6 */
if(!s->budget--) { s->failed_pc=0x0c0406e6u; return 0; }
goto P_0c0406e8;
P_0c0406e8: /* original 1f04, guest PC 0x0c0406e8 */
if(!s->budget--) { s->failed_pc=0x0c0406e8u; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c0406ea;
P_0c0406ea: /* original ee00, guest PC 0x0c0406ea */
if(!s->budget--) { s->failed_pc=0x0c0406eau; return 0; }
r[14]=0x00000000u;
goto P_0c0406ec;
P_0c0406ec: /* original a008, guest PC 0x0c0406ec */
if(!s->budget--) { s->failed_pc=0x0c0406ecu; return 0; }
goto P_0c040700;
P_0c0406ee: /* original 0009, guest PC 0x0c0406ee */
if(!s->budget--) { s->failed_pc=0x0c0406eeu; return 0; }
goto P_0c0406f0;
P_0c0406f0: /* original 940c, guest PC 0x0c0406f0 */
if(!s->budget--) { s->failed_pc=0x0c0406f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04070cu,2);
goto P_0c0406f2;
P_0c0406f2: /* original b414, guest PC 0x0c0406f2 */
if(!s->budget--) { s->failed_pc=0x0c0406f2u; return 0; }
target=code_base|0x0c040f1eu; r[16]=code_base|0x0c0406f6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0406f6u) { target=s->pc; goto dispatch; }
goto P_0c0406f6;
P_0c0406f4: /* original 0009, guest PC 0x0c0406f4 */
if(!s->budget--) { s->failed_pc=0x0c0406f4u; return 0; }
goto P_0c0406f6;
P_0c0406f6: /* original 2008, guest PC 0x0c0406f6 */
if(!s->budget--) { s->failed_pc=0x0c0406f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0406f8;
P_0c0406f8: /* original 8b01, guest PC 0x0c0406f8 */
if(!s->budget--) { s->failed_pc=0x0c0406f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0406fe; }
goto P_0c0406fa;
P_0c0406fa: /* original a00b, guest PC 0x0c0406fa */
if(!s->budget--) { s->failed_pc=0x0c0406fau; return 0; }
goto P_0c040714;
P_0c0406fc: /* original 0009, guest PC 0x0c0406fc */
if(!s->budget--) { s->failed_pc=0x0c0406fcu; return 0; }
goto P_0c0406fe;
P_0c0406fe: /* original 7e01, guest PC 0x0c0406fe */
if(!s->budget--) { s->failed_pc=0x0c0406feu; return 0; }
r[14]+=0x00000001u;
goto P_0c040700;
P_0c040700: /* original d303, guest PC 0x0c040700 */
if(!s->budget--) { s->failed_pc=0x0c040700u; return 0; }
r[3]=read(ram,0x0c040710u,4);
goto P_0c040702;
P_0c040702: /* original 3e33, guest PC 0x0c040702 */
if(!s->budget--) { s->failed_pc=0x0c040702u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c040704;
P_0c040704: /* original 8bf4, guest PC 0x0c040704 */
if(!s->budget--) { s->failed_pc=0x0c040704u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0406f0; }
goto P_0c040706;
P_0c040706: /* original 9002, guest PC 0x0c040706 */
if(!s->budget--) { s->failed_pc=0x0c040706u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04070eu,2);
goto P_0c040708;
P_0c040708: /* original a058, guest PC 0x0c040708 */
if(!s->budget--) { s->failed_pc=0x0c040708u; return 0; }
goto P_0c0407bc;
P_0c04070a: /* original 0009, guest PC 0x0c04070a */
if(!s->budget--) { s->failed_pc=0x0c04070au; return 0; }
if(!vf3_matrix_family(0x0c04070cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04070cu; return 0; } return 1;
P_0c040714: /* original ee00, guest PC 0x0c040714 */
if(!s->budget--) { s->failed_pc=0x0c040714u; return 0; }
r[14]=0x00000000u;
goto P_0c040716;
P_0c040716: /* original a007, guest PC 0x0c040716 */
if(!s->budget--) { s->failed_pc=0x0c040716u; return 0; }
goto P_0c040728;
P_0c040718: /* original 0009, guest PC 0x0c040718 */
if(!s->budget--) { s->failed_pc=0x0c040718u; return 0; }
goto P_0c04071a;
P_0c04071a: /* original d322, guest PC 0x0c04071a */
if(!s->budget--) { s->failed_pc=0x0c04071au; return 0; }
r[3]=read(ram,0x0c0407a4u,4);
goto P_0c04071c;
P_0c04071c: /* original 6232, guest PC 0x0c04071c */
if(!s->budget--) { s->failed_pc=0x0c04071cu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c04071e;
P_0c04071e: /* original 2228, guest PC 0x0c04071e */
if(!s->budget--) { s->failed_pc=0x0c04071eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c040720;
P_0c040720: /* original 8901, guest PC 0x0c040720 */
if(!s->budget--) { s->failed_pc=0x0c040720u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040726; }
goto P_0c040722;
P_0c040722: /* original a007, guest PC 0x0c040722 */
if(!s->budget--) { s->failed_pc=0x0c040722u; return 0; }
goto P_0c040734;
P_0c040724: /* original 0009, guest PC 0x0c040724 */
if(!s->budget--) { s->failed_pc=0x0c040724u; return 0; }
goto P_0c040726;
P_0c040726: /* original 7e01, guest PC 0x0c040726 */
if(!s->budget--) { s->failed_pc=0x0c040726u; return 0; }
r[14]+=0x00000001u;
goto P_0c040728;
P_0c040728: /* original d31f, guest PC 0x0c040728 */
if(!s->budget--) { s->failed_pc=0x0c040728u; return 0; }
r[3]=read(ram,0x0c0407a8u,4);
goto P_0c04072a;
P_0c04072a: /* original 3e33, guest PC 0x0c04072a */
if(!s->budget--) { s->failed_pc=0x0c04072au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c04072c;
P_0c04072c: /* original 8bf5, guest PC 0x0c04072c */
if(!s->budget--) { s->failed_pc=0x0c04072cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04071a; }
goto P_0c04072e;
P_0c04072e: /* original 9037, guest PC 0x0c04072e */
if(!s->budget--) { s->failed_pc=0x0c04072eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0407a0u,2);
goto P_0c040730;
P_0c040730: /* original a044, guest PC 0x0c040730 */
if(!s->budget--) { s->failed_pc=0x0c040730u; return 0; }
goto P_0c0407bc;
P_0c040732: /* original 0009, guest PC 0x0c040732 */
if(!s->budget--) { s->failed_pc=0x0c040732u; return 0; }
goto P_0c040734;
P_0c040734: /* original 63f2, guest PC 0x0c040734 */
if(!s->budget--) { s->failed_pc=0x0c040734u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c040736;
P_0c040736: /* original 2338, guest PC 0x0c040736 */
if(!s->budget--) { s->failed_pc=0x0c040736u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c040738;
P_0c040738: /* original 8911, guest PC 0x0c040738 */
if(!s->budget--) { s->failed_pc=0x0c040738u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04075e; }
goto P_0c04073a;
P_0c04073a: /* original 66f2, guest PC 0x0c04073a */
if(!s->budget--) { s->failed_pc=0x0c04073au; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c04073c;
P_0c04073c: /* original 53f3, guest PC 0x0c04073c */
if(!s->budget--) { s->failed_pc=0x0c04073cu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c04073e;
P_0c04073e: /* original 55f4, guest PC 0x0c04073e */
if(!s->budget--) { s->failed_pc=0x0c04073eu; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c040740;
P_0c040740: /* original 353c, guest PC 0x0c040740 */
if(!s->budget--) { s->failed_pc=0x0c040740u; return 0; }
r[5]+=r[3];
goto P_0c040742;
P_0c040742: /* original 54f4, guest PC 0x0c040742 */
if(!s->budget--) { s->failed_pc=0x0c040742u; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c040744;
P_0c040744: /* original bcbc, guest PC 0x0c040744 */
if(!s->budget--) { s->failed_pc=0x0c040744u; return 0; }
target=code_base|0x0c0400c0u; r[16]=code_base|0x0c040748u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c040748u) { target=s->pc; goto dispatch; }
goto P_0c040748;
P_0c040746: /* original 0009, guest PC 0x0c040746 */
if(!s->budget--) { s->failed_pc=0x0c040746u; return 0; }
goto P_0c040748;
P_0c040748: /* original 1f01, guest PC 0x0c040748 */
if(!s->budget--) { s->failed_pc=0x0c040748u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c04074a;
P_0c04074a: /* original 2008, guest PC 0x0c04074a */
if(!s->budget--) { s->failed_pc=0x0c04074au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04074c;
P_0c04074c: /* original 8901, guest PC 0x0c04074c */
if(!s->budget--) { s->failed_pc=0x0c04074cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040752; }
goto P_0c04074e;
P_0c04074e: /* original a035, guest PC 0x0c04074e */
if(!s->budget--) { s->failed_pc=0x0c04074eu; return 0; }
goto P_0c0407bc;
P_0c040750: /* original 0009, guest PC 0x0c040750 */
if(!s->budget--) { s->failed_pc=0x0c040750u; return 0; }
goto P_0c040752;
P_0c040752: /* original a000, guest PC 0x0c040752 */
if(!s->budget--) { s->failed_pc=0x0c040752u; return 0; }
goto P_0c040756;
P_0c040754: /* original 0009, guest PC 0x0c040754 */
if(!s->budget--) { s->failed_pc=0x0c040754u; return 0; }
goto P_0c040756;
P_0c040756: /* original bcf1, guest PC 0x0c040756 */
if(!s->budget--) { s->failed_pc=0x0c040756u; return 0; }
target=code_base|0x0c04013cu; r[16]=code_base|0x0c04075au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04075au) { target=s->pc; goto dispatch; }
goto P_0c04075a;
P_0c040758: /* original 0009, guest PC 0x0c040758 */
if(!s->budget--) { s->failed_pc=0x0c040758u; return 0; }
goto P_0c04075a;
P_0c04075a: /* original 2008, guest PC 0x0c04075a */
if(!s->budget--) { s->failed_pc=0x0c04075au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04075c;
P_0c04075c: /* original 8bfb, guest PC 0x0c04075c */
if(!s->budget--) { s->failed_pc=0x0c04075cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040756; }
goto P_0c04075e;
P_0c04075e: /* original 5df6, guest PC 0x0c04075e */
if(!s->budget--) { s->failed_pc=0x0c04075eu; return 0; }
r[13]=read(ram,r[15]+24,4);
goto P_0c040760;
P_0c040760: /* original 5cf4, guest PC 0x0c040760 */
if(!s->budget--) { s->failed_pc=0x0c040760u; return 0; }
r[12]=read(ram,r[15]+16,4);
goto P_0c040762;
P_0c040762: /* original ee00, guest PC 0x0c040762 */
if(!s->budget--) { s->failed_pc=0x0c040762u; return 0; }
r[14]=0x00000000u;
goto P_0c040764;
P_0c040764: /* original a005, guest PC 0x0c040764 */
if(!s->budget--) { s->failed_pc=0x0c040764u; return 0; }
goto P_0c040772;
P_0c040766: /* original 0009, guest PC 0x0c040766 */
if(!s->budget--) { s->failed_pc=0x0c040766u; return 0; }
goto P_0c040768;
P_0c040768: /* original 62c3, guest PC 0x0c040768 */
if(!s->budget--) { s->failed_pc=0x0c040768u; return 0; }
r[2]=r[12];
goto P_0c04076a;
P_0c04076a: /* original 7c04, guest PC 0x0c04076a */
if(!s->budget--) { s->failed_pc=0x0c04076au; return 0; }
r[12]+=0x00000004u;
goto P_0c04076c;
P_0c04076c: /* original 63d6, guest PC 0x0c04076c */
if(!s->budget--) { s->failed_pc=0x0c04076cu; return 0; }
tmp=read(ram,r[13],4);
r[13]+=4;
r[3]=tmp;
goto P_0c04076e;
P_0c04076e: /* original 2232, guest PC 0x0c04076e */
if(!s->budget--) { s->failed_pc=0x0c04076eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c040770;
P_0c040770: /* original 7e01, guest PC 0x0c040770 */
if(!s->budget--) { s->failed_pc=0x0c040770u; return 0; }
r[14]+=0x00000001u;
goto P_0c040772;
P_0c040772: /* original 52f3, guest PC 0x0c040772 */
if(!s->budget--) { s->failed_pc=0x0c040772u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c040774;
P_0c040774: /* original 4209, guest PC 0x0c040774 */
if(!s->budget--) { s->failed_pc=0x0c040774u; return 0; }
r[2]>>=2;
goto P_0c040776;
P_0c040776: /* original 3e22, guest PC 0x0c040776 */
if(!s->budget--) { s->failed_pc=0x0c040776u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[2])!=0);
goto P_0c040778;
P_0c040778: /* original 8bf6, guest PC 0x0c040778 */
if(!s->budget--) { s->failed_pc=0x0c040778u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040768; }
goto P_0c04077a;
P_0c04077a: /* original e201, guest PC 0x0c04077a */
if(!s->budget--) { s->failed_pc=0x0c04077au; return 0; }
r[2]=0x00000001u;
goto P_0c04077c;
P_0c04077c: /* original d30b, guest PC 0x0c04077c */
if(!s->budget--) { s->failed_pc=0x0c04077cu; return 0; }
r[3]=read(ram,0x0c0407acu,4);
goto P_0c04077e;
P_0c04077e: /* original 2322, guest PC 0x0c04077e */
if(!s->budget--) { s->failed_pc=0x0c04077eu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c040780;
P_0c040780: /* original ee00, guest PC 0x0c040780 */
if(!s->budget--) { s->failed_pc=0x0c040780u; return 0; }
r[14]=0x00000000u;
goto P_0c040782;
P_0c040782: /* original a007, guest PC 0x0c040782 */
if(!s->budget--) { s->failed_pc=0x0c040782u; return 0; }
goto P_0c040794;
P_0c040784: /* original 0009, guest PC 0x0c040784 */
if(!s->budget--) { s->failed_pc=0x0c040784u; return 0; }
goto P_0c040786;
P_0c040786: /* original d207, guest PC 0x0c040786 */
if(!s->budget--) { s->failed_pc=0x0c040786u; return 0; }
r[2]=read(ram,0x0c0407a4u,4);
goto P_0c040788;
P_0c040788: /* original 6322, guest PC 0x0c040788 */
if(!s->budget--) { s->failed_pc=0x0c040788u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c04078a;
P_0c04078a: /* original 2338, guest PC 0x0c04078a */
if(!s->budget--) { s->failed_pc=0x0c04078au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04078c;
P_0c04078c: /* original 8b01, guest PC 0x0c04078c */
if(!s->budget--) { s->failed_pc=0x0c04078cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040792; }
goto P_0c04078e;
P_0c04078e: /* original a00f, guest PC 0x0c04078e */
if(!s->budget--) { s->failed_pc=0x0c04078eu; return 0; }
goto P_0c0407b0;
P_0c040790: /* original 0009, guest PC 0x0c040790 */
if(!s->budget--) { s->failed_pc=0x0c040790u; return 0; }
goto P_0c040792;
P_0c040792: /* original 7e01, guest PC 0x0c040792 */
if(!s->budget--) { s->failed_pc=0x0c040792u; return 0; }
r[14]+=0x00000001u;
goto P_0c040794;
P_0c040794: /* original d204, guest PC 0x0c040794 */
if(!s->budget--) { s->failed_pc=0x0c040794u; return 0; }
r[2]=read(ram,0x0c0407a8u,4);
goto P_0c040796;
P_0c040796: /* original 3e23, guest PC 0x0c040796 */
if(!s->budget--) { s->failed_pc=0x0c040796u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c040798;
P_0c040798: /* original 8bf5, guest PC 0x0c040798 */
if(!s->budget--) { s->failed_pc=0x0c040798u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040786; }
goto P_0c04079a;
P_0c04079a: /* original 9001, guest PC 0x0c04079a */
if(!s->budget--) { s->failed_pc=0x0c04079au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0407a0u,2);
goto P_0c04079c;
P_0c04079c: /* original a00e, guest PC 0x0c04079c */
if(!s->budget--) { s->failed_pc=0x0c04079cu; return 0; }
goto P_0c0407bc;
P_0c04079e: /* original 0009, guest PC 0x0c04079e */
if(!s->budget--) { s->failed_pc=0x0c04079eu; return 0; }
if(!vf3_matrix_family(0x0c0407a0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0407a0u; return 0; } return 1;
P_0c0407b0: /* original e200, guest PC 0x0c0407b0 */
if(!s->budget--) { s->failed_pc=0x0c0407b0u; return 0; }
r[2]=0x00000000u;
goto P_0c0407b2;
P_0c0407b2: /* original d30e, guest PC 0x0c0407b2 */
if(!s->budget--) { s->failed_pc=0x0c0407b2u; return 0; }
r[3]=read(ram,0x0c0407ecu,4);
goto P_0c0407b4;
P_0c0407b4: /* original 2322, guest PC 0x0c0407b4 */
if(!s->budget--) { s->failed_pc=0x0c0407b4u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0407b6;
P_0c0407b6: /* original e000, guest PC 0x0c0407b6 */
if(!s->budget--) { s->failed_pc=0x0c0407b6u; return 0; }
r[0]=0x00000000u;
goto P_0c0407b8;
P_0c0407b8: /* original a000, guest PC 0x0c0407b8 */
if(!s->budget--) { s->failed_pc=0x0c0407b8u; return 0; }
goto P_0c0407bc;
P_0c0407ba: /* original 0009, guest PC 0x0c0407ba */
if(!s->budget--) { s->failed_pc=0x0c0407bau; return 0; }
goto P_0c0407bc;
P_0c0407bc: /* original 7f1c, guest PC 0x0c0407bc */
if(!s->budget--) { s->failed_pc=0x0c0407bcu; return 0; }
r[15]+=0x0000001cu;
goto P_0c0407be;
P_0c0407be: /* original 4f26, guest PC 0x0c0407be */
if(!s->budget--) { s->failed_pc=0x0c0407beu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0407c0;
P_0c0407c0: /* original 6cf6, guest PC 0x0c0407c0 */
if(!s->budget--) { s->failed_pc=0x0c0407c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0407c2;
P_0c0407c2: /* original 6df6, guest PC 0x0c0407c2 */
if(!s->budget--) { s->failed_pc=0x0c0407c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0407c4;
P_0c0407c4: /* original 6ef6, guest PC 0x0c0407c4 */
if(!s->budget--) { s->failed_pc=0x0c0407c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0407c6;
P_0c0407c6: /* original 000b, guest PC 0x0c0407c6 */
if(!s->budget--) { s->failed_pc=0x0c0407c6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0407c8: /* original 0009, guest PC 0x0c0407c8 */
if(!s->budget--) { s->failed_pc=0x0c0407c8u; return 0; }
if(!vf3_matrix_family(0x0c0407cau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0407cau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
