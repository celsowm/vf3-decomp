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
int vf3_away_batch152_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0b5ff6u: goto P_0c0b5ff6;
case 0x0c0b5ff8u: goto P_0c0b5ff8;
case 0x0c0b5ffau: goto P_0c0b5ffa;
case 0x0c0b5ffcu: goto P_0c0b5ffc;
case 0x0c0b5ffeu: goto P_0c0b5ffe;
case 0x0c0b6000u: goto P_0c0b6000;
case 0x0c0b6002u: goto P_0c0b6002;
case 0x0c0b6004u: goto P_0c0b6004;
case 0x0c0b6006u: goto P_0c0b6006;
case 0x0c0b6008u: goto P_0c0b6008;
case 0x0c0b600au: goto P_0c0b600a;
case 0x0c0b600cu: goto P_0c0b600c;
case 0x0c0b600eu: goto P_0c0b600e;
case 0x0c0b6010u: goto P_0c0b6010;
case 0x0c0b6012u: goto P_0c0b6012;
case 0x0c0b6014u: goto P_0c0b6014;
case 0x0c0b6016u: goto P_0c0b6016;
case 0x0c0b6018u: goto P_0c0b6018;
case 0x0c0b601au: goto P_0c0b601a;
case 0x0c0b601cu: goto P_0c0b601c;
case 0x0c0b601eu: goto P_0c0b601e;
case 0x0c0b6020u: goto P_0c0b6020;
case 0x0c0b6022u: goto P_0c0b6022;
case 0x0c0b6024u: goto P_0c0b6024;
case 0x0c0b6026u: goto P_0c0b6026;
case 0x0c0b6028u: goto P_0c0b6028;
case 0x0c0b602au: goto P_0c0b602a;
case 0x0c0b602cu: goto P_0c0b602c;
case 0x0c0b602eu: goto P_0c0b602e;
case 0x0c0b6030u: goto P_0c0b6030;
case 0x0c0b6032u: goto P_0c0b6032;
case 0x0c0b6034u: goto P_0c0b6034;
case 0x0c0b6036u: goto P_0c0b6036;
case 0x0c0b6038u: goto P_0c0b6038;
case 0x0c0b603au: goto P_0c0b603a;
case 0x0c0b603cu: goto P_0c0b603c;
case 0x0c0b603eu: goto P_0c0b603e;
case 0x0c0b6040u: goto P_0c0b6040;
case 0x0c0b6042u: goto P_0c0b6042;
case 0x0c0b6044u: goto P_0c0b6044;
case 0x0c0b6046u: goto P_0c0b6046;
case 0x0c0b6048u: goto P_0c0b6048;
case 0x0c0b604au: goto P_0c0b604a;
case 0x0c0b604cu: goto P_0c0b604c;
case 0x0c0b604eu: goto P_0c0b604e;
case 0x0c0b6050u: goto P_0c0b6050;
case 0x0c0b6052u: goto P_0c0b6052;
case 0x0c0b6054u: goto P_0c0b6054;
case 0x0c0b6056u: goto P_0c0b6056;
case 0x0c0b6058u: goto P_0c0b6058;
case 0x0c0b605au: goto P_0c0b605a;
case 0x0c0b605cu: goto P_0c0b605c;
case 0x0c0b605eu: goto P_0c0b605e;
case 0x0c0b6060u: goto P_0c0b6060;
case 0x0c0b6062u: goto P_0c0b6062;
case 0x0c0b6064u: goto P_0c0b6064;
case 0x0c0b6066u: goto P_0c0b6066;
case 0x0c0b6068u: goto P_0c0b6068;
case 0x0c0b606au: goto P_0c0b606a;
case 0x0c0b606cu: goto P_0c0b606c;
case 0x0c0b606eu: goto P_0c0b606e;
case 0x0c0b6070u: goto P_0c0b6070;
case 0x0c0b6072u: goto P_0c0b6072;
case 0x0c0b6074u: goto P_0c0b6074;
case 0x0c0b6076u: goto P_0c0b6076;
case 0x0c0b6078u: goto P_0c0b6078;
case 0x0c0b607au: goto P_0c0b607a;
case 0x0c0b607cu: goto P_0c0b607c;
case 0x0c0b607eu: goto P_0c0b607e;
case 0x0c0b6080u: goto P_0c0b6080;
case 0x0c0b6082u: goto P_0c0b6082;
case 0x0c0b6084u: goto P_0c0b6084;
case 0x0c0b6086u: goto P_0c0b6086;
case 0x0c0b6088u: goto P_0c0b6088;
case 0x0c0b608au: goto P_0c0b608a;
case 0x0c0b608cu: goto P_0c0b608c;
case 0x0c0b608eu: goto P_0c0b608e;
case 0x0c0b6090u: goto P_0c0b6090;
case 0x0c0b6092u: goto P_0c0b6092;
case 0x0c0b6094u: goto P_0c0b6094;
case 0x0c0b6096u: goto P_0c0b6096;
case 0x0c0b6098u: goto P_0c0b6098;
case 0x0c0b609au: goto P_0c0b609a;
case 0x0c0b609cu: goto P_0c0b609c;
case 0x0c0b609eu: goto P_0c0b609e;
case 0x0c0b60a0u: goto P_0c0b60a0;
case 0x0c0b60a2u: goto P_0c0b60a2;
case 0x0c0b60a4u: goto P_0c0b60a4;
case 0x0c0b60a6u: goto P_0c0b60a6;
case 0x0c0b60a8u: goto P_0c0b60a8;
case 0x0c0b60aau: goto P_0c0b60aa;
case 0x0c0b60acu: goto P_0c0b60ac;
case 0x0c0b60aeu: goto P_0c0b60ae;
case 0x0c0b60b0u: goto P_0c0b60b0;
case 0x0c0b60b2u: goto P_0c0b60b2;
case 0x0c0b60b4u: goto P_0c0b60b4;
case 0x0c0b60b6u: goto P_0c0b60b6;
case 0x0c0b60b8u: goto P_0c0b60b8;
case 0x0c0b60bau: goto P_0c0b60ba;
case 0x0c0b60bcu: goto P_0c0b60bc;
case 0x0c0b60beu: goto P_0c0b60be;
case 0x0c0b60c0u: goto P_0c0b60c0;
case 0x0c0b60c2u: goto P_0c0b60c2;
case 0x0c0b60c4u: goto P_0c0b60c4;
case 0x0c0b60c6u: goto P_0c0b60c6;
case 0x0c0b60c8u: goto P_0c0b60c8;
case 0x0c0b60cau: goto P_0c0b60ca;
case 0x0c0b60ccu: goto P_0c0b60cc;
case 0x0c0b60ceu: goto P_0c0b60ce;
case 0x0c0b60d0u: goto P_0c0b60d0;
case 0x0c0b60d2u: goto P_0c0b60d2;
case 0x0c0b60d4u: goto P_0c0b60d4;
case 0x0c0b60d6u: goto P_0c0b60d6;
case 0x0c0b60d8u: goto P_0c0b60d8;
case 0x0c0b60dau: goto P_0c0b60da;
case 0x0c0b60dcu: goto P_0c0b60dc;
case 0x0c0b60deu: goto P_0c0b60de;
case 0x0c0b60e0u: goto P_0c0b60e0;
case 0x0c0b60e2u: goto P_0c0b60e2;
case 0x0c0b60e4u: goto P_0c0b60e4;
case 0x0c0b60e6u: goto P_0c0b60e6;
case 0x0c0b60e8u: goto P_0c0b60e8;
case 0x0c0b60eau: goto P_0c0b60ea;
case 0x0c0b60ecu: goto P_0c0b60ec;
case 0x0c0b60eeu: goto P_0c0b60ee;
case 0x0c0b60f0u: goto P_0c0b60f0;
case 0x0c0b60f2u: goto P_0c0b60f2;
case 0x0c0b60f4u: goto P_0c0b60f4;
case 0x0c0b60f6u: goto P_0c0b60f6;
case 0x0c0b60f8u: goto P_0c0b60f8;
case 0x0c0b60fau: goto P_0c0b60fa;
case 0x0c0b60fcu: goto P_0c0b60fc;
case 0x0c0b60feu: goto P_0c0b60fe;
case 0x0c0b6100u: goto P_0c0b6100;
case 0x0c0b6102u: goto P_0c0b6102;
case 0x0c0b6104u: goto P_0c0b6104;
case 0x0c0b6106u: goto P_0c0b6106;
case 0x0c0b6108u: goto P_0c0b6108;
case 0x0c0b610au: goto P_0c0b610a;
case 0x0c0b610cu: goto P_0c0b610c;
case 0x0c0b610eu: goto P_0c0b610e;
case 0x0c0b6110u: goto P_0c0b6110;
case 0x0c0b6112u: goto P_0c0b6112;
case 0x0c0b6114u: goto P_0c0b6114;
case 0x0c0b6116u: goto P_0c0b6116;
case 0x0c0b6118u: goto P_0c0b6118;
case 0x0c0b611au: goto P_0c0b611a;
case 0x0c0b611cu: goto P_0c0b611c;
case 0x0c0b611eu: goto P_0c0b611e;
case 0x0c0b6120u: goto P_0c0b6120;
case 0x0c0b6122u: goto P_0c0b6122;
case 0x0c0b6124u: goto P_0c0b6124;
case 0x0c0b6126u: goto P_0c0b6126;
case 0x0c0b6128u: goto P_0c0b6128;
case 0x0c0b612au: goto P_0c0b612a;
case 0x0c0b612cu: goto P_0c0b612c;
case 0x0c0b612eu: goto P_0c0b612e;
case 0x0c0b6130u: goto P_0c0b6130;
case 0x0c0b6132u: goto P_0c0b6132;
case 0x0c0b6134u: goto P_0c0b6134;
case 0x0c0b6136u: goto P_0c0b6136;
case 0x0c0b6138u: goto P_0c0b6138;
case 0x0c0b613au: goto P_0c0b613a;
case 0x0c0b613cu: goto P_0c0b613c;
case 0x0c0b613eu: goto P_0c0b613e;
case 0x0c0b6140u: goto P_0c0b6140;
case 0x0c0b6142u: goto P_0c0b6142;
case 0x0c0b6144u: goto P_0c0b6144;
case 0x0c0b6146u: goto P_0c0b6146;
case 0x0c0b6148u: goto P_0c0b6148;
case 0x0c0b614au: goto P_0c0b614a;
case 0x0c0b614cu: goto P_0c0b614c;
case 0x0c0b614eu: goto P_0c0b614e;
case 0x0c0b6150u: goto P_0c0b6150;
case 0x0c0b6152u: goto P_0c0b6152;
case 0x0c0b6154u: goto P_0c0b6154;
case 0x0c0b6156u: goto P_0c0b6156;
case 0x0c0b6158u: goto P_0c0b6158;
case 0x0c0b61c8u: goto P_0c0b61c8;
case 0x0c0b61cau: goto P_0c0b61ca;
case 0x0c0b61ccu: goto P_0c0b61cc;
case 0x0c0b61ceu: goto P_0c0b61ce;
case 0x0c0b61d0u: goto P_0c0b61d0;
case 0x0c0b61d2u: goto P_0c0b61d2;
case 0x0c0b61d4u: goto P_0c0b61d4;
case 0x0c0b61d6u: goto P_0c0b61d6;
case 0x0c0b61d8u: goto P_0c0b61d8;
case 0x0c0b61dau: goto P_0c0b61da;
case 0x0c0b61dcu: goto P_0c0b61dc;
case 0x0c0b61deu: goto P_0c0b61de;
case 0x0c0b61e0u: goto P_0c0b61e0;
case 0x0c0b61e2u: goto P_0c0b61e2;
case 0x0c0b61e4u: goto P_0c0b61e4;
case 0x0c0b61e6u: goto P_0c0b61e6;
case 0x0c0b61e8u: goto P_0c0b61e8;
case 0x0c0b61eau: goto P_0c0b61ea;
case 0x0c0b61ecu: goto P_0c0b61ec;
case 0x0c0b61eeu: goto P_0c0b61ee;
case 0x0c0b61f0u: goto P_0c0b61f0;
case 0x0c0b61f2u: goto P_0c0b61f2;
case 0x0c0b61f4u: goto P_0c0b61f4;
case 0x0c0b61f6u: goto P_0c0b61f6;
case 0x0c0b61f8u: goto P_0c0b61f8;
case 0x0c0b61fau: goto P_0c0b61fa;
case 0x0c0b61fcu: goto P_0c0b61fc;
case 0x0c0b61feu: goto P_0c0b61fe;
case 0x0c0b6200u: goto P_0c0b6200;
case 0x0c0b6202u: goto P_0c0b6202;
case 0x0c0b6204u: goto P_0c0b6204;
case 0x0c0b6206u: goto P_0c0b6206;
case 0x0c0b6208u: goto P_0c0b6208;
case 0x0c0b620au: goto P_0c0b620a;
case 0x0c0b620cu: goto P_0c0b620c;
case 0x0c0b620eu: goto P_0c0b620e;
case 0x0c0b6210u: goto P_0c0b6210;
case 0x0c0b6212u: goto P_0c0b6212;
case 0x0c0b6214u: goto P_0c0b6214;
case 0x0c0b6216u: goto P_0c0b6216;
case 0x0c0b6218u: goto P_0c0b6218;
case 0x0c0b621au: goto P_0c0b621a;
case 0x0c0b621cu: goto P_0c0b621c;
case 0x0c0b621eu: goto P_0c0b621e;
case 0x0c0b6220u: goto P_0c0b6220;
case 0x0c0b6222u: goto P_0c0b6222;
case 0x0c0b6224u: goto P_0c0b6224;
case 0x0c0b6226u: goto P_0c0b6226;
case 0x0c0b6228u: goto P_0c0b6228;
case 0x0c0b622au: goto P_0c0b622a;
case 0x0c0b622cu: goto P_0c0b622c;
case 0x0c0b622eu: goto P_0c0b622e;
case 0x0c0b6230u: goto P_0c0b6230;
case 0x0c0b6232u: goto P_0c0b6232;
case 0x0c0b6234u: goto P_0c0b6234;
case 0x0c0b6236u: goto P_0c0b6236;
case 0x0c0b6238u: goto P_0c0b6238;
case 0x0c0b623au: goto P_0c0b623a;
case 0x0c0b623cu: goto P_0c0b623c;
case 0x0c0b623eu: goto P_0c0b623e;
case 0x0c0b6240u: goto P_0c0b6240;
case 0x0c0b6242u: goto P_0c0b6242;
case 0x0c0b6244u: goto P_0c0b6244;
case 0x0c0b6246u: goto P_0c0b6246;
case 0x0c0b6248u: goto P_0c0b6248;
case 0x0c0b624au: goto P_0c0b624a;
case 0x0c0b624cu: goto P_0c0b624c;
case 0x0c0b624eu: goto P_0c0b624e;
case 0x0c0b6250u: goto P_0c0b6250;
case 0x0c0b6252u: goto P_0c0b6252;
case 0x0c0b6254u: goto P_0c0b6254;
case 0x0c0b6256u: goto P_0c0b6256;
case 0x0c0b6258u: goto P_0c0b6258;
case 0x0c0b625au: goto P_0c0b625a;
case 0x0c0b625cu: goto P_0c0b625c;
case 0x0c0b625eu: goto P_0c0b625e;
case 0x0c0b6260u: goto P_0c0b6260;
case 0x0c0b6262u: goto P_0c0b6262;
case 0x0c0b6264u: goto P_0c0b6264;
case 0x0c0b6266u: goto P_0c0b6266;
case 0x0c0b6268u: goto P_0c0b6268;
case 0x0c0b626au: goto P_0c0b626a;
case 0x0c0b626cu: goto P_0c0b626c;
case 0x0c0b626eu: goto P_0c0b626e;
case 0x0c0b6270u: goto P_0c0b6270;
case 0x0c0b6272u: goto P_0c0b6272;
case 0x0c0b6274u: goto P_0c0b6274;
case 0x0c0b6276u: goto P_0c0b6276;
case 0x0c0b6278u: goto P_0c0b6278;
case 0x0c0b627au: goto P_0c0b627a;
case 0x0c0b627cu: goto P_0c0b627c;
case 0x0c0b627eu: goto P_0c0b627e;
case 0x0c0b6280u: goto P_0c0b6280;
case 0x0c0b6282u: goto P_0c0b6282;
case 0x0c0b6284u: goto P_0c0b6284;
case 0x0c0b6286u: goto P_0c0b6286;
case 0x0c0b6288u: goto P_0c0b6288;
case 0x0c0b628au: goto P_0c0b628a;
case 0x0c0b628cu: goto P_0c0b628c;
case 0x0c0b628eu: goto P_0c0b628e;
case 0x0c0b6290u: goto P_0c0b6290;
case 0x0c0b6292u: goto P_0c0b6292;
case 0x0c0b6294u: goto P_0c0b6294;
case 0x0c0b6296u: goto P_0c0b6296;
case 0x0c0b6298u: goto P_0c0b6298;
case 0x0c0b629au: goto P_0c0b629a;
case 0x0c0b629cu: goto P_0c0b629c;
case 0x0c0b629eu: goto P_0c0b629e;
case 0x0c0b62a0u: goto P_0c0b62a0;
case 0x0c0b62a2u: goto P_0c0b62a2;
case 0x0c0b62a4u: goto P_0c0b62a4;
case 0x0c0b62a6u: goto P_0c0b62a6;
case 0x0c0b62a8u: goto P_0c0b62a8;
case 0x0c0b62aau: goto P_0c0b62aa;
case 0x0c0b62acu: goto P_0c0b62ac;
case 0x0c0b62aeu: goto P_0c0b62ae;
case 0x0c0b62b0u: goto P_0c0b62b0;
case 0x0c0b62b2u: goto P_0c0b62b2;
case 0x0c0b62b4u: goto P_0c0b62b4;
case 0x0c0b62b6u: goto P_0c0b62b6;
case 0x0c0b62b8u: goto P_0c0b62b8;
case 0x0c0b62bau: goto P_0c0b62ba;
case 0x0c0b62bcu: goto P_0c0b62bc;
case 0x0c0b62beu: goto P_0c0b62be;
case 0x0c0b62c0u: goto P_0c0b62c0;
case 0x0c0b62c2u: goto P_0c0b62c2;
case 0x0c0b62c4u: goto P_0c0b62c4;
case 0x0c0b62c6u: goto P_0c0b62c6;
case 0x0c0b62c8u: goto P_0c0b62c8;
case 0x0c0b62cau: goto P_0c0b62ca;
case 0x0c0b62ccu: goto P_0c0b62cc;
case 0x0c0b62ceu: goto P_0c0b62ce;
case 0x0c0b62d0u: goto P_0c0b62d0;
case 0x0c0b62d2u: goto P_0c0b62d2;
case 0x0c0b62d4u: goto P_0c0b62d4;
case 0x0c0b62d6u: goto P_0c0b62d6;
case 0x0c0b62d8u: goto P_0c0b62d8;
case 0x0c0b62dau: goto P_0c0b62da;
case 0x0c0b62dcu: goto P_0c0b62dc;
case 0x0c0b62deu: goto P_0c0b62de;
case 0x0c0b62e0u: goto P_0c0b62e0;
case 0x0c0b62e2u: goto P_0c0b62e2;
case 0x0c0b62e4u: goto P_0c0b62e4;
case 0x0c0b62e6u: goto P_0c0b62e6;
case 0x0c0b62e8u: goto P_0c0b62e8;
case 0x0c0b62eau: goto P_0c0b62ea;
case 0x0c0b62ecu: goto P_0c0b62ec;
case 0x0c0b62eeu: goto P_0c0b62ee;
case 0x0c0b62f0u: goto P_0c0b62f0;
case 0x0c0b62f2u: goto P_0c0b62f2;
case 0x0c0b62f4u: goto P_0c0b62f4;
case 0x0c0b62f6u: goto P_0c0b62f6;
case 0x0c0b62f8u: goto P_0c0b62f8;
case 0x0c0b62fau: goto P_0c0b62fa;
case 0x0c0b62fcu: goto P_0c0b62fc;
case 0x0c0b62feu: goto P_0c0b62fe;
case 0x0c0b6300u: goto P_0c0b6300;
case 0x0c0b6302u: goto P_0c0b6302;
case 0x0c0b6304u: goto P_0c0b6304;
case 0x0c0b6306u: goto P_0c0b6306;
case 0x0c0b6308u: goto P_0c0b6308;
case 0x0c0b630au: goto P_0c0b630a;
case 0x0c0b630cu: goto P_0c0b630c;
case 0x0c0b630eu: goto P_0c0b630e;
case 0x0c0b6310u: goto P_0c0b6310;
case 0x0c0b6312u: goto P_0c0b6312;
case 0x0c0b6314u: goto P_0c0b6314;
case 0x0c0b6316u: goto P_0c0b6316;
case 0x0c0b6318u: goto P_0c0b6318;
case 0x0c0b631au: goto P_0c0b631a;
case 0x0c0b631cu: goto P_0c0b631c;
case 0x0c0b631eu: goto P_0c0b631e;
case 0x0c0b6320u: goto P_0c0b6320;
case 0x0c0b639au: goto P_0c0b639a;
case 0x0c0b639cu: goto P_0c0b639c;
case 0x0c0b639eu: goto P_0c0b639e;
case 0x0c0b63a0u: goto P_0c0b63a0;
case 0x0c0b63a2u: goto P_0c0b63a2;
case 0x0c0b63a4u: goto P_0c0b63a4;
case 0x0c0b63a6u: goto P_0c0b63a6;
case 0x0c0b63a8u: goto P_0c0b63a8;
case 0x0c0b63aau: goto P_0c0b63aa;
case 0x0c0b63acu: goto P_0c0b63ac;
case 0x0c0b63aeu: goto P_0c0b63ae;
case 0x0c0b63b0u: goto P_0c0b63b0;
case 0x0c0b63b2u: goto P_0c0b63b2;
case 0x0c0b63b4u: goto P_0c0b63b4;
case 0x0c0b63b6u: goto P_0c0b63b6;
case 0x0c0b63b8u: goto P_0c0b63b8;
case 0x0c0b63bau: goto P_0c0b63ba;
case 0x0c0b63bcu: goto P_0c0b63bc;
case 0x0c0b63beu: goto P_0c0b63be;
case 0x0c0b63c0u: goto P_0c0b63c0;
case 0x0c0b63c2u: goto P_0c0b63c2;
case 0x0c0b63c4u: goto P_0c0b63c4;
case 0x0c0b63c6u: goto P_0c0b63c6;
case 0x0c0b63c8u: goto P_0c0b63c8;
case 0x0c0b63cau: goto P_0c0b63ca;
case 0x0c0b63ccu: goto P_0c0b63cc;
case 0x0c0b63ceu: goto P_0c0b63ce;
case 0x0c0b63d0u: goto P_0c0b63d0;
case 0x0c0b63d2u: goto P_0c0b63d2;
case 0x0c0b63d4u: goto P_0c0b63d4;
case 0x0c0b63d6u: goto P_0c0b63d6;
case 0x0c0b63d8u: goto P_0c0b63d8;
case 0x0c0b63dau: goto P_0c0b63da;
case 0x0c0b63dcu: goto P_0c0b63dc;
case 0x0c0b63deu: goto P_0c0b63de;
case 0x0c0b63e0u: goto P_0c0b63e0;
case 0x0c0b63e2u: goto P_0c0b63e2;
case 0x0c0b63e4u: goto P_0c0b63e4;
case 0x0c0b63e6u: goto P_0c0b63e6;
case 0x0c0b63e8u: goto P_0c0b63e8;
case 0x0c0b63eau: goto P_0c0b63ea;
case 0x0c0b63ecu: goto P_0c0b63ec;
case 0x0c0b63eeu: goto P_0c0b63ee;
case 0x0c0b63f0u: goto P_0c0b63f0;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0b5ff6: /* original 2fe6, guest PC 0x0c0b5ff6 */
if(!s->budget--) { s->failed_pc=0x0c0b5ff6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b5ff8;
P_0c0b5ff8: /* original 2fd6, guest PC 0x0c0b5ff8 */
if(!s->budget--) { s->failed_pc=0x0c0b5ff8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b5ffa;
P_0c0b5ffa: /* original 2fc6, guest PC 0x0c0b5ffa */
if(!s->budget--) { s->failed_pc=0x0c0b5ffau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b5ffc;
P_0c0b5ffc: /* original 2fb6, guest PC 0x0c0b5ffc */
if(!s->budget--) { s->failed_pc=0x0c0b5ffcu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b5ffe;
P_0c0b5ffe: /* original 2fa6, guest PC 0x0c0b5ffe */
if(!s->budget--) { s->failed_pc=0x0c0b5ffeu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b6000;
P_0c0b6000: /* original 2f96, guest PC 0x0c0b6000 */
if(!s->budget--) { s->failed_pc=0x0c0b6000u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b6002;
P_0c0b6002: /* original 4f22, guest PC 0x0c0b6002 */
if(!s->budget--) { s->failed_pc=0x0c0b6002u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b6004;
P_0c0b6004: /* original 5d44, guest PC 0x0c0b6004 */
if(!s->budget--) { s->failed_pc=0x0c0b6004u; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0b6006;
P_0c0b6006: /* original 94a8, guest PC 0x0c0b6006 */
if(!s->budget--) { s->failed_pc=0x0c0b6006u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b615au,2);
goto P_0c0b6008;
P_0c0b6008: /* original de6e, guest PC 0x0c0b6008 */
if(!s->budget--) { s->failed_pc=0x0c0b6008u; return 0; }
r[14]=read(ram,0x0c0b61c4u,4);
goto P_0c0b600a;
P_0c0b600a: /* original 7ff8, guest PC 0x0c0b600a */
if(!s->budget--) { s->failed_pc=0x0c0b600au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0b600c;
P_0c0b600c: /* original 4e0b, guest PC 0x0c0b600c */
if(!s->budget--) { s->failed_pc=0x0c0b600cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6010u;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6010u) { target=s->pc; goto dispatch; }
goto P_0c0b6010;
P_0c0b600e: /* original 65d2, guest PC 0x0c0b600e */
if(!s->budget--) { s->failed_pc=0x0c0b600eu; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0b6010;
P_0c0b6010: /* original 94a4, guest PC 0x0c0b6010 */
if(!s->budget--) { s->failed_pc=0x0c0b6010u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b615cu,2);
goto P_0c0b6012;
P_0c0b6012: /* original 4e0b, guest PC 0x0c0b6012 */
if(!s->budget--) { s->failed_pc=0x0c0b6012u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6016u;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6016u) { target=s->pc; goto dispatch; }
goto P_0c0b6016;
P_0c0b6014: /* original 55d1, guest PC 0x0c0b6014 */
if(!s->budget--) { s->failed_pc=0x0c0b6014u; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0b6016;
P_0c0b6016: /* original 94a2, guest PC 0x0c0b6016 */
if(!s->budget--) { s->failed_pc=0x0c0b6016u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b615eu,2);
goto P_0c0b6018;
P_0c0b6018: /* original 4e0b, guest PC 0x0c0b6018 */
if(!s->budget--) { s->failed_pc=0x0c0b6018u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b601cu;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b601cu) { target=s->pc; goto dispatch; }
goto P_0c0b601c;
P_0c0b601a: /* original 55d2, guest PC 0x0c0b601a */
if(!s->budget--) { s->failed_pc=0x0c0b601au; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0b601c;
P_0c0b601c: /* original 94a0, guest PC 0x0c0b601c */
if(!s->budget--) { s->failed_pc=0x0c0b601cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6160u,2);
goto P_0c0b601e;
P_0c0b601e: /* original 4e0b, guest PC 0x0c0b601e */
if(!s->budget--) { s->failed_pc=0x0c0b601eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6022u;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6022u) { target=s->pc; goto dispatch; }
goto P_0c0b6022;
P_0c0b6020: /* original 55d3, guest PC 0x0c0b6020 */
if(!s->budget--) { s->failed_pc=0x0c0b6020u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0b6022;
P_0c0b6022: /* original 949e, guest PC 0x0c0b6022 */
if(!s->budget--) { s->failed_pc=0x0c0b6022u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6162u,2);
goto P_0c0b6024;
P_0c0b6024: /* original 4e0b, guest PC 0x0c0b6024 */
if(!s->budget--) { s->failed_pc=0x0c0b6024u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6028u;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6028u) { target=s->pc; goto dispatch; }
goto P_0c0b6028;
P_0c0b6026: /* original 55d4, guest PC 0x0c0b6026 */
if(!s->budget--) { s->failed_pc=0x0c0b6026u; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0b6028;
P_0c0b6028: /* original 949c, guest PC 0x0c0b6028 */
if(!s->budget--) { s->failed_pc=0x0c0b6028u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6164u,2);
goto P_0c0b602a;
P_0c0b602a: /* original 4e0b, guest PC 0x0c0b602a */
if(!s->budget--) { s->failed_pc=0x0c0b602au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b602eu;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b602eu) { target=s->pc; goto dispatch; }
goto P_0c0b602e;
P_0c0b602c: /* original 55d5, guest PC 0x0c0b602c */
if(!s->budget--) { s->failed_pc=0x0c0b602cu; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0b602e;
P_0c0b602e: /* original 949a, guest PC 0x0c0b602e */
if(!s->budget--) { s->failed_pc=0x0c0b602eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6166u,2);
goto P_0c0b6030;
P_0c0b6030: /* original 4e0b, guest PC 0x0c0b6030 */
if(!s->budget--) { s->failed_pc=0x0c0b6030u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6034u;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6034u) { target=s->pc; goto dispatch; }
goto P_0c0b6034;
P_0c0b6032: /* original 55d6, guest PC 0x0c0b6032 */
if(!s->budget--) { s->failed_pc=0x0c0b6032u; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0b6034;
P_0c0b6034: /* original 9498, guest PC 0x0c0b6034 */
if(!s->budget--) { s->failed_pc=0x0c0b6034u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6168u,2);
goto P_0c0b6036;
P_0c0b6036: /* original 4e0b, guest PC 0x0c0b6036 */
if(!s->budget--) { s->failed_pc=0x0c0b6036u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b603au;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b603au) { target=s->pc; goto dispatch; }
goto P_0c0b603a;
P_0c0b6038: /* original 55d7, guest PC 0x0c0b6038 */
if(!s->budget--) { s->failed_pc=0x0c0b6038u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0b603a;
P_0c0b603a: /* original 9496, guest PC 0x0c0b603a */
if(!s->budget--) { s->failed_pc=0x0c0b603au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b616au,2);
goto P_0c0b603c;
P_0c0b603c: /* original 4e0b, guest PC 0x0c0b603c */
if(!s->budget--) { s->failed_pc=0x0c0b603cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6040u;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6040u) { target=s->pc; goto dispatch; }
goto P_0c0b6040;
P_0c0b603e: /* original 55d8, guest PC 0x0c0b603e */
if(!s->budget--) { s->failed_pc=0x0c0b603eu; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0b6040;
P_0c0b6040: /* original 9494, guest PC 0x0c0b6040 */
if(!s->budget--) { s->failed_pc=0x0c0b6040u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b616cu,2);
goto P_0c0b6042;
P_0c0b6042: /* original 4e0b, guest PC 0x0c0b6042 */
if(!s->budget--) { s->failed_pc=0x0c0b6042u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6046u;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6046u) { target=s->pc; goto dispatch; }
goto P_0c0b6046;
P_0c0b6044: /* original 55d9, guest PC 0x0c0b6044 */
if(!s->budget--) { s->failed_pc=0x0c0b6044u; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0b6046;
P_0c0b6046: /* original 9492, guest PC 0x0c0b6046 */
if(!s->budget--) { s->failed_pc=0x0c0b6046u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b616eu,2);
goto P_0c0b6048;
P_0c0b6048: /* original 4e0b, guest PC 0x0c0b6048 */
if(!s->budget--) { s->failed_pc=0x0c0b6048u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b604cu;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b604cu) { target=s->pc; goto dispatch; }
goto P_0c0b604c;
P_0c0b604a: /* original 55da, guest PC 0x0c0b604a */
if(!s->budget--) { s->failed_pc=0x0c0b604au; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0b604c;
P_0c0b604c: /* original 9490, guest PC 0x0c0b604c */
if(!s->budget--) { s->failed_pc=0x0c0b604cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6170u,2);
goto P_0c0b604e;
P_0c0b604e: /* original 4e0b, guest PC 0x0c0b604e */
if(!s->budget--) { s->failed_pc=0x0c0b604eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6052u;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6052u) { target=s->pc; goto dispatch; }
goto P_0c0b6052;
P_0c0b6050: /* original 55db, guest PC 0x0c0b6050 */
if(!s->budget--) { s->failed_pc=0x0c0b6050u; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0b6052;
P_0c0b6052: /* original 948e, guest PC 0x0c0b6052 */
if(!s->budget--) { s->failed_pc=0x0c0b6052u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6172u,2);
goto P_0c0b6054;
P_0c0b6054: /* original 4e0b, guest PC 0x0c0b6054 */
if(!s->budget--) { s->failed_pc=0x0c0b6054u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6058u;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6058u) { target=s->pc; goto dispatch; }
goto P_0c0b6058;
P_0c0b6056: /* original 55dc, guest PC 0x0c0b6056 */
if(!s->budget--) { s->failed_pc=0x0c0b6056u; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0b6058;
P_0c0b6058: /* original 948c, guest PC 0x0c0b6058 */
if(!s->budget--) { s->failed_pc=0x0c0b6058u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6174u,2);
goto P_0c0b605a;
P_0c0b605a: /* original 4e0b, guest PC 0x0c0b605a */
if(!s->budget--) { s->failed_pc=0x0c0b605au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b605eu;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b605eu) { target=s->pc; goto dispatch; }
goto P_0c0b605e;
P_0c0b605c: /* original 55dd, guest PC 0x0c0b605c */
if(!s->budget--) { s->failed_pc=0x0c0b605cu; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0b605e;
P_0c0b605e: /* original 948a, guest PC 0x0c0b605e */
if(!s->budget--) { s->failed_pc=0x0c0b605eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6176u,2);
goto P_0c0b6060;
P_0c0b6060: /* original 4e0b, guest PC 0x0c0b6060 */
if(!s->budget--) { s->failed_pc=0x0c0b6060u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6064u;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6064u) { target=s->pc; goto dispatch; }
goto P_0c0b6064;
P_0c0b6062: /* original 55de, guest PC 0x0c0b6062 */
if(!s->budget--) { s->failed_pc=0x0c0b6062u; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0b6064;
P_0c0b6064: /* original 9488, guest PC 0x0c0b6064 */
if(!s->budget--) { s->failed_pc=0x0c0b6064u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6178u,2);
goto P_0c0b6066;
P_0c0b6066: /* original 4e0b, guest PC 0x0c0b6066 */
if(!s->budget--) { s->failed_pc=0x0c0b6066u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b606au;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b606au) { target=s->pc; goto dispatch; }
goto P_0c0b606a;
P_0c0b6068: /* original 55df, guest PC 0x0c0b6068 */
if(!s->budget--) { s->failed_pc=0x0c0b6068u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0b606a;
P_0c0b606a: /* original 9486, guest PC 0x0c0b606a */
if(!s->budget--) { s->failed_pc=0x0c0b606au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b617au,2);
goto P_0c0b606c;
P_0c0b606c: /* original e040, guest PC 0x0c0b606c */
if(!s->budget--) { s->failed_pc=0x0c0b606cu; return 0; }
r[0]=0x00000040u;
goto P_0c0b606e;
P_0c0b606e: /* original 4e0b, guest PC 0x0c0b606e */
if(!s->budget--) { s->failed_pc=0x0c0b606eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6072u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6072u) { target=s->pc; goto dispatch; }
goto P_0c0b6072;
P_0c0b6070: /* original 05de, guest PC 0x0c0b6070 */
if(!s->budget--) { s->failed_pc=0x0c0b6070u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6072;
P_0c0b6072: /* original 9483, guest PC 0x0c0b6072 */
if(!s->budget--) { s->failed_pc=0x0c0b6072u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b617cu,2);
goto P_0c0b6074;
P_0c0b6074: /* original e044, guest PC 0x0c0b6074 */
if(!s->budget--) { s->failed_pc=0x0c0b6074u; return 0; }
r[0]=0x00000044u;
goto P_0c0b6076;
P_0c0b6076: /* original 4e0b, guest PC 0x0c0b6076 */
if(!s->budget--) { s->failed_pc=0x0c0b6076u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b607au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b607au) { target=s->pc; goto dispatch; }
goto P_0c0b607a;
P_0c0b6078: /* original 05de, guest PC 0x0c0b6078 */
if(!s->budget--) { s->failed_pc=0x0c0b6078u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b607a;
P_0c0b607a: /* original 9480, guest PC 0x0c0b607a */
if(!s->budget--) { s->failed_pc=0x0c0b607au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b617eu,2);
goto P_0c0b607c;
P_0c0b607c: /* original e048, guest PC 0x0c0b607c */
if(!s->budget--) { s->failed_pc=0x0c0b607cu; return 0; }
r[0]=0x00000048u;
goto P_0c0b607e;
P_0c0b607e: /* original 4e0b, guest PC 0x0c0b607e */
if(!s->budget--) { s->failed_pc=0x0c0b607eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6082u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6082u) { target=s->pc; goto dispatch; }
goto P_0c0b6082;
P_0c0b6080: /* original 05de, guest PC 0x0c0b6080 */
if(!s->budget--) { s->failed_pc=0x0c0b6080u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6082;
P_0c0b6082: /* original 947d, guest PC 0x0c0b6082 */
if(!s->budget--) { s->failed_pc=0x0c0b6082u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6180u,2);
goto P_0c0b6084;
P_0c0b6084: /* original e04c, guest PC 0x0c0b6084 */
if(!s->budget--) { s->failed_pc=0x0c0b6084u; return 0; }
r[0]=0x0000004cu;
goto P_0c0b6086;
P_0c0b6086: /* original 4e0b, guest PC 0x0c0b6086 */
if(!s->budget--) { s->failed_pc=0x0c0b6086u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b608au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b608au) { target=s->pc; goto dispatch; }
goto P_0c0b608a;
P_0c0b6088: /* original 05de, guest PC 0x0c0b6088 */
if(!s->budget--) { s->failed_pc=0x0c0b6088u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b608a;
P_0c0b608a: /* original 947a, guest PC 0x0c0b608a */
if(!s->budget--) { s->failed_pc=0x0c0b608au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6182u,2);
goto P_0c0b608c;
P_0c0b608c: /* original e050, guest PC 0x0c0b608c */
if(!s->budget--) { s->failed_pc=0x0c0b608cu; return 0; }
r[0]=0x00000050u;
goto P_0c0b608e;
P_0c0b608e: /* original 4e0b, guest PC 0x0c0b608e */
if(!s->budget--) { s->failed_pc=0x0c0b608eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6092u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6092u) { target=s->pc; goto dispatch; }
goto P_0c0b6092;
P_0c0b6090: /* original 05de, guest PC 0x0c0b6090 */
if(!s->budget--) { s->failed_pc=0x0c0b6090u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6092;
P_0c0b6092: /* original 9477, guest PC 0x0c0b6092 */
if(!s->budget--) { s->failed_pc=0x0c0b6092u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6184u,2);
goto P_0c0b6094;
P_0c0b6094: /* original e054, guest PC 0x0c0b6094 */
if(!s->budget--) { s->failed_pc=0x0c0b6094u; return 0; }
r[0]=0x00000054u;
goto P_0c0b6096;
P_0c0b6096: /* original 4e0b, guest PC 0x0c0b6096 */
if(!s->budget--) { s->failed_pc=0x0c0b6096u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b609au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b609au) { target=s->pc; goto dispatch; }
goto P_0c0b609a;
P_0c0b6098: /* original 05de, guest PC 0x0c0b6098 */
if(!s->budget--) { s->failed_pc=0x0c0b6098u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b609a;
P_0c0b609a: /* original 9474, guest PC 0x0c0b609a */
if(!s->budget--) { s->failed_pc=0x0c0b609au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6186u,2);
goto P_0c0b609c;
P_0c0b609c: /* original e058, guest PC 0x0c0b609c */
if(!s->budget--) { s->failed_pc=0x0c0b609cu; return 0; }
r[0]=0x00000058u;
goto P_0c0b609e;
P_0c0b609e: /* original 4e0b, guest PC 0x0c0b609e */
if(!s->budget--) { s->failed_pc=0x0c0b609eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b60a2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b60a2u) { target=s->pc; goto dispatch; }
goto P_0c0b60a2;
P_0c0b60a0: /* original 05de, guest PC 0x0c0b60a0 */
if(!s->budget--) { s->failed_pc=0x0c0b60a0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b60a2;
P_0c0b60a2: /* original 9471, guest PC 0x0c0b60a2 */
if(!s->budget--) { s->failed_pc=0x0c0b60a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6188u,2);
goto P_0c0b60a4;
P_0c0b60a4: /* original e05c, guest PC 0x0c0b60a4 */
if(!s->budget--) { s->failed_pc=0x0c0b60a4u; return 0; }
r[0]=0x0000005cu;
goto P_0c0b60a6;
P_0c0b60a6: /* original 4e0b, guest PC 0x0c0b60a6 */
if(!s->budget--) { s->failed_pc=0x0c0b60a6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b60aau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b60aau) { target=s->pc; goto dispatch; }
goto P_0c0b60aa;
P_0c0b60a8: /* original 05de, guest PC 0x0c0b60a8 */
if(!s->budget--) { s->failed_pc=0x0c0b60a8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b60aa;
P_0c0b60aa: /* original 946e, guest PC 0x0c0b60aa */
if(!s->budget--) { s->failed_pc=0x0c0b60aau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b618au,2);
goto P_0c0b60ac;
P_0c0b60ac: /* original e060, guest PC 0x0c0b60ac */
if(!s->budget--) { s->failed_pc=0x0c0b60acu; return 0; }
r[0]=0x00000060u;
goto P_0c0b60ae;
P_0c0b60ae: /* original 4e0b, guest PC 0x0c0b60ae */
if(!s->budget--) { s->failed_pc=0x0c0b60aeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b60b2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b60b2u) { target=s->pc; goto dispatch; }
goto P_0c0b60b2;
P_0c0b60b0: /* original 05de, guest PC 0x0c0b60b0 */
if(!s->budget--) { s->failed_pc=0x0c0b60b0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b60b2;
P_0c0b60b2: /* original 946b, guest PC 0x0c0b60b2 */
if(!s->budget--) { s->failed_pc=0x0c0b60b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b618cu,2);
goto P_0c0b60b4;
P_0c0b60b4: /* original e064, guest PC 0x0c0b60b4 */
if(!s->budget--) { s->failed_pc=0x0c0b60b4u; return 0; }
r[0]=0x00000064u;
goto P_0c0b60b6;
P_0c0b60b6: /* original 4e0b, guest PC 0x0c0b60b6 */
if(!s->budget--) { s->failed_pc=0x0c0b60b6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b60bau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b60bau) { target=s->pc; goto dispatch; }
goto P_0c0b60ba;
P_0c0b60b8: /* original 05de, guest PC 0x0c0b60b8 */
if(!s->budget--) { s->failed_pc=0x0c0b60b8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b60ba;
P_0c0b60ba: /* original 9468, guest PC 0x0c0b60ba */
if(!s->budget--) { s->failed_pc=0x0c0b60bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b618eu,2);
goto P_0c0b60bc;
P_0c0b60bc: /* original e068, guest PC 0x0c0b60bc */
if(!s->budget--) { s->failed_pc=0x0c0b60bcu; return 0; }
r[0]=0x00000068u;
goto P_0c0b60be;
P_0c0b60be: /* original 4e0b, guest PC 0x0c0b60be */
if(!s->budget--) { s->failed_pc=0x0c0b60beu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b60c2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b60c2u) { target=s->pc; goto dispatch; }
goto P_0c0b60c2;
P_0c0b60c0: /* original 05de, guest PC 0x0c0b60c0 */
if(!s->budget--) { s->failed_pc=0x0c0b60c0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b60c2;
P_0c0b60c2: /* original 9465, guest PC 0x0c0b60c2 */
if(!s->budget--) { s->failed_pc=0x0c0b60c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6190u,2);
goto P_0c0b60c4;
P_0c0b60c4: /* original e06c, guest PC 0x0c0b60c4 */
if(!s->budget--) { s->failed_pc=0x0c0b60c4u; return 0; }
r[0]=0x0000006cu;
goto P_0c0b60c6;
P_0c0b60c6: /* original 4e0b, guest PC 0x0c0b60c6 */
if(!s->budget--) { s->failed_pc=0x0c0b60c6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b60cau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b60cau) { target=s->pc; goto dispatch; }
goto P_0c0b60ca;
P_0c0b60c8: /* original 05de, guest PC 0x0c0b60c8 */
if(!s->budget--) { s->failed_pc=0x0c0b60c8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b60ca;
P_0c0b60ca: /* original 9462, guest PC 0x0c0b60ca */
if(!s->budget--) { s->failed_pc=0x0c0b60cau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6192u,2);
goto P_0c0b60cc;
P_0c0b60cc: /* original e070, guest PC 0x0c0b60cc */
if(!s->budget--) { s->failed_pc=0x0c0b60ccu; return 0; }
r[0]=0x00000070u;
goto P_0c0b60ce;
P_0c0b60ce: /* original 4e0b, guest PC 0x0c0b60ce */
if(!s->budget--) { s->failed_pc=0x0c0b60ceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b60d2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b60d2u) { target=s->pc; goto dispatch; }
goto P_0c0b60d2;
P_0c0b60d0: /* original 05de, guest PC 0x0c0b60d0 */
if(!s->budget--) { s->failed_pc=0x0c0b60d0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b60d2;
P_0c0b60d2: /* original 945f, guest PC 0x0c0b60d2 */
if(!s->budget--) { s->failed_pc=0x0c0b60d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6194u,2);
goto P_0c0b60d4;
P_0c0b60d4: /* original e074, guest PC 0x0c0b60d4 */
if(!s->budget--) { s->failed_pc=0x0c0b60d4u; return 0; }
r[0]=0x00000074u;
goto P_0c0b60d6;
P_0c0b60d6: /* original 4e0b, guest PC 0x0c0b60d6 */
if(!s->budget--) { s->failed_pc=0x0c0b60d6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b60dau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b60dau) { target=s->pc; goto dispatch; }
goto P_0c0b60da;
P_0c0b60d8: /* original 05de, guest PC 0x0c0b60d8 */
if(!s->budget--) { s->failed_pc=0x0c0b60d8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b60da;
P_0c0b60da: /* original 945c, guest PC 0x0c0b60da */
if(!s->budget--) { s->failed_pc=0x0c0b60dau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6196u,2);
goto P_0c0b60dc;
P_0c0b60dc: /* original e078, guest PC 0x0c0b60dc */
if(!s->budget--) { s->failed_pc=0x0c0b60dcu; return 0; }
r[0]=0x00000078u;
goto P_0c0b60de;
P_0c0b60de: /* original 4e0b, guest PC 0x0c0b60de */
if(!s->budget--) { s->failed_pc=0x0c0b60deu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b60e2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b60e2u) { target=s->pc; goto dispatch; }
goto P_0c0b60e2;
P_0c0b60e0: /* original 05de, guest PC 0x0c0b60e0 */
if(!s->budget--) { s->failed_pc=0x0c0b60e0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b60e2;
P_0c0b60e2: /* original 9459, guest PC 0x0c0b60e2 */
if(!s->budget--) { s->failed_pc=0x0c0b60e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6198u,2);
goto P_0c0b60e4;
P_0c0b60e4: /* original e07c, guest PC 0x0c0b60e4 */
if(!s->budget--) { s->failed_pc=0x0c0b60e4u; return 0; }
r[0]=0x0000007cu;
goto P_0c0b60e6;
P_0c0b60e6: /* original 4e0b, guest PC 0x0c0b60e6 */
if(!s->budget--) { s->failed_pc=0x0c0b60e6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b60eau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b60eau) { target=s->pc; goto dispatch; }
goto P_0c0b60ea;
P_0c0b60e8: /* original 05de, guest PC 0x0c0b60e8 */
if(!s->budget--) { s->failed_pc=0x0c0b60e8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b60ea;
P_0c0b60ea: /* original 9457, guest PC 0x0c0b60ea */
if(!s->budget--) { s->failed_pc=0x0c0b60eau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b619cu,2);
goto P_0c0b60ec;
P_0c0b60ec: /* original 9055, guest PC 0x0c0b60ec */
if(!s->budget--) { s->failed_pc=0x0c0b60ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b619au,2);
goto P_0c0b60ee;
P_0c0b60ee: /* original 4e0b, guest PC 0x0c0b60ee */
if(!s->budget--) { s->failed_pc=0x0c0b60eeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b60f2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b60f2u) { target=s->pc; goto dispatch; }
goto P_0c0b60f2;
P_0c0b60f0: /* original 05de, guest PC 0x0c0b60f0 */
if(!s->budget--) { s->failed_pc=0x0c0b60f0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b60f2;
P_0c0b60f2: /* original 9554, guest PC 0x0c0b60f2 */
if(!s->budget--) { s->failed_pc=0x0c0b60f2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b619eu,2);
goto P_0c0b60f4;
P_0c0b60f4: /* original 35dc, guest PC 0x0c0b60f4 */
if(!s->budget--) { s->failed_pc=0x0c0b60f4u; return 0; }
r[5]+=r[13];
goto P_0c0b60f6;
P_0c0b60f6: /* original 2f52, guest PC 0x0c0b60f6 */
if(!s->budget--) { s->failed_pc=0x0c0b60f6u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b60f8;
P_0c0b60f8: /* original 9452, guest PC 0x0c0b60f8 */
if(!s->budget--) { s->failed_pc=0x0c0b60f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b61a0u,2);
goto P_0c0b60fa;
P_0c0b60fa: /* original 4e0b, guest PC 0x0c0b60fa */
if(!s->budget--) { s->failed_pc=0x0c0b60fau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b60feu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b60feu) { target=s->pc; goto dispatch; }
goto P_0c0b60fe;
P_0c0b60fc: /* original 6552, guest PC 0x0c0b60fc */
if(!s->budget--) { s->failed_pc=0x0c0b60fcu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b60fe;
P_0c0b60fe: /* original 9550, guest PC 0x0c0b60fe */
if(!s->budget--) { s->failed_pc=0x0c0b60feu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b61a2u,2);
goto P_0c0b6100;
P_0c0b6100: /* original 35dc, guest PC 0x0c0b6100 */
if(!s->budget--) { s->failed_pc=0x0c0b6100u; return 0; }
r[5]+=r[13];
goto P_0c0b6102;
P_0c0b6102: /* original 1f51, guest PC 0x0c0b6102 */
if(!s->budget--) { s->failed_pc=0x0c0b6102u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0b6104;
P_0c0b6104: /* original 944e, guest PC 0x0c0b6104 */
if(!s->budget--) { s->failed_pc=0x0c0b6104u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b61a4u,2);
goto P_0c0b6106;
P_0c0b6106: /* original 4e0b, guest PC 0x0c0b6106 */
if(!s->budget--) { s->failed_pc=0x0c0b6106u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b610au;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b610au) { target=s->pc; goto dispatch; }
goto P_0c0b610a;
P_0c0b6108: /* original 6552, guest PC 0x0c0b6108 */
if(!s->budget--) { s->failed_pc=0x0c0b6108u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b610a;
P_0c0b610a: /* original 944d, guest PC 0x0c0b610a */
if(!s->budget--) { s->failed_pc=0x0c0b610au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b61a8u,2);
goto P_0c0b610c;
P_0c0b610c: /* original 904b, guest PC 0x0c0b610c */
if(!s->budget--) { s->failed_pc=0x0c0b610cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b61a6u,2);
goto P_0c0b610e;
P_0c0b610e: /* original 4e0b, guest PC 0x0c0b610e */
if(!s->budget--) { s->failed_pc=0x0c0b610eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6112u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6112u) { target=s->pc; goto dispatch; }
goto P_0c0b6112;
P_0c0b6110: /* original 05de, guest PC 0x0c0b6110 */
if(!s->budget--) { s->failed_pc=0x0c0b6110u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6112;
P_0c0b6112: /* original 944b, guest PC 0x0c0b6112 */
if(!s->budget--) { s->failed_pc=0x0c0b6112u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b61acu,2);
goto P_0c0b6114;
P_0c0b6114: /* original 9049, guest PC 0x0c0b6114 */
if(!s->budget--) { s->failed_pc=0x0c0b6114u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b61aau,2);
goto P_0c0b6116;
P_0c0b6116: /* original 4e0b, guest PC 0x0c0b6116 */
if(!s->budget--) { s->failed_pc=0x0c0b6116u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b611au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b611au) { target=s->pc; goto dispatch; }
goto P_0c0b611a;
P_0c0b6118: /* original 05de, guest PC 0x0c0b6118 */
if(!s->budget--) { s->failed_pc=0x0c0b6118u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b611a;
P_0c0b611a: /* original 9948, guest PC 0x0c0b611a */
if(!s->budget--) { s->failed_pc=0x0c0b611au; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b61aeu,2);
goto P_0c0b611c;
P_0c0b611c: /* original 9448, guest PC 0x0c0b611c */
if(!s->budget--) { s->failed_pc=0x0c0b611cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b61b0u,2);
goto P_0c0b611e;
P_0c0b611e: /* original 39dc, guest PC 0x0c0b611e */
if(!s->budget--) { s->failed_pc=0x0c0b611eu; return 0; }
r[9]+=r[13];
goto P_0c0b6120;
P_0c0b6120: /* original 4e0b, guest PC 0x0c0b6120 */
if(!s->budget--) { s->failed_pc=0x0c0b6120u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6124u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6124u) { target=s->pc; goto dispatch; }
goto P_0c0b6124;
P_0c0b6122: /* original 6592, guest PC 0x0c0b6122 */
if(!s->budget--) { s->failed_pc=0x0c0b6122u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b6124;
P_0c0b6124: /* original 9445, guest PC 0x0c0b6124 */
if(!s->budget--) { s->failed_pc=0x0c0b6124u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b61b2u,2);
goto P_0c0b6126;
P_0c0b6126: /* original 4e0b, guest PC 0x0c0b6126 */
if(!s->budget--) { s->failed_pc=0x0c0b6126u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b612au;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b612au) { target=s->pc; goto dispatch; }
goto P_0c0b612a;
P_0c0b6128: /* original 6592, guest PC 0x0c0b6128 */
if(!s->budget--) { s->failed_pc=0x0c0b6128u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b612a;
P_0c0b612a: /* original 9443, guest PC 0x0c0b612a */
if(!s->budget--) { s->failed_pc=0x0c0b612au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b61b4u,2);
goto P_0c0b612c;
P_0c0b612c: /* original 4e0b, guest PC 0x0c0b612c */
if(!s->budget--) { s->failed_pc=0x0c0b612cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6130u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6130u) { target=s->pc; goto dispatch; }
goto P_0c0b6130;
P_0c0b612e: /* original 6592, guest PC 0x0c0b612e */
if(!s->budget--) { s->failed_pc=0x0c0b612eu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b6130;
P_0c0b6130: /* original 9441, guest PC 0x0c0b6130 */
if(!s->budget--) { s->failed_pc=0x0c0b6130u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b61b6u,2);
goto P_0c0b6132;
P_0c0b6132: /* original 4e0b, guest PC 0x0c0b6132 */
if(!s->budget--) { s->failed_pc=0x0c0b6132u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6136u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6136u) { target=s->pc; goto dispatch; }
goto P_0c0b6136;
P_0c0b6134: /* original 6592, guest PC 0x0c0b6134 */
if(!s->budget--) { s->failed_pc=0x0c0b6134u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b6136;
P_0c0b6136: /* original 9c3f, guest PC 0x0c0b6136 */
if(!s->budget--) { s->failed_pc=0x0c0b6136u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b61b8u,2);
goto P_0c0b6138;
P_0c0b6138: /* original 943f, guest PC 0x0c0b6138 */
if(!s->budget--) { s->failed_pc=0x0c0b6138u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b61bau,2);
goto P_0c0b613a;
P_0c0b613a: /* original 3cdc, guest PC 0x0c0b613a */
if(!s->budget--) { s->failed_pc=0x0c0b613au; return 0; }
r[12]+=r[13];
goto P_0c0b613c;
P_0c0b613c: /* original 4e0b, guest PC 0x0c0b613c */
if(!s->budget--) { s->failed_pc=0x0c0b613cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6140u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6140u) { target=s->pc; goto dispatch; }
goto P_0c0b6140;
P_0c0b613e: /* original 65c2, guest PC 0x0c0b613e */
if(!s->budget--) { s->failed_pc=0x0c0b613eu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b6140;
P_0c0b6140: /* original 943c, guest PC 0x0c0b6140 */
if(!s->budget--) { s->failed_pc=0x0c0b6140u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b61bcu,2);
goto P_0c0b6142;
P_0c0b6142: /* original 4e0b, guest PC 0x0c0b6142 */
if(!s->budget--) { s->failed_pc=0x0c0b6142u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6146u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6146u) { target=s->pc; goto dispatch; }
goto P_0c0b6146;
P_0c0b6144: /* original 65c2, guest PC 0x0c0b6144 */
if(!s->budget--) { s->failed_pc=0x0c0b6144u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b6146;
P_0c0b6146: /* original 943a, guest PC 0x0c0b6146 */
if(!s->budget--) { s->failed_pc=0x0c0b6146u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b61beu,2);
goto P_0c0b6148;
P_0c0b6148: /* original 4e0b, guest PC 0x0c0b6148 */
if(!s->budget--) { s->failed_pc=0x0c0b6148u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b614cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b614cu) { target=s->pc; goto dispatch; }
goto P_0c0b614c;
P_0c0b614a: /* original 65c2, guest PC 0x0c0b614a */
if(!s->budget--) { s->failed_pc=0x0c0b614au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b614c;
P_0c0b614c: /* original 9438, guest PC 0x0c0b614c */
if(!s->budget--) { s->failed_pc=0x0c0b614cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b61c0u,2);
goto P_0c0b614e;
P_0c0b614e: /* original 4e0b, guest PC 0x0c0b614e */
if(!s->budget--) { s->failed_pc=0x0c0b614eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6152u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6152u) { target=s->pc; goto dispatch; }
goto P_0c0b6152;
P_0c0b6150: /* original 65c2, guest PC 0x0c0b6150 */
if(!s->budget--) { s->failed_pc=0x0c0b6150u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b6152;
P_0c0b6152: /* original 9b36, guest PC 0x0c0b6152 */
if(!s->budget--) { s->failed_pc=0x0c0b6152u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b61c2u,2);
goto P_0c0b6154;
P_0c0b6154: /* original 3bdc, guest PC 0x0c0b6154 */
if(!s->budget--) { s->failed_pc=0x0c0b6154u; return 0; }
r[11]+=r[13];
goto P_0c0b6156;
P_0c0b6156: /* original a037, guest PC 0x0c0b6156 */
if(!s->budget--) { s->failed_pc=0x0c0b6156u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b61c8;
P_0c0b6158: /* original 65b2, guest PC 0x0c0b6158 */
if(!s->budget--) { s->failed_pc=0x0c0b6158u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0b615au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b615au; return 0; } return 1;
P_0c0b61c8: /* original 94ab, guest PC 0x0c0b61c8 */
if(!s->budget--) { s->failed_pc=0x0c0b61c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6322u,2);
goto P_0c0b61ca;
P_0c0b61ca: /* original 4e0b, guest PC 0x0c0b61ca */
if(!s->budget--) { s->failed_pc=0x0c0b61cau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b61ceu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b61ceu) { target=s->pc; goto dispatch; }
goto P_0c0b61ce;
P_0c0b61cc: /* original 0009, guest PC 0x0c0b61cc */
if(!s->budget--) { s->failed_pc=0x0c0b61ccu; return 0; }
goto P_0c0b61ce;
P_0c0b61ce: /* original 94a9, guest PC 0x0c0b61ce */
if(!s->budget--) { s->failed_pc=0x0c0b61ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6324u,2);
goto P_0c0b61d0;
P_0c0b61d0: /* original 4e0b, guest PC 0x0c0b61d0 */
if(!s->budget--) { s->failed_pc=0x0c0b61d0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b61d4u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b61d4u) { target=s->pc; goto dispatch; }
goto P_0c0b61d4;
P_0c0b61d2: /* original 65b2, guest PC 0x0c0b61d2 */
if(!s->budget--) { s->failed_pc=0x0c0b61d2u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b61d4;
P_0c0b61d4: /* original 94a7, guest PC 0x0c0b61d4 */
if(!s->budget--) { s->failed_pc=0x0c0b61d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6326u,2);
goto P_0c0b61d6;
P_0c0b61d6: /* original 4e0b, guest PC 0x0c0b61d6 */
if(!s->budget--) { s->failed_pc=0x0c0b61d6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b61dau;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b61dau) { target=s->pc; goto dispatch; }
goto P_0c0b61da;
P_0c0b61d8: /* original 65b2, guest PC 0x0c0b61d8 */
if(!s->budget--) { s->failed_pc=0x0c0b61d8u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b61da;
P_0c0b61da: /* original 94a5, guest PC 0x0c0b61da */
if(!s->budget--) { s->failed_pc=0x0c0b61dau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6328u,2);
goto P_0c0b61dc;
P_0c0b61dc: /* original 4e0b, guest PC 0x0c0b61dc */
if(!s->budget--) { s->failed_pc=0x0c0b61dcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b61e0u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b61e0u) { target=s->pc; goto dispatch; }
goto P_0c0b61e0;
P_0c0b61de: /* original 65b2, guest PC 0x0c0b61de */
if(!s->budget--) { s->failed_pc=0x0c0b61deu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b61e0;
P_0c0b61e0: /* original 9aa3, guest PC 0x0c0b61e0 */
if(!s->budget--) { s->failed_pc=0x0c0b61e0u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b632au,2);
goto P_0c0b61e2;
P_0c0b61e2: /* original 94a3, guest PC 0x0c0b61e2 */
if(!s->budget--) { s->failed_pc=0x0c0b61e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b632cu,2);
goto P_0c0b61e4;
P_0c0b61e4: /* original 3adc, guest PC 0x0c0b61e4 */
if(!s->budget--) { s->failed_pc=0x0c0b61e4u; return 0; }
r[10]+=r[13];
goto P_0c0b61e6;
P_0c0b61e6: /* original 4e0b, guest PC 0x0c0b61e6 */
if(!s->budget--) { s->failed_pc=0x0c0b61e6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b61eau;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b61eau) { target=s->pc; goto dispatch; }
goto P_0c0b61ea;
P_0c0b61e8: /* original 65a2, guest PC 0x0c0b61e8 */
if(!s->budget--) { s->failed_pc=0x0c0b61e8u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b61ea;
P_0c0b61ea: /* original 94a0, guest PC 0x0c0b61ea */
if(!s->budget--) { s->failed_pc=0x0c0b61eau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b632eu,2);
goto P_0c0b61ec;
P_0c0b61ec: /* original 4e0b, guest PC 0x0c0b61ec */
if(!s->budget--) { s->failed_pc=0x0c0b61ecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b61f0u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b61f0u) { target=s->pc; goto dispatch; }
goto P_0c0b61f0;
P_0c0b61ee: /* original 65a2, guest PC 0x0c0b61ee */
if(!s->budget--) { s->failed_pc=0x0c0b61eeu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b61f0;
P_0c0b61f0: /* original 949e, guest PC 0x0c0b61f0 */
if(!s->budget--) { s->failed_pc=0x0c0b61f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6330u,2);
goto P_0c0b61f2;
P_0c0b61f2: /* original 4e0b, guest PC 0x0c0b61f2 */
if(!s->budget--) { s->failed_pc=0x0c0b61f2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b61f6u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b61f6u) { target=s->pc; goto dispatch; }
goto P_0c0b61f6;
P_0c0b61f4: /* original 65a2, guest PC 0x0c0b61f4 */
if(!s->budget--) { s->failed_pc=0x0c0b61f4u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b61f6;
P_0c0b61f6: /* original 949c, guest PC 0x0c0b61f6 */
if(!s->budget--) { s->failed_pc=0x0c0b61f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6332u,2);
goto P_0c0b61f8;
P_0c0b61f8: /* original 4e0b, guest PC 0x0c0b61f8 */
if(!s->budget--) { s->failed_pc=0x0c0b61f8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b61fcu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b61fcu) { target=s->pc; goto dispatch; }
goto P_0c0b61fc;
P_0c0b61fa: /* original 65a2, guest PC 0x0c0b61fa */
if(!s->budget--) { s->failed_pc=0x0c0b61fau; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b61fc;
P_0c0b61fc: /* original 949a, guest PC 0x0c0b61fc */
if(!s->budget--) { s->failed_pc=0x0c0b61fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6334u,2);
goto P_0c0b61fe;
P_0c0b61fe: /* original 65f2, guest PC 0x0c0b61fe */
if(!s->budget--) { s->failed_pc=0x0c0b61feu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b6200;
P_0c0b6200: /* original 4e0b, guest PC 0x0c0b6200 */
if(!s->budget--) { s->failed_pc=0x0c0b6200u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6204u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6204u) { target=s->pc; goto dispatch; }
goto P_0c0b6204;
P_0c0b6202: /* original 6552, guest PC 0x0c0b6202 */
if(!s->budget--) { s->failed_pc=0x0c0b6202u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b6204;
P_0c0b6204: /* original 9497, guest PC 0x0c0b6204 */
if(!s->budget--) { s->failed_pc=0x0c0b6204u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6336u,2);
goto P_0c0b6206;
P_0c0b6206: /* original 55f1, guest PC 0x0c0b6206 */
if(!s->budget--) { s->failed_pc=0x0c0b6206u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0b6208;
P_0c0b6208: /* original 4e0b, guest PC 0x0c0b6208 */
if(!s->budget--) { s->failed_pc=0x0c0b6208u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b620cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b620cu) { target=s->pc; goto dispatch; }
goto P_0c0b620c;
P_0c0b620a: /* original 6552, guest PC 0x0c0b620a */
if(!s->budget--) { s->failed_pc=0x0c0b620au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b620c;
P_0c0b620c: /* original 9494, guest PC 0x0c0b620c */
if(!s->budget--) { s->failed_pc=0x0c0b620cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6338u,2);
goto P_0c0b620e;
P_0c0b620e: /* original 4e0b, guest PC 0x0c0b620e */
if(!s->budget--) { s->failed_pc=0x0c0b620eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6212u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6212u) { target=s->pc; goto dispatch; }
goto P_0c0b6212;
P_0c0b6210: /* original 6592, guest PC 0x0c0b6210 */
if(!s->budget--) { s->failed_pc=0x0c0b6210u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b6212;
P_0c0b6212: /* original 9492, guest PC 0x0c0b6212 */
if(!s->budget--) { s->failed_pc=0x0c0b6212u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b633au,2);
goto P_0c0b6214;
P_0c0b6214: /* original 4e0b, guest PC 0x0c0b6214 */
if(!s->budget--) { s->failed_pc=0x0c0b6214u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6218u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6218u) { target=s->pc; goto dispatch; }
goto P_0c0b6218;
P_0c0b6216: /* original 6592, guest PC 0x0c0b6216 */
if(!s->budget--) { s->failed_pc=0x0c0b6216u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b6218;
P_0c0b6218: /* original 9490, guest PC 0x0c0b6218 */
if(!s->budget--) { s->failed_pc=0x0c0b6218u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b633cu,2);
goto P_0c0b621a;
P_0c0b621a: /* original 4e0b, guest PC 0x0c0b621a */
if(!s->budget--) { s->failed_pc=0x0c0b621au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b621eu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b621eu) { target=s->pc; goto dispatch; }
goto P_0c0b621e;
P_0c0b621c: /* original 6592, guest PC 0x0c0b621c */
if(!s->budget--) { s->failed_pc=0x0c0b621cu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b621e;
P_0c0b621e: /* original 948e, guest PC 0x0c0b621e */
if(!s->budget--) { s->failed_pc=0x0c0b621eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b633eu,2);
goto P_0c0b6220;
P_0c0b6220: /* original 4e0b, guest PC 0x0c0b6220 */
if(!s->budget--) { s->failed_pc=0x0c0b6220u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6224u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6224u) { target=s->pc; goto dispatch; }
goto P_0c0b6224;
P_0c0b6222: /* original 6592, guest PC 0x0c0b6222 */
if(!s->budget--) { s->failed_pc=0x0c0b6222u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b6224;
P_0c0b6224: /* original 948c, guest PC 0x0c0b6224 */
if(!s->budget--) { s->failed_pc=0x0c0b6224u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6340u,2);
goto P_0c0b6226;
P_0c0b6226: /* original 4e0b, guest PC 0x0c0b6226 */
if(!s->budget--) { s->failed_pc=0x0c0b6226u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b622au;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b622au) { target=s->pc; goto dispatch; }
goto P_0c0b622a;
P_0c0b6228: /* original 65c2, guest PC 0x0c0b6228 */
if(!s->budget--) { s->failed_pc=0x0c0b6228u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b622a;
P_0c0b622a: /* original 948a, guest PC 0x0c0b622a */
if(!s->budget--) { s->failed_pc=0x0c0b622au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6342u,2);
goto P_0c0b622c;
P_0c0b622c: /* original 4e0b, guest PC 0x0c0b622c */
if(!s->budget--) { s->failed_pc=0x0c0b622cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6230u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6230u) { target=s->pc; goto dispatch; }
goto P_0c0b6230;
P_0c0b622e: /* original 65c2, guest PC 0x0c0b622e */
if(!s->budget--) { s->failed_pc=0x0c0b622eu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b6230;
P_0c0b6230: /* original 9488, guest PC 0x0c0b6230 */
if(!s->budget--) { s->failed_pc=0x0c0b6230u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6344u,2);
goto P_0c0b6232;
P_0c0b6232: /* original 4e0b, guest PC 0x0c0b6232 */
if(!s->budget--) { s->failed_pc=0x0c0b6232u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6236u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6236u) { target=s->pc; goto dispatch; }
goto P_0c0b6236;
P_0c0b6234: /* original 65c2, guest PC 0x0c0b6234 */
if(!s->budget--) { s->failed_pc=0x0c0b6234u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b6236;
P_0c0b6236: /* original 9486, guest PC 0x0c0b6236 */
if(!s->budget--) { s->failed_pc=0x0c0b6236u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6346u,2);
goto P_0c0b6238;
P_0c0b6238: /* original 4e0b, guest PC 0x0c0b6238 */
if(!s->budget--) { s->failed_pc=0x0c0b6238u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b623cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b623cu) { target=s->pc; goto dispatch; }
goto P_0c0b623c;
P_0c0b623a: /* original 65c2, guest PC 0x0c0b623a */
if(!s->budget--) { s->failed_pc=0x0c0b623au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b623c;
P_0c0b623c: /* original 9484, guest PC 0x0c0b623c */
if(!s->budget--) { s->failed_pc=0x0c0b623cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6348u,2);
goto P_0c0b623e;
P_0c0b623e: /* original 4e0b, guest PC 0x0c0b623e */
if(!s->budget--) { s->failed_pc=0x0c0b623eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6242u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6242u) { target=s->pc; goto dispatch; }
goto P_0c0b6242;
P_0c0b6240: /* original 65b2, guest PC 0x0c0b6240 */
if(!s->budget--) { s->failed_pc=0x0c0b6240u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b6242;
P_0c0b6242: /* original 9482, guest PC 0x0c0b6242 */
if(!s->budget--) { s->failed_pc=0x0c0b6242u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b634au,2);
goto P_0c0b6244;
P_0c0b6244: /* original 4e0b, guest PC 0x0c0b6244 */
if(!s->budget--) { s->failed_pc=0x0c0b6244u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6248u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6248u) { target=s->pc; goto dispatch; }
goto P_0c0b6248;
P_0c0b6246: /* original 65b2, guest PC 0x0c0b6246 */
if(!s->budget--) { s->failed_pc=0x0c0b6246u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b6248;
P_0c0b6248: /* original 9480, guest PC 0x0c0b6248 */
if(!s->budget--) { s->failed_pc=0x0c0b6248u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b634cu,2);
goto P_0c0b624a;
P_0c0b624a: /* original 4e0b, guest PC 0x0c0b624a */
if(!s->budget--) { s->failed_pc=0x0c0b624au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b624eu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b624eu) { target=s->pc; goto dispatch; }
goto P_0c0b624e;
P_0c0b624c: /* original 65b2, guest PC 0x0c0b624c */
if(!s->budget--) { s->failed_pc=0x0c0b624cu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b624e;
P_0c0b624e: /* original 947e, guest PC 0x0c0b624e */
if(!s->budget--) { s->failed_pc=0x0c0b624eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b634eu,2);
goto P_0c0b6250;
P_0c0b6250: /* original 4e0b, guest PC 0x0c0b6250 */
if(!s->budget--) { s->failed_pc=0x0c0b6250u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6254u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6254u) { target=s->pc; goto dispatch; }
goto P_0c0b6254;
P_0c0b6252: /* original 65b2, guest PC 0x0c0b6252 */
if(!s->budget--) { s->failed_pc=0x0c0b6252u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b6254;
P_0c0b6254: /* original 947c, guest PC 0x0c0b6254 */
if(!s->budget--) { s->failed_pc=0x0c0b6254u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6350u,2);
goto P_0c0b6256;
P_0c0b6256: /* original 4e0b, guest PC 0x0c0b6256 */
if(!s->budget--) { s->failed_pc=0x0c0b6256u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b625au;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b625au) { target=s->pc; goto dispatch; }
goto P_0c0b625a;
P_0c0b6258: /* original 65a2, guest PC 0x0c0b6258 */
if(!s->budget--) { s->failed_pc=0x0c0b6258u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b625a;
P_0c0b625a: /* original 947a, guest PC 0x0c0b625a */
if(!s->budget--) { s->failed_pc=0x0c0b625au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6352u,2);
goto P_0c0b625c;
P_0c0b625c: /* original 4e0b, guest PC 0x0c0b625c */
if(!s->budget--) { s->failed_pc=0x0c0b625cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6260u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6260u) { target=s->pc; goto dispatch; }
goto P_0c0b6260;
P_0c0b625e: /* original 65a2, guest PC 0x0c0b625e */
if(!s->budget--) { s->failed_pc=0x0c0b625eu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b6260;
P_0c0b6260: /* original 9478, guest PC 0x0c0b6260 */
if(!s->budget--) { s->failed_pc=0x0c0b6260u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6354u,2);
goto P_0c0b6262;
P_0c0b6262: /* original 4e0b, guest PC 0x0c0b6262 */
if(!s->budget--) { s->failed_pc=0x0c0b6262u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6266u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6266u) { target=s->pc; goto dispatch; }
goto P_0c0b6266;
P_0c0b6264: /* original 65a2, guest PC 0x0c0b6264 */
if(!s->budget--) { s->failed_pc=0x0c0b6264u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b6266;
P_0c0b6266: /* original 9476, guest PC 0x0c0b6266 */
if(!s->budget--) { s->failed_pc=0x0c0b6266u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6356u,2);
goto P_0c0b6268;
P_0c0b6268: /* original 4e0b, guest PC 0x0c0b6268 */
if(!s->budget--) { s->failed_pc=0x0c0b6268u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b626cu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b626cu) { target=s->pc; goto dispatch; }
goto P_0c0b626c;
P_0c0b626a: /* original 65a2, guest PC 0x0c0b626a */
if(!s->budget--) { s->failed_pc=0x0c0b626au; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b626c;
P_0c0b626c: /* original 9574, guest PC 0x0c0b626c */
if(!s->budget--) { s->failed_pc=0x0c0b626cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6358u,2);
goto P_0c0b626e;
P_0c0b626e: /* original 35dc, guest PC 0x0c0b626e */
if(!s->budget--) { s->failed_pc=0x0c0b626eu; return 0; }
r[5]+=r[13];
goto P_0c0b6270;
P_0c0b6270: /* original 2f52, guest PC 0x0c0b6270 */
if(!s->budget--) { s->failed_pc=0x0c0b6270u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b6272;
P_0c0b6272: /* original 9472, guest PC 0x0c0b6272 */
if(!s->budget--) { s->failed_pc=0x0c0b6272u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b635au,2);
goto P_0c0b6274;
P_0c0b6274: /* original 4e0b, guest PC 0x0c0b6274 */
if(!s->budget--) { s->failed_pc=0x0c0b6274u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6278u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6278u) { target=s->pc; goto dispatch; }
goto P_0c0b6278;
P_0c0b6276: /* original 6552, guest PC 0x0c0b6276 */
if(!s->budget--) { s->failed_pc=0x0c0b6276u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b6278;
P_0c0b6278: /* original 9470, guest PC 0x0c0b6278 */
if(!s->budget--) { s->failed_pc=0x0c0b6278u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b635cu,2);
goto P_0c0b627a;
P_0c0b627a: /* original 65f2, guest PC 0x0c0b627a */
if(!s->budget--) { s->failed_pc=0x0c0b627au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b627c;
P_0c0b627c: /* original 4e0b, guest PC 0x0c0b627c */
if(!s->budget--) { s->failed_pc=0x0c0b627cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6280u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6280u) { target=s->pc; goto dispatch; }
goto P_0c0b6280;
P_0c0b627e: /* original 6552, guest PC 0x0c0b627e */
if(!s->budget--) { s->failed_pc=0x0c0b627eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b6280;
P_0c0b6280: /* original 956d, guest PC 0x0c0b6280 */
if(!s->budget--) { s->failed_pc=0x0c0b6280u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b635eu,2);
goto P_0c0b6282;
P_0c0b6282: /* original 35dc, guest PC 0x0c0b6282 */
if(!s->budget--) { s->failed_pc=0x0c0b6282u; return 0; }
r[5]+=r[13];
goto P_0c0b6284;
P_0c0b6284: /* original 2f52, guest PC 0x0c0b6284 */
if(!s->budget--) { s->failed_pc=0x0c0b6284u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b6286;
P_0c0b6286: /* original 946b, guest PC 0x0c0b6286 */
if(!s->budget--) { s->failed_pc=0x0c0b6286u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6360u,2);
goto P_0c0b6288;
P_0c0b6288: /* original 4e0b, guest PC 0x0c0b6288 */
if(!s->budget--) { s->failed_pc=0x0c0b6288u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b628cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b628cu) { target=s->pc; goto dispatch; }
goto P_0c0b628c;
P_0c0b628a: /* original 6552, guest PC 0x0c0b628a */
if(!s->budget--) { s->failed_pc=0x0c0b628au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b628c;
P_0c0b628c: /* original 9469, guest PC 0x0c0b628c */
if(!s->budget--) { s->failed_pc=0x0c0b628cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6362u,2);
goto P_0c0b628e;
P_0c0b628e: /* original 65f2, guest PC 0x0c0b628e */
if(!s->budget--) { s->failed_pc=0x0c0b628eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b6290;
P_0c0b6290: /* original 4e0b, guest PC 0x0c0b6290 */
if(!s->budget--) { s->failed_pc=0x0c0b6290u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6294u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6294u) { target=s->pc; goto dispatch; }
goto P_0c0b6294;
P_0c0b6292: /* original 6552, guest PC 0x0c0b6292 */
if(!s->budget--) { s->failed_pc=0x0c0b6292u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b6294;
P_0c0b6294: /* original 9467, guest PC 0x0c0b6294 */
if(!s->budget--) { s->failed_pc=0x0c0b6294u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6366u,2);
goto P_0c0b6296;
P_0c0b6296: /* original 9065, guest PC 0x0c0b6296 */
if(!s->budget--) { s->failed_pc=0x0c0b6296u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6364u,2);
goto P_0c0b6298;
P_0c0b6298: /* original 4e0b, guest PC 0x0c0b6298 */
if(!s->budget--) { s->failed_pc=0x0c0b6298u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b629cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b629cu) { target=s->pc; goto dispatch; }
goto P_0c0b629c;
P_0c0b629a: /* original 05de, guest PC 0x0c0b629a */
if(!s->budget--) { s->failed_pc=0x0c0b629au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b629c;
P_0c0b629c: /* original 9564, guest PC 0x0c0b629c */
if(!s->budget--) { s->failed_pc=0x0c0b629cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6368u,2);
goto P_0c0b629e;
P_0c0b629e: /* original 35dc, guest PC 0x0c0b629e */
if(!s->budget--) { s->failed_pc=0x0c0b629eu; return 0; }
r[5]+=r[13];
goto P_0c0b62a0;
P_0c0b62a0: /* original 2f52, guest PC 0x0c0b62a0 */
if(!s->budget--) { s->failed_pc=0x0c0b62a0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b62a2;
P_0c0b62a2: /* original 9462, guest PC 0x0c0b62a2 */
if(!s->budget--) { s->failed_pc=0x0c0b62a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b636au,2);
goto P_0c0b62a4;
P_0c0b62a4: /* original 4e0b, guest PC 0x0c0b62a4 */
if(!s->budget--) { s->failed_pc=0x0c0b62a4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b62a8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b62a8u) { target=s->pc; goto dispatch; }
goto P_0c0b62a8;
P_0c0b62a6: /* original 6552, guest PC 0x0c0b62a6 */
if(!s->budget--) { s->failed_pc=0x0c0b62a6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b62a8;
P_0c0b62a8: /* original 9460, guest PC 0x0c0b62a8 */
if(!s->budget--) { s->failed_pc=0x0c0b62a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b636cu,2);
goto P_0c0b62aa;
P_0c0b62aa: /* original 65f2, guest PC 0x0c0b62aa */
if(!s->budget--) { s->failed_pc=0x0c0b62aau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b62ac;
P_0c0b62ac: /* original 4e0b, guest PC 0x0c0b62ac */
if(!s->budget--) { s->failed_pc=0x0c0b62acu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b62b0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b62b0u) { target=s->pc; goto dispatch; }
goto P_0c0b62b0;
P_0c0b62ae: /* original 6552, guest PC 0x0c0b62ae */
if(!s->budget--) { s->failed_pc=0x0c0b62aeu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b62b0;
P_0c0b62b0: /* original 945e, guest PC 0x0c0b62b0 */
if(!s->budget--) { s->failed_pc=0x0c0b62b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6370u,2);
goto P_0c0b62b2;
P_0c0b62b2: /* original 905c, guest PC 0x0c0b62b2 */
if(!s->budget--) { s->failed_pc=0x0c0b62b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b636eu,2);
goto P_0c0b62b4;
P_0c0b62b4: /* original 4e0b, guest PC 0x0c0b62b4 */
if(!s->budget--) { s->failed_pc=0x0c0b62b4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b62b8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b62b8u) { target=s->pc; goto dispatch; }
goto P_0c0b62b8;
P_0c0b62b6: /* original 05de, guest PC 0x0c0b62b6 */
if(!s->budget--) { s->failed_pc=0x0c0b62b6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b62b8;
P_0c0b62b8: /* original 955b, guest PC 0x0c0b62b8 */
if(!s->budget--) { s->failed_pc=0x0c0b62b8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6372u,2);
goto P_0c0b62ba;
P_0c0b62ba: /* original 35dc, guest PC 0x0c0b62ba */
if(!s->budget--) { s->failed_pc=0x0c0b62bau; return 0; }
r[5]+=r[13];
goto P_0c0b62bc;
P_0c0b62bc: /* original 2f52, guest PC 0x0c0b62bc */
if(!s->budget--) { s->failed_pc=0x0c0b62bcu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b62be;
P_0c0b62be: /* original 9459, guest PC 0x0c0b62be */
if(!s->budget--) { s->failed_pc=0x0c0b62beu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6374u,2);
goto P_0c0b62c0;
P_0c0b62c0: /* original 4e0b, guest PC 0x0c0b62c0 */
if(!s->budget--) { s->failed_pc=0x0c0b62c0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b62c4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b62c4u) { target=s->pc; goto dispatch; }
goto P_0c0b62c4;
P_0c0b62c2: /* original 6552, guest PC 0x0c0b62c2 */
if(!s->budget--) { s->failed_pc=0x0c0b62c2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b62c4;
P_0c0b62c4: /* original 9457, guest PC 0x0c0b62c4 */
if(!s->budget--) { s->failed_pc=0x0c0b62c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6376u,2);
goto P_0c0b62c6;
P_0c0b62c6: /* original 65f2, guest PC 0x0c0b62c6 */
if(!s->budget--) { s->failed_pc=0x0c0b62c6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b62c8;
P_0c0b62c8: /* original 4e0b, guest PC 0x0c0b62c8 */
if(!s->budget--) { s->failed_pc=0x0c0b62c8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b62ccu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b62ccu) { target=s->pc; goto dispatch; }
goto P_0c0b62cc;
P_0c0b62ca: /* original 6552, guest PC 0x0c0b62ca */
if(!s->budget--) { s->failed_pc=0x0c0b62cau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b62cc;
P_0c0b62cc: /* original 9455, guest PC 0x0c0b62cc */
if(!s->budget--) { s->failed_pc=0x0c0b62ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b637au,2);
goto P_0c0b62ce;
P_0c0b62ce: /* original 9053, guest PC 0x0c0b62ce */
if(!s->budget--) { s->failed_pc=0x0c0b62ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6378u,2);
goto P_0c0b62d0;
P_0c0b62d0: /* original 4e0b, guest PC 0x0c0b62d0 */
if(!s->budget--) { s->failed_pc=0x0c0b62d0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b62d4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b62d4u) { target=s->pc; goto dispatch; }
goto P_0c0b62d4;
P_0c0b62d2: /* original 05de, guest PC 0x0c0b62d2 */
if(!s->budget--) { s->failed_pc=0x0c0b62d2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b62d4;
P_0c0b62d4: /* original 9552, guest PC 0x0c0b62d4 */
if(!s->budget--) { s->failed_pc=0x0c0b62d4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b637cu,2);
goto P_0c0b62d6;
P_0c0b62d6: /* original 35dc, guest PC 0x0c0b62d6 */
if(!s->budget--) { s->failed_pc=0x0c0b62d6u; return 0; }
r[5]+=r[13];
goto P_0c0b62d8;
P_0c0b62d8: /* original 2f52, guest PC 0x0c0b62d8 */
if(!s->budget--) { s->failed_pc=0x0c0b62d8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b62da;
P_0c0b62da: /* original 9450, guest PC 0x0c0b62da */
if(!s->budget--) { s->failed_pc=0x0c0b62dau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b637eu,2);
goto P_0c0b62dc;
P_0c0b62dc: /* original 4e0b, guest PC 0x0c0b62dc */
if(!s->budget--) { s->failed_pc=0x0c0b62dcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b62e0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b62e0u) { target=s->pc; goto dispatch; }
goto P_0c0b62e0;
P_0c0b62de: /* original 6552, guest PC 0x0c0b62de */
if(!s->budget--) { s->failed_pc=0x0c0b62deu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b62e0;
P_0c0b62e0: /* original 944e, guest PC 0x0c0b62e0 */
if(!s->budget--) { s->failed_pc=0x0c0b62e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6380u,2);
goto P_0c0b62e2;
P_0c0b62e2: /* original 65f2, guest PC 0x0c0b62e2 */
if(!s->budget--) { s->failed_pc=0x0c0b62e2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b62e4;
P_0c0b62e4: /* original 4e0b, guest PC 0x0c0b62e4 */
if(!s->budget--) { s->failed_pc=0x0c0b62e4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b62e8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b62e8u) { target=s->pc; goto dispatch; }
goto P_0c0b62e8;
P_0c0b62e6: /* original 6552, guest PC 0x0c0b62e6 */
if(!s->budget--) { s->failed_pc=0x0c0b62e6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b62e8;
P_0c0b62e8: /* original 954b, guest PC 0x0c0b62e8 */
if(!s->budget--) { s->failed_pc=0x0c0b62e8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6382u,2);
goto P_0c0b62ea;
P_0c0b62ea: /* original 35dc, guest PC 0x0c0b62ea */
if(!s->budget--) { s->failed_pc=0x0c0b62eau; return 0; }
r[5]+=r[13];
goto P_0c0b62ec;
P_0c0b62ec: /* original 2f52, guest PC 0x0c0b62ec */
if(!s->budget--) { s->failed_pc=0x0c0b62ecu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b62ee;
P_0c0b62ee: /* original 9449, guest PC 0x0c0b62ee */
if(!s->budget--) { s->failed_pc=0x0c0b62eeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6384u,2);
goto P_0c0b62f0;
P_0c0b62f0: /* original 4e0b, guest PC 0x0c0b62f0 */
if(!s->budget--) { s->failed_pc=0x0c0b62f0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b62f4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b62f4u) { target=s->pc; goto dispatch; }
goto P_0c0b62f4;
P_0c0b62f2: /* original 6552, guest PC 0x0c0b62f2 */
if(!s->budget--) { s->failed_pc=0x0c0b62f2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b62f4;
P_0c0b62f4: /* original 9447, guest PC 0x0c0b62f4 */
if(!s->budget--) { s->failed_pc=0x0c0b62f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6386u,2);
goto P_0c0b62f6;
P_0c0b62f6: /* original 65f2, guest PC 0x0c0b62f6 */
if(!s->budget--) { s->failed_pc=0x0c0b62f6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b62f8;
P_0c0b62f8: /* original 4e0b, guest PC 0x0c0b62f8 */
if(!s->budget--) { s->failed_pc=0x0c0b62f8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b62fcu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b62fcu) { target=s->pc; goto dispatch; }
goto P_0c0b62fc;
P_0c0b62fa: /* original 6552, guest PC 0x0c0b62fa */
if(!s->budget--) { s->failed_pc=0x0c0b62fau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b62fc;
P_0c0b62fc: /* original 9445, guest PC 0x0c0b62fc */
if(!s->budget--) { s->failed_pc=0x0c0b62fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b638au,2);
goto P_0c0b62fe;
P_0c0b62fe: /* original 9043, guest PC 0x0c0b62fe */
if(!s->budget--) { s->failed_pc=0x0c0b62feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6388u,2);
goto P_0c0b6300;
P_0c0b6300: /* original 4e0b, guest PC 0x0c0b6300 */
if(!s->budget--) { s->failed_pc=0x0c0b6300u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6304u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6304u) { target=s->pc; goto dispatch; }
goto P_0c0b6304;
P_0c0b6302: /* original 05de, guest PC 0x0c0b6302 */
if(!s->budget--) { s->failed_pc=0x0c0b6302u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6304;
P_0c0b6304: /* original 9443, guest PC 0x0c0b6304 */
if(!s->budget--) { s->failed_pc=0x0c0b6304u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b638eu,2);
goto P_0c0b6306;
P_0c0b6306: /* original 9041, guest PC 0x0c0b6306 */
if(!s->budget--) { s->failed_pc=0x0c0b6306u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b638cu,2);
goto P_0c0b6308;
P_0c0b6308: /* original 4e0b, guest PC 0x0c0b6308 */
if(!s->budget--) { s->failed_pc=0x0c0b6308u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b630cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b630cu) { target=s->pc; goto dispatch; }
goto P_0c0b630c;
P_0c0b630a: /* original 05de, guest PC 0x0c0b630a */
if(!s->budget--) { s->failed_pc=0x0c0b630au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b630c;
P_0c0b630c: /* original 9441, guest PC 0x0c0b630c */
if(!s->budget--) { s->failed_pc=0x0c0b630cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6392u,2);
goto P_0c0b630e;
P_0c0b630e: /* original 903f, guest PC 0x0c0b630e */
if(!s->budget--) { s->failed_pc=0x0c0b630eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6390u,2);
goto P_0c0b6310;
P_0c0b6310: /* original 4e0b, guest PC 0x0c0b6310 */
if(!s->budget--) { s->failed_pc=0x0c0b6310u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6314u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6314u) { target=s->pc; goto dispatch; }
goto P_0c0b6314;
P_0c0b6312: /* original 05de, guest PC 0x0c0b6312 */
if(!s->budget--) { s->failed_pc=0x0c0b6312u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6314;
P_0c0b6314: /* original 943f, guest PC 0x0c0b6314 */
if(!s->budget--) { s->failed_pc=0x0c0b6314u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6396u,2);
goto P_0c0b6316;
P_0c0b6316: /* original 903d, guest PC 0x0c0b6316 */
if(!s->budget--) { s->failed_pc=0x0c0b6316u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6394u,2);
goto P_0c0b6318;
P_0c0b6318: /* original 4e0b, guest PC 0x0c0b6318 */
if(!s->budget--) { s->failed_pc=0x0c0b6318u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b631cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b631cu) { target=s->pc; goto dispatch; }
goto P_0c0b631c;
P_0c0b631a: /* original 05de, guest PC 0x0c0b631a */
if(!s->budget--) { s->failed_pc=0x0c0b631au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b631c;
P_0c0b631c: /* original 903c, guest PC 0x0c0b631c */
if(!s->budget--) { s->failed_pc=0x0c0b631cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6398u,2);
goto P_0c0b631e;
P_0c0b631e: /* original a03c, guest PC 0x0c0b631e */
if(!s->budget--) { s->failed_pc=0x0c0b631eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b639a;
P_0c0b6320: /* original 05de, guest PC 0x0c0b6320 */
if(!s->budget--) { s->failed_pc=0x0c0b6320u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0b6322u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b6322u; return 0; } return 1;
P_0c0b639a: /* original 942a, guest PC 0x0c0b639a */
if(!s->budget--) { s->failed_pc=0x0c0b639au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b63f2u,2);
goto P_0c0b639c;
P_0c0b639c: /* original 4e0b, guest PC 0x0c0b639c */
if(!s->budget--) { s->failed_pc=0x0c0b639cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b63a0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b63a0u) { target=s->pc; goto dispatch; }
goto P_0c0b63a0;
P_0c0b639e: /* original 0009, guest PC 0x0c0b639e */
if(!s->budget--) { s->failed_pc=0x0c0b639eu; return 0; }
goto P_0c0b63a0;
P_0c0b63a0: /* original 9429, guest PC 0x0c0b63a0 */
if(!s->budget--) { s->failed_pc=0x0c0b63a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b63f6u,2);
goto P_0c0b63a2;
P_0c0b63a2: /* original 9027, guest PC 0x0c0b63a2 */
if(!s->budget--) { s->failed_pc=0x0c0b63a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b63f4u,2);
goto P_0c0b63a4;
P_0c0b63a4: /* original 4e0b, guest PC 0x0c0b63a4 */
if(!s->budget--) { s->failed_pc=0x0c0b63a4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b63a8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b63a8u) { target=s->pc; goto dispatch; }
goto P_0c0b63a8;
P_0c0b63a6: /* original 05de, guest PC 0x0c0b63a6 */
if(!s->budget--) { s->failed_pc=0x0c0b63a6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b63a8;
P_0c0b63a8: /* original 9427, guest PC 0x0c0b63a8 */
if(!s->budget--) { s->failed_pc=0x0c0b63a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b63fau,2);
goto P_0c0b63aa;
P_0c0b63aa: /* original 9025, guest PC 0x0c0b63aa */
if(!s->budget--) { s->failed_pc=0x0c0b63aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b63f8u,2);
goto P_0c0b63ac;
P_0c0b63ac: /* original 4e0b, guest PC 0x0c0b63ac */
if(!s->budget--) { s->failed_pc=0x0c0b63acu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b63b0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b63b0u) { target=s->pc; goto dispatch; }
goto P_0c0b63b0;
P_0c0b63ae: /* original 05de, guest PC 0x0c0b63ae */
if(!s->budget--) { s->failed_pc=0x0c0b63aeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b63b0;
P_0c0b63b0: /* original 9425, guest PC 0x0c0b63b0 */
if(!s->budget--) { s->failed_pc=0x0c0b63b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b63feu,2);
goto P_0c0b63b2;
P_0c0b63b2: /* original 9023, guest PC 0x0c0b63b2 */
if(!s->budget--) { s->failed_pc=0x0c0b63b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b63fcu,2);
goto P_0c0b63b4;
P_0c0b63b4: /* original 4e0b, guest PC 0x0c0b63b4 */
if(!s->budget--) { s->failed_pc=0x0c0b63b4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b63b8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b63b8u) { target=s->pc; goto dispatch; }
goto P_0c0b63b8;
P_0c0b63b6: /* original 05de, guest PC 0x0c0b63b6 */
if(!s->budget--) { s->failed_pc=0x0c0b63b6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b63b8;
P_0c0b63b8: /* original 9423, guest PC 0x0c0b63b8 */
if(!s->budget--) { s->failed_pc=0x0c0b63b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6402u,2);
goto P_0c0b63ba;
P_0c0b63ba: /* original 9021, guest PC 0x0c0b63ba */
if(!s->budget--) { s->failed_pc=0x0c0b63bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6400u,2);
goto P_0c0b63bc;
P_0c0b63bc: /* original 4e0b, guest PC 0x0c0b63bc */
if(!s->budget--) { s->failed_pc=0x0c0b63bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b63c0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b63c0u) { target=s->pc; goto dispatch; }
goto P_0c0b63c0;
P_0c0b63be: /* original 05de, guest PC 0x0c0b63be */
if(!s->budget--) { s->failed_pc=0x0c0b63beu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b63c0;
P_0c0b63c0: /* original 9421, guest PC 0x0c0b63c0 */
if(!s->budget--) { s->failed_pc=0x0c0b63c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6406u,2);
goto P_0c0b63c2;
P_0c0b63c2: /* original 901f, guest PC 0x0c0b63c2 */
if(!s->budget--) { s->failed_pc=0x0c0b63c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6404u,2);
goto P_0c0b63c4;
P_0c0b63c4: /* original 4e0b, guest PC 0x0c0b63c4 */
if(!s->budget--) { s->failed_pc=0x0c0b63c4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b63c8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b63c8u) { target=s->pc; goto dispatch; }
goto P_0c0b63c8;
P_0c0b63c6: /* original 05de, guest PC 0x0c0b63c6 */
if(!s->budget--) { s->failed_pc=0x0c0b63c6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b63c8;
P_0c0b63c8: /* original 941f, guest PC 0x0c0b63c8 */
if(!s->budget--) { s->failed_pc=0x0c0b63c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b640au,2);
goto P_0c0b63ca;
P_0c0b63ca: /* original 901d, guest PC 0x0c0b63ca */
if(!s->budget--) { s->failed_pc=0x0c0b63cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6408u,2);
goto P_0c0b63cc;
P_0c0b63cc: /* original 4e0b, guest PC 0x0c0b63cc */
if(!s->budget--) { s->failed_pc=0x0c0b63ccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b63d0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b63d0u) { target=s->pc; goto dispatch; }
goto P_0c0b63d0;
P_0c0b63ce: /* original 05de, guest PC 0x0c0b63ce */
if(!s->budget--) { s->failed_pc=0x0c0b63ceu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b63d0;
P_0c0b63d0: /* original 941d, guest PC 0x0c0b63d0 */
if(!s->budget--) { s->failed_pc=0x0c0b63d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b640eu,2);
goto P_0c0b63d2;
P_0c0b63d2: /* original 901b, guest PC 0x0c0b63d2 */
if(!s->budget--) { s->failed_pc=0x0c0b63d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b640cu,2);
goto P_0c0b63d4;
P_0c0b63d4: /* original 4e0b, guest PC 0x0c0b63d4 */
if(!s->budget--) { s->failed_pc=0x0c0b63d4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b63d8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b63d8u) { target=s->pc; goto dispatch; }
goto P_0c0b63d8;
P_0c0b63d6: /* original 05de, guest PC 0x0c0b63d6 */
if(!s->budget--) { s->failed_pc=0x0c0b63d6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b63d8;
P_0c0b63d8: /* original 941b, guest PC 0x0c0b63d8 */
if(!s->budget--) { s->failed_pc=0x0c0b63d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6412u,2);
goto P_0c0b63da;
P_0c0b63da: /* original 9019, guest PC 0x0c0b63da */
if(!s->budget--) { s->failed_pc=0x0c0b63dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6410u,2);
goto P_0c0b63dc;
P_0c0b63dc: /* original 4e0b, guest PC 0x0c0b63dc */
if(!s->budget--) { s->failed_pc=0x0c0b63dcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b63e0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b63e0u) { target=s->pc; goto dispatch; }
goto P_0c0b63e0;
P_0c0b63de: /* original 05de, guest PC 0x0c0b63de */
if(!s->budget--) { s->failed_pc=0x0c0b63deu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b63e0;
P_0c0b63e0: /* original 7f08, guest PC 0x0c0b63e0 */
if(!s->budget--) { s->failed_pc=0x0c0b63e0u; return 0; }
r[15]+=0x00000008u;
goto P_0c0b63e2;
P_0c0b63e2: /* original 4f26, guest PC 0x0c0b63e2 */
if(!s->budget--) { s->failed_pc=0x0c0b63e2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b63e4;
P_0c0b63e4: /* original 69f6, guest PC 0x0c0b63e4 */
if(!s->budget--) { s->failed_pc=0x0c0b63e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b63e6;
P_0c0b63e6: /* original 6af6, guest PC 0x0c0b63e6 */
if(!s->budget--) { s->failed_pc=0x0c0b63e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b63e8;
P_0c0b63e8: /* original 6bf6, guest PC 0x0c0b63e8 */
if(!s->budget--) { s->failed_pc=0x0c0b63e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b63ea;
P_0c0b63ea: /* original 6cf6, guest PC 0x0c0b63ea */
if(!s->budget--) { s->failed_pc=0x0c0b63eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b63ec;
P_0c0b63ec: /* original 6df6, guest PC 0x0c0b63ec */
if(!s->budget--) { s->failed_pc=0x0c0b63ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b63ee;
P_0c0b63ee: /* original 000b, guest PC 0x0c0b63ee */
if(!s->budget--) { s->failed_pc=0x0c0b63eeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b63f0: /* original 6ef6, guest PC 0x0c0b63f0 */
if(!s->budget--) { s->failed_pc=0x0c0b63f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b63f2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b63f2u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
