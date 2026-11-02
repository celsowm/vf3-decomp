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
int vf3_away_batch3_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0365d4u: goto P_0c0365d4;
case 0x0c0365d6u: goto P_0c0365d6;
case 0x0c0365d8u: goto P_0c0365d8;
case 0x0c0365dau: goto P_0c0365da;
case 0x0c0365dcu: goto P_0c0365dc;
case 0x0c0365deu: goto P_0c0365de;
case 0x0c0365e0u: goto P_0c0365e0;
case 0x0c0365e2u: goto P_0c0365e2;
case 0x0c0365e4u: goto P_0c0365e4;
case 0x0c0365e6u: goto P_0c0365e6;
case 0x0c0365e8u: goto P_0c0365e8;
case 0x0c0365eau: goto P_0c0365ea;
case 0x0c0365ecu: goto P_0c0365ec;
case 0x0c0365eeu: goto P_0c0365ee;
case 0x0c0365f0u: goto P_0c0365f0;
case 0x0c0365f2u: goto P_0c0365f2;
case 0x0c0365f4u: goto P_0c0365f4;
case 0x0c0365f6u: goto P_0c0365f6;
case 0x0c0365f8u: goto P_0c0365f8;
case 0x0c0365fau: goto P_0c0365fa;
case 0x0c0365fcu: goto P_0c0365fc;
case 0x0c0365feu: goto P_0c0365fe;
case 0x0c036600u: goto P_0c036600;
case 0x0c036610u: goto P_0c036610;
case 0x0c036612u: goto P_0c036612;
case 0x0c036614u: goto P_0c036614;
case 0x0c036616u: goto P_0c036616;
case 0x0c036618u: goto P_0c036618;
case 0x0c03661au: goto P_0c03661a;
case 0x0c03661cu: goto P_0c03661c;
case 0x0c03661eu: goto P_0c03661e;
case 0x0c036620u: goto P_0c036620;
case 0x0c036622u: goto P_0c036622;
case 0x0c036624u: goto P_0c036624;
case 0x0c036626u: goto P_0c036626;
case 0x0c036628u: goto P_0c036628;
case 0x0c036654u: goto P_0c036654;
case 0x0c036656u: goto P_0c036656;
case 0x0c036658u: goto P_0c036658;
case 0x0c03665au: goto P_0c03665a;
case 0x0c03665cu: goto P_0c03665c;
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
case 0x0c038990u: goto P_0c038990;
case 0x0c038992u: goto P_0c038992;
case 0x0c038994u: goto P_0c038994;
case 0x0c038996u: goto P_0c038996;
case 0x0c038998u: goto P_0c038998;
case 0x0c0389a0u: goto P_0c0389a0;
case 0x0c0389a2u: goto P_0c0389a2;
case 0x0c0389a4u: goto P_0c0389a4;
case 0x0c0389a6u: goto P_0c0389a6;
case 0x0c0389b0u: goto P_0c0389b0;
case 0x0c0389b2u: goto P_0c0389b2;
case 0x0c0389b4u: goto P_0c0389b4;
case 0x0c0389b6u: goto P_0c0389b6;
case 0x0c0389b8u: goto P_0c0389b8;
case 0x0c0389c0u: goto P_0c0389c0;
case 0x0c0389c2u: goto P_0c0389c2;
case 0x0c0389c4u: goto P_0c0389c4;
case 0x0c0389c6u: goto P_0c0389c6;
case 0x0c0389e0u: goto P_0c0389e0;
case 0x0c0389e2u: goto P_0c0389e2;
case 0x0c0389e4u: goto P_0c0389e4;
case 0x0c0389e6u: goto P_0c0389e6;
case 0x0c0389e8u: goto P_0c0389e8;
case 0x0c0389f0u: goto P_0c0389f0;
case 0x0c0389f2u: goto P_0c0389f2;
case 0x0c0389f4u: goto P_0c0389f4;
case 0x0c0389f6u: goto P_0c0389f6;
case 0x0c0389f8u: goto P_0c0389f8;
case 0x0c038a00u: goto P_0c038a00;
case 0x0c038a02u: goto P_0c038a02;
case 0x0c038a04u: goto P_0c038a04;
case 0x0c038a06u: goto P_0c038a06;
case 0x0c038a08u: goto P_0c038a08;
case 0x0c038a10u: goto P_0c038a10;
case 0x0c038a12u: goto P_0c038a12;
case 0x0c038a14u: goto P_0c038a14;
case 0x0c038a16u: goto P_0c038a16;
case 0x0c038a18u: goto P_0c038a18;
case 0x0c038a1au: goto P_0c038a1a;
case 0x0c038a20u: goto P_0c038a20;
case 0x0c038a22u: goto P_0c038a22;
case 0x0c038a24u: goto P_0c038a24;
case 0x0c038a26u: goto P_0c038a26;
case 0x0c038a28u: goto P_0c038a28;
case 0x0c038a2au: goto P_0c038a2a;
case 0x0c038a2cu: goto P_0c038a2c;
case 0x0c038a2eu: goto P_0c038a2e;
case 0x0c038a30u: goto P_0c038a30;
case 0x0c038a32u: goto P_0c038a32;
case 0x0c038a34u: goto P_0c038a34;
case 0x0c038a36u: goto P_0c038a36;
case 0x0c038a38u: goto P_0c038a38;
case 0x0c038a3au: goto P_0c038a3a;
case 0x0c038a3cu: goto P_0c038a3c;
case 0x0c038a3eu: goto P_0c038a3e;
case 0x0c038a40u: goto P_0c038a40;
case 0x0c038a42u: goto P_0c038a42;
case 0x0c038a44u: goto P_0c038a44;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0365d4: /* original e22c, guest PC 0x0c0365d4 */
if(!s->budget--) { s->failed_pc=0x0c0365d4u; return 0; }
r[2]=0x0000002cu;
goto P_0c0365d6;
P_0c0365d6: /* original d31b, guest PC 0x0c0365d6 */
if(!s->budget--) { s->failed_pc=0x0c0365d6u; return 0; }
r[3]=read(ram,0x0c036644u,4);
goto P_0c0365d8;
P_0c0365d8: /* original 4f12, guest PC 0x0c0365d8 */
if(!s->budget--) { s->failed_pc=0x0c0365d8u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0365da;
P_0c0365da: /* original 242f, guest PC 0x0c0365da */
if(!s->budget--) { s->failed_pc=0x0c0365dau; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[2]);
goto P_0c0365dc;
P_0c0365dc: /* original 6032, guest PC 0x0c0365dc */
if(!s->budget--) { s->failed_pc=0x0c0365dcu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0365de;
P_0c0365de: /* original 7028, guest PC 0x0c0365de */
if(!s->budget--) { s->failed_pc=0x0c0365deu; return 0; }
r[0]+=0x00000028u;
goto P_0c0365e0;
P_0c0365e0: /* original 041a, guest PC 0x0c0365e0 */
if(!s->budget--) { s->failed_pc=0x0c0365e0u; return 0; }
r[4]=r[19];
goto P_0c0365e2;
P_0c0365e2: /* original 644f, guest PC 0x0c0365e2 */
if(!s->budget--) { s->failed_pc=0x0c0365e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0365e4;
P_0c0365e4: /* original 304c, guest PC 0x0c0365e4 */
if(!s->budget--) { s->failed_pc=0x0c0365e4u; return 0; }
r[0]+=r[4];
goto P_0c0365e6;
P_0c0365e6: /* original 000b, guest PC 0x0c0365e6 */
if(!s->budget--) { s->failed_pc=0x0c0365e6u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c0365e8: /* original 4f16, guest PC 0x0c0365e8 */
if(!s->budget--) { s->failed_pc=0x0c0365e8u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0365ea;
P_0c0365ea: /* original e278, guest PC 0x0c0365ea */
if(!s->budget--) { s->failed_pc=0x0c0365eau; return 0; }
r[2]=0x00000078u;
goto P_0c0365ec;
P_0c0365ec: /* original d315, guest PC 0x0c0365ec */
if(!s->budget--) { s->failed_pc=0x0c0365ecu; return 0; }
r[3]=read(ram,0x0c036644u,4);
goto P_0c0365ee;
P_0c0365ee: /* original 4f12, guest PC 0x0c0365ee */
if(!s->budget--) { s->failed_pc=0x0c0365eeu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0365f0;
P_0c0365f0: /* original 242f, guest PC 0x0c0365f0 */
if(!s->budget--) { s->failed_pc=0x0c0365f0u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[2]);
goto P_0c0365f2;
P_0c0365f2: /* original 911f, guest PC 0x0c0365f2 */
if(!s->budget--) { s->failed_pc=0x0c0365f2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036634u,2);
goto P_0c0365f4;
P_0c0365f4: /* original 6032, guest PC 0x0c0365f4 */
if(!s->budget--) { s->failed_pc=0x0c0365f4u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0365f6;
P_0c0365f6: /* original 041a, guest PC 0x0c0365f6 */
if(!s->budget--) { s->failed_pc=0x0c0365f6u; return 0; }
r[4]=r[19];
goto P_0c0365f8;
P_0c0365f8: /* original 301c, guest PC 0x0c0365f8 */
if(!s->budget--) { s->failed_pc=0x0c0365f8u; return 0; }
r[0]+=r[1];
goto P_0c0365fa;
P_0c0365fa: /* original 644f, guest PC 0x0c0365fa */
if(!s->budget--) { s->failed_pc=0x0c0365fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0365fc;
P_0c0365fc: /* original 304c, guest PC 0x0c0365fc */
if(!s->budget--) { s->failed_pc=0x0c0365fcu; return 0; }
r[0]+=r[4];
goto P_0c0365fe;
P_0c0365fe: /* original 000b, guest PC 0x0c0365fe */
if(!s->budget--) { s->failed_pc=0x0c0365feu; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c036600: /* original 4f16, guest PC 0x0c036600 */
if(!s->budget--) { s->failed_pc=0x0c036600u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c036602u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c036602u; return 0; } return 1;
P_0c036610: /* original 4f22, guest PC 0x0c036610 */
if(!s->budget--) { s->failed_pc=0x0c036610u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c036612;
P_0c036612: /* original 7ffc, guest PC 0x0c036612 */
if(!s->budget--) { s->failed_pc=0x0c036612u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c036614;
P_0c036614: /* original bfde, guest PC 0x0c036614 */
if(!s->budget--) { s->failed_pc=0x0c036614u; return 0; }
target=code_base|0x0c0365d4u; r[16]=code_base|0x0c036618u;
write(ram,r[15],r[5],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c036618u) { target=s->pc; goto dispatch; }
goto P_0c036618;
P_0c036616: /* original 2f52, guest PC 0x0c036616 */
if(!s->budget--) { s->failed_pc=0x0c036616u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c036618;
P_0c036618: /* original 6403, guest PC 0x0c036618 */
if(!s->budget--) { s->failed_pc=0x0c036618u; return 0; }
r[4]=r[0];
goto P_0c03661a;
P_0c03661a: /* original 5348, guest PC 0x0c03661a */
if(!s->budget--) { s->failed_pc=0x0c03661au; return 0; }
r[3]=read(ram,r[4]+32,4);
goto P_0c03661c;
P_0c03661c: /* original 62f2, guest PC 0x0c03661c */
if(!s->budget--) { s->failed_pc=0x0c03661cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c03661e;
P_0c03661e: /* original 3320, guest PC 0x0c03661e */
if(!s->budget--) { s->failed_pc=0x0c03661eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c036620;
P_0c036620: /* original 8b18, guest PC 0x0c036620 */
if(!s->budget--) { s->failed_pc=0x0c036620u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c036654; }
goto P_0c036622;
P_0c036622: /* original 7f04, guest PC 0x0c036622 */
if(!s->budget--) { s->failed_pc=0x0c036622u; return 0; }
r[15]+=0x00000004u;
goto P_0c036624;
P_0c036624: /* original 4f26, guest PC 0x0c036624 */
if(!s->budget--) { s->failed_pc=0x0c036624u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c036626;
P_0c036626: /* original 000b, guest PC 0x0c036626 */
if(!s->budget--) { s->failed_pc=0x0c036626u; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c036628: /* original e001, guest PC 0x0c036628 */
if(!s->budget--) { s->failed_pc=0x0c036628u; return 0; }
r[0]=0x00000001u;
if(!vf3_matrix_family(0x0c03662au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03662au; return 0; } return 1;
P_0c036654: /* original e000, guest PC 0x0c036654 */
if(!s->budget--) { s->failed_pc=0x0c036654u; return 0; }
r[0]=0x00000000u;
goto P_0c036656;
P_0c036656: /* original 7f04, guest PC 0x0c036656 */
if(!s->budget--) { s->failed_pc=0x0c036656u; return 0; }
r[15]+=0x00000004u;
goto P_0c036658;
P_0c036658: /* original 4f26, guest PC 0x0c036658 */
if(!s->budget--) { s->failed_pc=0x0c036658u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03665a;
P_0c03665a: /* original 000b, guest PC 0x0c03665a */
if(!s->budget--) { s->failed_pc=0x0c03665au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03665c: /* original 0009, guest PC 0x0c03665c */
if(!s->budget--) { s->failed_pc=0x0c03665cu; return 0; }
if(!vf3_matrix_family(0x0c03665eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03665eu; return 0; } return 1;
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
P_0c038990: /* original 6043, guest PC 0x0c038990 */
if(!s->budget--) { s->failed_pc=0x0c038990u; return 0; }
r[0]=r[4];
goto P_0c038992;
P_0c038992: /* original 8808, guest PC 0x0c038992 */
if(!s->budget--) { s->failed_pc=0x0c038992u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c038994;
P_0c038994: /* original 8b04, guest PC 0x0c038994 */
if(!s->budget--) { s->failed_pc=0x0c038994u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0389a0; }
goto P_0c038996;
P_0c038996: /* original a03f, guest PC 0x0c038996 */
if(!s->budget--) { s->failed_pc=0x0c038996u; return 0; }
r[4]=0x00000000u;
goto P_0c038a18;
P_0c038998: /* original e400, guest PC 0x0c038998 */
if(!s->budget--) { s->failed_pc=0x0c038998u; return 0; }
r[4]=0x00000000u;
if(!vf3_matrix_family(0x0c03899au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03899au; return 0; } return 1;
P_0c0389a0: /* original 8810, guest PC 0x0c0389a0 */
if(!s->budget--) { s->failed_pc=0x0c0389a0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c0389a2;
P_0c0389a2: /* original 8b05, guest PC 0x0c0389a2 */
if(!s->budget--) { s->failed_pc=0x0c0389a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0389b0; }
goto P_0c0389a4;
P_0c0389a4: /* original a038, guest PC 0x0c0389a4 */
if(!s->budget--) { s->failed_pc=0x0c0389a4u; return 0; }
r[4]=0x00000001u;
goto P_0c038a18;
P_0c0389a6: /* original e401, guest PC 0x0c0389a6 */
if(!s->budget--) { s->failed_pc=0x0c0389a6u; return 0; }
r[4]=0x00000001u;
if(!vf3_matrix_family(0x0c0389a8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0389a8u; return 0; } return 1;
P_0c0389b0: /* original 6043, guest PC 0x0c0389b0 */
if(!s->budget--) { s->failed_pc=0x0c0389b0u; return 0; }
r[0]=r[4];
goto P_0c0389b2;
P_0c0389b2: /* original 8820, guest PC 0x0c0389b2 */
if(!s->budget--) { s->failed_pc=0x0c0389b2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c0389b4;
P_0c0389b4: /* original 8b04, guest PC 0x0c0389b4 */
if(!s->budget--) { s->failed_pc=0x0c0389b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0389c0; }
goto P_0c0389b6;
P_0c0389b6: /* original a02f, guest PC 0x0c0389b6 */
if(!s->budget--) { s->failed_pc=0x0c0389b6u; return 0; }
r[4]=0x00000002u;
goto P_0c038a18;
P_0c0389b8: /* original e402, guest PC 0x0c0389b8 */
if(!s->budget--) { s->failed_pc=0x0c0389b8u; return 0; }
r[4]=0x00000002u;
if(!vf3_matrix_family(0x0c0389bau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0389bau; return 0; } return 1;
P_0c0389c0: /* original 8840, guest PC 0x0c0389c0 */
if(!s->budget--) { s->failed_pc=0x0c0389c0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c0389c2;
P_0c0389c2: /* original 8b0d, guest PC 0x0c0389c2 */
if(!s->budget--) { s->failed_pc=0x0c0389c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0389e0; }
goto P_0c0389c4;
P_0c0389c4: /* original a028, guest PC 0x0c0389c4 */
if(!s->budget--) { s->failed_pc=0x0c0389c4u; return 0; }
r[4]=0x00000003u;
goto P_0c038a18;
P_0c0389c6: /* original e403, guest PC 0x0c0389c6 */
if(!s->budget--) { s->failed_pc=0x0c0389c6u; return 0; }
r[4]=0x00000003u;
if(!vf3_matrix_family(0x0c0389c8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0389c8u; return 0; } return 1;
P_0c0389e0: /* original 9387, guest PC 0x0c0389e0 */
if(!s->budget--) { s->failed_pc=0x0c0389e0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c038af2u,2);
goto P_0c0389e2;
P_0c0389e2: /* original 3430, guest PC 0x0c0389e2 */
if(!s->budget--) { s->failed_pc=0x0c0389e2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c0389e4;
P_0c0389e4: /* original 8b04, guest PC 0x0c0389e4 */
if(!s->budget--) { s->failed_pc=0x0c0389e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0389f0; }
goto P_0c0389e6;
P_0c0389e6: /* original a017, guest PC 0x0c0389e6 */
if(!s->budget--) { s->failed_pc=0x0c0389e6u; return 0; }
r[4]=0x00000004u;
goto P_0c038a18;
P_0c0389e8: /* original e404, guest PC 0x0c0389e8 */
if(!s->budget--) { s->failed_pc=0x0c0389e8u; return 0; }
r[4]=0x00000004u;
if(!vf3_matrix_family(0x0c0389eau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0389eau; return 0; } return 1;
P_0c0389f0: /* original 9280, guest PC 0x0c0389f0 */
if(!s->budget--) { s->failed_pc=0x0c0389f0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c038af4u,2);
goto P_0c0389f2;
P_0c0389f2: /* original 3420, guest PC 0x0c0389f2 */
if(!s->budget--) { s->failed_pc=0x0c0389f2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c0389f4;
P_0c0389f4: /* original 8b04, guest PC 0x0c0389f4 */
if(!s->budget--) { s->failed_pc=0x0c0389f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c038a00; }
goto P_0c0389f6;
P_0c0389f6: /* original a00f, guest PC 0x0c0389f6 */
if(!s->budget--) { s->failed_pc=0x0c0389f6u; return 0; }
r[4]=0x00000005u;
goto P_0c038a18;
P_0c0389f8: /* original e405, guest PC 0x0c0389f8 */
if(!s->budget--) { s->failed_pc=0x0c0389f8u; return 0; }
r[4]=0x00000005u;
if(!vf3_matrix_family(0x0c0389fau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0389fau; return 0; } return 1;
P_0c038a00: /* original 9179, guest PC 0x0c038a00 */
if(!s->budget--) { s->failed_pc=0x0c038a00u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c038af6u,2);
goto P_0c038a02;
P_0c038a02: /* original 3410, guest PC 0x0c038a02 */
if(!s->budget--) { s->failed_pc=0x0c038a02u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[1])!=0);
goto P_0c038a04;
P_0c038a04: /* original 8b04, guest PC 0x0c038a04 */
if(!s->budget--) { s->failed_pc=0x0c038a04u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c038a10; }
goto P_0c038a06;
P_0c038a06: /* original a007, guest PC 0x0c038a06 */
if(!s->budget--) { s->failed_pc=0x0c038a06u; return 0; }
r[4]=0x00000006u;
goto P_0c038a18;
P_0c038a08: /* original e406, guest PC 0x0c038a08 */
if(!s->budget--) { s->failed_pc=0x0c038a08u; return 0; }
r[4]=0x00000006u;
if(!vf3_matrix_family(0x0c038a0au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038a0au; return 0; } return 1;
P_0c038a10: /* original 9372, guest PC 0x0c038a10 */
if(!s->budget--) { s->failed_pc=0x0c038a10u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c038af8u,2);
goto P_0c038a12;
P_0c038a12: /* original 3430, guest PC 0x0c038a12 */
if(!s->budget--) { s->failed_pc=0x0c038a12u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c038a14;
P_0c038a14: /* original 8b00, guest PC 0x0c038a14 */
if(!s->budget--) { s->failed_pc=0x0c038a14u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c038a18; }
goto P_0c038a16;
P_0c038a16: /* original e407, guest PC 0x0c038a16 */
if(!s->budget--) { s->failed_pc=0x0c038a16u; return 0; }
r[4]=0x00000007u;
goto P_0c038a18;
P_0c038a18: /* original 000b, guest PC 0x0c038a18 */
if(!s->budget--) { s->failed_pc=0x0c038a18u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c038a1a: /* original 6043, guest PC 0x0c038a1a */
if(!s->budget--) { s->failed_pc=0x0c038a1au; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c038a1cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038a1cu; return 0; } return 1;
P_0c038a20: /* original e23c, guest PC 0x0c038a20 */
if(!s->budget--) { s->failed_pc=0x0c038a20u; return 0; }
r[2]=0x0000003cu;
goto P_0c038a22;
P_0c038a22: /* original d036, guest PC 0x0c038a22 */
if(!s->budget--) { s->failed_pc=0x0c038a22u; return 0; }
r[0]=read(ram,0x0c038afcu,4);
goto P_0c038a24;
P_0c038a24: /* original 4f12, guest PC 0x0c038a24 */
if(!s->budget--) { s->failed_pc=0x0c038a24u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c038a26;
P_0c038a26: /* original 0527, guest PC 0x0c038a26 */
if(!s->budget--) { s->failed_pc=0x0c038a26u; return 0; }
r[19]=r[5]*r[2];
goto P_0c038a28;
P_0c038a28: /* original 6102, guest PC 0x0c038a28 */
if(!s->budget--) { s->failed_pc=0x0c038a28u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c038a2a;
P_0c038a2a: /* original e3c0, guest PC 0x0c038a2a */
if(!s->budget--) { s->failed_pc=0x0c038a2au; return 0; }
r[3]=0xffffffc0u;
goto P_0c038a2c;
P_0c038a2c: /* original 5642, guest PC 0x0c038a2c */
if(!s->budget--) { s->failed_pc=0x0c038a2cu; return 0; }
r[6]=read(ram,r[4]+8,4);
goto P_0c038a2e;
P_0c038a2e: /* original e700, guest PC 0x0c038a2e */
if(!s->budget--) { s->failed_pc=0x0c038a2eu; return 0; }
r[7]=0x00000000u;
goto P_0c038a30;
P_0c038a30: /* original 051a, guest PC 0x0c038a30 */
if(!s->budget--) { s->failed_pc=0x0c038a30u; return 0; }
r[5]=r[19];
goto P_0c038a32;
P_0c038a32: /* original 2639, guest PC 0x0c038a32 */
if(!s->budget--) { s->failed_pc=0x0c038a32u; return 0; }
r[6]&=r[3];
goto P_0c038a34;
P_0c038a34: /* original 351c, guest PC 0x0c038a34 */
if(!s->budget--) { s->failed_pc=0x0c038a34u; return 0; }
r[5]+=r[1];
goto P_0c038a36;
P_0c038a36: /* original 525d, guest PC 0x0c038a36 */
if(!s->budget--) { s->failed_pc=0x0c038a36u; return 0; }
r[2]=read(ram,r[5]+52,4);
goto P_0c038a38;
P_0c038a38: /* original 535c, guest PC 0x0c038a38 */
if(!s->budget--) { s->failed_pc=0x0c038a38u; return 0; }
r[3]=read(ram,r[5]+48,4);
goto P_0c038a3a;
P_0c038a3a: /* original 272b, guest PC 0x0c038a3a */
if(!s->budget--) { s->failed_pc=0x0c038a3au; return 0; }
r[7]|=r[2];
goto P_0c038a3c;
P_0c038a3c: /* original 263b, guest PC 0x0c038a3c */
if(!s->budget--) { s->failed_pc=0x0c038a3cu; return 0; }
r[6]|=r[3];
goto P_0c038a3e;
P_0c038a3e: /* original 1462, guest PC 0x0c038a3e */
if(!s->budget--) { s->failed_pc=0x0c038a3eu; return 0; }
write(ram,r[4]+8,r[6],4);
goto P_0c038a40;
P_0c038a40: /* original 1473, guest PC 0x0c038a40 */
if(!s->budget--) { s->failed_pc=0x0c038a40u; return 0; }
write(ram,r[4]+12,r[7],4);
goto P_0c038a42;
P_0c038a42: /* original 000b, guest PC 0x0c038a42 */
if(!s->budget--) { s->failed_pc=0x0c038a42u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c038a44: /* original 4f16, guest PC 0x0c038a44 */
if(!s->budget--) { s->failed_pc=0x0c038a44u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c038a46u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038a46u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
