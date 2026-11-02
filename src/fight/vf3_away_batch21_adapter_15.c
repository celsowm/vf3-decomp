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
int vf3_away_batch21_adapter_15(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0aada0u: goto P_0c0aada0;
case 0x0c0aada2u: goto P_0c0aada2;
case 0x0c0aada4u: goto P_0c0aada4;
case 0x0c0aada6u: goto P_0c0aada6;
case 0x0c0aada8u: goto P_0c0aada8;
case 0x0c0aadaau: goto P_0c0aadaa;
case 0x0c0aadacu: goto P_0c0aadac;
case 0x0c0aadaeu: goto P_0c0aadae;
case 0x0c0aadb0u: goto P_0c0aadb0;
case 0x0c0aadb2u: goto P_0c0aadb2;
case 0x0c0aadb4u: goto P_0c0aadb4;
case 0x0c0aadb6u: goto P_0c0aadb6;
case 0x0c0aadb8u: goto P_0c0aadb8;
case 0x0c0aadbau: goto P_0c0aadba;
case 0x0c0aadbcu: goto P_0c0aadbc;
case 0x0c0aadbeu: goto P_0c0aadbe;
case 0x0c0aadc0u: goto P_0c0aadc0;
case 0x0c0aadc2u: goto P_0c0aadc2;
case 0x0c0aadc4u: goto P_0c0aadc4;
case 0x0c0aadc6u: goto P_0c0aadc6;
case 0x0c0aadc8u: goto P_0c0aadc8;
case 0x0c0aadcau: goto P_0c0aadca;
case 0x0c0aadccu: goto P_0c0aadcc;
case 0x0c0aadceu: goto P_0c0aadce;
case 0x0c0aadd0u: goto P_0c0aadd0;
case 0x0c0aadd2u: goto P_0c0aadd2;
case 0x0c0aadd4u: goto P_0c0aadd4;
case 0x0c0aadd6u: goto P_0c0aadd6;
case 0x0c0aadd8u: goto P_0c0aadd8;
case 0x0c0aaddau: goto P_0c0aadda;
case 0x0c0aaddcu: goto P_0c0aaddc;
case 0x0c0aaddeu: goto P_0c0aadde;
case 0x0c0aade0u: goto P_0c0aade0;
case 0x0c0aade2u: goto P_0c0aade2;
case 0x0c0aade4u: goto P_0c0aade4;
case 0x0c0aade6u: goto P_0c0aade6;
case 0x0c0aade8u: goto P_0c0aade8;
case 0x0c0aadeau: goto P_0c0aadea;
case 0x0c0aadecu: goto P_0c0aadec;
case 0x0c0aadeeu: goto P_0c0aadee;
case 0x0c0aadf0u: goto P_0c0aadf0;
case 0x0c0aadf2u: goto P_0c0aadf2;
case 0x0c0aadf4u: goto P_0c0aadf4;
case 0x0c0aadf6u: goto P_0c0aadf6;
case 0x0c0aadf8u: goto P_0c0aadf8;
case 0x0c0aadfau: goto P_0c0aadfa;
case 0x0c0aadfcu: goto P_0c0aadfc;
case 0x0c0aadfeu: goto P_0c0aadfe;
case 0x0c0aae00u: goto P_0c0aae00;
case 0x0c0aae02u: goto P_0c0aae02;
case 0x0c0aae04u: goto P_0c0aae04;
case 0x0c0aae06u: goto P_0c0aae06;
case 0x0c0aae08u: goto P_0c0aae08;
case 0x0c0aae0au: goto P_0c0aae0a;
case 0x0c0aae0cu: goto P_0c0aae0c;
case 0x0c0aae0eu: goto P_0c0aae0e;
case 0x0c0aae10u: goto P_0c0aae10;
case 0x0c0aae12u: goto P_0c0aae12;
case 0x0c0aae14u: goto P_0c0aae14;
case 0x0c0aae16u: goto P_0c0aae16;
case 0x0c0aae18u: goto P_0c0aae18;
case 0x0c0aae1au: goto P_0c0aae1a;
case 0x0c0aae1cu: goto P_0c0aae1c;
case 0x0c0aae1eu: goto P_0c0aae1e;
case 0x0c0aae20u: goto P_0c0aae20;
case 0x0c0aae22u: goto P_0c0aae22;
case 0x0c0aae24u: goto P_0c0aae24;
case 0x0c0aae26u: goto P_0c0aae26;
case 0x0c0aae28u: goto P_0c0aae28;
case 0x0c0aae2au: goto P_0c0aae2a;
case 0x0c0aae2cu: goto P_0c0aae2c;
case 0x0c0aae2eu: goto P_0c0aae2e;
case 0x0c0aae30u: goto P_0c0aae30;
case 0x0c0aae32u: goto P_0c0aae32;
case 0x0c0aae34u: goto P_0c0aae34;
case 0x0c0aae36u: goto P_0c0aae36;
case 0x0c0aae38u: goto P_0c0aae38;
case 0x0c0aae3au: goto P_0c0aae3a;
case 0x0c0aae74u: goto P_0c0aae74;
case 0x0c0aae76u: goto P_0c0aae76;
case 0x0c0aae78u: goto P_0c0aae78;
case 0x0c0aae7au: goto P_0c0aae7a;
case 0x0c0aae7cu: goto P_0c0aae7c;
case 0x0c0aae7eu: goto P_0c0aae7e;
case 0x0c0aae80u: goto P_0c0aae80;
case 0x0c0aae82u: goto P_0c0aae82;
case 0x0c0aae84u: goto P_0c0aae84;
case 0x0c0aae86u: goto P_0c0aae86;
case 0x0c0aae88u: goto P_0c0aae88;
case 0x0c0aae8au: goto P_0c0aae8a;
case 0x0c0aae8cu: goto P_0c0aae8c;
case 0x0c0aae8eu: goto P_0c0aae8e;
case 0x0c0aae90u: goto P_0c0aae90;
case 0x0c0aae92u: goto P_0c0aae92;
case 0x0c0aae94u: goto P_0c0aae94;
case 0x0c0aae96u: goto P_0c0aae96;
case 0x0c0aae98u: goto P_0c0aae98;
case 0x0c0aae9au: goto P_0c0aae9a;
case 0x0c0aae9cu: goto P_0c0aae9c;
case 0x0c0aae9eu: goto P_0c0aae9e;
case 0x0c0aaea0u: goto P_0c0aaea0;
case 0x0c0aaea2u: goto P_0c0aaea2;
case 0x0c0aaea4u: goto P_0c0aaea4;
case 0x0c0aaea6u: goto P_0c0aaea6;
case 0x0c0aaea8u: goto P_0c0aaea8;
case 0x0c0aaeaau: goto P_0c0aaeaa;
case 0x0c0aaeacu: goto P_0c0aaeac;
case 0x0c0aaeaeu: goto P_0c0aaeae;
case 0x0c0aaeb0u: goto P_0c0aaeb0;
case 0x0c0aaeb2u: goto P_0c0aaeb2;
case 0x0c0aaeb4u: goto P_0c0aaeb4;
case 0x0c0aaeb6u: goto P_0c0aaeb6;
case 0x0c0aaeb8u: goto P_0c0aaeb8;
case 0x0c0aaf98u: goto P_0c0aaf98;
case 0x0c0aaf9au: goto P_0c0aaf9a;
case 0x0c0aaf9cu: goto P_0c0aaf9c;
case 0x0c0aaf9eu: goto P_0c0aaf9e;
case 0x0c0aafa0u: goto P_0c0aafa0;
case 0x0c0aafa2u: goto P_0c0aafa2;
case 0x0c0aafa4u: goto P_0c0aafa4;
case 0x0c0aafa6u: goto P_0c0aafa6;
case 0x0c0aafa8u: goto P_0c0aafa8;
case 0x0c0aafaau: goto P_0c0aafaa;
case 0x0c0aafacu: goto P_0c0aafac;
case 0x0c0aafaeu: goto P_0c0aafae;
case 0x0c0aafb0u: goto P_0c0aafb0;
case 0x0c0aafb2u: goto P_0c0aafb2;
case 0x0c0aafb4u: goto P_0c0aafb4;
case 0x0c0aafb6u: goto P_0c0aafb6;
case 0x0c0aafb8u: goto P_0c0aafb8;
case 0x0c0aafbau: goto P_0c0aafba;
case 0x0c0aafbcu: goto P_0c0aafbc;
case 0x0c0aafbeu: goto P_0c0aafbe;
case 0x0c0aafc0u: goto P_0c0aafc0;
case 0x0c0aafc2u: goto P_0c0aafc2;
case 0x0c0aafc4u: goto P_0c0aafc4;
case 0x0c0aafc6u: goto P_0c0aafc6;
case 0x0c0aafc8u: goto P_0c0aafc8;
case 0x0c0aafcau: goto P_0c0aafca;
case 0x0c0aafccu: goto P_0c0aafcc;
case 0x0c0aafceu: goto P_0c0aafce;
case 0x0c0aafd0u: goto P_0c0aafd0;
case 0x0c0aafd2u: goto P_0c0aafd2;
case 0x0c0aafd4u: goto P_0c0aafd4;
case 0x0c0aafd6u: goto P_0c0aafd6;
case 0x0c0aafd8u: goto P_0c0aafd8;
case 0x0c0aafdau: goto P_0c0aafda;
case 0x0c0aafdcu: goto P_0c0aafdc;
case 0x0c0aafdeu: goto P_0c0aafde;
case 0x0c0aafe0u: goto P_0c0aafe0;
case 0x0c0aafe2u: goto P_0c0aafe2;
case 0x0c0aafe4u: goto P_0c0aafe4;
case 0x0c0aafe6u: goto P_0c0aafe6;
case 0x0c0aafe8u: goto P_0c0aafe8;
case 0x0c0aafeau: goto P_0c0aafea;
case 0x0c0aafecu: goto P_0c0aafec;
case 0x0c0aafeeu: goto P_0c0aafee;
case 0x0c0aaff0u: goto P_0c0aaff0;
case 0x0c0aaff2u: goto P_0c0aaff2;
case 0x0c0aaff4u: goto P_0c0aaff4;
case 0x0c0aaff6u: goto P_0c0aaff6;
case 0x0c0aaff8u: goto P_0c0aaff8;
case 0x0c0aaffau: goto P_0c0aaffa;
case 0x0c0aaffcu: goto P_0c0aaffc;
case 0x0c0aaffeu: goto P_0c0aaffe;
case 0x0c0ab000u: goto P_0c0ab000;
case 0x0c0ab002u: goto P_0c0ab002;
case 0x0c0ab004u: goto P_0c0ab004;
case 0x0c0ab006u: goto P_0c0ab006;
case 0x0c0ab008u: goto P_0c0ab008;
case 0x0c0ab00au: goto P_0c0ab00a;
case 0x0c0ab00cu: goto P_0c0ab00c;
case 0x0c0ab00eu: goto P_0c0ab00e;
case 0x0c0ab010u: goto P_0c0ab010;
case 0x0c0ab012u: goto P_0c0ab012;
case 0x0c0ab014u: goto P_0c0ab014;
case 0x0c0ab016u: goto P_0c0ab016;
case 0x0c0ab018u: goto P_0c0ab018;
case 0x0c0ab01au: goto P_0c0ab01a;
case 0x0c0ab01cu: goto P_0c0ab01c;
case 0x0c0ab01eu: goto P_0c0ab01e;
case 0x0c0ab020u: goto P_0c0ab020;
case 0x0c0ab022u: goto P_0c0ab022;
case 0x0c0ab024u: goto P_0c0ab024;
case 0x0c0ab026u: goto P_0c0ab026;
case 0x0c0ab028u: goto P_0c0ab028;
case 0x0c0ab02au: goto P_0c0ab02a;
case 0x0c0ab02cu: goto P_0c0ab02c;
case 0x0c0ab02eu: goto P_0c0ab02e;
case 0x0c0ab030u: goto P_0c0ab030;
case 0x0c0ab032u: goto P_0c0ab032;
case 0x0c0ab034u: goto P_0c0ab034;
case 0x0c0ab036u: goto P_0c0ab036;
case 0x0c0ab038u: goto P_0c0ab038;
case 0x0c0ab03au: goto P_0c0ab03a;
case 0x0c0ab03cu: goto P_0c0ab03c;
case 0x0c0ab03eu: goto P_0c0ab03e;
case 0x0c0ab040u: goto P_0c0ab040;
case 0x0c0ab042u: goto P_0c0ab042;
case 0x0c0ab044u: goto P_0c0ab044;
case 0x0c0ab046u: goto P_0c0ab046;
case 0x0c0ab048u: goto P_0c0ab048;
case 0x0c0ab04au: goto P_0c0ab04a;
case 0x0c0ab04cu: goto P_0c0ab04c;
case 0x0c0ab04eu: goto P_0c0ab04e;
case 0x0c0ab050u: goto P_0c0ab050;
case 0x0c0ab052u: goto P_0c0ab052;
case 0x0c0ab054u: goto P_0c0ab054;
case 0x0c0ab056u: goto P_0c0ab056;
case 0x0c0ab058u: goto P_0c0ab058;
case 0x0c0ab05au: goto P_0c0ab05a;
case 0x0c0ab05cu: goto P_0c0ab05c;
case 0x0c0ab05eu: goto P_0c0ab05e;
case 0x0c0ab060u: goto P_0c0ab060;
case 0x0c0ab062u: goto P_0c0ab062;
case 0x0c0ab064u: goto P_0c0ab064;
case 0x0c0ab066u: goto P_0c0ab066;
case 0x0c0ab068u: goto P_0c0ab068;
case 0x0c0ab06au: goto P_0c0ab06a;
case 0x0c0ab06cu: goto P_0c0ab06c;
case 0x0c0ab06eu: goto P_0c0ab06e;
case 0x0c0ab070u: goto P_0c0ab070;
case 0x0c0ab072u: goto P_0c0ab072;
case 0x0c0ab074u: goto P_0c0ab074;
case 0x0c0ab076u: goto P_0c0ab076;
case 0x0c0ab078u: goto P_0c0ab078;
case 0x0c0ab07au: goto P_0c0ab07a;
case 0x0c0ab07cu: goto P_0c0ab07c;
case 0x0c0ab07eu: goto P_0c0ab07e;
case 0x0c0ab080u: goto P_0c0ab080;
case 0x0c0ab082u: goto P_0c0ab082;
case 0x0c0ab084u: goto P_0c0ab084;
case 0x0c0ab086u: goto P_0c0ab086;
case 0x0c0ab088u: goto P_0c0ab088;
case 0x0c0ab08au: goto P_0c0ab08a;
case 0x0c0ab08cu: goto P_0c0ab08c;
case 0x0c0ab08eu: goto P_0c0ab08e;
case 0x0c0ab090u: goto P_0c0ab090;
case 0x0c0ab092u: goto P_0c0ab092;
case 0x0c0ab094u: goto P_0c0ab094;
case 0x0c0ab096u: goto P_0c0ab096;
case 0x0c0ab098u: goto P_0c0ab098;
case 0x0c0ab09au: goto P_0c0ab09a;
case 0x0c0ab09cu: goto P_0c0ab09c;
case 0x0c0ab09eu: goto P_0c0ab09e;
case 0x0c0ab0a0u: goto P_0c0ab0a0;
case 0x0c0ab0a2u: goto P_0c0ab0a2;
case 0x0c0ab0a4u: goto P_0c0ab0a4;
case 0x0c0ab0a6u: goto P_0c0ab0a6;
case 0x0c0ab0a8u: goto P_0c0ab0a8;
case 0x0c0ab0aau: goto P_0c0ab0aa;
case 0x0c0ab0acu: goto P_0c0ab0ac;
case 0x0c0ab0aeu: goto P_0c0ab0ae;
case 0x0c0ab0b0u: goto P_0c0ab0b0;
case 0x0c0ab0b2u: goto P_0c0ab0b2;
case 0x0c0ab0b4u: goto P_0c0ab0b4;
case 0x0c0ab0b6u: goto P_0c0ab0b6;
case 0x0c0ab0b8u: goto P_0c0ab0b8;
case 0x0c0ab0bau: goto P_0c0ab0ba;
case 0x0c0ab0bcu: goto P_0c0ab0bc;
case 0x0c0ab0e4u: goto P_0c0ab0e4;
case 0x0c0ab0e6u: goto P_0c0ab0e6;
case 0x0c0ab0e8u: goto P_0c0ab0e8;
case 0x0c0ab0eau: goto P_0c0ab0ea;
case 0x0c0ab0ecu: goto P_0c0ab0ec;
case 0x0c0ab0eeu: goto P_0c0ab0ee;
case 0x0c0ab0f0u: goto P_0c0ab0f0;
case 0x0c0ab0f2u: goto P_0c0ab0f2;
case 0x0c0ab0f4u: goto P_0c0ab0f4;
case 0x0c0ab0f6u: goto P_0c0ab0f6;
case 0x0c0ab0f8u: goto P_0c0ab0f8;
case 0x0c0ab0fau: goto P_0c0ab0fa;
case 0x0c0ab0fcu: goto P_0c0ab0fc;
case 0x0c0ab0feu: goto P_0c0ab0fe;
case 0x0c0ab100u: goto P_0c0ab100;
case 0x0c0ab102u: goto P_0c0ab102;
case 0x0c0ab104u: goto P_0c0ab104;
case 0x0c0ab106u: goto P_0c0ab106;
case 0x0c0ab108u: goto P_0c0ab108;
case 0x0c0ab10au: goto P_0c0ab10a;
case 0x0c0ab10cu: goto P_0c0ab10c;
case 0x0c0ab10eu: goto P_0c0ab10e;
case 0x0c0ab110u: goto P_0c0ab110;
case 0x0c0ab112u: goto P_0c0ab112;
case 0x0c0ab114u: goto P_0c0ab114;
case 0x0c0ab116u: goto P_0c0ab116;
case 0x0c0ab118u: goto P_0c0ab118;
case 0x0c0ab11au: goto P_0c0ab11a;
case 0x0c0ab11cu: goto P_0c0ab11c;
case 0x0c0ab11eu: goto P_0c0ab11e;
case 0x0c0ab120u: goto P_0c0ab120;
case 0x0c0ab122u: goto P_0c0ab122;
case 0x0c0ab124u: goto P_0c0ab124;
case 0x0c0ab126u: goto P_0c0ab126;
case 0x0c0ab128u: goto P_0c0ab128;
case 0x0c0ab12au: goto P_0c0ab12a;
case 0x0c0ab12cu: goto P_0c0ab12c;
case 0x0c0ab12eu: goto P_0c0ab12e;
case 0x0c0ab130u: goto P_0c0ab130;
case 0x0c0ab132u: goto P_0c0ab132;
case 0x0c0ab134u: goto P_0c0ab134;
case 0x0c0ab136u: goto P_0c0ab136;
case 0x0c0ab138u: goto P_0c0ab138;
case 0x0c0ab13au: goto P_0c0ab13a;
case 0x0c0ab13cu: goto P_0c0ab13c;
case 0x0c0ab13eu: goto P_0c0ab13e;
case 0x0c0ab140u: goto P_0c0ab140;
case 0x0c0ab142u: goto P_0c0ab142;
case 0x0c0ab144u: goto P_0c0ab144;
case 0x0c0ab146u: goto P_0c0ab146;
case 0x0c0ab148u: goto P_0c0ab148;
case 0x0c0ab14au: goto P_0c0ab14a;
case 0x0c0ab14cu: goto P_0c0ab14c;
case 0x0c0ab14eu: goto P_0c0ab14e;
case 0x0c0ab150u: goto P_0c0ab150;
case 0x0c0ab152u: goto P_0c0ab152;
case 0x0c0ab154u: goto P_0c0ab154;
case 0x0c0ab156u: goto P_0c0ab156;
case 0x0c0ab158u: goto P_0c0ab158;
case 0x0c0ab15au: goto P_0c0ab15a;
case 0x0c0ab15cu: goto P_0c0ab15c;
case 0x0c0ab15eu: goto P_0c0ab15e;
case 0x0c0ab160u: goto P_0c0ab160;
case 0x0c0ab162u: goto P_0c0ab162;
case 0x0c0ab164u: goto P_0c0ab164;
case 0x0c0ab166u: goto P_0c0ab166;
case 0x0c0ab168u: goto P_0c0ab168;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0aada0: /* original 2fe6, guest PC 0x0c0aada0 */
if(!s->budget--) { s->failed_pc=0x0c0aada0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aada2;
P_0c0aada2: /* original e058, guest PC 0x0c0aada2 */
if(!s->budget--) { s->failed_pc=0x0c0aada2u; return 0; }
r[0]=0x00000058u;
goto P_0c0aada4;
P_0c0aada4: /* original 2fd6, guest PC 0x0c0aada4 */
if(!s->budget--) { s->failed_pc=0x0c0aada4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aada6;
P_0c0aada6: /* original 6e43, guest PC 0x0c0aada6 */
if(!s->budget--) { s->failed_pc=0x0c0aada6u; return 0; }
r[14]=r[4];
goto P_0c0aada8;
P_0c0aada8: /* original 2fc6, guest PC 0x0c0aada8 */
if(!s->budget--) { s->failed_pc=0x0c0aada8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aadaa;
P_0c0aadaa: /* original 0dee, guest PC 0x0c0aadaa */
if(!s->budget--) { s->failed_pc=0x0c0aadaau; return 0; }
r[13]=read(ram,r[14]+r[0],4);
goto P_0c0aadac;
P_0c0aadac: /* original e048, guest PC 0x0c0aadac */
if(!s->budget--) { s->failed_pc=0x0c0aadacu; return 0; }
r[0]=0x00000048u;
goto P_0c0aadae;
P_0c0aadae: /* original 4f22, guest PC 0x0c0aadae */
if(!s->budget--) { s->failed_pc=0x0c0aadaeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aadb0;
P_0c0aadb0: /* original 03ee, guest PC 0x0c0aadb0 */
if(!s->budget--) { s->failed_pc=0x0c0aadb0u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0aadb2;
P_0c0aadb2: /* original 7ffc, guest PC 0x0c0aadb2 */
if(!s->budget--) { s->failed_pc=0x0c0aadb2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0aadb4;
P_0c0aadb4: /* original 2f32, guest PC 0x0c0aadb4 */
if(!s->budget--) { s->failed_pc=0x0c0aadb4u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0aadb6;
P_0c0aadb6: /* original 9044, guest PC 0x0c0aadb6 */
if(!s->budget--) { s->failed_pc=0x0c0aadb6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aae42u,2);
goto P_0c0aadb8;
P_0c0aadb8: /* original d327, guest PC 0x0c0aadb8 */
if(!s->budget--) { s->failed_pc=0x0c0aadb8u; return 0; }
r[3]=read(ram,0x0c0aae58u,4);
goto P_0c0aadba;
P_0c0aadba: /* original 025e, guest PC 0x0c0aadba */
if(!s->budget--) { s->failed_pc=0x0c0aadbau; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c0aadbc;
P_0c0aadbc: /* original 2238, guest PC 0x0c0aadbc */
if(!s->budget--) { s->failed_pc=0x0c0aadbcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aadbe;
P_0c0aadbe: /* original 8d0b, guest PC 0x0c0aadbe */
if(!s->budget--) { s->failed_pc=0x0c0aadbeu; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[14],4);
r[12]=tmp;
if(cond) { goto P_0c0aadd8; }
goto P_0c0aadc2;
P_0c0aadc0: /* original 6ce2, guest PC 0x0c0aadc0 */
if(!s->budget--) { s->failed_pc=0x0c0aadc0u; return 0; }
tmp=read(ram,r[14],4);
r[12]=tmp;
goto P_0c0aadc2;
P_0c0aadc2: /* original d226, guest PC 0x0c0aadc2 */
if(!s->budget--) { s->failed_pc=0x0c0aadc2u; return 0; }
r[2]=read(ram,0x0c0aae5cu,4);
goto P_0c0aadc4;
P_0c0aadc4: /* original 420b, guest PC 0x0c0aadc4 */
if(!s->budget--) { s->failed_pc=0x0c0aadc4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0aadc8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aadc8u) { target=s->pc; goto dispatch; }
goto P_0c0aadc8;
P_0c0aadc6: /* original 64e3, guest PC 0x0c0aadc6 */
if(!s->budget--) { s->failed_pc=0x0c0aadc6u; return 0; }
r[4]=r[14];
goto P_0c0aadc8;
P_0c0aadc8: /* original 6403, guest PC 0x0c0aadc8 */
if(!s->budget--) { s->failed_pc=0x0c0aadc8u; return 0; }
r[4]=r[0];
goto P_0c0aadca;
P_0c0aadca: /* original e048, guest PC 0x0c0aadca */
if(!s->budget--) { s->failed_pc=0x0c0aadcau; return 0; }
r[0]=0x00000048u;
goto P_0c0aadcc;
P_0c0aadcc: /* original 02ee, guest PC 0x0c0aadcc */
if(!s->budget--) { s->failed_pc=0x0c0aadccu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0aadce;
P_0c0aadce: /* original 2448, guest PC 0x0c0aadce */
if(!s->budget--) { s->failed_pc=0x0c0aadceu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0aadd0;
P_0c0aadd0: /* original d323, guest PC 0x0c0aadd0 */
if(!s->budget--) { s->failed_pc=0x0c0aadd0u; return 0; }
r[3]=read(ram,0x0c0aae60u,4);
goto P_0c0aadd2;
P_0c0aadd2: /* original 2239, guest PC 0x0c0aadd2 */
if(!s->budget--) { s->failed_pc=0x0c0aadd2u; return 0; }
r[2]&=r[3];
goto P_0c0aadd4;
P_0c0aadd4: /* original 8f6b, guest PC 0x0c0aadd4 */
if(!s->budget--) { s->failed_pc=0x0c0aadd4u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[2],4);
if(!cond) { goto P_0c0aaeae; }
goto P_0c0aadd8;
P_0c0aadd6: /* original 0e26, guest PC 0x0c0aadd6 */
if(!s->budget--) { s->failed_pc=0x0c0aadd6u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0aadd8;
P_0c0aadd8: /* original 61f2, guest PC 0x0c0aadd8 */
if(!s->budget--) { s->failed_pc=0x0c0aadd8u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0aadda;
P_0c0aadda: /* original d322, guest PC 0x0c0aadda */
if(!s->budget--) { s->failed_pc=0x0c0aaddau; return 0; }
r[3]=read(ram,0x0c0aae64u,4);
goto P_0c0aaddc;
P_0c0aaddc: /* original 2138, guest PC 0x0c0aaddc */
if(!s->budget--) { s->failed_pc=0x0c0aaddcu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0aadde;
P_0c0aadde: /* original 8b49, guest PC 0x0c0aadde */
if(!s->budget--) { s->failed_pc=0x0c0aaddeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aae74; }
goto P_0c0aade0;
P_0c0aade0: /* original 9330, guest PC 0x0c0aade0 */
if(!s->budget--) { s->failed_pc=0x0c0aade0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aae44u,2);
goto P_0c0aade2;
P_0c0aade2: /* original 85dc, guest PC 0x0c0aade2 */
if(!s->budget--) { s->failed_pc=0x0c0aade2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+24,2);
goto P_0c0aade4;
P_0c0aade4: /* original 2c38, guest PC 0x0c0aade4 */
if(!s->budget--) { s->failed_pc=0x0c0aade4u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[3])==0)!=0);
goto P_0c0aade6;
P_0c0aade6: /* original 8f5a, guest PC 0x0c0aade6 */
if(!s->budget--) { s->failed_pc=0x0c0aade6u; return 0; }
cond=r[17]&1u;
r[5]=r[0]&65535u;
if(!cond) { goto P_0c0aae9e; }
goto P_0c0aadea;
P_0c0aade8: /* original 650d, guest PC 0x0c0aade8 */
if(!s->budget--) { s->failed_pc=0x0c0aade8u; return 0; }
r[5]=r[0]&65535u;
goto P_0c0aadea;
P_0c0aadea: /* original 64d3, guest PC 0x0c0aadea */
if(!s->budget--) { s->failed_pc=0x0c0aadeau; return 0; }
r[4]=r[13];
goto P_0c0aadec;
P_0c0aadec: /* original e03c, guest PC 0x0c0aadec */
if(!s->budget--) { s->failed_pc=0x0c0aadecu; return 0; }
r[0]=0x0000003cu;
goto P_0c0aadee;
P_0c0aadee: /* original 7420, guest PC 0x0c0aadee */
if(!s->budget--) { s->failed_pc=0x0c0aadeeu; return 0; }
r[4]+=0x00000020u;
goto P_0c0aadf0;
P_0c0aadf0: /* original 03ed, guest PC 0x0c0aadf0 */
if(!s->budget--) { s->failed_pc=0x0c0aadf0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aadf2;
P_0c0aadf2: /* original 6441, guest PC 0x0c0aadf2 */
if(!s->budget--) { s->failed_pc=0x0c0aadf2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[4]=tmp;
goto P_0c0aadf4;
P_0c0aadf4: /* original 633d, guest PC 0x0c0aadf4 */
if(!s->budget--) { s->failed_pc=0x0c0aadf4u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0aadf6;
P_0c0aadf6: /* original 644d, guest PC 0x0c0aadf6 */
if(!s->budget--) { s->failed_pc=0x0c0aadf6u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0aadf8;
P_0c0aadf8: /* original 3340, guest PC 0x0c0aadf8 */
if(!s->budget--) { s->failed_pc=0x0c0aadf8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[4])!=0);
goto P_0c0aadfa;
P_0c0aadfa: /* original 8958, guest PC 0x0c0aadfa */
if(!s->budget--) { s->failed_pc=0x0c0aadfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aaeae; }
goto P_0c0aadfc;
P_0c0aadfc: /* original 9023, guest PC 0x0c0aadfc */
if(!s->budget--) { s->failed_pc=0x0c0aadfcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aae46u,2);
goto P_0c0aadfe;
P_0c0aadfe: /* original 9323, guest PC 0x0c0aadfe */
if(!s->budget--) { s->failed_pc=0x0c0aadfeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aae48u,2);
goto P_0c0aae00;
P_0c0aae00: /* original 04ed, guest PC 0x0c0aae00 */
if(!s->budget--) { s->failed_pc=0x0c0aae00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aae02;
P_0c0aae02: /* original 644d, guest PC 0x0c0aae02 */
if(!s->budget--) { s->failed_pc=0x0c0aae02u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0aae04;
P_0c0aae04: /* original 2438, guest PC 0x0c0aae04 */
if(!s->budget--) { s->failed_pc=0x0c0aae04u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0aae06;
P_0c0aae06: /* original 8912, guest PC 0x0c0aae06 */
if(!s->budget--) { s->failed_pc=0x0c0aae06u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aae2e; }
goto P_0c0aae08;
P_0c0aae08: /* original 901f, guest PC 0x0c0aae08 */
if(!s->budget--) { s->failed_pc=0x0c0aae08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aae4au,2);
goto P_0c0aae0a;
P_0c0aae0a: /* original 65d3, guest PC 0x0c0aae0a */
if(!s->budget--) { s->failed_pc=0x0c0aae0au; return 0; }
r[5]=r[13];
goto P_0c0aae0c;
P_0c0aae0c: /* original d216, guest PC 0x0c0aae0c */
if(!s->budget--) { s->failed_pc=0x0c0aae0cu; return 0; }
r[2]=read(ram,0x0c0aae68u,4);
goto P_0c0aae0e;
P_0c0aae0e: /* original 7520, guest PC 0x0c0aae0e */
if(!s->budget--) { s->failed_pc=0x0c0aae0eu; return 0; }
r[5]+=0x00000020u;
goto P_0c0aae10;
P_0c0aae10: /* original 01ee, guest PC 0x0c0aae10 */
if(!s->budget--) { s->failed_pc=0x0c0aae10u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0aae12;
P_0c0aae12: /* original 6551, guest PC 0x0c0aae12 */
if(!s->budget--) { s->failed_pc=0x0c0aae12u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0aae14;
P_0c0aae14: /* original 2128, guest PC 0x0c0aae14 */
if(!s->budget--) { s->failed_pc=0x0c0aae14u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0aae16;
P_0c0aae16: /* original 8d02, guest PC 0x0c0aae16 */
if(!s->budget--) { s->failed_pc=0x0c0aae16u; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(cond) { goto P_0c0aae1e; }
goto P_0c0aae1a;
P_0c0aae18: /* original 655d, guest PC 0x0c0aae18 */
if(!s->budget--) { s->failed_pc=0x0c0aae18u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0aae1a;
P_0c0aae1a: /* original 85dc, guest PC 0x0c0aae1a */
if(!s->budget--) { s->failed_pc=0x0c0aae1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+24,2);
goto P_0c0aae1c;
P_0c0aae1c: /* original 650d, guest PC 0x0c0aae1c */
if(!s->budget--) { s->failed_pc=0x0c0aae1cu; return 0; }
r[5]=r[0]&65535u;
goto P_0c0aae1e;
P_0c0aae1e: /* original 7f04, guest PC 0x0c0aae1e */
if(!s->budget--) { s->failed_pc=0x0c0aae1eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aae20;
P_0c0aae20: /* original d312, guest PC 0x0c0aae20 */
if(!s->budget--) { s->failed_pc=0x0c0aae20u; return 0; }
r[3]=read(ram,0x0c0aae6cu,4);
goto P_0c0aae22;
P_0c0aae22: /* original 4f26, guest PC 0x0c0aae22 */
if(!s->budget--) { s->failed_pc=0x0c0aae22u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aae24;
P_0c0aae24: /* original 64e3, guest PC 0x0c0aae24 */
if(!s->budget--) { s->failed_pc=0x0c0aae24u; return 0; }
r[4]=r[14];
goto P_0c0aae26;
P_0c0aae26: /* original 6cf6, guest PC 0x0c0aae26 */
if(!s->budget--) { s->failed_pc=0x0c0aae26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0aae28;
P_0c0aae28: /* original 6df6, guest PC 0x0c0aae28 */
if(!s->budget--) { s->failed_pc=0x0c0aae28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aae2a;
P_0c0aae2a: /* original 432b, guest PC 0x0c0aae2a */
if(!s->budget--) { s->failed_pc=0x0c0aae2au; return 0; }
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
P_0c0aae2c: /* original 6ef6, guest PC 0x0c0aae2c */
if(!s->budget--) { s->failed_pc=0x0c0aae2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aae2e;
P_0c0aae2e: /* original 900c, guest PC 0x0c0aae2e */
if(!s->budget--) { s->failed_pc=0x0c0aae2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aae4au,2);
goto P_0c0aae30;
P_0c0aae30: /* original d30f, guest PC 0x0c0aae30 */
if(!s->budget--) { s->failed_pc=0x0c0aae30u; return 0; }
r[3]=read(ram,0x0c0aae70u,4);
goto P_0c0aae32;
P_0c0aae32: /* original 02ee, guest PC 0x0c0aae32 */
if(!s->budget--) { s->failed_pc=0x0c0aae32u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0aae34;
P_0c0aae34: /* original 2238, guest PC 0x0c0aae34 */
if(!s->budget--) { s->failed_pc=0x0c0aae34u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aae36;
P_0c0aae36: /* original 8b3a, guest PC 0x0c0aae36 */
if(!s->budget--) { s->failed_pc=0x0c0aae36u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aaeae; }
goto P_0c0aae38;
P_0c0aae38: /* original a031, guest PC 0x0c0aae38 */
if(!s->budget--) { s->failed_pc=0x0c0aae38u; return 0; }
goto P_0c0aae9e;
P_0c0aae3a: /* original 0009, guest PC 0x0c0aae3a */
if(!s->budget--) { s->failed_pc=0x0c0aae3au; return 0; }
if(!vf3_matrix_family(0x0c0aae3cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aae3cu; return 0; } return 1;
P_0c0aae74: /* original 65d3, guest PC 0x0c0aae74 */
if(!s->budget--) { s->failed_pc=0x0c0aae74u; return 0; }
r[5]=r[13];
goto P_0c0aae76;
P_0c0aae76: /* original 907c, guest PC 0x0c0aae76 */
if(!s->budget--) { s->failed_pc=0x0c0aae76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aaf72u,2);
goto P_0c0aae78;
P_0c0aae78: /* original 7520, guest PC 0x0c0aae78 */
if(!s->budget--) { s->failed_pc=0x0c0aae78u; return 0; }
r[5]+=0x00000020u;
goto P_0c0aae7a;
P_0c0aae7a: /* original d340, guest PC 0x0c0aae7a */
if(!s->budget--) { s->failed_pc=0x0c0aae7au; return 0; }
r[3]=read(ram,0x0c0aaf7cu,4);
goto P_0c0aae7c;
P_0c0aae7c: /* original 6551, guest PC 0x0c0aae7c */
if(!s->budget--) { s->failed_pc=0x0c0aae7cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0aae7e;
P_0c0aae7e: /* original 04ed, guest PC 0x0c0aae7e */
if(!s->budget--) { s->failed_pc=0x0c0aae7eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aae80;
P_0c0aae80: /* original 2c38, guest PC 0x0c0aae80 */
if(!s->budget--) { s->failed_pc=0x0c0aae80u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[3])==0)!=0);
goto P_0c0aae82;
P_0c0aae82: /* original 655d, guest PC 0x0c0aae82 */
if(!s->budget--) { s->failed_pc=0x0c0aae82u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0aae84;
P_0c0aae84: /* original 8f0b, guest PC 0x0c0aae84 */
if(!s->budget--) { s->failed_pc=0x0c0aae84u; return 0; }
cond=r[17]&1u;
r[4]=r[4]&65535u;
if(!cond) { goto P_0c0aae9e; }
goto P_0c0aae88;
P_0c0aae86: /* original 644d, guest PC 0x0c0aae86 */
if(!s->budget--) { s->failed_pc=0x0c0aae86u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0aae88;
P_0c0aae88: /* original 9174, guest PC 0x0c0aae88 */
if(!s->budget--) { s->failed_pc=0x0c0aae88u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aaf74u,2);
goto P_0c0aae8a;
P_0c0aae8a: /* original 2418, guest PC 0x0c0aae8a */
if(!s->budget--) { s->failed_pc=0x0c0aae8au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[1])==0)!=0);
goto P_0c0aae8c;
P_0c0aae8c: /* original 8b07, guest PC 0x0c0aae8c */
if(!s->budget--) { s->failed_pc=0x0c0aae8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aae9e; }
goto P_0c0aae8e;
P_0c0aae8e: /* original 7f04, guest PC 0x0c0aae8e */
if(!s->budget--) { s->failed_pc=0x0c0aae8eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aae90;
P_0c0aae90: /* original d23b, guest PC 0x0c0aae90 */
if(!s->budget--) { s->failed_pc=0x0c0aae90u; return 0; }
r[2]=read(ram,0x0c0aaf80u,4);
goto P_0c0aae92;
P_0c0aae92: /* original 4f26, guest PC 0x0c0aae92 */
if(!s->budget--) { s->failed_pc=0x0c0aae92u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aae94;
P_0c0aae94: /* original 64e3, guest PC 0x0c0aae94 */
if(!s->budget--) { s->failed_pc=0x0c0aae94u; return 0; }
r[4]=r[14];
goto P_0c0aae96;
P_0c0aae96: /* original 6cf6, guest PC 0x0c0aae96 */
if(!s->budget--) { s->failed_pc=0x0c0aae96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0aae98;
P_0c0aae98: /* original 6df6, guest PC 0x0c0aae98 */
if(!s->budget--) { s->failed_pc=0x0c0aae98u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aae9a;
P_0c0aae9a: /* original 422b, guest PC 0x0c0aae9a */
if(!s->budget--) { s->failed_pc=0x0c0aae9au; return 0; }
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
P_0c0aae9c: /* original 6ef6, guest PC 0x0c0aae9c */
if(!s->budget--) { s->failed_pc=0x0c0aae9cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aae9e;
P_0c0aae9e: /* original 7f04, guest PC 0x0c0aae9e */
if(!s->budget--) { s->failed_pc=0x0c0aae9eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aaea0;
P_0c0aaea0: /* original d338, guest PC 0x0c0aaea0 */
if(!s->budget--) { s->failed_pc=0x0c0aaea0u; return 0; }
r[3]=read(ram,0x0c0aaf84u,4);
goto P_0c0aaea2;
P_0c0aaea2: /* original 4f26, guest PC 0x0c0aaea2 */
if(!s->budget--) { s->failed_pc=0x0c0aaea2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aaea4;
P_0c0aaea4: /* original 64e3, guest PC 0x0c0aaea4 */
if(!s->budget--) { s->failed_pc=0x0c0aaea4u; return 0; }
r[4]=r[14];
goto P_0c0aaea6;
P_0c0aaea6: /* original 6cf6, guest PC 0x0c0aaea6 */
if(!s->budget--) { s->failed_pc=0x0c0aaea6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0aaea8;
P_0c0aaea8: /* original 6df6, guest PC 0x0c0aaea8 */
if(!s->budget--) { s->failed_pc=0x0c0aaea8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aaeaa;
P_0c0aaeaa: /* original 432b, guest PC 0x0c0aaeaa */
if(!s->budget--) { s->failed_pc=0x0c0aaeaau; return 0; }
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
P_0c0aaeac: /* original 6ef6, guest PC 0x0c0aaeac */
if(!s->budget--) { s->failed_pc=0x0c0aaeacu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aaeae;
P_0c0aaeae: /* original 7f04, guest PC 0x0c0aaeae */
if(!s->budget--) { s->failed_pc=0x0c0aaeaeu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aaeb0;
P_0c0aaeb0: /* original 4f26, guest PC 0x0c0aaeb0 */
if(!s->budget--) { s->failed_pc=0x0c0aaeb0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aaeb2;
P_0c0aaeb2: /* original 6cf6, guest PC 0x0c0aaeb2 */
if(!s->budget--) { s->failed_pc=0x0c0aaeb2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0aaeb4;
P_0c0aaeb4: /* original 6df6, guest PC 0x0c0aaeb4 */
if(!s->budget--) { s->failed_pc=0x0c0aaeb4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aaeb6;
P_0c0aaeb6: /* original 000b, guest PC 0x0c0aaeb6 */
if(!s->budget--) { s->failed_pc=0x0c0aaeb6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0aaeb8: /* original 6ef6, guest PC 0x0c0aaeb8 */
if(!s->budget--) { s->failed_pc=0x0c0aaeb8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0aaebau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aaebau; return 0; } return 1;
P_0c0aaf98: /* original 2fe6, guest PC 0x0c0aaf98 */
if(!s->budget--) { s->failed_pc=0x0c0aaf98u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aaf9a;
P_0c0aaf9a: /* original 6e43, guest PC 0x0c0aaf9a */
if(!s->budget--) { s->failed_pc=0x0c0aaf9au; return 0; }
r[14]=r[4];
goto P_0c0aaf9c;
P_0c0aaf9c: /* original 2fd6, guest PC 0x0c0aaf9c */
if(!s->budget--) { s->failed_pc=0x0c0aaf9cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aaf9e;
P_0c0aaf9e: /* original e058, guest PC 0x0c0aaf9e */
if(!s->budget--) { s->failed_pc=0x0c0aaf9eu; return 0; }
r[0]=0x00000058u;
goto P_0c0aafa0;
P_0c0aafa0: /* original 2fc6, guest PC 0x0c0aafa0 */
if(!s->budget--) { s->failed_pc=0x0c0aafa0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aafa2;
P_0c0aafa2: /* original 2fb6, guest PC 0x0c0aafa2 */
if(!s->budget--) { s->failed_pc=0x0c0aafa2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aafa4;
P_0c0aafa4: /* original 6b53, guest PC 0x0c0aafa4 */
if(!s->budget--) { s->failed_pc=0x0c0aafa4u; return 0; }
r[11]=r[5];
goto P_0c0aafa6;
P_0c0aafa6: /* original 2fa6, guest PC 0x0c0aafa6 */
if(!s->budget--) { s->failed_pc=0x0c0aafa6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aafa8;
P_0c0aafa8: /* original 0aee, guest PC 0x0c0aafa8 */
if(!s->budget--) { s->failed_pc=0x0c0aafa8u; return 0; }
r[10]=read(ram,r[14]+r[0],4);
goto P_0c0aafaa;
P_0c0aafaa: /* original 9088, guest PC 0x0c0aafaa */
if(!s->budget--) { s->failed_pc=0x0c0aafaau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab0beu,2);
goto P_0c0aafac;
P_0c0aafac: /* original f39d, guest PC 0x0c0aafac */
if(!s->budget--) { s->failed_pc=0x0c0aafacu; return 0; }
fr[3]=0x3f800000u;
goto P_0c0aafae;
P_0c0aafae: /* original f2e6, guest PC 0x0c0aafae */
if(!s->budget--) { s->failed_pc=0x0c0aafaeu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0aafb0;
P_0c0aafb0: /* original 4f22, guest PC 0x0c0aafb0 */
if(!s->budget--) { s->failed_pc=0x0c0aafb0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aafb2;
P_0c0aafb2: /* original f230, guest PC 0x0c0aafb2 */
if(!s->budget--) { s->failed_pc=0x0c0aafb2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0aafb4;
P_0c0aafb4: /* original 7ff0, guest PC 0x0c0aafb4 */
if(!s->budget--) { s->failed_pc=0x0c0aafb4u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0aafb6;
P_0c0aafb6: /* original fe27, guest PC 0x0c0aafb6 */
if(!s->budget--) { s->failed_pc=0x0c0aafb6u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0aafb8;
P_0c0aafb8: /* original e066, guest PC 0x0c0aafb8 */
if(!s->budget--) { s->failed_pc=0x0c0aafb8u; return 0; }
r[0]=0x00000066u;
goto P_0c0aafba;
P_0c0aafba: /* original 0ced, guest PC 0x0c0aafba */
if(!s->budget--) { s->failed_pc=0x0c0aafbau; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aafbc;
P_0c0aafbc: /* original 7cff, guest PC 0x0c0aafbc */
if(!s->budget--) { s->failed_pc=0x0c0aafbcu; return 0; }
r[12]+=0xffffffffu;
goto P_0c0aafbe;
P_0c0aafbe: /* original 4c11, guest PC 0x0c0aafbe */
if(!s->budget--) { s->failed_pc=0x0c0aafbeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=0)!=0);
goto P_0c0aafc0;
P_0c0aafc0: /* original 8d01, guest PC 0x0c0aafc0 */
if(!s->budget--) { s->failed_pc=0x0c0aafc0u; return 0; }
cond=r[17]&1u;
r[13]=r[6];
if(cond) { goto P_0c0aafc6; }
goto P_0c0aafc4;
P_0c0aafc2: /* original 6d63, guest PC 0x0c0aafc2 */
if(!s->budget--) { s->failed_pc=0x0c0aafc2u; return 0; }
r[13]=r[6];
goto P_0c0aafc4;
P_0c0aafc4: /* original ec00, guest PC 0x0c0aafc4 */
if(!s->budget--) { s->failed_pc=0x0c0aafc4u; return 0; }
r[12]=0x00000000u;
goto P_0c0aafc6;
P_0c0aafc6: /* original 0ec5, guest PC 0x0c0aafc6 */
if(!s->budget--) { s->failed_pc=0x0c0aafc6u; return 0; }
write(ram,r[14]+r[0],r[12],2);
goto P_0c0aafc8;
P_0c0aafc8: /* original 64d2, guest PC 0x0c0aafc8 */
if(!s->budget--) { s->failed_pc=0x0c0aafc8u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0aafca;
P_0c0aafca: /* original 4429, guest PC 0x0c0aafca */
if(!s->budget--) { s->failed_pc=0x0c0aafcau; return 0; }
r[4]>>=16;
goto P_0c0aafcc;
P_0c0aafcc: /* original 644c, guest PC 0x0c0aafcc */
if(!s->budget--) { s->failed_pc=0x0c0aafccu; return 0; }
r[4]=r[4]&255u;
goto P_0c0aafce;
P_0c0aafce: /* original 6043, guest PC 0x0c0aafce */
if(!s->budget--) { s->failed_pc=0x0c0aafceu; return 0; }
r[0]=r[4];
goto P_0c0aafd0;
P_0c0aafd0: /* original 8801, guest PC 0x0c0aafd0 */
if(!s->budget--) { s->failed_pc=0x0c0aafd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0aafd2;
P_0c0aafd2: /* original 8b03, guest PC 0x0c0aafd2 */
if(!s->budget--) { s->failed_pc=0x0c0aafd2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aafdc; }
goto P_0c0aafd4;
P_0c0aafd4: /* original d23d, guest PC 0x0c0aafd4 */
if(!s->budget--) { s->failed_pc=0x0c0aafd4u; return 0; }
r[2]=read(ram,0x0c0ab0ccu,4);
goto P_0c0aafd6;
P_0c0aafd6: /* original 65b3, guest PC 0x0c0aafd6 */
if(!s->budget--) { s->failed_pc=0x0c0aafd6u; return 0; }
r[5]=r[11];
goto P_0c0aafd8;
P_0c0aafd8: /* original 420b, guest PC 0x0c0aafd8 */
if(!s->budget--) { s->failed_pc=0x0c0aafd8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0aafdcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aafdcu) { target=s->pc; goto dispatch; }
goto P_0c0aafdc;
P_0c0aafda: /* original 64e3, guest PC 0x0c0aafda */
if(!s->budget--) { s->failed_pc=0x0c0aafdau; return 0; }
r[4]=r[14];
goto P_0c0aafdc;
P_0c0aafdc: /* original 50d1, guest PC 0x0c0aafdc */
if(!s->budget--) { s->failed_pc=0x0c0aafdcu; return 0; }
r[0]=read(ram,r[13]+4,4);
goto P_0c0aafde;
P_0c0aafde: /* original 8800, guest PC 0x0c0aafde */
if(!s->budget--) { s->failed_pc=0x0c0aafdeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0aafe0;
P_0c0aafe0: /* original 8907, guest PC 0x0c0aafe0 */
if(!s->budget--) { s->failed_pc=0x0c0aafe0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aaff2; }
goto P_0c0aafe2;
P_0c0aafe2: /* original 8801, guest PC 0x0c0aafe2 */
if(!s->budget--) { s->failed_pc=0x0c0aafe2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0aafe4;
P_0c0aafe4: /* original 894f, guest PC 0x0c0aafe4 */
if(!s->budget--) { s->failed_pc=0x0c0aafe4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab086; }
goto P_0c0aafe6;
P_0c0aafe6: /* original 8802, guest PC 0x0c0aafe6 */
if(!s->budget--) { s->failed_pc=0x0c0aafe6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0aafe8;
P_0c0aafe8: /* original 895c, guest PC 0x0c0aafe8 */
if(!s->budget--) { s->failed_pc=0x0c0aafe8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab0a4; }
goto P_0c0aafea;
P_0c0aafea: /* original 8803, guest PC 0x0c0aafea */
if(!s->budget--) { s->failed_pc=0x0c0aafeau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0aafec;
P_0c0aafec: /* original 8b01, guest PC 0x0c0aafec */
if(!s->budget--) { s->failed_pc=0x0c0aafecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aaff2; }
goto P_0c0aafee;
P_0c0aafee: /* original a083, guest PC 0x0c0aafee */
if(!s->budget--) { s->failed_pc=0x0c0aafeeu; return 0; }
goto P_0c0ab0f8;
P_0c0aaff0: /* original 0009, guest PC 0x0c0aaff0 */
if(!s->budget--) { s->failed_pc=0x0c0aaff0u; return 0; }
goto P_0c0aaff2;
P_0c0aaff2: /* original c738, guest PC 0x0c0aaff2 */
if(!s->budget--) { s->failed_pc=0x0c0aaff2u; return 0; }
r[0]=code_base|0x000ab0d4u;
goto P_0c0aaff4;
P_0c0aaff4: /* original d336, guest PC 0x0c0aaff4 */
if(!s->budget--) { s->failed_pc=0x0c0aaff4u; return 0; }
r[3]=read(ram,0x0c0ab0d0u,4);
goto P_0c0aaff6;
P_0c0aaff6: /* original 62e2, guest PC 0x0c0aaff6 */
if(!s->budget--) { s->failed_pc=0x0c0aaff6u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0aaff8;
P_0c0aaff8: /* original 65f3, guest PC 0x0c0aaff8 */
if(!s->budget--) { s->failed_pc=0x0c0aaff8u; return 0; }
r[5]=r[15];
goto P_0c0aaffa;
P_0c0aaffa: /* original 64f3, guest PC 0x0c0aaffa */
if(!s->budget--) { s->failed_pc=0x0c0aaffau; return 0; }
r[4]=r[15];
goto P_0c0aaffc;
P_0c0aaffc: /* original 223b, guest PC 0x0c0aaffc */
if(!s->budget--) { s->failed_pc=0x0c0aaffcu; return 0; }
r[2]|=r[3];
goto P_0c0aaffe;
P_0c0aaffe: /* original 2e22, guest PC 0x0c0aaffe */
if(!s->budget--) { s->failed_pc=0x0c0aaffeu; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0ab000;
P_0c0ab000: /* original f708, guest PC 0x0c0ab000 */
if(!s->budget--) { s->failed_pc=0x0c0ab000u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0ab002;
P_0c0ab002: /* original 905d, guest PC 0x0c0ab002 */
if(!s->budget--) { s->failed_pc=0x0c0ab002u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab0c0u,2);
goto P_0c0ab004;
P_0c0ab004: /* original f49d, guest PC 0x0c0ab004 */
if(!s->budget--) { s->failed_pc=0x0c0ab004u; return 0; }
fr[4]=0x3f800000u;
goto P_0c0ab006;
P_0c0ab006: /* original f5e6, guest PC 0x0c0ab006 */
if(!s->budget--) { s->failed_pc=0x0c0ab006u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0ab008;
P_0c0ab008: /* original 7008, guest PC 0x0c0ab008 */
if(!s->budget--) { s->failed_pc=0x0c0ab008u; return 0; }
r[0]+=0x00000008u;
goto P_0c0ab00a;
P_0c0ab00a: /* original f34c, guest PC 0x0c0ab00a */
if(!s->budget--) { s->failed_pc=0x0c0ab00au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0ab00c;
P_0c0ab00c: /* original f352, guest PC 0x0c0ab00c */
if(!s->budget--) { s->failed_pc=0x0c0ab00cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c0ab00e;
P_0c0ab00e: /* original f6e6, guest PC 0x0c0ab00e */
if(!s->budget--) { s->failed_pc=0x0c0ab00eu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0ab010;
P_0c0ab010: /* original e00c, guest PC 0x0c0ab010 */
if(!s->budget--) { s->failed_pc=0x0c0ab010u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab012;
P_0c0ab012: /* original f462, guest PC 0x0c0ab012 */
if(!s->budget--) { s->failed_pc=0x0c0ab012u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0ab014;
P_0c0ab014: /* original ff37, guest PC 0x0c0ab014 */
if(!s->budget--) { s->failed_pc=0x0c0ab014u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab016;
P_0c0ab016: /* original e008, guest PC 0x0c0ab016 */
if(!s->budget--) { s->failed_pc=0x0c0ab016u; return 0; }
r[0]=0x00000008u;
goto P_0c0ab018;
P_0c0ab018: /* original ff47, guest PC 0x0c0ab018 */
if(!s->budget--) { s->failed_pc=0x0c0ab018u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0ab01a;
P_0c0ab01a: /* original e004, guest PC 0x0c0ab01a */
if(!s->budget--) { s->failed_pc=0x0c0ab01au; return 0; }
r[0]=0x00000004u;
goto P_0c0ab01c;
P_0c0ab01c: /* original f27c, guest PC 0x0c0ab01c */
if(!s->budget--) { s->failed_pc=0x0c0ab01cu; return 0; }
vf3_matrix_move(s,2,7);
goto P_0c0ab01e;
P_0c0ab01e: /* original f252, guest PC 0x0c0ab01e */
if(!s->budget--) { s->failed_pc=0x0c0ab01eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'*');
goto P_0c0ab020;
P_0c0ab020: /* original f762, guest PC 0x0c0ab020 */
if(!s->budget--) { s->failed_pc=0x0c0ab020u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'*');
goto P_0c0ab022;
P_0c0ab022: /* original ff27, guest PC 0x0c0ab022 */
if(!s->budget--) { s->failed_pc=0x0c0ab022u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0ab024;
P_0c0ab024: /* original ff7a, guest PC 0x0c0ab024 */
if(!s->budget--) { s->failed_pc=0x0c0ab024u; return 0; }
vf3_matrix_store(s,ram,7,r[15]);
goto P_0c0ab026;
P_0c0ab026: /* original bb82, guest PC 0x0c0ab026 */
if(!s->budget--) { s->failed_pc=0x0c0ab026u; return 0; }
target=code_base|0x0c0aa72eu; r[16]=code_base|0x0c0ab02au;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab02au) { target=s->pc; goto dispatch; }
goto P_0c0ab02a;
P_0c0ab028: /* original 7404, guest PC 0x0c0ab028 */
if(!s->budget--) { s->failed_pc=0x0c0ab028u; return 0; }
r[4]+=0x00000004u;
goto P_0c0ab02a;
P_0c0ab02a: /* original e00c, guest PC 0x0c0ab02a */
if(!s->budget--) { s->failed_pc=0x0c0ab02au; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab02c;
P_0c0ab02c: /* original f3f6, guest PC 0x0c0ab02c */
if(!s->budget--) { s->failed_pc=0x0c0ab02cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab02e;
P_0c0ab02e: /* original e024, guest PC 0x0c0ab02e */
if(!s->budget--) { s->failed_pc=0x0c0ab02eu; return 0; }
r[0]=0x00000024u;
goto P_0c0ab030;
P_0c0ab030: /* original fe37, guest PC 0x0c0ab030 */
if(!s->budget--) { s->failed_pc=0x0c0ab030u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab032;
P_0c0ab032: /* original e008, guest PC 0x0c0ab032 */
if(!s->budget--) { s->failed_pc=0x0c0ab032u; return 0; }
r[0]=0x00000008u;
goto P_0c0ab034;
P_0c0ab034: /* original f3f6, guest PC 0x0c0ab034 */
if(!s->budget--) { s->failed_pc=0x0c0ab034u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab036;
P_0c0ab036: /* original e02c, guest PC 0x0c0ab036 */
if(!s->budget--) { s->failed_pc=0x0c0ab036u; return 0; }
r[0]=0x0000002cu;
goto P_0c0ab038;
P_0c0ab038: /* original fe37, guest PC 0x0c0ab038 */
if(!s->budget--) { s->failed_pc=0x0c0ab038u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab03a;
P_0c0ab03a: /* original e004, guest PC 0x0c0ab03a */
if(!s->budget--) { s->failed_pc=0x0c0ab03au; return 0; }
r[0]=0x00000004u;
goto P_0c0ab03c;
P_0c0ab03c: /* original f3f6, guest PC 0x0c0ab03c */
if(!s->budget--) { s->failed_pc=0x0c0ab03cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab03e;
P_0c0ab03e: /* original 9040, guest PC 0x0c0ab03e */
if(!s->budget--) { s->failed_pc=0x0c0ab03eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab0c2u,2);
goto P_0c0ab040;
P_0c0ab040: /* original fe37, guest PC 0x0c0ab040 */
if(!s->budget--) { s->failed_pc=0x0c0ab040u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab042;
P_0c0ab042: /* original 903f, guest PC 0x0c0ab042 */
if(!s->budget--) { s->failed_pc=0x0c0ab042u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab0c4u,2);
goto P_0c0ab044;
P_0c0ab044: /* original f3f8, guest PC 0x0c0ab044 */
if(!s->budget--) { s->failed_pc=0x0c0ab044u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0ab046;
P_0c0ab046: /* original fe37, guest PC 0x0c0ab046 */
if(!s->budget--) { s->failed_pc=0x0c0ab046u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab048;
P_0c0ab048: /* original 65d2, guest PC 0x0c0ab048 */
if(!s->budget--) { s->failed_pc=0x0c0ab048u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0ab04a;
P_0c0ab04a: /* original 655d, guest PC 0x0c0ab04a */
if(!s->budget--) { s->failed_pc=0x0c0ab04au; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ab04c;
P_0c0ab04c: /* original 2558, guest PC 0x0c0ab04c */
if(!s->budget--) { s->failed_pc=0x0c0ab04cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0ab04e;
P_0c0ab04e: /* original 8b08, guest PC 0x0c0ab04e */
if(!s->budget--) { s->failed_pc=0x0c0ab04eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab062; }
goto P_0c0ab050;
P_0c0ab050: /* original 85ae, guest PC 0x0c0ab050 */
if(!s->budget--) { s->failed_pc=0x0c0ab050u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+28,2);
goto P_0c0ab052;
P_0c0ab052: /* original d321, guest PC 0x0c0ab052 */
if(!s->budget--) { s->failed_pc=0x0c0ab052u; return 0; }
r[3]=read(ram,0x0c0ab0d8u,4);
goto P_0c0ab054;
P_0c0ab054: /* original 650d, guest PC 0x0c0ab054 */
if(!s->budget--) { s->failed_pc=0x0c0ab054u; return 0; }
r[5]=r[0]&65535u;
goto P_0c0ab056;
P_0c0ab056: /* original e048, guest PC 0x0c0ab056 */
if(!s->budget--) { s->failed_pc=0x0c0ab056u; return 0; }
r[0]=0x00000048u;
goto P_0c0ab058;
P_0c0ab058: /* original 02ee, guest PC 0x0c0ab058 */
if(!s->budget--) { s->failed_pc=0x0c0ab058u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ab05a;
P_0c0ab05a: /* original 2238, guest PC 0x0c0ab05a */
if(!s->budget--) { s->failed_pc=0x0c0ab05au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab05c;
P_0c0ab05c: /* original 8b01, guest PC 0x0c0ab05c */
if(!s->budget--) { s->failed_pc=0x0c0ab05cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab062; }
goto P_0c0ab05e;
P_0c0ab05e: /* original 85ac, guest PC 0x0c0ab05e */
if(!s->budget--) { s->failed_pc=0x0c0ab05eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+24,2);
goto P_0c0ab060;
P_0c0ab060: /* original 650d, guest PC 0x0c0ab060 */
if(!s->budget--) { s->failed_pc=0x0c0ab060u; return 0; }
r[5]=r[0]&65535u;
goto P_0c0ab062;
P_0c0ab062: /* original d31e, guest PC 0x0c0ab062 */
if(!s->budget--) { s->failed_pc=0x0c0ab062u; return 0; }
r[3]=read(ram,0x0c0ab0dcu,4);
goto P_0c0ab064;
P_0c0ab064: /* original 430b, guest PC 0x0c0ab064 */
if(!s->budget--) { s->failed_pc=0x0c0ab064u; return 0; }
target=r[3];
r[16]=code_base|0x0c0ab068u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab068u) { target=s->pc; goto dispatch; }
goto P_0c0ab068;
P_0c0ab066: /* original 64e3, guest PC 0x0c0ab066 */
if(!s->budget--) { s->failed_pc=0x0c0ab066u; return 0; }
r[4]=r[14];
goto P_0c0ab068;
P_0c0ab068: /* original e048, guest PC 0x0c0ab068 */
if(!s->budget--) { s->failed_pc=0x0c0ab068u; return 0; }
r[0]=0x00000048u;
goto P_0c0ab06a;
P_0c0ab06a: /* original d31d, guest PC 0x0c0ab06a */
if(!s->budget--) { s->failed_pc=0x0c0ab06au; return 0; }
r[3]=read(ram,0x0c0ab0e0u,4);
goto P_0c0ab06c;
P_0c0ab06c: /* original 02ee, guest PC 0x0c0ab06c */
if(!s->budget--) { s->failed_pc=0x0c0ab06cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ab06e;
P_0c0ab06e: /* original 223b, guest PC 0x0c0ab06e */
if(!s->budget--) { s->failed_pc=0x0c0ab06eu; return 0; }
r[2]|=r[3];
goto P_0c0ab070;
P_0c0ab070: /* original 0e26, guest PC 0x0c0ab070 */
if(!s->budget--) { s->failed_pc=0x0c0ab070u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0ab072;
P_0c0ab072: /* original 9028, guest PC 0x0c0ab072 */
if(!s->budget--) { s->failed_pc=0x0c0ab072u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab0c6u,2);
goto P_0c0ab074;
P_0c0ab074: /* original 01ed, guest PC 0x0c0ab074 */
if(!s->budget--) { s->failed_pc=0x0c0ab074u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab076;
P_0c0ab076: /* original e03e, guest PC 0x0c0ab076 */
if(!s->budget--) { s->failed_pc=0x0c0ab076u; return 0; }
r[0]=0x0000003eu;
goto P_0c0ab078;
P_0c0ab078: /* original 0e15, guest PC 0x0c0ab078 */
if(!s->budget--) { s->failed_pc=0x0c0ab078u; return 0; }
write(ram,r[14]+r[0],r[1],2);
goto P_0c0ab07a;
P_0c0ab07a: /* original e062, guest PC 0x0c0ab07a */
if(!s->budget--) { s->failed_pc=0x0c0ab07au; return 0; }
r[0]=0x00000062u;
goto P_0c0ab07c;
P_0c0ab07c: /* original 52d1, guest PC 0x0c0ab07c */
if(!s->budget--) { s->failed_pc=0x0c0ab07cu; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0ab07e;
P_0c0ab07e: /* original 7201, guest PC 0x0c0ab07e */
if(!s->budget--) { s->failed_pc=0x0c0ab07eu; return 0; }
r[2]+=0x00000001u;
goto P_0c0ab080;
P_0c0ab080: /* original 6123, guest PC 0x0c0ab080 */
if(!s->budget--) { s->failed_pc=0x0c0ab080u; return 0; }
r[1]=r[2];
goto P_0c0ab082;
P_0c0ab082: /* original 1d21, guest PC 0x0c0ab082 */
if(!s->budget--) { s->failed_pc=0x0c0ab082u; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0ab084;
P_0c0ab084: /* original 0e14, guest PC 0x0c0ab084 */
if(!s->budget--) { s->failed_pc=0x0c0ab084u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c0ab086;
P_0c0ab086: /* original e03e, guest PC 0x0c0ab086 */
if(!s->budget--) { s->failed_pc=0x0c0ab086u; return 0; }
r[0]=0x0000003eu;
goto P_0c0ab088;
P_0c0ab088: /* original 05ed, guest PC 0x0c0ab088 */
if(!s->budget--) { s->failed_pc=0x0c0ab088u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab08a;
P_0c0ab08a: /* original 901d, guest PC 0x0c0ab08a */
if(!s->budget--) { s->failed_pc=0x0c0ab08au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab0c8u,2);
goto P_0c0ab08c;
P_0c0ab08c: /* original 655d, guest PC 0x0c0ab08c */
if(!s->budget--) { s->failed_pc=0x0c0ab08cu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ab08e;
P_0c0ab08e: /* original 04ed, guest PC 0x0c0ab08e */
if(!s->budget--) { s->failed_pc=0x0c0ab08eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab090;
P_0c0ab090: /* original 644d, guest PC 0x0c0ab090 */
if(!s->budget--) { s->failed_pc=0x0c0ab090u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0ab092;
P_0c0ab092: /* original 74ff, guest PC 0x0c0ab092 */
if(!s->budget--) { s->failed_pc=0x0c0ab092u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0ab094;
P_0c0ab094: /* original 3542, guest PC 0x0c0ab094 */
if(!s->budget--) { s->failed_pc=0x0c0ab094u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[4])!=0);
goto P_0c0ab096;
P_0c0ab096: /* original 8b60, guest PC 0x0c0ab096 */
if(!s->budget--) { s->failed_pc=0x0c0ab096u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab15a; }
goto P_0c0ab098;
P_0c0ab098: /* original 52d1, guest PC 0x0c0ab098 */
if(!s->budget--) { s->failed_pc=0x0c0ab098u; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0ab09a;
P_0c0ab09a: /* original e062, guest PC 0x0c0ab09a */
if(!s->budget--) { s->failed_pc=0x0c0ab09au; return 0; }
r[0]=0x00000062u;
goto P_0c0ab09c;
P_0c0ab09c: /* original 7201, guest PC 0x0c0ab09c */
if(!s->budget--) { s->failed_pc=0x0c0ab09cu; return 0; }
r[2]+=0x00000001u;
goto P_0c0ab09e;
P_0c0ab09e: /* original 6323, guest PC 0x0c0ab09e */
if(!s->budget--) { s->failed_pc=0x0c0ab09eu; return 0; }
r[3]=r[2];
goto P_0c0ab0a0;
P_0c0ab0a0: /* original 1d21, guest PC 0x0c0ab0a0 */
if(!s->budget--) { s->failed_pc=0x0c0ab0a0u; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0ab0a2;
P_0c0ab0a2: /* original 0e34, guest PC 0x0c0ab0a2 */
if(!s->budget--) { s->failed_pc=0x0c0ab0a2u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ab0a4;
P_0c0ab0a4: /* original 9010, guest PC 0x0c0ab0a4 */
if(!s->budget--) { s->failed_pc=0x0c0ab0a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab0c8u,2);
goto P_0c0ab0a6;
P_0c0ab0a6: /* original 04ed, guest PC 0x0c0ab0a6 */
if(!s->budget--) { s->failed_pc=0x0c0ab0a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab0a8;
P_0c0ab0a8: /* original 7002, guest PC 0x0c0ab0a8 */
if(!s->budget--) { s->failed_pc=0x0c0ab0a8u; return 0; }
r[0]+=0x00000002u;
goto P_0c0ab0aa;
P_0c0ab0aa: /* original 05ed, guest PC 0x0c0ab0aa */
if(!s->budget--) { s->failed_pc=0x0c0ab0aau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab0ac;
P_0c0ab0ac: /* original 644d, guest PC 0x0c0ab0ac */
if(!s->budget--) { s->failed_pc=0x0c0ab0acu; return 0; }
r[4]=r[4]&65535u;
goto P_0c0ab0ae;
P_0c0ab0ae: /* original 655d, guest PC 0x0c0ab0ae */
if(!s->budget--) { s->failed_pc=0x0c0ab0aeu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ab0b0;
P_0c0ab0b0: /* original 35c8, guest PC 0x0c0ab0b0 */
if(!s->budget--) { s->failed_pc=0x0c0ab0b0u; return 0; }
r[5]-=r[12];
goto P_0c0ab0b2;
P_0c0ab0b2: /* original 74ff, guest PC 0x0c0ab0b2 */
if(!s->budget--) { s->failed_pc=0x0c0ab0b2u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0ab0b4;
P_0c0ab0b4: /* original 3453, guest PC 0x0c0ab0b4 */
if(!s->budget--) { s->failed_pc=0x0c0ab0b4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c0ab0b6;
P_0c0ab0b6: /* original 8b15, guest PC 0x0c0ab0b6 */
if(!s->budget--) { s->failed_pc=0x0c0ab0b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab0e4; }
goto P_0c0ab0b8;
P_0c0ab0b8: /* original e03e, guest PC 0x0c0ab0b8 */
if(!s->budget--) { s->failed_pc=0x0c0ab0b8u; return 0; }
r[0]=0x0000003eu;
goto P_0c0ab0ba;
P_0c0ab0ba: /* original a02a, guest PC 0x0c0ab0ba */
if(!s->budget--) { s->failed_pc=0x0c0ab0bau; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0ab112;
P_0c0ab0bc: /* original 0e45, guest PC 0x0c0ab0bc */
if(!s->budget--) { s->failed_pc=0x0c0ab0bcu; return 0; }
write(ram,r[14]+r[0],r[4],2);
if(!vf3_matrix_family(0x0c0ab0beu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ab0beu; return 0; } return 1;
P_0c0ab0e4: /* original 62e2, guest PC 0x0c0ab0e4 */
if(!s->budget--) { s->failed_pc=0x0c0ab0e4u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0ab0e6;
P_0c0ab0e6: /* original e062, guest PC 0x0c0ab0e6 */
if(!s->budget--) { s->failed_pc=0x0c0ab0e6u; return 0; }
r[0]=0x00000062u;
goto P_0c0ab0e8;
P_0c0ab0e8: /* original d321, guest PC 0x0c0ab0e8 */
if(!s->budget--) { s->failed_pc=0x0c0ab0e8u; return 0; }
r[3]=read(ram,0x0c0ab170u,4);
goto P_0c0ab0ea;
P_0c0ab0ea: /* original 2239, guest PC 0x0c0ab0ea */
if(!s->budget--) { s->failed_pc=0x0c0ab0eau; return 0; }
r[2]&=r[3];
goto P_0c0ab0ec;
P_0c0ab0ec: /* original 2e22, guest PC 0x0c0ab0ec */
if(!s->budget--) { s->failed_pc=0x0c0ab0ecu; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0ab0ee;
P_0c0ab0ee: /* original 51d1, guest PC 0x0c0ab0ee */
if(!s->budget--) { s->failed_pc=0x0c0ab0eeu; return 0; }
r[1]=read(ram,r[13]+4,4);
goto P_0c0ab0f0;
P_0c0ab0f0: /* original 7101, guest PC 0x0c0ab0f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab0f0u; return 0; }
r[1]+=0x00000001u;
goto P_0c0ab0f2;
P_0c0ab0f2: /* original 6213, guest PC 0x0c0ab0f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab0f2u; return 0; }
r[2]=r[1];
goto P_0c0ab0f4;
P_0c0ab0f4: /* original 1d11, guest PC 0x0c0ab0f4 */
if(!s->budget--) { s->failed_pc=0x0c0ab0f4u; return 0; }
write(ram,r[13]+4,r[1],4);
goto P_0c0ab0f6;
P_0c0ab0f6: /* original 0e24, guest PC 0x0c0ab0f6 */
if(!s->budget--) { s->failed_pc=0x0c0ab0f6u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0ab0f8;
P_0c0ab0f8: /* original 4c15, guest PC 0x0c0ab0f8 */
if(!s->budget--) { s->failed_pc=0x0c0ab0f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>0)!=0);
goto P_0c0ab0fa;
P_0c0ab0fa: /* original 890a, guest PC 0x0c0ab0fa */
if(!s->budget--) { s->failed_pc=0x0c0ab0fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab112; }
goto P_0c0ab0fc;
P_0c0ab0fc: /* original e300, guest PC 0x0c0ab0fc */
if(!s->budget--) { s->failed_pc=0x0c0ab0fcu; return 0; }
r[3]=0x00000000u;
goto P_0c0ab0fe;
P_0c0ab0fe: /* original e048, guest PC 0x0c0ab0fe */
if(!s->budget--) { s->failed_pc=0x0c0ab0feu; return 0; }
r[0]=0x00000048u;
goto P_0c0ab100;
P_0c0ab100: /* original 1e3e, guest PC 0x0c0ab100 */
if(!s->budget--) { s->failed_pc=0x0c0ab100u; return 0; }
write(ram,r[14]+56,r[3],4);
goto P_0c0ab102;
P_0c0ab102: /* original 02ee, guest PC 0x0c0ab102 */
if(!s->budget--) { s->failed_pc=0x0c0ab102u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ab104;
P_0c0ab104: /* original d31b, guest PC 0x0c0ab104 */
if(!s->budget--) { s->failed_pc=0x0c0ab104u; return 0; }
r[3]=read(ram,0x0c0ab174u,4);
goto P_0c0ab106;
P_0c0ab106: /* original 2239, guest PC 0x0c0ab106 */
if(!s->budget--) { s->failed_pc=0x0c0ab106u; return 0; }
r[2]&=r[3];
goto P_0c0ab108;
P_0c0ab108: /* original 0e26, guest PC 0x0c0ab108 */
if(!s->budget--) { s->failed_pc=0x0c0ab108u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0ab10a;
P_0c0ab10a: /* original 61e2, guest PC 0x0c0ab10a */
if(!s->budget--) { s->failed_pc=0x0c0ab10au; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0ab10c;
P_0c0ab10c: /* original d218, guest PC 0x0c0ab10c */
if(!s->budget--) { s->failed_pc=0x0c0ab10cu; return 0; }
r[2]=read(ram,0x0c0ab170u,4);
goto P_0c0ab10e;
P_0c0ab10e: /* original 2129, guest PC 0x0c0ab10e */
if(!s->budget--) { s->failed_pc=0x0c0ab10eu; return 0; }
r[1]&=r[2];
goto P_0c0ab110;
P_0c0ab110: /* original 2e12, guest PC 0x0c0ab110 */
if(!s->budget--) { s->failed_pc=0x0c0ab110u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0ab112;
P_0c0ab112: /* original 902a, guest PC 0x0c0ab112 */
if(!s->budget--) { s->failed_pc=0x0c0ab112u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab16au,2);
goto P_0c0ab114;
P_0c0ab114: /* original 03bd, guest PC 0x0c0ab114 */
if(!s->budget--) { s->failed_pc=0x0c0ab114u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c0ab116;
P_0c0ab116: /* original 7004, guest PC 0x0c0ab116 */
if(!s->budget--) { s->failed_pc=0x0c0ab116u; return 0; }
r[0]+=0x00000004u;
goto P_0c0ab118;
P_0c0ab118: /* original 02ed, guest PC 0x0c0ab118 */
if(!s->budget--) { s->failed_pc=0x0c0ab118u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab11a;
P_0c0ab11a: /* original 3320, guest PC 0x0c0ab11a */
if(!s->budget--) { s->failed_pc=0x0c0ab11au; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0ab11c;
P_0c0ab11c: /* original 891d, guest PC 0x0c0ab11c */
if(!s->budget--) { s->failed_pc=0x0c0ab11cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab15a; }
goto P_0c0ab11e;
P_0c0ab11e: /* original 9025, guest PC 0x0c0ab11e */
if(!s->budget--) { s->failed_pc=0x0c0ab11eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab16cu,2);
goto P_0c0ab120;
P_0c0ab120: /* original d315, guest PC 0x0c0ab120 */
if(!s->budget--) { s->failed_pc=0x0c0ab120u; return 0; }
r[3]=read(ram,0x0c0ab178u,4);
goto P_0c0ab122;
P_0c0ab122: /* original 04be, guest PC 0x0c0ab122 */
if(!s->budget--) { s->failed_pc=0x0c0ab122u; return 0; }
r[4]=read(ram,r[11]+r[0],4);
goto P_0c0ab124;
P_0c0ab124: /* original 2348, guest PC 0x0c0ab124 */
if(!s->budget--) { s->failed_pc=0x0c0ab124u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0ab126;
P_0c0ab126: /* original 8b02, guest PC 0x0c0ab126 */
if(!s->budget--) { s->failed_pc=0x0c0ab126u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab12e; }
goto P_0c0ab128;
P_0c0ab128: /* original d114, guest PC 0x0c0ab128 */
if(!s->budget--) { s->failed_pc=0x0c0ab128u; return 0; }
r[1]=read(ram,0x0c0ab17cu,4);
goto P_0c0ab12a;
P_0c0ab12a: /* original 2148, guest PC 0x0c0ab12a */
if(!s->budget--) { s->failed_pc=0x0c0ab12au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c0ab12c;
P_0c0ab12c: /* original 8915, guest PC 0x0c0ab12c */
if(!s->budget--) { s->failed_pc=0x0c0ab12cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab15a; }
goto P_0c0ab12e;
P_0c0ab12e: /* original e048, guest PC 0x0c0ab12e */
if(!s->budget--) { s->failed_pc=0x0c0ab12eu; return 0; }
r[0]=0x00000048u;
goto P_0c0ab130;
P_0c0ab130: /* original d313, guest PC 0x0c0ab130 */
if(!s->budget--) { s->failed_pc=0x0c0ab130u; return 0; }
r[3]=read(ram,0x0c0ab180u,4);
goto P_0c0ab132;
P_0c0ab132: /* original 02ee, guest PC 0x0c0ab132 */
if(!s->budget--) { s->failed_pc=0x0c0ab132u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ab134;
P_0c0ab134: /* original 2238, guest PC 0x0c0ab134 */
if(!s->budget--) { s->failed_pc=0x0c0ab134u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab136;
P_0c0ab136: /* original 8902, guest PC 0x0c0ab136 */
if(!s->budget--) { s->failed_pc=0x0c0ab136u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab13e; }
goto P_0c0ab138;
P_0c0ab138: /* original d212, guest PC 0x0c0ab138 */
if(!s->budget--) { s->failed_pc=0x0c0ab138u; return 0; }
r[2]=read(ram,0x0c0ab184u,4);
goto P_0c0ab13a;
P_0c0ab13a: /* original 2428, guest PC 0x0c0ab13a */
if(!s->budget--) { s->failed_pc=0x0c0ab13au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0ab13c;
P_0c0ab13c: /* original 8b0d, guest PC 0x0c0ab13c */
if(!s->budget--) { s->failed_pc=0x0c0ab13cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab15a; }
goto P_0c0ab13e;
P_0c0ab13e: /* original d212, guest PC 0x0c0ab13e */
if(!s->budget--) { s->failed_pc=0x0c0ab13eu; return 0; }
r[2]=read(ram,0x0c0ab188u,4);
goto P_0c0ab140;
P_0c0ab140: /* original 65b3, guest PC 0x0c0ab140 */
if(!s->budget--) { s->failed_pc=0x0c0ab140u; return 0; }
r[5]=r[11];
goto P_0c0ab142;
P_0c0ab142: /* original 420b, guest PC 0x0c0ab142 */
if(!s->budget--) { s->failed_pc=0x0c0ab142u; return 0; }
target=r[2];
r[16]=code_base|0x0c0ab146u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab146u) { target=s->pc; goto dispatch; }
goto P_0c0ab146;
P_0c0ab144: /* original 64e3, guest PC 0x0c0ab144 */
if(!s->budget--) { s->failed_pc=0x0c0ab144u; return 0; }
r[4]=r[14];
goto P_0c0ab146;
P_0c0ab146: /* original 6403, guest PC 0x0c0ab146 */
if(!s->budget--) { s->failed_pc=0x0c0ab146u; return 0; }
r[4]=r[0];
goto P_0c0ab148;
P_0c0ab148: /* original 2448, guest PC 0x0c0ab148 */
if(!s->budget--) { s->failed_pc=0x0c0ab148u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0ab14a;
P_0c0ab14a: /* original 8906, guest PC 0x0c0ab14a */
if(!s->budget--) { s->failed_pc=0x0c0ab14au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab15a; }
goto P_0c0ab14c;
P_0c0ab14c: /* original 62e3, guest PC 0x0c0ab14c */
if(!s->budget--) { s->failed_pc=0x0c0ab14cu; return 0; }
r[2]=r[14];
goto P_0c0ab14e;
P_0c0ab14e: /* original e001, guest PC 0x0c0ab14e */
if(!s->budget--) { s->failed_pc=0x0c0ab14eu; return 0; }
r[0]=0x00000001u;
goto P_0c0ab150;
P_0c0ab150: /* original 7238, guest PC 0x0c0ab150 */
if(!s->budget--) { s->failed_pc=0x0c0ab150u; return 0; }
r[2]+=0x00000038u;
goto P_0c0ab152;
P_0c0ab152: /* original 8022, guest PC 0x0c0ab152 */
if(!s->budget--) { s->failed_pc=0x0c0ab152u; return 0; }
write(ram,r[2]+2,r[0],1);
goto P_0c0ab154;
P_0c0ab154: /* original e062, guest PC 0x0c0ab154 */
if(!s->budget--) { s->failed_pc=0x0c0ab154u; return 0; }
r[0]=0x00000062u;
goto P_0c0ab156;
P_0c0ab156: /* original e303, guest PC 0x0c0ab156 */
if(!s->budget--) { s->failed_pc=0x0c0ab156u; return 0; }
r[3]=0x00000003u;
goto P_0c0ab158;
P_0c0ab158: /* original 0e34, guest PC 0x0c0ab158 */
if(!s->budget--) { s->failed_pc=0x0c0ab158u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ab15a;
P_0c0ab15a: /* original 7f10, guest PC 0x0c0ab15a */
if(!s->budget--) { s->failed_pc=0x0c0ab15au; return 0; }
r[15]+=0x00000010u;
goto P_0c0ab15c;
P_0c0ab15c: /* original 4f26, guest PC 0x0c0ab15c */
if(!s->budget--) { s->failed_pc=0x0c0ab15cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ab15e;
P_0c0ab15e: /* original 6af6, guest PC 0x0c0ab15e */
if(!s->budget--) { s->failed_pc=0x0c0ab15eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0ab160;
P_0c0ab160: /* original 6bf6, guest PC 0x0c0ab160 */
if(!s->budget--) { s->failed_pc=0x0c0ab160u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ab162;
P_0c0ab162: /* original 6cf6, guest PC 0x0c0ab162 */
if(!s->budget--) { s->failed_pc=0x0c0ab162u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ab164;
P_0c0ab164: /* original 6df6, guest PC 0x0c0ab164 */
if(!s->budget--) { s->failed_pc=0x0c0ab164u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ab166;
P_0c0ab166: /* original 000b, guest PC 0x0c0ab166 */
if(!s->budget--) { s->failed_pc=0x0c0ab166u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ab168: /* original 6ef6, guest PC 0x0c0ab168 */
if(!s->budget--) { s->failed_pc=0x0c0ab168u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ab16au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ab16au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
