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
int vf3_away_batch42_adapter_16(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09e428u: goto P_0c09e428;
case 0x0c09e42au: goto P_0c09e42a;
case 0x0c09e42cu: goto P_0c09e42c;
case 0x0c09e42eu: goto P_0c09e42e;
case 0x0c09e430u: goto P_0c09e430;
case 0x0c09e432u: goto P_0c09e432;
case 0x0c09e434u: goto P_0c09e434;
case 0x0c09e436u: goto P_0c09e436;
case 0x0c09e438u: goto P_0c09e438;
case 0x0c09e43au: goto P_0c09e43a;
case 0x0c09e43cu: goto P_0c09e43c;
case 0x0c09e43eu: goto P_0c09e43e;
case 0x0c09e440u: goto P_0c09e440;
case 0x0c09e442u: goto P_0c09e442;
case 0x0c09e444u: goto P_0c09e444;
case 0x0c09e446u: goto P_0c09e446;
case 0x0c09e448u: goto P_0c09e448;
case 0x0c09e44au: goto P_0c09e44a;
case 0x0c09e44cu: goto P_0c09e44c;
case 0x0c09e44eu: goto P_0c09e44e;
case 0x0c09e450u: goto P_0c09e450;
case 0x0c09e452u: goto P_0c09e452;
case 0x0c09e454u: goto P_0c09e454;
case 0x0c09e456u: goto P_0c09e456;
case 0x0c09e458u: goto P_0c09e458;
case 0x0c09e45au: goto P_0c09e45a;
case 0x0c09e45cu: goto P_0c09e45c;
case 0x0c09e45eu: goto P_0c09e45e;
case 0x0c09e460u: goto P_0c09e460;
case 0x0c09e462u: goto P_0c09e462;
case 0x0c09e464u: goto P_0c09e464;
case 0x0c09e466u: goto P_0c09e466;
case 0x0c09e468u: goto P_0c09e468;
case 0x0c09e46au: goto P_0c09e46a;
case 0x0c09e46cu: goto P_0c09e46c;
case 0x0c09e46eu: goto P_0c09e46e;
case 0x0c09e470u: goto P_0c09e470;
case 0x0c09e472u: goto P_0c09e472;
case 0x0c09e474u: goto P_0c09e474;
case 0x0c09e476u: goto P_0c09e476;
case 0x0c09e478u: goto P_0c09e478;
case 0x0c09e47au: goto P_0c09e47a;
case 0x0c09e47cu: goto P_0c09e47c;
case 0x0c09e47eu: goto P_0c09e47e;
case 0x0c09e480u: goto P_0c09e480;
case 0x0c09e482u: goto P_0c09e482;
case 0x0c09e484u: goto P_0c09e484;
case 0x0c09e486u: goto P_0c09e486;
case 0x0c09e488u: goto P_0c09e488;
case 0x0c09e48au: goto P_0c09e48a;
case 0x0c09e48cu: goto P_0c09e48c;
case 0x0c09e48eu: goto P_0c09e48e;
case 0x0c09e490u: goto P_0c09e490;
case 0x0c09e492u: goto P_0c09e492;
case 0x0c09e494u: goto P_0c09e494;
case 0x0c09e496u: goto P_0c09e496;
case 0x0c09e498u: goto P_0c09e498;
case 0x0c09e49au: goto P_0c09e49a;
case 0x0c09e49cu: goto P_0c09e49c;
case 0x0c09e49eu: goto P_0c09e49e;
case 0x0c09e4a0u: goto P_0c09e4a0;
case 0x0c09e4a2u: goto P_0c09e4a2;
case 0x0c09e4a4u: goto P_0c09e4a4;
case 0x0c09e4a6u: goto P_0c09e4a6;
case 0x0c09e4a8u: goto P_0c09e4a8;
case 0x0c09e4c8u: goto P_0c09e4c8;
case 0x0c09e4cau: goto P_0c09e4ca;
case 0x0c09e4ccu: goto P_0c09e4cc;
case 0x0c09e4ceu: goto P_0c09e4ce;
case 0x0c09e4d0u: goto P_0c09e4d0;
case 0x0c09e4d2u: goto P_0c09e4d2;
case 0x0c09e4d4u: goto P_0c09e4d4;
case 0x0c09e4d6u: goto P_0c09e4d6;
case 0x0c09e4d8u: goto P_0c09e4d8;
case 0x0c09e4dau: goto P_0c09e4da;
case 0x0c09e4dcu: goto P_0c09e4dc;
case 0x0c09e4deu: goto P_0c09e4de;
case 0x0c09e4e0u: goto P_0c09e4e0;
case 0x0c09e4e2u: goto P_0c09e4e2;
case 0x0c09e4e4u: goto P_0c09e4e4;
case 0x0c09e4e6u: goto P_0c09e4e6;
case 0x0c09e4e8u: goto P_0c09e4e8;
case 0x0c09e4eau: goto P_0c09e4ea;
case 0x0c09e4ecu: goto P_0c09e4ec;
case 0x0c09e4eeu: goto P_0c09e4ee;
case 0x0c09e4f0u: goto P_0c09e4f0;
case 0x0c09e4f2u: goto P_0c09e4f2;
case 0x0c09e4f4u: goto P_0c09e4f4;
case 0x0c09e4f6u: goto P_0c09e4f6;
case 0x0c09e4f8u: goto P_0c09e4f8;
case 0x0c09e4fau: goto P_0c09e4fa;
case 0x0c09e4fcu: goto P_0c09e4fc;
case 0x0c09e4feu: goto P_0c09e4fe;
case 0x0c09e500u: goto P_0c09e500;
case 0x0c09e502u: goto P_0c09e502;
case 0x0c09e504u: goto P_0c09e504;
case 0x0c09e506u: goto P_0c09e506;
case 0x0c09e508u: goto P_0c09e508;
case 0x0c09e50au: goto P_0c09e50a;
case 0x0c09e50cu: goto P_0c09e50c;
case 0x0c09e50eu: goto P_0c09e50e;
case 0x0c09e510u: goto P_0c09e510;
case 0x0c09e512u: goto P_0c09e512;
case 0x0c09e514u: goto P_0c09e514;
case 0x0c09e516u: goto P_0c09e516;
case 0x0c09e518u: goto P_0c09e518;
case 0x0c09e51au: goto P_0c09e51a;
case 0x0c09e51cu: goto P_0c09e51c;
case 0x0c09e51eu: goto P_0c09e51e;
case 0x0c09e520u: goto P_0c09e520;
case 0x0c09e522u: goto P_0c09e522;
case 0x0c09e524u: goto P_0c09e524;
case 0x0c09e526u: goto P_0c09e526;
case 0x0c09e528u: goto P_0c09e528;
case 0x0c09e52au: goto P_0c09e52a;
case 0x0c09e52cu: goto P_0c09e52c;
case 0x0c09e52eu: goto P_0c09e52e;
case 0x0c09e530u: goto P_0c09e530;
case 0x0c09e532u: goto P_0c09e532;
case 0x0c09e534u: goto P_0c09e534;
case 0x0c09e536u: goto P_0c09e536;
case 0x0c09e538u: goto P_0c09e538;
case 0x0c09e53au: goto P_0c09e53a;
case 0x0c09e53cu: goto P_0c09e53c;
case 0x0c09e53eu: goto P_0c09e53e;
case 0x0c09e540u: goto P_0c09e540;
case 0x0c09e542u: goto P_0c09e542;
case 0x0c09e544u: goto P_0c09e544;
case 0x0c09e546u: goto P_0c09e546;
case 0x0c09e548u: goto P_0c09e548;
case 0x0c09e54au: goto P_0c09e54a;
case 0x0c09e54cu: goto P_0c09e54c;
case 0x0c09e54eu: goto P_0c09e54e;
case 0x0c09e550u: goto P_0c09e550;
case 0x0c09e552u: goto P_0c09e552;
case 0x0c09e554u: goto P_0c09e554;
case 0x0c09e556u: goto P_0c09e556;
case 0x0c09e558u: goto P_0c09e558;
case 0x0c09e55au: goto P_0c09e55a;
case 0x0c09e55cu: goto P_0c09e55c;
case 0x0c09e55eu: goto P_0c09e55e;
case 0x0c09e560u: goto P_0c09e560;
case 0x0c09e562u: goto P_0c09e562;
case 0x0c09e564u: goto P_0c09e564;
case 0x0c09e566u: goto P_0c09e566;
case 0x0c09e568u: goto P_0c09e568;
case 0x0c09e56au: goto P_0c09e56a;
case 0x0c09e56cu: goto P_0c09e56c;
case 0x0c09e56eu: goto P_0c09e56e;
case 0x0c09e570u: goto P_0c09e570;
case 0x0c09e572u: goto P_0c09e572;
case 0x0c09e574u: goto P_0c09e574;
case 0x0c09e576u: goto P_0c09e576;
case 0x0c09e578u: goto P_0c09e578;
case 0x0c09e57au: goto P_0c09e57a;
case 0x0c09e57cu: goto P_0c09e57c;
case 0x0c09e57eu: goto P_0c09e57e;
case 0x0c09e580u: goto P_0c09e580;
case 0x0c09e582u: goto P_0c09e582;
case 0x0c09e584u: goto P_0c09e584;
case 0x0c09e586u: goto P_0c09e586;
case 0x0c09e588u: goto P_0c09e588;
case 0x0c09e58au: goto P_0c09e58a;
case 0x0c09e58cu: goto P_0c09e58c;
case 0x0c09e58eu: goto P_0c09e58e;
case 0x0c09e590u: goto P_0c09e590;
case 0x0c09e592u: goto P_0c09e592;
case 0x0c09e594u: goto P_0c09e594;
case 0x0c09e596u: goto P_0c09e596;
case 0x0c09e598u: goto P_0c09e598;
case 0x0c09e59au: goto P_0c09e59a;
case 0x0c09e59cu: goto P_0c09e59c;
case 0x0c09e59eu: goto P_0c09e59e;
case 0x0c09e5a0u: goto P_0c09e5a0;
case 0x0c09e5a2u: goto P_0c09e5a2;
case 0x0c09e5a4u: goto P_0c09e5a4;
case 0x0c09e5a6u: goto P_0c09e5a6;
case 0x0c09e5a8u: goto P_0c09e5a8;
case 0x0c09e5aau: goto P_0c09e5aa;
case 0x0c09e5acu: goto P_0c09e5ac;
case 0x0c09e5aeu: goto P_0c09e5ae;
case 0x0c09e5b0u: goto P_0c09e5b0;
case 0x0c09e5b2u: goto P_0c09e5b2;
case 0x0c09e5b4u: goto P_0c09e5b4;
case 0x0c09e5b6u: goto P_0c09e5b6;
case 0x0c09e5b8u: goto P_0c09e5b8;
case 0x0c09e5bau: goto P_0c09e5ba;
case 0x0c09e5bcu: goto P_0c09e5bc;
case 0x0c09e5beu: goto P_0c09e5be;
case 0x0c09e5c0u: goto P_0c09e5c0;
case 0x0c09e5c2u: goto P_0c09e5c2;
case 0x0c09e5c4u: goto P_0c09e5c4;
case 0x0c09e5c6u: goto P_0c09e5c6;
case 0x0c09e5c8u: goto P_0c09e5c8;
case 0x0c09e5cau: goto P_0c09e5ca;
case 0x0c09e5ccu: goto P_0c09e5cc;
case 0x0c09e5ceu: goto P_0c09e5ce;
case 0x0c09e5d0u: goto P_0c09e5d0;
case 0x0c09e5d2u: goto P_0c09e5d2;
case 0x0c09e5d4u: goto P_0c09e5d4;
case 0x0c09e5d6u: goto P_0c09e5d6;
case 0x0c09e5d8u: goto P_0c09e5d8;
case 0x0c09e5dau: goto P_0c09e5da;
case 0x0c09e5dcu: goto P_0c09e5dc;
case 0x0c09e5deu: goto P_0c09e5de;
case 0x0c09e5e0u: goto P_0c09e5e0;
case 0x0c09e5e2u: goto P_0c09e5e2;
case 0x0c09e5e4u: goto P_0c09e5e4;
case 0x0c09e5e6u: goto P_0c09e5e6;
case 0x0c09e5e8u: goto P_0c09e5e8;
case 0x0c09e5eau: goto P_0c09e5ea;
case 0x0c09e5ecu: goto P_0c09e5ec;
case 0x0c09e5eeu: goto P_0c09e5ee;
case 0x0c09e5f0u: goto P_0c09e5f0;
case 0x0c09e5f2u: goto P_0c09e5f2;
case 0x0c09e5f4u: goto P_0c09e5f4;
case 0x0c09e5f6u: goto P_0c09e5f6;
case 0x0c09e5f8u: goto P_0c09e5f8;
case 0x0c09e5fau: goto P_0c09e5fa;
case 0x0c09e5fcu: goto P_0c09e5fc;
case 0x0c09e5feu: goto P_0c09e5fe;
case 0x0c09e600u: goto P_0c09e600;
case 0x0c09e602u: goto P_0c09e602;
case 0x0c09e604u: goto P_0c09e604;
case 0x0c09e606u: goto P_0c09e606;
case 0x0c09e608u: goto P_0c09e608;
case 0x0c09e60au: goto P_0c09e60a;
case 0x0c09e60cu: goto P_0c09e60c;
case 0x0c09e60eu: goto P_0c09e60e;
case 0x0c09e610u: goto P_0c09e610;
case 0x0c09e612u: goto P_0c09e612;
case 0x0c09e614u: goto P_0c09e614;
case 0x0c09e616u: goto P_0c09e616;
case 0x0c09e618u: goto P_0c09e618;
case 0x0c09e61au: goto P_0c09e61a;
case 0x0c09e61cu: goto P_0c09e61c;
case 0x0c09e61eu: goto P_0c09e61e;
case 0x0c09e620u: goto P_0c09e620;
case 0x0c09e622u: goto P_0c09e622;
case 0x0c09e624u: goto P_0c09e624;
case 0x0c09e626u: goto P_0c09e626;
case 0x0c09e628u: goto P_0c09e628;
case 0x0c09e62au: goto P_0c09e62a;
case 0x0c09e62cu: goto P_0c09e62c;
case 0x0c09e62eu: goto P_0c09e62e;
case 0x0c09e630u: goto P_0c09e630;
case 0x0c09e632u: goto P_0c09e632;
case 0x0c09e634u: goto P_0c09e634;
case 0x0c09e636u: goto P_0c09e636;
case 0x0c09e638u: goto P_0c09e638;
case 0x0c09e63au: goto P_0c09e63a;
case 0x0c09e63cu: goto P_0c09e63c;
case 0x0c09e63eu: goto P_0c09e63e;
case 0x0c09e640u: goto P_0c09e640;
case 0x0c09e642u: goto P_0c09e642;
case 0x0c09e644u: goto P_0c09e644;
case 0x0c09e646u: goto P_0c09e646;
case 0x0c09e648u: goto P_0c09e648;
case 0x0c09e64au: goto P_0c09e64a;
case 0x0c09e64cu: goto P_0c09e64c;
case 0x0c09e698u: goto P_0c09e698;
case 0x0c09e69au: goto P_0c09e69a;
case 0x0c09e69cu: goto P_0c09e69c;
case 0x0c09e69eu: goto P_0c09e69e;
case 0x0c09e6a0u: goto P_0c09e6a0;
case 0x0c09e6a2u: goto P_0c09e6a2;
case 0x0c09e6a4u: goto P_0c09e6a4;
case 0x0c09e6a6u: goto P_0c09e6a6;
case 0x0c09e6a8u: goto P_0c09e6a8;
case 0x0c09e6aau: goto P_0c09e6aa;
case 0x0c09e6acu: goto P_0c09e6ac;
case 0x0c09e6aeu: goto P_0c09e6ae;
case 0x0c09e6b0u: goto P_0c09e6b0;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09e428: /* original 2fe6, guest PC 0x0c09e428 */
if(!s->budget--) { s->failed_pc=0x0c09e428u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09e42a;
P_0c09e42a: /* original 6e43, guest PC 0x0c09e42a */
if(!s->budget--) { s->failed_pc=0x0c09e42au; return 0; }
r[14]=r[4];
goto P_0c09e42c;
P_0c09e42c: /* original 4f22, guest PC 0x0c09e42c */
if(!s->budget--) { s->failed_pc=0x0c09e42cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09e42e;
P_0c09e42e: /* original 7ff0, guest PC 0x0c09e42e */
if(!s->budget--) { s->failed_pc=0x0c09e42eu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09e430;
P_0c09e430: /* original 2f52, guest PC 0x0c09e430 */
if(!s->budget--) { s->failed_pc=0x0c09e430u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c09e432;
P_0c09e432: /* original d320, guest PC 0x0c09e432 */
if(!s->budget--) { s->failed_pc=0x0c09e432u; return 0; }
r[3]=read(ram,0x0c09e4b4u,4);
goto P_0c09e434;
P_0c09e434: /* original 430b, guest PC 0x0c09e434 */
if(!s->budget--) { s->failed_pc=0x0c09e434u; return 0; }
target=r[3];
r[16]=code_base|0x0c09e438u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e438u) { target=s->pc; goto dispatch; }
goto P_0c09e438;
P_0c09e436: /* original e400, guest PC 0x0c09e436 */
if(!s->budget--) { s->failed_pc=0x0c09e436u; return 0; }
r[4]=0x00000000u;
goto P_0c09e438;
P_0c09e438: /* original 9037, guest PC 0x0c09e438 */
if(!s->budget--) { s->failed_pc=0x0c09e438u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e4aau,2);
goto P_0c09e43a;
P_0c09e43a: /* original 04ed, guest PC 0x0c09e43a */
if(!s->budget--) { s->failed_pc=0x0c09e43au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09e43c;
P_0c09e43c: /* original 70d0, guest PC 0x0c09e43c */
if(!s->budget--) { s->failed_pc=0x0c09e43cu; return 0; }
r[0]+=0xffffffd0u;
goto P_0c09e43e;
P_0c09e43e: /* original 05ed, guest PC 0x0c09e43e */
if(!s->budget--) { s->failed_pc=0x0c09e43eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09e440;
P_0c09e440: /* original 644d, guest PC 0x0c09e440 */
if(!s->budget--) { s->failed_pc=0x0c09e440u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09e442;
P_0c09e442: /* original 655d, guest PC 0x0c09e442 */
if(!s->budget--) { s->failed_pc=0x0c09e442u; return 0; }
r[5]=r[5]&65535u;
goto P_0c09e444;
P_0c09e444: /* original 3548, guest PC 0x0c09e444 */
if(!s->budget--) { s->failed_pc=0x0c09e444u; return 0; }
r[5]-=r[4];
goto P_0c09e446;
P_0c09e446: /* original 655f, guest PC 0x0c09e446 */
if(!s->budget--) { s->failed_pc=0x0c09e446u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c09e448;
P_0c09e448: /* original 4501, guest PC 0x0c09e448 */
if(!s->budget--) { s->failed_pc=0x0c09e448u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c09e44a;
P_0c09e44a: /* original 345c, guest PC 0x0c09e44a */
if(!s->budget--) { s->failed_pc=0x0c09e44au; return 0; }
r[4]+=r[5];
goto P_0c09e44c;
P_0c09e44c: /* original 644d, guest PC 0x0c09e44c */
if(!s->budget--) { s->failed_pc=0x0c09e44cu; return 0; }
r[4]=r[4]&65535u;
goto P_0c09e44e;
P_0c09e44e: /* original 1f42, guest PC 0x0c09e44e */
if(!s->budget--) { s->failed_pc=0x0c09e44eu; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c09e450;
P_0c09e450: /* original 902c, guest PC 0x0c09e450 */
if(!s->budget--) { s->failed_pc=0x0c09e450u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e4acu,2);
goto P_0c09e452;
P_0c09e452: /* original 05ed, guest PC 0x0c09e452 */
if(!s->budget--) { s->failed_pc=0x0c09e452u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09e454;
P_0c09e454: /* original 7030, guest PC 0x0c09e454 */
if(!s->budget--) { s->failed_pc=0x0c09e454u; return 0; }
r[0]+=0x00000030u;
goto P_0c09e456;
P_0c09e456: /* original 04ed, guest PC 0x0c09e456 */
if(!s->budget--) { s->failed_pc=0x0c09e456u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09e458;
P_0c09e458: /* original 655d, guest PC 0x0c09e458 */
if(!s->budget--) { s->failed_pc=0x0c09e458u; return 0; }
r[5]=r[5]&65535u;
goto P_0c09e45a;
P_0c09e45a: /* original 644d, guest PC 0x0c09e45a */
if(!s->budget--) { s->failed_pc=0x0c09e45au; return 0; }
r[4]=r[4]&65535u;
goto P_0c09e45c;
P_0c09e45c: /* original 3548, guest PC 0x0c09e45c */
if(!s->budget--) { s->failed_pc=0x0c09e45cu; return 0; }
r[5]-=r[4];
goto P_0c09e45e;
P_0c09e45e: /* original 655f, guest PC 0x0c09e45e */
if(!s->budget--) { s->failed_pc=0x0c09e45eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c09e460;
P_0c09e460: /* original 4501, guest PC 0x0c09e460 */
if(!s->budget--) { s->failed_pc=0x0c09e460u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c09e462;
P_0c09e462: /* original 345c, guest PC 0x0c09e462 */
if(!s->budget--) { s->failed_pc=0x0c09e462u; return 0; }
r[4]+=r[5];
goto P_0c09e464;
P_0c09e464: /* original 644d, guest PC 0x0c09e464 */
if(!s->budget--) { s->failed_pc=0x0c09e464u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09e466;
P_0c09e466: /* original 1f43, guest PC 0x0c09e466 */
if(!s->budget--) { s->failed_pc=0x0c09e466u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c09e468;
P_0c09e468: /* original 9021, guest PC 0x0c09e468 */
if(!s->budget--) { s->failed_pc=0x0c09e468u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e4aeu,2);
goto P_0c09e46a;
P_0c09e46a: /* original 05ed, guest PC 0x0c09e46a */
if(!s->budget--) { s->failed_pc=0x0c09e46au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09e46c;
P_0c09e46c: /* original 7030, guest PC 0x0c09e46c */
if(!s->budget--) { s->failed_pc=0x0c09e46cu; return 0; }
r[0]+=0x00000030u;
goto P_0c09e46e;
P_0c09e46e: /* original 04ed, guest PC 0x0c09e46e */
if(!s->budget--) { s->failed_pc=0x0c09e46eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09e470;
P_0c09e470: /* original 655d, guest PC 0x0c09e470 */
if(!s->budget--) { s->failed_pc=0x0c09e470u; return 0; }
r[5]=r[5]&65535u;
goto P_0c09e472;
P_0c09e472: /* original 644d, guest PC 0x0c09e472 */
if(!s->budget--) { s->failed_pc=0x0c09e472u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09e474;
P_0c09e474: /* original 3548, guest PC 0x0c09e474 */
if(!s->budget--) { s->failed_pc=0x0c09e474u; return 0; }
r[5]-=r[4];
goto P_0c09e476;
P_0c09e476: /* original 655f, guest PC 0x0c09e476 */
if(!s->budget--) { s->failed_pc=0x0c09e476u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c09e478;
P_0c09e478: /* original 4501, guest PC 0x0c09e478 */
if(!s->budget--) { s->failed_pc=0x0c09e478u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c09e47a;
P_0c09e47a: /* original 345c, guest PC 0x0c09e47a */
if(!s->budget--) { s->failed_pc=0x0c09e47au; return 0; }
r[4]+=r[5];
goto P_0c09e47c;
P_0c09e47c: /* original 644d, guest PC 0x0c09e47c */
if(!s->budget--) { s->failed_pc=0x0c09e47cu; return 0; }
r[4]=r[4]&65535u;
goto P_0c09e47e;
P_0c09e47e: /* original 1f41, guest PC 0x0c09e47e */
if(!s->budget--) { s->failed_pc=0x0c09e47eu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c09e480;
P_0c09e480: /* original 56f2, guest PC 0x0c09e480 */
if(!s->budget--) { s->failed_pc=0x0c09e480u; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c09e482;
P_0c09e482: /* original d30d, guest PC 0x0c09e482 */
if(!s->budget--) { s->failed_pc=0x0c09e482u; return 0; }
r[3]=read(ram,0x0c09e4b8u,4);
goto P_0c09e484;
P_0c09e484: /* original 430b, guest PC 0x0c09e484 */
if(!s->budget--) { s->failed_pc=0x0c09e484u; return 0; }
target=r[3];
r[16]=code_base|0x0c09e488u;
r[5]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e488u) { target=s->pc; goto dispatch; }
goto P_0c09e488;
P_0c09e486: /* original 55f3, guest PC 0x0c09e486 */
if(!s->budget--) { s->failed_pc=0x0c09e486u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c09e488;
P_0c09e488: /* original d20c, guest PC 0x0c09e488 */
if(!s->budget--) { s->failed_pc=0x0c09e488u; return 0; }
r[2]=read(ram,0x0c09e4bcu,4);
goto P_0c09e48a;
P_0c09e48a: /* original 9411, guest PC 0x0c09e48a */
if(!s->budget--) { s->failed_pc=0x0c09e48au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e4b0u,2);
goto P_0c09e48c;
P_0c09e48c: /* original 420b, guest PC 0x0c09e48c */
if(!s->budget--) { s->failed_pc=0x0c09e48cu; return 0; }
target=r[2];
r[16]=code_base|0x0c09e490u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e490u) { target=s->pc; goto dispatch; }
goto P_0c09e490;
P_0c09e48e: /* original 0009, guest PC 0x0c09e48e */
if(!s->budget--) { s->failed_pc=0x0c09e48eu; return 0; }
goto P_0c09e490;
P_0c09e490: /* original b829, guest PC 0x0c09e490 */
if(!s->budget--) { s->failed_pc=0x0c09e490u; return 0; }
target=code_base|0x0c09d4e6u; r[16]=code_base|0x0c09e494u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e494u) { target=s->pc; goto dispatch; }
goto P_0c09e494;
P_0c09e492: /* original 64f2, guest PC 0x0c09e492 */
if(!s->budget--) { s->failed_pc=0x0c09e492u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c09e494;
P_0c09e494: /* original d30a, guest PC 0x0c09e494 */
if(!s->budget--) { s->failed_pc=0x0c09e494u; return 0; }
r[3]=read(ram,0x0c09e4c0u,4);
goto P_0c09e496;
P_0c09e496: /* original 940c, guest PC 0x0c09e496 */
if(!s->budget--) { s->failed_pc=0x0c09e496u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e4b2u,2);
goto P_0c09e498;
P_0c09e498: /* original 65f2, guest PC 0x0c09e498 */
if(!s->budget--) { s->failed_pc=0x0c09e498u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c09e49a;
P_0c09e49a: /* original 430b, guest PC 0x0c09e49a */
if(!s->budget--) { s->failed_pc=0x0c09e49au; return 0; }
target=r[3];
r[16]=code_base|0x0c09e49eu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e49eu) { target=s->pc; goto dispatch; }
goto P_0c09e49e;
P_0c09e49c: /* original 34ec, guest PC 0x0c09e49c */
if(!s->budget--) { s->failed_pc=0x0c09e49cu; return 0; }
r[4]+=r[14];
goto P_0c09e49e;
P_0c09e49e: /* original 7f10, guest PC 0x0c09e49e */
if(!s->budget--) { s->failed_pc=0x0c09e49eu; return 0; }
r[15]+=0x00000010u;
goto P_0c09e4a0;
P_0c09e4a0: /* original d208, guest PC 0x0c09e4a0 */
if(!s->budget--) { s->failed_pc=0x0c09e4a0u; return 0; }
r[2]=read(ram,0x0c09e4c4u,4);
goto P_0c09e4a2;
P_0c09e4a2: /* original 4f26, guest PC 0x0c09e4a2 */
if(!s->budget--) { s->failed_pc=0x0c09e4a2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09e4a4;
P_0c09e4a4: /* original e401, guest PC 0x0c09e4a4 */
if(!s->budget--) { s->failed_pc=0x0c09e4a4u; return 0; }
r[4]=0x00000001u;
goto P_0c09e4a6;
P_0c09e4a6: /* original 422b, guest PC 0x0c09e4a6 */
if(!s->budget--) { s->failed_pc=0x0c09e4a6u; return 0; }
target=r[2];
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
P_0c09e4a8: /* original 6ef6, guest PC 0x0c09e4a8 */
if(!s->budget--) { s->failed_pc=0x0c09e4a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09e4aau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09e4aau; return 0; } return 1;
P_0c09e4c8: /* original 2fe6, guest PC 0x0c09e4c8 */
if(!s->budget--) { s->failed_pc=0x0c09e4c8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09e4ca;
P_0c09e4ca: /* original 6e43, guest PC 0x0c09e4ca */
if(!s->budget--) { s->failed_pc=0x0c09e4cau; return 0; }
r[14]=r[4];
goto P_0c09e4cc;
P_0c09e4cc: /* original 2fd6, guest PC 0x0c09e4cc */
if(!s->budget--) { s->failed_pc=0x0c09e4ccu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09e4ce;
P_0c09e4ce: /* original 6d53, guest PC 0x0c09e4ce */
if(!s->budget--) { s->failed_pc=0x0c09e4ceu; return 0; }
r[13]=r[5];
goto P_0c09e4d0;
P_0c09e4d0: /* original 4f22, guest PC 0x0c09e4d0 */
if(!s->budget--) { s->failed_pc=0x0c09e4d0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09e4d2;
P_0c09e4d2: /* original 94bc, guest PC 0x0c09e4d2 */
if(!s->budget--) { s->failed_pc=0x0c09e4d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e64eu,2);
goto P_0c09e4d4;
P_0c09e4d4: /* original d363, guest PC 0x0c09e4d4 */
if(!s->budget--) { s->failed_pc=0x0c09e4d4u; return 0; }
r[3]=read(ram,0x0c09e664u,4);
goto P_0c09e4d6;
P_0c09e4d6: /* original 7f9c, guest PC 0x0c09e4d6 */
if(!s->budget--) { s->failed_pc=0x0c09e4d6u; return 0; }
r[15]+=0xffffff9cu;
goto P_0c09e4d8;
P_0c09e4d8: /* original 430b, guest PC 0x0c09e4d8 */
if(!s->budget--) { s->failed_pc=0x0c09e4d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c09e4dcu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e4dcu) { target=s->pc; goto dispatch; }
goto P_0c09e4dc;
P_0c09e4da: /* original 34ec, guest PC 0x0c09e4da */
if(!s->budget--) { s->failed_pc=0x0c09e4dau; return 0; }
r[4]+=r[14];
goto P_0c09e4dc;
P_0c09e4dc: /* original e061, guest PC 0x0c09e4dc */
if(!s->budget--) { s->failed_pc=0x0c09e4dcu; return 0; }
r[0]=0x00000061u;
goto P_0c09e4de;
P_0c09e4de: /* original d363, guest PC 0x0c09e4de */
if(!s->budget--) { s->failed_pc=0x0c09e4deu; return 0; }
r[3]=read(ram,0x0c09e66cu,4);
goto P_0c09e4e0;
P_0c09e4e0: /* original 04ec, guest PC 0x0c09e4e0 */
if(!s->budget--) { s->failed_pc=0x0c09e4e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09e4e2;
P_0c09e4e2: /* original d061, guest PC 0x0c09e4e2 */
if(!s->budget--) { s->failed_pc=0x0c09e4e2u; return 0; }
r[0]=read(ram,0x0c09e668u,4);
goto P_0c09e4e4;
P_0c09e4e4: /* original 644c, guest PC 0x0c09e4e4 */
if(!s->budget--) { s->failed_pc=0x0c09e4e4u; return 0; }
r[4]=r[4]&255u;
goto P_0c09e4e6;
P_0c09e4e6: /* original 4400, guest PC 0x0c09e4e6 */
if(!s->budget--) { s->failed_pc=0x0c09e4e6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c09e4e8;
P_0c09e4e8: /* original 430b, guest PC 0x0c09e4e8 */
if(!s->budget--) { s->failed_pc=0x0c09e4e8u; return 0; }
target=r[3];
r[16]=code_base|0x0c09e4ecu;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e4ecu) { target=s->pc; goto dispatch; }
goto P_0c09e4ec;
P_0c09e4ea: /* original 044d, guest PC 0x0c09e4ea */
if(!s->budget--) { s->failed_pc=0x0c09e4eau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09e4ec;
P_0c09e4ec: /* original d360, guest PC 0x0c09e4ec */
if(!s->budget--) { s->failed_pc=0x0c09e4ecu; return 0; }
r[3]=read(ram,0x0c09e670u,4);
goto P_0c09e4ee;
P_0c09e4ee: /* original 90af, guest PC 0x0c09e4ee */
if(!s->budget--) { s->failed_pc=0x0c09e4eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e650u,2);
goto P_0c09e4f0;
P_0c09e4f0: /* original 430b, guest PC 0x0c09e4f0 */
if(!s->budget--) { s->failed_pc=0x0c09e4f0u; return 0; }
target=r[3];
r[16]=code_base|0x0c09e4f4u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e4f4u) { target=s->pc; goto dispatch; }
goto P_0c09e4f4;
P_0c09e4f2: /* original 04ed, guest PC 0x0c09e4f2 */
if(!s->budget--) { s->failed_pc=0x0c09e4f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09e4f4;
P_0c09e4f4: /* original 90ad, guest PC 0x0c09e4f4 */
if(!s->budget--) { s->failed_pc=0x0c09e4f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e652u,2);
goto P_0c09e4f6;
P_0c09e4f6: /* original d35d, guest PC 0x0c09e4f6 */
if(!s->budget--) { s->failed_pc=0x0c09e4f6u; return 0; }
r[3]=read(ram,0x0c09e66cu,4);
goto P_0c09e4f8;
P_0c09e4f8: /* original 04ed, guest PC 0x0c09e4f8 */
if(!s->budget--) { s->failed_pc=0x0c09e4f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09e4fa;
P_0c09e4fa: /* original 430b, guest PC 0x0c09e4fa */
if(!s->budget--) { s->failed_pc=0x0c09e4fau; return 0; }
target=r[3];
r[16]=code_base|0x0c09e4feu;
r[4]=0u-r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e4feu) { target=s->pc; goto dispatch; }
goto P_0c09e4fe;
P_0c09e4fc: /* original 644b, guest PC 0x0c09e4fc */
if(!s->budget--) { s->failed_pc=0x0c09e4fcu; return 0; }
r[4]=0u-r[4];
goto P_0c09e4fe;
P_0c09e4fe: /* original d25d, guest PC 0x0c09e4fe */
if(!s->budget--) { s->failed_pc=0x0c09e4feu; return 0; }
r[2]=read(ram,0x0c09e674u,4);
goto P_0c09e500;
P_0c09e500: /* original 64f3, guest PC 0x0c09e500 */
if(!s->budget--) { s->failed_pc=0x0c09e500u; return 0; }
r[4]=r[15];
goto P_0c09e502;
P_0c09e502: /* original 420b, guest PC 0x0c09e502 */
if(!s->budget--) { s->failed_pc=0x0c09e502u; return 0; }
target=r[2];
r[16]=code_base|0x0c09e506u;
r[4]+=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e506u) { target=s->pc; goto dispatch; }
goto P_0c09e506;
P_0c09e504: /* original 740c, guest PC 0x0c09e504 */
if(!s->budget--) { s->failed_pc=0x0c09e504u; return 0; }
r[4]+=0x0000000cu;
goto P_0c09e506;
P_0c09e506: /* original e00c, guest PC 0x0c09e506 */
if(!s->budget--) { s->failed_pc=0x0c09e506u; return 0; }
r[0]=0x0000000cu;
goto P_0c09e508;
P_0c09e508: /* original 64f3, guest PC 0x0c09e508 */
if(!s->budget--) { s->failed_pc=0x0c09e508u; return 0; }
r[4]=r[15];
goto P_0c09e50a;
P_0c09e50a: /* original f3f6, guest PC 0x0c09e50a */
if(!s->budget--) { s->failed_pc=0x0c09e50au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e50c;
P_0c09e50c: /* original e010, guest PC 0x0c09e50c */
if(!s->budget--) { s->failed_pc=0x0c09e50cu; return 0; }
r[0]=0x00000010u;
goto P_0c09e50e;
P_0c09e50e: /* original fd37, guest PC 0x0c09e50e */
if(!s->budget--) { s->failed_pc=0x0c09e50eu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09e510;
P_0c09e510: /* original e010, guest PC 0x0c09e510 */
if(!s->budget--) { s->failed_pc=0x0c09e510u; return 0; }
r[0]=0x00000010u;
goto P_0c09e512;
P_0c09e512: /* original f3f6, guest PC 0x0c09e512 */
if(!s->budget--) { s->failed_pc=0x0c09e512u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e514;
P_0c09e514: /* original e014, guest PC 0x0c09e514 */
if(!s->budget--) { s->failed_pc=0x0c09e514u; return 0; }
r[0]=0x00000014u;
goto P_0c09e516;
P_0c09e516: /* original fd37, guest PC 0x0c09e516 */
if(!s->budget--) { s->failed_pc=0x0c09e516u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09e518;
P_0c09e518: /* original e014, guest PC 0x0c09e518 */
if(!s->budget--) { s->failed_pc=0x0c09e518u; return 0; }
r[0]=0x00000014u;
goto P_0c09e51a;
P_0c09e51a: /* original f3f6, guest PC 0x0c09e51a */
if(!s->budget--) { s->failed_pc=0x0c09e51au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e51c;
P_0c09e51c: /* original e018, guest PC 0x0c09e51c */
if(!s->budget--) { s->failed_pc=0x0c09e51cu; return 0; }
r[0]=0x00000018u;
goto P_0c09e51e;
P_0c09e51e: /* original fd37, guest PC 0x0c09e51e */
if(!s->budget--) { s->failed_pc=0x0c09e51eu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09e520;
P_0c09e520: /* original e00c, guest PC 0x0c09e520 */
if(!s->budget--) { s->failed_pc=0x0c09e520u; return 0; }
r[0]=0x0000000cu;
goto P_0c09e522;
P_0c09e522: /* original f3f6, guest PC 0x0c09e522 */
if(!s->budget--) { s->failed_pc=0x0c09e522u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e524;
P_0c09e524: /* original e010, guest PC 0x0c09e524 */
if(!s->budget--) { s->failed_pc=0x0c09e524u; return 0; }
r[0]=0x00000010u;
goto P_0c09e526;
P_0c09e526: /* original f43a, guest PC 0x0c09e526 */
if(!s->budget--) { s->failed_pc=0x0c09e526u; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c09e528;
P_0c09e528: /* original f3f6, guest PC 0x0c09e528 */
if(!s->budget--) { s->failed_pc=0x0c09e528u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e52a;
P_0c09e52a: /* original e004, guest PC 0x0c09e52a */
if(!s->budget--) { s->failed_pc=0x0c09e52au; return 0; }
r[0]=0x00000004u;
goto P_0c09e52c;
P_0c09e52c: /* original f437, guest PC 0x0c09e52c */
if(!s->budget--) { s->failed_pc=0x0c09e52cu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c09e52e;
P_0c09e52e: /* original e014, guest PC 0x0c09e52e */
if(!s->budget--) { s->failed_pc=0x0c09e52eu; return 0; }
r[0]=0x00000014u;
goto P_0c09e530;
P_0c09e530: /* original f3f6, guest PC 0x0c09e530 */
if(!s->budget--) { s->failed_pc=0x0c09e530u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e532;
P_0c09e532: /* original e008, guest PC 0x0c09e532 */
if(!s->budget--) { s->failed_pc=0x0c09e532u; return 0; }
r[0]=0x00000008u;
goto P_0c09e534;
P_0c09e534: /* original f437, guest PC 0x0c09e534 */
if(!s->budget--) { s->failed_pc=0x0c09e534u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c09e536;
P_0c09e536: /* original e02c, guest PC 0x0c09e536 */
if(!s->budget--) { s->failed_pc=0x0c09e536u; return 0; }
r[0]=0x0000002cu;
goto P_0c09e538;
P_0c09e538: /* original f3f6, guest PC 0x0c09e538 */
if(!s->budget--) { s->failed_pc=0x0c09e538u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e53a;
P_0c09e53a: /* original e020, guest PC 0x0c09e53a */
if(!s->budget--) { s->failed_pc=0x0c09e53au; return 0; }
r[0]=0x00000020u;
goto P_0c09e53c;
P_0c09e53c: /* original fd37, guest PC 0x0c09e53c */
if(!s->budget--) { s->failed_pc=0x0c09e53cu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09e53e;
P_0c09e53e: /* original e030, guest PC 0x0c09e53e */
if(!s->budget--) { s->failed_pc=0x0c09e53eu; return 0; }
r[0]=0x00000030u;
goto P_0c09e540;
P_0c09e540: /* original f3f6, guest PC 0x0c09e540 */
if(!s->budget--) { s->failed_pc=0x0c09e540u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e542;
P_0c09e542: /* original e024, guest PC 0x0c09e542 */
if(!s->budget--) { s->failed_pc=0x0c09e542u; return 0; }
r[0]=0x00000024u;
goto P_0c09e544;
P_0c09e544: /* original fd37, guest PC 0x0c09e544 */
if(!s->budget--) { s->failed_pc=0x0c09e544u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09e546;
P_0c09e546: /* original e034, guest PC 0x0c09e546 */
if(!s->budget--) { s->failed_pc=0x0c09e546u; return 0; }
r[0]=0x00000034u;
goto P_0c09e548;
P_0c09e548: /* original f3f6, guest PC 0x0c09e548 */
if(!s->budget--) { s->failed_pc=0x0c09e548u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e54a;
P_0c09e54a: /* original e028, guest PC 0x0c09e54a */
if(!s->budget--) { s->failed_pc=0x0c09e54au; return 0; }
r[0]=0x00000028u;
goto P_0c09e54c;
P_0c09e54c: /* original fd37, guest PC 0x0c09e54c */
if(!s->budget--) { s->failed_pc=0x0c09e54cu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09e54e;
P_0c09e54e: /* original e01c, guest PC 0x0c09e54e */
if(!s->budget--) { s->failed_pc=0x0c09e54eu; return 0; }
r[0]=0x0000001cu;
goto P_0c09e550;
P_0c09e550: /* original f3f6, guest PC 0x0c09e550 */
if(!s->budget--) { s->failed_pc=0x0c09e550u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e552;
P_0c09e552: /* original e00c, guest PC 0x0c09e552 */
if(!s->budget--) { s->failed_pc=0x0c09e552u; return 0; }
r[0]=0x0000000cu;
goto P_0c09e554;
P_0c09e554: /* original f34d, guest PC 0x0c09e554 */
if(!s->budget--) { s->failed_pc=0x0c09e554u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09e556;
P_0c09e556: /* original ff37, guest PC 0x0c09e556 */
if(!s->budget--) { s->failed_pc=0x0c09e556u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e558;
P_0c09e558: /* original e020, guest PC 0x0c09e558 */
if(!s->budget--) { s->failed_pc=0x0c09e558u; return 0; }
r[0]=0x00000020u;
goto P_0c09e55a;
P_0c09e55a: /* original f3f6, guest PC 0x0c09e55a */
if(!s->budget--) { s->failed_pc=0x0c09e55au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e55c;
P_0c09e55c: /* original e010, guest PC 0x0c09e55c */
if(!s->budget--) { s->failed_pc=0x0c09e55cu; return 0; }
r[0]=0x00000010u;
goto P_0c09e55e;
P_0c09e55e: /* original f34d, guest PC 0x0c09e55e */
if(!s->budget--) { s->failed_pc=0x0c09e55eu; return 0; }
fr[3]^=0x80000000u;
goto P_0c09e560;
P_0c09e560: /* original ff37, guest PC 0x0c09e560 */
if(!s->budget--) { s->failed_pc=0x0c09e560u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e562;
P_0c09e562: /* original e024, guest PC 0x0c09e562 */
if(!s->budget--) { s->failed_pc=0x0c09e562u; return 0; }
r[0]=0x00000024u;
goto P_0c09e564;
P_0c09e564: /* original f3f6, guest PC 0x0c09e564 */
if(!s->budget--) { s->failed_pc=0x0c09e564u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e566;
P_0c09e566: /* original e014, guest PC 0x0c09e566 */
if(!s->budget--) { s->failed_pc=0x0c09e566u; return 0; }
r[0]=0x00000014u;
goto P_0c09e568;
P_0c09e568: /* original f34d, guest PC 0x0c09e568 */
if(!s->budget--) { s->failed_pc=0x0c09e568u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09e56a;
P_0c09e56a: /* original ff37, guest PC 0x0c09e56a */
if(!s->budget--) { s->failed_pc=0x0c09e56au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e56c;
P_0c09e56c: /* original e00c, guest PC 0x0c09e56c */
if(!s->budget--) { s->failed_pc=0x0c09e56cu; return 0; }
r[0]=0x0000000cu;
goto P_0c09e56e;
P_0c09e56e: /* original f3f6, guest PC 0x0c09e56e */
if(!s->budget--) { s->failed_pc=0x0c09e56eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e570;
P_0c09e570: /* original e010, guest PC 0x0c09e570 */
if(!s->budget--) { s->failed_pc=0x0c09e570u; return 0; }
r[0]=0x00000010u;
goto P_0c09e572;
P_0c09e572: /* original fd3a, guest PC 0x0c09e572 */
if(!s->budget--) { s->failed_pc=0x0c09e572u; return 0; }
vf3_matrix_store(s,ram,3,r[13]);
goto P_0c09e574;
P_0c09e574: /* original f3f6, guest PC 0x0c09e574 */
if(!s->budget--) { s->failed_pc=0x0c09e574u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e576;
P_0c09e576: /* original e004, guest PC 0x0c09e576 */
if(!s->budget--) { s->failed_pc=0x0c09e576u; return 0; }
r[0]=0x00000004u;
goto P_0c09e578;
P_0c09e578: /* original fd37, guest PC 0x0c09e578 */
if(!s->budget--) { s->failed_pc=0x0c09e578u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09e57a;
P_0c09e57a: /* original e014, guest PC 0x0c09e57a */
if(!s->budget--) { s->failed_pc=0x0c09e57au; return 0; }
r[0]=0x00000014u;
goto P_0c09e57c;
P_0c09e57c: /* original f3f6, guest PC 0x0c09e57c */
if(!s->budget--) { s->failed_pc=0x0c09e57cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e57e;
P_0c09e57e: /* original e008, guest PC 0x0c09e57e */
if(!s->budget--) { s->failed_pc=0x0c09e57eu; return 0; }
r[0]=0x00000008u;
goto P_0c09e580;
P_0c09e580: /* original fd37, guest PC 0x0c09e580 */
if(!s->budget--) { s->failed_pc=0x0c09e580u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09e582;
P_0c09e582: /* original e01c, guest PC 0x0c09e582 */
if(!s->budget--) { s->failed_pc=0x0c09e582u; return 0; }
r[0]=0x0000001cu;
goto P_0c09e584;
P_0c09e584: /* original f348, guest PC 0x0c09e584 */
if(!s->budget--) { s->failed_pc=0x0c09e584u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c09e586;
P_0c09e586: /* original ff37, guest PC 0x0c09e586 */
if(!s->budget--) { s->failed_pc=0x0c09e586u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e588;
P_0c09e588: /* original e004, guest PC 0x0c09e588 */
if(!s->budget--) { s->failed_pc=0x0c09e588u; return 0; }
r[0]=0x00000004u;
goto P_0c09e58a;
P_0c09e58a: /* original f346, guest PC 0x0c09e58a */
if(!s->budget--) { s->failed_pc=0x0c09e58au; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c09e58c;
P_0c09e58c: /* original e020, guest PC 0x0c09e58c */
if(!s->budget--) { s->failed_pc=0x0c09e58cu; return 0; }
r[0]=0x00000020u;
goto P_0c09e58e;
P_0c09e58e: /* original 65d3, guest PC 0x0c09e58e */
if(!s->budget--) { s->failed_pc=0x0c09e58eu; return 0; }
r[5]=r[13];
goto P_0c09e590;
P_0c09e590: /* original ff37, guest PC 0x0c09e590 */
if(!s->budget--) { s->failed_pc=0x0c09e590u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e592;
P_0c09e592: /* original e008, guest PC 0x0c09e592 */
if(!s->budget--) { s->failed_pc=0x0c09e592u; return 0; }
r[0]=0x00000008u;
goto P_0c09e594;
P_0c09e594: /* original f346, guest PC 0x0c09e594 */
if(!s->budget--) { s->failed_pc=0x0c09e594u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c09e596;
P_0c09e596: /* original e024, guest PC 0x0c09e596 */
if(!s->budget--) { s->failed_pc=0x0c09e596u; return 0; }
r[0]=0x00000024u;
goto P_0c09e598;
P_0c09e598: /* original ff37, guest PC 0x0c09e598 */
if(!s->budget--) { s->failed_pc=0x0c09e598u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e59a;
P_0c09e59a: /* original 945b, guest PC 0x0c09e59a */
if(!s->budget--) { s->failed_pc=0x0c09e59au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e654u,2);
goto P_0c09e59c;
P_0c09e59c: /* original d336, guest PC 0x0c09e59c */
if(!s->budget--) { s->failed_pc=0x0c09e59cu; return 0; }
r[3]=read(ram,0x0c09e678u,4);
goto P_0c09e59e;
P_0c09e59e: /* original 430b, guest PC 0x0c09e59e */
if(!s->budget--) { s->failed_pc=0x0c09e59eu; return 0; }
target=r[3];
r[16]=code_base|0x0c09e5a2u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e5a2u) { target=s->pc; goto dispatch; }
goto P_0c09e5a2;
P_0c09e5a0: /* original 34ec, guest PC 0x0c09e5a0 */
if(!s->budget--) { s->failed_pc=0x0c09e5a0u; return 0; }
r[4]+=r[14];
goto P_0c09e5a2;
P_0c09e5a2: /* original c736, guest PC 0x0c09e5a2 */
if(!s->budget--) { s->failed_pc=0x0c09e5a2u; return 0; }
r[0]=code_base|0x0009e67cu;
goto P_0c09e5a4;
P_0c09e5a4: /* original f408, guest PC 0x0c09e5a4 */
if(!s->budget--) { s->failed_pc=0x0c09e5a4u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c09e5a6;
P_0c09e5a6: /* original e03c, guest PC 0x0c09e5a6 */
if(!s->budget--) { s->failed_pc=0x0c09e5a6u; return 0; }
r[0]=0x0000003cu;
goto P_0c09e5a8;
P_0c09e5a8: /* original f3f6, guest PC 0x0c09e5a8 */
if(!s->budget--) { s->failed_pc=0x0c09e5a8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e5aa;
P_0c09e5aa: /* original e00c, guest PC 0x0c09e5aa */
if(!s->budget--) { s->failed_pc=0x0c09e5aau; return 0; }
r[0]=0x0000000cu;
goto P_0c09e5ac;
P_0c09e5ac: /* original f2f6, guest PC 0x0c09e5ac */
if(!s->budget--) { s->failed_pc=0x0c09e5acu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09e5ae;
P_0c09e5ae: /* original f04c, guest PC 0x0c09e5ae */
if(!s->budget--) { s->failed_pc=0x0c09e5aeu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c09e5b0;
P_0c09e5b0: /* original f32e, guest PC 0x0c09e5b0 */
if(!s->budget--) { s->failed_pc=0x0c09e5b0u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09e5b2;
P_0c09e5b2: /* original 9050, guest PC 0x0c09e5b2 */
if(!s->budget--) { s->failed_pc=0x0c09e5b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e656u,2);
goto P_0c09e5b4;
P_0c09e5b4: /* original fe37, guest PC 0x0c09e5b4 */
if(!s->budget--) { s->failed_pc=0x0c09e5b4u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09e5b6;
P_0c09e5b6: /* original e040, guest PC 0x0c09e5b6 */
if(!s->budget--) { s->failed_pc=0x0c09e5b6u; return 0; }
r[0]=0x00000040u;
goto P_0c09e5b8;
P_0c09e5b8: /* original f3f6, guest PC 0x0c09e5b8 */
if(!s->budget--) { s->failed_pc=0x0c09e5b8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e5ba;
P_0c09e5ba: /* original e010, guest PC 0x0c09e5ba */
if(!s->budget--) { s->failed_pc=0x0c09e5bau; return 0; }
r[0]=0x00000010u;
goto P_0c09e5bc;
P_0c09e5bc: /* original f2f6, guest PC 0x0c09e5bc */
if(!s->budget--) { s->failed_pc=0x0c09e5bcu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09e5be;
P_0c09e5be: /* original 904b, guest PC 0x0c09e5be */
if(!s->budget--) { s->failed_pc=0x0c09e5beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e658u,2);
goto P_0c09e5c0;
P_0c09e5c0: /* original f32e, guest PC 0x0c09e5c0 */
if(!s->budget--) { s->failed_pc=0x0c09e5c0u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09e5c2;
P_0c09e5c2: /* original fe37, guest PC 0x0c09e5c2 */
if(!s->budget--) { s->failed_pc=0x0c09e5c2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09e5c4;
P_0c09e5c4: /* original e044, guest PC 0x0c09e5c4 */
if(!s->budget--) { s->failed_pc=0x0c09e5c4u; return 0; }
r[0]=0x00000044u;
goto P_0c09e5c6;
P_0c09e5c6: /* original f3f6, guest PC 0x0c09e5c6 */
if(!s->budget--) { s->failed_pc=0x0c09e5c6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e5c8;
P_0c09e5c8: /* original e014, guest PC 0x0c09e5c8 */
if(!s->budget--) { s->failed_pc=0x0c09e5c8u; return 0; }
r[0]=0x00000014u;
goto P_0c09e5ca;
P_0c09e5ca: /* original f2f6, guest PC 0x0c09e5ca */
if(!s->budget--) { s->failed_pc=0x0c09e5cau; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09e5cc;
P_0c09e5cc: /* original 9045, guest PC 0x0c09e5cc */
if(!s->budget--) { s->failed_pc=0x0c09e5ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e65au,2);
goto P_0c09e5ce;
P_0c09e5ce: /* original f32e, guest PC 0x0c09e5ce */
if(!s->budget--) { s->failed_pc=0x0c09e5ceu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09e5d0;
P_0c09e5d0: /* original fe37, guest PC 0x0c09e5d0 */
if(!s->budget--) { s->failed_pc=0x0c09e5d0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09e5d2;
P_0c09e5d2: /* original c72b, guest PC 0x0c09e5d2 */
if(!s->budget--) { s->failed_pc=0x0c09e5d2u; return 0; }
r[0]=code_base|0x0009e680u;
goto P_0c09e5d4;
P_0c09e5d4: /* original f308, guest PC 0x0c09e5d4 */
if(!s->budget--) { s->failed_pc=0x0c09e5d4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09e5d6;
P_0c09e5d6: /* original e058, guest PC 0x0c09e5d6 */
if(!s->budget--) { s->failed_pc=0x0c09e5d6u; return 0; }
r[0]=0x00000058u;
goto P_0c09e5d8;
P_0c09e5d8: /* original ff37, guest PC 0x0c09e5d8 */
if(!s->budget--) { s->failed_pc=0x0c09e5d8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e5da;
P_0c09e5da: /* original e05c, guest PC 0x0c09e5da */
if(!s->budget--) { s->failed_pc=0x0c09e5dau; return 0; }
r[0]=0x0000005cu;
goto P_0c09e5dc;
P_0c09e5dc: /* original f38d, guest PC 0x0c09e5dc */
if(!s->budget--) { s->failed_pc=0x0c09e5dcu; return 0; }
fr[3]=0;
goto P_0c09e5de;
P_0c09e5de: /* original ff37, guest PC 0x0c09e5de */
if(!s->budget--) { s->failed_pc=0x0c09e5deu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e5e0;
P_0c09e5e0: /* original c728, guest PC 0x0c09e5e0 */
if(!s->budget--) { s->failed_pc=0x0c09e5e0u; return 0; }
r[0]=code_base|0x0009e684u;
goto P_0c09e5e2;
P_0c09e5e2: /* original f308, guest PC 0x0c09e5e2 */
if(!s->budget--) { s->failed_pc=0x0c09e5e2u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09e5e4;
P_0c09e5e4: /* original e060, guest PC 0x0c09e5e4 */
if(!s->budget--) { s->failed_pc=0x0c09e5e4u; return 0; }
r[0]=0x00000060u;
goto P_0c09e5e6;
P_0c09e5e6: /* original 64f3, guest PC 0x0c09e5e6 */
if(!s->budget--) { s->failed_pc=0x0c09e5e6u; return 0; }
r[4]=r[15];
goto P_0c09e5e8;
P_0c09e5e8: /* original ff37, guest PC 0x0c09e5e8 */
if(!s->budget--) { s->failed_pc=0x0c09e5e8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e5ea;
P_0c09e5ea: /* original d327, guest PC 0x0c09e5ea */
if(!s->budget--) { s->failed_pc=0x0c09e5eau; return 0; }
r[3]=read(ram,0x0c09e688u,4);
goto P_0c09e5ec;
P_0c09e5ec: /* original 430b, guest PC 0x0c09e5ec */
if(!s->budget--) { s->failed_pc=0x0c09e5ecu; return 0; }
target=r[3];
r[16]=code_base|0x0c09e5f0u;
r[4]+=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e5f0u) { target=s->pc; goto dispatch; }
goto P_0c09e5f0;
P_0c09e5ee: /* original 740c, guest PC 0x0c09e5ee */
if(!s->budget--) { s->failed_pc=0x0c09e5eeu; return 0; }
r[4]+=0x0000000cu;
goto P_0c09e5f0;
P_0c09e5f0: /* original d226, guest PC 0x0c09e5f0 */
if(!s->budget--) { s->failed_pc=0x0c09e5f0u; return 0; }
r[2]=read(ram,0x0c09e68cu,4);
goto P_0c09e5f2;
P_0c09e5f2: /* original 420b, guest PC 0x0c09e5f2 */
if(!s->budget--) { s->failed_pc=0x0c09e5f2u; return 0; }
target=r[2];
r[16]=code_base|0x0c09e5f6u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e5f6u) { target=s->pc; goto dispatch; }
goto P_0c09e5f6;
P_0c09e5f4: /* original e400, guest PC 0x0c09e5f4 */
if(!s->budget--) { s->failed_pc=0x0c09e5f4u; return 0; }
r[4]=0x00000000u;
goto P_0c09e5f6;
P_0c09e5f6: /* original d326, guest PC 0x0c09e5f6 */
if(!s->budget--) { s->failed_pc=0x0c09e5f6u; return 0; }
r[3]=read(ram,0x0c09e690u,4);
goto P_0c09e5f8;
P_0c09e5f8: /* original 65f3, guest PC 0x0c09e5f8 */
if(!s->budget--) { s->failed_pc=0x0c09e5f8u; return 0; }
r[5]=r[15];
goto P_0c09e5fa;
P_0c09e5fa: /* original 64f3, guest PC 0x0c09e5fa */
if(!s->budget--) { s->failed_pc=0x0c09e5fau; return 0; }
r[4]=r[15];
goto P_0c09e5fc;
P_0c09e5fc: /* original 754c, guest PC 0x0c09e5fc */
if(!s->budget--) { s->failed_pc=0x0c09e5fcu; return 0; }
r[5]+=0x0000004cu;
goto P_0c09e5fe;
P_0c09e5fe: /* original 430b, guest PC 0x0c09e5fe */
if(!s->budget--) { s->failed_pc=0x0c09e5feu; return 0; }
target=r[3];
r[16]=code_base|0x0c09e602u;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e602u) { target=s->pc; goto dispatch; }
goto P_0c09e602;
P_0c09e600: /* original 7458, guest PC 0x0c09e600 */
if(!s->budget--) { s->failed_pc=0x0c09e600u; return 0; }
r[4]+=0x00000058u;
goto P_0c09e602;
P_0c09e602: /* original d224, guest PC 0x0c09e602 */
if(!s->budget--) { s->failed_pc=0x0c09e602u; return 0; }
r[2]=read(ram,0x0c09e694u,4);
goto P_0c09e604;
P_0c09e604: /* original 420b, guest PC 0x0c09e604 */
if(!s->budget--) { s->failed_pc=0x0c09e604u; return 0; }
target=r[2];
r[16]=code_base|0x0c09e608u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e608u) { target=s->pc; goto dispatch; }
goto P_0c09e608;
P_0c09e606: /* original e401, guest PC 0x0c09e606 */
if(!s->budget--) { s->failed_pc=0x0c09e606u; return 0; }
r[4]=0x00000001u;
goto P_0c09e608;
P_0c09e608: /* original e04c, guest PC 0x0c09e608 */
if(!s->budget--) { s->failed_pc=0x0c09e608u; return 0; }
r[0]=0x0000004cu;
goto P_0c09e60a;
P_0c09e60a: /* original f3f6, guest PC 0x0c09e60a */
if(!s->budget--) { s->failed_pc=0x0c09e60au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e60c;
P_0c09e60c: /* original 9026, guest PC 0x0c09e60c */
if(!s->budget--) { s->failed_pc=0x0c09e60cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e65cu,2);
goto P_0c09e60e;
P_0c09e60e: /* original fe37, guest PC 0x0c09e60e */
if(!s->budget--) { s->failed_pc=0x0c09e60eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09e610;
P_0c09e610: /* original e050, guest PC 0x0c09e610 */
if(!s->budget--) { s->failed_pc=0x0c09e610u; return 0; }
r[0]=0x00000050u;
goto P_0c09e612;
P_0c09e612: /* original f3f6, guest PC 0x0c09e612 */
if(!s->budget--) { s->failed_pc=0x0c09e612u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e614;
P_0c09e614: /* original 9023, guest PC 0x0c09e614 */
if(!s->budget--) { s->failed_pc=0x0c09e614u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e65eu,2);
goto P_0c09e616;
P_0c09e616: /* original fe37, guest PC 0x0c09e616 */
if(!s->budget--) { s->failed_pc=0x0c09e616u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09e618;
P_0c09e618: /* original e054, guest PC 0x0c09e618 */
if(!s->budget--) { s->failed_pc=0x0c09e618u; return 0; }
r[0]=0x00000054u;
goto P_0c09e61a;
P_0c09e61a: /* original f3f6, guest PC 0x0c09e61a */
if(!s->budget--) { s->failed_pc=0x0c09e61au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e61c;
P_0c09e61c: /* original 9020, guest PC 0x0c09e61c */
if(!s->budget--) { s->failed_pc=0x0c09e61cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e660u,2);
goto P_0c09e61e;
P_0c09e61e: /* original fe37, guest PC 0x0c09e61e */
if(!s->budget--) { s->failed_pc=0x0c09e61eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09e620;
P_0c09e620: /* original e060, guest PC 0x0c09e620 */
if(!s->budget--) { s->failed_pc=0x0c09e620u; return 0; }
r[0]=0x00000060u;
goto P_0c09e622;
P_0c09e622: /* original f3f6, guest PC 0x0c09e622 */
if(!s->budget--) { s->failed_pc=0x0c09e622u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e624;
P_0c09e624: /* original e060, guest PC 0x0c09e624 */
if(!s->budget--) { s->failed_pc=0x0c09e624u; return 0; }
r[0]=0x00000060u;
goto P_0c09e626;
P_0c09e626: /* original f34d, guest PC 0x0c09e626 */
if(!s->budget--) { s->failed_pc=0x0c09e626u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09e628;
P_0c09e628: /* original ff37, guest PC 0x0c09e628 */
if(!s->budget--) { s->failed_pc=0x0c09e628u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09e62a;
P_0c09e62a: /* original d318, guest PC 0x0c09e62a */
if(!s->budget--) { s->failed_pc=0x0c09e62au; return 0; }
r[3]=read(ram,0x0c09e68cu,4);
goto P_0c09e62c;
P_0c09e62c: /* original 430b, guest PC 0x0c09e62c */
if(!s->budget--) { s->failed_pc=0x0c09e62cu; return 0; }
target=r[3];
r[16]=code_base|0x0c09e630u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e630u) { target=s->pc; goto dispatch; }
goto P_0c09e630;
P_0c09e62e: /* original e400, guest PC 0x0c09e62e */
if(!s->budget--) { s->failed_pc=0x0c09e62eu; return 0; }
r[4]=0x00000000u;
goto P_0c09e630;
P_0c09e630: /* original d217, guest PC 0x0c09e630 */
if(!s->budget--) { s->failed_pc=0x0c09e630u; return 0; }
r[2]=read(ram,0x0c09e690u,4);
goto P_0c09e632;
P_0c09e632: /* original 65f3, guest PC 0x0c09e632 */
if(!s->budget--) { s->failed_pc=0x0c09e632u; return 0; }
r[5]=r[15];
goto P_0c09e634;
P_0c09e634: /* original 64f3, guest PC 0x0c09e634 */
if(!s->budget--) { s->failed_pc=0x0c09e634u; return 0; }
r[4]=r[15];
goto P_0c09e636;
P_0c09e636: /* original 754c, guest PC 0x0c09e636 */
if(!s->budget--) { s->failed_pc=0x0c09e636u; return 0; }
r[5]+=0x0000004cu;
goto P_0c09e638;
P_0c09e638: /* original 420b, guest PC 0x0c09e638 */
if(!s->budget--) { s->failed_pc=0x0c09e638u; return 0; }
target=r[2];
r[16]=code_base|0x0c09e63cu;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e63cu) { target=s->pc; goto dispatch; }
goto P_0c09e63c;
P_0c09e63a: /* original 7458, guest PC 0x0c09e63a */
if(!s->budget--) { s->failed_pc=0x0c09e63au; return 0; }
r[4]+=0x00000058u;
goto P_0c09e63c;
P_0c09e63c: /* original d315, guest PC 0x0c09e63c */
if(!s->budget--) { s->failed_pc=0x0c09e63cu; return 0; }
r[3]=read(ram,0x0c09e694u,4);
goto P_0c09e63e;
P_0c09e63e: /* original 430b, guest PC 0x0c09e63e */
if(!s->budget--) { s->failed_pc=0x0c09e63eu; return 0; }
target=r[3];
r[16]=code_base|0x0c09e642u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e642u) { target=s->pc; goto dispatch; }
goto P_0c09e642;
P_0c09e640: /* original e401, guest PC 0x0c09e640 */
if(!s->budget--) { s->failed_pc=0x0c09e640u; return 0; }
r[4]=0x00000001u;
goto P_0c09e642;
P_0c09e642: /* original e04c, guest PC 0x0c09e642 */
if(!s->budget--) { s->failed_pc=0x0c09e642u; return 0; }
r[0]=0x0000004cu;
goto P_0c09e644;
P_0c09e644: /* original f3f6, guest PC 0x0c09e644 */
if(!s->budget--) { s->failed_pc=0x0c09e644u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e646;
P_0c09e646: /* original 900c, guest PC 0x0c09e646 */
if(!s->budget--) { s->failed_pc=0x0c09e646u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e662u,2);
goto P_0c09e648;
P_0c09e648: /* original fe37, guest PC 0x0c09e648 */
if(!s->budget--) { s->failed_pc=0x0c09e648u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09e64a;
P_0c09e64a: /* original a025, guest PC 0x0c09e64a */
if(!s->budget--) { s->failed_pc=0x0c09e64au; return 0; }
goto P_0c09e698;
P_0c09e64c: /* original 0009, guest PC 0x0c09e64c */
if(!s->budget--) { s->failed_pc=0x0c09e64cu; return 0; }
if(!vf3_matrix_family(0x0c09e64eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09e64eu; return 0; } return 1;
P_0c09e698: /* original e050, guest PC 0x0c09e698 */
if(!s->budget--) { s->failed_pc=0x0c09e698u; return 0; }
r[0]=0x00000050u;
goto P_0c09e69a;
P_0c09e69a: /* original f3f6, guest PC 0x0c09e69a */
if(!s->budget--) { s->failed_pc=0x0c09e69au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e69c;
P_0c09e69c: /* original 909b, guest PC 0x0c09e69c */
if(!s->budget--) { s->failed_pc=0x0c09e69cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e7d6u,2);
goto P_0c09e69e;
P_0c09e69e: /* original fe37, guest PC 0x0c09e69e */
if(!s->budget--) { s->failed_pc=0x0c09e69eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09e6a0;
P_0c09e6a0: /* original e054, guest PC 0x0c09e6a0 */
if(!s->budget--) { s->failed_pc=0x0c09e6a0u; return 0; }
r[0]=0x00000054u;
goto P_0c09e6a2;
P_0c09e6a2: /* original f3f6, guest PC 0x0c09e6a2 */
if(!s->budget--) { s->failed_pc=0x0c09e6a2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09e6a4;
P_0c09e6a4: /* original 7f64, guest PC 0x0c09e6a4 */
if(!s->budget--) { s->failed_pc=0x0c09e6a4u; return 0; }
r[15]+=0x00000064u;
goto P_0c09e6a6;
P_0c09e6a6: /* original 4f26, guest PC 0x0c09e6a6 */
if(!s->budget--) { s->failed_pc=0x0c09e6a6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09e6a8;
P_0c09e6a8: /* original 9096, guest PC 0x0c09e6a8 */
if(!s->budget--) { s->failed_pc=0x0c09e6a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e7d8u,2);
goto P_0c09e6aa;
P_0c09e6aa: /* original fe37, guest PC 0x0c09e6aa */
if(!s->budget--) { s->failed_pc=0x0c09e6aau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09e6ac;
P_0c09e6ac: /* original 6df6, guest PC 0x0c09e6ac */
if(!s->budget--) { s->failed_pc=0x0c09e6acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09e6ae;
P_0c09e6ae: /* original 000b, guest PC 0x0c09e6ae */
if(!s->budget--) { s->failed_pc=0x0c09e6aeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09e6b0: /* original 6ef6, guest PC 0x0c09e6b0 */
if(!s->budget--) { s->failed_pc=0x0c09e6b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09e6b2u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
