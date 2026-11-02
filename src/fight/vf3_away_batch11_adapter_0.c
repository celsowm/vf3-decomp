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
int vf3_away_batch11_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c035bc6u: goto P_0c035bc6;
case 0x0c035bc8u: goto P_0c035bc8;
case 0x0c035bcau: goto P_0c035bca;
case 0x0c035bccu: goto P_0c035bcc;
case 0x0c035bceu: goto P_0c035bce;
case 0x0c035bd0u: goto P_0c035bd0;
case 0x0c035bd2u: goto P_0c035bd2;
case 0x0c035bd4u: goto P_0c035bd4;
case 0x0c035bd6u: goto P_0c035bd6;
case 0x0c035bd8u: goto P_0c035bd8;
case 0x0c035bdau: goto P_0c035bda;
case 0x0c035bdcu: goto P_0c035bdc;
case 0x0c035bdeu: goto P_0c035bde;
case 0x0c035be0u: goto P_0c035be0;
case 0x0c035be2u: goto P_0c035be2;
case 0x0c035be4u: goto P_0c035be4;
case 0x0c035be6u: goto P_0c035be6;
case 0x0c035be8u: goto P_0c035be8;
case 0x0c035beau: goto P_0c035bea;
case 0x0c035becu: goto P_0c035bec;
case 0x0c035beeu: goto P_0c035bee;
case 0x0c035bf0u: goto P_0c035bf0;
case 0x0c035ca4u: goto P_0c035ca4;
case 0x0c035ca6u: goto P_0c035ca6;
case 0x0c035ca8u: goto P_0c035ca8;
case 0x0c035caau: goto P_0c035caa;
case 0x0c035cacu: goto P_0c035cac;
case 0x0c035caeu: goto P_0c035cae;
case 0x0c035cb0u: goto P_0c035cb0;
case 0x0c035cb2u: goto P_0c035cb2;
case 0x0c035cb4u: goto P_0c035cb4;
case 0x0c035cb6u: goto P_0c035cb6;
case 0x0c035cb8u: goto P_0c035cb8;
case 0x0c036fdcu: goto P_0c036fdc;
case 0x0c036fdeu: goto P_0c036fde;
case 0x0c036fe0u: goto P_0c036fe0;
case 0x0c036fe2u: goto P_0c036fe2;
case 0x0c036fe4u: goto P_0c036fe4;
case 0x0c036fe6u: goto P_0c036fe6;
case 0x0c036fe8u: goto P_0c036fe8;
case 0x0c036feau: goto P_0c036fea;
case 0x0c036fecu: goto P_0c036fec;
case 0x0c036feeu: goto P_0c036fee;
case 0x0c036ff0u: goto P_0c036ff0;
case 0x0c036ff2u: goto P_0c036ff2;
case 0x0c036ff4u: goto P_0c036ff4;
case 0x0c036ff6u: goto P_0c036ff6;
case 0x0c036ff8u: goto P_0c036ff8;
case 0x0c036ffau: goto P_0c036ffa;
case 0x0c036ffcu: goto P_0c036ffc;
case 0x0c036ffeu: goto P_0c036ffe;
case 0x0c037000u: goto P_0c037000;
case 0x0c037002u: goto P_0c037002;
case 0x0c0371f8u: goto P_0c0371f8;
case 0x0c0371fau: goto P_0c0371fa;
case 0x0c0371fcu: goto P_0c0371fc;
case 0x0c037240u: goto P_0c037240;
case 0x0c037242u: goto P_0c037242;
case 0x0c037244u: goto P_0c037244;
case 0x0c037246u: goto P_0c037246;
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
P_0c035bc6: /* original d267, guest PC 0x0c035bc6 */
if(!s->budget--) { s->failed_pc=0x0c035bc6u; return 0; }
r[2]=read(ram,0x0c035d64u,4);
goto P_0c035bc8;
P_0c035bc8: /* original 4f22, guest PC 0x0c035bc8 */
if(!s->budget--) { s->failed_pc=0x0c035bc8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c035bca;
P_0c035bca: /* original 6322, guest PC 0x0c035bca */
if(!s->budget--) { s->failed_pc=0x0c035bcau; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c035bcc;
P_0c035bcc: /* original 2338, guest PC 0x0c035bcc */
if(!s->budget--) { s->failed_pc=0x0c035bccu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c035bce;
P_0c035bce: /* original 890d, guest PC 0x0c035bce */
if(!s->budget--) { s->failed_pc=0x0c035bceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035bec; }
goto P_0c035bd0;
P_0c035bd0: /* original d163, guest PC 0x0c035bd0 */
if(!s->budget--) { s->failed_pc=0x0c035bd0u; return 0; }
r[1]=read(ram,0x0c035d60u,4);
goto P_0c035bd2;
P_0c035bd2: /* original 6312, guest PC 0x0c035bd2 */
if(!s->budget--) { s->failed_pc=0x0c035bd2u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c035bd4;
P_0c035bd4: /* original 5035, guest PC 0x0c035bd4 */
if(!s->budget--) { s->failed_pc=0x0c035bd4u; return 0; }
r[0]=read(ram,r[3]+20,4);
goto P_0c035bd6;
P_0c035bd6: /* original 400b, guest PC 0x0c035bd6 */
if(!s->budget--) { s->failed_pc=0x0c035bd6u; return 0; }
target=r[0];
r[16]=code_base|0x0c035bdau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035bdau) { target=s->pc; goto dispatch; }
goto P_0c035bda;
P_0c035bd8: /* original 0009, guest PC 0x0c035bd8 */
if(!s->budget--) { s->failed_pc=0x0c035bd8u; return 0; }
goto P_0c035bda;
P_0c035bda: /* original d366, guest PC 0x0c035bda */
if(!s->budget--) { s->failed_pc=0x0c035bdau; return 0; }
r[3]=read(ram,0x0c035d74u,4);
goto P_0c035bdc;
P_0c035bdc: /* original d462, guest PC 0x0c035bdc */
if(!s->budget--) { s->failed_pc=0x0c035bdcu; return 0; }
r[4]=read(ram,0x0c035d68u,4);
goto P_0c035bde;
P_0c035bde: /* original 430b, guest PC 0x0c035bde */
if(!s->budget--) { s->failed_pc=0x0c035bdeu; return 0; }
target=r[3];
r[16]=code_base|0x0c035be2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c035be2u) { target=s->pc; goto dispatch; }
goto P_0c035be2;
P_0c035be0: /* original 0009, guest PC 0x0c035be0 */
if(!s->budget--) { s->failed_pc=0x0c035be0u; return 0; }
goto P_0c035be2;
P_0c035be2: /* original d260, guest PC 0x0c035be2 */
if(!s->budget--) { s->failed_pc=0x0c035be2u; return 0; }
r[2]=read(ram,0x0c035d64u,4);
goto P_0c035be4;
P_0c035be4: /* original e400, guest PC 0x0c035be4 */
if(!s->budget--) { s->failed_pc=0x0c035be4u; return 0; }
r[4]=0x00000000u;
goto P_0c035be6;
P_0c035be6: /* original 2242, guest PC 0x0c035be6 */
if(!s->budget--) { s->failed_pc=0x0c035be6u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c035be8;
P_0c035be8: /* original d35d, guest PC 0x0c035be8 */
if(!s->budget--) { s->failed_pc=0x0c035be8u; return 0; }
r[3]=read(ram,0x0c035d60u,4);
goto P_0c035bea;
P_0c035bea: /* original 2342, guest PC 0x0c035bea */
if(!s->budget--) { s->failed_pc=0x0c035beau; return 0; }
write(ram,r[3],r[4],4);
goto P_0c035bec;
P_0c035bec: /* original 4f26, guest PC 0x0c035bec */
if(!s->budget--) { s->failed_pc=0x0c035becu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c035bee;
P_0c035bee: /* original 000b, guest PC 0x0c035bee */
if(!s->budget--) { s->failed_pc=0x0c035beeu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c035bf0: /* original 0009, guest PC 0x0c035bf0 */
if(!s->budget--) { s->failed_pc=0x0c035bf0u; return 0; }
if(!vf3_matrix_family(0x0c035bf2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c035bf2u; return 0; } return 1;
P_0c035ca4: /* original 2fe6, guest PC 0x0c035ca4 */
if(!s->budget--) { s->failed_pc=0x0c035ca4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035ca6;
P_0c035ca6: /* original d32e, guest PC 0x0c035ca6 */
if(!s->budget--) { s->failed_pc=0x0c035ca6u; return 0; }
r[3]=read(ram,0x0c035d60u,4);
goto P_0c035ca8;
P_0c035ca8: /* original 6e32, guest PC 0x0c035ca8 */
if(!s->budget--) { s->failed_pc=0x0c035ca8u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c035caa;
P_0c035caa: /* original 2ee8, guest PC 0x0c035caa */
if(!s->budget--) { s->failed_pc=0x0c035caau; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c035cac;
P_0c035cac: /* original 8902, guest PC 0x0c035cac */
if(!s->budget--) { s->failed_pc=0x0c035cacu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035cb4; }
goto P_0c035cae;
P_0c035cae: /* original 50ec, guest PC 0x0c035cae */
if(!s->budget--) { s->failed_pc=0x0c035caeu; return 0; }
r[0]=read(ram,r[14]+48,4);
goto P_0c035cb0;
P_0c035cb0: /* original 402b, guest PC 0x0c035cb0 */
if(!s->budget--) { s->failed_pc=0x0c035cb0u; return 0; }
target=r[0];
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
P_0c035cb2: /* original 6ef6, guest PC 0x0c035cb2 */
if(!s->budget--) { s->failed_pc=0x0c035cb2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c035cb4;
P_0c035cb4: /* original e000, guest PC 0x0c035cb4 */
if(!s->budget--) { s->failed_pc=0x0c035cb4u; return 0; }
r[0]=0x00000000u;
goto P_0c035cb6;
P_0c035cb6: /* original 000b, guest PC 0x0c035cb6 */
if(!s->budget--) { s->failed_pc=0x0c035cb6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c035cb8: /* original 6ef6, guest PC 0x0c035cb8 */
if(!s->budget--) { s->failed_pc=0x0c035cb8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c035cbau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c035cbau; return 0; } return 1;
P_0c036fdc: /* original 2fe6, guest PC 0x0c036fdc */
if(!s->budget--) { s->failed_pc=0x0c036fdcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036fde;
P_0c036fde: /* original ee00, guest PC 0x0c036fde */
if(!s->budget--) { s->failed_pc=0x0c036fdeu; return 0; }
r[14]=0x00000000u;
goto P_0c036fe0;
P_0c036fe0: /* original 2fd6, guest PC 0x0c036fe0 */
if(!s->budget--) { s->failed_pc=0x0c036fe0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036fe2;
P_0c036fe2: /* original 63e3, guest PC 0x0c036fe2 */
if(!s->budget--) { s->failed_pc=0x0c036fe2u; return 0; }
r[3]=r[14];
goto P_0c036fe4;
P_0c036fe4: /* original 2fc6, guest PC 0x0c036fe4 */
if(!s->budget--) { s->failed_pc=0x0c036fe4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c036fe6;
P_0c036fe6: /* original 6c53, guest PC 0x0c036fe6 */
if(!s->budget--) { s->failed_pc=0x0c036fe6u; return 0; }
r[12]=r[5];
goto P_0c036fe8;
P_0c036fe8: /* original 33c2, guest PC 0x0c036fe8 */
if(!s->budget--) { s->failed_pc=0x0c036fe8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[12])!=0);
goto P_0c036fea;
P_0c036fea: /* original 8d07, guest PC 0x0c036fea */
if(!s->budget--) { s->failed_pc=0x0c036feau; return 0; }
cond=r[17]&1u;
r[13]=r[4];
if(cond) { goto P_0c036ffc; }
goto P_0c036fee;
P_0c036fec: /* original 6d43, guest PC 0x0c036fec */
if(!s->budget--) { s->failed_pc=0x0c036fecu; return 0; }
r[13]=r[4];
goto P_0c036fee;
P_0c036fee: /* original 64d3, guest PC 0x0c036fee */
if(!s->budget--) { s->failed_pc=0x0c036feeu; return 0; }
r[4]=r[13];
goto P_0c036ff0;
P_0c036ff0: /* original 04a3, guest PC 0x0c036ff0 */
if(!s->budget--) { s->failed_pc=0x0c036ff0u; return 0; }
goto P_0c036ff2;
P_0c036ff2: /* original 0009, guest PC 0x0c036ff2 */
if(!s->budget--) { s->failed_pc=0x0c036ff2u; return 0; }
goto P_0c036ff4;
P_0c036ff4: /* original 7e01, guest PC 0x0c036ff4 */
if(!s->budget--) { s->failed_pc=0x0c036ff4u; return 0; }
r[14]+=0x00000001u;
goto P_0c036ff6;
P_0c036ff6: /* original 3ec2, guest PC 0x0c036ff6 */
if(!s->budget--) { s->failed_pc=0x0c036ff6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[12])!=0);
goto P_0c036ff8;
P_0c036ff8: /* original 8ff9, guest PC 0x0c036ff8 */
if(!s->budget--) { s->failed_pc=0x0c036ff8u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000020u;
if(!cond) { goto P_0c036fee; }
goto P_0c036ffc;
P_0c036ffa: /* original 7d20, guest PC 0x0c036ffa */
if(!s->budget--) { s->failed_pc=0x0c036ffau; return 0; }
r[13]+=0x00000020u;
goto P_0c036ffc;
P_0c036ffc: /* original 6cf6, guest PC 0x0c036ffc */
if(!s->budget--) { s->failed_pc=0x0c036ffcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c036ffe;
P_0c036ffe: /* original 6df6, guest PC 0x0c036ffe */
if(!s->budget--) { s->failed_pc=0x0c036ffeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c037000;
P_0c037000: /* original 000b, guest PC 0x0c037000 */
if(!s->budget--) { s->failed_pc=0x0c037000u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c037002: /* original 6ef6, guest PC 0x0c037002 */
if(!s->budget--) { s->failed_pc=0x0c037002u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c037004u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c037004u; return 0; } return 1;
P_0c0371f8: /* original d001, guest PC 0x0c0371f8 */
if(!s->budget--) { s->failed_pc=0x0c0371f8u; return 0; }
r[0]=read(ram,0x0c037200u,4);
goto P_0c0371fa;
P_0c0371fa: /* original 000b, guest PC 0x0c0371fa */
if(!s->budget--) { s->failed_pc=0x0c0371fau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0371fc: /* original 0009, guest PC 0x0c0371fc */
if(!s->budget--) { s->failed_pc=0x0c0371fcu; return 0; }
if(!vf3_matrix_family(0x0c0371feu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0371feu; return 0; } return 1;
P_0c037240: /* original d346, guest PC 0x0c037240 */
if(!s->budget--) { s->failed_pc=0x0c037240u; return 0; }
r[3]=read(ram,0x0c03735cu,4);
goto P_0c037242;
P_0c037242: /* original d545, guest PC 0x0c037242 */
if(!s->budget--) { s->failed_pc=0x0c037242u; return 0; }
r[5]=read(ram,0x0c037358u,4);
goto P_0c037244;
P_0c037244: /* original 432b, guest PC 0x0c037244 */
if(!s->budget--) { s->failed_pc=0x0c037244u; return 0; }
target=r[3];
r[4]=0x00000000u;
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
P_0c037246: /* original e400, guest PC 0x0c037246 */
if(!s->budget--) { s->failed_pc=0x0c037246u; return 0; }
r[4]=0x00000000u;
if(!vf3_matrix_family(0x0c037248u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c037248u; return 0; } return 1;
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
unsupported: s->failed_pc=target; return 0;
}
