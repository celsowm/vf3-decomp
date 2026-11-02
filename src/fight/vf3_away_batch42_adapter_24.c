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
int vf3_away_batch42_adapter_24(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0cb4bau: goto P_0c0cb4ba;
case 0x0c0cb4bcu: goto P_0c0cb4bc;
case 0x0c0cb4beu: goto P_0c0cb4be;
case 0x0c0cb4c0u: goto P_0c0cb4c0;
case 0x0c0cb4c2u: goto P_0c0cb4c2;
case 0x0c0cb4c4u: goto P_0c0cb4c4;
case 0x0c0cb4c6u: goto P_0c0cb4c6;
case 0x0c0cb4c8u: goto P_0c0cb4c8;
case 0x0c0cb4cau: goto P_0c0cb4ca;
case 0x0c0cb4ccu: goto P_0c0cb4cc;
case 0x0c0cb4ceu: goto P_0c0cb4ce;
case 0x0c0cb4d0u: goto P_0c0cb4d0;
case 0x0c0cb4d2u: goto P_0c0cb4d2;
case 0x0c0cb4d4u: goto P_0c0cb4d4;
case 0x0c0cb4d6u: goto P_0c0cb4d6;
case 0x0c0cb4d8u: goto P_0c0cb4d8;
case 0x0c0cb4dau: goto P_0c0cb4da;
case 0x0c0cb4dcu: goto P_0c0cb4dc;
case 0x0c0cb4deu: goto P_0c0cb4de;
case 0x0c0cb4e0u: goto P_0c0cb4e0;
case 0x0c0cb4e2u: goto P_0c0cb4e2;
case 0x0c0cb4e4u: goto P_0c0cb4e4;
case 0x0c0cb4e6u: goto P_0c0cb4e6;
case 0x0c0cb4e8u: goto P_0c0cb4e8;
case 0x0c0cb4eau: goto P_0c0cb4ea;
case 0x0c0cb4ecu: goto P_0c0cb4ec;
case 0x0c0cb4eeu: goto P_0c0cb4ee;
case 0x0c0cb4f0u: goto P_0c0cb4f0;
case 0x0c0cb4f2u: goto P_0c0cb4f2;
case 0x0c0cb4f4u: goto P_0c0cb4f4;
case 0x0c0cb4f6u: goto P_0c0cb4f6;
case 0x0c0cb4f8u: goto P_0c0cb4f8;
case 0x0c0cb4fau: goto P_0c0cb4fa;
case 0x0c0cb4fcu: goto P_0c0cb4fc;
case 0x0c0cb4feu: goto P_0c0cb4fe;
case 0x0c0cb500u: goto P_0c0cb500;
case 0x0c0cb502u: goto P_0c0cb502;
case 0x0c0cb504u: goto P_0c0cb504;
case 0x0c0cb506u: goto P_0c0cb506;
case 0x0c0cb508u: goto P_0c0cb508;
case 0x0c0cb50au: goto P_0c0cb50a;
case 0x0c0cb50cu: goto P_0c0cb50c;
case 0x0c0cb50eu: goto P_0c0cb50e;
case 0x0c0cb510u: goto P_0c0cb510;
case 0x0c0cb512u: goto P_0c0cb512;
case 0x0c0cb514u: goto P_0c0cb514;
case 0x0c0cb516u: goto P_0c0cb516;
case 0x0c0cb518u: goto P_0c0cb518;
case 0x0c0cb51au: goto P_0c0cb51a;
case 0x0c0cb51cu: goto P_0c0cb51c;
case 0x0c0cb51eu: goto P_0c0cb51e;
case 0x0c0cb520u: goto P_0c0cb520;
case 0x0c0cb522u: goto P_0c0cb522;
case 0x0c0cb524u: goto P_0c0cb524;
case 0x0c0cb526u: goto P_0c0cb526;
case 0x0c0cb528u: goto P_0c0cb528;
case 0x0c0cb52au: goto P_0c0cb52a;
case 0x0c0cb52cu: goto P_0c0cb52c;
case 0x0c0cb52eu: goto P_0c0cb52e;
case 0x0c0cb530u: goto P_0c0cb530;
case 0x0c0cb532u: goto P_0c0cb532;
case 0x0c0cb534u: goto P_0c0cb534;
case 0x0c0cb536u: goto P_0c0cb536;
case 0x0c0cb538u: goto P_0c0cb538;
case 0x0c0cb53au: goto P_0c0cb53a;
case 0x0c0cb53cu: goto P_0c0cb53c;
case 0x0c0cb53eu: goto P_0c0cb53e;
case 0x0c0cb540u: goto P_0c0cb540;
case 0x0c0cb542u: goto P_0c0cb542;
case 0x0c0cb544u: goto P_0c0cb544;
case 0x0c0cb546u: goto P_0c0cb546;
case 0x0c0cb548u: goto P_0c0cb548;
case 0x0c0cb54au: goto P_0c0cb54a;
case 0x0c0cb54cu: goto P_0c0cb54c;
case 0x0c0cb54eu: goto P_0c0cb54e;
case 0x0c0cb550u: goto P_0c0cb550;
case 0x0c0cb552u: goto P_0c0cb552;
case 0x0c0cb554u: goto P_0c0cb554;
case 0x0c0cb57cu: goto P_0c0cb57c;
case 0x0c0cb57eu: goto P_0c0cb57e;
case 0x0c0cb580u: goto P_0c0cb580;
case 0x0c0cb582u: goto P_0c0cb582;
case 0x0c0cb584u: goto P_0c0cb584;
case 0x0c0cb586u: goto P_0c0cb586;
case 0x0c0cb588u: goto P_0c0cb588;
case 0x0c0cb58au: goto P_0c0cb58a;
case 0x0c0cb58cu: goto P_0c0cb58c;
case 0x0c0cb58eu: goto P_0c0cb58e;
case 0x0c0cb590u: goto P_0c0cb590;
case 0x0c0cb592u: goto P_0c0cb592;
case 0x0c0cb594u: goto P_0c0cb594;
case 0x0c0cb596u: goto P_0c0cb596;
case 0x0c0cb598u: goto P_0c0cb598;
case 0x0c0cb59au: goto P_0c0cb59a;
case 0x0c0cb59cu: goto P_0c0cb59c;
case 0x0c0cb59eu: goto P_0c0cb59e;
case 0x0c0cb5a0u: goto P_0c0cb5a0;
case 0x0c0cb5a2u: goto P_0c0cb5a2;
case 0x0c0cb5a4u: goto P_0c0cb5a4;
case 0x0c0cb5a6u: goto P_0c0cb5a6;
case 0x0c0cb5a8u: goto P_0c0cb5a8;
case 0x0c0cb5aau: goto P_0c0cb5aa;
case 0x0c0cb5acu: goto P_0c0cb5ac;
case 0x0c0cb5aeu: goto P_0c0cb5ae;
case 0x0c0cb5b0u: goto P_0c0cb5b0;
case 0x0c0cb5b2u: goto P_0c0cb5b2;
case 0x0c0cb5b4u: goto P_0c0cb5b4;
case 0x0c0cb5b6u: goto P_0c0cb5b6;
case 0x0c0cb5b8u: goto P_0c0cb5b8;
case 0x0c0cb5bau: goto P_0c0cb5ba;
case 0x0c0cb5bcu: goto P_0c0cb5bc;
case 0x0c0cb5beu: goto P_0c0cb5be;
case 0x0c0cb5c0u: goto P_0c0cb5c0;
case 0x0c0cb5c2u: goto P_0c0cb5c2;
case 0x0c0cb5c4u: goto P_0c0cb5c4;
case 0x0c0cb5c6u: goto P_0c0cb5c6;
case 0x0c0cb5c8u: goto P_0c0cb5c8;
case 0x0c0cb5cau: goto P_0c0cb5ca;
case 0x0c0cb5ccu: goto P_0c0cb5cc;
case 0x0c0cb5ceu: goto P_0c0cb5ce;
case 0x0c0cb5d0u: goto P_0c0cb5d0;
case 0x0c0cb5d2u: goto P_0c0cb5d2;
case 0x0c0cb5d4u: goto P_0c0cb5d4;
case 0x0c0cb5d6u: goto P_0c0cb5d6;
case 0x0c0cb5d8u: goto P_0c0cb5d8;
case 0x0c0cb5dau: goto P_0c0cb5da;
case 0x0c0cb5dcu: goto P_0c0cb5dc;
case 0x0c0cb5deu: goto P_0c0cb5de;
case 0x0c0cb5e0u: goto P_0c0cb5e0;
case 0x0c0cb5e2u: goto P_0c0cb5e2;
case 0x0c0cb5e4u: goto P_0c0cb5e4;
case 0x0c0cb5e6u: goto P_0c0cb5e6;
case 0x0c0cb5e8u: goto P_0c0cb5e8;
case 0x0c0cb5eau: goto P_0c0cb5ea;
case 0x0c0cb5ecu: goto P_0c0cb5ec;
case 0x0c0cb5eeu: goto P_0c0cb5ee;
case 0x0c0cb5f0u: goto P_0c0cb5f0;
case 0x0c0cb5f2u: goto P_0c0cb5f2;
case 0x0c0cb5f4u: goto P_0c0cb5f4;
case 0x0c0cb5f6u: goto P_0c0cb5f6;
case 0x0c0cb5f8u: goto P_0c0cb5f8;
case 0x0c0cb5fau: goto P_0c0cb5fa;
case 0x0c0cb5fcu: goto P_0c0cb5fc;
case 0x0c0cb5feu: goto P_0c0cb5fe;
case 0x0c0cb600u: goto P_0c0cb600;
case 0x0c0cb602u: goto P_0c0cb602;
case 0x0c0cb604u: goto P_0c0cb604;
case 0x0c0cb606u: goto P_0c0cb606;
case 0x0c0cb608u: goto P_0c0cb608;
case 0x0c0cb60au: goto P_0c0cb60a;
case 0x0c0cb60cu: goto P_0c0cb60c;
case 0x0c0cb60eu: goto P_0c0cb60e;
case 0x0c0cb610u: goto P_0c0cb610;
case 0x0c0cb612u: goto P_0c0cb612;
case 0x0c0cb614u: goto P_0c0cb614;
case 0x0c0cb616u: goto P_0c0cb616;
case 0x0c0cb618u: goto P_0c0cb618;
case 0x0c0cb61au: goto P_0c0cb61a;
case 0x0c0cb61cu: goto P_0c0cb61c;
case 0x0c0cb61eu: goto P_0c0cb61e;
case 0x0c0cb620u: goto P_0c0cb620;
case 0x0c0cb622u: goto P_0c0cb622;
case 0x0c0cb624u: goto P_0c0cb624;
case 0x0c0cb626u: goto P_0c0cb626;
case 0x0c0cb628u: goto P_0c0cb628;
case 0x0c0cb62au: goto P_0c0cb62a;
case 0x0c0cb62cu: goto P_0c0cb62c;
case 0x0c0cb62eu: goto P_0c0cb62e;
case 0x0c0cb630u: goto P_0c0cb630;
case 0x0c0cb632u: goto P_0c0cb632;
case 0x0c0cb634u: goto P_0c0cb634;
case 0x0c0cb636u: goto P_0c0cb636;
case 0x0c0cb638u: goto P_0c0cb638;
case 0x0c0cb63au: goto P_0c0cb63a;
case 0x0c0cb63cu: goto P_0c0cb63c;
case 0x0c0cb63eu: goto P_0c0cb63e;
case 0x0c0cb640u: goto P_0c0cb640;
case 0x0c0cb642u: goto P_0c0cb642;
case 0x0c0cb644u: goto P_0c0cb644;
case 0x0c0cb646u: goto P_0c0cb646;
case 0x0c0cb648u: goto P_0c0cb648;
case 0x0c0cb64au: goto P_0c0cb64a;
case 0x0c0cb64cu: goto P_0c0cb64c;
case 0x0c0cb64eu: goto P_0c0cb64e;
case 0x0c0cb650u: goto P_0c0cb650;
case 0x0c0cb652u: goto P_0c0cb652;
case 0x0c0cb654u: goto P_0c0cb654;
case 0x0c0cb656u: goto P_0c0cb656;
case 0x0c0cb658u: goto P_0c0cb658;
case 0x0c0cb65au: goto P_0c0cb65a;
case 0x0c0cb65cu: goto P_0c0cb65c;
case 0x0c0cb65eu: goto P_0c0cb65e;
case 0x0c0cb660u: goto P_0c0cb660;
case 0x0c0cb662u: goto P_0c0cb662;
case 0x0c0cb664u: goto P_0c0cb664;
case 0x0c0cb666u: goto P_0c0cb666;
case 0x0c0cb668u: goto P_0c0cb668;
case 0x0c0cb66au: goto P_0c0cb66a;
case 0x0c0cb66cu: goto P_0c0cb66c;
case 0x0c0cb66eu: goto P_0c0cb66e;
case 0x0c0cb670u: goto P_0c0cb670;
case 0x0c0cb672u: goto P_0c0cb672;
case 0x0c0cb674u: goto P_0c0cb674;
case 0x0c0cb676u: goto P_0c0cb676;
case 0x0c0cb678u: goto P_0c0cb678;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0cb4ba: /* original 2fe6, guest PC 0x0c0cb4ba */
if(!s->budget--) { s->failed_pc=0x0c0cb4bau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cb4bc;
P_0c0cb4bc: /* original e004, guest PC 0x0c0cb4bc */
if(!s->budget--) { s->failed_pc=0x0c0cb4bcu; return 0; }
r[0]=0x00000004u;
goto P_0c0cb4be;
P_0c0cb4be: /* original 2fd6, guest PC 0x0c0cb4be */
if(!s->budget--) { s->failed_pc=0x0c0cb4beu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cb4c0;
P_0c0cb4c0: /* original fffb, guest PC 0x0c0cb4c0 */
if(!s->budget--) { s->failed_pc=0x0c0cb4c0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0cb4c2;
P_0c0cb4c2: /* original ffeb, guest PC 0x0c0cb4c2 */
if(!s->budget--) { s->failed_pc=0x0c0cb4c2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0cb4c4;
P_0c0cb4c4: /* original ffdb, guest PC 0x0c0cb4c4 */
if(!s->budget--) { s->failed_pc=0x0c0cb4c4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0cb4c6;
P_0c0cb4c6: /* original 4f22, guest PC 0x0c0cb4c6 */
if(!s->budget--) { s->failed_pc=0x0c0cb4c6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cb4c8;
P_0c0cb4c8: /* original 7ff8, guest PC 0x0c0cb4c8 */
if(!s->budget--) { s->failed_pc=0x0c0cb4c8u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0cb4ca;
P_0c0cb4ca: /* original ff6a, guest PC 0x0c0cb4ca */
if(!s->budget--) { s->failed_pc=0x0c0cb4cau; return 0; }
vf3_matrix_store(s,ram,6,r[15]);
goto P_0c0cb4cc;
P_0c0cb4cc: /* original ff77, guest PC 0x0c0cb4cc */
if(!s->budget--) { s->failed_pc=0x0c0cb4ccu; return 0; }
vf3_matrix_store(s,ram,7,r[15]+r[0]);
goto P_0c0cb4ce;
P_0c0cb4ce: /* original c724, guest PC 0x0c0cb4ce */
if(!s->budget--) { s->failed_pc=0x0c0cb4ceu; return 0; }
r[0]=code_base|0x000cb560u;
goto P_0c0cb4d0;
P_0c0cb4d0: /* original f308, guest PC 0x0c0cb4d0 */
if(!s->budget--) { s->failed_pc=0x0c0cb4d0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb4d2;
P_0c0cb4d2: /* original fd4c, guest PC 0x0c0cb4d2 */
if(!s->budget--) { s->failed_pc=0x0c0cb4d2u; return 0; }
vf3_matrix_move(s,13,4);
goto P_0c0cb4d4;
P_0c0cb4d4: /* original fd30, guest PC 0x0c0cb4d4 */
if(!s->budget--) { s->failed_pc=0x0c0cb4d4u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'+');
goto P_0c0cb4d6;
P_0c0cb4d6: /* original dd23, guest PC 0x0c0cb4d6 */
if(!s->budget--) { s->failed_pc=0x0c0cb4d6u; return 0; }
r[13]=read(ram,0x0c0cb564u,4);
goto P_0c0cb4d8;
P_0c0cb4d8: /* original fe5c, guest PC 0x0c0cb4d8 */
if(!s->budget--) { s->failed_pc=0x0c0cb4d8u; return 0; }
vf3_matrix_move(s,14,5);
goto P_0c0cb4da;
P_0c0cb4da: /* original f54d, guest PC 0x0c0cb4da */
if(!s->budget--) { s->failed_pc=0x0c0cb4dau; return 0; }
fr[5]^=0x80000000u;
goto P_0c0cb4dc;
P_0c0cb4dc: /* original 4d0b, guest PC 0x0c0cb4dc */
if(!s->budget--) { s->failed_pc=0x0c0cb4dcu; return 0; }
target=r[13];
r[16]=code_base|0x0c0cb4e0u;
vf3_matrix_move(s,4,13);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cb4e0u) { target=s->pc; goto dispatch; }
goto P_0c0cb4e0;
P_0c0cb4de: /* original f4dc, guest PC 0x0c0cb4de */
if(!s->budget--) { s->failed_pc=0x0c0cb4deu; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0cb4e0;
P_0c0cb4e0: /* original ff0c, guest PC 0x0c0cb4e0 */
if(!s->budget--) { s->failed_pc=0x0c0cb4e0u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c0cb4e2;
P_0c0cb4e2: /* original a00e, guest PC 0x0c0cb4e2 */
if(!s->budget--) { s->failed_pc=0x0c0cb4e2u; return 0; }
r[14]=0x00000004u;
goto P_0c0cb502;
P_0c0cb4e4: /* original ee04, guest PC 0x0c0cb4e4 */
if(!s->budget--) { s->failed_pc=0x0c0cb4e4u; return 0; }
r[14]=0x00000004u;
goto P_0c0cb4e6;
P_0c0cb4e6: /* original e004, guest PC 0x0c0cb4e6 */
if(!s->budget--) { s->failed_pc=0x0c0cb4e6u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb4e8;
P_0c0cb4e8: /* original f3f8, guest PC 0x0c0cb4e8 */
if(!s->budget--) { s->failed_pc=0x0c0cb4e8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0cb4ea;
P_0c0cb4ea: /* original f2f6, guest PC 0x0c0cb4ea */
if(!s->budget--) { s->failed_pc=0x0c0cb4eau; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0cb4ec;
P_0c0cb4ec: /* original fd30, guest PC 0x0c0cb4ec */
if(!s->budget--) { s->failed_pc=0x0c0cb4ecu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'+');
goto P_0c0cb4ee;
P_0c0cb4ee: /* original fe20, guest PC 0x0c0cb4ee */
if(!s->budget--) { s->failed_pc=0x0c0cb4eeu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[2],r[18],'+');
goto P_0c0cb4f0;
P_0c0cb4f0: /* original f5ec, guest PC 0x0c0cb4f0 */
if(!s->budget--) { s->failed_pc=0x0c0cb4f0u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0cb4f2;
P_0c0cb4f2: /* original f54d, guest PC 0x0c0cb4f2 */
if(!s->budget--) { s->failed_pc=0x0c0cb4f2u; return 0; }
fr[5]^=0x80000000u;
goto P_0c0cb4f4;
P_0c0cb4f4: /* original 4d0b, guest PC 0x0c0cb4f4 */
if(!s->budget--) { s->failed_pc=0x0c0cb4f4u; return 0; }
target=r[13];
r[16]=code_base|0x0c0cb4f8u;
vf3_matrix_move(s,4,13);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cb4f8u) { target=s->pc; goto dispatch; }
goto P_0c0cb4f8;
P_0c0cb4f6: /* original f4dc, guest PC 0x0c0cb4f6 */
if(!s->budget--) { s->failed_pc=0x0c0cb4f6u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0cb4f8;
P_0c0cb4f8: /* original f40c, guest PC 0x0c0cb4f8 */
if(!s->budget--) { s->failed_pc=0x0c0cb4f8u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0cb4fa;
P_0c0cb4fa: /* original f4f5, guest PC 0x0c0cb4fa */
if(!s->budget--) { s->failed_pc=0x0c0cb4fau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[15]))!=0);
goto P_0c0cb4fc;
P_0c0cb4fc: /* original 8f01, guest PC 0x0c0cb4fc */
if(!s->budget--) { s->failed_pc=0x0c0cb4fcu; return 0; }
cond=r[17]&1u;
r[14]+=0xffffffffu;
if(!cond) { goto P_0c0cb502; }
goto P_0c0cb500;
P_0c0cb4fe: /* original 7eff, guest PC 0x0c0cb4fe */
if(!s->budget--) { s->failed_pc=0x0c0cb4feu; return 0; }
r[14]+=0xffffffffu;
goto P_0c0cb500;
P_0c0cb500: /* original ff4c, guest PC 0x0c0cb500 */
if(!s->budget--) { s->failed_pc=0x0c0cb500u; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c0cb502;
P_0c0cb502: /* original 2ee8, guest PC 0x0c0cb502 */
if(!s->budget--) { s->failed_pc=0x0c0cb502u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0cb504;
P_0c0cb504: /* original 8bef, guest PC 0x0c0cb504 */
if(!s->budget--) { s->failed_pc=0x0c0cb504u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb4e6; }
goto P_0c0cb506;
P_0c0cb506: /* original 7f08, guest PC 0x0c0cb506 */
if(!s->budget--) { s->failed_pc=0x0c0cb506u; return 0; }
r[15]+=0x00000008u;
goto P_0c0cb508;
P_0c0cb508: /* original c717, guest PC 0x0c0cb508 */
if(!s->budget--) { s->failed_pc=0x0c0cb508u; return 0; }
r[0]=code_base|0x000cb568u;
goto P_0c0cb50a;
P_0c0cb50a: /* original 4f26, guest PC 0x0c0cb50a */
if(!s->budget--) { s->failed_pc=0x0c0cb50au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cb50c;
P_0c0cb50c: /* original f308, guest PC 0x0c0cb50c */
if(!s->budget--) { s->failed_pc=0x0c0cb50cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb50e;
P_0c0cb50e: /* original ff30, guest PC 0x0c0cb50e */
if(!s->budget--) { s->failed_pc=0x0c0cb50eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c0cb510;
P_0c0cb510: /* original fdf9, guest PC 0x0c0cb510 */
if(!s->budget--) { s->failed_pc=0x0c0cb510u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cb512;
P_0c0cb512: /* original fef9, guest PC 0x0c0cb512 */
if(!s->budget--) { s->failed_pc=0x0c0cb512u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cb514;
P_0c0cb514: /* original f0fc, guest PC 0x0c0cb514 */
if(!s->budget--) { s->failed_pc=0x0c0cb514u; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c0cb516;
P_0c0cb516: /* original fff9, guest PC 0x0c0cb516 */
if(!s->budget--) { s->failed_pc=0x0c0cb516u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cb518;
P_0c0cb518: /* original 6df6, guest PC 0x0c0cb518 */
if(!s->budget--) { s->failed_pc=0x0c0cb518u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cb51a;
P_0c0cb51a: /* original 000b, guest PC 0x0c0cb51a */
if(!s->budget--) { s->failed_pc=0x0c0cb51au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cb51c: /* original 6ef6, guest PC 0x0c0cb51c */
if(!s->budget--) { s->failed_pc=0x0c0cb51cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0cb51e;
P_0c0cb51e: /* original 2fd6, guest PC 0x0c0cb51e */
if(!s->budget--) { s->failed_pc=0x0c0cb51eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cb520;
P_0c0cb520: /* original 2fc6, guest PC 0x0c0cb520 */
if(!s->budget--) { s->failed_pc=0x0c0cb520u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cb522;
P_0c0cb522: /* original ec06, guest PC 0x0c0cb522 */
if(!s->budget--) { s->failed_pc=0x0c0cb522u; return 0; }
r[12]=0x00000006u;
goto P_0c0cb524;
P_0c0cb524: /* original 2fb6, guest PC 0x0c0cb524 */
if(!s->budget--) { s->failed_pc=0x0c0cb524u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cb526;
P_0c0cb526: /* original 66c3, guest PC 0x0c0cb526 */
if(!s->budget--) { s->failed_pc=0x0c0cb526u; return 0; }
r[6]=r[12];
goto P_0c0cb528;
P_0c0cb528: /* original 2fa6, guest PC 0x0c0cb528 */
if(!s->budget--) { s->failed_pc=0x0c0cb528u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cb52a;
P_0c0cb52a: /* original 2f96, guest PC 0x0c0cb52a */
if(!s->budget--) { s->failed_pc=0x0c0cb52au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cb52c;
P_0c0cb52c: /* original fffb, guest PC 0x0c0cb52c */
if(!s->budget--) { s->failed_pc=0x0c0cb52cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0cb52e;
P_0c0cb52e: /* original ffdb, guest PC 0x0c0cb52e */
if(!s->budget--) { s->failed_pc=0x0c0cb52eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0cb530;
P_0c0cb530: /* original 9012, guest PC 0x0c0cb530 */
if(!s->budget--) { s->failed_pc=0x0c0cb530u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb558u,2);
goto P_0c0cb532;
P_0c0cb532: /* original 4f22, guest PC 0x0c0cb532 */
if(!s->budget--) { s->failed_pc=0x0c0cb532u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cb534;
P_0c0cb534: /* original 094e, guest PC 0x0c0cb534 */
if(!s->budget--) { s->failed_pc=0x0c0cb534u; return 0; }
r[9]=read(ram,r[4]+r[0],4);
goto P_0c0cb536;
P_0c0cb536: /* original c70e, guest PC 0x0c0cb536 */
if(!s->budget--) { s->failed_pc=0x0c0cb536u; return 0; }
r[0]=code_base|0x000cb570u;
goto P_0c0cb538;
P_0c0cb538: /* original f308, guest PC 0x0c0cb538 */
if(!s->budget--) { s->failed_pc=0x0c0cb538u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb53a;
P_0c0cb53a: /* original c70e, guest PC 0x0c0cb53a */
if(!s->budget--) { s->failed_pc=0x0c0cb53au; return 0; }
r[0]=code_base|0x000cb574u;
goto P_0c0cb53c;
P_0c0cb53c: /* original 7ff4, guest PC 0x0c0cb53c */
if(!s->budget--) { s->failed_pc=0x0c0cb53cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0cb53e;
P_0c0cb53e: /* original 6742, guest PC 0x0c0cb53e */
if(!s->budget--) { s->failed_pc=0x0c0cb53eu; return 0; }
tmp=read(ram,r[4],4);
r[7]=tmp;
goto P_0c0cb540;
P_0c0cb540: /* original da0a, guest PC 0x0c0cb540 */
if(!s->budget--) { s->failed_pc=0x0c0cb540u; return 0; }
r[10]=read(ram,0x0c0cb56cu,4);
goto P_0c0cb542;
P_0c0cb542: /* original ff3a, guest PC 0x0c0cb542 */
if(!s->budget--) { s->failed_pc=0x0c0cb542u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0cb544;
P_0c0cb544: /* original f708, guest PC 0x0c0cb544 */
if(!s->budget--) { s->failed_pc=0x0c0cb544u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0cb546;
P_0c0cb546: /* original e004, guest PC 0x0c0cb546 */
if(!s->budget--) { s->failed_pc=0x0c0cb546u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb548;
P_0c0cb548: /* original fb8d, guest PC 0x0c0cb548 */
if(!s->budget--) { s->failed_pc=0x0c0cb548u; return 0; }
fr[11]=0;
goto P_0c0cb54a;
P_0c0cb54a: /* original ffb7, guest PC 0x0c0cb54a */
if(!s->budget--) { s->failed_pc=0x0c0cb54au; return 0; }
vf3_matrix_store(s,ram,11,r[15]+r[0]);
goto P_0c0cb54c;
P_0c0cb54c: /* original e008, guest PC 0x0c0cb54c */
if(!s->budget--) { s->failed_pc=0x0c0cb54cu; return 0; }
r[0]=0x00000008u;
goto P_0c0cb54e;
P_0c0cb54e: /* original ffb7, guest PC 0x0c0cb54e */
if(!s->budget--) { s->failed_pc=0x0c0cb54eu; return 0; }
vf3_matrix_store(s,ram,11,r[15]+r[0]);
goto P_0c0cb550;
P_0c0cb550: /* original dd09, guest PC 0x0c0cb550 */
if(!s->budget--) { s->failed_pc=0x0c0cb550u; return 0; }
r[13]=read(ram,0x0c0cb578u,4);
goto P_0c0cb552;
P_0c0cb552: /* original a06d, guest PC 0x0c0cb552 */
if(!s->budget--) { s->failed_pc=0x0c0cb552u; return 0; }
r[11]=0x00000004u;
goto P_0c0cb630;
P_0c0cb554: /* original eb04, guest PC 0x0c0cb554 */
if(!s->budget--) { s->failed_pc=0x0c0cb554u; return 0; }
r[11]=0x00000004u;
if(!vf3_matrix_family(0x0c0cb556u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0cb556u; return 0; } return 1;
P_0c0cb57c: /* original 65c3, guest PC 0x0c0cb57c */
if(!s->budget--) { s->failed_pc=0x0c0cb57cu; return 0; }
r[5]=r[12];
goto P_0c0cb57e;
P_0c0cb57e: /* original 3568, guest PC 0x0c0cb57e */
if(!s->budget--) { s->failed_pc=0x0c0cb57eu; return 0; }
r[5]-=r[6];
goto P_0c0cb580;
P_0c0cb580: /* original 35ac, guest PC 0x0c0cb580 */
if(!s->budget--) { s->failed_pc=0x0c0cb580u; return 0; }
r[5]+=r[10];
goto P_0c0cb582;
P_0c0cb582: /* original d24d, guest PC 0x0c0cb582 */
if(!s->budget--) { s->failed_pc=0x0c0cb582u; return 0; }
r[2]=read(ram,0x0c0cb6b8u,4);
goto P_0c0cb584;
P_0c0cb584: /* original 6150, guest PC 0x0c0cb584 */
if(!s->budget--) { s->failed_pc=0x0c0cb584u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[1]=tmp;
goto P_0c0cb586;
P_0c0cb586: /* original 420b, guest PC 0x0c0cb586 */
if(!s->budget--) { s->failed_pc=0x0c0cb586u; return 0; }
target=r[2];
r[16]=code_base|0x0c0cb58au;
r[0]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cb58au) { target=s->pc; goto dispatch; }
goto P_0c0cb58a;
P_0c0cb588: /* original 60b3, guest PC 0x0c0cb588 */
if(!s->budget--) { s->failed_pc=0x0c0cb588u; return 0; }
r[0]=r[11];
goto P_0c0cb58a;
P_0c0cb58a: /* original 928e, guest PC 0x0c0cb58a */
if(!s->budget--) { s->failed_pc=0x0c0cb58au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb6aau,2);
goto P_0c0cb58c;
P_0c0cb58c: /* original 6503, guest PC 0x0c0cb58c */
if(!s->budget--) { s->failed_pc=0x0c0cb58cu; return 0; }
r[5]=r[0];
goto P_0c0cb58e;
P_0c0cb58e: /* original 635e, guest PC 0x0c0cb58e */
if(!s->budget--) { s->failed_pc=0x0c0cb58eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c0cb590;
P_0c0cb590: /* original f3f8, guest PC 0x0c0cb590 */
if(!s->budget--) { s->failed_pc=0x0c0cb590u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0cb592;
P_0c0cb592: /* original 324c, guest PC 0x0c0cb592 */
if(!s->budget--) { s->failed_pc=0x0c0cb592u; return 0; }
r[2]+=r[4];
goto P_0c0cb594;
P_0c0cb594: /* original 4308, guest PC 0x0c0cb594 */
if(!s->budget--) { s->failed_pc=0x0c0cb594u; return 0; }
r[3]<<=2;
goto P_0c0cb596;
P_0c0cb596: /* original 332c, guest PC 0x0c0cb596 */
if(!s->budget--) { s->failed_pc=0x0c0cb596u; return 0; }
r[3]+=r[2];
goto P_0c0cb598;
P_0c0cb598: /* original 615e, guest PC 0x0c0cb598 */
if(!s->budget--) { s->failed_pc=0x0c0cb598u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c0cb59a;
P_0c0cb59a: /* original f438, guest PC 0x0c0cb59a */
if(!s->budget--) { s->failed_pc=0x0c0cb59au; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c0cb59c;
P_0c0cb59c: /* original 6313, guest PC 0x0c0cb59c */
if(!s->budget--) { s->failed_pc=0x0c0cb59cu; return 0; }
r[3]=r[1];
goto P_0c0cb59e;
P_0c0cb59e: /* original 4100, guest PC 0x0c0cb59e */
if(!s->budget--) { s->failed_pc=0x0c0cb59eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0cb5a0;
P_0c0cb5a0: /* original 313c, guest PC 0x0c0cb5a0 */
if(!s->budget--) { s->failed_pc=0x0c0cb5a0u; return 0; }
r[1]+=r[3];
goto P_0c0cb5a2;
P_0c0cb5a2: /* original fa4c, guest PC 0x0c0cb5a2 */
if(!s->budget--) { s->failed_pc=0x0c0cb5a2u; return 0; }
vf3_matrix_move(s,10,4);
goto P_0c0cb5a4;
P_0c0cb5a4: /* original 4108, guest PC 0x0c0cb5a4 */
if(!s->budget--) { s->failed_pc=0x0c0cb5a4u; return 0; }
r[1]<<=2;
goto P_0c0cb5a6;
P_0c0cb5a6: /* original 319c, guest PC 0x0c0cb5a6 */
if(!s->budget--) { s->failed_pc=0x0c0cb5a6u; return 0; }
r[1]+=r[9];
goto P_0c0cb5a8;
P_0c0cb5a8: /* original f618, guest PC 0x0c0cb5a8 */
if(!s->budget--) { s->failed_pc=0x0c0cb5a8u; return 0; }
vf3_matrix_load(s,ram,6,r[1]);
goto P_0c0cb5aa;
P_0c0cb5aa: /* original e008, guest PC 0x0c0cb5aa */
if(!s->budget--) { s->failed_pc=0x0c0cb5aau; return 0; }
r[0]=0x00000008u;
goto P_0c0cb5ac;
P_0c0cb5ac: /* original f516, guest PC 0x0c0cb5ac */
if(!s->budget--) { s->failed_pc=0x0c0cb5acu; return 0; }
vf3_matrix_load(s,ram,5,r[1]+r[0]);
goto P_0c0cb5ae;
P_0c0cb5ae: /* original f96c, guest PC 0x0c0cb5ae */
if(!s->budget--) { s->failed_pc=0x0c0cb5aeu; return 0; }
vf3_matrix_move(s,9,6);
goto P_0c0cb5b0;
P_0c0cb5b0: /* original fa60, guest PC 0x0c0cb5b0 */
if(!s->budget--) { s->failed_pc=0x0c0cb5b0u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[6],r[18],'+');
goto P_0c0cb5b2;
P_0c0cb5b2: /* original f64c, guest PC 0x0c0cb5b2 */
if(!s->budget--) { s->failed_pc=0x0c0cb5b2u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c0cb5b4;
P_0c0cb5b4: /* original f650, guest PC 0x0c0cb5b4 */
if(!s->budget--) { s->failed_pc=0x0c0cb5b4u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'+');
goto P_0c0cb5b6;
P_0c0cb5b6: /* original f941, guest PC 0x0c0cb5b6 */
if(!s->budget--) { s->failed_pc=0x0c0cb5b6u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[4],r[18],'-');
goto P_0c0cb5b8;
P_0c0cb5b8: /* original f85c, guest PC 0x0c0cb5b8 */
if(!s->budget--) { s->failed_pc=0x0c0cb5b8u; return 0; }
vf3_matrix_move(s,8,5);
goto P_0c0cb5ba;
P_0c0cb5ba: /* original f841, guest PC 0x0c0cb5ba */
if(!s->budget--) { s->failed_pc=0x0c0cb5bau; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'-');
goto P_0c0cb5bc;
P_0c0cb5bc: /* original f0ac, guest PC 0x0c0cb5bc */
if(!s->budget--) { s->failed_pc=0x0c0cb5bcu; return 0; }
vf3_matrix_move(s,0,10);
goto P_0c0cb5be;
P_0c0cb5be: /* original f031, guest PC 0x0c0cb5be */
if(!s->budget--) { s->failed_pc=0x0c0cb5beu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0cb5c0;
P_0c0cb5c0: /* original ff6c, guest PC 0x0c0cb5c0 */
if(!s->budget--) { s->failed_pc=0x0c0cb5c0u; return 0; }
vf3_matrix_move(s,15,6);
goto P_0c0cb5c2;
P_0c0cb5c2: /* original ff31, guest PC 0x0c0cb5c2 */
if(!s->budget--) { s->failed_pc=0x0c0cb5c2u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'-');
goto P_0c0cb5c4;
P_0c0cb5c4: /* original f19c, guest PC 0x0c0cb5c4 */
if(!s->budget--) { s->failed_pc=0x0c0cb5c4u; return 0; }
vf3_matrix_move(s,1,9);
goto P_0c0cb5c6;
P_0c0cb5c6: /* original f171, guest PC 0x0c0cb5c6 */
if(!s->budget--) { s->failed_pc=0x0c0cb5c6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[7],r[18],'-');
goto P_0c0cb5c8;
P_0c0cb5c8: /* original fd8c, guest PC 0x0c0cb5c8 */
if(!s->budget--) { s->failed_pc=0x0c0cb5c8u; return 0; }
vf3_matrix_move(s,13,8);
goto P_0c0cb5ca;
P_0c0cb5ca: /* original f38d, guest PC 0x0c0cb5ca */
if(!s->budget--) { s->failed_pc=0x0c0cb5cau; return 0; }
fr[3]=0;
goto P_0c0cb5cc;
P_0c0cb5cc: /* original f305, guest PC 0x0c0cb5cc */
if(!s->budget--) { s->failed_pc=0x0c0cb5ccu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[0]))!=0);
goto P_0c0cb5ce;
P_0c0cb5ce: /* original fd71, guest PC 0x0c0cb5ce */
if(!s->budget--) { s->failed_pc=0x0c0cb5ceu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[7],r[18],'-');
goto P_0c0cb5d0;
P_0c0cb5d0: /* original f48d, guest PC 0x0c0cb5d0 */
if(!s->budget--) { s->failed_pc=0x0c0cb5d0u; return 0; }
fr[4]=0;
goto P_0c0cb5d2;
P_0c0cb5d2: /* original f64c, guest PC 0x0c0cb5d2 */
if(!s->budget--) { s->failed_pc=0x0c0cb5d2u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c0cb5d4;
P_0c0cb5d4: /* original 8d03, guest PC 0x0c0cb5d4 */
if(!s->budget--) { s->failed_pc=0x0c0cb5d4u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,4);
if(cond) { goto P_0c0cb5de; }
goto P_0c0cb5d8;
P_0c0cb5d6: /* original f54c, guest PC 0x0c0cb5d6 */
if(!s->budget--) { s->failed_pc=0x0c0cb5d6u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0cb5d8;
P_0c0cb5d8: /* original f40c, guest PC 0x0c0cb5d8 */
if(!s->budget--) { s->failed_pc=0x0c0cb5d8u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0cb5da;
P_0c0cb5da: /* original f50c, guest PC 0x0c0cb5da */
if(!s->budget--) { s->failed_pc=0x0c0cb5dau; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c0cb5dc;
P_0c0cb5dc: /* original f452, guest PC 0x0c0cb5dc */
if(!s->budget--) { s->failed_pc=0x0c0cb5dcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c0cb5de;
P_0c0cb5de: /* original f38d, guest PC 0x0c0cb5de */
if(!s->budget--) { s->failed_pc=0x0c0cb5deu; return 0; }
fr[3]=0;
goto P_0c0cb5e0;
P_0c0cb5e0: /* original f135, guest PC 0x0c0cb5e0 */
if(!s->budget--) { s->failed_pc=0x0c0cb5e0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[3]))!=0);
goto P_0c0cb5e2;
P_0c0cb5e2: /* original 8907, guest PC 0x0c0cb5e2 */
if(!s->budget--) { s->failed_pc=0x0c0cb5e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb5f4; }
goto P_0c0cb5e4;
P_0c0cb5e4: /* original f39c, guest PC 0x0c0cb5e4 */
if(!s->budget--) { s->failed_pc=0x0c0cb5e4u; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c0cb5e6;
P_0c0cb5e6: /* original f97c, guest PC 0x0c0cb5e6 */
if(!s->budget--) { s->failed_pc=0x0c0cb5e6u; return 0; }
vf3_matrix_move(s,9,7);
goto P_0c0cb5e8;
P_0c0cb5e8: /* original f931, guest PC 0x0c0cb5e8 */
if(!s->budget--) { s->failed_pc=0x0c0cb5e8u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'-');
goto P_0c0cb5ea;
P_0c0cb5ea: /* original f24c, guest PC 0x0c0cb5ea */
if(!s->budget--) { s->failed_pc=0x0c0cb5eau; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0cb5ec;
P_0c0cb5ec: /* original f51c, guest PC 0x0c0cb5ec */
if(!s->budget--) { s->failed_pc=0x0c0cb5ecu; return 0; }
vf3_matrix_move(s,5,1);
goto P_0c0cb5ee;
P_0c0cb5ee: /* original f09c, guest PC 0x0c0cb5ee */
if(!s->budget--) { s->failed_pc=0x0c0cb5eeu; return 0; }
vf3_matrix_move(s,0,9);
goto P_0c0cb5f0;
P_0c0cb5f0: /* original f29e, guest PC 0x0c0cb5f0 */
if(!s->budget--) { s->failed_pc=0x0c0cb5f0u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[9],fr[2],r[18]);
goto P_0c0cb5f2;
P_0c0cb5f2: /* original f42c, guest PC 0x0c0cb5f2 */
if(!s->budget--) { s->failed_pc=0x0c0cb5f2u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c0cb5f4;
P_0c0cb5f4: /* original f38d, guest PC 0x0c0cb5f4 */
if(!s->budget--) { s->failed_pc=0x0c0cb5f4u; return 0; }
fr[3]=0;
goto P_0c0cb5f6;
P_0c0cb5f6: /* original f3f5, guest PC 0x0c0cb5f6 */
if(!s->budget--) { s->failed_pc=0x0c0cb5f6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0cb5f8;
P_0c0cb5f8: /* original 8d05, guest PC 0x0c0cb5f8 */
if(!s->budget--) { s->failed_pc=0x0c0cb5f8u; return 0; }
cond=r[17]&1u;
fr[2]=0;
if(cond) { goto P_0c0cb606; }
goto P_0c0cb5fc;
P_0c0cb5fa: /* original f28d, guest PC 0x0c0cb5fa */
if(!s->budget--) { s->failed_pc=0x0c0cb5fau; return 0; }
fr[2]=0;
goto P_0c0cb5fc;
P_0c0cb5fc: /* original f0fc, guest PC 0x0c0cb5fc */
if(!s->budget--) { s->failed_pc=0x0c0cb5fcu; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c0cb5fe;
P_0c0cb5fe: /* original f34c, guest PC 0x0c0cb5fe */
if(!s->budget--) { s->failed_pc=0x0c0cb5feu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0cb600;
P_0c0cb600: /* original f6fc, guest PC 0x0c0cb600 */
if(!s->budget--) { s->failed_pc=0x0c0cb600u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0cb602;
P_0c0cb602: /* original f36e, guest PC 0x0c0cb602 */
if(!s->budget--) { s->failed_pc=0x0c0cb602u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[6],fr[3],r[18]);
goto P_0c0cb604;
P_0c0cb604: /* original f43c, guest PC 0x0c0cb604 */
if(!s->budget--) { s->failed_pc=0x0c0cb604u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0cb606;
P_0c0cb606: /* original fd25, guest PC 0x0c0cb606 */
if(!s->budget--) { s->failed_pc=0x0c0cb606u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[13])>as_float(fr[2]))!=0);
goto P_0c0cb608;
P_0c0cb608: /* original 8907, guest PC 0x0c0cb608 */
if(!s->budget--) { s->failed_pc=0x0c0cb608u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb61a; }
goto P_0c0cb60a;
P_0c0cb60a: /* original f38c, guest PC 0x0c0cb60a */
if(!s->budget--) { s->failed_pc=0x0c0cb60au; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c0cb60c;
P_0c0cb60c: /* original f87c, guest PC 0x0c0cb60c */
if(!s->budget--) { s->failed_pc=0x0c0cb60cu; return 0; }
vf3_matrix_move(s,8,7);
goto P_0c0cb60e;
P_0c0cb60e: /* original f831, guest PC 0x0c0cb60e */
if(!s->budget--) { s->failed_pc=0x0c0cb60eu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'-');
goto P_0c0cb610;
P_0c0cb610: /* original f24c, guest PC 0x0c0cb610 */
if(!s->budget--) { s->failed_pc=0x0c0cb610u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0cb612;
P_0c0cb612: /* original f6dc, guest PC 0x0c0cb612 */
if(!s->budget--) { s->failed_pc=0x0c0cb612u; return 0; }
vf3_matrix_move(s,6,13);
goto P_0c0cb614;
P_0c0cb614: /* original f08c, guest PC 0x0c0cb614 */
if(!s->budget--) { s->failed_pc=0x0c0cb614u; return 0; }
vf3_matrix_move(s,0,8);
goto P_0c0cb616;
P_0c0cb616: /* original f28e, guest PC 0x0c0cb616 */
if(!s->budget--) { s->failed_pc=0x0c0cb616u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c0cb618;
P_0c0cb618: /* original f42c, guest PC 0x0c0cb618 */
if(!s->budget--) { s->failed_pc=0x0c0cb618u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c0cb61a;
P_0c0cb61a: /* original f4b5, guest PC 0x0c0cb61a */
if(!s->budget--) { s->failed_pc=0x0c0cb61au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[11]))!=0);
goto P_0c0cb61c;
P_0c0cb61c: /* original 8f08, guest PC 0x0c0cb61c */
if(!s->budget--) { s->failed_pc=0x0c0cb61cu; return 0; }
cond=r[17]&1u;
r[6]+=0xffffffffu;
if(!cond) { goto P_0c0cb630; }
goto P_0c0cb620;
P_0c0cb61e: /* original 76ff, guest PC 0x0c0cb61e */
if(!s->budget--) { s->failed_pc=0x0c0cb61eu; return 0; }
r[6]+=0xffffffffu;
goto P_0c0cb620;
P_0c0cb620: /* original e008, guest PC 0x0c0cb620 */
if(!s->budget--) { s->failed_pc=0x0c0cb620u; return 0; }
r[0]=0x00000008u;
goto P_0c0cb622;
P_0c0cb622: /* original f54d, guest PC 0x0c0cb622 */
if(!s->budget--) { s->failed_pc=0x0c0cb622u; return 0; }
fr[5]^=0x80000000u;
goto P_0c0cb624;
P_0c0cb624: /* original ff57, guest PC 0x0c0cb624 */
if(!s->budget--) { s->failed_pc=0x0c0cb624u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0cb626;
P_0c0cb626: /* original e004, guest PC 0x0c0cb626 */
if(!s->budget--) { s->failed_pc=0x0c0cb626u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb628;
P_0c0cb628: /* original f64d, guest PC 0x0c0cb628 */
if(!s->budget--) { s->failed_pc=0x0c0cb628u; return 0; }
fr[6]^=0x80000000u;
goto P_0c0cb62a;
P_0c0cb62a: /* original 27db, guest PC 0x0c0cb62a */
if(!s->budget--) { s->failed_pc=0x0c0cb62au; return 0; }
r[7]|=r[13];
goto P_0c0cb62c;
P_0c0cb62c: /* original ff67, guest PC 0x0c0cb62c */
if(!s->budget--) { s->failed_pc=0x0c0cb62cu; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c0cb62e;
P_0c0cb62e: /* original fb4c, guest PC 0x0c0cb62e */
if(!s->budget--) { s->failed_pc=0x0c0cb62eu; return 0; }
vf3_matrix_move(s,11,4);
goto P_0c0cb630;
P_0c0cb630: /* original 2668, guest PC 0x0c0cb630 */
if(!s->budget--) { s->failed_pc=0x0c0cb630u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0cb632;
P_0c0cb632: /* original 8ba3, guest PC 0x0c0cb632 */
if(!s->budget--) { s->failed_pc=0x0c0cb632u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb57c; }
goto P_0c0cb634;
P_0c0cb634: /* original e008, guest PC 0x0c0cb634 */
if(!s->budget--) { s->failed_pc=0x0c0cb634u; return 0; }
r[0]=0x00000008u;
goto P_0c0cb636;
P_0c0cb636: /* original f3f6, guest PC 0x0c0cb636 */
if(!s->budget--) { s->failed_pc=0x0c0cb636u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb638;
P_0c0cb638: /* original 9038, guest PC 0x0c0cb638 */
if(!s->budget--) { s->failed_pc=0x0c0cb638u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb6acu,2);
goto P_0c0cb63a;
P_0c0cb63a: /* original f437, guest PC 0x0c0cb63a */
if(!s->budget--) { s->failed_pc=0x0c0cb63au; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0cb63c;
P_0c0cb63c: /* original e004, guest PC 0x0c0cb63c */
if(!s->budget--) { s->failed_pc=0x0c0cb63cu; return 0; }
r[0]=0x00000004u;
goto P_0c0cb63e;
P_0c0cb63e: /* original f3f6, guest PC 0x0c0cb63e */
if(!s->budget--) { s->failed_pc=0x0c0cb63eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb640;
P_0c0cb640: /* original 7f0c, guest PC 0x0c0cb640 */
if(!s->budget--) { s->failed_pc=0x0c0cb640u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0cb642;
P_0c0cb642: /* original 4f26, guest PC 0x0c0cb642 */
if(!s->budget--) { s->failed_pc=0x0c0cb642u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cb644;
P_0c0cb644: /* original 9033, guest PC 0x0c0cb644 */
if(!s->budget--) { s->failed_pc=0x0c0cb644u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb6aeu,2);
goto P_0c0cb646;
P_0c0cb646: /* original f437, guest PC 0x0c0cb646 */
if(!s->budget--) { s->failed_pc=0x0c0cb646u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0cb648;
P_0c0cb648: /* original 2472, guest PC 0x0c0cb648 */
if(!s->budget--) { s->failed_pc=0x0c0cb648u; return 0; }
write(ram,r[4],r[7],4);
goto P_0c0cb64a;
P_0c0cb64a: /* original fdf9, guest PC 0x0c0cb64a */
if(!s->budget--) { s->failed_pc=0x0c0cb64au; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cb64c;
P_0c0cb64c: /* original fff9, guest PC 0x0c0cb64c */
if(!s->budget--) { s->failed_pc=0x0c0cb64cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cb64e;
P_0c0cb64e: /* original 69f6, guest PC 0x0c0cb64e */
if(!s->budget--) { s->failed_pc=0x0c0cb64eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0cb650;
P_0c0cb650: /* original 6af6, guest PC 0x0c0cb650 */
if(!s->budget--) { s->failed_pc=0x0c0cb650u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0cb652;
P_0c0cb652: /* original 6bf6, guest PC 0x0c0cb652 */
if(!s->budget--) { s->failed_pc=0x0c0cb652u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0cb654;
P_0c0cb654: /* original 6cf6, guest PC 0x0c0cb654 */
if(!s->budget--) { s->failed_pc=0x0c0cb654u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cb656;
P_0c0cb656: /* original 000b, guest PC 0x0c0cb656 */
if(!s->budget--) { s->failed_pc=0x0c0cb656u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cb658: /* original 6df6, guest PC 0x0c0cb658 */
if(!s->budget--) { s->failed_pc=0x0c0cb658u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cb65a;
P_0c0cb65a: /* original 4f22, guest PC 0x0c0cb65a */
if(!s->budget--) { s->failed_pc=0x0c0cb65au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cb65c;
P_0c0cb65c: /* original 7ffc, guest PC 0x0c0cb65c */
if(!s->budget--) { s->failed_pc=0x0c0cb65cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0cb65e;
P_0c0cb65e: /* original 2f52, guest PC 0x0c0cb65e */
if(!s->budget--) { s->failed_pc=0x0c0cb65eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0cb660;
P_0c0cb660: /* original d117, guest PC 0x0c0cb660 */
if(!s->budget--) { s->failed_pc=0x0c0cb660u; return 0; }
r[1]=read(ram,0x0c0cb6c0u,4);
goto P_0c0cb662;
P_0c0cb662: /* original d316, guest PC 0x0c0cb662 */
if(!s->budget--) { s->failed_pc=0x0c0cb662u; return 0; }
r[3]=read(ram,0x0c0cb6bcu,4);
goto P_0c0cb664;
P_0c0cb664: /* original 6212, guest PC 0x0c0cb664 */
if(!s->budget--) { s->failed_pc=0x0c0cb664u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0cb666;
P_0c0cb666: /* original 2238, guest PC 0x0c0cb666 */
if(!s->budget--) { s->failed_pc=0x0c0cb666u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cb668;
P_0c0cb668: /* original 8b03, guest PC 0x0c0cb668 */
if(!s->budget--) { s->failed_pc=0x0c0cb668u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb672; }
goto P_0c0cb66a;
P_0c0cb66a: /* original b006, guest PC 0x0c0cb66a */
if(!s->budget--) { s->failed_pc=0x0c0cb66au; return 0; }
target=code_base|0x0c0cb67au; r[16]=code_base|0x0c0cb66eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cb66eu) { target=s->pc; goto dispatch; }
goto P_0c0cb66e;
P_0c0cb66c: /* original 0009, guest PC 0x0c0cb66c */
if(!s->budget--) { s->failed_pc=0x0c0cb66cu; return 0; }
goto P_0c0cb66e;
P_0c0cb66e: /* original b004, guest PC 0x0c0cb66e */
if(!s->budget--) { s->failed_pc=0x0c0cb66eu; return 0; }
target=code_base|0x0c0cb67au; r[16]=code_base|0x0c0cb672u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cb672u) { target=s->pc; goto dispatch; }
goto P_0c0cb672;
P_0c0cb670: /* original 64f2, guest PC 0x0c0cb670 */
if(!s->budget--) { s->failed_pc=0x0c0cb670u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0cb672;
P_0c0cb672: /* original 7f04, guest PC 0x0c0cb672 */
if(!s->budget--) { s->failed_pc=0x0c0cb672u; return 0; }
r[15]+=0x00000004u;
goto P_0c0cb674;
P_0c0cb674: /* original 4f26, guest PC 0x0c0cb674 */
if(!s->budget--) { s->failed_pc=0x0c0cb674u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cb676;
P_0c0cb676: /* original 000b, guest PC 0x0c0cb676 */
if(!s->budget--) { s->failed_pc=0x0c0cb676u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0cb678: /* original 0009, guest PC 0x0c0cb678 */
if(!s->budget--) { s->failed_pc=0x0c0cb678u; return 0; }
return vf3_matrix_family(0x0c0cb67au,s,ram);
unsupported: s->failed_pc=target; return 0;
}
