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
int vf3_away_batch158_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0bdc32u: goto P_0c0bdc32;
case 0x0c0bdc34u: goto P_0c0bdc34;
case 0x0c0bdc36u: goto P_0c0bdc36;
case 0x0c0bdc38u: goto P_0c0bdc38;
case 0x0c0bdc3au: goto P_0c0bdc3a;
case 0x0c0bdc3cu: goto P_0c0bdc3c;
case 0x0c0bdc3eu: goto P_0c0bdc3e;
case 0x0c0bdc40u: goto P_0c0bdc40;
case 0x0c0bdc42u: goto P_0c0bdc42;
case 0x0c0bdc44u: goto P_0c0bdc44;
case 0x0c0bdc46u: goto P_0c0bdc46;
case 0x0c0bdc48u: goto P_0c0bdc48;
case 0x0c0bdc4au: goto P_0c0bdc4a;
case 0x0c0bdc4cu: goto P_0c0bdc4c;
case 0x0c0bdc4eu: goto P_0c0bdc4e;
case 0x0c0bdc50u: goto P_0c0bdc50;
case 0x0c0bdc52u: goto P_0c0bdc52;
case 0x0c0bdc54u: goto P_0c0bdc54;
case 0x0c0bdc56u: goto P_0c0bdc56;
case 0x0c0bdc58u: goto P_0c0bdc58;
case 0x0c0bdc5au: goto P_0c0bdc5a;
case 0x0c0bdc5cu: goto P_0c0bdc5c;
case 0x0c0bdc5eu: goto P_0c0bdc5e;
case 0x0c0bdc60u: goto P_0c0bdc60;
case 0x0c0bdc62u: goto P_0c0bdc62;
case 0x0c0bdc64u: goto P_0c0bdc64;
case 0x0c0bdc66u: goto P_0c0bdc66;
case 0x0c0bdc68u: goto P_0c0bdc68;
case 0x0c0bdc6au: goto P_0c0bdc6a;
case 0x0c0bdc6cu: goto P_0c0bdc6c;
case 0x0c0bdc6eu: goto P_0c0bdc6e;
case 0x0c0bdc70u: goto P_0c0bdc70;
case 0x0c0bdc72u: goto P_0c0bdc72;
case 0x0c0bdc74u: goto P_0c0bdc74;
case 0x0c0bdc76u: goto P_0c0bdc76;
case 0x0c0bdc78u: goto P_0c0bdc78;
case 0x0c0bdc7au: goto P_0c0bdc7a;
case 0x0c0bdc7cu: goto P_0c0bdc7c;
case 0x0c0bdc7eu: goto P_0c0bdc7e;
case 0x0c0bdc80u: goto P_0c0bdc80;
case 0x0c0bdc82u: goto P_0c0bdc82;
case 0x0c0bdc84u: goto P_0c0bdc84;
case 0x0c0bdc86u: goto P_0c0bdc86;
case 0x0c0bdc88u: goto P_0c0bdc88;
case 0x0c0bdc8au: goto P_0c0bdc8a;
case 0x0c0bdc8cu: goto P_0c0bdc8c;
case 0x0c0bdc8eu: goto P_0c0bdc8e;
case 0x0c0bdc90u: goto P_0c0bdc90;
case 0x0c0bdc92u: goto P_0c0bdc92;
case 0x0c0bdc94u: goto P_0c0bdc94;
case 0x0c0bdc96u: goto P_0c0bdc96;
case 0x0c0bdc98u: goto P_0c0bdc98;
case 0x0c0bdc9au: goto P_0c0bdc9a;
case 0x0c0bdc9cu: goto P_0c0bdc9c;
case 0x0c0bdc9eu: goto P_0c0bdc9e;
case 0x0c0bdca0u: goto P_0c0bdca0;
case 0x0c0bdca2u: goto P_0c0bdca2;
case 0x0c0bdca4u: goto P_0c0bdca4;
case 0x0c0bdca6u: goto P_0c0bdca6;
case 0x0c0bdca8u: goto P_0c0bdca8;
case 0x0c0bdcaau: goto P_0c0bdcaa;
case 0x0c0bdcacu: goto P_0c0bdcac;
case 0x0c0bdcaeu: goto P_0c0bdcae;
case 0x0c0bdcb0u: goto P_0c0bdcb0;
case 0x0c0bdcb2u: goto P_0c0bdcb2;
case 0x0c0bdcb4u: goto P_0c0bdcb4;
case 0x0c0bdcb6u: goto P_0c0bdcb6;
case 0x0c0bdcb8u: goto P_0c0bdcb8;
case 0x0c0bdcbau: goto P_0c0bdcba;
case 0x0c0bdcbcu: goto P_0c0bdcbc;
case 0x0c0bdcbeu: goto P_0c0bdcbe;
case 0x0c0bdcc0u: goto P_0c0bdcc0;
case 0x0c0bdcc2u: goto P_0c0bdcc2;
case 0x0c0bdcc4u: goto P_0c0bdcc4;
case 0x0c0bdcc6u: goto P_0c0bdcc6;
case 0x0c0bdcc8u: goto P_0c0bdcc8;
case 0x0c0bdccau: goto P_0c0bdcca;
case 0x0c0bdcccu: goto P_0c0bdccc;
case 0x0c0bdcceu: goto P_0c0bdcce;
case 0x0c0bdcd0u: goto P_0c0bdcd0;
case 0x0c0bdcd2u: goto P_0c0bdcd2;
case 0x0c0bdcd4u: goto P_0c0bdcd4;
case 0x0c0bdcd6u: goto P_0c0bdcd6;
case 0x0c0bdcd8u: goto P_0c0bdcd8;
case 0x0c0bdcdau: goto P_0c0bdcda;
case 0x0c0bdcdcu: goto P_0c0bdcdc;
case 0x0c0bdcdeu: goto P_0c0bdcde;
case 0x0c0bdce0u: goto P_0c0bdce0;
case 0x0c0bdce2u: goto P_0c0bdce2;
case 0x0c0bdce4u: goto P_0c0bdce4;
case 0x0c0bdce6u: goto P_0c0bdce6;
case 0x0c0bdce8u: goto P_0c0bdce8;
case 0x0c0bdceau: goto P_0c0bdcea;
case 0x0c0bdcecu: goto P_0c0bdcec;
case 0x0c0bdceeu: goto P_0c0bdcee;
case 0x0c0bdcf0u: goto P_0c0bdcf0;
case 0x0c0bdcf2u: goto P_0c0bdcf2;
case 0x0c0bdcf4u: goto P_0c0bdcf4;
case 0x0c0bdcf6u: goto P_0c0bdcf6;
case 0x0c0bdcf8u: goto P_0c0bdcf8;
case 0x0c0bdcfau: goto P_0c0bdcfa;
case 0x0c0bdcfcu: goto P_0c0bdcfc;
case 0x0c0bdcfeu: goto P_0c0bdcfe;
case 0x0c0bdd00u: goto P_0c0bdd00;
case 0x0c0bdd02u: goto P_0c0bdd02;
case 0x0c0bdd04u: goto P_0c0bdd04;
case 0x0c0bdd06u: goto P_0c0bdd06;
case 0x0c0bdd08u: goto P_0c0bdd08;
case 0x0c0bdd0au: goto P_0c0bdd0a;
case 0x0c0bdd0cu: goto P_0c0bdd0c;
case 0x0c0bdd0eu: goto P_0c0bdd0e;
case 0x0c0bdd10u: goto P_0c0bdd10;
case 0x0c0bdd12u: goto P_0c0bdd12;
case 0x0c0bdd14u: goto P_0c0bdd14;
case 0x0c0bdd16u: goto P_0c0bdd16;
case 0x0c0bdd18u: goto P_0c0bdd18;
case 0x0c0bdd1au: goto P_0c0bdd1a;
case 0x0c0bdd1cu: goto P_0c0bdd1c;
case 0x0c0bdd1eu: goto P_0c0bdd1e;
case 0x0c0bdd20u: goto P_0c0bdd20;
case 0x0c0bdd22u: goto P_0c0bdd22;
case 0x0c0bdd24u: goto P_0c0bdd24;
case 0x0c0bdd26u: goto P_0c0bdd26;
case 0x0c0bdd28u: goto P_0c0bdd28;
case 0x0c0bdd2au: goto P_0c0bdd2a;
case 0x0c0bdd2cu: goto P_0c0bdd2c;
case 0x0c0bdd2eu: goto P_0c0bdd2e;
case 0x0c0bdd30u: goto P_0c0bdd30;
case 0x0c0bdd32u: goto P_0c0bdd32;
case 0x0c0bdd34u: goto P_0c0bdd34;
case 0x0c0bdd36u: goto P_0c0bdd36;
case 0x0c0bdd38u: goto P_0c0bdd38;
case 0x0c0bdd3au: goto P_0c0bdd3a;
case 0x0c0bdd3cu: goto P_0c0bdd3c;
case 0x0c0bdd3eu: goto P_0c0bdd3e;
case 0x0c0bdd40u: goto P_0c0bdd40;
case 0x0c0bdd42u: goto P_0c0bdd42;
case 0x0c0bdd44u: goto P_0c0bdd44;
case 0x0c0bdd46u: goto P_0c0bdd46;
case 0x0c0bdd48u: goto P_0c0bdd48;
case 0x0c0bdd4au: goto P_0c0bdd4a;
case 0x0c0bdd4cu: goto P_0c0bdd4c;
case 0x0c0bdd4eu: goto P_0c0bdd4e;
case 0x0c0bdd50u: goto P_0c0bdd50;
case 0x0c0bdd52u: goto P_0c0bdd52;
case 0x0c0bdd54u: goto P_0c0bdd54;
case 0x0c0bdd56u: goto P_0c0bdd56;
case 0x0c0bdd58u: goto P_0c0bdd58;
case 0x0c0bdd5au: goto P_0c0bdd5a;
case 0x0c0bdd5cu: goto P_0c0bdd5c;
case 0x0c0bdd5eu: goto P_0c0bdd5e;
case 0x0c0bdd60u: goto P_0c0bdd60;
case 0x0c0bdd62u: goto P_0c0bdd62;
case 0x0c0bdd64u: goto P_0c0bdd64;
case 0x0c0bdd66u: goto P_0c0bdd66;
case 0x0c0bdd68u: goto P_0c0bdd68;
case 0x0c0bdd6au: goto P_0c0bdd6a;
case 0x0c0bdd6cu: goto P_0c0bdd6c;
case 0x0c0bdd6eu: goto P_0c0bdd6e;
case 0x0c0bdd70u: goto P_0c0bdd70;
case 0x0c0bdd72u: goto P_0c0bdd72;
case 0x0c0bdd74u: goto P_0c0bdd74;
case 0x0c0bdd76u: goto P_0c0bdd76;
case 0x0c0bdd78u: goto P_0c0bdd78;
case 0x0c0bdd7au: goto P_0c0bdd7a;
case 0x0c0bdd7cu: goto P_0c0bdd7c;
case 0x0c0bdd7eu: goto P_0c0bdd7e;
case 0x0c0bdd80u: goto P_0c0bdd80;
case 0x0c0bdd82u: goto P_0c0bdd82;
case 0x0c0bdd84u: goto P_0c0bdd84;
case 0x0c0bdd86u: goto P_0c0bdd86;
case 0x0c0bdd88u: goto P_0c0bdd88;
case 0x0c0bdd8au: goto P_0c0bdd8a;
case 0x0c0bdd8cu: goto P_0c0bdd8c;
case 0x0c0bdd8eu: goto P_0c0bdd8e;
case 0x0c0bdd90u: goto P_0c0bdd90;
case 0x0c0bdd92u: goto P_0c0bdd92;
case 0x0c0bdd94u: goto P_0c0bdd94;
case 0x0c0bde04u: goto P_0c0bde04;
case 0x0c0bde06u: goto P_0c0bde06;
case 0x0c0bde08u: goto P_0c0bde08;
case 0x0c0bde0au: goto P_0c0bde0a;
case 0x0c0bde0cu: goto P_0c0bde0c;
case 0x0c0bde0eu: goto P_0c0bde0e;
case 0x0c0bde10u: goto P_0c0bde10;
case 0x0c0bde12u: goto P_0c0bde12;
case 0x0c0bde14u: goto P_0c0bde14;
case 0x0c0bde16u: goto P_0c0bde16;
case 0x0c0bde18u: goto P_0c0bde18;
case 0x0c0bde1au: goto P_0c0bde1a;
case 0x0c0bde1cu: goto P_0c0bde1c;
case 0x0c0bde1eu: goto P_0c0bde1e;
case 0x0c0bde20u: goto P_0c0bde20;
case 0x0c0bde22u: goto P_0c0bde22;
case 0x0c0bde24u: goto P_0c0bde24;
case 0x0c0bde26u: goto P_0c0bde26;
case 0x0c0bde28u: goto P_0c0bde28;
case 0x0c0bde2au: goto P_0c0bde2a;
case 0x0c0bde2cu: goto P_0c0bde2c;
case 0x0c0bde2eu: goto P_0c0bde2e;
case 0x0c0bde30u: goto P_0c0bde30;
case 0x0c0bde32u: goto P_0c0bde32;
case 0x0c0bde34u: goto P_0c0bde34;
case 0x0c0bde36u: goto P_0c0bde36;
case 0x0c0bde38u: goto P_0c0bde38;
case 0x0c0bde3au: goto P_0c0bde3a;
case 0x0c0bde3cu: goto P_0c0bde3c;
case 0x0c0bde3eu: goto P_0c0bde3e;
case 0x0c0bde40u: goto P_0c0bde40;
case 0x0c0bde42u: goto P_0c0bde42;
case 0x0c0bde44u: goto P_0c0bde44;
case 0x0c0bde46u: goto P_0c0bde46;
case 0x0c0bde48u: goto P_0c0bde48;
case 0x0c0bde4au: goto P_0c0bde4a;
case 0x0c0bde4cu: goto P_0c0bde4c;
case 0x0c0bde4eu: goto P_0c0bde4e;
case 0x0c0bde50u: goto P_0c0bde50;
case 0x0c0bde52u: goto P_0c0bde52;
case 0x0c0bde54u: goto P_0c0bde54;
case 0x0c0bde56u: goto P_0c0bde56;
case 0x0c0bde58u: goto P_0c0bde58;
case 0x0c0bde5au: goto P_0c0bde5a;
case 0x0c0bde5cu: goto P_0c0bde5c;
case 0x0c0bde5eu: goto P_0c0bde5e;
case 0x0c0bde60u: goto P_0c0bde60;
case 0x0c0bde62u: goto P_0c0bde62;
case 0x0c0bde64u: goto P_0c0bde64;
case 0x0c0bde66u: goto P_0c0bde66;
case 0x0c0bde68u: goto P_0c0bde68;
case 0x0c0bde6au: goto P_0c0bde6a;
case 0x0c0bde6cu: goto P_0c0bde6c;
case 0x0c0bde6eu: goto P_0c0bde6e;
case 0x0c0bde70u: goto P_0c0bde70;
case 0x0c0bde72u: goto P_0c0bde72;
case 0x0c0bde74u: goto P_0c0bde74;
case 0x0c0bde76u: goto P_0c0bde76;
case 0x0c0bde78u: goto P_0c0bde78;
case 0x0c0bde7au: goto P_0c0bde7a;
case 0x0c0bde7cu: goto P_0c0bde7c;
case 0x0c0bde7eu: goto P_0c0bde7e;
case 0x0c0bde80u: goto P_0c0bde80;
case 0x0c0bde82u: goto P_0c0bde82;
case 0x0c0bde84u: goto P_0c0bde84;
case 0x0c0bde86u: goto P_0c0bde86;
case 0x0c0bde88u: goto P_0c0bde88;
case 0x0c0bde8au: goto P_0c0bde8a;
case 0x0c0bde8cu: goto P_0c0bde8c;
case 0x0c0bde8eu: goto P_0c0bde8e;
case 0x0c0bde90u: goto P_0c0bde90;
case 0x0c0bde92u: goto P_0c0bde92;
case 0x0c0bde94u: goto P_0c0bde94;
case 0x0c0bde96u: goto P_0c0bde96;
case 0x0c0bde98u: goto P_0c0bde98;
case 0x0c0bde9au: goto P_0c0bde9a;
case 0x0c0bde9cu: goto P_0c0bde9c;
case 0x0c0bde9eu: goto P_0c0bde9e;
case 0x0c0bdea0u: goto P_0c0bdea0;
case 0x0c0bdea2u: goto P_0c0bdea2;
case 0x0c0bdea4u: goto P_0c0bdea4;
case 0x0c0bdea6u: goto P_0c0bdea6;
case 0x0c0bdea8u: goto P_0c0bdea8;
case 0x0c0bdeaau: goto P_0c0bdeaa;
case 0x0c0bdeacu: goto P_0c0bdeac;
case 0x0c0bdeaeu: goto P_0c0bdeae;
case 0x0c0bdeb0u: goto P_0c0bdeb0;
case 0x0c0bdeb2u: goto P_0c0bdeb2;
case 0x0c0bdeb4u: goto P_0c0bdeb4;
case 0x0c0bdeb6u: goto P_0c0bdeb6;
case 0x0c0bdeb8u: goto P_0c0bdeb8;
case 0x0c0bdebau: goto P_0c0bdeba;
case 0x0c0bdebcu: goto P_0c0bdebc;
case 0x0c0bdebeu: goto P_0c0bdebe;
case 0x0c0bdec0u: goto P_0c0bdec0;
case 0x0c0bdec2u: goto P_0c0bdec2;
case 0x0c0bdec4u: goto P_0c0bdec4;
case 0x0c0bdec6u: goto P_0c0bdec6;
case 0x0c0bdec8u: goto P_0c0bdec8;
case 0x0c0bdecau: goto P_0c0bdeca;
case 0x0c0bdeccu: goto P_0c0bdecc;
case 0x0c0bdeceu: goto P_0c0bdece;
case 0x0c0bded0u: goto P_0c0bded0;
case 0x0c0bded2u: goto P_0c0bded2;
case 0x0c0bded4u: goto P_0c0bded4;
case 0x0c0bded6u: goto P_0c0bded6;
case 0x0c0bded8u: goto P_0c0bded8;
case 0x0c0bdedau: goto P_0c0bdeda;
case 0x0c0bdedcu: goto P_0c0bdedc;
case 0x0c0bdedeu: goto P_0c0bdede;
case 0x0c0bdee0u: goto P_0c0bdee0;
case 0x0c0bdee2u: goto P_0c0bdee2;
case 0x0c0bdee4u: goto P_0c0bdee4;
case 0x0c0bdee6u: goto P_0c0bdee6;
case 0x0c0bdee8u: goto P_0c0bdee8;
case 0x0c0bdeeau: goto P_0c0bdeea;
case 0x0c0bdeecu: goto P_0c0bdeec;
case 0x0c0bdeeeu: goto P_0c0bdeee;
case 0x0c0bdef0u: goto P_0c0bdef0;
case 0x0c0bdef2u: goto P_0c0bdef2;
case 0x0c0bdef4u: goto P_0c0bdef4;
case 0x0c0bdef6u: goto P_0c0bdef6;
case 0x0c0bdef8u: goto P_0c0bdef8;
case 0x0c0bdefau: goto P_0c0bdefa;
case 0x0c0bdefcu: goto P_0c0bdefc;
case 0x0c0bdefeu: goto P_0c0bdefe;
case 0x0c0bdf00u: goto P_0c0bdf00;
case 0x0c0bdf02u: goto P_0c0bdf02;
case 0x0c0bdf04u: goto P_0c0bdf04;
case 0x0c0bdf06u: goto P_0c0bdf06;
case 0x0c0bdf08u: goto P_0c0bdf08;
case 0x0c0bdf0au: goto P_0c0bdf0a;
case 0x0c0bdf0cu: goto P_0c0bdf0c;
case 0x0c0bdf0eu: goto P_0c0bdf0e;
case 0x0c0bdf10u: goto P_0c0bdf10;
case 0x0c0bdf12u: goto P_0c0bdf12;
case 0x0c0bdf14u: goto P_0c0bdf14;
case 0x0c0bdf16u: goto P_0c0bdf16;
case 0x0c0bdf18u: goto P_0c0bdf18;
case 0x0c0bdf1au: goto P_0c0bdf1a;
case 0x0c0bdf1cu: goto P_0c0bdf1c;
case 0x0c0bdf1eu: goto P_0c0bdf1e;
case 0x0c0bdf20u: goto P_0c0bdf20;
case 0x0c0bdf22u: goto P_0c0bdf22;
case 0x0c0bdf24u: goto P_0c0bdf24;
case 0x0c0bdf26u: goto P_0c0bdf26;
case 0x0c0bdf28u: goto P_0c0bdf28;
case 0x0c0bdf2au: goto P_0c0bdf2a;
case 0x0c0bdf2cu: goto P_0c0bdf2c;
case 0x0c0bdf2eu: goto P_0c0bdf2e;
case 0x0c0bdf30u: goto P_0c0bdf30;
case 0x0c0bdf32u: goto P_0c0bdf32;
case 0x0c0bdf34u: goto P_0c0bdf34;
case 0x0c0bdf36u: goto P_0c0bdf36;
case 0x0c0bdf38u: goto P_0c0bdf38;
case 0x0c0bdf3au: goto P_0c0bdf3a;
case 0x0c0bdf3cu: goto P_0c0bdf3c;
case 0x0c0bdf3eu: goto P_0c0bdf3e;
case 0x0c0bdf40u: goto P_0c0bdf40;
case 0x0c0bdf42u: goto P_0c0bdf42;
case 0x0c0bdf44u: goto P_0c0bdf44;
case 0x0c0bdf46u: goto P_0c0bdf46;
case 0x0c0bdf48u: goto P_0c0bdf48;
case 0x0c0bdf4au: goto P_0c0bdf4a;
case 0x0c0bdf4cu: goto P_0c0bdf4c;
case 0x0c0bdf4eu: goto P_0c0bdf4e;
case 0x0c0bdf50u: goto P_0c0bdf50;
case 0x0c0bdf52u: goto P_0c0bdf52;
case 0x0c0bdf54u: goto P_0c0bdf54;
case 0x0c0bdf56u: goto P_0c0bdf56;
case 0x0c0bdf58u: goto P_0c0bdf58;
case 0x0c0bdf5au: goto P_0c0bdf5a;
case 0x0c0bdf5cu: goto P_0c0bdf5c;
case 0x0c0bdfd6u: goto P_0c0bdfd6;
case 0x0c0bdfd8u: goto P_0c0bdfd8;
case 0x0c0bdfdau: goto P_0c0bdfda;
case 0x0c0bdfdcu: goto P_0c0bdfdc;
case 0x0c0bdfdeu: goto P_0c0bdfde;
case 0x0c0bdfe0u: goto P_0c0bdfe0;
case 0x0c0bdfe2u: goto P_0c0bdfe2;
case 0x0c0bdfe4u: goto P_0c0bdfe4;
case 0x0c0bdfe6u: goto P_0c0bdfe6;
case 0x0c0bdfe8u: goto P_0c0bdfe8;
case 0x0c0bdfeau: goto P_0c0bdfea;
case 0x0c0bdfecu: goto P_0c0bdfec;
case 0x0c0bdfeeu: goto P_0c0bdfee;
case 0x0c0bdff0u: goto P_0c0bdff0;
case 0x0c0bdff2u: goto P_0c0bdff2;
case 0x0c0bdff4u: goto P_0c0bdff4;
case 0x0c0bdff6u: goto P_0c0bdff6;
case 0x0c0bdff8u: goto P_0c0bdff8;
case 0x0c0bdffau: goto P_0c0bdffa;
case 0x0c0bdffcu: goto P_0c0bdffc;
case 0x0c0bdffeu: goto P_0c0bdffe;
case 0x0c0be000u: goto P_0c0be000;
case 0x0c0be002u: goto P_0c0be002;
case 0x0c0be004u: goto P_0c0be004;
case 0x0c0be006u: goto P_0c0be006;
case 0x0c0be008u: goto P_0c0be008;
case 0x0c0be00au: goto P_0c0be00a;
case 0x0c0be00cu: goto P_0c0be00c;
case 0x0c0be00eu: goto P_0c0be00e;
case 0x0c0be010u: goto P_0c0be010;
case 0x0c0be012u: goto P_0c0be012;
case 0x0c0be014u: goto P_0c0be014;
case 0x0c0be016u: goto P_0c0be016;
case 0x0c0be018u: goto P_0c0be018;
case 0x0c0be01au: goto P_0c0be01a;
case 0x0c0be01cu: goto P_0c0be01c;
case 0x0c0be01eu: goto P_0c0be01e;
case 0x0c0be020u: goto P_0c0be020;
case 0x0c0be022u: goto P_0c0be022;
case 0x0c0be024u: goto P_0c0be024;
case 0x0c0be026u: goto P_0c0be026;
case 0x0c0be028u: goto P_0c0be028;
case 0x0c0be02au: goto P_0c0be02a;
case 0x0c0be02cu: goto P_0c0be02c;
case 0x0c0be02eu: goto P_0c0be02e;
case 0x0c0be030u: goto P_0c0be030;
case 0x0c0be032u: goto P_0c0be032;
case 0x0c0be034u: goto P_0c0be034;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0bdc32: /* original 2fe6, guest PC 0x0c0bdc32 */
if(!s->budget--) { s->failed_pc=0x0c0bdc32u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bdc34;
P_0c0bdc34: /* original 2fd6, guest PC 0x0c0bdc34 */
if(!s->budget--) { s->failed_pc=0x0c0bdc34u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bdc36;
P_0c0bdc36: /* original 2fc6, guest PC 0x0c0bdc36 */
if(!s->budget--) { s->failed_pc=0x0c0bdc36u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bdc38;
P_0c0bdc38: /* original 2fb6, guest PC 0x0c0bdc38 */
if(!s->budget--) { s->failed_pc=0x0c0bdc38u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bdc3a;
P_0c0bdc3a: /* original 2fa6, guest PC 0x0c0bdc3a */
if(!s->budget--) { s->failed_pc=0x0c0bdc3au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bdc3c;
P_0c0bdc3c: /* original 2f96, guest PC 0x0c0bdc3c */
if(!s->budget--) { s->failed_pc=0x0c0bdc3cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bdc3e;
P_0c0bdc3e: /* original 4f22, guest PC 0x0c0bdc3e */
if(!s->budget--) { s->failed_pc=0x0c0bdc3eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0bdc40;
P_0c0bdc40: /* original 5d44, guest PC 0x0c0bdc40 */
if(!s->budget--) { s->failed_pc=0x0c0bdc40u; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0bdc42;
P_0c0bdc42: /* original 94a8, guest PC 0x0c0bdc42 */
if(!s->budget--) { s->failed_pc=0x0c0bdc42u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdd96u,2);
goto P_0c0bdc44;
P_0c0bdc44: /* original de6e, guest PC 0x0c0bdc44 */
if(!s->budget--) { s->failed_pc=0x0c0bdc44u; return 0; }
r[14]=read(ram,0x0c0bde00u,4);
goto P_0c0bdc46;
P_0c0bdc46: /* original 7ff8, guest PC 0x0c0bdc46 */
if(!s->budget--) { s->failed_pc=0x0c0bdc46u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0bdc48;
P_0c0bdc48: /* original 4e0b, guest PC 0x0c0bdc48 */
if(!s->budget--) { s->failed_pc=0x0c0bdc48u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdc4cu;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdc4cu) { target=s->pc; goto dispatch; }
goto P_0c0bdc4c;
P_0c0bdc4a: /* original 65d2, guest PC 0x0c0bdc4a */
if(!s->budget--) { s->failed_pc=0x0c0bdc4au; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0bdc4c;
P_0c0bdc4c: /* original 94a4, guest PC 0x0c0bdc4c */
if(!s->budget--) { s->failed_pc=0x0c0bdc4cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdd98u,2);
goto P_0c0bdc4e;
P_0c0bdc4e: /* original 4e0b, guest PC 0x0c0bdc4e */
if(!s->budget--) { s->failed_pc=0x0c0bdc4eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdc52u;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdc52u) { target=s->pc; goto dispatch; }
goto P_0c0bdc52;
P_0c0bdc50: /* original 55d1, guest PC 0x0c0bdc50 */
if(!s->budget--) { s->failed_pc=0x0c0bdc50u; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0bdc52;
P_0c0bdc52: /* original 94a2, guest PC 0x0c0bdc52 */
if(!s->budget--) { s->failed_pc=0x0c0bdc52u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdd9au,2);
goto P_0c0bdc54;
P_0c0bdc54: /* original 4e0b, guest PC 0x0c0bdc54 */
if(!s->budget--) { s->failed_pc=0x0c0bdc54u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdc58u;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdc58u) { target=s->pc; goto dispatch; }
goto P_0c0bdc58;
P_0c0bdc56: /* original 55d2, guest PC 0x0c0bdc56 */
if(!s->budget--) { s->failed_pc=0x0c0bdc56u; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0bdc58;
P_0c0bdc58: /* original 94a0, guest PC 0x0c0bdc58 */
if(!s->budget--) { s->failed_pc=0x0c0bdc58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdd9cu,2);
goto P_0c0bdc5a;
P_0c0bdc5a: /* original 4e0b, guest PC 0x0c0bdc5a */
if(!s->budget--) { s->failed_pc=0x0c0bdc5au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdc5eu;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdc5eu) { target=s->pc; goto dispatch; }
goto P_0c0bdc5e;
P_0c0bdc5c: /* original 55d3, guest PC 0x0c0bdc5c */
if(!s->budget--) { s->failed_pc=0x0c0bdc5cu; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0bdc5e;
P_0c0bdc5e: /* original 949e, guest PC 0x0c0bdc5e */
if(!s->budget--) { s->failed_pc=0x0c0bdc5eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdd9eu,2);
goto P_0c0bdc60;
P_0c0bdc60: /* original 4e0b, guest PC 0x0c0bdc60 */
if(!s->budget--) { s->failed_pc=0x0c0bdc60u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdc64u;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdc64u) { target=s->pc; goto dispatch; }
goto P_0c0bdc64;
P_0c0bdc62: /* original 55d4, guest PC 0x0c0bdc62 */
if(!s->budget--) { s->failed_pc=0x0c0bdc62u; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0bdc64;
P_0c0bdc64: /* original 949c, guest PC 0x0c0bdc64 */
if(!s->budget--) { s->failed_pc=0x0c0bdc64u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdda0u,2);
goto P_0c0bdc66;
P_0c0bdc66: /* original 4e0b, guest PC 0x0c0bdc66 */
if(!s->budget--) { s->failed_pc=0x0c0bdc66u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdc6au;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdc6au) { target=s->pc; goto dispatch; }
goto P_0c0bdc6a;
P_0c0bdc68: /* original 55d5, guest PC 0x0c0bdc68 */
if(!s->budget--) { s->failed_pc=0x0c0bdc68u; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0bdc6a;
P_0c0bdc6a: /* original 949a, guest PC 0x0c0bdc6a */
if(!s->budget--) { s->failed_pc=0x0c0bdc6au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdda2u,2);
goto P_0c0bdc6c;
P_0c0bdc6c: /* original 4e0b, guest PC 0x0c0bdc6c */
if(!s->budget--) { s->failed_pc=0x0c0bdc6cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdc70u;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdc70u) { target=s->pc; goto dispatch; }
goto P_0c0bdc70;
P_0c0bdc6e: /* original 55d6, guest PC 0x0c0bdc6e */
if(!s->budget--) { s->failed_pc=0x0c0bdc6eu; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0bdc70;
P_0c0bdc70: /* original 9498, guest PC 0x0c0bdc70 */
if(!s->budget--) { s->failed_pc=0x0c0bdc70u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdda4u,2);
goto P_0c0bdc72;
P_0c0bdc72: /* original 4e0b, guest PC 0x0c0bdc72 */
if(!s->budget--) { s->failed_pc=0x0c0bdc72u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdc76u;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdc76u) { target=s->pc; goto dispatch; }
goto P_0c0bdc76;
P_0c0bdc74: /* original 55d7, guest PC 0x0c0bdc74 */
if(!s->budget--) { s->failed_pc=0x0c0bdc74u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0bdc76;
P_0c0bdc76: /* original 9496, guest PC 0x0c0bdc76 */
if(!s->budget--) { s->failed_pc=0x0c0bdc76u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdda6u,2);
goto P_0c0bdc78;
P_0c0bdc78: /* original 4e0b, guest PC 0x0c0bdc78 */
if(!s->budget--) { s->failed_pc=0x0c0bdc78u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdc7cu;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdc7cu) { target=s->pc; goto dispatch; }
goto P_0c0bdc7c;
P_0c0bdc7a: /* original 55d8, guest PC 0x0c0bdc7a */
if(!s->budget--) { s->failed_pc=0x0c0bdc7au; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0bdc7c;
P_0c0bdc7c: /* original 9494, guest PC 0x0c0bdc7c */
if(!s->budget--) { s->failed_pc=0x0c0bdc7cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdda8u,2);
goto P_0c0bdc7e;
P_0c0bdc7e: /* original 4e0b, guest PC 0x0c0bdc7e */
if(!s->budget--) { s->failed_pc=0x0c0bdc7eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdc82u;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdc82u) { target=s->pc; goto dispatch; }
goto P_0c0bdc82;
P_0c0bdc80: /* original 55d9, guest PC 0x0c0bdc80 */
if(!s->budget--) { s->failed_pc=0x0c0bdc80u; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0bdc82;
P_0c0bdc82: /* original 9492, guest PC 0x0c0bdc82 */
if(!s->budget--) { s->failed_pc=0x0c0bdc82u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddaau,2);
goto P_0c0bdc84;
P_0c0bdc84: /* original 4e0b, guest PC 0x0c0bdc84 */
if(!s->budget--) { s->failed_pc=0x0c0bdc84u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdc88u;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdc88u) { target=s->pc; goto dispatch; }
goto P_0c0bdc88;
P_0c0bdc86: /* original 55da, guest PC 0x0c0bdc86 */
if(!s->budget--) { s->failed_pc=0x0c0bdc86u; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0bdc88;
P_0c0bdc88: /* original 9490, guest PC 0x0c0bdc88 */
if(!s->budget--) { s->failed_pc=0x0c0bdc88u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddacu,2);
goto P_0c0bdc8a;
P_0c0bdc8a: /* original 4e0b, guest PC 0x0c0bdc8a */
if(!s->budget--) { s->failed_pc=0x0c0bdc8au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdc8eu;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdc8eu) { target=s->pc; goto dispatch; }
goto P_0c0bdc8e;
P_0c0bdc8c: /* original 55db, guest PC 0x0c0bdc8c */
if(!s->budget--) { s->failed_pc=0x0c0bdc8cu; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0bdc8e;
P_0c0bdc8e: /* original 948e, guest PC 0x0c0bdc8e */
if(!s->budget--) { s->failed_pc=0x0c0bdc8eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddaeu,2);
goto P_0c0bdc90;
P_0c0bdc90: /* original 4e0b, guest PC 0x0c0bdc90 */
if(!s->budget--) { s->failed_pc=0x0c0bdc90u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdc94u;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdc94u) { target=s->pc; goto dispatch; }
goto P_0c0bdc94;
P_0c0bdc92: /* original 55dc, guest PC 0x0c0bdc92 */
if(!s->budget--) { s->failed_pc=0x0c0bdc92u; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0bdc94;
P_0c0bdc94: /* original 948c, guest PC 0x0c0bdc94 */
if(!s->budget--) { s->failed_pc=0x0c0bdc94u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddb0u,2);
goto P_0c0bdc96;
P_0c0bdc96: /* original 4e0b, guest PC 0x0c0bdc96 */
if(!s->budget--) { s->failed_pc=0x0c0bdc96u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdc9au;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdc9au) { target=s->pc; goto dispatch; }
goto P_0c0bdc9a;
P_0c0bdc98: /* original 55dd, guest PC 0x0c0bdc98 */
if(!s->budget--) { s->failed_pc=0x0c0bdc98u; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0bdc9a;
P_0c0bdc9a: /* original 948a, guest PC 0x0c0bdc9a */
if(!s->budget--) { s->failed_pc=0x0c0bdc9au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddb2u,2);
goto P_0c0bdc9c;
P_0c0bdc9c: /* original 4e0b, guest PC 0x0c0bdc9c */
if(!s->budget--) { s->failed_pc=0x0c0bdc9cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdca0u;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdca0u) { target=s->pc; goto dispatch; }
goto P_0c0bdca0;
P_0c0bdc9e: /* original 55de, guest PC 0x0c0bdc9e */
if(!s->budget--) { s->failed_pc=0x0c0bdc9eu; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0bdca0;
P_0c0bdca0: /* original 9488, guest PC 0x0c0bdca0 */
if(!s->budget--) { s->failed_pc=0x0c0bdca0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddb4u,2);
goto P_0c0bdca2;
P_0c0bdca2: /* original 4e0b, guest PC 0x0c0bdca2 */
if(!s->budget--) { s->failed_pc=0x0c0bdca2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdca6u;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdca6u) { target=s->pc; goto dispatch; }
goto P_0c0bdca6;
P_0c0bdca4: /* original 55df, guest PC 0x0c0bdca4 */
if(!s->budget--) { s->failed_pc=0x0c0bdca4u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0bdca6;
P_0c0bdca6: /* original 9486, guest PC 0x0c0bdca6 */
if(!s->budget--) { s->failed_pc=0x0c0bdca6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddb6u,2);
goto P_0c0bdca8;
P_0c0bdca8: /* original e040, guest PC 0x0c0bdca8 */
if(!s->budget--) { s->failed_pc=0x0c0bdca8u; return 0; }
r[0]=0x00000040u;
goto P_0c0bdcaa;
P_0c0bdcaa: /* original 4e0b, guest PC 0x0c0bdcaa */
if(!s->budget--) { s->failed_pc=0x0c0bdcaau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdcaeu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdcaeu) { target=s->pc; goto dispatch; }
goto P_0c0bdcae;
P_0c0bdcac: /* original 05de, guest PC 0x0c0bdcac */
if(!s->budget--) { s->failed_pc=0x0c0bdcacu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdcae;
P_0c0bdcae: /* original 9483, guest PC 0x0c0bdcae */
if(!s->budget--) { s->failed_pc=0x0c0bdcaeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddb8u,2);
goto P_0c0bdcb0;
P_0c0bdcb0: /* original e044, guest PC 0x0c0bdcb0 */
if(!s->budget--) { s->failed_pc=0x0c0bdcb0u; return 0; }
r[0]=0x00000044u;
goto P_0c0bdcb2;
P_0c0bdcb2: /* original 4e0b, guest PC 0x0c0bdcb2 */
if(!s->budget--) { s->failed_pc=0x0c0bdcb2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdcb6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdcb6u) { target=s->pc; goto dispatch; }
goto P_0c0bdcb6;
P_0c0bdcb4: /* original 05de, guest PC 0x0c0bdcb4 */
if(!s->budget--) { s->failed_pc=0x0c0bdcb4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdcb6;
P_0c0bdcb6: /* original 9480, guest PC 0x0c0bdcb6 */
if(!s->budget--) { s->failed_pc=0x0c0bdcb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddbau,2);
goto P_0c0bdcb8;
P_0c0bdcb8: /* original e048, guest PC 0x0c0bdcb8 */
if(!s->budget--) { s->failed_pc=0x0c0bdcb8u; return 0; }
r[0]=0x00000048u;
goto P_0c0bdcba;
P_0c0bdcba: /* original 4e0b, guest PC 0x0c0bdcba */
if(!s->budget--) { s->failed_pc=0x0c0bdcbau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdcbeu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdcbeu) { target=s->pc; goto dispatch; }
goto P_0c0bdcbe;
P_0c0bdcbc: /* original 05de, guest PC 0x0c0bdcbc */
if(!s->budget--) { s->failed_pc=0x0c0bdcbcu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdcbe;
P_0c0bdcbe: /* original 947d, guest PC 0x0c0bdcbe */
if(!s->budget--) { s->failed_pc=0x0c0bdcbeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddbcu,2);
goto P_0c0bdcc0;
P_0c0bdcc0: /* original e04c, guest PC 0x0c0bdcc0 */
if(!s->budget--) { s->failed_pc=0x0c0bdcc0u; return 0; }
r[0]=0x0000004cu;
goto P_0c0bdcc2;
P_0c0bdcc2: /* original 4e0b, guest PC 0x0c0bdcc2 */
if(!s->budget--) { s->failed_pc=0x0c0bdcc2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdcc6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdcc6u) { target=s->pc; goto dispatch; }
goto P_0c0bdcc6;
P_0c0bdcc4: /* original 05de, guest PC 0x0c0bdcc4 */
if(!s->budget--) { s->failed_pc=0x0c0bdcc4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdcc6;
P_0c0bdcc6: /* original 947a, guest PC 0x0c0bdcc6 */
if(!s->budget--) { s->failed_pc=0x0c0bdcc6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddbeu,2);
goto P_0c0bdcc8;
P_0c0bdcc8: /* original e050, guest PC 0x0c0bdcc8 */
if(!s->budget--) { s->failed_pc=0x0c0bdcc8u; return 0; }
r[0]=0x00000050u;
goto P_0c0bdcca;
P_0c0bdcca: /* original 4e0b, guest PC 0x0c0bdcca */
if(!s->budget--) { s->failed_pc=0x0c0bdccau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdcceu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdcceu) { target=s->pc; goto dispatch; }
goto P_0c0bdcce;
P_0c0bdccc: /* original 05de, guest PC 0x0c0bdccc */
if(!s->budget--) { s->failed_pc=0x0c0bdcccu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdcce;
P_0c0bdcce: /* original 9477, guest PC 0x0c0bdcce */
if(!s->budget--) { s->failed_pc=0x0c0bdcceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddc0u,2);
goto P_0c0bdcd0;
P_0c0bdcd0: /* original e054, guest PC 0x0c0bdcd0 */
if(!s->budget--) { s->failed_pc=0x0c0bdcd0u; return 0; }
r[0]=0x00000054u;
goto P_0c0bdcd2;
P_0c0bdcd2: /* original 4e0b, guest PC 0x0c0bdcd2 */
if(!s->budget--) { s->failed_pc=0x0c0bdcd2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdcd6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdcd6u) { target=s->pc; goto dispatch; }
goto P_0c0bdcd6;
P_0c0bdcd4: /* original 05de, guest PC 0x0c0bdcd4 */
if(!s->budget--) { s->failed_pc=0x0c0bdcd4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdcd6;
P_0c0bdcd6: /* original 9474, guest PC 0x0c0bdcd6 */
if(!s->budget--) { s->failed_pc=0x0c0bdcd6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddc2u,2);
goto P_0c0bdcd8;
P_0c0bdcd8: /* original e058, guest PC 0x0c0bdcd8 */
if(!s->budget--) { s->failed_pc=0x0c0bdcd8u; return 0; }
r[0]=0x00000058u;
goto P_0c0bdcda;
P_0c0bdcda: /* original 4e0b, guest PC 0x0c0bdcda */
if(!s->budget--) { s->failed_pc=0x0c0bdcdau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdcdeu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdcdeu) { target=s->pc; goto dispatch; }
goto P_0c0bdcde;
P_0c0bdcdc: /* original 05de, guest PC 0x0c0bdcdc */
if(!s->budget--) { s->failed_pc=0x0c0bdcdcu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdcde;
P_0c0bdcde: /* original 9471, guest PC 0x0c0bdcde */
if(!s->budget--) { s->failed_pc=0x0c0bdcdeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddc4u,2);
goto P_0c0bdce0;
P_0c0bdce0: /* original e05c, guest PC 0x0c0bdce0 */
if(!s->budget--) { s->failed_pc=0x0c0bdce0u; return 0; }
r[0]=0x0000005cu;
goto P_0c0bdce2;
P_0c0bdce2: /* original 4e0b, guest PC 0x0c0bdce2 */
if(!s->budget--) { s->failed_pc=0x0c0bdce2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdce6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdce6u) { target=s->pc; goto dispatch; }
goto P_0c0bdce6;
P_0c0bdce4: /* original 05de, guest PC 0x0c0bdce4 */
if(!s->budget--) { s->failed_pc=0x0c0bdce4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdce6;
P_0c0bdce6: /* original 946e, guest PC 0x0c0bdce6 */
if(!s->budget--) { s->failed_pc=0x0c0bdce6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddc6u,2);
goto P_0c0bdce8;
P_0c0bdce8: /* original e060, guest PC 0x0c0bdce8 */
if(!s->budget--) { s->failed_pc=0x0c0bdce8u; return 0; }
r[0]=0x00000060u;
goto P_0c0bdcea;
P_0c0bdcea: /* original 4e0b, guest PC 0x0c0bdcea */
if(!s->budget--) { s->failed_pc=0x0c0bdceau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdceeu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdceeu) { target=s->pc; goto dispatch; }
goto P_0c0bdcee;
P_0c0bdcec: /* original 05de, guest PC 0x0c0bdcec */
if(!s->budget--) { s->failed_pc=0x0c0bdcecu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdcee;
P_0c0bdcee: /* original 946b, guest PC 0x0c0bdcee */
if(!s->budget--) { s->failed_pc=0x0c0bdceeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddc8u,2);
goto P_0c0bdcf0;
P_0c0bdcf0: /* original e064, guest PC 0x0c0bdcf0 */
if(!s->budget--) { s->failed_pc=0x0c0bdcf0u; return 0; }
r[0]=0x00000064u;
goto P_0c0bdcf2;
P_0c0bdcf2: /* original 4e0b, guest PC 0x0c0bdcf2 */
if(!s->budget--) { s->failed_pc=0x0c0bdcf2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdcf6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdcf6u) { target=s->pc; goto dispatch; }
goto P_0c0bdcf6;
P_0c0bdcf4: /* original 05de, guest PC 0x0c0bdcf4 */
if(!s->budget--) { s->failed_pc=0x0c0bdcf4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdcf6;
P_0c0bdcf6: /* original 9468, guest PC 0x0c0bdcf6 */
if(!s->budget--) { s->failed_pc=0x0c0bdcf6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddcau,2);
goto P_0c0bdcf8;
P_0c0bdcf8: /* original e068, guest PC 0x0c0bdcf8 */
if(!s->budget--) { s->failed_pc=0x0c0bdcf8u; return 0; }
r[0]=0x00000068u;
goto P_0c0bdcfa;
P_0c0bdcfa: /* original 4e0b, guest PC 0x0c0bdcfa */
if(!s->budget--) { s->failed_pc=0x0c0bdcfau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdcfeu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdcfeu) { target=s->pc; goto dispatch; }
goto P_0c0bdcfe;
P_0c0bdcfc: /* original 05de, guest PC 0x0c0bdcfc */
if(!s->budget--) { s->failed_pc=0x0c0bdcfcu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdcfe;
P_0c0bdcfe: /* original 9465, guest PC 0x0c0bdcfe */
if(!s->budget--) { s->failed_pc=0x0c0bdcfeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddccu,2);
goto P_0c0bdd00;
P_0c0bdd00: /* original e06c, guest PC 0x0c0bdd00 */
if(!s->budget--) { s->failed_pc=0x0c0bdd00u; return 0; }
r[0]=0x0000006cu;
goto P_0c0bdd02;
P_0c0bdd02: /* original 4e0b, guest PC 0x0c0bdd02 */
if(!s->budget--) { s->failed_pc=0x0c0bdd02u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdd06u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdd06u) { target=s->pc; goto dispatch; }
goto P_0c0bdd06;
P_0c0bdd04: /* original 05de, guest PC 0x0c0bdd04 */
if(!s->budget--) { s->failed_pc=0x0c0bdd04u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdd06;
P_0c0bdd06: /* original 9462, guest PC 0x0c0bdd06 */
if(!s->budget--) { s->failed_pc=0x0c0bdd06u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddceu,2);
goto P_0c0bdd08;
P_0c0bdd08: /* original e070, guest PC 0x0c0bdd08 */
if(!s->budget--) { s->failed_pc=0x0c0bdd08u; return 0; }
r[0]=0x00000070u;
goto P_0c0bdd0a;
P_0c0bdd0a: /* original 4e0b, guest PC 0x0c0bdd0a */
if(!s->budget--) { s->failed_pc=0x0c0bdd0au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdd0eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdd0eu) { target=s->pc; goto dispatch; }
goto P_0c0bdd0e;
P_0c0bdd0c: /* original 05de, guest PC 0x0c0bdd0c */
if(!s->budget--) { s->failed_pc=0x0c0bdd0cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdd0e;
P_0c0bdd0e: /* original 945f, guest PC 0x0c0bdd0e */
if(!s->budget--) { s->failed_pc=0x0c0bdd0eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddd0u,2);
goto P_0c0bdd10;
P_0c0bdd10: /* original e074, guest PC 0x0c0bdd10 */
if(!s->budget--) { s->failed_pc=0x0c0bdd10u; return 0; }
r[0]=0x00000074u;
goto P_0c0bdd12;
P_0c0bdd12: /* original 4e0b, guest PC 0x0c0bdd12 */
if(!s->budget--) { s->failed_pc=0x0c0bdd12u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdd16u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdd16u) { target=s->pc; goto dispatch; }
goto P_0c0bdd16;
P_0c0bdd14: /* original 05de, guest PC 0x0c0bdd14 */
if(!s->budget--) { s->failed_pc=0x0c0bdd14u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdd16;
P_0c0bdd16: /* original 945c, guest PC 0x0c0bdd16 */
if(!s->budget--) { s->failed_pc=0x0c0bdd16u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddd2u,2);
goto P_0c0bdd18;
P_0c0bdd18: /* original e078, guest PC 0x0c0bdd18 */
if(!s->budget--) { s->failed_pc=0x0c0bdd18u; return 0; }
r[0]=0x00000078u;
goto P_0c0bdd1a;
P_0c0bdd1a: /* original 4e0b, guest PC 0x0c0bdd1a */
if(!s->budget--) { s->failed_pc=0x0c0bdd1au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdd1eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdd1eu) { target=s->pc; goto dispatch; }
goto P_0c0bdd1e;
P_0c0bdd1c: /* original 05de, guest PC 0x0c0bdd1c */
if(!s->budget--) { s->failed_pc=0x0c0bdd1cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdd1e;
P_0c0bdd1e: /* original 9459, guest PC 0x0c0bdd1e */
if(!s->budget--) { s->failed_pc=0x0c0bdd1eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddd4u,2);
goto P_0c0bdd20;
P_0c0bdd20: /* original e07c, guest PC 0x0c0bdd20 */
if(!s->budget--) { s->failed_pc=0x0c0bdd20u; return 0; }
r[0]=0x0000007cu;
goto P_0c0bdd22;
P_0c0bdd22: /* original 4e0b, guest PC 0x0c0bdd22 */
if(!s->budget--) { s->failed_pc=0x0c0bdd22u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdd26u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdd26u) { target=s->pc; goto dispatch; }
goto P_0c0bdd26;
P_0c0bdd24: /* original 05de, guest PC 0x0c0bdd24 */
if(!s->budget--) { s->failed_pc=0x0c0bdd24u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdd26;
P_0c0bdd26: /* original 9457, guest PC 0x0c0bdd26 */
if(!s->budget--) { s->failed_pc=0x0c0bdd26u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddd8u,2);
goto P_0c0bdd28;
P_0c0bdd28: /* original 9055, guest PC 0x0c0bdd28 */
if(!s->budget--) { s->failed_pc=0x0c0bdd28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddd6u,2);
goto P_0c0bdd2a;
P_0c0bdd2a: /* original 4e0b, guest PC 0x0c0bdd2a */
if(!s->budget--) { s->failed_pc=0x0c0bdd2au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdd2eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdd2eu) { target=s->pc; goto dispatch; }
goto P_0c0bdd2e;
P_0c0bdd2c: /* original 05de, guest PC 0x0c0bdd2c */
if(!s->budget--) { s->failed_pc=0x0c0bdd2cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdd2e;
P_0c0bdd2e: /* original 9554, guest PC 0x0c0bdd2e */
if(!s->budget--) { s->failed_pc=0x0c0bdd2eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdddau,2);
goto P_0c0bdd30;
P_0c0bdd30: /* original 35dc, guest PC 0x0c0bdd30 */
if(!s->budget--) { s->failed_pc=0x0c0bdd30u; return 0; }
r[5]+=r[13];
goto P_0c0bdd32;
P_0c0bdd32: /* original 2f52, guest PC 0x0c0bdd32 */
if(!s->budget--) { s->failed_pc=0x0c0bdd32u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bdd34;
P_0c0bdd34: /* original 9452, guest PC 0x0c0bdd34 */
if(!s->budget--) { s->failed_pc=0x0c0bdd34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdddcu,2);
goto P_0c0bdd36;
P_0c0bdd36: /* original 4e0b, guest PC 0x0c0bdd36 */
if(!s->budget--) { s->failed_pc=0x0c0bdd36u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdd3au;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdd3au) { target=s->pc; goto dispatch; }
goto P_0c0bdd3a;
P_0c0bdd38: /* original 6552, guest PC 0x0c0bdd38 */
if(!s->budget--) { s->failed_pc=0x0c0bdd38u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bdd3a;
P_0c0bdd3a: /* original 9550, guest PC 0x0c0bdd3a */
if(!s->budget--) { s->failed_pc=0x0c0bdd3au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdddeu,2);
goto P_0c0bdd3c;
P_0c0bdd3c: /* original 35dc, guest PC 0x0c0bdd3c */
if(!s->budget--) { s->failed_pc=0x0c0bdd3cu; return 0; }
r[5]+=r[13];
goto P_0c0bdd3e;
P_0c0bdd3e: /* original 1f51, guest PC 0x0c0bdd3e */
if(!s->budget--) { s->failed_pc=0x0c0bdd3eu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0bdd40;
P_0c0bdd40: /* original 944e, guest PC 0x0c0bdd40 */
if(!s->budget--) { s->failed_pc=0x0c0bdd40u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdde0u,2);
goto P_0c0bdd42;
P_0c0bdd42: /* original 4e0b, guest PC 0x0c0bdd42 */
if(!s->budget--) { s->failed_pc=0x0c0bdd42u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdd46u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdd46u) { target=s->pc; goto dispatch; }
goto P_0c0bdd46;
P_0c0bdd44: /* original 6552, guest PC 0x0c0bdd44 */
if(!s->budget--) { s->failed_pc=0x0c0bdd44u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bdd46;
P_0c0bdd46: /* original 944d, guest PC 0x0c0bdd46 */
if(!s->budget--) { s->failed_pc=0x0c0bdd46u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdde4u,2);
goto P_0c0bdd48;
P_0c0bdd48: /* original 904b, guest PC 0x0c0bdd48 */
if(!s->budget--) { s->failed_pc=0x0c0bdd48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdde2u,2);
goto P_0c0bdd4a;
P_0c0bdd4a: /* original 4e0b, guest PC 0x0c0bdd4a */
if(!s->budget--) { s->failed_pc=0x0c0bdd4au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdd4eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdd4eu) { target=s->pc; goto dispatch; }
goto P_0c0bdd4e;
P_0c0bdd4c: /* original 05de, guest PC 0x0c0bdd4c */
if(!s->budget--) { s->failed_pc=0x0c0bdd4cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdd4e;
P_0c0bdd4e: /* original 944b, guest PC 0x0c0bdd4e */
if(!s->budget--) { s->failed_pc=0x0c0bdd4eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdde8u,2);
goto P_0c0bdd50;
P_0c0bdd50: /* original 9049, guest PC 0x0c0bdd50 */
if(!s->budget--) { s->failed_pc=0x0c0bdd50u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdde6u,2);
goto P_0c0bdd52;
P_0c0bdd52: /* original 4e0b, guest PC 0x0c0bdd52 */
if(!s->budget--) { s->failed_pc=0x0c0bdd52u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdd56u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdd56u) { target=s->pc; goto dispatch; }
goto P_0c0bdd56;
P_0c0bdd54: /* original 05de, guest PC 0x0c0bdd54 */
if(!s->budget--) { s->failed_pc=0x0c0bdd54u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdd56;
P_0c0bdd56: /* original 9948, guest PC 0x0c0bdd56 */
if(!s->budget--) { s->failed_pc=0x0c0bdd56u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddeau,2);
goto P_0c0bdd58;
P_0c0bdd58: /* original 9448, guest PC 0x0c0bdd58 */
if(!s->budget--) { s->failed_pc=0x0c0bdd58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddecu,2);
goto P_0c0bdd5a;
P_0c0bdd5a: /* original 39dc, guest PC 0x0c0bdd5a */
if(!s->budget--) { s->failed_pc=0x0c0bdd5au; return 0; }
r[9]+=r[13];
goto P_0c0bdd5c;
P_0c0bdd5c: /* original 4e0b, guest PC 0x0c0bdd5c */
if(!s->budget--) { s->failed_pc=0x0c0bdd5cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdd60u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdd60u) { target=s->pc; goto dispatch; }
goto P_0c0bdd60;
P_0c0bdd5e: /* original 6592, guest PC 0x0c0bdd5e */
if(!s->budget--) { s->failed_pc=0x0c0bdd5eu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bdd60;
P_0c0bdd60: /* original 9445, guest PC 0x0c0bdd60 */
if(!s->budget--) { s->failed_pc=0x0c0bdd60u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddeeu,2);
goto P_0c0bdd62;
P_0c0bdd62: /* original 4e0b, guest PC 0x0c0bdd62 */
if(!s->budget--) { s->failed_pc=0x0c0bdd62u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdd66u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdd66u) { target=s->pc; goto dispatch; }
goto P_0c0bdd66;
P_0c0bdd64: /* original 6592, guest PC 0x0c0bdd64 */
if(!s->budget--) { s->failed_pc=0x0c0bdd64u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bdd66;
P_0c0bdd66: /* original 9443, guest PC 0x0c0bdd66 */
if(!s->budget--) { s->failed_pc=0x0c0bdd66u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddf0u,2);
goto P_0c0bdd68;
P_0c0bdd68: /* original 4e0b, guest PC 0x0c0bdd68 */
if(!s->budget--) { s->failed_pc=0x0c0bdd68u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdd6cu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdd6cu) { target=s->pc; goto dispatch; }
goto P_0c0bdd6c;
P_0c0bdd6a: /* original 6592, guest PC 0x0c0bdd6a */
if(!s->budget--) { s->failed_pc=0x0c0bdd6au; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bdd6c;
P_0c0bdd6c: /* original 9441, guest PC 0x0c0bdd6c */
if(!s->budget--) { s->failed_pc=0x0c0bdd6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddf2u,2);
goto P_0c0bdd6e;
P_0c0bdd6e: /* original 4e0b, guest PC 0x0c0bdd6e */
if(!s->budget--) { s->failed_pc=0x0c0bdd6eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdd72u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdd72u) { target=s->pc; goto dispatch; }
goto P_0c0bdd72;
P_0c0bdd70: /* original 6592, guest PC 0x0c0bdd70 */
if(!s->budget--) { s->failed_pc=0x0c0bdd70u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bdd72;
P_0c0bdd72: /* original 9c3f, guest PC 0x0c0bdd72 */
if(!s->budget--) { s->failed_pc=0x0c0bdd72u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddf4u,2);
goto P_0c0bdd74;
P_0c0bdd74: /* original 943f, guest PC 0x0c0bdd74 */
if(!s->budget--) { s->failed_pc=0x0c0bdd74u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddf6u,2);
goto P_0c0bdd76;
P_0c0bdd76: /* original 3cdc, guest PC 0x0c0bdd76 */
if(!s->budget--) { s->failed_pc=0x0c0bdd76u; return 0; }
r[12]+=r[13];
goto P_0c0bdd78;
P_0c0bdd78: /* original 4e0b, guest PC 0x0c0bdd78 */
if(!s->budget--) { s->failed_pc=0x0c0bdd78u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdd7cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdd7cu) { target=s->pc; goto dispatch; }
goto P_0c0bdd7c;
P_0c0bdd7a: /* original 65c2, guest PC 0x0c0bdd7a */
if(!s->budget--) { s->failed_pc=0x0c0bdd7au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bdd7c;
P_0c0bdd7c: /* original 943c, guest PC 0x0c0bdd7c */
if(!s->budget--) { s->failed_pc=0x0c0bdd7cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddf8u,2);
goto P_0c0bdd7e;
P_0c0bdd7e: /* original 4e0b, guest PC 0x0c0bdd7e */
if(!s->budget--) { s->failed_pc=0x0c0bdd7eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdd82u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdd82u) { target=s->pc; goto dispatch; }
goto P_0c0bdd82;
P_0c0bdd80: /* original 65c2, guest PC 0x0c0bdd80 */
if(!s->budget--) { s->failed_pc=0x0c0bdd80u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bdd82;
P_0c0bdd82: /* original 943a, guest PC 0x0c0bdd82 */
if(!s->budget--) { s->failed_pc=0x0c0bdd82u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddfau,2);
goto P_0c0bdd84;
P_0c0bdd84: /* original 4e0b, guest PC 0x0c0bdd84 */
if(!s->budget--) { s->failed_pc=0x0c0bdd84u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdd88u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdd88u) { target=s->pc; goto dispatch; }
goto P_0c0bdd88;
P_0c0bdd86: /* original 65c2, guest PC 0x0c0bdd86 */
if(!s->budget--) { s->failed_pc=0x0c0bdd86u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bdd88;
P_0c0bdd88: /* original 9438, guest PC 0x0c0bdd88 */
if(!s->budget--) { s->failed_pc=0x0c0bdd88u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddfcu,2);
goto P_0c0bdd8a;
P_0c0bdd8a: /* original 4e0b, guest PC 0x0c0bdd8a */
if(!s->budget--) { s->failed_pc=0x0c0bdd8au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdd8eu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdd8eu) { target=s->pc; goto dispatch; }
goto P_0c0bdd8e;
P_0c0bdd8c: /* original 65c2, guest PC 0x0c0bdd8c */
if(!s->budget--) { s->failed_pc=0x0c0bdd8cu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bdd8e;
P_0c0bdd8e: /* original 9b36, guest PC 0x0c0bdd8e */
if(!s->budget--) { s->failed_pc=0x0c0bdd8eu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bddfeu,2);
goto P_0c0bdd90;
P_0c0bdd90: /* original 3bdc, guest PC 0x0c0bdd90 */
if(!s->budget--) { s->failed_pc=0x0c0bdd90u; return 0; }
r[11]+=r[13];
goto P_0c0bdd92;
P_0c0bdd92: /* original a037, guest PC 0x0c0bdd92 */
if(!s->budget--) { s->failed_pc=0x0c0bdd92u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bde04;
P_0c0bdd94: /* original 65b2, guest PC 0x0c0bdd94 */
if(!s->budget--) { s->failed_pc=0x0c0bdd94u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0bdd96u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bdd96u; return 0; } return 1;
P_0c0bde04: /* original 94ab, guest PC 0x0c0bde04 */
if(!s->budget--) { s->failed_pc=0x0c0bde04u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf5eu,2);
goto P_0c0bde06;
P_0c0bde06: /* original 4e0b, guest PC 0x0c0bde06 */
if(!s->budget--) { s->failed_pc=0x0c0bde06u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde0au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde0au) { target=s->pc; goto dispatch; }
goto P_0c0bde0a;
P_0c0bde08: /* original 0009, guest PC 0x0c0bde08 */
if(!s->budget--) { s->failed_pc=0x0c0bde08u; return 0; }
goto P_0c0bde0a;
P_0c0bde0a: /* original 94a9, guest PC 0x0c0bde0a */
if(!s->budget--) { s->failed_pc=0x0c0bde0au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf60u,2);
goto P_0c0bde0c;
P_0c0bde0c: /* original 4e0b, guest PC 0x0c0bde0c */
if(!s->budget--) { s->failed_pc=0x0c0bde0cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde10u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde10u) { target=s->pc; goto dispatch; }
goto P_0c0bde10;
P_0c0bde0e: /* original 65b2, guest PC 0x0c0bde0e */
if(!s->budget--) { s->failed_pc=0x0c0bde0eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bde10;
P_0c0bde10: /* original 94a7, guest PC 0x0c0bde10 */
if(!s->budget--) { s->failed_pc=0x0c0bde10u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf62u,2);
goto P_0c0bde12;
P_0c0bde12: /* original 4e0b, guest PC 0x0c0bde12 */
if(!s->budget--) { s->failed_pc=0x0c0bde12u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde16u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde16u) { target=s->pc; goto dispatch; }
goto P_0c0bde16;
P_0c0bde14: /* original 65b2, guest PC 0x0c0bde14 */
if(!s->budget--) { s->failed_pc=0x0c0bde14u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bde16;
P_0c0bde16: /* original 94a5, guest PC 0x0c0bde16 */
if(!s->budget--) { s->failed_pc=0x0c0bde16u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf64u,2);
goto P_0c0bde18;
P_0c0bde18: /* original 4e0b, guest PC 0x0c0bde18 */
if(!s->budget--) { s->failed_pc=0x0c0bde18u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde1cu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde1cu) { target=s->pc; goto dispatch; }
goto P_0c0bde1c;
P_0c0bde1a: /* original 65b2, guest PC 0x0c0bde1a */
if(!s->budget--) { s->failed_pc=0x0c0bde1au; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bde1c;
P_0c0bde1c: /* original 9aa3, guest PC 0x0c0bde1c */
if(!s->budget--) { s->failed_pc=0x0c0bde1cu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf66u,2);
goto P_0c0bde1e;
P_0c0bde1e: /* original 94a3, guest PC 0x0c0bde1e */
if(!s->budget--) { s->failed_pc=0x0c0bde1eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf68u,2);
goto P_0c0bde20;
P_0c0bde20: /* original 3adc, guest PC 0x0c0bde20 */
if(!s->budget--) { s->failed_pc=0x0c0bde20u; return 0; }
r[10]+=r[13];
goto P_0c0bde22;
P_0c0bde22: /* original 4e0b, guest PC 0x0c0bde22 */
if(!s->budget--) { s->failed_pc=0x0c0bde22u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde26u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde26u) { target=s->pc; goto dispatch; }
goto P_0c0bde26;
P_0c0bde24: /* original 65a2, guest PC 0x0c0bde24 */
if(!s->budget--) { s->failed_pc=0x0c0bde24u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bde26;
P_0c0bde26: /* original 94a0, guest PC 0x0c0bde26 */
if(!s->budget--) { s->failed_pc=0x0c0bde26u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf6au,2);
goto P_0c0bde28;
P_0c0bde28: /* original 4e0b, guest PC 0x0c0bde28 */
if(!s->budget--) { s->failed_pc=0x0c0bde28u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde2cu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde2cu) { target=s->pc; goto dispatch; }
goto P_0c0bde2c;
P_0c0bde2a: /* original 65a2, guest PC 0x0c0bde2a */
if(!s->budget--) { s->failed_pc=0x0c0bde2au; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bde2c;
P_0c0bde2c: /* original 949e, guest PC 0x0c0bde2c */
if(!s->budget--) { s->failed_pc=0x0c0bde2cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf6cu,2);
goto P_0c0bde2e;
P_0c0bde2e: /* original 4e0b, guest PC 0x0c0bde2e */
if(!s->budget--) { s->failed_pc=0x0c0bde2eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde32u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde32u) { target=s->pc; goto dispatch; }
goto P_0c0bde32;
P_0c0bde30: /* original 65a2, guest PC 0x0c0bde30 */
if(!s->budget--) { s->failed_pc=0x0c0bde30u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bde32;
P_0c0bde32: /* original 949c, guest PC 0x0c0bde32 */
if(!s->budget--) { s->failed_pc=0x0c0bde32u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf6eu,2);
goto P_0c0bde34;
P_0c0bde34: /* original 4e0b, guest PC 0x0c0bde34 */
if(!s->budget--) { s->failed_pc=0x0c0bde34u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde38u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde38u) { target=s->pc; goto dispatch; }
goto P_0c0bde38;
P_0c0bde36: /* original 65a2, guest PC 0x0c0bde36 */
if(!s->budget--) { s->failed_pc=0x0c0bde36u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bde38;
P_0c0bde38: /* original 949a, guest PC 0x0c0bde38 */
if(!s->budget--) { s->failed_pc=0x0c0bde38u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf70u,2);
goto P_0c0bde3a;
P_0c0bde3a: /* original 65f2, guest PC 0x0c0bde3a */
if(!s->budget--) { s->failed_pc=0x0c0bde3au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bde3c;
P_0c0bde3c: /* original 4e0b, guest PC 0x0c0bde3c */
if(!s->budget--) { s->failed_pc=0x0c0bde3cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde40u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde40u) { target=s->pc; goto dispatch; }
goto P_0c0bde40;
P_0c0bde3e: /* original 6552, guest PC 0x0c0bde3e */
if(!s->budget--) { s->failed_pc=0x0c0bde3eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bde40;
P_0c0bde40: /* original 9497, guest PC 0x0c0bde40 */
if(!s->budget--) { s->failed_pc=0x0c0bde40u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf72u,2);
goto P_0c0bde42;
P_0c0bde42: /* original 55f1, guest PC 0x0c0bde42 */
if(!s->budget--) { s->failed_pc=0x0c0bde42u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0bde44;
P_0c0bde44: /* original 4e0b, guest PC 0x0c0bde44 */
if(!s->budget--) { s->failed_pc=0x0c0bde44u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde48u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde48u) { target=s->pc; goto dispatch; }
goto P_0c0bde48;
P_0c0bde46: /* original 6552, guest PC 0x0c0bde46 */
if(!s->budget--) { s->failed_pc=0x0c0bde46u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bde48;
P_0c0bde48: /* original 9494, guest PC 0x0c0bde48 */
if(!s->budget--) { s->failed_pc=0x0c0bde48u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf74u,2);
goto P_0c0bde4a;
P_0c0bde4a: /* original 4e0b, guest PC 0x0c0bde4a */
if(!s->budget--) { s->failed_pc=0x0c0bde4au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde4eu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde4eu) { target=s->pc; goto dispatch; }
goto P_0c0bde4e;
P_0c0bde4c: /* original 6592, guest PC 0x0c0bde4c */
if(!s->budget--) { s->failed_pc=0x0c0bde4cu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bde4e;
P_0c0bde4e: /* original 9492, guest PC 0x0c0bde4e */
if(!s->budget--) { s->failed_pc=0x0c0bde4eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf76u,2);
goto P_0c0bde50;
P_0c0bde50: /* original 4e0b, guest PC 0x0c0bde50 */
if(!s->budget--) { s->failed_pc=0x0c0bde50u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde54u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde54u) { target=s->pc; goto dispatch; }
goto P_0c0bde54;
P_0c0bde52: /* original 6592, guest PC 0x0c0bde52 */
if(!s->budget--) { s->failed_pc=0x0c0bde52u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bde54;
P_0c0bde54: /* original 9490, guest PC 0x0c0bde54 */
if(!s->budget--) { s->failed_pc=0x0c0bde54u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf78u,2);
goto P_0c0bde56;
P_0c0bde56: /* original 4e0b, guest PC 0x0c0bde56 */
if(!s->budget--) { s->failed_pc=0x0c0bde56u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde5au;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde5au) { target=s->pc; goto dispatch; }
goto P_0c0bde5a;
P_0c0bde58: /* original 6592, guest PC 0x0c0bde58 */
if(!s->budget--) { s->failed_pc=0x0c0bde58u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bde5a;
P_0c0bde5a: /* original 948e, guest PC 0x0c0bde5a */
if(!s->budget--) { s->failed_pc=0x0c0bde5au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf7au,2);
goto P_0c0bde5c;
P_0c0bde5c: /* original 4e0b, guest PC 0x0c0bde5c */
if(!s->budget--) { s->failed_pc=0x0c0bde5cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde60u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde60u) { target=s->pc; goto dispatch; }
goto P_0c0bde60;
P_0c0bde5e: /* original 6592, guest PC 0x0c0bde5e */
if(!s->budget--) { s->failed_pc=0x0c0bde5eu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bde60;
P_0c0bde60: /* original 948c, guest PC 0x0c0bde60 */
if(!s->budget--) { s->failed_pc=0x0c0bde60u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf7cu,2);
goto P_0c0bde62;
P_0c0bde62: /* original 4e0b, guest PC 0x0c0bde62 */
if(!s->budget--) { s->failed_pc=0x0c0bde62u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde66u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde66u) { target=s->pc; goto dispatch; }
goto P_0c0bde66;
P_0c0bde64: /* original 65c2, guest PC 0x0c0bde64 */
if(!s->budget--) { s->failed_pc=0x0c0bde64u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bde66;
P_0c0bde66: /* original 948a, guest PC 0x0c0bde66 */
if(!s->budget--) { s->failed_pc=0x0c0bde66u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf7eu,2);
goto P_0c0bde68;
P_0c0bde68: /* original 4e0b, guest PC 0x0c0bde68 */
if(!s->budget--) { s->failed_pc=0x0c0bde68u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde6cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde6cu) { target=s->pc; goto dispatch; }
goto P_0c0bde6c;
P_0c0bde6a: /* original 65c2, guest PC 0x0c0bde6a */
if(!s->budget--) { s->failed_pc=0x0c0bde6au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bde6c;
P_0c0bde6c: /* original 9488, guest PC 0x0c0bde6c */
if(!s->budget--) { s->failed_pc=0x0c0bde6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf80u,2);
goto P_0c0bde6e;
P_0c0bde6e: /* original 4e0b, guest PC 0x0c0bde6e */
if(!s->budget--) { s->failed_pc=0x0c0bde6eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde72u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde72u) { target=s->pc; goto dispatch; }
goto P_0c0bde72;
P_0c0bde70: /* original 65c2, guest PC 0x0c0bde70 */
if(!s->budget--) { s->failed_pc=0x0c0bde70u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bde72;
P_0c0bde72: /* original 9486, guest PC 0x0c0bde72 */
if(!s->budget--) { s->failed_pc=0x0c0bde72u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf82u,2);
goto P_0c0bde74;
P_0c0bde74: /* original 4e0b, guest PC 0x0c0bde74 */
if(!s->budget--) { s->failed_pc=0x0c0bde74u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde78u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde78u) { target=s->pc; goto dispatch; }
goto P_0c0bde78;
P_0c0bde76: /* original 65c2, guest PC 0x0c0bde76 */
if(!s->budget--) { s->failed_pc=0x0c0bde76u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bde78;
P_0c0bde78: /* original 9484, guest PC 0x0c0bde78 */
if(!s->budget--) { s->failed_pc=0x0c0bde78u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf84u,2);
goto P_0c0bde7a;
P_0c0bde7a: /* original 4e0b, guest PC 0x0c0bde7a */
if(!s->budget--) { s->failed_pc=0x0c0bde7au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde7eu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde7eu) { target=s->pc; goto dispatch; }
goto P_0c0bde7e;
P_0c0bde7c: /* original 65b2, guest PC 0x0c0bde7c */
if(!s->budget--) { s->failed_pc=0x0c0bde7cu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bde7e;
P_0c0bde7e: /* original 9482, guest PC 0x0c0bde7e */
if(!s->budget--) { s->failed_pc=0x0c0bde7eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf86u,2);
goto P_0c0bde80;
P_0c0bde80: /* original 4e0b, guest PC 0x0c0bde80 */
if(!s->budget--) { s->failed_pc=0x0c0bde80u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde84u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde84u) { target=s->pc; goto dispatch; }
goto P_0c0bde84;
P_0c0bde82: /* original 65b2, guest PC 0x0c0bde82 */
if(!s->budget--) { s->failed_pc=0x0c0bde82u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bde84;
P_0c0bde84: /* original 9480, guest PC 0x0c0bde84 */
if(!s->budget--) { s->failed_pc=0x0c0bde84u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf88u,2);
goto P_0c0bde86;
P_0c0bde86: /* original 4e0b, guest PC 0x0c0bde86 */
if(!s->budget--) { s->failed_pc=0x0c0bde86u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde8au;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde8au) { target=s->pc; goto dispatch; }
goto P_0c0bde8a;
P_0c0bde88: /* original 65b2, guest PC 0x0c0bde88 */
if(!s->budget--) { s->failed_pc=0x0c0bde88u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bde8a;
P_0c0bde8a: /* original 947e, guest PC 0x0c0bde8a */
if(!s->budget--) { s->failed_pc=0x0c0bde8au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf8au,2);
goto P_0c0bde8c;
P_0c0bde8c: /* original 4e0b, guest PC 0x0c0bde8c */
if(!s->budget--) { s->failed_pc=0x0c0bde8cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde90u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde90u) { target=s->pc; goto dispatch; }
goto P_0c0bde90;
P_0c0bde8e: /* original 65b2, guest PC 0x0c0bde8e */
if(!s->budget--) { s->failed_pc=0x0c0bde8eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bde90;
P_0c0bde90: /* original 947c, guest PC 0x0c0bde90 */
if(!s->budget--) { s->failed_pc=0x0c0bde90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf8cu,2);
goto P_0c0bde92;
P_0c0bde92: /* original 4e0b, guest PC 0x0c0bde92 */
if(!s->budget--) { s->failed_pc=0x0c0bde92u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde96u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde96u) { target=s->pc; goto dispatch; }
goto P_0c0bde96;
P_0c0bde94: /* original 65a2, guest PC 0x0c0bde94 */
if(!s->budget--) { s->failed_pc=0x0c0bde94u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bde96;
P_0c0bde96: /* original 947a, guest PC 0x0c0bde96 */
if(!s->budget--) { s->failed_pc=0x0c0bde96u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf8eu,2);
goto P_0c0bde98;
P_0c0bde98: /* original 4e0b, guest PC 0x0c0bde98 */
if(!s->budget--) { s->failed_pc=0x0c0bde98u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bde9cu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bde9cu) { target=s->pc; goto dispatch; }
goto P_0c0bde9c;
P_0c0bde9a: /* original 65a2, guest PC 0x0c0bde9a */
if(!s->budget--) { s->failed_pc=0x0c0bde9au; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bde9c;
P_0c0bde9c: /* original 9478, guest PC 0x0c0bde9c */
if(!s->budget--) { s->failed_pc=0x0c0bde9cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf90u,2);
goto P_0c0bde9e;
P_0c0bde9e: /* original 4e0b, guest PC 0x0c0bde9e */
if(!s->budget--) { s->failed_pc=0x0c0bde9eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdea2u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdea2u) { target=s->pc; goto dispatch; }
goto P_0c0bdea2;
P_0c0bdea0: /* original 65a2, guest PC 0x0c0bdea0 */
if(!s->budget--) { s->failed_pc=0x0c0bdea0u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bdea2;
P_0c0bdea2: /* original 9476, guest PC 0x0c0bdea2 */
if(!s->budget--) { s->failed_pc=0x0c0bdea2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf92u,2);
goto P_0c0bdea4;
P_0c0bdea4: /* original 4e0b, guest PC 0x0c0bdea4 */
if(!s->budget--) { s->failed_pc=0x0c0bdea4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdea8u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdea8u) { target=s->pc; goto dispatch; }
goto P_0c0bdea8;
P_0c0bdea6: /* original 65a2, guest PC 0x0c0bdea6 */
if(!s->budget--) { s->failed_pc=0x0c0bdea6u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bdea8;
P_0c0bdea8: /* original 9574, guest PC 0x0c0bdea8 */
if(!s->budget--) { s->failed_pc=0x0c0bdea8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf94u,2);
goto P_0c0bdeaa;
P_0c0bdeaa: /* original 35dc, guest PC 0x0c0bdeaa */
if(!s->budget--) { s->failed_pc=0x0c0bdeaau; return 0; }
r[5]+=r[13];
goto P_0c0bdeac;
P_0c0bdeac: /* original 2f52, guest PC 0x0c0bdeac */
if(!s->budget--) { s->failed_pc=0x0c0bdeacu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bdeae;
P_0c0bdeae: /* original 9472, guest PC 0x0c0bdeae */
if(!s->budget--) { s->failed_pc=0x0c0bdeaeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf96u,2);
goto P_0c0bdeb0;
P_0c0bdeb0: /* original 4e0b, guest PC 0x0c0bdeb0 */
if(!s->budget--) { s->failed_pc=0x0c0bdeb0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdeb4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdeb4u) { target=s->pc; goto dispatch; }
goto P_0c0bdeb4;
P_0c0bdeb2: /* original 6552, guest PC 0x0c0bdeb2 */
if(!s->budget--) { s->failed_pc=0x0c0bdeb2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bdeb4;
P_0c0bdeb4: /* original 9470, guest PC 0x0c0bdeb4 */
if(!s->budget--) { s->failed_pc=0x0c0bdeb4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf98u,2);
goto P_0c0bdeb6;
P_0c0bdeb6: /* original 65f2, guest PC 0x0c0bdeb6 */
if(!s->budget--) { s->failed_pc=0x0c0bdeb6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bdeb8;
P_0c0bdeb8: /* original 4e0b, guest PC 0x0c0bdeb8 */
if(!s->budget--) { s->failed_pc=0x0c0bdeb8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdebcu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdebcu) { target=s->pc; goto dispatch; }
goto P_0c0bdebc;
P_0c0bdeba: /* original 6552, guest PC 0x0c0bdeba */
if(!s->budget--) { s->failed_pc=0x0c0bdebau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bdebc;
P_0c0bdebc: /* original 956d, guest PC 0x0c0bdebc */
if(!s->budget--) { s->failed_pc=0x0c0bdebcu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf9au,2);
goto P_0c0bdebe;
P_0c0bdebe: /* original 35dc, guest PC 0x0c0bdebe */
if(!s->budget--) { s->failed_pc=0x0c0bdebeu; return 0; }
r[5]+=r[13];
goto P_0c0bdec0;
P_0c0bdec0: /* original 2f52, guest PC 0x0c0bdec0 */
if(!s->budget--) { s->failed_pc=0x0c0bdec0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bdec2;
P_0c0bdec2: /* original 946b, guest PC 0x0c0bdec2 */
if(!s->budget--) { s->failed_pc=0x0c0bdec2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf9cu,2);
goto P_0c0bdec4;
P_0c0bdec4: /* original 4e0b, guest PC 0x0c0bdec4 */
if(!s->budget--) { s->failed_pc=0x0c0bdec4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdec8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdec8u) { target=s->pc; goto dispatch; }
goto P_0c0bdec8;
P_0c0bdec6: /* original 6552, guest PC 0x0c0bdec6 */
if(!s->budget--) { s->failed_pc=0x0c0bdec6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bdec8;
P_0c0bdec8: /* original 9469, guest PC 0x0c0bdec8 */
if(!s->budget--) { s->failed_pc=0x0c0bdec8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdf9eu,2);
goto P_0c0bdeca;
P_0c0bdeca: /* original 65f2, guest PC 0x0c0bdeca */
if(!s->budget--) { s->failed_pc=0x0c0bdecau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bdecc;
P_0c0bdecc: /* original 4e0b, guest PC 0x0c0bdecc */
if(!s->budget--) { s->failed_pc=0x0c0bdeccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bded0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bded0u) { target=s->pc; goto dispatch; }
goto P_0c0bded0;
P_0c0bdece: /* original 6552, guest PC 0x0c0bdece */
if(!s->budget--) { s->failed_pc=0x0c0bdeceu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bded0;
P_0c0bded0: /* original 9467, guest PC 0x0c0bded0 */
if(!s->budget--) { s->failed_pc=0x0c0bded0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfa2u,2);
goto P_0c0bded2;
P_0c0bded2: /* original 9065, guest PC 0x0c0bded2 */
if(!s->budget--) { s->failed_pc=0x0c0bded2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfa0u,2);
goto P_0c0bded4;
P_0c0bded4: /* original 4e0b, guest PC 0x0c0bded4 */
if(!s->budget--) { s->failed_pc=0x0c0bded4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bded8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bded8u) { target=s->pc; goto dispatch; }
goto P_0c0bded8;
P_0c0bded6: /* original 05de, guest PC 0x0c0bded6 */
if(!s->budget--) { s->failed_pc=0x0c0bded6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bded8;
P_0c0bded8: /* original 9564, guest PC 0x0c0bded8 */
if(!s->budget--) { s->failed_pc=0x0c0bded8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfa4u,2);
goto P_0c0bdeda;
P_0c0bdeda: /* original 35dc, guest PC 0x0c0bdeda */
if(!s->budget--) { s->failed_pc=0x0c0bdedau; return 0; }
r[5]+=r[13];
goto P_0c0bdedc;
P_0c0bdedc: /* original 2f52, guest PC 0x0c0bdedc */
if(!s->budget--) { s->failed_pc=0x0c0bdedcu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bdede;
P_0c0bdede: /* original 9462, guest PC 0x0c0bdede */
if(!s->budget--) { s->failed_pc=0x0c0bdedeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfa6u,2);
goto P_0c0bdee0;
P_0c0bdee0: /* original 4e0b, guest PC 0x0c0bdee0 */
if(!s->budget--) { s->failed_pc=0x0c0bdee0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdee4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdee4u) { target=s->pc; goto dispatch; }
goto P_0c0bdee4;
P_0c0bdee2: /* original 6552, guest PC 0x0c0bdee2 */
if(!s->budget--) { s->failed_pc=0x0c0bdee2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bdee4;
P_0c0bdee4: /* original 9460, guest PC 0x0c0bdee4 */
if(!s->budget--) { s->failed_pc=0x0c0bdee4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfa8u,2);
goto P_0c0bdee6;
P_0c0bdee6: /* original 65f2, guest PC 0x0c0bdee6 */
if(!s->budget--) { s->failed_pc=0x0c0bdee6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bdee8;
P_0c0bdee8: /* original 4e0b, guest PC 0x0c0bdee8 */
if(!s->budget--) { s->failed_pc=0x0c0bdee8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdeecu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdeecu) { target=s->pc; goto dispatch; }
goto P_0c0bdeec;
P_0c0bdeea: /* original 6552, guest PC 0x0c0bdeea */
if(!s->budget--) { s->failed_pc=0x0c0bdeeau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bdeec;
P_0c0bdeec: /* original 945e, guest PC 0x0c0bdeec */
if(!s->budget--) { s->failed_pc=0x0c0bdeecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfacu,2);
goto P_0c0bdeee;
P_0c0bdeee: /* original 905c, guest PC 0x0c0bdeee */
if(!s->budget--) { s->failed_pc=0x0c0bdeeeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfaau,2);
goto P_0c0bdef0;
P_0c0bdef0: /* original 4e0b, guest PC 0x0c0bdef0 */
if(!s->budget--) { s->failed_pc=0x0c0bdef0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdef4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdef4u) { target=s->pc; goto dispatch; }
goto P_0c0bdef4;
P_0c0bdef2: /* original 05de, guest PC 0x0c0bdef2 */
if(!s->budget--) { s->failed_pc=0x0c0bdef2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdef4;
P_0c0bdef4: /* original 955b, guest PC 0x0c0bdef4 */
if(!s->budget--) { s->failed_pc=0x0c0bdef4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfaeu,2);
goto P_0c0bdef6;
P_0c0bdef6: /* original 35dc, guest PC 0x0c0bdef6 */
if(!s->budget--) { s->failed_pc=0x0c0bdef6u; return 0; }
r[5]+=r[13];
goto P_0c0bdef8;
P_0c0bdef8: /* original 2f52, guest PC 0x0c0bdef8 */
if(!s->budget--) { s->failed_pc=0x0c0bdef8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bdefa;
P_0c0bdefa: /* original 9459, guest PC 0x0c0bdefa */
if(!s->budget--) { s->failed_pc=0x0c0bdefau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfb0u,2);
goto P_0c0bdefc;
P_0c0bdefc: /* original 4e0b, guest PC 0x0c0bdefc */
if(!s->budget--) { s->failed_pc=0x0c0bdefcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdf00u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdf00u) { target=s->pc; goto dispatch; }
goto P_0c0bdf00;
P_0c0bdefe: /* original 6552, guest PC 0x0c0bdefe */
if(!s->budget--) { s->failed_pc=0x0c0bdefeu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bdf00;
P_0c0bdf00: /* original 9457, guest PC 0x0c0bdf00 */
if(!s->budget--) { s->failed_pc=0x0c0bdf00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfb2u,2);
goto P_0c0bdf02;
P_0c0bdf02: /* original 65f2, guest PC 0x0c0bdf02 */
if(!s->budget--) { s->failed_pc=0x0c0bdf02u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bdf04;
P_0c0bdf04: /* original 4e0b, guest PC 0x0c0bdf04 */
if(!s->budget--) { s->failed_pc=0x0c0bdf04u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdf08u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdf08u) { target=s->pc; goto dispatch; }
goto P_0c0bdf08;
P_0c0bdf06: /* original 6552, guest PC 0x0c0bdf06 */
if(!s->budget--) { s->failed_pc=0x0c0bdf06u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bdf08;
P_0c0bdf08: /* original 9455, guest PC 0x0c0bdf08 */
if(!s->budget--) { s->failed_pc=0x0c0bdf08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfb6u,2);
goto P_0c0bdf0a;
P_0c0bdf0a: /* original 9053, guest PC 0x0c0bdf0a */
if(!s->budget--) { s->failed_pc=0x0c0bdf0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfb4u,2);
goto P_0c0bdf0c;
P_0c0bdf0c: /* original 4e0b, guest PC 0x0c0bdf0c */
if(!s->budget--) { s->failed_pc=0x0c0bdf0cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdf10u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdf10u) { target=s->pc; goto dispatch; }
goto P_0c0bdf10;
P_0c0bdf0e: /* original 05de, guest PC 0x0c0bdf0e */
if(!s->budget--) { s->failed_pc=0x0c0bdf0eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdf10;
P_0c0bdf10: /* original 9552, guest PC 0x0c0bdf10 */
if(!s->budget--) { s->failed_pc=0x0c0bdf10u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfb8u,2);
goto P_0c0bdf12;
P_0c0bdf12: /* original 35dc, guest PC 0x0c0bdf12 */
if(!s->budget--) { s->failed_pc=0x0c0bdf12u; return 0; }
r[5]+=r[13];
goto P_0c0bdf14;
P_0c0bdf14: /* original 2f52, guest PC 0x0c0bdf14 */
if(!s->budget--) { s->failed_pc=0x0c0bdf14u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bdf16;
P_0c0bdf16: /* original 9450, guest PC 0x0c0bdf16 */
if(!s->budget--) { s->failed_pc=0x0c0bdf16u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfbau,2);
goto P_0c0bdf18;
P_0c0bdf18: /* original 4e0b, guest PC 0x0c0bdf18 */
if(!s->budget--) { s->failed_pc=0x0c0bdf18u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdf1cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdf1cu) { target=s->pc; goto dispatch; }
goto P_0c0bdf1c;
P_0c0bdf1a: /* original 6552, guest PC 0x0c0bdf1a */
if(!s->budget--) { s->failed_pc=0x0c0bdf1au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bdf1c;
P_0c0bdf1c: /* original 944e, guest PC 0x0c0bdf1c */
if(!s->budget--) { s->failed_pc=0x0c0bdf1cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfbcu,2);
goto P_0c0bdf1e;
P_0c0bdf1e: /* original 65f2, guest PC 0x0c0bdf1e */
if(!s->budget--) { s->failed_pc=0x0c0bdf1eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bdf20;
P_0c0bdf20: /* original 4e0b, guest PC 0x0c0bdf20 */
if(!s->budget--) { s->failed_pc=0x0c0bdf20u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdf24u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdf24u) { target=s->pc; goto dispatch; }
goto P_0c0bdf24;
P_0c0bdf22: /* original 6552, guest PC 0x0c0bdf22 */
if(!s->budget--) { s->failed_pc=0x0c0bdf22u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bdf24;
P_0c0bdf24: /* original 954b, guest PC 0x0c0bdf24 */
if(!s->budget--) { s->failed_pc=0x0c0bdf24u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfbeu,2);
goto P_0c0bdf26;
P_0c0bdf26: /* original 35dc, guest PC 0x0c0bdf26 */
if(!s->budget--) { s->failed_pc=0x0c0bdf26u; return 0; }
r[5]+=r[13];
goto P_0c0bdf28;
P_0c0bdf28: /* original 2f52, guest PC 0x0c0bdf28 */
if(!s->budget--) { s->failed_pc=0x0c0bdf28u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bdf2a;
P_0c0bdf2a: /* original 9449, guest PC 0x0c0bdf2a */
if(!s->budget--) { s->failed_pc=0x0c0bdf2au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfc0u,2);
goto P_0c0bdf2c;
P_0c0bdf2c: /* original 4e0b, guest PC 0x0c0bdf2c */
if(!s->budget--) { s->failed_pc=0x0c0bdf2cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdf30u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdf30u) { target=s->pc; goto dispatch; }
goto P_0c0bdf30;
P_0c0bdf2e: /* original 6552, guest PC 0x0c0bdf2e */
if(!s->budget--) { s->failed_pc=0x0c0bdf2eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bdf30;
P_0c0bdf30: /* original 9447, guest PC 0x0c0bdf30 */
if(!s->budget--) { s->failed_pc=0x0c0bdf30u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfc2u,2);
goto P_0c0bdf32;
P_0c0bdf32: /* original 65f2, guest PC 0x0c0bdf32 */
if(!s->budget--) { s->failed_pc=0x0c0bdf32u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bdf34;
P_0c0bdf34: /* original 4e0b, guest PC 0x0c0bdf34 */
if(!s->budget--) { s->failed_pc=0x0c0bdf34u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdf38u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdf38u) { target=s->pc; goto dispatch; }
goto P_0c0bdf38;
P_0c0bdf36: /* original 6552, guest PC 0x0c0bdf36 */
if(!s->budget--) { s->failed_pc=0x0c0bdf36u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bdf38;
P_0c0bdf38: /* original 9445, guest PC 0x0c0bdf38 */
if(!s->budget--) { s->failed_pc=0x0c0bdf38u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfc6u,2);
goto P_0c0bdf3a;
P_0c0bdf3a: /* original 9043, guest PC 0x0c0bdf3a */
if(!s->budget--) { s->failed_pc=0x0c0bdf3au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfc4u,2);
goto P_0c0bdf3c;
P_0c0bdf3c: /* original 4e0b, guest PC 0x0c0bdf3c */
if(!s->budget--) { s->failed_pc=0x0c0bdf3cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdf40u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdf40u) { target=s->pc; goto dispatch; }
goto P_0c0bdf40;
P_0c0bdf3e: /* original 05de, guest PC 0x0c0bdf3e */
if(!s->budget--) { s->failed_pc=0x0c0bdf3eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdf40;
P_0c0bdf40: /* original 9443, guest PC 0x0c0bdf40 */
if(!s->budget--) { s->failed_pc=0x0c0bdf40u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfcau,2);
goto P_0c0bdf42;
P_0c0bdf42: /* original 9041, guest PC 0x0c0bdf42 */
if(!s->budget--) { s->failed_pc=0x0c0bdf42u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfc8u,2);
goto P_0c0bdf44;
P_0c0bdf44: /* original 4e0b, guest PC 0x0c0bdf44 */
if(!s->budget--) { s->failed_pc=0x0c0bdf44u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdf48u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdf48u) { target=s->pc; goto dispatch; }
goto P_0c0bdf48;
P_0c0bdf46: /* original 05de, guest PC 0x0c0bdf46 */
if(!s->budget--) { s->failed_pc=0x0c0bdf46u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdf48;
P_0c0bdf48: /* original 9441, guest PC 0x0c0bdf48 */
if(!s->budget--) { s->failed_pc=0x0c0bdf48u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfceu,2);
goto P_0c0bdf4a;
P_0c0bdf4a: /* original 903f, guest PC 0x0c0bdf4a */
if(!s->budget--) { s->failed_pc=0x0c0bdf4au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfccu,2);
goto P_0c0bdf4c;
P_0c0bdf4c: /* original 4e0b, guest PC 0x0c0bdf4c */
if(!s->budget--) { s->failed_pc=0x0c0bdf4cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdf50u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdf50u) { target=s->pc; goto dispatch; }
goto P_0c0bdf50;
P_0c0bdf4e: /* original 05de, guest PC 0x0c0bdf4e */
if(!s->budget--) { s->failed_pc=0x0c0bdf4eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdf50;
P_0c0bdf50: /* original 943f, guest PC 0x0c0bdf50 */
if(!s->budget--) { s->failed_pc=0x0c0bdf50u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfd2u,2);
goto P_0c0bdf52;
P_0c0bdf52: /* original 903d, guest PC 0x0c0bdf52 */
if(!s->budget--) { s->failed_pc=0x0c0bdf52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfd0u,2);
goto P_0c0bdf54;
P_0c0bdf54: /* original 4e0b, guest PC 0x0c0bdf54 */
if(!s->budget--) { s->failed_pc=0x0c0bdf54u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdf58u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdf58u) { target=s->pc; goto dispatch; }
goto P_0c0bdf58;
P_0c0bdf56: /* original 05de, guest PC 0x0c0bdf56 */
if(!s->budget--) { s->failed_pc=0x0c0bdf56u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdf58;
P_0c0bdf58: /* original 903c, guest PC 0x0c0bdf58 */
if(!s->budget--) { s->failed_pc=0x0c0bdf58u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdfd4u,2);
goto P_0c0bdf5a;
P_0c0bdf5a: /* original a03c, guest PC 0x0c0bdf5a */
if(!s->budget--) { s->failed_pc=0x0c0bdf5au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdfd6;
P_0c0bdf5c: /* original 05de, guest PC 0x0c0bdf5c */
if(!s->budget--) { s->failed_pc=0x0c0bdf5cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0bdf5eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bdf5eu; return 0; } return 1;
P_0c0bdfd6: /* original 942e, guest PC 0x0c0bdfd6 */
if(!s->budget--) { s->failed_pc=0x0c0bdfd6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be036u,2);
goto P_0c0bdfd8;
P_0c0bdfd8: /* original 4e0b, guest PC 0x0c0bdfd8 */
if(!s->budget--) { s->failed_pc=0x0c0bdfd8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdfdcu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdfdcu) { target=s->pc; goto dispatch; }
goto P_0c0bdfdc;
P_0c0bdfda: /* original 0009, guest PC 0x0c0bdfda */
if(!s->budget--) { s->failed_pc=0x0c0bdfdau; return 0; }
goto P_0c0bdfdc;
P_0c0bdfdc: /* original 942d, guest PC 0x0c0bdfdc */
if(!s->budget--) { s->failed_pc=0x0c0bdfdcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be03au,2);
goto P_0c0bdfde;
P_0c0bdfde: /* original 902b, guest PC 0x0c0bdfde */
if(!s->budget--) { s->failed_pc=0x0c0bdfdeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be038u,2);
goto P_0c0bdfe0;
P_0c0bdfe0: /* original 4e0b, guest PC 0x0c0bdfe0 */
if(!s->budget--) { s->failed_pc=0x0c0bdfe0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdfe4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdfe4u) { target=s->pc; goto dispatch; }
goto P_0c0bdfe4;
P_0c0bdfe2: /* original 05de, guest PC 0x0c0bdfe2 */
if(!s->budget--) { s->failed_pc=0x0c0bdfe2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdfe4;
P_0c0bdfe4: /* original 942b, guest PC 0x0c0bdfe4 */
if(!s->budget--) { s->failed_pc=0x0c0bdfe4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be03eu,2);
goto P_0c0bdfe6;
P_0c0bdfe6: /* original 9029, guest PC 0x0c0bdfe6 */
if(!s->budget--) { s->failed_pc=0x0c0bdfe6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be03cu,2);
goto P_0c0bdfe8;
P_0c0bdfe8: /* original 4e0b, guest PC 0x0c0bdfe8 */
if(!s->budget--) { s->failed_pc=0x0c0bdfe8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdfecu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdfecu) { target=s->pc; goto dispatch; }
goto P_0c0bdfec;
P_0c0bdfea: /* original 05de, guest PC 0x0c0bdfea */
if(!s->budget--) { s->failed_pc=0x0c0bdfeau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdfec;
P_0c0bdfec: /* original 9429, guest PC 0x0c0bdfec */
if(!s->budget--) { s->failed_pc=0x0c0bdfecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be042u,2);
goto P_0c0bdfee;
P_0c0bdfee: /* original 9027, guest PC 0x0c0bdfee */
if(!s->budget--) { s->failed_pc=0x0c0bdfeeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be040u,2);
goto P_0c0bdff0;
P_0c0bdff0: /* original 4e0b, guest PC 0x0c0bdff0 */
if(!s->budget--) { s->failed_pc=0x0c0bdff0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdff4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdff4u) { target=s->pc; goto dispatch; }
goto P_0c0bdff4;
P_0c0bdff2: /* original 05de, guest PC 0x0c0bdff2 */
if(!s->budget--) { s->failed_pc=0x0c0bdff2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdff4;
P_0c0bdff4: /* original 9427, guest PC 0x0c0bdff4 */
if(!s->budget--) { s->failed_pc=0x0c0bdff4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be046u,2);
goto P_0c0bdff6;
P_0c0bdff6: /* original 9025, guest PC 0x0c0bdff6 */
if(!s->budget--) { s->failed_pc=0x0c0bdff6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be044u,2);
goto P_0c0bdff8;
P_0c0bdff8: /* original 4e0b, guest PC 0x0c0bdff8 */
if(!s->budget--) { s->failed_pc=0x0c0bdff8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bdffcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bdffcu) { target=s->pc; goto dispatch; }
goto P_0c0bdffc;
P_0c0bdffa: /* original 05de, guest PC 0x0c0bdffa */
if(!s->budget--) { s->failed_pc=0x0c0bdffau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bdffc;
P_0c0bdffc: /* original 9425, guest PC 0x0c0bdffc */
if(!s->budget--) { s->failed_pc=0x0c0bdffcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be04au,2);
goto P_0c0bdffe;
P_0c0bdffe: /* original 9023, guest PC 0x0c0bdffe */
if(!s->budget--) { s->failed_pc=0x0c0bdffeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be048u,2);
goto P_0c0be000;
P_0c0be000: /* original 4e0b, guest PC 0x0c0be000 */
if(!s->budget--) { s->failed_pc=0x0c0be000u; return 0; }
target=r[14];
r[16]=code_base|0x0c0be004u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0be004u) { target=s->pc; goto dispatch; }
goto P_0c0be004;
P_0c0be002: /* original 05de, guest PC 0x0c0be002 */
if(!s->budget--) { s->failed_pc=0x0c0be002u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0be004;
P_0c0be004: /* original 9423, guest PC 0x0c0be004 */
if(!s->budget--) { s->failed_pc=0x0c0be004u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be04eu,2);
goto P_0c0be006;
P_0c0be006: /* original 9021, guest PC 0x0c0be006 */
if(!s->budget--) { s->failed_pc=0x0c0be006u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be04cu,2);
goto P_0c0be008;
P_0c0be008: /* original 4e0b, guest PC 0x0c0be008 */
if(!s->budget--) { s->failed_pc=0x0c0be008u; return 0; }
target=r[14];
r[16]=code_base|0x0c0be00cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0be00cu) { target=s->pc; goto dispatch; }
goto P_0c0be00c;
P_0c0be00a: /* original 05de, guest PC 0x0c0be00a */
if(!s->budget--) { s->failed_pc=0x0c0be00au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0be00c;
P_0c0be00c: /* original 9421, guest PC 0x0c0be00c */
if(!s->budget--) { s->failed_pc=0x0c0be00cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be052u,2);
goto P_0c0be00e;
P_0c0be00e: /* original 901f, guest PC 0x0c0be00e */
if(!s->budget--) { s->failed_pc=0x0c0be00eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be050u,2);
goto P_0c0be010;
P_0c0be010: /* original 4e0b, guest PC 0x0c0be010 */
if(!s->budget--) { s->failed_pc=0x0c0be010u; return 0; }
target=r[14];
r[16]=code_base|0x0c0be014u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0be014u) { target=s->pc; goto dispatch; }
goto P_0c0be014;
P_0c0be012: /* original 05de, guest PC 0x0c0be012 */
if(!s->budget--) { s->failed_pc=0x0c0be012u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0be014;
P_0c0be014: /* original 941f, guest PC 0x0c0be014 */
if(!s->budget--) { s->failed_pc=0x0c0be014u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be056u,2);
goto P_0c0be016;
P_0c0be016: /* original 901d, guest PC 0x0c0be016 */
if(!s->budget--) { s->failed_pc=0x0c0be016u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be054u,2);
goto P_0c0be018;
P_0c0be018: /* original 4e0b, guest PC 0x0c0be018 */
if(!s->budget--) { s->failed_pc=0x0c0be018u; return 0; }
target=r[14];
r[16]=code_base|0x0c0be01cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0be01cu) { target=s->pc; goto dispatch; }
goto P_0c0be01c;
P_0c0be01a: /* original 05de, guest PC 0x0c0be01a */
if(!s->budget--) { s->failed_pc=0x0c0be01au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0be01c;
P_0c0be01c: /* original 941d, guest PC 0x0c0be01c */
if(!s->budget--) { s->failed_pc=0x0c0be01cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be05au,2);
goto P_0c0be01e;
P_0c0be01e: /* original 901b, guest PC 0x0c0be01e */
if(!s->budget--) { s->failed_pc=0x0c0be01eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be058u,2);
goto P_0c0be020;
P_0c0be020: /* original 4e0b, guest PC 0x0c0be020 */
if(!s->budget--) { s->failed_pc=0x0c0be020u; return 0; }
target=r[14];
r[16]=code_base|0x0c0be024u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0be024u) { target=s->pc; goto dispatch; }
goto P_0c0be024;
P_0c0be022: /* original 05de, guest PC 0x0c0be022 */
if(!s->budget--) { s->failed_pc=0x0c0be022u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0be024;
P_0c0be024: /* original 7f08, guest PC 0x0c0be024 */
if(!s->budget--) { s->failed_pc=0x0c0be024u; return 0; }
r[15]+=0x00000008u;
goto P_0c0be026;
P_0c0be026: /* original 4f26, guest PC 0x0c0be026 */
if(!s->budget--) { s->failed_pc=0x0c0be026u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0be028;
P_0c0be028: /* original 69f6, guest PC 0x0c0be028 */
if(!s->budget--) { s->failed_pc=0x0c0be028u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0be02a;
P_0c0be02a: /* original 6af6, guest PC 0x0c0be02a */
if(!s->budget--) { s->failed_pc=0x0c0be02au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0be02c;
P_0c0be02c: /* original 6bf6, guest PC 0x0c0be02c */
if(!s->budget--) { s->failed_pc=0x0c0be02cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0be02e;
P_0c0be02e: /* original 6cf6, guest PC 0x0c0be02e */
if(!s->budget--) { s->failed_pc=0x0c0be02eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0be030;
P_0c0be030: /* original 6df6, guest PC 0x0c0be030 */
if(!s->budget--) { s->failed_pc=0x0c0be030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0be032;
P_0c0be032: /* original 000b, guest PC 0x0c0be032 */
if(!s->budget--) { s->failed_pc=0x0c0be032u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0be034: /* original 6ef6, guest PC 0x0c0be034 */
if(!s->budget--) { s->failed_pc=0x0c0be034u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0be036u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0be036u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
