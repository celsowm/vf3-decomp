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
int vf3_away_batch199_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09ea66u: goto P_0c09ea66;
case 0x0c09ea68u: goto P_0c09ea68;
case 0x0c09ea6au: goto P_0c09ea6a;
case 0x0c09ea6cu: goto P_0c09ea6c;
case 0x0c09ea6eu: goto P_0c09ea6e;
case 0x0c09ea70u: goto P_0c09ea70;
case 0x0c09ea72u: goto P_0c09ea72;
case 0x0c09ea74u: goto P_0c09ea74;
case 0x0c09ea76u: goto P_0c09ea76;
case 0x0c09ea78u: goto P_0c09ea78;
case 0x0c09ea7au: goto P_0c09ea7a;
case 0x0c09ea7cu: goto P_0c09ea7c;
case 0x0c09ea7eu: goto P_0c09ea7e;
case 0x0c09ea80u: goto P_0c09ea80;
case 0x0c09ea82u: goto P_0c09ea82;
case 0x0c09ea84u: goto P_0c09ea84;
case 0x0c09ea86u: goto P_0c09ea86;
case 0x0c09ea88u: goto P_0c09ea88;
case 0x0c09ea8au: goto P_0c09ea8a;
case 0x0c09ea8cu: goto P_0c09ea8c;
case 0x0c09ea8eu: goto P_0c09ea8e;
case 0x0c09ea90u: goto P_0c09ea90;
case 0x0c09ea92u: goto P_0c09ea92;
case 0x0c09ea94u: goto P_0c09ea94;
case 0x0c09ea96u: goto P_0c09ea96;
case 0x0c09ea98u: goto P_0c09ea98;
case 0x0c09ea9au: goto P_0c09ea9a;
case 0x0c09ea9cu: goto P_0c09ea9c;
case 0x0c09ea9eu: goto P_0c09ea9e;
case 0x0c09eaa0u: goto P_0c09eaa0;
case 0x0c09eaa2u: goto P_0c09eaa2;
case 0x0c09eaa4u: goto P_0c09eaa4;
case 0x0c09eaa6u: goto P_0c09eaa6;
case 0x0c09eaa8u: goto P_0c09eaa8;
case 0x0c09eaaau: goto P_0c09eaaa;
case 0x0c09eaacu: goto P_0c09eaac;
case 0x0c09eaaeu: goto P_0c09eaae;
case 0x0c09eab0u: goto P_0c09eab0;
case 0x0c09eab2u: goto P_0c09eab2;
case 0x0c09eab4u: goto P_0c09eab4;
case 0x0c09eab6u: goto P_0c09eab6;
case 0x0c09eab8u: goto P_0c09eab8;
case 0x0c09eabau: goto P_0c09eaba;
case 0x0c09eabcu: goto P_0c09eabc;
case 0x0c09eabeu: goto P_0c09eabe;
case 0x0c09eac0u: goto P_0c09eac0;
case 0x0c09eac2u: goto P_0c09eac2;
case 0x0c09eac4u: goto P_0c09eac4;
case 0x0c09eac6u: goto P_0c09eac6;
case 0x0c09eac8u: goto P_0c09eac8;
case 0x0c09eacau: goto P_0c09eaca;
case 0x0c09eaccu: goto P_0c09eacc;
case 0x0c09eaceu: goto P_0c09eace;
case 0x0c09ead0u: goto P_0c09ead0;
case 0x0c09ead2u: goto P_0c09ead2;
case 0x0c09ead4u: goto P_0c09ead4;
case 0x0c09ead6u: goto P_0c09ead6;
case 0x0c09ead8u: goto P_0c09ead8;
case 0x0c09eae2u: goto P_0c09eae2;
case 0x0c09eae4u: goto P_0c09eae4;
case 0x0c09eae6u: goto P_0c09eae6;
case 0x0c09eae8u: goto P_0c09eae8;
case 0x0c09eaeau: goto P_0c09eaea;
case 0x0c09eaecu: goto P_0c09eaec;
case 0x0c09eaeeu: goto P_0c09eaee;
case 0x0c09eaf0u: goto P_0c09eaf0;
case 0x0c09eaf2u: goto P_0c09eaf2;
case 0x0c09eaf4u: goto P_0c09eaf4;
case 0x0c09eaf6u: goto P_0c09eaf6;
case 0x0c09eaf8u: goto P_0c09eaf8;
case 0x0c09eafau: goto P_0c09eafa;
case 0x0c09eafcu: goto P_0c09eafc;
case 0x0c09eafeu: goto P_0c09eafe;
case 0x0c09eb00u: goto P_0c09eb00;
case 0x0c09eb02u: goto P_0c09eb02;
case 0x0c09eb04u: goto P_0c09eb04;
case 0x0c09eb06u: goto P_0c09eb06;
case 0x0c09eb08u: goto P_0c09eb08;
case 0x0c09eb0au: goto P_0c09eb0a;
case 0x0c09eb0cu: goto P_0c09eb0c;
case 0x0c09eb0eu: goto P_0c09eb0e;
case 0x0c09eb10u: goto P_0c09eb10;
case 0x0c09eb12u: goto P_0c09eb12;
case 0x0c09eb14u: goto P_0c09eb14;
case 0x0c09eb16u: goto P_0c09eb16;
case 0x0c09eb18u: goto P_0c09eb18;
case 0x0c09eb1au: goto P_0c09eb1a;
case 0x0c09eb1cu: goto P_0c09eb1c;
case 0x0c09eb1eu: goto P_0c09eb1e;
case 0x0c09eb20u: goto P_0c09eb20;
case 0x0c09eb22u: goto P_0c09eb22;
case 0x0c09eb24u: goto P_0c09eb24;
case 0x0c09eb26u: goto P_0c09eb26;
case 0x0c09eb28u: goto P_0c09eb28;
case 0x0c09eb2au: goto P_0c09eb2a;
case 0x0c09eb2cu: goto P_0c09eb2c;
case 0x0c09eb2eu: goto P_0c09eb2e;
case 0x0c09eb30u: goto P_0c09eb30;
case 0x0c09eb32u: goto P_0c09eb32;
case 0x0c09eb34u: goto P_0c09eb34;
case 0x0c09eb36u: goto P_0c09eb36;
case 0x0c09eb38u: goto P_0c09eb38;
case 0x0c09eb3au: goto P_0c09eb3a;
case 0x0c09eb3cu: goto P_0c09eb3c;
case 0x0c09eb3eu: goto P_0c09eb3e;
case 0x0c09eb40u: goto P_0c09eb40;
case 0x0c09eb42u: goto P_0c09eb42;
case 0x0c09eb44u: goto P_0c09eb44;
case 0x0c09eb46u: goto P_0c09eb46;
case 0x0c09eb48u: goto P_0c09eb48;
case 0x0c09eb4au: goto P_0c09eb4a;
case 0x0c09eb4cu: goto P_0c09eb4c;
case 0x0c09eb4eu: goto P_0c09eb4e;
case 0x0c09eb50u: goto P_0c09eb50;
case 0x0c09eb52u: goto P_0c09eb52;
case 0x0c09eb54u: goto P_0c09eb54;
case 0x0c09eb56u: goto P_0c09eb56;
case 0x0c09eb58u: goto P_0c09eb58;
case 0x0c09eb5au: goto P_0c09eb5a;
case 0x0c09eb5cu: goto P_0c09eb5c;
case 0x0c09eb5eu: goto P_0c09eb5e;
case 0x0c09eb60u: goto P_0c09eb60;
case 0x0c09eb62u: goto P_0c09eb62;
case 0x0c09eb64u: goto P_0c09eb64;
case 0x0c09eb66u: goto P_0c09eb66;
case 0x0c09eb68u: goto P_0c09eb68;
case 0x0c09eb6au: goto P_0c09eb6a;
case 0x0c09eb6cu: goto P_0c09eb6c;
case 0x0c09eb6eu: goto P_0c09eb6e;
case 0x0c09eb70u: goto P_0c09eb70;
case 0x0c09eb72u: goto P_0c09eb72;
case 0x0c09eb74u: goto P_0c09eb74;
case 0x0c09eb76u: goto P_0c09eb76;
case 0x0c09eb78u: goto P_0c09eb78;
case 0x0c09eb7au: goto P_0c09eb7a;
case 0x0c09eb7cu: goto P_0c09eb7c;
case 0x0c09eb7eu: goto P_0c09eb7e;
case 0x0c09eb80u: goto P_0c09eb80;
case 0x0c09eb82u: goto P_0c09eb82;
case 0x0c09eb84u: goto P_0c09eb84;
case 0x0c09eb86u: goto P_0c09eb86;
case 0x0c09eb88u: goto P_0c09eb88;
case 0x0c09eb8au: goto P_0c09eb8a;
case 0x0c09eb8cu: goto P_0c09eb8c;
case 0x0c09eb8eu: goto P_0c09eb8e;
case 0x0c09eb90u: goto P_0c09eb90;
case 0x0c09eb92u: goto P_0c09eb92;
case 0x0c09eb94u: goto P_0c09eb94;
case 0x0c09eb96u: goto P_0c09eb96;
case 0x0c09eb98u: goto P_0c09eb98;
case 0x0c09eb9au: goto P_0c09eb9a;
case 0x0c09eb9cu: goto P_0c09eb9c;
case 0x0c09eb9eu: goto P_0c09eb9e;
case 0x0c09eba0u: goto P_0c09eba0;
case 0x0c09eba2u: goto P_0c09eba2;
case 0x0c09eba4u: goto P_0c09eba4;
case 0x0c09eba6u: goto P_0c09eba6;
case 0x0c09eba8u: goto P_0c09eba8;
case 0x0c09ebaau: goto P_0c09ebaa;
case 0x0c09ebacu: goto P_0c09ebac;
case 0x0c09ebaeu: goto P_0c09ebae;
case 0x0c09ebb0u: goto P_0c09ebb0;
case 0x0c09ebb2u: goto P_0c09ebb2;
case 0x0c09ebb4u: goto P_0c09ebb4;
case 0x0c09ebb6u: goto P_0c09ebb6;
case 0x0c09ebb8u: goto P_0c09ebb8;
case 0x0c09ebbau: goto P_0c09ebba;
case 0x0c09ebbcu: goto P_0c09ebbc;
case 0x0c09ebbeu: goto P_0c09ebbe;
case 0x0c09ebc0u: goto P_0c09ebc0;
case 0x0c09ebc2u: goto P_0c09ebc2;
case 0x0c09ebc4u: goto P_0c09ebc4;
case 0x0c09ebc6u: goto P_0c09ebc6;
case 0x0c09ebc8u: goto P_0c09ebc8;
case 0x0c09ebcau: goto P_0c09ebca;
case 0x0c09ebccu: goto P_0c09ebcc;
case 0x0c09ebceu: goto P_0c09ebce;
case 0x0c09ebd0u: goto P_0c09ebd0;
case 0x0c09ebd2u: goto P_0c09ebd2;
case 0x0c09ebd4u: goto P_0c09ebd4;
case 0x0c09ebd6u: goto P_0c09ebd6;
case 0x0c09ebd8u: goto P_0c09ebd8;
case 0x0c09ebdau: goto P_0c09ebda;
case 0x0c09ebdcu: goto P_0c09ebdc;
case 0x0c09ebdeu: goto P_0c09ebde;
case 0x0c09ebe0u: goto P_0c09ebe0;
case 0x0c09ebe2u: goto P_0c09ebe2;
case 0x0c09ebe4u: goto P_0c09ebe4;
case 0x0c09ebe6u: goto P_0c09ebe6;
case 0x0c09ebe8u: goto P_0c09ebe8;
case 0x0c09ebeau: goto P_0c09ebea;
case 0x0c09ebecu: goto P_0c09ebec;
case 0x0c09ebeeu: goto P_0c09ebee;
case 0x0c09ebf0u: goto P_0c09ebf0;
case 0x0c09ebf2u: goto P_0c09ebf2;
case 0x0c09ec44u: goto P_0c09ec44;
case 0x0c09ec46u: goto P_0c09ec46;
case 0x0c09ec48u: goto P_0c09ec48;
case 0x0c09ec4au: goto P_0c09ec4a;
case 0x0c09ec4cu: goto P_0c09ec4c;
case 0x0c09ec4eu: goto P_0c09ec4e;
case 0x0c09ec50u: goto P_0c09ec50;
case 0x0c09ec52u: goto P_0c09ec52;
case 0x0c09ec54u: goto P_0c09ec54;
case 0x0c09ec56u: goto P_0c09ec56;
case 0x0c09ec58u: goto P_0c09ec58;
case 0x0c09ec5au: goto P_0c09ec5a;
case 0x0c09ec5cu: goto P_0c09ec5c;
case 0x0c09ec5eu: goto P_0c09ec5e;
case 0x0c09ec60u: goto P_0c09ec60;
case 0x0c09ec62u: goto P_0c09ec62;
case 0x0c09ec64u: goto P_0c09ec64;
case 0x0c09ec66u: goto P_0c09ec66;
case 0x0c09ec68u: goto P_0c09ec68;
case 0x0c09ec6au: goto P_0c09ec6a;
case 0x0c09ec6cu: goto P_0c09ec6c;
case 0x0c09ec6eu: goto P_0c09ec6e;
case 0x0c09ec70u: goto P_0c09ec70;
case 0x0c09ec72u: goto P_0c09ec72;
case 0x0c09ec74u: goto P_0c09ec74;
case 0x0c09ec76u: goto P_0c09ec76;
case 0x0c09ec78u: goto P_0c09ec78;
case 0x0c09ec7au: goto P_0c09ec7a;
case 0x0c09ec7cu: goto P_0c09ec7c;
case 0x0c09ec7eu: goto P_0c09ec7e;
case 0x0c09ec80u: goto P_0c09ec80;
case 0x0c09ec82u: goto P_0c09ec82;
case 0x0c09ec84u: goto P_0c09ec84;
case 0x0c09ec86u: goto P_0c09ec86;
case 0x0c09ec88u: goto P_0c09ec88;
case 0x0c09ec8au: goto P_0c09ec8a;
case 0x0c09ec8cu: goto P_0c09ec8c;
case 0x0c09ec8eu: goto P_0c09ec8e;
case 0x0c09ec90u: goto P_0c09ec90;
case 0x0c09ec92u: goto P_0c09ec92;
case 0x0c09ec94u: goto P_0c09ec94;
case 0x0c09ec96u: goto P_0c09ec96;
case 0x0c09ec98u: goto P_0c09ec98;
case 0x0c09ec9au: goto P_0c09ec9a;
case 0x0c09ec9cu: goto P_0c09ec9c;
case 0x0c09ec9eu: goto P_0c09ec9e;
case 0x0c09eca0u: goto P_0c09eca0;
case 0x0c09eca2u: goto P_0c09eca2;
case 0x0c09eca4u: goto P_0c09eca4;
case 0x0c09eca6u: goto P_0c09eca6;
case 0x0c09eca8u: goto P_0c09eca8;
case 0x0c09ecaau: goto P_0c09ecaa;
case 0x0c09ecacu: goto P_0c09ecac;
case 0x0c09ecaeu: goto P_0c09ecae;
case 0x0c09ecb0u: goto P_0c09ecb0;
case 0x0c09ecb2u: goto P_0c09ecb2;
case 0x0c09ecb4u: goto P_0c09ecb4;
case 0x0c09ecb6u: goto P_0c09ecb6;
case 0x0c09ecb8u: goto P_0c09ecb8;
case 0x0c09ecbau: goto P_0c09ecba;
case 0x0c09ecbcu: goto P_0c09ecbc;
case 0x0c09ecbeu: goto P_0c09ecbe;
case 0x0c09ecc0u: goto P_0c09ecc0;
case 0x0c09ecc2u: goto P_0c09ecc2;
case 0x0c09ecc4u: goto P_0c09ecc4;
case 0x0c09ecc6u: goto P_0c09ecc6;
case 0x0c09ecc8u: goto P_0c09ecc8;
case 0x0c09eccau: goto P_0c09ecca;
case 0x0c09ecccu: goto P_0c09eccc;
case 0x0c09ecceu: goto P_0c09ecce;
case 0x0c09ecd0u: goto P_0c09ecd0;
case 0x0c09ecd2u: goto P_0c09ecd2;
case 0x0c09ecd4u: goto P_0c09ecd4;
case 0x0c09ecd6u: goto P_0c09ecd6;
case 0x0c09ecd8u: goto P_0c09ecd8;
case 0x0c09ecdau: goto P_0c09ecda;
case 0x0c09ecdcu: goto P_0c09ecdc;
case 0x0c09ecdeu: goto P_0c09ecde;
case 0x0c09ece0u: goto P_0c09ece0;
case 0x0c09ece2u: goto P_0c09ece2;
case 0x0c09ece4u: goto P_0c09ece4;
case 0x0c09ece6u: goto P_0c09ece6;
case 0x0c09ece8u: goto P_0c09ece8;
case 0x0c09eceau: goto P_0c09ecea;
case 0x0c09ececu: goto P_0c09ecec;
case 0x0c09eceeu: goto P_0c09ecee;
case 0x0c09ecf0u: goto P_0c09ecf0;
case 0x0c09ecf2u: goto P_0c09ecf2;
case 0x0c09ecf4u: goto P_0c09ecf4;
case 0x0c09ecf6u: goto P_0c09ecf6;
case 0x0c09ecf8u: goto P_0c09ecf8;
case 0x0c09ecfau: goto P_0c09ecfa;
case 0x0c09ecfcu: goto P_0c09ecfc;
case 0x0c09ecfeu: goto P_0c09ecfe;
case 0x0c09ed00u: goto P_0c09ed00;
case 0x0c09ed02u: goto P_0c09ed02;
case 0x0c09ed04u: goto P_0c09ed04;
case 0x0c09ed06u: goto P_0c09ed06;
case 0x0c09ed08u: goto P_0c09ed08;
case 0x0c09ed0au: goto P_0c09ed0a;
case 0x0c09ed0cu: goto P_0c09ed0c;
case 0x0c09ed0eu: goto P_0c09ed0e;
case 0x0c09ed10u: goto P_0c09ed10;
case 0x0c09ed12u: goto P_0c09ed12;
case 0x0c09ed14u: goto P_0c09ed14;
case 0x0c09ed16u: goto P_0c09ed16;
case 0x0c09ed18u: goto P_0c09ed18;
case 0x0c09ed1au: goto P_0c09ed1a;
case 0x0c09ed1cu: goto P_0c09ed1c;
case 0x0c09ed1eu: goto P_0c09ed1e;
case 0x0c09ed20u: goto P_0c09ed20;
case 0x0c09ed22u: goto P_0c09ed22;
case 0x0c09ed24u: goto P_0c09ed24;
case 0x0c09ed26u: goto P_0c09ed26;
case 0x0c09ed28u: goto P_0c09ed28;
case 0x0c09ed2au: goto P_0c09ed2a;
case 0x0c09ed2cu: goto P_0c09ed2c;
case 0x0c09ed2eu: goto P_0c09ed2e;
case 0x0c09ed30u: goto P_0c09ed30;
case 0x0c09ed32u: goto P_0c09ed32;
case 0x0c09ed34u: goto P_0c09ed34;
case 0x0c09ed36u: goto P_0c09ed36;
case 0x0c09ed38u: goto P_0c09ed38;
case 0x0c09ed3au: goto P_0c09ed3a;
case 0x0c09ed3cu: goto P_0c09ed3c;
case 0x0c09ed3eu: goto P_0c09ed3e;
case 0x0c09ed40u: goto P_0c09ed40;
case 0x0c09ed42u: goto P_0c09ed42;
case 0x0c09ed44u: goto P_0c09ed44;
case 0x0c09ed46u: goto P_0c09ed46;
case 0x0c09ed48u: goto P_0c09ed48;
case 0x0c09ed4au: goto P_0c09ed4a;
case 0x0c09ed4cu: goto P_0c09ed4c;
case 0x0c09ed4eu: goto P_0c09ed4e;
case 0x0c09ed50u: goto P_0c09ed50;
case 0x0c09ed52u: goto P_0c09ed52;
case 0x0c09ed54u: goto P_0c09ed54;
case 0x0c09ed56u: goto P_0c09ed56;
case 0x0c09ed58u: goto P_0c09ed58;
case 0x0c09ed5au: goto P_0c09ed5a;
case 0x0c09ed5cu: goto P_0c09ed5c;
case 0x0c09ed5eu: goto P_0c09ed5e;
case 0x0c09ed60u: goto P_0c09ed60;
case 0x0c09ed62u: goto P_0c09ed62;
case 0x0c09ed64u: goto P_0c09ed64;
case 0x0c09ed66u: goto P_0c09ed66;
case 0x0c09ed68u: goto P_0c09ed68;
case 0x0c09ed6au: goto P_0c09ed6a;
case 0x0c09ed6cu: goto P_0c09ed6c;
case 0x0c09ed6eu: goto P_0c09ed6e;
case 0x0c09ed70u: goto P_0c09ed70;
case 0x0c09ed72u: goto P_0c09ed72;
case 0x0c09ed74u: goto P_0c09ed74;
case 0x0c09ed76u: goto P_0c09ed76;
case 0x0c09ed78u: goto P_0c09ed78;
case 0x0c09ed7au: goto P_0c09ed7a;
case 0x0c09ed7cu: goto P_0c09ed7c;
case 0x0c09ed7eu: goto P_0c09ed7e;
case 0x0c09ed80u: goto P_0c09ed80;
case 0x0c09ed82u: goto P_0c09ed82;
case 0x0c09ed84u: goto P_0c09ed84;
case 0x0c09ed86u: goto P_0c09ed86;
case 0x0c09ed88u: goto P_0c09ed88;
case 0x0c09ed8au: goto P_0c09ed8a;
case 0x0c09ed8cu: goto P_0c09ed8c;
case 0x0c09ed8eu: goto P_0c09ed8e;
case 0x0c09ed90u: goto P_0c09ed90;
case 0x0c09ed92u: goto P_0c09ed92;
case 0x0c09ed94u: goto P_0c09ed94;
case 0x0c09ed96u: goto P_0c09ed96;
case 0x0c09ed98u: goto P_0c09ed98;
case 0x0c09ed9au: goto P_0c09ed9a;
case 0x0c09ed9cu: goto P_0c09ed9c;
case 0x0c09ed9eu: goto P_0c09ed9e;
case 0x0c09eda0u: goto P_0c09eda0;
case 0x0c09eda2u: goto P_0c09eda2;
case 0x0c09eda4u: goto P_0c09eda4;
case 0x0c09eda6u: goto P_0c09eda6;
case 0x0c09eda8u: goto P_0c09eda8;
case 0x0c09edaau: goto P_0c09edaa;
case 0x0c09edacu: goto P_0c09edac;
case 0x0c09edaeu: goto P_0c09edae;
case 0x0c09edb0u: goto P_0c09edb0;
case 0x0c09edf8u: goto P_0c09edf8;
case 0x0c09edfau: goto P_0c09edfa;
case 0x0c09edfcu: goto P_0c09edfc;
case 0x0c09edfeu: goto P_0c09edfe;
case 0x0c09ee00u: goto P_0c09ee00;
case 0x0c09ee02u: goto P_0c09ee02;
case 0x0c09ee04u: goto P_0c09ee04;
case 0x0c09ee06u: goto P_0c09ee06;
case 0x0c09ee08u: goto P_0c09ee08;
case 0x0c09ee0au: goto P_0c09ee0a;
case 0x0c09ee0cu: goto P_0c09ee0c;
case 0x0c09ee0eu: goto P_0c09ee0e;
case 0x0c09ee10u: goto P_0c09ee10;
case 0x0c09ee12u: goto P_0c09ee12;
case 0x0c09ee14u: goto P_0c09ee14;
case 0x0c09ee16u: goto P_0c09ee16;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09ea66: /* original 2fe6, guest PC 0x0c09ea66 */
if(!s->budget--) { s->failed_pc=0x0c09ea66u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ea68;
P_0c09ea68: /* original 9038, guest PC 0x0c09ea68 */
if(!s->budget--) { s->failed_pc=0x0c09ea68u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09eadcu,2);
goto P_0c09ea6a;
P_0c09ea6a: /* original 0e4e, guest PC 0x0c09ea6a */
if(!s->budget--) { s->failed_pc=0x0c09ea6au; return 0; }
r[14]=read(ram,r[4]+r[0],4);
goto P_0c09ea6c;
P_0c09ea6c: /* original 70fc, guest PC 0x0c09ea6c */
if(!s->budget--) { s->failed_pc=0x0c09ea6cu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09ea6e;
P_0c09ea6e: /* original 034e, guest PC 0x0c09ea6e */
if(!s->budget--) { s->failed_pc=0x0c09ea6eu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c09ea70;
P_0c09ea70: /* original 7004, guest PC 0x0c09ea70 */
if(!s->budget--) { s->failed_pc=0x0c09ea70u; return 0; }
r[0]+=0x00000004u;
goto P_0c09ea72;
P_0c09ea72: /* original 0436, guest PC 0x0c09ea72 */
if(!s->budget--) { s->failed_pc=0x0c09ea72u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c09ea74;
P_0c09ea74: /* original 70fc, guest PC 0x0c09ea74 */
if(!s->budget--) { s->failed_pc=0x0c09ea74u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09ea76;
P_0c09ea76: /* original 04e6, guest PC 0x0c09ea76 */
if(!s->budget--) { s->failed_pc=0x0c09ea76u; return 0; }
write(ram,r[4]+r[0],r[14],4);
goto P_0c09ea78;
P_0c09ea78: /* original 9031, guest PC 0x0c09ea78 */
if(!s->budget--) { s->failed_pc=0x0c09ea78u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09eadeu,2);
goto P_0c09ea7a;
P_0c09ea7a: /* original f48d, guest PC 0x0c09ea7a */
if(!s->budget--) { s->failed_pc=0x0c09ea7au; return 0; }
fr[4]=0;
goto P_0c09ea7c;
P_0c09ea7c: /* original f447, guest PC 0x0c09ea7c */
if(!s->budget--) { s->failed_pc=0x0c09ea7cu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09ea7e;
P_0c09ea7e: /* original 7004, guest PC 0x0c09ea7e */
if(!s->budget--) { s->failed_pc=0x0c09ea7eu; return 0; }
r[0]+=0x00000004u;
goto P_0c09ea80;
P_0c09ea80: /* original f447, guest PC 0x0c09ea80 */
if(!s->budget--) { s->failed_pc=0x0c09ea80u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09ea82;
P_0c09ea82: /* original 7004, guest PC 0x0c09ea82 */
if(!s->budget--) { s->failed_pc=0x0c09ea82u; return 0; }
r[0]+=0x00000004u;
goto P_0c09ea84;
P_0c09ea84: /* original f447, guest PC 0x0c09ea84 */
if(!s->budget--) { s->failed_pc=0x0c09ea84u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09ea86;
P_0c09ea86: /* original 7004, guest PC 0x0c09ea86 */
if(!s->budget--) { s->failed_pc=0x0c09ea86u; return 0; }
r[0]+=0x00000004u;
goto P_0c09ea88;
P_0c09ea88: /* original f447, guest PC 0x0c09ea88 */
if(!s->budget--) { s->failed_pc=0x0c09ea88u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09ea8a;
P_0c09ea8a: /* original 7004, guest PC 0x0c09ea8a */
if(!s->budget--) { s->failed_pc=0x0c09ea8au; return 0; }
r[0]+=0x00000004u;
goto P_0c09ea8c;
P_0c09ea8c: /* original f447, guest PC 0x0c09ea8c */
if(!s->budget--) { s->failed_pc=0x0c09ea8cu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09ea8e;
P_0c09ea8e: /* original 7004, guest PC 0x0c09ea8e */
if(!s->budget--) { s->failed_pc=0x0c09ea8eu; return 0; }
r[0]+=0x00000004u;
goto P_0c09ea90;
P_0c09ea90: /* original f447, guest PC 0x0c09ea90 */
if(!s->budget--) { s->failed_pc=0x0c09ea90u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09ea92;
P_0c09ea92: /* original 7004, guest PC 0x0c09ea92 */
if(!s->budget--) { s->failed_pc=0x0c09ea92u; return 0; }
r[0]+=0x00000004u;
goto P_0c09ea94;
P_0c09ea94: /* original f447, guest PC 0x0c09ea94 */
if(!s->budget--) { s->failed_pc=0x0c09ea94u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09ea96;
P_0c09ea96: /* original 7004, guest PC 0x0c09ea96 */
if(!s->budget--) { s->failed_pc=0x0c09ea96u; return 0; }
r[0]+=0x00000004u;
goto P_0c09ea98;
P_0c09ea98: /* original f447, guest PC 0x0c09ea98 */
if(!s->budget--) { s->failed_pc=0x0c09ea98u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09ea9a;
P_0c09ea9a: /* original 7004, guest PC 0x0c09ea9a */
if(!s->budget--) { s->failed_pc=0x0c09ea9au; return 0; }
r[0]+=0x00000004u;
goto P_0c09ea9c;
P_0c09ea9c: /* original f447, guest PC 0x0c09ea9c */
if(!s->budget--) { s->failed_pc=0x0c09ea9cu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09ea9e;
P_0c09ea9e: /* original 7004, guest PC 0x0c09ea9e */
if(!s->budget--) { s->failed_pc=0x0c09ea9eu; return 0; }
r[0]+=0x00000004u;
goto P_0c09eaa0;
P_0c09eaa0: /* original f447, guest PC 0x0c09eaa0 */
if(!s->budget--) { s->failed_pc=0x0c09eaa0u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09eaa2;
P_0c09eaa2: /* original 7004, guest PC 0x0c09eaa2 */
if(!s->budget--) { s->failed_pc=0x0c09eaa2u; return 0; }
r[0]+=0x00000004u;
goto P_0c09eaa4;
P_0c09eaa4: /* original f447, guest PC 0x0c09eaa4 */
if(!s->budget--) { s->failed_pc=0x0c09eaa4u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09eaa6;
P_0c09eaa6: /* original 7004, guest PC 0x0c09eaa6 */
if(!s->budget--) { s->failed_pc=0x0c09eaa6u; return 0; }
r[0]+=0x00000004u;
goto P_0c09eaa8;
P_0c09eaa8: /* original f447, guest PC 0x0c09eaa8 */
if(!s->budget--) { s->failed_pc=0x0c09eaa8u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09eaaa;
P_0c09eaaa: /* original 7004, guest PC 0x0c09eaaa */
if(!s->budget--) { s->failed_pc=0x0c09eaaau; return 0; }
r[0]+=0x00000004u;
goto P_0c09eaac;
P_0c09eaac: /* original f447, guest PC 0x0c09eaac */
if(!s->budget--) { s->failed_pc=0x0c09eaacu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09eaae;
P_0c09eaae: /* original 7004, guest PC 0x0c09eaae */
if(!s->budget--) { s->failed_pc=0x0c09eaaeu; return 0; }
r[0]+=0x00000004u;
goto P_0c09eab0;
P_0c09eab0: /* original f447, guest PC 0x0c09eab0 */
if(!s->budget--) { s->failed_pc=0x0c09eab0u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09eab2;
P_0c09eab2: /* original 7004, guest PC 0x0c09eab2 */
if(!s->budget--) { s->failed_pc=0x0c09eab2u; return 0; }
r[0]+=0x00000004u;
goto P_0c09eab4;
P_0c09eab4: /* original f447, guest PC 0x0c09eab4 */
if(!s->budget--) { s->failed_pc=0x0c09eab4u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09eab6;
P_0c09eab6: /* original e500, guest PC 0x0c09eab6 */
if(!s->budget--) { s->failed_pc=0x0c09eab6u; return 0; }
r[5]=0x00000000u;
goto P_0c09eab8;
P_0c09eab8: /* original 9012, guest PC 0x0c09eab8 */
if(!s->budget--) { s->failed_pc=0x0c09eab8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09eae0u,2);
goto P_0c09eaba;
P_0c09eaba: /* original 0455, guest PC 0x0c09eaba */
if(!s->budget--) { s->failed_pc=0x0c09eabau; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c09eabc;
P_0c09eabc: /* original 7028, guest PC 0x0c09eabc */
if(!s->budget--) { s->failed_pc=0x0c09eabcu; return 0; }
r[0]+=0x00000028u;
goto P_0c09eabe;
P_0c09eabe: /* original 0455, guest PC 0x0c09eabe */
if(!s->budget--) { s->failed_pc=0x0c09eabeu; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c09eac0;
P_0c09eac0: /* original 7004, guest PC 0x0c09eac0 */
if(!s->budget--) { s->failed_pc=0x0c09eac0u; return 0; }
r[0]+=0x00000004u;
goto P_0c09eac2;
P_0c09eac2: /* original 0455, guest PC 0x0c09eac2 */
if(!s->budget--) { s->failed_pc=0x0c09eac2u; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c09eac4;
P_0c09eac4: /* original 7020, guest PC 0x0c09eac4 */
if(!s->budget--) { s->failed_pc=0x0c09eac4u; return 0; }
r[0]+=0x00000020u;
goto P_0c09eac6;
P_0c09eac6: /* original f447, guest PC 0x0c09eac6 */
if(!s->budget--) { s->failed_pc=0x0c09eac6u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09eac8;
P_0c09eac8: /* original 70b6, guest PC 0x0c09eac8 */
if(!s->budget--) { s->failed_pc=0x0c09eac8u; return 0; }
r[0]+=0xffffffb6u;
goto P_0c09eaca;
P_0c09eaca: /* original 0455, guest PC 0x0c09eaca */
if(!s->budget--) { s->failed_pc=0x0c09eacau; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c09eacc;
P_0c09eacc: /* original 702c, guest PC 0x0c09eacc */
if(!s->budget--) { s->failed_pc=0x0c09eaccu; return 0; }
r[0]+=0x0000002cu;
goto P_0c09eace;
P_0c09eace: /* original 0455, guest PC 0x0c09eace */
if(!s->budget--) { s->failed_pc=0x0c09eaceu; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c09ead0;
P_0c09ead0: /* original 70fc, guest PC 0x0c09ead0 */
if(!s->budget--) { s->failed_pc=0x0c09ead0u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09ead2;
P_0c09ead2: /* original 0455, guest PC 0x0c09ead2 */
if(!s->budget--) { s->failed_pc=0x0c09ead2u; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c09ead4;
P_0c09ead4: /* original 65e3, guest PC 0x0c09ead4 */
if(!s->budget--) { s->failed_pc=0x0c09ead4u; return 0; }
r[5]=r[14];
goto P_0c09ead6;
P_0c09ead6: /* original a004, guest PC 0x0c09ead6 */
if(!s->budget--) { s->failed_pc=0x0c09ead6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09eae2;
P_0c09ead8: /* original 6ef6, guest PC 0x0c09ead8 */
if(!s->budget--) { s->failed_pc=0x0c09ead8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09eadau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09eadau; return 0; } return 1;
P_0c09eae2: /* original 2fe6, guest PC 0x0c09eae2 */
if(!s->budget--) { s->failed_pc=0x0c09eae2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09eae4;
P_0c09eae4: /* original 6e43, guest PC 0x0c09eae4 */
if(!s->budget--) { s->failed_pc=0x0c09eae4u; return 0; }
r[14]=r[4];
goto P_0c09eae6;
P_0c09eae6: /* original 2fd6, guest PC 0x0c09eae6 */
if(!s->budget--) { s->failed_pc=0x0c09eae6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09eae8;
P_0c09eae8: /* original 2fc6, guest PC 0x0c09eae8 */
if(!s->budget--) { s->failed_pc=0x0c09eae8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09eaea;
P_0c09eaea: /* original 2fb6, guest PC 0x0c09eaea */
if(!s->budget--) { s->failed_pc=0x0c09eaeau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09eaec;
P_0c09eaec: /* original 2fa6, guest PC 0x0c09eaec */
if(!s->budget--) { s->failed_pc=0x0c09eaecu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09eaee;
P_0c09eaee: /* original 2f96, guest PC 0x0c09eaee */
if(!s->budget--) { s->failed_pc=0x0c09eaeeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09eaf0;
P_0c09eaf0: /* original 2f86, guest PC 0x0c09eaf0 */
if(!s->budget--) { s->failed_pc=0x0c09eaf0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09eaf2;
P_0c09eaf2: /* original 4f22, guest PC 0x0c09eaf2 */
if(!s->budget--) { s->failed_pc=0x0c09eaf2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09eaf4;
P_0c09eaf4: /* original 907e, guest PC 0x0c09eaf4 */
if(!s->budget--) { s->failed_pc=0x0c09eaf4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ebf4u,2);
goto P_0c09eaf6;
P_0c09eaf6: /* original d346, guest PC 0x0c09eaf6 */
if(!s->budget--) { s->failed_pc=0x0c09eaf6u; return 0; }
r[3]=read(ram,0x0c09ec10u,4);
goto P_0c09eaf8;
P_0c09eaf8: /* original 4f12, guest PC 0x0c09eaf8 */
if(!s->budget--) { s->failed_pc=0x0c09eaf8u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c09eafa;
P_0c09eafa: /* original 3f0c, guest PC 0x0c09eafa */
if(!s->budget--) { s->failed_pc=0x0c09eafau; return 0; }
r[15]+=r[0];
goto P_0c09eafc;
P_0c09eafc: /* original 430b, guest PC 0x0c09eafc */
if(!s->budget--) { s->failed_pc=0x0c09eafcu; return 0; }
target=r[3];
r[16]=code_base|0x0c09eb00u;
r[12]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eb00u) { target=s->pc; goto dispatch; }
goto P_0c09eb00;
P_0c09eafe: /* original 6c53, guest PC 0x0c09eafe */
if(!s->budget--) { s->failed_pc=0x0c09eafeu; return 0; }
r[12]=r[5];
goto P_0c09eb00;
P_0c09eb00: /* original 9479, guest PC 0x0c09eb00 */
if(!s->budget--) { s->failed_pc=0x0c09eb00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ebf6u,2);
goto P_0c09eb02;
P_0c09eb02: /* original dd44, guest PC 0x0c09eb02 */
if(!s->budget--) { s->failed_pc=0x0c09eb02u; return 0; }
r[13]=read(ram,0x0c09ec14u,4);
goto P_0c09eb04;
P_0c09eb04: /* original 4d0b, guest PC 0x0c09eb04 */
if(!s->budget--) { s->failed_pc=0x0c09eb04u; return 0; }
target=r[13];
r[16]=code_base|0x0c09eb08u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eb08u) { target=s->pc; goto dispatch; }
goto P_0c09eb08;
P_0c09eb06: /* original 34fc, guest PC 0x0c09eb06 */
if(!s->budget--) { s->failed_pc=0x0c09eb06u; return 0; }
r[4]+=r[15];
goto P_0c09eb08;
P_0c09eb08: /* original 64f3, guest PC 0x0c09eb08 */
if(!s->budget--) { s->failed_pc=0x0c09eb08u; return 0; }
r[4]=r[15];
goto P_0c09eb0a;
P_0c09eb0a: /* original 4d0b, guest PC 0x0c09eb0a */
if(!s->budget--) { s->failed_pc=0x0c09eb0au; return 0; }
target=r[13];
r[16]=code_base|0x0c09eb0eu;
r[4]+=0x00000064u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eb0eu) { target=s->pc; goto dispatch; }
goto P_0c09eb0e;
P_0c09eb0c: /* original 7464, guest PC 0x0c09eb0c */
if(!s->budget--) { s->failed_pc=0x0c09eb0cu; return 0; }
r[4]+=0x00000064u;
goto P_0c09eb0e;
P_0c09eb0e: /* original 64f3, guest PC 0x0c09eb0e */
if(!s->budget--) { s->failed_pc=0x0c09eb0eu; return 0; }
r[4]=r[15];
goto P_0c09eb10;
P_0c09eb10: /* original 4d0b, guest PC 0x0c09eb10 */
if(!s->budget--) { s->failed_pc=0x0c09eb10u; return 0; }
target=r[13];
r[16]=code_base|0x0c09eb14u;
r[4]+=0x00000024u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eb14u) { target=s->pc; goto dispatch; }
goto P_0c09eb14;
P_0c09eb12: /* original 7424, guest PC 0x0c09eb12 */
if(!s->budget--) { s->failed_pc=0x0c09eb12u; return 0; }
r[4]+=0x00000024u;
goto P_0c09eb14;
P_0c09eb14: /* original e061, guest PC 0x0c09eb14 */
if(!s->budget--) { s->failed_pc=0x0c09eb14u; return 0; }
r[0]=0x00000061u;
goto P_0c09eb16;
P_0c09eb16: /* original d240, guest PC 0x0c09eb16 */
if(!s->budget--) { s->failed_pc=0x0c09eb16u; return 0; }
r[2]=read(ram,0x0c09ec18u,4);
goto P_0c09eb18;
P_0c09eb18: /* original 0dec, guest PC 0x0c09eb18 */
if(!s->budget--) { s->failed_pc=0x0c09eb18u; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09eb1a;
P_0c09eb1a: /* original e36c, guest PC 0x0c09eb1a */
if(!s->budget--) { s->failed_pc=0x0c09eb1au; return 0; }
r[3]=0x0000006cu;
goto P_0c09eb1c;
P_0c09eb1c: /* original 6ddc, guest PC 0x0c09eb1c */
if(!s->budget--) { s->failed_pc=0x0c09eb1cu; return 0; }
r[13]=r[13]&255u;
goto P_0c09eb1e;
P_0c09eb1e: /* original 2d3f, guest PC 0x0c09eb1e */
if(!s->budget--) { s->failed_pc=0x0c09eb1eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[3]);
goto P_0c09eb20;
P_0c09eb20: /* original d33e, guest PC 0x0c09eb20 */
if(!s->budget--) { s->failed_pc=0x0c09eb20u; return 0; }
r[3]=read(ram,0x0c09ec1cu,4);
goto P_0c09eb22;
P_0c09eb22: /* original 0d1a, guest PC 0x0c09eb22 */
if(!s->budget--) { s->failed_pc=0x0c09eb22u; return 0; }
r[13]=r[19];
goto P_0c09eb24;
P_0c09eb24: /* original 6ddf, guest PC 0x0c09eb24 */
if(!s->budget--) { s->failed_pc=0x0c09eb24u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c09eb26;
P_0c09eb26: /* original 3d2c, guest PC 0x0c09eb26 */
if(!s->budget--) { s->failed_pc=0x0c09eb26u; return 0; }
r[13]+=r[2];
goto P_0c09eb28;
P_0c09eb28: /* original 430b, guest PC 0x0c09eb28 */
if(!s->budget--) { s->failed_pc=0x0c09eb28u; return 0; }
target=r[3];
r[16]=code_base|0x0c09eb2cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eb2cu) { target=s->pc; goto dispatch; }
goto P_0c09eb2c;
P_0c09eb2a: /* original 64e3, guest PC 0x0c09eb2a */
if(!s->budget--) { s->failed_pc=0x0c09eb2au; return 0; }
r[4]=r[14];
goto P_0c09eb2c;
P_0c09eb2c: /* original d23c, guest PC 0x0c09eb2c */
if(!s->budget--) { s->failed_pc=0x0c09eb2cu; return 0; }
r[2]=read(ram,0x0c09ec20u,4);
goto P_0c09eb2e;
P_0c09eb2e: /* original 420b, guest PC 0x0c09eb2e */
if(!s->budget--) { s->failed_pc=0x0c09eb2eu; return 0; }
target=r[2];
r[16]=code_base|0x0c09eb32u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eb32u) { target=s->pc; goto dispatch; }
goto P_0c09eb32;
P_0c09eb30: /* original 64e3, guest PC 0x0c09eb30 */
if(!s->budget--) { s->failed_pc=0x0c09eb30u; return 0; }
r[4]=r[14];
goto P_0c09eb32;
P_0c09eb32: /* original d33c, guest PC 0x0c09eb32 */
if(!s->budget--) { s->failed_pc=0x0c09eb32u; return 0; }
r[3]=read(ram,0x0c09ec24u,4);
goto P_0c09eb34;
P_0c09eb34: /* original 9460, guest PC 0x0c09eb34 */
if(!s->budget--) { s->failed_pc=0x0c09eb34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ebf8u,2);
goto P_0c09eb36;
P_0c09eb36: /* original 430b, guest PC 0x0c09eb36 */
if(!s->budget--) { s->failed_pc=0x0c09eb36u; return 0; }
target=r[3];
r[16]=code_base|0x0c09eb3au;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eb3au) { target=s->pc; goto dispatch; }
goto P_0c09eb3a;
P_0c09eb38: /* original 34ec, guest PC 0x0c09eb38 */
if(!s->budget--) { s->failed_pc=0x0c09eb38u; return 0; }
r[4]+=r[14];
goto P_0c09eb3a;
P_0c09eb3a: /* original 945e, guest PC 0x0c09eb3a */
if(!s->budget--) { s->failed_pc=0x0c09eb3au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ebfau,2);
goto P_0c09eb3c;
P_0c09eb3c: /* original db3a, guest PC 0x0c09eb3c */
if(!s->budget--) { s->failed_pc=0x0c09eb3cu; return 0; }
r[11]=read(ram,0x0c09ec28u,4);
goto P_0c09eb3e;
P_0c09eb3e: /* original 4b0b, guest PC 0x0c09eb3e */
if(!s->budget--) { s->failed_pc=0x0c09eb3eu; return 0; }
target=r[11];
r[16]=code_base|0x0c09eb42u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eb42u) { target=s->pc; goto dispatch; }
goto P_0c09eb42;
P_0c09eb40: /* original 34fc, guest PC 0x0c09eb40 */
if(!s->budget--) { s->failed_pc=0x0c09eb40u; return 0; }
r[4]+=r[15];
goto P_0c09eb42;
P_0c09eb42: /* original 945b, guest PC 0x0c09eb42 */
if(!s->budget--) { s->failed_pc=0x0c09eb42u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ebfcu,2);
goto P_0c09eb44;
P_0c09eb44: /* original 4b0b, guest PC 0x0c09eb44 */
if(!s->budget--) { s->failed_pc=0x0c09eb44u; return 0; }
target=r[11];
r[16]=code_base|0x0c09eb48u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eb48u) { target=s->pc; goto dispatch; }
goto P_0c09eb48;
P_0c09eb46: /* original 34fc, guest PC 0x0c09eb46 */
if(!s->budget--) { s->failed_pc=0x0c09eb46u; return 0; }
r[4]+=r[15];
goto P_0c09eb48;
P_0c09eb48: /* original 64f3, guest PC 0x0c09eb48 */
if(!s->budget--) { s->failed_pc=0x0c09eb48u; return 0; }
r[4]=r[15];
goto P_0c09eb4a;
P_0c09eb4a: /* original 4b0b, guest PC 0x0c09eb4a */
if(!s->budget--) { s->failed_pc=0x0c09eb4au; return 0; }
target=r[11];
r[16]=code_base|0x0c09eb4eu;
r[4]+=0x00000054u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eb4eu) { target=s->pc; goto dispatch; }
goto P_0c09eb4e;
P_0c09eb4c: /* original 7454, guest PC 0x0c09eb4c */
if(!s->budget--) { s->failed_pc=0x0c09eb4cu; return 0; }
r[4]+=0x00000054u;
goto P_0c09eb4e;
P_0c09eb4e: /* original d937, guest PC 0x0c09eb4e */
if(!s->budget--) { s->failed_pc=0x0c09eb4eu; return 0; }
r[9]=read(ram,0x0c09ec2cu,4);
goto P_0c09eb50;
P_0c09eb50: /* original 490b, guest PC 0x0c09eb50 */
if(!s->budget--) { s->failed_pc=0x0c09eb50u; return 0; }
target=r[9];
r[16]=code_base|0x0c09eb54u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eb54u) { target=s->pc; goto dispatch; }
goto P_0c09eb54;
P_0c09eb52: /* original e400, guest PC 0x0c09eb52 */
if(!s->budget--) { s->failed_pc=0x0c09eb52u; return 0; }
r[4]=0x00000000u;
goto P_0c09eb54;
P_0c09eb54: /* original 9053, guest PC 0x0c09eb54 */
if(!s->budget--) { s->failed_pc=0x0c09eb54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ebfeu,2);
goto P_0c09eb56;
P_0c09eb56: /* original d336, guest PC 0x0c09eb56 */
if(!s->budget--) { s->failed_pc=0x0c09eb56u; return 0; }
r[3]=read(ram,0x0c09ec30u,4);
goto P_0c09eb58;
P_0c09eb58: /* original 9452, guest PC 0x0c09eb58 */
if(!s->budget--) { s->failed_pc=0x0c09eb58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ec00u,2);
goto P_0c09eb5a;
P_0c09eb5a: /* original 05ed, guest PC 0x0c09eb5a */
if(!s->budget--) { s->failed_pc=0x0c09eb5au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09eb5c;
P_0c09eb5c: /* original 430b, guest PC 0x0c09eb5c */
if(!s->budget--) { s->failed_pc=0x0c09eb5cu; return 0; }
target=r[3];
r[16]=code_base|0x0c09eb60u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eb60u) { target=s->pc; goto dispatch; }
goto P_0c09eb60;
P_0c09eb5e: /* original 34ec, guest PC 0x0c09eb5e */
if(!s->budget--) { s->failed_pc=0x0c09eb5eu; return 0; }
r[4]+=r[14];
goto P_0c09eb60;
P_0c09eb60: /* original 904f, guest PC 0x0c09eb60 */
if(!s->budget--) { s->failed_pc=0x0c09eb60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ec02u,2);
goto P_0c09eb62;
P_0c09eb62: /* original 66f3, guest PC 0x0c09eb62 */
if(!s->budget--) { s->failed_pc=0x0c09eb62u; return 0; }
r[6]=r[15];
goto P_0c09eb64;
P_0c09eb64: /* original 65f3, guest PC 0x0c09eb64 */
if(!s->budget--) { s->failed_pc=0x0c09eb64u; return 0; }
r[5]=r[15];
goto P_0c09eb66;
P_0c09eb66: /* original 7504, guest PC 0x0c09eb66 */
if(!s->budget--) { s->failed_pc=0x0c09eb66u; return 0; }
r[5]+=0x00000004u;
goto P_0c09eb68;
P_0c09eb68: /* original f3e6, guest PC 0x0c09eb68 */
if(!s->budget--) { s->failed_pc=0x0c09eb68u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09eb6a;
P_0c09eb6a: /* original 64f3, guest PC 0x0c09eb6a */
if(!s->budget--) { s->failed_pc=0x0c09eb6au; return 0; }
r[4]=r[15];
goto P_0c09eb6c;
P_0c09eb6c: /* original 904a, guest PC 0x0c09eb6c */
if(!s->budget--) { s->failed_pc=0x0c09eb6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ec04u,2);
goto P_0c09eb6e;
P_0c09eb6e: /* original 7608, guest PC 0x0c09eb6e */
if(!s->budget--) { s->failed_pc=0x0c09eb6eu; return 0; }
r[6]+=0x00000008u;
goto P_0c09eb70;
P_0c09eb70: /* original f2e6, guest PC 0x0c09eb70 */
if(!s->budget--) { s->failed_pc=0x0c09eb70u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c09eb72;
P_0c09eb72: /* original e018, guest PC 0x0c09eb72 */
if(!s->budget--) { s->failed_pc=0x0c09eb72u; return 0; }
r[0]=0x00000018u;
goto P_0c09eb74;
P_0c09eb74: /* original f230, guest PC 0x0c09eb74 */
if(!s->budget--) { s->failed_pc=0x0c09eb74u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c09eb76;
P_0c09eb76: /* original ff27, guest PC 0x0c09eb76 */
if(!s->budget--) { s->failed_pc=0x0c09eb76u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c09eb78;
P_0c09eb78: /* original 9045, guest PC 0x0c09eb78 */
if(!s->budget--) { s->failed_pc=0x0c09eb78u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ec06u,2);
goto P_0c09eb7a;
P_0c09eb7a: /* original f3e6, guest PC 0x0c09eb7a */
if(!s->budget--) { s->failed_pc=0x0c09eb7au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09eb7c;
P_0c09eb7c: /* original 9044, guest PC 0x0c09eb7c */
if(!s->budget--) { s->failed_pc=0x0c09eb7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ec08u,2);
goto P_0c09eb7e;
P_0c09eb7e: /* original f2e6, guest PC 0x0c09eb7e */
if(!s->budget--) { s->failed_pc=0x0c09eb7eu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c09eb80;
P_0c09eb80: /* original e01c, guest PC 0x0c09eb80 */
if(!s->budget--) { s->failed_pc=0x0c09eb80u; return 0; }
r[0]=0x0000001cu;
goto P_0c09eb82;
P_0c09eb82: /* original f230, guest PC 0x0c09eb82 */
if(!s->budget--) { s->failed_pc=0x0c09eb82u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c09eb84;
P_0c09eb84: /* original ff27, guest PC 0x0c09eb84 */
if(!s->budget--) { s->failed_pc=0x0c09eb84u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c09eb86;
P_0c09eb86: /* original 9040, guest PC 0x0c09eb86 */
if(!s->budget--) { s->failed_pc=0x0c09eb86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ec0au,2);
goto P_0c09eb88;
P_0c09eb88: /* original f3e6, guest PC 0x0c09eb88 */
if(!s->budget--) { s->failed_pc=0x0c09eb88u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09eb8a;
P_0c09eb8a: /* original 903f, guest PC 0x0c09eb8a */
if(!s->budget--) { s->failed_pc=0x0c09eb8au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ec0cu,2);
goto P_0c09eb8c;
P_0c09eb8c: /* original f2e6, guest PC 0x0c09eb8c */
if(!s->budget--) { s->failed_pc=0x0c09eb8cu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c09eb8e;
P_0c09eb8e: /* original e020, guest PC 0x0c09eb8e */
if(!s->budget--) { s->failed_pc=0x0c09eb8eu; return 0; }
r[0]=0x00000020u;
goto P_0c09eb90;
P_0c09eb90: /* original f230, guest PC 0x0c09eb90 */
if(!s->budget--) { s->failed_pc=0x0c09eb90u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c09eb92;
P_0c09eb92: /* original ff27, guest PC 0x0c09eb92 */
if(!s->budget--) { s->failed_pc=0x0c09eb92u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c09eb94;
P_0c09eb94: /* original b84e, guest PC 0x0c09eb94 */
if(!s->budget--) { s->failed_pc=0x0c09eb94u; return 0; }
target=code_base|0x0c09dc34u; r[16]=code_base|0x0c09eb98u;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eb98u) { target=s->pc; goto dispatch; }
goto P_0c09eb98;
P_0c09eb96: /* original 7418, guest PC 0x0c09eb96 */
if(!s->budget--) { s->failed_pc=0x0c09eb96u; return 0; }
r[4]+=0x00000018u;
goto P_0c09eb98;
P_0c09eb98: /* original d226, guest PC 0x0c09eb98 */
if(!s->budget--) { s->failed_pc=0x0c09eb98u; return 0; }
r[2]=read(ram,0x0c09ec34u,4);
goto P_0c09eb9a;
P_0c09eb9a: /* original 942c, guest PC 0x0c09eb9a */
if(!s->budget--) { s->failed_pc=0x0c09eb9au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ebf6u,2);
goto P_0c09eb9c;
P_0c09eb9c: /* original 420b, guest PC 0x0c09eb9c */
if(!s->budget--) { s->failed_pc=0x0c09eb9cu; return 0; }
target=r[2];
r[16]=code_base|0x0c09eba0u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eba0u) { target=s->pc; goto dispatch; }
goto P_0c09eba0;
P_0c09eb9e: /* original 34fc, guest PC 0x0c09eb9e */
if(!s->budget--) { s->failed_pc=0x0c09eb9eu; return 0; }
r[4]+=r[15];
goto P_0c09eba0;
P_0c09eba0: /* original 9529, guest PC 0x0c09eba0 */
if(!s->budget--) { s->failed_pc=0x0c09eba0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ebf6u,2);
goto P_0c09eba2;
P_0c09eba2: /* original 9434, guest PC 0x0c09eba2 */
if(!s->budget--) { s->failed_pc=0x0c09eba2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ec0eu,2);
goto P_0c09eba4;
P_0c09eba4: /* original d324, guest PC 0x0c09eba4 */
if(!s->budget--) { s->failed_pc=0x0c09eba4u; return 0; }
r[3]=read(ram,0x0c09ec38u,4);
goto P_0c09eba6;
P_0c09eba6: /* original 35fc, guest PC 0x0c09eba6 */
if(!s->budget--) { s->failed_pc=0x0c09eba6u; return 0; }
r[5]+=r[15];
goto P_0c09eba8;
P_0c09eba8: /* original 430b, guest PC 0x0c09eba8 */
if(!s->budget--) { s->failed_pc=0x0c09eba8u; return 0; }
target=r[3];
r[16]=code_base|0x0c09ebacu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ebacu) { target=s->pc; goto dispatch; }
goto P_0c09ebac;
P_0c09ebaa: /* original 34ec, guest PC 0x0c09ebaa */
if(!s->budget--) { s->failed_pc=0x0c09ebaau; return 0; }
r[4]+=r[14];
goto P_0c09ebac;
P_0c09ebac: /* original f3d8, guest PC 0x0c09ebac */
if(!s->budget--) { s->failed_pc=0x0c09ebacu; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c09ebae;
P_0c09ebae: /* original e00c, guest PC 0x0c09ebae */
if(!s->budget--) { s->failed_pc=0x0c09ebaeu; return 0; }
r[0]=0x0000000cu;
goto P_0c09ebb0;
P_0c09ebb0: /* original 65c3, guest PC 0x0c09ebb0 */
if(!s->budget--) { s->failed_pc=0x0c09ebb0u; return 0; }
r[5]=r[12];
goto P_0c09ebb2;
P_0c09ebb2: /* original 64f3, guest PC 0x0c09ebb2 */
if(!s->budget--) { s->failed_pc=0x0c09ebb2u; return 0; }
r[4]=r[15];
goto P_0c09ebb4;
P_0c09ebb4: /* original ff37, guest PC 0x0c09ebb4 */
if(!s->budget--) { s->failed_pc=0x0c09ebb4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09ebb6;
P_0c09ebb6: /* original e008, guest PC 0x0c09ebb6 */
if(!s->budget--) { s->failed_pc=0x0c09ebb6u; return 0; }
r[0]=0x00000008u;
goto P_0c09ebb8;
P_0c09ebb8: /* original f3d6, guest PC 0x0c09ebb8 */
if(!s->budget--) { s->failed_pc=0x0c09ebb8u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c09ebba;
P_0c09ebba: /* original e010, guest PC 0x0c09ebba */
if(!s->budget--) { s->failed_pc=0x0c09ebbau; return 0; }
r[0]=0x00000010u;
goto P_0c09ebbc;
P_0c09ebbc: /* original 750c, guest PC 0x0c09ebbc */
if(!s->budget--) { s->failed_pc=0x0c09ebbcu; return 0; }
r[5]+=0x0000000cu;
goto P_0c09ebbe;
P_0c09ebbe: /* original ff37, guest PC 0x0c09ebbe */
if(!s->budget--) { s->failed_pc=0x0c09ebbeu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09ebc0;
P_0c09ebc0: /* original e004, guest PC 0x0c09ebc0 */
if(!s->budget--) { s->failed_pc=0x0c09ebc0u; return 0; }
r[0]=0x00000004u;
goto P_0c09ebc2;
P_0c09ebc2: /* original f3d6, guest PC 0x0c09ebc2 */
if(!s->budget--) { s->failed_pc=0x0c09ebc2u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c09ebc4;
P_0c09ebc4: /* original e014, guest PC 0x0c09ebc4 */
if(!s->budget--) { s->failed_pc=0x0c09ebc4u; return 0; }
r[0]=0x00000014u;
goto P_0c09ebc6;
P_0c09ebc6: /* original ff37, guest PC 0x0c09ebc6 */
if(!s->budget--) { s->failed_pc=0x0c09ebc6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09ebc8;
P_0c09ebc8: /* original d81c, guest PC 0x0c09ebc8 */
if(!s->budget--) { s->failed_pc=0x0c09ebc8u; return 0; }
r[8]=read(ram,0x0c09ec3cu,4);
goto P_0c09ebca;
P_0c09ebca: /* original 480b, guest PC 0x0c09ebca */
if(!s->budget--) { s->failed_pc=0x0c09ebcau; return 0; }
target=r[8];
r[16]=code_base|0x0c09ebceu;
r[4]+=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ebceu) { target=s->pc; goto dispatch; }
goto P_0c09ebce;
P_0c09ebcc: /* original 740c, guest PC 0x0c09ebcc */
if(!s->budget--) { s->failed_pc=0x0c09ebccu; return 0; }
r[4]+=0x0000000cu;
goto P_0c09ebce;
P_0c09ebce: /* original e004, guest PC 0x0c09ebce */
if(!s->budget--) { s->failed_pc=0x0c09ebceu; return 0; }
r[0]=0x00000004u;
goto P_0c09ebd0;
P_0c09ebd0: /* original 64f3, guest PC 0x0c09ebd0 */
if(!s->budget--) { s->failed_pc=0x0c09ebd0u; return 0; }
r[4]=r[15];
goto P_0c09ebd2;
P_0c09ebd2: /* original f3d6, guest PC 0x0c09ebd2 */
if(!s->budget--) { s->failed_pc=0x0c09ebd2u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c09ebd4;
P_0c09ebd4: /* original e014, guest PC 0x0c09ebd4 */
if(!s->budget--) { s->failed_pc=0x0c09ebd4u; return 0; }
r[0]=0x00000014u;
goto P_0c09ebd6;
P_0c09ebd6: /* original 65c3, guest PC 0x0c09ebd6 */
if(!s->budget--) { s->failed_pc=0x0c09ebd6u; return 0; }
r[5]=r[12];
goto P_0c09ebd8;
P_0c09ebd8: /* original f34d, guest PC 0x0c09ebd8 */
if(!s->budget--) { s->failed_pc=0x0c09ebd8u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09ebda;
P_0c09ebda: /* original ff37, guest PC 0x0c09ebda */
if(!s->budget--) { s->failed_pc=0x0c09ebdau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09ebdc;
P_0c09ebdc: /* original 480b, guest PC 0x0c09ebdc */
if(!s->budget--) { s->failed_pc=0x0c09ebdcu; return 0; }
target=r[8];
r[16]=code_base|0x0c09ebe0u;
r[4]+=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ebe0u) { target=s->pc; goto dispatch; }
goto P_0c09ebe0;
P_0c09ebde: /* original 740c, guest PC 0x0c09ebde */
if(!s->budget--) { s->failed_pc=0x0c09ebdeu; return 0; }
r[4]+=0x0000000cu;
goto P_0c09ebe0;
P_0c09ebe0: /* original 490b, guest PC 0x0c09ebe0 */
if(!s->budget--) { s->failed_pc=0x0c09ebe0u; return 0; }
target=r[9];
r[16]=code_base|0x0c09ebe4u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ebe4u) { target=s->pc; goto dispatch; }
goto P_0c09ebe4;
P_0c09ebe2: /* original e400, guest PC 0x0c09ebe2 */
if(!s->budget--) { s->failed_pc=0x0c09ebe2u; return 0; }
r[4]=0x00000000u;
goto P_0c09ebe4;
P_0c09ebe4: /* original e061, guest PC 0x0c09ebe4 */
if(!s->budget--) { s->failed_pc=0x0c09ebe4u; return 0; }
r[0]=0x00000061u;
goto P_0c09ebe6;
P_0c09ebe6: /* original d416, guest PC 0x0c09ebe6 */
if(!s->budget--) { s->failed_pc=0x0c09ebe6u; return 0; }
r[4]=read(ram,0x0c09ec40u,4);
goto P_0c09ebe8;
P_0c09ebe8: /* original 00ec, guest PC 0x0c09ebe8 */
if(!s->budget--) { s->failed_pc=0x0c09ebe8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09ebea;
P_0c09ebea: /* original 600c, guest PC 0x0c09ebea */
if(!s->budget--) { s->failed_pc=0x0c09ebeau; return 0; }
r[0]=r[0]&255u;
goto P_0c09ebec;
P_0c09ebec: /* original 880c, guest PC 0x0c09ebec */
if(!s->budget--) { s->failed_pc=0x0c09ebecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c09ebee;
P_0c09ebee: /* original 8b29, guest PC 0x0c09ebee */
if(!s->budget--) { s->failed_pc=0x0c09ebeeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ec44; }
goto P_0c09ebf0;
P_0c09ebf0: /* original a02d, guest PC 0x0c09ebf0 */
if(!s->budget--) { s->failed_pc=0x0c09ebf0u; return 0; }
r[11]=read(ram,r[4]+8,4);
goto P_0c09ec4e;
P_0c09ebf2: /* original 5b42, guest PC 0x0c09ebf2 */
if(!s->budget--) { s->failed_pc=0x0c09ebf2u; return 0; }
r[11]=read(ram,r[4]+8,4);
if(!vf3_matrix_family(0x0c09ebf4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09ebf4u; return 0; } return 1;
P_0c09ec44: /* original 90b5, guest PC 0x0c09ec44 */
if(!s->budget--) { s->failed_pc=0x0c09ec44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edb2u,2);
goto P_0c09ec46;
P_0c09ec46: /* original 00ec, guest PC 0x0c09ec46 */
if(!s->budget--) { s->failed_pc=0x0c09ec46u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09ec48;
P_0c09ec48: /* original 600c, guest PC 0x0c09ec48 */
if(!s->budget--) { s->failed_pc=0x0c09ec48u; return 0; }
r[0]=r[0]&255u;
goto P_0c09ec4a;
P_0c09ec4a: /* original 4008, guest PC 0x0c09ec4a */
if(!s->budget--) { s->failed_pc=0x0c09ec4au; return 0; }
r[0]<<=2;
goto P_0c09ec4c;
P_0c09ec4c: /* original 0b4e, guest PC 0x0c09ec4c */
if(!s->budget--) { s->failed_pc=0x0c09ec4cu; return 0; }
r[11]=read(ram,r[4]+r[0],4);
goto P_0c09ec4e;
P_0c09ec4e: /* original 65b3, guest PC 0x0c09ec4e */
if(!s->budget--) { s->failed_pc=0x0c09ec4eu; return 0; }
r[5]=r[11];
goto P_0c09ec50;
P_0c09ec50: /* original b844, guest PC 0x0c09ec50 */
if(!s->budget--) { s->failed_pc=0x0c09ec50u; return 0; }
target=code_base|0x0c09dcdcu; r[16]=code_base|0x0c09ec54u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ec54u) { target=s->pc; goto dispatch; }
goto P_0c09ec54;
P_0c09ec52: /* original 64e3, guest PC 0x0c09ec52 */
if(!s->budget--) { s->failed_pc=0x0c09ec52u; return 0; }
r[4]=r[14];
goto P_0c09ec54;
P_0c09ec54: /* original e00c, guest PC 0x0c09ec54 */
if(!s->budget--) { s->failed_pc=0x0c09ec54u; return 0; }
r[0]=0x0000000cu;
goto P_0c09ec56;
P_0c09ec56: /* original 65c3, guest PC 0x0c09ec56 */
if(!s->budget--) { s->failed_pc=0x0c09ec56u; return 0; }
r[5]=r[12];
goto P_0c09ec58;
P_0c09ec58: /* original f3d6, guest PC 0x0c09ec58 */
if(!s->budget--) { s->failed_pc=0x0c09ec58u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c09ec5a;
P_0c09ec5a: /* original e00c, guest PC 0x0c09ec5a */
if(!s->budget--) { s->failed_pc=0x0c09ec5au; return 0; }
r[0]=0x0000000cu;
goto P_0c09ec5c;
P_0c09ec5c: /* original 64f3, guest PC 0x0c09ec5c */
if(!s->budget--) { s->failed_pc=0x0c09ec5cu; return 0; }
r[4]=r[15];
goto P_0c09ec5e;
P_0c09ec5e: /* original 7518, guest PC 0x0c09ec5e */
if(!s->budget--) { s->failed_pc=0x0c09ec5eu; return 0; }
r[5]+=0x00000018u;
goto P_0c09ec60;
P_0c09ec60: /* original ff37, guest PC 0x0c09ec60 */
if(!s->budget--) { s->failed_pc=0x0c09ec60u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09ec62;
P_0c09ec62: /* original e010, guest PC 0x0c09ec62 */
if(!s->budget--) { s->failed_pc=0x0c09ec62u; return 0; }
r[0]=0x00000010u;
goto P_0c09ec64;
P_0c09ec64: /* original f3d6, guest PC 0x0c09ec64 */
if(!s->budget--) { s->failed_pc=0x0c09ec64u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c09ec66;
P_0c09ec66: /* original e010, guest PC 0x0c09ec66 */
if(!s->budget--) { s->failed_pc=0x0c09ec66u; return 0; }
r[0]=0x00000010u;
goto P_0c09ec68;
P_0c09ec68: /* original ff37, guest PC 0x0c09ec68 */
if(!s->budget--) { s->failed_pc=0x0c09ec68u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09ec6a;
P_0c09ec6a: /* original e014, guest PC 0x0c09ec6a */
if(!s->budget--) { s->failed_pc=0x0c09ec6au; return 0; }
r[0]=0x00000014u;
goto P_0c09ec6c;
P_0c09ec6c: /* original f3d6, guest PC 0x0c09ec6c */
if(!s->budget--) { s->failed_pc=0x0c09ec6cu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c09ec6e;
P_0c09ec6e: /* original e014, guest PC 0x0c09ec6e */
if(!s->budget--) { s->failed_pc=0x0c09ec6eu; return 0; }
r[0]=0x00000014u;
goto P_0c09ec70;
P_0c09ec70: /* original ff37, guest PC 0x0c09ec70 */
if(!s->budget--) { s->failed_pc=0x0c09ec70u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09ec72;
P_0c09ec72: /* original 480b, guest PC 0x0c09ec72 */
if(!s->budget--) { s->failed_pc=0x0c09ec72u; return 0; }
target=r[8];
r[16]=code_base|0x0c09ec76u;
r[4]+=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ec76u) { target=s->pc; goto dispatch; }
goto P_0c09ec76;
P_0c09ec74: /* original 740c, guest PC 0x0c09ec74 */
if(!s->budget--) { s->failed_pc=0x0c09ec74u; return 0; }
r[4]+=0x0000000cu;
goto P_0c09ec76;
P_0c09ec76: /* original da5f, guest PC 0x0c09ec76 */
if(!s->budget--) { s->failed_pc=0x0c09ec76u; return 0; }
r[10]=read(ram,0x0c09edf4u,4);
goto P_0c09ec78;
P_0c09ec78: /* original 4a0b, guest PC 0x0c09ec78 */
if(!s->budget--) { s->failed_pc=0x0c09ec78u; return 0; }
target=r[10];
r[16]=code_base|0x0c09ec7cu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ec7cu) { target=s->pc; goto dispatch; }
goto P_0c09ec7c;
P_0c09ec7a: /* original e401, guest PC 0x0c09ec7a */
if(!s->budget--) { s->failed_pc=0x0c09ec7au; return 0; }
r[4]=0x00000001u;
goto P_0c09ec7c;
P_0c09ec7c: /* original 490b, guest PC 0x0c09ec7c */
if(!s->budget--) { s->failed_pc=0x0c09ec7cu; return 0; }
target=r[9];
r[16]=code_base|0x0c09ec80u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ec80u) { target=s->pc; goto dispatch; }
goto P_0c09ec80;
P_0c09ec7e: /* original e400, guest PC 0x0c09ec7e */
if(!s->budget--) { s->failed_pc=0x0c09ec7eu; return 0; }
r[4]=0x00000000u;
goto P_0c09ec80;
P_0c09ec80: /* original 939a, guest PC 0x0c09ec80 */
if(!s->budget--) { s->failed_pc=0x0c09ec80u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edb8u,2);
goto P_0c09ec82;
P_0c09ec82: /* original 62c3, guest PC 0x0c09ec82 */
if(!s->budget--) { s->failed_pc=0x0c09ec82u; return 0; }
r[2]=r[12];
goto P_0c09ec84;
P_0c09ec84: /* original 7224, guest PC 0x0c09ec84 */
if(!s->budget--) { s->failed_pc=0x0c09ec84u; return 0; }
r[2]+=0x00000024u;
goto P_0c09ec86;
P_0c09ec86: /* original 9495, guest PC 0x0c09ec86 */
if(!s->budget--) { s->failed_pc=0x0c09ec86u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edb4u,2);
goto P_0c09ec88;
P_0c09ec88: /* original 33ec, guest PC 0x0c09ec88 */
if(!s->budget--) { s->failed_pc=0x0c09ec88u; return 0; }
r[3]+=r[14];
goto P_0c09ec8a;
P_0c09ec8a: /* original 9794, guest PC 0x0c09ec8a */
if(!s->budget--) { s->failed_pc=0x0c09ec8au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edb6u,2);
goto P_0c09ec8c;
P_0c09ec8c: /* original 2f36, guest PC 0x0c09ec8c */
if(!s->budget--) { s->failed_pc=0x0c09ec8cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ec8e;
P_0c09ec8e: /* original 63d3, guest PC 0x0c09ec8e */
if(!s->budget--) { s->failed_pc=0x0c09ec8eu; return 0; }
r[3]=r[13];
goto P_0c09ec90;
P_0c09ec90: /* original 2f26, guest PC 0x0c09ec90 */
if(!s->budget--) { s->failed_pc=0x0c09ec90u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ec92;
P_0c09ec92: /* original 7318, guest PC 0x0c09ec92 */
if(!s->budget--) { s->failed_pc=0x0c09ec92u; return 0; }
r[3]+=0x00000018u;
goto P_0c09ec94;
P_0c09ec94: /* original 2f36, guest PC 0x0c09ec94 */
if(!s->budget--) { s->failed_pc=0x0c09ec94u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ec96;
P_0c09ec96: /* original 34ec, guest PC 0x0c09ec96 */
if(!s->budget--) { s->failed_pc=0x0c09ec96u; return 0; }
r[4]+=r[14];
goto P_0c09ec98;
P_0c09ec98: /* original 2f46, guest PC 0x0c09ec98 */
if(!s->budget--) { s->failed_pc=0x0c09ec98u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ec9a;
P_0c09ec9a: /* original 66b3, guest PC 0x0c09ec9a */
if(!s->budget--) { s->failed_pc=0x0c09ec9au; return 0; }
r[6]=r[11];
goto P_0c09ec9c;
P_0c09ec9c: /* original 928d, guest PC 0x0c09ec9c */
if(!s->budget--) { s->failed_pc=0x0c09ec9cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edbau,2);
goto P_0c09ec9e;
P_0c09ec9e: /* original 7604, guest PC 0x0c09ec9e */
if(!s->budget--) { s->failed_pc=0x0c09ec9eu; return 0; }
r[6]+=0x00000004u;
goto P_0c09eca0;
P_0c09eca0: /* original 37ec, guest PC 0x0c09eca0 */
if(!s->budget--) { s->failed_pc=0x0c09eca0u; return 0; }
r[7]+=r[14];
goto P_0c09eca2;
P_0c09eca2: /* original 32ec, guest PC 0x0c09eca2 */
if(!s->budget--) { s->failed_pc=0x0c09eca2u; return 0; }
r[2]+=r[14];
goto P_0c09eca4;
P_0c09eca4: /* original 2f26, guest PC 0x0c09eca4 */
if(!s->budget--) { s->failed_pc=0x0c09eca4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09eca6;
P_0c09eca6: /* original 9589, guest PC 0x0c09eca6 */
if(!s->budget--) { s->failed_pc=0x0c09eca6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edbcu,2);
goto P_0c09eca8;
P_0c09eca8: /* original 9489, guest PC 0x0c09eca8 */
if(!s->budget--) { s->failed_pc=0x0c09eca8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edbeu,2);
goto P_0c09ecaa;
P_0c09ecaa: /* original 35ec, guest PC 0x0c09ecaa */
if(!s->budget--) { s->failed_pc=0x0c09ecaau; return 0; }
r[5]+=r[14];
goto P_0c09ecac;
P_0c09ecac: /* original b9d8, guest PC 0x0c09ecac */
if(!s->budget--) { s->failed_pc=0x0c09ecacu; return 0; }
target=code_base|0x0c09e060u; r[16]=code_base|0x0c09ecb0u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ecb0u) { target=s->pc; goto dispatch; }
goto P_0c09ecb0;
P_0c09ecae: /* original 34ec, guest PC 0x0c09ecae */
if(!s->budget--) { s->failed_pc=0x0c09ecaeu; return 0; }
r[4]+=r[14];
goto P_0c09ecb0;
P_0c09ecb0: /* original 4a0b, guest PC 0x0c09ecb0 */
if(!s->budget--) { s->failed_pc=0x0c09ecb0u; return 0; }
target=r[10];
r[16]=code_base|0x0c09ecb4u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ecb4u) { target=s->pc; goto dispatch; }
goto P_0c09ecb4;
P_0c09ecb2: /* original e401, guest PC 0x0c09ecb2 */
if(!s->budget--) { s->failed_pc=0x0c09ecb2u; return 0; }
r[4]=0x00000001u;
goto P_0c09ecb4;
P_0c09ecb4: /* original 9286, guest PC 0x0c09ecb4 */
if(!s->budget--) { s->failed_pc=0x0c09ecb4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edc4u,2);
goto P_0c09ecb6;
P_0c09ecb6: /* original 63c3, guest PC 0x0c09ecb6 */
if(!s->budget--) { s->failed_pc=0x0c09ecb6u; return 0; }
r[3]=r[12];
goto P_0c09ecb8;
P_0c09ecb8: /* original 7360, guest PC 0x0c09ecb8 */
if(!s->budget--) { s->failed_pc=0x0c09ecb8u; return 0; }
r[3]+=0x00000060u;
goto P_0c09ecba;
P_0c09ecba: /* original 9481, guest PC 0x0c09ecba */
if(!s->budget--) { s->failed_pc=0x0c09ecbau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edc0u,2);
goto P_0c09ecbc;
P_0c09ecbc: /* original 32ec, guest PC 0x0c09ecbc */
if(!s->budget--) { s->failed_pc=0x0c09ecbcu; return 0; }
r[2]+=r[14];
goto P_0c09ecbe;
P_0c09ecbe: /* original 9780, guest PC 0x0c09ecbe */
if(!s->budget--) { s->failed_pc=0x0c09ecbeu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edc2u,2);
goto P_0c09ecc0;
P_0c09ecc0: /* original 2f26, guest PC 0x0c09ecc0 */
if(!s->budget--) { s->failed_pc=0x0c09ecc0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ecc2;
P_0c09ecc2: /* original 62d3, guest PC 0x0c09ecc2 */
if(!s->budget--) { s->failed_pc=0x0c09ecc2u; return 0; }
r[2]=r[13];
goto P_0c09ecc4;
P_0c09ecc4: /* original 2f36, guest PC 0x0c09ecc4 */
if(!s->budget--) { s->failed_pc=0x0c09ecc4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ecc6;
P_0c09ecc6: /* original 7224, guest PC 0x0c09ecc6 */
if(!s->budget--) { s->failed_pc=0x0c09ecc6u; return 0; }
r[2]+=0x00000024u;
goto P_0c09ecc8;
P_0c09ecc8: /* original 2f26, guest PC 0x0c09ecc8 */
if(!s->budget--) { s->failed_pc=0x0c09ecc8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ecca;
P_0c09ecca: /* original 34ec, guest PC 0x0c09ecca */
if(!s->budget--) { s->failed_pc=0x0c09eccau; return 0; }
r[4]+=r[14];
goto P_0c09eccc;
P_0c09eccc: /* original 2f46, guest PC 0x0c09eccc */
if(!s->budget--) { s->failed_pc=0x0c09ecccu; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ecce;
P_0c09ecce: /* original 66b3, guest PC 0x0c09ecce */
if(!s->budget--) { s->failed_pc=0x0c09ecceu; return 0; }
r[6]=r[11];
goto P_0c09ecd0;
P_0c09ecd0: /* original 9379, guest PC 0x0c09ecd0 */
if(!s->budget--) { s->failed_pc=0x0c09ecd0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edc6u,2);
goto P_0c09ecd2;
P_0c09ecd2: /* original 7618, guest PC 0x0c09ecd2 */
if(!s->budget--) { s->failed_pc=0x0c09ecd2u; return 0; }
r[6]+=0x00000018u;
goto P_0c09ecd4;
P_0c09ecd4: /* original 37ec, guest PC 0x0c09ecd4 */
if(!s->budget--) { s->failed_pc=0x0c09ecd4u; return 0; }
r[7]+=r[14];
goto P_0c09ecd6;
P_0c09ecd6: /* original 33ec, guest PC 0x0c09ecd6 */
if(!s->budget--) { s->failed_pc=0x0c09ecd6u; return 0; }
r[3]+=r[14];
goto P_0c09ecd8;
P_0c09ecd8: /* original 2f36, guest PC 0x0c09ecd8 */
if(!s->budget--) { s->failed_pc=0x0c09ecd8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ecda;
P_0c09ecda: /* original 9575, guest PC 0x0c09ecda */
if(!s->budget--) { s->failed_pc=0x0c09ecdau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edc8u,2);
goto P_0c09ecdc;
P_0c09ecdc: /* original 9475, guest PC 0x0c09ecdc */
if(!s->budget--) { s->failed_pc=0x0c09ecdcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edcau,2);
goto P_0c09ecde;
P_0c09ecde: /* original 35ec, guest PC 0x0c09ecde */
if(!s->budget--) { s->failed_pc=0x0c09ecdeu; return 0; }
r[5]+=r[14];
goto P_0c09ece0;
P_0c09ece0: /* original b9be, guest PC 0x0c09ece0 */
if(!s->budget--) { s->failed_pc=0x0c09ece0u; return 0; }
target=code_base|0x0c09e060u; r[16]=code_base|0x0c09ece4u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ece4u) { target=s->pc; goto dispatch; }
goto P_0c09ece4;
P_0c09ece2: /* original 34ec, guest PC 0x0c09ece2 */
if(!s->budget--) { s->failed_pc=0x0c09ece2u; return 0; }
r[4]+=r[14];
goto P_0c09ece4;
P_0c09ece4: /* original 4a0b, guest PC 0x0c09ece4 */
if(!s->budget--) { s->failed_pc=0x0c09ece4u; return 0; }
target=r[10];
r[16]=code_base|0x0c09ece8u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ece8u) { target=s->pc; goto dispatch; }
goto P_0c09ece8;
P_0c09ece6: /* original e401, guest PC 0x0c09ece6 */
if(!s->budget--) { s->failed_pc=0x0c09ece6u; return 0; }
r[4]=0x00000001u;
goto P_0c09ece8;
P_0c09ece8: /* original e030, guest PC 0x0c09ece8 */
if(!s->budget--) { s->failed_pc=0x0c09ece8u; return 0; }
r[0]=0x00000030u;
goto P_0c09ecea;
P_0c09ecea: /* original 64f3, guest PC 0x0c09ecea */
if(!s->budget--) { s->failed_pc=0x0c09eceau; return 0; }
r[4]=r[15];
goto P_0c09ecec;
P_0c09ecec: /* original f3d6, guest PC 0x0c09ecec */
if(!s->budget--) { s->failed_pc=0x0c09ececu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c09ecee;
P_0c09ecee: /* original e034, guest PC 0x0c09ecee */
if(!s->budget--) { s->failed_pc=0x0c09eceeu; return 0; }
r[0]=0x00000034u;
goto P_0c09ecf0;
P_0c09ecf0: /* original ff37, guest PC 0x0c09ecf0 */
if(!s->budget--) { s->failed_pc=0x0c09ecf0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09ecf2;
P_0c09ecf2: /* original e034, guest PC 0x0c09ecf2 */
if(!s->budget--) { s->failed_pc=0x0c09ecf2u; return 0; }
r[0]=0x00000034u;
goto P_0c09ecf4;
P_0c09ecf4: /* original f3d6, guest PC 0x0c09ecf4 */
if(!s->budget--) { s->failed_pc=0x0c09ecf4u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c09ecf6;
P_0c09ecf6: /* original e038, guest PC 0x0c09ecf6 */
if(!s->budget--) { s->failed_pc=0x0c09ecf6u; return 0; }
r[0]=0x00000038u;
goto P_0c09ecf8;
P_0c09ecf8: /* original ff37, guest PC 0x0c09ecf8 */
if(!s->budget--) { s->failed_pc=0x0c09ecf8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09ecfa;
P_0c09ecfa: /* original e038, guest PC 0x0c09ecfa */
if(!s->budget--) { s->failed_pc=0x0c09ecfau; return 0; }
r[0]=0x00000038u;
goto P_0c09ecfc;
P_0c09ecfc: /* original f3d6, guest PC 0x0c09ecfc */
if(!s->budget--) { s->failed_pc=0x0c09ecfcu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c09ecfe;
P_0c09ecfe: /* original e03c, guest PC 0x0c09ecfe */
if(!s->budget--) { s->failed_pc=0x0c09ecfeu; return 0; }
r[0]=0x0000003cu;
goto P_0c09ed00;
P_0c09ed00: /* original ff37, guest PC 0x0c09ed00 */
if(!s->budget--) { s->failed_pc=0x0c09ed00u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09ed02;
P_0c09ed02: /* original 9563, guest PC 0x0c09ed02 */
if(!s->budget--) { s->failed_pc=0x0c09ed02u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edccu,2);
goto P_0c09ed04;
P_0c09ed04: /* original 35cc, guest PC 0x0c09ed04 */
if(!s->budget--) { s->failed_pc=0x0c09ed04u; return 0; }
r[5]+=r[12];
goto P_0c09ed06;
P_0c09ed06: /* original 480b, guest PC 0x0c09ed06 */
if(!s->budget--) { s->failed_pc=0x0c09ed06u; return 0; }
target=r[8];
r[16]=code_base|0x0c09ed0au;
r[4]+=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ed0au) { target=s->pc; goto dispatch; }
goto P_0c09ed0a;
P_0c09ed08: /* original 7434, guest PC 0x0c09ed08 */
if(!s->budget--) { s->failed_pc=0x0c09ed08u; return 0; }
r[4]+=0x00000034u;
goto P_0c09ed0a;
P_0c09ed0a: /* original 9560, guest PC 0x0c09ed0a */
if(!s->budget--) { s->failed_pc=0x0c09ed0au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edceu,2);
goto P_0c09ed0c;
P_0c09ed0c: /* original 35fc, guest PC 0x0c09ed0c */
if(!s->budget--) { s->failed_pc=0x0c09ed0cu; return 0; }
r[5]+=r[15];
goto P_0c09ed0e;
P_0c09ed0e: /* original bb8b, guest PC 0x0c09ed0e */
if(!s->budget--) { s->failed_pc=0x0c09ed0eu; return 0; }
target=code_base|0x0c09e428u; r[16]=code_base|0x0c09ed12u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ed12u) { target=s->pc; goto dispatch; }
goto P_0c09ed12;
P_0c09ed10: /* original 64e3, guest PC 0x0c09ed10 */
if(!s->budget--) { s->failed_pc=0x0c09ed10u; return 0; }
r[4]=r[14];
goto P_0c09ed12;
P_0c09ed12: /* original 65f3, guest PC 0x0c09ed12 */
if(!s->budget--) { s->failed_pc=0x0c09ed12u; return 0; }
r[5]=r[15];
goto P_0c09ed14;
P_0c09ed14: /* original 754c, guest PC 0x0c09ed14 */
if(!s->budget--) { s->failed_pc=0x0c09ed14u; return 0; }
r[5]+=0x0000004cu;
goto P_0c09ed16;
P_0c09ed16: /* original bbd7, guest PC 0x0c09ed16 */
if(!s->budget--) { s->failed_pc=0x0c09ed16u; return 0; }
target=code_base|0x0c09e4c8u; r[16]=code_base|0x0c09ed1au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ed1au) { target=s->pc; goto dispatch; }
goto P_0c09ed1a;
P_0c09ed18: /* original 64e3, guest PC 0x0c09ed18 */
if(!s->budget--) { s->failed_pc=0x0c09ed18u; return 0; }
r[4]=r[14];
goto P_0c09ed1a;
P_0c09ed1a: /* original 490b, guest PC 0x0c09ed1a */
if(!s->budget--) { s->failed_pc=0x0c09ed1au; return 0; }
target=r[9];
r[16]=code_base|0x0c09ed1eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ed1eu) { target=s->pc; goto dispatch; }
goto P_0c09ed1e;
P_0c09ed1c: /* original e400, guest PC 0x0c09ed1c */
if(!s->budget--) { s->failed_pc=0x0c09ed1cu; return 0; }
r[4]=0x00000000u;
goto P_0c09ed1e;
P_0c09ed1e: /* original 9358, guest PC 0x0c09ed1e */
if(!s->budget--) { s->failed_pc=0x0c09ed1eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edd2u,2);
goto P_0c09ed20;
P_0c09ed20: /* original 67b3, guest PC 0x0c09ed20 */
if(!s->budget--) { s->failed_pc=0x0c09ed20u; return 0; }
r[7]=r[11];
goto P_0c09ed22;
P_0c09ed22: /* original 9555, guest PC 0x0c09ed22 */
if(!s->budget--) { s->failed_pc=0x0c09ed22u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edd0u,2);
goto P_0c09ed24;
P_0c09ed24: /* original 772c, guest PC 0x0c09ed24 */
if(!s->budget--) { s->failed_pc=0x0c09ed24u; return 0; }
r[7]+=0x0000002cu;
goto P_0c09ed26;
P_0c09ed26: /* original 33ec, guest PC 0x0c09ed26 */
if(!s->budget--) { s->failed_pc=0x0c09ed26u; return 0; }
r[3]+=r[14];
goto P_0c09ed28;
P_0c09ed28: /* original 1f3a, guest PC 0x0c09ed28 */
if(!s->budget--) { s->failed_pc=0x0c09ed28u; return 0; }
write(ram,r[15]+40,r[3],4);
goto P_0c09ed2a;
P_0c09ed2a: /* original 35ec, guest PC 0x0c09ed2a */
if(!s->budget--) { s->failed_pc=0x0c09ed2au; return 0; }
r[5]+=r[14];
goto P_0c09ed2c;
P_0c09ed2c: /* original 9054, guest PC 0x0c09ed2c */
if(!s->budget--) { s->failed_pc=0x0c09ed2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edd8u,2);
goto P_0c09ed2e;
P_0c09ed2e: /* original 9451, guest PC 0x0c09ed2e */
if(!s->budget--) { s->failed_pc=0x0c09ed2eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edd4u,2);
goto P_0c09ed30;
P_0c09ed30: /* original 03ed, guest PC 0x0c09ed30 */
if(!s->budget--) { s->failed_pc=0x0c09ed30u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09ed32;
P_0c09ed32: /* original 70fe, guest PC 0x0c09ed32 */
if(!s->budget--) { s->failed_pc=0x0c09ed32u; return 0; }
r[0]+=0xfffffffeu;
goto P_0c09ed34;
P_0c09ed34: /* original 964f, guest PC 0x0c09ed34 */
if(!s->budget--) { s->failed_pc=0x0c09ed34u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edd6u,2);
goto P_0c09ed36;
P_0c09ed36: /* original 34ec, guest PC 0x0c09ed36 */
if(!s->budget--) { s->failed_pc=0x0c09ed36u; return 0; }
r[4]+=r[14];
goto P_0c09ed38;
P_0c09ed38: /* original 0e35, guest PC 0x0c09ed38 */
if(!s->budget--) { s->failed_pc=0x0c09ed38u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c09ed3a;
P_0c09ed3a: /* original 924e, guest PC 0x0c09ed3a */
if(!s->budget--) { s->failed_pc=0x0c09ed3au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09eddau,2);
goto P_0c09ed3c;
P_0c09ed3c: /* original 36ec, guest PC 0x0c09ed3c */
if(!s->budget--) { s->failed_pc=0x0c09ed3cu; return 0; }
r[6]+=r[14];
goto P_0c09ed3e;
P_0c09ed3e: /* original 32ec, guest PC 0x0c09ed3e */
if(!s->budget--) { s->failed_pc=0x0c09ed3eu; return 0; }
r[2]+=r[14];
goto P_0c09ed40;
P_0c09ed40: /* original 2f26, guest PC 0x0c09ed40 */
if(!s->budget--) { s->failed_pc=0x0c09ed40u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ed42;
P_0c09ed42: /* original 62d3, guest PC 0x0c09ed42 */
if(!s->budget--) { s->failed_pc=0x0c09ed42u; return 0; }
r[2]=r[13];
goto P_0c09ed44;
P_0c09ed44: /* original 934a, guest PC 0x0c09ed44 */
if(!s->budget--) { s->failed_pc=0x0c09ed44u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09eddcu,2);
goto P_0c09ed46;
P_0c09ed46: /* original 723c, guest PC 0x0c09ed46 */
if(!s->budget--) { s->failed_pc=0x0c09ed46u; return 0; }
r[2]+=0x0000003cu;
goto P_0c09ed48;
P_0c09ed48: /* original 33cc, guest PC 0x0c09ed48 */
if(!s->budget--) { s->failed_pc=0x0c09ed48u; return 0; }
r[3]+=r[12];
goto P_0c09ed4a;
P_0c09ed4a: /* original 2f36, guest PC 0x0c09ed4a */
if(!s->budget--) { s->failed_pc=0x0c09ed4au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ed4c;
P_0c09ed4c: /* original 2f26, guest PC 0x0c09ed4c */
if(!s->budget--) { s->failed_pc=0x0c09ed4cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ed4e;
P_0c09ed4e: /* original 53fd, guest PC 0x0c09ed4e */
if(!s->budget--) { s->failed_pc=0x0c09ed4eu; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c09ed50;
P_0c09ed50: /* original 2f36, guest PC 0x0c09ed50 */
if(!s->budget--) { s->failed_pc=0x0c09ed50u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ed52;
P_0c09ed52: /* original 2f46, guest PC 0x0c09ed52 */
if(!s->budget--) { s->failed_pc=0x0c09ed52u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ed54;
P_0c09ed54: /* original 2f66, guest PC 0x0c09ed54 */
if(!s->budget--) { s->failed_pc=0x0c09ed54u; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ed56;
P_0c09ed56: /* original 9042, guest PC 0x0c09ed56 */
if(!s->budget--) { s->failed_pc=0x0c09ed56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09eddeu,2);
goto P_0c09ed58;
P_0c09ed58: /* original 9642, guest PC 0x0c09ed58 */
if(!s->budget--) { s->failed_pc=0x0c09ed58u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ede0u,2);
goto P_0c09ed5a;
P_0c09ed5a: /* original f4e6, guest PC 0x0c09ed5a */
if(!s->budget--) { s->failed_pc=0x0c09ed5au; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c09ed5c;
P_0c09ed5c: /* original 36ec, guest PC 0x0c09ed5c */
if(!s->budget--) { s->failed_pc=0x0c09ed5cu; return 0; }
r[6]+=r[14];
goto P_0c09ed5e;
P_0c09ed5e: /* original bca8, guest PC 0x0c09ed5e */
if(!s->budget--) { s->failed_pc=0x0c09ed5eu; return 0; }
target=code_base|0x0c09e6b2u; r[16]=code_base|0x0c09ed62u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ed62u) { target=s->pc; goto dispatch; }
goto P_0c09ed62;
P_0c09ed60: /* original 64e3, guest PC 0x0c09ed60 */
if(!s->budget--) { s->failed_pc=0x0c09ed60u; return 0; }
r[4]=r[14];
goto P_0c09ed62;
P_0c09ed62: /* original 4a0b, guest PC 0x0c09ed62 */
if(!s->budget--) { s->failed_pc=0x0c09ed62u; return 0; }
target=r[10];
r[16]=code_base|0x0c09ed66u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ed66u) { target=s->pc; goto dispatch; }
goto P_0c09ed66;
P_0c09ed64: /* original e401, guest PC 0x0c09ed64 */
if(!s->budget--) { s->failed_pc=0x0c09ed64u; return 0; }
r[4]=0x00000001u;
goto P_0c09ed66;
P_0c09ed66: /* original 490b, guest PC 0x0c09ed66 */
if(!s->budget--) { s->failed_pc=0x0c09ed66u; return 0; }
target=r[9];
r[16]=code_base|0x0c09ed6au;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ed6au) { target=s->pc; goto dispatch; }
goto P_0c09ed6a;
P_0c09ed68: /* original e400, guest PC 0x0c09ed68 */
if(!s->budget--) { s->failed_pc=0x0c09ed68u; return 0; }
r[4]=0x00000000u;
goto P_0c09ed6a;
P_0c09ed6a: /* original 923d, guest PC 0x0c09ed6a */
if(!s->budget--) { s->failed_pc=0x0c09ed6au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ede8u,2);
goto P_0c09ed6c;
P_0c09ed6c: /* original e040, guest PC 0x0c09ed6c */
if(!s->budget--) { s->failed_pc=0x0c09ed6cu; return 0; }
r[0]=0x00000040u;
goto P_0c09ed6e;
P_0c09ed6e: /* original 9439, guest PC 0x0c09ed6e */
if(!s->budget--) { s->failed_pc=0x0c09ed6eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ede4u,2);
goto P_0c09ed70;
P_0c09ed70: /* original 67b3, guest PC 0x0c09ed70 */
if(!s->budget--) { s->failed_pc=0x0c09ed70u; return 0; }
r[7]=r[11];
goto P_0c09ed72;
P_0c09ed72: /* original 32ec, guest PC 0x0c09ed72 */
if(!s->budget--) { s->failed_pc=0x0c09ed72u; return 0; }
r[2]+=r[14];
goto P_0c09ed74;
P_0c09ed74: /* original 9637, guest PC 0x0c09ed74 */
if(!s->budget--) { s->failed_pc=0x0c09ed74u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ede6u,2);
goto P_0c09ed76;
P_0c09ed76: /* original 34ec, guest PC 0x0c09ed76 */
if(!s->budget--) { s->failed_pc=0x0c09ed76u; return 0; }
r[4]+=r[14];
goto P_0c09ed78;
P_0c09ed78: /* original 9533, guest PC 0x0c09ed78 */
if(!s->budget--) { s->failed_pc=0x0c09ed78u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ede2u,2);
goto P_0c09ed7a;
P_0c09ed7a: /* original 0f26, guest PC 0x0c09ed7a */
if(!s->budget--) { s->failed_pc=0x0c09ed7au; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c09ed7c;
P_0c09ed7c: /* original 36ec, guest PC 0x0c09ed7c */
if(!s->budget--) { s->failed_pc=0x0c09ed7cu; return 0; }
r[6]+=r[14];
goto P_0c09ed7e;
P_0c09ed7e: /* original 9034, guest PC 0x0c09ed7e */
if(!s->budget--) { s->failed_pc=0x0c09ed7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edeau,2);
goto P_0c09ed80;
P_0c09ed80: /* original 35ec, guest PC 0x0c09ed80 */
if(!s->budget--) { s->failed_pc=0x0c09ed80u; return 0; }
r[5]+=r[14];
goto P_0c09ed82;
P_0c09ed82: /* original 773c, guest PC 0x0c09ed82 */
if(!s->budget--) { s->failed_pc=0x0c09ed82u; return 0; }
r[7]+=0x0000003cu;
goto P_0c09ed84;
P_0c09ed84: /* original 03ed, guest PC 0x0c09ed84 */
if(!s->budget--) { s->failed_pc=0x0c09ed84u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09ed86;
P_0c09ed86: /* original 70fc, guest PC 0x0c09ed86 */
if(!s->budget--) { s->failed_pc=0x0c09ed86u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09ed88;
P_0c09ed88: /* original 0e35, guest PC 0x0c09ed88 */
if(!s->budget--) { s->failed_pc=0x0c09ed88u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c09ed8a;
P_0c09ed8a: /* original e054, guest PC 0x0c09ed8a */
if(!s->budget--) { s->failed_pc=0x0c09ed8au; return 0; }
r[0]=0x00000054u;
goto P_0c09ed8c;
P_0c09ed8c: /* original 922e, guest PC 0x0c09ed8c */
if(!s->budget--) { s->failed_pc=0x0c09ed8cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edecu,2);
goto P_0c09ed8e;
P_0c09ed8e: /* original 32ec, guest PC 0x0c09ed8e */
if(!s->budget--) { s->failed_pc=0x0c09ed8eu; return 0; }
r[2]+=r[14];
goto P_0c09ed90;
P_0c09ed90: /* original 2f26, guest PC 0x0c09ed90 */
if(!s->budget--) { s->failed_pc=0x0c09ed90u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ed92;
P_0c09ed92: /* original 62d3, guest PC 0x0c09ed92 */
if(!s->budget--) { s->failed_pc=0x0c09ed92u; return 0; }
r[2]=r[13];
goto P_0c09ed94;
P_0c09ed94: /* original 9319, guest PC 0x0c09ed94 */
if(!s->budget--) { s->failed_pc=0x0c09ed94u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edcau,2);
goto P_0c09ed96;
P_0c09ed96: /* original 7254, guest PC 0x0c09ed96 */
if(!s->budget--) { s->failed_pc=0x0c09ed96u; return 0; }
r[2]+=0x00000054u;
goto P_0c09ed98;
P_0c09ed98: /* original 33cc, guest PC 0x0c09ed98 */
if(!s->budget--) { s->failed_pc=0x0c09ed98u; return 0; }
r[3]+=r[12];
goto P_0c09ed9a;
P_0c09ed9a: /* original 2f36, guest PC 0x0c09ed9a */
if(!s->budget--) { s->failed_pc=0x0c09ed9au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ed9c;
P_0c09ed9c: /* original 2f26, guest PC 0x0c09ed9c */
if(!s->budget--) { s->failed_pc=0x0c09ed9cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ed9e;
P_0c09ed9e: /* original 2f46, guest PC 0x0c09ed9e */
if(!s->budget--) { s->failed_pc=0x0c09ed9eu; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09eda0;
P_0c09eda0: /* original 2f66, guest PC 0x0c09eda0 */
if(!s->budget--) { s->failed_pc=0x0c09eda0u; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09eda2;
P_0c09eda2: /* original 03fe, guest PC 0x0c09eda2 */
if(!s->budget--) { s->failed_pc=0x0c09eda2u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c09eda4;
P_0c09eda4: /* original 2f36, guest PC 0x0c09eda4 */
if(!s->budget--) { s->failed_pc=0x0c09eda4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09eda6;
P_0c09eda6: /* original 9022, guest PC 0x0c09eda6 */
if(!s->budget--) { s->failed_pc=0x0c09eda6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edeeu,2);
goto P_0c09eda8;
P_0c09eda8: /* original f4e6, guest PC 0x0c09eda8 */
if(!s->budget--) { s->failed_pc=0x0c09eda8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c09edaa;
P_0c09edaa: /* original 9621, guest PC 0x0c09edaa */
if(!s->budget--) { s->failed_pc=0x0c09edaau; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09edf0u,2);
goto P_0c09edac;
P_0c09edac: /* original 36ec, guest PC 0x0c09edac */
if(!s->budget--) { s->failed_pc=0x0c09edacu; return 0; }
r[6]+=r[14];
goto P_0c09edae;
P_0c09edae: /* original a023, guest PC 0x0c09edae */
if(!s->budget--) { s->failed_pc=0x0c09edaeu; return 0; }
r[4]=r[14];
goto P_0c09edf8;
P_0c09edb0: /* original 64e3, guest PC 0x0c09edb0 */
if(!s->budget--) { s->failed_pc=0x0c09edb0u; return 0; }
r[4]=r[14];
if(!vf3_matrix_family(0x0c09edb2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09edb2u; return 0; } return 1;
P_0c09edf8: /* original bc5b, guest PC 0x0c09edf8 */
if(!s->budget--) { s->failed_pc=0x0c09edf8u; return 0; }
target=code_base|0x0c09e6b2u; r[16]=code_base|0x0c09edfcu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09edfcu) { target=s->pc; goto dispatch; }
goto P_0c09edfc;
P_0c09edfa: /* original 0009, guest PC 0x0c09edfa */
if(!s->budget--) { s->failed_pc=0x0c09edfau; return 0; }
goto P_0c09edfc;
P_0c09edfc: /* original 4a0b, guest PC 0x0c09edfc */
if(!s->budget--) { s->failed_pc=0x0c09edfcu; return 0; }
target=r[10];
r[16]=code_base|0x0c09ee00u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ee00u) { target=s->pc; goto dispatch; }
goto P_0c09ee00;
P_0c09edfe: /* original e401, guest PC 0x0c09edfe */
if(!s->budget--) { s->failed_pc=0x0c09edfeu; return 0; }
r[4]=0x00000001u;
goto P_0c09ee00;
P_0c09ee00: /* original 9193, guest PC 0x0c09ee00 */
if(!s->budget--) { s->failed_pc=0x0c09ee00u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2au,2);
goto P_0c09ee02;
P_0c09ee02: /* original 3f1c, guest PC 0x0c09ee02 */
if(!s->budget--) { s->failed_pc=0x0c09ee02u; return 0; }
r[15]+=r[1];
goto P_0c09ee04;
P_0c09ee04: /* original 4f16, guest PC 0x0c09ee04 */
if(!s->budget--) { s->failed_pc=0x0c09ee04u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c09ee06;
P_0c09ee06: /* original 4f26, guest PC 0x0c09ee06 */
if(!s->budget--) { s->failed_pc=0x0c09ee06u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09ee08;
P_0c09ee08: /* original 68f6, guest PC 0x0c09ee08 */
if(!s->budget--) { s->failed_pc=0x0c09ee08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09ee0a;
P_0c09ee0a: /* original 69f6, guest PC 0x0c09ee0a */
if(!s->budget--) { s->failed_pc=0x0c09ee0au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09ee0c;
P_0c09ee0c: /* original 6af6, guest PC 0x0c09ee0c */
if(!s->budget--) { s->failed_pc=0x0c09ee0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09ee0e;
P_0c09ee0e: /* original 6bf6, guest PC 0x0c09ee0e */
if(!s->budget--) { s->failed_pc=0x0c09ee0eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09ee10;
P_0c09ee10: /* original 6cf6, guest PC 0x0c09ee10 */
if(!s->budget--) { s->failed_pc=0x0c09ee10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09ee12;
P_0c09ee12: /* original 6df6, guest PC 0x0c09ee12 */
if(!s->budget--) { s->failed_pc=0x0c09ee12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09ee14;
P_0c09ee14: /* original 000b, guest PC 0x0c09ee14 */
if(!s->budget--) { s->failed_pc=0x0c09ee14u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09ee16: /* original 6ef6, guest PC 0x0c09ee16 */
if(!s->budget--) { s->failed_pc=0x0c09ee16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09ee18u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
