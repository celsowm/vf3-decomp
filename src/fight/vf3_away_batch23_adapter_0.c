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
int vf3_away_batch23_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03550cu: goto P_0c03550c;
case 0x0c03550eu: goto P_0c03550e;
case 0x0c035510u: goto P_0c035510;
case 0x0c035512u: goto P_0c035512;
case 0x0c035514u: goto P_0c035514;
case 0x0c035516u: goto P_0c035516;
case 0x0c035518u: goto P_0c035518;
case 0x0c03551au: goto P_0c03551a;
case 0x0c03551cu: goto P_0c03551c;
case 0x0c03551eu: goto P_0c03551e;
case 0x0c035520u: goto P_0c035520;
case 0x0c035522u: goto P_0c035522;
case 0x0c035524u: goto P_0c035524;
case 0x0c035526u: goto P_0c035526;
case 0x0c035528u: goto P_0c035528;
case 0x0c03552au: goto P_0c03552a;
case 0x0c03552cu: goto P_0c03552c;
case 0x0c03552eu: goto P_0c03552e;
case 0x0c035530u: goto P_0c035530;
case 0x0c035532u: goto P_0c035532;
case 0x0c035534u: goto P_0c035534;
case 0x0c035536u: goto P_0c035536;
case 0x0c035538u: goto P_0c035538;
case 0x0c03553au: goto P_0c03553a;
case 0x0c03553cu: goto P_0c03553c;
case 0x0c03553eu: goto P_0c03553e;
case 0x0c035540u: goto P_0c035540;
case 0x0c035542u: goto P_0c035542;
case 0x0c035544u: goto P_0c035544;
case 0x0c035546u: goto P_0c035546;
case 0x0c035548u: goto P_0c035548;
case 0x0c03554au: goto P_0c03554a;
case 0x0c03554cu: goto P_0c03554c;
case 0x0c03554eu: goto P_0c03554e;
case 0x0c035550u: goto P_0c035550;
case 0x0c035552u: goto P_0c035552;
case 0x0c035554u: goto P_0c035554;
case 0x0c035556u: goto P_0c035556;
case 0x0c035558u: goto P_0c035558;
case 0x0c03555au: goto P_0c03555a;
case 0x0c03555cu: goto P_0c03555c;
case 0x0c03555eu: goto P_0c03555e;
case 0x0c035560u: goto P_0c035560;
case 0x0c035562u: goto P_0c035562;
case 0x0c035564u: goto P_0c035564;
case 0x0c035566u: goto P_0c035566;
case 0x0c035568u: goto P_0c035568;
case 0x0c03556au: goto P_0c03556a;
case 0x0c03556cu: goto P_0c03556c;
case 0x0c03556eu: goto P_0c03556e;
case 0x0c035570u: goto P_0c035570;
case 0x0c035572u: goto P_0c035572;
case 0x0c035574u: goto P_0c035574;
case 0x0c035576u: goto P_0c035576;
case 0x0c035578u: goto P_0c035578;
case 0x0c03557au: goto P_0c03557a;
case 0x0c03557cu: goto P_0c03557c;
case 0x0c03557eu: goto P_0c03557e;
case 0x0c035580u: goto P_0c035580;
case 0x0c035582u: goto P_0c035582;
case 0x0c035584u: goto P_0c035584;
case 0x0c035586u: goto P_0c035586;
case 0x0c035588u: goto P_0c035588;
case 0x0c03558au: goto P_0c03558a;
case 0x0c03558cu: goto P_0c03558c;
case 0x0c0355a0u: goto P_0c0355a0;
case 0x0c0355a2u: goto P_0c0355a2;
case 0x0c0355a4u: goto P_0c0355a4;
case 0x0c0355a6u: goto P_0c0355a6;
case 0x0c0355a8u: goto P_0c0355a8;
case 0x0c0355aau: goto P_0c0355aa;
case 0x0c0355acu: goto P_0c0355ac;
case 0x0c0355aeu: goto P_0c0355ae;
case 0x0c0355b0u: goto P_0c0355b0;
case 0x0c0355b2u: goto P_0c0355b2;
case 0x0c0355b4u: goto P_0c0355b4;
case 0x0c0355b6u: goto P_0c0355b6;
case 0x0c0355b8u: goto P_0c0355b8;
case 0x0c0355bau: goto P_0c0355ba;
case 0x0c0355bcu: goto P_0c0355bc;
case 0x0c0355beu: goto P_0c0355be;
case 0x0c0355c0u: goto P_0c0355c0;
case 0x0c0355c2u: goto P_0c0355c2;
case 0x0c0355c4u: goto P_0c0355c4;
case 0x0c0355c6u: goto P_0c0355c6;
case 0x0c0355c8u: goto P_0c0355c8;
case 0x0c035a20u: goto P_0c035a20;
case 0x0c035a22u: goto P_0c035a22;
case 0x0c035a24u: goto P_0c035a24;
case 0x0c035a26u: goto P_0c035a26;
case 0x0c035a28u: goto P_0c035a28;
case 0x0c035a2au: goto P_0c035a2a;
case 0x0c035a2cu: goto P_0c035a2c;
case 0x0c035a2eu: goto P_0c035a2e;
case 0x0c035a30u: goto P_0c035a30;
case 0x0c035a32u: goto P_0c035a32;
case 0x0c035a34u: goto P_0c035a34;
case 0x0c035a36u: goto P_0c035a36;
case 0x0c035a4eu: goto P_0c035a4e;
case 0x0c035a50u: goto P_0c035a50;
case 0x0c035a52u: goto P_0c035a52;
case 0x0c035a54u: goto P_0c035a54;
case 0x0c035a56u: goto P_0c035a56;
case 0x0c035a58u: goto P_0c035a58;
case 0x0c035a5au: goto P_0c035a5a;
case 0x0c035a5cu: goto P_0c035a5c;
case 0x0c035a5eu: goto P_0c035a5e;
case 0x0c035a60u: goto P_0c035a60;
case 0x0c035a62u: goto P_0c035a62;
case 0x0c035a64u: goto P_0c035a64;
case 0x0c035a66u: goto P_0c035a66;
case 0x0c035a68u: goto P_0c035a68;
case 0x0c035a6au: goto P_0c035a6a;
case 0x0c035a6cu: goto P_0c035a6c;
case 0x0c035a6eu: goto P_0c035a6e;
case 0x0c035a70u: goto P_0c035a70;
case 0x0c035a72u: goto P_0c035a72;
case 0x0c035a74u: goto P_0c035a74;
case 0x0c035a76u: goto P_0c035a76;
case 0x0c035a78u: goto P_0c035a78;
case 0x0c035a7au: goto P_0c035a7a;
case 0x0c035a7cu: goto P_0c035a7c;
case 0x0c035a7eu: goto P_0c035a7e;
case 0x0c035a80u: goto P_0c035a80;
case 0x0c035a82u: goto P_0c035a82;
case 0x0c035a84u: goto P_0c035a84;
case 0x0c035a86u: goto P_0c035a86;
case 0x0c035a88u: goto P_0c035a88;
case 0x0c035a8au: goto P_0c035a8a;
case 0x0c035a8cu: goto P_0c035a8c;
case 0x0c035a8eu: goto P_0c035a8e;
case 0x0c035a90u: goto P_0c035a90;
case 0x0c035a92u: goto P_0c035a92;
case 0x0c035a94u: goto P_0c035a94;
case 0x0c035a96u: goto P_0c035a96;
case 0x0c035a98u: goto P_0c035a98;
case 0x0c035a9au: goto P_0c035a9a;
case 0x0c035a9cu: goto P_0c035a9c;
case 0x0c035a9eu: goto P_0c035a9e;
case 0x0c035aa0u: goto P_0c035aa0;
case 0x0c038570u: goto P_0c038570;
case 0x0c038572u: goto P_0c038572;
case 0x0c038574u: goto P_0c038574;
case 0x0c038576u: goto P_0c038576;
case 0x0c038578u: goto P_0c038578;
case 0x0c03857au: goto P_0c03857a;
case 0x0c03857cu: goto P_0c03857c;
case 0x0c03857eu: goto P_0c03857e;
case 0x0c038580u: goto P_0c038580;
case 0x0c038582u: goto P_0c038582;
case 0x0c038584u: goto P_0c038584;
case 0x0c038586u: goto P_0c038586;
case 0x0c038590u: goto P_0c038590;
case 0x0c038592u: goto P_0c038592;
case 0x0c038594u: goto P_0c038594;
case 0x0c038596u: goto P_0c038596;
case 0x0c038598u: goto P_0c038598;
case 0x0c03859au: goto P_0c03859a;
case 0x0c03859cu: goto P_0c03859c;
case 0x0c03859eu: goto P_0c03859e;
case 0x0c0385a0u: goto P_0c0385a0;
case 0x0c0385a2u: goto P_0c0385a2;
case 0x0c0385a4u: goto P_0c0385a4;
case 0x0c0385a6u: goto P_0c0385a6;
case 0x0c0385a8u: goto P_0c0385a8;
case 0x0c0385aau: goto P_0c0385aa;
case 0x0c0385acu: goto P_0c0385ac;
case 0x0c0385aeu: goto P_0c0385ae;
case 0x0c0385b0u: goto P_0c0385b0;
case 0x0c0385b2u: goto P_0c0385b2;
case 0x0c0385b4u: goto P_0c0385b4;
case 0x0c0385b6u: goto P_0c0385b6;
case 0x0c0385b8u: goto P_0c0385b8;
case 0x0c0385c0u: goto P_0c0385c0;
case 0x0c0385c2u: goto P_0c0385c2;
case 0x0c0385c4u: goto P_0c0385c4;
case 0x0c0385c6u: goto P_0c0385c6;
case 0x0c0385c8u: goto P_0c0385c8;
case 0x0c0385cau: goto P_0c0385ca;
case 0x0c0385ccu: goto P_0c0385cc;
case 0x0c0385ceu: goto P_0c0385ce;
case 0x0c0385d0u: goto P_0c0385d0;
case 0x0c0385d2u: goto P_0c0385d2;
case 0x0c0385d4u: goto P_0c0385d4;
case 0x0c0385d6u: goto P_0c0385d6;
case 0x0c0385d8u: goto P_0c0385d8;
case 0x0c0385dau: goto P_0c0385da;
case 0x0c0385dcu: goto P_0c0385dc;
case 0x0c0385deu: goto P_0c0385de;
case 0x0c0385e0u: goto P_0c0385e0;
case 0x0c0385e2u: goto P_0c0385e2;
case 0x0c0385e4u: goto P_0c0385e4;
case 0x0c0385e6u: goto P_0c0385e6;
case 0x0c03b5c0u: goto P_0c03b5c0;
case 0x0c03b5c2u: goto P_0c03b5c2;
case 0x0c03b5c4u: goto P_0c03b5c4;
case 0x0c03b5c6u: goto P_0c03b5c6;
case 0x0c03b5c8u: goto P_0c03b5c8;
case 0x0c03b5cau: goto P_0c03b5ca;
case 0x0c03b5ccu: goto P_0c03b5cc;
case 0x0c03b5ceu: goto P_0c03b5ce;
case 0x0c03b5d0u: goto P_0c03b5d0;
case 0x0c03b5d2u: goto P_0c03b5d2;
case 0x0c03b5d4u: goto P_0c03b5d4;
case 0x0c03b5d6u: goto P_0c03b5d6;
case 0x0c03b5d8u: goto P_0c03b5d8;
case 0x0c03b5dau: goto P_0c03b5da;
case 0x0c03b5dcu: goto P_0c03b5dc;
case 0x0c03b5deu: goto P_0c03b5de;
case 0x0c03b5e0u: goto P_0c03b5e0;
case 0x0c03b5e2u: goto P_0c03b5e2;
case 0x0c03b5e4u: goto P_0c03b5e4;
case 0x0c03b5e6u: goto P_0c03b5e6;
case 0x0c03b5e8u: goto P_0c03b5e8;
case 0x0c03b5eau: goto P_0c03b5ea;
case 0x0c03b5ecu: goto P_0c03b5ec;
case 0x0c03b5eeu: goto P_0c03b5ee;
case 0x0c03b5f0u: goto P_0c03b5f0;
case 0x0c03b5f2u: goto P_0c03b5f2;
case 0x0c03b5f4u: goto P_0c03b5f4;
case 0x0c03b5f6u: goto P_0c03b5f6;
case 0x0c03b5f8u: goto P_0c03b5f8;
case 0x0c03b5fau: goto P_0c03b5fa;
case 0x0c03b5fcu: goto P_0c03b5fc;
case 0x0c03b5feu: goto P_0c03b5fe;
case 0x0c03b600u: goto P_0c03b600;
case 0x0c03b602u: goto P_0c03b602;
case 0x0c03b604u: goto P_0c03b604;
case 0x0c03b606u: goto P_0c03b606;
case 0x0c03b608u: goto P_0c03b608;
case 0x0c03b60au: goto P_0c03b60a;
case 0x0c03b60cu: goto P_0c03b60c;
case 0x0c03b60eu: goto P_0c03b60e;
case 0x0c03b610u: goto P_0c03b610;
case 0x0c03b612u: goto P_0c03b612;
case 0x0c03b614u: goto P_0c03b614;
case 0x0c03b616u: goto P_0c03b616;
case 0x0c03b618u: goto P_0c03b618;
case 0x0c03b61au: goto P_0c03b61a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03550c: /* original 2fe6, guest PC 0x0c03550c */
if(!s->budget--) { s->failed_pc=0x0c03550cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03550e;
P_0c03550e: /* original 6e43, guest PC 0x0c03550e */
if(!s->budget--) { s->failed_pc=0x0c03550eu; return 0; }
r[14]=r[4];
goto P_0c035510;
P_0c035510: /* original 2fd6, guest PC 0x0c035510 */
if(!s->budget--) { s->failed_pc=0x0c035510u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035512;
P_0c035512: /* original 2fc6, guest PC 0x0c035512 */
if(!s->budget--) { s->failed_pc=0x0c035512u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035514;
P_0c035514: /* original 2fb6, guest PC 0x0c035514 */
if(!s->budget--) { s->failed_pc=0x0c035514u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035516;
P_0c035516: /* original 2fa6, guest PC 0x0c035516 */
if(!s->budget--) { s->failed_pc=0x0c035516u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035518;
P_0c035518: /* original 4f22, guest PC 0x0c035518 */
if(!s->budget--) { s->failed_pc=0x0c035518u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03551a;
P_0c03551a: /* original d333, guest PC 0x0c03551a */
if(!s->budget--) { s->failed_pc=0x0c03551au; return 0; }
r[3]=read(ram,0x0c0355e8u,4);
goto P_0c03551c;
P_0c03551c: /* original 6d32, guest PC 0x0c03551c */
if(!s->budget--) { s->failed_pc=0x0c03551cu; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c03551e;
P_0c03551e: /* original 9c61, guest PC 0x0c03551e */
if(!s->budget--) { s->failed_pc=0x0c03551eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0355e4u,2);
goto P_0c035520;
P_0c035520: /* original da32, guest PC 0x0c035520 */
if(!s->budget--) { s->failed_pc=0x0c035520u; return 0; }
r[10]=read(ram,0x0c0355ecu,4);
goto P_0c035522;
P_0c035522: /* original 5be6, guest PC 0x0c035522 */
if(!s->budget--) { s->failed_pc=0x0c035522u; return 0; }
r[11]=read(ram,r[14]+24,4);
goto P_0c035524;
P_0c035524: /* original 60e2, guest PC 0x0c035524 */
if(!s->budget--) { s->failed_pc=0x0c035524u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c035526;
P_0c035526: /* original 5009, guest PC 0x0c035526 */
if(!s->budget--) { s->failed_pc=0x0c035526u; return 0; }
r[0]=read(ram,r[0]+36,4);
goto P_0c035528;
P_0c035528: /* original 8802, guest PC 0x0c035528 */
if(!s->budget--) { s->failed_pc=0x0c035528u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c03552a;
P_0c03552a: /* original 8901, guest PC 0x0c03552a */
if(!s->budget--) { s->failed_pc=0x0c03552au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035530; }
goto P_0c03552c;
P_0c03552c: /* original 4a0b, guest PC 0x0c03552c */
if(!s->budget--) { s->failed_pc=0x0c03552cu; return 0; }
target=r[10];
r[16]=code_base|0x0c035530u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035530u) { target=s->pc; goto dispatch; }
goto P_0c035530;
P_0c03552e: /* original 0009, guest PC 0x0c03552e */
if(!s->budget--) { s->failed_pc=0x0c03552eu; return 0; }
goto P_0c035530;
P_0c035530: /* original b276, guest PC 0x0c035530 */
if(!s->budget--) { s->failed_pc=0x0c035530u; return 0; }
target=code_base|0x0c035a20u; r[16]=code_base|0x0c035534u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035534u) { target=s->pc; goto dispatch; }
goto P_0c035534;
P_0c035532: /* original 64e3, guest PC 0x0c035532 */
if(!s->budget--) { s->failed_pc=0x0c035532u; return 0; }
r[4]=r[14];
goto P_0c035534;
P_0c035534: /* original 8800, guest PC 0x0c035534 */
if(!s->budget--) { s->failed_pc=0x0c035534u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c035536;
P_0c035536: /* original 8d0e, guest PC 0x0c035536 */
if(!s->budget--) { s->failed_pc=0x0c035536u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c035556; }
goto P_0c03553a;
P_0c035538: /* original 6403, guest PC 0x0c035538 */
if(!s->budget--) { s->failed_pc=0x0c035538u; return 0; }
r[4]=r[0];
goto P_0c03553a;
P_0c03553a: /* original 8801, guest PC 0x0c03553a */
if(!s->budget--) { s->failed_pc=0x0c03553au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c03553c;
P_0c03553c: /* original 890d, guest PC 0x0c03553c */
if(!s->budget--) { s->failed_pc=0x0c03553cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555a; }
goto P_0c03553e;
P_0c03553e: /* original 8802, guest PC 0x0c03553e */
if(!s->budget--) { s->failed_pc=0x0c03553eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c035540;
P_0c035540: /* original 890d, guest PC 0x0c035540 */
if(!s->budget--) { s->failed_pc=0x0c035540u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555e; }
goto P_0c035542;
P_0c035542: /* original 8803, guest PC 0x0c035542 */
if(!s->budget--) { s->failed_pc=0x0c035542u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c035544;
P_0c035544: /* original 890b, guest PC 0x0c035544 */
if(!s->budget--) { s->failed_pc=0x0c035544u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555e; }
goto P_0c035546;
P_0c035546: /* original 8804, guest PC 0x0c035546 */
if(!s->budget--) { s->failed_pc=0x0c035546u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c035548;
P_0c035548: /* original 8909, guest PC 0x0c035548 */
if(!s->budget--) { s->failed_pc=0x0c035548u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555e; }
goto P_0c03554a;
P_0c03554a: /* original 8805, guest PC 0x0c03554a */
if(!s->budget--) { s->failed_pc=0x0c03554au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c03554c;
P_0c03554c: /* original 890d, guest PC 0x0c03554c */
if(!s->budget--) { s->failed_pc=0x0c03554cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03556a; }
goto P_0c03554e;
P_0c03554e: /* original 8806, guest PC 0x0c03554e */
if(!s->budget--) { s->failed_pc=0x0c03554eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c035550;
P_0c035550: /* original 890b, guest PC 0x0c035550 */
if(!s->budget--) { s->failed_pc=0x0c035550u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03556a; }
goto P_0c035552;
P_0c035552: /* original a00d, guest PC 0x0c035552 */
if(!s->budget--) { s->failed_pc=0x0c035552u; return 0; }
goto P_0c035570;
P_0c035554: /* original 0009, guest PC 0x0c035554 */
if(!s->budget--) { s->failed_pc=0x0c035554u; return 0; }
goto P_0c035556;
P_0c035556: /* original a013, guest PC 0x0c035556 */
if(!s->budget--) { s->failed_pc=0x0c035556u; return 0; }
r[0]=0xffffffe0u;
goto P_0c035580;
P_0c035558: /* original e0e0, guest PC 0x0c035558 */
if(!s->budget--) { s->failed_pc=0x0c035558u; return 0; }
r[0]=0xffffffe0u;
goto P_0c03555a;
P_0c03555a: /* original a011, guest PC 0x0c03555a */
if(!s->budget--) { s->failed_pc=0x0c03555au; return 0; }
r[0]=0x00000000u;
goto P_0c035580;
P_0c03555c: /* original e000, guest PC 0x0c03555c */
if(!s->budget--) { s->failed_pc=0x0c03555cu; return 0; }
r[0]=0x00000000u;
goto P_0c03555e;
P_0c03555e: /* original 53e6, guest PC 0x0c03555e */
if(!s->budget--) { s->failed_pc=0x0c03555eu; return 0; }
r[3]=read(ram,r[14]+24,4);
goto P_0c035560;
P_0c035560: /* original 3b30, guest PC 0x0c035560 */
if(!s->budget--) { s->failed_pc=0x0c035560u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[3])!=0);
goto P_0c035562;
P_0c035562: /* original 8907, guest PC 0x0c035562 */
if(!s->budget--) { s->failed_pc=0x0c035562u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035574; }
goto P_0c035564;
P_0c035564: /* original d120, guest PC 0x0c035564 */
if(!s->budget--) { s->failed_pc=0x0c035564u; return 0; }
r[1]=read(ram,0x0c0355e8u,4);
goto P_0c035566;
P_0c035566: /* original a005, guest PC 0x0c035566 */
if(!s->budget--) { s->failed_pc=0x0c035566u; return 0; }
tmp=read(ram,r[1],4);
r[13]=tmp;
goto P_0c035574;
P_0c035568: /* original 6d12, guest PC 0x0c035568 */
if(!s->budget--) { s->failed_pc=0x0c035568u; return 0; }
tmp=read(ram,r[1],4);
r[13]=tmp;
goto P_0c03556a;
P_0c03556a: /* original e04e, guest PC 0x0c03556a */
if(!s->budget--) { s->failed_pc=0x0c03556au; return 0; }
r[0]=0x0000004eu;
goto P_0c03556c;
P_0c03556c: /* original a008, guest PC 0x0c03556c */
if(!s->budget--) { s->failed_pc=0x0c03556cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c035580;
P_0c03556e: /* original 00ed, guest PC 0x0c03556e */
if(!s->budget--) { s->failed_pc=0x0c03556eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c035570;
P_0c035570: /* original a006, guest PC 0x0c035570 */
if(!s->budget--) { s->failed_pc=0x0c035570u; return 0; }
r[0]=0xffffffe7u;
goto P_0c035580;
P_0c035572: /* original e0e7, guest PC 0x0c035572 */
if(!s->budget--) { s->failed_pc=0x0c035572u; return 0; }
r[0]=0xffffffe7u;
goto P_0c035574;
P_0c035574: /* original d31c, guest PC 0x0c035574 */
if(!s->budget--) { s->failed_pc=0x0c035574u; return 0; }
r[3]=read(ram,0x0c0355e8u,4);
goto P_0c035576;
P_0c035576: /* original 6432, guest PC 0x0c035576 */
if(!s->budget--) { s->failed_pc=0x0c035576u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c035578;
P_0c035578: /* original 34d8, guest PC 0x0c035578 */
if(!s->budget--) { s->failed_pc=0x0c035578u; return 0; }
r[4]-=r[13];
goto P_0c03557a;
P_0c03557a: /* original 34c6, guest PC 0x0c03557a */
if(!s->budget--) { s->failed_pc=0x0c03557au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[12])!=0);
goto P_0c03557c;
P_0c03557c: /* original 8bd2, guest PC 0x0c03557c */
if(!s->budget--) { s->failed_pc=0x0c03557cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c035524; }
goto P_0c03557e;
P_0c03557e: /* original e0eb, guest PC 0x0c03557e */
if(!s->budget--) { s->failed_pc=0x0c03557eu; return 0; }
r[0]=0xffffffebu;
goto P_0c035580;
P_0c035580: /* original 4f26, guest PC 0x0c035580 */
if(!s->budget--) { s->failed_pc=0x0c035580u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c035582;
P_0c035582: /* original 6af6, guest PC 0x0c035582 */
if(!s->budget--) { s->failed_pc=0x0c035582u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c035584;
P_0c035584: /* original 6bf6, guest PC 0x0c035584 */
if(!s->budget--) { s->failed_pc=0x0c035584u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c035586;
P_0c035586: /* original 6cf6, guest PC 0x0c035586 */
if(!s->budget--) { s->failed_pc=0x0c035586u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c035588;
P_0c035588: /* original 6df6, guest PC 0x0c035588 */
if(!s->budget--) { s->failed_pc=0x0c035588u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03558a;
P_0c03558a: /* original 000b, guest PC 0x0c03558a */
if(!s->budget--) { s->failed_pc=0x0c03558au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03558c: /* original 6ef6, guest PC 0x0c03558c */
if(!s->budget--) { s->failed_pc=0x0c03558cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03558eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03558eu; return 0; } return 1;
P_0c0355a0: /* original 2fe6, guest PC 0x0c0355a0 */
if(!s->budget--) { s->failed_pc=0x0c0355a0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0355a2;
P_0c0355a2: /* original 6e43, guest PC 0x0c0355a2 */
if(!s->budget--) { s->failed_pc=0x0c0355a2u; return 0; }
r[14]=r[4];
goto P_0c0355a4;
P_0c0355a4: /* original 4f22, guest PC 0x0c0355a4 */
if(!s->budget--) { s->failed_pc=0x0c0355a4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0355a6;
P_0c0355a6: /* original 2ee8, guest PC 0x0c0355a6 */
if(!s->budget--) { s->failed_pc=0x0c0355a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0355a8;
P_0c0355a8: /* original 890c, guest PC 0x0c0355a8 */
if(!s->budget--) { s->failed_pc=0x0c0355a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0355c4; }
goto P_0c0355aa;
P_0c0355aa: /* original e048, guest PC 0x0c0355aa */
if(!s->budget--) { s->failed_pc=0x0c0355aau; return 0; }
r[0]=0x00000048u;
goto P_0c0355ac;
P_0c0355ac: /* original 02ed, guest PC 0x0c0355ac */
if(!s->budget--) { s->failed_pc=0x0c0355acu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0355ae;
P_0c0355ae: /* original 2228, guest PC 0x0c0355ae */
if(!s->budget--) { s->failed_pc=0x0c0355aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0355b0;
P_0c0355b0: /* original 8908, guest PC 0x0c0355b0 */
if(!s->budget--) { s->failed_pc=0x0c0355b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0355c4; }
goto P_0c0355b2;
P_0c0355b2: /* original e04c, guest PC 0x0c0355b2 */
if(!s->budget--) { s->failed_pc=0x0c0355b2u; return 0; }
r[0]=0x0000004cu;
goto P_0c0355b4;
P_0c0355b4: /* original 00ed, guest PC 0x0c0355b4 */
if(!s->budget--) { s->failed_pc=0x0c0355b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0355b6;
P_0c0355b6: /* original 8802, guest PC 0x0c0355b6 */
if(!s->budget--) { s->failed_pc=0x0c0355b6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0355b8;
P_0c0355b8: /* original 8b01, guest PC 0x0c0355b8 */
if(!s->budget--) { s->failed_pc=0x0c0355b8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0355be; }
goto P_0c0355ba;
P_0c0355ba: /* original b248, guest PC 0x0c0355ba */
if(!s->budget--) { s->failed_pc=0x0c0355bau; return 0; }
target=code_base|0x0c035a4eu; r[16]=code_base|0x0c0355beu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0355beu) { target=s->pc; goto dispatch; }
goto P_0c0355be;
P_0c0355bc: /* original 64e3, guest PC 0x0c0355bc */
if(!s->budget--) { s->failed_pc=0x0c0355bcu; return 0; }
r[4]=r[14];
goto P_0c0355be;
P_0c0355be: /* original e048, guest PC 0x0c0355be */
if(!s->budget--) { s->failed_pc=0x0c0355beu; return 0; }
r[0]=0x00000048u;
goto P_0c0355c0;
P_0c0355c0: /* original e300, guest PC 0x0c0355c0 */
if(!s->budget--) { s->failed_pc=0x0c0355c0u; return 0; }
r[3]=0x00000000u;
goto P_0c0355c2;
P_0c0355c2: /* original 0e35, guest PC 0x0c0355c2 */
if(!s->budget--) { s->failed_pc=0x0c0355c2u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0355c4;
P_0c0355c4: /* original 4f26, guest PC 0x0c0355c4 */
if(!s->budget--) { s->failed_pc=0x0c0355c4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0355c6;
P_0c0355c6: /* original 000b, guest PC 0x0c0355c6 */
if(!s->budget--) { s->failed_pc=0x0c0355c6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0355c8: /* original 6ef6, guest PC 0x0c0355c8 */
if(!s->budget--) { s->failed_pc=0x0c0355c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0355cau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0355cau; return 0; } return 1;
P_0c035a20: /* original 2448, guest PC 0x0c035a20 */
if(!s->budget--) { s->failed_pc=0x0c035a20u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c035a22;
P_0c035a22: /* original 8903, guest PC 0x0c035a22 */
if(!s->budget--) { s->failed_pc=0x0c035a22u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035a2c; }
goto P_0c035a24;
P_0c035a24: /* original e048, guest PC 0x0c035a24 */
if(!s->budget--) { s->failed_pc=0x0c035a24u; return 0; }
r[0]=0x00000048u;
goto P_0c035a26;
P_0c035a26: /* original 024d, guest PC 0x0c035a26 */
if(!s->budget--) { s->failed_pc=0x0c035a26u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c035a28;
P_0c035a28: /* original 2228, guest PC 0x0c035a28 */
if(!s->budget--) { s->failed_pc=0x0c035a28u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c035a2a;
P_0c035a2a: /* original 8b01, guest PC 0x0c035a2a */
if(!s->budget--) { s->failed_pc=0x0c035a2au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c035a30; }
goto P_0c035a2c;
P_0c035a2c: /* original 000b, guest PC 0x0c035a2c */
if(!s->budget--) { s->failed_pc=0x0c035a2cu; return 0; }
target=r[16];
r[0]=0xfffffff6u;
s->pc=target; return ram->oob==0;
P_0c035a2e: /* original e0f6, guest PC 0x0c035a2e */
if(!s->budget--) { s->failed_pc=0x0c035a2eu; return 0; }
r[0]=0xfffffff6u;
goto P_0c035a30;
P_0c035a30: /* original e04c, guest PC 0x0c035a30 */
if(!s->budget--) { s->failed_pc=0x0c035a30u; return 0; }
r[0]=0x0000004cu;
goto P_0c035a32;
P_0c035a32: /* original 004d, guest PC 0x0c035a32 */
if(!s->budget--) { s->failed_pc=0x0c035a32u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c035a34;
P_0c035a34: /* original 000b, guest PC 0x0c035a34 */
if(!s->budget--) { s->failed_pc=0x0c035a34u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c035a36: /* original 0009, guest PC 0x0c035a36 */
if(!s->budget--) { s->failed_pc=0x0c035a36u; return 0; }
if(!vf3_matrix_family(0x0c035a38u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c035a38u; return 0; } return 1;
P_0c035a4e: /* original 2fe6, guest PC 0x0c035a4e */
if(!s->budget--) { s->failed_pc=0x0c035a4eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035a50;
P_0c035a50: /* original 6e43, guest PC 0x0c035a50 */
if(!s->budget--) { s->failed_pc=0x0c035a50u; return 0; }
r[14]=r[4];
goto P_0c035a52;
P_0c035a52: /* original 4f22, guest PC 0x0c035a52 */
if(!s->budget--) { s->failed_pc=0x0c035a52u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c035a54;
P_0c035a54: /* original 2ee8, guest PC 0x0c035a54 */
if(!s->budget--) { s->failed_pc=0x0c035a54u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c035a56;
P_0c035a56: /* original 8903, guest PC 0x0c035a56 */
if(!s->budget--) { s->failed_pc=0x0c035a56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035a60; }
goto P_0c035a58;
P_0c035a58: /* original e048, guest PC 0x0c035a58 */
if(!s->budget--) { s->failed_pc=0x0c035a58u; return 0; }
r[0]=0x00000048u;
goto P_0c035a5a;
P_0c035a5a: /* original 02ed, guest PC 0x0c035a5a */
if(!s->budget--) { s->failed_pc=0x0c035a5au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c035a5c;
P_0c035a5c: /* original 2228, guest PC 0x0c035a5c */
if(!s->budget--) { s->failed_pc=0x0c035a5cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c035a5e;
P_0c035a5e: /* original 8b03, guest PC 0x0c035a5e */
if(!s->budget--) { s->failed_pc=0x0c035a5eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c035a68; }
goto P_0c035a60;
P_0c035a60: /* original 4f26, guest PC 0x0c035a60 */
if(!s->budget--) { s->failed_pc=0x0c035a60u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c035a62;
P_0c035a62: /* original e0f6, guest PC 0x0c035a62 */
if(!s->budget--) { s->failed_pc=0x0c035a62u; return 0; }
r[0]=0xfffffff6u;
goto P_0c035a64;
P_0c035a64: /* original 000b, guest PC 0x0c035a64 */
if(!s->budget--) { s->failed_pc=0x0c035a64u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c035a66: /* original 6ef6, guest PC 0x0c035a66 */
if(!s->budget--) { s->failed_pc=0x0c035a66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c035a68;
P_0c035a68: /* original e04c, guest PC 0x0c035a68 */
if(!s->budget--) { s->failed_pc=0x0c035a68u; return 0; }
r[0]=0x0000004cu;
goto P_0c035a6a;
P_0c035a6a: /* original 00ed, guest PC 0x0c035a6a */
if(!s->budget--) { s->failed_pc=0x0c035a6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c035a6c;
P_0c035a6c: /* original 8802, guest PC 0x0c035a6c */
if(!s->budget--) { s->failed_pc=0x0c035a6cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c035a6e;
P_0c035a6e: /* original 8906, guest PC 0x0c035a6e */
if(!s->budget--) { s->failed_pc=0x0c035a6eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035a7e; }
goto P_0c035a70;
P_0c035a70: /* original 4f26, guest PC 0x0c035a70 */
if(!s->budget--) { s->failed_pc=0x0c035a70u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c035a72;
P_0c035a72: /* original e04c, guest PC 0x0c035a72 */
if(!s->budget--) { s->failed_pc=0x0c035a72u; return 0; }
r[0]=0x0000004cu;
goto P_0c035a74;
P_0c035a74: /* original e200, guest PC 0x0c035a74 */
if(!s->budget--) { s->failed_pc=0x0c035a74u; return 0; }
r[2]=0x00000000u;
goto P_0c035a76;
P_0c035a76: /* original 0e25, guest PC 0x0c035a76 */
if(!s->budget--) { s->failed_pc=0x0c035a76u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c035a78;
P_0c035a78: /* original 6023, guest PC 0x0c035a78 */
if(!s->budget--) { s->failed_pc=0x0c035a78u; return 0; }
r[0]=r[2];
goto P_0c035a7a;
P_0c035a7a: /* original 000b, guest PC 0x0c035a7a */
if(!s->budget--) { s->failed_pc=0x0c035a7au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c035a7c: /* original 6ef6, guest PC 0x0c035a7c */
if(!s->budget--) { s->failed_pc=0x0c035a7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c035a7e;
P_0c035a7e: /* original 63e2, guest PC 0x0c035a7e */
if(!s->budget--) { s->failed_pc=0x0c035a7eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c035a80;
P_0c035a80: /* original 523a, guest PC 0x0c035a80 */
if(!s->budget--) { s->failed_pc=0x0c035a80u; return 0; }
r[2]=read(ram,r[3]+40,4);
goto P_0c035a82;
P_0c035a82: /* original 32e0, guest PC 0x0c035a82 */
if(!s->budget--) { s->failed_pc=0x0c035a82u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[14])!=0);
goto P_0c035a84;
P_0c035a84: /* original 8903, guest PC 0x0c035a84 */
if(!s->budget--) { s->failed_pc=0x0c035a84u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035a8e; }
goto P_0c035a86;
P_0c035a86: /* original 4f26, guest PC 0x0c035a86 */
if(!s->budget--) { s->failed_pc=0x0c035a86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c035a88;
P_0c035a88: /* original e0f3, guest PC 0x0c035a88 */
if(!s->budget--) { s->failed_pc=0x0c035a88u; return 0; }
r[0]=0xfffffff3u;
goto P_0c035a8a;
P_0c035a8a: /* original 000b, guest PC 0x0c035a8a */
if(!s->budget--) { s->failed_pc=0x0c035a8au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c035a8c: /* original 6ef6, guest PC 0x0c035a8c */
if(!s->budget--) { s->failed_pc=0x0c035a8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c035a8e;
P_0c035a8e: /* original 62e2, guest PC 0x0c035a8e */
if(!s->budget--) { s->failed_pc=0x0c035a8eu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c035a90;
P_0c035a90: /* original 5325, guest PC 0x0c035a90 */
if(!s->budget--) { s->failed_pc=0x0c035a90u; return 0; }
r[3]=read(ram,r[2]+20,4);
goto P_0c035a92;
P_0c035a92: /* original 5135, guest PC 0x0c035a92 */
if(!s->budget--) { s->failed_pc=0x0c035a92u; return 0; }
r[1]=read(ram,r[3]+20,4);
goto P_0c035a94;
P_0c035a94: /* original 410b, guest PC 0x0c035a94 */
if(!s->budget--) { s->failed_pc=0x0c035a94u; return 0; }
target=r[1];
r[16]=code_base|0x0c035a98u;
r[4]=read(ram,r[14]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035a98u) { target=s->pc; goto dispatch; }
goto P_0c035a98;
P_0c035a96: /* original 54ef, guest PC 0x0c035a96 */
if(!s->budget--) { s->failed_pc=0x0c035a96u; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c035a98;
P_0c035a98: /* original bd38, guest PC 0x0c035a98 */
if(!s->budget--) { s->failed_pc=0x0c035a98u; return 0; }
target=code_base|0x0c03550cu; r[16]=code_base|0x0c035a9cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035a9cu) { target=s->pc; goto dispatch; }
goto P_0c035a9c;
P_0c035a9a: /* original 64e3, guest PC 0x0c035a9a */
if(!s->budget--) { s->failed_pc=0x0c035a9au; return 0; }
r[4]=r[14];
goto P_0c035a9c;
P_0c035a9c: /* original 4f26, guest PC 0x0c035a9c */
if(!s->budget--) { s->failed_pc=0x0c035a9cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c035a9e;
P_0c035a9e: /* original 000b, guest PC 0x0c035a9e */
if(!s->budget--) { s->failed_pc=0x0c035a9eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c035aa0: /* original 6ef6, guest PC 0x0c035aa0 */
if(!s->budget--) { s->failed_pc=0x0c035aa0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c035aa2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c035aa2u; return 0; } return 1;
P_0c038570: /* original d41f, guest PC 0x0c038570 */
if(!s->budget--) { s->failed_pc=0x0c038570u; return 0; }
r[4]=read(ram,0x0c0385f0u,4);
goto P_0c038572;
P_0c038572: /* original e000, guest PC 0x0c038572 */
if(!s->budget--) { s->failed_pc=0x0c038572u; return 0; }
r[0]=0x00000000u;
goto P_0c038574;
P_0c038574: /* original 8143, guest PC 0x0c038574 */
if(!s->budget--) { s->failed_pc=0x0c038574u; return 0; }
write(ram,r[4]+6,r[0],2);
goto P_0c038576;
P_0c038576: /* original d51f, guest PC 0x0c038576 */
if(!s->budget--) { s->failed_pc=0x0c038576u; return 0; }
r[5]=read(ram,0x0c0385f4u,4);
goto P_0c038578;
P_0c038578: /* original 6552, guest PC 0x0c038578 */
if(!s->budget--) { s->failed_pc=0x0c038578u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c03857a;
P_0c03857a: /* original 145b, guest PC 0x0c03857a */
if(!s->budget--) { s->failed_pc=0x0c03857au; return 0; }
write(ram,r[4]+44,r[5],4);
goto P_0c03857c;
P_0c03857c: /* original 145c, guest PC 0x0c03857c */
if(!s->budget--) { s->failed_pc=0x0c03857cu; return 0; }
write(ram,r[4]+48,r[5],4);
goto P_0c03857e;
P_0c03857e: /* original d51e, guest PC 0x0c03857e */
if(!s->budget--) { s->failed_pc=0x0c03857eu; return 0; }
r[5]=read(ram,0x0c0385f8u,4);
goto P_0c038580;
P_0c038580: /* original 6552, guest PC 0x0c038580 */
if(!s->budget--) { s->failed_pc=0x0c038580u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c038582;
P_0c038582: /* original 145e, guest PC 0x0c038582 */
if(!s->budget--) { s->failed_pc=0x0c038582u; return 0; }
write(ram,r[4]+56,r[5],4);
goto P_0c038584;
P_0c038584: /* original 000b, guest PC 0x0c038584 */
if(!s->budget--) { s->failed_pc=0x0c038584u; return 0; }
target=r[16];
write(ram,r[4]+60,r[5],4);
s->pc=target; return ram->oob==0;
P_0c038586: /* original 145f, guest PC 0x0c038586 */
if(!s->budget--) { s->failed_pc=0x0c038586u; return 0; }
write(ram,r[4]+60,r[5],4);
if(!vf3_matrix_family(0x0c038588u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038588u; return 0; } return 1;
P_0c038590: /* original d417, guest PC 0x0c038590 */
if(!s->budget--) { s->failed_pc=0x0c038590u; return 0; }
r[4]=read(ram,0x0c0385f0u,4);
goto P_0c038592;
P_0c038592: /* original e330, guest PC 0x0c038592 */
if(!s->budget--) { s->failed_pc=0x0c038592u; return 0; }
r[3]=0x00000030u;
goto P_0c038594;
P_0c038594: /* original 8543, guest PC 0x0c038594 */
if(!s->budget--) { s->failed_pc=0x0c038594u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+6,2);
goto P_0c038596;
P_0c038596: /* original 6503, guest PC 0x0c038596 */
if(!s->budget--) { s->failed_pc=0x0c038596u; return 0; }
r[5]=r[0];
goto P_0c038598;
P_0c038598: /* original 3533, guest PC 0x0c038598 */
if(!s->budget--) { s->failed_pc=0x0c038598u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[3])!=0);
goto P_0c03859a;
P_0c03859a: /* original 8d0c, guest PC 0x0c03859a */
if(!s->budget--) { s->failed_pc=0x0c03859au; return 0; }
cond=r[17]&1u;
r[6]=0xffffffffu;
if(cond) { goto P_0c0385b6; }
goto P_0c03859e;
P_0c03859c: /* original e6ff, guest PC 0x0c03859c */
if(!s->budget--) { s->failed_pc=0x0c03859cu; return 0; }
r[6]=0xffffffffu;
goto P_0c03859e;
P_0c03859e: /* original 7501, guest PC 0x0c03859e */
if(!s->budget--) { s->failed_pc=0x0c03859eu; return 0; }
r[5]+=0x00000001u;
goto P_0c0385a0;
P_0c0385a0: /* original 6053, guest PC 0x0c0385a0 */
if(!s->budget--) { s->failed_pc=0x0c0385a0u; return 0; }
r[0]=r[5];
goto P_0c0385a2;
P_0c0385a2: /* original 8143, guest PC 0x0c0385a2 */
if(!s->budget--) { s->failed_pc=0x0c0385a2u; return 0; }
write(ram,r[4]+6,r[0],2);
goto P_0c0385a4;
P_0c0385a4: /* original d013, guest PC 0x0c0385a4 */
if(!s->budget--) { s->failed_pc=0x0c0385a4u; return 0; }
r[0]=read(ram,0x0c0385f4u,4);
goto P_0c0385a6;
P_0c0385a6: /* original 4508, guest PC 0x0c0385a6 */
if(!s->budget--) { s->failed_pc=0x0c0385a6u; return 0; }
r[5]<<=2;
goto P_0c0385a8;
P_0c0385a8: /* original 524b, guest PC 0x0c0385a8 */
if(!s->budget--) { s->failed_pc=0x0c0385a8u; return 0; }
r[2]=read(ram,r[4]+44,4);
goto P_0c0385aa;
P_0c0385aa: /* original 6653, guest PC 0x0c0385aa */
if(!s->budget--) { s->failed_pc=0x0c0385aau; return 0; }
r[6]=r[5];
goto P_0c0385ac;
P_0c0385ac: /* original 0526, guest PC 0x0c0385ac */
if(!s->budget--) { s->failed_pc=0x0c0385acu; return 0; }
write(ram,r[5]+r[0],r[2],4);
goto P_0c0385ae;
P_0c0385ae: /* original 524e, guest PC 0x0c0385ae */
if(!s->budget--) { s->failed_pc=0x0c0385aeu; return 0; }
r[2]=read(ram,r[4]+56,4);
goto P_0c0385b0;
P_0c0385b0: /* original d011, guest PC 0x0c0385b0 */
if(!s->budget--) { s->failed_pc=0x0c0385b0u; return 0; }
r[0]=read(ram,0x0c0385f8u,4);
goto P_0c0385b2;
P_0c0385b2: /* original 0626, guest PC 0x0c0385b2 */
if(!s->budget--) { s->failed_pc=0x0c0385b2u; return 0; }
write(ram,r[6]+r[0],r[2],4);
goto P_0c0385b4;
P_0c0385b4: /* original e600, guest PC 0x0c0385b4 */
if(!s->budget--) { s->failed_pc=0x0c0385b4u; return 0; }
r[6]=0x00000000u;
goto P_0c0385b6;
P_0c0385b6: /* original 000b, guest PC 0x0c0385b6 */
if(!s->budget--) { s->failed_pc=0x0c0385b6u; return 0; }
target=r[16];
r[0]=r[6];
s->pc=target; return ram->oob==0;
P_0c0385b8: /* original 6063, guest PC 0x0c0385b8 */
if(!s->budget--) { s->failed_pc=0x0c0385b8u; return 0; }
r[0]=r[6];
if(!vf3_matrix_family(0x0c0385bau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0385bau; return 0; } return 1;
P_0c0385c0: /* original d40b, guest PC 0x0c0385c0 */
if(!s->budget--) { s->failed_pc=0x0c0385c0u; return 0; }
r[4]=read(ram,0x0c0385f0u,4);
goto P_0c0385c2;
P_0c0385c2: /* original 8543, guest PC 0x0c0385c2 */
if(!s->budget--) { s->failed_pc=0x0c0385c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+6,2);
goto P_0c0385c4;
P_0c0385c4: /* original 6103, guest PC 0x0c0385c4 */
if(!s->budget--) { s->failed_pc=0x0c0385c4u; return 0; }
r[1]=r[0];
goto P_0c0385c6;
P_0c0385c6: /* original 4115, guest PC 0x0c0385c6 */
if(!s->budget--) { s->failed_pc=0x0c0385c6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c0385c8;
P_0c0385c8: /* original 8f0c, guest PC 0x0c0385c8 */
if(!s->budget--) { s->failed_pc=0x0c0385c8u; return 0; }
cond=r[17]&1u;
r[5]=0xffffffffu;
if(!cond) { goto P_0c0385e4; }
goto P_0c0385cc;
P_0c0385ca: /* original e5ff, guest PC 0x0c0385ca */
if(!s->budget--) { s->failed_pc=0x0c0385cau; return 0; }
r[5]=0xffffffffu;
goto P_0c0385cc;
P_0c0385cc: /* original d00a, guest PC 0x0c0385cc */
if(!s->budget--) { s->failed_pc=0x0c0385ccu; return 0; }
r[0]=read(ram,0x0c0385f8u,4);
goto P_0c0385ce;
P_0c0385ce: /* original 6513, guest PC 0x0c0385ce */
if(!s->budget--) { s->failed_pc=0x0c0385ceu; return 0; }
r[5]=r[1];
goto P_0c0385d0;
P_0c0385d0: /* original 4508, guest PC 0x0c0385d0 */
if(!s->budget--) { s->failed_pc=0x0c0385d0u; return 0; }
r[5]<<=2;
goto P_0c0385d2;
P_0c0385d2: /* original 035e, guest PC 0x0c0385d2 */
if(!s->budget--) { s->failed_pc=0x0c0385d2u; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c0385d4;
P_0c0385d4: /* original 143e, guest PC 0x0c0385d4 */
if(!s->budget--) { s->failed_pc=0x0c0385d4u; return 0; }
write(ram,r[4]+56,r[3],4);
goto P_0c0385d6;
P_0c0385d6: /* original d007, guest PC 0x0c0385d6 */
if(!s->budget--) { s->failed_pc=0x0c0385d6u; return 0; }
r[0]=read(ram,0x0c0385f4u,4);
goto P_0c0385d8;
P_0c0385d8: /* original 035e, guest PC 0x0c0385d8 */
if(!s->budget--) { s->failed_pc=0x0c0385d8u; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c0385da;
P_0c0385da: /* original 6013, guest PC 0x0c0385da */
if(!s->budget--) { s->failed_pc=0x0c0385dau; return 0; }
r[0]=r[1];
goto P_0c0385dc;
P_0c0385dc: /* original 70ff, guest PC 0x0c0385dc */
if(!s->budget--) { s->failed_pc=0x0c0385dcu; return 0; }
r[0]+=0xffffffffu;
goto P_0c0385de;
P_0c0385de: /* original e500, guest PC 0x0c0385de */
if(!s->budget--) { s->failed_pc=0x0c0385deu; return 0; }
r[5]=0x00000000u;
goto P_0c0385e0;
P_0c0385e0: /* original 143b, guest PC 0x0c0385e0 */
if(!s->budget--) { s->failed_pc=0x0c0385e0u; return 0; }
write(ram,r[4]+44,r[3],4);
goto P_0c0385e2;
P_0c0385e2: /* original 8143, guest PC 0x0c0385e2 */
if(!s->budget--) { s->failed_pc=0x0c0385e2u; return 0; }
write(ram,r[4]+6,r[0],2);
goto P_0c0385e4;
P_0c0385e4: /* original 000b, guest PC 0x0c0385e4 */
if(!s->budget--) { s->failed_pc=0x0c0385e4u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c0385e6: /* original 6053, guest PC 0x0c0385e6 */
if(!s->budget--) { s->failed_pc=0x0c0385e6u; return 0; }
r[0]=r[5];
if(!vf3_matrix_family(0x0c0385e8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0385e8u; return 0; } return 1;
P_0c03b5c0: /* original fbfd, guest PC 0x0c03b5c0 */
if(!s->budget--) { s->failed_pc=0x0c03b5c0u; return 0; }
vf3_matrix_swap(s);
goto P_0c03b5c2;
P_0c03b5c2: /* original f3ed, guest PC 0x0c03b5c2 */
if(!s->budget--) { s->failed_pc=0x0c03b5c2u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c03b5c4;
P_0c03b5c4: /* original f7ed, guest PC 0x0c03b5c4 */
if(!s->budget--) { s->failed_pc=0x0c03b5c4u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c03b5c6;
P_0c03b5c6: /* original fbed, guest PC 0x0c03b5c6 */
if(!s->budget--) { s->failed_pc=0x0c03b5c6u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+8,r[18],fr+11)) goto unsupported;
goto P_0c03b5c8;
P_0c03b5c8: /* original fc3c, guest PC 0x0c03b5c8 */
if(!s->budget--) { s->failed_pc=0x0c03b5c8u; return 0; }
vf3_matrix_move(s,12,3);
goto P_0c03b5ca;
P_0c03b5ca: /* original f331, guest PC 0x0c03b5ca */
if(!s->budget--) { s->failed_pc=0x0c03b5cau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[3],r[18],'-');
goto P_0c03b5cc;
P_0c03b5cc: /* original fd7c, guest PC 0x0c03b5cc */
if(!s->budget--) { s->failed_pc=0x0c03b5ccu; return 0; }
vf3_matrix_move(s,13,7);
goto P_0c03b5ce;
P_0c03b5ce: /* original f771, guest PC 0x0c03b5ce */
if(!s->budget--) { s->failed_pc=0x0c03b5ceu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[7],r[18],'-');
goto P_0c03b5d0;
P_0c03b5d0: /* original febc, guest PC 0x0c03b5d0 */
if(!s->budget--) { s->failed_pc=0x0c03b5d0u; return 0; }
vf3_matrix_move(s,14,11);
goto P_0c03b5d2;
P_0c03b5d2: /* original fbb1, guest PC 0x0c03b5d2 */
if(!s->budget--) { s->failed_pc=0x0c03b5d2u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'-');
goto P_0c03b5d4;
P_0c03b5d4: /* original f0ed, guest PC 0x0c03b5d4 */
if(!s->budget--) { s->failed_pc=0x0c03b5d4u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c03b5d6;
P_0c03b5d6: /* original fc4d, guest PC 0x0c03b5d6 */
if(!s->budget--) { s->failed_pc=0x0c03b5d6u; return 0; }
fr[12]^=0x80000000u;
goto P_0c03b5d8;
P_0c03b5d8: /* original f5ed, guest PC 0x0c03b5d8 */
if(!s->budget--) { s->failed_pc=0x0c03b5d8u; return 0; }
if(!vf3_fpu_fipr(fr+4,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c03b5da;
P_0c03b5da: /* original fd4d, guest PC 0x0c03b5da */
if(!s->budget--) { s->failed_pc=0x0c03b5dau; return 0; }
fr[13]^=0x80000000u;
goto P_0c03b5dc;
P_0c03b5dc: /* original faed, guest PC 0x0c03b5dc */
if(!s->budget--) { s->failed_pc=0x0c03b5dcu; return 0; }
if(!vf3_fpu_fipr(fr+8,fr+8,r[18],fr+11)) goto unsupported;
goto P_0c03b5de;
P_0c03b5de: /* original fe4d, guest PC 0x0c03b5de */
if(!s->budget--) { s->failed_pc=0x0c03b5deu; return 0; }
fr[14]^=0x80000000u;
goto P_0c03b5e0;
P_0c03b5e0: /* original f37d, guest PC 0x0c03b5e0 */
if(!s->budget--) { s->failed_pc=0x0c03b5e0u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c03b5e2;
P_0c03b5e2: /* original f77d, guest PC 0x0c03b5e2 */
if(!s->budget--) { s->failed_pc=0x0c03b5e2u; return 0; }
if(!vf3_fpu_fsrra(fr[7],r[18],&fr[7])) goto unsupported;
goto P_0c03b5e4;
P_0c03b5e4: /* original fb7d, guest PC 0x0c03b5e4 */
if(!s->budget--) { s->failed_pc=0x0c03b5e4u; return 0; }
if(!vf3_fpu_fsrra(fr[11],r[18],&fr[11])) goto unsupported;
goto P_0c03b5e6;
P_0c03b5e6: /* original f132, guest PC 0x0c03b5e6 */
if(!s->budget--) { s->failed_pc=0x0c03b5e6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c03b5e8;
P_0c03b5e8: /* original f472, guest PC 0x0c03b5e8 */
if(!s->budget--) { s->failed_pc=0x0c03b5e8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c03b5ea;
P_0c03b5ea: /* original f232, guest PC 0x0c03b5ea */
if(!s->budget--) { s->failed_pc=0x0c03b5eau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03b5ec;
P_0c03b5ec: /* original f11d, guest PC 0x0c03b5ec */
if(!s->budget--) { s->failed_pc=0x0c03b5ecu; return 0; }
r[53]=fr[1];
goto P_0c03b5ee;
P_0c03b5ee: /* original f8b2, guest PC 0x0c03b5ee */
if(!s->budget--) { s->failed_pc=0x0c03b5eeu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[11],r[18],'*');
goto P_0c03b5f0;
P_0c03b5f0: /* original f14c, guest PC 0x0c03b5f0 */
if(!s->budget--) { s->failed_pc=0x0c03b5f0u; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c03b5f2;
P_0c03b5f2: /* original f672, guest PC 0x0c03b5f2 */
if(!s->budget--) { s->failed_pc=0x0c03b5f2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c03b5f4;
P_0c03b5f4: /* original f40d, guest PC 0x0c03b5f4 */
if(!s->budget--) { s->failed_pc=0x0c03b5f4u; return 0; }
fr[4]=r[53];
goto P_0c03b5f6;
P_0c03b5f6: /* original f9b2, guest PC 0x0c03b5f6 */
if(!s->budget--) { s->failed_pc=0x0c03b5f6u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[11],r[18],'*');
goto P_0c03b5f8;
P_0c03b5f8: /* original f21d, guest PC 0x0c03b5f8 */
if(!s->budget--) { s->failed_pc=0x0c03b5f8u; return 0; }
r[53]=fr[2];
goto P_0c03b5fa;
P_0c03b5fa: /* original f032, guest PC 0x0c03b5fa */
if(!s->budget--) { s->failed_pc=0x0c03b5fau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c03b5fc;
P_0c03b5fc: /* original f28c, guest PC 0x0c03b5fc */
if(!s->budget--) { s->failed_pc=0x0c03b5fcu; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c03b5fe;
P_0c03b5fe: /* original f572, guest PC 0x0c03b5fe */
if(!s->budget--) { s->failed_pc=0x0c03b5feu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c03b600;
P_0c03b600: /* original f80d, guest PC 0x0c03b600 */
if(!s->budget--) { s->failed_pc=0x0c03b600u; return 0; }
fr[8]=r[53];
goto P_0c03b602;
P_0c03b602: /* original fab2, guest PC 0x0c03b602 */
if(!s->budget--) { s->failed_pc=0x0c03b602u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[11],r[18],'*');
goto P_0c03b604;
P_0c03b604: /* original f61d, guest PC 0x0c03b604 */
if(!s->budget--) { s->failed_pc=0x0c03b604u; return 0; }
r[53]=fr[6];
goto P_0c03b606;
P_0c03b606: /* original fc32, guest PC 0x0c03b606 */
if(!s->budget--) { s->failed_pc=0x0c03b606u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'*');
goto P_0c03b608;
P_0c03b608: /* original f69c, guest PC 0x0c03b608 */
if(!s->budget--) { s->failed_pc=0x0c03b608u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c03b60a;
P_0c03b60a: /* original fd72, guest PC 0x0c03b60a */
if(!s->budget--) { s->failed_pc=0x0c03b60au; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[7],r[18],'*');
goto P_0c03b60c;
P_0c03b60c: /* original f90d, guest PC 0x0c03b60c */
if(!s->budget--) { s->failed_pc=0x0c03b60cu; return 0; }
fr[9]=r[53];
goto P_0c03b60e;
P_0c03b60e: /* original feb2, guest PC 0x0c03b60e */
if(!s->budget--) { s->failed_pc=0x0c03b60eu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[11],r[18],'*');
goto P_0c03b610;
P_0c03b610: /* original f38d, guest PC 0x0c03b610 */
if(!s->budget--) { s->failed_pc=0x0c03b610u; return 0; }
fr[3]=0;
goto P_0c03b612;
P_0c03b612: /* original f771, guest PC 0x0c03b612 */
if(!s->budget--) { s->failed_pc=0x0c03b612u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[7],r[18],'-');
goto P_0c03b614;
P_0c03b614: /* original fb8d, guest PC 0x0c03b614 */
if(!s->budget--) { s->failed_pc=0x0c03b614u; return 0; }
fr[11]=0;
goto P_0c03b616;
P_0c03b616: /* original fbfd, guest PC 0x0c03b616 */
if(!s->budget--) { s->failed_pc=0x0c03b616u; return 0; }
vf3_matrix_swap(s);
goto P_0c03b618;
P_0c03b618: /* original 000b, guest PC 0x0c03b618 */
if(!s->budget--) { s->failed_pc=0x0c03b618u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03b61a: /* original 0009, guest PC 0x0c03b61a */
if(!s->budget--) { s->failed_pc=0x0c03b61au; return 0; }
if(!vf3_matrix_family(0x0c03b61cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03b61cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
