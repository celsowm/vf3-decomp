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
int vf3_away_batch24_adapter_12(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0bcd5eu: goto P_0c0bcd5e;
case 0x0c0bcd60u: goto P_0c0bcd60;
case 0x0c0bcd62u: goto P_0c0bcd62;
case 0x0c0bcd64u: goto P_0c0bcd64;
case 0x0c0bcd66u: goto P_0c0bcd66;
case 0x0c0bcd68u: goto P_0c0bcd68;
case 0x0c0bcd6au: goto P_0c0bcd6a;
case 0x0c0bcd6cu: goto P_0c0bcd6c;
case 0x0c0bcd6eu: goto P_0c0bcd6e;
case 0x0c0bcd70u: goto P_0c0bcd70;
case 0x0c0bcd72u: goto P_0c0bcd72;
case 0x0c0bcd74u: goto P_0c0bcd74;
case 0x0c0bcd76u: goto P_0c0bcd76;
case 0x0c0bcd78u: goto P_0c0bcd78;
case 0x0c0bcd7au: goto P_0c0bcd7a;
case 0x0c0bcd7cu: goto P_0c0bcd7c;
case 0x0c0bcd7eu: goto P_0c0bcd7e;
case 0x0c0bcd80u: goto P_0c0bcd80;
case 0x0c0bcd82u: goto P_0c0bcd82;
case 0x0c0bcd84u: goto P_0c0bcd84;
case 0x0c0bcd86u: goto P_0c0bcd86;
case 0x0c0bcd88u: goto P_0c0bcd88;
case 0x0c0bcd8au: goto P_0c0bcd8a;
case 0x0c0bcd8cu: goto P_0c0bcd8c;
case 0x0c0bcd8eu: goto P_0c0bcd8e;
case 0x0c0bcd90u: goto P_0c0bcd90;
case 0x0c0bcd92u: goto P_0c0bcd92;
case 0x0c0bcd94u: goto P_0c0bcd94;
case 0x0c0bcd96u: goto P_0c0bcd96;
case 0x0c0bcd98u: goto P_0c0bcd98;
case 0x0c0bcd9au: goto P_0c0bcd9a;
case 0x0c0bcd9cu: goto P_0c0bcd9c;
case 0x0c0bcd9eu: goto P_0c0bcd9e;
case 0x0c0bcda0u: goto P_0c0bcda0;
case 0x0c0bcda2u: goto P_0c0bcda2;
case 0x0c0bcda4u: goto P_0c0bcda4;
case 0x0c0bcda6u: goto P_0c0bcda6;
case 0x0c0bcda8u: goto P_0c0bcda8;
case 0x0c0bcdaau: goto P_0c0bcdaa;
case 0x0c0bcdacu: goto P_0c0bcdac;
case 0x0c0bcdaeu: goto P_0c0bcdae;
case 0x0c0bcdb0u: goto P_0c0bcdb0;
case 0x0c0bcdb2u: goto P_0c0bcdb2;
case 0x0c0bcdb4u: goto P_0c0bcdb4;
case 0x0c0bcdb6u: goto P_0c0bcdb6;
case 0x0c0bcdb8u: goto P_0c0bcdb8;
case 0x0c0bcdbau: goto P_0c0bcdba;
case 0x0c0bcdbcu: goto P_0c0bcdbc;
case 0x0c0bcdbeu: goto P_0c0bcdbe;
case 0x0c0bcdc0u: goto P_0c0bcdc0;
case 0x0c0bcdc2u: goto P_0c0bcdc2;
case 0x0c0bcdc4u: goto P_0c0bcdc4;
case 0x0c0bcdc6u: goto P_0c0bcdc6;
case 0x0c0bcdc8u: goto P_0c0bcdc8;
case 0x0c0bcdcau: goto P_0c0bcdca;
case 0x0c0bcdccu: goto P_0c0bcdcc;
case 0x0c0bcdceu: goto P_0c0bcdce;
case 0x0c0bcdd0u: goto P_0c0bcdd0;
case 0x0c0bcdd2u: goto P_0c0bcdd2;
case 0x0c0bcdd4u: goto P_0c0bcdd4;
case 0x0c0bcdd6u: goto P_0c0bcdd6;
case 0x0c0bcdd8u: goto P_0c0bcdd8;
case 0x0c0bcddau: goto P_0c0bcdda;
case 0x0c0bcddcu: goto P_0c0bcddc;
case 0x0c0bcddeu: goto P_0c0bcdde;
case 0x0c0bcde0u: goto P_0c0bcde0;
case 0x0c0bcde2u: goto P_0c0bcde2;
case 0x0c0bcde4u: goto P_0c0bcde4;
case 0x0c0bcde6u: goto P_0c0bcde6;
case 0x0c0bcde8u: goto P_0c0bcde8;
case 0x0c0bcdeau: goto P_0c0bcdea;
case 0x0c0bcdecu: goto P_0c0bcdec;
case 0x0c0bcdeeu: goto P_0c0bcdee;
case 0x0c0bcdf0u: goto P_0c0bcdf0;
case 0x0c0bcdf2u: goto P_0c0bcdf2;
case 0x0c0bcdf4u: goto P_0c0bcdf4;
case 0x0c0bcdf6u: goto P_0c0bcdf6;
case 0x0c0bcdf8u: goto P_0c0bcdf8;
case 0x0c0bcdfau: goto P_0c0bcdfa;
case 0x0c0bcdfcu: goto P_0c0bcdfc;
case 0x0c0bcdfeu: goto P_0c0bcdfe;
case 0x0c0bce00u: goto P_0c0bce00;
case 0x0c0bce02u: goto P_0c0bce02;
case 0x0c0bce04u: goto P_0c0bce04;
case 0x0c0bce06u: goto P_0c0bce06;
case 0x0c0bce08u: goto P_0c0bce08;
case 0x0c0bce0au: goto P_0c0bce0a;
case 0x0c0bce0cu: goto P_0c0bce0c;
case 0x0c0bce0eu: goto P_0c0bce0e;
case 0x0c0bce10u: goto P_0c0bce10;
case 0x0c0bce12u: goto P_0c0bce12;
case 0x0c0bce14u: goto P_0c0bce14;
case 0x0c0bce16u: goto P_0c0bce16;
case 0x0c0bce18u: goto P_0c0bce18;
case 0x0c0bce1au: goto P_0c0bce1a;
case 0x0c0bce1cu: goto P_0c0bce1c;
case 0x0c0bce1eu: goto P_0c0bce1e;
case 0x0c0bce20u: goto P_0c0bce20;
case 0x0c0bce22u: goto P_0c0bce22;
case 0x0c0bce24u: goto P_0c0bce24;
case 0x0c0bce26u: goto P_0c0bce26;
case 0x0c0bce28u: goto P_0c0bce28;
case 0x0c0bce2au: goto P_0c0bce2a;
case 0x0c0bce2cu: goto P_0c0bce2c;
case 0x0c0bce2eu: goto P_0c0bce2e;
case 0x0c0bce30u: goto P_0c0bce30;
case 0x0c0bce32u: goto P_0c0bce32;
case 0x0c0bce34u: goto P_0c0bce34;
case 0x0c0bce36u: goto P_0c0bce36;
case 0x0c0bce38u: goto P_0c0bce38;
case 0x0c0bce3au: goto P_0c0bce3a;
case 0x0c0bce3cu: goto P_0c0bce3c;
case 0x0c0bce3eu: goto P_0c0bce3e;
case 0x0c0bce40u: goto P_0c0bce40;
case 0x0c0bce42u: goto P_0c0bce42;
case 0x0c0bce44u: goto P_0c0bce44;
case 0x0c0bce46u: goto P_0c0bce46;
case 0x0c0bce48u: goto P_0c0bce48;
case 0x0c0bce4au: goto P_0c0bce4a;
case 0x0c0bce4cu: goto P_0c0bce4c;
case 0x0c0bce4eu: goto P_0c0bce4e;
case 0x0c0bce50u: goto P_0c0bce50;
case 0x0c0bce52u: goto P_0c0bce52;
case 0x0c0bce54u: goto P_0c0bce54;
case 0x0c0bce56u: goto P_0c0bce56;
case 0x0c0bce58u: goto P_0c0bce58;
case 0x0c0bce5au: goto P_0c0bce5a;
case 0x0c0bce5cu: goto P_0c0bce5c;
case 0x0c0bce5eu: goto P_0c0bce5e;
case 0x0c0bce60u: goto P_0c0bce60;
case 0x0c0bce62u: goto P_0c0bce62;
case 0x0c0bce64u: goto P_0c0bce64;
case 0x0c0bce66u: goto P_0c0bce66;
case 0x0c0bce68u: goto P_0c0bce68;
case 0x0c0bce6au: goto P_0c0bce6a;
case 0x0c0bce6cu: goto P_0c0bce6c;
case 0x0c0bce6eu: goto P_0c0bce6e;
case 0x0c0bce70u: goto P_0c0bce70;
case 0x0c0bce72u: goto P_0c0bce72;
case 0x0c0bce74u: goto P_0c0bce74;
case 0x0c0bce76u: goto P_0c0bce76;
case 0x0c0bce78u: goto P_0c0bce78;
case 0x0c0bce7au: goto P_0c0bce7a;
case 0x0c0bce7cu: goto P_0c0bce7c;
case 0x0c0bce7eu: goto P_0c0bce7e;
case 0x0c0bce80u: goto P_0c0bce80;
case 0x0c0bce82u: goto P_0c0bce82;
case 0x0c0bce84u: goto P_0c0bce84;
case 0x0c0bce86u: goto P_0c0bce86;
case 0x0c0bce88u: goto P_0c0bce88;
case 0x0c0bce8au: goto P_0c0bce8a;
case 0x0c0bce8cu: goto P_0c0bce8c;
case 0x0c0bce8eu: goto P_0c0bce8e;
case 0x0c0bce90u: goto P_0c0bce90;
case 0x0c0bce92u: goto P_0c0bce92;
case 0x0c0bce94u: goto P_0c0bce94;
case 0x0c0bce96u: goto P_0c0bce96;
case 0x0c0bce98u: goto P_0c0bce98;
case 0x0c0bce9au: goto P_0c0bce9a;
case 0x0c0bce9cu: goto P_0c0bce9c;
case 0x0c0bce9eu: goto P_0c0bce9e;
case 0x0c0bcea0u: goto P_0c0bcea0;
case 0x0c0bcea2u: goto P_0c0bcea2;
case 0x0c0bcea4u: goto P_0c0bcea4;
case 0x0c0bcea6u: goto P_0c0bcea6;
case 0x0c0bcea8u: goto P_0c0bcea8;
case 0x0c0bceaau: goto P_0c0bceaa;
case 0x0c0bceacu: goto P_0c0bceac;
case 0x0c0bceaeu: goto P_0c0bceae;
case 0x0c0bceb0u: goto P_0c0bceb0;
case 0x0c0bceb2u: goto P_0c0bceb2;
case 0x0c0bceb4u: goto P_0c0bceb4;
case 0x0c0bceb6u: goto P_0c0bceb6;
case 0x0c0bceb8u: goto P_0c0bceb8;
case 0x0c0bcebau: goto P_0c0bceba;
case 0x0c0bcebcu: goto P_0c0bcebc;
case 0x0c0bcebeu: goto P_0c0bcebe;
case 0x0c0bcec0u: goto P_0c0bcec0;
case 0x0c0bcf30u: goto P_0c0bcf30;
case 0x0c0bcf32u: goto P_0c0bcf32;
case 0x0c0bcf34u: goto P_0c0bcf34;
case 0x0c0bcf36u: goto P_0c0bcf36;
case 0x0c0bcf38u: goto P_0c0bcf38;
case 0x0c0bcf3au: goto P_0c0bcf3a;
case 0x0c0bcf3cu: goto P_0c0bcf3c;
case 0x0c0bcf3eu: goto P_0c0bcf3e;
case 0x0c0bcf40u: goto P_0c0bcf40;
case 0x0c0bcf42u: goto P_0c0bcf42;
case 0x0c0bcf44u: goto P_0c0bcf44;
case 0x0c0bcf46u: goto P_0c0bcf46;
case 0x0c0bcf48u: goto P_0c0bcf48;
case 0x0c0bcf4au: goto P_0c0bcf4a;
case 0x0c0bcf4cu: goto P_0c0bcf4c;
case 0x0c0bcf4eu: goto P_0c0bcf4e;
case 0x0c0bcf50u: goto P_0c0bcf50;
case 0x0c0bcf52u: goto P_0c0bcf52;
case 0x0c0bcf54u: goto P_0c0bcf54;
case 0x0c0bcf56u: goto P_0c0bcf56;
case 0x0c0bcf58u: goto P_0c0bcf58;
case 0x0c0bcf5au: goto P_0c0bcf5a;
case 0x0c0bcf5cu: goto P_0c0bcf5c;
case 0x0c0bcf5eu: goto P_0c0bcf5e;
case 0x0c0bcf60u: goto P_0c0bcf60;
case 0x0c0bcf62u: goto P_0c0bcf62;
case 0x0c0bcf64u: goto P_0c0bcf64;
case 0x0c0bcf66u: goto P_0c0bcf66;
case 0x0c0bcf68u: goto P_0c0bcf68;
case 0x0c0bcf6au: goto P_0c0bcf6a;
case 0x0c0bcf6cu: goto P_0c0bcf6c;
case 0x0c0bcf6eu: goto P_0c0bcf6e;
case 0x0c0bcf70u: goto P_0c0bcf70;
case 0x0c0bcf72u: goto P_0c0bcf72;
case 0x0c0bcf74u: goto P_0c0bcf74;
case 0x0c0bcf76u: goto P_0c0bcf76;
case 0x0c0bcf78u: goto P_0c0bcf78;
case 0x0c0bcf7au: goto P_0c0bcf7a;
case 0x0c0bcf7cu: goto P_0c0bcf7c;
case 0x0c0bcf7eu: goto P_0c0bcf7e;
case 0x0c0bcf80u: goto P_0c0bcf80;
case 0x0c0bcf82u: goto P_0c0bcf82;
case 0x0c0bcf84u: goto P_0c0bcf84;
case 0x0c0bcf86u: goto P_0c0bcf86;
case 0x0c0bcf88u: goto P_0c0bcf88;
case 0x0c0bcf8au: goto P_0c0bcf8a;
case 0x0c0bcf8cu: goto P_0c0bcf8c;
case 0x0c0bcf8eu: goto P_0c0bcf8e;
case 0x0c0bcf90u: goto P_0c0bcf90;
case 0x0c0bcf92u: goto P_0c0bcf92;
case 0x0c0bcf94u: goto P_0c0bcf94;
case 0x0c0bcf96u: goto P_0c0bcf96;
case 0x0c0bcf98u: goto P_0c0bcf98;
case 0x0c0bcf9au: goto P_0c0bcf9a;
case 0x0c0bcf9cu: goto P_0c0bcf9c;
case 0x0c0bcf9eu: goto P_0c0bcf9e;
case 0x0c0bcfa0u: goto P_0c0bcfa0;
case 0x0c0bcfa2u: goto P_0c0bcfa2;
case 0x0c0bcfa4u: goto P_0c0bcfa4;
case 0x0c0bcfa6u: goto P_0c0bcfa6;
case 0x0c0bcfa8u: goto P_0c0bcfa8;
case 0x0c0bcfaau: goto P_0c0bcfaa;
case 0x0c0bcfacu: goto P_0c0bcfac;
case 0x0c0bcfaeu: goto P_0c0bcfae;
case 0x0c0bcfb0u: goto P_0c0bcfb0;
case 0x0c0bcfb2u: goto P_0c0bcfb2;
case 0x0c0bcfb4u: goto P_0c0bcfb4;
case 0x0c0bcfb6u: goto P_0c0bcfb6;
case 0x0c0bcfb8u: goto P_0c0bcfb8;
case 0x0c0bcfbau: goto P_0c0bcfba;
case 0x0c0bcfbcu: goto P_0c0bcfbc;
case 0x0c0bcfbeu: goto P_0c0bcfbe;
case 0x0c0bcfc0u: goto P_0c0bcfc0;
case 0x0c0bcfc2u: goto P_0c0bcfc2;
case 0x0c0bcfc4u: goto P_0c0bcfc4;
case 0x0c0bcfc6u: goto P_0c0bcfc6;
case 0x0c0bcfc8u: goto P_0c0bcfc8;
case 0x0c0bcfcau: goto P_0c0bcfca;
case 0x0c0bcfccu: goto P_0c0bcfcc;
case 0x0c0bcfceu: goto P_0c0bcfce;
case 0x0c0bcfd0u: goto P_0c0bcfd0;
case 0x0c0bcfd2u: goto P_0c0bcfd2;
case 0x0c0bcfd4u: goto P_0c0bcfd4;
case 0x0c0bcfd6u: goto P_0c0bcfd6;
case 0x0c0bcfd8u: goto P_0c0bcfd8;
case 0x0c0bcfdau: goto P_0c0bcfda;
case 0x0c0bcfdcu: goto P_0c0bcfdc;
case 0x0c0bcfdeu: goto P_0c0bcfde;
case 0x0c0bcfe0u: goto P_0c0bcfe0;
case 0x0c0bcfe2u: goto P_0c0bcfe2;
case 0x0c0bcfe4u: goto P_0c0bcfe4;
case 0x0c0bcfe6u: goto P_0c0bcfe6;
case 0x0c0bcfe8u: goto P_0c0bcfe8;
case 0x0c0bcfeau: goto P_0c0bcfea;
case 0x0c0bcfecu: goto P_0c0bcfec;
case 0x0c0bcfeeu: goto P_0c0bcfee;
case 0x0c0bcff0u: goto P_0c0bcff0;
case 0x0c0bcff2u: goto P_0c0bcff2;
case 0x0c0bcff4u: goto P_0c0bcff4;
case 0x0c0bcff6u: goto P_0c0bcff6;
case 0x0c0bcff8u: goto P_0c0bcff8;
case 0x0c0bcffau: goto P_0c0bcffa;
case 0x0c0bcffcu: goto P_0c0bcffc;
case 0x0c0bcffeu: goto P_0c0bcffe;
case 0x0c0bd000u: goto P_0c0bd000;
case 0x0c0bd002u: goto P_0c0bd002;
case 0x0c0bd004u: goto P_0c0bd004;
case 0x0c0bd006u: goto P_0c0bd006;
case 0x0c0bd008u: goto P_0c0bd008;
case 0x0c0bd00au: goto P_0c0bd00a;
case 0x0c0bd00cu: goto P_0c0bd00c;
case 0x0c0bd00eu: goto P_0c0bd00e;
case 0x0c0bd010u: goto P_0c0bd010;
case 0x0c0bd012u: goto P_0c0bd012;
case 0x0c0bd014u: goto P_0c0bd014;
case 0x0c0bd016u: goto P_0c0bd016;
case 0x0c0bd018u: goto P_0c0bd018;
case 0x0c0bd01au: goto P_0c0bd01a;
case 0x0c0bd01cu: goto P_0c0bd01c;
case 0x0c0bd01eu: goto P_0c0bd01e;
case 0x0c0bd020u: goto P_0c0bd020;
case 0x0c0bd022u: goto P_0c0bd022;
case 0x0c0bd024u: goto P_0c0bd024;
case 0x0c0bd026u: goto P_0c0bd026;
case 0x0c0bd028u: goto P_0c0bd028;
case 0x0c0bd02au: goto P_0c0bd02a;
case 0x0c0bd02cu: goto P_0c0bd02c;
case 0x0c0bd02eu: goto P_0c0bd02e;
case 0x0c0bd030u: goto P_0c0bd030;
case 0x0c0bd032u: goto P_0c0bd032;
case 0x0c0bd034u: goto P_0c0bd034;
case 0x0c0bd036u: goto P_0c0bd036;
case 0x0c0bd038u: goto P_0c0bd038;
case 0x0c0bd03au: goto P_0c0bd03a;
case 0x0c0bd03cu: goto P_0c0bd03c;
case 0x0c0bd03eu: goto P_0c0bd03e;
case 0x0c0bd040u: goto P_0c0bd040;
case 0x0c0bd042u: goto P_0c0bd042;
case 0x0c0bd044u: goto P_0c0bd044;
case 0x0c0bd046u: goto P_0c0bd046;
case 0x0c0bd048u: goto P_0c0bd048;
case 0x0c0bd04au: goto P_0c0bd04a;
case 0x0c0bd04cu: goto P_0c0bd04c;
case 0x0c0bd04eu: goto P_0c0bd04e;
case 0x0c0bd050u: goto P_0c0bd050;
case 0x0c0bd052u: goto P_0c0bd052;
case 0x0c0bd054u: goto P_0c0bd054;
case 0x0c0bd056u: goto P_0c0bd056;
case 0x0c0bd058u: goto P_0c0bd058;
case 0x0c0bd05au: goto P_0c0bd05a;
case 0x0c0bd05cu: goto P_0c0bd05c;
case 0x0c0bd05eu: goto P_0c0bd05e;
case 0x0c0bd060u: goto P_0c0bd060;
case 0x0c0bd062u: goto P_0c0bd062;
case 0x0c0bd064u: goto P_0c0bd064;
case 0x0c0bd066u: goto P_0c0bd066;
case 0x0c0bd068u: goto P_0c0bd068;
case 0x0c0bd06au: goto P_0c0bd06a;
case 0x0c0bd06cu: goto P_0c0bd06c;
case 0x0c0bd06eu: goto P_0c0bd06e;
case 0x0c0bd070u: goto P_0c0bd070;
case 0x0c0bd072u: goto P_0c0bd072;
case 0x0c0bd074u: goto P_0c0bd074;
case 0x0c0bd076u: goto P_0c0bd076;
case 0x0c0bd078u: goto P_0c0bd078;
case 0x0c0bd07au: goto P_0c0bd07a;
case 0x0c0bd07cu: goto P_0c0bd07c;
case 0x0c0bd07eu: goto P_0c0bd07e;
case 0x0c0bd080u: goto P_0c0bd080;
case 0x0c0bd082u: goto P_0c0bd082;
case 0x0c0bd084u: goto P_0c0bd084;
case 0x0c0bd086u: goto P_0c0bd086;
case 0x0c0bd088u: goto P_0c0bd088;
case 0x0c0bd102u: goto P_0c0bd102;
case 0x0c0bd104u: goto P_0c0bd104;
case 0x0c0bd106u: goto P_0c0bd106;
case 0x0c0bd108u: goto P_0c0bd108;
case 0x0c0bd10au: goto P_0c0bd10a;
case 0x0c0bd10cu: goto P_0c0bd10c;
case 0x0c0bd10eu: goto P_0c0bd10e;
case 0x0c0bd110u: goto P_0c0bd110;
case 0x0c0bd112u: goto P_0c0bd112;
case 0x0c0bd114u: goto P_0c0bd114;
case 0x0c0bd116u: goto P_0c0bd116;
case 0x0c0bd118u: goto P_0c0bd118;
case 0x0c0bd11au: goto P_0c0bd11a;
case 0x0c0bd11cu: goto P_0c0bd11c;
case 0x0c0bd11eu: goto P_0c0bd11e;
case 0x0c0bd120u: goto P_0c0bd120;
case 0x0c0bd122u: goto P_0c0bd122;
case 0x0c0bd124u: goto P_0c0bd124;
case 0x0c0bd126u: goto P_0c0bd126;
case 0x0c0bd128u: goto P_0c0bd128;
case 0x0c0bd12au: goto P_0c0bd12a;
case 0x0c0bd12cu: goto P_0c0bd12c;
case 0x0c0bd12eu: goto P_0c0bd12e;
case 0x0c0bd130u: goto P_0c0bd130;
case 0x0c0bd132u: goto P_0c0bd132;
case 0x0c0bd134u: goto P_0c0bd134;
case 0x0c0bd136u: goto P_0c0bd136;
case 0x0c0bd138u: goto P_0c0bd138;
case 0x0c0bd13au: goto P_0c0bd13a;
case 0x0c0bd13cu: goto P_0c0bd13c;
case 0x0c0bd13eu: goto P_0c0bd13e;
case 0x0c0bd140u: goto P_0c0bd140;
case 0x0c0bd142u: goto P_0c0bd142;
case 0x0c0bd144u: goto P_0c0bd144;
case 0x0c0bd146u: goto P_0c0bd146;
case 0x0c0bd148u: goto P_0c0bd148;
case 0x0c0bd14au: goto P_0c0bd14a;
case 0x0c0bd14cu: goto P_0c0bd14c;
case 0x0c0bd14eu: goto P_0c0bd14e;
case 0x0c0bd150u: goto P_0c0bd150;
case 0x0c0bd152u: goto P_0c0bd152;
case 0x0c0bd154u: goto P_0c0bd154;
case 0x0c0bd156u: goto P_0c0bd156;
case 0x0c0bd158u: goto P_0c0bd158;
case 0x0c0bd15au: goto P_0c0bd15a;
case 0x0c0bd15cu: goto P_0c0bd15c;
case 0x0c0bd15eu: goto P_0c0bd15e;
case 0x0c0bd160u: goto P_0c0bd160;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0bcd5e: /* original 2fe6, guest PC 0x0c0bcd5e */
if(!s->budget--) { s->failed_pc=0x0c0bcd5eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bcd60;
P_0c0bcd60: /* original 2fd6, guest PC 0x0c0bcd60 */
if(!s->budget--) { s->failed_pc=0x0c0bcd60u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bcd62;
P_0c0bcd62: /* original 2fc6, guest PC 0x0c0bcd62 */
if(!s->budget--) { s->failed_pc=0x0c0bcd62u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bcd64;
P_0c0bcd64: /* original 2fb6, guest PC 0x0c0bcd64 */
if(!s->budget--) { s->failed_pc=0x0c0bcd64u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bcd66;
P_0c0bcd66: /* original 2fa6, guest PC 0x0c0bcd66 */
if(!s->budget--) { s->failed_pc=0x0c0bcd66u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bcd68;
P_0c0bcd68: /* original 2f96, guest PC 0x0c0bcd68 */
if(!s->budget--) { s->failed_pc=0x0c0bcd68u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bcd6a;
P_0c0bcd6a: /* original 4f22, guest PC 0x0c0bcd6a */
if(!s->budget--) { s->failed_pc=0x0c0bcd6au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0bcd6c;
P_0c0bcd6c: /* original 5d44, guest PC 0x0c0bcd6c */
if(!s->budget--) { s->failed_pc=0x0c0bcd6cu; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0bcd6e;
P_0c0bcd6e: /* original 94a8, guest PC 0x0c0bcd6e */
if(!s->budget--) { s->failed_pc=0x0c0bcd6eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcec2u,2);
goto P_0c0bcd70;
P_0c0bcd70: /* original de6e, guest PC 0x0c0bcd70 */
if(!s->budget--) { s->failed_pc=0x0c0bcd70u; return 0; }
r[14]=read(ram,0x0c0bcf2cu,4);
goto P_0c0bcd72;
P_0c0bcd72: /* original 7ff8, guest PC 0x0c0bcd72 */
if(!s->budget--) { s->failed_pc=0x0c0bcd72u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0bcd74;
P_0c0bcd74: /* original 4e0b, guest PC 0x0c0bcd74 */
if(!s->budget--) { s->failed_pc=0x0c0bcd74u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcd78u;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcd78u) { target=s->pc; goto dispatch; }
goto P_0c0bcd78;
P_0c0bcd76: /* original 65d2, guest PC 0x0c0bcd76 */
if(!s->budget--) { s->failed_pc=0x0c0bcd76u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0bcd78;
P_0c0bcd78: /* original 94a4, guest PC 0x0c0bcd78 */
if(!s->budget--) { s->failed_pc=0x0c0bcd78u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcec4u,2);
goto P_0c0bcd7a;
P_0c0bcd7a: /* original 4e0b, guest PC 0x0c0bcd7a */
if(!s->budget--) { s->failed_pc=0x0c0bcd7au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcd7eu;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcd7eu) { target=s->pc; goto dispatch; }
goto P_0c0bcd7e;
P_0c0bcd7c: /* original 55d1, guest PC 0x0c0bcd7c */
if(!s->budget--) { s->failed_pc=0x0c0bcd7cu; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0bcd7e;
P_0c0bcd7e: /* original 94a2, guest PC 0x0c0bcd7e */
if(!s->budget--) { s->failed_pc=0x0c0bcd7eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcec6u,2);
goto P_0c0bcd80;
P_0c0bcd80: /* original 4e0b, guest PC 0x0c0bcd80 */
if(!s->budget--) { s->failed_pc=0x0c0bcd80u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcd84u;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcd84u) { target=s->pc; goto dispatch; }
goto P_0c0bcd84;
P_0c0bcd82: /* original 55d2, guest PC 0x0c0bcd82 */
if(!s->budget--) { s->failed_pc=0x0c0bcd82u; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0bcd84;
P_0c0bcd84: /* original 94a0, guest PC 0x0c0bcd84 */
if(!s->budget--) { s->failed_pc=0x0c0bcd84u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcec8u,2);
goto P_0c0bcd86;
P_0c0bcd86: /* original 4e0b, guest PC 0x0c0bcd86 */
if(!s->budget--) { s->failed_pc=0x0c0bcd86u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcd8au;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcd8au) { target=s->pc; goto dispatch; }
goto P_0c0bcd8a;
P_0c0bcd88: /* original 55d3, guest PC 0x0c0bcd88 */
if(!s->budget--) { s->failed_pc=0x0c0bcd88u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0bcd8a;
P_0c0bcd8a: /* original 949e, guest PC 0x0c0bcd8a */
if(!s->budget--) { s->failed_pc=0x0c0bcd8au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcecau,2);
goto P_0c0bcd8c;
P_0c0bcd8c: /* original 4e0b, guest PC 0x0c0bcd8c */
if(!s->budget--) { s->failed_pc=0x0c0bcd8cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcd90u;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcd90u) { target=s->pc; goto dispatch; }
goto P_0c0bcd90;
P_0c0bcd8e: /* original 55d4, guest PC 0x0c0bcd8e */
if(!s->budget--) { s->failed_pc=0x0c0bcd8eu; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0bcd90;
P_0c0bcd90: /* original 949c, guest PC 0x0c0bcd90 */
if(!s->budget--) { s->failed_pc=0x0c0bcd90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bceccu,2);
goto P_0c0bcd92;
P_0c0bcd92: /* original 4e0b, guest PC 0x0c0bcd92 */
if(!s->budget--) { s->failed_pc=0x0c0bcd92u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcd96u;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcd96u) { target=s->pc; goto dispatch; }
goto P_0c0bcd96;
P_0c0bcd94: /* original 55d5, guest PC 0x0c0bcd94 */
if(!s->budget--) { s->failed_pc=0x0c0bcd94u; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0bcd96;
P_0c0bcd96: /* original 949a, guest PC 0x0c0bcd96 */
if(!s->budget--) { s->failed_pc=0x0c0bcd96u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bceceu,2);
goto P_0c0bcd98;
P_0c0bcd98: /* original 4e0b, guest PC 0x0c0bcd98 */
if(!s->budget--) { s->failed_pc=0x0c0bcd98u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcd9cu;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcd9cu) { target=s->pc; goto dispatch; }
goto P_0c0bcd9c;
P_0c0bcd9a: /* original 55d6, guest PC 0x0c0bcd9a */
if(!s->budget--) { s->failed_pc=0x0c0bcd9au; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0bcd9c;
P_0c0bcd9c: /* original 9498, guest PC 0x0c0bcd9c */
if(!s->budget--) { s->failed_pc=0x0c0bcd9cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bced0u,2);
goto P_0c0bcd9e;
P_0c0bcd9e: /* original 4e0b, guest PC 0x0c0bcd9e */
if(!s->budget--) { s->failed_pc=0x0c0bcd9eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcda2u;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcda2u) { target=s->pc; goto dispatch; }
goto P_0c0bcda2;
P_0c0bcda0: /* original 55d7, guest PC 0x0c0bcda0 */
if(!s->budget--) { s->failed_pc=0x0c0bcda0u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0bcda2;
P_0c0bcda2: /* original 9496, guest PC 0x0c0bcda2 */
if(!s->budget--) { s->failed_pc=0x0c0bcda2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bced2u,2);
goto P_0c0bcda4;
P_0c0bcda4: /* original 4e0b, guest PC 0x0c0bcda4 */
if(!s->budget--) { s->failed_pc=0x0c0bcda4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcda8u;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcda8u) { target=s->pc; goto dispatch; }
goto P_0c0bcda8;
P_0c0bcda6: /* original 55d8, guest PC 0x0c0bcda6 */
if(!s->budget--) { s->failed_pc=0x0c0bcda6u; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0bcda8;
P_0c0bcda8: /* original 9494, guest PC 0x0c0bcda8 */
if(!s->budget--) { s->failed_pc=0x0c0bcda8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bced4u,2);
goto P_0c0bcdaa;
P_0c0bcdaa: /* original 4e0b, guest PC 0x0c0bcdaa */
if(!s->budget--) { s->failed_pc=0x0c0bcdaau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcdaeu;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcdaeu) { target=s->pc; goto dispatch; }
goto P_0c0bcdae;
P_0c0bcdac: /* original 55d9, guest PC 0x0c0bcdac */
if(!s->budget--) { s->failed_pc=0x0c0bcdacu; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0bcdae;
P_0c0bcdae: /* original 9492, guest PC 0x0c0bcdae */
if(!s->budget--) { s->failed_pc=0x0c0bcdaeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bced6u,2);
goto P_0c0bcdb0;
P_0c0bcdb0: /* original 4e0b, guest PC 0x0c0bcdb0 */
if(!s->budget--) { s->failed_pc=0x0c0bcdb0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcdb4u;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcdb4u) { target=s->pc; goto dispatch; }
goto P_0c0bcdb4;
P_0c0bcdb2: /* original 55da, guest PC 0x0c0bcdb2 */
if(!s->budget--) { s->failed_pc=0x0c0bcdb2u; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0bcdb4;
P_0c0bcdb4: /* original 9490, guest PC 0x0c0bcdb4 */
if(!s->budget--) { s->failed_pc=0x0c0bcdb4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bced8u,2);
goto P_0c0bcdb6;
P_0c0bcdb6: /* original 4e0b, guest PC 0x0c0bcdb6 */
if(!s->budget--) { s->failed_pc=0x0c0bcdb6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcdbau;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcdbau) { target=s->pc; goto dispatch; }
goto P_0c0bcdba;
P_0c0bcdb8: /* original 55db, guest PC 0x0c0bcdb8 */
if(!s->budget--) { s->failed_pc=0x0c0bcdb8u; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0bcdba;
P_0c0bcdba: /* original 948e, guest PC 0x0c0bcdba */
if(!s->budget--) { s->failed_pc=0x0c0bcdbau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcedau,2);
goto P_0c0bcdbc;
P_0c0bcdbc: /* original 4e0b, guest PC 0x0c0bcdbc */
if(!s->budget--) { s->failed_pc=0x0c0bcdbcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcdc0u;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcdc0u) { target=s->pc; goto dispatch; }
goto P_0c0bcdc0;
P_0c0bcdbe: /* original 55dc, guest PC 0x0c0bcdbe */
if(!s->budget--) { s->failed_pc=0x0c0bcdbeu; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0bcdc0;
P_0c0bcdc0: /* original 948c, guest PC 0x0c0bcdc0 */
if(!s->budget--) { s->failed_pc=0x0c0bcdc0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcedcu,2);
goto P_0c0bcdc2;
P_0c0bcdc2: /* original 4e0b, guest PC 0x0c0bcdc2 */
if(!s->budget--) { s->failed_pc=0x0c0bcdc2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcdc6u;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcdc6u) { target=s->pc; goto dispatch; }
goto P_0c0bcdc6;
P_0c0bcdc4: /* original 55dd, guest PC 0x0c0bcdc4 */
if(!s->budget--) { s->failed_pc=0x0c0bcdc4u; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0bcdc6;
P_0c0bcdc6: /* original 948a, guest PC 0x0c0bcdc6 */
if(!s->budget--) { s->failed_pc=0x0c0bcdc6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcedeu,2);
goto P_0c0bcdc8;
P_0c0bcdc8: /* original 4e0b, guest PC 0x0c0bcdc8 */
if(!s->budget--) { s->failed_pc=0x0c0bcdc8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcdccu;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcdccu) { target=s->pc; goto dispatch; }
goto P_0c0bcdcc;
P_0c0bcdca: /* original 55de, guest PC 0x0c0bcdca */
if(!s->budget--) { s->failed_pc=0x0c0bcdcau; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0bcdcc;
P_0c0bcdcc: /* original 9488, guest PC 0x0c0bcdcc */
if(!s->budget--) { s->failed_pc=0x0c0bcdccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcee0u,2);
goto P_0c0bcdce;
P_0c0bcdce: /* original 4e0b, guest PC 0x0c0bcdce */
if(!s->budget--) { s->failed_pc=0x0c0bcdceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcdd2u;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcdd2u) { target=s->pc; goto dispatch; }
goto P_0c0bcdd2;
P_0c0bcdd0: /* original 55df, guest PC 0x0c0bcdd0 */
if(!s->budget--) { s->failed_pc=0x0c0bcdd0u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0bcdd2;
P_0c0bcdd2: /* original 9486, guest PC 0x0c0bcdd2 */
if(!s->budget--) { s->failed_pc=0x0c0bcdd2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcee2u,2);
goto P_0c0bcdd4;
P_0c0bcdd4: /* original e040, guest PC 0x0c0bcdd4 */
if(!s->budget--) { s->failed_pc=0x0c0bcdd4u; return 0; }
r[0]=0x00000040u;
goto P_0c0bcdd6;
P_0c0bcdd6: /* original 4e0b, guest PC 0x0c0bcdd6 */
if(!s->budget--) { s->failed_pc=0x0c0bcdd6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcddau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcddau) { target=s->pc; goto dispatch; }
goto P_0c0bcdda;
P_0c0bcdd8: /* original 05de, guest PC 0x0c0bcdd8 */
if(!s->budget--) { s->failed_pc=0x0c0bcdd8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bcdda;
P_0c0bcdda: /* original 9483, guest PC 0x0c0bcdda */
if(!s->budget--) { s->failed_pc=0x0c0bcddau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcee4u,2);
goto P_0c0bcddc;
P_0c0bcddc: /* original e044, guest PC 0x0c0bcddc */
if(!s->budget--) { s->failed_pc=0x0c0bcddcu; return 0; }
r[0]=0x00000044u;
goto P_0c0bcdde;
P_0c0bcdde: /* original 4e0b, guest PC 0x0c0bcdde */
if(!s->budget--) { s->failed_pc=0x0c0bcddeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcde2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcde2u) { target=s->pc; goto dispatch; }
goto P_0c0bcde2;
P_0c0bcde0: /* original 05de, guest PC 0x0c0bcde0 */
if(!s->budget--) { s->failed_pc=0x0c0bcde0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bcde2;
P_0c0bcde2: /* original 9480, guest PC 0x0c0bcde2 */
if(!s->budget--) { s->failed_pc=0x0c0bcde2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcee6u,2);
goto P_0c0bcde4;
P_0c0bcde4: /* original e048, guest PC 0x0c0bcde4 */
if(!s->budget--) { s->failed_pc=0x0c0bcde4u; return 0; }
r[0]=0x00000048u;
goto P_0c0bcde6;
P_0c0bcde6: /* original 4e0b, guest PC 0x0c0bcde6 */
if(!s->budget--) { s->failed_pc=0x0c0bcde6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcdeau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcdeau) { target=s->pc; goto dispatch; }
goto P_0c0bcdea;
P_0c0bcde8: /* original 05de, guest PC 0x0c0bcde8 */
if(!s->budget--) { s->failed_pc=0x0c0bcde8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bcdea;
P_0c0bcdea: /* original 947d, guest PC 0x0c0bcdea */
if(!s->budget--) { s->failed_pc=0x0c0bcdeau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcee8u,2);
goto P_0c0bcdec;
P_0c0bcdec: /* original e04c, guest PC 0x0c0bcdec */
if(!s->budget--) { s->failed_pc=0x0c0bcdecu; return 0; }
r[0]=0x0000004cu;
goto P_0c0bcdee;
P_0c0bcdee: /* original 4e0b, guest PC 0x0c0bcdee */
if(!s->budget--) { s->failed_pc=0x0c0bcdeeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcdf2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcdf2u) { target=s->pc; goto dispatch; }
goto P_0c0bcdf2;
P_0c0bcdf0: /* original 05de, guest PC 0x0c0bcdf0 */
if(!s->budget--) { s->failed_pc=0x0c0bcdf0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bcdf2;
P_0c0bcdf2: /* original 947a, guest PC 0x0c0bcdf2 */
if(!s->budget--) { s->failed_pc=0x0c0bcdf2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bceeau,2);
goto P_0c0bcdf4;
P_0c0bcdf4: /* original e050, guest PC 0x0c0bcdf4 */
if(!s->budget--) { s->failed_pc=0x0c0bcdf4u; return 0; }
r[0]=0x00000050u;
goto P_0c0bcdf6;
P_0c0bcdf6: /* original 4e0b, guest PC 0x0c0bcdf6 */
if(!s->budget--) { s->failed_pc=0x0c0bcdf6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcdfau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcdfau) { target=s->pc; goto dispatch; }
goto P_0c0bcdfa;
P_0c0bcdf8: /* original 05de, guest PC 0x0c0bcdf8 */
if(!s->budget--) { s->failed_pc=0x0c0bcdf8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bcdfa;
P_0c0bcdfa: /* original 9477, guest PC 0x0c0bcdfa */
if(!s->budget--) { s->failed_pc=0x0c0bcdfau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bceecu,2);
goto P_0c0bcdfc;
P_0c0bcdfc: /* original e054, guest PC 0x0c0bcdfc */
if(!s->budget--) { s->failed_pc=0x0c0bcdfcu; return 0; }
r[0]=0x00000054u;
goto P_0c0bcdfe;
P_0c0bcdfe: /* original 4e0b, guest PC 0x0c0bcdfe */
if(!s->budget--) { s->failed_pc=0x0c0bcdfeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bce02u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bce02u) { target=s->pc; goto dispatch; }
goto P_0c0bce02;
P_0c0bce00: /* original 05de, guest PC 0x0c0bce00 */
if(!s->budget--) { s->failed_pc=0x0c0bce00u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bce02;
P_0c0bce02: /* original 9474, guest PC 0x0c0bce02 */
if(!s->budget--) { s->failed_pc=0x0c0bce02u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bceeeu,2);
goto P_0c0bce04;
P_0c0bce04: /* original e058, guest PC 0x0c0bce04 */
if(!s->budget--) { s->failed_pc=0x0c0bce04u; return 0; }
r[0]=0x00000058u;
goto P_0c0bce06;
P_0c0bce06: /* original 4e0b, guest PC 0x0c0bce06 */
if(!s->budget--) { s->failed_pc=0x0c0bce06u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bce0au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bce0au) { target=s->pc; goto dispatch; }
goto P_0c0bce0a;
P_0c0bce08: /* original 05de, guest PC 0x0c0bce08 */
if(!s->budget--) { s->failed_pc=0x0c0bce08u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bce0a;
P_0c0bce0a: /* original 9471, guest PC 0x0c0bce0a */
if(!s->budget--) { s->failed_pc=0x0c0bce0au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcef0u,2);
goto P_0c0bce0c;
P_0c0bce0c: /* original e05c, guest PC 0x0c0bce0c */
if(!s->budget--) { s->failed_pc=0x0c0bce0cu; return 0; }
r[0]=0x0000005cu;
goto P_0c0bce0e;
P_0c0bce0e: /* original 4e0b, guest PC 0x0c0bce0e */
if(!s->budget--) { s->failed_pc=0x0c0bce0eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bce12u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bce12u) { target=s->pc; goto dispatch; }
goto P_0c0bce12;
P_0c0bce10: /* original 05de, guest PC 0x0c0bce10 */
if(!s->budget--) { s->failed_pc=0x0c0bce10u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bce12;
P_0c0bce12: /* original 946e, guest PC 0x0c0bce12 */
if(!s->budget--) { s->failed_pc=0x0c0bce12u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcef2u,2);
goto P_0c0bce14;
P_0c0bce14: /* original e060, guest PC 0x0c0bce14 */
if(!s->budget--) { s->failed_pc=0x0c0bce14u; return 0; }
r[0]=0x00000060u;
goto P_0c0bce16;
P_0c0bce16: /* original 4e0b, guest PC 0x0c0bce16 */
if(!s->budget--) { s->failed_pc=0x0c0bce16u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bce1au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bce1au) { target=s->pc; goto dispatch; }
goto P_0c0bce1a;
P_0c0bce18: /* original 05de, guest PC 0x0c0bce18 */
if(!s->budget--) { s->failed_pc=0x0c0bce18u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bce1a;
P_0c0bce1a: /* original 946b, guest PC 0x0c0bce1a */
if(!s->budget--) { s->failed_pc=0x0c0bce1au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcef4u,2);
goto P_0c0bce1c;
P_0c0bce1c: /* original e064, guest PC 0x0c0bce1c */
if(!s->budget--) { s->failed_pc=0x0c0bce1cu; return 0; }
r[0]=0x00000064u;
goto P_0c0bce1e;
P_0c0bce1e: /* original 4e0b, guest PC 0x0c0bce1e */
if(!s->budget--) { s->failed_pc=0x0c0bce1eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bce22u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bce22u) { target=s->pc; goto dispatch; }
goto P_0c0bce22;
P_0c0bce20: /* original 05de, guest PC 0x0c0bce20 */
if(!s->budget--) { s->failed_pc=0x0c0bce20u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bce22;
P_0c0bce22: /* original 9468, guest PC 0x0c0bce22 */
if(!s->budget--) { s->failed_pc=0x0c0bce22u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcef6u,2);
goto P_0c0bce24;
P_0c0bce24: /* original e068, guest PC 0x0c0bce24 */
if(!s->budget--) { s->failed_pc=0x0c0bce24u; return 0; }
r[0]=0x00000068u;
goto P_0c0bce26;
P_0c0bce26: /* original 4e0b, guest PC 0x0c0bce26 */
if(!s->budget--) { s->failed_pc=0x0c0bce26u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bce2au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bce2au) { target=s->pc; goto dispatch; }
goto P_0c0bce2a;
P_0c0bce28: /* original 05de, guest PC 0x0c0bce28 */
if(!s->budget--) { s->failed_pc=0x0c0bce28u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bce2a;
P_0c0bce2a: /* original 9465, guest PC 0x0c0bce2a */
if(!s->budget--) { s->failed_pc=0x0c0bce2au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcef8u,2);
goto P_0c0bce2c;
P_0c0bce2c: /* original e06c, guest PC 0x0c0bce2c */
if(!s->budget--) { s->failed_pc=0x0c0bce2cu; return 0; }
r[0]=0x0000006cu;
goto P_0c0bce2e;
P_0c0bce2e: /* original 4e0b, guest PC 0x0c0bce2e */
if(!s->budget--) { s->failed_pc=0x0c0bce2eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bce32u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bce32u) { target=s->pc; goto dispatch; }
goto P_0c0bce32;
P_0c0bce30: /* original 05de, guest PC 0x0c0bce30 */
if(!s->budget--) { s->failed_pc=0x0c0bce30u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bce32;
P_0c0bce32: /* original 9462, guest PC 0x0c0bce32 */
if(!s->budget--) { s->failed_pc=0x0c0bce32u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcefau,2);
goto P_0c0bce34;
P_0c0bce34: /* original e070, guest PC 0x0c0bce34 */
if(!s->budget--) { s->failed_pc=0x0c0bce34u; return 0; }
r[0]=0x00000070u;
goto P_0c0bce36;
P_0c0bce36: /* original 4e0b, guest PC 0x0c0bce36 */
if(!s->budget--) { s->failed_pc=0x0c0bce36u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bce3au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bce3au) { target=s->pc; goto dispatch; }
goto P_0c0bce3a;
P_0c0bce38: /* original 05de, guest PC 0x0c0bce38 */
if(!s->budget--) { s->failed_pc=0x0c0bce38u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bce3a;
P_0c0bce3a: /* original 945f, guest PC 0x0c0bce3a */
if(!s->budget--) { s->failed_pc=0x0c0bce3au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcefcu,2);
goto P_0c0bce3c;
P_0c0bce3c: /* original e074, guest PC 0x0c0bce3c */
if(!s->budget--) { s->failed_pc=0x0c0bce3cu; return 0; }
r[0]=0x00000074u;
goto P_0c0bce3e;
P_0c0bce3e: /* original 4e0b, guest PC 0x0c0bce3e */
if(!s->budget--) { s->failed_pc=0x0c0bce3eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bce42u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bce42u) { target=s->pc; goto dispatch; }
goto P_0c0bce42;
P_0c0bce40: /* original 05de, guest PC 0x0c0bce40 */
if(!s->budget--) { s->failed_pc=0x0c0bce40u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bce42;
P_0c0bce42: /* original 945c, guest PC 0x0c0bce42 */
if(!s->budget--) { s->failed_pc=0x0c0bce42u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcefeu,2);
goto P_0c0bce44;
P_0c0bce44: /* original e078, guest PC 0x0c0bce44 */
if(!s->budget--) { s->failed_pc=0x0c0bce44u; return 0; }
r[0]=0x00000078u;
goto P_0c0bce46;
P_0c0bce46: /* original 4e0b, guest PC 0x0c0bce46 */
if(!s->budget--) { s->failed_pc=0x0c0bce46u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bce4au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bce4au) { target=s->pc; goto dispatch; }
goto P_0c0bce4a;
P_0c0bce48: /* original 05de, guest PC 0x0c0bce48 */
if(!s->budget--) { s->failed_pc=0x0c0bce48u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bce4a;
P_0c0bce4a: /* original 9459, guest PC 0x0c0bce4a */
if(!s->budget--) { s->failed_pc=0x0c0bce4au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcf00u,2);
goto P_0c0bce4c;
P_0c0bce4c: /* original e07c, guest PC 0x0c0bce4c */
if(!s->budget--) { s->failed_pc=0x0c0bce4cu; return 0; }
r[0]=0x0000007cu;
goto P_0c0bce4e;
P_0c0bce4e: /* original 4e0b, guest PC 0x0c0bce4e */
if(!s->budget--) { s->failed_pc=0x0c0bce4eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bce52u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bce52u) { target=s->pc; goto dispatch; }
goto P_0c0bce52;
P_0c0bce50: /* original 05de, guest PC 0x0c0bce50 */
if(!s->budget--) { s->failed_pc=0x0c0bce50u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bce52;
P_0c0bce52: /* original 9457, guest PC 0x0c0bce52 */
if(!s->budget--) { s->failed_pc=0x0c0bce52u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcf04u,2);
goto P_0c0bce54;
P_0c0bce54: /* original 9055, guest PC 0x0c0bce54 */
if(!s->budget--) { s->failed_pc=0x0c0bce54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcf02u,2);
goto P_0c0bce56;
P_0c0bce56: /* original 4e0b, guest PC 0x0c0bce56 */
if(!s->budget--) { s->failed_pc=0x0c0bce56u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bce5au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bce5au) { target=s->pc; goto dispatch; }
goto P_0c0bce5a;
P_0c0bce58: /* original 05de, guest PC 0x0c0bce58 */
if(!s->budget--) { s->failed_pc=0x0c0bce58u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bce5a;
P_0c0bce5a: /* original 9554, guest PC 0x0c0bce5a */
if(!s->budget--) { s->failed_pc=0x0c0bce5au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcf06u,2);
goto P_0c0bce5c;
P_0c0bce5c: /* original 35dc, guest PC 0x0c0bce5c */
if(!s->budget--) { s->failed_pc=0x0c0bce5cu; return 0; }
r[5]+=r[13];
goto P_0c0bce5e;
P_0c0bce5e: /* original 2f52, guest PC 0x0c0bce5e */
if(!s->budget--) { s->failed_pc=0x0c0bce5eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bce60;
P_0c0bce60: /* original 9452, guest PC 0x0c0bce60 */
if(!s->budget--) { s->failed_pc=0x0c0bce60u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcf08u,2);
goto P_0c0bce62;
P_0c0bce62: /* original 4e0b, guest PC 0x0c0bce62 */
if(!s->budget--) { s->failed_pc=0x0c0bce62u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bce66u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bce66u) { target=s->pc; goto dispatch; }
goto P_0c0bce66;
P_0c0bce64: /* original 6552, guest PC 0x0c0bce64 */
if(!s->budget--) { s->failed_pc=0x0c0bce64u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bce66;
P_0c0bce66: /* original 9550, guest PC 0x0c0bce66 */
if(!s->budget--) { s->failed_pc=0x0c0bce66u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcf0au,2);
goto P_0c0bce68;
P_0c0bce68: /* original 35dc, guest PC 0x0c0bce68 */
if(!s->budget--) { s->failed_pc=0x0c0bce68u; return 0; }
r[5]+=r[13];
goto P_0c0bce6a;
P_0c0bce6a: /* original 1f51, guest PC 0x0c0bce6a */
if(!s->budget--) { s->failed_pc=0x0c0bce6au; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0bce6c;
P_0c0bce6c: /* original 944e, guest PC 0x0c0bce6c */
if(!s->budget--) { s->failed_pc=0x0c0bce6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcf0cu,2);
goto P_0c0bce6e;
P_0c0bce6e: /* original 4e0b, guest PC 0x0c0bce6e */
if(!s->budget--) { s->failed_pc=0x0c0bce6eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bce72u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bce72u) { target=s->pc; goto dispatch; }
goto P_0c0bce72;
P_0c0bce70: /* original 6552, guest PC 0x0c0bce70 */
if(!s->budget--) { s->failed_pc=0x0c0bce70u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bce72;
P_0c0bce72: /* original 944d, guest PC 0x0c0bce72 */
if(!s->budget--) { s->failed_pc=0x0c0bce72u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcf10u,2);
goto P_0c0bce74;
P_0c0bce74: /* original 904b, guest PC 0x0c0bce74 */
if(!s->budget--) { s->failed_pc=0x0c0bce74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcf0eu,2);
goto P_0c0bce76;
P_0c0bce76: /* original 4e0b, guest PC 0x0c0bce76 */
if(!s->budget--) { s->failed_pc=0x0c0bce76u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bce7au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bce7au) { target=s->pc; goto dispatch; }
goto P_0c0bce7a;
P_0c0bce78: /* original 05de, guest PC 0x0c0bce78 */
if(!s->budget--) { s->failed_pc=0x0c0bce78u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bce7a;
P_0c0bce7a: /* original 944b, guest PC 0x0c0bce7a */
if(!s->budget--) { s->failed_pc=0x0c0bce7au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcf14u,2);
goto P_0c0bce7c;
P_0c0bce7c: /* original 9049, guest PC 0x0c0bce7c */
if(!s->budget--) { s->failed_pc=0x0c0bce7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcf12u,2);
goto P_0c0bce7e;
P_0c0bce7e: /* original 4e0b, guest PC 0x0c0bce7e */
if(!s->budget--) { s->failed_pc=0x0c0bce7eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bce82u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bce82u) { target=s->pc; goto dispatch; }
goto P_0c0bce82;
P_0c0bce80: /* original 05de, guest PC 0x0c0bce80 */
if(!s->budget--) { s->failed_pc=0x0c0bce80u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bce82;
P_0c0bce82: /* original 9948, guest PC 0x0c0bce82 */
if(!s->budget--) { s->failed_pc=0x0c0bce82u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcf16u,2);
goto P_0c0bce84;
P_0c0bce84: /* original 9448, guest PC 0x0c0bce84 */
if(!s->budget--) { s->failed_pc=0x0c0bce84u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcf18u,2);
goto P_0c0bce86;
P_0c0bce86: /* original 39dc, guest PC 0x0c0bce86 */
if(!s->budget--) { s->failed_pc=0x0c0bce86u; return 0; }
r[9]+=r[13];
goto P_0c0bce88;
P_0c0bce88: /* original 4e0b, guest PC 0x0c0bce88 */
if(!s->budget--) { s->failed_pc=0x0c0bce88u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bce8cu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bce8cu) { target=s->pc; goto dispatch; }
goto P_0c0bce8c;
P_0c0bce8a: /* original 6592, guest PC 0x0c0bce8a */
if(!s->budget--) { s->failed_pc=0x0c0bce8au; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bce8c;
P_0c0bce8c: /* original 9445, guest PC 0x0c0bce8c */
if(!s->budget--) { s->failed_pc=0x0c0bce8cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcf1au,2);
goto P_0c0bce8e;
P_0c0bce8e: /* original 4e0b, guest PC 0x0c0bce8e */
if(!s->budget--) { s->failed_pc=0x0c0bce8eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bce92u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bce92u) { target=s->pc; goto dispatch; }
goto P_0c0bce92;
P_0c0bce90: /* original 6592, guest PC 0x0c0bce90 */
if(!s->budget--) { s->failed_pc=0x0c0bce90u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bce92;
P_0c0bce92: /* original 9443, guest PC 0x0c0bce92 */
if(!s->budget--) { s->failed_pc=0x0c0bce92u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcf1cu,2);
goto P_0c0bce94;
P_0c0bce94: /* original 4e0b, guest PC 0x0c0bce94 */
if(!s->budget--) { s->failed_pc=0x0c0bce94u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bce98u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bce98u) { target=s->pc; goto dispatch; }
goto P_0c0bce98;
P_0c0bce96: /* original 6592, guest PC 0x0c0bce96 */
if(!s->budget--) { s->failed_pc=0x0c0bce96u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bce98;
P_0c0bce98: /* original 9441, guest PC 0x0c0bce98 */
if(!s->budget--) { s->failed_pc=0x0c0bce98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcf1eu,2);
goto P_0c0bce9a;
P_0c0bce9a: /* original 4e0b, guest PC 0x0c0bce9a */
if(!s->budget--) { s->failed_pc=0x0c0bce9au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bce9eu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bce9eu) { target=s->pc; goto dispatch; }
goto P_0c0bce9e;
P_0c0bce9c: /* original 6592, guest PC 0x0c0bce9c */
if(!s->budget--) { s->failed_pc=0x0c0bce9cu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bce9e;
P_0c0bce9e: /* original 9c3f, guest PC 0x0c0bce9e */
if(!s->budget--) { s->failed_pc=0x0c0bce9eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcf20u,2);
goto P_0c0bcea0;
P_0c0bcea0: /* original 943f, guest PC 0x0c0bcea0 */
if(!s->budget--) { s->failed_pc=0x0c0bcea0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcf22u,2);
goto P_0c0bcea2;
P_0c0bcea2: /* original 3cdc, guest PC 0x0c0bcea2 */
if(!s->budget--) { s->failed_pc=0x0c0bcea2u; return 0; }
r[12]+=r[13];
goto P_0c0bcea4;
P_0c0bcea4: /* original 4e0b, guest PC 0x0c0bcea4 */
if(!s->budget--) { s->failed_pc=0x0c0bcea4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcea8u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcea8u) { target=s->pc; goto dispatch; }
goto P_0c0bcea8;
P_0c0bcea6: /* original 65c2, guest PC 0x0c0bcea6 */
if(!s->budget--) { s->failed_pc=0x0c0bcea6u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bcea8;
P_0c0bcea8: /* original 943c, guest PC 0x0c0bcea8 */
if(!s->budget--) { s->failed_pc=0x0c0bcea8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcf24u,2);
goto P_0c0bceaa;
P_0c0bceaa: /* original 4e0b, guest PC 0x0c0bceaa */
if(!s->budget--) { s->failed_pc=0x0c0bceaau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bceaeu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bceaeu) { target=s->pc; goto dispatch; }
goto P_0c0bceae;
P_0c0bceac: /* original 65c2, guest PC 0x0c0bceac */
if(!s->budget--) { s->failed_pc=0x0c0bceacu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bceae;
P_0c0bceae: /* original 943a, guest PC 0x0c0bceae */
if(!s->budget--) { s->failed_pc=0x0c0bceaeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcf26u,2);
goto P_0c0bceb0;
P_0c0bceb0: /* original 4e0b, guest PC 0x0c0bceb0 */
if(!s->budget--) { s->failed_pc=0x0c0bceb0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bceb4u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bceb4u) { target=s->pc; goto dispatch; }
goto P_0c0bceb4;
P_0c0bceb2: /* original 65c2, guest PC 0x0c0bceb2 */
if(!s->budget--) { s->failed_pc=0x0c0bceb2u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bceb4;
P_0c0bceb4: /* original 9438, guest PC 0x0c0bceb4 */
if(!s->budget--) { s->failed_pc=0x0c0bceb4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcf28u,2);
goto P_0c0bceb6;
P_0c0bceb6: /* original 4e0b, guest PC 0x0c0bceb6 */
if(!s->budget--) { s->failed_pc=0x0c0bceb6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcebau;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcebau) { target=s->pc; goto dispatch; }
goto P_0c0bceba;
P_0c0bceb8: /* original 65c2, guest PC 0x0c0bceb8 */
if(!s->budget--) { s->failed_pc=0x0c0bceb8u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bceba;
P_0c0bceba: /* original 9b36, guest PC 0x0c0bceba */
if(!s->budget--) { s->failed_pc=0x0c0bcebau; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bcf2au,2);
goto P_0c0bcebc;
P_0c0bcebc: /* original 3bdc, guest PC 0x0c0bcebc */
if(!s->budget--) { s->failed_pc=0x0c0bcebcu; return 0; }
r[11]+=r[13];
goto P_0c0bcebe;
P_0c0bcebe: /* original a037, guest PC 0x0c0bcebe */
if(!s->budget--) { s->failed_pc=0x0c0bcebeu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bcf30;
P_0c0bcec0: /* original 65b2, guest PC 0x0c0bcec0 */
if(!s->budget--) { s->failed_pc=0x0c0bcec0u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0bcec2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bcec2u; return 0; } return 1;
P_0c0bcf30: /* original 94ab, guest PC 0x0c0bcf30 */
if(!s->budget--) { s->failed_pc=0x0c0bcf30u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd08au,2);
goto P_0c0bcf32;
P_0c0bcf32: /* original 4e0b, guest PC 0x0c0bcf32 */
if(!s->budget--) { s->failed_pc=0x0c0bcf32u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcf36u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcf36u) { target=s->pc; goto dispatch; }
goto P_0c0bcf36;
P_0c0bcf34: /* original 0009, guest PC 0x0c0bcf34 */
if(!s->budget--) { s->failed_pc=0x0c0bcf34u; return 0; }
goto P_0c0bcf36;
P_0c0bcf36: /* original 94a9, guest PC 0x0c0bcf36 */
if(!s->budget--) { s->failed_pc=0x0c0bcf36u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd08cu,2);
goto P_0c0bcf38;
P_0c0bcf38: /* original 4e0b, guest PC 0x0c0bcf38 */
if(!s->budget--) { s->failed_pc=0x0c0bcf38u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcf3cu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcf3cu) { target=s->pc; goto dispatch; }
goto P_0c0bcf3c;
P_0c0bcf3a: /* original 65b2, guest PC 0x0c0bcf3a */
if(!s->budget--) { s->failed_pc=0x0c0bcf3au; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bcf3c;
P_0c0bcf3c: /* original 94a7, guest PC 0x0c0bcf3c */
if(!s->budget--) { s->failed_pc=0x0c0bcf3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd08eu,2);
goto P_0c0bcf3e;
P_0c0bcf3e: /* original 4e0b, guest PC 0x0c0bcf3e */
if(!s->budget--) { s->failed_pc=0x0c0bcf3eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcf42u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcf42u) { target=s->pc; goto dispatch; }
goto P_0c0bcf42;
P_0c0bcf40: /* original 65b2, guest PC 0x0c0bcf40 */
if(!s->budget--) { s->failed_pc=0x0c0bcf40u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bcf42;
P_0c0bcf42: /* original 94a5, guest PC 0x0c0bcf42 */
if(!s->budget--) { s->failed_pc=0x0c0bcf42u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd090u,2);
goto P_0c0bcf44;
P_0c0bcf44: /* original 4e0b, guest PC 0x0c0bcf44 */
if(!s->budget--) { s->failed_pc=0x0c0bcf44u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcf48u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcf48u) { target=s->pc; goto dispatch; }
goto P_0c0bcf48;
P_0c0bcf46: /* original 65b2, guest PC 0x0c0bcf46 */
if(!s->budget--) { s->failed_pc=0x0c0bcf46u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bcf48;
P_0c0bcf48: /* original 9aa3, guest PC 0x0c0bcf48 */
if(!s->budget--) { s->failed_pc=0x0c0bcf48u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd092u,2);
goto P_0c0bcf4a;
P_0c0bcf4a: /* original 94a3, guest PC 0x0c0bcf4a */
if(!s->budget--) { s->failed_pc=0x0c0bcf4au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd094u,2);
goto P_0c0bcf4c;
P_0c0bcf4c: /* original 3adc, guest PC 0x0c0bcf4c */
if(!s->budget--) { s->failed_pc=0x0c0bcf4cu; return 0; }
r[10]+=r[13];
goto P_0c0bcf4e;
P_0c0bcf4e: /* original 4e0b, guest PC 0x0c0bcf4e */
if(!s->budget--) { s->failed_pc=0x0c0bcf4eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcf52u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcf52u) { target=s->pc; goto dispatch; }
goto P_0c0bcf52;
P_0c0bcf50: /* original 65a2, guest PC 0x0c0bcf50 */
if(!s->budget--) { s->failed_pc=0x0c0bcf50u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bcf52;
P_0c0bcf52: /* original 94a0, guest PC 0x0c0bcf52 */
if(!s->budget--) { s->failed_pc=0x0c0bcf52u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd096u,2);
goto P_0c0bcf54;
P_0c0bcf54: /* original 4e0b, guest PC 0x0c0bcf54 */
if(!s->budget--) { s->failed_pc=0x0c0bcf54u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcf58u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcf58u) { target=s->pc; goto dispatch; }
goto P_0c0bcf58;
P_0c0bcf56: /* original 65a2, guest PC 0x0c0bcf56 */
if(!s->budget--) { s->failed_pc=0x0c0bcf56u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bcf58;
P_0c0bcf58: /* original 949e, guest PC 0x0c0bcf58 */
if(!s->budget--) { s->failed_pc=0x0c0bcf58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd098u,2);
goto P_0c0bcf5a;
P_0c0bcf5a: /* original 4e0b, guest PC 0x0c0bcf5a */
if(!s->budget--) { s->failed_pc=0x0c0bcf5au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcf5eu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcf5eu) { target=s->pc; goto dispatch; }
goto P_0c0bcf5e;
P_0c0bcf5c: /* original 65a2, guest PC 0x0c0bcf5c */
if(!s->budget--) { s->failed_pc=0x0c0bcf5cu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bcf5e;
P_0c0bcf5e: /* original 949c, guest PC 0x0c0bcf5e */
if(!s->budget--) { s->failed_pc=0x0c0bcf5eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd09au,2);
goto P_0c0bcf60;
P_0c0bcf60: /* original 4e0b, guest PC 0x0c0bcf60 */
if(!s->budget--) { s->failed_pc=0x0c0bcf60u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcf64u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcf64u) { target=s->pc; goto dispatch; }
goto P_0c0bcf64;
P_0c0bcf62: /* original 65a2, guest PC 0x0c0bcf62 */
if(!s->budget--) { s->failed_pc=0x0c0bcf62u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bcf64;
P_0c0bcf64: /* original 949a, guest PC 0x0c0bcf64 */
if(!s->budget--) { s->failed_pc=0x0c0bcf64u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd09cu,2);
goto P_0c0bcf66;
P_0c0bcf66: /* original 65f2, guest PC 0x0c0bcf66 */
if(!s->budget--) { s->failed_pc=0x0c0bcf66u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bcf68;
P_0c0bcf68: /* original 4e0b, guest PC 0x0c0bcf68 */
if(!s->budget--) { s->failed_pc=0x0c0bcf68u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcf6cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcf6cu) { target=s->pc; goto dispatch; }
goto P_0c0bcf6c;
P_0c0bcf6a: /* original 6552, guest PC 0x0c0bcf6a */
if(!s->budget--) { s->failed_pc=0x0c0bcf6au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bcf6c;
P_0c0bcf6c: /* original 9497, guest PC 0x0c0bcf6c */
if(!s->budget--) { s->failed_pc=0x0c0bcf6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd09eu,2);
goto P_0c0bcf6e;
P_0c0bcf6e: /* original 55f1, guest PC 0x0c0bcf6e */
if(!s->budget--) { s->failed_pc=0x0c0bcf6eu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0bcf70;
P_0c0bcf70: /* original 4e0b, guest PC 0x0c0bcf70 */
if(!s->budget--) { s->failed_pc=0x0c0bcf70u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcf74u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcf74u) { target=s->pc; goto dispatch; }
goto P_0c0bcf74;
P_0c0bcf72: /* original 6552, guest PC 0x0c0bcf72 */
if(!s->budget--) { s->failed_pc=0x0c0bcf72u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bcf74;
P_0c0bcf74: /* original 9494, guest PC 0x0c0bcf74 */
if(!s->budget--) { s->failed_pc=0x0c0bcf74u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0a0u,2);
goto P_0c0bcf76;
P_0c0bcf76: /* original 4e0b, guest PC 0x0c0bcf76 */
if(!s->budget--) { s->failed_pc=0x0c0bcf76u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcf7au;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcf7au) { target=s->pc; goto dispatch; }
goto P_0c0bcf7a;
P_0c0bcf78: /* original 6592, guest PC 0x0c0bcf78 */
if(!s->budget--) { s->failed_pc=0x0c0bcf78u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bcf7a;
P_0c0bcf7a: /* original 9492, guest PC 0x0c0bcf7a */
if(!s->budget--) { s->failed_pc=0x0c0bcf7au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0a2u,2);
goto P_0c0bcf7c;
P_0c0bcf7c: /* original 4e0b, guest PC 0x0c0bcf7c */
if(!s->budget--) { s->failed_pc=0x0c0bcf7cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcf80u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcf80u) { target=s->pc; goto dispatch; }
goto P_0c0bcf80;
P_0c0bcf7e: /* original 6592, guest PC 0x0c0bcf7e */
if(!s->budget--) { s->failed_pc=0x0c0bcf7eu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bcf80;
P_0c0bcf80: /* original 9490, guest PC 0x0c0bcf80 */
if(!s->budget--) { s->failed_pc=0x0c0bcf80u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0a4u,2);
goto P_0c0bcf82;
P_0c0bcf82: /* original 4e0b, guest PC 0x0c0bcf82 */
if(!s->budget--) { s->failed_pc=0x0c0bcf82u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcf86u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcf86u) { target=s->pc; goto dispatch; }
goto P_0c0bcf86;
P_0c0bcf84: /* original 6592, guest PC 0x0c0bcf84 */
if(!s->budget--) { s->failed_pc=0x0c0bcf84u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bcf86;
P_0c0bcf86: /* original 948e, guest PC 0x0c0bcf86 */
if(!s->budget--) { s->failed_pc=0x0c0bcf86u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0a6u,2);
goto P_0c0bcf88;
P_0c0bcf88: /* original 4e0b, guest PC 0x0c0bcf88 */
if(!s->budget--) { s->failed_pc=0x0c0bcf88u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcf8cu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcf8cu) { target=s->pc; goto dispatch; }
goto P_0c0bcf8c;
P_0c0bcf8a: /* original 6592, guest PC 0x0c0bcf8a */
if(!s->budget--) { s->failed_pc=0x0c0bcf8au; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bcf8c;
P_0c0bcf8c: /* original 948c, guest PC 0x0c0bcf8c */
if(!s->budget--) { s->failed_pc=0x0c0bcf8cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0a8u,2);
goto P_0c0bcf8e;
P_0c0bcf8e: /* original 4e0b, guest PC 0x0c0bcf8e */
if(!s->budget--) { s->failed_pc=0x0c0bcf8eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcf92u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcf92u) { target=s->pc; goto dispatch; }
goto P_0c0bcf92;
P_0c0bcf90: /* original 65c2, guest PC 0x0c0bcf90 */
if(!s->budget--) { s->failed_pc=0x0c0bcf90u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bcf92;
P_0c0bcf92: /* original 948a, guest PC 0x0c0bcf92 */
if(!s->budget--) { s->failed_pc=0x0c0bcf92u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0aau,2);
goto P_0c0bcf94;
P_0c0bcf94: /* original 4e0b, guest PC 0x0c0bcf94 */
if(!s->budget--) { s->failed_pc=0x0c0bcf94u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcf98u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcf98u) { target=s->pc; goto dispatch; }
goto P_0c0bcf98;
P_0c0bcf96: /* original 65c2, guest PC 0x0c0bcf96 */
if(!s->budget--) { s->failed_pc=0x0c0bcf96u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bcf98;
P_0c0bcf98: /* original 9488, guest PC 0x0c0bcf98 */
if(!s->budget--) { s->failed_pc=0x0c0bcf98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0acu,2);
goto P_0c0bcf9a;
P_0c0bcf9a: /* original 4e0b, guest PC 0x0c0bcf9a */
if(!s->budget--) { s->failed_pc=0x0c0bcf9au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcf9eu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcf9eu) { target=s->pc; goto dispatch; }
goto P_0c0bcf9e;
P_0c0bcf9c: /* original 65c2, guest PC 0x0c0bcf9c */
if(!s->budget--) { s->failed_pc=0x0c0bcf9cu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bcf9e;
P_0c0bcf9e: /* original 9486, guest PC 0x0c0bcf9e */
if(!s->budget--) { s->failed_pc=0x0c0bcf9eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0aeu,2);
goto P_0c0bcfa0;
P_0c0bcfa0: /* original 4e0b, guest PC 0x0c0bcfa0 */
if(!s->budget--) { s->failed_pc=0x0c0bcfa0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcfa4u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcfa4u) { target=s->pc; goto dispatch; }
goto P_0c0bcfa4;
P_0c0bcfa2: /* original 65c2, guest PC 0x0c0bcfa2 */
if(!s->budget--) { s->failed_pc=0x0c0bcfa2u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bcfa4;
P_0c0bcfa4: /* original 9484, guest PC 0x0c0bcfa4 */
if(!s->budget--) { s->failed_pc=0x0c0bcfa4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0b0u,2);
goto P_0c0bcfa6;
P_0c0bcfa6: /* original 4e0b, guest PC 0x0c0bcfa6 */
if(!s->budget--) { s->failed_pc=0x0c0bcfa6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcfaau;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcfaau) { target=s->pc; goto dispatch; }
goto P_0c0bcfaa;
P_0c0bcfa8: /* original 65b2, guest PC 0x0c0bcfa8 */
if(!s->budget--) { s->failed_pc=0x0c0bcfa8u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bcfaa;
P_0c0bcfaa: /* original 9482, guest PC 0x0c0bcfaa */
if(!s->budget--) { s->failed_pc=0x0c0bcfaau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0b2u,2);
goto P_0c0bcfac;
P_0c0bcfac: /* original 4e0b, guest PC 0x0c0bcfac */
if(!s->budget--) { s->failed_pc=0x0c0bcfacu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcfb0u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcfb0u) { target=s->pc; goto dispatch; }
goto P_0c0bcfb0;
P_0c0bcfae: /* original 65b2, guest PC 0x0c0bcfae */
if(!s->budget--) { s->failed_pc=0x0c0bcfaeu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bcfb0;
P_0c0bcfb0: /* original 9480, guest PC 0x0c0bcfb0 */
if(!s->budget--) { s->failed_pc=0x0c0bcfb0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0b4u,2);
goto P_0c0bcfb2;
P_0c0bcfb2: /* original 4e0b, guest PC 0x0c0bcfb2 */
if(!s->budget--) { s->failed_pc=0x0c0bcfb2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcfb6u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcfb6u) { target=s->pc; goto dispatch; }
goto P_0c0bcfb6;
P_0c0bcfb4: /* original 65b2, guest PC 0x0c0bcfb4 */
if(!s->budget--) { s->failed_pc=0x0c0bcfb4u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bcfb6;
P_0c0bcfb6: /* original 947e, guest PC 0x0c0bcfb6 */
if(!s->budget--) { s->failed_pc=0x0c0bcfb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0b6u,2);
goto P_0c0bcfb8;
P_0c0bcfb8: /* original 4e0b, guest PC 0x0c0bcfb8 */
if(!s->budget--) { s->failed_pc=0x0c0bcfb8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcfbcu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcfbcu) { target=s->pc; goto dispatch; }
goto P_0c0bcfbc;
P_0c0bcfba: /* original 65b2, guest PC 0x0c0bcfba */
if(!s->budget--) { s->failed_pc=0x0c0bcfbau; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bcfbc;
P_0c0bcfbc: /* original 947c, guest PC 0x0c0bcfbc */
if(!s->budget--) { s->failed_pc=0x0c0bcfbcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0b8u,2);
goto P_0c0bcfbe;
P_0c0bcfbe: /* original 4e0b, guest PC 0x0c0bcfbe */
if(!s->budget--) { s->failed_pc=0x0c0bcfbeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcfc2u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcfc2u) { target=s->pc; goto dispatch; }
goto P_0c0bcfc2;
P_0c0bcfc0: /* original 65a2, guest PC 0x0c0bcfc0 */
if(!s->budget--) { s->failed_pc=0x0c0bcfc0u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bcfc2;
P_0c0bcfc2: /* original 947a, guest PC 0x0c0bcfc2 */
if(!s->budget--) { s->failed_pc=0x0c0bcfc2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0bau,2);
goto P_0c0bcfc4;
P_0c0bcfc4: /* original 4e0b, guest PC 0x0c0bcfc4 */
if(!s->budget--) { s->failed_pc=0x0c0bcfc4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcfc8u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcfc8u) { target=s->pc; goto dispatch; }
goto P_0c0bcfc8;
P_0c0bcfc6: /* original 65a2, guest PC 0x0c0bcfc6 */
if(!s->budget--) { s->failed_pc=0x0c0bcfc6u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bcfc8;
P_0c0bcfc8: /* original 9478, guest PC 0x0c0bcfc8 */
if(!s->budget--) { s->failed_pc=0x0c0bcfc8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0bcu,2);
goto P_0c0bcfca;
P_0c0bcfca: /* original 4e0b, guest PC 0x0c0bcfca */
if(!s->budget--) { s->failed_pc=0x0c0bcfcau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcfceu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcfceu) { target=s->pc; goto dispatch; }
goto P_0c0bcfce;
P_0c0bcfcc: /* original 65a2, guest PC 0x0c0bcfcc */
if(!s->budget--) { s->failed_pc=0x0c0bcfccu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bcfce;
P_0c0bcfce: /* original 9476, guest PC 0x0c0bcfce */
if(!s->budget--) { s->failed_pc=0x0c0bcfceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0beu,2);
goto P_0c0bcfd0;
P_0c0bcfd0: /* original 4e0b, guest PC 0x0c0bcfd0 */
if(!s->budget--) { s->failed_pc=0x0c0bcfd0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcfd4u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcfd4u) { target=s->pc; goto dispatch; }
goto P_0c0bcfd4;
P_0c0bcfd2: /* original 65a2, guest PC 0x0c0bcfd2 */
if(!s->budget--) { s->failed_pc=0x0c0bcfd2u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bcfd4;
P_0c0bcfd4: /* original 9574, guest PC 0x0c0bcfd4 */
if(!s->budget--) { s->failed_pc=0x0c0bcfd4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0c0u,2);
goto P_0c0bcfd6;
P_0c0bcfd6: /* original 35dc, guest PC 0x0c0bcfd6 */
if(!s->budget--) { s->failed_pc=0x0c0bcfd6u; return 0; }
r[5]+=r[13];
goto P_0c0bcfd8;
P_0c0bcfd8: /* original 2f52, guest PC 0x0c0bcfd8 */
if(!s->budget--) { s->failed_pc=0x0c0bcfd8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bcfda;
P_0c0bcfda: /* original 9472, guest PC 0x0c0bcfda */
if(!s->budget--) { s->failed_pc=0x0c0bcfdau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0c2u,2);
goto P_0c0bcfdc;
P_0c0bcfdc: /* original 4e0b, guest PC 0x0c0bcfdc */
if(!s->budget--) { s->failed_pc=0x0c0bcfdcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcfe0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcfe0u) { target=s->pc; goto dispatch; }
goto P_0c0bcfe0;
P_0c0bcfde: /* original 6552, guest PC 0x0c0bcfde */
if(!s->budget--) { s->failed_pc=0x0c0bcfdeu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bcfe0;
P_0c0bcfe0: /* original 9470, guest PC 0x0c0bcfe0 */
if(!s->budget--) { s->failed_pc=0x0c0bcfe0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0c4u,2);
goto P_0c0bcfe2;
P_0c0bcfe2: /* original 65f2, guest PC 0x0c0bcfe2 */
if(!s->budget--) { s->failed_pc=0x0c0bcfe2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bcfe4;
P_0c0bcfe4: /* original 4e0b, guest PC 0x0c0bcfe4 */
if(!s->budget--) { s->failed_pc=0x0c0bcfe4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcfe8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcfe8u) { target=s->pc; goto dispatch; }
goto P_0c0bcfe8;
P_0c0bcfe6: /* original 6552, guest PC 0x0c0bcfe6 */
if(!s->budget--) { s->failed_pc=0x0c0bcfe6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bcfe8;
P_0c0bcfe8: /* original 956d, guest PC 0x0c0bcfe8 */
if(!s->budget--) { s->failed_pc=0x0c0bcfe8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0c6u,2);
goto P_0c0bcfea;
P_0c0bcfea: /* original 35dc, guest PC 0x0c0bcfea */
if(!s->budget--) { s->failed_pc=0x0c0bcfeau; return 0; }
r[5]+=r[13];
goto P_0c0bcfec;
P_0c0bcfec: /* original 2f52, guest PC 0x0c0bcfec */
if(!s->budget--) { s->failed_pc=0x0c0bcfecu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bcfee;
P_0c0bcfee: /* original 946b, guest PC 0x0c0bcfee */
if(!s->budget--) { s->failed_pc=0x0c0bcfeeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0c8u,2);
goto P_0c0bcff0;
P_0c0bcff0: /* original 4e0b, guest PC 0x0c0bcff0 */
if(!s->budget--) { s->failed_pc=0x0c0bcff0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcff4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcff4u) { target=s->pc; goto dispatch; }
goto P_0c0bcff4;
P_0c0bcff2: /* original 6552, guest PC 0x0c0bcff2 */
if(!s->budget--) { s->failed_pc=0x0c0bcff2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bcff4;
P_0c0bcff4: /* original 9469, guest PC 0x0c0bcff4 */
if(!s->budget--) { s->failed_pc=0x0c0bcff4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0cau,2);
goto P_0c0bcff6;
P_0c0bcff6: /* original 65f2, guest PC 0x0c0bcff6 */
if(!s->budget--) { s->failed_pc=0x0c0bcff6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bcff8;
P_0c0bcff8: /* original 4e0b, guest PC 0x0c0bcff8 */
if(!s->budget--) { s->failed_pc=0x0c0bcff8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bcffcu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bcffcu) { target=s->pc; goto dispatch; }
goto P_0c0bcffc;
P_0c0bcffa: /* original 6552, guest PC 0x0c0bcffa */
if(!s->budget--) { s->failed_pc=0x0c0bcffau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bcffc;
P_0c0bcffc: /* original 9467, guest PC 0x0c0bcffc */
if(!s->budget--) { s->failed_pc=0x0c0bcffcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0ceu,2);
goto P_0c0bcffe;
P_0c0bcffe: /* original 9065, guest PC 0x0c0bcffe */
if(!s->budget--) { s->failed_pc=0x0c0bcffeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0ccu,2);
goto P_0c0bd000;
P_0c0bd000: /* original 4e0b, guest PC 0x0c0bd000 */
if(!s->budget--) { s->failed_pc=0x0c0bd000u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd004u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd004u) { target=s->pc; goto dispatch; }
goto P_0c0bd004;
P_0c0bd002: /* original 05de, guest PC 0x0c0bd002 */
if(!s->budget--) { s->failed_pc=0x0c0bd002u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd004;
P_0c0bd004: /* original 9564, guest PC 0x0c0bd004 */
if(!s->budget--) { s->failed_pc=0x0c0bd004u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0d0u,2);
goto P_0c0bd006;
P_0c0bd006: /* original 35dc, guest PC 0x0c0bd006 */
if(!s->budget--) { s->failed_pc=0x0c0bd006u; return 0; }
r[5]+=r[13];
goto P_0c0bd008;
P_0c0bd008: /* original 2f52, guest PC 0x0c0bd008 */
if(!s->budget--) { s->failed_pc=0x0c0bd008u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bd00a;
P_0c0bd00a: /* original 9462, guest PC 0x0c0bd00a */
if(!s->budget--) { s->failed_pc=0x0c0bd00au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0d2u,2);
goto P_0c0bd00c;
P_0c0bd00c: /* original 4e0b, guest PC 0x0c0bd00c */
if(!s->budget--) { s->failed_pc=0x0c0bd00cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd010u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd010u) { target=s->pc; goto dispatch; }
goto P_0c0bd010;
P_0c0bd00e: /* original 6552, guest PC 0x0c0bd00e */
if(!s->budget--) { s->failed_pc=0x0c0bd00eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd010;
P_0c0bd010: /* original 9460, guest PC 0x0c0bd010 */
if(!s->budget--) { s->failed_pc=0x0c0bd010u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0d4u,2);
goto P_0c0bd012;
P_0c0bd012: /* original 65f2, guest PC 0x0c0bd012 */
if(!s->budget--) { s->failed_pc=0x0c0bd012u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bd014;
P_0c0bd014: /* original 4e0b, guest PC 0x0c0bd014 */
if(!s->budget--) { s->failed_pc=0x0c0bd014u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd018u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd018u) { target=s->pc; goto dispatch; }
goto P_0c0bd018;
P_0c0bd016: /* original 6552, guest PC 0x0c0bd016 */
if(!s->budget--) { s->failed_pc=0x0c0bd016u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd018;
P_0c0bd018: /* original 945e, guest PC 0x0c0bd018 */
if(!s->budget--) { s->failed_pc=0x0c0bd018u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0d8u,2);
goto P_0c0bd01a;
P_0c0bd01a: /* original 905c, guest PC 0x0c0bd01a */
if(!s->budget--) { s->failed_pc=0x0c0bd01au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0d6u,2);
goto P_0c0bd01c;
P_0c0bd01c: /* original 4e0b, guest PC 0x0c0bd01c */
if(!s->budget--) { s->failed_pc=0x0c0bd01cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd020u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd020u) { target=s->pc; goto dispatch; }
goto P_0c0bd020;
P_0c0bd01e: /* original 05de, guest PC 0x0c0bd01e */
if(!s->budget--) { s->failed_pc=0x0c0bd01eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd020;
P_0c0bd020: /* original 955b, guest PC 0x0c0bd020 */
if(!s->budget--) { s->failed_pc=0x0c0bd020u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0dau,2);
goto P_0c0bd022;
P_0c0bd022: /* original 35dc, guest PC 0x0c0bd022 */
if(!s->budget--) { s->failed_pc=0x0c0bd022u; return 0; }
r[5]+=r[13];
goto P_0c0bd024;
P_0c0bd024: /* original 2f52, guest PC 0x0c0bd024 */
if(!s->budget--) { s->failed_pc=0x0c0bd024u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bd026;
P_0c0bd026: /* original 9459, guest PC 0x0c0bd026 */
if(!s->budget--) { s->failed_pc=0x0c0bd026u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0dcu,2);
goto P_0c0bd028;
P_0c0bd028: /* original 4e0b, guest PC 0x0c0bd028 */
if(!s->budget--) { s->failed_pc=0x0c0bd028u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd02cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd02cu) { target=s->pc; goto dispatch; }
goto P_0c0bd02c;
P_0c0bd02a: /* original 6552, guest PC 0x0c0bd02a */
if(!s->budget--) { s->failed_pc=0x0c0bd02au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd02c;
P_0c0bd02c: /* original 9457, guest PC 0x0c0bd02c */
if(!s->budget--) { s->failed_pc=0x0c0bd02cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0deu,2);
goto P_0c0bd02e;
P_0c0bd02e: /* original 65f2, guest PC 0x0c0bd02e */
if(!s->budget--) { s->failed_pc=0x0c0bd02eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bd030;
P_0c0bd030: /* original 4e0b, guest PC 0x0c0bd030 */
if(!s->budget--) { s->failed_pc=0x0c0bd030u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd034u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd034u) { target=s->pc; goto dispatch; }
goto P_0c0bd034;
P_0c0bd032: /* original 6552, guest PC 0x0c0bd032 */
if(!s->budget--) { s->failed_pc=0x0c0bd032u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd034;
P_0c0bd034: /* original 9455, guest PC 0x0c0bd034 */
if(!s->budget--) { s->failed_pc=0x0c0bd034u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0e2u,2);
goto P_0c0bd036;
P_0c0bd036: /* original 9053, guest PC 0x0c0bd036 */
if(!s->budget--) { s->failed_pc=0x0c0bd036u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0e0u,2);
goto P_0c0bd038;
P_0c0bd038: /* original 4e0b, guest PC 0x0c0bd038 */
if(!s->budget--) { s->failed_pc=0x0c0bd038u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd03cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd03cu) { target=s->pc; goto dispatch; }
goto P_0c0bd03c;
P_0c0bd03a: /* original 05de, guest PC 0x0c0bd03a */
if(!s->budget--) { s->failed_pc=0x0c0bd03au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd03c;
P_0c0bd03c: /* original 9552, guest PC 0x0c0bd03c */
if(!s->budget--) { s->failed_pc=0x0c0bd03cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0e4u,2);
goto P_0c0bd03e;
P_0c0bd03e: /* original 35dc, guest PC 0x0c0bd03e */
if(!s->budget--) { s->failed_pc=0x0c0bd03eu; return 0; }
r[5]+=r[13];
goto P_0c0bd040;
P_0c0bd040: /* original 2f52, guest PC 0x0c0bd040 */
if(!s->budget--) { s->failed_pc=0x0c0bd040u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bd042;
P_0c0bd042: /* original 9450, guest PC 0x0c0bd042 */
if(!s->budget--) { s->failed_pc=0x0c0bd042u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0e6u,2);
goto P_0c0bd044;
P_0c0bd044: /* original 4e0b, guest PC 0x0c0bd044 */
if(!s->budget--) { s->failed_pc=0x0c0bd044u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd048u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd048u) { target=s->pc; goto dispatch; }
goto P_0c0bd048;
P_0c0bd046: /* original 6552, guest PC 0x0c0bd046 */
if(!s->budget--) { s->failed_pc=0x0c0bd046u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd048;
P_0c0bd048: /* original 944e, guest PC 0x0c0bd048 */
if(!s->budget--) { s->failed_pc=0x0c0bd048u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0e8u,2);
goto P_0c0bd04a;
P_0c0bd04a: /* original 65f2, guest PC 0x0c0bd04a */
if(!s->budget--) { s->failed_pc=0x0c0bd04au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bd04c;
P_0c0bd04c: /* original 4e0b, guest PC 0x0c0bd04c */
if(!s->budget--) { s->failed_pc=0x0c0bd04cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd050u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd050u) { target=s->pc; goto dispatch; }
goto P_0c0bd050;
P_0c0bd04e: /* original 6552, guest PC 0x0c0bd04e */
if(!s->budget--) { s->failed_pc=0x0c0bd04eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd050;
P_0c0bd050: /* original 954b, guest PC 0x0c0bd050 */
if(!s->budget--) { s->failed_pc=0x0c0bd050u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0eau,2);
goto P_0c0bd052;
P_0c0bd052: /* original 35dc, guest PC 0x0c0bd052 */
if(!s->budget--) { s->failed_pc=0x0c0bd052u; return 0; }
r[5]+=r[13];
goto P_0c0bd054;
P_0c0bd054: /* original 2f52, guest PC 0x0c0bd054 */
if(!s->budget--) { s->failed_pc=0x0c0bd054u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bd056;
P_0c0bd056: /* original 9449, guest PC 0x0c0bd056 */
if(!s->budget--) { s->failed_pc=0x0c0bd056u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0ecu,2);
goto P_0c0bd058;
P_0c0bd058: /* original 4e0b, guest PC 0x0c0bd058 */
if(!s->budget--) { s->failed_pc=0x0c0bd058u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd05cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd05cu) { target=s->pc; goto dispatch; }
goto P_0c0bd05c;
P_0c0bd05a: /* original 6552, guest PC 0x0c0bd05a */
if(!s->budget--) { s->failed_pc=0x0c0bd05au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd05c;
P_0c0bd05c: /* original 9447, guest PC 0x0c0bd05c */
if(!s->budget--) { s->failed_pc=0x0c0bd05cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0eeu,2);
goto P_0c0bd05e;
P_0c0bd05e: /* original 65f2, guest PC 0x0c0bd05e */
if(!s->budget--) { s->failed_pc=0x0c0bd05eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bd060;
P_0c0bd060: /* original 4e0b, guest PC 0x0c0bd060 */
if(!s->budget--) { s->failed_pc=0x0c0bd060u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd064u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd064u) { target=s->pc; goto dispatch; }
goto P_0c0bd064;
P_0c0bd062: /* original 6552, guest PC 0x0c0bd062 */
if(!s->budget--) { s->failed_pc=0x0c0bd062u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bd064;
P_0c0bd064: /* original 9445, guest PC 0x0c0bd064 */
if(!s->budget--) { s->failed_pc=0x0c0bd064u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0f2u,2);
goto P_0c0bd066;
P_0c0bd066: /* original 9043, guest PC 0x0c0bd066 */
if(!s->budget--) { s->failed_pc=0x0c0bd066u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0f0u,2);
goto P_0c0bd068;
P_0c0bd068: /* original 4e0b, guest PC 0x0c0bd068 */
if(!s->budget--) { s->failed_pc=0x0c0bd068u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd06cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd06cu) { target=s->pc; goto dispatch; }
goto P_0c0bd06c;
P_0c0bd06a: /* original 05de, guest PC 0x0c0bd06a */
if(!s->budget--) { s->failed_pc=0x0c0bd06au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd06c;
P_0c0bd06c: /* original 9443, guest PC 0x0c0bd06c */
if(!s->budget--) { s->failed_pc=0x0c0bd06cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0f6u,2);
goto P_0c0bd06e;
P_0c0bd06e: /* original 9041, guest PC 0x0c0bd06e */
if(!s->budget--) { s->failed_pc=0x0c0bd06eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0f4u,2);
goto P_0c0bd070;
P_0c0bd070: /* original 4e0b, guest PC 0x0c0bd070 */
if(!s->budget--) { s->failed_pc=0x0c0bd070u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd074u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd074u) { target=s->pc; goto dispatch; }
goto P_0c0bd074;
P_0c0bd072: /* original 05de, guest PC 0x0c0bd072 */
if(!s->budget--) { s->failed_pc=0x0c0bd072u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd074;
P_0c0bd074: /* original 9441, guest PC 0x0c0bd074 */
if(!s->budget--) { s->failed_pc=0x0c0bd074u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0fau,2);
goto P_0c0bd076;
P_0c0bd076: /* original 903f, guest PC 0x0c0bd076 */
if(!s->budget--) { s->failed_pc=0x0c0bd076u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0f8u,2);
goto P_0c0bd078;
P_0c0bd078: /* original 4e0b, guest PC 0x0c0bd078 */
if(!s->budget--) { s->failed_pc=0x0c0bd078u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd07cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd07cu) { target=s->pc; goto dispatch; }
goto P_0c0bd07c;
P_0c0bd07a: /* original 05de, guest PC 0x0c0bd07a */
if(!s->budget--) { s->failed_pc=0x0c0bd07au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd07c;
P_0c0bd07c: /* original 943f, guest PC 0x0c0bd07c */
if(!s->budget--) { s->failed_pc=0x0c0bd07cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0feu,2);
goto P_0c0bd07e;
P_0c0bd07e: /* original 903d, guest PC 0x0c0bd07e */
if(!s->budget--) { s->failed_pc=0x0c0bd07eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd0fcu,2);
goto P_0c0bd080;
P_0c0bd080: /* original 4e0b, guest PC 0x0c0bd080 */
if(!s->budget--) { s->failed_pc=0x0c0bd080u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd084u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd084u) { target=s->pc; goto dispatch; }
goto P_0c0bd084;
P_0c0bd082: /* original 05de, guest PC 0x0c0bd082 */
if(!s->budget--) { s->failed_pc=0x0c0bd082u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd084;
P_0c0bd084: /* original 903c, guest PC 0x0c0bd084 */
if(!s->budget--) { s->failed_pc=0x0c0bd084u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd100u,2);
goto P_0c0bd086;
P_0c0bd086: /* original a03c, guest PC 0x0c0bd086 */
if(!s->budget--) { s->failed_pc=0x0c0bd086u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd102;
P_0c0bd088: /* original 05de, guest PC 0x0c0bd088 */
if(!s->budget--) { s->failed_pc=0x0c0bd088u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0bd08au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bd08au; return 0; } return 1;
P_0c0bd102: /* original 942e, guest PC 0x0c0bd102 */
if(!s->budget--) { s->failed_pc=0x0c0bd102u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd162u,2);
goto P_0c0bd104;
P_0c0bd104: /* original 4e0b, guest PC 0x0c0bd104 */
if(!s->budget--) { s->failed_pc=0x0c0bd104u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd108u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd108u) { target=s->pc; goto dispatch; }
goto P_0c0bd108;
P_0c0bd106: /* original 0009, guest PC 0x0c0bd106 */
if(!s->budget--) { s->failed_pc=0x0c0bd106u; return 0; }
goto P_0c0bd108;
P_0c0bd108: /* original 942d, guest PC 0x0c0bd108 */
if(!s->budget--) { s->failed_pc=0x0c0bd108u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd166u,2);
goto P_0c0bd10a;
P_0c0bd10a: /* original 902b, guest PC 0x0c0bd10a */
if(!s->budget--) { s->failed_pc=0x0c0bd10au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd164u,2);
goto P_0c0bd10c;
P_0c0bd10c: /* original 4e0b, guest PC 0x0c0bd10c */
if(!s->budget--) { s->failed_pc=0x0c0bd10cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd110u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd110u) { target=s->pc; goto dispatch; }
goto P_0c0bd110;
P_0c0bd10e: /* original 05de, guest PC 0x0c0bd10e */
if(!s->budget--) { s->failed_pc=0x0c0bd10eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd110;
P_0c0bd110: /* original 942b, guest PC 0x0c0bd110 */
if(!s->budget--) { s->failed_pc=0x0c0bd110u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd16au,2);
goto P_0c0bd112;
P_0c0bd112: /* original 9029, guest PC 0x0c0bd112 */
if(!s->budget--) { s->failed_pc=0x0c0bd112u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd168u,2);
goto P_0c0bd114;
P_0c0bd114: /* original 4e0b, guest PC 0x0c0bd114 */
if(!s->budget--) { s->failed_pc=0x0c0bd114u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd118u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd118u) { target=s->pc; goto dispatch; }
goto P_0c0bd118;
P_0c0bd116: /* original 05de, guest PC 0x0c0bd116 */
if(!s->budget--) { s->failed_pc=0x0c0bd116u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd118;
P_0c0bd118: /* original 9429, guest PC 0x0c0bd118 */
if(!s->budget--) { s->failed_pc=0x0c0bd118u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd16eu,2);
goto P_0c0bd11a;
P_0c0bd11a: /* original 9027, guest PC 0x0c0bd11a */
if(!s->budget--) { s->failed_pc=0x0c0bd11au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd16cu,2);
goto P_0c0bd11c;
P_0c0bd11c: /* original 4e0b, guest PC 0x0c0bd11c */
if(!s->budget--) { s->failed_pc=0x0c0bd11cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd120u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd120u) { target=s->pc; goto dispatch; }
goto P_0c0bd120;
P_0c0bd11e: /* original 05de, guest PC 0x0c0bd11e */
if(!s->budget--) { s->failed_pc=0x0c0bd11eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd120;
P_0c0bd120: /* original 9427, guest PC 0x0c0bd120 */
if(!s->budget--) { s->failed_pc=0x0c0bd120u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd172u,2);
goto P_0c0bd122;
P_0c0bd122: /* original 9025, guest PC 0x0c0bd122 */
if(!s->budget--) { s->failed_pc=0x0c0bd122u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd170u,2);
goto P_0c0bd124;
P_0c0bd124: /* original 4e0b, guest PC 0x0c0bd124 */
if(!s->budget--) { s->failed_pc=0x0c0bd124u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd128u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd128u) { target=s->pc; goto dispatch; }
goto P_0c0bd128;
P_0c0bd126: /* original 05de, guest PC 0x0c0bd126 */
if(!s->budget--) { s->failed_pc=0x0c0bd126u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd128;
P_0c0bd128: /* original 9425, guest PC 0x0c0bd128 */
if(!s->budget--) { s->failed_pc=0x0c0bd128u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd176u,2);
goto P_0c0bd12a;
P_0c0bd12a: /* original 9023, guest PC 0x0c0bd12a */
if(!s->budget--) { s->failed_pc=0x0c0bd12au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd174u,2);
goto P_0c0bd12c;
P_0c0bd12c: /* original 4e0b, guest PC 0x0c0bd12c */
if(!s->budget--) { s->failed_pc=0x0c0bd12cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd130u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd130u) { target=s->pc; goto dispatch; }
goto P_0c0bd130;
P_0c0bd12e: /* original 05de, guest PC 0x0c0bd12e */
if(!s->budget--) { s->failed_pc=0x0c0bd12eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd130;
P_0c0bd130: /* original 9423, guest PC 0x0c0bd130 */
if(!s->budget--) { s->failed_pc=0x0c0bd130u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd17au,2);
goto P_0c0bd132;
P_0c0bd132: /* original 9021, guest PC 0x0c0bd132 */
if(!s->budget--) { s->failed_pc=0x0c0bd132u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd178u,2);
goto P_0c0bd134;
P_0c0bd134: /* original 4e0b, guest PC 0x0c0bd134 */
if(!s->budget--) { s->failed_pc=0x0c0bd134u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd138u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd138u) { target=s->pc; goto dispatch; }
goto P_0c0bd138;
P_0c0bd136: /* original 05de, guest PC 0x0c0bd136 */
if(!s->budget--) { s->failed_pc=0x0c0bd136u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd138;
P_0c0bd138: /* original 9421, guest PC 0x0c0bd138 */
if(!s->budget--) { s->failed_pc=0x0c0bd138u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd17eu,2);
goto P_0c0bd13a;
P_0c0bd13a: /* original 901f, guest PC 0x0c0bd13a */
if(!s->budget--) { s->failed_pc=0x0c0bd13au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd17cu,2);
goto P_0c0bd13c;
P_0c0bd13c: /* original 4e0b, guest PC 0x0c0bd13c */
if(!s->budget--) { s->failed_pc=0x0c0bd13cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd140u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd140u) { target=s->pc; goto dispatch; }
goto P_0c0bd140;
P_0c0bd13e: /* original 05de, guest PC 0x0c0bd13e */
if(!s->budget--) { s->failed_pc=0x0c0bd13eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd140;
P_0c0bd140: /* original 941f, guest PC 0x0c0bd140 */
if(!s->budget--) { s->failed_pc=0x0c0bd140u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd182u,2);
goto P_0c0bd142;
P_0c0bd142: /* original 901d, guest PC 0x0c0bd142 */
if(!s->budget--) { s->failed_pc=0x0c0bd142u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd180u,2);
goto P_0c0bd144;
P_0c0bd144: /* original 4e0b, guest PC 0x0c0bd144 */
if(!s->budget--) { s->failed_pc=0x0c0bd144u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd148u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd148u) { target=s->pc; goto dispatch; }
goto P_0c0bd148;
P_0c0bd146: /* original 05de, guest PC 0x0c0bd146 */
if(!s->budget--) { s->failed_pc=0x0c0bd146u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd148;
P_0c0bd148: /* original 941d, guest PC 0x0c0bd148 */
if(!s->budget--) { s->failed_pc=0x0c0bd148u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd186u,2);
goto P_0c0bd14a;
P_0c0bd14a: /* original 901b, guest PC 0x0c0bd14a */
if(!s->budget--) { s->failed_pc=0x0c0bd14au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bd184u,2);
goto P_0c0bd14c;
P_0c0bd14c: /* original 4e0b, guest PC 0x0c0bd14c */
if(!s->budget--) { s->failed_pc=0x0c0bd14cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bd150u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bd150u) { target=s->pc; goto dispatch; }
goto P_0c0bd150;
P_0c0bd14e: /* original 05de, guest PC 0x0c0bd14e */
if(!s->budget--) { s->failed_pc=0x0c0bd14eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bd150;
P_0c0bd150: /* original 7f08, guest PC 0x0c0bd150 */
if(!s->budget--) { s->failed_pc=0x0c0bd150u; return 0; }
r[15]+=0x00000008u;
goto P_0c0bd152;
P_0c0bd152: /* original 4f26, guest PC 0x0c0bd152 */
if(!s->budget--) { s->failed_pc=0x0c0bd152u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0bd154;
P_0c0bd154: /* original 69f6, guest PC 0x0c0bd154 */
if(!s->budget--) { s->failed_pc=0x0c0bd154u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0bd156;
P_0c0bd156: /* original 6af6, guest PC 0x0c0bd156 */
if(!s->budget--) { s->failed_pc=0x0c0bd156u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0bd158;
P_0c0bd158: /* original 6bf6, guest PC 0x0c0bd158 */
if(!s->budget--) { s->failed_pc=0x0c0bd158u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0bd15a;
P_0c0bd15a: /* original 6cf6, guest PC 0x0c0bd15a */
if(!s->budget--) { s->failed_pc=0x0c0bd15au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0bd15c;
P_0c0bd15c: /* original 6df6, guest PC 0x0c0bd15c */
if(!s->budget--) { s->failed_pc=0x0c0bd15cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0bd15e;
P_0c0bd15e: /* original 000b, guest PC 0x0c0bd15e */
if(!s->budget--) { s->failed_pc=0x0c0bd15eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0bd160: /* original 6ef6, guest PC 0x0c0bd160 */
if(!s->budget--) { s->failed_pc=0x0c0bd160u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0bd162u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bd162u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
