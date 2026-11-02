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
int vf3_away_batch45_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07eb9eu: goto P_0c07eb9e;
case 0x0c07eba0u: goto P_0c07eba0;
case 0x0c07eba2u: goto P_0c07eba2;
case 0x0c07eba4u: goto P_0c07eba4;
case 0x0c07eba6u: goto P_0c07eba6;
case 0x0c07eba8u: goto P_0c07eba8;
case 0x0c07ebaau: goto P_0c07ebaa;
case 0x0c07ebacu: goto P_0c07ebac;
case 0x0c07ebaeu: goto P_0c07ebae;
case 0x0c07ebb0u: goto P_0c07ebb0;
case 0x0c07ebb2u: goto P_0c07ebb2;
case 0x0c07ebb4u: goto P_0c07ebb4;
case 0x0c07ebb6u: goto P_0c07ebb6;
case 0x0c07ebb8u: goto P_0c07ebb8;
case 0x0c07ebbau: goto P_0c07ebba;
case 0x0c07ebbcu: goto P_0c07ebbc;
case 0x0c07ebbeu: goto P_0c07ebbe;
case 0x0c07ebc0u: goto P_0c07ebc0;
case 0x0c07ebc2u: goto P_0c07ebc2;
case 0x0c07ebc4u: goto P_0c07ebc4;
case 0x0c07ebc6u: goto P_0c07ebc6;
case 0x0c07ebc8u: goto P_0c07ebc8;
case 0x0c07ebcau: goto P_0c07ebca;
case 0x0c07ebccu: goto P_0c07ebcc;
case 0x0c07ebceu: goto P_0c07ebce;
case 0x0c07ebd0u: goto P_0c07ebd0;
case 0x0c07ebd2u: goto P_0c07ebd2;
case 0x0c07ebd4u: goto P_0c07ebd4;
case 0x0c07ebd6u: goto P_0c07ebd6;
case 0x0c07ebd8u: goto P_0c07ebd8;
case 0x0c07ebdau: goto P_0c07ebda;
case 0x0c07ebdcu: goto P_0c07ebdc;
case 0x0c07ebdeu: goto P_0c07ebde;
case 0x0c07ebe0u: goto P_0c07ebe0;
case 0x0c07ebe2u: goto P_0c07ebe2;
case 0x0c07ebe4u: goto P_0c07ebe4;
case 0x0c07ebe6u: goto P_0c07ebe6;
case 0x0c07ebe8u: goto P_0c07ebe8;
case 0x0c07ebeau: goto P_0c07ebea;
case 0x0c07ebecu: goto P_0c07ebec;
case 0x0c07ebeeu: goto P_0c07ebee;
case 0x0c07ebf0u: goto P_0c07ebf0;
case 0x0c07ebf2u: goto P_0c07ebf2;
case 0x0c07ebf4u: goto P_0c07ebf4;
case 0x0c07ebf6u: goto P_0c07ebf6;
case 0x0c07ebf8u: goto P_0c07ebf8;
case 0x0c07ebfau: goto P_0c07ebfa;
case 0x0c07ebfcu: goto P_0c07ebfc;
case 0x0c07ebfeu: goto P_0c07ebfe;
case 0x0c07ec00u: goto P_0c07ec00;
case 0x0c07ec40u: goto P_0c07ec40;
case 0x0c07ec42u: goto P_0c07ec42;
case 0x0c07ec44u: goto P_0c07ec44;
case 0x0c07ec46u: goto P_0c07ec46;
case 0x0c07ec48u: goto P_0c07ec48;
case 0x0c07ec4au: goto P_0c07ec4a;
case 0x0c07ec4cu: goto P_0c07ec4c;
case 0x0c07ec4eu: goto P_0c07ec4e;
case 0x0c07ec50u: goto P_0c07ec50;
case 0x0c07ec52u: goto P_0c07ec52;
case 0x0c07ec54u: goto P_0c07ec54;
case 0x0c07ec56u: goto P_0c07ec56;
case 0x0c07ec58u: goto P_0c07ec58;
case 0x0c07ec5au: goto P_0c07ec5a;
case 0x0c07ec5cu: goto P_0c07ec5c;
case 0x0c07ec5eu: goto P_0c07ec5e;
case 0x0c07ec60u: goto P_0c07ec60;
case 0x0c07ec62u: goto P_0c07ec62;
case 0x0c07ec64u: goto P_0c07ec64;
case 0x0c07ec66u: goto P_0c07ec66;
case 0x0c07ec68u: goto P_0c07ec68;
case 0x0c07ec6au: goto P_0c07ec6a;
case 0x0c07ec6cu: goto P_0c07ec6c;
case 0x0c07ec6eu: goto P_0c07ec6e;
case 0x0c07ec70u: goto P_0c07ec70;
case 0x0c07ec72u: goto P_0c07ec72;
case 0x0c07ec74u: goto P_0c07ec74;
case 0x0c07ec76u: goto P_0c07ec76;
case 0x0c07ec78u: goto P_0c07ec78;
case 0x0c07ec7au: goto P_0c07ec7a;
case 0x0c07ec7cu: goto P_0c07ec7c;
case 0x0c07ec7eu: goto P_0c07ec7e;
case 0x0c07ec80u: goto P_0c07ec80;
case 0x0c07ec82u: goto P_0c07ec82;
case 0x0c07ec84u: goto P_0c07ec84;
case 0x0c07ec86u: goto P_0c07ec86;
case 0x0c07ec88u: goto P_0c07ec88;
case 0x0c07ec8au: goto P_0c07ec8a;
case 0x0c07ec8cu: goto P_0c07ec8c;
case 0x0c07ec8eu: goto P_0c07ec8e;
case 0x0c07ec90u: goto P_0c07ec90;
case 0x0c07ec92u: goto P_0c07ec92;
case 0x0c07ec94u: goto P_0c07ec94;
case 0x0c07ec96u: goto P_0c07ec96;
case 0x0c07ec98u: goto P_0c07ec98;
case 0x0c07ec9au: goto P_0c07ec9a;
case 0x0c07ec9cu: goto P_0c07ec9c;
case 0x0c07ec9eu: goto P_0c07ec9e;
case 0x0c07eca0u: goto P_0c07eca0;
case 0x0c07eca2u: goto P_0c07eca2;
case 0x0c07eca4u: goto P_0c07eca4;
case 0x0c07eca6u: goto P_0c07eca6;
case 0x0c07eca8u: goto P_0c07eca8;
case 0x0c07ecaau: goto P_0c07ecaa;
case 0x0c07ecacu: goto P_0c07ecac;
case 0x0c07ecaeu: goto P_0c07ecae;
case 0x0c07ecb0u: goto P_0c07ecb0;
case 0x0c07ecb2u: goto P_0c07ecb2;
case 0x0c07ecb4u: goto P_0c07ecb4;
case 0x0c07ecb6u: goto P_0c07ecb6;
case 0x0c07ecb8u: goto P_0c07ecb8;
case 0x0c07ecbau: goto P_0c07ecba;
case 0x0c07ecbcu: goto P_0c07ecbc;
case 0x0c07ecbeu: goto P_0c07ecbe;
case 0x0c07ecc0u: goto P_0c07ecc0;
case 0x0c07ecc2u: goto P_0c07ecc2;
case 0x0c07ecc4u: goto P_0c07ecc4;
case 0x0c07ecc6u: goto P_0c07ecc6;
case 0x0c07ecc8u: goto P_0c07ecc8;
case 0x0c07eccau: goto P_0c07ecca;
case 0x0c07ecccu: goto P_0c07eccc;
case 0x0c07ecceu: goto P_0c07ecce;
case 0x0c07ecd0u: goto P_0c07ecd0;
case 0x0c07ecd2u: goto P_0c07ecd2;
case 0x0c07ecd4u: goto P_0c07ecd4;
case 0x0c07ecd6u: goto P_0c07ecd6;
case 0x0c07ecd8u: goto P_0c07ecd8;
case 0x0c07ecdau: goto P_0c07ecda;
case 0x0c07ecdcu: goto P_0c07ecdc;
case 0x0c07ecdeu: goto P_0c07ecde;
case 0x0c07ece0u: goto P_0c07ece0;
case 0x0c07ece2u: goto P_0c07ece2;
case 0x0c07ece4u: goto P_0c07ece4;
case 0x0c07ece6u: goto P_0c07ece6;
case 0x0c07ece8u: goto P_0c07ece8;
case 0x0c07eceau: goto P_0c07ecea;
case 0x0c07ececu: goto P_0c07ecec;
case 0x0c07eceeu: goto P_0c07ecee;
case 0x0c07ecf0u: goto P_0c07ecf0;
case 0x0c07ecf2u: goto P_0c07ecf2;
case 0x0c07ecf4u: goto P_0c07ecf4;
case 0x0c07ecf6u: goto P_0c07ecf6;
case 0x0c07ecf8u: goto P_0c07ecf8;
case 0x0c07ecfau: goto P_0c07ecfa;
case 0x0c07ecfcu: goto P_0c07ecfc;
case 0x0c07ecfeu: goto P_0c07ecfe;
case 0x0c07ed00u: goto P_0c07ed00;
case 0x0c07ed02u: goto P_0c07ed02;
case 0x0c07ed04u: goto P_0c07ed04;
case 0x0c07ed06u: goto P_0c07ed06;
case 0x0c07ed08u: goto P_0c07ed08;
case 0x0c07ed0au: goto P_0c07ed0a;
case 0x0c07ed0cu: goto P_0c07ed0c;
case 0x0c07ed0eu: goto P_0c07ed0e;
case 0x0c07ed10u: goto P_0c07ed10;
case 0x0c07ed12u: goto P_0c07ed12;
case 0x0c07ed14u: goto P_0c07ed14;
case 0x0c07ed16u: goto P_0c07ed16;
case 0x0c07ed18u: goto P_0c07ed18;
case 0x0c07ed1au: goto P_0c07ed1a;
case 0x0c07ed1cu: goto P_0c07ed1c;
case 0x0c07ed1eu: goto P_0c07ed1e;
case 0x0c07ed20u: goto P_0c07ed20;
case 0x0c07ed58u: goto P_0c07ed58;
case 0x0c07ed5au: goto P_0c07ed5a;
case 0x0c07ed5cu: goto P_0c07ed5c;
case 0x0c07ed5eu: goto P_0c07ed5e;
case 0x0c07ed60u: goto P_0c07ed60;
case 0x0c07ed62u: goto P_0c07ed62;
case 0x0c07ed64u: goto P_0c07ed64;
case 0x0c07ed66u: goto P_0c07ed66;
case 0x0c07ed68u: goto P_0c07ed68;
case 0x0c07ed6au: goto P_0c07ed6a;
case 0x0c07ed6cu: goto P_0c07ed6c;
case 0x0c07ed6eu: goto P_0c07ed6e;
case 0x0c07ed70u: goto P_0c07ed70;
case 0x0c07ed72u: goto P_0c07ed72;
case 0x0c07ed74u: goto P_0c07ed74;
case 0x0c07ed76u: goto P_0c07ed76;
case 0x0c07ed78u: goto P_0c07ed78;
case 0x0c07ed7au: goto P_0c07ed7a;
case 0x0c07ed7cu: goto P_0c07ed7c;
case 0x0c07ed7eu: goto P_0c07ed7e;
case 0x0c07ed80u: goto P_0c07ed80;
case 0x0c07ed82u: goto P_0c07ed82;
case 0x0c07ed84u: goto P_0c07ed84;
case 0x0c07ed86u: goto P_0c07ed86;
case 0x0c07ed88u: goto P_0c07ed88;
case 0x0c07ed8au: goto P_0c07ed8a;
case 0x0c07ed8cu: goto P_0c07ed8c;
case 0x0c07ed8eu: goto P_0c07ed8e;
case 0x0c07ed90u: goto P_0c07ed90;
case 0x0c07ed92u: goto P_0c07ed92;
case 0x0c07ed94u: goto P_0c07ed94;
case 0x0c07ed96u: goto P_0c07ed96;
case 0x0c07ed98u: goto P_0c07ed98;
case 0x0c07ed9au: goto P_0c07ed9a;
case 0x0c07ed9cu: goto P_0c07ed9c;
case 0x0c07ed9eu: goto P_0c07ed9e;
case 0x0c07eda0u: goto P_0c07eda0;
case 0x0c07eda2u: goto P_0c07eda2;
case 0x0c07eda4u: goto P_0c07eda4;
case 0x0c07eda6u: goto P_0c07eda6;
case 0x0c07eda8u: goto P_0c07eda8;
case 0x0c07edaau: goto P_0c07edaa;
case 0x0c07edacu: goto P_0c07edac;
case 0x0c07edaeu: goto P_0c07edae;
case 0x0c07edb0u: goto P_0c07edb0;
case 0x0c07edb2u: goto P_0c07edb2;
case 0x0c07edb4u: goto P_0c07edb4;
case 0x0c07edb6u: goto P_0c07edb6;
case 0x0c07edb8u: goto P_0c07edb8;
case 0x0c07edbau: goto P_0c07edba;
case 0x0c07edbcu: goto P_0c07edbc;
case 0x0c07edbeu: goto P_0c07edbe;
case 0x0c07edc0u: goto P_0c07edc0;
case 0x0c07edc2u: goto P_0c07edc2;
case 0x0c07edc4u: goto P_0c07edc4;
case 0x0c07edc6u: goto P_0c07edc6;
case 0x0c07edc8u: goto P_0c07edc8;
case 0x0c07edcau: goto P_0c07edca;
case 0x0c07edccu: goto P_0c07edcc;
case 0x0c07edceu: goto P_0c07edce;
case 0x0c07edd0u: goto P_0c07edd0;
case 0x0c07edd2u: goto P_0c07edd2;
case 0x0c07edd4u: goto P_0c07edd4;
case 0x0c07edd6u: goto P_0c07edd6;
case 0x0c07edd8u: goto P_0c07edd8;
case 0x0c07eddau: goto P_0c07edda;
case 0x0c07eddcu: goto P_0c07eddc;
case 0x0c07eddeu: goto P_0c07edde;
case 0x0c07ede0u: goto P_0c07ede0;
case 0x0c07ede2u: goto P_0c07ede2;
case 0x0c07ede4u: goto P_0c07ede4;
case 0x0c07ede6u: goto P_0c07ede6;
case 0x0c07ede8u: goto P_0c07ede8;
case 0x0c07edeau: goto P_0c07edea;
case 0x0c07edecu: goto P_0c07edec;
case 0x0c07edeeu: goto P_0c07edee;
case 0x0c07edf0u: goto P_0c07edf0;
case 0x0c07edf2u: goto P_0c07edf2;
case 0x0c07edf4u: goto P_0c07edf4;
case 0x0c07edf6u: goto P_0c07edf6;
case 0x0c07edf8u: goto P_0c07edf8;
case 0x0c07edfau: goto P_0c07edfa;
case 0x0c07edfcu: goto P_0c07edfc;
case 0x0c07edfeu: goto P_0c07edfe;
case 0x0c07ee00u: goto P_0c07ee00;
case 0x0c07ee02u: goto P_0c07ee02;
case 0x0c07ee04u: goto P_0c07ee04;
case 0x0c07ee06u: goto P_0c07ee06;
case 0x0c07ee08u: goto P_0c07ee08;
case 0x0c07ee0au: goto P_0c07ee0a;
case 0x0c07ee0cu: goto P_0c07ee0c;
case 0x0c07ee0eu: goto P_0c07ee0e;
case 0x0c07ee10u: goto P_0c07ee10;
case 0x0c07ee12u: goto P_0c07ee12;
case 0x0c07ee14u: goto P_0c07ee14;
case 0x0c07ee16u: goto P_0c07ee16;
case 0x0c07ee18u: goto P_0c07ee18;
case 0x0c07ee1au: goto P_0c07ee1a;
case 0x0c07ee1cu: goto P_0c07ee1c;
case 0x0c07ee1eu: goto P_0c07ee1e;
case 0x0c07ee20u: goto P_0c07ee20;
case 0x0c07ee22u: goto P_0c07ee22;
case 0x0c07ee24u: goto P_0c07ee24;
case 0x0c07ee26u: goto P_0c07ee26;
case 0x0c07ee28u: goto P_0c07ee28;
case 0x0c07ee2au: goto P_0c07ee2a;
case 0x0c07ee2cu: goto P_0c07ee2c;
case 0x0c07ee2eu: goto P_0c07ee2e;
case 0x0c07ee30u: goto P_0c07ee30;
case 0x0c07ee32u: goto P_0c07ee32;
case 0x0c07f018u: goto P_0c07f018;
case 0x0c07f01au: goto P_0c07f01a;
case 0x0c07f01cu: goto P_0c07f01c;
case 0x0c07f01eu: goto P_0c07f01e;
case 0x0c07f020u: goto P_0c07f020;
case 0x0c07f022u: goto P_0c07f022;
case 0x0c07f024u: goto P_0c07f024;
case 0x0c07f026u: goto P_0c07f026;
case 0x0c07f028u: goto P_0c07f028;
case 0x0c07f02au: goto P_0c07f02a;
case 0x0c07f02cu: goto P_0c07f02c;
case 0x0c07f02eu: goto P_0c07f02e;
case 0x0c07f030u: goto P_0c07f030;
case 0x0c07f032u: goto P_0c07f032;
case 0x0c07f034u: goto P_0c07f034;
case 0x0c07f036u: goto P_0c07f036;
case 0x0c07f038u: goto P_0c07f038;
case 0x0c07f03au: goto P_0c07f03a;
case 0x0c07f03cu: goto P_0c07f03c;
case 0x0c07f03eu: goto P_0c07f03e;
case 0x0c07f040u: goto P_0c07f040;
case 0x0c07f042u: goto P_0c07f042;
case 0x0c07f044u: goto P_0c07f044;
case 0x0c07f046u: goto P_0c07f046;
case 0x0c07f048u: goto P_0c07f048;
case 0x0c07f04au: goto P_0c07f04a;
case 0x0c07f04cu: goto P_0c07f04c;
case 0x0c07f04eu: goto P_0c07f04e;
case 0x0c07f050u: goto P_0c07f050;
case 0x0c07f052u: goto P_0c07f052;
case 0x0c07f054u: goto P_0c07f054;
case 0x0c07f056u: goto P_0c07f056;
case 0x0c07f058u: goto P_0c07f058;
case 0x0c07f05au: goto P_0c07f05a;
case 0x0c07f05cu: goto P_0c07f05c;
case 0x0c07f05eu: goto P_0c07f05e;
case 0x0c07f060u: goto P_0c07f060;
case 0x0c07f062u: goto P_0c07f062;
case 0x0c07f064u: goto P_0c07f064;
case 0x0c07f066u: goto P_0c07f066;
case 0x0c07f068u: goto P_0c07f068;
case 0x0c07f06au: goto P_0c07f06a;
case 0x0c07f06cu: goto P_0c07f06c;
case 0x0c07f06eu: goto P_0c07f06e;
case 0x0c07f070u: goto P_0c07f070;
case 0x0c07f072u: goto P_0c07f072;
case 0x0c07f074u: goto P_0c07f074;
case 0x0c07f076u: goto P_0c07f076;
case 0x0c07f078u: goto P_0c07f078;
case 0x0c07f07au: goto P_0c07f07a;
case 0x0c07f07cu: goto P_0c07f07c;
case 0x0c07f07eu: goto P_0c07f07e;
case 0x0c07f080u: goto P_0c07f080;
case 0x0c07f082u: goto P_0c07f082;
case 0x0c07f084u: goto P_0c07f084;
case 0x0c07f086u: goto P_0c07f086;
case 0x0c07f088u: goto P_0c07f088;
case 0x0c07f1acu: goto P_0c07f1ac;
case 0x0c07f1aeu: goto P_0c07f1ae;
case 0x0c07f1b0u: goto P_0c07f1b0;
case 0x0c07f1b2u: goto P_0c07f1b2;
case 0x0c07f1b4u: goto P_0c07f1b4;
case 0x0c07f1b6u: goto P_0c07f1b6;
case 0x0c07f1b8u: goto P_0c07f1b8;
case 0x0c07f1bau: goto P_0c07f1ba;
case 0x0c07f1bcu: goto P_0c07f1bc;
case 0x0c07f1beu: goto P_0c07f1be;
case 0x0c07f1c0u: goto P_0c07f1c0;
case 0x0c07f1c2u: goto P_0c07f1c2;
case 0x0c07f1c4u: goto P_0c07f1c4;
case 0x0c07f1c6u: goto P_0c07f1c6;
case 0x0c07f1c8u: goto P_0c07f1c8;
case 0x0c07f1cau: goto P_0c07f1ca;
case 0x0c07f1ccu: goto P_0c07f1cc;
case 0x0c07f1ceu: goto P_0c07f1ce;
case 0x0c07f1d0u: goto P_0c07f1d0;
case 0x0c07f1d2u: goto P_0c07f1d2;
case 0x0c07f1d4u: goto P_0c07f1d4;
case 0x0c07f1d6u: goto P_0c07f1d6;
case 0x0c07f1d8u: goto P_0c07f1d8;
case 0x0c07f1dau: goto P_0c07f1da;
case 0x0c07f1dcu: goto P_0c07f1dc;
case 0x0c07f1deu: goto P_0c07f1de;
case 0x0c07f1e0u: goto P_0c07f1e0;
case 0x0c07f1e2u: goto P_0c07f1e2;
case 0x0c07f1e4u: goto P_0c07f1e4;
case 0x0c07f1e6u: goto P_0c07f1e6;
case 0x0c07f1e8u: goto P_0c07f1e8;
case 0x0c07f1eau: goto P_0c07f1ea;
case 0x0c07f1ecu: goto P_0c07f1ec;
case 0x0c07f1eeu: goto P_0c07f1ee;
case 0x0c07f1f0u: goto P_0c07f1f0;
case 0x0c07f1f2u: goto P_0c07f1f2;
case 0x0c07f1f4u: goto P_0c07f1f4;
case 0x0c07f1f6u: goto P_0c07f1f6;
case 0x0c07f1f8u: goto P_0c07f1f8;
case 0x0c07f238u: goto P_0c07f238;
case 0x0c07f23au: goto P_0c07f23a;
case 0x0c07f23cu: goto P_0c07f23c;
case 0x0c07f23eu: goto P_0c07f23e;
case 0x0c07f240u: goto P_0c07f240;
case 0x0c07f242u: goto P_0c07f242;
case 0x0c07f244u: goto P_0c07f244;
case 0x0c07f246u: goto P_0c07f246;
case 0x0c07f248u: goto P_0c07f248;
case 0x0c07f24au: goto P_0c07f24a;
case 0x0c07f24cu: goto P_0c07f24c;
case 0x0c07f24eu: goto P_0c07f24e;
case 0x0c07f250u: goto P_0c07f250;
case 0x0c07f252u: goto P_0c07f252;
case 0x0c07f254u: goto P_0c07f254;
case 0x0c07f256u: goto P_0c07f256;
case 0x0c07f258u: goto P_0c07f258;
case 0x0c07f25au: goto P_0c07f25a;
case 0x0c07f25cu: goto P_0c07f25c;
case 0x0c07f25eu: goto P_0c07f25e;
case 0x0c07f260u: goto P_0c07f260;
case 0x0c07f262u: goto P_0c07f262;
case 0x0c07f264u: goto P_0c07f264;
case 0x0c07f266u: goto P_0c07f266;
case 0x0c07f268u: goto P_0c07f268;
case 0x0c07f26au: goto P_0c07f26a;
case 0x0c07f26cu: goto P_0c07f26c;
case 0x0c07f26eu: goto P_0c07f26e;
case 0x0c07f270u: goto P_0c07f270;
case 0x0c07f272u: goto P_0c07f272;
case 0x0c07f274u: goto P_0c07f274;
case 0x0c07f276u: goto P_0c07f276;
case 0x0c07f278u: goto P_0c07f278;
case 0x0c07f27au: goto P_0c07f27a;
case 0x0c07f27cu: goto P_0c07f27c;
case 0x0c07f27eu: goto P_0c07f27e;
case 0x0c07f280u: goto P_0c07f280;
case 0x0c07f282u: goto P_0c07f282;
case 0x0c07f284u: goto P_0c07f284;
case 0x0c07f286u: goto P_0c07f286;
case 0x0c07f288u: goto P_0c07f288;
case 0x0c07f28au: goto P_0c07f28a;
case 0x0c07f28cu: goto P_0c07f28c;
case 0x0c07f28eu: goto P_0c07f28e;
case 0x0c07f290u: goto P_0c07f290;
case 0x0c07f292u: goto P_0c07f292;
case 0x0c07f294u: goto P_0c07f294;
case 0x0c07f296u: goto P_0c07f296;
case 0x0c07f298u: goto P_0c07f298;
case 0x0c07f29au: goto P_0c07f29a;
case 0x0c07f29cu: goto P_0c07f29c;
case 0x0c07f29eu: goto P_0c07f29e;
case 0x0c07f2a0u: goto P_0c07f2a0;
case 0x0c07f2a2u: goto P_0c07f2a2;
case 0x0c07f2a4u: goto P_0c07f2a4;
case 0x0c07f2a6u: goto P_0c07f2a6;
case 0x0c07f2a8u: goto P_0c07f2a8;
case 0x0c07f2aau: goto P_0c07f2aa;
case 0x0c07f2acu: goto P_0c07f2ac;
case 0x0c07f2aeu: goto P_0c07f2ae;
case 0x0c07f2b0u: goto P_0c07f2b0;
case 0x0c07f2b2u: goto P_0c07f2b2;
case 0x0c07f2b4u: goto P_0c07f2b4;
case 0x0c07f2b6u: goto P_0c07f2b6;
case 0x0c07f2b8u: goto P_0c07f2b8;
case 0x0c07f2bau: goto P_0c07f2ba;
case 0x0c07f2bcu: goto P_0c07f2bc;
case 0x0c07f2beu: goto P_0c07f2be;
case 0x0c07f2c0u: goto P_0c07f2c0;
case 0x0c07f2c2u: goto P_0c07f2c2;
case 0x0c07f2c4u: goto P_0c07f2c4;
case 0x0c07f2c6u: goto P_0c07f2c6;
case 0x0c07f2c8u: goto P_0c07f2c8;
case 0x0c07f2cau: goto P_0c07f2ca;
case 0x0c07f2ccu: goto P_0c07f2cc;
case 0x0c07f2ceu: goto P_0c07f2ce;
case 0x0c07f2d0u: goto P_0c07f2d0;
case 0x0c07f2d2u: goto P_0c07f2d2;
case 0x0c07f2d4u: goto P_0c07f2d4;
case 0x0c07f2d6u: goto P_0c07f2d6;
case 0x0c07f2d8u: goto P_0c07f2d8;
case 0x0c07f2dau: goto P_0c07f2da;
case 0x0c07f2dcu: goto P_0c07f2dc;
case 0x0c07f2deu: goto P_0c07f2de;
case 0x0c07f2e0u: goto P_0c07f2e0;
case 0x0c07f2e2u: goto P_0c07f2e2;
case 0x0c07f2e4u: goto P_0c07f2e4;
case 0x0c07f2e6u: goto P_0c07f2e6;
case 0x0c07f2e8u: goto P_0c07f2e8;
case 0x0c07f2eau: goto P_0c07f2ea;
case 0x0c07f2ecu: goto P_0c07f2ec;
case 0x0c07f2eeu: goto P_0c07f2ee;
case 0x0c07f2f0u: goto P_0c07f2f0;
case 0x0c07f2f2u: goto P_0c07f2f2;
case 0x0c07f2f4u: goto P_0c07f2f4;
case 0x0c07f2f6u: goto P_0c07f2f6;
case 0x0c07f2f8u: goto P_0c07f2f8;
case 0x0c07f2fau: goto P_0c07f2fa;
case 0x0c07f2fcu: goto P_0c07f2fc;
case 0x0c07f2feu: goto P_0c07f2fe;
case 0x0c07f300u: goto P_0c07f300;
case 0x0c07f302u: goto P_0c07f302;
case 0x0c07f304u: goto P_0c07f304;
case 0x0c07f306u: goto P_0c07f306;
case 0x0c07f308u: goto P_0c07f308;
case 0x0c07f30au: goto P_0c07f30a;
case 0x0c07f30cu: goto P_0c07f30c;
case 0x0c07f30eu: goto P_0c07f30e;
case 0x0c07f310u: goto P_0c07f310;
case 0x0c07f312u: goto P_0c07f312;
case 0x0c07f314u: goto P_0c07f314;
case 0x0c07f316u: goto P_0c07f316;
case 0x0c07f318u: goto P_0c07f318;
case 0x0c07f31au: goto P_0c07f31a;
case 0x0c07f31cu: goto P_0c07f31c;
case 0x0c07f31eu: goto P_0c07f31e;
case 0x0c07f320u: goto P_0c07f320;
case 0x0c07f322u: goto P_0c07f322;
case 0x0c07f324u: goto P_0c07f324;
case 0x0c07f326u: goto P_0c07f326;
case 0x0c07f328u: goto P_0c07f328;
case 0x0c07f32au: goto P_0c07f32a;
case 0x0c07f32cu: goto P_0c07f32c;
case 0x0c07f32eu: goto P_0c07f32e;
case 0x0c07f330u: goto P_0c07f330;
case 0x0c07f332u: goto P_0c07f332;
case 0x0c07f334u: goto P_0c07f334;
case 0x0c07f336u: goto P_0c07f336;
case 0x0c07f338u: goto P_0c07f338;
case 0x0c07f33au: goto P_0c07f33a;
case 0x0c07f33cu: goto P_0c07f33c;
case 0x0c07f33eu: goto P_0c07f33e;
case 0x0c07f340u: goto P_0c07f340;
case 0x0c07f342u: goto P_0c07f342;
case 0x0c07f344u: goto P_0c07f344;
case 0x0c07f346u: goto P_0c07f346;
case 0x0c07f348u: goto P_0c07f348;
case 0x0c07f34au: goto P_0c07f34a;
case 0x0c07f34cu: goto P_0c07f34c;
case 0x0c07f34eu: goto P_0c07f34e;
case 0x0c07f350u: goto P_0c07f350;
case 0x0c07f352u: goto P_0c07f352;
case 0x0c07f354u: goto P_0c07f354;
case 0x0c07f356u: goto P_0c07f356;
case 0x0c07f358u: goto P_0c07f358;
case 0x0c07f35au: goto P_0c07f35a;
case 0x0c07f35cu: goto P_0c07f35c;
case 0x0c07f35eu: goto P_0c07f35e;
case 0x0c07f360u: goto P_0c07f360;
case 0x0c07f362u: goto P_0c07f362;
case 0x0c07f364u: goto P_0c07f364;
case 0x0c07f366u: goto P_0c07f366;
case 0x0c07f368u: goto P_0c07f368;
case 0x0c07f36au: goto P_0c07f36a;
case 0x0c07f36cu: goto P_0c07f36c;
case 0x0c07f36eu: goto P_0c07f36e;
case 0x0c07f370u: goto P_0c07f370;
case 0x0c07f372u: goto P_0c07f372;
case 0x0c07f374u: goto P_0c07f374;
case 0x0c07f376u: goto P_0c07f376;
case 0x0c07f378u: goto P_0c07f378;
case 0x0c07f37au: goto P_0c07f37a;
case 0x0c07f37cu: goto P_0c07f37c;
case 0x0c07f37eu: goto P_0c07f37e;
case 0x0c07f380u: goto P_0c07f380;
case 0x0c07f382u: goto P_0c07f382;
case 0x0c07f384u: goto P_0c07f384;
case 0x0c07f386u: goto P_0c07f386;
case 0x0c07f388u: goto P_0c07f388;
case 0x0c07f38au: goto P_0c07f38a;
case 0x0c07f38cu: goto P_0c07f38c;
case 0x0c07f38eu: goto P_0c07f38e;
case 0x0c07f390u: goto P_0c07f390;
case 0x0c07f392u: goto P_0c07f392;
case 0x0c07f394u: goto P_0c07f394;
case 0x0c07f3e0u: goto P_0c07f3e0;
case 0x0c07f3e2u: goto P_0c07f3e2;
case 0x0c07f3e4u: goto P_0c07f3e4;
case 0x0c07f3e6u: goto P_0c07f3e6;
case 0x0c07f3e8u: goto P_0c07f3e8;
case 0x0c07f3eau: goto P_0c07f3ea;
case 0x0c07f3ecu: goto P_0c07f3ec;
case 0x0c07f3eeu: goto P_0c07f3ee;
case 0x0c07f3f0u: goto P_0c07f3f0;
case 0x0c07f3f2u: goto P_0c07f3f2;
case 0x0c07f3f4u: goto P_0c07f3f4;
case 0x0c07f3f6u: goto P_0c07f3f6;
case 0x0c07f3f8u: goto P_0c07f3f8;
case 0x0c07f3fau: goto P_0c07f3fa;
case 0x0c07f3fcu: goto P_0c07f3fc;
case 0x0c07f3feu: goto P_0c07f3fe;
case 0x0c07f400u: goto P_0c07f400;
case 0x0c07f402u: goto P_0c07f402;
case 0x0c07f404u: goto P_0c07f404;
case 0x0c07f406u: goto P_0c07f406;
case 0x0c07f408u: goto P_0c07f408;
case 0x0c07f40au: goto P_0c07f40a;
case 0x0c07f40cu: goto P_0c07f40c;
case 0x0c07f40eu: goto P_0c07f40e;
case 0x0c07f424u: goto P_0c07f424;
case 0x0c07f426u: goto P_0c07f426;
case 0x0c07f428u: goto P_0c07f428;
case 0x0c07f42au: goto P_0c07f42a;
case 0x0c07f42cu: goto P_0c07f42c;
case 0x0c07f42eu: goto P_0c07f42e;
case 0x0c07f430u: goto P_0c07f430;
case 0x0c07f432u: goto P_0c07f432;
case 0x0c07f434u: goto P_0c07f434;
case 0x0c07f436u: goto P_0c07f436;
case 0x0c07f438u: goto P_0c07f438;
case 0x0c07f43au: goto P_0c07f43a;
case 0x0c07f43cu: goto P_0c07f43c;
case 0x0c07f43eu: goto P_0c07f43e;
case 0x0c07f440u: goto P_0c07f440;
case 0x0c07f442u: goto P_0c07f442;
case 0x0c07f444u: goto P_0c07f444;
case 0x0c07f446u: goto P_0c07f446;
case 0x0c07f448u: goto P_0c07f448;
case 0x0c07f44au: goto P_0c07f44a;
case 0x0c07f44cu: goto P_0c07f44c;
case 0x0c07f44eu: goto P_0c07f44e;
case 0x0c07f450u: goto P_0c07f450;
case 0x0c07f452u: goto P_0c07f452;
case 0x0c07f454u: goto P_0c07f454;
case 0x0c07f456u: goto P_0c07f456;
case 0x0c07f458u: goto P_0c07f458;
case 0x0c07f45au: goto P_0c07f45a;
case 0x0c07f45cu: goto P_0c07f45c;
case 0x0c07f45eu: goto P_0c07f45e;
case 0x0c07f460u: goto P_0c07f460;
case 0x0c07f462u: goto P_0c07f462;
case 0x0c07f464u: goto P_0c07f464;
case 0x0c07f466u: goto P_0c07f466;
case 0x0c07f468u: goto P_0c07f468;
case 0x0c07f46au: goto P_0c07f46a;
case 0x0c07f46cu: goto P_0c07f46c;
case 0x0c07f46eu: goto P_0c07f46e;
case 0x0c07f470u: goto P_0c07f470;
case 0x0c07f472u: goto P_0c07f472;
case 0x0c07f474u: goto P_0c07f474;
case 0x0c07f476u: goto P_0c07f476;
case 0x0c07f478u: goto P_0c07f478;
case 0x0c07f47au: goto P_0c07f47a;
case 0x0c07f47cu: goto P_0c07f47c;
case 0x0c07f47eu: goto P_0c07f47e;
case 0x0c07f480u: goto P_0c07f480;
case 0x0c07f482u: goto P_0c07f482;
case 0x0c07f484u: goto P_0c07f484;
case 0x0c07f486u: goto P_0c07f486;
case 0x0c07f488u: goto P_0c07f488;
case 0x0c07f48au: goto P_0c07f48a;
case 0x0c07f48cu: goto P_0c07f48c;
case 0x0c07f48eu: goto P_0c07f48e;
case 0x0c07f490u: goto P_0c07f490;
case 0x0c07f492u: goto P_0c07f492;
case 0x0c07f494u: goto P_0c07f494;
case 0x0c07f496u: goto P_0c07f496;
case 0x0c07f498u: goto P_0c07f498;
case 0x0c07f49au: goto P_0c07f49a;
case 0x0c07f49cu: goto P_0c07f49c;
case 0x0c07f49eu: goto P_0c07f49e;
case 0x0c07f4a0u: goto P_0c07f4a0;
case 0x0c07f4a2u: goto P_0c07f4a2;
case 0x0c07f4a4u: goto P_0c07f4a4;
case 0x0c07f4a6u: goto P_0c07f4a6;
case 0x0c07f4a8u: goto P_0c07f4a8;
case 0x0c07f4aau: goto P_0c07f4aa;
case 0x0c07f4acu: goto P_0c07f4ac;
case 0x0c07f4aeu: goto P_0c07f4ae;
case 0x0c07f4b0u: goto P_0c07f4b0;
case 0x0c07f4b2u: goto P_0c07f4b2;
case 0x0c07f4b4u: goto P_0c07f4b4;
case 0x0c07f4b6u: goto P_0c07f4b6;
case 0x0c07f4b8u: goto P_0c07f4b8;
case 0x0c07f4bau: goto P_0c07f4ba;
case 0x0c07f4bcu: goto P_0c07f4bc;
case 0x0c07f4beu: goto P_0c07f4be;
case 0x0c07f4c0u: goto P_0c07f4c0;
case 0x0c07f4c2u: goto P_0c07f4c2;
case 0x0c07f4c4u: goto P_0c07f4c4;
case 0x0c07f4c6u: goto P_0c07f4c6;
case 0x0c07f4c8u: goto P_0c07f4c8;
case 0x0c07f4cau: goto P_0c07f4ca;
case 0x0c07f4ccu: goto P_0c07f4cc;
case 0x0c07f4ceu: goto P_0c07f4ce;
case 0x0c07f4d0u: goto P_0c07f4d0;
case 0x0c07f4d2u: goto P_0c07f4d2;
case 0x0c07f4d4u: goto P_0c07f4d4;
case 0x0c07f4d6u: goto P_0c07f4d6;
case 0x0c07f4d8u: goto P_0c07f4d8;
case 0x0c07f4dau: goto P_0c07f4da;
case 0x0c07f4dcu: goto P_0c07f4dc;
case 0x0c07f4deu: goto P_0c07f4de;
case 0x0c07f4e0u: goto P_0c07f4e0;
case 0x0c07f4e2u: goto P_0c07f4e2;
case 0x0c07f4e4u: goto P_0c07f4e4;
case 0x0c07f4e6u: goto P_0c07f4e6;
case 0x0c07f4e8u: goto P_0c07f4e8;
case 0x0c07f4eau: goto P_0c07f4ea;
case 0x0c07f4ecu: goto P_0c07f4ec;
case 0x0c07f4eeu: goto P_0c07f4ee;
case 0x0c07f4f0u: goto P_0c07f4f0;
case 0x0c07f4f2u: goto P_0c07f4f2;
case 0x0c07f4f4u: goto P_0c07f4f4;
case 0x0c07f4f6u: goto P_0c07f4f6;
case 0x0c07f4f8u: goto P_0c07f4f8;
case 0x0c07f4fau: goto P_0c07f4fa;
case 0x0c07f4fcu: goto P_0c07f4fc;
case 0x0c07f4feu: goto P_0c07f4fe;
case 0x0c07f500u: goto P_0c07f500;
case 0x0c07f502u: goto P_0c07f502;
case 0x0c07f504u: goto P_0c07f504;
case 0x0c07f506u: goto P_0c07f506;
case 0x0c07f508u: goto P_0c07f508;
case 0x0c07f50au: goto P_0c07f50a;
case 0x0c07f50cu: goto P_0c07f50c;
case 0x0c07f50eu: goto P_0c07f50e;
case 0x0c07f510u: goto P_0c07f510;
case 0x0c07f512u: goto P_0c07f512;
case 0x0c07f514u: goto P_0c07f514;
case 0x0c07f516u: goto P_0c07f516;
case 0x0c07f518u: goto P_0c07f518;
case 0x0c07f51au: goto P_0c07f51a;
case 0x0c07f51cu: goto P_0c07f51c;
case 0x0c07f51eu: goto P_0c07f51e;
case 0x0c07f520u: goto P_0c07f520;
case 0x0c07f522u: goto P_0c07f522;
case 0x0c07f524u: goto P_0c07f524;
case 0x0c07f526u: goto P_0c07f526;
case 0x0c07f528u: goto P_0c07f528;
case 0x0c07f52au: goto P_0c07f52a;
case 0x0c07f52cu: goto P_0c07f52c;
case 0x0c07f52eu: goto P_0c07f52e;
case 0x0c07f530u: goto P_0c07f530;
case 0x0c07f532u: goto P_0c07f532;
case 0x0c07f534u: goto P_0c07f534;
case 0x0c07f536u: goto P_0c07f536;
case 0x0c07f538u: goto P_0c07f538;
case 0x0c07f53au: goto P_0c07f53a;
case 0x0c07f53cu: goto P_0c07f53c;
case 0x0c07f53eu: goto P_0c07f53e;
case 0x0c07f540u: goto P_0c07f540;
case 0x0c07f580u: goto P_0c07f580;
case 0x0c07f582u: goto P_0c07f582;
case 0x0c07f584u: goto P_0c07f584;
case 0x0c07f586u: goto P_0c07f586;
case 0x0c07f588u: goto P_0c07f588;
case 0x0c07f58au: goto P_0c07f58a;
case 0x0c07f58cu: goto P_0c07f58c;
case 0x0c07f58eu: goto P_0c07f58e;
case 0x0c07f590u: goto P_0c07f590;
case 0x0c07f592u: goto P_0c07f592;
case 0x0c07f594u: goto P_0c07f594;
case 0x0c07f596u: goto P_0c07f596;
case 0x0c07f598u: goto P_0c07f598;
case 0x0c07f59au: goto P_0c07f59a;
case 0x0c07f59cu: goto P_0c07f59c;
case 0x0c07f59eu: goto P_0c07f59e;
case 0x0c07f5a0u: goto P_0c07f5a0;
case 0x0c07f5a2u: goto P_0c07f5a2;
case 0x0c07f5a4u: goto P_0c07f5a4;
case 0x0c07f5a6u: goto P_0c07f5a6;
case 0x0c07f5a8u: goto P_0c07f5a8;
case 0x0c07f5aau: goto P_0c07f5aa;
case 0x0c07f5acu: goto P_0c07f5ac;
case 0x0c07f5aeu: goto P_0c07f5ae;
case 0x0c07f5b0u: goto P_0c07f5b0;
case 0x0c07f5b2u: goto P_0c07f5b2;
case 0x0c07f5b4u: goto P_0c07f5b4;
case 0x0c07f5b6u: goto P_0c07f5b6;
case 0x0c07f5b8u: goto P_0c07f5b8;
case 0x0c07f5bau: goto P_0c07f5ba;
case 0x0c07f5bcu: goto P_0c07f5bc;
case 0x0c07f5beu: goto P_0c07f5be;
case 0x0c07f5c0u: goto P_0c07f5c0;
case 0x0c07f5c2u: goto P_0c07f5c2;
case 0x0c07f5c4u: goto P_0c07f5c4;
case 0x0c07f5c6u: goto P_0c07f5c6;
case 0x0c07f5c8u: goto P_0c07f5c8;
case 0x0c07f5cau: goto P_0c07f5ca;
case 0x0c07f5ccu: goto P_0c07f5cc;
case 0x0c07f5ceu: goto P_0c07f5ce;
case 0x0c07f5d0u: goto P_0c07f5d0;
case 0x0c07f5d2u: goto P_0c07f5d2;
case 0x0c07f5d4u: goto P_0c07f5d4;
case 0x0c07f5d6u: goto P_0c07f5d6;
case 0x0c07f5d8u: goto P_0c07f5d8;
case 0x0c07f5dau: goto P_0c07f5da;
case 0x0c07f5dcu: goto P_0c07f5dc;
case 0x0c07f5deu: goto P_0c07f5de;
case 0x0c07f5e0u: goto P_0c07f5e0;
case 0x0c07f5e2u: goto P_0c07f5e2;
case 0x0c07f5e4u: goto P_0c07f5e4;
case 0x0c07f5e6u: goto P_0c07f5e6;
case 0x0c07f5f8u: goto P_0c07f5f8;
case 0x0c07f5fau: goto P_0c07f5fa;
case 0x0c07f5fcu: goto P_0c07f5fc;
case 0x0c07f5feu: goto P_0c07f5fe;
case 0x0c07f600u: goto P_0c07f600;
case 0x0c07f602u: goto P_0c07f602;
case 0x0c07f604u: goto P_0c07f604;
case 0x0c07f606u: goto P_0c07f606;
case 0x0c07f608u: goto P_0c07f608;
case 0x0c07f60au: goto P_0c07f60a;
case 0x0c07f60cu: goto P_0c07f60c;
case 0x0c07f60eu: goto P_0c07f60e;
case 0x0c07f610u: goto P_0c07f610;
case 0x0c07f612u: goto P_0c07f612;
case 0x0c07f614u: goto P_0c07f614;
case 0x0c07f616u: goto P_0c07f616;
case 0x0c07f618u: goto P_0c07f618;
case 0x0c07f61au: goto P_0c07f61a;
case 0x0c07f61cu: goto P_0c07f61c;
case 0x0c07f61eu: goto P_0c07f61e;
case 0x0c07f620u: goto P_0c07f620;
case 0x0c07f622u: goto P_0c07f622;
case 0x0c07f624u: goto P_0c07f624;
case 0x0c07f626u: goto P_0c07f626;
case 0x0c07f628u: goto P_0c07f628;
case 0x0c07f62au: goto P_0c07f62a;
case 0x0c07f62cu: goto P_0c07f62c;
case 0x0c07f62eu: goto P_0c07f62e;
case 0x0c07f630u: goto P_0c07f630;
case 0x0c07f632u: goto P_0c07f632;
case 0x0c07f634u: goto P_0c07f634;
case 0x0c07f636u: goto P_0c07f636;
case 0x0c07f638u: goto P_0c07f638;
case 0x0c07f63au: goto P_0c07f63a;
case 0x0c07f63cu: goto P_0c07f63c;
case 0x0c07f63eu: goto P_0c07f63e;
case 0x0c07f640u: goto P_0c07f640;
case 0x0c07f642u: goto P_0c07f642;
case 0x0c07f644u: goto P_0c07f644;
case 0x0c07f646u: goto P_0c07f646;
case 0x0c07f648u: goto P_0c07f648;
case 0x0c07f64au: goto P_0c07f64a;
case 0x0c07f64cu: goto P_0c07f64c;
case 0x0c07f64eu: goto P_0c07f64e;
case 0x0c07f650u: goto P_0c07f650;
case 0x0c07f652u: goto P_0c07f652;
case 0x0c07f654u: goto P_0c07f654;
case 0x0c07f656u: goto P_0c07f656;
case 0x0c07f658u: goto P_0c07f658;
case 0x0c07f65au: goto P_0c07f65a;
case 0x0c07f65cu: goto P_0c07f65c;
case 0x0c07f65eu: goto P_0c07f65e;
case 0x0c07f660u: goto P_0c07f660;
case 0x0c07f662u: goto P_0c07f662;
case 0x0c07f664u: goto P_0c07f664;
case 0x0c07f666u: goto P_0c07f666;
case 0x0c07f668u: goto P_0c07f668;
case 0x0c07f66au: goto P_0c07f66a;
case 0x0c07f66cu: goto P_0c07f66c;
case 0x0c07f66eu: goto P_0c07f66e;
case 0x0c07f670u: goto P_0c07f670;
case 0x0c07f672u: goto P_0c07f672;
case 0x0c07f674u: goto P_0c07f674;
case 0x0c07f676u: goto P_0c07f676;
case 0x0c07f678u: goto P_0c07f678;
case 0x0c07f67au: goto P_0c07f67a;
case 0x0c07f67cu: goto P_0c07f67c;
case 0x0c07f67eu: goto P_0c07f67e;
case 0x0c07f680u: goto P_0c07f680;
case 0x0c07f682u: goto P_0c07f682;
case 0x0c07f684u: goto P_0c07f684;
case 0x0c07f686u: goto P_0c07f686;
case 0x0c07f688u: goto P_0c07f688;
case 0x0c07f68au: goto P_0c07f68a;
case 0x0c07f68cu: goto P_0c07f68c;
case 0x0c07f68eu: goto P_0c07f68e;
case 0x0c07f690u: goto P_0c07f690;
case 0x0c07f692u: goto P_0c07f692;
case 0x0c07f694u: goto P_0c07f694;
case 0x0c07f696u: goto P_0c07f696;
case 0x0c07f698u: goto P_0c07f698;
case 0x0c07f69au: goto P_0c07f69a;
case 0x0c07f69cu: goto P_0c07f69c;
case 0x0c07f69eu: goto P_0c07f69e;
case 0x0c07f6a0u: goto P_0c07f6a0;
case 0x0c07f6a2u: goto P_0c07f6a2;
case 0x0c07f6a4u: goto P_0c07f6a4;
case 0x0c07f6a6u: goto P_0c07f6a6;
case 0x0c07f6a8u: goto P_0c07f6a8;
case 0x0c07f6aau: goto P_0c07f6aa;
case 0x0c07f6acu: goto P_0c07f6ac;
case 0x0c07f6aeu: goto P_0c07f6ae;
case 0x0c07f6b0u: goto P_0c07f6b0;
case 0x0c07f6b2u: goto P_0c07f6b2;
case 0x0c07f6b4u: goto P_0c07f6b4;
case 0x0c07f6b6u: goto P_0c07f6b6;
case 0x0c07f6b8u: goto P_0c07f6b8;
case 0x0c07f6bau: goto P_0c07f6ba;
case 0x0c07f6bcu: goto P_0c07f6bc;
case 0x0c07f6beu: goto P_0c07f6be;
case 0x0c07f6c0u: goto P_0c07f6c0;
case 0x0c07f6c2u: goto P_0c07f6c2;
case 0x0c07f6c4u: goto P_0c07f6c4;
case 0x0c07f6c6u: goto P_0c07f6c6;
case 0x0c07f6c8u: goto P_0c07f6c8;
case 0x0c07f6cau: goto P_0c07f6ca;
case 0x0c07f6ccu: goto P_0c07f6cc;
case 0x0c07f6ceu: goto P_0c07f6ce;
case 0x0c07f6d0u: goto P_0c07f6d0;
case 0x0c07f6d2u: goto P_0c07f6d2;
case 0x0c07f6d4u: goto P_0c07f6d4;
case 0x0c07f6d6u: goto P_0c07f6d6;
case 0x0c07f6d8u: goto P_0c07f6d8;
case 0x0c07f6dau: goto P_0c07f6da;
case 0x0c07f6dcu: goto P_0c07f6dc;
case 0x0c07f6deu: goto P_0c07f6de;
case 0x0c07f6e0u: goto P_0c07f6e0;
case 0x0c07f6e2u: goto P_0c07f6e2;
case 0x0c07f6e4u: goto P_0c07f6e4;
case 0x0c07f6e6u: goto P_0c07f6e6;
case 0x0c07f6e8u: goto P_0c07f6e8;
case 0x0c07f6eau: goto P_0c07f6ea;
case 0x0c07f6ecu: goto P_0c07f6ec;
case 0x0c07f6eeu: goto P_0c07f6ee;
case 0x0c07f6f0u: goto P_0c07f6f0;
case 0x0c07f6f2u: goto P_0c07f6f2;
case 0x0c07f6f4u: goto P_0c07f6f4;
case 0x0c080920u: goto P_0c080920;
case 0x0c080922u: goto P_0c080922;
case 0x0c080924u: goto P_0c080924;
case 0x0c080926u: goto P_0c080926;
case 0x0c080928u: goto P_0c080928;
case 0x0c08092au: goto P_0c08092a;
case 0x0c08092cu: goto P_0c08092c;
case 0x0c08092eu: goto P_0c08092e;
case 0x0c080930u: goto P_0c080930;
case 0x0c080932u: goto P_0c080932;
case 0x0c080934u: goto P_0c080934;
case 0x0c080936u: goto P_0c080936;
case 0x0c080938u: goto P_0c080938;
case 0x0c08093au: goto P_0c08093a;
case 0x0c08093cu: goto P_0c08093c;
case 0x0c08093eu: goto P_0c08093e;
case 0x0c080940u: goto P_0c080940;
case 0x0c080942u: goto P_0c080942;
case 0x0c080944u: goto P_0c080944;
case 0x0c080946u: goto P_0c080946;
case 0x0c080948u: goto P_0c080948;
case 0x0c08094au: goto P_0c08094a;
case 0x0c08094cu: goto P_0c08094c;
case 0x0c08094eu: goto P_0c08094e;
case 0x0c080950u: goto P_0c080950;
case 0x0c080952u: goto P_0c080952;
case 0x0c080954u: goto P_0c080954;
case 0x0c080956u: goto P_0c080956;
case 0x0c080958u: goto P_0c080958;
case 0x0c08095au: goto P_0c08095a;
case 0x0c08095cu: goto P_0c08095c;
case 0x0c08095eu: goto P_0c08095e;
case 0x0c080960u: goto P_0c080960;
case 0x0c080962u: goto P_0c080962;
case 0x0c080964u: goto P_0c080964;
case 0x0c080966u: goto P_0c080966;
case 0x0c080968u: goto P_0c080968;
case 0x0c08096au: goto P_0c08096a;
case 0x0c08096cu: goto P_0c08096c;
case 0x0c08096eu: goto P_0c08096e;
case 0x0c080970u: goto P_0c080970;
case 0x0c080972u: goto P_0c080972;
case 0x0c080974u: goto P_0c080974;
case 0x0c080976u: goto P_0c080976;
case 0x0c080978u: goto P_0c080978;
case 0x0c08097au: goto P_0c08097a;
case 0x0c08097cu: goto P_0c08097c;
case 0x0c08097eu: goto P_0c08097e;
case 0x0c080980u: goto P_0c080980;
case 0x0c080982u: goto P_0c080982;
case 0x0c080984u: goto P_0c080984;
case 0x0c080986u: goto P_0c080986;
case 0x0c080988u: goto P_0c080988;
case 0x0c08098au: goto P_0c08098a;
case 0x0c08098cu: goto P_0c08098c;
case 0x0c08098eu: goto P_0c08098e;
case 0x0c080990u: goto P_0c080990;
case 0x0c080992u: goto P_0c080992;
case 0x0c080994u: goto P_0c080994;
case 0x0c080996u: goto P_0c080996;
case 0x0c080998u: goto P_0c080998;
case 0x0c08099au: goto P_0c08099a;
case 0x0c08099cu: goto P_0c08099c;
case 0x0c08099eu: goto P_0c08099e;
case 0x0c0809a0u: goto P_0c0809a0;
case 0x0c0809a2u: goto P_0c0809a2;
case 0x0c0809a4u: goto P_0c0809a4;
case 0x0c0809a6u: goto P_0c0809a6;
case 0x0c0809a8u: goto P_0c0809a8;
case 0x0c0809aau: goto P_0c0809aa;
case 0x0c0809acu: goto P_0c0809ac;
case 0x0c0809aeu: goto P_0c0809ae;
case 0x0c0809b0u: goto P_0c0809b0;
case 0x0c0809b2u: goto P_0c0809b2;
case 0x0c0809b4u: goto P_0c0809b4;
case 0x0c0809b6u: goto P_0c0809b6;
case 0x0c0809b8u: goto P_0c0809b8;
case 0x0c0809bau: goto P_0c0809ba;
case 0x0c0809bcu: goto P_0c0809bc;
case 0x0c0809beu: goto P_0c0809be;
case 0x0c0809c0u: goto P_0c0809c0;
case 0x0c0809c2u: goto P_0c0809c2;
case 0x0c0809c4u: goto P_0c0809c4;
case 0x0c0809c6u: goto P_0c0809c6;
case 0x0c0809c8u: goto P_0c0809c8;
case 0x0c0809cau: goto P_0c0809ca;
case 0x0c0809ccu: goto P_0c0809cc;
case 0x0c0809ceu: goto P_0c0809ce;
case 0x0c0809d0u: goto P_0c0809d0;
case 0x0c0809d2u: goto P_0c0809d2;
case 0x0c0809d4u: goto P_0c0809d4;
case 0x0c0809d6u: goto P_0c0809d6;
case 0x0c0809d8u: goto P_0c0809d8;
case 0x0c0809dau: goto P_0c0809da;
case 0x0c0809dcu: goto P_0c0809dc;
case 0x0c0809deu: goto P_0c0809de;
case 0x0c0809e0u: goto P_0c0809e0;
case 0x0c0809e2u: goto P_0c0809e2;
case 0x0c0809e4u: goto P_0c0809e4;
case 0x0c0809e6u: goto P_0c0809e6;
case 0x0c0809e8u: goto P_0c0809e8;
case 0x0c0809eau: goto P_0c0809ea;
case 0x0c0809ecu: goto P_0c0809ec;
case 0x0c0809eeu: goto P_0c0809ee;
case 0x0c0809f0u: goto P_0c0809f0;
case 0x0c0809f2u: goto P_0c0809f2;
case 0x0c0809f4u: goto P_0c0809f4;
case 0x0c0809f6u: goto P_0c0809f6;
case 0x0c0809f8u: goto P_0c0809f8;
case 0x0c0809fau: goto P_0c0809fa;
case 0x0c0809fcu: goto P_0c0809fc;
case 0x0c0809feu: goto P_0c0809fe;
case 0x0c080a00u: goto P_0c080a00;
case 0x0c080a02u: goto P_0c080a02;
case 0x0c080a04u: goto P_0c080a04;
case 0x0c080a06u: goto P_0c080a06;
case 0x0c080a08u: goto P_0c080a08;
case 0x0c080a0au: goto P_0c080a0a;
case 0x0c080a0cu: goto P_0c080a0c;
case 0x0c080a0eu: goto P_0c080a0e;
case 0x0c080a10u: goto P_0c080a10;
case 0x0c080a12u: goto P_0c080a12;
case 0x0c080a14u: goto P_0c080a14;
case 0x0c080a16u: goto P_0c080a16;
case 0x0c080a18u: goto P_0c080a18;
case 0x0c080a1au: goto P_0c080a1a;
case 0x0c080a1cu: goto P_0c080a1c;
case 0x0c080a1eu: goto P_0c080a1e;
case 0x0c080a20u: goto P_0c080a20;
case 0x0c080a22u: goto P_0c080a22;
case 0x0c080a24u: goto P_0c080a24;
case 0x0c080a26u: goto P_0c080a26;
case 0x0c080a28u: goto P_0c080a28;
case 0x0c080a2au: goto P_0c080a2a;
case 0x0c080a2cu: goto P_0c080a2c;
case 0x0c080a2eu: goto P_0c080a2e;
case 0x0c080a30u: goto P_0c080a30;
case 0x0c080a32u: goto P_0c080a32;
case 0x0c080a34u: goto P_0c080a34;
case 0x0c080a36u: goto P_0c080a36;
case 0x0c080a38u: goto P_0c080a38;
case 0x0c080a3au: goto P_0c080a3a;
case 0x0c080a3cu: goto P_0c080a3c;
case 0x0c080a3eu: goto P_0c080a3e;
case 0x0c080a40u: goto P_0c080a40;
case 0x0c080a42u: goto P_0c080a42;
case 0x0c080a44u: goto P_0c080a44;
case 0x0c080a46u: goto P_0c080a46;
case 0x0c080a48u: goto P_0c080a48;
case 0x0c080a4au: goto P_0c080a4a;
case 0x0c080a4cu: goto P_0c080a4c;
case 0x0c080a4eu: goto P_0c080a4e;
case 0x0c080a50u: goto P_0c080a50;
case 0x0c080a52u: goto P_0c080a52;
case 0x0c080a54u: goto P_0c080a54;
case 0x0c080a74u: goto P_0c080a74;
case 0x0c080a76u: goto P_0c080a76;
case 0x0c080a78u: goto P_0c080a78;
case 0x0c080a7au: goto P_0c080a7a;
case 0x0c080a7cu: goto P_0c080a7c;
case 0x0c080a7eu: goto P_0c080a7e;
case 0x0c080a80u: goto P_0c080a80;
case 0x0c080a82u: goto P_0c080a82;
case 0x0c080a84u: goto P_0c080a84;
case 0x0c080a86u: goto P_0c080a86;
case 0x0c080a88u: goto P_0c080a88;
case 0x0c080a8au: goto P_0c080a8a;
case 0x0c080a8cu: goto P_0c080a8c;
case 0x0c080a8eu: goto P_0c080a8e;
case 0x0c080a90u: goto P_0c080a90;
case 0x0c080a92u: goto P_0c080a92;
case 0x0c080a94u: goto P_0c080a94;
case 0x0c080a96u: goto P_0c080a96;
case 0x0c080a98u: goto P_0c080a98;
case 0x0c080a9au: goto P_0c080a9a;
case 0x0c080a9cu: goto P_0c080a9c;
case 0x0c080a9eu: goto P_0c080a9e;
case 0x0c080aa0u: goto P_0c080aa0;
case 0x0c080aa2u: goto P_0c080aa2;
case 0x0c080aa4u: goto P_0c080aa4;
case 0x0c080aa6u: goto P_0c080aa6;
case 0x0c080aa8u: goto P_0c080aa8;
case 0x0c080aaau: goto P_0c080aaa;
case 0x0c080aacu: goto P_0c080aac;
case 0x0c080aaeu: goto P_0c080aae;
case 0x0c080ab0u: goto P_0c080ab0;
case 0x0c080ab2u: goto P_0c080ab2;
case 0x0c080ab4u: goto P_0c080ab4;
case 0x0c080ab6u: goto P_0c080ab6;
case 0x0c080ab8u: goto P_0c080ab8;
case 0x0c080abau: goto P_0c080aba;
case 0x0c080abcu: goto P_0c080abc;
case 0x0c080abeu: goto P_0c080abe;
case 0x0c080ac0u: goto P_0c080ac0;
case 0x0c080ac2u: goto P_0c080ac2;
case 0x0c080ac4u: goto P_0c080ac4;
case 0x0c080ac6u: goto P_0c080ac6;
case 0x0c080ac8u: goto P_0c080ac8;
case 0x0c080acau: goto P_0c080aca;
case 0x0c080accu: goto P_0c080acc;
case 0x0c080aceu: goto P_0c080ace;
case 0x0c080ad0u: goto P_0c080ad0;
case 0x0c080ad2u: goto P_0c080ad2;
case 0x0c080ad4u: goto P_0c080ad4;
case 0x0c080ad6u: goto P_0c080ad6;
case 0x0c080ad8u: goto P_0c080ad8;
case 0x0c080adau: goto P_0c080ada;
case 0x0c080adcu: goto P_0c080adc;
case 0x0c080adeu: goto P_0c080ade;
case 0x0c080ae0u: goto P_0c080ae0;
case 0x0c080ae2u: goto P_0c080ae2;
case 0x0c080ae4u: goto P_0c080ae4;
case 0x0c080ae6u: goto P_0c080ae6;
case 0x0c080ae8u: goto P_0c080ae8;
case 0x0c080aeau: goto P_0c080aea;
case 0x0c080aecu: goto P_0c080aec;
case 0x0c080aeeu: goto P_0c080aee;
case 0x0c080af0u: goto P_0c080af0;
case 0x0c080af2u: goto P_0c080af2;
case 0x0c080af4u: goto P_0c080af4;
case 0x0c080af6u: goto P_0c080af6;
case 0x0c080af8u: goto P_0c080af8;
case 0x0c080afau: goto P_0c080afa;
case 0x0c080afcu: goto P_0c080afc;
case 0x0c080afeu: goto P_0c080afe;
case 0x0c080b00u: goto P_0c080b00;
case 0x0c080b02u: goto P_0c080b02;
case 0x0c080b04u: goto P_0c080b04;
case 0x0c080b06u: goto P_0c080b06;
case 0x0c080b08u: goto P_0c080b08;
case 0x0c080b0au: goto P_0c080b0a;
case 0x0c080b0cu: goto P_0c080b0c;
case 0x0c080b0eu: goto P_0c080b0e;
case 0x0c080b10u: goto P_0c080b10;
case 0x0c080b12u: goto P_0c080b12;
case 0x0c080b14u: goto P_0c080b14;
case 0x0c080b16u: goto P_0c080b16;
case 0x0c080b18u: goto P_0c080b18;
case 0x0c080b1au: goto P_0c080b1a;
case 0x0c080b1cu: goto P_0c080b1c;
case 0x0c080b1eu: goto P_0c080b1e;
case 0x0c080b20u: goto P_0c080b20;
case 0x0c080b22u: goto P_0c080b22;
case 0x0c080b24u: goto P_0c080b24;
case 0x0c080b26u: goto P_0c080b26;
case 0x0c080b28u: goto P_0c080b28;
case 0x0c080b2au: goto P_0c080b2a;
case 0x0c080b2cu: goto P_0c080b2c;
case 0x0c080b2eu: goto P_0c080b2e;
case 0x0c080b30u: goto P_0c080b30;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07eb9e: /* original 2fe6, guest PC 0x0c07eb9e */
if(!s->budget--) { s->failed_pc=0x0c07eb9eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07eba0;
P_0c07eba0: /* original e500, guest PC 0x0c07eba0 */
if(!s->budget--) { s->failed_pc=0x0c07eba0u; return 0; }
r[5]=0x00000000u;
goto P_0c07eba2;
P_0c07eba2: /* original 2fd6, guest PC 0x0c07eba2 */
if(!s->budget--) { s->failed_pc=0x0c07eba2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07eba4;
P_0c07eba4: /* original 2fc6, guest PC 0x0c07eba4 */
if(!s->budget--) { s->failed_pc=0x0c07eba4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07eba6;
P_0c07eba6: /* original 6c43, guest PC 0x0c07eba6 */
if(!s->budget--) { s->failed_pc=0x0c07eba6u; return 0; }
r[12]=r[4];
goto P_0c07eba8;
P_0c07eba8: /* original 4f22, guest PC 0x0c07eba8 */
if(!s->budget--) { s->failed_pc=0x0c07eba8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ebaa;
P_0c07ebaa: /* original 7ffc, guest PC 0x0c07ebaa */
if(!s->budget--) { s->failed_pc=0x0c07ebaau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07ebac;
P_0c07ebac: /* original 2f42, guest PC 0x0c07ebac */
if(!s->budget--) { s->failed_pc=0x0c07ebacu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07ebae;
P_0c07ebae: /* original d31a, guest PC 0x0c07ebae */
if(!s->budget--) { s->failed_pc=0x0c07ebaeu; return 0; }
r[3]=read(ram,0x0c07ec18u,4);
goto P_0c07ebb0;
P_0c07ebb0: /* original de17, guest PC 0x0c07ebb0 */
if(!s->budget--) { s->failed_pc=0x0c07ebb0u; return 0; }
r[14]=read(ram,0x0c07ec10u,4);
goto P_0c07ebb2;
P_0c07ebb2: /* original 6230, guest PC 0x0c07ebb2 */
if(!s->budget--) { s->failed_pc=0x0c07ebb2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c07ebb4;
P_0c07ebb4: /* original 7201, guest PC 0x0c07ebb4 */
if(!s->budget--) { s->failed_pc=0x0c07ebb4u; return 0; }
r[2]+=0x00000001u;
goto P_0c07ebb6;
P_0c07ebb6: /* original 2320, guest PC 0x0c07ebb6 */
if(!s->budget--) { s->failed_pc=0x0c07ebb6u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c07ebb8;
P_0c07ebb8: /* original d31f, guest PC 0x0c07ebb8 */
if(!s->budget--) { s->failed_pc=0x0c07ebb8u; return 0; }
r[3]=read(ram,0x0c07ec38u,4);
goto P_0c07ebba;
P_0c07ebba: /* original 1c34, guest PC 0x0c07ebba */
if(!s->budget--) { s->failed_pc=0x0c07ebbau; return 0; }
write(ram,r[12]+16,r[3],4);
goto P_0c07ebbc;
P_0c07ebbc: /* original d21f, guest PC 0x0c07ebbc */
if(!s->budget--) { s->failed_pc=0x0c07ebbcu; return 0; }
r[2]=read(ram,0x0c07ec3cu,4);
goto P_0c07ebbe;
P_0c07ebbe: /* original 420b, guest PC 0x0c07ebbe */
if(!s->budget--) { s->failed_pc=0x0c07ebbeu; return 0; }
target=r[2];
r[16]=code_base|0x0c07ebc2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ebc2u) { target=s->pc; goto dispatch; }
goto P_0c07ebc2;
P_0c07ebc0: /* original 64e3, guest PC 0x0c07ebc0 */
if(!s->budget--) { s->failed_pc=0x0c07ebc0u; return 0; }
r[4]=r[14];
goto P_0c07ebc2;
P_0c07ebc2: /* original e320, guest PC 0x0c07ebc2 */
if(!s->budget--) { s->failed_pc=0x0c07ebc2u; return 0; }
r[3]=0x00000020u;
goto P_0c07ebc4;
P_0c07ebc4: /* original 9520, guest PC 0x0c07ebc4 */
if(!s->budget--) { s->failed_pc=0x0c07ebc4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ec08u,2);
goto P_0c07ebc6;
P_0c07ebc6: /* original e618, guest PC 0x0c07ebc6 */
if(!s->budget--) { s->failed_pc=0x0c07ebc6u; return 0; }
r[6]=0x00000018u;
goto P_0c07ebc8;
P_0c07ebc8: /* original 2f36, guest PC 0x0c07ebc8 */
if(!s->budget--) { s->failed_pc=0x0c07ebc8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ebca;
P_0c07ebca: /* original d216, guest PC 0x0c07ebca */
if(!s->budget--) { s->failed_pc=0x0c07ebcau; return 0; }
r[2]=read(ram,0x0c07ec24u,4);
goto P_0c07ebcc;
P_0c07ebcc: /* original e701, guest PC 0x0c07ebcc */
if(!s->budget--) { s->failed_pc=0x0c07ebccu; return 0; }
r[7]=0x00000001u;
goto P_0c07ebce;
P_0c07ebce: /* original 420b, guest PC 0x0c07ebce */
if(!s->budget--) { s->failed_pc=0x0c07ebceu; return 0; }
target=r[2];
r[16]=code_base|0x0c07ebd2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ebd2u) { target=s->pc; goto dispatch; }
goto P_0c07ebd2;
P_0c07ebd0: /* original 64e3, guest PC 0x0c07ebd0 */
if(!s->budget--) { s->failed_pc=0x0c07ebd0u; return 0; }
r[4]=r[14];
goto P_0c07ebd2;
P_0c07ebd2: /* original 9d1a, guest PC 0x0c07ebd2 */
if(!s->budget--) { s->failed_pc=0x0c07ebd2u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ec0au,2);
goto P_0c07ebd4;
P_0c07ebd4: /* original e320, guest PC 0x0c07ebd4 */
if(!s->budget--) { s->failed_pc=0x0c07ebd4u; return 0; }
r[3]=0x00000020u;
goto P_0c07ebd6;
P_0c07ebd6: /* original e618, guest PC 0x0c07ebd6 */
if(!s->budget--) { s->failed_pc=0x0c07ebd6u; return 0; }
r[6]=0x00000018u;
goto P_0c07ebd8;
P_0c07ebd8: /* original 2f36, guest PC 0x0c07ebd8 */
if(!s->budget--) { s->failed_pc=0x0c07ebd8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ebda;
P_0c07ebda: /* original d212, guest PC 0x0c07ebda */
if(!s->budget--) { s->failed_pc=0x0c07ebdau; return 0; }
r[2]=read(ram,0x0c07ec24u,4);
goto P_0c07ebdc;
P_0c07ebdc: /* original 65d3, guest PC 0x0c07ebdc */
if(!s->budget--) { s->failed_pc=0x0c07ebdcu; return 0; }
r[5]=r[13];
goto P_0c07ebde;
P_0c07ebde: /* original e701, guest PC 0x0c07ebde */
if(!s->budget--) { s->failed_pc=0x0c07ebdeu; return 0; }
r[7]=0x00000001u;
goto P_0c07ebe0;
P_0c07ebe0: /* original 420b, guest PC 0x0c07ebe0 */
if(!s->budget--) { s->failed_pc=0x0c07ebe0u; return 0; }
target=r[2];
r[16]=code_base|0x0c07ebe4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ebe4u) { target=s->pc; goto dispatch; }
goto P_0c07ebe4;
P_0c07ebe2: /* original 64e3, guest PC 0x0c07ebe2 */
if(!s->budget--) { s->failed_pc=0x0c07ebe2u; return 0; }
r[4]=r[14];
goto P_0c07ebe4;
P_0c07ebe4: /* original d315, guest PC 0x0c07ebe4 */
if(!s->budget--) { s->failed_pc=0x0c07ebe4u; return 0; }
r[3]=read(ram,0x0c07ec3cu,4);
goto P_0c07ebe6;
P_0c07ebe6: /* original 9511, guest PC 0x0c07ebe6 */
if(!s->budget--) { s->failed_pc=0x0c07ebe6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ec0cu,2);
goto P_0c07ebe8;
P_0c07ebe8: /* original 430b, guest PC 0x0c07ebe8 */
if(!s->budget--) { s->failed_pc=0x0c07ebe8u; return 0; }
target=r[3];
r[16]=code_base|0x0c07ebecu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ebecu) { target=s->pc; goto dispatch; }
goto P_0c07ebec;
P_0c07ebea: /* original 64e3, guest PC 0x0c07ebea */
if(!s->budget--) { s->failed_pc=0x0c07ebeau; return 0; }
r[4]=r[14];
goto P_0c07ebec;
P_0c07ebec: /* original 900f, guest PC 0x0c07ebec */
if(!s->budget--) { s->failed_pc=0x0c07ebecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ec0eu,2);
goto P_0c07ebee;
P_0c07ebee: /* original e202, guest PC 0x0c07ebee */
if(!s->budget--) { s->failed_pc=0x0c07ebeeu; return 0; }
r[2]=0x00000002u;
goto P_0c07ebf0;
P_0c07ebf0: /* original 65d3, guest PC 0x0c07ebf0 */
if(!s->budget--) { s->failed_pc=0x0c07ebf0u; return 0; }
r[5]=r[13];
goto P_0c07ebf2;
P_0c07ebf2: /* original 0c26, guest PC 0x0c07ebf2 */
if(!s->budget--) { s->failed_pc=0x0c07ebf2u; return 0; }
write(ram,r[12]+r[0],r[2],4);
goto P_0c07ebf4;
P_0c07ebf4: /* original 54f2, guest PC 0x0c07ebf4 */
if(!s->budget--) { s->failed_pc=0x0c07ebf4u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07ebf6;
P_0c07ebf6: /* original 7f0c, guest PC 0x0c07ebf6 */
if(!s->budget--) { s->failed_pc=0x0c07ebf6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07ebf8;
P_0c07ebf8: /* original 4f26, guest PC 0x0c07ebf8 */
if(!s->budget--) { s->failed_pc=0x0c07ebf8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ebfa;
P_0c07ebfa: /* original 6cf6, guest PC 0x0c07ebfa */
if(!s->budget--) { s->failed_pc=0x0c07ebfau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07ebfc;
P_0c07ebfc: /* original 6df6, guest PC 0x0c07ebfc */
if(!s->budget--) { s->failed_pc=0x0c07ebfcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07ebfe;
P_0c07ebfe: /* original a01f, guest PC 0x0c07ebfe */
if(!s->budget--) { s->failed_pc=0x0c07ebfeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07ec40;
P_0c07ec00: /* original 6ef6, guest PC 0x0c07ec00 */
if(!s->budget--) { s->failed_pc=0x0c07ec00u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07ec02u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07ec02u; return 0; } return 1;
P_0c07ec40: /* original 2fe6, guest PC 0x0c07ec40 */
if(!s->budget--) { s->failed_pc=0x0c07ec40u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ec42;
P_0c07ec42: /* original 6e43, guest PC 0x0c07ec42 */
if(!s->budget--) { s->failed_pc=0x0c07ec42u; return 0; }
r[14]=r[4];
goto P_0c07ec44;
P_0c07ec44: /* original 2fd6, guest PC 0x0c07ec44 */
if(!s->budget--) { s->failed_pc=0x0c07ec44u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ec46;
P_0c07ec46: /* original 66e3, guest PC 0x0c07ec46 */
if(!s->budget--) { s->failed_pc=0x0c07ec46u; return 0; }
r[6]=r[14];
goto P_0c07ec48;
P_0c07ec48: /* original 2fc6, guest PC 0x0c07ec48 */
if(!s->budget--) { s->failed_pc=0x0c07ec48u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ec4a;
P_0c07ec4a: /* original 4f22, guest PC 0x0c07ec4a */
if(!s->budget--) { s->failed_pc=0x0c07ec4au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ec4c;
P_0c07ec4c: /* original d33b, guest PC 0x0c07ec4c */
if(!s->budget--) { s->failed_pc=0x0c07ec4cu; return 0; }
r[3]=read(ram,0x0c07ed3cu,4);
goto P_0c07ec4e;
P_0c07ec4e: /* original 7ff4, guest PC 0x0c07ec4e */
if(!s->budget--) { s->failed_pc=0x0c07ec4eu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c07ec50;
P_0c07ec50: /* original 1f32, guest PC 0x0c07ec50 */
if(!s->budget--) { s->failed_pc=0x0c07ec50u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07ec52;
P_0c07ec52: /* original d53b, guest PC 0x0c07ec52 */
if(!s->budget--) { s->failed_pc=0x0c07ec52u; return 0; }
r[5]=read(ram,0x0c07ed40u,4);
goto P_0c07ec54;
P_0c07ec54: /* original 6453, guest PC 0x0c07ec54 */
if(!s->budget--) { s->failed_pc=0x0c07ec54u; return 0; }
r[4]=r[5];
goto P_0c07ec56;
P_0c07ec56: /* original 1f51, guest PC 0x0c07ec56 */
if(!s->budget--) { s->failed_pc=0x0c07ec56u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c07ec58;
P_0c07ec58: /* original 9363, guest PC 0x0c07ec58 */
if(!s->budget--) { s->failed_pc=0x0c07ec58u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed22u,2);
goto P_0c07ec5a;
P_0c07ec5a: /* original 7458, guest PC 0x0c07ec5a */
if(!s->budget--) { s->failed_pc=0x0c07ec5au; return 0; }
r[4]+=0x00000058u;
goto P_0c07ec5c;
P_0c07ec5c: /* original 335c, guest PC 0x0c07ec5c */
if(!s->budget--) { s->failed_pc=0x0c07ec5cu; return 0; }
r[3]+=r[5];
goto P_0c07ec5e;
P_0c07ec5e: /* original 2f32, guest PC 0x0c07ec5e */
if(!s->budget--) { s->failed_pc=0x0c07ec5eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07ec60;
P_0c07ec60: /* original 9060, guest PC 0x0c07ec60 */
if(!s->budget--) { s->failed_pc=0x0c07ec60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed24u,2);
goto P_0c07ec62;
P_0c07ec62: /* original 006e, guest PC 0x0c07ec62 */
if(!s->budget--) { s->failed_pc=0x0c07ec62u; return 0; }
r[0]=read(ram,r[6]+r[0],4);
goto P_0c07ec64;
P_0c07ec64: /* original 8801, guest PC 0x0c07ec64 */
if(!s->budget--) { s->failed_pc=0x0c07ec64u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07ec66;
P_0c07ec66: /* original 8f08, guest PC 0x0c07ec66 */
if(!s->budget--) { s->failed_pc=0x0c07ec66u; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(!cond) { goto P_0c07ec7a; }
goto P_0c07ec6a;
P_0c07ec68: /* original 6503, guest PC 0x0c07ec68 */
if(!s->budget--) { s->failed_pc=0x0c07ec68u; return 0; }
r[5]=r[0];
goto P_0c07ec6a;
P_0c07ec6a: /* original d236, guest PC 0x0c07ec6a */
if(!s->budget--) { s->failed_pc=0x0c07ec6au; return 0; }
r[2]=read(ram,0x0c07ed44u,4);
goto P_0c07ec6c;
P_0c07ec6c: /* original 420b, guest PC 0x0c07ec6c */
if(!s->budget--) { s->failed_pc=0x0c07ec6cu; return 0; }
target=r[2];
r[16]=code_base|0x0c07ec70u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ec70u) { target=s->pc; goto dispatch; }
goto P_0c07ec70;
P_0c07ec6e: /* original 0009, guest PC 0x0c07ec6e */
if(!s->budget--) { s->failed_pc=0x0c07ec6eu; return 0; }
goto P_0c07ec70;
P_0c07ec70: /* original d335, guest PC 0x0c07ec70 */
if(!s->budget--) { s->failed_pc=0x0c07ec70u; return 0; }
r[3]=read(ram,0x0c07ed48u,4);
goto P_0c07ec72;
P_0c07ec72: /* original 9458, guest PC 0x0c07ec72 */
if(!s->budget--) { s->failed_pc=0x0c07ec72u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed26u,2);
goto P_0c07ec74;
P_0c07ec74: /* original 66f2, guest PC 0x0c07ec74 */
if(!s->budget--) { s->failed_pc=0x0c07ec74u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c07ec76;
P_0c07ec76: /* original 430b, guest PC 0x0c07ec76 */
if(!s->budget--) { s->failed_pc=0x0c07ec76u; return 0; }
target=r[3];
r[16]=code_base|0x0c07ec7au;
r[5]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ec7au) { target=s->pc; goto dispatch; }
goto P_0c07ec7a;
P_0c07ec78: /* original 55f1, guest PC 0x0c07ec78 */
if(!s->budget--) { s->failed_pc=0x0c07ec78u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c07ec7a;
P_0c07ec7a: /* original dd34, guest PC 0x0c07ec7a */
if(!s->budget--) { s->failed_pc=0x0c07ec7au; return 0; }
r[13]=read(ram,0x0c07ed4cu,4);
goto P_0c07ec7c;
P_0c07ec7c: /* original d234, guest PC 0x0c07ec7c */
if(!s->budget--) { s->failed_pc=0x0c07ec7cu; return 0; }
r[2]=read(ram,0x0c07ed50u,4);
goto P_0c07ec7e;
P_0c07ec7e: /* original 54d2, guest PC 0x0c07ec7e */
if(!s->budget--) { s->failed_pc=0x0c07ec7eu; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c07ec80;
P_0c07ec80: /* original 2428, guest PC 0x0c07ec80 */
if(!s->budget--) { s->failed_pc=0x0c07ec80u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c07ec82;
P_0c07ec82: /* original 8906, guest PC 0x0c07ec82 */
if(!s->budget--) { s->failed_pc=0x0c07ec82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ec92; }
goto P_0c07ec84;
P_0c07ec84: /* original 7f0c, guest PC 0x0c07ec84 */
if(!s->budget--) { s->failed_pc=0x0c07ec84u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07ec86;
P_0c07ec86: /* original 64e3, guest PC 0x0c07ec86 */
if(!s->budget--) { s->failed_pc=0x0c07ec86u; return 0; }
r[4]=r[14];
goto P_0c07ec88;
P_0c07ec88: /* original 4f26, guest PC 0x0c07ec88 */
if(!s->budget--) { s->failed_pc=0x0c07ec88u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ec8a;
P_0c07ec8a: /* original 6cf6, guest PC 0x0c07ec8a */
if(!s->budget--) { s->failed_pc=0x0c07ec8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07ec8c;
P_0c07ec8c: /* original 6df6, guest PC 0x0c07ec8c */
if(!s->budget--) { s->failed_pc=0x0c07ec8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07ec8e;
P_0c07ec8e: /* original a033, guest PC 0x0c07ec8e */
if(!s->budget--) { s->failed_pc=0x0c07ec8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07ecf8;
P_0c07ec90: /* original 6ef6, guest PC 0x0c07ec90 */
if(!s->budget--) { s->failed_pc=0x0c07ec90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07ec92;
P_0c07ec92: /* original d330, guest PC 0x0c07ec92 */
if(!s->budget--) { s->failed_pc=0x0c07ec92u; return 0; }
r[3]=read(ram,0x0c07ed54u,4);
goto P_0c07ec94;
P_0c07ec94: /* original 54f2, guest PC 0x0c07ec94 */
if(!s->budget--) { s->failed_pc=0x0c07ec94u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07ec96;
P_0c07ec96: /* original 430b, guest PC 0x0c07ec96 */
if(!s->budget--) { s->failed_pc=0x0c07ec96u; return 0; }
target=r[3];
r[16]=code_base|0x0c07ec9au;
r[4]+=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ec9au) { target=s->pc; goto dispatch; }
goto P_0c07ec9a;
P_0c07ec98: /* original 7412, guest PC 0x0c07ec98 */
if(!s->budget--) { s->failed_pc=0x0c07ec98u; return 0; }
r[4]+=0x00000012u;
goto P_0c07ec9a;
P_0c07ec9a: /* original 6c0c, guest PC 0x0c07ec9a */
if(!s->budget--) { s->failed_pc=0x0c07ec9au; return 0; }
r[12]=r[0]&255u;
goto P_0c07ec9c;
P_0c07ec9c: /* original e018, guest PC 0x0c07ec9c */
if(!s->budget--) { s->failed_pc=0x0c07ec9cu; return 0; }
r[0]=0x00000018u;
goto P_0c07ec9e;
P_0c07ec9e: /* original 05dc, guest PC 0x0c07ec9e */
if(!s->budget--) { s->failed_pc=0x0c07ec9eu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07eca0;
P_0c07eca0: /* original 9042, guest PC 0x0c07eca0 */
if(!s->budget--) { s->failed_pc=0x0c07eca0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed28u,2);
goto P_0c07eca2;
P_0c07eca2: /* original 04de, guest PC 0x0c07eca2 */
if(!s->budget--) { s->failed_pc=0x0c07eca2u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c07eca4;
P_0c07eca4: /* original e046, guest PC 0x0c07eca4 */
if(!s->budget--) { s->failed_pc=0x0c07eca4u; return 0; }
r[0]=0x00000046u;
goto P_0c07eca6;
P_0c07eca6: /* original 064d, guest PC 0x0c07eca6 */
if(!s->budget--) { s->failed_pc=0x0c07eca6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07eca8;
P_0c07eca8: /* original 903f, guest PC 0x0c07eca8 */
if(!s->budget--) { s->failed_pc=0x0c07eca8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed2au,2);
goto P_0c07ecaa;
P_0c07ecaa: /* original 074d, guest PC 0x0c07ecaa */
if(!s->budget--) { s->failed_pc=0x0c07ecaau; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07ecac;
P_0c07ecac: /* original 645e, guest PC 0x0c07ecac */
if(!s->budget--) { s->failed_pc=0x0c07ecacu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c07ecae;
P_0c07ecae: /* original 2448, guest PC 0x0c07ecae */
if(!s->budget--) { s->failed_pc=0x0c07ecaeu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07ecb0;
P_0c07ecb0: /* original 8b0b, guest PC 0x0c07ecb0 */
if(!s->budget--) { s->failed_pc=0x0c07ecb0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ecca; }
goto P_0c07ecb2;
P_0c07ecb2: /* original 677f, guest PC 0x0c07ecb2 */
if(!s->budget--) { s->failed_pc=0x0c07ecb2u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)r[7];
goto P_0c07ecb4;
P_0c07ecb4: /* original 666f, guest PC 0x0c07ecb4 */
if(!s->budget--) { s->failed_pc=0x0c07ecb4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c07ecb6;
P_0c07ecb6: /* original 3670, guest PC 0x0c07ecb6 */
if(!s->budget--) { s->failed_pc=0x0c07ecb6u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[7])!=0);
goto P_0c07ecb8;
P_0c07ecb8: /* original 8b03, guest PC 0x0c07ecb8 */
if(!s->budget--) { s->failed_pc=0x0c07ecb8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ecc2; }
goto P_0c07ecba;
P_0c07ecba: /* original 9737, guest PC 0x0c07ecba */
if(!s->budget--) { s->failed_pc=0x0c07ecbau; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed2cu,2);
goto P_0c07ecbc;
P_0c07ecbc: /* original e510, guest PC 0x0c07ecbc */
if(!s->budget--) { s->failed_pc=0x0c07ecbcu; return 0; }
r[5]=0x00000010u;
goto P_0c07ecbe;
P_0c07ecbe: /* original a014, guest PC 0x0c07ecbe */
if(!s->budget--) { s->failed_pc=0x0c07ecbeu; return 0; }
r[6]=0x0000001eu;
goto P_0c07ecea;
P_0c07ecc0: /* original e61e, guest PC 0x0c07ecc0 */
if(!s->budget--) { s->failed_pc=0x0c07ecc0u; return 0; }
r[6]=0x0000001eu;
goto P_0c07ecc2;
P_0c07ecc2: /* original 9734, guest PC 0x0c07ecc2 */
if(!s->budget--) { s->failed_pc=0x0c07ecc2u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed2eu,2);
goto P_0c07ecc4;
P_0c07ecc4: /* original e51a, guest PC 0x0c07ecc4 */
if(!s->budget--) { s->failed_pc=0x0c07ecc4u; return 0; }
r[5]=0x0000001au;
goto P_0c07ecc6;
P_0c07ecc6: /* original a010, guest PC 0x0c07ecc6 */
if(!s->budget--) { s->failed_pc=0x0c07ecc6u; return 0; }
r[6]=0x00000018u;
goto P_0c07ecea;
P_0c07ecc8: /* original e618, guest PC 0x0c07ecc8 */
if(!s->budget--) { s->failed_pc=0x0c07ecc8u; return 0; }
r[6]=0x00000018u;
goto P_0c07ecca;
P_0c07ecca: /* original 6043, guest PC 0x0c07ecca */
if(!s->budget--) { s->failed_pc=0x0c07eccau; return 0; }
r[0]=r[4];
goto P_0c07eccc;
P_0c07eccc: /* original 8801, guest PC 0x0c07eccc */
if(!s->budget--) { s->failed_pc=0x0c07ecccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07ecce;
P_0c07ecce: /* original 8f07, guest PC 0x0c07ecce */
if(!s->budget--) { s->failed_pc=0x0c07ecceu; return 0; }
cond=r[17]&1u;
r[6]=0x00000014u;
if(!cond) { goto P_0c07ece0; }
goto P_0c07ecd2;
P_0c07ecd0: /* original e614, guest PC 0x0c07ecd0 */
if(!s->budget--) { s->failed_pc=0x0c07ecd0u; return 0; }
r[6]=0x00000014u;
goto P_0c07ecd2;
P_0c07ecd2: /* original 972d, guest PC 0x0c07ecd2 */
if(!s->budget--) { s->failed_pc=0x0c07ecd2u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed30u,2);
goto P_0c07ecd4;
P_0c07ecd4: /* original 2cc8, guest PC 0x0c07ecd4 */
if(!s->budget--) { s->failed_pc=0x0c07ecd4u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c07ecd6;
P_0c07ecd6: /* original 8d08, guest PC 0x0c07ecd6 */
if(!s->budget--) { s->failed_pc=0x0c07ecd6u; return 0; }
cond=r[17]&1u;
r[5]=0x00000015u;
if(cond) { goto P_0c07ecea; }
goto P_0c07ecda;
P_0c07ecd8: /* original e515, guest PC 0x0c07ecd8 */
if(!s->budget--) { s->failed_pc=0x0c07ecd8u; return 0; }
r[5]=0x00000015u;
goto P_0c07ecda;
P_0c07ecda: /* original 972a, guest PC 0x0c07ecda */
if(!s->budget--) { s->failed_pc=0x0c07ecdau; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed32u,2);
goto P_0c07ecdc;
P_0c07ecdc: /* original a005, guest PC 0x0c07ecdc */
if(!s->budget--) { s->failed_pc=0x0c07ecdcu; return 0; }
r[5]=0x0000000cu;
goto P_0c07ecea;
P_0c07ecde: /* original e50c, guest PC 0x0c07ecde */
if(!s->budget--) { s->failed_pc=0x0c07ecdeu; return 0; }
r[5]=0x0000000cu;
goto P_0c07ece0;
P_0c07ece0: /* original 9728, guest PC 0x0c07ece0 */
if(!s->budget--) { s->failed_pc=0x0c07ece0u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed34u,2);
goto P_0c07ece2;
P_0c07ece2: /* original 2cc8, guest PC 0x0c07ece2 */
if(!s->budget--) { s->failed_pc=0x0c07ece2u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c07ece4;
P_0c07ece4: /* original 8d01, guest PC 0x0c07ece4 */
if(!s->budget--) { s->failed_pc=0x0c07ece4u; return 0; }
cond=r[17]&1u;
r[5]=0x00000012u;
if(cond) { goto P_0c07ecea; }
goto P_0c07ece8;
P_0c07ece6: /* original e512, guest PC 0x0c07ece6 */
if(!s->budget--) { s->failed_pc=0x0c07ece6u; return 0; }
r[5]=0x00000012u;
goto P_0c07ece8;
P_0c07ece8: /* original 9725, guest PC 0x0c07ece8 */
if(!s->budget--) { s->failed_pc=0x0c07ece8u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed36u,2);
goto P_0c07ecea;
P_0c07ecea: /* original 7f0c, guest PC 0x0c07ecea */
if(!s->budget--) { s->failed_pc=0x0c07eceau; return 0; }
r[15]+=0x0000000cu;
goto P_0c07ecec;
P_0c07ecec: /* original 64e3, guest PC 0x0c07ecec */
if(!s->budget--) { s->failed_pc=0x0c07ececu; return 0; }
r[4]=r[14];
goto P_0c07ecee;
P_0c07ecee: /* original 4f26, guest PC 0x0c07ecee */
if(!s->budget--) { s->failed_pc=0x0c07eceeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ecf0;
P_0c07ecf0: /* original 6cf6, guest PC 0x0c07ecf0 */
if(!s->budget--) { s->failed_pc=0x0c07ecf0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07ecf2;
P_0c07ecf2: /* original 6df6, guest PC 0x0c07ecf2 */
if(!s->budget--) { s->failed_pc=0x0c07ecf2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07ecf4;
P_0c07ecf4: /* original a030, guest PC 0x0c07ecf4 */
if(!s->budget--) { s->failed_pc=0x0c07ecf4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07ed58;
P_0c07ecf6: /* original 6ef6, guest PC 0x0c07ecf6 */
if(!s->budget--) { s->failed_pc=0x0c07ecf6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07ecf8;
P_0c07ecf8: /* original d514, guest PC 0x0c07ecf8 */
if(!s->budget--) { s->failed_pc=0x0c07ecf8u; return 0; }
r[5]=read(ram,0x0c07ed4cu,4);
goto P_0c07ecfa;
P_0c07ecfa: /* original e029, guest PC 0x0c07ecfa */
if(!s->budget--) { s->failed_pc=0x0c07ecfau; return 0; }
r[0]=0x00000029u;
goto P_0c07ecfc;
P_0c07ecfc: /* original 075c, guest PC 0x0c07ecfc */
if(!s->budget--) { s->failed_pc=0x0c07ecfcu; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07ecfe;
P_0c07ecfe: /* original e01d, guest PC 0x0c07ecfe */
if(!s->budget--) { s->failed_pc=0x0c07ecfeu; return 0; }
r[0]=0x0000001du;
goto P_0c07ed00;
P_0c07ed00: /* original 055c, guest PC 0x0c07ed00 */
if(!s->budget--) { s->failed_pc=0x0c07ed00u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07ed02;
P_0c07ed02: /* original 667e, guest PC 0x0c07ed02 */
if(!s->budget--) { s->failed_pc=0x0c07ed02u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[7];
goto P_0c07ed04;
P_0c07ed04: /* original 6063, guest PC 0x0c07ed04 */
if(!s->budget--) { s->failed_pc=0x0c07ed04u; return 0; }
r[0]=r[6];
goto P_0c07ed06;
P_0c07ed06: /* original 8803, guest PC 0x0c07ed06 */
if(!s->budget--) { s->failed_pc=0x0c07ed06u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c07ed08;
P_0c07ed08: /* original 8d03, guest PC 0x0c07ed08 */
if(!s->budget--) { s->failed_pc=0x0c07ed08u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000001u;
if(cond) { goto P_0c07ed12; }
goto P_0c07ed0c;
P_0c07ed0a: /* original 7501, guest PC 0x0c07ed0a */
if(!s->budget--) { s->failed_pc=0x0c07ed0au; return 0; }
r[5]+=0x00000001u;
goto P_0c07ed0c;
P_0c07ed0c: /* original 655e, guest PC 0x0c07ed0c */
if(!s->budget--) { s->failed_pc=0x0c07ed0cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c07ed0e;
P_0c07ed0e: /* original 3650, guest PC 0x0c07ed0e */
if(!s->budget--) { s->failed_pc=0x0c07ed0eu; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[5])!=0);
goto P_0c07ed10;
P_0c07ed10: /* original 8b03, guest PC 0x0c07ed10 */
if(!s->budget--) { s->failed_pc=0x0c07ed10u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ed1a; }
goto P_0c07ed12;
P_0c07ed12: /* original 9711, guest PC 0x0c07ed12 */
if(!s->budget--) { s->failed_pc=0x0c07ed12u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed38u,2);
goto P_0c07ed14;
P_0c07ed14: /* original e61e, guest PC 0x0c07ed14 */
if(!s->budget--) { s->failed_pc=0x0c07ed14u; return 0; }
r[6]=0x0000001eu;
goto P_0c07ed16;
P_0c07ed16: /* original a01f, guest PC 0x0c07ed16 */
if(!s->budget--) { s->failed_pc=0x0c07ed16u; return 0; }
r[5]=0x00000014u;
goto P_0c07ed58;
P_0c07ed18: /* original e514, guest PC 0x0c07ed18 */
if(!s->budget--) { s->failed_pc=0x0c07ed18u; return 0; }
r[5]=0x00000014u;
goto P_0c07ed1a;
P_0c07ed1a: /* original 970e, guest PC 0x0c07ed1a */
if(!s->budget--) { s->failed_pc=0x0c07ed1au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed3au,2);
goto P_0c07ed1c;
P_0c07ed1c: /* original e61e, guest PC 0x0c07ed1c */
if(!s->budget--) { s->failed_pc=0x0c07ed1cu; return 0; }
r[6]=0x0000001eu;
goto P_0c07ed1e;
P_0c07ed1e: /* original a01b, guest PC 0x0c07ed1e */
if(!s->budget--) { s->failed_pc=0x0c07ed1eu; return 0; }
r[5]=0x00000014u;
goto P_0c07ed58;
P_0c07ed20: /* original e514, guest PC 0x0c07ed20 */
if(!s->budget--) { s->failed_pc=0x0c07ed20u; return 0; }
r[5]=0x00000014u;
if(!vf3_matrix_family(0x0c07ed22u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07ed22u; return 0; } return 1;
P_0c07ed58: /* original 2fe6, guest PC 0x0c07ed58 */
if(!s->budget--) { s->failed_pc=0x0c07ed58u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ed5a;
P_0c07ed5a: /* original 6053, guest PC 0x0c07ed5a */
if(!s->budget--) { s->failed_pc=0x0c07ed5au; return 0; }
r[0]=r[5];
goto P_0c07ed5c;
P_0c07ed5c: /* original 2fd6, guest PC 0x0c07ed5c */
if(!s->budget--) { s->failed_pc=0x0c07ed5cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ed5e;
P_0c07ed5e: /* original e307, guest PC 0x0c07ed5e */
if(!s->budget--) { s->failed_pc=0x0c07ed5eu; return 0; }
r[3]=0x00000007u;
goto P_0c07ed60;
P_0c07ed60: /* original 2fc6, guest PC 0x0c07ed60 */
if(!s->budget--) { s->failed_pc=0x0c07ed60u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ed62;
P_0c07ed62: /* original 6c6f, guest PC 0x0c07ed62 */
if(!s->budget--) { s->failed_pc=0x0c07ed62u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c07ed64;
P_0c07ed64: /* original 2fb6, guest PC 0x0c07ed64 */
if(!s->budget--) { s->failed_pc=0x0c07ed64u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ed66;
P_0c07ed66: /* original 6b5f, guest PC 0x0c07ed66 */
if(!s->budget--) { s->failed_pc=0x0c07ed66u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c07ed68;
P_0c07ed68: /* original 2fa6, guest PC 0x0c07ed68 */
if(!s->budget--) { s->failed_pc=0x0c07ed68u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ed6a;
P_0c07ed6a: /* original 6eb3, guest PC 0x0c07ed6a */
if(!s->budget--) { s->failed_pc=0x0c07ed6au; return 0; }
r[14]=r[11];
goto P_0c07ed6c;
P_0c07ed6c: /* original 2f96, guest PC 0x0c07ed6c */
if(!s->budget--) { s->failed_pc=0x0c07ed6cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ed6e;
P_0c07ed6e: /* original 6973, guest PC 0x0c07ed6e */
if(!s->budget--) { s->failed_pc=0x0c07ed6eu; return 0; }
r[9]=r[7];
goto P_0c07ed70;
P_0c07ed70: /* original 2f86, guest PC 0x0c07ed70 */
if(!s->budget--) { s->failed_pc=0x0c07ed70u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ed72;
P_0c07ed72: /* original e200, guest PC 0x0c07ed72 */
if(!s->budget--) { s->failed_pc=0x0c07ed72u; return 0; }
r[2]=0x00000000u;
goto P_0c07ed74;
P_0c07ed74: /* original 4f22, guest PC 0x0c07ed74 */
if(!s->budget--) { s->failed_pc=0x0c07ed74u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ed76;
P_0c07ed76: /* original 4c3c, guest PC 0x0c07ed76 */
if(!s->budget--) { s->failed_pc=0x0c07ed76u; return 0; }
r[12]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[12]>>((-r[3])&31u)):((int32_t)r[12]<0?0xffffffffu:0)):r[12]<<(r[3]&31u);
goto P_0c07ed78;
P_0c07ed78: /* original 6723, guest PC 0x0c07ed78 */
if(!s->budget--) { s->failed_pc=0x0c07ed78u; return 0; }
r[7]=r[2];
goto P_0c07ed7a;
P_0c07ed7a: /* original 4e00, guest PC 0x0c07ed7a */
if(!s->budget--) { s->failed_pc=0x0c07ed7au; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07ed7c;
P_0c07ed7c: /* original 7ffc, guest PC 0x0c07ed7c */
if(!s->budget--) { s->failed_pc=0x0c07ed7cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07ed7e;
P_0c07ed7e: /* original 2f42, guest PC 0x0c07ed7e */
if(!s->budget--) { s->failed_pc=0x0c07ed7eu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07ed80;
P_0c07ed80: /* original 659d, guest PC 0x0c07ed80 */
if(!s->budget--) { s->failed_pc=0x0c07ed80u; return 0; }
r[5]=r[9]&65535u;
goto P_0c07ed82;
P_0c07ed82: /* original 814a, guest PC 0x0c07ed82 */
if(!s->budget--) { s->failed_pc=0x0c07ed82u; return 0; }
write(ram,r[4]+20,r[0],2);
goto P_0c07ed84;
P_0c07ed84: /* original 6063, guest PC 0x0c07ed84 */
if(!s->budget--) { s->failed_pc=0x0c07ed84u; return 0; }
r[0]=r[6];
goto P_0c07ed86;
P_0c07ed86: /* original 814b, guest PC 0x0c07ed86 */
if(!s->budget--) { s->failed_pc=0x0c07ed86u; return 0; }
write(ram,r[4]+22,r[0],2);
goto P_0c07ed88;
P_0c07ed88: /* original 6093, guest PC 0x0c07ed88 */
if(!s->budget--) { s->failed_pc=0x0c07ed88u; return 0; }
r[0]=r[9];
goto P_0c07ed8a;
P_0c07ed8a: /* original 814c, guest PC 0x0c07ed8a */
if(!s->budget--) { s->failed_pc=0x0c07ed8au; return 0; }
write(ram,r[4]+24,r[0],2);
goto P_0c07ed8c;
P_0c07ed8c: /* original 2ecb, guest PC 0x0c07ed8c */
if(!s->budget--) { s->failed_pc=0x0c07ed8cu; return 0; }
r[14]|=r[12];
goto P_0c07ed8e;
P_0c07ed8e: /* original da39, guest PC 0x0c07ed8e */
if(!s->budget--) { s->failed_pc=0x0c07ed8eu; return 0; }
r[10]=read(ram,0x0c07ee74u,4);
goto P_0c07ed90;
P_0c07ed90: /* original d837, guest PC 0x0c07ed90 */
if(!s->budget--) { s->failed_pc=0x0c07ed90u; return 0; }
r[8]=read(ram,0x0c07ee70u,4);
goto P_0c07ed92;
P_0c07ed92: /* original 66a3, guest PC 0x0c07ed92 */
if(!s->budget--) { s->failed_pc=0x0c07ed92u; return 0; }
r[6]=r[10];
goto P_0c07ed94;
P_0c07ed94: /* original 2f26, guest PC 0x0c07ed94 */
if(!s->budget--) { s->failed_pc=0x0c07ed94u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ed96;
P_0c07ed96: /* original 480b, guest PC 0x0c07ed96 */
if(!s->budget--) { s->failed_pc=0x0c07ed96u; return 0; }
target=r[8];
r[16]=code_base|0x0c07ed9au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ed9au) { target=s->pc; goto dispatch; }
goto P_0c07ed9a;
P_0c07ed98: /* original 64e3, guest PC 0x0c07ed98 */
if(!s->budget--) { s->failed_pc=0x0c07ed98u; return 0; }
r[4]=r[14];
goto P_0c07ed9a;
P_0c07ed9a: /* original 9361, guest PC 0x0c07ed9a */
if(!s->budget--) { s->failed_pc=0x0c07ed9au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee60u,2);
goto P_0c07ed9c;
P_0c07ed9c: /* original 6d9f, guest PC 0x0c07ed9c */
if(!s->budget--) { s->failed_pc=0x0c07ed9cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[9];
goto P_0c07ed9e;
P_0c07ed9e: /* original 3d30, guest PC 0x0c07ed9e */
if(!s->budget--) { s->failed_pc=0x0c07ed9eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c07eda0;
P_0c07eda0: /* original 8f0a, guest PC 0x0c07eda0 */
if(!s->budget--) { s->failed_pc=0x0c07eda0u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(!cond) { goto P_0c07edb8; }
goto P_0c07eda4;
P_0c07eda2: /* original 7f04, guest PC 0x0c07eda2 */
if(!s->budget--) { s->failed_pc=0x0c07eda2u; return 0; }
r[15]+=0x00000004u;
goto P_0c07eda4;
P_0c07eda4: /* original 6eb3, guest PC 0x0c07eda4 */
if(!s->budget--) { s->failed_pc=0x0c07eda4u; return 0; }
r[14]=r[11];
goto P_0c07eda6;
P_0c07eda6: /* original 7e0d, guest PC 0x0c07eda6 */
if(!s->budget--) { s->failed_pc=0x0c07eda6u; return 0; }
r[14]+=0x0000000du;
goto P_0c07eda8;
P_0c07eda8: /* original e200, guest PC 0x0c07eda8 */
if(!s->budget--) { s->failed_pc=0x0c07eda8u; return 0; }
r[2]=0x00000000u;
goto P_0c07edaa;
P_0c07edaa: /* original 4e00, guest PC 0x0c07edaa */
if(!s->budget--) { s->failed_pc=0x0c07edaau; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07edac;
P_0c07edac: /* original 6723, guest PC 0x0c07edac */
if(!s->budget--) { s->failed_pc=0x0c07edacu; return 0; }
r[7]=r[2];
goto P_0c07edae;
P_0c07edae: /* original 2ecb, guest PC 0x0c07edae */
if(!s->budget--) { s->failed_pc=0x0c07edaeu; return 0; }
r[14]|=r[12];
goto P_0c07edb0;
P_0c07edb0: /* original 2f26, guest PC 0x0c07edb0 */
if(!s->budget--) { s->failed_pc=0x0c07edb0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07edb2;
P_0c07edb2: /* original 9556, guest PC 0x0c07edb2 */
if(!s->budget--) { s->failed_pc=0x0c07edb2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee62u,2);
goto P_0c07edb4;
P_0c07edb4: /* original a00c, guest PC 0x0c07edb4 */
if(!s->budget--) { s->failed_pc=0x0c07edb4u; return 0; }
r[6]=r[10];
goto P_0c07edd0;
P_0c07edb6: /* original 66a3, guest PC 0x0c07edb6 */
if(!s->budget--) { s->failed_pc=0x0c07edb6u; return 0; }
r[6]=r[10];
goto P_0c07edb8;
P_0c07edb8: /* original 9254, guest PC 0x0c07edb8 */
if(!s->budget--) { s->failed_pc=0x0c07edb8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee64u,2);
goto P_0c07edba;
P_0c07edba: /* original 3d20, guest PC 0x0c07edba */
if(!s->budget--) { s->failed_pc=0x0c07edbau; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c07edbc;
P_0c07edbc: /* original 8b0c, guest PC 0x0c07edbc */
if(!s->budget--) { s->failed_pc=0x0c07edbcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07edd8; }
goto P_0c07edbe;
P_0c07edbe: /* original 6eb3, guest PC 0x0c07edbe */
if(!s->budget--) { s->failed_pc=0x0c07edbeu; return 0; }
r[14]=r[11];
goto P_0c07edc0;
P_0c07edc0: /* original 7e0c, guest PC 0x0c07edc0 */
if(!s->budget--) { s->failed_pc=0x0c07edc0u; return 0; }
r[14]+=0x0000000cu;
goto P_0c07edc2;
P_0c07edc2: /* original e100, guest PC 0x0c07edc2 */
if(!s->budget--) { s->failed_pc=0x0c07edc2u; return 0; }
r[1]=0x00000000u;
goto P_0c07edc4;
P_0c07edc4: /* original 66a3, guest PC 0x0c07edc4 */
if(!s->budget--) { s->failed_pc=0x0c07edc4u; return 0; }
r[6]=r[10];
goto P_0c07edc6;
P_0c07edc6: /* original 4e00, guest PC 0x0c07edc6 */
if(!s->budget--) { s->failed_pc=0x0c07edc6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07edc8;
P_0c07edc8: /* original 6713, guest PC 0x0c07edc8 */
if(!s->budget--) { s->failed_pc=0x0c07edc8u; return 0; }
r[7]=r[1];
goto P_0c07edca;
P_0c07edca: /* original 2ecb, guest PC 0x0c07edca */
if(!s->budget--) { s->failed_pc=0x0c07edcau; return 0; }
r[14]|=r[12];
goto P_0c07edcc;
P_0c07edcc: /* original 2f16, guest PC 0x0c07edcc */
if(!s->budget--) { s->failed_pc=0x0c07edccu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07edce;
P_0c07edce: /* original 954a, guest PC 0x0c07edce */
if(!s->budget--) { s->failed_pc=0x0c07edceu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee66u,2);
goto P_0c07edd0;
P_0c07edd0: /* original 480b, guest PC 0x0c07edd0 */
if(!s->budget--) { s->failed_pc=0x0c07edd0u; return 0; }
target=r[8];
r[16]=code_base|0x0c07edd4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07edd4u) { target=s->pc; goto dispatch; }
goto P_0c07edd4;
P_0c07edd2: /* original 64e3, guest PC 0x0c07edd2 */
if(!s->budget--) { s->failed_pc=0x0c07edd2u; return 0; }
r[4]=r[14];
goto P_0c07edd4;
P_0c07edd4: /* original a00f, guest PC 0x0c07edd4 */
if(!s->budget--) { s->failed_pc=0x0c07edd4u; return 0; }
r[15]+=0x00000004u;
goto P_0c07edf6;
P_0c07edd6: /* original 7f04, guest PC 0x0c07edd6 */
if(!s->budget--) { s->failed_pc=0x0c07edd6u; return 0; }
r[15]+=0x00000004u;
goto P_0c07edd8;
P_0c07edd8: /* original 9146, guest PC 0x0c07edd8 */
if(!s->budget--) { s->failed_pc=0x0c07edd8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee68u,2);
goto P_0c07edda;
P_0c07edda: /* original 3d10, guest PC 0x0c07edda */
if(!s->budget--) { s->failed_pc=0x0c07eddau; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c07eddc;
P_0c07eddc: /* original 8b0b, guest PC 0x0c07eddc */
if(!s->budget--) { s->failed_pc=0x0c07eddcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07edf6; }
goto P_0c07edde;
P_0c07edde: /* original 6eb3, guest PC 0x0c07edde */
if(!s->budget--) { s->failed_pc=0x0c07eddeu; return 0; }
r[14]=r[11];
goto P_0c07ede0;
P_0c07ede0: /* original 7e0c, guest PC 0x0c07ede0 */
if(!s->budget--) { s->failed_pc=0x0c07ede0u; return 0; }
r[14]+=0x0000000cu;
goto P_0c07ede2;
P_0c07ede2: /* original e300, guest PC 0x0c07ede2 */
if(!s->budget--) { s->failed_pc=0x0c07ede2u; return 0; }
r[3]=0x00000000u;
goto P_0c07ede4;
P_0c07ede4: /* original 66a3, guest PC 0x0c07ede4 */
if(!s->budget--) { s->failed_pc=0x0c07ede4u; return 0; }
r[6]=r[10];
goto P_0c07ede6;
P_0c07ede6: /* original 4e00, guest PC 0x0c07ede6 */
if(!s->budget--) { s->failed_pc=0x0c07ede6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07ede8;
P_0c07ede8: /* original 6733, guest PC 0x0c07ede8 */
if(!s->budget--) { s->failed_pc=0x0c07ede8u; return 0; }
r[7]=r[3];
goto P_0c07edea;
P_0c07edea: /* original 2ecb, guest PC 0x0c07edea */
if(!s->budget--) { s->failed_pc=0x0c07edeau; return 0; }
r[14]|=r[12];
goto P_0c07edec;
P_0c07edec: /* original 2f36, guest PC 0x0c07edec */
if(!s->budget--) { s->failed_pc=0x0c07edecu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07edee;
P_0c07edee: /* original 953c, guest PC 0x0c07edee */
if(!s->budget--) { s->failed_pc=0x0c07edeeu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee6au,2);
goto P_0c07edf0;
P_0c07edf0: /* original 480b, guest PC 0x0c07edf0 */
if(!s->budget--) { s->failed_pc=0x0c07edf0u; return 0; }
target=r[8];
r[16]=code_base|0x0c07edf4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07edf4u) { target=s->pc; goto dispatch; }
goto P_0c07edf4;
P_0c07edf2: /* original 64e3, guest PC 0x0c07edf2 */
if(!s->budget--) { s->failed_pc=0x0c07edf2u; return 0; }
r[4]=r[14];
goto P_0c07edf4;
P_0c07edf4: /* original 7f04, guest PC 0x0c07edf4 */
if(!s->budget--) { s->failed_pc=0x0c07edf4u; return 0; }
r[15]+=0x00000004u;
goto P_0c07edf6;
P_0c07edf6: /* original d420, guest PC 0x0c07edf6 */
if(!s->budget--) { s->failed_pc=0x0c07edf6u; return 0; }
r[4]=read(ram,0x0c07ee78u,4);
goto P_0c07edf8;
P_0c07edf8: /* original e20f, guest PC 0x0c07edf8 */
if(!s->budget--) { s->failed_pc=0x0c07edf8u; return 0; }
r[2]=0x0000000fu;
goto P_0c07edfa;
P_0c07edfa: /* original 1425, guest PC 0x0c07edfa */
if(!s->budget--) { s->failed_pc=0x0c07edfau; return 0; }
write(ram,r[4]+20,r[2],4);
goto P_0c07edfc;
P_0c07edfc: /* original 9330, guest PC 0x0c07edfc */
if(!s->budget--) { s->failed_pc=0x0c07edfcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee60u,2);
goto P_0c07edfe;
P_0c07edfe: /* original 3d30, guest PC 0x0c07edfe */
if(!s->budget--) { s->failed_pc=0x0c07edfeu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c07ee00;
P_0c07ee00: /* original 8908, guest PC 0x0c07ee00 */
if(!s->budget--) { s->failed_pc=0x0c07ee00u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ee14; }
goto P_0c07ee02;
P_0c07ee02: /* original 9133, guest PC 0x0c07ee02 */
if(!s->budget--) { s->failed_pc=0x0c07ee02u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee6cu,2);
goto P_0c07ee04;
P_0c07ee04: /* original 3d10, guest PC 0x0c07ee04 */
if(!s->budget--) { s->failed_pc=0x0c07ee04u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c07ee06;
P_0c07ee06: /* original 8905, guest PC 0x0c07ee06 */
if(!s->budget--) { s->failed_pc=0x0c07ee06u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ee14; }
goto P_0c07ee08;
P_0c07ee08: /* original 902e, guest PC 0x0c07ee08 */
if(!s->budget--) { s->failed_pc=0x0c07ee08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee68u,2);
goto P_0c07ee0a;
P_0c07ee0a: /* original 3d00, guest PC 0x0c07ee0a */
if(!s->budget--) { s->failed_pc=0x0c07ee0au; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[0])!=0);
goto P_0c07ee0c;
P_0c07ee0c: /* original 8902, guest PC 0x0c07ee0c */
if(!s->budget--) { s->failed_pc=0x0c07ee0cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ee14; }
goto P_0c07ee0e;
P_0c07ee0e: /* original 922e, guest PC 0x0c07ee0e */
if(!s->budget--) { s->failed_pc=0x0c07ee0eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee6eu,2);
goto P_0c07ee10;
P_0c07ee10: /* original 3d20, guest PC 0x0c07ee10 */
if(!s->budget--) { s->failed_pc=0x0c07ee10u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c07ee12;
P_0c07ee12: /* original 8b02, guest PC 0x0c07ee12 */
if(!s->budget--) { s->failed_pc=0x0c07ee12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ee1a; }
goto P_0c07ee14;
P_0c07ee14: /* original 5045, guest PC 0x0c07ee14 */
if(!s->budget--) { s->failed_pc=0x0c07ee14u; return 0; }
r[0]=read(ram,r[4]+20,4);
goto P_0c07ee16;
P_0c07ee16: /* original cb80, guest PC 0x0c07ee16 */
if(!s->budget--) { s->failed_pc=0x0c07ee16u; return 0; }
r[0]|=128u;
goto P_0c07ee18;
P_0c07ee18: /* original 1405, guest PC 0x0c07ee18 */
if(!s->budget--) { s->failed_pc=0x0c07ee18u; return 0; }
write(ram,r[4]+20,r[0],4);
goto P_0c07ee1a;
P_0c07ee1a: /* original 64f2, guest PC 0x0c07ee1a */
if(!s->budget--) { s->failed_pc=0x0c07ee1au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07ee1c;
P_0c07ee1c: /* original 7f04, guest PC 0x0c07ee1c */
if(!s->budget--) { s->failed_pc=0x0c07ee1cu; return 0; }
r[15]+=0x00000004u;
goto P_0c07ee1e;
P_0c07ee1e: /* original 4f26, guest PC 0x0c07ee1e */
if(!s->budget--) { s->failed_pc=0x0c07ee1eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ee20;
P_0c07ee20: /* original d316, guest PC 0x0c07ee20 */
if(!s->budget--) { s->failed_pc=0x0c07ee20u; return 0; }
r[3]=read(ram,0x0c07ee7cu,4);
goto P_0c07ee22;
P_0c07ee22: /* original 65e3, guest PC 0x0c07ee22 */
if(!s->budget--) { s->failed_pc=0x0c07ee22u; return 0; }
r[5]=r[14];
goto P_0c07ee24;
P_0c07ee24: /* original 68f6, guest PC 0x0c07ee24 */
if(!s->budget--) { s->failed_pc=0x0c07ee24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c07ee26;
P_0c07ee26: /* original 69f6, guest PC 0x0c07ee26 */
if(!s->budget--) { s->failed_pc=0x0c07ee26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07ee28;
P_0c07ee28: /* original 6af6, guest PC 0x0c07ee28 */
if(!s->budget--) { s->failed_pc=0x0c07ee28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07ee2a;
P_0c07ee2a: /* original 6bf6, guest PC 0x0c07ee2a */
if(!s->budget--) { s->failed_pc=0x0c07ee2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07ee2c;
P_0c07ee2c: /* original 6cf6, guest PC 0x0c07ee2c */
if(!s->budget--) { s->failed_pc=0x0c07ee2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07ee2e;
P_0c07ee2e: /* original 6df6, guest PC 0x0c07ee2e */
if(!s->budget--) { s->failed_pc=0x0c07ee2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07ee30;
P_0c07ee30: /* original 432b, guest PC 0x0c07ee30 */
if(!s->budget--) { s->failed_pc=0x0c07ee30u; return 0; }
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
P_0c07ee32: /* original 6ef6, guest PC 0x0c07ee32 */
if(!s->budget--) { s->failed_pc=0x0c07ee32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07ee34u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07ee34u; return 0; } return 1;
P_0c07f018: /* original 2fe6, guest PC 0x0c07f018 */
if(!s->budget--) { s->failed_pc=0x0c07f018u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f01a;
P_0c07f01a: /* original 6543, guest PC 0x0c07f01a */
if(!s->budget--) { s->failed_pc=0x0c07f01au; return 0; }
r[5]=r[4];
goto P_0c07f01c;
P_0c07f01c: /* original 2fd6, guest PC 0x0c07f01c */
if(!s->budget--) { s->failed_pc=0x0c07f01cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f01e;
P_0c07f01e: /* original ed00, guest PC 0x0c07f01e */
if(!s->budget--) { s->failed_pc=0x0c07f01eu; return 0; }
r[13]=0x00000000u;
goto P_0c07f020;
P_0c07f020: /* original 2fc6, guest PC 0x0c07f020 */
if(!s->budget--) { s->failed_pc=0x0c07f020u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f022;
P_0c07f022: /* original 4f22, guest PC 0x0c07f022 */
if(!s->budget--) { s->failed_pc=0x0c07f022u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07f024;
P_0c07f024: /* original 7ffc, guest PC 0x0c07f024 */
if(!s->budget--) { s->failed_pc=0x0c07f024u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07f026;
P_0c07f026: /* original 2f42, guest PC 0x0c07f026 */
if(!s->budget--) { s->failed_pc=0x0c07f026u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07f028;
P_0c07f028: /* original d32f, guest PC 0x0c07f028 */
if(!s->budget--) { s->failed_pc=0x0c07f028u; return 0; }
r[3]=read(ram,0x0c07f0e8u,4);
goto P_0c07f02a;
P_0c07f02a: /* original d428, guest PC 0x0c07f02a */
if(!s->budget--) { s->failed_pc=0x0c07f02au; return 0; }
r[4]=read(ram,0x0c07f0ccu,4);
goto P_0c07f02c;
P_0c07f02c: /* original 6230, guest PC 0x0c07f02c */
if(!s->budget--) { s->failed_pc=0x0c07f02cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c07f02e;
P_0c07f02e: /* original 6e43, guest PC 0x0c07f02e */
if(!s->budget--) { s->failed_pc=0x0c07f02eu; return 0; }
r[14]=r[4];
goto P_0c07f030;
P_0c07f030: /* original 6c43, guest PC 0x0c07f030 */
if(!s->budget--) { s->failed_pc=0x0c07f030u; return 0; }
r[12]=r[4];
goto P_0c07f032;
P_0c07f032: /* original 7201, guest PC 0x0c07f032 */
if(!s->budget--) { s->failed_pc=0x0c07f032u; return 0; }
r[2]+=0x00000001u;
goto P_0c07f034;
P_0c07f034: /* original 2320, guest PC 0x0c07f034 */
if(!s->budget--) { s->failed_pc=0x0c07f034u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c07f036;
P_0c07f036: /* original e2ff, guest PC 0x0c07f036 */
if(!s->budget--) { s->failed_pc=0x0c07f036u; return 0; }
r[2]=0xffffffffu;
goto P_0c07f038;
P_0c07f038: /* original d32c, guest PC 0x0c07f038 */
if(!s->budget--) { s->failed_pc=0x0c07f038u; return 0; }
r[3]=read(ram,0x0c07f0ecu,4);
goto P_0c07f03a;
P_0c07f03a: /* original 7c58, guest PC 0x0c07f03a */
if(!s->budget--) { s->failed_pc=0x0c07f03au; return 0; }
r[12]+=0x00000058u;
goto P_0c07f03c;
P_0c07f03c: /* original 66c3, guest PC 0x0c07f03c */
if(!s->budget--) { s->failed_pc=0x0c07f03cu; return 0; }
r[6]=r[12];
goto P_0c07f03e;
P_0c07f03e: /* original 1534, guest PC 0x0c07f03e */
if(!s->budget--) { s->failed_pc=0x0c07f03eu; return 0; }
write(ram,r[5]+16,r[3],4);
goto P_0c07f040;
P_0c07f040: /* original 903e, guest PC 0x0c07f040 */
if(!s->budget--) { s->failed_pc=0x0c07f040u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f0c0u,2);
goto P_0c07f042;
P_0c07f042: /* original 0426, guest PC 0x0c07f042 */
if(!s->budget--) { s->failed_pc=0x0c07f042u; return 0; }
write(ram,r[4]+r[0],r[2],4);
goto P_0c07f044;
P_0c07f044: /* original 903d, guest PC 0x0c07f044 */
if(!s->budget--) { s->failed_pc=0x0c07f044u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f0c2u,2);
goto P_0c07f046;
P_0c07f046: /* original 04d6, guest PC 0x0c07f046 */
if(!s->budget--) { s->failed_pc=0x0c07f046u; return 0; }
write(ram,r[4]+r[0],r[13],4);
goto P_0c07f048;
P_0c07f048: /* original 943c, guest PC 0x0c07f048 */
if(!s->budget--) { s->failed_pc=0x0c07f048u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f0c4u,2);
goto P_0c07f04a;
P_0c07f04a: /* original d321, guest PC 0x0c07f04a */
if(!s->budget--) { s->failed_pc=0x0c07f04au; return 0; }
r[3]=read(ram,0x0c07f0d0u,4);
goto P_0c07f04c;
P_0c07f04c: /* original 430b, guest PC 0x0c07f04c */
if(!s->budget--) { s->failed_pc=0x0c07f04cu; return 0; }
target=r[3];
r[16]=code_base|0x0c07f050u;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f050u) { target=s->pc; goto dispatch; }
goto P_0c07f050;
P_0c07f04e: /* original 65e3, guest PC 0x0c07f04e */
if(!s->budget--) { s->failed_pc=0x0c07f04eu; return 0; }
r[5]=r[14];
goto P_0c07f050;
P_0c07f050: /* original d227, guest PC 0x0c07f050 */
if(!s->budget--) { s->failed_pc=0x0c07f050u; return 0; }
r[2]=read(ram,0x0c07f0f0u,4);
goto P_0c07f052;
P_0c07f052: /* original 420b, guest PC 0x0c07f052 */
if(!s->budget--) { s->failed_pc=0x0c07f052u; return 0; }
target=r[2];
r[16]=code_base|0x0c07f056u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f056u) { target=s->pc; goto dispatch; }
goto P_0c07f056;
P_0c07f054: /* original 64e3, guest PC 0x0c07f054 */
if(!s->budget--) { s->failed_pc=0x0c07f054u; return 0; }
r[4]=r[14];
goto P_0c07f056;
P_0c07f056: /* original 65d3, guest PC 0x0c07f056 */
if(!s->budget--) { s->failed_pc=0x0c07f056u; return 0; }
r[5]=r[13];
goto P_0c07f058;
P_0c07f058: /* original e63e, guest PC 0x0c07f058 */
if(!s->budget--) { s->failed_pc=0x0c07f058u; return 0; }
r[6]=0x0000003eu;
goto P_0c07f05a;
P_0c07f05a: /* original 2fd6, guest PC 0x0c07f05a */
if(!s->budget--) { s->failed_pc=0x0c07f05au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f05c;
P_0c07f05c: /* original e730, guest PC 0x0c07f05c */
if(!s->budget--) { s->failed_pc=0x0c07f05cu; return 0; }
r[7]=0x00000030u;
goto P_0c07f05e;
P_0c07f05e: /* original d31f, guest PC 0x0c07f05e */
if(!s->budget--) { s->failed_pc=0x0c07f05eu; return 0; }
r[3]=read(ram,0x0c07f0dcu,4);
goto P_0c07f060;
P_0c07f060: /* original 430b, guest PC 0x0c07f060 */
if(!s->budget--) { s->failed_pc=0x0c07f060u; return 0; }
target=r[3];
r[16]=code_base|0x0c07f064u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f064u) { target=s->pc; goto dispatch; }
goto P_0c07f064;
P_0c07f062: /* original 64c3, guest PC 0x0c07f062 */
if(!s->budget--) { s->failed_pc=0x0c07f062u; return 0; }
r[4]=r[12];
goto P_0c07f064;
P_0c07f064: /* original 9c2f, guest PC 0x0c07f064 */
if(!s->budget--) { s->failed_pc=0x0c07f064u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f0c6u,2);
goto P_0c07f066;
P_0c07f066: /* original 66e3, guest PC 0x0c07f066 */
if(!s->budget--) { s->failed_pc=0x0c07f066u; return 0; }
r[6]=r[14];
goto P_0c07f068;
P_0c07f068: /* original 2fd6, guest PC 0x0c07f068 */
if(!s->budget--) { s->failed_pc=0x0c07f068u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f06a;
P_0c07f06a: /* original 67d3, guest PC 0x0c07f06a */
if(!s->budget--) { s->failed_pc=0x0c07f06au; return 0; }
r[7]=r[13];
goto P_0c07f06c;
P_0c07f06c: /* original 952c, guest PC 0x0c07f06c */
if(!s->budget--) { s->failed_pc=0x0c07f06cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f0c8u,2);
goto P_0c07f06e;
P_0c07f06e: /* original d21c, guest PC 0x0c07f06e */
if(!s->budget--) { s->failed_pc=0x0c07f06eu; return 0; }
r[2]=read(ram,0x0c07f0e0u,4);
goto P_0c07f070;
P_0c07f070: /* original 420b, guest PC 0x0c07f070 */
if(!s->budget--) { s->failed_pc=0x0c07f070u; return 0; }
target=r[2];
r[16]=code_base|0x0c07f074u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f074u) { target=s->pc; goto dispatch; }
goto P_0c07f074;
P_0c07f072: /* original 64c3, guest PC 0x0c07f072 */
if(!s->budget--) { s->failed_pc=0x0c07f072u; return 0; }
r[4]=r[12];
goto P_0c07f074;
P_0c07f074: /* original 65c3, guest PC 0x0c07f074 */
if(!s->budget--) { s->failed_pc=0x0c07f074u; return 0; }
r[5]=r[12];
goto P_0c07f076;
P_0c07f076: /* original d31f, guest PC 0x0c07f076 */
if(!s->budget--) { s->failed_pc=0x0c07f076u; return 0; }
r[3]=read(ram,0x0c07f0f4u,4);
goto P_0c07f078;
P_0c07f078: /* original 23d2, guest PC 0x0c07f078 */
if(!s->budget--) { s->failed_pc=0x0c07f078u; return 0; }
write(ram,r[3],r[13],4);
goto P_0c07f07a;
P_0c07f07a: /* original 54f2, guest PC 0x0c07f07a */
if(!s->budget--) { s->failed_pc=0x0c07f07au; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07f07c;
P_0c07f07c: /* original 7f0c, guest PC 0x0c07f07c */
if(!s->budget--) { s->failed_pc=0x0c07f07cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c07f07e;
P_0c07f07e: /* original 4f26, guest PC 0x0c07f07e */
if(!s->budget--) { s->failed_pc=0x0c07f07eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07f080;
P_0c07f080: /* original d218, guest PC 0x0c07f080 */
if(!s->budget--) { s->failed_pc=0x0c07f080u; return 0; }
r[2]=read(ram,0x0c07f0e4u,4);
goto P_0c07f082;
P_0c07f082: /* original 6cf6, guest PC 0x0c07f082 */
if(!s->budget--) { s->failed_pc=0x0c07f082u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07f084;
P_0c07f084: /* original 6df6, guest PC 0x0c07f084 */
if(!s->budget--) { s->failed_pc=0x0c07f084u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07f086;
P_0c07f086: /* original 422b, guest PC 0x0c07f086 */
if(!s->budget--) { s->failed_pc=0x0c07f086u; return 0; }
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
P_0c07f088: /* original 6ef6, guest PC 0x0c07f088 */
if(!s->budget--) { s->failed_pc=0x0c07f088u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07f08au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07f08au; return 0; } return 1;
P_0c07f1ac: /* original 2fe6, guest PC 0x0c07f1ac */
if(!s->budget--) { s->failed_pc=0x0c07f1acu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f1ae;
P_0c07f1ae: /* original 2fd6, guest PC 0x0c07f1ae */
if(!s->budget--) { s->failed_pc=0x0c07f1aeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f1b0;
P_0c07f1b0: /* original ed00, guest PC 0x0c07f1b0 */
if(!s->budget--) { s->failed_pc=0x0c07f1b0u; return 0; }
r[13]=0x00000000u;
goto P_0c07f1b2;
P_0c07f1b2: /* original 2fc6, guest PC 0x0c07f1b2 */
if(!s->budget--) { s->failed_pc=0x0c07f1b2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f1b4;
P_0c07f1b4: /* original 60d3, guest PC 0x0c07f1b4 */
if(!s->budget--) { s->failed_pc=0x0c07f1b4u; return 0; }
r[0]=r[13];
goto P_0c07f1b6;
P_0c07f1b6: /* original 2fb6, guest PC 0x0c07f1b6 */
if(!s->budget--) { s->failed_pc=0x0c07f1b6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f1b8;
P_0c07f1b8: /* original 2fa6, guest PC 0x0c07f1b8 */
if(!s->budget--) { s->failed_pc=0x0c07f1b8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f1ba;
P_0c07f1ba: /* original 4f22, guest PC 0x0c07f1ba */
if(!s->budget--) { s->failed_pc=0x0c07f1bau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07f1bc;
P_0c07f1bc: /* original dc13, guest PC 0x0c07f1bc */
if(!s->budget--) { s->failed_pc=0x0c07f1bcu; return 0; }
r[12]=read(ram,0x0c07f20cu,4);
goto P_0c07f1be;
P_0c07f1be: /* original 7ff8, guest PC 0x0c07f1be */
if(!s->budget--) { s->failed_pc=0x0c07f1beu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c07f1c0;
P_0c07f1c0: /* original 1f41, guest PC 0x0c07f1c0 */
if(!s->budget--) { s->failed_pc=0x0c07f1c0u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c07f1c2;
P_0c07f1c2: /* original d31a, guest PC 0x0c07f1c2 */
if(!s->budget--) { s->failed_pc=0x0c07f1c2u; return 0; }
r[3]=read(ram,0x0c07f22cu,4);
goto P_0c07f1c4;
P_0c07f1c4: /* original 2f32, guest PC 0x0c07f1c4 */
if(!s->budget--) { s->failed_pc=0x0c07f1c4u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07f1c6;
P_0c07f1c6: /* original d410, guest PC 0x0c07f1c6 */
if(!s->budget--) { s->failed_pc=0x0c07f1c6u; return 0; }
r[4]=read(ram,0x0c07f208u,4);
goto P_0c07f1c8;
P_0c07f1c8: /* original 9618, guest PC 0x0c07f1c8 */
if(!s->budget--) { s->failed_pc=0x0c07f1c8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f1fcu,2);
goto P_0c07f1ca;
P_0c07f1ca: /* original d219, guest PC 0x0c07f1ca */
if(!s->budget--) { s->failed_pc=0x0c07f1cau; return 0; }
r[2]=read(ram,0x0c07f230u,4);
goto P_0c07f1cc;
P_0c07f1cc: /* original 6e43, guest PC 0x0c07f1cc */
if(!s->budget--) { s->failed_pc=0x0c07f1ccu; return 0; }
r[14]=r[4];
goto P_0c07f1ce;
P_0c07f1ce: /* original 364c, guest PC 0x0c07f1ce */
if(!s->budget--) { s->failed_pc=0x0c07f1ceu; return 0; }
r[6]+=r[4];
goto P_0c07f1d0;
P_0c07f1d0: /* original 6b22, guest PC 0x0c07f1d0 */
if(!s->budget--) { s->failed_pc=0x0c07f1d0u; return 0; }
tmp=read(ram,r[2],4);
r[11]=tmp;
goto P_0c07f1d2;
P_0c07f1d2: /* original 81ea, guest PC 0x0c07f1d2 */
if(!s->budget--) { s->failed_pc=0x0c07f1d2u; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c07f1d4;
P_0c07f1d4: /* original 81eb, guest PC 0x0c07f1d4 */
if(!s->budget--) { s->failed_pc=0x0c07f1d4u; return 0; }
write(ram,r[14]+22,r[0],2);
goto P_0c07f1d6;
P_0c07f1d6: /* original 9414, guest PC 0x0c07f1d6 */
if(!s->budget--) { s->failed_pc=0x0c07f1d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f202u,2);
goto P_0c07f1d8;
P_0c07f1d8: /* original d30f, guest PC 0x0c07f1d8 */
if(!s->budget--) { s->failed_pc=0x0c07f1d8u; return 0; }
r[3]=read(ram,0x0c07f218u,4);
goto P_0c07f1da;
P_0c07f1da: /* original 430b, guest PC 0x0c07f1da */
if(!s->budget--) { s->failed_pc=0x0c07f1dau; return 0; }
target=r[3];
r[16]=code_base|0x0c07f1deu;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f1deu) { target=s->pc; goto dispatch; }
goto P_0c07f1de;
P_0c07f1dc: /* original 65e3, guest PC 0x0c07f1dc */
if(!s->budget--) { s->failed_pc=0x0c07f1dcu; return 0; }
r[5]=r[14];
goto P_0c07f1de;
P_0c07f1de: /* original d20d, guest PC 0x0c07f1de */
if(!s->budget--) { s->failed_pc=0x0c07f1deu; return 0; }
r[2]=read(ram,0x0c07f214u,4);
goto P_0c07f1e0;
P_0c07f1e0: /* original 420b, guest PC 0x0c07f1e0 */
if(!s->budget--) { s->failed_pc=0x0c07f1e0u; return 0; }
target=r[2];
r[16]=code_base|0x0c07f1e4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f1e4u) { target=s->pc; goto dispatch; }
goto P_0c07f1e4;
P_0c07f1e2: /* original 64e3, guest PC 0x0c07f1e2 */
if(!s->budget--) { s->failed_pc=0x0c07f1e2u; return 0; }
r[4]=r[14];
goto P_0c07f1e4;
P_0c07f1e4: /* original d313, guest PC 0x0c07f1e4 */
if(!s->budget--) { s->failed_pc=0x0c07f1e4u; return 0; }
r[3]=read(ram,0x0c07f234u,4);
goto P_0c07f1e6;
P_0c07f1e6: /* original 64f2, guest PC 0x0c07f1e6 */
if(!s->budget--) { s->failed_pc=0x0c07f1e6u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07f1e8;
P_0c07f1e8: /* original 430b, guest PC 0x0c07f1e8 */
if(!s->budget--) { s->failed_pc=0x0c07f1e8u; return 0; }
target=r[3];
r[16]=code_base|0x0c07f1ecu;
r[4]+=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f1ecu) { target=s->pc; goto dispatch; }
goto P_0c07f1ec;
P_0c07f1ea: /* original 7412, guest PC 0x0c07f1ea */
if(!s->budget--) { s->failed_pc=0x0c07f1eau; return 0; }
r[4]+=0x00000012u;
goto P_0c07f1ec;
P_0c07f1ec: /* original 650c, guest PC 0x0c07f1ec */
if(!s->budget--) { s->failed_pc=0x0c07f1ecu; return 0; }
r[5]=r[0]&255u;
goto P_0c07f1ee;
P_0c07f1ee: /* original 2558, guest PC 0x0c07f1ee */
if(!s->budget--) { s->failed_pc=0x0c07f1eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c07f1f0;
P_0c07f1f0: /* original 8d22, guest PC 0x0c07f1f0 */
if(!s->budget--) { s->failed_pc=0x0c07f1f0u; return 0; }
cond=r[17]&1u;
r[4]=0x00000018u;
if(cond) { goto P_0c07f238; }
goto P_0c07f1f4;
P_0c07f1f2: /* original e418, guest PC 0x0c07f1f2 */
if(!s->budget--) { s->failed_pc=0x0c07f1f2u; return 0; }
r[4]=0x00000018u;
goto P_0c07f1f4;
P_0c07f1f4: /* original 9506, guest PC 0x0c07f1f4 */
if(!s->budget--) { s->failed_pc=0x0c07f1f4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f204u,2);
goto P_0c07f1f6;
P_0c07f1f6: /* original a021, guest PC 0x0c07f1f6 */
if(!s->budget--) { s->failed_pc=0x0c07f1f6u; return 0; }
r[10]=0x0000001fu;
goto P_0c07f23c;
P_0c07f1f8: /* original ea1f, guest PC 0x0c07f1f8 */
if(!s->budget--) { s->failed_pc=0x0c07f1f8u; return 0; }
r[10]=0x0000001fu;
if(!vf3_matrix_family(0x0c07f1fau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07f1fau; return 0; } return 1;
P_0c07f238: /* original 95ad, guest PC 0x0c07f238 */
if(!s->budget--) { s->failed_pc=0x0c07f238u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f396u,2);
goto P_0c07f23a;
P_0c07f23a: /* original ea22, guest PC 0x0c07f23a */
if(!s->budget--) { s->failed_pc=0x0c07f23au; return 0; }
r[10]=0x00000022u;
goto P_0c07f23c;
P_0c07f23c: /* original e307, guest PC 0x0c07f23c */
if(!s->budget--) { s->failed_pc=0x0c07f23cu; return 0; }
r[3]=0x00000007u;
goto P_0c07f23e;
P_0c07f23e: /* original 66e3, guest PC 0x0c07f23e */
if(!s->budget--) { s->failed_pc=0x0c07f23eu; return 0; }
r[6]=r[14];
goto P_0c07f240;
P_0c07f240: /* original 3ab8, guest PC 0x0c07f240 */
if(!s->budget--) { s->failed_pc=0x0c07f240u; return 0; }
r[10]-=r[11];
goto P_0c07f242;
P_0c07f242: /* original 2fd6, guest PC 0x0c07f242 */
if(!s->budget--) { s->failed_pc=0x0c07f242u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f244;
P_0c07f244: /* original 4a3c, guest PC 0x0c07f244 */
if(!s->budget--) { s->failed_pc=0x0c07f244u; return 0; }
r[10]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[10]>>((-r[3])&31u)):((int32_t)r[10]<0?0xffffffffu:0)):r[10]<<(r[3]&31u);
goto P_0c07f246;
P_0c07f246: /* original e700, guest PC 0x0c07f246 */
if(!s->budget--) { s->failed_pc=0x0c07f246u; return 0; }
r[7]=0x00000000u;
goto P_0c07f248;
P_0c07f248: /* original 2a4b, guest PC 0x0c07f248 */
if(!s->budget--) { s->failed_pc=0x0c07f248u; return 0; }
r[10]|=r[4];
goto P_0c07f24a;
P_0c07f24a: /* original 4c0b, guest PC 0x0c07f24a */
if(!s->budget--) { s->failed_pc=0x0c07f24au; return 0; }
target=r[12];
r[16]=code_base|0x0c07f24eu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f24eu) { target=s->pc; goto dispatch; }
goto P_0c07f24e;
P_0c07f24c: /* original 64a3, guest PC 0x0c07f24c */
if(!s->budget--) { s->failed_pc=0x0c07f24cu; return 0; }
r[4]=r[10];
goto P_0c07f24e;
P_0c07f24e: /* original ea28, guest PC 0x0c07f24e */
if(!s->budget--) { s->failed_pc=0x0c07f24eu; return 0; }
r[10]=0x00000028u;
goto P_0c07f250;
P_0c07f250: /* original 66e3, guest PC 0x0c07f250 */
if(!s->budget--) { s->failed_pc=0x0c07f250u; return 0; }
r[6]=r[14];
goto P_0c07f252;
P_0c07f252: /* original e307, guest PC 0x0c07f252 */
if(!s->budget--) { s->failed_pc=0x0c07f252u; return 0; }
r[3]=0x00000007u;
goto P_0c07f254;
P_0c07f254: /* original 3ab8, guest PC 0x0c07f254 */
if(!s->budget--) { s->failed_pc=0x0c07f254u; return 0; }
r[10]-=r[11];
goto P_0c07f256;
P_0c07f256: /* original e20e, guest PC 0x0c07f256 */
if(!s->budget--) { s->failed_pc=0x0c07f256u; return 0; }
r[2]=0x0000000eu;
goto P_0c07f258;
P_0c07f258: /* original 4a3c, guest PC 0x0c07f258 */
if(!s->budget--) { s->failed_pc=0x0c07f258u; return 0; }
r[10]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[10]>>((-r[3])&31u)):((int32_t)r[10]<0?0xffffffffu:0)):r[10]<<(r[3]&31u);
goto P_0c07f25a;
P_0c07f25a: /* original 22ab, guest PC 0x0c07f25a */
if(!s->budget--) { s->failed_pc=0x0c07f25au; return 0; }
r[2]|=r[10];
goto P_0c07f25c;
P_0c07f25c: /* original 1f21, guest PC 0x0c07f25c */
if(!s->budget--) { s->failed_pc=0x0c07f25cu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c07f25e;
P_0c07f25e: /* original e700, guest PC 0x0c07f25e */
if(!s->budget--) { s->failed_pc=0x0c07f25eu; return 0; }
r[7]=0x00000000u;
goto P_0c07f260;
P_0c07f260: /* original 2fd6, guest PC 0x0c07f260 */
if(!s->budget--) { s->failed_pc=0x0c07f260u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f262;
P_0c07f262: /* original 9599, guest PC 0x0c07f262 */
if(!s->budget--) { s->failed_pc=0x0c07f262u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f398u,2);
goto P_0c07f264;
P_0c07f264: /* original 4c0b, guest PC 0x0c07f264 */
if(!s->budget--) { s->failed_pc=0x0c07f264u; return 0; }
target=r[12];
r[16]=code_base|0x0c07f268u;
r[4]=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f268u) { target=s->pc; goto dispatch; }
goto P_0c07f268;
P_0c07f266: /* original 6423, guest PC 0x0c07f266 */
if(!s->budget--) { s->failed_pc=0x0c07f266u; return 0; }
r[4]=r[2];
goto P_0c07f268;
P_0c07f268: /* original e31c, guest PC 0x0c07f268 */
if(!s->budget--) { s->failed_pc=0x0c07f268u; return 0; }
r[3]=0x0000001cu;
goto P_0c07f26a;
P_0c07f26a: /* original 66e3, guest PC 0x0c07f26a */
if(!s->budget--) { s->failed_pc=0x0c07f26au; return 0; }
r[6]=r[14];
goto P_0c07f26c;
P_0c07f26c: /* original 23ab, guest PC 0x0c07f26c */
if(!s->budget--) { s->failed_pc=0x0c07f26cu; return 0; }
r[3]|=r[10];
goto P_0c07f26e;
P_0c07f26e: /* original 1f32, guest PC 0x0c07f26e */
if(!s->budget--) { s->failed_pc=0x0c07f26eu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07f270;
P_0c07f270: /* original e700, guest PC 0x0c07f270 */
if(!s->budget--) { s->failed_pc=0x0c07f270u; return 0; }
r[7]=0x00000000u;
goto P_0c07f272;
P_0c07f272: /* original 2fd6, guest PC 0x0c07f272 */
if(!s->budget--) { s->failed_pc=0x0c07f272u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f274;
P_0c07f274: /* original 9591, guest PC 0x0c07f274 */
if(!s->budget--) { s->failed_pc=0x0c07f274u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f39au,2);
goto P_0c07f276;
P_0c07f276: /* original 4c0b, guest PC 0x0c07f276 */
if(!s->budget--) { s->failed_pc=0x0c07f276u; return 0; }
target=r[12];
r[16]=code_base|0x0c07f27au;
r[4]=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f27au) { target=s->pc; goto dispatch; }
goto P_0c07f27a;
P_0c07f278: /* original 6433, guest PC 0x0c07f278 */
if(!s->budget--) { s->failed_pc=0x0c07f278u; return 0; }
r[4]=r[3];
goto P_0c07f27a;
P_0c07f27a: /* original e236, guest PC 0x0c07f27a */
if(!s->budget--) { s->failed_pc=0x0c07f27au; return 0; }
r[2]=0x00000036u;
goto P_0c07f27c;
P_0c07f27c: /* original 66e3, guest PC 0x0c07f27c */
if(!s->budget--) { s->failed_pc=0x0c07f27cu; return 0; }
r[6]=r[14];
goto P_0c07f27e;
P_0c07f27e: /* original 22ab, guest PC 0x0c07f27e */
if(!s->budget--) { s->failed_pc=0x0c07f27eu; return 0; }
r[2]|=r[10];
goto P_0c07f280;
P_0c07f280: /* original 1f23, guest PC 0x0c07f280 */
if(!s->budget--) { s->failed_pc=0x0c07f280u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c07f282;
P_0c07f282: /* original e700, guest PC 0x0c07f282 */
if(!s->budget--) { s->failed_pc=0x0c07f282u; return 0; }
r[7]=0x00000000u;
goto P_0c07f284;
P_0c07f284: /* original 2fd6, guest PC 0x0c07f284 */
if(!s->budget--) { s->failed_pc=0x0c07f284u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f286;
P_0c07f286: /* original 9589, guest PC 0x0c07f286 */
if(!s->budget--) { s->failed_pc=0x0c07f286u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f39cu,2);
goto P_0c07f288;
P_0c07f288: /* original 4c0b, guest PC 0x0c07f288 */
if(!s->budget--) { s->failed_pc=0x0c07f288u; return 0; }
target=r[12];
r[16]=code_base|0x0c07f28cu;
r[4]=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f28cu) { target=s->pc; goto dispatch; }
goto P_0c07f28c;
P_0c07f28a: /* original 6423, guest PC 0x0c07f28a */
if(!s->budget--) { s->failed_pc=0x0c07f28au; return 0; }
r[4]=r[2];
goto P_0c07f28c;
P_0c07f28c: /* original eb50, guest PC 0x0c07f28c */
if(!s->budget--) { s->failed_pc=0x0c07f28cu; return 0; }
r[11]=0x00000050u;
goto P_0c07f28e;
P_0c07f28e: /* original 66e3, guest PC 0x0c07f28e */
if(!s->budget--) { s->failed_pc=0x0c07f28eu; return 0; }
r[6]=r[14];
goto P_0c07f290;
P_0c07f290: /* original e700, guest PC 0x0c07f290 */
if(!s->budget--) { s->failed_pc=0x0c07f290u; return 0; }
r[7]=0x00000000u;
goto P_0c07f292;
P_0c07f292: /* original 2fd6, guest PC 0x0c07f292 */
if(!s->budget--) { s->failed_pc=0x0c07f292u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f294;
P_0c07f294: /* original 9583, guest PC 0x0c07f294 */
if(!s->budget--) { s->failed_pc=0x0c07f294u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f39eu,2);
goto P_0c07f296;
P_0c07f296: /* original 2bab, guest PC 0x0c07f296 */
if(!s->budget--) { s->failed_pc=0x0c07f296u; return 0; }
r[11]|=r[10];
goto P_0c07f298;
P_0c07f298: /* original 4c0b, guest PC 0x0c07f298 */
if(!s->budget--) { s->failed_pc=0x0c07f298u; return 0; }
target=r[12];
r[16]=code_base|0x0c07f29cu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f29cu) { target=s->pc; goto dispatch; }
goto P_0c07f29c;
P_0c07f29a: /* original 64b3, guest PC 0x0c07f29a */
if(!s->budget--) { s->failed_pc=0x0c07f29au; return 0; }
r[4]=r[11];
goto P_0c07f29c;
P_0c07f29c: /* original d345, guest PC 0x0c07f29c */
if(!s->budget--) { s->failed_pc=0x0c07f29cu; return 0; }
r[3]=read(ram,0x0c07f3b4u,4);
goto P_0c07f29e;
P_0c07f29e: /* original 957f, guest PC 0x0c07f29e */
if(!s->budget--) { s->failed_pc=0x0c07f29eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f3a0u,2);
goto P_0c07f2a0;
P_0c07f2a0: /* original 430b, guest PC 0x0c07f2a0 */
if(!s->budget--) { s->failed_pc=0x0c07f2a0u; return 0; }
target=r[3];
r[16]=code_base|0x0c07f2a4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f2a4u) { target=s->pc; goto dispatch; }
goto P_0c07f2a4;
P_0c07f2a2: /* original 64e3, guest PC 0x0c07f2a2 */
if(!s->budget--) { s->failed_pc=0x0c07f2a2u; return 0; }
r[4]=r[14];
goto P_0c07f2a4;
P_0c07f2a4: /* original 65b3, guest PC 0x0c07f2a4 */
if(!s->budget--) { s->failed_pc=0x0c07f2a4u; return 0; }
r[5]=r[11];
goto P_0c07f2a6;
P_0c07f2a6: /* original d244, guest PC 0x0c07f2a6 */
if(!s->budget--) { s->failed_pc=0x0c07f2a6u; return 0; }
r[2]=read(ram,0x0c07f3b8u,4);
goto P_0c07f2a8;
P_0c07f2a8: /* original 6320, guest PC 0x0c07f2a8 */
if(!s->budget--) { s->failed_pc=0x0c07f2a8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c07f2aa;
P_0c07f2aa: /* original 7301, guest PC 0x0c07f2aa */
if(!s->budget--) { s->failed_pc=0x0c07f2aau; return 0; }
r[3]+=0x00000001u;
goto P_0c07f2ac;
P_0c07f2ac: /* original 2230, guest PC 0x0c07f2ac */
if(!s->budget--) { s->failed_pc=0x0c07f2acu; return 0; }
write(ram,r[2],r[3],1);
goto P_0c07f2ae;
P_0c07f2ae: /* original 54f6, guest PC 0x0c07f2ae */
if(!s->budget--) { s->failed_pc=0x0c07f2aeu; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c07f2b0;
P_0c07f2b0: /* original 7f1c, guest PC 0x0c07f2b0 */
if(!s->budget--) { s->failed_pc=0x0c07f2b0u; return 0; }
r[15]+=0x0000001cu;
goto P_0c07f2b2;
P_0c07f2b2: /* original 4f26, guest PC 0x0c07f2b2 */
if(!s->budget--) { s->failed_pc=0x0c07f2b2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07f2b4;
P_0c07f2b4: /* original 6af6, guest PC 0x0c07f2b4 */
if(!s->budget--) { s->failed_pc=0x0c07f2b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07f2b6;
P_0c07f2b6: /* original 6bf6, guest PC 0x0c07f2b6 */
if(!s->budget--) { s->failed_pc=0x0c07f2b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07f2b8;
P_0c07f2b8: /* original 6cf6, guest PC 0x0c07f2b8 */
if(!s->budget--) { s->failed_pc=0x0c07f2b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07f2ba;
P_0c07f2ba: /* original 6df6, guest PC 0x0c07f2ba */
if(!s->budget--) { s->failed_pc=0x0c07f2bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07f2bc;
P_0c07f2bc: /* original a000, guest PC 0x0c07f2bc */
if(!s->budget--) { s->failed_pc=0x0c07f2bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07f2c0;
P_0c07f2be: /* original 6ef6, guest PC 0x0c07f2be */
if(!s->budget--) { s->failed_pc=0x0c07f2beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07f2c0;
P_0c07f2c0: /* original 2fe6, guest PC 0x0c07f2c0 */
if(!s->budget--) { s->failed_pc=0x0c07f2c0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f2c2;
P_0c07f2c2: /* original 2fd6, guest PC 0x0c07f2c2 */
if(!s->budget--) { s->failed_pc=0x0c07f2c2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f2c4;
P_0c07f2c4: /* original 4f22, guest PC 0x0c07f2c4 */
if(!s->budget--) { s->failed_pc=0x0c07f2c4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07f2c6;
P_0c07f2c6: /* original 7ff8, guest PC 0x0c07f2c6 */
if(!s->budget--) { s->failed_pc=0x0c07f2c6u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c07f2c8;
P_0c07f2c8: /* original 1f41, guest PC 0x0c07f2c8 */
if(!s->budget--) { s->failed_pc=0x0c07f2c8u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c07f2ca;
P_0c07f2ca: /* original dd3a, guest PC 0x0c07f2ca */
if(!s->budget--) { s->failed_pc=0x0c07f2cau; return 0; }
r[13]=read(ram,0x0c07f3b4u,4);
goto P_0c07f2cc;
P_0c07f2cc: /* original 9569, guest PC 0x0c07f2cc */
if(!s->budget--) { s->failed_pc=0x0c07f2ccu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f3a2u,2);
goto P_0c07f2ce;
P_0c07f2ce: /* original de3b, guest PC 0x0c07f2ce */
if(!s->budget--) { s->failed_pc=0x0c07f2ceu; return 0; }
r[14]=read(ram,0x0c07f3bcu,4);
goto P_0c07f2d0;
P_0c07f2d0: /* original 4d0b, guest PC 0x0c07f2d0 */
if(!s->budget--) { s->failed_pc=0x0c07f2d0u; return 0; }
target=r[13];
r[16]=code_base|0x0c07f2d4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f2d4u) { target=s->pc; goto dispatch; }
goto P_0c07f2d4;
P_0c07f2d2: /* original 64e3, guest PC 0x0c07f2d2 */
if(!s->budget--) { s->failed_pc=0x0c07f2d2u; return 0; }
r[4]=r[14];
goto P_0c07f2d4;
P_0c07f2d4: /* original 9366, guest PC 0x0c07f2d4 */
if(!s->budget--) { s->failed_pc=0x0c07f2d4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f3a4u,2);
goto P_0c07f2d6;
P_0c07f2d6: /* original 6433, guest PC 0x0c07f2d6 */
if(!s->budget--) { s->failed_pc=0x0c07f2d6u; return 0; }
r[4]=r[3];
goto P_0c07f2d8;
P_0c07f2d8: /* original 2f32, guest PC 0x0c07f2d8 */
if(!s->budget--) { s->failed_pc=0x0c07f2d8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07f2da;
P_0c07f2da: /* original d33a, guest PC 0x0c07f2da */
if(!s->budget--) { s->failed_pc=0x0c07f2dau; return 0; }
r[3]=read(ram,0x0c07f3c4u,4);
goto P_0c07f2dc;
P_0c07f2dc: /* original d538, guest PC 0x0c07f2dc */
if(!s->budget--) { s->failed_pc=0x0c07f2dcu; return 0; }
r[5]=read(ram,0x0c07f3c0u,4);
goto P_0c07f2de;
P_0c07f2de: /* original 430b, guest PC 0x0c07f2de */
if(!s->budget--) { s->failed_pc=0x0c07f2deu; return 0; }
target=r[3];
r[16]=code_base|0x0c07f2e2u;
r[6]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f2e2u) { target=s->pc; goto dispatch; }
goto P_0c07f2e2;
P_0c07f2e0: /* original e601, guest PC 0x0c07f2e0 */
if(!s->budget--) { s->failed_pc=0x0c07f2e0u; return 0; }
r[6]=0x00000001u;
goto P_0c07f2e2;
P_0c07f2e2: /* original d339, guest PC 0x0c07f2e2 */
if(!s->budget--) { s->failed_pc=0x0c07f2e2u; return 0; }
r[3]=read(ram,0x0c07f3c8u,4);
goto P_0c07f2e4;
P_0c07f2e4: /* original 430b, guest PC 0x0c07f2e4 */
if(!s->budget--) { s->failed_pc=0x0c07f2e4u; return 0; }
target=r[3];
r[16]=code_base|0x0c07f2e8u;
write(ram,r[15],r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f2e8u) { target=s->pc; goto dispatch; }
goto P_0c07f2e8;
P_0c07f2e6: /* original 2f02, guest PC 0x0c07f2e6 */
if(!s->budget--) { s->failed_pc=0x0c07f2e6u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c07f2e8;
P_0c07f2e8: /* original 955b, guest PC 0x0c07f2e8 */
if(!s->budget--) { s->failed_pc=0x0c07f2e8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f3a2u,2);
goto P_0c07f2ea;
P_0c07f2ea: /* original 4d0b, guest PC 0x0c07f2ea */
if(!s->budget--) { s->failed_pc=0x0c07f2eau; return 0; }
target=r[13];
r[16]=code_base|0x0c07f2eeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f2eeu) { target=s->pc; goto dispatch; }
goto P_0c07f2ee;
P_0c07f2ec: /* original 64e3, guest PC 0x0c07f2ec */
if(!s->budget--) { s->failed_pc=0x0c07f2ecu; return 0; }
r[4]=r[14];
goto P_0c07f2ee;
P_0c07f2ee: /* original d237, guest PC 0x0c07f2ee */
if(!s->budget--) { s->failed_pc=0x0c07f2eeu; return 0; }
r[2]=read(ram,0x0c07f3ccu,4);
goto P_0c07f2f0;
P_0c07f2f0: /* original 420b, guest PC 0x0c07f2f0 */
if(!s->budget--) { s->failed_pc=0x0c07f2f0u; return 0; }
target=r[2];
r[16]=code_base|0x0c07f2f4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f2f4u) { target=s->pc; goto dispatch; }
goto P_0c07f2f4;
P_0c07f2f2: /* original 0009, guest PC 0x0c07f2f2 */
if(!s->budget--) { s->failed_pc=0x0c07f2f2u; return 0; }
goto P_0c07f2f4;
P_0c07f2f4: /* original 9554, guest PC 0x0c07f2f4 */
if(!s->budget--) { s->failed_pc=0x0c07f2f4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f3a0u,2);
goto P_0c07f2f6;
P_0c07f2f6: /* original 4d0b, guest PC 0x0c07f2f6 */
if(!s->budget--) { s->failed_pc=0x0c07f2f6u; return 0; }
target=r[13];
r[16]=code_base|0x0c07f2fau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f2fau) { target=s->pc; goto dispatch; }
goto P_0c07f2fa;
P_0c07f2f8: /* original 64e3, guest PC 0x0c07f2f8 */
if(!s->budget--) { s->failed_pc=0x0c07f2f8u; return 0; }
r[4]=r[14];
goto P_0c07f2fa;
P_0c07f2fa: /* original 54f1, guest PC 0x0c07f2fa */
if(!s->budget--) { s->failed_pc=0x0c07f2fau; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07f2fc;
P_0c07f2fc: /* original 65f2, guest PC 0x0c07f2fc */
if(!s->budget--) { s->failed_pc=0x0c07f2fcu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c07f2fe;
P_0c07f2fe: /* original 7f08, guest PC 0x0c07f2fe */
if(!s->budget--) { s->failed_pc=0x0c07f2feu; return 0; }
r[15]+=0x00000008u;
goto P_0c07f300;
P_0c07f300: /* original 4f26, guest PC 0x0c07f300 */
if(!s->budget--) { s->failed_pc=0x0c07f300u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07f302;
P_0c07f302: /* original d333, guest PC 0x0c07f302 */
if(!s->budget--) { s->failed_pc=0x0c07f302u; return 0; }
r[3]=read(ram,0x0c07f3d0u,4);
goto P_0c07f304;
P_0c07f304: /* original 6df6, guest PC 0x0c07f304 */
if(!s->budget--) { s->failed_pc=0x0c07f304u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07f306;
P_0c07f306: /* original 432b, guest PC 0x0c07f306 */
if(!s->budget--) { s->failed_pc=0x0c07f306u; return 0; }
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
P_0c07f308: /* original 6ef6, guest PC 0x0c07f308 */
if(!s->budget--) { s->failed_pc=0x0c07f308u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07f30a;
P_0c07f30a: /* original 2fe6, guest PC 0x0c07f30a */
if(!s->budget--) { s->failed_pc=0x0c07f30au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f30c;
P_0c07f30c: /* original 6343, guest PC 0x0c07f30c */
if(!s->budget--) { s->failed_pc=0x0c07f30cu; return 0; }
r[3]=r[4];
goto P_0c07f30e;
P_0c07f30e: /* original 2fd6, guest PC 0x0c07f30e */
if(!s->budget--) { s->failed_pc=0x0c07f30eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f310;
P_0c07f310: /* original 2fc6, guest PC 0x0c07f310 */
if(!s->budget--) { s->failed_pc=0x0c07f310u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f312;
P_0c07f312: /* original 2fb6, guest PC 0x0c07f312 */
if(!s->budget--) { s->failed_pc=0x0c07f312u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f314;
P_0c07f314: /* original 4f22, guest PC 0x0c07f314 */
if(!s->budget--) { s->failed_pc=0x0c07f314u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07f316;
P_0c07f316: /* original 7ff4, guest PC 0x0c07f316 */
if(!s->budget--) { s->failed_pc=0x0c07f316u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c07f318;
P_0c07f318: /* original 1f41, guest PC 0x0c07f318 */
if(!s->budget--) { s->failed_pc=0x0c07f318u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c07f31a;
P_0c07f31a: /* original 1f32, guest PC 0x0c07f31a */
if(!s->budget--) { s->failed_pc=0x0c07f31au; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07f31c;
P_0c07f31c: /* original d32d, guest PC 0x0c07f31c */
if(!s->budget--) { s->failed_pc=0x0c07f31cu; return 0; }
r[3]=read(ram,0x0c07f3d4u,4);
goto P_0c07f31e;
P_0c07f31e: /* original de27, guest PC 0x0c07f31e */
if(!s->budget--) { s->failed_pc=0x0c07f31eu; return 0; }
r[14]=read(ram,0x0c07f3bcu,4);
goto P_0c07f320;
P_0c07f320: /* original 430b, guest PC 0x0c07f320 */
if(!s->budget--) { s->failed_pc=0x0c07f320u; return 0; }
target=r[3];
r[16]=code_base|0x0c07f324u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f324u) { target=s->pc; goto dispatch; }
goto P_0c07f324;
P_0c07f322: /* original 64e3, guest PC 0x0c07f322 */
if(!s->budget--) { s->failed_pc=0x0c07f322u; return 0; }
r[4]=r[14];
goto P_0c07f324;
P_0c07f324: /* original 923f, guest PC 0x0c07f324 */
if(!s->budget--) { s->failed_pc=0x0c07f324u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f3a6u,2);
goto P_0c07f326;
P_0c07f326: /* original ed00, guest PC 0x0c07f326 */
if(!s->budget--) { s->failed_pc=0x0c07f326u; return 0; }
r[13]=0x00000000u;
goto P_0c07f328;
P_0c07f328: /* original 66e3, guest PC 0x0c07f328 */
if(!s->budget--) { s->failed_pc=0x0c07f328u; return 0; }
r[6]=r[14];
goto P_0c07f32a;
P_0c07f32a: /* original 67d3, guest PC 0x0c07f32a */
if(!s->budget--) { s->failed_pc=0x0c07f32au; return 0; }
r[7]=r[13];
goto P_0c07f32c;
P_0c07f32c: /* original 2f22, guest PC 0x0c07f32c */
if(!s->budget--) { s->failed_pc=0x0c07f32cu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c07f32e;
P_0c07f32e: /* original dc2a, guest PC 0x0c07f32e */
if(!s->budget--) { s->failed_pc=0x0c07f32eu; return 0; }
r[12]=read(ram,0x0c07f3d8u,4);
goto P_0c07f330;
P_0c07f330: /* original 2fd6, guest PC 0x0c07f330 */
if(!s->budget--) { s->failed_pc=0x0c07f330u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f332;
P_0c07f332: /* original 9539, guest PC 0x0c07f332 */
if(!s->budget--) { s->failed_pc=0x0c07f332u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f3a8u,2);
goto P_0c07f334;
P_0c07f334: /* original 4c0b, guest PC 0x0c07f334 */
if(!s->budget--) { s->failed_pc=0x0c07f334u; return 0; }
target=r[12];
r[16]=code_base|0x0c07f338u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f338u) { target=s->pc; goto dispatch; }
goto P_0c07f338;
P_0c07f336: /* original 54f1, guest PC 0x0c07f336 */
if(!s->budget--) { s->failed_pc=0x0c07f336u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07f338;
P_0c07f338: /* original 9337, guest PC 0x0c07f338 */
if(!s->budget--) { s->failed_pc=0x0c07f338u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f3aau,2);
goto P_0c07f33a;
P_0c07f33a: /* original 66e3, guest PC 0x0c07f33a */
if(!s->budget--) { s->failed_pc=0x0c07f33au; return 0; }
r[6]=r[14];
goto P_0c07f33c;
P_0c07f33c: /* original 67d3, guest PC 0x0c07f33c */
if(!s->budget--) { s->failed_pc=0x0c07f33cu; return 0; }
r[7]=r[13];
goto P_0c07f33e;
P_0c07f33e: /* original 1f31, guest PC 0x0c07f33e */
if(!s->budget--) { s->failed_pc=0x0c07f33eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07f340;
P_0c07f340: /* original 2fd6, guest PC 0x0c07f340 */
if(!s->budget--) { s->failed_pc=0x0c07f340u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f342;
P_0c07f342: /* original 9529, guest PC 0x0c07f342 */
if(!s->budget--) { s->failed_pc=0x0c07f342u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f398u,2);
goto P_0c07f344;
P_0c07f344: /* original 4c0b, guest PC 0x0c07f344 */
if(!s->budget--) { s->failed_pc=0x0c07f344u; return 0; }
target=r[12];
r[16]=code_base|0x0c07f348u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f348u) { target=s->pc; goto dispatch; }
goto P_0c07f348;
P_0c07f346: /* original 54f2, guest PC 0x0c07f346 */
if(!s->budget--) { s->failed_pc=0x0c07f346u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07f348;
P_0c07f348: /* original 9330, guest PC 0x0c07f348 */
if(!s->budget--) { s->failed_pc=0x0c07f348u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f3acu,2);
goto P_0c07f34a;
P_0c07f34a: /* original 66e3, guest PC 0x0c07f34a */
if(!s->budget--) { s->failed_pc=0x0c07f34au; return 0; }
r[6]=r[14];
goto P_0c07f34c;
P_0c07f34c: /* original 67d3, guest PC 0x0c07f34c */
if(!s->budget--) { s->failed_pc=0x0c07f34cu; return 0; }
r[7]=r[13];
goto P_0c07f34e;
P_0c07f34e: /* original 1f32, guest PC 0x0c07f34e */
if(!s->budget--) { s->failed_pc=0x0c07f34eu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07f350;
P_0c07f350: /* original 2fd6, guest PC 0x0c07f350 */
if(!s->budget--) { s->failed_pc=0x0c07f350u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f352;
P_0c07f352: /* original 9522, guest PC 0x0c07f352 */
if(!s->budget--) { s->failed_pc=0x0c07f352u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f39au,2);
goto P_0c07f354;
P_0c07f354: /* original 4c0b, guest PC 0x0c07f354 */
if(!s->budget--) { s->failed_pc=0x0c07f354u; return 0; }
target=r[12];
r[16]=code_base|0x0c07f358u;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f358u) { target=s->pc; goto dispatch; }
goto P_0c07f358;
P_0c07f356: /* original 54f3, guest PC 0x0c07f356 */
if(!s->budget--) { s->failed_pc=0x0c07f356u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c07f358;
P_0c07f358: /* original 9329, guest PC 0x0c07f358 */
if(!s->budget--) { s->failed_pc=0x0c07f358u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f3aeu,2);
goto P_0c07f35a;
P_0c07f35a: /* original 66e3, guest PC 0x0c07f35a */
if(!s->budget--) { s->failed_pc=0x0c07f35au; return 0; }
r[6]=r[14];
goto P_0c07f35c;
P_0c07f35c: /* original 67d3, guest PC 0x0c07f35c */
if(!s->budget--) { s->failed_pc=0x0c07f35cu; return 0; }
r[7]=r[13];
goto P_0c07f35e;
P_0c07f35e: /* original 1f33, guest PC 0x0c07f35e */
if(!s->budget--) { s->failed_pc=0x0c07f35eu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c07f360;
P_0c07f360: /* original 2fd6, guest PC 0x0c07f360 */
if(!s->budget--) { s->failed_pc=0x0c07f360u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f362;
P_0c07f362: /* original 951b, guest PC 0x0c07f362 */
if(!s->budget--) { s->failed_pc=0x0c07f362u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f39cu,2);
goto P_0c07f364;
P_0c07f364: /* original 4c0b, guest PC 0x0c07f364 */
if(!s->budget--) { s->failed_pc=0x0c07f364u; return 0; }
target=r[12];
r[16]=code_base|0x0c07f368u;
r[4]=read(ram,r[15]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f368u) { target=s->pc; goto dispatch; }
goto P_0c07f368;
P_0c07f366: /* original 54f4, guest PC 0x0c07f366 */
if(!s->budget--) { s->failed_pc=0x0c07f366u; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c07f368;
P_0c07f368: /* original 9b22, guest PC 0x0c07f368 */
if(!s->budget--) { s->failed_pc=0x0c07f368u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f3b0u,2);
goto P_0c07f36a;
P_0c07f36a: /* original 66e3, guest PC 0x0c07f36a */
if(!s->budget--) { s->failed_pc=0x0c07f36au; return 0; }
r[6]=r[14];
goto P_0c07f36c;
P_0c07f36c: /* original 2fd6, guest PC 0x0c07f36c */
if(!s->budget--) { s->failed_pc=0x0c07f36cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f36e;
P_0c07f36e: /* original 67d3, guest PC 0x0c07f36e */
if(!s->budget--) { s->failed_pc=0x0c07f36eu; return 0; }
r[7]=r[13];
goto P_0c07f370;
P_0c07f370: /* original 9515, guest PC 0x0c07f370 */
if(!s->budget--) { s->failed_pc=0x0c07f370u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f39eu,2);
goto P_0c07f372;
P_0c07f372: /* original 4c0b, guest PC 0x0c07f372 */
if(!s->budget--) { s->failed_pc=0x0c07f372u; return 0; }
target=r[12];
r[16]=code_base|0x0c07f376u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f376u) { target=s->pc; goto dispatch; }
goto P_0c07f376;
P_0c07f374: /* original 64b3, guest PC 0x0c07f374 */
if(!s->budget--) { s->failed_pc=0x0c07f374u; return 0; }
r[4]=r[11];
goto P_0c07f376;
P_0c07f376: /* original 53f7, guest PC 0x0c07f376 */
if(!s->budget--) { s->failed_pc=0x0c07f376u; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c07f378;
P_0c07f378: /* original 65b3, guest PC 0x0c07f378 */
if(!s->budget--) { s->failed_pc=0x0c07f378u; return 0; }
r[5]=r[11];
goto P_0c07f37a;
P_0c07f37a: /* original d218, guest PC 0x0c07f37a */
if(!s->budget--) { s->failed_pc=0x0c07f37au; return 0; }
r[2]=read(ram,0x0c07f3dcu,4);
goto P_0c07f37c;
P_0c07f37c: /* original 1324, guest PC 0x0c07f37c */
if(!s->budget--) { s->failed_pc=0x0c07f37cu; return 0; }
write(ram,r[3]+16,r[2],4);
goto P_0c07f37e;
P_0c07f37e: /* original d30e, guest PC 0x0c07f37e */
if(!s->budget--) { s->failed_pc=0x0c07f37eu; return 0; }
r[3]=read(ram,0x0c07f3b8u,4);
goto P_0c07f380;
P_0c07f380: /* original 6130, guest PC 0x0c07f380 */
if(!s->budget--) { s->failed_pc=0x0c07f380u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[1]=tmp;
goto P_0c07f382;
P_0c07f382: /* original 7101, guest PC 0x0c07f382 */
if(!s->budget--) { s->failed_pc=0x0c07f382u; return 0; }
r[1]+=0x00000001u;
goto P_0c07f384;
P_0c07f384: /* original 2310, guest PC 0x0c07f384 */
if(!s->budget--) { s->failed_pc=0x0c07f384u; return 0; }
write(ram,r[3],r[1],1);
goto P_0c07f386;
P_0c07f386: /* original 54f6, guest PC 0x0c07f386 */
if(!s->budget--) { s->failed_pc=0x0c07f386u; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c07f388;
P_0c07f388: /* original 7f20, guest PC 0x0c07f388 */
if(!s->budget--) { s->failed_pc=0x0c07f388u; return 0; }
r[15]+=0x00000020u;
goto P_0c07f38a;
P_0c07f38a: /* original 4f26, guest PC 0x0c07f38a */
if(!s->budget--) { s->failed_pc=0x0c07f38au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07f38c;
P_0c07f38c: /* original 6bf6, guest PC 0x0c07f38c */
if(!s->budget--) { s->failed_pc=0x0c07f38cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07f38e;
P_0c07f38e: /* original 6cf6, guest PC 0x0c07f38e */
if(!s->budget--) { s->failed_pc=0x0c07f38eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07f390;
P_0c07f390: /* original 6df6, guest PC 0x0c07f390 */
if(!s->budget--) { s->failed_pc=0x0c07f390u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07f392;
P_0c07f392: /* original a025, guest PC 0x0c07f392 */
if(!s->budget--) { s->failed_pc=0x0c07f392u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07f3e0;
P_0c07f394: /* original 6ef6, guest PC 0x0c07f394 */
if(!s->budget--) { s->failed_pc=0x0c07f394u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07f396u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07f396u; return 0; } return 1;
P_0c07f3e0: /* original 2fe6, guest PC 0x0c07f3e0 */
if(!s->budget--) { s->failed_pc=0x0c07f3e0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f3e2;
P_0c07f3e2: /* original 4f22, guest PC 0x0c07f3e2 */
if(!s->budget--) { s->failed_pc=0x0c07f3e2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07f3e4;
P_0c07f3e4: /* original 7ff8, guest PC 0x0c07f3e4 */
if(!s->budget--) { s->failed_pc=0x0c07f3e4u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c07f3e6;
P_0c07f3e6: /* original 2f42, guest PC 0x0c07f3e6 */
if(!s->budget--) { s->failed_pc=0x0c07f3e6u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07f3e8;
P_0c07f3e8: /* original 1f51, guest PC 0x0c07f3e8 */
if(!s->budget--) { s->failed_pc=0x0c07f3e8u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c07f3ea;
P_0c07f3ea: /* original 9511, guest PC 0x0c07f3ea */
if(!s->budget--) { s->failed_pc=0x0c07f3eau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f410u,2);
goto P_0c07f3ec;
P_0c07f3ec: /* original de09, guest PC 0x0c07f3ec */
if(!s->budget--) { s->failed_pc=0x0c07f3ecu; return 0; }
r[14]=read(ram,0x0c07f414u,4);
goto P_0c07f3ee;
P_0c07f3ee: /* original d30a, guest PC 0x0c07f3ee */
if(!s->budget--) { s->failed_pc=0x0c07f3eeu; return 0; }
r[3]=read(ram,0x0c07f418u,4);
goto P_0c07f3f0;
P_0c07f3f0: /* original 430b, guest PC 0x0c07f3f0 */
if(!s->budget--) { s->failed_pc=0x0c07f3f0u; return 0; }
target=r[3];
r[16]=code_base|0x0c07f3f4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f3f4u) { target=s->pc; goto dispatch; }
goto P_0c07f3f4;
P_0c07f3f2: /* original 64e3, guest PC 0x0c07f3f2 */
if(!s->budget--) { s->failed_pc=0x0c07f3f2u; return 0; }
r[4]=r[14];
goto P_0c07f3f4;
P_0c07f3f4: /* original d209, guest PC 0x0c07f3f4 */
if(!s->budget--) { s->failed_pc=0x0c07f3f4u; return 0; }
r[2]=read(ram,0x0c07f41cu,4);
goto P_0c07f3f6;
P_0c07f3f6: /* original 420b, guest PC 0x0c07f3f6 */
if(!s->budget--) { s->failed_pc=0x0c07f3f6u; return 0; }
target=r[2];
r[16]=code_base|0x0c07f3fau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f3fau) { target=s->pc; goto dispatch; }
goto P_0c07f3fa;
P_0c07f3f8: /* original 0009, guest PC 0x0c07f3f8 */
if(!s->budget--) { s->failed_pc=0x0c07f3f8u; return 0; }
goto P_0c07f3fa;
P_0c07f3fa: /* original d307, guest PC 0x0c07f3fa */
if(!s->budget--) { s->failed_pc=0x0c07f3fau; return 0; }
r[3]=read(ram,0x0c07f418u,4);
goto P_0c07f3fc;
P_0c07f3fc: /* original 9509, guest PC 0x0c07f3fc */
if(!s->budget--) { s->failed_pc=0x0c07f3fcu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f412u,2);
goto P_0c07f3fe;
P_0c07f3fe: /* original 430b, guest PC 0x0c07f3fe */
if(!s->budget--) { s->failed_pc=0x0c07f3feu; return 0; }
target=r[3];
r[16]=code_base|0x0c07f402u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f402u) { target=s->pc; goto dispatch; }
goto P_0c07f402;
P_0c07f400: /* original 64e3, guest PC 0x0c07f400 */
if(!s->budget--) { s->failed_pc=0x0c07f400u; return 0; }
r[4]=r[14];
goto P_0c07f402;
P_0c07f402: /* original 64f2, guest PC 0x0c07f402 */
if(!s->budget--) { s->failed_pc=0x0c07f402u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07f404;
P_0c07f404: /* original 55f1, guest PC 0x0c07f404 */
if(!s->budget--) { s->failed_pc=0x0c07f404u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c07f406;
P_0c07f406: /* original 7f08, guest PC 0x0c07f406 */
if(!s->budget--) { s->failed_pc=0x0c07f406u; return 0; }
r[15]+=0x00000008u;
goto P_0c07f408;
P_0c07f408: /* original 4f26, guest PC 0x0c07f408 */
if(!s->budget--) { s->failed_pc=0x0c07f408u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07f40a;
P_0c07f40a: /* original d305, guest PC 0x0c07f40a */
if(!s->budget--) { s->failed_pc=0x0c07f40au; return 0; }
r[3]=read(ram,0x0c07f420u,4);
goto P_0c07f40c;
P_0c07f40c: /* original 432b, guest PC 0x0c07f40c */
if(!s->budget--) { s->failed_pc=0x0c07f40cu; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c07ba28u: return vf3_matrix_family(0x0c07ba28u,s,ram);
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
P_0c07f40e: /* original 6ef6, guest PC 0x0c07f40e */
if(!s->budget--) { s->failed_pc=0x0c07f40eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07f410u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07f410u; return 0; } return 1;
P_0c07f424: /* original 2fe6, guest PC 0x0c07f424 */
if(!s->budget--) { s->failed_pc=0x0c07f424u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f426;
P_0c07f426: /* original ee00, guest PC 0x0c07f426 */
if(!s->budget--) { s->failed_pc=0x0c07f426u; return 0; }
r[14]=0x00000000u;
goto P_0c07f428;
P_0c07f428: /* original 2fd6, guest PC 0x0c07f428 */
if(!s->budget--) { s->failed_pc=0x0c07f428u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f42a;
P_0c07f42a: /* original 60e3, guest PC 0x0c07f42a */
if(!s->budget--) { s->failed_pc=0x0c07f42au; return 0; }
r[0]=r[14];
goto P_0c07f42c;
P_0c07f42c: /* original 2fc6, guest PC 0x0c07f42c */
if(!s->budget--) { s->failed_pc=0x0c07f42cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f42e;
P_0c07f42e: /* original 2fb6, guest PC 0x0c07f42e */
if(!s->budget--) { s->failed_pc=0x0c07f42eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f430;
P_0c07f430: /* original 2fa6, guest PC 0x0c07f430 */
if(!s->budget--) { s->failed_pc=0x0c07f430u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f432;
P_0c07f432: /* original 2f96, guest PC 0x0c07f432 */
if(!s->budget--) { s->failed_pc=0x0c07f432u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f434;
P_0c07f434: /* original 2f86, guest PC 0x0c07f434 */
if(!s->budget--) { s->failed_pc=0x0c07f434u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f436;
P_0c07f436: /* original 4f22, guest PC 0x0c07f436 */
if(!s->budget--) { s->failed_pc=0x0c07f436u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07f438;
P_0c07f438: /* original 7fdc, guest PC 0x0c07f438 */
if(!s->budget--) { s->failed_pc=0x0c07f438u; return 0; }
r[15]+=0xffffffdcu;
goto P_0c07f43a;
P_0c07f43a: /* original 1f46, guest PC 0x0c07f43a */
if(!s->budget--) { s->failed_pc=0x0c07f43au; return 0; }
write(ram,r[15]+24,r[4],4);
goto P_0c07f43c;
P_0c07f43c: /* original d347, guest PC 0x0c07f43c */
if(!s->budget--) { s->failed_pc=0x0c07f43cu; return 0; }
r[3]=read(ram,0x0c07f55cu,4);
goto P_0c07f43e;
P_0c07f43e: /* original 1f38, guest PC 0x0c07f43e */
if(!s->budget--) { s->failed_pc=0x0c07f43eu; return 0; }
write(ram,r[15]+32,r[3],4);
goto P_0c07f440;
P_0c07f440: /* original 52f6, guest PC 0x0c07f440 */
if(!s->budget--) { s->failed_pc=0x0c07f440u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c07f442;
P_0c07f442: /* original 1f27, guest PC 0x0c07f442 */
if(!s->budget--) { s->failed_pc=0x0c07f442u; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c07f444;
P_0c07f444: /* original d446, guest PC 0x0c07f444 */
if(!s->budget--) { s->failed_pc=0x0c07f444u; return 0; }
r[4]=read(ram,0x0c07f560u,4);
goto P_0c07f446;
P_0c07f446: /* original 6343, guest PC 0x0c07f446 */
if(!s->budget--) { s->failed_pc=0x0c07f446u; return 0; }
r[3]=r[4];
goto P_0c07f448;
P_0c07f448: /* original 7358, guest PC 0x0c07f448 */
if(!s->budget--) { s->failed_pc=0x0c07f448u; return 0; }
r[3]+=0x00000058u;
goto P_0c07f44a;
P_0c07f44a: /* original 1f33, guest PC 0x0c07f44a */
if(!s->budget--) { s->failed_pc=0x0c07f44au; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c07f44c;
P_0c07f44c: /* original 6c43, guest PC 0x0c07f44c */
if(!s->budget--) { s->failed_pc=0x0c07f44cu; return 0; }
r[12]=r[4];
goto P_0c07f44e;
P_0c07f44e: /* original 81ca, guest PC 0x0c07f44e */
if(!s->budget--) { s->failed_pc=0x0c07f44eu; return 0; }
write(ram,r[12]+20,r[0],2);
goto P_0c07f450;
P_0c07f450: /* original 81cb, guest PC 0x0c07f450 */
if(!s->budget--) { s->failed_pc=0x0c07f450u; return 0; }
write(ram,r[12]+22,r[0],2);
goto P_0c07f452;
P_0c07f452: /* original d344, guest PC 0x0c07f452 */
if(!s->budget--) { s->failed_pc=0x0c07f452u; return 0; }
r[3]=read(ram,0x0c07f564u,4);
goto P_0c07f454;
P_0c07f454: /* original 2302, guest PC 0x0c07f454 */
if(!s->budget--) { s->failed_pc=0x0c07f454u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c07f456;
P_0c07f456: /* original 56f3, guest PC 0x0c07f456 */
if(!s->budget--) { s->failed_pc=0x0c07f456u; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c07f458;
P_0c07f458: /* original d243, guest PC 0x0c07f458 */
if(!s->budget--) { s->failed_pc=0x0c07f458u; return 0; }
r[2]=read(ram,0x0c07f568u,4);
goto P_0c07f45a;
P_0c07f45a: /* original 9472, guest PC 0x0c07f45a */
if(!s->budget--) { s->failed_pc=0x0c07f45au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f542u,2);
goto P_0c07f45c;
P_0c07f45c: /* original 420b, guest PC 0x0c07f45c */
if(!s->budget--) { s->failed_pc=0x0c07f45cu; return 0; }
target=r[2];
r[16]=code_base|0x0c07f460u;
r[5]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f460u) { target=s->pc; goto dispatch; }
goto P_0c07f460;
P_0c07f45e: /* original 65c3, guest PC 0x0c07f45e */
if(!s->budget--) { s->failed_pc=0x0c07f45eu; return 0; }
r[5]=r[12];
goto P_0c07f460;
P_0c07f460: /* original 9070, guest PC 0x0c07f460 */
if(!s->budget--) { s->failed_pc=0x0c07f460u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f544u,2);
goto P_0c07f462;
P_0c07f462: /* original 66c3, guest PC 0x0c07f462 */
if(!s->budget--) { s->failed_pc=0x0c07f462u; return 0; }
r[6]=r[12];
goto P_0c07f464;
P_0c07f464: /* original db41, guest PC 0x0c07f464 */
if(!s->budget--) { s->failed_pc=0x0c07f464u; return 0; }
r[11]=read(ram,0x0c07f56cu,4);
goto P_0c07f466;
P_0c07f466: /* original 67e3, guest PC 0x0c07f466 */
if(!s->budget--) { s->failed_pc=0x0c07f466u; return 0; }
r[7]=r[14];
goto P_0c07f468;
P_0c07f468: /* original d441, guest PC 0x0c07f468 */
if(!s->budget--) { s->failed_pc=0x0c07f468u; return 0; }
r[4]=read(ram,0x0c07f570u,4);
goto P_0c07f46a;
P_0c07f46a: /* original 05bc, guest PC 0x0c07f46a */
if(!s->budget--) { s->failed_pc=0x0c07f46au; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c07f46c;
P_0c07f46c: /* original 4500, guest PC 0x0c07f46c */
if(!s->budget--) { s->failed_pc=0x0c07f46cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07f46e;
P_0c07f46e: /* original 6053, guest PC 0x0c07f46e */
if(!s->budget--) { s->failed_pc=0x0c07f46eu; return 0; }
r[0]=r[5];
goto P_0c07f470;
P_0c07f470: /* original 4000, guest PC 0x0c07f470 */
if(!s->budget--) { s->failed_pc=0x0c07f470u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07f472;
P_0c07f472: /* original 034d, guest PC 0x0c07f472 */
if(!s->budget--) { s->failed_pc=0x0c07f472u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07f474;
P_0c07f474: /* original 6053, guest PC 0x0c07f474 */
if(!s->budget--) { s->failed_pc=0x0c07f474u; return 0; }
r[0]=r[5];
goto P_0c07f476;
P_0c07f476: /* original 7001, guest PC 0x0c07f476 */
if(!s->budget--) { s->failed_pc=0x0c07f476u; return 0; }
r[0]+=0x00000001u;
goto P_0c07f478;
P_0c07f478: /* original 4000, guest PC 0x0c07f478 */
if(!s->budget--) { s->failed_pc=0x0c07f478u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07f47a;
P_0c07f47a: /* original 2f31, guest PC 0x0c07f47a */
if(!s->budget--) { s->failed_pc=0x0c07f47au; return 0; }
write(ram,r[15],r[3],2);
goto P_0c07f47c;
P_0c07f47c: /* original 004d, guest PC 0x0c07f47c */
if(!s->budget--) { s->failed_pc=0x0c07f47cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07f47e;
P_0c07f47e: /* original 653f, guest PC 0x0c07f47e */
if(!s->budget--) { s->failed_pc=0x0c07f47eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c07f480;
P_0c07f480: /* original 81f2, guest PC 0x0c07f480 */
if(!s->budget--) { s->failed_pc=0x0c07f480u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c07f482;
P_0c07f482: /* original 9260, guest PC 0x0c07f482 */
if(!s->budget--) { s->failed_pc=0x0c07f482u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f546u,2);
goto P_0c07f484;
P_0c07f484: /* original 1f22, guest PC 0x0c07f484 */
if(!s->budget--) { s->failed_pc=0x0c07f484u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c07f486;
P_0c07f486: /* original dd3b, guest PC 0x0c07f486 */
if(!s->budget--) { s->failed_pc=0x0c07f486u; return 0; }
r[13]=read(ram,0x0c07f574u,4);
goto P_0c07f488;
P_0c07f488: /* original 2fe6, guest PC 0x0c07f488 */
if(!s->budget--) { s->failed_pc=0x0c07f488u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f48a;
P_0c07f48a: /* original 4d0b, guest PC 0x0c07f48a */
if(!s->budget--) { s->failed_pc=0x0c07f48au; return 0; }
target=r[13];
r[16]=code_base|0x0c07f48eu;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f48eu) { target=s->pc; goto dispatch; }
goto P_0c07f48e;
P_0c07f48c: /* original 54f3, guest PC 0x0c07f48c */
if(!s->budget--) { s->failed_pc=0x0c07f48cu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c07f48e;
P_0c07f48e: /* original 935b, guest PC 0x0c07f48e */
if(!s->budget--) { s->failed_pc=0x0c07f48eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f548u,2);
goto P_0c07f490;
P_0c07f490: /* original 67e3, guest PC 0x0c07f490 */
if(!s->budget--) { s->failed_pc=0x0c07f490u; return 0; }
r[7]=r[14];
goto P_0c07f492;
P_0c07f492: /* original 66c3, guest PC 0x0c07f492 */
if(!s->budget--) { s->failed_pc=0x0c07f492u; return 0; }
r[6]=r[12];
goto P_0c07f494;
P_0c07f494: /* original 1f31, guest PC 0x0c07f494 */
if(!s->budget--) { s->failed_pc=0x0c07f494u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07f496;
P_0c07f496: /* original 2fe6, guest PC 0x0c07f496 */
if(!s->budget--) { s->failed_pc=0x0c07f496u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f498;
P_0c07f498: /* original 85f6, guest PC 0x0c07f498 */
if(!s->budget--) { s->failed_pc=0x0c07f498u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c07f49a;
P_0c07f49a: /* original 6503, guest PC 0x0c07f49a */
if(!s->budget--) { s->failed_pc=0x0c07f49au; return 0; }
r[5]=r[0];
goto P_0c07f49c;
P_0c07f49c: /* original 4d0b, guest PC 0x0c07f49c */
if(!s->budget--) { s->failed_pc=0x0c07f49cu; return 0; }
target=r[13];
r[16]=code_base|0x0c07f4a0u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f4a0u) { target=s->pc; goto dispatch; }
goto P_0c07f4a0;
P_0c07f49e: /* original 54f2, guest PC 0x0c07f49e */
if(!s->budget--) { s->failed_pc=0x0c07f49eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07f4a0;
P_0c07f4a0: /* original 9053, guest PC 0x0c07f4a0 */
if(!s->budget--) { s->failed_pc=0x0c07f4a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f54au,2);
goto P_0c07f4a2;
P_0c07f4a2: /* original d335, guest PC 0x0c07f4a2 */
if(!s->budget--) { s->failed_pc=0x0c07f4a2u; return 0; }
r[3]=read(ram,0x0c07f578u,4);
goto P_0c07f4a4;
P_0c07f4a4: /* original 0abc, guest PC 0x0c07f4a4 */
if(!s->budget--) { s->failed_pc=0x0c07f4a4u; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c07f4a6;
P_0c07f4a6: /* original 9752, guest PC 0x0c07f4a6 */
if(!s->budget--) { s->failed_pc=0x0c07f4a6u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f54eu,2);
goto P_0c07f4a8;
P_0c07f4a8: /* original 9550, guest PC 0x0c07f4a8 */
if(!s->budget--) { s->failed_pc=0x0c07f4a8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f54cu,2);
goto P_0c07f4aa;
P_0c07f4aa: /* original 66a3, guest PC 0x0c07f4aa */
if(!s->budget--) { s->failed_pc=0x0c07f4aau; return 0; }
r[6]=r[10];
goto P_0c07f4ac;
P_0c07f4ac: /* original 430b, guest PC 0x0c07f4ac */
if(!s->budget--) { s->failed_pc=0x0c07f4acu; return 0; }
target=r[3];
r[16]=code_base|0x0c07f4b0u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f4b0u) { target=s->pc; goto dispatch; }
goto P_0c07f4b0;
P_0c07f4ae: /* original 64c3, guest PC 0x0c07f4ae */
if(!s->budget--) { s->failed_pc=0x0c07f4aeu; return 0; }
r[4]=r[12];
goto P_0c07f4b0;
P_0c07f4b0: /* original 60a3, guest PC 0x0c07f4b0 */
if(!s->budget--) { s->failed_pc=0x0c07f4b0u; return 0; }
r[0]=r[10];
goto P_0c07f4b2;
P_0c07f4b2: /* original e40c, guest PC 0x0c07f4b2 */
if(!s->budget--) { s->failed_pc=0x0c07f4b2u; return 0; }
r[4]=0x0000000cu;
goto P_0c07f4b4;
P_0c07f4b4: /* original 4021, guest PC 0x0c07f4b4 */
if(!s->budget--) { s->failed_pc=0x0c07f4b4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c07f4b6;
P_0c07f4b6: /* original d131, guest PC 0x0c07f4b6 */
if(!s->budget--) { s->failed_pc=0x0c07f4b6u; return 0; }
r[1]=read(ram,0x0c07f57cu,4);
goto P_0c07f4b8;
P_0c07f4b8: /* original 2409, guest PC 0x0c07f4b8 */
if(!s->budget--) { s->failed_pc=0x0c07f4b8u; return 0; }
r[4]&=r[0];
goto P_0c07f4ba;
P_0c07f4ba: /* original 67e3, guest PC 0x0c07f4ba */
if(!s->budget--) { s->failed_pc=0x0c07f4bau; return 0; }
r[7]=r[14];
goto P_0c07f4bc;
P_0c07f4bc: /* original 4401, guest PC 0x0c07f4bc */
if(!s->budget--) { s->failed_pc=0x0c07f4bcu; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c07f4be;
P_0c07f4be: /* original 66c3, guest PC 0x0c07f4be */
if(!s->budget--) { s->failed_pc=0x0c07f4beu; return 0; }
r[6]=r[12];
goto P_0c07f4c0;
P_0c07f4c0: /* original 6043, guest PC 0x0c07f4c0 */
if(!s->budget--) { s->failed_pc=0x0c07f4c0u; return 0; }
r[0]=r[4];
goto P_0c07f4c2;
P_0c07f4c2: /* original 4000, guest PC 0x0c07f4c2 */
if(!s->budget--) { s->failed_pc=0x0c07f4c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07f4c4;
P_0c07f4c4: /* original 001d, guest PC 0x0c07f4c4 */
if(!s->budget--) { s->failed_pc=0x0c07f4c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c07f4c6;
P_0c07f4c6: /* original 81f6, guest PC 0x0c07f4c6 */
if(!s->budget--) { s->failed_pc=0x0c07f4c6u; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c07f4c8;
P_0c07f4c8: /* original 9342, guest PC 0x0c07f4c8 */
if(!s->budget--) { s->failed_pc=0x0c07f4c8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f550u,2);
goto P_0c07f4ca;
P_0c07f4ca: /* original 1f34, guest PC 0x0c07f4ca */
if(!s->budget--) { s->failed_pc=0x0c07f4cau; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c07f4cc;
P_0c07f4cc: /* original 2fe6, guest PC 0x0c07f4cc */
if(!s->budget--) { s->failed_pc=0x0c07f4ccu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f4ce;
P_0c07f4ce: /* original 85f8, guest PC 0x0c07f4ce */
if(!s->budget--) { s->failed_pc=0x0c07f4ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c07f4d0;
P_0c07f4d0: /* original 1f03, guest PC 0x0c07f4d0 */
if(!s->budget--) { s->failed_pc=0x0c07f4d0u; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c07f4d2;
P_0c07f4d2: /* original 6503, guest PC 0x0c07f4d2 */
if(!s->budget--) { s->failed_pc=0x0c07f4d2u; return 0; }
r[5]=r[0];
goto P_0c07f4d4;
P_0c07f4d4: /* original 4d0b, guest PC 0x0c07f4d4 */
if(!s->budget--) { s->failed_pc=0x0c07f4d4u; return 0; }
target=r[13];
r[16]=code_base|0x0c07f4d8u;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f4d8u) { target=s->pc; goto dispatch; }
goto P_0c07f4d8;
P_0c07f4d6: /* original 54f5, guest PC 0x0c07f4d6 */
if(!s->budget--) { s->failed_pc=0x0c07f4d6u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c07f4d8;
P_0c07f4d8: /* original 933b, guest PC 0x0c07f4d8 */
if(!s->budget--) { s->failed_pc=0x0c07f4d8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f552u,2);
goto P_0c07f4da;
P_0c07f4da: /* original 66c3, guest PC 0x0c07f4da */
if(!s->budget--) { s->failed_pc=0x0c07f4dau; return 0; }
r[6]=r[12];
goto P_0c07f4dc;
P_0c07f4dc: /* original 67e3, guest PC 0x0c07f4dc */
if(!s->budget--) { s->failed_pc=0x0c07f4dcu; return 0; }
r[7]=r[14];
goto P_0c07f4de;
P_0c07f4de: /* original 1f34, guest PC 0x0c07f4de */
if(!s->budget--) { s->failed_pc=0x0c07f4deu; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c07f4e0;
P_0c07f4e0: /* original 2fe6, guest PC 0x0c07f4e0 */
if(!s->budget--) { s->failed_pc=0x0c07f4e0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f4e2;
P_0c07f4e2: /* original 55f4, guest PC 0x0c07f4e2 */
if(!s->budget--) { s->failed_pc=0x0c07f4e2u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c07f4e4;
P_0c07f4e4: /* original 4d0b, guest PC 0x0c07f4e4 */
if(!s->budget--) { s->failed_pc=0x0c07f4e4u; return 0; }
target=r[13];
r[16]=code_base|0x0c07f4e8u;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f4e8u) { target=s->pc; goto dispatch; }
goto P_0c07f4e8;
P_0c07f4e6: /* original 54f5, guest PC 0x0c07f4e6 */
if(!s->budget--) { s->failed_pc=0x0c07f4e6u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c07f4e8;
P_0c07f4e8: /* original 9834, guest PC 0x0c07f4e8 */
if(!s->budget--) { s->failed_pc=0x0c07f4e8u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f554u,2);
goto P_0c07f4ea;
P_0c07f4ea: /* original e302, guest PC 0x0c07f4ea */
if(!s->budget--) { s->failed_pc=0x0c07f4eau; return 0; }
r[3]=0x00000002u;
goto P_0c07f4ec;
P_0c07f4ec: /* original 7f10, guest PC 0x0c07f4ec */
if(!s->budget--) { s->failed_pc=0x0c07f4ecu; return 0; }
r[15]+=0x00000010u;
goto P_0c07f4ee;
P_0c07f4ee: /* original 1f32, guest PC 0x0c07f4ee */
if(!s->budget--) { s->failed_pc=0x0c07f4eeu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07f4f0;
P_0c07f4f0: /* original e901, guest PC 0x0c07f4f0 */
if(!s->budget--) { s->failed_pc=0x0c07f4f0u; return 0; }
r[9]=0x00000001u;
goto P_0c07f4f2;
P_0c07f4f2: /* original e206, guest PC 0x0c07f4f2 */
if(!s->budget--) { s->failed_pc=0x0c07f4f2u; return 0; }
r[2]=0x00000006u;
goto P_0c07f4f4;
P_0c07f4f4: /* original 2f22, guest PC 0x0c07f4f4 */
if(!s->budget--) { s->failed_pc=0x0c07f4f4u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c07f4f6;
P_0c07f4f6: /* original 6393, guest PC 0x0c07f4f6 */
if(!s->budget--) { s->failed_pc=0x0c07f4f6u; return 0; }
r[3]=r[9];
goto P_0c07f4f8;
P_0c07f4f8: /* original 4300, guest PC 0x0c07f4f8 */
if(!s->budget--) { s->failed_pc=0x0c07f4f8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07f4fa;
P_0c07f4fa: /* original 238b, guest PC 0x0c07f4fa */
if(!s->budget--) { s->failed_pc=0x0c07f4fau; return 0; }
r[3]|=r[8];
goto P_0c07f4fc;
P_0c07f4fc: /* original 66c3, guest PC 0x0c07f4fc */
if(!s->budget--) { s->failed_pc=0x0c07f4fcu; return 0; }
r[6]=r[12];
goto P_0c07f4fe;
P_0c07f4fe: /* original 1f31, guest PC 0x0c07f4fe */
if(!s->budget--) { s->failed_pc=0x0c07f4feu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07f500;
P_0c07f500: /* original e700, guest PC 0x0c07f500 */
if(!s->budget--) { s->failed_pc=0x0c07f500u; return 0; }
r[7]=0x00000000u;
goto P_0c07f502;
P_0c07f502: /* original 2fe6, guest PC 0x0c07f502 */
if(!s->budget--) { s->failed_pc=0x0c07f502u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f504;
P_0c07f504: /* original 9527, guest PC 0x0c07f504 */
if(!s->budget--) { s->failed_pc=0x0c07f504u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f556u,2);
goto P_0c07f506;
P_0c07f506: /* original 4d0b, guest PC 0x0c07f506 */
if(!s->budget--) { s->failed_pc=0x0c07f506u; return 0; }
target=r[13];
r[16]=code_base|0x0c07f50au;
r[4]=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f50au) { target=s->pc; goto dispatch; }
goto P_0c07f50a;
P_0c07f508: /* original 6433, guest PC 0x0c07f508 */
if(!s->budget--) { s->failed_pc=0x0c07f508u; return 0; }
r[4]=r[3];
goto P_0c07f50a;
P_0c07f50a: /* original 7f04, guest PC 0x0c07f50a */
if(!s->budget--) { s->failed_pc=0x0c07f50au; return 0; }
r[15]+=0x00000004u;
goto P_0c07f50c;
P_0c07f50c: /* original 62f2, guest PC 0x0c07f50c */
if(!s->budget--) { s->failed_pc=0x0c07f50cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07f50e;
P_0c07f50e: /* original 72ff, guest PC 0x0c07f50e */
if(!s->budget--) { s->failed_pc=0x0c07f50eu; return 0; }
r[2]+=0xffffffffu;
goto P_0c07f510;
P_0c07f510: /* original 4215, guest PC 0x0c07f510 */
if(!s->budget--) { s->failed_pc=0x0c07f510u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c07f512;
P_0c07f512: /* original 2f22, guest PC 0x0c07f512 */
if(!s->budget--) { s->failed_pc=0x0c07f512u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c07f514;
P_0c07f514: /* original 8def, guest PC 0x0c07f514 */
if(!s->budget--) { s->failed_pc=0x0c07f514u; return 0; }
cond=r[17]&1u;
r[9]+=0x00000004u;
if(cond) { goto P_0c07f4f6; }
goto P_0c07f518;
P_0c07f516: /* original 7904, guest PC 0x0c07f516 */
if(!s->budget--) { s->failed_pc=0x0c07f516u; return 0; }
r[9]+=0x00000004u;
goto P_0c07f518;
P_0c07f518: /* original 52f2, guest PC 0x0c07f518 */
if(!s->budget--) { s->failed_pc=0x0c07f518u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c07f51a;
P_0c07f51a: /* original e925, guest PC 0x0c07f51a */
if(!s->budget--) { s->failed_pc=0x0c07f51au; return 0; }
r[9]=0x00000025u;
goto P_0c07f51c;
P_0c07f51c: /* original 72ff, guest PC 0x0c07f51c */
if(!s->budget--) { s->failed_pc=0x0c07f51cu; return 0; }
r[2]+=0xffffffffu;
goto P_0c07f51e;
P_0c07f51e: /* original 2228, guest PC 0x0c07f51e */
if(!s->budget--) { s->failed_pc=0x0c07f51eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07f520;
P_0c07f520: /* original 8fe7, guest PC 0x0c07f520 */
if(!s->budget--) { s->failed_pc=0x0c07f520u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[2],4);
if(!cond) { goto P_0c07f4f2; }
goto P_0c07f524;
P_0c07f522: /* original 1f22, guest PC 0x0c07f522 */
if(!s->budget--) { s->failed_pc=0x0c07f522u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c07f524;
P_0c07f524: /* original 9018, guest PC 0x0c07f524 */
if(!s->budget--) { s->failed_pc=0x0c07f524u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f558u,2);
goto P_0c07f526;
P_0c07f526: /* original 2aa8, guest PC 0x0c07f526 */
if(!s->budget--) { s->failed_pc=0x0c07f526u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c07f528;
P_0c07f528: /* original 00bd, guest PC 0x0c07f528 */
if(!s->budget--) { s->failed_pc=0x0c07f528u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c07f52a;
P_0c07f52a: /* original 81f8, guest PC 0x0c07f52a */
if(!s->budget--) { s->failed_pc=0x0c07f52au; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c07f52c;
P_0c07f52c: /* original 8d50, guest PC 0x0c07f52c */
if(!s->budget--) { s->failed_pc=0x0c07f52cu; return 0; }
cond=r[17]&1u;
r[5]=r[10];
if(cond) { goto P_0c07f5d0; }
goto P_0c07f530;
P_0c07f52e: /* original 65a3, guest PC 0x0c07f52e */
if(!s->budget--) { s->failed_pc=0x0c07f52eu; return 0; }
r[5]=r[10];
goto P_0c07f530;
P_0c07f530: /* original e405, guest PC 0x0c07f530 */
if(!s->budget--) { s->failed_pc=0x0c07f530u; return 0; }
r[4]=0x00000005u;
goto P_0c07f532;
P_0c07f532: /* original 3a47, guest PC 0x0c07f532 */
if(!s->budget--) { s->failed_pc=0x0c07f532u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>(int32_t)r[4])!=0);
goto P_0c07f534;
P_0c07f534: /* original 8b00, guest PC 0x0c07f534 */
if(!s->budget--) { s->failed_pc=0x0c07f534u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07f538; }
goto P_0c07f536;
P_0c07f536: /* original 6543, guest PC 0x0c07f536 */
if(!s->budget--) { s->failed_pc=0x0c07f536u; return 0; }
r[5]=r[4];
goto P_0c07f538;
P_0c07f538: /* original e31f, guest PC 0x0c07f538 */
if(!s->budget--) { s->failed_pc=0x0c07f538u; return 0; }
r[3]=0x0000001fu;
goto P_0c07f53a;
P_0c07f53a: /* original 1f41, guest PC 0x0c07f53a */
if(!s->budget--) { s->failed_pc=0x0c07f53au; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c07f53c;
P_0c07f53c: /* original 1f32, guest PC 0x0c07f53c */
if(!s->budget--) { s->failed_pc=0x0c07f53cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07f53e;
P_0c07f53e: /* original a045, guest PC 0x0c07f53e */
if(!s->budget--) { s->failed_pc=0x0c07f53eu; return 0; }
r[9]=r[5];
goto P_0c07f5cc;
P_0c07f540: /* original 6953, guest PC 0x0c07f540 */
if(!s->budget--) { s->failed_pc=0x0c07f540u; return 0; }
r[9]=r[5];
if(!vf3_matrix_family(0x0c07f542u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07f542u; return 0; } return 1;
P_0c07f580: /* original 4915, guest PC 0x0c07f580 */
if(!s->budget--) { s->failed_pc=0x0c07f580u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>0)!=0);
goto P_0c07f582;
P_0c07f582: /* original 8f20, guest PC 0x0c07f582 */
if(!s->budget--) { s->failed_pc=0x0c07f582u; return 0; }
cond=r[17]&1u;
r[10]+=0xfffffffbu;
if(!cond) { goto P_0c07f5c6; }
goto P_0c07f586;
P_0c07f584: /* original 7afb, guest PC 0x0c07f584 */
if(!s->budget--) { s->failed_pc=0x0c07f584u; return 0; }
r[10]+=0xfffffffbu;
goto P_0c07f586;
P_0c07f586: /* original 932f, guest PC 0x0c07f586 */
if(!s->budget--) { s->failed_pc=0x0c07f586u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f5e8u,2);
goto P_0c07f588;
P_0c07f588: /* original 2f32, guest PC 0x0c07f588 */
if(!s->budget--) { s->failed_pc=0x0c07f588u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07f58a;
P_0c07f58a: /* original 53f2, guest PC 0x0c07f58a */
if(!s->budget--) { s->failed_pc=0x0c07f58au; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07f58c;
P_0c07f58c: /* original d218, guest PC 0x0c07f58c */
if(!s->budget--) { s->failed_pc=0x0c07f58cu; return 0; }
r[2]=read(ram,0x0c07f5f0u,4);
goto P_0c07f58e;
P_0c07f58e: /* original 85f8, guest PC 0x0c07f58e */
if(!s->budget--) { s->failed_pc=0x0c07f58eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c07f590;
P_0c07f590: /* original 633b, guest PC 0x0c07f590 */
if(!s->budget--) { s->failed_pc=0x0c07f590u; return 0; }
r[3]=0u-r[3];
goto P_0c07f592;
P_0c07f592: /* original 423d, guest PC 0x0c07f592 */
if(!s->budget--) { s->failed_pc=0x0c07f592u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c07f594;
P_0c07f594: /* original 2208, guest PC 0x0c07f594 */
if(!s->budget--) { s->failed_pc=0x0c07f594u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[0])==0)!=0);
goto P_0c07f596;
P_0c07f596: /* original 8901, guest PC 0x0c07f596 */
if(!s->budget--) { s->failed_pc=0x0c07f596u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07f59c; }
goto P_0c07f598;
P_0c07f598: /* original 9127, guest PC 0x0c07f598 */
if(!s->budget--) { s->failed_pc=0x0c07f598u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f5eau,2);
goto P_0c07f59a;
P_0c07f59a: /* original 2f12, guest PC 0x0c07f59a */
if(!s->budget--) { s->failed_pc=0x0c07f59au; return 0; }
write(ram,r[15],r[1],4);
goto P_0c07f59c;
P_0c07f59c: /* original 53f1, guest PC 0x0c07f59c */
if(!s->budget--) { s->failed_pc=0x0c07f59cu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07f59e;
P_0c07f59e: /* original e201, guest PC 0x0c07f59e */
if(!s->budget--) { s->failed_pc=0x0c07f59eu; return 0; }
r[2]=0x00000001u;
goto P_0c07f5a0;
P_0c07f5a0: /* original 66c3, guest PC 0x0c07f5a0 */
if(!s->budget--) { s->failed_pc=0x0c07f5a0u; return 0; }
r[6]=r[12];
goto P_0c07f5a2;
P_0c07f5a2: /* original e700, guest PC 0x0c07f5a2 */
if(!s->budget--) { s->failed_pc=0x0c07f5a2u; return 0; }
r[7]=0x00000000u;
goto P_0c07f5a4;
P_0c07f5a4: /* original 4300, guest PC 0x0c07f5a4 */
if(!s->budget--) { s->failed_pc=0x0c07f5a4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07f5a6;
P_0c07f5a6: /* original 238b, guest PC 0x0c07f5a6 */
if(!s->budget--) { s->failed_pc=0x0c07f5a6u; return 0; }
r[3]|=r[8];
goto P_0c07f5a8;
P_0c07f5a8: /* original 1f35, guest PC 0x0c07f5a8 */
if(!s->budget--) { s->failed_pc=0x0c07f5a8u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c07f5aa;
P_0c07f5aa: /* original 2f26, guest PC 0x0c07f5aa */
if(!s->budget--) { s->failed_pc=0x0c07f5aau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f5ac;
P_0c07f5ac: /* original 55f1, guest PC 0x0c07f5ac */
if(!s->budget--) { s->failed_pc=0x0c07f5acu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c07f5ae;
P_0c07f5ae: /* original 4d0b, guest PC 0x0c07f5ae */
if(!s->budget--) { s->failed_pc=0x0c07f5aeu; return 0; }
target=r[13];
r[16]=code_base|0x0c07f5b2u;
r[4]=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f5b2u) { target=s->pc; goto dispatch; }
goto P_0c07f5b2;
P_0c07f5b0: /* original 6433, guest PC 0x0c07f5b0 */
if(!s->budget--) { s->failed_pc=0x0c07f5b0u; return 0; }
r[4]=r[3];
goto P_0c07f5b2;
P_0c07f5b2: /* original 7f04, guest PC 0x0c07f5b2 */
if(!s->budget--) { s->failed_pc=0x0c07f5b2u; return 0; }
r[15]+=0x00000004u;
goto P_0c07f5b4;
P_0c07f5b4: /* original 53f1, guest PC 0x0c07f5b4 */
if(!s->budget--) { s->failed_pc=0x0c07f5b4u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07f5b6;
P_0c07f5b6: /* original 79ff, guest PC 0x0c07f5b6 */
if(!s->budget--) { s->failed_pc=0x0c07f5b6u; return 0; }
r[9]+=0xffffffffu;
goto P_0c07f5b8;
P_0c07f5b8: /* original 4915, guest PC 0x0c07f5b8 */
if(!s->budget--) { s->failed_pc=0x0c07f5b8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>0)!=0);
goto P_0c07f5ba;
P_0c07f5ba: /* original 7304, guest PC 0x0c07f5ba */
if(!s->budget--) { s->failed_pc=0x0c07f5bau; return 0; }
r[3]+=0x00000004u;
goto P_0c07f5bc;
P_0c07f5bc: /* original 1f31, guest PC 0x0c07f5bc */
if(!s->budget--) { s->failed_pc=0x0c07f5bcu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07f5be;
P_0c07f5be: /* original 52f2, guest PC 0x0c07f5be */
if(!s->budget--) { s->failed_pc=0x0c07f5beu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c07f5c0;
P_0c07f5c0: /* original 72ff, guest PC 0x0c07f5c0 */
if(!s->budget--) { s->failed_pc=0x0c07f5c0u; return 0; }
r[2]+=0xffffffffu;
goto P_0c07f5c2;
P_0c07f5c2: /* original 8de0, guest PC 0x0c07f5c2 */
if(!s->budget--) { s->failed_pc=0x0c07f5c2u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[2],4);
if(cond) { goto P_0c07f586; }
goto P_0c07f5c6;
P_0c07f5c4: /* original 1f22, guest PC 0x0c07f5c4 */
if(!s->budget--) { s->failed_pc=0x0c07f5c4u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c07f5c6;
P_0c07f5c6: /* original e325, guest PC 0x0c07f5c6 */
if(!s->budget--) { s->failed_pc=0x0c07f5c6u; return 0; }
r[3]=0x00000025u;
goto P_0c07f5c8;
P_0c07f5c8: /* original 69a3, guest PC 0x0c07f5c8 */
if(!s->budget--) { s->failed_pc=0x0c07f5c8u; return 0; }
r[9]=r[10];
goto P_0c07f5ca;
P_0c07f5ca: /* original 1f31, guest PC 0x0c07f5ca */
if(!s->budget--) { s->failed_pc=0x0c07f5cau; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07f5cc;
P_0c07f5cc: /* original 4a15, guest PC 0x0c07f5cc */
if(!s->budget--) { s->failed_pc=0x0c07f5ccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>0)!=0);
goto P_0c07f5ce;
P_0c07f5ce: /* original 89d7, guest PC 0x0c07f5ce */
if(!s->budget--) { s->failed_pc=0x0c07f5ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07f580; }
goto P_0c07f5d0;
P_0c07f5d0: /* original d308, guest PC 0x0c07f5d0 */
if(!s->budget--) { s->failed_pc=0x0c07f5d0u; return 0; }
r[3]=read(ram,0x0c07f5f4u,4);
goto P_0c07f5d2;
P_0c07f5d2: /* original 54f8, guest PC 0x0c07f5d2 */
if(!s->budget--) { s->failed_pc=0x0c07f5d2u; return 0; }
r[4]=read(ram,r[15]+32,4);
goto P_0c07f5d4;
P_0c07f5d4: /* original 430b, guest PC 0x0c07f5d4 */
if(!s->budget--) { s->failed_pc=0x0c07f5d4u; return 0; }
target=r[3];
r[16]=code_base|0x0c07f5d8u;
r[4]+=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f5d8u) { target=s->pc; goto dispatch; }
goto P_0c07f5d8;
P_0c07f5d6: /* original 7412, guest PC 0x0c07f5d6 */
if(!s->budget--) { s->failed_pc=0x0c07f5d6u; return 0; }
r[4]+=0x00000012u;
goto P_0c07f5d8;
P_0c07f5d8: /* original 640c, guest PC 0x0c07f5d8 */
if(!s->budget--) { s->failed_pc=0x0c07f5d8u; return 0; }
r[4]=r[0]&255u;
goto P_0c07f5da;
P_0c07f5da: /* original 2448, guest PC 0x0c07f5da */
if(!s->budget--) { s->failed_pc=0x0c07f5dau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07f5dc;
P_0c07f5dc: /* original 890c, guest PC 0x0c07f5dc */
if(!s->budget--) { s->failed_pc=0x0c07f5dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07f5f8; }
goto P_0c07f5de;
P_0c07f5de: /* original e700, guest PC 0x0c07f5de */
if(!s->budget--) { s->failed_pc=0x0c07f5deu; return 0; }
r[7]=0x00000000u;
goto P_0c07f5e0;
P_0c07f5e0: /* original 2fe6, guest PC 0x0c07f5e0 */
if(!s->budget--) { s->failed_pc=0x0c07f5e0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f5e2;
P_0c07f5e2: /* original 9503, guest PC 0x0c07f5e2 */
if(!s->budget--) { s->failed_pc=0x0c07f5e2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f5ecu,2);
goto P_0c07f5e4;
P_0c07f5e4: /* original a00c, guest PC 0x0c07f5e4 */
if(!s->budget--) { s->failed_pc=0x0c07f5e4u; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c07f600;
P_0c07f5e6: /* original 56f4, guest PC 0x0c07f5e6 */
if(!s->budget--) { s->failed_pc=0x0c07f5e6u; return 0; }
r[6]=read(ram,r[15]+16,4);
if(!vf3_matrix_family(0x0c07f5e8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07f5e8u; return 0; } return 1;
P_0c07f5f8: /* original 2fe6, guest PC 0x0c07f5f8 */
if(!s->budget--) { s->failed_pc=0x0c07f5f8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f5fa;
P_0c07f5fa: /* original e700, guest PC 0x0c07f5fa */
if(!s->budget--) { s->failed_pc=0x0c07f5fau; return 0; }
r[7]=0x00000000u;
goto P_0c07f5fc;
P_0c07f5fc: /* original 56f4, guest PC 0x0c07f5fc */
if(!s->budget--) { s->failed_pc=0x0c07f5fcu; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c07f5fe;
P_0c07f5fe: /* original 957a, guest PC 0x0c07f5fe */
if(!s->budget--) { s->failed_pc=0x0c07f5feu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f6f6u,2);
goto P_0c07f600;
P_0c07f600: /* original 4d0b, guest PC 0x0c07f600 */
if(!s->budget--) { s->failed_pc=0x0c07f600u; return 0; }
target=r[13];
r[16]=code_base|0x0c07f604u;
r[4]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f604u) { target=s->pc; goto dispatch; }
goto P_0c07f604;
P_0c07f602: /* original 6473, guest PC 0x0c07f602 */
if(!s->budget--) { s->failed_pc=0x0c07f602u; return 0; }
r[4]=r[7];
goto P_0c07f604;
P_0c07f604: /* original 9a78, guest PC 0x0c07f604 */
if(!s->budget--) { s->failed_pc=0x0c07f604u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f6f8u,2);
goto P_0c07f606;
P_0c07f606: /* original e700, guest PC 0x0c07f606 */
if(!s->budget--) { s->failed_pc=0x0c07f606u; return 0; }
r[7]=0x00000000u;
goto P_0c07f608;
P_0c07f608: /* original 2fe6, guest PC 0x0c07f608 */
if(!s->budget--) { s->failed_pc=0x0c07f608u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f60a;
P_0c07f60a: /* original 56f5, guest PC 0x0c07f60a */
if(!s->budget--) { s->failed_pc=0x0c07f60au; return 0; }
r[6]=read(ram,r[15]+20,4);
goto P_0c07f60c;
P_0c07f60c: /* original 9575, guest PC 0x0c07f60c */
if(!s->budget--) { s->failed_pc=0x0c07f60cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f6fau,2);
goto P_0c07f60e;
P_0c07f60e: /* original 4d0b, guest PC 0x0c07f60e */
if(!s->budget--) { s->failed_pc=0x0c07f60eu; return 0; }
target=r[13];
r[16]=code_base|0x0c07f612u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f612u) { target=s->pc; goto dispatch; }
goto P_0c07f612;
P_0c07f610: /* original 64a3, guest PC 0x0c07f610 */
if(!s->budget--) { s->failed_pc=0x0c07f610u; return 0; }
r[4]=r[10];
goto P_0c07f612;
P_0c07f612: /* original 9073, guest PC 0x0c07f612 */
if(!s->budget--) { s->failed_pc=0x0c07f612u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f6fcu,2);
goto P_0c07f614;
P_0c07f614: /* original 7f08, guest PC 0x0c07f614 */
if(!s->budget--) { s->failed_pc=0x0c07f614u; return 0; }
r[15]+=0x00000008u;
goto P_0c07f616;
P_0c07f616: /* original d33b, guest PC 0x0c07f616 */
if(!s->budget--) { s->failed_pc=0x0c07f616u; return 0; }
r[3]=read(ram,0x0c07f704u,4);
goto P_0c07f618;
P_0c07f618: /* original e70a, guest PC 0x0c07f618 */
if(!s->budget--) { s->failed_pc=0x0c07f618u; return 0; }
r[7]=0x0000000au;
goto P_0c07f61a;
P_0c07f61a: /* original 05bd, guest PC 0x0c07f61a */
if(!s->budget--) { s->failed_pc=0x0c07f61au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c07f61c;
P_0c07f61c: /* original 7012, guest PC 0x0c07f61c */
if(!s->budget--) { s->failed_pc=0x0c07f61cu; return 0; }
r[0]+=0x00000012u;
goto P_0c07f61e;
P_0c07f61e: /* original 0cbd, guest PC 0x0c07f61e */
if(!s->budget--) { s->failed_pc=0x0c07f61eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c07f620;
P_0c07f620: /* original 615f, guest PC 0x0c07f620 */
if(!s->budget--) { s->failed_pc=0x0c07f620u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c07f622;
P_0c07f622: /* original 430b, guest PC 0x0c07f622 */
if(!s->budget--) { s->failed_pc=0x0c07f622u; return 0; }
target=r[3];
r[16]=code_base|0x0c07f626u;
r[0]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f626u) { target=s->pc; goto dispatch; }
goto P_0c07f626;
P_0c07f624: /* original 6073, guest PC 0x0c07f624 */
if(!s->budget--) { s->failed_pc=0x0c07f624u; return 0; }
r[0]=r[7];
goto P_0c07f626;
P_0c07f626: /* original 6603, guest PC 0x0c07f626 */
if(!s->budget--) { s->failed_pc=0x0c07f626u; return 0; }
r[6]=r[0];
goto P_0c07f628;
P_0c07f628: /* original 4608, guest PC 0x0c07f628 */
if(!s->budget--) { s->failed_pc=0x0c07f628u; return 0; }
r[6]<<=2;
goto P_0c07f62a;
P_0c07f62a: /* original 6303, guest PC 0x0c07f62a */
if(!s->budget--) { s->failed_pc=0x0c07f62au; return 0; }
r[3]=r[0];
goto P_0c07f62c;
P_0c07f62c: /* original 363c, guest PC 0x0c07f62c */
if(!s->budget--) { s->failed_pc=0x0c07f62cu; return 0; }
r[6]+=r[3];
goto P_0c07f62e;
P_0c07f62e: /* original 6d53, guest PC 0x0c07f62e */
if(!s->budget--) { s->failed_pc=0x0c07f62eu; return 0; }
r[13]=r[5];
goto P_0c07f630;
P_0c07f630: /* original d334, guest PC 0x0c07f630 */
if(!s->budget--) { s->failed_pc=0x0c07f630u; return 0; }
r[3]=read(ram,0x0c07f704u,4);
goto P_0c07f632;
P_0c07f632: /* original 6403, guest PC 0x0c07f632 */
if(!s->budget--) { s->failed_pc=0x0c07f632u; return 0; }
r[4]=r[0];
goto P_0c07f634;
P_0c07f634: /* original 4600, guest PC 0x0c07f634 */
if(!s->budget--) { s->failed_pc=0x0c07f634u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c07f636;
P_0c07f636: /* original 614f, guest PC 0x0c07f636 */
if(!s->budget--) { s->failed_pc=0x0c07f636u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c07f638;
P_0c07f638: /* original 3d68, guest PC 0x0c07f638 */
if(!s->budget--) { s->failed_pc=0x0c07f638u; return 0; }
r[13]-=r[6];
goto P_0c07f63a;
P_0c07f63a: /* original 430b, guest PC 0x0c07f63a */
if(!s->budget--) { s->failed_pc=0x0c07f63au; return 0; }
target=r[3];
r[16]=code_base|0x0c07f63eu;
r[0]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f63eu) { target=s->pc; goto dispatch; }
goto P_0c07f63e;
P_0c07f63c: /* original 6073, guest PC 0x0c07f63c */
if(!s->budget--) { s->failed_pc=0x0c07f63cu; return 0; }
r[0]=r[7];
goto P_0c07f63e;
P_0c07f63e: /* original 6603, guest PC 0x0c07f63e */
if(!s->budget--) { s->failed_pc=0x0c07f63eu; return 0; }
r[6]=r[0];
goto P_0c07f640;
P_0c07f640: /* original 4608, guest PC 0x0c07f640 */
if(!s->budget--) { s->failed_pc=0x0c07f640u; return 0; }
r[6]<<=2;
goto P_0c07f642;
P_0c07f642: /* original 6303, guest PC 0x0c07f642 */
if(!s->budget--) { s->failed_pc=0x0c07f642u; return 0; }
r[3]=r[0];
goto P_0c07f644;
P_0c07f644: /* original 363c, guest PC 0x0c07f644 */
if(!s->budget--) { s->failed_pc=0x0c07f644u; return 0; }
r[6]+=r[3];
goto P_0c07f646;
P_0c07f646: /* original d32f, guest PC 0x0c07f646 */
if(!s->budget--) { s->failed_pc=0x0c07f646u; return 0; }
r[3]=read(ram,0x0c07f704u,4);
goto P_0c07f648;
P_0c07f648: /* original 4600, guest PC 0x0c07f648 */
if(!s->budget--) { s->failed_pc=0x0c07f648u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c07f64a;
P_0c07f64a: /* original 6503, guest PC 0x0c07f64a */
if(!s->budget--) { s->failed_pc=0x0c07f64au; return 0; }
r[5]=r[0];
goto P_0c07f64c;
P_0c07f64c: /* original 615f, guest PC 0x0c07f64c */
if(!s->budget--) { s->failed_pc=0x0c07f64cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c07f64e;
P_0c07f64e: /* original 3468, guest PC 0x0c07f64e */
if(!s->budget--) { s->failed_pc=0x0c07f64eu; return 0; }
r[4]-=r[6];
goto P_0c07f650;
P_0c07f650: /* original 430b, guest PC 0x0c07f650 */
if(!s->budget--) { s->failed_pc=0x0c07f650u; return 0; }
target=r[3];
r[16]=code_base|0x0c07f654u;
r[0]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f654u) { target=s->pc; goto dispatch; }
goto P_0c07f654;
P_0c07f652: /* original 6073, guest PC 0x0c07f652 */
if(!s->budget--) { s->failed_pc=0x0c07f652u; return 0; }
r[0]=r[7];
goto P_0c07f654;
P_0c07f654: /* original 6203, guest PC 0x0c07f654 */
if(!s->budget--) { s->failed_pc=0x0c07f654u; return 0; }
r[2]=r[0];
goto P_0c07f656;
P_0c07f656: /* original 4208, guest PC 0x0c07f656 */
if(!s->budget--) { s->failed_pc=0x0c07f656u; return 0; }
r[2]<<=2;
goto P_0c07f658;
P_0c07f658: /* original 6303, guest PC 0x0c07f658 */
if(!s->budget--) { s->failed_pc=0x0c07f658u; return 0; }
r[3]=r[0];
goto P_0c07f65a;
P_0c07f65a: /* original 323c, guest PC 0x0c07f65a */
if(!s->budget--) { s->failed_pc=0x0c07f65au; return 0; }
r[2]+=r[3];
goto P_0c07f65c;
P_0c07f65c: /* original 4200, guest PC 0x0c07f65c */
if(!s->budget--) { s->failed_pc=0x0c07f65cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07f65e;
P_0c07f65e: /* original 6603, guest PC 0x0c07f65e */
if(!s->budget--) { s->failed_pc=0x0c07f65eu; return 0; }
r[6]=r[0];
goto P_0c07f660;
P_0c07f660: /* original 61cf, guest PC 0x0c07f660 */
if(!s->budget--) { s->failed_pc=0x0c07f660u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c07f662;
P_0c07f662: /* original 2f21, guest PC 0x0c07f662 */
if(!s->budget--) { s->failed_pc=0x0c07f662u; return 0; }
write(ram,r[15],r[2],2);
goto P_0c07f664;
P_0c07f664: /* original d327, guest PC 0x0c07f664 */
if(!s->budget--) { s->failed_pc=0x0c07f664u; return 0; }
r[3]=read(ram,0x0c07f704u,4);
goto P_0c07f666;
P_0c07f666: /* original 3528, guest PC 0x0c07f666 */
if(!s->budget--) { s->failed_pc=0x0c07f666u; return 0; }
r[5]-=r[2];
goto P_0c07f668;
P_0c07f668: /* original 430b, guest PC 0x0c07f668 */
if(!s->budget--) { s->failed_pc=0x0c07f668u; return 0; }
target=r[3];
r[16]=code_base|0x0c07f66cu;
r[0]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07f66cu) { target=s->pc; goto dispatch; }
goto P_0c07f66c;
P_0c07f66a: /* original 6073, guest PC 0x0c07f66a */
if(!s->budget--) { s->failed_pc=0x0c07f66au; return 0; }
r[0]=r[7];
goto P_0c07f66c;
P_0c07f66c: /* original 6103, guest PC 0x0c07f66c */
if(!s->budget--) { s->failed_pc=0x0c07f66cu; return 0; }
r[1]=r[0];
goto P_0c07f66e;
P_0c07f66e: /* original 4108, guest PC 0x0c07f66e */
if(!s->budget--) { s->failed_pc=0x0c07f66eu; return 0; }
r[1]<<=2;
goto P_0c07f670;
P_0c07f670: /* original 6303, guest PC 0x0c07f670 */
if(!s->budget--) { s->failed_pc=0x0c07f670u; return 0; }
r[3]=r[0];
goto P_0c07f672;
P_0c07f672: /* original 313c, guest PC 0x0c07f672 */
if(!s->budget--) { s->failed_pc=0x0c07f672u; return 0; }
r[1]+=r[3];
goto P_0c07f674;
P_0c07f674: /* original 4100, guest PC 0x0c07f674 */
if(!s->budget--) { s->failed_pc=0x0c07f674u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c07f676;
P_0c07f676: /* original 6703, guest PC 0x0c07f676 */
if(!s->budget--) { s->failed_pc=0x0c07f676u; return 0; }
r[7]=r[0];
goto P_0c07f678;
P_0c07f678: /* original 636f, guest PC 0x0c07f678 */
if(!s->budget--) { s->failed_pc=0x0c07f678u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c07f67a;
P_0c07f67a: /* original 3c18, guest PC 0x0c07f67a */
if(!s->budget--) { s->failed_pc=0x0c07f67au; return 0; }
r[12]-=r[1];
goto P_0c07f67c;
P_0c07f67c: /* original 2338, guest PC 0x0c07f67c */
if(!s->budget--) { s->failed_pc=0x0c07f67cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07f67e;
P_0c07f67e: /* original 2fc1, guest PC 0x0c07f67e */
if(!s->budget--) { s->failed_pc=0x0c07f67eu; return 0; }
write(ram,r[15],r[12],2);
goto P_0c07f680;
P_0c07f680: /* original 8b11, guest PC 0x0c07f680 */
if(!s->budget--) { s->failed_pc=0x0c07f680u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07f6a6; }
goto P_0c07f682;
P_0c07f682: /* original 635f, guest PC 0x0c07f682 */
if(!s->budget--) { s->failed_pc=0x0c07f682u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c07f684;
P_0c07f684: /* original 9c3b, guest PC 0x0c07f684 */
if(!s->budget--) { s->failed_pc=0x0c07f684u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f6feu,2);
goto P_0c07f686;
P_0c07f686: /* original 2338, guest PC 0x0c07f686 */
if(!s->budget--) { s->failed_pc=0x0c07f686u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07f688;
P_0c07f688: /* original 8f0d, guest PC 0x0c07f688 */
if(!s->budget--) { s->failed_pc=0x0c07f688u; return 0; }
cond=r[17]&1u;
r[6]=r[12];
if(!cond) { goto P_0c07f6a6; }
goto P_0c07f68c;
P_0c07f68a: /* original 66c3, guest PC 0x0c07f68a */
if(!s->budget--) { s->failed_pc=0x0c07f68au; return 0; }
r[6]=r[12];
goto P_0c07f68c;
P_0c07f68c: /* original 634f, guest PC 0x0c07f68c */
if(!s->budget--) { s->failed_pc=0x0c07f68cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c07f68e;
P_0c07f68e: /* original 2338, guest PC 0x0c07f68e */
if(!s->budget--) { s->failed_pc=0x0c07f68eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07f690;
P_0c07f690: /* original 8f09, guest PC 0x0c07f690 */
if(!s->budget--) { s->failed_pc=0x0c07f690u; return 0; }
cond=r[17]&1u;
r[5]=r[12];
if(!cond) { goto P_0c07f6a6; }
goto P_0c07f694;
P_0c07f692: /* original 65c3, guest PC 0x0c07f692 */
if(!s->budget--) { s->failed_pc=0x0c07f692u; return 0; }
r[5]=r[12];
goto P_0c07f694;
P_0c07f694: /* original 63df, guest PC 0x0c07f694 */
if(!s->budget--) { s->failed_pc=0x0c07f694u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c07f696;
P_0c07f696: /* original 2338, guest PC 0x0c07f696 */
if(!s->budget--) { s->failed_pc=0x0c07f696u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07f698;
P_0c07f698: /* original 8f05, guest PC 0x0c07f698 */
if(!s->budget--) { s->failed_pc=0x0c07f698u; return 0; }
cond=r[17]&1u;
r[4]=r[12];
if(!cond) { goto P_0c07f6a6; }
goto P_0c07f69c;
P_0c07f69a: /* original 64c3, guest PC 0x0c07f69a */
if(!s->budget--) { s->failed_pc=0x0c07f69au; return 0; }
r[4]=r[12];
goto P_0c07f69c;
P_0c07f69c: /* original 637f, guest PC 0x0c07f69c */
if(!s->budget--) { s->failed_pc=0x0c07f69cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[7];
goto P_0c07f69e;
P_0c07f69e: /* original 2338, guest PC 0x0c07f69e */
if(!s->budget--) { s->failed_pc=0x0c07f69eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07f6a0;
P_0c07f6a0: /* original 8f01, guest PC 0x0c07f6a0 */
if(!s->budget--) { s->failed_pc=0x0c07f6a0u; return 0; }
cond=r[17]&1u;
r[13]=r[12];
if(!cond) { goto P_0c07f6a6; }
goto P_0c07f6a4;
P_0c07f6a2: /* original 6dc3, guest PC 0x0c07f6a2 */
if(!s->budget--) { s->failed_pc=0x0c07f6a2u; return 0; }
r[13]=r[12];
goto P_0c07f6a4;
P_0c07f6a4: /* original 67c3, guest PC 0x0c07f6a4 */
if(!s->budget--) { s->failed_pc=0x0c07f6a4u; return 0; }
r[7]=r[12];
goto P_0c07f6a6;
P_0c07f6a6: /* original 902b, guest PC 0x0c07f6a6 */
if(!s->budget--) { s->failed_pc=0x0c07f6a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f700u,2);
goto P_0c07f6a8;
P_0c07f6a8: /* original 63f0, guest PC 0x0c07f6a8 */
if(!s->budget--) { s->failed_pc=0x0c07f6a8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[3]=tmp;
goto P_0c07f6aa;
P_0c07f6aa: /* original 0b34, guest PC 0x0c07f6aa */
if(!s->budget--) { s->failed_pc=0x0c07f6aau; return 0; }
write(ram,r[11]+r[0],r[3],1);
goto P_0c07f6ac;
P_0c07f6ac: /* original 7001, guest PC 0x0c07f6ac */
if(!s->budget--) { s->failed_pc=0x0c07f6acu; return 0; }
r[0]+=0x00000001u;
goto P_0c07f6ae;
P_0c07f6ae: /* original 0b74, guest PC 0x0c07f6ae */
if(!s->budget--) { s->failed_pc=0x0c07f6aeu; return 0; }
write(ram,r[11]+r[0],r[7],1);
goto P_0c07f6b0;
P_0c07f6b0: /* original 7001, guest PC 0x0c07f6b0 */
if(!s->budget--) { s->failed_pc=0x0c07f6b0u; return 0; }
r[0]+=0x00000001u;
goto P_0c07f6b2;
P_0c07f6b2: /* original 0bd4, guest PC 0x0c07f6b2 */
if(!s->budget--) { s->failed_pc=0x0c07f6b2u; return 0; }
write(ram,r[11]+r[0],r[13],1);
goto P_0c07f6b4;
P_0c07f6b4: /* original 7001, guest PC 0x0c07f6b4 */
if(!s->budget--) { s->failed_pc=0x0c07f6b4u; return 0; }
r[0]+=0x00000001u;
goto P_0c07f6b6;
P_0c07f6b6: /* original 0b44, guest PC 0x0c07f6b6 */
if(!s->budget--) { s->failed_pc=0x0c07f6b6u; return 0; }
write(ram,r[11]+r[0],r[4],1);
goto P_0c07f6b8;
P_0c07f6b8: /* original 7001, guest PC 0x0c07f6b8 */
if(!s->budget--) { s->failed_pc=0x0c07f6b8u; return 0; }
r[0]+=0x00000001u;
goto P_0c07f6ba;
P_0c07f6ba: /* original 0b54, guest PC 0x0c07f6ba */
if(!s->budget--) { s->failed_pc=0x0c07f6bau; return 0; }
write(ram,r[11]+r[0],r[5],1);
goto P_0c07f6bc;
P_0c07f6bc: /* original 7001, guest PC 0x0c07f6bc */
if(!s->budget--) { s->failed_pc=0x0c07f6bcu; return 0; }
r[0]+=0x00000001u;
goto P_0c07f6be;
P_0c07f6be: /* original 0b64, guest PC 0x0c07f6be */
if(!s->budget--) { s->failed_pc=0x0c07f6beu; return 0; }
write(ram,r[11]+r[0],r[6],1);
goto P_0c07f6c0;
P_0c07f6c0: /* original 70f9, guest PC 0x0c07f6c0 */
if(!s->budget--) { s->failed_pc=0x0c07f6c0u; return 0; }
r[0]+=0xfffffff9u;
goto P_0c07f6c2;
P_0c07f6c2: /* original 0be4, guest PC 0x0c07f6c2 */
if(!s->budget--) { s->failed_pc=0x0c07f6c2u; return 0; }
write(ram,r[11]+r[0],r[14],1);
goto P_0c07f6c4;
P_0c07f6c4: /* original 7001, guest PC 0x0c07f6c4 */
if(!s->budget--) { s->failed_pc=0x0c07f6c4u; return 0; }
r[0]+=0x00000001u;
goto P_0c07f6c6;
P_0c07f6c6: /* original 0be4, guest PC 0x0c07f6c6 */
if(!s->budget--) { s->failed_pc=0x0c07f6c6u; return 0; }
write(ram,r[11]+r[0],r[14],1);
goto P_0c07f6c8;
P_0c07f6c8: /* original 7008, guest PC 0x0c07f6c8 */
if(!s->budget--) { s->failed_pc=0x0c07f6c8u; return 0; }
r[0]+=0x00000008u;
goto P_0c07f6ca;
P_0c07f6ca: /* original e301, guest PC 0x0c07f6ca */
if(!s->budget--) { s->failed_pc=0x0c07f6cau; return 0; }
r[3]=0x00000001u;
goto P_0c07f6cc;
P_0c07f6cc: /* original 65a3, guest PC 0x0c07f6cc */
if(!s->budget--) { s->failed_pc=0x0c07f6ccu; return 0; }
r[5]=r[10];
goto P_0c07f6ce;
P_0c07f6ce: /* original 0b34, guest PC 0x0c07f6ce */
if(!s->budget--) { s->failed_pc=0x0c07f6ceu; return 0; }
write(ram,r[11]+r[0],r[3],1);
goto P_0c07f6d0;
P_0c07f6d0: /* original d30d, guest PC 0x0c07f6d0 */
if(!s->budget--) { s->failed_pc=0x0c07f6d0u; return 0; }
r[3]=read(ram,0x0c07f708u,4);
goto P_0c07f6d2;
P_0c07f6d2: /* original 52f7, guest PC 0x0c07f6d2 */
if(!s->budget--) { s->failed_pc=0x0c07f6d2u; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c07f6d4;
P_0c07f6d4: /* original 1234, guest PC 0x0c07f6d4 */
if(!s->budget--) { s->failed_pc=0x0c07f6d4u; return 0; }
write(ram,r[2]+16,r[3],4);
goto P_0c07f6d6;
P_0c07f6d6: /* original d20d, guest PC 0x0c07f6d6 */
if(!s->budget--) { s->failed_pc=0x0c07f6d6u; return 0; }
r[2]=read(ram,0x0c07f70cu,4);
goto P_0c07f6d8;
P_0c07f6d8: /* original 6120, guest PC 0x0c07f6d8 */
if(!s->budget--) { s->failed_pc=0x0c07f6d8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c07f6da;
P_0c07f6da: /* original 7101, guest PC 0x0c07f6da */
if(!s->budget--) { s->failed_pc=0x0c07f6dau; return 0; }
r[1]+=0x00000001u;
goto P_0c07f6dc;
P_0c07f6dc: /* original 2210, guest PC 0x0c07f6dc */
if(!s->budget--) { s->failed_pc=0x0c07f6dcu; return 0; }
write(ram,r[2],r[1],1);
goto P_0c07f6de;
P_0c07f6de: /* original 54f6, guest PC 0x0c07f6de */
if(!s->budget--) { s->failed_pc=0x0c07f6deu; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c07f6e0;
P_0c07f6e0: /* original 7f24, guest PC 0x0c07f6e0 */
if(!s->budget--) { s->failed_pc=0x0c07f6e0u; return 0; }
r[15]+=0x00000024u;
goto P_0c07f6e2;
P_0c07f6e2: /* original 4f26, guest PC 0x0c07f6e2 */
if(!s->budget--) { s->failed_pc=0x0c07f6e2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07f6e4;
P_0c07f6e4: /* original 68f6, guest PC 0x0c07f6e4 */
if(!s->budget--) { s->failed_pc=0x0c07f6e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c07f6e6;
P_0c07f6e6: /* original 69f6, guest PC 0x0c07f6e6 */
if(!s->budget--) { s->failed_pc=0x0c07f6e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07f6e8;
P_0c07f6e8: /* original d309, guest PC 0x0c07f6e8 */
if(!s->budget--) { s->failed_pc=0x0c07f6e8u; return 0; }
r[3]=read(ram,0x0c07f710u,4);
goto P_0c07f6ea;
P_0c07f6ea: /* original 6af6, guest PC 0x0c07f6ea */
if(!s->budget--) { s->failed_pc=0x0c07f6eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07f6ec;
P_0c07f6ec: /* original 6bf6, guest PC 0x0c07f6ec */
if(!s->budget--) { s->failed_pc=0x0c07f6ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07f6ee;
P_0c07f6ee: /* original 6cf6, guest PC 0x0c07f6ee */
if(!s->budget--) { s->failed_pc=0x0c07f6eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07f6f0;
P_0c07f6f0: /* original 6df6, guest PC 0x0c07f6f0 */
if(!s->budget--) { s->failed_pc=0x0c07f6f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07f6f2;
P_0c07f6f2: /* original 432b, guest PC 0x0c07f6f2 */
if(!s->budget--) { s->failed_pc=0x0c07f6f2u; return 0; }
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
P_0c07f6f4: /* original 6ef6, guest PC 0x0c07f6f4 */
if(!s->budget--) { s->failed_pc=0x0c07f6f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07f6f6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07f6f6u; return 0; } return 1;
P_0c080920: /* original 2fe6, guest PC 0x0c080920 */
if(!s->budget--) { s->failed_pc=0x0c080920u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080922;
P_0c080922: /* original 2fd6, guest PC 0x0c080922 */
if(!s->budget--) { s->failed_pc=0x0c080922u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080924;
P_0c080924: /* original 2fc6, guest PC 0x0c080924 */
if(!s->budget--) { s->failed_pc=0x0c080924u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080926;
P_0c080926: /* original 2fb6, guest PC 0x0c080926 */
if(!s->budget--) { s->failed_pc=0x0c080926u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080928;
P_0c080928: /* original 2fa6, guest PC 0x0c080928 */
if(!s->budget--) { s->failed_pc=0x0c080928u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08092a;
P_0c08092a: /* original 2f96, guest PC 0x0c08092a */
if(!s->budget--) { s->failed_pc=0x0c08092au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08092c;
P_0c08092c: /* original 2f86, guest PC 0x0c08092c */
if(!s->budget--) { s->failed_pc=0x0c08092cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08092e;
P_0c08092e: /* original d44d, guest PC 0x0c08092e */
if(!s->budget--) { s->failed_pc=0x0c08092eu; return 0; }
r[4]=read(ram,0x0c080a64u,4);
goto P_0c080930;
P_0c080930: /* original 4f22, guest PC 0x0c080930 */
if(!s->budget--) { s->failed_pc=0x0c080930u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c080932;
P_0c080932: /* original d54a, guest PC 0x0c080932 */
if(!s->budget--) { s->failed_pc=0x0c080932u; return 0; }
r[5]=read(ram,0x0c080a5cu,4);
goto P_0c080934;
P_0c080934: /* original 5344, guest PC 0x0c080934 */
if(!s->budget--) { s->failed_pc=0x0c080934u; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c080936;
P_0c080936: /* original 6d53, guest PC 0x0c080936 */
if(!s->budget--) { s->failed_pc=0x0c080936u; return 0; }
r[13]=r[5];
goto P_0c080938;
P_0c080938: /* original 7fe0, guest PC 0x0c080938 */
if(!s->budget--) { s->failed_pc=0x0c080938u; return 0; }
r[15]+=0xffffffe0u;
goto P_0c08093a;
P_0c08093a: /* original dc49, guest PC 0x0c08093a */
if(!s->budget--) { s->failed_pc=0x0c08093au; return 0; }
r[12]=read(ram,0x0c080a60u,4);
goto P_0c08093c;
P_0c08093c: /* original 1f37, guest PC 0x0c08093c */
if(!s->budget--) { s->failed_pc=0x0c08093cu; return 0; }
write(ram,r[15]+28,r[3],4);
goto P_0c08093e;
P_0c08093e: /* original e304, guest PC 0x0c08093e */
if(!s->budget--) { s->failed_pc=0x0c08093eu; return 0; }
r[3]=0x00000004u;
goto P_0c080940;
P_0c080940: /* original 5245, guest PC 0x0c080940 */
if(!s->budget--) { s->failed_pc=0x0c080940u; return 0; }
r[2]=read(ram,r[4]+20,4);
goto P_0c080942;
P_0c080942: /* original 1f26, guest PC 0x0c080942 */
if(!s->budget--) { s->failed_pc=0x0c080942u; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c080944;
P_0c080944: /* original 54d2, guest PC 0x0c080944 */
if(!s->budget--) { s->failed_pc=0x0c080944u; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c080946;
P_0c080946: /* original da49, guest PC 0x0c080946 */
if(!s->budget--) { s->failed_pc=0x0c080946u; return 0; }
r[10]=read(ram,0x0c080a6cu,4);
goto P_0c080948;
P_0c080948: /* original db49, guest PC 0x0c080948 */
if(!s->budget--) { s->failed_pc=0x0c080948u; return 0; }
r[11]=read(ram,0x0c080a70u,4);
goto P_0c08094a;
P_0c08094a: /* original 2438, guest PC 0x0c08094a */
if(!s->budget--) { s->failed_pc=0x0c08094au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c08094c;
P_0c08094c: /* original d946, guest PC 0x0c08094c */
if(!s->budget--) { s->failed_pc=0x0c08094cu; return 0; }
r[9]=read(ram,0x0c080a68u,4);
goto P_0c08094e;
P_0c08094e: /* original 8f02, guest PC 0x0c08094e */
if(!s->budget--) { s->failed_pc=0x0c08094eu; return 0; }
cond=r[17]&1u;
r[14]=0x00000000u;
if(!cond) { goto P_0c080956; }
goto P_0c080952;
P_0c080950: /* original ee00, guest PC 0x0c080950 */
if(!s->budget--) { s->failed_pc=0x0c080950u; return 0; }
r[14]=0x00000000u;
goto P_0c080952;
P_0c080952: /* original a08f, guest PC 0x0c080952 */
if(!s->budget--) { s->failed_pc=0x0c080952u; return 0; }
goto P_0c080a74;
P_0c080954: /* original 0009, guest PC 0x0c080954 */
if(!s->budget--) { s->failed_pc=0x0c080954u; return 0; }
goto P_0c080956;
P_0c080956: /* original 907e, guest PC 0x0c080956 */
if(!s->budget--) { s->failed_pc=0x0c080956u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080a56u,2);
goto P_0c080958;
P_0c080958: /* original 68e3, guest PC 0x0c080958 */
if(!s->budget--) { s->failed_pc=0x0c080958u; return 0; }
r[8]=r[14];
goto P_0c08095a;
P_0c08095a: /* original 04dc, guest PC 0x0c08095a */
if(!s->budget--) { s->failed_pc=0x0c08095au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08095c;
P_0c08095c: /* original e01b, guest PC 0x0c08095c */
if(!s->budget--) { s->failed_pc=0x0c08095cu; return 0; }
r[0]=0x0000001bu;
goto P_0c08095e;
P_0c08095e: /* original 02dc, guest PC 0x0c08095e */
if(!s->budget--) { s->failed_pc=0x0c08095eu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c080960;
P_0c080960: /* original e014, guest PC 0x0c080960 */
if(!s->budget--) { s->failed_pc=0x0c080960u; return 0; }
r[0]=0x00000014u;
goto P_0c080962;
P_0c080962: /* original 0f24, guest PC 0x0c080962 */
if(!s->budget--) { s->failed_pc=0x0c080962u; return 0; }
write(ram,r[15]+r[0],r[2],1);
goto P_0c080964;
P_0c080964: /* original 6243, guest PC 0x0c080964 */
if(!s->budget--) { s->failed_pc=0x0c080964u; return 0; }
r[2]=r[4];
goto P_0c080966;
P_0c080966: /* original 61b2, guest PC 0x0c080966 */
if(!s->budget--) { s->failed_pc=0x0c080966u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c080968;
P_0c080968: /* original 4215, guest PC 0x0c080968 */
if(!s->budget--) { s->failed_pc=0x0c080968u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c08096a;
P_0c08096a: /* original 7106, guest PC 0x0c08096a */
if(!s->budget--) { s->failed_pc=0x0c08096au; return 0; }
r[1]+=0x00000006u;
goto P_0c08096c;
P_0c08096c: /* original 2f10, guest PC 0x0c08096c */
if(!s->budget--) { s->failed_pc=0x0c08096cu; return 0; }
write(ram,r[15],r[1],1);
goto P_0c08096e;
P_0c08096e: /* original 8f2f, guest PC 0x0c08096e */
if(!s->budget--) { s->failed_pc=0x0c08096eu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[4],4);
if(!cond) { goto P_0c0809d0; }
goto P_0c080972;
P_0c080970: /* original 1f41, guest PC 0x0c080970 */
if(!s->budget--) { s->failed_pc=0x0c080970u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c080972;
P_0c080972: /* original 9371, guest PC 0x0c080972 */
if(!s->budget--) { s->failed_pc=0x0c080972u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080a58u,2);
goto P_0c080974;
P_0c080974: /* original 648e, guest PC 0x0c080974 */
if(!s->budget--) { s->failed_pc=0x0c080974u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[8];
goto P_0c080976;
P_0c080976: /* original 33dc, guest PC 0x0c080976 */
if(!s->budget--) { s->failed_pc=0x0c080976u; return 0; }
r[3]+=r[13];
goto P_0c080978;
P_0c080978: /* original 343c, guest PC 0x0c080978 */
if(!s->budget--) { s->failed_pc=0x0c080978u; return 0; }
r[4]+=r[3];
goto P_0c08097a;
P_0c08097a: /* original 6440, guest PC 0x0c08097a */
if(!s->budget--) { s->failed_pc=0x0c08097au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]=tmp;
goto P_0c08097c;
P_0c08097c: /* original e30d, guest PC 0x0c08097c */
if(!s->budget--) { s->failed_pc=0x0c08097cu; return 0; }
r[3]=0x0000000du;
goto P_0c08097e;
P_0c08097e: /* original 3433, guest PC 0x0c08097e */
if(!s->budget--) { s->failed_pc=0x0c08097eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c080980;
P_0c080980: /* original 8b00, guest PC 0x0c080980 */
if(!s->budget--) { s->failed_pc=0x0c080980u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c080984; }
goto P_0c080982;
P_0c080982: /* original 3438, guest PC 0x0c080982 */
if(!s->budget--) { s->failed_pc=0x0c080982u; return 0; }
r[4]-=r[3];
goto P_0c080984;
P_0c080984: /* original 604e, guest PC 0x0c080984 */
if(!s->budget--) { s->failed_pc=0x0c080984u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c080986;
P_0c080986: /* original 4000, guest PC 0x0c080986 */
if(!s->budget--) { s->failed_pc=0x0c080986u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c080988;
P_0c080988: /* original 00ad, guest PC 0x0c080988 */
if(!s->budget--) { s->failed_pc=0x0c080988u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c08098a;
P_0c08098a: /* original e307, guest PC 0x0c08098a */
if(!s->budget--) { s->failed_pc=0x0c08098au; return 0; }
r[3]=0x00000007u;
goto P_0c08098c;
P_0c08098c: /* original 628e, guest PC 0x0c08098c */
if(!s->budget--) { s->failed_pc=0x0c08098cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[8];
goto P_0c08098e;
P_0c08098e: /* original 81f6, guest PC 0x0c08098e */
if(!s->budget--) { s->failed_pc=0x0c08098eu; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c080990;
P_0c080990: /* original 60f0, guest PC 0x0c080990 */
if(!s->budget--) { s->failed_pc=0x0c080990u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[0]=tmp;
goto P_0c080992;
P_0c080992: /* original 403c, guest PC 0x0c080992 */
if(!s->budget--) { s->failed_pc=0x0c080992u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c080994;
P_0c080994: /* original cb04, guest PC 0x0c080994 */
if(!s->budget--) { s->failed_pc=0x0c080994u; return 0; }
r[0]|=4u;
goto P_0c080996;
P_0c080996: /* original 1f04, guest PC 0x0c080996 */
if(!s->budget--) { s->failed_pc=0x0c080996u; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c080998;
P_0c080998: /* original 60e3, guest PC 0x0c080998 */
if(!s->budget--) { s->failed_pc=0x0c080998u; return 0; }
r[0]=r[14];
goto P_0c08099a;
P_0c08099a: /* original 80f8, guest PC 0x0c08099a */
if(!s->budget--) { s->failed_pc=0x0c08099au; return 0; }
write(ram,r[15]+8,r[0],1);
goto P_0c08099c;
P_0c08099c: /* original e014, guest PC 0x0c08099c */
if(!s->budget--) { s->failed_pc=0x0c08099cu; return 0; }
r[0]=0x00000014u;
goto P_0c08099e;
P_0c08099e: /* original 01fc, guest PC 0x0c08099e */
if(!s->budget--) { s->failed_pc=0x0c08099eu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c0809a0;
P_0c0809a0: /* original 3213, guest PC 0x0c0809a0 */
if(!s->budget--) { s->failed_pc=0x0c0809a0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[1])!=0);
goto P_0c0809a2;
P_0c0809a2: /* original 8901, guest PC 0x0c0809a2 */
if(!s->budget--) { s->failed_pc=0x0c0809a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0809a8; }
goto P_0c0809a4;
P_0c0809a4: /* original e001, guest PC 0x0c0809a4 */
if(!s->budget--) { s->failed_pc=0x0c0809a4u; return 0; }
r[0]=0x00000001u;
goto P_0c0809a6;
P_0c0809a6: /* original 80f8, guest PC 0x0c0809a6 */
if(!s->budget--) { s->failed_pc=0x0c0809a6u; return 0; }
write(ram,r[15]+8,r[0],1);
goto P_0c0809a8;
P_0c0809a8: /* original 2fe6, guest PC 0x0c0809a8 */
if(!s->budget--) { s->failed_pc=0x0c0809a8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0809aa;
P_0c0809aa: /* original 66c3, guest PC 0x0c0809aa */
if(!s->budget--) { s->failed_pc=0x0c0809aau; return 0; }
r[6]=r[12];
goto P_0c0809ac;
P_0c0809ac: /* original 85f8, guest PC 0x0c0809ac */
if(!s->budget--) { s->failed_pc=0x0c0809acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c0809ae;
P_0c0809ae: /* original e700, guest PC 0x0c0809ae */
if(!s->budget--) { s->failed_pc=0x0c0809aeu; return 0; }
r[7]=0x00000000u;
goto P_0c0809b0;
P_0c0809b0: /* original 6303, guest PC 0x0c0809b0 */
if(!s->budget--) { s->failed_pc=0x0c0809b0u; return 0; }
r[3]=r[0];
goto P_0c0809b2;
P_0c0809b2: /* original 84fc, guest PC 0x0c0809b2 */
if(!s->budget--) { s->failed_pc=0x0c0809b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+12,1);
goto P_0c0809b4;
P_0c0809b4: /* original 3308, guest PC 0x0c0809b4 */
if(!s->budget--) { s->failed_pc=0x0c0809b4u; return 0; }
r[3]-=r[0];
goto P_0c0809b6;
P_0c0809b6: /* original 6533, guest PC 0x0c0809b6 */
if(!s->budget--) { s->failed_pc=0x0c0809b6u; return 0; }
r[5]=r[3];
goto P_0c0809b8;
P_0c0809b8: /* original 7502, guest PC 0x0c0809b8 */
if(!s->budget--) { s->failed_pc=0x0c0809b8u; return 0; }
r[5]+=0x00000002u;
goto P_0c0809ba;
P_0c0809ba: /* original 490b, guest PC 0x0c0809ba */
if(!s->budget--) { s->failed_pc=0x0c0809bau; return 0; }
target=r[9];
r[16]=code_base|0x0c0809beu;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0809beu) { target=s->pc; goto dispatch; }
goto P_0c0809be;
P_0c0809bc: /* original 54f5, guest PC 0x0c0809bc */
if(!s->budget--) { s->failed_pc=0x0c0809bcu; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c0809be;
P_0c0809be: /* original 7f04, guest PC 0x0c0809be */
if(!s->budget--) { s->failed_pc=0x0c0809beu; return 0; }
r[15]+=0x00000004u;
goto P_0c0809c0;
P_0c0809c0: /* original 63f0, guest PC 0x0c0809c0 */
if(!s->budget--) { s->failed_pc=0x0c0809c0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[3]=tmp;
goto P_0c0809c2;
P_0c0809c2: /* original 7801, guest PC 0x0c0809c2 */
if(!s->budget--) { s->failed_pc=0x0c0809c2u; return 0; }
r[8]+=0x00000001u;
goto P_0c0809c4;
P_0c0809c4: /* original 628e, guest PC 0x0c0809c4 */
if(!s->budget--) { s->failed_pc=0x0c0809c4u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[8];
goto P_0c0809c6;
P_0c0809c6: /* original 7302, guest PC 0x0c0809c6 */
if(!s->budget--) { s->failed_pc=0x0c0809c6u; return 0; }
r[3]+=0x00000002u;
goto P_0c0809c8;
P_0c0809c8: /* original 2f30, guest PC 0x0c0809c8 */
if(!s->budget--) { s->failed_pc=0x0c0809c8u; return 0; }
write(ram,r[15],r[3],1);
goto P_0c0809ca;
P_0c0809ca: /* original 51f1, guest PC 0x0c0809ca */
if(!s->budget--) { s->failed_pc=0x0c0809cau; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0809cc;
P_0c0809cc: /* original 3213, guest PC 0x0c0809cc */
if(!s->budget--) { s->failed_pc=0x0c0809ccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[1])!=0);
goto P_0c0809ce;
P_0c0809ce: /* original 8bd0, guest PC 0x0c0809ce */
if(!s->budget--) { s->failed_pc=0x0c0809ceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c080972; }
goto P_0c0809d0;
P_0c0809d0: /* original 9041, guest PC 0x0c0809d0 */
if(!s->budget--) { s->failed_pc=0x0c0809d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080a56u,2);
goto P_0c0809d2;
P_0c0809d2: /* original 04dc, guest PC 0x0c0809d2 */
if(!s->budget--) { s->failed_pc=0x0c0809d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0809d4;
P_0c0809d4: /* original e01a, guest PC 0x0c0809d4 */
if(!s->budget--) { s->failed_pc=0x0c0809d4u; return 0; }
r[0]=0x0000001au;
goto P_0c0809d6;
P_0c0809d6: /* original 00dc, guest PC 0x0c0809d6 */
if(!s->budget--) { s->failed_pc=0x0c0809d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0809d8;
P_0c0809d8: /* original 6243, guest PC 0x0c0809d8 */
if(!s->budget--) { s->failed_pc=0x0c0809d8u; return 0; }
r[2]=r[4];
goto P_0c0809da;
P_0c0809da: /* original 4215, guest PC 0x0c0809da */
if(!s->budget--) { s->failed_pc=0x0c0809dau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0809dc;
P_0c0809dc: /* original 80fc, guest PC 0x0c0809dc */
if(!s->budget--) { s->failed_pc=0x0c0809dcu; return 0; }
write(ram,r[15]+12,r[0],1);
goto P_0c0809de;
P_0c0809de: /* original 63b2, guest PC 0x0c0809de */
if(!s->budget--) { s->failed_pc=0x0c0809deu; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c0809e0;
P_0c0809e0: /* original 6be3, guest PC 0x0c0809e0 */
if(!s->budget--) { s->failed_pc=0x0c0809e0u; return 0; }
r[11]=r[14];
goto P_0c0809e2;
P_0c0809e2: /* original 7306, guest PC 0x0c0809e2 */
if(!s->budget--) { s->failed_pc=0x0c0809e2u; return 0; }
r[3]+=0x00000006u;
goto P_0c0809e4;
P_0c0809e4: /* original 2f30, guest PC 0x0c0809e4 */
if(!s->budget--) { s->failed_pc=0x0c0809e4u; return 0; }
write(ram,r[15],r[3],1);
goto P_0c0809e6;
P_0c0809e6: /* original 8d02, guest PC 0x0c0809e6 */
if(!s->budget--) { s->failed_pc=0x0c0809e6u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[4],4);
if(cond) { goto P_0c0809ee; }
goto P_0c0809ea;
P_0c0809e8: /* original 1f41, guest PC 0x0c0809e8 */
if(!s->budget--) { s->failed_pc=0x0c0809e8u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0809ea;
P_0c0809ea: /* original a097, guest PC 0x0c0809ea */
if(!s->budget--) { s->failed_pc=0x0c0809eau; return 0; }
goto P_0c080b1c;
P_0c0809ec: /* original 0009, guest PC 0x0c0809ec */
if(!s->budget--) { s->failed_pc=0x0c0809ecu; return 0; }
goto P_0c0809ee;
P_0c0809ee: /* original 9334, guest PC 0x0c0809ee */
if(!s->budget--) { s->failed_pc=0x0c0809eeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080a5au,2);
goto P_0c0809f0;
P_0c0809f0: /* original 64be, guest PC 0x0c0809f0 */
if(!s->budget--) { s->failed_pc=0x0c0809f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[11];
goto P_0c0809f2;
P_0c0809f2: /* original 33dc, guest PC 0x0c0809f2 */
if(!s->budget--) { s->failed_pc=0x0c0809f2u; return 0; }
r[3]+=r[13];
goto P_0c0809f4;
P_0c0809f4: /* original 343c, guest PC 0x0c0809f4 */
if(!s->budget--) { s->failed_pc=0x0c0809f4u; return 0; }
r[4]+=r[3];
goto P_0c0809f6;
P_0c0809f6: /* original 6440, guest PC 0x0c0809f6 */
if(!s->budget--) { s->failed_pc=0x0c0809f6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]=tmp;
goto P_0c0809f8;
P_0c0809f8: /* original e30d, guest PC 0x0c0809f8 */
if(!s->budget--) { s->failed_pc=0x0c0809f8u; return 0; }
r[3]=0x0000000du;
goto P_0c0809fa;
P_0c0809fa: /* original 3433, guest PC 0x0c0809fa */
if(!s->budget--) { s->failed_pc=0x0c0809fau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0809fc;
P_0c0809fc: /* original 8f01, guest PC 0x0c0809fc */
if(!s->budget--) { s->failed_pc=0x0c0809fcu; return 0; }
cond=r[17]&1u;
r[5]=0x00000036u;
if(!cond) { goto P_0c080a02; }
goto P_0c080a00;
P_0c0809fe: /* original e536, guest PC 0x0c0809fe */
if(!s->budget--) { s->failed_pc=0x0c0809feu; return 0; }
r[5]=0x00000036u;
goto P_0c080a00;
P_0c080a00: /* original 3438, guest PC 0x0c080a00 */
if(!s->budget--) { s->failed_pc=0x0c080a00u; return 0; }
r[4]-=r[3];
goto P_0c080a02;
P_0c080a02: /* original 604e, guest PC 0x0c080a02 */
if(!s->budget--) { s->failed_pc=0x0c080a02u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c080a04;
P_0c080a04: /* original 880c, guest PC 0x0c080a04 */
if(!s->budget--) { s->failed_pc=0x0c080a04u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c080a06;
P_0c080a06: /* original 8f01, guest PC 0x0c080a06 */
if(!s->budget--) { s->failed_pc=0x0c080a06u; return 0; }
cond=r[17]&1u;
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
if(!cond) { goto P_0c080a0c; }
goto P_0c080a0a;
P_0c080a08: /* original 604e, guest PC 0x0c080a08 */
if(!s->budget--) { s->failed_pc=0x0c080a08u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c080a0a;
P_0c080a0a: /* original e535, guest PC 0x0c080a0a */
if(!s->budget--) { s->failed_pc=0x0c080a0au; return 0; }
r[5]=0x00000035u;
goto P_0c080a0c;
P_0c080a0c: /* original 4000, guest PC 0x0c080a0c */
if(!s->budget--) { s->failed_pc=0x0c080a0cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c080a0e;
P_0c080a0e: /* original 00ad, guest PC 0x0c080a0e */
if(!s->budget--) { s->failed_pc=0x0c080a0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c080a10;
P_0c080a10: /* original e207, guest PC 0x0c080a10 */
if(!s->budget--) { s->failed_pc=0x0c080a10u; return 0; }
r[2]=0x00000007u;
goto P_0c080a12;
P_0c080a12: /* original 655e, guest PC 0x0c080a12 */
if(!s->budget--) { s->failed_pc=0x0c080a12u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c080a14;
P_0c080a14: /* original 81f4, guest PC 0x0c080a14 */
if(!s->budget--) { s->failed_pc=0x0c080a14u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c080a16;
P_0c080a16: /* original 4500, guest PC 0x0c080a16 */
if(!s->budget--) { s->failed_pc=0x0c080a16u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c080a18;
P_0c080a18: /* original 63f0, guest PC 0x0c080a18 */
if(!s->budget--) { s->failed_pc=0x0c080a18u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[3]=tmp;
goto P_0c080a1a;
P_0c080a1a: /* original 432c, guest PC 0x0c080a1a */
if(!s->budget--) { s->failed_pc=0x0c080a1au; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c080a1c;
P_0c080a1c: /* original 253b, guest PC 0x0c080a1c */
if(!s->budget--) { s->failed_pc=0x0c080a1cu; return 0; }
r[5]|=r[3];
goto P_0c080a1e;
P_0c080a1e: /* original 63be, guest PC 0x0c080a1e */
if(!s->budget--) { s->failed_pc=0x0c080a1eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[11];
goto P_0c080a20;
P_0c080a20: /* original 1f54, guest PC 0x0c080a20 */
if(!s->budget--) { s->failed_pc=0x0c080a20u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c080a22;
P_0c080a22: /* original 84fc, guest PC 0x0c080a22 */
if(!s->budget--) { s->failed_pc=0x0c080a22u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+12,1);
goto P_0c080a24;
P_0c080a24: /* original 3303, guest PC 0x0c080a24 */
if(!s->budget--) { s->failed_pc=0x0c080a24u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[0])!=0);
goto P_0c080a26;
P_0c080a26: /* original 8d01, guest PC 0x0c080a26 */
if(!s->budget--) { s->failed_pc=0x0c080a26u; return 0; }
cond=r[17]&1u;
r[8]=r[14];
if(cond) { goto P_0c080a2c; }
goto P_0c080a2a;
P_0c080a28: /* original 68e3, guest PC 0x0c080a28 */
if(!s->budget--) { s->failed_pc=0x0c080a28u; return 0; }
r[8]=r[14];
goto P_0c080a2a;
P_0c080a2a: /* original e801, guest PC 0x0c080a2a */
if(!s->budget--) { s->failed_pc=0x0c080a2au; return 0; }
r[8]=0x00000001u;
goto P_0c080a2c;
P_0c080a2c: /* original 2fe6, guest PC 0x0c080a2c */
if(!s->budget--) { s->failed_pc=0x0c080a2cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080a2e;
P_0c080a2e: /* original 688e, guest PC 0x0c080a2e */
if(!s->budget--) { s->failed_pc=0x0c080a2eu; return 0; }
r[8]=(uint32_t)(int32_t)(int8_t)r[8];
goto P_0c080a30;
P_0c080a30: /* original 85f6, guest PC 0x0c080a30 */
if(!s->budget--) { s->failed_pc=0x0c080a30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c080a32;
P_0c080a32: /* original 66c3, guest PC 0x0c080a32 */
if(!s->budget--) { s->failed_pc=0x0c080a32u; return 0; }
r[6]=r[12];
goto P_0c080a34;
P_0c080a34: /* original e700, guest PC 0x0c080a34 */
if(!s->budget--) { s->failed_pc=0x0c080a34u; return 0; }
r[7]=0x00000000u;
goto P_0c080a36;
P_0c080a36: /* original 3088, guest PC 0x0c080a36 */
if(!s->budget--) { s->failed_pc=0x0c080a36u; return 0; }
r[0]-=r[8];
goto P_0c080a38;
P_0c080a38: /* original 6503, guest PC 0x0c080a38 */
if(!s->budget--) { s->failed_pc=0x0c080a38u; return 0; }
r[5]=r[0];
goto P_0c080a3a;
P_0c080a3a: /* original 7502, guest PC 0x0c080a3a */
if(!s->budget--) { s->failed_pc=0x0c080a3au; return 0; }
r[5]+=0x00000002u;
goto P_0c080a3c;
P_0c080a3c: /* original 490b, guest PC 0x0c080a3c */
if(!s->budget--) { s->failed_pc=0x0c080a3cu; return 0; }
target=r[9];
r[16]=code_base|0x0c080a40u;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080a40u) { target=s->pc; goto dispatch; }
goto P_0c080a40;
P_0c080a3e: /* original 54f5, guest PC 0x0c080a3e */
if(!s->budget--) { s->failed_pc=0x0c080a3eu; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c080a40;
P_0c080a40: /* original 7f04, guest PC 0x0c080a40 */
if(!s->budget--) { s->failed_pc=0x0c080a40u; return 0; }
r[15]+=0x00000004u;
goto P_0c080a42;
P_0c080a42: /* original 63f0, guest PC 0x0c080a42 */
if(!s->budget--) { s->failed_pc=0x0c080a42u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[3]=tmp;
goto P_0c080a44;
P_0c080a44: /* original 7b01, guest PC 0x0c080a44 */
if(!s->budget--) { s->failed_pc=0x0c080a44u; return 0; }
r[11]+=0x00000001u;
goto P_0c080a46;
P_0c080a46: /* original 62be, guest PC 0x0c080a46 */
if(!s->budget--) { s->failed_pc=0x0c080a46u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[11];
goto P_0c080a48;
P_0c080a48: /* original 7302, guest PC 0x0c080a48 */
if(!s->budget--) { s->failed_pc=0x0c080a48u; return 0; }
r[3]+=0x00000002u;
goto P_0c080a4a;
P_0c080a4a: /* original 2f30, guest PC 0x0c080a4a */
if(!s->budget--) { s->failed_pc=0x0c080a4au; return 0; }
write(ram,r[15],r[3],1);
goto P_0c080a4c;
P_0c080a4c: /* original 51f1, guest PC 0x0c080a4c */
if(!s->budget--) { s->failed_pc=0x0c080a4cu; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c080a4e;
P_0c080a4e: /* original 3213, guest PC 0x0c080a4e */
if(!s->budget--) { s->failed_pc=0x0c080a4eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[1])!=0);
goto P_0c080a50;
P_0c080a50: /* original 8bcd, guest PC 0x0c080a50 */
if(!s->budget--) { s->failed_pc=0x0c080a50u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0809ee; }
goto P_0c080a52;
P_0c080a52: /* original a063, guest PC 0x0c080a52 */
if(!s->budget--) { s->failed_pc=0x0c080a52u; return 0; }
goto P_0c080b1c;
P_0c080a54: /* original 0009, guest PC 0x0c080a54 */
if(!s->budget--) { s->failed_pc=0x0c080a54u; return 0; }
if(!vf3_matrix_family(0x0c080a56u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c080a56u; return 0; } return 1;
P_0c080a74: /* original 5152, guest PC 0x0c080a74 */
if(!s->budget--) { s->failed_pc=0x0c080a74u; return 0; }
r[1]=read(ram,r[5]+8,4);
goto P_0c080a76;
P_0c080a76: /* original d22f, guest PC 0x0c080a76 */
if(!s->budget--) { s->failed_pc=0x0c080a76u; return 0; }
r[2]=read(ram,0x0c080b34u,4);
goto P_0c080a78;
P_0c080a78: /* original 2128, guest PC 0x0c080a78 */
if(!s->budget--) { s->failed_pc=0x0c080a78u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c080a7a;
P_0c080a7a: /* original 8b4f, guest PC 0x0c080a7a */
if(!s->budget--) { s->failed_pc=0x0c080a7au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c080b1c; }
goto P_0c080a7c;
P_0c080a7c: /* original 60b2, guest PC 0x0c080a7c */
if(!s->budget--) { s->failed_pc=0x0c080a7cu; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c080a7e;
P_0c080a7e: /* original e307, guest PC 0x0c080a7e */
if(!s->budget--) { s->failed_pc=0x0c080a7eu; return 0; }
r[3]=0x00000007u;
goto P_0c080a80;
P_0c080a80: /* original e220, guest PC 0x0c080a80 */
if(!s->budget--) { s->failed_pc=0x0c080a80u; return 0; }
r[2]=0x00000020u;
goto P_0c080a82;
P_0c080a82: /* original 7006, guest PC 0x0c080a82 */
if(!s->budget--) { s->failed_pc=0x0c080a82u; return 0; }
r[0]+=0x00000006u;
goto P_0c080a84;
P_0c080a84: /* original 403c, guest PC 0x0c080a84 */
if(!s->budget--) { s->failed_pc=0x0c080a84u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c080a86;
P_0c080a86: /* original cb04, guest PC 0x0c080a86 */
if(!s->budget--) { s->failed_pc=0x0c080a86u; return 0; }
r[0]|=4u;
goto P_0c080a88;
P_0c080a88: /* original 2f02, guest PC 0x0c080a88 */
if(!s->budget--) { s->failed_pc=0x0c080a88u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c080a8a;
P_0c080a8a: /* original 6503, guest PC 0x0c080a8a */
if(!s->budget--) { s->failed_pc=0x0c080a8au; return 0; }
r[5]=r[0];
goto P_0c080a8c;
P_0c080a8c: /* original e615, guest PC 0x0c080a8c */
if(!s->budget--) { s->failed_pc=0x0c080a8cu; return 0; }
r[6]=0x00000015u;
goto P_0c080a8e;
P_0c080a8e: /* original 2f26, guest PC 0x0c080a8e */
if(!s->budget--) { s->failed_pc=0x0c080a8eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080a90;
P_0c080a90: /* original d329, guest PC 0x0c080a90 */
if(!s->budget--) { s->failed_pc=0x0c080a90u; return 0; }
r[3]=read(ram,0x0c080b38u,4);
goto P_0c080a92;
P_0c080a92: /* original e701, guest PC 0x0c080a92 */
if(!s->budget--) { s->failed_pc=0x0c080a92u; return 0; }
r[7]=0x00000001u;
goto P_0c080a94;
P_0c080a94: /* original 430b, guest PC 0x0c080a94 */
if(!s->budget--) { s->failed_pc=0x0c080a94u; return 0; }
target=r[3];
r[16]=code_base|0x0c080a98u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080a98u) { target=s->pc; goto dispatch; }
goto P_0c080a98;
P_0c080a96: /* original 64c3, guest PC 0x0c080a96 */
if(!s->budget--) { s->failed_pc=0x0c080a96u; return 0; }
r[4]=r[12];
goto P_0c080a98;
P_0c080a98: /* original 60b2, guest PC 0x0c080a98 */
if(!s->budget--) { s->failed_pc=0x0c080a98u; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c080a9a;
P_0c080a9a: /* original e307, guest PC 0x0c080a9a */
if(!s->budget--) { s->failed_pc=0x0c080a9au; return 0; }
r[3]=0x00000007u;
goto P_0c080a9c;
P_0c080a9c: /* original e220, guest PC 0x0c080a9c */
if(!s->budget--) { s->failed_pc=0x0c080a9cu; return 0; }
r[2]=0x00000020u;
goto P_0c080a9e;
P_0c080a9e: /* original 7006, guest PC 0x0c080a9e */
if(!s->budget--) { s->failed_pc=0x0c080a9eu; return 0; }
r[0]+=0x00000006u;
goto P_0c080aa0;
P_0c080aa0: /* original 403c, guest PC 0x0c080aa0 */
if(!s->budget--) { s->failed_pc=0x0c080aa0u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c080aa2;
P_0c080aa2: /* original cb5c, guest PC 0x0c080aa2 */
if(!s->budget--) { s->failed_pc=0x0c080aa2u; return 0; }
r[0]|=92u;
goto P_0c080aa4;
P_0c080aa4: /* original 1f01, guest PC 0x0c080aa4 */
if(!s->budget--) { s->failed_pc=0x0c080aa4u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c080aa6;
P_0c080aa6: /* original 6503, guest PC 0x0c080aa6 */
if(!s->budget--) { s->failed_pc=0x0c080aa6u; return 0; }
r[5]=r[0];
goto P_0c080aa8;
P_0c080aa8: /* original e615, guest PC 0x0c080aa8 */
if(!s->budget--) { s->failed_pc=0x0c080aa8u; return 0; }
r[6]=0x00000015u;
goto P_0c080aaa;
P_0c080aaa: /* original 2f26, guest PC 0x0c080aaa */
if(!s->budget--) { s->failed_pc=0x0c080aaau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080aac;
P_0c080aac: /* original d322, guest PC 0x0c080aac */
if(!s->budget--) { s->failed_pc=0x0c080aacu; return 0; }
r[3]=read(ram,0x0c080b38u,4);
goto P_0c080aae;
P_0c080aae: /* original e701, guest PC 0x0c080aae */
if(!s->budget--) { s->failed_pc=0x0c080aaeu; return 0; }
r[7]=0x00000001u;
goto P_0c080ab0;
P_0c080ab0: /* original 430b, guest PC 0x0c080ab0 */
if(!s->budget--) { s->failed_pc=0x0c080ab0u; return 0; }
target=r[3];
r[16]=code_base|0x0c080ab4u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080ab4u) { target=s->pc; goto dispatch; }
goto P_0c080ab4;
P_0c080ab2: /* original 64c3, guest PC 0x0c080ab2 */
if(!s->budget--) { s->failed_pc=0x0c080ab2u; return 0; }
r[4]=r[12];
goto P_0c080ab4;
P_0c080ab4: /* original 54f9, guest PC 0x0c080ab4 */
if(!s->budget--) { s->failed_pc=0x0c080ab4u; return 0; }
r[4]=read(ram,r[15]+36,4);
goto P_0c080ab6;
P_0c080ab6: /* original e061, guest PC 0x0c080ab6 */
if(!s->budget--) { s->failed_pc=0x0c080ab6u; return 0; }
r[0]=0x00000061u;
goto P_0c080ab8;
P_0c080ab8: /* original e207, guest PC 0x0c080ab8 */
if(!s->budget--) { s->failed_pc=0x0c080ab8u; return 0; }
r[2]=0x00000007u;
goto P_0c080aba;
P_0c080aba: /* original 66c3, guest PC 0x0c080aba */
if(!s->budget--) { s->failed_pc=0x0c080abau; return 0; }
r[6]=r[12];
goto P_0c080abc;
P_0c080abc: /* original 044c, guest PC 0x0c080abc */
if(!s->budget--) { s->failed_pc=0x0c080abcu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c080abe;
P_0c080abe: /* original e700, guest PC 0x0c080abe */
if(!s->budget--) { s->failed_pc=0x0c080abeu; return 0; }
r[7]=0x00000000u;
goto P_0c080ac0;
P_0c080ac0: /* original 604e, guest PC 0x0c080ac0 */
if(!s->budget--) { s->failed_pc=0x0c080ac0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c080ac2;
P_0c080ac2: /* original 4000, guest PC 0x0c080ac2 */
if(!s->budget--) { s->failed_pc=0x0c080ac2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c080ac4;
P_0c080ac4: /* original 03ad, guest PC 0x0c080ac4 */
if(!s->budget--) { s->failed_pc=0x0c080ac4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c080ac6;
P_0c080ac6: /* original 6033, guest PC 0x0c080ac6 */
if(!s->budget--) { s->failed_pc=0x0c080ac6u; return 0; }
r[0]=r[3];
goto P_0c080ac8;
P_0c080ac8: /* original 81f4, guest PC 0x0c080ac8 */
if(!s->budget--) { s->failed_pc=0x0c080ac8u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c080aca;
P_0c080aca: /* original 60b2, guest PC 0x0c080aca */
if(!s->budget--) { s->failed_pc=0x0c080acau; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c080acc;
P_0c080acc: /* original 7006, guest PC 0x0c080acc */
if(!s->budget--) { s->failed_pc=0x0c080accu; return 0; }
r[0]+=0x00000006u;
goto P_0c080ace;
P_0c080ace: /* original 402c, guest PC 0x0c080ace */
if(!s->budget--) { s->failed_pc=0x0c080aceu; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[0]>>((-r[2])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[2]&31u);
goto P_0c080ad0;
P_0c080ad0: /* original cb04, guest PC 0x0c080ad0 */
if(!s->budget--) { s->failed_pc=0x0c080ad0u; return 0; }
r[0]|=4u;
goto P_0c080ad2;
P_0c080ad2: /* original 1f04, guest PC 0x0c080ad2 */
if(!s->budget--) { s->failed_pc=0x0c080ad2u; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c080ad4;
P_0c080ad4: /* original 2fe6, guest PC 0x0c080ad4 */
if(!s->budget--) { s->failed_pc=0x0c080ad4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080ad6;
P_0c080ad6: /* original 85f6, guest PC 0x0c080ad6 */
if(!s->budget--) { s->failed_pc=0x0c080ad6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c080ad8;
P_0c080ad8: /* original 6503, guest PC 0x0c080ad8 */
if(!s->budget--) { s->failed_pc=0x0c080ad8u; return 0; }
r[5]=r[0];
goto P_0c080ada;
P_0c080ada: /* original 7502, guest PC 0x0c080ada */
if(!s->budget--) { s->failed_pc=0x0c080adau; return 0; }
r[5]+=0x00000002u;
goto P_0c080adc;
P_0c080adc: /* original 490b, guest PC 0x0c080adc */
if(!s->budget--) { s->failed_pc=0x0c080adcu; return 0; }
target=r[9];
r[16]=code_base|0x0c080ae0u;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080ae0u) { target=s->pc; goto dispatch; }
goto P_0c080ae0;
P_0c080ade: /* original 54f5, guest PC 0x0c080ade */
if(!s->budget--) { s->failed_pc=0x0c080adeu; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c080ae0;
P_0c080ae0: /* original 7f0c, guest PC 0x0c080ae0 */
if(!s->budget--) { s->failed_pc=0x0c080ae0u; return 0; }
r[15]+=0x0000000cu;
goto P_0c080ae2;
P_0c080ae2: /* original 54f6, guest PC 0x0c080ae2 */
if(!s->budget--) { s->failed_pc=0x0c080ae2u; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c080ae4;
P_0c080ae4: /* original e061, guest PC 0x0c080ae4 */
if(!s->budget--) { s->failed_pc=0x0c080ae4u; return 0; }
r[0]=0x00000061u;
goto P_0c080ae6;
P_0c080ae6: /* original e307, guest PC 0x0c080ae6 */
if(!s->budget--) { s->failed_pc=0x0c080ae6u; return 0; }
r[3]=0x00000007u;
goto P_0c080ae8;
P_0c080ae8: /* original 044c, guest PC 0x0c080ae8 */
if(!s->budget--) { s->failed_pc=0x0c080ae8u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c080aea;
P_0c080aea: /* original ed6c, guest PC 0x0c080aea */
if(!s->budget--) { s->failed_pc=0x0c080aeau; return 0; }
r[13]=0x0000006cu;
goto P_0c080aec;
P_0c080aec: /* original 60b2, guest PC 0x0c080aec */
if(!s->budget--) { s->failed_pc=0x0c080aecu; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c080aee;
P_0c080aee: /* original 7006, guest PC 0x0c080aee */
if(!s->budget--) { s->failed_pc=0x0c080aeeu; return 0; }
r[0]+=0x00000006u;
goto P_0c080af0;
P_0c080af0: /* original 403c, guest PC 0x0c080af0 */
if(!s->budget--) { s->failed_pc=0x0c080af0u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c080af2;
P_0c080af2: /* original 2d0b, guest PC 0x0c080af2 */
if(!s->budget--) { s->failed_pc=0x0c080af2u; return 0; }
r[13]|=r[0];
goto P_0c080af4;
P_0c080af4: /* original 604e, guest PC 0x0c080af4 */
if(!s->budget--) { s->failed_pc=0x0c080af4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c080af6;
P_0c080af6: /* original 880c, guest PC 0x0c080af6 */
if(!s->budget--) { s->failed_pc=0x0c080af6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c080af8;
P_0c080af8: /* original 8b04, guest PC 0x0c080af8 */
if(!s->budget--) { s->failed_pc=0x0c080af8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c080b04; }
goto P_0c080afa;
P_0c080afa: /* original 60b2, guest PC 0x0c080afa */
if(!s->budget--) { s->failed_pc=0x0c080afau; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c080afc;
P_0c080afc: /* original ed64, guest PC 0x0c080afc */
if(!s->budget--) { s->failed_pc=0x0c080afcu; return 0; }
r[13]=0x00000064u;
goto P_0c080afe;
P_0c080afe: /* original 7006, guest PC 0x0c080afe */
if(!s->budget--) { s->failed_pc=0x0c080afeu; return 0; }
r[0]+=0x00000006u;
goto P_0c080b00;
P_0c080b00: /* original 403c, guest PC 0x0c080b00 */
if(!s->budget--) { s->failed_pc=0x0c080b00u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c080b02;
P_0c080b02: /* original 2d0b, guest PC 0x0c080b02 */
if(!s->budget--) { s->failed_pc=0x0c080b02u; return 0; }
r[13]|=r[0];
goto P_0c080b04;
P_0c080b04: /* original 604e, guest PC 0x0c080b04 */
if(!s->budget--) { s->failed_pc=0x0c080b04u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c080b06;
P_0c080b06: /* original 66c3, guest PC 0x0c080b06 */
if(!s->budget--) { s->failed_pc=0x0c080b06u; return 0; }
r[6]=r[12];
goto P_0c080b08;
P_0c080b08: /* original 4000, guest PC 0x0c080b08 */
if(!s->budget--) { s->failed_pc=0x0c080b08u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c080b0a;
P_0c080b0a: /* original 03ad, guest PC 0x0c080b0a */
if(!s->budget--) { s->failed_pc=0x0c080b0au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c080b0c;
P_0c080b0c: /* original e700, guest PC 0x0c080b0c */
if(!s->budget--) { s->failed_pc=0x0c080b0cu; return 0; }
r[7]=0x00000000u;
goto P_0c080b0e;
P_0c080b0e: /* original 653f, guest PC 0x0c080b0e */
if(!s->budget--) { s->failed_pc=0x0c080b0eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c080b10;
P_0c080b10: /* original 2f31, guest PC 0x0c080b10 */
if(!s->budget--) { s->failed_pc=0x0c080b10u; return 0; }
write(ram,r[15],r[3],2);
goto P_0c080b12;
P_0c080b12: /* original 7502, guest PC 0x0c080b12 */
if(!s->budget--) { s->failed_pc=0x0c080b12u; return 0; }
r[5]+=0x00000002u;
goto P_0c080b14;
P_0c080b14: /* original 2fe6, guest PC 0x0c080b14 */
if(!s->budget--) { s->failed_pc=0x0c080b14u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080b16;
P_0c080b16: /* original 490b, guest PC 0x0c080b16 */
if(!s->budget--) { s->failed_pc=0x0c080b16u; return 0; }
target=r[9];
r[16]=code_base|0x0c080b1au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080b1au) { target=s->pc; goto dispatch; }
goto P_0c080b1a;
P_0c080b18: /* original 64d3, guest PC 0x0c080b18 */
if(!s->budget--) { s->failed_pc=0x0c080b18u; return 0; }
r[4]=r[13];
goto P_0c080b1a;
P_0c080b1a: /* original 7f04, guest PC 0x0c080b1a */
if(!s->budget--) { s->failed_pc=0x0c080b1au; return 0; }
r[15]+=0x00000004u;
goto P_0c080b1c;
P_0c080b1c: /* original 7f20, guest PC 0x0c080b1c */
if(!s->budget--) { s->failed_pc=0x0c080b1cu; return 0; }
r[15]+=0x00000020u;
goto P_0c080b1e;
P_0c080b1e: /* original 4f26, guest PC 0x0c080b1e */
if(!s->budget--) { s->failed_pc=0x0c080b1eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c080b20;
P_0c080b20: /* original e000, guest PC 0x0c080b20 */
if(!s->budget--) { s->failed_pc=0x0c080b20u; return 0; }
r[0]=0x00000000u;
goto P_0c080b22;
P_0c080b22: /* original 68f6, guest PC 0x0c080b22 */
if(!s->budget--) { s->failed_pc=0x0c080b22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c080b24;
P_0c080b24: /* original 69f6, guest PC 0x0c080b24 */
if(!s->budget--) { s->failed_pc=0x0c080b24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c080b26;
P_0c080b26: /* original 6af6, guest PC 0x0c080b26 */
if(!s->budget--) { s->failed_pc=0x0c080b26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c080b28;
P_0c080b28: /* original 6bf6, guest PC 0x0c080b28 */
if(!s->budget--) { s->failed_pc=0x0c080b28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c080b2a;
P_0c080b2a: /* original 6cf6, guest PC 0x0c080b2a */
if(!s->budget--) { s->failed_pc=0x0c080b2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c080b2c;
P_0c080b2c: /* original 6df6, guest PC 0x0c080b2c */
if(!s->budget--) { s->failed_pc=0x0c080b2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c080b2e;
P_0c080b2e: /* original 000b, guest PC 0x0c080b2e */
if(!s->budget--) { s->failed_pc=0x0c080b2eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c080b30: /* original 6ef6, guest PC 0x0c080b30 */
if(!s->budget--) { s->failed_pc=0x0c080b30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c080b32u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c080b32u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
