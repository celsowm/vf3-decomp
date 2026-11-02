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
int vf3_away_batch57_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08a4ccu: goto P_0c08a4cc;
case 0x0c08a4ceu: goto P_0c08a4ce;
case 0x0c08a4d0u: goto P_0c08a4d0;
case 0x0c08a4d2u: goto P_0c08a4d2;
case 0x0c08a4d4u: goto P_0c08a4d4;
case 0x0c08a4d6u: goto P_0c08a4d6;
case 0x0c08a4d8u: goto P_0c08a4d8;
case 0x0c08a4dau: goto P_0c08a4da;
case 0x0c08a4dcu: goto P_0c08a4dc;
case 0x0c08a4deu: goto P_0c08a4de;
case 0x0c08a4e0u: goto P_0c08a4e0;
case 0x0c08a4e2u: goto P_0c08a4e2;
case 0x0c08a4e4u: goto P_0c08a4e4;
case 0x0c08a4e6u: goto P_0c08a4e6;
case 0x0c08a4e8u: goto P_0c08a4e8;
case 0x0c08a4eau: goto P_0c08a4ea;
case 0x0c08a4ecu: goto P_0c08a4ec;
case 0x0c08a4eeu: goto P_0c08a4ee;
case 0x0c08a4f0u: goto P_0c08a4f0;
case 0x0c08a4f2u: goto P_0c08a4f2;
case 0x0c08a4f4u: goto P_0c08a4f4;
case 0x0c08a4f6u: goto P_0c08a4f6;
case 0x0c08a4f8u: goto P_0c08a4f8;
case 0x0c08a4fau: goto P_0c08a4fa;
case 0x0c08a4fcu: goto P_0c08a4fc;
case 0x0c08a4feu: goto P_0c08a4fe;
case 0x0c08a500u: goto P_0c08a500;
case 0x0c08a502u: goto P_0c08a502;
case 0x0c08a504u: goto P_0c08a504;
case 0x0c08a506u: goto P_0c08a506;
case 0x0c08a508u: goto P_0c08a508;
case 0x0c08a50au: goto P_0c08a50a;
case 0x0c08a50cu: goto P_0c08a50c;
case 0x0c08a50eu: goto P_0c08a50e;
case 0x0c08a510u: goto P_0c08a510;
case 0x0c08a512u: goto P_0c08a512;
case 0x0c08a514u: goto P_0c08a514;
case 0x0c08a516u: goto P_0c08a516;
case 0x0c08a518u: goto P_0c08a518;
case 0x0c08a51au: goto P_0c08a51a;
case 0x0c08a51cu: goto P_0c08a51c;
case 0x0c08a51eu: goto P_0c08a51e;
case 0x0c08a520u: goto P_0c08a520;
case 0x0c08a522u: goto P_0c08a522;
case 0x0c08a524u: goto P_0c08a524;
case 0x0c08a526u: goto P_0c08a526;
case 0x0c08a528u: goto P_0c08a528;
case 0x0c08a52au: goto P_0c08a52a;
case 0x0c08a52cu: goto P_0c08a52c;
case 0x0c08a52eu: goto P_0c08a52e;
case 0x0c08a530u: goto P_0c08a530;
case 0x0c08a532u: goto P_0c08a532;
case 0x0c08a534u: goto P_0c08a534;
case 0x0c08a536u: goto P_0c08a536;
case 0x0c08a538u: goto P_0c08a538;
case 0x0c08a53au: goto P_0c08a53a;
case 0x0c08a53cu: goto P_0c08a53c;
case 0x0c08a53eu: goto P_0c08a53e;
case 0x0c08a540u: goto P_0c08a540;
case 0x0c08a542u: goto P_0c08a542;
case 0x0c08a544u: goto P_0c08a544;
case 0x0c08a546u: goto P_0c08a546;
case 0x0c08a548u: goto P_0c08a548;
case 0x0c08a54au: goto P_0c08a54a;
case 0x0c08a54cu: goto P_0c08a54c;
case 0x0c08a54eu: goto P_0c08a54e;
case 0x0c08a550u: goto P_0c08a550;
case 0x0c08a552u: goto P_0c08a552;
case 0x0c08a554u: goto P_0c08a554;
case 0x0c08a556u: goto P_0c08a556;
case 0x0c08a558u: goto P_0c08a558;
case 0x0c08a55au: goto P_0c08a55a;
case 0x0c08a55cu: goto P_0c08a55c;
case 0x0c08a55eu: goto P_0c08a55e;
case 0x0c08a560u: goto P_0c08a560;
case 0x0c08a562u: goto P_0c08a562;
case 0x0c08a564u: goto P_0c08a564;
case 0x0c08a566u: goto P_0c08a566;
case 0x0c08a568u: goto P_0c08a568;
case 0x0c08a56au: goto P_0c08a56a;
case 0x0c08a56cu: goto P_0c08a56c;
case 0x0c08a56eu: goto P_0c08a56e;
case 0x0c08a570u: goto P_0c08a570;
case 0x0c08a572u: goto P_0c08a572;
case 0x0c08a574u: goto P_0c08a574;
case 0x0c08a576u: goto P_0c08a576;
case 0x0c08a578u: goto P_0c08a578;
case 0x0c08a57au: goto P_0c08a57a;
case 0x0c08a57cu: goto P_0c08a57c;
case 0x0c08a57eu: goto P_0c08a57e;
case 0x0c08a580u: goto P_0c08a580;
case 0x0c08a582u: goto P_0c08a582;
case 0x0c08a584u: goto P_0c08a584;
case 0x0c08a586u: goto P_0c08a586;
case 0x0c08a588u: goto P_0c08a588;
case 0x0c08a58au: goto P_0c08a58a;
case 0x0c08a58cu: goto P_0c08a58c;
case 0x0c08a58eu: goto P_0c08a58e;
case 0x0c08a590u: goto P_0c08a590;
case 0x0c08a592u: goto P_0c08a592;
case 0x0c08a594u: goto P_0c08a594;
case 0x0c08a596u: goto P_0c08a596;
case 0x0c08a598u: goto P_0c08a598;
case 0x0c08a59au: goto P_0c08a59a;
case 0x0c08a59cu: goto P_0c08a59c;
case 0x0c08a59eu: goto P_0c08a59e;
case 0x0c08a5a0u: goto P_0c08a5a0;
case 0x0c08a5a2u: goto P_0c08a5a2;
case 0x0c08a5a4u: goto P_0c08a5a4;
case 0x0c08a5a6u: goto P_0c08a5a6;
case 0x0c08a5a8u: goto P_0c08a5a8;
case 0x0c08a5aau: goto P_0c08a5aa;
case 0x0c08a5acu: goto P_0c08a5ac;
case 0x0c08a5aeu: goto P_0c08a5ae;
case 0x0c08a5b0u: goto P_0c08a5b0;
case 0x0c08a5b2u: goto P_0c08a5b2;
case 0x0c08a5b4u: goto P_0c08a5b4;
case 0x0c08a5b6u: goto P_0c08a5b6;
case 0x0c08a5b8u: goto P_0c08a5b8;
case 0x0c08a5bau: goto P_0c08a5ba;
case 0x0c08a5bcu: goto P_0c08a5bc;
case 0x0c08a5beu: goto P_0c08a5be;
case 0x0c08a5c0u: goto P_0c08a5c0;
case 0x0c08a5c2u: goto P_0c08a5c2;
case 0x0c08a5c4u: goto P_0c08a5c4;
case 0x0c08a5c6u: goto P_0c08a5c6;
case 0x0c08a5c8u: goto P_0c08a5c8;
case 0x0c08a5cau: goto P_0c08a5ca;
case 0x0c08a5ccu: goto P_0c08a5cc;
case 0x0c08a5ceu: goto P_0c08a5ce;
case 0x0c08a5d0u: goto P_0c08a5d0;
case 0x0c08a5d2u: goto P_0c08a5d2;
case 0x0c08a5d4u: goto P_0c08a5d4;
case 0x0c08a5d6u: goto P_0c08a5d6;
case 0x0c08a6ecu: goto P_0c08a6ec;
case 0x0c08a6eeu: goto P_0c08a6ee;
case 0x0c08a6f0u: goto P_0c08a6f0;
case 0x0c08a6f2u: goto P_0c08a6f2;
case 0x0c08a6f4u: goto P_0c08a6f4;
case 0x0c08a6f6u: goto P_0c08a6f6;
case 0x0c08a6f8u: goto P_0c08a6f8;
case 0x0c08a6fau: goto P_0c08a6fa;
case 0x0c08a6fcu: goto P_0c08a6fc;
case 0x0c08a6feu: goto P_0c08a6fe;
case 0x0c08a700u: goto P_0c08a700;
case 0x0c08a702u: goto P_0c08a702;
case 0x0c08a704u: goto P_0c08a704;
case 0x0c08a706u: goto P_0c08a706;
case 0x0c08a708u: goto P_0c08a708;
case 0x0c08a70au: goto P_0c08a70a;
case 0x0c08a70cu: goto P_0c08a70c;
case 0x0c08a70eu: goto P_0c08a70e;
case 0x0c08a710u: goto P_0c08a710;
case 0x0c08a712u: goto P_0c08a712;
case 0x0c08a714u: goto P_0c08a714;
case 0x0c08a716u: goto P_0c08a716;
case 0x0c08a718u: goto P_0c08a718;
case 0x0c08a71au: goto P_0c08a71a;
case 0x0c08a71cu: goto P_0c08a71c;
case 0x0c08a71eu: goto P_0c08a71e;
case 0x0c08a720u: goto P_0c08a720;
case 0x0c08a722u: goto P_0c08a722;
case 0x0c08a724u: goto P_0c08a724;
case 0x0c08a726u: goto P_0c08a726;
case 0x0c08a728u: goto P_0c08a728;
case 0x0c08a72au: goto P_0c08a72a;
case 0x0c08a72cu: goto P_0c08a72c;
case 0x0c08a72eu: goto P_0c08a72e;
case 0x0c08a730u: goto P_0c08a730;
case 0x0c08a732u: goto P_0c08a732;
case 0x0c08a734u: goto P_0c08a734;
case 0x0c08a736u: goto P_0c08a736;
case 0x0c08a738u: goto P_0c08a738;
case 0x0c08a73au: goto P_0c08a73a;
case 0x0c08a73cu: goto P_0c08a73c;
case 0x0c08a73eu: goto P_0c08a73e;
case 0x0c08a740u: goto P_0c08a740;
case 0x0c08a742u: goto P_0c08a742;
case 0x0c08a744u: goto P_0c08a744;
case 0x0c08a746u: goto P_0c08a746;
case 0x0c08a748u: goto P_0c08a748;
case 0x0c08a74au: goto P_0c08a74a;
case 0x0c08a74cu: goto P_0c08a74c;
case 0x0c08a74eu: goto P_0c08a74e;
case 0x0c08a750u: goto P_0c08a750;
case 0x0c08a752u: goto P_0c08a752;
case 0x0c08a754u: goto P_0c08a754;
case 0x0c08a756u: goto P_0c08a756;
case 0x0c08a758u: goto P_0c08a758;
case 0x0c08a75au: goto P_0c08a75a;
case 0x0c08a75cu: goto P_0c08a75c;
case 0x0c08a75eu: goto P_0c08a75e;
case 0x0c08a760u: goto P_0c08a760;
case 0x0c08a762u: goto P_0c08a762;
case 0x0c08a764u: goto P_0c08a764;
case 0x0c08a766u: goto P_0c08a766;
case 0x0c08a768u: goto P_0c08a768;
case 0x0c08a76au: goto P_0c08a76a;
case 0x0c08a76cu: goto P_0c08a76c;
case 0x0c08a76eu: goto P_0c08a76e;
case 0x0c08a770u: goto P_0c08a770;
case 0x0c08a772u: goto P_0c08a772;
case 0x0c08a774u: goto P_0c08a774;
case 0x0c08a776u: goto P_0c08a776;
case 0x0c08a778u: goto P_0c08a778;
case 0x0c08a77au: goto P_0c08a77a;
case 0x0c08a77cu: goto P_0c08a77c;
case 0x0c08a77eu: goto P_0c08a77e;
case 0x0c08a780u: goto P_0c08a780;
case 0x0c08a782u: goto P_0c08a782;
case 0x0c08a784u: goto P_0c08a784;
case 0x0c08a786u: goto P_0c08a786;
case 0x0c08a788u: goto P_0c08a788;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08a4cc: /* original 2fe6, guest PC 0x0c08a4cc */
if(!s->budget--) { s->failed_pc=0x0c08a4ccu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a4ce;
P_0c08a4ce: /* original 6e43, guest PC 0x0c08a4ce */
if(!s->budget--) { s->failed_pc=0x0c08a4ceu; return 0; }
r[14]=r[4];
goto P_0c08a4d0;
P_0c08a4d0: /* original 2fd6, guest PC 0x0c08a4d0 */
if(!s->budget--) { s->failed_pc=0x0c08a4d0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a4d2;
P_0c08a4d2: /* original 2fc6, guest PC 0x0c08a4d2 */
if(!s->budget--) { s->failed_pc=0x0c08a4d2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a4d4;
P_0c08a4d4: /* original fffb, guest PC 0x0c08a4d4 */
if(!s->budget--) { s->failed_pc=0x0c08a4d4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08a4d6;
P_0c08a4d6: /* original 907f, guest PC 0x0c08a4d6 */
if(!s->budget--) { s->failed_pc=0x0c08a4d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a5d8u,2);
goto P_0c08a4d8;
P_0c08a4d8: /* original 4f22, guest PC 0x0c08a4d8 */
if(!s->budget--) { s->failed_pc=0x0c08a4d8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08a4da;
P_0c08a4da: /* original f3e6, guest PC 0x0c08a4da */
if(!s->budget--) { s->failed_pc=0x0c08a4dau; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08a4dc;
P_0c08a4dc: /* original 7008, guest PC 0x0c08a4dc */
if(!s->budget--) { s->failed_pc=0x0c08a4dcu; return 0; }
r[0]+=0x00000008u;
goto P_0c08a4de;
P_0c08a4de: /* original f33d, guest PC 0x0c08a4de */
if(!s->budget--) { s->failed_pc=0x0c08a4deu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c08a4e0;
P_0c08a4e0: /* original f3e6, guest PC 0x0c08a4e0 */
if(!s->budget--) { s->failed_pc=0x0c08a4e0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08a4e2;
P_0c08a4e2: /* original 70fc, guest PC 0x0c08a4e2 */
if(!s->budget--) { s->failed_pc=0x0c08a4e2u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08a4e4;
P_0c08a4e4: /* original ffe6, guest PC 0x0c08a4e4 */
if(!s->budget--) { s->failed_pc=0x0c08a4e4u; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c08a4e6;
P_0c08a4e6: /* original e040, guest PC 0x0c08a4e6 */
if(!s->budget--) { s->failed_pc=0x0c08a4e6u; return 0; }
r[0]=0x00000040u;
goto P_0c08a4e8;
P_0c08a4e8: /* original 7ff4, guest PC 0x0c08a4e8 */
if(!s->budget--) { s->failed_pc=0x0c08a4e8u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c08a4ea;
P_0c08a4ea: /* original 0d5a, guest PC 0x0c08a4ea */
if(!s->budget--) { s->failed_pc=0x0c08a4eau; return 0; }
r[13]=r[53];
goto P_0c08a4ec;
P_0c08a4ec: /* original f33d, guest PC 0x0c08a4ec */
if(!s->budget--) { s->failed_pc=0x0c08a4ecu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c08a4ee;
P_0c08a4ee: /* original f3e6, guest PC 0x0c08a4ee */
if(!s->budget--) { s->failed_pc=0x0c08a4eeu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08a4f0;
P_0c08a4f0: /* original e044, guest PC 0x0c08a4f0 */
if(!s->budget--) { s->failed_pc=0x0c08a4f0u; return 0; }
r[0]=0x00000044u;
goto P_0c08a4f2;
P_0c08a4f2: /* original ff3a, guest PC 0x0c08a4f2 */
if(!s->budget--) { s->failed_pc=0x0c08a4f2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08a4f4;
P_0c08a4f4: /* original f3e6, guest PC 0x0c08a4f4 */
if(!s->budget--) { s->failed_pc=0x0c08a4f4u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08a4f6;
P_0c08a4f6: /* original e004, guest PC 0x0c08a4f6 */
if(!s->budget--) { s->failed_pc=0x0c08a4f6u; return 0; }
r[0]=0x00000004u;
goto P_0c08a4f8;
P_0c08a4f8: /* original ff37, guest PC 0x0c08a4f8 */
if(!s->budget--) { s->failed_pc=0x0c08a4f8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a4fa;
P_0c08a4fa: /* original e048, guest PC 0x0c08a4fa */
if(!s->budget--) { s->failed_pc=0x0c08a4fau; return 0; }
r[0]=0x00000048u;
goto P_0c08a4fc;
P_0c08a4fc: /* original f3e6, guest PC 0x0c08a4fc */
if(!s->budget--) { s->failed_pc=0x0c08a4fcu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08a4fe;
P_0c08a4fe: /* original e008, guest PC 0x0c08a4fe */
if(!s->budget--) { s->failed_pc=0x0c08a4feu; return 0; }
r[0]=0x00000008u;
goto P_0c08a500;
P_0c08a500: /* original ff37, guest PC 0x0c08a500 */
if(!s->budget--) { s->failed_pc=0x0c08a500u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a502;
P_0c08a502: /* original 906a, guest PC 0x0c08a502 */
if(!s->budget--) { s->failed_pc=0x0c08a502u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a5dau,2);
goto P_0c08a504;
P_0c08a504: /* original 03ed, guest PC 0x0c08a504 */
if(!s->budget--) { s->failed_pc=0x0c08a504u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08a506;
P_0c08a506: /* original 2338, guest PC 0x0c08a506 */
if(!s->budget--) { s->failed_pc=0x0c08a506u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c08a508;
P_0c08a508: /* original 8f09, guest PC 0x0c08a508 */
if(!s->budget--) { s->failed_pc=0x0c08a508u; return 0; }
cond=r[17]&1u;
r[12]=r[53];
if(!cond) { goto P_0c08a51e; }
goto P_0c08a50c;
P_0c08a50a: /* original 0c5a, guest PC 0x0c08a50a */
if(!s->budget--) { s->failed_pc=0x0c08a50au; return 0; }
r[12]=r[53];
goto P_0c08a50c;
P_0c08a50c: /* original c734, guest PC 0x0c08a50c */
if(!s->budget--) { s->failed_pc=0x0c08a50cu; return 0; }
r[0]=code_base|0x0008a5e0u;
goto P_0c08a50e;
P_0c08a50e: /* original f308, guest PC 0x0c08a50e */
if(!s->budget--) { s->failed_pc=0x0c08a50eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08a510;
P_0c08a510: /* original e004, guest PC 0x0c08a510 */
if(!s->budget--) { s->failed_pc=0x0c08a510u; return 0; }
r[0]=0x00000004u;
goto P_0c08a512;
P_0c08a512: /* original f2f6, guest PC 0x0c08a512 */
if(!s->budget--) { s->failed_pc=0x0c08a512u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c08a514;
P_0c08a514: /* original e004, guest PC 0x0c08a514 */
if(!s->budget--) { s->failed_pc=0x0c08a514u; return 0; }
r[0]=0x00000004u;
goto P_0c08a516;
P_0c08a516: /* original ff32, guest PC 0x0c08a516 */
if(!s->budget--) { s->failed_pc=0x0c08a516u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c08a518;
P_0c08a518: /* original f2f1, guest PC 0x0c08a518 */
if(!s->budget--) { s->failed_pc=0x0c08a518u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[15],r[18],'-');
goto P_0c08a51a;
P_0c08a51a: /* original a039, guest PC 0x0c08a51a */
if(!s->budget--) { s->failed_pc=0x0c08a51au; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c08a590;
P_0c08a51c: /* original ff27, guest PC 0x0c08a51c */
if(!s->budget--) { s->failed_pc=0x0c08a51cu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c08a51e;
P_0c08a51e: /* original 02ed, guest PC 0x0c08a51e */
if(!s->budget--) { s->failed_pc=0x0c08a51eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08a520;
P_0c08a520: /* original e30e, guest PC 0x0c08a520 */
if(!s->budget--) { s->failed_pc=0x0c08a520u; return 0; }
r[3]=0x0000000eu;
goto P_0c08a522;
P_0c08a522: /* original 3233, guest PC 0x0c08a522 */
if(!s->budget--) { s->failed_pc=0x0c08a522u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c08a524;
P_0c08a524: /* original 891c, guest PC 0x0c08a524 */
if(!s->budget--) { s->failed_pc=0x0c08a524u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08a560; }
goto P_0c08a526;
P_0c08a526: /* original c72f, guest PC 0x0c08a526 */
if(!s->budget--) { s->failed_pc=0x0c08a526u; return 0; }
r[0]=code_base|0x0008a5e4u;
goto P_0c08a528;
P_0c08a528: /* original f308, guest PC 0x0c08a528 */
if(!s->budget--) { s->failed_pc=0x0c08a528u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08a52a;
P_0c08a52a: /* original e004, guest PC 0x0c08a52a */
if(!s->budget--) { s->failed_pc=0x0c08a52au; return 0; }
r[0]=0x00000004u;
goto P_0c08a52c;
P_0c08a52c: /* original f2f6, guest PC 0x0c08a52c */
if(!s->budget--) { s->failed_pc=0x0c08a52cu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c08a52e;
P_0c08a52e: /* original e004, guest PC 0x0c08a52e */
if(!s->budget--) { s->failed_pc=0x0c08a52eu; return 0; }
r[0]=0x00000004u;
goto P_0c08a530;
P_0c08a530: /* original ff32, guest PC 0x0c08a530 */
if(!s->budget--) { s->failed_pc=0x0c08a530u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c08a532;
P_0c08a532: /* original 7c20, guest PC 0x0c08a532 */
if(!s->budget--) { s->failed_pc=0x0c08a532u; return 0; }
r[12]+=0x00000020u;
goto P_0c08a534;
P_0c08a534: /* original 7d50, guest PC 0x0c08a534 */
if(!s->budget--) { s->failed_pc=0x0c08a534u; return 0; }
r[13]+=0x00000050u;
goto P_0c08a536;
P_0c08a536: /* original f2f0, guest PC 0x0c08a536 */
if(!s->budget--) { s->failed_pc=0x0c08a536u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[15],r[18],'+');
goto P_0c08a538;
P_0c08a538: /* original ff27, guest PC 0x0c08a538 */
if(!s->budget--) { s->failed_pc=0x0c08a538u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c08a53a;
P_0c08a53a: /* original c72b, guest PC 0x0c08a53a */
if(!s->budget--) { s->failed_pc=0x0c08a53au; return 0; }
r[0]=code_base|0x0008a5e8u;
goto P_0c08a53c;
P_0c08a53c: /* original f208, guest PC 0x0c08a53c */
if(!s->budget--) { s->failed_pc=0x0c08a53cu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c08a53e;
P_0c08a53e: /* original c72b, guest PC 0x0c08a53e */
if(!s->budget--) { s->failed_pc=0x0c08a53eu; return 0; }
r[0]=code_base|0x0008a5ecu;
goto P_0c08a540;
P_0c08a540: /* original f1f8, guest PC 0x0c08a540 */
if(!s->budget--) { s->failed_pc=0x0c08a540u; return 0; }
vf3_matrix_load(s,ram,1,r[15]);
goto P_0c08a542;
P_0c08a542: /* original f120, guest PC 0x0c08a542 */
if(!s->budget--) { s->failed_pc=0x0c08a542u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'+');
goto P_0c08a544;
P_0c08a544: /* original ff1a, guest PC 0x0c08a544 */
if(!s->budget--) { s->failed_pc=0x0c08a544u; return 0; }
vf3_matrix_store(s,ram,1,r[15]);
goto P_0c08a546;
P_0c08a546: /* original f108, guest PC 0x0c08a546 */
if(!s->budget--) { s->failed_pc=0x0c08a546u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c08a548;
P_0c08a548: /* original e008, guest PC 0x0c08a548 */
if(!s->budget--) { s->failed_pc=0x0c08a548u; return 0; }
r[0]=0x00000008u;
goto P_0c08a54a;
P_0c08a54a: /* original f0f6, guest PC 0x0c08a54a */
if(!s->budget--) { s->failed_pc=0x0c08a54au; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c08a54c;
P_0c08a54c: /* original e008, guest PC 0x0c08a54c */
if(!s->budget--) { s->failed_pc=0x0c08a54cu; return 0; }
r[0]=0x00000008u;
goto P_0c08a54e;
P_0c08a54e: /* original f010, guest PC 0x0c08a54e */
if(!s->budget--) { s->failed_pc=0x0c08a54eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'+');
goto P_0c08a550;
P_0c08a550: /* original ff07, guest PC 0x0c08a550 */
if(!s->budget--) { s->failed_pc=0x0c08a550u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c08a552;
P_0c08a552: /* original 9042, guest PC 0x0c08a552 */
if(!s->budget--) { s->failed_pc=0x0c08a552u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a5dau,2);
goto P_0c08a554;
P_0c08a554: /* original 02ed, guest PC 0x0c08a554 */
if(!s->budget--) { s->failed_pc=0x0c08a554u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08a556;
P_0c08a556: /* original 7201, guest PC 0x0c08a556 */
if(!s->budget--) { s->failed_pc=0x0c08a556u; return 0; }
r[2]+=0x00000001u;
goto P_0c08a558;
P_0c08a558: /* original 0e25, guest PC 0x0c08a558 */
if(!s->budget--) { s->failed_pc=0x0c08a558u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c08a55a;
P_0c08a55a: /* original c725, guest PC 0x0c08a55a */
if(!s->budget--) { s->failed_pc=0x0c08a55au; return 0; }
r[0]=code_base|0x0008a5f0u;
goto P_0c08a55c;
P_0c08a55c: /* original a018, guest PC 0x0c08a55c */
if(!s->budget--) { s->failed_pc=0x0c08a55cu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08a590;
P_0c08a55e: /* original ff08, guest PC 0x0c08a55e */
if(!s->budget--) { s->failed_pc=0x0c08a55eu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08a560;
P_0c08a560: /* original c724, guest PC 0x0c08a560 */
if(!s->budget--) { s->failed_pc=0x0c08a560u; return 0; }
r[0]=code_base|0x0008a5f4u;
goto P_0c08a562;
P_0c08a562: /* original f308, guest PC 0x0c08a562 */
if(!s->budget--) { s->failed_pc=0x0c08a562u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08a564;
P_0c08a564: /* original e004, guest PC 0x0c08a564 */
if(!s->budget--) { s->failed_pc=0x0c08a564u; return 0; }
r[0]=0x00000004u;
goto P_0c08a566;
P_0c08a566: /* original f2f6, guest PC 0x0c08a566 */
if(!s->budget--) { s->failed_pc=0x0c08a566u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c08a568;
P_0c08a568: /* original e004, guest PC 0x0c08a568 */
if(!s->budget--) { s->failed_pc=0x0c08a568u; return 0; }
r[0]=0x00000004u;
goto P_0c08a56a;
P_0c08a56a: /* original ff32, guest PC 0x0c08a56a */
if(!s->budget--) { s->failed_pc=0x0c08a56au; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c08a56c;
P_0c08a56c: /* original f2f1, guest PC 0x0c08a56c */
if(!s->budget--) { s->failed_pc=0x0c08a56cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[15],r[18],'-');
goto P_0c08a56e;
P_0c08a56e: /* original ff27, guest PC 0x0c08a56e */
if(!s->budget--) { s->failed_pc=0x0c08a56eu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c08a570;
P_0c08a570: /* original c721, guest PC 0x0c08a570 */
if(!s->budget--) { s->failed_pc=0x0c08a570u; return 0; }
r[0]=code_base|0x0008a5f8u;
goto P_0c08a572;
P_0c08a572: /* original f1f8, guest PC 0x0c08a572 */
if(!s->budget--) { s->failed_pc=0x0c08a572u; return 0; }
vf3_matrix_load(s,ram,1,r[15]);
goto P_0c08a574;
P_0c08a574: /* original f208, guest PC 0x0c08a574 */
if(!s->budget--) { s->failed_pc=0x0c08a574u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c08a576;
P_0c08a576: /* original c721, guest PC 0x0c08a576 */
if(!s->budget--) { s->failed_pc=0x0c08a576u; return 0; }
r[0]=code_base|0x0008a5fcu;
goto P_0c08a578;
P_0c08a578: /* original f120, guest PC 0x0c08a578 */
if(!s->budget--) { s->failed_pc=0x0c08a578u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'+');
goto P_0c08a57a;
P_0c08a57a: /* original ff1a, guest PC 0x0c08a57a */
if(!s->budget--) { s->failed_pc=0x0c08a57au; return 0; }
vf3_matrix_store(s,ram,1,r[15]);
goto P_0c08a57c;
P_0c08a57c: /* original f108, guest PC 0x0c08a57c */
if(!s->budget--) { s->failed_pc=0x0c08a57cu; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c08a57e;
P_0c08a57e: /* original e008, guest PC 0x0c08a57e */
if(!s->budget--) { s->failed_pc=0x0c08a57eu; return 0; }
r[0]=0x00000008u;
goto P_0c08a580;
P_0c08a580: /* original f0f6, guest PC 0x0c08a580 */
if(!s->budget--) { s->failed_pc=0x0c08a580u; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c08a582;
P_0c08a582: /* original e008, guest PC 0x0c08a582 */
if(!s->budget--) { s->failed_pc=0x0c08a582u; return 0; }
r[0]=0x00000008u;
goto P_0c08a584;
P_0c08a584: /* original f010, guest PC 0x0c08a584 */
if(!s->budget--) { s->failed_pc=0x0c08a584u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'+');
goto P_0c08a586;
P_0c08a586: /* original ff07, guest PC 0x0c08a586 */
if(!s->budget--) { s->failed_pc=0x0c08a586u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c08a588;
P_0c08a588: /* original 9027, guest PC 0x0c08a588 */
if(!s->budget--) { s->failed_pc=0x0c08a588u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a5dau,2);
goto P_0c08a58a;
P_0c08a58a: /* original 02ed, guest PC 0x0c08a58a */
if(!s->budget--) { s->failed_pc=0x0c08a58au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08a58c;
P_0c08a58c: /* original 7201, guest PC 0x0c08a58c */
if(!s->budget--) { s->failed_pc=0x0c08a58cu; return 0; }
r[2]+=0x00000001u;
goto P_0c08a58e;
P_0c08a58e: /* original 0e25, guest PC 0x0c08a58e */
if(!s->budget--) { s->failed_pc=0x0c08a58eu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c08a590;
P_0c08a590: /* original d31b, guest PC 0x0c08a590 */
if(!s->budget--) { s->failed_pc=0x0c08a590u; return 0; }
r[3]=read(ram,0x0c08a600u,4);
goto P_0c08a592;
P_0c08a592: /* original 64e3, guest PC 0x0c08a592 */
if(!s->budget--) { s->failed_pc=0x0c08a592u; return 0; }
r[4]=r[14];
goto P_0c08a594;
P_0c08a594: /* original 430b, guest PC 0x0c08a594 */
if(!s->budget--) { s->failed_pc=0x0c08a594u; return 0; }
target=r[3];
r[16]=code_base|0x0c08a598u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a598u) { target=s->pc; goto dispatch; }
goto P_0c08a598;
P_0c08a596: /* original 7410, guest PC 0x0c08a596 */
if(!s->budget--) { s->failed_pc=0x0c08a596u; return 0; }
r[4]+=0x00000010u;
goto P_0c08a598;
P_0c08a598: /* original 63df, guest PC 0x0c08a598 */
if(!s->budget--) { s->failed_pc=0x0c08a598u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c08a59a;
P_0c08a59a: /* original 901f, guest PC 0x0c08a59a */
if(!s->budget--) { s->failed_pc=0x0c08a59au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a5dcu,2);
goto P_0c08a59c;
P_0c08a59c: /* original fef7, guest PC 0x0c08a59c */
if(!s->budget--) { s->failed_pc=0x0c08a59cu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c08a59e;
P_0c08a59e: /* original 70fc, guest PC 0x0c08a59e */
if(!s->budget--) { s->failed_pc=0x0c08a59eu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08a5a0;
P_0c08a5a0: /* original 435a, guest PC 0x0c08a5a0 */
if(!s->budget--) { s->failed_pc=0x0c08a5a0u; return 0; }
r[53]=r[3];
goto P_0c08a5a2;
P_0c08a5a2: /* original 63cf, guest PC 0x0c08a5a2 */
if(!s->budget--) { s->failed_pc=0x0c08a5a2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c08a5a4;
P_0c08a5a4: /* original f32d, guest PC 0x0c08a5a4 */
if(!s->budget--) { s->failed_pc=0x0c08a5a4u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c08a5a6;
P_0c08a5a6: /* original fe37, guest PC 0x0c08a5a6 */
if(!s->budget--) { s->failed_pc=0x0c08a5a6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08a5a8;
P_0c08a5a8: /* original 7008, guest PC 0x0c08a5a8 */
if(!s->budget--) { s->failed_pc=0x0c08a5a8u; return 0; }
r[0]+=0x00000008u;
goto P_0c08a5aa;
P_0c08a5aa: /* original 435a, guest PC 0x0c08a5aa */
if(!s->budget--) { s->failed_pc=0x0c08a5aau; return 0; }
r[53]=r[3];
goto P_0c08a5ac;
P_0c08a5ac: /* original f32d, guest PC 0x0c08a5ac */
if(!s->budget--) { s->failed_pc=0x0c08a5acu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c08a5ae;
P_0c08a5ae: /* original fe37, guest PC 0x0c08a5ae */
if(!s->budget--) { s->failed_pc=0x0c08a5aeu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08a5b0;
P_0c08a5b0: /* original d314, guest PC 0x0c08a5b0 */
if(!s->budget--) { s->failed_pc=0x0c08a5b0u; return 0; }
r[3]=read(ram,0x0c08a604u,4);
goto P_0c08a5b2;
P_0c08a5b2: /* original 430b, guest PC 0x0c08a5b2 */
if(!s->budget--) { s->failed_pc=0x0c08a5b2u; return 0; }
target=r[3];
r[16]=code_base|0x0c08a5b6u;
r[4]=(uint32_t)(int32_t)(int16_t)r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a5b6u) { target=s->pc; goto dispatch; }
goto P_0c08a5b6;
P_0c08a5b4: /* original 64df, guest PC 0x0c08a5b4 */
if(!s->budget--) { s->failed_pc=0x0c08a5b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c08a5b6;
P_0c08a5b6: /* original d214, guest PC 0x0c08a5b6 */
if(!s->budget--) { s->failed_pc=0x0c08a5b6u; return 0; }
r[2]=read(ram,0x0c08a608u,4);
goto P_0c08a5b8;
P_0c08a5b8: /* original 420b, guest PC 0x0c08a5b8 */
if(!s->budget--) { s->failed_pc=0x0c08a5b8u; return 0; }
target=r[2];
r[16]=code_base|0x0c08a5bcu;
r[4]=(uint32_t)(int32_t)(int16_t)r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a5bcu) { target=s->pc; goto dispatch; }
goto P_0c08a5bc;
P_0c08a5ba: /* original 64cf, guest PC 0x0c08a5ba */
if(!s->budget--) { s->failed_pc=0x0c08a5bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c08a5bc;
P_0c08a5bc: /* original d313, guest PC 0x0c08a5bc */
if(!s->budget--) { s->failed_pc=0x0c08a5bcu; return 0; }
r[3]=read(ram,0x0c08a60cu,4);
goto P_0c08a5be;
P_0c08a5be: /* original 430b, guest PC 0x0c08a5be */
if(!s->budget--) { s->failed_pc=0x0c08a5beu; return 0; }
target=r[3];
r[16]=code_base|0x0c08a5c2u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a5c2u) { target=s->pc; goto dispatch; }
goto P_0c08a5c2;
P_0c08a5c0: /* original 64f3, guest PC 0x0c08a5c0 */
if(!s->budget--) { s->failed_pc=0x0c08a5c0u; return 0; }
r[4]=r[15];
goto P_0c08a5c2;
P_0c08a5c2: /* original d213, guest PC 0x0c08a5c2 */
if(!s->budget--) { s->failed_pc=0x0c08a5c2u; return 0; }
r[2]=read(ram,0x0c08a610u,4);
goto P_0c08a5c4;
P_0c08a5c4: /* original 64e3, guest PC 0x0c08a5c4 */
if(!s->budget--) { s->failed_pc=0x0c08a5c4u; return 0; }
r[4]=r[14];
goto P_0c08a5c6;
P_0c08a5c6: /* original 420b, guest PC 0x0c08a5c6 */
if(!s->budget--) { s->failed_pc=0x0c08a5c6u; return 0; }
target=r[2];
r[16]=code_base|0x0c08a5cau;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a5cau) { target=s->pc; goto dispatch; }
goto P_0c08a5ca;
P_0c08a5c8: /* original 7410, guest PC 0x0c08a5c8 */
if(!s->budget--) { s->failed_pc=0x0c08a5c8u; return 0; }
r[4]+=0x00000010u;
goto P_0c08a5ca;
P_0c08a5ca: /* original 7f0c, guest PC 0x0c08a5ca */
if(!s->budget--) { s->failed_pc=0x0c08a5cau; return 0; }
r[15]+=0x0000000cu;
goto P_0c08a5cc;
P_0c08a5cc: /* original 4f26, guest PC 0x0c08a5cc */
if(!s->budget--) { s->failed_pc=0x0c08a5ccu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08a5ce;
P_0c08a5ce: /* original fff9, guest PC 0x0c08a5ce */
if(!s->budget--) { s->failed_pc=0x0c08a5ceu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08a5d0;
P_0c08a5d0: /* original 6cf6, guest PC 0x0c08a5d0 */
if(!s->budget--) { s->failed_pc=0x0c08a5d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08a5d2;
P_0c08a5d2: /* original 6df6, guest PC 0x0c08a5d2 */
if(!s->budget--) { s->failed_pc=0x0c08a5d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08a5d4;
P_0c08a5d4: /* original 000b, guest PC 0x0c08a5d4 */
if(!s->budget--) { s->failed_pc=0x0c08a5d4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08a5d6: /* original 6ef6, guest PC 0x0c08a5d6 */
if(!s->budget--) { s->failed_pc=0x0c08a5d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08a5d8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08a5d8u; return 0; } return 1;
P_0c08a6ec: /* original 2fe6, guest PC 0x0c08a6ec */
if(!s->budget--) { s->failed_pc=0x0c08a6ecu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a6ee;
P_0c08a6ee: /* original 6e53, guest PC 0x0c08a6ee */
if(!s->budget--) { s->failed_pc=0x0c08a6eeu; return 0; }
r[14]=r[5];
goto P_0c08a6f0;
P_0c08a6f0: /* original 2fd6, guest PC 0x0c08a6f0 */
if(!s->budget--) { s->failed_pc=0x0c08a6f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a6f2;
P_0c08a6f2: /* original e309, guest PC 0x0c08a6f2 */
if(!s->budget--) { s->failed_pc=0x0c08a6f2u; return 0; }
r[3]=0x00000009u;
goto P_0c08a6f4;
P_0c08a6f4: /* original fffb, guest PC 0x0c08a6f4 */
if(!s->budget--) { s->failed_pc=0x0c08a6f4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08a6f6;
P_0c08a6f6: /* original 6d63, guest PC 0x0c08a6f6 */
if(!s->budget--) { s->failed_pc=0x0c08a6f6u; return 0; }
r[13]=r[6];
goto P_0c08a6f8;
P_0c08a6f8: /* original 4f22, guest PC 0x0c08a6f8 */
if(!s->budget--) { s->failed_pc=0x0c08a6f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08a6fa;
P_0c08a6fa: /* original 7ff4, guest PC 0x0c08a6fa */
if(!s->budget--) { s->failed_pc=0x0c08a6fau; return 0; }
r[15]+=0xfffffff4u;
goto P_0c08a6fc;
P_0c08a6fc: /* original 1f72, guest PC 0x0c08a6fc */
if(!s->budget--) { s->failed_pc=0x0c08a6fcu; return 0; }
write(ram,r[15]+8,r[7],4);
goto P_0c08a6fe;
P_0c08a6fe: /* original 8541, guest PC 0x0c08a6fe */
if(!s->budget--) { s->failed_pc=0x0c08a6feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c08a700;
P_0c08a700: /* original 6503, guest PC 0x0c08a700 */
if(!s->budget--) { s->failed_pc=0x0c08a700u; return 0; }
r[5]=r[0];
goto P_0c08a702;
P_0c08a702: /* original 7501, guest PC 0x0c08a702 */
if(!s->budget--) { s->failed_pc=0x0c08a702u; return 0; }
r[5]+=0x00000001u;
goto P_0c08a704;
P_0c08a704: /* original 3537, guest PC 0x0c08a704 */
if(!s->budget--) { s->failed_pc=0x0c08a704u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[3])!=0);
goto P_0c08a706;
P_0c08a706: /* original 8f01, guest PC 0x0c08a706 */
if(!s->budget--) { s->failed_pc=0x0c08a706u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+14,r[0],2);
if(!cond) { goto P_0c08a70c; }
goto P_0c08a70a;
P_0c08a708: /* original 81e7, guest PC 0x0c08a708 */
if(!s->budget--) { s->failed_pc=0x0c08a708u; return 0; }
write(ram,r[14]+14,r[0],2);
goto P_0c08a70a;
P_0c08a70a: /* original e500, guest PC 0x0c08a70a */
if(!s->budget--) { s->failed_pc=0x0c08a70au; return 0; }
r[5]=0x00000000u;
goto P_0c08a70c;
P_0c08a70c: /* original d355, guest PC 0x0c08a70c */
if(!s->budget--) { s->failed_pc=0x0c08a70cu; return 0; }
r[3]=read(ram,0x0c08a864u,4);
goto P_0c08a70e;
P_0c08a70e: /* original 6053, guest PC 0x0c08a70e */
if(!s->budget--) { s->failed_pc=0x0c08a70eu; return 0; }
r[0]=r[5];
goto P_0c08a710;
P_0c08a710: /* original 430b, guest PC 0x0c08a710 */
if(!s->budget--) { s->failed_pc=0x0c08a710u; return 0; }
target=r[3];
r[16]=code_base|0x0c08a714u;
write(ram,r[4]+2,r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a714u) { target=s->pc; goto dispatch; }
goto P_0c08a714;
P_0c08a712: /* original 8141, guest PC 0x0c08a712 */
if(!s->budget--) { s->failed_pc=0x0c08a712u; return 0; }
write(ram,r[4]+2,r[0],2);
goto P_0c08a714;
P_0c08a714: /* original 6503, guest PC 0x0c08a714 */
if(!s->budget--) { s->failed_pc=0x0c08a714u; return 0; }
r[5]=r[0];
goto P_0c08a716;
P_0c08a716: /* original 97a3, guest PC 0x0c08a716 */
if(!s->budget--) { s->failed_pc=0x0c08a716u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a860u,2);
goto P_0c08a718;
P_0c08a718: /* original 4518, guest PC 0x0c08a718 */
if(!s->budget--) { s->failed_pc=0x0c08a718u; return 0; }
r[5]<<=8;
goto P_0c08a71a;
P_0c08a71a: /* original 6403, guest PC 0x0c08a71a */
if(!s->budget--) { s->failed_pc=0x0c08a71au; return 0; }
r[4]=r[0];
goto P_0c08a71c;
P_0c08a71c: /* original 2579, guest PC 0x0c08a71c */
if(!s->budget--) { s->failed_pc=0x0c08a71cu; return 0; }
r[5]&=r[7];
goto P_0c08a71e;
P_0c08a71e: /* original 6603, guest PC 0x0c08a71e */
if(!s->budget--) { s->failed_pc=0x0c08a71eu; return 0; }
r[6]=r[0];
goto P_0c08a720;
P_0c08a720: /* original 455a, guest PC 0x0c08a720 */
if(!s->budget--) { s->failed_pc=0x0c08a720u; return 0; }
r[53]=r[5];
goto P_0c08a722;
P_0c08a722: /* original 4421, guest PC 0x0c08a722 */
if(!s->budget--) { s->failed_pc=0x0c08a722u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]=(uint32_t)((int32_t)r[4]>>1);
goto P_0c08a724;
P_0c08a724: /* original 2479, guest PC 0x0c08a724 */
if(!s->budget--) { s->failed_pc=0x0c08a724u; return 0; }
r[4]&=r[7];
goto P_0c08a726;
P_0c08a726: /* original 939c, guest PC 0x0c08a726 */
if(!s->budget--) { s->failed_pc=0x0c08a726u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a862u,2);
goto P_0c08a728;
P_0c08a728: /* original 4608, guest PC 0x0c08a728 */
if(!s->budget--) { s->failed_pc=0x0c08a728u; return 0; }
r[6]<<=2;
goto P_0c08a72a;
P_0c08a72a: /* original f32d, guest PC 0x0c08a72a */
if(!s->budget--) { s->failed_pc=0x0c08a72au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c08a72c;
P_0c08a72c: /* original 2639, guest PC 0x0c08a72c */
if(!s->budget--) { s->failed_pc=0x0c08a72cu; return 0; }
r[6]&=r[3];
goto P_0c08a72e;
P_0c08a72e: /* original e004, guest PC 0x0c08a72e */
if(!s->budget--) { s->failed_pc=0x0c08a72eu; return 0; }
r[0]=0x00000004u;
goto P_0c08a730;
P_0c08a730: /* original ff37, guest PC 0x0c08a730 */
if(!s->budget--) { s->failed_pc=0x0c08a730u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a732;
P_0c08a732: /* original c74d, guest PC 0x0c08a732 */
if(!s->budget--) { s->failed_pc=0x0c08a732u; return 0; }
r[0]=code_base|0x0008a868u;
goto P_0c08a734;
P_0c08a734: /* original 445a, guest PC 0x0c08a734 */
if(!s->budget--) { s->failed_pc=0x0c08a734u; return 0; }
r[53]=r[4];
goto P_0c08a736;
P_0c08a736: /* original f22d, guest PC 0x0c08a736 */
if(!s->budget--) { s->failed_pc=0x0c08a736u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c08a738;
P_0c08a738: /* original ff2a, guest PC 0x0c08a738 */
if(!s->budget--) { s->failed_pc=0x0c08a738u; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c08a73a;
P_0c08a73a: /* original 465a, guest PC 0x0c08a73a */
if(!s->budget--) { s->failed_pc=0x0c08a73au; return 0; }
r[53]=r[6];
goto P_0c08a73c;
P_0c08a73c: /* original f408, guest PC 0x0c08a73c */
if(!s->budget--) { s->failed_pc=0x0c08a73cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c08a73e;
P_0c08a73e: /* original e004, guest PC 0x0c08a73e */
if(!s->budget--) { s->failed_pc=0x0c08a73eu; return 0; }
r[0]=0x00000004u;
goto P_0c08a740;
P_0c08a740: /* original f12d, guest PC 0x0c08a740 */
if(!s->budget--) { s->failed_pc=0x0c08a740u; return 0; }
fr[1]=vf3_fpu_float(r[53],r[18]);
goto P_0c08a742;
P_0c08a742: /* original ff1c, guest PC 0x0c08a742 */
if(!s->budget--) { s->failed_pc=0x0c08a742u; return 0; }
vf3_matrix_move(s,15,1);
goto P_0c08a744;
P_0c08a744: /* original ff43, guest PC 0x0c08a744 */
if(!s->budget--) { s->failed_pc=0x0c08a744u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'/');
goto P_0c08a746;
P_0c08a746: /* original f1f6, guest PC 0x0c08a746 */
if(!s->budget--) { s->failed_pc=0x0c08a746u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c08a748;
P_0c08a748: /* original e004, guest PC 0x0c08a748 */
if(!s->budget--) { s->failed_pc=0x0c08a748u; return 0; }
r[0]=0x00000004u;
goto P_0c08a74a;
P_0c08a74a: /* original f143, guest PC 0x0c08a74a */
if(!s->budget--) { s->failed_pc=0x0c08a74au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'/');
goto P_0c08a74c;
P_0c08a74c: /* original ff17, guest PC 0x0c08a74c */
if(!s->budget--) { s->failed_pc=0x0c08a74cu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c08a74e;
P_0c08a74e: /* original f3f8, guest PC 0x0c08a74e */
if(!s->budget--) { s->failed_pc=0x0c08a74eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c08a750;
P_0c08a750: /* original f343, guest PC 0x0c08a750 */
if(!s->budget--) { s->failed_pc=0x0c08a750u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'/');
goto P_0c08a752;
P_0c08a752: /* original ff3a, guest PC 0x0c08a752 */
if(!s->budget--) { s->failed_pc=0x0c08a752u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08a754;
P_0c08a754: /* original d245, guest PC 0x0c08a754 */
if(!s->budget--) { s->failed_pc=0x0c08a754u; return 0; }
r[2]=read(ram,0x0c08a86cu,4);
goto P_0c08a756;
P_0c08a756: /* original 65f3, guest PC 0x0c08a756 */
if(!s->budget--) { s->failed_pc=0x0c08a756u; return 0; }
r[5]=r[15];
goto P_0c08a758;
P_0c08a758: /* original 66f3, guest PC 0x0c08a758 */
if(!s->budget--) { s->failed_pc=0x0c08a758u; return 0; }
r[6]=r[15];
goto P_0c08a75a;
P_0c08a75a: /* original 7504, guest PC 0x0c08a75a */
if(!s->budget--) { s->failed_pc=0x0c08a75au; return 0; }
r[5]+=0x00000004u;
goto P_0c08a75c;
P_0c08a75c: /* original 420b, guest PC 0x0c08a75c */
if(!s->budget--) { s->failed_pc=0x0c08a75cu; return 0; }
target=r[2];
r[16]=code_base|0x0c08a760u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a760u) { target=s->pc; goto dispatch; }
goto P_0c08a760;
P_0c08a75e: /* original 54f2, guest PC 0x0c08a75e */
if(!s->budget--) { s->failed_pc=0x0c08a75eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c08a760;
P_0c08a760: /* original e004, guest PC 0x0c08a760 */
if(!s->budget--) { s->failed_pc=0x0c08a760u; return 0; }
r[0]=0x00000004u;
goto P_0c08a762;
P_0c08a762: /* original f3d8, guest PC 0x0c08a762 */
if(!s->budget--) { s->failed_pc=0x0c08a762u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c08a764;
P_0c08a764: /* original f2f6, guest PC 0x0c08a764 */
if(!s->budget--) { s->failed_pc=0x0c08a764u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c08a766;
P_0c08a766: /* original e004, guest PC 0x0c08a766 */
if(!s->budget--) { s->failed_pc=0x0c08a766u; return 0; }
r[0]=0x00000004u;
goto P_0c08a768;
P_0c08a768: /* original f230, guest PC 0x0c08a768 */
if(!s->budget--) { s->failed_pc=0x0c08a768u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c08a76a;
P_0c08a76a: /* original fe2a, guest PC 0x0c08a76a */
if(!s->budget--) { s->failed_pc=0x0c08a76au; return 0; }
vf3_matrix_store(s,ram,2,r[14]);
goto P_0c08a76c;
P_0c08a76c: /* original f3d6, guest PC 0x0c08a76c */
if(!s->budget--) { s->failed_pc=0x0c08a76cu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c08a76e;
P_0c08a76e: /* original ff30, guest PC 0x0c08a76e */
if(!s->budget--) { s->failed_pc=0x0c08a76eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c08a770;
P_0c08a770: /* original fef7, guest PC 0x0c08a770 */
if(!s->budget--) { s->failed_pc=0x0c08a770u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c08a772;
P_0c08a772: /* original e008, guest PC 0x0c08a772 */
if(!s->budget--) { s->failed_pc=0x0c08a772u; return 0; }
r[0]=0x00000008u;
goto P_0c08a774;
P_0c08a774: /* original f3f8, guest PC 0x0c08a774 */
if(!s->budget--) { s->failed_pc=0x0c08a774u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c08a776;
P_0c08a776: /* original 7f0c, guest PC 0x0c08a776 */
if(!s->budget--) { s->failed_pc=0x0c08a776u; return 0; }
r[15]+=0x0000000cu;
goto P_0c08a778;
P_0c08a778: /* original 4f26, guest PC 0x0c08a778 */
if(!s->budget--) { s->failed_pc=0x0c08a778u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08a77a;
P_0c08a77a: /* original f2d6, guest PC 0x0c08a77a */
if(!s->budget--) { s->failed_pc=0x0c08a77au; return 0; }
vf3_matrix_load(s,ram,2,r[13]+r[0]);
goto P_0c08a77c;
P_0c08a77c: /* original f34d, guest PC 0x0c08a77c */
if(!s->budget--) { s->failed_pc=0x0c08a77cu; return 0; }
fr[3]^=0x80000000u;
goto P_0c08a77e;
P_0c08a77e: /* original f321, guest PC 0x0c08a77e */
if(!s->budget--) { s->failed_pc=0x0c08a77eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'-');
goto P_0c08a780;
P_0c08a780: /* original fe37, guest PC 0x0c08a780 */
if(!s->budget--) { s->failed_pc=0x0c08a780u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08a782;
P_0c08a782: /* original fff9, guest PC 0x0c08a782 */
if(!s->budget--) { s->failed_pc=0x0c08a782u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08a784;
P_0c08a784: /* original 6df6, guest PC 0x0c08a784 */
if(!s->budget--) { s->failed_pc=0x0c08a784u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08a786;
P_0c08a786: /* original 000b, guest PC 0x0c08a786 */
if(!s->budget--) { s->failed_pc=0x0c08a786u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08a788: /* original 6ef6, guest PC 0x0c08a788 */
if(!s->budget--) { s->failed_pc=0x0c08a788u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08a78au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08a78au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
