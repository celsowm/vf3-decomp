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
int vf3_away_batch132_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c038fe0u: goto P_0c038fe0;
case 0x0c038fe2u: goto P_0c038fe2;
case 0x0c038fe4u: goto P_0c038fe4;
case 0x0c038fe6u: goto P_0c038fe6;
case 0x0c038fe8u: goto P_0c038fe8;
case 0x0c038feau: goto P_0c038fea;
case 0x0c038fecu: goto P_0c038fec;
case 0x0c038feeu: goto P_0c038fee;
case 0x0c038ff0u: goto P_0c038ff0;
case 0x0c038ff2u: goto P_0c038ff2;
case 0x0c038ff4u: goto P_0c038ff4;
case 0x0c038ff6u: goto P_0c038ff6;
case 0x0c038ff8u: goto P_0c038ff8;
case 0x0c038ffau: goto P_0c038ffa;
case 0x0c038ffcu: goto P_0c038ffc;
case 0x0c038ffeu: goto P_0c038ffe;
case 0x0c039000u: goto P_0c039000;
case 0x0c039002u: goto P_0c039002;
case 0x0c039004u: goto P_0c039004;
case 0x0c039006u: goto P_0c039006;
case 0x0c039008u: goto P_0c039008;
case 0x0c03900au: goto P_0c03900a;
case 0x0c03900cu: goto P_0c03900c;
case 0x0c03900eu: goto P_0c03900e;
case 0x0c039010u: goto P_0c039010;
case 0x0c039012u: goto P_0c039012;
case 0x0c039014u: goto P_0c039014;
case 0x0c039016u: goto P_0c039016;
case 0x0c039018u: goto P_0c039018;
case 0x0c03901au: goto P_0c03901a;
case 0x0c03901cu: goto P_0c03901c;
case 0x0c03901eu: goto P_0c03901e;
case 0x0c039020u: goto P_0c039020;
case 0x0c039022u: goto P_0c039022;
case 0x0c039024u: goto P_0c039024;
case 0x0c039030u: goto P_0c039030;
case 0x0c039032u: goto P_0c039032;
case 0x0c039034u: goto P_0c039034;
case 0x0c039036u: goto P_0c039036;
case 0x0c039038u: goto P_0c039038;
case 0x0c03903au: goto P_0c03903a;
case 0x0c03903cu: goto P_0c03903c;
case 0x0c03903eu: goto P_0c03903e;
case 0x0c039040u: goto P_0c039040;
case 0x0c039042u: goto P_0c039042;
case 0x0c039044u: goto P_0c039044;
case 0x0c039046u: goto P_0c039046;
case 0x0c039048u: goto P_0c039048;
case 0x0c03904au: goto P_0c03904a;
case 0x0c03904cu: goto P_0c03904c;
case 0x0c03904eu: goto P_0c03904e;
case 0x0c039050u: goto P_0c039050;
case 0x0c039052u: goto P_0c039052;
case 0x0c039054u: goto P_0c039054;
case 0x0c039056u: goto P_0c039056;
case 0x0c039058u: goto P_0c039058;
case 0x0c03905au: goto P_0c03905a;
case 0x0c03905cu: goto P_0c03905c;
case 0x0c03905eu: goto P_0c03905e;
case 0x0c039060u: goto P_0c039060;
case 0x0c039062u: goto P_0c039062;
case 0x0c039064u: goto P_0c039064;
case 0x0c039066u: goto P_0c039066;
case 0x0c039068u: goto P_0c039068;
case 0x0c03906au: goto P_0c03906a;
case 0x0c03906cu: goto P_0c03906c;
case 0x0c03906eu: goto P_0c03906e;
case 0x0c039070u: goto P_0c039070;
case 0x0c039072u: goto P_0c039072;
case 0x0c039074u: goto P_0c039074;
case 0x0c039076u: goto P_0c039076;
case 0x0c039078u: goto P_0c039078;
case 0x0c03907au: goto P_0c03907a;
case 0x0c03907cu: goto P_0c03907c;
case 0x0c03907eu: goto P_0c03907e;
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
P_0c038fe0: /* original 2fc6, guest PC 0x0c038fe0 */
if(!s->budget--) { s->failed_pc=0x0c038fe0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038fe2;
P_0c038fe2: /* original e004, guest PC 0x0c038fe2 */
if(!s->budget--) { s->failed_pc=0x0c038fe2u; return 0; }
r[0]=0x00000004u;
goto P_0c038fe4;
P_0c038fe4: /* original 4f22, guest PC 0x0c038fe4 */
if(!s->budget--) { s->failed_pc=0x0c038fe4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c038fe6;
P_0c038fe6: /* original d74c, guest PC 0x0c038fe6 */
if(!s->budget--) { s->failed_pc=0x0c038fe6u; return 0; }
r[7]=read(ram,0x0c039118u,4);
goto P_0c038fe8;
P_0c038fe8: /* original 7f94, guest PC 0x0c038fe8 */
if(!s->budget--) { s->failed_pc=0x0c038fe8u; return 0; }
r[15]+=0xffffff94u;
goto P_0c038fea;
P_0c038fea: /* original 2742, guest PC 0x0c038fea */
if(!s->budget--) { s->failed_pc=0x0c038feau; return 0; }
write(ram,r[7],r[4],4);
goto P_0c038fec;
P_0c038fec: /* original 1751, guest PC 0x0c038fec */
if(!s->budget--) { s->failed_pc=0x0c038fecu; return 0; }
write(ram,r[7]+4,r[5],4);
goto P_0c038fee;
P_0c038fee: /* original 1762, guest PC 0x0c038fee */
if(!s->budget--) { s->failed_pc=0x0c038feeu; return 0; }
write(ram,r[7]+8,r[6],4);
goto P_0c038ff0;
P_0c038ff0: /* original 67f3, guest PC 0x0c038ff0 */
if(!s->budget--) { s->failed_pc=0x0c038ff0u; return 0; }
r[7]=r[15];
goto P_0c038ff2;
P_0c038ff2: /* original 770c, guest PC 0x0c038ff2 */
if(!s->budget--) { s->failed_pc=0x0c038ff2u; return 0; }
r[7]+=0x0000000cu;
goto P_0c038ff4;
P_0c038ff4: /* original d349, guest PC 0x0c038ff4 */
if(!s->budget--) { s->failed_pc=0x0c038ff4u; return 0; }
r[3]=read(ram,0x0c03911cu,4);
goto P_0c038ff6;
P_0c038ff6: /* original 6273, guest PC 0x0c038ff6 */
if(!s->budget--) { s->failed_pc=0x0c038ff6u; return 0; }
r[2]=r[7];
goto P_0c038ff8;
P_0c038ff8: /* original 6123, guest PC 0x0c038ff8 */
if(!s->budget--) { s->failed_pc=0x0c038ff8u; return 0; }
r[1]=r[2];
goto P_0c038ffa;
P_0c038ffa: /* original 7120, guest PC 0x0c038ffa */
if(!s->budget--) { s->failed_pc=0x0c038ffau; return 0; }
r[1]+=0x00000020u;
goto P_0c038ffc;
P_0c038ffc: /* original 2232, guest PC 0x0c038ffc */
if(!s->budget--) { s->failed_pc=0x0c038ffcu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c038ffe;
P_0c038ffe: /* original f48d, guest PC 0x0c038ffe */
if(!s->budget--) { s->failed_pc=0x0c038ffeu; return 0; }
fr[4]=0;
goto P_0c039000;
P_0c039000: /* original f247, guest PC 0x0c039000 */
if(!s->budget--) { s->failed_pc=0x0c039000u; return 0; }
vf3_matrix_store(s,ram,4,r[2]+r[0]);
goto P_0c039002;
P_0c039002: /* original e008, guest PC 0x0c039002 */
if(!s->budget--) { s->failed_pc=0x0c039002u; return 0; }
r[0]=0x00000008u;
goto P_0c039004;
P_0c039004: /* original f247, guest PC 0x0c039004 */
if(!s->budget--) { s->failed_pc=0x0c039004u; return 0; }
vf3_matrix_store(s,ram,4,r[2]+r[0]);
goto P_0c039006;
P_0c039006: /* original c746, guest PC 0x0c039006 */
if(!s->budget--) { s->failed_pc=0x0c039006u; return 0; }
r[0]=code_base|0x00039120u;
goto P_0c039008;
P_0c039008: /* original f508, guest PC 0x0c039008 */
if(!s->budget--) { s->failed_pc=0x0c039008u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c03900a;
P_0c03900a: /* original e00c, guest PC 0x0c03900a */
if(!s->budget--) { s->failed_pc=0x0c03900au; return 0; }
r[0]=0x0000000cu;
goto P_0c03900c;
P_0c03900c: /* original f257, guest PC 0x0c03900c */
if(!s->budget--) { s->failed_pc=0x0c03900cu; return 0; }
vf3_matrix_store(s,ram,5,r[2]+r[0]);
goto P_0c03900e;
P_0c03900e: /* original 1244, guest PC 0x0c03900e */
if(!s->budget--) { s->failed_pc=0x0c03900eu; return 0; }
write(ram,r[2]+16,r[4],4);
goto P_0c039010;
P_0c039010: /* original 1246, guest PC 0x0c039010 */
if(!s->budget--) { s->failed_pc=0x0c039010u; return 0; }
write(ram,r[2]+24,r[4],4);
goto P_0c039012;
P_0c039012: /* original 2132, guest PC 0x0c039012 */
if(!s->budget--) { s->failed_pc=0x0c039012u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c039014;
P_0c039014: /* original dc43, guest PC 0x0c039014 */
if(!s->budget--) { s->failed_pc=0x0c039014u; return 0; }
r[12]=read(ram,0x0c039124u,4);
goto P_0c039016;
P_0c039016: /* original 85c2, guest PC 0x0c039016 */
if(!s->budget--) { s->failed_pc=0x0c039016u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+4,2);
goto P_0c039018;
P_0c039018: /* original 6403, guest PC 0x0c039018 */
if(!s->budget--) { s->failed_pc=0x0c039018u; return 0; }
r[4]=r[0];
goto P_0c03901a;
P_0c03901a: /* original 85c5, guest PC 0x0c03901a */
if(!s->budget--) { s->failed_pc=0x0c03901au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+10,2);
goto P_0c03901c;
P_0c03901c: /* original 2008, guest PC 0x0c03901c */
if(!s->budget--) { s->failed_pc=0x0c03901cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c03901e;
P_0c03901e: /* original 8907, guest PC 0x0c03901e */
if(!s->budget--) { s->failed_pc=0x0c03901eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c039030; }
goto P_0c039020;
P_0c039020: /* original 644f, guest PC 0x0c039020 */
if(!s->budget--) { s->failed_pc=0x0c039020u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c039022;
P_0c039022: /* original a006, guest PC 0x0c039022 */
if(!s->budget--) { s->failed_pc=0x0c039022u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c039032;
P_0c039024: /* original 4400, guest PC 0x0c039024 */
if(!s->budget--) { s->failed_pc=0x0c039024u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
if(!vf3_matrix_family(0x0c039026u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c039026u; return 0; } return 1;
P_0c039030: /* original 644f, guest PC 0x0c039030 */
if(!s->budget--) { s->failed_pc=0x0c039030u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c039032;
P_0c039032: /* original 445a, guest PC 0x0c039032 */
if(!s->budget--) { s->failed_pc=0x0c039032u; return 0; }
r[53]=r[4];
goto P_0c039034;
P_0c039034: /* original e004, guest PC 0x0c039034 */
if(!s->budget--) { s->failed_pc=0x0c039034u; return 0; }
r[0]=0x00000004u;
goto P_0c039036;
P_0c039036: /* original 6473, guest PC 0x0c039036 */
if(!s->budget--) { s->failed_pc=0x0c039036u; return 0; }
r[4]=r[7];
goto P_0c039038;
P_0c039038: /* original 7440, guest PC 0x0c039038 */
if(!s->budget--) { s->failed_pc=0x0c039038u; return 0; }
r[4]+=0x00000040u;
goto P_0c03903a;
P_0c03903a: /* original f32d, guest PC 0x0c03903a */
if(!s->budget--) { s->failed_pc=0x0c03903au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03903c;
P_0c03903c: /* original f137, guest PC 0x0c03903c */
if(!s->budget--) { s->failed_pc=0x0c03903cu; return 0; }
vf3_matrix_store(s,ram,3,r[1]+r[0]);
goto P_0c03903e;
P_0c03903e: /* original e008, guest PC 0x0c03903e */
if(!s->budget--) { s->failed_pc=0x0c03903eu; return 0; }
r[0]=0x00000008u;
goto P_0c039040;
P_0c039040: /* original f147, guest PC 0x0c039040 */
if(!s->budget--) { s->failed_pc=0x0c039040u; return 0; }
vf3_matrix_store(s,ram,4,r[1]+r[0]);
goto P_0c039042;
P_0c039042: /* original e00c, guest PC 0x0c039042 */
if(!s->budget--) { s->failed_pc=0x0c039042u; return 0; }
r[0]=0x0000000cu;
goto P_0c039044;
P_0c039044: /* original f157, guest PC 0x0c039044 */
if(!s->budget--) { s->failed_pc=0x0c039044u; return 0; }
vf3_matrix_store(s,ram,5,r[1]+r[0]);
goto P_0c039046;
P_0c039046: /* original e004, guest PC 0x0c039046 */
if(!s->budget--) { s->failed_pc=0x0c039046u; return 0; }
r[0]=0x00000004u;
goto P_0c039048;
P_0c039048: /* original 1154, guest PC 0x0c039048 */
if(!s->budget--) { s->failed_pc=0x0c039048u; return 0; }
write(ram,r[1]+16,r[5],4);
goto P_0c03904a;
P_0c03904a: /* original 1156, guest PC 0x0c03904a */
if(!s->budget--) { s->failed_pc=0x0c03904au; return 0; }
write(ram,r[1]+24,r[5],4);
goto P_0c03904c;
P_0c03904c: /* original e500, guest PC 0x0c03904c */
if(!s->budget--) { s->failed_pc=0x0c03904cu; return 0; }
r[5]=0x00000000u;
goto P_0c03904e;
P_0c03904e: /* original d336, guest PC 0x0c03904e */
if(!s->budget--) { s->failed_pc=0x0c03904eu; return 0; }
r[3]=read(ram,0x0c039128u,4);
goto P_0c039050;
P_0c039050: /* original 2432, guest PC 0x0c039050 */
if(!s->budget--) { s->failed_pc=0x0c039050u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c039052;
P_0c039052: /* original f447, guest PC 0x0c039052 */
if(!s->budget--) { s->failed_pc=0x0c039052u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c039054;
P_0c039054: /* original 85c3, guest PC 0x0c039054 */
if(!s->budget--) { s->failed_pc=0x0c039054u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+6,2);
goto P_0c039056;
P_0c039056: /* original 6cf3, guest PC 0x0c039056 */
if(!s->budget--) { s->failed_pc=0x0c039056u; return 0; }
r[12]=r[15];
goto P_0c039058;
P_0c039058: /* original 6303, guest PC 0x0c039058 */
if(!s->budget--) { s->failed_pc=0x0c039058u; return 0; }
r[3]=r[0];
goto P_0c03905a;
P_0c03905a: /* original 435a, guest PC 0x0c03905a */
if(!s->budget--) { s->failed_pc=0x0c03905au; return 0; }
r[53]=r[3];
goto P_0c03905c;
P_0c03905c: /* original e008, guest PC 0x0c03905c */
if(!s->budget--) { s->failed_pc=0x0c03905cu; return 0; }
r[0]=0x00000008u;
goto P_0c03905e;
P_0c03905e: /* original f32d, guest PC 0x0c03905e */
if(!s->budget--) { s->failed_pc=0x0c03905eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c039060;
P_0c039060: /* original f437, guest PC 0x0c039060 */
if(!s->budget--) { s->failed_pc=0x0c039060u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c039062;
P_0c039062: /* original e00c, guest PC 0x0c039062 */
if(!s->budget--) { s->failed_pc=0x0c039062u; return 0; }
r[0]=0x0000000cu;
goto P_0c039064;
P_0c039064: /* original f457, guest PC 0x0c039064 */
if(!s->budget--) { s->failed_pc=0x0c039064u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c039066;
P_0c039066: /* original 1464, guest PC 0x0c039066 */
if(!s->budget--) { s->failed_pc=0x0c039066u; return 0; }
write(ram,r[4]+16,r[6],4);
goto P_0c039068;
P_0c039068: /* original 1466, guest PC 0x0c039068 */
if(!s->budget--) { s->failed_pc=0x0c039068u; return 0; }
write(ram,r[4]+24,r[6],4);
goto P_0c03906a;
P_0c03906a: /* original e620, guest PC 0x0c03906a */
if(!s->budget--) { s->failed_pc=0x0c03906au; return 0; }
r[6]=0x00000020u;
goto P_0c03906c;
P_0c03906c: /* original 2c22, guest PC 0x0c03906c */
if(!s->budget--) { s->failed_pc=0x0c03906cu; return 0; }
write(ram,r[12],r[2],4);
goto P_0c03906e;
P_0c03906e: /* original 1c11, guest PC 0x0c03906e */
if(!s->budget--) { s->failed_pc=0x0c03906eu; return 0; }
write(ram,r[12]+4,r[1],4);
goto P_0c039070;
P_0c039070: /* original 1c42, guest PC 0x0c039070 */
if(!s->budget--) { s->failed_pc=0x0c039070u; return 0; }
write(ram,r[12]+8,r[4],4);
goto P_0c039072;
P_0c039072: /* original d32e, guest PC 0x0c039072 */
if(!s->budget--) { s->failed_pc=0x0c039072u; return 0; }
r[3]=read(ram,0x0c03912cu,4);
goto P_0c039074;
P_0c039074: /* original 430b, guest PC 0x0c039074 */
if(!s->budget--) { s->failed_pc=0x0c039074u; return 0; }
target=r[3];
r[16]=code_base|0x0c039078u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c039078u) { target=s->pc; goto dispatch; }
goto P_0c039078;
P_0c039076: /* original 64c3, guest PC 0x0c039076 */
if(!s->budget--) { s->failed_pc=0x0c039076u; return 0; }
r[4]=r[12];
goto P_0c039078;
P_0c039078: /* original 7f6c, guest PC 0x0c039078 */
if(!s->budget--) { s->failed_pc=0x0c039078u; return 0; }
r[15]+=0x0000006cu;
goto P_0c03907a;
P_0c03907a: /* original 4f26, guest PC 0x0c03907a */
if(!s->budget--) { s->failed_pc=0x0c03907au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03907c;
P_0c03907c: /* original 000b, guest PC 0x0c03907c */
if(!s->budget--) { s->failed_pc=0x0c03907cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
s->pc=target; return ram->oob==0;
P_0c03907e: /* original 6cf6, guest PC 0x0c03907e */
if(!s->budget--) { s->failed_pc=0x0c03907eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
if(!vf3_matrix_family(0x0c039080u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c039080u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
