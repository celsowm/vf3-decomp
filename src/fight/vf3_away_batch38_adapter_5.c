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
int vf3_away_batch38_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06d458u: goto P_0c06d458;
case 0x0c06d45au: goto P_0c06d45a;
case 0x0c06d45cu: goto P_0c06d45c;
case 0x0c06d45eu: goto P_0c06d45e;
case 0x0c06d460u: goto P_0c06d460;
case 0x0c06d462u: goto P_0c06d462;
case 0x0c06d464u: goto P_0c06d464;
case 0x0c06d466u: goto P_0c06d466;
case 0x0c06d468u: goto P_0c06d468;
case 0x0c06d46au: goto P_0c06d46a;
case 0x0c06d46cu: goto P_0c06d46c;
case 0x0c06d46eu: goto P_0c06d46e;
case 0x0c06d470u: goto P_0c06d470;
case 0x0c06d472u: goto P_0c06d472;
case 0x0c06d474u: goto P_0c06d474;
case 0x0c06d476u: goto P_0c06d476;
case 0x0c06d478u: goto P_0c06d478;
case 0x0c06d47au: goto P_0c06d47a;
case 0x0c06d47cu: goto P_0c06d47c;
case 0x0c06d47eu: goto P_0c06d47e;
case 0x0c06d480u: goto P_0c06d480;
case 0x0c06d482u: goto P_0c06d482;
case 0x0c06d484u: goto P_0c06d484;
case 0x0c06d486u: goto P_0c06d486;
case 0x0c06d488u: goto P_0c06d488;
case 0x0c06d48au: goto P_0c06d48a;
case 0x0c06d48cu: goto P_0c06d48c;
case 0x0c06d48eu: goto P_0c06d48e;
case 0x0c06d490u: goto P_0c06d490;
case 0x0c06d492u: goto P_0c06d492;
case 0x0c06d494u: goto P_0c06d494;
case 0x0c06d496u: goto P_0c06d496;
case 0x0c06d498u: goto P_0c06d498;
case 0x0c06d49au: goto P_0c06d49a;
case 0x0c06d49cu: goto P_0c06d49c;
case 0x0c06d49eu: goto P_0c06d49e;
case 0x0c06d4a0u: goto P_0c06d4a0;
case 0x0c06d4a2u: goto P_0c06d4a2;
case 0x0c06d4a4u: goto P_0c06d4a4;
case 0x0c06d4a6u: goto P_0c06d4a6;
case 0x0c06d4a8u: goto P_0c06d4a8;
case 0x0c06d4aau: goto P_0c06d4aa;
case 0x0c06d4acu: goto P_0c06d4ac;
case 0x0c06d4aeu: goto P_0c06d4ae;
case 0x0c06d4b0u: goto P_0c06d4b0;
case 0x0c06d4b2u: goto P_0c06d4b2;
case 0x0c06d4b4u: goto P_0c06d4b4;
case 0x0c06d4b6u: goto P_0c06d4b6;
case 0x0c06d4b8u: goto P_0c06d4b8;
case 0x0c06d4bau: goto P_0c06d4ba;
case 0x0c06d4bcu: goto P_0c06d4bc;
case 0x0c06d4beu: goto P_0c06d4be;
case 0x0c06d4c0u: goto P_0c06d4c0;
case 0x0c06d4c2u: goto P_0c06d4c2;
case 0x0c06d4c4u: goto P_0c06d4c4;
case 0x0c06d4c6u: goto P_0c06d4c6;
case 0x0c06d4c8u: goto P_0c06d4c8;
case 0x0c06d4cau: goto P_0c06d4ca;
case 0x0c06d4ccu: goto P_0c06d4cc;
case 0x0c06d4ceu: goto P_0c06d4ce;
case 0x0c06d4d0u: goto P_0c06d4d0;
case 0x0c06d4d2u: goto P_0c06d4d2;
case 0x0c06d4d4u: goto P_0c06d4d4;
case 0x0c06d4d6u: goto P_0c06d4d6;
case 0x0c06d4d8u: goto P_0c06d4d8;
case 0x0c06d4dau: goto P_0c06d4da;
case 0x0c06d4dcu: goto P_0c06d4dc;
case 0x0c06d4deu: goto P_0c06d4de;
case 0x0c06d4e0u: goto P_0c06d4e0;
case 0x0c06d4e2u: goto P_0c06d4e2;
case 0x0c06d4e4u: goto P_0c06d4e4;
case 0x0c06d4e6u: goto P_0c06d4e6;
case 0x0c06d4e8u: goto P_0c06d4e8;
case 0x0c06d4eau: goto P_0c06d4ea;
case 0x0c06d4ecu: goto P_0c06d4ec;
case 0x0c06d4eeu: goto P_0c06d4ee;
case 0x0c06d4f0u: goto P_0c06d4f0;
case 0x0c06d4f2u: goto P_0c06d4f2;
case 0x0c06d4f4u: goto P_0c06d4f4;
case 0x0c06d4f6u: goto P_0c06d4f6;
case 0x0c06d4f8u: goto P_0c06d4f8;
case 0x0c06d4fau: goto P_0c06d4fa;
case 0x0c06d4fcu: goto P_0c06d4fc;
case 0x0c06d4feu: goto P_0c06d4fe;
case 0x0c06d500u: goto P_0c06d500;
case 0x0c06d502u: goto P_0c06d502;
case 0x0c06d504u: goto P_0c06d504;
case 0x0c06d506u: goto P_0c06d506;
case 0x0c06d508u: goto P_0c06d508;
case 0x0c06d50au: goto P_0c06d50a;
case 0x0c06d50cu: goto P_0c06d50c;
case 0x0c06d50eu: goto P_0c06d50e;
case 0x0c06d510u: goto P_0c06d510;
case 0x0c06d512u: goto P_0c06d512;
case 0x0c06d514u: goto P_0c06d514;
case 0x0c06d516u: goto P_0c06d516;
case 0x0c06d518u: goto P_0c06d518;
case 0x0c06d51au: goto P_0c06d51a;
case 0x0c06d51cu: goto P_0c06d51c;
case 0x0c06d51eu: goto P_0c06d51e;
case 0x0c06d520u: goto P_0c06d520;
case 0x0c06d522u: goto P_0c06d522;
case 0x0c06d524u: goto P_0c06d524;
case 0x0c06d526u: goto P_0c06d526;
case 0x0c06d528u: goto P_0c06d528;
case 0x0c06d52au: goto P_0c06d52a;
case 0x0c06d52cu: goto P_0c06d52c;
case 0x0c06d52eu: goto P_0c06d52e;
case 0x0c06d530u: goto P_0c06d530;
case 0x0c06d532u: goto P_0c06d532;
case 0x0c06d534u: goto P_0c06d534;
case 0x0c06d536u: goto P_0c06d536;
case 0x0c06d538u: goto P_0c06d538;
case 0x0c06d53au: goto P_0c06d53a;
case 0x0c06d53cu: goto P_0c06d53c;
case 0x0c06d53eu: goto P_0c06d53e;
case 0x0c06d540u: goto P_0c06d540;
case 0x0c06d542u: goto P_0c06d542;
case 0x0c06d544u: goto P_0c06d544;
case 0x0c06d546u: goto P_0c06d546;
case 0x0c06d548u: goto P_0c06d548;
case 0x0c06d54au: goto P_0c06d54a;
case 0x0c06d54cu: goto P_0c06d54c;
case 0x0c06d54eu: goto P_0c06d54e;
case 0x0c06d550u: goto P_0c06d550;
case 0x0c06d552u: goto P_0c06d552;
case 0x0c06d554u: goto P_0c06d554;
case 0x0c06d556u: goto P_0c06d556;
case 0x0c06d558u: goto P_0c06d558;
case 0x0c06d55au: goto P_0c06d55a;
case 0x0c06d55cu: goto P_0c06d55c;
case 0x0c06d55eu: goto P_0c06d55e;
case 0x0c06d560u: goto P_0c06d560;
case 0x0c06d562u: goto P_0c06d562;
case 0x0c06d564u: goto P_0c06d564;
case 0x0c06d566u: goto P_0c06d566;
case 0x0c06d568u: goto P_0c06d568;
case 0x0c06d56au: goto P_0c06d56a;
case 0x0c06d56cu: goto P_0c06d56c;
case 0x0c06d56eu: goto P_0c06d56e;
case 0x0c06d570u: goto P_0c06d570;
case 0x0c06d572u: goto P_0c06d572;
case 0x0c06d574u: goto P_0c06d574;
case 0x0c06d576u: goto P_0c06d576;
case 0x0c06d578u: goto P_0c06d578;
case 0x0c06d57au: goto P_0c06d57a;
case 0x0c06d57cu: goto P_0c06d57c;
case 0x0c06d57eu: goto P_0c06d57e;
case 0x0c06d580u: goto P_0c06d580;
case 0x0c06d582u: goto P_0c06d582;
case 0x0c06d5ccu: goto P_0c06d5cc;
case 0x0c06d5ceu: goto P_0c06d5ce;
case 0x0c06d5d0u: goto P_0c06d5d0;
case 0x0c06d5d2u: goto P_0c06d5d2;
case 0x0c06d5d4u: goto P_0c06d5d4;
case 0x0c06d5d6u: goto P_0c06d5d6;
case 0x0c06d5d8u: goto P_0c06d5d8;
case 0x0c06d5dau: goto P_0c06d5da;
case 0x0c06d5dcu: goto P_0c06d5dc;
case 0x0c06d5deu: goto P_0c06d5de;
case 0x0c06d5e0u: goto P_0c06d5e0;
case 0x0c06d5e2u: goto P_0c06d5e2;
case 0x0c06d5e4u: goto P_0c06d5e4;
case 0x0c06d5e6u: goto P_0c06d5e6;
case 0x0c06d5e8u: goto P_0c06d5e8;
case 0x0c06d5eau: goto P_0c06d5ea;
case 0x0c06d5ecu: goto P_0c06d5ec;
case 0x0c06d5eeu: goto P_0c06d5ee;
case 0x0c06d5f0u: goto P_0c06d5f0;
case 0x0c06d5f2u: goto P_0c06d5f2;
case 0x0c06d5f4u: goto P_0c06d5f4;
case 0x0c06d5f6u: goto P_0c06d5f6;
case 0x0c06d5f8u: goto P_0c06d5f8;
case 0x0c06d5fau: goto P_0c06d5fa;
case 0x0c06d5fcu: goto P_0c06d5fc;
case 0x0c06d5feu: goto P_0c06d5fe;
case 0x0c06d600u: goto P_0c06d600;
case 0x0c06d602u: goto P_0c06d602;
case 0x0c06d604u: goto P_0c06d604;
case 0x0c06d606u: goto P_0c06d606;
case 0x0c06d608u: goto P_0c06d608;
case 0x0c06d60au: goto P_0c06d60a;
case 0x0c06d60cu: goto P_0c06d60c;
case 0x0c06d60eu: goto P_0c06d60e;
case 0x0c06d610u: goto P_0c06d610;
case 0x0c06d612u: goto P_0c06d612;
case 0x0c06d614u: goto P_0c06d614;
case 0x0c06d616u: goto P_0c06d616;
case 0x0c06d618u: goto P_0c06d618;
case 0x0c06d61au: goto P_0c06d61a;
case 0x0c06d61cu: goto P_0c06d61c;
case 0x0c06d61eu: goto P_0c06d61e;
case 0x0c06d620u: goto P_0c06d620;
case 0x0c06d622u: goto P_0c06d622;
case 0x0c06d624u: goto P_0c06d624;
case 0x0c06d626u: goto P_0c06d626;
case 0x0c06d628u: goto P_0c06d628;
case 0x0c06d62au: goto P_0c06d62a;
case 0x0c06d62cu: goto P_0c06d62c;
case 0x0c06d62eu: goto P_0c06d62e;
case 0x0c06d630u: goto P_0c06d630;
case 0x0c06d632u: goto P_0c06d632;
case 0x0c06d634u: goto P_0c06d634;
case 0x0c06d636u: goto P_0c06d636;
case 0x0c06d638u: goto P_0c06d638;
case 0x0c06d63au: goto P_0c06d63a;
case 0x0c06d63cu: goto P_0c06d63c;
case 0x0c06d63eu: goto P_0c06d63e;
case 0x0c06d640u: goto P_0c06d640;
case 0x0c06d642u: goto P_0c06d642;
case 0x0c06d644u: goto P_0c06d644;
case 0x0c06d646u: goto P_0c06d646;
case 0x0c06d648u: goto P_0c06d648;
case 0x0c06d64au: goto P_0c06d64a;
case 0x0c06d64cu: goto P_0c06d64c;
case 0x0c06d64eu: goto P_0c06d64e;
case 0x0c06d650u: goto P_0c06d650;
case 0x0c06d652u: goto P_0c06d652;
case 0x0c06d654u: goto P_0c06d654;
case 0x0c06d656u: goto P_0c06d656;
case 0x0c06d658u: goto P_0c06d658;
case 0x0c06d65au: goto P_0c06d65a;
case 0x0c06d65cu: goto P_0c06d65c;
case 0x0c06d65eu: goto P_0c06d65e;
case 0x0c06d660u: goto P_0c06d660;
case 0x0c06d662u: goto P_0c06d662;
case 0x0c06d664u: goto P_0c06d664;
case 0x0c06d666u: goto P_0c06d666;
case 0x0c06d668u: goto P_0c06d668;
case 0x0c06d66au: goto P_0c06d66a;
case 0x0c06d66cu: goto P_0c06d66c;
case 0x0c06d66eu: goto P_0c06d66e;
case 0x0c06d670u: goto P_0c06d670;
case 0x0c06d672u: goto P_0c06d672;
case 0x0c06d674u: goto P_0c06d674;
case 0x0c06d676u: goto P_0c06d676;
case 0x0c06d678u: goto P_0c06d678;
case 0x0c06d67au: goto P_0c06d67a;
case 0x0c06d67cu: goto P_0c06d67c;
case 0x0c06d67eu: goto P_0c06d67e;
case 0x0c06d680u: goto P_0c06d680;
case 0x0c06d682u: goto P_0c06d682;
case 0x0c06d684u: goto P_0c06d684;
case 0x0c06d686u: goto P_0c06d686;
case 0x0c06d688u: goto P_0c06d688;
case 0x0c06d68au: goto P_0c06d68a;
case 0x0c06d68cu: goto P_0c06d68c;
case 0x0c06d68eu: goto P_0c06d68e;
case 0x0c06d690u: goto P_0c06d690;
case 0x0c06d692u: goto P_0c06d692;
case 0x0c06d694u: goto P_0c06d694;
case 0x0c06d696u: goto P_0c06d696;
case 0x0c06d698u: goto P_0c06d698;
case 0x0c06d69au: goto P_0c06d69a;
case 0x0c06d69cu: goto P_0c06d69c;
case 0x0c06d69eu: goto P_0c06d69e;
case 0x0c06d6a0u: goto P_0c06d6a0;
case 0x0c06d6a2u: goto P_0c06d6a2;
case 0x0c06d6a4u: goto P_0c06d6a4;
case 0x0c06d6a6u: goto P_0c06d6a6;
case 0x0c06d6a8u: goto P_0c06d6a8;
case 0x0c06d6aau: goto P_0c06d6aa;
case 0x0c06d6acu: goto P_0c06d6ac;
case 0x0c06d6aeu: goto P_0c06d6ae;
case 0x0c06d6b0u: goto P_0c06d6b0;
case 0x0c06d6b2u: goto P_0c06d6b2;
case 0x0c06d6b4u: goto P_0c06d6b4;
case 0x0c06d6b6u: goto P_0c06d6b6;
case 0x0c06d6b8u: goto P_0c06d6b8;
case 0x0c06d6bau: goto P_0c06d6ba;
case 0x0c06d6bcu: goto P_0c06d6bc;
case 0x0c06d6beu: goto P_0c06d6be;
case 0x0c06d6c0u: goto P_0c06d6c0;
case 0x0c06d6c2u: goto P_0c06d6c2;
case 0x0c06d6c4u: goto P_0c06d6c4;
case 0x0c06d6c6u: goto P_0c06d6c6;
case 0x0c06d6c8u: goto P_0c06d6c8;
case 0x0c06d6cau: goto P_0c06d6ca;
case 0x0c06d6ccu: goto P_0c06d6cc;
case 0x0c06d6ceu: goto P_0c06d6ce;
case 0x0c06d6d0u: goto P_0c06d6d0;
case 0x0c06d6d2u: goto P_0c06d6d2;
case 0x0c06d6d4u: goto P_0c06d6d4;
case 0x0c06d6d6u: goto P_0c06d6d6;
case 0x0c06d6d8u: goto P_0c06d6d8;
case 0x0c06d6dau: goto P_0c06d6da;
case 0x0c06d6dcu: goto P_0c06d6dc;
case 0x0c06d6deu: goto P_0c06d6de;
case 0x0c06d6e0u: goto P_0c06d6e0;
case 0x0c06d6e2u: goto P_0c06d6e2;
case 0x0c06d6e4u: goto P_0c06d6e4;
case 0x0c06d6e6u: goto P_0c06d6e6;
case 0x0c06d6e8u: goto P_0c06d6e8;
case 0x0c06d6eau: goto P_0c06d6ea;
case 0x0c06d6ecu: goto P_0c06d6ec;
case 0x0c06d6eeu: goto P_0c06d6ee;
case 0x0c06d6f0u: goto P_0c06d6f0;
case 0x0c06d6f2u: goto P_0c06d6f2;
case 0x0c06d6f4u: goto P_0c06d6f4;
case 0x0c06d6f6u: goto P_0c06d6f6;
case 0x0c06d6f8u: goto P_0c06d6f8;
case 0x0c06d6fau: goto P_0c06d6fa;
case 0x0c06d6fcu: goto P_0c06d6fc;
case 0x0c06d6feu: goto P_0c06d6fe;
case 0x0c06d700u: goto P_0c06d700;
case 0x0c06d702u: goto P_0c06d702;
case 0x0c06d704u: goto P_0c06d704;
case 0x0c06d706u: goto P_0c06d706;
case 0x0c06d708u: goto P_0c06d708;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06d458: /* original 2fe6, guest PC 0x0c06d458 */
if(!s->budget--) { s->failed_pc=0x0c06d458u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06d45a;
P_0c06d45a: /* original e300, guest PC 0x0c06d45a */
if(!s->budget--) { s->failed_pc=0x0c06d45au; return 0; }
r[3]=0x00000000u;
goto P_0c06d45c;
P_0c06d45c: /* original 2fd6, guest PC 0x0c06d45c */
if(!s->budget--) { s->failed_pc=0x0c06d45cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06d45e;
P_0c06d45e: /* original 6d43, guest PC 0x0c06d45e */
if(!s->budget--) { s->failed_pc=0x0c06d45eu; return 0; }
r[13]=r[4];
goto P_0c06d460;
P_0c06d460: /* original 2fc6, guest PC 0x0c06d460 */
if(!s->budget--) { s->failed_pc=0x0c06d460u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06d462;
P_0c06d462: /* original 2fb6, guest PC 0x0c06d462 */
if(!s->budget--) { s->failed_pc=0x0c06d462u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06d464;
P_0c06d464: /* original 2fa6, guest PC 0x0c06d464 */
if(!s->budget--) { s->failed_pc=0x0c06d464u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06d466;
P_0c06d466: /* original 2f96, guest PC 0x0c06d466 */
if(!s->budget--) { s->failed_pc=0x0c06d466u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06d468;
P_0c06d468: /* original 2f86, guest PC 0x0c06d468 */
if(!s->budget--) { s->failed_pc=0x0c06d468u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06d46a;
P_0c06d46a: /* original de4a, guest PC 0x0c06d46a */
if(!s->budget--) { s->failed_pc=0x0c06d46au; return 0; }
r[14]=read(ram,0x0c06d594u,4);
goto P_0c06d46c;
P_0c06d46c: /* original 4f22, guest PC 0x0c06d46c */
if(!s->budget--) { s->failed_pc=0x0c06d46cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06d46e;
P_0c06d46e: /* original db48, guest PC 0x0c06d46e */
if(!s->budget--) { s->failed_pc=0x0c06d46eu; return 0; }
r[11]=read(ram,0x0c06d590u,4);
goto P_0c06d470;
P_0c06d470: /* original 7fdc, guest PC 0x0c06d470 */
if(!s->budget--) { s->failed_pc=0x0c06d470u; return 0; }
r[15]+=0xffffffdcu;
goto P_0c06d472;
P_0c06d472: /* original 1f35, guest PC 0x0c06d472 */
if(!s->budget--) { s->failed_pc=0x0c06d472u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c06d474;
P_0c06d474: /* original 62e2, guest PC 0x0c06d474 */
if(!s->budget--) { s->failed_pc=0x0c06d474u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c06d476;
P_0c06d476: /* original 2f22, guest PC 0x0c06d476 */
if(!s->budget--) { s->failed_pc=0x0c06d476u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c06d478;
P_0c06d478: /* original d247, guest PC 0x0c06d478 */
if(!s->budget--) { s->failed_pc=0x0c06d478u; return 0; }
r[2]=read(ram,0x0c06d598u,4);
goto P_0c06d47a;
P_0c06d47a: /* original 53e1, guest PC 0x0c06d47a */
if(!s->budget--) { s->failed_pc=0x0c06d47au; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c06d47c;
P_0c06d47c: /* original 420b, guest PC 0x0c06d47c */
if(!s->budget--) { s->failed_pc=0x0c06d47cu; return 0; }
target=r[2];
r[16]=code_base|0x0c06d480u;
write(ram,r[15]+16,r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d480u) { target=s->pc; goto dispatch; }
goto P_0c06d480;
P_0c06d47e: /* original 1f34, guest PC 0x0c06d47e */
if(!s->budget--) { s->failed_pc=0x0c06d47eu; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c06d480;
P_0c06d480: /* original 2008, guest PC 0x0c06d480 */
if(!s->budget--) { s->failed_pc=0x0c06d480u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06d482;
P_0c06d482: /* original 8b01, guest PC 0x0c06d482 */
if(!s->budget--) { s->failed_pc=0x0c06d482u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d488; }
goto P_0c06d484;
P_0c06d484: /* original a0c9, guest PC 0x0c06d484 */
if(!s->budget--) { s->failed_pc=0x0c06d484u; return 0; }
goto P_0c06d61a;
P_0c06d486: /* original 0009, guest PC 0x0c06d486 */
if(!s->budget--) { s->failed_pc=0x0c06d486u; return 0; }
goto P_0c06d488;
P_0c06d488: /* original 62f2, guest PC 0x0c06d488 */
if(!s->budget--) { s->failed_pc=0x0c06d488u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c06d48a;
P_0c06d48a: /* original d344, guest PC 0x0c06d48a */
if(!s->budget--) { s->failed_pc=0x0c06d48au; return 0; }
r[3]=read(ram,0x0c06d59cu,4);
goto P_0c06d48c;
P_0c06d48c: /* original 2238, guest PC 0x0c06d48c */
if(!s->budget--) { s->failed_pc=0x0c06d48cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c06d48e;
P_0c06d48e: /* original 890b, guest PC 0x0c06d48e */
if(!s->budget--) { s->failed_pc=0x0c06d48eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d4a8; }
goto P_0c06d490;
P_0c06d490: /* original 51f4, guest PC 0x0c06d490 */
if(!s->budget--) { s->failed_pc=0x0c06d490u; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c06d492;
P_0c06d492: /* original d343, guest PC 0x0c06d492 */
if(!s->budget--) { s->failed_pc=0x0c06d492u; return 0; }
r[3]=read(ram,0x0c06d5a0u,4);
goto P_0c06d494;
P_0c06d494: /* original 2138, guest PC 0x0c06d494 */
if(!s->budget--) { s->failed_pc=0x0c06d494u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c06d496;
P_0c06d496: /* original 8907, guest PC 0x0c06d496 */
if(!s->budget--) { s->failed_pc=0x0c06d496u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d4a8; }
goto P_0c06d498;
P_0c06d498: /* original 9074, guest PC 0x0c06d498 */
if(!s->budget--) { s->failed_pc=0x0c06d498u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d584u,2);
goto P_0c06d49a;
P_0c06d49a: /* original d342, guest PC 0x0c06d49a */
if(!s->budget--) { s->failed_pc=0x0c06d49au; return 0; }
r[3]=read(ram,0x0c06d5a4u,4);
goto P_0c06d49c;
P_0c06d49c: /* original 05bd, guest PC 0x0c06d49c */
if(!s->budget--) { s->failed_pc=0x0c06d49cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c06d49e;
P_0c06d49e: /* original 70fe, guest PC 0x0c06d49e */
if(!s->budget--) { s->failed_pc=0x0c06d49eu; return 0; }
r[0]+=0xfffffffeu;
goto P_0c06d4a0;
P_0c06d4a0: /* original 430b, guest PC 0x0c06d4a0 */
if(!s->budget--) { s->failed_pc=0x0c06d4a0u; return 0; }
target=r[3];
r[16]=code_base|0x0c06d4a4u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d4a4u) { target=s->pc; goto dispatch; }
goto P_0c06d4a4;
P_0c06d4a2: /* original 04bd, guest PC 0x0c06d4a2 */
if(!s->budget--) { s->failed_pc=0x0c06d4a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c06d4a4;
P_0c06d4a4: /* original e201, guest PC 0x0c06d4a4 */
if(!s->budget--) { s->failed_pc=0x0c06d4a4u; return 0; }
r[2]=0x00000001u;
goto P_0c06d4a6;
P_0c06d4a6: /* original 1f25, guest PC 0x0c06d4a6 */
if(!s->budget--) { s->failed_pc=0x0c06d4a6u; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c06d4a8;
P_0c06d4a8: /* original e01c, guest PC 0x0c06d4a8 */
if(!s->budget--) { s->failed_pc=0x0c06d4a8u; return 0; }
r[0]=0x0000001cu;
goto P_0c06d4aa;
P_0c06d4aa: /* original da3f, guest PC 0x0c06d4aa */
if(!s->budget--) { s->failed_pc=0x0c06d4aau; return 0; }
r[10]=read(ram,0x0c06d5a8u,4);
goto P_0c06d4ac;
P_0c06d4ac: /* original e90f, guest PC 0x0c06d4ac */
if(!s->budget--) { s->failed_pc=0x0c06d4acu; return 0; }
r[9]=0x0000000fu;
goto P_0c06d4ae;
P_0c06d4ae: /* original 53a5, guest PC 0x0c06d4ae */
if(!s->budget--) { s->failed_pc=0x0c06d4aeu; return 0; }
r[3]=read(ram,r[10]+20,4);
goto P_0c06d4b0;
P_0c06d4b0: /* original 5ca4, guest PC 0x0c06d4b0 */
if(!s->budget--) { s->failed_pc=0x0c06d4b0u; return 0; }
r[12]=read(ram,r[10]+16,4);
goto P_0c06d4b2;
P_0c06d4b2: /* original 2f32, guest PC 0x0c06d4b2 */
if(!s->budget--) { s->failed_pc=0x0c06d4b2u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06d4b4;
P_0c06d4b4: /* original 00ec, guest PC 0x0c06d4b4 */
if(!s->budget--) { s->failed_pc=0x0c06d4b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06d4b6;
P_0c06d4b6: /* original d83d, guest PC 0x0c06d4b6 */
if(!s->budget--) { s->failed_pc=0x0c06d4b6u; return 0; }
r[8]=read(ram,0x0c06d5acu,4);
goto P_0c06d4b8;
P_0c06d4b8: /* original 600c, guest PC 0x0c06d4b8 */
if(!s->budget--) { s->failed_pc=0x0c06d4b8u; return 0; }
r[0]=r[0]&255u;
goto P_0c06d4ba;
P_0c06d4ba: /* original 2099, guest PC 0x0c06d4ba */
if(!s->budget--) { s->failed_pc=0x0c06d4bau; return 0; }
r[0]&=r[9];
goto P_0c06d4bc;
P_0c06d4bc: /* original 8804, guest PC 0x0c06d4bc */
if(!s->budget--) { s->failed_pc=0x0c06d4bcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c06d4be;
P_0c06d4be: /* original 8b0a, guest PC 0x0c06d4be */
if(!s->budget--) { s->failed_pc=0x0c06d4beu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d4d6; }
goto P_0c06d4c0;
P_0c06d4c0: /* original d53b, guest PC 0x0c06d4c0 */
if(!s->budget--) { s->failed_pc=0x0c06d4c0u; return 0; }
r[5]=read(ram,0x0c06d5b0u,4);
goto P_0c06d4c2;
P_0c06d4c2: /* original 66f3, guest PC 0x0c06d4c2 */
if(!s->budget--) { s->failed_pc=0x0c06d4c2u; return 0; }
r[6]=r[15];
goto P_0c06d4c4;
P_0c06d4c4: /* original 7618, guest PC 0x0c06d4c4 */
if(!s->budget--) { s->failed_pc=0x0c06d4c4u; return 0; }
r[6]+=0x00000018u;
goto P_0c06d4c6;
P_0c06d4c6: /* original b0b2, guest PC 0x0c06d4c6 */
if(!s->budget--) { s->failed_pc=0x0c06d4c6u; return 0; }
target=code_base|0x0c06d62eu; r[16]=code_base|0x0c06d4cau;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d4cau) { target=s->pc; goto dispatch; }
goto P_0c06d4ca;
P_0c06d4c8: /* original 64c3, guest PC 0x0c06d4c8 */
if(!s->budget--) { s->failed_pc=0x0c06d4c8u; return 0; }
r[4]=r[12];
goto P_0c06d4ca;
P_0c06d4ca: /* original 64f3, guest PC 0x0c06d4ca */
if(!s->budget--) { s->failed_pc=0x0c06d4cau; return 0; }
r[4]=r[15];
goto P_0c06d4cc;
P_0c06d4cc: /* original c739, guest PC 0x0c06d4cc */
if(!s->budget--) { s->failed_pc=0x0c06d4ccu; return 0; }
r[0]=code_base|0x0006d5b4u;
goto P_0c06d4ce;
P_0c06d4ce: /* original 7418, guest PC 0x0c06d4ce */
if(!s->budget--) { s->failed_pc=0x0c06d4ceu; return 0; }
r[4]+=0x00000018u;
goto P_0c06d4d0;
P_0c06d4d0: /* original f40c, guest PC 0x0c06d4d0 */
if(!s->budget--) { s->failed_pc=0x0c06d4d0u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c06d4d2;
P_0c06d4d2: /* original 480b, guest PC 0x0c06d4d2 */
if(!s->budget--) { s->failed_pc=0x0c06d4d2u; return 0; }
target=r[8];
r[16]=code_base|0x0c06d4d6u;
vf3_matrix_load(s,ram,5,r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d4d6u) { target=s->pc; goto dispatch; }
goto P_0c06d4d6;
P_0c06d4d4: /* original f508, guest PC 0x0c06d4d4 */
if(!s->budget--) { s->failed_pc=0x0c06d4d4u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c06d4d6;
P_0c06d4d6: /* original d338, guest PC 0x0c06d4d6 */
if(!s->budget--) { s->failed_pc=0x0c06d4d6u; return 0; }
r[3]=read(ram,0x0c06d5b8u,4);
goto P_0c06d4d8;
P_0c06d4d8: /* original 430b, guest PC 0x0c06d4d8 */
if(!s->budget--) { s->failed_pc=0x0c06d4d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c06d4dcu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d4dcu) { target=s->pc; goto dispatch; }
goto P_0c06d4dc;
P_0c06d4da: /* original 64c3, guest PC 0x0c06d4da */
if(!s->budget--) { s->failed_pc=0x0c06d4dau; return 0; }
r[4]=r[12];
goto P_0c06d4dc;
P_0c06d4dc: /* original 9053, guest PC 0x0c06d4dc */
if(!s->budget--) { s->failed_pc=0x0c06d4dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d586u,2);
goto P_0c06d4de;
P_0c06d4de: /* original 02bc, guest PC 0x0c06d4de */
if(!s->budget--) { s->failed_pc=0x0c06d4deu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c06d4e0;
P_0c06d4e0: /* original 2228, guest PC 0x0c06d4e0 */
if(!s->budget--) { s->failed_pc=0x0c06d4e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c06d4e2;
P_0c06d4e2: /* original 8b03, guest PC 0x0c06d4e2 */
if(!s->budget--) { s->failed_pc=0x0c06d4e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d4ec; }
goto P_0c06d4e4;
P_0c06d4e4: /* original d235, guest PC 0x0c06d4e4 */
if(!s->budget--) { s->failed_pc=0x0c06d4e4u; return 0; }
r[2]=read(ram,0x0c06d5bcu,4);
goto P_0c06d4e6;
P_0c06d4e6: /* original 65c3, guest PC 0x0c06d4e6 */
if(!s->budget--) { s->failed_pc=0x0c06d4e6u; return 0; }
r[5]=r[12];
goto P_0c06d4e8;
P_0c06d4e8: /* original 420b, guest PC 0x0c06d4e8 */
if(!s->budget--) { s->failed_pc=0x0c06d4e8u; return 0; }
target=r[2];
r[16]=code_base|0x0c06d4ecu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d4ecu) { target=s->pc; goto dispatch; }
goto P_0c06d4ec;
P_0c06d4ea: /* original 64d3, guest PC 0x0c06d4ea */
if(!s->budget--) { s->failed_pc=0x0c06d4eau; return 0; }
r[4]=r[13];
goto P_0c06d4ec;
P_0c06d4ec: /* original d334, guest PC 0x0c06d4ec */
if(!s->budget--) { s->failed_pc=0x0c06d4ecu; return 0; }
r[3]=read(ram,0x0c06d5c0u,4);
goto P_0c06d4ee;
P_0c06d4ee: /* original 65c3, guest PC 0x0c06d4ee */
if(!s->budget--) { s->failed_pc=0x0c06d4eeu; return 0; }
r[5]=r[12];
goto P_0c06d4f0;
P_0c06d4f0: /* original 66f2, guest PC 0x0c06d4f0 */
if(!s->budget--) { s->failed_pc=0x0c06d4f0u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c06d4f2;
P_0c06d4f2: /* original 430b, guest PC 0x0c06d4f2 */
if(!s->budget--) { s->failed_pc=0x0c06d4f2u; return 0; }
target=r[3];
r[16]=code_base|0x0c06d4f6u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d4f6u) { target=s->pc; goto dispatch; }
goto P_0c06d4f6;
P_0c06d4f4: /* original 64d3, guest PC 0x0c06d4f4 */
if(!s->budget--) { s->failed_pc=0x0c06d4f4u; return 0; }
r[4]=r[13];
goto P_0c06d4f6;
P_0c06d4f6: /* original d233, guest PC 0x0c06d4f6 */
if(!s->budget--) { s->failed_pc=0x0c06d4f6u; return 0; }
r[2]=read(ram,0x0c06d5c4u,4);
goto P_0c06d4f8;
P_0c06d4f8: /* original 420b, guest PC 0x0c06d4f8 */
if(!s->budget--) { s->failed_pc=0x0c06d4f8u; return 0; }
target=r[2];
r[16]=code_base|0x0c06d4fcu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d4fcu) { target=s->pc; goto dispatch; }
goto P_0c06d4fc;
P_0c06d4fa: /* original 64c3, guest PC 0x0c06d4fa */
if(!s->budget--) { s->failed_pc=0x0c06d4fau; return 0; }
r[4]=r[12];
goto P_0c06d4fc;
P_0c06d4fc: /* original e01c, guest PC 0x0c06d4fc */
if(!s->budget--) { s->failed_pc=0x0c06d4fcu; return 0; }
r[0]=0x0000001cu;
goto P_0c06d4fe;
P_0c06d4fe: /* original 53a4, guest PC 0x0c06d4fe */
if(!s->budget--) { s->failed_pc=0x0c06d4feu; return 0; }
r[3]=read(ram,r[10]+16,4);
goto P_0c06d500;
P_0c06d500: /* original 5ca5, guest PC 0x0c06d500 */
if(!s->budget--) { s->failed_pc=0x0c06d500u; return 0; }
r[12]=read(ram,r[10]+20,4);
goto P_0c06d502;
P_0c06d502: /* original 2f32, guest PC 0x0c06d502 */
if(!s->budget--) { s->failed_pc=0x0c06d502u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06d504;
P_0c06d504: /* original 00ec, guest PC 0x0c06d504 */
if(!s->budget--) { s->failed_pc=0x0c06d504u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06d506;
P_0c06d506: /* original 600c, guest PC 0x0c06d506 */
if(!s->budget--) { s->failed_pc=0x0c06d506u; return 0; }
r[0]=r[0]&255u;
goto P_0c06d508;
P_0c06d508: /* original 2099, guest PC 0x0c06d508 */
if(!s->budget--) { s->failed_pc=0x0c06d508u; return 0; }
r[0]&=r[9];
goto P_0c06d50a;
P_0c06d50a: /* original 8804, guest PC 0x0c06d50a */
if(!s->budget--) { s->failed_pc=0x0c06d50au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c06d50c;
P_0c06d50c: /* original 8b0a, guest PC 0x0c06d50c */
if(!s->budget--) { s->failed_pc=0x0c06d50cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d524; }
goto P_0c06d50e;
P_0c06d50e: /* original d528, guest PC 0x0c06d50e */
if(!s->budget--) { s->failed_pc=0x0c06d50eu; return 0; }
r[5]=read(ram,0x0c06d5b0u,4);
goto P_0c06d510;
P_0c06d510: /* original 66f3, guest PC 0x0c06d510 */
if(!s->budget--) { s->failed_pc=0x0c06d510u; return 0; }
r[6]=r[15];
goto P_0c06d512;
P_0c06d512: /* original 7618, guest PC 0x0c06d512 */
if(!s->budget--) { s->failed_pc=0x0c06d512u; return 0; }
r[6]+=0x00000018u;
goto P_0c06d514;
P_0c06d514: /* original b08b, guest PC 0x0c06d514 */
if(!s->budget--) { s->failed_pc=0x0c06d514u; return 0; }
target=code_base|0x0c06d62eu; r[16]=code_base|0x0c06d518u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d518u) { target=s->pc; goto dispatch; }
goto P_0c06d518;
P_0c06d516: /* original 64c3, guest PC 0x0c06d516 */
if(!s->budget--) { s->failed_pc=0x0c06d516u; return 0; }
r[4]=r[12];
goto P_0c06d518;
P_0c06d518: /* original 64f3, guest PC 0x0c06d518 */
if(!s->budget--) { s->failed_pc=0x0c06d518u; return 0; }
r[4]=r[15];
goto P_0c06d51a;
P_0c06d51a: /* original c726, guest PC 0x0c06d51a */
if(!s->budget--) { s->failed_pc=0x0c06d51au; return 0; }
r[0]=code_base|0x0006d5b4u;
goto P_0c06d51c;
P_0c06d51c: /* original 7418, guest PC 0x0c06d51c */
if(!s->budget--) { s->failed_pc=0x0c06d51cu; return 0; }
r[4]+=0x00000018u;
goto P_0c06d51e;
P_0c06d51e: /* original f40c, guest PC 0x0c06d51e */
if(!s->budget--) { s->failed_pc=0x0c06d51eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c06d520;
P_0c06d520: /* original 480b, guest PC 0x0c06d520 */
if(!s->budget--) { s->failed_pc=0x0c06d520u; return 0; }
target=r[8];
r[16]=code_base|0x0c06d524u;
vf3_matrix_load(s,ram,5,r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d524u) { target=s->pc; goto dispatch; }
goto P_0c06d524;
P_0c06d522: /* original f508, guest PC 0x0c06d522 */
if(!s->budget--) { s->failed_pc=0x0c06d522u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c06d524;
P_0c06d524: /* original d324, guest PC 0x0c06d524 */
if(!s->budget--) { s->failed_pc=0x0c06d524u; return 0; }
r[3]=read(ram,0x0c06d5b8u,4);
goto P_0c06d526;
P_0c06d526: /* original 430b, guest PC 0x0c06d526 */
if(!s->budget--) { s->failed_pc=0x0c06d526u; return 0; }
target=r[3];
r[16]=code_base|0x0c06d52au;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d52au) { target=s->pc; goto dispatch; }
goto P_0c06d52a;
P_0c06d528: /* original 64c3, guest PC 0x0c06d528 */
if(!s->budget--) { s->failed_pc=0x0c06d528u; return 0; }
r[4]=r[12];
goto P_0c06d52a;
P_0c06d52a: /* original 902c, guest PC 0x0c06d52a */
if(!s->budget--) { s->failed_pc=0x0c06d52au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d586u,2);
goto P_0c06d52c;
P_0c06d52c: /* original 02bc, guest PC 0x0c06d52c */
if(!s->budget--) { s->failed_pc=0x0c06d52cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c06d52e;
P_0c06d52e: /* original 2228, guest PC 0x0c06d52e */
if(!s->budget--) { s->failed_pc=0x0c06d52eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c06d530;
P_0c06d530: /* original 8b03, guest PC 0x0c06d530 */
if(!s->budget--) { s->failed_pc=0x0c06d530u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d53a; }
goto P_0c06d532;
P_0c06d532: /* original d222, guest PC 0x0c06d532 */
if(!s->budget--) { s->failed_pc=0x0c06d532u; return 0; }
r[2]=read(ram,0x0c06d5bcu,4);
goto P_0c06d534;
P_0c06d534: /* original 65c3, guest PC 0x0c06d534 */
if(!s->budget--) { s->failed_pc=0x0c06d534u; return 0; }
r[5]=r[12];
goto P_0c06d536;
P_0c06d536: /* original 420b, guest PC 0x0c06d536 */
if(!s->budget--) { s->failed_pc=0x0c06d536u; return 0; }
target=r[2];
r[16]=code_base|0x0c06d53au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d53au) { target=s->pc; goto dispatch; }
goto P_0c06d53a;
P_0c06d538: /* original 64d3, guest PC 0x0c06d538 */
if(!s->budget--) { s->failed_pc=0x0c06d538u; return 0; }
r[4]=r[13];
goto P_0c06d53a;
P_0c06d53a: /* original d321, guest PC 0x0c06d53a */
if(!s->budget--) { s->failed_pc=0x0c06d53au; return 0; }
r[3]=read(ram,0x0c06d5c0u,4);
goto P_0c06d53c;
P_0c06d53c: /* original 65c3, guest PC 0x0c06d53c */
if(!s->budget--) { s->failed_pc=0x0c06d53cu; return 0; }
r[5]=r[12];
goto P_0c06d53e;
P_0c06d53e: /* original 66f2, guest PC 0x0c06d53e */
if(!s->budget--) { s->failed_pc=0x0c06d53eu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c06d540;
P_0c06d540: /* original 430b, guest PC 0x0c06d540 */
if(!s->budget--) { s->failed_pc=0x0c06d540u; return 0; }
target=r[3];
r[16]=code_base|0x0c06d544u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d544u) { target=s->pc; goto dispatch; }
goto P_0c06d544;
P_0c06d542: /* original 64d3, guest PC 0x0c06d542 */
if(!s->budget--) { s->failed_pc=0x0c06d542u; return 0; }
r[4]=r[13];
goto P_0c06d544;
P_0c06d544: /* original d21f, guest PC 0x0c06d544 */
if(!s->budget--) { s->failed_pc=0x0c06d544u; return 0; }
r[2]=read(ram,0x0c06d5c4u,4);
goto P_0c06d546;
P_0c06d546: /* original 420b, guest PC 0x0c06d546 */
if(!s->budget--) { s->failed_pc=0x0c06d546u; return 0; }
target=r[2];
r[16]=code_base|0x0c06d54au;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d54au) { target=s->pc; goto dispatch; }
goto P_0c06d54a;
P_0c06d548: /* original 64c3, guest PC 0x0c06d548 */
if(!s->budget--) { s->failed_pc=0x0c06d548u; return 0; }
r[4]=r[12];
goto P_0c06d54a;
P_0c06d54a: /* original e01c, guest PC 0x0c06d54a */
if(!s->budget--) { s->failed_pc=0x0c06d54au; return 0; }
r[0]=0x0000001cu;
goto P_0c06d54c;
P_0c06d54c: /* original 00ec, guest PC 0x0c06d54c */
if(!s->budget--) { s->failed_pc=0x0c06d54cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06d54e;
P_0c06d54e: /* original 600c, guest PC 0x0c06d54e */
if(!s->budget--) { s->failed_pc=0x0c06d54eu; return 0; }
r[0]=r[0]&255u;
goto P_0c06d550;
P_0c06d550: /* original 2099, guest PC 0x0c06d550 */
if(!s->budget--) { s->failed_pc=0x0c06d550u; return 0; }
r[0]&=r[9];
goto P_0c06d552;
P_0c06d552: /* original 8804, guest PC 0x0c06d552 */
if(!s->budget--) { s->failed_pc=0x0c06d552u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c06d554;
P_0c06d554: /* original 8b50, guest PC 0x0c06d554 */
if(!s->budget--) { s->failed_pc=0x0c06d554u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d5f8; }
goto P_0c06d556;
P_0c06d556: /* original 9019, guest PC 0x0c06d556 */
if(!s->budget--) { s->failed_pc=0x0c06d556u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d58cu,2);
goto P_0c06d558;
P_0c06d558: /* original 9b17, guest PC 0x0c06d558 */
if(!s->budget--) { s->failed_pc=0x0c06d558u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d58au,2);
goto P_0c06d55a;
P_0c06d55a: /* original 02dd, guest PC 0x0c06d55a */
if(!s->budget--) { s->failed_pc=0x0c06d55au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c06d55c;
P_0c06d55c: /* original 7002, guest PC 0x0c06d55c */
if(!s->budget--) { s->failed_pc=0x0c06d55cu; return 0; }
r[0]+=0x00000002u;
goto P_0c06d55e;
P_0c06d55e: /* original 03dd, guest PC 0x0c06d55e */
if(!s->budget--) { s->failed_pc=0x0c06d55eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c06d560;
P_0c06d560: /* original 3b2c, guest PC 0x0c06d560 */
if(!s->budget--) { s->failed_pc=0x0c06d560u; return 0; }
r[11]+=r[2];
goto P_0c06d562;
P_0c06d562: /* original 9c11, guest PC 0x0c06d562 */
if(!s->budget--) { s->failed_pc=0x0c06d562u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d588u,2);
goto P_0c06d564;
P_0c06d564: /* original e200, guest PC 0x0c06d564 */
if(!s->budget--) { s->failed_pc=0x0c06d564u; return 0; }
r[2]=0x00000000u;
goto P_0c06d566;
P_0c06d566: /* original 6bbf, guest PC 0x0c06d566 */
if(!s->budget--) { s->failed_pc=0x0c06d566u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c06d568;
P_0c06d568: /* original 2f26, guest PC 0x0c06d568 */
if(!s->budget--) { s->failed_pc=0x0c06d568u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06d56a;
P_0c06d56a: /* original 2fb6, guest PC 0x0c06d56a */
if(!s->budget--) { s->failed_pc=0x0c06d56au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06d56c;
P_0c06d56c: /* original 3c3c, guest PC 0x0c06d56c */
if(!s->budget--) { s->failed_pc=0x0c06d56cu; return 0; }
r[12]+=r[3];
goto P_0c06d56e;
P_0c06d56e: /* original 65f3, guest PC 0x0c06d56e */
if(!s->budget--) { s->failed_pc=0x0c06d56eu; return 0; }
r[5]=r[15];
goto P_0c06d570;
P_0c06d570: /* original 66f3, guest PC 0x0c06d570 */
if(!s->budget--) { s->failed_pc=0x0c06d570u; return 0; }
r[6]=r[15];
goto P_0c06d572;
P_0c06d572: /* original d315, guest PC 0x0c06d572 */
if(!s->budget--) { s->failed_pc=0x0c06d572u; return 0; }
r[3]=read(ram,0x0c06d5c8u,4);
goto P_0c06d574;
P_0c06d574: /* original 64f3, guest PC 0x0c06d574 */
if(!s->budget--) { s->failed_pc=0x0c06d574u; return 0; }
r[4]=r[15];
goto P_0c06d576;
P_0c06d576: /* original 7510, guest PC 0x0c06d576 */
if(!s->budget--) { s->failed_pc=0x0c06d576u; return 0; }
r[5]+=0x00000010u;
goto P_0c06d578;
P_0c06d578: /* original 67cf, guest PC 0x0c06d578 */
if(!s->budget--) { s->failed_pc=0x0c06d578u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c06d57a;
P_0c06d57a: /* original 7614, guest PC 0x0c06d57a */
if(!s->budget--) { s->failed_pc=0x0c06d57au; return 0; }
r[6]+=0x00000014u;
goto P_0c06d57c;
P_0c06d57c: /* original 430b, guest PC 0x0c06d57c */
if(!s->budget--) { s->failed_pc=0x0c06d57cu; return 0; }
target=r[3];
r[16]=code_base|0x0c06d580u;
r[4]+=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d580u) { target=s->pc; goto dispatch; }
goto P_0c06d580;
P_0c06d57e: /* original 740c, guest PC 0x0c06d57e */
if(!s->budget--) { s->failed_pc=0x0c06d57eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c06d580;
P_0c06d580: /* original a024, guest PC 0x0c06d580 */
if(!s->budget--) { s->failed_pc=0x0c06d580u; return 0; }
goto P_0c06d5cc;
P_0c06d582: /* original 0009, guest PC 0x0c06d582 */
if(!s->budget--) { s->failed_pc=0x0c06d582u; return 0; }
if(!vf3_matrix_family(0x0c06d584u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06d584u; return 0; } return 1;
P_0c06d5cc: /* original e004, guest PC 0x0c06d5cc */
if(!s->budget--) { s->failed_pc=0x0c06d5ccu; return 0; }
r[0]=0x00000004u;
goto P_0c06d5ce;
P_0c06d5ce: /* original 7f08, guest PC 0x0c06d5ce */
if(!s->budget--) { s->failed_pc=0x0c06d5ceu; return 0; }
r[15]+=0x00000008u;
goto P_0c06d5d0;
P_0c06d5d0: /* original f3f6, guest PC 0x0c06d5d0 */
if(!s->budget--) { s->failed_pc=0x0c06d5d0u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06d5d2;
P_0c06d5d2: /* original e018, guest PC 0x0c06d5d2 */
if(!s->budget--) { s->failed_pc=0x0c06d5d2u; return 0; }
r[0]=0x00000018u;
goto P_0c06d5d4;
P_0c06d5d4: /* original 64f3, guest PC 0x0c06d5d4 */
if(!s->budget--) { s->failed_pc=0x0c06d5d4u; return 0; }
r[4]=r[15];
goto P_0c06d5d6;
P_0c06d5d6: /* original 7418, guest PC 0x0c06d5d6 */
if(!s->budget--) { s->failed_pc=0x0c06d5d6u; return 0; }
r[4]+=0x00000018u;
goto P_0c06d5d8;
P_0c06d5d8: /* original ff37, guest PC 0x0c06d5d8 */
if(!s->budget--) { s->failed_pc=0x0c06d5d8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06d5da;
P_0c06d5da: /* original e008, guest PC 0x0c06d5da */
if(!s->budget--) { s->failed_pc=0x0c06d5dau; return 0; }
r[0]=0x00000008u;
goto P_0c06d5dc;
P_0c06d5dc: /* original f3f6, guest PC 0x0c06d5dc */
if(!s->budget--) { s->failed_pc=0x0c06d5dcu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06d5de;
P_0c06d5de: /* original e01c, guest PC 0x0c06d5de */
if(!s->budget--) { s->failed_pc=0x0c06d5deu; return 0; }
r[0]=0x0000001cu;
goto P_0c06d5e0;
P_0c06d5e0: /* original ff37, guest PC 0x0c06d5e0 */
if(!s->budget--) { s->failed_pc=0x0c06d5e0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06d5e2;
P_0c06d5e2: /* original e00c, guest PC 0x0c06d5e2 */
if(!s->budget--) { s->failed_pc=0x0c06d5e2u; return 0; }
r[0]=0x0000000cu;
goto P_0c06d5e4;
P_0c06d5e4: /* original f3f6, guest PC 0x0c06d5e4 */
if(!s->budget--) { s->failed_pc=0x0c06d5e4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06d5e6;
P_0c06d5e6: /* original e020, guest PC 0x0c06d5e6 */
if(!s->budget--) { s->failed_pc=0x0c06d5e6u; return 0; }
r[0]=0x00000020u;
goto P_0c06d5e8;
P_0c06d5e8: /* original ff37, guest PC 0x0c06d5e8 */
if(!s->budget--) { s->failed_pc=0x0c06d5e8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06d5ea;
P_0c06d5ea: /* original c74e, guest PC 0x0c06d5ea */
if(!s->budget--) { s->failed_pc=0x0c06d5eau; return 0; }
r[0]=code_base|0x0006d724u;
goto P_0c06d5ec;
P_0c06d5ec: /* original f308, guest PC 0x0c06d5ec */
if(!s->budget--) { s->failed_pc=0x0c06d5ecu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06d5ee;
P_0c06d5ee: /* original 9094, guest PC 0x0c06d5ee */
if(!s->budget--) { s->failed_pc=0x0c06d5eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d71au,2);
goto P_0c06d5f0;
P_0c06d5f0: /* original f5d6, guest PC 0x0c06d5f0 */
if(!s->budget--) { s->failed_pc=0x0c06d5f0u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c06d5f2;
P_0c06d5f2: /* original f530, guest PC 0x0c06d5f2 */
if(!s->budget--) { s->failed_pc=0x0c06d5f2u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c06d5f4;
P_0c06d5f4: /* original 480b, guest PC 0x0c06d5f4 */
if(!s->budget--) { s->failed_pc=0x0c06d5f4u; return 0; }
target=r[8];
r[16]=code_base|0x0c06d5f8u;
fr[4]=0x3f800000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d5f8u) { target=s->pc; goto dispatch; }
goto P_0c06d5f8;
P_0c06d5f6: /* original f49d, guest PC 0x0c06d5f6 */
if(!s->budget--) { s->failed_pc=0x0c06d5f6u; return 0; }
fr[4]=0x3f800000u;
goto P_0c06d5f8;
P_0c06d5f8: /* original 53f5, guest PC 0x0c06d5f8 */
if(!s->budget--) { s->failed_pc=0x0c06d5f8u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c06d5fa;
P_0c06d5fa: /* original 2338, guest PC 0x0c06d5fa */
if(!s->budget--) { s->failed_pc=0x0c06d5fau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06d5fc;
P_0c06d5fc: /* original 890d, guest PC 0x0c06d5fc */
if(!s->budget--) { s->failed_pc=0x0c06d5fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d61a; }
goto P_0c06d5fe;
P_0c06d5fe: /* original e01c, guest PC 0x0c06d5fe */
if(!s->budget--) { s->failed_pc=0x0c06d5feu; return 0; }
r[0]=0x0000001cu;
goto P_0c06d600;
P_0c06d600: /* original 03ec, guest PC 0x0c06d600 */
if(!s->budget--) { s->failed_pc=0x0c06d600u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06d602;
P_0c06d602: /* original de49, guest PC 0x0c06d602 */
if(!s->budget--) { s->failed_pc=0x0c06d602u; return 0; }
r[14]=read(ram,0x0c06d728u,4);
goto P_0c06d604;
P_0c06d604: /* original 633c, guest PC 0x0c06d604 */
if(!s->budget--) { s->failed_pc=0x0c06d604u; return 0; }
r[3]=r[3]&255u;
goto P_0c06d606;
P_0c06d606: /* original 4308, guest PC 0x0c06d606 */
if(!s->budget--) { s->failed_pc=0x0c06d606u; return 0; }
r[3]<<=2;
goto P_0c06d608;
P_0c06d608: /* original 4308, guest PC 0x0c06d608 */
if(!s->budget--) { s->failed_pc=0x0c06d608u; return 0; }
r[3]<<=2;
goto P_0c06d60a;
P_0c06d60a: /* original 4308, guest PC 0x0c06d60a */
if(!s->budget--) { s->failed_pc=0x0c06d60au; return 0; }
r[3]<<=2;
goto P_0c06d60c;
P_0c06d60c: /* original 3e3c, guest PC 0x0c06d60c */
if(!s->budget--) { s->failed_pc=0x0c06d60cu; return 0; }
r[14]+=r[3];
goto P_0c06d60e;
P_0c06d60e: /* original d347, guest PC 0x0c06d60e */
if(!s->budget--) { s->failed_pc=0x0c06d60eu; return 0; }
r[3]=read(ram,0x0c06d72cu,4);
goto P_0c06d610;
P_0c06d610: /* original 85e7, guest PC 0x0c06d610 */
if(!s->budget--) { s->failed_pc=0x0c06d610u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c06d612;
P_0c06d612: /* original 6503, guest PC 0x0c06d612 */
if(!s->budget--) { s->failed_pc=0x0c06d612u; return 0; }
r[5]=r[0];
goto P_0c06d614;
P_0c06d614: /* original 85e6, guest PC 0x0c06d614 */
if(!s->budget--) { s->failed_pc=0x0c06d614u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c06d616;
P_0c06d616: /* original 430b, guest PC 0x0c06d616 */
if(!s->budget--) { s->failed_pc=0x0c06d616u; return 0; }
target=r[3];
r[16]=code_base|0x0c06d61au;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d61au) { target=s->pc; goto dispatch; }
goto P_0c06d61a;
P_0c06d618: /* original 6403, guest PC 0x0c06d618 */
if(!s->budget--) { s->failed_pc=0x0c06d618u; return 0; }
r[4]=r[0];
goto P_0c06d61a;
P_0c06d61a: /* original 7f24, guest PC 0x0c06d61a */
if(!s->budget--) { s->failed_pc=0x0c06d61au; return 0; }
r[15]+=0x00000024u;
goto P_0c06d61c;
P_0c06d61c: /* original 4f26, guest PC 0x0c06d61c */
if(!s->budget--) { s->failed_pc=0x0c06d61cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06d61e;
P_0c06d61e: /* original 68f6, guest PC 0x0c06d61e */
if(!s->budget--) { s->failed_pc=0x0c06d61eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06d620;
P_0c06d620: /* original 69f6, guest PC 0x0c06d620 */
if(!s->budget--) { s->failed_pc=0x0c06d620u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06d622;
P_0c06d622: /* original 6af6, guest PC 0x0c06d622 */
if(!s->budget--) { s->failed_pc=0x0c06d622u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06d624;
P_0c06d624: /* original 6bf6, guest PC 0x0c06d624 */
if(!s->budget--) { s->failed_pc=0x0c06d624u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06d626;
P_0c06d626: /* original 6cf6, guest PC 0x0c06d626 */
if(!s->budget--) { s->failed_pc=0x0c06d626u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06d628;
P_0c06d628: /* original 6df6, guest PC 0x0c06d628 */
if(!s->budget--) { s->failed_pc=0x0c06d628u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06d62a;
P_0c06d62a: /* original 000b, guest PC 0x0c06d62a */
if(!s->budget--) { s->failed_pc=0x0c06d62au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06d62c: /* original 6ef6, guest PC 0x0c06d62c */
if(!s->budget--) { s->failed_pc=0x0c06d62cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06d62e;
P_0c06d62e: /* original 2fe6, guest PC 0x0c06d62e */
if(!s->budget--) { s->failed_pc=0x0c06d62eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06d630;
P_0c06d630: /* original 6e63, guest PC 0x0c06d630 */
if(!s->budget--) { s->failed_pc=0x0c06d630u; return 0; }
r[14]=r[6];
goto P_0c06d632;
P_0c06d632: /* original fffb, guest PC 0x0c06d632 */
if(!s->budget--) { s->failed_pc=0x0c06d632u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06d634;
P_0c06d634: /* original ffeb, guest PC 0x0c06d634 */
if(!s->budget--) { s->failed_pc=0x0c06d634u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06d636;
P_0c06d636: /* original 9071, guest PC 0x0c06d636 */
if(!s->budget--) { s->failed_pc=0x0c06d636u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d71cu,2);
goto P_0c06d638;
P_0c06d638: /* original 4f22, guest PC 0x0c06d638 */
if(!s->budget--) { s->failed_pc=0x0c06d638u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06d63a;
P_0c06d63a: /* original f346, guest PC 0x0c06d63a */
if(!s->budget--) { s->failed_pc=0x0c06d63au; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06d63c;
P_0c06d63c: /* original e004, guest PC 0x0c06d63c */
if(!s->budget--) { s->failed_pc=0x0c06d63cu; return 0; }
r[0]=0x00000004u;
goto P_0c06d63e;
P_0c06d63e: /* original 7ff4, guest PC 0x0c06d63e */
if(!s->budget--) { s->failed_pc=0x0c06d63eu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c06d640;
P_0c06d640: /* original ff37, guest PC 0x0c06d640 */
if(!s->budget--) { s->failed_pc=0x0c06d640u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06d642;
P_0c06d642: /* original 906c, guest PC 0x0c06d642 */
if(!s->budget--) { s->failed_pc=0x0c06d642u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d71eu,2);
goto P_0c06d644;
P_0c06d644: /* original f346, guest PC 0x0c06d644 */
if(!s->budget--) { s->failed_pc=0x0c06d644u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06d646;
P_0c06d646: /* original ff3a, guest PC 0x0c06d646 */
if(!s->budget--) { s->failed_pc=0x0c06d646u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c06d648;
P_0c06d648: /* original 906a, guest PC 0x0c06d648 */
if(!s->budget--) { s->failed_pc=0x0c06d648u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d720u,2);
goto P_0c06d64a;
P_0c06d64a: /* original f346, guest PC 0x0c06d64a */
if(!s->budget--) { s->failed_pc=0x0c06d64au; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06d64c;
P_0c06d64c: /* original e008, guest PC 0x0c06d64c */
if(!s->budget--) { s->failed_pc=0x0c06d64cu; return 0; }
r[0]=0x00000008u;
goto P_0c06d64e;
P_0c06d64e: /* original f34d, guest PC 0x0c06d64e */
if(!s->budget--) { s->failed_pc=0x0c06d64eu; return 0; }
fr[3]^=0x80000000u;
goto P_0c06d650;
P_0c06d650: /* original ff37, guest PC 0x0c06d650 */
if(!s->budget--) { s->failed_pc=0x0c06d650u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06d652;
P_0c06d652: /* original f68d, guest PC 0x0c06d652 */
if(!s->budget--) { s->failed_pc=0x0c06d652u; return 0; }
fr[6]=0;
goto P_0c06d654;
P_0c06d654: /* original f76c, guest PC 0x0c06d654 */
if(!s->budget--) { s->failed_pc=0x0c06d654u; return 0; }
vf3_matrix_move(s,7,6);
goto P_0c06d656;
P_0c06d656: /* original f56c, guest PC 0x0c06d656 */
if(!s->budget--) { s->failed_pc=0x0c06d656u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c06d658;
P_0c06d658: /* original e004, guest PC 0x0c06d658 */
if(!s->budget--) { s->failed_pc=0x0c06d658u; return 0; }
r[0]=0x00000004u;
goto P_0c06d65a;
P_0c06d65a: /* original faf8, guest PC 0x0c06d65a */
if(!s->budget--) { s->failed_pc=0x0c06d65au; return 0; }
vf3_matrix_load(s,ram,10,r[15]);
goto P_0c06d65c;
P_0c06d65c: /* original f356, guest PC 0x0c06d65c */
if(!s->budget--) { s->failed_pc=0x0c06d65cu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c06d65e;
P_0c06d65e: /* original e004, guest PC 0x0c06d65e */
if(!s->budget--) { s->failed_pc=0x0c06d65eu; return 0; }
r[0]=0x00000004u;
goto P_0c06d660;
P_0c06d660: /* original fbf6, guest PC 0x0c06d660 */
if(!s->budget--) { s->failed_pc=0x0c06d660u; return 0; }
vf3_matrix_load(s,ram,11,r[15]+r[0]);
goto P_0c06d662;
P_0c06d662: /* original e008, guest PC 0x0c06d662 */
if(!s->budget--) { s->failed_pc=0x0c06d662u; return 0; }
r[0]=0x00000008u;
goto P_0c06d664;
P_0c06d664: /* original fe9d, guest PC 0x0c06d664 */
if(!s->budget--) { s->failed_pc=0x0c06d664u; return 0; }
fr[14]=0x3f800000u;
goto P_0c06d666;
P_0c06d666: /* original fb31, guest PC 0x0c06d666 */
if(!s->budget--) { s->failed_pc=0x0c06d666u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[3],r[18],'-');
goto P_0c06d668;
P_0c06d668: /* original f356, guest PC 0x0c06d668 */
if(!s->budget--) { s->failed_pc=0x0c06d668u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c06d66a;
P_0c06d66a: /* original e00c, guest PC 0x0c06d66a */
if(!s->budget--) { s->failed_pc=0x0c06d66au; return 0; }
r[0]=0x0000000cu;
goto P_0c06d66c;
P_0c06d66c: /* original f858, guest PC 0x0c06d66c */
if(!s->budget--) { s->failed_pc=0x0c06d66cu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
goto P_0c06d66e;
P_0c06d66e: /* original fa31, guest PC 0x0c06d66e */
if(!s->budget--) { s->failed_pc=0x0c06d66eu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[3],r[18],'-');
goto P_0c06d670;
P_0c06d670: /* original f356, guest PC 0x0c06d670 */
if(!s->budget--) { s->failed_pc=0x0c06d670u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c06d672;
P_0c06d672: /* original e008, guest PC 0x0c06d672 */
if(!s->budget--) { s->failed_pc=0x0c06d672u; return 0; }
r[0]=0x00000008u;
goto P_0c06d674;
P_0c06d674: /* original f4bc, guest PC 0x0c06d674 */
if(!s->budget--) { s->failed_pc=0x0c06d674u; return 0; }
vf3_matrix_move(s,4,11);
goto P_0c06d676;
P_0c06d676: /* original f4b2, guest PC 0x0c06d676 */
if(!s->budget--) { s->failed_pc=0x0c06d676u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[11],r[18],'*');
goto P_0c06d678;
P_0c06d678: /* original f9f6, guest PC 0x0c06d678 */
if(!s->budget--) { s->failed_pc=0x0c06d678u; return 0; }
vf3_matrix_load(s,ram,9,r[15]+r[0]);
goto P_0c06d67a;
P_0c06d67a: /* original f0ac, guest PC 0x0c06d67a */
if(!s->budget--) { s->failed_pc=0x0c06d67au; return 0; }
vf3_matrix_move(s,0,10);
goto P_0c06d67c;
P_0c06d67c: /* original f931, guest PC 0x0c06d67c */
if(!s->budget--) { s->failed_pc=0x0c06d67cu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'-');
goto P_0c06d67e;
P_0c06d67e: /* original f34c, guest PC 0x0c06d67e */
if(!s->budget--) { s->failed_pc=0x0c06d67eu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c06d680;
P_0c06d680: /* original f3ae, guest PC 0x0c06d680 */
if(!s->budget--) { s->failed_pc=0x0c06d680u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[10],fr[3],r[18]);
goto P_0c06d682;
P_0c06d682: /* original f09c, guest PC 0x0c06d682 */
if(!s->budget--) { s->failed_pc=0x0c06d682u; return 0; }
vf3_matrix_move(s,0,9);
goto P_0c06d684;
P_0c06d684: /* original f23c, guest PC 0x0c06d684 */
if(!s->budget--) { s->failed_pc=0x0c06d684u; return 0; }
vf3_matrix_move(s,2,3);
goto P_0c06d686;
P_0c06d686: /* original f29e, guest PC 0x0c06d686 */
if(!s->budget--) { s->failed_pc=0x0c06d686u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[9],fr[2],r[18]);
goto P_0c06d688;
P_0c06d688: /* original f0bc, guest PC 0x0c06d688 */
if(!s->budget--) { s->failed_pc=0x0c06d688u; return 0; }
vf3_matrix_move(s,0,11);
goto P_0c06d68a;
P_0c06d68a: /* original f42c, guest PC 0x0c06d68a */
if(!s->budget--) { s->failed_pc=0x0c06d68au; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c06d68c;
P_0c06d68c: /* original f4e0, guest PC 0x0c06d68c */
if(!s->budget--) { s->failed_pc=0x0c06d68cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'+');
goto P_0c06d68e;
P_0c06d68e: /* original f25c, guest PC 0x0c06d68e */
if(!s->budget--) { s->failed_pc=0x0c06d68eu; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c06d690;
P_0c06d690: /* original f34c, guest PC 0x0c06d690 */
if(!s->budget--) { s->failed_pc=0x0c06d690u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c06d692;
P_0c06d692: /* original f432, guest PC 0x0c06d692 */
if(!s->budget--) { s->failed_pc=0x0c06d692u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c06d694;
P_0c06d694: /* original f843, guest PC 0x0c06d694 */
if(!s->budget--) { s->failed_pc=0x0c06d694u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'/');
goto P_0c06d696;
P_0c06d696: /* original f28e, guest PC 0x0c06d696 */
if(!s->budget--) { s->failed_pc=0x0c06d696u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c06d698;
P_0c06d698: /* original f0ac, guest PC 0x0c06d698 */
if(!s->budget--) { s->failed_pc=0x0c06d698u; return 0; }
vf3_matrix_move(s,0,10);
goto P_0c06d69a;
P_0c06d69a: /* original 7510, guest PC 0x0c06d69a */
if(!s->budget--) { s->failed_pc=0x0c06d69au; return 0; }
r[5]+=0x00000010u;
goto P_0c06d69c;
P_0c06d69c: /* original f37c, guest PC 0x0c06d69c */
if(!s->budget--) { s->failed_pc=0x0c06d69cu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c06d69e;
P_0c06d69e: /* original f38e, guest PC 0x0c06d69e */
if(!s->budget--) { s->failed_pc=0x0c06d69eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[8],fr[3],r[18]);
goto P_0c06d6a0;
P_0c06d6a0: /* original f52c, guest PC 0x0c06d6a0 */
if(!s->budget--) { s->failed_pc=0x0c06d6a0u; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c06d6a2;
P_0c06d6a2: /* original f09c, guest PC 0x0c06d6a2 */
if(!s->budget--) { s->failed_pc=0x0c06d6a2u; return 0; }
vf3_matrix_move(s,0,9);
goto P_0c06d6a4;
P_0c06d6a4: /* original f26c, guest PC 0x0c06d6a4 */
if(!s->budget--) { s->failed_pc=0x0c06d6a4u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c06d6a6;
P_0c06d6a6: /* original f28e, guest PC 0x0c06d6a6 */
if(!s->budget--) { s->failed_pc=0x0c06d6a6u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c06d6a8;
P_0c06d6a8: /* original 6052, guest PC 0x0c06d6a8 */
if(!s->budget--) { s->failed_pc=0x0c06d6a8u; return 0; }
tmp=read(ram,r[5],4);
r[0]=tmp;
goto P_0c06d6aa;
P_0c06d6aa: /* original f73c, guest PC 0x0c06d6aa */
if(!s->budget--) { s->failed_pc=0x0c06d6aau; return 0; }
vf3_matrix_move(s,7,3);
goto P_0c06d6ac;
P_0c06d6ac: /* original 88ff, guest PC 0x0c06d6ac */
if(!s->budget--) { s->failed_pc=0x0c06d6acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c06d6ae;
P_0c06d6ae: /* original 8fd3, guest PC 0x0c06d6ae */
if(!s->budget--) { s->failed_pc=0x0c06d6aeu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,6,2);
if(!cond) { goto P_0c06d658; }
goto P_0c06d6b2;
P_0c06d6b0: /* original f62c, guest PC 0x0c06d6b0 */
if(!s->budget--) { s->failed_pc=0x0c06d6b0u; return 0; }
vf3_matrix_move(s,6,2);
goto P_0c06d6b2;
P_0c06d6b2: /* original ff5c, guest PC 0x0c06d6b2 */
if(!s->budget--) { s->failed_pc=0x0c06d6b2u; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c06d6b4;
P_0c06d6b4: /* original ff52, guest PC 0x0c06d6b4 */
if(!s->budget--) { s->failed_pc=0x0c06d6b4u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[5],r[18],'*');
goto P_0c06d6b6;
P_0c06d6b6: /* original f07c, guest PC 0x0c06d6b6 */
if(!s->budget--) { s->failed_pc=0x0c06d6b6u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c06d6b8;
P_0c06d6b8: /* original c71d, guest PC 0x0c06d6b8 */
if(!s->budget--) { s->failed_pc=0x0c06d6b8u; return 0; }
r[0]=code_base|0x0006d730u;
goto P_0c06d6ba;
P_0c06d6ba: /* original f3fc, guest PC 0x0c06d6ba */
if(!s->budget--) { s->failed_pc=0x0c06d6bau; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c06d6bc;
P_0c06d6bc: /* original f37e, guest PC 0x0c06d6bc */
if(!s->budget--) { s->failed_pc=0x0c06d6bcu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[7],fr[3],r[18]);
goto P_0c06d6be;
P_0c06d6be: /* original f06c, guest PC 0x0c06d6be */
if(!s->budget--) { s->failed_pc=0x0c06d6beu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c06d6c0;
P_0c06d6c0: /* original f23c, guest PC 0x0c06d6c0 */
if(!s->budget--) { s->failed_pc=0x0c06d6c0u; return 0; }
vf3_matrix_move(s,2,3);
goto P_0c06d6c2;
P_0c06d6c2: /* original f26e, guest PC 0x0c06d6c2 */
if(!s->budget--) { s->failed_pc=0x0c06d6c2u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[6],fr[2],r[18]);
goto P_0c06d6c4;
P_0c06d6c4: /* original f308, guest PC 0x0c06d6c4 */
if(!s->budget--) { s->failed_pc=0x0c06d6c4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06d6c6;
P_0c06d6c6: /* original ff2c, guest PC 0x0c06d6c6 */
if(!s->budget--) { s->failed_pc=0x0c06d6c6u; return 0; }
vf3_matrix_move(s,15,2);
goto P_0c06d6c8;
P_0c06d6c8: /* original f3f5, guest PC 0x0c06d6c8 */
if(!s->budget--) { s->failed_pc=0x0c06d6c8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c06d6ca;
P_0c06d6ca: /* original 8b01, guest PC 0x0c06d6ca */
if(!s->budget--) { s->failed_pc=0x0c06d6cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d6d0; }
goto P_0c06d6cc;
P_0c06d6cc: /* original a002, guest PC 0x0c06d6cc */
if(!s->budget--) { s->failed_pc=0x0c06d6ccu; return 0; }
fr[4]=0;
goto P_0c06d6d4;
P_0c06d6ce: /* original f48d, guest PC 0x0c06d6ce */
if(!s->budget--) { s->failed_pc=0x0c06d6ceu; return 0; }
fr[4]=0;
goto P_0c06d6d0;
P_0c06d6d0: /* original f4fc, guest PC 0x0c06d6d0 */
if(!s->budget--) { s->failed_pc=0x0c06d6d0u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c06d6d2;
P_0c06d6d2: /* original f47d, guest PC 0x0c06d6d2 */
if(!s->budget--) { s->failed_pc=0x0c06d6d2u; return 0; }
if(!vf3_fpu_fsrra(fr[4],r[18],&fr[4])) goto unsupported;
goto P_0c06d6d4;
P_0c06d6d4: /* original f742, guest PC 0x0c06d6d4 */
if(!s->budget--) { s->failed_pc=0x0c06d6d4u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c06d6d6;
P_0c06d6d6: /* original e004, guest PC 0x0c06d6d6 */
if(!s->budget--) { s->failed_pc=0x0c06d6d6u; return 0; }
r[0]=0x00000004u;
goto P_0c06d6d8;
P_0c06d6d8: /* original f642, guest PC 0x0c06d6d8 */
if(!s->budget--) { s->failed_pc=0x0c06d6d8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c06d6da;
P_0c06d6da: /* original f542, guest PC 0x0c06d6da */
if(!s->budget--) { s->failed_pc=0x0c06d6dau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c06d6dc;
P_0c06d6dc: /* original fe5a, guest PC 0x0c06d6dc */
if(!s->budget--) { s->failed_pc=0x0c06d6dcu; return 0; }
vf3_matrix_store(s,ram,5,r[14]);
goto P_0c06d6de;
P_0c06d6de: /* original fe77, guest PC 0x0c06d6de */
if(!s->budget--) { s->failed_pc=0x0c06d6deu; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c06d6e0;
P_0c06d6e0: /* original e008, guest PC 0x0c06d6e0 */
if(!s->budget--) { s->failed_pc=0x0c06d6e0u; return 0; }
r[0]=0x00000008u;
goto P_0c06d6e2;
P_0c06d6e2: /* original fe67, guest PC 0x0c06d6e2 */
if(!s->budget--) { s->failed_pc=0x0c06d6e2u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c06d6e4;
P_0c06d6e4: /* original d313, guest PC 0x0c06d6e4 */
if(!s->budget--) { s->failed_pc=0x0c06d6e4u; return 0; }
r[3]=read(ram,0x0c06d734u,4);
goto P_0c06d6e6;
P_0c06d6e6: /* original 430b, guest PC 0x0c06d6e6 */
if(!s->budget--) { s->failed_pc=0x0c06d6e6u; return 0; }
target=r[3];
r[16]=code_base|0x0c06d6eau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d6eau) { target=s->pc; goto dispatch; }
goto P_0c06d6ea;
P_0c06d6e8: /* original 64e3, guest PC 0x0c06d6e8 */
if(!s->budget--) { s->failed_pc=0x0c06d6e8u; return 0; }
r[4]=r[14];
goto P_0c06d6ea;
P_0c06d6ea: /* original ffe5, guest PC 0x0c06d6ea */
if(!s->budget--) { s->failed_pc=0x0c06d6eau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[14]))!=0);
goto P_0c06d6ec;
P_0c06d6ec: /* original 8b01, guest PC 0x0c06d6ec */
if(!s->budget--) { s->failed_pc=0x0c06d6ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d6f2; }
goto P_0c06d6ee;
P_0c06d6ee: /* original a005, guest PC 0x0c06d6ee */
if(!s->budget--) { s->failed_pc=0x0c06d6eeu; return 0; }
vf3_matrix_move(s,15,14);
goto P_0c06d6fc;
P_0c06d6f0: /* original ffec, guest PC 0x0c06d6f0 */
if(!s->budget--) { s->failed_pc=0x0c06d6f0u; return 0; }
vf3_matrix_move(s,15,14);
goto P_0c06d6f2;
P_0c06d6f2: /* original c711, guest PC 0x0c06d6f2 */
if(!s->budget--) { s->failed_pc=0x0c06d6f2u; return 0; }
r[0]=code_base|0x0006d738u;
goto P_0c06d6f4;
P_0c06d6f4: /* original f408, guest PC 0x0c06d6f4 */
if(!s->budget--) { s->failed_pc=0x0c06d6f4u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c06d6f6;
P_0c06d6f6: /* original f4f5, guest PC 0x0c06d6f6 */
if(!s->budget--) { s->failed_pc=0x0c06d6f6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[15]))!=0);
goto P_0c06d6f8;
P_0c06d6f8: /* original 8b00, guest PC 0x0c06d6f8 */
if(!s->budget--) { s->failed_pc=0x0c06d6f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d6fc; }
goto P_0c06d6fa;
P_0c06d6fa: /* original ff4c, guest PC 0x0c06d6fa */
if(!s->budget--) { s->failed_pc=0x0c06d6fau; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c06d6fc;
P_0c06d6fc: /* original 7f0c, guest PC 0x0c06d6fc */
if(!s->budget--) { s->failed_pc=0x0c06d6fcu; return 0; }
r[15]+=0x0000000cu;
goto P_0c06d6fe;
P_0c06d6fe: /* original f0fc, guest PC 0x0c06d6fe */
if(!s->budget--) { s->failed_pc=0x0c06d6feu; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c06d700;
P_0c06d700: /* original 4f26, guest PC 0x0c06d700 */
if(!s->budget--) { s->failed_pc=0x0c06d700u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06d702;
P_0c06d702: /* original fef9, guest PC 0x0c06d702 */
if(!s->budget--) { s->failed_pc=0x0c06d702u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06d704;
P_0c06d704: /* original fff9, guest PC 0x0c06d704 */
if(!s->budget--) { s->failed_pc=0x0c06d704u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06d706;
P_0c06d706: /* original 000b, guest PC 0x0c06d706 */
if(!s->budget--) { s->failed_pc=0x0c06d706u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06d708: /* original 6ef6, guest PC 0x0c06d708 */
if(!s->budget--) { s->failed_pc=0x0c06d708u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06d70au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06d70au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
