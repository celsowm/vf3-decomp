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
int vf3_away_batch20_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042900u: goto P_0c042900;
case 0x0c042902u: goto P_0c042902;
case 0x0c042904u: goto P_0c042904;
case 0x0c042906u: goto P_0c042906;
case 0x0c042908u: goto P_0c042908;
case 0x0c04290au: goto P_0c04290a;
case 0x0c04290cu: goto P_0c04290c;
case 0x0c04290eu: goto P_0c04290e;
case 0x0c042910u: goto P_0c042910;
case 0x0c042912u: goto P_0c042912;
case 0x0c042914u: goto P_0c042914;
case 0x0c042930u: goto P_0c042930;
case 0x0c042932u: goto P_0c042932;
case 0x0c042934u: goto P_0c042934;
case 0x0c042936u: goto P_0c042936;
case 0x0c042938u: goto P_0c042938;
case 0x0c04293au: goto P_0c04293a;
case 0x0c04293cu: goto P_0c04293c;
case 0x0c04293eu: goto P_0c04293e;
case 0x0c042940u: goto P_0c042940;
case 0x0c042942u: goto P_0c042942;
case 0x0c042944u: goto P_0c042944;
case 0x0c042946u: goto P_0c042946;
case 0x0c042948u: goto P_0c042948;
case 0x0c04294au: goto P_0c04294a;
case 0x0c042950u: goto P_0c042950;
case 0x0c042952u: goto P_0c042952;
case 0x0c042954u: goto P_0c042954;
case 0x0c042960u: goto P_0c042960;
case 0x0c042962u: goto P_0c042962;
case 0x0c042964u: goto P_0c042964;
case 0x0c042970u: goto P_0c042970;
case 0x0c042972u: goto P_0c042972;
case 0x0c042974u: goto P_0c042974;
case 0x0c0429b0u: goto P_0c0429b0;
case 0x0c0429b2u: goto P_0c0429b2;
case 0x0c0429b4u: goto P_0c0429b4;
case 0x0c0429b6u: goto P_0c0429b6;
case 0x0c0429b8u: goto P_0c0429b8;
case 0x0c0429bau: goto P_0c0429ba;
case 0x0c0429bcu: goto P_0c0429bc;
case 0x0c0429beu: goto P_0c0429be;
case 0x0c0429c0u: goto P_0c0429c0;
case 0x0c0429c2u: goto P_0c0429c2;
case 0x0c0429c4u: goto P_0c0429c4;
case 0x0c0429c6u: goto P_0c0429c6;
case 0x0c0429c8u: goto P_0c0429c8;
case 0x0c0429cau: goto P_0c0429ca;
case 0x0c0429ccu: goto P_0c0429cc;
case 0x0c0429ceu: goto P_0c0429ce;
case 0x0c0429d0u: goto P_0c0429d0;
case 0x0c0429d2u: goto P_0c0429d2;
case 0x0c0429d4u: goto P_0c0429d4;
case 0x0c0429d6u: goto P_0c0429d6;
case 0x0c0429d8u: goto P_0c0429d8;
case 0x0c0429dau: goto P_0c0429da;
case 0x0c0429dcu: goto P_0c0429dc;
case 0x0c0429deu: goto P_0c0429de;
case 0x0c0429e0u: goto P_0c0429e0;
case 0x0c0429e2u: goto P_0c0429e2;
case 0x0c0429e4u: goto P_0c0429e4;
case 0x0c0429e6u: goto P_0c0429e6;
case 0x0c0429e8u: goto P_0c0429e8;
case 0x0c0429eau: goto P_0c0429ea;
case 0x0c0429ecu: goto P_0c0429ec;
case 0x0c0429eeu: goto P_0c0429ee;
case 0x0c0429f0u: goto P_0c0429f0;
case 0x0c0429f2u: goto P_0c0429f2;
case 0x0c0429f4u: goto P_0c0429f4;
case 0x0c0429f6u: goto P_0c0429f6;
case 0x0c0429f8u: goto P_0c0429f8;
case 0x0c0429fau: goto P_0c0429fa;
case 0x0c0429fcu: goto P_0c0429fc;
case 0x0c0429feu: goto P_0c0429fe;
case 0x0c042a00u: goto P_0c042a00;
case 0x0c042a02u: goto P_0c042a02;
case 0x0c042a04u: goto P_0c042a04;
case 0x0c042a06u: goto P_0c042a06;
case 0x0c042a08u: goto P_0c042a08;
case 0x0c042a0au: goto P_0c042a0a;
case 0x0c042a0cu: goto P_0c042a0c;
case 0x0c042a0eu: goto P_0c042a0e;
case 0x0c042a10u: goto P_0c042a10;
case 0x0c042a12u: goto P_0c042a12;
case 0x0c042a14u: goto P_0c042a14;
case 0x0c042a16u: goto P_0c042a16;
case 0x0c042a18u: goto P_0c042a18;
case 0x0c042a1au: goto P_0c042a1a;
case 0x0c042a1cu: goto P_0c042a1c;
case 0x0c042a1eu: goto P_0c042a1e;
case 0x0c042a20u: goto P_0c042a20;
case 0x0c042a22u: goto P_0c042a22;
case 0x0c042a24u: goto P_0c042a24;
case 0x0c042a26u: goto P_0c042a26;
case 0x0c042a28u: goto P_0c042a28;
case 0x0c042a2au: goto P_0c042a2a;
case 0x0c042a2cu: goto P_0c042a2c;
case 0x0c042a2eu: goto P_0c042a2e;
case 0x0c042a30u: goto P_0c042a30;
case 0x0c042a32u: goto P_0c042a32;
case 0x0c042a34u: goto P_0c042a34;
case 0x0c042a36u: goto P_0c042a36;
case 0x0c042a38u: goto P_0c042a38;
case 0x0c042a3au: goto P_0c042a3a;
case 0x0c042a3cu: goto P_0c042a3c;
case 0x0c042a3eu: goto P_0c042a3e;
case 0x0c042a40u: goto P_0c042a40;
case 0x0c042a42u: goto P_0c042a42;
case 0x0c042a44u: goto P_0c042a44;
case 0x0c042a46u: goto P_0c042a46;
case 0x0c042a48u: goto P_0c042a48;
case 0x0c042a4au: goto P_0c042a4a;
case 0x0c042a4cu: goto P_0c042a4c;
case 0x0c042a4eu: goto P_0c042a4e;
case 0x0c042a50u: goto P_0c042a50;
case 0x0c042a52u: goto P_0c042a52;
case 0x0c042a54u: goto P_0c042a54;
case 0x0c042a56u: goto P_0c042a56;
case 0x0c042a58u: goto P_0c042a58;
case 0x0c042a5au: goto P_0c042a5a;
case 0x0c042a5cu: goto P_0c042a5c;
case 0x0c042a5eu: goto P_0c042a5e;
case 0x0c042a60u: goto P_0c042a60;
case 0x0c042a62u: goto P_0c042a62;
case 0x0c042a64u: goto P_0c042a64;
case 0x0c042a66u: goto P_0c042a66;
case 0x0c042a68u: goto P_0c042a68;
case 0x0c042a6au: goto P_0c042a6a;
case 0x0c042a6cu: goto P_0c042a6c;
case 0x0c042a6eu: goto P_0c042a6e;
case 0x0c042a70u: goto P_0c042a70;
case 0x0c042a72u: goto P_0c042a72;
case 0x0c042a74u: goto P_0c042a74;
case 0x0c042a76u: goto P_0c042a76;
case 0x0c042a78u: goto P_0c042a78;
case 0x0c042a7au: goto P_0c042a7a;
case 0x0c042a7cu: goto P_0c042a7c;
case 0x0c042a7eu: goto P_0c042a7e;
case 0x0c042aa0u: goto P_0c042aa0;
case 0x0c042aa2u: goto P_0c042aa2;
case 0x0c042aa4u: goto P_0c042aa4;
case 0x0c042aa6u: goto P_0c042aa6;
case 0x0c042aa8u: goto P_0c042aa8;
case 0x0c042aaau: goto P_0c042aaa;
case 0x0c042aacu: goto P_0c042aac;
case 0x0c042aaeu: goto P_0c042aae;
case 0x0c042ab0u: goto P_0c042ab0;
case 0x0c042ab2u: goto P_0c042ab2;
case 0x0c042ab4u: goto P_0c042ab4;
case 0x0c042ab6u: goto P_0c042ab6;
case 0x0c042ab8u: goto P_0c042ab8;
case 0x0c042abau: goto P_0c042aba;
case 0x0c042abcu: goto P_0c042abc;
case 0x0c042abeu: goto P_0c042abe;
case 0x0c042ac0u: goto P_0c042ac0;
case 0x0c042ac2u: goto P_0c042ac2;
case 0x0c042ac4u: goto P_0c042ac4;
case 0x0c042ad0u: goto P_0c042ad0;
case 0x0c042ad2u: goto P_0c042ad2;
case 0x0c042ad4u: goto P_0c042ad4;
case 0x0c042ad6u: goto P_0c042ad6;
case 0x0c042ad8u: goto P_0c042ad8;
case 0x0c042adau: goto P_0c042ada;
case 0x0c042ae0u: goto P_0c042ae0;
case 0x0c042ae2u: goto P_0c042ae2;
case 0x0c042ae4u: goto P_0c042ae4;
case 0x0c042ae6u: goto P_0c042ae6;
case 0x0c042ae8u: goto P_0c042ae8;
case 0x0c042aeau: goto P_0c042aea;
case 0x0c042aecu: goto P_0c042aec;
case 0x0c042aeeu: goto P_0c042aee;
case 0x0c042af0u: goto P_0c042af0;
case 0x0c042af2u: goto P_0c042af2;
case 0x0c042af4u: goto P_0c042af4;
case 0x0c042af6u: goto P_0c042af6;
case 0x0c042af8u: goto P_0c042af8;
case 0x0c042afau: goto P_0c042afa;
case 0x0c042afcu: goto P_0c042afc;
case 0x0c042afeu: goto P_0c042afe;
case 0x0c042b00u: goto P_0c042b00;
case 0x0c042b02u: goto P_0c042b02;
case 0x0c042b04u: goto P_0c042b04;
case 0x0c042b06u: goto P_0c042b06;
case 0x0c042b10u: goto P_0c042b10;
case 0x0c042b12u: goto P_0c042b12;
case 0x0c042b14u: goto P_0c042b14;
case 0x0c042b16u: goto P_0c042b16;
case 0x0c042b18u: goto P_0c042b18;
case 0x0c042b1au: goto P_0c042b1a;
case 0x0c042b1cu: goto P_0c042b1c;
case 0x0c042b1eu: goto P_0c042b1e;
case 0x0c042b20u: goto P_0c042b20;
case 0x0c042b22u: goto P_0c042b22;
case 0x0c042b24u: goto P_0c042b24;
case 0x0c042b26u: goto P_0c042b26;
case 0x0c042b30u: goto P_0c042b30;
case 0x0c042b32u: goto P_0c042b32;
case 0x0c042b34u: goto P_0c042b34;
case 0x0c042b36u: goto P_0c042b36;
case 0x0c042b38u: goto P_0c042b38;
case 0x0c042b3au: goto P_0c042b3a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c042900: /* original 4f22, guest PC 0x0c042900 */
if(!s->budget--) { s->failed_pc=0x0c042900u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c042902;
P_0c042902: /* original e503, guest PC 0x0c042902 */
if(!s->budget--) { s->failed_pc=0x0c042902u; return 0; }
r[5]=0x00000003u;
goto P_0c042904;
P_0c042904: /* original 60f3, guest PC 0x0c042904 */
if(!s->budget--) { s->failed_pc=0x0c042904u; return 0; }
r[0]=r[15];
goto P_0c042906;
P_0c042906: /* original 7004, guest PC 0x0c042906 */
if(!s->budget--) { s->failed_pc=0x0c042906u; return 0; }
r[0]+=0x00000004u;
goto P_0c042908;
P_0c042908: /* original 7004, guest PC 0x0c042908 */
if(!s->budget--) { s->failed_pc=0x0c042908u; return 0; }
r[0]+=0x00000004u;
goto P_0c04290a;
P_0c04290a: /* original 2508, guest PC 0x0c04290a */
if(!s->budget--) { s->failed_pc=0x0c04290au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[0])==0)!=0);
goto P_0c04290c;
P_0c04290c: /* original 8910, guest PC 0x0c04290c */
if(!s->budget--) { s->failed_pc=0x0c04290cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042930; }
goto P_0c04290e;
P_0c04290e: /* original 65f3, guest PC 0x0c04290e */
if(!s->budget--) { s->failed_pc=0x0c04290eu; return 0; }
r[5]=r[15];
goto P_0c042910;
P_0c042910: /* original 7504, guest PC 0x0c042910 */
if(!s->budget--) { s->failed_pc=0x0c042910u; return 0; }
r[5]+=0x00000004u;
goto P_0c042912;
P_0c042912: /* original a010, guest PC 0x0c042912 */
if(!s->budget--) { s->failed_pc=0x0c042912u; return 0; }
r[5]+=0x00000008u;
goto P_0c042936;
P_0c042914: /* original 7508, guest PC 0x0c042914 */
if(!s->budget--) { s->failed_pc=0x0c042914u; return 0; }
r[5]+=0x00000008u;
if(!vf3_matrix_family(0x0c042916u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042916u; return 0; } return 1;
P_0c042930: /* original 65f3, guest PC 0x0c042930 */
if(!s->budget--) { s->failed_pc=0x0c042930u; return 0; }
r[5]=r[15];
goto P_0c042932;
P_0c042932: /* original 7504, guest PC 0x0c042932 */
if(!s->budget--) { s->failed_pc=0x0c042932u; return 0; }
r[5]+=0x00000004u;
goto P_0c042934;
P_0c042934: /* original 7504, guest PC 0x0c042934 */
if(!s->budget--) { s->failed_pc=0x0c042934u; return 0; }
r[5]+=0x00000004u;
goto P_0c042936;
P_0c042936: /* original d318, guest PC 0x0c042936 */
if(!s->budget--) { s->failed_pc=0x0c042936u; return 0; }
r[3]=read(ram,0x0c042998u,4);
goto P_0c042938;
P_0c042938: /* original 6653, guest PC 0x0c042938 */
if(!s->budget--) { s->failed_pc=0x0c042938u; return 0; }
r[6]=r[5];
goto P_0c04293a;
P_0c04293a: /* original d416, guest PC 0x0c04293a */
if(!s->budget--) { s->failed_pc=0x0c04293au; return 0; }
r[4]=read(ram,0x0c042994u,4);
goto P_0c04293c;
P_0c04293c: /* original 430b, guest PC 0x0c04293c */
if(!s->budget--) { s->failed_pc=0x0c04293cu; return 0; }
target=r[3];
r[16]=code_base|0x0c042940u;
r[5]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c042940u) { target=s->pc; goto dispatch; }
goto P_0c042940;
P_0c04293e: /* original 55f1, guest PC 0x0c04293e */
if(!s->budget--) { s->failed_pc=0x0c04293eu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c042940;
P_0c042940: /* original d414, guest PC 0x0c042940 */
if(!s->budget--) { s->failed_pc=0x0c042940u; return 0; }
r[4]=read(ram,0x0c042994u,4);
goto P_0c042942;
P_0c042942: /* original bf25, guest PC 0x0c042942 */
if(!s->budget--) { s->failed_pc=0x0c042942u; return 0; }
target=code_base|0x0c042790u; r[16]=code_base|0x0c042946u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c042946u) { target=s->pc; goto dispatch; }
goto P_0c042946;
P_0c042944: /* original 0009, guest PC 0x0c042944 */
if(!s->budget--) { s->failed_pc=0x0c042944u; return 0; }
goto P_0c042946;
P_0c042946: /* original 4f26, guest PC 0x0c042946 */
if(!s->budget--) { s->failed_pc=0x0c042946u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c042948;
P_0c042948: /* original 000b, guest PC 0x0c042948 */
if(!s->budget--) { s->failed_pc=0x0c042948u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c04294a: /* original e000, guest PC 0x0c04294a */
if(!s->budget--) { s->failed_pc=0x0c04294au; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c04294cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04294cu; return 0; } return 1;
P_0c042950: /* original d312, guest PC 0x0c042950 */
if(!s->budget--) { s->failed_pc=0x0c042950u; return 0; }
r[3]=read(ram,0x0c04299cu,4);
goto P_0c042952;
P_0c042952: /* original 000b, guest PC 0x0c042952 */
if(!s->budget--) { s->failed_pc=0x0c042952u; return 0; }
target=r[16];
write(ram,r[3],r[4],1);
s->pc=target; return ram->oob==0;
P_0c042954: /* original 2340, guest PC 0x0c042954 */
if(!s->budget--) { s->failed_pc=0x0c042954u; return 0; }
write(ram,r[3],r[4],1);
if(!vf3_matrix_family(0x0c042956u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042956u; return 0; } return 1;
P_0c042960: /* original d20f, guest PC 0x0c042960 */
if(!s->budget--) { s->failed_pc=0x0c042960u; return 0; }
r[2]=read(ram,0x0c0429a0u,4);
goto P_0c042962;
P_0c042962: /* original 000b, guest PC 0x0c042962 */
if(!s->budget--) { s->failed_pc=0x0c042962u; return 0; }
target=r[16];
write(ram,r[2],r[4],1);
s->pc=target; return ram->oob==0;
P_0c042964: /* original 2240, guest PC 0x0c042964 */
if(!s->budget--) { s->failed_pc=0x0c042964u; return 0; }
write(ram,r[2],r[4],1);
if(!vf3_matrix_family(0x0c042966u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042966u; return 0; } return 1;
P_0c042970: /* original d30c, guest PC 0x0c042970 */
if(!s->budget--) { s->failed_pc=0x0c042970u; return 0; }
r[3]=read(ram,0x0c0429a4u,4);
goto P_0c042972;
P_0c042972: /* original 000b, guest PC 0x0c042972 */
if(!s->budget--) { s->failed_pc=0x0c042972u; return 0; }
target=r[16];
write(ram,r[3],r[4],1);
s->pc=target; return ram->oob==0;
P_0c042974: /* original 2340, guest PC 0x0c042974 */
if(!s->budget--) { s->failed_pc=0x0c042974u; return 0; }
write(ram,r[3],r[4],1);
if(!vf3_matrix_family(0x0c042976u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042976u; return 0; } return 1;
P_0c0429b0: /* original 2fe6, guest PC 0x0c0429b0 */
if(!s->budget--) { s->failed_pc=0x0c0429b0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0429b2;
P_0c0429b2: /* original 2fb6, guest PC 0x0c0429b2 */
if(!s->budget--) { s->failed_pc=0x0c0429b2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0429b4;
P_0c0429b4: /* original 2fa6, guest PC 0x0c0429b4 */
if(!s->budget--) { s->failed_pc=0x0c0429b4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0429b6;
P_0c0429b6: /* original 2f96, guest PC 0x0c0429b6 */
if(!s->budget--) { s->failed_pc=0x0c0429b6u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0429b8;
P_0c0429b8: /* original d233, guest PC 0x0c0429b8 */
if(!s->budget--) { s->failed_pc=0x0c0429b8u; return 0; }
r[2]=read(ram,0x0c042a88u,4);
goto P_0c0429ba;
P_0c0429ba: /* original 6922, guest PC 0x0c0429ba */
if(!s->budget--) { s->failed_pc=0x0c0429bau; return 0; }
tmp=read(ram,r[2],4);
r[9]=tmp;
goto P_0c0429bc;
P_0c0429bc: /* original 2998, guest PC 0x0c0429bc */
if(!s->budget--) { s->failed_pc=0x0c0429bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0429be;
P_0c0429be: /* original 893a, guest PC 0x0c0429be */
if(!s->budget--) { s->failed_pc=0x0c0429beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a36; }
goto P_0c0429c0;
P_0c0429c0: /* original 4611, guest PC 0x0c0429c0 */
if(!s->budget--) { s->failed_pc=0x0c0429c0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=0)!=0);
goto P_0c0429c2;
P_0c0429c2: /* original 8b38, guest PC 0x0c0429c2 */
if(!s->budget--) { s->failed_pc=0x0c0429c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042a36; }
goto P_0c0429c4;
P_0c0429c4: /* original 975c, guest PC 0x0c0429c4 */
if(!s->budget--) { s->failed_pc=0x0c0429c4u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042a80u,2);
goto P_0c0429c6;
P_0c0429c6: /* original 3472, guest PC 0x0c0429c6 */
if(!s->budget--) { s->failed_pc=0x0c0429c6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[7])!=0);
goto P_0c0429c8;
P_0c0429c8: /* original 8935, guest PC 0x0c0429c8 */
if(!s->budget--) { s->failed_pc=0x0c0429c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a36; }
goto P_0c0429ca;
P_0c0429ca: /* original 3572, guest PC 0x0c0429ca */
if(!s->budget--) { s->failed_pc=0x0c0429cau; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[7])!=0);
goto P_0c0429cc;
P_0c0429cc: /* original 8933, guest PC 0x0c0429cc */
if(!s->budget--) { s->failed_pc=0x0c0429ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a36; }
goto P_0c0429ce;
P_0c0429ce: /* original 6343, guest PC 0x0c0429ce */
if(!s->budget--) { s->failed_pc=0x0c0429ceu; return 0; }
r[3]=r[4];
goto P_0c0429d0;
P_0c0429d0: /* original e701, guest PC 0x0c0429d0 */
if(!s->budget--) { s->failed_pc=0x0c0429d0u; return 0; }
r[7]=0x00000001u;
goto P_0c0429d2;
P_0c0429d2: /* original 2378, guest PC 0x0c0429d2 */
if(!s->budget--) { s->failed_pc=0x0c0429d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c0429d4;
P_0c0429d4: /* original 8d03, guest PC 0x0c0429d4 */
if(!s->budget--) { s->failed_pc=0x0c0429d4u; return 0; }
cond=r[17]&1u;
r[10]=0x00000003u;
if(cond) { goto P_0c0429de; }
goto P_0c0429d8;
P_0c0429d6: /* original ea03, guest PC 0x0c0429d6 */
if(!s->budget--) { s->failed_pc=0x0c0429d6u; return 0; }
r[10]=0x00000003u;
goto P_0c0429d8;
P_0c0429d8: /* original 4608, guest PC 0x0c0429d8 */
if(!s->budget--) { s->failed_pc=0x0c0429d8u; return 0; }
r[6]<<=2;
goto P_0c0429da;
P_0c0429da: /* original 4608, guest PC 0x0c0429da */
if(!s->budget--) { s->failed_pc=0x0c0429dau; return 0; }
r[6]<<=2;
goto P_0c0429dc;
P_0c0429dc: /* original ea30, guest PC 0x0c0429dc */
if(!s->budget--) { s->failed_pc=0x0c0429dcu; return 0; }
r[10]=0x00000030u;
goto P_0c0429de;
P_0c0429de: /* original 6353, guest PC 0x0c0429de */
if(!s->budget--) { s->failed_pc=0x0c0429deu; return 0; }
r[3]=r[5];
goto P_0c0429e0;
P_0c0429e0: /* original 2378, guest PC 0x0c0429e0 */
if(!s->budget--) { s->failed_pc=0x0c0429e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c0429e2;
P_0c0429e2: /* original 8901, guest PC 0x0c0429e2 */
if(!s->budget--) { s->failed_pc=0x0c0429e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0429e8; }
goto P_0c0429e4;
P_0c0429e4: /* original 4608, guest PC 0x0c0429e4 */
if(!s->budget--) { s->failed_pc=0x0c0429e4u; return 0; }
r[6]<<=2;
goto P_0c0429e6;
P_0c0429e6: /* original 4a08, guest PC 0x0c0429e6 */
if(!s->budget--) { s->failed_pc=0x0c0429e6u; return 0; }
r[10]<<=2;
goto P_0c0429e8;
P_0c0429e8: /* original 934b, guest PC 0x0c0429e8 */
if(!s->budget--) { s->failed_pc=0x0c0429e8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042a82u,2);
goto P_0c0429ea;
P_0c0429ea: /* original 6e73, guest PC 0x0c0429ea */
if(!s->budget--) { s->failed_pc=0x0c0429eau; return 0; }
r[14]=r[7];
goto P_0c0429ec;
P_0c0429ec: /* original 914a, guest PC 0x0c0429ec */
if(!s->budget--) { s->failed_pc=0x0c0429ecu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042a84u,2);
goto P_0c0429ee;
P_0c0429ee: /* original eb00, guest PC 0x0c0429ee */
if(!s->budget--) { s->failed_pc=0x0c0429eeu; return 0; }
r[11]=0x00000000u;
goto P_0c0429f0;
P_0c0429f0: /* original 9048, guest PC 0x0c0429f0 */
if(!s->budget--) { s->failed_pc=0x0c0429f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042a84u,2);
goto P_0c0429f2;
P_0c0429f2: /* original 33a8, guest PC 0x0c0429f2 */
if(!s->budget--) { s->failed_pc=0x0c0429f2u; return 0; }
r[3]-=r[10];
goto P_0c0429f4;
P_0c0429f4: /* original 6a33, guest PC 0x0c0429f4 */
if(!s->budget--) { s->failed_pc=0x0c0429f4u; return 0; }
r[10]=r[3];
goto P_0c0429f6;
P_0c0429f6: /* original 4401, guest PC 0x0c0429f6 */
if(!s->budget--) { s->failed_pc=0x0c0429f6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c0429f8;
P_0c0429f8: /* original 4501, guest PC 0x0c0429f8 */
if(!s->budget--) { s->failed_pc=0x0c0429f8u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c0429fa;
P_0c0429fa: /* original 2008, guest PC 0x0c0429fa */
if(!s->budget--) { s->failed_pc=0x0c0429fau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0429fc;
P_0c0429fc: /* original 8906, guest PC 0x0c0429fc */
if(!s->budget--) { s->failed_pc=0x0c0429fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a0c; }
goto P_0c0429fe;
P_0c0429fe: /* original 6353, guest PC 0x0c0429fe */
if(!s->budget--) { s->failed_pc=0x0c0429feu; return 0; }
r[3]=r[5];
goto P_0c042a00;
P_0c042a00: /* original 2378, guest PC 0x0c042a00 */
if(!s->budget--) { s->failed_pc=0x0c042a00u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c042a02;
P_0c042a02: /* original 8900, guest PC 0x0c042a02 */
if(!s->budget--) { s->failed_pc=0x0c042a02u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a06; }
goto P_0c042a04;
P_0c042a04: /* original 2beb, guest PC 0x0c042a04 */
if(!s->budget--) { s->failed_pc=0x0c042a04u; return 0; }
r[11]|=r[14];
goto P_0c042a06;
P_0c042a06: /* original 4e00, guest PC 0x0c042a06 */
if(!s->budget--) { s->failed_pc=0x0c042a06u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c042a08;
P_0c042a08: /* original 4501, guest PC 0x0c042a08 */
if(!s->budget--) { s->failed_pc=0x0c042a08u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c042a0a;
P_0c042a0a: /* original 4021, guest PC 0x0c042a0a */
if(!s->budget--) { s->failed_pc=0x0c042a0au; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c042a0c;
P_0c042a0c: /* original 2118, guest PC 0x0c042a0c */
if(!s->budget--) { s->failed_pc=0x0c042a0cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c042a0e;
P_0c042a0e: /* original 8906, guest PC 0x0c042a0e */
if(!s->budget--) { s->failed_pc=0x0c042a0eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a1e; }
goto P_0c042a10;
P_0c042a10: /* original 6243, guest PC 0x0c042a10 */
if(!s->budget--) { s->failed_pc=0x0c042a10u; return 0; }
r[2]=r[4];
goto P_0c042a12;
P_0c042a12: /* original 2278, guest PC 0x0c042a12 */
if(!s->budget--) { s->failed_pc=0x0c042a12u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[7])==0)!=0);
goto P_0c042a14;
P_0c042a14: /* original 8900, guest PC 0x0c042a14 */
if(!s->budget--) { s->failed_pc=0x0c042a14u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a18; }
goto P_0c042a16;
P_0c042a16: /* original 2beb, guest PC 0x0c042a16 */
if(!s->budget--) { s->failed_pc=0x0c042a16u; return 0; }
r[11]|=r[14];
goto P_0c042a18;
P_0c042a18: /* original 4e00, guest PC 0x0c042a18 */
if(!s->budget--) { s->failed_pc=0x0c042a18u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c042a1a;
P_0c042a1a: /* original 4401, guest PC 0x0c042a1a */
if(!s->budget--) { s->failed_pc=0x0c042a1au; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c042a1c;
P_0c042a1c: /* original 4121, guest PC 0x0c042a1c */
if(!s->budget--) { s->failed_pc=0x0c042a1cu; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]=(uint32_t)((int32_t)r[1]>>1);
goto P_0c042a1e;
P_0c042a1e: /* original 6213, guest PC 0x0c042a1e */
if(!s->budget--) { s->failed_pc=0x0c042a1eu; return 0; }
r[2]=r[1];
goto P_0c042a20;
P_0c042a20: /* original 220b, guest PC 0x0c042a20 */
if(!s->budget--) { s->failed_pc=0x0c042a20u; return 0; }
r[2]|=r[0];
goto P_0c042a22;
P_0c042a22: /* original 2228, guest PC 0x0c042a22 */
if(!s->budget--) { s->failed_pc=0x0c042a22u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c042a24;
P_0c042a24: /* original 8be9, guest PC 0x0c042a24 */
if(!s->budget--) { s->failed_pc=0x0c042a24u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0429fa; }
goto P_0c042a26;
P_0c042a26: /* original 932e, guest PC 0x0c042a26 */
if(!s->budget--) { s->failed_pc=0x0c042a26u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042a86u,2);
goto P_0c042a28;
P_0c042a28: /* original 64b3, guest PC 0x0c042a28 */
if(!s->budget--) { s->failed_pc=0x0c042a28u; return 0; }
r[4]=r[11];
goto P_0c042a2a;
P_0c042a2a: /* original 349c, guest PC 0x0c042a2a */
if(!s->budget--) { s->failed_pc=0x0c042a2au; return 0; }
r[4]+=r[9];
goto P_0c042a2c;
P_0c042a2c: /* original 343c, guest PC 0x0c042a2c */
if(!s->budget--) { s->failed_pc=0x0c042a2cu; return 0; }
r[4]+=r[3];
goto P_0c042a2e;
P_0c042a2e: /* original 6240, guest PC 0x0c042a2e */
if(!s->budget--) { s->failed_pc=0x0c042a2eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c042a30;
P_0c042a30: /* original 2a29, guest PC 0x0c042a30 */
if(!s->budget--) { s->failed_pc=0x0c042a30u; return 0; }
r[10]&=r[2];
goto P_0c042a32;
P_0c042a32: /* original 2a6b, guest PC 0x0c042a32 */
if(!s->budget--) { s->failed_pc=0x0c042a32u; return 0; }
r[10]|=r[6];
goto P_0c042a34;
P_0c042a34: /* original 24a0, guest PC 0x0c042a34 */
if(!s->budget--) { s->failed_pc=0x0c042a34u; return 0; }
write(ram,r[4],r[10],1);
goto P_0c042a36;
P_0c042a36: /* original 69f6, guest PC 0x0c042a36 */
if(!s->budget--) { s->failed_pc=0x0c042a36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c042a38;
P_0c042a38: /* original 6af6, guest PC 0x0c042a38 */
if(!s->budget--) { s->failed_pc=0x0c042a38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c042a3a;
P_0c042a3a: /* original 6bf6, guest PC 0x0c042a3a */
if(!s->budget--) { s->failed_pc=0x0c042a3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c042a3c;
P_0c042a3c: /* original 000b, guest PC 0x0c042a3c */
if(!s->budget--) { s->failed_pc=0x0c042a3cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c042a3e: /* original 6ef6, guest PC 0x0c042a3e */
if(!s->budget--) { s->failed_pc=0x0c042a3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c042a40;
P_0c042a40: /* original 2fe6, guest PC 0x0c042a40 */
if(!s->budget--) { s->failed_pc=0x0c042a40u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042a42;
P_0c042a42: /* original 2fd6, guest PC 0x0c042a42 */
if(!s->budget--) { s->failed_pc=0x0c042a42u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042a44;
P_0c042a44: /* original 2fc6, guest PC 0x0c042a44 */
if(!s->budget--) { s->failed_pc=0x0c042a44u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042a46;
P_0c042a46: /* original dd10, guest PC 0x0c042a46 */
if(!s->budget--) { s->failed_pc=0x0c042a46u; return 0; }
r[13]=read(ram,0x0c042a88u,4);
goto P_0c042a48;
P_0c042a48: /* original 4f22, guest PC 0x0c042a48 */
if(!s->budget--) { s->failed_pc=0x0c042a48u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c042a4a;
P_0c042a4a: /* original 6ed2, guest PC 0x0c042a4a */
if(!s->budget--) { s->failed_pc=0x0c042a4au; return 0; }
tmp=read(ram,r[13],4);
r[14]=tmp;
goto P_0c042a4c;
P_0c042a4c: /* original 2ee8, guest PC 0x0c042a4c */
if(!s->budget--) { s->failed_pc=0x0c042a4cu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c042a4e;
P_0c042a4e: /* original 893f, guest PC 0x0c042a4e */
if(!s->budget--) { s->failed_pc=0x0c042a4eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042ad0; }
goto P_0c042a50;
P_0c042a50: /* original e202, guest PC 0x0c042a50 */
if(!s->budget--) { s->failed_pc=0x0c042a50u; return 0; }
r[2]=0x00000002u;
goto P_0c042a52;
P_0c042a52: /* original 6c4e, guest PC 0x0c042a52 */
if(!s->budget--) { s->failed_pc=0x0c042a52u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c042a54;
P_0c042a54: /* original 22c8, guest PC 0x0c042a54 */
if(!s->budget--) { s->failed_pc=0x0c042a54u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c042a56;
P_0c042a56: /* original 8903, guest PC 0x0c042a56 */
if(!s->budget--) { s->failed_pc=0x0c042a56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a60; }
goto P_0c042a58;
P_0c042a58: /* original d20c, guest PC 0x0c042a58 */
if(!s->budget--) { s->failed_pc=0x0c042a58u; return 0; }
r[2]=read(ram,0x0c042a8cu,4);
goto P_0c042a5a;
P_0c042a5a: /* original e540, guest PC 0x0c042a5a */
if(!s->budget--) { s->failed_pc=0x0c042a5au; return 0; }
r[5]=0x00000040u;
goto P_0c042a5c;
P_0c042a5c: /* original 420b, guest PC 0x0c042a5c */
if(!s->budget--) { s->failed_pc=0x0c042a5cu; return 0; }
target=r[2];
r[16]=code_base|0x0c042a60u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c042a60u) { target=s->pc; goto dispatch; }
goto P_0c042a60;
P_0c042a5e: /* original 64e3, guest PC 0x0c042a5e */
if(!s->budget--) { s->failed_pc=0x0c042a5eu; return 0; }
r[4]=r[14];
goto P_0c042a60;
P_0c042a60: /* original e301, guest PC 0x0c042a60 */
if(!s->budget--) { s->failed_pc=0x0c042a60u; return 0; }
r[3]=0x00000001u;
goto P_0c042a62;
P_0c042a62: /* original 2c38, guest PC 0x0c042a62 */
if(!s->budget--) { s->failed_pc=0x0c042a62u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[3])==0)!=0);
goto P_0c042a64;
P_0c042a64: /* original 8905, guest PC 0x0c042a64 */
if(!s->budget--) { s->failed_pc=0x0c042a64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a72; }
goto P_0c042a66;
P_0c042a66: /* original 950e, guest PC 0x0c042a66 */
if(!s->budget--) { s->failed_pc=0x0c042a66u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042a86u,2);
goto P_0c042a68;
P_0c042a68: /* original 64d2, guest PC 0x0c042a68 */
if(!s->budget--) { s->failed_pc=0x0c042a68u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c042a6a;
P_0c042a6a: /* original d108, guest PC 0x0c042a6a */
if(!s->budget--) { s->failed_pc=0x0c042a6au; return 0; }
r[1]=read(ram,0x0c042a8cu,4);
goto P_0c042a6c;
P_0c042a6c: /* original 6253, guest PC 0x0c042a6c */
if(!s->budget--) { s->failed_pc=0x0c042a6cu; return 0; }
r[2]=r[5];
goto P_0c042a6e;
P_0c042a6e: /* original 410b, guest PC 0x0c042a6e */
if(!s->budget--) { s->failed_pc=0x0c042a6eu; return 0; }
target=r[1];
r[16]=code_base|0x0c042a72u;
r[4]+=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c042a72u) { target=s->pc; goto dispatch; }
goto P_0c042a72;
P_0c042a70: /* original 342c, guest PC 0x0c042a70 */
if(!s->budget--) { s->failed_pc=0x0c042a70u; return 0; }
r[4]+=r[2];
goto P_0c042a72;
P_0c042a72: /* original de07, guest PC 0x0c042a72 */
if(!s->budget--) { s->failed_pc=0x0c042a72u; return 0; }
r[14]=read(ram,0x0c042a90u,4);
goto P_0c042a74;
P_0c042a74: /* original 60e0, guest PC 0x0c042a74 */
if(!s->budget--) { s->failed_pc=0x0c042a74u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[0]=tmp;
goto P_0c042a76;
P_0c042a76: /* original 8802, guest PC 0x0c042a76 */
if(!s->budget--) { s->failed_pc=0x0c042a76u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c042a78;
P_0c042a78: /* original 8f12, guest PC 0x0c042a78 */
if(!s->budget--) { s->failed_pc=0x0c042a78u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c042aa0; }
goto P_0c042a7c;
P_0c042a7a: /* original 6403, guest PC 0x0c042a7a */
if(!s->budget--) { s->failed_pc=0x0c042a7au; return 0; }
r[4]=r[0];
goto P_0c042a7c;
P_0c042a7c: /* original a012, guest PC 0x0c042a7c */
if(!s->budget--) { s->failed_pc=0x0c042a7cu; return 0; }
r[3]=0x00000000u;
goto P_0c042aa4;
P_0c042a7e: /* original e300, guest PC 0x0c042a7e */
if(!s->budget--) { s->failed_pc=0x0c042a7eu; return 0; }
r[3]=0x00000000u;
if(!vf3_matrix_family(0x0c042a80u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042a80u; return 0; } return 1;
P_0c042aa0: /* original 6343, guest PC 0x0c042aa0 */
if(!s->budget--) { s->failed_pc=0x0c042aa0u; return 0; }
r[3]=r[4];
goto P_0c042aa2;
P_0c042aa2: /* original 7301, guest PC 0x0c042aa2 */
if(!s->budget--) { s->failed_pc=0x0c042aa2u; return 0; }
r[3]+=0x00000001u;
goto P_0c042aa4;
P_0c042aa4: /* original 2e30, guest PC 0x0c042aa4 */
if(!s->budget--) { s->failed_pc=0x0c042aa4u; return 0; }
write(ram,r[14],r[3],1);
goto P_0c042aa6;
P_0c042aa6: /* original e700, guest PC 0x0c042aa6 */
if(!s->budget--) { s->failed_pc=0x0c042aa6u; return 0; }
r[7]=0x00000000u;
goto P_0c042aa8;
P_0c042aa8: /* original 64e0, guest PC 0x0c042aa8 */
if(!s->budget--) { s->failed_pc=0x0c042aa8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[4]=tmp;
goto P_0c042aaa;
P_0c042aaa: /* original 6673, guest PC 0x0c042aaa */
if(!s->budget--) { s->failed_pc=0x0c042aaau; return 0; }
r[6]=r[7];
goto P_0c042aac;
P_0c042aac: /* original d23b, guest PC 0x0c042aac */
if(!s->budget--) { s->failed_pc=0x0c042aacu; return 0; }
r[2]=read(ram,0x0c042b9cu,4);
goto P_0c042aae;
P_0c042aae: /* original 6343, guest PC 0x0c042aae */
if(!s->budget--) { s->failed_pc=0x0c042aaeu; return 0; }
r[3]=r[4];
goto P_0c042ab0;
P_0c042ab0: /* original 4408, guest PC 0x0c042ab0 */
if(!s->budget--) { s->failed_pc=0x0c042ab0u; return 0; }
r[4]<<=2;
goto P_0c042ab2;
P_0c042ab2: /* original 343c, guest PC 0x0c042ab2 */
if(!s->budget--) { s->failed_pc=0x0c042ab2u; return 0; }
r[4]+=r[3];
goto P_0c042ab4;
P_0c042ab4: /* original d33a, guest PC 0x0c042ab4 */
if(!s->budget--) { s->failed_pc=0x0c042ab4u; return 0; }
r[3]=read(ram,0x0c042ba0u,4);
goto P_0c042ab6;
P_0c042ab6: /* original 4408, guest PC 0x0c042ab6 */
if(!s->budget--) { s->failed_pc=0x0c042ab6u; return 0; }
r[4]<<=2;
goto P_0c042ab8;
P_0c042ab8: /* original 65d2, guest PC 0x0c042ab8 */
if(!s->budget--) { s->failed_pc=0x0c042ab8u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c042aba;
P_0c042aba: /* original 4400, guest PC 0x0c042aba */
if(!s->budget--) { s->failed_pc=0x0c042abau; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c042abc;
P_0c042abc: /* original 644e, guest PC 0x0c042abc */
if(!s->budget--) { s->failed_pc=0x0c042abcu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c042abe;
P_0c042abe: /* original 430b, guest PC 0x0c042abe */
if(!s->budget--) { s->failed_pc=0x0c042abeu; return 0; }
target=r[3];
r[16]=code_base|0x0c042ac2u;
r[4]+=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c042ac2u) { target=s->pc; goto dispatch; }
goto P_0c042ac2;
P_0c042ac0: /* original 342c, guest PC 0x0c042ac0 */
if(!s->budget--) { s->failed_pc=0x0c042ac0u; return 0; }
r[4]+=r[2];
goto P_0c042ac2;
P_0c042ac2: /* original a006, guest PC 0x0c042ac2 */
if(!s->budget--) { s->failed_pc=0x0c042ac2u; return 0; }
goto P_0c042ad2;
P_0c042ac4: /* original 0009, guest PC 0x0c042ac4 */
if(!s->budget--) { s->failed_pc=0x0c042ac4u; return 0; }
if(!vf3_matrix_family(0x0c042ac6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042ac6u; return 0; } return 1;
P_0c042ad0: /* original e000, guest PC 0x0c042ad0 */
if(!s->budget--) { s->failed_pc=0x0c042ad0u; return 0; }
r[0]=0x00000000u;
goto P_0c042ad2;
P_0c042ad2: /* original 4f26, guest PC 0x0c042ad2 */
if(!s->budget--) { s->failed_pc=0x0c042ad2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c042ad4;
P_0c042ad4: /* original 6cf6, guest PC 0x0c042ad4 */
if(!s->budget--) { s->failed_pc=0x0c042ad4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c042ad6;
P_0c042ad6: /* original 6df6, guest PC 0x0c042ad6 */
if(!s->budget--) { s->failed_pc=0x0c042ad6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c042ad8;
P_0c042ad8: /* original 000b, guest PC 0x0c042ad8 */
if(!s->budget--) { s->failed_pc=0x0c042ad8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c042ada: /* original 6ef6, guest PC 0x0c042ada */
if(!s->budget--) { s->failed_pc=0x0c042adau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c042adcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042adcu; return 0; } return 1;
P_0c042ae0: /* original e620, guest PC 0x0c042ae0 */
if(!s->budget--) { s->failed_pc=0x0c042ae0u; return 0; }
r[6]=0x00000020u;
goto P_0c042ae2;
P_0c042ae2: /* original 3467, guest PC 0x0c042ae2 */
if(!s->budget--) { s->failed_pc=0x0c042ae2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[6])!=0);
goto P_0c042ae4;
P_0c042ae4: /* original 8b27, guest PC 0x0c042ae4 */
if(!s->budget--) { s->failed_pc=0x0c042ae4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042b36; }
goto P_0c042ae6;
P_0c042ae6: /* original 6043, guest PC 0x0c042ae6 */
if(!s->budget--) { s->failed_pc=0x0c042ae6u; return 0; }
r[0]=r[4];
goto P_0c042ae8;
P_0c042ae8: /* original 0009, guest PC 0x0c042ae8 */
if(!s->budget--) { s->failed_pc=0x0c042ae8u; return 0; }
goto P_0c042aea;
P_0c042aea: /* original 887f, guest PC 0x0c042aea */
if(!s->budget--) { s->failed_pc=0x0c042aeau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000007fu)!=0);
goto P_0c042aec;
P_0c042aec: /* original 8923, guest PC 0x0c042aec */
if(!s->budget--) { s->failed_pc=0x0c042aecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042b36; }
goto P_0c042aee;
P_0c042aee: /* original d52d, guest PC 0x0c042aee */
if(!s->budget--) { s->failed_pc=0x0c042aeeu; return 0; }
r[5]=read(ram,0x0c042ba4u,4);
goto P_0c042af0;
P_0c042af0: /* original e77f, guest PC 0x0c042af0 */
if(!s->budget--) { s->failed_pc=0x0c042af0u; return 0; }
r[7]=0x0000007fu;
goto P_0c042af2;
P_0c042af2: /* original 3473, guest PC 0x0c042af2 */
if(!s->budget--) { s->failed_pc=0x0c042af2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[7])!=0);
goto P_0c042af4;
P_0c042af4: /* original 891c, guest PC 0x0c042af4 */
if(!s->budget--) { s->failed_pc=0x0c042af4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042b30; }
goto P_0c042af6;
P_0c042af6: /* original 6350, guest PC 0x0c042af6 */
if(!s->budget--) { s->failed_pc=0x0c042af6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[3]=tmp;
goto P_0c042af8;
P_0c042af8: /* original 2338, guest PC 0x0c042af8 */
if(!s->budget--) { s->failed_pc=0x0c042af8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c042afa;
P_0c042afa: /* original 890c, guest PC 0x0c042afa */
if(!s->budget--) { s->failed_pc=0x0c042afau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042b16; }
goto P_0c042afc;
P_0c042afc: /* original 6043, guest PC 0x0c042afc */
if(!s->budget--) { s->failed_pc=0x0c042afcu; return 0; }
r[0]=r[4];
goto P_0c042afe;
P_0c042afe: /* original 0009, guest PC 0x0c042afe */
if(!s->budget--) { s->failed_pc=0x0c042afeu; return 0; }
goto P_0c042b00;
P_0c042b00: /* original 885c, guest PC 0x0c042b00 */
if(!s->budget--) { s->failed_pc=0x0c042b00u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000005cu)!=0);
goto P_0c042b02;
P_0c042b02: /* original 8b05, guest PC 0x0c042b02 */
if(!s->budget--) { s->failed_pc=0x0c042b02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042b10; }
goto P_0c042b04;
P_0c042b04: /* original a007, guest PC 0x0c042b04 */
if(!s->budget--) { s->failed_pc=0x0c042b04u; return 0; }
r[4]=r[7];
goto P_0c042b16;
P_0c042b06: /* original 6473, guest PC 0x0c042b06 */
if(!s->budget--) { s->failed_pc=0x0c042b06u; return 0; }
r[4]=r[7];
if(!vf3_matrix_family(0x0c042b08u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042b08u; return 0; } return 1;
P_0c042b10: /* original 887e, guest PC 0x0c042b10 */
if(!s->budget--) { s->failed_pc=0x0c042b10u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000007eu)!=0);
goto P_0c042b12;
P_0c042b12: /* original 8b00, guest PC 0x0c042b12 */
if(!s->budget--) { s->failed_pc=0x0c042b12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042b16; }
goto P_0c042b14;
P_0c042b14: /* original 6463, guest PC 0x0c042b14 */
if(!s->budget--) { s->failed_pc=0x0c042b14u; return 0; }
r[4]=r[6];
goto P_0c042b16;
P_0c042b16: /* original 6043, guest PC 0x0c042b16 */
if(!s->budget--) { s->failed_pc=0x0c042b16u; return 0; }
r[0]=r[4];
goto P_0c042b18;
P_0c042b18: /* original 0009, guest PC 0x0c042b18 */
if(!s->budget--) { s->failed_pc=0x0c042b18u; return 0; }
goto P_0c042b1a;
P_0c042b1a: /* original 70e0, guest PC 0x0c042b1a */
if(!s->budget--) { s->failed_pc=0x0c042b1au; return 0; }
r[0]+=0xffffffe0u;
goto P_0c042b1c;
P_0c042b1c: /* original 6303, guest PC 0x0c042b1c */
if(!s->budget--) { s->failed_pc=0x0c042b1cu; return 0; }
r[3]=r[0];
goto P_0c042b1e;
P_0c042b1e: /* original 4008, guest PC 0x0c042b1e */
if(!s->budget--) { s->failed_pc=0x0c042b1eu; return 0; }
r[0]<<=2;
goto P_0c042b20;
P_0c042b20: /* original 4000, guest PC 0x0c042b20 */
if(!s->budget--) { s->failed_pc=0x0c042b20u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c042b22;
P_0c042b22: /* original 303c, guest PC 0x0c042b22 */
if(!s->budget--) { s->failed_pc=0x0c042b22u; return 0; }
r[0]+=r[3];
goto P_0c042b24;
P_0c042b24: /* original 000b, guest PC 0x0c042b24 */
if(!s->budget--) { s->failed_pc=0x0c042b24u; return 0; }
target=r[16];
r[0]<<=2;
s->pc=target; return ram->oob==0;
P_0c042b26: /* original 4008, guest PC 0x0c042b26 */
if(!s->budget--) { s->failed_pc=0x0c042b26u; return 0; }
r[0]<<=2;
if(!vf3_matrix_family(0x0c042b28u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042b28u; return 0; } return 1;
P_0c042b30: /* original 922d, guest PC 0x0c042b30 */
if(!s->budget--) { s->failed_pc=0x0c042b30u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042b8eu,2);
goto P_0c042b32;
P_0c042b32: /* original 3423, guest PC 0x0c042b32 */
if(!s->budget--) { s->failed_pc=0x0c042b32u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c042b34;
P_0c042b34: /* original 8904, guest PC 0x0c042b34 */
if(!s->budget--) { s->failed_pc=0x0c042b34u; return 0; }
cond=r[17]&1u;
if(cond) { return vf3_matrix_family(0x0c042b40u,s,ram); }
goto P_0c042b36;
P_0c042b36: /* original 902b, guest PC 0x0c042b36 */
if(!s->budget--) { s->failed_pc=0x0c042b36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042b90u,2);
goto P_0c042b38;
P_0c042b38: /* original 000b, guest PC 0x0c042b38 */
if(!s->budget--) { s->failed_pc=0x0c042b38u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c042b3a: /* original 0009, guest PC 0x0c042b3a */
if(!s->budget--) { s->failed_pc=0x0c042b3au; return 0; }
if(!vf3_matrix_family(0x0c042b3cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042b3cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
