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
int vf3_away_batch4_adapter_16(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04d448u: goto P_0c04d448;
case 0x0c04d44au: goto P_0c04d44a;
case 0x0c04d44cu: goto P_0c04d44c;
case 0x0c04d44eu: goto P_0c04d44e;
case 0x0c04d450u: goto P_0c04d450;
case 0x0c04d452u: goto P_0c04d452;
case 0x0c04d454u: goto P_0c04d454;
case 0x0c04d456u: goto P_0c04d456;
case 0x0c04d458u: goto P_0c04d458;
case 0x0c04d45au: goto P_0c04d45a;
case 0x0c04d45cu: goto P_0c04d45c;
case 0x0c04d45eu: goto P_0c04d45e;
case 0x0c04d460u: goto P_0c04d460;
case 0x0c04d462u: goto P_0c04d462;
case 0x0c04d464u: goto P_0c04d464;
case 0x0c04d466u: goto P_0c04d466;
case 0x0c04d468u: goto P_0c04d468;
case 0x0c04d46au: goto P_0c04d46a;
case 0x0c04d46cu: goto P_0c04d46c;
case 0x0c04d46eu: goto P_0c04d46e;
case 0x0c04d470u: goto P_0c04d470;
case 0x0c04d472u: goto P_0c04d472;
case 0x0c04d474u: goto P_0c04d474;
case 0x0c04d476u: goto P_0c04d476;
case 0x0c04d478u: goto P_0c04d478;
case 0x0c04d47au: goto P_0c04d47a;
case 0x0c04d47cu: goto P_0c04d47c;
case 0x0c04d47eu: goto P_0c04d47e;
case 0x0c04d480u: goto P_0c04d480;
case 0x0c04d482u: goto P_0c04d482;
case 0x0c04d484u: goto P_0c04d484;
case 0x0c04d486u: goto P_0c04d486;
case 0x0c04d488u: goto P_0c04d488;
case 0x0c04d48au: goto P_0c04d48a;
case 0x0c04d48cu: goto P_0c04d48c;
case 0x0c04d48eu: goto P_0c04d48e;
case 0x0c04d490u: goto P_0c04d490;
case 0x0c04d492u: goto P_0c04d492;
case 0x0c04d494u: goto P_0c04d494;
case 0x0c04d496u: goto P_0c04d496;
case 0x0c04d498u: goto P_0c04d498;
case 0x0c04d49au: goto P_0c04d49a;
case 0x0c04d49cu: goto P_0c04d49c;
case 0x0c04d49eu: goto P_0c04d49e;
case 0x0c04d4a0u: goto P_0c04d4a0;
case 0x0c04d4a2u: goto P_0c04d4a2;
case 0x0c04d4a4u: goto P_0c04d4a4;
case 0x0c04d4a6u: goto P_0c04d4a6;
case 0x0c04d4a8u: goto P_0c04d4a8;
case 0x0c04d4aau: goto P_0c04d4aa;
case 0x0c04d4acu: goto P_0c04d4ac;
case 0x0c04d4aeu: goto P_0c04d4ae;
case 0x0c04d4b0u: goto P_0c04d4b0;
case 0x0c04d4b2u: goto P_0c04d4b2;
case 0x0c04d4b4u: goto P_0c04d4b4;
case 0x0c04d4b6u: goto P_0c04d4b6;
case 0x0c04d4b8u: goto P_0c04d4b8;
case 0x0c04d4bau: goto P_0c04d4ba;
case 0x0c04d4bcu: goto P_0c04d4bc;
case 0x0c04d4beu: goto P_0c04d4be;
case 0x0c04d4c0u: goto P_0c04d4c0;
case 0x0c04d4c2u: goto P_0c04d4c2;
case 0x0c04d4c4u: goto P_0c04d4c4;
case 0x0c04d4c6u: goto P_0c04d4c6;
case 0x0c04d4c8u: goto P_0c04d4c8;
case 0x0c04d4cau: goto P_0c04d4ca;
case 0x0c04d4ccu: goto P_0c04d4cc;
case 0x0c04d4ceu: goto P_0c04d4ce;
case 0x0c04d4d0u: goto P_0c04d4d0;
case 0x0c04d4d2u: goto P_0c04d4d2;
case 0x0c04d4d4u: goto P_0c04d4d4;
case 0x0c04d4d6u: goto P_0c04d4d6;
case 0x0c04d4d8u: goto P_0c04d4d8;
case 0x0c04d4dau: goto P_0c04d4da;
case 0x0c04d4dcu: goto P_0c04d4dc;
case 0x0c04d4deu: goto P_0c04d4de;
case 0x0c04d4e0u: goto P_0c04d4e0;
case 0x0c04d4e2u: goto P_0c04d4e2;
case 0x0c04d4e4u: goto P_0c04d4e4;
case 0x0c04d4e6u: goto P_0c04d4e6;
case 0x0c04d4e8u: goto P_0c04d4e8;
case 0x0c04d4eau: goto P_0c04d4ea;
case 0x0c04d4ecu: goto P_0c04d4ec;
case 0x0c04d4eeu: goto P_0c04d4ee;
case 0x0c04d4f0u: goto P_0c04d4f0;
case 0x0c04d4f2u: goto P_0c04d4f2;
case 0x0c04d4f4u: goto P_0c04d4f4;
case 0x0c04d4f6u: goto P_0c04d4f6;
case 0x0c04d4f8u: goto P_0c04d4f8;
case 0x0c04d4fau: goto P_0c04d4fa;
case 0x0c04d4fcu: goto P_0c04d4fc;
case 0x0c04d4feu: goto P_0c04d4fe;
case 0x0c04d500u: goto P_0c04d500;
case 0x0c04d502u: goto P_0c04d502;
case 0x0c04d504u: goto P_0c04d504;
case 0x0c04d506u: goto P_0c04d506;
case 0x0c04d508u: goto P_0c04d508;
case 0x0c04d50au: goto P_0c04d50a;
case 0x0c04d50cu: goto P_0c04d50c;
case 0x0c04d50eu: goto P_0c04d50e;
case 0x0c04d510u: goto P_0c04d510;
case 0x0c04d512u: goto P_0c04d512;
case 0x0c04d514u: goto P_0c04d514;
case 0x0c04d516u: goto P_0c04d516;
case 0x0c04d518u: goto P_0c04d518;
case 0x0c04d51au: goto P_0c04d51a;
case 0x0c04d51cu: goto P_0c04d51c;
case 0x0c04d51eu: goto P_0c04d51e;
case 0x0c04d520u: goto P_0c04d520;
case 0x0c04d522u: goto P_0c04d522;
case 0x0c04d524u: goto P_0c04d524;
case 0x0c04d526u: goto P_0c04d526;
case 0x0c04d528u: goto P_0c04d528;
case 0x0c04d52au: goto P_0c04d52a;
case 0x0c04d52cu: goto P_0c04d52c;
case 0x0c04d52eu: goto P_0c04d52e;
case 0x0c04d530u: goto P_0c04d530;
case 0x0c04d532u: goto P_0c04d532;
case 0x0c04d534u: goto P_0c04d534;
case 0x0c04d536u: goto P_0c04d536;
case 0x0c04d538u: goto P_0c04d538;
case 0x0c04d53au: goto P_0c04d53a;
case 0x0c04d53cu: goto P_0c04d53c;
case 0x0c04d53eu: goto P_0c04d53e;
case 0x0c04d540u: goto P_0c04d540;
case 0x0c04d542u: goto P_0c04d542;
case 0x0c04d544u: goto P_0c04d544;
case 0x0c04d546u: goto P_0c04d546;
case 0x0c04d548u: goto P_0c04d548;
case 0x0c04d54au: goto P_0c04d54a;
case 0x0c04d54cu: goto P_0c04d54c;
case 0x0c04d560u: goto P_0c04d560;
case 0x0c04d562u: goto P_0c04d562;
case 0x0c04d564u: goto P_0c04d564;
case 0x0c04d566u: goto P_0c04d566;
case 0x0c04d568u: goto P_0c04d568;
case 0x0c04d56au: goto P_0c04d56a;
case 0x0c04d56cu: goto P_0c04d56c;
case 0x0c04d56eu: goto P_0c04d56e;
case 0x0c04d570u: goto P_0c04d570;
case 0x0c04d572u: goto P_0c04d572;
case 0x0c04d574u: goto P_0c04d574;
case 0x0c04d576u: goto P_0c04d576;
case 0x0c04d578u: goto P_0c04d578;
case 0x0c04d57au: goto P_0c04d57a;
case 0x0c04d57cu: goto P_0c04d57c;
case 0x0c04d57eu: goto P_0c04d57e;
case 0x0c04d580u: goto P_0c04d580;
case 0x0c04d582u: goto P_0c04d582;
case 0x0c04d584u: goto P_0c04d584;
case 0x0c04d586u: goto P_0c04d586;
case 0x0c04d588u: goto P_0c04d588;
case 0x0c04d58au: goto P_0c04d58a;
case 0x0c04d58cu: goto P_0c04d58c;
case 0x0c04d58eu: goto P_0c04d58e;
case 0x0c04d590u: goto P_0c04d590;
case 0x0c04d592u: goto P_0c04d592;
case 0x0c04d594u: goto P_0c04d594;
case 0x0c04d596u: goto P_0c04d596;
case 0x0c04d598u: goto P_0c04d598;
case 0x0c04d59au: goto P_0c04d59a;
case 0x0c04d59cu: goto P_0c04d59c;
case 0x0c04d59eu: goto P_0c04d59e;
case 0x0c04d5a0u: goto P_0c04d5a0;
case 0x0c04d5a2u: goto P_0c04d5a2;
case 0x0c04d5a4u: goto P_0c04d5a4;
case 0x0c04d5a6u: goto P_0c04d5a6;
case 0x0c04d5a8u: goto P_0c04d5a8;
case 0x0c04d5aau: goto P_0c04d5aa;
case 0x0c04d5acu: goto P_0c04d5ac;
case 0x0c04d5aeu: goto P_0c04d5ae;
case 0x0c04d5b0u: goto P_0c04d5b0;
case 0x0c04d5b2u: goto P_0c04d5b2;
case 0x0c04d5b4u: goto P_0c04d5b4;
case 0x0c04d5b6u: goto P_0c04d5b6;
case 0x0c04d5b8u: goto P_0c04d5b8;
case 0x0c04d5bau: goto P_0c04d5ba;
case 0x0c04d5bcu: goto P_0c04d5bc;
case 0x0c04d5beu: goto P_0c04d5be;
case 0x0c04d5c0u: goto P_0c04d5c0;
case 0x0c04d5c2u: goto P_0c04d5c2;
case 0x0c04d5c4u: goto P_0c04d5c4;
case 0x0c04d5c6u: goto P_0c04d5c6;
case 0x0c04d5c8u: goto P_0c04d5c8;
case 0x0c04d5cau: goto P_0c04d5ca;
case 0x0c04d5ccu: goto P_0c04d5cc;
case 0x0c04d5ceu: goto P_0c04d5ce;
case 0x0c04d5d0u: goto P_0c04d5d0;
case 0x0c04d5d2u: goto P_0c04d5d2;
case 0x0c04d5d4u: goto P_0c04d5d4;
case 0x0c04d5d6u: goto P_0c04d5d6;
case 0x0c04d5d8u: goto P_0c04d5d8;
case 0x0c04d5dau: goto P_0c04d5da;
case 0x0c04d5dcu: goto P_0c04d5dc;
case 0x0c04d5deu: goto P_0c04d5de;
case 0x0c04d5e0u: goto P_0c04d5e0;
case 0x0c04d5e2u: goto P_0c04d5e2;
case 0x0c04d5e4u: goto P_0c04d5e4;
case 0x0c04d5e6u: goto P_0c04d5e6;
case 0x0c04d5e8u: goto P_0c04d5e8;
case 0x0c04d5eau: goto P_0c04d5ea;
case 0x0c04d5ecu: goto P_0c04d5ec;
case 0x0c04d5eeu: goto P_0c04d5ee;
case 0x0c04d5f0u: goto P_0c04d5f0;
case 0x0c04d5f2u: goto P_0c04d5f2;
case 0x0c04d5f4u: goto P_0c04d5f4;
case 0x0c04d5f6u: goto P_0c04d5f6;
case 0x0c04d5f8u: goto P_0c04d5f8;
case 0x0c04d5fau: goto P_0c04d5fa;
case 0x0c04d5fcu: goto P_0c04d5fc;
case 0x0c04d5feu: goto P_0c04d5fe;
case 0x0c04d600u: goto P_0c04d600;
case 0x0c04d602u: goto P_0c04d602;
case 0x0c04d604u: goto P_0c04d604;
case 0x0c04d606u: goto P_0c04d606;
case 0x0c04d608u: goto P_0c04d608;
case 0x0c04d60au: goto P_0c04d60a;
case 0x0c04d60cu: goto P_0c04d60c;
case 0x0c04d60eu: goto P_0c04d60e;
case 0x0c04d610u: goto P_0c04d610;
case 0x0c04d612u: goto P_0c04d612;
case 0x0c04d614u: goto P_0c04d614;
case 0x0c04d616u: goto P_0c04d616;
case 0x0c04d618u: goto P_0c04d618;
case 0x0c04d61au: goto P_0c04d61a;
case 0x0c04d61cu: goto P_0c04d61c;
case 0x0c04d61eu: goto P_0c04d61e;
case 0x0c04d620u: goto P_0c04d620;
case 0x0c04d622u: goto P_0c04d622;
case 0x0c04d624u: goto P_0c04d624;
case 0x0c04d626u: goto P_0c04d626;
case 0x0c04d628u: goto P_0c04d628;
case 0x0c04d62au: goto P_0c04d62a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04d448: /* original 2fe6, guest PC 0x0c04d448 */
if(!s->budget--) { s->failed_pc=0x0c04d448u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d44a;
P_0c04d44a: /* original 6e43, guest PC 0x0c04d44a */
if(!s->budget--) { s->failed_pc=0x0c04d44au; return 0; }
r[14]=r[4];
goto P_0c04d44c;
P_0c04d44c: /* original 2fd6, guest PC 0x0c04d44c */
if(!s->budget--) { s->failed_pc=0x0c04d44cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d44e;
P_0c04d44e: /* original 6053, guest PC 0x0c04d44e */
if(!s->budget--) { s->failed_pc=0x0c04d44eu; return 0; }
r[0]=r[5];
goto P_0c04d450;
P_0c04d450: /* original 4f22, guest PC 0x0c04d450 */
if(!s->budget--) { s->failed_pc=0x0c04d450u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04d452;
P_0c04d452: /* original 4f12, guest PC 0x0c04d452 */
if(!s->budget--) { s->failed_pc=0x0c04d452u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04d454;
P_0c04d454: /* original 7ff8, guest PC 0x0c04d454 */
if(!s->budget--) { s->failed_pc=0x0c04d454u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c04d456;
P_0c04d456: /* original 81f2, guest PC 0x0c04d456 */
if(!s->budget--) { s->failed_pc=0x0c04d456u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c04d458;
P_0c04d458: /* original 9d79, guest PC 0x0c04d458 */
if(!s->budget--) { s->failed_pc=0x0c04d458u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d54eu,2);
goto P_0c04d45a;
P_0c04d45a: /* original d33d, guest PC 0x0c04d45a */
if(!s->budget--) { s->failed_pc=0x0c04d45au; return 0; }
r[3]=read(ram,0x0c04d550u,4);
goto P_0c04d45c;
P_0c04d45c: /* original 2edf, guest PC 0x0c04d45c */
if(!s->budget--) { s->failed_pc=0x0c04d45cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[13]);
goto P_0c04d45e;
P_0c04d45e: /* original 85f2, guest PC 0x0c04d45e */
if(!s->budget--) { s->failed_pc=0x0c04d45eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c04d460;
P_0c04d460: /* original 0d1a, guest PC 0x0c04d460 */
if(!s->budget--) { s->failed_pc=0x0c04d460u; return 0; }
r[13]=r[19];
goto P_0c04d462;
P_0c04d462: /* original 6ddf, guest PC 0x0c04d462 */
if(!s->budget--) { s->failed_pc=0x0c04d462u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c04d464;
P_0c04d464: /* original 3d3c, guest PC 0x0c04d464 */
if(!s->budget--) { s->failed_pc=0x0c04d464u; return 0; }
r[13]+=r[3];
goto P_0c04d466;
P_0c04d466: /* original 54d7, guest PC 0x0c04d466 */
if(!s->budget--) { s->failed_pc=0x0c04d466u; return 0; }
r[4]=read(ram,r[13]+28,4);
goto P_0c04d468;
P_0c04d468: /* original 5542, guest PC 0x0c04d468 */
if(!s->budget--) { s->failed_pc=0x0c04d468u; return 0; }
r[5]=read(ram,r[4]+8,4);
goto P_0c04d46a;
P_0c04d46a: /* original 5244, guest PC 0x0c04d46a */
if(!s->budget--) { s->failed_pc=0x0c04d46au; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c04d46c;
P_0c04d46c: /* original 3528, guest PC 0x0c04d46c */
if(!s->budget--) { s->failed_pc=0x0c04d46cu; return 0; }
r[5]-=r[2];
goto P_0c04d46e;
P_0c04d46e: /* original 5246, guest PC 0x0c04d46e */
if(!s->budget--) { s->failed_pc=0x0c04d46eu; return 0; }
r[2]=read(ram,r[4]+24,4);
goto P_0c04d470;
P_0c04d470: /* original 6753, guest PC 0x0c04d470 */
if(!s->budget--) { s->failed_pc=0x0c04d470u; return 0; }
r[7]=r[5];
goto P_0c04d472;
P_0c04d472: /* original 6653, guest PC 0x0c04d472 */
if(!s->budget--) { s->failed_pc=0x0c04d472u; return 0; }
r[6]=r[5];
goto P_0c04d474;
P_0c04d474: /* original 6503, guest PC 0x0c04d474 */
if(!s->budget--) { s->failed_pc=0x0c04d474u; return 0; }
r[5]=r[0];
goto P_0c04d476;
P_0c04d476: /* original 3628, guest PC 0x0c04d476 */
if(!s->budget--) { s->failed_pc=0x0c04d476u; return 0; }
r[6]-=r[2];
goto P_0c04d478;
P_0c04d478: /* original 77ff, guest PC 0x0c04d478 */
if(!s->budget--) { s->failed_pc=0x0c04d478u; return 0; }
r[7]+=0xffffffffu;
goto P_0c04d47a;
P_0c04d47a: /* original b01b, guest PC 0x0c04d47a */
if(!s->budget--) { s->failed_pc=0x0c04d47au; return 0; }
target=code_base|0x0c04d4b4u; r[16]=code_base|0x0c04d47eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d47eu) { target=s->pc; goto dispatch; }
goto P_0c04d47e;
P_0c04d47c: /* original 64e3, guest PC 0x0c04d47c */
if(!s->budget--) { s->failed_pc=0x0c04d47cu; return 0; }
r[4]=r[14];
goto P_0c04d47e;
P_0c04d47e: /* original 4015, guest PC 0x0c04d47e */
if(!s->budget--) { s->failed_pc=0x0c04d47eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c04d480;
P_0c04d480: /* original 8d0f, guest PC 0x0c04d480 */
if(!s->budget--) { s->failed_pc=0x0c04d480u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c04d4a2; }
goto P_0c04d484;
P_0c04d482: /* original 6403, guest PC 0x0c04d482 */
if(!s->budget--) { s->failed_pc=0x0c04d482u; return 0; }
r[4]=r[0];
goto P_0c04d484;
P_0c04d484: /* original 54d7, guest PC 0x0c04d484 */
if(!s->budget--) { s->failed_pc=0x0c04d484u; return 0; }
r[4]=read(ram,r[13]+28,4);
goto P_0c04d486;
P_0c04d486: /* original 5347, guest PC 0x0c04d486 */
if(!s->budget--) { s->failed_pc=0x0c04d486u; return 0; }
r[3]=read(ram,r[4]+28,4);
goto P_0c04d488;
P_0c04d488: /* original 2f32, guest PC 0x0c04d488 */
if(!s->budget--) { s->failed_pc=0x0c04d488u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c04d48a;
P_0c04d48a: /* original 67f2, guest PC 0x0c04d48a */
if(!s->budget--) { s->failed_pc=0x0c04d48au; return 0; }
tmp=read(ram,r[15],4);
r[7]=tmp;
goto P_0c04d48c;
P_0c04d48c: /* original 5348, guest PC 0x0c04d48c */
if(!s->budget--) { s->failed_pc=0x0c04d48cu; return 0; }
r[3]=read(ram,r[4]+32,4);
goto P_0c04d48e;
P_0c04d48e: /* original 85f2, guest PC 0x0c04d48e */
if(!s->budget--) { s->failed_pc=0x0c04d48eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c04d490;
P_0c04d490: /* original 66f2, guest PC 0x0c04d490 */
if(!s->budget--) { s->failed_pc=0x0c04d490u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c04d492;
P_0c04d492: /* original 373c, guest PC 0x0c04d492 */
if(!s->budget--) { s->failed_pc=0x0c04d492u; return 0; }
r[7]+=r[3];
goto P_0c04d494;
P_0c04d494: /* original 6503, guest PC 0x0c04d494 */
if(!s->budget--) { s->failed_pc=0x0c04d494u; return 0; }
r[5]=r[0];
goto P_0c04d496;
P_0c04d496: /* original 77ff, guest PC 0x0c04d496 */
if(!s->budget--) { s->failed_pc=0x0c04d496u; return 0; }
r[7]+=0xffffffffu;
goto P_0c04d498;
P_0c04d498: /* original b00c, guest PC 0x0c04d498 */
if(!s->budget--) { s->failed_pc=0x0c04d498u; return 0; }
target=code_base|0x0c04d4b4u; r[16]=code_base|0x0c04d49cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d49cu) { target=s->pc; goto dispatch; }
goto P_0c04d49c;
P_0c04d49a: /* original 64e3, guest PC 0x0c04d49a */
if(!s->budget--) { s->failed_pc=0x0c04d49au; return 0; }
r[4]=r[14];
goto P_0c04d49c;
P_0c04d49c: /* original 4015, guest PC 0x0c04d49c */
if(!s->budget--) { s->failed_pc=0x0c04d49cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c04d49e;
P_0c04d49e: /* original 8f02, guest PC 0x0c04d49e */
if(!s->budget--) { s->failed_pc=0x0c04d49eu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c04d4a6; }
goto P_0c04d4a2;
P_0c04d4a0: /* original 6403, guest PC 0x0c04d4a0 */
if(!s->budget--) { s->failed_pc=0x0c04d4a0u; return 0; }
r[4]=r[0];
goto P_0c04d4a2;
P_0c04d4a2: /* original a001, guest PC 0x0c04d4a2 */
if(!s->budget--) { s->failed_pc=0x0c04d4a2u; return 0; }
r[0]=r[4];
goto P_0c04d4a8;
P_0c04d4a4: /* original 6043, guest PC 0x0c04d4a4 */
if(!s->budget--) { s->failed_pc=0x0c04d4a4u; return 0; }
r[0]=r[4];
goto P_0c04d4a6;
P_0c04d4a6: /* original e0ff, guest PC 0x0c04d4a6 */
if(!s->budget--) { s->failed_pc=0x0c04d4a6u; return 0; }
r[0]=0xffffffffu;
goto P_0c04d4a8;
P_0c04d4a8: /* original 7f08, guest PC 0x0c04d4a8 */
if(!s->budget--) { s->failed_pc=0x0c04d4a8u; return 0; }
r[15]+=0x00000008u;
goto P_0c04d4aa;
P_0c04d4aa: /* original 4f16, guest PC 0x0c04d4aa */
if(!s->budget--) { s->failed_pc=0x0c04d4aau; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d4ac;
P_0c04d4ac: /* original 4f26, guest PC 0x0c04d4ac */
if(!s->budget--) { s->failed_pc=0x0c04d4acu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d4ae;
P_0c04d4ae: /* original 6df6, guest PC 0x0c04d4ae */
if(!s->budget--) { s->failed_pc=0x0c04d4aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04d4b0;
P_0c04d4b0: /* original 000b, guest PC 0x0c04d4b0 */
if(!s->budget--) { s->failed_pc=0x0c04d4b0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04d4b2: /* original 6ef6, guest PC 0x0c04d4b2 */
if(!s->budget--) { s->failed_pc=0x0c04d4b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04d4b4;
P_0c04d4b4: /* original 2fe6, guest PC 0x0c04d4b4 */
if(!s->budget--) { s->failed_pc=0x0c04d4b4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d4b6;
P_0c04d4b6: /* original 6e73, guest PC 0x0c04d4b6 */
if(!s->budget--) { s->failed_pc=0x0c04d4b6u; return 0; }
r[14]=r[7];
goto P_0c04d4b8;
P_0c04d4b8: /* original 2fd6, guest PC 0x0c04d4b8 */
if(!s->budget--) { s->failed_pc=0x0c04d4b8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d4ba;
P_0c04d4ba: /* original 6d63, guest PC 0x0c04d4ba */
if(!s->budget--) { s->failed_pc=0x0c04d4bau; return 0; }
r[13]=r[6];
goto P_0c04d4bc;
P_0c04d4bc: /* original 2fc6, guest PC 0x0c04d4bc */
if(!s->budget--) { s->failed_pc=0x0c04d4bcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d4be;
P_0c04d4be: /* original 3ed3, guest PC 0x0c04d4be */
if(!s->budget--) { s->failed_pc=0x0c04d4beu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[13])!=0);
goto P_0c04d4c0;
P_0c04d4c0: /* original 2fb6, guest PC 0x0c04d4c0 */
if(!s->budget--) { s->failed_pc=0x0c04d4c0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d4c2;
P_0c04d4c2: /* original 4f22, guest PC 0x0c04d4c2 */
if(!s->budget--) { s->failed_pc=0x0c04d4c2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04d4c4;
P_0c04d4c4: /* original 4f12, guest PC 0x0c04d4c4 */
if(!s->budget--) { s->failed_pc=0x0c04d4c4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04d4c6;
P_0c04d4c6: /* original 7ffc, guest PC 0x0c04d4c6 */
if(!s->budget--) { s->failed_pc=0x0c04d4c6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04d4c8;
P_0c04d4c8: /* original 2f51, guest PC 0x0c04d4c8 */
if(!s->budget--) { s->failed_pc=0x0c04d4c8u; return 0; }
write(ram,r[15],r[5],2);
goto P_0c04d4ca;
P_0c04d4ca: /* original 9c40, guest PC 0x0c04d4ca */
if(!s->budget--) { s->failed_pc=0x0c04d4cau; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d54eu,2);
goto P_0c04d4cc;
P_0c04d4cc: /* original db21, guest PC 0x0c04d4cc */
if(!s->budget--) { s->failed_pc=0x0c04d4ccu; return 0; }
r[11]=read(ram,0x0c04d554u,4);
goto P_0c04d4ce;
P_0c04d4ce: /* original 24cf, guest PC 0x0c04d4ce */
if(!s->budget--) { s->failed_pc=0x0c04d4ceu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[12]);
goto P_0c04d4d0;
P_0c04d4d0: /* original d31f, guest PC 0x0c04d4d0 */
if(!s->budget--) { s->failed_pc=0x0c04d4d0u; return 0; }
r[3]=read(ram,0x0c04d550u,4);
goto P_0c04d4d2;
P_0c04d4d2: /* original 0c1a, guest PC 0x0c04d4d2 */
if(!s->budget--) { s->failed_pc=0x0c04d4d2u; return 0; }
r[12]=r[19];
goto P_0c04d4d4;
P_0c04d4d4: /* original 6ccf, guest PC 0x0c04d4d4 */
if(!s->budget--) { s->failed_pc=0x0c04d4d4u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c04d4d6;
P_0c04d4d6: /* original 8f10, guest PC 0x0c04d4d6 */
if(!s->budget--) { s->failed_pc=0x0c04d4d6u; return 0; }
cond=r[17]&1u;
r[12]+=r[3];
if(!cond) { goto P_0c04d4fa; }
goto P_0c04d4da;
P_0c04d4d8: /* original 3c3c, guest PC 0x0c04d4d8 */
if(!s->budget--) { s->failed_pc=0x0c04d4d8u; return 0; }
r[12]+=r[3];
goto P_0c04d4da;
P_0c04d4da: /* original 63b2, guest PC 0x0c04d4da */
if(!s->budget--) { s->failed_pc=0x0c04d4dau; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c04d4dc;
P_0c04d4dc: /* original 65e3, guest PC 0x0c04d4dc */
if(!s->budget--) { s->failed_pc=0x0c04d4dcu; return 0; }
r[5]=r[14];
goto P_0c04d4de;
P_0c04d4de: /* original 4500, guest PC 0x0c04d4de */
if(!s->budget--) { s->failed_pc=0x0c04d4deu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c04d4e0;
P_0c04d4e0: /* original 5233, guest PC 0x0c04d4e0 */
if(!s->budget--) { s->failed_pc=0x0c04d4e0u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c04d4e2;
P_0c04d4e2: /* original 420b, guest PC 0x0c04d4e2 */
if(!s->budget--) { s->failed_pc=0x0c04d4e2u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d4e6u;
r[4]=read(ram,r[12]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d4e6u) { target=s->pc; goto dispatch; }
goto P_0c04d4e6;
P_0c04d4e4: /* original 54c9, guest PC 0x0c04d4e4 */
if(!s->budget--) { s->failed_pc=0x0c04d4e4u; return 0; }
r[4]=read(ram,r[12]+36,4);
goto P_0c04d4e6;
P_0c04d4e6: /* original 63f1, guest PC 0x0c04d4e6 */
if(!s->budget--) { s->failed_pc=0x0c04d4e6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c04d4e8;
P_0c04d4e8: /* original 600d, guest PC 0x0c04d4e8 */
if(!s->budget--) { s->failed_pc=0x0c04d4e8u; return 0; }
r[0]=r[0]&65535u;
goto P_0c04d4ea;
P_0c04d4ea: /* original 633d, guest PC 0x0c04d4ea */
if(!s->budget--) { s->failed_pc=0x0c04d4eau; return 0; }
r[3]=r[3]&65535u;
goto P_0c04d4ec;
P_0c04d4ec: /* original 3030, guest PC 0x0c04d4ec */
if(!s->budget--) { s->failed_pc=0x0c04d4ecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c04d4ee;
P_0c04d4ee: /* original 8b01, guest PC 0x0c04d4ee */
if(!s->budget--) { s->failed_pc=0x0c04d4eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d4f4; }
goto P_0c04d4f0;
P_0c04d4f0: /* original a004, guest PC 0x0c04d4f0 */
if(!s->budget--) { s->failed_pc=0x0c04d4f0u; return 0; }
r[0]=r[14];
goto P_0c04d4fc;
P_0c04d4f2: /* original 60e3, guest PC 0x0c04d4f2 */
if(!s->budget--) { s->failed_pc=0x0c04d4f2u; return 0; }
r[0]=r[14];
goto P_0c04d4f4;
P_0c04d4f4: /* original 7eff, guest PC 0x0c04d4f4 */
if(!s->budget--) { s->failed_pc=0x0c04d4f4u; return 0; }
r[14]+=0xffffffffu;
goto P_0c04d4f6;
P_0c04d4f6: /* original 3ed3, guest PC 0x0c04d4f6 */
if(!s->budget--) { s->failed_pc=0x0c04d4f6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[13])!=0);
goto P_0c04d4f8;
P_0c04d4f8: /* original 89ef, guest PC 0x0c04d4f8 */
if(!s->budget--) { s->failed_pc=0x0c04d4f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d4da; }
goto P_0c04d4fa;
P_0c04d4fa: /* original e0ff, guest PC 0x0c04d4fa */
if(!s->budget--) { s->failed_pc=0x0c04d4fau; return 0; }
r[0]=0xffffffffu;
goto P_0c04d4fc;
P_0c04d4fc: /* original 7f04, guest PC 0x0c04d4fc */
if(!s->budget--) { s->failed_pc=0x0c04d4fcu; return 0; }
r[15]+=0x00000004u;
goto P_0c04d4fe;
P_0c04d4fe: /* original 4f16, guest PC 0x0c04d4fe */
if(!s->budget--) { s->failed_pc=0x0c04d4feu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d500;
P_0c04d500: /* original 4f26, guest PC 0x0c04d500 */
if(!s->budget--) { s->failed_pc=0x0c04d500u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d502;
P_0c04d502: /* original 6bf6, guest PC 0x0c04d502 */
if(!s->budget--) { s->failed_pc=0x0c04d502u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04d504;
P_0c04d504: /* original 6cf6, guest PC 0x0c04d504 */
if(!s->budget--) { s->failed_pc=0x0c04d504u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04d506;
P_0c04d506: /* original 6df6, guest PC 0x0c04d506 */
if(!s->budget--) { s->failed_pc=0x0c04d506u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04d508;
P_0c04d508: /* original 000b, guest PC 0x0c04d508 */
if(!s->budget--) { s->failed_pc=0x0c04d508u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04d50a: /* original 6ef6, guest PC 0x0c04d50a */
if(!s->budget--) { s->failed_pc=0x0c04d50au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04d50c;
P_0c04d50c: /* original 2fe6, guest PC 0x0c04d50c */
if(!s->budget--) { s->failed_pc=0x0c04d50cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d50e;
P_0c04d50e: /* original 6e53, guest PC 0x0c04d50e */
if(!s->budget--) { s->failed_pc=0x0c04d50eu; return 0; }
r[14]=r[5];
goto P_0c04d510;
P_0c04d510: /* original 2fd6, guest PC 0x0c04d510 */
if(!s->budget--) { s->failed_pc=0x0c04d510u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d512;
P_0c04d512: /* original 2fc6, guest PC 0x0c04d512 */
if(!s->budget--) { s->failed_pc=0x0c04d512u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d514;
P_0c04d514: /* original 6c43, guest PC 0x0c04d514 */
if(!s->budget--) { s->failed_pc=0x0c04d514u; return 0; }
r[12]=r[4];
goto P_0c04d516;
P_0c04d516: /* original 4f22, guest PC 0x0c04d516 */
if(!s->budget--) { s->failed_pc=0x0c04d516u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04d518;
P_0c04d518: /* original 9d19, guest PC 0x0c04d518 */
if(!s->budget--) { s->failed_pc=0x0c04d518u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d54eu,2);
goto P_0c04d51a;
P_0c04d51a: /* original 4f12, guest PC 0x0c04d51a */
if(!s->budget--) { s->failed_pc=0x0c04d51au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04d51c;
P_0c04d51c: /* original 2cdf, guest PC 0x0c04d51c */
if(!s->budget--) { s->failed_pc=0x0c04d51cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[12]*(int32_t)(int16_t)r[13]);
goto P_0c04d51e;
P_0c04d51e: /* original 7ff4, guest PC 0x0c04d51e */
if(!s->budget--) { s->failed_pc=0x0c04d51eu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c04d520;
P_0c04d520: /* original 0d1a, guest PC 0x0c04d520 */
if(!s->budget--) { s->failed_pc=0x0c04d520u; return 0; }
r[13]=r[19];
goto P_0c04d522;
P_0c04d522: /* original 6ddf, guest PC 0x0c04d522 */
if(!s->budget--) { s->failed_pc=0x0c04d522u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c04d524;
P_0c04d524: /* original 2fd2, guest PC 0x0c04d524 */
if(!s->budget--) { s->failed_pc=0x0c04d524u; return 0; }
write(ram,r[15],r[13],4);
goto P_0c04d526;
P_0c04d526: /* original d30a, guest PC 0x0c04d526 */
if(!s->budget--) { s->failed_pc=0x0c04d526u; return 0; }
r[3]=read(ram,0x0c04d550u,4);
goto P_0c04d528;
P_0c04d528: /* original 2fe6, guest PC 0x0c04d528 */
if(!s->budget--) { s->failed_pc=0x0c04d528u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d52a;
P_0c04d52a: /* original 3d3c, guest PC 0x0c04d52a */
if(!s->budget--) { s->failed_pc=0x0c04d52au; return 0; }
r[13]+=r[3];
goto P_0c04d52c;
P_0c04d52c: /* original 2fc6, guest PC 0x0c04d52c */
if(!s->budget--) { s->failed_pc=0x0c04d52cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d52e;
P_0c04d52e: /* original d20a, guest PC 0x0c04d52e */
if(!s->budget--) { s->failed_pc=0x0c04d52eu; return 0; }
r[2]=read(ram,0x0c04d558u,4);
goto P_0c04d530;
P_0c04d530: /* original b836, guest PC 0x0c04d530 */
if(!s->budget--) { s->failed_pc=0x0c04d530u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04d534u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d534u) { target=s->pc; goto dispatch; }
goto P_0c04d534;
P_0c04d532: /* original 2f26, guest PC 0x0c04d532 */
if(!s->budget--) { s->failed_pc=0x0c04d532u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d534;
P_0c04d534: /* original 84d2, guest PC 0x0c04d534 */
if(!s->budget--) { s->failed_pc=0x0c04d534u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+2,1);
goto P_0c04d536;
P_0c04d536: /* original 2008, guest PC 0x0c04d536 */
if(!s->budget--) { s->failed_pc=0x0c04d536u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d538;
P_0c04d538: /* original 8d1d, guest PC 0x0c04d538 */
if(!s->budget--) { s->failed_pc=0x0c04d538u; return 0; }
cond=r[17]&1u;
r[15]+=0x0000000cu;
if(cond) { goto P_0c04d576; }
goto P_0c04d53c;
P_0c04d53a: /* original 7f0c, guest PC 0x0c04d53a */
if(!s->budget--) { s->failed_pc=0x0c04d53au; return 0; }
r[15]+=0x0000000cu;
goto P_0c04d53c;
P_0c04d53c: /* original d207, guest PC 0x0c04d53c */
if(!s->budget--) { s->failed_pc=0x0c04d53cu; return 0; }
r[2]=read(ram,0x0c04d55cu,4);
goto P_0c04d53e;
P_0c04d53e: /* original 420b, guest PC 0x0c04d53e */
if(!s->budget--) { s->failed_pc=0x0c04d53eu; return 0; }
target=r[2];
r[16]=code_base|0x0c04d542u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d542u) { target=s->pc; goto dispatch; }
goto P_0c04d542;
P_0c04d540: /* original 64c3, guest PC 0x0c04d540 */
if(!s->budget--) { s->failed_pc=0x0c04d540u; return 0; }
r[4]=r[12];
goto P_0c04d542;
P_0c04d542: /* original 2008, guest PC 0x0c04d542 */
if(!s->budget--) { s->failed_pc=0x0c04d542u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d544;
P_0c04d544: /* original 8b0c, guest PC 0x0c04d544 */
if(!s->budget--) { s->failed_pc=0x0c04d544u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d560; }
goto P_0c04d546;
P_0c04d546: /* original bcc2, guest PC 0x0c04d546 */
if(!s->budget--) { s->failed_pc=0x0c04d546u; return 0; }
target=code_base|0x0c04ceceu; r[16]=code_base|0x0c04d54au;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d54au) { target=s->pc; goto dispatch; }
goto P_0c04d54a;
P_0c04d548: /* original 64c3, guest PC 0x0c04d548 */
if(!s->budget--) { s->failed_pc=0x0c04d548u; return 0; }
r[4]=r[12];
goto P_0c04d54a;
P_0c04d54a: /* original a014, guest PC 0x0c04d54a */
if(!s->budget--) { s->failed_pc=0x0c04d54au; return 0; }
goto P_0c04d576;
P_0c04d54c: /* original 0009, guest PC 0x0c04d54c */
if(!s->budget--) { s->failed_pc=0x0c04d54cu; return 0; }
if(!vf3_matrix_family(0x0c04d54eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04d54eu; return 0; } return 1;
P_0c04d560: /* original d346, guest PC 0x0c04d560 */
if(!s->budget--) { s->failed_pc=0x0c04d560u; return 0; }
r[3]=read(ram,0x0c04d67cu,4);
goto P_0c04d562;
P_0c04d562: /* original 430b, guest PC 0x0c04d562 */
if(!s->budget--) { s->failed_pc=0x0c04d562u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d566u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d566u) { target=s->pc; goto dispatch; }
goto P_0c04d566;
P_0c04d564: /* original 64c3, guest PC 0x0c04d564 */
if(!s->budget--) { s->failed_pc=0x0c04d564u; return 0; }
r[4]=r[12];
goto P_0c04d566;
P_0c04d566: /* original 2008, guest PC 0x0c04d566 */
if(!s->budget--) { s->failed_pc=0x0c04d566u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d568;
P_0c04d568: /* original 8905, guest PC 0x0c04d568 */
if(!s->budget--) { s->failed_pc=0x0c04d568u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d576; }
goto P_0c04d56a;
P_0c04d56a: /* original 62f2, guest PC 0x0c04d56a */
if(!s->budget--) { s->failed_pc=0x0c04d56au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04d56c;
P_0c04d56c: /* original d344, guest PC 0x0c04d56c */
if(!s->budget--) { s->failed_pc=0x0c04d56cu; return 0; }
r[3]=read(ram,0x0c04d680u,4);
goto P_0c04d56e;
P_0c04d56e: /* original 323c, guest PC 0x0c04d56e */
if(!s->budget--) { s->failed_pc=0x0c04d56eu; return 0; }
r[2]+=r[3];
goto P_0c04d570;
P_0c04d570: /* original 8428, guest PC 0x0c04d570 */
if(!s->budget--) { s->failed_pc=0x0c04d570u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04d572;
P_0c04d572: /* original 2008, guest PC 0x0c04d572 */
if(!s->budget--) { s->failed_pc=0x0c04d572u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d574;
P_0c04d574: /* original 8b02, guest PC 0x0c04d574 */
if(!s->budget--) { s->failed_pc=0x0c04d574u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d57c; }
goto P_0c04d576;
P_0c04d576: /* original 907e, guest PC 0x0c04d576 */
if(!s->budget--) { s->failed_pc=0x0c04d576u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d676u,2);
goto P_0c04d578;
P_0c04d578: /* original a051, guest PC 0x0c04d578 */
if(!s->budget--) { s->failed_pc=0x0c04d578u; return 0; }
goto P_0c04d61e;
P_0c04d57a: /* original 0009, guest PC 0x0c04d57a */
if(!s->budget--) { s->failed_pc=0x0c04d57au; return 0; }
goto P_0c04d57c;
P_0c04d57c: /* original d341, guest PC 0x0c04d57c */
if(!s->budget--) { s->failed_pc=0x0c04d57cu; return 0; }
r[3]=read(ram,0x0c04d684u,4);
goto P_0c04d57e;
P_0c04d57e: /* original 430b, guest PC 0x0c04d57e */
if(!s->budget--) { s->failed_pc=0x0c04d57eu; return 0; }
target=r[3];
r[16]=code_base|0x0c04d582u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d582u) { target=s->pc; goto dispatch; }
goto P_0c04d582;
P_0c04d580: /* original 64c3, guest PC 0x0c04d580 */
if(!s->budget--) { s->failed_pc=0x0c04d580u; return 0; }
r[4]=r[12];
goto P_0c04d582;
P_0c04d582: /* original 4011, guest PC 0x0c04d582 */
if(!s->budget--) { s->failed_pc=0x0c04d582u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04d584;
P_0c04d584: /* original 8902, guest PC 0x0c04d584 */
if(!s->budget--) { s->failed_pc=0x0c04d584u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d58c; }
goto P_0c04d586;
P_0c04d586: /* original 9077, guest PC 0x0c04d586 */
if(!s->budget--) { s->failed_pc=0x0c04d586u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d678u,2);
goto P_0c04d588;
P_0c04d588: /* original a049, guest PC 0x0c04d588 */
if(!s->budget--) { s->failed_pc=0x0c04d588u; return 0; }
goto P_0c04d61e;
P_0c04d58a: /* original 0009, guest PC 0x0c04d58a */
if(!s->budget--) { s->failed_pc=0x0c04d58au; return 0; }
goto P_0c04d58c;
P_0c04d58c: /* original e600, guest PC 0x0c04d58c */
if(!s->budget--) { s->failed_pc=0x0c04d58cu; return 0; }
r[6]=0x00000000u;
goto P_0c04d58e;
P_0c04d58e: /* original 6463, guest PC 0x0c04d58e */
if(!s->budget--) { s->failed_pc=0x0c04d58eu; return 0; }
r[4]=r[6];
goto P_0c04d590;
P_0c04d590: /* original a008, guest PC 0x0c04d590 */
if(!s->budget--) { s->failed_pc=0x0c04d590u; return 0; }
r[5]=0x00000020u;
goto P_0c04d5a4;
P_0c04d592: /* original e520, guest PC 0x0c04d592 */
if(!s->budget--) { s->failed_pc=0x0c04d592u; return 0; }
r[5]=0x00000020u;
goto P_0c04d594;
P_0c04d594: /* original 6343, guest PC 0x0c04d594 */
if(!s->budget--) { s->failed_pc=0x0c04d594u; return 0; }
r[3]=r[4];
goto P_0c04d596;
P_0c04d596: /* original 50d8, guest PC 0x0c04d596 */
if(!s->budget--) { s->failed_pc=0x0c04d596u; return 0; }
r[0]=read(ram,r[13]+32,4);
goto P_0c04d598;
P_0c04d598: /* original 7310, guest PC 0x0c04d598 */
if(!s->budget--) { s->failed_pc=0x0c04d598u; return 0; }
r[3]+=0x00000010u;
goto P_0c04d59a;
P_0c04d59a: /* original 62e3, guest PC 0x0c04d59a */
if(!s->budget--) { s->failed_pc=0x0c04d59au; return 0; }
r[2]=r[14];
goto P_0c04d59c;
P_0c04d59c: /* original 013c, guest PC 0x0c04d59c */
if(!s->budget--) { s->failed_pc=0x0c04d59cu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04d59e;
P_0c04d59e: /* original 324c, guest PC 0x0c04d59e */
if(!s->budget--) { s->failed_pc=0x0c04d59eu; return 0; }
r[2]+=r[4];
goto P_0c04d5a0;
P_0c04d5a0: /* original 7401, guest PC 0x0c04d5a0 */
if(!s->budget--) { s->failed_pc=0x0c04d5a0u; return 0; }
r[4]+=0x00000001u;
goto P_0c04d5a2;
P_0c04d5a2: /* original 2210, guest PC 0x0c04d5a2 */
if(!s->budget--) { s->failed_pc=0x0c04d5a2u; return 0; }
write(ram,r[2],r[1],1);
goto P_0c04d5a4;
P_0c04d5a4: /* original 3453, guest PC 0x0c04d5a4 */
if(!s->budget--) { s->failed_pc=0x0c04d5a4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c04d5a6;
P_0c04d5a6: /* original 8bf5, guest PC 0x0c04d5a6 */
if(!s->budget--) { s->failed_pc=0x0c04d5a6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d594; }
goto P_0c04d5a8;
P_0c04d5a8: /* original 54d8, guest PC 0x0c04d5a8 */
if(!s->budget--) { s->failed_pc=0x0c04d5a8u; return 0; }
r[4]=read(ram,r[13]+32,4);
goto P_0c04d5aa;
P_0c04d5aa: /* original 65f3, guest PC 0x0c04d5aa */
if(!s->budget--) { s->failed_pc=0x0c04d5aau; return 0; }
r[5]=r[15];
goto P_0c04d5ac;
P_0c04d5ac: /* original 7504, guest PC 0x0c04d5ac */
if(!s->budget--) { s->failed_pc=0x0c04d5acu; return 0; }
r[5]+=0x00000004u;
goto P_0c04d5ae;
P_0c04d5ae: /* original 7430, guest PC 0x0c04d5ae */
if(!s->budget--) { s->failed_pc=0x0c04d5aeu; return 0; }
r[4]+=0x00000030u;
goto P_0c04d5b0;
P_0c04d5b0: /* original a004, guest PC 0x0c04d5b0 */
if(!s->budget--) { s->failed_pc=0x0c04d5b0u; return 0; }
r[7]=0x00000008u;
goto P_0c04d5bc;
P_0c04d5b2: /* original e708, guest PC 0x0c04d5b2 */
if(!s->budget--) { s->failed_pc=0x0c04d5b2u; return 0; }
r[7]=0x00000008u;
goto P_0c04d5b4;
P_0c04d5b4: /* original 6344, guest PC 0x0c04d5b4 */
if(!s->budget--) { s->failed_pc=0x0c04d5b4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[3]=tmp;
goto P_0c04d5b6;
P_0c04d5b6: /* original 7601, guest PC 0x0c04d5b6 */
if(!s->budget--) { s->failed_pc=0x0c04d5b6u; return 0; }
r[6]+=0x00000001u;
goto P_0c04d5b8;
P_0c04d5b8: /* original 2530, guest PC 0x0c04d5b8 */
if(!s->budget--) { s->failed_pc=0x0c04d5b8u; return 0; }
write(ram,r[5],r[3],1);
goto P_0c04d5ba;
P_0c04d5ba: /* original 7501, guest PC 0x0c04d5ba */
if(!s->budget--) { s->failed_pc=0x0c04d5bau; return 0; }
r[5]+=0x00000001u;
goto P_0c04d5bc;
P_0c04d5bc: /* original 3673, guest PC 0x0c04d5bc */
if(!s->budget--) { s->failed_pc=0x0c04d5bcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[7])!=0);
goto P_0c04d5be;
P_0c04d5be: /* original 8bf9, guest PC 0x0c04d5be */
if(!s->budget--) { s->failed_pc=0x0c04d5beu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d5b4; }
goto P_0c04d5c0;
P_0c04d5c0: /* original d331, guest PC 0x0c04d5c0 */
if(!s->budget--) { s->failed_pc=0x0c04d5c0u; return 0; }
r[3]=read(ram,0x0c04d688u,4);
goto P_0c04d5c2;
P_0c04d5c2: /* original 65f3, guest PC 0x0c04d5c2 */
if(!s->budget--) { s->failed_pc=0x0c04d5c2u; return 0; }
r[5]=r[15];
goto P_0c04d5c4;
P_0c04d5c4: /* original 64e3, guest PC 0x0c04d5c4 */
if(!s->budget--) { s->failed_pc=0x0c04d5c4u; return 0; }
r[4]=r[14];
goto P_0c04d5c6;
P_0c04d5c6: /* original 7504, guest PC 0x0c04d5c6 */
if(!s->budget--) { s->failed_pc=0x0c04d5c6u; return 0; }
r[5]+=0x00000004u;
goto P_0c04d5c8;
P_0c04d5c8: /* original 430b, guest PC 0x0c04d5c8 */
if(!s->budget--) { s->failed_pc=0x0c04d5c8u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d5ccu;
r[4]+=0x00000030u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d5ccu) { target=s->pc; goto dispatch; }
goto P_0c04d5cc;
P_0c04d5ca: /* original 7430, guest PC 0x0c04d5ca */
if(!s->budget--) { s->failed_pc=0x0c04d5cau; return 0; }
r[4]+=0x00000030u;
goto P_0c04d5cc;
P_0c04d5cc: /* original 52d7, guest PC 0x0c04d5cc */
if(!s->budget--) { s->failed_pc=0x0c04d5ccu; return 0; }
r[2]=read(ram,r[13]+28,4);
goto P_0c04d5ce;
P_0c04d5ce: /* original e020, guest PC 0x0c04d5ce */
if(!s->budget--) { s->failed_pc=0x0c04d5ceu; return 0; }
r[0]=0x00000020u;
goto P_0c04d5d0;
P_0c04d5d0: /* original e500, guest PC 0x0c04d5d0 */
if(!s->budget--) { s->failed_pc=0x0c04d5d0u; return 0; }
r[5]=0x00000000u;
goto P_0c04d5d2;
P_0c04d5d2: /* original 6322, guest PC 0x0c04d5d2 */
if(!s->budget--) { s->failed_pc=0x0c04d5d2u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c04d5d4;
P_0c04d5d4: /* original 7301, guest PC 0x0c04d5d4 */
if(!s->budget--) { s->failed_pc=0x0c04d5d4u; return 0; }
r[3]+=0x00000001u;
goto P_0c04d5d6;
P_0c04d5d6: /* original 0e35, guest PC 0x0c04d5d6 */
if(!s->budget--) { s->failed_pc=0x0c04d5d6u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c04d5d8;
P_0c04d5d8: /* original e022, guest PC 0x0c04d5d8 */
if(!s->budget--) { s->failed_pc=0x0c04d5d8u; return 0; }
r[0]=0x00000022u;
goto P_0c04d5da;
P_0c04d5da: /* original 52d7, guest PC 0x0c04d5da */
if(!s->budget--) { s->failed_pc=0x0c04d5dau; return 0; }
r[2]=read(ram,r[13]+28,4);
goto P_0c04d5dc;
P_0c04d5dc: /* original 532c, guest PC 0x0c04d5dc */
if(!s->budget--) { s->failed_pc=0x0c04d5dcu; return 0; }
r[3]=read(ram,r[2]+48,4);
goto P_0c04d5de;
P_0c04d5de: /* original 0e35, guest PC 0x0c04d5de */
if(!s->budget--) { s->failed_pc=0x0c04d5deu; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c04d5e0;
P_0c04d5e0: /* original b024, guest PC 0x0c04d5e0 */
if(!s->budget--) { s->failed_pc=0x0c04d5e0u; return 0; }
target=code_base|0x0c04d62cu; r[16]=code_base|0x0c04d5e4u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d5e4u) { target=s->pc; goto dispatch; }
goto P_0c04d5e4;
P_0c04d5e2: /* original 64c3, guest PC 0x0c04d5e2 */
if(!s->budget--) { s->failed_pc=0x0c04d5e2u; return 0; }
r[4]=r[12];
goto P_0c04d5e4;
P_0c04d5e4: /* original e126, guest PC 0x0c04d5e4 */
if(!s->budget--) { s->failed_pc=0x0c04d5e4u; return 0; }
r[1]=0x00000026u;
goto P_0c04d5e6;
P_0c04d5e6: /* original 31ec, guest PC 0x0c04d5e6 */
if(!s->budget--) { s->failed_pc=0x0c04d5e6u; return 0; }
r[1]+=r[14];
goto P_0c04d5e8;
P_0c04d5e8: /* original 2101, guest PC 0x0c04d5e8 */
if(!s->budget--) { s->failed_pc=0x0c04d5e8u; return 0; }
write(ram,r[1],r[0],2);
goto P_0c04d5ea;
P_0c04d5ea: /* original e026, guest PC 0x0c04d5ea */
if(!s->budget--) { s->failed_pc=0x0c04d5eau; return 0; }
r[0]=0x00000026u;
goto P_0c04d5ec;
P_0c04d5ec: /* original 03ed, guest PC 0x0c04d5ec */
if(!s->budget--) { s->failed_pc=0x0c04d5ecu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c04d5ee;
P_0c04d5ee: /* original e024, guest PC 0x0c04d5ee */
if(!s->budget--) { s->failed_pc=0x0c04d5eeu; return 0; }
r[0]=0x00000024u;
goto P_0c04d5f0;
P_0c04d5f0: /* original e501, guest PC 0x0c04d5f0 */
if(!s->budget--) { s->failed_pc=0x0c04d5f0u; return 0; }
r[5]=0x00000001u;
goto P_0c04d5f2;
P_0c04d5f2: /* original 0e35, guest PC 0x0c04d5f2 */
if(!s->budget--) { s->failed_pc=0x0c04d5f2u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c04d5f4;
P_0c04d5f4: /* original e028, guest PC 0x0c04d5f4 */
if(!s->budget--) { s->failed_pc=0x0c04d5f4u; return 0; }
r[0]=0x00000028u;
goto P_0c04d5f6;
P_0c04d5f6: /* original 52d7, guest PC 0x0c04d5f6 */
if(!s->budget--) { s->failed_pc=0x0c04d5f6u; return 0; }
r[2]=read(ram,r[13]+28,4);
goto P_0c04d5f8;
P_0c04d5f8: /* original 532e, guest PC 0x0c04d5f8 */
if(!s->budget--) { s->failed_pc=0x0c04d5f8u; return 0; }
r[3]=read(ram,r[2]+56,4);
goto P_0c04d5fa;
P_0c04d5fa: /* original 0e35, guest PC 0x0c04d5fa */
if(!s->budget--) { s->failed_pc=0x0c04d5fau; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c04d5fc;
P_0c04d5fc: /* original b016, guest PC 0x0c04d5fc */
if(!s->budget--) { s->failed_pc=0x0c04d5fcu; return 0; }
target=code_base|0x0c04d62cu; r[16]=code_base|0x0c04d600u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d600u) { target=s->pc; goto dispatch; }
goto P_0c04d600;
P_0c04d5fe: /* original 64c3, guest PC 0x0c04d5fe */
if(!s->budget--) { s->failed_pc=0x0c04d5feu; return 0; }
r[4]=r[12];
goto P_0c04d600;
P_0c04d600: /* original e12a, guest PC 0x0c04d600 */
if(!s->budget--) { s->failed_pc=0x0c04d600u; return 0; }
r[1]=0x0000002au;
goto P_0c04d602;
P_0c04d602: /* original 31ec, guest PC 0x0c04d602 */
if(!s->budget--) { s->failed_pc=0x0c04d602u; return 0; }
r[1]+=r[14];
goto P_0c04d604;
P_0c04d604: /* original 2101, guest PC 0x0c04d604 */
if(!s->budget--) { s->failed_pc=0x0c04d604u; return 0; }
write(ram,r[1],r[0],2);
goto P_0c04d606;
P_0c04d606: /* original e02c, guest PC 0x0c04d606 */
if(!s->budget--) { s->failed_pc=0x0c04d606u; return 0; }
r[0]=0x0000002cu;
goto P_0c04d608;
P_0c04d608: /* original 53d7, guest PC 0x0c04d608 */
if(!s->budget--) { s->failed_pc=0x0c04d608u; return 0; }
r[3]=read(ram,r[13]+28,4);
goto P_0c04d60a;
P_0c04d60a: /* original 523b, guest PC 0x0c04d60a */
if(!s->budget--) { s->failed_pc=0x0c04d60au; return 0; }
r[2]=read(ram,r[3]+44,4);
goto P_0c04d60c;
P_0c04d60c: /* original 7201, guest PC 0x0c04d60c */
if(!s->budget--) { s->failed_pc=0x0c04d60cu; return 0; }
r[2]+=0x00000001u;
goto P_0c04d60e;
P_0c04d60e: /* original 0e25, guest PC 0x0c04d60e */
if(!s->budget--) { s->failed_pc=0x0c04d60eu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c04d610;
P_0c04d610: /* original e04e, guest PC 0x0c04d610 */
if(!s->budget--) { s->failed_pc=0x0c04d610u; return 0; }
r[0]=0x0000004eu;
goto P_0c04d612;
P_0c04d612: /* original 53d8, guest PC 0x0c04d612 */
if(!s->budget--) { s->failed_pc=0x0c04d612u; return 0; }
r[3]=read(ram,r[13]+32,4);
goto P_0c04d614;
P_0c04d614: /* original 023c, guest PC 0x0c04d614 */
if(!s->budget--) { s->failed_pc=0x0c04d614u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04d616;
P_0c04d616: /* original e02e, guest PC 0x0c04d616 */
if(!s->budget--) { s->failed_pc=0x0c04d616u; return 0; }
r[0]=0x0000002eu;
goto P_0c04d618;
P_0c04d618: /* original 622c, guest PC 0x0c04d618 */
if(!s->budget--) { s->failed_pc=0x0c04d618u; return 0; }
r[2]=r[2]&255u;
goto P_0c04d61a;
P_0c04d61a: /* original 0e25, guest PC 0x0c04d61a */
if(!s->budget--) { s->failed_pc=0x0c04d61au; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c04d61c;
P_0c04d61c: /* original e000, guest PC 0x0c04d61c */
if(!s->budget--) { s->failed_pc=0x0c04d61cu; return 0; }
r[0]=0x00000000u;
goto P_0c04d61e;
P_0c04d61e: /* original 7f0c, guest PC 0x0c04d61e */
if(!s->budget--) { s->failed_pc=0x0c04d61eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c04d620;
P_0c04d620: /* original 4f16, guest PC 0x0c04d620 */
if(!s->budget--) { s->failed_pc=0x0c04d620u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d622;
P_0c04d622: /* original 4f26, guest PC 0x0c04d622 */
if(!s->budget--) { s->failed_pc=0x0c04d622u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d624;
P_0c04d624: /* original 6cf6, guest PC 0x0c04d624 */
if(!s->budget--) { s->failed_pc=0x0c04d624u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04d626;
P_0c04d626: /* original 6df6, guest PC 0x0c04d626 */
if(!s->budget--) { s->failed_pc=0x0c04d626u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04d628;
P_0c04d628: /* original 000b, guest PC 0x0c04d628 */
if(!s->budget--) { s->failed_pc=0x0c04d628u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04d62a: /* original 6ef6, guest PC 0x0c04d62a */
if(!s->budget--) { s->failed_pc=0x0c04d62au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04d62cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
