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
int vf3_away_batch5_adapter_13(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04e4e0u: goto P_0c04e4e0;
case 0x0c04e4e2u: goto P_0c04e4e2;
case 0x0c04e4e4u: goto P_0c04e4e4;
case 0x0c04e4e6u: goto P_0c04e4e6;
case 0x0c04e4e8u: goto P_0c04e4e8;
case 0x0c04e4eau: goto P_0c04e4ea;
case 0x0c04e4ecu: goto P_0c04e4ec;
case 0x0c04e4eeu: goto P_0c04e4ee;
case 0x0c04e4f0u: goto P_0c04e4f0;
case 0x0c04e4f2u: goto P_0c04e4f2;
case 0x0c04e4f4u: goto P_0c04e4f4;
case 0x0c04e4f6u: goto P_0c04e4f6;
case 0x0c04e4f8u: goto P_0c04e4f8;
case 0x0c04e4fau: goto P_0c04e4fa;
case 0x0c04e4fcu: goto P_0c04e4fc;
case 0x0c04e4feu: goto P_0c04e4fe;
case 0x0c04e500u: goto P_0c04e500;
case 0x0c04e502u: goto P_0c04e502;
case 0x0c04e504u: goto P_0c04e504;
case 0x0c04e506u: goto P_0c04e506;
case 0x0c04e508u: goto P_0c04e508;
case 0x0c04e50au: goto P_0c04e50a;
case 0x0c04e50cu: goto P_0c04e50c;
case 0x0c04e50eu: goto P_0c04e50e;
case 0x0c04e510u: goto P_0c04e510;
case 0x0c04e512u: goto P_0c04e512;
case 0x0c04e514u: goto P_0c04e514;
case 0x0c04e516u: goto P_0c04e516;
case 0x0c04e518u: goto P_0c04e518;
case 0x0c04e51au: goto P_0c04e51a;
case 0x0c04e51cu: goto P_0c04e51c;
case 0x0c04e51eu: goto P_0c04e51e;
case 0x0c04e520u: goto P_0c04e520;
case 0x0c04e522u: goto P_0c04e522;
case 0x0c04e524u: goto P_0c04e524;
case 0x0c04e526u: goto P_0c04e526;
case 0x0c04e528u: goto P_0c04e528;
case 0x0c04e52au: goto P_0c04e52a;
case 0x0c04e52cu: goto P_0c04e52c;
case 0x0c04e52eu: goto P_0c04e52e;
case 0x0c04e530u: goto P_0c04e530;
case 0x0c04e532u: goto P_0c04e532;
case 0x0c04e534u: goto P_0c04e534;
case 0x0c04e536u: goto P_0c04e536;
case 0x0c04e538u: goto P_0c04e538;
case 0x0c04e53au: goto P_0c04e53a;
case 0x0c04e53cu: goto P_0c04e53c;
case 0x0c04e53eu: goto P_0c04e53e;
case 0x0c04e540u: goto P_0c04e540;
case 0x0c04e542u: goto P_0c04e542;
case 0x0c04e544u: goto P_0c04e544;
case 0x0c04e546u: goto P_0c04e546;
case 0x0c04e548u: goto P_0c04e548;
case 0x0c04e54au: goto P_0c04e54a;
case 0x0c04e54cu: goto P_0c04e54c;
case 0x0c04e54eu: goto P_0c04e54e;
case 0x0c04e550u: goto P_0c04e550;
case 0x0c04e552u: goto P_0c04e552;
case 0x0c04e554u: goto P_0c04e554;
case 0x0c04e556u: goto P_0c04e556;
case 0x0c04e558u: goto P_0c04e558;
case 0x0c04e55au: goto P_0c04e55a;
case 0x0c04e55cu: goto P_0c04e55c;
case 0x0c04e55eu: goto P_0c04e55e;
case 0x0c04e560u: goto P_0c04e560;
case 0x0c04e562u: goto P_0c04e562;
case 0x0c04e564u: goto P_0c04e564;
case 0x0c04e566u: goto P_0c04e566;
case 0x0c04e568u: goto P_0c04e568;
case 0x0c04e59cu: goto P_0c04e59c;
case 0x0c04e59eu: goto P_0c04e59e;
case 0x0c04e5a0u: goto P_0c04e5a0;
case 0x0c04e5a2u: goto P_0c04e5a2;
case 0x0c04e5a4u: goto P_0c04e5a4;
case 0x0c04e5a6u: goto P_0c04e5a6;
case 0x0c04e5a8u: goto P_0c04e5a8;
case 0x0c04e5aau: goto P_0c04e5aa;
case 0x0c04e5acu: goto P_0c04e5ac;
case 0x0c04e5aeu: goto P_0c04e5ae;
case 0x0c04e5b0u: goto P_0c04e5b0;
case 0x0c04e5b2u: goto P_0c04e5b2;
case 0x0c04e5b4u: goto P_0c04e5b4;
case 0x0c04e5b6u: goto P_0c04e5b6;
case 0x0c04e5b8u: goto P_0c04e5b8;
case 0x0c04e5bau: goto P_0c04e5ba;
case 0x0c04e5bcu: goto P_0c04e5bc;
case 0x0c04e5beu: goto P_0c04e5be;
case 0x0c04e5c0u: goto P_0c04e5c0;
case 0x0c04e5c2u: goto P_0c04e5c2;
case 0x0c04e5c4u: goto P_0c04e5c4;
case 0x0c04e5c6u: goto P_0c04e5c6;
case 0x0c04e5c8u: goto P_0c04e5c8;
case 0x0c04e5cau: goto P_0c04e5ca;
case 0x0c04e5ccu: goto P_0c04e5cc;
case 0x0c04e5ceu: goto P_0c04e5ce;
case 0x0c04e5d0u: goto P_0c04e5d0;
case 0x0c04e5d2u: goto P_0c04e5d2;
case 0x0c04e5d4u: goto P_0c04e5d4;
case 0x0c04e5d6u: goto P_0c04e5d6;
case 0x0c04e5d8u: goto P_0c04e5d8;
case 0x0c04e5dau: goto P_0c04e5da;
case 0x0c04e5dcu: goto P_0c04e5dc;
case 0x0c04e5deu: goto P_0c04e5de;
case 0x0c04e5e0u: goto P_0c04e5e0;
case 0x0c04e5e2u: goto P_0c04e5e2;
case 0x0c04e5e4u: goto P_0c04e5e4;
case 0x0c04e5e6u: goto P_0c04e5e6;
case 0x0c04e5e8u: goto P_0c04e5e8;
case 0x0c04e5eau: goto P_0c04e5ea;
case 0x0c04e5ecu: goto P_0c04e5ec;
case 0x0c04e5eeu: goto P_0c04e5ee;
case 0x0c04e5f0u: goto P_0c04e5f0;
case 0x0c04e5f2u: goto P_0c04e5f2;
case 0x0c04e5f4u: goto P_0c04e5f4;
case 0x0c04e5f6u: goto P_0c04e5f6;
case 0x0c04e5f8u: goto P_0c04e5f8;
case 0x0c04e5fau: goto P_0c04e5fa;
case 0x0c04e5fcu: goto P_0c04e5fc;
case 0x0c04e5feu: goto P_0c04e5fe;
case 0x0c04e600u: goto P_0c04e600;
case 0x0c04e602u: goto P_0c04e602;
case 0x0c04e604u: goto P_0c04e604;
case 0x0c04e606u: goto P_0c04e606;
case 0x0c04e608u: goto P_0c04e608;
case 0x0c04e60au: goto P_0c04e60a;
case 0x0c04e60cu: goto P_0c04e60c;
case 0x0c04e60eu: goto P_0c04e60e;
case 0x0c04e610u: goto P_0c04e610;
case 0x0c04e612u: goto P_0c04e612;
case 0x0c04e614u: goto P_0c04e614;
case 0x0c04e616u: goto P_0c04e616;
case 0x0c04e618u: goto P_0c04e618;
case 0x0c04e61au: goto P_0c04e61a;
case 0x0c04e61cu: goto P_0c04e61c;
case 0x0c04e61eu: goto P_0c04e61e;
case 0x0c04e620u: goto P_0c04e620;
case 0x0c04e622u: goto P_0c04e622;
case 0x0c04e624u: goto P_0c04e624;
case 0x0c04e626u: goto P_0c04e626;
case 0x0c04e628u: goto P_0c04e628;
case 0x0c04e62au: goto P_0c04e62a;
case 0x0c04e62cu: goto P_0c04e62c;
case 0x0c04e62eu: goto P_0c04e62e;
case 0x0c04e630u: goto P_0c04e630;
case 0x0c04e632u: goto P_0c04e632;
case 0x0c04e634u: goto P_0c04e634;
case 0x0c04e636u: goto P_0c04e636;
case 0x0c04e638u: goto P_0c04e638;
case 0x0c04e63au: goto P_0c04e63a;
case 0x0c04e63cu: goto P_0c04e63c;
case 0x0c04e63eu: goto P_0c04e63e;
case 0x0c04e640u: goto P_0c04e640;
case 0x0c04e642u: goto P_0c04e642;
case 0x0c04e644u: goto P_0c04e644;
case 0x0c04e646u: goto P_0c04e646;
case 0x0c04e648u: goto P_0c04e648;
case 0x0c04e64au: goto P_0c04e64a;
case 0x0c04e64cu: goto P_0c04e64c;
case 0x0c04e64eu: goto P_0c04e64e;
case 0x0c04e650u: goto P_0c04e650;
case 0x0c04e652u: goto P_0c04e652;
case 0x0c04e654u: goto P_0c04e654;
case 0x0c04e656u: goto P_0c04e656;
case 0x0c04e658u: goto P_0c04e658;
case 0x0c04e65au: goto P_0c04e65a;
case 0x0c04e65cu: goto P_0c04e65c;
case 0x0c04e65eu: goto P_0c04e65e;
case 0x0c04e660u: goto P_0c04e660;
case 0x0c04e662u: goto P_0c04e662;
case 0x0c04e664u: goto P_0c04e664;
case 0x0c04e666u: goto P_0c04e666;
case 0x0c04e668u: goto P_0c04e668;
case 0x0c04e66au: goto P_0c04e66a;
case 0x0c04e66cu: goto P_0c04e66c;
case 0x0c04e66eu: goto P_0c04e66e;
case 0x0c04e670u: goto P_0c04e670;
case 0x0c04e672u: goto P_0c04e672;
case 0x0c04e674u: goto P_0c04e674;
case 0x0c04e676u: goto P_0c04e676;
case 0x0c04e678u: goto P_0c04e678;
case 0x0c04e67au: goto P_0c04e67a;
case 0x0c04e67cu: goto P_0c04e67c;
case 0x0c04e67eu: goto P_0c04e67e;
case 0x0c04e680u: goto P_0c04e680;
case 0x0c04e682u: goto P_0c04e682;
case 0x0c04e684u: goto P_0c04e684;
case 0x0c04e686u: goto P_0c04e686;
case 0x0c04e6b4u: goto P_0c04e6b4;
case 0x0c04e6b6u: goto P_0c04e6b6;
case 0x0c04e6b8u: goto P_0c04e6b8;
case 0x0c04e6bau: goto P_0c04e6ba;
case 0x0c04e6bcu: goto P_0c04e6bc;
case 0x0c04e6beu: goto P_0c04e6be;
case 0x0c04e6c0u: goto P_0c04e6c0;
case 0x0c04e6c2u: goto P_0c04e6c2;
case 0x0c04e6c4u: goto P_0c04e6c4;
case 0x0c04e6c6u: goto P_0c04e6c6;
case 0x0c04e6c8u: goto P_0c04e6c8;
case 0x0c04e6cau: goto P_0c04e6ca;
case 0x0c04e6ccu: goto P_0c04e6cc;
case 0x0c04e6ceu: goto P_0c04e6ce;
case 0x0c04e6d0u: goto P_0c04e6d0;
case 0x0c04e6d2u: goto P_0c04e6d2;
case 0x0c04e6d4u: goto P_0c04e6d4;
case 0x0c04e6d6u: goto P_0c04e6d6;
case 0x0c04e6d8u: goto P_0c04e6d8;
case 0x0c04e6dau: goto P_0c04e6da;
case 0x0c04e6dcu: goto P_0c04e6dc;
case 0x0c04e6deu: goto P_0c04e6de;
case 0x0c04e6e0u: goto P_0c04e6e0;
case 0x0c04e6e2u: goto P_0c04e6e2;
case 0x0c04e6e4u: goto P_0c04e6e4;
case 0x0c04e6e6u: goto P_0c04e6e6;
case 0x0c04e6e8u: goto P_0c04e6e8;
case 0x0c04e6eau: goto P_0c04e6ea;
case 0x0c04e6ecu: goto P_0c04e6ec;
case 0x0c04e6eeu: goto P_0c04e6ee;
case 0x0c04e6f0u: goto P_0c04e6f0;
case 0x0c04e6f2u: goto P_0c04e6f2;
case 0x0c04e6f4u: goto P_0c04e6f4;
case 0x0c04e6f6u: goto P_0c04e6f6;
case 0x0c04e6f8u: goto P_0c04e6f8;
case 0x0c04e6fau: goto P_0c04e6fa;
case 0x0c04e6fcu: goto P_0c04e6fc;
case 0x0c04e6feu: goto P_0c04e6fe;
case 0x0c04e700u: goto P_0c04e700;
case 0x0c04e702u: goto P_0c04e702;
case 0x0c04e704u: goto P_0c04e704;
case 0x0c04e706u: goto P_0c04e706;
case 0x0c04e708u: goto P_0c04e708;
case 0x0c04e70au: goto P_0c04e70a;
case 0x0c04e70cu: goto P_0c04e70c;
case 0x0c04e70eu: goto P_0c04e70e;
case 0x0c04e710u: goto P_0c04e710;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04e4e0: /* original 2fe6, guest PC 0x0c04e4e0 */
if(!s->budget--) { s->failed_pc=0x0c04e4e0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e4e2;
P_0c04e4e2: /* original 2fd6, guest PC 0x0c04e4e2 */
if(!s->budget--) { s->failed_pc=0x0c04e4e2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e4e4;
P_0c04e4e4: /* original 6d43, guest PC 0x0c04e4e4 */
if(!s->budget--) { s->failed_pc=0x0c04e4e4u; return 0; }
r[13]=r[4];
goto P_0c04e4e6;
P_0c04e4e6: /* original 2fc6, guest PC 0x0c04e4e6 */
if(!s->budget--) { s->failed_pc=0x0c04e4e6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e4e8;
P_0c04e4e8: /* original 2fa6, guest PC 0x0c04e4e8 */
if(!s->budget--) { s->failed_pc=0x0c04e4e8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e4ea;
P_0c04e4ea: /* original 6a53, guest PC 0x0c04e4ea */
if(!s->budget--) { s->failed_pc=0x0c04e4eau; return 0; }
r[10]=r[5];
goto P_0c04e4ec;
P_0c04e4ec: /* original 4f22, guest PC 0x0c04e4ec */
if(!s->budget--) { s->failed_pc=0x0c04e4ecu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04e4ee;
P_0c04e4ee: /* original 9e3c, guest PC 0x0c04e4ee */
if(!s->budget--) { s->failed_pc=0x0c04e4eeu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e56au,2);
goto P_0c04e4f0;
P_0c04e4f0: /* original 4f12, guest PC 0x0c04e4f0 */
if(!s->budget--) { s->failed_pc=0x0c04e4f0u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04e4f2;
P_0c04e4f2: /* original 2def, guest PC 0x0c04e4f2 */
if(!s->budget--) { s->failed_pc=0x0c04e4f2u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[14]);
goto P_0c04e4f4;
P_0c04e4f4: /* original 7ffc, guest PC 0x0c04e4f4 */
if(!s->budget--) { s->failed_pc=0x0c04e4f4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04e4f6;
P_0c04e4f6: /* original 0e1a, guest PC 0x0c04e4f6 */
if(!s->budget--) { s->failed_pc=0x0c04e4f6u; return 0; }
r[14]=r[19];
goto P_0c04e4f8;
P_0c04e4f8: /* original 6eef, guest PC 0x0c04e4f8 */
if(!s->budget--) { s->failed_pc=0x0c04e4f8u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04e4fa;
P_0c04e4fa: /* original 2fe2, guest PC 0x0c04e4fa */
if(!s->budget--) { s->failed_pc=0x0c04e4fau; return 0; }
write(ram,r[15],r[14],4);
goto P_0c04e4fc;
P_0c04e4fc: /* original d321, guest PC 0x0c04e4fc */
if(!s->budget--) { s->failed_pc=0x0c04e4fcu; return 0; }
r[3]=read(ram,0x0c04e584u,4);
goto P_0c04e4fe;
P_0c04e4fe: /* original 2fa6, guest PC 0x0c04e4fe */
if(!s->budget--) { s->failed_pc=0x0c04e4feu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e500;
P_0c04e500: /* original 3e3c, guest PC 0x0c04e500 */
if(!s->budget--) { s->failed_pc=0x0c04e500u; return 0; }
r[14]+=r[3];
goto P_0c04e502;
P_0c04e502: /* original 2fd6, guest PC 0x0c04e502 */
if(!s->budget--) { s->failed_pc=0x0c04e502u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e504;
P_0c04e504: /* original d220, guest PC 0x0c04e504 */
if(!s->budget--) { s->failed_pc=0x0c04e504u; return 0; }
r[2]=read(ram,0x0c04e588u,4);
goto P_0c04e506;
P_0c04e506: /* original d121, guest PC 0x0c04e506 */
if(!s->budget--) { s->failed_pc=0x0c04e506u; return 0; }
r[1]=read(ram,0x0c04e58cu,4);
goto P_0c04e508;
P_0c04e508: /* original 410b, guest PC 0x0c04e508 */
if(!s->budget--) { s->failed_pc=0x0c04e508u; return 0; }
target=r[1];
r[16]=code_base|0x0c04e50cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e50cu) { target=s->pc; goto dispatch; }
goto P_0c04e50c;
P_0c04e50a: /* original 2f26, guest PC 0x0c04e50a */
if(!s->budget--) { s->failed_pc=0x0c04e50au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e50c;
P_0c04e50c: /* original 84e2, guest PC 0x0c04e50c */
if(!s->budget--) { s->failed_pc=0x0c04e50cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c04e50e;
P_0c04e50e: /* original 2008, guest PC 0x0c04e50e */
if(!s->budget--) { s->failed_pc=0x0c04e50eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e510;
P_0c04e510: /* original 8d15, guest PC 0x0c04e510 */
if(!s->budget--) { s->failed_pc=0x0c04e510u; return 0; }
cond=r[17]&1u;
r[15]+=0x0000000cu;
if(cond) { goto P_0c04e53e; }
goto P_0c04e514;
P_0c04e512: /* original 7f0c, guest PC 0x0c04e512 */
if(!s->budget--) { s->failed_pc=0x0c04e512u; return 0; }
r[15]+=0x0000000cu;
goto P_0c04e514;
P_0c04e514: /* original d21e, guest PC 0x0c04e514 */
if(!s->budget--) { s->failed_pc=0x0c04e514u; return 0; }
r[2]=read(ram,0x0c04e590u,4);
goto P_0c04e516;
P_0c04e516: /* original 420b, guest PC 0x0c04e516 */
if(!s->budget--) { s->failed_pc=0x0c04e516u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e51au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e51au) { target=s->pc; goto dispatch; }
goto P_0c04e51a;
P_0c04e518: /* original 64d3, guest PC 0x0c04e518 */
if(!s->budget--) { s->failed_pc=0x0c04e518u; return 0; }
r[4]=r[13];
goto P_0c04e51a;
P_0c04e51a: /* original 2008, guest PC 0x0c04e51a */
if(!s->budget--) { s->failed_pc=0x0c04e51au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e51c;
P_0c04e51c: /* original 8b04, guest PC 0x0c04e51c */
if(!s->budget--) { s->failed_pc=0x0c04e51cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e528; }
goto P_0c04e51e;
P_0c04e51e: /* original d21d, guest PC 0x0c04e51e */
if(!s->budget--) { s->failed_pc=0x0c04e51eu; return 0; }
r[2]=read(ram,0x0c04e594u,4);
goto P_0c04e520;
P_0c04e520: /* original 420b, guest PC 0x0c04e520 */
if(!s->budget--) { s->failed_pc=0x0c04e520u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e524u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e524u) { target=s->pc; goto dispatch; }
goto P_0c04e524;
P_0c04e522: /* original 64d3, guest PC 0x0c04e522 */
if(!s->budget--) { s->failed_pc=0x0c04e522u; return 0; }
r[4]=r[13];
goto P_0c04e524;
P_0c04e524: /* original a00b, guest PC 0x0c04e524 */
if(!s->budget--) { s->failed_pc=0x0c04e524u; return 0; }
goto P_0c04e53e;
P_0c04e526: /* original 0009, guest PC 0x0c04e526 */
if(!s->budget--) { s->failed_pc=0x0c04e526u; return 0; }
goto P_0c04e528;
P_0c04e528: /* original d312, guest PC 0x0c04e528 */
if(!s->budget--) { s->failed_pc=0x0c04e528u; return 0; }
r[3]=read(ram,0x0c04e574u,4);
goto P_0c04e52a;
P_0c04e52a: /* original 430b, guest PC 0x0c04e52a */
if(!s->budget--) { s->failed_pc=0x0c04e52au; return 0; }
target=r[3];
r[16]=code_base|0x0c04e52eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e52eu) { target=s->pc; goto dispatch; }
goto P_0c04e52e;
P_0c04e52c: /* original 64d3, guest PC 0x0c04e52c */
if(!s->budget--) { s->failed_pc=0x0c04e52cu; return 0; }
r[4]=r[13];
goto P_0c04e52e;
P_0c04e52e: /* original 2008, guest PC 0x0c04e52e */
if(!s->budget--) { s->failed_pc=0x0c04e52eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e530;
P_0c04e530: /* original 8905, guest PC 0x0c04e530 */
if(!s->budget--) { s->failed_pc=0x0c04e530u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e53e; }
goto P_0c04e532;
P_0c04e532: /* original 62f2, guest PC 0x0c04e532 */
if(!s->budget--) { s->failed_pc=0x0c04e532u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04e534;
P_0c04e534: /* original d313, guest PC 0x0c04e534 */
if(!s->budget--) { s->failed_pc=0x0c04e534u; return 0; }
r[3]=read(ram,0x0c04e584u,4);
goto P_0c04e536;
P_0c04e536: /* original 323c, guest PC 0x0c04e536 */
if(!s->budget--) { s->failed_pc=0x0c04e536u; return 0; }
r[2]+=r[3];
goto P_0c04e538;
P_0c04e538: /* original 8428, guest PC 0x0c04e538 */
if(!s->budget--) { s->failed_pc=0x0c04e538u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04e53a;
P_0c04e53a: /* original 2008, guest PC 0x0c04e53a */
if(!s->budget--) { s->failed_pc=0x0c04e53au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e53c;
P_0c04e53c: /* original 8b02, guest PC 0x0c04e53c */
if(!s->budget--) { s->failed_pc=0x0c04e53cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e544; }
goto P_0c04e53e;
P_0c04e53e: /* original 9015, guest PC 0x0c04e53e */
if(!s->budget--) { s->failed_pc=0x0c04e53eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e56cu,2);
goto P_0c04e540;
P_0c04e540: /* original a056, guest PC 0x0c04e540 */
if(!s->budget--) { s->failed_pc=0x0c04e540u; return 0; }
goto P_0c04e5f0;
P_0c04e542: /* original 0009, guest PC 0x0c04e542 */
if(!s->budget--) { s->failed_pc=0x0c04e542u; return 0; }
goto P_0c04e544;
P_0c04e544: /* original d30d, guest PC 0x0c04e544 */
if(!s->budget--) { s->failed_pc=0x0c04e544u; return 0; }
r[3]=read(ram,0x0c04e57cu,4);
goto P_0c04e546;
P_0c04e546: /* original 430b, guest PC 0x0c04e546 */
if(!s->budget--) { s->failed_pc=0x0c04e546u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e54au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e54au) { target=s->pc; goto dispatch; }
goto P_0c04e54a;
P_0c04e548: /* original 64d3, guest PC 0x0c04e548 */
if(!s->budget--) { s->failed_pc=0x0c04e548u; return 0; }
r[4]=r[13];
goto P_0c04e54a;
P_0c04e54a: /* original 4011, guest PC 0x0c04e54a */
if(!s->budget--) { s->failed_pc=0x0c04e54au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e54c;
P_0c04e54c: /* original 8902, guest PC 0x0c04e54c */
if(!s->budget--) { s->failed_pc=0x0c04e54cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e554; }
goto P_0c04e54e;
P_0c04e54e: /* original 900e, guest PC 0x0c04e54e */
if(!s->budget--) { s->failed_pc=0x0c04e54eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e56eu,2);
goto P_0c04e550;
P_0c04e550: /* original a04e, guest PC 0x0c04e550 */
if(!s->budget--) { s->failed_pc=0x0c04e550u; return 0; }
goto P_0c04e5f0;
P_0c04e552: /* original 0009, guest PC 0x0c04e552 */
if(!s->budget--) { s->failed_pc=0x0c04e552u; return 0; }
goto P_0c04e554;
P_0c04e554: /* original ec00, guest PC 0x0c04e554 */
if(!s->budget--) { s->failed_pc=0x0c04e554u; return 0; }
r[12]=0x00000000u;
goto P_0c04e556;
P_0c04e556: /* original 65c3, guest PC 0x0c04e556 */
if(!s->budget--) { s->failed_pc=0x0c04e556u; return 0; }
r[5]=r[12];
goto P_0c04e558;
P_0c04e558: /* original 1ec6, guest PC 0x0c04e558 */
if(!s->budget--) { s->failed_pc=0x0c04e558u; return 0; }
write(ram,r[14]+24,r[12],4);
goto P_0c04e55a;
P_0c04e55a: /* original d30f, guest PC 0x0c04e55a */
if(!s->budget--) { s->failed_pc=0x0c04e55au; return 0; }
r[3]=read(ram,0x0c04e598u,4);
goto P_0c04e55c;
P_0c04e55c: /* original 430b, guest PC 0x0c04e55c */
if(!s->budget--) { s->failed_pc=0x0c04e55cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04e560u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e560u) { target=s->pc; goto dispatch; }
goto P_0c04e560;
P_0c04e55e: /* original 64d3, guest PC 0x0c04e55e */
if(!s->budget--) { s->failed_pc=0x0c04e55eu; return 0; }
r[4]=r[13];
goto P_0c04e560;
P_0c04e560: /* original 65c3, guest PC 0x0c04e560 */
if(!s->budget--) { s->failed_pc=0x0c04e560u; return 0; }
r[5]=r[12];
goto P_0c04e562;
P_0c04e562: /* original 6dc3, guest PC 0x0c04e562 */
if(!s->budget--) { s->failed_pc=0x0c04e562u; return 0; }
r[13]=r[12];
goto P_0c04e564;
P_0c04e564: /* original 6403, guest PC 0x0c04e564 */
if(!s->budget--) { s->failed_pc=0x0c04e564u; return 0; }
r[4]=r[0];
goto P_0c04e566;
P_0c04e566: /* original a028, guest PC 0x0c04e566 */
if(!s->budget--) { s->failed_pc=0x0c04e566u; return 0; }
r[1]=0x00000001u;
goto P_0c04e5ba;
P_0c04e568: /* original e101, guest PC 0x0c04e568 */
if(!s->budget--) { s->failed_pc=0x0c04e568u; return 0; }
r[1]=0x00000001u;
if(!vf3_matrix_family(0x0c04e56au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04e56au; return 0; } return 1;
P_0c04e59c: /* original 6640, guest PC 0x0c04e59c */
if(!s->budget--) { s->failed_pc=0x0c04e59cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[6]=tmp;
goto P_0c04e59e;
P_0c04e59e: /* original 676c, guest PC 0x0c04e59e */
if(!s->budget--) { s->failed_pc=0x0c04e59eu; return 0; }
r[7]=r[6]&255u;
goto P_0c04e5a0;
P_0c04e5a0: /* original 6073, guest PC 0x0c04e5a0 */
if(!s->budget--) { s->failed_pc=0x0c04e5a0u; return 0; }
r[0]=r[7];
goto P_0c04e5a2;
P_0c04e5a2: /* original 8833, guest PC 0x0c04e5a2 */
if(!s->budget--) { s->failed_pc=0x0c04e5a2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000033u)!=0);
goto P_0c04e5a4;
P_0c04e5a4: /* original 8902, guest PC 0x0c04e5a4 */
if(!s->budget--) { s->failed_pc=0x0c04e5a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e5ac; }
goto P_0c04e5a6;
P_0c04e5a6: /* original 926f, guest PC 0x0c04e5a6 */
if(!s->budget--) { s->failed_pc=0x0c04e5a6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e688u,2);
goto P_0c04e5a8;
P_0c04e5a8: /* original 3720, guest PC 0x0c04e5a8 */
if(!s->budget--) { s->failed_pc=0x0c04e5a8u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[2])!=0);
goto P_0c04e5aa;
P_0c04e5aa: /* original 8b01, guest PC 0x0c04e5aa */
if(!s->budget--) { s->failed_pc=0x0c04e5aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e5b0; }
goto P_0c04e5ac;
P_0c04e5ac: /* original a009, guest PC 0x0c04e5ac */
if(!s->budget--) { s->failed_pc=0x0c04e5acu; return 0; }
r[13]=r[1];
goto P_0c04e5c2;
P_0c04e5ae: /* original 6d13, guest PC 0x0c04e5ae */
if(!s->budget--) { s->failed_pc=0x0c04e5aeu; return 0; }
r[13]=r[1];
goto P_0c04e5b0;
P_0c04e5b0: /* original 53e6, guest PC 0x0c04e5b0 */
if(!s->budget--) { s->failed_pc=0x0c04e5b0u; return 0; }
r[3]=read(ram,r[14]+24,4);
goto P_0c04e5b2;
P_0c04e5b2: /* original 7420, guest PC 0x0c04e5b2 */
if(!s->budget--) { s->failed_pc=0x0c04e5b2u; return 0; }
r[4]+=0x00000020u;
goto P_0c04e5b4;
P_0c04e5b4: /* original 7501, guest PC 0x0c04e5b4 */
if(!s->budget--) { s->failed_pc=0x0c04e5b4u; return 0; }
r[5]+=0x00000001u;
goto P_0c04e5b6;
P_0c04e5b6: /* original 7301, guest PC 0x0c04e5b6 */
if(!s->budget--) { s->failed_pc=0x0c04e5b6u; return 0; }
r[3]+=0x00000001u;
goto P_0c04e5b8;
P_0c04e5b8: /* original 1e36, guest PC 0x0c04e5b8 */
if(!s->budget--) { s->failed_pc=0x0c04e5b8u; return 0; }
write(ram,r[14]+24,r[3],4);
goto P_0c04e5ba;
P_0c04e5ba: /* original 52e7, guest PC 0x0c04e5ba */
if(!s->budget--) { s->failed_pc=0x0c04e5bau; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04e5bc;
P_0c04e5bc: /* original 532c, guest PC 0x0c04e5bc */
if(!s->budget--) { s->failed_pc=0x0c04e5bcu; return 0; }
r[3]=read(ram,r[2]+48,4);
goto P_0c04e5be;
P_0c04e5be: /* original 3533, guest PC 0x0c04e5be */
if(!s->budget--) { s->failed_pc=0x0c04e5beu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[3])!=0);
goto P_0c04e5c0;
P_0c04e5c0: /* original 8bec, guest PC 0x0c04e5c0 */
if(!s->budget--) { s->failed_pc=0x0c04e5c0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e59c; }
goto P_0c04e5c2;
P_0c04e5c2: /* original 2dd8, guest PC 0x0c04e5c2 */
if(!s->budget--) { s->failed_pc=0x0c04e5c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c04e5c4;
P_0c04e5c4: /* original 8b02, guest PC 0x0c04e5c4 */
if(!s->budget--) { s->failed_pc=0x0c04e5c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e5cc; }
goto P_0c04e5c6;
P_0c04e5c6: /* original 9060, guest PC 0x0c04e5c6 */
if(!s->budget--) { s->failed_pc=0x0c04e5c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e68au,2);
goto P_0c04e5c8;
P_0c04e5c8: /* original a012, guest PC 0x0c04e5c8 */
if(!s->budget--) { s->failed_pc=0x0c04e5c8u; return 0; }
goto P_0c04e5f0;
P_0c04e5ca: /* original 0009, guest PC 0x0c04e5ca */
if(!s->budget--) { s->failed_pc=0x0c04e5cau; return 0; }
goto P_0c04e5cc;
P_0c04e5cc: /* original 6743, guest PC 0x0c04e5cc */
if(!s->budget--) { s->failed_pc=0x0c04e5ccu; return 0; }
r[7]=r[4];
goto P_0c04e5ce;
P_0c04e5ce: /* original 64a3, guest PC 0x0c04e5ce */
if(!s->budget--) { s->failed_pc=0x0c04e5ceu; return 0; }
r[4]=r[10];
goto P_0c04e5d0;
P_0c04e5d0: /* original 7704, guest PC 0x0c04e5d0 */
if(!s->budget--) { s->failed_pc=0x0c04e5d0u; return 0; }
r[7]+=0x00000004u;
goto P_0c04e5d2;
P_0c04e5d2: /* original 65c3, guest PC 0x0c04e5d2 */
if(!s->budget--) { s->failed_pc=0x0c04e5d2u; return 0; }
r[5]=r[12];
goto P_0c04e5d4;
P_0c04e5d4: /* original a004, guest PC 0x0c04e5d4 */
if(!s->budget--) { s->failed_pc=0x0c04e5d4u; return 0; }
r[6]=0x0000000cu;
goto P_0c04e5e0;
P_0c04e5d6: /* original e60c, guest PC 0x0c04e5d6 */
if(!s->budget--) { s->failed_pc=0x0c04e5d6u; return 0; }
r[6]=0x0000000cu;
goto P_0c04e5d8;
P_0c04e5d8: /* original 6374, guest PC 0x0c04e5d8 */
if(!s->budget--) { s->failed_pc=0x0c04e5d8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]+=1;
r[3]=tmp;
goto P_0c04e5da;
P_0c04e5da: /* original 7501, guest PC 0x0c04e5da */
if(!s->budget--) { s->failed_pc=0x0c04e5dau; return 0; }
r[5]+=0x00000001u;
goto P_0c04e5dc;
P_0c04e5dc: /* original 2430, guest PC 0x0c04e5dc */
if(!s->budget--) { s->failed_pc=0x0c04e5dcu; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04e5de;
P_0c04e5de: /* original 7401, guest PC 0x0c04e5de */
if(!s->budget--) { s->failed_pc=0x0c04e5deu; return 0; }
r[4]+=0x00000001u;
goto P_0c04e5e0;
P_0c04e5e0: /* original 3563, guest PC 0x0c04e5e0 */
if(!s->budget--) { s->failed_pc=0x0c04e5e0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c04e5e2;
P_0c04e5e2: /* original 8bf9, guest PC 0x0c04e5e2 */
if(!s->budget--) { s->failed_pc=0x0c04e5e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e5d8; }
goto P_0c04e5e4;
P_0c04e5e4: /* original 60c3, guest PC 0x0c04e5e4 */
if(!s->budget--) { s->failed_pc=0x0c04e5e4u; return 0; }
r[0]=r[12];
goto P_0c04e5e6;
P_0c04e5e6: /* original 80ac, guest PC 0x0c04e5e6 */
if(!s->budget--) { s->failed_pc=0x0c04e5e6u; return 0; }
write(ram,r[10]+12,r[0],1);
goto P_0c04e5e8;
P_0c04e5e8: /* original 53e6, guest PC 0x0c04e5e8 */
if(!s->budget--) { s->failed_pc=0x0c04e5e8u; return 0; }
r[3]=read(ram,r[14]+24,4);
goto P_0c04e5ea;
P_0c04e5ea: /* original e000, guest PC 0x0c04e5ea */
if(!s->budget--) { s->failed_pc=0x0c04e5eau; return 0; }
r[0]=0x00000000u;
goto P_0c04e5ec;
P_0c04e5ec: /* original 7301, guest PC 0x0c04e5ec */
if(!s->budget--) { s->failed_pc=0x0c04e5ecu; return 0; }
r[3]+=0x00000001u;
goto P_0c04e5ee;
P_0c04e5ee: /* original 1e36, guest PC 0x0c04e5ee */
if(!s->budget--) { s->failed_pc=0x0c04e5eeu; return 0; }
write(ram,r[14]+24,r[3],4);
goto P_0c04e5f0;
P_0c04e5f0: /* original 7f04, guest PC 0x0c04e5f0 */
if(!s->budget--) { s->failed_pc=0x0c04e5f0u; return 0; }
r[15]+=0x00000004u;
goto P_0c04e5f2;
P_0c04e5f2: /* original 4f16, guest PC 0x0c04e5f2 */
if(!s->budget--) { s->failed_pc=0x0c04e5f2u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e5f4;
P_0c04e5f4: /* original 4f26, guest PC 0x0c04e5f4 */
if(!s->budget--) { s->failed_pc=0x0c04e5f4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e5f6;
P_0c04e5f6: /* original 6af6, guest PC 0x0c04e5f6 */
if(!s->budget--) { s->failed_pc=0x0c04e5f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04e5f8;
P_0c04e5f8: /* original 6cf6, guest PC 0x0c04e5f8 */
if(!s->budget--) { s->failed_pc=0x0c04e5f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04e5fa;
P_0c04e5fa: /* original 6df6, guest PC 0x0c04e5fa */
if(!s->budget--) { s->failed_pc=0x0c04e5fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04e5fc;
P_0c04e5fc: /* original 000b, guest PC 0x0c04e5fc */
if(!s->budget--) { s->failed_pc=0x0c04e5fcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04e5fe: /* original 6ef6, guest PC 0x0c04e5fe */
if(!s->budget--) { s->failed_pc=0x0c04e5feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04e600;
P_0c04e600: /* original 2fe6, guest PC 0x0c04e600 */
if(!s->budget--) { s->failed_pc=0x0c04e600u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e602;
P_0c04e602: /* original 6e43, guest PC 0x0c04e602 */
if(!s->budget--) { s->failed_pc=0x0c04e602u; return 0; }
r[14]=r[4];
goto P_0c04e604;
P_0c04e604: /* original 2fd6, guest PC 0x0c04e604 */
if(!s->budget--) { s->failed_pc=0x0c04e604u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e606;
P_0c04e606: /* original 2fb6, guest PC 0x0c04e606 */
if(!s->budget--) { s->failed_pc=0x0c04e606u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e608;
P_0c04e608: /* original 6b53, guest PC 0x0c04e608 */
if(!s->budget--) { s->failed_pc=0x0c04e608u; return 0; }
r[11]=r[5];
goto P_0c04e60a;
P_0c04e60a: /* original 2fa6, guest PC 0x0c04e60a */
if(!s->budget--) { s->failed_pc=0x0c04e60au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e60c;
P_0c04e60c: /* original 4f22, guest PC 0x0c04e60c */
if(!s->budget--) { s->failed_pc=0x0c04e60cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04e60e;
P_0c04e60e: /* original 9d3d, guest PC 0x0c04e60e */
if(!s->budget--) { s->failed_pc=0x0c04e60eu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e68cu,2);
goto P_0c04e610;
P_0c04e610: /* original 4f12, guest PC 0x0c04e610 */
if(!s->budget--) { s->failed_pc=0x0c04e610u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04e612;
P_0c04e612: /* original 2edf, guest PC 0x0c04e612 */
if(!s->budget--) { s->failed_pc=0x0c04e612u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[13]);
goto P_0c04e614;
P_0c04e614: /* original 7ffc, guest PC 0x0c04e614 */
if(!s->budget--) { s->failed_pc=0x0c04e614u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04e616;
P_0c04e616: /* original 0d1a, guest PC 0x0c04e616 */
if(!s->budget--) { s->failed_pc=0x0c04e616u; return 0; }
r[13]=r[19];
goto P_0c04e618;
P_0c04e618: /* original 6ddf, guest PC 0x0c04e618 */
if(!s->budget--) { s->failed_pc=0x0c04e618u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c04e61a;
P_0c04e61a: /* original 2fd2, guest PC 0x0c04e61a */
if(!s->budget--) { s->failed_pc=0x0c04e61au; return 0; }
write(ram,r[15],r[13],4);
goto P_0c04e61c;
P_0c04e61c: /* original d31d, guest PC 0x0c04e61c */
if(!s->budget--) { s->failed_pc=0x0c04e61cu; return 0; }
r[3]=read(ram,0x0c04e694u,4);
goto P_0c04e61e;
P_0c04e61e: /* original 2fb6, guest PC 0x0c04e61e */
if(!s->budget--) { s->failed_pc=0x0c04e61eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e620;
P_0c04e620: /* original 3d3c, guest PC 0x0c04e620 */
if(!s->budget--) { s->failed_pc=0x0c04e620u; return 0; }
r[13]+=r[3];
goto P_0c04e622;
P_0c04e622: /* original 2fe6, guest PC 0x0c04e622 */
if(!s->budget--) { s->failed_pc=0x0c04e622u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e624;
P_0c04e624: /* original d21c, guest PC 0x0c04e624 */
if(!s->budget--) { s->failed_pc=0x0c04e624u; return 0; }
r[2]=read(ram,0x0c04e698u,4);
goto P_0c04e626;
P_0c04e626: /* original d11d, guest PC 0x0c04e626 */
if(!s->budget--) { s->failed_pc=0x0c04e626u; return 0; }
r[1]=read(ram,0x0c04e69cu,4);
goto P_0c04e628;
P_0c04e628: /* original 410b, guest PC 0x0c04e628 */
if(!s->budget--) { s->failed_pc=0x0c04e628u; return 0; }
target=r[1];
r[16]=code_base|0x0c04e62cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e62cu) { target=s->pc; goto dispatch; }
goto P_0c04e62c;
P_0c04e62a: /* original 2f26, guest PC 0x0c04e62a */
if(!s->budget--) { s->failed_pc=0x0c04e62au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e62c;
P_0c04e62c: /* original 84d2, guest PC 0x0c04e62c */
if(!s->budget--) { s->failed_pc=0x0c04e62cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+2,1);
goto P_0c04e62e;
P_0c04e62e: /* original 2008, guest PC 0x0c04e62e */
if(!s->budget--) { s->failed_pc=0x0c04e62eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e630;
P_0c04e630: /* original 8d15, guest PC 0x0c04e630 */
if(!s->budget--) { s->failed_pc=0x0c04e630u; return 0; }
cond=r[17]&1u;
r[15]+=0x0000000cu;
if(cond) { goto P_0c04e65e; }
goto P_0c04e634;
P_0c04e632: /* original 7f0c, guest PC 0x0c04e632 */
if(!s->budget--) { s->failed_pc=0x0c04e632u; return 0; }
r[15]+=0x0000000cu;
goto P_0c04e634;
P_0c04e634: /* original d21a, guest PC 0x0c04e634 */
if(!s->budget--) { s->failed_pc=0x0c04e634u; return 0; }
r[2]=read(ram,0x0c04e6a0u,4);
goto P_0c04e636;
P_0c04e636: /* original 420b, guest PC 0x0c04e636 */
if(!s->budget--) { s->failed_pc=0x0c04e636u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e63au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e63au) { target=s->pc; goto dispatch; }
goto P_0c04e63a;
P_0c04e638: /* original 64e3, guest PC 0x0c04e638 */
if(!s->budget--) { s->failed_pc=0x0c04e638u; return 0; }
r[4]=r[14];
goto P_0c04e63a;
P_0c04e63a: /* original 2008, guest PC 0x0c04e63a */
if(!s->budget--) { s->failed_pc=0x0c04e63au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e63c;
P_0c04e63c: /* original 8b04, guest PC 0x0c04e63c */
if(!s->budget--) { s->failed_pc=0x0c04e63cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e648; }
goto P_0c04e63e;
P_0c04e63e: /* original d219, guest PC 0x0c04e63e */
if(!s->budget--) { s->failed_pc=0x0c04e63eu; return 0; }
r[2]=read(ram,0x0c04e6a4u,4);
goto P_0c04e640;
P_0c04e640: /* original 420b, guest PC 0x0c04e640 */
if(!s->budget--) { s->failed_pc=0x0c04e640u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e644u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e644u) { target=s->pc; goto dispatch; }
goto P_0c04e644;
P_0c04e642: /* original 64e3, guest PC 0x0c04e642 */
if(!s->budget--) { s->failed_pc=0x0c04e642u; return 0; }
r[4]=r[14];
goto P_0c04e644;
P_0c04e644: /* original a00b, guest PC 0x0c04e644 */
if(!s->budget--) { s->failed_pc=0x0c04e644u; return 0; }
goto P_0c04e65e;
P_0c04e646: /* original 0009, guest PC 0x0c04e646 */
if(!s->budget--) { s->failed_pc=0x0c04e646u; return 0; }
goto P_0c04e648;
P_0c04e648: /* original d317, guest PC 0x0c04e648 */
if(!s->budget--) { s->failed_pc=0x0c04e648u; return 0; }
r[3]=read(ram,0x0c04e6a8u,4);
goto P_0c04e64a;
P_0c04e64a: /* original 430b, guest PC 0x0c04e64a */
if(!s->budget--) { s->failed_pc=0x0c04e64au; return 0; }
target=r[3];
r[16]=code_base|0x0c04e64eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e64eu) { target=s->pc; goto dispatch; }
goto P_0c04e64e;
P_0c04e64c: /* original 64e3, guest PC 0x0c04e64c */
if(!s->budget--) { s->failed_pc=0x0c04e64cu; return 0; }
r[4]=r[14];
goto P_0c04e64e;
P_0c04e64e: /* original 2008, guest PC 0x0c04e64e */
if(!s->budget--) { s->failed_pc=0x0c04e64eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e650;
P_0c04e650: /* original 8905, guest PC 0x0c04e650 */
if(!s->budget--) { s->failed_pc=0x0c04e650u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e65e; }
goto P_0c04e652;
P_0c04e652: /* original 62f2, guest PC 0x0c04e652 */
if(!s->budget--) { s->failed_pc=0x0c04e652u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04e654;
P_0c04e654: /* original d30f, guest PC 0x0c04e654 */
if(!s->budget--) { s->failed_pc=0x0c04e654u; return 0; }
r[3]=read(ram,0x0c04e694u,4);
goto P_0c04e656;
P_0c04e656: /* original 323c, guest PC 0x0c04e656 */
if(!s->budget--) { s->failed_pc=0x0c04e656u; return 0; }
r[2]+=r[3];
goto P_0c04e658;
P_0c04e658: /* original 8428, guest PC 0x0c04e658 */
if(!s->budget--) { s->failed_pc=0x0c04e658u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04e65a;
P_0c04e65a: /* original 2008, guest PC 0x0c04e65a */
if(!s->budget--) { s->failed_pc=0x0c04e65au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e65c;
P_0c04e65c: /* original 8b02, guest PC 0x0c04e65c */
if(!s->budget--) { s->failed_pc=0x0c04e65cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e664; }
goto P_0c04e65e;
P_0c04e65e: /* original 9016, guest PC 0x0c04e65e */
if(!s->budget--) { s->failed_pc=0x0c04e65eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e68eu,2);
goto P_0c04e660;
P_0c04e660: /* original a04f, guest PC 0x0c04e660 */
if(!s->budget--) { s->failed_pc=0x0c04e660u; return 0; }
goto P_0c04e702;
P_0c04e662: /* original 0009, guest PC 0x0c04e662 */
if(!s->budget--) { s->failed_pc=0x0c04e662u; return 0; }
goto P_0c04e664;
P_0c04e664: /* original d311, guest PC 0x0c04e664 */
if(!s->budget--) { s->failed_pc=0x0c04e664u; return 0; }
r[3]=read(ram,0x0c04e6acu,4);
goto P_0c04e666;
P_0c04e666: /* original 430b, guest PC 0x0c04e666 */
if(!s->budget--) { s->failed_pc=0x0c04e666u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e66au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e66au) { target=s->pc; goto dispatch; }
goto P_0c04e66a;
P_0c04e668: /* original 64e3, guest PC 0x0c04e668 */
if(!s->budget--) { s->failed_pc=0x0c04e668u; return 0; }
r[4]=r[14];
goto P_0c04e66a;
P_0c04e66a: /* original 4011, guest PC 0x0c04e66a */
if(!s->budget--) { s->failed_pc=0x0c04e66au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e66c;
P_0c04e66c: /* original 8902, guest PC 0x0c04e66c */
if(!s->budget--) { s->failed_pc=0x0c04e66cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e674; }
goto P_0c04e66e;
P_0c04e66e: /* original 900f, guest PC 0x0c04e66e */
if(!s->budget--) { s->failed_pc=0x0c04e66eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e690u,2);
goto P_0c04e670;
P_0c04e670: /* original a047, guest PC 0x0c04e670 */
if(!s->budget--) { s->failed_pc=0x0c04e670u; return 0; }
goto P_0c04e702;
P_0c04e672: /* original 0009, guest PC 0x0c04e672 */
if(!s->budget--) { s->failed_pc=0x0c04e672u; return 0; }
goto P_0c04e674;
P_0c04e674: /* original d30e, guest PC 0x0c04e674 */
if(!s->budget--) { s->failed_pc=0x0c04e674u; return 0; }
r[3]=read(ram,0x0c04e6b0u,4);
goto P_0c04e676;
P_0c04e676: /* original 55d6, guest PC 0x0c04e676 */
if(!s->budget--) { s->failed_pc=0x0c04e676u; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c04e678;
P_0c04e678: /* original 430b, guest PC 0x0c04e678 */
if(!s->budget--) { s->failed_pc=0x0c04e678u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e67cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e67cu) { target=s->pc; goto dispatch; }
goto P_0c04e67c;
P_0c04e67a: /* original 64e3, guest PC 0x0c04e67a */
if(!s->budget--) { s->failed_pc=0x0c04e67au; return 0; }
r[4]=r[14];
goto P_0c04e67c;
P_0c04e67c: /* original 55d6, guest PC 0x0c04e67c */
if(!s->budget--) { s->failed_pc=0x0c04e67cu; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c04e67e;
P_0c04e67e: /* original ea00, guest PC 0x0c04e67e */
if(!s->budget--) { s->failed_pc=0x0c04e67eu; return 0; }
r[10]=0x00000000u;
goto P_0c04e680;
P_0c04e680: /* original 6403, guest PC 0x0c04e680 */
if(!s->budget--) { s->failed_pc=0x0c04e680u; return 0; }
r[4]=r[0];
goto P_0c04e682;
P_0c04e682: /* original 6ea3, guest PC 0x0c04e682 */
if(!s->budget--) { s->failed_pc=0x0c04e682u; return 0; }
r[14]=r[10];
goto P_0c04e684;
P_0c04e684: /* original a025, guest PC 0x0c04e684 */
if(!s->budget--) { s->failed_pc=0x0c04e684u; return 0; }
r[6]=0x00000001u;
goto P_0c04e6d2;
P_0c04e686: /* original e601, guest PC 0x0c04e686 */
if(!s->budget--) { s->failed_pc=0x0c04e686u; return 0; }
r[6]=0x00000001u;
if(!vf3_matrix_family(0x0c04e688u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04e688u; return 0; } return 1;
P_0c04e6b4: /* original 53d6, guest PC 0x0c04e6b4 */
if(!s->budget--) { s->failed_pc=0x0c04e6b4u; return 0; }
r[3]=read(ram,r[13]+24,4);
goto P_0c04e6b6;
P_0c04e6b6: /* original 7301, guest PC 0x0c04e6b6 */
if(!s->budget--) { s->failed_pc=0x0c04e6b6u; return 0; }
r[3]+=0x00000001u;
goto P_0c04e6b8;
P_0c04e6b8: /* original 1d36, guest PC 0x0c04e6b8 */
if(!s->budget--) { s->failed_pc=0x0c04e6b8u; return 0; }
write(ram,r[13]+24,r[3],4);
goto P_0c04e6ba;
P_0c04e6ba: /* original 6140, guest PC 0x0c04e6ba */
if(!s->budget--) { s->failed_pc=0x0c04e6bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[1]=tmp;
goto P_0c04e6bc;
P_0c04e6bc: /* original 671c, guest PC 0x0c04e6bc */
if(!s->budget--) { s->failed_pc=0x0c04e6bcu; return 0; }
r[7]=r[1]&255u;
goto P_0c04e6be;
P_0c04e6be: /* original 6073, guest PC 0x0c04e6be */
if(!s->budget--) { s->failed_pc=0x0c04e6beu; return 0; }
r[0]=r[7];
goto P_0c04e6c0;
P_0c04e6c0: /* original 8833, guest PC 0x0c04e6c0 */
if(!s->budget--) { s->failed_pc=0x0c04e6c0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000033u)!=0);
goto P_0c04e6c2;
P_0c04e6c2: /* original 8902, guest PC 0x0c04e6c2 */
if(!s->budget--) { s->failed_pc=0x0c04e6c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e6ca; }
goto P_0c04e6c4;
P_0c04e6c4: /* original 9373, guest PC 0x0c04e6c4 */
if(!s->budget--) { s->failed_pc=0x0c04e6c4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e7aeu,2);
goto P_0c04e6c6;
P_0c04e6c6: /* original 3730, guest PC 0x0c04e6c6 */
if(!s->budget--) { s->failed_pc=0x0c04e6c6u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[3])!=0);
goto P_0c04e6c8;
P_0c04e6c8: /* original 8b01, guest PC 0x0c04e6c8 */
if(!s->budget--) { s->failed_pc=0x0c04e6c8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e6ce; }
goto P_0c04e6ca;
P_0c04e6ca: /* original a006, guest PC 0x0c04e6ca */
if(!s->budget--) { s->failed_pc=0x0c04e6cau; return 0; }
r[14]=r[6];
goto P_0c04e6da;
P_0c04e6cc: /* original 6e63, guest PC 0x0c04e6cc */
if(!s->budget--) { s->failed_pc=0x0c04e6ccu; return 0; }
r[14]=r[6];
goto P_0c04e6ce;
P_0c04e6ce: /* original 7420, guest PC 0x0c04e6ce */
if(!s->budget--) { s->failed_pc=0x0c04e6ceu; return 0; }
r[4]+=0x00000020u;
goto P_0c04e6d0;
P_0c04e6d0: /* original 7501, guest PC 0x0c04e6d0 */
if(!s->budget--) { s->failed_pc=0x0c04e6d0u; return 0; }
r[5]+=0x00000001u;
goto P_0c04e6d2;
P_0c04e6d2: /* original 52d7, guest PC 0x0c04e6d2 */
if(!s->budget--) { s->failed_pc=0x0c04e6d2u; return 0; }
r[2]=read(ram,r[13]+28,4);
goto P_0c04e6d4;
P_0c04e6d4: /* original 532c, guest PC 0x0c04e6d4 */
if(!s->budget--) { s->failed_pc=0x0c04e6d4u; return 0; }
r[3]=read(ram,r[2]+48,4);
goto P_0c04e6d6;
P_0c04e6d6: /* original 3533, guest PC 0x0c04e6d6 */
if(!s->budget--) { s->failed_pc=0x0c04e6d6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[3])!=0);
goto P_0c04e6d8;
P_0c04e6d8: /* original 8bec, guest PC 0x0c04e6d8 */
if(!s->budget--) { s->failed_pc=0x0c04e6d8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e6b4; }
goto P_0c04e6da;
P_0c04e6da: /* original 2ee8, guest PC 0x0c04e6da */
if(!s->budget--) { s->failed_pc=0x0c04e6dau; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c04e6dc;
P_0c04e6dc: /* original 8b02, guest PC 0x0c04e6dc */
if(!s->budget--) { s->failed_pc=0x0c04e6dcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e6e4; }
goto P_0c04e6de;
P_0c04e6de: /* original 9067, guest PC 0x0c04e6de */
if(!s->budget--) { s->failed_pc=0x0c04e6deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e7b0u,2);
goto P_0c04e6e0;
P_0c04e6e0: /* original a00f, guest PC 0x0c04e6e0 */
if(!s->budget--) { s->failed_pc=0x0c04e6e0u; return 0; }
goto P_0c04e702;
P_0c04e6e2: /* original 0009, guest PC 0x0c04e6e2 */
if(!s->budget--) { s->failed_pc=0x0c04e6e2u; return 0; }
goto P_0c04e6e4;
P_0c04e6e4: /* original 6743, guest PC 0x0c04e6e4 */
if(!s->budget--) { s->failed_pc=0x0c04e6e4u; return 0; }
r[7]=r[4];
goto P_0c04e6e6;
P_0c04e6e6: /* original 64b3, guest PC 0x0c04e6e6 */
if(!s->budget--) { s->failed_pc=0x0c04e6e6u; return 0; }
r[4]=r[11];
goto P_0c04e6e8;
P_0c04e6e8: /* original 7704, guest PC 0x0c04e6e8 */
if(!s->budget--) { s->failed_pc=0x0c04e6e8u; return 0; }
r[7]+=0x00000004u;
goto P_0c04e6ea;
P_0c04e6ea: /* original 65a3, guest PC 0x0c04e6ea */
if(!s->budget--) { s->failed_pc=0x0c04e6eau; return 0; }
r[5]=r[10];
goto P_0c04e6ec;
P_0c04e6ec: /* original a004, guest PC 0x0c04e6ec */
if(!s->budget--) { s->failed_pc=0x0c04e6ecu; return 0; }
r[6]=0x0000000cu;
goto P_0c04e6f8;
P_0c04e6ee: /* original e60c, guest PC 0x0c04e6ee */
if(!s->budget--) { s->failed_pc=0x0c04e6eeu; return 0; }
r[6]=0x0000000cu;
goto P_0c04e6f0;
P_0c04e6f0: /* original 6374, guest PC 0x0c04e6f0 */
if(!s->budget--) { s->failed_pc=0x0c04e6f0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]+=1;
r[3]=tmp;
goto P_0c04e6f2;
P_0c04e6f2: /* original 7501, guest PC 0x0c04e6f2 */
if(!s->budget--) { s->failed_pc=0x0c04e6f2u; return 0; }
r[5]+=0x00000001u;
goto P_0c04e6f4;
P_0c04e6f4: /* original 2430, guest PC 0x0c04e6f4 */
if(!s->budget--) { s->failed_pc=0x0c04e6f4u; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04e6f6;
P_0c04e6f6: /* original 7401, guest PC 0x0c04e6f6 */
if(!s->budget--) { s->failed_pc=0x0c04e6f6u; return 0; }
r[4]+=0x00000001u;
goto P_0c04e6f8;
P_0c04e6f8: /* original 3563, guest PC 0x0c04e6f8 */
if(!s->budget--) { s->failed_pc=0x0c04e6f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c04e6fa;
P_0c04e6fa: /* original 8bf9, guest PC 0x0c04e6fa */
if(!s->budget--) { s->failed_pc=0x0c04e6fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e6f0; }
goto P_0c04e6fc;
P_0c04e6fc: /* original 60a3, guest PC 0x0c04e6fc */
if(!s->budget--) { s->failed_pc=0x0c04e6fcu; return 0; }
r[0]=r[10];
goto P_0c04e6fe;
P_0c04e6fe: /* original 80bc, guest PC 0x0c04e6fe */
if(!s->budget--) { s->failed_pc=0x0c04e6feu; return 0; }
write(ram,r[11]+12,r[0],1);
goto P_0c04e700;
P_0c04e700: /* original e000, guest PC 0x0c04e700 */
if(!s->budget--) { s->failed_pc=0x0c04e700u; return 0; }
r[0]=0x00000000u;
goto P_0c04e702;
P_0c04e702: /* original 7f04, guest PC 0x0c04e702 */
if(!s->budget--) { s->failed_pc=0x0c04e702u; return 0; }
r[15]+=0x00000004u;
goto P_0c04e704;
P_0c04e704: /* original 4f16, guest PC 0x0c04e704 */
if(!s->budget--) { s->failed_pc=0x0c04e704u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e706;
P_0c04e706: /* original 4f26, guest PC 0x0c04e706 */
if(!s->budget--) { s->failed_pc=0x0c04e706u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e708;
P_0c04e708: /* original 6af6, guest PC 0x0c04e708 */
if(!s->budget--) { s->failed_pc=0x0c04e708u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04e70a;
P_0c04e70a: /* original 6bf6, guest PC 0x0c04e70a */
if(!s->budget--) { s->failed_pc=0x0c04e70au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04e70c;
P_0c04e70c: /* original 6df6, guest PC 0x0c04e70c */
if(!s->budget--) { s->failed_pc=0x0c04e70cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04e70e;
P_0c04e70e: /* original 000b, guest PC 0x0c04e70e */
if(!s->budget--) { s->failed_pc=0x0c04e70eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04e710: /* original 6ef6, guest PC 0x0c04e710 */
if(!s->budget--) { s->failed_pc=0x0c04e710u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04e712u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
