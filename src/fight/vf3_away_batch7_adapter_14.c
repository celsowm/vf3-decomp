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
int vf3_away_batch7_adapter_14(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05d424u: goto P_0c05d424;
case 0x0c05d426u: goto P_0c05d426;
case 0x0c05d428u: goto P_0c05d428;
case 0x0c05d42au: goto P_0c05d42a;
case 0x0c05d42cu: goto P_0c05d42c;
case 0x0c05d42eu: goto P_0c05d42e;
case 0x0c05d430u: goto P_0c05d430;
case 0x0c05d432u: goto P_0c05d432;
case 0x0c05d434u: goto P_0c05d434;
case 0x0c05d436u: goto P_0c05d436;
case 0x0c05d438u: goto P_0c05d438;
case 0x0c05d43au: goto P_0c05d43a;
case 0x0c05d43cu: goto P_0c05d43c;
case 0x0c05d43eu: goto P_0c05d43e;
case 0x0c05d440u: goto P_0c05d440;
case 0x0c05d442u: goto P_0c05d442;
case 0x0c05d444u: goto P_0c05d444;
case 0x0c05d446u: goto P_0c05d446;
case 0x0c05d448u: goto P_0c05d448;
case 0x0c05d44au: goto P_0c05d44a;
case 0x0c05d44cu: goto P_0c05d44c;
case 0x0c05d44eu: goto P_0c05d44e;
case 0x0c05d450u: goto P_0c05d450;
case 0x0c05d452u: goto P_0c05d452;
case 0x0c05d454u: goto P_0c05d454;
case 0x0c05d456u: goto P_0c05d456;
case 0x0c05d458u: goto P_0c05d458;
case 0x0c05d45au: goto P_0c05d45a;
case 0x0c05d45cu: goto P_0c05d45c;
case 0x0c05d45eu: goto P_0c05d45e;
case 0x0c05d460u: goto P_0c05d460;
case 0x0c05d462u: goto P_0c05d462;
case 0x0c05d464u: goto P_0c05d464;
case 0x0c05d466u: goto P_0c05d466;
case 0x0c05d468u: goto P_0c05d468;
case 0x0c05d46au: goto P_0c05d46a;
case 0x0c05d46cu: goto P_0c05d46c;
case 0x0c05d46eu: goto P_0c05d46e;
case 0x0c05d470u: goto P_0c05d470;
case 0x0c05d472u: goto P_0c05d472;
case 0x0c05d474u: goto P_0c05d474;
case 0x0c05d476u: goto P_0c05d476;
case 0x0c05d478u: goto P_0c05d478;
case 0x0c05d47au: goto P_0c05d47a;
case 0x0c05d47cu: goto P_0c05d47c;
case 0x0c05d47eu: goto P_0c05d47e;
case 0x0c05d480u: goto P_0c05d480;
case 0x0c05d482u: goto P_0c05d482;
case 0x0c05d484u: goto P_0c05d484;
case 0x0c05d486u: goto P_0c05d486;
case 0x0c05d488u: goto P_0c05d488;
case 0x0c05d48au: goto P_0c05d48a;
case 0x0c05d48cu: goto P_0c05d48c;
case 0x0c05d48eu: goto P_0c05d48e;
case 0x0c05d490u: goto P_0c05d490;
case 0x0c05d492u: goto P_0c05d492;
case 0x0c05d494u: goto P_0c05d494;
case 0x0c05d496u: goto P_0c05d496;
case 0x0c05d498u: goto P_0c05d498;
case 0x0c05d49au: goto P_0c05d49a;
case 0x0c05d49cu: goto P_0c05d49c;
case 0x0c05d49eu: goto P_0c05d49e;
case 0x0c05d4a0u: goto P_0c05d4a0;
case 0x0c05d4a2u: goto P_0c05d4a2;
case 0x0c05d4a4u: goto P_0c05d4a4;
case 0x0c05d4a6u: goto P_0c05d4a6;
case 0x0c05d4a8u: goto P_0c05d4a8;
case 0x0c05d4aau: goto P_0c05d4aa;
case 0x0c05d4acu: goto P_0c05d4ac;
case 0x0c05d4aeu: goto P_0c05d4ae;
case 0x0c05d4b0u: goto P_0c05d4b0;
case 0x0c05d4b2u: goto P_0c05d4b2;
case 0x0c05d4b4u: goto P_0c05d4b4;
case 0x0c05d4b6u: goto P_0c05d4b6;
case 0x0c05d4b8u: goto P_0c05d4b8;
case 0x0c05d4bau: goto P_0c05d4ba;
case 0x0c05d4bcu: goto P_0c05d4bc;
case 0x0c05d4beu: goto P_0c05d4be;
case 0x0c05d4c0u: goto P_0c05d4c0;
case 0x0c05d4c2u: goto P_0c05d4c2;
case 0x0c05d4c4u: goto P_0c05d4c4;
case 0x0c05d4c6u: goto P_0c05d4c6;
case 0x0c05d4c8u: goto P_0c05d4c8;
case 0x0c05d4cau: goto P_0c05d4ca;
case 0x0c05d4ccu: goto P_0c05d4cc;
case 0x0c05d4ceu: goto P_0c05d4ce;
case 0x0c05d4d0u: goto P_0c05d4d0;
case 0x0c05d4d2u: goto P_0c05d4d2;
case 0x0c05d4d4u: goto P_0c05d4d4;
case 0x0c05d4d6u: goto P_0c05d4d6;
case 0x0c05d4d8u: goto P_0c05d4d8;
case 0x0c05d4dau: goto P_0c05d4da;
case 0x0c05d4dcu: goto P_0c05d4dc;
case 0x0c05d4deu: goto P_0c05d4de;
case 0x0c05d4e0u: goto P_0c05d4e0;
case 0x0c05d4e2u: goto P_0c05d4e2;
case 0x0c05d4e4u: goto P_0c05d4e4;
case 0x0c05d4e6u: goto P_0c05d4e6;
case 0x0c05d4e8u: goto P_0c05d4e8;
case 0x0c05d4eau: goto P_0c05d4ea;
case 0x0c05d4ecu: goto P_0c05d4ec;
case 0x0c05d4eeu: goto P_0c05d4ee;
case 0x0c05d4f0u: goto P_0c05d4f0;
case 0x0c05d4f2u: goto P_0c05d4f2;
case 0x0c05d4f4u: goto P_0c05d4f4;
case 0x0c05d4f6u: goto P_0c05d4f6;
case 0x0c05d4f8u: goto P_0c05d4f8;
case 0x0c05d4fau: goto P_0c05d4fa;
case 0x0c05d4fcu: goto P_0c05d4fc;
case 0x0c05d4feu: goto P_0c05d4fe;
case 0x0c05d500u: goto P_0c05d500;
case 0x0c05d502u: goto P_0c05d502;
case 0x0c05d504u: goto P_0c05d504;
case 0x0c05d506u: goto P_0c05d506;
case 0x0c05d508u: goto P_0c05d508;
case 0x0c05d50au: goto P_0c05d50a;
case 0x0c05d50cu: goto P_0c05d50c;
case 0x0c05d50eu: goto P_0c05d50e;
case 0x0c05d510u: goto P_0c05d510;
case 0x0c05d512u: goto P_0c05d512;
case 0x0c05d514u: goto P_0c05d514;
case 0x0c05d516u: goto P_0c05d516;
case 0x0c05d518u: goto P_0c05d518;
case 0x0c05d51au: goto P_0c05d51a;
case 0x0c05d51cu: goto P_0c05d51c;
case 0x0c05d51eu: goto P_0c05d51e;
case 0x0c05d520u: goto P_0c05d520;
case 0x0c05d522u: goto P_0c05d522;
case 0x0c05d524u: goto P_0c05d524;
case 0x0c05d526u: goto P_0c05d526;
case 0x0c05d528u: goto P_0c05d528;
case 0x0c05d52au: goto P_0c05d52a;
case 0x0c05d52cu: goto P_0c05d52c;
case 0x0c05d52eu: goto P_0c05d52e;
case 0x0c05d530u: goto P_0c05d530;
case 0x0c05d532u: goto P_0c05d532;
case 0x0c05d534u: goto P_0c05d534;
case 0x0c05d536u: goto P_0c05d536;
case 0x0c05d538u: goto P_0c05d538;
case 0x0c05d53au: goto P_0c05d53a;
case 0x0c05d53cu: goto P_0c05d53c;
case 0x0c05d53eu: goto P_0c05d53e;
case 0x0c05d540u: goto P_0c05d540;
case 0x0c05d542u: goto P_0c05d542;
case 0x0c05d544u: goto P_0c05d544;
case 0x0c05d546u: goto P_0c05d546;
case 0x0c05d548u: goto P_0c05d548;
case 0x0c05d54au: goto P_0c05d54a;
case 0x0c05d54cu: goto P_0c05d54c;
case 0x0c05d54eu: goto P_0c05d54e;
case 0x0c05d550u: goto P_0c05d550;
case 0x0c05d552u: goto P_0c05d552;
case 0x0c05d554u: goto P_0c05d554;
case 0x0c05d556u: goto P_0c05d556;
case 0x0c05d558u: goto P_0c05d558;
case 0x0c05d55au: goto P_0c05d55a;
case 0x0c05d55cu: goto P_0c05d55c;
case 0x0c05d55eu: goto P_0c05d55e;
case 0x0c05d560u: goto P_0c05d560;
case 0x0c05d562u: goto P_0c05d562;
case 0x0c05d564u: goto P_0c05d564;
case 0x0c05d566u: goto P_0c05d566;
case 0x0c05d568u: goto P_0c05d568;
case 0x0c05d56au: goto P_0c05d56a;
case 0x0c05d56cu: goto P_0c05d56c;
case 0x0c05d56eu: goto P_0c05d56e;
case 0x0c05d570u: goto P_0c05d570;
case 0x0c05d572u: goto P_0c05d572;
case 0x0c05d574u: goto P_0c05d574;
case 0x0c05d576u: goto P_0c05d576;
case 0x0c05d578u: goto P_0c05d578;
case 0x0c05d57au: goto P_0c05d57a;
case 0x0c05d57cu: goto P_0c05d57c;
case 0x0c05d57eu: goto P_0c05d57e;
case 0x0c05d580u: goto P_0c05d580;
case 0x0c05d582u: goto P_0c05d582;
case 0x0c05d584u: goto P_0c05d584;
case 0x0c05d586u: goto P_0c05d586;
case 0x0c05d588u: goto P_0c05d588;
case 0x0c05d58au: goto P_0c05d58a;
case 0x0c05d58cu: goto P_0c05d58c;
case 0x0c05d58eu: goto P_0c05d58e;
case 0x0c05d590u: goto P_0c05d590;
case 0x0c05d592u: goto P_0c05d592;
case 0x0c05d594u: goto P_0c05d594;
case 0x0c05d596u: goto P_0c05d596;
case 0x0c05d598u: goto P_0c05d598;
case 0x0c05d59au: goto P_0c05d59a;
case 0x0c05d59cu: goto P_0c05d59c;
case 0x0c05d59eu: goto P_0c05d59e;
case 0x0c05d5a0u: goto P_0c05d5a0;
case 0x0c05d5a2u: goto P_0c05d5a2;
case 0x0c05d5a4u: goto P_0c05d5a4;
case 0x0c05d5a6u: goto P_0c05d5a6;
case 0x0c05d5a8u: goto P_0c05d5a8;
case 0x0c05d5aau: goto P_0c05d5aa;
case 0x0c05d5acu: goto P_0c05d5ac;
case 0x0c05d5aeu: goto P_0c05d5ae;
case 0x0c05d5b0u: goto P_0c05d5b0;
case 0x0c05d5b2u: goto P_0c05d5b2;
case 0x0c05d5b4u: goto P_0c05d5b4;
case 0x0c05d5b6u: goto P_0c05d5b6;
case 0x0c05d5b8u: goto P_0c05d5b8;
case 0x0c05d5bau: goto P_0c05d5ba;
case 0x0c05d5bcu: goto P_0c05d5bc;
case 0x0c05d5beu: goto P_0c05d5be;
case 0x0c05d5c0u: goto P_0c05d5c0;
case 0x0c05d5c2u: goto P_0c05d5c2;
case 0x0c05d5c4u: goto P_0c05d5c4;
case 0x0c05d5c6u: goto P_0c05d5c6;
case 0x0c05d5c8u: goto P_0c05d5c8;
case 0x0c05d5cau: goto P_0c05d5ca;
case 0x0c05d5ccu: goto P_0c05d5cc;
case 0x0c05d5ceu: goto P_0c05d5ce;
case 0x0c05d5d0u: goto P_0c05d5d0;
case 0x0c05d5d2u: goto P_0c05d5d2;
case 0x0c05d5d4u: goto P_0c05d5d4;
case 0x0c05d5d6u: goto P_0c05d5d6;
case 0x0c05d5d8u: goto P_0c05d5d8;
case 0x0c05d5dau: goto P_0c05d5da;
case 0x0c05d5dcu: goto P_0c05d5dc;
case 0x0c05d5deu: goto P_0c05d5de;
case 0x0c05d5e0u: goto P_0c05d5e0;
case 0x0c05d5e2u: goto P_0c05d5e2;
case 0x0c05d5e4u: goto P_0c05d5e4;
case 0x0c05d5e6u: goto P_0c05d5e6;
case 0x0c05d5e8u: goto P_0c05d5e8;
case 0x0c05d5eau: goto P_0c05d5ea;
case 0x0c05d5ecu: goto P_0c05d5ec;
case 0x0c05d5eeu: goto P_0c05d5ee;
case 0x0c05d5f0u: goto P_0c05d5f0;
case 0x0c05d5f2u: goto P_0c05d5f2;
case 0x0c05d5f4u: goto P_0c05d5f4;
case 0x0c05d5f6u: goto P_0c05d5f6;
case 0x0c05d5f8u: goto P_0c05d5f8;
case 0x0c05d5fau: goto P_0c05d5fa;
case 0x0c05d5fcu: goto P_0c05d5fc;
case 0x0c05d5feu: goto P_0c05d5fe;
case 0x0c05d600u: goto P_0c05d600;
case 0x0c05d602u: goto P_0c05d602;
case 0x0c05d604u: goto P_0c05d604;
case 0x0c05d606u: goto P_0c05d606;
case 0x0c05d608u: goto P_0c05d608;
case 0x0c05d60au: goto P_0c05d60a;
case 0x0c05d60cu: goto P_0c05d60c;
case 0x0c05d60eu: goto P_0c05d60e;
case 0x0c05d610u: goto P_0c05d610;
case 0x0c05d612u: goto P_0c05d612;
case 0x0c05d614u: goto P_0c05d614;
case 0x0c05d616u: goto P_0c05d616;
case 0x0c05d618u: goto P_0c05d618;
case 0x0c05d61au: goto P_0c05d61a;
case 0x0c05d61cu: goto P_0c05d61c;
case 0x0c05d61eu: goto P_0c05d61e;
case 0x0c05d620u: goto P_0c05d620;
case 0x0c05d622u: goto P_0c05d622;
case 0x0c05d624u: goto P_0c05d624;
case 0x0c05d626u: goto P_0c05d626;
case 0x0c05d628u: goto P_0c05d628;
case 0x0c05d62au: goto P_0c05d62a;
case 0x0c05d62cu: goto P_0c05d62c;
case 0x0c05d62eu: goto P_0c05d62e;
case 0x0c05d630u: goto P_0c05d630;
case 0x0c05d632u: goto P_0c05d632;
case 0x0c05d634u: goto P_0c05d634;
case 0x0c05d636u: goto P_0c05d636;
case 0x0c05d638u: goto P_0c05d638;
case 0x0c05d63au: goto P_0c05d63a;
case 0x0c05d63cu: goto P_0c05d63c;
case 0x0c05d63eu: goto P_0c05d63e;
case 0x0c05d640u: goto P_0c05d640;
case 0x0c05d642u: goto P_0c05d642;
case 0x0c05d644u: goto P_0c05d644;
case 0x0c05d646u: goto P_0c05d646;
case 0x0c05d648u: goto P_0c05d648;
case 0x0c05d64au: goto P_0c05d64a;
case 0x0c05d64cu: goto P_0c05d64c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05d424: /* original 2fe6, guest PC 0x0c05d424 */
if(!s->budget--) { s->failed_pc=0x0c05d424u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d426;
P_0c05d426: /* original 2fd6, guest PC 0x0c05d426 */
if(!s->budget--) { s->failed_pc=0x0c05d426u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d428;
P_0c05d428: /* original 2fc6, guest PC 0x0c05d428 */
if(!s->budget--) { s->failed_pc=0x0c05d428u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d42a;
P_0c05d42a: /* original 6d43, guest PC 0x0c05d42a */
if(!s->budget--) { s->failed_pc=0x0c05d42au; return 0; }
r[13]=r[4];
goto P_0c05d42c;
P_0c05d42c: /* original d288, guest PC 0x0c05d42c */
if(!s->budget--) { s->failed_pc=0x0c05d42cu; return 0; }
r[2]=read(ram,0x0c05d650u,4);
goto P_0c05d42e;
P_0c05d42e: /* original 2fb6, guest PC 0x0c05d42e */
if(!s->budget--) { s->failed_pc=0x0c05d42eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d430;
P_0c05d430: /* original 2fa6, guest PC 0x0c05d430 */
if(!s->budget--) { s->failed_pc=0x0c05d430u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d432;
P_0c05d432: /* original 2f96, guest PC 0x0c05d432 */
if(!s->budget--) { s->failed_pc=0x0c05d432u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d434;
P_0c05d434: /* original 2f86, guest PC 0x0c05d434 */
if(!s->budget--) { s->failed_pc=0x0c05d434u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d436;
P_0c05d436: /* original 4f22, guest PC 0x0c05d436 */
if(!s->budget--) { s->failed_pc=0x0c05d436u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05d438;
P_0c05d438: /* original d386, guest PC 0x0c05d438 */
if(!s->budget--) { s->failed_pc=0x0c05d438u; return 0; }
r[3]=read(ram,0x0c05d654u,4);
goto P_0c05d43a;
P_0c05d43a: /* original 7fe0, guest PC 0x0c05d43a */
if(!s->budget--) { s->failed_pc=0x0c05d43au; return 0; }
r[15]+=0xffffffe0u;
goto P_0c05d43c;
P_0c05d43c: /* original 6ef3, guest PC 0x0c05d43c */
if(!s->budget--) { s->failed_pc=0x0c05d43cu; return 0; }
r[14]=r[15];
goto P_0c05d43e;
P_0c05d43e: /* original 61f3, guest PC 0x0c05d43e */
if(!s->budget--) { s->failed_pc=0x0c05d43eu; return 0; }
r[1]=r[15];
goto P_0c05d440;
P_0c05d440: /* original 430b, guest PC 0x0c05d440 */
if(!s->budget--) { s->failed_pc=0x0c05d440u; return 0; }
target=r[3];
r[16]=code_base|0x0c05d444u;
r[0]=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d444u) { target=s->pc; goto dispatch; }
goto P_0c05d444;
P_0c05d442: /* original e020, guest PC 0x0c05d442 */
if(!s->budget--) { s->failed_pc=0x0c05d442u; return 0; }
r[0]=0x00000020u;
goto P_0c05d444;
P_0c05d444: /* original d884, guest PC 0x0c05d444 */
if(!s->budget--) { s->failed_pc=0x0c05d444u; return 0; }
r[8]=read(ram,0x0c05d658u,4);
goto P_0c05d446;
P_0c05d446: /* original db85, guest PC 0x0c05d446 */
if(!s->budget--) { s->failed_pc=0x0c05d446u; return 0; }
r[11]=read(ram,0x0c05d65cu,4);
goto P_0c05d448;
P_0c05d448: /* original dc85, guest PC 0x0c05d448 */
if(!s->budget--) { s->failed_pc=0x0c05d448u; return 0; }
r[12]=read(ram,0x0c05d660u,4);
goto P_0c05d44a;
P_0c05d44a: /* original d186, guest PC 0x0c05d44a */
if(!s->budget--) { s->failed_pc=0x0c05d44au; return 0; }
r[1]=read(ram,0x0c05d664u,4);
goto P_0c05d44c;
P_0c05d44c: /* original 6012, guest PC 0x0c05d44c */
if(!s->budget--) { s->failed_pc=0x0c05d44cu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05d44e;
P_0c05d44e: /* original c801, guest PC 0x0c05d44e */
if(!s->budget--) { s->failed_pc=0x0c05d44eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c05d450;
P_0c05d450: /* original 8d1b, guest PC 0x0c05d450 */
if(!s->budget--) { s->failed_pc=0x0c05d450u; return 0; }
cond=r[17]&1u;
r[9]=0x00000008u;
if(cond) { goto P_0c05d48a; }
goto P_0c05d454;
P_0c05d452: /* original e908, guest PC 0x0c05d452 */
if(!s->budget--) { s->failed_pc=0x0c05d452u; return 0; }
r[9]=0x00000008u;
goto P_0c05d454;
P_0c05d454: /* original d084, guest PC 0x0c05d454 */
if(!s->budget--) { s->failed_pc=0x0c05d454u; return 0; }
r[0]=read(ram,0x0c05d668u,4);
goto P_0c05d456;
P_0c05d456: /* original 6302, guest PC 0x0c05d456 */
if(!s->budget--) { s->failed_pc=0x0c05d456u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c05d458;
P_0c05d458: /* original 2338, guest PC 0x0c05d458 */
if(!s->budget--) { s->failed_pc=0x0c05d458u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c05d45a;
P_0c05d45a: /* original 8903, guest PC 0x0c05d45a */
if(!s->budget--) { s->failed_pc=0x0c05d45au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d464; }
goto P_0c05d45c;
P_0c05d45c: /* original d383, guest PC 0x0c05d45c */
if(!s->budget--) { s->failed_pc=0x0c05d45cu; return 0; }
r[3]=read(ram,0x0c05d66cu,4);
goto P_0c05d45e;
P_0c05d45e: /* original 6032, guest PC 0x0c05d45e */
if(!s->budget--) { s->failed_pc=0x0c05d45eu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05d460;
P_0c05d460: /* original 8820, guest PC 0x0c05d460 */
if(!s->budget--) { s->failed_pc=0x0c05d460u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c05d462;
P_0c05d462: /* original 8912, guest PC 0x0c05d462 */
if(!s->budget--) { s->failed_pc=0x0c05d462u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d48a; }
goto P_0c05d464;
P_0c05d464: /* original ea00, guest PC 0x0c05d464 */
if(!s->budget--) { s->failed_pc=0x0c05d464u; return 0; }
r[10]=0x00000000u;
goto P_0c05d466;
P_0c05d466: /* original 63a3, guest PC 0x0c05d466 */
if(!s->budget--) { s->failed_pc=0x0c05d466u; return 0; }
r[3]=r[10];
goto P_0c05d468;
P_0c05d468: /* original 33d2, guest PC 0x0c05d468 */
if(!s->budget--) { s->failed_pc=0x0c05d468u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c05d46a;
P_0c05d46a: /* original 890d, guest PC 0x0c05d46a */
if(!s->budget--) { s->failed_pc=0x0c05d46au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d488; }
goto P_0c05d46c;
P_0c05d46c: /* original e620, guest PC 0x0c05d46c */
if(!s->budget--) { s->failed_pc=0x0c05d46cu; return 0; }
r[6]=0x00000020u;
goto P_0c05d46e;
P_0c05d46e: /* original 65e3, guest PC 0x0c05d46e */
if(!s->budget--) { s->failed_pc=0x0c05d46eu; return 0; }
r[5]=r[14];
goto P_0c05d470;
P_0c05d470: /* original 64a3, guest PC 0x0c05d470 */
if(!s->budget--) { s->failed_pc=0x0c05d470u; return 0; }
r[4]=r[10];
goto P_0c05d472;
P_0c05d472: /* original 63a3, guest PC 0x0c05d472 */
if(!s->budget--) { s->failed_pc=0x0c05d472u; return 0; }
r[3]=r[10];
goto P_0c05d474;
P_0c05d474: /* original 4408, guest PC 0x0c05d474 */
if(!s->budget--) { s->failed_pc=0x0c05d474u; return 0; }
r[4]<<=2;
goto P_0c05d476;
P_0c05d476: /* original 343c, guest PC 0x0c05d476 */
if(!s->budget--) { s->failed_pc=0x0c05d476u; return 0; }
r[4]+=r[3];
goto P_0c05d478;
P_0c05d478: /* original 4408, guest PC 0x0c05d478 */
if(!s->budget--) { s->failed_pc=0x0c05d478u; return 0; }
r[4]<<=2;
goto P_0c05d47a;
P_0c05d47a: /* original 644e, guest PC 0x0c05d47a */
if(!s->budget--) { s->failed_pc=0x0c05d47au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c05d47c;
P_0c05d47c: /* original 34bc, guest PC 0x0c05d47c */
if(!s->budget--) { s->failed_pc=0x0c05d47cu; return 0; }
r[4]+=r[11];
goto P_0c05d47e;
P_0c05d47e: /* original 4c0b, guest PC 0x0c05d47e */
if(!s->budget--) { s->failed_pc=0x0c05d47eu; return 0; }
target=r[12];
r[16]=code_base|0x0c05d482u;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d482u) { target=s->pc; goto dispatch; }
goto P_0c05d482;
P_0c05d480: /* original 6442, guest PC 0x0c05d480 */
if(!s->budget--) { s->failed_pc=0x0c05d480u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05d482;
P_0c05d482: /* original 7a01, guest PC 0x0c05d482 */
if(!s->budget--) { s->failed_pc=0x0c05d482u; return 0; }
r[10]+=0x00000001u;
goto P_0c05d484;
P_0c05d484: /* original 3ad2, guest PC 0x0c05d484 */
if(!s->budget--) { s->failed_pc=0x0c05d484u; return 0; }
r[17]=(r[17]&~1u)|((r[10]>=r[13])!=0);
goto P_0c05d486;
P_0c05d486: /* original 8bf1, guest PC 0x0c05d486 */
if(!s->budget--) { s->failed_pc=0x0c05d486u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d46c; }
goto P_0c05d488;
P_0c05d488: /* original 2892, guest PC 0x0c05d488 */
if(!s->budget--) { s->failed_pc=0x0c05d488u; return 0; }
write(ram,r[8],r[9],4);
goto P_0c05d48a;
P_0c05d48a: /* original d376, guest PC 0x0c05d48a */
if(!s->budget--) { s->failed_pc=0x0c05d48au; return 0; }
r[3]=read(ram,0x0c05d664u,4);
goto P_0c05d48c;
P_0c05d48c: /* original 6032, guest PC 0x0c05d48c */
if(!s->budget--) { s->failed_pc=0x0c05d48cu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05d48e;
P_0c05d48e: /* original c802, guest PC 0x0c05d48e */
if(!s->budget--) { s->failed_pc=0x0c05d48eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c05d490;
P_0c05d490: /* original 891c, guest PC 0x0c05d490 */
if(!s->budget--) { s->failed_pc=0x0c05d490u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d4cc; }
goto P_0c05d492;
P_0c05d492: /* original d177, guest PC 0x0c05d492 */
if(!s->budget--) { s->failed_pc=0x0c05d492u; return 0; }
r[1]=read(ram,0x0c05d670u,4);
goto P_0c05d494;
P_0c05d494: /* original d074, guest PC 0x0c05d494 */
if(!s->budget--) { s->failed_pc=0x0c05d494u; return 0; }
r[0]=read(ram,0x0c05d668u,4);
goto P_0c05d496;
P_0c05d496: /* original 2e12, guest PC 0x0c05d496 */
if(!s->budget--) { s->failed_pc=0x0c05d496u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c05d498;
P_0c05d498: /* original 6202, guest PC 0x0c05d498 */
if(!s->budget--) { s->failed_pc=0x0c05d498u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c05d49a;
P_0c05d49a: /* original 2228, guest PC 0x0c05d49a */
if(!s->budget--) { s->failed_pc=0x0c05d49au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c05d49c;
P_0c05d49c: /* original 8903, guest PC 0x0c05d49c */
if(!s->budget--) { s->failed_pc=0x0c05d49cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d4a6; }
goto P_0c05d49e;
P_0c05d49e: /* original d273, guest PC 0x0c05d49e */
if(!s->budget--) { s->failed_pc=0x0c05d49eu; return 0; }
r[2]=read(ram,0x0c05d66cu,4);
goto P_0c05d4a0;
P_0c05d4a0: /* original 6022, guest PC 0x0c05d4a0 */
if(!s->budget--) { s->failed_pc=0x0c05d4a0u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05d4a2;
P_0c05d4a2: /* original 8821, guest PC 0x0c05d4a2 */
if(!s->budget--) { s->failed_pc=0x0c05d4a2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000021u)!=0);
goto P_0c05d4a4;
P_0c05d4a4: /* original 8912, guest PC 0x0c05d4a4 */
if(!s->budget--) { s->failed_pc=0x0c05d4a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d4cc; }
goto P_0c05d4a6;
P_0c05d4a6: /* original ea00, guest PC 0x0c05d4a6 */
if(!s->budget--) { s->failed_pc=0x0c05d4a6u; return 0; }
r[10]=0x00000000u;
goto P_0c05d4a8;
P_0c05d4a8: /* original 63a3, guest PC 0x0c05d4a8 */
if(!s->budget--) { s->failed_pc=0x0c05d4a8u; return 0; }
r[3]=r[10];
goto P_0c05d4aa;
P_0c05d4aa: /* original 33d2, guest PC 0x0c05d4aa */
if(!s->budget--) { s->failed_pc=0x0c05d4aau; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c05d4ac;
P_0c05d4ac: /* original 890d, guest PC 0x0c05d4ac */
if(!s->budget--) { s->failed_pc=0x0c05d4acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d4ca; }
goto P_0c05d4ae;
P_0c05d4ae: /* original e620, guest PC 0x0c05d4ae */
if(!s->budget--) { s->failed_pc=0x0c05d4aeu; return 0; }
r[6]=0x00000020u;
goto P_0c05d4b0;
P_0c05d4b0: /* original 65e3, guest PC 0x0c05d4b0 */
if(!s->budget--) { s->failed_pc=0x0c05d4b0u; return 0; }
r[5]=r[14];
goto P_0c05d4b2;
P_0c05d4b2: /* original 64a3, guest PC 0x0c05d4b2 */
if(!s->budget--) { s->failed_pc=0x0c05d4b2u; return 0; }
r[4]=r[10];
goto P_0c05d4b4;
P_0c05d4b4: /* original 63a3, guest PC 0x0c05d4b4 */
if(!s->budget--) { s->failed_pc=0x0c05d4b4u; return 0; }
r[3]=r[10];
goto P_0c05d4b6;
P_0c05d4b6: /* original 4408, guest PC 0x0c05d4b6 */
if(!s->budget--) { s->failed_pc=0x0c05d4b6u; return 0; }
r[4]<<=2;
goto P_0c05d4b8;
P_0c05d4b8: /* original 343c, guest PC 0x0c05d4b8 */
if(!s->budget--) { s->failed_pc=0x0c05d4b8u; return 0; }
r[4]+=r[3];
goto P_0c05d4ba;
P_0c05d4ba: /* original 4408, guest PC 0x0c05d4ba */
if(!s->budget--) { s->failed_pc=0x0c05d4bau; return 0; }
r[4]<<=2;
goto P_0c05d4bc;
P_0c05d4bc: /* original 644e, guest PC 0x0c05d4bc */
if(!s->budget--) { s->failed_pc=0x0c05d4bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c05d4be;
P_0c05d4be: /* original 34bc, guest PC 0x0c05d4be */
if(!s->budget--) { s->failed_pc=0x0c05d4beu; return 0; }
r[4]+=r[11];
goto P_0c05d4c0;
P_0c05d4c0: /* original 4c0b, guest PC 0x0c05d4c0 */
if(!s->budget--) { s->failed_pc=0x0c05d4c0u; return 0; }
target=r[12];
r[16]=code_base|0x0c05d4c4u;
r[4]=read(ram,r[4]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d4c4u) { target=s->pc; goto dispatch; }
goto P_0c05d4c4;
P_0c05d4c2: /* original 5441, guest PC 0x0c05d4c2 */
if(!s->budget--) { s->failed_pc=0x0c05d4c2u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c05d4c4;
P_0c05d4c4: /* original 7a01, guest PC 0x0c05d4c4 */
if(!s->budget--) { s->failed_pc=0x0c05d4c4u; return 0; }
r[10]+=0x00000001u;
goto P_0c05d4c6;
P_0c05d4c6: /* original 3ad2, guest PC 0x0c05d4c6 */
if(!s->budget--) { s->failed_pc=0x0c05d4c6u; return 0; }
r[17]=(r[17]&~1u)|((r[10]>=r[13])!=0);
goto P_0c05d4c8;
P_0c05d4c8: /* original 8bf1, guest PC 0x0c05d4c8 */
if(!s->budget--) { s->failed_pc=0x0c05d4c8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d4ae; }
goto P_0c05d4ca;
P_0c05d4ca: /* original 1891, guest PC 0x0c05d4ca */
if(!s->budget--) { s->failed_pc=0x0c05d4cau; return 0; }
write(ram,r[8]+4,r[9],4);
goto P_0c05d4cc;
P_0c05d4cc: /* original d365, guest PC 0x0c05d4cc */
if(!s->budget--) { s->failed_pc=0x0c05d4ccu; return 0; }
r[3]=read(ram,0x0c05d664u,4);
goto P_0c05d4ce;
P_0c05d4ce: /* original 6032, guest PC 0x0c05d4ce */
if(!s->budget--) { s->failed_pc=0x0c05d4ceu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05d4d0;
P_0c05d4d0: /* original c804, guest PC 0x0c05d4d0 */
if(!s->budget--) { s->failed_pc=0x0c05d4d0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c05d4d2;
P_0c05d4d2: /* original 891d, guest PC 0x0c05d4d2 */
if(!s->budget--) { s->failed_pc=0x0c05d4d2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d510; }
goto P_0c05d4d4;
P_0c05d4d4: /* original d167, guest PC 0x0c05d4d4 */
if(!s->budget--) { s->failed_pc=0x0c05d4d4u; return 0; }
r[1]=read(ram,0x0c05d674u,4);
goto P_0c05d4d6;
P_0c05d4d6: /* original 2e12, guest PC 0x0c05d4d6 */
if(!s->budget--) { s->failed_pc=0x0c05d4d6u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c05d4d8;
P_0c05d4d8: /* original d063, guest PC 0x0c05d4d8 */
if(!s->budget--) { s->failed_pc=0x0c05d4d8u; return 0; }
r[0]=read(ram,0x0c05d668u,4);
goto P_0c05d4da;
P_0c05d4da: /* original 6202, guest PC 0x0c05d4da */
if(!s->budget--) { s->failed_pc=0x0c05d4dau; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c05d4dc;
P_0c05d4dc: /* original 2228, guest PC 0x0c05d4dc */
if(!s->budget--) { s->failed_pc=0x0c05d4dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c05d4de;
P_0c05d4de: /* original 8903, guest PC 0x0c05d4de */
if(!s->budget--) { s->failed_pc=0x0c05d4deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d4e8; }
goto P_0c05d4e0;
P_0c05d4e0: /* original d262, guest PC 0x0c05d4e0 */
if(!s->budget--) { s->failed_pc=0x0c05d4e0u; return 0; }
r[2]=read(ram,0x0c05d66cu,4);
goto P_0c05d4e2;
P_0c05d4e2: /* original 6022, guest PC 0x0c05d4e2 */
if(!s->budget--) { s->failed_pc=0x0c05d4e2u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05d4e4;
P_0c05d4e4: /* original 8822, guest PC 0x0c05d4e4 */
if(!s->budget--) { s->failed_pc=0x0c05d4e4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000022u)!=0);
goto P_0c05d4e6;
P_0c05d4e6: /* original 8913, guest PC 0x0c05d4e6 */
if(!s->budget--) { s->failed_pc=0x0c05d4e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d510; }
goto P_0c05d4e8;
P_0c05d4e8: /* original ea00, guest PC 0x0c05d4e8 */
if(!s->budget--) { s->failed_pc=0x0c05d4e8u; return 0; }
r[10]=0x00000000u;
goto P_0c05d4ea;
P_0c05d4ea: /* original 63a3, guest PC 0x0c05d4ea */
if(!s->budget--) { s->failed_pc=0x0c05d4eau; return 0; }
r[3]=r[10];
goto P_0c05d4ec;
P_0c05d4ec: /* original 33d2, guest PC 0x0c05d4ec */
if(!s->budget--) { s->failed_pc=0x0c05d4ecu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c05d4ee;
P_0c05d4ee: /* original 890d, guest PC 0x0c05d4ee */
if(!s->budget--) { s->failed_pc=0x0c05d4eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d50c; }
goto P_0c05d4f0;
P_0c05d4f0: /* original e620, guest PC 0x0c05d4f0 */
if(!s->budget--) { s->failed_pc=0x0c05d4f0u; return 0; }
r[6]=0x00000020u;
goto P_0c05d4f2;
P_0c05d4f2: /* original 65e3, guest PC 0x0c05d4f2 */
if(!s->budget--) { s->failed_pc=0x0c05d4f2u; return 0; }
r[5]=r[14];
goto P_0c05d4f4;
P_0c05d4f4: /* original 64a3, guest PC 0x0c05d4f4 */
if(!s->budget--) { s->failed_pc=0x0c05d4f4u; return 0; }
r[4]=r[10];
goto P_0c05d4f6;
P_0c05d4f6: /* original 63a3, guest PC 0x0c05d4f6 */
if(!s->budget--) { s->failed_pc=0x0c05d4f6u; return 0; }
r[3]=r[10];
goto P_0c05d4f8;
P_0c05d4f8: /* original 4408, guest PC 0x0c05d4f8 */
if(!s->budget--) { s->failed_pc=0x0c05d4f8u; return 0; }
r[4]<<=2;
goto P_0c05d4fa;
P_0c05d4fa: /* original 343c, guest PC 0x0c05d4fa */
if(!s->budget--) { s->failed_pc=0x0c05d4fau; return 0; }
r[4]+=r[3];
goto P_0c05d4fc;
P_0c05d4fc: /* original 4408, guest PC 0x0c05d4fc */
if(!s->budget--) { s->failed_pc=0x0c05d4fcu; return 0; }
r[4]<<=2;
goto P_0c05d4fe;
P_0c05d4fe: /* original 644e, guest PC 0x0c05d4fe */
if(!s->budget--) { s->failed_pc=0x0c05d4feu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c05d500;
P_0c05d500: /* original 34bc, guest PC 0x0c05d500 */
if(!s->budget--) { s->failed_pc=0x0c05d500u; return 0; }
r[4]+=r[11];
goto P_0c05d502;
P_0c05d502: /* original 4c0b, guest PC 0x0c05d502 */
if(!s->budget--) { s->failed_pc=0x0c05d502u; return 0; }
target=r[12];
r[16]=code_base|0x0c05d506u;
r[4]=read(ram,r[4]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d506u) { target=s->pc; goto dispatch; }
goto P_0c05d506;
P_0c05d504: /* original 5442, guest PC 0x0c05d504 */
if(!s->budget--) { s->failed_pc=0x0c05d504u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c05d506;
P_0c05d506: /* original 7a01, guest PC 0x0c05d506 */
if(!s->budget--) { s->failed_pc=0x0c05d506u; return 0; }
r[10]+=0x00000001u;
goto P_0c05d508;
P_0c05d508: /* original 3ad2, guest PC 0x0c05d508 */
if(!s->budget--) { s->failed_pc=0x0c05d508u; return 0; }
r[17]=(r[17]&~1u)|((r[10]>=r[13])!=0);
goto P_0c05d50a;
P_0c05d50a: /* original 8bf1, guest PC 0x0c05d50a */
if(!s->budget--) { s->failed_pc=0x0c05d50au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d4f0; }
goto P_0c05d50c;
P_0c05d50c: /* original e308, guest PC 0x0c05d50c */
if(!s->budget--) { s->failed_pc=0x0c05d50cu; return 0; }
r[3]=0x00000008u;
goto P_0c05d50e;
P_0c05d50e: /* original 1832, guest PC 0x0c05d50e */
if(!s->budget--) { s->failed_pc=0x0c05d50eu; return 0; }
write(ram,r[8]+8,r[3],4);
goto P_0c05d510;
P_0c05d510: /* original d154, guest PC 0x0c05d510 */
if(!s->budget--) { s->failed_pc=0x0c05d510u; return 0; }
r[1]=read(ram,0x0c05d664u,4);
goto P_0c05d512;
P_0c05d512: /* original 6212, guest PC 0x0c05d512 */
if(!s->budget--) { s->failed_pc=0x0c05d512u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c05d514;
P_0c05d514: /* original 2298, guest PC 0x0c05d514 */
if(!s->budget--) { s->failed_pc=0x0c05d514u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[9])==0)!=0);
goto P_0c05d516;
P_0c05d516: /* original 891c, guest PC 0x0c05d516 */
if(!s->budget--) { s->failed_pc=0x0c05d516u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d552; }
goto P_0c05d518;
P_0c05d518: /* original d057, guest PC 0x0c05d518 */
if(!s->budget--) { s->failed_pc=0x0c05d518u; return 0; }
r[0]=read(ram,0x0c05d678u,4);
goto P_0c05d51a;
P_0c05d51a: /* original 2e02, guest PC 0x0c05d51a */
if(!s->budget--) { s->failed_pc=0x0c05d51au; return 0; }
write(ram,r[14],r[0],4);
goto P_0c05d51c;
P_0c05d51c: /* original d252, guest PC 0x0c05d51c */
if(!s->budget--) { s->failed_pc=0x0c05d51cu; return 0; }
r[2]=read(ram,0x0c05d668u,4);
goto P_0c05d51e;
P_0c05d51e: /* original 6322, guest PC 0x0c05d51e */
if(!s->budget--) { s->failed_pc=0x0c05d51eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c05d520;
P_0c05d520: /* original 2338, guest PC 0x0c05d520 */
if(!s->budget--) { s->failed_pc=0x0c05d520u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c05d522;
P_0c05d522: /* original 8903, guest PC 0x0c05d522 */
if(!s->budget--) { s->failed_pc=0x0c05d522u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d52c; }
goto P_0c05d524;
P_0c05d524: /* original d351, guest PC 0x0c05d524 */
if(!s->budget--) { s->failed_pc=0x0c05d524u; return 0; }
r[3]=read(ram,0x0c05d66cu,4);
goto P_0c05d526;
P_0c05d526: /* original 6032, guest PC 0x0c05d526 */
if(!s->budget--) { s->failed_pc=0x0c05d526u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05d528;
P_0c05d528: /* original 8823, guest PC 0x0c05d528 */
if(!s->budget--) { s->failed_pc=0x0c05d528u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000023u)!=0);
goto P_0c05d52a;
P_0c05d52a: /* original 8912, guest PC 0x0c05d52a */
if(!s->budget--) { s->failed_pc=0x0c05d52au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d552; }
goto P_0c05d52c;
P_0c05d52c: /* original ea00, guest PC 0x0c05d52c */
if(!s->budget--) { s->failed_pc=0x0c05d52cu; return 0; }
r[10]=0x00000000u;
goto P_0c05d52e;
P_0c05d52e: /* original 63a3, guest PC 0x0c05d52e */
if(!s->budget--) { s->failed_pc=0x0c05d52eu; return 0; }
r[3]=r[10];
goto P_0c05d530;
P_0c05d530: /* original 33d2, guest PC 0x0c05d530 */
if(!s->budget--) { s->failed_pc=0x0c05d530u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c05d532;
P_0c05d532: /* original 890d, guest PC 0x0c05d532 */
if(!s->budget--) { s->failed_pc=0x0c05d532u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d550; }
goto P_0c05d534;
P_0c05d534: /* original e620, guest PC 0x0c05d534 */
if(!s->budget--) { s->failed_pc=0x0c05d534u; return 0; }
r[6]=0x00000020u;
goto P_0c05d536;
P_0c05d536: /* original 65e3, guest PC 0x0c05d536 */
if(!s->budget--) { s->failed_pc=0x0c05d536u; return 0; }
r[5]=r[14];
goto P_0c05d538;
P_0c05d538: /* original 64a3, guest PC 0x0c05d538 */
if(!s->budget--) { s->failed_pc=0x0c05d538u; return 0; }
r[4]=r[10];
goto P_0c05d53a;
P_0c05d53a: /* original 63a3, guest PC 0x0c05d53a */
if(!s->budget--) { s->failed_pc=0x0c05d53au; return 0; }
r[3]=r[10];
goto P_0c05d53c;
P_0c05d53c: /* original 4408, guest PC 0x0c05d53c */
if(!s->budget--) { s->failed_pc=0x0c05d53cu; return 0; }
r[4]<<=2;
goto P_0c05d53e;
P_0c05d53e: /* original 343c, guest PC 0x0c05d53e */
if(!s->budget--) { s->failed_pc=0x0c05d53eu; return 0; }
r[4]+=r[3];
goto P_0c05d540;
P_0c05d540: /* original 4408, guest PC 0x0c05d540 */
if(!s->budget--) { s->failed_pc=0x0c05d540u; return 0; }
r[4]<<=2;
goto P_0c05d542;
P_0c05d542: /* original 644e, guest PC 0x0c05d542 */
if(!s->budget--) { s->failed_pc=0x0c05d542u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c05d544;
P_0c05d544: /* original 34bc, guest PC 0x0c05d544 */
if(!s->budget--) { s->failed_pc=0x0c05d544u; return 0; }
r[4]+=r[11];
goto P_0c05d546;
P_0c05d546: /* original 4c0b, guest PC 0x0c05d546 */
if(!s->budget--) { s->failed_pc=0x0c05d546u; return 0; }
target=r[12];
r[16]=code_base|0x0c05d54au;
r[4]=read(ram,r[4]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d54au) { target=s->pc; goto dispatch; }
goto P_0c05d54a;
P_0c05d548: /* original 5443, guest PC 0x0c05d548 */
if(!s->budget--) { s->failed_pc=0x0c05d548u; return 0; }
r[4]=read(ram,r[4]+12,4);
goto P_0c05d54a;
P_0c05d54a: /* original 7a01, guest PC 0x0c05d54a */
if(!s->budget--) { s->failed_pc=0x0c05d54au; return 0; }
r[10]+=0x00000001u;
goto P_0c05d54c;
P_0c05d54c: /* original 3ad2, guest PC 0x0c05d54c */
if(!s->budget--) { s->failed_pc=0x0c05d54cu; return 0; }
r[17]=(r[17]&~1u)|((r[10]>=r[13])!=0);
goto P_0c05d54e;
P_0c05d54e: /* original 8bf1, guest PC 0x0c05d54e */
if(!s->budget--) { s->failed_pc=0x0c05d54eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d534; }
goto P_0c05d550;
P_0c05d550: /* original 1893, guest PC 0x0c05d550 */
if(!s->budget--) { s->failed_pc=0x0c05d550u; return 0; }
write(ram,r[8]+12,r[9],4);
goto P_0c05d552;
P_0c05d552: /* original d344, guest PC 0x0c05d552 */
if(!s->budget--) { s->failed_pc=0x0c05d552u; return 0; }
r[3]=read(ram,0x0c05d664u,4);
goto P_0c05d554;
P_0c05d554: /* original 6032, guest PC 0x0c05d554 */
if(!s->budget--) { s->failed_pc=0x0c05d554u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05d556;
P_0c05d556: /* original c810, guest PC 0x0c05d556 */
if(!s->budget--) { s->failed_pc=0x0c05d556u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c05d558;
P_0c05d558: /* original 891c, guest PC 0x0c05d558 */
if(!s->budget--) { s->failed_pc=0x0c05d558u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d594; }
goto P_0c05d55a;
P_0c05d55a: /* original d148, guest PC 0x0c05d55a */
if(!s->budget--) { s->failed_pc=0x0c05d55au; return 0; }
r[1]=read(ram,0x0c05d67cu,4);
goto P_0c05d55c;
P_0c05d55c: /* original d042, guest PC 0x0c05d55c */
if(!s->budget--) { s->failed_pc=0x0c05d55cu; return 0; }
r[0]=read(ram,0x0c05d668u,4);
goto P_0c05d55e;
P_0c05d55e: /* original 2e12, guest PC 0x0c05d55e */
if(!s->budget--) { s->failed_pc=0x0c05d55eu; return 0; }
write(ram,r[14],r[1],4);
goto P_0c05d560;
P_0c05d560: /* original 6202, guest PC 0x0c05d560 */
if(!s->budget--) { s->failed_pc=0x0c05d560u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c05d562;
P_0c05d562: /* original 2228, guest PC 0x0c05d562 */
if(!s->budget--) { s->failed_pc=0x0c05d562u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c05d564;
P_0c05d564: /* original 8903, guest PC 0x0c05d564 */
if(!s->budget--) { s->failed_pc=0x0c05d564u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d56e; }
goto P_0c05d566;
P_0c05d566: /* original d241, guest PC 0x0c05d566 */
if(!s->budget--) { s->failed_pc=0x0c05d566u; return 0; }
r[2]=read(ram,0x0c05d66cu,4);
goto P_0c05d568;
P_0c05d568: /* original 6022, guest PC 0x0c05d568 */
if(!s->budget--) { s->failed_pc=0x0c05d568u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05d56a;
P_0c05d56a: /* original 8824, guest PC 0x0c05d56a */
if(!s->budget--) { s->failed_pc=0x0c05d56au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000024u)!=0);
goto P_0c05d56c;
P_0c05d56c: /* original 8912, guest PC 0x0c05d56c */
if(!s->budget--) { s->failed_pc=0x0c05d56cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d594; }
goto P_0c05d56e;
P_0c05d56e: /* original ea00, guest PC 0x0c05d56e */
if(!s->budget--) { s->failed_pc=0x0c05d56eu; return 0; }
r[10]=0x00000000u;
goto P_0c05d570;
P_0c05d570: /* original 63a3, guest PC 0x0c05d570 */
if(!s->budget--) { s->failed_pc=0x0c05d570u; return 0; }
r[3]=r[10];
goto P_0c05d572;
P_0c05d572: /* original 33d2, guest PC 0x0c05d572 */
if(!s->budget--) { s->failed_pc=0x0c05d572u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c05d574;
P_0c05d574: /* original 890d, guest PC 0x0c05d574 */
if(!s->budget--) { s->failed_pc=0x0c05d574u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d592; }
goto P_0c05d576;
P_0c05d576: /* original e620, guest PC 0x0c05d576 */
if(!s->budget--) { s->failed_pc=0x0c05d576u; return 0; }
r[6]=0x00000020u;
goto P_0c05d578;
P_0c05d578: /* original 65e3, guest PC 0x0c05d578 */
if(!s->budget--) { s->failed_pc=0x0c05d578u; return 0; }
r[5]=r[14];
goto P_0c05d57a;
P_0c05d57a: /* original 64a3, guest PC 0x0c05d57a */
if(!s->budget--) { s->failed_pc=0x0c05d57au; return 0; }
r[4]=r[10];
goto P_0c05d57c;
P_0c05d57c: /* original 63a3, guest PC 0x0c05d57c */
if(!s->budget--) { s->failed_pc=0x0c05d57cu; return 0; }
r[3]=r[10];
goto P_0c05d57e;
P_0c05d57e: /* original 4408, guest PC 0x0c05d57e */
if(!s->budget--) { s->failed_pc=0x0c05d57eu; return 0; }
r[4]<<=2;
goto P_0c05d580;
P_0c05d580: /* original 343c, guest PC 0x0c05d580 */
if(!s->budget--) { s->failed_pc=0x0c05d580u; return 0; }
r[4]+=r[3];
goto P_0c05d582;
P_0c05d582: /* original 4408, guest PC 0x0c05d582 */
if(!s->budget--) { s->failed_pc=0x0c05d582u; return 0; }
r[4]<<=2;
goto P_0c05d584;
P_0c05d584: /* original 644e, guest PC 0x0c05d584 */
if(!s->budget--) { s->failed_pc=0x0c05d584u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c05d586;
P_0c05d586: /* original 34bc, guest PC 0x0c05d586 */
if(!s->budget--) { s->failed_pc=0x0c05d586u; return 0; }
r[4]+=r[11];
goto P_0c05d588;
P_0c05d588: /* original 4c0b, guest PC 0x0c05d588 */
if(!s->budget--) { s->failed_pc=0x0c05d588u; return 0; }
target=r[12];
r[16]=code_base|0x0c05d58cu;
r[4]=read(ram,r[4]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d58cu) { target=s->pc; goto dispatch; }
goto P_0c05d58c;
P_0c05d58a: /* original 5444, guest PC 0x0c05d58a */
if(!s->budget--) { s->failed_pc=0x0c05d58au; return 0; }
r[4]=read(ram,r[4]+16,4);
goto P_0c05d58c;
P_0c05d58c: /* original 7a01, guest PC 0x0c05d58c */
if(!s->budget--) { s->failed_pc=0x0c05d58cu; return 0; }
r[10]+=0x00000001u;
goto P_0c05d58e;
P_0c05d58e: /* original 3ad2, guest PC 0x0c05d58e */
if(!s->budget--) { s->failed_pc=0x0c05d58eu; return 0; }
r[17]=(r[17]&~1u)|((r[10]>=r[13])!=0);
goto P_0c05d590;
P_0c05d590: /* original 8bf1, guest PC 0x0c05d590 */
if(!s->budget--) { s->failed_pc=0x0c05d590u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d576; }
goto P_0c05d592;
P_0c05d592: /* original 1894, guest PC 0x0c05d592 */
if(!s->budget--) { s->failed_pc=0x0c05d592u; return 0; }
write(ram,r[8]+16,r[9],4);
goto P_0c05d594;
P_0c05d594: /* original 7f20, guest PC 0x0c05d594 */
if(!s->budget--) { s->failed_pc=0x0c05d594u; return 0; }
r[15]+=0x00000020u;
goto P_0c05d596;
P_0c05d596: /* original 4f26, guest PC 0x0c05d596 */
if(!s->budget--) { s->failed_pc=0x0c05d596u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05d598;
P_0c05d598: /* original 68f6, guest PC 0x0c05d598 */
if(!s->budget--) { s->failed_pc=0x0c05d598u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c05d59a;
P_0c05d59a: /* original 69f6, guest PC 0x0c05d59a */
if(!s->budget--) { s->failed_pc=0x0c05d59au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05d59c;
P_0c05d59c: /* original 6af6, guest PC 0x0c05d59c */
if(!s->budget--) { s->failed_pc=0x0c05d59cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05d59e;
P_0c05d59e: /* original 6bf6, guest PC 0x0c05d59e */
if(!s->budget--) { s->failed_pc=0x0c05d59eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05d5a0;
P_0c05d5a0: /* original 6cf6, guest PC 0x0c05d5a0 */
if(!s->budget--) { s->failed_pc=0x0c05d5a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05d5a2;
P_0c05d5a2: /* original 6df6, guest PC 0x0c05d5a2 */
if(!s->budget--) { s->failed_pc=0x0c05d5a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05d5a4;
P_0c05d5a4: /* original 000b, guest PC 0x0c05d5a4 */
if(!s->budget--) { s->failed_pc=0x0c05d5a4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05d5a6: /* original 6ef6, guest PC 0x0c05d5a6 */
if(!s->budget--) { s->failed_pc=0x0c05d5a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c05d5a8;
P_0c05d5a8: /* original 4f22, guest PC 0x0c05d5a8 */
if(!s->budget--) { s->failed_pc=0x0c05d5a8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05d5aa;
P_0c05d5aa: /* original 7fe4, guest PC 0x0c05d5aa */
if(!s->budget--) { s->failed_pc=0x0c05d5aau; return 0; }
r[15]+=0xffffffe4u;
goto P_0c05d5ac;
P_0c05d5ac: /* original d234, guest PC 0x0c05d5ac */
if(!s->budget--) { s->failed_pc=0x0c05d5acu; return 0; }
r[2]=read(ram,0x0c05d680u,4);
goto P_0c05d5ae;
P_0c05d5ae: /* original 65f3, guest PC 0x0c05d5ae */
if(!s->budget--) { s->failed_pc=0x0c05d5aeu; return 0; }
r[5]=r[15];
goto P_0c05d5b0;
P_0c05d5b0: /* original d328, guest PC 0x0c05d5b0 */
if(!s->budget--) { s->failed_pc=0x0c05d5b0u; return 0; }
r[3]=read(ram,0x0c05d654u,4);
goto P_0c05d5b2;
P_0c05d5b2: /* original 61f3, guest PC 0x0c05d5b2 */
if(!s->budget--) { s->failed_pc=0x0c05d5b2u; return 0; }
r[1]=r[15];
goto P_0c05d5b4;
P_0c05d5b4: /* original 750c, guest PC 0x0c05d5b4 */
if(!s->budget--) { s->failed_pc=0x0c05d5b4u; return 0; }
r[5]+=0x0000000cu;
goto P_0c05d5b6;
P_0c05d5b6: /* original 710c, guest PC 0x0c05d5b6 */
if(!s->budget--) { s->failed_pc=0x0c05d5b6u; return 0; }
r[1]+=0x0000000cu;
goto P_0c05d5b8;
P_0c05d5b8: /* original 430b, guest PC 0x0c05d5b8 */
if(!s->budget--) { s->failed_pc=0x0c05d5b8u; return 0; }
target=r[3];
r[16]=code_base|0x0c05d5bcu;
r[0]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d5bcu) { target=s->pc; goto dispatch; }
goto P_0c05d5bc;
P_0c05d5ba: /* original e010, guest PC 0x0c05d5ba */
if(!s->budget--) { s->failed_pc=0x0c05d5bau; return 0; }
r[0]=0x00000010u;
goto P_0c05d5bc;
P_0c05d5bc: /* original e603, guest PC 0x0c05d5bc */
if(!s->budget--) { s->failed_pc=0x0c05d5bcu; return 0; }
r[6]=0x00000003u;
goto P_0c05d5be;
P_0c05d5be: /* original 6143, guest PC 0x0c05d5be */
if(!s->budget--) { s->failed_pc=0x0c05d5beu; return 0; }
r[1]=r[4];
goto P_0c05d5c0;
P_0c05d5c0: /* original 4129, guest PC 0x0c05d5c0 */
if(!s->budget--) { s->failed_pc=0x0c05d5c0u; return 0; }
r[1]>>=16;
goto P_0c05d5c2;
P_0c05d5c2: /* original 4101, guest PC 0x0c05d5c2 */
if(!s->budget--) { s->failed_pc=0x0c05d5c2u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c05d5c4;
P_0c05d5c4: /* original 2169, guest PC 0x0c05d5c4 */
if(!s->budget--) { s->failed_pc=0x0c05d5c4u; return 0; }
r[1]&=r[6];
goto P_0c05d5c6;
P_0c05d5c6: /* original 6743, guest PC 0x0c05d5c6 */
if(!s->budget--) { s->failed_pc=0x0c05d5c6u; return 0; }
r[7]=r[4];
goto P_0c05d5c8;
P_0c05d5c8: /* original 1f11, guest PC 0x0c05d5c8 */
if(!s->budget--) { s->failed_pc=0x0c05d5c8u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c05d5ca;
P_0c05d5ca: /* original 6343, guest PC 0x0c05d5ca */
if(!s->budget--) { s->failed_pc=0x0c05d5cau; return 0; }
r[3]=r[4];
goto P_0c05d5cc;
P_0c05d5cc: /* original 4729, guest PC 0x0c05d5cc */
if(!s->budget--) { s->failed_pc=0x0c05d5ccu; return 0; }
r[7]>>=16;
goto P_0c05d5ce;
P_0c05d5ce: /* original 4709, guest PC 0x0c05d5ce */
if(!s->budget--) { s->failed_pc=0x0c05d5ceu; return 0; }
r[7]>>=2;
goto P_0c05d5d0;
P_0c05d5d0: /* original 4701, guest PC 0x0c05d5d0 */
if(!s->budget--) { s->failed_pc=0x0c05d5d0u; return 0; }
r[17]=(r[17]&~1u)|((r[7]&1)!=0);
r[7]>>=1;
goto P_0c05d5d2;
P_0c05d5d2: /* original 2769, guest PC 0x0c05d5d2 */
if(!s->budget--) { s->failed_pc=0x0c05d5d2u; return 0; }
r[7]&=r[6];
goto P_0c05d5d4;
P_0c05d5d4: /* original e0eb, guest PC 0x0c05d5d4 */
if(!s->budget--) { s->failed_pc=0x0c05d5d4u; return 0; }
r[0]=0xffffffebu;
goto P_0c05d5d6;
P_0c05d5d6: /* original 430d, guest PC 0x0c05d5d6 */
if(!s->budget--) { s->failed_pc=0x0c05d5d6u; return 0; }
r[3]=(r[0]&0x80000000u)?((r[0]&31u)?r[3]>>((-r[0])&31u):0):r[3]<<(r[0]&31u);
goto P_0c05d5d8;
P_0c05d5d8: /* original 2369, guest PC 0x0c05d5d8 */
if(!s->budget--) { s->failed_pc=0x0c05d5d8u; return 0; }
r[3]&=r[6];
goto P_0c05d5da;
P_0c05d5da: /* original 6243, guest PC 0x0c05d5da */
if(!s->budget--) { s->failed_pc=0x0c05d5dau; return 0; }
r[2]=r[4];
goto P_0c05d5dc;
P_0c05d5dc: /* original 2f32, guest PC 0x0c05d5dc */
if(!s->budget--) { s->failed_pc=0x0c05d5dcu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c05d5de;
P_0c05d5de: /* original e0e9, guest PC 0x0c05d5de */
if(!s->budget--) { s->failed_pc=0x0c05d5deu; return 0; }
r[0]=0xffffffe9u;
goto P_0c05d5e0;
P_0c05d5e0: /* original 420d, guest PC 0x0c05d5e0 */
if(!s->budget--) { s->failed_pc=0x0c05d5e0u; return 0; }
r[2]=(r[0]&0x80000000u)?((r[0]&31u)?r[2]>>((-r[0])&31u):0):r[2]<<(r[0]&31u);
goto P_0c05d5e2;
P_0c05d5e2: /* original 2269, guest PC 0x0c05d5e2 */
if(!s->budget--) { s->failed_pc=0x0c05d5e2u; return 0; }
r[2]&=r[6];
goto P_0c05d5e4;
P_0c05d5e4: /* original d027, guest PC 0x0c05d5e4 */
if(!s->budget--) { s->failed_pc=0x0c05d5e4u; return 0; }
r[0]=read(ram,0x0c05d684u,4);
goto P_0c05d5e6;
P_0c05d5e6: /* original 4429, guest PC 0x0c05d5e6 */
if(!s->budget--) { s->failed_pc=0x0c05d5e6u; return 0; }
r[4]>>=16;
goto P_0c05d5e8;
P_0c05d5e8: /* original 1f22, guest PC 0x0c05d5e8 */
if(!s->budget--) { s->failed_pc=0x0c05d5e8u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c05d5ea;
P_0c05d5ea: /* original 4419, guest PC 0x0c05d5ea */
if(!s->budget--) { s->failed_pc=0x0c05d5eau; return 0; }
r[4]>>=8;
goto P_0c05d5ec;
P_0c05d5ec: /* original 4401, guest PC 0x0c05d5ec */
if(!s->budget--) { s->failed_pc=0x0c05d5ecu; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c05d5ee;
P_0c05d5ee: /* original 2649, guest PC 0x0c05d5ee */
if(!s->budget--) { s->failed_pc=0x0c05d5eeu; return 0; }
r[6]&=r[4];
goto P_0c05d5f0;
P_0c05d5f0: /* original 6102, guest PC 0x0c05d5f0 */
if(!s->budget--) { s->failed_pc=0x0c05d5f0u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c05d5f2;
P_0c05d5f2: /* original d325, guest PC 0x0c05d5f2 */
if(!s->budget--) { s->failed_pc=0x0c05d5f2u; return 0; }
r[3]=read(ram,0x0c05d688u,4);
goto P_0c05d5f4;
P_0c05d5f4: /* original 6032, guest PC 0x0c05d5f4 */
if(!s->budget--) { s->failed_pc=0x0c05d5f4u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05d5f6;
P_0c05d5f6: /* original 0017, guest PC 0x0c05d5f6 */
if(!s->budget--) { s->failed_pc=0x0c05d5f6u; return 0; }
r[19]=r[0]*r[1];
goto P_0c05d5f8;
P_0c05d5f8: /* original d124, guest PC 0x0c05d5f8 */
if(!s->budget--) { s->failed_pc=0x0c05d5f8u; return 0; }
r[1]=read(ram,0x0c05d68cu,4);
goto P_0c05d5fa;
P_0c05d5fa: /* original 6012, guest PC 0x0c05d5fa */
if(!s->budget--) { s->failed_pc=0x0c05d5fau; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05d5fc;
P_0c05d5fc: /* original c820, guest PC 0x0c05d5fc */
if(!s->budget--) { s->failed_pc=0x0c05d5fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c05d5fe;
P_0c05d5fe: /* original 8d07, guest PC 0x0c05d5fe */
if(!s->budget--) { s->failed_pc=0x0c05d5feu; return 0; }
cond=r[17]&1u;
r[4]=r[19];
if(cond) { goto P_0c05d610; }
goto P_0c05d602;
P_0c05d600: /* original 041a, guest PC 0x0c05d600 */
if(!s->budget--) { s->failed_pc=0x0c05d600u; return 0; }
r[4]=r[19];
goto P_0c05d602;
P_0c05d602: /* original d023, guest PC 0x0c05d602 */
if(!s->budget--) { s->failed_pc=0x0c05d602u; return 0; }
r[0]=read(ram,0x0c05d690u,4);
goto P_0c05d604;
P_0c05d604: /* original 6202, guest PC 0x0c05d604 */
if(!s->budget--) { s->failed_pc=0x0c05d604u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c05d606;
P_0c05d606: /* original 2228, guest PC 0x0c05d606 */
if(!s->budget--) { s->failed_pc=0x0c05d606u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c05d608;
P_0c05d608: /* original 8901, guest PC 0x0c05d608 */
if(!s->budget--) { s->failed_pc=0x0c05d608u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d60e; }
goto P_0c05d60a;
P_0c05d60a: /* original a001, guest PC 0x0c05d60a */
if(!s->budget--) { s->failed_pc=0x0c05d60au; return 0; }
r[4]<<=2;
goto P_0c05d610;
P_0c05d60c: /* original 4408, guest PC 0x0c05d60c */
if(!s->budget--) { s->failed_pc=0x0c05d60cu; return 0; }
r[4]<<=2;
goto P_0c05d60e;
P_0c05d60e: /* original 344c, guest PC 0x0c05d60e */
if(!s->budget--) { s->failed_pc=0x0c05d60eu; return 0; }
r[4]+=r[4];
goto P_0c05d610;
P_0c05d610: /* original 50f1, guest PC 0x0c05d610 */
if(!s->budget--) { s->failed_pc=0x0c05d610u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c05d612;
P_0c05d612: /* original 4008, guest PC 0x0c05d612 */
if(!s->budget--) { s->failed_pc=0x0c05d612u; return 0; }
r[0]<<=2;
goto P_0c05d614;
P_0c05d614: /* original 035e, guest PC 0x0c05d614 */
if(!s->budget--) { s->failed_pc=0x0c05d614u; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c05d616;
P_0c05d616: /* original 6073, guest PC 0x0c05d616 */
if(!s->budget--) { s->failed_pc=0x0c05d616u; return 0; }
r[0]=r[7];
goto P_0c05d618;
P_0c05d618: /* original 0009, guest PC 0x0c05d618 */
if(!s->budget--) { s->failed_pc=0x0c05d618u; return 0; }
goto P_0c05d61a;
P_0c05d61a: /* original 4008, guest PC 0x0c05d61a */
if(!s->budget--) { s->failed_pc=0x0c05d61au; return 0; }
r[0]<<=2;
goto P_0c05d61c;
P_0c05d61c: /* original 025e, guest PC 0x0c05d61c */
if(!s->budget--) { s->failed_pc=0x0c05d61cu; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c05d61e;
P_0c05d61e: /* original 332c, guest PC 0x0c05d61e */
if(!s->budget--) { s->failed_pc=0x0c05d61eu; return 0; }
r[3]+=r[2];
goto P_0c05d620;
P_0c05d620: /* original 60f2, guest PC 0x0c05d620 */
if(!s->budget--) { s->failed_pc=0x0c05d620u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c05d622;
P_0c05d622: /* original 4008, guest PC 0x0c05d622 */
if(!s->budget--) { s->failed_pc=0x0c05d622u; return 0; }
r[0]<<=2;
goto P_0c05d624;
P_0c05d624: /* original 025e, guest PC 0x0c05d624 */
if(!s->budget--) { s->failed_pc=0x0c05d624u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c05d626;
P_0c05d626: /* original 332c, guest PC 0x0c05d626 */
if(!s->budget--) { s->failed_pc=0x0c05d626u; return 0; }
r[3]+=r[2];
goto P_0c05d628;
P_0c05d628: /* original 50f2, guest PC 0x0c05d628 */
if(!s->budget--) { s->failed_pc=0x0c05d628u; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c05d62a;
P_0c05d62a: /* original 4008, guest PC 0x0c05d62a */
if(!s->budget--) { s->failed_pc=0x0c05d62au; return 0; }
r[0]<<=2;
goto P_0c05d62c;
P_0c05d62c: /* original 025e, guest PC 0x0c05d62c */
if(!s->budget--) { s->failed_pc=0x0c05d62cu; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c05d62e;
P_0c05d62e: /* original 332c, guest PC 0x0c05d62e */
if(!s->budget--) { s->failed_pc=0x0c05d62eu; return 0; }
r[3]+=r[2];
goto P_0c05d630;
P_0c05d630: /* original 6063, guest PC 0x0c05d630 */
if(!s->budget--) { s->failed_pc=0x0c05d630u; return 0; }
r[0]=r[6];
goto P_0c05d632;
P_0c05d632: /* original 0009, guest PC 0x0c05d632 */
if(!s->budget--) { s->failed_pc=0x0c05d632u; return 0; }
goto P_0c05d634;
P_0c05d634: /* original d117, guest PC 0x0c05d634 */
if(!s->budget--) { s->failed_pc=0x0c05d634u; return 0; }
r[1]=read(ram,0x0c05d694u,4);
goto P_0c05d636;
P_0c05d636: /* original 4008, guest PC 0x0c05d636 */
if(!s->budget--) { s->failed_pc=0x0c05d636u; return 0; }
r[0]<<=2;
goto P_0c05d638;
P_0c05d638: /* original 025e, guest PC 0x0c05d638 */
if(!s->budget--) { s->failed_pc=0x0c05d638u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c05d63a;
P_0c05d63a: /* original 332c, guest PC 0x0c05d63a */
if(!s->budget--) { s->failed_pc=0x0c05d63au; return 0; }
r[3]+=r[2];
goto P_0c05d63c;
P_0c05d63c: /* original 4308, guest PC 0x0c05d63c */
if(!s->budget--) { s->failed_pc=0x0c05d63cu; return 0; }
r[3]<<=2;
goto P_0c05d63e;
P_0c05d63e: /* original 7318, guest PC 0x0c05d63e */
if(!s->budget--) { s->failed_pc=0x0c05d63eu; return 0; }
r[3]+=0x00000018u;
goto P_0c05d640;
P_0c05d640: /* original 0347, guest PC 0x0c05d640 */
if(!s->budget--) { s->failed_pc=0x0c05d640u; return 0; }
r[19]=r[3]*r[4];
goto P_0c05d642;
P_0c05d642: /* original 031a, guest PC 0x0c05d642 */
if(!s->budget--) { s->failed_pc=0x0c05d642u; return 0; }
r[3]=r[19];
goto P_0c05d644;
P_0c05d644: /* original 2132, guest PC 0x0c05d644 */
if(!s->budget--) { s->failed_pc=0x0c05d644u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c05d646;
P_0c05d646: /* original 7f1c, guest PC 0x0c05d646 */
if(!s->budget--) { s->failed_pc=0x0c05d646u; return 0; }
r[15]+=0x0000001cu;
goto P_0c05d648;
P_0c05d648: /* original 4f26, guest PC 0x0c05d648 */
if(!s->budget--) { s->failed_pc=0x0c05d648u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05d64a;
P_0c05d64a: /* original 000b, guest PC 0x0c05d64a */
if(!s->budget--) { s->failed_pc=0x0c05d64au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c05d64c: /* original 0009, guest PC 0x0c05d64c */
if(!s->budget--) { s->failed_pc=0x0c05d64cu; return 0; }
if(!vf3_matrix_family(0x0c05d64eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05d64eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
