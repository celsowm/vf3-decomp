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
int vf3_away_batch19_adapter_37(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a036cu: goto P_0c0a036c;
case 0x0c0a036eu: goto P_0c0a036e;
case 0x0c0a0370u: goto P_0c0a0370;
case 0x0c0a0372u: goto P_0c0a0372;
case 0x0c0a0374u: goto P_0c0a0374;
case 0x0c0a0376u: goto P_0c0a0376;
case 0x0c0a0378u: goto P_0c0a0378;
case 0x0c0a037au: goto P_0c0a037a;
case 0x0c0a037cu: goto P_0c0a037c;
case 0x0c0a037eu: goto P_0c0a037e;
case 0x0c0a0380u: goto P_0c0a0380;
case 0x0c0a0382u: goto P_0c0a0382;
case 0x0c0a0384u: goto P_0c0a0384;
case 0x0c0a0386u: goto P_0c0a0386;
case 0x0c0a0388u: goto P_0c0a0388;
case 0x0c0a038au: goto P_0c0a038a;
case 0x0c0a038cu: goto P_0c0a038c;
case 0x0c0a038eu: goto P_0c0a038e;
case 0x0c0a0390u: goto P_0c0a0390;
case 0x0c0a0392u: goto P_0c0a0392;
case 0x0c0a0394u: goto P_0c0a0394;
case 0x0c0a0396u: goto P_0c0a0396;
case 0x0c0a0398u: goto P_0c0a0398;
case 0x0c0a039au: goto P_0c0a039a;
case 0x0c0a039cu: goto P_0c0a039c;
case 0x0c0a039eu: goto P_0c0a039e;
case 0x0c0a03a0u: goto P_0c0a03a0;
case 0x0c0a03a2u: goto P_0c0a03a2;
case 0x0c0a03a4u: goto P_0c0a03a4;
case 0x0c0a03a6u: goto P_0c0a03a6;
case 0x0c0a03a8u: goto P_0c0a03a8;
case 0x0c0a03aau: goto P_0c0a03aa;
case 0x0c0a03acu: goto P_0c0a03ac;
case 0x0c0a03aeu: goto P_0c0a03ae;
case 0x0c0a03b0u: goto P_0c0a03b0;
case 0x0c0a03b2u: goto P_0c0a03b2;
case 0x0c0a03b4u: goto P_0c0a03b4;
case 0x0c0a03b6u: goto P_0c0a03b6;
case 0x0c0a03b8u: goto P_0c0a03b8;
case 0x0c0a03bau: goto P_0c0a03ba;
case 0x0c0a03bcu: goto P_0c0a03bc;
case 0x0c0a03beu: goto P_0c0a03be;
case 0x0c0a03c0u: goto P_0c0a03c0;
case 0x0c0a03c2u: goto P_0c0a03c2;
case 0x0c0a03c4u: goto P_0c0a03c4;
case 0x0c0a03c6u: goto P_0c0a03c6;
case 0x0c0a03c8u: goto P_0c0a03c8;
case 0x0c0a03cau: goto P_0c0a03ca;
case 0x0c0a03ccu: goto P_0c0a03cc;
case 0x0c0a03ceu: goto P_0c0a03ce;
case 0x0c0a03d0u: goto P_0c0a03d0;
case 0x0c0a03d2u: goto P_0c0a03d2;
case 0x0c0a03d4u: goto P_0c0a03d4;
case 0x0c0a03d6u: goto P_0c0a03d6;
case 0x0c0a03d8u: goto P_0c0a03d8;
case 0x0c0a03dau: goto P_0c0a03da;
case 0x0c0a03dcu: goto P_0c0a03dc;
case 0x0c0a03deu: goto P_0c0a03de;
case 0x0c0a03e0u: goto P_0c0a03e0;
case 0x0c0a03e2u: goto P_0c0a03e2;
case 0x0c0a03e4u: goto P_0c0a03e4;
case 0x0c0a03e6u: goto P_0c0a03e6;
case 0x0c0a03e8u: goto P_0c0a03e8;
case 0x0c0a03eau: goto P_0c0a03ea;
case 0x0c0a03ecu: goto P_0c0a03ec;
case 0x0c0a03eeu: goto P_0c0a03ee;
case 0x0c0a03f0u: goto P_0c0a03f0;
case 0x0c0a03f2u: goto P_0c0a03f2;
case 0x0c0a03f4u: goto P_0c0a03f4;
case 0x0c0a03f6u: goto P_0c0a03f6;
case 0x0c0a03f8u: goto P_0c0a03f8;
case 0x0c0a03fau: goto P_0c0a03fa;
case 0x0c0a03fcu: goto P_0c0a03fc;
case 0x0c0a03feu: goto P_0c0a03fe;
case 0x0c0a0400u: goto P_0c0a0400;
case 0x0c0a0402u: goto P_0c0a0402;
case 0x0c0a0404u: goto P_0c0a0404;
case 0x0c0a0406u: goto P_0c0a0406;
case 0x0c0a0408u: goto P_0c0a0408;
case 0x0c0a040au: goto P_0c0a040a;
case 0x0c0a040cu: goto P_0c0a040c;
case 0x0c0a040eu: goto P_0c0a040e;
case 0x0c0a0410u: goto P_0c0a0410;
case 0x0c0a0412u: goto P_0c0a0412;
case 0x0c0a0414u: goto P_0c0a0414;
case 0x0c0a0416u: goto P_0c0a0416;
case 0x0c0a0418u: goto P_0c0a0418;
case 0x0c0a041au: goto P_0c0a041a;
case 0x0c0a041cu: goto P_0c0a041c;
case 0x0c0a041eu: goto P_0c0a041e;
case 0x0c0a0420u: goto P_0c0a0420;
case 0x0c0a0422u: goto P_0c0a0422;
case 0x0c0a0424u: goto P_0c0a0424;
case 0x0c0a0426u: goto P_0c0a0426;
case 0x0c0a0428u: goto P_0c0a0428;
case 0x0c0a042au: goto P_0c0a042a;
case 0x0c0a042cu: goto P_0c0a042c;
case 0x0c0a042eu: goto P_0c0a042e;
case 0x0c0a0430u: goto P_0c0a0430;
case 0x0c0a0432u: goto P_0c0a0432;
case 0x0c0a0434u: goto P_0c0a0434;
case 0x0c0a0436u: goto P_0c0a0436;
case 0x0c0a0438u: goto P_0c0a0438;
case 0x0c0a043au: goto P_0c0a043a;
case 0x0c0a043cu: goto P_0c0a043c;
case 0x0c0a043eu: goto P_0c0a043e;
case 0x0c0a0440u: goto P_0c0a0440;
case 0x0c0a0442u: goto P_0c0a0442;
case 0x0c0a045cu: goto P_0c0a045c;
case 0x0c0a045eu: goto P_0c0a045e;
case 0x0c0a0460u: goto P_0c0a0460;
case 0x0c0a0462u: goto P_0c0a0462;
case 0x0c0a0464u: goto P_0c0a0464;
case 0x0c0a0466u: goto P_0c0a0466;
case 0x0c0a0468u: goto P_0c0a0468;
case 0x0c0a046au: goto P_0c0a046a;
case 0x0c0a046cu: goto P_0c0a046c;
case 0x0c0a046eu: goto P_0c0a046e;
case 0x0c0a0470u: goto P_0c0a0470;
case 0x0c0a0472u: goto P_0c0a0472;
case 0x0c0a0474u: goto P_0c0a0474;
case 0x0c0a0476u: goto P_0c0a0476;
case 0x0c0a0478u: goto P_0c0a0478;
case 0x0c0a047au: goto P_0c0a047a;
case 0x0c0a047cu: goto P_0c0a047c;
case 0x0c0a047eu: goto P_0c0a047e;
case 0x0c0a0480u: goto P_0c0a0480;
case 0x0c0a0482u: goto P_0c0a0482;
case 0x0c0a0484u: goto P_0c0a0484;
case 0x0c0a0486u: goto P_0c0a0486;
case 0x0c0a0488u: goto P_0c0a0488;
case 0x0c0a048au: goto P_0c0a048a;
case 0x0c0a048cu: goto P_0c0a048c;
case 0x0c0a048eu: goto P_0c0a048e;
case 0x0c0a0490u: goto P_0c0a0490;
case 0x0c0a0492u: goto P_0c0a0492;
case 0x0c0a0494u: goto P_0c0a0494;
case 0x0c0a0496u: goto P_0c0a0496;
case 0x0c0a0498u: goto P_0c0a0498;
case 0x0c0a049au: goto P_0c0a049a;
case 0x0c0a049cu: goto P_0c0a049c;
case 0x0c0a049eu: goto P_0c0a049e;
case 0x0c0a04a0u: goto P_0c0a04a0;
case 0x0c0a04a2u: goto P_0c0a04a2;
case 0x0c0a04a4u: goto P_0c0a04a4;
case 0x0c0a04a6u: goto P_0c0a04a6;
case 0x0c0a04a8u: goto P_0c0a04a8;
case 0x0c0a04aau: goto P_0c0a04aa;
case 0x0c0a04acu: goto P_0c0a04ac;
case 0x0c0a04aeu: goto P_0c0a04ae;
case 0x0c0a04b0u: goto P_0c0a04b0;
case 0x0c0a04b2u: goto P_0c0a04b2;
case 0x0c0a04b4u: goto P_0c0a04b4;
case 0x0c0a04b6u: goto P_0c0a04b6;
case 0x0c0a04b8u: goto P_0c0a04b8;
case 0x0c0a04bau: goto P_0c0a04ba;
case 0x0c0a04bcu: goto P_0c0a04bc;
case 0x0c0a04beu: goto P_0c0a04be;
case 0x0c0a04c0u: goto P_0c0a04c0;
case 0x0c0a04c2u: goto P_0c0a04c2;
case 0x0c0a04c4u: goto P_0c0a04c4;
case 0x0c0a04c6u: goto P_0c0a04c6;
case 0x0c0a04c8u: goto P_0c0a04c8;
case 0x0c0a04cau: goto P_0c0a04ca;
case 0x0c0a04ccu: goto P_0c0a04cc;
case 0x0c0a04ceu: goto P_0c0a04ce;
case 0x0c0a04d0u: goto P_0c0a04d0;
case 0x0c0a04d2u: goto P_0c0a04d2;
case 0x0c0a04d4u: goto P_0c0a04d4;
case 0x0c0a04d6u: goto P_0c0a04d6;
case 0x0c0a04d8u: goto P_0c0a04d8;
case 0x0c0a04dau: goto P_0c0a04da;
case 0x0c0a04dcu: goto P_0c0a04dc;
case 0x0c0a04deu: goto P_0c0a04de;
case 0x0c0a04e0u: goto P_0c0a04e0;
case 0x0c0a04e2u: goto P_0c0a04e2;
case 0x0c0a04e4u: goto P_0c0a04e4;
case 0x0c0a04e6u: goto P_0c0a04e6;
case 0x0c0a04e8u: goto P_0c0a04e8;
case 0x0c0a04eau: goto P_0c0a04ea;
case 0x0c0a04ecu: goto P_0c0a04ec;
case 0x0c0a04eeu: goto P_0c0a04ee;
case 0x0c0a04f0u: goto P_0c0a04f0;
case 0x0c0a04f2u: goto P_0c0a04f2;
case 0x0c0a04f4u: goto P_0c0a04f4;
case 0x0c0a04f6u: goto P_0c0a04f6;
case 0x0c0a04f8u: goto P_0c0a04f8;
case 0x0c0a04fau: goto P_0c0a04fa;
case 0x0c0a04fcu: goto P_0c0a04fc;
case 0x0c0a04feu: goto P_0c0a04fe;
case 0x0c0a0500u: goto P_0c0a0500;
case 0x0c0a0502u: goto P_0c0a0502;
case 0x0c0a0504u: goto P_0c0a0504;
case 0x0c0a0506u: goto P_0c0a0506;
case 0x0c0a0508u: goto P_0c0a0508;
case 0x0c0a050au: goto P_0c0a050a;
case 0x0c0a050cu: goto P_0c0a050c;
case 0x0c0a050eu: goto P_0c0a050e;
case 0x0c0a0510u: goto P_0c0a0510;
case 0x0c0a0512u: goto P_0c0a0512;
case 0x0c0a0514u: goto P_0c0a0514;
case 0x0c0a0516u: goto P_0c0a0516;
case 0x0c0a0518u: goto P_0c0a0518;
case 0x0c0a051au: goto P_0c0a051a;
case 0x0c0a051cu: goto P_0c0a051c;
case 0x0c0a051eu: goto P_0c0a051e;
case 0x0c0a0520u: goto P_0c0a0520;
case 0x0c0a0522u: goto P_0c0a0522;
case 0x0c0a0524u: goto P_0c0a0524;
case 0x0c0a0526u: goto P_0c0a0526;
case 0x0c0a0528u: goto P_0c0a0528;
case 0x0c0a052au: goto P_0c0a052a;
case 0x0c0a052cu: goto P_0c0a052c;
case 0x0c0a052eu: goto P_0c0a052e;
case 0x0c0a0530u: goto P_0c0a0530;
case 0x0c0a0532u: goto P_0c0a0532;
case 0x0c0a0534u: goto P_0c0a0534;
case 0x0c0a0536u: goto P_0c0a0536;
case 0x0c0a0538u: goto P_0c0a0538;
case 0x0c0a053au: goto P_0c0a053a;
case 0x0c0a053cu: goto P_0c0a053c;
case 0x0c0a053eu: goto P_0c0a053e;
case 0x0c0a0540u: goto P_0c0a0540;
case 0x0c0a0542u: goto P_0c0a0542;
case 0x0c0a0544u: goto P_0c0a0544;
case 0x0c0a0546u: goto P_0c0a0546;
case 0x0c0a0548u: goto P_0c0a0548;
case 0x0c0a054au: goto P_0c0a054a;
case 0x0c0a054cu: goto P_0c0a054c;
case 0x0c0a054eu: goto P_0c0a054e;
case 0x0c0a0550u: goto P_0c0a0550;
case 0x0c0a0552u: goto P_0c0a0552;
case 0x0c0a0554u: goto P_0c0a0554;
case 0x0c0a0556u: goto P_0c0a0556;
case 0x0c0a0558u: goto P_0c0a0558;
case 0x0c0a055au: goto P_0c0a055a;
case 0x0c0a055cu: goto P_0c0a055c;
case 0x0c0a055eu: goto P_0c0a055e;
case 0x0c0a0560u: goto P_0c0a0560;
case 0x0c0a0562u: goto P_0c0a0562;
case 0x0c0a0564u: goto P_0c0a0564;
case 0x0c0a0566u: goto P_0c0a0566;
case 0x0c0a0568u: goto P_0c0a0568;
case 0x0c0a056au: goto P_0c0a056a;
case 0x0c0a056cu: goto P_0c0a056c;
case 0x0c0a056eu: goto P_0c0a056e;
case 0x0c0a0570u: goto P_0c0a0570;
case 0x0c0a0572u: goto P_0c0a0572;
case 0x0c0a0574u: goto P_0c0a0574;
case 0x0c0a0576u: goto P_0c0a0576;
case 0x0c0a0578u: goto P_0c0a0578;
case 0x0c0a057au: goto P_0c0a057a;
case 0x0c0a057cu: goto P_0c0a057c;
case 0x0c0a057eu: goto P_0c0a057e;
case 0x0c0a0580u: goto P_0c0a0580;
case 0x0c0a0582u: goto P_0c0a0582;
case 0x0c0a0584u: goto P_0c0a0584;
case 0x0c0a0586u: goto P_0c0a0586;
case 0x0c0a0588u: goto P_0c0a0588;
case 0x0c0a058au: goto P_0c0a058a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a036c: /* original 2fe6, guest PC 0x0c0a036c */
if(!s->budget--) { s->failed_pc=0x0c0a036cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a036e;
P_0c0a036e: /* original e606, guest PC 0x0c0a036e */
if(!s->budget--) { s->failed_pc=0x0c0a036eu; return 0; }
r[6]=0x00000006u;
goto P_0c0a0370;
P_0c0a0370: /* original 2fd6, guest PC 0x0c0a0370 */
if(!s->budget--) { s->failed_pc=0x0c0a0370u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0372;
P_0c0a0372: /* original e700, guest PC 0x0c0a0372 */
if(!s->budget--) { s->failed_pc=0x0c0a0372u; return 0; }
r[7]=0x00000000u;
goto P_0c0a0374;
P_0c0a0374: /* original 2fc6, guest PC 0x0c0a0374 */
if(!s->budget--) { s->failed_pc=0x0c0a0374u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0376;
P_0c0a0376: /* original 2fb6, guest PC 0x0c0a0376 */
if(!s->budget--) { s->failed_pc=0x0c0a0376u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0378;
P_0c0a0378: /* original d433, guest PC 0x0c0a0378 */
if(!s->budget--) { s->failed_pc=0x0c0a0378u; return 0; }
r[4]=read(ram,0x0c0a0448u,4);
goto P_0c0a037a;
P_0c0a037a: /* original 9063, guest PC 0x0c0a037a */
if(!s->budget--) { s->failed_pc=0x0c0a037au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0444u,2);
goto P_0c0a037c;
P_0c0a037c: /* original 4f22, guest PC 0x0c0a037c */
if(!s->budget--) { s->failed_pc=0x0c0a037cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a037e;
P_0c0a037e: /* original 054c, guest PC 0x0c0a037e */
if(!s->budget--) { s->failed_pc=0x0c0a037eu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a0380;
P_0c0a0380: /* original dc32, guest PC 0x0c0a0380 */
if(!s->budget--) { s->failed_pc=0x0c0a0380u; return 0; }
r[12]=read(ram,0x0c0a044cu,4);
goto P_0c0a0382;
P_0c0a0382: /* original 3563, guest PC 0x0c0a0382 */
if(!s->budget--) { s->failed_pc=0x0c0a0382u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c0a0384;
P_0c0a0384: /* original 8f08, guest PC 0x0c0a0384 */
if(!s->budget--) { s->failed_pc=0x0c0a0384u; return 0; }
cond=r[17]&1u;
r[14]=r[7];
if(!cond) { goto P_0c0a0398; }
goto P_0c0a0388;
P_0c0a0386: /* original 6e73, guest PC 0x0c0a0386 */
if(!s->budget--) { s->failed_pc=0x0c0a0386u; return 0; }
r[14]=r[7];
goto P_0c0a0388;
P_0c0a0388: /* original e50c, guest PC 0x0c0a0388 */
if(!s->budget--) { s->failed_pc=0x0c0a0388u; return 0; }
r[5]=0x0000000cu;
goto P_0c0a038a;
P_0c0a038a: /* original 6053, guest PC 0x0c0a038a */
if(!s->budget--) { s->failed_pc=0x0c0a038au; return 0; }
r[0]=r[5];
goto P_0c0a038c;
P_0c0a038c: /* original 707c, guest PC 0x0c0a038c */
if(!s->budget--) { s->failed_pc=0x0c0a038cu; return 0; }
r[0]+=0x0000007cu;
goto P_0c0a038e;
P_0c0a038e: /* original 034c, guest PC 0x0c0a038e */
if(!s->budget--) { s->failed_pc=0x0c0a038eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a0390;
P_0c0a0390: /* original 3353, guest PC 0x0c0a0390 */
if(!s->budget--) { s->failed_pc=0x0c0a0390u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[5])!=0);
goto P_0c0a0392;
P_0c0a0392: /* original 8f01, guest PC 0x0c0a0392 */
if(!s->budget--) { s->failed_pc=0x0c0a0392u; return 0; }
cond=r[17]&1u;
r[14]=r[6];
if(!cond) { goto P_0c0a0398; }
goto P_0c0a0396;
P_0c0a0394: /* original 6e63, guest PC 0x0c0a0394 */
if(!s->budget--) { s->failed_pc=0x0c0a0394u; return 0; }
r[14]=r[6];
goto P_0c0a0396;
P_0c0a0396: /* original 6e53, guest PC 0x0c0a0396 */
if(!s->budget--) { s->failed_pc=0x0c0a0396u; return 0; }
r[14]=r[5];
goto P_0c0a0398;
P_0c0a0398: /* original eb18, guest PC 0x0c0a0398 */
if(!s->budget--) { s->failed_pc=0x0c0a0398u; return 0; }
r[11]=0x00000018u;
goto P_0c0a039a;
P_0c0a039a: /* original a018, guest PC 0x0c0a039a */
if(!s->budget--) { s->failed_pc=0x0c0a039au; return 0; }
r[13]=r[7];
goto P_0c0a03ce;
P_0c0a039c: /* original 6d73, guest PC 0x0c0a039c */
if(!s->budget--) { s->failed_pc=0x0c0a039cu; return 0; }
r[13]=r[7];
goto P_0c0a039e;
P_0c0a039e: /* original 65e3, guest PC 0x0c0a039e */
if(!s->budget--) { s->failed_pc=0x0c0a039eu; return 0; }
r[5]=r[14];
goto P_0c0a03a0;
P_0c0a03a0: /* original b03d, guest PC 0x0c0a03a0 */
if(!s->budget--) { s->failed_pc=0x0c0a03a0u; return 0; }
target=code_base|0x0c0a041eu; r[16]=code_base|0x0c0a03a4u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a03a4u) { target=s->pc; goto dispatch; }
goto P_0c0a03a4;
P_0c0a03a2: /* original 64d3, guest PC 0x0c0a03a2 */
if(!s->budget--) { s->failed_pc=0x0c0a03a2u; return 0; }
r[4]=r[13];
goto P_0c0a03a4;
P_0c0a03a4: /* original 65e3, guest PC 0x0c0a03a4 */
if(!s->budget--) { s->failed_pc=0x0c0a03a4u; return 0; }
r[5]=r[14];
goto P_0c0a03a6;
P_0c0a03a6: /* original 63c3, guest PC 0x0c0a03a6 */
if(!s->budget--) { s->failed_pc=0x0c0a03a6u; return 0; }
r[3]=r[12];
goto P_0c0a03a8;
P_0c0a03a8: /* original 4508, guest PC 0x0c0a03a8 */
if(!s->budget--) { s->failed_pc=0x0c0a03a8u; return 0; }
r[5]<<=2;
goto P_0c0a03aa;
P_0c0a03aa: /* original 353c, guest PC 0x0c0a03aa */
if(!s->budget--) { s->failed_pc=0x0c0a03aau; return 0; }
r[5]+=r[3];
goto P_0c0a03ac;
P_0c0a03ac: /* original b056, guest PC 0x0c0a03ac */
if(!s->budget--) { s->failed_pc=0x0c0a03acu; return 0; }
target=code_base|0x0c0a045cu; r[16]=code_base|0x0c0a03b0u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a03b0u) { target=s->pc; goto dispatch; }
goto P_0c0a03b0;
P_0c0a03ae: /* original 64d3, guest PC 0x0c0a03ae */
if(!s->budget--) { s->failed_pc=0x0c0a03aeu; return 0; }
r[4]=r[13];
goto P_0c0a03b0;
P_0c0a03b0: /* original 63c3, guest PC 0x0c0a03b0 */
if(!s->budget--) { s->failed_pc=0x0c0a03b0u; return 0; }
r[3]=r[12];
goto P_0c0a03b2;
P_0c0a03b2: /* original 65e3, guest PC 0x0c0a03b2 */
if(!s->budget--) { s->failed_pc=0x0c0a03b2u; return 0; }
r[5]=r[14];
goto P_0c0a03b4;
P_0c0a03b4: /* original 7348, guest PC 0x0c0a03b4 */
if(!s->budget--) { s->failed_pc=0x0c0a03b4u; return 0; }
r[3]+=0x00000048u;
goto P_0c0a03b6;
P_0c0a03b6: /* original 4508, guest PC 0x0c0a03b6 */
if(!s->budget--) { s->failed_pc=0x0c0a03b6u; return 0; }
r[5]<<=2;
goto P_0c0a03b8;
P_0c0a03b8: /* original 353c, guest PC 0x0c0a03b8 */
if(!s->budget--) { s->failed_pc=0x0c0a03b8u; return 0; }
r[5]+=r[3];
goto P_0c0a03ba;
P_0c0a03ba: /* original b08f, guest PC 0x0c0a03ba */
if(!s->budget--) { s->failed_pc=0x0c0a03bau; return 0; }
target=code_base|0x0c0a04dcu; r[16]=code_base|0x0c0a03beu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a03beu) { target=s->pc; goto dispatch; }
goto P_0c0a03be;
P_0c0a03bc: /* original 64d3, guest PC 0x0c0a03bc */
if(!s->budget--) { s->failed_pc=0x0c0a03bcu; return 0; }
r[4]=r[13];
goto P_0c0a03be;
P_0c0a03be: /* original 9642, guest PC 0x0c0a03be */
if(!s->budget--) { s->failed_pc=0x0c0a03beu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0446u,2);
goto P_0c0a03c0;
P_0c0a03c0: /* original 65e3, guest PC 0x0c0a03c0 */
if(!s->budget--) { s->failed_pc=0x0c0a03c0u; return 0; }
r[5]=r[14];
goto P_0c0a03c2;
P_0c0a03c2: /* original 36cc, guest PC 0x0c0a03c2 */
if(!s->budget--) { s->failed_pc=0x0c0a03c2u; return 0; }
r[6]+=r[12];
goto P_0c0a03c4;
P_0c0a03c4: /* original 36ec, guest PC 0x0c0a03c4 */
if(!s->budget--) { s->failed_pc=0x0c0a03c4u; return 0; }
r[6]+=r[14];
goto P_0c0a03c6;
P_0c0a03c6: /* original b0e1, guest PC 0x0c0a03c6 */
if(!s->budget--) { s->failed_pc=0x0c0a03c6u; return 0; }
target=code_base|0x0c0a058cu; r[16]=code_base|0x0c0a03cau;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a03cau) { target=s->pc; goto dispatch; }
goto P_0c0a03ca;
P_0c0a03c8: /* original 64d3, guest PC 0x0c0a03c8 */
if(!s->budget--) { s->failed_pc=0x0c0a03c8u; return 0; }
r[4]=r[13];
goto P_0c0a03ca;
P_0c0a03ca: /* original 7e01, guest PC 0x0c0a03ca */
if(!s->budget--) { s->failed_pc=0x0c0a03cau; return 0; }
r[14]+=0x00000001u;
goto P_0c0a03cc;
P_0c0a03cc: /* original 7d04, guest PC 0x0c0a03cc */
if(!s->budget--) { s->failed_pc=0x0c0a03ccu; return 0; }
r[13]+=0x00000004u;
goto P_0c0a03ce;
P_0c0a03ce: /* original 3db3, guest PC 0x0c0a03ce */
if(!s->budget--) { s->failed_pc=0x0c0a03ceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[11])!=0);
goto P_0c0a03d0;
P_0c0a03d0: /* original 8be5, guest PC 0x0c0a03d0 */
if(!s->budget--) { s->failed_pc=0x0c0a03d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a039e; }
goto P_0c0a03d2;
P_0c0a03d2: /* original 4f26, guest PC 0x0c0a03d2 */
if(!s->budget--) { s->failed_pc=0x0c0a03d2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a03d4;
P_0c0a03d4: /* original 6bf6, guest PC 0x0c0a03d4 */
if(!s->budget--) { s->failed_pc=0x0c0a03d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a03d6;
P_0c0a03d6: /* original 6cf6, guest PC 0x0c0a03d6 */
if(!s->budget--) { s->failed_pc=0x0c0a03d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a03d8;
P_0c0a03d8: /* original 6df6, guest PC 0x0c0a03d8 */
if(!s->budget--) { s->failed_pc=0x0c0a03d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a03da;
P_0c0a03da: /* original 000b, guest PC 0x0c0a03da */
if(!s->budget--) { s->failed_pc=0x0c0a03dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a03dc: /* original 6ef6, guest PC 0x0c0a03dc */
if(!s->budget--) { s->failed_pc=0x0c0a03dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a03de;
P_0c0a03de: /* original 2fe6, guest PC 0x0c0a03de */
if(!s->budget--) { s->failed_pc=0x0c0a03deu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a03e0;
P_0c0a03e0: /* original 2fd6, guest PC 0x0c0a03e0 */
if(!s->budget--) { s->failed_pc=0x0c0a03e0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a03e2;
P_0c0a03e2: /* original 2fc6, guest PC 0x0c0a03e2 */
if(!s->budget--) { s->failed_pc=0x0c0a03e2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a03e4;
P_0c0a03e4: /* original ec1f, guest PC 0x0c0a03e4 */
if(!s->budget--) { s->failed_pc=0x0c0a03e4u; return 0; }
r[12]=0x0000001fu;
goto P_0c0a03e6;
P_0c0a03e6: /* original d31a, guest PC 0x0c0a03e6 */
if(!s->budget--) { s->failed_pc=0x0c0a03e6u; return 0; }
r[3]=read(ram,0x0c0a0450u,4);
goto P_0c0a03e8;
P_0c0a03e8: /* original d417, guest PC 0x0c0a03e8 */
if(!s->budget--) { s->failed_pc=0x0c0a03e8u; return 0; }
r[4]=read(ram,0x0c0a0448u,4);
goto P_0c0a03ea;
P_0c0a03ea: /* original 902b, guest PC 0x0c0a03ea */
if(!s->budget--) { s->failed_pc=0x0c0a03eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0444u,2);
goto P_0c0a03ec;
P_0c0a03ec: /* original 6532, guest PC 0x0c0a03ec */
if(!s->budget--) { s->failed_pc=0x0c0a03ecu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c0a03ee;
P_0c0a03ee: /* original 0e4c, guest PC 0x0c0a03ee */
if(!s->budget--) { s->failed_pc=0x0c0a03eeu; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a03f0;
P_0c0a03f0: /* original 4f22, guest PC 0x0c0a03f0 */
if(!s->budget--) { s->failed_pc=0x0c0a03f0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a03f2;
P_0c0a03f2: /* original 3c58, guest PC 0x0c0a03f2 */
if(!s->budget--) { s->failed_pc=0x0c0a03f2u; return 0; }
r[12]-=r[5];
goto P_0c0a03f4;
P_0c0a03f4: /* original dd15, guest PC 0x0c0a03f4 */
if(!s->budget--) { s->failed_pc=0x0c0a03f4u; return 0; }
r[13]=read(ram,0x0c0a044cu,4);
goto P_0c0a03f6;
P_0c0a03f6: /* original 65e3, guest PC 0x0c0a03f6 */
if(!s->budget--) { s->failed_pc=0x0c0a03f6u; return 0; }
r[5]=r[14];
goto P_0c0a03f8;
P_0c0a03f8: /* original b011, guest PC 0x0c0a03f8 */
if(!s->budget--) { s->failed_pc=0x0c0a03f8u; return 0; }
target=code_base|0x0c0a041eu; r[16]=code_base|0x0c0a03fcu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a03fcu) { target=s->pc; goto dispatch; }
goto P_0c0a03fc;
P_0c0a03fa: /* original 64c3, guest PC 0x0c0a03fa */
if(!s->budget--) { s->failed_pc=0x0c0a03fau; return 0; }
r[4]=r[12];
goto P_0c0a03fc;
P_0c0a03fc: /* original 63d3, guest PC 0x0c0a03fc */
if(!s->budget--) { s->failed_pc=0x0c0a03fcu; return 0; }
r[3]=r[13];
goto P_0c0a03fe;
P_0c0a03fe: /* original 65e3, guest PC 0x0c0a03fe */
if(!s->budget--) { s->failed_pc=0x0c0a03feu; return 0; }
r[5]=r[14];
goto P_0c0a0400;
P_0c0a0400: /* original 7348, guest PC 0x0c0a0400 */
if(!s->budget--) { s->failed_pc=0x0c0a0400u; return 0; }
r[3]+=0x00000048u;
goto P_0c0a0402;
P_0c0a0402: /* original 4508, guest PC 0x0c0a0402 */
if(!s->budget--) { s->failed_pc=0x0c0a0402u; return 0; }
r[5]<<=2;
goto P_0c0a0404;
P_0c0a0404: /* original 353c, guest PC 0x0c0a0404 */
if(!s->budget--) { s->failed_pc=0x0c0a0404u; return 0; }
r[5]+=r[3];
goto P_0c0a0406;
P_0c0a0406: /* original b069, guest PC 0x0c0a0406 */
if(!s->budget--) { s->failed_pc=0x0c0a0406u; return 0; }
target=code_base|0x0c0a04dcu; r[16]=code_base|0x0c0a040au;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a040au) { target=s->pc; goto dispatch; }
goto P_0c0a040a;
P_0c0a0408: /* original 64c3, guest PC 0x0c0a0408 */
if(!s->budget--) { s->failed_pc=0x0c0a0408u; return 0; }
r[4]=r[12];
goto P_0c0a040a;
P_0c0a040a: /* original 4f26, guest PC 0x0c0a040a */
if(!s->budget--) { s->failed_pc=0x0c0a040au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a040c;
P_0c0a040c: /* original 64c3, guest PC 0x0c0a040c */
if(!s->budget--) { s->failed_pc=0x0c0a040cu; return 0; }
r[4]=r[12];
goto P_0c0a040e;
P_0c0a040e: /* original 961a, guest PC 0x0c0a040e */
if(!s->budget--) { s->failed_pc=0x0c0a040eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0446u,2);
goto P_0c0a0410;
P_0c0a0410: /* original 65e3, guest PC 0x0c0a0410 */
if(!s->budget--) { s->failed_pc=0x0c0a0410u; return 0; }
r[5]=r[14];
goto P_0c0a0412;
P_0c0a0412: /* original 6cf6, guest PC 0x0c0a0412 */
if(!s->budget--) { s->failed_pc=0x0c0a0412u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a0414;
P_0c0a0414: /* original 36dc, guest PC 0x0c0a0414 */
if(!s->budget--) { s->failed_pc=0x0c0a0414u; return 0; }
r[6]+=r[13];
goto P_0c0a0416;
P_0c0a0416: /* original 36ec, guest PC 0x0c0a0416 */
if(!s->budget--) { s->failed_pc=0x0c0a0416u; return 0; }
r[6]+=r[14];
goto P_0c0a0418;
P_0c0a0418: /* original 6df6, guest PC 0x0c0a0418 */
if(!s->budget--) { s->failed_pc=0x0c0a0418u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a041a;
P_0c0a041a: /* original a0b7, guest PC 0x0c0a041a */
if(!s->budget--) { s->failed_pc=0x0c0a041au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a058cu,s,ram);
P_0c0a041c: /* original 6ef6, guest PC 0x0c0a041c */
if(!s->budget--) { s->failed_pc=0x0c0a041cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a041e;
P_0c0a041e: /* original 4f22, guest PC 0x0c0a041e */
if(!s->budget--) { s->failed_pc=0x0c0a041eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a0420;
P_0c0a0420: /* original 6153, guest PC 0x0c0a0420 */
if(!s->budget--) { s->failed_pc=0x0c0a0420u; return 0; }
r[1]=r[5];
goto P_0c0a0422;
P_0c0a0422: /* original 7101, guest PC 0x0c0a0422 */
if(!s->budget--) { s->failed_pc=0x0c0a0422u; return 0; }
r[1]+=0x00000001u;
goto P_0c0a0424;
P_0c0a0424: /* original e307, guest PC 0x0c0a0424 */
if(!s->budget--) { s->failed_pc=0x0c0a0424u; return 0; }
r[3]=0x00000007u;
goto P_0c0a0426;
P_0c0a0426: /* original 7ffc, guest PC 0x0c0a0426 */
if(!s->budget--) { s->failed_pc=0x0c0a0426u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a0428;
P_0c0a0428: /* original 2f52, guest PC 0x0c0a0428 */
if(!s->budget--) { s->failed_pc=0x0c0a0428u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0a042a;
P_0c0a042a: /* original 740c, guest PC 0x0c0a042a */
if(!s->budget--) { s->failed_pc=0x0c0a042au; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a042c;
P_0c0a042c: /* original 2f16, guest PC 0x0c0a042c */
if(!s->budget--) { s->failed_pc=0x0c0a042cu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a042e;
P_0c0a042e: /* original 443c, guest PC 0x0c0a042e */
if(!s->budget--) { s->failed_pc=0x0c0a042eu; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c0a0430;
P_0c0a0430: /* original d309, guest PC 0x0c0a0430 */
if(!s->budget--) { s->failed_pc=0x0c0a0430u; return 0; }
r[3]=read(ram,0x0c0a0458u,4);
goto P_0c0a0432;
P_0c0a0432: /* original e20e, guest PC 0x0c0a0432 */
if(!s->budget--) { s->failed_pc=0x0c0a0432u; return 0; }
r[2]=0x0000000eu;
goto P_0c0a0434;
P_0c0a0434: /* original d107, guest PC 0x0c0a0434 */
if(!s->budget--) { s->failed_pc=0x0c0a0434u; return 0; }
r[1]=read(ram,0x0c0a0454u,4);
goto P_0c0a0436;
P_0c0a0436: /* original 242b, guest PC 0x0c0a0436 */
if(!s->budget--) { s->failed_pc=0x0c0a0436u; return 0; }
r[4]|=r[2];
goto P_0c0a0438;
P_0c0a0438: /* original 430b, guest PC 0x0c0a0438 */
if(!s->budget--) { s->failed_pc=0x0c0a0438u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a043cu;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a043cu) { target=s->pc; goto dispatch; }
goto P_0c0a043c;
P_0c0a043a: /* original 2f16, guest PC 0x0c0a043a */
if(!s->budget--) { s->failed_pc=0x0c0a043au; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a043c;
P_0c0a043c: /* original 7f0c, guest PC 0x0c0a043c */
if(!s->budget--) { s->failed_pc=0x0c0a043cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a043e;
P_0c0a043e: /* original 4f26, guest PC 0x0c0a043e */
if(!s->budget--) { s->failed_pc=0x0c0a043eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a0440;
P_0c0a0440: /* original 000b, guest PC 0x0c0a0440 */
if(!s->budget--) { s->failed_pc=0x0c0a0440u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a0442: /* original 0009, guest PC 0x0c0a0442 */
if(!s->budget--) { s->failed_pc=0x0c0a0442u; return 0; }
if(!vf3_matrix_family(0x0c0a0444u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a0444u; return 0; } return 1;
P_0c0a045c: /* original 2fe6, guest PC 0x0c0a045c */
if(!s->budget--) { s->failed_pc=0x0c0a045cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a045e;
P_0c0a045e: /* original 2fd6, guest PC 0x0c0a045e */
if(!s->budget--) { s->failed_pc=0x0c0a045eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0460;
P_0c0a0460: /* original 6d53, guest PC 0x0c0a0460 */
if(!s->budget--) { s->failed_pc=0x0c0a0460u; return 0; }
r[13]=r[5];
goto P_0c0a0462;
P_0c0a0462: /* original 2fc6, guest PC 0x0c0a0462 */
if(!s->budget--) { s->failed_pc=0x0c0a0462u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0464;
P_0c0a0464: /* original 4f22, guest PC 0x0c0a0464 */
if(!s->budget--) { s->failed_pc=0x0c0a0464u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a0466;
P_0c0a0466: /* original 7ffc, guest PC 0x0c0a0466 */
if(!s->budget--) { s->failed_pc=0x0c0a0466u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a0468;
P_0c0a0468: /* original 2f42, guest PC 0x0c0a0468 */
if(!s->budget--) { s->failed_pc=0x0c0a0468u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a046a;
P_0c0a046a: /* original de5b, guest PC 0x0c0a046a */
if(!s->budget--) { s->failed_pc=0x0c0a046au; return 0; }
r[14]=read(ram,0x0c0a05d8u,4);
goto P_0c0a046c;
P_0c0a046c: /* original d35b, guest PC 0x0c0a046c */
if(!s->budget--) { s->failed_pc=0x0c0a046cu; return 0; }
r[3]=read(ram,0x0c0a05dcu,4);
goto P_0c0a046e;
P_0c0a046e: /* original 430b, guest PC 0x0c0a046e */
if(!s->budget--) { s->failed_pc=0x0c0a046eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a0472u;
r[4]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0472u) { target=s->pc; goto dispatch; }
goto P_0c0a0472;
P_0c0a0470: /* original 6453, guest PC 0x0c0a0470 */
if(!s->budget--) { s->failed_pc=0x0c0a0470u; return 0; }
r[4]=r[5];
goto P_0c0a0472;
P_0c0a0472: /* original 6203, guest PC 0x0c0a0472 */
if(!s->budget--) { s->failed_pc=0x0c0a0472u; return 0; }
r[2]=r[0];
goto P_0c0a0474;
P_0c0a0474: /* original 6403, guest PC 0x0c0a0474 */
if(!s->budget--) { s->failed_pc=0x0c0a0474u; return 0; }
r[4]=r[0];
goto P_0c0a0476;
P_0c0a0476: /* original 90aa, guest PC 0x0c0a0476 */
if(!s->budget--) { s->failed_pc=0x0c0a0476u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a05ceu,2);
goto P_0c0a0478;
P_0c0a0478: /* original 4229, guest PC 0x0c0a0478 */
if(!s->budget--) { s->failed_pc=0x0c0a0478u; return 0; }
r[2]>>=16;
goto P_0c0a047a;
P_0c0a047a: /* original 4219, guest PC 0x0c0a047a */
if(!s->budget--) { s->failed_pc=0x0c0a047au; return 0; }
r[2]>>=8;
goto P_0c0a047c;
P_0c0a047c: /* original 6343, guest PC 0x0c0a047c */
if(!s->budget--) { s->failed_pc=0x0c0a047cu; return 0; }
r[3]=r[4];
goto P_0c0a047e;
P_0c0a047e: /* original 0e24, guest PC 0x0c0a047e */
if(!s->budget--) { s->failed_pc=0x0c0a047eu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0a0480;
P_0c0a0480: /* original 7001, guest PC 0x0c0a0480 */
if(!s->budget--) { s->failed_pc=0x0c0a0480u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a0482;
P_0c0a0482: /* original 4329, guest PC 0x0c0a0482 */
if(!s->budget--) { s->failed_pc=0x0c0a0482u; return 0; }
r[3]>>=16;
goto P_0c0a0484;
P_0c0a0484: /* original 6243, guest PC 0x0c0a0484 */
if(!s->budget--) { s->failed_pc=0x0c0a0484u; return 0; }
r[2]=r[4];
goto P_0c0a0486;
P_0c0a0486: /* original 0e34, guest PC 0x0c0a0486 */
if(!s->budget--) { s->failed_pc=0x0c0a0486u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0a0488;
P_0c0a0488: /* original 7001, guest PC 0x0c0a0488 */
if(!s->budget--) { s->failed_pc=0x0c0a0488u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a048a;
P_0c0a048a: /* original 4219, guest PC 0x0c0a048a */
if(!s->budget--) { s->failed_pc=0x0c0a048au; return 0; }
r[2]>>=8;
goto P_0c0a048c;
P_0c0a048c: /* original 0e24, guest PC 0x0c0a048c */
if(!s->budget--) { s->failed_pc=0x0c0a048cu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0a048e;
P_0c0a048e: /* original 7001, guest PC 0x0c0a048e */
if(!s->budget--) { s->failed_pc=0x0c0a048eu; return 0; }
r[0]+=0x00000001u;
goto P_0c0a0490;
P_0c0a0490: /* original 0e44, guest PC 0x0c0a0490 */
if(!s->budget--) { s->failed_pc=0x0c0a0490u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a0492;
P_0c0a0492: /* original dc53, guest PC 0x0c0a0492 */
if(!s->budget--) { s->failed_pc=0x0c0a0492u; return 0; }
r[12]=read(ram,0x0c0a05e0u,4);
goto P_0c0a0494;
P_0c0a0494: /* original 4c0b, guest PC 0x0c0a0494 */
if(!s->budget--) { s->failed_pc=0x0c0a0494u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a0498u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0498u) { target=s->pc; goto dispatch; }
goto P_0c0a0498;
P_0c0a0496: /* original 64d3, guest PC 0x0c0a0496 */
if(!s->budget--) { s->failed_pc=0x0c0a0496u; return 0; }
r[4]=r[13];
goto P_0c0a0498;
P_0c0a0498: /* original 9199, guest PC 0x0c0a0498 */
if(!s->budget--) { s->failed_pc=0x0c0a0498u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a05ceu,2);
goto P_0c0a049a;
P_0c0a049a: /* original 64d3, guest PC 0x0c0a049a */
if(!s->budget--) { s->failed_pc=0x0c0a049au; return 0; }
r[4]=r[13];
goto P_0c0a049c;
P_0c0a049c: /* original 31ec, guest PC 0x0c0a049c */
if(!s->budget--) { s->failed_pc=0x0c0a049cu; return 0; }
r[1]+=r[14];
goto P_0c0a049e;
P_0c0a049e: /* original 2100, guest PC 0x0c0a049e */
if(!s->budget--) { s->failed_pc=0x0c0a049eu; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0a04a0;
P_0c0a04a0: /* original 4c0b, guest PC 0x0c0a04a0 */
if(!s->budget--) { s->failed_pc=0x0c0a04a0u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a04a4u;
r[4]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a04a4u) { target=s->pc; goto dispatch; }
goto P_0c0a04a4;
P_0c0a04a2: /* original 7401, guest PC 0x0c0a04a2 */
if(!s->budget--) { s->failed_pc=0x0c0a04a2u; return 0; }
r[4]+=0x00000001u;
goto P_0c0a04a4;
P_0c0a04a4: /* original 9194, guest PC 0x0c0a04a4 */
if(!s->budget--) { s->failed_pc=0x0c0a04a4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a05d0u,2);
goto P_0c0a04a6;
P_0c0a04a6: /* original 64d3, guest PC 0x0c0a04a6 */
if(!s->budget--) { s->failed_pc=0x0c0a04a6u; return 0; }
r[4]=r[13];
goto P_0c0a04a8;
P_0c0a04a8: /* original 31ec, guest PC 0x0c0a04a8 */
if(!s->budget--) { s->failed_pc=0x0c0a04a8u; return 0; }
r[1]+=r[14];
goto P_0c0a04aa;
P_0c0a04aa: /* original 2100, guest PC 0x0c0a04aa */
if(!s->budget--) { s->failed_pc=0x0c0a04aau; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0a04ac;
P_0c0a04ac: /* original 4c0b, guest PC 0x0c0a04ac */
if(!s->budget--) { s->failed_pc=0x0c0a04acu; return 0; }
target=r[12];
r[16]=code_base|0x0c0a04b0u;
r[4]+=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a04b0u) { target=s->pc; goto dispatch; }
goto P_0c0a04b0;
P_0c0a04ae: /* original 7402, guest PC 0x0c0a04ae */
if(!s->budget--) { s->failed_pc=0x0c0a04aeu; return 0; }
r[4]+=0x00000002u;
goto P_0c0a04b0;
P_0c0a04b0: /* original 918f, guest PC 0x0c0a04b0 */
if(!s->budget--) { s->failed_pc=0x0c0a04b0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a05d2u,2);
goto P_0c0a04b2;
P_0c0a04b2: /* original e300, guest PC 0x0c0a04b2 */
if(!s->budget--) { s->failed_pc=0x0c0a04b2u; return 0; }
r[3]=0x00000000u;
goto P_0c0a04b4;
P_0c0a04b4: /* original e21c, guest PC 0x0c0a04b4 */
if(!s->budget--) { s->failed_pc=0x0c0a04b4u; return 0; }
r[2]=0x0000001cu;
goto P_0c0a04b6;
P_0c0a04b6: /* original 31ec, guest PC 0x0c0a04b6 */
if(!s->budget--) { s->failed_pc=0x0c0a04b6u; return 0; }
r[1]+=r[14];
goto P_0c0a04b8;
P_0c0a04b8: /* original 2100, guest PC 0x0c0a04b8 */
if(!s->budget--) { s->failed_pc=0x0c0a04b8u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0a04ba;
P_0c0a04ba: /* original e601, guest PC 0x0c0a04ba */
if(!s->budget--) { s->failed_pc=0x0c0a04bau; return 0; }
r[6]=0x00000001u;
goto P_0c0a04bc;
P_0c0a04bc: /* original 908a, guest PC 0x0c0a04bc */
if(!s->budget--) { s->failed_pc=0x0c0a04bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a05d4u,2);
goto P_0c0a04be;
P_0c0a04be: /* original 0e34, guest PC 0x0c0a04be */
if(!s->budget--) { s->failed_pc=0x0c0a04beu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0a04c0;
P_0c0a04c0: /* original e307, guest PC 0x0c0a04c0 */
if(!s->budget--) { s->failed_pc=0x0c0a04c0u; return 0; }
r[3]=0x00000007u;
goto P_0c0a04c2;
P_0c0a04c2: /* original 64f2, guest PC 0x0c0a04c2 */
if(!s->budget--) { s->failed_pc=0x0c0a04c2u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a04c4;
P_0c0a04c4: /* original 7f04, guest PC 0x0c0a04c4 */
if(!s->budget--) { s->failed_pc=0x0c0a04c4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a04c6;
P_0c0a04c6: /* original 4f26, guest PC 0x0c0a04c6 */
if(!s->budget--) { s->failed_pc=0x0c0a04c6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a04c8;
P_0c0a04c8: /* original 9581, guest PC 0x0c0a04c8 */
if(!s->budget--) { s->failed_pc=0x0c0a04c8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a05ceu,2);
goto P_0c0a04ca;
P_0c0a04ca: /* original 740c, guest PC 0x0c0a04ca */
if(!s->budget--) { s->failed_pc=0x0c0a04cau; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a04cc;
P_0c0a04cc: /* original d145, guest PC 0x0c0a04cc */
if(!s->budget--) { s->failed_pc=0x0c0a04ccu; return 0; }
r[1]=read(ram,0x0c0a05e4u,4);
goto P_0c0a04ce;
P_0c0a04ce: /* original 443d, guest PC 0x0c0a04ce */
if(!s->budget--) { s->failed_pc=0x0c0a04ceu; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c0a04d0;
P_0c0a04d0: /* original 6cf6, guest PC 0x0c0a04d0 */
if(!s->budget--) { s->failed_pc=0x0c0a04d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a04d2;
P_0c0a04d2: /* original 242b, guest PC 0x0c0a04d2 */
if(!s->budget--) { s->failed_pc=0x0c0a04d2u; return 0; }
r[4]|=r[2];
goto P_0c0a04d4;
P_0c0a04d4: /* original 35ec, guest PC 0x0c0a04d4 */
if(!s->budget--) { s->failed_pc=0x0c0a04d4u; return 0; }
r[5]+=r[14];
goto P_0c0a04d6;
P_0c0a04d6: /* original 6df6, guest PC 0x0c0a04d6 */
if(!s->budget--) { s->failed_pc=0x0c0a04d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a04d8;
P_0c0a04d8: /* original 412b, guest PC 0x0c0a04d8 */
if(!s->budget--) { s->failed_pc=0x0c0a04d8u; return 0; }
target=r[1];
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
P_0c0a04da: /* original 6ef6, guest PC 0x0c0a04da */
if(!s->budget--) { s->failed_pc=0x0c0a04dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a04dc;
P_0c0a04dc: /* original 2fe6, guest PC 0x0c0a04dc */
if(!s->budget--) { s->failed_pc=0x0c0a04dcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a04de;
P_0c0a04de: /* original 2fd6, guest PC 0x0c0a04de */
if(!s->budget--) { s->failed_pc=0x0c0a04deu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a04e0;
P_0c0a04e0: /* original 2fc6, guest PC 0x0c0a04e0 */
if(!s->budget--) { s->failed_pc=0x0c0a04e0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a04e2;
P_0c0a04e2: /* original 4f22, guest PC 0x0c0a04e2 */
if(!s->budget--) { s->failed_pc=0x0c0a04e2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a04e4;
P_0c0a04e4: /* original 4f12, guest PC 0x0c0a04e4 */
if(!s->budget--) { s->failed_pc=0x0c0a04e4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a04e6;
P_0c0a04e6: /* original 7ff8, guest PC 0x0c0a04e6 */
if(!s->budget--) { s->failed_pc=0x0c0a04e6u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a04e8;
P_0c0a04e8: /* original 2f42, guest PC 0x0c0a04e8 */
if(!s->budget--) { s->failed_pc=0x0c0a04e8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a04ea;
P_0c0a04ea: /* original 1f51, guest PC 0x0c0a04ea */
if(!s->budget--) { s->failed_pc=0x0c0a04eau; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0a04ec;
P_0c0a04ec: /* original d33b, guest PC 0x0c0a04ec */
if(!s->budget--) { s->failed_pc=0x0c0a04ecu; return 0; }
r[3]=read(ram,0x0c0a05dcu,4);
goto P_0c0a04ee;
P_0c0a04ee: /* original 430b, guest PC 0x0c0a04ee */
if(!s->budget--) { s->failed_pc=0x0c0a04eeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a04f2u;
r[4]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a04f2u) { target=s->pc; goto dispatch; }
goto P_0c0a04f2;
P_0c0a04f0: /* original 6453, guest PC 0x0c0a04f0 */
if(!s->budget--) { s->failed_pc=0x0c0a04f0u; return 0; }
r[4]=r[5];
goto P_0c0a04f2;
P_0c0a04f2: /* original ee3f, guest PC 0x0c0a04f2 */
if(!s->budget--) { s->failed_pc=0x0c0a04f2u; return 0; }
r[14]=0x0000003fu;
goto P_0c0a04f4;
P_0c0a04f4: /* original 6403, guest PC 0x0c0a04f4 */
if(!s->budget--) { s->failed_pc=0x0c0a04f4u; return 0; }
r[4]=r[0];
goto P_0c0a04f6;
P_0c0a04f6: /* original 2e49, guest PC 0x0c0a04f6 */
if(!s->budget--) { s->failed_pc=0x0c0a04f6u; return 0; }
r[14]&=r[4];
goto P_0c0a04f8;
P_0c0a04f8: /* original e264, guest PC 0x0c0a04f8 */
if(!s->budget--) { s->failed_pc=0x0c0a04f8u; return 0; }
r[2]=0x00000064u;
goto P_0c0a04fa;
P_0c0a04fa: /* original 0e27, guest PC 0x0c0a04fa */
if(!s->budget--) { s->failed_pc=0x0c0a04fau; return 0; }
r[19]=r[14]*r[2];
goto P_0c0a04fc;
P_0c0a04fc: /* original e3fa, guest PC 0x0c0a04fc */
if(!s->budget--) { s->failed_pc=0x0c0a04fcu; return 0; }
r[3]=0xfffffffau;
goto P_0c0a04fe;
P_0c0a04fe: /* original e50a, guest PC 0x0c0a04fe */
if(!s->budget--) { s->failed_pc=0x0c0a04feu; return 0; }
r[5]=0x0000000au;
goto P_0c0a0500;
P_0c0a0500: /* original e73c, guest PC 0x0c0a0500 */
if(!s->budget--) { s->failed_pc=0x0c0a0500u; return 0; }
r[7]=0x0000003cu;
goto P_0c0a0502;
P_0c0a0502: /* original 0e1a, guest PC 0x0c0a0502 */
if(!s->budget--) { s->failed_pc=0x0c0a0502u; return 0; }
r[14]=r[19];
goto P_0c0a0504;
P_0c0a0504: /* original 4e3c, guest PC 0x0c0a0504 */
if(!s->budget--) { s->failed_pc=0x0c0a0504u; return 0; }
r[14]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[14]>>((-r[3])&31u)):((int32_t)r[14]<0?0xffffffffu:0)):r[14]<<(r[3]&31u);
goto P_0c0a0506;
P_0c0a0506: /* original d338, guest PC 0x0c0a0506 */
if(!s->budget--) { s->failed_pc=0x0c0a0506u; return 0; }
r[3]=read(ram,0x0c0a05e8u,4);
goto P_0c0a0508;
P_0c0a0508: /* original 61e3, guest PC 0x0c0a0508 */
if(!s->budget--) { s->failed_pc=0x0c0a0508u; return 0; }
r[1]=r[14];
goto P_0c0a050a;
P_0c0a050a: /* original 430b, guest PC 0x0c0a050a */
if(!s->budget--) { s->failed_pc=0x0c0a050au; return 0; }
target=r[3];
r[16]=code_base|0x0c0a050eu;
r[0]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a050eu) { target=s->pc; goto dispatch; }
goto P_0c0a050e;
P_0c0a050c: /* original 6053, guest PC 0x0c0a050c */
if(!s->budget--) { s->failed_pc=0x0c0a050cu; return 0; }
r[0]=r[5];
goto P_0c0a050e;
P_0c0a050e: /* original 6103, guest PC 0x0c0a050e */
if(!s->budget--) { s->failed_pc=0x0c0a050eu; return 0; }
r[1]=r[0];
goto P_0c0a0510;
P_0c0a0510: /* original 4108, guest PC 0x0c0a0510 */
if(!s->budget--) { s->failed_pc=0x0c0a0510u; return 0; }
r[1]<<=2;
goto P_0c0a0512;
P_0c0a0512: /* original 6303, guest PC 0x0c0a0512 */
if(!s->budget--) { s->failed_pc=0x0c0a0512u; return 0; }
r[3]=r[0];
goto P_0c0a0514;
P_0c0a0514: /* original 313c, guest PC 0x0c0a0514 */
if(!s->budget--) { s->failed_pc=0x0c0a0514u; return 0; }
r[1]+=r[3];
goto P_0c0a0516;
P_0c0a0516: /* original e3fa, guest PC 0x0c0a0516 */
if(!s->budget--) { s->failed_pc=0x0c0a0516u; return 0; }
r[3]=0xfffffffau;
goto P_0c0a0518;
P_0c0a0518: /* original 6c03, guest PC 0x0c0a0518 */
if(!s->budget--) { s->failed_pc=0x0c0a0518u; return 0; }
r[12]=r[0];
goto P_0c0a051a;
P_0c0a051a: /* original 443c, guest PC 0x0c0a051a */
if(!s->budget--) { s->failed_pc=0x0c0a051au; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c0a051c;
P_0c0a051c: /* original d332, guest PC 0x0c0a051c */
if(!s->budget--) { s->failed_pc=0x0c0a051cu; return 0; }
r[3]=read(ram,0x0c0a05e8u,4);
goto P_0c0a051e;
P_0c0a051e: /* original 4100, guest PC 0x0c0a051e */
if(!s->budget--) { s->failed_pc=0x0c0a051eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0a0520;
P_0c0a0520: /* original 3e18, guest PC 0x0c0a0520 */
if(!s->budget--) { s->failed_pc=0x0c0a0520u; return 0; }
r[14]-=r[1];
goto P_0c0a0522;
P_0c0a0522: /* original 6143, guest PC 0x0c0a0522 */
if(!s->budget--) { s->failed_pc=0x0c0a0522u; return 0; }
r[1]=r[4];
goto P_0c0a0524;
P_0c0a0524: /* original 430b, guest PC 0x0c0a0524 */
if(!s->budget--) { s->failed_pc=0x0c0a0524u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a0528u;
r[0]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0528u) { target=s->pc; goto dispatch; }
goto P_0c0a0528;
P_0c0a0526: /* original 6073, guest PC 0x0c0a0526 */
if(!s->budget--) { s->failed_pc=0x0c0a0526u; return 0; }
r[0]=r[7];
goto P_0c0a0528;
P_0c0a0528: /* original 6603, guest PC 0x0c0a0528 */
if(!s->budget--) { s->failed_pc=0x0c0a0528u; return 0; }
r[6]=r[0];
goto P_0c0a052a;
P_0c0a052a: /* original 6d43, guest PC 0x0c0a052a */
if(!s->budget--) { s->failed_pc=0x0c0a052au; return 0; }
r[13]=r[4];
goto P_0c0a052c;
P_0c0a052c: /* original 0677, guest PC 0x0c0a052c */
if(!s->budget--) { s->failed_pc=0x0c0a052cu; return 0; }
r[19]=r[6]*r[7];
goto P_0c0a052e;
P_0c0a052e: /* original d32e, guest PC 0x0c0a052e */
if(!s->budget--) { s->failed_pc=0x0c0a052eu; return 0; }
r[3]=read(ram,0x0c0a05e8u,4);
goto P_0c0a0530;
P_0c0a0530: /* original 071a, guest PC 0x0c0a0530 */
if(!s->budget--) { s->failed_pc=0x0c0a0530u; return 0; }
r[7]=r[19];
goto P_0c0a0532;
P_0c0a0532: /* original 3d78, guest PC 0x0c0a0532 */
if(!s->budget--) { s->failed_pc=0x0c0a0532u; return 0; }
r[13]-=r[7];
goto P_0c0a0534;
P_0c0a0534: /* original 61d3, guest PC 0x0c0a0534 */
if(!s->budget--) { s->failed_pc=0x0c0a0534u; return 0; }
r[1]=r[13];
goto P_0c0a0536;
P_0c0a0536: /* original 430b, guest PC 0x0c0a0536 */
if(!s->budget--) { s->failed_pc=0x0c0a0536u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a053au;
r[0]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a053au) { target=s->pc; goto dispatch; }
goto P_0c0a053a;
P_0c0a0538: /* original 6053, guest PC 0x0c0a0538 */
if(!s->budget--) { s->failed_pc=0x0c0a0538u; return 0; }
r[0]=r[5];
goto P_0c0a053a;
P_0c0a053a: /* original 6103, guest PC 0x0c0a053a */
if(!s->budget--) { s->failed_pc=0x0c0a053au; return 0; }
r[1]=r[0];
goto P_0c0a053c;
P_0c0a053c: /* original 4108, guest PC 0x0c0a053c */
if(!s->budget--) { s->failed_pc=0x0c0a053cu; return 0; }
r[1]<<=2;
goto P_0c0a053e;
P_0c0a053e: /* original 6303, guest PC 0x0c0a053e */
if(!s->budget--) { s->failed_pc=0x0c0a053eu; return 0; }
r[3]=r[0];
goto P_0c0a0540;
P_0c0a0540: /* original 313c, guest PC 0x0c0a0540 */
if(!s->budget--) { s->failed_pc=0x0c0a0540u; return 0; }
r[1]+=r[3];
goto P_0c0a0542;
P_0c0a0542: /* original 4100, guest PC 0x0c0a0542 */
if(!s->budget--) { s->failed_pc=0x0c0a0542u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0a0544;
P_0c0a0544: /* original d328, guest PC 0x0c0a0544 */
if(!s->budget--) { s->failed_pc=0x0c0a0544u; return 0; }
r[3]=read(ram,0x0c0a05e8u,4);
goto P_0c0a0546;
P_0c0a0546: /* original 3d18, guest PC 0x0c0a0546 */
if(!s->budget--) { s->failed_pc=0x0c0a0546u; return 0; }
r[13]-=r[1];
goto P_0c0a0548;
P_0c0a0548: /* original 6703, guest PC 0x0c0a0548 */
if(!s->budget--) { s->failed_pc=0x0c0a0548u; return 0; }
r[7]=r[0];
goto P_0c0a054a;
P_0c0a054a: /* original 6163, guest PC 0x0c0a054a */
if(!s->budget--) { s->failed_pc=0x0c0a054au; return 0; }
r[1]=r[6];
goto P_0c0a054c;
P_0c0a054c: /* original 430b, guest PC 0x0c0a054c */
if(!s->budget--) { s->failed_pc=0x0c0a054cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a0550u;
r[0]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0550u) { target=s->pc; goto dispatch; }
goto P_0c0a0550;
P_0c0a054e: /* original 6053, guest PC 0x0c0a054e */
if(!s->budget--) { s->failed_pc=0x0c0a054eu; return 0; }
r[0]=r[5];
goto P_0c0a0550;
P_0c0a0550: /* original 6103, guest PC 0x0c0a0550 */
if(!s->budget--) { s->failed_pc=0x0c0a0550u; return 0; }
r[1]=r[0];
goto P_0c0a0552;
P_0c0a0552: /* original 64f2, guest PC 0x0c0a0552 */
if(!s->budget--) { s->failed_pc=0x0c0a0552u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a0554;
P_0c0a0554: /* original 4108, guest PC 0x0c0a0554 */
if(!s->budget--) { s->failed_pc=0x0c0a0554u; return 0; }
r[1]<<=2;
goto P_0c0a0556;
P_0c0a0556: /* original 2fe6, guest PC 0x0c0a0556 */
if(!s->budget--) { s->failed_pc=0x0c0a0556u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0558;
P_0c0a0558: /* original 6303, guest PC 0x0c0a0558 */
if(!s->budget--) { s->failed_pc=0x0c0a0558u; return 0; }
r[3]=r[0];
goto P_0c0a055a;
P_0c0a055a: /* original 2fc6, guest PC 0x0c0a055a */
if(!s->budget--) { s->failed_pc=0x0c0a055au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a055c;
P_0c0a055c: /* original 313c, guest PC 0x0c0a055c */
if(!s->budget--) { s->failed_pc=0x0c0a055cu; return 0; }
r[1]+=r[3];
goto P_0c0a055e;
P_0c0a055e: /* original 2fd6, guest PC 0x0c0a055e */
if(!s->budget--) { s->failed_pc=0x0c0a055eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0560;
P_0c0a0560: /* original e307, guest PC 0x0c0a0560 */
if(!s->budget--) { s->failed_pc=0x0c0a0560u; return 0; }
r[3]=0x00000007u;
goto P_0c0a0562;
P_0c0a0562: /* original 2f76, guest PC 0x0c0a0562 */
if(!s->budget--) { s->failed_pc=0x0c0a0562u; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0564;
P_0c0a0564: /* original 740c, guest PC 0x0c0a0564 */
if(!s->budget--) { s->failed_pc=0x0c0a0564u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a0566;
P_0c0a0566: /* original 6503, guest PC 0x0c0a0566 */
if(!s->budget--) { s->failed_pc=0x0c0a0566u; return 0; }
r[5]=r[0];
goto P_0c0a0568;
P_0c0a0568: /* original 4100, guest PC 0x0c0a0568 */
if(!s->budget--) { s->failed_pc=0x0c0a0568u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0a056a;
P_0c0a056a: /* original 443c, guest PC 0x0c0a056a */
if(!s->budget--) { s->failed_pc=0x0c0a056au; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c0a056c;
P_0c0a056c: /* original 3618, guest PC 0x0c0a056c */
if(!s->budget--) { s->failed_pc=0x0c0a056cu; return 0; }
r[6]-=r[1];
goto P_0c0a056e;
P_0c0a056e: /* original 2f66, guest PC 0x0c0a056e */
if(!s->budget--) { s->failed_pc=0x0c0a056eu; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0570;
P_0c0a0570: /* original e12e, guest PC 0x0c0a0570 */
if(!s->budget--) { s->failed_pc=0x0c0a0570u; return 0; }
r[1]=0x0000002eu;
goto P_0c0a0572;
P_0c0a0572: /* original 241b, guest PC 0x0c0a0572 */
if(!s->budget--) { s->failed_pc=0x0c0a0572u; return 0; }
r[4]|=r[1];
goto P_0c0a0574;
P_0c0a0574: /* original 2f56, guest PC 0x0c0a0574 */
if(!s->budget--) { s->failed_pc=0x0c0a0574u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0576;
P_0c0a0576: /* original d31e, guest PC 0x0c0a0576 */
if(!s->budget--) { s->failed_pc=0x0c0a0576u; return 0; }
r[3]=read(ram,0x0c0a05f0u,4);
goto P_0c0a0578;
P_0c0a0578: /* original d21c, guest PC 0x0c0a0578 */
if(!s->budget--) { s->failed_pc=0x0c0a0578u; return 0; }
r[2]=read(ram,0x0c0a05ecu,4);
goto P_0c0a057a;
P_0c0a057a: /* original 430b, guest PC 0x0c0a057a */
if(!s->budget--) { s->failed_pc=0x0c0a057au; return 0; }
target=r[3];
r[16]=code_base|0x0c0a057eu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a057eu) { target=s->pc; goto dispatch; }
goto P_0c0a057e;
P_0c0a057c: /* original 2f26, guest PC 0x0c0a057c */
if(!s->budget--) { s->failed_pc=0x0c0a057cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a057e;
P_0c0a057e: /* original 7f24, guest PC 0x0c0a057e */
if(!s->budget--) { s->failed_pc=0x0c0a057eu; return 0; }
r[15]+=0x00000024u;
goto P_0c0a0580;
P_0c0a0580: /* original 4f16, guest PC 0x0c0a0580 */
if(!s->budget--) { s->failed_pc=0x0c0a0580u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a0582;
P_0c0a0582: /* original 4f26, guest PC 0x0c0a0582 */
if(!s->budget--) { s->failed_pc=0x0c0a0582u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a0584;
P_0c0a0584: /* original 6cf6, guest PC 0x0c0a0584 */
if(!s->budget--) { s->failed_pc=0x0c0a0584u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a0586;
P_0c0a0586: /* original 6df6, guest PC 0x0c0a0586 */
if(!s->budget--) { s->failed_pc=0x0c0a0586u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a0588;
P_0c0a0588: /* original 000b, guest PC 0x0c0a0588 */
if(!s->budget--) { s->failed_pc=0x0c0a0588u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a058a: /* original 6ef6, guest PC 0x0c0a058a */
if(!s->budget--) { s->failed_pc=0x0c0a058au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a058cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
