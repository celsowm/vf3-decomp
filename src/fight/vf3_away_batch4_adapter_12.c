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
int vf3_away_batch4_adapter_12(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04c3c6u: goto P_0c04c3c6;
case 0x0c04c3c8u: goto P_0c04c3c8;
case 0x0c04c3cau: goto P_0c04c3ca;
case 0x0c04c3ccu: goto P_0c04c3cc;
case 0x0c04c3ceu: goto P_0c04c3ce;
case 0x0c04c3d0u: goto P_0c04c3d0;
case 0x0c04c3d2u: goto P_0c04c3d2;
case 0x0c04c3d4u: goto P_0c04c3d4;
case 0x0c04c3d6u: goto P_0c04c3d6;
case 0x0c04c3d8u: goto P_0c04c3d8;
case 0x0c04c3dau: goto P_0c04c3da;
case 0x0c04c3dcu: goto P_0c04c3dc;
case 0x0c04c3deu: goto P_0c04c3de;
case 0x0c04c3e0u: goto P_0c04c3e0;
case 0x0c04c3e2u: goto P_0c04c3e2;
case 0x0c04c3e4u: goto P_0c04c3e4;
case 0x0c04c3e6u: goto P_0c04c3e6;
case 0x0c04c47cu: goto P_0c04c47c;
case 0x0c04c47eu: goto P_0c04c47e;
case 0x0c04c480u: goto P_0c04c480;
case 0x0c04c482u: goto P_0c04c482;
case 0x0c04c484u: goto P_0c04c484;
case 0x0c04c486u: goto P_0c04c486;
case 0x0c04c488u: goto P_0c04c488;
case 0x0c04c48au: goto P_0c04c48a;
case 0x0c04c49cu: goto P_0c04c49c;
case 0x0c04c49eu: goto P_0c04c49e;
case 0x0c04c4a0u: goto P_0c04c4a0;
case 0x0c04c4a2u: goto P_0c04c4a2;
case 0x0c04c4a4u: goto P_0c04c4a4;
case 0x0c04c4a6u: goto P_0c04c4a6;
case 0x0c04c4a8u: goto P_0c04c4a8;
case 0x0c04c4aau: goto P_0c04c4aa;
case 0x0c04c4acu: goto P_0c04c4ac;
case 0x0c04c4aeu: goto P_0c04c4ae;
case 0x0c04c4b0u: goto P_0c04c4b0;
case 0x0c04c4b2u: goto P_0c04c4b2;
case 0x0c04c4b4u: goto P_0c04c4b4;
case 0x0c04c4b6u: goto P_0c04c4b6;
case 0x0c04c4b8u: goto P_0c04c4b8;
case 0x0c04c4bau: goto P_0c04c4ba;
case 0x0c04c4bcu: goto P_0c04c4bc;
case 0x0c04c4beu: goto P_0c04c4be;
case 0x0c04c4f0u: goto P_0c04c4f0;
case 0x0c04c4f2u: goto P_0c04c4f2;
case 0x0c04c4f4u: goto P_0c04c4f4;
case 0x0c04c4f6u: goto P_0c04c4f6;
case 0x0c04c4f8u: goto P_0c04c4f8;
case 0x0c04c4fau: goto P_0c04c4fa;
case 0x0c04c4fcu: goto P_0c04c4fc;
case 0x0c04c4feu: goto P_0c04c4fe;
case 0x0c04c500u: goto P_0c04c500;
case 0x0c04c502u: goto P_0c04c502;
case 0x0c04c504u: goto P_0c04c504;
case 0x0c04c506u: goto P_0c04c506;
case 0x0c04c508u: goto P_0c04c508;
case 0x0c04c50au: goto P_0c04c50a;
case 0x0c04c50cu: goto P_0c04c50c;
case 0x0c04c50eu: goto P_0c04c50e;
case 0x0c04c510u: goto P_0c04c510;
case 0x0c04c512u: goto P_0c04c512;
case 0x0c04c514u: goto P_0c04c514;
case 0x0c04c516u: goto P_0c04c516;
case 0x0c04c518u: goto P_0c04c518;
case 0x0c04c51au: goto P_0c04c51a;
case 0x0c04c51cu: goto P_0c04c51c;
case 0x0c04c51eu: goto P_0c04c51e;
case 0x0c04c520u: goto P_0c04c520;
case 0x0c04c522u: goto P_0c04c522;
case 0x0c04c524u: goto P_0c04c524;
case 0x0c04c526u: goto P_0c04c526;
case 0x0c04c528u: goto P_0c04c528;
case 0x0c04c52au: goto P_0c04c52a;
case 0x0c04c52cu: goto P_0c04c52c;
case 0x0c04c52eu: goto P_0c04c52e;
case 0x0c04c530u: goto P_0c04c530;
case 0x0c04c532u: goto P_0c04c532;
case 0x0c04c534u: goto P_0c04c534;
case 0x0c04c536u: goto P_0c04c536;
case 0x0c04c538u: goto P_0c04c538;
case 0x0c04c53au: goto P_0c04c53a;
case 0x0c04c53cu: goto P_0c04c53c;
case 0x0c04c53eu: goto P_0c04c53e;
case 0x0c04c540u: goto P_0c04c540;
case 0x0c04c542u: goto P_0c04c542;
case 0x0c04c544u: goto P_0c04c544;
case 0x0c04c546u: goto P_0c04c546;
case 0x0c04c548u: goto P_0c04c548;
case 0x0c04c54au: goto P_0c04c54a;
case 0x0c04c54cu: goto P_0c04c54c;
case 0x0c04c54eu: goto P_0c04c54e;
case 0x0c04c550u: goto P_0c04c550;
case 0x0c04c552u: goto P_0c04c552;
case 0x0c04c554u: goto P_0c04c554;
case 0x0c04c556u: goto P_0c04c556;
case 0x0c04c558u: goto P_0c04c558;
case 0x0c04c55au: goto P_0c04c55a;
case 0x0c04c55cu: goto P_0c04c55c;
case 0x0c04c55eu: goto P_0c04c55e;
case 0x0c04c560u: goto P_0c04c560;
case 0x0c04c562u: goto P_0c04c562;
case 0x0c04c564u: goto P_0c04c564;
case 0x0c04c566u: goto P_0c04c566;
case 0x0c04c568u: goto P_0c04c568;
case 0x0c04c56au: goto P_0c04c56a;
case 0x0c04c56cu: goto P_0c04c56c;
case 0x0c04c56eu: goto P_0c04c56e;
case 0x0c04c570u: goto P_0c04c570;
case 0x0c04c572u: goto P_0c04c572;
case 0x0c04c574u: goto P_0c04c574;
case 0x0c04c576u: goto P_0c04c576;
case 0x0c04c578u: goto P_0c04c578;
case 0x0c04c57au: goto P_0c04c57a;
case 0x0c04c5a0u: goto P_0c04c5a0;
case 0x0c04c5a2u: goto P_0c04c5a2;
case 0x0c04c5a4u: goto P_0c04c5a4;
case 0x0c04c5a6u: goto P_0c04c5a6;
case 0x0c04c5a8u: goto P_0c04c5a8;
case 0x0c04c5aau: goto P_0c04c5aa;
case 0x0c04c5acu: goto P_0c04c5ac;
case 0x0c04c5aeu: goto P_0c04c5ae;
case 0x0c04c5b0u: goto P_0c04c5b0;
case 0x0c04c5b2u: goto P_0c04c5b2;
case 0x0c04c5b4u: goto P_0c04c5b4;
case 0x0c04c5b6u: goto P_0c04c5b6;
case 0x0c04c5b8u: goto P_0c04c5b8;
case 0x0c04c5bau: goto P_0c04c5ba;
case 0x0c04c5bcu: goto P_0c04c5bc;
case 0x0c04c5beu: goto P_0c04c5be;
case 0x0c04c5c0u: goto P_0c04c5c0;
case 0x0c04c5c2u: goto P_0c04c5c2;
case 0x0c04c5c4u: goto P_0c04c5c4;
case 0x0c04c5c6u: goto P_0c04c5c6;
case 0x0c04c5c8u: goto P_0c04c5c8;
case 0x0c04c5cau: goto P_0c04c5ca;
case 0x0c04c5ccu: goto P_0c04c5cc;
case 0x0c04c5ceu: goto P_0c04c5ce;
case 0x0c04c5d0u: goto P_0c04c5d0;
case 0x0c04c5d2u: goto P_0c04c5d2;
case 0x0c04c5d4u: goto P_0c04c5d4;
case 0x0c04c5d6u: goto P_0c04c5d6;
case 0x0c04c5d8u: goto P_0c04c5d8;
case 0x0c04c5dau: goto P_0c04c5da;
case 0x0c04c5dcu: goto P_0c04c5dc;
case 0x0c04c5deu: goto P_0c04c5de;
case 0x0c04c5e0u: goto P_0c04c5e0;
case 0x0c04c5e2u: goto P_0c04c5e2;
case 0x0c04c5e4u: goto P_0c04c5e4;
case 0x0c04c5e6u: goto P_0c04c5e6;
case 0x0c04c5e8u: goto P_0c04c5e8;
case 0x0c04c5eau: goto P_0c04c5ea;
case 0x0c04c5ecu: goto P_0c04c5ec;
case 0x0c04c5eeu: goto P_0c04c5ee;
case 0x0c04c5f0u: goto P_0c04c5f0;
case 0x0c04c5f2u: goto P_0c04c5f2;
case 0x0c04c5f4u: goto P_0c04c5f4;
case 0x0c04c5f6u: goto P_0c04c5f6;
case 0x0c04c5f8u: goto P_0c04c5f8;
case 0x0c04c5fau: goto P_0c04c5fa;
case 0x0c04c5fcu: goto P_0c04c5fc;
case 0x0c04c5feu: goto P_0c04c5fe;
case 0x0c04c600u: goto P_0c04c600;
case 0x0c04c602u: goto P_0c04c602;
case 0x0c04c604u: goto P_0c04c604;
case 0x0c04c606u: goto P_0c04c606;
case 0x0c04c608u: goto P_0c04c608;
case 0x0c04c60au: goto P_0c04c60a;
case 0x0c04c60cu: goto P_0c04c60c;
case 0x0c04c60eu: goto P_0c04c60e;
case 0x0c04c610u: goto P_0c04c610;
case 0x0c04c612u: goto P_0c04c612;
case 0x0c04c614u: goto P_0c04c614;
case 0x0c04c616u: goto P_0c04c616;
case 0x0c04c618u: goto P_0c04c618;
case 0x0c04c61au: goto P_0c04c61a;
case 0x0c04c61cu: goto P_0c04c61c;
case 0x0c04c61eu: goto P_0c04c61e;
case 0x0c04c620u: goto P_0c04c620;
case 0x0c04c622u: goto P_0c04c622;
case 0x0c04c624u: goto P_0c04c624;
case 0x0c04c626u: goto P_0c04c626;
case 0x0c04c628u: goto P_0c04c628;
case 0x0c04c62au: goto P_0c04c62a;
case 0x0c04c62cu: goto P_0c04c62c;
case 0x0c04c62eu: goto P_0c04c62e;
case 0x0c04c630u: goto P_0c04c630;
case 0x0c04c632u: goto P_0c04c632;
case 0x0c04c634u: goto P_0c04c634;
case 0x0c04c636u: goto P_0c04c636;
case 0x0c04c638u: goto P_0c04c638;
case 0x0c04c63au: goto P_0c04c63a;
case 0x0c04c63cu: goto P_0c04c63c;
case 0x0c04c63eu: goto P_0c04c63e;
case 0x0c04c640u: goto P_0c04c640;
case 0x0c04c642u: goto P_0c04c642;
case 0x0c04c644u: goto P_0c04c644;
case 0x0c04c646u: goto P_0c04c646;
case 0x0c04c648u: goto P_0c04c648;
case 0x0c04c64au: goto P_0c04c64a;
case 0x0c04c64cu: goto P_0c04c64c;
case 0x0c04c64eu: goto P_0c04c64e;
case 0x0c04c650u: goto P_0c04c650;
case 0x0c04c652u: goto P_0c04c652;
case 0x0c04c654u: goto P_0c04c654;
case 0x0c04c656u: goto P_0c04c656;
case 0x0c04c658u: goto P_0c04c658;
case 0x0c04c65au: goto P_0c04c65a;
case 0x0c04c65cu: goto P_0c04c65c;
case 0x0c04c65eu: goto P_0c04c65e;
case 0x0c04c660u: goto P_0c04c660;
case 0x0c04c662u: goto P_0c04c662;
case 0x0c04c664u: goto P_0c04c664;
case 0x0c04c666u: goto P_0c04c666;
case 0x0c04c668u: goto P_0c04c668;
case 0x0c04c66au: goto P_0c04c66a;
case 0x0c04c66cu: goto P_0c04c66c;
case 0x0c04c66eu: goto P_0c04c66e;
case 0x0c04c670u: goto P_0c04c670;
case 0x0c04c672u: goto P_0c04c672;
case 0x0c04c674u: goto P_0c04c674;
case 0x0c04c676u: goto P_0c04c676;
case 0x0c04c678u: goto P_0c04c678;
case 0x0c04c67au: goto P_0c04c67a;
case 0x0c04c67cu: goto P_0c04c67c;
case 0x0c04c67eu: goto P_0c04c67e;
case 0x0c04c680u: goto P_0c04c680;
case 0x0c04c682u: goto P_0c04c682;
case 0x0c04c684u: goto P_0c04c684;
case 0x0c04c686u: goto P_0c04c686;
case 0x0c04c688u: goto P_0c04c688;
case 0x0c04c68au: goto P_0c04c68a;
case 0x0c04c6c8u: goto P_0c04c6c8;
case 0x0c04c6cau: goto P_0c04c6ca;
case 0x0c04c6ccu: goto P_0c04c6cc;
case 0x0c04c6ceu: goto P_0c04c6ce;
case 0x0c04c6d0u: goto P_0c04c6d0;
case 0x0c04c6d2u: goto P_0c04c6d2;
case 0x0c04c6d4u: goto P_0c04c6d4;
case 0x0c04c6d6u: goto P_0c04c6d6;
case 0x0c04c6d8u: goto P_0c04c6d8;
case 0x0c04c6dau: goto P_0c04c6da;
case 0x0c04c6dcu: goto P_0c04c6dc;
case 0x0c04c6deu: goto P_0c04c6de;
case 0x0c04c6e0u: goto P_0c04c6e0;
case 0x0c04c6e2u: goto P_0c04c6e2;
case 0x0c04c6e4u: goto P_0c04c6e4;
case 0x0c04c6e6u: goto P_0c04c6e6;
case 0x0c04c6e8u: goto P_0c04c6e8;
case 0x0c04c6eau: goto P_0c04c6ea;
case 0x0c04c6ecu: goto P_0c04c6ec;
case 0x0c04c6eeu: goto P_0c04c6ee;
case 0x0c04c6f0u: goto P_0c04c6f0;
case 0x0c04c6f2u: goto P_0c04c6f2;
case 0x0c04c6f4u: goto P_0c04c6f4;
case 0x0c04c6f6u: goto P_0c04c6f6;
case 0x0c04c6f8u: goto P_0c04c6f8;
case 0x0c04c6fau: goto P_0c04c6fa;
case 0x0c04c6fcu: goto P_0c04c6fc;
case 0x0c04c6feu: goto P_0c04c6fe;
case 0x0c04c700u: goto P_0c04c700;
case 0x0c04c702u: goto P_0c04c702;
case 0x0c04c704u: goto P_0c04c704;
case 0x0c04c706u: goto P_0c04c706;
case 0x0c04c708u: goto P_0c04c708;
case 0x0c04c70au: goto P_0c04c70a;
case 0x0c04c70cu: goto P_0c04c70c;
case 0x0c04c70eu: goto P_0c04c70e;
case 0x0c04c710u: goto P_0c04c710;
case 0x0c04c712u: goto P_0c04c712;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04c3c6: /* original 2fe6, guest PC 0x0c04c3c6 */
if(!s->budget--) { s->failed_pc=0x0c04c3c6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c3c8;
P_0c04c3c8: /* original 6e43, guest PC 0x0c04c3c8 */
if(!s->budget--) { s->failed_pc=0x0c04c3c8u; return 0; }
r[14]=r[4];
goto P_0c04c3ca;
P_0c04c3ca: /* original 4e08, guest PC 0x0c04c3ca */
if(!s->budget--) { s->failed_pc=0x0c04c3cau; return 0; }
r[14]<<=2;
goto P_0c04c3cc;
P_0c04c3cc: /* original d318, guest PC 0x0c04c3cc */
if(!s->budget--) { s->failed_pc=0x0c04c3ccu; return 0; }
r[3]=read(ram,0x0c04c430u,4);
goto P_0c04c3ce;
P_0c04c3ce: /* original 4e08, guest PC 0x0c04c3ce */
if(!s->budget--) { s->failed_pc=0x0c04c3ceu; return 0; }
r[14]<<=2;
goto P_0c04c3d0;
P_0c04c3d0: /* original 4e08, guest PC 0x0c04c3d0 */
if(!s->budget--) { s->failed_pc=0x0c04c3d0u; return 0; }
r[14]<<=2;
goto P_0c04c3d2;
P_0c04c3d2: /* original 4e00, guest PC 0x0c04c3d2 */
if(!s->budget--) { s->failed_pc=0x0c04c3d2u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c04c3d4;
P_0c04c3d4: /* original e078, guest PC 0x0c04c3d4 */
if(!s->budget--) { s->failed_pc=0x0c04c3d4u; return 0; }
r[0]=0x00000078u;
goto P_0c04c3d6;
P_0c04c3d6: /* original 3e3c, guest PC 0x0c04c3d6 */
if(!s->budget--) { s->failed_pc=0x0c04c3d6u; return 0; }
r[14]+=r[3];
goto P_0c04c3d8;
P_0c04c3d8: /* original 02ee, guest PC 0x0c04c3d8 */
if(!s->budget--) { s->failed_pc=0x0c04c3d8u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c04c3da;
P_0c04c3da: /* original 2228, guest PC 0x0c04c3da */
if(!s->budget--) { s->failed_pc=0x0c04c3dau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04c3dc;
P_0c04c3dc: /* original 8902, guest PC 0x0c04c3dc */
if(!s->budget--) { s->failed_pc=0x0c04c3dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c3e4; }
goto P_0c04c3de;
P_0c04c3de: /* original 02ee, guest PC 0x0c04c3de */
if(!s->budget--) { s->failed_pc=0x0c04c3deu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c04c3e0;
P_0c04c3e0: /* original 422b, guest PC 0x0c04c3e0 */
if(!s->budget--) { s->failed_pc=0x0c04c3e0u; return 0; }
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
P_0c04c3e2: /* original 6ef6, guest PC 0x0c04c3e2 */
if(!s->budget--) { s->failed_pc=0x0c04c3e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04c3e4;
P_0c04c3e4: /* original 000b, guest PC 0x0c04c3e4 */
if(!s->budget--) { s->failed_pc=0x0c04c3e4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04c3e6: /* original 6ef6, guest PC 0x0c04c3e6 */
if(!s->budget--) { s->failed_pc=0x0c04c3e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04c3e8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04c3e8u; return 0; } return 1;
P_0c04c47c: /* original 4408, guest PC 0x0c04c47c */
if(!s->budget--) { s->failed_pc=0x0c04c47cu; return 0; }
r[4]<<=2;
goto P_0c04c47e;
P_0c04c47e: /* original d31b, guest PC 0x0c04c47e */
if(!s->budget--) { s->failed_pc=0x0c04c47eu; return 0; }
r[3]=read(ram,0x0c04c4ecu,4);
goto P_0c04c480;
P_0c04c480: /* original 4408, guest PC 0x0c04c480 */
if(!s->budget--) { s->failed_pc=0x0c04c480u; return 0; }
r[4]<<=2;
goto P_0c04c482;
P_0c04c482: /* original 4408, guest PC 0x0c04c482 */
if(!s->budget--) { s->failed_pc=0x0c04c482u; return 0; }
r[4]<<=2;
goto P_0c04c484;
P_0c04c484: /* original 4400, guest PC 0x0c04c484 */
if(!s->budget--) { s->failed_pc=0x0c04c484u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c04c486;
P_0c04c486: /* original 343c, guest PC 0x0c04c486 */
if(!s->budget--) { s->failed_pc=0x0c04c486u; return 0; }
r[4]+=r[3];
goto P_0c04c488;
P_0c04c488: /* original 000b, guest PC 0x0c04c488 */
if(!s->budget--) { s->failed_pc=0x0c04c488u; return 0; }
target=r[16];
r[0]=read(ram,r[4]+4,4);
s->pc=target; return ram->oob==0;
P_0c04c48a: /* original 5041, guest PC 0x0c04c48a */
if(!s->budget--) { s->failed_pc=0x0c04c48au; return 0; }
r[0]=read(ram,r[4]+4,4);
if(!vf3_matrix_family(0x0c04c48cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04c48cu; return 0; } return 1;
P_0c04c49c: /* original 4408, guest PC 0x0c04c49c */
if(!s->budget--) { s->failed_pc=0x0c04c49cu; return 0; }
r[4]<<=2;
goto P_0c04c49e;
P_0c04c49e: /* original d313, guest PC 0x0c04c49e */
if(!s->budget--) { s->failed_pc=0x0c04c49eu; return 0; }
r[3]=read(ram,0x0c04c4ecu,4);
goto P_0c04c4a0;
P_0c04c4a0: /* original 4408, guest PC 0x0c04c4a0 */
if(!s->budget--) { s->failed_pc=0x0c04c4a0u; return 0; }
r[4]<<=2;
goto P_0c04c4a2;
P_0c04c4a2: /* original 4408, guest PC 0x0c04c4a2 */
if(!s->budget--) { s->failed_pc=0x0c04c4a2u; return 0; }
r[4]<<=2;
goto P_0c04c4a4;
P_0c04c4a4: /* original 4400, guest PC 0x0c04c4a4 */
if(!s->budget--) { s->failed_pc=0x0c04c4a4u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c04c4a6;
P_0c04c4a6: /* original 343c, guest PC 0x0c04c4a6 */
if(!s->budget--) { s->failed_pc=0x0c04c4a6u; return 0; }
r[4]+=r[3];
goto P_0c04c4a8;
P_0c04c4a8: /* original 1455, guest PC 0x0c04c4a8 */
if(!s->budget--) { s->failed_pc=0x0c04c4a8u; return 0; }
write(ram,r[4]+20,r[5],4);
goto P_0c04c4aa;
P_0c04c4aa: /* original 1466, guest PC 0x0c04c4aa */
if(!s->budget--) { s->failed_pc=0x0c04c4aau; return 0; }
write(ram,r[4]+24,r[6],4);
goto P_0c04c4ac;
P_0c04c4ac: /* original 1477, guest PC 0x0c04c4ac */
if(!s->budget--) { s->failed_pc=0x0c04c4acu; return 0; }
write(ram,r[4]+28,r[7],4);
goto P_0c04c4ae;
P_0c04c4ae: /* original 62f2, guest PC 0x0c04c4ae */
if(!s->budget--) { s->failed_pc=0x0c04c4aeu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04c4b0;
P_0c04c4b0: /* original 1428, guest PC 0x0c04c4b0 */
if(!s->budget--) { s->failed_pc=0x0c04c4b0u; return 0; }
write(ram,r[4]+32,r[2],4);
goto P_0c04c4b2;
P_0c04c4b2: /* original 51f1, guest PC 0x0c04c4b2 */
if(!s->budget--) { s->failed_pc=0x0c04c4b2u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c04c4b4;
P_0c04c4b4: /* original 1419, guest PC 0x0c04c4b4 */
if(!s->budget--) { s->failed_pc=0x0c04c4b4u; return 0; }
write(ram,r[4]+36,r[1],4);
goto P_0c04c4b6;
P_0c04c4b6: /* original e101, guest PC 0x0c04c4b6 */
if(!s->budget--) { s->failed_pc=0x0c04c4b6u; return 0; }
r[1]=0x00000001u;
goto P_0c04c4b8;
P_0c04c4b8: /* original 52f2, guest PC 0x0c04c4b8 */
if(!s->budget--) { s->failed_pc=0x0c04c4b8u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c04c4ba;
P_0c04c4ba: /* original 142a, guest PC 0x0c04c4ba */
if(!s->budget--) { s->failed_pc=0x0c04c4bau; return 0; }
write(ram,r[4]+40,r[2],4);
goto P_0c04c4bc;
P_0c04c4bc: /* original 000b, guest PC 0x0c04c4bc */
if(!s->budget--) { s->failed_pc=0x0c04c4bcu; return 0; }
target=r[16];
write(ram,r[4]+4,r[1],4);
s->pc=target; return ram->oob==0;
P_0c04c4be: /* original 1411, guest PC 0x0c04c4be */
if(!s->budget--) { s->failed_pc=0x0c04c4beu; return 0; }
write(ram,r[4]+4,r[1],4);
if(!vf3_matrix_family(0x0c04c4c0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04c4c0u; return 0; } return 1;
P_0c04c4f0: /* original 2fe6, guest PC 0x0c04c4f0 */
if(!s->budget--) { s->failed_pc=0x0c04c4f0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c4f2;
P_0c04c4f2: /* original e70d, guest PC 0x0c04c4f2 */
if(!s->budget--) { s->failed_pc=0x0c04c4f2u; return 0; }
r[7]=0x0000000du;
goto P_0c04c4f4;
P_0c04c4f4: /* original 2fd6, guest PC 0x0c04c4f4 */
if(!s->budget--) { s->failed_pc=0x0c04c4f4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c4f6;
P_0c04c4f6: /* original 6d43, guest PC 0x0c04c4f6 */
if(!s->budget--) { s->failed_pc=0x0c04c4f6u; return 0; }
r[13]=r[4];
goto P_0c04c4f8;
P_0c04c4f8: /* original 4d08, guest PC 0x0c04c4f8 */
if(!s->budget--) { s->failed_pc=0x0c04c4f8u; return 0; }
r[13]<<=2;
goto P_0c04c4fa;
P_0c04c4fa: /* original 2fc6, guest PC 0x0c04c4fa */
if(!s->budget--) { s->failed_pc=0x0c04c4fau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c4fc;
P_0c04c4fc: /* original 4d08, guest PC 0x0c04c4fc */
if(!s->budget--) { s->failed_pc=0x0c04c4fcu; return 0; }
r[13]<<=2;
goto P_0c04c4fe;
P_0c04c4fe: /* original 2fb6, guest PC 0x0c04c4fe */
if(!s->budget--) { s->failed_pc=0x0c04c4feu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c500;
P_0c04c500: /* original d325, guest PC 0x0c04c500 */
if(!s->budget--) { s->failed_pc=0x0c04c500u; return 0; }
r[3]=read(ram,0x0c04c598u,4);
goto P_0c04c502;
P_0c04c502: /* original 4d08, guest PC 0x0c04c502 */
if(!s->budget--) { s->failed_pc=0x0c04c502u; return 0; }
r[13]<<=2;
goto P_0c04c504;
P_0c04c504: /* original 4d00, guest PC 0x0c04c504 */
if(!s->budget--) { s->failed_pc=0x0c04c504u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c04c506;
P_0c04c506: /* original 3d3c, guest PC 0x0c04c506 */
if(!s->budget--) { s->failed_pc=0x0c04c506u; return 0; }
r[13]+=r[3];
goto P_0c04c508;
P_0c04c508: /* original e400, guest PC 0x0c04c508 */
if(!s->budget--) { s->failed_pc=0x0c04c508u; return 0; }
r[4]=0x00000000u;
goto P_0c04c50a;
P_0c04c50a: /* original 6ed3, guest PC 0x0c04c50a */
if(!s->budget--) { s->failed_pc=0x0c04c50au; return 0; }
r[14]=r[13];
goto P_0c04c50c;
P_0c04c50c: /* original 7e2c, guest PC 0x0c04c50c */
if(!s->budget--) { s->failed_pc=0x0c04c50cu; return 0; }
r[14]+=0x0000002cu;
goto P_0c04c50e;
P_0c04c50e: /* original 6c43, guest PC 0x0c04c50e */
if(!s->budget--) { s->failed_pc=0x0c04c50eu; return 0; }
r[12]=r[4];
goto P_0c04c510;
P_0c04c510: /* original 7ffc, guest PC 0x0c04c510 */
if(!s->budget--) { s->failed_pc=0x0c04c510u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04c512;
P_0c04c512: /* original 7c01, guest PC 0x0c04c512 */
if(!s->budget--) { s->failed_pc=0x0c04c512u; return 0; }
r[12]+=0x00000001u;
goto P_0c04c514;
P_0c04c514: /* original 2e40, guest PC 0x0c04c514 */
if(!s->budget--) { s->failed_pc=0x0c04c514u; return 0; }
write(ram,r[14],r[4],1);
goto P_0c04c516;
P_0c04c516: /* original 3c73, guest PC 0x0c04c516 */
if(!s->budget--) { s->failed_pc=0x0c04c516u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[7])!=0);
goto P_0c04c518;
P_0c04c518: /* original 8ffb, guest PC 0x0c04c518 */
if(!s->budget--) { s->failed_pc=0x0c04c518u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000001u;
if(!cond) { goto P_0c04c512; }
goto P_0c04c51c;
P_0c04c51a: /* original 7e01, guest PC 0x0c04c51a */
if(!s->budget--) { s->failed_pc=0x0c04c51au; return 0; }
r[14]+=0x00000001u;
goto P_0c04c51c;
P_0c04c51c: /* original 6ed3, guest PC 0x0c04c51c */
if(!s->budget--) { s->failed_pc=0x0c04c51cu; return 0; }
r[14]=r[13];
goto P_0c04c51e;
P_0c04c51e: /* original 7e3c, guest PC 0x0c04c51e */
if(!s->budget--) { s->failed_pc=0x0c04c51eu; return 0; }
r[14]+=0x0000003cu;
goto P_0c04c520;
P_0c04c520: /* original 6c43, guest PC 0x0c04c520 */
if(!s->budget--) { s->failed_pc=0x0c04c520u; return 0; }
r[12]=r[4];
goto P_0c04c522;
P_0c04c522: /* original 7c01, guest PC 0x0c04c522 */
if(!s->budget--) { s->failed_pc=0x0c04c522u; return 0; }
r[12]+=0x00000001u;
goto P_0c04c524;
P_0c04c524: /* original 2e40, guest PC 0x0c04c524 */
if(!s->budget--) { s->failed_pc=0x0c04c524u; return 0; }
write(ram,r[14],r[4],1);
goto P_0c04c526;
P_0c04c526: /* original 3c73, guest PC 0x0c04c526 */
if(!s->budget--) { s->failed_pc=0x0c04c526u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[7])!=0);
goto P_0c04c528;
P_0c04c528: /* original 8ffb, guest PC 0x0c04c528 */
if(!s->budget--) { s->failed_pc=0x0c04c528u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000001u;
if(!cond) { goto P_0c04c522; }
goto P_0c04c52c;
P_0c04c52a: /* original 7e01, guest PC 0x0c04c52a */
if(!s->budget--) { s->failed_pc=0x0c04c52au; return 0; }
r[14]+=0x00000001u;
goto P_0c04c52c;
P_0c04c52c: /* original eb00, guest PC 0x0c04c52c */
if(!s->budget--) { s->failed_pc=0x0c04c52cu; return 0; }
r[11]=0x00000000u;
goto P_0c04c52e;
P_0c04c52e: /* original 67d3, guest PC 0x0c04c52e */
if(!s->budget--) { s->failed_pc=0x0c04c52eu; return 0; }
r[7]=r[13];
goto P_0c04c530;
P_0c04c530: /* original 3b5c, guest PC 0x0c04c530 */
if(!s->budget--) { s->failed_pc=0x0c04c530u; return 0; }
r[11]+=r[5];
goto P_0c04c532;
P_0c04c532: /* original 6c43, guest PC 0x0c04c532 */
if(!s->budget--) { s->failed_pc=0x0c04c532u; return 0; }
r[12]=r[4];
goto P_0c04c534;
P_0c04c534: /* original e50c, guest PC 0x0c04c534 */
if(!s->budget--) { s->failed_pc=0x0c04c534u; return 0; }
r[5]=0x0000000cu;
goto P_0c04c536;
P_0c04c536: /* original 6eb3, guest PC 0x0c04c536 */
if(!s->budget--) { s->failed_pc=0x0c04c536u; return 0; }
r[14]=r[11];
goto P_0c04c538;
P_0c04c538: /* original 772c, guest PC 0x0c04c538 */
if(!s->budget--) { s->failed_pc=0x0c04c538u; return 0; }
r[7]+=0x0000002cu;
goto P_0c04c53a;
P_0c04c53a: /* original 2fb2, guest PC 0x0c04c53a */
if(!s->budget--) { s->failed_pc=0x0c04c53au; return 0; }
write(ram,r[15],r[11],4);
goto P_0c04c53c;
P_0c04c53c: /* original 63e0, guest PC 0x0c04c53c */
if(!s->budget--) { s->failed_pc=0x0c04c53cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[3]=tmp;
goto P_0c04c53e;
P_0c04c53e: /* original 2338, guest PC 0x0c04c53e */
if(!s->budget--) { s->failed_pc=0x0c04c53eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04c540;
P_0c04c540: /* original 8906, guest PC 0x0c04c540 */
if(!s->budget--) { s->failed_pc=0x0c04c540u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c550; }
goto P_0c04c542;
P_0c04c542: /* original 63b4, guest PC 0x0c04c542 */
if(!s->budget--) { s->failed_pc=0x0c04c542u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[11],1);
r[11]+=1;
r[3]=tmp;
goto P_0c04c544;
P_0c04c544: /* original 7c01, guest PC 0x0c04c544 */
if(!s->budget--) { s->failed_pc=0x0c04c544u; return 0; }
r[12]+=0x00000001u;
goto P_0c04c546;
P_0c04c546: /* original 3c53, guest PC 0x0c04c546 */
if(!s->budget--) { s->failed_pc=0x0c04c546u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[5])!=0);
goto P_0c04c548;
P_0c04c548: /* original 2730, guest PC 0x0c04c548 */
if(!s->budget--) { s->failed_pc=0x0c04c548u; return 0; }
write(ram,r[7],r[3],1);
goto P_0c04c54a;
P_0c04c54a: /* original 7701, guest PC 0x0c04c54a */
if(!s->budget--) { s->failed_pc=0x0c04c54au; return 0; }
r[7]+=0x00000001u;
goto P_0c04c54c;
P_0c04c54c: /* original 8ff6, guest PC 0x0c04c54c */
if(!s->budget--) { s->failed_pc=0x0c04c54cu; return 0; }
cond=r[17]&1u;
r[14]+=0x00000001u;
if(!cond) { goto P_0c04c53c; }
goto P_0c04c550;
P_0c04c54e: /* original 7e01, guest PC 0x0c04c54e */
if(!s->budget--) { s->failed_pc=0x0c04c54eu; return 0; }
r[14]+=0x00000001u;
goto P_0c04c550;
P_0c04c550: /* original 6743, guest PC 0x0c04c550 */
if(!s->budget--) { s->failed_pc=0x0c04c550u; return 0; }
r[7]=r[4];
goto P_0c04c552;
P_0c04c552: /* original e400, guest PC 0x0c04c552 */
if(!s->budget--) { s->failed_pc=0x0c04c552u; return 0; }
r[4]=0x00000000u;
goto P_0c04c554;
P_0c04c554: /* original 346c, guest PC 0x0c04c554 */
if(!s->budget--) { s->failed_pc=0x0c04c554u; return 0; }
r[4]+=r[6];
goto P_0c04c556;
P_0c04c556: /* original 66d3, guest PC 0x0c04c556 */
if(!s->budget--) { s->failed_pc=0x0c04c556u; return 0; }
r[6]=r[13];
goto P_0c04c558;
P_0c04c558: /* original 763c, guest PC 0x0c04c558 */
if(!s->budget--) { s->failed_pc=0x0c04c558u; return 0; }
r[6]+=0x0000003cu;
goto P_0c04c55a;
P_0c04c55a: /* original 6e43, guest PC 0x0c04c55a */
if(!s->budget--) { s->failed_pc=0x0c04c55au; return 0; }
r[14]=r[4];
goto P_0c04c55c;
P_0c04c55c: /* original 6340, guest PC 0x0c04c55c */
if(!s->budget--) { s->failed_pc=0x0c04c55cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c04c55e;
P_0c04c55e: /* original 2338, guest PC 0x0c04c55e */
if(!s->budget--) { s->failed_pc=0x0c04c55eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04c560;
P_0c04c560: /* original 8906, guest PC 0x0c04c560 */
if(!s->budget--) { s->failed_pc=0x0c04c560u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c570; }
goto P_0c04c562;
P_0c04c562: /* original 63e4, guest PC 0x0c04c562 */
if(!s->budget--) { s->failed_pc=0x0c04c562u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[14]+=1;
r[3]=tmp;
goto P_0c04c564;
P_0c04c564: /* original 7701, guest PC 0x0c04c564 */
if(!s->budget--) { s->failed_pc=0x0c04c564u; return 0; }
r[7]+=0x00000001u;
goto P_0c04c566;
P_0c04c566: /* original 3753, guest PC 0x0c04c566 */
if(!s->budget--) { s->failed_pc=0x0c04c566u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[5])!=0);
goto P_0c04c568;
P_0c04c568: /* original 2630, guest PC 0x0c04c568 */
if(!s->budget--) { s->failed_pc=0x0c04c568u; return 0; }
write(ram,r[6],r[3],1);
goto P_0c04c56a;
P_0c04c56a: /* original 7601, guest PC 0x0c04c56a */
if(!s->budget--) { s->failed_pc=0x0c04c56au; return 0; }
r[6]+=0x00000001u;
goto P_0c04c56c;
P_0c04c56c: /* original 8ff6, guest PC 0x0c04c56c */
if(!s->budget--) { s->failed_pc=0x0c04c56cu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c04c55c; }
goto P_0c04c570;
P_0c04c56e: /* original 7401, guest PC 0x0c04c56e */
if(!s->budget--) { s->failed_pc=0x0c04c56eu; return 0; }
r[4]+=0x00000001u;
goto P_0c04c570;
P_0c04c570: /* original 7f04, guest PC 0x0c04c570 */
if(!s->budget--) { s->failed_pc=0x0c04c570u; return 0; }
r[15]+=0x00000004u;
goto P_0c04c572;
P_0c04c572: /* original 6bf6, guest PC 0x0c04c572 */
if(!s->budget--) { s->failed_pc=0x0c04c572u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04c574;
P_0c04c574: /* original 6cf6, guest PC 0x0c04c574 */
if(!s->budget--) { s->failed_pc=0x0c04c574u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04c576;
P_0c04c576: /* original 6df6, guest PC 0x0c04c576 */
if(!s->budget--) { s->failed_pc=0x0c04c576u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04c578;
P_0c04c578: /* original 000b, guest PC 0x0c04c578 */
if(!s->budget--) { s->failed_pc=0x0c04c578u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04c57a: /* original 6ef6, guest PC 0x0c04c57a */
if(!s->budget--) { s->failed_pc=0x0c04c57au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04c57cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04c57cu; return 0; } return 1;
P_0c04c5a0: /* original 2fe6, guest PC 0x0c04c5a0 */
if(!s->budget--) { s->failed_pc=0x0c04c5a0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c5a2;
P_0c04c5a2: /* original e503, guest PC 0x0c04c5a2 */
if(!s->budget--) { s->failed_pc=0x0c04c5a2u; return 0; }
r[5]=0x00000003u;
goto P_0c04c5a4;
P_0c04c5a4: /* original 4f22, guest PC 0x0c04c5a4 */
if(!s->budget--) { s->failed_pc=0x0c04c5a4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04c5a6;
P_0c04c5a6: /* original 60f3, guest PC 0x0c04c5a6 */
if(!s->budget--) { s->failed_pc=0x0c04c5a6u; return 0; }
r[0]=r[15];
goto P_0c04c5a8;
P_0c04c5a8: /* original 7008, guest PC 0x0c04c5a8 */
if(!s->budget--) { s->failed_pc=0x0c04c5a8u; return 0; }
r[0]+=0x00000008u;
goto P_0c04c5aa;
P_0c04c5aa: /* original 7004, guest PC 0x0c04c5aa */
if(!s->budget--) { s->failed_pc=0x0c04c5aau; return 0; }
r[0]+=0x00000004u;
goto P_0c04c5ac;
P_0c04c5ac: /* original 2508, guest PC 0x0c04c5ac */
if(!s->budget--) { s->failed_pc=0x0c04c5acu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[0])==0)!=0);
goto P_0c04c5ae;
P_0c04c5ae: /* original 8903, guest PC 0x0c04c5ae */
if(!s->budget--) { s->failed_pc=0x0c04c5aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c5b8; }
goto P_0c04c5b0;
P_0c04c5b0: /* original 65f3, guest PC 0x0c04c5b0 */
if(!s->budget--) { s->failed_pc=0x0c04c5b0u; return 0; }
r[5]=r[15];
goto P_0c04c5b2;
P_0c04c5b2: /* original 7508, guest PC 0x0c04c5b2 */
if(!s->budget--) { s->failed_pc=0x0c04c5b2u; return 0; }
r[5]+=0x00000008u;
goto P_0c04c5b4;
P_0c04c5b4: /* original a003, guest PC 0x0c04c5b4 */
if(!s->budget--) { s->failed_pc=0x0c04c5b4u; return 0; }
r[5]+=0x00000008u;
goto P_0c04c5be;
P_0c04c5b6: /* original 7508, guest PC 0x0c04c5b6 */
if(!s->budget--) { s->failed_pc=0x0c04c5b6u; return 0; }
r[5]+=0x00000008u;
goto P_0c04c5b8;
P_0c04c5b8: /* original 65f3, guest PC 0x0c04c5b8 */
if(!s->budget--) { s->failed_pc=0x0c04c5b8u; return 0; }
r[5]=r[15];
goto P_0c04c5ba;
P_0c04c5ba: /* original 7508, guest PC 0x0c04c5ba */
if(!s->budget--) { s->failed_pc=0x0c04c5bau; return 0; }
r[5]+=0x00000008u;
goto P_0c04c5bc;
P_0c04c5bc: /* original 7504, guest PC 0x0c04c5bc */
if(!s->budget--) { s->failed_pc=0x0c04c5bcu; return 0; }
r[5]+=0x00000004u;
goto P_0c04c5be;
P_0c04c5be: /* original d335, guest PC 0x0c04c5be */
if(!s->budget--) { s->failed_pc=0x0c04c5beu; return 0; }
r[3]=read(ram,0x0c04c694u,4);
goto P_0c04c5c0;
P_0c04c5c0: /* original 6653, guest PC 0x0c04c5c0 */
if(!s->budget--) { s->failed_pc=0x0c04c5c0u; return 0; }
r[6]=r[5];
goto P_0c04c5c2;
P_0c04c5c2: /* original d433, guest PC 0x0c04c5c2 */
if(!s->budget--) { s->failed_pc=0x0c04c5c2u; return 0; }
r[4]=read(ram,0x0c04c690u,4);
goto P_0c04c5c4;
P_0c04c5c4: /* original 430b, guest PC 0x0c04c5c4 */
if(!s->budget--) { s->failed_pc=0x0c04c5c4u; return 0; }
target=r[3];
r[16]=code_base|0x0c04c5c8u;
r[5]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c5c8u) { target=s->pc; goto dispatch; }
goto P_0c04c5c8;
P_0c04c5c6: /* original 55f2, guest PC 0x0c04c5c6 */
if(!s->budget--) { s->failed_pc=0x0c04c5c6u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c04c5c8;
P_0c04c5c8: /* original d233, guest PC 0x0c04c5c8 */
if(!s->budget--) { s->failed_pc=0x0c04c5c8u; return 0; }
r[2]=read(ram,0x0c04c698u,4);
goto P_0c04c5ca;
P_0c04c5ca: /* original 6e22, guest PC 0x0c04c5ca */
if(!s->budget--) { s->failed_pc=0x0c04c5cau; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c04c5cc;
P_0c04c5cc: /* original 2ee8, guest PC 0x0c04c5cc */
if(!s->budget--) { s->failed_pc=0x0c04c5ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c04c5ce;
P_0c04c5ce: /* original 8902, guest PC 0x0c04c5ce */
if(!s->budget--) { s->failed_pc=0x0c04c5ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c5d6; }
goto P_0c04c5d0;
P_0c04c5d0: /* original d42f, guest PC 0x0c04c5d0 */
if(!s->budget--) { s->failed_pc=0x0c04c5d0u; return 0; }
r[4]=read(ram,0x0c04c690u,4);
goto P_0c04c5d2;
P_0c04c5d2: /* original 4e0b, guest PC 0x0c04c5d2 */
if(!s->budget--) { s->failed_pc=0x0c04c5d2u; return 0; }
target=r[14];
r[16]=code_base|0x0c04c5d6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c5d6u) { target=s->pc; goto dispatch; }
goto P_0c04c5d6;
P_0c04c5d4: /* original 0009, guest PC 0x0c04c5d4 */
if(!s->budget--) { s->failed_pc=0x0c04c5d4u; return 0; }
goto P_0c04c5d6;
P_0c04c5d6: /* original 4f26, guest PC 0x0c04c5d6 */
if(!s->budget--) { s->failed_pc=0x0c04c5d6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04c5d8;
P_0c04c5d8: /* original 000b, guest PC 0x0c04c5d8 */
if(!s->budget--) { s->failed_pc=0x0c04c5d8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04c5da: /* original 6ef6, guest PC 0x0c04c5da */
if(!s->budget--) { s->failed_pc=0x0c04c5dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04c5dc;
P_0c04c5dc: /* original d52f, guest PC 0x0c04c5dc */
if(!s->budget--) { s->failed_pc=0x0c04c5dcu; return 0; }
r[5]=read(ram,0x0c04c69cu,4);
goto P_0c04c5de;
P_0c04c5de: /* original e301, guest PC 0x0c04c5de */
if(!s->budget--) { s->failed_pc=0x0c04c5deu; return 0; }
r[3]=0x00000001u;
goto P_0c04c5e0;
P_0c04c5e0: /* original 2439, guest PC 0x0c04c5e0 */
if(!s->budget--) { s->failed_pc=0x0c04c5e0u; return 0; }
r[4]&=r[3];
goto P_0c04c5e2;
P_0c04c5e2: /* original 6252, guest PC 0x0c04c5e2 */
if(!s->budget--) { s->failed_pc=0x0c04c5e2u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c04c5e4;
P_0c04c5e4: /* original 6043, guest PC 0x0c04c5e4 */
if(!s->budget--) { s->failed_pc=0x0c04c5e4u; return 0; }
r[0]=r[4];
goto P_0c04c5e6;
P_0c04c5e6: /* original 8801, guest PC 0x0c04c5e6 */
if(!s->budget--) { s->failed_pc=0x0c04c5e6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c04c5e8;
P_0c04c5e8: /* original 2242, guest PC 0x0c04c5e8 */
if(!s->budget--) { s->failed_pc=0x0c04c5e8u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c04c5ea;
P_0c04c5ea: /* original 8f07, guest PC 0x0c04c5ea */
if(!s->budget--) { s->failed_pc=0x0c04c5eau; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[5],4);
r[6]=tmp;
if(!cond) { goto P_0c04c5fc; }
goto P_0c04c5ee;
P_0c04c5ec: /* original 6652, guest PC 0x0c04c5ec */
if(!s->budget--) { s->failed_pc=0x0c04c5ecu; return 0; }
tmp=read(ram,r[5],4);
r[6]=tmp;
goto P_0c04c5ee;
P_0c04c5ee: /* original d22c, guest PC 0x0c04c5ee */
if(!s->budget--) { s->failed_pc=0x0c04c5eeu; return 0; }
r[2]=read(ram,0x0c04c6a0u,4);
goto P_0c04c5f0;
P_0c04c5f0: /* original 1623, guest PC 0x0c04c5f0 */
if(!s->budget--) { s->failed_pc=0x0c04c5f0u; return 0; }
write(ram,r[6]+12,r[2],4);
goto P_0c04c5f2;
P_0c04c5f2: /* original d22c, guest PC 0x0c04c5f2 */
if(!s->budget--) { s->failed_pc=0x0c04c5f2u; return 0; }
r[2]=read(ram,0x0c04c6a4u,4);
goto P_0c04c5f4;
P_0c04c5f4: /* original 6152, guest PC 0x0c04c5f4 */
if(!s->budget--) { s->failed_pc=0x0c04c5f4u; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c04c5f6;
P_0c04c5f6: /* original 1124, guest PC 0x0c04c5f6 */
if(!s->budget--) { s->failed_pc=0x0c04c5f6u; return 0; }
write(ram,r[1]+16,r[2],4);
goto P_0c04c5f8;
P_0c04c5f8: /* original a005, guest PC 0x0c04c5f8 */
if(!s->budget--) { s->failed_pc=0x0c04c5f8u; return 0; }
goto P_0c04c606;
P_0c04c5fa: /* original 0009, guest PC 0x0c04c5fa */
if(!s->budget--) { s->failed_pc=0x0c04c5fau; return 0; }
goto P_0c04c5fc;
P_0c04c5fc: /* original d02a, guest PC 0x0c04c5fc */
if(!s->budget--) { s->failed_pc=0x0c04c5fcu; return 0; }
r[0]=read(ram,0x0c04c6a8u,4);
goto P_0c04c5fe;
P_0c04c5fe: /* original 1603, guest PC 0x0c04c5fe */
if(!s->budget--) { s->failed_pc=0x0c04c5feu; return 0; }
write(ram,r[6]+12,r[0],4);
goto P_0c04c600;
P_0c04c600: /* original 6252, guest PC 0x0c04c600 */
if(!s->budget--) { s->failed_pc=0x0c04c600u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c04c602;
P_0c04c602: /* original d12a, guest PC 0x0c04c602 */
if(!s->budget--) { s->failed_pc=0x0c04c602u; return 0; }
r[1]=read(ram,0x0c04c6acu,4);
goto P_0c04c604;
P_0c04c604: /* original 1214, guest PC 0x0c04c604 */
if(!s->budget--) { s->failed_pc=0x0c04c604u; return 0; }
write(ram,r[2]+16,r[1],4);
goto P_0c04c606;
P_0c04c606: /* original 000b, guest PC 0x0c04c606 */
if(!s->budget--) { s->failed_pc=0x0c04c606u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c04c608: /* original 0009, guest PC 0x0c04c608 */
if(!s->budget--) { s->failed_pc=0x0c04c608u; return 0; }
goto P_0c04c60a;
P_0c04c60a: /* original 2fe6, guest PC 0x0c04c60a */
if(!s->budget--) { s->failed_pc=0x0c04c60au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c60c;
P_0c04c60c: /* original 2fd6, guest PC 0x0c04c60c */
if(!s->budget--) { s->failed_pc=0x0c04c60cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c60e;
P_0c04c60e: /* original 2fc6, guest PC 0x0c04c60e */
if(!s->budget--) { s->failed_pc=0x0c04c60eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c610;
P_0c04c610: /* original 6c53, guest PC 0x0c04c610 */
if(!s->budget--) { s->failed_pc=0x0c04c610u; return 0; }
r[12]=r[5];
goto P_0c04c612;
P_0c04c612: /* original 2fb6, guest PC 0x0c04c612 */
if(!s->budget--) { s->failed_pc=0x0c04c612u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c614;
P_0c04c614: /* original 6b63, guest PC 0x0c04c614 */
if(!s->budget--) { s->failed_pc=0x0c04c614u; return 0; }
r[11]=r[6];
goto P_0c04c616;
P_0c04c616: /* original 2fa6, guest PC 0x0c04c616 */
if(!s->budget--) { s->failed_pc=0x0c04c616u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c618;
P_0c04c618: /* original 2f96, guest PC 0x0c04c618 */
if(!s->budget--) { s->failed_pc=0x0c04c618u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c61a;
P_0c04c61a: /* original 2f86, guest PC 0x0c04c61a */
if(!s->budget--) { s->failed_pc=0x0c04c61au; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c61c;
P_0c04c61c: /* original 6843, guest PC 0x0c04c61c */
if(!s->budget--) { s->failed_pc=0x0c04c61cu; return 0; }
r[8]=r[4];
goto P_0c04c61e;
P_0c04c61e: /* original 4f22, guest PC 0x0c04c61e */
if(!s->budget--) { s->failed_pc=0x0c04c61eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04c620;
P_0c04c620: /* original 2f66, guest PC 0x0c04c620 */
if(!s->budget--) { s->failed_pc=0x0c04c620u; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c622;
P_0c04c622: /* original 2fc6, guest PC 0x0c04c622 */
if(!s->budget--) { s->failed_pc=0x0c04c622u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c624;
P_0c04c624: /* original 2f86, guest PC 0x0c04c624 */
if(!s->budget--) { s->failed_pc=0x0c04c624u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c626;
P_0c04c626: /* original d322, guest PC 0x0c04c626 */
if(!s->budget--) { s->failed_pc=0x0c04c626u; return 0; }
r[3]=read(ram,0x0c04c6b0u,4);
goto P_0c04c628;
P_0c04c628: /* original bfba, guest PC 0x0c04c628 */
if(!s->budget--) { s->failed_pc=0x0c04c628u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04c62cu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c62cu) { target=s->pc; goto dispatch; }
goto P_0c04c62c;
P_0c04c62a: /* original 2f36, guest PC 0x0c04c62a */
if(!s->budget--) { s->failed_pc=0x0c04c62au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c62c;
P_0c04c62c: /* original d321, guest PC 0x0c04c62c */
if(!s->budget--) { s->failed_pc=0x0c04c62cu; return 0; }
r[3]=read(ram,0x0c04c6b4u,4);
goto P_0c04c62e;
P_0c04c62e: /* original ed00, guest PC 0x0c04c62e */
if(!s->budget--) { s->failed_pc=0x0c04c62eu; return 0; }
r[13]=0x00000000u;
goto P_0c04c630;
P_0c04c630: /* original d91a, guest PC 0x0c04c630 */
if(!s->budget--) { s->failed_pc=0x0c04c630u; return 0; }
r[9]=read(ram,0x0c04c69cu,4);
goto P_0c04c632;
P_0c04c632: /* original ee08, guest PC 0x0c04c632 */
if(!s->budget--) { s->failed_pc=0x0c04c632u; return 0; }
r[14]=0x00000008u;
goto P_0c04c634;
P_0c04c634: /* original 65d3, guest PC 0x0c04c634 */
if(!s->budget--) { s->failed_pc=0x0c04c634u; return 0; }
r[5]=r[13];
goto P_0c04c636;
P_0c04c636: /* original 7f10, guest PC 0x0c04c636 */
if(!s->budget--) { s->failed_pc=0x0c04c636u; return 0; }
r[15]+=0x00000010u;
goto P_0c04c638;
P_0c04c638: /* original 2932, guest PC 0x0c04c638 */
if(!s->budget--) { s->failed_pc=0x0c04c638u; return 0; }
write(ram,r[9],r[3],4);
goto P_0c04c63a;
P_0c04c63a: /* original d41f, guest PC 0x0c04c63a */
if(!s->budget--) { s->failed_pc=0x0c04c63au; return 0; }
r[4]=read(ram,0x0c04c6b8u,4);
goto P_0c04c63c;
P_0c04c63c: /* original 7501, guest PC 0x0c04c63c */
if(!s->budget--) { s->failed_pc=0x0c04c63cu; return 0; }
r[5]+=0x00000001u;
goto P_0c04c63e;
P_0c04c63e: /* original 24d2, guest PC 0x0c04c63e */
if(!s->budget--) { s->failed_pc=0x0c04c63eu; return 0; }
write(ram,r[4],r[13],4);
goto P_0c04c640;
P_0c04c640: /* original 35e3, guest PC 0x0c04c640 */
if(!s->budget--) { s->failed_pc=0x0c04c640u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[14])!=0);
goto P_0c04c642;
P_0c04c642: /* original 8ffb, guest PC 0x0c04c642 */
if(!s->budget--) { s->failed_pc=0x0c04c642u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c04c63c; }
goto P_0c04c646;
P_0c04c644: /* original 7404, guest PC 0x0c04c644 */
if(!s->budget--) { s->failed_pc=0x0c04c644u; return 0; }
r[4]+=0x00000004u;
goto P_0c04c646;
P_0c04c646: /* original d41b, guest PC 0x0c04c646 */
if(!s->budget--) { s->failed_pc=0x0c04c646u; return 0; }
r[4]=read(ram,0x0c04c6b4u,4);
goto P_0c04c648;
P_0c04c648: /* original e614, guest PC 0x0c04c648 */
if(!s->budget--) { s->failed_pc=0x0c04c648u; return 0; }
r[6]=0x00000014u;
goto P_0c04c64a;
P_0c04c64a: /* original da1c, guest PC 0x0c04c64a */
if(!s->budget--) { s->failed_pc=0x0c04c64au; return 0; }
r[10]=read(ram,0x0c04c6bcu,4);
goto P_0c04c64c;
P_0c04c64c: /* original 4a0b, guest PC 0x0c04c64c */
if(!s->budget--) { s->failed_pc=0x0c04c64cu; return 0; }
target=r[10];
r[16]=code_base|0x0c04c650u;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c650u) { target=s->pc; goto dispatch; }
goto P_0c04c650;
P_0c04c64e: /* original e500, guest PC 0x0c04c64e */
if(!s->budget--) { s->failed_pc=0x0c04c64eu; return 0; }
r[5]=0x00000000u;
goto P_0c04c650;
P_0c04c650: /* original d41b, guest PC 0x0c04c650 */
if(!s->budget--) { s->failed_pc=0x0c04c650u; return 0; }
r[4]=read(ram,0x0c04c6c0u,4);
goto P_0c04c652;
P_0c04c652: /* original 961b, guest PC 0x0c04c652 */
if(!s->budget--) { s->failed_pc=0x0c04c652u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04c68cu,2);
goto P_0c04c654;
P_0c04c654: /* original 4a0b, guest PC 0x0c04c654 */
if(!s->budget--) { s->failed_pc=0x0c04c654u; return 0; }
target=r[10];
r[16]=code_base|0x0c04c658u;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c658u) { target=s->pc; goto dispatch; }
goto P_0c04c658;
P_0c04c656: /* original e500, guest PC 0x0c04c656 */
if(!s->budget--) { s->failed_pc=0x0c04c656u; return 0; }
r[5]=0x00000000u;
goto P_0c04c658;
P_0c04c658: /* original bfc0, guest PC 0x0c04c658 */
if(!s->budget--) { s->failed_pc=0x0c04c658u; return 0; }
target=code_base|0x0c04c5dcu; r[16]=code_base|0x0c04c65cu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c65cu) { target=s->pc; goto dispatch; }
goto P_0c04c65c;
P_0c04c65a: /* original e400, guest PC 0x0c04c65a */
if(!s->budget--) { s->failed_pc=0x0c04c65au; return 0; }
r[4]=0x00000000u;
goto P_0c04c65c;
P_0c04c65c: /* original d419, guest PC 0x0c04c65c */
if(!s->budget--) { s->failed_pc=0x0c04c65cu; return 0; }
r[4]=read(ram,0x0c04c6c4u,4);
goto P_0c04c65e;
P_0c04c65e: /* original e200, guest PC 0x0c04c65e */
if(!s->budget--) { s->failed_pc=0x0c04c65eu; return 0; }
r[2]=0x00000000u;
goto P_0c04c660;
P_0c04c660: /* original e601, guest PC 0x0c04c660 */
if(!s->budget--) { s->failed_pc=0x0c04c660u; return 0; }
r[6]=0x00000001u;
goto P_0c04c662;
P_0c04c662: /* original 65d3, guest PC 0x0c04c662 */
if(!s->budget--) { s->failed_pc=0x0c04c662u; return 0; }
r[5]=r[13];
goto P_0c04c664;
P_0c04c664: /* original 2422, guest PC 0x0c04c664 */
if(!s->budget--) { s->failed_pc=0x0c04c664u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c04c666;
P_0c04c666: /* original 63c3, guest PC 0x0c04c666 */
if(!s->budget--) { s->failed_pc=0x0c04c666u; return 0; }
r[3]=r[12];
goto P_0c04c668;
P_0c04c668: /* original 2368, guest PC 0x0c04c668 */
if(!s->budget--) { s->failed_pc=0x0c04c668u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c04c66a;
P_0c04c66a: /* original 8d03, guest PC 0x0c04c66a */
if(!s->budget--) { s->failed_pc=0x0c04c66au; return 0; }
cond=r[17]&1u;
r[5]+=0x00000001u;
if(cond) { goto P_0c04c674; }
goto P_0c04c66e;
P_0c04c66c: /* original 7501, guest PC 0x0c04c66c */
if(!s->budget--) { s->failed_pc=0x0c04c66cu; return 0; }
r[5]+=0x00000001u;
goto P_0c04c66e;
P_0c04c66e: /* original 6142, guest PC 0x0c04c66e */
if(!s->budget--) { s->failed_pc=0x0c04c66eu; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c04c670;
P_0c04c670: /* original 7101, guest PC 0x0c04c670 */
if(!s->budget--) { s->failed_pc=0x0c04c670u; return 0; }
r[1]+=0x00000001u;
goto P_0c04c672;
P_0c04c672: /* original 2412, guest PC 0x0c04c672 */
if(!s->budget--) { s->failed_pc=0x0c04c672u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c04c674;
P_0c04c674: /* original 4600, guest PC 0x0c04c674 */
if(!s->budget--) { s->failed_pc=0x0c04c674u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c04c676;
P_0c04c676: /* original 35e3, guest PC 0x0c04c676 */
if(!s->budget--) { s->failed_pc=0x0c04c676u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[14])!=0);
goto P_0c04c678;
P_0c04c678: /* original 8bf5, guest PC 0x0c04c678 */
if(!s->budget--) { s->failed_pc=0x0c04c678u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04c666; }
goto P_0c04c67a;
P_0c04c67a: /* original 2bb8, guest PC 0x0c04c67a */
if(!s->budget--) { s->failed_pc=0x0c04c67au; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c04c67c;
P_0c04c67c: /* original 8924, guest PC 0x0c04c67c */
if(!s->budget--) { s->failed_pc=0x0c04c67cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c6c8; }
goto P_0c04c67e;
P_0c04c67e: /* original 65c3, guest PC 0x0c04c67e */
if(!s->budget--) { s->failed_pc=0x0c04c67eu; return 0; }
r[5]=r[12];
goto P_0c04c680;
P_0c04c680: /* original 66b3, guest PC 0x0c04c680 */
if(!s->budget--) { s->failed_pc=0x0c04c680u; return 0; }
r[6]=r[11];
goto P_0c04c682;
P_0c04c682: /* original b065, guest PC 0x0c04c682 */
if(!s->budget--) { s->failed_pc=0x0c04c682u; return 0; }
target=code_base|0x0c04c750u; r[16]=code_base|0x0c04c686u;
r[4]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c686u) { target=s->pc; goto dispatch; }
goto P_0c04c686;
P_0c04c684: /* original 6483, guest PC 0x0c04c684 */
if(!s->budget--) { s->failed_pc=0x0c04c684u; return 0; }
r[4]=r[8];
goto P_0c04c686;
P_0c04c686: /* original 6292, guest PC 0x0c04c686 */
if(!s->budget--) { s->failed_pc=0x0c04c686u; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c04c688;
P_0c04c688: /* original a025, guest PC 0x0c04c688 */
if(!s->budget--) { s->failed_pc=0x0c04c688u; return 0; }
write(ram,r[2]+8,r[13],4);
goto P_0c04c6d6;
P_0c04c68a: /* original 12d2, guest PC 0x0c04c68a */
if(!s->budget--) { s->failed_pc=0x0c04c68au; return 0; }
write(ram,r[2]+8,r[13],4);
if(!vf3_matrix_family(0x0c04c68cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04c68cu; return 0; } return 1;
P_0c04c6c8: /* original 65c3, guest PC 0x0c04c6c8 */
if(!s->budget--) { s->failed_pc=0x0c04c6c8u; return 0; }
r[5]=r[12];
goto P_0c04c6ca;
P_0c04c6ca: /* original 66b3, guest PC 0x0c04c6ca */
if(!s->budget--) { s->failed_pc=0x0c04c6cau; return 0; }
r[6]=r[11];
goto P_0c04c6cc;
P_0c04c6cc: /* original b022, guest PC 0x0c04c6cc */
if(!s->budget--) { s->failed_pc=0x0c04c6ccu; return 0; }
target=code_base|0x0c04c714u; r[16]=code_base|0x0c04c6d0u;
r[4]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c6d0u) { target=s->pc; goto dispatch; }
goto P_0c04c6d0;
P_0c04c6ce: /* original 6483, guest PC 0x0c04c6ce */
if(!s->budget--) { s->failed_pc=0x0c04c6ceu; return 0; }
r[4]=r[8];
goto P_0c04c6d0;
P_0c04c6d0: /* original 6392, guest PC 0x0c04c6d0 */
if(!s->budget--) { s->failed_pc=0x0c04c6d0u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c04c6d2;
P_0c04c6d2: /* original e201, guest PC 0x0c04c6d2 */
if(!s->budget--) { s->failed_pc=0x0c04c6d2u; return 0; }
r[2]=0x00000001u;
goto P_0c04c6d4;
P_0c04c6d4: /* original 1322, guest PC 0x0c04c6d4 */
if(!s->budget--) { s->failed_pc=0x0c04c6d4u; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c04c6d6;
P_0c04c6d6: /* original d338, guest PC 0x0c04c6d6 */
if(!s->budget--) { s->failed_pc=0x0c04c6d6u; return 0; }
r[3]=read(ram,0x0c04c7b8u,4);
goto P_0c04c6d8;
P_0c04c6d8: /* original 23e2, guest PC 0x0c04c6d8 */
if(!s->budget--) { s->failed_pc=0x0c04c6d8u; return 0; }
write(ram,r[3],r[14],4);
goto P_0c04c6da;
P_0c04c6da: /* original d238, guest PC 0x0c04c6da */
if(!s->budget--) { s->failed_pc=0x0c04c6dau; return 0; }
r[2]=read(ram,0x0c04c7bcu,4);
goto P_0c04c6dc;
P_0c04c6dc: /* original 22d2, guest PC 0x0c04c6dc */
if(!s->budget--) { s->failed_pc=0x0c04c6dcu; return 0; }
write(ram,r[2],r[13],4);
goto P_0c04c6de;
P_0c04c6de: /* original d138, guest PC 0x0c04c6de */
if(!s->budget--) { s->failed_pc=0x0c04c6deu; return 0; }
r[1]=read(ram,0x0c04c7c0u,4);
goto P_0c04c6e0;
P_0c04c6e0: /* original 410b, guest PC 0x0c04c6e0 */
if(!s->budget--) { s->failed_pc=0x0c04c6e0u; return 0; }
target=r[1];
r[16]=code_base|0x0c04c6e4u;
r[4]=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c6e4u) { target=s->pc; goto dispatch; }
goto P_0c04c6e4;
P_0c04c6e2: /* original e40a, guest PC 0x0c04c6e2 */
if(!s->budget--) { s->failed_pc=0x0c04c6e2u; return 0; }
r[4]=0x0000000au;
goto P_0c04c6e4;
P_0c04c6e4: /* original d234, guest PC 0x0c04c6e4 */
if(!s->budget--) { s->failed_pc=0x0c04c6e4u; return 0; }
r[2]=read(ram,0x0c04c7b8u,4);
goto P_0c04c6e6;
P_0c04c6e6: /* original d437, guest PC 0x0c04c6e6 */
if(!s->budget--) { s->failed_pc=0x0c04c6e6u; return 0; }
r[4]=read(ram,0x0c04c7c4u,4);
goto P_0c04c6e8;
P_0c04c6e8: /* original 6622, guest PC 0x0c04c6e8 */
if(!s->budget--) { s->failed_pc=0x0c04c6e8u; return 0; }
tmp=read(ram,r[2],4);
r[6]=tmp;
goto P_0c04c6ea;
P_0c04c6ea: /* original 6363, guest PC 0x0c04c6ea */
if(!s->budget--) { s->failed_pc=0x0c04c6eau; return 0; }
r[3]=r[6];
goto P_0c04c6ec;
P_0c04c6ec: /* original 4608, guest PC 0x0c04c6ec */
if(!s->budget--) { s->failed_pc=0x0c04c6ecu; return 0; }
r[6]<<=2;
goto P_0c04c6ee;
P_0c04c6ee: /* original 4600, guest PC 0x0c04c6ee */
if(!s->budget--) { s->failed_pc=0x0c04c6eeu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c04c6f0;
P_0c04c6f0: /* original 363c, guest PC 0x0c04c6f0 */
if(!s->budget--) { s->failed_pc=0x0c04c6f0u; return 0; }
r[6]+=r[3];
goto P_0c04c6f2;
P_0c04c6f2: /* original 4608, guest PC 0x0c04c6f2 */
if(!s->budget--) { s->failed_pc=0x0c04c6f2u; return 0; }
r[6]<<=2;
goto P_0c04c6f4;
P_0c04c6f4: /* original 4600, guest PC 0x0c04c6f4 */
if(!s->budget--) { s->failed_pc=0x0c04c6f4u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c04c6f6;
P_0c04c6f6: /* original 4a0b, guest PC 0x0c04c6f6 */
if(!s->budget--) { s->failed_pc=0x0c04c6f6u; return 0; }
target=r[10];
r[16]=code_base|0x0c04c6fau;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c6fau) { target=s->pc; goto dispatch; }
goto P_0c04c6fa;
P_0c04c6f8: /* original e500, guest PC 0x0c04c6f8 */
if(!s->budget--) { s->failed_pc=0x0c04c6f8u; return 0; }
r[5]=0x00000000u;
goto P_0c04c6fa;
P_0c04c6fa: /* original d333, guest PC 0x0c04c6fa */
if(!s->budget--) { s->failed_pc=0x0c04c6fau; return 0; }
r[3]=read(ram,0x0c04c7c8u,4);
goto P_0c04c6fc;
P_0c04c6fc: /* original 430b, guest PC 0x0c04c6fc */
if(!s->budget--) { s->failed_pc=0x0c04c6fcu; return 0; }
target=r[3];
r[16]=code_base|0x0c04c700u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c700u) { target=s->pc; goto dispatch; }
goto P_0c04c700;
P_0c04c6fe: /* original 0009, guest PC 0x0c04c6fe */
if(!s->budget--) { s->failed_pc=0x0c04c6feu; return 0; }
goto P_0c04c700;
P_0c04c700: /* original 4f26, guest PC 0x0c04c700 */
if(!s->budget--) { s->failed_pc=0x0c04c700u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04c702;
P_0c04c702: /* original 60d3, guest PC 0x0c04c702 */
if(!s->budget--) { s->failed_pc=0x0c04c702u; return 0; }
r[0]=r[13];
goto P_0c04c704;
P_0c04c704: /* original 68f6, guest PC 0x0c04c704 */
if(!s->budget--) { s->failed_pc=0x0c04c704u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04c706;
P_0c04c706: /* original 69f6, guest PC 0x0c04c706 */
if(!s->budget--) { s->failed_pc=0x0c04c706u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04c708;
P_0c04c708: /* original 6af6, guest PC 0x0c04c708 */
if(!s->budget--) { s->failed_pc=0x0c04c708u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04c70a;
P_0c04c70a: /* original 6bf6, guest PC 0x0c04c70a */
if(!s->budget--) { s->failed_pc=0x0c04c70au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04c70c;
P_0c04c70c: /* original 6cf6, guest PC 0x0c04c70c */
if(!s->budget--) { s->failed_pc=0x0c04c70cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04c70e;
P_0c04c70e: /* original 6df6, guest PC 0x0c04c70e */
if(!s->budget--) { s->failed_pc=0x0c04c70eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04c710;
P_0c04c710: /* original 000b, guest PC 0x0c04c710 */
if(!s->budget--) { s->failed_pc=0x0c04c710u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04c712: /* original 6ef6, guest PC 0x0c04c712 */
if(!s->budget--) { s->failed_pc=0x0c04c712u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04c714u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
