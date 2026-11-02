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
int vf3_away_batch38_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06cbe4u: goto P_0c06cbe4;
case 0x0c06cbe6u: goto P_0c06cbe6;
case 0x0c06cbe8u: goto P_0c06cbe8;
case 0x0c06cbeau: goto P_0c06cbea;
case 0x0c06cbecu: goto P_0c06cbec;
case 0x0c06cbeeu: goto P_0c06cbee;
case 0x0c06cbf0u: goto P_0c06cbf0;
case 0x0c06cbf2u: goto P_0c06cbf2;
case 0x0c06cbf4u: goto P_0c06cbf4;
case 0x0c06cbf6u: goto P_0c06cbf6;
case 0x0c06cbf8u: goto P_0c06cbf8;
case 0x0c06cbfau: goto P_0c06cbfa;
case 0x0c06cbfcu: goto P_0c06cbfc;
case 0x0c06cbfeu: goto P_0c06cbfe;
case 0x0c06cc00u: goto P_0c06cc00;
case 0x0c06cc02u: goto P_0c06cc02;
case 0x0c06cc04u: goto P_0c06cc04;
case 0x0c06cc06u: goto P_0c06cc06;
case 0x0c06cc08u: goto P_0c06cc08;
case 0x0c06cc0au: goto P_0c06cc0a;
case 0x0c06cc0cu: goto P_0c06cc0c;
case 0x0c06cc0eu: goto P_0c06cc0e;
case 0x0c06cc10u: goto P_0c06cc10;
case 0x0c06cc12u: goto P_0c06cc12;
case 0x0c06cc14u: goto P_0c06cc14;
case 0x0c06cc16u: goto P_0c06cc16;
case 0x0c06cc18u: goto P_0c06cc18;
case 0x0c06cc1au: goto P_0c06cc1a;
case 0x0c06cc1cu: goto P_0c06cc1c;
case 0x0c06cdf2u: goto P_0c06cdf2;
case 0x0c06cdf4u: goto P_0c06cdf4;
case 0x0c06cdf6u: goto P_0c06cdf6;
case 0x0c06cdf8u: goto P_0c06cdf8;
case 0x0c06cdfau: goto P_0c06cdfa;
case 0x0c06cdfcu: goto P_0c06cdfc;
case 0x0c06cdfeu: goto P_0c06cdfe;
case 0x0c06ce00u: goto P_0c06ce00;
case 0x0c06ce02u: goto P_0c06ce02;
case 0x0c06ce04u: goto P_0c06ce04;
case 0x0c06ce06u: goto P_0c06ce06;
case 0x0c06ce08u: goto P_0c06ce08;
case 0x0c06ce0au: goto P_0c06ce0a;
case 0x0c06ce0cu: goto P_0c06ce0c;
case 0x0c06ce0eu: goto P_0c06ce0e;
case 0x0c06ce10u: goto P_0c06ce10;
case 0x0c06ce12u: goto P_0c06ce12;
case 0x0c06ce14u: goto P_0c06ce14;
case 0x0c06ce16u: goto P_0c06ce16;
case 0x0c06ce18u: goto P_0c06ce18;
case 0x0c06ce1au: goto P_0c06ce1a;
case 0x0c06ce1cu: goto P_0c06ce1c;
case 0x0c06ce1eu: goto P_0c06ce1e;
case 0x0c06ce20u: goto P_0c06ce20;
case 0x0c06ce22u: goto P_0c06ce22;
case 0x0c06ce24u: goto P_0c06ce24;
case 0x0c06ce26u: goto P_0c06ce26;
case 0x0c06ce28u: goto P_0c06ce28;
case 0x0c06ce2au: goto P_0c06ce2a;
case 0x0c06ce54u: goto P_0c06ce54;
case 0x0c06ce56u: goto P_0c06ce56;
case 0x0c06ce58u: goto P_0c06ce58;
case 0x0c06ce5au: goto P_0c06ce5a;
case 0x0c06ce5cu: goto P_0c06ce5c;
case 0x0c06ce5eu: goto P_0c06ce5e;
case 0x0c06ce60u: goto P_0c06ce60;
case 0x0c06ce62u: goto P_0c06ce62;
case 0x0c06ce64u: goto P_0c06ce64;
case 0x0c06ce66u: goto P_0c06ce66;
case 0x0c06ce68u: goto P_0c06ce68;
case 0x0c06ce6au: goto P_0c06ce6a;
case 0x0c06ce6cu: goto P_0c06ce6c;
case 0x0c06ce6eu: goto P_0c06ce6e;
case 0x0c06ce70u: goto P_0c06ce70;
case 0x0c06ce72u: goto P_0c06ce72;
case 0x0c06ce74u: goto P_0c06ce74;
case 0x0c06ce76u: goto P_0c06ce76;
case 0x0c06ce78u: goto P_0c06ce78;
case 0x0c06ce7au: goto P_0c06ce7a;
case 0x0c06ce7cu: goto P_0c06ce7c;
case 0x0c06ce7eu: goto P_0c06ce7e;
case 0x0c06ce80u: goto P_0c06ce80;
case 0x0c06ce82u: goto P_0c06ce82;
case 0x0c06ce84u: goto P_0c06ce84;
case 0x0c06ce86u: goto P_0c06ce86;
case 0x0c06ce88u: goto P_0c06ce88;
case 0x0c06ce8au: goto P_0c06ce8a;
case 0x0c06ce8cu: goto P_0c06ce8c;
case 0x0c06ce8eu: goto P_0c06ce8e;
case 0x0c06ce90u: goto P_0c06ce90;
case 0x0c06ce92u: goto P_0c06ce92;
case 0x0c06ce94u: goto P_0c06ce94;
case 0x0c06ce96u: goto P_0c06ce96;
case 0x0c06ce98u: goto P_0c06ce98;
case 0x0c06ce9au: goto P_0c06ce9a;
case 0x0c06ce9cu: goto P_0c06ce9c;
case 0x0c06ce9eu: goto P_0c06ce9e;
case 0x0c06cea0u: goto P_0c06cea0;
case 0x0c06cea2u: goto P_0c06cea2;
case 0x0c06cea4u: goto P_0c06cea4;
case 0x0c06cea6u: goto P_0c06cea6;
case 0x0c06cea8u: goto P_0c06cea8;
case 0x0c06ceaau: goto P_0c06ceaa;
case 0x0c06ceacu: goto P_0c06ceac;
case 0x0c06ceaeu: goto P_0c06ceae;
case 0x0c06ceb0u: goto P_0c06ceb0;
case 0x0c06ceb2u: goto P_0c06ceb2;
case 0x0c06ceb4u: goto P_0c06ceb4;
case 0x0c06ceb6u: goto P_0c06ceb6;
case 0x0c06ceb8u: goto P_0c06ceb8;
case 0x0c06cebau: goto P_0c06ceba;
case 0x0c06cebcu: goto P_0c06cebc;
case 0x0c06cebeu: goto P_0c06cebe;
case 0x0c06cec0u: goto P_0c06cec0;
case 0x0c06cec2u: goto P_0c06cec2;
case 0x0c06cec4u: goto P_0c06cec4;
case 0x0c06cec6u: goto P_0c06cec6;
case 0x0c06cec8u: goto P_0c06cec8;
case 0x0c06cecau: goto P_0c06ceca;
case 0x0c06ceccu: goto P_0c06cecc;
case 0x0c06ceceu: goto P_0c06cece;
case 0x0c06ced0u: goto P_0c06ced0;
case 0x0c06ced2u: goto P_0c06ced2;
case 0x0c06ced4u: goto P_0c06ced4;
case 0x0c06ced6u: goto P_0c06ced6;
case 0x0c06ced8u: goto P_0c06ced8;
case 0x0c06cedau: goto P_0c06ceda;
case 0x0c06cedcu: goto P_0c06cedc;
case 0x0c06cedeu: goto P_0c06cede;
case 0x0c06cee0u: goto P_0c06cee0;
case 0x0c06cee2u: goto P_0c06cee2;
case 0x0c06cee4u: goto P_0c06cee4;
case 0x0c06cee6u: goto P_0c06cee6;
case 0x0c06cee8u: goto P_0c06cee8;
case 0x0c06ceeau: goto P_0c06ceea;
case 0x0c06ceecu: goto P_0c06ceec;
case 0x0c06ceeeu: goto P_0c06ceee;
case 0x0c06cef0u: goto P_0c06cef0;
case 0x0c06cef2u: goto P_0c06cef2;
case 0x0c06cef4u: goto P_0c06cef4;
case 0x0c06cef6u: goto P_0c06cef6;
case 0x0c06cef8u: goto P_0c06cef8;
case 0x0c06cefau: goto P_0c06cefa;
case 0x0c06cefcu: goto P_0c06cefc;
case 0x0c06cefeu: goto P_0c06cefe;
case 0x0c06cf00u: goto P_0c06cf00;
case 0x0c06cf02u: goto P_0c06cf02;
case 0x0c06cf04u: goto P_0c06cf04;
case 0x0c06cf06u: goto P_0c06cf06;
case 0x0c06cf08u: goto P_0c06cf08;
case 0x0c06cf0au: goto P_0c06cf0a;
case 0x0c06cf0cu: goto P_0c06cf0c;
case 0x0c06cf0eu: goto P_0c06cf0e;
case 0x0c06cf10u: goto P_0c06cf10;
case 0x0c06cfb8u: goto P_0c06cfb8;
case 0x0c06cfbau: goto P_0c06cfba;
case 0x0c06cfbcu: goto P_0c06cfbc;
case 0x0c06cfbeu: goto P_0c06cfbe;
case 0x0c06cfc0u: goto P_0c06cfc0;
case 0x0c06cfc2u: goto P_0c06cfc2;
case 0x0c06cfc4u: goto P_0c06cfc4;
case 0x0c06cfc6u: goto P_0c06cfc6;
case 0x0c06cfc8u: goto P_0c06cfc8;
case 0x0c06cfcau: goto P_0c06cfca;
case 0x0c06cfccu: goto P_0c06cfcc;
case 0x0c06cfceu: goto P_0c06cfce;
case 0x0c06cfd0u: goto P_0c06cfd0;
case 0x0c06cfd2u: goto P_0c06cfd2;
case 0x0c06cfd4u: goto P_0c06cfd4;
case 0x0c06cfd6u: goto P_0c06cfd6;
case 0x0c06cfd8u: goto P_0c06cfd8;
case 0x0c06cfdau: goto P_0c06cfda;
case 0x0c06cfdcu: goto P_0c06cfdc;
case 0x0c06cfdeu: goto P_0c06cfde;
case 0x0c06cfe0u: goto P_0c06cfe0;
case 0x0c06cfe2u: goto P_0c06cfe2;
case 0x0c06cfe4u: goto P_0c06cfe4;
case 0x0c06cfe6u: goto P_0c06cfe6;
case 0x0c06cfe8u: goto P_0c06cfe8;
case 0x0c06cfeau: goto P_0c06cfea;
case 0x0c06cfecu: goto P_0c06cfec;
case 0x0c06cfeeu: goto P_0c06cfee;
case 0x0c06cff0u: goto P_0c06cff0;
case 0x0c06cff2u: goto P_0c06cff2;
case 0x0c06cff4u: goto P_0c06cff4;
case 0x0c06cff6u: goto P_0c06cff6;
case 0x0c06cff8u: goto P_0c06cff8;
case 0x0c06cffau: goto P_0c06cffa;
case 0x0c06cffcu: goto P_0c06cffc;
case 0x0c06cffeu: goto P_0c06cffe;
case 0x0c06d000u: goto P_0c06d000;
case 0x0c06d002u: goto P_0c06d002;
case 0x0c06d004u: goto P_0c06d004;
case 0x0c06d006u: goto P_0c06d006;
case 0x0c06d008u: goto P_0c06d008;
case 0x0c06d00au: goto P_0c06d00a;
case 0x0c06d00cu: goto P_0c06d00c;
case 0x0c06d00eu: goto P_0c06d00e;
case 0x0c06d010u: goto P_0c06d010;
case 0x0c06d012u: goto P_0c06d012;
case 0x0c06d014u: goto P_0c06d014;
case 0x0c06d016u: goto P_0c06d016;
case 0x0c06d018u: goto P_0c06d018;
case 0x0c06d01au: goto P_0c06d01a;
case 0x0c06d01cu: goto P_0c06d01c;
case 0x0c06d01eu: goto P_0c06d01e;
case 0x0c06d020u: goto P_0c06d020;
case 0x0c06d022u: goto P_0c06d022;
case 0x0c06d024u: goto P_0c06d024;
case 0x0c06d026u: goto P_0c06d026;
case 0x0c06d028u: goto P_0c06d028;
case 0x0c06d02au: goto P_0c06d02a;
case 0x0c06d02cu: goto P_0c06d02c;
case 0x0c06d08cu: goto P_0c06d08c;
case 0x0c06d08eu: goto P_0c06d08e;
case 0x0c06d090u: goto P_0c06d090;
case 0x0c06d092u: goto P_0c06d092;
case 0x0c06d094u: goto P_0c06d094;
case 0x0c06d096u: goto P_0c06d096;
case 0x0c06d098u: goto P_0c06d098;
case 0x0c06d09au: goto P_0c06d09a;
case 0x0c06d09cu: goto P_0c06d09c;
case 0x0c06d09eu: goto P_0c06d09e;
case 0x0c06d0a0u: goto P_0c06d0a0;
case 0x0c06d0a2u: goto P_0c06d0a2;
case 0x0c06d0a4u: goto P_0c06d0a4;
case 0x0c06d0a6u: goto P_0c06d0a6;
case 0x0c06d0a8u: goto P_0c06d0a8;
case 0x0c06d0aau: goto P_0c06d0aa;
case 0x0c06d0acu: goto P_0c06d0ac;
case 0x0c06d0aeu: goto P_0c06d0ae;
case 0x0c06d0b0u: goto P_0c06d0b0;
case 0x0c06d0b2u: goto P_0c06d0b2;
case 0x0c06d0b4u: goto P_0c06d0b4;
case 0x0c06d0b6u: goto P_0c06d0b6;
case 0x0c06d0b8u: goto P_0c06d0b8;
case 0x0c06d0dcu: goto P_0c06d0dc;
case 0x0c06d0deu: goto P_0c06d0de;
case 0x0c06d0e0u: goto P_0c06d0e0;
case 0x0c06d0e2u: goto P_0c06d0e2;
case 0x0c06d0e4u: goto P_0c06d0e4;
case 0x0c06d0e6u: goto P_0c06d0e6;
case 0x0c06d0e8u: goto P_0c06d0e8;
case 0x0c06d0eau: goto P_0c06d0ea;
case 0x0c06d0ecu: goto P_0c06d0ec;
case 0x0c06d0eeu: goto P_0c06d0ee;
case 0x0c06d0f0u: goto P_0c06d0f0;
case 0x0c06d0f2u: goto P_0c06d0f2;
case 0x0c06d0f4u: goto P_0c06d0f4;
case 0x0c06d0f6u: goto P_0c06d0f6;
case 0x0c06d0f8u: goto P_0c06d0f8;
case 0x0c06d0fau: goto P_0c06d0fa;
case 0x0c06d0fcu: goto P_0c06d0fc;
case 0x0c06d0feu: goto P_0c06d0fe;
case 0x0c06d100u: goto P_0c06d100;
case 0x0c06d102u: goto P_0c06d102;
case 0x0c06d104u: goto P_0c06d104;
case 0x0c06d106u: goto P_0c06d106;
case 0x0c06d108u: goto P_0c06d108;
case 0x0c06d10au: goto P_0c06d10a;
case 0x0c06d10cu: goto P_0c06d10c;
case 0x0c06d10eu: goto P_0c06d10e;
case 0x0c06d110u: goto P_0c06d110;
case 0x0c06d112u: goto P_0c06d112;
case 0x0c06d114u: goto P_0c06d114;
case 0x0c06d116u: goto P_0c06d116;
case 0x0c06d118u: goto P_0c06d118;
case 0x0c06d11au: goto P_0c06d11a;
case 0x0c06d11cu: goto P_0c06d11c;
case 0x0c06d11eu: goto P_0c06d11e;
case 0x0c06d120u: goto P_0c06d120;
case 0x0c06d122u: goto P_0c06d122;
case 0x0c06d124u: goto P_0c06d124;
case 0x0c06d126u: goto P_0c06d126;
case 0x0c06d128u: goto P_0c06d128;
case 0x0c06d12au: goto P_0c06d12a;
case 0x0c06d12cu: goto P_0c06d12c;
case 0x0c06d12eu: goto P_0c06d12e;
case 0x0c06d130u: goto P_0c06d130;
case 0x0c06d132u: goto P_0c06d132;
case 0x0c06d134u: goto P_0c06d134;
case 0x0c06d136u: goto P_0c06d136;
case 0x0c06d138u: goto P_0c06d138;
case 0x0c06d13au: goto P_0c06d13a;
case 0x0c06d13cu: goto P_0c06d13c;
case 0x0c06d13eu: goto P_0c06d13e;
case 0x0c06d140u: goto P_0c06d140;
case 0x0c06d142u: goto P_0c06d142;
case 0x0c06d144u: goto P_0c06d144;
case 0x0c06d146u: goto P_0c06d146;
case 0x0c06d148u: goto P_0c06d148;
case 0x0c06d14au: goto P_0c06d14a;
case 0x0c06d14cu: goto P_0c06d14c;
case 0x0c06d14eu: goto P_0c06d14e;
case 0x0c06d150u: goto P_0c06d150;
case 0x0c06d152u: goto P_0c06d152;
case 0x0c06d154u: goto P_0c06d154;
case 0x0c06d156u: goto P_0c06d156;
case 0x0c06d158u: goto P_0c06d158;
case 0x0c06d15au: goto P_0c06d15a;
case 0x0c06d15cu: goto P_0c06d15c;
case 0x0c06d15eu: goto P_0c06d15e;
case 0x0c06d160u: goto P_0c06d160;
case 0x0c06d162u: goto P_0c06d162;
case 0x0c06d164u: goto P_0c06d164;
case 0x0c06d166u: goto P_0c06d166;
case 0x0c06d168u: goto P_0c06d168;
case 0x0c06d16au: goto P_0c06d16a;
case 0x0c06d16cu: goto P_0c06d16c;
case 0x0c06d16eu: goto P_0c06d16e;
case 0x0c06d170u: goto P_0c06d170;
case 0x0c06d172u: goto P_0c06d172;
case 0x0c06d174u: goto P_0c06d174;
case 0x0c06d176u: goto P_0c06d176;
case 0x0c06d178u: goto P_0c06d178;
case 0x0c06d17au: goto P_0c06d17a;
case 0x0c06d17cu: goto P_0c06d17c;
case 0x0c06d17eu: goto P_0c06d17e;
case 0x0c06d180u: goto P_0c06d180;
case 0x0c06d182u: goto P_0c06d182;
case 0x0c06d184u: goto P_0c06d184;
case 0x0c06d186u: goto P_0c06d186;
case 0x0c06d188u: goto P_0c06d188;
case 0x0c06d18au: goto P_0c06d18a;
case 0x0c06d18cu: goto P_0c06d18c;
case 0x0c06d18eu: goto P_0c06d18e;
case 0x0c06d190u: goto P_0c06d190;
case 0x0c06d192u: goto P_0c06d192;
case 0x0c06d194u: goto P_0c06d194;
case 0x0c06d196u: goto P_0c06d196;
case 0x0c06d198u: goto P_0c06d198;
case 0x0c06d19au: goto P_0c06d19a;
case 0x0c06d19cu: goto P_0c06d19c;
case 0x0c06d19eu: goto P_0c06d19e;
case 0x0c06d1a0u: goto P_0c06d1a0;
case 0x0c06d1a2u: goto P_0c06d1a2;
case 0x0c06d1a4u: goto P_0c06d1a4;
case 0x0c06d1a6u: goto P_0c06d1a6;
case 0x0c06d1a8u: goto P_0c06d1a8;
case 0x0c06d1aau: goto P_0c06d1aa;
case 0x0c06d1acu: goto P_0c06d1ac;
case 0x0c06d1aeu: goto P_0c06d1ae;
case 0x0c06d1b0u: goto P_0c06d1b0;
case 0x0c06d1b2u: goto P_0c06d1b2;
case 0x0c06d1b4u: goto P_0c06d1b4;
case 0x0c06d1b6u: goto P_0c06d1b6;
case 0x0c06d1b8u: goto P_0c06d1b8;
case 0x0c06d1bau: goto P_0c06d1ba;
case 0x0c06d1bcu: goto P_0c06d1bc;
case 0x0c06d1beu: goto P_0c06d1be;
case 0x0c06d1c0u: goto P_0c06d1c0;
case 0x0c06d1c2u: goto P_0c06d1c2;
case 0x0c06d1c4u: goto P_0c06d1c4;
case 0x0c06d1c6u: goto P_0c06d1c6;
case 0x0c06d1c8u: goto P_0c06d1c8;
case 0x0c06d1cau: goto P_0c06d1ca;
case 0x0c06d1ccu: goto P_0c06d1cc;
case 0x0c06d1ceu: goto P_0c06d1ce;
case 0x0c06d1d0u: goto P_0c06d1d0;
case 0x0c06d1d2u: goto P_0c06d1d2;
case 0x0c06d1d4u: goto P_0c06d1d4;
case 0x0c06d1d6u: goto P_0c06d1d6;
case 0x0c06d1d8u: goto P_0c06d1d8;
case 0x0c06d1dau: goto P_0c06d1da;
case 0x0c06d1dcu: goto P_0c06d1dc;
case 0x0c06d1deu: goto P_0c06d1de;
case 0x0c06d1e0u: goto P_0c06d1e0;
case 0x0c06d1e2u: goto P_0c06d1e2;
case 0x0c06d1e4u: goto P_0c06d1e4;
case 0x0c06d1e6u: goto P_0c06d1e6;
case 0x0c06d1e8u: goto P_0c06d1e8;
case 0x0c06d1eau: goto P_0c06d1ea;
case 0x0c06d1ecu: goto P_0c06d1ec;
case 0x0c06d1eeu: goto P_0c06d1ee;
case 0x0c06d1f0u: goto P_0c06d1f0;
case 0x0c06d1f2u: goto P_0c06d1f2;
case 0x0c06d1f4u: goto P_0c06d1f4;
case 0x0c06d1f6u: goto P_0c06d1f6;
case 0x0c06d1f8u: goto P_0c06d1f8;
case 0x0c06d1fau: goto P_0c06d1fa;
case 0x0c06d1fcu: goto P_0c06d1fc;
case 0x0c06d1feu: goto P_0c06d1fe;
case 0x0c06d200u: goto P_0c06d200;
case 0x0c06d250u: goto P_0c06d250;
case 0x0c06d252u: goto P_0c06d252;
case 0x0c06d254u: goto P_0c06d254;
case 0x0c06d256u: goto P_0c06d256;
case 0x0c06d258u: goto P_0c06d258;
case 0x0c06d25au: goto P_0c06d25a;
case 0x0c06d25cu: goto P_0c06d25c;
case 0x0c06d25eu: goto P_0c06d25e;
case 0x0c06d260u: goto P_0c06d260;
case 0x0c06d262u: goto P_0c06d262;
case 0x0c06d264u: goto P_0c06d264;
case 0x0c06d266u: goto P_0c06d266;
case 0x0c06d268u: goto P_0c06d268;
case 0x0c06d26au: goto P_0c06d26a;
case 0x0c06d26cu: goto P_0c06d26c;
case 0x0c06d26eu: goto P_0c06d26e;
case 0x0c06d270u: goto P_0c06d270;
case 0x0c06d272u: goto P_0c06d272;
case 0x0c06d274u: goto P_0c06d274;
case 0x0c06d276u: goto P_0c06d276;
case 0x0c06d278u: goto P_0c06d278;
case 0x0c06d27au: goto P_0c06d27a;
case 0x0c06d27cu: goto P_0c06d27c;
case 0x0c06d27eu: goto P_0c06d27e;
case 0x0c06d280u: goto P_0c06d280;
case 0x0c06d282u: goto P_0c06d282;
case 0x0c06d284u: goto P_0c06d284;
case 0x0c06d286u: goto P_0c06d286;
case 0x0c06d288u: goto P_0c06d288;
case 0x0c06d28au: goto P_0c06d28a;
case 0x0c06d28cu: goto P_0c06d28c;
case 0x0c06d28eu: goto P_0c06d28e;
case 0x0c06d290u: goto P_0c06d290;
case 0x0c06d292u: goto P_0c06d292;
case 0x0c06d294u: goto P_0c06d294;
case 0x0c06d296u: goto P_0c06d296;
case 0x0c06d298u: goto P_0c06d298;
case 0x0c06d29au: goto P_0c06d29a;
case 0x0c06d2acu: goto P_0c06d2ac;
case 0x0c06d2aeu: goto P_0c06d2ae;
case 0x0c06d2b0u: goto P_0c06d2b0;
case 0x0c06d2b2u: goto P_0c06d2b2;
case 0x0c06d2b4u: goto P_0c06d2b4;
case 0x0c06d2b6u: goto P_0c06d2b6;
case 0x0c06d2b8u: goto P_0c06d2b8;
case 0x0c06d2bau: goto P_0c06d2ba;
case 0x0c06d2bcu: goto P_0c06d2bc;
case 0x0c06d2beu: goto P_0c06d2be;
case 0x0c06d2c0u: goto P_0c06d2c0;
case 0x0c06d2c2u: goto P_0c06d2c2;
case 0x0c06d2c4u: goto P_0c06d2c4;
case 0x0c06d2c6u: goto P_0c06d2c6;
case 0x0c06d2c8u: goto P_0c06d2c8;
case 0x0c06d2cau: goto P_0c06d2ca;
case 0x0c06d2ccu: goto P_0c06d2cc;
case 0x0c06d2ceu: goto P_0c06d2ce;
case 0x0c06d2d0u: goto P_0c06d2d0;
case 0x0c06d2d2u: goto P_0c06d2d2;
case 0x0c06d2d4u: goto P_0c06d2d4;
case 0x0c06d2d6u: goto P_0c06d2d6;
case 0x0c06d2d8u: goto P_0c06d2d8;
case 0x0c06d2dau: goto P_0c06d2da;
case 0x0c06d2dcu: goto P_0c06d2dc;
case 0x0c06d2deu: goto P_0c06d2de;
case 0x0c06d2e0u: goto P_0c06d2e0;
case 0x0c06d2e2u: goto P_0c06d2e2;
case 0x0c06d2e4u: goto P_0c06d2e4;
case 0x0c06d2e6u: goto P_0c06d2e6;
case 0x0c06d2e8u: goto P_0c06d2e8;
case 0x0c06d2eau: goto P_0c06d2ea;
case 0x0c06d2ecu: goto P_0c06d2ec;
case 0x0c06d2eeu: goto P_0c06d2ee;
case 0x0c06d2f0u: goto P_0c06d2f0;
case 0x0c06d2f2u: goto P_0c06d2f2;
case 0x0c06d2f4u: goto P_0c06d2f4;
case 0x0c06d2f6u: goto P_0c06d2f6;
case 0x0c06d2f8u: goto P_0c06d2f8;
case 0x0c06d2fau: goto P_0c06d2fa;
case 0x0c06d2fcu: goto P_0c06d2fc;
case 0x0c06d2feu: goto P_0c06d2fe;
case 0x0c06d300u: goto P_0c06d300;
case 0x0c06d302u: goto P_0c06d302;
case 0x0c06d304u: goto P_0c06d304;
case 0x0c06d306u: goto P_0c06d306;
case 0x0c06d308u: goto P_0c06d308;
case 0x0c06d30au: goto P_0c06d30a;
case 0x0c06d30cu: goto P_0c06d30c;
case 0x0c06d30eu: goto P_0c06d30e;
case 0x0c06d310u: goto P_0c06d310;
case 0x0c06d312u: goto P_0c06d312;
case 0x0c06d314u: goto P_0c06d314;
case 0x0c06d316u: goto P_0c06d316;
case 0x0c06d318u: goto P_0c06d318;
case 0x0c06d31au: goto P_0c06d31a;
case 0x0c06d31cu: goto P_0c06d31c;
case 0x0c06d31eu: goto P_0c06d31e;
case 0x0c06d320u: goto P_0c06d320;
case 0x0c06d322u: goto P_0c06d322;
case 0x0c06d324u: goto P_0c06d324;
case 0x0c06d326u: goto P_0c06d326;
case 0x0c06d328u: goto P_0c06d328;
case 0x0c06d32au: goto P_0c06d32a;
case 0x0c06d32cu: goto P_0c06d32c;
case 0x0c06d32eu: goto P_0c06d32e;
case 0x0c06d330u: goto P_0c06d330;
case 0x0c06d332u: goto P_0c06d332;
case 0x0c06d334u: goto P_0c06d334;
case 0x0c06d336u: goto P_0c06d336;
case 0x0c06d338u: goto P_0c06d338;
case 0x0c06d33au: goto P_0c06d33a;
case 0x0c06d33cu: goto P_0c06d33c;
case 0x0c06d33eu: goto P_0c06d33e;
case 0x0c06d340u: goto P_0c06d340;
case 0x0c06d342u: goto P_0c06d342;
case 0x0c06d344u: goto P_0c06d344;
case 0x0c06d346u: goto P_0c06d346;
case 0x0c06d348u: goto P_0c06d348;
case 0x0c06d34au: goto P_0c06d34a;
case 0x0c06d34cu: goto P_0c06d34c;
case 0x0c06d34eu: goto P_0c06d34e;
case 0x0c06d350u: goto P_0c06d350;
case 0x0c06d352u: goto P_0c06d352;
case 0x0c06d354u: goto P_0c06d354;
case 0x0c06d356u: goto P_0c06d356;
case 0x0c06d358u: goto P_0c06d358;
case 0x0c06d35au: goto P_0c06d35a;
case 0x0c06d35cu: goto P_0c06d35c;
case 0x0c06d35eu: goto P_0c06d35e;
case 0x0c06d360u: goto P_0c06d360;
case 0x0c06d362u: goto P_0c06d362;
case 0x0c06d364u: goto P_0c06d364;
case 0x0c06d366u: goto P_0c06d366;
case 0x0c06d368u: goto P_0c06d368;
case 0x0c06d36au: goto P_0c06d36a;
case 0x0c06d36cu: goto P_0c06d36c;
case 0x0c06d36eu: goto P_0c06d36e;
case 0x0c06d370u: goto P_0c06d370;
case 0x0c06d372u: goto P_0c06d372;
case 0x0c06d374u: goto P_0c06d374;
case 0x0c06d376u: goto P_0c06d376;
case 0x0c06d378u: goto P_0c06d378;
case 0x0c06d37au: goto P_0c06d37a;
case 0x0c06d37cu: goto P_0c06d37c;
case 0x0c06d37eu: goto P_0c06d37e;
case 0x0c06d380u: goto P_0c06d380;
case 0x0c06d382u: goto P_0c06d382;
case 0x0c06d384u: goto P_0c06d384;
case 0x0c06d386u: goto P_0c06d386;
case 0x0c06d388u: goto P_0c06d388;
case 0x0c06d38au: goto P_0c06d38a;
case 0x0c06d38cu: goto P_0c06d38c;
case 0x0c06d38eu: goto P_0c06d38e;
case 0x0c06d390u: goto P_0c06d390;
case 0x0c06d392u: goto P_0c06d392;
case 0x0c06d394u: goto P_0c06d394;
case 0x0c06d396u: goto P_0c06d396;
case 0x0c06d3e0u: goto P_0c06d3e0;
case 0x0c06d3e2u: goto P_0c06d3e2;
case 0x0c06d3e4u: goto P_0c06d3e4;
case 0x0c06d3e6u: goto P_0c06d3e6;
case 0x0c06d3e8u: goto P_0c06d3e8;
case 0x0c06d3eau: goto P_0c06d3ea;
case 0x0c06d3ecu: goto P_0c06d3ec;
case 0x0c06d3eeu: goto P_0c06d3ee;
case 0x0c06d3f0u: goto P_0c06d3f0;
case 0x0c06d3f2u: goto P_0c06d3f2;
case 0x0c06d3f4u: goto P_0c06d3f4;
case 0x0c06d3f6u: goto P_0c06d3f6;
case 0x0c06d3f8u: goto P_0c06d3f8;
case 0x0c06d3fau: goto P_0c06d3fa;
case 0x0c06d3fcu: goto P_0c06d3fc;
case 0x0c06d3feu: goto P_0c06d3fe;
case 0x0c06d400u: goto P_0c06d400;
case 0x0c06d402u: goto P_0c06d402;
case 0x0c06d404u: goto P_0c06d404;
case 0x0c06d406u: goto P_0c06d406;
case 0x0c06d408u: goto P_0c06d408;
case 0x0c06d40au: goto P_0c06d40a;
case 0x0c06d40cu: goto P_0c06d40c;
case 0x0c06d40eu: goto P_0c06d40e;
case 0x0c06d410u: goto P_0c06d410;
case 0x0c06d412u: goto P_0c06d412;
case 0x0c06d414u: goto P_0c06d414;
case 0x0c06d416u: goto P_0c06d416;
case 0x0c06d418u: goto P_0c06d418;
case 0x0c06d41au: goto P_0c06d41a;
case 0x0c06d41cu: goto P_0c06d41c;
case 0x0c06d41eu: goto P_0c06d41e;
case 0x0c06d420u: goto P_0c06d420;
case 0x0c06d422u: goto P_0c06d422;
case 0x0c06d424u: goto P_0c06d424;
case 0x0c06d426u: goto P_0c06d426;
case 0x0c06d428u: goto P_0c06d428;
case 0x0c06d42au: goto P_0c06d42a;
case 0x0c06d42cu: goto P_0c06d42c;
case 0x0c06d42eu: goto P_0c06d42e;
case 0x0c06d430u: goto P_0c06d430;
case 0x0c06d432u: goto P_0c06d432;
case 0x0c06d434u: goto P_0c06d434;
case 0x0c06d436u: goto P_0c06d436;
case 0x0c06d438u: goto P_0c06d438;
case 0x0c06d43au: goto P_0c06d43a;
case 0x0c06d43cu: goto P_0c06d43c;
case 0x0c06d43eu: goto P_0c06d43e;
case 0x0c06d440u: goto P_0c06d440;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06cbe4: /* original 4f22, guest PC 0x0c06cbe4 */
if(!s->budget--) { s->failed_pc=0x0c06cbe4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06cbe6;
P_0c06cbe6: /* original e018, guest PC 0x0c06cbe6 */
if(!s->budget--) { s->failed_pc=0x0c06cbe6u; return 0; }
r[0]=0x00000018u;
goto P_0c06cbe8;
P_0c06cbe8: /* original 7ff8, guest PC 0x0c06cbe8 */
if(!s->budget--) { s->failed_pc=0x0c06cbe8u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c06cbea;
P_0c06cbea: /* original 2f42, guest PC 0x0c06cbea */
if(!s->budget--) { s->failed_pc=0x0c06cbeau; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06cbec;
P_0c06cbec: /* original 1f71, guest PC 0x0c06cbec */
if(!s->budget--) { s->failed_pc=0x0c06cbecu; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c06cbee;
P_0c06cbee: /* original 03fc, guest PC 0x0c06cbee */
if(!s->budget--) { s->failed_pc=0x0c06cbeeu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c06cbf0;
P_0c06cbf0: /* original e018, guest PC 0x0c06cbf0 */
if(!s->budget--) { s->failed_pc=0x0c06cbf0u; return 0; }
r[0]=0x00000018u;
goto P_0c06cbf2;
P_0c06cbf2: /* original 2f36, guest PC 0x0c06cbf2 */
if(!s->budget--) { s->failed_pc=0x0c06cbf2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbf4;
P_0c06cbf4: /* original 02fc, guest PC 0x0c06cbf4 */
if(!s->budget--) { s->failed_pc=0x0c06cbf4u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c06cbf6;
P_0c06cbf6: /* original e01c, guest PC 0x0c06cbf6 */
if(!s->budget--) { s->failed_pc=0x0c06cbf6u; return 0; }
r[0]=0x0000001cu;
goto P_0c06cbf8;
P_0c06cbf8: /* original 2f26, guest PC 0x0c06cbf8 */
if(!s->budget--) { s->failed_pc=0x0c06cbf8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbfa;
P_0c06cbfa: /* original 53f3, guest PC 0x0c06cbfa */
if(!s->budget--) { s->failed_pc=0x0c06cbfau; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c06cbfc;
P_0c06cbfc: /* original 2f36, guest PC 0x0c06cbfc */
if(!s->budget--) { s->failed_pc=0x0c06cbfcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbfe;
P_0c06cbfe: /* original 02fc, guest PC 0x0c06cbfe */
if(!s->budget--) { s->failed_pc=0x0c06cbfeu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c06cc00;
P_0c06cc00: /* original e01c, guest PC 0x0c06cc00 */
if(!s->budget--) { s->failed_pc=0x0c06cc00u; return 0; }
r[0]=0x0000001cu;
goto P_0c06cc02;
P_0c06cc02: /* original 2f26, guest PC 0x0c06cc02 */
if(!s->budget--) { s->failed_pc=0x0c06cc02u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cc04;
P_0c06cc04: /* original 00fc, guest PC 0x0c06cc04 */
if(!s->budget--) { s->failed_pc=0x0c06cc04u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c06cc06;
P_0c06cc06: /* original 2f06, guest PC 0x0c06cc06 */
if(!s->budget--) { s->failed_pc=0x0c06cc06u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cc08;
P_0c06cc08: /* original 2f66, guest PC 0x0c06cc08 */
if(!s->budget--) { s->failed_pc=0x0c06cc08u; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cc0a;
P_0c06cc0a: /* original 2f56, guest PC 0x0c06cc0a */
if(!s->budget--) { s->failed_pc=0x0c06cc0au; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cc0c;
P_0c06cc0c: /* original d319, guest PC 0x0c06cc0c */
if(!s->budget--) { s->failed_pc=0x0c06cc0cu; return 0; }
r[3]=read(ram,0x0c06cc74u,4);
goto P_0c06cc0e;
P_0c06cc0e: /* original 2f36, guest PC 0x0c06cc0e */
if(!s->budget--) { s->failed_pc=0x0c06cc0eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cc10;
P_0c06cc10: /* original d215, guest PC 0x0c06cc10 */
if(!s->budget--) { s->failed_pc=0x0c06cc10u; return 0; }
r[2]=read(ram,0x0c06cc68u,4);
goto P_0c06cc12;
P_0c06cc12: /* original 420b, guest PC 0x0c06cc12 */
if(!s->budget--) { s->failed_pc=0x0c06cc12u; return 0; }
target=r[2];
r[16]=code_base|0x0c06cc16u;
r[4]=read(ram,r[15]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cc16u) { target=s->pc; goto dispatch; }
goto P_0c06cc16;
P_0c06cc14: /* original 54f8, guest PC 0x0c06cc14 */
if(!s->budget--) { s->failed_pc=0x0c06cc14u; return 0; }
r[4]=read(ram,r[15]+32,4);
goto P_0c06cc16;
P_0c06cc16: /* original 7f28, guest PC 0x0c06cc16 */
if(!s->budget--) { s->failed_pc=0x0c06cc16u; return 0; }
r[15]+=0x00000028u;
goto P_0c06cc18;
P_0c06cc18: /* original 4f26, guest PC 0x0c06cc18 */
if(!s->budget--) { s->failed_pc=0x0c06cc18u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06cc1a;
P_0c06cc1a: /* original 000b, guest PC 0x0c06cc1a */
if(!s->budget--) { s->failed_pc=0x0c06cc1au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06cc1c: /* original 0009, guest PC 0x0c06cc1c */
if(!s->budget--) { s->failed_pc=0x0c06cc1cu; return 0; }
if(!vf3_matrix_family(0x0c06cc1eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06cc1eu; return 0; } return 1;
P_0c06cdf2: /* original 2fe6, guest PC 0x0c06cdf2 */
if(!s->budget--) { s->failed_pc=0x0c06cdf2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cdf4;
P_0c06cdf4: /* original 2fd6, guest PC 0x0c06cdf4 */
if(!s->budget--) { s->failed_pc=0x0c06cdf4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cdf6;
P_0c06cdf6: /* original 2fc6, guest PC 0x0c06cdf6 */
if(!s->budget--) { s->failed_pc=0x0c06cdf6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cdf8;
P_0c06cdf8: /* original 2fb6, guest PC 0x0c06cdf8 */
if(!s->budget--) { s->failed_pc=0x0c06cdf8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cdfa;
P_0c06cdfa: /* original 901a, guest PC 0x0c06cdfa */
if(!s->budget--) { s->failed_pc=0x0c06cdfau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ce32u,2);
goto P_0c06cdfc;
P_0c06cdfc: /* original d414, guest PC 0x0c06cdfc */
if(!s->budget--) { s->failed_pc=0x0c06cdfcu; return 0; }
r[4]=read(ram,0x0c06ce50u,4);
goto P_0c06cdfe;
P_0c06cdfe: /* original 4f22, guest PC 0x0c06cdfe */
if(!s->budget--) { s->failed_pc=0x0c06cdfeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06ce00;
P_0c06ce00: /* original 034c, guest PC 0x0c06ce00 */
if(!s->budget--) { s->failed_pc=0x0c06ce00u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06ce02;
P_0c06ce02: /* original 7ffc, guest PC 0x0c06ce02 */
if(!s->budget--) { s->failed_pc=0x0c06ce02u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06ce04;
P_0c06ce04: /* original 2f32, guest PC 0x0c06ce04 */
if(!s->budget--) { s->failed_pc=0x0c06ce04u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06ce06;
P_0c06ce06: /* original 9012, guest PC 0x0c06ce06 */
if(!s->budget--) { s->failed_pc=0x0c06ce06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ce2eu,2);
goto P_0c06ce08;
P_0c06ce08: /* original 0b4c, guest PC 0x0c06ce08 */
if(!s->budget--) { s->failed_pc=0x0c06ce08u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06ce0a;
P_0c06ce0a: /* original 9013, guest PC 0x0c06ce0a */
if(!s->budget--) { s->failed_pc=0x0c06ce0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ce34u,2);
goto P_0c06ce0c;
P_0c06ce0c: /* original 064c, guest PC 0x0c06ce0c */
if(!s->budget--) { s->failed_pc=0x0c06ce0cu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06ce0e;
P_0c06ce0e: /* original 7001, guest PC 0x0c06ce0e */
if(!s->budget--) { s->failed_pc=0x0c06ce0eu; return 0; }
r[0]+=0x00000001u;
goto P_0c06ce10;
P_0c06ce10: /* original 074c, guest PC 0x0c06ce10 */
if(!s->budget--) { s->failed_pc=0x0c06ce10u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06ce12;
P_0c06ce12: /* original 700e, guest PC 0x0c06ce12 */
if(!s->budget--) { s->failed_pc=0x0c06ce12u; return 0; }
r[0]+=0x0000000eu;
goto P_0c06ce14;
P_0c06ce14: /* original 054c, guest PC 0x0c06ce14 */
if(!s->budget--) { s->failed_pc=0x0c06ce14u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06ce16;
P_0c06ce16: /* original 6033, guest PC 0x0c06ce16 */
if(!s->budget--) { s->failed_pc=0x0c06ce16u; return 0; }
r[0]=r[3];
goto P_0c06ce18;
P_0c06ce18: /* original 8801, guest PC 0x0c06ce18 */
if(!s->budget--) { s->failed_pc=0x0c06ce18u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06ce1a;
P_0c06ce1a: /* original 891b, guest PC 0x0c06ce1a */
if(!s->budget--) { s->failed_pc=0x0c06ce1au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06ce54; }
goto P_0c06ce1c;
P_0c06ce1c: /* original 60b3, guest PC 0x0c06ce1c */
if(!s->budget--) { s->failed_pc=0x0c06ce1cu; return 0; }
r[0]=r[11];
goto P_0c06ce1e;
P_0c06ce1e: /* original 8801, guest PC 0x0c06ce1e */
if(!s->budget--) { s->failed_pc=0x0c06ce1eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06ce20;
P_0c06ce20: /* original 8f01, guest PC 0x0c06ce20 */
if(!s->budget--) { s->failed_pc=0x0c06ce20u; return 0; }
cond=r[17]&1u;
r[14]=0x00000027u;
if(!cond) { goto P_0c06ce26; }
goto P_0c06ce24;
P_0c06ce22: /* original ee27, guest PC 0x0c06ce22 */
if(!s->budget--) { s->failed_pc=0x0c06ce22u; return 0; }
r[14]=0x00000027u;
goto P_0c06ce24;
P_0c06ce24: /* original ee05, guest PC 0x0c06ce24 */
if(!s->budget--) { s->failed_pc=0x0c06ce24u; return 0; }
r[14]=0x00000005u;
goto P_0c06ce26;
P_0c06ce26: /* original 6d63, guest PC 0x0c06ce26 */
if(!s->budget--) { s->failed_pc=0x0c06ce26u; return 0; }
r[13]=r[6];
goto P_0c06ce28;
P_0c06ce28: /* original a01f, guest PC 0x0c06ce28 */
if(!s->budget--) { s->failed_pc=0x0c06ce28u; return 0; }
r[12]=r[7];
goto P_0c06ce6a;
P_0c06ce2a: /* original 6c73, guest PC 0x0c06ce2a */
if(!s->budget--) { s->failed_pc=0x0c06ce2au; return 0; }
r[12]=r[7];
if(!vf3_matrix_family(0x0c06ce2cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06ce2cu; return 0; } return 1;
P_0c06ce54: /* original 905d, guest PC 0x0c06ce54 */
if(!s->budget--) { s->failed_pc=0x0c06ce54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cf12u,2);
goto P_0c06ce56;
P_0c06ce56: /* original 0d4c, guest PC 0x0c06ce56 */
if(!s->budget--) { s->failed_pc=0x0c06ce56u; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06ce58;
P_0c06ce58: /* original 7001, guest PC 0x0c06ce58 */
if(!s->budget--) { s->failed_pc=0x0c06ce58u; return 0; }
r[0]+=0x00000001u;
goto P_0c06ce5a;
P_0c06ce5a: /* original 0c4c, guest PC 0x0c06ce5a */
if(!s->budget--) { s->failed_pc=0x0c06ce5au; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06ce5c;
P_0c06ce5c: /* original 60b3, guest PC 0x0c06ce5c */
if(!s->budget--) { s->failed_pc=0x0c06ce5cu; return 0; }
r[0]=r[11];
goto P_0c06ce5e;
P_0c06ce5e: /* original 8801, guest PC 0x0c06ce5e */
if(!s->budget--) { s->failed_pc=0x0c06ce5eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06ce60;
P_0c06ce60: /* original 8f03, guest PC 0x0c06ce60 */
if(!s->budget--) { s->failed_pc=0x0c06ce60u; return 0; }
cond=r[17]&1u;
r[14]=0x00000027u;
if(!cond) { goto P_0c06ce6a; }
goto P_0c06ce64;
P_0c06ce62: /* original ee27, guest PC 0x0c06ce62 */
if(!s->budget--) { s->failed_pc=0x0c06ce62u; return 0; }
r[14]=0x00000027u;
goto P_0c06ce64;
P_0c06ce64: /* original 6c73, guest PC 0x0c06ce64 */
if(!s->budget--) { s->failed_pc=0x0c06ce64u; return 0; }
r[12]=r[7];
goto P_0c06ce66;
P_0c06ce66: /* original 6d63, guest PC 0x0c06ce66 */
if(!s->budget--) { s->failed_pc=0x0c06ce66u; return 0; }
r[13]=r[6];
goto P_0c06ce68;
P_0c06ce68: /* original ee05, guest PC 0x0c06ce68 */
if(!s->budget--) { s->failed_pc=0x0c06ce68u; return 0; }
r[14]=0x00000005u;
goto P_0c06ce6a;
P_0c06ce6a: /* original 9353, guest PC 0x0c06ce6a */
if(!s->budget--) { s->failed_pc=0x0c06ce6au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cf14u,2);
goto P_0c06ce6c;
P_0c06ce6c: /* original 64e3, guest PC 0x0c06ce6c */
if(!s->budget--) { s->failed_pc=0x0c06ce6cu; return 0; }
r[4]=r[14];
goto P_0c06ce6e;
P_0c06ce6e: /* original 6b53, guest PC 0x0c06ce6e */
if(!s->budget--) { s->failed_pc=0x0c06ce6eu; return 0; }
r[11]=r[5];
goto P_0c06ce70;
P_0c06ce70: /* original 4400, guest PC 0x0c06ce70 */
if(!s->budget--) { s->failed_pc=0x0c06ce70u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06ce72;
P_0c06ce72: /* original ba75, guest PC 0x0c06ce72 */
if(!s->budget--) { s->failed_pc=0x0c06ce72u; return 0; }
target=code_base|0x0c06c360u; r[16]=code_base|0x0c06ce76u;
r[4]|=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ce76u) { target=s->pc; goto dispatch; }
goto P_0c06ce76;
P_0c06ce74: /* original 243b, guest PC 0x0c06ce74 */
if(!s->budget--) { s->failed_pc=0x0c06ce74u; return 0; }
r[4]|=r[3];
goto P_0c06ce76;
P_0c06ce76: /* original 2008, guest PC 0x0c06ce76 */
if(!s->budget--) { s->failed_pc=0x0c06ce76u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06ce78;
P_0c06ce78: /* original 8906, guest PC 0x0c06ce78 */
if(!s->budget--) { s->failed_pc=0x0c06ce78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06ce88; }
goto P_0c06ce7a;
P_0c06ce7a: /* original 66d3, guest PC 0x0c06ce7a */
if(!s->budget--) { s->failed_pc=0x0c06ce7au; return 0; }
r[6]=r[13];
goto P_0c06ce7c;
P_0c06ce7c: /* original e52e, guest PC 0x0c06ce7c */
if(!s->budget--) { s->failed_pc=0x0c06ce7cu; return 0; }
r[5]=0x0000002eu;
goto P_0c06ce7e;
P_0c06ce7e: /* original 2fb6, guest PC 0x0c06ce7e */
if(!s->budget--) { s->failed_pc=0x0c06ce7eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ce80;
P_0c06ce80: /* original 67c3, guest PC 0x0c06ce80 */
if(!s->budget--) { s->failed_pc=0x0c06ce80u; return 0; }
r[7]=r[12];
goto P_0c06ce82;
P_0c06ce82: /* original be30, guest PC 0x0c06ce82 */
if(!s->budget--) { s->failed_pc=0x0c06ce82u; return 0; }
target=code_base|0x0c06cae6u; r[16]=code_base|0x0c06ce86u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ce86u) { target=s->pc; goto dispatch; }
goto P_0c06ce86;
P_0c06ce84: /* original 64e3, guest PC 0x0c06ce84 */
if(!s->budget--) { s->failed_pc=0x0c06ce84u; return 0; }
r[4]=r[14];
goto P_0c06ce86;
P_0c06ce86: /* original 7f04, guest PC 0x0c06ce86 */
if(!s->budget--) { s->failed_pc=0x0c06ce86u; return 0; }
r[15]+=0x00000004u;
goto P_0c06ce88;
P_0c06ce88: /* original 7f04, guest PC 0x0c06ce88 */
if(!s->budget--) { s->failed_pc=0x0c06ce88u; return 0; }
r[15]+=0x00000004u;
goto P_0c06ce8a;
P_0c06ce8a: /* original 4f26, guest PC 0x0c06ce8a */
if(!s->budget--) { s->failed_pc=0x0c06ce8au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06ce8c;
P_0c06ce8c: /* original 6bf6, guest PC 0x0c06ce8c */
if(!s->budget--) { s->failed_pc=0x0c06ce8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06ce8e;
P_0c06ce8e: /* original 6cf6, guest PC 0x0c06ce8e */
if(!s->budget--) { s->failed_pc=0x0c06ce8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06ce90;
P_0c06ce90: /* original 6df6, guest PC 0x0c06ce90 */
if(!s->budget--) { s->failed_pc=0x0c06ce90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06ce92;
P_0c06ce92: /* original 000b, guest PC 0x0c06ce92 */
if(!s->budget--) { s->failed_pc=0x0c06ce92u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06ce94: /* original 6ef6, guest PC 0x0c06ce94 */
if(!s->budget--) { s->failed_pc=0x0c06ce94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06ce96;
P_0c06ce96: /* original 2fe6, guest PC 0x0c06ce96 */
if(!s->budget--) { s->failed_pc=0x0c06ce96u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ce98;
P_0c06ce98: /* original 2fd6, guest PC 0x0c06ce98 */
if(!s->budget--) { s->failed_pc=0x0c06ce98u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ce9a;
P_0c06ce9a: /* original 2fc6, guest PC 0x0c06ce9a */
if(!s->budget--) { s->failed_pc=0x0c06ce9au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ce9c;
P_0c06ce9c: /* original 2fb6, guest PC 0x0c06ce9c */
if(!s->budget--) { s->failed_pc=0x0c06ce9cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ce9e;
P_0c06ce9e: /* original 903a, guest PC 0x0c06ce9e */
if(!s->budget--) { s->failed_pc=0x0c06ce9eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cf16u,2);
goto P_0c06cea0;
P_0c06cea0: /* original d41e, guest PC 0x0c06cea0 */
if(!s->budget--) { s->failed_pc=0x0c06cea0u; return 0; }
r[4]=read(ram,0x0c06cf1cu,4);
goto P_0c06cea2;
P_0c06cea2: /* original 4f22, guest PC 0x0c06cea2 */
if(!s->budget--) { s->failed_pc=0x0c06cea2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06cea4;
P_0c06cea4: /* original 034c, guest PC 0x0c06cea4 */
if(!s->budget--) { s->failed_pc=0x0c06cea4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06cea6;
P_0c06cea6: /* original 7ffc, guest PC 0x0c06cea6 */
if(!s->budget--) { s->failed_pc=0x0c06cea6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06cea8;
P_0c06cea8: /* original 2f32, guest PC 0x0c06cea8 */
if(!s->budget--) { s->failed_pc=0x0c06cea8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06ceaa;
P_0c06ceaa: /* original 9035, guest PC 0x0c06ceaa */
if(!s->budget--) { s->failed_pc=0x0c06ceaau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cf18u,2);
goto P_0c06ceac;
P_0c06ceac: /* original 0b4c, guest PC 0x0c06ceac */
if(!s->budget--) { s->failed_pc=0x0c06ceacu; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06ceae;
P_0c06ceae: /* original 9034, guest PC 0x0c06ceae */
if(!s->budget--) { s->failed_pc=0x0c06ceaeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cf1au,2);
goto P_0c06ceb0;
P_0c06ceb0: /* original 064c, guest PC 0x0c06ceb0 */
if(!s->budget--) { s->failed_pc=0x0c06ceb0u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06ceb2;
P_0c06ceb2: /* original 7001, guest PC 0x0c06ceb2 */
if(!s->budget--) { s->failed_pc=0x0c06ceb2u; return 0; }
r[0]+=0x00000001u;
goto P_0c06ceb4;
P_0c06ceb4: /* original 074c, guest PC 0x0c06ceb4 */
if(!s->budget--) { s->failed_pc=0x0c06ceb4u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06ceb6;
P_0c06ceb6: /* original 700f, guest PC 0x0c06ceb6 */
if(!s->budget--) { s->failed_pc=0x0c06ceb6u; return 0; }
r[0]+=0x0000000fu;
goto P_0c06ceb8;
P_0c06ceb8: /* original 054c, guest PC 0x0c06ceb8 */
if(!s->budget--) { s->failed_pc=0x0c06ceb8u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06ceba;
P_0c06ceba: /* original 6033, guest PC 0x0c06ceba */
if(!s->budget--) { s->failed_pc=0x0c06cebau; return 0; }
r[0]=r[3];
goto P_0c06cebc;
P_0c06cebc: /* original 8801, guest PC 0x0c06cebc */
if(!s->budget--) { s->failed_pc=0x0c06cebcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cebe;
P_0c06cebe: /* original 8907, guest PC 0x0c06cebe */
if(!s->budget--) { s->failed_pc=0x0c06cebeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06ced0; }
goto P_0c06cec0;
P_0c06cec0: /* original 60b3, guest PC 0x0c06cec0 */
if(!s->budget--) { s->failed_pc=0x0c06cec0u; return 0; }
r[0]=r[11];
goto P_0c06cec2;
P_0c06cec2: /* original 8801, guest PC 0x0c06cec2 */
if(!s->budget--) { s->failed_pc=0x0c06cec2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cec4;
P_0c06cec4: /* original 8f01, guest PC 0x0c06cec4 */
if(!s->budget--) { s->failed_pc=0x0c06cec4u; return 0; }
cond=r[17]&1u;
r[14]=0x00000005u;
if(!cond) { goto P_0c06ceca; }
goto P_0c06cec8;
P_0c06cec6: /* original ee05, guest PC 0x0c06cec6 */
if(!s->budget--) { s->failed_pc=0x0c06cec6u; return 0; }
r[14]=0x00000005u;
goto P_0c06cec8;
P_0c06cec8: /* original ee27, guest PC 0x0c06cec8 */
if(!s->budget--) { s->failed_pc=0x0c06cec8u; return 0; }
r[14]=0x00000027u;
goto P_0c06ceca;
P_0c06ceca: /* original 6d63, guest PC 0x0c06ceca */
if(!s->budget--) { s->failed_pc=0x0c06cecau; return 0; }
r[13]=r[6];
goto P_0c06cecc;
P_0c06cecc: /* original a00b, guest PC 0x0c06cecc */
if(!s->budget--) { s->failed_pc=0x0c06ceccu; return 0; }
r[12]=r[7];
goto P_0c06cee6;
P_0c06cece: /* original 6c73, guest PC 0x0c06cece */
if(!s->budget--) { s->failed_pc=0x0c06ceceu; return 0; }
r[12]=r[7];
goto P_0c06ced0;
P_0c06ced0: /* original 60b3, guest PC 0x0c06ced0 */
if(!s->budget--) { s->failed_pc=0x0c06ced0u; return 0; }
r[0]=r[11];
goto P_0c06ced2;
P_0c06ced2: /* original 8801, guest PC 0x0c06ced2 */
if(!s->budget--) { s->failed_pc=0x0c06ced2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06ced4;
P_0c06ced4: /* original ee05, guest PC 0x0c06ced4 */
if(!s->budget--) { s->failed_pc=0x0c06ced4u; return 0; }
r[14]=0x00000005u;
goto P_0c06ced6;
P_0c06ced6: /* original 6d63, guest PC 0x0c06ced6 */
if(!s->budget--) { s->failed_pc=0x0c06ced6u; return 0; }
r[13]=r[6];
goto P_0c06ced8;
P_0c06ced8: /* original 8f05, guest PC 0x0c06ced8 */
if(!s->budget--) { s->failed_pc=0x0c06ced8u; return 0; }
cond=r[17]&1u;
r[12]=r[7];
if(!cond) { goto P_0c06cee6; }
goto P_0c06cedc;
P_0c06ceda: /* original 6c73, guest PC 0x0c06ceda */
if(!s->budget--) { s->failed_pc=0x0c06cedau; return 0; }
r[12]=r[7];
goto P_0c06cedc;
P_0c06cedc: /* original 9019, guest PC 0x0c06cedc */
if(!s->budget--) { s->failed_pc=0x0c06cedcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cf12u,2);
goto P_0c06cede;
P_0c06cede: /* original ee27, guest PC 0x0c06cede */
if(!s->budget--) { s->failed_pc=0x0c06cedeu; return 0; }
r[14]=0x00000027u;
goto P_0c06cee0;
P_0c06cee0: /* original 0d4c, guest PC 0x0c06cee0 */
if(!s->budget--) { s->failed_pc=0x0c06cee0u; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06cee2;
P_0c06cee2: /* original 7001, guest PC 0x0c06cee2 */
if(!s->budget--) { s->failed_pc=0x0c06cee2u; return 0; }
r[0]+=0x00000001u;
goto P_0c06cee4;
P_0c06cee4: /* original 0c4c, guest PC 0x0c06cee4 */
if(!s->budget--) { s->failed_pc=0x0c06cee4u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06cee6;
P_0c06cee6: /* original 9315, guest PC 0x0c06cee6 */
if(!s->budget--) { s->failed_pc=0x0c06cee6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cf14u,2);
goto P_0c06cee8;
P_0c06cee8: /* original 64e3, guest PC 0x0c06cee8 */
if(!s->budget--) { s->failed_pc=0x0c06cee8u; return 0; }
r[4]=r[14];
goto P_0c06ceea;
P_0c06ceea: /* original 6b53, guest PC 0x0c06ceea */
if(!s->budget--) { s->failed_pc=0x0c06ceeau; return 0; }
r[11]=r[5];
goto P_0c06ceec;
P_0c06ceec: /* original 4400, guest PC 0x0c06ceec */
if(!s->budget--) { s->failed_pc=0x0c06ceecu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06ceee;
P_0c06ceee: /* original ba37, guest PC 0x0c06ceee */
if(!s->budget--) { s->failed_pc=0x0c06ceeeu; return 0; }
target=code_base|0x0c06c360u; r[16]=code_base|0x0c06cef2u;
r[4]|=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cef2u) { target=s->pc; goto dispatch; }
goto P_0c06cef2;
P_0c06cef0: /* original 243b, guest PC 0x0c06cef0 */
if(!s->budget--) { s->failed_pc=0x0c06cef0u; return 0; }
r[4]|=r[3];
goto P_0c06cef2;
P_0c06cef2: /* original 2008, guest PC 0x0c06cef2 */
if(!s->budget--) { s->failed_pc=0x0c06cef2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06cef4;
P_0c06cef4: /* original 8906, guest PC 0x0c06cef4 */
if(!s->budget--) { s->failed_pc=0x0c06cef4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cf04; }
goto P_0c06cef6;
P_0c06cef6: /* original 66d3, guest PC 0x0c06cef6 */
if(!s->budget--) { s->failed_pc=0x0c06cef6u; return 0; }
r[6]=r[13];
goto P_0c06cef8;
P_0c06cef8: /* original e52e, guest PC 0x0c06cef8 */
if(!s->budget--) { s->failed_pc=0x0c06cef8u; return 0; }
r[5]=0x0000002eu;
goto P_0c06cefa;
P_0c06cefa: /* original 2fb6, guest PC 0x0c06cefa */
if(!s->budget--) { s->failed_pc=0x0c06cefau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cefc;
P_0c06cefc: /* original 67c3, guest PC 0x0c06cefc */
if(!s->budget--) { s->failed_pc=0x0c06cefcu; return 0; }
r[7]=r[12];
goto P_0c06cefe;
P_0c06cefe: /* original bdf2, guest PC 0x0c06cefe */
if(!s->budget--) { s->failed_pc=0x0c06cefeu; return 0; }
target=code_base|0x0c06cae6u; r[16]=code_base|0x0c06cf02u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cf02u) { target=s->pc; goto dispatch; }
goto P_0c06cf02;
P_0c06cf00: /* original 64e3, guest PC 0x0c06cf00 */
if(!s->budget--) { s->failed_pc=0x0c06cf00u; return 0; }
r[4]=r[14];
goto P_0c06cf02;
P_0c06cf02: /* original 7f04, guest PC 0x0c06cf02 */
if(!s->budget--) { s->failed_pc=0x0c06cf02u; return 0; }
r[15]+=0x00000004u;
goto P_0c06cf04;
P_0c06cf04: /* original 7f04, guest PC 0x0c06cf04 */
if(!s->budget--) { s->failed_pc=0x0c06cf04u; return 0; }
r[15]+=0x00000004u;
goto P_0c06cf06;
P_0c06cf06: /* original 4f26, guest PC 0x0c06cf06 */
if(!s->budget--) { s->failed_pc=0x0c06cf06u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06cf08;
P_0c06cf08: /* original 6bf6, guest PC 0x0c06cf08 */
if(!s->budget--) { s->failed_pc=0x0c06cf08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06cf0a;
P_0c06cf0a: /* original 6cf6, guest PC 0x0c06cf0a */
if(!s->budget--) { s->failed_pc=0x0c06cf0au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06cf0c;
P_0c06cf0c: /* original 6df6, guest PC 0x0c06cf0c */
if(!s->budget--) { s->failed_pc=0x0c06cf0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06cf0e;
P_0c06cf0e: /* original 000b, guest PC 0x0c06cf0e */
if(!s->budget--) { s->failed_pc=0x0c06cf0eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06cf10: /* original 6ef6, guest PC 0x0c06cf10 */
if(!s->budget--) { s->failed_pc=0x0c06cf10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06cf12u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06cf12u; return 0; } return 1;
P_0c06cfb8: /* original 2fe6, guest PC 0x0c06cfb8 */
if(!s->budget--) { s->failed_pc=0x0c06cfb8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cfba;
P_0c06cfba: /* original 2fd6, guest PC 0x0c06cfba */
if(!s->budget--) { s->failed_pc=0x0c06cfbau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cfbc;
P_0c06cfbc: /* original 2fc6, guest PC 0x0c06cfbc */
if(!s->budget--) { s->failed_pc=0x0c06cfbcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cfbe;
P_0c06cfbe: /* original 2fb6, guest PC 0x0c06cfbe */
if(!s->budget--) { s->failed_pc=0x0c06cfbeu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cfc0;
P_0c06cfc0: /* original 6b43, guest PC 0x0c06cfc0 */
if(!s->budget--) { s->failed_pc=0x0c06cfc0u; return 0; }
r[11]=r[4];
goto P_0c06cfc2;
P_0c06cfc2: /* original 2fa6, guest PC 0x0c06cfc2 */
if(!s->budget--) { s->failed_pc=0x0c06cfc2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cfc4;
P_0c06cfc4: /* original 2f96, guest PC 0x0c06cfc4 */
if(!s->budget--) { s->failed_pc=0x0c06cfc4u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cfc6;
P_0c06cfc6: /* original 2f86, guest PC 0x0c06cfc6 */
if(!s->budget--) { s->failed_pc=0x0c06cfc6u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cfc8;
P_0c06cfc8: /* original fffb, guest PC 0x0c06cfc8 */
if(!s->budget--) { s->failed_pc=0x0c06cfc8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06cfca;
P_0c06cfca: /* original ffeb, guest PC 0x0c06cfca */
if(!s->budget--) { s->failed_pc=0x0c06cfcau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06cfcc;
P_0c06cfcc: /* original ffdb, guest PC 0x0c06cfcc */
if(!s->budget--) { s->failed_pc=0x0c06cfccu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c06cfce;
P_0c06cfce: /* original ffcb, guest PC 0x0c06cfce */
if(!s->budget--) { s->failed_pc=0x0c06cfceu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c06cfd0;
P_0c06cfd0: /* original 4f22, guest PC 0x0c06cfd0 */
if(!s->budget--) { s->failed_pc=0x0c06cfd0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06cfd2;
P_0c06cfd2: /* original 64b2, guest PC 0x0c06cfd2 */
if(!s->budget--) { s->failed_pc=0x0c06cfd2u; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c06cfd4;
P_0c06cfd4: /* original d323, guest PC 0x0c06cfd4 */
if(!s->budget--) { s->failed_pc=0x0c06cfd4u; return 0; }
r[3]=read(ram,0x0c06d064u,4);
goto P_0c06cfd6;
P_0c06cfd6: /* original 9035, guest PC 0x0c06cfd6 */
if(!s->budget--) { s->failed_pc=0x0c06cfd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d044u,2);
goto P_0c06cfd8;
P_0c06cfd8: /* original 7ff4, guest PC 0x0c06cfd8 */
if(!s->budget--) { s->failed_pc=0x0c06cfd8u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c06cfda;
P_0c06cfda: /* original dc1d, guest PC 0x0c06cfda */
if(!s->budget--) { s->failed_pc=0x0c06cfdau; return 0; }
r[12]=read(ram,0x0c06d050u,4);
goto P_0c06cfdc;
P_0c06cfdc: /* original 2438, guest PC 0x0c06cfdc */
if(!s->budget--) { s->failed_pc=0x0c06cfdcu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c06cfde;
P_0c06cfde: /* original 8d02, guest PC 0x0c06cfde */
if(!s->budget--) { s->failed_pc=0x0c06cfdeu; return 0; }
cond=r[17]&1u;
r[8]=read(ram,r[12]+r[0],4);
if(cond) { goto P_0c06cfe6; }
goto P_0c06cfe2;
P_0c06cfe0: /* original 08ce, guest PC 0x0c06cfe0 */
if(!s->budget--) { s->failed_pc=0x0c06cfe0u; return 0; }
r[8]=read(ram,r[12]+r[0],4);
goto P_0c06cfe2;
P_0c06cfe2: /* original a220, guest PC 0x0c06cfe2 */
if(!s->budget--) { s->failed_pc=0x0c06cfe2u; return 0; }
goto P_0c06d426;
P_0c06cfe4: /* original 0009, guest PC 0x0c06cfe4 */
if(!s->budget--) { s->failed_pc=0x0c06cfe4u; return 0; }
goto P_0c06cfe6;
P_0c06cfe6: /* original da20, guest PC 0x0c06cfe6 */
if(!s->budget--) { s->failed_pc=0x0c06cfe6u; return 0; }
r[10]=read(ram,0x0c06d068u,4);
goto P_0c06cfe8;
P_0c06cfe8: /* original de20, guest PC 0x0c06cfe8 */
if(!s->budget--) { s->failed_pc=0x0c06cfe8u; return 0; }
r[14]=read(ram,0x0c06d06cu,4);
goto P_0c06cfea;
P_0c06cfea: /* original 63a2, guest PC 0x0c06cfea */
if(!s->budget--) { s->failed_pc=0x0c06cfeau; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c06cfec;
P_0c06cfec: /* original 23e8, guest PC 0x0c06cfec */
if(!s->budget--) { s->failed_pc=0x0c06cfecu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c06cfee;
P_0c06cfee: /* original 8904, guest PC 0x0c06cfee */
if(!s->budget--) { s->failed_pc=0x0c06cfeeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cffa; }
goto P_0c06cff0;
P_0c06cff0: /* original 51a1, guest PC 0x0c06cff0 */
if(!s->budget--) { s->failed_pc=0x0c06cff0u; return 0; }
r[1]=read(ram,r[10]+4,4);
goto P_0c06cff2;
P_0c06cff2: /* original 21e8, guest PC 0x0c06cff2 */
if(!s->budget--) { s->failed_pc=0x0c06cff2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[14])==0)!=0);
goto P_0c06cff4;
P_0c06cff4: /* original 8901, guest PC 0x0c06cff4 */
if(!s->budget--) { s->failed_pc=0x0c06cff4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cffa; }
goto P_0c06cff6;
P_0c06cff6: /* original a216, guest PC 0x0c06cff6 */
if(!s->budget--) { s->failed_pc=0x0c06cff6u; return 0; }
goto P_0c06d426;
P_0c06cff8: /* original 0009, guest PC 0x0c06cff8 */
if(!s->budget--) { s->failed_pc=0x0c06cff8u; return 0; }
goto P_0c06cffa;
P_0c06cffa: /* original dd1d, guest PC 0x0c06cffa */
if(!s->budget--) { s->failed_pc=0x0c06cffau; return 0; }
r[13]=read(ram,0x0c06d070u,4);
goto P_0c06cffc;
P_0c06cffc: /* original 4d0b, guest PC 0x0c06cffc */
if(!s->budget--) { s->failed_pc=0x0c06cffcu; return 0; }
target=r[13];
r[16]=code_base|0x0c06d000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d000u) { target=s->pc; goto dispatch; }
goto P_0c06d000;
P_0c06cffe: /* original 0009, guest PC 0x0c06cffe */
if(!s->budget--) { s->failed_pc=0x0c06cffeu; return 0; }
goto P_0c06d000;
P_0c06d000: /* original d21c, guest PC 0x0c06d000 */
if(!s->budget--) { s->failed_pc=0x0c06d000u; return 0; }
r[2]=read(ram,0x0c06d074u,4);
goto P_0c06d002;
P_0c06d002: /* original 420b, guest PC 0x0c06d002 */
if(!s->budget--) { s->failed_pc=0x0c06d002u; return 0; }
target=r[2];
r[16]=code_base|0x0c06d006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d006u) { target=s->pc; goto dispatch; }
goto P_0c06d006;
P_0c06d004: /* original 0009, guest PC 0x0c06d004 */
if(!s->budget--) { s->failed_pc=0x0c06d004u; return 0; }
goto P_0c06d006;
P_0c06d006: /* original d31c, guest PC 0x0c06d006 */
if(!s->budget--) { s->failed_pc=0x0c06d006u; return 0; }
r[3]=read(ram,0x0c06d078u,4);
goto P_0c06d008;
P_0c06d008: /* original 941d, guest PC 0x0c06d008 */
if(!s->budget--) { s->failed_pc=0x0c06d008u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d046u,2);
goto P_0c06d00a;
P_0c06d00a: /* original 430b, guest PC 0x0c06d00a */
if(!s->budget--) { s->failed_pc=0x0c06d00au; return 0; }
target=r[3];
r[16]=code_base|0x0c06d00eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d00eu) { target=s->pc; goto dispatch; }
goto P_0c06d00e;
P_0c06d00c: /* original 0009, guest PC 0x0c06d00c */
if(!s->budget--) { s->failed_pc=0x0c06d00cu; return 0; }
goto P_0c06d00e;
P_0c06d00e: /* original 64a2, guest PC 0x0c06d00e */
if(!s->budget--) { s->failed_pc=0x0c06d00eu; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c06d010;
P_0c06d010: /* original d91a, guest PC 0x0c06d010 */
if(!s->budget--) { s->failed_pc=0x0c06d010u; return 0; }
r[9]=read(ram,0x0c06d07cu,4);
goto P_0c06d012;
P_0c06d012: /* original 2e48, guest PC 0x0c06d012 */
if(!s->budget--) { s->failed_pc=0x0c06d012u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[4])==0)!=0);
goto P_0c06d014;
P_0c06d014: /* original 8904, guest PC 0x0c06d014 */
if(!s->budget--) { s->failed_pc=0x0c06d014u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d020; }
goto P_0c06d016;
P_0c06d016: /* original c71a, guest PC 0x0c06d016 */
if(!s->budget--) { s->failed_pc=0x0c06d016u; return 0; }
r[0]=code_base|0x0006d080u;
goto P_0c06d018;
P_0c06d018: /* original fe08, guest PC 0x0c06d018 */
if(!s->budget--) { s->failed_pc=0x0c06d018u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c06d01a;
P_0c06d01a: /* original c71a, guest PC 0x0c06d01a */
if(!s->budget--) { s->failed_pc=0x0c06d01au; return 0; }
r[0]=code_base|0x0006d084u;
goto P_0c06d01c;
P_0c06d01c: /* original a062, guest PC 0x0c06d01c */
if(!s->budget--) { s->failed_pc=0x0c06d01cu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c06d0e4;
P_0c06d01e: /* original ff08, guest PC 0x0c06d01e */
if(!s->budget--) { s->failed_pc=0x0c06d01eu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c06d020;
P_0c06d020: /* original 9212, guest PC 0x0c06d020 */
if(!s->budget--) { s->failed_pc=0x0c06d020u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d048u,2);
goto P_0c06d022;
P_0c06d022: /* original 2248, guest PC 0x0c06d022 */
if(!s->budget--) { s->failed_pc=0x0c06d022u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c06d024;
P_0c06d024: /* original 8932, guest PC 0x0c06d024 */
if(!s->budget--) { s->failed_pc=0x0c06d024u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d08c; }
goto P_0c06d026;
P_0c06d026: /* original c718, guest PC 0x0c06d026 */
if(!s->budget--) { s->failed_pc=0x0c06d026u; return 0; }
r[0]=code_base|0x0006d088u;
goto P_0c06d028;
P_0c06d028: /* original fe08, guest PC 0x0c06d028 */
if(!s->budget--) { s->failed_pc=0x0c06d028u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c06d02a;
P_0c06d02a: /* original a05b, guest PC 0x0c06d02a */
if(!s->budget--) { s->failed_pc=0x0c06d02au; return 0; }
fr[15]=0;
goto P_0c06d0e4;
P_0c06d02c: /* original ff8d, guest PC 0x0c06d02c */
if(!s->budget--) { s->failed_pc=0x0c06d02cu; return 0; }
fr[15]=0;
if(!vf3_matrix_family(0x0c06d02eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06d02eu; return 0; } return 1;
P_0c06d08c: /* original d20b, guest PC 0x0c06d08c */
if(!s->budget--) { s->failed_pc=0x0c06d08cu; return 0; }
r[2]=read(ram,0x0c06d0bcu,4);
goto P_0c06d08e;
P_0c06d08e: /* original 2248, guest PC 0x0c06d08e */
if(!s->budget--) { s->failed_pc=0x0c06d08eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c06d090;
P_0c06d090: /* original 8904, guest PC 0x0c06d090 */
if(!s->budget--) { s->failed_pc=0x0c06d090u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d09c; }
goto P_0c06d092;
P_0c06d092: /* original c70b, guest PC 0x0c06d092 */
if(!s->budget--) { s->failed_pc=0x0c06d092u; return 0; }
r[0]=code_base|0x0006d0c0u;
goto P_0c06d094;
P_0c06d094: /* original fe08, guest PC 0x0c06d094 */
if(!s->budget--) { s->failed_pc=0x0c06d094u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c06d096;
P_0c06d096: /* original c70b, guest PC 0x0c06d096 */
if(!s->budget--) { s->failed_pc=0x0c06d096u; return 0; }
r[0]=code_base|0x0006d0c4u;
goto P_0c06d098;
P_0c06d098: /* original a024, guest PC 0x0c06d098 */
if(!s->budget--) { s->failed_pc=0x0c06d098u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c06d0e4;
P_0c06d09a: /* original ff08, guest PC 0x0c06d09a */
if(!s->budget--) { s->failed_pc=0x0c06d09au; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c06d09c;
P_0c06d09c: /* original d20a, guest PC 0x0c06d09c */
if(!s->budget--) { s->failed_pc=0x0c06d09cu; return 0; }
r[2]=read(ram,0x0c06d0c8u,4);
goto P_0c06d09e;
P_0c06d09e: /* original 2248, guest PC 0x0c06d09e */
if(!s->budget--) { s->failed_pc=0x0c06d09eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c06d0a0;
P_0c06d0a0: /* original 8904, guest PC 0x0c06d0a0 */
if(!s->budget--) { s->failed_pc=0x0c06d0a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d0ac; }
goto P_0c06d0a2;
P_0c06d0a2: /* original c70a, guest PC 0x0c06d0a2 */
if(!s->budget--) { s->failed_pc=0x0c06d0a2u; return 0; }
r[0]=code_base|0x0006d0ccu;
goto P_0c06d0a4;
P_0c06d0a4: /* original fe08, guest PC 0x0c06d0a4 */
if(!s->budget--) { s->failed_pc=0x0c06d0a4u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c06d0a6;
P_0c06d0a6: /* original c70a, guest PC 0x0c06d0a6 */
if(!s->budget--) { s->failed_pc=0x0c06d0a6u; return 0; }
r[0]=code_base|0x0006d0d0u;
goto P_0c06d0a8;
P_0c06d0a8: /* original a01c, guest PC 0x0c06d0a8 */
if(!s->budget--) { s->failed_pc=0x0c06d0a8u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c06d0e4;
P_0c06d0aa: /* original ff08, guest PC 0x0c06d0aa */
if(!s->budget--) { s->failed_pc=0x0c06d0aau; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c06d0ac;
P_0c06d0ac: /* original 2498, guest PC 0x0c06d0ac */
if(!s->budget--) { s->failed_pc=0x0c06d0acu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[9])==0)!=0);
goto P_0c06d0ae;
P_0c06d0ae: /* original 8915, guest PC 0x0c06d0ae */
if(!s->budget--) { s->failed_pc=0x0c06d0aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d0dc; }
goto P_0c06d0b0;
P_0c06d0b0: /* original c708, guest PC 0x0c06d0b0 */
if(!s->budget--) { s->failed_pc=0x0c06d0b0u; return 0; }
r[0]=code_base|0x0006d0d4u;
goto P_0c06d0b2;
P_0c06d0b2: /* original fe08, guest PC 0x0c06d0b2 */
if(!s->budget--) { s->failed_pc=0x0c06d0b2u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c06d0b4;
P_0c06d0b4: /* original c708, guest PC 0x0c06d0b4 */
if(!s->budget--) { s->failed_pc=0x0c06d0b4u; return 0; }
r[0]=code_base|0x0006d0d8u;
goto P_0c06d0b6;
P_0c06d0b6: /* original a015, guest PC 0x0c06d0b6 */
if(!s->budget--) { s->failed_pc=0x0c06d0b6u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c06d0e4;
P_0c06d0b8: /* original ff08, guest PC 0x0c06d0b8 */
if(!s->budget--) { s->failed_pc=0x0c06d0b8u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
if(!vf3_matrix_family(0x0c06d0bau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06d0bau; return 0; } return 1;
P_0c06d0dc: /* original c74d, guest PC 0x0c06d0dc */
if(!s->budget--) { s->failed_pc=0x0c06d0dcu; return 0; }
r[0]=code_base|0x0006d214u;
goto P_0c06d0de;
P_0c06d0de: /* original fe08, guest PC 0x0c06d0de */
if(!s->budget--) { s->failed_pc=0x0c06d0deu; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c06d0e0;
P_0c06d0e0: /* original c74d, guest PC 0x0c06d0e0 */
if(!s->budget--) { s->failed_pc=0x0c06d0e0u; return 0; }
r[0]=code_base|0x0006d218u;
goto P_0c06d0e2;
P_0c06d0e2: /* original ff08, guest PC 0x0c06d0e2 */
if(!s->budget--) { s->failed_pc=0x0c06d0e2u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c06d0e4;
P_0c06d0e4: /* original c74d, guest PC 0x0c06d0e4 */
if(!s->budget--) { s->failed_pc=0x0c06d0e4u; return 0; }
r[0]=code_base|0x0006d21cu;
goto P_0c06d0e6;
P_0c06d0e6: /* original f408, guest PC 0x0c06d0e6 */
if(!s->budget--) { s->failed_pc=0x0c06d0e6u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c06d0e8;
P_0c06d0e8: /* original c74d, guest PC 0x0c06d0e8 */
if(!s->budget--) { s->failed_pc=0x0c06d0e8u; return 0; }
r[0]=code_base|0x0006d220u;
goto P_0c06d0ea;
P_0c06d0ea: /* original f308, guest PC 0x0c06d0ea */
if(!s->budget--) { s->failed_pc=0x0c06d0eau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06d0ec;
P_0c06d0ec: /* original e008, guest PC 0x0c06d0ec */
if(!s->budget--) { s->failed_pc=0x0c06d0ecu; return 0; }
r[0]=0x00000008u;
goto P_0c06d0ee;
P_0c06d0ee: /* original ff43, guest PC 0x0c06d0ee */
if(!s->budget--) { s->failed_pc=0x0c06d0eeu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'/');
goto P_0c06d0f0;
P_0c06d0f0: /* original fe43, guest PC 0x0c06d0f0 */
if(!s->budget--) { s->failed_pc=0x0c06d0f0u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'/');
goto P_0c06d0f2;
P_0c06d0f2: /* original 4d0b, guest PC 0x0c06d0f2 */
if(!s->budget--) { s->failed_pc=0x0c06d0f2u; return 0; }
target=r[13];
r[16]=code_base|0x0c06d0f6u;
vf3_matrix_store(s,ram,3,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d0f6u) { target=s->pc; goto dispatch; }
goto P_0c06d0f6;
P_0c06d0f4: /* original ff37, guest PC 0x0c06d0f4 */
if(!s->budget--) { s->failed_pc=0x0c06d0f4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06d0f6;
P_0c06d0f6: /* original e008, guest PC 0x0c06d0f6 */
if(!s->budget--) { s->failed_pc=0x0c06d0f6u; return 0; }
r[0]=0x00000008u;
goto P_0c06d0f8;
P_0c06d0f8: /* original d34a, guest PC 0x0c06d0f8 */
if(!s->budget--) { s->failed_pc=0x0c06d0f8u; return 0; }
r[3]=read(ram,0x0c06d224u,4);
goto P_0c06d0fa;
P_0c06d0fa: /* original f6f6, guest PC 0x0c06d0fa */
if(!s->budget--) { s->failed_pc=0x0c06d0fau; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c06d0fc;
P_0c06d0fc: /* original f5fc, guest PC 0x0c06d0fc */
if(!s->budget--) { s->failed_pc=0x0c06d0fcu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c06d0fe;
P_0c06d0fe: /* original 430b, guest PC 0x0c06d0fe */
if(!s->budget--) { s->failed_pc=0x0c06d0feu; return 0; }
target=r[3];
r[16]=code_base|0x0c06d102u;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d102u) { target=s->pc; goto dispatch; }
goto P_0c06d102;
P_0c06d100: /* original f4ec, guest PC 0x0c06d100 */
if(!s->budget--) { s->failed_pc=0x0c06d100u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06d102;
P_0c06d102: /* original d249, guest PC 0x0c06d102 */
if(!s->budget--) { s->failed_pc=0x0c06d102u; return 0; }
r[2]=read(ram,0x0c06d228u,4);
goto P_0c06d104;
P_0c06d104: /* original 947d, guest PC 0x0c06d104 */
if(!s->budget--) { s->failed_pc=0x0c06d104u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d202u,2);
goto P_0c06d106;
P_0c06d106: /* original 420b, guest PC 0x0c06d106 */
if(!s->budget--) { s->failed_pc=0x0c06d106u; return 0; }
target=r[2];
r[16]=code_base|0x0c06d10au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d10au) { target=s->pc; goto dispatch; }
goto P_0c06d10a;
P_0c06d108: /* original 0009, guest PC 0x0c06d108 */
if(!s->budget--) { s->failed_pc=0x0c06d108u; return 0; }
goto P_0c06d10a;
P_0c06d10a: /* original d348, guest PC 0x0c06d10a */
if(!s->budget--) { s->failed_pc=0x0c06d10au; return 0; }
r[3]=read(ram,0x0c06d22cu,4);
goto P_0c06d10c;
P_0c06d10c: /* original 947a, guest PC 0x0c06d10c */
if(!s->budget--) { s->failed_pc=0x0c06d10cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d204u,2);
goto P_0c06d10e;
P_0c06d10e: /* original 430b, guest PC 0x0c06d10e */
if(!s->budget--) { s->failed_pc=0x0c06d10eu; return 0; }
target=r[3];
r[16]=code_base|0x0c06d112u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d112u) { target=s->pc; goto dispatch; }
goto P_0c06d112;
P_0c06d110: /* original 0009, guest PC 0x0c06d110 */
if(!s->budget--) { s->failed_pc=0x0c06d110u; return 0; }
goto P_0c06d112;
P_0c06d112: /* original d246, guest PC 0x0c06d112 */
if(!s->budget--) { s->failed_pc=0x0c06d112u; return 0; }
r[2]=read(ram,0x0c06d22cu,4);
goto P_0c06d114;
P_0c06d114: /* original 9477, guest PC 0x0c06d114 */
if(!s->budget--) { s->failed_pc=0x0c06d114u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d206u,2);
goto P_0c06d116;
P_0c06d116: /* original 420b, guest PC 0x0c06d116 */
if(!s->budget--) { s->failed_pc=0x0c06d116u; return 0; }
target=r[2];
r[16]=code_base|0x0c06d11au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d11au) { target=s->pc; goto dispatch; }
goto P_0c06d11a;
P_0c06d118: /* original 0009, guest PC 0x0c06d118 */
if(!s->budget--) { s->failed_pc=0x0c06d118u; return 0; }
goto P_0c06d11a;
P_0c06d11a: /* original 9075, guest PC 0x0c06d11a */
if(!s->budget--) { s->failed_pc=0x0c06d11au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d208u,2);
goto P_0c06d11c;
P_0c06d11c: /* original 00bc, guest PC 0x0c06d11c */
if(!s->budget--) { s->failed_pc=0x0c06d11cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c06d11e;
P_0c06d11e: /* original 8815, guest PC 0x0c06d11e */
if(!s->budget--) { s->failed_pc=0x0c06d11eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000015u)!=0);
goto P_0c06d120;
P_0c06d120: /* original 8f05, guest PC 0x0c06d120 */
if(!s->budget--) { s->failed_pc=0x0c06d120u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c06d12e; }
goto P_0c06d124;
P_0c06d122: /* original 6403, guest PC 0x0c06d122 */
if(!s->budget--) { s->failed_pc=0x0c06d122u; return 0; }
r[4]=r[0];
goto P_0c06d124;
P_0c06d124: /* original 9071, guest PC 0x0c06d124 */
if(!s->budget--) { s->failed_pc=0x0c06d124u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d20au,2);
goto P_0c06d126;
P_0c06d126: /* original 05bc, guest PC 0x0c06d126 */
if(!s->budget--) { s->failed_pc=0x0c06d126u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c06d128;
P_0c06d128: /* original 70ea, guest PC 0x0c06d128 */
if(!s->budget--) { s->failed_pc=0x0c06d128u; return 0; }
r[0]+=0xffffffeau;
goto P_0c06d12a;
P_0c06d12a: /* original 6453, guest PC 0x0c06d12a */
if(!s->budget--) { s->failed_pc=0x0c06d12au; return 0; }
r[4]=r[5];
goto P_0c06d12c;
P_0c06d12c: /* original 0b44, guest PC 0x0c06d12c */
if(!s->budget--) { s->failed_pc=0x0c06d12cu; return 0; }
write(ram,r[11]+r[0],r[4],1);
goto P_0c06d12e;
P_0c06d12e: /* original d040, guest PC 0x0c06d12e */
if(!s->budget--) { s->failed_pc=0x0c06d12eu; return 0; }
r[0]=read(ram,0x0c06d230u,4);
goto P_0c06d130;
P_0c06d130: /* original 4408, guest PC 0x0c06d130 */
if(!s->budget--) { s->failed_pc=0x0c06d130u; return 0; }
r[4]<<=2;
goto P_0c06d132;
P_0c06d132: /* original 034e, guest PC 0x0c06d132 */
if(!s->budget--) { s->failed_pc=0x0c06d132u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c06d134;
P_0c06d134: /* original 6233, guest PC 0x0c06d134 */
if(!s->budget--) { s->failed_pc=0x0c06d134u; return 0; }
r[2]=r[3];
goto P_0c06d136;
P_0c06d136: /* original 2f32, guest PC 0x0c06d136 */
if(!s->budget--) { s->failed_pc=0x0c06d136u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06d138;
P_0c06d138: /* original 420b, guest PC 0x0c06d138 */
if(!s->budget--) { s->failed_pc=0x0c06d138u; return 0; }
target=r[2];
r[16]=code_base|0x0c06d13cu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d13cu) { target=s->pc; goto dispatch; }
goto P_0c06d13c;
P_0c06d13a: /* original 64b3, guest PC 0x0c06d13a */
if(!s->budget--) { s->failed_pc=0x0c06d13au; return 0; }
r[4]=r[11];
goto P_0c06d13c;
P_0c06d13c: /* original 9366, guest PC 0x0c06d13c */
if(!s->budget--) { s->failed_pc=0x0c06d13cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d20cu,2);
goto P_0c06d13e;
P_0c06d13e: /* original 64a2, guest PC 0x0c06d13e */
if(!s->budget--) { s->failed_pc=0x0c06d13eu; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c06d140;
P_0c06d140: /* original 2438, guest PC 0x0c06d140 */
if(!s->budget--) { s->failed_pc=0x0c06d140u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c06d142;
P_0c06d142: /* original 890e, guest PC 0x0c06d142 */
if(!s->budget--) { s->failed_pc=0x0c06d142u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d162; }
goto P_0c06d144;
P_0c06d144: /* original 84a9, guest PC 0x0c06d144 */
if(!s->budget--) { s->failed_pc=0x0c06d144u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+9,1);
goto P_0c06d146;
P_0c06d146: /* original e320, guest PC 0x0c06d146 */
if(!s->budget--) { s->failed_pc=0x0c06d146u; return 0; }
r[3]=0x00000020u;
goto P_0c06d148;
P_0c06d148: /* original 640c, guest PC 0x0c06d148 */
if(!s->budget--) { s->failed_pc=0x0c06d148u; return 0; }
r[4]=r[0]&255u;
goto P_0c06d14a;
P_0c06d14a: /* original 3433, guest PC 0x0c06d14a */
if(!s->budget--) { s->failed_pc=0x0c06d14au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c06d14c;
P_0c06d14c: /* original 8901, guest PC 0x0c06d14c */
if(!s->budget--) { s->failed_pc=0x0c06d14cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d152; }
goto P_0c06d14e;
P_0c06d14e: /* original a16a, guest PC 0x0c06d14e */
if(!s->budget--) { s->failed_pc=0x0c06d14eu; return 0; }
goto P_0c06d426;
P_0c06d150: /* original 0009, guest PC 0x0c06d150 */
if(!s->budget--) { s->failed_pc=0x0c06d150u; return 0; }
goto P_0c06d152;
P_0c06d152: /* original e225, guest PC 0x0c06d152 */
if(!s->budget--) { s->failed_pc=0x0c06d152u; return 0; }
r[2]=0x00000025u;
goto P_0c06d154;
P_0c06d154: /* original 3427, guest PC 0x0c06d154 */
if(!s->budget--) { s->failed_pc=0x0c06d154u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[2])!=0);
goto P_0c06d156;
P_0c06d156: /* original 8904, guest PC 0x0c06d156 */
if(!s->budget--) { s->failed_pc=0x0c06d156u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d162; }
goto P_0c06d158;
P_0c06d158: /* original e324, guest PC 0x0c06d158 */
if(!s->budget--) { s->failed_pc=0x0c06d158u; return 0; }
r[3]=0x00000024u;
goto P_0c06d15a;
P_0c06d15a: /* original 3433, guest PC 0x0c06d15a */
if(!s->budget--) { s->failed_pc=0x0c06d15au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c06d15c;
P_0c06d15c: /* original 8b01, guest PC 0x0c06d15c */
if(!s->budget--) { s->failed_pc=0x0c06d15cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d162; }
goto P_0c06d15e;
P_0c06d15e: /* original a162, guest PC 0x0c06d15e */
if(!s->budget--) { s->failed_pc=0x0c06d15eu; return 0; }
goto P_0c06d426;
P_0c06d160: /* original 0009, guest PC 0x0c06d160 */
if(!s->budget--) { s->failed_pc=0x0c06d160u; return 0; }
goto P_0c06d162;
P_0c06d162: /* original d334, guest PC 0x0c06d162 */
if(!s->budget--) { s->failed_pc=0x0c06d162u; return 0; }
r[3]=read(ram,0x0c06d234u,4);
goto P_0c06d164;
P_0c06d164: /* original 9053, guest PC 0x0c06d164 */
if(!s->budget--) { s->failed_pc=0x0c06d164u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d20eu,2);
goto P_0c06d166;
P_0c06d166: /* original 430b, guest PC 0x0c06d166 */
if(!s->budget--) { s->failed_pc=0x0c06d166u; return 0; }
target=r[3];
r[16]=code_base|0x0c06d16au;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d16au) { target=s->pc; goto dispatch; }
goto P_0c06d16a;
P_0c06d168: /* original 04bd, guest PC 0x0c06d168 */
if(!s->budget--) { s->failed_pc=0x0c06d168u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c06d16a;
P_0c06d16a: /* original 4d0b, guest PC 0x0c06d16a */
if(!s->budget--) { s->failed_pc=0x0c06d16au; return 0; }
target=r[13];
r[16]=code_base|0x0c06d16eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d16eu) { target=s->pc; goto dispatch; }
goto P_0c06d16e;
P_0c06d16c: /* original 0009, guest PC 0x0c06d16c */
if(!s->budget--) { s->failed_pc=0x0c06d16cu; return 0; }
goto P_0c06d16e;
P_0c06d16e: /* original d32e, guest PC 0x0c06d16e */
if(!s->budget--) { s->failed_pc=0x0c06d16eu; return 0; }
r[3]=read(ram,0x0c06d228u,4);
goto P_0c06d170;
P_0c06d170: /* original 85be, guest PC 0x0c06d170 */
if(!s->budget--) { s->failed_pc=0x0c06d170u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+28,2);
goto P_0c06d172;
P_0c06d172: /* original 430b, guest PC 0x0c06d172 */
if(!s->budget--) { s->failed_pc=0x0c06d172u; return 0; }
target=r[3];
r[16]=code_base|0x0c06d176u;
r[4]=0u-r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d176u) { target=s->pc; goto dispatch; }
goto P_0c06d176;
P_0c06d174: /* original 640b, guest PC 0x0c06d174 */
if(!s->budget--) { s->failed_pc=0x0c06d174u; return 0; }
r[4]=0u-r[0];
goto P_0c06d176;
P_0c06d176: /* original d330, guest PC 0x0c06d176 */
if(!s->budget--) { s->failed_pc=0x0c06d176u; return 0; }
r[3]=read(ram,0x0c06d238u,4);
goto P_0c06d178;
P_0c06d178: /* original 85bf, guest PC 0x0c06d178 */
if(!s->budget--) { s->failed_pc=0x0c06d178u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+30,2);
goto P_0c06d17a;
P_0c06d17a: /* original 430b, guest PC 0x0c06d17a */
if(!s->budget--) { s->failed_pc=0x0c06d17au; return 0; }
target=r[3];
r[16]=code_base|0x0c06d17eu;
r[4]=0u-r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d17eu) { target=s->pc; goto dispatch; }
goto P_0c06d17e;
P_0c06d17c: /* original 640b, guest PC 0x0c06d17c */
if(!s->budget--) { s->failed_pc=0x0c06d17cu; return 0; }
r[4]=0u-r[0];
goto P_0c06d17e;
P_0c06d17e: /* original e010, guest PC 0x0c06d17e */
if(!s->budget--) { s->failed_pc=0x0c06d17eu; return 0; }
r[0]=0x00000010u;
goto P_0c06d180;
P_0c06d180: /* original d328, guest PC 0x0c06d180 */
if(!s->budget--) { s->failed_pc=0x0c06d180u; return 0; }
r[3]=read(ram,0x0c06d224u,4);
goto P_0c06d182;
P_0c06d182: /* original f4b6, guest PC 0x0c06d182 */
if(!s->budget--) { s->failed_pc=0x0c06d182u; return 0; }
vf3_matrix_load(s,ram,4,r[11]+r[0]);
goto P_0c06d184;
P_0c06d184: /* original e014, guest PC 0x0c06d184 */
if(!s->budget--) { s->failed_pc=0x0c06d184u; return 0; }
r[0]=0x00000014u;
goto P_0c06d186;
P_0c06d186: /* original f5b6, guest PC 0x0c06d186 */
if(!s->budget--) { s->failed_pc=0x0c06d186u; return 0; }
vf3_matrix_load(s,ram,5,r[11]+r[0]);
goto P_0c06d188;
P_0c06d188: /* original e018, guest PC 0x0c06d188 */
if(!s->budget--) { s->failed_pc=0x0c06d188u; return 0; }
r[0]=0x00000018u;
goto P_0c06d18a;
P_0c06d18a: /* original f44d, guest PC 0x0c06d18a */
if(!s->budget--) { s->failed_pc=0x0c06d18au; return 0; }
fr[4]^=0x80000000u;
goto P_0c06d18c;
P_0c06d18c: /* original f54d, guest PC 0x0c06d18c */
if(!s->budget--) { s->failed_pc=0x0c06d18cu; return 0; }
fr[5]^=0x80000000u;
goto P_0c06d18e;
P_0c06d18e: /* original 430b, guest PC 0x0c06d18e */
if(!s->budget--) { s->failed_pc=0x0c06d18eu; return 0; }
target=r[3];
r[16]=code_base|0x0c06d192u;
vf3_matrix_load(s,ram,6,r[11]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d192u) { target=s->pc; goto dispatch; }
goto P_0c06d192;
P_0c06d190: /* original f6b6, guest PC 0x0c06d190 */
if(!s->budget--) { s->failed_pc=0x0c06d190u; return 0; }
vf3_matrix_load(s,ram,6,r[11]+r[0]);
goto P_0c06d192;
P_0c06d192: /* original d22a, guest PC 0x0c06d192 */
if(!s->budget--) { s->failed_pc=0x0c06d192u; return 0; }
r[2]=read(ram,0x0c06d23cu,4);
goto P_0c06d194;
P_0c06d194: /* original e301, guest PC 0x0c06d194 */
if(!s->budget--) { s->failed_pc=0x0c06d194u; return 0; }
r[3]=0x00000001u;
goto P_0c06d196;
P_0c06d196: /* original 6422, guest PC 0x0c06d196 */
if(!s->budget--) { s->failed_pc=0x0c06d196u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c06d198;
P_0c06d198: /* original 2438, guest PC 0x0c06d198 */
if(!s->budget--) { s->failed_pc=0x0c06d198u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c06d19a;
P_0c06d19a: /* original 8926, guest PC 0x0c06d19a */
if(!s->budget--) { s->failed_pc=0x0c06d19au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d1ea; }
goto P_0c06d19c;
P_0c06d19c: /* original c728, guest PC 0x0c06d19c */
if(!s->budget--) { s->failed_pc=0x0c06d19cu; return 0; }
r[0]=code_base|0x0006d240u;
goto P_0c06d19e;
P_0c06d19e: /* original fd8d, guest PC 0x0c06d19e */
if(!s->budget--) { s->failed_pc=0x0c06d19eu; return 0; }
fr[13]=0;
goto P_0c06d1a0;
P_0c06d1a0: /* original fc08, guest PC 0x0c06d1a0 */
if(!s->budget--) { s->failed_pc=0x0c06d1a0u; return 0; }
vf3_matrix_load(s,ram,12,r[0]);
goto P_0c06d1a2;
P_0c06d1a2: /* original c728, guest PC 0x0c06d1a2 */
if(!s->budget--) { s->failed_pc=0x0c06d1a2u; return 0; }
r[0]=code_base|0x0006d244u;
goto P_0c06d1a4;
P_0c06d1a4: /* original f308, guest PC 0x0c06d1a4 */
if(!s->budget--) { s->failed_pc=0x0c06d1a4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06d1a6;
P_0c06d1a6: /* original e004, guest PC 0x0c06d1a6 */
if(!s->budget--) { s->failed_pc=0x0c06d1a6u; return 0; }
r[0]=0x00000004u;
goto P_0c06d1a8;
P_0c06d1a8: /* original ff37, guest PC 0x0c06d1a8 */
if(!s->budget--) { s->failed_pc=0x0c06d1a8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06d1aa;
P_0c06d1aa: /* original 9e31, guest PC 0x0c06d1aa */
if(!s->budget--) { s->failed_pc=0x0c06d1aau; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d210u,2);
goto P_0c06d1ac;
P_0c06d1ac: /* original f38d, guest PC 0x0c06d1ac */
if(!s->budget--) { s->failed_pc=0x0c06d1acu; return 0; }
fr[3]=0;
goto P_0c06d1ae;
P_0c06d1ae: /* original 3ebc, guest PC 0x0c06d1ae */
if(!s->budget--) { s->failed_pc=0x0c06d1aeu; return 0; }
r[14]+=r[11];
goto P_0c06d1b0;
P_0c06d1b0: /* original fee9, guest PC 0x0c06d1b0 */
if(!s->budget--) { s->failed_pc=0x0c06d1b0u; return 0; }
vf3_matrix_load(s,ram,14,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c06d1b2;
P_0c06d1b2: /* original fe34, guest PC 0x0c06d1b2 */
if(!s->budget--) { s->failed_pc=0x0c06d1b2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])==as_float(fr[3]))!=0);
goto P_0c06d1b4;
P_0c06d1b4: /* original 8f02, guest PC 0x0c06d1b4 */
if(!s->budget--) { s->failed_pc=0x0c06d1b4u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,15,r[14]);
if(!cond) { goto P_0c06d1bc; }
goto P_0c06d1b8;
P_0c06d1b6: /* original ffe8, guest PC 0x0c06d1b6 */
if(!s->budget--) { s->failed_pc=0x0c06d1b6u; return 0; }
vf3_matrix_load(s,ram,15,r[14]);
goto P_0c06d1b8;
P_0c06d1b8: /* original ff34, guest PC 0x0c06d1b8 */
if(!s->budget--) { s->failed_pc=0x0c06d1b8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])==as_float(fr[3]))!=0);
goto P_0c06d1ba;
P_0c06d1ba: /* original 8916, guest PC 0x0c06d1ba */
if(!s->budget--) { s->failed_pc=0x0c06d1bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d1ea; }
goto P_0c06d1bc;
P_0c06d1bc: /* original d319, guest PC 0x0c06d1bc */
if(!s->budget--) { s->failed_pc=0x0c06d1bcu; return 0; }
r[3]=read(ram,0x0c06d224u,4);
goto P_0c06d1be;
P_0c06d1be: /* original f5fc, guest PC 0x0c06d1be */
if(!s->budget--) { s->failed_pc=0x0c06d1beu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c06d1c0;
P_0c06d1c0: /* original f6dc, guest PC 0x0c06d1c0 */
if(!s->budget--) { s->failed_pc=0x0c06d1c0u; return 0; }
vf3_matrix_move(s,6,13);
goto P_0c06d1c2;
P_0c06d1c2: /* original 430b, guest PC 0x0c06d1c2 */
if(!s->budget--) { s->failed_pc=0x0c06d1c2u; return 0; }
target=r[3];
r[16]=code_base|0x0c06d1c6u;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d1c6u) { target=s->pc; goto dispatch; }
goto P_0c06d1c6;
P_0c06d1c4: /* original f4ec, guest PC 0x0c06d1c4 */
if(!s->budget--) { s->failed_pc=0x0c06d1c4u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06d1c6;
P_0c06d1c6: /* original ffc2, guest PC 0x0c06d1c6 */
if(!s->budget--) { s->failed_pc=0x0c06d1c6u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[12],r[18],'*');
goto P_0c06d1c8;
P_0c06d1c8: /* original e004, guest PC 0x0c06d1c8 */
if(!s->budget--) { s->failed_pc=0x0c06d1c8u; return 0; }
r[0]=0x00000004u;
goto P_0c06d1ca;
P_0c06d1ca: /* original f2f6, guest PC 0x0c06d1ca */
if(!s->budget--) { s->failed_pc=0x0c06d1cau; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c06d1cc;
P_0c06d1cc: /* original f3fc, guest PC 0x0c06d1cc */
if(!s->budget--) { s->failed_pc=0x0c06d1ccu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c06d1ce;
P_0c06d1ce: /* original f35d, guest PC 0x0c06d1ce */
if(!s->budget--) { s->failed_pc=0x0c06d1ceu; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c06d1d0;
P_0c06d1d0: /* original f325, guest PC 0x0c06d1d0 */
if(!s->budget--) { s->failed_pc=0x0c06d1d0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c06d1d2;
P_0c06d1d2: /* original 8d01, guest PC 0x0c06d1d2 */
if(!s->budget--) { s->failed_pc=0x0c06d1d2u; return 0; }
cond=r[17]&1u;
fr[14]=vf3_fpu_binary(fr[14],fr[12],r[18],'*');
if(cond) { goto P_0c06d1d8; }
goto P_0c06d1d6;
P_0c06d1d4: /* original fec2, guest PC 0x0c06d1d4 */
if(!s->budget--) { s->failed_pc=0x0c06d1d4u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[12],r[18],'*');
goto P_0c06d1d6;
P_0c06d1d6: /* original ffdc, guest PC 0x0c06d1d6 */
if(!s->budget--) { s->failed_pc=0x0c06d1d6u; return 0; }
vf3_matrix_move(s,15,13);
goto P_0c06d1d8;
P_0c06d1d8: /* original e004, guest PC 0x0c06d1d8 */
if(!s->budget--) { s->failed_pc=0x0c06d1d8u; return 0; }
r[0]=0x00000004u;
goto P_0c06d1da;
P_0c06d1da: /* original f3ec, guest PC 0x0c06d1da */
if(!s->budget--) { s->failed_pc=0x0c06d1dau; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c06d1dc;
P_0c06d1dc: /* original f2f6, guest PC 0x0c06d1dc */
if(!s->budget--) { s->failed_pc=0x0c06d1dcu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c06d1de;
P_0c06d1de: /* original f35d, guest PC 0x0c06d1de */
if(!s->budget--) { s->failed_pc=0x0c06d1deu; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c06d1e0;
P_0c06d1e0: /* original f325, guest PC 0x0c06d1e0 */
if(!s->budget--) { s->failed_pc=0x0c06d1e0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c06d1e2;
P_0c06d1e2: /* original 8d01, guest PC 0x0c06d1e2 */
if(!s->budget--) { s->failed_pc=0x0c06d1e2u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,15,r[14]);
if(cond) { goto P_0c06d1e8; }
goto P_0c06d1e6;
P_0c06d1e4: /* original fefa, guest PC 0x0c06d1e4 */
if(!s->budget--) { s->failed_pc=0x0c06d1e4u; return 0; }
vf3_matrix_store(s,ram,15,r[14]);
goto P_0c06d1e6;
P_0c06d1e6: /* original fedc, guest PC 0x0c06d1e6 */
if(!s->budget--) { s->failed_pc=0x0c06d1e6u; return 0; }
vf3_matrix_move(s,14,13);
goto P_0c06d1e8;
P_0c06d1e8: /* original feeb, guest PC 0x0c06d1e8 */
if(!s->budget--) { s->failed_pc=0x0c06d1e8u; return 0; }
r[14]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[14]);
goto P_0c06d1ea;
P_0c06d1ea: /* original d217, guest PC 0x0c06d1ea */
if(!s->budget--) { s->failed_pc=0x0c06d1eau; return 0; }
r[2]=read(ram,0x0c06d248u,4);
goto P_0c06d1ec;
P_0c06d1ec: /* original 9411, guest PC 0x0c06d1ec */
if(!s->budget--) { s->failed_pc=0x0c06d1ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d212u,2);
goto P_0c06d1ee;
P_0c06d1ee: /* original 420b, guest PC 0x0c06d1ee */
if(!s->budget--) { s->failed_pc=0x0c06d1eeu; return 0; }
target=r[2];
r[16]=code_base|0x0c06d1f2u;
r[4]+=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d1f2u) { target=s->pc; goto dispatch; }
goto P_0c06d1f2;
P_0c06d1f0: /* original 34bc, guest PC 0x0c06d1f0 */
if(!s->budget--) { s->failed_pc=0x0c06d1f0u; return 0; }
r[4]+=r[11];
goto P_0c06d1f2;
P_0c06d1f2: /* original d316, guest PC 0x0c06d1f2 */
if(!s->budget--) { s->failed_pc=0x0c06d1f2u; return 0; }
r[3]=read(ram,0x0c06d24cu,4);
goto P_0c06d1f4;
P_0c06d1f4: /* original 430b, guest PC 0x0c06d1f4 */
if(!s->budget--) { s->failed_pc=0x0c06d1f4u; return 0; }
target=r[3];
r[16]=code_base|0x0c06d1f8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d1f8u) { target=s->pc; goto dispatch; }
goto P_0c06d1f8;
P_0c06d1f6: /* original 0009, guest PC 0x0c06d1f6 */
if(!s->budget--) { s->failed_pc=0x0c06d1f6u; return 0; }
goto P_0c06d1f8;
P_0c06d1f8: /* original 84a8, guest PC 0x0c06d1f8 */
if(!s->budget--) { s->failed_pc=0x0c06d1f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+8,1);
goto P_0c06d1fa;
P_0c06d1fa: /* original 600c, guest PC 0x0c06d1fa */
if(!s->budget--) { s->failed_pc=0x0c06d1fau; return 0; }
r[0]=r[0]&255u;
goto P_0c06d1fc;
P_0c06d1fc: /* original 8805, guest PC 0x0c06d1fc */
if(!s->budget--) { s->failed_pc=0x0c06d1fcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c06d1fe;
P_0c06d1fe: /* original a027, guest PC 0x0c06d1fe */
if(!s->budget--) { s->failed_pc=0x0c06d1feu; return 0; }
r[4]=r[0];
goto P_0c06d250;
P_0c06d200: /* original 6403, guest PC 0x0c06d200 */
if(!s->budget--) { s->failed_pc=0x0c06d200u; return 0; }
r[4]=r[0];
if(!vf3_matrix_family(0x0c06d202u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06d202u; return 0; } return 1;
P_0c06d250: /* original 8f2c, guest PC 0x0c06d250 */
if(!s->budget--) { s->failed_pc=0x0c06d250u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d2ac; }
goto P_0c06d254;
P_0c06d252: /* original 0009, guest PC 0x0c06d252 */
if(!s->budget--) { s->failed_pc=0x0c06d252u; return 0; }
goto P_0c06d254;
P_0c06d254: /* original d312, guest PC 0x0c06d254 */
if(!s->budget--) { s->failed_pc=0x0c06d254u; return 0; }
r[3]=read(ram,0x0c06d2a0u,4);
goto P_0c06d256;
P_0c06d256: /* original 54a1, guest PC 0x0c06d256 */
if(!s->budget--) { s->failed_pc=0x0c06d256u; return 0; }
r[4]=read(ram,r[10]+4,4);
goto P_0c06d258;
P_0c06d258: /* original 2439, guest PC 0x0c06d258 */
if(!s->budget--) { s->failed_pc=0x0c06d258u; return 0; }
r[4]&=r[3];
goto P_0c06d25a;
P_0c06d25a: /* original 2448, guest PC 0x0c06d25a */
if(!s->budget--) { s->failed_pc=0x0c06d25au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06d25c;
P_0c06d25c: /* original 8901, guest PC 0x0c06d25c */
if(!s->budget--) { s->failed_pc=0x0c06d25cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d262; }
goto P_0c06d25e;
P_0c06d25e: /* original a0e2, guest PC 0x0c06d25e */
if(!s->budget--) { s->failed_pc=0x0c06d25eu; return 0; }
goto P_0c06d426;
P_0c06d260: /* original 0009, guest PC 0x0c06d260 */
if(!s->budget--) { s->failed_pc=0x0c06d260u; return 0; }
goto P_0c06d262;
P_0c06d262: /* original 54cb, guest PC 0x0c06d262 */
if(!s->budget--) { s->failed_pc=0x0c06d262u; return 0; }
r[4]=read(ram,r[12]+44,4);
goto P_0c06d264;
P_0c06d264: /* original e302, guest PC 0x0c06d264 */
if(!s->budget--) { s->failed_pc=0x0c06d264u; return 0; }
r[3]=0x00000002u;
goto P_0c06d266;
P_0c06d266: /* original 3437, guest PC 0x0c06d266 */
if(!s->budget--) { s->failed_pc=0x0c06d266u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c06d268;
P_0c06d268: /* original 8901, guest PC 0x0c06d268 */
if(!s->budget--) { s->failed_pc=0x0c06d268u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d26e; }
goto P_0c06d26a;
P_0c06d26a: /* original a0dc, guest PC 0x0c06d26a */
if(!s->budget--) { s->failed_pc=0x0c06d26au; return 0; }
goto P_0c06d426;
P_0c06d26c: /* original 0009, guest PC 0x0c06d26c */
if(!s->budget--) { s->failed_pc=0x0c06d26cu; return 0; }
goto P_0c06d26e;
P_0c06d26e: /* original 9e15, guest PC 0x0c06d26e */
if(!s->budget--) { s->failed_pc=0x0c06d26eu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d29cu,2);
goto P_0c06d270;
P_0c06d270: /* original d30c, guest PC 0x0c06d270 */
if(!s->budget--) { s->failed_pc=0x0c06d270u; return 0; }
r[3]=read(ram,0x0c06d2a4u,4);
goto P_0c06d272;
P_0c06d272: /* original 65e3, guest PC 0x0c06d272 */
if(!s->budget--) { s->failed_pc=0x0c06d272u; return 0; }
r[5]=r[14];
goto P_0c06d274;
P_0c06d274: /* original 66e3, guest PC 0x0c06d274 */
if(!s->budget--) { s->failed_pc=0x0c06d274u; return 0; }
r[6]=r[14];
goto P_0c06d276;
P_0c06d276: /* original f58d, guest PC 0x0c06d276 */
if(!s->budget--) { s->failed_pc=0x0c06d276u; return 0; }
fr[5]=0;
goto P_0c06d278;
P_0c06d278: /* original f48d, guest PC 0x0c06d278 */
if(!s->budget--) { s->failed_pc=0x0c06d278u; return 0; }
fr[4]=0;
goto P_0c06d27a;
P_0c06d27a: /* original 430b, guest PC 0x0c06d27a */
if(!s->budget--) { s->failed_pc=0x0c06d27au; return 0; }
target=r[3];
r[16]=code_base|0x0c06d27eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d27eu) { target=s->pc; goto dispatch; }
goto P_0c06d27e;
P_0c06d27c: /* original 64e3, guest PC 0x0c06d27c */
if(!s->budget--) { s->failed_pc=0x0c06d27cu; return 0; }
r[4]=r[14];
goto P_0c06d27e;
P_0c06d27e: /* original 7f0c, guest PC 0x0c06d27e */
if(!s->budget--) { s->failed_pc=0x0c06d27eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c06d280;
P_0c06d280: /* original d209, guest PC 0x0c06d280 */
if(!s->budget--) { s->failed_pc=0x0c06d280u; return 0; }
r[2]=read(ram,0x0c06d2a8u,4);
goto P_0c06d282;
P_0c06d282: /* original 4f26, guest PC 0x0c06d282 */
if(!s->budget--) { s->failed_pc=0x0c06d282u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06d284;
P_0c06d284: /* original fcf9, guest PC 0x0c06d284 */
if(!s->budget--) { s->failed_pc=0x0c06d284u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06d286;
P_0c06d286: /* original fdf9, guest PC 0x0c06d286 */
if(!s->budget--) { s->failed_pc=0x0c06d286u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06d288;
P_0c06d288: /* original fef9, guest PC 0x0c06d288 */
if(!s->budget--) { s->failed_pc=0x0c06d288u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06d28a;
P_0c06d28a: /* original fff9, guest PC 0x0c06d28a */
if(!s->budget--) { s->failed_pc=0x0c06d28au; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06d28c;
P_0c06d28c: /* original 68f6, guest PC 0x0c06d28c */
if(!s->budget--) { s->failed_pc=0x0c06d28cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06d28e;
P_0c06d28e: /* original 69f6, guest PC 0x0c06d28e */
if(!s->budget--) { s->failed_pc=0x0c06d28eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06d290;
P_0c06d290: /* original 6af6, guest PC 0x0c06d290 */
if(!s->budget--) { s->failed_pc=0x0c06d290u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06d292;
P_0c06d292: /* original 6bf6, guest PC 0x0c06d292 */
if(!s->budget--) { s->failed_pc=0x0c06d292u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06d294;
P_0c06d294: /* original 6cf6, guest PC 0x0c06d294 */
if(!s->budget--) { s->failed_pc=0x0c06d294u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06d296;
P_0c06d296: /* original 6df6, guest PC 0x0c06d296 */
if(!s->budget--) { s->failed_pc=0x0c06d296u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06d298;
P_0c06d298: /* original 422b, guest PC 0x0c06d298 */
if(!s->budget--) { s->failed_pc=0x0c06d298u; return 0; }
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
P_0c06d29a: /* original 6ef6, guest PC 0x0c06d29a */
if(!s->budget--) { s->failed_pc=0x0c06d29au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06d29cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06d29cu; return 0; } return 1;
P_0c06d2ac: /* original 4d0b, guest PC 0x0c06d2ac */
if(!s->budget--) { s->failed_pc=0x0c06d2acu; return 0; }
target=r[13];
r[16]=code_base|0x0c06d2b0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d2b0u) { target=s->pc; goto dispatch; }
goto P_0c06d2b0;
P_0c06d2ae: /* original 0009, guest PC 0x0c06d2ae */
if(!s->budget--) { s->failed_pc=0x0c06d2aeu; return 0; }
goto P_0c06d2b0;
P_0c06d2b0: /* original b25e, guest PC 0x0c06d2b0 */
if(!s->budget--) { s->failed_pc=0x0c06d2b0u; return 0; }
target=code_base|0x0c06d770u; r[16]=code_base|0x0c06d2b4u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d2b4u) { target=s->pc; goto dispatch; }
goto P_0c06d2b4;
P_0c06d2b2: /* original 64b3, guest PC 0x0c06d2b2 */
if(!s->budget--) { s->failed_pc=0x0c06d2b2u; return 0; }
r[4]=r[11];
goto P_0c06d2b4;
P_0c06d2b4: /* original b2c0, guest PC 0x0c06d2b4 */
if(!s->budget--) { s->failed_pc=0x0c06d2b4u; return 0; }
target=code_base|0x0c06d838u; r[16]=code_base|0x0c06d2b8u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d2b8u) { target=s->pc; goto dispatch; }
goto P_0c06d2b8;
P_0c06d2b6: /* original 64b3, guest PC 0x0c06d2b6 */
if(!s->budget--) { s->failed_pc=0x0c06d2b6u; return 0; }
r[4]=r[11];
goto P_0c06d2b8;
P_0c06d2b8: /* original d33b, guest PC 0x0c06d2b8 */
if(!s->budget--) { s->failed_pc=0x0c06d2b8u; return 0; }
r[3]=read(ram,0x0c06d3a8u,4);
goto P_0c06d2ba;
P_0c06d2ba: /* original 430b, guest PC 0x0c06d2ba */
if(!s->budget--) { s->failed_pc=0x0c06d2bau; return 0; }
target=r[3];
r[16]=code_base|0x0c06d2beu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d2beu) { target=s->pc; goto dispatch; }
goto P_0c06d2be;
P_0c06d2bc: /* original 0009, guest PC 0x0c06d2bc */
if(!s->budget--) { s->failed_pc=0x0c06d2bcu; return 0; }
goto P_0c06d2be;
P_0c06d2be: /* original d23b, guest PC 0x0c06d2be */
if(!s->budget--) { s->failed_pc=0x0c06d2beu; return 0; }
r[2]=read(ram,0x0c06d3acu,4);
goto P_0c06d2c0;
P_0c06d2c0: /* original 420b, guest PC 0x0c06d2c0 */
if(!s->budget--) { s->failed_pc=0x0c06d2c0u; return 0; }
target=r[2];
r[16]=code_base|0x0c06d2c4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d2c4u) { target=s->pc; goto dispatch; }
goto P_0c06d2c4;
P_0c06d2c2: /* original 0009, guest PC 0x0c06d2c2 */
if(!s->budget--) { s->failed_pc=0x0c06d2c2u; return 0; }
goto P_0c06d2c4;
P_0c06d2c4: /* original 9068, guest PC 0x0c06d2c4 */
if(!s->budget--) { s->failed_pc=0x0c06d2c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d398u,2);
goto P_0c06d2c6;
P_0c06d2c6: /* original 04cc, guest PC 0x0c06d2c6 */
if(!s->budget--) { s->failed_pc=0x0c06d2c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c06d2c8;
P_0c06d2c8: /* original 604c, guest PC 0x0c06d2c8 */
if(!s->budget--) { s->failed_pc=0x0c06d2c8u; return 0; }
r[0]=r[4]&255u;
goto P_0c06d2ca;
P_0c06d2ca: /* original 8802, guest PC 0x0c06d2ca */
if(!s->budget--) { s->failed_pc=0x0c06d2cau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c06d2cc;
P_0c06d2cc: /* original 8d03, guest PC 0x0c06d2cc */
if(!s->budget--) { s->failed_pc=0x0c06d2ccu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c06d2d6; }
goto P_0c06d2d0;
P_0c06d2ce: /* original 6403, guest PC 0x0c06d2ce */
if(!s->budget--) { s->failed_pc=0x0c06d2ceu; return 0; }
r[4]=r[0];
goto P_0c06d2d0;
P_0c06d2d0: /* original d337, guest PC 0x0c06d2d0 */
if(!s->budget--) { s->failed_pc=0x0c06d2d0u; return 0; }
r[3]=read(ram,0x0c06d3b0u,4);
goto P_0c06d2d2;
P_0c06d2d2: /* original 430b, guest PC 0x0c06d2d2 */
if(!s->budget--) { s->failed_pc=0x0c06d2d2u; return 0; }
target=r[3];
r[16]=code_base|0x0c06d2d6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d2d6u) { target=s->pc; goto dispatch; }
goto P_0c06d2d6;
P_0c06d2d4: /* original 0009, guest PC 0x0c06d2d4 */
if(!s->budget--) { s->failed_pc=0x0c06d2d4u; return 0; }
goto P_0c06d2d6;
P_0c06d2d6: /* original d237, guest PC 0x0c06d2d6 */
if(!s->budget--) { s->failed_pc=0x0c06d2d6u; return 0; }
r[2]=read(ram,0x0c06d3b4u,4);
goto P_0c06d2d8;
P_0c06d2d8: /* original 420b, guest PC 0x0c06d2d8 */
if(!s->budget--) { s->failed_pc=0x0c06d2d8u; return 0; }
target=r[2];
r[16]=code_base|0x0c06d2dcu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d2dcu) { target=s->pc; goto dispatch; }
goto P_0c06d2dc;
P_0c06d2da: /* original 0009, guest PC 0x0c06d2da */
if(!s->budget--) { s->failed_pc=0x0c06d2dau; return 0; }
goto P_0c06d2dc;
P_0c06d2dc: /* original dd36, guest PC 0x0c06d2dc */
if(!s->budget--) { s->failed_pc=0x0c06d2dcu; return 0; }
r[13]=read(ram,0x0c06d3b8u,4);
goto P_0c06d2de;
P_0c06d2de: /* original 64a2, guest PC 0x0c06d2de */
if(!s->budget--) { s->failed_pc=0x0c06d2deu; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c06d2e0;
P_0c06d2e0: /* original 24d8, guest PC 0x0c06d2e0 */
if(!s->budget--) { s->failed_pc=0x0c06d2e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[13])==0)!=0);
goto P_0c06d2e2;
P_0c06d2e2: /* original 8924, guest PC 0x0c06d2e2 */
if(!s->budget--) { s->failed_pc=0x0c06d2e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d32e; }
goto P_0c06d2e4;
P_0c06d2e4: /* original 54a1, guest PC 0x0c06d2e4 */
if(!s->budget--) { s->failed_pc=0x0c06d2e4u; return 0; }
r[4]=read(ram,r[10]+4,4);
goto P_0c06d2e6;
P_0c06d2e6: /* original 2498, guest PC 0x0c06d2e6 */
if(!s->budget--) { s->failed_pc=0x0c06d2e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[9])==0)!=0);
goto P_0c06d2e8;
P_0c06d2e8: /* original 8921, guest PC 0x0c06d2e8 */
if(!s->budget--) { s->failed_pc=0x0c06d2e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d32e; }
goto P_0c06d2ea;
P_0c06d2ea: /* original e01c, guest PC 0x0c06d2ea */
if(!s->budget--) { s->failed_pc=0x0c06d2eau; return 0; }
r[0]=0x0000001cu;
goto P_0c06d2ec;
P_0c06d2ec: /* original 00ac, guest PC 0x0c06d2ec */
if(!s->budget--) { s->failed_pc=0x0c06d2ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c06d2ee;
P_0c06d2ee: /* original 600c, guest PC 0x0c06d2ee */
if(!s->budget--) { s->failed_pc=0x0c06d2eeu; return 0; }
r[0]=r[0]&255u;
goto P_0c06d2f0;
P_0c06d2f0: /* original c90f, guest PC 0x0c06d2f0 */
if(!s->budget--) { s->failed_pc=0x0c06d2f0u; return 0; }
r[0]&=15u;
goto P_0c06d2f2;
P_0c06d2f2: /* original 880d, guest PC 0x0c06d2f2 */
if(!s->budget--) { s->failed_pc=0x0c06d2f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c06d2f4;
P_0c06d2f4: /* original 8b1b, guest PC 0x0c06d2f4 */
if(!s->budget--) { s->failed_pc=0x0c06d2f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d32e; }
goto P_0c06d2f6;
P_0c06d2f6: /* original e060, guest PC 0x0c06d2f6 */
if(!s->budget--) { s->failed_pc=0x0c06d2f6u; return 0; }
r[0]=0x00000060u;
goto P_0c06d2f8;
P_0c06d2f8: /* original 048c, guest PC 0x0c06d2f8 */
if(!s->budget--) { s->failed_pc=0x0c06d2f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[8]+r[0],1);
goto P_0c06d2fa;
P_0c06d2fa: /* original 604c, guest PC 0x0c06d2fa */
if(!s->budget--) { s->failed_pc=0x0c06d2fau; return 0; }
r[0]=r[4]&255u;
goto P_0c06d2fc;
P_0c06d2fc: /* original 8808, guest PC 0x0c06d2fc */
if(!s->budget--) { s->failed_pc=0x0c06d2fcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c06d2fe;
P_0c06d2fe: /* original 8d03, guest PC 0x0c06d2fe */
if(!s->budget--) { s->failed_pc=0x0c06d2feu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c06d308; }
goto P_0c06d302;
P_0c06d300: /* original 6403, guest PC 0x0c06d300 */
if(!s->budget--) { s->failed_pc=0x0c06d300u; return 0; }
r[4]=r[0];
goto P_0c06d302;
P_0c06d302: /* original 6043, guest PC 0x0c06d302 */
if(!s->budget--) { s->failed_pc=0x0c06d302u; return 0; }
r[0]=r[4];
goto P_0c06d304;
P_0c06d304: /* original 8815, guest PC 0x0c06d304 */
if(!s->budget--) { s->failed_pc=0x0c06d304u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000015u)!=0);
goto P_0c06d306;
P_0c06d306: /* original 8b12, guest PC 0x0c06d306 */
if(!s->budget--) { s->failed_pc=0x0c06d306u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d32e; }
goto P_0c06d308;
P_0c06d308: /* original e019, guest PC 0x0c06d308 */
if(!s->budget--) { s->failed_pc=0x0c06d308u; return 0; }
r[0]=0x00000019u;
goto P_0c06d30a;
P_0c06d30a: /* original 00cc, guest PC 0x0c06d30a */
if(!s->budget--) { s->failed_pc=0x0c06d30au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c06d30c;
P_0c06d30c: /* original 600c, guest PC 0x0c06d30c */
if(!s->budget--) { s->failed_pc=0x0c06d30cu; return 0; }
r[0]=r[0]&255u;
goto P_0c06d30e;
P_0c06d30e: /* original 8802, guest PC 0x0c06d30e */
if(!s->budget--) { s->failed_pc=0x0c06d30eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c06d310;
P_0c06d310: /* original 890d, guest PC 0x0c06d310 */
if(!s->budget--) { s->failed_pc=0x0c06d310u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d32e; }
goto P_0c06d312;
P_0c06d312: /* original e018, guest PC 0x0c06d312 */
if(!s->budget--) { s->failed_pc=0x0c06d312u; return 0; }
r[0]=0x00000018u;
goto P_0c06d314;
P_0c06d314: /* original 03cc, guest PC 0x0c06d314 */
if(!s->budget--) { s->failed_pc=0x0c06d314u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c06d316;
P_0c06d316: /* original 2338, guest PC 0x0c06d316 */
if(!s->budget--) { s->failed_pc=0x0c06d316u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06d318;
P_0c06d318: /* original 8b09, guest PC 0x0c06d318 */
if(!s->budget--) { s->failed_pc=0x0c06d318u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d32e; }
goto P_0c06d31a;
P_0c06d31a: /* original e046, guest PC 0x0c06d31a */
if(!s->budget--) { s->failed_pc=0x0c06d31au; return 0; }
r[0]=0x00000046u;
goto P_0c06d31c;
P_0c06d31c: /* original 028d, guest PC 0x0c06d31c */
if(!s->budget--) { s->failed_pc=0x0c06d31cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+r[0],2);
goto P_0c06d31e;
P_0c06d31e: /* original 903c, guest PC 0x0c06d31e */
if(!s->budget--) { s->failed_pc=0x0c06d31eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d39au,2);
goto P_0c06d320;
P_0c06d320: /* original 622d, guest PC 0x0c06d320 */
if(!s->budget--) { s->failed_pc=0x0c06d320u; return 0; }
r[2]=r[2]&65535u;
goto P_0c06d322;
P_0c06d322: /* original 038d, guest PC 0x0c06d322 */
if(!s->budget--) { s->failed_pc=0x0c06d322u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+r[0],2);
goto P_0c06d324;
P_0c06d324: /* original 3230, guest PC 0x0c06d324 */
if(!s->budget--) { s->failed_pc=0x0c06d324u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c06d326;
P_0c06d326: /* original 8b02, guest PC 0x0c06d326 */
if(!s->budget--) { s->failed_pc=0x0c06d326u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d32e; }
goto P_0c06d328;
P_0c06d328: /* original d324, guest PC 0x0c06d328 */
if(!s->budget--) { s->failed_pc=0x0c06d328u; return 0; }
r[3]=read(ram,0x0c06d3bcu,4);
goto P_0c06d32a;
P_0c06d32a: /* original 430b, guest PC 0x0c06d32a */
if(!s->budget--) { s->failed_pc=0x0c06d32au; return 0; }
target=r[3];
r[16]=code_base|0x0c06d32eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d32eu) { target=s->pc; goto dispatch; }
goto P_0c06d32e;
P_0c06d32c: /* original 0009, guest PC 0x0c06d32c */
if(!s->budget--) { s->failed_pc=0x0c06d32cu; return 0; }
goto P_0c06d32e;
P_0c06d32e: /* original 64a2, guest PC 0x0c06d32e */
if(!s->budget--) { s->failed_pc=0x0c06d32eu; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c06d330;
P_0c06d330: /* original de23, guest PC 0x0c06d330 */
if(!s->budget--) { s->failed_pc=0x0c06d330u; return 0; }
r[14]=read(ram,0x0c06d3c0u,4);
goto P_0c06d332;
P_0c06d332: /* original 24d8, guest PC 0x0c06d332 */
if(!s->budget--) { s->failed_pc=0x0c06d332u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[13])==0)!=0);
goto P_0c06d334;
P_0c06d334: /* original 8917, guest PC 0x0c06d334 */
if(!s->budget--) { s->failed_pc=0x0c06d334u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d366; }
goto P_0c06d336;
P_0c06d336: /* original 54a1, guest PC 0x0c06d336 */
if(!s->budget--) { s->failed_pc=0x0c06d336u; return 0; }
r[4]=read(ram,r[10]+4,4);
goto P_0c06d338;
P_0c06d338: /* original 2498, guest PC 0x0c06d338 */
if(!s->budget--) { s->failed_pc=0x0c06d338u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[9])==0)!=0);
goto P_0c06d33a;
P_0c06d33a: /* original 8914, guest PC 0x0c06d33a */
if(!s->budget--) { s->failed_pc=0x0c06d33au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d366; }
goto P_0c06d33c;
P_0c06d33c: /* original 902e, guest PC 0x0c06d33c */
if(!s->budget--) { s->failed_pc=0x0c06d33cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d39cu,2);
goto P_0c06d33e;
P_0c06d33e: /* original 04ce, guest PC 0x0c06d33e */
if(!s->budget--) { s->failed_pc=0x0c06d33eu; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c06d340;
P_0c06d340: /* original 902d, guest PC 0x0c06d340 */
if(!s->budget--) { s->failed_pc=0x0c06d340u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d39eu,2);
goto P_0c06d342;
P_0c06d342: /* original 004e, guest PC 0x0c06d342 */
if(!s->budget--) { s->failed_pc=0x0c06d342u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c06d344;
P_0c06d344: /* original c808, guest PC 0x0c06d344 */
if(!s->budget--) { s->failed_pc=0x0c06d344u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c06d346;
P_0c06d346: /* original 890e, guest PC 0x0c06d346 */
if(!s->budget--) { s->failed_pc=0x0c06d346u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d366; }
goto P_0c06d348;
P_0c06d348: /* original e044, guest PC 0x0c06d348 */
if(!s->budget--) { s->failed_pc=0x0c06d348u; return 0; }
r[0]=0x00000044u;
goto P_0c06d34a;
P_0c06d34a: /* original 932a, guest PC 0x0c06d34a */
if(!s->budget--) { s->failed_pc=0x0c06d34au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d3a2u,2);
goto P_0c06d34c;
P_0c06d34c: /* original 04ee, guest PC 0x0c06d34c */
if(!s->budget--) { s->failed_pc=0x0c06d34cu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c06d34e;
P_0c06d34e: /* original 9027, guest PC 0x0c06d34e */
if(!s->budget--) { s->failed_pc=0x0c06d34eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d3a0u,2);
goto P_0c06d350;
P_0c06d350: /* original 044e, guest PC 0x0c06d350 */
if(!s->budget--) { s->failed_pc=0x0c06d350u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c06d352;
P_0c06d352: /* original 334c, guest PC 0x0c06d352 */
if(!s->budget--) { s->failed_pc=0x0c06d352u; return 0; }
r[3]+=r[4];
goto P_0c06d354;
P_0c06d354: /* original 6433, guest PC 0x0c06d354 */
if(!s->budget--) { s->failed_pc=0x0c06d354u; return 0; }
r[4]=r[3];
goto P_0c06d356;
P_0c06d356: /* original 2f32, guest PC 0x0c06d356 */
if(!s->budget--) { s->failed_pc=0x0c06d356u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06d358;
P_0c06d358: /* original d31a, guest PC 0x0c06d358 */
if(!s->budget--) { s->failed_pc=0x0c06d358u; return 0; }
r[3]=read(ram,0x0c06d3c4u,4);
goto P_0c06d35a;
P_0c06d35a: /* original 430b, guest PC 0x0c06d35a */
if(!s->budget--) { s->failed_pc=0x0c06d35au; return 0; }
target=r[3];
r[16]=code_base|0x0c06d35eu;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d35eu) { target=s->pc; goto dispatch; }
goto P_0c06d35e;
P_0c06d35c: /* original 7410, guest PC 0x0c06d35c */
if(!s->budget--) { s->failed_pc=0x0c06d35cu; return 0; }
r[4]+=0x00000010u;
goto P_0c06d35e;
P_0c06d35e: /* original d21a, guest PC 0x0c06d35e */
if(!s->budget--) { s->failed_pc=0x0c06d35eu; return 0; }
r[2]=read(ram,0x0c06d3c8u,4);
goto P_0c06d360;
P_0c06d360: /* original 9420, guest PC 0x0c06d360 */
if(!s->budget--) { s->failed_pc=0x0c06d360u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d3a4u,2);
goto P_0c06d362;
P_0c06d362: /* original 420b, guest PC 0x0c06d362 */
if(!s->budget--) { s->failed_pc=0x0c06d362u; return 0; }
target=r[2];
r[16]=code_base|0x0c06d366u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d366u) { target=s->pc; goto dispatch; }
goto P_0c06d366;
P_0c06d364: /* original 0009, guest PC 0x0c06d364 */
if(!s->budget--) { s->failed_pc=0x0c06d364u; return 0; }
goto P_0c06d366;
P_0c06d366: /* original d319, guest PC 0x0c06d366 */
if(!s->budget--) { s->failed_pc=0x0c06d366u; return 0; }
r[3]=read(ram,0x0c06d3ccu,4);
goto P_0c06d368;
P_0c06d368: /* original 430b, guest PC 0x0c06d368 */
if(!s->budget--) { s->failed_pc=0x0c06d368u; return 0; }
target=r[3];
r[16]=code_base|0x0c06d36cu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d36cu) { target=s->pc; goto dispatch; }
goto P_0c06d36c;
P_0c06d36a: /* original 64b3, guest PC 0x0c06d36a */
if(!s->budget--) { s->failed_pc=0x0c06d36au; return 0; }
r[4]=r[11];
goto P_0c06d36c;
P_0c06d36c: /* original d218, guest PC 0x0c06d36c */
if(!s->budget--) { s->failed_pc=0x0c06d36cu; return 0; }
r[2]=read(ram,0x0c06d3d0u,4);
goto P_0c06d36e;
P_0c06d36e: /* original 420b, guest PC 0x0c06d36e */
if(!s->budget--) { s->failed_pc=0x0c06d36eu; return 0; }
target=r[2];
r[16]=code_base|0x0c06d372u;
r[4]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d372u) { target=s->pc; goto dispatch; }
goto P_0c06d372;
P_0c06d370: /* original 54e4, guest PC 0x0c06d370 */
if(!s->budget--) { s->failed_pc=0x0c06d370u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c06d372;
P_0c06d372: /* original d317, guest PC 0x0c06d372 */
if(!s->budget--) { s->failed_pc=0x0c06d372u; return 0; }
r[3]=read(ram,0x0c06d3d0u,4);
goto P_0c06d374;
P_0c06d374: /* original 430b, guest PC 0x0c06d374 */
if(!s->budget--) { s->failed_pc=0x0c06d374u; return 0; }
target=r[3];
r[16]=code_base|0x0c06d378u;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d378u) { target=s->pc; goto dispatch; }
goto P_0c06d378;
P_0c06d376: /* original 54e5, guest PC 0x0c06d376 */
if(!s->budget--) { s->failed_pc=0x0c06d376u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c06d378;
P_0c06d378: /* original d216, guest PC 0x0c06d378 */
if(!s->budget--) { s->failed_pc=0x0c06d378u; return 0; }
r[2]=read(ram,0x0c06d3d4u,4);
goto P_0c06d37a;
P_0c06d37a: /* original 6ca2, guest PC 0x0c06d37a */
if(!s->budget--) { s->failed_pc=0x0c06d37au; return 0; }
tmp=read(ram,r[10],4);
r[12]=tmp;
goto P_0c06d37c;
P_0c06d37c: /* original 22c8, guest PC 0x0c06d37c */
if(!s->budget--) { s->failed_pc=0x0c06d37cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c06d37e;
P_0c06d37e: /* original 8b4d, guest PC 0x0c06d37e */
if(!s->budget--) { s->failed_pc=0x0c06d37eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d41c; }
goto P_0c06d380;
P_0c06d380: /* original 2dc8, guest PC 0x0c06d380 */
if(!s->budget--) { s->failed_pc=0x0c06d380u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[12])==0)!=0);
goto P_0c06d382;
P_0c06d382: /* original 8903, guest PC 0x0c06d382 */
if(!s->budget--) { s->failed_pc=0x0c06d382u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d38c; }
goto P_0c06d384;
P_0c06d384: /* original 52a1, guest PC 0x0c06d384 */
if(!s->budget--) { s->failed_pc=0x0c06d384u; return 0; }
r[2]=read(ram,r[10]+4,4);
goto P_0c06d386;
P_0c06d386: /* original d314, guest PC 0x0c06d386 */
if(!s->budget--) { s->failed_pc=0x0c06d386u; return 0; }
r[3]=read(ram,0x0c06d3d8u,4);
goto P_0c06d388;
P_0c06d388: /* original 2238, guest PC 0x0c06d388 */
if(!s->budget--) { s->failed_pc=0x0c06d388u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c06d38a;
P_0c06d38a: /* original 8b47, guest PC 0x0c06d38a */
if(!s->budget--) { s->failed_pc=0x0c06d38au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d41c; }
goto P_0c06d38c;
P_0c06d38c: /* original b064, guest PC 0x0c06d38c */
if(!s->budget--) { s->failed_pc=0x0c06d38cu; return 0; }
target=code_base|0x0c06d458u; r[16]=code_base|0x0c06d390u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d390u) { target=s->pc; goto dispatch; }
goto P_0c06d390;
P_0c06d38e: /* original 64b3, guest PC 0x0c06d38e */
if(!s->budget--) { s->failed_pc=0x0c06d38eu; return 0; }
r[4]=r[11];
goto P_0c06d390;
P_0c06d390: /* original d212, guest PC 0x0c06d390 */
if(!s->budget--) { s->failed_pc=0x0c06d390u; return 0; }
r[2]=read(ram,0x0c06d3dcu,4);
goto P_0c06d392;
P_0c06d392: /* original 2c28, guest PC 0x0c06d392 */
if(!s->budget--) { s->failed_pc=0x0c06d392u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[2])==0)!=0);
goto P_0c06d394;
P_0c06d394: /* original a024, guest PC 0x0c06d394 */
if(!s->budget--) { s->failed_pc=0x0c06d394u; return 0; }
goto P_0c06d3e0;
P_0c06d396: /* original 0009, guest PC 0x0c06d396 */
if(!s->budget--) { s->failed_pc=0x0c06d396u; return 0; }
if(!vf3_matrix_family(0x0c06d398u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06d398u; return 0; } return 1;
P_0c06d3e0: /* original 8b15, guest PC 0x0c06d3e0 */
if(!s->budget--) { s->failed_pc=0x0c06d3e0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d40e; }
goto P_0c06d3e2;
P_0c06d3e2: /* original e01c, guest PC 0x0c06d3e2 */
if(!s->budget--) { s->failed_pc=0x0c06d3e2u; return 0; }
r[0]=0x0000001cu;
goto P_0c06d3e4;
P_0c06d3e4: /* original 00ac, guest PC 0x0c06d3e4 */
if(!s->budget--) { s->failed_pc=0x0c06d3e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c06d3e6;
P_0c06d3e6: /* original e40f, guest PC 0x0c06d3e6 */
if(!s->budget--) { s->failed_pc=0x0c06d3e6u; return 0; }
r[4]=0x0000000fu;
goto P_0c06d3e8;
P_0c06d3e8: /* original 600c, guest PC 0x0c06d3e8 */
if(!s->budget--) { s->failed_pc=0x0c06d3e8u; return 0; }
r[0]=r[0]&255u;
goto P_0c06d3ea;
P_0c06d3ea: /* original 2409, guest PC 0x0c06d3ea */
if(!s->budget--) { s->failed_pc=0x0c06d3eau; return 0; }
r[4]&=r[0];
goto P_0c06d3ec;
P_0c06d3ec: /* original 6043, guest PC 0x0c06d3ec */
if(!s->budget--) { s->failed_pc=0x0c06d3ecu; return 0; }
r[0]=r[4];
goto P_0c06d3ee;
P_0c06d3ee: /* original 880b, guest PC 0x0c06d3ee */
if(!s->budget--) { s->failed_pc=0x0c06d3eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c06d3f0;
P_0c06d3f0: /* original 890d, guest PC 0x0c06d3f0 */
if(!s->budget--) { s->failed_pc=0x0c06d3f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d40e; }
goto P_0c06d3f2;
P_0c06d3f2: /* original 6043, guest PC 0x0c06d3f2 */
if(!s->budget--) { s->failed_pc=0x0c06d3f2u; return 0; }
r[0]=r[4];
goto P_0c06d3f4;
P_0c06d3f4: /* original 880d, guest PC 0x0c06d3f4 */
if(!s->budget--) { s->failed_pc=0x0c06d3f4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c06d3f6;
P_0c06d3f6: /* original 8b04, guest PC 0x0c06d3f6 */
if(!s->budget--) { s->failed_pc=0x0c06d3f6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d402; }
goto P_0c06d3f8;
P_0c06d3f8: /* original d312, guest PC 0x0c06d3f8 */
if(!s->budget--) { s->failed_pc=0x0c06d3f8u; return 0; }
r[3]=read(ram,0x0c06d444u,4);
goto P_0c06d3fa;
P_0c06d3fa: /* original 430b, guest PC 0x0c06d3fa */
if(!s->budget--) { s->failed_pc=0x0c06d3fau; return 0; }
target=r[3];
r[16]=code_base|0x0c06d3feu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d3feu) { target=s->pc; goto dispatch; }
goto P_0c06d3fe;
P_0c06d3fc: /* original 64b3, guest PC 0x0c06d3fc */
if(!s->budget--) { s->failed_pc=0x0c06d3fcu; return 0; }
r[4]=r[11];
goto P_0c06d3fe;
P_0c06d3fe: /* original a006, guest PC 0x0c06d3fe */
if(!s->budget--) { s->failed_pc=0x0c06d3feu; return 0; }
goto P_0c06d40e;
P_0c06d400: /* original 0009, guest PC 0x0c06d400 */
if(!s->budget--) { s->failed_pc=0x0c06d400u; return 0; }
goto P_0c06d402;
P_0c06d402: /* original d311, guest PC 0x0c06d402 */
if(!s->budget--) { s->failed_pc=0x0c06d402u; return 0; }
r[3]=read(ram,0x0c06d448u,4);
goto P_0c06d404;
P_0c06d404: /* original 430b, guest PC 0x0c06d404 */
if(!s->budget--) { s->failed_pc=0x0c06d404u; return 0; }
target=r[3];
r[16]=code_base|0x0c06d408u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d408u) { target=s->pc; goto dispatch; }
goto P_0c06d408;
P_0c06d406: /* original 0009, guest PC 0x0c06d406 */
if(!s->budget--) { s->failed_pc=0x0c06d406u; return 0; }
goto P_0c06d408;
P_0c06d408: /* original d210, guest PC 0x0c06d408 */
if(!s->budget--) { s->failed_pc=0x0c06d408u; return 0; }
r[2]=read(ram,0x0c06d44cu,4);
goto P_0c06d40a;
P_0c06d40a: /* original 420b, guest PC 0x0c06d40a */
if(!s->budget--) { s->failed_pc=0x0c06d40au; return 0; }
target=r[2];
r[16]=code_base|0x0c06d40eu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d40eu) { target=s->pc; goto dispatch; }
goto P_0c06d40e;
P_0c06d40c: /* original 64b3, guest PC 0x0c06d40c */
if(!s->budget--) { s->failed_pc=0x0c06d40cu; return 0; }
r[4]=r[11];
goto P_0c06d40e;
P_0c06d40e: /* original d310, guest PC 0x0c06d40e */
if(!s->budget--) { s->failed_pc=0x0c06d40eu; return 0; }
r[3]=read(ram,0x0c06d450u,4);
goto P_0c06d410;
P_0c06d410: /* original 6032, guest PC 0x0c06d410 */
if(!s->budget--) { s->failed_pc=0x0c06d410u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c06d412;
P_0c06d412: /* original c880, guest PC 0x0c06d412 */
if(!s->budget--) { s->failed_pc=0x0c06d412u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c06d414;
P_0c06d414: /* original 8b02, guest PC 0x0c06d414 */
if(!s->budget--) { s->failed_pc=0x0c06d414u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d41c; }
goto P_0c06d416;
P_0c06d416: /* original d10f, guest PC 0x0c06d416 */
if(!s->budget--) { s->failed_pc=0x0c06d416u; return 0; }
r[1]=read(ram,0x0c06d454u,4);
goto P_0c06d418;
P_0c06d418: /* original 410b, guest PC 0x0c06d418 */
if(!s->budget--) { s->failed_pc=0x0c06d418u; return 0; }
target=r[1];
r[16]=code_base|0x0c06d41cu;
r[4]=0x00000007u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d41cu) { target=s->pc; goto dispatch; }
goto P_0c06d41c;
P_0c06d41a: /* original e407, guest PC 0x0c06d41a */
if(!s->budget--) { s->failed_pc=0x0c06d41au; return 0; }
r[4]=0x00000007u;
goto P_0c06d41c;
P_0c06d41c: /* original 54e8, guest PC 0x0c06d41c */
if(!s->budget--) { s->failed_pc=0x0c06d41cu; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c06d41e;
P_0c06d41e: /* original e3fd, guest PC 0x0c06d41e */
if(!s->budget--) { s->failed_pc=0x0c06d41eu; return 0; }
r[3]=0xfffffffdu;
goto P_0c06d420;
P_0c06d420: /* original 6242, guest PC 0x0c06d420 */
if(!s->budget--) { s->failed_pc=0x0c06d420u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c06d422;
P_0c06d422: /* original 2239, guest PC 0x0c06d422 */
if(!s->budget--) { s->failed_pc=0x0c06d422u; return 0; }
r[2]&=r[3];
goto P_0c06d424;
P_0c06d424: /* original 2422, guest PC 0x0c06d424 */
if(!s->budget--) { s->failed_pc=0x0c06d424u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c06d426;
P_0c06d426: /* original 7f0c, guest PC 0x0c06d426 */
if(!s->budget--) { s->failed_pc=0x0c06d426u; return 0; }
r[15]+=0x0000000cu;
goto P_0c06d428;
P_0c06d428: /* original 4f26, guest PC 0x0c06d428 */
if(!s->budget--) { s->failed_pc=0x0c06d428u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06d42a;
P_0c06d42a: /* original fcf9, guest PC 0x0c06d42a */
if(!s->budget--) { s->failed_pc=0x0c06d42au; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06d42c;
P_0c06d42c: /* original fdf9, guest PC 0x0c06d42c */
if(!s->budget--) { s->failed_pc=0x0c06d42cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06d42e;
P_0c06d42e: /* original fef9, guest PC 0x0c06d42e */
if(!s->budget--) { s->failed_pc=0x0c06d42eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06d430;
P_0c06d430: /* original fff9, guest PC 0x0c06d430 */
if(!s->budget--) { s->failed_pc=0x0c06d430u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06d432;
P_0c06d432: /* original 68f6, guest PC 0x0c06d432 */
if(!s->budget--) { s->failed_pc=0x0c06d432u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06d434;
P_0c06d434: /* original 69f6, guest PC 0x0c06d434 */
if(!s->budget--) { s->failed_pc=0x0c06d434u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06d436;
P_0c06d436: /* original 6af6, guest PC 0x0c06d436 */
if(!s->budget--) { s->failed_pc=0x0c06d436u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06d438;
P_0c06d438: /* original 6bf6, guest PC 0x0c06d438 */
if(!s->budget--) { s->failed_pc=0x0c06d438u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06d43a;
P_0c06d43a: /* original 6cf6, guest PC 0x0c06d43a */
if(!s->budget--) { s->failed_pc=0x0c06d43au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06d43c;
P_0c06d43c: /* original 6df6, guest PC 0x0c06d43c */
if(!s->budget--) { s->failed_pc=0x0c06d43cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06d43e;
P_0c06d43e: /* original 000b, guest PC 0x0c06d43e */
if(!s->budget--) { s->failed_pc=0x0c06d43eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06d440: /* original 6ef6, guest PC 0x0c06d440 */
if(!s->budget--) { s->failed_pc=0x0c06d440u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06d442u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06d442u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
