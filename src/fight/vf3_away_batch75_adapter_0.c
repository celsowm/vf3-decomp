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
int vf3_away_batch75_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03c5b0u: goto P_0c03c5b0;
case 0x0c03c5b2u: goto P_0c03c5b2;
case 0x0c03c5b4u: goto P_0c03c5b4;
case 0x0c03c5b6u: goto P_0c03c5b6;
case 0x0c03c5b8u: goto P_0c03c5b8;
case 0x0c03c5bau: goto P_0c03c5ba;
case 0x0c03c5bcu: goto P_0c03c5bc;
case 0x0c03c5beu: goto P_0c03c5be;
case 0x0c03c5c0u: goto P_0c03c5c0;
case 0x0c03c5c2u: goto P_0c03c5c2;
case 0x0c03c5c4u: goto P_0c03c5c4;
case 0x0c03c5c6u: goto P_0c03c5c6;
case 0x0c03c5c8u: goto P_0c03c5c8;
case 0x0c03c5cau: goto P_0c03c5ca;
case 0x0c03c5ccu: goto P_0c03c5cc;
case 0x0c03c5ceu: goto P_0c03c5ce;
case 0x0c03c5d0u: goto P_0c03c5d0;
case 0x0c03c5d2u: goto P_0c03c5d2;
case 0x0c03c5d4u: goto P_0c03c5d4;
case 0x0c03c5d6u: goto P_0c03c5d6;
case 0x0c03c5d8u: goto P_0c03c5d8;
case 0x0c03c5dau: goto P_0c03c5da;
case 0x0c03c5dcu: goto P_0c03c5dc;
case 0x0c03c5deu: goto P_0c03c5de;
case 0x0c03c5e0u: goto P_0c03c5e0;
case 0x0c03c5e2u: goto P_0c03c5e2;
case 0x0c03c5e4u: goto P_0c03c5e4;
case 0x0c03c5e6u: goto P_0c03c5e6;
case 0x0c03c5e8u: goto P_0c03c5e8;
case 0x0c03c5eau: goto P_0c03c5ea;
case 0x0c09d42cu: goto P_0c09d42c;
case 0x0c09d42eu: goto P_0c09d42e;
case 0x0c09d430u: goto P_0c09d430;
case 0x0c09d432u: goto P_0c09d432;
case 0x0c09d434u: goto P_0c09d434;
case 0x0c09d436u: goto P_0c09d436;
case 0x0c09d438u: goto P_0c09d438;
case 0x0c09d43au: goto P_0c09d43a;
case 0x0c09d43cu: goto P_0c09d43c;
case 0x0c09d43eu: goto P_0c09d43e;
case 0x0c09d440u: goto P_0c09d440;
case 0x0c09d442u: goto P_0c09d442;
case 0x0c09d444u: goto P_0c09d444;
case 0x0c09d446u: goto P_0c09d446;
case 0x0c09d448u: goto P_0c09d448;
case 0x0c09d44au: goto P_0c09d44a;
case 0x0c09d44cu: goto P_0c09d44c;
case 0x0c09d44eu: goto P_0c09d44e;
case 0x0c09d450u: goto P_0c09d450;
case 0x0c09d452u: goto P_0c09d452;
case 0x0c09d454u: goto P_0c09d454;
case 0x0c09d456u: goto P_0c09d456;
case 0x0c09d458u: goto P_0c09d458;
case 0x0c09d45au: goto P_0c09d45a;
case 0x0c09d45cu: goto P_0c09d45c;
case 0x0c09d45eu: goto P_0c09d45e;
case 0x0c09d460u: goto P_0c09d460;
case 0x0c09d462u: goto P_0c09d462;
case 0x0c09d464u: goto P_0c09d464;
case 0x0c09d466u: goto P_0c09d466;
case 0x0c09d468u: goto P_0c09d468;
case 0x0c09d46au: goto P_0c09d46a;
case 0x0c09d46cu: goto P_0c09d46c;
case 0x0c09d46eu: goto P_0c09d46e;
case 0x0c09d470u: goto P_0c09d470;
case 0x0c09d472u: goto P_0c09d472;
case 0x0c09d474u: goto P_0c09d474;
case 0x0c09d476u: goto P_0c09d476;
case 0x0c09d478u: goto P_0c09d478;
case 0x0c09d47au: goto P_0c09d47a;
case 0x0c09d47cu: goto P_0c09d47c;
case 0x0c09d47eu: goto P_0c09d47e;
case 0x0c09d480u: goto P_0c09d480;
case 0x0c09d482u: goto P_0c09d482;
case 0x0c09d484u: goto P_0c09d484;
case 0x0c09d486u: goto P_0c09d486;
case 0x0c09d488u: goto P_0c09d488;
case 0x0c09d48au: goto P_0c09d48a;
case 0x0c09d48cu: goto P_0c09d48c;
case 0x0c09d48eu: goto P_0c09d48e;
case 0x0c09d490u: goto P_0c09d490;
case 0x0c09d492u: goto P_0c09d492;
case 0x0c09d494u: goto P_0c09d494;
case 0x0c09d496u: goto P_0c09d496;
case 0x0c09d498u: goto P_0c09d498;
case 0x0c09d49au: goto P_0c09d49a;
case 0x0c09d49cu: goto P_0c09d49c;
case 0x0c09d49eu: goto P_0c09d49e;
case 0x0c09d4a0u: goto P_0c09d4a0;
case 0x0c09d4a2u: goto P_0c09d4a2;
case 0x0c09d4a4u: goto P_0c09d4a4;
case 0x0c09d4a6u: goto P_0c09d4a6;
case 0x0c09d4a8u: goto P_0c09d4a8;
case 0x0c09d4aau: goto P_0c09d4aa;
case 0x0c09d4acu: goto P_0c09d4ac;
case 0x0c09d4aeu: goto P_0c09d4ae;
case 0x0c09d4b0u: goto P_0c09d4b0;
case 0x0c09d4b2u: goto P_0c09d4b2;
case 0x0c09d4b4u: goto P_0c09d4b4;
case 0x0c09d4b6u: goto P_0c09d4b6;
case 0x0c09d4b8u: goto P_0c09d4b8;
case 0x0c09d4bau: goto P_0c09d4ba;
case 0x0c09d4bcu: goto P_0c09d4bc;
case 0x0c09d4beu: goto P_0c09d4be;
case 0x0c09d4c0u: goto P_0c09d4c0;
case 0x0c09d4c2u: goto P_0c09d4c2;
case 0x0c09d4c4u: goto P_0c09d4c4;
case 0x0c09d4c6u: goto P_0c09d4c6;
case 0x0c09d4c8u: goto P_0c09d4c8;
case 0x0c09d4cau: goto P_0c09d4ca;
case 0x0c09d4ccu: goto P_0c09d4cc;
case 0x0c09d4ceu: goto P_0c09d4ce;
case 0x0c09d4d0u: goto P_0c09d4d0;
case 0x0c09d4d2u: goto P_0c09d4d2;
case 0x0c09d4d4u: goto P_0c09d4d4;
case 0x0c09d4d6u: goto P_0c09d4d6;
case 0x0c09d4d8u: goto P_0c09d4d8;
case 0x0c09d4dau: goto P_0c09d4da;
case 0x0c09d4dcu: goto P_0c09d4dc;
case 0x0c09d4deu: goto P_0c09d4de;
case 0x0c09d4e0u: goto P_0c09d4e0;
case 0x0c09d4e2u: goto P_0c09d4e2;
case 0x0c09d4e4u: goto P_0c09d4e4;
case 0x0c09d4e6u: goto P_0c09d4e6;
case 0x0c09d4e8u: goto P_0c09d4e8;
case 0x0c09d4eau: goto P_0c09d4ea;
case 0x0c09d4ecu: goto P_0c09d4ec;
case 0x0c09d4eeu: goto P_0c09d4ee;
case 0x0c09d4f0u: goto P_0c09d4f0;
case 0x0c09d4f2u: goto P_0c09d4f2;
case 0x0c09d4f4u: goto P_0c09d4f4;
case 0x0c09d4f6u: goto P_0c09d4f6;
case 0x0c09d4f8u: goto P_0c09d4f8;
case 0x0c09d4fau: goto P_0c09d4fa;
case 0x0c09d4fcu: goto P_0c09d4fc;
case 0x0c09d4feu: goto P_0c09d4fe;
case 0x0c09d500u: goto P_0c09d500;
case 0x0c09d502u: goto P_0c09d502;
case 0x0c09d504u: goto P_0c09d504;
case 0x0c09d506u: goto P_0c09d506;
case 0x0c09d508u: goto P_0c09d508;
case 0x0c09d50au: goto P_0c09d50a;
case 0x0c09d50cu: goto P_0c09d50c;
case 0x0c09d50eu: goto P_0c09d50e;
case 0x0c09d510u: goto P_0c09d510;
case 0x0c09d512u: goto P_0c09d512;
case 0x0c09d514u: goto P_0c09d514;
case 0x0c09d516u: goto P_0c09d516;
case 0x0c09d518u: goto P_0c09d518;
case 0x0c09d51au: goto P_0c09d51a;
case 0x0c09d51cu: goto P_0c09d51c;
case 0x0c09d51eu: goto P_0c09d51e;
case 0x0c09d520u: goto P_0c09d520;
case 0x0c09d522u: goto P_0c09d522;
case 0x0c09d524u: goto P_0c09d524;
case 0x0c09d526u: goto P_0c09d526;
case 0x0c09d528u: goto P_0c09d528;
case 0x0c09d52au: goto P_0c09d52a;
case 0x0c09d52cu: goto P_0c09d52c;
case 0x0c09d52eu: goto P_0c09d52e;
case 0x0c09d530u: goto P_0c09d530;
case 0x0c09d532u: goto P_0c09d532;
case 0x0c09d534u: goto P_0c09d534;
case 0x0c09d536u: goto P_0c09d536;
case 0x0c09d538u: goto P_0c09d538;
case 0x0c09d53au: goto P_0c09d53a;
case 0x0c09d53cu: goto P_0c09d53c;
case 0x0c09d53eu: goto P_0c09d53e;
case 0x0c09d540u: goto P_0c09d540;
case 0x0c09d542u: goto P_0c09d542;
case 0x0c09d544u: goto P_0c09d544;
case 0x0c09d546u: goto P_0c09d546;
case 0x0c09d548u: goto P_0c09d548;
case 0x0c09d54au: goto P_0c09d54a;
case 0x0c09d54cu: goto P_0c09d54c;
case 0x0c09d54eu: goto P_0c09d54e;
case 0x0c09d550u: goto P_0c09d550;
case 0x0c09d552u: goto P_0c09d552;
case 0x0c09d554u: goto P_0c09d554;
case 0x0c09d556u: goto P_0c09d556;
case 0x0c09d558u: goto P_0c09d558;
case 0x0c09d55au: goto P_0c09d55a;
case 0x0c09d55cu: goto P_0c09d55c;
case 0x0c09d55eu: goto P_0c09d55e;
case 0x0c09d560u: goto P_0c09d560;
case 0x0c09d562u: goto P_0c09d562;
case 0x0c09d564u: goto P_0c09d564;
case 0x0c09d566u: goto P_0c09d566;
case 0x0c09d568u: goto P_0c09d568;
case 0x0c09d56au: goto P_0c09d56a;
case 0x0c09d56cu: goto P_0c09d56c;
case 0x0c09d56eu: goto P_0c09d56e;
case 0x0c09d570u: goto P_0c09d570;
case 0x0c09d572u: goto P_0c09d572;
case 0x0c09d574u: goto P_0c09d574;
case 0x0c09d576u: goto P_0c09d576;
case 0x0c09d578u: goto P_0c09d578;
case 0x0c09d9eau: goto P_0c09d9ea;
case 0x0c09d9ecu: goto P_0c09d9ec;
case 0x0c09d9eeu: goto P_0c09d9ee;
case 0x0c09d9f0u: goto P_0c09d9f0;
case 0x0c09d9f2u: goto P_0c09d9f2;
case 0x0c09d9f4u: goto P_0c09d9f4;
case 0x0c09d9f6u: goto P_0c09d9f6;
case 0x0c09d9f8u: goto P_0c09d9f8;
case 0x0c09d9fau: goto P_0c09d9fa;
case 0x0c09d9fcu: goto P_0c09d9fc;
case 0x0c09d9feu: goto P_0c09d9fe;
case 0x0c09da00u: goto P_0c09da00;
case 0x0c09da02u: goto P_0c09da02;
case 0x0c09da04u: goto P_0c09da04;
case 0x0c09da06u: goto P_0c09da06;
case 0x0c09da08u: goto P_0c09da08;
case 0x0c09da0au: goto P_0c09da0a;
case 0x0c09da0cu: goto P_0c09da0c;
case 0x0c09da0eu: goto P_0c09da0e;
case 0x0c09da10u: goto P_0c09da10;
case 0x0c09da12u: goto P_0c09da12;
case 0x0c09da14u: goto P_0c09da14;
case 0x0c09da16u: goto P_0c09da16;
case 0x0c09da18u: goto P_0c09da18;
case 0x0c09da1au: goto P_0c09da1a;
case 0x0c09da1cu: goto P_0c09da1c;
case 0x0c09da1eu: goto P_0c09da1e;
case 0x0c09da20u: goto P_0c09da20;
case 0x0c09da22u: goto P_0c09da22;
case 0x0c09da24u: goto P_0c09da24;
case 0x0c09da26u: goto P_0c09da26;
case 0x0c09da28u: goto P_0c09da28;
case 0x0c09da2au: goto P_0c09da2a;
case 0x0c09da2cu: goto P_0c09da2c;
case 0x0c09da2eu: goto P_0c09da2e;
case 0x0c09da30u: goto P_0c09da30;
case 0x0c09da32u: goto P_0c09da32;
case 0x0c09da34u: goto P_0c09da34;
case 0x0c09da36u: goto P_0c09da36;
case 0x0c09da38u: goto P_0c09da38;
case 0x0c09da3au: goto P_0c09da3a;
case 0x0c09da3cu: goto P_0c09da3c;
case 0x0c09da3eu: goto P_0c09da3e;
case 0x0c09da40u: goto P_0c09da40;
case 0x0c09da42u: goto P_0c09da42;
case 0x0c09da44u: goto P_0c09da44;
case 0x0c09da46u: goto P_0c09da46;
case 0x0c09da48u: goto P_0c09da48;
case 0x0c09da4au: goto P_0c09da4a;
case 0x0c09da4cu: goto P_0c09da4c;
case 0x0c09da4eu: goto P_0c09da4e;
case 0x0c09da50u: goto P_0c09da50;
case 0x0c09da52u: goto P_0c09da52;
case 0x0c09da54u: goto P_0c09da54;
case 0x0c09da56u: goto P_0c09da56;
case 0x0c09da58u: goto P_0c09da58;
case 0x0c09da5au: goto P_0c09da5a;
case 0x0c09da5cu: goto P_0c09da5c;
case 0x0c09da5eu: goto P_0c09da5e;
case 0x0c09da60u: goto P_0c09da60;
case 0x0c09da62u: goto P_0c09da62;
case 0x0c09da64u: goto P_0c09da64;
case 0x0c09da66u: goto P_0c09da66;
case 0x0c09da68u: goto P_0c09da68;
case 0x0c09da6au: goto P_0c09da6a;
case 0x0c09da6cu: goto P_0c09da6c;
case 0x0c09da6eu: goto P_0c09da6e;
case 0x0c09da70u: goto P_0c09da70;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03c5b0: /* original fbfd, guest PC 0x0c03c5b0 */
if(!s->budget--) { s->failed_pc=0x0c03c5b0u; return 0; }
vf3_matrix_swap(s);
goto P_0c03c5b2;
P_0c03c5b2: /* original f38d, guest PC 0x0c03c5b2 */
if(!s->budget--) { s->failed_pc=0x0c03c5b2u; return 0; }
fr[3]=0;
goto P_0c03c5b4;
P_0c03c5b4: /* original fbb1, guest PC 0x0c03c5b4 */
if(!s->budget--) { s->failed_pc=0x0c03c5b4u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'-');
goto P_0c03c5b6;
P_0c03c5b6: /* original f78d, guest PC 0x0c03c5b6 */
if(!s->budget--) { s->failed_pc=0x0c03c5b6u; return 0; }
fr[7]=0;
goto P_0c03c5b8;
P_0c03c5b8: /* original ff9d, guest PC 0x0c03c5b8 */
if(!s->budget--) { s->failed_pc=0x0c03c5b8u; return 0; }
fr[15]=0x3f800000u;
goto P_0c03c5ba;
P_0c03c5ba: /* original f11d, guest PC 0x0c03c5ba */
if(!s->budget--) { s->failed_pc=0x0c03c5bau; return 0; }
r[53]=fr[1];
goto P_0c03c5bc;
P_0c03c5bc: /* original f3ed, guest PC 0x0c03c5bc */
if(!s->budget--) { s->failed_pc=0x0c03c5bcu; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c03c5be;
P_0c03c5be: /* original f14c, guest PC 0x0c03c5be */
if(!s->budget--) { s->failed_pc=0x0c03c5beu; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c03c5c0;
P_0c03c5c0: /* original f7ed, guest PC 0x0c03c5c0 */
if(!s->budget--) { s->failed_pc=0x0c03c5c0u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c03c5c2;
P_0c03c5c2: /* original f40d, guest PC 0x0c03c5c2 */
if(!s->budget--) { s->failed_pc=0x0c03c5c2u; return 0; }
fr[4]=r[53];
goto P_0c03c5c4;
P_0c03c5c4: /* original fbed, guest PC 0x0c03c5c4 */
if(!s->budget--) { s->failed_pc=0x0c03c5c4u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+8,r[18],fr+11)) goto unsupported;
goto P_0c03c5c6;
P_0c03c5c6: /* original fc8d, guest PC 0x0c03c5c6 */
if(!s->budget--) { s->failed_pc=0x0c03c5c6u; return 0; }
fr[12]=0;
goto P_0c03c5c8;
P_0c03c5c8: /* original fee1, guest PC 0x0c03c5c8 */
if(!s->budget--) { s->failed_pc=0x0c03c5c8u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[14],r[18],'-');
goto P_0c03c5ca;
P_0c03c5ca: /* original fc31, guest PC 0x0c03c5ca */
if(!s->budget--) { s->failed_pc=0x0c03c5cau; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'-');
goto P_0c03c5cc;
P_0c03c5cc: /* original fd8d, guest PC 0x0c03c5cc */
if(!s->budget--) { s->failed_pc=0x0c03c5ccu; return 0; }
fr[13]=0;
goto P_0c03c5ce;
P_0c03c5ce: /* original fd71, guest PC 0x0c03c5ce */
if(!s->budget--) { s->failed_pc=0x0c03c5ceu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[7],r[18],'-');
goto P_0c03c5d0;
P_0c03c5d0: /* original f21d, guest PC 0x0c03c5d0 */
if(!s->budget--) { s->failed_pc=0x0c03c5d0u; return 0; }
r[53]=fr[2];
goto P_0c03c5d2;
P_0c03c5d2: /* original feb1, guest PC 0x0c03c5d2 */
if(!s->budget--) { s->failed_pc=0x0c03c5d2u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[11],r[18],'-');
goto P_0c03c5d4;
P_0c03c5d4: /* original f28c, guest PC 0x0c03c5d4 */
if(!s->budget--) { s->failed_pc=0x0c03c5d4u; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c03c5d6;
P_0c03c5d6: /* original f331, guest PC 0x0c03c5d6 */
if(!s->budget--) { s->failed_pc=0x0c03c5d6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[3],r[18],'-');
goto P_0c03c5d8;
P_0c03c5d8: /* original f80d, guest PC 0x0c03c5d8 */
if(!s->budget--) { s->failed_pc=0x0c03c5d8u; return 0; }
fr[8]=r[53];
goto P_0c03c5da;
P_0c03c5da: /* original f771, guest PC 0x0c03c5da */
if(!s->budget--) { s->failed_pc=0x0c03c5dau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[7],r[18],'-');
goto P_0c03c5dc;
P_0c03c5dc: /* original f61d, guest PC 0x0c03c5dc */
if(!s->budget--) { s->failed_pc=0x0c03c5dcu; return 0; }
r[53]=fr[6];
goto P_0c03c5de;
P_0c03c5de: /* original fbb1, guest PC 0x0c03c5de */
if(!s->budget--) { s->failed_pc=0x0c03c5deu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'-');
goto P_0c03c5e0;
P_0c03c5e0: /* original f69c, guest PC 0x0c03c5e0 */
if(!s->budget--) { s->failed_pc=0x0c03c5e0u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c03c5e2;
P_0c03c5e2: /* original f90d, guest PC 0x0c03c5e2 */
if(!s->budget--) { s->failed_pc=0x0c03c5e2u; return 0; }
fr[9]=r[53];
goto P_0c03c5e4;
P_0c03c5e4: /* original fbfd, guest PC 0x0c03c5e4 */
if(!s->budget--) { s->failed_pc=0x0c03c5e4u; return 0; }
vf3_matrix_swap(s);
goto P_0c03c5e6;
P_0c03c5e6: /* original 0009, guest PC 0x0c03c5e6 */
if(!s->budget--) { s->failed_pc=0x0c03c5e6u; return 0; }
goto P_0c03c5e8;
P_0c03c5e8: /* original 000b, guest PC 0x0c03c5e8 */
if(!s->budget--) { s->failed_pc=0x0c03c5e8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03c5ea: /* original 0009, guest PC 0x0c03c5ea */
if(!s->budget--) { s->failed_pc=0x0c03c5eau; return 0; }
if(!vf3_matrix_family(0x0c03c5ecu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03c5ecu; return 0; } return 1;
P_0c09d42c: /* original 4f22, guest PC 0x0c09d42c */
if(!s->budget--) { s->failed_pc=0x0c09d42cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d42e;
P_0c09d42e: /* original e004, guest PC 0x0c09d42e */
if(!s->budget--) { s->failed_pc=0x0c09d42eu; return 0; }
r[0]=0x00000004u;
goto P_0c09d430;
P_0c09d430: /* original 7ff0, guest PC 0x0c09d430 */
if(!s->budget--) { s->failed_pc=0x0c09d430u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09d432;
P_0c09d432: /* original 2f42, guest PC 0x0c09d432 */
if(!s->budget--) { s->failed_pc=0x0c09d432u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09d434;
P_0c09d434: /* original 64f3, guest PC 0x0c09d434 */
if(!s->budget--) { s->failed_pc=0x0c09d434u; return 0; }
r[4]=r[15];
goto P_0c09d436;
P_0c09d436: /* original ff47, guest PC 0x0c09d436 */
if(!s->budget--) { s->failed_pc=0x0c09d436u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c09d438;
P_0c09d438: /* original e008, guest PC 0x0c09d438 */
if(!s->budget--) { s->failed_pc=0x0c09d438u; return 0; }
r[0]=0x00000008u;
goto P_0c09d43a;
P_0c09d43a: /* original f38d, guest PC 0x0c09d43a */
if(!s->budget--) { s->failed_pc=0x0c09d43au; return 0; }
fr[3]=0;
goto P_0c09d43c;
P_0c09d43c: /* original ff37, guest PC 0x0c09d43c */
if(!s->budget--) { s->failed_pc=0x0c09d43cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09d43e;
P_0c09d43e: /* original e00c, guest PC 0x0c09d43e */
if(!s->budget--) { s->failed_pc=0x0c09d43eu; return 0; }
r[0]=0x0000000cu;
goto P_0c09d440;
P_0c09d440: /* original ff57, guest PC 0x0c09d440 */
if(!s->budget--) { s->failed_pc=0x0c09d440u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c09d442;
P_0c09d442: /* original d34e, guest PC 0x0c09d442 */
if(!s->budget--) { s->failed_pc=0x0c09d442u; return 0; }
r[3]=read(ram,0x0c09d57cu,4);
goto P_0c09d444;
P_0c09d444: /* original 65f2, guest PC 0x0c09d444 */
if(!s->budget--) { s->failed_pc=0x0c09d444u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c09d446;
P_0c09d446: /* original 430b, guest PC 0x0c09d446 */
if(!s->budget--) { s->failed_pc=0x0c09d446u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d44au;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d44au) { target=s->pc; goto dispatch; }
goto P_0c09d44a;
P_0c09d448: /* original 7404, guest PC 0x0c09d448 */
if(!s->budget--) { s->failed_pc=0x0c09d448u; return 0; }
r[4]+=0x00000004u;
goto P_0c09d44a;
P_0c09d44a: /* original 7f10, guest PC 0x0c09d44a */
if(!s->budget--) { s->failed_pc=0x0c09d44au; return 0; }
r[15]+=0x00000010u;
goto P_0c09d44c;
P_0c09d44c: /* original 4f26, guest PC 0x0c09d44c */
if(!s->budget--) { s->failed_pc=0x0c09d44cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d44e;
P_0c09d44e: /* original 000b, guest PC 0x0c09d44e */
if(!s->budget--) { s->failed_pc=0x0c09d44eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09d450: /* original 0009, guest PC 0x0c09d450 */
if(!s->budget--) { s->failed_pc=0x0c09d450u; return 0; }
goto P_0c09d452;
P_0c09d452: /* original 4f22, guest PC 0x0c09d452 */
if(!s->budget--) { s->failed_pc=0x0c09d452u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d454;
P_0c09d454: /* original 6053, guest PC 0x0c09d454 */
if(!s->budget--) { s->failed_pc=0x0c09d454u; return 0; }
r[0]=r[5];
goto P_0c09d456;
P_0c09d456: /* original 7ff4, guest PC 0x0c09d456 */
if(!s->budget--) { s->failed_pc=0x0c09d456u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c09d458;
P_0c09d458: /* original 2f41, guest PC 0x0c09d458 */
if(!s->budget--) { s->failed_pc=0x0c09d458u; return 0; }
write(ram,r[15],r[4],2);
goto P_0c09d45a;
P_0c09d45a: /* original 81f2, guest PC 0x0c09d45a */
if(!s->budget--) { s->failed_pc=0x0c09d45au; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c09d45c;
P_0c09d45c: /* original 6063, guest PC 0x0c09d45c */
if(!s->budget--) { s->failed_pc=0x0c09d45cu; return 0; }
r[0]=r[6];
goto P_0c09d45e;
P_0c09d45e: /* original 81f4, guest PC 0x0c09d45e */
if(!s->budget--) { s->failed_pc=0x0c09d45eu; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c09d460;
P_0c09d460: /* original 85f4, guest PC 0x0c09d460 */
if(!s->budget--) { s->failed_pc=0x0c09d460u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c09d462;
P_0c09d462: /* original d347, guest PC 0x0c09d462 */
if(!s->budget--) { s->failed_pc=0x0c09d462u; return 0; }
r[3]=read(ram,0x0c09d580u,4);
goto P_0c09d464;
P_0c09d464: /* original 6403, guest PC 0x0c09d464 */
if(!s->budget--) { s->failed_pc=0x0c09d464u; return 0; }
r[4]=r[0];
goto P_0c09d466;
P_0c09d466: /* original 430b, guest PC 0x0c09d466 */
if(!s->budget--) { s->failed_pc=0x0c09d466u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d46au;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d46au) { target=s->pc; goto dispatch; }
goto P_0c09d46a;
P_0c09d468: /* original 644d, guest PC 0x0c09d468 */
if(!s->budget--) { s->failed_pc=0x0c09d468u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d46a;
P_0c09d46a: /* original 85f2, guest PC 0x0c09d46a */
if(!s->budget--) { s->failed_pc=0x0c09d46au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c09d46c;
P_0c09d46c: /* original d345, guest PC 0x0c09d46c */
if(!s->budget--) { s->failed_pc=0x0c09d46cu; return 0; }
r[3]=read(ram,0x0c09d584u,4);
goto P_0c09d46e;
P_0c09d46e: /* original 6403, guest PC 0x0c09d46e */
if(!s->budget--) { s->failed_pc=0x0c09d46eu; return 0; }
r[4]=r[0];
goto P_0c09d470;
P_0c09d470: /* original 430b, guest PC 0x0c09d470 */
if(!s->budget--) { s->failed_pc=0x0c09d470u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d474u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d474u) { target=s->pc; goto dispatch; }
goto P_0c09d474;
P_0c09d472: /* original 644d, guest PC 0x0c09d472 */
if(!s->budget--) { s->failed_pc=0x0c09d472u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d474;
P_0c09d474: /* original 64f1, guest PC 0x0c09d474 */
if(!s->budget--) { s->failed_pc=0x0c09d474u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c09d476;
P_0c09d476: /* original 7f0c, guest PC 0x0c09d476 */
if(!s->budget--) { s->failed_pc=0x0c09d476u; return 0; }
r[15]+=0x0000000cu;
goto P_0c09d478;
P_0c09d478: /* original d343, guest PC 0x0c09d478 */
if(!s->budget--) { s->failed_pc=0x0c09d478u; return 0; }
r[3]=read(ram,0x0c09d588u,4);
goto P_0c09d47a;
P_0c09d47a: /* original 644d, guest PC 0x0c09d47a */
if(!s->budget--) { s->failed_pc=0x0c09d47au; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d47c;
P_0c09d47c: /* original 432b, guest PC 0x0c09d47c */
if(!s->budget--) { s->failed_pc=0x0c09d47cu; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c09d47e: /* original 4f26, guest PC 0x0c09d47e */
if(!s->budget--) { s->failed_pc=0x0c09d47eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d480;
P_0c09d480: /* original 4f22, guest PC 0x0c09d480 */
if(!s->budget--) { s->failed_pc=0x0c09d480u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d482;
P_0c09d482: /* original 6041, guest PC 0x0c09d482 */
if(!s->budget--) { s->failed_pc=0x0c09d482u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
goto P_0c09d484;
P_0c09d484: /* original 7ff4, guest PC 0x0c09d484 */
if(!s->budget--) { s->failed_pc=0x0c09d484u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c09d486;
P_0c09d486: /* original 81f4, guest PC 0x0c09d486 */
if(!s->budget--) { s->failed_pc=0x0c09d486u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c09d488;
P_0c09d488: /* original 8541, guest PC 0x0c09d488 */
if(!s->budget--) { s->failed_pc=0x0c09d488u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c09d48a;
P_0c09d48a: /* original 81f2, guest PC 0x0c09d48a */
if(!s->budget--) { s->failed_pc=0x0c09d48au; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c09d48c;
P_0c09d48c: /* original 8542, guest PC 0x0c09d48c */
if(!s->budget--) { s->failed_pc=0x0c09d48cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+4,2);
goto P_0c09d48e;
P_0c09d48e: /* original 2f01, guest PC 0x0c09d48e */
if(!s->budget--) { s->failed_pc=0x0c09d48eu; return 0; }
write(ram,r[15],r[0],2);
goto P_0c09d490;
P_0c09d490: /* original 85f4, guest PC 0x0c09d490 */
if(!s->budget--) { s->failed_pc=0x0c09d490u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c09d492;
P_0c09d492: /* original d33b, guest PC 0x0c09d492 */
if(!s->budget--) { s->failed_pc=0x0c09d492u; return 0; }
r[3]=read(ram,0x0c09d580u,4);
goto P_0c09d494;
P_0c09d494: /* original 6403, guest PC 0x0c09d494 */
if(!s->budget--) { s->failed_pc=0x0c09d494u; return 0; }
r[4]=r[0];
goto P_0c09d496;
P_0c09d496: /* original 430b, guest PC 0x0c09d496 */
if(!s->budget--) { s->failed_pc=0x0c09d496u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d49au;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d49au) { target=s->pc; goto dispatch; }
goto P_0c09d49a;
P_0c09d498: /* original 644d, guest PC 0x0c09d498 */
if(!s->budget--) { s->failed_pc=0x0c09d498u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d49a;
P_0c09d49a: /* original 85f2, guest PC 0x0c09d49a */
if(!s->budget--) { s->failed_pc=0x0c09d49au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c09d49c;
P_0c09d49c: /* original d339, guest PC 0x0c09d49c */
if(!s->budget--) { s->failed_pc=0x0c09d49cu; return 0; }
r[3]=read(ram,0x0c09d584u,4);
goto P_0c09d49e;
P_0c09d49e: /* original 6403, guest PC 0x0c09d49e */
if(!s->budget--) { s->failed_pc=0x0c09d49eu; return 0; }
r[4]=r[0];
goto P_0c09d4a0;
P_0c09d4a0: /* original 430b, guest PC 0x0c09d4a0 */
if(!s->budget--) { s->failed_pc=0x0c09d4a0u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d4a4u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d4a4u) { target=s->pc; goto dispatch; }
goto P_0c09d4a4;
P_0c09d4a2: /* original 644d, guest PC 0x0c09d4a2 */
if(!s->budget--) { s->failed_pc=0x0c09d4a2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d4a4;
P_0c09d4a4: /* original 64f1, guest PC 0x0c09d4a4 */
if(!s->budget--) { s->failed_pc=0x0c09d4a4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c09d4a6;
P_0c09d4a6: /* original 7f0c, guest PC 0x0c09d4a6 */
if(!s->budget--) { s->failed_pc=0x0c09d4a6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c09d4a8;
P_0c09d4a8: /* original d337, guest PC 0x0c09d4a8 */
if(!s->budget--) { s->failed_pc=0x0c09d4a8u; return 0; }
r[3]=read(ram,0x0c09d588u,4);
goto P_0c09d4aa;
P_0c09d4aa: /* original 644d, guest PC 0x0c09d4aa */
if(!s->budget--) { s->failed_pc=0x0c09d4aau; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d4ac;
P_0c09d4ac: /* original 432b, guest PC 0x0c09d4ac */
if(!s->budget--) { s->failed_pc=0x0c09d4acu; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c09d4ae: /* original 4f26, guest PC 0x0c09d4ae */
if(!s->budget--) { s->failed_pc=0x0c09d4aeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d4b0;
P_0c09d4b0: /* original 4f22, guest PC 0x0c09d4b0 */
if(!s->budget--) { s->failed_pc=0x0c09d4b0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d4b2;
P_0c09d4b2: /* original 7ff0, guest PC 0x0c09d4b2 */
if(!s->budget--) { s->failed_pc=0x0c09d4b2u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09d4b4;
P_0c09d4b4: /* original 2f51, guest PC 0x0c09d4b4 */
if(!s->budget--) { s->failed_pc=0x0c09d4b4u; return 0; }
write(ram,r[15],r[5],2);
goto P_0c09d4b6;
P_0c09d4b6: /* original 6041, guest PC 0x0c09d4b6 */
if(!s->budget--) { s->failed_pc=0x0c09d4b6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
goto P_0c09d4b8;
P_0c09d4b8: /* original 81f4, guest PC 0x0c09d4b8 */
if(!s->budget--) { s->failed_pc=0x0c09d4b8u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c09d4ba;
P_0c09d4ba: /* original 8541, guest PC 0x0c09d4ba */
if(!s->budget--) { s->failed_pc=0x0c09d4bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c09d4bc;
P_0c09d4bc: /* original 81f2, guest PC 0x0c09d4bc */
if(!s->budget--) { s->failed_pc=0x0c09d4bcu; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c09d4be;
P_0c09d4be: /* original 8542, guest PC 0x0c09d4be */
if(!s->budget--) { s->failed_pc=0x0c09d4beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+4,2);
goto P_0c09d4c0;
P_0c09d4c0: /* original 81f6, guest PC 0x0c09d4c0 */
if(!s->budget--) { s->failed_pc=0x0c09d4c0u; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c09d4c2;
P_0c09d4c2: /* original 85f4, guest PC 0x0c09d4c2 */
if(!s->budget--) { s->failed_pc=0x0c09d4c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c09d4c4;
P_0c09d4c4: /* original d32e, guest PC 0x0c09d4c4 */
if(!s->budget--) { s->failed_pc=0x0c09d4c4u; return 0; }
r[3]=read(ram,0x0c09d580u,4);
goto P_0c09d4c6;
P_0c09d4c6: /* original 6403, guest PC 0x0c09d4c6 */
if(!s->budget--) { s->failed_pc=0x0c09d4c6u; return 0; }
r[4]=r[0];
goto P_0c09d4c8;
P_0c09d4c8: /* original 430b, guest PC 0x0c09d4c8 */
if(!s->budget--) { s->failed_pc=0x0c09d4c8u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d4ccu;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d4ccu) { target=s->pc; goto dispatch; }
goto P_0c09d4cc;
P_0c09d4ca: /* original 644d, guest PC 0x0c09d4ca */
if(!s->budget--) { s->failed_pc=0x0c09d4cau; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d4cc;
P_0c09d4cc: /* original 85f2, guest PC 0x0c09d4cc */
if(!s->budget--) { s->failed_pc=0x0c09d4ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c09d4ce;
P_0c09d4ce: /* original 64f1, guest PC 0x0c09d4ce */
if(!s->budget--) { s->failed_pc=0x0c09d4ceu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c09d4d0;
P_0c09d4d0: /* original d32c, guest PC 0x0c09d4d0 */
if(!s->budget--) { s->failed_pc=0x0c09d4d0u; return 0; }
r[3]=read(ram,0x0c09d584u,4);
goto P_0c09d4d2;
P_0c09d4d2: /* original 600d, guest PC 0x0c09d4d2 */
if(!s->budget--) { s->failed_pc=0x0c09d4d2u; return 0; }
r[0]=r[0]&65535u;
goto P_0c09d4d4;
P_0c09d4d4: /* original 430b, guest PC 0x0c09d4d4 */
if(!s->budget--) { s->failed_pc=0x0c09d4d4u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d4d8u;
r[4]+=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d4d8u) { target=s->pc; goto dispatch; }
goto P_0c09d4d8;
P_0c09d4d6: /* original 340c, guest PC 0x0c09d4d6 */
if(!s->budget--) { s->failed_pc=0x0c09d4d6u; return 0; }
r[4]+=r[0];
goto P_0c09d4d8;
P_0c09d4d8: /* original 85f6, guest PC 0x0c09d4d8 */
if(!s->budget--) { s->failed_pc=0x0c09d4d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c09d4da;
P_0c09d4da: /* original 7f10, guest PC 0x0c09d4da */
if(!s->budget--) { s->failed_pc=0x0c09d4dau; return 0; }
r[15]+=0x00000010u;
goto P_0c09d4dc;
P_0c09d4dc: /* original d32a, guest PC 0x0c09d4dc */
if(!s->budget--) { s->failed_pc=0x0c09d4dcu; return 0; }
r[3]=read(ram,0x0c09d588u,4);
goto P_0c09d4de;
P_0c09d4de: /* original 6403, guest PC 0x0c09d4de */
if(!s->budget--) { s->failed_pc=0x0c09d4deu; return 0; }
r[4]=r[0];
goto P_0c09d4e0;
P_0c09d4e0: /* original 644d, guest PC 0x0c09d4e0 */
if(!s->budget--) { s->failed_pc=0x0c09d4e0u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d4e2;
P_0c09d4e2: /* original 432b, guest PC 0x0c09d4e2 */
if(!s->budget--) { s->failed_pc=0x0c09d4e2u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c09d4e4: /* original 4f26, guest PC 0x0c09d4e4 */
if(!s->budget--) { s->failed_pc=0x0c09d4e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d4e6;
P_0c09d4e6: /* original 2fe6, guest PC 0x0c09d4e6 */
if(!s->budget--) { s->failed_pc=0x0c09d4e6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d4e8;
P_0c09d4e8: /* original e030, guest PC 0x0c09d4e8 */
if(!s->budget--) { s->failed_pc=0x0c09d4e8u; return 0; }
r[0]=0x00000030u;
goto P_0c09d4ea;
P_0c09d4ea: /* original 2fd6, guest PC 0x0c09d4ea */
if(!s->budget--) { s->failed_pc=0x0c09d4eau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d4ec;
P_0c09d4ec: /* original 6e43, guest PC 0x0c09d4ec */
if(!s->budget--) { s->failed_pc=0x0c09d4ecu; return 0; }
r[14]=r[4];
goto P_0c09d4ee;
P_0c09d4ee: /* original 4f22, guest PC 0x0c09d4ee */
if(!s->budget--) { s->failed_pc=0x0c09d4eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d4f0;
P_0c09d4f0: /* original f3e6, guest PC 0x0c09d4f0 */
if(!s->budget--) { s->failed_pc=0x0c09d4f0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09d4f2;
P_0c09d4f2: /* original e034, guest PC 0x0c09d4f2 */
if(!s->budget--) { s->failed_pc=0x0c09d4f2u; return 0; }
r[0]=0x00000034u;
goto P_0c09d4f4;
P_0c09d4f4: /* original 7ff4, guest PC 0x0c09d4f4 */
if(!s->budget--) { s->failed_pc=0x0c09d4f4u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c09d4f6;
P_0c09d4f6: /* original 6df3, guest PC 0x0c09d4f6 */
if(!s->budget--) { s->failed_pc=0x0c09d4f6u; return 0; }
r[13]=r[15];
goto P_0c09d4f8;
P_0c09d4f8: /* original fd3a, guest PC 0x0c09d4f8 */
if(!s->budget--) { s->failed_pc=0x0c09d4f8u; return 0; }
vf3_matrix_store(s,ram,3,r[13]);
goto P_0c09d4fa;
P_0c09d4fa: /* original f3e6, guest PC 0x0c09d4fa */
if(!s->budget--) { s->failed_pc=0x0c09d4fau; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09d4fc;
P_0c09d4fc: /* original e004, guest PC 0x0c09d4fc */
if(!s->budget--) { s->failed_pc=0x0c09d4fcu; return 0; }
r[0]=0x00000004u;
goto P_0c09d4fe;
P_0c09d4fe: /* original fd37, guest PC 0x0c09d4fe */
if(!s->budget--) { s->failed_pc=0x0c09d4feu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09d500;
P_0c09d500: /* original e038, guest PC 0x0c09d500 */
if(!s->budget--) { s->failed_pc=0x0c09d500u; return 0; }
r[0]=0x00000038u;
goto P_0c09d502;
P_0c09d502: /* original f3e6, guest PC 0x0c09d502 */
if(!s->budget--) { s->failed_pc=0x0c09d502u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09d504;
P_0c09d504: /* original e008, guest PC 0x0c09d504 */
if(!s->budget--) { s->failed_pc=0x0c09d504u; return 0; }
r[0]=0x00000008u;
goto P_0c09d506;
P_0c09d506: /* original fd37, guest PC 0x0c09d506 */
if(!s->budget--) { s->failed_pc=0x0c09d506u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09d508;
P_0c09d508: /* original d320, guest PC 0x0c09d508 */
if(!s->budget--) { s->failed_pc=0x0c09d508u; return 0; }
r[3]=read(ram,0x0c09d58cu,4);
goto P_0c09d50a;
P_0c09d50a: /* original 430b, guest PC 0x0c09d50a */
if(!s->budget--) { s->failed_pc=0x0c09d50au; return 0; }
target=r[3];
r[16]=code_base|0x0c09d50eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d50eu) { target=s->pc; goto dispatch; }
goto P_0c09d50e;
P_0c09d50c: /* original 64e3, guest PC 0x0c09d50c */
if(!s->budget--) { s->failed_pc=0x0c09d50cu; return 0; }
r[4]=r[14];
goto P_0c09d50e;
P_0c09d50e: /* original f3d8, guest PC 0x0c09d50e */
if(!s->budget--) { s->failed_pc=0x0c09d50eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c09d510;
P_0c09d510: /* original e030, guest PC 0x0c09d510 */
if(!s->budget--) { s->failed_pc=0x0c09d510u; return 0; }
r[0]=0x00000030u;
goto P_0c09d512;
P_0c09d512: /* original 7f0c, guest PC 0x0c09d512 */
if(!s->budget--) { s->failed_pc=0x0c09d512u; return 0; }
r[15]+=0x0000000cu;
goto P_0c09d514;
P_0c09d514: /* original fe37, guest PC 0x0c09d514 */
if(!s->budget--) { s->failed_pc=0x0c09d514u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09d516;
P_0c09d516: /* original e004, guest PC 0x0c09d516 */
if(!s->budget--) { s->failed_pc=0x0c09d516u; return 0; }
r[0]=0x00000004u;
goto P_0c09d518;
P_0c09d518: /* original f3d6, guest PC 0x0c09d518 */
if(!s->budget--) { s->failed_pc=0x0c09d518u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c09d51a;
P_0c09d51a: /* original e034, guest PC 0x0c09d51a */
if(!s->budget--) { s->failed_pc=0x0c09d51au; return 0; }
r[0]=0x00000034u;
goto P_0c09d51c;
P_0c09d51c: /* original 4f26, guest PC 0x0c09d51c */
if(!s->budget--) { s->failed_pc=0x0c09d51cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d51e;
P_0c09d51e: /* original fe37, guest PC 0x0c09d51e */
if(!s->budget--) { s->failed_pc=0x0c09d51eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09d520;
P_0c09d520: /* original e008, guest PC 0x0c09d520 */
if(!s->budget--) { s->failed_pc=0x0c09d520u; return 0; }
r[0]=0x00000008u;
goto P_0c09d522;
P_0c09d522: /* original f3d6, guest PC 0x0c09d522 */
if(!s->budget--) { s->failed_pc=0x0c09d522u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c09d524;
P_0c09d524: /* original e038, guest PC 0x0c09d524 */
if(!s->budget--) { s->failed_pc=0x0c09d524u; return 0; }
r[0]=0x00000038u;
goto P_0c09d526;
P_0c09d526: /* original fe37, guest PC 0x0c09d526 */
if(!s->budget--) { s->failed_pc=0x0c09d526u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09d528;
P_0c09d528: /* original 6df6, guest PC 0x0c09d528 */
if(!s->budget--) { s->failed_pc=0x0c09d528u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09d52a;
P_0c09d52a: /* original 000b, guest PC 0x0c09d52a */
if(!s->budget--) { s->failed_pc=0x0c09d52au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09d52c: /* original 6ef6, guest PC 0x0c09d52c */
if(!s->budget--) { s->failed_pc=0x0c09d52cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09d52e;
P_0c09d52e: /* original 4f22, guest PC 0x0c09d52e */
if(!s->budget--) { s->failed_pc=0x0c09d52eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d530;
P_0c09d530: /* original e004, guest PC 0x0c09d530 */
if(!s->budget--) { s->failed_pc=0x0c09d530u; return 0; }
r[0]=0x00000004u;
goto P_0c09d532;
P_0c09d532: /* original 7ff0, guest PC 0x0c09d532 */
if(!s->budget--) { s->failed_pc=0x0c09d532u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09d534;
P_0c09d534: /* original 2f42, guest PC 0x0c09d534 */
if(!s->budget--) { s->failed_pc=0x0c09d534u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09d536;
P_0c09d536: /* original 64f3, guest PC 0x0c09d536 */
if(!s->budget--) { s->failed_pc=0x0c09d536u; return 0; }
r[4]=r[15];
goto P_0c09d538;
P_0c09d538: /* original ff47, guest PC 0x0c09d538 */
if(!s->budget--) { s->failed_pc=0x0c09d538u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c09d53a;
P_0c09d53a: /* original e008, guest PC 0x0c09d53a */
if(!s->budget--) { s->failed_pc=0x0c09d53au; return 0; }
r[0]=0x00000008u;
goto P_0c09d53c;
P_0c09d53c: /* original f48d, guest PC 0x0c09d53c */
if(!s->budget--) { s->failed_pc=0x0c09d53cu; return 0; }
fr[4]=0;
goto P_0c09d53e;
P_0c09d53e: /* original ff47, guest PC 0x0c09d53e */
if(!s->budget--) { s->failed_pc=0x0c09d53eu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c09d540;
P_0c09d540: /* original e00c, guest PC 0x0c09d540 */
if(!s->budget--) { s->failed_pc=0x0c09d540u; return 0; }
r[0]=0x0000000cu;
goto P_0c09d542;
P_0c09d542: /* original ff47, guest PC 0x0c09d542 */
if(!s->budget--) { s->failed_pc=0x0c09d542u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c09d544;
P_0c09d544: /* original d30d, guest PC 0x0c09d544 */
if(!s->budget--) { s->failed_pc=0x0c09d544u; return 0; }
r[3]=read(ram,0x0c09d57cu,4);
goto P_0c09d546;
P_0c09d546: /* original 65f2, guest PC 0x0c09d546 */
if(!s->budget--) { s->failed_pc=0x0c09d546u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c09d548;
P_0c09d548: /* original 430b, guest PC 0x0c09d548 */
if(!s->budget--) { s->failed_pc=0x0c09d548u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d54cu;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d54cu) { target=s->pc; goto dispatch; }
goto P_0c09d54c;
P_0c09d54a: /* original 7404, guest PC 0x0c09d54a */
if(!s->budget--) { s->failed_pc=0x0c09d54au; return 0; }
r[4]+=0x00000004u;
goto P_0c09d54c;
P_0c09d54c: /* original 7f10, guest PC 0x0c09d54c */
if(!s->budget--) { s->failed_pc=0x0c09d54cu; return 0; }
r[15]+=0x00000010u;
goto P_0c09d54e;
P_0c09d54e: /* original 4f26, guest PC 0x0c09d54e */
if(!s->budget--) { s->failed_pc=0x0c09d54eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d550;
P_0c09d550: /* original 000b, guest PC 0x0c09d550 */
if(!s->budget--) { s->failed_pc=0x0c09d550u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09d552: /* original 0009, guest PC 0x0c09d552 */
if(!s->budget--) { s->failed_pc=0x0c09d552u; return 0; }
goto P_0c09d554;
P_0c09d554: /* original 4f22, guest PC 0x0c09d554 */
if(!s->budget--) { s->failed_pc=0x0c09d554u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d556;
P_0c09d556: /* original e004, guest PC 0x0c09d556 */
if(!s->budget--) { s->failed_pc=0x0c09d556u; return 0; }
r[0]=0x00000004u;
goto P_0c09d558;
P_0c09d558: /* original 7ff0, guest PC 0x0c09d558 */
if(!s->budget--) { s->failed_pc=0x0c09d558u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09d55a;
P_0c09d55a: /* original 2f42, guest PC 0x0c09d55a */
if(!s->budget--) { s->failed_pc=0x0c09d55au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09d55c;
P_0c09d55c: /* original 64f3, guest PC 0x0c09d55c */
if(!s->budget--) { s->failed_pc=0x0c09d55cu; return 0; }
r[4]=r[15];
goto P_0c09d55e;
P_0c09d55e: /* original f58d, guest PC 0x0c09d55e */
if(!s->budget--) { s->failed_pc=0x0c09d55eu; return 0; }
fr[5]=0;
goto P_0c09d560;
P_0c09d560: /* original ff57, guest PC 0x0c09d560 */
if(!s->budget--) { s->failed_pc=0x0c09d560u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c09d562;
P_0c09d562: /* original e008, guest PC 0x0c09d562 */
if(!s->budget--) { s->failed_pc=0x0c09d562u; return 0; }
r[0]=0x00000008u;
goto P_0c09d564;
P_0c09d564: /* original ff47, guest PC 0x0c09d564 */
if(!s->budget--) { s->failed_pc=0x0c09d564u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c09d566;
P_0c09d566: /* original e00c, guest PC 0x0c09d566 */
if(!s->budget--) { s->failed_pc=0x0c09d566u; return 0; }
r[0]=0x0000000cu;
goto P_0c09d568;
P_0c09d568: /* original ff57, guest PC 0x0c09d568 */
if(!s->budget--) { s->failed_pc=0x0c09d568u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c09d56a;
P_0c09d56a: /* original d304, guest PC 0x0c09d56a */
if(!s->budget--) { s->failed_pc=0x0c09d56au; return 0; }
r[3]=read(ram,0x0c09d57cu,4);
goto P_0c09d56c;
P_0c09d56c: /* original 65f2, guest PC 0x0c09d56c */
if(!s->budget--) { s->failed_pc=0x0c09d56cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c09d56e;
P_0c09d56e: /* original 430b, guest PC 0x0c09d56e */
if(!s->budget--) { s->failed_pc=0x0c09d56eu; return 0; }
target=r[3];
r[16]=code_base|0x0c09d572u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d572u) { target=s->pc; goto dispatch; }
goto P_0c09d572;
P_0c09d570: /* original 7404, guest PC 0x0c09d570 */
if(!s->budget--) { s->failed_pc=0x0c09d570u; return 0; }
r[4]+=0x00000004u;
goto P_0c09d572;
P_0c09d572: /* original 7f10, guest PC 0x0c09d572 */
if(!s->budget--) { s->failed_pc=0x0c09d572u; return 0; }
r[15]+=0x00000010u;
goto P_0c09d574;
P_0c09d574: /* original 4f26, guest PC 0x0c09d574 */
if(!s->budget--) { s->failed_pc=0x0c09d574u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d576;
P_0c09d576: /* original 000b, guest PC 0x0c09d576 */
if(!s->budget--) { s->failed_pc=0x0c09d576u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09d578: /* original 0009, guest PC 0x0c09d578 */
if(!s->budget--) { s->failed_pc=0x0c09d578u; return 0; }
if(!vf3_matrix_family(0x0c09d57au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09d57au; return 0; } return 1;
P_0c09d9ea: /* original 2fe6, guest PC 0x0c09d9ea */
if(!s->budget--) { s->failed_pc=0x0c09d9eau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d9ec;
P_0c09d9ec: /* original 4f22, guest PC 0x0c09d9ec */
if(!s->budget--) { s->failed_pc=0x0c09d9ecu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d9ee;
P_0c09d9ee: /* original d33a, guest PC 0x0c09d9ee */
if(!s->budget--) { s->failed_pc=0x0c09d9eeu; return 0; }
r[3]=read(ram,0x0c09dad8u,4);
goto P_0c09d9f0;
P_0c09d9f0: /* original 430b, guest PC 0x0c09d9f0 */
if(!s->budget--) { s->failed_pc=0x0c09d9f0u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d9f4u;
r[14]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d9f4u) { target=s->pc; goto dispatch; }
goto P_0c09d9f4;
P_0c09d9f2: /* original 6e43, guest PC 0x0c09d9f2 */
if(!s->budget--) { s->failed_pc=0x0c09d9f2u; return 0; }
r[14]=r[4];
goto P_0c09d9f4;
P_0c09d9f4: /* original d339, guest PC 0x0c09d9f4 */
if(!s->budget--) { s->failed_pc=0x0c09d9f4u; return 0; }
r[3]=read(ram,0x0c09dadcu,4);
goto P_0c09d9f6;
P_0c09d9f6: /* original 85ef, guest PC 0x0c09d9f6 */
if(!s->budget--) { s->failed_pc=0x0c09d9f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c09d9f8;
P_0c09d9f8: /* original 430b, guest PC 0x0c09d9f8 */
if(!s->budget--) { s->failed_pc=0x0c09d9f8u; return 0; }
target=r[3];
r[16]=code_base|0x0c09d9fcu;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d9fcu) { target=s->pc; goto dispatch; }
goto P_0c09d9fc;
P_0c09d9fa: /* original 6403, guest PC 0x0c09d9fa */
if(!s->budget--) { s->failed_pc=0x0c09d9fau; return 0; }
r[4]=r[0];
goto P_0c09d9fc;
P_0c09d9fc: /* original 9066, guest PC 0x0c09d9fc */
if(!s->budget--) { s->failed_pc=0x0c09d9fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09daccu,2);
goto P_0c09d9fe;
P_0c09d9fe: /* original d338, guest PC 0x0c09d9fe */
if(!s->budget--) { s->failed_pc=0x0c09d9feu; return 0; }
r[3]=read(ram,0x0c09dae0u,4);
goto P_0c09da00;
P_0c09da00: /* original 04ed, guest PC 0x0c09da00 */
if(!s->budget--) { s->failed_pc=0x0c09da00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09da02;
P_0c09da02: /* original 430b, guest PC 0x0c09da02 */
if(!s->budget--) { s->failed_pc=0x0c09da02u; return 0; }
target=r[3];
r[16]=code_base|0x0c09da06u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09da06u) { target=s->pc; goto dispatch; }
goto P_0c09da06;
P_0c09da04: /* original 644d, guest PC 0x0c09da04 */
if(!s->budget--) { s->failed_pc=0x0c09da04u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09da06;
P_0c09da06: /* original 9062, guest PC 0x0c09da06 */
if(!s->budget--) { s->failed_pc=0x0c09da06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09daceu,2);
goto P_0c09da08;
P_0c09da08: /* original d334, guest PC 0x0c09da08 */
if(!s->budget--) { s->failed_pc=0x0c09da08u; return 0; }
r[3]=read(ram,0x0c09dadcu,4);
goto P_0c09da0a;
P_0c09da0a: /* original 04ed, guest PC 0x0c09da0a */
if(!s->budget--) { s->failed_pc=0x0c09da0au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09da0c;
P_0c09da0c: /* original 430b, guest PC 0x0c09da0c */
if(!s->budget--) { s->failed_pc=0x0c09da0cu; return 0; }
target=r[3];
r[16]=code_base|0x0c09da10u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09da10u) { target=s->pc; goto dispatch; }
goto P_0c09da10;
P_0c09da0e: /* original 644d, guest PC 0x0c09da0e */
if(!s->budget--) { s->failed_pc=0x0c09da0eu; return 0; }
r[4]=r[4]&65535u;
goto P_0c09da10;
P_0c09da10: /* original 905e, guest PC 0x0c09da10 */
if(!s->budget--) { s->failed_pc=0x0c09da10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dad0u,2);
goto P_0c09da12;
P_0c09da12: /* original 4f26, guest PC 0x0c09da12 */
if(!s->budget--) { s->failed_pc=0x0c09da12u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09da14;
P_0c09da14: /* original 04ed, guest PC 0x0c09da14 */
if(!s->budget--) { s->failed_pc=0x0c09da14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09da16;
P_0c09da16: /* original d333, guest PC 0x0c09da16 */
if(!s->budget--) { s->failed_pc=0x0c09da16u; return 0; }
r[3]=read(ram,0x0c09dae4u,4);
goto P_0c09da18;
P_0c09da18: /* original 644d, guest PC 0x0c09da18 */
if(!s->budget--) { s->failed_pc=0x0c09da18u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09da1a;
P_0c09da1a: /* original 432b, guest PC 0x0c09da1a */
if(!s->budget--) { s->failed_pc=0x0c09da1au; return 0; }
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
P_0c09da1c: /* original 6ef6, guest PC 0x0c09da1c */
if(!s->budget--) { s->failed_pc=0x0c09da1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09da1e;
P_0c09da1e: /* original 2fe6, guest PC 0x0c09da1e */
if(!s->budget--) { s->failed_pc=0x0c09da1eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09da20;
P_0c09da20: /* original 6e43, guest PC 0x0c09da20 */
if(!s->budget--) { s->failed_pc=0x0c09da20u; return 0; }
r[14]=r[4];
goto P_0c09da22;
P_0c09da22: /* original 4f22, guest PC 0x0c09da22 */
if(!s->budget--) { s->failed_pc=0x0c09da22u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09da24;
P_0c09da24: /* original 7ff0, guest PC 0x0c09da24 */
if(!s->budget--) { s->failed_pc=0x0c09da24u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09da26;
P_0c09da26: /* original 64f3, guest PC 0x0c09da26 */
if(!s->budget--) { s->failed_pc=0x0c09da26u; return 0; }
r[4]=r[15];
goto P_0c09da28;
P_0c09da28: /* original 2f52, guest PC 0x0c09da28 */
if(!s->budget--) { s->failed_pc=0x0c09da28u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c09da2a;
P_0c09da2a: /* original d32f, guest PC 0x0c09da2a */
if(!s->budget--) { s->failed_pc=0x0c09da2au; return 0; }
r[3]=read(ram,0x0c09dae8u,4);
goto P_0c09da2c;
P_0c09da2c: /* original 430b, guest PC 0x0c09da2c */
if(!s->budget--) { s->failed_pc=0x0c09da2cu; return 0; }
target=r[3];
r[16]=code_base|0x0c09da30u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09da30u) { target=s->pc; goto dispatch; }
goto P_0c09da30;
P_0c09da2e: /* original 7404, guest PC 0x0c09da2e */
if(!s->budget--) { s->failed_pc=0x0c09da2eu; return 0; }
r[4]+=0x00000004u;
goto P_0c09da30;
P_0c09da30: /* original d229, guest PC 0x0c09da30 */
if(!s->budget--) { s->failed_pc=0x0c09da30u; return 0; }
r[2]=read(ram,0x0c09dad8u,4);
goto P_0c09da32;
P_0c09da32: /* original 420b, guest PC 0x0c09da32 */
if(!s->budget--) { s->failed_pc=0x0c09da32u; return 0; }
target=r[2];
r[16]=code_base|0x0c09da36u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09da36u) { target=s->pc; goto dispatch; }
goto P_0c09da36;
P_0c09da34: /* original 0009, guest PC 0x0c09da34 */
if(!s->budget--) { s->failed_pc=0x0c09da34u; return 0; }
goto P_0c09da36;
P_0c09da36: /* original 64f2, guest PC 0x0c09da36 */
if(!s->budget--) { s->failed_pc=0x0c09da36u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c09da38;
P_0c09da38: /* original d328, guest PC 0x0c09da38 */
if(!s->budget--) { s->failed_pc=0x0c09da38u; return 0; }
r[3]=read(ram,0x0c09dadcu,4);
goto P_0c09da3a;
P_0c09da3a: /* original 854f, guest PC 0x0c09da3a */
if(!s->budget--) { s->failed_pc=0x0c09da3au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+30,2);
goto P_0c09da3c;
P_0c09da3c: /* original 430b, guest PC 0x0c09da3c */
if(!s->budget--) { s->failed_pc=0x0c09da3cu; return 0; }
target=r[3];
r[16]=code_base|0x0c09da40u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09da40u) { target=s->pc; goto dispatch; }
goto P_0c09da40;
P_0c09da3e: /* original 6403, guest PC 0x0c09da3e */
if(!s->budget--) { s->failed_pc=0x0c09da3eu; return 0; }
r[4]=r[0];
goto P_0c09da40;
P_0c09da40: /* original d227, guest PC 0x0c09da40 */
if(!s->budget--) { s->failed_pc=0x0c09da40u; return 0; }
r[2]=read(ram,0x0c09dae0u,4);
goto P_0c09da42;
P_0c09da42: /* original 64e1, guest PC 0x0c09da42 */
if(!s->budget--) { s->failed_pc=0x0c09da42u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[4]=tmp;
goto P_0c09da44;
P_0c09da44: /* original 420b, guest PC 0x0c09da44 */
if(!s->budget--) { s->failed_pc=0x0c09da44u; return 0; }
target=r[2];
r[16]=code_base|0x0c09da48u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09da48u) { target=s->pc; goto dispatch; }
goto P_0c09da48;
P_0c09da46: /* original 644d, guest PC 0x0c09da46 */
if(!s->budget--) { s->failed_pc=0x0c09da46u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09da48;
P_0c09da48: /* original d324, guest PC 0x0c09da48 */
if(!s->budget--) { s->failed_pc=0x0c09da48u; return 0; }
r[3]=read(ram,0x0c09dadcu,4);
goto P_0c09da4a;
P_0c09da4a: /* original 85e1, guest PC 0x0c09da4a */
if(!s->budget--) { s->failed_pc=0x0c09da4au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c09da4c;
P_0c09da4c: /* original 430b, guest PC 0x0c09da4c */
if(!s->budget--) { s->failed_pc=0x0c09da4cu; return 0; }
target=r[3];
r[16]=code_base|0x0c09da50u;
r[4]=r[0]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09da50u) { target=s->pc; goto dispatch; }
goto P_0c09da50;
P_0c09da4e: /* original 640d, guest PC 0x0c09da4e */
if(!s->budget--) { s->failed_pc=0x0c09da4eu; return 0; }
r[4]=r[0]&65535u;
goto P_0c09da50;
P_0c09da50: /* original 64f2, guest PC 0x0c09da50 */
if(!s->budget--) { s->failed_pc=0x0c09da50u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c09da52;
P_0c09da52: /* original 923e, guest PC 0x0c09da52 */
if(!s->budget--) { s->failed_pc=0x0c09da52u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dad2u,2);
goto P_0c09da54;
P_0c09da54: /* original 85e2, guest PC 0x0c09da54 */
if(!s->budget--) { s->failed_pc=0x0c09da54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+4,2);
goto P_0c09da56;
P_0c09da56: /* original 324c, guest PC 0x0c09da56 */
if(!s->budget--) { s->failed_pc=0x0c09da56u; return 0; }
r[2]+=r[4];
goto P_0c09da58;
P_0c09da58: /* original d322, guest PC 0x0c09da58 */
if(!s->budget--) { s->failed_pc=0x0c09da58u; return 0; }
r[3]=read(ram,0x0c09dae4u,4);
goto P_0c09da5a;
P_0c09da5a: /* original 6421, guest PC 0x0c09da5a */
if(!s->budget--) { s->failed_pc=0x0c09da5au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[4]=tmp;
goto P_0c09da5c;
P_0c09da5c: /* original 600d, guest PC 0x0c09da5c */
if(!s->budget--) { s->failed_pc=0x0c09da5cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c09da5e;
P_0c09da5e: /* original 430b, guest PC 0x0c09da5e */
if(!s->budget--) { s->failed_pc=0x0c09da5eu; return 0; }
target=r[3];
r[16]=code_base|0x0c09da62u;
r[4]+=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09da62u) { target=s->pc; goto dispatch; }
goto P_0c09da62;
P_0c09da60: /* original 340c, guest PC 0x0c09da60 */
if(!s->budget--) { s->failed_pc=0x0c09da60u; return 0; }
r[4]+=r[0];
goto P_0c09da62;
P_0c09da62: /* original d222, guest PC 0x0c09da62 */
if(!s->budget--) { s->failed_pc=0x0c09da62u; return 0; }
r[2]=read(ram,0x0c09daecu,4);
goto P_0c09da64;
P_0c09da64: /* original 64f3, guest PC 0x0c09da64 */
if(!s->budget--) { s->failed_pc=0x0c09da64u; return 0; }
r[4]=r[15];
goto P_0c09da66;
P_0c09da66: /* original 420b, guest PC 0x0c09da66 */
if(!s->budget--) { s->failed_pc=0x0c09da66u; return 0; }
target=r[2];
r[16]=code_base|0x0c09da6au;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09da6au) { target=s->pc; goto dispatch; }
goto P_0c09da6a;
P_0c09da68: /* original 7404, guest PC 0x0c09da68 */
if(!s->budget--) { s->failed_pc=0x0c09da68u; return 0; }
r[4]+=0x00000004u;
goto P_0c09da6a;
P_0c09da6a: /* original 7f10, guest PC 0x0c09da6a */
if(!s->budget--) { s->failed_pc=0x0c09da6au; return 0; }
r[15]+=0x00000010u;
goto P_0c09da6c;
P_0c09da6c: /* original 4f26, guest PC 0x0c09da6c */
if(!s->budget--) { s->failed_pc=0x0c09da6cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09da6e;
P_0c09da6e: /* original 000b, guest PC 0x0c09da6e */
if(!s->budget--) { s->failed_pc=0x0c09da6eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09da70: /* original 6ef6, guest PC 0x0c09da70 */
if(!s->budget--) { s->failed_pc=0x0c09da70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09da72u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
