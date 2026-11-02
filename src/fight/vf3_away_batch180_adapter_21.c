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
int vf3_away_batch180_adapter_21(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09690au: goto P_0c09690a;
case 0x0c09690cu: goto P_0c09690c;
case 0x0c09690eu: goto P_0c09690e;
case 0x0c096910u: goto P_0c096910;
case 0x0c096912u: goto P_0c096912;
case 0x0c09a55eu: goto P_0c09a55e;
case 0x0c09a560u: goto P_0c09a560;
case 0x0c09a562u: goto P_0c09a562;
case 0x0c09a564u: goto P_0c09a564;
case 0x0c09a566u: goto P_0c09a566;
case 0x0c09a568u: goto P_0c09a568;
case 0x0c09a56au: goto P_0c09a56a;
case 0x0c09a56cu: goto P_0c09a56c;
case 0x0c09a56eu: goto P_0c09a56e;
case 0x0c09a570u: goto P_0c09a570;
case 0x0c09a572u: goto P_0c09a572;
case 0x0c09a574u: goto P_0c09a574;
case 0x0c09a576u: goto P_0c09a576;
case 0x0c09a578u: goto P_0c09a578;
case 0x0c09a57au: goto P_0c09a57a;
case 0x0c09a57cu: goto P_0c09a57c;
case 0x0c09a57eu: goto P_0c09a57e;
case 0x0c09a580u: goto P_0c09a580;
case 0x0c09a5b4u: goto P_0c09a5b4;
case 0x0c09a5b6u: goto P_0c09a5b6;
case 0x0c09a5b8u: goto P_0c09a5b8;
case 0x0c09a5bau: goto P_0c09a5ba;
case 0x0c09a5bcu: goto P_0c09a5bc;
case 0x0c09a5beu: goto P_0c09a5be;
case 0x0c09a5c0u: goto P_0c09a5c0;
case 0x0c09a5c2u: goto P_0c09a5c2;
case 0x0c09a5c4u: goto P_0c09a5c4;
case 0x0c09a5c6u: goto P_0c09a5c6;
case 0x0c09a5c8u: goto P_0c09a5c8;
case 0x0c09a5cau: goto P_0c09a5ca;
case 0x0c09a5ccu: goto P_0c09a5cc;
case 0x0c09a5ceu: goto P_0c09a5ce;
case 0x0c09a5d0u: goto P_0c09a5d0;
case 0x0c09a5d2u: goto P_0c09a5d2;
case 0x0c09a5d4u: goto P_0c09a5d4;
case 0x0c09a5d6u: goto P_0c09a5d6;
case 0x0c09a5d8u: goto P_0c09a5d8;
case 0x0c09a5dau: goto P_0c09a5da;
case 0x0c09a5dcu: goto P_0c09a5dc;
case 0x0c09a5deu: goto P_0c09a5de;
case 0x0c09a5e0u: goto P_0c09a5e0;
case 0x0c09a5e2u: goto P_0c09a5e2;
case 0x0c09a5e4u: goto P_0c09a5e4;
case 0x0c09a5e6u: goto P_0c09a5e6;
case 0x0c09a5e8u: goto P_0c09a5e8;
case 0x0c09a5eau: goto P_0c09a5ea;
case 0x0c09a5ecu: goto P_0c09a5ec;
case 0x0c09a5eeu: goto P_0c09a5ee;
case 0x0c09a5f0u: goto P_0c09a5f0;
case 0x0c09a5f2u: goto P_0c09a5f2;
case 0x0c09a5f4u: goto P_0c09a5f4;
case 0x0c09a5f6u: goto P_0c09a5f6;
case 0x0c09a5f8u: goto P_0c09a5f8;
case 0x0c09a5fau: goto P_0c09a5fa;
case 0x0c09a5fcu: goto P_0c09a5fc;
case 0x0c09a5feu: goto P_0c09a5fe;
case 0x0c09a600u: goto P_0c09a600;
case 0x0c09a602u: goto P_0c09a602;
case 0x0c09a604u: goto P_0c09a604;
case 0x0c09a606u: goto P_0c09a606;
case 0x0c09a608u: goto P_0c09a608;
case 0x0c09a60au: goto P_0c09a60a;
case 0x0c09a60cu: goto P_0c09a60c;
case 0x0c09a60eu: goto P_0c09a60e;
case 0x0c09a610u: goto P_0c09a610;
case 0x0c09a612u: goto P_0c09a612;
case 0x0c09a614u: goto P_0c09a614;
case 0x0c09a616u: goto P_0c09a616;
case 0x0c09a618u: goto P_0c09a618;
case 0x0c09a61au: goto P_0c09a61a;
case 0x0c09a61cu: goto P_0c09a61c;
case 0x0c09a61eu: goto P_0c09a61e;
case 0x0c09a620u: goto P_0c09a620;
case 0x0c09a622u: goto P_0c09a622;
case 0x0c09a624u: goto P_0c09a624;
case 0x0c09a626u: goto P_0c09a626;
case 0x0c09a628u: goto P_0c09a628;
case 0x0c09a62au: goto P_0c09a62a;
case 0x0c09a62cu: goto P_0c09a62c;
case 0x0c09a62eu: goto P_0c09a62e;
case 0x0c09a630u: goto P_0c09a630;
case 0x0c09a632u: goto P_0c09a632;
case 0x0c09a634u: goto P_0c09a634;
case 0x0c09a636u: goto P_0c09a636;
case 0x0c09a638u: goto P_0c09a638;
case 0x0c09a63au: goto P_0c09a63a;
case 0x0c09a63cu: goto P_0c09a63c;
case 0x0c09a63eu: goto P_0c09a63e;
case 0x0c09a640u: goto P_0c09a640;
case 0x0c09a642u: goto P_0c09a642;
case 0x0c09a644u: goto P_0c09a644;
case 0x0c09a646u: goto P_0c09a646;
case 0x0c09a648u: goto P_0c09a648;
case 0x0c09a64au: goto P_0c09a64a;
case 0x0c09a64cu: goto P_0c09a64c;
case 0x0c09a64eu: goto P_0c09a64e;
case 0x0c09a650u: goto P_0c09a650;
case 0x0c09a652u: goto P_0c09a652;
case 0x0c09a654u: goto P_0c09a654;
case 0x0c09a656u: goto P_0c09a656;
case 0x0c09a658u: goto P_0c09a658;
case 0x0c09a65au: goto P_0c09a65a;
case 0x0c09a65cu: goto P_0c09a65c;
case 0x0c09a65eu: goto P_0c09a65e;
case 0x0c09a660u: goto P_0c09a660;
case 0x0c09a662u: goto P_0c09a662;
case 0x0c09a664u: goto P_0c09a664;
case 0x0c09a666u: goto P_0c09a666;
case 0x0c09a668u: goto P_0c09a668;
case 0x0c09a66au: goto P_0c09a66a;
case 0x0c09a66cu: goto P_0c09a66c;
case 0x0c09a66eu: goto P_0c09a66e;
case 0x0c09a670u: goto P_0c09a670;
case 0x0c09a672u: goto P_0c09a672;
case 0x0c09a674u: goto P_0c09a674;
case 0x0c09a676u: goto P_0c09a676;
case 0x0c09a678u: goto P_0c09a678;
case 0x0c09a67au: goto P_0c09a67a;
case 0x0c09a67cu: goto P_0c09a67c;
case 0x0c09a67eu: goto P_0c09a67e;
case 0x0c09a680u: goto P_0c09a680;
case 0x0c09a682u: goto P_0c09a682;
case 0x0c09a684u: goto P_0c09a684;
case 0x0c09a686u: goto P_0c09a686;
case 0x0c09a688u: goto P_0c09a688;
case 0x0c09a68au: goto P_0c09a68a;
case 0x0c09a68cu: goto P_0c09a68c;
case 0x0c09a68eu: goto P_0c09a68e;
case 0x0c09a690u: goto P_0c09a690;
case 0x0c09a692u: goto P_0c09a692;
case 0x0c09a694u: goto P_0c09a694;
case 0x0c09a696u: goto P_0c09a696;
case 0x0c09a698u: goto P_0c09a698;
case 0x0c09a69au: goto P_0c09a69a;
case 0x0c09a69cu: goto P_0c09a69c;
case 0x0c09a69eu: goto P_0c09a69e;
case 0x0c09a6a0u: goto P_0c09a6a0;
case 0x0c09a6a2u: goto P_0c09a6a2;
case 0x0c09a6a4u: goto P_0c09a6a4;
case 0x0c09a6a6u: goto P_0c09a6a6;
case 0x0c09a6a8u: goto P_0c09a6a8;
case 0x0c09a6aau: goto P_0c09a6aa;
case 0x0c09a6acu: goto P_0c09a6ac;
case 0x0c09a6aeu: goto P_0c09a6ae;
case 0x0c09a6b0u: goto P_0c09a6b0;
case 0x0c09a6b2u: goto P_0c09a6b2;
case 0x0c09a6b4u: goto P_0c09a6b4;
case 0x0c09a6b6u: goto P_0c09a6b6;
case 0x0c09a6b8u: goto P_0c09a6b8;
case 0x0c09a6bau: goto P_0c09a6ba;
case 0x0c09a6bcu: goto P_0c09a6bc;
case 0x0c09a6beu: goto P_0c09a6be;
case 0x0c09a6c0u: goto P_0c09a6c0;
case 0x0c09a6c2u: goto P_0c09a6c2;
case 0x0c09a6c4u: goto P_0c09a6c4;
case 0x0c09a6c6u: goto P_0c09a6c6;
case 0x0c09a6c8u: goto P_0c09a6c8;
case 0x0c09a6cau: goto P_0c09a6ca;
case 0x0c09a6ccu: goto P_0c09a6cc;
case 0x0c09a6ceu: goto P_0c09a6ce;
case 0x0c09a6d0u: goto P_0c09a6d0;
case 0x0c09a6d2u: goto P_0c09a6d2;
case 0x0c09a6d4u: goto P_0c09a6d4;
case 0x0c09a710u: goto P_0c09a710;
case 0x0c09a712u: goto P_0c09a712;
case 0x0c09a714u: goto P_0c09a714;
case 0x0c09a716u: goto P_0c09a716;
case 0x0c09a718u: goto P_0c09a718;
case 0x0c09a71au: goto P_0c09a71a;
case 0x0c09a71cu: goto P_0c09a71c;
case 0x0c09a71eu: goto P_0c09a71e;
case 0x0c09a720u: goto P_0c09a720;
case 0x0c09a722u: goto P_0c09a722;
case 0x0c09a724u: goto P_0c09a724;
case 0x0c09a726u: goto P_0c09a726;
case 0x0c09a728u: goto P_0c09a728;
case 0x0c09a72au: goto P_0c09a72a;
case 0x0c09a72cu: goto P_0c09a72c;
case 0x0c09a72eu: goto P_0c09a72e;
case 0x0c09a730u: goto P_0c09a730;
case 0x0c09a732u: goto P_0c09a732;
case 0x0c09a734u: goto P_0c09a734;
case 0x0c09a736u: goto P_0c09a736;
case 0x0c09a738u: goto P_0c09a738;
case 0x0c09a73au: goto P_0c09a73a;
case 0x0c09a73cu: goto P_0c09a73c;
case 0x0c09a73eu: goto P_0c09a73e;
case 0x0c09a740u: goto P_0c09a740;
case 0x0c09a742u: goto P_0c09a742;
case 0x0c09a744u: goto P_0c09a744;
case 0x0c09a746u: goto P_0c09a746;
case 0x0c09a748u: goto P_0c09a748;
case 0x0c09a74au: goto P_0c09a74a;
case 0x0c09a74cu: goto P_0c09a74c;
case 0x0c09a74eu: goto P_0c09a74e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09690a: /* original 6042, guest PC 0x0c09690a */
if(!s->budget--) { s->failed_pc=0x0c09690au; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c09690c;
P_0c09690c: /* original cb01, guest PC 0x0c09690c */
if(!s->budget--) { s->failed_pc=0x0c09690cu; return 0; }
r[0]|=1u;
goto P_0c09690e;
P_0c09690e: /* original 2402, guest PC 0x0c09690e */
if(!s->budget--) { s->failed_pc=0x0c09690eu; return 0; }
write(ram,r[4],r[0],4);
goto P_0c096910;
P_0c096910: /* original 000b, guest PC 0x0c096910 */
if(!s->budget--) { s->failed_pc=0x0c096910u; return 0; }
target=r[16];
write(ram,r[4]+12,r[5],4);
s->pc=target; return ram->oob==0;
P_0c096912: /* original 1453, guest PC 0x0c096912 */
if(!s->budget--) { s->failed_pc=0x0c096912u; return 0; }
write(ram,r[4]+12,r[5],4);
if(!vf3_matrix_family(0x0c096914u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096914u; return 0; } return 1;
P_0c09a55e: /* original 2fe6, guest PC 0x0c09a55e */
if(!s->budget--) { s->failed_pc=0x0c09a55eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09a560;
P_0c09a560: /* original e029, guest PC 0x0c09a560 */
if(!s->budget--) { s->failed_pc=0x0c09a560u; return 0; }
r[0]=0x00000029u;
goto P_0c09a562;
P_0c09a562: /* original 2fd6, guest PC 0x0c09a562 */
if(!s->budget--) { s->failed_pc=0x0c09a562u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09a564;
P_0c09a564: /* original 2fc6, guest PC 0x0c09a564 */
if(!s->budget--) { s->failed_pc=0x0c09a564u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09a566;
P_0c09a566: /* original 2fb6, guest PC 0x0c09a566 */
if(!s->budget--) { s->failed_pc=0x0c09a566u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09a568;
P_0c09a568: /* original 2fa6, guest PC 0x0c09a568 */
if(!s->budget--) { s->failed_pc=0x0c09a568u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09a56a;
P_0c09a56a: /* original 2f96, guest PC 0x0c09a56a */
if(!s->budget--) { s->failed_pc=0x0c09a56au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09a56c;
P_0c09a56c: /* original fffb, guest PC 0x0c09a56c */
if(!s->budget--) { s->failed_pc=0x0c09a56cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09a56e;
P_0c09a56e: /* original dc07, guest PC 0x0c09a56e */
if(!s->budget--) { s->failed_pc=0x0c09a56eu; return 0; }
r[12]=read(ram,0x0c09a58cu,4);
goto P_0c09a570;
P_0c09a570: /* original 4f22, guest PC 0x0c09a570 */
if(!s->budget--) { s->failed_pc=0x0c09a570u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09a572;
P_0c09a572: /* original 00cc, guest PC 0x0c09a572 */
if(!s->budget--) { s->failed_pc=0x0c09a572u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c09a574;
P_0c09a574: /* original de0e, guest PC 0x0c09a574 */
if(!s->budget--) { s->failed_pc=0x0c09a574u; return 0; }
r[14]=read(ram,0x0c09a5b0u,4);
goto P_0c09a576;
P_0c09a576: /* original 600c, guest PC 0x0c09a576 */
if(!s->budget--) { s->failed_pc=0x0c09a576u; return 0; }
r[0]=r[0]&255u;
goto P_0c09a578;
P_0c09a578: /* original dd05, guest PC 0x0c09a578 */
if(!s->budget--) { s->failed_pc=0x0c09a578u; return 0; }
r[13]=read(ram,0x0c09a590u,4);
goto P_0c09a57a;
P_0c09a57a: /* original 8801, guest PC 0x0c09a57a */
if(!s->budget--) { s->failed_pc=0x0c09a57au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09a57c;
P_0c09a57c: /* original 8b1a, guest PC 0x0c09a57c */
if(!s->budget--) { s->failed_pc=0x0c09a57cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09a5b4; }
goto P_0c09a57e;
P_0c09a57e: /* original a01a, guest PC 0x0c09a57e */
if(!s->budget--) { s->failed_pc=0x0c09a57eu; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c09a5b6;
P_0c09a580: /* original 54e4, guest PC 0x0c09a580 */
if(!s->budget--) { s->failed_pc=0x0c09a580u; return 0; }
r[4]=read(ram,r[14]+16,4);
if(!vf3_matrix_family(0x0c09a582u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09a582u; return 0; } return 1;
P_0c09a5b4: /* original 54e5, guest PC 0x0c09a5b4 */
if(!s->budget--) { s->failed_pc=0x0c09a5b4u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c09a5b6;
P_0c09a5b6: /* original 908e, guest PC 0x0c09a5b6 */
if(!s->budget--) { s->failed_pc=0x0c09a5b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a6d6u,2);
goto P_0c09a5b8;
P_0c09a5b8: /* original 03cc, guest PC 0x0c09a5b8 */
if(!s->budget--) { s->failed_pc=0x0c09a5b8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c09a5ba;
P_0c09a5ba: /* original e060, guest PC 0x0c09a5ba */
if(!s->budget--) { s->failed_pc=0x0c09a5bau; return 0; }
r[0]=0x00000060u;
goto P_0c09a5bc;
P_0c09a5bc: /* original 0434, guest PC 0x0c09a5bc */
if(!s->budget--) { s->failed_pc=0x0c09a5bcu; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c09a5be;
P_0c09a5be: /* original 908b, guest PC 0x0c09a5be */
if(!s->budget--) { s->failed_pc=0x0c09a5beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a6d8u,2);
goto P_0c09a5c0;
P_0c09a5c0: /* original 02cc, guest PC 0x0c09a5c0 */
if(!s->budget--) { s->failed_pc=0x0c09a5c0u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c09a5c2;
P_0c09a5c2: /* original e061, guest PC 0x0c09a5c2 */
if(!s->budget--) { s->failed_pc=0x0c09a5c2u; return 0; }
r[0]=0x00000061u;
goto P_0c09a5c4;
P_0c09a5c4: /* original 0424, guest PC 0x0c09a5c4 */
if(!s->budget--) { s->failed_pc=0x0c09a5c4u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c09a5c6;
P_0c09a5c6: /* original d547, guest PC 0x0c09a5c6 */
if(!s->budget--) { s->failed_pc=0x0c09a5c6u; return 0; }
r[5]=read(ram,0x0c09a6e4u,4);
goto P_0c09a5c8;
P_0c09a5c8: /* original d347, guest PC 0x0c09a5c8 */
if(!s->budget--) { s->failed_pc=0x0c09a5c8u; return 0; }
r[3]=read(ram,0x0c09a6e8u,4);
goto P_0c09a5ca;
P_0c09a5ca: /* original 430b, guest PC 0x0c09a5ca */
if(!s->budget--) { s->failed_pc=0x0c09a5cau; return 0; }
target=r[3];
r[16]=code_base|0x0c09a5ceu;
r[4]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a5ceu) { target=s->pc; goto dispatch; }
goto P_0c09a5ce;
P_0c09a5cc: /* original 54e7, guest PC 0x0c09a5cc */
if(!s->budget--) { s->failed_pc=0x0c09a5ccu; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c09a5ce;
P_0c09a5ce: /* original d246, guest PC 0x0c09a5ce */
if(!s->budget--) { s->failed_pc=0x0c09a5ceu; return 0; }
r[2]=read(ram,0x0c09a6e8u,4);
goto P_0c09a5d0;
P_0c09a5d0: /* original d546, guest PC 0x0c09a5d0 */
if(!s->budget--) { s->failed_pc=0x0c09a5d0u; return 0; }
r[5]=read(ram,0x0c09a6ecu,4);
goto P_0c09a5d2;
P_0c09a5d2: /* original 420b, guest PC 0x0c09a5d2 */
if(!s->budget--) { s->failed_pc=0x0c09a5d2u; return 0; }
target=r[2];
r[16]=code_base|0x0c09a5d6u;
r[4]=read(ram,r[14]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a5d6u) { target=s->pc; goto dispatch; }
goto P_0c09a5d6;
P_0c09a5d4: /* original 54e6, guest PC 0x0c09a5d4 */
if(!s->budget--) { s->failed_pc=0x0c09a5d4u; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c09a5d6;
P_0c09a5d6: /* original d346, guest PC 0x0c09a5d6 */
if(!s->budget--) { s->failed_pc=0x0c09a5d6u; return 0; }
r[3]=read(ram,0x0c09a6f0u,4);
goto P_0c09a5d8;
P_0c09a5d8: /* original 430b, guest PC 0x0c09a5d8 */
if(!s->budget--) { s->failed_pc=0x0c09a5d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c09a5dcu;
r[4]=0x0000001fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a5dcu) { target=s->pc; goto dispatch; }
goto P_0c09a5dc;
P_0c09a5da: /* original e41f, guest PC 0x0c09a5da */
if(!s->budget--) { s->failed_pc=0x0c09a5dau; return 0; }
r[4]=0x0000001fu;
goto P_0c09a5dc;
P_0c09a5dc: /* original d345, guest PC 0x0c09a5dc */
if(!s->budget--) { s->failed_pc=0x0c09a5dcu; return 0; }
r[3]=read(ram,0x0c09a6f4u,4);
goto P_0c09a5de;
P_0c09a5de: /* original e01c, guest PC 0x0c09a5de */
if(!s->budget--) { s->failed_pc=0x0c09a5deu; return 0; }
r[0]=0x0000001cu;
goto P_0c09a5e0;
P_0c09a5e0: /* original e90d, guest PC 0x0c09a5e0 */
if(!s->budget--) { s->failed_pc=0x0c09a5e0u; return 0; }
r[9]=0x0000000du;
goto P_0c09a5e2;
P_0c09a5e2: /* original 430b, guest PC 0x0c09a5e2 */
if(!s->budget--) { s->failed_pc=0x0c09a5e2u; return 0; }
target=r[3];
r[16]=code_base|0x0c09a5e6u;
write(ram,r[13]+r[0],r[9],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a5e6u) { target=s->pc; goto dispatch; }
goto P_0c09a5e6;
P_0c09a5e4: /* original 0d94, guest PC 0x0c09a5e4 */
if(!s->budget--) { s->failed_pc=0x0c09a5e4u; return 0; }
write(ram,r[13]+r[0],r[9],1);
goto P_0c09a5e6;
P_0c09a5e6: /* original d244, guest PC 0x0c09a5e6 */
if(!s->budget--) { s->failed_pc=0x0c09a5e6u; return 0; }
r[2]=read(ram,0x0c09a6f8u,4);
goto P_0c09a5e8;
P_0c09a5e8: /* original 420b, guest PC 0x0c09a5e8 */
if(!s->budget--) { s->failed_pc=0x0c09a5e8u; return 0; }
target=r[2];
r[16]=code_base|0x0c09a5ecu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a5ecu) { target=s->pc; goto dispatch; }
goto P_0c09a5ec;
P_0c09a5ea: /* original 0009, guest PC 0x0c09a5ea */
if(!s->budget--) { s->failed_pc=0x0c09a5eau; return 0; }
goto P_0c09a5ec;
P_0c09a5ec: /* original e029, guest PC 0x0c09a5ec */
if(!s->budget--) { s->failed_pc=0x0c09a5ecu; return 0; }
r[0]=0x00000029u;
goto P_0c09a5ee;
P_0c09a5ee: /* original da43, guest PC 0x0c09a5ee */
if(!s->budget--) { s->failed_pc=0x0c09a5eeu; return 0; }
r[10]=read(ram,0x0c09a6fcu,4);
goto P_0c09a5f0;
P_0c09a5f0: /* original 00cc, guest PC 0x0c09a5f0 */
if(!s->budget--) { s->failed_pc=0x0c09a5f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c09a5f2;
P_0c09a5f2: /* original e715, guest PC 0x0c09a5f2 */
if(!s->budget--) { s->failed_pc=0x0c09a5f2u; return 0; }
r[7]=0x00000015u;
goto P_0c09a5f4;
P_0c09a5f4: /* original e408, guest PC 0x0c09a5f4 */
if(!s->budget--) { s->failed_pc=0x0c09a5f4u; return 0; }
r[4]=0x00000008u;
goto P_0c09a5f6;
P_0c09a5f6: /* original 600c, guest PC 0x0c09a5f6 */
if(!s->budget--) { s->failed_pc=0x0c09a5f6u; return 0; }
r[0]=r[0]&255u;
goto P_0c09a5f8;
P_0c09a5f8: /* original 8802, guest PC 0x0c09a5f8 */
if(!s->budget--) { s->failed_pc=0x0c09a5f8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09a5fa;
P_0c09a5fa: /* original eb02, guest PC 0x0c09a5fa */
if(!s->budget--) { s->failed_pc=0x0c09a5fau; return 0; }
r[11]=0x00000002u;
goto P_0c09a5fc;
P_0c09a5fc: /* original 8d2d, guest PC 0x0c09a5fc */
if(!s->budget--) { s->failed_pc=0x0c09a5fcu; return 0; }
cond=r[17]&1u;
fr[15]=0;
if(cond) { goto P_0c09a65a; }
goto P_0c09a600;
P_0c09a5fe: /* original ff8d, guest PC 0x0c09a5fe */
if(!s->budget--) { s->failed_pc=0x0c09a5feu; return 0; }
fr[15]=0;
goto P_0c09a600;
P_0c09a600: /* original 56e4, guest PC 0x0c09a600 */
if(!s->budget--) { s->failed_pc=0x0c09a600u; return 0; }
r[6]=read(ram,r[14]+16,4);
goto P_0c09a602;
P_0c09a602: /* original e060, guest PC 0x0c09a602 */
if(!s->budget--) { s->failed_pc=0x0c09a602u; return 0; }
r[0]=0x00000060u;
goto P_0c09a604;
P_0c09a604: /* original 036c, guest PC 0x0c09a604 */
if(!s->budget--) { s->failed_pc=0x0c09a604u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c09a606;
P_0c09a606: /* original 633c, guest PC 0x0c09a606 */
if(!s->budget--) { s->failed_pc=0x0c09a606u; return 0; }
r[3]=r[3]&255u;
goto P_0c09a608;
P_0c09a608: /* original 3393, guest PC 0x0c09a608 */
if(!s->budget--) { s->failed_pc=0x0c09a608u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[9])!=0);
goto P_0c09a60a;
P_0c09a60a: /* original 8f06, guest PC 0x0c09a60a */
if(!s->budget--) { s->failed_pc=0x0c09a60au; return 0; }
cond=r[17]&1u;
r[5]=r[7];
if(!cond) { goto P_0c09a61a; }
goto P_0c09a60e;
P_0c09a60c: /* original 6573, guest PC 0x0c09a60c */
if(!s->budget--) { s->failed_pc=0x0c09a60cu; return 0; }
r[5]=r[7];
goto P_0c09a60e;
P_0c09a60e: /* original 9064, guest PC 0x0c09a60e */
if(!s->budget--) { s->failed_pc=0x0c09a60eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a6dau,2);
goto P_0c09a610;
P_0c09a610: /* original 6543, guest PC 0x0c09a610 */
if(!s->budget--) { s->failed_pc=0x0c09a610u; return 0; }
r[5]=r[4];
goto P_0c09a612;
P_0c09a612: /* original d33b, guest PC 0x0c09a612 */
if(!s->budget--) { s->failed_pc=0x0c09a612u; return 0; }
r[3]=read(ram,0x0c09a700u,4);
goto P_0c09a614;
P_0c09a614: /* original 06de, guest PC 0x0c09a614 */
if(!s->budget--) { s->failed_pc=0x0c09a614u; return 0; }
r[6]=read(ram,r[13]+r[0],4);
goto P_0c09a616;
P_0c09a616: /* original 263b, guest PC 0x0c09a616 */
if(!s->budget--) { s->failed_pc=0x0c09a616u; return 0; }
r[6]|=r[3];
goto P_0c09a618;
P_0c09a618: /* original 0d66, guest PC 0x0c09a618 */
if(!s->budget--) { s->failed_pc=0x0c09a618u; return 0; }
write(ram,r[13]+r[0],r[6],4);
goto P_0c09a61a;
P_0c09a61a: /* original 56e5, guest PC 0x0c09a61a */
if(!s->budget--) { s->failed_pc=0x0c09a61au; return 0; }
r[6]=read(ram,r[14]+20,4);
goto P_0c09a61c;
P_0c09a61c: /* original e060, guest PC 0x0c09a61c */
if(!s->budget--) { s->failed_pc=0x0c09a61cu; return 0; }
r[0]=0x00000060u;
goto P_0c09a61e;
P_0c09a61e: /* original 0654, guest PC 0x0c09a61e */
if(!s->budget--) { s->failed_pc=0x0c09a61eu; return 0; }
write(ram,r[6]+r[0],r[5],1);
goto P_0c09a620;
P_0c09a620: /* original e061, guest PC 0x0c09a620 */
if(!s->budget--) { s->failed_pc=0x0c09a620u; return 0; }
r[0]=0x00000061u;
goto P_0c09a622;
P_0c09a622: /* original 0644, guest PC 0x0c09a622 */
if(!s->budget--) { s->failed_pc=0x0c09a622u; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c09a624;
P_0c09a624: /* original c738, guest PC 0x0c09a624 */
if(!s->budget--) { s->failed_pc=0x0c09a624u; return 0; }
r[0]=code_base|0x0009a708u;
goto P_0c09a626;
P_0c09a626: /* original f408, guest PC 0x0c09a626 */
if(!s->budget--) { s->failed_pc=0x0c09a626u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c09a628;
P_0c09a628: /* original d536, guest PC 0x0c09a628 */
if(!s->budget--) { s->failed_pc=0x0c09a628u; return 0; }
r[5]=read(ram,0x0c09a704u,4);
goto P_0c09a62a;
P_0c09a62a: /* original f6fc, guest PC 0x0c09a62a */
if(!s->budget--) { s->failed_pc=0x0c09a62au; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c09a62c;
P_0c09a62c: /* original f5fc, guest PC 0x0c09a62c */
if(!s->budget--) { s->failed_pc=0x0c09a62cu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09a62e;
P_0c09a62e: /* original 4a0b, guest PC 0x0c09a62e */
if(!s->budget--) { s->failed_pc=0x0c09a62eu; return 0; }
target=r[10];
r[16]=code_base|0x0c09a632u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a632u) { target=s->pc; goto dispatch; }
goto P_0c09a632;
P_0c09a630: /* original e400, guest PC 0x0c09a630 */
if(!s->budget--) { s->failed_pc=0x0c09a630u; return 0; }
r[4]=0x00000000u;
goto P_0c09a632;
P_0c09a632: /* original 9553, guest PC 0x0c09a632 */
if(!s->budget--) { s->failed_pc=0x0c09a632u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a6dcu,2);
goto P_0c09a634;
P_0c09a634: /* original f49d, guest PC 0x0c09a634 */
if(!s->budget--) { s->failed_pc=0x0c09a634u; return 0; }
fr[4]=0x3f800000u;
goto P_0c09a636;
P_0c09a636: /* original f5fc, guest PC 0x0c09a636 */
if(!s->budget--) { s->failed_pc=0x0c09a636u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09a638;
P_0c09a638: /* original f6fc, guest PC 0x0c09a638 */
if(!s->budget--) { s->failed_pc=0x0c09a638u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c09a63a;
P_0c09a63a: /* original 4a0b, guest PC 0x0c09a63a */
if(!s->budget--) { s->failed_pc=0x0c09a63au; return 0; }
target=r[10];
r[16]=code_base|0x0c09a63eu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a63eu) { target=s->pc; goto dispatch; }
goto P_0c09a63e;
P_0c09a63c: /* original e401, guest PC 0x0c09a63c */
if(!s->budget--) { s->failed_pc=0x0c09a63cu; return 0; }
r[4]=0x00000001u;
goto P_0c09a63e;
P_0c09a63e: /* original 904e, guest PC 0x0c09a63e */
if(!s->budget--) { s->failed_pc=0x0c09a63eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a6deu,2);
goto P_0c09a640;
P_0c09a640: /* original e301, guest PC 0x0c09a640 */
if(!s->budget--) { s->failed_pc=0x0c09a640u; return 0; }
r[3]=0x00000001u;
goto P_0c09a642;
P_0c09a642: /* original 5ae5, guest PC 0x0c09a642 */
if(!s->budget--) { s->failed_pc=0x0c09a642u; return 0; }
r[10]=read(ram,r[14]+20,4);
goto P_0c09a644;
P_0c09a644: /* original 0c34, guest PC 0x0c09a644 */
if(!s->budget--) { s->failed_pc=0x0c09a644u; return 0; }
write(ram,r[12]+r[0],r[3],1);
goto P_0c09a646;
P_0c09a646: /* original e3fd, guest PC 0x0c09a646 */
if(!s->budget--) { s->failed_pc=0x0c09a646u; return 0; }
r[3]=0xfffffffdu;
goto P_0c09a648;
P_0c09a648: /* original 57ea, guest PC 0x0c09a648 */
if(!s->budget--) { s->failed_pc=0x0c09a648u; return 0; }
r[7]=read(ram,r[14]+40,4);
goto P_0c09a64a;
P_0c09a64a: /* original 56eb, guest PC 0x0c09a64a */
if(!s->budget--) { s->failed_pc=0x0c09a64au; return 0; }
r[6]=read(ram,r[14]+44,4);
goto P_0c09a64c;
P_0c09a64c: /* original 6572, guest PC 0x0c09a64c */
if(!s->budget--) { s->failed_pc=0x0c09a64cu; return 0; }
tmp=read(ram,r[7],4);
r[5]=tmp;
goto P_0c09a64e;
P_0c09a64e: /* original 6462, guest PC 0x0c09a64e */
if(!s->budget--) { s->failed_pc=0x0c09a64eu; return 0; }
tmp=read(ram,r[6],4);
r[4]=tmp;
goto P_0c09a650;
P_0c09a650: /* original 25bb, guest PC 0x0c09a650 */
if(!s->budget--) { s->failed_pc=0x0c09a650u; return 0; }
r[5]|=r[11];
goto P_0c09a652;
P_0c09a652: /* original 2752, guest PC 0x0c09a652 */
if(!s->budget--) { s->failed_pc=0x0c09a652u; return 0; }
write(ram,r[7],r[5],4);
goto P_0c09a654;
P_0c09a654: /* original 2439, guest PC 0x0c09a654 */
if(!s->budget--) { s->failed_pc=0x0c09a654u; return 0; }
r[4]&=r[3];
goto P_0c09a656;
P_0c09a656: /* original a02c, guest PC 0x0c09a656 */
if(!s->budget--) { s->failed_pc=0x0c09a656u; return 0; }
write(ram,r[6],r[4],4);
goto P_0c09a6b2;
P_0c09a658: /* original 2642, guest PC 0x0c09a658 */
if(!s->budget--) { s->failed_pc=0x0c09a658u; return 0; }
write(ram,r[6],r[4],4);
goto P_0c09a65a;
P_0c09a65a: /* original 56e5, guest PC 0x0c09a65a */
if(!s->budget--) { s->failed_pc=0x0c09a65au; return 0; }
r[6]=read(ram,r[14]+20,4);
goto P_0c09a65c;
P_0c09a65c: /* original e060, guest PC 0x0c09a65c */
if(!s->budget--) { s->failed_pc=0x0c09a65cu; return 0; }
r[0]=0x00000060u;
goto P_0c09a65e;
P_0c09a65e: /* original 036c, guest PC 0x0c09a65e */
if(!s->budget--) { s->failed_pc=0x0c09a65eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c09a660;
P_0c09a660: /* original 633c, guest PC 0x0c09a660 */
if(!s->budget--) { s->failed_pc=0x0c09a660u; return 0; }
r[3]=r[3]&255u;
goto P_0c09a662;
P_0c09a662: /* original 3393, guest PC 0x0c09a662 */
if(!s->budget--) { s->failed_pc=0x0c09a662u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[9])!=0);
goto P_0c09a664;
P_0c09a664: /* original 8d06, guest PC 0x0c09a664 */
if(!s->budget--) { s->failed_pc=0x0c09a664u; return 0; }
cond=r[17]&1u;
r[5]=r[4];
if(cond) { goto P_0c09a674; }
goto P_0c09a668;
P_0c09a666: /* original 6543, guest PC 0x0c09a666 */
if(!s->budget--) { s->failed_pc=0x0c09a666u; return 0; }
r[5]=r[4];
goto P_0c09a668;
P_0c09a668: /* original 9037, guest PC 0x0c09a668 */
if(!s->budget--) { s->failed_pc=0x0c09a668u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a6dau,2);
goto P_0c09a66a;
P_0c09a66a: /* original 6573, guest PC 0x0c09a66a */
if(!s->budget--) { s->failed_pc=0x0c09a66au; return 0; }
r[5]=r[7];
goto P_0c09a66c;
P_0c09a66c: /* original d324, guest PC 0x0c09a66c */
if(!s->budget--) { s->failed_pc=0x0c09a66cu; return 0; }
r[3]=read(ram,0x0c09a700u,4);
goto P_0c09a66e;
P_0c09a66e: /* original 06de, guest PC 0x0c09a66e */
if(!s->budget--) { s->failed_pc=0x0c09a66eu; return 0; }
r[6]=read(ram,r[13]+r[0],4);
goto P_0c09a670;
P_0c09a670: /* original 263b, guest PC 0x0c09a670 */
if(!s->budget--) { s->failed_pc=0x0c09a670u; return 0; }
r[6]|=r[3];
goto P_0c09a672;
P_0c09a672: /* original 0d66, guest PC 0x0c09a672 */
if(!s->budget--) { s->failed_pc=0x0c09a672u; return 0; }
write(ram,r[13]+r[0],r[6],4);
goto P_0c09a674;
P_0c09a674: /* original 56e4, guest PC 0x0c09a674 */
if(!s->budget--) { s->failed_pc=0x0c09a674u; return 0; }
r[6]=read(ram,r[14]+16,4);
goto P_0c09a676;
P_0c09a676: /* original e060, guest PC 0x0c09a676 */
if(!s->budget--) { s->failed_pc=0x0c09a676u; return 0; }
r[0]=0x00000060u;
goto P_0c09a678;
P_0c09a678: /* original 0654, guest PC 0x0c09a678 */
if(!s->budget--) { s->failed_pc=0x0c09a678u; return 0; }
write(ram,r[6]+r[0],r[5],1);
goto P_0c09a67a;
P_0c09a67a: /* original e061, guest PC 0x0c09a67a */
if(!s->budget--) { s->failed_pc=0x0c09a67au; return 0; }
r[0]=0x00000061u;
goto P_0c09a67c;
P_0c09a67c: /* original 0644, guest PC 0x0c09a67c */
if(!s->budget--) { s->failed_pc=0x0c09a67cu; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c09a67e;
P_0c09a67e: /* original c722, guest PC 0x0c09a67e */
if(!s->budget--) { s->failed_pc=0x0c09a67eu; return 0; }
r[0]=code_base|0x0009a708u;
goto P_0c09a680;
P_0c09a680: /* original f408, guest PC 0x0c09a680 */
if(!s->budget--) { s->failed_pc=0x0c09a680u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c09a682;
P_0c09a682: /* original d520, guest PC 0x0c09a682 */
if(!s->budget--) { s->failed_pc=0x0c09a682u; return 0; }
r[5]=read(ram,0x0c09a704u,4);
goto P_0c09a684;
P_0c09a684: /* original f6fc, guest PC 0x0c09a684 */
if(!s->budget--) { s->failed_pc=0x0c09a684u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c09a686;
P_0c09a686: /* original f5fc, guest PC 0x0c09a686 */
if(!s->budget--) { s->failed_pc=0x0c09a686u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09a688;
P_0c09a688: /* original 4a0b, guest PC 0x0c09a688 */
if(!s->budget--) { s->failed_pc=0x0c09a688u; return 0; }
target=r[10];
r[16]=code_base|0x0c09a68cu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a68cu) { target=s->pc; goto dispatch; }
goto P_0c09a68c;
P_0c09a68a: /* original e400, guest PC 0x0c09a68a */
if(!s->budget--) { s->failed_pc=0x0c09a68au; return 0; }
r[4]=0x00000000u;
goto P_0c09a68c;
P_0c09a68c: /* original 9526, guest PC 0x0c09a68c */
if(!s->budget--) { s->failed_pc=0x0c09a68cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a6dcu,2);
goto P_0c09a68e;
P_0c09a68e: /* original f49d, guest PC 0x0c09a68e */
if(!s->budget--) { s->failed_pc=0x0c09a68eu; return 0; }
fr[4]=0x3f800000u;
goto P_0c09a690;
P_0c09a690: /* original f5fc, guest PC 0x0c09a690 */
if(!s->budget--) { s->failed_pc=0x0c09a690u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09a692;
P_0c09a692: /* original f6fc, guest PC 0x0c09a692 */
if(!s->budget--) { s->failed_pc=0x0c09a692u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c09a694;
P_0c09a694: /* original 4a0b, guest PC 0x0c09a694 */
if(!s->budget--) { s->failed_pc=0x0c09a694u; return 0; }
target=r[10];
r[16]=code_base|0x0c09a698u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a698u) { target=s->pc; goto dispatch; }
goto P_0c09a698;
P_0c09a696: /* original e401, guest PC 0x0c09a696 */
if(!s->budget--) { s->failed_pc=0x0c09a696u; return 0; }
r[4]=0x00000001u;
goto P_0c09a698;
P_0c09a698: /* original 9021, guest PC 0x0c09a698 */
if(!s->budget--) { s->failed_pc=0x0c09a698u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a6deu,2);
goto P_0c09a69a;
P_0c09a69a: /* original e300, guest PC 0x0c09a69a */
if(!s->budget--) { s->failed_pc=0x0c09a69au; return 0; }
r[3]=0x00000000u;
goto P_0c09a69c;
P_0c09a69c: /* original 5ae5, guest PC 0x0c09a69c */
if(!s->budget--) { s->failed_pc=0x0c09a69cu; return 0; }
r[10]=read(ram,r[14]+20,4);
goto P_0c09a69e;
P_0c09a69e: /* original 0c34, guest PC 0x0c09a69e */
if(!s->budget--) { s->failed_pc=0x0c09a69eu; return 0; }
write(ram,r[12]+r[0],r[3],1);
goto P_0c09a6a0;
P_0c09a6a0: /* original e3fd, guest PC 0x0c09a6a0 */
if(!s->budget--) { s->failed_pc=0x0c09a6a0u; return 0; }
r[3]=0xfffffffdu;
goto P_0c09a6a2;
P_0c09a6a2: /* original 54ea, guest PC 0x0c09a6a2 */
if(!s->budget--) { s->failed_pc=0x0c09a6a2u; return 0; }
r[4]=read(ram,r[14]+40,4);
goto P_0c09a6a4;
P_0c09a6a4: /* original 56eb, guest PC 0x0c09a6a4 */
if(!s->budget--) { s->failed_pc=0x0c09a6a4u; return 0; }
r[6]=read(ram,r[14]+44,4);
goto P_0c09a6a6;
P_0c09a6a6: /* original 6742, guest PC 0x0c09a6a6 */
if(!s->budget--) { s->failed_pc=0x0c09a6a6u; return 0; }
tmp=read(ram,r[4],4);
r[7]=tmp;
goto P_0c09a6a8;
P_0c09a6a8: /* original 6562, guest PC 0x0c09a6a8 */
if(!s->budget--) { s->failed_pc=0x0c09a6a8u; return 0; }
tmp=read(ram,r[6],4);
r[5]=tmp;
goto P_0c09a6aa;
P_0c09a6aa: /* original 2739, guest PC 0x0c09a6aa */
if(!s->budget--) { s->failed_pc=0x0c09a6aau; return 0; }
r[7]&=r[3];
goto P_0c09a6ac;
P_0c09a6ac: /* original 25bb, guest PC 0x0c09a6ac */
if(!s->budget--) { s->failed_pc=0x0c09a6acu; return 0; }
r[5]|=r[11];
goto P_0c09a6ae;
P_0c09a6ae: /* original 2472, guest PC 0x0c09a6ae */
if(!s->budget--) { s->failed_pc=0x0c09a6aeu; return 0; }
write(ram,r[4],r[7],4);
goto P_0c09a6b0;
P_0c09a6b0: /* original 2652, guest PC 0x0c09a6b0 */
if(!s->budget--) { s->failed_pc=0x0c09a6b0u; return 0; }
write(ram,r[6],r[5],4);
goto P_0c09a6b2;
P_0c09a6b2: /* original d216, guest PC 0x0c09a6b2 */
if(!s->budget--) { s->failed_pc=0x0c09a6b2u; return 0; }
r[2]=read(ram,0x0c09a70cu,4);
goto P_0c09a6b4;
P_0c09a6b4: /* original 420b, guest PC 0x0c09a6b4 */
if(!s->budget--) { s->failed_pc=0x0c09a6b4u; return 0; }
target=r[2];
r[16]=code_base|0x0c09a6b8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a6b8u) { target=s->pc; goto dispatch; }
goto P_0c09a6b8;
P_0c09a6b6: /* original 0009, guest PC 0x0c09a6b6 */
if(!s->budget--) { s->failed_pc=0x0c09a6b6u; return 0; }
goto P_0c09a6b8;
P_0c09a6b8: /* original 9012, guest PC 0x0c09a6b8 */
if(!s->budget--) { s->failed_pc=0x0c09a6b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a6e0u,2);
goto P_0c09a6ba;
P_0c09a6ba: /* original 03cc, guest PC 0x0c09a6ba */
if(!s->budget--) { s->failed_pc=0x0c09a6bau; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c09a6bc;
P_0c09a6bc: /* original 2338, guest PC 0x0c09a6bc */
if(!s->budget--) { s->failed_pc=0x0c09a6bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09a6be;
P_0c09a6be: /* original 8927, guest PC 0x0c09a6be */
if(!s->budget--) { s->failed_pc=0x0c09a6beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09a710; }
goto P_0c09a6c0;
P_0c09a6c0: /* original 900f, guest PC 0x0c09a6c0 */
if(!s->budget--) { s->failed_pc=0x0c09a6c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a6e2u,2);
goto P_0c09a6c2;
P_0c09a6c2: /* original 54e8, guest PC 0x0c09a6c2 */
if(!s->budget--) { s->failed_pc=0x0c09a6c2u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c09a6c4;
P_0c09a6c4: /* original 04b4, guest PC 0x0c09a6c4 */
if(!s->budget--) { s->failed_pc=0x0c09a6c4u; return 0; }
write(ram,r[4]+r[0],r[11],1);
goto P_0c09a6c6;
P_0c09a6c6: /* original 50c2, guest PC 0x0c09a6c6 */
if(!s->budget--) { s->failed_pc=0x0c09a6c6u; return 0; }
r[0]=read(ram,r[12]+8,4);
goto P_0c09a6c8;
P_0c09a6c8: /* original c804, guest PC 0x0c09a6c8 */
if(!s->budget--) { s->failed_pc=0x0c09a6c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c09a6ca;
P_0c09a6ca: /* original 8901, guest PC 0x0c09a6ca */
if(!s->budget--) { s->failed_pc=0x0c09a6cau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09a6d0; }
goto P_0c09a6cc;
P_0c09a6cc: /* original a001, guest PC 0x0c09a6cc */
if(!s->budget--) { s->failed_pc=0x0c09a6ccu; return 0; }
r[0]=0x00000012u;
goto P_0c09a6d2;
P_0c09a6ce: /* original e012, guest PC 0x0c09a6ce */
if(!s->budget--) { s->failed_pc=0x0c09a6ceu; return 0; }
r[0]=0x00000012u;
goto P_0c09a6d0;
P_0c09a6d0: /* original e010, guest PC 0x0c09a6d0 */
if(!s->budget--) { s->failed_pc=0x0c09a6d0u; return 0; }
r[0]=0x00000010u;
goto P_0c09a6d2;
P_0c09a6d2: /* original a034, guest PC 0x0c09a6d2 */
if(!s->budget--) { s->failed_pc=0x0c09a6d2u; return 0; }
write(ram,r[13]+10,r[0],1);
goto P_0c09a73e;
P_0c09a6d4: /* original 80da, guest PC 0x0c09a6d4 */
if(!s->budget--) { s->failed_pc=0x0c09a6d4u; return 0; }
write(ram,r[13]+10,r[0],1);
if(!vf3_matrix_family(0x0c09a6d6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09a6d6u; return 0; } return 1;
P_0c09a710: /* original d344, guest PC 0x0c09a710 */
if(!s->budget--) { s->failed_pc=0x0c09a710u; return 0; }
r[3]=read(ram,0x0c09a824u,4);
goto P_0c09a712;
P_0c09a712: /* original 430b, guest PC 0x0c09a712 */
if(!s->budget--) { s->failed_pc=0x0c09a712u; return 0; }
target=r[3];
r[16]=code_base|0x0c09a716u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a716u) { target=s->pc; goto dispatch; }
goto P_0c09a716;
P_0c09a714: /* original 64a3, guest PC 0x0c09a714 */
if(!s->budget--) { s->failed_pc=0x0c09a714u; return 0; }
r[4]=r[10];
goto P_0c09a716;
P_0c09a716: /* original 4f26, guest PC 0x0c09a716 */
if(!s->budget--) { s->failed_pc=0x0c09a716u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09a718;
P_0c09a718: /* original 54e8, guest PC 0x0c09a718 */
if(!s->budget--) { s->failed_pc=0x0c09a718u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c09a71a;
P_0c09a71a: /* original e32b, guest PC 0x0c09a71a */
if(!s->budget--) { s->failed_pc=0x0c09a71au; return 0; }
r[3]=0x0000002bu;
goto P_0c09a71c;
P_0c09a71c: /* original 907c, guest PC 0x0c09a71c */
if(!s->budget--) { s->failed_pc=0x0c09a71cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a818u,2);
goto P_0c09a71e;
P_0c09a71e: /* original 04b4, guest PC 0x0c09a71e */
if(!s->budget--) { s->failed_pc=0x0c09a71eu; return 0; }
write(ram,r[4]+r[0],r[11],1);
goto P_0c09a720;
P_0c09a720: /* original e010, guest PC 0x0c09a720 */
if(!s->budget--) { s->failed_pc=0x0c09a720u; return 0; }
r[0]=0x00000010u;
goto P_0c09a722;
P_0c09a722: /* original 0d34, guest PC 0x0c09a722 */
if(!s->budget--) { s->failed_pc=0x0c09a722u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c09a724;
P_0c09a724: /* original 9279, guest PC 0x0c09a724 */
if(!s->budget--) { s->failed_pc=0x0c09a724u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a81au,2);
goto P_0c09a726;
P_0c09a726: /* original 1d23, guest PC 0x0c09a726 */
if(!s->budget--) { s->failed_pc=0x0c09a726u; return 0; }
write(ram,r[13]+12,r[2],4);
goto P_0c09a728;
P_0c09a728: /* original 84da, guest PC 0x0c09a728 */
if(!s->budget--) { s->failed_pc=0x0c09a728u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+10,1);
goto P_0c09a72a;
P_0c09a72a: /* original 7001, guest PC 0x0c09a72a */
if(!s->budget--) { s->failed_pc=0x0c09a72au; return 0; }
r[0]+=0x00000001u;
goto P_0c09a72c;
P_0c09a72c: /* original 80da, guest PC 0x0c09a72c */
if(!s->budget--) { s->failed_pc=0x0c09a72cu; return 0; }
write(ram,r[13]+10,r[0],1);
goto P_0c09a72e;
P_0c09a72e: /* original fff9, guest PC 0x0c09a72e */
if(!s->budget--) { s->failed_pc=0x0c09a72eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09a730;
P_0c09a730: /* original 69f6, guest PC 0x0c09a730 */
if(!s->budget--) { s->failed_pc=0x0c09a730u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09a732;
P_0c09a732: /* original 6af6, guest PC 0x0c09a732 */
if(!s->budget--) { s->failed_pc=0x0c09a732u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09a734;
P_0c09a734: /* original 6bf6, guest PC 0x0c09a734 */
if(!s->budget--) { s->failed_pc=0x0c09a734u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09a736;
P_0c09a736: /* original 6cf6, guest PC 0x0c09a736 */
if(!s->budget--) { s->failed_pc=0x0c09a736u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09a738;
P_0c09a738: /* original 6df6, guest PC 0x0c09a738 */
if(!s->budget--) { s->failed_pc=0x0c09a738u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09a73a;
P_0c09a73a: /* original a009, guest PC 0x0c09a73a */
if(!s->budget--) { s->failed_pc=0x0c09a73au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09a750u,s,ram);
P_0c09a73c: /* original 6ef6, guest PC 0x0c09a73c */
if(!s->budget--) { s->failed_pc=0x0c09a73cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09a73e;
P_0c09a73e: /* original 4f26, guest PC 0x0c09a73e */
if(!s->budget--) { s->failed_pc=0x0c09a73eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09a740;
P_0c09a740: /* original fff9, guest PC 0x0c09a740 */
if(!s->budget--) { s->failed_pc=0x0c09a740u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09a742;
P_0c09a742: /* original 69f6, guest PC 0x0c09a742 */
if(!s->budget--) { s->failed_pc=0x0c09a742u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09a744;
P_0c09a744: /* original 6af6, guest PC 0x0c09a744 */
if(!s->budget--) { s->failed_pc=0x0c09a744u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09a746;
P_0c09a746: /* original 6bf6, guest PC 0x0c09a746 */
if(!s->budget--) { s->failed_pc=0x0c09a746u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09a748;
P_0c09a748: /* original 6cf6, guest PC 0x0c09a748 */
if(!s->budget--) { s->failed_pc=0x0c09a748u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09a74a;
P_0c09a74a: /* original 6df6, guest PC 0x0c09a74a */
if(!s->budget--) { s->failed_pc=0x0c09a74au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09a74c;
P_0c09a74c: /* original 000b, guest PC 0x0c09a74c */
if(!s->budget--) { s->failed_pc=0x0c09a74cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09a74e: /* original 6ef6, guest PC 0x0c09a74e */
if(!s->budget--) { s->failed_pc=0x0c09a74eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09a750u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
