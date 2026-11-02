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
int vf3_away_batch70_adapter_37(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c600cu: goto P_0c0c600c;
case 0x0c0c600eu: goto P_0c0c600e;
case 0x0c0c6010u: goto P_0c0c6010;
case 0x0c0c6012u: goto P_0c0c6012;
case 0x0c0c6014u: goto P_0c0c6014;
case 0x0c0c6016u: goto P_0c0c6016;
case 0x0c0c6018u: goto P_0c0c6018;
case 0x0c0c601au: goto P_0c0c601a;
case 0x0c0c601cu: goto P_0c0c601c;
case 0x0c0c601eu: goto P_0c0c601e;
case 0x0c0c6020u: goto P_0c0c6020;
case 0x0c0c6022u: goto P_0c0c6022;
case 0x0c0c6024u: goto P_0c0c6024;
case 0x0c0c6026u: goto P_0c0c6026;
case 0x0c0c6028u: goto P_0c0c6028;
case 0x0c0c602au: goto P_0c0c602a;
case 0x0c0c602cu: goto P_0c0c602c;
case 0x0c0c602eu: goto P_0c0c602e;
case 0x0c0c6030u: goto P_0c0c6030;
case 0x0c0c6032u: goto P_0c0c6032;
case 0x0c0c6034u: goto P_0c0c6034;
case 0x0c0c6036u: goto P_0c0c6036;
case 0x0c0c6038u: goto P_0c0c6038;
case 0x0c0c603au: goto P_0c0c603a;
case 0x0c0c603cu: goto P_0c0c603c;
case 0x0c0c603eu: goto P_0c0c603e;
case 0x0c0c6040u: goto P_0c0c6040;
case 0x0c0c6042u: goto P_0c0c6042;
case 0x0c0c6044u: goto P_0c0c6044;
case 0x0c0c6046u: goto P_0c0c6046;
case 0x0c0c6048u: goto P_0c0c6048;
case 0x0c0c604au: goto P_0c0c604a;
case 0x0c0c604cu: goto P_0c0c604c;
case 0x0c0c604eu: goto P_0c0c604e;
case 0x0c0c6050u: goto P_0c0c6050;
case 0x0c0c6052u: goto P_0c0c6052;
case 0x0c0c6054u: goto P_0c0c6054;
case 0x0c0c6056u: goto P_0c0c6056;
case 0x0c0c6058u: goto P_0c0c6058;
case 0x0c0c605au: goto P_0c0c605a;
case 0x0c0c605cu: goto P_0c0c605c;
case 0x0c0c605eu: goto P_0c0c605e;
case 0x0c0c6060u: goto P_0c0c6060;
case 0x0c0c6062u: goto P_0c0c6062;
case 0x0c0c6064u: goto P_0c0c6064;
case 0x0c0c6066u: goto P_0c0c6066;
case 0x0c0c6068u: goto P_0c0c6068;
case 0x0c0c606au: goto P_0c0c606a;
case 0x0c0c606cu: goto P_0c0c606c;
case 0x0c0c606eu: goto P_0c0c606e;
case 0x0c0c6070u: goto P_0c0c6070;
case 0x0c0c6072u: goto P_0c0c6072;
case 0x0c0c6074u: goto P_0c0c6074;
case 0x0c0c6076u: goto P_0c0c6076;
case 0x0c0c6078u: goto P_0c0c6078;
case 0x0c0c607au: goto P_0c0c607a;
case 0x0c0c607cu: goto P_0c0c607c;
case 0x0c0c607eu: goto P_0c0c607e;
case 0x0c0c6080u: goto P_0c0c6080;
case 0x0c0c6082u: goto P_0c0c6082;
case 0x0c0c6084u: goto P_0c0c6084;
case 0x0c0c6086u: goto P_0c0c6086;
case 0x0c0c6088u: goto P_0c0c6088;
case 0x0c0c608au: goto P_0c0c608a;
case 0x0c0c608cu: goto P_0c0c608c;
case 0x0c0c608eu: goto P_0c0c608e;
case 0x0c0c6090u: goto P_0c0c6090;
case 0x0c0c6092u: goto P_0c0c6092;
case 0x0c0c6094u: goto P_0c0c6094;
case 0x0c0c6096u: goto P_0c0c6096;
case 0x0c0c6098u: goto P_0c0c6098;
case 0x0c0c609au: goto P_0c0c609a;
case 0x0c0c609cu: goto P_0c0c609c;
case 0x0c0c609eu: goto P_0c0c609e;
case 0x0c0c60a0u: goto P_0c0c60a0;
case 0x0c0c60a2u: goto P_0c0c60a2;
case 0x0c0c60a4u: goto P_0c0c60a4;
case 0x0c0c60a6u: goto P_0c0c60a6;
case 0x0c0c60a8u: goto P_0c0c60a8;
case 0x0c0c60aau: goto P_0c0c60aa;
case 0x0c0c60acu: goto P_0c0c60ac;
case 0x0c0c60aeu: goto P_0c0c60ae;
case 0x0c0c60b0u: goto P_0c0c60b0;
case 0x0c0c60b2u: goto P_0c0c60b2;
case 0x0c0c60b4u: goto P_0c0c60b4;
case 0x0c0c60b6u: goto P_0c0c60b6;
case 0x0c0c60b8u: goto P_0c0c60b8;
case 0x0c0c60bau: goto P_0c0c60ba;
case 0x0c0c60bcu: goto P_0c0c60bc;
case 0x0c0c60beu: goto P_0c0c60be;
case 0x0c0c66b8u: goto P_0c0c66b8;
case 0x0c0c66bau: goto P_0c0c66ba;
case 0x0c0c66c0u: goto P_0c0c66c0;
case 0x0c0c66c2u: goto P_0c0c66c2;
case 0x0c0c6742u: goto P_0c0c6742;
case 0x0c0c6744u: goto P_0c0c6744;
case 0x0c0c6746u: goto P_0c0c6746;
case 0x0c0c6748u: goto P_0c0c6748;
case 0x0c0c70a4u: goto P_0c0c70a4;
case 0x0c0c70a6u: goto P_0c0c70a6;
case 0x0c0c70a8u: goto P_0c0c70a8;
case 0x0c0c70aau: goto P_0c0c70aa;
case 0x0c0c70acu: goto P_0c0c70ac;
case 0x0c0c70aeu: goto P_0c0c70ae;
case 0x0c0c70b0u: goto P_0c0c70b0;
case 0x0c0c70b2u: goto P_0c0c70b2;
case 0x0c0c70b4u: goto P_0c0c70b4;
case 0x0c0c70b6u: goto P_0c0c70b6;
case 0x0c0c70b8u: goto P_0c0c70b8;
case 0x0c0c70bau: goto P_0c0c70ba;
case 0x0c0c70bcu: goto P_0c0c70bc;
case 0x0c0c70beu: goto P_0c0c70be;
case 0x0c0c70c0u: goto P_0c0c70c0;
case 0x0c0c70c2u: goto P_0c0c70c2;
case 0x0c0c70c4u: goto P_0c0c70c4;
case 0x0c0c70c6u: goto P_0c0c70c6;
case 0x0c0c70c8u: goto P_0c0c70c8;
case 0x0c0c70cau: goto P_0c0c70ca;
case 0x0c0c70ccu: goto P_0c0c70cc;
case 0x0c0c70ceu: goto P_0c0c70ce;
case 0x0c0c70d0u: goto P_0c0c70d0;
case 0x0c0c70d2u: goto P_0c0c70d2;
case 0x0c0c70d4u: goto P_0c0c70d4;
case 0x0c0c70d6u: goto P_0c0c70d6;
case 0x0c0c70d8u: goto P_0c0c70d8;
case 0x0c0c70dau: goto P_0c0c70da;
case 0x0c0c70dcu: goto P_0c0c70dc;
case 0x0c0c70deu: goto P_0c0c70de;
case 0x0c0c70e0u: goto P_0c0c70e0;
case 0x0c0c70e2u: goto P_0c0c70e2;
case 0x0c0c70e4u: goto P_0c0c70e4;
case 0x0c0c7648u: goto P_0c0c7648;
case 0x0c0c764au: goto P_0c0c764a;
case 0x0c0c764cu: goto P_0c0c764c;
case 0x0c0c764eu: goto P_0c0c764e;
case 0x0c0c7650u: goto P_0c0c7650;
case 0x0c0c7652u: goto P_0c0c7652;
case 0x0c0c7654u: goto P_0c0c7654;
case 0x0c0c7656u: goto P_0c0c7656;
case 0x0c0c7658u: goto P_0c0c7658;
case 0x0c0c765au: goto P_0c0c765a;
case 0x0c0c765cu: goto P_0c0c765c;
case 0x0c0c765eu: goto P_0c0c765e;
case 0x0c0c7660u: goto P_0c0c7660;
case 0x0c0c7662u: goto P_0c0c7662;
case 0x0c0c7664u: goto P_0c0c7664;
case 0x0c0c7666u: goto P_0c0c7666;
case 0x0c0c7668u: goto P_0c0c7668;
case 0x0c0c766au: goto P_0c0c766a;
case 0x0c0c766cu: goto P_0c0c766c;
case 0x0c0c766eu: goto P_0c0c766e;
case 0x0c0c7670u: goto P_0c0c7670;
case 0x0c0c7672u: goto P_0c0c7672;
case 0x0c0c7674u: goto P_0c0c7674;
case 0x0c0c7676u: goto P_0c0c7676;
case 0x0c0c7678u: goto P_0c0c7678;
case 0x0c0c767au: goto P_0c0c767a;
case 0x0c0c767cu: goto P_0c0c767c;
case 0x0c0c767eu: goto P_0c0c767e;
case 0x0c0c7680u: goto P_0c0c7680;
case 0x0c0c7682u: goto P_0c0c7682;
case 0x0c0c7684u: goto P_0c0c7684;
case 0x0c0c7686u: goto P_0c0c7686;
case 0x0c0c7688u: goto P_0c0c7688;
case 0x0c0c768au: goto P_0c0c768a;
case 0x0c0c768cu: goto P_0c0c768c;
case 0x0c0c768eu: goto P_0c0c768e;
case 0x0c0c7690u: goto P_0c0c7690;
case 0x0c0c7692u: goto P_0c0c7692;
case 0x0c0c7694u: goto P_0c0c7694;
case 0x0c0c7696u: goto P_0c0c7696;
case 0x0c0c7698u: goto P_0c0c7698;
case 0x0c0c769au: goto P_0c0c769a;
case 0x0c0c769cu: goto P_0c0c769c;
case 0x0c0c769eu: goto P_0c0c769e;
case 0x0c0c76a0u: goto P_0c0c76a0;
case 0x0c0c76a2u: goto P_0c0c76a2;
case 0x0c0c76a4u: goto P_0c0c76a4;
case 0x0c0c76a6u: goto P_0c0c76a6;
case 0x0c0c76a8u: goto P_0c0c76a8;
case 0x0c0c76aau: goto P_0c0c76aa;
case 0x0c0c76acu: goto P_0c0c76ac;
case 0x0c0c76aeu: goto P_0c0c76ae;
case 0x0c0c76b0u: goto P_0c0c76b0;
case 0x0c0c76b2u: goto P_0c0c76b2;
case 0x0c0c76b4u: goto P_0c0c76b4;
case 0x0c0c76b6u: goto P_0c0c76b6;
case 0x0c0c76b8u: goto P_0c0c76b8;
case 0x0c0c76bau: goto P_0c0c76ba;
case 0x0c0c76bcu: goto P_0c0c76bc;
case 0x0c0c76beu: goto P_0c0c76be;
case 0x0c0c76c0u: goto P_0c0c76c0;
case 0x0c0c76c2u: goto P_0c0c76c2;
case 0x0c0c76c4u: goto P_0c0c76c4;
case 0x0c0c76c6u: goto P_0c0c76c6;
case 0x0c0c76c8u: goto P_0c0c76c8;
case 0x0c0c76cau: goto P_0c0c76ca;
case 0x0c0c76ccu: goto P_0c0c76cc;
case 0x0c0c76ceu: goto P_0c0c76ce;
case 0x0c0c76d0u: goto P_0c0c76d0;
case 0x0c0c76d2u: goto P_0c0c76d2;
case 0x0c0c76d4u: goto P_0c0c76d4;
case 0x0c0c76d6u: goto P_0c0c76d6;
case 0x0c0c76d8u: goto P_0c0c76d8;
case 0x0c0c76dau: goto P_0c0c76da;
case 0x0c0c76dcu: goto P_0c0c76dc;
case 0x0c0c76deu: goto P_0c0c76de;
case 0x0c0c76e0u: goto P_0c0c76e0;
case 0x0c0c76e2u: goto P_0c0c76e2;
case 0x0c0c76e4u: goto P_0c0c76e4;
case 0x0c0c76e6u: goto P_0c0c76e6;
case 0x0c0c76e8u: goto P_0c0c76e8;
case 0x0c0c76eau: goto P_0c0c76ea;
case 0x0c0c76ecu: goto P_0c0c76ec;
case 0x0c0c76eeu: goto P_0c0c76ee;
case 0x0c0c76f0u: goto P_0c0c76f0;
case 0x0c0c76f2u: goto P_0c0c76f2;
case 0x0c0c76f4u: goto P_0c0c76f4;
case 0x0c0c76f6u: goto P_0c0c76f6;
case 0x0c0c76f8u: goto P_0c0c76f8;
case 0x0c0c76fau: goto P_0c0c76fa;
case 0x0c0c76fcu: goto P_0c0c76fc;
case 0x0c0c76feu: goto P_0c0c76fe;
case 0x0c0c7700u: goto P_0c0c7700;
case 0x0c0c7702u: goto P_0c0c7702;
case 0x0c0c7704u: goto P_0c0c7704;
case 0x0c0c7706u: goto P_0c0c7706;
case 0x0c0c7708u: goto P_0c0c7708;
case 0x0c0c770au: goto P_0c0c770a;
case 0x0c0c770cu: goto P_0c0c770c;
case 0x0c0c770eu: goto P_0c0c770e;
case 0x0c0c7710u: goto P_0c0c7710;
case 0x0c0c7712u: goto P_0c0c7712;
case 0x0c0c7714u: goto P_0c0c7714;
case 0x0c0c7716u: goto P_0c0c7716;
case 0x0c0c7718u: goto P_0c0c7718;
case 0x0c0c771au: goto P_0c0c771a;
case 0x0c0c771cu: goto P_0c0c771c;
case 0x0c0c771eu: goto P_0c0c771e;
case 0x0c0c7720u: goto P_0c0c7720;
case 0x0c0c7722u: goto P_0c0c7722;
case 0x0c0c7724u: goto P_0c0c7724;
case 0x0c0c7726u: goto P_0c0c7726;
case 0x0c0c7728u: goto P_0c0c7728;
case 0x0c0c772au: goto P_0c0c772a;
case 0x0c0c772cu: goto P_0c0c772c;
case 0x0c0c772eu: goto P_0c0c772e;
case 0x0c0c7730u: goto P_0c0c7730;
case 0x0c0c7732u: goto P_0c0c7732;
case 0x0c0c7734u: goto P_0c0c7734;
case 0x0c0c7736u: goto P_0c0c7736;
case 0x0c0c7738u: goto P_0c0c7738;
case 0x0c0c773au: goto P_0c0c773a;
case 0x0c0c773cu: goto P_0c0c773c;
case 0x0c0c773eu: goto P_0c0c773e;
case 0x0c0c7740u: goto P_0c0c7740;
case 0x0c0c7742u: goto P_0c0c7742;
case 0x0c0c7744u: goto P_0c0c7744;
case 0x0c0c7746u: goto P_0c0c7746;
case 0x0c0c7778u: goto P_0c0c7778;
case 0x0c0c777au: goto P_0c0c777a;
case 0x0c0c777cu: goto P_0c0c777c;
case 0x0c0c777eu: goto P_0c0c777e;
case 0x0c0c7780u: goto P_0c0c7780;
case 0x0c0c7782u: goto P_0c0c7782;
case 0x0c0c7784u: goto P_0c0c7784;
case 0x0c0c7786u: goto P_0c0c7786;
case 0x0c0c7788u: goto P_0c0c7788;
case 0x0c0c778au: goto P_0c0c778a;
case 0x0c0c778cu: goto P_0c0c778c;
case 0x0c0c778eu: goto P_0c0c778e;
case 0x0c0c7790u: goto P_0c0c7790;
case 0x0c0c7792u: goto P_0c0c7792;
case 0x0c0c7794u: goto P_0c0c7794;
case 0x0c0c7796u: goto P_0c0c7796;
case 0x0c0c7798u: goto P_0c0c7798;
case 0x0c0c779au: goto P_0c0c779a;
case 0x0c0c779cu: goto P_0c0c779c;
case 0x0c0c779eu: goto P_0c0c779e;
case 0x0c0c77a0u: goto P_0c0c77a0;
case 0x0c0c77a2u: goto P_0c0c77a2;
case 0x0c0c77a4u: goto P_0c0c77a4;
case 0x0c0c77a6u: goto P_0c0c77a6;
case 0x0c0c77a8u: goto P_0c0c77a8;
case 0x0c0c77aau: goto P_0c0c77aa;
case 0x0c0c77acu: goto P_0c0c77ac;
case 0x0c0c77aeu: goto P_0c0c77ae;
case 0x0c0c77b0u: goto P_0c0c77b0;
case 0x0c0c77b2u: goto P_0c0c77b2;
case 0x0c0c77b4u: goto P_0c0c77b4;
case 0x0c0c77b6u: goto P_0c0c77b6;
case 0x0c0c77b8u: goto P_0c0c77b8;
case 0x0c0c77bau: goto P_0c0c77ba;
case 0x0c0c77bcu: goto P_0c0c77bc;
case 0x0c0c77beu: goto P_0c0c77be;
case 0x0c0c77c0u: goto P_0c0c77c0;
case 0x0c0c77c2u: goto P_0c0c77c2;
case 0x0c0c77c4u: goto P_0c0c77c4;
case 0x0c0c77c6u: goto P_0c0c77c6;
case 0x0c0c77c8u: goto P_0c0c77c8;
case 0x0c0c77cau: goto P_0c0c77ca;
case 0x0c0c77ccu: goto P_0c0c77cc;
case 0x0c0c77ceu: goto P_0c0c77ce;
case 0x0c0c77d0u: goto P_0c0c77d0;
case 0x0c0c77d2u: goto P_0c0c77d2;
case 0x0c0c77d4u: goto P_0c0c77d4;
case 0x0c0c77d6u: goto P_0c0c77d6;
case 0x0c0c77d8u: goto P_0c0c77d8;
case 0x0c0c77dau: goto P_0c0c77da;
case 0x0c0c77dcu: goto P_0c0c77dc;
case 0x0c0c77deu: goto P_0c0c77de;
case 0x0c0c77e0u: goto P_0c0c77e0;
case 0x0c0c77e2u: goto P_0c0c77e2;
case 0x0c0c77e4u: goto P_0c0c77e4;
case 0x0c0c77e6u: goto P_0c0c77e6;
case 0x0c0c77e8u: goto P_0c0c77e8;
case 0x0c0c77eau: goto P_0c0c77ea;
case 0x0c0c77ecu: goto P_0c0c77ec;
case 0x0c0c77eeu: goto P_0c0c77ee;
case 0x0c0c77f0u: goto P_0c0c77f0;
case 0x0c0c77f2u: goto P_0c0c77f2;
case 0x0c0c77f4u: goto P_0c0c77f4;
case 0x0c0c77f6u: goto P_0c0c77f6;
case 0x0c0c77f8u: goto P_0c0c77f8;
case 0x0c0c77fau: goto P_0c0c77fa;
case 0x0c0c77fcu: goto P_0c0c77fc;
case 0x0c0c77feu: goto P_0c0c77fe;
case 0x0c0c7800u: goto P_0c0c7800;
case 0x0c0c7802u: goto P_0c0c7802;
case 0x0c0c7804u: goto P_0c0c7804;
case 0x0c0c7806u: goto P_0c0c7806;
case 0x0c0c7808u: goto P_0c0c7808;
case 0x0c0c780au: goto P_0c0c780a;
case 0x0c0c780cu: goto P_0c0c780c;
case 0x0c0c780eu: goto P_0c0c780e;
case 0x0c0c7810u: goto P_0c0c7810;
case 0x0c0c7812u: goto P_0c0c7812;
case 0x0c0c7814u: goto P_0c0c7814;
case 0x0c0c7816u: goto P_0c0c7816;
case 0x0c0c7818u: goto P_0c0c7818;
case 0x0c0c781au: goto P_0c0c781a;
case 0x0c0c781cu: goto P_0c0c781c;
case 0x0c0c781eu: goto P_0c0c781e;
case 0x0c0c7820u: goto P_0c0c7820;
case 0x0c0c7822u: goto P_0c0c7822;
case 0x0c0c7824u: goto P_0c0c7824;
case 0x0c0c7826u: goto P_0c0c7826;
case 0x0c0c7828u: goto P_0c0c7828;
case 0x0c0c782au: goto P_0c0c782a;
case 0x0c0c782cu: goto P_0c0c782c;
case 0x0c0c782eu: goto P_0c0c782e;
case 0x0c0c7830u: goto P_0c0c7830;
case 0x0c0c7832u: goto P_0c0c7832;
case 0x0c0c7834u: goto P_0c0c7834;
case 0x0c0c7836u: goto P_0c0c7836;
case 0x0c0c7838u: goto P_0c0c7838;
case 0x0c0c783au: goto P_0c0c783a;
case 0x0c0c783cu: goto P_0c0c783c;
case 0x0c0c783eu: goto P_0c0c783e;
case 0x0c0c7840u: goto P_0c0c7840;
case 0x0c0c7842u: goto P_0c0c7842;
case 0x0c0c7844u: goto P_0c0c7844;
case 0x0c0c7846u: goto P_0c0c7846;
case 0x0c0c7848u: goto P_0c0c7848;
case 0x0c0c784au: goto P_0c0c784a;
case 0x0c0c784cu: goto P_0c0c784c;
case 0x0c0c784eu: goto P_0c0c784e;
case 0x0c0c7850u: goto P_0c0c7850;
case 0x0c0c7852u: goto P_0c0c7852;
case 0x0c0c7854u: goto P_0c0c7854;
case 0x0c0c7856u: goto P_0c0c7856;
case 0x0c0c7858u: goto P_0c0c7858;
case 0x0c0c785au: goto P_0c0c785a;
case 0x0c0c785cu: goto P_0c0c785c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c600c: /* original 2fe6, guest PC 0x0c0c600c */
if(!s->budget--) { s->failed_pc=0x0c0c600cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c600e;
P_0c0c600e: /* original 4411, guest PC 0x0c0c600e */
if(!s->budget--) { s->failed_pc=0x0c0c600eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c6010;
P_0c0c6010: /* original 2fd6, guest PC 0x0c0c6010 */
if(!s->budget--) { s->failed_pc=0x0c0c6010u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6012;
P_0c0c6012: /* original 2fc6, guest PC 0x0c0c6012 */
if(!s->budget--) { s->failed_pc=0x0c0c6012u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6014;
P_0c0c6014: /* original 2fb6, guest PC 0x0c0c6014 */
if(!s->budget--) { s->failed_pc=0x0c0c6014u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6016;
P_0c0c6016: /* original 2fa6, guest PC 0x0c0c6016 */
if(!s->budget--) { s->failed_pc=0x0c0c6016u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6018;
P_0c0c6018: /* original 2f96, guest PC 0x0c0c6018 */
if(!s->budget--) { s->failed_pc=0x0c0c6018u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c601a;
P_0c0c601a: /* original 2f86, guest PC 0x0c0c601a */
if(!s->budget--) { s->failed_pc=0x0c0c601au; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c601c;
P_0c0c601c: /* original 4f22, guest PC 0x0c0c601c */
if(!s->budget--) { s->failed_pc=0x0c0c601cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c601e;
P_0c0c601e: /* original d32a, guest PC 0x0c0c601e */
if(!s->budget--) { s->failed_pc=0x0c0c601eu; return 0; }
r[3]=read(ram,0x0c0c60c8u,4);
goto P_0c0c6020;
P_0c0c6020: /* original 7ff8, guest PC 0x0c0c6020 */
if(!s->budget--) { s->failed_pc=0x0c0c6020u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c6022;
P_0c0c6022: /* original 1f31, guest PC 0x0c0c6022 */
if(!s->budget--) { s->failed_pc=0x0c0c6022u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c6024;
P_0c0c6024: /* original 8b42, guest PC 0x0c0c6024 */
if(!s->budget--) { s->failed_pc=0x0c0c6024u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c60ac; }
goto P_0c0c6026;
P_0c0c6026: /* original 924b, guest PC 0x0c0c6026 */
if(!s->budget--) { s->failed_pc=0x0c0c6026u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c60c0u,2);
goto P_0c0c6028;
P_0c0c6028: /* original 3423, guest PC 0x0c0c6028 */
if(!s->budget--) { s->failed_pc=0x0c0c6028u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0c602a;
P_0c0c602a: /* original 893f, guest PC 0x0c0c602a */
if(!s->budget--) { s->failed_pc=0x0c0c602au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c60ac; }
goto P_0c0c602c;
P_0c0c602c: /* original d027, guest PC 0x0c0c602c */
if(!s->budget--) { s->failed_pc=0x0c0c602cu; return 0; }
r[0]=read(ram,0x0c0c60ccu,4);
goto P_0c0c602e;
P_0c0c602e: /* original 6143, guest PC 0x0c0c602e */
if(!s->budget--) { s->failed_pc=0x0c0c602eu; return 0; }
r[1]=r[4];
goto P_0c0c6030;
P_0c0c6030: /* original 4108, guest PC 0x0c0c6030 */
if(!s->budget--) { s->failed_pc=0x0c0c6030u; return 0; }
r[1]<<=2;
goto P_0c0c6032;
P_0c0c6032: /* original 031e, guest PC 0x0c0c6032 */
if(!s->budget--) { s->failed_pc=0x0c0c6032u; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c0c6034;
P_0c0c6034: /* original 4311, guest PC 0x0c0c6034 */
if(!s->budget--) { s->failed_pc=0x0c0c6034u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0c6036;
P_0c0c6036: /* original 8b39, guest PC 0x0c0c6036 */
if(!s->budget--) { s->failed_pc=0x0c0c6036u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c60ac; }
goto P_0c0c6038;
P_0c0c6038: /* original d325, guest PC 0x0c0c6038 */
if(!s->budget--) { s->failed_pc=0x0c0c6038u; return 0; }
r[3]=read(ram,0x0c0c60d0u,4);
goto P_0c0c603a;
P_0c0c603a: /* original ec00, guest PC 0x0c0c603a */
if(!s->budget--) { s->failed_pc=0x0c0c603au; return 0; }
r[12]=0x00000000u;
goto P_0c0c603c;
P_0c0c603c: /* original e8ff, guest PC 0x0c0c603c */
if(!s->budget--) { s->failed_pc=0x0c0c603cu; return 0; }
r[8]=0xffffffffu;
goto P_0c0c603e;
P_0c0c603e: /* original 2f32, guest PC 0x0c0c603e */
if(!s->budget--) { s->failed_pc=0x0c0c603eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c6040;
P_0c0c6040: /* original da24, guest PC 0x0c0c6040 */
if(!s->budget--) { s->failed_pc=0x0c0c6040u; return 0; }
r[10]=read(ram,0x0c0c60d4u,4);
goto P_0c0c6042;
P_0c0c6042: /* original 993e, guest PC 0x0c0c6042 */
if(!s->budget--) { s->failed_pc=0x0c0c6042u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c60c2u,2);
goto P_0c0c6044;
P_0c0c6044: /* original dd25, guest PC 0x0c0c6044 */
if(!s->budget--) { s->failed_pc=0x0c0c6044u; return 0; }
r[13]=read(ram,0x0c0c60dcu,4);
goto P_0c0c6046;
P_0c0c6046: /* original db24, guest PC 0x0c0c6046 */
if(!s->budget--) { s->failed_pc=0x0c0c6046u; return 0; }
r[11]=read(ram,0x0c0c60d8u,4);
goto P_0c0c6048;
P_0c0c6048: /* original 6ec3, guest PC 0x0c0c6048 */
if(!s->budget--) { s->failed_pc=0x0c0c6048u; return 0; }
r[14]=r[12];
goto P_0c0c604a;
P_0c0c604a: /* original 4e08, guest PC 0x0c0c604a */
if(!s->budget--) { s->failed_pc=0x0c0c604au; return 0; }
r[14]<<=2;
goto P_0c0c604c;
P_0c0c604c: /* original 4e00, guest PC 0x0c0c604c */
if(!s->budget--) { s->failed_pc=0x0c0c604cu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c0c604e;
P_0c0c604e: /* original 3eac, guest PC 0x0c0c604e */
if(!s->budget--) { s->failed_pc=0x0c0c604eu; return 0; }
r[14]+=r[10];
goto P_0c0c6050;
P_0c0c6050: /* original 53e1, guest PC 0x0c0c6050 */
if(!s->budget--) { s->failed_pc=0x0c0c6050u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0c6052;
P_0c0c6052: /* original 2338, guest PC 0x0c0c6052 */
if(!s->budget--) { s->failed_pc=0x0c0c6052u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c6054;
P_0c0c6054: /* original 892a, guest PC 0x0c0c6054 */
if(!s->budget--) { s->failed_pc=0x0c0c6054u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c60ac; }
goto P_0c0c6056;
P_0c0c6056: /* original 52e1, guest PC 0x0c0c6056 */
if(!s->budget--) { s->failed_pc=0x0c0c6056u; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0c6058;
P_0c0c6058: /* original 3420, guest PC 0x0c0c6058 */
if(!s->budget--) { s->failed_pc=0x0c0c6058u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c0c605a;
P_0c0c605a: /* original 8b25, guest PC 0x0c0c605a */
if(!s->budget--) { s->failed_pc=0x0c0c605au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c60a8; }
goto P_0c0c605c;
P_0c0c605c: /* original 61f2, guest PC 0x0c0c605c */
if(!s->budget--) { s->failed_pc=0x0c0c605cu; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0c605e;
P_0c0c605e: /* original 63e2, guest PC 0x0c0c605e */
if(!s->budget--) { s->failed_pc=0x0c0c605eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0c6060;
P_0c0c6060: /* original 6212, guest PC 0x0c0c6060 */
if(!s->budget--) { s->failed_pc=0x0c0c6060u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0c6062;
P_0c0c6062: /* original 3230, guest PC 0x0c0c6062 */
if(!s->budget--) { s->failed_pc=0x0c0c6062u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0c6064;
P_0c0c6064: /* original 891b, guest PC 0x0c0c6064 */
if(!s->budget--) { s->failed_pc=0x0c0c6064u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c609e; }
goto P_0c0c6066;
P_0c0c6066: /* original 65b2, guest PC 0x0c0c6066 */
if(!s->budget--) { s->failed_pc=0x0c0c6066u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0c6068;
P_0c0c6068: /* original d31d, guest PC 0x0c0c6068 */
if(!s->budget--) { s->failed_pc=0x0c0c6068u; return 0; }
r[3]=read(ram,0x0c0c60e0u,4);
goto P_0c0c606a;
P_0c0c606a: /* original 35dc, guest PC 0x0c0c606a */
if(!s->budget--) { s->failed_pc=0x0c0c606au; return 0; }
r[5]+=r[13];
goto P_0c0c606c;
P_0c0c606c: /* original 430b, guest PC 0x0c0c606c */
if(!s->budget--) { s->failed_pc=0x0c0c606cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6070u;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6070u) { target=s->pc; goto dispatch; }
goto P_0c0c6070;
P_0c0c606e: /* original 64e2, guest PC 0x0c0c606e */
if(!s->budget--) { s->failed_pc=0x0c0c606eu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0c6070;
P_0c0c6070: /* original d41c, guest PC 0x0c0c6070 */
if(!s->budget--) { s->failed_pc=0x0c0c6070u; return 0; }
r[4]=read(ram,0x0c0c60e4u,4);
goto P_0c0c6072;
P_0c0c6072: /* original be0f, guest PC 0x0c0c6072 */
if(!s->budget--) { s->failed_pc=0x0c0c6072u; return 0; }
target=code_base|0x0c0c5c94u; r[16]=code_base|0x0c0c6076u;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6076u) { target=s->pc; goto dispatch; }
goto P_0c0c6076;
P_0c0c6074: /* original e500, guest PC 0x0c0c6074 */
if(!s->budget--) { s->failed_pc=0x0c0c6074u; return 0; }
r[5]=0x00000000u;
goto P_0c0c6076;
P_0c0c6076: /* original d31c, guest PC 0x0c0c6076 */
if(!s->budget--) { s->failed_pc=0x0c0c6076u; return 0; }
r[3]=read(ram,0x0c0c60e8u,4);
goto P_0c0c6078;
P_0c0c6078: /* original 430b, guest PC 0x0c0c6078 */
if(!s->budget--) { s->failed_pc=0x0c0c6078u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c607cu;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c607cu) { target=s->pc; goto dispatch; }
goto P_0c0c607c;
P_0c0c607a: /* original e403, guest PC 0x0c0c607a */
if(!s->budget--) { s->failed_pc=0x0c0c607au; return 0; }
r[4]=0x00000003u;
goto P_0c0c607c;
P_0c0c607c: /* original d21b, guest PC 0x0c0c607c */
if(!s->budget--) { s->failed_pc=0x0c0c607cu; return 0; }
r[2]=read(ram,0x0c0c60ecu,4);
goto P_0c0c607e;
P_0c0c607e: /* original e503, guest PC 0x0c0c607e */
if(!s->budget--) { s->failed_pc=0x0c0c607eu; return 0; }
r[5]=0x00000003u;
goto P_0c0c6080;
P_0c0c6080: /* original 64b2, guest PC 0x0c0c6080 */
if(!s->budget--) { s->failed_pc=0x0c0c6080u; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c0c6082;
P_0c0c6082: /* original 420b, guest PC 0x0c0c6082 */
if(!s->budget--) { s->failed_pc=0x0c0c6082u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c6086u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6086u) { target=s->pc; goto dispatch; }
goto P_0c0c6086;
P_0c0c6084: /* original 34dc, guest PC 0x0c0c6084 */
if(!s->budget--) { s->failed_pc=0x0c0c6084u; return 0; }
r[4]+=r[13];
goto P_0c0c6086;
P_0c0c6086: /* original 2008, guest PC 0x0c0c6086 */
if(!s->budget--) { s->failed_pc=0x0c0c6086u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c6088;
P_0c0c6088: /* original 8903, guest PC 0x0c0c6088 */
if(!s->budget--) { s->failed_pc=0x0c0c6088u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6092; }
goto P_0c0c608a;
P_0c0c608a: /* original d219, guest PC 0x0c0c608a */
if(!s->budget--) { s->failed_pc=0x0c0c608au; return 0; }
r[2]=read(ram,0x0c0c60f0u,4);
goto P_0c0c608c;
P_0c0c608c: /* original 6593, guest PC 0x0c0c608c */
if(!s->budget--) { s->failed_pc=0x0c0c608cu; return 0; }
r[5]=r[9];
goto P_0c0c608e;
P_0c0c608e: /* original 420b, guest PC 0x0c0c608e */
if(!s->budget--) { s->failed_pc=0x0c0c608eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c6092u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6092u) { target=s->pc; goto dispatch; }
goto P_0c0c6092;
P_0c0c6090: /* original e401, guest PC 0x0c0c6090 */
if(!s->budget--) { s->failed_pc=0x0c0c6090u; return 0; }
r[4]=0x00000001u;
goto P_0c0c6092;
P_0c0c6092: /* original 4c08, guest PC 0x0c0c6092 */
if(!s->budget--) { s->failed_pc=0x0c0c6092u; return 0; }
r[12]<<=2;
goto P_0c0c6094;
P_0c0c6094: /* original 63f2, guest PC 0x0c0c6094 */
if(!s->budget--) { s->failed_pc=0x0c0c6094u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c6096;
P_0c0c6096: /* original 4c00, guest PC 0x0c0c6096 */
if(!s->budget--) { s->failed_pc=0x0c0c6096u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c0c6098;
P_0c0c6098: /* original 3cac, guest PC 0x0c0c6098 */
if(!s->budget--) { s->failed_pc=0x0c0c6098u; return 0; }
r[12]+=r[10];
goto P_0c0c609a;
P_0c0c609a: /* original 62c2, guest PC 0x0c0c609a */
if(!s->budget--) { s->failed_pc=0x0c0c609au; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c0c609c;
P_0c0c609c: /* original 2322, guest PC 0x0c0c609c */
if(!s->budget--) { s->failed_pc=0x0c0c609cu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0c609e;
P_0c0c609e: /* original 9011, guest PC 0x0c0c609e */
if(!s->budget--) { s->failed_pc=0x0c0c609eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c60c4u,2);
goto P_0c0c60a0;
P_0c0c60a0: /* original 53f1, guest PC 0x0c0c60a0 */
if(!s->budget--) { s->failed_pc=0x0c0c60a0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c60a2;
P_0c0c60a2: /* original 0386, guest PC 0x0c0c60a2 */
if(!s->budget--) { s->failed_pc=0x0c0c60a2u; return 0; }
write(ram,r[3]+r[0],r[8],4);
goto P_0c0c60a4;
P_0c0c60a4: /* original a002, guest PC 0x0c0c60a4 */
if(!s->budget--) { s->failed_pc=0x0c0c60a4u; return 0; }
goto P_0c0c60ac;
P_0c0c60a6: /* original 0009, guest PC 0x0c0c60a6 */
if(!s->budget--) { s->failed_pc=0x0c0c60a6u; return 0; }
goto P_0c0c60a8;
P_0c0c60a8: /* original afce, guest PC 0x0c0c60a8 */
if(!s->budget--) { s->failed_pc=0x0c0c60a8u; return 0; }
r[12]+=0x00000001u;
goto P_0c0c6048;
P_0c0c60aa: /* original 7c01, guest PC 0x0c0c60aa */
if(!s->budget--) { s->failed_pc=0x0c0c60aau; return 0; }
r[12]+=0x00000001u;
goto P_0c0c60ac;
P_0c0c60ac: /* original 7f08, guest PC 0x0c0c60ac */
if(!s->budget--) { s->failed_pc=0x0c0c60acu; return 0; }
r[15]+=0x00000008u;
goto P_0c0c60ae;
P_0c0c60ae: /* original 4f26, guest PC 0x0c0c60ae */
if(!s->budget--) { s->failed_pc=0x0c0c60aeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c60b0;
P_0c0c60b0: /* original 68f6, guest PC 0x0c0c60b0 */
if(!s->budget--) { s->failed_pc=0x0c0c60b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c60b2;
P_0c0c60b2: /* original 69f6, guest PC 0x0c0c60b2 */
if(!s->budget--) { s->failed_pc=0x0c0c60b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c60b4;
P_0c0c60b4: /* original 6af6, guest PC 0x0c0c60b4 */
if(!s->budget--) { s->failed_pc=0x0c0c60b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c60b6;
P_0c0c60b6: /* original 6bf6, guest PC 0x0c0c60b6 */
if(!s->budget--) { s->failed_pc=0x0c0c60b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c60b8;
P_0c0c60b8: /* original 6cf6, guest PC 0x0c0c60b8 */
if(!s->budget--) { s->failed_pc=0x0c0c60b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c60ba;
P_0c0c60ba: /* original 6df6, guest PC 0x0c0c60ba */
if(!s->budget--) { s->failed_pc=0x0c0c60bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c60bc;
P_0c0c60bc: /* original 000b, guest PC 0x0c0c60bc */
if(!s->budget--) { s->failed_pc=0x0c0c60bcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c60be: /* original 6ef6, guest PC 0x0c0c60be */
if(!s->budget--) { s->failed_pc=0x0c0c60beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c60c0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c60c0u; return 0; } return 1;
P_0c0c66b8: /* original 000b, guest PC 0x0c0c66b8 */
if(!s->budget--) { s->failed_pc=0x0c0c66b8u; return 0; }
target=r[16];
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c66ba: /* original 6040, guest PC 0x0c0c66ba */
if(!s->budget--) { s->failed_pc=0x0c0c66bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
if(!vf3_matrix_family(0x0c0c66bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66bcu; return 0; } return 1;
P_0c0c66c0: /* original 000b, guest PC 0x0c0c66c0 */
if(!s->budget--) { s->failed_pc=0x0c0c66c0u; return 0; }
target=r[16];
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c66c2: /* original 6041, guest PC 0x0c0c66c2 */
if(!s->budget--) { s->failed_pc=0x0c0c66c2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
if(!vf3_matrix_family(0x0c0c66c4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66c4u; return 0; } return 1;
P_0c0c6742: /* original 9049, guest PC 0x0c0c6742 */
if(!s->budget--) { s->failed_pc=0x0c0c6742u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c67d8u,2);
goto P_0c0c6744;
P_0c0c6744: /* original d426, guest PC 0x0c0c6744 */
if(!s->budget--) { s->failed_pc=0x0c0c6744u; return 0; }
r[4]=read(ram,0x0c0c67e0u,4);
goto P_0c0c6746;
P_0c0c6746: /* original 000b, guest PC 0x0c0c6746 */
if(!s->budget--) { s->failed_pc=0x0c0c6746u; return 0; }
target=r[16];
r[0]=read(ram,r[4]+r[0],4);
s->pc=target; return ram->oob==0;
P_0c0c6748: /* original 004e, guest PC 0x0c0c6748 */
if(!s->budget--) { s->failed_pc=0x0c0c6748u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
if(!vf3_matrix_family(0x0c0c674au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c674au; return 0; } return 1;
P_0c0c70a4: /* original d413, guest PC 0x0c0c70a4 */
if(!s->budget--) { s->failed_pc=0x0c0c70a4u; return 0; }
r[4]=read(ram,0x0c0c70f4u,4);
goto P_0c0c70a6;
P_0c0c70a6: /* original e01c, guest PC 0x0c0c70a6 */
if(!s->budget--) { s->failed_pc=0x0c0c70a6u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c70a8;
P_0c0c70a8: /* original e50f, guest PC 0x0c0c70a8 */
if(!s->budget--) { s->failed_pc=0x0c0c70a8u; return 0; }
r[5]=0x0000000fu;
goto P_0c0c70aa;
P_0c0c70aa: /* original 044c, guest PC 0x0c0c70aa */
if(!s->budget--) { s->failed_pc=0x0c0c70aau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c70ac;
P_0c0c70ac: /* original d012, guest PC 0x0c0c70ac */
if(!s->budget--) { s->failed_pc=0x0c0c70acu; return 0; }
r[0]=read(ram,0x0c0c70f8u,4);
goto P_0c0c70ae;
P_0c0c70ae: /* original 644c, guest PC 0x0c0c70ae */
if(!s->budget--) { s->failed_pc=0x0c0c70aeu; return 0; }
r[4]=r[4]&255u;
goto P_0c0c70b0;
P_0c0c70b0: /* original 2459, guest PC 0x0c0c70b0 */
if(!s->budget--) { s->failed_pc=0x0c0c70b0u; return 0; }
r[4]&=r[5];
goto P_0c0c70b2;
P_0c0c70b2: /* original 4408, guest PC 0x0c0c70b2 */
if(!s->budget--) { s->failed_pc=0x0c0c70b2u; return 0; }
r[4]<<=2;
goto P_0c0c70b4;
P_0c0c70b4: /* original 4408, guest PC 0x0c0c70b4 */
if(!s->budget--) { s->failed_pc=0x0c0c70b4u; return 0; }
r[4]<<=2;
goto P_0c0c70b6;
P_0c0c70b6: /* original 4408, guest PC 0x0c0c70b6 */
if(!s->budget--) { s->failed_pc=0x0c0c70b6u; return 0; }
r[4]<<=2;
goto P_0c0c70b8;
P_0c0c70b8: /* original 044c, guest PC 0x0c0c70b8 */
if(!s->budget--) { s->failed_pc=0x0c0c70b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c70ba;
P_0c0c70ba: /* original 644c, guest PC 0x0c0c70ba */
if(!s->budget--) { s->failed_pc=0x0c0c70bau; return 0; }
r[4]=r[4]&255u;
goto P_0c0c70bc;
P_0c0c70bc: /* original 3457, guest PC 0x0c0c70bc */
if(!s->budget--) { s->failed_pc=0x0c0c70bcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[5])!=0);
goto P_0c0c70be;
P_0c0c70be: /* original 8b01, guest PC 0x0c0c70be */
if(!s->budget--) { s->failed_pc=0x0c0c70beu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c70c4; }
goto P_0c0c70c0;
P_0c0c70c0: /* original a003, guest PC 0x0c0c70c0 */
if(!s->budget--) { s->failed_pc=0x0c0c70c0u; return 0; }
r[4]=r[5];
goto P_0c0c70ca;
P_0c0c70c2: /* original 6453, guest PC 0x0c0c70c2 */
if(!s->budget--) { s->failed_pc=0x0c0c70c2u; return 0; }
r[4]=r[5];
goto P_0c0c70c4;
P_0c0c70c4: /* original 4411, guest PC 0x0c0c70c4 */
if(!s->budget--) { s->failed_pc=0x0c0c70c4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c70c6;
P_0c0c70c6: /* original 8900, guest PC 0x0c0c70c6 */
if(!s->budget--) { s->failed_pc=0x0c0c70c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c70ca; }
goto P_0c0c70c8;
P_0c0c70c8: /* original e400, guest PC 0x0c0c70c8 */
if(!s->budget--) { s->failed_pc=0x0c0c70c8u; return 0; }
r[4]=0x00000000u;
goto P_0c0c70ca;
P_0c0c70ca: /* original d20c, guest PC 0x0c0c70ca */
if(!s->budget--) { s->failed_pc=0x0c0c70cau; return 0; }
r[2]=read(ram,0x0c0c70fcu,4);
goto P_0c0c70cc;
P_0c0c70cc: /* original 4400, guest PC 0x0c0c70cc */
if(!s->budget--) { s->failed_pc=0x0c0c70ccu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0c70ce;
P_0c0c70ce: /* original d60c, guest PC 0x0c0c70ce */
if(!s->budget--) { s->failed_pc=0x0c0c70ceu; return 0; }
r[6]=read(ram,0x0c0c7100u,4);
goto P_0c0c70d0;
P_0c0c70d0: /* original 6043, guest PC 0x0c0c70d0 */
if(!s->budget--) { s->failed_pc=0x0c0c70d0u; return 0; }
r[0]=r[4];
goto P_0c0c70d2;
P_0c0c70d2: /* original 910a, guest PC 0x0c0c70d2 */
if(!s->budget--) { s->failed_pc=0x0c0c70d2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c70eau,2);
goto P_0c0c70d4;
P_0c0c70d4: /* original 6522, guest PC 0x0c0c70d4 */
if(!s->budget--) { s->failed_pc=0x0c0c70d4u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c0c70d6;
P_0c0c70d6: /* original 036c, guest PC 0x0c0c70d6 */
if(!s->budget--) { s->failed_pc=0x0c0c70d6u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0c70d8;
P_0c0c70d8: /* original 7001, guest PC 0x0c0c70d8 */
if(!s->budget--) { s->failed_pc=0x0c0c70d8u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c70da;
P_0c0c70da: /* original 315c, guest PC 0x0c0c70da */
if(!s->budget--) { s->failed_pc=0x0c0c70dau; return 0; }
r[1]+=r[5];
goto P_0c0c70dc;
P_0c0c70dc: /* original 2130, guest PC 0x0c0c70dc */
if(!s->budget--) { s->failed_pc=0x0c0c70dcu; return 0; }
write(ram,r[1],r[3],1);
goto P_0c0c70de;
P_0c0c70de: /* original 036c, guest PC 0x0c0c70de */
if(!s->budget--) { s->failed_pc=0x0c0c70deu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0c70e0;
P_0c0c70e0: /* original 9004, guest PC 0x0c0c70e0 */
if(!s->budget--) { s->failed_pc=0x0c0c70e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c70ecu,2);
goto P_0c0c70e2;
P_0c0c70e2: /* original 000b, guest PC 0x0c0c70e2 */
if(!s->budget--) { s->failed_pc=0x0c0c70e2u; return 0; }
target=r[16];
write(ram,r[5]+r[0],r[3],1);
s->pc=target; return ram->oob==0;
P_0c0c70e4: /* original 0534, guest PC 0x0c0c70e4 */
if(!s->budget--) { s->failed_pc=0x0c0c70e4u; return 0; }
write(ram,r[5]+r[0],r[3],1);
if(!vf3_matrix_family(0x0c0c70e6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c70e6u; return 0; } return 1;
P_0c0c7648: /* original 2fe6, guest PC 0x0c0c7648 */
if(!s->budget--) { s->failed_pc=0x0c0c7648u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c764a;
P_0c0c764a: /* original 2fd6, guest PC 0x0c0c764a */
if(!s->budget--) { s->failed_pc=0x0c0c764au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c764c;
P_0c0c764c: /* original 2fc6, guest PC 0x0c0c764c */
if(!s->budget--) { s->failed_pc=0x0c0c764cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c764e;
P_0c0c764e: /* original 2fb6, guest PC 0x0c0c764e */
if(!s->budget--) { s->failed_pc=0x0c0c764eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7650;
P_0c0c7650: /* original 2fa6, guest PC 0x0c0c7650 */
if(!s->budget--) { s->failed_pc=0x0c0c7650u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7652;
P_0c0c7652: /* original 2f96, guest PC 0x0c0c7652 */
if(!s->budget--) { s->failed_pc=0x0c0c7652u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7654;
P_0c0c7654: /* original da40, guest PC 0x0c0c7654 */
if(!s->budget--) { s->failed_pc=0x0c0c7654u; return 0; }
r[10]=read(ram,0x0c0c7758u,4);
goto P_0c0c7656;
P_0c0c7656: /* original 9077, guest PC 0x0c0c7656 */
if(!s->budget--) { s->failed_pc=0x0c0c7656u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7748u,2);
goto P_0c0c7658;
P_0c0c7658: /* original 4f22, guest PC 0x0c0c7658 */
if(!s->budget--) { s->failed_pc=0x0c0c7658u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c765a;
P_0c0c765a: /* original 0cae, guest PC 0x0c0c765a */
if(!s->budget--) { s->failed_pc=0x0c0c765au; return 0; }
r[12]=read(ram,r[10]+r[0],4);
goto P_0c0c765c;
P_0c0c765c: /* original 7004, guest PC 0x0c0c765c */
if(!s->budget--) { s->failed_pc=0x0c0c765cu; return 0; }
r[0]+=0x00000004u;
goto P_0c0c765e;
P_0c0c765e: /* original dd3f, guest PC 0x0c0c765e */
if(!s->budget--) { s->failed_pc=0x0c0c765eu; return 0; }
r[13]=read(ram,0x0c0c775cu,4);
goto P_0c0c7660;
P_0c0c7660: /* original 2cc8, guest PC 0x0c0c7660 */
if(!s->budget--) { s->failed_pc=0x0c0c7660u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0c7662;
P_0c0c7662: /* original 8d0e, guest PC 0x0c0c7662 */
if(!s->budget--) { s->failed_pc=0x0c0c7662u; return 0; }
cond=r[17]&1u;
r[11]=read(ram,r[10]+r[0],4);
if(cond) { goto P_0c0c7682; }
goto P_0c0c7666;
P_0c0c7664: /* original 0bae, guest PC 0x0c0c7664 */
if(!s->budget--) { s->failed_pc=0x0c0c7664u; return 0; }
r[11]=read(ram,r[10]+r[0],4);
goto P_0c0c7666;
P_0c0c7666: /* original 85c6, guest PC 0x0c0c7666 */
if(!s->budget--) { s->failed_pc=0x0c0c7666u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+12,2);
goto P_0c0c7668;
P_0c0c7668: /* original 996f, guest PC 0x0c0c7668 */
if(!s->budget--) { s->failed_pc=0x0c0c7668u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c774au,2);
goto P_0c0c766a;
P_0c0c766a: /* original 6e0d, guest PC 0x0c0c766a */
if(!s->budget--) { s->failed_pc=0x0c0c766au; return 0; }
r[14]=r[0]&65535u;
goto P_0c0c766c;
P_0c0c766c: /* original 4e15, guest PC 0x0c0c766c */
if(!s->budget--) { s->failed_pc=0x0c0c766cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c766e;
P_0c0c766e: /* original 8b05, guest PC 0x0c0c766e */
if(!s->budget--) { s->failed_pc=0x0c0c766eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c767c; }
goto P_0c0c7670;
P_0c0c7670: /* original 6493, guest PC 0x0c0c7670 */
if(!s->budget--) { s->failed_pc=0x0c0c7670u; return 0; }
r[4]=r[9];
goto P_0c0c7672;
P_0c0c7672: /* original 4d0b, guest PC 0x0c0c7672 */
if(!s->budget--) { s->failed_pc=0x0c0c7672u; return 0; }
target=r[13];
r[16]=code_base|0x0c0c7676u;
r[9]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7676u) { target=s->pc; goto dispatch; }
goto P_0c0c7676;
P_0c0c7674: /* original 7901, guest PC 0x0c0c7674 */
if(!s->budget--) { s->failed_pc=0x0c0c7674u; return 0; }
r[9]+=0x00000001u;
goto P_0c0c7676;
P_0c0c7676: /* original 7eff, guest PC 0x0c0c7676 */
if(!s->budget--) { s->failed_pc=0x0c0c7676u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0c7678;
P_0c0c7678: /* original 4e15, guest PC 0x0c0c7678 */
if(!s->budget--) { s->failed_pc=0x0c0c7678u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c767a;
P_0c0c767a: /* original 89f9, guest PC 0x0c0c767a */
if(!s->budget--) { s->failed_pc=0x0c0c767au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7670; }
goto P_0c0c767c;
P_0c0c767c: /* original d338, guest PC 0x0c0c767c */
if(!s->budget--) { s->failed_pc=0x0c0c767cu; return 0; }
r[3]=read(ram,0x0c0c7760u,4);
goto P_0c0c767e;
P_0c0c767e: /* original 430b, guest PC 0x0c0c767e */
if(!s->budget--) { s->failed_pc=0x0c0c767eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7682u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7682u) { target=s->pc; goto dispatch; }
goto P_0c0c7682;
P_0c0c7680: /* original 64c3, guest PC 0x0c0c7680 */
if(!s->budget--) { s->failed_pc=0x0c0c7680u; return 0; }
r[4]=r[12];
goto P_0c0c7682;
P_0c0c7682: /* original 2bb8, guest PC 0x0c0c7682 */
if(!s->budget--) { s->failed_pc=0x0c0c7682u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0c7684;
P_0c0c7684: /* original 890d, guest PC 0x0c0c7684 */
if(!s->budget--) { s->failed_pc=0x0c0c7684u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c76a2; }
goto P_0c0c7686;
P_0c0c7686: /* original 85b6, guest PC 0x0c0c7686 */
if(!s->budget--) { s->failed_pc=0x0c0c7686u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+12,2);
goto P_0c0c7688;
P_0c0c7688: /* original 9c60, guest PC 0x0c0c7688 */
if(!s->budget--) { s->failed_pc=0x0c0c7688u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c774cu,2);
goto P_0c0c768a;
P_0c0c768a: /* original 6e0d, guest PC 0x0c0c768a */
if(!s->budget--) { s->failed_pc=0x0c0c768au; return 0; }
r[14]=r[0]&65535u;
goto P_0c0c768c;
P_0c0c768c: /* original 4e15, guest PC 0x0c0c768c */
if(!s->budget--) { s->failed_pc=0x0c0c768cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c768e;
P_0c0c768e: /* original 8b05, guest PC 0x0c0c768e */
if(!s->budget--) { s->failed_pc=0x0c0c768eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c769c; }
goto P_0c0c7690;
P_0c0c7690: /* original 64c3, guest PC 0x0c0c7690 */
if(!s->budget--) { s->failed_pc=0x0c0c7690u; return 0; }
r[4]=r[12];
goto P_0c0c7692;
P_0c0c7692: /* original 4d0b, guest PC 0x0c0c7692 */
if(!s->budget--) { s->failed_pc=0x0c0c7692u; return 0; }
target=r[13];
r[16]=code_base|0x0c0c7696u;
r[12]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7696u) { target=s->pc; goto dispatch; }
goto P_0c0c7696;
P_0c0c7694: /* original 7c01, guest PC 0x0c0c7694 */
if(!s->budget--) { s->failed_pc=0x0c0c7694u; return 0; }
r[12]+=0x00000001u;
goto P_0c0c7696;
P_0c0c7696: /* original 7eff, guest PC 0x0c0c7696 */
if(!s->budget--) { s->failed_pc=0x0c0c7696u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0c7698;
P_0c0c7698: /* original 4e15, guest PC 0x0c0c7698 */
if(!s->budget--) { s->failed_pc=0x0c0c7698u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c769a;
P_0c0c769a: /* original 89f9, guest PC 0x0c0c769a */
if(!s->budget--) { s->failed_pc=0x0c0c769au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7690; }
goto P_0c0c769c;
P_0c0c769c: /* original d330, guest PC 0x0c0c769c */
if(!s->budget--) { s->failed_pc=0x0c0c769cu; return 0; }
r[3]=read(ram,0x0c0c7760u,4);
goto P_0c0c769e;
P_0c0c769e: /* original 430b, guest PC 0x0c0c769e */
if(!s->budget--) { s->failed_pc=0x0c0c769eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c76a2u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c76a2u) { target=s->pc; goto dispatch; }
goto P_0c0c76a2;
P_0c0c76a0: /* original 64b3, guest PC 0x0c0c76a0 */
if(!s->budget--) { s->failed_pc=0x0c0c76a0u; return 0; }
r[4]=r[11];
goto P_0c0c76a2;
P_0c0c76a2: /* original 9054, guest PC 0x0c0c76a2 */
if(!s->budget--) { s->failed_pc=0x0c0c76a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c774eu,2);
goto P_0c0c76a4;
P_0c0c76a4: /* original e400, guest PC 0x0c0c76a4 */
if(!s->budget--) { s->failed_pc=0x0c0c76a4u; return 0; }
r[4]=0x00000000u;
goto P_0c0c76a6;
P_0c0c76a6: /* original 4f26, guest PC 0x0c0c76a6 */
if(!s->budget--) { s->failed_pc=0x0c0c76a6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c76a8;
P_0c0c76a8: /* original 0a46, guest PC 0x0c0c76a8 */
if(!s->budget--) { s->failed_pc=0x0c0c76a8u; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c0c76aa;
P_0c0c76aa: /* original 70f8, guest PC 0x0c0c76aa */
if(!s->budget--) { s->failed_pc=0x0c0c76aau; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c76ac;
P_0c0c76ac: /* original 0a46, guest PC 0x0c0c76ac */
if(!s->budget--) { s->failed_pc=0x0c0c76acu; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c0c76ae;
P_0c0c76ae: /* original 7004, guest PC 0x0c0c76ae */
if(!s->budget--) { s->failed_pc=0x0c0c76aeu; return 0; }
r[0]+=0x00000004u;
goto P_0c0c76b0;
P_0c0c76b0: /* original 0a46, guest PC 0x0c0c76b0 */
if(!s->budget--) { s->failed_pc=0x0c0c76b0u; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c0c76b2;
P_0c0c76b2: /* original 69f6, guest PC 0x0c0c76b2 */
if(!s->budget--) { s->failed_pc=0x0c0c76b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c76b4;
P_0c0c76b4: /* original 6af6, guest PC 0x0c0c76b4 */
if(!s->budget--) { s->failed_pc=0x0c0c76b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c76b6;
P_0c0c76b6: /* original 6bf6, guest PC 0x0c0c76b6 */
if(!s->budget--) { s->failed_pc=0x0c0c76b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c76b8;
P_0c0c76b8: /* original 6cf6, guest PC 0x0c0c76b8 */
if(!s->budget--) { s->failed_pc=0x0c0c76b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c76ba;
P_0c0c76ba: /* original 6df6, guest PC 0x0c0c76ba */
if(!s->budget--) { s->failed_pc=0x0c0c76bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c76bc;
P_0c0c76bc: /* original 000b, guest PC 0x0c0c76bc */
if(!s->budget--) { s->failed_pc=0x0c0c76bcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c76be: /* original 6ef6, guest PC 0x0c0c76be */
if(!s->budget--) { s->failed_pc=0x0c0c76beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c76c0;
P_0c0c76c0: /* original 2fe6, guest PC 0x0c0c76c0 */
if(!s->budget--) { s->failed_pc=0x0c0c76c0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c76c2;
P_0c0c76c2: /* original e01c, guest PC 0x0c0c76c2 */
if(!s->budget--) { s->failed_pc=0x0c0c76c2u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c76c4;
P_0c0c76c4: /* original 2fd6, guest PC 0x0c0c76c4 */
if(!s->budget--) { s->failed_pc=0x0c0c76c4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c76c6;
P_0c0c76c6: /* original 2fc6, guest PC 0x0c0c76c6 */
if(!s->budget--) { s->failed_pc=0x0c0c76c6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c76c8;
P_0c0c76c8: /* original ec0f, guest PC 0x0c0c76c8 */
if(!s->budget--) { s->failed_pc=0x0c0c76c8u; return 0; }
r[12]=0x0000000fu;
goto P_0c0c76ca;
P_0c0c76ca: /* original 2fb6, guest PC 0x0c0c76ca */
if(!s->budget--) { s->failed_pc=0x0c0c76cau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c76cc;
P_0c0c76cc: /* original 2fa6, guest PC 0x0c0c76cc */
if(!s->budget--) { s->failed_pc=0x0c0c76ccu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c76ce;
P_0c0c76ce: /* original 2f96, guest PC 0x0c0c76ce */
if(!s->budget--) { s->failed_pc=0x0c0c76ceu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c76d0;
P_0c0c76d0: /* original 2f86, guest PC 0x0c0c76d0 */
if(!s->budget--) { s->failed_pc=0x0c0c76d0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c76d2;
P_0c0c76d2: /* original de21, guest PC 0x0c0c76d2 */
if(!s->budget--) { s->failed_pc=0x0c0c76d2u; return 0; }
r[14]=read(ram,0x0c0c7758u,4);
goto P_0c0c76d4;
P_0c0c76d4: /* original 4f22, guest PC 0x0c0c76d4 */
if(!s->budget--) { s->failed_pc=0x0c0c76d4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c76d6;
P_0c0c76d6: /* original 09ec, guest PC 0x0c0c76d6 */
if(!s->budget--) { s->failed_pc=0x0c0c76d6u; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c76d8;
P_0c0c76d8: /* original d024, guest PC 0x0c0c76d8 */
if(!s->budget--) { s->failed_pc=0x0c0c76d8u; return 0; }
r[0]=read(ram,0x0c0c776cu,4);
goto P_0c0c76da;
P_0c0c76da: /* original 699c, guest PC 0x0c0c76da */
if(!s->budget--) { s->failed_pc=0x0c0c76dau; return 0; }
r[9]=r[9]&255u;
goto P_0c0c76dc;
P_0c0c76dc: /* original d322, guest PC 0x0c0c76dc */
if(!s->budget--) { s->failed_pc=0x0c0c76dcu; return 0; }
r[3]=read(ram,0x0c0c7768u,4);
goto P_0c0c76de;
P_0c0c76de: /* original 2c99, guest PC 0x0c0c76de */
if(!s->budget--) { s->failed_pc=0x0c0c76deu; return 0; }
r[12]&=r[9];
goto P_0c0c76e0;
P_0c0c76e0: /* original db20, guest PC 0x0c0c76e0 */
if(!s->budget--) { s->failed_pc=0x0c0c76e0u; return 0; }
r[11]=read(ram,0x0c0c7764u,4);
goto P_0c0c76e2;
P_0c0c76e2: /* original 4c08, guest PC 0x0c0c76e2 */
if(!s->budget--) { s->failed_pc=0x0c0c76e2u; return 0; }
r[12]<<=2;
goto P_0c0c76e4;
P_0c0c76e4: /* original 4c00, guest PC 0x0c0c76e4 */
if(!s->budget--) { s->failed_pc=0x0c0c76e4u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c0c76e6;
P_0c0c76e6: /* original 00ce, guest PC 0x0c0c76e6 */
if(!s->budget--) { s->failed_pc=0x0c0c76e6u; return 0; }
r[0]=read(ram,r[12]+r[0],4);
goto P_0c0c76e8;
P_0c0c76e8: /* original 7ffc, guest PC 0x0c0c76e8 */
if(!s->budget--) { s->failed_pc=0x0c0c76e8u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c76ea;
P_0c0c76ea: /* original 88ff, guest PC 0x0c0c76ea */
if(!s->budget--) { s->failed_pc=0x0c0c76eau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c76ec;
P_0c0c76ec: /* original 8d44, guest PC 0x0c0c76ec */
if(!s->budget--) { s->failed_pc=0x0c0c76ecu; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[3],4);
r[4]=tmp;
if(cond) { goto P_0c0c7778; }
goto P_0c0c76f0;
P_0c0c76ee: /* original 6432, guest PC 0x0c0c76ee */
if(!s->budget--) { s->failed_pc=0x0c0c76eeu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0c76f0;
P_0c0c76f0: /* original 902e, guest PC 0x0c0c76f0 */
if(!s->budget--) { s->failed_pc=0x0c0c76f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7750u,2);
goto P_0c0c76f2;
P_0c0c76f2: /* original 0e46, guest PC 0x0c0c76f2 */
if(!s->budget--) { s->failed_pc=0x0c0c76f2u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c76f4;
P_0c0c76f4: /* original d51d, guest PC 0x0c0c76f4 */
if(!s->budget--) { s->failed_pc=0x0c0c76f4u; return 0; }
r[5]=read(ram,0x0c0c776cu,4);
goto P_0c0c76f6;
P_0c0c76f6: /* original d21e, guest PC 0x0c0c76f6 */
if(!s->budget--) { s->failed_pc=0x0c0c76f6u; return 0; }
r[2]=read(ram,0x0c0c7770u,4);
goto P_0c0c76f8;
P_0c0c76f8: /* original 35cc, guest PC 0x0c0c76f8 */
if(!s->budget--) { s->failed_pc=0x0c0c76f8u; return 0; }
r[5]+=r[12];
goto P_0c0c76fa;
P_0c0c76fa: /* original 0aee, guest PC 0x0c0c76fa */
if(!s->budget--) { s->failed_pc=0x0c0c76fau; return 0; }
r[10]=read(ram,r[14]+r[0],4);
goto P_0c0c76fc;
P_0c0c76fc: /* original 6721, guest PC 0x0c0c76fc */
if(!s->budget--) { s->failed_pc=0x0c0c76fcu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[7]=tmp;
goto P_0c0c76fe;
P_0c0c76fe: /* original 2f52, guest PC 0x0c0c76fe */
if(!s->budget--) { s->failed_pc=0x0c0c76feu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c7700;
P_0c0c7700: /* original 66a3, guest PC 0x0c0c7700 */
if(!s->budget--) { s->failed_pc=0x0c0c7700u; return 0; }
r[6]=r[10];
goto P_0c0c7702;
P_0c0c7702: /* original 64f2, guest PC 0x0c0c7702 */
if(!s->budget--) { s->failed_pc=0x0c0c7702u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c7704;
P_0c0c7704: /* original 5551, guest PC 0x0c0c7704 */
if(!s->budget--) { s->failed_pc=0x0c0c7704u; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c0c7706;
P_0c0c7706: /* original d31b, guest PC 0x0c0c7706 */
if(!s->budget--) { s->failed_pc=0x0c0c7706u; return 0; }
r[3]=read(ram,0x0c0c7774u,4);
goto P_0c0c7708;
P_0c0c7708: /* original 430b, guest PC 0x0c0c7708 */
if(!s->budget--) { s->failed_pc=0x0c0c7708u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c770cu;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c770cu) { target=s->pc; goto dispatch; }
goto P_0c0c770c;
P_0c0c770a: /* original 6442, guest PC 0x0c0c770a */
if(!s->budget--) { s->failed_pc=0x0c0c770au; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c770c;
P_0c0c770c: /* original 52a4, guest PC 0x0c0c770c */
if(!s->budget--) { s->failed_pc=0x0c0c770cu; return 0; }
r[2]=read(ram,r[10]+16,4);
goto P_0c0c770e;
P_0c0c770e: /* original 2f22, guest PC 0x0c0c770e */
if(!s->budget--) { s->failed_pc=0x0c0c770eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c7710;
P_0c0c7710: /* original 981c, guest PC 0x0c0c7710 */
if(!s->budget--) { s->failed_pc=0x0c0c7710u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c774cu,2);
goto P_0c0c7712;
P_0c0c7712: /* original a008, guest PC 0x0c0c7712 */
if(!s->budget--) { s->failed_pc=0x0c0c7712u; return 0; }
r[13]=0x00000000u;
goto P_0c0c7726;
P_0c0c7714: /* original ed00, guest PC 0x0c0c7714 */
if(!s->budget--) { s->failed_pc=0x0c0c7714u; return 0; }
r[13]=0x00000000u;
goto P_0c0c7716;
P_0c0c7716: /* original 60f2, guest PC 0x0c0c7716 */
if(!s->budget--) { s->failed_pc=0x0c0c7716u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0c7718;
P_0c0c7718: /* original 65d3, guest PC 0x0c0c7718 */
if(!s->budget--) { s->failed_pc=0x0c0c7718u; return 0; }
r[5]=r[13];
goto P_0c0c771a;
P_0c0c771a: /* original 4508, guest PC 0x0c0c771a */
if(!s->budget--) { s->failed_pc=0x0c0c771au; return 0; }
r[5]<<=2;
goto P_0c0c771c;
P_0c0c771c: /* original 6483, guest PC 0x0c0c771c */
if(!s->budget--) { s->failed_pc=0x0c0c771cu; return 0; }
r[4]=r[8];
goto P_0c0c771e;
P_0c0c771e: /* original 055e, guest PC 0x0c0c771e */
if(!s->budget--) { s->failed_pc=0x0c0c771eu; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c0c7720;
P_0c0c7720: /* original 4b0b, guest PC 0x0c0c7720 */
if(!s->budget--) { s->failed_pc=0x0c0c7720u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c7724u;
r[8]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7724u) { target=s->pc; goto dispatch; }
goto P_0c0c7724;
P_0c0c7722: /* original 7801, guest PC 0x0c0c7722 */
if(!s->budget--) { s->failed_pc=0x0c0c7722u; return 0; }
r[8]+=0x00000001u;
goto P_0c0c7724;
P_0c0c7724: /* original 7d01, guest PC 0x0c0c7724 */
if(!s->budget--) { s->failed_pc=0x0c0c7724u; return 0; }
r[13]+=0x00000001u;
goto P_0c0c7726;
P_0c0c7726: /* original 85a6, guest PC 0x0c0c7726 */
if(!s->budget--) { s->failed_pc=0x0c0c7726u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+12,2);
goto P_0c0c7728;
P_0c0c7728: /* original 600d, guest PC 0x0c0c7728 */
if(!s->budget--) { s->failed_pc=0x0c0c7728u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c772a;
P_0c0c772a: /* original 3d03, guest PC 0x0c0c772a */
if(!s->budget--) { s->failed_pc=0x0c0c772au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[0])!=0);
goto P_0c0c772c;
P_0c0c772c: /* original 8bf3, guest PC 0x0c0c772c */
if(!s->budget--) { s->failed_pc=0x0c0c772cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7716; }
goto P_0c0c772e;
P_0c0c772e: /* original 900f, guest PC 0x0c0c772e */
if(!s->budget--) { s->failed_pc=0x0c0c772eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7750u,2);
goto P_0c0c7730;
P_0c0c7730: /* original 53a6, guest PC 0x0c0c7730 */
if(!s->budget--) { s->failed_pc=0x0c0c7730u; return 0; }
r[3]=read(ram,r[10]+24,4);
goto P_0c0c7732;
P_0c0c7732: /* original 02ee, guest PC 0x0c0c7732 */
if(!s->budget--) { s->failed_pc=0x0c0c7732u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0c7734;
P_0c0c7734: /* original 7004, guest PC 0x0c0c7734 */
if(!s->budget--) { s->failed_pc=0x0c0c7734u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c7736;
P_0c0c7736: /* original 910c, guest PC 0x0c0c7736 */
if(!s->budget--) { s->failed_pc=0x0c0c7736u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7752u,2);
goto P_0c0c7738;
P_0c0c7738: /* original 323c, guest PC 0x0c0c7738 */
if(!s->budget--) { s->failed_pc=0x0c0c7738u; return 0; }
r[2]+=r[3];
goto P_0c0c773a;
P_0c0c773a: /* original 930b, guest PC 0x0c0c773a */
if(!s->budget--) { s->failed_pc=0x0c0c773au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7754u,2);
goto P_0c0c773c;
P_0c0c773c: /* original 321c, guest PC 0x0c0c773c */
if(!s->budget--) { s->failed_pc=0x0c0c773cu; return 0; }
r[2]+=r[1];
goto P_0c0c773e;
P_0c0c773e: /* original 2239, guest PC 0x0c0c773e */
if(!s->budget--) { s->failed_pc=0x0c0c773eu; return 0; }
r[2]&=r[3];
goto P_0c0c7740;
P_0c0c7740: /* original 0e26, guest PC 0x0c0c7740 */
if(!s->budget--) { s->failed_pc=0x0c0c7740u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c7742;
P_0c0c7742: /* original 70f8, guest PC 0x0c0c7742 */
if(!s->budget--) { s->failed_pc=0x0c0c7742u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c7744;
P_0c0c7744: /* original a01a, guest PC 0x0c0c7744 */
if(!s->budget--) { s->failed_pc=0x0c0c7744u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c777c;
P_0c0c7746: /* original 0e26, guest PC 0x0c0c7746 */
if(!s->budget--) { s->failed_pc=0x0c0c7746u; return 0; }
write(ram,r[14]+r[0],r[2],4);
if(!vf3_matrix_family(0x0c0c7748u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c7748u; return 0; } return 1;
P_0c0c7778: /* original 9071, guest PC 0x0c0c7778 */
if(!s->budget--) { s->failed_pc=0x0c0c7778u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c785eu,2);
goto P_0c0c777a;
P_0c0c777a: /* original 0e46, guest PC 0x0c0c777a */
if(!s->budget--) { s->failed_pc=0x0c0c777au; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c777c;
P_0c0c777c: /* original d03a, guest PC 0x0c0c777c */
if(!s->budget--) { s->failed_pc=0x0c0c777cu; return 0; }
r[0]=read(ram,0x0c0c7868u,4);
goto P_0c0c777e;
P_0c0c777e: /* original 00ce, guest PC 0x0c0c777e */
if(!s->budget--) { s->failed_pc=0x0c0c777eu; return 0; }
r[0]=read(ram,r[12]+r[0],4);
goto P_0c0c7780;
P_0c0c7780: /* original 88ff, guest PC 0x0c0c7780 */
if(!s->budget--) { s->failed_pc=0x0c0c7780u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c7782;
P_0c0c7782: /* original 8931, guest PC 0x0c0c7782 */
if(!s->budget--) { s->failed_pc=0x0c0c7782u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c77e8; }
goto P_0c0c7784;
P_0c0c7784: /* original 906b, guest PC 0x0c0c7784 */
if(!s->budget--) { s->failed_pc=0x0c0c7784u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c785eu,2);
goto P_0c0c7786;
P_0c0c7786: /* original d339, guest PC 0x0c0c7786 */
if(!s->budget--) { s->failed_pc=0x0c0c7786u; return 0; }
r[3]=read(ram,0x0c0c786cu,4);
goto P_0c0c7788;
P_0c0c7788: /* original 0dee, guest PC 0x0c0c7788 */
if(!s->budget--) { s->failed_pc=0x0c0c7788u; return 0; }
r[13]=read(ram,r[14]+r[0],4);
goto P_0c0c778a;
P_0c0c778a: /* original 6093, guest PC 0x0c0c778a */
if(!s->budget--) { s->failed_pc=0x0c0c778au; return 0; }
r[0]=r[9];
goto P_0c0c778c;
P_0c0c778c: /* original 8812, guest PC 0x0c0c778c */
if(!s->budget--) { s->failed_pc=0x0c0c778cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c0c778e;
P_0c0c778e: /* original 8f08, guest PC 0x0c0c778e */
if(!s->budget--) { s->failed_pc=0x0c0c778eu; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[7]=tmp;
if(!cond) { goto P_0c0c77a2; }
goto P_0c0c7792;
P_0c0c7790: /* original 6731, guest PC 0x0c0c7790 */
if(!s->budget--) { s->failed_pc=0x0c0c7790u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[7]=tmp;
goto P_0c0c7792;
P_0c0c7792: /* original 9565, guest PC 0x0c0c7792 */
if(!s->budget--) { s->failed_pc=0x0c0c7792u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7860u,2);
goto P_0c0c7794;
P_0c0c7794: /* original 66d3, guest PC 0x0c0c7794 */
if(!s->budget--) { s->failed_pc=0x0c0c7794u; return 0; }
r[6]=r[13];
goto P_0c0c7796;
P_0c0c7796: /* original d136, guest PC 0x0c0c7796 */
if(!s->budget--) { s->failed_pc=0x0c0c7796u; return 0; }
r[1]=read(ram,0x0c0c7870u,4);
goto P_0c0c7798;
P_0c0c7798: /* original 6453, guest PC 0x0c0c7798 */
if(!s->budget--) { s->failed_pc=0x0c0c7798u; return 0; }
r[4]=r[5];
goto P_0c0c779a;
P_0c0c779a: /* original 410b, guest PC 0x0c0c779a */
if(!s->budget--) { s->failed_pc=0x0c0c779au; return 0; }
target=r[1];
r[16]=code_base|0x0c0c779eu;
r[4]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c779eu) { target=s->pc; goto dispatch; }
goto P_0c0c779e;
P_0c0c779c: /* original 7401, guest PC 0x0c0c779c */
if(!s->budget--) { s->failed_pc=0x0c0c779cu; return 0; }
r[4]+=0x00000001u;
goto P_0c0c779e;
P_0c0c779e: /* original a009, guest PC 0x0c0c779e */
if(!s->budget--) { s->failed_pc=0x0c0c779eu; return 0; }
goto P_0c0c77b4;
P_0c0c77a0: /* original 0009, guest PC 0x0c0c77a0 */
if(!s->budget--) { s->failed_pc=0x0c0c77a0u; return 0; }
goto P_0c0c77a2;
P_0c0c77a2: /* original d531, guest PC 0x0c0c77a2 */
if(!s->budget--) { s->failed_pc=0x0c0c77a2u; return 0; }
r[5]=read(ram,0x0c0c7868u,4);
goto P_0c0c77a4;
P_0c0c77a4: /* original 66d3, guest PC 0x0c0c77a4 */
if(!s->budget--) { s->failed_pc=0x0c0c77a4u; return 0; }
r[6]=r[13];
goto P_0c0c77a6;
P_0c0c77a6: /* original 35cc, guest PC 0x0c0c77a6 */
if(!s->budget--) { s->failed_pc=0x0c0c77a6u; return 0; }
r[5]+=r[12];
goto P_0c0c77a8;
P_0c0c77a8: /* original 2f52, guest PC 0x0c0c77a8 */
if(!s->budget--) { s->failed_pc=0x0c0c77a8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c77aa;
P_0c0c77aa: /* original 64f2, guest PC 0x0c0c77aa */
if(!s->budget--) { s->failed_pc=0x0c0c77aau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c77ac;
P_0c0c77ac: /* original d230, guest PC 0x0c0c77ac */
if(!s->budget--) { s->failed_pc=0x0c0c77acu; return 0; }
r[2]=read(ram,0x0c0c7870u,4);
goto P_0c0c77ae;
P_0c0c77ae: /* original 5551, guest PC 0x0c0c77ae */
if(!s->budget--) { s->failed_pc=0x0c0c77aeu; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c0c77b0;
P_0c0c77b0: /* original 420b, guest PC 0x0c0c77b0 */
if(!s->budget--) { s->failed_pc=0x0c0c77b0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c77b4u;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c77b4u) { target=s->pc; goto dispatch; }
goto P_0c0c77b4;
P_0c0c77b2: /* original 6442, guest PC 0x0c0c77b2 */
if(!s->budget--) { s->failed_pc=0x0c0c77b2u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c77b4;
P_0c0c77b4: /* original 9a55, guest PC 0x0c0c77b4 */
if(!s->budget--) { s->failed_pc=0x0c0c77b4u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7862u,2);
goto P_0c0c77b6;
P_0c0c77b6: /* original 59d4, guest PC 0x0c0c77b6 */
if(!s->budget--) { s->failed_pc=0x0c0c77b6u; return 0; }
r[9]=read(ram,r[13]+16,4);
goto P_0c0c77b8;
P_0c0c77b8: /* original a007, guest PC 0x0c0c77b8 */
if(!s->budget--) { s->failed_pc=0x0c0c77b8u; return 0; }
r[12]=0x00000000u;
goto P_0c0c77ca;
P_0c0c77ba: /* original ec00, guest PC 0x0c0c77ba */
if(!s->budget--) { s->failed_pc=0x0c0c77bau; return 0; }
r[12]=0x00000000u;
goto P_0c0c77bc;
P_0c0c77bc: /* original 60c3, guest PC 0x0c0c77bc */
if(!s->budget--) { s->failed_pc=0x0c0c77bcu; return 0; }
r[0]=r[12];
goto P_0c0c77be;
P_0c0c77be: /* original 4008, guest PC 0x0c0c77be */
if(!s->budget--) { s->failed_pc=0x0c0c77beu; return 0; }
r[0]<<=2;
goto P_0c0c77c0;
P_0c0c77c0: /* original 059e, guest PC 0x0c0c77c0 */
if(!s->budget--) { s->failed_pc=0x0c0c77c0u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c0c77c2;
P_0c0c77c2: /* original 64a3, guest PC 0x0c0c77c2 */
if(!s->budget--) { s->failed_pc=0x0c0c77c2u; return 0; }
r[4]=r[10];
goto P_0c0c77c4;
P_0c0c77c4: /* original 4b0b, guest PC 0x0c0c77c4 */
if(!s->budget--) { s->failed_pc=0x0c0c77c4u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c77c8u;
r[10]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c77c8u) { target=s->pc; goto dispatch; }
goto P_0c0c77c8;
P_0c0c77c6: /* original 7a01, guest PC 0x0c0c77c6 */
if(!s->budget--) { s->failed_pc=0x0c0c77c6u; return 0; }
r[10]+=0x00000001u;
goto P_0c0c77c8;
P_0c0c77c8: /* original 7c01, guest PC 0x0c0c77c8 */
if(!s->budget--) { s->failed_pc=0x0c0c77c8u; return 0; }
r[12]+=0x00000001u;
goto P_0c0c77ca;
P_0c0c77ca: /* original 85d6, guest PC 0x0c0c77ca */
if(!s->budget--) { s->failed_pc=0x0c0c77cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+12,2);
goto P_0c0c77cc;
P_0c0c77cc: /* original 600d, guest PC 0x0c0c77cc */
if(!s->budget--) { s->failed_pc=0x0c0c77ccu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c77ce;
P_0c0c77ce: /* original 3c03, guest PC 0x0c0c77ce */
if(!s->budget--) { s->failed_pc=0x0c0c77ceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[0])!=0);
goto P_0c0c77d0;
P_0c0c77d0: /* original 8bf4, guest PC 0x0c0c77d0 */
if(!s->budget--) { s->failed_pc=0x0c0c77d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c77bc; }
goto P_0c0c77d2;
P_0c0c77d2: /* original 9044, guest PC 0x0c0c77d2 */
if(!s->budget--) { s->failed_pc=0x0c0c77d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c785eu,2);
goto P_0c0c77d4;
P_0c0c77d4: /* original 53d6, guest PC 0x0c0c77d4 */
if(!s->budget--) { s->failed_pc=0x0c0c77d4u; return 0; }
r[3]=read(ram,r[13]+24,4);
goto P_0c0c77d6;
P_0c0c77d6: /* original 02ee, guest PC 0x0c0c77d6 */
if(!s->budget--) { s->failed_pc=0x0c0c77d6u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0c77d8;
P_0c0c77d8: /* original 7008, guest PC 0x0c0c77d8 */
if(!s->budget--) { s->failed_pc=0x0c0c77d8u; return 0; }
r[0]+=0x00000008u;
goto P_0c0c77da;
P_0c0c77da: /* original 9143, guest PC 0x0c0c77da */
if(!s->budget--) { s->failed_pc=0x0c0c77dau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7864u,2);
goto P_0c0c77dc;
P_0c0c77dc: /* original 323c, guest PC 0x0c0c77dc */
if(!s->budget--) { s->failed_pc=0x0c0c77dcu; return 0; }
r[2]+=r[3];
goto P_0c0c77de;
P_0c0c77de: /* original 9342, guest PC 0x0c0c77de */
if(!s->budget--) { s->failed_pc=0x0c0c77deu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7866u,2);
goto P_0c0c77e0;
P_0c0c77e0: /* original 321c, guest PC 0x0c0c77e0 */
if(!s->budget--) { s->failed_pc=0x0c0c77e0u; return 0; }
r[2]+=r[1];
goto P_0c0c77e2;
P_0c0c77e2: /* original 2239, guest PC 0x0c0c77e2 */
if(!s->budget--) { s->failed_pc=0x0c0c77e2u; return 0; }
r[2]&=r[3];
goto P_0c0c77e4;
P_0c0c77e4: /* original a003, guest PC 0x0c0c77e4 */
if(!s->budget--) { s->failed_pc=0x0c0c77e4u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c77ee;
P_0c0c77e6: /* original 0e26, guest PC 0x0c0c77e6 */
if(!s->budget--) { s->failed_pc=0x0c0c77e6u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c77e8;
P_0c0c77e8: /* original 9039, guest PC 0x0c0c77e8 */
if(!s->budget--) { s->failed_pc=0x0c0c77e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c785eu,2);
goto P_0c0c77ea;
P_0c0c77ea: /* original e300, guest PC 0x0c0c77ea */
if(!s->budget--) { s->failed_pc=0x0c0c77eau; return 0; }
r[3]=0x00000000u;
goto P_0c0c77ec;
P_0c0c77ec: /* original 0e36, guest PC 0x0c0c77ec */
if(!s->budget--) { s->failed_pc=0x0c0c77ecu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0c77ee;
P_0c0c77ee: /* original 7f04, guest PC 0x0c0c77ee */
if(!s->budget--) { s->failed_pc=0x0c0c77eeu; return 0; }
r[15]+=0x00000004u;
goto P_0c0c77f0;
P_0c0c77f0: /* original 4f26, guest PC 0x0c0c77f0 */
if(!s->budget--) { s->failed_pc=0x0c0c77f0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c77f2;
P_0c0c77f2: /* original 68f6, guest PC 0x0c0c77f2 */
if(!s->budget--) { s->failed_pc=0x0c0c77f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c77f4;
P_0c0c77f4: /* original 69f6, guest PC 0x0c0c77f4 */
if(!s->budget--) { s->failed_pc=0x0c0c77f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c77f6;
P_0c0c77f6: /* original 6af6, guest PC 0x0c0c77f6 */
if(!s->budget--) { s->failed_pc=0x0c0c77f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c77f8;
P_0c0c77f8: /* original 6bf6, guest PC 0x0c0c77f8 */
if(!s->budget--) { s->failed_pc=0x0c0c77f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c77fa;
P_0c0c77fa: /* original 6cf6, guest PC 0x0c0c77fa */
if(!s->budget--) { s->failed_pc=0x0c0c77fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c77fc;
P_0c0c77fc: /* original 6df6, guest PC 0x0c0c77fc */
if(!s->budget--) { s->failed_pc=0x0c0c77fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c77fe;
P_0c0c77fe: /* original a000, guest PC 0x0c0c77fe */
if(!s->budget--) { s->failed_pc=0x0c0c77feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c7802;
P_0c0c7800: /* original 6ef6, guest PC 0x0c0c7800 */
if(!s->budget--) { s->failed_pc=0x0c0c7800u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c7802;
P_0c0c7802: /* original e01c, guest PC 0x0c0c7802 */
if(!s->budget--) { s->failed_pc=0x0c0c7802u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7804;
P_0c0c7804: /* original 2fe6, guest PC 0x0c0c7804 */
if(!s->budget--) { s->failed_pc=0x0c0c7804u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7806;
P_0c0c7806: /* original 2fd6, guest PC 0x0c0c7806 */
if(!s->budget--) { s->failed_pc=0x0c0c7806u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7808;
P_0c0c7808: /* original 2fc6, guest PC 0x0c0c7808 */
if(!s->budget--) { s->failed_pc=0x0c0c7808u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c780a;
P_0c0c780a: /* original 2fb6, guest PC 0x0c0c780a */
if(!s->budget--) { s->failed_pc=0x0c0c780au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c780c;
P_0c0c780c: /* original 2fa6, guest PC 0x0c0c780c */
if(!s->budget--) { s->failed_pc=0x0c0c780cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c780e;
P_0c0c780e: /* original d419, guest PC 0x0c0c780e */
if(!s->budget--) { s->failed_pc=0x0c0c780eu; return 0; }
r[4]=read(ram,0x0c0c7874u,4);
goto P_0c0c7810;
P_0c0c7810: /* original 4f22, guest PC 0x0c0c7810 */
if(!s->budget--) { s->failed_pc=0x0c0c7810u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7812;
P_0c0c7812: /* original 004c, guest PC 0x0c0c7812 */
if(!s->budget--) { s->failed_pc=0x0c0c7812u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7814;
P_0c0c7814: /* original e40f, guest PC 0x0c0c7814 */
if(!s->budget--) { s->failed_pc=0x0c0c7814u; return 0; }
r[4]=0x0000000fu;
goto P_0c0c7816;
P_0c0c7816: /* original 600c, guest PC 0x0c0c7816 */
if(!s->budget--) { s->failed_pc=0x0c0c7816u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c7818;
P_0c0c7818: /* original 2409, guest PC 0x0c0c7818 */
if(!s->budget--) { s->failed_pc=0x0c0c7818u; return 0; }
r[4]&=r[0];
goto P_0c0c781a;
P_0c0c781a: /* original d017, guest PC 0x0c0c781a */
if(!s->budget--) { s->failed_pc=0x0c0c781au; return 0; }
r[0]=read(ram,0x0c0c7878u,4);
goto P_0c0c781c;
P_0c0c781c: /* original 6e43, guest PC 0x0c0c781c */
if(!s->budget--) { s->failed_pc=0x0c0c781cu; return 0; }
r[14]=r[4];
goto P_0c0c781e;
P_0c0c781e: /* original 4e08, guest PC 0x0c0c781e */
if(!s->budget--) { s->failed_pc=0x0c0c781eu; return 0; }
r[14]<<=2;
goto P_0c0c7820;
P_0c0c7820: /* original 0eee, guest PC 0x0c0c7820 */
if(!s->budget--) { s->failed_pc=0x0c0c7820u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c0c7822;
P_0c0c7822: /* original 2ee8, guest PC 0x0c0c7822 */
if(!s->budget--) { s->failed_pc=0x0c0c7822u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c7824;
P_0c0c7824: /* original 8914, guest PC 0x0c0c7824 */
if(!s->budget--) { s->failed_pc=0x0c0c7824u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7850; }
goto P_0c0c7826;
P_0c0c7826: /* original dc17, guest PC 0x0c0c7826 */
if(!s->budget--) { s->failed_pc=0x0c0c7826u; return 0; }
r[12]=read(ram,0x0c0c7884u,4);
goto P_0c0c7828;
P_0c0c7828: /* original db15, guest PC 0x0c0c7828 */
if(!s->budget--) { s->failed_pc=0x0c0c7828u; return 0; }
r[11]=read(ram,0x0c0c7880u,4);
goto P_0c0c782a;
P_0c0c782a: /* original da14, guest PC 0x0c0c782a */
if(!s->budget--) { s->failed_pc=0x0c0c782au; return 0; }
r[10]=read(ram,0x0c0c787cu,4);
goto P_0c0c782c;
P_0c0c782c: /* original a00d, guest PC 0x0c0c782c */
if(!s->budget--) { s->failed_pc=0x0c0c782cu; return 0; }
r[13]=0x00000001u;
goto P_0c0c784a;
P_0c0c782e: /* original ed01, guest PC 0x0c0c782e */
if(!s->budget--) { s->failed_pc=0x0c0c782eu; return 0; }
r[13]=0x00000001u;
goto P_0c0c7830;
P_0c0c7830: /* original 60e5, guest PC 0x0c0c7830 */
if(!s->budget--) { s->failed_pc=0x0c0c7830u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[0]=tmp;
goto P_0c0c7832;
P_0c0c7832: /* original 600d, guest PC 0x0c0c7832 */
if(!s->budget--) { s->failed_pc=0x0c0c7832u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c7834;
P_0c0c7834: /* original 4008, guest PC 0x0c0c7834 */
if(!s->budget--) { s->failed_pc=0x0c0c7834u; return 0; }
r[0]<<=2;
goto P_0c0c7836;
P_0c0c7836: /* original 04ce, guest PC 0x0c0c7836 */
if(!s->budget--) { s->failed_pc=0x0c0c7836u; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c0c7838;
P_0c0c7838: /* original 5341, guest PC 0x0c0c7838 */
if(!s->budget--) { s->failed_pc=0x0c0c7838u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0c783a;
P_0c0c783a: /* original 23d8, guest PC 0x0c0c783a */
if(!s->budget--) { s->failed_pc=0x0c0c783au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c783c;
P_0c0c783c: /* original 8903, guest PC 0x0c0c783c */
if(!s->budget--) { s->failed_pc=0x0c0c783cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7846; }
goto P_0c0c783e;
P_0c0c783e: /* original 4b0b, guest PC 0x0c0c783e */
if(!s->budget--) { s->failed_pc=0x0c0c783eu; return 0; }
target=r[11];
r[16]=code_base|0x0c0c7842u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7842u) { target=s->pc; goto dispatch; }
goto P_0c0c7842;
P_0c0c7840: /* original 0009, guest PC 0x0c0c7840 */
if(!s->budget--) { s->failed_pc=0x0c0c7840u; return 0; }
goto P_0c0c7842;
P_0c0c7842: /* original a002, guest PC 0x0c0c7842 */
if(!s->budget--) { s->failed_pc=0x0c0c7842u; return 0; }
goto P_0c0c784a;
P_0c0c7844: /* original 0009, guest PC 0x0c0c7844 */
if(!s->budget--) { s->failed_pc=0x0c0c7844u; return 0; }
goto P_0c0c7846;
P_0c0c7846: /* original 4a0b, guest PC 0x0c0c7846 */
if(!s->budget--) { s->failed_pc=0x0c0c7846u; return 0; }
target=r[10];
r[16]=code_base|0x0c0c784au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c784au) { target=s->pc; goto dispatch; }
goto P_0c0c784a;
P_0c0c7848: /* original 0009, guest PC 0x0c0c7848 */
if(!s->budget--) { s->failed_pc=0x0c0c7848u; return 0; }
goto P_0c0c784a;
P_0c0c784a: /* original 62e1, guest PC 0x0c0c784a */
if(!s->budget--) { s->failed_pc=0x0c0c784au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c0c784c;
P_0c0c784c: /* original 2228, guest PC 0x0c0c784c */
if(!s->budget--) { s->failed_pc=0x0c0c784cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c784e;
P_0c0c784e: /* original 8bef, guest PC 0x0c0c784e */
if(!s->budget--) { s->failed_pc=0x0c0c784eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7830; }
goto P_0c0c7850;
P_0c0c7850: /* original 4f26, guest PC 0x0c0c7850 */
if(!s->budget--) { s->failed_pc=0x0c0c7850u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7852;
P_0c0c7852: /* original 6af6, guest PC 0x0c0c7852 */
if(!s->budget--) { s->failed_pc=0x0c0c7852u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c7854;
P_0c0c7854: /* original 6bf6, guest PC 0x0c0c7854 */
if(!s->budget--) { s->failed_pc=0x0c0c7854u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c7856;
P_0c0c7856: /* original 6cf6, guest PC 0x0c0c7856 */
if(!s->budget--) { s->failed_pc=0x0c0c7856u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c7858;
P_0c0c7858: /* original 6df6, guest PC 0x0c0c7858 */
if(!s->budget--) { s->failed_pc=0x0c0c7858u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c785a;
P_0c0c785a: /* original 000b, guest PC 0x0c0c785a */
if(!s->budget--) { s->failed_pc=0x0c0c785au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c785c: /* original 6ef6, guest PC 0x0c0c785c */
if(!s->budget--) { s->failed_pc=0x0c0c785cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c785eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c785eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
