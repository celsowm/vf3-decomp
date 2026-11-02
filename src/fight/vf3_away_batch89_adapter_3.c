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
int vf3_away_batch89_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09571cu: goto P_0c09571c;
case 0x0c09571eu: goto P_0c09571e;
case 0x0c095720u: goto P_0c095720;
case 0x0c095722u: goto P_0c095722;
case 0x0c0a2b98u: goto P_0c0a2b98;
case 0x0c0a2b9au: goto P_0c0a2b9a;
case 0x0c0a2b9cu: goto P_0c0a2b9c;
case 0x0c0a2b9eu: goto P_0c0a2b9e;
case 0x0c0a2ba0u: goto P_0c0a2ba0;
case 0x0c0a2ba2u: goto P_0c0a2ba2;
case 0x0c0a2ba4u: goto P_0c0a2ba4;
case 0x0c0a2ba6u: goto P_0c0a2ba6;
case 0x0c0a2ba8u: goto P_0c0a2ba8;
case 0x0c0a2baau: goto P_0c0a2baa;
case 0x0c0a2bacu: goto P_0c0a2bac;
case 0x0c0a2baeu: goto P_0c0a2bae;
case 0x0c0a2bb0u: goto P_0c0a2bb0;
case 0x0c0a2bb2u: goto P_0c0a2bb2;
case 0x0c0a2bb4u: goto P_0c0a2bb4;
case 0x0c0a2bb6u: goto P_0c0a2bb6;
case 0x0c0a2bb8u: goto P_0c0a2bb8;
case 0x0c0a2bbau: goto P_0c0a2bba;
case 0x0c0a2bbcu: goto P_0c0a2bbc;
case 0x0c0a2bbeu: goto P_0c0a2bbe;
case 0x0c0a2bc0u: goto P_0c0a2bc0;
case 0x0c0a2bc2u: goto P_0c0a2bc2;
case 0x0c0a2bc4u: goto P_0c0a2bc4;
case 0x0c0a2bc6u: goto P_0c0a2bc6;
case 0x0c0a2bc8u: goto P_0c0a2bc8;
case 0x0c0a2bcau: goto P_0c0a2bca;
case 0x0c0a2bccu: goto P_0c0a2bcc;
case 0x0c0a2bceu: goto P_0c0a2bce;
case 0x0c0a2bd0u: goto P_0c0a2bd0;
case 0x0c0a2bd2u: goto P_0c0a2bd2;
case 0x0c0a2bd4u: goto P_0c0a2bd4;
case 0x0c0a2bd6u: goto P_0c0a2bd6;
case 0x0c0a2bd8u: goto P_0c0a2bd8;
case 0x0c0a2bdau: goto P_0c0a2bda;
case 0x0c0a2bdcu: goto P_0c0a2bdc;
case 0x0c0a2bdeu: goto P_0c0a2bde;
case 0x0c0a2be0u: goto P_0c0a2be0;
case 0x0c0a2be2u: goto P_0c0a2be2;
case 0x0c0a2be4u: goto P_0c0a2be4;
case 0x0c0a2be6u: goto P_0c0a2be6;
case 0x0c0a2be8u: goto P_0c0a2be8;
case 0x0c0a2beau: goto P_0c0a2bea;
case 0x0c0a2becu: goto P_0c0a2bec;
case 0x0c0a2beeu: goto P_0c0a2bee;
case 0x0c0a2bf0u: goto P_0c0a2bf0;
case 0x0c0a2bf2u: goto P_0c0a2bf2;
case 0x0c0a2bf4u: goto P_0c0a2bf4;
case 0x0c0a2bf6u: goto P_0c0a2bf6;
case 0x0c0a2bf8u: goto P_0c0a2bf8;
case 0x0c0a2bfau: goto P_0c0a2bfa;
case 0x0c0a2bfcu: goto P_0c0a2bfc;
case 0x0c0a2bfeu: goto P_0c0a2bfe;
case 0x0c0a2c00u: goto P_0c0a2c00;
case 0x0c0a2c02u: goto P_0c0a2c02;
case 0x0c0a2c04u: goto P_0c0a2c04;
case 0x0c0a2c06u: goto P_0c0a2c06;
case 0x0c0a2c08u: goto P_0c0a2c08;
case 0x0c0a2c0au: goto P_0c0a2c0a;
case 0x0c0a2c0cu: goto P_0c0a2c0c;
case 0x0c0a2c0eu: goto P_0c0a2c0e;
case 0x0c0a2c10u: goto P_0c0a2c10;
case 0x0c0a2c12u: goto P_0c0a2c12;
case 0x0c0a2c14u: goto P_0c0a2c14;
case 0x0c0a2c16u: goto P_0c0a2c16;
case 0x0c0a2c18u: goto P_0c0a2c18;
case 0x0c0a2c1au: goto P_0c0a2c1a;
case 0x0c0a2c1cu: goto P_0c0a2c1c;
case 0x0c0a2c1eu: goto P_0c0a2c1e;
case 0x0c0a2c20u: goto P_0c0a2c20;
case 0x0c0a2c22u: goto P_0c0a2c22;
case 0x0c0a2c24u: goto P_0c0a2c24;
case 0x0c0a2c26u: goto P_0c0a2c26;
case 0x0c0a2c28u: goto P_0c0a2c28;
case 0x0c0a2c2au: goto P_0c0a2c2a;
case 0x0c0a2c2cu: goto P_0c0a2c2c;
case 0x0c0a2c2eu: goto P_0c0a2c2e;
case 0x0c0a2c30u: goto P_0c0a2c30;
case 0x0c0a2c32u: goto P_0c0a2c32;
case 0x0c0a2c34u: goto P_0c0a2c34;
case 0x0c0a7600u: goto P_0c0a7600;
case 0x0c0a7602u: goto P_0c0a7602;
case 0x0c0a7604u: goto P_0c0a7604;
case 0x0c0a7606u: goto P_0c0a7606;
case 0x0c0a7608u: goto P_0c0a7608;
case 0x0c0a760au: goto P_0c0a760a;
case 0x0c0a760cu: goto P_0c0a760c;
case 0x0c0a760eu: goto P_0c0a760e;
case 0x0c0a7610u: goto P_0c0a7610;
case 0x0c0a7612u: goto P_0c0a7612;
case 0x0c0a7614u: goto P_0c0a7614;
case 0x0c0a7616u: goto P_0c0a7616;
case 0x0c0a7618u: goto P_0c0a7618;
case 0x0c0a761au: goto P_0c0a761a;
case 0x0c0a761cu: goto P_0c0a761c;
case 0x0c0a761eu: goto P_0c0a761e;
case 0x0c0a7620u: goto P_0c0a7620;
case 0x0c0a7622u: goto P_0c0a7622;
case 0x0c0a7624u: goto P_0c0a7624;
case 0x0c0a7626u: goto P_0c0a7626;
case 0x0c0a7628u: goto P_0c0a7628;
case 0x0c0a762au: goto P_0c0a762a;
case 0x0c0a762cu: goto P_0c0a762c;
case 0x0c0a762eu: goto P_0c0a762e;
case 0x0c0a7630u: goto P_0c0a7630;
case 0x0c0a7632u: goto P_0c0a7632;
case 0x0c0a7634u: goto P_0c0a7634;
case 0x0c0a7636u: goto P_0c0a7636;
case 0x0c0a7638u: goto P_0c0a7638;
case 0x0c0a763au: goto P_0c0a763a;
case 0x0c0a763cu: goto P_0c0a763c;
case 0x0c0a763eu: goto P_0c0a763e;
case 0x0c0a7640u: goto P_0c0a7640;
case 0x0c0a7642u: goto P_0c0a7642;
case 0x0c0a7644u: goto P_0c0a7644;
case 0x0c0a7646u: goto P_0c0a7646;
case 0x0c0a7648u: goto P_0c0a7648;
case 0x0c0a764au: goto P_0c0a764a;
case 0x0c0a764cu: goto P_0c0a764c;
case 0x0c0a764eu: goto P_0c0a764e;
case 0x0c0a7650u: goto P_0c0a7650;
case 0x0c0a7652u: goto P_0c0a7652;
case 0x0c0a7654u: goto P_0c0a7654;
case 0x0c0a7656u: goto P_0c0a7656;
case 0x0c0a7658u: goto P_0c0a7658;
case 0x0c0a765au: goto P_0c0a765a;
case 0x0c0a765cu: goto P_0c0a765c;
case 0x0c0a765eu: goto P_0c0a765e;
case 0x0c0a7660u: goto P_0c0a7660;
case 0x0c0a7662u: goto P_0c0a7662;
case 0x0c0a7664u: goto P_0c0a7664;
case 0x0c0a7666u: goto P_0c0a7666;
case 0x0c0a7668u: goto P_0c0a7668;
case 0x0c0a766au: goto P_0c0a766a;
case 0x0c0a766cu: goto P_0c0a766c;
case 0x0c0a766eu: goto P_0c0a766e;
case 0x0c0a7670u: goto P_0c0a7670;
case 0x0c0a7672u: goto P_0c0a7672;
case 0x0c0a7674u: goto P_0c0a7674;
case 0x0c0a7676u: goto P_0c0a7676;
case 0x0c0a7678u: goto P_0c0a7678;
case 0x0c0a767au: goto P_0c0a767a;
case 0x0c0a767cu: goto P_0c0a767c;
case 0x0c0a767eu: goto P_0c0a767e;
case 0x0c0a7680u: goto P_0c0a7680;
case 0x0c0a7682u: goto P_0c0a7682;
case 0x0c0a7684u: goto P_0c0a7684;
case 0x0c0a7686u: goto P_0c0a7686;
case 0x0c0a7688u: goto P_0c0a7688;
case 0x0c0a768au: goto P_0c0a768a;
case 0x0c0a768cu: goto P_0c0a768c;
case 0x0c0a768eu: goto P_0c0a768e;
case 0x0c0a7690u: goto P_0c0a7690;
case 0x0c0a7692u: goto P_0c0a7692;
case 0x0c0a7694u: goto P_0c0a7694;
case 0x0c0a7696u: goto P_0c0a7696;
case 0x0c0a7698u: goto P_0c0a7698;
case 0x0c0a769au: goto P_0c0a769a;
case 0x0c0a769cu: goto P_0c0a769c;
case 0x0c0a769eu: goto P_0c0a769e;
case 0x0c0a76a0u: goto P_0c0a76a0;
case 0x0c0a76a2u: goto P_0c0a76a2;
case 0x0c0a76a4u: goto P_0c0a76a4;
case 0x0c0a76a6u: goto P_0c0a76a6;
case 0x0c0a76a8u: goto P_0c0a76a8;
case 0x0c0a76aau: goto P_0c0a76aa;
case 0x0c0a76acu: goto P_0c0a76ac;
case 0x0c0a76aeu: goto P_0c0a76ae;
case 0x0c0a76b0u: goto P_0c0a76b0;
case 0x0c0a76b2u: goto P_0c0a76b2;
case 0x0c0a76b4u: goto P_0c0a76b4;
case 0x0c0a76b6u: goto P_0c0a76b6;
case 0x0c0a76b8u: goto P_0c0a76b8;
case 0x0c0a76bau: goto P_0c0a76ba;
case 0x0c0a76bcu: goto P_0c0a76bc;
case 0x0c0a76ecu: goto P_0c0a76ec;
case 0x0c0a76eeu: goto P_0c0a76ee;
case 0x0c0a76f0u: goto P_0c0a76f0;
case 0x0c0a76f2u: goto P_0c0a76f2;
case 0x0c0a76f4u: goto P_0c0a76f4;
case 0x0c0a76f6u: goto P_0c0a76f6;
case 0x0c0a76f8u: goto P_0c0a76f8;
case 0x0c0a76fau: goto P_0c0a76fa;
case 0x0c0a76fcu: goto P_0c0a76fc;
case 0x0c0a76feu: goto P_0c0a76fe;
case 0x0c0a7700u: goto P_0c0a7700;
case 0x0c0a7702u: goto P_0c0a7702;
case 0x0c0a7704u: goto P_0c0a7704;
case 0x0c0a7706u: goto P_0c0a7706;
case 0x0c0a7708u: goto P_0c0a7708;
case 0x0c0a770au: goto P_0c0a770a;
case 0x0c0a770cu: goto P_0c0a770c;
case 0x0c0a770eu: goto P_0c0a770e;
case 0x0c0a7710u: goto P_0c0a7710;
case 0x0c0a7712u: goto P_0c0a7712;
case 0x0c0a7714u: goto P_0c0a7714;
case 0x0c0a7716u: goto P_0c0a7716;
case 0x0c0a7718u: goto P_0c0a7718;
case 0x0c0a771au: goto P_0c0a771a;
case 0x0c0a771cu: goto P_0c0a771c;
case 0x0c0a771eu: goto P_0c0a771e;
case 0x0c0a7720u: goto P_0c0a7720;
case 0x0c0a7722u: goto P_0c0a7722;
case 0x0c0a7724u: goto P_0c0a7724;
case 0x0c0a7726u: goto P_0c0a7726;
case 0x0c0a7728u: goto P_0c0a7728;
case 0x0c0a772au: goto P_0c0a772a;
case 0x0c0a772cu: goto P_0c0a772c;
case 0x0c0a772eu: goto P_0c0a772e;
case 0x0c0a7730u: goto P_0c0a7730;
case 0x0c0a7732u: goto P_0c0a7732;
case 0x0c0a7734u: goto P_0c0a7734;
case 0x0c0a7736u: goto P_0c0a7736;
case 0x0c0a7738u: goto P_0c0a7738;
case 0x0c0a773au: goto P_0c0a773a;
case 0x0c0a773cu: goto P_0c0a773c;
case 0x0c0a773eu: goto P_0c0a773e;
case 0x0c0a7740u: goto P_0c0a7740;
case 0x0c0a7742u: goto P_0c0a7742;
case 0x0c0a7744u: goto P_0c0a7744;
case 0x0c0a7746u: goto P_0c0a7746;
case 0x0c0a7748u: goto P_0c0a7748;
case 0x0c0a774au: goto P_0c0a774a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09571c: /* original d21c, guest PC 0x0c09571c */
if(!s->budget--) { s->failed_pc=0x0c09571cu; return 0; }
r[2]=read(ram,0x0c095790u,4);
goto P_0c09571e;
P_0c09571e: /* original 6322, guest PC 0x0c09571e */
if(!s->budget--) { s->failed_pc=0x0c09571eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c095720;
P_0c095720: /* original 432b, guest PC 0x0c095720 */
if(!s->budget--) { s->failed_pc=0x0c095720u; return 0; }
target=r[3];
r[4]=0x00000001u;
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
P_0c095722: /* original e401, guest PC 0x0c095722 */
if(!s->budget--) { s->failed_pc=0x0c095722u; return 0; }
r[4]=0x00000001u;
if(!vf3_matrix_family(0x0c095724u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095724u; return 0; } return 1;
P_0c0a2b98: /* original 2fe6, guest PC 0x0c0a2b98 */
if(!s->budget--) { s->failed_pc=0x0c0a2b98u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2b9a;
P_0c0a2b9a: /* original 6e43, guest PC 0x0c0a2b9a */
if(!s->budget--) { s->failed_pc=0x0c0a2b9au; return 0; }
r[14]=r[4];
goto P_0c0a2b9c;
P_0c0a2b9c: /* original 2fd6, guest PC 0x0c0a2b9c */
if(!s->budget--) { s->failed_pc=0x0c0a2b9cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2b9e;
P_0c0a2b9e: /* original 2fc6, guest PC 0x0c0a2b9e */
if(!s->budget--) { s->failed_pc=0x0c0a2b9eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba0;
P_0c0a2ba0: /* original 2fb6, guest PC 0x0c0a2ba0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba2;
P_0c0a2ba2: /* original 2fa6, guest PC 0x0c0a2ba2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba4;
P_0c0a2ba4: /* original 2f96, guest PC 0x0c0a2ba4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba4u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba6;
P_0c0a2ba6: /* original 2f86, guest PC 0x0c0a2ba6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba6u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba8;
P_0c0a2ba8: /* original 60e2, guest PC 0x0c0a2ba8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba8u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0a2baa;
P_0c0a2baa: /* original 4f22, guest PC 0x0c0a2baa */
if(!s->budget--) { s->failed_pc=0x0c0a2baau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2bac;
P_0c0a2bac: /* original c880, guest PC 0x0c0a2bac */
if(!s->budget--) { s->failed_pc=0x0c0a2bacu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0a2bae;
P_0c0a2bae: /* original 8938, guest PC 0x0c0a2bae */
if(!s->budget--) { s->failed_pc=0x0c0a2baeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2c22; }
goto P_0c0a2bb0;
P_0c0a2bb0: /* original 62e2, guest PC 0x0c0a2bb0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0a2bb2;
P_0c0a2bb2: /* original d33b, guest PC 0x0c0a2bb2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb2u; return 0; }
r[3]=read(ram,0x0c0a2ca0u,4);
goto P_0c0a2bb4;
P_0c0a2bb4: /* original 9173, guest PC 0x0c0a2bb4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2c9eu,2);
goto P_0c0a2bb6;
P_0c0a2bb6: /* original 2239, guest PC 0x0c0a2bb6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb6u; return 0; }
r[2]&=r[3];
goto P_0c0a2bb8;
P_0c0a2bb8: /* original 3210, guest PC 0x0c0a2bb8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c0a2bba;
P_0c0a2bba: /* original 8905, guest PC 0x0c0a2bba */
if(!s->budget--) { s->failed_pc=0x0c0a2bbau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2bc8; }
goto P_0c0a2bbc;
P_0c0a2bbc: /* original d239, guest PC 0x0c0a2bbc */
if(!s->budget--) { s->failed_pc=0x0c0a2bbcu; return 0; }
r[2]=read(ram,0x0c0a2ca4u,4);
goto P_0c0a2bbe;
P_0c0a2bbe: /* original e56a, guest PC 0x0c0a2bbe */
if(!s->budget--) { s->failed_pc=0x0c0a2bbeu; return 0; }
r[5]=0x0000006au;
goto P_0c0a2bc0;
P_0c0a2bc0: /* original 420b, guest PC 0x0c0a2bc0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2bc4u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2bc4u) { target=s->pc; goto dispatch; }
goto P_0c0a2bc4;
P_0c0a2bc2: /* original e401, guest PC 0x0c0a2bc2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc2u; return 0; }
r[4]=0x00000001u;
goto P_0c0a2bc4;
P_0c0a2bc4: /* original a02e, guest PC 0x0c0a2bc4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc4u; return 0; }
r[0]=0xffffffffu;
goto P_0c0a2c24;
P_0c0a2bc6: /* original e0ff, guest PC 0x0c0a2bc6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc6u; return 0; }
r[0]=0xffffffffu;
goto P_0c0a2bc8;
P_0c0a2bc8: /* original e020, guest PC 0x0c0a2bc8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc8u; return 0; }
r[0]=0x00000020u;
goto P_0c0a2bca;
P_0c0a2bca: /* original 03ed, guest PC 0x0c0a2bca */
if(!s->budget--) { s->failed_pc=0x0c0a2bcau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2bcc;
P_0c0a2bcc: /* original e022, guest PC 0x0c0a2bcc */
if(!s->budget--) { s->failed_pc=0x0c0a2bccu; return 0; }
r[0]=0x00000022u;
goto P_0c0a2bce;
P_0c0a2bce: /* original 02ed, guest PC 0x0c0a2bce */
if(!s->budget--) { s->failed_pc=0x0c0a2bceu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2bd0;
P_0c0a2bd0: /* original 633d, guest PC 0x0c0a2bd0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd0u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a2bd2;
P_0c0a2bd2: /* original 622d, guest PC 0x0c0a2bd2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd2u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0a2bd4;
P_0c0a2bd4: /* original 232b, guest PC 0x0c0a2bd4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd4u; return 0; }
r[3]|=r[2];
goto P_0c0a2bd6;
P_0c0a2bd6: /* original 2338, guest PC 0x0c0a2bd6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2bd8;
P_0c0a2bd8: /* original 8923, guest PC 0x0c0a2bd8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2c22; }
goto P_0c0a2bda;
P_0c0a2bda: /* original e020, guest PC 0x0c0a2bda */
if(!s->budget--) { s->failed_pc=0x0c0a2bdau; return 0; }
r[0]=0x00000020u;
goto P_0c0a2bdc;
P_0c0a2bdc: /* original d332, guest PC 0x0c0a2bdc */
if(!s->budget--) { s->failed_pc=0x0c0a2bdcu; return 0; }
r[3]=read(ram,0x0c0a2ca8u,4);
goto P_0c0a2bde;
P_0c0a2bde: /* original 04ed, guest PC 0x0c0a2bde */
if(!s->budget--) { s->failed_pc=0x0c0a2bdeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2be0;
P_0c0a2be0: /* original 430b, guest PC 0x0c0a2be0 */
if(!s->budget--) { s->failed_pc=0x0c0a2be0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2be4u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2be4u) { target=s->pc; goto dispatch; }
goto P_0c0a2be4;
P_0c0a2be2: /* original 644d, guest PC 0x0c0a2be2 */
if(!s->budget--) { s->failed_pc=0x0c0a2be2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a2be4;
P_0c0a2be4: /* original d932, guest PC 0x0c0a2be4 */
if(!s->budget--) { s->failed_pc=0x0c0a2be4u; return 0; }
r[9]=read(ram,0x0c0a2cb0u,4);
goto P_0c0a2be6;
P_0c0a2be6: /* original eb01, guest PC 0x0c0a2be6 */
if(!s->budget--) { s->failed_pc=0x0c0a2be6u; return 0; }
r[11]=0x00000001u;
goto P_0c0a2be8;
P_0c0a2be8: /* original d830, guest PC 0x0c0a2be8 */
if(!s->budget--) { s->failed_pc=0x0c0a2be8u; return 0; }
r[8]=read(ram,0x0c0a2cacu,4);
goto P_0c0a2bea;
P_0c0a2bea: /* original 5ae4, guest PC 0x0c0a2bea */
if(!s->budget--) { s->failed_pc=0x0c0a2beau; return 0; }
r[10]=read(ram,r[14]+16,4);
goto P_0c0a2bec;
P_0c0a2bec: /* original a010, guest PC 0x0c0a2bec */
if(!s->budget--) { s->failed_pc=0x0c0a2becu; return 0; }
r[12]=0x00000000u;
goto P_0c0a2c10;
P_0c0a2bee: /* original ec00, guest PC 0x0c0a2bee */
if(!s->budget--) { s->failed_pc=0x0c0a2beeu; return 0; }
r[12]=0x00000000u;
goto P_0c0a2bf0;
P_0c0a2bf0: /* original 6dc3, guest PC 0x0c0a2bf0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf0u; return 0; }
r[13]=r[12];
goto P_0c0a2bf2;
P_0c0a2bf2: /* original 4d08, guest PC 0x0c0a2bf2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf2u; return 0; }
r[13]<<=2;
goto P_0c0a2bf4;
P_0c0a2bf4: /* original 3dac, guest PC 0x0c0a2bf4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf4u; return 0; }
r[13]+=r[10];
goto P_0c0a2bf6;
P_0c0a2bf6: /* original 63d2, guest PC 0x0c0a2bf6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf6u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0a2bf8;
P_0c0a2bf8: /* original 5231, guest PC 0x0c0a2bf8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf8u; return 0; }
r[2]=read(ram,r[3]+4,4);
goto P_0c0a2bfa;
P_0c0a2bfa: /* original 22b8, guest PC 0x0c0a2bfa */
if(!s->budget--) { s->failed_pc=0x0c0a2bfau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[11])==0)!=0);
goto P_0c0a2bfc;
P_0c0a2bfc: /* original 8903, guest PC 0x0c0a2bfc */
if(!s->budget--) { s->failed_pc=0x0c0a2bfcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2c06; }
goto P_0c0a2bfe;
P_0c0a2bfe: /* original 480b, guest PC 0x0c0a2bfe */
if(!s->budget--) { s->failed_pc=0x0c0a2bfeu; return 0; }
target=r[8];
r[16]=code_base|0x0c0a2c02u;
tmp=read(ram,r[13],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2c02u) { target=s->pc; goto dispatch; }
goto P_0c0a2c02;
P_0c0a2c00: /* original 64d2, guest PC 0x0c0a2c00 */
if(!s->budget--) { s->failed_pc=0x0c0a2c00u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2c02;
P_0c0a2c02: /* original a004, guest PC 0x0c0a2c02 */
if(!s->budget--) { s->failed_pc=0x0c0a2c02u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2c0e;
P_0c0a2c04: /* original 2008, guest PC 0x0c0a2c04 */
if(!s->budget--) { s->failed_pc=0x0c0a2c04u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2c06;
P_0c0a2c06: /* original 64d2, guest PC 0x0c0a2c06 */
if(!s->budget--) { s->failed_pc=0x0c0a2c06u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2c08;
P_0c0a2c08: /* original 490b, guest PC 0x0c0a2c08 */
if(!s->budget--) { s->failed_pc=0x0c0a2c08u; return 0; }
target=r[9];
r[16]=code_base|0x0c0a2c0cu;
r[4]=read(ram,r[4]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2c0cu) { target=s->pc; goto dispatch; }
goto P_0c0a2c0c;
P_0c0a2c0a: /* original 5441, guest PC 0x0c0a2c0a */
if(!s->budget--) { s->failed_pc=0x0c0a2c0au; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0a2c0c;
P_0c0a2c0c: /* original 2008, guest PC 0x0c0a2c0c */
if(!s->budget--) { s->failed_pc=0x0c0a2c0cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2c0e;
P_0c0a2c0e: /* original 7c01, guest PC 0x0c0a2c0e */
if(!s->budget--) { s->failed_pc=0x0c0a2c0eu; return 0; }
r[12]+=0x00000001u;
goto P_0c0a2c10;
P_0c0a2c10: /* original 85e6, guest PC 0x0c0a2c10 */
if(!s->budget--) { s->failed_pc=0x0c0a2c10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c0a2c12;
P_0c0a2c12: /* original 600d, guest PC 0x0c0a2c12 */
if(!s->budget--) { s->failed_pc=0x0c0a2c12u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2c14;
P_0c0a2c14: /* original 3c03, guest PC 0x0c0a2c14 */
if(!s->budget--) { s->failed_pc=0x0c0a2c14u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[0])!=0);
goto P_0c0a2c16;
P_0c0a2c16: /* original 8beb, guest PC 0x0c0a2c16 */
if(!s->budget--) { s->failed_pc=0x0c0a2c16u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2bf0; }
goto P_0c0a2c18;
P_0c0a2c18: /* original e022, guest PC 0x0c0a2c18 */
if(!s->budget--) { s->failed_pc=0x0c0a2c18u; return 0; }
r[0]=0x00000022u;
goto P_0c0a2c1a;
P_0c0a2c1a: /* original e200, guest PC 0x0c0a2c1a */
if(!s->budget--) { s->failed_pc=0x0c0a2c1au; return 0; }
r[2]=0x00000000u;
goto P_0c0a2c1c;
P_0c0a2c1c: /* original 0e25, guest PC 0x0c0a2c1c */
if(!s->budget--) { s->failed_pc=0x0c0a2c1cu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0a2c1e;
P_0c0a2c1e: /* original e020, guest PC 0x0c0a2c1e */
if(!s->budget--) { s->failed_pc=0x0c0a2c1eu; return 0; }
r[0]=0x00000020u;
goto P_0c0a2c20;
P_0c0a2c20: /* original 0e25, guest PC 0x0c0a2c20 */
if(!s->budget--) { s->failed_pc=0x0c0a2c20u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0a2c22;
P_0c0a2c22: /* original e000, guest PC 0x0c0a2c22 */
if(!s->budget--) { s->failed_pc=0x0c0a2c22u; return 0; }
r[0]=0x00000000u;
goto P_0c0a2c24;
P_0c0a2c24: /* original 4f26, guest PC 0x0c0a2c24 */
if(!s->budget--) { s->failed_pc=0x0c0a2c24u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2c26;
P_0c0a2c26: /* original 68f6, guest PC 0x0c0a2c26 */
if(!s->budget--) { s->failed_pc=0x0c0a2c26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a2c28;
P_0c0a2c28: /* original 69f6, guest PC 0x0c0a2c28 */
if(!s->budget--) { s->failed_pc=0x0c0a2c28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a2c2a;
P_0c0a2c2a: /* original 6af6, guest PC 0x0c0a2c2a */
if(!s->budget--) { s->failed_pc=0x0c0a2c2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a2c2c;
P_0c0a2c2c: /* original 6bf6, guest PC 0x0c0a2c2c */
if(!s->budget--) { s->failed_pc=0x0c0a2c2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a2c2e;
P_0c0a2c2e: /* original 6cf6, guest PC 0x0c0a2c2e */
if(!s->budget--) { s->failed_pc=0x0c0a2c2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a2c30;
P_0c0a2c30: /* original 6df6, guest PC 0x0c0a2c30 */
if(!s->budget--) { s->failed_pc=0x0c0a2c30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2c32;
P_0c0a2c32: /* original 000b, guest PC 0x0c0a2c32 */
if(!s->budget--) { s->failed_pc=0x0c0a2c32u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2c34: /* original 6ef6, guest PC 0x0c0a2c34 */
if(!s->budget--) { s->failed_pc=0x0c0a2c34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a2c36u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2c36u; return 0; } return 1;
P_0c0a7600: /* original 2fe6, guest PC 0x0c0a7600 */
if(!s->budget--) { s->failed_pc=0x0c0a7600u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7602;
P_0c0a7602: /* original 4f22, guest PC 0x0c0a7602 */
if(!s->budget--) { s->failed_pc=0x0c0a7602u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7604;
P_0c0a7604: /* original 935b, guest PC 0x0c0a7604 */
if(!s->budget--) { s->failed_pc=0x0c0a7604u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a76beu,2);
goto P_0c0a7606;
P_0c0a7606: /* original 3433, guest PC 0x0c0a7606 */
if(!s->budget--) { s->failed_pc=0x0c0a7606u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0a7608;
P_0c0a7608: /* original 7ffc, guest PC 0x0c0a7608 */
if(!s->budget--) { s->failed_pc=0x0c0a7608u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a760a;
P_0c0a760a: /* original 8d26, guest PC 0x0c0a760a */
if(!s->budget--) { s->failed_pc=0x0c0a760au; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,4,r[15]);
if(cond) { goto P_0c0a765a; }
goto P_0c0a760e;
P_0c0a760c: /* original ff4a, guest PC 0x0c0a760c */
if(!s->budget--) { s->failed_pc=0x0c0a760cu; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c0a760e;
P_0c0a760e: /* original d02c, guest PC 0x0c0a760e */
if(!s->budget--) { s->failed_pc=0x0c0a760eu; return 0; }
r[0]=read(ram,0x0c0a76c0u,4);
goto P_0c0a7610;
P_0c0a7610: /* original 6e43, guest PC 0x0c0a7610 */
if(!s->budget--) { s->failed_pc=0x0c0a7610u; return 0; }
r[14]=r[4];
goto P_0c0a7612;
P_0c0a7612: /* original 4e08, guest PC 0x0c0a7612 */
if(!s->budget--) { s->failed_pc=0x0c0a7612u; return 0; }
r[14]<<=2;
goto P_0c0a7614;
P_0c0a7614: /* original 0eee, guest PC 0x0c0a7614 */
if(!s->budget--) { s->failed_pc=0x0c0a7614u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c0a7616;
P_0c0a7616: /* original 2ee8, guest PC 0x0c0a7616 */
if(!s->budget--) { s->failed_pc=0x0c0a7616u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a7618;
P_0c0a7618: /* original 891f, guest PC 0x0c0a7618 */
if(!s->budget--) { s->failed_pc=0x0c0a7618u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a765a; }
goto P_0c0a761a;
P_0c0a761a: /* original 60e3, guest PC 0x0c0a761a */
if(!s->budget--) { s->failed_pc=0x0c0a761au; return 0; }
r[0]=r[14];
goto P_0c0a761c;
P_0c0a761c: /* original 88ff, guest PC 0x0c0a761c */
if(!s->budget--) { s->failed_pc=0x0c0a761cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0a761e;
P_0c0a761e: /* original 891c, guest PC 0x0c0a761e */
if(!s->budget--) { s->failed_pc=0x0c0a761eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a765a; }
goto P_0c0a7620;
P_0c0a7620: /* original d328, guest PC 0x0c0a7620 */
if(!s->budget--) { s->failed_pc=0x0c0a7620u; return 0; }
r[3]=read(ram,0x0c0a76c4u,4);
goto P_0c0a7622;
P_0c0a7622: /* original 430b, guest PC 0x0c0a7622 */
if(!s->budget--) { s->failed_pc=0x0c0a7622u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7626u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7626u) { target=s->pc; goto dispatch; }
goto P_0c0a7626;
P_0c0a7624: /* original e400, guest PC 0x0c0a7624 */
if(!s->budget--) { s->failed_pc=0x0c0a7624u; return 0; }
r[4]=0x00000000u;
goto P_0c0a7626;
P_0c0a7626: /* original d229, guest PC 0x0c0a7626 */
if(!s->budget--) { s->failed_pc=0x0c0a7626u; return 0; }
r[2]=read(ram,0x0c0a76ccu,4);
goto P_0c0a7628;
P_0c0a7628: /* original d427, guest PC 0x0c0a7628 */
if(!s->budget--) { s->failed_pc=0x0c0a7628u; return 0; }
r[4]=read(ram,0x0c0a76c8u,4);
goto P_0c0a762a;
P_0c0a762a: /* original 420b, guest PC 0x0c0a762a */
if(!s->budget--) { s->failed_pc=0x0c0a762au; return 0; }
target=r[2];
r[16]=code_base|0x0c0a762eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a762eu) { target=s->pc; goto dispatch; }
goto P_0c0a762e;
P_0c0a762c: /* original 0009, guest PC 0x0c0a762c */
if(!s->budget--) { s->failed_pc=0x0c0a762cu; return 0; }
goto P_0c0a762e;
P_0c0a762e: /* original 50e1, guest PC 0x0c0a762e */
if(!s->budget--) { s->failed_pc=0x0c0a762eu; return 0; }
r[0]=read(ram,r[14]+4,4);
goto P_0c0a7630;
P_0c0a7630: /* original c801, guest PC 0x0c0a7630 */
if(!s->budget--) { s->failed_pc=0x0c0a7630u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a7632;
P_0c0a7632: /* original 8905, guest PC 0x0c0a7632 */
if(!s->budget--) { s->failed_pc=0x0c0a7632u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7640; }
goto P_0c0a7634;
P_0c0a7634: /* original d326, guest PC 0x0c0a7634 */
if(!s->budget--) { s->failed_pc=0x0c0a7634u; return 0; }
r[3]=read(ram,0x0c0a76d0u,4);
goto P_0c0a7636;
P_0c0a7636: /* original f4f8, guest PC 0x0c0a7636 */
if(!s->budget--) { s->failed_pc=0x0c0a7636u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0a7638;
P_0c0a7638: /* original 430b, guest PC 0x0c0a7638 */
if(!s->budget--) { s->failed_pc=0x0c0a7638u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a763cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a763cu) { target=s->pc; goto dispatch; }
goto P_0c0a763c;
P_0c0a763a: /* original 64e3, guest PC 0x0c0a763a */
if(!s->budget--) { s->failed_pc=0x0c0a763au; return 0; }
r[4]=r[14];
goto P_0c0a763c;
P_0c0a763c: /* original a007, guest PC 0x0c0a763c */
if(!s->budget--) { s->failed_pc=0x0c0a763cu; return 0; }
goto P_0c0a764e;
P_0c0a763e: /* original 0009, guest PC 0x0c0a763e */
if(!s->budget--) { s->failed_pc=0x0c0a763eu; return 0; }
goto P_0c0a7640;
P_0c0a7640: /* original d324, guest PC 0x0c0a7640 */
if(!s->budget--) { s->failed_pc=0x0c0a7640u; return 0; }
r[3]=read(ram,0x0c0a76d4u,4);
goto P_0c0a7642;
P_0c0a7642: /* original 430b, guest PC 0x0c0a7642 */
if(!s->budget--) { s->failed_pc=0x0c0a7642u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7646u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7646u) { target=s->pc; goto dispatch; }
goto P_0c0a7646;
P_0c0a7644: /* original 0009, guest PC 0x0c0a7644 */
if(!s->budget--) { s->failed_pc=0x0c0a7644u; return 0; }
goto P_0c0a7646;
P_0c0a7646: /* original d324, guest PC 0x0c0a7646 */
if(!s->budget--) { s->failed_pc=0x0c0a7646u; return 0; }
r[3]=read(ram,0x0c0a76d8u,4);
goto P_0c0a7648;
P_0c0a7648: /* original f4f8, guest PC 0x0c0a7648 */
if(!s->budget--) { s->failed_pc=0x0c0a7648u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0a764a;
P_0c0a764a: /* original 430b, guest PC 0x0c0a764a */
if(!s->budget--) { s->failed_pc=0x0c0a764au; return 0; }
target=r[3];
r[16]=code_base|0x0c0a764eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a764eu) { target=s->pc; goto dispatch; }
goto P_0c0a764e;
P_0c0a764c: /* original 64e3, guest PC 0x0c0a764c */
if(!s->budget--) { s->failed_pc=0x0c0a764cu; return 0; }
r[4]=r[14];
goto P_0c0a764e;
P_0c0a764e: /* original 7f04, guest PC 0x0c0a764e */
if(!s->budget--) { s->failed_pc=0x0c0a764eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0a7650;
P_0c0a7650: /* original d222, guest PC 0x0c0a7650 */
if(!s->budget--) { s->failed_pc=0x0c0a7650u; return 0; }
r[2]=read(ram,0x0c0a76dcu,4);
goto P_0c0a7652;
P_0c0a7652: /* original 4f26, guest PC 0x0c0a7652 */
if(!s->budget--) { s->failed_pc=0x0c0a7652u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7654;
P_0c0a7654: /* original e401, guest PC 0x0c0a7654 */
if(!s->budget--) { s->failed_pc=0x0c0a7654u; return 0; }
r[4]=0x00000001u;
goto P_0c0a7656;
P_0c0a7656: /* original 422b, guest PC 0x0c0a7656 */
if(!s->budget--) { s->failed_pc=0x0c0a7656u; return 0; }
target=r[2];
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
P_0c0a7658: /* original 6ef6, guest PC 0x0c0a7658 */
if(!s->budget--) { s->failed_pc=0x0c0a7658u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a765a;
P_0c0a765a: /* original 7f04, guest PC 0x0c0a765a */
if(!s->budget--) { s->failed_pc=0x0c0a765au; return 0; }
r[15]+=0x00000004u;
goto P_0c0a765c;
P_0c0a765c: /* original 4f26, guest PC 0x0c0a765c */
if(!s->budget--) { s->failed_pc=0x0c0a765cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a765e;
P_0c0a765e: /* original 000b, guest PC 0x0c0a765e */
if(!s->budget--) { s->failed_pc=0x0c0a765eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a7660: /* original 6ef6, guest PC 0x0c0a7660 */
if(!s->budget--) { s->failed_pc=0x0c0a7660u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a7662;
P_0c0a7662: /* original 2fe6, guest PC 0x0c0a7662 */
if(!s->budget--) { s->failed_pc=0x0c0a7662u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7664;
P_0c0a7664: /* original 932b, guest PC 0x0c0a7664 */
if(!s->budget--) { s->failed_pc=0x0c0a7664u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a76beu,2);
goto P_0c0a7666;
P_0c0a7666: /* original 4f22, guest PC 0x0c0a7666 */
if(!s->budget--) { s->failed_pc=0x0c0a7666u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7668;
P_0c0a7668: /* original 3433, guest PC 0x0c0a7668 */
if(!s->budget--) { s->failed_pc=0x0c0a7668u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0a766a;
P_0c0a766a: /* original 8925, guest PC 0x0c0a766a */
if(!s->budget--) { s->failed_pc=0x0c0a766au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a766c;
P_0c0a766c: /* original d014, guest PC 0x0c0a766c */
if(!s->budget--) { s->failed_pc=0x0c0a766cu; return 0; }
r[0]=read(ram,0x0c0a76c0u,4);
goto P_0c0a766e;
P_0c0a766e: /* original 6e43, guest PC 0x0c0a766e */
if(!s->budget--) { s->failed_pc=0x0c0a766eu; return 0; }
r[14]=r[4];
goto P_0c0a7670;
P_0c0a7670: /* original 4e08, guest PC 0x0c0a7670 */
if(!s->budget--) { s->failed_pc=0x0c0a7670u; return 0; }
r[14]<<=2;
goto P_0c0a7672;
P_0c0a7672: /* original 0eee, guest PC 0x0c0a7672 */
if(!s->budget--) { s->failed_pc=0x0c0a7672u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c0a7674;
P_0c0a7674: /* original 2ee8, guest PC 0x0c0a7674 */
if(!s->budget--) { s->failed_pc=0x0c0a7674u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a7676;
P_0c0a7676: /* original 891f, guest PC 0x0c0a7676 */
if(!s->budget--) { s->failed_pc=0x0c0a7676u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a7678;
P_0c0a7678: /* original 60e3, guest PC 0x0c0a7678 */
if(!s->budget--) { s->failed_pc=0x0c0a7678u; return 0; }
r[0]=r[14];
goto P_0c0a767a;
P_0c0a767a: /* original 88ff, guest PC 0x0c0a767a */
if(!s->budget--) { s->failed_pc=0x0c0a767au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0a767c;
P_0c0a767c: /* original 891c, guest PC 0x0c0a767c */
if(!s->budget--) { s->failed_pc=0x0c0a767cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a767e;
P_0c0a767e: /* original d311, guest PC 0x0c0a767e */
if(!s->budget--) { s->failed_pc=0x0c0a767eu; return 0; }
r[3]=read(ram,0x0c0a76c4u,4);
goto P_0c0a7680;
P_0c0a7680: /* original 430b, guest PC 0x0c0a7680 */
if(!s->budget--) { s->failed_pc=0x0c0a7680u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7684u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7684u) { target=s->pc; goto dispatch; }
goto P_0c0a7684;
P_0c0a7682: /* original e400, guest PC 0x0c0a7682 */
if(!s->budget--) { s->failed_pc=0x0c0a7682u; return 0; }
r[4]=0x00000000u;
goto P_0c0a7684;
P_0c0a7684: /* original d211, guest PC 0x0c0a7684 */
if(!s->budget--) { s->failed_pc=0x0c0a7684u; return 0; }
r[2]=read(ram,0x0c0a76ccu,4);
goto P_0c0a7686;
P_0c0a7686: /* original d410, guest PC 0x0c0a7686 */
if(!s->budget--) { s->failed_pc=0x0c0a7686u; return 0; }
r[4]=read(ram,0x0c0a76c8u,4);
goto P_0c0a7688;
P_0c0a7688: /* original 420b, guest PC 0x0c0a7688 */
if(!s->budget--) { s->failed_pc=0x0c0a7688u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a768cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a768cu) { target=s->pc; goto dispatch; }
goto P_0c0a768c;
P_0c0a768a: /* original 0009, guest PC 0x0c0a768a */
if(!s->budget--) { s->failed_pc=0x0c0a768au; return 0; }
goto P_0c0a768c;
P_0c0a768c: /* original 50e1, guest PC 0x0c0a768c */
if(!s->budget--) { s->failed_pc=0x0c0a768cu; return 0; }
r[0]=read(ram,r[14]+4,4);
goto P_0c0a768e;
P_0c0a768e: /* original c801, guest PC 0x0c0a768e */
if(!s->budget--) { s->failed_pc=0x0c0a768eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a7690;
P_0c0a7690: /* original 8904, guest PC 0x0c0a7690 */
if(!s->budget--) { s->failed_pc=0x0c0a7690u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a769c; }
goto P_0c0a7692;
P_0c0a7692: /* original d213, guest PC 0x0c0a7692 */
if(!s->budget--) { s->failed_pc=0x0c0a7692u; return 0; }
r[2]=read(ram,0x0c0a76e0u,4);
goto P_0c0a7694;
P_0c0a7694: /* original 420b, guest PC 0x0c0a7694 */
if(!s->budget--) { s->failed_pc=0x0c0a7694u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7698u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7698u) { target=s->pc; goto dispatch; }
goto P_0c0a7698;
P_0c0a7696: /* original 64e3, guest PC 0x0c0a7696 */
if(!s->budget--) { s->failed_pc=0x0c0a7696u; return 0; }
r[4]=r[14];
goto P_0c0a7698;
P_0c0a7698: /* original a009, guest PC 0x0c0a7698 */
if(!s->budget--) { s->failed_pc=0x0c0a7698u; return 0; }
goto P_0c0a76ae;
P_0c0a769a: /* original 0009, guest PC 0x0c0a769a */
if(!s->budget--) { s->failed_pc=0x0c0a769au; return 0; }
goto P_0c0a769c;
P_0c0a769c: /* original d20d, guest PC 0x0c0a769c */
if(!s->budget--) { s->failed_pc=0x0c0a769cu; return 0; }
r[2]=read(ram,0x0c0a76d4u,4);
goto P_0c0a769e;
P_0c0a769e: /* original 420b, guest PC 0x0c0a769e */
if(!s->budget--) { s->failed_pc=0x0c0a769eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a76a2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a76a2u) { target=s->pc; goto dispatch; }
goto P_0c0a76a2;
P_0c0a76a0: /* original 0009, guest PC 0x0c0a76a0 */
if(!s->budget--) { s->failed_pc=0x0c0a76a0u; return 0; }
goto P_0c0a76a2;
P_0c0a76a2: /* original d310, guest PC 0x0c0a76a2 */
if(!s->budget--) { s->failed_pc=0x0c0a76a2u; return 0; }
r[3]=read(ram,0x0c0a76e4u,4);
goto P_0c0a76a4;
P_0c0a76a4: /* original 23e8, guest PC 0x0c0a76a4 */
if(!s->budget--) { s->failed_pc=0x0c0a76a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c0a76a6;
P_0c0a76a6: /* original 8902, guest PC 0x0c0a76a6 */
if(!s->budget--) { s->failed_pc=0x0c0a76a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76ae; }
goto P_0c0a76a8;
P_0c0a76a8: /* original d30f, guest PC 0x0c0a76a8 */
if(!s->budget--) { s->failed_pc=0x0c0a76a8u; return 0; }
r[3]=read(ram,0x0c0a76e8u,4);
goto P_0c0a76aa;
P_0c0a76aa: /* original 430b, guest PC 0x0c0a76aa */
if(!s->budget--) { s->failed_pc=0x0c0a76aau; return 0; }
target=r[3];
r[16]=code_base|0x0c0a76aeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a76aeu) { target=s->pc; goto dispatch; }
goto P_0c0a76ae;
P_0c0a76ac: /* original 64e3, guest PC 0x0c0a76ac */
if(!s->budget--) { s->failed_pc=0x0c0a76acu; return 0; }
r[4]=r[14];
goto P_0c0a76ae;
P_0c0a76ae: /* original 4f26, guest PC 0x0c0a76ae */
if(!s->budget--) { s->failed_pc=0x0c0a76aeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a76b0;
P_0c0a76b0: /* original d30a, guest PC 0x0c0a76b0 */
if(!s->budget--) { s->failed_pc=0x0c0a76b0u; return 0; }
r[3]=read(ram,0x0c0a76dcu,4);
goto P_0c0a76b2;
P_0c0a76b2: /* original e401, guest PC 0x0c0a76b2 */
if(!s->budget--) { s->failed_pc=0x0c0a76b2u; return 0; }
r[4]=0x00000001u;
goto P_0c0a76b4;
P_0c0a76b4: /* original 432b, guest PC 0x0c0a76b4 */
if(!s->budget--) { s->failed_pc=0x0c0a76b4u; return 0; }
target=r[3];
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
P_0c0a76b6: /* original 6ef6, guest PC 0x0c0a76b6 */
if(!s->budget--) { s->failed_pc=0x0c0a76b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a76b8;
P_0c0a76b8: /* original 4f26, guest PC 0x0c0a76b8 */
if(!s->budget--) { s->failed_pc=0x0c0a76b8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a76ba;
P_0c0a76ba: /* original 000b, guest PC 0x0c0a76ba */
if(!s->budget--) { s->failed_pc=0x0c0a76bau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a76bc: /* original 6ef6, guest PC 0x0c0a76bc */
if(!s->budget--) { s->failed_pc=0x0c0a76bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a76beu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a76beu; return 0; } return 1;
P_0c0a76ec: /* original 2fe6, guest PC 0x0c0a76ec */
if(!s->budget--) { s->failed_pc=0x0c0a76ecu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a76ee;
P_0c0a76ee: /* original 4f22, guest PC 0x0c0a76ee */
if(!s->budget--) { s->failed_pc=0x0c0a76eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a76f0;
P_0c0a76f0: /* original 7ff8, guest PC 0x0c0a76f0 */
if(!s->budget--) { s->failed_pc=0x0c0a76f0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a76f2;
P_0c0a76f2: /* original 1f41, guest PC 0x0c0a76f2 */
if(!s->budget--) { s->failed_pc=0x0c0a76f2u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0a76f4;
P_0c0a76f4: /* original ff4a, guest PC 0x0c0a76f4 */
if(!s->budget--) { s->failed_pc=0x0c0a76f4u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c0a76f6;
P_0c0a76f6: /* original d34b, guest PC 0x0c0a76f6 */
if(!s->budget--) { s->failed_pc=0x0c0a76f6u; return 0; }
r[3]=read(ram,0x0c0a7824u,4);
goto P_0c0a76f8;
P_0c0a76f8: /* original 430b, guest PC 0x0c0a76f8 */
if(!s->budget--) { s->failed_pc=0x0c0a76f8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a76fcu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a76fcu) { target=s->pc; goto dispatch; }
goto P_0c0a76fc;
P_0c0a76fa: /* original e400, guest PC 0x0c0a76fa */
if(!s->budget--) { s->failed_pc=0x0c0a76fau; return 0; }
r[4]=0x00000000u;
goto P_0c0a76fc;
P_0c0a76fc: /* original 5ef1, guest PC 0x0c0a76fc */
if(!s->budget--) { s->failed_pc=0x0c0a76fcu; return 0; }
r[14]=read(ram,r[15]+4,4);
goto P_0c0a76fe;
P_0c0a76fe: /* original e301, guest PC 0x0c0a76fe */
if(!s->budget--) { s->failed_pc=0x0c0a76feu; return 0; }
r[3]=0x00000001u;
goto P_0c0a7700;
P_0c0a7700: /* original 5ee1, guest PC 0x0c0a7700 */
if(!s->budget--) { s->failed_pc=0x0c0a7700u; return 0; }
r[14]=read(ram,r[14]+4,4);
goto P_0c0a7702;
P_0c0a7702: /* original 23e8, guest PC 0x0c0a7702 */
if(!s->budget--) { s->failed_pc=0x0c0a7702u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c0a7704;
P_0c0a7704: /* original 8b1e, guest PC 0x0c0a7704 */
if(!s->budget--) { s->failed_pc=0x0c0a7704u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7744; }
goto P_0c0a7706;
P_0c0a7706: /* original 2ee8, guest PC 0x0c0a7706 */
if(!s->budget--) { s->failed_pc=0x0c0a7706u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a7708;
P_0c0a7708: /* original 8916, guest PC 0x0c0a7708 */
if(!s->budget--) { s->failed_pc=0x0c0a7708u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7738; }
goto P_0c0a770a;
P_0c0a770a: /* original d348, guest PC 0x0c0a770a */
if(!s->budget--) { s->failed_pc=0x0c0a770au; return 0; }
r[3]=read(ram,0x0c0a782cu,4);
goto P_0c0a770c;
P_0c0a770c: /* original d446, guest PC 0x0c0a770c */
if(!s->budget--) { s->failed_pc=0x0c0a770cu; return 0; }
r[4]=read(ram,0x0c0a7828u,4);
goto P_0c0a770e;
P_0c0a770e: /* original 430b, guest PC 0x0c0a770e */
if(!s->budget--) { s->failed_pc=0x0c0a770eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7712u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7712u) { target=s->pc; goto dispatch; }
goto P_0c0a7712;
P_0c0a7710: /* original 0009, guest PC 0x0c0a7710 */
if(!s->budget--) { s->failed_pc=0x0c0a7710u; return 0; }
goto P_0c0a7712;
P_0c0a7712: /* original d247, guest PC 0x0c0a7712 */
if(!s->budget--) { s->failed_pc=0x0c0a7712u; return 0; }
r[2]=read(ram,0x0c0a7830u,4);
goto P_0c0a7714;
P_0c0a7714: /* original 420b, guest PC 0x0c0a7714 */
if(!s->budget--) { s->failed_pc=0x0c0a7714u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7718u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7718u) { target=s->pc; goto dispatch; }
goto P_0c0a7718;
P_0c0a7716: /* original 0009, guest PC 0x0c0a7716 */
if(!s->budget--) { s->failed_pc=0x0c0a7716u; return 0; }
goto P_0c0a7718;
P_0c0a7718: /* original f2f8, guest PC 0x0c0a7718 */
if(!s->budget--) { s->failed_pc=0x0c0a7718u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0a771a;
P_0c0a771a: /* original f39d, guest PC 0x0c0a771a */
if(!s->budget--) { s->failed_pc=0x0c0a771au; return 0; }
fr[3]=0x3f800000u;
goto P_0c0a771c;
P_0c0a771c: /* original f325, guest PC 0x0c0a771c */
if(!s->budget--) { s->failed_pc=0x0c0a771cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0a771e;
P_0c0a771e: /* original 8907, guest PC 0x0c0a771e */
if(!s->budget--) { s->failed_pc=0x0c0a771eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7730; }
goto P_0c0a7720;
P_0c0a7720: /* original d244, guest PC 0x0c0a7720 */
if(!s->budget--) { s->failed_pc=0x0c0a7720u; return 0; }
r[2]=read(ram,0x0c0a7834u,4);
goto P_0c0a7722;
P_0c0a7722: /* original 22e8, guest PC 0x0c0a7722 */
if(!s->budget--) { s->failed_pc=0x0c0a7722u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[14])==0)!=0);
goto P_0c0a7724;
P_0c0a7724: /* original 8908, guest PC 0x0c0a7724 */
if(!s->budget--) { s->failed_pc=0x0c0a7724u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7738; }
goto P_0c0a7726;
P_0c0a7726: /* original d244, guest PC 0x0c0a7726 */
if(!s->budget--) { s->failed_pc=0x0c0a7726u; return 0; }
r[2]=read(ram,0x0c0a7838u,4);
goto P_0c0a7728;
P_0c0a7728: /* original 420b, guest PC 0x0c0a7728 */
if(!s->budget--) { s->failed_pc=0x0c0a7728u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a772cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a772cu) { target=s->pc; goto dispatch; }
goto P_0c0a772c;
P_0c0a772a: /* original 64e3, guest PC 0x0c0a772a */
if(!s->budget--) { s->failed_pc=0x0c0a772au; return 0; }
r[4]=r[14];
goto P_0c0a772c;
P_0c0a772c: /* original a004, guest PC 0x0c0a772c */
if(!s->budget--) { s->failed_pc=0x0c0a772cu; return 0; }
goto P_0c0a7738;
P_0c0a772e: /* original 0009, guest PC 0x0c0a772e */
if(!s->budget--) { s->failed_pc=0x0c0a772eu; return 0; }
goto P_0c0a7730;
P_0c0a7730: /* original d342, guest PC 0x0c0a7730 */
if(!s->budget--) { s->failed_pc=0x0c0a7730u; return 0; }
r[3]=read(ram,0x0c0a783cu,4);
goto P_0c0a7732;
P_0c0a7732: /* original f42c, guest PC 0x0c0a7732 */
if(!s->budget--) { s->failed_pc=0x0c0a7732u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c0a7734;
P_0c0a7734: /* original 430b, guest PC 0x0c0a7734 */
if(!s->budget--) { s->failed_pc=0x0c0a7734u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7738u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7738u) { target=s->pc; goto dispatch; }
goto P_0c0a7738;
P_0c0a7736: /* original 64e3, guest PC 0x0c0a7736 */
if(!s->budget--) { s->failed_pc=0x0c0a7736u; return 0; }
r[4]=r[14];
goto P_0c0a7738;
P_0c0a7738: /* original 7f08, guest PC 0x0c0a7738 */
if(!s->budget--) { s->failed_pc=0x0c0a7738u; return 0; }
r[15]+=0x00000008u;
goto P_0c0a773a;
P_0c0a773a: /* original d241, guest PC 0x0c0a773a */
if(!s->budget--) { s->failed_pc=0x0c0a773au; return 0; }
r[2]=read(ram,0x0c0a7840u,4);
goto P_0c0a773c;
P_0c0a773c: /* original 4f26, guest PC 0x0c0a773c */
if(!s->budget--) { s->failed_pc=0x0c0a773cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a773e;
P_0c0a773e: /* original e401, guest PC 0x0c0a773e */
if(!s->budget--) { s->failed_pc=0x0c0a773eu; return 0; }
r[4]=0x00000001u;
goto P_0c0a7740;
P_0c0a7740: /* original 422b, guest PC 0x0c0a7740 */
if(!s->budget--) { s->failed_pc=0x0c0a7740u; return 0; }
target=r[2];
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
P_0c0a7742: /* original 6ef6, guest PC 0x0c0a7742 */
if(!s->budget--) { s->failed_pc=0x0c0a7742u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a7744;
P_0c0a7744: /* original 7f08, guest PC 0x0c0a7744 */
if(!s->budget--) { s->failed_pc=0x0c0a7744u; return 0; }
r[15]+=0x00000008u;
goto P_0c0a7746;
P_0c0a7746: /* original 4f26, guest PC 0x0c0a7746 */
if(!s->budget--) { s->failed_pc=0x0c0a7746u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7748;
P_0c0a7748: /* original 000b, guest PC 0x0c0a7748 */
if(!s->budget--) { s->failed_pc=0x0c0a7748u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a774a: /* original 6ef6, guest PC 0x0c0a774a */
if(!s->budget--) { s->failed_pc=0x0c0a774au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a774cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a774cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
