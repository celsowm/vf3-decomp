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
int vf3_away_batch2_adapter_11(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04667au: goto P_0c04667a;
case 0x0c04667cu: goto P_0c04667c;
case 0x0c04667eu: goto P_0c04667e;
case 0x0c046680u: goto P_0c046680;
case 0x0c046682u: goto P_0c046682;
case 0x0c046684u: goto P_0c046684;
case 0x0c046686u: goto P_0c046686;
case 0x0c046688u: goto P_0c046688;
case 0x0c04668au: goto P_0c04668a;
case 0x0c04668cu: goto P_0c04668c;
case 0x0c04668eu: goto P_0c04668e;
case 0x0c046690u: goto P_0c046690;
case 0x0c046692u: goto P_0c046692;
case 0x0c046694u: goto P_0c046694;
case 0x0c046696u: goto P_0c046696;
case 0x0c046698u: goto P_0c046698;
case 0x0c04669au: goto P_0c04669a;
case 0x0c04669cu: goto P_0c04669c;
case 0x0c04669eu: goto P_0c04669e;
case 0x0c04708cu: goto P_0c04708c;
case 0x0c04708eu: goto P_0c04708e;
case 0x0c047090u: goto P_0c047090;
case 0x0c047092u: goto P_0c047092;
case 0x0c047094u: goto P_0c047094;
case 0x0c047096u: goto P_0c047096;
case 0x0c047098u: goto P_0c047098;
case 0x0c04709au: goto P_0c04709a;
case 0x0c04709cu: goto P_0c04709c;
case 0x0c04709eu: goto P_0c04709e;
case 0x0c0470a0u: goto P_0c0470a0;
case 0x0c0470a2u: goto P_0c0470a2;
case 0x0c0470a4u: goto P_0c0470a4;
case 0x0c0470a6u: goto P_0c0470a6;
case 0x0c0470a8u: goto P_0c0470a8;
case 0x0c0470aau: goto P_0c0470aa;
case 0x0c0470acu: goto P_0c0470ac;
case 0x0c0470aeu: goto P_0c0470ae;
case 0x0c0470b0u: goto P_0c0470b0;
case 0x0c0470b2u: goto P_0c0470b2;
case 0x0c0470b4u: goto P_0c0470b4;
case 0x0c0470b6u: goto P_0c0470b6;
case 0x0c0470b8u: goto P_0c0470b8;
case 0x0c0470bau: goto P_0c0470ba;
case 0x0c0470bcu: goto P_0c0470bc;
case 0x0c0470beu: goto P_0c0470be;
case 0x0c0470d8u: goto P_0c0470d8;
case 0x0c0470dau: goto P_0c0470da;
case 0x0c0470dcu: goto P_0c0470dc;
case 0x0c0470deu: goto P_0c0470de;
case 0x0c0470e0u: goto P_0c0470e0;
case 0x0c0470e2u: goto P_0c0470e2;
case 0x0c0470e4u: goto P_0c0470e4;
case 0x0c0470e6u: goto P_0c0470e6;
case 0x0c0470e8u: goto P_0c0470e8;
case 0x0c0470eau: goto P_0c0470ea;
case 0x0c0470ecu: goto P_0c0470ec;
case 0x0c0470eeu: goto P_0c0470ee;
case 0x0c0470f0u: goto P_0c0470f0;
case 0x0c0470f2u: goto P_0c0470f2;
case 0x0c0470f4u: goto P_0c0470f4;
case 0x0c0470f6u: goto P_0c0470f6;
case 0x0c0470f8u: goto P_0c0470f8;
case 0x0c0470fau: goto P_0c0470fa;
case 0x0c0470fcu: goto P_0c0470fc;
case 0x0c0470feu: goto P_0c0470fe;
case 0x0c047100u: goto P_0c047100;
case 0x0c047102u: goto P_0c047102;
case 0x0c047104u: goto P_0c047104;
case 0x0c047106u: goto P_0c047106;
case 0x0c047108u: goto P_0c047108;
case 0x0c04710au: goto P_0c04710a;
case 0x0c04710cu: goto P_0c04710c;
case 0x0c04710eu: goto P_0c04710e;
case 0x0c047110u: goto P_0c047110;
case 0x0c047112u: goto P_0c047112;
case 0x0c047114u: goto P_0c047114;
case 0x0c047116u: goto P_0c047116;
case 0x0c047118u: goto P_0c047118;
case 0x0c04711au: goto P_0c04711a;
case 0x0c04711cu: goto P_0c04711c;
case 0x0c04711eu: goto P_0c04711e;
case 0x0c047120u: goto P_0c047120;
case 0x0c047122u: goto P_0c047122;
case 0x0c047124u: goto P_0c047124;
case 0x0c047126u: goto P_0c047126;
case 0x0c047128u: goto P_0c047128;
case 0x0c04712au: goto P_0c04712a;
case 0x0c04712cu: goto P_0c04712c;
case 0x0c04712eu: goto P_0c04712e;
case 0x0c047130u: goto P_0c047130;
case 0x0c047132u: goto P_0c047132;
case 0x0c047134u: goto P_0c047134;
case 0x0c047136u: goto P_0c047136;
case 0x0c047138u: goto P_0c047138;
case 0x0c04713au: goto P_0c04713a;
case 0x0c04713cu: goto P_0c04713c;
case 0x0c04713eu: goto P_0c04713e;
case 0x0c047140u: goto P_0c047140;
case 0x0c047142u: goto P_0c047142;
case 0x0c047144u: goto P_0c047144;
case 0x0c047146u: goto P_0c047146;
case 0x0c047148u: goto P_0c047148;
case 0x0c04714au: goto P_0c04714a;
case 0x0c04714cu: goto P_0c04714c;
case 0x0c04714eu: goto P_0c04714e;
case 0x0c047150u: goto P_0c047150;
case 0x0c047152u: goto P_0c047152;
case 0x0c047154u: goto P_0c047154;
case 0x0c047156u: goto P_0c047156;
case 0x0c047158u: goto P_0c047158;
case 0x0c04715au: goto P_0c04715a;
case 0x0c04715cu: goto P_0c04715c;
case 0x0c04715eu: goto P_0c04715e;
case 0x0c047160u: goto P_0c047160;
case 0x0c047162u: goto P_0c047162;
case 0x0c047164u: goto P_0c047164;
case 0x0c047166u: goto P_0c047166;
case 0x0c047168u: goto P_0c047168;
case 0x0c04716au: goto P_0c04716a;
case 0x0c04716cu: goto P_0c04716c;
case 0x0c04716eu: goto P_0c04716e;
case 0x0c047170u: goto P_0c047170;
case 0x0c047172u: goto P_0c047172;
case 0x0c047174u: goto P_0c047174;
case 0x0c047176u: goto P_0c047176;
case 0x0c047178u: goto P_0c047178;
case 0x0c04717au: goto P_0c04717a;
case 0x0c04717cu: goto P_0c04717c;
case 0x0c04717eu: goto P_0c04717e;
case 0x0c047180u: goto P_0c047180;
case 0x0c047182u: goto P_0c047182;
case 0x0c047184u: goto P_0c047184;
case 0x0c047186u: goto P_0c047186;
case 0x0c047188u: goto P_0c047188;
case 0x0c04718au: goto P_0c04718a;
case 0x0c04718cu: goto P_0c04718c;
case 0x0c04718eu: goto P_0c04718e;
case 0x0c047190u: goto P_0c047190;
case 0x0c047192u: goto P_0c047192;
case 0x0c047194u: goto P_0c047194;
case 0x0c047196u: goto P_0c047196;
case 0x0c047198u: goto P_0c047198;
case 0x0c04719au: goto P_0c04719a;
case 0x0c04719cu: goto P_0c04719c;
case 0x0c04719eu: goto P_0c04719e;
case 0x0c0471a0u: goto P_0c0471a0;
case 0x0c0471a2u: goto P_0c0471a2;
case 0x0c0471a4u: goto P_0c0471a4;
case 0x0c0471a6u: goto P_0c0471a6;
case 0x0c0471a8u: goto P_0c0471a8;
case 0x0c0471aau: goto P_0c0471aa;
case 0x0c0471acu: goto P_0c0471ac;
case 0x0c0471aeu: goto P_0c0471ae;
case 0x0c0471b0u: goto P_0c0471b0;
case 0x0c0471b2u: goto P_0c0471b2;
case 0x0c0471b4u: goto P_0c0471b4;
case 0x0c0471b6u: goto P_0c0471b6;
case 0x0c0471b8u: goto P_0c0471b8;
case 0x0c0471bau: goto P_0c0471ba;
case 0x0c0471bcu: goto P_0c0471bc;
case 0x0c0471beu: goto P_0c0471be;
case 0x0c0471c0u: goto P_0c0471c0;
case 0x0c0471c2u: goto P_0c0471c2;
case 0x0c0471c4u: goto P_0c0471c4;
case 0x0c0471c6u: goto P_0c0471c6;
case 0x0c0471c8u: goto P_0c0471c8;
case 0x0c0471cau: goto P_0c0471ca;
case 0x0c0471ccu: goto P_0c0471cc;
case 0x0c0471ceu: goto P_0c0471ce;
case 0x0c0471d0u: goto P_0c0471d0;
case 0x0c0471d2u: goto P_0c0471d2;
case 0x0c0471d4u: goto P_0c0471d4;
case 0x0c0471d6u: goto P_0c0471d6;
case 0x0c0471d8u: goto P_0c0471d8;
case 0x0c0471dau: goto P_0c0471da;
case 0x0c0471dcu: goto P_0c0471dc;
case 0x0c0471deu: goto P_0c0471de;
case 0x0c0471e0u: goto P_0c0471e0;
case 0x0c0471e2u: goto P_0c0471e2;
case 0x0c0471e4u: goto P_0c0471e4;
case 0x0c0471e6u: goto P_0c0471e6;
case 0x0c0471e8u: goto P_0c0471e8;
case 0x0c0471eau: goto P_0c0471ea;
case 0x0c0471ecu: goto P_0c0471ec;
case 0x0c0471eeu: goto P_0c0471ee;
case 0x0c0471f0u: goto P_0c0471f0;
case 0x0c0471f2u: goto P_0c0471f2;
case 0x0c0471f4u: goto P_0c0471f4;
case 0x0c0471f6u: goto P_0c0471f6;
case 0x0c0471f8u: goto P_0c0471f8;
case 0x0c0471fau: goto P_0c0471fa;
case 0x0c0471fcu: goto P_0c0471fc;
case 0x0c0471feu: goto P_0c0471fe;
case 0x0c047200u: goto P_0c047200;
case 0x0c047202u: goto P_0c047202;
case 0x0c047204u: goto P_0c047204;
case 0x0c047218u: goto P_0c047218;
case 0x0c04721au: goto P_0c04721a;
case 0x0c04721cu: goto P_0c04721c;
case 0x0c04721eu: goto P_0c04721e;
case 0x0c047220u: goto P_0c047220;
case 0x0c047222u: goto P_0c047222;
case 0x0c047224u: goto P_0c047224;
case 0x0c047226u: goto P_0c047226;
case 0x0c047228u: goto P_0c047228;
case 0x0c04722au: goto P_0c04722a;
case 0x0c04722cu: goto P_0c04722c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04667a: /* original 4f22, guest PC 0x0c04667a */
if(!s->budget--) { s->failed_pc=0x0c04667au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04667c;
P_0c04667c: /* original 7ff8, guest PC 0x0c04667c */
if(!s->budget--) { s->failed_pc=0x0c04667cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c04667e;
P_0c04667e: /* original 2f42, guest PC 0x0c04667e */
if(!s->budget--) { s->failed_pc=0x0c04667eu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c046680;
P_0c046680: /* original 1f51, guest PC 0x0c046680 */
if(!s->budget--) { s->failed_pc=0x0c046680u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c046682;
P_0c046682: /* original d322, guest PC 0x0c046682 */
if(!s->budget--) { s->failed_pc=0x0c046682u; return 0; }
r[3]=read(ram,0x0c04670cu,4);
goto P_0c046684;
P_0c046684: /* original 430b, guest PC 0x0c046684 */
if(!s->budget--) { s->failed_pc=0x0c046684u; return 0; }
target=r[3];
r[16]=code_base|0x0c046688u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c046688u) { target=s->pc; goto dispatch; }
goto P_0c046688;
P_0c046686: /* original 64f2, guest PC 0x0c046686 */
if(!s->budget--) { s->failed_pc=0x0c046686u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c046688;
P_0c046688: /* original 2008, guest PC 0x0c046688 */
if(!s->budget--) { s->failed_pc=0x0c046688u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04668a;
P_0c04668a: /* original 8903, guest PC 0x0c04668a */
if(!s->budget--) { s->failed_pc=0x0c04668au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046694; }
goto P_0c04668c;
P_0c04668c: /* original 7f08, guest PC 0x0c04668c */
if(!s->budget--) { s->failed_pc=0x0c04668cu; return 0; }
r[15]+=0x00000008u;
goto P_0c04668e;
P_0c04668e: /* original 4f26, guest PC 0x0c04668e */
if(!s->budget--) { s->failed_pc=0x0c04668eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046690;
P_0c046690: /* original 000b, guest PC 0x0c046690 */
if(!s->budget--) { s->failed_pc=0x0c046690u; return 0; }
target=r[16];
r[0]=0xffffffffu;
s->pc=target; return ram->oob==0;
P_0c046692: /* original e0ff, guest PC 0x0c046692 */
if(!s->budget--) { s->failed_pc=0x0c046692u; return 0; }
r[0]=0xffffffffu;
goto P_0c046694;
P_0c046694: /* original d324, guest PC 0x0c046694 */
if(!s->budget--) { s->failed_pc=0x0c046694u; return 0; }
r[3]=read(ram,0x0c046728u,4);
goto P_0c046696;
P_0c046696: /* original 64f2, guest PC 0x0c046696 */
if(!s->budget--) { s->failed_pc=0x0c046696u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c046698;
P_0c046698: /* original 55f1, guest PC 0x0c046698 */
if(!s->budget--) { s->failed_pc=0x0c046698u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c04669a;
P_0c04669a: /* original 7f08, guest PC 0x0c04669a */
if(!s->budget--) { s->failed_pc=0x0c04669au; return 0; }
r[15]+=0x00000008u;
goto P_0c04669c;
P_0c04669c: /* original 432b, guest PC 0x0c04669c */
if(!s->budget--) { s->failed_pc=0x0c04669cu; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c04669e: /* original 4f26, guest PC 0x0c04669e */
if(!s->budget--) { s->failed_pc=0x0c04669eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c0466a0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0466a0u; return 0; } return 1;
P_0c04708c: /* original 2fe6, guest PC 0x0c04708c */
if(!s->budget--) { s->failed_pc=0x0c04708cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04708e;
P_0c04708e: /* original 6e53, guest PC 0x0c04708e */
if(!s->budget--) { s->failed_pc=0x0c04708eu; return 0; }
r[14]=r[5];
goto P_0c047090;
P_0c047090: /* original 2fd6, guest PC 0x0c047090 */
if(!s->budget--) { s->failed_pc=0x0c047090u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c047092;
P_0c047092: /* original e040, guest PC 0x0c047092 */
if(!s->budget--) { s->failed_pc=0x0c047092u; return 0; }
r[0]=0x00000040u;
goto P_0c047094;
P_0c047094: /* original 2fc6, guest PC 0x0c047094 */
if(!s->budget--) { s->failed_pc=0x0c047094u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c047096;
P_0c047096: /* original 2fb6, guest PC 0x0c047096 */
if(!s->budget--) { s->failed_pc=0x0c047096u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c047098;
P_0c047098: /* original 2fa6, guest PC 0x0c047098 */
if(!s->budget--) { s->failed_pc=0x0c047098u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04709a;
P_0c04709a: /* original 4f22, guest PC 0x0c04709a */
if(!s->budget--) { s->failed_pc=0x0c04709au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04709c;
P_0c04709c: /* original 03ed, guest PC 0x0c04709c */
if(!s->budget--) { s->failed_pc=0x0c04709cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c04709e;
P_0c04709e: /* original 2338, guest PC 0x0c04709e */
if(!s->budget--) { s->failed_pc=0x0c04709eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0470a0;
P_0c0470a0: /* original 7ffc, guest PC 0x0c0470a0 */
if(!s->budget--) { s->failed_pc=0x0c0470a0u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0470a2;
P_0c0470a2: /* original 8d0a, guest PC 0x0c0470a2 */
if(!s->budget--) { s->failed_pc=0x0c0470a2u; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c0470ba; }
goto P_0c0470a6;
P_0c0470a4: /* original 6d53, guest PC 0x0c0470a4 */
if(!s->budget--) { s->failed_pc=0x0c0470a4u; return 0; }
r[13]=r[5];
goto P_0c0470a6;
P_0c0470a6: /* original 03ed, guest PC 0x0c0470a6 */
if(!s->budget--) { s->failed_pc=0x0c0470a6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0470a8;
P_0c0470a8: /* original e503, guest PC 0x0c0470a8 */
if(!s->budget--) { s->failed_pc=0x0c0470a8u; return 0; }
r[5]=0x00000003u;
goto P_0c0470aa;
P_0c0470aa: /* original 633d, guest PC 0x0c0470aa */
if(!s->budget--) { s->failed_pc=0x0c0470aau; return 0; }
r[3]=r[3]&65535u;
goto P_0c0470ac;
P_0c0470ac: /* original 3357, guest PC 0x0c0470ac */
if(!s->budget--) { s->failed_pc=0x0c0470acu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[5])!=0);
goto P_0c0470ae;
P_0c0470ae: /* original 8904, guest PC 0x0c0470ae */
if(!s->budget--) { s->failed_pc=0x0c0470aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0470ba; }
goto P_0c0470b0;
P_0c0470b0: /* original e044, guest PC 0x0c0470b0 */
if(!s->budget--) { s->failed_pc=0x0c0470b0u; return 0; }
r[0]=0x00000044u;
goto P_0c0470b2;
P_0c0470b2: /* original 03ed, guest PC 0x0c0470b2 */
if(!s->budget--) { s->failed_pc=0x0c0470b2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0470b4;
P_0c0470b4: /* original 633d, guest PC 0x0c0470b4 */
if(!s->budget--) { s->failed_pc=0x0c0470b4u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0470b6;
P_0c0470b6: /* original 3357, guest PC 0x0c0470b6 */
if(!s->budget--) { s->failed_pc=0x0c0470b6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[5])!=0);
goto P_0c0470b8;
P_0c0470b8: /* original 8b0e, guest PC 0x0c0470b8 */
if(!s->budget--) { s->failed_pc=0x0c0470b8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0470d8; }
goto P_0c0470ba;
P_0c0470ba: /* original 9005, guest PC 0x0c0470ba */
if(!s->budget--) { s->failed_pc=0x0c0470bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0470c8u,2);
goto P_0c0470bc;
P_0c0470bc: /* original a084, guest PC 0x0c0470bc */
if(!s->budget--) { s->failed_pc=0x0c0470bcu; return 0; }
goto P_0c0471c8;
P_0c0470be: /* original 0009, guest PC 0x0c0470be */
if(!s->budget--) { s->failed_pc=0x0c0470beu; return 0; }
if(!vf3_matrix_family(0x0c0470c0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0470c0u; return 0; } return 1;
P_0c0470d8: /* original e040, guest PC 0x0c0470d8 */
if(!s->budget--) { s->failed_pc=0x0c0470d8u; return 0; }
r[0]=0x00000040u;
goto P_0c0470da;
P_0c0470da: /* original 9194, guest PC 0x0c0470da */
if(!s->budget--) { s->failed_pc=0x0c0470dau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c047206u,2);
goto P_0c0470dc;
P_0c0470dc: /* original 0aed, guest PC 0x0c0470dc */
if(!s->budget--) { s->failed_pc=0x0c0470dcu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0470de;
P_0c0470de: /* original 67e3, guest PC 0x0c0470de */
if(!s->budget--) { s->failed_pc=0x0c0470deu; return 0; }
r[7]=r[14];
goto P_0c0470e0;
P_0c0470e0: /* original d04a, guest PC 0x0c0470e0 */
if(!s->budget--) { s->failed_pc=0x0c0470e0u; return 0; }
r[0]=read(ram,0x0c04720cu,4);
goto P_0c0470e2;
P_0c0470e2: /* original 6643, guest PC 0x0c0470e2 */
if(!s->budget--) { s->failed_pc=0x0c0470e2u; return 0; }
r[6]=r[4];
goto P_0c0470e4;
P_0c0470e4: /* original 6aad, guest PC 0x0c0470e4 */
if(!s->budget--) { s->failed_pc=0x0c0470e4u; return 0; }
r[10]=r[10]&65535u;
goto P_0c0470e6;
P_0c0470e6: /* original 4a08, guest PC 0x0c0470e6 */
if(!s->budget--) { s->failed_pc=0x0c0470e6u; return 0; }
r[10]<<=2;
goto P_0c0470e8;
P_0c0470e8: /* original 0aae, guest PC 0x0c0470e8 */
if(!s->budget--) { s->failed_pc=0x0c0470e8u; return 0; }
r[10]=read(ram,r[10]+r[0],4);
goto P_0c0470ea;
P_0c0470ea: /* original e044, guest PC 0x0c0470ea */
if(!s->budget--) { s->failed_pc=0x0c0470eau; return 0; }
r[0]=0x00000044u;
goto P_0c0470ec;
P_0c0470ec: /* original 0bed, guest PC 0x0c0470ec */
if(!s->budget--) { s->failed_pc=0x0c0470ecu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0470ee;
P_0c0470ee: /* original d048, guest PC 0x0c0470ee */
if(!s->budget--) { s->failed_pc=0x0c0470eeu; return 0; }
r[0]=read(ram,0x0c047210u,4);
goto P_0c0470f0;
P_0c0470f0: /* original 63a3, guest PC 0x0c0470f0 */
if(!s->budget--) { s->failed_pc=0x0c0470f0u; return 0; }
r[3]=r[10];
goto P_0c0470f2;
P_0c0470f2: /* original 6bbd, guest PC 0x0c0470f2 */
if(!s->budget--) { s->failed_pc=0x0c0470f2u; return 0; }
r[11]=r[11]&65535u;
goto P_0c0470f4;
P_0c0470f4: /* original 4b08, guest PC 0x0c0470f4 */
if(!s->budget--) { s->failed_pc=0x0c0470f4u; return 0; }
r[11]<<=2;
goto P_0c0470f6;
P_0c0470f6: /* original 0bbe, guest PC 0x0c0470f6 */
if(!s->budget--) { s->failed_pc=0x0c0470f6u; return 0; }
r[11]=read(ram,r[11]+r[0],4);
goto P_0c0470f8;
P_0c0470f8: /* original e048, guest PC 0x0c0470f8 */
if(!s->budget--) { s->failed_pc=0x0c0470f8u; return 0; }
r[0]=0x00000048u;
goto P_0c0470fa;
P_0c0470fa: /* original 02ee, guest PC 0x0c0470fa */
if(!s->budget--) { s->failed_pc=0x0c0470fau; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0470fc;
P_0c0470fc: /* original 33bc, guest PC 0x0c0470fc */
if(!s->budget--) { s->failed_pc=0x0c0470fcu; return 0; }
r[3]+=r[11];
goto P_0c0470fe;
P_0c0470fe: /* original 332c, guest PC 0x0c0470fe */
if(!s->budget--) { s->failed_pc=0x0c0470feu; return 0; }
r[3]+=r[2];
goto P_0c047100;
P_0c047100: /* original 331c, guest PC 0x0c047100 */
if(!s->budget--) { s->failed_pc=0x0c047100u; return 0; }
r[3]+=r[1];
goto P_0c047102;
P_0c047102: /* original 2f32, guest PC 0x0c047102 */
if(!s->budget--) { s->failed_pc=0x0c047102u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c047104;
P_0c047104: /* original a004, guest PC 0x0c047104 */
if(!s->budget--) { s->failed_pc=0x0c047104u; return 0; }
r[5]=0x00000010u;
goto P_0c047110;
P_0c047106: /* original e510, guest PC 0x0c047106 */
if(!s->budget--) { s->failed_pc=0x0c047106u; return 0; }
r[5]=0x00000010u;
goto P_0c047108;
P_0c047108: /* original 6374, guest PC 0x0c047108 */
if(!s->budget--) { s->failed_pc=0x0c047108u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]+=1;
r[3]=tmp;
goto P_0c04710a;
P_0c04710a: /* original 75ff, guest PC 0x0c04710a */
if(!s->budget--) { s->failed_pc=0x0c04710au; return 0; }
r[5]+=0xffffffffu;
goto P_0c04710c;
P_0c04710c: /* original 2630, guest PC 0x0c04710c */
if(!s->budget--) { s->failed_pc=0x0c04710cu; return 0; }
write(ram,r[6],r[3],1);
goto P_0c04710e;
P_0c04710e: /* original 7601, guest PC 0x0c04710e */
if(!s->budget--) { s->failed_pc=0x0c04710eu; return 0; }
r[6]+=0x00000001u;
goto P_0c047110;
P_0c047110: /* original 2558, guest PC 0x0c047110 */
if(!s->budget--) { s->failed_pc=0x0c047110u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c047112;
P_0c047112: /* original 8bf9, guest PC 0x0c047112 */
if(!s->budget--) { s->failed_pc=0x0c047112u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c047108; }
goto P_0c047114;
P_0c047114: /* original 6743, guest PC 0x0c047114 */
if(!s->budget--) { s->failed_pc=0x0c047114u; return 0; }
r[7]=r[4];
goto P_0c047116;
P_0c047116: /* original 6ce3, guest PC 0x0c047116 */
if(!s->budget--) { s->failed_pc=0x0c047116u; return 0; }
r[12]=r[14];
goto P_0c047118;
P_0c047118: /* original e500, guest PC 0x0c047118 */
if(!s->budget--) { s->failed_pc=0x0c047118u; return 0; }
r[5]=0x00000000u;
goto P_0c04711a;
P_0c04711a: /* original 7c10, guest PC 0x0c04711a */
if(!s->budget--) { s->failed_pc=0x0c04711au; return 0; }
r[12]+=0x00000010u;
goto P_0c04711c;
P_0c04711c: /* original 2650, guest PC 0x0c04711c */
if(!s->budget--) { s->failed_pc=0x0c04711cu; return 0; }
write(ram,r[6],r[5],1);
goto P_0c04711e;
P_0c04711e: /* original 7712, guest PC 0x0c04711e */
if(!s->budget--) { s->failed_pc=0x0c04711eu; return 0; }
r[7]+=0x00000012u;
goto P_0c047120;
P_0c047120: /* original a004, guest PC 0x0c047120 */
if(!s->budget--) { s->failed_pc=0x0c047120u; return 0; }
r[6]=0x00000020u;
goto P_0c04712c;
P_0c047122: /* original e620, guest PC 0x0c047122 */
if(!s->budget--) { s->failed_pc=0x0c047122u; return 0; }
r[6]=0x00000020u;
goto P_0c047124;
P_0c047124: /* original 63c4, guest PC 0x0c047124 */
if(!s->budget--) { s->failed_pc=0x0c047124u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[12]+=1;
r[3]=tmp;
goto P_0c047126;
P_0c047126: /* original 76ff, guest PC 0x0c047126 */
if(!s->budget--) { s->failed_pc=0x0c047126u; return 0; }
r[6]+=0xffffffffu;
goto P_0c047128;
P_0c047128: /* original 2730, guest PC 0x0c047128 */
if(!s->budget--) { s->failed_pc=0x0c047128u; return 0; }
write(ram,r[7],r[3],1);
goto P_0c04712a;
P_0c04712a: /* original 7701, guest PC 0x0c04712a */
if(!s->budget--) { s->failed_pc=0x0c04712au; return 0; }
r[7]+=0x00000001u;
goto P_0c04712c;
P_0c04712c: /* original 2668, guest PC 0x0c04712c */
if(!s->budget--) { s->failed_pc=0x0c04712cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c04712e;
P_0c04712e: /* original 8bf9, guest PC 0x0c04712e */
if(!s->budget--) { s->failed_pc=0x0c04712eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c047124; }
goto P_0c047130;
P_0c047130: /* original 2750, guest PC 0x0c047130 */
if(!s->budget--) { s->failed_pc=0x0c047130u; return 0; }
write(ram,r[7],r[5],1);
goto P_0c047132;
P_0c047132: /* original 6ce3, guest PC 0x0c047132 */
if(!s->budget--) { s->failed_pc=0x0c047132u; return 0; }
r[12]=r[14];
goto P_0c047134;
P_0c047134: /* original 6743, guest PC 0x0c047134 */
if(!s->budget--) { s->failed_pc=0x0c047134u; return 0; }
r[7]=r[4];
goto P_0c047136;
P_0c047136: /* original 7c30, guest PC 0x0c047136 */
if(!s->budget--) { s->failed_pc=0x0c047136u; return 0; }
r[12]+=0x00000030u;
goto P_0c047138;
P_0c047138: /* original 7734, guest PC 0x0c047138 */
if(!s->budget--) { s->failed_pc=0x0c047138u; return 0; }
r[7]+=0x00000034u;
goto P_0c04713a;
P_0c04713a: /* original a004, guest PC 0x0c04713a */
if(!s->budget--) { s->failed_pc=0x0c04713au; return 0; }
r[6]=0x00000010u;
goto P_0c047146;
P_0c04713c: /* original e610, guest PC 0x0c04713c */
if(!s->budget--) { s->failed_pc=0x0c04713cu; return 0; }
r[6]=0x00000010u;
goto P_0c04713e;
P_0c04713e: /* original 63c4, guest PC 0x0c04713e */
if(!s->budget--) { s->failed_pc=0x0c04713eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[12]+=1;
r[3]=tmp;
goto P_0c047140;
P_0c047140: /* original 76ff, guest PC 0x0c047140 */
if(!s->budget--) { s->failed_pc=0x0c047140u; return 0; }
r[6]+=0xffffffffu;
goto P_0c047142;
P_0c047142: /* original 2730, guest PC 0x0c047142 */
if(!s->budget--) { s->failed_pc=0x0c047142u; return 0; }
write(ram,r[7],r[3],1);
goto P_0c047144;
P_0c047144: /* original 7701, guest PC 0x0c047144 */
if(!s->budget--) { s->failed_pc=0x0c047144u; return 0; }
r[7]+=0x00000001u;
goto P_0c047146;
P_0c047146: /* original 2668, guest PC 0x0c047146 */
if(!s->budget--) { s->failed_pc=0x0c047146u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c047148;
P_0c047148: /* original 8bf9, guest PC 0x0c047148 */
if(!s->budget--) { s->failed_pc=0x0c047148u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04713e; }
goto P_0c04714a;
P_0c04714a: /* original e042, guest PC 0x0c04714a */
if(!s->budget--) { s->failed_pc=0x0c04714au; return 0; }
r[0]=0x00000042u;
goto P_0c04714c;
P_0c04714c: /* original 66d3, guest PC 0x0c04714c */
if(!s->budget--) { s->failed_pc=0x0c04714cu; return 0; }
r[6]=r[13];
goto P_0c04714e;
P_0c04714e: /* original 2750, guest PC 0x0c04714e */
if(!s->budget--) { s->failed_pc=0x0c04714eu; return 0; }
write(ram,r[7],r[5],1);
goto P_0c047150;
P_0c047150: /* original 03ed, guest PC 0x0c047150 */
if(!s->budget--) { s->failed_pc=0x0c047150u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c047152;
P_0c047152: /* original e04e, guest PC 0x0c047152 */
if(!s->budget--) { s->failed_pc=0x0c047152u; return 0; }
r[0]=0x0000004eu;
goto P_0c047154;
P_0c047154: /* original 0435, guest PC 0x0c047154 */
if(!s->budget--) { s->failed_pc=0x0c047154u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c047156;
P_0c047156: /* original e040, guest PC 0x0c047156 */
if(!s->budget--) { s->failed_pc=0x0c047156u; return 0; }
r[0]=0x00000040u;
goto P_0c047158;
P_0c047158: /* original 02ed, guest PC 0x0c047158 */
if(!s->budget--) { s->failed_pc=0x0c047158u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c04715a;
P_0c04715a: /* original e04c, guest PC 0x0c04715a */
if(!s->budget--) { s->failed_pc=0x0c04715au; return 0; }
r[0]=0x0000004cu;
goto P_0c04715c;
P_0c04715c: /* original 63d3, guest PC 0x0c04715c */
if(!s->budget--) { s->failed_pc=0x0c04715cu; return 0; }
r[3]=r[13];
goto P_0c04715e;
P_0c04715e: /* original 7360, guest PC 0x0c04715e */
if(!s->budget--) { s->failed_pc=0x0c04715eu; return 0; }
r[3]+=0x00000060u;
goto P_0c047160;
P_0c047160: /* original 0425, guest PC 0x0c047160 */
if(!s->budget--) { s->failed_pc=0x0c047160u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c047162;
P_0c047162: /* original e044, guest PC 0x0c047162 */
if(!s->budget--) { s->failed_pc=0x0c047162u; return 0; }
r[0]=0x00000044u;
goto P_0c047164;
P_0c047164: /* original 0436, guest PC 0x0c047164 */
if(!s->budget--) { s->failed_pc=0x0c047164u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c047166;
P_0c047166: /* original e048, guest PC 0x0c047166 */
if(!s->budget--) { s->failed_pc=0x0c047166u; return 0; }
r[0]=0x00000048u;
goto P_0c047168;
P_0c047168: /* original 924d, guest PC 0x0c047168 */
if(!s->budget--) { s->failed_pc=0x0c047168u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c047206u,2);
goto P_0c04716a;
P_0c04716a: /* original 362c, guest PC 0x0c04716a */
if(!s->budget--) { s->failed_pc=0x0c04716au; return 0; }
r[6]+=r[2];
goto P_0c04716c;
P_0c04716c: /* original 0466, guest PC 0x0c04716c */
if(!s->budget--) { s->failed_pc=0x0c04716cu; return 0; }
write(ram,r[4]+r[0],r[6],4);
goto P_0c04716e;
P_0c04716e: /* original e044, guest PC 0x0c04716e */
if(!s->budget--) { s->failed_pc=0x0c04716eu; return 0; }
r[0]=0x00000044u;
goto P_0c047170;
P_0c047170: /* original 03ed, guest PC 0x0c047170 */
if(!s->budget--) { s->failed_pc=0x0c047170u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c047172;
P_0c047172: /* original e054, guest PC 0x0c047172 */
if(!s->budget--) { s->failed_pc=0x0c047172u; return 0; }
r[0]=0x00000054u;
goto P_0c047174;
P_0c047174: /* original 0435, guest PC 0x0c047174 */
if(!s->budget--) { s->failed_pc=0x0c047174u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c047176;
P_0c047176: /* original e044, guest PC 0x0c047176 */
if(!s->budget--) { s->failed_pc=0x0c047176u; return 0; }
r[0]=0x00000044u;
goto P_0c047178;
P_0c047178: /* original 01ed, guest PC 0x0c047178 */
if(!s->budget--) { s->failed_pc=0x0c047178u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c04717a;
P_0c04717a: /* original 2118, guest PC 0x0c04717a */
if(!s->budget--) { s->failed_pc=0x0c04717au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c04717c;
P_0c04717c: /* original 8f03, guest PC 0x0c04717c */
if(!s->budget--) { s->failed_pc=0x0c04717cu; return 0; }
cond=r[17]&1u;
r[6]+=r[10];
if(!cond) { goto P_0c047186; }
goto P_0c047180;
P_0c04717e: /* original 36ac, guest PC 0x0c04717e */
if(!s->budget--) { s->failed_pc=0x0c04717eu; return 0; }
r[6]+=r[10];
goto P_0c047180;
P_0c047180: /* original e050, guest PC 0x0c047180 */
if(!s->budget--) { s->failed_pc=0x0c047180u; return 0; }
r[0]=0x00000050u;
goto P_0c047182;
P_0c047182: /* original a003, guest PC 0x0c047182 */
if(!s->budget--) { s->failed_pc=0x0c047182u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c04718c;
P_0c047184: /* original 0456, guest PC 0x0c047184 */
if(!s->budget--) { s->failed_pc=0x0c047184u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c047186;
P_0c047186: /* original e050, guest PC 0x0c047186 */
if(!s->budget--) { s->failed_pc=0x0c047186u; return 0; }
r[0]=0x00000050u;
goto P_0c047188;
P_0c047188: /* original 0466, guest PC 0x0c047188 */
if(!s->budget--) { s->failed_pc=0x0c047188u; return 0; }
write(ram,r[4]+r[0],r[6],4);
goto P_0c04718a;
P_0c04718a: /* original 36bc, guest PC 0x0c04718a */
if(!s->budget--) { s->failed_pc=0x0c04718au; return 0; }
r[6]+=r[11];
goto P_0c04718c;
P_0c04718c: /* original e048, guest PC 0x0c04718c */
if(!s->budget--) { s->failed_pc=0x0c04718cu; return 0; }
r[0]=0x00000048u;
goto P_0c04718e;
P_0c04718e: /* original 03ee, guest PC 0x0c04718e */
if(!s->budget--) { s->failed_pc=0x0c04718eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c047190;
P_0c047190: /* original e05c, guest PC 0x0c047190 */
if(!s->budget--) { s->failed_pc=0x0c047190u; return 0; }
r[0]=0x0000005cu;
goto P_0c047192;
P_0c047192: /* original 0436, guest PC 0x0c047192 */
if(!s->budget--) { s->failed_pc=0x0c047192u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c047194;
P_0c047194: /* original e048, guest PC 0x0c047194 */
if(!s->budget--) { s->failed_pc=0x0c047194u; return 0; }
r[0]=0x00000048u;
goto P_0c047196;
P_0c047196: /* original 02ee, guest PC 0x0c047196 */
if(!s->budget--) { s->failed_pc=0x0c047196u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c047198;
P_0c047198: /* original 2228, guest PC 0x0c047198 */
if(!s->budget--) { s->failed_pc=0x0c047198u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04719a;
P_0c04719a: /* original 8b02, guest PC 0x0c04719a */
if(!s->budget--) { s->failed_pc=0x0c04719au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0471a2; }
goto P_0c04719c;
P_0c04719c: /* original e058, guest PC 0x0c04719c */
if(!s->budget--) { s->failed_pc=0x0c04719cu; return 0; }
r[0]=0x00000058u;
goto P_0c04719e;
P_0c04719e: /* original a002, guest PC 0x0c04719e */
if(!s->budget--) { s->failed_pc=0x0c04719eu; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c0471a6;
P_0c0471a0: /* original 0456, guest PC 0x0c0471a0 */
if(!s->budget--) { s->failed_pc=0x0c0471a0u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c0471a2;
P_0c0471a2: /* original e058, guest PC 0x0c0471a2 */
if(!s->budget--) { s->failed_pc=0x0c0471a2u; return 0; }
r[0]=0x00000058u;
goto P_0c0471a4;
P_0c0471a4: /* original 0466, guest PC 0x0c0471a4 */
if(!s->budget--) { s->failed_pc=0x0c0471a4u; return 0; }
write(ram,r[4]+r[0],r[6],4);
goto P_0c0471a6;
P_0c0471a6: /* original e046, guest PC 0x0c0471a6 */
if(!s->budget--) { s->failed_pc=0x0c0471a6u; return 0; }
r[0]=0x00000046u;
goto P_0c0471a8;
P_0c0471a8: /* original 0ced, guest PC 0x0c0471a8 */
if(!s->budget--) { s->failed_pc=0x0c0471a8u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0471aa;
P_0c0471aa: /* original 0e55, guest PC 0x0c0471aa */
if(!s->budget--) { s->failed_pc=0x0c0471aau; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0471ac;
P_0c0471ac: /* original 65f2, guest PC 0x0c0471ac */
if(!s->budget--) { s->failed_pc=0x0c0471acu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0471ae;
P_0c0471ae: /* original b013, guest PC 0x0c0471ae */
if(!s->budget--) { s->failed_pc=0x0c0471aeu; return 0; }
target=code_base|0x0c0471d8u; r[16]=code_base|0x0c0471b2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0471b2u) { target=s->pc; goto dispatch; }
goto P_0c0471b2;
P_0c0471b0: /* original 64d3, guest PC 0x0c0471b0 */
if(!s->budget--) { s->failed_pc=0x0c0471b0u; return 0; }
r[4]=r[13];
goto P_0c0471b2;
P_0c0471b2: /* original 6403, guest PC 0x0c0471b2 */
if(!s->budget--) { s->failed_pc=0x0c0471b2u; return 0; }
r[4]=r[0];
goto P_0c0471b4;
P_0c0471b4: /* original e046, guest PC 0x0c0471b4 */
if(!s->budget--) { s->failed_pc=0x0c0471b4u; return 0; }
r[0]=0x00000046u;
goto P_0c0471b6;
P_0c0471b6: /* original 0ec5, guest PC 0x0c0471b6 */
if(!s->budget--) { s->failed_pc=0x0c0471b6u; return 0; }
write(ram,r[14]+r[0],r[12],2);
goto P_0c0471b8;
P_0c0471b8: /* original 6ccd, guest PC 0x0c0471b8 */
if(!s->budget--) { s->failed_pc=0x0c0471b8u; return 0; }
r[12]=r[12]&65535u;
goto P_0c0471ba;
P_0c0471ba: /* original 644d, guest PC 0x0c0471ba */
if(!s->budget--) { s->failed_pc=0x0c0471bau; return 0; }
r[4]=r[4]&65535u;
goto P_0c0471bc;
P_0c0471bc: /* original 34c0, guest PC 0x0c0471bc */
if(!s->budget--) { s->failed_pc=0x0c0471bcu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[12])!=0);
goto P_0c0471be;
P_0c0471be: /* original 8902, guest PC 0x0c0471be */
if(!s->budget--) { s->failed_pc=0x0c0471beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0471c6; }
goto P_0c0471c0;
P_0c0471c0: /* original 9022, guest PC 0x0c0471c0 */
if(!s->budget--) { s->failed_pc=0x0c0471c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c047208u,2);
goto P_0c0471c2;
P_0c0471c2: /* original a001, guest PC 0x0c0471c2 */
if(!s->budget--) { s->failed_pc=0x0c0471c2u; return 0; }
goto P_0c0471c8;
P_0c0471c4: /* original 0009, guest PC 0x0c0471c4 */
if(!s->budget--) { s->failed_pc=0x0c0471c4u; return 0; }
goto P_0c0471c6;
P_0c0471c6: /* original e000, guest PC 0x0c0471c6 */
if(!s->budget--) { s->failed_pc=0x0c0471c6u; return 0; }
r[0]=0x00000000u;
goto P_0c0471c8;
P_0c0471c8: /* original 7f04, guest PC 0x0c0471c8 */
if(!s->budget--) { s->failed_pc=0x0c0471c8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0471ca;
P_0c0471ca: /* original 4f26, guest PC 0x0c0471ca */
if(!s->budget--) { s->failed_pc=0x0c0471cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0471cc;
P_0c0471cc: /* original 6af6, guest PC 0x0c0471cc */
if(!s->budget--) { s->failed_pc=0x0c0471ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0471ce;
P_0c0471ce: /* original 6bf6, guest PC 0x0c0471ce */
if(!s->budget--) { s->failed_pc=0x0c0471ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0471d0;
P_0c0471d0: /* original 6cf6, guest PC 0x0c0471d0 */
if(!s->budget--) { s->failed_pc=0x0c0471d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0471d2;
P_0c0471d2: /* original 6df6, guest PC 0x0c0471d2 */
if(!s->budget--) { s->failed_pc=0x0c0471d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0471d4;
P_0c0471d4: /* original 000b, guest PC 0x0c0471d4 */
if(!s->budget--) { s->failed_pc=0x0c0471d4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0471d6: /* original 6ef6, guest PC 0x0c0471d6 */
if(!s->budget--) { s->failed_pc=0x0c0471d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0471d8;
P_0c0471d8: /* original 2fc6, guest PC 0x0c0471d8 */
if(!s->budget--) { s->failed_pc=0x0c0471d8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0471da;
P_0c0471da: /* original e600, guest PC 0x0c0471da */
if(!s->budget--) { s->failed_pc=0x0c0471dau; return 0; }
r[6]=0x00000000u;
goto P_0c0471dc;
P_0c0471dc: /* original 2fb6, guest PC 0x0c0471dc */
if(!s->budget--) { s->failed_pc=0x0c0471dcu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0471de;
P_0c0471de: /* original eb08, guest PC 0x0c0471de */
if(!s->budget--) { s->failed_pc=0x0c0471deu; return 0; }
r[11]=0x00000008u;
goto P_0c0471e0;
P_0c0471e0: /* original 2fa6, guest PC 0x0c0471e0 */
if(!s->budget--) { s->failed_pc=0x0c0471e0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0471e2;
P_0c0471e2: /* original 6a43, guest PC 0x0c0471e2 */
if(!s->budget--) { s->failed_pc=0x0c0471e2u; return 0; }
r[10]=r[4];
goto P_0c0471e4;
P_0c0471e4: /* original 9111, guest PC 0x0c0471e4 */
if(!s->budget--) { s->failed_pc=0x0c0471e4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04720au,2);
goto P_0c0471e6;
P_0c0471e6: /* original 6463, guest PC 0x0c0471e6 */
if(!s->budget--) { s->failed_pc=0x0c0471e6u; return 0; }
r[4]=r[6];
goto P_0c0471e8;
P_0c0471e8: /* original d00a, guest PC 0x0c0471e8 */
if(!s->budget--) { s->failed_pc=0x0c0471e8u; return 0; }
r[0]=read(ram,0x0c047214u,4);
goto P_0c0471ea;
P_0c0471ea: /* original a019, guest PC 0x0c0471ea */
if(!s->budget--) { s->failed_pc=0x0c0471eau; return 0; }
r[12]=r[6];
goto P_0c047220;
P_0c0471ec: /* original 6c63, guest PC 0x0c0471ec */
if(!s->budget--) { s->failed_pc=0x0c0471ecu; return 0; }
r[12]=r[6];
goto P_0c0471ee;
P_0c0471ee: /* original 63a4, guest PC 0x0c0471ee */
if(!s->budget--) { s->failed_pc=0x0c0471eeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[10],1);
r[10]+=1;
r[3]=tmp;
goto P_0c0471f0;
P_0c0471f0: /* original 67b3, guest PC 0x0c0471f0 */
if(!s->budget--) { s->failed_pc=0x0c0471f0u; return 0; }
r[7]=r[11];
goto P_0c0471f2;
P_0c0471f2: /* original 4318, guest PC 0x0c0471f2 */
if(!s->budget--) { s->failed_pc=0x0c0471f2u; return 0; }
r[3]<<=8;
goto P_0c0471f4;
P_0c0471f4: /* original 243a, guest PC 0x0c0471f4 */
if(!s->budget--) { s->failed_pc=0x0c0471f4u; return 0; }
r[4]^=r[3];
goto P_0c0471f6;
P_0c0471f6: /* original 6243, guest PC 0x0c0471f6 */
if(!s->budget--) { s->failed_pc=0x0c0471f6u; return 0; }
r[2]=r[4];
goto P_0c0471f8;
P_0c0471f8: /* original 6643, guest PC 0x0c0471f8 */
if(!s->budget--) { s->failed_pc=0x0c0471f8u; return 0; }
r[6]=r[4];
goto P_0c0471fa;
P_0c0471fa: /* original 4600, guest PC 0x0c0471fa */
if(!s->budget--) { s->failed_pc=0x0c0471fau; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0471fc;
P_0c0471fc: /* original 2208, guest PC 0x0c0471fc */
if(!s->budget--) { s->failed_pc=0x0c0471fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[0])==0)!=0);
goto P_0c0471fe;
P_0c0471fe: /* original 890b, guest PC 0x0c0471fe */
if(!s->budget--) { s->failed_pc=0x0c0471feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c047218; }
goto P_0c047200;
P_0c047200: /* original 6463, guest PC 0x0c047200 */
if(!s->budget--) { s->failed_pc=0x0c047200u; return 0; }
r[4]=r[6];
goto P_0c047202;
P_0c047202: /* original a00a, guest PC 0x0c047202 */
if(!s->budget--) { s->failed_pc=0x0c047202u; return 0; }
r[4]^=r[1];
goto P_0c04721a;
P_0c047204: /* original 241a, guest PC 0x0c047204 */
if(!s->budget--) { s->failed_pc=0x0c047204u; return 0; }
r[4]^=r[1];
if(!vf3_matrix_family(0x0c047206u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c047206u; return 0; } return 1;
P_0c047218: /* original 6463, guest PC 0x0c047218 */
if(!s->budget--) { s->failed_pc=0x0c047218u; return 0; }
r[4]=r[6];
goto P_0c04721a;
P_0c04721a: /* original 4710, guest PC 0x0c04721a */
if(!s->budget--) { s->failed_pc=0x0c04721au; return 0; }
--r[7];
r[17]=(r[17]&~1u)|((r[7]==0)!=0);
goto P_0c04721c;
P_0c04721c: /* original 8beb, guest PC 0x0c04721c */
if(!s->budget--) { s->failed_pc=0x0c04721cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0471f6; }
goto P_0c04721e;
P_0c04721e: /* original 7c01, guest PC 0x0c04721e */
if(!s->budget--) { s->failed_pc=0x0c04721eu; return 0; }
r[12]+=0x00000001u;
goto P_0c047220;
P_0c047220: /* original 3c52, guest PC 0x0c047220 */
if(!s->budget--) { s->failed_pc=0x0c047220u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>=r[5])!=0);
goto P_0c047222;
P_0c047222: /* original 8be4, guest PC 0x0c047222 */
if(!s->budget--) { s->failed_pc=0x0c047222u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0471ee; }
goto P_0c047224;
P_0c047224: /* original 6af6, guest PC 0x0c047224 */
if(!s->budget--) { s->failed_pc=0x0c047224u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c047226;
P_0c047226: /* original 6043, guest PC 0x0c047226 */
if(!s->budget--) { s->failed_pc=0x0c047226u; return 0; }
r[0]=r[4];
goto P_0c047228;
P_0c047228: /* original 6bf6, guest PC 0x0c047228 */
if(!s->budget--) { s->failed_pc=0x0c047228u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04722a;
P_0c04722a: /* original 000b, guest PC 0x0c04722a */
if(!s->budget--) { s->failed_pc=0x0c04722au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
s->pc=target; return ram->oob==0;
P_0c04722c: /* original 6cf6, guest PC 0x0c04722c */
if(!s->budget--) { s->failed_pc=0x0c04722cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
if(!vf3_matrix_family(0x0c04722eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04722eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
