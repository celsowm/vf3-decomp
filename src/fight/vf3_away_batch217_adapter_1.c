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
int vf3_away_batch217_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09553cu: goto P_0c09553c;
case 0x0c09553eu: goto P_0c09553e;
case 0x0c095540u: goto P_0c095540;
case 0x0c095542u: goto P_0c095542;
case 0x0c095544u: goto P_0c095544;
case 0x0c095546u: goto P_0c095546;
case 0x0c095548u: goto P_0c095548;
case 0x0c09554au: goto P_0c09554a;
case 0x0c09554cu: goto P_0c09554c;
case 0x0c09554eu: goto P_0c09554e;
case 0x0c095550u: goto P_0c095550;
case 0x0c095552u: goto P_0c095552;
case 0x0c095554u: goto P_0c095554;
case 0x0c095556u: goto P_0c095556;
case 0x0c095558u: goto P_0c095558;
case 0x0c09555au: goto P_0c09555a;
case 0x0c09555cu: goto P_0c09555c;
case 0x0c09555eu: goto P_0c09555e;
case 0x0c095560u: goto P_0c095560;
case 0x0c095562u: goto P_0c095562;
case 0x0c095564u: goto P_0c095564;
case 0x0c095566u: goto P_0c095566;
case 0x0c095568u: goto P_0c095568;
case 0x0c09556au: goto P_0c09556a;
case 0x0c09556cu: goto P_0c09556c;
case 0x0c09556eu: goto P_0c09556e;
case 0x0c095570u: goto P_0c095570;
case 0x0c095572u: goto P_0c095572;
case 0x0c095574u: goto P_0c095574;
case 0x0c095576u: goto P_0c095576;
case 0x0c095578u: goto P_0c095578;
case 0x0c09557au: goto P_0c09557a;
case 0x0c09557cu: goto P_0c09557c;
case 0x0c09557eu: goto P_0c09557e;
case 0x0c095580u: goto P_0c095580;
case 0x0c095582u: goto P_0c095582;
case 0x0c0ae29cu: goto P_0c0ae29c;
case 0x0c0ae29eu: goto P_0c0ae29e;
case 0x0c0ae2a0u: goto P_0c0ae2a0;
case 0x0c0ae2a2u: goto P_0c0ae2a2;
case 0x0c0ae2a4u: goto P_0c0ae2a4;
case 0x0c0ae2a6u: goto P_0c0ae2a6;
case 0x0c0ae2a8u: goto P_0c0ae2a8;
case 0x0c0ae2aau: goto P_0c0ae2aa;
case 0x0c0ae2acu: goto P_0c0ae2ac;
case 0x0c0ae2aeu: goto P_0c0ae2ae;
case 0x0c0ae2b0u: goto P_0c0ae2b0;
case 0x0c0ae2b2u: goto P_0c0ae2b2;
case 0x0c0ae2b4u: goto P_0c0ae2b4;
case 0x0c0ae2b6u: goto P_0c0ae2b6;
case 0x0c0ae2b8u: goto P_0c0ae2b8;
case 0x0c0ae2bau: goto P_0c0ae2ba;
case 0x0c0ae2bcu: goto P_0c0ae2bc;
case 0x0c0ae2beu: goto P_0c0ae2be;
case 0x0c0ae2c0u: goto P_0c0ae2c0;
case 0x0c0ae2c2u: goto P_0c0ae2c2;
case 0x0c0ae2c4u: goto P_0c0ae2c4;
case 0x0c0ae2c6u: goto P_0c0ae2c6;
case 0x0c0ae2c8u: goto P_0c0ae2c8;
case 0x0c0ae2cau: goto P_0c0ae2ca;
case 0x0c0ae2ccu: goto P_0c0ae2cc;
case 0x0c0ae2ceu: goto P_0c0ae2ce;
case 0x0c0ae2d0u: goto P_0c0ae2d0;
case 0x0c0ae2d2u: goto P_0c0ae2d2;
case 0x0c0ae2d4u: goto P_0c0ae2d4;
case 0x0c0ae2d6u: goto P_0c0ae2d6;
case 0x0c0ae2d8u: goto P_0c0ae2d8;
case 0x0c0ae2dau: goto P_0c0ae2da;
case 0x0c0aed34u: goto P_0c0aed34;
case 0x0c0aed36u: goto P_0c0aed36;
case 0x0c0aed38u: goto P_0c0aed38;
case 0x0c0aed3au: goto P_0c0aed3a;
case 0x0c0aed3cu: goto P_0c0aed3c;
case 0x0c0aed3eu: goto P_0c0aed3e;
case 0x0c0aed40u: goto P_0c0aed40;
case 0x0c0aed42u: goto P_0c0aed42;
case 0x0c0aed44u: goto P_0c0aed44;
case 0x0c0aed46u: goto P_0c0aed46;
case 0x0c0aed48u: goto P_0c0aed48;
case 0x0c0aed4au: goto P_0c0aed4a;
case 0x0c0aed4cu: goto P_0c0aed4c;
case 0x0c0aed4eu: goto P_0c0aed4e;
case 0x0c0aed50u: goto P_0c0aed50;
case 0x0c0aed52u: goto P_0c0aed52;
case 0x0c0aed54u: goto P_0c0aed54;
case 0x0c0aed56u: goto P_0c0aed56;
case 0x0c0aed58u: goto P_0c0aed58;
case 0x0c0aed5au: goto P_0c0aed5a;
case 0x0c0aed5cu: goto P_0c0aed5c;
case 0x0c0aed5eu: goto P_0c0aed5e;
case 0x0c0aed60u: goto P_0c0aed60;
case 0x0c0aed62u: goto P_0c0aed62;
case 0x0c0aed64u: goto P_0c0aed64;
case 0x0c0aed66u: goto P_0c0aed66;
case 0x0c0aed68u: goto P_0c0aed68;
case 0x0c0aed6au: goto P_0c0aed6a;
case 0x0c0aed6cu: goto P_0c0aed6c;
case 0x0c0aed6eu: goto P_0c0aed6e;
case 0x0c0aed70u: goto P_0c0aed70;
case 0x0c0aed72u: goto P_0c0aed72;
case 0x0c0aed74u: goto P_0c0aed74;
case 0x0c0aed76u: goto P_0c0aed76;
case 0x0c0aed78u: goto P_0c0aed78;
case 0x0c0aed7au: goto P_0c0aed7a;
case 0x0c0aed7cu: goto P_0c0aed7c;
case 0x0c0aed7eu: goto P_0c0aed7e;
case 0x0c0aed80u: goto P_0c0aed80;
case 0x0c0aed82u: goto P_0c0aed82;
case 0x0c0aed84u: goto P_0c0aed84;
case 0x0c0aed86u: goto P_0c0aed86;
case 0x0c0aed88u: goto P_0c0aed88;
case 0x0c0aed8au: goto P_0c0aed8a;
case 0x0c0aed8cu: goto P_0c0aed8c;
case 0x0c0aed8eu: goto P_0c0aed8e;
case 0x0c0aed90u: goto P_0c0aed90;
case 0x0c0aed92u: goto P_0c0aed92;
case 0x0c0aed94u: goto P_0c0aed94;
case 0x0c0aed96u: goto P_0c0aed96;
case 0x0c0aed98u: goto P_0c0aed98;
case 0x0c0aed9au: goto P_0c0aed9a;
case 0x0c0aed9cu: goto P_0c0aed9c;
case 0x0c0aed9eu: goto P_0c0aed9e;
case 0x0c0aeda0u: goto P_0c0aeda0;
case 0x0c0aeda2u: goto P_0c0aeda2;
case 0x0c0aeda4u: goto P_0c0aeda4;
case 0x0c0aeda6u: goto P_0c0aeda6;
case 0x0c0aeda8u: goto P_0c0aeda8;
case 0x0c0aedaau: goto P_0c0aedaa;
case 0x0c0aedacu: goto P_0c0aedac;
case 0x0c0aedaeu: goto P_0c0aedae;
case 0x0c0aedb0u: goto P_0c0aedb0;
case 0x0c0aedb2u: goto P_0c0aedb2;
case 0x0c0aedb4u: goto P_0c0aedb4;
case 0x0c0aedb6u: goto P_0c0aedb6;
case 0x0c0aedb8u: goto P_0c0aedb8;
case 0x0c0aedbau: goto P_0c0aedba;
case 0x0c0aedbcu: goto P_0c0aedbc;
case 0x0c0aedbeu: goto P_0c0aedbe;
case 0x0c0aedc0u: goto P_0c0aedc0;
case 0x0c0aedc2u: goto P_0c0aedc2;
case 0x0c0aedc4u: goto P_0c0aedc4;
case 0x0c0aedc6u: goto P_0c0aedc6;
case 0x0c0aedc8u: goto P_0c0aedc8;
case 0x0c0aedcau: goto P_0c0aedca;
case 0x0c0aedccu: goto P_0c0aedcc;
case 0x0c0aedceu: goto P_0c0aedce;
case 0x0c0aedd0u: goto P_0c0aedd0;
case 0x0c0aedd2u: goto P_0c0aedd2;
case 0x0c0aedd4u: goto P_0c0aedd4;
case 0x0c0aedd6u: goto P_0c0aedd6;
case 0x0c0aedd8u: goto P_0c0aedd8;
case 0x0c0aeddau: goto P_0c0aedda;
case 0x0c0aeddcu: goto P_0c0aeddc;
case 0x0c0aeddeu: goto P_0c0aedde;
case 0x0c0aede0u: goto P_0c0aede0;
case 0x0c0aede2u: goto P_0c0aede2;
case 0x0c0aede4u: goto P_0c0aede4;
case 0x0c0aede6u: goto P_0c0aede6;
case 0x0c0aede8u: goto P_0c0aede8;
case 0x0c0aedeau: goto P_0c0aedea;
case 0x0c0aedecu: goto P_0c0aedec;
case 0x0c0aedeeu: goto P_0c0aedee;
case 0x0c0aedf0u: goto P_0c0aedf0;
case 0x0c0aedf2u: goto P_0c0aedf2;
case 0x0c0aedf4u: goto P_0c0aedf4;
case 0x0c0aedf6u: goto P_0c0aedf6;
case 0x0c0aedf8u: goto P_0c0aedf8;
case 0x0c0aedfau: goto P_0c0aedfa;
case 0x0c0aedfcu: goto P_0c0aedfc;
case 0x0c0aedfeu: goto P_0c0aedfe;
case 0x0c0aee00u: goto P_0c0aee00;
case 0x0c0aee02u: goto P_0c0aee02;
case 0x0c0aee04u: goto P_0c0aee04;
case 0x0c0aee06u: goto P_0c0aee06;
case 0x0c0aee08u: goto P_0c0aee08;
case 0x0c0aee0au: goto P_0c0aee0a;
case 0x0c0aee0cu: goto P_0c0aee0c;
case 0x0c0aee0eu: goto P_0c0aee0e;
case 0x0c0aee10u: goto P_0c0aee10;
case 0x0c0aee12u: goto P_0c0aee12;
case 0x0c0aee14u: goto P_0c0aee14;
case 0x0c0aee16u: goto P_0c0aee16;
case 0x0c0aee18u: goto P_0c0aee18;
case 0x0c0aee1au: goto P_0c0aee1a;
case 0x0c0aee1cu: goto P_0c0aee1c;
case 0x0c0aee1eu: goto P_0c0aee1e;
case 0x0c0aee20u: goto P_0c0aee20;
case 0x0c0aee22u: goto P_0c0aee22;
case 0x0c0aee24u: goto P_0c0aee24;
case 0x0c0aee26u: goto P_0c0aee26;
case 0x0c0aee28u: goto P_0c0aee28;
case 0x0c0aee2au: goto P_0c0aee2a;
case 0x0c0aee2cu: goto P_0c0aee2c;
case 0x0c0aee2eu: goto P_0c0aee2e;
case 0x0c0aee30u: goto P_0c0aee30;
case 0x0c0aee32u: goto P_0c0aee32;
case 0x0c0aee34u: goto P_0c0aee34;
case 0x0c0aee36u: goto P_0c0aee36;
case 0x0c0aee38u: goto P_0c0aee38;
case 0x0c0aee3au: goto P_0c0aee3a;
case 0x0c0aee3cu: goto P_0c0aee3c;
case 0x0c0aee3eu: goto P_0c0aee3e;
case 0x0c0aee40u: goto P_0c0aee40;
case 0x0c0aee42u: goto P_0c0aee42;
case 0x0c0aee44u: goto P_0c0aee44;
case 0x0c0aee46u: goto P_0c0aee46;
case 0x0c0aee48u: goto P_0c0aee48;
case 0x0c0aee4au: goto P_0c0aee4a;
case 0x0c0aee4cu: goto P_0c0aee4c;
case 0x0c0aee4eu: goto P_0c0aee4e;
case 0x0c0aee50u: goto P_0c0aee50;
case 0x0c0aee52u: goto P_0c0aee52;
case 0x0c0aee54u: goto P_0c0aee54;
case 0x0c0aee56u: goto P_0c0aee56;
case 0x0c0aee58u: goto P_0c0aee58;
case 0x0c0aee5au: goto P_0c0aee5a;
case 0x0c0aee5cu: goto P_0c0aee5c;
case 0x0c0aee5eu: goto P_0c0aee5e;
case 0x0c0aee60u: goto P_0c0aee60;
case 0x0c0aee62u: goto P_0c0aee62;
case 0x0c0aee64u: goto P_0c0aee64;
case 0x0c0aee66u: goto P_0c0aee66;
case 0x0c0aee68u: goto P_0c0aee68;
case 0x0c0aee6au: goto P_0c0aee6a;
case 0x0c0aee6cu: goto P_0c0aee6c;
case 0x0c0aee6eu: goto P_0c0aee6e;
case 0x0c0aee70u: goto P_0c0aee70;
case 0x0c0aee72u: goto P_0c0aee72;
case 0x0c0aee74u: goto P_0c0aee74;
case 0x0c0aee76u: goto P_0c0aee76;
case 0x0c0aee78u: goto P_0c0aee78;
case 0x0c0aee7au: goto P_0c0aee7a;
case 0x0c0aee7cu: goto P_0c0aee7c;
case 0x0c0aee7eu: goto P_0c0aee7e;
case 0x0c0aee80u: goto P_0c0aee80;
case 0x0c0aee82u: goto P_0c0aee82;
case 0x0c0aee84u: goto P_0c0aee84;
case 0x0c0aee86u: goto P_0c0aee86;
case 0x0c0aee88u: goto P_0c0aee88;
case 0x0c0aee8au: goto P_0c0aee8a;
case 0x0c0aee8cu: goto P_0c0aee8c;
case 0x0c0aee8eu: goto P_0c0aee8e;
case 0x0c0aee90u: goto P_0c0aee90;
case 0x0c0aee92u: goto P_0c0aee92;
case 0x0c0aee94u: goto P_0c0aee94;
case 0x0c0aee96u: goto P_0c0aee96;
case 0x0c0aee98u: goto P_0c0aee98;
case 0x0c0aee9au: goto P_0c0aee9a;
case 0x0c0aee9cu: goto P_0c0aee9c;
case 0x0c0aee9eu: goto P_0c0aee9e;
case 0x0c0aeea0u: goto P_0c0aeea0;
case 0x0c0aeea2u: goto P_0c0aeea2;
case 0x0c0aeea4u: goto P_0c0aeea4;
case 0x0c0aeea6u: goto P_0c0aeea6;
case 0x0c0aeea8u: goto P_0c0aeea8;
case 0x0c0aeeaau: goto P_0c0aeeaa;
case 0x0c0aeeccu: goto P_0c0aeecc;
case 0x0c0aeeceu: goto P_0c0aeece;
case 0x0c0aeed0u: goto P_0c0aeed0;
case 0x0c0aeed2u: goto P_0c0aeed2;
case 0x0c0aeed4u: goto P_0c0aeed4;
case 0x0c0aeed6u: goto P_0c0aeed6;
case 0x0c0aeed8u: goto P_0c0aeed8;
case 0x0c0aeedau: goto P_0c0aeeda;
case 0x0c0aeedcu: goto P_0c0aeedc;
case 0x0c0aeedeu: goto P_0c0aeede;
case 0x0c0aeee0u: goto P_0c0aeee0;
case 0x0c0aeee2u: goto P_0c0aeee2;
case 0x0c0aeee4u: goto P_0c0aeee4;
case 0x0c0aeee6u: goto P_0c0aeee6;
case 0x0c0aeee8u: goto P_0c0aeee8;
case 0x0c0aeeeau: goto P_0c0aeeea;
case 0x0c0aeeecu: goto P_0c0aeeec;
case 0x0c0aeeeeu: goto P_0c0aeeee;
case 0x0c0aeef0u: goto P_0c0aeef0;
case 0x0c0aeef2u: goto P_0c0aeef2;
case 0x0c0aeef4u: goto P_0c0aeef4;
case 0x0c0aeef6u: goto P_0c0aeef6;
case 0x0c0aeef8u: goto P_0c0aeef8;
case 0x0c0aeefau: goto P_0c0aeefa;
case 0x0c0aeefcu: goto P_0c0aeefc;
case 0x0c0aeefeu: goto P_0c0aeefe;
case 0x0c0aef00u: goto P_0c0aef00;
case 0x0c0aef02u: goto P_0c0aef02;
case 0x0c0aef04u: goto P_0c0aef04;
case 0x0c0aef06u: goto P_0c0aef06;
case 0x0c0aef08u: goto P_0c0aef08;
case 0x0c0aef0au: goto P_0c0aef0a;
case 0x0c0aef0cu: goto P_0c0aef0c;
case 0x0c0aef0eu: goto P_0c0aef0e;
case 0x0c0aef10u: goto P_0c0aef10;
case 0x0c0aef12u: goto P_0c0aef12;
case 0x0c0aef14u: goto P_0c0aef14;
case 0x0c0aef16u: goto P_0c0aef16;
case 0x0c0aef18u: goto P_0c0aef18;
case 0x0c0aef1au: goto P_0c0aef1a;
case 0x0c0aef1cu: goto P_0c0aef1c;
case 0x0c0aef1eu: goto P_0c0aef1e;
case 0x0c0aef20u: goto P_0c0aef20;
case 0x0c0aef22u: goto P_0c0aef22;
case 0x0c0aef24u: goto P_0c0aef24;
case 0x0c0aef26u: goto P_0c0aef26;
case 0x0c0aef28u: goto P_0c0aef28;
case 0x0c0aef2au: goto P_0c0aef2a;
case 0x0c0aef2cu: goto P_0c0aef2c;
case 0x0c0aef2eu: goto P_0c0aef2e;
case 0x0c0aef30u: goto P_0c0aef30;
case 0x0c0aef32u: goto P_0c0aef32;
case 0x0c0aef34u: goto P_0c0aef34;
case 0x0c0aef36u: goto P_0c0aef36;
case 0x0c0aef38u: goto P_0c0aef38;
case 0x0c0aef3au: goto P_0c0aef3a;
case 0x0c0aef3cu: goto P_0c0aef3c;
case 0x0c0aef3eu: goto P_0c0aef3e;
case 0x0c0aef40u: goto P_0c0aef40;
case 0x0c0aef42u: goto P_0c0aef42;
case 0x0c0aef44u: goto P_0c0aef44;
case 0x0c0aef46u: goto P_0c0aef46;
case 0x0c0aef48u: goto P_0c0aef48;
case 0x0c0aef4au: goto P_0c0aef4a;
case 0x0c0aef4cu: goto P_0c0aef4c;
case 0x0c0aef4eu: goto P_0c0aef4e;
case 0x0c0aef50u: goto P_0c0aef50;
case 0x0c0aef52u: goto P_0c0aef52;
case 0x0c0aef54u: goto P_0c0aef54;
case 0x0c0aef56u: goto P_0c0aef56;
case 0x0c0aef58u: goto P_0c0aef58;
case 0x0c0aef5au: goto P_0c0aef5a;
case 0x0c0aef5cu: goto P_0c0aef5c;
case 0x0c0aef5eu: goto P_0c0aef5e;
case 0x0c0aef60u: goto P_0c0aef60;
case 0x0c0aef62u: goto P_0c0aef62;
case 0x0c0aef64u: goto P_0c0aef64;
case 0x0c0aef66u: goto P_0c0aef66;
case 0x0c0aef68u: goto P_0c0aef68;
case 0x0c0aef6au: goto P_0c0aef6a;
case 0x0c0aef6cu: goto P_0c0aef6c;
case 0x0c0aef6eu: goto P_0c0aef6e;
case 0x0c0aef70u: goto P_0c0aef70;
case 0x0c0aef72u: goto P_0c0aef72;
case 0x0c0aef74u: goto P_0c0aef74;
case 0x0c0aef76u: goto P_0c0aef76;
case 0x0c0aef78u: goto P_0c0aef78;
case 0x0c0aef7au: goto P_0c0aef7a;
case 0x0c0aef7cu: goto P_0c0aef7c;
case 0x0c0aef7eu: goto P_0c0aef7e;
case 0x0c0aef80u: goto P_0c0aef80;
case 0x0c0aef82u: goto P_0c0aef82;
case 0x0c0aef84u: goto P_0c0aef84;
case 0x0c0aef86u: goto P_0c0aef86;
case 0x0c0aef88u: goto P_0c0aef88;
case 0x0c0aef8au: goto P_0c0aef8a;
case 0x0c0aef8cu: goto P_0c0aef8c;
case 0x0c0aef8eu: goto P_0c0aef8e;
case 0x0c0aef90u: goto P_0c0aef90;
case 0x0c0aef92u: goto P_0c0aef92;
case 0x0c0aef94u: goto P_0c0aef94;
case 0x0c0aef96u: goto P_0c0aef96;
case 0x0c0aef98u: goto P_0c0aef98;
case 0x0c0aef9au: goto P_0c0aef9a;
case 0x0c0aef9cu: goto P_0c0aef9c;
case 0x0c0aef9eu: goto P_0c0aef9e;
case 0x0c0aefa0u: goto P_0c0aefa0;
case 0x0c0aefa2u: goto P_0c0aefa2;
case 0x0c0aefa4u: goto P_0c0aefa4;
case 0x0c0aefa6u: goto P_0c0aefa6;
case 0x0c0aefa8u: goto P_0c0aefa8;
case 0x0c0aefaau: goto P_0c0aefaa;
case 0x0c0aefacu: goto P_0c0aefac;
case 0x0c0aefaeu: goto P_0c0aefae;
case 0x0c0aefb0u: goto P_0c0aefb0;
case 0x0c0aefb2u: goto P_0c0aefb2;
case 0x0c0aefb4u: goto P_0c0aefb4;
case 0x0c0aefb6u: goto P_0c0aefb6;
case 0x0c0aefb8u: goto P_0c0aefb8;
case 0x0c0aefbau: goto P_0c0aefba;
case 0x0c0aefbcu: goto P_0c0aefbc;
case 0x0c0aefbeu: goto P_0c0aefbe;
case 0x0c0aefc0u: goto P_0c0aefc0;
case 0x0c0aefc2u: goto P_0c0aefc2;
case 0x0c0aefc4u: goto P_0c0aefc4;
case 0x0c0aefc6u: goto P_0c0aefc6;
case 0x0c0aefc8u: goto P_0c0aefc8;
case 0x0c0aefcau: goto P_0c0aefca;
case 0x0c0aefccu: goto P_0c0aefcc;
case 0x0c0aefceu: goto P_0c0aefce;
case 0x0c0aefd0u: goto P_0c0aefd0;
case 0x0c0aefd2u: goto P_0c0aefd2;
case 0x0c0aefd4u: goto P_0c0aefd4;
case 0x0c0aefd6u: goto P_0c0aefd6;
case 0x0c0aefd8u: goto P_0c0aefd8;
case 0x0c0aefdau: goto P_0c0aefda;
case 0x0c0aefdcu: goto P_0c0aefdc;
case 0x0c0aefdeu: goto P_0c0aefde;
case 0x0c0aefe0u: goto P_0c0aefe0;
case 0x0c0aefe2u: goto P_0c0aefe2;
case 0x0c0aefe4u: goto P_0c0aefe4;
case 0x0c0aefe6u: goto P_0c0aefe6;
case 0x0c0aefe8u: goto P_0c0aefe8;
case 0x0c0aefeau: goto P_0c0aefea;
case 0x0c0aefecu: goto P_0c0aefec;
case 0x0c0aefeeu: goto P_0c0aefee;
case 0x0c0aeff0u: goto P_0c0aeff0;
case 0x0c0aeff2u: goto P_0c0aeff2;
case 0x0c0aeff4u: goto P_0c0aeff4;
case 0x0c0aeff6u: goto P_0c0aeff6;
case 0x0c0aeff8u: goto P_0c0aeff8;
case 0x0c0aeffau: goto P_0c0aeffa;
case 0x0c0aeffcu: goto P_0c0aeffc;
case 0x0c0aeffeu: goto P_0c0aeffe;
case 0x0c0af000u: goto P_0c0af000;
case 0x0c0af002u: goto P_0c0af002;
case 0x0c0af004u: goto P_0c0af004;
case 0x0c0af006u: goto P_0c0af006;
case 0x0c0af008u: goto P_0c0af008;
case 0x0c0af00au: goto P_0c0af00a;
case 0x0c0af00cu: goto P_0c0af00c;
case 0x0c0af00eu: goto P_0c0af00e;
case 0x0c0af010u: goto P_0c0af010;
case 0x0c0af012u: goto P_0c0af012;
case 0x0c0af014u: goto P_0c0af014;
case 0x0c0af016u: goto P_0c0af016;
case 0x0c0af018u: goto P_0c0af018;
case 0x0c0af01au: goto P_0c0af01a;
case 0x0c0af01cu: goto P_0c0af01c;
case 0x0c0af01eu: goto P_0c0af01e;
case 0x0c0af020u: goto P_0c0af020;
case 0x0c0af022u: goto P_0c0af022;
case 0x0c0af024u: goto P_0c0af024;
case 0x0c0af026u: goto P_0c0af026;
case 0x0c0af028u: goto P_0c0af028;
case 0x0c0af02au: goto P_0c0af02a;
case 0x0c0af02cu: goto P_0c0af02c;
case 0x0c0af02eu: goto P_0c0af02e;
case 0x0c0af030u: goto P_0c0af030;
case 0x0c0af032u: goto P_0c0af032;
case 0x0c0af034u: goto P_0c0af034;
case 0x0c0af036u: goto P_0c0af036;
case 0x0c0af038u: goto P_0c0af038;
case 0x0c0af03au: goto P_0c0af03a;
case 0x0c0af03cu: goto P_0c0af03c;
case 0x0c0af03eu: goto P_0c0af03e;
case 0x0c0af040u: goto P_0c0af040;
case 0x0c0af042u: goto P_0c0af042;
case 0x0c0af044u: goto P_0c0af044;
case 0x0c0af046u: goto P_0c0af046;
case 0x0c0af048u: goto P_0c0af048;
case 0x0c0af04au: goto P_0c0af04a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09553c: /* original fffb, guest PC 0x0c09553c */
if(!s->budget--) { s->failed_pc=0x0c09553cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09553e;
P_0c09553e: /* original 4f22, guest PC 0x0c09553e */
if(!s->budget--) { s->failed_pc=0x0c09553eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c095540;
P_0c095540: /* original 7ff0, guest PC 0x0c095540 */
if(!s->budget--) { s->failed_pc=0x0c095540u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c095542;
P_0c095542: /* original 1f42, guest PC 0x0c095542 */
if(!s->budget--) { s->failed_pc=0x0c095542u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c095544;
P_0c095544: /* original 2f52, guest PC 0x0c095544 */
if(!s->budget--) { s->failed_pc=0x0c095544u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c095546;
P_0c095546: /* original 1f61, guest PC 0x0c095546 */
if(!s->budget--) { s->failed_pc=0x0c095546u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c095548;
P_0c095548: /* original 54f2, guest PC 0x0c095548 */
if(!s->budget--) { s->failed_pc=0x0c095548u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c09554a;
P_0c09554a: /* original d369, guest PC 0x0c09554a */
if(!s->budget--) { s->failed_pc=0x0c09554au; return 0; }
r[3]=read(ram,0x0c0956f0u,4);
goto P_0c09554c;
P_0c09554c: /* original 644f, guest PC 0x0c09554c */
if(!s->budget--) { s->failed_pc=0x0c09554cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c09554e;
P_0c09554e: /* original 430b, guest PC 0x0c09554e */
if(!s->budget--) { s->failed_pc=0x0c09554eu; return 0; }
target=r[3];
r[16]=code_base|0x0c095552u;
write(ram,r[15]+12,r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c095552u) { target=s->pc; goto dispatch; }
goto P_0c095552;
P_0c095550: /* original 1f43, guest PC 0x0c095550 */
if(!s->budget--) { s->failed_pc=0x0c095550u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c095552;
P_0c095552: /* original d368, guest PC 0x0c095552 */
if(!s->budget--) { s->failed_pc=0x0c095552u; return 0; }
r[3]=read(ram,0x0c0956f4u,4);
goto P_0c095554;
P_0c095554: /* original ff0c, guest PC 0x0c095554 */
if(!s->budget--) { s->failed_pc=0x0c095554u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c095556;
P_0c095556: /* original 430b, guest PC 0x0c095556 */
if(!s->budget--) { s->failed_pc=0x0c095556u; return 0; }
target=r[3];
r[16]=code_base|0x0c09555au;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09555au) { target=s->pc; goto dispatch; }
goto P_0c09555a;
P_0c095558: /* original 54f3, guest PC 0x0c095558 */
if(!s->budget--) { s->failed_pc=0x0c095558u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c09555a;
P_0c09555a: /* original 62f2, guest PC 0x0c09555a */
if(!s->budget--) { s->failed_pc=0x0c09555au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09555c;
P_0c09555c: /* original f70c, guest PC 0x0c09555c */
if(!s->budget--) { s->failed_pc=0x0c09555cu; return 0; }
vf3_matrix_move(s,7,0);
goto P_0c09555e;
P_0c09555e: /* original f628, guest PC 0x0c09555e */
if(!s->budget--) { s->failed_pc=0x0c09555eu; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
goto P_0c095560;
P_0c095560: /* original 53f1, guest PC 0x0c095560 */
if(!s->budget--) { s->failed_pc=0x0c095560u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c095562;
P_0c095562: /* original f762, guest PC 0x0c095562 */
if(!s->budget--) { s->failed_pc=0x0c095562u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'*');
goto P_0c095564;
P_0c095564: /* original f40c, guest PC 0x0c095564 */
if(!s->budget--) { s->failed_pc=0x0c095564u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c095566;
P_0c095566: /* original f538, guest PC 0x0c095566 */
if(!s->budget--) { s->failed_pc=0x0c095566u; return 0; }
vf3_matrix_load(s,ram,5,r[3]);
goto P_0c095568;
P_0c095568: /* original 6323, guest PC 0x0c095568 */
if(!s->budget--) { s->failed_pc=0x0c095568u; return 0; }
r[3]=r[2];
goto P_0c09556a;
P_0c09556a: /* original f05c, guest PC 0x0c09556a */
if(!s->budget--) { s->failed_pc=0x0c09556au; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c09556c;
P_0c09556c: /* original f452, guest PC 0x0c09556c */
if(!s->budget--) { s->failed_pc=0x0c09556cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c09556e;
P_0c09556e: /* original f7fe, guest PC 0x0c09556e */
if(!s->budget--) { s->failed_pc=0x0c09556eu; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[15],fr[7],r[18]);
goto P_0c095570;
P_0c095570: /* original ff62, guest PC 0x0c095570 */
if(!s->budget--) { s->failed_pc=0x0c095570u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[6],r[18],'*');
goto P_0c095572;
P_0c095572: /* original f57c, guest PC 0x0c095572 */
if(!s->budget--) { s->failed_pc=0x0c095572u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c095574;
P_0c095574: /* original f35a, guest PC 0x0c095574 */
if(!s->budget--) { s->failed_pc=0x0c095574u; return 0; }
vf3_matrix_store(s,ram,5,r[3]);
goto P_0c095576;
P_0c095576: /* original f4f1, guest PC 0x0c095576 */
if(!s->budget--) { s->failed_pc=0x0c095576u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
goto P_0c095578;
P_0c095578: /* original 53f1, guest PC 0x0c095578 */
if(!s->budget--) { s->failed_pc=0x0c095578u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09557a;
P_0c09557a: /* original 7f10, guest PC 0x0c09557a */
if(!s->budget--) { s->failed_pc=0x0c09557au; return 0; }
r[15]+=0x00000010u;
goto P_0c09557c;
P_0c09557c: /* original 4f26, guest PC 0x0c09557c */
if(!s->budget--) { s->failed_pc=0x0c09557cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09557e;
P_0c09557e: /* original f34a, guest PC 0x0c09557e */
if(!s->budget--) { s->failed_pc=0x0c09557eu; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c095580;
P_0c095580: /* original 000b, guest PC 0x0c095580 */
if(!s->budget--) { s->failed_pc=0x0c095580u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c095582: /* original fff9, guest PC 0x0c095582 */
if(!s->budget--) { s->failed_pc=0x0c095582u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c095584u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095584u; return 0; } return 1;
P_0c0ae29c: /* original 5762, guest PC 0x0c0ae29c */
if(!s->budget--) { s->failed_pc=0x0c0ae29cu; return 0; }
r[7]=read(ram,r[6]+8,4);
goto P_0c0ae29e;
P_0c0ae29e: /* original 7ffc, guest PC 0x0c0ae29e */
if(!s->budget--) { s->failed_pc=0x0c0ae29eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ae2a0;
P_0c0ae2a0: /* original 6770, guest PC 0x0c0ae2a0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]=tmp;
goto P_0c0ae2a2;
P_0c0ae2a2: /* original 677c, guest PC 0x0c0ae2a2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a2u; return 0; }
r[7]=r[7]&255u;
goto P_0c0ae2a4;
P_0c0ae2a4: /* original 2778, guest PC 0x0c0ae2a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0ae2a6;
P_0c0ae2a6: /* original 8910, guest PC 0x0c0ae2a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae2ca; }
goto P_0c0ae2a8;
P_0c0ae2a8: /* original 5362, guest PC 0x0c0ae2a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a8u; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c0ae2aa;
P_0c0ae2aa: /* original 2f32, guest PC 0x0c0ae2aa */
if(!s->budget--) { s->failed_pc=0x0c0ae2aau; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ae2ac;
P_0c0ae2ac: /* original 62f2, guest PC 0x0c0ae2ac */
if(!s->budget--) { s->failed_pc=0x0c0ae2acu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0ae2ae;
P_0c0ae2ae: /* original 8432, guest PC 0x0c0ae2ae */
if(!s->budget--) { s->failed_pc=0x0c0ae2aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+2,1);
goto P_0c0ae2b0;
P_0c0ae2b0: /* original 7201, guest PC 0x0c0ae2b0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b0u; return 0; }
r[2]+=0x00000001u;
goto P_0c0ae2b2;
P_0c0ae2b2: /* original d315, guest PC 0x0c0ae2b2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b2u; return 0; }
r[3]=read(ram,0x0c0ae308u,4);
goto P_0c0ae2b4;
P_0c0ae2b4: /* original 600c, guest PC 0x0c0ae2b4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae2b6;
P_0c0ae2b6: /* original 6220, guest PC 0x0c0ae2b6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[2]=tmp;
goto P_0c0ae2b8;
P_0c0ae2b8: /* original 4018, guest PC 0x0c0ae2b8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b8u; return 0; }
r[0]<<=8;
goto P_0c0ae2ba;
P_0c0ae2ba: /* original 622c, guest PC 0x0c0ae2ba */
if(!s->budget--) { s->failed_pc=0x0c0ae2bau; return 0; }
r[2]=r[2]&255u;
goto P_0c0ae2bc;
P_0c0ae2bc: /* original 2039, guest PC 0x0c0ae2bc */
if(!s->budget--) { s->failed_pc=0x0c0ae2bcu; return 0; }
r[0]&=r[3];
goto P_0c0ae2be;
P_0c0ae2be: /* original 202b, guest PC 0x0c0ae2be */
if(!s->budget--) { s->failed_pc=0x0c0ae2beu; return 0; }
r[0]|=r[2];
goto P_0c0ae2c0;
P_0c0ae2c0: /* original 6103, guest PC 0x0c0ae2c0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c0u; return 0; }
r[1]=r[0];
goto P_0c0ae2c2;
P_0c0ae2c2: /* original 1601, guest PC 0x0c0ae2c2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c2u; return 0; }
write(ram,r[6]+4,r[0],4);
goto P_0c0ae2c4;
P_0c0ae2c4: /* original 6262, guest PC 0x0c0ae2c4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c4u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c0ae2c6;
P_0c0ae2c6: /* original 3212, guest PC 0x0c0ae2c6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[1])!=0);
goto P_0c0ae2c8;
P_0c0ae2c8: /* original 8902, guest PC 0x0c0ae2c8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae2d0; }
goto P_0c0ae2ca;
P_0c0ae2ca: /* original d310, guest PC 0x0c0ae2ca */
if(!s->budget--) { s->failed_pc=0x0c0ae2cau; return 0; }
r[3]=read(ram,0x0c0ae30cu,4);
goto P_0c0ae2cc;
P_0c0ae2cc: /* original 432b, guest PC 0x0c0ae2cc */
if(!s->budget--) { s->failed_pc=0x0c0ae2ccu; return 0; }
target=r[3];
r[15]+=0x00000004u;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0af728u: return vf3_matrix_family(0x0c0af728u,s,ram);
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
P_0c0ae2ce: /* original 7f04, guest PC 0x0c0ae2ce */
if(!s->budget--) { s->failed_pc=0x0c0ae2ceu; return 0; }
r[15]+=0x00000004u;
goto P_0c0ae2d0;
P_0c0ae2d0: /* original d00f, guest PC 0x0c0ae2d0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d0u; return 0; }
r[0]=read(ram,0x0c0ae310u,4);
goto P_0c0ae2d2;
P_0c0ae2d2: /* original 4708, guest PC 0x0c0ae2d2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d2u; return 0; }
r[7]<<=2;
goto P_0c0ae2d4;
P_0c0ae2d4: /* original 027e, guest PC 0x0c0ae2d4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d4u; return 0; }
r[2]=read(ram,r[7]+r[0],4);
goto P_0c0ae2d6;
P_0c0ae2d6: /* original 2f22, guest PC 0x0c0ae2d6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d6u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ae2d8;
P_0c0ae2d8: /* original 422b, guest PC 0x0c0ae2d8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d8u; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c0ae2da: /* original 7f04, guest PC 0x0c0ae2da */
if(!s->budget--) { s->failed_pc=0x0c0ae2dau; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c0ae2dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ae2dcu; return 0; } return 1;
P_0c0aed34: /* original 2fe6, guest PC 0x0c0aed34 */
if(!s->budget--) { s->failed_pc=0x0c0aed34u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aed36;
P_0c0aed36: /* original 6e43, guest PC 0x0c0aed36 */
if(!s->budget--) { s->failed_pc=0x0c0aed36u; return 0; }
r[14]=r[4];
goto P_0c0aed38;
P_0c0aed38: /* original 2fd6, guest PC 0x0c0aed38 */
if(!s->budget--) { s->failed_pc=0x0c0aed38u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aed3a;
P_0c0aed3a: /* original 2fc6, guest PC 0x0c0aed3a */
if(!s->budget--) { s->failed_pc=0x0c0aed3au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aed3c;
P_0c0aed3c: /* original 2fb6, guest PC 0x0c0aed3c */
if(!s->budget--) { s->failed_pc=0x0c0aed3cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aed3e;
P_0c0aed3e: /* original 2fa6, guest PC 0x0c0aed3e */
if(!s->budget--) { s->failed_pc=0x0c0aed3eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aed40;
P_0c0aed40: /* original 2f96, guest PC 0x0c0aed40 */
if(!s->budget--) { s->failed_pc=0x0c0aed40u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aed42;
P_0c0aed42: /* original 2f86, guest PC 0x0c0aed42 */
if(!s->budget--) { s->failed_pc=0x0c0aed42u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aed44;
P_0c0aed44: /* original 6853, guest PC 0x0c0aed44 */
if(!s->budget--) { s->failed_pc=0x0c0aed44u; return 0; }
r[8]=r[5];
goto P_0c0aed46;
P_0c0aed46: /* original fffb, guest PC 0x0c0aed46 */
if(!s->budget--) { s->failed_pc=0x0c0aed46u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0aed48;
P_0c0aed48: /* original d458, guest PC 0x0c0aed48 */
if(!s->budget--) { s->failed_pc=0x0c0aed48u; return 0; }
r[4]=read(ram,0x0c0aeeacu,4);
goto P_0c0aed4a;
P_0c0aed4a: /* original 4f22, guest PC 0x0c0aed4a */
if(!s->budget--) { s->failed_pc=0x0c0aed4au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aed4c;
P_0c0aed4c: /* original d558, guest PC 0x0c0aed4c */
if(!s->budget--) { s->failed_pc=0x0c0aed4cu; return 0; }
r[5]=read(ram,0x0c0aeeb0u,4);
goto P_0c0aed4e;
P_0c0aed4e: /* original 5341, guest PC 0x0c0aed4e */
if(!s->budget--) { s->failed_pc=0x0c0aed4eu; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0aed50;
P_0c0aed50: /* original 7fcc, guest PC 0x0c0aed50 */
if(!s->budget--) { s->failed_pc=0x0c0aed50u; return 0; }
r[15]+=0xffffffccu;
goto P_0c0aed52;
P_0c0aed52: /* original 2358, guest PC 0x0c0aed52 */
if(!s->budget--) { s->failed_pc=0x0c0aed52u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0aed54;
P_0c0aed54: /* original 8d02, guest PC 0x0c0aed54 */
if(!s->budget--) { s->failed_pc=0x0c0aed54u; return 0; }
cond=r[17]&1u;
r[12]=r[6];
if(cond) { goto P_0c0aed5c; }
goto P_0c0aed58;
P_0c0aed56: /* original 6c63, guest PC 0x0c0aed56 */
if(!s->budget--) { s->failed_pc=0x0c0aed56u; return 0; }
r[12]=r[6];
goto P_0c0aed58;
P_0c0aed58: /* original a166, guest PC 0x0c0aed58 */
if(!s->budget--) { s->failed_pc=0x0c0aed58u; return 0; }
goto P_0c0af028;
P_0c0aed5a: /* original 0009, guest PC 0x0c0aed5a */
if(!s->budget--) { s->failed_pc=0x0c0aed5au; return 0; }
goto P_0c0aed5c;
P_0c0aed5c: /* original 6242, guest PC 0x0c0aed5c */
if(!s->budget--) { s->failed_pc=0x0c0aed5cu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0aed5e;
P_0c0aed5e: /* original 2528, guest PC 0x0c0aed5e */
if(!s->budget--) { s->failed_pc=0x0c0aed5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c0aed60;
P_0c0aed60: /* original 8901, guest PC 0x0c0aed60 */
if(!s->budget--) { s->failed_pc=0x0c0aed60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aed66; }
goto P_0c0aed62;
P_0c0aed62: /* original a161, guest PC 0x0c0aed62 */
if(!s->budget--) { s->failed_pc=0x0c0aed62u; return 0; }
goto P_0c0af028;
P_0c0aed64: /* original 0009, guest PC 0x0c0aed64 */
if(!s->budget--) { s->failed_pc=0x0c0aed64u; return 0; }
goto P_0c0aed66;
P_0c0aed66: /* original 56c2, guest PC 0x0c0aed66 */
if(!s->budget--) { s->failed_pc=0x0c0aed66u; return 0; }
r[6]=read(ram,r[12]+8,4);
goto P_0c0aed68;
P_0c0aed68: /* original 65f3, guest PC 0x0c0aed68 */
if(!s->budget--) { s->failed_pc=0x0c0aed68u; return 0; }
r[5]=r[15];
goto P_0c0aed6a;
P_0c0aed6a: /* original db53, guest PC 0x0c0aed6a */
if(!s->budget--) { s->failed_pc=0x0c0aed6au; return 0; }
r[11]=read(ram,0x0c0aeeb8u,4);
goto P_0c0aed6c;
P_0c0aed6c: /* original 7514, guest PC 0x0c0aed6c */
if(!s->budget--) { s->failed_pc=0x0c0aed6cu; return 0; }
r[5]+=0x00000014u;
goto P_0c0aed6e;
P_0c0aed6e: /* original 6363, guest PC 0x0c0aed6e */
if(!s->budget--) { s->failed_pc=0x0c0aed6eu; return 0; }
r[3]=r[6];
goto P_0c0aed70;
P_0c0aed70: /* original 7313, guest PC 0x0c0aed70 */
if(!s->budget--) { s->failed_pc=0x0c0aed70u; return 0; }
r[3]+=0x00000013u;
goto P_0c0aed72;
P_0c0aed72: /* original 6163, guest PC 0x0c0aed72 */
if(!s->budget--) { s->failed_pc=0x0c0aed72u; return 0; }
r[1]=r[6];
goto P_0c0aed74;
P_0c0aed74: /* original 7112, guest PC 0x0c0aed74 */
if(!s->budget--) { s->failed_pc=0x0c0aed74u; return 0; }
r[1]+=0x00000012u;
goto P_0c0aed76;
P_0c0aed76: /* original 6230, guest PC 0x0c0aed76 */
if(!s->budget--) { s->failed_pc=0x0c0aed76u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c0aed78;
P_0c0aed78: /* original 6453, guest PC 0x0c0aed78 */
if(!s->budget--) { s->failed_pc=0x0c0aed78u; return 0; }
r[4]=r[5];
goto P_0c0aed7a;
P_0c0aed7a: /* original 6010, guest PC 0x0c0aed7a */
if(!s->budget--) { s->failed_pc=0x0c0aed7au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[0]=tmp;
goto P_0c0aed7c;
P_0c0aed7c: /* original 6163, guest PC 0x0c0aed7c */
if(!s->budget--) { s->failed_pc=0x0c0aed7cu; return 0; }
r[1]=r[6];
goto P_0c0aed7e;
P_0c0aed7e: /* original 622c, guest PC 0x0c0aed7e */
if(!s->budget--) { s->failed_pc=0x0c0aed7eu; return 0; }
r[2]=r[2]&255u;
goto P_0c0aed80;
P_0c0aed80: /* original d34e, guest PC 0x0c0aed80 */
if(!s->budget--) { s->failed_pc=0x0c0aed80u; return 0; }
r[3]=read(ram,0x0c0aeebcu,4);
goto P_0c0aed82;
P_0c0aed82: /* original 4228, guest PC 0x0c0aed82 */
if(!s->budget--) { s->failed_pc=0x0c0aed82u; return 0; }
r[2]<<=16;
goto P_0c0aed84;
P_0c0aed84: /* original d94b, guest PC 0x0c0aed84 */
if(!s->budget--) { s->failed_pc=0x0c0aed84u; return 0; }
r[9]=read(ram,0x0c0aeeb4u,4);
goto P_0c0aed86;
P_0c0aed86: /* original 600c, guest PC 0x0c0aed86 */
if(!s->budget--) { s->failed_pc=0x0c0aed86u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aed88;
P_0c0aed88: /* original 4028, guest PC 0x0c0aed88 */
if(!s->budget--) { s->failed_pc=0x0c0aed88u; return 0; }
r[0]<<=16;
goto P_0c0aed8a;
P_0c0aed8a: /* original 4218, guest PC 0x0c0aed8a */
if(!s->budget--) { s->failed_pc=0x0c0aed8au; return 0; }
r[2]<<=8;
goto P_0c0aed8c;
P_0c0aed8c: /* original 20b9, guest PC 0x0c0aed8c */
if(!s->budget--) { s->failed_pc=0x0c0aed8cu; return 0; }
r[0]&=r[11];
goto P_0c0aed8e;
P_0c0aed8e: /* original 2239, guest PC 0x0c0aed8e */
if(!s->budget--) { s->failed_pc=0x0c0aed8eu; return 0; }
r[2]&=r[3];
goto P_0c0aed90;
P_0c0aed90: /* original 220b, guest PC 0x0c0aed90 */
if(!s->budget--) { s->failed_pc=0x0c0aed90u; return 0; }
r[2]|=r[0];
goto P_0c0aed92;
P_0c0aed92: /* original 7111, guest PC 0x0c0aed92 */
if(!s->budget--) { s->failed_pc=0x0c0aed92u; return 0; }
r[1]+=0x00000011u;
goto P_0c0aed94;
P_0c0aed94: /* original 6010, guest PC 0x0c0aed94 */
if(!s->budget--) { s->failed_pc=0x0c0aed94u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[0]=tmp;
goto P_0c0aed96;
P_0c0aed96: /* original 6163, guest PC 0x0c0aed96 */
if(!s->budget--) { s->failed_pc=0x0c0aed96u; return 0; }
r[1]=r[6];
goto P_0c0aed98;
P_0c0aed98: /* original 7110, guest PC 0x0c0aed98 */
if(!s->budget--) { s->failed_pc=0x0c0aed98u; return 0; }
r[1]+=0x00000010u;
goto P_0c0aed9a;
P_0c0aed9a: /* original 600c, guest PC 0x0c0aed9a */
if(!s->budget--) { s->failed_pc=0x0c0aed9au; return 0; }
r[0]=r[0]&255u;
goto P_0c0aed9c;
P_0c0aed9c: /* original 4018, guest PC 0x0c0aed9c */
if(!s->budget--) { s->failed_pc=0x0c0aed9cu; return 0; }
r[0]<<=8;
goto P_0c0aed9e;
P_0c0aed9e: /* original 2099, guest PC 0x0c0aed9e */
if(!s->budget--) { s->failed_pc=0x0c0aed9eu; return 0; }
r[0]&=r[9];
goto P_0c0aeda0;
P_0c0aeda0: /* original 220b, guest PC 0x0c0aeda0 */
if(!s->budget--) { s->failed_pc=0x0c0aeda0u; return 0; }
r[2]|=r[0];
goto P_0c0aeda2;
P_0c0aeda2: /* original 6010, guest PC 0x0c0aeda2 */
if(!s->budget--) { s->failed_pc=0x0c0aeda2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[0]=tmp;
goto P_0c0aeda4;
P_0c0aeda4: /* original 600c, guest PC 0x0c0aeda4 */
if(!s->budget--) { s->failed_pc=0x0c0aeda4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aeda6;
P_0c0aeda6: /* original 220b, guest PC 0x0c0aeda6 */
if(!s->budget--) { s->failed_pc=0x0c0aeda6u; return 0; }
r[2]|=r[0];
goto P_0c0aeda8;
P_0c0aeda8: /* original 2422, guest PC 0x0c0aeda8 */
if(!s->budget--) { s->failed_pc=0x0c0aeda8u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c0aedaa;
P_0c0aedaa: /* original 56c2, guest PC 0x0c0aedaa */
if(!s->budget--) { s->failed_pc=0x0c0aedaau; return 0; }
r[6]=read(ram,r[12]+8,4);
goto P_0c0aedac;
P_0c0aedac: /* original 6263, guest PC 0x0c0aedac */
if(!s->budget--) { s->failed_pc=0x0c0aedacu; return 0; }
r[2]=r[6];
goto P_0c0aedae;
P_0c0aedae: /* original 7217, guest PC 0x0c0aedae */
if(!s->budget--) { s->failed_pc=0x0c0aedaeu; return 0; }
r[2]+=0x00000017u;
goto P_0c0aedb0;
P_0c0aedb0: /* original 6120, guest PC 0x0c0aedb0 */
if(!s->budget--) { s->failed_pc=0x0c0aedb0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c0aedb2;
P_0c0aedb2: /* original 6263, guest PC 0x0c0aedb2 */
if(!s->budget--) { s->failed_pc=0x0c0aedb2u; return 0; }
r[2]=r[6];
goto P_0c0aedb4;
P_0c0aedb4: /* original 7216, guest PC 0x0c0aedb4 */
if(!s->budget--) { s->failed_pc=0x0c0aedb4u; return 0; }
r[2]+=0x00000016u;
goto P_0c0aedb6;
P_0c0aedb6: /* original 6020, guest PC 0x0c0aedb6 */
if(!s->budget--) { s->failed_pc=0x0c0aedb6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[0]=tmp;
goto P_0c0aedb8;
P_0c0aedb8: /* original 611c, guest PC 0x0c0aedb8 */
if(!s->budget--) { s->failed_pc=0x0c0aedb8u; return 0; }
r[1]=r[1]&255u;
goto P_0c0aedba;
P_0c0aedba: /* original 4128, guest PC 0x0c0aedba */
if(!s->budget--) { s->failed_pc=0x0c0aedbau; return 0; }
r[1]<<=16;
goto P_0c0aedbc;
P_0c0aedbc: /* original 6263, guest PC 0x0c0aedbc */
if(!s->budget--) { s->failed_pc=0x0c0aedbcu; return 0; }
r[2]=r[6];
goto P_0c0aedbe;
P_0c0aedbe: /* original 600c, guest PC 0x0c0aedbe */
if(!s->budget--) { s->failed_pc=0x0c0aedbeu; return 0; }
r[0]=r[0]&255u;
goto P_0c0aedc0;
P_0c0aedc0: /* original 4028, guest PC 0x0c0aedc0 */
if(!s->budget--) { s->failed_pc=0x0c0aedc0u; return 0; }
r[0]<<=16;
goto P_0c0aedc2;
P_0c0aedc2: /* original 4118, guest PC 0x0c0aedc2 */
if(!s->budget--) { s->failed_pc=0x0c0aedc2u; return 0; }
r[1]<<=8;
goto P_0c0aedc4;
P_0c0aedc4: /* original 20b9, guest PC 0x0c0aedc4 */
if(!s->budget--) { s->failed_pc=0x0c0aedc4u; return 0; }
r[0]&=r[11];
goto P_0c0aedc6;
P_0c0aedc6: /* original 2139, guest PC 0x0c0aedc6 */
if(!s->budget--) { s->failed_pc=0x0c0aedc6u; return 0; }
r[1]&=r[3];
goto P_0c0aedc8;
P_0c0aedc8: /* original 7215, guest PC 0x0c0aedc8 */
if(!s->budget--) { s->failed_pc=0x0c0aedc8u; return 0; }
r[2]+=0x00000015u;
goto P_0c0aedca;
P_0c0aedca: /* original 210b, guest PC 0x0c0aedca */
if(!s->budget--) { s->failed_pc=0x0c0aedcau; return 0; }
r[1]|=r[0];
goto P_0c0aedcc;
P_0c0aedcc: /* original 6020, guest PC 0x0c0aedcc */
if(!s->budget--) { s->failed_pc=0x0c0aedccu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[0]=tmp;
goto P_0c0aedce;
P_0c0aedce: /* original 6263, guest PC 0x0c0aedce */
if(!s->budget--) { s->failed_pc=0x0c0aedceu; return 0; }
r[2]=r[6];
goto P_0c0aedd0;
P_0c0aedd0: /* original 7214, guest PC 0x0c0aedd0 */
if(!s->budget--) { s->failed_pc=0x0c0aedd0u; return 0; }
r[2]+=0x00000014u;
goto P_0c0aedd2;
P_0c0aedd2: /* original 600c, guest PC 0x0c0aedd2 */
if(!s->budget--) { s->failed_pc=0x0c0aedd2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aedd4;
P_0c0aedd4: /* original 4018, guest PC 0x0c0aedd4 */
if(!s->budget--) { s->failed_pc=0x0c0aedd4u; return 0; }
r[0]<<=8;
goto P_0c0aedd6;
P_0c0aedd6: /* original 2099, guest PC 0x0c0aedd6 */
if(!s->budget--) { s->failed_pc=0x0c0aedd6u; return 0; }
r[0]&=r[9];
goto P_0c0aedd8;
P_0c0aedd8: /* original 210b, guest PC 0x0c0aedd8 */
if(!s->budget--) { s->failed_pc=0x0c0aedd8u; return 0; }
r[1]|=r[0];
goto P_0c0aedda;
P_0c0aedda: /* original 6020, guest PC 0x0c0aedda */
if(!s->budget--) { s->failed_pc=0x0c0aeddau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[0]=tmp;
goto P_0c0aeddc;
P_0c0aeddc: /* original 600c, guest PC 0x0c0aeddc */
if(!s->budget--) { s->failed_pc=0x0c0aeddcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0aedde;
P_0c0aedde: /* original 210b, guest PC 0x0c0aedde */
if(!s->budget--) { s->failed_pc=0x0c0aeddeu; return 0; }
r[1]|=r[0];
goto P_0c0aede0;
P_0c0aede0: /* original 1411, guest PC 0x0c0aede0 */
if(!s->budget--) { s->failed_pc=0x0c0aede0u; return 0; }
write(ram,r[4]+4,r[1],4);
goto P_0c0aede2;
P_0c0aede2: /* original 56c2, guest PC 0x0c0aede2 */
if(!s->budget--) { s->failed_pc=0x0c0aede2u; return 0; }
r[6]=read(ram,r[12]+8,4);
goto P_0c0aede4;
P_0c0aede4: /* original 846b, guest PC 0x0c0aede4 */
if(!s->budget--) { s->failed_pc=0x0c0aede4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+11,1);
goto P_0c0aede6;
P_0c0aede6: /* original 600c, guest PC 0x0c0aede6 */
if(!s->budget--) { s->failed_pc=0x0c0aede6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aede8;
P_0c0aede8: /* original 4028, guest PC 0x0c0aede8 */
if(!s->budget--) { s->failed_pc=0x0c0aede8u; return 0; }
r[0]<<=16;
goto P_0c0aedea;
P_0c0aedea: /* original 4018, guest PC 0x0c0aedea */
if(!s->budget--) { s->failed_pc=0x0c0aedeau; return 0; }
r[0]<<=8;
goto P_0c0aedec;
P_0c0aedec: /* original 2039, guest PC 0x0c0aedec */
if(!s->budget--) { s->failed_pc=0x0c0aedecu; return 0; }
r[0]&=r[3];
goto P_0c0aedee;
P_0c0aedee: /* original 6203, guest PC 0x0c0aedee */
if(!s->budget--) { s->failed_pc=0x0c0aedeeu; return 0; }
r[2]=r[0];
goto P_0c0aedf0;
P_0c0aedf0: /* original 846a, guest PC 0x0c0aedf0 */
if(!s->budget--) { s->failed_pc=0x0c0aedf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+10,1);
goto P_0c0aedf2;
P_0c0aedf2: /* original 600c, guest PC 0x0c0aedf2 */
if(!s->budget--) { s->failed_pc=0x0c0aedf2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aedf4;
P_0c0aedf4: /* original 4028, guest PC 0x0c0aedf4 */
if(!s->budget--) { s->failed_pc=0x0c0aedf4u; return 0; }
r[0]<<=16;
goto P_0c0aedf6;
P_0c0aedf6: /* original 20b9, guest PC 0x0c0aedf6 */
if(!s->budget--) { s->failed_pc=0x0c0aedf6u; return 0; }
r[0]&=r[11];
goto P_0c0aedf8;
P_0c0aedf8: /* original 220b, guest PC 0x0c0aedf8 */
if(!s->budget--) { s->failed_pc=0x0c0aedf8u; return 0; }
r[2]|=r[0];
goto P_0c0aedfa;
P_0c0aedfa: /* original 8469, guest PC 0x0c0aedfa */
if(!s->budget--) { s->failed_pc=0x0c0aedfau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+9,1);
goto P_0c0aedfc;
P_0c0aedfc: /* original 600c, guest PC 0x0c0aedfc */
if(!s->budget--) { s->failed_pc=0x0c0aedfcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0aedfe;
P_0c0aedfe: /* original 4018, guest PC 0x0c0aedfe */
if(!s->budget--) { s->failed_pc=0x0c0aedfeu; return 0; }
r[0]<<=8;
goto P_0c0aee00;
P_0c0aee00: /* original 2099, guest PC 0x0c0aee00 */
if(!s->budget--) { s->failed_pc=0x0c0aee00u; return 0; }
r[0]&=r[9];
goto P_0c0aee02;
P_0c0aee02: /* original 220b, guest PC 0x0c0aee02 */
if(!s->budget--) { s->failed_pc=0x0c0aee02u; return 0; }
r[2]|=r[0];
goto P_0c0aee04;
P_0c0aee04: /* original 8468, guest PC 0x0c0aee04 */
if(!s->budget--) { s->failed_pc=0x0c0aee04u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+8,1);
goto P_0c0aee06;
P_0c0aee06: /* original 600c, guest PC 0x0c0aee06 */
if(!s->budget--) { s->failed_pc=0x0c0aee06u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aee08;
P_0c0aee08: /* original 220b, guest PC 0x0c0aee08 */
if(!s->budget--) { s->failed_pc=0x0c0aee08u; return 0; }
r[2]|=r[0];
goto P_0c0aee0a;
P_0c0aee0a: /* original 1422, guest PC 0x0c0aee0a */
if(!s->budget--) { s->failed_pc=0x0c0aee0au; return 0; }
write(ram,r[4]+8,r[2],4);
goto P_0c0aee0c;
P_0c0aee0c: /* original 56c2, guest PC 0x0c0aee0c */
if(!s->budget--) { s->failed_pc=0x0c0aee0cu; return 0; }
r[6]=read(ram,r[12]+8,4);
goto P_0c0aee0e;
P_0c0aee0e: /* original 846f, guest PC 0x0c0aee0e */
if(!s->budget--) { s->failed_pc=0x0c0aee0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+15,1);
goto P_0c0aee10;
P_0c0aee10: /* original 600c, guest PC 0x0c0aee10 */
if(!s->budget--) { s->failed_pc=0x0c0aee10u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aee12;
P_0c0aee12: /* original 4028, guest PC 0x0c0aee12 */
if(!s->budget--) { s->failed_pc=0x0c0aee12u; return 0; }
r[0]<<=16;
goto P_0c0aee14;
P_0c0aee14: /* original 4018, guest PC 0x0c0aee14 */
if(!s->budget--) { s->failed_pc=0x0c0aee14u; return 0; }
r[0]<<=8;
goto P_0c0aee16;
P_0c0aee16: /* original 2039, guest PC 0x0c0aee16 */
if(!s->budget--) { s->failed_pc=0x0c0aee16u; return 0; }
r[0]&=r[3];
goto P_0c0aee18;
P_0c0aee18: /* original 6203, guest PC 0x0c0aee18 */
if(!s->budget--) { s->failed_pc=0x0c0aee18u; return 0; }
r[2]=r[0];
goto P_0c0aee1a;
P_0c0aee1a: /* original 846e, guest PC 0x0c0aee1a */
if(!s->budget--) { s->failed_pc=0x0c0aee1au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+14,1);
goto P_0c0aee1c;
P_0c0aee1c: /* original 600c, guest PC 0x0c0aee1c */
if(!s->budget--) { s->failed_pc=0x0c0aee1cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0aee1e;
P_0c0aee1e: /* original 4028, guest PC 0x0c0aee1e */
if(!s->budget--) { s->failed_pc=0x0c0aee1eu; return 0; }
r[0]<<=16;
goto P_0c0aee20;
P_0c0aee20: /* original 20b9, guest PC 0x0c0aee20 */
if(!s->budget--) { s->failed_pc=0x0c0aee20u; return 0; }
r[0]&=r[11];
goto P_0c0aee22;
P_0c0aee22: /* original 220b, guest PC 0x0c0aee22 */
if(!s->budget--) { s->failed_pc=0x0c0aee22u; return 0; }
r[2]|=r[0];
goto P_0c0aee24;
P_0c0aee24: /* original 846d, guest PC 0x0c0aee24 */
if(!s->budget--) { s->failed_pc=0x0c0aee24u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+13,1);
goto P_0c0aee26;
P_0c0aee26: /* original 600c, guest PC 0x0c0aee26 */
if(!s->budget--) { s->failed_pc=0x0c0aee26u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aee28;
P_0c0aee28: /* original 4018, guest PC 0x0c0aee28 */
if(!s->budget--) { s->failed_pc=0x0c0aee28u; return 0; }
r[0]<<=8;
goto P_0c0aee2a;
P_0c0aee2a: /* original 2099, guest PC 0x0c0aee2a */
if(!s->budget--) { s->failed_pc=0x0c0aee2au; return 0; }
r[0]&=r[9];
goto P_0c0aee2c;
P_0c0aee2c: /* original 220b, guest PC 0x0c0aee2c */
if(!s->budget--) { s->failed_pc=0x0c0aee2cu; return 0; }
r[2]|=r[0];
goto P_0c0aee2e;
P_0c0aee2e: /* original 846c, guest PC 0x0c0aee2e */
if(!s->budget--) { s->failed_pc=0x0c0aee2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+12,1);
goto P_0c0aee30;
P_0c0aee30: /* original e310, guest PC 0x0c0aee30 */
if(!s->budget--) { s->failed_pc=0x0c0aee30u; return 0; }
r[3]=0x00000010u;
goto P_0c0aee32;
P_0c0aee32: /* original 600c, guest PC 0x0c0aee32 */
if(!s->budget--) { s->failed_pc=0x0c0aee32u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aee34;
P_0c0aee34: /* original 220b, guest PC 0x0c0aee34 */
if(!s->budget--) { s->failed_pc=0x0c0aee34u; return 0; }
r[2]|=r[0];
goto P_0c0aee36;
P_0c0aee36: /* original 1423, guest PC 0x0c0aee36 */
if(!s->budget--) { s->failed_pc=0x0c0aee36u; return 0; }
write(ram,r[4]+12,r[2],4);
goto P_0c0aee38;
P_0c0aee38: /* original e008, guest PC 0x0c0aee38 */
if(!s->budget--) { s->failed_pc=0x0c0aee38u; return 0; }
r[0]=0x00000008u;
goto P_0c0aee3a;
P_0c0aee3a: /* original 54c2, guest PC 0x0c0aee3a */
if(!s->budget--) { s->failed_pc=0x0c0aee3au; return 0; }
r[4]=read(ram,r[12]+8,4);
goto P_0c0aee3c;
P_0c0aee3c: /* original f656, guest PC 0x0c0aee3c */
if(!s->budget--) { s->failed_pc=0x0c0aee3cu; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c0aee3e;
P_0c0aee3e: /* original e00c, guest PC 0x0c0aee3e */
if(!s->budget--) { s->failed_pc=0x0c0aee3eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0aee40;
P_0c0aee40: /* original 7407, guest PC 0x0c0aee40 */
if(!s->budget--) { s->failed_pc=0x0c0aee40u; return 0; }
r[4]+=0x00000007u;
goto P_0c0aee42;
P_0c0aee42: /* original 61e2, guest PC 0x0c0aee42 */
if(!s->budget--) { s->failed_pc=0x0c0aee42u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0aee44;
P_0c0aee44: /* original 6440, guest PC 0x0c0aee44 */
if(!s->budget--) { s->failed_pc=0x0c0aee44u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]=tmp;
goto P_0c0aee46;
P_0c0aee46: /* original d21e, guest PC 0x0c0aee46 */
if(!s->budget--) { s->failed_pc=0x0c0aee46u; return 0; }
r[2]=read(ram,0x0c0aeec0u,4);
goto P_0c0aee48;
P_0c0aee48: /* original f556, guest PC 0x0c0aee48 */
if(!s->budget--) { s->failed_pc=0x0c0aee48u; return 0; }
vf3_matrix_load(s,ram,5,r[5]+r[0]);
goto P_0c0aee4a;
P_0c0aee4a: /* original 644c, guest PC 0x0c0aee4a */
if(!s->budget--) { s->failed_pc=0x0c0aee4au; return 0; }
r[4]=r[4]&255u;
goto P_0c0aee4c;
P_0c0aee4c: /* original 2128, guest PC 0x0c0aee4c */
if(!s->budget--) { s->failed_pc=0x0c0aee4cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0aee4e;
P_0c0aee4e: /* original 85ef, guest PC 0x0c0aee4e */
if(!s->budget--) { s->failed_pc=0x0c0aee4eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0aee50;
P_0c0aee50: /* original 2349, guest PC 0x0c0aee50 */
if(!s->budget--) { s->failed_pc=0x0c0aee50u; return 0; }
r[3]&=r[4];
goto P_0c0aee52;
P_0c0aee52: /* original da1c, guest PC 0x0c0aee52 */
if(!s->budget--) { s->failed_pc=0x0c0aee52u; return 0; }
r[10]=read(ram,0x0c0aeec4u,4);
goto P_0c0aee54;
P_0c0aee54: /* original e202, guest PC 0x0c0aee54 */
if(!s->budget--) { s->failed_pc=0x0c0aee54u; return 0; }
r[2]=0x00000002u;
goto P_0c0aee56;
P_0c0aee56: /* original ff9d, guest PC 0x0c0aee56 */
if(!s->budget--) { s->failed_pc=0x0c0aee56u; return 0; }
fr[15]=0x3f800000u;
goto P_0c0aee58;
P_0c0aee58: /* original 2248, guest PC 0x0c0aee58 */
if(!s->budget--) { s->failed_pc=0x0c0aee58u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0aee5a;
P_0c0aee5a: /* original 6503, guest PC 0x0c0aee5a */
if(!s->budget--) { s->failed_pc=0x0c0aee5au; return 0; }
r[5]=r[0];
goto P_0c0aee5c;
P_0c0aee5c: /* original 1f33, guest PC 0x0c0aee5c */
if(!s->budget--) { s->failed_pc=0x0c0aee5cu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0aee5e;
P_0c0aee5e: /* original 8f35, guest PC 0x0c0aee5e */
if(!s->budget--) { s->failed_pc=0x0c0aee5eu; return 0; }
cond=r[17]&1u;
r[13]=(uint32_t)(int32_t)(int16_t)r[5];
if(!cond) { goto P_0c0aeecc; }
goto P_0c0aee62;
P_0c0aee60: /* original 6d5f, guest PC 0x0c0aee60 */
if(!s->budget--) { s->failed_pc=0x0c0aee60u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c0aee62;
P_0c0aee62: /* original e304, guest PC 0x0c0aee62 */
if(!s->budget--) { s->failed_pc=0x0c0aee62u; return 0; }
r[3]=0x00000004u;
goto P_0c0aee64;
P_0c0aee64: /* original 2438, guest PC 0x0c0aee64 */
if(!s->budget--) { s->failed_pc=0x0c0aee64u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0aee66;
P_0c0aee66: /* original 8b31, guest PC 0x0c0aee66 */
if(!s->budget--) { s->failed_pc=0x0c0aee66u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aeecc; }
goto P_0c0aee68;
P_0c0aee68: /* original e05c, guest PC 0x0c0aee68 */
if(!s->budget--) { s->failed_pc=0x0c0aee68u; return 0; }
r[0]=0x0000005cu;
goto P_0c0aee6a;
P_0c0aee6a: /* original f38d, guest PC 0x0c0aee6a */
if(!s->budget--) { s->failed_pc=0x0c0aee6au; return 0; }
fr[3]=0;
goto P_0c0aee6c;
P_0c0aee6c: /* original f4e6, guest PC 0x0c0aee6c */
if(!s->budget--) { s->failed_pc=0x0c0aee6cu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0aee6e;
P_0c0aee6e: /* original f434, guest PC 0x0c0aee6e */
if(!s->budget--) { s->failed_pc=0x0c0aee6eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c0aee70;
P_0c0aee70: /* original 8b01, guest PC 0x0c0aee70 */
if(!s->budget--) { s->failed_pc=0x0c0aee70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aee76; }
goto P_0c0aee72;
P_0c0aee72: /* original a0d9, guest PC 0x0c0aee72 */
if(!s->budget--) { s->failed_pc=0x0c0aee72u; return 0; }
goto P_0c0af028;
P_0c0aee74: /* original 0009, guest PC 0x0c0aee74 */
if(!s->budget--) { s->failed_pc=0x0c0aee74u; return 0; }
goto P_0c0aee76;
P_0c0aee76: /* original 53f3, guest PC 0x0c0aee76 */
if(!s->budget--) { s->failed_pc=0x0c0aee76u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0aee78;
P_0c0aee78: /* original 2338, guest PC 0x0c0aee78 */
if(!s->budget--) { s->failed_pc=0x0c0aee78u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0aee7a;
P_0c0aee7a: /* original 8900, guest PC 0x0c0aee7a */
if(!s->budget--) { s->failed_pc=0x0c0aee7au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aee7e; }
goto P_0c0aee7c;
P_0c0aee7c: /* original f44d, guest PC 0x0c0aee7c */
if(!s->budget--) { s->failed_pc=0x0c0aee7cu; return 0; }
fr[4]^=0x80000000u;
goto P_0c0aee7e;
P_0c0aee7e: /* original f455, guest PC 0x0c0aee7e */
if(!s->budget--) { s->failed_pc=0x0c0aee7eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0aee80;
P_0c0aee80: /* original 8d01, guest PC 0x0c0aee80 */
if(!s->budget--) { s->failed_pc=0x0c0aee80u; return 0; }
cond=r[17]&1u;
r[4]=r[13];
if(cond) { goto P_0c0aee86; }
goto P_0c0aee84;
P_0c0aee82: /* original 64d3, guest PC 0x0c0aee82 */
if(!s->budget--) { s->failed_pc=0x0c0aee82u; return 0; }
r[4]=r[13];
goto P_0c0aee84;
P_0c0aee84: /* original f465, guest PC 0x0c0aee84 */
if(!s->budget--) { s->failed_pc=0x0c0aee84u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c0aee86;
P_0c0aee86: /* original d210, guest PC 0x0c0aee86 */
if(!s->budget--) { s->failed_pc=0x0c0aee86u; return 0; }
r[2]=read(ram,0x0c0aeec8u,4);
goto P_0c0aee88;
P_0c0aee88: /* original 420b, guest PC 0x0c0aee88 */
if(!s->budget--) { s->failed_pc=0x0c0aee88u; return 0; }
target=r[2];
r[16]=code_base|0x0c0aee8cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aee8cu) { target=s->pc; goto dispatch; }
goto P_0c0aee8c;
P_0c0aee8a: /* original 0009, guest PC 0x0c0aee8a */
if(!s->budget--) { s->failed_pc=0x0c0aee8au; return 0; }
goto P_0c0aee8c;
P_0c0aee8c: /* original ff0a, guest PC 0x0c0aee8c */
if(!s->budget--) { s->failed_pc=0x0c0aee8cu; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aee8e;
P_0c0aee8e: /* original 4a0b, guest PC 0x0c0aee8e */
if(!s->budget--) { s->failed_pc=0x0c0aee8eu; return 0; }
target=r[10];
r[16]=code_base|0x0c0aee92u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aee92u) { target=s->pc; goto dispatch; }
goto P_0c0aee92;
P_0c0aee90: /* original 64d3, guest PC 0x0c0aee90 */
if(!s->budget--) { s->failed_pc=0x0c0aee90u; return 0; }
r[4]=r[13];
goto P_0c0aee92;
P_0c0aee92: /* original f0f2, guest PC 0x0c0aee92 */
if(!s->budget--) { s->failed_pc=0x0c0aee92u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c0aee94;
P_0c0aee94: /* original f04d, guest PC 0x0c0aee94 */
if(!s->budget--) { s->failed_pc=0x0c0aee94u; return 0; }
fr[0]^=0x80000000u;
goto P_0c0aee96;
P_0c0aee96: /* original ff0a, guest PC 0x0c0aee96 */
if(!s->budget--) { s->failed_pc=0x0c0aee96u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aee98;
P_0c0aee98: /* original 4a0b, guest PC 0x0c0aee98 */
if(!s->budget--) { s->failed_pc=0x0c0aee98u; return 0; }
target=r[10];
r[16]=code_base|0x0c0aee9cu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aee9cu) { target=s->pc; goto dispatch; }
goto P_0c0aee9c;
P_0c0aee9a: /* original 64d3, guest PC 0x0c0aee9a */
if(!s->budget--) { s->failed_pc=0x0c0aee9au; return 0; }
r[4]=r[13];
goto P_0c0aee9c;
P_0c0aee9c: /* original f0f2, guest PC 0x0c0aee9c */
if(!s->budget--) { s->failed_pc=0x0c0aee9cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c0aee9e;
P_0c0aee9e: /* original f04d, guest PC 0x0c0aee9e */
if(!s->budget--) { s->failed_pc=0x0c0aee9eu; return 0; }
fr[0]^=0x80000000u;
goto P_0c0aeea0;
P_0c0aeea0: /* original ff0a, guest PC 0x0c0aeea0 */
if(!s->budget--) { s->failed_pc=0x0c0aeea0u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aeea2;
P_0c0aeea2: /* original d309, guest PC 0x0c0aeea2 */
if(!s->budget--) { s->failed_pc=0x0c0aeea2u; return 0; }
r[3]=read(ram,0x0c0aeec8u,4);
goto P_0c0aeea4;
P_0c0aeea4: /* original 430b, guest PC 0x0c0aeea4 */
if(!s->budget--) { s->failed_pc=0x0c0aeea4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0aeea8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aeea8u) { target=s->pc; goto dispatch; }
goto P_0c0aeea8;
P_0c0aeea6: /* original 64d3, guest PC 0x0c0aeea6 */
if(!s->budget--) { s->failed_pc=0x0c0aeea6u; return 0; }
r[4]=r[13];
goto P_0c0aeea8;
P_0c0aeea8: /* original a05d, guest PC 0x0c0aeea8 */
if(!s->budget--) { s->failed_pc=0x0c0aeea8u; return 0; }
goto P_0c0aef66;
P_0c0aeeaa: /* original 0009, guest PC 0x0c0aeeaa */
if(!s->budget--) { s->failed_pc=0x0c0aeeaau; return 0; }
if(!vf3_matrix_family(0x0c0aeeacu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aeeacu; return 0; } return 1;
P_0c0aeecc: /* original 52f3, guest PC 0x0c0aeecc */
if(!s->budget--) { s->failed_pc=0x0c0aeeccu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0aeece;
P_0c0aeece: /* original 2228, guest PC 0x0c0aeece */
if(!s->budget--) { s->failed_pc=0x0c0aeeceu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0aeed0;
P_0c0aeed0: /* original 8f04, guest PC 0x0c0aeed0 */
if(!s->budget--) { s->failed_pc=0x0c0aeed0u; return 0; }
cond=r[17]&1u;
r[4]=r[13];
if(!cond) { goto P_0c0aeedc; }
goto P_0c0aeed4;
P_0c0aeed2: /* original 64d3, guest PC 0x0c0aeed2 */
if(!s->budget--) { s->failed_pc=0x0c0aeed2u; return 0; }
r[4]=r[13];
goto P_0c0aeed4;
P_0c0aeed4: /* original 90ba, guest PC 0x0c0aeed4 */
if(!s->budget--) { s->failed_pc=0x0c0aeed4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af04cu,2);
goto P_0c0aeed6;
P_0c0aeed6: /* original e200, guest PC 0x0c0aeed6 */
if(!s->budget--) { s->failed_pc=0x0c0aeed6u; return 0; }
r[2]=0x00000000u;
goto P_0c0aeed8;
P_0c0aeed8: /* original a003, guest PC 0x0c0aeed8 */
if(!s->budget--) { s->failed_pc=0x0c0aeed8u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0aeee2;
P_0c0aeeda: /* original 0e24, guest PC 0x0c0aeeda */
if(!s->budget--) { s->failed_pc=0x0c0aeedau; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0aeedc;
P_0c0aeedc: /* original 90b6, guest PC 0x0c0aeedc */
if(!s->budget--) { s->failed_pc=0x0c0aeedcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af04cu,2);
goto P_0c0aeede;
P_0c0aeede: /* original e101, guest PC 0x0c0aeede */
if(!s->budget--) { s->failed_pc=0x0c0aeedeu; return 0; }
r[1]=0x00000001u;
goto P_0c0aeee0;
P_0c0aeee0: /* original 0e14, guest PC 0x0c0aeee0 */
if(!s->budget--) { s->failed_pc=0x0c0aeee0u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c0aeee2;
P_0c0aeee2: /* original d35b, guest PC 0x0c0aeee2 */
if(!s->budget--) { s->failed_pc=0x0c0aeee2u; return 0; }
r[3]=read(ram,0x0c0af050u,4);
goto P_0c0aeee4;
P_0c0aeee4: /* original 430b, guest PC 0x0c0aeee4 */
if(!s->budget--) { s->failed_pc=0x0c0aeee4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0aeee8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aeee8u) { target=s->pc; goto dispatch; }
goto P_0c0aeee8;
P_0c0aeee6: /* original 0009, guest PC 0x0c0aeee6 */
if(!s->budget--) { s->failed_pc=0x0c0aeee6u; return 0; }
goto P_0c0aeee8;
P_0c0aeee8: /* original ff0a, guest PC 0x0c0aeee8 */
if(!s->budget--) { s->failed_pc=0x0c0aeee8u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aeeea;
P_0c0aeeea: /* original 4a0b, guest PC 0x0c0aeeea */
if(!s->budget--) { s->failed_pc=0x0c0aeeeau; return 0; }
target=r[10];
r[16]=code_base|0x0c0aeeeeu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aeeeeu) { target=s->pc; goto dispatch; }
goto P_0c0aeeee;
P_0c0aeeec: /* original 64d3, guest PC 0x0c0aeeec */
if(!s->budget--) { s->failed_pc=0x0c0aeeecu; return 0; }
r[4]=r[13];
goto P_0c0aeeee;
P_0c0aeeee: /* original f0f2, guest PC 0x0c0aeeee */
if(!s->budget--) { s->failed_pc=0x0c0aeeeeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c0aeef0;
P_0c0aeef0: /* original f04d, guest PC 0x0c0aeef0 */
if(!s->budget--) { s->failed_pc=0x0c0aeef0u; return 0; }
fr[0]^=0x80000000u;
goto P_0c0aeef2;
P_0c0aeef2: /* original ff0a, guest PC 0x0c0aeef2 */
if(!s->budget--) { s->failed_pc=0x0c0aeef2u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aeef4;
P_0c0aeef4: /* original 4a0b, guest PC 0x0c0aeef4 */
if(!s->budget--) { s->failed_pc=0x0c0aeef4u; return 0; }
target=r[10];
r[16]=code_base|0x0c0aeef8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aeef8u) { target=s->pc; goto dispatch; }
goto P_0c0aeef8;
P_0c0aeef6: /* original 64d3, guest PC 0x0c0aeef6 */
if(!s->budget--) { s->failed_pc=0x0c0aeef6u; return 0; }
r[4]=r[13];
goto P_0c0aeef8;
P_0c0aeef8: /* original f0f2, guest PC 0x0c0aeef8 */
if(!s->budget--) { s->failed_pc=0x0c0aeef8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c0aeefa;
P_0c0aeefa: /* original f04d, guest PC 0x0c0aeefa */
if(!s->budget--) { s->failed_pc=0x0c0aeefau; return 0; }
fr[0]^=0x80000000u;
goto P_0c0aeefc;
P_0c0aeefc: /* original ff0a, guest PC 0x0c0aeefc */
if(!s->budget--) { s->failed_pc=0x0c0aeefcu; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aeefe;
P_0c0aeefe: /* original d354, guest PC 0x0c0aeefe */
if(!s->budget--) { s->failed_pc=0x0c0aeefeu; return 0; }
r[3]=read(ram,0x0c0af050u,4);
goto P_0c0aef00;
P_0c0aef00: /* original 430b, guest PC 0x0c0aef00 */
if(!s->budget--) { s->failed_pc=0x0c0aef00u; return 0; }
target=r[3];
r[16]=code_base|0x0c0aef04u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aef04u) { target=s->pc; goto dispatch; }
goto P_0c0aef04;
P_0c0aef02: /* original 64d3, guest PC 0x0c0aef02 */
if(!s->budget--) { s->failed_pc=0x0c0aef02u; return 0; }
r[4]=r[13];
goto P_0c0aef04;
P_0c0aef04: /* original 65f3, guest PC 0x0c0aef04 */
if(!s->budget--) { s->failed_pc=0x0c0aef04u; return 0; }
r[5]=r[15];
goto P_0c0aef06;
P_0c0aef06: /* original 752c, guest PC 0x0c0aef06 */
if(!s->budget--) { s->failed_pc=0x0c0aef06u; return 0; }
r[5]+=0x0000002cu;
goto P_0c0aef08;
P_0c0aef08: /* original ff0a, guest PC 0x0c0aef08 */
if(!s->budget--) { s->failed_pc=0x0c0aef08u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aef0a;
P_0c0aef0a: /* original 54c2, guest PC 0x0c0aef0a */
if(!s->budget--) { s->failed_pc=0x0c0aef0au; return 0; }
r[4]=read(ram,r[12]+8,4);
goto P_0c0aef0c;
P_0c0aef0c: /* original 6343, guest PC 0x0c0aef0c */
if(!s->budget--) { s->failed_pc=0x0c0aef0cu; return 0; }
r[3]=r[4];
goto P_0c0aef0e;
P_0c0aef0e: /* original 731b, guest PC 0x0c0aef0e */
if(!s->budget--) { s->failed_pc=0x0c0aef0eu; return 0; }
r[3]+=0x0000001bu;
goto P_0c0aef10;
P_0c0aef10: /* original 6143, guest PC 0x0c0aef10 */
if(!s->budget--) { s->failed_pc=0x0c0aef10u; return 0; }
r[1]=r[4];
goto P_0c0aef12;
P_0c0aef12: /* original 6230, guest PC 0x0c0aef12 */
if(!s->budget--) { s->failed_pc=0x0c0aef12u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c0aef14;
P_0c0aef14: /* original 711a, guest PC 0x0c0aef14 */
if(!s->budget--) { s->failed_pc=0x0c0aef14u; return 0; }
r[1]+=0x0000001au;
goto P_0c0aef16;
P_0c0aef16: /* original d34f, guest PC 0x0c0aef16 */
if(!s->budget--) { s->failed_pc=0x0c0aef16u; return 0; }
r[3]=read(ram,0x0c0af054u,4);
goto P_0c0aef18;
P_0c0aef18: /* original 6010, guest PC 0x0c0aef18 */
if(!s->budget--) { s->failed_pc=0x0c0aef18u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[0]=tmp;
goto P_0c0aef1a;
P_0c0aef1a: /* original 622c, guest PC 0x0c0aef1a */
if(!s->budget--) { s->failed_pc=0x0c0aef1au; return 0; }
r[2]=r[2]&255u;
goto P_0c0aef1c;
P_0c0aef1c: /* original 4228, guest PC 0x0c0aef1c */
if(!s->budget--) { s->failed_pc=0x0c0aef1cu; return 0; }
r[2]<<=16;
goto P_0c0aef1e;
P_0c0aef1e: /* original 6143, guest PC 0x0c0aef1e */
if(!s->budget--) { s->failed_pc=0x0c0aef1eu; return 0; }
r[1]=r[4];
goto P_0c0aef20;
P_0c0aef20: /* original 600c, guest PC 0x0c0aef20 */
if(!s->budget--) { s->failed_pc=0x0c0aef20u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aef22;
P_0c0aef22: /* original 4218, guest PC 0x0c0aef22 */
if(!s->budget--) { s->failed_pc=0x0c0aef22u; return 0; }
r[2]<<=8;
goto P_0c0aef24;
P_0c0aef24: /* original 4028, guest PC 0x0c0aef24 */
if(!s->budget--) { s->failed_pc=0x0c0aef24u; return 0; }
r[0]<<=16;
goto P_0c0aef26;
P_0c0aef26: /* original 2239, guest PC 0x0c0aef26 */
if(!s->budget--) { s->failed_pc=0x0c0aef26u; return 0; }
r[2]&=r[3];
goto P_0c0aef28;
P_0c0aef28: /* original 20b9, guest PC 0x0c0aef28 */
if(!s->budget--) { s->failed_pc=0x0c0aef28u; return 0; }
r[0]&=r[11];
goto P_0c0aef2a;
P_0c0aef2a: /* original 7119, guest PC 0x0c0aef2a */
if(!s->budget--) { s->failed_pc=0x0c0aef2au; return 0; }
r[1]+=0x00000019u;
goto P_0c0aef2c;
P_0c0aef2c: /* original 220b, guest PC 0x0c0aef2c */
if(!s->budget--) { s->failed_pc=0x0c0aef2cu; return 0; }
r[2]|=r[0];
goto P_0c0aef2e;
P_0c0aef2e: /* original 6010, guest PC 0x0c0aef2e */
if(!s->budget--) { s->failed_pc=0x0c0aef2eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[0]=tmp;
goto P_0c0aef30;
P_0c0aef30: /* original 6143, guest PC 0x0c0aef30 */
if(!s->budget--) { s->failed_pc=0x0c0aef30u; return 0; }
r[1]=r[4];
goto P_0c0aef32;
P_0c0aef32: /* original 7118, guest PC 0x0c0aef32 */
if(!s->budget--) { s->failed_pc=0x0c0aef32u; return 0; }
r[1]+=0x00000018u;
goto P_0c0aef34;
P_0c0aef34: /* original 600c, guest PC 0x0c0aef34 */
if(!s->budget--) { s->failed_pc=0x0c0aef34u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aef36;
P_0c0aef36: /* original 4018, guest PC 0x0c0aef36 */
if(!s->budget--) { s->failed_pc=0x0c0aef36u; return 0; }
r[0]<<=8;
goto P_0c0aef38;
P_0c0aef38: /* original 2099, guest PC 0x0c0aef38 */
if(!s->budget--) { s->failed_pc=0x0c0aef38u; return 0; }
r[0]&=r[9];
goto P_0c0aef3a;
P_0c0aef3a: /* original 220b, guest PC 0x0c0aef3a */
if(!s->budget--) { s->failed_pc=0x0c0aef3au; return 0; }
r[2]|=r[0];
goto P_0c0aef3c;
P_0c0aef3c: /* original 6010, guest PC 0x0c0aef3c */
if(!s->budget--) { s->failed_pc=0x0c0aef3cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[0]=tmp;
goto P_0c0aef3e;
P_0c0aef3e: /* original 600c, guest PC 0x0c0aef3e */
if(!s->budget--) { s->failed_pc=0x0c0aef3eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0aef40;
P_0c0aef40: /* original 220b, guest PC 0x0c0aef40 */
if(!s->budget--) { s->failed_pc=0x0c0aef40u; return 0; }
r[2]|=r[0];
goto P_0c0aef42;
P_0c0aef42: /* original 2522, guest PC 0x0c0aef42 */
if(!s->budget--) { s->failed_pc=0x0c0aef42u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c0aef44;
P_0c0aef44: /* original d242, guest PC 0x0c0aef44 */
if(!s->budget--) { s->failed_pc=0x0c0aef44u; return 0; }
r[2]=read(ram,0x0c0af050u,4);
goto P_0c0aef46;
P_0c0aef46: /* original 420b, guest PC 0x0c0aef46 */
if(!s->budget--) { s->failed_pc=0x0c0aef46u; return 0; }
target=r[2];
r[16]=code_base|0x0c0aef4au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aef4au) { target=s->pc; goto dispatch; }
goto P_0c0aef4a;
P_0c0aef48: /* original 64d3, guest PC 0x0c0aef48 */
if(!s->budget--) { s->failed_pc=0x0c0aef48u; return 0; }
r[4]=r[13];
goto P_0c0aef4a;
P_0c0aef4a: /* original ff0a, guest PC 0x0c0aef4a */
if(!s->budget--) { s->failed_pc=0x0c0aef4au; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aef4c;
P_0c0aef4c: /* original 4a0b, guest PC 0x0c0aef4c */
if(!s->budget--) { s->failed_pc=0x0c0aef4cu; return 0; }
target=r[10];
r[16]=code_base|0x0c0aef50u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aef50u) { target=s->pc; goto dispatch; }
goto P_0c0aef50;
P_0c0aef4e: /* original 64d3, guest PC 0x0c0aef4e */
if(!s->budget--) { s->failed_pc=0x0c0aef4eu; return 0; }
r[4]=r[13];
goto P_0c0aef50;
P_0c0aef50: /* original f0f2, guest PC 0x0c0aef50 */
if(!s->budget--) { s->failed_pc=0x0c0aef50u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c0aef52;
P_0c0aef52: /* original f04d, guest PC 0x0c0aef52 */
if(!s->budget--) { s->failed_pc=0x0c0aef52u; return 0; }
fr[0]^=0x80000000u;
goto P_0c0aef54;
P_0c0aef54: /* original ff0a, guest PC 0x0c0aef54 */
if(!s->budget--) { s->failed_pc=0x0c0aef54u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aef56;
P_0c0aef56: /* original 4a0b, guest PC 0x0c0aef56 */
if(!s->budget--) { s->failed_pc=0x0c0aef56u; return 0; }
target=r[10];
r[16]=code_base|0x0c0aef5au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aef5au) { target=s->pc; goto dispatch; }
goto P_0c0aef5a;
P_0c0aef58: /* original 64d3, guest PC 0x0c0aef58 */
if(!s->budget--) { s->failed_pc=0x0c0aef58u; return 0; }
r[4]=r[13];
goto P_0c0aef5a;
P_0c0aef5a: /* original f0f2, guest PC 0x0c0aef5a */
if(!s->budget--) { s->failed_pc=0x0c0aef5au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c0aef5c;
P_0c0aef5c: /* original f04d, guest PC 0x0c0aef5c */
if(!s->budget--) { s->failed_pc=0x0c0aef5cu; return 0; }
fr[0]^=0x80000000u;
goto P_0c0aef5e;
P_0c0aef5e: /* original ff0a, guest PC 0x0c0aef5e */
if(!s->budget--) { s->failed_pc=0x0c0aef5eu; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aef60;
P_0c0aef60: /* original d33b, guest PC 0x0c0aef60 */
if(!s->budget--) { s->failed_pc=0x0c0aef60u; return 0; }
r[3]=read(ram,0x0c0af050u,4);
goto P_0c0aef62;
P_0c0aef62: /* original 430b, guest PC 0x0c0aef62 */
if(!s->budget--) { s->failed_pc=0x0c0aef62u; return 0; }
target=r[3];
r[16]=code_base|0x0c0aef66u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aef66u) { target=s->pc; goto dispatch; }
goto P_0c0aef66;
P_0c0aef64: /* original 64d3, guest PC 0x0c0aef64 */
if(!s->budget--) { s->failed_pc=0x0c0aef64u; return 0; }
r[4]=r[13];
goto P_0c0aef66;
P_0c0aef66: /* original ff0a, guest PC 0x0c0aef66 */
if(!s->budget--) { s->failed_pc=0x0c0aef66u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aef68;
P_0c0aef68: /* original d339, guest PC 0x0c0aef68 */
if(!s->budget--) { s->failed_pc=0x0c0aef68u; return 0; }
r[3]=read(ram,0x0c0af050u,4);
goto P_0c0aef6a;
P_0c0aef6a: /* original 430b, guest PC 0x0c0aef6a */
if(!s->budget--) { s->failed_pc=0x0c0aef6au; return 0; }
target=r[3];
r[16]=code_base|0x0c0aef6eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aef6eu) { target=s->pc; goto dispatch; }
goto P_0c0aef6e;
P_0c0aef6c: /* original 64d3, guest PC 0x0c0aef6c */
if(!s->budget--) { s->failed_pc=0x0c0aef6cu; return 0; }
r[4]=r[13];
goto P_0c0aef6e;
P_0c0aef6e: /* original ff0a, guest PC 0x0c0aef6e */
if(!s->budget--) { s->failed_pc=0x0c0aef6eu; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aef70;
P_0c0aef70: /* original 4a0b, guest PC 0x0c0aef70 */
if(!s->budget--) { s->failed_pc=0x0c0aef70u; return 0; }
target=r[10];
r[16]=code_base|0x0c0aef74u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aef74u) { target=s->pc; goto dispatch; }
goto P_0c0aef74;
P_0c0aef72: /* original 64d3, guest PC 0x0c0aef72 */
if(!s->budget--) { s->failed_pc=0x0c0aef72u; return 0; }
r[4]=r[13];
goto P_0c0aef74;
P_0c0aef74: /* original ff0a, guest PC 0x0c0aef74 */
if(!s->budget--) { s->failed_pc=0x0c0aef74u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aef76;
P_0c0aef76: /* original 4a0b, guest PC 0x0c0aef76 */
if(!s->budget--) { s->failed_pc=0x0c0aef76u; return 0; }
target=r[10];
r[16]=code_base|0x0c0aef7au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aef7au) { target=s->pc; goto dispatch; }
goto P_0c0aef7a;
P_0c0aef78: /* original 64d3, guest PC 0x0c0aef78 */
if(!s->budget--) { s->failed_pc=0x0c0aef78u; return 0; }
r[4]=r[13];
goto P_0c0aef7a;
P_0c0aef7a: /* original ff0a, guest PC 0x0c0aef7a */
if(!s->budget--) { s->failed_pc=0x0c0aef7au; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aef7c;
P_0c0aef7c: /* original d334, guest PC 0x0c0aef7c */
if(!s->budget--) { s->failed_pc=0x0c0aef7cu; return 0; }
r[3]=read(ram,0x0c0af050u,4);
goto P_0c0aef7e;
P_0c0aef7e: /* original 430b, guest PC 0x0c0aef7e */
if(!s->budget--) { s->failed_pc=0x0c0aef7eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0aef82u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aef82u) { target=s->pc; goto dispatch; }
goto P_0c0aef82;
P_0c0aef80: /* original 64d3, guest PC 0x0c0aef80 */
if(!s->budget--) { s->failed_pc=0x0c0aef80u; return 0; }
r[4]=r[13];
goto P_0c0aef82;
P_0c0aef82: /* original 63f3, guest PC 0x0c0aef82 */
if(!s->budget--) { s->failed_pc=0x0c0aef82u; return 0; }
r[3]=r[15];
goto P_0c0aef84;
P_0c0aef84: /* original 7308, guest PC 0x0c0aef84 */
if(!s->budget--) { s->failed_pc=0x0c0aef84u; return 0; }
r[3]+=0x00000008u;
goto P_0c0aef86;
P_0c0aef86: /* original ff0a, guest PC 0x0c0aef86 */
if(!s->budget--) { s->failed_pc=0x0c0aef86u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aef88;
P_0c0aef88: /* original 2f36, guest PC 0x0c0aef88 */
if(!s->budget--) { s->failed_pc=0x0c0aef88u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aef8a;
P_0c0aef8a: /* original 66f3, guest PC 0x0c0aef8a */
if(!s->budget--) { s->failed_pc=0x0c0aef8au; return 0; }
r[6]=r[15];
goto P_0c0aef8c;
P_0c0aef8c: /* original 65f3, guest PC 0x0c0aef8c */
if(!s->budget--) { s->failed_pc=0x0c0aef8cu; return 0; }
r[5]=r[15];
goto P_0c0aef8e;
P_0c0aef8e: /* original 67f3, guest PC 0x0c0aef8e */
if(!s->budget--) { s->failed_pc=0x0c0aef8eu; return 0; }
r[7]=r[15];
goto P_0c0aef90;
P_0c0aef90: /* original d231, guest PC 0x0c0aef90 */
if(!s->budget--) { s->failed_pc=0x0c0aef90u; return 0; }
r[2]=read(ram,0x0c0af058u,4);
goto P_0c0aef92;
P_0c0aef92: /* original 7504, guest PC 0x0c0aef92 */
if(!s->budget--) { s->failed_pc=0x0c0aef92u; return 0; }
r[5]+=0x00000004u;
goto P_0c0aef94;
P_0c0aef94: /* original 7714, guest PC 0x0c0aef94 */
if(!s->budget--) { s->failed_pc=0x0c0aef94u; return 0; }
r[7]+=0x00000014u;
goto P_0c0aef96;
P_0c0aef96: /* original 7608, guest PC 0x0c0aef96 */
if(!s->budget--) { s->failed_pc=0x0c0aef96u; return 0; }
r[6]+=0x00000008u;
goto P_0c0aef98;
P_0c0aef98: /* original 420b, guest PC 0x0c0aef98 */
if(!s->budget--) { s->failed_pc=0x0c0aef98u; return 0; }
target=r[2];
r[16]=code_base|0x0c0aef9cu;
r[4]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aef9cu) { target=s->pc; goto dispatch; }
goto P_0c0aef9c;
P_0c0aef9a: /* original 6483, guest PC 0x0c0aef9a */
if(!s->budget--) { s->failed_pc=0x0c0aef9au; return 0; }
r[4]=r[8];
goto P_0c0aef9c;
P_0c0aef9c: /* original 7f04, guest PC 0x0c0aef9c */
if(!s->budget--) { s->failed_pc=0x0c0aef9cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aef9e;
P_0c0aef9e: /* original 53f3, guest PC 0x0c0aef9e */
if(!s->budget--) { s->failed_pc=0x0c0aef9eu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0aefa0;
P_0c0aefa0: /* original 2338, guest PC 0x0c0aefa0 */
if(!s->budget--) { s->failed_pc=0x0c0aefa0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0aefa2;
P_0c0aefa2: /* original 8903, guest PC 0x0c0aefa2 */
if(!s->budget--) { s->failed_pc=0x0c0aefa2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aefac; }
goto P_0c0aefa4;
P_0c0aefa4: /* original 52f2, guest PC 0x0c0aefa4 */
if(!s->budget--) { s->failed_pc=0x0c0aefa4u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0aefa6;
P_0c0aefa6: /* original d32d, guest PC 0x0c0aefa6 */
if(!s->budget--) { s->failed_pc=0x0c0aefa6u; return 0; }
r[3]=read(ram,0x0c0af05cu,4);
goto P_0c0aefa8;
P_0c0aefa8: /* original 223a, guest PC 0x0c0aefa8 */
if(!s->budget--) { s->failed_pc=0x0c0aefa8u; return 0; }
r[2]^=r[3];
goto P_0c0aefaa;
P_0c0aefaa: /* original 1f22, guest PC 0x0c0aefaa */
if(!s->budget--) { s->failed_pc=0x0c0aefaau; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0aefac;
P_0c0aefac: /* original 904f, guest PC 0x0c0aefac */
if(!s->budget--) { s->failed_pc=0x0c0aefacu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af04eu,2);
goto P_0c0aefae;
P_0c0aefae: /* original 64f3, guest PC 0x0c0aefae */
if(!s->budget--) { s->failed_pc=0x0c0aefaeu; return 0; }
r[4]=r[15];
goto P_0c0aefb0;
P_0c0aefb0: /* original 53f2, guest PC 0x0c0aefb0 */
if(!s->budget--) { s->failed_pc=0x0c0aefb0u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0aefb2;
P_0c0aefb2: /* original 742c, guest PC 0x0c0aefb2 */
if(!s->budget--) { s->failed_pc=0x0c0aefb2u; return 0; }
r[4]+=0x0000002cu;
goto P_0c0aefb4;
P_0c0aefb4: /* original 6543, guest PC 0x0c0aefb4 */
if(!s->budget--) { s->failed_pc=0x0c0aefb4u; return 0; }
r[5]=r[4];
goto P_0c0aefb6;
P_0c0aefb6: /* original 6643, guest PC 0x0c0aefb6 */
if(!s->budget--) { s->failed_pc=0x0c0aefb6u; return 0; }
r[6]=r[4];
goto P_0c0aefb8;
P_0c0aefb8: /* original 3038, guest PC 0x0c0aefb8 */
if(!s->budget--) { s->failed_pc=0x0c0aefb8u; return 0; }
r[0]-=r[3];
goto P_0c0aefba;
P_0c0aefba: /* original 81ef, guest PC 0x0c0aefba */
if(!s->budget--) { s->failed_pc=0x0c0aefbau; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0aefbc;
P_0c0aefbc: /* original e010, guest PC 0x0c0aefbc */
if(!s->budget--) { s->failed_pc=0x0c0aefbcu; return 0; }
r[0]=0x00000010u;
goto P_0c0aefbe;
P_0c0aefbe: /* original f586, guest PC 0x0c0aefbe */
if(!s->budget--) { s->failed_pc=0x0c0aefbeu; return 0; }
vf3_matrix_load(s,ram,5,r[8]+r[0]);
goto P_0c0aefc0;
P_0c0aefc0: /* original e018, guest PC 0x0c0aefc0 */
if(!s->budget--) { s->failed_pc=0x0c0aefc0u; return 0; }
r[0]=0x00000018u;
goto P_0c0aefc2;
P_0c0aefc2: /* original f486, guest PC 0x0c0aefc2 */
if(!s->budget--) { s->failed_pc=0x0c0aefc2u; return 0; }
vf3_matrix_load(s,ram,4,r[8]+r[0]);
goto P_0c0aefc4;
P_0c0aefc4: /* original e004, guest PC 0x0c0aefc4 */
if(!s->budget--) { s->failed_pc=0x0c0aefc4u; return 0; }
r[0]=0x00000004u;
goto P_0c0aefc6;
P_0c0aefc6: /* original f3f8, guest PC 0x0c0aefc6 */
if(!s->budget--) { s->failed_pc=0x0c0aefc6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0aefc8;
P_0c0aefc8: /* original f351, guest PC 0x0c0aefc8 */
if(!s->budget--) { s->failed_pc=0x0c0aefc8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c0aefca;
P_0c0aefca: /* original ff3a, guest PC 0x0c0aefca */
if(!s->budget--) { s->failed_pc=0x0c0aefcau; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0aefcc;
P_0c0aefcc: /* original f2f6, guest PC 0x0c0aefcc */
if(!s->budget--) { s->failed_pc=0x0c0aefccu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0aefce;
P_0c0aefce: /* original e004, guest PC 0x0c0aefce */
if(!s->budget--) { s->failed_pc=0x0c0aefceu; return 0; }
r[0]=0x00000004u;
goto P_0c0aefd0;
P_0c0aefd0: /* original f44d, guest PC 0x0c0aefd0 */
if(!s->budget--) { s->failed_pc=0x0c0aefd0u; return 0; }
fr[4]^=0x80000000u;
goto P_0c0aefd2;
P_0c0aefd2: /* original f421, guest PC 0x0c0aefd2 */
if(!s->budget--) { s->failed_pc=0x0c0aefd2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'-');
goto P_0c0aefd4;
P_0c0aefd4: /* original ff47, guest PC 0x0c0aefd4 */
if(!s->budget--) { s->failed_pc=0x0c0aefd4u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0aefd6;
P_0c0aefd6: /* original 54c2, guest PC 0x0c0aefd6 */
if(!s->budget--) { s->failed_pc=0x0c0aefd6u; return 0; }
r[4]=read(ram,r[12]+8,4);
goto P_0c0aefd8;
P_0c0aefd8: /* original d31e, guest PC 0x0c0aefd8 */
if(!s->budget--) { s->failed_pc=0x0c0aefd8u; return 0; }
r[3]=read(ram,0x0c0af054u,4);
goto P_0c0aefda;
P_0c0aefda: /* original 8446, guest PC 0x0c0aefda */
if(!s->budget--) { s->failed_pc=0x0c0aefdau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+6,1);
goto P_0c0aefdc;
P_0c0aefdc: /* original 600c, guest PC 0x0c0aefdc */
if(!s->budget--) { s->failed_pc=0x0c0aefdcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0aefde;
P_0c0aefde: /* original 4028, guest PC 0x0c0aefde */
if(!s->budget--) { s->failed_pc=0x0c0aefdeu; return 0; }
r[0]<<=16;
goto P_0c0aefe0;
P_0c0aefe0: /* original 4018, guest PC 0x0c0aefe0 */
if(!s->budget--) { s->failed_pc=0x0c0aefe0u; return 0; }
r[0]<<=8;
goto P_0c0aefe2;
P_0c0aefe2: /* original 2039, guest PC 0x0c0aefe2 */
if(!s->budget--) { s->failed_pc=0x0c0aefe2u; return 0; }
r[0]&=r[3];
goto P_0c0aefe4;
P_0c0aefe4: /* original 6203, guest PC 0x0c0aefe4 */
if(!s->budget--) { s->failed_pc=0x0c0aefe4u; return 0; }
r[2]=r[0];
goto P_0c0aefe6;
P_0c0aefe6: /* original 8445, guest PC 0x0c0aefe6 */
if(!s->budget--) { s->failed_pc=0x0c0aefe6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+5,1);
goto P_0c0aefe8;
P_0c0aefe8: /* original 600c, guest PC 0x0c0aefe8 */
if(!s->budget--) { s->failed_pc=0x0c0aefe8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aefea;
P_0c0aefea: /* original 4028, guest PC 0x0c0aefea */
if(!s->budget--) { s->failed_pc=0x0c0aefeau; return 0; }
r[0]<<=16;
goto P_0c0aefec;
P_0c0aefec: /* original 20b9, guest PC 0x0c0aefec */
if(!s->budget--) { s->failed_pc=0x0c0aefecu; return 0; }
r[0]&=r[11];
goto P_0c0aefee;
P_0c0aefee: /* original 220b, guest PC 0x0c0aefee */
if(!s->budget--) { s->failed_pc=0x0c0aefeeu; return 0; }
r[2]|=r[0];
goto P_0c0aeff0;
P_0c0aeff0: /* original 8444, guest PC 0x0c0aeff0 */
if(!s->budget--) { s->failed_pc=0x0c0aeff0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+4,1);
goto P_0c0aeff2;
P_0c0aeff2: /* original 600c, guest PC 0x0c0aeff2 */
if(!s->budget--) { s->failed_pc=0x0c0aeff2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aeff4;
P_0c0aeff4: /* original 4018, guest PC 0x0c0aeff4 */
if(!s->budget--) { s->failed_pc=0x0c0aeff4u; return 0; }
r[0]<<=8;
goto P_0c0aeff6;
P_0c0aeff6: /* original 2099, guest PC 0x0c0aeff6 */
if(!s->budget--) { s->failed_pc=0x0c0aeff6u; return 0; }
r[0]&=r[9];
goto P_0c0aeff8;
P_0c0aeff8: /* original 220b, guest PC 0x0c0aeff8 */
if(!s->budget--) { s->failed_pc=0x0c0aeff8u; return 0; }
r[2]|=r[0];
goto P_0c0aeffa;
P_0c0aeffa: /* original 8443, guest PC 0x0c0aeffa */
if(!s->budget--) { s->failed_pc=0x0c0aeffau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c0aeffc;
P_0c0aeffc: /* original 600c, guest PC 0x0c0aeffc */
if(!s->budget--) { s->failed_pc=0x0c0aeffcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0aeffe;
P_0c0aeffe: /* original 220b, guest PC 0x0c0aeffe */
if(!s->budget--) { s->failed_pc=0x0c0aeffeu; return 0; }
r[2]|=r[0];
goto P_0c0af000;
P_0c0af000: /* original e004, guest PC 0x0c0af000 */
if(!s->budget--) { s->failed_pc=0x0c0af000u; return 0; }
r[0]=0x00000004u;
goto P_0c0af002;
P_0c0af002: /* original 2522, guest PC 0x0c0af002 */
if(!s->budget--) { s->failed_pc=0x0c0af002u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c0af004;
P_0c0af004: /* original f368, guest PC 0x0c0af004 */
if(!s->budget--) { s->failed_pc=0x0c0af004u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
goto P_0c0af006;
P_0c0af006: /* original f4fc, guest PC 0x0c0af006 */
if(!s->budget--) { s->failed_pc=0x0c0af006u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0af008;
P_0c0af008: /* original f433, guest PC 0x0c0af008 */
if(!s->budget--) { s->failed_pc=0x0c0af008u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c0af00a;
P_0c0af00a: /* original f3f8, guest PC 0x0c0af00a */
if(!s->budget--) { s->failed_pc=0x0c0af00au; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0af00c;
P_0c0af00c: /* original f24c, guest PC 0x0c0af00c */
if(!s->budget--) { s->failed_pc=0x0c0af00cu; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0af00e;
P_0c0af00e: /* original f232, guest PC 0x0c0af00e */
if(!s->budget--) { s->failed_pc=0x0c0af00eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0af010;
P_0c0af010: /* original ff2a, guest PC 0x0c0af010 */
if(!s->budget--) { s->failed_pc=0x0c0af010u; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c0af012;
P_0c0af012: /* original f3f6, guest PC 0x0c0af012 */
if(!s->budget--) { s->failed_pc=0x0c0af012u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0af014;
P_0c0af014: /* original e004, guest PC 0x0c0af014 */
if(!s->budget--) { s->failed_pc=0x0c0af014u; return 0; }
r[0]=0x00000004u;
goto P_0c0af016;
P_0c0af016: /* original f432, guest PC 0x0c0af016 */
if(!s->budget--) { s->failed_pc=0x0c0af016u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0af018;
P_0c0af018: /* original ff47, guest PC 0x0c0af018 */
if(!s->budget--) { s->failed_pc=0x0c0af018u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0af01a;
P_0c0af01a: /* original e024, guest PC 0x0c0af01a */
if(!s->budget--) { s->failed_pc=0x0c0af01au; return 0; }
r[0]=0x00000024u;
goto P_0c0af01c;
P_0c0af01c: /* original f3f8, guest PC 0x0c0af01c */
if(!s->budget--) { s->failed_pc=0x0c0af01cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0af01e;
P_0c0af01e: /* original fe37, guest PC 0x0c0af01e */
if(!s->budget--) { s->failed_pc=0x0c0af01eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0af020;
P_0c0af020: /* original e004, guest PC 0x0c0af020 */
if(!s->budget--) { s->failed_pc=0x0c0af020u; return 0; }
r[0]=0x00000004u;
goto P_0c0af022;
P_0c0af022: /* original f3f6, guest PC 0x0c0af022 */
if(!s->budget--) { s->failed_pc=0x0c0af022u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0af024;
P_0c0af024: /* original e02c, guest PC 0x0c0af024 */
if(!s->budget--) { s->failed_pc=0x0c0af024u; return 0; }
r[0]=0x0000002cu;
goto P_0c0af026;
P_0c0af026: /* original fe37, guest PC 0x0c0af026 */
if(!s->budget--) { s->failed_pc=0x0c0af026u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0af028;
P_0c0af028: /* original 53c2, guest PC 0x0c0af028 */
if(!s->budget--) { s->failed_pc=0x0c0af028u; return 0; }
r[3]=read(ram,r[12]+8,4);
goto P_0c0af02a;
P_0c0af02a: /* original 6583, guest PC 0x0c0af02a */
if(!s->budget--) { s->failed_pc=0x0c0af02au; return 0; }
r[5]=r[8];
goto P_0c0af02c;
P_0c0af02c: /* original 66c3, guest PC 0x0c0af02c */
if(!s->budget--) { s->failed_pc=0x0c0af02cu; return 0; }
r[6]=r[12];
goto P_0c0af02e;
P_0c0af02e: /* original 731c, guest PC 0x0c0af02e */
if(!s->budget--) { s->failed_pc=0x0c0af02eu; return 0; }
r[3]+=0x0000001cu;
goto P_0c0af030;
P_0c0af030: /* original 1c32, guest PC 0x0c0af030 */
if(!s->budget--) { s->failed_pc=0x0c0af030u; return 0; }
write(ram,r[12]+8,r[3],4);
goto P_0c0af032;
P_0c0af032: /* original b933, guest PC 0x0c0af032 */
if(!s->budget--) { s->failed_pc=0x0c0af032u; return 0; }
target=code_base|0x0c0ae29cu; r[16]=code_base|0x0c0af036u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0af036u) { target=s->pc; goto dispatch; }
goto P_0c0af036;
P_0c0af034: /* original 64e3, guest PC 0x0c0af034 */
if(!s->budget--) { s->failed_pc=0x0c0af034u; return 0; }
r[4]=r[14];
goto P_0c0af036;
P_0c0af036: /* original 7f34, guest PC 0x0c0af036 */
if(!s->budget--) { s->failed_pc=0x0c0af036u; return 0; }
r[15]+=0x00000034u;
goto P_0c0af038;
P_0c0af038: /* original 4f26, guest PC 0x0c0af038 */
if(!s->budget--) { s->failed_pc=0x0c0af038u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0af03a;
P_0c0af03a: /* original fff9, guest PC 0x0c0af03a */
if(!s->budget--) { s->failed_pc=0x0c0af03au; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0af03c;
P_0c0af03c: /* original 68f6, guest PC 0x0c0af03c */
if(!s->budget--) { s->failed_pc=0x0c0af03cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0af03e;
P_0c0af03e: /* original 69f6, guest PC 0x0c0af03e */
if(!s->budget--) { s->failed_pc=0x0c0af03eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0af040;
P_0c0af040: /* original 6af6, guest PC 0x0c0af040 */
if(!s->budget--) { s->failed_pc=0x0c0af040u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0af042;
P_0c0af042: /* original 6bf6, guest PC 0x0c0af042 */
if(!s->budget--) { s->failed_pc=0x0c0af042u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0af044;
P_0c0af044: /* original 6cf6, guest PC 0x0c0af044 */
if(!s->budget--) { s->failed_pc=0x0c0af044u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0af046;
P_0c0af046: /* original 6df6, guest PC 0x0c0af046 */
if(!s->budget--) { s->failed_pc=0x0c0af046u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0af048;
P_0c0af048: /* original 000b, guest PC 0x0c0af048 */
if(!s->budget--) { s->failed_pc=0x0c0af048u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0af04a: /* original 6ef6, guest PC 0x0c0af04a */
if(!s->budget--) { s->failed_pc=0x0c0af04au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0af04cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0af04cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
