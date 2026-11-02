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
int vf3_away_batch156_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0bbdd6u: goto P_0c0bbdd6;
case 0x0c0bbdd8u: goto P_0c0bbdd8;
case 0x0c0bbddau: goto P_0c0bbdda;
case 0x0c0bbddcu: goto P_0c0bbddc;
case 0x0c0bbddeu: goto P_0c0bbdde;
case 0x0c0bbde0u: goto P_0c0bbde0;
case 0x0c0bbde2u: goto P_0c0bbde2;
case 0x0c0bbde4u: goto P_0c0bbde4;
case 0x0c0bbde6u: goto P_0c0bbde6;
case 0x0c0bbde8u: goto P_0c0bbde8;
case 0x0c0bbdeau: goto P_0c0bbdea;
case 0x0c0bbdecu: goto P_0c0bbdec;
case 0x0c0bbdeeu: goto P_0c0bbdee;
case 0x0c0bbdf0u: goto P_0c0bbdf0;
case 0x0c0bbdf2u: goto P_0c0bbdf2;
case 0x0c0bbdf4u: goto P_0c0bbdf4;
case 0x0c0bbdf6u: goto P_0c0bbdf6;
case 0x0c0bbdf8u: goto P_0c0bbdf8;
case 0x0c0bbdfau: goto P_0c0bbdfa;
case 0x0c0bbdfcu: goto P_0c0bbdfc;
case 0x0c0bbdfeu: goto P_0c0bbdfe;
case 0x0c0bbe00u: goto P_0c0bbe00;
case 0x0c0bbe02u: goto P_0c0bbe02;
case 0x0c0bbe04u: goto P_0c0bbe04;
case 0x0c0bbe06u: goto P_0c0bbe06;
case 0x0c0bbe08u: goto P_0c0bbe08;
case 0x0c0bbe0au: goto P_0c0bbe0a;
case 0x0c0bbe0cu: goto P_0c0bbe0c;
case 0x0c0bbe0eu: goto P_0c0bbe0e;
case 0x0c0bbe10u: goto P_0c0bbe10;
case 0x0c0bbe12u: goto P_0c0bbe12;
case 0x0c0bbe14u: goto P_0c0bbe14;
case 0x0c0bbe16u: goto P_0c0bbe16;
case 0x0c0bbe18u: goto P_0c0bbe18;
case 0x0c0bbe1au: goto P_0c0bbe1a;
case 0x0c0bbe1cu: goto P_0c0bbe1c;
case 0x0c0bbe1eu: goto P_0c0bbe1e;
case 0x0c0bbe20u: goto P_0c0bbe20;
case 0x0c0bbe22u: goto P_0c0bbe22;
case 0x0c0bbe24u: goto P_0c0bbe24;
case 0x0c0bbe26u: goto P_0c0bbe26;
case 0x0c0bbe28u: goto P_0c0bbe28;
case 0x0c0bbe2au: goto P_0c0bbe2a;
case 0x0c0bbe2cu: goto P_0c0bbe2c;
case 0x0c0bbe2eu: goto P_0c0bbe2e;
case 0x0c0bbe30u: goto P_0c0bbe30;
case 0x0c0bbe32u: goto P_0c0bbe32;
case 0x0c0bbe34u: goto P_0c0bbe34;
case 0x0c0bbe36u: goto P_0c0bbe36;
case 0x0c0bbe38u: goto P_0c0bbe38;
case 0x0c0bbe3au: goto P_0c0bbe3a;
case 0x0c0bbe3cu: goto P_0c0bbe3c;
case 0x0c0bbe3eu: goto P_0c0bbe3e;
case 0x0c0bbe40u: goto P_0c0bbe40;
case 0x0c0bbe42u: goto P_0c0bbe42;
case 0x0c0bbe44u: goto P_0c0bbe44;
case 0x0c0bbe46u: goto P_0c0bbe46;
case 0x0c0bbe48u: goto P_0c0bbe48;
case 0x0c0bbe4au: goto P_0c0bbe4a;
case 0x0c0bbe4cu: goto P_0c0bbe4c;
case 0x0c0bbe4eu: goto P_0c0bbe4e;
case 0x0c0bbe50u: goto P_0c0bbe50;
case 0x0c0bbe52u: goto P_0c0bbe52;
case 0x0c0bbe54u: goto P_0c0bbe54;
case 0x0c0bbe56u: goto P_0c0bbe56;
case 0x0c0bbe58u: goto P_0c0bbe58;
case 0x0c0bbe5au: goto P_0c0bbe5a;
case 0x0c0bbe5cu: goto P_0c0bbe5c;
case 0x0c0bbe5eu: goto P_0c0bbe5e;
case 0x0c0bbe60u: goto P_0c0bbe60;
case 0x0c0bbe62u: goto P_0c0bbe62;
case 0x0c0bbe64u: goto P_0c0bbe64;
case 0x0c0bbe66u: goto P_0c0bbe66;
case 0x0c0bbe68u: goto P_0c0bbe68;
case 0x0c0bbe6au: goto P_0c0bbe6a;
case 0x0c0bbe6cu: goto P_0c0bbe6c;
case 0x0c0bbe6eu: goto P_0c0bbe6e;
case 0x0c0bbe70u: goto P_0c0bbe70;
case 0x0c0bbe72u: goto P_0c0bbe72;
case 0x0c0bbe74u: goto P_0c0bbe74;
case 0x0c0bbe76u: goto P_0c0bbe76;
case 0x0c0bbe78u: goto P_0c0bbe78;
case 0x0c0bbe7au: goto P_0c0bbe7a;
case 0x0c0bbe7cu: goto P_0c0bbe7c;
case 0x0c0bbe7eu: goto P_0c0bbe7e;
case 0x0c0bbe80u: goto P_0c0bbe80;
case 0x0c0bbe82u: goto P_0c0bbe82;
case 0x0c0bbe84u: goto P_0c0bbe84;
case 0x0c0bbe86u: goto P_0c0bbe86;
case 0x0c0bbe88u: goto P_0c0bbe88;
case 0x0c0bbe8au: goto P_0c0bbe8a;
case 0x0c0bbe8cu: goto P_0c0bbe8c;
case 0x0c0bbe8eu: goto P_0c0bbe8e;
case 0x0c0bbe90u: goto P_0c0bbe90;
case 0x0c0bbe92u: goto P_0c0bbe92;
case 0x0c0bbe94u: goto P_0c0bbe94;
case 0x0c0bbe96u: goto P_0c0bbe96;
case 0x0c0bbe98u: goto P_0c0bbe98;
case 0x0c0bbe9au: goto P_0c0bbe9a;
case 0x0c0bbe9cu: goto P_0c0bbe9c;
case 0x0c0bbe9eu: goto P_0c0bbe9e;
case 0x0c0bbea0u: goto P_0c0bbea0;
case 0x0c0bbea2u: goto P_0c0bbea2;
case 0x0c0bbea4u: goto P_0c0bbea4;
case 0x0c0bbea6u: goto P_0c0bbea6;
case 0x0c0bbea8u: goto P_0c0bbea8;
case 0x0c0bbeaau: goto P_0c0bbeaa;
case 0x0c0bbeacu: goto P_0c0bbeac;
case 0x0c0bbeaeu: goto P_0c0bbeae;
case 0x0c0bbeb0u: goto P_0c0bbeb0;
case 0x0c0bbeb2u: goto P_0c0bbeb2;
case 0x0c0bbeb4u: goto P_0c0bbeb4;
case 0x0c0bbeb6u: goto P_0c0bbeb6;
case 0x0c0bbeb8u: goto P_0c0bbeb8;
case 0x0c0bbebau: goto P_0c0bbeba;
case 0x0c0bbebcu: goto P_0c0bbebc;
case 0x0c0bbebeu: goto P_0c0bbebe;
case 0x0c0bbec0u: goto P_0c0bbec0;
case 0x0c0bbec2u: goto P_0c0bbec2;
case 0x0c0bbec4u: goto P_0c0bbec4;
case 0x0c0bbec6u: goto P_0c0bbec6;
case 0x0c0bbec8u: goto P_0c0bbec8;
case 0x0c0bbecau: goto P_0c0bbeca;
case 0x0c0bbeccu: goto P_0c0bbecc;
case 0x0c0bbeceu: goto P_0c0bbece;
case 0x0c0bbed0u: goto P_0c0bbed0;
case 0x0c0bbed2u: goto P_0c0bbed2;
case 0x0c0bbed4u: goto P_0c0bbed4;
case 0x0c0bbed6u: goto P_0c0bbed6;
case 0x0c0bbed8u: goto P_0c0bbed8;
case 0x0c0bbedau: goto P_0c0bbeda;
case 0x0c0bbedcu: goto P_0c0bbedc;
case 0x0c0bbedeu: goto P_0c0bbede;
case 0x0c0bbee0u: goto P_0c0bbee0;
case 0x0c0bbee2u: goto P_0c0bbee2;
case 0x0c0bbee4u: goto P_0c0bbee4;
case 0x0c0bbee6u: goto P_0c0bbee6;
case 0x0c0bbee8u: goto P_0c0bbee8;
case 0x0c0bbeeau: goto P_0c0bbeea;
case 0x0c0bbeecu: goto P_0c0bbeec;
case 0x0c0bbeeeu: goto P_0c0bbeee;
case 0x0c0bbef0u: goto P_0c0bbef0;
case 0x0c0bbef2u: goto P_0c0bbef2;
case 0x0c0bbef4u: goto P_0c0bbef4;
case 0x0c0bbef6u: goto P_0c0bbef6;
case 0x0c0bbef8u: goto P_0c0bbef8;
case 0x0c0bbefau: goto P_0c0bbefa;
case 0x0c0bbefcu: goto P_0c0bbefc;
case 0x0c0bbefeu: goto P_0c0bbefe;
case 0x0c0bbf00u: goto P_0c0bbf00;
case 0x0c0bbf02u: goto P_0c0bbf02;
case 0x0c0bbf04u: goto P_0c0bbf04;
case 0x0c0bbf06u: goto P_0c0bbf06;
case 0x0c0bbf08u: goto P_0c0bbf08;
case 0x0c0bbf0au: goto P_0c0bbf0a;
case 0x0c0bbf0cu: goto P_0c0bbf0c;
case 0x0c0bbf0eu: goto P_0c0bbf0e;
case 0x0c0bbf10u: goto P_0c0bbf10;
case 0x0c0bbf12u: goto P_0c0bbf12;
case 0x0c0bbf14u: goto P_0c0bbf14;
case 0x0c0bbf16u: goto P_0c0bbf16;
case 0x0c0bbf18u: goto P_0c0bbf18;
case 0x0c0bbf1au: goto P_0c0bbf1a;
case 0x0c0bbf1cu: goto P_0c0bbf1c;
case 0x0c0bbf1eu: goto P_0c0bbf1e;
case 0x0c0bbf20u: goto P_0c0bbf20;
case 0x0c0bbf22u: goto P_0c0bbf22;
case 0x0c0bbf24u: goto P_0c0bbf24;
case 0x0c0bbf26u: goto P_0c0bbf26;
case 0x0c0bbf28u: goto P_0c0bbf28;
case 0x0c0bbf2au: goto P_0c0bbf2a;
case 0x0c0bbf2cu: goto P_0c0bbf2c;
case 0x0c0bbf2eu: goto P_0c0bbf2e;
case 0x0c0bbf30u: goto P_0c0bbf30;
case 0x0c0bbf32u: goto P_0c0bbf32;
case 0x0c0bbf34u: goto P_0c0bbf34;
case 0x0c0bbf36u: goto P_0c0bbf36;
case 0x0c0bbf38u: goto P_0c0bbf38;
case 0x0c0bbfa8u: goto P_0c0bbfa8;
case 0x0c0bbfaau: goto P_0c0bbfaa;
case 0x0c0bbfacu: goto P_0c0bbfac;
case 0x0c0bbfaeu: goto P_0c0bbfae;
case 0x0c0bbfb0u: goto P_0c0bbfb0;
case 0x0c0bbfb2u: goto P_0c0bbfb2;
case 0x0c0bbfb4u: goto P_0c0bbfb4;
case 0x0c0bbfb6u: goto P_0c0bbfb6;
case 0x0c0bbfb8u: goto P_0c0bbfb8;
case 0x0c0bbfbau: goto P_0c0bbfba;
case 0x0c0bbfbcu: goto P_0c0bbfbc;
case 0x0c0bbfbeu: goto P_0c0bbfbe;
case 0x0c0bbfc0u: goto P_0c0bbfc0;
case 0x0c0bbfc2u: goto P_0c0bbfc2;
case 0x0c0bbfc4u: goto P_0c0bbfc4;
case 0x0c0bbfc6u: goto P_0c0bbfc6;
case 0x0c0bbfc8u: goto P_0c0bbfc8;
case 0x0c0bbfcau: goto P_0c0bbfca;
case 0x0c0bbfccu: goto P_0c0bbfcc;
case 0x0c0bbfceu: goto P_0c0bbfce;
case 0x0c0bbfd0u: goto P_0c0bbfd0;
case 0x0c0bbfd2u: goto P_0c0bbfd2;
case 0x0c0bbfd4u: goto P_0c0bbfd4;
case 0x0c0bbfd6u: goto P_0c0bbfd6;
case 0x0c0bbfd8u: goto P_0c0bbfd8;
case 0x0c0bbfdau: goto P_0c0bbfda;
case 0x0c0bbfdcu: goto P_0c0bbfdc;
case 0x0c0bbfdeu: goto P_0c0bbfde;
case 0x0c0bbfe0u: goto P_0c0bbfe0;
case 0x0c0bbfe2u: goto P_0c0bbfe2;
case 0x0c0bbfe4u: goto P_0c0bbfe4;
case 0x0c0bbfe6u: goto P_0c0bbfe6;
case 0x0c0bbfe8u: goto P_0c0bbfe8;
case 0x0c0bbfeau: goto P_0c0bbfea;
case 0x0c0bbfecu: goto P_0c0bbfec;
case 0x0c0bbfeeu: goto P_0c0bbfee;
case 0x0c0bbff0u: goto P_0c0bbff0;
case 0x0c0bbff2u: goto P_0c0bbff2;
case 0x0c0bbff4u: goto P_0c0bbff4;
case 0x0c0bbff6u: goto P_0c0bbff6;
case 0x0c0bbff8u: goto P_0c0bbff8;
case 0x0c0bbffau: goto P_0c0bbffa;
case 0x0c0bbffcu: goto P_0c0bbffc;
case 0x0c0bbffeu: goto P_0c0bbffe;
case 0x0c0bc000u: goto P_0c0bc000;
case 0x0c0bc002u: goto P_0c0bc002;
case 0x0c0bc004u: goto P_0c0bc004;
case 0x0c0bc006u: goto P_0c0bc006;
case 0x0c0bc008u: goto P_0c0bc008;
case 0x0c0bc00au: goto P_0c0bc00a;
case 0x0c0bc00cu: goto P_0c0bc00c;
case 0x0c0bc00eu: goto P_0c0bc00e;
case 0x0c0bc010u: goto P_0c0bc010;
case 0x0c0bc012u: goto P_0c0bc012;
case 0x0c0bc014u: goto P_0c0bc014;
case 0x0c0bc016u: goto P_0c0bc016;
case 0x0c0bc018u: goto P_0c0bc018;
case 0x0c0bc01au: goto P_0c0bc01a;
case 0x0c0bc01cu: goto P_0c0bc01c;
case 0x0c0bc01eu: goto P_0c0bc01e;
case 0x0c0bc020u: goto P_0c0bc020;
case 0x0c0bc022u: goto P_0c0bc022;
case 0x0c0bc024u: goto P_0c0bc024;
case 0x0c0bc026u: goto P_0c0bc026;
case 0x0c0bc028u: goto P_0c0bc028;
case 0x0c0bc02au: goto P_0c0bc02a;
case 0x0c0bc02cu: goto P_0c0bc02c;
case 0x0c0bc02eu: goto P_0c0bc02e;
case 0x0c0bc030u: goto P_0c0bc030;
case 0x0c0bc032u: goto P_0c0bc032;
case 0x0c0bc034u: goto P_0c0bc034;
case 0x0c0bc036u: goto P_0c0bc036;
case 0x0c0bc038u: goto P_0c0bc038;
case 0x0c0bc03au: goto P_0c0bc03a;
case 0x0c0bc03cu: goto P_0c0bc03c;
case 0x0c0bc03eu: goto P_0c0bc03e;
case 0x0c0bc040u: goto P_0c0bc040;
case 0x0c0bc042u: goto P_0c0bc042;
case 0x0c0bc044u: goto P_0c0bc044;
case 0x0c0bc046u: goto P_0c0bc046;
case 0x0c0bc048u: goto P_0c0bc048;
case 0x0c0bc04au: goto P_0c0bc04a;
case 0x0c0bc04cu: goto P_0c0bc04c;
case 0x0c0bc04eu: goto P_0c0bc04e;
case 0x0c0bc050u: goto P_0c0bc050;
case 0x0c0bc052u: goto P_0c0bc052;
case 0x0c0bc054u: goto P_0c0bc054;
case 0x0c0bc056u: goto P_0c0bc056;
case 0x0c0bc058u: goto P_0c0bc058;
case 0x0c0bc05au: goto P_0c0bc05a;
case 0x0c0bc05cu: goto P_0c0bc05c;
case 0x0c0bc05eu: goto P_0c0bc05e;
case 0x0c0bc060u: goto P_0c0bc060;
case 0x0c0bc062u: goto P_0c0bc062;
case 0x0c0bc064u: goto P_0c0bc064;
case 0x0c0bc066u: goto P_0c0bc066;
case 0x0c0bc068u: goto P_0c0bc068;
case 0x0c0bc06au: goto P_0c0bc06a;
case 0x0c0bc06cu: goto P_0c0bc06c;
case 0x0c0bc06eu: goto P_0c0bc06e;
case 0x0c0bc070u: goto P_0c0bc070;
case 0x0c0bc072u: goto P_0c0bc072;
case 0x0c0bc074u: goto P_0c0bc074;
case 0x0c0bc076u: goto P_0c0bc076;
case 0x0c0bc078u: goto P_0c0bc078;
case 0x0c0bc07au: goto P_0c0bc07a;
case 0x0c0bc07cu: goto P_0c0bc07c;
case 0x0c0bc07eu: goto P_0c0bc07e;
case 0x0c0bc080u: goto P_0c0bc080;
case 0x0c0bc082u: goto P_0c0bc082;
case 0x0c0bc084u: goto P_0c0bc084;
case 0x0c0bc086u: goto P_0c0bc086;
case 0x0c0bc088u: goto P_0c0bc088;
case 0x0c0bc08au: goto P_0c0bc08a;
case 0x0c0bc08cu: goto P_0c0bc08c;
case 0x0c0bc08eu: goto P_0c0bc08e;
case 0x0c0bc090u: goto P_0c0bc090;
case 0x0c0bc092u: goto P_0c0bc092;
case 0x0c0bc094u: goto P_0c0bc094;
case 0x0c0bc096u: goto P_0c0bc096;
case 0x0c0bc098u: goto P_0c0bc098;
case 0x0c0bc09au: goto P_0c0bc09a;
case 0x0c0bc09cu: goto P_0c0bc09c;
case 0x0c0bc09eu: goto P_0c0bc09e;
case 0x0c0bc0a0u: goto P_0c0bc0a0;
case 0x0c0bc0a2u: goto P_0c0bc0a2;
case 0x0c0bc0a4u: goto P_0c0bc0a4;
case 0x0c0bc0a6u: goto P_0c0bc0a6;
case 0x0c0bc0a8u: goto P_0c0bc0a8;
case 0x0c0bc0aau: goto P_0c0bc0aa;
case 0x0c0bc0acu: goto P_0c0bc0ac;
case 0x0c0bc0aeu: goto P_0c0bc0ae;
case 0x0c0bc0b0u: goto P_0c0bc0b0;
case 0x0c0bc0b2u: goto P_0c0bc0b2;
case 0x0c0bc0b4u: goto P_0c0bc0b4;
case 0x0c0bc0b6u: goto P_0c0bc0b6;
case 0x0c0bc0b8u: goto P_0c0bc0b8;
case 0x0c0bc0bau: goto P_0c0bc0ba;
case 0x0c0bc0bcu: goto P_0c0bc0bc;
case 0x0c0bc0beu: goto P_0c0bc0be;
case 0x0c0bc0c0u: goto P_0c0bc0c0;
case 0x0c0bc0c2u: goto P_0c0bc0c2;
case 0x0c0bc0c4u: goto P_0c0bc0c4;
case 0x0c0bc0c6u: goto P_0c0bc0c6;
case 0x0c0bc0c8u: goto P_0c0bc0c8;
case 0x0c0bc0cau: goto P_0c0bc0ca;
case 0x0c0bc0ccu: goto P_0c0bc0cc;
case 0x0c0bc0ceu: goto P_0c0bc0ce;
case 0x0c0bc0d0u: goto P_0c0bc0d0;
case 0x0c0bc0d2u: goto P_0c0bc0d2;
case 0x0c0bc0d4u: goto P_0c0bc0d4;
case 0x0c0bc0d6u: goto P_0c0bc0d6;
case 0x0c0bc0d8u: goto P_0c0bc0d8;
case 0x0c0bc0dau: goto P_0c0bc0da;
case 0x0c0bc0dcu: goto P_0c0bc0dc;
case 0x0c0bc0deu: goto P_0c0bc0de;
case 0x0c0bc0e0u: goto P_0c0bc0e0;
case 0x0c0bc0e2u: goto P_0c0bc0e2;
case 0x0c0bc0e4u: goto P_0c0bc0e4;
case 0x0c0bc0e6u: goto P_0c0bc0e6;
case 0x0c0bc0e8u: goto P_0c0bc0e8;
case 0x0c0bc0eau: goto P_0c0bc0ea;
case 0x0c0bc0ecu: goto P_0c0bc0ec;
case 0x0c0bc0eeu: goto P_0c0bc0ee;
case 0x0c0bc0f0u: goto P_0c0bc0f0;
case 0x0c0bc0f2u: goto P_0c0bc0f2;
case 0x0c0bc0f4u: goto P_0c0bc0f4;
case 0x0c0bc0f6u: goto P_0c0bc0f6;
case 0x0c0bc0f8u: goto P_0c0bc0f8;
case 0x0c0bc0fau: goto P_0c0bc0fa;
case 0x0c0bc0fcu: goto P_0c0bc0fc;
case 0x0c0bc0feu: goto P_0c0bc0fe;
case 0x0c0bc100u: goto P_0c0bc100;
case 0x0c0bc17au: goto P_0c0bc17a;
case 0x0c0bc17cu: goto P_0c0bc17c;
case 0x0c0bc17eu: goto P_0c0bc17e;
case 0x0c0bc180u: goto P_0c0bc180;
case 0x0c0bc182u: goto P_0c0bc182;
case 0x0c0bc184u: goto P_0c0bc184;
case 0x0c0bc186u: goto P_0c0bc186;
case 0x0c0bc188u: goto P_0c0bc188;
case 0x0c0bc18au: goto P_0c0bc18a;
case 0x0c0bc18cu: goto P_0c0bc18c;
case 0x0c0bc18eu: goto P_0c0bc18e;
case 0x0c0bc190u: goto P_0c0bc190;
case 0x0c0bc192u: goto P_0c0bc192;
case 0x0c0bc194u: goto P_0c0bc194;
case 0x0c0bc196u: goto P_0c0bc196;
case 0x0c0bc198u: goto P_0c0bc198;
case 0x0c0bc19au: goto P_0c0bc19a;
case 0x0c0bc19cu: goto P_0c0bc19c;
case 0x0c0bc19eu: goto P_0c0bc19e;
case 0x0c0bc1a0u: goto P_0c0bc1a0;
case 0x0c0bc1a2u: goto P_0c0bc1a2;
case 0x0c0bc1a4u: goto P_0c0bc1a4;
case 0x0c0bc1a6u: goto P_0c0bc1a6;
case 0x0c0bc1a8u: goto P_0c0bc1a8;
case 0x0c0bc1aau: goto P_0c0bc1aa;
case 0x0c0bc1acu: goto P_0c0bc1ac;
case 0x0c0bc1aeu: goto P_0c0bc1ae;
case 0x0c0bc1b0u: goto P_0c0bc1b0;
case 0x0c0bc1b2u: goto P_0c0bc1b2;
case 0x0c0bc1b4u: goto P_0c0bc1b4;
case 0x0c0bc1b6u: goto P_0c0bc1b6;
case 0x0c0bc1b8u: goto P_0c0bc1b8;
case 0x0c0bc1bau: goto P_0c0bc1ba;
case 0x0c0bc1bcu: goto P_0c0bc1bc;
case 0x0c0bc1beu: goto P_0c0bc1be;
case 0x0c0bc1c0u: goto P_0c0bc1c0;
case 0x0c0bc1c2u: goto P_0c0bc1c2;
case 0x0c0bc1c4u: goto P_0c0bc1c4;
case 0x0c0bc1c6u: goto P_0c0bc1c6;
case 0x0c0bc1c8u: goto P_0c0bc1c8;
case 0x0c0bc1cau: goto P_0c0bc1ca;
case 0x0c0bc1ccu: goto P_0c0bc1cc;
case 0x0c0bc1ceu: goto P_0c0bc1ce;
case 0x0c0bc1d0u: goto P_0c0bc1d0;
case 0x0c0bc1d2u: goto P_0c0bc1d2;
case 0x0c0bc1d4u: goto P_0c0bc1d4;
case 0x0c0bc1d6u: goto P_0c0bc1d6;
case 0x0c0bc1d8u: goto P_0c0bc1d8;
case 0x0c0bc1dau: goto P_0c0bc1da;
case 0x0c0bc1dcu: goto P_0c0bc1dc;
case 0x0c0bc1deu: goto P_0c0bc1de;
case 0x0c0bc1e0u: goto P_0c0bc1e0;
case 0x0c0bc1e2u: goto P_0c0bc1e2;
case 0x0c0bc1e4u: goto P_0c0bc1e4;
case 0x0c0bc1e6u: goto P_0c0bc1e6;
case 0x0c0bc1e8u: goto P_0c0bc1e8;
case 0x0c0bc1eau: goto P_0c0bc1ea;
case 0x0c0bc1ecu: goto P_0c0bc1ec;
case 0x0c0bc1eeu: goto P_0c0bc1ee;
case 0x0c0bc1f0u: goto P_0c0bc1f0;
case 0x0c0bc1f2u: goto P_0c0bc1f2;
case 0x0c0bc1f4u: goto P_0c0bc1f4;
case 0x0c0bc1f6u: goto P_0c0bc1f6;
case 0x0c0bc1f8u: goto P_0c0bc1f8;
case 0x0c0bc1fau: goto P_0c0bc1fa;
case 0x0c0bc1fcu: goto P_0c0bc1fc;
case 0x0c0bc1feu: goto P_0c0bc1fe;
case 0x0c0bc200u: goto P_0c0bc200;
case 0x0c0bc202u: goto P_0c0bc202;
case 0x0c0bc204u: goto P_0c0bc204;
case 0x0c0bc206u: goto P_0c0bc206;
case 0x0c0bc208u: goto P_0c0bc208;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0bbdd6: /* original 2fe6, guest PC 0x0c0bbdd6 */
if(!s->budget--) { s->failed_pc=0x0c0bbdd6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bbdd8;
P_0c0bbdd8: /* original 2fd6, guest PC 0x0c0bbdd8 */
if(!s->budget--) { s->failed_pc=0x0c0bbdd8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bbdda;
P_0c0bbdda: /* original 2fc6, guest PC 0x0c0bbdda */
if(!s->budget--) { s->failed_pc=0x0c0bbddau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bbddc;
P_0c0bbddc: /* original 2fb6, guest PC 0x0c0bbddc */
if(!s->budget--) { s->failed_pc=0x0c0bbddcu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bbdde;
P_0c0bbdde: /* original 2fa6, guest PC 0x0c0bbdde */
if(!s->budget--) { s->failed_pc=0x0c0bbddeu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bbde0;
P_0c0bbde0: /* original 2f96, guest PC 0x0c0bbde0 */
if(!s->budget--) { s->failed_pc=0x0c0bbde0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bbde2;
P_0c0bbde2: /* original 4f22, guest PC 0x0c0bbde2 */
if(!s->budget--) { s->failed_pc=0x0c0bbde2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0bbde4;
P_0c0bbde4: /* original 5d44, guest PC 0x0c0bbde4 */
if(!s->budget--) { s->failed_pc=0x0c0bbde4u; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0bbde6;
P_0c0bbde6: /* original 94a8, guest PC 0x0c0bbde6 */
if(!s->budget--) { s->failed_pc=0x0c0bbde6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf3au,2);
goto P_0c0bbde8;
P_0c0bbde8: /* original de6e, guest PC 0x0c0bbde8 */
if(!s->budget--) { s->failed_pc=0x0c0bbde8u; return 0; }
r[14]=read(ram,0x0c0bbfa4u,4);
goto P_0c0bbdea;
P_0c0bbdea: /* original 7ff8, guest PC 0x0c0bbdea */
if(!s->budget--) { s->failed_pc=0x0c0bbdeau; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0bbdec;
P_0c0bbdec: /* original 4e0b, guest PC 0x0c0bbdec */
if(!s->budget--) { s->failed_pc=0x0c0bbdecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbdf0u;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbdf0u) { target=s->pc; goto dispatch; }
goto P_0c0bbdf0;
P_0c0bbdee: /* original 65d2, guest PC 0x0c0bbdee */
if(!s->budget--) { s->failed_pc=0x0c0bbdeeu; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0bbdf0;
P_0c0bbdf0: /* original 94a4, guest PC 0x0c0bbdf0 */
if(!s->budget--) { s->failed_pc=0x0c0bbdf0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf3cu,2);
goto P_0c0bbdf2;
P_0c0bbdf2: /* original 4e0b, guest PC 0x0c0bbdf2 */
if(!s->budget--) { s->failed_pc=0x0c0bbdf2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbdf6u;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbdf6u) { target=s->pc; goto dispatch; }
goto P_0c0bbdf6;
P_0c0bbdf4: /* original 55d1, guest PC 0x0c0bbdf4 */
if(!s->budget--) { s->failed_pc=0x0c0bbdf4u; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0bbdf6;
P_0c0bbdf6: /* original 94a2, guest PC 0x0c0bbdf6 */
if(!s->budget--) { s->failed_pc=0x0c0bbdf6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf3eu,2);
goto P_0c0bbdf8;
P_0c0bbdf8: /* original 4e0b, guest PC 0x0c0bbdf8 */
if(!s->budget--) { s->failed_pc=0x0c0bbdf8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbdfcu;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbdfcu) { target=s->pc; goto dispatch; }
goto P_0c0bbdfc;
P_0c0bbdfa: /* original 55d2, guest PC 0x0c0bbdfa */
if(!s->budget--) { s->failed_pc=0x0c0bbdfau; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0bbdfc;
P_0c0bbdfc: /* original 94a0, guest PC 0x0c0bbdfc */
if(!s->budget--) { s->failed_pc=0x0c0bbdfcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf40u,2);
goto P_0c0bbdfe;
P_0c0bbdfe: /* original 4e0b, guest PC 0x0c0bbdfe */
if(!s->budget--) { s->failed_pc=0x0c0bbdfeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe02u;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe02u) { target=s->pc; goto dispatch; }
goto P_0c0bbe02;
P_0c0bbe00: /* original 55d3, guest PC 0x0c0bbe00 */
if(!s->budget--) { s->failed_pc=0x0c0bbe00u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0bbe02;
P_0c0bbe02: /* original 949e, guest PC 0x0c0bbe02 */
if(!s->budget--) { s->failed_pc=0x0c0bbe02u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf42u,2);
goto P_0c0bbe04;
P_0c0bbe04: /* original 4e0b, guest PC 0x0c0bbe04 */
if(!s->budget--) { s->failed_pc=0x0c0bbe04u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe08u;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe08u) { target=s->pc; goto dispatch; }
goto P_0c0bbe08;
P_0c0bbe06: /* original 55d4, guest PC 0x0c0bbe06 */
if(!s->budget--) { s->failed_pc=0x0c0bbe06u; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0bbe08;
P_0c0bbe08: /* original 949c, guest PC 0x0c0bbe08 */
if(!s->budget--) { s->failed_pc=0x0c0bbe08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf44u,2);
goto P_0c0bbe0a;
P_0c0bbe0a: /* original 4e0b, guest PC 0x0c0bbe0a */
if(!s->budget--) { s->failed_pc=0x0c0bbe0au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe0eu;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe0eu) { target=s->pc; goto dispatch; }
goto P_0c0bbe0e;
P_0c0bbe0c: /* original 55d5, guest PC 0x0c0bbe0c */
if(!s->budget--) { s->failed_pc=0x0c0bbe0cu; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0bbe0e;
P_0c0bbe0e: /* original 949a, guest PC 0x0c0bbe0e */
if(!s->budget--) { s->failed_pc=0x0c0bbe0eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf46u,2);
goto P_0c0bbe10;
P_0c0bbe10: /* original 4e0b, guest PC 0x0c0bbe10 */
if(!s->budget--) { s->failed_pc=0x0c0bbe10u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe14u;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe14u) { target=s->pc; goto dispatch; }
goto P_0c0bbe14;
P_0c0bbe12: /* original 55d6, guest PC 0x0c0bbe12 */
if(!s->budget--) { s->failed_pc=0x0c0bbe12u; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0bbe14;
P_0c0bbe14: /* original 9498, guest PC 0x0c0bbe14 */
if(!s->budget--) { s->failed_pc=0x0c0bbe14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf48u,2);
goto P_0c0bbe16;
P_0c0bbe16: /* original 4e0b, guest PC 0x0c0bbe16 */
if(!s->budget--) { s->failed_pc=0x0c0bbe16u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe1au;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe1au) { target=s->pc; goto dispatch; }
goto P_0c0bbe1a;
P_0c0bbe18: /* original 55d7, guest PC 0x0c0bbe18 */
if(!s->budget--) { s->failed_pc=0x0c0bbe18u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0bbe1a;
P_0c0bbe1a: /* original 9496, guest PC 0x0c0bbe1a */
if(!s->budget--) { s->failed_pc=0x0c0bbe1au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf4au,2);
goto P_0c0bbe1c;
P_0c0bbe1c: /* original 4e0b, guest PC 0x0c0bbe1c */
if(!s->budget--) { s->failed_pc=0x0c0bbe1cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe20u;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe20u) { target=s->pc; goto dispatch; }
goto P_0c0bbe20;
P_0c0bbe1e: /* original 55d8, guest PC 0x0c0bbe1e */
if(!s->budget--) { s->failed_pc=0x0c0bbe1eu; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0bbe20;
P_0c0bbe20: /* original 9494, guest PC 0x0c0bbe20 */
if(!s->budget--) { s->failed_pc=0x0c0bbe20u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf4cu,2);
goto P_0c0bbe22;
P_0c0bbe22: /* original 4e0b, guest PC 0x0c0bbe22 */
if(!s->budget--) { s->failed_pc=0x0c0bbe22u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe26u;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe26u) { target=s->pc; goto dispatch; }
goto P_0c0bbe26;
P_0c0bbe24: /* original 55d9, guest PC 0x0c0bbe24 */
if(!s->budget--) { s->failed_pc=0x0c0bbe24u; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0bbe26;
P_0c0bbe26: /* original 9492, guest PC 0x0c0bbe26 */
if(!s->budget--) { s->failed_pc=0x0c0bbe26u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf4eu,2);
goto P_0c0bbe28;
P_0c0bbe28: /* original 4e0b, guest PC 0x0c0bbe28 */
if(!s->budget--) { s->failed_pc=0x0c0bbe28u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe2cu;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe2cu) { target=s->pc; goto dispatch; }
goto P_0c0bbe2c;
P_0c0bbe2a: /* original 55da, guest PC 0x0c0bbe2a */
if(!s->budget--) { s->failed_pc=0x0c0bbe2au; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0bbe2c;
P_0c0bbe2c: /* original 9490, guest PC 0x0c0bbe2c */
if(!s->budget--) { s->failed_pc=0x0c0bbe2cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf50u,2);
goto P_0c0bbe2e;
P_0c0bbe2e: /* original 4e0b, guest PC 0x0c0bbe2e */
if(!s->budget--) { s->failed_pc=0x0c0bbe2eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe32u;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe32u) { target=s->pc; goto dispatch; }
goto P_0c0bbe32;
P_0c0bbe30: /* original 55db, guest PC 0x0c0bbe30 */
if(!s->budget--) { s->failed_pc=0x0c0bbe30u; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0bbe32;
P_0c0bbe32: /* original 948e, guest PC 0x0c0bbe32 */
if(!s->budget--) { s->failed_pc=0x0c0bbe32u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf52u,2);
goto P_0c0bbe34;
P_0c0bbe34: /* original 4e0b, guest PC 0x0c0bbe34 */
if(!s->budget--) { s->failed_pc=0x0c0bbe34u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe38u;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe38u) { target=s->pc; goto dispatch; }
goto P_0c0bbe38;
P_0c0bbe36: /* original 55dc, guest PC 0x0c0bbe36 */
if(!s->budget--) { s->failed_pc=0x0c0bbe36u; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0bbe38;
P_0c0bbe38: /* original 948c, guest PC 0x0c0bbe38 */
if(!s->budget--) { s->failed_pc=0x0c0bbe38u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf54u,2);
goto P_0c0bbe3a;
P_0c0bbe3a: /* original 4e0b, guest PC 0x0c0bbe3a */
if(!s->budget--) { s->failed_pc=0x0c0bbe3au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe3eu;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe3eu) { target=s->pc; goto dispatch; }
goto P_0c0bbe3e;
P_0c0bbe3c: /* original 55dd, guest PC 0x0c0bbe3c */
if(!s->budget--) { s->failed_pc=0x0c0bbe3cu; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0bbe3e;
P_0c0bbe3e: /* original 948a, guest PC 0x0c0bbe3e */
if(!s->budget--) { s->failed_pc=0x0c0bbe3eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf56u,2);
goto P_0c0bbe40;
P_0c0bbe40: /* original 4e0b, guest PC 0x0c0bbe40 */
if(!s->budget--) { s->failed_pc=0x0c0bbe40u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe44u;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe44u) { target=s->pc; goto dispatch; }
goto P_0c0bbe44;
P_0c0bbe42: /* original 55de, guest PC 0x0c0bbe42 */
if(!s->budget--) { s->failed_pc=0x0c0bbe42u; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0bbe44;
P_0c0bbe44: /* original 9488, guest PC 0x0c0bbe44 */
if(!s->budget--) { s->failed_pc=0x0c0bbe44u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf58u,2);
goto P_0c0bbe46;
P_0c0bbe46: /* original 4e0b, guest PC 0x0c0bbe46 */
if(!s->budget--) { s->failed_pc=0x0c0bbe46u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe4au;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe4au) { target=s->pc; goto dispatch; }
goto P_0c0bbe4a;
P_0c0bbe48: /* original 55df, guest PC 0x0c0bbe48 */
if(!s->budget--) { s->failed_pc=0x0c0bbe48u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0bbe4a;
P_0c0bbe4a: /* original 9486, guest PC 0x0c0bbe4a */
if(!s->budget--) { s->failed_pc=0x0c0bbe4au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf5au,2);
goto P_0c0bbe4c;
P_0c0bbe4c: /* original e040, guest PC 0x0c0bbe4c */
if(!s->budget--) { s->failed_pc=0x0c0bbe4cu; return 0; }
r[0]=0x00000040u;
goto P_0c0bbe4e;
P_0c0bbe4e: /* original 4e0b, guest PC 0x0c0bbe4e */
if(!s->budget--) { s->failed_pc=0x0c0bbe4eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe52u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe52u) { target=s->pc; goto dispatch; }
goto P_0c0bbe52;
P_0c0bbe50: /* original 05de, guest PC 0x0c0bbe50 */
if(!s->budget--) { s->failed_pc=0x0c0bbe50u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbe52;
P_0c0bbe52: /* original 9483, guest PC 0x0c0bbe52 */
if(!s->budget--) { s->failed_pc=0x0c0bbe52u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf5cu,2);
goto P_0c0bbe54;
P_0c0bbe54: /* original e044, guest PC 0x0c0bbe54 */
if(!s->budget--) { s->failed_pc=0x0c0bbe54u; return 0; }
r[0]=0x00000044u;
goto P_0c0bbe56;
P_0c0bbe56: /* original 4e0b, guest PC 0x0c0bbe56 */
if(!s->budget--) { s->failed_pc=0x0c0bbe56u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe5au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe5au) { target=s->pc; goto dispatch; }
goto P_0c0bbe5a;
P_0c0bbe58: /* original 05de, guest PC 0x0c0bbe58 */
if(!s->budget--) { s->failed_pc=0x0c0bbe58u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbe5a;
P_0c0bbe5a: /* original 9480, guest PC 0x0c0bbe5a */
if(!s->budget--) { s->failed_pc=0x0c0bbe5au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf5eu,2);
goto P_0c0bbe5c;
P_0c0bbe5c: /* original e048, guest PC 0x0c0bbe5c */
if(!s->budget--) { s->failed_pc=0x0c0bbe5cu; return 0; }
r[0]=0x00000048u;
goto P_0c0bbe5e;
P_0c0bbe5e: /* original 4e0b, guest PC 0x0c0bbe5e */
if(!s->budget--) { s->failed_pc=0x0c0bbe5eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe62u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe62u) { target=s->pc; goto dispatch; }
goto P_0c0bbe62;
P_0c0bbe60: /* original 05de, guest PC 0x0c0bbe60 */
if(!s->budget--) { s->failed_pc=0x0c0bbe60u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbe62;
P_0c0bbe62: /* original 947d, guest PC 0x0c0bbe62 */
if(!s->budget--) { s->failed_pc=0x0c0bbe62u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf60u,2);
goto P_0c0bbe64;
P_0c0bbe64: /* original e04c, guest PC 0x0c0bbe64 */
if(!s->budget--) { s->failed_pc=0x0c0bbe64u; return 0; }
r[0]=0x0000004cu;
goto P_0c0bbe66;
P_0c0bbe66: /* original 4e0b, guest PC 0x0c0bbe66 */
if(!s->budget--) { s->failed_pc=0x0c0bbe66u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe6au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe6au) { target=s->pc; goto dispatch; }
goto P_0c0bbe6a;
P_0c0bbe68: /* original 05de, guest PC 0x0c0bbe68 */
if(!s->budget--) { s->failed_pc=0x0c0bbe68u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbe6a;
P_0c0bbe6a: /* original 947a, guest PC 0x0c0bbe6a */
if(!s->budget--) { s->failed_pc=0x0c0bbe6au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf62u,2);
goto P_0c0bbe6c;
P_0c0bbe6c: /* original e050, guest PC 0x0c0bbe6c */
if(!s->budget--) { s->failed_pc=0x0c0bbe6cu; return 0; }
r[0]=0x00000050u;
goto P_0c0bbe6e;
P_0c0bbe6e: /* original 4e0b, guest PC 0x0c0bbe6e */
if(!s->budget--) { s->failed_pc=0x0c0bbe6eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe72u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe72u) { target=s->pc; goto dispatch; }
goto P_0c0bbe72;
P_0c0bbe70: /* original 05de, guest PC 0x0c0bbe70 */
if(!s->budget--) { s->failed_pc=0x0c0bbe70u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbe72;
P_0c0bbe72: /* original 9477, guest PC 0x0c0bbe72 */
if(!s->budget--) { s->failed_pc=0x0c0bbe72u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf64u,2);
goto P_0c0bbe74;
P_0c0bbe74: /* original e054, guest PC 0x0c0bbe74 */
if(!s->budget--) { s->failed_pc=0x0c0bbe74u; return 0; }
r[0]=0x00000054u;
goto P_0c0bbe76;
P_0c0bbe76: /* original 4e0b, guest PC 0x0c0bbe76 */
if(!s->budget--) { s->failed_pc=0x0c0bbe76u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe7au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe7au) { target=s->pc; goto dispatch; }
goto P_0c0bbe7a;
P_0c0bbe78: /* original 05de, guest PC 0x0c0bbe78 */
if(!s->budget--) { s->failed_pc=0x0c0bbe78u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbe7a;
P_0c0bbe7a: /* original 9474, guest PC 0x0c0bbe7a */
if(!s->budget--) { s->failed_pc=0x0c0bbe7au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf66u,2);
goto P_0c0bbe7c;
P_0c0bbe7c: /* original e058, guest PC 0x0c0bbe7c */
if(!s->budget--) { s->failed_pc=0x0c0bbe7cu; return 0; }
r[0]=0x00000058u;
goto P_0c0bbe7e;
P_0c0bbe7e: /* original 4e0b, guest PC 0x0c0bbe7e */
if(!s->budget--) { s->failed_pc=0x0c0bbe7eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe82u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe82u) { target=s->pc; goto dispatch; }
goto P_0c0bbe82;
P_0c0bbe80: /* original 05de, guest PC 0x0c0bbe80 */
if(!s->budget--) { s->failed_pc=0x0c0bbe80u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbe82;
P_0c0bbe82: /* original 9471, guest PC 0x0c0bbe82 */
if(!s->budget--) { s->failed_pc=0x0c0bbe82u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf68u,2);
goto P_0c0bbe84;
P_0c0bbe84: /* original e05c, guest PC 0x0c0bbe84 */
if(!s->budget--) { s->failed_pc=0x0c0bbe84u; return 0; }
r[0]=0x0000005cu;
goto P_0c0bbe86;
P_0c0bbe86: /* original 4e0b, guest PC 0x0c0bbe86 */
if(!s->budget--) { s->failed_pc=0x0c0bbe86u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe8au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe8au) { target=s->pc; goto dispatch; }
goto P_0c0bbe8a;
P_0c0bbe88: /* original 05de, guest PC 0x0c0bbe88 */
if(!s->budget--) { s->failed_pc=0x0c0bbe88u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbe8a;
P_0c0bbe8a: /* original 946e, guest PC 0x0c0bbe8a */
if(!s->budget--) { s->failed_pc=0x0c0bbe8au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf6au,2);
goto P_0c0bbe8c;
P_0c0bbe8c: /* original e060, guest PC 0x0c0bbe8c */
if(!s->budget--) { s->failed_pc=0x0c0bbe8cu; return 0; }
r[0]=0x00000060u;
goto P_0c0bbe8e;
P_0c0bbe8e: /* original 4e0b, guest PC 0x0c0bbe8e */
if(!s->budget--) { s->failed_pc=0x0c0bbe8eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe92u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe92u) { target=s->pc; goto dispatch; }
goto P_0c0bbe92;
P_0c0bbe90: /* original 05de, guest PC 0x0c0bbe90 */
if(!s->budget--) { s->failed_pc=0x0c0bbe90u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbe92;
P_0c0bbe92: /* original 946b, guest PC 0x0c0bbe92 */
if(!s->budget--) { s->failed_pc=0x0c0bbe92u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf6cu,2);
goto P_0c0bbe94;
P_0c0bbe94: /* original e064, guest PC 0x0c0bbe94 */
if(!s->budget--) { s->failed_pc=0x0c0bbe94u; return 0; }
r[0]=0x00000064u;
goto P_0c0bbe96;
P_0c0bbe96: /* original 4e0b, guest PC 0x0c0bbe96 */
if(!s->budget--) { s->failed_pc=0x0c0bbe96u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbe9au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbe9au) { target=s->pc; goto dispatch; }
goto P_0c0bbe9a;
P_0c0bbe98: /* original 05de, guest PC 0x0c0bbe98 */
if(!s->budget--) { s->failed_pc=0x0c0bbe98u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbe9a;
P_0c0bbe9a: /* original 9468, guest PC 0x0c0bbe9a */
if(!s->budget--) { s->failed_pc=0x0c0bbe9au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf6eu,2);
goto P_0c0bbe9c;
P_0c0bbe9c: /* original e068, guest PC 0x0c0bbe9c */
if(!s->budget--) { s->failed_pc=0x0c0bbe9cu; return 0; }
r[0]=0x00000068u;
goto P_0c0bbe9e;
P_0c0bbe9e: /* original 4e0b, guest PC 0x0c0bbe9e */
if(!s->budget--) { s->failed_pc=0x0c0bbe9eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbea2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbea2u) { target=s->pc; goto dispatch; }
goto P_0c0bbea2;
P_0c0bbea0: /* original 05de, guest PC 0x0c0bbea0 */
if(!s->budget--) { s->failed_pc=0x0c0bbea0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbea2;
P_0c0bbea2: /* original 9465, guest PC 0x0c0bbea2 */
if(!s->budget--) { s->failed_pc=0x0c0bbea2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf70u,2);
goto P_0c0bbea4;
P_0c0bbea4: /* original e06c, guest PC 0x0c0bbea4 */
if(!s->budget--) { s->failed_pc=0x0c0bbea4u; return 0; }
r[0]=0x0000006cu;
goto P_0c0bbea6;
P_0c0bbea6: /* original 4e0b, guest PC 0x0c0bbea6 */
if(!s->budget--) { s->failed_pc=0x0c0bbea6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbeaau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbeaau) { target=s->pc; goto dispatch; }
goto P_0c0bbeaa;
P_0c0bbea8: /* original 05de, guest PC 0x0c0bbea8 */
if(!s->budget--) { s->failed_pc=0x0c0bbea8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbeaa;
P_0c0bbeaa: /* original 9462, guest PC 0x0c0bbeaa */
if(!s->budget--) { s->failed_pc=0x0c0bbeaau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf72u,2);
goto P_0c0bbeac;
P_0c0bbeac: /* original e070, guest PC 0x0c0bbeac */
if(!s->budget--) { s->failed_pc=0x0c0bbeacu; return 0; }
r[0]=0x00000070u;
goto P_0c0bbeae;
P_0c0bbeae: /* original 4e0b, guest PC 0x0c0bbeae */
if(!s->budget--) { s->failed_pc=0x0c0bbeaeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbeb2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbeb2u) { target=s->pc; goto dispatch; }
goto P_0c0bbeb2;
P_0c0bbeb0: /* original 05de, guest PC 0x0c0bbeb0 */
if(!s->budget--) { s->failed_pc=0x0c0bbeb0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbeb2;
P_0c0bbeb2: /* original 945f, guest PC 0x0c0bbeb2 */
if(!s->budget--) { s->failed_pc=0x0c0bbeb2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf74u,2);
goto P_0c0bbeb4;
P_0c0bbeb4: /* original e074, guest PC 0x0c0bbeb4 */
if(!s->budget--) { s->failed_pc=0x0c0bbeb4u; return 0; }
r[0]=0x00000074u;
goto P_0c0bbeb6;
P_0c0bbeb6: /* original 4e0b, guest PC 0x0c0bbeb6 */
if(!s->budget--) { s->failed_pc=0x0c0bbeb6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbebau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbebau) { target=s->pc; goto dispatch; }
goto P_0c0bbeba;
P_0c0bbeb8: /* original 05de, guest PC 0x0c0bbeb8 */
if(!s->budget--) { s->failed_pc=0x0c0bbeb8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbeba;
P_0c0bbeba: /* original 945c, guest PC 0x0c0bbeba */
if(!s->budget--) { s->failed_pc=0x0c0bbebau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf76u,2);
goto P_0c0bbebc;
P_0c0bbebc: /* original e078, guest PC 0x0c0bbebc */
if(!s->budget--) { s->failed_pc=0x0c0bbebcu; return 0; }
r[0]=0x00000078u;
goto P_0c0bbebe;
P_0c0bbebe: /* original 4e0b, guest PC 0x0c0bbebe */
if(!s->budget--) { s->failed_pc=0x0c0bbebeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbec2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbec2u) { target=s->pc; goto dispatch; }
goto P_0c0bbec2;
P_0c0bbec0: /* original 05de, guest PC 0x0c0bbec0 */
if(!s->budget--) { s->failed_pc=0x0c0bbec0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbec2;
P_0c0bbec2: /* original 9459, guest PC 0x0c0bbec2 */
if(!s->budget--) { s->failed_pc=0x0c0bbec2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf78u,2);
goto P_0c0bbec4;
P_0c0bbec4: /* original e07c, guest PC 0x0c0bbec4 */
if(!s->budget--) { s->failed_pc=0x0c0bbec4u; return 0; }
r[0]=0x0000007cu;
goto P_0c0bbec6;
P_0c0bbec6: /* original 4e0b, guest PC 0x0c0bbec6 */
if(!s->budget--) { s->failed_pc=0x0c0bbec6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbecau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbecau) { target=s->pc; goto dispatch; }
goto P_0c0bbeca;
P_0c0bbec8: /* original 05de, guest PC 0x0c0bbec8 */
if(!s->budget--) { s->failed_pc=0x0c0bbec8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbeca;
P_0c0bbeca: /* original 9457, guest PC 0x0c0bbeca */
if(!s->budget--) { s->failed_pc=0x0c0bbecau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf7cu,2);
goto P_0c0bbecc;
P_0c0bbecc: /* original 9055, guest PC 0x0c0bbecc */
if(!s->budget--) { s->failed_pc=0x0c0bbeccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf7au,2);
goto P_0c0bbece;
P_0c0bbece: /* original 4e0b, guest PC 0x0c0bbece */
if(!s->budget--) { s->failed_pc=0x0c0bbeceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbed2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbed2u) { target=s->pc; goto dispatch; }
goto P_0c0bbed2;
P_0c0bbed0: /* original 05de, guest PC 0x0c0bbed0 */
if(!s->budget--) { s->failed_pc=0x0c0bbed0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbed2;
P_0c0bbed2: /* original 9554, guest PC 0x0c0bbed2 */
if(!s->budget--) { s->failed_pc=0x0c0bbed2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf7eu,2);
goto P_0c0bbed4;
P_0c0bbed4: /* original 35dc, guest PC 0x0c0bbed4 */
if(!s->budget--) { s->failed_pc=0x0c0bbed4u; return 0; }
r[5]+=r[13];
goto P_0c0bbed6;
P_0c0bbed6: /* original 2f52, guest PC 0x0c0bbed6 */
if(!s->budget--) { s->failed_pc=0x0c0bbed6u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bbed8;
P_0c0bbed8: /* original 9452, guest PC 0x0c0bbed8 */
if(!s->budget--) { s->failed_pc=0x0c0bbed8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf80u,2);
goto P_0c0bbeda;
P_0c0bbeda: /* original 4e0b, guest PC 0x0c0bbeda */
if(!s->budget--) { s->failed_pc=0x0c0bbedau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbedeu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbedeu) { target=s->pc; goto dispatch; }
goto P_0c0bbede;
P_0c0bbedc: /* original 6552, guest PC 0x0c0bbedc */
if(!s->budget--) { s->failed_pc=0x0c0bbedcu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bbede;
P_0c0bbede: /* original 9550, guest PC 0x0c0bbede */
if(!s->budget--) { s->failed_pc=0x0c0bbedeu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf82u,2);
goto P_0c0bbee0;
P_0c0bbee0: /* original 35dc, guest PC 0x0c0bbee0 */
if(!s->budget--) { s->failed_pc=0x0c0bbee0u; return 0; }
r[5]+=r[13];
goto P_0c0bbee2;
P_0c0bbee2: /* original 1f51, guest PC 0x0c0bbee2 */
if(!s->budget--) { s->failed_pc=0x0c0bbee2u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0bbee4;
P_0c0bbee4: /* original 944e, guest PC 0x0c0bbee4 */
if(!s->budget--) { s->failed_pc=0x0c0bbee4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf84u,2);
goto P_0c0bbee6;
P_0c0bbee6: /* original 4e0b, guest PC 0x0c0bbee6 */
if(!s->budget--) { s->failed_pc=0x0c0bbee6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbeeau;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbeeau) { target=s->pc; goto dispatch; }
goto P_0c0bbeea;
P_0c0bbee8: /* original 6552, guest PC 0x0c0bbee8 */
if(!s->budget--) { s->failed_pc=0x0c0bbee8u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bbeea;
P_0c0bbeea: /* original 944d, guest PC 0x0c0bbeea */
if(!s->budget--) { s->failed_pc=0x0c0bbeeau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf88u,2);
goto P_0c0bbeec;
P_0c0bbeec: /* original 904b, guest PC 0x0c0bbeec */
if(!s->budget--) { s->failed_pc=0x0c0bbeecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf86u,2);
goto P_0c0bbeee;
P_0c0bbeee: /* original 4e0b, guest PC 0x0c0bbeee */
if(!s->budget--) { s->failed_pc=0x0c0bbeeeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbef2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbef2u) { target=s->pc; goto dispatch; }
goto P_0c0bbef2;
P_0c0bbef0: /* original 05de, guest PC 0x0c0bbef0 */
if(!s->budget--) { s->failed_pc=0x0c0bbef0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbef2;
P_0c0bbef2: /* original 944b, guest PC 0x0c0bbef2 */
if(!s->budget--) { s->failed_pc=0x0c0bbef2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf8cu,2);
goto P_0c0bbef4;
P_0c0bbef4: /* original 9049, guest PC 0x0c0bbef4 */
if(!s->budget--) { s->failed_pc=0x0c0bbef4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf8au,2);
goto P_0c0bbef6;
P_0c0bbef6: /* original 4e0b, guest PC 0x0c0bbef6 */
if(!s->budget--) { s->failed_pc=0x0c0bbef6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbefau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbefau) { target=s->pc; goto dispatch; }
goto P_0c0bbefa;
P_0c0bbef8: /* original 05de, guest PC 0x0c0bbef8 */
if(!s->budget--) { s->failed_pc=0x0c0bbef8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bbefa;
P_0c0bbefa: /* original 9948, guest PC 0x0c0bbefa */
if(!s->budget--) { s->failed_pc=0x0c0bbefau; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf8eu,2);
goto P_0c0bbefc;
P_0c0bbefc: /* original 9448, guest PC 0x0c0bbefc */
if(!s->budget--) { s->failed_pc=0x0c0bbefcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf90u,2);
goto P_0c0bbefe;
P_0c0bbefe: /* original 39dc, guest PC 0x0c0bbefe */
if(!s->budget--) { s->failed_pc=0x0c0bbefeu; return 0; }
r[9]+=r[13];
goto P_0c0bbf00;
P_0c0bbf00: /* original 4e0b, guest PC 0x0c0bbf00 */
if(!s->budget--) { s->failed_pc=0x0c0bbf00u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbf04u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbf04u) { target=s->pc; goto dispatch; }
goto P_0c0bbf04;
P_0c0bbf02: /* original 6592, guest PC 0x0c0bbf02 */
if(!s->budget--) { s->failed_pc=0x0c0bbf02u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bbf04;
P_0c0bbf04: /* original 9445, guest PC 0x0c0bbf04 */
if(!s->budget--) { s->failed_pc=0x0c0bbf04u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf92u,2);
goto P_0c0bbf06;
P_0c0bbf06: /* original 4e0b, guest PC 0x0c0bbf06 */
if(!s->budget--) { s->failed_pc=0x0c0bbf06u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbf0au;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbf0au) { target=s->pc; goto dispatch; }
goto P_0c0bbf0a;
P_0c0bbf08: /* original 6592, guest PC 0x0c0bbf08 */
if(!s->budget--) { s->failed_pc=0x0c0bbf08u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bbf0a;
P_0c0bbf0a: /* original 9443, guest PC 0x0c0bbf0a */
if(!s->budget--) { s->failed_pc=0x0c0bbf0au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf94u,2);
goto P_0c0bbf0c;
P_0c0bbf0c: /* original 4e0b, guest PC 0x0c0bbf0c */
if(!s->budget--) { s->failed_pc=0x0c0bbf0cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbf10u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbf10u) { target=s->pc; goto dispatch; }
goto P_0c0bbf10;
P_0c0bbf0e: /* original 6592, guest PC 0x0c0bbf0e */
if(!s->budget--) { s->failed_pc=0x0c0bbf0eu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bbf10;
P_0c0bbf10: /* original 9441, guest PC 0x0c0bbf10 */
if(!s->budget--) { s->failed_pc=0x0c0bbf10u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf96u,2);
goto P_0c0bbf12;
P_0c0bbf12: /* original 4e0b, guest PC 0x0c0bbf12 */
if(!s->budget--) { s->failed_pc=0x0c0bbf12u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbf16u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbf16u) { target=s->pc; goto dispatch; }
goto P_0c0bbf16;
P_0c0bbf14: /* original 6592, guest PC 0x0c0bbf14 */
if(!s->budget--) { s->failed_pc=0x0c0bbf14u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bbf16;
P_0c0bbf16: /* original 9c3f, guest PC 0x0c0bbf16 */
if(!s->budget--) { s->failed_pc=0x0c0bbf16u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf98u,2);
goto P_0c0bbf18;
P_0c0bbf18: /* original 943f, guest PC 0x0c0bbf18 */
if(!s->budget--) { s->failed_pc=0x0c0bbf18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf9au,2);
goto P_0c0bbf1a;
P_0c0bbf1a: /* original 3cdc, guest PC 0x0c0bbf1a */
if(!s->budget--) { s->failed_pc=0x0c0bbf1au; return 0; }
r[12]+=r[13];
goto P_0c0bbf1c;
P_0c0bbf1c: /* original 4e0b, guest PC 0x0c0bbf1c */
if(!s->budget--) { s->failed_pc=0x0c0bbf1cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbf20u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbf20u) { target=s->pc; goto dispatch; }
goto P_0c0bbf20;
P_0c0bbf1e: /* original 65c2, guest PC 0x0c0bbf1e */
if(!s->budget--) { s->failed_pc=0x0c0bbf1eu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bbf20;
P_0c0bbf20: /* original 943c, guest PC 0x0c0bbf20 */
if(!s->budget--) { s->failed_pc=0x0c0bbf20u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf9cu,2);
goto P_0c0bbf22;
P_0c0bbf22: /* original 4e0b, guest PC 0x0c0bbf22 */
if(!s->budget--) { s->failed_pc=0x0c0bbf22u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbf26u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbf26u) { target=s->pc; goto dispatch; }
goto P_0c0bbf26;
P_0c0bbf24: /* original 65c2, guest PC 0x0c0bbf24 */
if(!s->budget--) { s->failed_pc=0x0c0bbf24u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bbf26;
P_0c0bbf26: /* original 943a, guest PC 0x0c0bbf26 */
if(!s->budget--) { s->failed_pc=0x0c0bbf26u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbf9eu,2);
goto P_0c0bbf28;
P_0c0bbf28: /* original 4e0b, guest PC 0x0c0bbf28 */
if(!s->budget--) { s->failed_pc=0x0c0bbf28u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbf2cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbf2cu) { target=s->pc; goto dispatch; }
goto P_0c0bbf2c;
P_0c0bbf2a: /* original 65c2, guest PC 0x0c0bbf2a */
if(!s->budget--) { s->failed_pc=0x0c0bbf2au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bbf2c;
P_0c0bbf2c: /* original 9438, guest PC 0x0c0bbf2c */
if(!s->budget--) { s->failed_pc=0x0c0bbf2cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbfa0u,2);
goto P_0c0bbf2e;
P_0c0bbf2e: /* original 4e0b, guest PC 0x0c0bbf2e */
if(!s->budget--) { s->failed_pc=0x0c0bbf2eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbf32u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbf32u) { target=s->pc; goto dispatch; }
goto P_0c0bbf32;
P_0c0bbf30: /* original 65c2, guest PC 0x0c0bbf30 */
if(!s->budget--) { s->failed_pc=0x0c0bbf30u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bbf32;
P_0c0bbf32: /* original 9b36, guest PC 0x0c0bbf32 */
if(!s->budget--) { s->failed_pc=0x0c0bbf32u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bbfa2u,2);
goto P_0c0bbf34;
P_0c0bbf34: /* original 3bdc, guest PC 0x0c0bbf34 */
if(!s->budget--) { s->failed_pc=0x0c0bbf34u; return 0; }
r[11]+=r[13];
goto P_0c0bbf36;
P_0c0bbf36: /* original a037, guest PC 0x0c0bbf36 */
if(!s->budget--) { s->failed_pc=0x0c0bbf36u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bbfa8;
P_0c0bbf38: /* original 65b2, guest PC 0x0c0bbf38 */
if(!s->budget--) { s->failed_pc=0x0c0bbf38u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0bbf3au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bbf3au; return 0; } return 1;
P_0c0bbfa8: /* original 94ab, guest PC 0x0c0bbfa8 */
if(!s->budget--) { s->failed_pc=0x0c0bbfa8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc102u,2);
goto P_0c0bbfaa;
P_0c0bbfaa: /* original 4e0b, guest PC 0x0c0bbfaa */
if(!s->budget--) { s->failed_pc=0x0c0bbfaau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbfaeu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbfaeu) { target=s->pc; goto dispatch; }
goto P_0c0bbfae;
P_0c0bbfac: /* original 0009, guest PC 0x0c0bbfac */
if(!s->budget--) { s->failed_pc=0x0c0bbfacu; return 0; }
goto P_0c0bbfae;
P_0c0bbfae: /* original 94a9, guest PC 0x0c0bbfae */
if(!s->budget--) { s->failed_pc=0x0c0bbfaeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc104u,2);
goto P_0c0bbfb0;
P_0c0bbfb0: /* original 4e0b, guest PC 0x0c0bbfb0 */
if(!s->budget--) { s->failed_pc=0x0c0bbfb0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbfb4u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbfb4u) { target=s->pc; goto dispatch; }
goto P_0c0bbfb4;
P_0c0bbfb2: /* original 65b2, guest PC 0x0c0bbfb2 */
if(!s->budget--) { s->failed_pc=0x0c0bbfb2u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bbfb4;
P_0c0bbfb4: /* original 94a7, guest PC 0x0c0bbfb4 */
if(!s->budget--) { s->failed_pc=0x0c0bbfb4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc106u,2);
goto P_0c0bbfb6;
P_0c0bbfb6: /* original 4e0b, guest PC 0x0c0bbfb6 */
if(!s->budget--) { s->failed_pc=0x0c0bbfb6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbfbau;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbfbau) { target=s->pc; goto dispatch; }
goto P_0c0bbfba;
P_0c0bbfb8: /* original 65b2, guest PC 0x0c0bbfb8 */
if(!s->budget--) { s->failed_pc=0x0c0bbfb8u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bbfba;
P_0c0bbfba: /* original 94a5, guest PC 0x0c0bbfba */
if(!s->budget--) { s->failed_pc=0x0c0bbfbau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc108u,2);
goto P_0c0bbfbc;
P_0c0bbfbc: /* original 4e0b, guest PC 0x0c0bbfbc */
if(!s->budget--) { s->failed_pc=0x0c0bbfbcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbfc0u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbfc0u) { target=s->pc; goto dispatch; }
goto P_0c0bbfc0;
P_0c0bbfbe: /* original 65b2, guest PC 0x0c0bbfbe */
if(!s->budget--) { s->failed_pc=0x0c0bbfbeu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bbfc0;
P_0c0bbfc0: /* original 9aa3, guest PC 0x0c0bbfc0 */
if(!s->budget--) { s->failed_pc=0x0c0bbfc0u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc10au,2);
goto P_0c0bbfc2;
P_0c0bbfc2: /* original 94a3, guest PC 0x0c0bbfc2 */
if(!s->budget--) { s->failed_pc=0x0c0bbfc2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc10cu,2);
goto P_0c0bbfc4;
P_0c0bbfc4: /* original 3adc, guest PC 0x0c0bbfc4 */
if(!s->budget--) { s->failed_pc=0x0c0bbfc4u; return 0; }
r[10]+=r[13];
goto P_0c0bbfc6;
P_0c0bbfc6: /* original 4e0b, guest PC 0x0c0bbfc6 */
if(!s->budget--) { s->failed_pc=0x0c0bbfc6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbfcau;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbfcau) { target=s->pc; goto dispatch; }
goto P_0c0bbfca;
P_0c0bbfc8: /* original 65a2, guest PC 0x0c0bbfc8 */
if(!s->budget--) { s->failed_pc=0x0c0bbfc8u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bbfca;
P_0c0bbfca: /* original 94a0, guest PC 0x0c0bbfca */
if(!s->budget--) { s->failed_pc=0x0c0bbfcau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc10eu,2);
goto P_0c0bbfcc;
P_0c0bbfcc: /* original 4e0b, guest PC 0x0c0bbfcc */
if(!s->budget--) { s->failed_pc=0x0c0bbfccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbfd0u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbfd0u) { target=s->pc; goto dispatch; }
goto P_0c0bbfd0;
P_0c0bbfce: /* original 65a2, guest PC 0x0c0bbfce */
if(!s->budget--) { s->failed_pc=0x0c0bbfceu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bbfd0;
P_0c0bbfd0: /* original 949e, guest PC 0x0c0bbfd0 */
if(!s->budget--) { s->failed_pc=0x0c0bbfd0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc110u,2);
goto P_0c0bbfd2;
P_0c0bbfd2: /* original 4e0b, guest PC 0x0c0bbfd2 */
if(!s->budget--) { s->failed_pc=0x0c0bbfd2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbfd6u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbfd6u) { target=s->pc; goto dispatch; }
goto P_0c0bbfd6;
P_0c0bbfd4: /* original 65a2, guest PC 0x0c0bbfd4 */
if(!s->budget--) { s->failed_pc=0x0c0bbfd4u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bbfd6;
P_0c0bbfd6: /* original 949c, guest PC 0x0c0bbfd6 */
if(!s->budget--) { s->failed_pc=0x0c0bbfd6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc112u,2);
goto P_0c0bbfd8;
P_0c0bbfd8: /* original 4e0b, guest PC 0x0c0bbfd8 */
if(!s->budget--) { s->failed_pc=0x0c0bbfd8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbfdcu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbfdcu) { target=s->pc; goto dispatch; }
goto P_0c0bbfdc;
P_0c0bbfda: /* original 65a2, guest PC 0x0c0bbfda */
if(!s->budget--) { s->failed_pc=0x0c0bbfdau; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bbfdc;
P_0c0bbfdc: /* original 949a, guest PC 0x0c0bbfdc */
if(!s->budget--) { s->failed_pc=0x0c0bbfdcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc114u,2);
goto P_0c0bbfde;
P_0c0bbfde: /* original 65f2, guest PC 0x0c0bbfde */
if(!s->budget--) { s->failed_pc=0x0c0bbfdeu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bbfe0;
P_0c0bbfe0: /* original 4e0b, guest PC 0x0c0bbfe0 */
if(!s->budget--) { s->failed_pc=0x0c0bbfe0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbfe4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbfe4u) { target=s->pc; goto dispatch; }
goto P_0c0bbfe4;
P_0c0bbfe2: /* original 6552, guest PC 0x0c0bbfe2 */
if(!s->budget--) { s->failed_pc=0x0c0bbfe2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bbfe4;
P_0c0bbfe4: /* original 9497, guest PC 0x0c0bbfe4 */
if(!s->budget--) { s->failed_pc=0x0c0bbfe4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc116u,2);
goto P_0c0bbfe6;
P_0c0bbfe6: /* original 55f1, guest PC 0x0c0bbfe6 */
if(!s->budget--) { s->failed_pc=0x0c0bbfe6u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0bbfe8;
P_0c0bbfe8: /* original 4e0b, guest PC 0x0c0bbfe8 */
if(!s->budget--) { s->failed_pc=0x0c0bbfe8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbfecu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbfecu) { target=s->pc; goto dispatch; }
goto P_0c0bbfec;
P_0c0bbfea: /* original 6552, guest PC 0x0c0bbfea */
if(!s->budget--) { s->failed_pc=0x0c0bbfeau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bbfec;
P_0c0bbfec: /* original 9494, guest PC 0x0c0bbfec */
if(!s->budget--) { s->failed_pc=0x0c0bbfecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc118u,2);
goto P_0c0bbfee;
P_0c0bbfee: /* original 4e0b, guest PC 0x0c0bbfee */
if(!s->budget--) { s->failed_pc=0x0c0bbfeeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbff2u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbff2u) { target=s->pc; goto dispatch; }
goto P_0c0bbff2;
P_0c0bbff0: /* original 6592, guest PC 0x0c0bbff0 */
if(!s->budget--) { s->failed_pc=0x0c0bbff0u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bbff2;
P_0c0bbff2: /* original 9492, guest PC 0x0c0bbff2 */
if(!s->budget--) { s->failed_pc=0x0c0bbff2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc11au,2);
goto P_0c0bbff4;
P_0c0bbff4: /* original 4e0b, guest PC 0x0c0bbff4 */
if(!s->budget--) { s->failed_pc=0x0c0bbff4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbff8u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbff8u) { target=s->pc; goto dispatch; }
goto P_0c0bbff8;
P_0c0bbff6: /* original 6592, guest PC 0x0c0bbff6 */
if(!s->budget--) { s->failed_pc=0x0c0bbff6u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bbff8;
P_0c0bbff8: /* original 9490, guest PC 0x0c0bbff8 */
if(!s->budget--) { s->failed_pc=0x0c0bbff8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc11cu,2);
goto P_0c0bbffa;
P_0c0bbffa: /* original 4e0b, guest PC 0x0c0bbffa */
if(!s->budget--) { s->failed_pc=0x0c0bbffau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bbffeu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bbffeu) { target=s->pc; goto dispatch; }
goto P_0c0bbffe;
P_0c0bbffc: /* original 6592, guest PC 0x0c0bbffc */
if(!s->budget--) { s->failed_pc=0x0c0bbffcu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bbffe;
P_0c0bbffe: /* original 948e, guest PC 0x0c0bbffe */
if(!s->budget--) { s->failed_pc=0x0c0bbffeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc11eu,2);
goto P_0c0bc000;
P_0c0bc000: /* original 4e0b, guest PC 0x0c0bc000 */
if(!s->budget--) { s->failed_pc=0x0c0bc000u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc004u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc004u) { target=s->pc; goto dispatch; }
goto P_0c0bc004;
P_0c0bc002: /* original 6592, guest PC 0x0c0bc002 */
if(!s->budget--) { s->failed_pc=0x0c0bc002u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bc004;
P_0c0bc004: /* original 948c, guest PC 0x0c0bc004 */
if(!s->budget--) { s->failed_pc=0x0c0bc004u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc120u,2);
goto P_0c0bc006;
P_0c0bc006: /* original 4e0b, guest PC 0x0c0bc006 */
if(!s->budget--) { s->failed_pc=0x0c0bc006u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc00au;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc00au) { target=s->pc; goto dispatch; }
goto P_0c0bc00a;
P_0c0bc008: /* original 65c2, guest PC 0x0c0bc008 */
if(!s->budget--) { s->failed_pc=0x0c0bc008u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bc00a;
P_0c0bc00a: /* original 948a, guest PC 0x0c0bc00a */
if(!s->budget--) { s->failed_pc=0x0c0bc00au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc122u,2);
goto P_0c0bc00c;
P_0c0bc00c: /* original 4e0b, guest PC 0x0c0bc00c */
if(!s->budget--) { s->failed_pc=0x0c0bc00cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc010u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc010u) { target=s->pc; goto dispatch; }
goto P_0c0bc010;
P_0c0bc00e: /* original 65c2, guest PC 0x0c0bc00e */
if(!s->budget--) { s->failed_pc=0x0c0bc00eu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bc010;
P_0c0bc010: /* original 9488, guest PC 0x0c0bc010 */
if(!s->budget--) { s->failed_pc=0x0c0bc010u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc124u,2);
goto P_0c0bc012;
P_0c0bc012: /* original 4e0b, guest PC 0x0c0bc012 */
if(!s->budget--) { s->failed_pc=0x0c0bc012u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc016u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc016u) { target=s->pc; goto dispatch; }
goto P_0c0bc016;
P_0c0bc014: /* original 65c2, guest PC 0x0c0bc014 */
if(!s->budget--) { s->failed_pc=0x0c0bc014u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bc016;
P_0c0bc016: /* original 9486, guest PC 0x0c0bc016 */
if(!s->budget--) { s->failed_pc=0x0c0bc016u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc126u,2);
goto P_0c0bc018;
P_0c0bc018: /* original 4e0b, guest PC 0x0c0bc018 */
if(!s->budget--) { s->failed_pc=0x0c0bc018u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc01cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc01cu) { target=s->pc; goto dispatch; }
goto P_0c0bc01c;
P_0c0bc01a: /* original 65c2, guest PC 0x0c0bc01a */
if(!s->budget--) { s->failed_pc=0x0c0bc01au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bc01c;
P_0c0bc01c: /* original 9484, guest PC 0x0c0bc01c */
if(!s->budget--) { s->failed_pc=0x0c0bc01cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc128u,2);
goto P_0c0bc01e;
P_0c0bc01e: /* original 4e0b, guest PC 0x0c0bc01e */
if(!s->budget--) { s->failed_pc=0x0c0bc01eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc022u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc022u) { target=s->pc; goto dispatch; }
goto P_0c0bc022;
P_0c0bc020: /* original 65b2, guest PC 0x0c0bc020 */
if(!s->budget--) { s->failed_pc=0x0c0bc020u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bc022;
P_0c0bc022: /* original 9482, guest PC 0x0c0bc022 */
if(!s->budget--) { s->failed_pc=0x0c0bc022u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc12au,2);
goto P_0c0bc024;
P_0c0bc024: /* original 4e0b, guest PC 0x0c0bc024 */
if(!s->budget--) { s->failed_pc=0x0c0bc024u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc028u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc028u) { target=s->pc; goto dispatch; }
goto P_0c0bc028;
P_0c0bc026: /* original 65b2, guest PC 0x0c0bc026 */
if(!s->budget--) { s->failed_pc=0x0c0bc026u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bc028;
P_0c0bc028: /* original 9480, guest PC 0x0c0bc028 */
if(!s->budget--) { s->failed_pc=0x0c0bc028u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc12cu,2);
goto P_0c0bc02a;
P_0c0bc02a: /* original 4e0b, guest PC 0x0c0bc02a */
if(!s->budget--) { s->failed_pc=0x0c0bc02au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc02eu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc02eu) { target=s->pc; goto dispatch; }
goto P_0c0bc02e;
P_0c0bc02c: /* original 65b2, guest PC 0x0c0bc02c */
if(!s->budget--) { s->failed_pc=0x0c0bc02cu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bc02e;
P_0c0bc02e: /* original 947e, guest PC 0x0c0bc02e */
if(!s->budget--) { s->failed_pc=0x0c0bc02eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc12eu,2);
goto P_0c0bc030;
P_0c0bc030: /* original 4e0b, guest PC 0x0c0bc030 */
if(!s->budget--) { s->failed_pc=0x0c0bc030u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc034u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc034u) { target=s->pc; goto dispatch; }
goto P_0c0bc034;
P_0c0bc032: /* original 65b2, guest PC 0x0c0bc032 */
if(!s->budget--) { s->failed_pc=0x0c0bc032u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bc034;
P_0c0bc034: /* original 947c, guest PC 0x0c0bc034 */
if(!s->budget--) { s->failed_pc=0x0c0bc034u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc130u,2);
goto P_0c0bc036;
P_0c0bc036: /* original 4e0b, guest PC 0x0c0bc036 */
if(!s->budget--) { s->failed_pc=0x0c0bc036u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc03au;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc03au) { target=s->pc; goto dispatch; }
goto P_0c0bc03a;
P_0c0bc038: /* original 65a2, guest PC 0x0c0bc038 */
if(!s->budget--) { s->failed_pc=0x0c0bc038u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bc03a;
P_0c0bc03a: /* original 947a, guest PC 0x0c0bc03a */
if(!s->budget--) { s->failed_pc=0x0c0bc03au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc132u,2);
goto P_0c0bc03c;
P_0c0bc03c: /* original 4e0b, guest PC 0x0c0bc03c */
if(!s->budget--) { s->failed_pc=0x0c0bc03cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc040u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc040u) { target=s->pc; goto dispatch; }
goto P_0c0bc040;
P_0c0bc03e: /* original 65a2, guest PC 0x0c0bc03e */
if(!s->budget--) { s->failed_pc=0x0c0bc03eu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bc040;
P_0c0bc040: /* original 9478, guest PC 0x0c0bc040 */
if(!s->budget--) { s->failed_pc=0x0c0bc040u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc134u,2);
goto P_0c0bc042;
P_0c0bc042: /* original 4e0b, guest PC 0x0c0bc042 */
if(!s->budget--) { s->failed_pc=0x0c0bc042u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc046u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc046u) { target=s->pc; goto dispatch; }
goto P_0c0bc046;
P_0c0bc044: /* original 65a2, guest PC 0x0c0bc044 */
if(!s->budget--) { s->failed_pc=0x0c0bc044u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bc046;
P_0c0bc046: /* original 9476, guest PC 0x0c0bc046 */
if(!s->budget--) { s->failed_pc=0x0c0bc046u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc136u,2);
goto P_0c0bc048;
P_0c0bc048: /* original 4e0b, guest PC 0x0c0bc048 */
if(!s->budget--) { s->failed_pc=0x0c0bc048u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc04cu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc04cu) { target=s->pc; goto dispatch; }
goto P_0c0bc04c;
P_0c0bc04a: /* original 65a2, guest PC 0x0c0bc04a */
if(!s->budget--) { s->failed_pc=0x0c0bc04au; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bc04c;
P_0c0bc04c: /* original 9574, guest PC 0x0c0bc04c */
if(!s->budget--) { s->failed_pc=0x0c0bc04cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc138u,2);
goto P_0c0bc04e;
P_0c0bc04e: /* original 35dc, guest PC 0x0c0bc04e */
if(!s->budget--) { s->failed_pc=0x0c0bc04eu; return 0; }
r[5]+=r[13];
goto P_0c0bc050;
P_0c0bc050: /* original 2f52, guest PC 0x0c0bc050 */
if(!s->budget--) { s->failed_pc=0x0c0bc050u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bc052;
P_0c0bc052: /* original 9472, guest PC 0x0c0bc052 */
if(!s->budget--) { s->failed_pc=0x0c0bc052u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc13au,2);
goto P_0c0bc054;
P_0c0bc054: /* original 4e0b, guest PC 0x0c0bc054 */
if(!s->budget--) { s->failed_pc=0x0c0bc054u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc058u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc058u) { target=s->pc; goto dispatch; }
goto P_0c0bc058;
P_0c0bc056: /* original 6552, guest PC 0x0c0bc056 */
if(!s->budget--) { s->failed_pc=0x0c0bc056u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc058;
P_0c0bc058: /* original 9470, guest PC 0x0c0bc058 */
if(!s->budget--) { s->failed_pc=0x0c0bc058u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc13cu,2);
goto P_0c0bc05a;
P_0c0bc05a: /* original 65f2, guest PC 0x0c0bc05a */
if(!s->budget--) { s->failed_pc=0x0c0bc05au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bc05c;
P_0c0bc05c: /* original 4e0b, guest PC 0x0c0bc05c */
if(!s->budget--) { s->failed_pc=0x0c0bc05cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc060u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc060u) { target=s->pc; goto dispatch; }
goto P_0c0bc060;
P_0c0bc05e: /* original 6552, guest PC 0x0c0bc05e */
if(!s->budget--) { s->failed_pc=0x0c0bc05eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc060;
P_0c0bc060: /* original 956d, guest PC 0x0c0bc060 */
if(!s->budget--) { s->failed_pc=0x0c0bc060u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc13eu,2);
goto P_0c0bc062;
P_0c0bc062: /* original 35dc, guest PC 0x0c0bc062 */
if(!s->budget--) { s->failed_pc=0x0c0bc062u; return 0; }
r[5]+=r[13];
goto P_0c0bc064;
P_0c0bc064: /* original 2f52, guest PC 0x0c0bc064 */
if(!s->budget--) { s->failed_pc=0x0c0bc064u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bc066;
P_0c0bc066: /* original 946b, guest PC 0x0c0bc066 */
if(!s->budget--) { s->failed_pc=0x0c0bc066u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc140u,2);
goto P_0c0bc068;
P_0c0bc068: /* original 4e0b, guest PC 0x0c0bc068 */
if(!s->budget--) { s->failed_pc=0x0c0bc068u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc06cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc06cu) { target=s->pc; goto dispatch; }
goto P_0c0bc06c;
P_0c0bc06a: /* original 6552, guest PC 0x0c0bc06a */
if(!s->budget--) { s->failed_pc=0x0c0bc06au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc06c;
P_0c0bc06c: /* original 9469, guest PC 0x0c0bc06c */
if(!s->budget--) { s->failed_pc=0x0c0bc06cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc142u,2);
goto P_0c0bc06e;
P_0c0bc06e: /* original 65f2, guest PC 0x0c0bc06e */
if(!s->budget--) { s->failed_pc=0x0c0bc06eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bc070;
P_0c0bc070: /* original 4e0b, guest PC 0x0c0bc070 */
if(!s->budget--) { s->failed_pc=0x0c0bc070u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc074u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc074u) { target=s->pc; goto dispatch; }
goto P_0c0bc074;
P_0c0bc072: /* original 6552, guest PC 0x0c0bc072 */
if(!s->budget--) { s->failed_pc=0x0c0bc072u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc074;
P_0c0bc074: /* original 9467, guest PC 0x0c0bc074 */
if(!s->budget--) { s->failed_pc=0x0c0bc074u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc146u,2);
goto P_0c0bc076;
P_0c0bc076: /* original 9065, guest PC 0x0c0bc076 */
if(!s->budget--) { s->failed_pc=0x0c0bc076u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc144u,2);
goto P_0c0bc078;
P_0c0bc078: /* original 4e0b, guest PC 0x0c0bc078 */
if(!s->budget--) { s->failed_pc=0x0c0bc078u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc07cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc07cu) { target=s->pc; goto dispatch; }
goto P_0c0bc07c;
P_0c0bc07a: /* original 05de, guest PC 0x0c0bc07a */
if(!s->budget--) { s->failed_pc=0x0c0bc07au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc07c;
P_0c0bc07c: /* original 9564, guest PC 0x0c0bc07c */
if(!s->budget--) { s->failed_pc=0x0c0bc07cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc148u,2);
goto P_0c0bc07e;
P_0c0bc07e: /* original 35dc, guest PC 0x0c0bc07e */
if(!s->budget--) { s->failed_pc=0x0c0bc07eu; return 0; }
r[5]+=r[13];
goto P_0c0bc080;
P_0c0bc080: /* original 2f52, guest PC 0x0c0bc080 */
if(!s->budget--) { s->failed_pc=0x0c0bc080u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bc082;
P_0c0bc082: /* original 9462, guest PC 0x0c0bc082 */
if(!s->budget--) { s->failed_pc=0x0c0bc082u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc14au,2);
goto P_0c0bc084;
P_0c0bc084: /* original 4e0b, guest PC 0x0c0bc084 */
if(!s->budget--) { s->failed_pc=0x0c0bc084u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc088u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc088u) { target=s->pc; goto dispatch; }
goto P_0c0bc088;
P_0c0bc086: /* original 6552, guest PC 0x0c0bc086 */
if(!s->budget--) { s->failed_pc=0x0c0bc086u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc088;
P_0c0bc088: /* original 9460, guest PC 0x0c0bc088 */
if(!s->budget--) { s->failed_pc=0x0c0bc088u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc14cu,2);
goto P_0c0bc08a;
P_0c0bc08a: /* original 65f2, guest PC 0x0c0bc08a */
if(!s->budget--) { s->failed_pc=0x0c0bc08au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bc08c;
P_0c0bc08c: /* original 4e0b, guest PC 0x0c0bc08c */
if(!s->budget--) { s->failed_pc=0x0c0bc08cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc090u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc090u) { target=s->pc; goto dispatch; }
goto P_0c0bc090;
P_0c0bc08e: /* original 6552, guest PC 0x0c0bc08e */
if(!s->budget--) { s->failed_pc=0x0c0bc08eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc090;
P_0c0bc090: /* original 945e, guest PC 0x0c0bc090 */
if(!s->budget--) { s->failed_pc=0x0c0bc090u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc150u,2);
goto P_0c0bc092;
P_0c0bc092: /* original 905c, guest PC 0x0c0bc092 */
if(!s->budget--) { s->failed_pc=0x0c0bc092u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc14eu,2);
goto P_0c0bc094;
P_0c0bc094: /* original 4e0b, guest PC 0x0c0bc094 */
if(!s->budget--) { s->failed_pc=0x0c0bc094u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc098u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc098u) { target=s->pc; goto dispatch; }
goto P_0c0bc098;
P_0c0bc096: /* original 05de, guest PC 0x0c0bc096 */
if(!s->budget--) { s->failed_pc=0x0c0bc096u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc098;
P_0c0bc098: /* original 955b, guest PC 0x0c0bc098 */
if(!s->budget--) { s->failed_pc=0x0c0bc098u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc152u,2);
goto P_0c0bc09a;
P_0c0bc09a: /* original 35dc, guest PC 0x0c0bc09a */
if(!s->budget--) { s->failed_pc=0x0c0bc09au; return 0; }
r[5]+=r[13];
goto P_0c0bc09c;
P_0c0bc09c: /* original 2f52, guest PC 0x0c0bc09c */
if(!s->budget--) { s->failed_pc=0x0c0bc09cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bc09e;
P_0c0bc09e: /* original 9459, guest PC 0x0c0bc09e */
if(!s->budget--) { s->failed_pc=0x0c0bc09eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc154u,2);
goto P_0c0bc0a0;
P_0c0bc0a0: /* original 4e0b, guest PC 0x0c0bc0a0 */
if(!s->budget--) { s->failed_pc=0x0c0bc0a0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc0a4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc0a4u) { target=s->pc; goto dispatch; }
goto P_0c0bc0a4;
P_0c0bc0a2: /* original 6552, guest PC 0x0c0bc0a2 */
if(!s->budget--) { s->failed_pc=0x0c0bc0a2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc0a4;
P_0c0bc0a4: /* original 9457, guest PC 0x0c0bc0a4 */
if(!s->budget--) { s->failed_pc=0x0c0bc0a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc156u,2);
goto P_0c0bc0a6;
P_0c0bc0a6: /* original 65f2, guest PC 0x0c0bc0a6 */
if(!s->budget--) { s->failed_pc=0x0c0bc0a6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bc0a8;
P_0c0bc0a8: /* original 4e0b, guest PC 0x0c0bc0a8 */
if(!s->budget--) { s->failed_pc=0x0c0bc0a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc0acu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc0acu) { target=s->pc; goto dispatch; }
goto P_0c0bc0ac;
P_0c0bc0aa: /* original 6552, guest PC 0x0c0bc0aa */
if(!s->budget--) { s->failed_pc=0x0c0bc0aau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc0ac;
P_0c0bc0ac: /* original 9455, guest PC 0x0c0bc0ac */
if(!s->budget--) { s->failed_pc=0x0c0bc0acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc15au,2);
goto P_0c0bc0ae;
P_0c0bc0ae: /* original 9053, guest PC 0x0c0bc0ae */
if(!s->budget--) { s->failed_pc=0x0c0bc0aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc158u,2);
goto P_0c0bc0b0;
P_0c0bc0b0: /* original 4e0b, guest PC 0x0c0bc0b0 */
if(!s->budget--) { s->failed_pc=0x0c0bc0b0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc0b4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc0b4u) { target=s->pc; goto dispatch; }
goto P_0c0bc0b4;
P_0c0bc0b2: /* original 05de, guest PC 0x0c0bc0b2 */
if(!s->budget--) { s->failed_pc=0x0c0bc0b2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc0b4;
P_0c0bc0b4: /* original 9552, guest PC 0x0c0bc0b4 */
if(!s->budget--) { s->failed_pc=0x0c0bc0b4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc15cu,2);
goto P_0c0bc0b6;
P_0c0bc0b6: /* original 35dc, guest PC 0x0c0bc0b6 */
if(!s->budget--) { s->failed_pc=0x0c0bc0b6u; return 0; }
r[5]+=r[13];
goto P_0c0bc0b8;
P_0c0bc0b8: /* original 2f52, guest PC 0x0c0bc0b8 */
if(!s->budget--) { s->failed_pc=0x0c0bc0b8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bc0ba;
P_0c0bc0ba: /* original 9450, guest PC 0x0c0bc0ba */
if(!s->budget--) { s->failed_pc=0x0c0bc0bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc15eu,2);
goto P_0c0bc0bc;
P_0c0bc0bc: /* original 4e0b, guest PC 0x0c0bc0bc */
if(!s->budget--) { s->failed_pc=0x0c0bc0bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc0c0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc0c0u) { target=s->pc; goto dispatch; }
goto P_0c0bc0c0;
P_0c0bc0be: /* original 6552, guest PC 0x0c0bc0be */
if(!s->budget--) { s->failed_pc=0x0c0bc0beu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc0c0;
P_0c0bc0c0: /* original 944e, guest PC 0x0c0bc0c0 */
if(!s->budget--) { s->failed_pc=0x0c0bc0c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc160u,2);
goto P_0c0bc0c2;
P_0c0bc0c2: /* original 65f2, guest PC 0x0c0bc0c2 */
if(!s->budget--) { s->failed_pc=0x0c0bc0c2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bc0c4;
P_0c0bc0c4: /* original 4e0b, guest PC 0x0c0bc0c4 */
if(!s->budget--) { s->failed_pc=0x0c0bc0c4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc0c8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc0c8u) { target=s->pc; goto dispatch; }
goto P_0c0bc0c8;
P_0c0bc0c6: /* original 6552, guest PC 0x0c0bc0c6 */
if(!s->budget--) { s->failed_pc=0x0c0bc0c6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc0c8;
P_0c0bc0c8: /* original 954b, guest PC 0x0c0bc0c8 */
if(!s->budget--) { s->failed_pc=0x0c0bc0c8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc162u,2);
goto P_0c0bc0ca;
P_0c0bc0ca: /* original 35dc, guest PC 0x0c0bc0ca */
if(!s->budget--) { s->failed_pc=0x0c0bc0cau; return 0; }
r[5]+=r[13];
goto P_0c0bc0cc;
P_0c0bc0cc: /* original 2f52, guest PC 0x0c0bc0cc */
if(!s->budget--) { s->failed_pc=0x0c0bc0ccu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bc0ce;
P_0c0bc0ce: /* original 9449, guest PC 0x0c0bc0ce */
if(!s->budget--) { s->failed_pc=0x0c0bc0ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc164u,2);
goto P_0c0bc0d0;
P_0c0bc0d0: /* original 4e0b, guest PC 0x0c0bc0d0 */
if(!s->budget--) { s->failed_pc=0x0c0bc0d0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc0d4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc0d4u) { target=s->pc; goto dispatch; }
goto P_0c0bc0d4;
P_0c0bc0d2: /* original 6552, guest PC 0x0c0bc0d2 */
if(!s->budget--) { s->failed_pc=0x0c0bc0d2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc0d4;
P_0c0bc0d4: /* original 9447, guest PC 0x0c0bc0d4 */
if(!s->budget--) { s->failed_pc=0x0c0bc0d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc166u,2);
goto P_0c0bc0d6;
P_0c0bc0d6: /* original 65f2, guest PC 0x0c0bc0d6 */
if(!s->budget--) { s->failed_pc=0x0c0bc0d6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bc0d8;
P_0c0bc0d8: /* original 4e0b, guest PC 0x0c0bc0d8 */
if(!s->budget--) { s->failed_pc=0x0c0bc0d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc0dcu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc0dcu) { target=s->pc; goto dispatch; }
goto P_0c0bc0dc;
P_0c0bc0da: /* original 6552, guest PC 0x0c0bc0da */
if(!s->budget--) { s->failed_pc=0x0c0bc0dau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bc0dc;
P_0c0bc0dc: /* original 9445, guest PC 0x0c0bc0dc */
if(!s->budget--) { s->failed_pc=0x0c0bc0dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc16au,2);
goto P_0c0bc0de;
P_0c0bc0de: /* original 9043, guest PC 0x0c0bc0de */
if(!s->budget--) { s->failed_pc=0x0c0bc0deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc168u,2);
goto P_0c0bc0e0;
P_0c0bc0e0: /* original 4e0b, guest PC 0x0c0bc0e0 */
if(!s->budget--) { s->failed_pc=0x0c0bc0e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc0e4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc0e4u) { target=s->pc; goto dispatch; }
goto P_0c0bc0e4;
P_0c0bc0e2: /* original 05de, guest PC 0x0c0bc0e2 */
if(!s->budget--) { s->failed_pc=0x0c0bc0e2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc0e4;
P_0c0bc0e4: /* original 9443, guest PC 0x0c0bc0e4 */
if(!s->budget--) { s->failed_pc=0x0c0bc0e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc16eu,2);
goto P_0c0bc0e6;
P_0c0bc0e6: /* original 9041, guest PC 0x0c0bc0e6 */
if(!s->budget--) { s->failed_pc=0x0c0bc0e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc16cu,2);
goto P_0c0bc0e8;
P_0c0bc0e8: /* original 4e0b, guest PC 0x0c0bc0e8 */
if(!s->budget--) { s->failed_pc=0x0c0bc0e8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc0ecu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc0ecu) { target=s->pc; goto dispatch; }
goto P_0c0bc0ec;
P_0c0bc0ea: /* original 05de, guest PC 0x0c0bc0ea */
if(!s->budget--) { s->failed_pc=0x0c0bc0eau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc0ec;
P_0c0bc0ec: /* original 9441, guest PC 0x0c0bc0ec */
if(!s->budget--) { s->failed_pc=0x0c0bc0ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc172u,2);
goto P_0c0bc0ee;
P_0c0bc0ee: /* original 903f, guest PC 0x0c0bc0ee */
if(!s->budget--) { s->failed_pc=0x0c0bc0eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc170u,2);
goto P_0c0bc0f0;
P_0c0bc0f0: /* original 4e0b, guest PC 0x0c0bc0f0 */
if(!s->budget--) { s->failed_pc=0x0c0bc0f0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc0f4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc0f4u) { target=s->pc; goto dispatch; }
goto P_0c0bc0f4;
P_0c0bc0f2: /* original 05de, guest PC 0x0c0bc0f2 */
if(!s->budget--) { s->failed_pc=0x0c0bc0f2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc0f4;
P_0c0bc0f4: /* original 943f, guest PC 0x0c0bc0f4 */
if(!s->budget--) { s->failed_pc=0x0c0bc0f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc176u,2);
goto P_0c0bc0f6;
P_0c0bc0f6: /* original 903d, guest PC 0x0c0bc0f6 */
if(!s->budget--) { s->failed_pc=0x0c0bc0f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc174u,2);
goto P_0c0bc0f8;
P_0c0bc0f8: /* original 4e0b, guest PC 0x0c0bc0f8 */
if(!s->budget--) { s->failed_pc=0x0c0bc0f8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc0fcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc0fcu) { target=s->pc; goto dispatch; }
goto P_0c0bc0fc;
P_0c0bc0fa: /* original 05de, guest PC 0x0c0bc0fa */
if(!s->budget--) { s->failed_pc=0x0c0bc0fau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc0fc;
P_0c0bc0fc: /* original 903c, guest PC 0x0c0bc0fc */
if(!s->budget--) { s->failed_pc=0x0c0bc0fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc178u,2);
goto P_0c0bc0fe;
P_0c0bc0fe: /* original a03c, guest PC 0x0c0bc0fe */
if(!s->budget--) { s->failed_pc=0x0c0bc0feu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc17a;
P_0c0bc100: /* original 05de, guest PC 0x0c0bc100 */
if(!s->budget--) { s->failed_pc=0x0c0bc100u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0bc102u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bc102u; return 0; } return 1;
P_0c0bc17a: /* original 9446, guest PC 0x0c0bc17a */
if(!s->budget--) { s->failed_pc=0x0c0bc17au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc20au,2);
goto P_0c0bc17c;
P_0c0bc17c: /* original 4e0b, guest PC 0x0c0bc17c */
if(!s->budget--) { s->failed_pc=0x0c0bc17cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc180u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc180u) { target=s->pc; goto dispatch; }
goto P_0c0bc180;
P_0c0bc17e: /* original 0009, guest PC 0x0c0bc17e */
if(!s->budget--) { s->failed_pc=0x0c0bc17eu; return 0; }
goto P_0c0bc180;
P_0c0bc180: /* original 9445, guest PC 0x0c0bc180 */
if(!s->budget--) { s->failed_pc=0x0c0bc180u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc20eu,2);
goto P_0c0bc182;
P_0c0bc182: /* original 9043, guest PC 0x0c0bc182 */
if(!s->budget--) { s->failed_pc=0x0c0bc182u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc20cu,2);
goto P_0c0bc184;
P_0c0bc184: /* original 4e0b, guest PC 0x0c0bc184 */
if(!s->budget--) { s->failed_pc=0x0c0bc184u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc188u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc188u) { target=s->pc; goto dispatch; }
goto P_0c0bc188;
P_0c0bc186: /* original 05de, guest PC 0x0c0bc186 */
if(!s->budget--) { s->failed_pc=0x0c0bc186u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc188;
P_0c0bc188: /* original 9443, guest PC 0x0c0bc188 */
if(!s->budget--) { s->failed_pc=0x0c0bc188u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc212u,2);
goto P_0c0bc18a;
P_0c0bc18a: /* original 9041, guest PC 0x0c0bc18a */
if(!s->budget--) { s->failed_pc=0x0c0bc18au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc210u,2);
goto P_0c0bc18c;
P_0c0bc18c: /* original 4e0b, guest PC 0x0c0bc18c */
if(!s->budget--) { s->failed_pc=0x0c0bc18cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc190u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc190u) { target=s->pc; goto dispatch; }
goto P_0c0bc190;
P_0c0bc18e: /* original 05de, guest PC 0x0c0bc18e */
if(!s->budget--) { s->failed_pc=0x0c0bc18eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc190;
P_0c0bc190: /* original 9441, guest PC 0x0c0bc190 */
if(!s->budget--) { s->failed_pc=0x0c0bc190u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc216u,2);
goto P_0c0bc192;
P_0c0bc192: /* original 903f, guest PC 0x0c0bc192 */
if(!s->budget--) { s->failed_pc=0x0c0bc192u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc214u,2);
goto P_0c0bc194;
P_0c0bc194: /* original 4e0b, guest PC 0x0c0bc194 */
if(!s->budget--) { s->failed_pc=0x0c0bc194u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc198u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc198u) { target=s->pc; goto dispatch; }
goto P_0c0bc198;
P_0c0bc196: /* original 05de, guest PC 0x0c0bc196 */
if(!s->budget--) { s->failed_pc=0x0c0bc196u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc198;
P_0c0bc198: /* original 943f, guest PC 0x0c0bc198 */
if(!s->budget--) { s->failed_pc=0x0c0bc198u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc21au,2);
goto P_0c0bc19a;
P_0c0bc19a: /* original 903d, guest PC 0x0c0bc19a */
if(!s->budget--) { s->failed_pc=0x0c0bc19au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc218u,2);
goto P_0c0bc19c;
P_0c0bc19c: /* original 4e0b, guest PC 0x0c0bc19c */
if(!s->budget--) { s->failed_pc=0x0c0bc19cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc1a0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc1a0u) { target=s->pc; goto dispatch; }
goto P_0c0bc1a0;
P_0c0bc19e: /* original 05de, guest PC 0x0c0bc19e */
if(!s->budget--) { s->failed_pc=0x0c0bc19eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1a0;
P_0c0bc1a0: /* original 943d, guest PC 0x0c0bc1a0 */
if(!s->budget--) { s->failed_pc=0x0c0bc1a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc21eu,2);
goto P_0c0bc1a2;
P_0c0bc1a2: /* original 903b, guest PC 0x0c0bc1a2 */
if(!s->budget--) { s->failed_pc=0x0c0bc1a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc21cu,2);
goto P_0c0bc1a4;
P_0c0bc1a4: /* original 4e0b, guest PC 0x0c0bc1a4 */
if(!s->budget--) { s->failed_pc=0x0c0bc1a4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc1a8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc1a8u) { target=s->pc; goto dispatch; }
goto P_0c0bc1a8;
P_0c0bc1a6: /* original 05de, guest PC 0x0c0bc1a6 */
if(!s->budget--) { s->failed_pc=0x0c0bc1a6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1a8;
P_0c0bc1a8: /* original 943b, guest PC 0x0c0bc1a8 */
if(!s->budget--) { s->failed_pc=0x0c0bc1a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc222u,2);
goto P_0c0bc1aa;
P_0c0bc1aa: /* original 9039, guest PC 0x0c0bc1aa */
if(!s->budget--) { s->failed_pc=0x0c0bc1aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc220u,2);
goto P_0c0bc1ac;
P_0c0bc1ac: /* original 4e0b, guest PC 0x0c0bc1ac */
if(!s->budget--) { s->failed_pc=0x0c0bc1acu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc1b0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc1b0u) { target=s->pc; goto dispatch; }
goto P_0c0bc1b0;
P_0c0bc1ae: /* original 05de, guest PC 0x0c0bc1ae */
if(!s->budget--) { s->failed_pc=0x0c0bc1aeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1b0;
P_0c0bc1b0: /* original 9439, guest PC 0x0c0bc1b0 */
if(!s->budget--) { s->failed_pc=0x0c0bc1b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc226u,2);
goto P_0c0bc1b2;
P_0c0bc1b2: /* original 9037, guest PC 0x0c0bc1b2 */
if(!s->budget--) { s->failed_pc=0x0c0bc1b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc224u,2);
goto P_0c0bc1b4;
P_0c0bc1b4: /* original 4e0b, guest PC 0x0c0bc1b4 */
if(!s->budget--) { s->failed_pc=0x0c0bc1b4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc1b8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc1b8u) { target=s->pc; goto dispatch; }
goto P_0c0bc1b8;
P_0c0bc1b6: /* original 05de, guest PC 0x0c0bc1b6 */
if(!s->budget--) { s->failed_pc=0x0c0bc1b6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1b8;
P_0c0bc1b8: /* original 9437, guest PC 0x0c0bc1b8 */
if(!s->budget--) { s->failed_pc=0x0c0bc1b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc22au,2);
goto P_0c0bc1ba;
P_0c0bc1ba: /* original 9035, guest PC 0x0c0bc1ba */
if(!s->budget--) { s->failed_pc=0x0c0bc1bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc228u,2);
goto P_0c0bc1bc;
P_0c0bc1bc: /* original 4e0b, guest PC 0x0c0bc1bc */
if(!s->budget--) { s->failed_pc=0x0c0bc1bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc1c0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc1c0u) { target=s->pc; goto dispatch; }
goto P_0c0bc1c0;
P_0c0bc1be: /* original 05de, guest PC 0x0c0bc1be */
if(!s->budget--) { s->failed_pc=0x0c0bc1beu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1c0;
P_0c0bc1c0: /* original 9435, guest PC 0x0c0bc1c0 */
if(!s->budget--) { s->failed_pc=0x0c0bc1c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc22eu,2);
goto P_0c0bc1c2;
P_0c0bc1c2: /* original 9033, guest PC 0x0c0bc1c2 */
if(!s->budget--) { s->failed_pc=0x0c0bc1c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc22cu,2);
goto P_0c0bc1c4;
P_0c0bc1c4: /* original 4e0b, guest PC 0x0c0bc1c4 */
if(!s->budget--) { s->failed_pc=0x0c0bc1c4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc1c8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc1c8u) { target=s->pc; goto dispatch; }
goto P_0c0bc1c8;
P_0c0bc1c6: /* original 05de, guest PC 0x0c0bc1c6 */
if(!s->budget--) { s->failed_pc=0x0c0bc1c6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1c8;
P_0c0bc1c8: /* original 9433, guest PC 0x0c0bc1c8 */
if(!s->budget--) { s->failed_pc=0x0c0bc1c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc232u,2);
goto P_0c0bc1ca;
P_0c0bc1ca: /* original 9031, guest PC 0x0c0bc1ca */
if(!s->budget--) { s->failed_pc=0x0c0bc1cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc230u,2);
goto P_0c0bc1cc;
P_0c0bc1cc: /* original 4e0b, guest PC 0x0c0bc1cc */
if(!s->budget--) { s->failed_pc=0x0c0bc1ccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc1d0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc1d0u) { target=s->pc; goto dispatch; }
goto P_0c0bc1d0;
P_0c0bc1ce: /* original 05de, guest PC 0x0c0bc1ce */
if(!s->budget--) { s->failed_pc=0x0c0bc1ceu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1d0;
P_0c0bc1d0: /* original 9431, guest PC 0x0c0bc1d0 */
if(!s->budget--) { s->failed_pc=0x0c0bc1d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc236u,2);
goto P_0c0bc1d2;
P_0c0bc1d2: /* original 902f, guest PC 0x0c0bc1d2 */
if(!s->budget--) { s->failed_pc=0x0c0bc1d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc234u,2);
goto P_0c0bc1d4;
P_0c0bc1d4: /* original 4e0b, guest PC 0x0c0bc1d4 */
if(!s->budget--) { s->failed_pc=0x0c0bc1d4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc1d8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc1d8u) { target=s->pc; goto dispatch; }
goto P_0c0bc1d8;
P_0c0bc1d6: /* original 05de, guest PC 0x0c0bc1d6 */
if(!s->budget--) { s->failed_pc=0x0c0bc1d6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1d8;
P_0c0bc1d8: /* original 942f, guest PC 0x0c0bc1d8 */
if(!s->budget--) { s->failed_pc=0x0c0bc1d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc23au,2);
goto P_0c0bc1da;
P_0c0bc1da: /* original 902d, guest PC 0x0c0bc1da */
if(!s->budget--) { s->failed_pc=0x0c0bc1dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc238u,2);
goto P_0c0bc1dc;
P_0c0bc1dc: /* original 4e0b, guest PC 0x0c0bc1dc */
if(!s->budget--) { s->failed_pc=0x0c0bc1dcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc1e0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc1e0u) { target=s->pc; goto dispatch; }
goto P_0c0bc1e0;
P_0c0bc1de: /* original 05de, guest PC 0x0c0bc1de */
if(!s->budget--) { s->failed_pc=0x0c0bc1deu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1e0;
P_0c0bc1e0: /* original 942d, guest PC 0x0c0bc1e0 */
if(!s->budget--) { s->failed_pc=0x0c0bc1e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc23eu,2);
goto P_0c0bc1e2;
P_0c0bc1e2: /* original 902b, guest PC 0x0c0bc1e2 */
if(!s->budget--) { s->failed_pc=0x0c0bc1e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc23cu,2);
goto P_0c0bc1e4;
P_0c0bc1e4: /* original 4e0b, guest PC 0x0c0bc1e4 */
if(!s->budget--) { s->failed_pc=0x0c0bc1e4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc1e8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc1e8u) { target=s->pc; goto dispatch; }
goto P_0c0bc1e8;
P_0c0bc1e6: /* original 05de, guest PC 0x0c0bc1e6 */
if(!s->budget--) { s->failed_pc=0x0c0bc1e6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1e8;
P_0c0bc1e8: /* original 942b, guest PC 0x0c0bc1e8 */
if(!s->budget--) { s->failed_pc=0x0c0bc1e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc242u,2);
goto P_0c0bc1ea;
P_0c0bc1ea: /* original 9029, guest PC 0x0c0bc1ea */
if(!s->budget--) { s->failed_pc=0x0c0bc1eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc240u,2);
goto P_0c0bc1ec;
P_0c0bc1ec: /* original 4e0b, guest PC 0x0c0bc1ec */
if(!s->budget--) { s->failed_pc=0x0c0bc1ecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc1f0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc1f0u) { target=s->pc; goto dispatch; }
goto P_0c0bc1f0;
P_0c0bc1ee: /* original 05de, guest PC 0x0c0bc1ee */
if(!s->budget--) { s->failed_pc=0x0c0bc1eeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1f0;
P_0c0bc1f0: /* original 9429, guest PC 0x0c0bc1f0 */
if(!s->budget--) { s->failed_pc=0x0c0bc1f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc246u,2);
goto P_0c0bc1f2;
P_0c0bc1f2: /* original 9027, guest PC 0x0c0bc1f2 */
if(!s->budget--) { s->failed_pc=0x0c0bc1f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bc244u,2);
goto P_0c0bc1f4;
P_0c0bc1f4: /* original 4e0b, guest PC 0x0c0bc1f4 */
if(!s->budget--) { s->failed_pc=0x0c0bc1f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bc1f8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bc1f8u) { target=s->pc; goto dispatch; }
goto P_0c0bc1f8;
P_0c0bc1f6: /* original 05de, guest PC 0x0c0bc1f6 */
if(!s->budget--) { s->failed_pc=0x0c0bc1f6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bc1f8;
P_0c0bc1f8: /* original 7f08, guest PC 0x0c0bc1f8 */
if(!s->budget--) { s->failed_pc=0x0c0bc1f8u; return 0; }
r[15]+=0x00000008u;
goto P_0c0bc1fa;
P_0c0bc1fa: /* original 4f26, guest PC 0x0c0bc1fa */
if(!s->budget--) { s->failed_pc=0x0c0bc1fau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0bc1fc;
P_0c0bc1fc: /* original 69f6, guest PC 0x0c0bc1fc */
if(!s->budget--) { s->failed_pc=0x0c0bc1fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0bc1fe;
P_0c0bc1fe: /* original 6af6, guest PC 0x0c0bc1fe */
if(!s->budget--) { s->failed_pc=0x0c0bc1feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0bc200;
P_0c0bc200: /* original 6bf6, guest PC 0x0c0bc200 */
if(!s->budget--) { s->failed_pc=0x0c0bc200u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0bc202;
P_0c0bc202: /* original 6cf6, guest PC 0x0c0bc202 */
if(!s->budget--) { s->failed_pc=0x0c0bc202u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0bc204;
P_0c0bc204: /* original 6df6, guest PC 0x0c0bc204 */
if(!s->budget--) { s->failed_pc=0x0c0bc204u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0bc206;
P_0c0bc206: /* original 000b, guest PC 0x0c0bc206 */
if(!s->budget--) { s->failed_pc=0x0c0bc206u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0bc208: /* original 6ef6, guest PC 0x0c0bc208 */
if(!s->budget--) { s->failed_pc=0x0c0bc208u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0bc20au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bc20au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
