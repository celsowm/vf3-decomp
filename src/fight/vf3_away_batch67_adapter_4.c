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
int vf3_away_batch67_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c094368u: goto P_0c094368;
case 0x0c09436au: goto P_0c09436a;
case 0x0c09436cu: goto P_0c09436c;
case 0x0c09436eu: goto P_0c09436e;
case 0x0c094370u: goto P_0c094370;
case 0x0c094372u: goto P_0c094372;
case 0x0c094374u: goto P_0c094374;
case 0x0c094376u: goto P_0c094376;
case 0x0c094378u: goto P_0c094378;
case 0x0c09437au: goto P_0c09437a;
case 0x0c09437cu: goto P_0c09437c;
case 0x0c09437eu: goto P_0c09437e;
case 0x0c094380u: goto P_0c094380;
case 0x0c094382u: goto P_0c094382;
case 0x0c094384u: goto P_0c094384;
case 0x0c094386u: goto P_0c094386;
case 0x0c094388u: goto P_0c094388;
case 0x0c09438au: goto P_0c09438a;
case 0x0c09438cu: goto P_0c09438c;
case 0x0c09438eu: goto P_0c09438e;
case 0x0c094390u: goto P_0c094390;
case 0x0c094392u: goto P_0c094392;
case 0x0c094394u: goto P_0c094394;
case 0x0c094396u: goto P_0c094396;
case 0x0c094398u: goto P_0c094398;
case 0x0c09439au: goto P_0c09439a;
case 0x0c09439cu: goto P_0c09439c;
case 0x0c09439eu: goto P_0c09439e;
case 0x0c0943a0u: goto P_0c0943a0;
case 0x0c0943a2u: goto P_0c0943a2;
case 0x0c0943a4u: goto P_0c0943a4;
case 0x0c0943a6u: goto P_0c0943a6;
case 0x0c0943a8u: goto P_0c0943a8;
case 0x0c0943aau: goto P_0c0943aa;
case 0x0c0943acu: goto P_0c0943ac;
case 0x0c0943aeu: goto P_0c0943ae;
case 0x0c0943b0u: goto P_0c0943b0;
case 0x0c0943b2u: goto P_0c0943b2;
case 0x0c0943b4u: goto P_0c0943b4;
case 0x0c0943b6u: goto P_0c0943b6;
case 0x0c0943b8u: goto P_0c0943b8;
case 0x0c0943bau: goto P_0c0943ba;
case 0x0c0943f8u: goto P_0c0943f8;
case 0x0c0943fau: goto P_0c0943fa;
case 0x0c0943fcu: goto P_0c0943fc;
case 0x0c0943feu: goto P_0c0943fe;
case 0x0c094400u: goto P_0c094400;
case 0x0c094402u: goto P_0c094402;
case 0x0c094404u: goto P_0c094404;
case 0x0c094406u: goto P_0c094406;
case 0x0c094408u: goto P_0c094408;
case 0x0c09440au: goto P_0c09440a;
case 0x0c09440cu: goto P_0c09440c;
case 0x0c09440eu: goto P_0c09440e;
case 0x0c094410u: goto P_0c094410;
case 0x0c094412u: goto P_0c094412;
case 0x0c094414u: goto P_0c094414;
case 0x0c094416u: goto P_0c094416;
case 0x0c094418u: goto P_0c094418;
case 0x0c09441au: goto P_0c09441a;
case 0x0c094420u: goto P_0c094420;
case 0x0c094422u: goto P_0c094422;
case 0x0c094424u: goto P_0c094424;
case 0x0c094426u: goto P_0c094426;
case 0x0c094428u: goto P_0c094428;
case 0x0c09442au: goto P_0c09442a;
case 0x0c09442cu: goto P_0c09442c;
case 0x0c09442eu: goto P_0c09442e;
case 0x0c094430u: goto P_0c094430;
case 0x0c094432u: goto P_0c094432;
case 0x0c094434u: goto P_0c094434;
case 0x0c094436u: goto P_0c094436;
case 0x0c094438u: goto P_0c094438;
case 0x0c09443au: goto P_0c09443a;
case 0x0c09443cu: goto P_0c09443c;
case 0x0c09443eu: goto P_0c09443e;
case 0x0c094440u: goto P_0c094440;
case 0x0c094442u: goto P_0c094442;
case 0x0c094444u: goto P_0c094444;
case 0x0c094446u: goto P_0c094446;
case 0x0c094448u: goto P_0c094448;
case 0x0c09444au: goto P_0c09444a;
case 0x0c09444cu: goto P_0c09444c;
case 0x0c09444eu: goto P_0c09444e;
case 0x0c094450u: goto P_0c094450;
case 0x0c094452u: goto P_0c094452;
case 0x0c094454u: goto P_0c094454;
case 0x0c094456u: goto P_0c094456;
case 0x0c094458u: goto P_0c094458;
case 0x0c09445au: goto P_0c09445a;
case 0x0c09445cu: goto P_0c09445c;
case 0x0c09445eu: goto P_0c09445e;
case 0x0c094460u: goto P_0c094460;
case 0x0c094462u: goto P_0c094462;
case 0x0c094464u: goto P_0c094464;
case 0x0c094466u: goto P_0c094466;
case 0x0c094468u: goto P_0c094468;
case 0x0c094470u: goto P_0c094470;
case 0x0c094472u: goto P_0c094472;
case 0x0c094474u: goto P_0c094474;
case 0x0c094476u: goto P_0c094476;
case 0x0c094478u: goto P_0c094478;
case 0x0c09447au: goto P_0c09447a;
case 0x0c09447cu: goto P_0c09447c;
case 0x0c09447eu: goto P_0c09447e;
case 0x0c094480u: goto P_0c094480;
case 0x0c094482u: goto P_0c094482;
case 0x0c094484u: goto P_0c094484;
case 0x0c094486u: goto P_0c094486;
case 0x0c094488u: goto P_0c094488;
case 0x0c09448au: goto P_0c09448a;
case 0x0c09448cu: goto P_0c09448c;
case 0x0c09448eu: goto P_0c09448e;
case 0x0c094490u: goto P_0c094490;
case 0x0c094492u: goto P_0c094492;
case 0x0c094494u: goto P_0c094494;
case 0x0c094496u: goto P_0c094496;
case 0x0c094498u: goto P_0c094498;
case 0x0c09449au: goto P_0c09449a;
case 0x0c09449cu: goto P_0c09449c;
case 0x0c09449eu: goto P_0c09449e;
case 0x0c0944a0u: goto P_0c0944a0;
case 0x0c0944a2u: goto P_0c0944a2;
case 0x0c0944a4u: goto P_0c0944a4;
case 0x0c0944a6u: goto P_0c0944a6;
case 0x0c0944a8u: goto P_0c0944a8;
case 0x0c0944aau: goto P_0c0944aa;
case 0x0c0944acu: goto P_0c0944ac;
case 0x0c0944aeu: goto P_0c0944ae;
case 0x0c0944b0u: goto P_0c0944b0;
case 0x0c0944b2u: goto P_0c0944b2;
case 0x0c0944b4u: goto P_0c0944b4;
case 0x0c0944b6u: goto P_0c0944b6;
case 0x0c0944b8u: goto P_0c0944b8;
case 0x0c0944bau: goto P_0c0944ba;
case 0x0c0944bcu: goto P_0c0944bc;
case 0x0c0944beu: goto P_0c0944be;
case 0x0c0944c0u: goto P_0c0944c0;
case 0x0c0944c2u: goto P_0c0944c2;
case 0x0c0944c4u: goto P_0c0944c4;
case 0x0c0944c6u: goto P_0c0944c6;
case 0x0c0944c8u: goto P_0c0944c8;
case 0x0c0944cau: goto P_0c0944ca;
case 0x0c0944ccu: goto P_0c0944cc;
case 0x0c0944ceu: goto P_0c0944ce;
case 0x0c0944d0u: goto P_0c0944d0;
case 0x0c0944d2u: goto P_0c0944d2;
case 0x0c0944d4u: goto P_0c0944d4;
case 0x0c0944d6u: goto P_0c0944d6;
case 0x0c0944d8u: goto P_0c0944d8;
case 0x0c0944dau: goto P_0c0944da;
case 0x0c0944dcu: goto P_0c0944dc;
case 0x0c0944deu: goto P_0c0944de;
case 0x0c0944e0u: goto P_0c0944e0;
case 0x0c0944e2u: goto P_0c0944e2;
case 0x0c0944e4u: goto P_0c0944e4;
case 0x0c0944e6u: goto P_0c0944e6;
case 0x0c0944e8u: goto P_0c0944e8;
case 0x0c0944eau: goto P_0c0944ea;
case 0x0c0944ecu: goto P_0c0944ec;
case 0x0c0944eeu: goto P_0c0944ee;
case 0x0c0944f0u: goto P_0c0944f0;
case 0x0c094560u: goto P_0c094560;
case 0x0c094562u: goto P_0c094562;
case 0x0c094564u: goto P_0c094564;
case 0x0c094566u: goto P_0c094566;
case 0x0c094568u: goto P_0c094568;
case 0x0c09456au: goto P_0c09456a;
case 0x0c09456cu: goto P_0c09456c;
case 0x0c09456eu: goto P_0c09456e;
case 0x0c094570u: goto P_0c094570;
case 0x0c094572u: goto P_0c094572;
case 0x0c094574u: goto P_0c094574;
case 0x0c094576u: goto P_0c094576;
case 0x0c094578u: goto P_0c094578;
case 0x0c09457au: goto P_0c09457a;
case 0x0c09457cu: goto P_0c09457c;
case 0x0c09457eu: goto P_0c09457e;
case 0x0c094580u: goto P_0c094580;
case 0x0c094582u: goto P_0c094582;
case 0x0c094584u: goto P_0c094584;
case 0x0c094586u: goto P_0c094586;
case 0x0c094588u: goto P_0c094588;
case 0x0c09458au: goto P_0c09458a;
case 0x0c09458cu: goto P_0c09458c;
case 0x0c09458eu: goto P_0c09458e;
case 0x0c094590u: goto P_0c094590;
case 0x0c094592u: goto P_0c094592;
case 0x0c094594u: goto P_0c094594;
case 0x0c094596u: goto P_0c094596;
case 0x0c094598u: goto P_0c094598;
case 0x0c09459au: goto P_0c09459a;
case 0x0c09459cu: goto P_0c09459c;
case 0x0c09459eu: goto P_0c09459e;
case 0x0c0945a0u: goto P_0c0945a0;
case 0x0c0945a2u: goto P_0c0945a2;
case 0x0c0945a4u: goto P_0c0945a4;
case 0x0c0945a6u: goto P_0c0945a6;
case 0x0c0945a8u: goto P_0c0945a8;
case 0x0c0945aau: goto P_0c0945aa;
case 0x0c0945acu: goto P_0c0945ac;
case 0x0c0945aeu: goto P_0c0945ae;
case 0x0c0945b0u: goto P_0c0945b0;
case 0x0c0945b2u: goto P_0c0945b2;
case 0x0c0945b4u: goto P_0c0945b4;
case 0x0c0945b6u: goto P_0c0945b6;
case 0x0c0945b8u: goto P_0c0945b8;
case 0x0c0945bau: goto P_0c0945ba;
case 0x0c0945bcu: goto P_0c0945bc;
case 0x0c0945beu: goto P_0c0945be;
case 0x0c0945c0u: goto P_0c0945c0;
case 0x0c0945c2u: goto P_0c0945c2;
case 0x0c0945c4u: goto P_0c0945c4;
case 0x0c0945c6u: goto P_0c0945c6;
case 0x0c0945c8u: goto P_0c0945c8;
case 0x0c0945cau: goto P_0c0945ca;
case 0x0c0945ccu: goto P_0c0945cc;
case 0x0c0945ceu: goto P_0c0945ce;
case 0x0c0945d0u: goto P_0c0945d0;
case 0x0c0945d2u: goto P_0c0945d2;
case 0x0c0945d4u: goto P_0c0945d4;
case 0x0c0945d6u: goto P_0c0945d6;
case 0x0c0945d8u: goto P_0c0945d8;
case 0x0c0945dau: goto P_0c0945da;
case 0x0c0945dcu: goto P_0c0945dc;
case 0x0c0945deu: goto P_0c0945de;
case 0x0c0945e0u: goto P_0c0945e0;
case 0x0c0945e2u: goto P_0c0945e2;
case 0x0c0945e4u: goto P_0c0945e4;
case 0x0c0945e6u: goto P_0c0945e6;
case 0x0c0945e8u: goto P_0c0945e8;
case 0x0c0945eau: goto P_0c0945ea;
case 0x0c0945ecu: goto P_0c0945ec;
case 0x0c0945eeu: goto P_0c0945ee;
case 0x0c0945f0u: goto P_0c0945f0;
default: return vf3_matrix_family(target,s,ram);
}
P_0c094368: /* original 2fe6, guest PC 0x0c094368 */
if(!s->budget--) { s->failed_pc=0x0c094368u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09436a;
P_0c09436a: /* original 2fd6, guest PC 0x0c09436a */
if(!s->budget--) { s->failed_pc=0x0c09436au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09436c;
P_0c09436c: /* original 2fc6, guest PC 0x0c09436c */
if(!s->budget--) { s->failed_pc=0x0c09436cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09436e;
P_0c09436e: /* original 2fb6, guest PC 0x0c09436e */
if(!s->budget--) { s->failed_pc=0x0c09436eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094370;
P_0c094370: /* original fffb, guest PC 0x0c094370 */
if(!s->budget--) { s->failed_pc=0x0c094370u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c094372;
P_0c094372: /* original 4f22, guest PC 0x0c094372 */
if(!s->budget--) { s->failed_pc=0x0c094372u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c094374;
P_0c094374: /* original 7fd8, guest PC 0x0c094374 */
if(!s->budget--) { s->failed_pc=0x0c094374u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c094376;
P_0c094376: /* original 2f42, guest PC 0x0c094376 */
if(!s->budget--) { s->failed_pc=0x0c094376u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c094378;
P_0c094378: /* original 1f51, guest PC 0x0c094378 */
if(!s->budget--) { s->failed_pc=0x0c094378u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c09437a;
P_0c09437a: /* original d41a, guest PC 0x0c09437a */
if(!s->budget--) { s->failed_pc=0x0c09437au; return 0; }
r[4]=read(ram,0x0c0943e4u,4);
goto P_0c09437c;
P_0c09437c: /* original 901e, guest PC 0x0c09437c */
if(!s->budget--) { s->failed_pc=0x0c09437cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0943bcu,2);
goto P_0c09437e;
P_0c09437e: /* original dd18, guest PC 0x0c09437e */
if(!s->budget--) { s->failed_pc=0x0c09437eu; return 0; }
r[13]=read(ram,0x0c0943e0u,4);
goto P_0c094380;
P_0c094380: /* original 034e, guest PC 0x0c094380 */
if(!s->budget--) { s->failed_pc=0x0c094380u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c094382;
P_0c094382: /* original 2338, guest PC 0x0c094382 */
if(!s->budget--) { s->failed_pc=0x0c094382u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c094384;
P_0c094384: /* original 8900, guest PC 0x0c094384 */
if(!s->budget--) { s->failed_pc=0x0c094384u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094388; }
goto P_0c094386;
P_0c094386: /* original dd18, guest PC 0x0c094386 */
if(!s->budget--) { s->failed_pc=0x0c094386u; return 0; }
r[13]=read(ram,0x0c0943e8u,4);
goto P_0c094388;
P_0c094388: /* original c718, guest PC 0x0c094388 */
if(!s->budget--) { s->failed_pc=0x0c094388u; return 0; }
r[0]=code_base|0x000943ecu;
goto P_0c09438a;
P_0c09438a: /* original ff08, guest PC 0x0c09438a */
if(!s->budget--) { s->failed_pc=0x0c09438au; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c09438c;
P_0c09438c: /* original 6cd1, guest PC 0x0c09438c */
if(!s->budget--) { s->failed_pc=0x0c09438cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[12]=tmp;
goto P_0c09438e;
P_0c09438e: /* original 2cc8, guest PC 0x0c09438e */
if(!s->budget--) { s->failed_pc=0x0c09438eu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c094390;
P_0c094390: /* original 8b02, guest PC 0x0c094390 */
if(!s->budget--) { s->failed_pc=0x0c094390u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094398; }
goto P_0c094392;
P_0c094392: /* original d317, guest PC 0x0c094392 */
if(!s->budget--) { s->failed_pc=0x0c094392u; return 0; }
r[3]=read(ram,0x0c0943f0u,4);
goto P_0c094394;
P_0c094394: /* original 432b, guest PC 0x0c094394 */
if(!s->budget--) { s->failed_pc=0x0c094394u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09448cu: goto P_0c09448c;
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
P_0c094396: /* original 0009, guest PC 0x0c094396 */
if(!s->budget--) { s->failed_pc=0x0c094396u; return 0; }
goto P_0c094398;
P_0c094398: /* original 85d1, guest PC 0x0c094398 */
if(!s->budget--) { s->failed_pc=0x0c094398u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+2,2);
goto P_0c09439a;
P_0c09439a: /* original 5ef1, guest PC 0x0c09439a */
if(!s->budget--) { s->failed_pc=0x0c09439au; return 0; }
r[14]=read(ram,r[15]+4,4);
goto P_0c09439c;
P_0c09439c: /* original 6403, guest PC 0x0c09439c */
if(!s->budget--) { s->failed_pc=0x0c09439cu; return 0; }
r[4]=r[0];
goto P_0c09439e;
P_0c09439e: /* original 3e4c, guest PC 0x0c09439e */
if(!s->budget--) { s->failed_pc=0x0c09439eu; return 0; }
r[14]+=r[4];
goto P_0c0943a0;
P_0c0943a0: /* original 0e83, guest PC 0x0c0943a0 */
if(!s->budget--) { s->failed_pc=0x0c0943a0u; return 0; }
if((r[14]&0xFC000000u)==0xE0000000u) pref(ram,r[14]);
goto P_0c0943a2;
P_0c0943a2: /* original 53d1, guest PC 0x0c0943a2 */
if(!s->budget--) { s->failed_pc=0x0c0943a2u; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0943a4;
P_0c0943a4: /* original 1f32, guest PC 0x0c0943a4 */
if(!s->budget--) { s->failed_pc=0x0c0943a4u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0943a6;
P_0c0943a6: /* original 52d2, guest PC 0x0c0943a6 */
if(!s->budget--) { s->failed_pc=0x0c0943a6u; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c0943a8;
P_0c0943a8: /* original 1f23, guest PC 0x0c0943a8 */
if(!s->budget--) { s->failed_pc=0x0c0943a8u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0943aa;
P_0c0943aa: /* original d312, guest PC 0x0c0943aa */
if(!s->budget--) { s->failed_pc=0x0c0943aau; return 0; }
r[3]=read(ram,0x0c0943f4u,4);
goto P_0c0943ac;
P_0c0943ac: /* original 430b, guest PC 0x0c0943ac */
if(!s->budget--) { s->failed_pc=0x0c0943acu; return 0; }
target=r[3];
r[16]=code_base|0x0c0943b0u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0943b0u) { target=s->pc; goto dispatch; }
goto P_0c0943b0;
P_0c0943ae: /* original 64f2, guest PC 0x0c0943ae */
if(!s->budget--) { s->failed_pc=0x0c0943aeu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0943b0;
P_0c0943b0: /* original 64d3, guest PC 0x0c0943b0 */
if(!s->budget--) { s->failed_pc=0x0c0943b0u; return 0; }
r[4]=r[13];
goto P_0c0943b2;
P_0c0943b2: /* original 65f3, guest PC 0x0c0943b2 */
if(!s->budget--) { s->failed_pc=0x0c0943b2u; return 0; }
r[5]=r[15];
goto P_0c0943b4;
P_0c0943b4: /* original 740c, guest PC 0x0c0943b4 */
if(!s->budget--) { s->failed_pc=0x0c0943b4u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0943b6;
P_0c0943b6: /* original 751c, guest PC 0x0c0943b6 */
if(!s->budget--) { s->failed_pc=0x0c0943b6u; return 0; }
r[5]+=0x0000001cu;
goto P_0c0943b8;
P_0c0943b8: /* original a01e, guest PC 0x0c0943b8 */
if(!s->budget--) { s->failed_pc=0x0c0943b8u; return 0; }
goto P_0c0943f8;
P_0c0943ba: /* original 0009, guest PC 0x0c0943ba */
if(!s->budget--) { s->failed_pc=0x0c0943bau; return 0; }
if(!vf3_matrix_family(0x0c0943bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0943bcu; return 0; } return 1;
P_0c0943f8: /* original f449, guest PC 0x0c0943f8 */
if(!s->budget--) { s->failed_pc=0x0c0943f8u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0943fa;
P_0c0943fa: /* original f549, guest PC 0x0c0943fa */
if(!s->budget--) { s->failed_pc=0x0c0943fau; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0943fc;
P_0c0943fc: /* original f648, guest PC 0x0c0943fc */
if(!s->budget--) { s->failed_pc=0x0c0943fcu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0943fe;
P_0c0943fe: /* original f79d, guest PC 0x0c0943fe */
if(!s->budget--) { s->failed_pc=0x0c0943feu; return 0; }
fr[7]=0x3f800000u;
goto P_0c094400;
P_0c094400: /* original f5fd, guest PC 0x0c094400 */
if(!s->budget--) { s->failed_pc=0x0c094400u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c094402;
P_0c094402: /* original 750c, guest PC 0x0c094402 */
if(!s->budget--) { s->failed_pc=0x0c094402u; return 0; }
r[5]+=0x0000000cu;
goto P_0c094404;
P_0c094404: /* original f56b, guest PC 0x0c094404 */
if(!s->budget--) { s->failed_pc=0x0c094404u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c094406;
P_0c094406: /* original f55b, guest PC 0x0c094406 */
if(!s->budget--) { s->failed_pc=0x0c094406u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c094408;
P_0c094408: /* original f54b, guest PC 0x0c094408 */
if(!s->budget--) { s->failed_pc=0x0c094408u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c09440a;
P_0c09440a: /* original 0009, guest PC 0x0c09440a */
if(!s->budget--) { s->failed_pc=0x0c09440au; return 0; }
goto P_0c09440c;
P_0c09440c: /* original 7d18, guest PC 0x0c09440c */
if(!s->budget--) { s->failed_pc=0x0c09440cu; return 0; }
r[13]+=0x00000018u;
goto P_0c09440e;
P_0c09440e: /* original d303, guest PC 0x0c09440e */
if(!s->budget--) { s->failed_pc=0x0c09440eu; return 0; }
r[3]=read(ram,0x0c09441cu,4);
goto P_0c094410;
P_0c094410: /* original 430b, guest PC 0x0c094410 */
if(!s->budget--) { s->failed_pc=0x0c094410u; return 0; }
target=r[3];
r[16]=code_base|0x0c094414u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c094414u) { target=s->pc; goto dispatch; }
goto P_0c094414;
P_0c094412: /* original 64e3, guest PC 0x0c094412 */
if(!s->budget--) { s->failed_pc=0x0c094412u; return 0; }
r[4]=r[14];
goto P_0c094414;
P_0c094414: /* original 64f3, guest PC 0x0c094414 */
if(!s->budget--) { s->failed_pc=0x0c094414u; return 0; }
r[4]=r[15];
goto P_0c094416;
P_0c094416: /* original 741c, guest PC 0x0c094416 */
if(!s->budget--) { s->failed_pc=0x0c094416u; return 0; }
r[4]+=0x0000001cu;
goto P_0c094418;
P_0c094418: /* original a002, guest PC 0x0c094418 */
if(!s->budget--) { s->failed_pc=0x0c094418u; return 0; }
goto P_0c094420;
P_0c09441a: /* original 0009, guest PC 0x0c09441a */
if(!s->budget--) { s->failed_pc=0x0c09441au; return 0; }
if(!vf3_matrix_family(0x0c09441cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09441cu; return 0; } return 1;
P_0c094420: /* original fbfd, guest PC 0x0c094420 */
if(!s->budget--) { s->failed_pc=0x0c094420u; return 0; }
vf3_matrix_swap(s);
goto P_0c094422;
P_0c094422: /* original fc49, guest PC 0x0c094422 */
if(!s->budget--) { s->failed_pc=0x0c094422u; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094424;
P_0c094424: /* original fd49, guest PC 0x0c094424 */
if(!s->budget--) { s->failed_pc=0x0c094424u; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094426;
P_0c094426: /* original fe49, guest PC 0x0c094426 */
if(!s->budget--) { s->failed_pc=0x0c094426u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094428;
P_0c094428: /* original fbfd, guest PC 0x0c094428 */
if(!s->budget--) { s->failed_pc=0x0c094428u; return 0; }
vf3_matrix_swap(s);
goto P_0c09442a;
P_0c09442a: /* original 0009, guest PC 0x0c09442a */
if(!s->budget--) { s->failed_pc=0x0c09442au; return 0; }
goto P_0c09442c;
P_0c09442c: /* original 4c10, guest PC 0x0c09442c */
if(!s->budget--) { s->failed_pc=0x0c09442cu; return 0; }
--r[12];
r[17]=(r[17]&~1u)|((r[12]==0)!=0);
goto P_0c09442e;
P_0c09442e: /* original 8d15, guest PC 0x0c09442e */
if(!s->budget--) { s->failed_pc=0x0c09442eu; return 0; }
cond=r[17]&1u;
r[11]=read(ram,r[15]+12,4);
if(cond) { goto P_0c09445c; }
goto P_0c094432;
P_0c094430: /* original 5bf3, guest PC 0x0c094430 */
if(!s->budget--) { s->failed_pc=0x0c094430u; return 0; }
r[11]=read(ram,r[15]+12,4);
goto P_0c094432;
P_0c094432: /* original e01c, guest PC 0x0c094432 */
if(!s->budget--) { s->failed_pc=0x0c094432u; return 0; }
r[0]=0x0000001cu;
goto P_0c094434;
P_0c094434: /* original f2e9, guest PC 0x0c094434 */
if(!s->budget--) { s->failed_pc=0x0c094434u; return 0; }
vf3_matrix_load(s,ram,2,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c094436;
P_0c094436: /* original f3f6, guest PC 0x0c094436 */
if(!s->budget--) { s->failed_pc=0x0c094436u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c094438;
P_0c094438: /* original e01c, guest PC 0x0c094438 */
if(!s->budget--) { s->failed_pc=0x0c094438u; return 0; }
r[0]=0x0000001cu;
goto P_0c09443a;
P_0c09443a: /* original f0fc, guest PC 0x0c09443a */
if(!s->budget--) { s->failed_pc=0x0c09443au; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c09443c;
P_0c09443c: /* original f32e, guest PC 0x0c09443c */
if(!s->budget--) { s->failed_pc=0x0c09443cu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09443e;
P_0c09443e: /* original 5bf2, guest PC 0x0c09443e */
if(!s->budget--) { s->failed_pc=0x0c09443eu; return 0; }
r[11]=read(ram,r[15]+8,4);
goto P_0c094440;
P_0c094440: /* original ff37, guest PC 0x0c094440 */
if(!s->budget--) { s->failed_pc=0x0c094440u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c094442;
P_0c094442: /* original e020, guest PC 0x0c094442 */
if(!s->budget--) { s->failed_pc=0x0c094442u; return 0; }
r[0]=0x00000020u;
goto P_0c094444;
P_0c094444: /* original f2e9, guest PC 0x0c094444 */
if(!s->budget--) { s->failed_pc=0x0c094444u; return 0; }
vf3_matrix_load(s,ram,2,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c094446;
P_0c094446: /* original f3f6, guest PC 0x0c094446 */
if(!s->budget--) { s->failed_pc=0x0c094446u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c094448;
P_0c094448: /* original e020, guest PC 0x0c094448 */
if(!s->budget--) { s->failed_pc=0x0c094448u; return 0; }
r[0]=0x00000020u;
goto P_0c09444a;
P_0c09444a: /* original f32e, guest PC 0x0c09444a */
if(!s->budget--) { s->failed_pc=0x0c09444au; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09444c;
P_0c09444c: /* original ff37, guest PC 0x0c09444c */
if(!s->budget--) { s->failed_pc=0x0c09444cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09444e;
P_0c09444e: /* original e024, guest PC 0x0c09444e */
if(!s->budget--) { s->failed_pc=0x0c09444eu; return 0; }
r[0]=0x00000024u;
goto P_0c094450;
P_0c094450: /* original f2e9, guest PC 0x0c094450 */
if(!s->budget--) { s->failed_pc=0x0c094450u; return 0; }
vf3_matrix_load(s,ram,2,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c094452;
P_0c094452: /* original f3f6, guest PC 0x0c094452 */
if(!s->budget--) { s->failed_pc=0x0c094452u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c094454;
P_0c094454: /* original e024, guest PC 0x0c094454 */
if(!s->budget--) { s->failed_pc=0x0c094454u; return 0; }
r[0]=0x00000024u;
goto P_0c094456;
P_0c094456: /* original 7e18, guest PC 0x0c094456 */
if(!s->budget--) { s->failed_pc=0x0c094456u; return 0; }
r[14]+=0x00000018u;
goto P_0c094458;
P_0c094458: /* original f32e, guest PC 0x0c094458 */
if(!s->budget--) { s->failed_pc=0x0c094458u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09445a;
P_0c09445a: /* original ff37, guest PC 0x0c09445a */
if(!s->budget--) { s->failed_pc=0x0c09445au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09445c;
P_0c09445c: /* original d303, guest PC 0x0c09445c */
if(!s->budget--) { s->failed_pc=0x0c09445cu; return 0; }
r[3]=read(ram,0x0c09446cu,4);
goto P_0c09445e;
P_0c09445e: /* original 430b, guest PC 0x0c09445e */
if(!s->budget--) { s->failed_pc=0x0c09445eu; return 0; }
target=r[3];
r[16]=code_base|0x0c094462u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c094462u) { target=s->pc; goto dispatch; }
goto P_0c094462;
P_0c094460: /* original 64b3, guest PC 0x0c094460 */
if(!s->budget--) { s->failed_pc=0x0c094460u; return 0; }
r[4]=r[11];
goto P_0c094462;
P_0c094462: /* original 64f3, guest PC 0x0c094462 */
if(!s->budget--) { s->failed_pc=0x0c094462u; return 0; }
r[4]=r[15];
goto P_0c094464;
P_0c094464: /* original 741c, guest PC 0x0c094464 */
if(!s->budget--) { s->failed_pc=0x0c094464u; return 0; }
r[4]+=0x0000001cu;
goto P_0c094466;
P_0c094466: /* original a003, guest PC 0x0c094466 */
if(!s->budget--) { s->failed_pc=0x0c094466u; return 0; }
goto P_0c094470;
P_0c094468: /* original 0009, guest PC 0x0c094468 */
if(!s->budget--) { s->failed_pc=0x0c094468u; return 0; }
if(!vf3_matrix_family(0x0c09446au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09446au; return 0; } return 1;
P_0c094470: /* original fbfd, guest PC 0x0c094470 */
if(!s->budget--) { s->failed_pc=0x0c094470u; return 0; }
vf3_matrix_swap(s);
goto P_0c094472;
P_0c094472: /* original fc49, guest PC 0x0c094472 */
if(!s->budget--) { s->failed_pc=0x0c094472u; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094474;
P_0c094474: /* original fd49, guest PC 0x0c094474 */
if(!s->budget--) { s->failed_pc=0x0c094474u; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094476;
P_0c094476: /* original fe49, guest PC 0x0c094476 */
if(!s->budget--) { s->failed_pc=0x0c094476u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094478;
P_0c094478: /* original fbfd, guest PC 0x0c094478 */
if(!s->budget--) { s->failed_pc=0x0c094478u; return 0; }
vf3_matrix_swap(s);
goto P_0c09447a;
P_0c09447a: /* original 0009, guest PC 0x0c09447a */
if(!s->budget--) { s->failed_pc=0x0c09447au; return 0; }
goto P_0c09447c;
P_0c09447c: /* original 2cc8, guest PC 0x0c09447c */
if(!s->budget--) { s->failed_pc=0x0c09447cu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c09447e;
P_0c09447e: /* original 8902, guest PC 0x0c09447e */
if(!s->budget--) { s->failed_pc=0x0c09447eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094486; }
goto P_0c094480;
P_0c094480: /* original d32a, guest PC 0x0c094480 */
if(!s->budget--) { s->failed_pc=0x0c094480u; return 0; }
r[3]=read(ram,0x0c09452cu,4);
goto P_0c094482;
P_0c094482: /* original 432b, guest PC 0x0c094482 */
if(!s->budget--) { s->failed_pc=0x0c094482u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09440eu: goto P_0c09440e;
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
P_0c094484: /* original 0009, guest PC 0x0c094484 */
if(!s->budget--) { s->failed_pc=0x0c094484u; return 0; }
goto P_0c094486;
P_0c094486: /* original d32a, guest PC 0x0c094486 */
if(!s->budget--) { s->failed_pc=0x0c094486u; return 0; }
r[3]=read(ram,0x0c094530u,4);
goto P_0c094488;
P_0c094488: /* original 432b, guest PC 0x0c094488 */
if(!s->budget--) { s->failed_pc=0x0c094488u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09438cu: goto P_0c09438c;
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
P_0c09448a: /* original 0009, guest PC 0x0c09448a */
if(!s->budget--) { s->failed_pc=0x0c09448au; return 0; }
goto P_0c09448c;
P_0c09448c: /* original 7f28, guest PC 0x0c09448c */
if(!s->budget--) { s->failed_pc=0x0c09448cu; return 0; }
r[15]+=0x00000028u;
goto P_0c09448e;
P_0c09448e: /* original 4f26, guest PC 0x0c09448e */
if(!s->budget--) { s->failed_pc=0x0c09448eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c094490;
P_0c094490: /* original fff9, guest PC 0x0c094490 */
if(!s->budget--) { s->failed_pc=0x0c094490u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c094492;
P_0c094492: /* original 6bf6, guest PC 0x0c094492 */
if(!s->budget--) { s->failed_pc=0x0c094492u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c094494;
P_0c094494: /* original 6cf6, guest PC 0x0c094494 */
if(!s->budget--) { s->failed_pc=0x0c094494u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c094496;
P_0c094496: /* original 6df6, guest PC 0x0c094496 */
if(!s->budget--) { s->failed_pc=0x0c094496u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c094498;
P_0c094498: /* original 000b, guest PC 0x0c094498 */
if(!s->budget--) { s->failed_pc=0x0c094498u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09449a: /* original 6ef6, guest PC 0x0c09449a */
if(!s->budget--) { s->failed_pc=0x0c09449au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09449c;
P_0c09449c: /* original 2fe6, guest PC 0x0c09449c */
if(!s->budget--) { s->failed_pc=0x0c09449cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09449e;
P_0c09449e: /* original 6e53, guest PC 0x0c09449e */
if(!s->budget--) { s->failed_pc=0x0c09449eu; return 0; }
r[14]=r[5];
goto P_0c0944a0;
P_0c0944a0: /* original e034, guest PC 0x0c0944a0 */
if(!s->budget--) { s->failed_pc=0x0c0944a0u; return 0; }
r[0]=0x00000034u;
goto P_0c0944a2;
P_0c0944a2: /* original 00ed, guest PC 0x0c0944a2 */
if(!s->budget--) { s->failed_pc=0x0c0944a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0944a4;
P_0c0944a4: /* original 4f22, guest PC 0x0c0944a4 */
if(!s->budget--) { s->failed_pc=0x0c0944a4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0944a6;
P_0c0944a6: /* original 600d, guest PC 0x0c0944a6 */
if(!s->budget--) { s->failed_pc=0x0c0944a6u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0944a8;
P_0c0944a8: /* original c880, guest PC 0x0c0944a8 */
if(!s->budget--) { s->failed_pc=0x0c0944a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0944aa;
P_0c0944aa: /* original 7fc0, guest PC 0x0c0944aa */
if(!s->budget--) { s->failed_pc=0x0c0944aau; return 0; }
r[15]+=0xffffffc0u;
goto P_0c0944ac;
P_0c0944ac: /* original 8b1d, guest PC 0x0c0944ac */
if(!s->budget--) { s->failed_pc=0x0c0944acu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0944ea; }
goto P_0c0944ae;
P_0c0944ae: /* original e054, guest PC 0x0c0944ae */
if(!s->budget--) { s->failed_pc=0x0c0944aeu; return 0; }
r[0]=0x00000054u;
goto P_0c0944b0;
P_0c0944b0: /* original d320, guest PC 0x0c0944b0 */
if(!s->budget--) { s->failed_pc=0x0c0944b0u; return 0; }
r[3]=read(ram,0x0c094534u,4);
goto P_0c0944b2;
P_0c0944b2: /* original 02ed, guest PC 0x0c0944b2 */
if(!s->budget--) { s->failed_pc=0x0c0944b2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0944b4;
P_0c0944b4: /* original 622d, guest PC 0x0c0944b4 */
if(!s->budget--) { s->failed_pc=0x0c0944b4u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0944b6;
P_0c0944b6: /* original 430b, guest PC 0x0c0944b6 */
if(!s->budget--) { s->failed_pc=0x0c0944b6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0944bau;
r[4]+=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0944bau) { target=s->pc; goto dispatch; }
goto P_0c0944ba;
P_0c0944b8: /* original 342c, guest PC 0x0c0944b8 */
if(!s->budget--) { s->failed_pc=0x0c0944b8u; return 0; }
r[4]+=r[2];
goto P_0c0944ba;
P_0c0944ba: /* original d21f, guest PC 0x0c0944ba */
if(!s->budget--) { s->failed_pc=0x0c0944bau; return 0; }
r[2]=read(ram,0x0c094538u,4);
goto P_0c0944bc;
P_0c0944bc: /* original 64e3, guest PC 0x0c0944bc */
if(!s->budget--) { s->failed_pc=0x0c0944bcu; return 0; }
r[4]=r[14];
goto P_0c0944be;
P_0c0944be: /* original 420b, guest PC 0x0c0944be */
if(!s->budget--) { s->failed_pc=0x0c0944beu; return 0; }
target=r[2];
r[16]=code_base|0x0c0944c2u;
r[4]+=0x00000038u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0944c2u) { target=s->pc; goto dispatch; }
goto P_0c0944c2;
P_0c0944c0: /* original 7438, guest PC 0x0c0944c0 */
if(!s->budget--) { s->failed_pc=0x0c0944c0u; return 0; }
r[4]+=0x00000038u;
goto P_0c0944c2;
P_0c0944c2: /* original d31e, guest PC 0x0c0944c2 */
if(!s->budget--) { s->failed_pc=0x0c0944c2u; return 0; }
r[3]=read(ram,0x0c09453cu,4);
goto P_0c0944c4;
P_0c0944c4: /* original e032, guest PC 0x0c0944c4 */
if(!s->budget--) { s->failed_pc=0x0c0944c4u; return 0; }
r[0]=0x00000032u;
goto P_0c0944c6;
P_0c0944c6: /* original 430b, guest PC 0x0c0944c6 */
if(!s->budget--) { s->failed_pc=0x0c0944c6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0944cau;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0944cau) { target=s->pc; goto dispatch; }
goto P_0c0944ca;
P_0c0944c8: /* original 04ed, guest PC 0x0c0944c8 */
if(!s->budget--) { s->failed_pc=0x0c0944c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0944ca;
P_0c0944ca: /* original d31d, guest PC 0x0c0944ca */
if(!s->budget--) { s->failed_pc=0x0c0944cau; return 0; }
r[3]=read(ram,0x0c094540u,4);
goto P_0c0944cc;
P_0c0944cc: /* original e030, guest PC 0x0c0944cc */
if(!s->budget--) { s->failed_pc=0x0c0944ccu; return 0; }
r[0]=0x00000030u;
goto P_0c0944ce;
P_0c0944ce: /* original 430b, guest PC 0x0c0944ce */
if(!s->budget--) { s->failed_pc=0x0c0944ceu; return 0; }
target=r[3];
r[16]=code_base|0x0c0944d2u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0944d2u) { target=s->pc; goto dispatch; }
goto P_0c0944d2;
P_0c0944d0: /* original 04ed, guest PC 0x0c0944d0 */
if(!s->budget--) { s->failed_pc=0x0c0944d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0944d2;
P_0c0944d2: /* original d31c, guest PC 0x0c0944d2 */
if(!s->budget--) { s->failed_pc=0x0c0944d2u; return 0; }
r[3]=read(ram,0x0c094544u,4);
goto P_0c0944d4;
P_0c0944d4: /* original e02e, guest PC 0x0c0944d4 */
if(!s->budget--) { s->failed_pc=0x0c0944d4u; return 0; }
r[0]=0x0000002eu;
goto P_0c0944d6;
P_0c0944d6: /* original 430b, guest PC 0x0c0944d6 */
if(!s->budget--) { s->failed_pc=0x0c0944d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0944dau;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0944dau) { target=s->pc; goto dispatch; }
goto P_0c0944da;
P_0c0944d8: /* original 04ed, guest PC 0x0c0944d8 */
if(!s->budget--) { s->failed_pc=0x0c0944d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0944da;
P_0c0944da: /* original 7f40, guest PC 0x0c0944da */
if(!s->budget--) { s->failed_pc=0x0c0944dau; return 0; }
r[15]+=0x00000040u;
goto P_0c0944dc;
P_0c0944dc: /* original d31a, guest PC 0x0c0944dc */
if(!s->budget--) { s->failed_pc=0x0c0944dcu; return 0; }
r[3]=read(ram,0x0c094548u,4);
goto P_0c0944de;
P_0c0944de: /* original e02c, guest PC 0x0c0944de */
if(!s->budget--) { s->failed_pc=0x0c0944deu; return 0; }
r[0]=0x0000002cu;
goto P_0c0944e0;
P_0c0944e0: /* original 4f26, guest PC 0x0c0944e0 */
if(!s->budget--) { s->failed_pc=0x0c0944e0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0944e2;
P_0c0944e2: /* original 04ed, guest PC 0x0c0944e2 */
if(!s->budget--) { s->failed_pc=0x0c0944e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0944e4;
P_0c0944e4: /* original 644d, guest PC 0x0c0944e4 */
if(!s->budget--) { s->failed_pc=0x0c0944e4u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0944e6;
P_0c0944e6: /* original 432b, guest PC 0x0c0944e6 */
if(!s->budget--) { s->failed_pc=0x0c0944e6u; return 0; }
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
P_0c0944e8: /* original 6ef6, guest PC 0x0c0944e8 */
if(!s->budget--) { s->failed_pc=0x0c0944e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0944ea;
P_0c0944ea: /* original 7f40, guest PC 0x0c0944ea */
if(!s->budget--) { s->failed_pc=0x0c0944eau; return 0; }
r[15]+=0x00000040u;
goto P_0c0944ec;
P_0c0944ec: /* original 4f26, guest PC 0x0c0944ec */
if(!s->budget--) { s->failed_pc=0x0c0944ecu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0944ee;
P_0c0944ee: /* original 000b, guest PC 0x0c0944ee */
if(!s->budget--) { s->failed_pc=0x0c0944eeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0944f0: /* original 6ef6, guest PC 0x0c0944f0 */
if(!s->budget--) { s->failed_pc=0x0c0944f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0944f2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0944f2u; return 0; } return 1;
P_0c094560: /* original 2fe6, guest PC 0x0c094560 */
if(!s->budget--) { s->failed_pc=0x0c094560u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094562;
P_0c094562: /* original c740, guest PC 0x0c094562 */
if(!s->budget--) { s->failed_pc=0x0c094562u; return 0; }
r[0]=code_base|0x00094664u;
goto P_0c094564;
P_0c094564: /* original 2fd6, guest PC 0x0c094564 */
if(!s->budget--) { s->failed_pc=0x0c094564u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094566;
P_0c094566: /* original 6e43, guest PC 0x0c094566 */
if(!s->budget--) { s->failed_pc=0x0c094566u; return 0; }
r[14]=r[4];
goto P_0c094568;
P_0c094568: /* original 2fc6, guest PC 0x0c094568 */
if(!s->budget--) { s->failed_pc=0x0c094568u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09456a;
P_0c09456a: /* original 2fb6, guest PC 0x0c09456a */
if(!s->budget--) { s->failed_pc=0x0c09456au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09456c;
P_0c09456c: /* original eb32, guest PC 0x0c09456c */
if(!s->budget--) { s->failed_pc=0x0c09456cu; return 0; }
r[11]=0x00000032u;
goto P_0c09456e;
P_0c09456e: /* original 2fa6, guest PC 0x0c09456e */
if(!s->budget--) { s->failed_pc=0x0c09456eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094570;
P_0c094570: /* original ea00, guest PC 0x0c094570 */
if(!s->budget--) { s->failed_pc=0x0c094570u; return 0; }
r[10]=0x00000000u;
goto P_0c094572;
P_0c094572: /* original 2f96, guest PC 0x0c094572 */
if(!s->budget--) { s->failed_pc=0x0c094572u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094574;
P_0c094574: /* original e901, guest PC 0x0c094574 */
if(!s->budget--) { s->failed_pc=0x0c094574u; return 0; }
r[9]=0x00000001u;
goto P_0c094576;
P_0c094576: /* original fffb, guest PC 0x0c094576 */
if(!s->budget--) { s->failed_pc=0x0c094576u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c094578;
P_0c094578: /* original ffeb, guest PC 0x0c094578 */
if(!s->budget--) { s->failed_pc=0x0c094578u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c09457a;
P_0c09457a: /* original ffdb, guest PC 0x0c09457a */
if(!s->budget--) { s->failed_pc=0x0c09457au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c09457c;
P_0c09457c: /* original ffcb, guest PC 0x0c09457c */
if(!s->budget--) { s->failed_pc=0x0c09457cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c09457e;
P_0c09457e: /* original 4f22, guest PC 0x0c09457e */
if(!s->budget--) { s->failed_pc=0x0c09457eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c094580;
P_0c094580: /* original fd08, guest PC 0x0c094580 */
if(!s->budget--) { s->failed_pc=0x0c094580u; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c094582;
P_0c094582: /* original dc39, guest PC 0x0c094582 */
if(!s->budget--) { s->failed_pc=0x0c094582u; return 0; }
r[12]=read(ram,0x0c094668u,4);
goto P_0c094584;
P_0c094584: /* original dd39, guest PC 0x0c094584 */
if(!s->budget--) { s->failed_pc=0x0c094584u; return 0; }
r[13]=read(ram,0x0c09466cu,4);
goto P_0c094586;
P_0c094586: /* original fc8d, guest PC 0x0c094586 */
if(!s->budget--) { s->failed_pc=0x0c094586u; return 0; }
fr[12]=0;
goto P_0c094588;
P_0c094588: /* original c739, guest PC 0x0c094588 */
if(!s->budget--) { s->failed_pc=0x0c094588u; return 0; }
r[0]=code_base|0x00094670u;
goto P_0c09458a;
P_0c09458a: /* original ff08, guest PC 0x0c09458a */
if(!s->budget--) { s->failed_pc=0x0c09458au; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c09458c;
P_0c09458c: /* original c739, guest PC 0x0c09458c */
if(!s->budget--) { s->failed_pc=0x0c09458cu; return 0; }
r[0]=code_base|0x00094674u;
goto P_0c09458e;
P_0c09458e: /* original 4d0b, guest PC 0x0c09458e */
if(!s->budget--) { s->failed_pc=0x0c09458eu; return 0; }
target=r[13];
r[16]=code_base|0x0c094592u;
vf3_matrix_load(s,ram,14,r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c094592u) { target=s->pc; goto dispatch; }
goto P_0c094592;
P_0c094590: /* original fe08, guest PC 0x0c094590 */
if(!s->budget--) { s->failed_pc=0x0c094590u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c094592;
P_0c094592: /* original f0f2, guest PC 0x0c094592 */
if(!s->budget--) { s->failed_pc=0x0c094592u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c094594;
P_0c094594: /* original f0e1, guest PC 0x0c094594 */
if(!s->budget--) { s->failed_pc=0x0c094594u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[14],r[18],'-');
goto P_0c094596;
P_0c094596: /* original 4d0b, guest PC 0x0c094596 */
if(!s->budget--) { s->failed_pc=0x0c094596u; return 0; }
target=r[13];
r[16]=code_base|0x0c09459au;
vf3_matrix_store(s,ram,0,r[14]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09459au) { target=s->pc; goto dispatch; }
goto P_0c09459a;
P_0c094598: /* original fe0a, guest PC 0x0c094598 */
if(!s->budget--) { s->failed_pc=0x0c094598u; return 0; }
vf3_matrix_store(s,ram,0,r[14]);
goto P_0c09459a;
P_0c09459a: /* original f0f2, guest PC 0x0c09459a */
if(!s->budget--) { s->failed_pc=0x0c09459au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c09459c;
P_0c09459c: /* original e008, guest PC 0x0c09459c */
if(!s->budget--) { s->failed_pc=0x0c09459cu; return 0; }
r[0]=0x00000008u;
goto P_0c09459e;
P_0c09459e: /* original f0e1, guest PC 0x0c09459e */
if(!s->budget--) { s->failed_pc=0x0c09459eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[14],r[18],'-');
goto P_0c0945a0;
P_0c0945a0: /* original fe07, guest PC 0x0c0945a0 */
if(!s->budget--) { s->failed_pc=0x0c0945a0u; return 0; }
vf3_matrix_store(s,ram,0,r[14]+r[0]);
goto P_0c0945a2;
P_0c0945a2: /* original c735, guest PC 0x0c0945a2 */
if(!s->budget--) { s->failed_pc=0x0c0945a2u; return 0; }
r[0]=code_base|0x00094678u;
goto P_0c0945a4;
P_0c0945a4: /* original fe08, guest PC 0x0c0945a4 */
if(!s->budget--) { s->failed_pc=0x0c0945a4u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c0945a6;
P_0c0945a6: /* original 4d0b, guest PC 0x0c0945a6 */
if(!s->budget--) { s->failed_pc=0x0c0945a6u; return 0; }
target=r[13];
r[16]=code_base|0x0c0945aau;
vf3_matrix_move(s,15,13);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0945aau) { target=s->pc; goto dispatch; }
goto P_0c0945aa;
P_0c0945a8: /* original ffdc, guest PC 0x0c0945a8 */
if(!s->budget--) { s->failed_pc=0x0c0945a8u; return 0; }
vf3_matrix_move(s,15,13);
goto P_0c0945aa;
P_0c0945aa: /* original f30c, guest PC 0x0c0945aa */
if(!s->budget--) { s->failed_pc=0x0c0945aau; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0945ac;
P_0c0945ac: /* original e004, guest PC 0x0c0945ac */
if(!s->budget--) { s->failed_pc=0x0c0945acu; return 0; }
r[0]=0x00000004u;
goto P_0c0945ae;
P_0c0945ae: /* original f0ec, guest PC 0x0c0945ae */
if(!s->budget--) { s->failed_pc=0x0c0945aeu; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c0945b0;
P_0c0945b0: /* original ff3e, guest PC 0x0c0945b0 */
if(!s->budget--) { s->failed_pc=0x0c0945b0u; return 0; }
fr[15]=vf3_fpu_mac(fr[0],fr[3],fr[15],r[18]);
goto P_0c0945b2;
P_0c0945b2: /* original fef7, guest PC 0x0c0945b2 */
if(!s->budget--) { s->failed_pc=0x0c0945b2u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0945b4;
P_0c0945b4: /* original e00c, guest PC 0x0c0945b4 */
if(!s->budget--) { s->failed_pc=0x0c0945b4u; return 0; }
r[0]=0x0000000cu;
goto P_0c0945b6;
P_0c0945b6: /* original 4c0b, guest PC 0x0c0945b6 */
if(!s->budget--) { s->failed_pc=0x0c0945b6u; return 0; }
target=r[12];
r[16]=code_base|0x0c0945bau;
vf3_matrix_store(s,ram,12,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0945bau) { target=s->pc; goto dispatch; }
goto P_0c0945ba;
P_0c0945b8: /* original fec7, guest PC 0x0c0945b8 */
if(!s->budget--) { s->failed_pc=0x0c0945b8u; return 0; }
vf3_matrix_store(s,ram,12,r[14]+r[0]);
goto P_0c0945ba;
P_0c0945ba: /* original e116, guest PC 0x0c0945ba */
if(!s->budget--) { s->failed_pc=0x0c0945bau; return 0; }
r[1]=0x00000016u;
goto P_0c0945bc;
P_0c0945bc: /* original 31ec, guest PC 0x0c0945bc */
if(!s->budget--) { s->failed_pc=0x0c0945bcu; return 0; }
r[1]+=r[14];
goto P_0c0945be;
P_0c0945be: /* original c90f, guest PC 0x0c0945be */
if(!s->budget--) { s->failed_pc=0x0c0945beu; return 0; }
r[0]&=15u;
goto P_0c0945c0;
P_0c0945c0: /* original 4c0b, guest PC 0x0c0945c0 */
if(!s->budget--) { s->failed_pc=0x0c0945c0u; return 0; }
target=r[12];
r[16]=code_base|0x0c0945c4u;
write(ram,r[1],r[0],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0945c4u) { target=s->pc; goto dispatch; }
goto P_0c0945c4;
P_0c0945c2: /* original 2100, guest PC 0x0c0945c2 */
if(!s->budget--) { s->failed_pc=0x0c0945c2u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0945c4;
P_0c0945c4: /* original 4c0b, guest PC 0x0c0945c4 */
if(!s->budget--) { s->failed_pc=0x0c0945c4u; return 0; }
target=r[12];
r[16]=code_base|0x0c0945c8u;
write(ram,r[14]+16,r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0945c8u) { target=s->pc; goto dispatch; }
goto P_0c0945c8;
P_0c0945c6: /* original 81e8, guest PC 0x0c0945c6 */
if(!s->budget--) { s->failed_pc=0x0c0945c6u; return 0; }
write(ram,r[14]+16,r[0],2);
goto P_0c0945c8;
P_0c0945c8: /* original c9f0, guest PC 0x0c0945c8 */
if(!s->budget--) { s->failed_pc=0x0c0945c8u; return 0; }
r[0]&=240u;
goto P_0c0945ca;
P_0c0945ca: /* original 81ea, guest PC 0x0c0945ca */
if(!s->budget--) { s->failed_pc=0x0c0945cau; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c0945cc;
P_0c0945cc: /* original 60a3, guest PC 0x0c0945cc */
if(!s->budget--) { s->failed_pc=0x0c0945ccu; return 0; }
r[0]=r[10];
goto P_0c0945ce;
P_0c0945ce: /* original 81e9, guest PC 0x0c0945ce */
if(!s->budget--) { s->failed_pc=0x0c0945ceu; return 0; }
write(ram,r[14]+18,r[0],2);
goto P_0c0945d0;
P_0c0945d0: /* original e017, guest PC 0x0c0945d0 */
if(!s->budget--) { s->failed_pc=0x0c0945d0u; return 0; }
r[0]=0x00000017u;
goto P_0c0945d2;
P_0c0945d2: /* original 4b10, guest PC 0x0c0945d2 */
if(!s->budget--) { s->failed_pc=0x0c0945d2u; return 0; }
--r[11];
r[17]=(r[17]&~1u)|((r[11]==0)!=0);
goto P_0c0945d4;
P_0c0945d4: /* original 0e94, guest PC 0x0c0945d4 */
if(!s->budget--) { s->failed_pc=0x0c0945d4u; return 0; }
write(ram,r[14]+r[0],r[9],1);
goto P_0c0945d6;
P_0c0945d6: /* original 8fd7, guest PC 0x0c0945d6 */
if(!s->budget--) { s->failed_pc=0x0c0945d6u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000018u;
if(!cond) { goto P_0c094588; }
goto P_0c0945da;
P_0c0945d8: /* original 7e18, guest PC 0x0c0945d8 */
if(!s->budget--) { s->failed_pc=0x0c0945d8u; return 0; }
r[14]+=0x00000018u;
goto P_0c0945da;
P_0c0945da: /* original 4f26, guest PC 0x0c0945da */
if(!s->budget--) { s->failed_pc=0x0c0945dau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0945dc;
P_0c0945dc: /* original fcf9, guest PC 0x0c0945dc */
if(!s->budget--) { s->failed_pc=0x0c0945dcu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0945de;
P_0c0945de: /* original fdf9, guest PC 0x0c0945de */
if(!s->budget--) { s->failed_pc=0x0c0945deu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0945e0;
P_0c0945e0: /* original fef9, guest PC 0x0c0945e0 */
if(!s->budget--) { s->failed_pc=0x0c0945e0u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0945e2;
P_0c0945e2: /* original fff9, guest PC 0x0c0945e2 */
if(!s->budget--) { s->failed_pc=0x0c0945e2u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0945e4;
P_0c0945e4: /* original 69f6, guest PC 0x0c0945e4 */
if(!s->budget--) { s->failed_pc=0x0c0945e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0945e6;
P_0c0945e6: /* original 6af6, guest PC 0x0c0945e6 */
if(!s->budget--) { s->failed_pc=0x0c0945e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0945e8;
P_0c0945e8: /* original 6bf6, guest PC 0x0c0945e8 */
if(!s->budget--) { s->failed_pc=0x0c0945e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0945ea;
P_0c0945ea: /* original 6cf6, guest PC 0x0c0945ea */
if(!s->budget--) { s->failed_pc=0x0c0945eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0945ec;
P_0c0945ec: /* original 6df6, guest PC 0x0c0945ec */
if(!s->budget--) { s->failed_pc=0x0c0945ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0945ee;
P_0c0945ee: /* original 000b, guest PC 0x0c0945ee */
if(!s->budget--) { s->failed_pc=0x0c0945eeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0945f0: /* original 6ef6, guest PC 0x0c0945f0 */
if(!s->budget--) { s->failed_pc=0x0c0945f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0945f2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0945f2u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
