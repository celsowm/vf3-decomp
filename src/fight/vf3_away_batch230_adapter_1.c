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
int vf3_away_batch230_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0b84feu: goto P_0c0b84fe;
case 0x0c0b8500u: goto P_0c0b8500;
case 0x0c0b8502u: goto P_0c0b8502;
case 0x0c0b8504u: goto P_0c0b8504;
case 0x0c0b8506u: goto P_0c0b8506;
case 0x0c0b8508u: goto P_0c0b8508;
case 0x0c0b850au: goto P_0c0b850a;
case 0x0c0b850cu: goto P_0c0b850c;
case 0x0c0b850eu: goto P_0c0b850e;
case 0x0c0b8510u: goto P_0c0b8510;
case 0x0c0b8512u: goto P_0c0b8512;
case 0x0c0b8514u: goto P_0c0b8514;
case 0x0c0b8516u: goto P_0c0b8516;
case 0x0c0b8518u: goto P_0c0b8518;
case 0x0c0b851au: goto P_0c0b851a;
case 0x0c0b851cu: goto P_0c0b851c;
case 0x0c0b851eu: goto P_0c0b851e;
case 0x0c0b8520u: goto P_0c0b8520;
case 0x0c0b8522u: goto P_0c0b8522;
case 0x0c0b8524u: goto P_0c0b8524;
case 0x0c0b8526u: goto P_0c0b8526;
case 0x0c0b8528u: goto P_0c0b8528;
case 0x0c0b852au: goto P_0c0b852a;
case 0x0c0b852cu: goto P_0c0b852c;
case 0x0c0b852eu: goto P_0c0b852e;
case 0x0c0b8530u: goto P_0c0b8530;
case 0x0c0b8532u: goto P_0c0b8532;
case 0x0c0b8534u: goto P_0c0b8534;
case 0x0c0b8536u: goto P_0c0b8536;
case 0x0c0b8538u: goto P_0c0b8538;
case 0x0c0b853au: goto P_0c0b853a;
case 0x0c0b853cu: goto P_0c0b853c;
case 0x0c0b853eu: goto P_0c0b853e;
case 0x0c0b8540u: goto P_0c0b8540;
case 0x0c0b8542u: goto P_0c0b8542;
case 0x0c0b8544u: goto P_0c0b8544;
case 0x0c0b8546u: goto P_0c0b8546;
case 0x0c0b8548u: goto P_0c0b8548;
case 0x0c0b854au: goto P_0c0b854a;
case 0x0c0b854cu: goto P_0c0b854c;
case 0x0c0b854eu: goto P_0c0b854e;
case 0x0c0b8550u: goto P_0c0b8550;
case 0x0c0b8552u: goto P_0c0b8552;
case 0x0c0b8554u: goto P_0c0b8554;
case 0x0c0b8556u: goto P_0c0b8556;
case 0x0c0b8558u: goto P_0c0b8558;
case 0x0c0b855au: goto P_0c0b855a;
case 0x0c0b855cu: goto P_0c0b855c;
case 0x0c0b855eu: goto P_0c0b855e;
case 0x0c0b8560u: goto P_0c0b8560;
case 0x0c0b8562u: goto P_0c0b8562;
case 0x0c0b8564u: goto P_0c0b8564;
case 0x0c0b8566u: goto P_0c0b8566;
case 0x0c0b8568u: goto P_0c0b8568;
case 0x0c0b856au: goto P_0c0b856a;
case 0x0c0b856cu: goto P_0c0b856c;
case 0x0c0b856eu: goto P_0c0b856e;
case 0x0c0b8570u: goto P_0c0b8570;
case 0x0c0b8572u: goto P_0c0b8572;
case 0x0c0b8574u: goto P_0c0b8574;
case 0x0c0b8576u: goto P_0c0b8576;
case 0x0c0b8578u: goto P_0c0b8578;
case 0x0c0b857au: goto P_0c0b857a;
case 0x0c0b857cu: goto P_0c0b857c;
case 0x0c0b857eu: goto P_0c0b857e;
case 0x0c0b8580u: goto P_0c0b8580;
case 0x0c0b8582u: goto P_0c0b8582;
case 0x0c0b8584u: goto P_0c0b8584;
case 0x0c0b8586u: goto P_0c0b8586;
case 0x0c0b8588u: goto P_0c0b8588;
case 0x0c0b858au: goto P_0c0b858a;
case 0x0c0b858cu: goto P_0c0b858c;
case 0x0c0b858eu: goto P_0c0b858e;
case 0x0c0b8590u: goto P_0c0b8590;
case 0x0c0b8592u: goto P_0c0b8592;
case 0x0c0b8594u: goto P_0c0b8594;
case 0x0c0b8596u: goto P_0c0b8596;
case 0x0c0b8598u: goto P_0c0b8598;
case 0x0c0b859au: goto P_0c0b859a;
case 0x0c0b859cu: goto P_0c0b859c;
case 0x0c0b859eu: goto P_0c0b859e;
case 0x0c0b85a0u: goto P_0c0b85a0;
case 0x0c0b85a2u: goto P_0c0b85a2;
case 0x0c0b85a4u: goto P_0c0b85a4;
case 0x0c0b85a6u: goto P_0c0b85a6;
case 0x0c0b85a8u: goto P_0c0b85a8;
case 0x0c0b85aau: goto P_0c0b85aa;
case 0x0c0b85acu: goto P_0c0b85ac;
case 0x0c0b85aeu: goto P_0c0b85ae;
case 0x0c0b85b0u: goto P_0c0b85b0;
case 0x0c0b85b2u: goto P_0c0b85b2;
case 0x0c0b85b4u: goto P_0c0b85b4;
case 0x0c0b85b6u: goto P_0c0b85b6;
case 0x0c0b85b8u: goto P_0c0b85b8;
case 0x0c0b85bau: goto P_0c0b85ba;
case 0x0c0b85bcu: goto P_0c0b85bc;
case 0x0c0b85beu: goto P_0c0b85be;
case 0x0c0b85c0u: goto P_0c0b85c0;
case 0x0c0b85c2u: goto P_0c0b85c2;
case 0x0c0b85c4u: goto P_0c0b85c4;
case 0x0c0b85c6u: goto P_0c0b85c6;
case 0x0c0b85c8u: goto P_0c0b85c8;
case 0x0c0b85cau: goto P_0c0b85ca;
case 0x0c0b85ccu: goto P_0c0b85cc;
case 0x0c0b85ceu: goto P_0c0b85ce;
case 0x0c0b85d0u: goto P_0c0b85d0;
case 0x0c0b85d2u: goto P_0c0b85d2;
case 0x0c0b85d4u: goto P_0c0b85d4;
case 0x0c0b85d6u: goto P_0c0b85d6;
case 0x0c0b85d8u: goto P_0c0b85d8;
case 0x0c0b85dau: goto P_0c0b85da;
case 0x0c0b85dcu: goto P_0c0b85dc;
case 0x0c0b85deu: goto P_0c0b85de;
case 0x0c0b85e0u: goto P_0c0b85e0;
case 0x0c0b85e2u: goto P_0c0b85e2;
case 0x0c0b85e4u: goto P_0c0b85e4;
case 0x0c0b85e6u: goto P_0c0b85e6;
case 0x0c0b85e8u: goto P_0c0b85e8;
case 0x0c0b85eau: goto P_0c0b85ea;
case 0x0c0b85ecu: goto P_0c0b85ec;
case 0x0c0b85eeu: goto P_0c0b85ee;
case 0x0c0b85f0u: goto P_0c0b85f0;
case 0x0c0b85f2u: goto P_0c0b85f2;
case 0x0c0b85f4u: goto P_0c0b85f4;
case 0x0c0b85f6u: goto P_0c0b85f6;
case 0x0c0b85f8u: goto P_0c0b85f8;
case 0x0c0b85fau: goto P_0c0b85fa;
case 0x0c0b85fcu: goto P_0c0b85fc;
case 0x0c0b85feu: goto P_0c0b85fe;
case 0x0c0b8600u: goto P_0c0b8600;
case 0x0c0b8602u: goto P_0c0b8602;
case 0x0c0b8604u: goto P_0c0b8604;
case 0x0c0b8606u: goto P_0c0b8606;
case 0x0c0b8608u: goto P_0c0b8608;
case 0x0c0b860au: goto P_0c0b860a;
case 0x0c0b860cu: goto P_0c0b860c;
case 0x0c0b860eu: goto P_0c0b860e;
case 0x0c0b8610u: goto P_0c0b8610;
case 0x0c0b8612u: goto P_0c0b8612;
case 0x0c0b8614u: goto P_0c0b8614;
case 0x0c0b8616u: goto P_0c0b8616;
case 0x0c0b8618u: goto P_0c0b8618;
case 0x0c0b861au: goto P_0c0b861a;
case 0x0c0b861cu: goto P_0c0b861c;
case 0x0c0b861eu: goto P_0c0b861e;
case 0x0c0b8620u: goto P_0c0b8620;
case 0x0c0b8622u: goto P_0c0b8622;
case 0x0c0b8624u: goto P_0c0b8624;
case 0x0c0b8626u: goto P_0c0b8626;
case 0x0c0b8628u: goto P_0c0b8628;
case 0x0c0b862au: goto P_0c0b862a;
case 0x0c0b862cu: goto P_0c0b862c;
case 0x0c0b862eu: goto P_0c0b862e;
case 0x0c0b8630u: goto P_0c0b8630;
case 0x0c0b8632u: goto P_0c0b8632;
case 0x0c0b8634u: goto P_0c0b8634;
case 0x0c0b8636u: goto P_0c0b8636;
case 0x0c0b8638u: goto P_0c0b8638;
case 0x0c0b863au: goto P_0c0b863a;
case 0x0c0b863cu: goto P_0c0b863c;
case 0x0c0b863eu: goto P_0c0b863e;
case 0x0c0b8640u: goto P_0c0b8640;
case 0x0c0b8642u: goto P_0c0b8642;
case 0x0c0b8644u: goto P_0c0b8644;
case 0x0c0b8646u: goto P_0c0b8646;
case 0x0c0b8648u: goto P_0c0b8648;
case 0x0c0b864au: goto P_0c0b864a;
case 0x0c0b864cu: goto P_0c0b864c;
case 0x0c0b864eu: goto P_0c0b864e;
case 0x0c0b8650u: goto P_0c0b8650;
case 0x0c0b8652u: goto P_0c0b8652;
case 0x0c0b8654u: goto P_0c0b8654;
case 0x0c0b8656u: goto P_0c0b8656;
case 0x0c0b8658u: goto P_0c0b8658;
case 0x0c0b865au: goto P_0c0b865a;
case 0x0c0b865cu: goto P_0c0b865c;
case 0x0c0b865eu: goto P_0c0b865e;
case 0x0c0b8660u: goto P_0c0b8660;
case 0x0c0b86d0u: goto P_0c0b86d0;
case 0x0c0b86d2u: goto P_0c0b86d2;
case 0x0c0b86d4u: goto P_0c0b86d4;
case 0x0c0b86d6u: goto P_0c0b86d6;
case 0x0c0b86d8u: goto P_0c0b86d8;
case 0x0c0b86dau: goto P_0c0b86da;
case 0x0c0b86dcu: goto P_0c0b86dc;
case 0x0c0b86deu: goto P_0c0b86de;
case 0x0c0b86e0u: goto P_0c0b86e0;
case 0x0c0b86e2u: goto P_0c0b86e2;
case 0x0c0b86e4u: goto P_0c0b86e4;
case 0x0c0b86e6u: goto P_0c0b86e6;
case 0x0c0b86e8u: goto P_0c0b86e8;
case 0x0c0b86eau: goto P_0c0b86ea;
case 0x0c0b86ecu: goto P_0c0b86ec;
case 0x0c0b86eeu: goto P_0c0b86ee;
case 0x0c0b86f0u: goto P_0c0b86f0;
case 0x0c0b86f2u: goto P_0c0b86f2;
case 0x0c0b86f4u: goto P_0c0b86f4;
case 0x0c0b86f6u: goto P_0c0b86f6;
case 0x0c0b86f8u: goto P_0c0b86f8;
case 0x0c0b86fau: goto P_0c0b86fa;
case 0x0c0b86fcu: goto P_0c0b86fc;
case 0x0c0b86feu: goto P_0c0b86fe;
case 0x0c0b8700u: goto P_0c0b8700;
case 0x0c0b8702u: goto P_0c0b8702;
case 0x0c0b8704u: goto P_0c0b8704;
case 0x0c0b8706u: goto P_0c0b8706;
case 0x0c0b8708u: goto P_0c0b8708;
case 0x0c0b870au: goto P_0c0b870a;
case 0x0c0b870cu: goto P_0c0b870c;
case 0x0c0b870eu: goto P_0c0b870e;
case 0x0c0b8710u: goto P_0c0b8710;
case 0x0c0b8712u: goto P_0c0b8712;
case 0x0c0b8714u: goto P_0c0b8714;
case 0x0c0b8716u: goto P_0c0b8716;
case 0x0c0b8718u: goto P_0c0b8718;
case 0x0c0b871au: goto P_0c0b871a;
case 0x0c0b871cu: goto P_0c0b871c;
case 0x0c0b871eu: goto P_0c0b871e;
case 0x0c0b8720u: goto P_0c0b8720;
case 0x0c0b8722u: goto P_0c0b8722;
case 0x0c0b8724u: goto P_0c0b8724;
case 0x0c0b8726u: goto P_0c0b8726;
case 0x0c0b8728u: goto P_0c0b8728;
case 0x0c0b872au: goto P_0c0b872a;
case 0x0c0b872cu: goto P_0c0b872c;
case 0x0c0b872eu: goto P_0c0b872e;
case 0x0c0b8730u: goto P_0c0b8730;
case 0x0c0b8732u: goto P_0c0b8732;
case 0x0c0b8734u: goto P_0c0b8734;
case 0x0c0b8736u: goto P_0c0b8736;
case 0x0c0b8738u: goto P_0c0b8738;
case 0x0c0b873au: goto P_0c0b873a;
case 0x0c0b873cu: goto P_0c0b873c;
case 0x0c0b873eu: goto P_0c0b873e;
case 0x0c0b8740u: goto P_0c0b8740;
case 0x0c0b8742u: goto P_0c0b8742;
case 0x0c0b8744u: goto P_0c0b8744;
case 0x0c0b8746u: goto P_0c0b8746;
case 0x0c0b8748u: goto P_0c0b8748;
case 0x0c0b874au: goto P_0c0b874a;
case 0x0c0b874cu: goto P_0c0b874c;
case 0x0c0b874eu: goto P_0c0b874e;
case 0x0c0b8750u: goto P_0c0b8750;
case 0x0c0b8752u: goto P_0c0b8752;
case 0x0c0b8754u: goto P_0c0b8754;
case 0x0c0b8756u: goto P_0c0b8756;
case 0x0c0b8758u: goto P_0c0b8758;
case 0x0c0b875au: goto P_0c0b875a;
case 0x0c0b875cu: goto P_0c0b875c;
case 0x0c0b875eu: goto P_0c0b875e;
case 0x0c0b8760u: goto P_0c0b8760;
case 0x0c0b8762u: goto P_0c0b8762;
case 0x0c0b8764u: goto P_0c0b8764;
case 0x0c0b8766u: goto P_0c0b8766;
case 0x0c0b8768u: goto P_0c0b8768;
case 0x0c0b876au: goto P_0c0b876a;
case 0x0c0b876cu: goto P_0c0b876c;
case 0x0c0b876eu: goto P_0c0b876e;
case 0x0c0b8770u: goto P_0c0b8770;
case 0x0c0b8772u: goto P_0c0b8772;
case 0x0c0b8774u: goto P_0c0b8774;
case 0x0c0b8776u: goto P_0c0b8776;
case 0x0c0b8778u: goto P_0c0b8778;
case 0x0c0b877au: goto P_0c0b877a;
case 0x0c0b877cu: goto P_0c0b877c;
case 0x0c0b877eu: goto P_0c0b877e;
case 0x0c0b8780u: goto P_0c0b8780;
case 0x0c0b8782u: goto P_0c0b8782;
case 0x0c0b8784u: goto P_0c0b8784;
case 0x0c0b8786u: goto P_0c0b8786;
case 0x0c0b8788u: goto P_0c0b8788;
case 0x0c0b878au: goto P_0c0b878a;
case 0x0c0b878cu: goto P_0c0b878c;
case 0x0c0b878eu: goto P_0c0b878e;
case 0x0c0b8790u: goto P_0c0b8790;
case 0x0c0b8792u: goto P_0c0b8792;
case 0x0c0b8794u: goto P_0c0b8794;
case 0x0c0b8796u: goto P_0c0b8796;
case 0x0c0b8798u: goto P_0c0b8798;
case 0x0c0b879au: goto P_0c0b879a;
case 0x0c0b879cu: goto P_0c0b879c;
case 0x0c0b879eu: goto P_0c0b879e;
case 0x0c0b87a0u: goto P_0c0b87a0;
case 0x0c0b87a2u: goto P_0c0b87a2;
case 0x0c0b87a4u: goto P_0c0b87a4;
case 0x0c0b87a6u: goto P_0c0b87a6;
case 0x0c0b87a8u: goto P_0c0b87a8;
case 0x0c0b87aau: goto P_0c0b87aa;
case 0x0c0b87acu: goto P_0c0b87ac;
case 0x0c0b87aeu: goto P_0c0b87ae;
case 0x0c0b87b0u: goto P_0c0b87b0;
case 0x0c0b87b2u: goto P_0c0b87b2;
case 0x0c0b87b4u: goto P_0c0b87b4;
case 0x0c0b87b6u: goto P_0c0b87b6;
case 0x0c0b87b8u: goto P_0c0b87b8;
case 0x0c0b87bau: goto P_0c0b87ba;
case 0x0c0b87bcu: goto P_0c0b87bc;
case 0x0c0b87beu: goto P_0c0b87be;
case 0x0c0b87c0u: goto P_0c0b87c0;
case 0x0c0b87c2u: goto P_0c0b87c2;
case 0x0c0b87c4u: goto P_0c0b87c4;
case 0x0c0b87c6u: goto P_0c0b87c6;
case 0x0c0b87c8u: goto P_0c0b87c8;
case 0x0c0b87cau: goto P_0c0b87ca;
case 0x0c0b87ccu: goto P_0c0b87cc;
case 0x0c0b87ceu: goto P_0c0b87ce;
case 0x0c0b87d0u: goto P_0c0b87d0;
case 0x0c0b87d2u: goto P_0c0b87d2;
case 0x0c0b87d4u: goto P_0c0b87d4;
case 0x0c0b87d6u: goto P_0c0b87d6;
case 0x0c0b87d8u: goto P_0c0b87d8;
case 0x0c0b87dau: goto P_0c0b87da;
case 0x0c0b87dcu: goto P_0c0b87dc;
case 0x0c0b87deu: goto P_0c0b87de;
case 0x0c0b87e0u: goto P_0c0b87e0;
case 0x0c0b87e2u: goto P_0c0b87e2;
case 0x0c0b87e4u: goto P_0c0b87e4;
case 0x0c0b87e6u: goto P_0c0b87e6;
case 0x0c0b87e8u: goto P_0c0b87e8;
case 0x0c0b87eau: goto P_0c0b87ea;
case 0x0c0b87ecu: goto P_0c0b87ec;
case 0x0c0b87eeu: goto P_0c0b87ee;
case 0x0c0b87f0u: goto P_0c0b87f0;
case 0x0c0b87f2u: goto P_0c0b87f2;
case 0x0c0b87f4u: goto P_0c0b87f4;
case 0x0c0b87f6u: goto P_0c0b87f6;
case 0x0c0b87f8u: goto P_0c0b87f8;
case 0x0c0b87fau: goto P_0c0b87fa;
case 0x0c0b87fcu: goto P_0c0b87fc;
case 0x0c0b87feu: goto P_0c0b87fe;
case 0x0c0b8800u: goto P_0c0b8800;
case 0x0c0b8802u: goto P_0c0b8802;
case 0x0c0b8804u: goto P_0c0b8804;
case 0x0c0b8806u: goto P_0c0b8806;
case 0x0c0b8808u: goto P_0c0b8808;
case 0x0c0b880au: goto P_0c0b880a;
case 0x0c0b880cu: goto P_0c0b880c;
case 0x0c0b880eu: goto P_0c0b880e;
case 0x0c0b8810u: goto P_0c0b8810;
case 0x0c0b8812u: goto P_0c0b8812;
case 0x0c0b8814u: goto P_0c0b8814;
case 0x0c0b8816u: goto P_0c0b8816;
case 0x0c0b8818u: goto P_0c0b8818;
case 0x0c0b881au: goto P_0c0b881a;
case 0x0c0b881cu: goto P_0c0b881c;
case 0x0c0b881eu: goto P_0c0b881e;
case 0x0c0b8820u: goto P_0c0b8820;
case 0x0c0b8822u: goto P_0c0b8822;
case 0x0c0b8824u: goto P_0c0b8824;
case 0x0c0b8826u: goto P_0c0b8826;
case 0x0c0b8828u: goto P_0c0b8828;
case 0x0c0b88a2u: goto P_0c0b88a2;
case 0x0c0b88a4u: goto P_0c0b88a4;
case 0x0c0b88a6u: goto P_0c0b88a6;
case 0x0c0b88a8u: goto P_0c0b88a8;
case 0x0c0b88aau: goto P_0c0b88aa;
case 0x0c0b88acu: goto P_0c0b88ac;
case 0x0c0b88aeu: goto P_0c0b88ae;
case 0x0c0b88b0u: goto P_0c0b88b0;
case 0x0c0b88b2u: goto P_0c0b88b2;
case 0x0c0b88b4u: goto P_0c0b88b4;
case 0x0c0b88b6u: goto P_0c0b88b6;
case 0x0c0b88b8u: goto P_0c0b88b8;
case 0x0c0b88bau: goto P_0c0b88ba;
case 0x0c0b88bcu: goto P_0c0b88bc;
case 0x0c0b88beu: goto P_0c0b88be;
case 0x0c0b88c0u: goto P_0c0b88c0;
case 0x0c0b88c2u: goto P_0c0b88c2;
case 0x0c0b88c4u: goto P_0c0b88c4;
case 0x0c0b88c6u: goto P_0c0b88c6;
case 0x0c0b88c8u: goto P_0c0b88c8;
case 0x0c0b88cau: goto P_0c0b88ca;
case 0x0c0b88ccu: goto P_0c0b88cc;
case 0x0c0b88ceu: goto P_0c0b88ce;
case 0x0c0b88d0u: goto P_0c0b88d0;
case 0x0c0b88d2u: goto P_0c0b88d2;
case 0x0c0b88d4u: goto P_0c0b88d4;
case 0x0c0b88d6u: goto P_0c0b88d6;
case 0x0c0b88d8u: goto P_0c0b88d8;
case 0x0c0b88dau: goto P_0c0b88da;
case 0x0c0b88dcu: goto P_0c0b88dc;
case 0x0c0b88deu: goto P_0c0b88de;
case 0x0c0b88e0u: goto P_0c0b88e0;
case 0x0c0b88e2u: goto P_0c0b88e2;
case 0x0c0b88e4u: goto P_0c0b88e4;
case 0x0c0b88e6u: goto P_0c0b88e6;
case 0x0c0b88e8u: goto P_0c0b88e8;
case 0x0c0b88eau: goto P_0c0b88ea;
case 0x0c0b88ecu: goto P_0c0b88ec;
case 0x0c0b88eeu: goto P_0c0b88ee;
case 0x0c0b88f0u: goto P_0c0b88f0;
case 0x0c0b88f2u: goto P_0c0b88f2;
case 0x0c0b88f4u: goto P_0c0b88f4;
case 0x0c0b88f6u: goto P_0c0b88f6;
case 0x0c0b88f8u: goto P_0c0b88f8;
case 0x0c0b88fau: goto P_0c0b88fa;
case 0x0c0b88fcu: goto P_0c0b88fc;
case 0x0c0b88feu: goto P_0c0b88fe;
case 0x0c0b8900u: goto P_0c0b8900;
case 0x0c0b8902u: goto P_0c0b8902;
case 0x0c0b8904u: goto P_0c0b8904;
case 0x0c0b8906u: goto P_0c0b8906;
case 0x0c0b8908u: goto P_0c0b8908;
case 0x0c0b890au: goto P_0c0b890a;
case 0x0c0b890cu: goto P_0c0b890c;
case 0x0c0b890eu: goto P_0c0b890e;
case 0x0c0b8910u: goto P_0c0b8910;
case 0x0c0b8912u: goto P_0c0b8912;
case 0x0c0b8914u: goto P_0c0b8914;
case 0x0c0b8916u: goto P_0c0b8916;
case 0x0c0b8918u: goto P_0c0b8918;
case 0x0c0b891au: goto P_0c0b891a;
case 0x0c0b891cu: goto P_0c0b891c;
case 0x0c0b891eu: goto P_0c0b891e;
case 0x0c0b8920u: goto P_0c0b8920;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0b84fe: /* original 2fe6, guest PC 0x0c0b84fe */
if(!s->budget--) { s->failed_pc=0x0c0b84feu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b8500;
P_0c0b8500: /* original 2fd6, guest PC 0x0c0b8500 */
if(!s->budget--) { s->failed_pc=0x0c0b8500u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b8502;
P_0c0b8502: /* original 2fc6, guest PC 0x0c0b8502 */
if(!s->budget--) { s->failed_pc=0x0c0b8502u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b8504;
P_0c0b8504: /* original 2fb6, guest PC 0x0c0b8504 */
if(!s->budget--) { s->failed_pc=0x0c0b8504u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b8506;
P_0c0b8506: /* original 2fa6, guest PC 0x0c0b8506 */
if(!s->budget--) { s->failed_pc=0x0c0b8506u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b8508;
P_0c0b8508: /* original 2f96, guest PC 0x0c0b8508 */
if(!s->budget--) { s->failed_pc=0x0c0b8508u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b850a;
P_0c0b850a: /* original 4f22, guest PC 0x0c0b850a */
if(!s->budget--) { s->failed_pc=0x0c0b850au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b850c;
P_0c0b850c: /* original 5d44, guest PC 0x0c0b850c */
if(!s->budget--) { s->failed_pc=0x0c0b850cu; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0b850e;
P_0c0b850e: /* original 94a8, guest PC 0x0c0b850e */
if(!s->budget--) { s->failed_pc=0x0c0b850eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8662u,2);
goto P_0c0b8510;
P_0c0b8510: /* original de6e, guest PC 0x0c0b8510 */
if(!s->budget--) { s->failed_pc=0x0c0b8510u; return 0; }
r[14]=read(ram,0x0c0b86ccu,4);
goto P_0c0b8512;
P_0c0b8512: /* original 7ff8, guest PC 0x0c0b8512 */
if(!s->budget--) { s->failed_pc=0x0c0b8512u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0b8514;
P_0c0b8514: /* original 4e0b, guest PC 0x0c0b8514 */
if(!s->budget--) { s->failed_pc=0x0c0b8514u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8518u;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8518u) { target=s->pc; goto dispatch; }
goto P_0c0b8518;
P_0c0b8516: /* original 65d2, guest PC 0x0c0b8516 */
if(!s->budget--) { s->failed_pc=0x0c0b8516u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0b8518;
P_0c0b8518: /* original 94a4, guest PC 0x0c0b8518 */
if(!s->budget--) { s->failed_pc=0x0c0b8518u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8664u,2);
goto P_0c0b851a;
P_0c0b851a: /* original 4e0b, guest PC 0x0c0b851a */
if(!s->budget--) { s->failed_pc=0x0c0b851au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b851eu;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b851eu) { target=s->pc; goto dispatch; }
goto P_0c0b851e;
P_0c0b851c: /* original 55d1, guest PC 0x0c0b851c */
if(!s->budget--) { s->failed_pc=0x0c0b851cu; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0b851e;
P_0c0b851e: /* original 94a2, guest PC 0x0c0b851e */
if(!s->budget--) { s->failed_pc=0x0c0b851eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8666u,2);
goto P_0c0b8520;
P_0c0b8520: /* original 4e0b, guest PC 0x0c0b8520 */
if(!s->budget--) { s->failed_pc=0x0c0b8520u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8524u;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8524u) { target=s->pc; goto dispatch; }
goto P_0c0b8524;
P_0c0b8522: /* original 55d2, guest PC 0x0c0b8522 */
if(!s->budget--) { s->failed_pc=0x0c0b8522u; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0b8524;
P_0c0b8524: /* original 94a0, guest PC 0x0c0b8524 */
if(!s->budget--) { s->failed_pc=0x0c0b8524u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8668u,2);
goto P_0c0b8526;
P_0c0b8526: /* original 4e0b, guest PC 0x0c0b8526 */
if(!s->budget--) { s->failed_pc=0x0c0b8526u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b852au;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b852au) { target=s->pc; goto dispatch; }
goto P_0c0b852a;
P_0c0b8528: /* original 55d3, guest PC 0x0c0b8528 */
if(!s->budget--) { s->failed_pc=0x0c0b8528u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0b852a;
P_0c0b852a: /* original 949e, guest PC 0x0c0b852a */
if(!s->budget--) { s->failed_pc=0x0c0b852au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b866au,2);
goto P_0c0b852c;
P_0c0b852c: /* original 4e0b, guest PC 0x0c0b852c */
if(!s->budget--) { s->failed_pc=0x0c0b852cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8530u;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8530u) { target=s->pc; goto dispatch; }
goto P_0c0b8530;
P_0c0b852e: /* original 55d4, guest PC 0x0c0b852e */
if(!s->budget--) { s->failed_pc=0x0c0b852eu; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0b8530;
P_0c0b8530: /* original 949c, guest PC 0x0c0b8530 */
if(!s->budget--) { s->failed_pc=0x0c0b8530u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b866cu,2);
goto P_0c0b8532;
P_0c0b8532: /* original 4e0b, guest PC 0x0c0b8532 */
if(!s->budget--) { s->failed_pc=0x0c0b8532u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8536u;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8536u) { target=s->pc; goto dispatch; }
goto P_0c0b8536;
P_0c0b8534: /* original 55d5, guest PC 0x0c0b8534 */
if(!s->budget--) { s->failed_pc=0x0c0b8534u; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0b8536;
P_0c0b8536: /* original 949a, guest PC 0x0c0b8536 */
if(!s->budget--) { s->failed_pc=0x0c0b8536u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b866eu,2);
goto P_0c0b8538;
P_0c0b8538: /* original 4e0b, guest PC 0x0c0b8538 */
if(!s->budget--) { s->failed_pc=0x0c0b8538u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b853cu;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b853cu) { target=s->pc; goto dispatch; }
goto P_0c0b853c;
P_0c0b853a: /* original 55d6, guest PC 0x0c0b853a */
if(!s->budget--) { s->failed_pc=0x0c0b853au; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0b853c;
P_0c0b853c: /* original 9498, guest PC 0x0c0b853c */
if(!s->budget--) { s->failed_pc=0x0c0b853cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8670u,2);
goto P_0c0b853e;
P_0c0b853e: /* original 4e0b, guest PC 0x0c0b853e */
if(!s->budget--) { s->failed_pc=0x0c0b853eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8542u;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8542u) { target=s->pc; goto dispatch; }
goto P_0c0b8542;
P_0c0b8540: /* original 55d7, guest PC 0x0c0b8540 */
if(!s->budget--) { s->failed_pc=0x0c0b8540u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0b8542;
P_0c0b8542: /* original 9496, guest PC 0x0c0b8542 */
if(!s->budget--) { s->failed_pc=0x0c0b8542u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8672u,2);
goto P_0c0b8544;
P_0c0b8544: /* original 4e0b, guest PC 0x0c0b8544 */
if(!s->budget--) { s->failed_pc=0x0c0b8544u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8548u;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8548u) { target=s->pc; goto dispatch; }
goto P_0c0b8548;
P_0c0b8546: /* original 55d8, guest PC 0x0c0b8546 */
if(!s->budget--) { s->failed_pc=0x0c0b8546u; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0b8548;
P_0c0b8548: /* original 9494, guest PC 0x0c0b8548 */
if(!s->budget--) { s->failed_pc=0x0c0b8548u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8674u,2);
goto P_0c0b854a;
P_0c0b854a: /* original 4e0b, guest PC 0x0c0b854a */
if(!s->budget--) { s->failed_pc=0x0c0b854au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b854eu;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b854eu) { target=s->pc; goto dispatch; }
goto P_0c0b854e;
P_0c0b854c: /* original 55d9, guest PC 0x0c0b854c */
if(!s->budget--) { s->failed_pc=0x0c0b854cu; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0b854e;
P_0c0b854e: /* original 9492, guest PC 0x0c0b854e */
if(!s->budget--) { s->failed_pc=0x0c0b854eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8676u,2);
goto P_0c0b8550;
P_0c0b8550: /* original 4e0b, guest PC 0x0c0b8550 */
if(!s->budget--) { s->failed_pc=0x0c0b8550u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8554u;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8554u) { target=s->pc; goto dispatch; }
goto P_0c0b8554;
P_0c0b8552: /* original 55da, guest PC 0x0c0b8552 */
if(!s->budget--) { s->failed_pc=0x0c0b8552u; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0b8554;
P_0c0b8554: /* original 9490, guest PC 0x0c0b8554 */
if(!s->budget--) { s->failed_pc=0x0c0b8554u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8678u,2);
goto P_0c0b8556;
P_0c0b8556: /* original 4e0b, guest PC 0x0c0b8556 */
if(!s->budget--) { s->failed_pc=0x0c0b8556u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b855au;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b855au) { target=s->pc; goto dispatch; }
goto P_0c0b855a;
P_0c0b8558: /* original 55db, guest PC 0x0c0b8558 */
if(!s->budget--) { s->failed_pc=0x0c0b8558u; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0b855a;
P_0c0b855a: /* original 948e, guest PC 0x0c0b855a */
if(!s->budget--) { s->failed_pc=0x0c0b855au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b867au,2);
goto P_0c0b855c;
P_0c0b855c: /* original 4e0b, guest PC 0x0c0b855c */
if(!s->budget--) { s->failed_pc=0x0c0b855cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8560u;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8560u) { target=s->pc; goto dispatch; }
goto P_0c0b8560;
P_0c0b855e: /* original 55dc, guest PC 0x0c0b855e */
if(!s->budget--) { s->failed_pc=0x0c0b855eu; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0b8560;
P_0c0b8560: /* original 948c, guest PC 0x0c0b8560 */
if(!s->budget--) { s->failed_pc=0x0c0b8560u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b867cu,2);
goto P_0c0b8562;
P_0c0b8562: /* original 4e0b, guest PC 0x0c0b8562 */
if(!s->budget--) { s->failed_pc=0x0c0b8562u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8566u;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8566u) { target=s->pc; goto dispatch; }
goto P_0c0b8566;
P_0c0b8564: /* original 55dd, guest PC 0x0c0b8564 */
if(!s->budget--) { s->failed_pc=0x0c0b8564u; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0b8566;
P_0c0b8566: /* original 948a, guest PC 0x0c0b8566 */
if(!s->budget--) { s->failed_pc=0x0c0b8566u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b867eu,2);
goto P_0c0b8568;
P_0c0b8568: /* original 4e0b, guest PC 0x0c0b8568 */
if(!s->budget--) { s->failed_pc=0x0c0b8568u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b856cu;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b856cu) { target=s->pc; goto dispatch; }
goto P_0c0b856c;
P_0c0b856a: /* original 55de, guest PC 0x0c0b856a */
if(!s->budget--) { s->failed_pc=0x0c0b856au; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0b856c;
P_0c0b856c: /* original 9488, guest PC 0x0c0b856c */
if(!s->budget--) { s->failed_pc=0x0c0b856cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8680u,2);
goto P_0c0b856e;
P_0c0b856e: /* original 4e0b, guest PC 0x0c0b856e */
if(!s->budget--) { s->failed_pc=0x0c0b856eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8572u;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8572u) { target=s->pc; goto dispatch; }
goto P_0c0b8572;
P_0c0b8570: /* original 55df, guest PC 0x0c0b8570 */
if(!s->budget--) { s->failed_pc=0x0c0b8570u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0b8572;
P_0c0b8572: /* original 9486, guest PC 0x0c0b8572 */
if(!s->budget--) { s->failed_pc=0x0c0b8572u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8682u,2);
goto P_0c0b8574;
P_0c0b8574: /* original e040, guest PC 0x0c0b8574 */
if(!s->budget--) { s->failed_pc=0x0c0b8574u; return 0; }
r[0]=0x00000040u;
goto P_0c0b8576;
P_0c0b8576: /* original 4e0b, guest PC 0x0c0b8576 */
if(!s->budget--) { s->failed_pc=0x0c0b8576u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b857au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b857au) { target=s->pc; goto dispatch; }
goto P_0c0b857a;
P_0c0b8578: /* original 05de, guest PC 0x0c0b8578 */
if(!s->budget--) { s->failed_pc=0x0c0b8578u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b857a;
P_0c0b857a: /* original 9483, guest PC 0x0c0b857a */
if(!s->budget--) { s->failed_pc=0x0c0b857au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8684u,2);
goto P_0c0b857c;
P_0c0b857c: /* original e044, guest PC 0x0c0b857c */
if(!s->budget--) { s->failed_pc=0x0c0b857cu; return 0; }
r[0]=0x00000044u;
goto P_0c0b857e;
P_0c0b857e: /* original 4e0b, guest PC 0x0c0b857e */
if(!s->budget--) { s->failed_pc=0x0c0b857eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8582u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8582u) { target=s->pc; goto dispatch; }
goto P_0c0b8582;
P_0c0b8580: /* original 05de, guest PC 0x0c0b8580 */
if(!s->budget--) { s->failed_pc=0x0c0b8580u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8582;
P_0c0b8582: /* original 9480, guest PC 0x0c0b8582 */
if(!s->budget--) { s->failed_pc=0x0c0b8582u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8686u,2);
goto P_0c0b8584;
P_0c0b8584: /* original e048, guest PC 0x0c0b8584 */
if(!s->budget--) { s->failed_pc=0x0c0b8584u; return 0; }
r[0]=0x00000048u;
goto P_0c0b8586;
P_0c0b8586: /* original 4e0b, guest PC 0x0c0b8586 */
if(!s->budget--) { s->failed_pc=0x0c0b8586u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b858au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b858au) { target=s->pc; goto dispatch; }
goto P_0c0b858a;
P_0c0b8588: /* original 05de, guest PC 0x0c0b8588 */
if(!s->budget--) { s->failed_pc=0x0c0b8588u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b858a;
P_0c0b858a: /* original 947d, guest PC 0x0c0b858a */
if(!s->budget--) { s->failed_pc=0x0c0b858au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8688u,2);
goto P_0c0b858c;
P_0c0b858c: /* original e04c, guest PC 0x0c0b858c */
if(!s->budget--) { s->failed_pc=0x0c0b858cu; return 0; }
r[0]=0x0000004cu;
goto P_0c0b858e;
P_0c0b858e: /* original 4e0b, guest PC 0x0c0b858e */
if(!s->budget--) { s->failed_pc=0x0c0b858eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8592u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8592u) { target=s->pc; goto dispatch; }
goto P_0c0b8592;
P_0c0b8590: /* original 05de, guest PC 0x0c0b8590 */
if(!s->budget--) { s->failed_pc=0x0c0b8590u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8592;
P_0c0b8592: /* original 947a, guest PC 0x0c0b8592 */
if(!s->budget--) { s->failed_pc=0x0c0b8592u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b868au,2);
goto P_0c0b8594;
P_0c0b8594: /* original e050, guest PC 0x0c0b8594 */
if(!s->budget--) { s->failed_pc=0x0c0b8594u; return 0; }
r[0]=0x00000050u;
goto P_0c0b8596;
P_0c0b8596: /* original 4e0b, guest PC 0x0c0b8596 */
if(!s->budget--) { s->failed_pc=0x0c0b8596u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b859au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b859au) { target=s->pc; goto dispatch; }
goto P_0c0b859a;
P_0c0b8598: /* original 05de, guest PC 0x0c0b8598 */
if(!s->budget--) { s->failed_pc=0x0c0b8598u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b859a;
P_0c0b859a: /* original 9477, guest PC 0x0c0b859a */
if(!s->budget--) { s->failed_pc=0x0c0b859au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b868cu,2);
goto P_0c0b859c;
P_0c0b859c: /* original e054, guest PC 0x0c0b859c */
if(!s->budget--) { s->failed_pc=0x0c0b859cu; return 0; }
r[0]=0x00000054u;
goto P_0c0b859e;
P_0c0b859e: /* original 4e0b, guest PC 0x0c0b859e */
if(!s->budget--) { s->failed_pc=0x0c0b859eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b85a2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b85a2u) { target=s->pc; goto dispatch; }
goto P_0c0b85a2;
P_0c0b85a0: /* original 05de, guest PC 0x0c0b85a0 */
if(!s->budget--) { s->failed_pc=0x0c0b85a0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b85a2;
P_0c0b85a2: /* original 9474, guest PC 0x0c0b85a2 */
if(!s->budget--) { s->failed_pc=0x0c0b85a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b868eu,2);
goto P_0c0b85a4;
P_0c0b85a4: /* original e058, guest PC 0x0c0b85a4 */
if(!s->budget--) { s->failed_pc=0x0c0b85a4u; return 0; }
r[0]=0x00000058u;
goto P_0c0b85a6;
P_0c0b85a6: /* original 4e0b, guest PC 0x0c0b85a6 */
if(!s->budget--) { s->failed_pc=0x0c0b85a6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b85aau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b85aau) { target=s->pc; goto dispatch; }
goto P_0c0b85aa;
P_0c0b85a8: /* original 05de, guest PC 0x0c0b85a8 */
if(!s->budget--) { s->failed_pc=0x0c0b85a8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b85aa;
P_0c0b85aa: /* original 9471, guest PC 0x0c0b85aa */
if(!s->budget--) { s->failed_pc=0x0c0b85aau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8690u,2);
goto P_0c0b85ac;
P_0c0b85ac: /* original e05c, guest PC 0x0c0b85ac */
if(!s->budget--) { s->failed_pc=0x0c0b85acu; return 0; }
r[0]=0x0000005cu;
goto P_0c0b85ae;
P_0c0b85ae: /* original 4e0b, guest PC 0x0c0b85ae */
if(!s->budget--) { s->failed_pc=0x0c0b85aeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b85b2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b85b2u) { target=s->pc; goto dispatch; }
goto P_0c0b85b2;
P_0c0b85b0: /* original 05de, guest PC 0x0c0b85b0 */
if(!s->budget--) { s->failed_pc=0x0c0b85b0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b85b2;
P_0c0b85b2: /* original 946e, guest PC 0x0c0b85b2 */
if(!s->budget--) { s->failed_pc=0x0c0b85b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8692u,2);
goto P_0c0b85b4;
P_0c0b85b4: /* original e060, guest PC 0x0c0b85b4 */
if(!s->budget--) { s->failed_pc=0x0c0b85b4u; return 0; }
r[0]=0x00000060u;
goto P_0c0b85b6;
P_0c0b85b6: /* original 4e0b, guest PC 0x0c0b85b6 */
if(!s->budget--) { s->failed_pc=0x0c0b85b6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b85bau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b85bau) { target=s->pc; goto dispatch; }
goto P_0c0b85ba;
P_0c0b85b8: /* original 05de, guest PC 0x0c0b85b8 */
if(!s->budget--) { s->failed_pc=0x0c0b85b8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b85ba;
P_0c0b85ba: /* original 946b, guest PC 0x0c0b85ba */
if(!s->budget--) { s->failed_pc=0x0c0b85bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8694u,2);
goto P_0c0b85bc;
P_0c0b85bc: /* original e064, guest PC 0x0c0b85bc */
if(!s->budget--) { s->failed_pc=0x0c0b85bcu; return 0; }
r[0]=0x00000064u;
goto P_0c0b85be;
P_0c0b85be: /* original 4e0b, guest PC 0x0c0b85be */
if(!s->budget--) { s->failed_pc=0x0c0b85beu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b85c2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b85c2u) { target=s->pc; goto dispatch; }
goto P_0c0b85c2;
P_0c0b85c0: /* original 05de, guest PC 0x0c0b85c0 */
if(!s->budget--) { s->failed_pc=0x0c0b85c0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b85c2;
P_0c0b85c2: /* original 9468, guest PC 0x0c0b85c2 */
if(!s->budget--) { s->failed_pc=0x0c0b85c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8696u,2);
goto P_0c0b85c4;
P_0c0b85c4: /* original e068, guest PC 0x0c0b85c4 */
if(!s->budget--) { s->failed_pc=0x0c0b85c4u; return 0; }
r[0]=0x00000068u;
goto P_0c0b85c6;
P_0c0b85c6: /* original 4e0b, guest PC 0x0c0b85c6 */
if(!s->budget--) { s->failed_pc=0x0c0b85c6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b85cau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b85cau) { target=s->pc; goto dispatch; }
goto P_0c0b85ca;
P_0c0b85c8: /* original 05de, guest PC 0x0c0b85c8 */
if(!s->budget--) { s->failed_pc=0x0c0b85c8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b85ca;
P_0c0b85ca: /* original 9465, guest PC 0x0c0b85ca */
if(!s->budget--) { s->failed_pc=0x0c0b85cau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8698u,2);
goto P_0c0b85cc;
P_0c0b85cc: /* original e06c, guest PC 0x0c0b85cc */
if(!s->budget--) { s->failed_pc=0x0c0b85ccu; return 0; }
r[0]=0x0000006cu;
goto P_0c0b85ce;
P_0c0b85ce: /* original 4e0b, guest PC 0x0c0b85ce */
if(!s->budget--) { s->failed_pc=0x0c0b85ceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b85d2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b85d2u) { target=s->pc; goto dispatch; }
goto P_0c0b85d2;
P_0c0b85d0: /* original 05de, guest PC 0x0c0b85d0 */
if(!s->budget--) { s->failed_pc=0x0c0b85d0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b85d2;
P_0c0b85d2: /* original 9462, guest PC 0x0c0b85d2 */
if(!s->budget--) { s->failed_pc=0x0c0b85d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b869au,2);
goto P_0c0b85d4;
P_0c0b85d4: /* original e070, guest PC 0x0c0b85d4 */
if(!s->budget--) { s->failed_pc=0x0c0b85d4u; return 0; }
r[0]=0x00000070u;
goto P_0c0b85d6;
P_0c0b85d6: /* original 4e0b, guest PC 0x0c0b85d6 */
if(!s->budget--) { s->failed_pc=0x0c0b85d6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b85dau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b85dau) { target=s->pc; goto dispatch; }
goto P_0c0b85da;
P_0c0b85d8: /* original 05de, guest PC 0x0c0b85d8 */
if(!s->budget--) { s->failed_pc=0x0c0b85d8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b85da;
P_0c0b85da: /* original 945f, guest PC 0x0c0b85da */
if(!s->budget--) { s->failed_pc=0x0c0b85dau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b869cu,2);
goto P_0c0b85dc;
P_0c0b85dc: /* original e074, guest PC 0x0c0b85dc */
if(!s->budget--) { s->failed_pc=0x0c0b85dcu; return 0; }
r[0]=0x00000074u;
goto P_0c0b85de;
P_0c0b85de: /* original 4e0b, guest PC 0x0c0b85de */
if(!s->budget--) { s->failed_pc=0x0c0b85deu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b85e2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b85e2u) { target=s->pc; goto dispatch; }
goto P_0c0b85e2;
P_0c0b85e0: /* original 05de, guest PC 0x0c0b85e0 */
if(!s->budget--) { s->failed_pc=0x0c0b85e0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b85e2;
P_0c0b85e2: /* original 945c, guest PC 0x0c0b85e2 */
if(!s->budget--) { s->failed_pc=0x0c0b85e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b869eu,2);
goto P_0c0b85e4;
P_0c0b85e4: /* original e078, guest PC 0x0c0b85e4 */
if(!s->budget--) { s->failed_pc=0x0c0b85e4u; return 0; }
r[0]=0x00000078u;
goto P_0c0b85e6;
P_0c0b85e6: /* original 4e0b, guest PC 0x0c0b85e6 */
if(!s->budget--) { s->failed_pc=0x0c0b85e6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b85eau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b85eau) { target=s->pc; goto dispatch; }
goto P_0c0b85ea;
P_0c0b85e8: /* original 05de, guest PC 0x0c0b85e8 */
if(!s->budget--) { s->failed_pc=0x0c0b85e8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b85ea;
P_0c0b85ea: /* original 9459, guest PC 0x0c0b85ea */
if(!s->budget--) { s->failed_pc=0x0c0b85eau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b86a0u,2);
goto P_0c0b85ec;
P_0c0b85ec: /* original e07c, guest PC 0x0c0b85ec */
if(!s->budget--) { s->failed_pc=0x0c0b85ecu; return 0; }
r[0]=0x0000007cu;
goto P_0c0b85ee;
P_0c0b85ee: /* original 4e0b, guest PC 0x0c0b85ee */
if(!s->budget--) { s->failed_pc=0x0c0b85eeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b85f2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b85f2u) { target=s->pc; goto dispatch; }
goto P_0c0b85f2;
P_0c0b85f0: /* original 05de, guest PC 0x0c0b85f0 */
if(!s->budget--) { s->failed_pc=0x0c0b85f0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b85f2;
P_0c0b85f2: /* original 9457, guest PC 0x0c0b85f2 */
if(!s->budget--) { s->failed_pc=0x0c0b85f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b86a4u,2);
goto P_0c0b85f4;
P_0c0b85f4: /* original 9055, guest PC 0x0c0b85f4 */
if(!s->budget--) { s->failed_pc=0x0c0b85f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b86a2u,2);
goto P_0c0b85f6;
P_0c0b85f6: /* original 4e0b, guest PC 0x0c0b85f6 */
if(!s->budget--) { s->failed_pc=0x0c0b85f6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b85fau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b85fau) { target=s->pc; goto dispatch; }
goto P_0c0b85fa;
P_0c0b85f8: /* original 05de, guest PC 0x0c0b85f8 */
if(!s->budget--) { s->failed_pc=0x0c0b85f8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b85fa;
P_0c0b85fa: /* original 9554, guest PC 0x0c0b85fa */
if(!s->budget--) { s->failed_pc=0x0c0b85fau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b86a6u,2);
goto P_0c0b85fc;
P_0c0b85fc: /* original 35dc, guest PC 0x0c0b85fc */
if(!s->budget--) { s->failed_pc=0x0c0b85fcu; return 0; }
r[5]+=r[13];
goto P_0c0b85fe;
P_0c0b85fe: /* original 2f52, guest PC 0x0c0b85fe */
if(!s->budget--) { s->failed_pc=0x0c0b85feu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b8600;
P_0c0b8600: /* original 9452, guest PC 0x0c0b8600 */
if(!s->budget--) { s->failed_pc=0x0c0b8600u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b86a8u,2);
goto P_0c0b8602;
P_0c0b8602: /* original 4e0b, guest PC 0x0c0b8602 */
if(!s->budget--) { s->failed_pc=0x0c0b8602u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8606u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8606u) { target=s->pc; goto dispatch; }
goto P_0c0b8606;
P_0c0b8604: /* original 6552, guest PC 0x0c0b8604 */
if(!s->budget--) { s->failed_pc=0x0c0b8604u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8606;
P_0c0b8606: /* original 9550, guest PC 0x0c0b8606 */
if(!s->budget--) { s->failed_pc=0x0c0b8606u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b86aau,2);
goto P_0c0b8608;
P_0c0b8608: /* original 35dc, guest PC 0x0c0b8608 */
if(!s->budget--) { s->failed_pc=0x0c0b8608u; return 0; }
r[5]+=r[13];
goto P_0c0b860a;
P_0c0b860a: /* original 1f51, guest PC 0x0c0b860a */
if(!s->budget--) { s->failed_pc=0x0c0b860au; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0b860c;
P_0c0b860c: /* original 944e, guest PC 0x0c0b860c */
if(!s->budget--) { s->failed_pc=0x0c0b860cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b86acu,2);
goto P_0c0b860e;
P_0c0b860e: /* original 4e0b, guest PC 0x0c0b860e */
if(!s->budget--) { s->failed_pc=0x0c0b860eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8612u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8612u) { target=s->pc; goto dispatch; }
goto P_0c0b8612;
P_0c0b8610: /* original 6552, guest PC 0x0c0b8610 */
if(!s->budget--) { s->failed_pc=0x0c0b8610u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8612;
P_0c0b8612: /* original 944d, guest PC 0x0c0b8612 */
if(!s->budget--) { s->failed_pc=0x0c0b8612u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b86b0u,2);
goto P_0c0b8614;
P_0c0b8614: /* original 904b, guest PC 0x0c0b8614 */
if(!s->budget--) { s->failed_pc=0x0c0b8614u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b86aeu,2);
goto P_0c0b8616;
P_0c0b8616: /* original 4e0b, guest PC 0x0c0b8616 */
if(!s->budget--) { s->failed_pc=0x0c0b8616u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b861au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b861au) { target=s->pc; goto dispatch; }
goto P_0c0b861a;
P_0c0b8618: /* original 05de, guest PC 0x0c0b8618 */
if(!s->budget--) { s->failed_pc=0x0c0b8618u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b861a;
P_0c0b861a: /* original 944b, guest PC 0x0c0b861a */
if(!s->budget--) { s->failed_pc=0x0c0b861au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b86b4u,2);
goto P_0c0b861c;
P_0c0b861c: /* original 9049, guest PC 0x0c0b861c */
if(!s->budget--) { s->failed_pc=0x0c0b861cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b86b2u,2);
goto P_0c0b861e;
P_0c0b861e: /* original 4e0b, guest PC 0x0c0b861e */
if(!s->budget--) { s->failed_pc=0x0c0b861eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8622u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8622u) { target=s->pc; goto dispatch; }
goto P_0c0b8622;
P_0c0b8620: /* original 05de, guest PC 0x0c0b8620 */
if(!s->budget--) { s->failed_pc=0x0c0b8620u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8622;
P_0c0b8622: /* original 9948, guest PC 0x0c0b8622 */
if(!s->budget--) { s->failed_pc=0x0c0b8622u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b86b6u,2);
goto P_0c0b8624;
P_0c0b8624: /* original 9448, guest PC 0x0c0b8624 */
if(!s->budget--) { s->failed_pc=0x0c0b8624u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b86b8u,2);
goto P_0c0b8626;
P_0c0b8626: /* original 39dc, guest PC 0x0c0b8626 */
if(!s->budget--) { s->failed_pc=0x0c0b8626u; return 0; }
r[9]+=r[13];
goto P_0c0b8628;
P_0c0b8628: /* original 4e0b, guest PC 0x0c0b8628 */
if(!s->budget--) { s->failed_pc=0x0c0b8628u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b862cu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b862cu) { target=s->pc; goto dispatch; }
goto P_0c0b862c;
P_0c0b862a: /* original 6592, guest PC 0x0c0b862a */
if(!s->budget--) { s->failed_pc=0x0c0b862au; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b862c;
P_0c0b862c: /* original 9445, guest PC 0x0c0b862c */
if(!s->budget--) { s->failed_pc=0x0c0b862cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b86bau,2);
goto P_0c0b862e;
P_0c0b862e: /* original 4e0b, guest PC 0x0c0b862e */
if(!s->budget--) { s->failed_pc=0x0c0b862eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8632u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8632u) { target=s->pc; goto dispatch; }
goto P_0c0b8632;
P_0c0b8630: /* original 6592, guest PC 0x0c0b8630 */
if(!s->budget--) { s->failed_pc=0x0c0b8630u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b8632;
P_0c0b8632: /* original 9443, guest PC 0x0c0b8632 */
if(!s->budget--) { s->failed_pc=0x0c0b8632u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b86bcu,2);
goto P_0c0b8634;
P_0c0b8634: /* original 4e0b, guest PC 0x0c0b8634 */
if(!s->budget--) { s->failed_pc=0x0c0b8634u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8638u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8638u) { target=s->pc; goto dispatch; }
goto P_0c0b8638;
P_0c0b8636: /* original 6592, guest PC 0x0c0b8636 */
if(!s->budget--) { s->failed_pc=0x0c0b8636u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b8638;
P_0c0b8638: /* original 9441, guest PC 0x0c0b8638 */
if(!s->budget--) { s->failed_pc=0x0c0b8638u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b86beu,2);
goto P_0c0b863a;
P_0c0b863a: /* original 4e0b, guest PC 0x0c0b863a */
if(!s->budget--) { s->failed_pc=0x0c0b863au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b863eu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b863eu) { target=s->pc; goto dispatch; }
goto P_0c0b863e;
P_0c0b863c: /* original 6592, guest PC 0x0c0b863c */
if(!s->budget--) { s->failed_pc=0x0c0b863cu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b863e;
P_0c0b863e: /* original 9c3f, guest PC 0x0c0b863e */
if(!s->budget--) { s->failed_pc=0x0c0b863eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b86c0u,2);
goto P_0c0b8640;
P_0c0b8640: /* original 943f, guest PC 0x0c0b8640 */
if(!s->budget--) { s->failed_pc=0x0c0b8640u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b86c2u,2);
goto P_0c0b8642;
P_0c0b8642: /* original 3cdc, guest PC 0x0c0b8642 */
if(!s->budget--) { s->failed_pc=0x0c0b8642u; return 0; }
r[12]+=r[13];
goto P_0c0b8644;
P_0c0b8644: /* original 4e0b, guest PC 0x0c0b8644 */
if(!s->budget--) { s->failed_pc=0x0c0b8644u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8648u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8648u) { target=s->pc; goto dispatch; }
goto P_0c0b8648;
P_0c0b8646: /* original 65c2, guest PC 0x0c0b8646 */
if(!s->budget--) { s->failed_pc=0x0c0b8646u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b8648;
P_0c0b8648: /* original 943c, guest PC 0x0c0b8648 */
if(!s->budget--) { s->failed_pc=0x0c0b8648u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b86c4u,2);
goto P_0c0b864a;
P_0c0b864a: /* original 4e0b, guest PC 0x0c0b864a */
if(!s->budget--) { s->failed_pc=0x0c0b864au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b864eu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b864eu) { target=s->pc; goto dispatch; }
goto P_0c0b864e;
P_0c0b864c: /* original 65c2, guest PC 0x0c0b864c */
if(!s->budget--) { s->failed_pc=0x0c0b864cu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b864e;
P_0c0b864e: /* original 943a, guest PC 0x0c0b864e */
if(!s->budget--) { s->failed_pc=0x0c0b864eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b86c6u,2);
goto P_0c0b8650;
P_0c0b8650: /* original 4e0b, guest PC 0x0c0b8650 */
if(!s->budget--) { s->failed_pc=0x0c0b8650u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8654u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8654u) { target=s->pc; goto dispatch; }
goto P_0c0b8654;
P_0c0b8652: /* original 65c2, guest PC 0x0c0b8652 */
if(!s->budget--) { s->failed_pc=0x0c0b8652u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b8654;
P_0c0b8654: /* original 9438, guest PC 0x0c0b8654 */
if(!s->budget--) { s->failed_pc=0x0c0b8654u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b86c8u,2);
goto P_0c0b8656;
P_0c0b8656: /* original 4e0b, guest PC 0x0c0b8656 */
if(!s->budget--) { s->failed_pc=0x0c0b8656u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b865au;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b865au) { target=s->pc; goto dispatch; }
goto P_0c0b865a;
P_0c0b8658: /* original 65c2, guest PC 0x0c0b8658 */
if(!s->budget--) { s->failed_pc=0x0c0b8658u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b865a;
P_0c0b865a: /* original 9b36, guest PC 0x0c0b865a */
if(!s->budget--) { s->failed_pc=0x0c0b865au; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b86cau,2);
goto P_0c0b865c;
P_0c0b865c: /* original 3bdc, guest PC 0x0c0b865c */
if(!s->budget--) { s->failed_pc=0x0c0b865cu; return 0; }
r[11]+=r[13];
goto P_0c0b865e;
P_0c0b865e: /* original a037, guest PC 0x0c0b865e */
if(!s->budget--) { s->failed_pc=0x0c0b865eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b86d0;
P_0c0b8660: /* original 65b2, guest PC 0x0c0b8660 */
if(!s->budget--) { s->failed_pc=0x0c0b8660u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0b8662u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b8662u; return 0; } return 1;
P_0c0b86d0: /* original 94ab, guest PC 0x0c0b86d0 */
if(!s->budget--) { s->failed_pc=0x0c0b86d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b882au,2);
goto P_0c0b86d2;
P_0c0b86d2: /* original 4e0b, guest PC 0x0c0b86d2 */
if(!s->budget--) { s->failed_pc=0x0c0b86d2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b86d6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b86d6u) { target=s->pc; goto dispatch; }
goto P_0c0b86d6;
P_0c0b86d4: /* original 0009, guest PC 0x0c0b86d4 */
if(!s->budget--) { s->failed_pc=0x0c0b86d4u; return 0; }
goto P_0c0b86d6;
P_0c0b86d6: /* original 94a9, guest PC 0x0c0b86d6 */
if(!s->budget--) { s->failed_pc=0x0c0b86d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b882cu,2);
goto P_0c0b86d8;
P_0c0b86d8: /* original 4e0b, guest PC 0x0c0b86d8 */
if(!s->budget--) { s->failed_pc=0x0c0b86d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b86dcu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b86dcu) { target=s->pc; goto dispatch; }
goto P_0c0b86dc;
P_0c0b86da: /* original 65b2, guest PC 0x0c0b86da */
if(!s->budget--) { s->failed_pc=0x0c0b86dau; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b86dc;
P_0c0b86dc: /* original 94a7, guest PC 0x0c0b86dc */
if(!s->budget--) { s->failed_pc=0x0c0b86dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b882eu,2);
goto P_0c0b86de;
P_0c0b86de: /* original 4e0b, guest PC 0x0c0b86de */
if(!s->budget--) { s->failed_pc=0x0c0b86deu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b86e2u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b86e2u) { target=s->pc; goto dispatch; }
goto P_0c0b86e2;
P_0c0b86e0: /* original 65b2, guest PC 0x0c0b86e0 */
if(!s->budget--) { s->failed_pc=0x0c0b86e0u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b86e2;
P_0c0b86e2: /* original 94a5, guest PC 0x0c0b86e2 */
if(!s->budget--) { s->failed_pc=0x0c0b86e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8830u,2);
goto P_0c0b86e4;
P_0c0b86e4: /* original 4e0b, guest PC 0x0c0b86e4 */
if(!s->budget--) { s->failed_pc=0x0c0b86e4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b86e8u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b86e8u) { target=s->pc; goto dispatch; }
goto P_0c0b86e8;
P_0c0b86e6: /* original 65b2, guest PC 0x0c0b86e6 */
if(!s->budget--) { s->failed_pc=0x0c0b86e6u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b86e8;
P_0c0b86e8: /* original 9aa3, guest PC 0x0c0b86e8 */
if(!s->budget--) { s->failed_pc=0x0c0b86e8u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8832u,2);
goto P_0c0b86ea;
P_0c0b86ea: /* original 94a3, guest PC 0x0c0b86ea */
if(!s->budget--) { s->failed_pc=0x0c0b86eau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8834u,2);
goto P_0c0b86ec;
P_0c0b86ec: /* original 3adc, guest PC 0x0c0b86ec */
if(!s->budget--) { s->failed_pc=0x0c0b86ecu; return 0; }
r[10]+=r[13];
goto P_0c0b86ee;
P_0c0b86ee: /* original 4e0b, guest PC 0x0c0b86ee */
if(!s->budget--) { s->failed_pc=0x0c0b86eeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b86f2u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b86f2u) { target=s->pc; goto dispatch; }
goto P_0c0b86f2;
P_0c0b86f0: /* original 65a2, guest PC 0x0c0b86f0 */
if(!s->budget--) { s->failed_pc=0x0c0b86f0u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b86f2;
P_0c0b86f2: /* original 94a0, guest PC 0x0c0b86f2 */
if(!s->budget--) { s->failed_pc=0x0c0b86f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8836u,2);
goto P_0c0b86f4;
P_0c0b86f4: /* original 4e0b, guest PC 0x0c0b86f4 */
if(!s->budget--) { s->failed_pc=0x0c0b86f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b86f8u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b86f8u) { target=s->pc; goto dispatch; }
goto P_0c0b86f8;
P_0c0b86f6: /* original 65a2, guest PC 0x0c0b86f6 */
if(!s->budget--) { s->failed_pc=0x0c0b86f6u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b86f8;
P_0c0b86f8: /* original 949e, guest PC 0x0c0b86f8 */
if(!s->budget--) { s->failed_pc=0x0c0b86f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8838u,2);
goto P_0c0b86fa;
P_0c0b86fa: /* original 4e0b, guest PC 0x0c0b86fa */
if(!s->budget--) { s->failed_pc=0x0c0b86fau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b86feu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b86feu) { target=s->pc; goto dispatch; }
goto P_0c0b86fe;
P_0c0b86fc: /* original 65a2, guest PC 0x0c0b86fc */
if(!s->budget--) { s->failed_pc=0x0c0b86fcu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b86fe;
P_0c0b86fe: /* original 949c, guest PC 0x0c0b86fe */
if(!s->budget--) { s->failed_pc=0x0c0b86feu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b883au,2);
goto P_0c0b8700;
P_0c0b8700: /* original 4e0b, guest PC 0x0c0b8700 */
if(!s->budget--) { s->failed_pc=0x0c0b8700u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8704u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8704u) { target=s->pc; goto dispatch; }
goto P_0c0b8704;
P_0c0b8702: /* original 65a2, guest PC 0x0c0b8702 */
if(!s->budget--) { s->failed_pc=0x0c0b8702u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b8704;
P_0c0b8704: /* original 949a, guest PC 0x0c0b8704 */
if(!s->budget--) { s->failed_pc=0x0c0b8704u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b883cu,2);
goto P_0c0b8706;
P_0c0b8706: /* original 65f2, guest PC 0x0c0b8706 */
if(!s->budget--) { s->failed_pc=0x0c0b8706u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b8708;
P_0c0b8708: /* original 4e0b, guest PC 0x0c0b8708 */
if(!s->budget--) { s->failed_pc=0x0c0b8708u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b870cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b870cu) { target=s->pc; goto dispatch; }
goto P_0c0b870c;
P_0c0b870a: /* original 6552, guest PC 0x0c0b870a */
if(!s->budget--) { s->failed_pc=0x0c0b870au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b870c;
P_0c0b870c: /* original 9497, guest PC 0x0c0b870c */
if(!s->budget--) { s->failed_pc=0x0c0b870cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b883eu,2);
goto P_0c0b870e;
P_0c0b870e: /* original 55f1, guest PC 0x0c0b870e */
if(!s->budget--) { s->failed_pc=0x0c0b870eu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0b8710;
P_0c0b8710: /* original 4e0b, guest PC 0x0c0b8710 */
if(!s->budget--) { s->failed_pc=0x0c0b8710u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8714u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8714u) { target=s->pc; goto dispatch; }
goto P_0c0b8714;
P_0c0b8712: /* original 6552, guest PC 0x0c0b8712 */
if(!s->budget--) { s->failed_pc=0x0c0b8712u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8714;
P_0c0b8714: /* original 9494, guest PC 0x0c0b8714 */
if(!s->budget--) { s->failed_pc=0x0c0b8714u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8840u,2);
goto P_0c0b8716;
P_0c0b8716: /* original 4e0b, guest PC 0x0c0b8716 */
if(!s->budget--) { s->failed_pc=0x0c0b8716u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b871au;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b871au) { target=s->pc; goto dispatch; }
goto P_0c0b871a;
P_0c0b8718: /* original 6592, guest PC 0x0c0b8718 */
if(!s->budget--) { s->failed_pc=0x0c0b8718u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b871a;
P_0c0b871a: /* original 9492, guest PC 0x0c0b871a */
if(!s->budget--) { s->failed_pc=0x0c0b871au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8842u,2);
goto P_0c0b871c;
P_0c0b871c: /* original 4e0b, guest PC 0x0c0b871c */
if(!s->budget--) { s->failed_pc=0x0c0b871cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8720u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8720u) { target=s->pc; goto dispatch; }
goto P_0c0b8720;
P_0c0b871e: /* original 6592, guest PC 0x0c0b871e */
if(!s->budget--) { s->failed_pc=0x0c0b871eu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b8720;
P_0c0b8720: /* original 9490, guest PC 0x0c0b8720 */
if(!s->budget--) { s->failed_pc=0x0c0b8720u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8844u,2);
goto P_0c0b8722;
P_0c0b8722: /* original 4e0b, guest PC 0x0c0b8722 */
if(!s->budget--) { s->failed_pc=0x0c0b8722u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8726u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8726u) { target=s->pc; goto dispatch; }
goto P_0c0b8726;
P_0c0b8724: /* original 6592, guest PC 0x0c0b8724 */
if(!s->budget--) { s->failed_pc=0x0c0b8724u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b8726;
P_0c0b8726: /* original 948e, guest PC 0x0c0b8726 */
if(!s->budget--) { s->failed_pc=0x0c0b8726u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8846u,2);
goto P_0c0b8728;
P_0c0b8728: /* original 4e0b, guest PC 0x0c0b8728 */
if(!s->budget--) { s->failed_pc=0x0c0b8728u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b872cu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b872cu) { target=s->pc; goto dispatch; }
goto P_0c0b872c;
P_0c0b872a: /* original 6592, guest PC 0x0c0b872a */
if(!s->budget--) { s->failed_pc=0x0c0b872au; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b872c;
P_0c0b872c: /* original 948c, guest PC 0x0c0b872c */
if(!s->budget--) { s->failed_pc=0x0c0b872cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8848u,2);
goto P_0c0b872e;
P_0c0b872e: /* original 4e0b, guest PC 0x0c0b872e */
if(!s->budget--) { s->failed_pc=0x0c0b872eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8732u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8732u) { target=s->pc; goto dispatch; }
goto P_0c0b8732;
P_0c0b8730: /* original 65c2, guest PC 0x0c0b8730 */
if(!s->budget--) { s->failed_pc=0x0c0b8730u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b8732;
P_0c0b8732: /* original 948a, guest PC 0x0c0b8732 */
if(!s->budget--) { s->failed_pc=0x0c0b8732u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b884au,2);
goto P_0c0b8734;
P_0c0b8734: /* original 4e0b, guest PC 0x0c0b8734 */
if(!s->budget--) { s->failed_pc=0x0c0b8734u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8738u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8738u) { target=s->pc; goto dispatch; }
goto P_0c0b8738;
P_0c0b8736: /* original 65c2, guest PC 0x0c0b8736 */
if(!s->budget--) { s->failed_pc=0x0c0b8736u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b8738;
P_0c0b8738: /* original 9488, guest PC 0x0c0b8738 */
if(!s->budget--) { s->failed_pc=0x0c0b8738u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b884cu,2);
goto P_0c0b873a;
P_0c0b873a: /* original 4e0b, guest PC 0x0c0b873a */
if(!s->budget--) { s->failed_pc=0x0c0b873au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b873eu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b873eu) { target=s->pc; goto dispatch; }
goto P_0c0b873e;
P_0c0b873c: /* original 65c2, guest PC 0x0c0b873c */
if(!s->budget--) { s->failed_pc=0x0c0b873cu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b873e;
P_0c0b873e: /* original 9486, guest PC 0x0c0b873e */
if(!s->budget--) { s->failed_pc=0x0c0b873eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b884eu,2);
goto P_0c0b8740;
P_0c0b8740: /* original 4e0b, guest PC 0x0c0b8740 */
if(!s->budget--) { s->failed_pc=0x0c0b8740u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8744u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8744u) { target=s->pc; goto dispatch; }
goto P_0c0b8744;
P_0c0b8742: /* original 65c2, guest PC 0x0c0b8742 */
if(!s->budget--) { s->failed_pc=0x0c0b8742u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b8744;
P_0c0b8744: /* original 9484, guest PC 0x0c0b8744 */
if(!s->budget--) { s->failed_pc=0x0c0b8744u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8850u,2);
goto P_0c0b8746;
P_0c0b8746: /* original 4e0b, guest PC 0x0c0b8746 */
if(!s->budget--) { s->failed_pc=0x0c0b8746u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b874au;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b874au) { target=s->pc; goto dispatch; }
goto P_0c0b874a;
P_0c0b8748: /* original 65b2, guest PC 0x0c0b8748 */
if(!s->budget--) { s->failed_pc=0x0c0b8748u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b874a;
P_0c0b874a: /* original 9482, guest PC 0x0c0b874a */
if(!s->budget--) { s->failed_pc=0x0c0b874au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8852u,2);
goto P_0c0b874c;
P_0c0b874c: /* original 4e0b, guest PC 0x0c0b874c */
if(!s->budget--) { s->failed_pc=0x0c0b874cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8750u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8750u) { target=s->pc; goto dispatch; }
goto P_0c0b8750;
P_0c0b874e: /* original 65b2, guest PC 0x0c0b874e */
if(!s->budget--) { s->failed_pc=0x0c0b874eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b8750;
P_0c0b8750: /* original 9480, guest PC 0x0c0b8750 */
if(!s->budget--) { s->failed_pc=0x0c0b8750u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8854u,2);
goto P_0c0b8752;
P_0c0b8752: /* original 4e0b, guest PC 0x0c0b8752 */
if(!s->budget--) { s->failed_pc=0x0c0b8752u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8756u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8756u) { target=s->pc; goto dispatch; }
goto P_0c0b8756;
P_0c0b8754: /* original 65b2, guest PC 0x0c0b8754 */
if(!s->budget--) { s->failed_pc=0x0c0b8754u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b8756;
P_0c0b8756: /* original 947e, guest PC 0x0c0b8756 */
if(!s->budget--) { s->failed_pc=0x0c0b8756u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8856u,2);
goto P_0c0b8758;
P_0c0b8758: /* original 4e0b, guest PC 0x0c0b8758 */
if(!s->budget--) { s->failed_pc=0x0c0b8758u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b875cu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b875cu) { target=s->pc; goto dispatch; }
goto P_0c0b875c;
P_0c0b875a: /* original 65b2, guest PC 0x0c0b875a */
if(!s->budget--) { s->failed_pc=0x0c0b875au; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b875c;
P_0c0b875c: /* original 947c, guest PC 0x0c0b875c */
if(!s->budget--) { s->failed_pc=0x0c0b875cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8858u,2);
goto P_0c0b875e;
P_0c0b875e: /* original 4e0b, guest PC 0x0c0b875e */
if(!s->budget--) { s->failed_pc=0x0c0b875eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8762u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8762u) { target=s->pc; goto dispatch; }
goto P_0c0b8762;
P_0c0b8760: /* original 65a2, guest PC 0x0c0b8760 */
if(!s->budget--) { s->failed_pc=0x0c0b8760u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b8762;
P_0c0b8762: /* original 947a, guest PC 0x0c0b8762 */
if(!s->budget--) { s->failed_pc=0x0c0b8762u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b885au,2);
goto P_0c0b8764;
P_0c0b8764: /* original 4e0b, guest PC 0x0c0b8764 */
if(!s->budget--) { s->failed_pc=0x0c0b8764u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8768u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8768u) { target=s->pc; goto dispatch; }
goto P_0c0b8768;
P_0c0b8766: /* original 65a2, guest PC 0x0c0b8766 */
if(!s->budget--) { s->failed_pc=0x0c0b8766u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b8768;
P_0c0b8768: /* original 9478, guest PC 0x0c0b8768 */
if(!s->budget--) { s->failed_pc=0x0c0b8768u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b885cu,2);
goto P_0c0b876a;
P_0c0b876a: /* original 4e0b, guest PC 0x0c0b876a */
if(!s->budget--) { s->failed_pc=0x0c0b876au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b876eu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b876eu) { target=s->pc; goto dispatch; }
goto P_0c0b876e;
P_0c0b876c: /* original 65a2, guest PC 0x0c0b876c */
if(!s->budget--) { s->failed_pc=0x0c0b876cu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b876e;
P_0c0b876e: /* original 9476, guest PC 0x0c0b876e */
if(!s->budget--) { s->failed_pc=0x0c0b876eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b885eu,2);
goto P_0c0b8770;
P_0c0b8770: /* original 4e0b, guest PC 0x0c0b8770 */
if(!s->budget--) { s->failed_pc=0x0c0b8770u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8774u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8774u) { target=s->pc; goto dispatch; }
goto P_0c0b8774;
P_0c0b8772: /* original 65a2, guest PC 0x0c0b8772 */
if(!s->budget--) { s->failed_pc=0x0c0b8772u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b8774;
P_0c0b8774: /* original 9574, guest PC 0x0c0b8774 */
if(!s->budget--) { s->failed_pc=0x0c0b8774u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8860u,2);
goto P_0c0b8776;
P_0c0b8776: /* original 35dc, guest PC 0x0c0b8776 */
if(!s->budget--) { s->failed_pc=0x0c0b8776u; return 0; }
r[5]+=r[13];
goto P_0c0b8778;
P_0c0b8778: /* original 2f52, guest PC 0x0c0b8778 */
if(!s->budget--) { s->failed_pc=0x0c0b8778u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b877a;
P_0c0b877a: /* original 9472, guest PC 0x0c0b877a */
if(!s->budget--) { s->failed_pc=0x0c0b877au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8862u,2);
goto P_0c0b877c;
P_0c0b877c: /* original 4e0b, guest PC 0x0c0b877c */
if(!s->budget--) { s->failed_pc=0x0c0b877cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8780u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8780u) { target=s->pc; goto dispatch; }
goto P_0c0b8780;
P_0c0b877e: /* original 6552, guest PC 0x0c0b877e */
if(!s->budget--) { s->failed_pc=0x0c0b877eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8780;
P_0c0b8780: /* original 9470, guest PC 0x0c0b8780 */
if(!s->budget--) { s->failed_pc=0x0c0b8780u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8864u,2);
goto P_0c0b8782;
P_0c0b8782: /* original 65f2, guest PC 0x0c0b8782 */
if(!s->budget--) { s->failed_pc=0x0c0b8782u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b8784;
P_0c0b8784: /* original 4e0b, guest PC 0x0c0b8784 */
if(!s->budget--) { s->failed_pc=0x0c0b8784u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8788u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8788u) { target=s->pc; goto dispatch; }
goto P_0c0b8788;
P_0c0b8786: /* original 6552, guest PC 0x0c0b8786 */
if(!s->budget--) { s->failed_pc=0x0c0b8786u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8788;
P_0c0b8788: /* original 956d, guest PC 0x0c0b8788 */
if(!s->budget--) { s->failed_pc=0x0c0b8788u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8866u,2);
goto P_0c0b878a;
P_0c0b878a: /* original 35dc, guest PC 0x0c0b878a */
if(!s->budget--) { s->failed_pc=0x0c0b878au; return 0; }
r[5]+=r[13];
goto P_0c0b878c;
P_0c0b878c: /* original 2f52, guest PC 0x0c0b878c */
if(!s->budget--) { s->failed_pc=0x0c0b878cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b878e;
P_0c0b878e: /* original 946b, guest PC 0x0c0b878e */
if(!s->budget--) { s->failed_pc=0x0c0b878eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8868u,2);
goto P_0c0b8790;
P_0c0b8790: /* original 4e0b, guest PC 0x0c0b8790 */
if(!s->budget--) { s->failed_pc=0x0c0b8790u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8794u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8794u) { target=s->pc; goto dispatch; }
goto P_0c0b8794;
P_0c0b8792: /* original 6552, guest PC 0x0c0b8792 */
if(!s->budget--) { s->failed_pc=0x0c0b8792u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8794;
P_0c0b8794: /* original 9469, guest PC 0x0c0b8794 */
if(!s->budget--) { s->failed_pc=0x0c0b8794u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b886au,2);
goto P_0c0b8796;
P_0c0b8796: /* original 65f2, guest PC 0x0c0b8796 */
if(!s->budget--) { s->failed_pc=0x0c0b8796u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b8798;
P_0c0b8798: /* original 4e0b, guest PC 0x0c0b8798 */
if(!s->budget--) { s->failed_pc=0x0c0b8798u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b879cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b879cu) { target=s->pc; goto dispatch; }
goto P_0c0b879c;
P_0c0b879a: /* original 6552, guest PC 0x0c0b879a */
if(!s->budget--) { s->failed_pc=0x0c0b879au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b879c;
P_0c0b879c: /* original 9467, guest PC 0x0c0b879c */
if(!s->budget--) { s->failed_pc=0x0c0b879cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b886eu,2);
goto P_0c0b879e;
P_0c0b879e: /* original 9065, guest PC 0x0c0b879e */
if(!s->budget--) { s->failed_pc=0x0c0b879eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b886cu,2);
goto P_0c0b87a0;
P_0c0b87a0: /* original 4e0b, guest PC 0x0c0b87a0 */
if(!s->budget--) { s->failed_pc=0x0c0b87a0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b87a4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b87a4u) { target=s->pc; goto dispatch; }
goto P_0c0b87a4;
P_0c0b87a2: /* original 05de, guest PC 0x0c0b87a2 */
if(!s->budget--) { s->failed_pc=0x0c0b87a2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b87a4;
P_0c0b87a4: /* original 9564, guest PC 0x0c0b87a4 */
if(!s->budget--) { s->failed_pc=0x0c0b87a4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8870u,2);
goto P_0c0b87a6;
P_0c0b87a6: /* original 35dc, guest PC 0x0c0b87a6 */
if(!s->budget--) { s->failed_pc=0x0c0b87a6u; return 0; }
r[5]+=r[13];
goto P_0c0b87a8;
P_0c0b87a8: /* original 2f52, guest PC 0x0c0b87a8 */
if(!s->budget--) { s->failed_pc=0x0c0b87a8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b87aa;
P_0c0b87aa: /* original 9462, guest PC 0x0c0b87aa */
if(!s->budget--) { s->failed_pc=0x0c0b87aau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8872u,2);
goto P_0c0b87ac;
P_0c0b87ac: /* original 4e0b, guest PC 0x0c0b87ac */
if(!s->budget--) { s->failed_pc=0x0c0b87acu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b87b0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b87b0u) { target=s->pc; goto dispatch; }
goto P_0c0b87b0;
P_0c0b87ae: /* original 6552, guest PC 0x0c0b87ae */
if(!s->budget--) { s->failed_pc=0x0c0b87aeu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b87b0;
P_0c0b87b0: /* original 9460, guest PC 0x0c0b87b0 */
if(!s->budget--) { s->failed_pc=0x0c0b87b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8874u,2);
goto P_0c0b87b2;
P_0c0b87b2: /* original 65f2, guest PC 0x0c0b87b2 */
if(!s->budget--) { s->failed_pc=0x0c0b87b2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b87b4;
P_0c0b87b4: /* original 4e0b, guest PC 0x0c0b87b4 */
if(!s->budget--) { s->failed_pc=0x0c0b87b4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b87b8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b87b8u) { target=s->pc; goto dispatch; }
goto P_0c0b87b8;
P_0c0b87b6: /* original 6552, guest PC 0x0c0b87b6 */
if(!s->budget--) { s->failed_pc=0x0c0b87b6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b87b8;
P_0c0b87b8: /* original 945e, guest PC 0x0c0b87b8 */
if(!s->budget--) { s->failed_pc=0x0c0b87b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8878u,2);
goto P_0c0b87ba;
P_0c0b87ba: /* original 905c, guest PC 0x0c0b87ba */
if(!s->budget--) { s->failed_pc=0x0c0b87bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8876u,2);
goto P_0c0b87bc;
P_0c0b87bc: /* original 4e0b, guest PC 0x0c0b87bc */
if(!s->budget--) { s->failed_pc=0x0c0b87bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b87c0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b87c0u) { target=s->pc; goto dispatch; }
goto P_0c0b87c0;
P_0c0b87be: /* original 05de, guest PC 0x0c0b87be */
if(!s->budget--) { s->failed_pc=0x0c0b87beu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b87c0;
P_0c0b87c0: /* original 955b, guest PC 0x0c0b87c0 */
if(!s->budget--) { s->failed_pc=0x0c0b87c0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b887au,2);
goto P_0c0b87c2;
P_0c0b87c2: /* original 35dc, guest PC 0x0c0b87c2 */
if(!s->budget--) { s->failed_pc=0x0c0b87c2u; return 0; }
r[5]+=r[13];
goto P_0c0b87c4;
P_0c0b87c4: /* original 2f52, guest PC 0x0c0b87c4 */
if(!s->budget--) { s->failed_pc=0x0c0b87c4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b87c6;
P_0c0b87c6: /* original 9459, guest PC 0x0c0b87c6 */
if(!s->budget--) { s->failed_pc=0x0c0b87c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b887cu,2);
goto P_0c0b87c8;
P_0c0b87c8: /* original 4e0b, guest PC 0x0c0b87c8 */
if(!s->budget--) { s->failed_pc=0x0c0b87c8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b87ccu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b87ccu) { target=s->pc; goto dispatch; }
goto P_0c0b87cc;
P_0c0b87ca: /* original 6552, guest PC 0x0c0b87ca */
if(!s->budget--) { s->failed_pc=0x0c0b87cau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b87cc;
P_0c0b87cc: /* original 9457, guest PC 0x0c0b87cc */
if(!s->budget--) { s->failed_pc=0x0c0b87ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b887eu,2);
goto P_0c0b87ce;
P_0c0b87ce: /* original 65f2, guest PC 0x0c0b87ce */
if(!s->budget--) { s->failed_pc=0x0c0b87ceu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b87d0;
P_0c0b87d0: /* original 4e0b, guest PC 0x0c0b87d0 */
if(!s->budget--) { s->failed_pc=0x0c0b87d0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b87d4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b87d4u) { target=s->pc; goto dispatch; }
goto P_0c0b87d4;
P_0c0b87d2: /* original 6552, guest PC 0x0c0b87d2 */
if(!s->budget--) { s->failed_pc=0x0c0b87d2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b87d4;
P_0c0b87d4: /* original 9455, guest PC 0x0c0b87d4 */
if(!s->budget--) { s->failed_pc=0x0c0b87d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8882u,2);
goto P_0c0b87d6;
P_0c0b87d6: /* original 9053, guest PC 0x0c0b87d6 */
if(!s->budget--) { s->failed_pc=0x0c0b87d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8880u,2);
goto P_0c0b87d8;
P_0c0b87d8: /* original 4e0b, guest PC 0x0c0b87d8 */
if(!s->budget--) { s->failed_pc=0x0c0b87d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b87dcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b87dcu) { target=s->pc; goto dispatch; }
goto P_0c0b87dc;
P_0c0b87da: /* original 05de, guest PC 0x0c0b87da */
if(!s->budget--) { s->failed_pc=0x0c0b87dau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b87dc;
P_0c0b87dc: /* original 9552, guest PC 0x0c0b87dc */
if(!s->budget--) { s->failed_pc=0x0c0b87dcu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8884u,2);
goto P_0c0b87de;
P_0c0b87de: /* original 35dc, guest PC 0x0c0b87de */
if(!s->budget--) { s->failed_pc=0x0c0b87deu; return 0; }
r[5]+=r[13];
goto P_0c0b87e0;
P_0c0b87e0: /* original 2f52, guest PC 0x0c0b87e0 */
if(!s->budget--) { s->failed_pc=0x0c0b87e0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b87e2;
P_0c0b87e2: /* original 9450, guest PC 0x0c0b87e2 */
if(!s->budget--) { s->failed_pc=0x0c0b87e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8886u,2);
goto P_0c0b87e4;
P_0c0b87e4: /* original 4e0b, guest PC 0x0c0b87e4 */
if(!s->budget--) { s->failed_pc=0x0c0b87e4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b87e8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b87e8u) { target=s->pc; goto dispatch; }
goto P_0c0b87e8;
P_0c0b87e6: /* original 6552, guest PC 0x0c0b87e6 */
if(!s->budget--) { s->failed_pc=0x0c0b87e6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b87e8;
P_0c0b87e8: /* original 944e, guest PC 0x0c0b87e8 */
if(!s->budget--) { s->failed_pc=0x0c0b87e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8888u,2);
goto P_0c0b87ea;
P_0c0b87ea: /* original 65f2, guest PC 0x0c0b87ea */
if(!s->budget--) { s->failed_pc=0x0c0b87eau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b87ec;
P_0c0b87ec: /* original 4e0b, guest PC 0x0c0b87ec */
if(!s->budget--) { s->failed_pc=0x0c0b87ecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b87f0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b87f0u) { target=s->pc; goto dispatch; }
goto P_0c0b87f0;
P_0c0b87ee: /* original 6552, guest PC 0x0c0b87ee */
if(!s->budget--) { s->failed_pc=0x0c0b87eeu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b87f0;
P_0c0b87f0: /* original 954b, guest PC 0x0c0b87f0 */
if(!s->budget--) { s->failed_pc=0x0c0b87f0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b888au,2);
goto P_0c0b87f2;
P_0c0b87f2: /* original 35dc, guest PC 0x0c0b87f2 */
if(!s->budget--) { s->failed_pc=0x0c0b87f2u; return 0; }
r[5]+=r[13];
goto P_0c0b87f4;
P_0c0b87f4: /* original 2f52, guest PC 0x0c0b87f4 */
if(!s->budget--) { s->failed_pc=0x0c0b87f4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b87f6;
P_0c0b87f6: /* original 9449, guest PC 0x0c0b87f6 */
if(!s->budget--) { s->failed_pc=0x0c0b87f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b888cu,2);
goto P_0c0b87f8;
P_0c0b87f8: /* original 4e0b, guest PC 0x0c0b87f8 */
if(!s->budget--) { s->failed_pc=0x0c0b87f8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b87fcu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b87fcu) { target=s->pc; goto dispatch; }
goto P_0c0b87fc;
P_0c0b87fa: /* original 6552, guest PC 0x0c0b87fa */
if(!s->budget--) { s->failed_pc=0x0c0b87fau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b87fc;
P_0c0b87fc: /* original 9447, guest PC 0x0c0b87fc */
if(!s->budget--) { s->failed_pc=0x0c0b87fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b888eu,2);
goto P_0c0b87fe;
P_0c0b87fe: /* original 65f2, guest PC 0x0c0b87fe */
if(!s->budget--) { s->failed_pc=0x0c0b87feu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b8800;
P_0c0b8800: /* original 4e0b, guest PC 0x0c0b8800 */
if(!s->budget--) { s->failed_pc=0x0c0b8800u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8804u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8804u) { target=s->pc; goto dispatch; }
goto P_0c0b8804;
P_0c0b8802: /* original 6552, guest PC 0x0c0b8802 */
if(!s->budget--) { s->failed_pc=0x0c0b8802u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8804;
P_0c0b8804: /* original 9445, guest PC 0x0c0b8804 */
if(!s->budget--) { s->failed_pc=0x0c0b8804u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8892u,2);
goto P_0c0b8806;
P_0c0b8806: /* original 9043, guest PC 0x0c0b8806 */
if(!s->budget--) { s->failed_pc=0x0c0b8806u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8890u,2);
goto P_0c0b8808;
P_0c0b8808: /* original 4e0b, guest PC 0x0c0b8808 */
if(!s->budget--) { s->failed_pc=0x0c0b8808u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b880cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b880cu) { target=s->pc; goto dispatch; }
goto P_0c0b880c;
P_0c0b880a: /* original 05de, guest PC 0x0c0b880a */
if(!s->budget--) { s->failed_pc=0x0c0b880au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b880c;
P_0c0b880c: /* original 9443, guest PC 0x0c0b880c */
if(!s->budget--) { s->failed_pc=0x0c0b880cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8896u,2);
goto P_0c0b880e;
P_0c0b880e: /* original 9041, guest PC 0x0c0b880e */
if(!s->budget--) { s->failed_pc=0x0c0b880eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8894u,2);
goto P_0c0b8810;
P_0c0b8810: /* original 4e0b, guest PC 0x0c0b8810 */
if(!s->budget--) { s->failed_pc=0x0c0b8810u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8814u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8814u) { target=s->pc; goto dispatch; }
goto P_0c0b8814;
P_0c0b8812: /* original 05de, guest PC 0x0c0b8812 */
if(!s->budget--) { s->failed_pc=0x0c0b8812u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8814;
P_0c0b8814: /* original 9441, guest PC 0x0c0b8814 */
if(!s->budget--) { s->failed_pc=0x0c0b8814u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b889au,2);
goto P_0c0b8816;
P_0c0b8816: /* original 903f, guest PC 0x0c0b8816 */
if(!s->budget--) { s->failed_pc=0x0c0b8816u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8898u,2);
goto P_0c0b8818;
P_0c0b8818: /* original 4e0b, guest PC 0x0c0b8818 */
if(!s->budget--) { s->failed_pc=0x0c0b8818u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b881cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b881cu) { target=s->pc; goto dispatch; }
goto P_0c0b881c;
P_0c0b881a: /* original 05de, guest PC 0x0c0b881a */
if(!s->budget--) { s->failed_pc=0x0c0b881au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b881c;
P_0c0b881c: /* original 943f, guest PC 0x0c0b881c */
if(!s->budget--) { s->failed_pc=0x0c0b881cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b889eu,2);
goto P_0c0b881e;
P_0c0b881e: /* original 903d, guest PC 0x0c0b881e */
if(!s->budget--) { s->failed_pc=0x0c0b881eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b889cu,2);
goto P_0c0b8820;
P_0c0b8820: /* original 4e0b, guest PC 0x0c0b8820 */
if(!s->budget--) { s->failed_pc=0x0c0b8820u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8824u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8824u) { target=s->pc; goto dispatch; }
goto P_0c0b8824;
P_0c0b8822: /* original 05de, guest PC 0x0c0b8822 */
if(!s->budget--) { s->failed_pc=0x0c0b8822u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8824;
P_0c0b8824: /* original 903c, guest PC 0x0c0b8824 */
if(!s->budget--) { s->failed_pc=0x0c0b8824u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b88a0u,2);
goto P_0c0b8826;
P_0c0b8826: /* original a03c, guest PC 0x0c0b8826 */
if(!s->budget--) { s->failed_pc=0x0c0b8826u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b88a2;
P_0c0b8828: /* original 05de, guest PC 0x0c0b8828 */
if(!s->budget--) { s->failed_pc=0x0c0b8828u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0b882au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b882au; return 0; } return 1;
P_0c0b88a2: /* original 943e, guest PC 0x0c0b88a2 */
if(!s->budget--) { s->failed_pc=0x0c0b88a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8922u,2);
goto P_0c0b88a4;
P_0c0b88a4: /* original 4e0b, guest PC 0x0c0b88a4 */
if(!s->budget--) { s->failed_pc=0x0c0b88a4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b88a8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b88a8u) { target=s->pc; goto dispatch; }
goto P_0c0b88a8;
P_0c0b88a6: /* original 0009, guest PC 0x0c0b88a6 */
if(!s->budget--) { s->failed_pc=0x0c0b88a6u; return 0; }
goto P_0c0b88a8;
P_0c0b88a8: /* original 943d, guest PC 0x0c0b88a8 */
if(!s->budget--) { s->failed_pc=0x0c0b88a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8926u,2);
goto P_0c0b88aa;
P_0c0b88aa: /* original 903b, guest PC 0x0c0b88aa */
if(!s->budget--) { s->failed_pc=0x0c0b88aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8924u,2);
goto P_0c0b88ac;
P_0c0b88ac: /* original 4e0b, guest PC 0x0c0b88ac */
if(!s->budget--) { s->failed_pc=0x0c0b88acu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b88b0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b88b0u) { target=s->pc; goto dispatch; }
goto P_0c0b88b0;
P_0c0b88ae: /* original 05de, guest PC 0x0c0b88ae */
if(!s->budget--) { s->failed_pc=0x0c0b88aeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b88b0;
P_0c0b88b0: /* original 943b, guest PC 0x0c0b88b0 */
if(!s->budget--) { s->failed_pc=0x0c0b88b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b892au,2);
goto P_0c0b88b2;
P_0c0b88b2: /* original 9039, guest PC 0x0c0b88b2 */
if(!s->budget--) { s->failed_pc=0x0c0b88b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8928u,2);
goto P_0c0b88b4;
P_0c0b88b4: /* original 4e0b, guest PC 0x0c0b88b4 */
if(!s->budget--) { s->failed_pc=0x0c0b88b4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b88b8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b88b8u) { target=s->pc; goto dispatch; }
goto P_0c0b88b8;
P_0c0b88b6: /* original 05de, guest PC 0x0c0b88b6 */
if(!s->budget--) { s->failed_pc=0x0c0b88b6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b88b8;
P_0c0b88b8: /* original 9439, guest PC 0x0c0b88b8 */
if(!s->budget--) { s->failed_pc=0x0c0b88b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b892eu,2);
goto P_0c0b88ba;
P_0c0b88ba: /* original 9037, guest PC 0x0c0b88ba */
if(!s->budget--) { s->failed_pc=0x0c0b88bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b892cu,2);
goto P_0c0b88bc;
P_0c0b88bc: /* original 4e0b, guest PC 0x0c0b88bc */
if(!s->budget--) { s->failed_pc=0x0c0b88bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b88c0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b88c0u) { target=s->pc; goto dispatch; }
goto P_0c0b88c0;
P_0c0b88be: /* original 05de, guest PC 0x0c0b88be */
if(!s->budget--) { s->failed_pc=0x0c0b88beu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b88c0;
P_0c0b88c0: /* original 9437, guest PC 0x0c0b88c0 */
if(!s->budget--) { s->failed_pc=0x0c0b88c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8932u,2);
goto P_0c0b88c2;
P_0c0b88c2: /* original 9035, guest PC 0x0c0b88c2 */
if(!s->budget--) { s->failed_pc=0x0c0b88c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8930u,2);
goto P_0c0b88c4;
P_0c0b88c4: /* original 4e0b, guest PC 0x0c0b88c4 */
if(!s->budget--) { s->failed_pc=0x0c0b88c4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b88c8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b88c8u) { target=s->pc; goto dispatch; }
goto P_0c0b88c8;
P_0c0b88c6: /* original 05de, guest PC 0x0c0b88c6 */
if(!s->budget--) { s->failed_pc=0x0c0b88c6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b88c8;
P_0c0b88c8: /* original 9435, guest PC 0x0c0b88c8 */
if(!s->budget--) { s->failed_pc=0x0c0b88c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8936u,2);
goto P_0c0b88ca;
P_0c0b88ca: /* original 9033, guest PC 0x0c0b88ca */
if(!s->budget--) { s->failed_pc=0x0c0b88cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8934u,2);
goto P_0c0b88cc;
P_0c0b88cc: /* original 4e0b, guest PC 0x0c0b88cc */
if(!s->budget--) { s->failed_pc=0x0c0b88ccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b88d0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b88d0u) { target=s->pc; goto dispatch; }
goto P_0c0b88d0;
P_0c0b88ce: /* original 05de, guest PC 0x0c0b88ce */
if(!s->budget--) { s->failed_pc=0x0c0b88ceu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b88d0;
P_0c0b88d0: /* original 9433, guest PC 0x0c0b88d0 */
if(!s->budget--) { s->failed_pc=0x0c0b88d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b893au,2);
goto P_0c0b88d2;
P_0c0b88d2: /* original 9031, guest PC 0x0c0b88d2 */
if(!s->budget--) { s->failed_pc=0x0c0b88d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8938u,2);
goto P_0c0b88d4;
P_0c0b88d4: /* original 4e0b, guest PC 0x0c0b88d4 */
if(!s->budget--) { s->failed_pc=0x0c0b88d4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b88d8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b88d8u) { target=s->pc; goto dispatch; }
goto P_0c0b88d8;
P_0c0b88d6: /* original 05de, guest PC 0x0c0b88d6 */
if(!s->budget--) { s->failed_pc=0x0c0b88d6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b88d8;
P_0c0b88d8: /* original 9431, guest PC 0x0c0b88d8 */
if(!s->budget--) { s->failed_pc=0x0c0b88d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b893eu,2);
goto P_0c0b88da;
P_0c0b88da: /* original 902f, guest PC 0x0c0b88da */
if(!s->budget--) { s->failed_pc=0x0c0b88dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b893cu,2);
goto P_0c0b88dc;
P_0c0b88dc: /* original 4e0b, guest PC 0x0c0b88dc */
if(!s->budget--) { s->failed_pc=0x0c0b88dcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b88e0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b88e0u) { target=s->pc; goto dispatch; }
goto P_0c0b88e0;
P_0c0b88de: /* original 05de, guest PC 0x0c0b88de */
if(!s->budget--) { s->failed_pc=0x0c0b88deu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b88e0;
P_0c0b88e0: /* original 942f, guest PC 0x0c0b88e0 */
if(!s->budget--) { s->failed_pc=0x0c0b88e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8942u,2);
goto P_0c0b88e2;
P_0c0b88e2: /* original 902d, guest PC 0x0c0b88e2 */
if(!s->budget--) { s->failed_pc=0x0c0b88e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8940u,2);
goto P_0c0b88e4;
P_0c0b88e4: /* original 4e0b, guest PC 0x0c0b88e4 */
if(!s->budget--) { s->failed_pc=0x0c0b88e4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b88e8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b88e8u) { target=s->pc; goto dispatch; }
goto P_0c0b88e8;
P_0c0b88e6: /* original 05de, guest PC 0x0c0b88e6 */
if(!s->budget--) { s->failed_pc=0x0c0b88e6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b88e8;
P_0c0b88e8: /* original 942d, guest PC 0x0c0b88e8 */
if(!s->budget--) { s->failed_pc=0x0c0b88e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8946u,2);
goto P_0c0b88ea;
P_0c0b88ea: /* original 902b, guest PC 0x0c0b88ea */
if(!s->budget--) { s->failed_pc=0x0c0b88eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8944u,2);
goto P_0c0b88ec;
P_0c0b88ec: /* original 4e0b, guest PC 0x0c0b88ec */
if(!s->budget--) { s->failed_pc=0x0c0b88ecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b88f0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b88f0u) { target=s->pc; goto dispatch; }
goto P_0c0b88f0;
P_0c0b88ee: /* original 05de, guest PC 0x0c0b88ee */
if(!s->budget--) { s->failed_pc=0x0c0b88eeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b88f0;
P_0c0b88f0: /* original 942b, guest PC 0x0c0b88f0 */
if(!s->budget--) { s->failed_pc=0x0c0b88f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b894au,2);
goto P_0c0b88f2;
P_0c0b88f2: /* original 9029, guest PC 0x0c0b88f2 */
if(!s->budget--) { s->failed_pc=0x0c0b88f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8948u,2);
goto P_0c0b88f4;
P_0c0b88f4: /* original 4e0b, guest PC 0x0c0b88f4 */
if(!s->budget--) { s->failed_pc=0x0c0b88f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b88f8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b88f8u) { target=s->pc; goto dispatch; }
goto P_0c0b88f8;
P_0c0b88f6: /* original 05de, guest PC 0x0c0b88f6 */
if(!s->budget--) { s->failed_pc=0x0c0b88f6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b88f8;
P_0c0b88f8: /* original 9429, guest PC 0x0c0b88f8 */
if(!s->budget--) { s->failed_pc=0x0c0b88f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b894eu,2);
goto P_0c0b88fa;
P_0c0b88fa: /* original 9027, guest PC 0x0c0b88fa */
if(!s->budget--) { s->failed_pc=0x0c0b88fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b894cu,2);
goto P_0c0b88fc;
P_0c0b88fc: /* original 4e0b, guest PC 0x0c0b88fc */
if(!s->budget--) { s->failed_pc=0x0c0b88fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8900u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8900u) { target=s->pc; goto dispatch; }
goto P_0c0b8900;
P_0c0b88fe: /* original 05de, guest PC 0x0c0b88fe */
if(!s->budget--) { s->failed_pc=0x0c0b88feu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8900;
P_0c0b8900: /* original 9427, guest PC 0x0c0b8900 */
if(!s->budget--) { s->failed_pc=0x0c0b8900u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8952u,2);
goto P_0c0b8902;
P_0c0b8902: /* original 9025, guest PC 0x0c0b8902 */
if(!s->budget--) { s->failed_pc=0x0c0b8902u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8950u,2);
goto P_0c0b8904;
P_0c0b8904: /* original 4e0b, guest PC 0x0c0b8904 */
if(!s->budget--) { s->failed_pc=0x0c0b8904u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8908u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8908u) { target=s->pc; goto dispatch; }
goto P_0c0b8908;
P_0c0b8906: /* original 05de, guest PC 0x0c0b8906 */
if(!s->budget--) { s->failed_pc=0x0c0b8906u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8908;
P_0c0b8908: /* original 9425, guest PC 0x0c0b8908 */
if(!s->budget--) { s->failed_pc=0x0c0b8908u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8956u,2);
goto P_0c0b890a;
P_0c0b890a: /* original 9023, guest PC 0x0c0b890a */
if(!s->budget--) { s->failed_pc=0x0c0b890au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8954u,2);
goto P_0c0b890c;
P_0c0b890c: /* original 4e0b, guest PC 0x0c0b890c */
if(!s->budget--) { s->failed_pc=0x0c0b890cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8910u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8910u) { target=s->pc; goto dispatch; }
goto P_0c0b8910;
P_0c0b890e: /* original 05de, guest PC 0x0c0b890e */
if(!s->budget--) { s->failed_pc=0x0c0b890eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8910;
P_0c0b8910: /* original 7f08, guest PC 0x0c0b8910 */
if(!s->budget--) { s->failed_pc=0x0c0b8910u; return 0; }
r[15]+=0x00000008u;
goto P_0c0b8912;
P_0c0b8912: /* original 4f26, guest PC 0x0c0b8912 */
if(!s->budget--) { s->failed_pc=0x0c0b8912u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b8914;
P_0c0b8914: /* original 69f6, guest PC 0x0c0b8914 */
if(!s->budget--) { s->failed_pc=0x0c0b8914u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b8916;
P_0c0b8916: /* original 6af6, guest PC 0x0c0b8916 */
if(!s->budget--) { s->failed_pc=0x0c0b8916u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b8918;
P_0c0b8918: /* original 6bf6, guest PC 0x0c0b8918 */
if(!s->budget--) { s->failed_pc=0x0c0b8918u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b891a;
P_0c0b891a: /* original 6cf6, guest PC 0x0c0b891a */
if(!s->budget--) { s->failed_pc=0x0c0b891au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b891c;
P_0c0b891c: /* original 6df6, guest PC 0x0c0b891c */
if(!s->budget--) { s->failed_pc=0x0c0b891cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b891e;
P_0c0b891e: /* original 000b, guest PC 0x0c0b891e */
if(!s->budget--) { s->failed_pc=0x0c0b891eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b8920: /* original 6ef6, guest PC 0x0c0b8920 */
if(!s->budget--) { s->failed_pc=0x0c0b8920u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b8922u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b8922u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
