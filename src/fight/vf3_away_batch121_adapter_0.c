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
int vf3_away_batch121_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c038600u: goto P_0c038600;
case 0x0c038602u: goto P_0c038602;
case 0x0c038604u: goto P_0c038604;
case 0x0c038606u: goto P_0c038606;
case 0x0c038608u: goto P_0c038608;
case 0x0c03860au: goto P_0c03860a;
case 0x0c03860cu: goto P_0c03860c;
case 0x0c03860eu: goto P_0c03860e;
case 0x0c038610u: goto P_0c038610;
case 0x0c038612u: goto P_0c038612;
case 0x0c038614u: goto P_0c038614;
case 0x0c038616u: goto P_0c038616;
case 0x0c038618u: goto P_0c038618;
case 0x0c03861au: goto P_0c03861a;
case 0x0c03861cu: goto P_0c03861c;
case 0x0c03861eu: goto P_0c03861e;
case 0x0c038620u: goto P_0c038620;
case 0x0c038622u: goto P_0c038622;
case 0x0c038624u: goto P_0c038624;
case 0x0c038626u: goto P_0c038626;
case 0x0c038628u: goto P_0c038628;
case 0x0c03862au: goto P_0c03862a;
case 0x0c03862cu: goto P_0c03862c;
case 0x0c03862eu: goto P_0c03862e;
case 0x0c038630u: goto P_0c038630;
case 0x0c038632u: goto P_0c038632;
case 0x0c038634u: goto P_0c038634;
case 0x0c038636u: goto P_0c038636;
case 0x0c038638u: goto P_0c038638;
case 0x0c03863au: goto P_0c03863a;
case 0x0c03863cu: goto P_0c03863c;
case 0x0c03863eu: goto P_0c03863e;
case 0x0c038640u: goto P_0c038640;
case 0x0c038642u: goto P_0c038642;
case 0x0c038644u: goto P_0c038644;
case 0x0c038646u: goto P_0c038646;
case 0x0c038648u: goto P_0c038648;
case 0x0c03864au: goto P_0c03864a;
case 0x0c03864cu: goto P_0c03864c;
case 0x0c03864eu: goto P_0c03864e;
case 0x0c038650u: goto P_0c038650;
case 0x0c038652u: goto P_0c038652;
case 0x0c038654u: goto P_0c038654;
case 0x0c038656u: goto P_0c038656;
case 0x0c038658u: goto P_0c038658;
case 0x0c03865au: goto P_0c03865a;
case 0x0c03865cu: goto P_0c03865c;
case 0x0c038760u: goto P_0c038760;
case 0x0c038762u: goto P_0c038762;
case 0x0c038764u: goto P_0c038764;
case 0x0c038860u: goto P_0c038860;
case 0x0c038862u: goto P_0c038862;
case 0x0c038864u: goto P_0c038864;
case 0x0c038866u: goto P_0c038866;
case 0x0c038868u: goto P_0c038868;
case 0x0c03886au: goto P_0c03886a;
case 0x0c03886cu: goto P_0c03886c;
case 0x0c03886eu: goto P_0c03886e;
case 0x0c038870u: goto P_0c038870;
case 0x0c038872u: goto P_0c038872;
case 0x0c038874u: goto P_0c038874;
case 0x0c038876u: goto P_0c038876;
case 0x0c038878u: goto P_0c038878;
case 0x0c03887au: goto P_0c03887a;
case 0x0c03887cu: goto P_0c03887c;
case 0x0c038880u: goto P_0c038880;
case 0x0c038882u: goto P_0c038882;
case 0x0c038884u: goto P_0c038884;
case 0x0c038886u: goto P_0c038886;
case 0x0c038888u: goto P_0c038888;
case 0x0c03888au: goto P_0c03888a;
case 0x0c03888cu: goto P_0c03888c;
case 0x0c03888eu: goto P_0c03888e;
case 0x0c038890u: goto P_0c038890;
case 0x0c038892u: goto P_0c038892;
case 0x0c038894u: goto P_0c038894;
case 0x0c038896u: goto P_0c038896;
case 0x0c038898u: goto P_0c038898;
case 0x0c03889au: goto P_0c03889a;
case 0x0c03889cu: goto P_0c03889c;
case 0x0c03889eu: goto P_0c03889e;
case 0x0c0388a0u: goto P_0c0388a0;
case 0x0c0388b0u: goto P_0c0388b0;
case 0x0c0388b2u: goto P_0c0388b2;
case 0x0c0388b4u: goto P_0c0388b4;
case 0x0c0388c0u: goto P_0c0388c0;
case 0x0c0388c2u: goto P_0c0388c2;
case 0x0c0388c4u: goto P_0c0388c4;
case 0x0c0388c6u: goto P_0c0388c6;
case 0x0c0388c8u: goto P_0c0388c8;
case 0x0c0388cau: goto P_0c0388ca;
case 0x0c0388ccu: goto P_0c0388cc;
case 0x0c0388ceu: goto P_0c0388ce;
case 0x0c0388d0u: goto P_0c0388d0;
case 0x0c0388d2u: goto P_0c0388d2;
case 0x0c0388d4u: goto P_0c0388d4;
case 0x0c0388d6u: goto P_0c0388d6;
case 0x0c0388d8u: goto P_0c0388d8;
case 0x0c0388dau: goto P_0c0388da;
case 0x0c0388dcu: goto P_0c0388dc;
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
P_0c038600: /* original 2fe6, guest PC 0x0c038600 */
if(!s->budget--) { s->failed_pc=0x0c038600u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038602;
P_0c038602: /* original 6e43, guest PC 0x0c038602 */
if(!s->budget--) { s->failed_pc=0x0c038602u; return 0; }
r[14]=r[4];
goto P_0c038604;
P_0c038604: /* original 2fd6, guest PC 0x0c038604 */
if(!s->budget--) { s->failed_pc=0x0c038604u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038606;
P_0c038606: /* original ed3c, guest PC 0x0c038606 */
if(!s->budget--) { s->failed_pc=0x0c038606u; return 0; }
r[13]=0x0000003cu;
goto P_0c038608;
P_0c038608: /* original 4f22, guest PC 0x0c038608 */
if(!s->budget--) { s->failed_pc=0x0c038608u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03860a;
P_0c03860a: /* original 4f12, guest PC 0x0c03860a */
if(!s->budget--) { s->failed_pc=0x0c03860au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03860c;
P_0c03860c: /* original 05d7, guest PC 0x0c03860c */
if(!s->budget--) { s->failed_pc=0x0c03860cu; return 0; }
r[19]=r[5]*r[13];
goto P_0c03860e;
P_0c03860e: /* original 7ff8, guest PC 0x0c03860e */
if(!s->budget--) { s->failed_pc=0x0c03860eu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c038610;
P_0c038610: /* original 2f62, guest PC 0x0c038610 */
if(!s->budget--) { s->failed_pc=0x0c038610u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c038612;
P_0c038612: /* original 0d1a, guest PC 0x0c038612 */
if(!s->budget--) { s->failed_pc=0x0c038612u; return 0; }
r[13]=r[19];
goto P_0c038614;
P_0c038614: /* original 1fd1, guest PC 0x0c038614 */
if(!s->budget--) { s->failed_pc=0x0c038614u; return 0; }
write(ram,r[15]+4,r[13],4);
goto P_0c038616;
P_0c038616: /* original d284, guest PC 0x0c038616 */
if(!s->budget--) { s->failed_pc=0x0c038616u; return 0; }
r[2]=read(ram,0x0c038828u,4);
goto P_0c038618;
P_0c038618: /* original d484, guest PC 0x0c038618 */
if(!s->budget--) { s->failed_pc=0x0c038618u; return 0; }
r[4]=read(ram,0x0c03882cu,4);
goto P_0c03861a;
P_0c03861a: /* original 6322, guest PC 0x0c03861a */
if(!s->budget--) { s->failed_pc=0x0c03861au; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03861c;
P_0c03861c: /* original 6142, guest PC 0x0c03861c */
if(!s->budget--) { s->failed_pc=0x0c03861cu; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c03861e;
P_0c03861e: /* original 3d3c, guest PC 0x0c03861e */
if(!s->budget--) { s->failed_pc=0x0c03861eu; return 0; }
r[13]+=r[3];
goto P_0c038620;
P_0c038620: /* original 7101, guest PC 0x0c038620 */
if(!s->budget--) { s->failed_pc=0x0c038620u; return 0; }
r[1]+=0x00000001u;
goto P_0c038622;
P_0c038622: /* original 2412, guest PC 0x0c038622 */
if(!s->budget--) { s->failed_pc=0x0c038622u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c038624;
P_0c038624: /* original 85e1, guest PC 0x0c038624 */
if(!s->budget--) { s->failed_pc=0x0c038624u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c038626;
P_0c038626: /* original 57e1, guest PC 0x0c038626 */
if(!s->budget--) { s->failed_pc=0x0c038626u; return 0; }
r[7]=read(ram,r[14]+4,4);
goto P_0c038628;
P_0c038628: /* original 65e1, guest PC 0x0c038628 */
if(!s->budget--) { s->failed_pc=0x0c038628u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[5]=tmp;
goto P_0c03862a;
P_0c03862a: /* original 6603, guest PC 0x0c03862a */
if(!s->budget--) { s->failed_pc=0x0c03862au; return 0; }
r[6]=r[0];
goto P_0c03862c;
P_0c03862c: /* original d380, guest PC 0x0c03862c */
if(!s->budget--) { s->failed_pc=0x0c03862cu; return 0; }
r[3]=read(ram,0x0c038830u,4);
goto P_0c03862e;
P_0c03862e: /* original 430b, guest PC 0x0c03862e */
if(!s->budget--) { s->failed_pc=0x0c03862eu; return 0; }
target=r[3];
r[16]=code_base|0x0c038632u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c038632u) { target=s->pc; goto dispatch; }
goto P_0c038632;
P_0c038630: /* original 64d3, guest PC 0x0c038630 */
if(!s->budget--) { s->failed_pc=0x0c038630u; return 0; }
r[4]=r[13];
goto P_0c038632;
P_0c038632: /* original 6403, guest PC 0x0c038632 */
if(!s->budget--) { s->failed_pc=0x0c038632u; return 0; }
r[4]=r[0];
goto P_0c038634;
P_0c038634: /* original 2448, guest PC 0x0c038634 */
if(!s->budget--) { s->failed_pc=0x0c038634u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c038636;
P_0c038636: /* original 8f0b, guest PC 0x0c038636 */
if(!s->budget--) { s->failed_pc=0x0c038636u; return 0; }
cond=r[17]&1u;
write(ram,r[13]+40,r[0],4);
if(!cond) { goto P_0c038650; }
goto P_0c03863a;
P_0c038638: /* original 1d0a, guest PC 0x0c038638 */
if(!s->budget--) { s->failed_pc=0x0c038638u; return 0; }
write(ram,r[13]+40,r[0],4);
goto P_0c03863a;
P_0c03863a: /* original d27b, guest PC 0x0c03863a */
if(!s->budget--) { s->failed_pc=0x0c03863au; return 0; }
r[2]=read(ram,0x0c038828u,4);
goto P_0c03863c;
P_0c03863c: /* original e700, guest PC 0x0c03863c */
if(!s->budget--) { s->failed_pc=0x0c03863cu; return 0; }
r[7]=0x00000000u;
goto P_0c03863e;
P_0c03863e: /* original 54f1, guest PC 0x0c03863e */
if(!s->budget--) { s->failed_pc=0x0c03863eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c038640;
P_0c038640: /* original 6322, guest PC 0x0c038640 */
if(!s->budget--) { s->failed_pc=0x0c038640u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c038642;
P_0c038642: /* original 65f2, guest PC 0x0c038642 */
if(!s->budget--) { s->failed_pc=0x0c038642u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c038644;
P_0c038644: /* original 343c, guest PC 0x0c038644 */
if(!s->budget--) { s->failed_pc=0x0c038644u; return 0; }
r[4]+=r[3];
goto P_0c038646;
P_0c038646: /* original d37b, guest PC 0x0c038646 */
if(!s->budget--) { s->failed_pc=0x0c038646u; return 0; }
r[3]=read(ram,0x0c038834u,4);
goto P_0c038648;
P_0c038648: /* original 430b, guest PC 0x0c038648 */
if(!s->budget--) { s->failed_pc=0x0c038648u; return 0; }
target=r[3];
r[16]=code_base|0x0c03864cu;
r[6]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03864cu) { target=s->pc; goto dispatch; }
goto P_0c03864c;
P_0c03864a: /* original 6673, guest PC 0x0c03864a */
if(!s->budget--) { s->failed_pc=0x0c03864au; return 0; }
r[6]=r[7];
goto P_0c03864c;
P_0c03864c: /* original a001, guest PC 0x0c03864c */
if(!s->budget--) { s->failed_pc=0x0c03864cu; return 0; }
r[0]=0x00000000u;
goto P_0c038652;
P_0c03864e: /* original e000, guest PC 0x0c03864e */
if(!s->budget--) { s->failed_pc=0x0c03864eu; return 0; }
r[0]=0x00000000u;
goto P_0c038650;
P_0c038650: /* original e001, guest PC 0x0c038650 */
if(!s->budget--) { s->failed_pc=0x0c038650u; return 0; }
r[0]=0x00000001u;
goto P_0c038652;
P_0c038652: /* original 7f08, guest PC 0x0c038652 */
if(!s->budget--) { s->failed_pc=0x0c038652u; return 0; }
r[15]+=0x00000008u;
goto P_0c038654;
P_0c038654: /* original 4f16, guest PC 0x0c038654 */
if(!s->budget--) { s->failed_pc=0x0c038654u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c038656;
P_0c038656: /* original 4f26, guest PC 0x0c038656 */
if(!s->budget--) { s->failed_pc=0x0c038656u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c038658;
P_0c038658: /* original 6df6, guest PC 0x0c038658 */
if(!s->budget--) { s->failed_pc=0x0c038658u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03865a;
P_0c03865a: /* original 000b, guest PC 0x0c03865a */
if(!s->budget--) { s->failed_pc=0x0c03865au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03865c: /* original 6ef6, guest PC 0x0c03865c */
if(!s->budget--) { s->failed_pc=0x0c03865cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03865eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03865eu; return 0; } return 1;
P_0c038760: /* original d23a, guest PC 0x0c038760 */
if(!s->budget--) { s->failed_pc=0x0c038760u; return 0; }
r[2]=read(ram,0x0c03884cu,4);
goto P_0c038762;
P_0c038762: /* original 000b, guest PC 0x0c038762 */
if(!s->budget--) { s->failed_pc=0x0c038762u; return 0; }
target=r[16];
write(ram,r[2],r[4],4);
s->pc=target; return ram->oob==0;
P_0c038764: /* original 2242, guest PC 0x0c038764 */
if(!s->budget--) { s->failed_pc=0x0c038764u; return 0; }
write(ram,r[2],r[4],4);
if(!vf3_matrix_family(0x0c038766u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038766u; return 0; } return 1;
P_0c038860: /* original 2fe6, guest PC 0x0c038860 */
if(!s->budget--) { s->failed_pc=0x0c038860u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038862;
P_0c038862: /* original e700, guest PC 0x0c038862 */
if(!s->budget--) { s->failed_pc=0x0c038862u; return 0; }
r[7]=0x00000000u;
goto P_0c038864;
P_0c038864: /* original 2fd6, guest PC 0x0c038864 */
if(!s->budget--) { s->failed_pc=0x0c038864u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038866;
P_0c038866: /* original 6573, guest PC 0x0c038866 */
if(!s->budget--) { s->failed_pc=0x0c038866u; return 0; }
r[5]=r[7];
goto P_0c038868;
P_0c038868: /* original 2fb6, guest PC 0x0c038868 */
if(!s->budget--) { s->failed_pc=0x0c038868u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03886a;
P_0c03886a: /* original 6e73, guest PC 0x0c03886a */
if(!s->budget--) { s->failed_pc=0x0c03886au; return 0; }
r[14]=r[7];
goto P_0c03886c;
P_0c03886c: /* original 2fa6, guest PC 0x0c03886c */
if(!s->budget--) { s->failed_pc=0x0c03886cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03886e;
P_0c03886e: /* original 6a73, guest PC 0x0c03886e */
if(!s->budget--) { s->failed_pc=0x0c03886eu; return 0; }
r[10]=r[7];
goto P_0c038870;
P_0c038870: /* original 2f96, guest PC 0x0c038870 */
if(!s->budget--) { s->failed_pc=0x0c038870u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038872;
P_0c038872: /* original e901, guest PC 0x0c038872 */
if(!s->budget--) { s->failed_pc=0x0c038872u; return 0; }
r[9]=0x00000001u;
goto P_0c038874;
P_0c038874: /* original 2f86, guest PC 0x0c038874 */
if(!s->budget--) { s->failed_pc=0x0c038874u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038876;
P_0c038876: /* original d854, guest PC 0x0c038876 */
if(!s->budget--) { s->failed_pc=0x0c038876u; return 0; }
r[8]=read(ram,0x0c0389c8u,4);
goto P_0c038878;
P_0c038878: /* original dd54, guest PC 0x0c038878 */
if(!s->budget--) { s->failed_pc=0x0c038878u; return 0; }
r[13]=read(ram,0x0c0389ccu,4);
goto P_0c03887a;
P_0c03887a: /* original a025, guest PC 0x0c03887a */
if(!s->budget--) { s->failed_pc=0x0c03887au; return 0; }
r[11]=r[7];
goto P_0c0388c8;
P_0c03887c: /* original 6b73, guest PC 0x0c03887c */
if(!s->budget--) { s->failed_pc=0x0c03887cu; return 0; }
r[11]=r[7];
if(!vf3_matrix_family(0x0c03887eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03887eu; return 0; } return 1;
P_0c038880: /* original 60d2, guest PC 0x0c038880 */
if(!s->budget--) { s->failed_pc=0x0c038880u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c038882;
P_0c038882: /* original 00be, guest PC 0x0c038882 */
if(!s->budget--) { s->failed_pc=0x0c038882u; return 0; }
r[0]=read(ram,r[11]+r[0],4);
goto P_0c038884;
P_0c038884: /* original 88ff, guest PC 0x0c038884 */
if(!s->budget--) { s->failed_pc=0x0c038884u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c038886;
P_0c038886: /* original 8d1b, guest PC 0x0c038886 */
if(!s->budget--) { s->failed_pc=0x0c038886u; return 0; }
cond=r[17]&1u;
r[1]=r[0];
if(cond) { goto P_0c0388c0; }
goto P_0c03888a;
P_0c038888: /* original 6103, guest PC 0x0c038888 */
if(!s->budget--) { s->failed_pc=0x0c038888u; return 0; }
r[1]=r[0];
goto P_0c03888a;
P_0c03888a: /* original 6493, guest PC 0x0c03888a */
if(!s->budget--) { s->failed_pc=0x0c03888au; return 0; }
r[4]=r[9];
goto P_0c03888c;
P_0c03888c: /* original 6673, guest PC 0x0c03888c */
if(!s->budget--) { s->failed_pc=0x0c03888cu; return 0; }
r[6]=r[7];
goto P_0c03888e;
P_0c03888e: /* original 6213, guest PC 0x0c03888e */
if(!s->budget--) { s->failed_pc=0x0c03888eu; return 0; }
r[2]=r[1];
goto P_0c038890;
P_0c038890: /* original 2248, guest PC 0x0c038890 */
if(!s->budget--) { s->failed_pc=0x0c038890u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c038892;
P_0c038892: /* original 8b0d, guest PC 0x0c038892 */
if(!s->budget--) { s->failed_pc=0x0c038892u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0388b0; }
goto P_0c038894;
P_0c038894: /* original 60d2, guest PC 0x0c038894 */
if(!s->budget--) { s->failed_pc=0x0c038894u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c038896;
P_0c038896: /* original 02ee, guest PC 0x0c038896 */
if(!s->budget--) { s->failed_pc=0x0c038896u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c038898;
P_0c038898: /* original 224b, guest PC 0x0c038898 */
if(!s->budget--) { s->failed_pc=0x0c038898u; return 0; }
r[2]|=r[4];
goto P_0c03889a;
P_0c03889a: /* original 0e26, guest PC 0x0c03889a */
if(!s->budget--) { s->failed_pc=0x0c03889au; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c03889c;
P_0c03889c: /* original 6053, guest PC 0x0c03889c */
if(!s->budget--) { s->failed_pc=0x0c03889cu; return 0; }
r[0]=r[5];
goto P_0c03889e;
P_0c03889e: /* original a017, guest PC 0x0c03889e */
if(!s->budget--) { s->failed_pc=0x0c03889eu; return 0; }
r[0]+=r[6];
goto P_0c0388d0;
P_0c0388a0: /* original 306c, guest PC 0x0c0388a0 */
if(!s->budget--) { s->failed_pc=0x0c0388a0u; return 0; }
r[0]+=r[6];
if(!vf3_matrix_family(0x0c0388a2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0388a2u; return 0; } return 1;
P_0c0388b0: /* original 4400, guest PC 0x0c0388b0 */
if(!s->budget--) { s->failed_pc=0x0c0388b0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0388b2;
P_0c0388b2: /* original afec, guest PC 0x0c0388b2 */
if(!s->budget--) { s->failed_pc=0x0c0388b2u; return 0; }
r[6]+=0x00000001u;
goto P_0c03888e;
P_0c0388b4: /* original 7601, guest PC 0x0c0388b4 */
if(!s->budget--) { s->failed_pc=0x0c0388b4u; return 0; }
r[6]+=0x00000001u;
if(!vf3_matrix_family(0x0c0388b6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0388b6u; return 0; } return 1;
P_0c0388c0: /* original 7e04, guest PC 0x0c0388c0 */
if(!s->budget--) { s->failed_pc=0x0c0388c0u; return 0; }
r[14]+=0x00000004u;
goto P_0c0388c2;
P_0c0388c2: /* original 7b04, guest PC 0x0c0388c2 */
if(!s->budget--) { s->failed_pc=0x0c0388c2u; return 0; }
r[11]+=0x00000004u;
goto P_0c0388c4;
P_0c0388c4: /* original 7a01, guest PC 0x0c0388c4 */
if(!s->budget--) { s->failed_pc=0x0c0388c4u; return 0; }
r[10]+=0x00000001u;
goto P_0c0388c6;
P_0c0388c6: /* original 7520, guest PC 0x0c0388c6 */
if(!s->budget--) { s->failed_pc=0x0c0388c6u; return 0; }
r[5]+=0x00000020u;
goto P_0c0388c8;
P_0c0388c8: /* original 6382, guest PC 0x0c0388c8 */
if(!s->budget--) { s->failed_pc=0x0c0388c8u; return 0; }
tmp=read(ram,r[8],4);
r[3]=tmp;
goto P_0c0388ca;
P_0c0388ca: /* original 3a33, guest PC 0x0c0388ca */
if(!s->budget--) { s->failed_pc=0x0c0388cau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[3])!=0);
goto P_0c0388cc;
P_0c0388cc: /* original 8bd8, guest PC 0x0c0388cc */
if(!s->budget--) { s->failed_pc=0x0c0388ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c038880; }
goto P_0c0388ce;
P_0c0388ce: /* original e0ff, guest PC 0x0c0388ce */
if(!s->budget--) { s->failed_pc=0x0c0388ceu; return 0; }
r[0]=0xffffffffu;
goto P_0c0388d0;
P_0c0388d0: /* original 68f6, guest PC 0x0c0388d0 */
if(!s->budget--) { s->failed_pc=0x0c0388d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0388d2;
P_0c0388d2: /* original 69f6, guest PC 0x0c0388d2 */
if(!s->budget--) { s->failed_pc=0x0c0388d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0388d4;
P_0c0388d4: /* original 6af6, guest PC 0x0c0388d4 */
if(!s->budget--) { s->failed_pc=0x0c0388d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0388d6;
P_0c0388d6: /* original 6bf6, guest PC 0x0c0388d6 */
if(!s->budget--) { s->failed_pc=0x0c0388d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0388d8;
P_0c0388d8: /* original 6df6, guest PC 0x0c0388d8 */
if(!s->budget--) { s->failed_pc=0x0c0388d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0388da;
P_0c0388da: /* original 000b, guest PC 0x0c0388da */
if(!s->budget--) { s->failed_pc=0x0c0388dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0388dc: /* original 6ef6, guest PC 0x0c0388dc */
if(!s->budget--) { s->failed_pc=0x0c0388dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0388deu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0388deu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
