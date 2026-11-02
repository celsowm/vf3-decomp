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
int vf3_away_batch168_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07b5b0u: goto P_0c07b5b0;
case 0x0c07b5b2u: goto P_0c07b5b2;
case 0x0c07b5b4u: goto P_0c07b5b4;
case 0x0c07b5b6u: goto P_0c07b5b6;
case 0x0c07b5b8u: goto P_0c07b5b8;
case 0x0c07b5bau: goto P_0c07b5ba;
case 0x0c07b5bcu: goto P_0c07b5bc;
case 0x0c07b5beu: goto P_0c07b5be;
case 0x0c07b5c0u: goto P_0c07b5c0;
case 0x0c07b5c2u: goto P_0c07b5c2;
case 0x0c07b5c4u: goto P_0c07b5c4;
case 0x0c07b5c6u: goto P_0c07b5c6;
case 0x0c07b5c8u: goto P_0c07b5c8;
case 0x0c07b5cau: goto P_0c07b5ca;
case 0x0c07b5ccu: goto P_0c07b5cc;
case 0x0c07b66eu: goto P_0c07b66e;
case 0x0c07b670u: goto P_0c07b670;
case 0x0c07b672u: goto P_0c07b672;
case 0x0c07b674u: goto P_0c07b674;
case 0x0c07b676u: goto P_0c07b676;
case 0x0c07b678u: goto P_0c07b678;
case 0x0c07b67au: goto P_0c07b67a;
case 0x0c07b67cu: goto P_0c07b67c;
case 0x0c07b67eu: goto P_0c07b67e;
case 0x0c07b680u: goto P_0c07b680;
case 0x0c07b682u: goto P_0c07b682;
case 0x0c07b684u: goto P_0c07b684;
case 0x0c07b686u: goto P_0c07b686;
case 0x0c07b688u: goto P_0c07b688;
case 0x0c07b68au: goto P_0c07b68a;
case 0x0c07b68cu: goto P_0c07b68c;
case 0x0c07b68eu: goto P_0c07b68e;
case 0x0c07b690u: goto P_0c07b690;
case 0x0c07b692u: goto P_0c07b692;
case 0x0c07b694u: goto P_0c07b694;
case 0x0c07b696u: goto P_0c07b696;
case 0x0c07b698u: goto P_0c07b698;
case 0x0c07b69au: goto P_0c07b69a;
case 0x0c07b6c4u: goto P_0c07b6c4;
case 0x0c07b6c6u: goto P_0c07b6c6;
case 0x0c07b6c8u: goto P_0c07b6c8;
case 0x0c07b6cau: goto P_0c07b6ca;
case 0x0c07b6ccu: goto P_0c07b6cc;
case 0x0c07b6ceu: goto P_0c07b6ce;
case 0x0c07b6d0u: goto P_0c07b6d0;
case 0x0c07b6d2u: goto P_0c07b6d2;
case 0x0c07b6d4u: goto P_0c07b6d4;
case 0x0c07b6d6u: goto P_0c07b6d6;
case 0x0c07b6d8u: goto P_0c07b6d8;
case 0x0c07b6dau: goto P_0c07b6da;
case 0x0c07b6dcu: goto P_0c07b6dc;
case 0x0c07b6deu: goto P_0c07b6de;
case 0x0c07b6e0u: goto P_0c07b6e0;
case 0x0c07b6e2u: goto P_0c07b6e2;
case 0x0c07b6e4u: goto P_0c07b6e4;
case 0x0c07b6e6u: goto P_0c07b6e6;
case 0x0c07b6e8u: goto P_0c07b6e8;
case 0x0c07b6eau: goto P_0c07b6ea;
case 0x0c07b6ecu: goto P_0c07b6ec;
case 0x0c07b6eeu: goto P_0c07b6ee;
case 0x0c07b6f0u: goto P_0c07b6f0;
case 0x0c07b6f2u: goto P_0c07b6f2;
case 0x0c09abc4u: goto P_0c09abc4;
case 0x0c09abc6u: goto P_0c09abc6;
case 0x0c09abc8u: goto P_0c09abc8;
case 0x0c09abcau: goto P_0c09abca;
case 0x0c09abccu: goto P_0c09abcc;
case 0x0c09abceu: goto P_0c09abce;
case 0x0c09abd0u: goto P_0c09abd0;
case 0x0c09abd2u: goto P_0c09abd2;
case 0x0c09abd4u: goto P_0c09abd4;
case 0x0c09abd6u: goto P_0c09abd6;
case 0x0c09abd8u: goto P_0c09abd8;
case 0x0c09abdau: goto P_0c09abda;
case 0x0c09abdcu: goto P_0c09abdc;
case 0x0c09abdeu: goto P_0c09abde;
case 0x0c09abe0u: goto P_0c09abe0;
case 0x0c09abe2u: goto P_0c09abe2;
case 0x0c09abe4u: goto P_0c09abe4;
case 0x0c09abe6u: goto P_0c09abe6;
case 0x0c09abe8u: goto P_0c09abe8;
case 0x0c09abeau: goto P_0c09abea;
case 0x0c09abecu: goto P_0c09abec;
case 0x0c09abeeu: goto P_0c09abee;
case 0x0c09abf0u: goto P_0c09abf0;
case 0x0c09abf2u: goto P_0c09abf2;
case 0x0c09abf4u: goto P_0c09abf4;
case 0x0c09abf6u: goto P_0c09abf6;
case 0x0c09abf8u: goto P_0c09abf8;
case 0x0c09abfau: goto P_0c09abfa;
case 0x0c09abfcu: goto P_0c09abfc;
case 0x0c09abfeu: goto P_0c09abfe;
case 0x0c09ac00u: goto P_0c09ac00;
case 0x0c09ac02u: goto P_0c09ac02;
case 0x0c09ac04u: goto P_0c09ac04;
case 0x0c0a7f14u: goto P_0c0a7f14;
case 0x0c0a7f16u: goto P_0c0a7f16;
case 0x0c0a7f18u: goto P_0c0a7f18;
case 0x0c0a7f1au: goto P_0c0a7f1a;
case 0x0c0a7f1cu: goto P_0c0a7f1c;
case 0x0c0a7f1eu: goto P_0c0a7f1e;
case 0x0c0a7f20u: goto P_0c0a7f20;
case 0x0c0a7f22u: goto P_0c0a7f22;
case 0x0c0a7f24u: goto P_0c0a7f24;
case 0x0c0a7f26u: goto P_0c0a7f26;
case 0x0c0a7f28u: goto P_0c0a7f28;
case 0x0c0a7f2au: goto P_0c0a7f2a;
case 0x0c0a7f2cu: goto P_0c0a7f2c;
case 0x0c0a7f2eu: goto P_0c0a7f2e;
case 0x0c0a7f30u: goto P_0c0a7f30;
case 0x0c0a7f32u: goto P_0c0a7f32;
case 0x0c0a7f34u: goto P_0c0a7f34;
case 0x0c0a7f36u: goto P_0c0a7f36;
case 0x0c0a7f38u: goto P_0c0a7f38;
case 0x0c0a7f3au: goto P_0c0a7f3a;
case 0x0c0a7f3cu: goto P_0c0a7f3c;
case 0x0c0a7f3eu: goto P_0c0a7f3e;
case 0x0c0a7f40u: goto P_0c0a7f40;
case 0x0c0a7f42u: goto P_0c0a7f42;
case 0x0c0a7f44u: goto P_0c0a7f44;
case 0x0c0a7f46u: goto P_0c0a7f46;
case 0x0c0a7f48u: goto P_0c0a7f48;
case 0x0c0a7f4au: goto P_0c0a7f4a;
case 0x0c0a7f4cu: goto P_0c0a7f4c;
case 0x0c0a7f4eu: goto P_0c0a7f4e;
case 0x0c0a7f50u: goto P_0c0a7f50;
case 0x0c0a7f52u: goto P_0c0a7f52;
case 0x0c0a7f54u: goto P_0c0a7f54;
case 0x0c0a81eeu: goto P_0c0a81ee;
case 0x0c0a81f0u: goto P_0c0a81f0;
case 0x0c0a81f2u: goto P_0c0a81f2;
case 0x0c0a81f4u: goto P_0c0a81f4;
case 0x0c0a81f6u: goto P_0c0a81f6;
case 0x0c0a81f8u: goto P_0c0a81f8;
case 0x0c0a81fau: goto P_0c0a81fa;
case 0x0c0a81fcu: goto P_0c0a81fc;
case 0x0c0a81feu: goto P_0c0a81fe;
case 0x0c0a8200u: goto P_0c0a8200;
case 0x0c0a8202u: goto P_0c0a8202;
case 0x0c0a8204u: goto P_0c0a8204;
case 0x0c0a8206u: goto P_0c0a8206;
case 0x0c0a8208u: goto P_0c0a8208;
case 0x0c0a820au: goto P_0c0a820a;
case 0x0c0a820cu: goto P_0c0a820c;
case 0x0c0a820eu: goto P_0c0a820e;
case 0x0c0a8210u: goto P_0c0a8210;
case 0x0c0a8212u: goto P_0c0a8212;
case 0x0c0a8214u: goto P_0c0a8214;
case 0x0c0a8216u: goto P_0c0a8216;
case 0x0c0a8218u: goto P_0c0a8218;
case 0x0c0a821au: goto P_0c0a821a;
case 0x0c0a821cu: goto P_0c0a821c;
case 0x0c0a821eu: goto P_0c0a821e;
case 0x0c0a8220u: goto P_0c0a8220;
case 0x0c0a8222u: goto P_0c0a8222;
case 0x0c0a8224u: goto P_0c0a8224;
case 0x0c0a8226u: goto P_0c0a8226;
case 0x0c0a8228u: goto P_0c0a8228;
case 0x0c0a822au: goto P_0c0a822a;
case 0x0c0a822cu: goto P_0c0a822c;
case 0x0c0a822eu: goto P_0c0a822e;
case 0x0c0a8230u: goto P_0c0a8230;
case 0x0c0a8232u: goto P_0c0a8232;
case 0x0c0a8234u: goto P_0c0a8234;
case 0x0c0a8236u: goto P_0c0a8236;
case 0x0c0a8238u: goto P_0c0a8238;
case 0x0c0a823au: goto P_0c0a823a;
case 0x0c0a823cu: goto P_0c0a823c;
case 0x0c0a823eu: goto P_0c0a823e;
case 0x0c0a8240u: goto P_0c0a8240;
case 0x0c0a8242u: goto P_0c0a8242;
case 0x0c0a8244u: goto P_0c0a8244;
case 0x0c0a8246u: goto P_0c0a8246;
case 0x0c0a8248u: goto P_0c0a8248;
case 0x0c0a824au: goto P_0c0a824a;
case 0x0c0a824cu: goto P_0c0a824c;
case 0x0c0a824eu: goto P_0c0a824e;
case 0x0c0a8250u: goto P_0c0a8250;
case 0x0c0a8252u: goto P_0c0a8252;
case 0x0c0a8254u: goto P_0c0a8254;
case 0x0c0a8256u: goto P_0c0a8256;
case 0x0c0a8258u: goto P_0c0a8258;
case 0x0c0a825au: goto P_0c0a825a;
case 0x0c0a825cu: goto P_0c0a825c;
case 0x0c0a825eu: goto P_0c0a825e;
case 0x0c0a8260u: goto P_0c0a8260;
case 0x0c0a8262u: goto P_0c0a8262;
case 0x0c0a8264u: goto P_0c0a8264;
case 0x0c0a8266u: goto P_0c0a8266;
case 0x0c0a8268u: goto P_0c0a8268;
case 0x0c0a826au: goto P_0c0a826a;
case 0x0c0a826cu: goto P_0c0a826c;
case 0x0c0a826eu: goto P_0c0a826e;
case 0x0c0a8270u: goto P_0c0a8270;
case 0x0c0a8272u: goto P_0c0a8272;
case 0x0c0a8274u: goto P_0c0a8274;
case 0x0c0a8276u: goto P_0c0a8276;
case 0x0c0a8278u: goto P_0c0a8278;
case 0x0c0a827au: goto P_0c0a827a;
case 0x0c0a827cu: goto P_0c0a827c;
case 0x0c0a827eu: goto P_0c0a827e;
case 0x0c0a8280u: goto P_0c0a8280;
case 0x0c0a8282u: goto P_0c0a8282;
case 0x0c0a8284u: goto P_0c0a8284;
case 0x0c0a8286u: goto P_0c0a8286;
case 0x0c0a8288u: goto P_0c0a8288;
case 0x0c0a828au: goto P_0c0a828a;
case 0x0c0a828cu: goto P_0c0a828c;
case 0x0c0a828eu: goto P_0c0a828e;
case 0x0c0a8290u: goto P_0c0a8290;
case 0x0c0a8292u: goto P_0c0a8292;
case 0x0c0a8294u: goto P_0c0a8294;
case 0x0c0a8296u: goto P_0c0a8296;
case 0x0c0a8298u: goto P_0c0a8298;
case 0x0c0a829au: goto P_0c0a829a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07b5b0: /* original 920d, guest PC 0x0c07b5b0 */
if(!s->budget--) { s->failed_pc=0x0c07b5b0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5ceu,2);
goto P_0c07b5b2;
P_0c07b5b2: /* original 634d, guest PC 0x0c07b5b2 */
if(!s->budget--) { s->failed_pc=0x0c07b5b2u; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b5b4;
P_0c07b5b4: /* original 2328, guest PC 0x0c07b5b4 */
if(!s->budget--) { s->failed_pc=0x0c07b5b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[2])==0)!=0);
goto P_0c07b5b6;
P_0c07b5b6: /* original 8908, guest PC 0x0c07b5b6 */
if(!s->budget--) { s->failed_pc=0x0c07b5b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b5ca; }
goto P_0c07b5b8;
P_0c07b5b8: /* original 900a, guest PC 0x0c07b5b8 */
if(!s->budget--) { s->failed_pc=0x0c07b5b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5d0u,2);
goto P_0c07b5ba;
P_0c07b5ba: /* original 2409, guest PC 0x0c07b5ba */
if(!s->budget--) { s->failed_pc=0x0c07b5bau; return 0; }
r[4]&=r[0];
goto P_0c07b5bc;
P_0c07b5bc: /* original d005, guest PC 0x0c07b5bc */
if(!s->budget--) { s->failed_pc=0x0c07b5bcu; return 0; }
r[0]=read(ram,0x0c07b5d4u,4);
goto P_0c07b5be;
P_0c07b5be: /* original 634d, guest PC 0x0c07b5be */
if(!s->budget--) { s->failed_pc=0x0c07b5beu; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b5c0;
P_0c07b5c0: /* original 6133, guest PC 0x0c07b5c0 */
if(!s->budget--) { s->failed_pc=0x0c07b5c0u; return 0; }
r[1]=r[3];
goto P_0c07b5c2;
P_0c07b5c2: /* original 4108, guest PC 0x0c07b5c2 */
if(!s->budget--) { s->failed_pc=0x0c07b5c2u; return 0; }
r[1]<<=2;
goto P_0c07b5c4;
P_0c07b5c4: /* original 4300, guest PC 0x0c07b5c4 */
if(!s->budget--) { s->failed_pc=0x0c07b5c4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07b5c6;
P_0c07b5c6: /* original 331c, guest PC 0x0c07b5c6 */
if(!s->budget--) { s->failed_pc=0x0c07b5c6u; return 0; }
r[3]+=r[1];
goto P_0c07b5c8;
P_0c07b5c8: /* original 043d, guest PC 0x0c07b5c8 */
if(!s->budget--) { s->failed_pc=0x0c07b5c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07b5ca;
P_0c07b5ca: /* original 000b, guest PC 0x0c07b5ca */
if(!s->budget--) { s->failed_pc=0x0c07b5cau; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c07b5cc: /* original 6043, guest PC 0x0c07b5cc */
if(!s->budget--) { s->failed_pc=0x0c07b5ccu; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c07b5ceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b5ceu; return 0; } return 1;
P_0c07b66e: /* original 4f22, guest PC 0x0c07b66e */
if(!s->budget--) { s->failed_pc=0x0c07b66eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b670;
P_0c07b670: /* original bf9e, guest PC 0x0c07b670 */
if(!s->budget--) { s->failed_pc=0x0c07b670u; return 0; }
target=code_base|0x0c07b5b0u; r[16]=code_base|0x0c07b674u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b674u) { target=s->pc; goto dispatch; }
goto P_0c07b674;
P_0c07b672: /* original 0009, guest PC 0x0c07b672 */
if(!s->budget--) { s->failed_pc=0x0c07b672u; return 0; }
goto P_0c07b674;
P_0c07b674: /* original 6403, guest PC 0x0c07b674 */
if(!s->budget--) { s->failed_pc=0x0c07b674u; return 0; }
r[4]=r[0];
goto P_0c07b676;
P_0c07b676: /* original d30f, guest PC 0x0c07b676 */
if(!s->budget--) { s->failed_pc=0x0c07b676u; return 0; }
r[3]=read(ram,0x0c07b6b4u,4);
goto P_0c07b678;
P_0c07b678: /* original 654d, guest PC 0x0c07b678 */
if(!s->budget--) { s->failed_pc=0x0c07b678u; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b67a;
P_0c07b67a: /* original 4500, guest PC 0x0c07b67a */
if(!s->budget--) { s->failed_pc=0x0c07b67au; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07b67c;
P_0c07b67c: /* original 353c, guest PC 0x0c07b67c */
if(!s->budget--) { s->failed_pc=0x0c07b67cu; return 0; }
r[5]+=r[3];
goto P_0c07b67e;
P_0c07b67e: /* original 6251, guest PC 0x0c07b67e */
if(!s->budget--) { s->failed_pc=0x0c07b67eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c07b680;
P_0c07b680: /* original 2228, guest PC 0x0c07b680 */
if(!s->budget--) { s->failed_pc=0x0c07b680u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07b682;
P_0c07b682: /* original 8904, guest PC 0x0c07b682 */
if(!s->budget--) { s->failed_pc=0x0c07b682u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b68e; }
goto P_0c07b684;
P_0c07b684: /* original 6351, guest PC 0x0c07b684 */
if(!s->budget--) { s->failed_pc=0x0c07b684u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[3]=tmp;
goto P_0c07b686;
P_0c07b686: /* original d20c, guest PC 0x0c07b686 */
if(!s->budget--) { s->failed_pc=0x0c07b686u; return 0; }
r[2]=read(ram,0x0c07b6b8u,4);
goto P_0c07b688;
P_0c07b688: /* original 633d, guest PC 0x0c07b688 */
if(!s->budget--) { s->failed_pc=0x0c07b688u; return 0; }
r[3]=r[3]&65535u;
goto P_0c07b68a;
P_0c07b68a: /* original 3320, guest PC 0x0c07b68a */
if(!s->budget--) { s->failed_pc=0x0c07b68au; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c07b68c;
P_0c07b68c: /* original 8b02, guest PC 0x0c07b68c */
if(!s->budget--) { s->failed_pc=0x0c07b68cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b694; }
goto P_0c07b68e;
P_0c07b68e: /* original 4f26, guest PC 0x0c07b68e */
if(!s->budget--) { s->failed_pc=0x0c07b68eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b690;
P_0c07b690: /* original 000b, guest PC 0x0c07b690 */
if(!s->budget--) { s->failed_pc=0x0c07b690u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c07b692: /* original e000, guest PC 0x0c07b692 */
if(!s->budget--) { s->failed_pc=0x0c07b692u; return 0; }
r[0]=0x00000000u;
goto P_0c07b694;
P_0c07b694: /* original 6051, guest PC 0x0c07b694 */
if(!s->budget--) { s->failed_pc=0x0c07b694u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[0]=tmp;
goto P_0c07b696;
P_0c07b696: /* original 4f26, guest PC 0x0c07b696 */
if(!s->budget--) { s->failed_pc=0x0c07b696u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b698;
P_0c07b698: /* original 000b, guest PC 0x0c07b698 */
if(!s->budget--) { s->failed_pc=0x0c07b698u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07b69a: /* original 0009, guest PC 0x0c07b69a */
if(!s->budget--) { s->failed_pc=0x0c07b69au; return 0; }
if(!vf3_matrix_family(0x0c07b69cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b69cu; return 0; } return 1;
P_0c07b6c4: /* original 4f22, guest PC 0x0c07b6c4 */
if(!s->budget--) { s->failed_pc=0x0c07b6c4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b6c6;
P_0c07b6c6: /* original 7ffc, guest PC 0x0c07b6c6 */
if(!s->budget--) { s->failed_pc=0x0c07b6c6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07b6c8;
P_0c07b6c8: /* original 2f72, guest PC 0x0c07b6c8 */
if(!s->budget--) { s->failed_pc=0x0c07b6c8u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c07b6ca;
P_0c07b6ca: /* original 53f2, guest PC 0x0c07b6ca */
if(!s->budget--) { s->failed_pc=0x0c07b6cau; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07b6cc;
P_0c07b6cc: /* original 2f36, guest PC 0x0c07b6cc */
if(!s->budget--) { s->failed_pc=0x0c07b6ccu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b6ce;
P_0c07b6ce: /* original 52f1, guest PC 0x0c07b6ce */
if(!s->budget--) { s->failed_pc=0x0c07b6ceu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07b6d0;
P_0c07b6d0: /* original 2f26, guest PC 0x0c07b6d0 */
if(!s->budget--) { s->failed_pc=0x0c07b6d0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b6d2;
P_0c07b6d2: /* original b004, guest PC 0x0c07b6d2 */
if(!s->budget--) { s->failed_pc=0x0c07b6d2u; return 0; }
target=code_base|0x0c07b6deu; r[16]=code_base|0x0c07b6d6u;
r[7]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b6d6u) { target=s->pc; goto dispatch; }
goto P_0c07b6d6;
P_0c07b6d4: /* original e700, guest PC 0x0c07b6d4 */
if(!s->budget--) { s->failed_pc=0x0c07b6d4u; return 0; }
r[7]=0x00000000u;
goto P_0c07b6d6;
P_0c07b6d6: /* original 7f0c, guest PC 0x0c07b6d6 */
if(!s->budget--) { s->failed_pc=0x0c07b6d6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07b6d8;
P_0c07b6d8: /* original 4f26, guest PC 0x0c07b6d8 */
if(!s->budget--) { s->failed_pc=0x0c07b6d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b6da;
P_0c07b6da: /* original 000b, guest PC 0x0c07b6da */
if(!s->budget--) { s->failed_pc=0x0c07b6dau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07b6dc: /* original 0009, guest PC 0x0c07b6dc */
if(!s->budget--) { s->failed_pc=0x0c07b6dcu; return 0; }
goto P_0c07b6de;
P_0c07b6de: /* original 4f22, guest PC 0x0c07b6de */
if(!s->budget--) { s->failed_pc=0x0c07b6deu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b6e0;
P_0c07b6e0: /* original 53f2, guest PC 0x0c07b6e0 */
if(!s->budget--) { s->failed_pc=0x0c07b6e0u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07b6e2;
P_0c07b6e2: /* original 2f36, guest PC 0x0c07b6e2 */
if(!s->budget--) { s->failed_pc=0x0c07b6e2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b6e4;
P_0c07b6e4: /* original d311, guest PC 0x0c07b6e4 */
if(!s->budget--) { s->failed_pc=0x0c07b6e4u; return 0; }
r[3]=read(ram,0x0c07b72cu,4);
goto P_0c07b6e6;
P_0c07b6e6: /* original 52f2, guest PC 0x0c07b6e6 */
if(!s->budget--) { s->failed_pc=0x0c07b6e6u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c07b6e8;
P_0c07b6e8: /* original 430b, guest PC 0x0c07b6e8 */
if(!s->budget--) { s->failed_pc=0x0c07b6e8u; return 0; }
target=r[3];
r[16]=code_base|0x0c07b6ecu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b6ecu) { target=s->pc; goto dispatch; }
goto P_0c07b6ec;
P_0c07b6ea: /* original 2f26, guest PC 0x0c07b6ea */
if(!s->budget--) { s->failed_pc=0x0c07b6eau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b6ec;
P_0c07b6ec: /* original 7f08, guest PC 0x0c07b6ec */
if(!s->budget--) { s->failed_pc=0x0c07b6ecu; return 0; }
r[15]+=0x00000008u;
goto P_0c07b6ee;
P_0c07b6ee: /* original 4f26, guest PC 0x0c07b6ee */
if(!s->budget--) { s->failed_pc=0x0c07b6eeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b6f0;
P_0c07b6f0: /* original 000b, guest PC 0x0c07b6f0 */
if(!s->budget--) { s->failed_pc=0x0c07b6f0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07b6f2: /* original 0009, guest PC 0x0c07b6f2 */
if(!s->budget--) { s->failed_pc=0x0c07b6f2u; return 0; }
if(!vf3_matrix_family(0x0c07b6f4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b6f4u; return 0; } return 1;
P_0c09abc4: /* original d512, guest PC 0x0c09abc4 */
if(!s->budget--) { s->failed_pc=0x0c09abc4u; return 0; }
r[5]=read(ram,0x0c09ac10u,4);
goto P_0c09abc6;
P_0c09abc6: /* original e620, guest PC 0x0c09abc6 */
if(!s->budget--) { s->failed_pc=0x0c09abc6u; return 0; }
r[6]=0x00000020u;
goto P_0c09abc8;
P_0c09abc8: /* original 845b, guest PC 0x0c09abc8 */
if(!s->budget--) { s->failed_pc=0x0c09abc8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+11,1);
goto P_0c09abca;
P_0c09abca: /* original 640c, guest PC 0x0c09abca */
if(!s->budget--) { s->failed_pc=0x0c09abcau; return 0; }
r[4]=r[0]&255u;
goto P_0c09abcc;
P_0c09abcc: /* original 3463, guest PC 0x0c09abcc */
if(!s->budget--) { s->failed_pc=0x0c09abccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c09abce;
P_0c09abce: /* original 8b18, guest PC 0x0c09abce */
if(!s->budget--) { s->failed_pc=0x0c09abceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ac02; }
goto P_0c09abd0;
P_0c09abd0: /* original 9019, guest PC 0x0c09abd0 */
if(!s->budget--) { s->failed_pc=0x0c09abd0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ac06u,2);
goto P_0c09abd2;
P_0c09abd2: /* original 035e, guest PC 0x0c09abd2 */
if(!s->budget--) { s->failed_pc=0x0c09abd2u; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c09abd4;
P_0c09abd4: /* original 2368, guest PC 0x0c09abd4 */
if(!s->budget--) { s->failed_pc=0x0c09abd4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c09abd6;
P_0c09abd6: /* original 8914, guest PC 0x0c09abd6 */
if(!s->budget--) { s->failed_pc=0x0c09abd6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ac02; }
goto P_0c09abd8;
P_0c09abd8: /* original 9017, guest PC 0x0c09abd8 */
if(!s->budget--) { s->failed_pc=0x0c09abd8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ac0au,2);
goto P_0c09abda;
P_0c09abda: /* original 9315, guest PC 0x0c09abda */
if(!s->budget--) { s->failed_pc=0x0c09abdau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ac08u,2);
goto P_0c09abdc;
P_0c09abdc: /* original 025e, guest PC 0x0c09abdc */
if(!s->budget--) { s->failed_pc=0x0c09abdcu; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c09abde;
P_0c09abde: /* original 2238, guest PC 0x0c09abde */
if(!s->budget--) { s->failed_pc=0x0c09abdeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09abe0;
P_0c09abe0: /* original 8f05, guest PC 0x0c09abe0 */
if(!s->budget--) { s->failed_pc=0x0c09abe0u; return 0; }
cond=r[17]&1u;
r[7]=0x00000032u;
if(!cond) { goto P_0c09abee; }
goto P_0c09abe4;
P_0c09abe2: /* original e732, guest PC 0x0c09abe2 */
if(!s->budget--) { s->failed_pc=0x0c09abe2u; return 0; }
r[7]=0x00000032u;
goto P_0c09abe4;
P_0c09abe4: /* original 7401, guest PC 0x0c09abe4 */
if(!s->budget--) { s->failed_pc=0x0c09abe4u; return 0; }
r[4]+=0x00000001u;
goto P_0c09abe6;
P_0c09abe6: /* original 3477, guest PC 0x0c09abe6 */
if(!s->budget--) { s->failed_pc=0x0c09abe6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[7])!=0);
goto P_0c09abe8;
P_0c09abe8: /* original 8b09, guest PC 0x0c09abe8 */
if(!s->budget--) { s->failed_pc=0x0c09abe8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09abfe; }
goto P_0c09abea;
P_0c09abea: /* original a008, guest PC 0x0c09abea */
if(!s->budget--) { s->failed_pc=0x0c09abeau; return 0; }
r[4]=r[6];
goto P_0c09abfe;
P_0c09abec: /* original 6463, guest PC 0x0c09abec */
if(!s->budget--) { s->failed_pc=0x0c09abecu; return 0; }
r[4]=r[6];
goto P_0c09abee;
P_0c09abee: /* original 025e, guest PC 0x0c09abee */
if(!s->budget--) { s->failed_pc=0x0c09abeeu; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c09abf0;
P_0c09abf0: /* original 930c, guest PC 0x0c09abf0 */
if(!s->budget--) { s->failed_pc=0x0c09abf0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ac0cu,2);
goto P_0c09abf2;
P_0c09abf2: /* original 2238, guest PC 0x0c09abf2 */
if(!s->budget--) { s->failed_pc=0x0c09abf2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09abf4;
P_0c09abf4: /* original 8905, guest PC 0x0c09abf4 */
if(!s->budget--) { s->failed_pc=0x0c09abf4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ac02; }
goto P_0c09abf6;
P_0c09abf6: /* original 74fd, guest PC 0x0c09abf6 */
if(!s->budget--) { s->failed_pc=0x0c09abf6u; return 0; }
r[4]+=0xfffffffdu;
goto P_0c09abf8;
P_0c09abf8: /* original 3463, guest PC 0x0c09abf8 */
if(!s->budget--) { s->failed_pc=0x0c09abf8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c09abfa;
P_0c09abfa: /* original 8900, guest PC 0x0c09abfa */
if(!s->budget--) { s->failed_pc=0x0c09abfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09abfe; }
goto P_0c09abfc;
P_0c09abfc: /* original 6473, guest PC 0x0c09abfc */
if(!s->budget--) { s->failed_pc=0x0c09abfcu; return 0; }
r[4]=r[7];
goto P_0c09abfe;
P_0c09abfe: /* original 6043, guest PC 0x0c09abfe */
if(!s->budget--) { s->failed_pc=0x0c09abfeu; return 0; }
r[0]=r[4];
goto P_0c09ac00;
P_0c09ac00: /* original 805b, guest PC 0x0c09ac00 */
if(!s->budget--) { s->failed_pc=0x0c09ac00u; return 0; }
write(ram,r[5]+11,r[0],1);
goto P_0c09ac02;
P_0c09ac02: /* original 000b, guest PC 0x0c09ac02 */
if(!s->budget--) { s->failed_pc=0x0c09ac02u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09ac04: /* original 0009, guest PC 0x0c09ac04 */
if(!s->budget--) { s->failed_pc=0x0c09ac04u; return 0; }
if(!vf3_matrix_family(0x0c09ac06u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09ac06u; return 0; } return 1;
P_0c0a7f14: /* original 2fe6, guest PC 0x0c0a7f14 */
if(!s->budget--) { s->failed_pc=0x0c0a7f14u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f16;
P_0c0a7f16: /* original d324, guest PC 0x0c0a7f16 */
if(!s->budget--) { s->failed_pc=0x0c0a7f16u; return 0; }
r[3]=read(ram,0x0c0a7fa8u,4);
goto P_0c0a7f18;
P_0c0a7f18: /* original 4f12, guest PC 0x0c0a7f18 */
if(!s->budget--) { s->failed_pc=0x0c0a7f18u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a7f1a;
P_0c0a7f1a: /* original 6632, guest PC 0x0c0a7f1a */
if(!s->budget--) { s->failed_pc=0x0c0a7f1au; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c0a7f1c;
P_0c0a7f1c: /* original 856d, guest PC 0x0c0a7f1c */
if(!s->budget--) { s->failed_pc=0x0c0a7f1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+26,2);
goto P_0c0a7f1e;
P_0c0a7f1e: /* original 670d, guest PC 0x0c0a7f1e */
if(!s->budget--) { s->failed_pc=0x0c0a7f1eu; return 0; }
r[7]=r[0]&65535u;
goto P_0c0a7f20;
P_0c0a7f20: /* original a012, guest PC 0x0c0a7f20 */
if(!s->budget--) { s->failed_pc=0x0c0a7f20u; return 0; }
r[14]=0x0000001fu;
goto P_0c0a7f48;
P_0c0a7f22: /* original ee1f, guest PC 0x0c0a7f22 */
if(!s->budget--) { s->failed_pc=0x0c0a7f22u; return 0; }
r[14]=0x0000001fu;
goto P_0c0a7f24;
P_0c0a7f24: /* original 856b, guest PC 0x0c0a7f24 */
if(!s->budget--) { s->failed_pc=0x0c0a7f24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+22,2);
goto P_0c0a7f26;
P_0c0a7f26: /* original 600d, guest PC 0x0c0a7f26 */
if(!s->budget--) { s->failed_pc=0x0c0a7f26u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a7f28;
P_0c0a7f28: /* original 3500, guest PC 0x0c0a7f28 */
if(!s->budget--) { s->failed_pc=0x0c0a7f28u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[0])!=0);
goto P_0c0a7f2a;
P_0c0a7f2a: /* original 8910, guest PC 0x0c0a7f2a */
if(!s->budget--) { s->failed_pc=0x0c0a7f2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7f4e; }
goto P_0c0a7f2c;
P_0c0a7f2c: /* original e334, guest PC 0x0c0a7f2c */
if(!s->budget--) { s->failed_pc=0x0c0a7f2cu; return 0; }
r[3]=0x00000034u;
goto P_0c0a7f2e;
P_0c0a7f2e: /* original 6263, guest PC 0x0c0a7f2e */
if(!s->budget--) { s->failed_pc=0x0c0a7f2eu; return 0; }
r[2]=r[6];
goto P_0c0a7f30;
P_0c0a7f30: /* original 253f, guest PC 0x0c0a7f30 */
if(!s->budget--) { s->failed_pc=0x0c0a7f30u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[5]*(int32_t)(int16_t)r[3]);
goto P_0c0a7f32;
P_0c0a7f32: /* original 721c, guest PC 0x0c0a7f32 */
if(!s->budget--) { s->failed_pc=0x0c0a7f32u; return 0; }
r[2]+=0x0000001cu;
goto P_0c0a7f34;
P_0c0a7f34: /* original e030, guest PC 0x0c0a7f34 */
if(!s->budget--) { s->failed_pc=0x0c0a7f34u; return 0; }
r[0]=0x00000030u;
goto P_0c0a7f36;
P_0c0a7f36: /* original 051a, guest PC 0x0c0a7f36 */
if(!s->budget--) { s->failed_pc=0x0c0a7f36u; return 0; }
r[5]=r[19];
goto P_0c0a7f38;
P_0c0a7f38: /* original 655f, guest PC 0x0c0a7f38 */
if(!s->budget--) { s->failed_pc=0x0c0a7f38u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c0a7f3a;
P_0c0a7f3a: /* original 352c, guest PC 0x0c0a7f3a */
if(!s->budget--) { s->failed_pc=0x0c0a7f3au; return 0; }
r[5]+=r[2];
goto P_0c0a7f3c;
P_0c0a7f3c: /* original 015d, guest PC 0x0c0a7f3c */
if(!s->budget--) { s->failed_pc=0x0c0a7f3cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0a7f3e;
P_0c0a7f3e: /* original 3140, guest PC 0x0c0a7f3e */
if(!s->budget--) { s->failed_pc=0x0c0a7f3eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[4])!=0);
goto P_0c0a7f40;
P_0c0a7f40: /* original 8b01, guest PC 0x0c0a7f40 */
if(!s->budget--) { s->failed_pc=0x0c0a7f40u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7f46; }
goto P_0c0a7f42;
P_0c0a7f42: /* original a005, guest PC 0x0c0a7f42 */
if(!s->budget--) { s->failed_pc=0x0c0a7f42u; return 0; }
r[0]=0x00000001u;
goto P_0c0a7f50;
P_0c0a7f44: /* original e001, guest PC 0x0c0a7f44 */
if(!s->budget--) { s->failed_pc=0x0c0a7f44u; return 0; }
r[0]=0x00000001u;
goto P_0c0a7f46;
P_0c0a7f46: /* original 77ff, guest PC 0x0c0a7f46 */
if(!s->budget--) { s->failed_pc=0x0c0a7f46u; return 0; }
r[7]+=0xffffffffu;
goto P_0c0a7f48;
P_0c0a7f48: /* original 6573, guest PC 0x0c0a7f48 */
if(!s->budget--) { s->failed_pc=0x0c0a7f48u; return 0; }
r[5]=r[7];
goto P_0c0a7f4a;
P_0c0a7f4a: /* original afeb, guest PC 0x0c0a7f4a */
if(!s->budget--) { s->failed_pc=0x0c0a7f4au; return 0; }
r[5]&=r[14];
goto P_0c0a7f24;
P_0c0a7f4c: /* original 25e9, guest PC 0x0c0a7f4c */
if(!s->budget--) { s->failed_pc=0x0c0a7f4cu; return 0; }
r[5]&=r[14];
goto P_0c0a7f4e;
P_0c0a7f4e: /* original e000, guest PC 0x0c0a7f4e */
if(!s->budget--) { s->failed_pc=0x0c0a7f4eu; return 0; }
r[0]=0x00000000u;
goto P_0c0a7f50;
P_0c0a7f50: /* original 4f16, guest PC 0x0c0a7f50 */
if(!s->budget--) { s->failed_pc=0x0c0a7f50u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7f52;
P_0c0a7f52: /* original 000b, guest PC 0x0c0a7f52 */
if(!s->budget--) { s->failed_pc=0x0c0a7f52u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a7f54: /* original 6ef6, guest PC 0x0c0a7f54 */
if(!s->budget--) { s->failed_pc=0x0c0a7f54u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a7f56u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7f56u; return 0; } return 1;
P_0c0a81ee: /* original 2fe6, guest PC 0x0c0a81ee */
if(!s->budget--) { s->failed_pc=0x0c0a81eeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f0;
P_0c0a81f0: /* original 2fd6, guest PC 0x0c0a81f0 */
if(!s->budget--) { s->failed_pc=0x0c0a81f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f2;
P_0c0a81f2: /* original 2fc6, guest PC 0x0c0a81f2 */
if(!s->budget--) { s->failed_pc=0x0c0a81f2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f4;
P_0c0a81f4: /* original 2fb6, guest PC 0x0c0a81f4 */
if(!s->budget--) { s->failed_pc=0x0c0a81f4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f6;
P_0c0a81f6: /* original 6b43, guest PC 0x0c0a81f6 */
if(!s->budget--) { s->failed_pc=0x0c0a81f6u; return 0; }
r[11]=r[4];
goto P_0c0a81f8;
P_0c0a81f8: /* original 2fa6, guest PC 0x0c0a81f8 */
if(!s->budget--) { s->failed_pc=0x0c0a81f8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81fa;
P_0c0a81fa: /* original eaff, guest PC 0x0c0a81fa */
if(!s->budget--) { s->failed_pc=0x0c0a81fau; return 0; }
r[10]=0xffffffffu;
goto P_0c0a81fc;
P_0c0a81fc: /* original 4f22, guest PC 0x0c0a81fc */
if(!s->budget--) { s->failed_pc=0x0c0a81fcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a81fe;
P_0c0a81fe: /* original 4f12, guest PC 0x0c0a81fe */
if(!s->budget--) { s->failed_pc=0x0c0a81feu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a8200;
P_0c0a8200: /* original 7ff0, guest PC 0x0c0a8200 */
if(!s->budget--) { s->failed_pc=0x0c0a8200u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0a8202;
P_0c0a8202: /* original 1f51, guest PC 0x0c0a8202 */
if(!s->budget--) { s->failed_pc=0x0c0a8202u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0a8204;
P_0c0a8204: /* original 2f62, guest PC 0x0c0a8204 */
if(!s->budget--) { s->failed_pc=0x0c0a8204u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0a8206;
P_0c0a8206: /* original 1f72, guest PC 0x0c0a8206 */
if(!s->budget--) { s->failed_pc=0x0c0a8206u; return 0; }
write(ram,r[15]+8,r[7],4);
goto P_0c0a8208;
P_0c0a8208: /* original d32a, guest PC 0x0c0a8208 */
if(!s->budget--) { s->failed_pc=0x0c0a8208u; return 0; }
r[3]=read(ram,0x0c0a82b4u,4);
goto P_0c0a820a;
P_0c0a820a: /* original 9249, guest PC 0x0c0a820a */
if(!s->budget--) { s->failed_pc=0x0c0a820au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a82a0u,2);
goto P_0c0a820c;
P_0c0a820c: /* original 6e32, guest PC 0x0c0a820c */
if(!s->budget--) { s->failed_pc=0x0c0a820cu; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c0a820e;
P_0c0a820e: /* original 3b23, guest PC 0x0c0a820e */
if(!s->budget--) { s->failed_pc=0x0c0a820eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[2])!=0);
goto P_0c0a8210;
P_0c0a8210: /* original 8f03, guest PC 0x0c0a8210 */
if(!s->budget--) { s->failed_pc=0x0c0a8210u; return 0; }
cond=r[17]&1u;
r[12]=r[10];
if(!cond) { goto P_0c0a821a; }
goto P_0c0a8214;
P_0c0a8212: /* original 6ca3, guest PC 0x0c0a8212 */
if(!s->budget--) { s->failed_pc=0x0c0a8212u; return 0; }
r[12]=r[10];
goto P_0c0a8214;
P_0c0a8214: /* original dc28, guest PC 0x0c0a8214 */
if(!s->budget--) { s->failed_pc=0x0c0a8214u; return 0; }
r[12]=read(ram,0x0c0a82b8u,4);
goto P_0c0a8216;
P_0c0a8216: /* original a037, guest PC 0x0c0a8216 */
if(!s->budget--) { s->failed_pc=0x0c0a8216u; return 0; }
goto P_0c0a8288;
P_0c0a8218: /* original 0009, guest PC 0x0c0a8218 */
if(!s->budget--) { s->failed_pc=0x0c0a8218u; return 0; }
goto P_0c0a821a;
P_0c0a821a: /* original d028, guest PC 0x0c0a821a */
if(!s->budget--) { s->failed_pc=0x0c0a821au; return 0; }
r[0]=read(ram,0x0c0a82bcu,4);
goto P_0c0a821c;
P_0c0a821c: /* original 63b3, guest PC 0x0c0a821c */
if(!s->budget--) { s->failed_pc=0x0c0a821cu; return 0; }
r[3]=r[11];
goto P_0c0a821e;
P_0c0a821e: /* original 4308, guest PC 0x0c0a821e */
if(!s->budget--) { s->failed_pc=0x0c0a821eu; return 0; }
r[3]<<=2;
goto P_0c0a8220;
P_0c0a8220: /* original 023e, guest PC 0x0c0a8220 */
if(!s->budget--) { s->failed_pc=0x0c0a8220u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0a8222;
P_0c0a8222: /* original 1f23, guest PC 0x0c0a8222 */
if(!s->budget--) { s->failed_pc=0x0c0a8222u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0a8224;
P_0c0a8224: /* original 63f2, guest PC 0x0c0a8224 */
if(!s->budget--) { s->failed_pc=0x0c0a8224u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a8226;
P_0c0a8226: /* original 2338, guest PC 0x0c0a8226 */
if(!s->budget--) { s->failed_pc=0x0c0a8226u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a8228;
P_0c0a8228: /* original 892e, guest PC 0x0c0a8228 */
if(!s->budget--) { s->failed_pc=0x0c0a8228u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8288; }
goto P_0c0a822a;
P_0c0a822a: /* original 50f1, guest PC 0x0c0a822a */
if(!s->budget--) { s->failed_pc=0x0c0a822au; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0a822c;
P_0c0a822c: /* original c803, guest PC 0x0c0a822c */
if(!s->budget--) { s->failed_pc=0x0c0a822cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&3u)==0)!=0);
goto P_0c0a822e;
P_0c0a822e: /* original 8b2b, guest PC 0x0c0a822e */
if(!s->budget--) { s->failed_pc=0x0c0a822eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8288; }
goto P_0c0a8230;
P_0c0a8230: /* original 85ed, guest PC 0x0c0a8230 */
if(!s->budget--) { s->failed_pc=0x0c0a8230u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+26,2);
goto P_0c0a8232;
P_0c0a8232: /* original ed1f, guest PC 0x0c0a8232 */
if(!s->budget--) { s->failed_pc=0x0c0a8232u; return 0; }
r[13]=0x0000001fu;
goto P_0c0a8234;
P_0c0a8234: /* original 600d, guest PC 0x0c0a8234 */
if(!s->budget--) { s->failed_pc=0x0c0a8234u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a8236;
P_0c0a8236: /* original 7001, guest PC 0x0c0a8236 */
if(!s->budget--) { s->failed_pc=0x0c0a8236u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a8238;
P_0c0a8238: /* original 2d09, guest PC 0x0c0a8238 */
if(!s->budget--) { s->failed_pc=0x0c0a8238u; return 0; }
r[13]&=r[0];
goto P_0c0a823a;
P_0c0a823a: /* original 85eb, guest PC 0x0c0a823a */
if(!s->budget--) { s->failed_pc=0x0c0a823au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a823c;
P_0c0a823c: /* original 600d, guest PC 0x0c0a823c */
if(!s->budget--) { s->failed_pc=0x0c0a823cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a823e;
P_0c0a823e: /* original 3d00, guest PC 0x0c0a823e */
if(!s->budget--) { s->failed_pc=0x0c0a823eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[0])!=0);
goto P_0c0a8240;
P_0c0a8240: /* original 8922, guest PC 0x0c0a8240 */
if(!s->budget--) { s->failed_pc=0x0c0a8240u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8288; }
goto P_0c0a8242;
P_0c0a8242: /* original be67, guest PC 0x0c0a8242 */
if(!s->budget--) { s->failed_pc=0x0c0a8242u; return 0; }
target=code_base|0x0c0a7f14u; r[16]=code_base|0x0c0a8246u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8246u) { target=s->pc; goto dispatch; }
goto P_0c0a8246;
P_0c0a8244: /* original 64b3, guest PC 0x0c0a8244 */
if(!s->budget--) { s->failed_pc=0x0c0a8244u; return 0; }
r[4]=r[11];
goto P_0c0a8246;
P_0c0a8246: /* original 2008, guest PC 0x0c0a8246 */
if(!s->budget--) { s->failed_pc=0x0c0a8246u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a8248;
P_0c0a8248: /* original 8b1e, guest PC 0x0c0a8248 */
if(!s->budget--) { s->failed_pc=0x0c0a8248u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8288; }
goto P_0c0a824a;
P_0c0a824a: /* original e434, guest PC 0x0c0a824a */
if(!s->budget--) { s->failed_pc=0x0c0a824au; return 0; }
r[4]=0x00000034u;
goto P_0c0a824c;
P_0c0a824c: /* original 63e3, guest PC 0x0c0a824c */
if(!s->budget--) { s->failed_pc=0x0c0a824cu; return 0; }
r[3]=r[14];
goto P_0c0a824e;
P_0c0a824e: /* original 2d4f, guest PC 0x0c0a824e */
if(!s->budget--) { s->failed_pc=0x0c0a824eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[4]);
goto P_0c0a8250;
P_0c0a8250: /* original 731c, guest PC 0x0c0a8250 */
if(!s->budget--) { s->failed_pc=0x0c0a8250u; return 0; }
r[3]+=0x0000001cu;
goto P_0c0a8252;
P_0c0a8252: /* original 60d3, guest PC 0x0c0a8252 */
if(!s->budget--) { s->failed_pc=0x0c0a8252u; return 0; }
r[0]=r[13];
goto P_0c0a8254;
P_0c0a8254: /* original 81ed, guest PC 0x0c0a8254 */
if(!s->budget--) { s->failed_pc=0x0c0a8254u; return 0; }
write(ram,r[14]+26,r[0],2);
goto P_0c0a8256;
P_0c0a8256: /* original e030, guest PC 0x0c0a8256 */
if(!s->budget--) { s->failed_pc=0x0c0a8256u; return 0; }
r[0]=0x00000030u;
goto P_0c0a8258;
P_0c0a8258: /* original 62f2, guest PC 0x0c0a8258 */
if(!s->budget--) { s->failed_pc=0x0c0a8258u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a825a;
P_0c0a825a: /* original 6cd3, guest PC 0x0c0a825a */
if(!s->budget--) { s->failed_pc=0x0c0a825au; return 0; }
r[12]=r[13];
goto P_0c0a825c;
P_0c0a825c: /* original 041a, guest PC 0x0c0a825c */
if(!s->budget--) { s->failed_pc=0x0c0a825cu; return 0; }
r[4]=r[19];
goto P_0c0a825e;
P_0c0a825e: /* original 644f, guest PC 0x0c0a825e */
if(!s->budget--) { s->failed_pc=0x0c0a825eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0a8260;
P_0c0a8260: /* original 343c, guest PC 0x0c0a8260 */
if(!s->budget--) { s->failed_pc=0x0c0a8260u; return 0; }
r[4]+=r[3];
goto P_0c0a8262;
P_0c0a8262: /* original 6323, guest PC 0x0c0a8262 */
if(!s->budget--) { s->failed_pc=0x0c0a8262u; return 0; }
r[3]=r[2];
goto P_0c0a8264;
P_0c0a8264: /* original 2422, guest PC 0x0c0a8264 */
if(!s->budget--) { s->failed_pc=0x0c0a8264u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c0a8266;
P_0c0a8266: /* original e200, guest PC 0x0c0a8266 */
if(!s->budget--) { s->failed_pc=0x0c0a8266u; return 0; }
r[2]=0x00000000u;
goto P_0c0a8268;
P_0c0a8268: /* original 2322, guest PC 0x0c0a8268 */
if(!s->budget--) { s->failed_pc=0x0c0a8268u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0a826a;
P_0c0a826a: /* original 53f1, guest PC 0x0c0a826a */
if(!s->budget--) { s->failed_pc=0x0c0a826au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a826c;
P_0c0a826c: /* original 1431, guest PC 0x0c0a826c */
if(!s->budget--) { s->failed_pc=0x0c0a826cu; return 0; }
write(ram,r[4]+4,r[3],4);
goto P_0c0a826e;
P_0c0a826e: /* original 14a7, guest PC 0x0c0a826e */
if(!s->budget--) { s->failed_pc=0x0c0a826eu; return 0; }
write(ram,r[4]+28,r[10],4);
goto P_0c0a8270;
P_0c0a8270: /* original 14a2, guest PC 0x0c0a8270 */
if(!s->budget--) { s->failed_pc=0x0c0a8270u; return 0; }
write(ram,r[4]+8,r[10],4);
goto P_0c0a8272;
P_0c0a8272: /* original 53f3, guest PC 0x0c0a8272 */
if(!s->budget--) { s->failed_pc=0x0c0a8272u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0a8274;
P_0c0a8274: /* original 1434, guest PC 0x0c0a8274 */
if(!s->budget--) { s->failed_pc=0x0c0a8274u; return 0; }
write(ram,r[4]+16,r[3],4);
goto P_0c0a8276;
P_0c0a8276: /* original 52f2, guest PC 0x0c0a8276 */
if(!s->budget--) { s->failed_pc=0x0c0a8276u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0a8278;
P_0c0a8278: /* original 1425, guest PC 0x0c0a8278 */
if(!s->budget--) { s->failed_pc=0x0c0a8278u; return 0; }
write(ram,r[4]+20,r[2],4);
goto P_0c0a827a;
P_0c0a827a: /* original 53fb, guest PC 0x0c0a827a */
if(!s->budget--) { s->failed_pc=0x0c0a827au; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c0a827c;
P_0c0a827c: /* original 1436, guest PC 0x0c0a827c */
if(!s->budget--) { s->failed_pc=0x0c0a827cu; return 0; }
write(ram,r[4]+24,r[3],4);
goto P_0c0a827e;
P_0c0a827e: /* original 52fc, guest PC 0x0c0a827e */
if(!s->budget--) { s->failed_pc=0x0c0a827eu; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c0a8280;
P_0c0a8280: /* original 142a, guest PC 0x0c0a8280 */
if(!s->budget--) { s->failed_pc=0x0c0a8280u; return 0; }
write(ram,r[4]+40,r[2],4);
goto P_0c0a8282;
P_0c0a8282: /* original 53fd, guest PC 0x0c0a8282 */
if(!s->budget--) { s->failed_pc=0x0c0a8282u; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c0a8284;
P_0c0a8284: /* original 143b, guest PC 0x0c0a8284 */
if(!s->budget--) { s->failed_pc=0x0c0a8284u; return 0; }
write(ram,r[4]+44,r[3],4);
goto P_0c0a8286;
P_0c0a8286: /* original 04b5, guest PC 0x0c0a8286 */
if(!s->budget--) { s->failed_pc=0x0c0a8286u; return 0; }
write(ram,r[4]+r[0],r[11],2);
goto P_0c0a8288;
P_0c0a8288: /* original 7f10, guest PC 0x0c0a8288 */
if(!s->budget--) { s->failed_pc=0x0c0a8288u; return 0; }
r[15]+=0x00000010u;
goto P_0c0a828a;
P_0c0a828a: /* original 60c3, guest PC 0x0c0a828a */
if(!s->budget--) { s->failed_pc=0x0c0a828au; return 0; }
r[0]=r[12];
goto P_0c0a828c;
P_0c0a828c: /* original 4f16, guest PC 0x0c0a828c */
if(!s->budget--) { s->failed_pc=0x0c0a828cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a828e;
P_0c0a828e: /* original 4f26, guest PC 0x0c0a828e */
if(!s->budget--) { s->failed_pc=0x0c0a828eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8290;
P_0c0a8290: /* original 6af6, guest PC 0x0c0a8290 */
if(!s->budget--) { s->failed_pc=0x0c0a8290u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a8292;
P_0c0a8292: /* original 6bf6, guest PC 0x0c0a8292 */
if(!s->budget--) { s->failed_pc=0x0c0a8292u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8294;
P_0c0a8294: /* original 6cf6, guest PC 0x0c0a8294 */
if(!s->budget--) { s->failed_pc=0x0c0a8294u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8296;
P_0c0a8296: /* original 6df6, guest PC 0x0c0a8296 */
if(!s->budget--) { s->failed_pc=0x0c0a8296u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8298;
P_0c0a8298: /* original 000b, guest PC 0x0c0a8298 */
if(!s->budget--) { s->failed_pc=0x0c0a8298u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a829a: /* original 6ef6, guest PC 0x0c0a829a */
if(!s->budget--) { s->failed_pc=0x0c0a829au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a829cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a829cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
