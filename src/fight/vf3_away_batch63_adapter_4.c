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
int vf3_away_batch63_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08ec00u: goto P_0c08ec00;
case 0x0c08ec02u: goto P_0c08ec02;
case 0x0c08ec04u: goto P_0c08ec04;
case 0x0c08ec06u: goto P_0c08ec06;
case 0x0c08ec08u: goto P_0c08ec08;
case 0x0c08ec0au: goto P_0c08ec0a;
case 0x0c08ec0cu: goto P_0c08ec0c;
case 0x0c08ec0eu: goto P_0c08ec0e;
case 0x0c08ec10u: goto P_0c08ec10;
case 0x0c08ec12u: goto P_0c08ec12;
case 0x0c08ec14u: goto P_0c08ec14;
case 0x0c08ec16u: goto P_0c08ec16;
case 0x0c08ec18u: goto P_0c08ec18;
case 0x0c08ec1au: goto P_0c08ec1a;
case 0x0c08ec1cu: goto P_0c08ec1c;
case 0x0c08ec1eu: goto P_0c08ec1e;
case 0x0c08ec20u: goto P_0c08ec20;
case 0x0c08ec22u: goto P_0c08ec22;
case 0x0c08ec24u: goto P_0c08ec24;
case 0x0c08ec26u: goto P_0c08ec26;
case 0x0c08ec28u: goto P_0c08ec28;
case 0x0c08ec2au: goto P_0c08ec2a;
case 0x0c08ec2cu: goto P_0c08ec2c;
case 0x0c08ec2eu: goto P_0c08ec2e;
case 0x0c08ec30u: goto P_0c08ec30;
case 0x0c08ec32u: goto P_0c08ec32;
case 0x0c08ec34u: goto P_0c08ec34;
case 0x0c08ec36u: goto P_0c08ec36;
case 0x0c08ec38u: goto P_0c08ec38;
case 0x0c08ec3au: goto P_0c08ec3a;
case 0x0c08ec3cu: goto P_0c08ec3c;
case 0x0c08ec3eu: goto P_0c08ec3e;
case 0x0c08ec40u: goto P_0c08ec40;
case 0x0c08ec42u: goto P_0c08ec42;
case 0x0c08ec44u: goto P_0c08ec44;
case 0x0c08ec46u: goto P_0c08ec46;
case 0x0c08ec48u: goto P_0c08ec48;
case 0x0c08ec4au: goto P_0c08ec4a;
case 0x0c08ec4cu: goto P_0c08ec4c;
case 0x0c08ec4eu: goto P_0c08ec4e;
case 0x0c08ec50u: goto P_0c08ec50;
case 0x0c08ec52u: goto P_0c08ec52;
case 0x0c08ec54u: goto P_0c08ec54;
case 0x0c08ec56u: goto P_0c08ec56;
case 0x0c08ec58u: goto P_0c08ec58;
case 0x0c08ec5au: goto P_0c08ec5a;
case 0x0c08ec5cu: goto P_0c08ec5c;
case 0x0c08ec5eu: goto P_0c08ec5e;
case 0x0c08ec60u: goto P_0c08ec60;
case 0x0c08ec62u: goto P_0c08ec62;
case 0x0c08ec64u: goto P_0c08ec64;
case 0x0c08ec66u: goto P_0c08ec66;
case 0x0c08ec68u: goto P_0c08ec68;
case 0x0c08ec6au: goto P_0c08ec6a;
case 0x0c08ec6cu: goto P_0c08ec6c;
case 0x0c08ec6eu: goto P_0c08ec6e;
case 0x0c08ec70u: goto P_0c08ec70;
case 0x0c08ec72u: goto P_0c08ec72;
case 0x0c08ec74u: goto P_0c08ec74;
case 0x0c08ec76u: goto P_0c08ec76;
case 0x0c08ec78u: goto P_0c08ec78;
case 0x0c08ec7au: goto P_0c08ec7a;
case 0x0c08ec7cu: goto P_0c08ec7c;
case 0x0c08ec7eu: goto P_0c08ec7e;
case 0x0c08ec80u: goto P_0c08ec80;
case 0x0c08ec82u: goto P_0c08ec82;
case 0x0c08ec84u: goto P_0c08ec84;
case 0x0c08ec86u: goto P_0c08ec86;
case 0x0c08ec88u: goto P_0c08ec88;
case 0x0c08ec8au: goto P_0c08ec8a;
case 0x0c08ec8cu: goto P_0c08ec8c;
case 0x0c08ec8eu: goto P_0c08ec8e;
case 0x0c08ec90u: goto P_0c08ec90;
case 0x0c08ec92u: goto P_0c08ec92;
case 0x0c08ec94u: goto P_0c08ec94;
case 0x0c08ec96u: goto P_0c08ec96;
case 0x0c08ec98u: goto P_0c08ec98;
case 0x0c08ec9au: goto P_0c08ec9a;
case 0x0c08ec9cu: goto P_0c08ec9c;
case 0x0c08ec9eu: goto P_0c08ec9e;
case 0x0c08eca0u: goto P_0c08eca0;
case 0x0c08eca2u: goto P_0c08eca2;
case 0x0c08eca4u: goto P_0c08eca4;
case 0x0c08eca6u: goto P_0c08eca6;
case 0x0c08eca8u: goto P_0c08eca8;
case 0x0c08ecaau: goto P_0c08ecaa;
case 0x0c08ecacu: goto P_0c08ecac;
case 0x0c08ecaeu: goto P_0c08ecae;
case 0x0c08ecb0u: goto P_0c08ecb0;
case 0x0c08ecb2u: goto P_0c08ecb2;
case 0x0c08ecb4u: goto P_0c08ecb4;
case 0x0c08ecb6u: goto P_0c08ecb6;
case 0x0c08ecb8u: goto P_0c08ecb8;
case 0x0c08ecbau: goto P_0c08ecba;
case 0x0c08ecbcu: goto P_0c08ecbc;
case 0x0c08ecbeu: goto P_0c08ecbe;
case 0x0c08ecc0u: goto P_0c08ecc0;
case 0x0c08ecc2u: goto P_0c08ecc2;
case 0x0c08ecc4u: goto P_0c08ecc4;
case 0x0c08ecc6u: goto P_0c08ecc6;
case 0x0c08ecc8u: goto P_0c08ecc8;
case 0x0c08eccau: goto P_0c08ecca;
case 0x0c08ecccu: goto P_0c08eccc;
case 0x0c08ecceu: goto P_0c08ecce;
case 0x0c08ecd0u: goto P_0c08ecd0;
case 0x0c08ecd2u: goto P_0c08ecd2;
case 0x0c08ecd4u: goto P_0c08ecd4;
case 0x0c08ecd6u: goto P_0c08ecd6;
case 0x0c08ecd8u: goto P_0c08ecd8;
case 0x0c08ecdau: goto P_0c08ecda;
case 0x0c08ecdcu: goto P_0c08ecdc;
case 0x0c08ecdeu: goto P_0c08ecde;
case 0x0c08ece0u: goto P_0c08ece0;
case 0x0c08ece2u: goto P_0c08ece2;
case 0x0c08ece4u: goto P_0c08ece4;
case 0x0c08ece6u: goto P_0c08ece6;
case 0x0c08ece8u: goto P_0c08ece8;
case 0x0c08eceau: goto P_0c08ecea;
case 0x0c08ececu: goto P_0c08ecec;
case 0x0c08eceeu: goto P_0c08ecee;
case 0x0c08ecf0u: goto P_0c08ecf0;
case 0x0c08ecf2u: goto P_0c08ecf2;
case 0x0c08ecf4u: goto P_0c08ecf4;
case 0x0c08ecf6u: goto P_0c08ecf6;
case 0x0c08ecf8u: goto P_0c08ecf8;
case 0x0c08ecfau: goto P_0c08ecfa;
case 0x0c08ecfcu: goto P_0c08ecfc;
case 0x0c08ecfeu: goto P_0c08ecfe;
case 0x0c08ed00u: goto P_0c08ed00;
case 0x0c08ed02u: goto P_0c08ed02;
case 0x0c08ed04u: goto P_0c08ed04;
case 0x0c08ed06u: goto P_0c08ed06;
case 0x0c08ed08u: goto P_0c08ed08;
case 0x0c08ed0au: goto P_0c08ed0a;
case 0x0c08ed0cu: goto P_0c08ed0c;
case 0x0c08ed0eu: goto P_0c08ed0e;
case 0x0c08ed10u: goto P_0c08ed10;
case 0x0c08ed12u: goto P_0c08ed12;
case 0x0c08ed14u: goto P_0c08ed14;
case 0x0c08ed16u: goto P_0c08ed16;
case 0x0c08ed18u: goto P_0c08ed18;
case 0x0c08ed1au: goto P_0c08ed1a;
case 0x0c08ed1cu: goto P_0c08ed1c;
case 0x0c08ed1eu: goto P_0c08ed1e;
case 0x0c08ed20u: goto P_0c08ed20;
case 0x0c08ed70u: goto P_0c08ed70;
case 0x0c08ed72u: goto P_0c08ed72;
case 0x0c08ed74u: goto P_0c08ed74;
case 0x0c08ed76u: goto P_0c08ed76;
case 0x0c08ed78u: goto P_0c08ed78;
case 0x0c08ed7au: goto P_0c08ed7a;
case 0x0c08ed7cu: goto P_0c08ed7c;
case 0x0c08ed7eu: goto P_0c08ed7e;
case 0x0c08ed80u: goto P_0c08ed80;
case 0x0c08ed82u: goto P_0c08ed82;
case 0x0c08ed84u: goto P_0c08ed84;
case 0x0c08ed86u: goto P_0c08ed86;
case 0x0c08ed88u: goto P_0c08ed88;
case 0x0c08ed8au: goto P_0c08ed8a;
case 0x0c08ed8cu: goto P_0c08ed8c;
case 0x0c08ed8eu: goto P_0c08ed8e;
case 0x0c08ed90u: goto P_0c08ed90;
case 0x0c08ed92u: goto P_0c08ed92;
case 0x0c08ed94u: goto P_0c08ed94;
case 0x0c08ed96u: goto P_0c08ed96;
case 0x0c08ed98u: goto P_0c08ed98;
case 0x0c08ed9au: goto P_0c08ed9a;
case 0x0c08ed9cu: goto P_0c08ed9c;
case 0x0c08ed9eu: goto P_0c08ed9e;
case 0x0c08eda0u: goto P_0c08eda0;
case 0x0c08eda2u: goto P_0c08eda2;
case 0x0c08eda4u: goto P_0c08eda4;
case 0x0c08eda6u: goto P_0c08eda6;
case 0x0c08eda8u: goto P_0c08eda8;
case 0x0c08edaau: goto P_0c08edaa;
case 0x0c08edacu: goto P_0c08edac;
case 0x0c08edaeu: goto P_0c08edae;
case 0x0c08edb0u: goto P_0c08edb0;
case 0x0c08edb2u: goto P_0c08edb2;
case 0x0c08edb4u: goto P_0c08edb4;
case 0x0c08edb6u: goto P_0c08edb6;
case 0x0c08edb8u: goto P_0c08edb8;
case 0x0c08edbau: goto P_0c08edba;
case 0x0c08edbcu: goto P_0c08edbc;
case 0x0c08edbeu: goto P_0c08edbe;
case 0x0c08edc0u: goto P_0c08edc0;
case 0x0c08edc2u: goto P_0c08edc2;
case 0x0c08edc4u: goto P_0c08edc4;
case 0x0c08edc6u: goto P_0c08edc6;
case 0x0c08edc8u: goto P_0c08edc8;
case 0x0c08edcau: goto P_0c08edca;
case 0x0c08edccu: goto P_0c08edcc;
case 0x0c08edceu: goto P_0c08edce;
case 0x0c08edd0u: goto P_0c08edd0;
case 0x0c08edd2u: goto P_0c08edd2;
case 0x0c08edd4u: goto P_0c08edd4;
case 0x0c08edd6u: goto P_0c08edd6;
case 0x0c08edd8u: goto P_0c08edd8;
case 0x0c08eddau: goto P_0c08edda;
case 0x0c08eddcu: goto P_0c08eddc;
case 0x0c08eddeu: goto P_0c08edde;
case 0x0c08ede0u: goto P_0c08ede0;
case 0x0c08ede2u: goto P_0c08ede2;
case 0x0c08ede4u: goto P_0c08ede4;
case 0x0c08ede6u: goto P_0c08ede6;
case 0x0c08ede8u: goto P_0c08ede8;
case 0x0c08edeau: goto P_0c08edea;
case 0x0c08edecu: goto P_0c08edec;
case 0x0c08edeeu: goto P_0c08edee;
case 0x0c08edf0u: goto P_0c08edf0;
case 0x0c08edf2u: goto P_0c08edf2;
case 0x0c08edf4u: goto P_0c08edf4;
case 0x0c08edf6u: goto P_0c08edf6;
case 0x0c08edf8u: goto P_0c08edf8;
case 0x0c08edfau: goto P_0c08edfa;
case 0x0c08edfcu: goto P_0c08edfc;
case 0x0c08edfeu: goto P_0c08edfe;
case 0x0c08ee00u: goto P_0c08ee00;
case 0x0c08ee02u: goto P_0c08ee02;
case 0x0c08ee04u: goto P_0c08ee04;
case 0x0c08ee06u: goto P_0c08ee06;
case 0x0c08ee08u: goto P_0c08ee08;
case 0x0c08ee0au: goto P_0c08ee0a;
case 0x0c08ee0cu: goto P_0c08ee0c;
case 0x0c08ee0eu: goto P_0c08ee0e;
case 0x0c08ee10u: goto P_0c08ee10;
case 0x0c08ee12u: goto P_0c08ee12;
case 0x0c08ee14u: goto P_0c08ee14;
case 0x0c08ee16u: goto P_0c08ee16;
case 0x0c08ee18u: goto P_0c08ee18;
case 0x0c08ee1au: goto P_0c08ee1a;
case 0x0c08ee1cu: goto P_0c08ee1c;
case 0x0c08ee1eu: goto P_0c08ee1e;
case 0x0c08ee20u: goto P_0c08ee20;
case 0x0c08ee22u: goto P_0c08ee22;
case 0x0c08ee24u: goto P_0c08ee24;
case 0x0c08ee26u: goto P_0c08ee26;
case 0x0c08ee28u: goto P_0c08ee28;
case 0x0c08ee2au: goto P_0c08ee2a;
case 0x0c08ee2cu: goto P_0c08ee2c;
case 0x0c08ee2eu: goto P_0c08ee2e;
case 0x0c08ee30u: goto P_0c08ee30;
case 0x0c08ee32u: goto P_0c08ee32;
case 0x0c08ee34u: goto P_0c08ee34;
case 0x0c08ee36u: goto P_0c08ee36;
case 0x0c08ee38u: goto P_0c08ee38;
case 0x0c08ee3au: goto P_0c08ee3a;
case 0x0c08ee3cu: goto P_0c08ee3c;
case 0x0c08ee3eu: goto P_0c08ee3e;
case 0x0c08ee40u: goto P_0c08ee40;
case 0x0c08ee42u: goto P_0c08ee42;
case 0x0c08ee44u: goto P_0c08ee44;
case 0x0c08ee46u: goto P_0c08ee46;
case 0x0c08ee48u: goto P_0c08ee48;
case 0x0c08ee4au: goto P_0c08ee4a;
case 0x0c08ee4cu: goto P_0c08ee4c;
case 0x0c08ee4eu: goto P_0c08ee4e;
case 0x0c08ee50u: goto P_0c08ee50;
case 0x0c08ee52u: goto P_0c08ee52;
case 0x0c08ee54u: goto P_0c08ee54;
case 0x0c08ee56u: goto P_0c08ee56;
case 0x0c08ee58u: goto P_0c08ee58;
case 0x0c08ee5au: goto P_0c08ee5a;
case 0x0c08ee5cu: goto P_0c08ee5c;
case 0x0c08ee5eu: goto P_0c08ee5e;
case 0x0c08ee60u: goto P_0c08ee60;
case 0x0c08ee62u: goto P_0c08ee62;
case 0x0c08ee64u: goto P_0c08ee64;
case 0x0c08ee66u: goto P_0c08ee66;
case 0x0c08ee68u: goto P_0c08ee68;
case 0x0c08ee6au: goto P_0c08ee6a;
case 0x0c08ee6cu: goto P_0c08ee6c;
case 0x0c08ee6eu: goto P_0c08ee6e;
case 0x0c08ee70u: goto P_0c08ee70;
case 0x0c08ee72u: goto P_0c08ee72;
case 0x0c08ee74u: goto P_0c08ee74;
case 0x0c08ee76u: goto P_0c08ee76;
case 0x0c08ee78u: goto P_0c08ee78;
case 0x0c08ee7au: goto P_0c08ee7a;
case 0x0c08ee7cu: goto P_0c08ee7c;
case 0x0c08ee7eu: goto P_0c08ee7e;
case 0x0c08ee80u: goto P_0c08ee80;
case 0x0c08ee82u: goto P_0c08ee82;
case 0x0c08ee84u: goto P_0c08ee84;
case 0x0c08ee86u: goto P_0c08ee86;
case 0x0c08ee88u: goto P_0c08ee88;
case 0x0c08ee8au: goto P_0c08ee8a;
case 0x0c08ee8cu: goto P_0c08ee8c;
case 0x0c08ee8eu: goto P_0c08ee8e;
case 0x0c08ee90u: goto P_0c08ee90;
case 0x0c08ee92u: goto P_0c08ee92;
case 0x0c08ee94u: goto P_0c08ee94;
case 0x0c08ee96u: goto P_0c08ee96;
case 0x0c08ee98u: goto P_0c08ee98;
case 0x0c08ee9au: goto P_0c08ee9a;
case 0x0c08ee9cu: goto P_0c08ee9c;
case 0x0c08ee9eu: goto P_0c08ee9e;
case 0x0c08eea0u: goto P_0c08eea0;
case 0x0c08eea2u: goto P_0c08eea2;
case 0x0c08eea4u: goto P_0c08eea4;
case 0x0c08eea6u: goto P_0c08eea6;
case 0x0c08eea8u: goto P_0c08eea8;
case 0x0c08eeaau: goto P_0c08eeaa;
case 0x0c08eeacu: goto P_0c08eeac;
case 0x0c08eeaeu: goto P_0c08eeae;
case 0x0c08eeb0u: goto P_0c08eeb0;
case 0x0c08eeb2u: goto P_0c08eeb2;
case 0x0c08eeb4u: goto P_0c08eeb4;
case 0x0c08eeb6u: goto P_0c08eeb6;
case 0x0c08eeb8u: goto P_0c08eeb8;
case 0x0c08eebau: goto P_0c08eeba;
case 0x0c08eebcu: goto P_0c08eebc;
case 0x0c08eebeu: goto P_0c08eebe;
case 0x0c08eec0u: goto P_0c08eec0;
case 0x0c08eec2u: goto P_0c08eec2;
case 0x0c08eec4u: goto P_0c08eec4;
case 0x0c08eec6u: goto P_0c08eec6;
case 0x0c08eec8u: goto P_0c08eec8;
case 0x0c08eecau: goto P_0c08eeca;
case 0x0c08eeccu: goto P_0c08eecc;
case 0x0c08eeceu: goto P_0c08eece;
case 0x0c08eed0u: goto P_0c08eed0;
case 0x0c08eed2u: goto P_0c08eed2;
case 0x0c08eed4u: goto P_0c08eed4;
case 0x0c08eed6u: goto P_0c08eed6;
case 0x0c08eed8u: goto P_0c08eed8;
case 0x0c08eedau: goto P_0c08eeda;
case 0x0c08eedcu: goto P_0c08eedc;
case 0x0c08eedeu: goto P_0c08eede;
case 0x0c08eee0u: goto P_0c08eee0;
case 0x0c08eee2u: goto P_0c08eee2;
case 0x0c08eee4u: goto P_0c08eee4;
case 0x0c08eee6u: goto P_0c08eee6;
case 0x0c08eee8u: goto P_0c08eee8;
case 0x0c08eeeau: goto P_0c08eeea;
case 0x0c08eeecu: goto P_0c08eeec;
case 0x0c08eeeeu: goto P_0c08eeee;
case 0x0c08eef0u: goto P_0c08eef0;
case 0x0c08eef2u: goto P_0c08eef2;
case 0x0c08eef4u: goto P_0c08eef4;
case 0x0c08eef6u: goto P_0c08eef6;
case 0x0c08eef8u: goto P_0c08eef8;
case 0x0c08eefau: goto P_0c08eefa;
case 0x0c08eefcu: goto P_0c08eefc;
case 0x0c08eefeu: goto P_0c08eefe;
case 0x0c08ef00u: goto P_0c08ef00;
case 0x0c08ef02u: goto P_0c08ef02;
case 0x0c08ef04u: goto P_0c08ef04;
case 0x0c08ef06u: goto P_0c08ef06;
case 0x0c08ef08u: goto P_0c08ef08;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08ec00: /* original 2fe6, guest PC 0x0c08ec00 */
if(!s->budget--) { s->failed_pc=0x0c08ec00u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ec02;
P_0c08ec02: /* original 2fd6, guest PC 0x0c08ec02 */
if(!s->budget--) { s->failed_pc=0x0c08ec02u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ec04;
P_0c08ec04: /* original 2fc6, guest PC 0x0c08ec04 */
if(!s->budget--) { s->failed_pc=0x0c08ec04u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ec06;
P_0c08ec06: /* original 2fb6, guest PC 0x0c08ec06 */
if(!s->budget--) { s->failed_pc=0x0c08ec06u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ec08;
P_0c08ec08: /* original 2fa6, guest PC 0x0c08ec08 */
if(!s->budget--) { s->failed_pc=0x0c08ec08u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ec0a;
P_0c08ec0a: /* original fffb, guest PC 0x0c08ec0a */
if(!s->budget--) { s->failed_pc=0x0c08ec0au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08ec0c;
P_0c08ec0c: /* original ffeb, guest PC 0x0c08ec0c */
if(!s->budget--) { s->failed_pc=0x0c08ec0cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c08ec0e;
P_0c08ec0e: /* original ffdb, guest PC 0x0c08ec0e */
if(!s->budget--) { s->failed_pc=0x0c08ec0eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c08ec10;
P_0c08ec10: /* original ffcb, guest PC 0x0c08ec10 */
if(!s->budget--) { s->failed_pc=0x0c08ec10u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c08ec12;
P_0c08ec12: /* original d34b, guest PC 0x0c08ec12 */
if(!s->budget--) { s->failed_pc=0x0c08ec12u; return 0; }
r[3]=read(ram,0x0c08ed40u,4);
goto P_0c08ec14;
P_0c08ec14: /* original 4f22, guest PC 0x0c08ec14 */
if(!s->budget--) { s->failed_pc=0x0c08ec14u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08ec16;
P_0c08ec16: /* original 6032, guest PC 0x0c08ec16 */
if(!s->budget--) { s->failed_pc=0x0c08ec16u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c08ec18;
P_0c08ec18: /* original c808, guest PC 0x0c08ec18 */
if(!s->budget--) { s->failed_pc=0x0c08ec18u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c08ec1a;
P_0c08ec1a: /* original 8f02, guest PC 0x0c08ec1a */
if(!s->budget--) { s->failed_pc=0x0c08ec1au; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(!cond) { goto P_0c08ec22; }
goto P_0c08ec1e;
P_0c08ec1c: /* original 6e43, guest PC 0x0c08ec1c */
if(!s->budget--) { s->failed_pc=0x0c08ec1cu; return 0; }
r[14]=r[4];
goto P_0c08ec1e;
P_0c08ec1e: /* original a0a7, guest PC 0x0c08ec1e */
if(!s->budget--) { s->failed_pc=0x0c08ec1eu; return 0; }
goto P_0c08ed70;
P_0c08ec20: /* original 0009, guest PC 0x0c08ec20 */
if(!s->budget--) { s->failed_pc=0x0c08ec20u; return 0; }
goto P_0c08ec22;
P_0c08ec22: /* original c748, guest PC 0x0c08ec22 */
if(!s->budget--) { s->failed_pc=0x0c08ec22u; return 0; }
r[0]=code_base|0x0008ed44u;
goto P_0c08ec24;
P_0c08ec24: /* original d349, guest PC 0x0c08ec24 */
if(!s->budget--) { s->failed_pc=0x0c08ec24u; return 0; }
r[3]=read(ram,0x0c08ed4cu,4);
goto P_0c08ec26;
P_0c08ec26: /* original fe08, guest PC 0x0c08ec26 */
if(!s->budget--) { s->failed_pc=0x0c08ec26u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c08ec28;
P_0c08ec28: /* original c747, guest PC 0x0c08ec28 */
if(!s->budget--) { s->failed_pc=0x0c08ec28u; return 0; }
r[0]=code_base|0x0008ed48u;
goto P_0c08ec2a;
P_0c08ec2a: /* original ff08, guest PC 0x0c08ec2a */
if(!s->budget--) { s->failed_pc=0x0c08ec2au; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08ec2c;
P_0c08ec2c: /* original fd8d, guest PC 0x0c08ec2c */
if(!s->budget--) { s->failed_pc=0x0c08ec2cu; return 0; }
fr[13]=0;
goto P_0c08ec2e;
P_0c08ec2e: /* original 430b, guest PC 0x0c08ec2e */
if(!s->budget--) { s->failed_pc=0x0c08ec2eu; return 0; }
target=r[3];
r[16]=code_base|0x0c08ec32u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ec32u) { target=s->pc; goto dispatch; }
goto P_0c08ec32;
P_0c08ec30: /* original e400, guest PC 0x0c08ec30 */
if(!s->budget--) { s->failed_pc=0x0c08ec30u; return 0; }
r[4]=0x00000000u;
goto P_0c08ec32;
P_0c08ec32: /* original da47, guest PC 0x0c08ec32 */
if(!s->budget--) { s->failed_pc=0x0c08ec32u; return 0; }
r[10]=read(ram,0x0c08ed50u,4);
goto P_0c08ec34;
P_0c08ec34: /* original 4a0b, guest PC 0x0c08ec34 */
if(!s->budget--) { s->failed_pc=0x0c08ec34u; return 0; }
target=r[10];
r[16]=code_base|0x0c08ec38u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ec38u) { target=s->pc; goto dispatch; }
goto P_0c08ec38;
P_0c08ec36: /* original 0009, guest PC 0x0c08ec36 */
if(!s->budget--) { s->failed_pc=0x0c08ec36u; return 0; }
goto P_0c08ec38;
P_0c08ec38: /* original 9076, guest PC 0x0c08ec38 */
if(!s->budget--) { s->failed_pc=0x0c08ec38u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ed28u,2);
goto P_0c08ec3a;
P_0c08ec3a: /* original dd46, guest PC 0x0c08ec3a */
if(!s->budget--) { s->failed_pc=0x0c08ec3au; return 0; }
r[13]=read(ram,0x0c08ed54u,4);
goto P_0c08ec3c;
P_0c08ec3c: /* original f6e6, guest PC 0x0c08ec3c */
if(!s->budget--) { s->failed_pc=0x0c08ec3cu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08ec3e;
P_0c08ec3e: /* original 70fc, guest PC 0x0c08ec3e */
if(!s->budget--) { s->failed_pc=0x0c08ec3eu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08ec40;
P_0c08ec40: /* original f5e6, guest PC 0x0c08ec40 */
if(!s->budget--) { s->failed_pc=0x0c08ec40u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08ec42;
P_0c08ec42: /* original 70fc, guest PC 0x0c08ec42 */
if(!s->budget--) { s->failed_pc=0x0c08ec42u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08ec44;
P_0c08ec44: /* original f64d, guest PC 0x0c08ec44 */
if(!s->budget--) { s->failed_pc=0x0c08ec44u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08ec46;
P_0c08ec46: /* original 4d0b, guest PC 0x0c08ec46 */
if(!s->budget--) { s->failed_pc=0x0c08ec46u; return 0; }
target=r[13];
r[16]=code_base|0x0c08ec4au;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ec4au) { target=s->pc; goto dispatch; }
goto P_0c08ec4a;
P_0c08ec48: /* original f4e6, guest PC 0x0c08ec48 */
if(!s->budget--) { s->failed_pc=0x0c08ec48u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08ec4a;
P_0c08ec4a: /* original 906e, guest PC 0x0c08ec4a */
if(!s->budget--) { s->failed_pc=0x0c08ec4au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ed2au,2);
goto P_0c08ec4c;
P_0c08ec4c: /* original dc42, guest PC 0x0c08ec4c */
if(!s->budget--) { s->failed_pc=0x0c08ec4cu; return 0; }
r[12]=read(ram,0x0c08ed58u,4);
goto P_0c08ec4e;
P_0c08ec4e: /* original fce6, guest PC 0x0c08ec4e */
if(!s->budget--) { s->failed_pc=0x0c08ec4eu; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c08ec50;
P_0c08ec50: /* original f5cc, guest PC 0x0c08ec50 */
if(!s->budget--) { s->failed_pc=0x0c08ec50u; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c08ec52;
P_0c08ec52: /* original f6cc, guest PC 0x0c08ec52 */
if(!s->budget--) { s->failed_pc=0x0c08ec52u; return 0; }
vf3_matrix_move(s,6,12);
goto P_0c08ec54;
P_0c08ec54: /* original 4c0b, guest PC 0x0c08ec54 */
if(!s->budget--) { s->failed_pc=0x0c08ec54u; return 0; }
target=r[12];
r[16]=code_base|0x0c08ec58u;
vf3_matrix_move(s,4,12);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ec58u) { target=s->pc; goto dispatch; }
goto P_0c08ec58;
P_0c08ec56: /* original f4cc, guest PC 0x0c08ec56 */
if(!s->budget--) { s->failed_pc=0x0c08ec56u; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c08ec58;
P_0c08ec58: /* original 9468, guest PC 0x0c08ec58 */
if(!s->budget--) { s->failed_pc=0x0c08ec58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ed2cu,2);
goto P_0c08ec5a;
P_0c08ec5a: /* original db40, guest PC 0x0c08ec5a */
if(!s->budget--) { s->failed_pc=0x0c08ec5au; return 0; }
r[11]=read(ram,0x0c08ed5cu,4);
goto P_0c08ec5c;
P_0c08ec5c: /* original 4b0b, guest PC 0x0c08ec5c */
if(!s->budget--) { s->failed_pc=0x0c08ec5cu; return 0; }
target=r[11];
r[16]=code_base|0x0c08ec60u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ec60u) { target=s->pc; goto dispatch; }
goto P_0c08ec60;
P_0c08ec5e: /* original 0009, guest PC 0x0c08ec5e */
if(!s->budget--) { s->failed_pc=0x0c08ec5eu; return 0; }
goto P_0c08ec60;
P_0c08ec60: /* original 4a0b, guest PC 0x0c08ec60 */
if(!s->budget--) { s->failed_pc=0x0c08ec60u; return 0; }
target=r[10];
r[16]=code_base|0x0c08ec64u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ec64u) { target=s->pc; goto dispatch; }
goto P_0c08ec64;
P_0c08ec62: /* original 0009, guest PC 0x0c08ec62 */
if(!s->budget--) { s->failed_pc=0x0c08ec62u; return 0; }
goto P_0c08ec64;
P_0c08ec64: /* original 9063, guest PC 0x0c08ec64 */
if(!s->budget--) { s->failed_pc=0x0c08ec64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ed2eu,2);
goto P_0c08ec66;
P_0c08ec66: /* original f6e6, guest PC 0x0c08ec66 */
if(!s->budget--) { s->failed_pc=0x0c08ec66u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08ec68;
P_0c08ec68: /* original 70fc, guest PC 0x0c08ec68 */
if(!s->budget--) { s->failed_pc=0x0c08ec68u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08ec6a;
P_0c08ec6a: /* original f5e6, guest PC 0x0c08ec6a */
if(!s->budget--) { s->failed_pc=0x0c08ec6au; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08ec6c;
P_0c08ec6c: /* original 70fc, guest PC 0x0c08ec6c */
if(!s->budget--) { s->failed_pc=0x0c08ec6cu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08ec6e;
P_0c08ec6e: /* original f64d, guest PC 0x0c08ec6e */
if(!s->budget--) { s->failed_pc=0x0c08ec6eu; return 0; }
fr[6]^=0x80000000u;
goto P_0c08ec70;
P_0c08ec70: /* original 4d0b, guest PC 0x0c08ec70 */
if(!s->budget--) { s->failed_pc=0x0c08ec70u; return 0; }
target=r[13];
r[16]=code_base|0x0c08ec74u;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ec74u) { target=s->pc; goto dispatch; }
goto P_0c08ec74;
P_0c08ec72: /* original f4e6, guest PC 0x0c08ec72 */
if(!s->budget--) { s->failed_pc=0x0c08ec72u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08ec74;
P_0c08ec74: /* original 905c, guest PC 0x0c08ec74 */
if(!s->budget--) { s->failed_pc=0x0c08ec74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ed30u,2);
goto P_0c08ec76;
P_0c08ec76: /* original fce6, guest PC 0x0c08ec76 */
if(!s->budget--) { s->failed_pc=0x0c08ec76u; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c08ec78;
P_0c08ec78: /* original f5cc, guest PC 0x0c08ec78 */
if(!s->budget--) { s->failed_pc=0x0c08ec78u; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c08ec7a;
P_0c08ec7a: /* original f6cc, guest PC 0x0c08ec7a */
if(!s->budget--) { s->failed_pc=0x0c08ec7au; return 0; }
vf3_matrix_move(s,6,12);
goto P_0c08ec7c;
P_0c08ec7c: /* original 4c0b, guest PC 0x0c08ec7c */
if(!s->budget--) { s->failed_pc=0x0c08ec7cu; return 0; }
target=r[12];
r[16]=code_base|0x0c08ec80u;
vf3_matrix_move(s,4,12);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ec80u) { target=s->pc; goto dispatch; }
goto P_0c08ec80;
P_0c08ec7e: /* original f4cc, guest PC 0x0c08ec7e */
if(!s->budget--) { s->failed_pc=0x0c08ec7eu; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c08ec80;
P_0c08ec80: /* original 9454, guest PC 0x0c08ec80 */
if(!s->budget--) { s->failed_pc=0x0c08ec80u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ed2cu,2);
goto P_0c08ec82;
P_0c08ec82: /* original 4b0b, guest PC 0x0c08ec82 */
if(!s->budget--) { s->failed_pc=0x0c08ec82u; return 0; }
target=r[11];
r[16]=code_base|0x0c08ec86u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ec86u) { target=s->pc; goto dispatch; }
goto P_0c08ec86;
P_0c08ec84: /* original 0009, guest PC 0x0c08ec84 */
if(!s->budget--) { s->failed_pc=0x0c08ec84u; return 0; }
goto P_0c08ec86;
P_0c08ec86: /* original 4a0b, guest PC 0x0c08ec86 */
if(!s->budget--) { s->failed_pc=0x0c08ec86u; return 0; }
target=r[10];
r[16]=code_base|0x0c08ec8au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ec8au) { target=s->pc; goto dispatch; }
goto P_0c08ec8a;
P_0c08ec88: /* original 0009, guest PC 0x0c08ec88 */
if(!s->budget--) { s->failed_pc=0x0c08ec88u; return 0; }
goto P_0c08ec8a;
P_0c08ec8a: /* original d335, guest PC 0x0c08ec8a */
if(!s->budget--) { s->failed_pc=0x0c08ec8au; return 0; }
r[3]=read(ram,0x0c08ed60u,4);
goto P_0c08ec8c;
P_0c08ec8c: /* original 85ef, guest PC 0x0c08ec8c */
if(!s->budget--) { s->failed_pc=0x0c08ec8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c08ec8e;
P_0c08ec8e: /* original 430b, guest PC 0x0c08ec8e */
if(!s->budget--) { s->failed_pc=0x0c08ec8eu; return 0; }
target=r[3];
r[16]=code_base|0x0c08ec92u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ec92u) { target=s->pc; goto dispatch; }
goto P_0c08ec92;
P_0c08ec90: /* original 6403, guest PC 0x0c08ec90 */
if(!s->budget--) { s->failed_pc=0x0c08ec90u; return 0; }
r[4]=r[0];
goto P_0c08ec92;
P_0c08ec92: /* original d334, guest PC 0x0c08ec92 */
if(!s->budget--) { s->failed_pc=0x0c08ec92u; return 0; }
r[3]=read(ram,0x0c08ed64u,4);
goto P_0c08ec94;
P_0c08ec94: /* original 85ee, guest PC 0x0c08ec94 */
if(!s->budget--) { s->failed_pc=0x0c08ec94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+28,2);
goto P_0c08ec96;
P_0c08ec96: /* original 430b, guest PC 0x0c08ec96 */
if(!s->budget--) { s->failed_pc=0x0c08ec96u; return 0; }
target=r[3];
r[16]=code_base|0x0c08ec9au;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ec9au) { target=s->pc; goto dispatch; }
goto P_0c08ec9a;
P_0c08ec98: /* original 6403, guest PC 0x0c08ec98 */
if(!s->budget--) { s->failed_pc=0x0c08ec98u; return 0; }
r[4]=r[0];
goto P_0c08ec9a;
P_0c08ec9a: /* original f5ec, guest PC 0x0c08ec9a */
if(!s->budget--) { s->failed_pc=0x0c08ec9au; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c08ec9c;
P_0c08ec9c: /* original f6fc, guest PC 0x0c08ec9c */
if(!s->budget--) { s->failed_pc=0x0c08ec9cu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08ec9e;
P_0c08ec9e: /* original 4d0b, guest PC 0x0c08ec9e */
if(!s->budget--) { s->failed_pc=0x0c08ec9eu; return 0; }
target=r[13];
r[16]=code_base|0x0c08eca2u;
vf3_matrix_move(s,4,13);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08eca2u) { target=s->pc; goto dispatch; }
goto P_0c08eca2;
P_0c08eca0: /* original f4dc, guest PC 0x0c08eca0 */
if(!s->budget--) { s->failed_pc=0x0c08eca0u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c08eca2;
P_0c08eca2: /* original d330, guest PC 0x0c08eca2 */
if(!s->budget--) { s->failed_pc=0x0c08eca2u; return 0; }
r[3]=read(ram,0x0c08ed64u,4);
goto P_0c08eca4;
P_0c08eca4: /* original 85ee, guest PC 0x0c08eca4 */
if(!s->budget--) { s->failed_pc=0x0c08eca4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+28,2);
goto P_0c08eca6;
P_0c08eca6: /* original 430b, guest PC 0x0c08eca6 */
if(!s->budget--) { s->failed_pc=0x0c08eca6u; return 0; }
target=r[3];
r[16]=code_base|0x0c08ecaau;
r[4]=0u-r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ecaau) { target=s->pc; goto dispatch; }
goto P_0c08ecaa;
P_0c08eca8: /* original 640b, guest PC 0x0c08eca8 */
if(!s->budget--) { s->failed_pc=0x0c08eca8u; return 0; }
r[4]=0u-r[0];
goto P_0c08ecaa;
P_0c08ecaa: /* original d32d, guest PC 0x0c08ecaa */
if(!s->budget--) { s->failed_pc=0x0c08ecaau; return 0; }
r[3]=read(ram,0x0c08ed60u,4);
goto P_0c08ecac;
P_0c08ecac: /* original 85ef, guest PC 0x0c08ecac */
if(!s->budget--) { s->failed_pc=0x0c08ecacu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c08ecae;
P_0c08ecae: /* original 430b, guest PC 0x0c08ecae */
if(!s->budget--) { s->failed_pc=0x0c08ecaeu; return 0; }
target=r[3];
r[16]=code_base|0x0c08ecb2u;
r[4]=0u-r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ecb2u) { target=s->pc; goto dispatch; }
goto P_0c08ecb2;
P_0c08ecb0: /* original 640b, guest PC 0x0c08ecb0 */
if(!s->budget--) { s->failed_pc=0x0c08ecb0u; return 0; }
r[4]=0u-r[0];
goto P_0c08ecb2;
P_0c08ecb2: /* original 903e, guest PC 0x0c08ecb2 */
if(!s->budget--) { s->failed_pc=0x0c08ecb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ed32u,2);
goto P_0c08ecb4;
P_0c08ecb4: /* original f6e6, guest PC 0x0c08ecb4 */
if(!s->budget--) { s->failed_pc=0x0c08ecb4u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08ecb6;
P_0c08ecb6: /* original 70fc, guest PC 0x0c08ecb6 */
if(!s->budget--) { s->failed_pc=0x0c08ecb6u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08ecb8;
P_0c08ecb8: /* original f5e6, guest PC 0x0c08ecb8 */
if(!s->budget--) { s->failed_pc=0x0c08ecb8u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08ecba;
P_0c08ecba: /* original 70fc, guest PC 0x0c08ecba */
if(!s->budget--) { s->failed_pc=0x0c08ecbau; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08ecbc;
P_0c08ecbc: /* original f64d, guest PC 0x0c08ecbc */
if(!s->budget--) { s->failed_pc=0x0c08ecbcu; return 0; }
fr[6]^=0x80000000u;
goto P_0c08ecbe;
P_0c08ecbe: /* original 4d0b, guest PC 0x0c08ecbe */
if(!s->budget--) { s->failed_pc=0x0c08ecbeu; return 0; }
target=r[13];
r[16]=code_base|0x0c08ecc2u;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ecc2u) { target=s->pc; goto dispatch; }
goto P_0c08ecc2;
P_0c08ecc0: /* original f4e6, guest PC 0x0c08ecc0 */
if(!s->budget--) { s->failed_pc=0x0c08ecc0u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08ecc2;
P_0c08ecc2: /* original 9037, guest PC 0x0c08ecc2 */
if(!s->budget--) { s->failed_pc=0x0c08ecc2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ed34u,2);
goto P_0c08ecc4;
P_0c08ecc4: /* original fce6, guest PC 0x0c08ecc4 */
if(!s->budget--) { s->failed_pc=0x0c08ecc4u; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c08ecc6;
P_0c08ecc6: /* original f5cc, guest PC 0x0c08ecc6 */
if(!s->budget--) { s->failed_pc=0x0c08ecc6u; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c08ecc8;
P_0c08ecc8: /* original f6cc, guest PC 0x0c08ecc8 */
if(!s->budget--) { s->failed_pc=0x0c08ecc8u; return 0; }
vf3_matrix_move(s,6,12);
goto P_0c08ecca;
P_0c08ecca: /* original 4c0b, guest PC 0x0c08ecca */
if(!s->budget--) { s->failed_pc=0x0c08eccau; return 0; }
target=r[12];
r[16]=code_base|0x0c08ecceu;
vf3_matrix_move(s,4,12);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ecceu) { target=s->pc; goto dispatch; }
goto P_0c08ecce;
P_0c08eccc: /* original f4cc, guest PC 0x0c08eccc */
if(!s->budget--) { s->failed_pc=0x0c08ecccu; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c08ecce;
P_0c08ecce: /* original 9432, guest PC 0x0c08ecce */
if(!s->budget--) { s->failed_pc=0x0c08ecceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ed36u,2);
goto P_0c08ecd0;
P_0c08ecd0: /* original 4b0b, guest PC 0x0c08ecd0 */
if(!s->budget--) { s->failed_pc=0x0c08ecd0u; return 0; }
target=r[11];
r[16]=code_base|0x0c08ecd4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ecd4u) { target=s->pc; goto dispatch; }
goto P_0c08ecd4;
P_0c08ecd2: /* original 0009, guest PC 0x0c08ecd2 */
if(!s->budget--) { s->failed_pc=0x0c08ecd2u; return 0; }
goto P_0c08ecd4;
P_0c08ecd4: /* original 4a0b, guest PC 0x0c08ecd4 */
if(!s->budget--) { s->failed_pc=0x0c08ecd4u; return 0; }
target=r[10];
r[16]=code_base|0x0c08ecd8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ecd8u) { target=s->pc; goto dispatch; }
goto P_0c08ecd8;
P_0c08ecd6: /* original 0009, guest PC 0x0c08ecd6 */
if(!s->budget--) { s->failed_pc=0x0c08ecd6u; return 0; }
goto P_0c08ecd8;
P_0c08ecd8: /* original 902e, guest PC 0x0c08ecd8 */
if(!s->budget--) { s->failed_pc=0x0c08ecd8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ed38u,2);
goto P_0c08ecda;
P_0c08ecda: /* original f6e6, guest PC 0x0c08ecda */
if(!s->budget--) { s->failed_pc=0x0c08ecdau; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08ecdc;
P_0c08ecdc: /* original 70fc, guest PC 0x0c08ecdc */
if(!s->budget--) { s->failed_pc=0x0c08ecdcu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08ecde;
P_0c08ecde: /* original f5e6, guest PC 0x0c08ecde */
if(!s->budget--) { s->failed_pc=0x0c08ecdeu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08ece0;
P_0c08ece0: /* original 70fc, guest PC 0x0c08ece0 */
if(!s->budget--) { s->failed_pc=0x0c08ece0u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08ece2;
P_0c08ece2: /* original f64d, guest PC 0x0c08ece2 */
if(!s->budget--) { s->failed_pc=0x0c08ece2u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08ece4;
P_0c08ece4: /* original 4d0b, guest PC 0x0c08ece4 */
if(!s->budget--) { s->failed_pc=0x0c08ece4u; return 0; }
target=r[13];
r[16]=code_base|0x0c08ece8u;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ece8u) { target=s->pc; goto dispatch; }
goto P_0c08ece8;
P_0c08ece6: /* original f4e6, guest PC 0x0c08ece6 */
if(!s->budget--) { s->failed_pc=0x0c08ece6u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08ece8;
P_0c08ece8: /* original 9027, guest PC 0x0c08ece8 */
if(!s->budget--) { s->failed_pc=0x0c08ece8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ed3au,2);
goto P_0c08ecea;
P_0c08ecea: /* original fce6, guest PC 0x0c08ecea */
if(!s->budget--) { s->failed_pc=0x0c08eceau; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c08ecec;
P_0c08ecec: /* original f5cc, guest PC 0x0c08ecec */
if(!s->budget--) { s->failed_pc=0x0c08ececu; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c08ecee;
P_0c08ecee: /* original f6cc, guest PC 0x0c08ecee */
if(!s->budget--) { s->failed_pc=0x0c08eceeu; return 0; }
vf3_matrix_move(s,6,12);
goto P_0c08ecf0;
P_0c08ecf0: /* original 4c0b, guest PC 0x0c08ecf0 */
if(!s->budget--) { s->failed_pc=0x0c08ecf0u; return 0; }
target=r[12];
r[16]=code_base|0x0c08ecf4u;
vf3_matrix_move(s,4,12);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ecf4u) { target=s->pc; goto dispatch; }
goto P_0c08ecf4;
P_0c08ecf2: /* original f4cc, guest PC 0x0c08ecf2 */
if(!s->budget--) { s->failed_pc=0x0c08ecf2u; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c08ecf4;
P_0c08ecf4: /* original 9422, guest PC 0x0c08ecf4 */
if(!s->budget--) { s->failed_pc=0x0c08ecf4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ed3cu,2);
goto P_0c08ecf6;
P_0c08ecf6: /* original 4b0b, guest PC 0x0c08ecf6 */
if(!s->budget--) { s->failed_pc=0x0c08ecf6u; return 0; }
target=r[11];
r[16]=code_base|0x0c08ecfau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ecfau) { target=s->pc; goto dispatch; }
goto P_0c08ecfa;
P_0c08ecf8: /* original 0009, guest PC 0x0c08ecf8 */
if(!s->budget--) { s->failed_pc=0x0c08ecf8u; return 0; }
goto P_0c08ecfa;
P_0c08ecfa: /* original d31b, guest PC 0x0c08ecfa */
if(!s->budget--) { s->failed_pc=0x0c08ecfau; return 0; }
r[3]=read(ram,0x0c08ed68u,4);
goto P_0c08ecfc;
P_0c08ecfc: /* original 430b, guest PC 0x0c08ecfc */
if(!s->budget--) { s->failed_pc=0x0c08ecfcu; return 0; }
target=r[3];
r[16]=code_base|0x0c08ed00u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ed00u) { target=s->pc; goto dispatch; }
goto P_0c08ed00;
P_0c08ecfe: /* original e401, guest PC 0x0c08ecfe */
if(!s->budget--) { s->failed_pc=0x0c08ecfeu; return 0; }
r[4]=0x00000001u;
goto P_0c08ed00;
P_0c08ed00: /* original 4f26, guest PC 0x0c08ed00 */
if(!s->budget--) { s->failed_pc=0x0c08ed00u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08ed02;
P_0c08ed02: /* original f4dc, guest PC 0x0c08ed02 */
if(!s->budget--) { s->failed_pc=0x0c08ed02u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c08ed04;
P_0c08ed04: /* original 64e3, guest PC 0x0c08ed04 */
if(!s->budget--) { s->failed_pc=0x0c08ed04u; return 0; }
r[4]=r[14];
goto P_0c08ed06;
P_0c08ed06: /* original f5ec, guest PC 0x0c08ed06 */
if(!s->budget--) { s->failed_pc=0x0c08ed06u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c08ed08;
P_0c08ed08: /* original fcf9, guest PC 0x0c08ed08 */
if(!s->budget--) { s->failed_pc=0x0c08ed08u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08ed0a;
P_0c08ed0a: /* original f6fc, guest PC 0x0c08ed0a */
if(!s->budget--) { s->failed_pc=0x0c08ed0au; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08ed0c;
P_0c08ed0c: /* original fdf9, guest PC 0x0c08ed0c */
if(!s->budget--) { s->failed_pc=0x0c08ed0cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08ed0e;
P_0c08ed0e: /* original d217, guest PC 0x0c08ed0e */
if(!s->budget--) { s->failed_pc=0x0c08ed0eu; return 0; }
r[2]=read(ram,0x0c08ed6cu,4);
goto P_0c08ed10;
P_0c08ed10: /* original fef9, guest PC 0x0c08ed10 */
if(!s->budget--) { s->failed_pc=0x0c08ed10u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08ed12;
P_0c08ed12: /* original 6522, guest PC 0x0c08ed12 */
if(!s->budget--) { s->failed_pc=0x0c08ed12u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c08ed14;
P_0c08ed14: /* original fff9, guest PC 0x0c08ed14 */
if(!s->budget--) { s->failed_pc=0x0c08ed14u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08ed16;
P_0c08ed16: /* original 6af6, guest PC 0x0c08ed16 */
if(!s->budget--) { s->failed_pc=0x0c08ed16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08ed18;
P_0c08ed18: /* original 6bf6, guest PC 0x0c08ed18 */
if(!s->budget--) { s->failed_pc=0x0c08ed18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08ed1a;
P_0c08ed1a: /* original 6cf6, guest PC 0x0c08ed1a */
if(!s->budget--) { s->failed_pc=0x0c08ed1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08ed1c;
P_0c08ed1c: /* original 6df6, guest PC 0x0c08ed1c */
if(!s->budget--) { s->failed_pc=0x0c08ed1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08ed1e;
P_0c08ed1e: /* original a032, guest PC 0x0c08ed1e */
if(!s->budget--) { s->failed_pc=0x0c08ed1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08ed86;
P_0c08ed20: /* original 6ef6, guest PC 0x0c08ed20 */
if(!s->budget--) { s->failed_pc=0x0c08ed20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08ed22u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08ed22u; return 0; } return 1;
P_0c08ed70: /* original 4f26, guest PC 0x0c08ed70 */
if(!s->budget--) { s->failed_pc=0x0c08ed70u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08ed72;
P_0c08ed72: /* original fcf9, guest PC 0x0c08ed72 */
if(!s->budget--) { s->failed_pc=0x0c08ed72u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08ed74;
P_0c08ed74: /* original fdf9, guest PC 0x0c08ed74 */
if(!s->budget--) { s->failed_pc=0x0c08ed74u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08ed76;
P_0c08ed76: /* original fef9, guest PC 0x0c08ed76 */
if(!s->budget--) { s->failed_pc=0x0c08ed76u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08ed78;
P_0c08ed78: /* original fff9, guest PC 0x0c08ed78 */
if(!s->budget--) { s->failed_pc=0x0c08ed78u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08ed7a;
P_0c08ed7a: /* original 6af6, guest PC 0x0c08ed7a */
if(!s->budget--) { s->failed_pc=0x0c08ed7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08ed7c;
P_0c08ed7c: /* original 6bf6, guest PC 0x0c08ed7c */
if(!s->budget--) { s->failed_pc=0x0c08ed7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08ed7e;
P_0c08ed7e: /* original 6cf6, guest PC 0x0c08ed7e */
if(!s->budget--) { s->failed_pc=0x0c08ed7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08ed80;
P_0c08ed80: /* original 6df6, guest PC 0x0c08ed80 */
if(!s->budget--) { s->failed_pc=0x0c08ed80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08ed82;
P_0c08ed82: /* original 000b, guest PC 0x0c08ed82 */
if(!s->budget--) { s->failed_pc=0x0c08ed82u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08ed84: /* original 6ef6, guest PC 0x0c08ed84 */
if(!s->budget--) { s->failed_pc=0x0c08ed84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08ed86;
P_0c08ed86: /* original 2fe6, guest PC 0x0c08ed86 */
if(!s->budget--) { s->failed_pc=0x0c08ed86u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ed88;
P_0c08ed88: /* original e00c, guest PC 0x0c08ed88 */
if(!s->budget--) { s->failed_pc=0x0c08ed88u; return 0; }
r[0]=0x0000000cu;
goto P_0c08ed8a;
P_0c08ed8a: /* original 2fd6, guest PC 0x0c08ed8a */
if(!s->budget--) { s->failed_pc=0x0c08ed8au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ed8c;
P_0c08ed8c: /* original 6e43, guest PC 0x0c08ed8c */
if(!s->budget--) { s->failed_pc=0x0c08ed8cu; return 0; }
r[14]=r[4];
goto P_0c08ed8e;
P_0c08ed8e: /* original 2fc6, guest PC 0x0c08ed8e */
if(!s->budget--) { s->failed_pc=0x0c08ed8eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ed90;
P_0c08ed90: /* original 2fb6, guest PC 0x0c08ed90 */
if(!s->budget--) { s->failed_pc=0x0c08ed90u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ed92;
P_0c08ed92: /* original 2fa6, guest PC 0x0c08ed92 */
if(!s->budget--) { s->failed_pc=0x0c08ed92u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ed94;
P_0c08ed94: /* original 2f96, guest PC 0x0c08ed94 */
if(!s->budget--) { s->failed_pc=0x0c08ed94u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ed96;
P_0c08ed96: /* original fffb, guest PC 0x0c08ed96 */
if(!s->budget--) { s->failed_pc=0x0c08ed96u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08ed98;
P_0c08ed98: /* original ffeb, guest PC 0x0c08ed98 */
if(!s->budget--) { s->failed_pc=0x0c08ed98u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c08ed9a;
P_0c08ed9a: /* original 4f22, guest PC 0x0c08ed9a */
if(!s->budget--) { s->failed_pc=0x0c08ed9au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08ed9c;
P_0c08ed9c: /* original 7fe4, guest PC 0x0c08ed9c */
if(!s->budget--) { s->failed_pc=0x0c08ed9cu; return 0; }
r[15]+=0xffffffe4u;
goto P_0c08ed9e;
P_0c08ed9e: /* original ff47, guest PC 0x0c08ed9e */
if(!s->budget--) { s->failed_pc=0x0c08ed9eu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c08eda0;
P_0c08eda0: /* original e008, guest PC 0x0c08eda0 */
if(!s->budget--) { s->failed_pc=0x0c08eda0u; return 0; }
r[0]=0x00000008u;
goto P_0c08eda2;
P_0c08eda2: /* original ff57, guest PC 0x0c08eda2 */
if(!s->budget--) { s->failed_pc=0x0c08eda2u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c08eda4;
P_0c08eda4: /* original e004, guest PC 0x0c08eda4 */
if(!s->budget--) { s->failed_pc=0x0c08eda4u; return 0; }
r[0]=0x00000004u;
goto P_0c08eda6;
P_0c08eda6: /* original ff67, guest PC 0x0c08eda6 */
if(!s->budget--) { s->failed_pc=0x0c08eda6u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c08eda8;
P_0c08eda8: /* original c75e, guest PC 0x0c08eda8 */
if(!s->budget--) { s->failed_pc=0x0c08eda8u; return 0; }
r[0]=code_base|0x0008ef24u;
goto P_0c08edaa;
P_0c08edaa: /* original d35f, guest PC 0x0c08edaa */
if(!s->budget--) { s->failed_pc=0x0c08edaau; return 0; }
r[3]=read(ram,0x0c08ef28u,4);
goto P_0c08edac;
P_0c08edac: /* original ff08, guest PC 0x0c08edac */
if(!s->budget--) { s->failed_pc=0x0c08edacu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08edae;
P_0c08edae: /* original 430b, guest PC 0x0c08edae */
if(!s->budget--) { s->failed_pc=0x0c08edaeu; return 0; }
target=r[3];
r[16]=code_base|0x0c08edb2u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08edb2u) { target=s->pc; goto dispatch; }
goto P_0c08edb2;
P_0c08edb0: /* original e400, guest PC 0x0c08edb0 */
if(!s->budget--) { s->failed_pc=0x0c08edb0u; return 0; }
r[4]=0x00000000u;
goto P_0c08edb2;
P_0c08edb2: /* original db5e, guest PC 0x0c08edb2 */
if(!s->budget--) { s->failed_pc=0x0c08edb2u; return 0; }
r[11]=read(ram,0x0c08ef2cu,4);
goto P_0c08edb4;
P_0c08edb4: /* original 4b0b, guest PC 0x0c08edb4 */
if(!s->budget--) { s->failed_pc=0x0c08edb4u; return 0; }
target=r[11];
r[16]=code_base|0x0c08edb8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08edb8u) { target=s->pc; goto dispatch; }
goto P_0c08edb8;
P_0c08edb6: /* original 0009, guest PC 0x0c08edb6 */
if(!s->budget--) { s->failed_pc=0x0c08edb6u; return 0; }
goto P_0c08edb8;
P_0c08edb8: /* original 90a7, guest PC 0x0c08edb8 */
if(!s->budget--) { s->failed_pc=0x0c08edb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef0au,2);
goto P_0c08edba;
P_0c08edba: /* original f4e6, guest PC 0x0c08edba */
if(!s->budget--) { s->failed_pc=0x0c08edbau; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08edbc;
P_0c08edbc: /* original 7004, guest PC 0x0c08edbc */
if(!s->budget--) { s->failed_pc=0x0c08edbcu; return 0; }
r[0]+=0x00000004u;
goto P_0c08edbe;
P_0c08edbe: /* original f3e6, guest PC 0x0c08edbe */
if(!s->budget--) { s->failed_pc=0x0c08edbeu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08edc0;
P_0c08edc0: /* original ff3a, guest PC 0x0c08edc0 */
if(!s->budget--) { s->failed_pc=0x0c08edc0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08edc2;
P_0c08edc2: /* original 90a3, guest PC 0x0c08edc2 */
if(!s->budget--) { s->failed_pc=0x0c08edc2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef0cu,2);
goto P_0c08edc4;
P_0c08edc4: /* original f3e6, guest PC 0x0c08edc4 */
if(!s->budget--) { s->failed_pc=0x0c08edc4u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08edc6;
P_0c08edc6: /* original e010, guest PC 0x0c08edc6 */
if(!s->budget--) { s->failed_pc=0x0c08edc6u; return 0; }
r[0]=0x00000010u;
goto P_0c08edc8;
P_0c08edc8: /* original ff37, guest PC 0x0c08edc8 */
if(!s->budget--) { s->failed_pc=0x0c08edc8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08edca;
P_0c08edca: /* original dd59, guest PC 0x0c08edca */
if(!s->budget--) { s->failed_pc=0x0c08edcau; return 0; }
r[13]=read(ram,0x0c08ef30u,4);
goto P_0c08edcc;
P_0c08edcc: /* original f63c, guest PC 0x0c08edcc */
if(!s->budget--) { s->failed_pc=0x0c08edccu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08edce;
P_0c08edce: /* original f64d, guest PC 0x0c08edce */
if(!s->budget--) { s->failed_pc=0x0c08edceu; return 0; }
fr[6]^=0x80000000u;
goto P_0c08edd0;
P_0c08edd0: /* original 4d0b, guest PC 0x0c08edd0 */
if(!s->budget--) { s->failed_pc=0x0c08edd0u; return 0; }
target=r[13];
r[16]=code_base|0x0c08edd4u;
vf3_matrix_load(s,ram,5,r[15]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08edd4u) { target=s->pc; goto dispatch; }
goto P_0c08edd4;
P_0c08edd2: /* original f5f8, guest PC 0x0c08edd2 */
if(!s->budget--) { s->failed_pc=0x0c08edd2u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c08edd4;
P_0c08edd4: /* original 909b, guest PC 0x0c08edd4 */
if(!s->budget--) { s->failed_pc=0x0c08edd4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef0eu,2);
goto P_0c08edd6;
P_0c08edd6: /* original dc57, guest PC 0x0c08edd6 */
if(!s->budget--) { s->failed_pc=0x0c08edd6u; return 0; }
r[12]=read(ram,0x0c08ef34u,4);
goto P_0c08edd8;
P_0c08edd8: /* original f6e6, guest PC 0x0c08edd8 */
if(!s->budget--) { s->failed_pc=0x0c08edd8u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08edda;
P_0c08edda: /* original 70fc, guest PC 0x0c08edda */
if(!s->budget--) { s->failed_pc=0x0c08eddau; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08eddc;
P_0c08eddc: /* original f5e6, guest PC 0x0c08eddc */
if(!s->budget--) { s->failed_pc=0x0c08eddcu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08edde;
P_0c08edde: /* original 70fc, guest PC 0x0c08edde */
if(!s->budget--) { s->failed_pc=0x0c08eddeu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08ede0;
P_0c08ede0: /* original f4e6, guest PC 0x0c08ede0 */
if(!s->budget--) { s->failed_pc=0x0c08ede0u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08ede2;
P_0c08ede2: /* original 4c0b, guest PC 0x0c08ede2 */
if(!s->budget--) { s->failed_pc=0x0c08ede2u; return 0; }
target=r[12];
r[16]=code_base|0x0c08ede6u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ede6u) { target=s->pc; goto dispatch; }
goto P_0c08ede6;
P_0c08ede4: /* original 64f3, guest PC 0x0c08ede4 */
if(!s->budget--) { s->failed_pc=0x0c08ede4u; return 0; }
r[4]=r[15];
goto P_0c08ede6;
P_0c08ede6: /* original fe0c, guest PC 0x0c08ede6 */
if(!s->budget--) { s->failed_pc=0x0c08ede6u; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c08ede8;
P_0c08ede8: /* original fef2, guest PC 0x0c08ede8 */
if(!s->budget--) { s->failed_pc=0x0c08ede8u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'*');
goto P_0c08edea;
P_0c08edea: /* original da53, guest PC 0x0c08edea */
if(!s->budget--) { s->failed_pc=0x0c08edeau; return 0; }
r[10]=read(ram,0x0c08ef38u,4);
goto P_0c08edec;
P_0c08edec: /* original f5ec, guest PC 0x0c08edec */
if(!s->budget--) { s->failed_pc=0x0c08edecu; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c08edee;
P_0c08edee: /* original f6ec, guest PC 0x0c08edee */
if(!s->budget--) { s->failed_pc=0x0c08edeeu; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c08edf0;
P_0c08edf0: /* original 4a0b, guest PC 0x0c08edf0 */
if(!s->budget--) { s->failed_pc=0x0c08edf0u; return 0; }
target=r[10];
r[16]=code_base|0x0c08edf4u;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08edf4u) { target=s->pc; goto dispatch; }
goto P_0c08edf4;
P_0c08edf2: /* original f4ec, guest PC 0x0c08edf2 */
if(!s->budget--) { s->failed_pc=0x0c08edf2u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c08edf4;
P_0c08edf4: /* original 4b0b, guest PC 0x0c08edf4 */
if(!s->budget--) { s->failed_pc=0x0c08edf4u; return 0; }
target=r[11];
r[16]=code_base|0x0c08edf8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08edf8u) { target=s->pc; goto dispatch; }
goto P_0c08edf8;
P_0c08edf6: /* original 0009, guest PC 0x0c08edf6 */
if(!s->budget--) { s->failed_pc=0x0c08edf6u; return 0; }
goto P_0c08edf8;
P_0c08edf8: /* original 908a, guest PC 0x0c08edf8 */
if(!s->budget--) { s->failed_pc=0x0c08edf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef10u,2);
goto P_0c08edfa;
P_0c08edfa: /* original f4e6, guest PC 0x0c08edfa */
if(!s->budget--) { s->failed_pc=0x0c08edfau; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08edfc;
P_0c08edfc: /* original 7004, guest PC 0x0c08edfc */
if(!s->budget--) { s->failed_pc=0x0c08edfcu; return 0; }
r[0]+=0x00000004u;
goto P_0c08edfe;
P_0c08edfe: /* original f3e6, guest PC 0x0c08edfe */
if(!s->budget--) { s->failed_pc=0x0c08edfeu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08ee00;
P_0c08ee00: /* original ff3a, guest PC 0x0c08ee00 */
if(!s->budget--) { s->failed_pc=0x0c08ee00u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08ee02;
P_0c08ee02: /* original 9086, guest PC 0x0c08ee02 */
if(!s->budget--) { s->failed_pc=0x0c08ee02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef12u,2);
goto P_0c08ee04;
P_0c08ee04: /* original f3e6, guest PC 0x0c08ee04 */
if(!s->budget--) { s->failed_pc=0x0c08ee04u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08ee06;
P_0c08ee06: /* original e014, guest PC 0x0c08ee06 */
if(!s->budget--) { s->failed_pc=0x0c08ee06u; return 0; }
r[0]=0x00000014u;
goto P_0c08ee08;
P_0c08ee08: /* original ff37, guest PC 0x0c08ee08 */
if(!s->budget--) { s->failed_pc=0x0c08ee08u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08ee0a;
P_0c08ee0a: /* original f63c, guest PC 0x0c08ee0a */
if(!s->budget--) { s->failed_pc=0x0c08ee0au; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08ee0c;
P_0c08ee0c: /* original f64d, guest PC 0x0c08ee0c */
if(!s->budget--) { s->failed_pc=0x0c08ee0cu; return 0; }
fr[6]^=0x80000000u;
goto P_0c08ee0e;
P_0c08ee0e: /* original 4d0b, guest PC 0x0c08ee0e */
if(!s->budget--) { s->failed_pc=0x0c08ee0eu; return 0; }
target=r[13];
r[16]=code_base|0x0c08ee12u;
vf3_matrix_load(s,ram,5,r[15]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ee12u) { target=s->pc; goto dispatch; }
goto P_0c08ee12;
P_0c08ee10: /* original f5f8, guest PC 0x0c08ee10 */
if(!s->budget--) { s->failed_pc=0x0c08ee10u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c08ee12;
P_0c08ee12: /* original 907f, guest PC 0x0c08ee12 */
if(!s->budget--) { s->failed_pc=0x0c08ee12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef14u,2);
goto P_0c08ee14;
P_0c08ee14: /* original f6e6, guest PC 0x0c08ee14 */
if(!s->budget--) { s->failed_pc=0x0c08ee14u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08ee16;
P_0c08ee16: /* original 70fc, guest PC 0x0c08ee16 */
if(!s->budget--) { s->failed_pc=0x0c08ee16u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08ee18;
P_0c08ee18: /* original f5e6, guest PC 0x0c08ee18 */
if(!s->budget--) { s->failed_pc=0x0c08ee18u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08ee1a;
P_0c08ee1a: /* original 70fc, guest PC 0x0c08ee1a */
if(!s->budget--) { s->failed_pc=0x0c08ee1au; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08ee1c;
P_0c08ee1c: /* original f4e6, guest PC 0x0c08ee1c */
if(!s->budget--) { s->failed_pc=0x0c08ee1cu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08ee1e;
P_0c08ee1e: /* original 4c0b, guest PC 0x0c08ee1e */
if(!s->budget--) { s->failed_pc=0x0c08ee1eu; return 0; }
target=r[12];
r[16]=code_base|0x0c08ee22u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ee22u) { target=s->pc; goto dispatch; }
goto P_0c08ee22;
P_0c08ee20: /* original 64f3, guest PC 0x0c08ee20 */
if(!s->budget--) { s->failed_pc=0x0c08ee20u; return 0; }
r[4]=r[15];
goto P_0c08ee22;
P_0c08ee22: /* original fe0c, guest PC 0x0c08ee22 */
if(!s->budget--) { s->failed_pc=0x0c08ee22u; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c08ee24;
P_0c08ee24: /* original fef2, guest PC 0x0c08ee24 */
if(!s->budget--) { s->failed_pc=0x0c08ee24u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'*');
goto P_0c08ee26;
P_0c08ee26: /* original f5ec, guest PC 0x0c08ee26 */
if(!s->budget--) { s->failed_pc=0x0c08ee26u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c08ee28;
P_0c08ee28: /* original f6ec, guest PC 0x0c08ee28 */
if(!s->budget--) { s->failed_pc=0x0c08ee28u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c08ee2a;
P_0c08ee2a: /* original 4a0b, guest PC 0x0c08ee2a */
if(!s->budget--) { s->failed_pc=0x0c08ee2au; return 0; }
target=r[10];
r[16]=code_base|0x0c08ee2eu;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ee2eu) { target=s->pc; goto dispatch; }
goto P_0c08ee2e;
P_0c08ee2c: /* original f4ec, guest PC 0x0c08ee2c */
if(!s->budget--) { s->failed_pc=0x0c08ee2cu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c08ee2e;
P_0c08ee2e: /* original 9472, guest PC 0x0c08ee2e */
if(!s->budget--) { s->failed_pc=0x0c08ee2eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef16u,2);
goto P_0c08ee30;
P_0c08ee30: /* original d942, guest PC 0x0c08ee30 */
if(!s->budget--) { s->failed_pc=0x0c08ee30u; return 0; }
r[9]=read(ram,0x0c08ef3cu,4);
goto P_0c08ee32;
P_0c08ee32: /* original 490b, guest PC 0x0c08ee32 */
if(!s->budget--) { s->failed_pc=0x0c08ee32u; return 0; }
target=r[9];
r[16]=code_base|0x0c08ee36u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ee36u) { target=s->pc; goto dispatch; }
goto P_0c08ee36;
P_0c08ee34: /* original 0009, guest PC 0x0c08ee34 */
if(!s->budget--) { s->failed_pc=0x0c08ee34u; return 0; }
goto P_0c08ee36;
P_0c08ee36: /* original 4b0b, guest PC 0x0c08ee36 */
if(!s->budget--) { s->failed_pc=0x0c08ee36u; return 0; }
target=r[11];
r[16]=code_base|0x0c08ee3au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ee3au) { target=s->pc; goto dispatch; }
goto P_0c08ee3a;
P_0c08ee38: /* original 0009, guest PC 0x0c08ee38 */
if(!s->budget--) { s->failed_pc=0x0c08ee38u; return 0; }
goto P_0c08ee3a;
P_0c08ee3a: /* original d341, guest PC 0x0c08ee3a */
if(!s->budget--) { s->failed_pc=0x0c08ee3au; return 0; }
r[3]=read(ram,0x0c08ef40u,4);
goto P_0c08ee3c;
P_0c08ee3c: /* original 85ef, guest PC 0x0c08ee3c */
if(!s->budget--) { s->failed_pc=0x0c08ee3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c08ee3e;
P_0c08ee3e: /* original 430b, guest PC 0x0c08ee3e */
if(!s->budget--) { s->failed_pc=0x0c08ee3eu; return 0; }
target=r[3];
r[16]=code_base|0x0c08ee42u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ee42u) { target=s->pc; goto dispatch; }
goto P_0c08ee42;
P_0c08ee40: /* original 6403, guest PC 0x0c08ee40 */
if(!s->budget--) { s->failed_pc=0x0c08ee40u; return 0; }
r[4]=r[0];
goto P_0c08ee42;
P_0c08ee42: /* original d340, guest PC 0x0c08ee42 */
if(!s->budget--) { s->failed_pc=0x0c08ee42u; return 0; }
r[3]=read(ram,0x0c08ef44u,4);
goto P_0c08ee44;
P_0c08ee44: /* original 85ee, guest PC 0x0c08ee44 */
if(!s->budget--) { s->failed_pc=0x0c08ee44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+28,2);
goto P_0c08ee46;
P_0c08ee46: /* original 430b, guest PC 0x0c08ee46 */
if(!s->budget--) { s->failed_pc=0x0c08ee46u; return 0; }
target=r[3];
r[16]=code_base|0x0c08ee4au;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ee4au) { target=s->pc; goto dispatch; }
goto P_0c08ee4a;
P_0c08ee48: /* original 6403, guest PC 0x0c08ee48 */
if(!s->budget--) { s->failed_pc=0x0c08ee48u; return 0; }
r[4]=r[0];
goto P_0c08ee4a;
P_0c08ee4a: /* original e00c, guest PC 0x0c08ee4a */
if(!s->budget--) { s->failed_pc=0x0c08ee4au; return 0; }
r[0]=0x0000000cu;
goto P_0c08ee4c;
P_0c08ee4c: /* original f4f6, guest PC 0x0c08ee4c */
if(!s->budget--) { s->failed_pc=0x0c08ee4cu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08ee4e;
P_0c08ee4e: /* original e008, guest PC 0x0c08ee4e */
if(!s->budget--) { s->failed_pc=0x0c08ee4eu; return 0; }
r[0]=0x00000008u;
goto P_0c08ee50;
P_0c08ee50: /* original f3f6, guest PC 0x0c08ee50 */
if(!s->budget--) { s->failed_pc=0x0c08ee50u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08ee52;
P_0c08ee52: /* original e004, guest PC 0x0c08ee52 */
if(!s->budget--) { s->failed_pc=0x0c08ee52u; return 0; }
r[0]=0x00000004u;
goto P_0c08ee54;
P_0c08ee54: /* original ff3a, guest PC 0x0c08ee54 */
if(!s->budget--) { s->failed_pc=0x0c08ee54u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08ee56;
P_0c08ee56: /* original f3f6, guest PC 0x0c08ee56 */
if(!s->budget--) { s->failed_pc=0x0c08ee56u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08ee58;
P_0c08ee58: /* original e018, guest PC 0x0c08ee58 */
if(!s->budget--) { s->failed_pc=0x0c08ee58u; return 0; }
r[0]=0x00000018u;
goto P_0c08ee5a;
P_0c08ee5a: /* original ff37, guest PC 0x0c08ee5a */
if(!s->budget--) { s->failed_pc=0x0c08ee5au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08ee5c;
P_0c08ee5c: /* original f63c, guest PC 0x0c08ee5c */
if(!s->budget--) { s->failed_pc=0x0c08ee5cu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08ee5e;
P_0c08ee5e: /* original f64d, guest PC 0x0c08ee5e */
if(!s->budget--) { s->failed_pc=0x0c08ee5eu; return 0; }
fr[6]^=0x80000000u;
goto P_0c08ee60;
P_0c08ee60: /* original 4d0b, guest PC 0x0c08ee60 */
if(!s->budget--) { s->failed_pc=0x0c08ee60u; return 0; }
target=r[13];
r[16]=code_base|0x0c08ee64u;
vf3_matrix_load(s,ram,5,r[15]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ee64u) { target=s->pc; goto dispatch; }
goto P_0c08ee64;
P_0c08ee62: /* original f5f8, guest PC 0x0c08ee62 */
if(!s->budget--) { s->failed_pc=0x0c08ee62u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c08ee64;
P_0c08ee64: /* original d337, guest PC 0x0c08ee64 */
if(!s->budget--) { s->failed_pc=0x0c08ee64u; return 0; }
r[3]=read(ram,0x0c08ef44u,4);
goto P_0c08ee66;
P_0c08ee66: /* original 85ee, guest PC 0x0c08ee66 */
if(!s->budget--) { s->failed_pc=0x0c08ee66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+28,2);
goto P_0c08ee68;
P_0c08ee68: /* original 430b, guest PC 0x0c08ee68 */
if(!s->budget--) { s->failed_pc=0x0c08ee68u; return 0; }
target=r[3];
r[16]=code_base|0x0c08ee6cu;
r[4]=0u-r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ee6cu) { target=s->pc; goto dispatch; }
goto P_0c08ee6c;
P_0c08ee6a: /* original 640b, guest PC 0x0c08ee6a */
if(!s->budget--) { s->failed_pc=0x0c08ee6au; return 0; }
r[4]=0u-r[0];
goto P_0c08ee6c;
P_0c08ee6c: /* original d334, guest PC 0x0c08ee6c */
if(!s->budget--) { s->failed_pc=0x0c08ee6cu; return 0; }
r[3]=read(ram,0x0c08ef40u,4);
goto P_0c08ee6e;
P_0c08ee6e: /* original 85ef, guest PC 0x0c08ee6e */
if(!s->budget--) { s->failed_pc=0x0c08ee6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c08ee70;
P_0c08ee70: /* original 430b, guest PC 0x0c08ee70 */
if(!s->budget--) { s->failed_pc=0x0c08ee70u; return 0; }
target=r[3];
r[16]=code_base|0x0c08ee74u;
r[4]=0u-r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ee74u) { target=s->pc; goto dispatch; }
goto P_0c08ee74;
P_0c08ee72: /* original 640b, guest PC 0x0c08ee72 */
if(!s->budget--) { s->failed_pc=0x0c08ee72u; return 0; }
r[4]=0u-r[0];
goto P_0c08ee74;
P_0c08ee74: /* original 9050, guest PC 0x0c08ee74 */
if(!s->budget--) { s->failed_pc=0x0c08ee74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef18u,2);
goto P_0c08ee76;
P_0c08ee76: /* original f6e6, guest PC 0x0c08ee76 */
if(!s->budget--) { s->failed_pc=0x0c08ee76u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08ee78;
P_0c08ee78: /* original 70fc, guest PC 0x0c08ee78 */
if(!s->budget--) { s->failed_pc=0x0c08ee78u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08ee7a;
P_0c08ee7a: /* original f5e6, guest PC 0x0c08ee7a */
if(!s->budget--) { s->failed_pc=0x0c08ee7au; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08ee7c;
P_0c08ee7c: /* original 70fc, guest PC 0x0c08ee7c */
if(!s->budget--) { s->failed_pc=0x0c08ee7cu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08ee7e;
P_0c08ee7e: /* original f64d, guest PC 0x0c08ee7e */
if(!s->budget--) { s->failed_pc=0x0c08ee7eu; return 0; }
fr[6]^=0x80000000u;
goto P_0c08ee80;
P_0c08ee80: /* original 4d0b, guest PC 0x0c08ee80 */
if(!s->budget--) { s->failed_pc=0x0c08ee80u; return 0; }
target=r[13];
r[16]=code_base|0x0c08ee84u;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ee84u) { target=s->pc; goto dispatch; }
goto P_0c08ee84;
P_0c08ee82: /* original f4e6, guest PC 0x0c08ee82 */
if(!s->budget--) { s->failed_pc=0x0c08ee82u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08ee84;
P_0c08ee84: /* original 9049, guest PC 0x0c08ee84 */
if(!s->budget--) { s->failed_pc=0x0c08ee84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef1au,2);
goto P_0c08ee86;
P_0c08ee86: /* original f6e6, guest PC 0x0c08ee86 */
if(!s->budget--) { s->failed_pc=0x0c08ee86u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08ee88;
P_0c08ee88: /* original 70fc, guest PC 0x0c08ee88 */
if(!s->budget--) { s->failed_pc=0x0c08ee88u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08ee8a;
P_0c08ee8a: /* original f5e6, guest PC 0x0c08ee8a */
if(!s->budget--) { s->failed_pc=0x0c08ee8au; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08ee8c;
P_0c08ee8c: /* original 70fc, guest PC 0x0c08ee8c */
if(!s->budget--) { s->failed_pc=0x0c08ee8cu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08ee8e;
P_0c08ee8e: /* original f4e6, guest PC 0x0c08ee8e */
if(!s->budget--) { s->failed_pc=0x0c08ee8eu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08ee90;
P_0c08ee90: /* original 4c0b, guest PC 0x0c08ee90 */
if(!s->budget--) { s->failed_pc=0x0c08ee90u; return 0; }
target=r[12];
r[16]=code_base|0x0c08ee94u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ee94u) { target=s->pc; goto dispatch; }
goto P_0c08ee94;
P_0c08ee92: /* original 64f3, guest PC 0x0c08ee92 */
if(!s->budget--) { s->failed_pc=0x0c08ee92u; return 0; }
r[4]=r[15];
goto P_0c08ee94;
P_0c08ee94: /* original fe0c, guest PC 0x0c08ee94 */
if(!s->budget--) { s->failed_pc=0x0c08ee94u; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c08ee96;
P_0c08ee96: /* original fef2, guest PC 0x0c08ee96 */
if(!s->budget--) { s->failed_pc=0x0c08ee96u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'*');
goto P_0c08ee98;
P_0c08ee98: /* original f5ec, guest PC 0x0c08ee98 */
if(!s->budget--) { s->failed_pc=0x0c08ee98u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c08ee9a;
P_0c08ee9a: /* original f6ec, guest PC 0x0c08ee9a */
if(!s->budget--) { s->failed_pc=0x0c08ee9au; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c08ee9c;
P_0c08ee9c: /* original 4a0b, guest PC 0x0c08ee9c */
if(!s->budget--) { s->failed_pc=0x0c08ee9cu; return 0; }
target=r[10];
r[16]=code_base|0x0c08eea0u;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08eea0u) { target=s->pc; goto dispatch; }
goto P_0c08eea0;
P_0c08ee9e: /* original f4ec, guest PC 0x0c08ee9e */
if(!s->budget--) { s->failed_pc=0x0c08ee9eu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c08eea0;
P_0c08eea0: /* original 943c, guest PC 0x0c08eea0 */
if(!s->budget--) { s->failed_pc=0x0c08eea0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef1cu,2);
goto P_0c08eea2;
P_0c08eea2: /* original 490b, guest PC 0x0c08eea2 */
if(!s->budget--) { s->failed_pc=0x0c08eea2u; return 0; }
target=r[9];
r[16]=code_base|0x0c08eea6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08eea6u) { target=s->pc; goto dispatch; }
goto P_0c08eea6;
P_0c08eea4: /* original 0009, guest PC 0x0c08eea4 */
if(!s->budget--) { s->failed_pc=0x0c08eea4u; return 0; }
goto P_0c08eea6;
P_0c08eea6: /* original 4b0b, guest PC 0x0c08eea6 */
if(!s->budget--) { s->failed_pc=0x0c08eea6u; return 0; }
target=r[11];
r[16]=code_base|0x0c08eeaau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08eeaau) { target=s->pc; goto dispatch; }
goto P_0c08eeaa;
P_0c08eea8: /* original 0009, guest PC 0x0c08eea8 */
if(!s->budget--) { s->failed_pc=0x0c08eea8u; return 0; }
goto P_0c08eeaa;
P_0c08eeaa: /* original 9038, guest PC 0x0c08eeaa */
if(!s->budget--) { s->failed_pc=0x0c08eeaau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef1eu,2);
goto P_0c08eeac;
P_0c08eeac: /* original f6e6, guest PC 0x0c08eeac */
if(!s->budget--) { s->failed_pc=0x0c08eeacu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08eeae;
P_0c08eeae: /* original 70fc, guest PC 0x0c08eeae */
if(!s->budget--) { s->failed_pc=0x0c08eeaeu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08eeb0;
P_0c08eeb0: /* original f5e6, guest PC 0x0c08eeb0 */
if(!s->budget--) { s->failed_pc=0x0c08eeb0u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08eeb2;
P_0c08eeb2: /* original 70fc, guest PC 0x0c08eeb2 */
if(!s->budget--) { s->failed_pc=0x0c08eeb2u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08eeb4;
P_0c08eeb4: /* original f64d, guest PC 0x0c08eeb4 */
if(!s->budget--) { s->failed_pc=0x0c08eeb4u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08eeb6;
P_0c08eeb6: /* original 4d0b, guest PC 0x0c08eeb6 */
if(!s->budget--) { s->failed_pc=0x0c08eeb6u; return 0; }
target=r[13];
r[16]=code_base|0x0c08eebau;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08eebau) { target=s->pc; goto dispatch; }
goto P_0c08eeba;
P_0c08eeb8: /* original f4e6, guest PC 0x0c08eeb8 */
if(!s->budget--) { s->failed_pc=0x0c08eeb8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08eeba;
P_0c08eeba: /* original 9031, guest PC 0x0c08eeba */
if(!s->budget--) { s->failed_pc=0x0c08eebau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef20u,2);
goto P_0c08eebc;
P_0c08eebc: /* original f6e6, guest PC 0x0c08eebc */
if(!s->budget--) { s->failed_pc=0x0c08eebcu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08eebe;
P_0c08eebe: /* original 70fc, guest PC 0x0c08eebe */
if(!s->budget--) { s->failed_pc=0x0c08eebeu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08eec0;
P_0c08eec0: /* original f5e6, guest PC 0x0c08eec0 */
if(!s->budget--) { s->failed_pc=0x0c08eec0u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08eec2;
P_0c08eec2: /* original 70fc, guest PC 0x0c08eec2 */
if(!s->budget--) { s->failed_pc=0x0c08eec2u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08eec4;
P_0c08eec4: /* original f4e6, guest PC 0x0c08eec4 */
if(!s->budget--) { s->failed_pc=0x0c08eec4u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08eec6;
P_0c08eec6: /* original 4c0b, guest PC 0x0c08eec6 */
if(!s->budget--) { s->failed_pc=0x0c08eec6u; return 0; }
target=r[12];
r[16]=code_base|0x0c08eecau;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08eecau) { target=s->pc; goto dispatch; }
goto P_0c08eeca;
P_0c08eec8: /* original 64f3, guest PC 0x0c08eec8 */
if(!s->budget--) { s->failed_pc=0x0c08eec8u; return 0; }
r[4]=r[15];
goto P_0c08eeca;
P_0c08eeca: /* original f3fc, guest PC 0x0c08eeca */
if(!s->budget--) { s->failed_pc=0x0c08eecau; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c08eecc;
P_0c08eecc: /* original ff0c, guest PC 0x0c08eecc */
if(!s->budget--) { s->failed_pc=0x0c08eeccu; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c08eece;
P_0c08eece: /* original ff32, guest PC 0x0c08eece */
if(!s->budget--) { s->failed_pc=0x0c08eeceu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c08eed0;
P_0c08eed0: /* original f5fc, guest PC 0x0c08eed0 */
if(!s->budget--) { s->failed_pc=0x0c08eed0u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08eed2;
P_0c08eed2: /* original f6fc, guest PC 0x0c08eed2 */
if(!s->budget--) { s->failed_pc=0x0c08eed2u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08eed4;
P_0c08eed4: /* original 4a0b, guest PC 0x0c08eed4 */
if(!s->budget--) { s->failed_pc=0x0c08eed4u; return 0; }
target=r[10];
r[16]=code_base|0x0c08eed8u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08eed8u) { target=s->pc; goto dispatch; }
goto P_0c08eed8;
P_0c08eed6: /* original f4fc, guest PC 0x0c08eed6 */
if(!s->budget--) { s->failed_pc=0x0c08eed6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08eed8;
P_0c08eed8: /* original 9423, guest PC 0x0c08eed8 */
if(!s->budget--) { s->failed_pc=0x0c08eed8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ef22u,2);
goto P_0c08eeda;
P_0c08eeda: /* original 490b, guest PC 0x0c08eeda */
if(!s->budget--) { s->failed_pc=0x0c08eedau; return 0; }
target=r[9];
r[16]=code_base|0x0c08eedeu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08eedeu) { target=s->pc; goto dispatch; }
goto P_0c08eede;
P_0c08eedc: /* original 0009, guest PC 0x0c08eedc */
if(!s->budget--) { s->failed_pc=0x0c08eedcu; return 0; }
goto P_0c08eede;
P_0c08eede: /* original d31a, guest PC 0x0c08eede */
if(!s->budget--) { s->failed_pc=0x0c08eedeu; return 0; }
r[3]=read(ram,0x0c08ef48u,4);
goto P_0c08eee0;
P_0c08eee0: /* original 430b, guest PC 0x0c08eee0 */
if(!s->budget--) { s->failed_pc=0x0c08eee0u; return 0; }
target=r[3];
r[16]=code_base|0x0c08eee4u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08eee4u) { target=s->pc; goto dispatch; }
goto P_0c08eee4;
P_0c08eee2: /* original e401, guest PC 0x0c08eee2 */
if(!s->budget--) { s->failed_pc=0x0c08eee2u; return 0; }
r[4]=0x00000001u;
goto P_0c08eee4;
P_0c08eee4: /* original e004, guest PC 0x0c08eee4 */
if(!s->budget--) { s->failed_pc=0x0c08eee4u; return 0; }
r[0]=0x00000004u;
goto P_0c08eee6;
P_0c08eee6: /* original f6f6, guest PC 0x0c08eee6 */
if(!s->budget--) { s->failed_pc=0x0c08eee6u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c08eee8;
P_0c08eee8: /* original e008, guest PC 0x0c08eee8 */
if(!s->budget--) { s->failed_pc=0x0c08eee8u; return 0; }
r[0]=0x00000008u;
goto P_0c08eeea;
P_0c08eeea: /* original f5f6, guest PC 0x0c08eeea */
if(!s->budget--) { s->failed_pc=0x0c08eeeau; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c08eeec;
P_0c08eeec: /* original e00c, guest PC 0x0c08eeec */
if(!s->budget--) { s->failed_pc=0x0c08eeecu; return 0; }
r[0]=0x0000000cu;
goto P_0c08eeee;
P_0c08eeee: /* original f4f6, guest PC 0x0c08eeee */
if(!s->budget--) { s->failed_pc=0x0c08eeeeu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08eef0;
P_0c08eef0: /* original b02c, guest PC 0x0c08eef0 */
if(!s->budget--) { s->failed_pc=0x0c08eef0u; return 0; }
target=code_base|0x0c08ef4cu; r[16]=code_base|0x0c08eef4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08eef4u) { target=s->pc; goto dispatch; }
goto P_0c08eef4;
P_0c08eef2: /* original 64e3, guest PC 0x0c08eef2 */
if(!s->budget--) { s->failed_pc=0x0c08eef2u; return 0; }
r[4]=r[14];
goto P_0c08eef4;
P_0c08eef4: /* original 7f1c, guest PC 0x0c08eef4 */
if(!s->budget--) { s->failed_pc=0x0c08eef4u; return 0; }
r[15]+=0x0000001cu;
goto P_0c08eef6;
P_0c08eef6: /* original 4f26, guest PC 0x0c08eef6 */
if(!s->budget--) { s->failed_pc=0x0c08eef6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08eef8;
P_0c08eef8: /* original fef9, guest PC 0x0c08eef8 */
if(!s->budget--) { s->failed_pc=0x0c08eef8u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08eefa;
P_0c08eefa: /* original fff9, guest PC 0x0c08eefa */
if(!s->budget--) { s->failed_pc=0x0c08eefau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08eefc;
P_0c08eefc: /* original 69f6, guest PC 0x0c08eefc */
if(!s->budget--) { s->failed_pc=0x0c08eefcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08eefe;
P_0c08eefe: /* original 6af6, guest PC 0x0c08eefe */
if(!s->budget--) { s->failed_pc=0x0c08eefeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08ef00;
P_0c08ef00: /* original 6bf6, guest PC 0x0c08ef00 */
if(!s->budget--) { s->failed_pc=0x0c08ef00u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08ef02;
P_0c08ef02: /* original 6cf6, guest PC 0x0c08ef02 */
if(!s->budget--) { s->failed_pc=0x0c08ef02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08ef04;
P_0c08ef04: /* original 6df6, guest PC 0x0c08ef04 */
if(!s->budget--) { s->failed_pc=0x0c08ef04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08ef06;
P_0c08ef06: /* original 000b, guest PC 0x0c08ef06 */
if(!s->budget--) { s->failed_pc=0x0c08ef06u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08ef08: /* original 6ef6, guest PC 0x0c08ef08 */
if(!s->budget--) { s->failed_pc=0x0c08ef08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08ef0au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08ef0au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
