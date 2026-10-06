/* Static C ABI adapters. Generated with tools/oracle/translate_adapters.py.
 * Matrix operations are hand-written in matrix_family.c; unknown code fails.
 * Executed opcodes are checked against the untouched identity image. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <math.h>
#include <string.h>
#define read vf3_matrix_read
#define write vf3_matrix_write
static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }
static uint32_t truncate_float(uint32_t u) { double d=as_float(u); if(isnan(d) || d< -2147483648.0) return 0x80000000u; if(d>=2147483648.0) return 0x7fffffffu; return (uint32_t)(int32_t)d; }
static void divide_step(vf3_matrix_state*s,unsigned n,unsigned m) { uint32_t *r=s->v; unsigned oldq=(r[17]>>8)&1u,sign=(r[17]>>9)&1u,q=r[n]>>31; uint32_t divisor=r[m],shifted=(r[n]<<1)|(r[17]&1u); r[n]=oldq==sign?shifted-divisor:shifted+divisor; unsigned carry=oldq==sign?r[n]>shifted:r[n]<shifted; q^=carry^sign; r[17]=(r[17]&~0x101u)|(q<<8)|(q==sign); }
int vf3_target_configuration_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c091afeu: goto P_0c091afe;
case 0x0c091b00u: goto P_0c091b00;
case 0x0c091b02u: goto P_0c091b02;
case 0x0c091b04u: goto P_0c091b04;
case 0x0c091b06u: goto P_0c091b06;
case 0x0c091b08u: goto P_0c091b08;
case 0x0c091b0au: goto P_0c091b0a;
case 0x0c091b0cu: goto P_0c091b0c;
case 0x0c091b0eu: goto P_0c091b0e;
case 0x0c091b10u: goto P_0c091b10;
case 0x0c091b12u: goto P_0c091b12;
case 0x0c091b14u: goto P_0c091b14;
case 0x0c091b16u: goto P_0c091b16;
case 0x0c091b18u: goto P_0c091b18;
case 0x0c091b1au: goto P_0c091b1a;
case 0x0c091b1cu: goto P_0c091b1c;
case 0x0c091b1eu: goto P_0c091b1e;
case 0x0c091b20u: goto P_0c091b20;
case 0x0c091b22u: goto P_0c091b22;
case 0x0c091b24u: goto P_0c091b24;
case 0x0c091b26u: goto P_0c091b26;
case 0x0c091b28u: goto P_0c091b28;
case 0x0c091b2au: goto P_0c091b2a;
case 0x0c091b2cu: goto P_0c091b2c;
case 0x0c091b2eu: goto P_0c091b2e;
case 0x0c091b30u: goto P_0c091b30;
case 0x0c091b32u: goto P_0c091b32;
case 0x0c091b34u: goto P_0c091b34;
case 0x0c091b36u: goto P_0c091b36;
case 0x0c091b38u: goto P_0c091b38;
case 0x0c091b3au: goto P_0c091b3a;
case 0x0c091b3cu: goto P_0c091b3c;
case 0x0c091b3eu: goto P_0c091b3e;
case 0x0c091b40u: goto P_0c091b40;
case 0x0c091b42u: goto P_0c091b42;
case 0x0c091b44u: goto P_0c091b44;
case 0x0c0a8582u: goto P_0c0a8582;
case 0x0c0a8584u: goto P_0c0a8584;
case 0x0c0a8586u: goto P_0c0a8586;
case 0x0c0a8588u: goto P_0c0a8588;
case 0x0c0a858au: goto P_0c0a858a;
case 0x0c0a858cu: goto P_0c0a858c;
case 0x0c0a858eu: goto P_0c0a858e;
case 0x0c0a8590u: goto P_0c0a8590;
case 0x0c0a8592u: goto P_0c0a8592;
case 0x0c0a8594u: goto P_0c0a8594;
case 0x0c0a8596u: goto P_0c0a8596;
case 0x0c0a8598u: goto P_0c0a8598;
case 0x0c0a859au: goto P_0c0a859a;
case 0x0c0a859cu: goto P_0c0a859c;
case 0x0c0a859eu: goto P_0c0a859e;
case 0x0c0a85a0u: goto P_0c0a85a0;
case 0x0c0a85a2u: goto P_0c0a85a2;
case 0x0c0a85a4u: goto P_0c0a85a4;
case 0x0c0a85a6u: goto P_0c0a85a6;
case 0x0c0a85a8u: goto P_0c0a85a8;
case 0x0c0a85aau: goto P_0c0a85aa;
case 0x0c0a85acu: goto P_0c0a85ac;
case 0x0c0a85aeu: goto P_0c0a85ae;
case 0x0c0a85b0u: goto P_0c0a85b0;
case 0x0c0a85b2u: goto P_0c0a85b2;
case 0x0c0a85b4u: goto P_0c0a85b4;
case 0x0c0a85b6u: goto P_0c0a85b6;
case 0x0c0a85b8u: goto P_0c0a85b8;
case 0x0c0a85bau: goto P_0c0a85ba;
case 0x0c0a85bcu: goto P_0c0a85bc;
case 0x0c0a85beu: goto P_0c0a85be;
case 0x0c0a85c0u: goto P_0c0a85c0;
case 0x0c0a85c2u: goto P_0c0a85c2;
case 0x0c0a85c4u: goto P_0c0a85c4;
case 0x0c0a85c6u: goto P_0c0a85c6;
case 0x0c0a85c8u: goto P_0c0a85c8;
case 0x0c0a85cau: goto P_0c0a85ca;
case 0x0c0a85ccu: goto P_0c0a85cc;
case 0x0c0a85ceu: goto P_0c0a85ce;
case 0x0c0a85d0u: goto P_0c0a85d0;
case 0x0c0a85d2u: goto P_0c0a85d2;
case 0x0c0a85d4u: goto P_0c0a85d4;
case 0x0c0a85d6u: goto P_0c0a85d6;
case 0x0c0a85d8u: goto P_0c0a85d8;
case 0x0c0a85dau: goto P_0c0a85da;
case 0x0c0a85dcu: goto P_0c0a85dc;
case 0x0c0a85deu: goto P_0c0a85de;
case 0x0c0a85e0u: goto P_0c0a85e0;
case 0x0c0a85e2u: goto P_0c0a85e2;
case 0x0c0a85e4u: goto P_0c0a85e4;
case 0x0c0a85e6u: goto P_0c0a85e6;
case 0x0c0a85e8u: goto P_0c0a85e8;
case 0x0c0a85eau: goto P_0c0a85ea;
case 0x0c0a85ecu: goto P_0c0a85ec;
case 0x0c0a85eeu: goto P_0c0a85ee;
case 0x0c0a85f0u: goto P_0c0a85f0;
case 0x0c0a85f2u: goto P_0c0a85f2;
case 0x0c0a85f4u: goto P_0c0a85f4;
case 0x0c0a85f6u: goto P_0c0a85f6;
case 0x0c0a85f8u: goto P_0c0a85f8;
case 0x0c0a85fau: goto P_0c0a85fa;
case 0x0c0a85fcu: goto P_0c0a85fc;
case 0x0c0a85feu: goto P_0c0a85fe;
case 0x0c0a8600u: goto P_0c0a8600;
case 0x0c0a8602u: goto P_0c0a8602;
case 0x0c0a8604u: goto P_0c0a8604;
case 0x0c0a8606u: goto P_0c0a8606;
case 0x0c0a8608u: goto P_0c0a8608;
case 0x0c0a860au: goto P_0c0a860a;
case 0x0c0a860cu: goto P_0c0a860c;
case 0x0c0a860eu: goto P_0c0a860e;
case 0x0c0a8610u: goto P_0c0a8610;
case 0x0c0a8612u: goto P_0c0a8612;
case 0x0c0a8614u: goto P_0c0a8614;
case 0x0c0a8616u: goto P_0c0a8616;
case 0x0c0a8618u: goto P_0c0a8618;
case 0x0c0a861au: goto P_0c0a861a;
case 0x0c0a861cu: goto P_0c0a861c;
case 0x0c0a861eu: goto P_0c0a861e;
case 0x0c0a8620u: goto P_0c0a8620;
case 0x0c0a8622u: goto P_0c0a8622;
case 0x0c0a8624u: goto P_0c0a8624;
case 0x0c0a8626u: goto P_0c0a8626;
case 0x0c0a8628u: goto P_0c0a8628;
case 0x0c0a862au: goto P_0c0a862a;
case 0x0c0a862cu: goto P_0c0a862c;
case 0x0c0a862eu: goto P_0c0a862e;
case 0x0c0a8630u: goto P_0c0a8630;
case 0x0c0a8632u: goto P_0c0a8632;
case 0x0c0a8634u: goto P_0c0a8634;
case 0x0c0a8636u: goto P_0c0a8636;
case 0x0c0a8638u: goto P_0c0a8638;
case 0x0c0a863au: goto P_0c0a863a;
case 0x0c0a863cu: goto P_0c0a863c;
case 0x0c0a863eu: goto P_0c0a863e;
case 0x0c0a8640u: goto P_0c0a8640;
case 0x0c0a8642u: goto P_0c0a8642;
case 0x0c0a8644u: goto P_0c0a8644;
case 0x0c0a8646u: goto P_0c0a8646;
case 0x0c0a8648u: goto P_0c0a8648;
case 0x0c0a864au: goto P_0c0a864a;
case 0x0c0a864cu: goto P_0c0a864c;
case 0x0c0a864eu: goto P_0c0a864e;
case 0x0c0a8650u: goto P_0c0a8650;
case 0x0c0a8652u: goto P_0c0a8652;
case 0x0c0a8654u: goto P_0c0a8654;
case 0x0c0a8656u: goto P_0c0a8656;
case 0x0c0a8658u: goto P_0c0a8658;
case 0x0c0a865au: goto P_0c0a865a;
case 0x0c0a865cu: goto P_0c0a865c;
case 0x0c0a865eu: goto P_0c0a865e;
case 0x0c0a8660u: goto P_0c0a8660;
case 0x0c0a8662u: goto P_0c0a8662;
case 0x0c0a8664u: goto P_0c0a8664;
case 0x0c0a8666u: goto P_0c0a8666;
case 0x0c0a8668u: goto P_0c0a8668;
case 0x0c0a866au: goto P_0c0a866a;
case 0x0c0a866cu: goto P_0c0a866c;
case 0x0c0a866eu: goto P_0c0a866e;
case 0x0c0a8670u: goto P_0c0a8670;
case 0x0c0a8672u: goto P_0c0a8672;
case 0x0c0a8674u: goto P_0c0a8674;
case 0x0c0a8676u: goto P_0c0a8676;
case 0x0c0a8678u: goto P_0c0a8678;
case 0x0c0a867au: goto P_0c0a867a;
case 0x0c0a867cu: goto P_0c0a867c;
case 0x0c0a867eu: goto P_0c0a867e;
case 0x0c0a86acu: goto P_0c0a86ac;
case 0x0c0a86aeu: goto P_0c0a86ae;
case 0x0c0a86b0u: goto P_0c0a86b0;
case 0x0c0a86b2u: goto P_0c0a86b2;
case 0x0c0a86b4u: goto P_0c0a86b4;
case 0x0c0a86b6u: goto P_0c0a86b6;
case 0x0c0a86b8u: goto P_0c0a86b8;
case 0x0c0a86bau: goto P_0c0a86ba;
case 0x0c0a86bcu: goto P_0c0a86bc;
case 0x0c0a86beu: goto P_0c0a86be;
case 0x0c0a86c0u: goto P_0c0a86c0;
case 0x0c0a86c2u: goto P_0c0a86c2;
case 0x0c0a86c4u: goto P_0c0a86c4;
case 0x0c0a86c6u: goto P_0c0a86c6;
case 0x0c0a86c8u: goto P_0c0a86c8;
case 0x0c0a86cau: goto P_0c0a86ca;
case 0x0c0a86ccu: goto P_0c0a86cc;
case 0x0c0a86ceu: goto P_0c0a86ce;
case 0x0c0a86d0u: goto P_0c0a86d0;
case 0x0c0a86d2u: goto P_0c0a86d2;
case 0x0c0a86d4u: goto P_0c0a86d4;
case 0x0c0a86d6u: goto P_0c0a86d6;
case 0x0c0a86d8u: goto P_0c0a86d8;
case 0x0c0a86dau: goto P_0c0a86da;
case 0x0c0a86dcu: goto P_0c0a86dc;
case 0x0c0a86deu: goto P_0c0a86de;
case 0x0c0a86e0u: goto P_0c0a86e0;
case 0x0c0a86e2u: goto P_0c0a86e2;
case 0x0c0a86e4u: goto P_0c0a86e4;
case 0x0c0a86e6u: goto P_0c0a86e6;
case 0x0c0a86e8u: goto P_0c0a86e8;
case 0x0c0a86eau: goto P_0c0a86ea;
case 0x0c0a86ecu: goto P_0c0a86ec;
case 0x0c0a86eeu: goto P_0c0a86ee;
case 0x0c0a86f0u: goto P_0c0a86f0;
case 0x0c0a86f2u: goto P_0c0a86f2;
case 0x0c0a86f4u: goto P_0c0a86f4;
case 0x0c0a86f6u: goto P_0c0a86f6;
case 0x0c0a86f8u: goto P_0c0a86f8;
case 0x0c0a86fau: goto P_0c0a86fa;
case 0x0c0a86fcu: goto P_0c0a86fc;
case 0x0c0a86feu: goto P_0c0a86fe;
case 0x0c0a8700u: goto P_0c0a8700;
case 0x0c0a8702u: goto P_0c0a8702;
case 0x0c0a8704u: goto P_0c0a8704;
case 0x0c0a8706u: goto P_0c0a8706;
case 0x0c0a8708u: goto P_0c0a8708;
case 0x0c0a870au: goto P_0c0a870a;
case 0x0c0a870cu: goto P_0c0a870c;
case 0x0c0a870eu: goto P_0c0a870e;
case 0x0c0a8710u: goto P_0c0a8710;
case 0x0c0a8712u: goto P_0c0a8712;
case 0x0c0a8714u: goto P_0c0a8714;
case 0x0c0a8716u: goto P_0c0a8716;
case 0x0c0a8718u: goto P_0c0a8718;
case 0x0c0a871au: goto P_0c0a871a;
case 0x0c0a871cu: goto P_0c0a871c;
case 0x0c0a871eu: goto P_0c0a871e;
case 0x0c0a8720u: goto P_0c0a8720;
case 0x0c0a8722u: goto P_0c0a8722;
case 0x0c0a8724u: goto P_0c0a8724;
case 0x0c0a8726u: goto P_0c0a8726;
case 0x0c0a8728u: goto P_0c0a8728;
case 0x0c0a872au: goto P_0c0a872a;
case 0x0c0a872cu: goto P_0c0a872c;
case 0x0c0a872eu: goto P_0c0a872e;
case 0x0c0a8730u: goto P_0c0a8730;
case 0x0c0a8732u: goto P_0c0a8732;
case 0x0c0a8734u: goto P_0c0a8734;
case 0x0c0a8736u: goto P_0c0a8736;
case 0x0c0a8738u: goto P_0c0a8738;
case 0x0c0a873au: goto P_0c0a873a;
case 0x0c0a873cu: goto P_0c0a873c;
case 0x0c0a873eu: goto P_0c0a873e;
case 0x0c0a8740u: goto P_0c0a8740;
case 0x0c0a8742u: goto P_0c0a8742;
case 0x0c0a8744u: goto P_0c0a8744;
case 0x0c0a8746u: goto P_0c0a8746;
case 0x0c0a8748u: goto P_0c0a8748;
case 0x0c0a874au: goto P_0c0a874a;
case 0x0c0a874cu: goto P_0c0a874c;
case 0x0c0a874eu: goto P_0c0a874e;
case 0x0c0a8750u: goto P_0c0a8750;
case 0x0c0a8752u: goto P_0c0a8752;
case 0x0c0a8754u: goto P_0c0a8754;
case 0x0c0a8756u: goto P_0c0a8756;
case 0x0c0a8758u: goto P_0c0a8758;
case 0x0c0a875au: goto P_0c0a875a;
case 0x0c0a875cu: goto P_0c0a875c;
case 0x0c0a875eu: goto P_0c0a875e;
case 0x0c0a8760u: goto P_0c0a8760;
case 0x0c0a8762u: goto P_0c0a8762;
case 0x0c0a8764u: goto P_0c0a8764;
case 0x0c0a8766u: goto P_0c0a8766;
case 0x0c0a8768u: goto P_0c0a8768;
case 0x0c0a876au: goto P_0c0a876a;
case 0x0c0a876cu: goto P_0c0a876c;
case 0x0c0a876eu: goto P_0c0a876e;
case 0x0c0a8770u: goto P_0c0a8770;
case 0x0c0a8772u: goto P_0c0a8772;
case 0x0c0a8774u: goto P_0c0a8774;
case 0x0c0a8776u: goto P_0c0a8776;
case 0x0c0a8778u: goto P_0c0a8778;
case 0x0c0a877au: goto P_0c0a877a;
case 0x0c0a877cu: goto P_0c0a877c;
case 0x0c0a877eu: goto P_0c0a877e;
case 0x0c0a8780u: goto P_0c0a8780;
case 0x0c0a8782u: goto P_0c0a8782;
case 0x0c0a8794u: goto P_0c0a8794;
case 0x0c0a8796u: goto P_0c0a8796;
case 0x0c0a8798u: goto P_0c0a8798;
case 0x0c0a879au: goto P_0c0a879a;
case 0x0c0a879cu: goto P_0c0a879c;
case 0x0c0a879eu: goto P_0c0a879e;
case 0x0c0a87a0u: goto P_0c0a87a0;
case 0x0c0a87a2u: goto P_0c0a87a2;
case 0x0c0a87a4u: goto P_0c0a87a4;
case 0x0c0a87a6u: goto P_0c0a87a6;
case 0x0c0a87a8u: goto P_0c0a87a8;
case 0x0c0a8f10u: goto P_0c0a8f10;
case 0x0c0a8f12u: goto P_0c0a8f12;
case 0x0c0a8f14u: goto P_0c0a8f14;
case 0x0c0a8f16u: goto P_0c0a8f16;
case 0x0c0a8f18u: goto P_0c0a8f18;
case 0x0c0a8f1au: goto P_0c0a8f1a;
case 0x0c0a8f1cu: goto P_0c0a8f1c;
case 0x0c0a8f1eu: goto P_0c0a8f1e;
case 0x0c0a8f20u: goto P_0c0a8f20;
case 0x0c0a8f22u: goto P_0c0a8f22;
case 0x0c0a8f24u: goto P_0c0a8f24;
case 0x0c0a8f26u: goto P_0c0a8f26;
case 0x0c0a8f28u: goto P_0c0a8f28;
case 0x0c0a8f2au: goto P_0c0a8f2a;
case 0x0c0a8f2cu: goto P_0c0a8f2c;
case 0x0c0a8f2eu: goto P_0c0a8f2e;
case 0x0c0a8f30u: goto P_0c0a8f30;
case 0x0c0a8f32u: goto P_0c0a8f32;
case 0x0c0a8f34u: goto P_0c0a8f34;
case 0x0c0a8f36u: goto P_0c0a8f36;
case 0x0c0a8f38u: goto P_0c0a8f38;
case 0x0c0a8f3au: goto P_0c0a8f3a;
case 0x0c0a8f3cu: goto P_0c0a8f3c;
case 0x0c0a8f3eu: goto P_0c0a8f3e;
case 0x0c0a8f40u: goto P_0c0a8f40;
case 0x0c0a8f42u: goto P_0c0a8f42;
case 0x0c0a8f44u: goto P_0c0a8f44;
case 0x0c0a8f46u: goto P_0c0a8f46;
case 0x0c0a8f48u: goto P_0c0a8f48;
case 0x0c0a8f4au: goto P_0c0a8f4a;
case 0x0c0a8f8cu: goto P_0c0a8f8c;
case 0x0c0a8f8eu: goto P_0c0a8f8e;
case 0x0c0a8f90u: goto P_0c0a8f90;
case 0x0c0a8f92u: goto P_0c0a8f92;
case 0x0c0a8f94u: goto P_0c0a8f94;
case 0x0c0a8f96u: goto P_0c0a8f96;
case 0x0c0a8f98u: goto P_0c0a8f98;
case 0x0c0a8f9au: goto P_0c0a8f9a;
case 0x0c0a8f9cu: goto P_0c0a8f9c;
case 0x0c0a8f9eu: goto P_0c0a8f9e;
case 0x0c0a8fa0u: goto P_0c0a8fa0;
case 0x0c0a8fa2u: goto P_0c0a8fa2;
case 0x0c0a8fa4u: goto P_0c0a8fa4;
case 0x0c0a8fa6u: goto P_0c0a8fa6;
case 0x0c0a8fa8u: goto P_0c0a8fa8;
case 0x0c0a8faau: goto P_0c0a8faa;
case 0x0c0a8facu: goto P_0c0a8fac;
case 0x0c0a8faeu: goto P_0c0a8fae;
case 0x0c0a8fb0u: goto P_0c0a8fb0;
case 0x0c0a8fb2u: goto P_0c0a8fb2;
case 0x0c0a8fb4u: goto P_0c0a8fb4;
case 0x0c0a8fb6u: goto P_0c0a8fb6;
case 0x0c0a8fb8u: goto P_0c0a8fb8;
case 0x0c0a8fbau: goto P_0c0a8fba;
case 0x0c0a8fbcu: goto P_0c0a8fbc;
case 0x0c0a8fbeu: goto P_0c0a8fbe;
case 0x0c0a8fc0u: goto P_0c0a8fc0;
case 0x0c0a8fc2u: goto P_0c0a8fc2;
case 0x0c0a8fc4u: goto P_0c0a8fc4;
case 0x0c0a8fc6u: goto P_0c0a8fc6;
case 0x0c0a8fc8u: goto P_0c0a8fc8;
case 0x0c0a8fcau: goto P_0c0a8fca;
case 0x0c0a8fccu: goto P_0c0a8fcc;
case 0x0c0a8fceu: goto P_0c0a8fce;
case 0x0c0a8fd0u: goto P_0c0a8fd0;
case 0x0c0a8fd2u: goto P_0c0a8fd2;
case 0x0c0a8fd4u: goto P_0c0a8fd4;
case 0x0c0a8fd6u: goto P_0c0a8fd6;
case 0x0c0a8fd8u: goto P_0c0a8fd8;
case 0x0c0a8fdau: goto P_0c0a8fda;
case 0x0c0a8fdcu: goto P_0c0a8fdc;
case 0x0c0a8fdeu: goto P_0c0a8fde;
case 0x0c0a8fe0u: goto P_0c0a8fe0;
case 0x0c0a8fe2u: goto P_0c0a8fe2;
case 0x0c0a8fe4u: goto P_0c0a8fe4;
case 0x0c0a8fe6u: goto P_0c0a8fe6;
case 0x0c0a8fe8u: goto P_0c0a8fe8;
case 0x0c0a8feau: goto P_0c0a8fea;
case 0x0c0a8fecu: goto P_0c0a8fec;
case 0x0c0a8feeu: goto P_0c0a8fee;
case 0x0c0a8ff0u: goto P_0c0a8ff0;
case 0x0c0a8ff2u: goto P_0c0a8ff2;
case 0x0c0a8ff4u: goto P_0c0a8ff4;
case 0x0c0a8ff6u: goto P_0c0a8ff6;
case 0x0c0a8ff8u: goto P_0c0a8ff8;
case 0x0c0a8ffau: goto P_0c0a8ffa;
case 0x0c0a8ffcu: goto P_0c0a8ffc;
case 0x0c0a8ffeu: goto P_0c0a8ffe;
case 0x0c0a9000u: goto P_0c0a9000;
case 0x0c0a9002u: goto P_0c0a9002;
case 0x0c0a9004u: goto P_0c0a9004;
case 0x0c0a9006u: goto P_0c0a9006;
case 0x0c0a9008u: goto P_0c0a9008;
case 0x0c0a900au: goto P_0c0a900a;
case 0x0c0a900cu: goto P_0c0a900c;
case 0x0c0a900eu: goto P_0c0a900e;
case 0x0c0a9010u: goto P_0c0a9010;
case 0x0c0a9012u: goto P_0c0a9012;
case 0x0c0a9014u: goto P_0c0a9014;
case 0x0c0a9016u: goto P_0c0a9016;
case 0x0c0a9018u: goto P_0c0a9018;
case 0x0c0a901au: goto P_0c0a901a;
case 0x0c0a901cu: goto P_0c0a901c;
case 0x0c0a901eu: goto P_0c0a901e;
case 0x0c0a9020u: goto P_0c0a9020;
case 0x0c0a9022u: goto P_0c0a9022;
case 0x0c0a9024u: goto P_0c0a9024;
case 0x0c0a9026u: goto P_0c0a9026;
case 0x0c0a9028u: goto P_0c0a9028;
case 0x0c0a902au: goto P_0c0a902a;
case 0x0c0a902cu: goto P_0c0a902c;
case 0x0c0a902eu: goto P_0c0a902e;
case 0x0c0a9030u: goto P_0c0a9030;
case 0x0c0a9032u: goto P_0c0a9032;
case 0x0c0a9034u: goto P_0c0a9034;
case 0x0c0a9036u: goto P_0c0a9036;
case 0x0c0a9038u: goto P_0c0a9038;
case 0x0c0a903au: goto P_0c0a903a;
case 0x0c0a903cu: goto P_0c0a903c;
case 0x0c0a903eu: goto P_0c0a903e;
case 0x0c0a9040u: goto P_0c0a9040;
case 0x0c0a9042u: goto P_0c0a9042;
case 0x0c0a9044u: goto P_0c0a9044;
case 0x0c0a9046u: goto P_0c0a9046;
case 0x0c0a9048u: goto P_0c0a9048;
case 0x0c0a904au: goto P_0c0a904a;
case 0x0c0a904cu: goto P_0c0a904c;
case 0x0c0a904eu: goto P_0c0a904e;
case 0x0c0a9050u: goto P_0c0a9050;
case 0x0c0a9052u: goto P_0c0a9052;
case 0x0c0a9054u: goto P_0c0a9054;
case 0x0c0a9056u: goto P_0c0a9056;
case 0x0c0a9058u: goto P_0c0a9058;
case 0x0c0a905au: goto P_0c0a905a;
case 0x0c0a905cu: goto P_0c0a905c;
case 0x0c0a905eu: goto P_0c0a905e;
case 0x0c0a9060u: goto P_0c0a9060;
case 0x0c0a9062u: goto P_0c0a9062;
case 0x0c0a9064u: goto P_0c0a9064;
case 0x0c0a9066u: goto P_0c0a9066;
case 0x0c0a9068u: goto P_0c0a9068;
case 0x0c0a906au: goto P_0c0a906a;
case 0x0c0a906cu: goto P_0c0a906c;
case 0x0c0a9088u: goto P_0c0a9088;
case 0x0c0a908au: goto P_0c0a908a;
case 0x0c0a908cu: goto P_0c0a908c;
case 0x0c0a908eu: goto P_0c0a908e;
case 0x0c0a9090u: goto P_0c0a9090;
case 0x0c0a9092u: goto P_0c0a9092;
case 0x0c0a9094u: goto P_0c0a9094;
case 0x0c0a9096u: goto P_0c0a9096;
case 0x0c0a9098u: goto P_0c0a9098;
case 0x0c0a909au: goto P_0c0a909a;
case 0x0c0a909cu: goto P_0c0a909c;
case 0x0c0a909eu: goto P_0c0a909e;
case 0x0c0a90a0u: goto P_0c0a90a0;
case 0x0c0a90a2u: goto P_0c0a90a2;
case 0x0c0a90a4u: goto P_0c0a90a4;
case 0x0c0a90a6u: goto P_0c0a90a6;
case 0x0c0a90a8u: goto P_0c0a90a8;
case 0x0c0a90aau: goto P_0c0a90aa;
case 0x0c0a90acu: goto P_0c0a90ac;
case 0x0c0a90aeu: goto P_0c0a90ae;
case 0x0c0a90b0u: goto P_0c0a90b0;
case 0x0c0a90b2u: goto P_0c0a90b2;
case 0x0c0a90b4u: goto P_0c0a90b4;
case 0x0c0a90b6u: goto P_0c0a90b6;
case 0x0c0a90b8u: goto P_0c0a90b8;
case 0x0c0a90bau: goto P_0c0a90ba;
case 0x0c0a90bcu: goto P_0c0a90bc;
case 0x0c0a90beu: goto P_0c0a90be;
case 0x0c0a90c0u: goto P_0c0a90c0;
case 0x0c0a90c2u: goto P_0c0a90c2;
case 0x0c0a90c4u: goto P_0c0a90c4;
case 0x0c0a90c6u: goto P_0c0a90c6;
case 0x0c0a90c8u: goto P_0c0a90c8;
case 0x0c0a90cau: goto P_0c0a90ca;
case 0x0c0a90ccu: goto P_0c0a90cc;
case 0x0c0a90ceu: goto P_0c0a90ce;
case 0x0c0a90d0u: goto P_0c0a90d0;
case 0x0c0a90d2u: goto P_0c0a90d2;
case 0x0c0a90d4u: goto P_0c0a90d4;
case 0x0c0a90d6u: goto P_0c0a90d6;
case 0x0c0a90d8u: goto P_0c0a90d8;
case 0x0c0a90dau: goto P_0c0a90da;
case 0x0c0a90dcu: goto P_0c0a90dc;
case 0x0c0a90deu: goto P_0c0a90de;
case 0x0c0a90e0u: goto P_0c0a90e0;
case 0x0c0a90e2u: goto P_0c0a90e2;
case 0x0c0a90e4u: goto P_0c0a90e4;
case 0x0c0a90e6u: goto P_0c0a90e6;
case 0x0c0a90e8u: goto P_0c0a90e8;
case 0x0c0a90eau: goto P_0c0a90ea;
case 0x0c0a90ecu: goto P_0c0a90ec;
case 0x0c0a90eeu: goto P_0c0a90ee;
case 0x0c0a90f0u: goto P_0c0a90f0;
case 0x0c0a90f2u: goto P_0c0a90f2;
case 0x0c0a90f4u: goto P_0c0a90f4;
case 0x0c0a90f6u: goto P_0c0a90f6;
case 0x0c0a90f8u: goto P_0c0a90f8;
case 0x0c0a90fau: goto P_0c0a90fa;
case 0x0c0a90fcu: goto P_0c0a90fc;
case 0x0c0a90feu: goto P_0c0a90fe;
case 0x0c0a9100u: goto P_0c0a9100;
case 0x0c0a9102u: goto P_0c0a9102;
case 0x0c0a9104u: goto P_0c0a9104;
case 0x0c0a9106u: goto P_0c0a9106;
case 0x0c0a9108u: goto P_0c0a9108;
case 0x0c0a910au: goto P_0c0a910a;
case 0x0c0a910cu: goto P_0c0a910c;
case 0x0c0a910eu: goto P_0c0a910e;
case 0x0c0a9110u: goto P_0c0a9110;
case 0x0c0a9112u: goto P_0c0a9112;
case 0x0c0a9114u: goto P_0c0a9114;
case 0x0c0a9116u: goto P_0c0a9116;
case 0x0c0a9118u: goto P_0c0a9118;
case 0x0c0a911au: goto P_0c0a911a;
case 0x0c0a911cu: goto P_0c0a911c;
case 0x0c0a911eu: goto P_0c0a911e;
case 0x0c0a9120u: goto P_0c0a9120;
case 0x0c0a9122u: goto P_0c0a9122;
case 0x0c0a9124u: goto P_0c0a9124;
case 0x0c0a9126u: goto P_0c0a9126;
case 0x0c0a9128u: goto P_0c0a9128;
case 0x0c0a912au: goto P_0c0a912a;
case 0x0c0a912cu: goto P_0c0a912c;
case 0x0c0a912eu: goto P_0c0a912e;
case 0x0c0a9130u: goto P_0c0a9130;
case 0x0c0a9132u: goto P_0c0a9132;
case 0x0c0a9134u: goto P_0c0a9134;
case 0x0c0a9136u: goto P_0c0a9136;
case 0x0c0a9138u: goto P_0c0a9138;
case 0x0c0a913au: goto P_0c0a913a;
case 0x0c0a913cu: goto P_0c0a913c;
case 0x0c0a913eu: goto P_0c0a913e;
case 0x0c0a9140u: goto P_0c0a9140;
case 0x0c0a9142u: goto P_0c0a9142;
case 0x0c0a9144u: goto P_0c0a9144;
case 0x0c0a9146u: goto P_0c0a9146;
case 0x0c0a9148u: goto P_0c0a9148;
case 0x0c0a914au: goto P_0c0a914a;
case 0x0c0a914cu: goto P_0c0a914c;
case 0x0c0a914eu: goto P_0c0a914e;
case 0x0c0a9150u: goto P_0c0a9150;
case 0x0c0a9152u: goto P_0c0a9152;
case 0x0c0a9154u: goto P_0c0a9154;
case 0x0c0a9156u: goto P_0c0a9156;
case 0x0c0a9158u: goto P_0c0a9158;
case 0x0c0a915au: goto P_0c0a915a;
case 0x0c0a915cu: goto P_0c0a915c;
case 0x0c0a915eu: goto P_0c0a915e;
case 0x0c0a9160u: goto P_0c0a9160;
case 0x0c0a9162u: goto P_0c0a9162;
case 0x0c0a9164u: goto P_0c0a9164;
case 0x0c0a9166u: goto P_0c0a9166;
case 0x0c0a9168u: goto P_0c0a9168;
case 0x0c0a916au: goto P_0c0a916a;
case 0x0c0a916cu: goto P_0c0a916c;
case 0x0c0a916eu: goto P_0c0a916e;
case 0x0c0a9170u: goto P_0c0a9170;
case 0x0c0a9172u: goto P_0c0a9172;
case 0x0c0a9174u: goto P_0c0a9174;
case 0x0c0a9176u: goto P_0c0a9176;
case 0x0c0a9178u: goto P_0c0a9178;
case 0x0c0a917au: goto P_0c0a917a;
case 0x0c0a917cu: goto P_0c0a917c;
case 0x0c0a917eu: goto P_0c0a917e;
case 0x0c0a9180u: goto P_0c0a9180;
case 0x0c0a9182u: goto P_0c0a9182;
case 0x0c0a9184u: goto P_0c0a9184;
case 0x0c0a9186u: goto P_0c0a9186;
case 0x0c0a9188u: goto P_0c0a9188;
case 0x0c0a918au: goto P_0c0a918a;
case 0x0c0a918cu: goto P_0c0a918c;
case 0x0c0a918eu: goto P_0c0a918e;
case 0x0c0a9190u: goto P_0c0a9190;
case 0x0c0a9192u: goto P_0c0a9192;
case 0x0c0a9194u: goto P_0c0a9194;
case 0x0c0a9196u: goto P_0c0a9196;
case 0x0c0a9198u: goto P_0c0a9198;
case 0x0c0a919au: goto P_0c0a919a;
case 0x0c0a91c0u: goto P_0c0a91c0;
case 0x0c0a91c2u: goto P_0c0a91c2;
case 0x0c0a91c4u: goto P_0c0a91c4;
case 0x0c0a91c6u: goto P_0c0a91c6;
case 0x0c0a91c8u: goto P_0c0a91c8;
case 0x0c0a91cau: goto P_0c0a91ca;
case 0x0c0a91ccu: goto P_0c0a91cc;
case 0x0c0a91ceu: goto P_0c0a91ce;
case 0x0c0a91d0u: goto P_0c0a91d0;
case 0x0c0a91d2u: goto P_0c0a91d2;
case 0x0c0a91d4u: goto P_0c0a91d4;
case 0x0c0a91d6u: goto P_0c0a91d6;
case 0x0c0a91d8u: goto P_0c0a91d8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c091afe: /* original d313, guest PC 0x0c091afe */
if(!s->budget--) { s->failed_pc=0x0c091afeu; return 0; }
r[3]=read(ram,0x0c091b4cu,4);
goto P_0c091b00;
P_0c091b00: /* original 7ff4, guest PC 0x0c091b00 */
if(!s->budget--) { s->failed_pc=0x0c091b00u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c091b02;
P_0c091b02: /* original d513, guest PC 0x0c091b02 */
if(!s->budget--) { s->failed_pc=0x0c091b02u; return 0; }
r[5]=read(ram,0x0c091b50u,4);
goto P_0c091b04;
P_0c091b04: /* original e201, guest PC 0x0c091b04 */
if(!s->budget--) { s->failed_pc=0x0c091b04u; return 0; }
r[2]=0x00000001u;
goto P_0c091b06;
P_0c091b06: /* original 6632, guest PC 0x0c091b06 */
if(!s->budget--) { s->failed_pc=0x0c091b06u; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c091b08;
P_0c091b08: /* original 1f21, guest PC 0x0c091b08 */
if(!s->budget--) { s->failed_pc=0x0c091b08u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c091b0a;
P_0c091b0a: /* original 7614, guest PC 0x0c091b0a */
if(!s->budget--) { s->failed_pc=0x0c091b0au; return 0; }
r[6]+=0x00000014u;
goto P_0c091b0c;
P_0c091b0c: /* original 6152, guest PC 0x0c091b0c */
if(!s->budget--) { s->failed_pc=0x0c091b0cu; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c091b0e;
P_0c091b0e: /* original 1f12, guest PC 0x0c091b0e */
if(!s->budget--) { s->failed_pc=0x0c091b0eu; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c091b10;
P_0c091b10: /* original 6462, guest PC 0x0c091b10 */
if(!s->budget--) { s->failed_pc=0x0c091b10u; return 0; }
tmp=read(ram,r[6],4);
r[4]=tmp;
goto P_0c091b12;
P_0c091b12: /* original 2448, guest PC 0x0c091b12 */
if(!s->budget--) { s->failed_pc=0x0c091b12u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c091b14;
P_0c091b14: /* original 8d15, guest PC 0x0c091b14 */
if(!s->budget--) { s->failed_pc=0x0c091b14u; return 0; }
cond=r[17]&1u;
r[7]=0x00000000u;
if(cond) { goto P_0c091b42; }
goto P_0c091b18;
P_0c091b16: /* original e700, guest PC 0x0c091b16 */
if(!s->budget--) { s->failed_pc=0x0c091b16u; return 0; }
r[7]=0x00000000u;
goto P_0c091b18;
P_0c091b18: /* original 6543, guest PC 0x0c091b18 */
if(!s->budget--) { s->failed_pc=0x0c091b18u; return 0; }
r[5]=r[4];
goto P_0c091b1a;
P_0c091b1a: /* original 6363, guest PC 0x0c091b1a */
if(!s->budget--) { s->failed_pc=0x0c091b1au; return 0; }
r[3]=r[6];
goto P_0c091b1c;
P_0c091b1c: /* original 6473, guest PC 0x0c091b1c */
if(!s->budget--) { s->failed_pc=0x0c091b1cu; return 0; }
r[4]=r[7];
goto P_0c091b1e;
P_0c091b1e: /* original 7304, guest PC 0x0c091b1e */
if(!s->budget--) { s->failed_pc=0x0c091b1eu; return 0; }
r[3]+=0x00000004u;
goto P_0c091b20;
P_0c091b20: /* original 4408, guest PC 0x0c091b20 */
if(!s->budget--) { s->failed_pc=0x0c091b20u; return 0; }
r[4]<<=2;
goto P_0c091b22;
P_0c091b22: /* original 343c, guest PC 0x0c091b22 */
if(!s->budget--) { s->failed_pc=0x0c091b22u; return 0; }
r[4]+=r[3];
goto P_0c091b24;
P_0c091b24: /* original 6442, guest PC 0x0c091b24 */
if(!s->budget--) { s->failed_pc=0x0c091b24u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c091b26;
P_0c091b26: /* original 5248, guest PC 0x0c091b26 */
if(!s->budget--) { s->failed_pc=0x0c091b26u; return 0; }
r[2]=read(ram,r[4]+32,4);
goto P_0c091b28;
P_0c091b28: /* original 6323, guest PC 0x0c091b28 */
if(!s->budget--) { s->failed_pc=0x0c091b28u; return 0; }
r[3]=r[2];
goto P_0c091b2a;
P_0c091b2a: /* original 2f22, guest PC 0x0c091b2a */
if(!s->budget--) { s->failed_pc=0x0c091b2au; return 0; }
write(ram,r[15],r[2],4);
goto P_0c091b2c;
P_0c091b2c: /* original 51f2, guest PC 0x0c091b2c */
if(!s->budget--) { s->failed_pc=0x0c091b2cu; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c091b2e;
P_0c091b2e: /* original 3138, guest PC 0x0c091b2e */
if(!s->budget--) { s->failed_pc=0x0c091b2eu; return 0; }
r[1]-=r[3];
goto P_0c091b30;
P_0c091b30: /* original 2f12, guest PC 0x0c091b30 */
if(!s->budget--) { s->failed_pc=0x0c091b30u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c091b32;
P_0c091b32: /* original 9208, guest PC 0x0c091b32 */
if(!s->budget--) { s->failed_pc=0x0c091b32u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091b46u,2);
goto P_0c091b34;
P_0c091b34: /* original 3126, guest PC 0x0c091b34 */
if(!s->budget--) { s->failed_pc=0x0c091b34u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[2])!=0);
goto P_0c091b36;
P_0c091b36: /* original 8d02, guest PC 0x0c091b36 */
if(!s->budget--) { s->failed_pc=0x0c091b36u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(cond) { goto P_0c091b3e; }
goto P_0c091b3a;
P_0c091b38: /* original 7701, guest PC 0x0c091b38 */
if(!s->budget--) { s->failed_pc=0x0c091b38u; return 0; }
r[7]+=0x00000001u;
goto P_0c091b3a;
P_0c091b3a: /* original 53f1, guest PC 0x0c091b3a */
if(!s->budget--) { s->failed_pc=0x0c091b3au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c091b3c;
P_0c091b3c: /* original 2432, guest PC 0x0c091b3c */
if(!s->budget--) { s->failed_pc=0x0c091b3cu; return 0; }
write(ram,r[4],r[3],4);
goto P_0c091b3e;
P_0c091b3e: /* original 4510, guest PC 0x0c091b3e */
if(!s->budget--) { s->failed_pc=0x0c091b3eu; return 0; }
--r[5];
r[17]=(r[17]&~1u)|((r[5]==0)!=0);
goto P_0c091b40;
P_0c091b40: /* original 8beb, guest PC 0x0c091b40 */
if(!s->budget--) { s->failed_pc=0x0c091b40u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091b1a; }
goto P_0c091b42;
P_0c091b42: /* original 000b, guest PC 0x0c091b42 */
if(!s->budget--) { s->failed_pc=0x0c091b42u; return 0; }
target=r[16];
r[15]+=0x0000000cu;
s->pc=target; return ram->oob==0;
P_0c091b44: /* original 7f0c, guest PC 0x0c091b44 */
if(!s->budget--) { s->failed_pc=0x0c091b44u; return 0; }
r[15]+=0x0000000cu;
return vf3_matrix_family(0x0c091b46u,s,ram);
P_0c0a8582: /* original 4f22, guest PC 0x0c0a8582 */
if(!s->budget--) { s->failed_pc=0x0c0a8582u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a8584;
P_0c0a8584: /* original 7ff4, guest PC 0x0c0a8584 */
if(!s->budget--) { s->failed_pc=0x0c0a8584u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a8586;
P_0c0a8586: /* original 2f42, guest PC 0x0c0a8586 */
if(!s->budget--) { s->failed_pc=0x0c0a8586u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a8588;
P_0c0a8588: /* original d340, guest PC 0x0c0a8588 */
if(!s->budget--) { s->failed_pc=0x0c0a8588u; return 0; }
r[3]=read(ram,0x0c0a868cu,4);
goto P_0c0a858a;
P_0c0a858a: /* original d241, guest PC 0x0c0a858a */
if(!s->budget--) { s->failed_pc=0x0c0a858au; return 0; }
r[2]=read(ram,0x0c0a8690u,4);
goto P_0c0a858c;
P_0c0a858c: /* original 420b, guest PC 0x0c0a858c */
if(!s->budget--) { s->failed_pc=0x0c0a858cu; return 0; }
target=r[2];
r[16]=0x0c0a8590u;
write(ram,r[15]+8,r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8590u) { target=s->pc; goto dispatch; }
goto P_0c0a8590;
P_0c0a858e: /* original 1f32, guest PC 0x0c0a858e */
if(!s->budget--) { s->failed_pc=0x0c0a858eu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0a8590;
P_0c0a8590: /* original 2008, guest PC 0x0c0a8590 */
if(!s->budget--) { s->failed_pc=0x0c0a8590u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a8592;
P_0c0a8592: /* original 896b, guest PC 0x0c0a8592 */
if(!s->budget--) { s->failed_pc=0x0c0a8592u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a866c; }
goto P_0c0a8594;
P_0c0a8594: /* original dc3f, guest PC 0x0c0a8594 */
if(!s->budget--) { s->failed_pc=0x0c0a8594u; return 0; }
r[12]=read(ram,0x0c0a8694u,4);
goto P_0c0a8596;
P_0c0a8596: /* original eb01, guest PC 0x0c0a8596 */
if(!s->budget--) { s->failed_pc=0x0c0a8596u; return 0; }
r[11]=0x00000001u;
goto P_0c0a8598;
P_0c0a8598: /* original 9072, guest PC 0x0c0a8598 */
if(!s->budget--) { s->failed_pc=0x0c0a8598u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8680u,2);
goto P_0c0a859a;
P_0c0a859a: /* original 6df2, guest PC 0x0c0a859a */
if(!s->budget--) { s->failed_pc=0x0c0a859au; return 0; }
tmp=read(ram,r[15],4);
r[13]=tmp;
goto P_0c0a859c;
P_0c0a859c: /* original 0cb4, guest PC 0x0c0a859c */
if(!s->budget--) { s->failed_pc=0x0c0a859cu; return 0; }
write(ram,r[12]+r[0],r[11],1);
goto P_0c0a859e;
P_0c0a859e: /* original e029, guest PC 0x0c0a859e */
if(!s->budget--) { s->failed_pc=0x0c0a859eu; return 0; }
r[0]=0x00000029u;
goto P_0c0a85a0;
P_0c0a85a0: /* original 00cc, guest PC 0x0c0a85a0 */
if(!s->budget--) { s->failed_pc=0x0c0a85a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0a85a2;
P_0c0a85a2: /* original 80f4, guest PC 0x0c0a85a2 */
if(!s->budget--) { s->failed_pc=0x0c0a85a2u; return 0; }
write(ram,r[15]+4,r[0],1);
goto P_0c0a85a4;
P_0c0a85a4: /* original 53c2, guest PC 0x0c0a85a4 */
if(!s->budget--) { s->failed_pc=0x0c0a85a4u; return 0; }
r[3]=read(ram,r[12]+8,4);
goto P_0c0a85a6;
P_0c0a85a6: /* original 2f32, guest PC 0x0c0a85a6 */
if(!s->budget--) { s->failed_pc=0x0c0a85a6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a85a8;
P_0c0a85a8: /* original 54f2, guest PC 0x0c0a85a8 */
if(!s->budget--) { s->failed_pc=0x0c0a85a8u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0a85aa;
P_0c0a85aa: /* original d33b, guest PC 0x0c0a85aa */
if(!s->budget--) { s->failed_pc=0x0c0a85aau; return 0; }
r[3]=read(ram,0x0c0a8698u,4);
goto P_0c0a85ac;
P_0c0a85ac: /* original 430b, guest PC 0x0c0a85ac */
if(!s->budget--) { s->failed_pc=0x0c0a85acu; return 0; }
target=r[3];
r[16]=0x0c0a85b0u;
r[4]+=0x00000013u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a85b0u) { target=s->pc; goto dispatch; }
goto P_0c0a85b0;
P_0c0a85ae: /* original 7413, guest PC 0x0c0a85ae */
if(!s->budget--) { s->failed_pc=0x0c0a85aeu; return 0; }
r[4]+=0x00000013u;
goto P_0c0a85b0;
P_0c0a85b0: /* original 6e0c, guest PC 0x0c0a85b0 */
if(!s->budget--) { s->failed_pc=0x0c0a85b0u; return 0; }
r[14]=r[0]&255u;
goto P_0c0a85b2;
P_0c0a85b2: /* original 84f4, guest PC 0x0c0a85b2 */
if(!s->budget--) { s->failed_pc=0x0c0a85b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c0a85b4;
P_0c0a85b4: /* original 8803, guest PC 0x0c0a85b4 */
if(!s->budget--) { s->failed_pc=0x0c0a85b4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0a85b6;
P_0c0a85b6: /* original 8b09, guest PC 0x0c0a85b6 */
if(!s->budget--) { s->failed_pc=0x0c0a85b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a85cc; }
goto P_0c0a85b8;
P_0c0a85b8: /* original 2ee8, guest PC 0x0c0a85b8 */
if(!s->budget--) { s->failed_pc=0x0c0a85b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a85ba;
P_0c0a85ba: /* original 8907, guest PC 0x0c0a85ba */
if(!s->budget--) { s->failed_pc=0x0c0a85bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a85cc; }
goto P_0c0a85bc;
P_0c0a85bc: /* original 64f2, guest PC 0x0c0a85bc */
if(!s->budget--) { s->failed_pc=0x0c0a85bcu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a85be;
P_0c0a85be: /* original 644c, guest PC 0x0c0a85be */
if(!s->budget--) { s->failed_pc=0x0c0a85beu; return 0; }
r[4]=r[4]&255u;
goto P_0c0a85c0;
P_0c0a85c0: /* original 6043, guest PC 0x0c0a85c0 */
if(!s->budget--) { s->failed_pc=0x0c0a85c0u; return 0; }
r[0]=r[4];
goto P_0c0a85c2;
P_0c0a85c2: /* original 8801, guest PC 0x0c0a85c2 */
if(!s->budget--) { s->failed_pc=0x0c0a85c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a85c4;
P_0c0a85c4: /* original 8b02, guest PC 0x0c0a85c4 */
if(!s->budget--) { s->failed_pc=0x0c0a85c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a85cc; }
goto P_0c0a85c6;
P_0c0a85c6: /* original 6043, guest PC 0x0c0a85c6 */
if(!s->budget--) { s->failed_pc=0x0c0a85c6u; return 0; }
r[0]=r[4];
goto P_0c0a85c8;
P_0c0a85c8: /* original 881d, guest PC 0x0c0a85c8 */
if(!s->budget--) { s->failed_pc=0x0c0a85c8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001du)!=0);
goto P_0c0a85ca;
P_0c0a85ca: /* original 8904, guest PC 0x0c0a85ca */
if(!s->budget--) { s->failed_pc=0x0c0a85cau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a85d6; }
goto P_0c0a85cc;
P_0c0a85cc: /* original e019, guest PC 0x0c0a85cc */
if(!s->budget--) { s->failed_pc=0x0c0a85ccu; return 0; }
r[0]=0x00000019u;
goto P_0c0a85ce;
P_0c0a85ce: /* original 04cc, guest PC 0x0c0a85ce */
if(!s->budget--) { s->failed_pc=0x0c0a85ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0a85d0;
P_0c0a85d0: /* original 604e, guest PC 0x0c0a85d0 */
if(!s->budget--) { s->failed_pc=0x0c0a85d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0a85d2;
P_0c0a85d2: /* original 8802, guest PC 0x0c0a85d2 */
if(!s->budget--) { s->failed_pc=0x0c0a85d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a85d4;
P_0c0a85d4: /* original 894a, guest PC 0x0c0a85d4 */
if(!s->budget--) { s->failed_pc=0x0c0a85d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a866c; }
goto P_0c0a85d6;
P_0c0a85d6: /* original d231, guest PC 0x0c0a85d6 */
if(!s->budget--) { s->failed_pc=0x0c0a85d6u; return 0; }
r[2]=read(ram,0x0c0a869cu,4);
goto P_0c0a85d8;
P_0c0a85d8: /* original 420b, guest PC 0x0c0a85d8 */
if(!s->budget--) { s->failed_pc=0x0c0a85d8u; return 0; }
target=r[2];
r[16]=0x0c0a85dcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a85dcu) { target=s->pc; goto dispatch; }
goto P_0c0a85dc;
P_0c0a85da: /* original 0009, guest PC 0x0c0a85da */
if(!s->budget--) { s->failed_pc=0x0c0a85dau; return 0; }
goto P_0c0a85dc;
P_0c0a85dc: /* original d430, guest PC 0x0c0a85dc */
if(!s->budget--) { s->failed_pc=0x0c0a85dcu; return 0; }
r[4]=read(ram,0x0c0a86a0u,4);
goto P_0c0a85de;
P_0c0a85de: /* original 9050, guest PC 0x0c0a85de */
if(!s->budget--) { s->failed_pc=0x0c0a85deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8682u,2);
goto P_0c0a85e0;
P_0c0a85e0: /* original 5a45, guest PC 0x0c0a85e0 */
if(!s->budget--) { s->failed_pc=0x0c0a85e0u; return 0; }
r[10]=read(ram,r[4]+20,4);
goto P_0c0a85e2;
P_0c0a85e2: /* original 5944, guest PC 0x0c0a85e2 */
if(!s->budget--) { s->failed_pc=0x0c0a85e2u; return 0; }
r[9]=read(ram,r[4]+16,4);
goto P_0c0a85e4;
P_0c0a85e4: /* original 09b4, guest PC 0x0c0a85e4 */
if(!s->budget--) { s->failed_pc=0x0c0a85e4u; return 0; }
write(ram,r[9]+r[0],r[11],1);
goto P_0c0a85e6;
P_0c0a85e6: /* original 0ae4, guest PC 0x0c0a85e6 */
if(!s->budget--) { s->failed_pc=0x0c0a85e6u; return 0; }
write(ram,r[10]+r[0],r[14],1);
goto P_0c0a85e8;
P_0c0a85e8: /* original e050, guest PC 0x0c0a85e8 */
if(!s->budget--) { s->failed_pc=0x0c0a85e8u; return 0; }
r[0]=0x00000050u;
goto P_0c0a85ea;
P_0c0a85ea: /* original 054e, guest PC 0x0c0a85ea */
if(!s->budget--) { s->failed_pc=0x0c0a85eau; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0a85ec;
P_0c0a85ec: /* original 5e54, guest PC 0x0c0a85ec */
if(!s->budget--) { s->failed_pc=0x0c0a85ecu; return 0; }
r[14]=read(ram,r[5]+16,4);
goto P_0c0a85ee;
P_0c0a85ee: /* original 1de4, guest PC 0x0c0a85ee */
if(!s->budget--) { s->failed_pc=0x0c0a85eeu; return 0; }
write(ram,r[13]+16,r[14],4);
goto P_0c0a85f0;
P_0c0a85f0: /* original 7eff, guest PC 0x0c0a85f0 */
if(!s->budget--) { s->failed_pc=0x0c0a85f0u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0a85f2;
P_0c0a85f2: /* original 9847, guest PC 0x0c0a85f2 */
if(!s->budget--) { s->failed_pc=0x0c0a85f2u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8684u,2);
goto P_0c0a85f4;
P_0c0a85f4: /* original 4e11, guest PC 0x0c0a85f4 */
if(!s->budget--) { s->failed_pc=0x0c0a85f4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0a85f6;
P_0c0a85f6: /* original 8900, guest PC 0x0c0a85f6 */
if(!s->budget--) { s->failed_pc=0x0c0a85f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a85fa; }
goto P_0c0a85f8;
P_0c0a85f8: /* original 6e83, guest PC 0x0c0a85f8 */
if(!s->budget--) { s->failed_pc=0x0c0a85f8u; return 0; }
r[14]=r[8];
goto P_0c0a85fa;
P_0c0a85fa: /* original 1de5, guest PC 0x0c0a85fa */
if(!s->budget--) { s->failed_pc=0x0c0a85fau; return 0; }
write(ram,r[13]+20,r[14],4);
goto P_0c0a85fc;
P_0c0a85fc: /* original 9043, guest PC 0x0c0a85fc */
if(!s->budget--) { s->failed_pc=0x0c0a85fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8686u,2);
goto P_0c0a85fe;
P_0c0a85fe: /* original 5444, guest PC 0x0c0a85fe */
if(!s->budget--) { s->failed_pc=0x0c0a85feu; return 0; }
r[4]=read(ram,r[4]+16,4);
goto P_0c0a8600;
P_0c0a8600: /* original 05ce, guest PC 0x0c0a8600 */
if(!s->budget--) { s->failed_pc=0x0c0a8600u; return 0; }
r[5]=read(ram,r[12]+r[0],4);
goto P_0c0a8602;
P_0c0a8602: /* original ec00, guest PC 0x0c0a8602 */
if(!s->budget--) { s->failed_pc=0x0c0a8602u; return 0; }
r[12]=0x00000000u;
goto P_0c0a8604;
P_0c0a8604: /* original 3540, guest PC 0x0c0a8604 */
if(!s->budget--) { s->failed_pc=0x0c0a8604u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[4])!=0);
goto P_0c0a8606;
P_0c0a8606: /* original 8d01, guest PC 0x0c0a8606 */
if(!s->budget--) { s->failed_pc=0x0c0a8606u; return 0; }
cond=r[17]&1u;
r[6]=r[12];
if(cond) { goto P_0c0a860c; }
goto P_0c0a860a;
P_0c0a8608: /* original 66c3, guest PC 0x0c0a8608 */
if(!s->budget--) { s->failed_pc=0x0c0a8608u; return 0; }
r[6]=r[12];
goto P_0c0a860a;
P_0c0a860a: /* original 66b3, guest PC 0x0c0a860a */
if(!s->budget--) { s->failed_pc=0x0c0a860au; return 0; }
r[6]=r[11];
goto P_0c0a860c;
P_0c0a860c: /* original e700, guest PC 0x0c0a860c */
if(!s->budget--) { s->failed_pc=0x0c0a860cu; return 0; }
r[7]=0x00000000u;
goto P_0c0a860e;
P_0c0a860e: /* original 65e3, guest PC 0x0c0a860e */
if(!s->budget--) { s->failed_pc=0x0c0a860eu; return 0; }
r[5]=r[14];
goto P_0c0a8610;
P_0c0a8610: /* original b04c, guest PC 0x0c0a8610 */
if(!s->budget--) { s->failed_pc=0x0c0a8610u; return 0; }
target=0x0c0a86acu; r[16]=0x0c0a8614u;
r[4]=r[7];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8614u) { target=s->pc; goto dispatch; }
goto P_0c0a8614;
P_0c0a8612: /* original 6473, guest PC 0x0c0a8612 */
if(!s->budget--) { s->failed_pc=0x0c0a8612u; return 0; }
r[4]=r[7];
goto P_0c0a8614;
P_0c0a8614: /* original 6403, guest PC 0x0c0a8614 */
if(!s->budget--) { s->failed_pc=0x0c0a8614u; return 0; }
r[4]=r[0];
goto P_0c0a8616;
P_0c0a8616: /* original 7eff, guest PC 0x0c0a8616 */
if(!s->budget--) { s->failed_pc=0x0c0a8616u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0a8618;
P_0c0a8618: /* original 4e11, guest PC 0x0c0a8618 */
if(!s->budget--) { s->failed_pc=0x0c0a8618u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0a861a;
P_0c0a861a: /* original 8900, guest PC 0x0c0a861a */
if(!s->budget--) { s->failed_pc=0x0c0a861au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a861e; }
goto P_0c0a861c;
P_0c0a861c: /* original 6e83, guest PC 0x0c0a861c */
if(!s->budget--) { s->failed_pc=0x0c0a861cu; return 0; }
r[14]=r[8];
goto P_0c0a861e;
P_0c0a861e: /* original 4410, guest PC 0x0c0a861e */
if(!s->budget--) { s->failed_pc=0x0c0a861eu; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c0a8620;
P_0c0a8620: /* original 8bf9, guest PC 0x0c0a8620 */
if(!s->budget--) { s->failed_pc=0x0c0a8620u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8616; }
goto P_0c0a8622;
P_0c0a8622: /* original 64e3, guest PC 0x0c0a8622 */
if(!s->budget--) { s->failed_pc=0x0c0a8622u; return 0; }
r[4]=r[14];
goto P_0c0a8624;
P_0c0a8624: /* original 7401, guest PC 0x0c0a8624 */
if(!s->budget--) { s->failed_pc=0x0c0a8624u; return 0; }
r[4]+=0x00000001u;
goto P_0c0a8626;
P_0c0a8626: /* original 3486, guest PC 0x0c0a8626 */
if(!s->budget--) { s->failed_pc=0x0c0a8626u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[8])!=0);
goto P_0c0a8628;
P_0c0a8628: /* original 8f01, guest PC 0x0c0a8628 */
if(!s->budget--) { s->failed_pc=0x0c0a8628u; return 0; }
cond=r[17]&1u;
write(ram,r[13]+24,r[14],4);
if(!cond) { goto P_0c0a862e; }
goto P_0c0a862c;
P_0c0a862a: /* original 1de6, guest PC 0x0c0a862a */
if(!s->budget--) { s->failed_pc=0x0c0a862au; return 0; }
write(ram,r[13]+24,r[14],4);
goto P_0c0a862c;
P_0c0a862c: /* original 64c3, guest PC 0x0c0a862c */
if(!s->budget--) { s->failed_pc=0x0c0a862cu; return 0; }
r[4]=r[12];
goto P_0c0a862e;
P_0c0a862e: /* original 6543, guest PC 0x0c0a862e */
if(!s->budget--) { s->failed_pc=0x0c0a862eu; return 0; }
r[5]=r[4];
goto P_0c0a8630;
P_0c0a8630: /* original 7501, guest PC 0x0c0a8630 */
if(!s->budget--) { s->failed_pc=0x0c0a8630u; return 0; }
r[5]+=0x00000001u;
goto P_0c0a8632;
P_0c0a8632: /* original 3586, guest PC 0x0c0a8632 */
if(!s->budget--) { s->failed_pc=0x0c0a8632u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[8])!=0);
goto P_0c0a8634;
P_0c0a8634: /* original 8b00, guest PC 0x0c0a8634 */
if(!s->budget--) { s->failed_pc=0x0c0a8634u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8638; }
goto P_0c0a8636;
P_0c0a8636: /* original 65c3, guest PC 0x0c0a8636 */
if(!s->budget--) { s->failed_pc=0x0c0a8636u; return 0; }
r[5]=r[12];
goto P_0c0a8638;
P_0c0a8638: /* original 4408, guest PC 0x0c0a8638 */
if(!s->budget--) { s->failed_pc=0x0c0a8638u; return 0; }
r[4]<<=2;
goto P_0c0a863a;
P_0c0a863a: /* original 1d54, guest PC 0x0c0a863a */
if(!s->budget--) { s->failed_pc=0x0c0a863au; return 0; }
write(ram,r[13]+16,r[5],4);
goto P_0c0a863c;
P_0c0a863c: /* original 4408, guest PC 0x0c0a863c */
if(!s->budget--) { s->failed_pc=0x0c0a863cu; return 0; }
r[4]<<=2;
goto P_0c0a863e;
P_0c0a863e: /* original de19, guest PC 0x0c0a863e */
if(!s->budget--) { s->failed_pc=0x0c0a863eu; return 0; }
r[14]=read(ram,0x0c0a86a4u,4);
goto P_0c0a8640;
P_0c0a8640: /* original 4408, guest PC 0x0c0a8640 */
if(!s->budget--) { s->failed_pc=0x0c0a8640u; return 0; }
r[4]<<=2;
goto P_0c0a8642;
P_0c0a8642: /* original 9221, guest PC 0x0c0a8642 */
if(!s->budget--) { s->failed_pc=0x0c0a8642u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8688u,2);
goto P_0c0a8644;
P_0c0a8644: /* original 4400, guest PC 0x0c0a8644 */
if(!s->budget--) { s->failed_pc=0x0c0a8644u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a8646;
P_0c0a8646: /* original 6593, guest PC 0x0c0a8646 */
if(!s->budget--) { s->failed_pc=0x0c0a8646u; return 0; }
r[5]=r[9];
goto P_0c0a8648;
P_0c0a8648: /* original 3e4c, guest PC 0x0c0a8648 */
if(!s->budget--) { s->failed_pc=0x0c0a8648u; return 0; }
r[14]+=r[4];
goto P_0c0a864a;
P_0c0a864a: /* original 66a3, guest PC 0x0c0a864a */
if(!s->budget--) { s->failed_pc=0x0c0a864au; return 0; }
r[6]=r[10];
goto P_0c0a864c;
P_0c0a864c: /* original 64e2, guest PC 0x0c0a864c */
if(!s->budget--) { s->failed_pc=0x0c0a864cu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0a864e;
P_0c0a864e: /* original 242b, guest PC 0x0c0a864e */
if(!s->budget--) { s->failed_pc=0x0c0a864eu; return 0; }
r[4]|=r[2];
goto P_0c0a8650;
P_0c0a8650: /* original 2e42, guest PC 0x0c0a8650 */
if(!s->budget--) { s->failed_pc=0x0c0a8650u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0a8652;
P_0c0a8652: /* original b4f0, guest PC 0x0c0a8652 */
if(!s->budget--) { s->failed_pc=0x0c0a8652u; return 0; }
target=0x0c0a9036u; r[16]=0x0c0a8656u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8656u) { target=s->pc; goto dispatch; }
goto P_0c0a8656;
P_0c0a8654: /* original 64e3, guest PC 0x0c0a8654 */
if(!s->budget--) { s->failed_pc=0x0c0a8654u; return 0; }
r[4]=r[14];
goto P_0c0a8656;
P_0c0a8656: /* original 7e40, guest PC 0x0c0a8656 */
if(!s->budget--) { s->failed_pc=0x0c0a8656u; return 0; }
r[14]+=0x00000040u;
goto P_0c0a8658;
P_0c0a8658: /* original 9316, guest PC 0x0c0a8658 */
if(!s->budget--) { s->failed_pc=0x0c0a8658u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8688u,2);
goto P_0c0a865a;
P_0c0a865a: /* original 62e2, guest PC 0x0c0a865a */
if(!s->budget--) { s->failed_pc=0x0c0a865au; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0a865c;
P_0c0a865c: /* original 65a3, guest PC 0x0c0a865c */
if(!s->budget--) { s->failed_pc=0x0c0a865cu; return 0; }
r[5]=r[10];
goto P_0c0a865e;
P_0c0a865e: /* original 6693, guest PC 0x0c0a865e */
if(!s->budget--) { s->failed_pc=0x0c0a865eu; return 0; }
r[6]=r[9];
goto P_0c0a8660;
P_0c0a8660: /* original 223b, guest PC 0x0c0a8660 */
if(!s->budget--) { s->failed_pc=0x0c0a8660u; return 0; }
r[2]|=r[3];
goto P_0c0a8662;
P_0c0a8662: /* original 2e22, guest PC 0x0c0a8662 */
if(!s->budget--) { s->failed_pc=0x0c0a8662u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0a8664;
P_0c0a8664: /* original b4e7, guest PC 0x0c0a8664 */
if(!s->budget--) { s->failed_pc=0x0c0a8664u; return 0; }
target=0x0c0a9036u; r[16]=0x0c0a8668u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8668u) { target=s->pc; goto dispatch; }
goto P_0c0a8668;
P_0c0a8666: /* original 64e3, guest PC 0x0c0a8666 */
if(!s->budget--) { s->failed_pc=0x0c0a8666u; return 0; }
r[4]=r[14];
goto P_0c0a8668;
P_0c0a8668: /* original d30f, guest PC 0x0c0a8668 */
if(!s->budget--) { s->failed_pc=0x0c0a8668u; return 0; }
r[3]=read(ram,0x0c0a86a8u,4);
goto P_0c0a866a;
P_0c0a866a: /* original 1d33, guest PC 0x0c0a866a */
if(!s->budget--) { s->failed_pc=0x0c0a866au; return 0; }
write(ram,r[13]+12,r[3],4);
goto P_0c0a866c;
P_0c0a866c: /* original 7f0c, guest PC 0x0c0a866c */
if(!s->budget--) { s->failed_pc=0x0c0a866cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a866e;
P_0c0a866e: /* original 4f26, guest PC 0x0c0a866e */
if(!s->budget--) { s->failed_pc=0x0c0a866eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8670;
P_0c0a8670: /* original 68f6, guest PC 0x0c0a8670 */
if(!s->budget--) { s->failed_pc=0x0c0a8670u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a8672;
P_0c0a8672: /* original 69f6, guest PC 0x0c0a8672 */
if(!s->budget--) { s->failed_pc=0x0c0a8672u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a8674;
P_0c0a8674: /* original 6af6, guest PC 0x0c0a8674 */
if(!s->budget--) { s->failed_pc=0x0c0a8674u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a8676;
P_0c0a8676: /* original 6bf6, guest PC 0x0c0a8676 */
if(!s->budget--) { s->failed_pc=0x0c0a8676u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8678;
P_0c0a8678: /* original 6cf6, guest PC 0x0c0a8678 */
if(!s->budget--) { s->failed_pc=0x0c0a8678u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a867a;
P_0c0a867a: /* original 6df6, guest PC 0x0c0a867a */
if(!s->budget--) { s->failed_pc=0x0c0a867au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a867c;
P_0c0a867c: /* original 000b, guest PC 0x0c0a867c */
if(!s->budget--) { s->failed_pc=0x0c0a867cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a867e: /* original 6ef6, guest PC 0x0c0a867e */
if(!s->budget--) { s->failed_pc=0x0c0a867eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a8680u,s,ram);
P_0c0a86ac: /* original 2fe6, guest PC 0x0c0a86ac */
if(!s->budget--) { s->failed_pc=0x0c0a86acu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a86ae;
P_0c0a86ae: /* original 6e53, guest PC 0x0c0a86ae */
if(!s->budget--) { s->failed_pc=0x0c0a86aeu; return 0; }
r[14]=r[5];
goto P_0c0a86b0;
P_0c0a86b0: /* original 2fd6, guest PC 0x0c0a86b0 */
if(!s->budget--) { s->failed_pc=0x0c0a86b0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a86b2;
P_0c0a86b2: /* original 6d73, guest PC 0x0c0a86b2 */
if(!s->budget--) { s->failed_pc=0x0c0a86b2u; return 0; }
r[13]=r[7];
goto P_0c0a86b4;
P_0c0a86b4: /* original 2fc6, guest PC 0x0c0a86b4 */
if(!s->budget--) { s->failed_pc=0x0c0a86b4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a86b6;
P_0c0a86b6: /* original 2fb6, guest PC 0x0c0a86b6 */
if(!s->budget--) { s->failed_pc=0x0c0a86b6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a86b8;
P_0c0a86b8: /* original 6b43, guest PC 0x0c0a86b8 */
if(!s->budget--) { s->failed_pc=0x0c0a86b8u; return 0; }
r[11]=r[4];
goto P_0c0a86ba;
P_0c0a86ba: /* original 4f22, guest PC 0x0c0a86ba */
if(!s->budget--) { s->failed_pc=0x0c0a86bau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a86bc;
P_0c0a86bc: /* original 7ffc, guest PC 0x0c0a86bc */
if(!s->budget--) { s->failed_pc=0x0c0a86bcu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a86be;
P_0c0a86be: /* original 2f62, guest PC 0x0c0a86be */
if(!s->budget--) { s->failed_pc=0x0c0a86beu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0a86c0;
P_0c0a86c0: /* original 64e3, guest PC 0x0c0a86c0 */
if(!s->budget--) { s->failed_pc=0x0c0a86c0u; return 0; }
r[4]=r[14];
goto P_0c0a86c2;
P_0c0a86c2: /* original 4408, guest PC 0x0c0a86c2 */
if(!s->budget--) { s->failed_pc=0x0c0a86c2u; return 0; }
r[4]<<=2;
goto P_0c0a86c4;
P_0c0a86c4: /* original 4408, guest PC 0x0c0a86c4 */
if(!s->budget--) { s->failed_pc=0x0c0a86c4u; return 0; }
r[4]<<=2;
goto P_0c0a86c6;
P_0c0a86c6: /* original dc31, guest PC 0x0c0a86c6 */
if(!s->budget--) { s->failed_pc=0x0c0a86c6u; return 0; }
r[12]=read(ram,0x0c0a878cu,4);
goto P_0c0a86c8;
P_0c0a86c8: /* original 4408, guest PC 0x0c0a86c8 */
if(!s->budget--) { s->failed_pc=0x0c0a86c8u; return 0; }
r[4]<<=2;
goto P_0c0a86ca;
P_0c0a86ca: /* original 4400, guest PC 0x0c0a86ca */
if(!s->budget--) { s->failed_pc=0x0c0a86cau; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a86cc;
P_0c0a86cc: /* original 6643, guest PC 0x0c0a86cc */
if(!s->budget--) { s->failed_pc=0x0c0a86ccu; return 0; }
r[6]=r[4];
goto P_0c0a86ce;
P_0c0a86ce: /* original e03b, guest PC 0x0c0a86ce */
if(!s->budget--) { s->failed_pc=0x0c0a86ceu; return 0; }
r[0]=0x0000003bu;
goto P_0c0a86d0;
P_0c0a86d0: /* original 36cc, guest PC 0x0c0a86d0 */
if(!s->budget--) { s->failed_pc=0x0c0a86d0u; return 0; }
r[6]+=r[12];
goto P_0c0a86d2;
P_0c0a86d2: /* original 046c, guest PC 0x0c0a86d2 */
if(!s->budget--) { s->failed_pc=0x0c0a86d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0a86d4;
P_0c0a86d4: /* original 2448, guest PC 0x0c0a86d4 */
if(!s->budget--) { s->failed_pc=0x0c0a86d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a86d6;
P_0c0a86d6: /* original 8b01, guest PC 0x0c0a86d6 */
if(!s->budget--) { s->failed_pc=0x0c0a86d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a86dc; }
goto P_0c0a86d8;
P_0c0a86d8: /* original a040, guest PC 0x0c0a86d8 */
if(!s->budget--) { s->failed_pc=0x0c0a86d8u; return 0; }
r[0]=0x00000001u;
goto P_0c0a875c;
P_0c0a86da: /* original e001, guest PC 0x0c0a86da */
if(!s->budget--) { s->failed_pc=0x0c0a86dau; return 0; }
r[0]=0x00000001u;
goto P_0c0a86dc;
P_0c0a86dc: /* original 60b3, guest PC 0x0c0a86dc */
if(!s->budget--) { s->failed_pc=0x0c0a86dcu; return 0; }
r[0]=r[11];
goto P_0c0a86de;
P_0c0a86de: /* original 8802, guest PC 0x0c0a86de */
if(!s->budget--) { s->failed_pc=0x0c0a86deu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a86e0;
P_0c0a86e0: /* original 8903, guest PC 0x0c0a86e0 */
if(!s->budget--) { s->failed_pc=0x0c0a86e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a86ea; }
goto P_0c0a86e2;
P_0c0a86e2: /* original 65f2, guest PC 0x0c0a86e2 */
if(!s->budget--) { s->failed_pc=0x0c0a86e2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0a86e4;
P_0c0a86e4: /* original b041, guest PC 0x0c0a86e4 */
if(!s->budget--) { s->failed_pc=0x0c0a86e4u; return 0; }
target=0x0c0a876au; r[16]=0x0c0a86e8u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a86e8u) { target=s->pc; goto dispatch; }
goto P_0c0a86e8;
P_0c0a86e6: /* original 64b3, guest PC 0x0c0a86e6 */
if(!s->budget--) { s->failed_pc=0x0c0a86e6u; return 0; }
r[4]=r[11];
goto P_0c0a86e8;
P_0c0a86e8: /* original 6b03, guest PC 0x0c0a86e8 */
if(!s->budget--) { s->failed_pc=0x0c0a86e8u; return 0; }
r[11]=r[0];
goto P_0c0a86ea;
P_0c0a86ea: /* original 60b3, guest PC 0x0c0a86ea */
if(!s->budget--) { s->failed_pc=0x0c0a86eau; return 0; }
r[0]=r[11];
goto P_0c0a86ec;
P_0c0a86ec: /* original 954a, guest PC 0x0c0a86ec */
if(!s->budget--) { s->failed_pc=0x0c0a86ecu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8784u,2);
goto P_0c0a86ee;
P_0c0a86ee: /* original 8802, guest PC 0x0c0a86ee */
if(!s->budget--) { s->failed_pc=0x0c0a86eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a86f0;
P_0c0a86f0: /* original 8b15, guest PC 0x0c0a86f0 */
if(!s->budget--) { s->failed_pc=0x0c0a86f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a871e; }
goto P_0c0a86f2;
P_0c0a86f2: /* original e400, guest PC 0x0c0a86f2 */
if(!s->budget--) { s->failed_pc=0x0c0a86f2u; return 0; }
r[4]=0x00000000u;
goto P_0c0a86f4;
P_0c0a86f4: /* original 66e3, guest PC 0x0c0a86f4 */
if(!s->budget--) { s->failed_pc=0x0c0a86f4u; return 0; }
r[6]=r[14];
goto P_0c0a86f6;
P_0c0a86f6: /* original 4608, guest PC 0x0c0a86f6 */
if(!s->budget--) { s->failed_pc=0x0c0a86f6u; return 0; }
r[6]<<=2;
goto P_0c0a86f8;
P_0c0a86f8: /* original 4608, guest PC 0x0c0a86f8 */
if(!s->budget--) { s->failed_pc=0x0c0a86f8u; return 0; }
r[6]<<=2;
goto P_0c0a86fa;
P_0c0a86fa: /* original 4608, guest PC 0x0c0a86fa */
if(!s->budget--) { s->failed_pc=0x0c0a86fau; return 0; }
r[6]<<=2;
goto P_0c0a86fc;
P_0c0a86fc: /* original 4600, guest PC 0x0c0a86fc */
if(!s->budget--) { s->failed_pc=0x0c0a86fcu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0a86fe;
P_0c0a86fe: /* original e03b, guest PC 0x0c0a86fe */
if(!s->budget--) { s->failed_pc=0x0c0a86feu; return 0; }
r[0]=0x0000003bu;
goto P_0c0a8700;
P_0c0a8700: /* original 36cc, guest PC 0x0c0a8700 */
if(!s->budget--) { s->failed_pc=0x0c0a8700u; return 0; }
r[6]+=r[12];
goto P_0c0a8702;
P_0c0a8702: /* original 066c, guest PC 0x0c0a8702 */
if(!s->budget--) { s->failed_pc=0x0c0a8702u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0a8704;
P_0c0a8704: /* original 2668, guest PC 0x0c0a8704 */
if(!s->budget--) { s->failed_pc=0x0c0a8704u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0a8706;
P_0c0a8706: /* original 8908, guest PC 0x0c0a8706 */
if(!s->budget--) { s->failed_pc=0x0c0a8706u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a871a; }
goto P_0c0a8708;
P_0c0a8708: /* original 7eff, guest PC 0x0c0a8708 */
if(!s->budget--) { s->failed_pc=0x0c0a8708u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0a870a;
P_0c0a870a: /* original 4e11, guest PC 0x0c0a870a */
if(!s->budget--) { s->failed_pc=0x0c0a870au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0a870c;
P_0c0a870c: /* original 8d01, guest PC 0x0c0a870c */
if(!s->budget--) { s->failed_pc=0x0c0a870cu; return 0; }
cond=r[17]&1u;
r[13]+=0x00000001u;
if(cond) { goto P_0c0a8712; }
goto P_0c0a8710;
P_0c0a870e: /* original 7d01, guest PC 0x0c0a870e */
if(!s->budget--) { s->failed_pc=0x0c0a870eu; return 0; }
r[13]+=0x00000001u;
goto P_0c0a8710;
P_0c0a8710: /* original 6e53, guest PC 0x0c0a8710 */
if(!s->budget--) { s->failed_pc=0x0c0a8710u; return 0; }
r[14]=r[5];
goto P_0c0a8712;
P_0c0a8712: /* original e31e, guest PC 0x0c0a8712 */
if(!s->budget--) { s->failed_pc=0x0c0a8712u; return 0; }
r[3]=0x0000001eu;
goto P_0c0a8714;
P_0c0a8714: /* original 7401, guest PC 0x0c0a8714 */
if(!s->budget--) { s->failed_pc=0x0c0a8714u; return 0; }
r[4]+=0x00000001u;
goto P_0c0a8716;
P_0c0a8716: /* original 3433, guest PC 0x0c0a8716 */
if(!s->budget--) { s->failed_pc=0x0c0a8716u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0a8718;
P_0c0a8718: /* original 8bec, guest PC 0x0c0a8718 */
if(!s->budget--) { s->failed_pc=0x0c0a8718u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a86f4; }
goto P_0c0a871a;
P_0c0a871a: /* original a009, guest PC 0x0c0a871a */
if(!s->budget--) { s->failed_pc=0x0c0a871au; return 0; }
r[4]=r[13];
goto P_0c0a8730;
P_0c0a871c: /* original 64d3, guest PC 0x0c0a871c */
if(!s->budget--) { s->failed_pc=0x0c0a871cu; return 0; }
r[4]=r[13];
goto P_0c0a871e;
P_0c0a871e: /* original 7eff, guest PC 0x0c0a871e */
if(!s->budget--) { s->failed_pc=0x0c0a871eu; return 0; }
r[14]+=0xffffffffu;
goto P_0c0a8720;
P_0c0a8720: /* original 4e11, guest PC 0x0c0a8720 */
if(!s->budget--) { s->failed_pc=0x0c0a8720u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0a8722;
P_0c0a8722: /* original 8d01, guest PC 0x0c0a8722 */
if(!s->budget--) { s->failed_pc=0x0c0a8722u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000001u;
if(cond) { goto P_0c0a8728; }
goto P_0c0a8726;
P_0c0a8724: /* original 7d01, guest PC 0x0c0a8724 */
if(!s->budget--) { s->failed_pc=0x0c0a8724u; return 0; }
r[13]+=0x00000001u;
goto P_0c0a8726;
P_0c0a8726: /* original 6e53, guest PC 0x0c0a8726 */
if(!s->budget--) { s->failed_pc=0x0c0a8726u; return 0; }
r[14]=r[5];
goto P_0c0a8728;
P_0c0a8728: /* original 962d, guest PC 0x0c0a8728 */
if(!s->budget--) { s->failed_pc=0x0c0a8728u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8786u,2);
goto P_0c0a872a;
P_0c0a872a: /* original 3d63, guest PC 0x0c0a872a */
if(!s->budget--) { s->failed_pc=0x0c0a872au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[6])!=0);
goto P_0c0a872c;
P_0c0a872c: /* original 8bc8, guest PC 0x0c0a872c */
if(!s->budget--) { s->failed_pc=0x0c0a872cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a86c0; }
goto P_0c0a872e;
P_0c0a872e: /* original 6463, guest PC 0x0c0a872e */
if(!s->budget--) { s->failed_pc=0x0c0a872eu; return 0; }
r[4]=r[6];
goto P_0c0a8730;
P_0c0a8730: /* original 962a, guest PC 0x0c0a8730 */
if(!s->budget--) { s->failed_pc=0x0c0a8730u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8788u,2);
goto P_0c0a8732;
P_0c0a8732: /* original 3463, guest PC 0x0c0a8732 */
if(!s->budget--) { s->failed_pc=0x0c0a8732u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c0a8734;
P_0c0a8734: /* original 8911, guest PC 0x0c0a8734 */
if(!s->budget--) { s->failed_pc=0x0c0a8734u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a875a; }
goto P_0c0a8736;
P_0c0a8736: /* original 67e3, guest PC 0x0c0a8736 */
if(!s->budget--) { s->failed_pc=0x0c0a8736u; return 0; }
r[7]=r[14];
goto P_0c0a8738;
P_0c0a8738: /* original 4708, guest PC 0x0c0a8738 */
if(!s->budget--) { s->failed_pc=0x0c0a8738u; return 0; }
r[7]<<=2;
goto P_0c0a873a;
P_0c0a873a: /* original 4708, guest PC 0x0c0a873a */
if(!s->budget--) { s->failed_pc=0x0c0a873au; return 0; }
r[7]<<=2;
goto P_0c0a873c;
P_0c0a873c: /* original 4708, guest PC 0x0c0a873c */
if(!s->budget--) { s->failed_pc=0x0c0a873cu; return 0; }
r[7]<<=2;
goto P_0c0a873e;
P_0c0a873e: /* original 4700, guest PC 0x0c0a873e */
if(!s->budget--) { s->failed_pc=0x0c0a873eu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c0a8740;
P_0c0a8740: /* original e03b, guest PC 0x0c0a8740 */
if(!s->budget--) { s->failed_pc=0x0c0a8740u; return 0; }
r[0]=0x0000003bu;
goto P_0c0a8742;
P_0c0a8742: /* original 37cc, guest PC 0x0c0a8742 */
if(!s->budget--) { s->failed_pc=0x0c0a8742u; return 0; }
r[7]+=r[12];
goto P_0c0a8744;
P_0c0a8744: /* original 077c, guest PC 0x0c0a8744 */
if(!s->budget--) { s->failed_pc=0x0c0a8744u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c0a8746;
P_0c0a8746: /* original 2778, guest PC 0x0c0a8746 */
if(!s->budget--) { s->failed_pc=0x0c0a8746u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0a8748;
P_0c0a8748: /* original 8907, guest PC 0x0c0a8748 */
if(!s->budget--) { s->failed_pc=0x0c0a8748u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a875a; }
goto P_0c0a874a;
P_0c0a874a: /* original 7eff, guest PC 0x0c0a874a */
if(!s->budget--) { s->failed_pc=0x0c0a874au; return 0; }
r[14]+=0xffffffffu;
goto P_0c0a874c;
P_0c0a874c: /* original 4e11, guest PC 0x0c0a874c */
if(!s->budget--) { s->failed_pc=0x0c0a874cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0a874e;
P_0c0a874e: /* original 7d01, guest PC 0x0c0a874e */
if(!s->budget--) { s->failed_pc=0x0c0a874eu; return 0; }
r[13]+=0x00000001u;
goto P_0c0a8750;
P_0c0a8750: /* original 8d01, guest PC 0x0c0a8750 */
if(!s->budget--) { s->failed_pc=0x0c0a8750u; return 0; }
cond=r[17]&1u;
r[4]=r[13];
if(cond) { goto P_0c0a8756; }
goto P_0c0a8754;
P_0c0a8752: /* original 64d3, guest PC 0x0c0a8752 */
if(!s->budget--) { s->failed_pc=0x0c0a8752u; return 0; }
r[4]=r[13];
goto P_0c0a8754;
P_0c0a8754: /* original 6e53, guest PC 0x0c0a8754 */
if(!s->budget--) { s->failed_pc=0x0c0a8754u; return 0; }
r[14]=r[5];
goto P_0c0a8756;
P_0c0a8756: /* original 3467, guest PC 0x0c0a8756 */
if(!s->budget--) { s->failed_pc=0x0c0a8756u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[6])!=0);
goto P_0c0a8758;
P_0c0a8758: /* original 8bed, guest PC 0x0c0a8758 */
if(!s->budget--) { s->failed_pc=0x0c0a8758u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8736; }
goto P_0c0a875a;
P_0c0a875a: /* original 6043, guest PC 0x0c0a875a */
if(!s->budget--) { s->failed_pc=0x0c0a875au; return 0; }
r[0]=r[4];
goto P_0c0a875c;
P_0c0a875c: /* original 7f04, guest PC 0x0c0a875c */
if(!s->budget--) { s->failed_pc=0x0c0a875cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0a875e;
P_0c0a875e: /* original 4f26, guest PC 0x0c0a875e */
if(!s->budget--) { s->failed_pc=0x0c0a875eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8760;
P_0c0a8760: /* original 6bf6, guest PC 0x0c0a8760 */
if(!s->budget--) { s->failed_pc=0x0c0a8760u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8762;
P_0c0a8762: /* original 6cf6, guest PC 0x0c0a8762 */
if(!s->budget--) { s->failed_pc=0x0c0a8762u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8764;
P_0c0a8764: /* original 6df6, guest PC 0x0c0a8764 */
if(!s->budget--) { s->failed_pc=0x0c0a8764u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8766;
P_0c0a8766: /* original 000b, guest PC 0x0c0a8766 */
if(!s->budget--) { s->failed_pc=0x0c0a8766u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a8768: /* original 6ef6, guest PC 0x0c0a8768 */
if(!s->budget--) { s->failed_pc=0x0c0a8768u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a876a;
P_0c0a876a: /* original 2448, guest PC 0x0c0a876a */
if(!s->budget--) { s->failed_pc=0x0c0a876au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a876c;
P_0c0a876c: /* original 8f12, guest PC 0x0c0a876c */
if(!s->budget--) { s->failed_pc=0x0c0a876cu; return 0; }
cond=r[17]&1u;
r[7]=r[6];
if(!cond) { goto P_0c0a8794; }
goto P_0c0a8770;
P_0c0a876e: /* original 6763, guest PC 0x0c0a876e */
if(!s->budget--) { s->failed_pc=0x0c0a876eu; return 0; }
r[7]=r[6];
goto P_0c0a8770;
P_0c0a8770: /* original 2558, guest PC 0x0c0a8770 */
if(!s->budget--) { s->failed_pc=0x0c0a8770u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0a8772;
P_0c0a8772: /* original 8901, guest PC 0x0c0a8772 */
if(!s->budget--) { s->failed_pc=0x0c0a8772u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8778; }
goto P_0c0a8774;
P_0c0a8774: /* original 6763, guest PC 0x0c0a8774 */
if(!s->budget--) { s->failed_pc=0x0c0a8774u; return 0; }
r[7]=r[6];
goto P_0c0a8776;
P_0c0a8776: /* original 7740, guest PC 0x0c0a8776 */
if(!s->budget--) { s->failed_pc=0x0c0a8776u; return 0; }
r[7]+=0x00000040u;
goto P_0c0a8778;
P_0c0a8778: /* original d605, guest PC 0x0c0a8778 */
if(!s->budget--) { s->failed_pc=0x0c0a8778u; return 0; }
r[6]=read(ram,0x0c0a8790u,4);
goto P_0c0a877a;
P_0c0a877a: /* original 5574, guest PC 0x0c0a877a */
if(!s->budget--) { s->failed_pc=0x0c0a877au; return 0; }
r[5]=read(ram,r[7]+16,4);
goto P_0c0a877c;
P_0c0a877c: /* original 2568, guest PC 0x0c0a877c */
if(!s->budget--) { s->failed_pc=0x0c0a877cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[6])==0)!=0);
goto P_0c0a877e;
P_0c0a877e: /* original 8b12, guest PC 0x0c0a877e */
if(!s->budget--) { s->failed_pc=0x0c0a877eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a87a6; }
goto P_0c0a8780;
P_0c0a8780: /* original a011, guest PC 0x0c0a8780 */
if(!s->budget--) { s->failed_pc=0x0c0a8780u; return 0; }
r[4]=0x00000001u;
goto P_0c0a87a6;
P_0c0a8782: /* original e401, guest PC 0x0c0a8782 */
if(!s->budget--) { s->failed_pc=0x0c0a8782u; return 0; }
r[4]=0x00000001u;
return vf3_matrix_family(0x0c0a8784u,s,ram);
P_0c0a8794: /* original 2558, guest PC 0x0c0a8794 */
if(!s->budget--) { s->failed_pc=0x0c0a8794u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0a8796;
P_0c0a8796: /* original 8b01, guest PC 0x0c0a8796 */
if(!s->budget--) { s->failed_pc=0x0c0a8796u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a879c; }
goto P_0c0a8798;
P_0c0a8798: /* original 6763, guest PC 0x0c0a8798 */
if(!s->budget--) { s->failed_pc=0x0c0a8798u; return 0; }
r[7]=r[6];
goto P_0c0a879a;
P_0c0a879a: /* original 7740, guest PC 0x0c0a879a */
if(!s->budget--) { s->failed_pc=0x0c0a879au; return 0; }
r[7]+=0x00000040u;
goto P_0c0a879c;
P_0c0a879c: /* original d514, guest PC 0x0c0a879c */
if(!s->budget--) { s->failed_pc=0x0c0a879cu; return 0; }
r[5]=read(ram,0x0c0a87f0u,4);
goto P_0c0a879e;
P_0c0a879e: /* original 5674, guest PC 0x0c0a879e */
if(!s->budget--) { s->failed_pc=0x0c0a879eu; return 0; }
r[6]=read(ram,r[7]+16,4);
goto P_0c0a87a0;
P_0c0a87a0: /* original 2658, guest PC 0x0c0a87a0 */
if(!s->budget--) { s->failed_pc=0x0c0a87a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[5])==0)!=0);
goto P_0c0a87a2;
P_0c0a87a2: /* original 8b00, guest PC 0x0c0a87a2 */
if(!s->budget--) { s->failed_pc=0x0c0a87a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a87a6; }
goto P_0c0a87a4;
P_0c0a87a4: /* original e402, guest PC 0x0c0a87a4 */
if(!s->budget--) { s->failed_pc=0x0c0a87a4u; return 0; }
r[4]=0x00000002u;
goto P_0c0a87a6;
P_0c0a87a6: /* original 000b, guest PC 0x0c0a87a6 */
if(!s->budget--) { s->failed_pc=0x0c0a87a6u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c0a87a8: /* original 6043, guest PC 0x0c0a87a8 */
if(!s->budget--) { s->failed_pc=0x0c0a87a8u; return 0; }
r[0]=r[4];
return vf3_matrix_family(0x0c0a87aau,s,ram);
P_0c0a8f10: /* original c71d, guest PC 0x0c0a8f10 */
if(!s->budget--) { s->failed_pc=0x0c0a8f10u; return 0; }
r[0]=0x0c0a8f88u;
goto P_0c0a8f12;
P_0c0a8f12: /* original f558, guest PC 0x0c0a8f12 */
if(!s->budget--) { s->failed_pc=0x0c0a8f12u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
goto P_0c0a8f14;
P_0c0a8f14: /* original f408, guest PC 0x0c0a8f14 */
if(!s->budget--) { s->failed_pc=0x0c0a8f14u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0a8f16;
P_0c0a8f16: /* original e010, guest PC 0x0c0a8f16 */
if(!s->budget--) { s->failed_pc=0x0c0a8f16u; return 0; }
r[0]=0x00000010u;
goto P_0c0a8f18;
P_0c0a8f18: /* original f346, guest PC 0x0c0a8f18 */
if(!s->budget--) { s->failed_pc=0x0c0a8f18u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a8f1a;
P_0c0a8f1a: /* original e014, guest PC 0x0c0a8f1a */
if(!s->budget--) { s->failed_pc=0x0c0a8f1au; return 0; }
r[0]=0x00000014u;
goto P_0c0a8f1c;
P_0c0a8f1c: /* original f64c, guest PC 0x0c0a8f1c */
if(!s->budget--) { s->failed_pc=0x0c0a8f1cu; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c0a8f1e;
P_0c0a8f1e: /* original f530, guest PC 0x0c0a8f1e */
if(!s->budget--) { s->failed_pc=0x0c0a8f1eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0a8f20;
P_0c0a8f20: /* original f346, guest PC 0x0c0a8f20 */
if(!s->budget--) { s->failed_pc=0x0c0a8f20u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a8f22;
P_0c0a8f22: /* original f74c, guest PC 0x0c0a8f22 */
if(!s->budget--) { s->failed_pc=0x0c0a8f22u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c0a8f24;
P_0c0a8f24: /* original e018, guest PC 0x0c0a8f24 */
if(!s->budget--) { s->failed_pc=0x0c0a8f24u; return 0; }
r[0]=0x00000018u;
goto P_0c0a8f26;
P_0c0a8f26: /* original f652, guest PC 0x0c0a8f26 */
if(!s->budget--) { s->failed_pc=0x0c0a8f26u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c0a8f28;
P_0c0a8f28: /* original f568, guest PC 0x0c0a8f28 */
if(!s->budget--) { s->failed_pc=0x0c0a8f28u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0a8f2a;
P_0c0a8f2a: /* original f530, guest PC 0x0c0a8f2a */
if(!s->budget--) { s->failed_pc=0x0c0a8f2au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0a8f2c;
P_0c0a8f2c: /* original f346, guest PC 0x0c0a8f2c */
if(!s->budget--) { s->failed_pc=0x0c0a8f2cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a8f2e;
P_0c0a8f2e: /* original f752, guest PC 0x0c0a8f2e */
if(!s->budget--) { s->failed_pc=0x0c0a8f2eu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'*');
goto P_0c0a8f30;
P_0c0a8f30: /* original f578, guest PC 0x0c0a8f30 */
if(!s->budget--) { s->failed_pc=0x0c0a8f30u; return 0; }
vf3_matrix_load(s,ram,5,r[7]);
goto P_0c0a8f32;
P_0c0a8f32: /* original f56a, guest PC 0x0c0a8f32 */
if(!s->budget--) { s->failed_pc=0x0c0a8f32u; return 0; }
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c0a8f34;
P_0c0a8f34: /* original f530, guest PC 0x0c0a8f34 */
if(!s->budget--) { s->failed_pc=0x0c0a8f34u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0a8f36;
P_0c0a8f36: /* original f67a, guest PC 0x0c0a8f36 */
if(!s->budget--) { s->failed_pc=0x0c0a8f36u; return 0; }
vf3_matrix_store(s,ram,7,r[6]);
goto P_0c0a8f38;
P_0c0a8f38: /* original f452, guest PC 0x0c0a8f38 */
if(!s->budget--) { s->failed_pc=0x0c0a8f38u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c0a8f3a;
P_0c0a8f3a: /* original 000b, guest PC 0x0c0a8f3a */
if(!s->budget--) { s->failed_pc=0x0c0a8f3au; return 0; }
target=r[16];
vf3_matrix_store(s,ram,4,r[7]);
s->pc=target; return ram->oob==0;
P_0c0a8f3c: /* original f74a, guest PC 0x0c0a8f3c */
if(!s->budget--) { s->failed_pc=0x0c0a8f3cu; return 0; }
vf3_matrix_store(s,ram,4,r[7]);
goto P_0c0a8f3e;
P_0c0a8f3e: /* original 854f, guest PC 0x0c0a8f3e */
if(!s->budget--) { s->failed_pc=0x0c0a8f3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+30,2);
goto P_0c0a8f40;
P_0c0a8f40: /* original 655f, guest PC 0x0c0a8f40 */
if(!s->budget--) { s->failed_pc=0x0c0a8f40u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c0a8f42;
P_0c0a8f42: /* original 6403, guest PC 0x0c0a8f42 */
if(!s->budget--) { s->failed_pc=0x0c0a8f42u; return 0; }
r[4]=r[0];
goto P_0c0a8f44;
P_0c0a8f44: /* original 345c, guest PC 0x0c0a8f44 */
if(!s->budget--) { s->failed_pc=0x0c0a8f44u; return 0; }
r[4]+=r[5];
goto P_0c0a8f46;
P_0c0a8f46: /* original 4421, guest PC 0x0c0a8f46 */
if(!s->budget--) { s->failed_pc=0x0c0a8f46u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]=(uint32_t)((int32_t)r[4]>>1);
goto P_0c0a8f48;
P_0c0a8f48: /* original 000b, guest PC 0x0c0a8f48 */
if(!s->budget--) { s->failed_pc=0x0c0a8f48u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c0a8f4a: /* original 6043, guest PC 0x0c0a8f4a */
if(!s->budget--) { s->failed_pc=0x0c0a8f4au; return 0; }
r[0]=r[4];
return vf3_matrix_family(0x0c0a8f4cu,s,ram);
P_0c0a8f8c: /* original 2fe6, guest PC 0x0c0a8f8c */
if(!s->budget--) { s->failed_pc=0x0c0a8f8cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8f8e;
P_0c0a8f8e: /* original 6e53, guest PC 0x0c0a8f8e */
if(!s->budget--) { s->failed_pc=0x0c0a8f8eu; return 0; }
r[14]=r[5];
goto P_0c0a8f90;
P_0c0a8f90: /* original 2fd6, guest PC 0x0c0a8f90 */
if(!s->budget--) { s->failed_pc=0x0c0a8f90u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8f92;
P_0c0a8f92: /* original 6d43, guest PC 0x0c0a8f92 */
if(!s->budget--) { s->failed_pc=0x0c0a8f92u; return 0; }
r[13]=r[4];
goto P_0c0a8f94;
P_0c0a8f94: /* original 906b, guest PC 0x0c0a8f94 */
if(!s->budget--) { s->failed_pc=0x0c0a8f94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a906eu,2);
goto P_0c0a8f96;
P_0c0a8f96: /* original e700, guest PC 0x0c0a8f96 */
if(!s->budget--) { s->failed_pc=0x0c0a8f96u; return 0; }
r[7]=0x00000000u;
goto P_0c0a8f98;
P_0c0a8f98: /* original 4f22, guest PC 0x0c0a8f98 */
if(!s->budget--) { s->failed_pc=0x0c0a8f98u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a8f9a;
P_0c0a8f9a: /* original 04ee, guest PC 0x0c0a8f9a */
if(!s->budget--) { s->failed_pc=0x0c0a8f9au; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0a8f9c;
P_0c0a8f9c: /* original e024, guest PC 0x0c0a8f9c */
if(!s->budget--) { s->failed_pc=0x0c0a8f9cu; return 0; }
r[0]=0x00000024u;
goto P_0c0a8f9e;
P_0c0a8f9e: /* original 00dd, guest PC 0x0c0a8f9e */
if(!s->budget--) { s->failed_pc=0x0c0a8f9eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a8fa0;
P_0c0a8fa0: /* original 7ff0, guest PC 0x0c0a8fa0 */
if(!s->budget--) { s->failed_pc=0x0c0a8fa0u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0a8fa2;
P_0c0a8fa2: /* original 81f6, guest PC 0x0c0a8fa2 */
if(!s->budget--) { s->failed_pc=0x0c0a8fa2u; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c0a8fa4;
P_0c0a8fa4: /* original e03e, guest PC 0x0c0a8fa4 */
if(!s->budget--) { s->failed_pc=0x0c0a8fa4u; return 0; }
r[0]=0x0000003eu;
goto P_0c0a8fa6;
P_0c0a8fa6: /* original 0e45, guest PC 0x0c0a8fa6 */
if(!s->budget--) { s->failed_pc=0x0c0a8fa6u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a8fa8;
P_0c0a8fa8: /* original 85f6, guest PC 0x0c0a8fa8 */
if(!s->budget--) { s->failed_pc=0x0c0a8fa8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c0a8faa;
P_0c0a8faa: /* original 6503, guest PC 0x0c0a8faa */
if(!s->budget--) { s->failed_pc=0x0c0a8faau; return 0; }
r[5]=r[0];
goto P_0c0a8fac;
P_0c0a8fac: /* original 3450, guest PC 0x0c0a8fac */
if(!s->budget--) { s->failed_pc=0x0c0a8facu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c0a8fae;
P_0c0a8fae: /* original 8d01, guest PC 0x0c0a8fae */
if(!s->budget--) { s->failed_pc=0x0c0a8faeu; return 0; }
cond=r[17]&1u;
r[6]=r[7];
if(cond) { goto P_0c0a8fb4; }
goto P_0c0a8fb2;
P_0c0a8fb0: /* original 6673, guest PC 0x0c0a8fb0 */
if(!s->budget--) { s->failed_pc=0x0c0a8fb0u; return 0; }
r[6]=r[7];
goto P_0c0a8fb2;
P_0c0a8fb2: /* original 965d, guest PC 0x0c0a8fb2 */
if(!s->budget--) { s->failed_pc=0x0c0a8fb2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9070u,2);
goto P_0c0a8fb4;
P_0c0a8fb4: /* original 3457, guest PC 0x0c0a8fb4 */
if(!s->budget--) { s->failed_pc=0x0c0a8fb4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[5])!=0);
goto P_0c0a8fb6;
P_0c0a8fb6: /* original e040, guest PC 0x0c0a8fb6 */
if(!s->budget--) { s->failed_pc=0x0c0a8fb6u; return 0; }
r[0]=0x00000040u;
goto P_0c0a8fb8;
P_0c0a8fb8: /* original 8d06, guest PC 0x0c0a8fb8 */
if(!s->budget--) { s->failed_pc=0x0c0a8fb8u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[6],2);
if(cond) { goto P_0c0a8fc8; }
goto P_0c0a8fbc;
P_0c0a8fba: /* original 0e65, guest PC 0x0c0a8fba */
if(!s->budget--) { s->failed_pc=0x0c0a8fbau; return 0; }
write(ram,r[14]+r[0],r[6],2);
goto P_0c0a8fbc;
P_0c0a8fbc: /* original e03c, guest PC 0x0c0a8fbc */
if(!s->budget--) { s->failed_pc=0x0c0a8fbcu; return 0; }
r[0]=0x0000003cu;
goto P_0c0a8fbe;
P_0c0a8fbe: /* original 05ed, guest PC 0x0c0a8fbe */
if(!s->budget--) { s->failed_pc=0x0c0a8fbeu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a8fc0;
P_0c0a8fc0: /* original e022, guest PC 0x0c0a8fc0 */
if(!s->budget--) { s->failed_pc=0x0c0a8fc0u; return 0; }
r[0]=0x00000022u;
goto P_0c0a8fc2;
P_0c0a8fc2: /* original 04dd, guest PC 0x0c0a8fc2 */
if(!s->budget--) { s->failed_pc=0x0c0a8fc2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a8fc4;
P_0c0a8fc4: /* original 3540, guest PC 0x0c0a8fc4 */
if(!s->budget--) { s->failed_pc=0x0c0a8fc4u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[4])!=0);
goto P_0c0a8fc6;
P_0c0a8fc6: /* original 8902, guest PC 0x0c0a8fc6 */
if(!s->budget--) { s->failed_pc=0x0c0a8fc6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8fce; }
goto P_0c0a8fc8;
P_0c0a8fc8: /* original e040, guest PC 0x0c0a8fc8 */
if(!s->budget--) { s->failed_pc=0x0c0a8fc8u; return 0; }
r[0]=0x00000040u;
goto P_0c0a8fca;
P_0c0a8fca: /* original a029, guest PC 0x0c0a8fca */
if(!s->budget--) { s->failed_pc=0x0c0a8fcau; return 0; }
write(ram,r[14]+r[0],r[7],2);
goto P_0c0a9020;
P_0c0a8fcc: /* original 0e75, guest PC 0x0c0a8fcc */
if(!s->budget--) { s->failed_pc=0x0c0a8fccu; return 0; }
write(ram,r[14]+r[0],r[7],2);
goto P_0c0a8fce;
P_0c0a8fce: /* original d62a, guest PC 0x0c0a8fce */
if(!s->budget--) { s->failed_pc=0x0c0a8fceu; return 0; }
r[6]=read(ram,0x0c0a9078u,4);
goto P_0c0a8fd0;
P_0c0a8fd0: /* original 65d2, guest PC 0x0c0a8fd0 */
if(!s->budget--) { s->failed_pc=0x0c0a8fd0u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0a8fd2;
P_0c0a8fd2: /* original 64e2, guest PC 0x0c0a8fd2 */
if(!s->budget--) { s->failed_pc=0x0c0a8fd2u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0a8fd4;
P_0c0a8fd4: /* original 2569, guest PC 0x0c0a8fd4 */
if(!s->budget--) { s->failed_pc=0x0c0a8fd4u; return 0; }
r[5]&=r[6];
goto P_0c0a8fd6;
P_0c0a8fd6: /* original 2469, guest PC 0x0c0a8fd6 */
if(!s->budget--) { s->failed_pc=0x0c0a8fd6u; return 0; }
r[4]&=r[6];
goto P_0c0a8fd8;
P_0c0a8fd8: /* original 3450, guest PC 0x0c0a8fd8 */
if(!s->budget--) { s->failed_pc=0x0c0a8fd8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c0a8fda;
P_0c0a8fda: /* original 8b21, guest PC 0x0c0a8fda */
if(!s->budget--) { s->failed_pc=0x0c0a8fdau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9020; }
goto P_0c0a8fdc;
P_0c0a8fdc: /* original e004, guest PC 0x0c0a8fdc */
if(!s->budget--) { s->failed_pc=0x0c0a8fdcu; return 0; }
r[0]=0x00000004u;
goto P_0c0a8fde;
P_0c0a8fde: /* original 65f3, guest PC 0x0c0a8fde */
if(!s->budget--) { s->failed_pc=0x0c0a8fdeu; return 0; }
r[5]=r[15];
goto P_0c0a8fe0;
P_0c0a8fe0: /* original f3d6, guest PC 0x0c0a8fe0 */
if(!s->budget--) { s->failed_pc=0x0c0a8fe0u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0a8fe2;
P_0c0a8fe2: /* original e008, guest PC 0x0c0a8fe2 */
if(!s->budget--) { s->failed_pc=0x0c0a8fe2u; return 0; }
r[0]=0x00000008u;
goto P_0c0a8fe4;
P_0c0a8fe4: /* original 66f3, guest PC 0x0c0a8fe4 */
if(!s->budget--) { s->failed_pc=0x0c0a8fe4u; return 0; }
r[6]=r[15];
goto P_0c0a8fe6;
P_0c0a8fe6: /* original 7508, guest PC 0x0c0a8fe6 */
if(!s->budget--) { s->failed_pc=0x0c0a8fe6u; return 0; }
r[5]+=0x00000008u;
goto P_0c0a8fe8;
P_0c0a8fe8: /* original ff37, guest PC 0x0c0a8fe8 */
if(!s->budget--) { s->failed_pc=0x0c0a8fe8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a8fea;
P_0c0a8fea: /* original e008, guest PC 0x0c0a8fea */
if(!s->budget--) { s->failed_pc=0x0c0a8feau; return 0; }
r[0]=0x00000008u;
goto P_0c0a8fec;
P_0c0a8fec: /* original f3d6, guest PC 0x0c0a8fec */
if(!s->budget--) { s->failed_pc=0x0c0a8fecu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0a8fee;
P_0c0a8fee: /* original e004, guest PC 0x0c0a8fee */
if(!s->budget--) { s->failed_pc=0x0c0a8feeu; return 0; }
r[0]=0x00000004u;
goto P_0c0a8ff0;
P_0c0a8ff0: /* original 7604, guest PC 0x0c0a8ff0 */
if(!s->budget--) { s->failed_pc=0x0c0a8ff0u; return 0; }
r[6]+=0x00000004u;
goto P_0c0a8ff2;
P_0c0a8ff2: /* original 67f3, guest PC 0x0c0a8ff2 */
if(!s->budget--) { s->failed_pc=0x0c0a8ff2u; return 0; }
r[7]=r[15];
goto P_0c0a8ff4;
P_0c0a8ff4: /* original ff37, guest PC 0x0c0a8ff4 */
if(!s->budget--) { s->failed_pc=0x0c0a8ff4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a8ff6;
P_0c0a8ff6: /* original e00c, guest PC 0x0c0a8ff6 */
if(!s->budget--) { s->failed_pc=0x0c0a8ff6u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a8ff8;
P_0c0a8ff8: /* original f3d6, guest PC 0x0c0a8ff8 */
if(!s->budget--) { s->failed_pc=0x0c0a8ff8u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0a8ffa;
P_0c0a8ffa: /* original ff3a, guest PC 0x0c0a8ffa */
if(!s->budget--) { s->failed_pc=0x0c0a8ffau; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0a8ffc;
P_0c0a8ffc: /* original bf88, guest PC 0x0c0a8ffc */
if(!s->budget--) { s->failed_pc=0x0c0a8ffcu; return 0; }
target=0x0c0a8f10u; r[16]=0x0c0a9000u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a9000u) { target=s->pc; goto dispatch; }
goto P_0c0a9000;
P_0c0a8ffe: /* original 64e3, guest PC 0x0c0a8ffe */
if(!s->budget--) { s->failed_pc=0x0c0a8ffeu; return 0; }
r[4]=r[14];
goto P_0c0a9000;
P_0c0a9000: /* original e008, guest PC 0x0c0a9000 */
if(!s->budget--) { s->failed_pc=0x0c0a9000u; return 0; }
r[0]=0x00000008u;
goto P_0c0a9002;
P_0c0a9002: /* original f6f8, guest PC 0x0c0a9002 */
if(!s->budget--) { s->failed_pc=0x0c0a9002u; return 0; }
vf3_matrix_load(s,ram,6,r[15]);
goto P_0c0a9004;
P_0c0a9004: /* original f4f6, guest PC 0x0c0a9004 */
if(!s->budget--) { s->failed_pc=0x0c0a9004u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0a9006;
P_0c0a9006: /* original e004, guest PC 0x0c0a9006 */
if(!s->budget--) { s->failed_pc=0x0c0a9006u; return 0; }
r[0]=0x00000004u;
goto P_0c0a9008;
P_0c0a9008: /* original f5f6, guest PC 0x0c0a9008 */
if(!s->budget--) { s->failed_pc=0x0c0a9008u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0a900a;
P_0c0a900a: /* original e010, guest PC 0x0c0a900a */
if(!s->budget--) { s->failed_pc=0x0c0a900au; return 0; }
r[0]=0x00000010u;
goto P_0c0a900c;
P_0c0a900c: /* original fe47, guest PC 0x0c0a900c */
if(!s->budget--) { s->failed_pc=0x0c0a900cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a900e;
P_0c0a900e: /* original e014, guest PC 0x0c0a900e */
if(!s->budget--) { s->failed_pc=0x0c0a900eu; return 0; }
r[0]=0x00000014u;
goto P_0c0a9010;
P_0c0a9010: /* original fe57, guest PC 0x0c0a9010 */
if(!s->budget--) { s->failed_pc=0x0c0a9010u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a9012;
P_0c0a9012: /* original e018, guest PC 0x0c0a9012 */
if(!s->budget--) { s->failed_pc=0x0c0a9012u; return 0; }
r[0]=0x00000018u;
goto P_0c0a9014;
P_0c0a9014: /* original fe67, guest PC 0x0c0a9014 */
if(!s->budget--) { s->failed_pc=0x0c0a9014u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c0a9016;
P_0c0a9016: /* original e020, guest PC 0x0c0a9016 */
if(!s->budget--) { s->failed_pc=0x0c0a9016u; return 0; }
r[0]=0x00000020u;
goto P_0c0a9018;
P_0c0a9018: /* original 05dd, guest PC 0x0c0a9018 */
if(!s->budget--) { s->failed_pc=0x0c0a9018u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a901a;
P_0c0a901a: /* original bf90, guest PC 0x0c0a901a */
if(!s->budget--) { s->failed_pc=0x0c0a901au; return 0; }
target=0x0c0a8f3eu; r[16]=0x0c0a901eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a901eu) { target=s->pc; goto dispatch; }
goto P_0c0a901e;
P_0c0a901c: /* original 64e3, guest PC 0x0c0a901c */
if(!s->budget--) { s->failed_pc=0x0c0a901cu; return 0; }
r[4]=r[14];
goto P_0c0a901e;
P_0c0a901e: /* original 81ef, guest PC 0x0c0a901e */
if(!s->budget--) { s->failed_pc=0x0c0a901eu; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0a9020;
P_0c0a9020: /* original d216, guest PC 0x0c0a9020 */
if(!s->budget--) { s->failed_pc=0x0c0a9020u; return 0; }
r[2]=read(ram,0x0c0a907cu,4);
goto P_0c0a9022;
P_0c0a9022: /* original 420b, guest PC 0x0c0a9022 */
if(!s->budget--) { s->failed_pc=0x0c0a9022u; return 0; }
target=r[2];
r[16]=0x0c0a9026u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a9026u) { target=s->pc; goto dispatch; }
goto P_0c0a9026;
P_0c0a9024: /* original 64e3, guest PC 0x0c0a9024 */
if(!s->budget--) { s->failed_pc=0x0c0a9024u; return 0; }
r[4]=r[14];
goto P_0c0a9026;
P_0c0a9026: /* original d316, guest PC 0x0c0a9026 */
if(!s->budget--) { s->failed_pc=0x0c0a9026u; return 0; }
r[3]=read(ram,0x0c0a9080u,4);
goto P_0c0a9028;
P_0c0a9028: /* original 430b, guest PC 0x0c0a9028 */
if(!s->budget--) { s->failed_pc=0x0c0a9028u; return 0; }
target=r[3];
r[16]=0x0c0a902cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a902cu) { target=s->pc; goto dispatch; }
goto P_0c0a902c;
P_0c0a902a: /* original 64e3, guest PC 0x0c0a902a */
if(!s->budget--) { s->failed_pc=0x0c0a902au; return 0; }
r[4]=r[14];
goto P_0c0a902c;
P_0c0a902c: /* original 7f10, guest PC 0x0c0a902c */
if(!s->budget--) { s->failed_pc=0x0c0a902cu; return 0; }
r[15]+=0x00000010u;
goto P_0c0a902e;
P_0c0a902e: /* original 4f26, guest PC 0x0c0a902e */
if(!s->budget--) { s->failed_pc=0x0c0a902eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9030;
P_0c0a9030: /* original 6df6, guest PC 0x0c0a9030 */
if(!s->budget--) { s->failed_pc=0x0c0a9030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a9032;
P_0c0a9032: /* original 000b, guest PC 0x0c0a9032 */
if(!s->budget--) { s->failed_pc=0x0c0a9032u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a9034: /* original 6ef6, guest PC 0x0c0a9034 */
if(!s->budget--) { s->failed_pc=0x0c0a9034u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a9036;
P_0c0a9036: /* original 2fe6, guest PC 0x0c0a9036 */
if(!s->budget--) { s->failed_pc=0x0c0a9036u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a9038;
P_0c0a9038: /* original 2fd6, guest PC 0x0c0a9038 */
if(!s->budget--) { s->failed_pc=0x0c0a9038u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a903a;
P_0c0a903a: /* original 6d43, guest PC 0x0c0a903a */
if(!s->budget--) { s->failed_pc=0x0c0a903au; return 0; }
r[13]=r[4];
goto P_0c0a903c;
P_0c0a903c: /* original 2fc6, guest PC 0x0c0a903c */
if(!s->budget--) { s->failed_pc=0x0c0a903cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a903e;
P_0c0a903e: /* original 2fb6, guest PC 0x0c0a903e */
if(!s->budget--) { s->failed_pc=0x0c0a903eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a9040;
P_0c0a9040: /* original 4f22, guest PC 0x0c0a9040 */
if(!s->budget--) { s->failed_pc=0x0c0a9040u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a9042;
P_0c0a9042: /* original 7fe8, guest PC 0x0c0a9042 */
if(!s->budget--) { s->failed_pc=0x0c0a9042u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0a9044;
P_0c0a9044: /* original 1f61, guest PC 0x0c0a9044 */
if(!s->budget--) { s->failed_pc=0x0c0a9044u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0a9046;
P_0c0a9046: /* original db0f, guest PC 0x0c0a9046 */
if(!s->budget--) { s->failed_pc=0x0c0a9046u; return 0; }
r[11]=read(ram,0x0c0a9084u,4);
goto P_0c0a9048;
P_0c0a9048: /* original 9313, guest PC 0x0c0a9048 */
if(!s->budget--) { s->failed_pc=0x0c0a9048u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9072u,2);
goto P_0c0a904a;
P_0c0a904a: /* original 5cb2, guest PC 0x0c0a904a */
if(!s->budget--) { s->failed_pc=0x0c0a904au; return 0; }
r[12]=read(ram,r[11]+8,4);
goto P_0c0a904c;
P_0c0a904c: /* original 23c8, guest PC 0x0c0a904c */
if(!s->budget--) { s->failed_pc=0x0c0a904cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0a904e;
P_0c0a904e: /* original 8d1b, guest PC 0x0c0a904e */
if(!s->budget--) { s->failed_pc=0x0c0a904eu; return 0; }
cond=r[17]&1u;
r[14]=r[5];
if(cond) { goto P_0c0a9088; }
goto P_0c0a9052;
P_0c0a9050: /* original 6e53, guest PC 0x0c0a9050 */
if(!s->budget--) { s->failed_pc=0x0c0a9050u; return 0; }
r[14]=r[5];
goto P_0c0a9052;
P_0c0a9052: /* original e040, guest PC 0x0c0a9052 */
if(!s->budget--) { s->failed_pc=0x0c0a9052u; return 0; }
r[0]=0x00000040u;
goto P_0c0a9054;
P_0c0a9054: /* original e100, guest PC 0x0c0a9054 */
if(!s->budget--) { s->failed_pc=0x0c0a9054u; return 0; }
r[1]=0x00000000u;
goto P_0c0a9056;
P_0c0a9056: /* original 0e15, guest PC 0x0c0a9056 */
if(!s->budget--) { s->failed_pc=0x0c0a9056u; return 0; }
write(ram,r[14]+r[0],r[1],2);
goto P_0c0a9058;
P_0c0a9058: /* original e301, guest PC 0x0c0a9058 */
if(!s->budget--) { s->failed_pc=0x0c0a9058u; return 0; }
r[3]=0x00000001u;
goto P_0c0a905a;
P_0c0a905a: /* original 900b, guest PC 0x0c0a905a */
if(!s->budget--) { s->failed_pc=0x0c0a905au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9074u,2);
goto P_0c0a905c;
P_0c0a905c: /* original 0cbd, guest PC 0x0c0a905c */
if(!s->budget--) { s->failed_pc=0x0c0a905cu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c0a905e;
P_0c0a905e: /* original 23c8, guest PC 0x0c0a905e */
if(!s->budget--) { s->failed_pc=0x0c0a905eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0a9060;
P_0c0a9060: /* original 8912, guest PC 0x0c0a9060 */
if(!s->budget--) { s->failed_pc=0x0c0a9060u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9088; }
goto P_0c0a9062;
P_0c0a9062: /* original 56f1, guest PC 0x0c0a9062 */
if(!s->budget--) { s->failed_pc=0x0c0a9062u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c0a9064;
P_0c0a9064: /* original 65e3, guest PC 0x0c0a9064 */
if(!s->budget--) { s->failed_pc=0x0c0a9064u; return 0; }
r[5]=r[14];
goto P_0c0a9066;
P_0c0a9066: /* original bf91, guest PC 0x0c0a9066 */
if(!s->budget--) { s->failed_pc=0x0c0a9066u; return 0; }
target=0x0c0a8f8cu; r[16]=0x0c0a906au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a906au) { target=s->pc; goto dispatch; }
goto P_0c0a906a;
P_0c0a9068: /* original 64d3, guest PC 0x0c0a9068 */
if(!s->budget--) { s->failed_pc=0x0c0a9068u; return 0; }
r[4]=r[13];
goto P_0c0a906a;
P_0c0a906a: /* original a0af, guest PC 0x0c0a906a */
if(!s->budget--) { s->failed_pc=0x0c0a906au; return 0; }
goto P_0c0a91cc;
P_0c0a906c: /* original 0009, guest PC 0x0c0a906c */
if(!s->budget--) { s->failed_pc=0x0c0a906cu; return 0; }
return vf3_matrix_family(0x0c0a906eu,s,ram);
P_0c0a9088: /* original e004, guest PC 0x0c0a9088 */
if(!s->budget--) { s->failed_pc=0x0c0a9088u; return 0; }
r[0]=0x00000004u;
goto P_0c0a908a;
P_0c0a908a: /* original 64d2, guest PC 0x0c0a908a */
if(!s->budget--) { s->failed_pc=0x0c0a908au; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a908c;
P_0c0a908c: /* original e3fe, guest PC 0x0c0a908c */
if(!s->budget--) { s->failed_pc=0x0c0a908cu; return 0; }
r[3]=0xfffffffeu;
goto P_0c0a908e;
P_0c0a908e: /* original 2439, guest PC 0x0c0a908e */
if(!s->budget--) { s->failed_pc=0x0c0a908eu; return 0; }
r[4]&=r[3];
goto P_0c0a9090;
P_0c0a9090: /* original 2e42, guest PC 0x0c0a9090 */
if(!s->budget--) { s->failed_pc=0x0c0a9090u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0a9092;
P_0c0a9092: /* original f5d6, guest PC 0x0c0a9092 */
if(!s->budget--) { s->failed_pc=0x0c0a9092u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c0a9094;
P_0c0a9094: /* original e008, guest PC 0x0c0a9094 */
if(!s->budget--) { s->failed_pc=0x0c0a9094u; return 0; }
r[0]=0x00000008u;
goto P_0c0a9096;
P_0c0a9096: /* original f6d6, guest PC 0x0c0a9096 */
if(!s->budget--) { s->failed_pc=0x0c0a9096u; return 0; }
vf3_matrix_load(s,ram,6,r[13]+r[0]);
goto P_0c0a9098;
P_0c0a9098: /* original e00c, guest PC 0x0c0a9098 */
if(!s->budget--) { s->failed_pc=0x0c0a9098u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a909a;
P_0c0a909a: /* original f4d6, guest PC 0x0c0a909a */
if(!s->budget--) { s->failed_pc=0x0c0a909au; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c0a909c;
P_0c0a909c: /* original e020, guest PC 0x0c0a909c */
if(!s->budget--) { s->failed_pc=0x0c0a909cu; return 0; }
r[0]=0x00000020u;
goto P_0c0a909e;
P_0c0a909e: /* original 00dd, guest PC 0x0c0a909e */
if(!s->budget--) { s->failed_pc=0x0c0a909eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a90a0;
P_0c0a90a0: /* original 81f4, guest PC 0x0c0a90a0 */
if(!s->budget--) { s->failed_pc=0x0c0a90a0u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c0a90a2;
P_0c0a90a2: /* original e024, guest PC 0x0c0a90a2 */
if(!s->budget--) { s->failed_pc=0x0c0a90a2u; return 0; }
r[0]=0x00000024u;
goto P_0c0a90a4;
P_0c0a90a4: /* original 04dd, guest PC 0x0c0a90a4 */
if(!s->budget--) { s->failed_pc=0x0c0a90a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a90a6;
P_0c0a90a6: /* original e038, guest PC 0x0c0a90a6 */
if(!s->budget--) { s->failed_pc=0x0c0a90a6u; return 0; }
r[0]=0x00000038u;
goto P_0c0a90a8;
P_0c0a90a8: /* original 52dc, guest PC 0x0c0a90a8 */
if(!s->budget--) { s->failed_pc=0x0c0a90a8u; return 0; }
r[2]=read(ram,r[13]+48,4);
goto P_0c0a90aa;
P_0c0a90aa: /* original 56db, guest PC 0x0c0a90aa */
if(!s->budget--) { s->failed_pc=0x0c0a90aau; return 0; }
r[6]=read(ram,r[13]+44,4);
goto P_0c0a90ac;
P_0c0a90ac: /* original 55d4, guest PC 0x0c0a90ac */
if(!s->budget--) { s->failed_pc=0x0c0a90acu; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0a90ae;
P_0c0a90ae: /* original 57d7, guest PC 0x0c0a90ae */
if(!s->budget--) { s->failed_pc=0x0c0a90aeu; return 0; }
r[7]=read(ram,r[13]+28,4);
goto P_0c0a90b0;
P_0c0a90b0: /* original 2f22, guest PC 0x0c0a90b0 */
if(!s->budget--) { s->failed_pc=0x0c0a90b0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a90b2;
P_0c0a90b2: /* original 01dc, guest PC 0x0c0a90b2 */
if(!s->budget--) { s->failed_pc=0x0c0a90b2u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a90b4;
P_0c0a90b4: /* original e014, guest PC 0x0c0a90b4 */
if(!s->budget--) { s->failed_pc=0x0c0a90b4u; return 0; }
r[0]=0x00000014u;
goto P_0c0a90b6;
P_0c0a90b6: /* original 0f14, guest PC 0x0c0a90b6 */
if(!s->budget--) { s->failed_pc=0x0c0a90b6u; return 0; }
write(ram,r[15]+r[0],r[1],1);
goto P_0c0a90b8;
P_0c0a90b8: /* original e02a, guest PC 0x0c0a90b8 */
if(!s->budget--) { s->failed_pc=0x0c0a90b8u; return 0; }
r[0]=0x0000002au;
goto P_0c0a90ba;
P_0c0a90ba: /* original 00dd, guest PC 0x0c0a90ba */
if(!s->budget--) { s->failed_pc=0x0c0a90bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a90bc;
P_0c0a90bc: /* original 81f8, guest PC 0x0c0a90bc */
if(!s->budget--) { s->failed_pc=0x0c0a90bcu; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c0a90be;
P_0c0a90be: /* original e03a, guest PC 0x0c0a90be */
if(!s->budget--) { s->failed_pc=0x0c0a90beu; return 0; }
r[0]=0x0000003au;
goto P_0c0a90c0;
P_0c0a90c0: /* original 00dc, guest PC 0x0c0a90c0 */
if(!s->budget--) { s->failed_pc=0x0c0a90c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a90c2;
P_0c0a90c2: /* original 80fc, guest PC 0x0c0a90c2 */
if(!s->budget--) { s->failed_pc=0x0c0a90c2u; return 0; }
write(ram,r[15]+12,r[0],1);
goto P_0c0a90c4;
P_0c0a90c4: /* original e010, guest PC 0x0c0a90c4 */
if(!s->budget--) { s->failed_pc=0x0c0a90c4u; return 0; }
r[0]=0x00000010u;
goto P_0c0a90c6;
P_0c0a90c6: /* original fe57, guest PC 0x0c0a90c6 */
if(!s->budget--) { s->failed_pc=0x0c0a90c6u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a90c8;
P_0c0a90c8: /* original e014, guest PC 0x0c0a90c8 */
if(!s->budget--) { s->failed_pc=0x0c0a90c8u; return 0; }
r[0]=0x00000014u;
goto P_0c0a90ca;
P_0c0a90ca: /* original fe67, guest PC 0x0c0a90ca */
if(!s->budget--) { s->failed_pc=0x0c0a90cau; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c0a90cc;
P_0c0a90cc: /* original e018, guest PC 0x0c0a90cc */
if(!s->budget--) { s->failed_pc=0x0c0a90ccu; return 0; }
r[0]=0x00000018u;
goto P_0c0a90ce;
P_0c0a90ce: /* original fe47, guest PC 0x0c0a90ce */
if(!s->budget--) { s->failed_pc=0x0c0a90ceu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a90d0;
P_0c0a90d0: /* original 85f4, guest PC 0x0c0a90d0 */
if(!s->budget--) { s->failed_pc=0x0c0a90d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c0a90d2;
P_0c0a90d2: /* original 81ef, guest PC 0x0c0a90d2 */
if(!s->budget--) { s->failed_pc=0x0c0a90d2u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0a90d4;
P_0c0a90d4: /* original e03e, guest PC 0x0c0a90d4 */
if(!s->budget--) { s->failed_pc=0x0c0a90d4u; return 0; }
r[0]=0x0000003eu;
goto P_0c0a90d6;
P_0c0a90d6: /* original 0e45, guest PC 0x0c0a90d6 */
if(!s->budget--) { s->failed_pc=0x0c0a90d6u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a90d8;
P_0c0a90d8: /* original 9060, guest PC 0x0c0a90d8 */
if(!s->budget--) { s->failed_pc=0x0c0a90d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a919cu,2);
goto P_0c0a90da;
P_0c0a90da: /* original 0e46, guest PC 0x0c0a90da */
if(!s->budget--) { s->failed_pc=0x0c0a90dau; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0a90dc;
P_0c0a90dc: /* original e048, guest PC 0x0c0a90dc */
if(!s->budget--) { s->failed_pc=0x0c0a90dcu; return 0; }
r[0]=0x00000048u;
goto P_0c0a90de;
P_0c0a90de: /* original 0e56, guest PC 0x0c0a90de */
if(!s->budget--) { s->failed_pc=0x0c0a90deu; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c0a90e0;
P_0c0a90e0: /* original 905d, guest PC 0x0c0a90e0 */
if(!s->budget--) { s->failed_pc=0x0c0a90e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a919eu,2);
goto P_0c0a90e2;
P_0c0a90e2: /* original 0e66, guest PC 0x0c0a90e2 */
if(!s->budget--) { s->failed_pc=0x0c0a90e2u; return 0; }
write(ram,r[14]+r[0],r[6],4);
goto P_0c0a90e4;
P_0c0a90e4: /* original 905c, guest PC 0x0c0a90e4 */
if(!s->budget--) { s->failed_pc=0x0c0a90e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91a0u,2);
goto P_0c0a90e6;
P_0c0a90e6: /* original 0e76, guest PC 0x0c0a90e6 */
if(!s->budget--) { s->failed_pc=0x0c0a90e6u; return 0; }
write(ram,r[14]+r[0],r[7],4);
goto P_0c0a90e8;
P_0c0a90e8: /* original 905b, guest PC 0x0c0a90e8 */
if(!s->budget--) { s->failed_pc=0x0c0a90e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91a2u,2);
goto P_0c0a90ea;
P_0c0a90ea: /* original 62f2, guest PC 0x0c0a90ea */
if(!s->budget--) { s->failed_pc=0x0c0a90eau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a90ec;
P_0c0a90ec: /* original 0e26, guest PC 0x0c0a90ec */
if(!s->budget--) { s->failed_pc=0x0c0a90ecu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0a90ee;
P_0c0a90ee: /* original e014, guest PC 0x0c0a90ee */
if(!s->budget--) { s->failed_pc=0x0c0a90eeu; return 0; }
r[0]=0x00000014u;
goto P_0c0a90f0;
P_0c0a90f0: /* original 01fc, guest PC 0x0c0a90f0 */
if(!s->budget--) { s->failed_pc=0x0c0a90f0u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c0a90f2;
P_0c0a90f2: /* original e246, guest PC 0x0c0a90f2 */
if(!s->budget--) { s->failed_pc=0x0c0a90f2u; return 0; }
r[2]=0x00000046u;
goto P_0c0a90f4;
P_0c0a90f4: /* original 9056, guest PC 0x0c0a90f4 */
if(!s->budget--) { s->failed_pc=0x0c0a90f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91a4u,2);
goto P_0c0a90f6;
P_0c0a90f6: /* original 32ec, guest PC 0x0c0a90f6 */
if(!s->budget--) { s->failed_pc=0x0c0a90f6u; return 0; }
r[2]+=r[14];
goto P_0c0a90f8;
P_0c0a90f8: /* original 0e14, guest PC 0x0c0a90f8 */
if(!s->budget--) { s->failed_pc=0x0c0a90f8u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c0a90fa;
P_0c0a90fa: /* original 85f8, guest PC 0x0c0a90fa */
if(!s->budget--) { s->failed_pc=0x0c0a90fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c0a90fc;
P_0c0a90fc: /* original 2201, guest PC 0x0c0a90fc */
if(!s->budget--) { s->failed_pc=0x0c0a90fcu; return 0; }
write(ram,r[2],r[0],2);
goto P_0c0a90fe;
P_0c0a90fe: /* original 9152, guest PC 0x0c0a90fe */
if(!s->budget--) { s->failed_pc=0x0c0a90feu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91a6u,2);
goto P_0c0a9100;
P_0c0a9100: /* original 84fc, guest PC 0x0c0a9100 */
if(!s->budget--) { s->failed_pc=0x0c0a9100u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+12,1);
goto P_0c0a9102;
P_0c0a9102: /* original 31bc, guest PC 0x0c0a9102 */
if(!s->budget--) { s->failed_pc=0x0c0a9102u; return 0; }
r[1]+=r[11];
goto P_0c0a9104;
P_0c0a9104: /* original 2100, guest PC 0x0c0a9104 */
if(!s->budget--) { s->failed_pc=0x0c0a9104u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0a9106;
P_0c0a9106: /* original e061, guest PC 0x0c0a9106 */
if(!s->budget--) { s->failed_pc=0x0c0a9106u; return 0; }
r[0]=0x00000061u;
goto P_0c0a9108;
P_0c0a9108: /* original 04ec, guest PC 0x0c0a9108 */
if(!s->budget--) { s->failed_pc=0x0c0a9108u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a910a;
P_0c0a910a: /* original 604e, guest PC 0x0c0a910a */
if(!s->budget--) { s->failed_pc=0x0c0a910au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0a910c;
P_0c0a910c: /* original 8808, guest PC 0x0c0a910c */
if(!s->budget--) { s->failed_pc=0x0c0a910cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0a910e;
P_0c0a910e: /* original 8b03, guest PC 0x0c0a910e */
if(!s->budget--) { s->failed_pc=0x0c0a910eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9118; }
goto P_0c0a9110;
P_0c0a9110: /* original e039, guest PC 0x0c0a9110 */
if(!s->budget--) { s->failed_pc=0x0c0a9110u; return 0; }
r[0]=0x00000039u;
goto P_0c0a9112;
P_0c0a9112: /* original 04dc, guest PC 0x0c0a9112 */
if(!s->budget--) { s->failed_pc=0x0c0a9112u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0a9114;
P_0c0a9114: /* original 9048, guest PC 0x0c0a9114 */
if(!s->budget--) { s->failed_pc=0x0c0a9114u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91a8u,2);
goto P_0c0a9116;
P_0c0a9116: /* original 0e44, guest PC 0x0c0a9116 */
if(!s->budget--) { s->failed_pc=0x0c0a9116u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a9118;
P_0c0a9118: /* original 54d5, guest PC 0x0c0a9118 */
if(!s->budget--) { s->failed_pc=0x0c0a9118u; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c0a911a;
P_0c0a911a: /* original 2448, guest PC 0x0c0a911a */
if(!s->budget--) { s->failed_pc=0x0c0a911au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a911c;
P_0c0a911c: /* original 8902, guest PC 0x0c0a911c */
if(!s->budget--) { s->failed_pc=0x0c0a911cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9124; }
goto P_0c0a911e;
P_0c0a911e: /* original d224, guest PC 0x0c0a911e */
if(!s->budget--) { s->failed_pc=0x0c0a911eu; return 0; }
r[2]=read(ram,0x0c0a91b0u,4);
goto P_0c0a9120;
P_0c0a9120: /* original 420b, guest PC 0x0c0a9120 */
if(!s->budget--) { s->failed_pc=0x0c0a9120u; return 0; }
target=r[2];
r[16]=0x0c0a9124u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a9124u) { target=s->pc; goto dispatch; }
goto P_0c0a9124;
P_0c0a9122: /* original 0009, guest PC 0x0c0a9122 */
if(!s->budget--) { s->failed_pc=0x0c0a9122u; return 0; }
goto P_0c0a9124;
P_0c0a9124: /* original 54d6, guest PC 0x0c0a9124 */
if(!s->budget--) { s->failed_pc=0x0c0a9124u; return 0; }
r[4]=read(ram,r[13]+24,4);
goto P_0c0a9126;
P_0c0a9126: /* original 2448, guest PC 0x0c0a9126 */
if(!s->budget--) { s->failed_pc=0x0c0a9126u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a9128;
P_0c0a9128: /* original 8902, guest PC 0x0c0a9128 */
if(!s->budget--) { s->failed_pc=0x0c0a9128u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9130; }
goto P_0c0a912a;
P_0c0a912a: /* original d221, guest PC 0x0c0a912a */
if(!s->budget--) { s->failed_pc=0x0c0a912au; return 0; }
r[2]=read(ram,0x0c0a91b0u,4);
goto P_0c0a912c;
P_0c0a912c: /* original 420b, guest PC 0x0c0a912c */
if(!s->budget--) { s->failed_pc=0x0c0a912cu; return 0; }
target=r[2];
r[16]=0x0c0a9130u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a9130u) { target=s->pc; goto dispatch; }
goto P_0c0a9130;
P_0c0a912e: /* original 0009, guest PC 0x0c0a912e */
if(!s->budget--) { s->failed_pc=0x0c0a912eu; return 0; }
goto P_0c0a9130;
P_0c0a9130: /* original e03c, guest PC 0x0c0a9130 */
if(!s->budget--) { s->failed_pc=0x0c0a9130u; return 0; }
r[0]=0x0000003cu;
goto P_0c0a9132;
P_0c0a9132: /* original 06ed, guest PC 0x0c0a9132 */
if(!s->budget--) { s->failed_pc=0x0c0a9132u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9134;
P_0c0a9134: /* original e022, guest PC 0x0c0a9134 */
if(!s->budget--) { s->failed_pc=0x0c0a9134u; return 0; }
r[0]=0x00000022u;
goto P_0c0a9136;
P_0c0a9136: /* original 04dd, guest PC 0x0c0a9136 */
if(!s->budget--) { s->failed_pc=0x0c0a9136u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a9138;
P_0c0a9138: /* original e03c, guest PC 0x0c0a9138 */
if(!s->budget--) { s->failed_pc=0x0c0a9138u; return 0; }
r[0]=0x0000003cu;
goto P_0c0a913a;
P_0c0a913a: /* original 654f, guest PC 0x0c0a913a */
if(!s->budget--) { s->failed_pc=0x0c0a913au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0a913c;
P_0c0a913c: /* original 2558, guest PC 0x0c0a913c */
if(!s->budget--) { s->failed_pc=0x0c0a913cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0a913e;
P_0c0a913e: /* original 8d45, guest PC 0x0c0a913e */
if(!s->budget--) { s->failed_pc=0x0c0a913eu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],2);
if(cond) { goto P_0c0a91cc; }
goto P_0c0a9142;
P_0c0a9140: /* original 0e45, guest PC 0x0c0a9140 */
if(!s->budget--) { s->failed_pc=0x0c0a9140u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9142;
P_0c0a9142: /* original 666f, guest PC 0x0c0a9142 */
if(!s->budget--) { s->failed_pc=0x0c0a9142u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c0a9144;
P_0c0a9144: /* original 3560, guest PC 0x0c0a9144 */
if(!s->budget--) { s->failed_pc=0x0c0a9144u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c0a9146;
P_0c0a9146: /* original 8b19, guest PC 0x0c0a9146 */
if(!s->budget--) { s->failed_pc=0x0c0a9146u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a917c; }
goto P_0c0a9148;
P_0c0a9148: /* original 902f, guest PC 0x0c0a9148 */
if(!s->budget--) { s->failed_pc=0x0c0a9148u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91aau,2);
goto P_0c0a914a;
P_0c0a914a: /* original 7cfd, guest PC 0x0c0a914a */
if(!s->budget--) { s->failed_pc=0x0c0a914au; return 0; }
r[12]+=0xfffffffdu;
goto P_0c0a914c;
P_0c0a914c: /* original 63c3, guest PC 0x0c0a914c */
if(!s->budget--) { s->failed_pc=0x0c0a914cu; return 0; }
r[3]=r[12];
goto P_0c0a914e;
P_0c0a914e: /* original e503, guest PC 0x0c0a914e */
if(!s->budget--) { s->failed_pc=0x0c0a914eu; return 0; }
r[5]=0x00000003u;
goto P_0c0a9150;
P_0c0a9150: /* original 04bc, guest PC 0x0c0a9150 */
if(!s->budget--) { s->failed_pc=0x0c0a9150u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0a9152;
P_0c0a9152: /* original 3353, guest PC 0x0c0a9152 */
if(!s->budget--) { s->failed_pc=0x0c0a9152u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[5])!=0);
goto P_0c0a9154;
P_0c0a9154: /* original 8d03, guest PC 0x0c0a9154 */
if(!s->budget--) { s->failed_pc=0x0c0a9154u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[12],4);
if(cond) { goto P_0c0a915e; }
goto P_0c0a9158;
P_0c0a9156: /* original 2fc2, guest PC 0x0c0a9156 */
if(!s->budget--) { s->failed_pc=0x0c0a9156u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c0a9158;
P_0c0a9158: /* original 9027, guest PC 0x0c0a9158 */
if(!s->budget--) { s->failed_pc=0x0c0a9158u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91aau,2);
goto P_0c0a915a;
P_0c0a915a: /* original 7401, guest PC 0x0c0a915a */
if(!s->budget--) { s->failed_pc=0x0c0a915au; return 0; }
r[4]+=0x00000001u;
goto P_0c0a915c;
P_0c0a915c: /* original 0b44, guest PC 0x0c0a915c */
if(!s->budget--) { s->failed_pc=0x0c0a915cu; return 0; }
write(ram,r[11]+r[0],r[4],1);
goto P_0c0a915e;
P_0c0a915e: /* original 63f2, guest PC 0x0c0a915e */
if(!s->budget--) { s->failed_pc=0x0c0a915eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a9160;
P_0c0a9160: /* original 3353, guest PC 0x0c0a9160 */
if(!s->budget--) { s->failed_pc=0x0c0a9160u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[5])!=0);
goto P_0c0a9162;
P_0c0a9162: /* original 8903, guest PC 0x0c0a9162 */
if(!s->budget--) { s->failed_pc=0x0c0a9162u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a916c; }
goto P_0c0a9164;
P_0c0a9164: /* original 9022, guest PC 0x0c0a9164 */
if(!s->budget--) { s->failed_pc=0x0c0a9164u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a91acu,2);
goto P_0c0a9166;
P_0c0a9166: /* original e101, guest PC 0x0c0a9166 */
if(!s->budget--) { s->failed_pc=0x0c0a9166u; return 0; }
r[1]=0x00000001u;
goto P_0c0a9168;
P_0c0a9168: /* original a008, guest PC 0x0c0a9168 */
if(!s->budget--) { s->failed_pc=0x0c0a9168u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c0a917c;
P_0c0a916a: /* original 0e14, guest PC 0x0c0a916a */
if(!s->budget--) { s->failed_pc=0x0c0a916au; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c0a916c;
P_0c0a916c: /* original e03e, guest PC 0x0c0a916c */
if(!s->budget--) { s->failed_pc=0x0c0a916cu; return 0; }
r[0]=0x0000003eu;
goto P_0c0a916e;
P_0c0a916e: /* original 04ed, guest PC 0x0c0a916e */
if(!s->budget--) { s->failed_pc=0x0c0a916eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9170;
P_0c0a9170: /* original 604d, guest PC 0x0c0a9170 */
if(!s->budget--) { s->failed_pc=0x0c0a9170u; return 0; }
r[0]=r[4]&65535u;
goto P_0c0a9172;
P_0c0a9172: /* original 8801, guest PC 0x0c0a9172 */
if(!s->budget--) { s->failed_pc=0x0c0a9172u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a9174;
P_0c0a9174: /* original 8d0d, guest PC 0x0c0a9174 */
if(!s->budget--) { s->failed_pc=0x0c0a9174u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0a9192; }
goto P_0c0a9178;
P_0c0a9176: /* original 6403, guest PC 0x0c0a9176 */
if(!s->budget--) { s->failed_pc=0x0c0a9176u; return 0; }
r[4]=r[0];
goto P_0c0a9178;
P_0c0a9178: /* original a022, guest PC 0x0c0a9178 */
if(!s->budget--) { s->failed_pc=0x0c0a9178u; return 0; }
goto P_0c0a91c0;
P_0c0a917a: /* original 0009, guest PC 0x0c0a917a */
if(!s->budget--) { s->failed_pc=0x0c0a917au; return 0; }
goto P_0c0a917c;
P_0c0a917c: /* original e03c, guest PC 0x0c0a917c */
if(!s->budget--) { s->failed_pc=0x0c0a917cu; return 0; }
r[0]=0x0000003cu;
goto P_0c0a917e;
P_0c0a917e: /* original 02ed, guest PC 0x0c0a917e */
if(!s->budget--) { s->failed_pc=0x0c0a917eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9180;
P_0c0a9180: /* original 2f21, guest PC 0x0c0a9180 */
if(!s->budget--) { s->failed_pc=0x0c0a9180u; return 0; }
write(ram,r[15],r[2],2);
goto P_0c0a9182;
P_0c0a9182: /* original 55f1, guest PC 0x0c0a9182 */
if(!s->budget--) { s->failed_pc=0x0c0a9182u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0a9184;
P_0c0a9184: /* original 66f1, guest PC 0x0c0a9184 */
if(!s->budget--) { s->failed_pc=0x0c0a9184u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[6]=tmp;
goto P_0c0a9186;
P_0c0a9186: /* original d30b, guest PC 0x0c0a9186 */
if(!s->budget--) { s->failed_pc=0x0c0a9186u; return 0; }
r[3]=read(ram,0x0c0a91b4u,4);
goto P_0c0a9188;
P_0c0a9188: /* original 430b, guest PC 0x0c0a9188 */
if(!s->budget--) { s->failed_pc=0x0c0a9188u; return 0; }
target=r[3];
r[16]=0x0c0a918cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a918cu) { target=s->pc; goto dispatch; }
goto P_0c0a918c;
P_0c0a918a: /* original 64e3, guest PC 0x0c0a918a */
if(!s->budget--) { s->failed_pc=0x0c0a918au; return 0; }
r[4]=r[14];
goto P_0c0a918c;
P_0c0a918c: /* original d20a, guest PC 0x0c0a918c */
if(!s->budget--) { s->failed_pc=0x0c0a918cu; return 0; }
r[2]=read(ram,0x0c0a91b8u,4);
goto P_0c0a918e;
P_0c0a918e: /* original 420b, guest PC 0x0c0a918e */
if(!s->budget--) { s->failed_pc=0x0c0a918eu; return 0; }
target=r[2];
r[16]=0x0c0a9192u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a9192u) { target=s->pc; goto dispatch; }
goto P_0c0a9192;
P_0c0a9190: /* original 64e3, guest PC 0x0c0a9190 */
if(!s->budget--) { s->failed_pc=0x0c0a9190u; return 0; }
r[4]=r[14];
goto P_0c0a9192;
P_0c0a9192: /* original d30a, guest PC 0x0c0a9192 */
if(!s->budget--) { s->failed_pc=0x0c0a9192u; return 0; }
r[3]=read(ram,0x0c0a91bcu,4);
goto P_0c0a9194;
P_0c0a9194: /* original 430b, guest PC 0x0c0a9194 */
if(!s->budget--) { s->failed_pc=0x0c0a9194u; return 0; }
target=r[3];
r[16]=0x0c0a9198u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a9198u) { target=s->pc; goto dispatch; }
goto P_0c0a9198;
P_0c0a9196: /* original 64e3, guest PC 0x0c0a9196 */
if(!s->budget--) { s->failed_pc=0x0c0a9196u; return 0; }
r[4]=r[14];
goto P_0c0a9198;
P_0c0a9198: /* original a015, guest PC 0x0c0a9198 */
if(!s->budget--) { s->failed_pc=0x0c0a9198u; return 0; }
goto P_0c0a91c6;
P_0c0a919a: /* original 0009, guest PC 0x0c0a919a */
if(!s->budget--) { s->failed_pc=0x0c0a919au; return 0; }
return vf3_matrix_family(0x0c0a919cu,s,ram);
P_0c0a91c0: /* original d335, guest PC 0x0c0a91c0 */
if(!s->budget--) { s->failed_pc=0x0c0a91c0u; return 0; }
r[3]=read(ram,0x0c0a9298u,4);
goto P_0c0a91c2;
P_0c0a91c2: /* original 430b, guest PC 0x0c0a91c2 */
if(!s->budget--) { s->failed_pc=0x0c0a91c2u; return 0; }
target=r[3];
r[16]=0x0c0a91c6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a91c6u) { target=s->pc; goto dispatch; }
goto P_0c0a91c6;
P_0c0a91c4: /* original 64e3, guest PC 0x0c0a91c4 */
if(!s->budget--) { s->failed_pc=0x0c0a91c4u; return 0; }
r[4]=r[14];
goto P_0c0a91c6;
P_0c0a91c6: /* original d235, guest PC 0x0c0a91c6 */
if(!s->budget--) { s->failed_pc=0x0c0a91c6u; return 0; }
r[2]=read(ram,0x0c0a929cu,4);
goto P_0c0a91c8;
P_0c0a91c8: /* original 420b, guest PC 0x0c0a91c8 */
if(!s->budget--) { s->failed_pc=0x0c0a91c8u; return 0; }
target=r[2];
r[16]=0x0c0a91ccu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a91ccu) { target=s->pc; goto dispatch; }
goto P_0c0a91cc;
P_0c0a91ca: /* original 64e3, guest PC 0x0c0a91ca */
if(!s->budget--) { s->failed_pc=0x0c0a91cau; return 0; }
r[4]=r[14];
goto P_0c0a91cc;
P_0c0a91cc: /* original 7f18, guest PC 0x0c0a91cc */
if(!s->budget--) { s->failed_pc=0x0c0a91ccu; return 0; }
r[15]+=0x00000018u;
goto P_0c0a91ce;
P_0c0a91ce: /* original 4f26, guest PC 0x0c0a91ce */
if(!s->budget--) { s->failed_pc=0x0c0a91ceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a91d0;
P_0c0a91d0: /* original 6bf6, guest PC 0x0c0a91d0 */
if(!s->budget--) { s->failed_pc=0x0c0a91d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a91d2;
P_0c0a91d2: /* original 6cf6, guest PC 0x0c0a91d2 */
if(!s->budget--) { s->failed_pc=0x0c0a91d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a91d4;
P_0c0a91d4: /* original 6df6, guest PC 0x0c0a91d4 */
if(!s->budget--) { s->failed_pc=0x0c0a91d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a91d6;
P_0c0a91d6: /* original 000b, guest PC 0x0c0a91d6 */
if(!s->budget--) { s->failed_pc=0x0c0a91d6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a91d8: /* original 6ef6, guest PC 0x0c0a91d8 */
if(!s->budget--) { s->failed_pc=0x0c0a91d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a91dau,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c091afeu,0x0c091b00u,0x0c091b02u,0x0c091b04u,0x0c091b06u,0x0c091b08u,0x0c091b0au,0x0c091b0cu,0x0c091b0eu,0x0c091b10u,0x0c091b12u,0x0c091b14u,0x0c091b16u,0x0c091b18u,0x0c091b1au,0x0c091b1cu,
0x0c091b1eu,0x0c091b20u,0x0c091b22u,0x0c091b24u,0x0c091b26u,0x0c091b28u,0x0c091b2au,0x0c091b2cu,0x0c091b2eu,0x0c091b30u,0x0c091b32u,0x0c091b34u,0x0c091b36u,0x0c091b38u,0x0c091b3au,0x0c091b3cu,
0x0c091b3eu,0x0c091b40u,0x0c091b42u,0x0c091b44u,0x0c0a8582u,0x0c0a8584u,0x0c0a8586u,0x0c0a8588u,0x0c0a858au,0x0c0a858cu,0x0c0a858eu,0x0c0a8590u,0x0c0a8592u,0x0c0a8594u,0x0c0a8596u,0x0c0a8598u,
0x0c0a859au,0x0c0a859cu,0x0c0a859eu,0x0c0a85a0u,0x0c0a85a2u,0x0c0a85a4u,0x0c0a85a6u,0x0c0a85a8u,0x0c0a85aau,0x0c0a85acu,0x0c0a85aeu,0x0c0a85b0u,0x0c0a85b2u,0x0c0a85b4u,0x0c0a85b6u,0x0c0a85b8u,
0x0c0a85bau,0x0c0a85bcu,0x0c0a85beu,0x0c0a85c0u,0x0c0a85c2u,0x0c0a85c4u,0x0c0a85c6u,0x0c0a85c8u,0x0c0a85cau,0x0c0a85ccu,0x0c0a85ceu,0x0c0a85d0u,0x0c0a85d2u,0x0c0a85d4u,0x0c0a85d6u,0x0c0a85d8u,
0x0c0a85dau,0x0c0a85dcu,0x0c0a85deu,0x0c0a85e0u,0x0c0a85e2u,0x0c0a85e4u,0x0c0a85e6u,0x0c0a85e8u,0x0c0a85eau,0x0c0a85ecu,0x0c0a85eeu,0x0c0a85f0u,0x0c0a85f2u,0x0c0a85f4u,0x0c0a85f6u,0x0c0a85f8u,
0x0c0a85fau,0x0c0a85fcu,0x0c0a85feu,0x0c0a8600u,0x0c0a8602u,0x0c0a8604u,0x0c0a8606u,0x0c0a8608u,0x0c0a860au,0x0c0a860cu,0x0c0a860eu,0x0c0a8610u,0x0c0a8612u,0x0c0a8614u,0x0c0a8616u,0x0c0a8618u,
0x0c0a861au,0x0c0a861cu,0x0c0a861eu,0x0c0a8620u,0x0c0a8622u,0x0c0a8624u,0x0c0a8626u,0x0c0a8628u,0x0c0a862au,0x0c0a862cu,0x0c0a862eu,0x0c0a8630u,0x0c0a8632u,0x0c0a8634u,0x0c0a8636u,0x0c0a8638u,
0x0c0a863au,0x0c0a863cu,0x0c0a863eu,0x0c0a8640u,0x0c0a8642u,0x0c0a8644u,0x0c0a8646u,0x0c0a8648u,0x0c0a864au,0x0c0a864cu,0x0c0a864eu,0x0c0a8650u,0x0c0a8652u,0x0c0a8654u,0x0c0a8656u,0x0c0a8658u,
0x0c0a865au,0x0c0a865cu,0x0c0a865eu,0x0c0a8660u,0x0c0a8662u,0x0c0a8664u,0x0c0a8666u,0x0c0a8668u,0x0c0a866au,0x0c0a866cu,0x0c0a866eu,0x0c0a8670u,0x0c0a8672u,0x0c0a8674u,0x0c0a8676u,0x0c0a8678u,
0x0c0a867au,0x0c0a867cu,0x0c0a867eu,0x0c0a86acu,0x0c0a86aeu,0x0c0a86b0u,0x0c0a86b2u,0x0c0a86b4u,0x0c0a86b6u,0x0c0a86b8u,0x0c0a86bau,0x0c0a86bcu,0x0c0a86beu,0x0c0a86c0u,0x0c0a86c2u,0x0c0a86c4u,
0x0c0a86c6u,0x0c0a86c8u,0x0c0a86cau,0x0c0a86ccu,0x0c0a86ceu,0x0c0a86d0u,0x0c0a86d2u,0x0c0a86d4u,0x0c0a86d6u,0x0c0a86d8u,0x0c0a86dau,0x0c0a86dcu,0x0c0a86deu,0x0c0a86e0u,0x0c0a86e2u,0x0c0a86e4u,
0x0c0a86e6u,0x0c0a86e8u,0x0c0a86eau,0x0c0a86ecu,0x0c0a86eeu,0x0c0a86f0u,0x0c0a86f2u,0x0c0a86f4u,0x0c0a86f6u,0x0c0a86f8u,0x0c0a86fau,0x0c0a86fcu,0x0c0a86feu,0x0c0a8700u,0x0c0a8702u,0x0c0a8704u,
0x0c0a8706u,0x0c0a8708u,0x0c0a870au,0x0c0a870cu,0x0c0a870eu,0x0c0a8710u,0x0c0a8712u,0x0c0a8714u,0x0c0a8716u,0x0c0a8718u,0x0c0a871au,0x0c0a871cu,0x0c0a871eu,0x0c0a8720u,0x0c0a8722u,0x0c0a8724u,
0x0c0a8726u,0x0c0a8728u,0x0c0a872au,0x0c0a872cu,0x0c0a872eu,0x0c0a8730u,0x0c0a8732u,0x0c0a8734u,0x0c0a8736u,0x0c0a8738u,0x0c0a873au,0x0c0a873cu,0x0c0a873eu,0x0c0a8740u,0x0c0a8742u,0x0c0a8744u,
0x0c0a8746u,0x0c0a8748u,0x0c0a874au,0x0c0a874cu,0x0c0a874eu,0x0c0a8750u,0x0c0a8752u,0x0c0a8754u,0x0c0a8756u,0x0c0a8758u,0x0c0a875au,0x0c0a875cu,0x0c0a875eu,0x0c0a8760u,0x0c0a8762u,0x0c0a8764u,
0x0c0a8766u,0x0c0a8768u,0x0c0a876au,0x0c0a876cu,0x0c0a876eu,0x0c0a8770u,0x0c0a8772u,0x0c0a8774u,0x0c0a8776u,0x0c0a8778u,0x0c0a877au,0x0c0a877cu,0x0c0a877eu,0x0c0a8780u,0x0c0a8782u,0x0c0a8794u,
0x0c0a8796u,0x0c0a8798u,0x0c0a879au,0x0c0a879cu,0x0c0a879eu,0x0c0a87a0u,0x0c0a87a2u,0x0c0a87a4u,0x0c0a87a6u,0x0c0a87a8u,0x0c0a8f10u,0x0c0a8f12u,0x0c0a8f14u,0x0c0a8f16u,0x0c0a8f18u,0x0c0a8f1au,
0x0c0a8f1cu,0x0c0a8f1eu,0x0c0a8f20u,0x0c0a8f22u,0x0c0a8f24u,0x0c0a8f26u,0x0c0a8f28u,0x0c0a8f2au,0x0c0a8f2cu,0x0c0a8f2eu,0x0c0a8f30u,0x0c0a8f32u,0x0c0a8f34u,0x0c0a8f36u,0x0c0a8f38u,0x0c0a8f3au,
0x0c0a8f3cu,0x0c0a8f3eu,0x0c0a8f40u,0x0c0a8f42u,0x0c0a8f44u,0x0c0a8f46u,0x0c0a8f48u,0x0c0a8f4au,0x0c0a8f8cu,0x0c0a8f8eu,0x0c0a8f90u,0x0c0a8f92u,0x0c0a8f94u,0x0c0a8f96u,0x0c0a8f98u,0x0c0a8f9au,
0x0c0a8f9cu,0x0c0a8f9eu,0x0c0a8fa0u,0x0c0a8fa2u,0x0c0a8fa4u,0x0c0a8fa6u,0x0c0a8fa8u,0x0c0a8faau,0x0c0a8facu,0x0c0a8faeu,0x0c0a8fb0u,0x0c0a8fb2u,0x0c0a8fb4u,0x0c0a8fb6u,0x0c0a8fb8u,0x0c0a8fbau,
0x0c0a8fbcu,0x0c0a8fbeu,0x0c0a8fc0u,0x0c0a8fc2u,0x0c0a8fc4u,0x0c0a8fc6u,0x0c0a8fc8u,0x0c0a8fcau,0x0c0a8fccu,0x0c0a8fceu,0x0c0a8fd0u,0x0c0a8fd2u,0x0c0a8fd4u,0x0c0a8fd6u,0x0c0a8fd8u,0x0c0a8fdau,
0x0c0a8fdcu,0x0c0a8fdeu,0x0c0a8fe0u,0x0c0a8fe2u,0x0c0a8fe4u,0x0c0a8fe6u,0x0c0a8fe8u,0x0c0a8feau,0x0c0a8fecu,0x0c0a8feeu,0x0c0a8ff0u,0x0c0a8ff2u,0x0c0a8ff4u,0x0c0a8ff6u,0x0c0a8ff8u,0x0c0a8ffau,
0x0c0a8ffcu,0x0c0a8ffeu,0x0c0a9000u,0x0c0a9002u,0x0c0a9004u,0x0c0a9006u,0x0c0a9008u,0x0c0a900au,0x0c0a900cu,0x0c0a900eu,0x0c0a9010u,0x0c0a9012u,0x0c0a9014u,0x0c0a9016u,0x0c0a9018u,0x0c0a901au,
0x0c0a901cu,0x0c0a901eu,0x0c0a9020u,0x0c0a9022u,0x0c0a9024u,0x0c0a9026u,0x0c0a9028u,0x0c0a902au,0x0c0a902cu,0x0c0a902eu,0x0c0a9030u,0x0c0a9032u,0x0c0a9034u,0x0c0a9036u,0x0c0a9038u,0x0c0a903au,
0x0c0a903cu,0x0c0a903eu,0x0c0a9040u,0x0c0a9042u,0x0c0a9044u,0x0c0a9046u,0x0c0a9048u,0x0c0a904au,0x0c0a904cu,0x0c0a904eu,0x0c0a9050u,0x0c0a9052u,0x0c0a9054u,0x0c0a9056u,0x0c0a9058u,0x0c0a905au,
0x0c0a905cu,0x0c0a905eu,0x0c0a9060u,0x0c0a9062u,0x0c0a9064u,0x0c0a9066u,0x0c0a9068u,0x0c0a906au,0x0c0a906cu,0x0c0a9088u,0x0c0a908au,0x0c0a908cu,0x0c0a908eu,0x0c0a9090u,0x0c0a9092u,0x0c0a9094u,
0x0c0a9096u,0x0c0a9098u,0x0c0a909au,0x0c0a909cu,0x0c0a909eu,0x0c0a90a0u,0x0c0a90a2u,0x0c0a90a4u,0x0c0a90a6u,0x0c0a90a8u,0x0c0a90aau,0x0c0a90acu,0x0c0a90aeu,0x0c0a90b0u,0x0c0a90b2u,0x0c0a90b4u,
0x0c0a90b6u,0x0c0a90b8u,0x0c0a90bau,0x0c0a90bcu,0x0c0a90beu,0x0c0a90c0u,0x0c0a90c2u,0x0c0a90c4u,0x0c0a90c6u,0x0c0a90c8u,0x0c0a90cau,0x0c0a90ccu,0x0c0a90ceu,0x0c0a90d0u,0x0c0a90d2u,0x0c0a90d4u,
0x0c0a90d6u,0x0c0a90d8u,0x0c0a90dau,0x0c0a90dcu,0x0c0a90deu,0x0c0a90e0u,0x0c0a90e2u,0x0c0a90e4u,0x0c0a90e6u,0x0c0a90e8u,0x0c0a90eau,0x0c0a90ecu,0x0c0a90eeu,0x0c0a90f0u,0x0c0a90f2u,0x0c0a90f4u,
0x0c0a90f6u,0x0c0a90f8u,0x0c0a90fau,0x0c0a90fcu,0x0c0a90feu,0x0c0a9100u,0x0c0a9102u,0x0c0a9104u,0x0c0a9106u,0x0c0a9108u,0x0c0a910au,0x0c0a910cu,0x0c0a910eu,0x0c0a9110u,0x0c0a9112u,0x0c0a9114u,
0x0c0a9116u,0x0c0a9118u,0x0c0a911au,0x0c0a911cu,0x0c0a911eu,0x0c0a9120u,0x0c0a9122u,0x0c0a9124u,0x0c0a9126u,0x0c0a9128u,0x0c0a912au,0x0c0a912cu,0x0c0a912eu,0x0c0a9130u,0x0c0a9132u,0x0c0a9134u,
0x0c0a9136u,0x0c0a9138u,0x0c0a913au,0x0c0a913cu,0x0c0a913eu,0x0c0a9140u,0x0c0a9142u,0x0c0a9144u,0x0c0a9146u,0x0c0a9148u,0x0c0a914au,0x0c0a914cu,0x0c0a914eu,0x0c0a9150u,0x0c0a9152u,0x0c0a9154u,
0x0c0a9156u,0x0c0a9158u,0x0c0a915au,0x0c0a915cu,0x0c0a915eu,0x0c0a9160u,0x0c0a9162u,0x0c0a9164u,0x0c0a9166u,0x0c0a9168u,0x0c0a916au,0x0c0a916cu,0x0c0a916eu,0x0c0a9170u,0x0c0a9172u,0x0c0a9174u,
0x0c0a9176u,0x0c0a9178u,0x0c0a917au,0x0c0a917cu,0x0c0a917eu,0x0c0a9180u,0x0c0a9182u,0x0c0a9184u,0x0c0a9186u,0x0c0a9188u,0x0c0a918au,0x0c0a918cu,0x0c0a918eu,0x0c0a9190u,0x0c0a9192u,0x0c0a9194u,
0x0c0a9196u,0x0c0a9198u,0x0c0a919au,0x0c0a91c0u,0x0c0a91c2u,0x0c0a91c4u,0x0c0a91c6u,0x0c0a91c8u,0x0c0a91cau,0x0c0a91ccu,0x0c0a91ceu,0x0c0a91d0u,0x0c0a91d2u,0x0c0a91d4u,0x0c0a91d6u,0x0c0a91d8u,
};
int vf3_target_configuration_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
