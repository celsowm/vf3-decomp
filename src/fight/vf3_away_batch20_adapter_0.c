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
int vf3_away_batch20_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c036794u: goto P_0c036794;
case 0x0c036796u: goto P_0c036796;
case 0x0c036798u: goto P_0c036798;
case 0x0c0368aau: goto P_0c0368aa;
case 0x0c0368acu: goto P_0c0368ac;
case 0x0c0368aeu: goto P_0c0368ae;
case 0x0c0368b0u: goto P_0c0368b0;
case 0x0c0368b2u: goto P_0c0368b2;
case 0x0c0368b4u: goto P_0c0368b4;
case 0x0c0368b6u: goto P_0c0368b6;
case 0x0c0368b8u: goto P_0c0368b8;
case 0x0c0368bau: goto P_0c0368ba;
case 0x0c0368bcu: goto P_0c0368bc;
case 0x0c0368beu: goto P_0c0368be;
case 0x0c0368c0u: goto P_0c0368c0;
case 0x0c0368c2u: goto P_0c0368c2;
case 0x0c0368c4u: goto P_0c0368c4;
case 0x0c0368c6u: goto P_0c0368c6;
case 0x0c0368c8u: goto P_0c0368c8;
case 0x0c0368cau: goto P_0c0368ca;
case 0x0c0368ccu: goto P_0c0368cc;
case 0x0c0368ceu: goto P_0c0368ce;
case 0x0c0368d0u: goto P_0c0368d0;
case 0x0c0368d2u: goto P_0c0368d2;
case 0x0c0368d4u: goto P_0c0368d4;
case 0x0c0368d6u: goto P_0c0368d6;
case 0x0c0368d8u: goto P_0c0368d8;
case 0x0c0368dau: goto P_0c0368da;
case 0x0c0368dcu: goto P_0c0368dc;
case 0x0c0368deu: goto P_0c0368de;
case 0x0c0368e0u: goto P_0c0368e0;
case 0x0c0368e2u: goto P_0c0368e2;
case 0x0c0368e4u: goto P_0c0368e4;
case 0x0c0368e6u: goto P_0c0368e6;
case 0x0c0368e8u: goto P_0c0368e8;
case 0x0c0368eau: goto P_0c0368ea;
case 0x0c0368ecu: goto P_0c0368ec;
case 0x0c0368eeu: goto P_0c0368ee;
case 0x0c0368f0u: goto P_0c0368f0;
case 0x0c0368f2u: goto P_0c0368f2;
case 0x0c0368f4u: goto P_0c0368f4;
case 0x0c0368f6u: goto P_0c0368f6;
case 0x0c0368f8u: goto P_0c0368f8;
case 0x0c0368fau: goto P_0c0368fa;
case 0x0c0368fcu: goto P_0c0368fc;
case 0x0c0368feu: goto P_0c0368fe;
case 0x0c036900u: goto P_0c036900;
case 0x0c036902u: goto P_0c036902;
case 0x0c036904u: goto P_0c036904;
case 0x0c036906u: goto P_0c036906;
case 0x0c036908u: goto P_0c036908;
case 0x0c03690au: goto P_0c03690a;
case 0x0c03690cu: goto P_0c03690c;
case 0x0c03690eu: goto P_0c03690e;
case 0x0c036910u: goto P_0c036910;
case 0x0c036912u: goto P_0c036912;
case 0x0c036914u: goto P_0c036914;
case 0x0c036916u: goto P_0c036916;
case 0x0c036918u: goto P_0c036918;
case 0x0c03691au: goto P_0c03691a;
case 0x0c03691cu: goto P_0c03691c;
case 0x0c03691eu: goto P_0c03691e;
case 0x0c036920u: goto P_0c036920;
case 0x0c036922u: goto P_0c036922;
case 0x0c036924u: goto P_0c036924;
case 0x0c036926u: goto P_0c036926;
case 0x0c036928u: goto P_0c036928;
case 0x0c03692au: goto P_0c03692a;
case 0x0c03692cu: goto P_0c03692c;
case 0x0c03692eu: goto P_0c03692e;
case 0x0c036930u: goto P_0c036930;
case 0x0c036932u: goto P_0c036932;
case 0x0c036934u: goto P_0c036934;
case 0x0c036936u: goto P_0c036936;
case 0x0c036938u: goto P_0c036938;
case 0x0c03693au: goto P_0c03693a;
case 0x0c03693cu: goto P_0c03693c;
case 0x0c03693eu: goto P_0c03693e;
case 0x0c036940u: goto P_0c036940;
case 0x0c036942u: goto P_0c036942;
case 0x0c036944u: goto P_0c036944;
case 0x0c036946u: goto P_0c036946;
case 0x0c036948u: goto P_0c036948;
case 0x0c03694au: goto P_0c03694a;
case 0x0c03694cu: goto P_0c03694c;
case 0x0c03694eu: goto P_0c03694e;
case 0x0c036950u: goto P_0c036950;
case 0x0c036952u: goto P_0c036952;
case 0x0c036954u: goto P_0c036954;
case 0x0c036956u: goto P_0c036956;
case 0x0c036958u: goto P_0c036958;
case 0x0c03695au: goto P_0c03695a;
case 0x0c03695cu: goto P_0c03695c;
case 0x0c03695eu: goto P_0c03695e;
case 0x0c036960u: goto P_0c036960;
case 0x0c036962u: goto P_0c036962;
case 0x0c036964u: goto P_0c036964;
case 0x0c036966u: goto P_0c036966;
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
P_0c036794: /* original d374, guest PC 0x0c036794 */
if(!s->budget--) { s->failed_pc=0x0c036794u; return 0; }
r[3]=read(ram,0x0c036968u,4);
goto P_0c036796;
P_0c036796: /* original 432b, guest PC 0x0c036796 */
if(!s->budget--) { s->failed_pc=0x0c036796u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c036db8u: return vf3_matrix_family(0x0c036db8u,s,ram);
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
P_0c036798: /* original 0009, guest PC 0x0c036798 */
if(!s->budget--) { s->failed_pc=0x0c036798u; return 0; }
if(!vf3_matrix_family(0x0c03679au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03679au; return 0; } return 1;
P_0c0368aa: /* original 000b, guest PC 0x0c0368aa */
if(!s->budget--) { s->failed_pc=0x0c0368aau; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c0368ac: /* original e000, guest PC 0x0c0368ac */
if(!s->budget--) { s->failed_pc=0x0c0368acu; return 0; }
r[0]=0x00000000u;
goto P_0c0368ae;
P_0c0368ae: /* original affc, guest PC 0x0c0368ae */
if(!s->budget--) { s->failed_pc=0x0c0368aeu; return 0; }
goto P_0c0368aa;
P_0c0368b0: /* original 0009, guest PC 0x0c0368b0 */
if(!s->budget--) { s->failed_pc=0x0c0368b0u; return 0; }
goto P_0c0368b2;
P_0c0368b2: /* original 2fe6, guest PC 0x0c0368b2 */
if(!s->budget--) { s->failed_pc=0x0c0368b2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0368b4;
P_0c0368b4: /* original 2fd6, guest PC 0x0c0368b4 */
if(!s->budget--) { s->failed_pc=0x0c0368b4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0368b6;
P_0c0368b6: /* original 2fc6, guest PC 0x0c0368b6 */
if(!s->budget--) { s->failed_pc=0x0c0368b6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0368b8;
P_0c0368b8: /* original 2fb6, guest PC 0x0c0368b8 */
if(!s->budget--) { s->failed_pc=0x0c0368b8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0368ba;
P_0c0368ba: /* original 2fa6, guest PC 0x0c0368ba */
if(!s->budget--) { s->failed_pc=0x0c0368bau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0368bc;
P_0c0368bc: /* original 2f96, guest PC 0x0c0368bc */
if(!s->budget--) { s->failed_pc=0x0c0368bcu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0368be;
P_0c0368be: /* original d439, guest PC 0x0c0368be */
if(!s->budget--) { s->failed_pc=0x0c0368beu; return 0; }
r[4]=read(ram,0x0c0369a4u,4);
goto P_0c0368c0;
P_0c0368c0: /* original 4f22, guest PC 0x0c0368c0 */
if(!s->budget--) { s->failed_pc=0x0c0368c0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0368c2;
P_0c0368c2: /* original 6342, guest PC 0x0c0368c2 */
if(!s->budget--) { s->failed_pc=0x0c0368c2u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0368c4;
P_0c0368c4: /* original d238, guest PC 0x0c0368c4 */
if(!s->budget--) { s->failed_pc=0x0c0368c4u; return 0; }
r[2]=read(ram,0x0c0369a8u,4);
goto P_0c0368c6;
P_0c0368c6: /* original 7301, guest PC 0x0c0368c6 */
if(!s->budget--) { s->failed_pc=0x0c0368c6u; return 0; }
r[3]+=0x00000001u;
goto P_0c0368c8;
P_0c0368c8: /* original 420b, guest PC 0x0c0368c8 */
if(!s->budget--) { s->failed_pc=0x0c0368c8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0368ccu;
write(ram,r[4],r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0368ccu) { target=s->pc; goto dispatch; }
goto P_0c0368cc;
P_0c0368ca: /* original 2432, guest PC 0x0c0368ca */
if(!s->budget--) { s->failed_pc=0x0c0368cau; return 0; }
write(ram,r[4],r[3],4);
goto P_0c0368cc;
P_0c0368cc: /* original d238, guest PC 0x0c0368cc */
if(!s->budget--) { s->failed_pc=0x0c0368ccu; return 0; }
r[2]=read(ram,0x0c0369b0u,4);
goto P_0c0368ce;
P_0c0368ce: /* original d137, guest PC 0x0c0368ce */
if(!s->budget--) { s->failed_pc=0x0c0368ceu; return 0; }
r[1]=read(ram,0x0c0369acu,4);
goto P_0c0368d0;
P_0c0368d0: /* original 6322, guest PC 0x0c0368d0 */
if(!s->budget--) { s->failed_pc=0x0c0368d0u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0368d2;
P_0c0368d2: /* original 2132, guest PC 0x0c0368d2 */
if(!s->budget--) { s->failed_pc=0x0c0368d2u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c0368d4;
P_0c0368d4: /* original ea00, guest PC 0x0c0368d4 */
if(!s->budget--) { s->failed_pc=0x0c0368d4u; return 0; }
r[10]=0x00000000u;
goto P_0c0368d6;
P_0c0368d6: /* original dd39, guest PC 0x0c0368d6 */
if(!s->budget--) { s->failed_pc=0x0c0368d6u; return 0; }
r[13]=read(ram,0x0c0369bcu,4);
goto P_0c0368d8;
P_0c0368d8: /* original e902, guest PC 0x0c0368d8 */
if(!s->budget--) { s->failed_pc=0x0c0368d8u; return 0; }
r[9]=0x00000002u;
goto P_0c0368da;
P_0c0368da: /* original db37, guest PC 0x0c0368da */
if(!s->budget--) { s->failed_pc=0x0c0368dau; return 0; }
r[11]=read(ram,0x0c0369b8u,4);
goto P_0c0368dc;
P_0c0368dc: /* original dc38, guest PC 0x0c0368dc */
if(!s->budget--) { s->failed_pc=0x0c0368dcu; return 0; }
r[12]=read(ram,0x0c0369c0u,4);
goto P_0c0368de;
P_0c0368de: /* original de35, guest PC 0x0c0368de */
if(!s->budget--) { s->failed_pc=0x0c0368deu; return 0; }
r[14]=read(ram,0x0c0369b4u,4);
goto P_0c0368e0;
P_0c0368e0: /* original bf58, guest PC 0x0c0368e0 */
if(!s->budget--) { s->failed_pc=0x0c0368e0u; return 0; }
target=code_base|0x0c036794u; r[16]=code_base|0x0c0368e4u;
tmp=read(ram,r[12],4);
r[12]+=4;
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0368e4u) { target=s->pc; goto dispatch; }
goto P_0c0368e4;
P_0c0368e2: /* original 64c6, guest PC 0x0c0368e2 */
if(!s->budget--) { s->failed_pc=0x0c0368e2u; return 0; }
tmp=read(ram,r[12],4);
r[12]+=4;
r[4]=tmp;
goto P_0c0368e4;
P_0c0368e4: /* original 6403, guest PC 0x0c0368e4 */
if(!s->budget--) { s->failed_pc=0x0c0368e4u; return 0; }
r[4]=r[0];
goto P_0c0368e6;
P_0c0368e6: /* original 60b1, guest PC 0x0c0368e6 */
if(!s->budget--) { s->failed_pc=0x0c0368e6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[11],2);
r[0]=tmp;
goto P_0c0368e8;
P_0c0368e8: /* original e2f8, guest PC 0x0c0368e8 */
if(!s->budget--) { s->failed_pc=0x0c0368e8u; return 0; }
r[2]=0xfffffff8u;
goto P_0c0368ea;
P_0c0368ea: /* original 81e2, guest PC 0x0c0368ea */
if(!s->budget--) { s->failed_pc=0x0c0368eau; return 0; }
write(ram,r[14]+4,r[0],2);
goto P_0c0368ec;
P_0c0368ec: /* original 5542, guest PC 0x0c0368ec */
if(!s->budget--) { s->failed_pc=0x0c0368ecu; return 0; }
r[5]=read(ram,r[4]+8,4);
goto P_0c0368ee;
P_0c0368ee: /* original 655d, guest PC 0x0c0368ee */
if(!s->budget--) { s->failed_pc=0x0c0368eeu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0368f0;
P_0c0368f0: /* original 6353, guest PC 0x0c0368f0 */
if(!s->budget--) { s->failed_pc=0x0c0368f0u; return 0; }
r[3]=r[5];
goto P_0c0368f2;
P_0c0368f2: /* original 6053, guest PC 0x0c0368f2 */
if(!s->budget--) { s->failed_pc=0x0c0368f2u; return 0; }
r[0]=r[5];
goto P_0c0368f4;
P_0c0368f4: /* original 432c, guest PC 0x0c0368f4 */
if(!s->budget--) { s->failed_pc=0x0c0368f4u; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c0368f6;
P_0c0368f6: /* original 4018, guest PC 0x0c0368f6 */
if(!s->budget--) { s->failed_pc=0x0c0368f6u; return 0; }
r[0]<<=8;
goto P_0c0368f8;
P_0c0368f8: /* original 633c, guest PC 0x0c0368f8 */
if(!s->budget--) { s->failed_pc=0x0c0368f8u; return 0; }
r[3]=r[3]&255u;
goto P_0c0368fa;
P_0c0368fa: /* original 20d9, guest PC 0x0c0368fa */
if(!s->budget--) { s->failed_pc=0x0c0368fau; return 0; }
r[0]&=r[13];
goto P_0c0368fc;
P_0c0368fc: /* original 203b, guest PC 0x0c0368fc */
if(!s->budget--) { s->failed_pc=0x0c0368fcu; return 0; }
r[0]|=r[3];
goto P_0c0368fe;
P_0c0368fe: /* original 81e1, guest PC 0x0c0368fe */
if(!s->budget--) { s->failed_pc=0x0c0368feu; return 0; }
write(ram,r[14]+2,r[0],2);
goto P_0c036900;
P_0c036900: /* original 5544, guest PC 0x0c036900 */
if(!s->budget--) { s->failed_pc=0x0c036900u; return 0; }
r[5]=read(ram,r[4]+16,4);
goto P_0c036902;
P_0c036902: /* original 655d, guest PC 0x0c036902 */
if(!s->budget--) { s->failed_pc=0x0c036902u; return 0; }
r[5]=r[5]&65535u;
goto P_0c036904;
P_0c036904: /* original 6353, guest PC 0x0c036904 */
if(!s->budget--) { s->failed_pc=0x0c036904u; return 0; }
r[3]=r[5];
goto P_0c036906;
P_0c036906: /* original 6053, guest PC 0x0c036906 */
if(!s->budget--) { s->failed_pc=0x0c036906u; return 0; }
r[0]=r[5];
goto P_0c036908;
P_0c036908: /* original 432c, guest PC 0x0c036908 */
if(!s->budget--) { s->failed_pc=0x0c036908u; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c03690a;
P_0c03690a: /* original 4018, guest PC 0x0c03690a */
if(!s->budget--) { s->failed_pc=0x0c03690au; return 0; }
r[0]<<=8;
goto P_0c03690c;
P_0c03690c: /* original 633c, guest PC 0x0c03690c */
if(!s->budget--) { s->failed_pc=0x0c03690cu; return 0; }
r[3]=r[3]&255u;
goto P_0c03690e;
P_0c03690e: /* original 20d9, guest PC 0x0c03690e */
if(!s->budget--) { s->failed_pc=0x0c03690eu; return 0; }
r[0]&=r[13];
goto P_0c036910;
P_0c036910: /* original 203b, guest PC 0x0c036910 */
if(!s->budget--) { s->failed_pc=0x0c036910u; return 0; }
r[0]|=r[3];
goto P_0c036912;
P_0c036912: /* original 81e3, guest PC 0x0c036912 */
if(!s->budget--) { s->failed_pc=0x0c036912u; return 0; }
write(ram,r[14]+6,r[0],2);
goto P_0c036914;
P_0c036914: /* original 5545, guest PC 0x0c036914 */
if(!s->budget--) { s->failed_pc=0x0c036914u; return 0; }
r[5]=read(ram,r[4]+20,4);
goto P_0c036916;
P_0c036916: /* original 655d, guest PC 0x0c036916 */
if(!s->budget--) { s->failed_pc=0x0c036916u; return 0; }
r[5]=r[5]&65535u;
goto P_0c036918;
P_0c036918: /* original 6353, guest PC 0x0c036918 */
if(!s->budget--) { s->failed_pc=0x0c036918u; return 0; }
r[3]=r[5];
goto P_0c03691a;
P_0c03691a: /* original 6053, guest PC 0x0c03691a */
if(!s->budget--) { s->failed_pc=0x0c03691au; return 0; }
r[0]=r[5];
goto P_0c03691c;
P_0c03691c: /* original 432c, guest PC 0x0c03691c */
if(!s->budget--) { s->failed_pc=0x0c03691cu; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c03691e;
P_0c03691e: /* original 4018, guest PC 0x0c03691e */
if(!s->budget--) { s->failed_pc=0x0c03691eu; return 0; }
r[0]<<=8;
goto P_0c036920;
P_0c036920: /* original 633c, guest PC 0x0c036920 */
if(!s->budget--) { s->failed_pc=0x0c036920u; return 0; }
r[3]=r[3]&255u;
goto P_0c036922;
P_0c036922: /* original 20d9, guest PC 0x0c036922 */
if(!s->budget--) { s->failed_pc=0x0c036922u; return 0; }
r[0]&=r[13];
goto P_0c036924;
P_0c036924: /* original 203b, guest PC 0x0c036924 */
if(!s->budget--) { s->failed_pc=0x0c036924u; return 0; }
r[0]|=r[3];
goto P_0c036926;
P_0c036926: /* original 81e4, guest PC 0x0c036926 */
if(!s->budget--) { s->failed_pc=0x0c036926u; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c036928;
P_0c036928: /* original 7a01, guest PC 0x0c036928 */
if(!s->budget--) { s->failed_pc=0x0c036928u; return 0; }
r[10]+=0x00000001u;
goto P_0c03692a;
P_0c03692a: /* original 854c, guest PC 0x0c03692a */
if(!s->budget--) { s->failed_pc=0x0c03692au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+24,2);
goto P_0c03692c;
P_0c03692c: /* original 3a93, guest PC 0x0c03692c */
if(!s->budget--) { s->failed_pc=0x0c03692cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[9])!=0);
goto P_0c03692e;
P_0c03692e: /* original 80ea, guest PC 0x0c03692e */
if(!s->budget--) { s->failed_pc=0x0c03692eu; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c036930;
P_0c036930: /* original 854d, guest PC 0x0c036930 */
if(!s->budget--) { s->failed_pc=0x0c036930u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+26,2);
goto P_0c036932;
P_0c036932: /* original 80eb, guest PC 0x0c036932 */
if(!s->budget--) { s->failed_pc=0x0c036932u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c036934;
P_0c036934: /* original 854e, guest PC 0x0c036934 */
if(!s->budget--) { s->failed_pc=0x0c036934u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+28,2);
goto P_0c036936;
P_0c036936: /* original 80ec, guest PC 0x0c036936 */
if(!s->budget--) { s->failed_pc=0x0c036936u; return 0; }
write(ram,r[14]+12,r[0],1);
goto P_0c036938;
P_0c036938: /* original 854f, guest PC 0x0c036938 */
if(!s->budget--) { s->failed_pc=0x0c036938u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+30,2);
goto P_0c03693a;
P_0c03693a: /* original 80ed, guest PC 0x0c03693a */
if(!s->budget--) { s->failed_pc=0x0c03693au; return 0; }
write(ram,r[14]+13,r[0],1);
goto P_0c03693c;
P_0c03693c: /* original e020, guest PC 0x0c03693c */
if(!s->budget--) { s->failed_pc=0x0c03693cu; return 0; }
r[0]=0x00000020u;
goto P_0c03693e;
P_0c03693e: /* original 004c, guest PC 0x0c03693e */
if(!s->budget--) { s->failed_pc=0x0c03693eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c036940;
P_0c036940: /* original 80ee, guest PC 0x0c036940 */
if(!s->budget--) { s->failed_pc=0x0c036940u; return 0; }
write(ram,r[14]+14,r[0],1);
goto P_0c036942;
P_0c036942: /* original e022, guest PC 0x0c036942 */
if(!s->budget--) { s->failed_pc=0x0c036942u; return 0; }
r[0]=0x00000022u;
goto P_0c036944;
P_0c036944: /* original 004c, guest PC 0x0c036944 */
if(!s->budget--) { s->failed_pc=0x0c036944u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c036946;
P_0c036946: /* original 80ef, guest PC 0x0c036946 */
if(!s->budget--) { s->failed_pc=0x0c036946u; return 0; }
write(ram,r[14]+15,r[0],1);
goto P_0c036948;
P_0c036948: /* original 85e1, guest PC 0x0c036948 */
if(!s->budget--) { s->failed_pc=0x0c036948u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c03694a;
P_0c03694a: /* original 2b01, guest PC 0x0c03694a */
if(!s->budget--) { s->failed_pc=0x0c03694au; return 0; }
write(ram,r[11],r[0],2);
goto P_0c03694c;
P_0c03694c: /* original 8fc8, guest PC 0x0c03694c */
if(!s->budget--) { s->failed_pc=0x0c03694cu; return 0; }
cond=r[17]&1u;
r[14]+=0x00000010u;
if(!cond) { goto P_0c0368e0; }
goto P_0c036950;
P_0c03694e: /* original 7e10, guest PC 0x0c03694e */
if(!s->budget--) { s->failed_pc=0x0c03694eu; return 0; }
r[14]+=0x00000010u;
goto P_0c036950;
P_0c036950: /* original d117, guest PC 0x0c036950 */
if(!s->budget--) { s->failed_pc=0x0c036950u; return 0; }
r[1]=read(ram,0x0c0369b0u,4);
goto P_0c036952;
P_0c036952: /* original d21c, guest PC 0x0c036952 */
if(!s->budget--) { s->failed_pc=0x0c036952u; return 0; }
r[2]=read(ram,0x0c0369c4u,4);
goto P_0c036954;
P_0c036954: /* original 6312, guest PC 0x0c036954 */
if(!s->budget--) { s->failed_pc=0x0c036954u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c036956;
P_0c036956: /* original 4f26, guest PC 0x0c036956 */
if(!s->budget--) { s->failed_pc=0x0c036956u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c036958;
P_0c036958: /* original 2232, guest PC 0x0c036958 */
if(!s->budget--) { s->failed_pc=0x0c036958u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c03695a;
P_0c03695a: /* original 69f6, guest PC 0x0c03695a */
if(!s->budget--) { s->failed_pc=0x0c03695au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03695c;
P_0c03695c: /* original 6af6, guest PC 0x0c03695c */
if(!s->budget--) { s->failed_pc=0x0c03695cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03695e;
P_0c03695e: /* original 6bf6, guest PC 0x0c03695e */
if(!s->budget--) { s->failed_pc=0x0c03695eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c036960;
P_0c036960: /* original 6cf6, guest PC 0x0c036960 */
if(!s->budget--) { s->failed_pc=0x0c036960u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c036962;
P_0c036962: /* original 6df6, guest PC 0x0c036962 */
if(!s->budget--) { s->failed_pc=0x0c036962u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c036964;
P_0c036964: /* original 000b, guest PC 0x0c036964 */
if(!s->budget--) { s->failed_pc=0x0c036964u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c036966: /* original 6ef6, guest PC 0x0c036966 */
if(!s->budget--) { s->failed_pc=0x0c036966u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c036968u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c036968u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
