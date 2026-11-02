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
int vf3_away_batch37_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06bd08u: goto P_0c06bd08;
case 0x0c06bd0au: goto P_0c06bd0a;
case 0x0c06bd0cu: goto P_0c06bd0c;
case 0x0c06bd0eu: goto P_0c06bd0e;
case 0x0c06bd10u: goto P_0c06bd10;
case 0x0c06bd12u: goto P_0c06bd12;
case 0x0c06bd14u: goto P_0c06bd14;
case 0x0c06bd16u: goto P_0c06bd16;
case 0x0c06bd18u: goto P_0c06bd18;
case 0x0c06bd1au: goto P_0c06bd1a;
case 0x0c06bd1cu: goto P_0c06bd1c;
case 0x0c06bd1eu: goto P_0c06bd1e;
case 0x0c06bd20u: goto P_0c06bd20;
case 0x0c06bd22u: goto P_0c06bd22;
case 0x0c06bd24u: goto P_0c06bd24;
case 0x0c06bd26u: goto P_0c06bd26;
case 0x0c06bd28u: goto P_0c06bd28;
case 0x0c06bd2au: goto P_0c06bd2a;
case 0x0c06bd2cu: goto P_0c06bd2c;
case 0x0c06bd2eu: goto P_0c06bd2e;
case 0x0c06bd30u: goto P_0c06bd30;
case 0x0c06bd32u: goto P_0c06bd32;
case 0x0c06bd34u: goto P_0c06bd34;
case 0x0c06bd36u: goto P_0c06bd36;
case 0x0c06bd38u: goto P_0c06bd38;
case 0x0c06bd3au: goto P_0c06bd3a;
case 0x0c06bd3cu: goto P_0c06bd3c;
case 0x0c06bd3eu: goto P_0c06bd3e;
case 0x0c06bd40u: goto P_0c06bd40;
case 0x0c06bd42u: goto P_0c06bd42;
case 0x0c06bd44u: goto P_0c06bd44;
case 0x0c06bd46u: goto P_0c06bd46;
case 0x0c06bd48u: goto P_0c06bd48;
case 0x0c06bd4au: goto P_0c06bd4a;
case 0x0c06bd4cu: goto P_0c06bd4c;
case 0x0c06bd4eu: goto P_0c06bd4e;
case 0x0c06bd50u: goto P_0c06bd50;
case 0x0c06bd52u: goto P_0c06bd52;
case 0x0c06bd54u: goto P_0c06bd54;
case 0x0c06bd56u: goto P_0c06bd56;
case 0x0c06bd58u: goto P_0c06bd58;
case 0x0c06bd5au: goto P_0c06bd5a;
case 0x0c06bd5cu: goto P_0c06bd5c;
case 0x0c06bd5eu: goto P_0c06bd5e;
case 0x0c06bd60u: goto P_0c06bd60;
case 0x0c06bd62u: goto P_0c06bd62;
case 0x0c06bd64u: goto P_0c06bd64;
case 0x0c06bd66u: goto P_0c06bd66;
case 0x0c06bd68u: goto P_0c06bd68;
case 0x0c06bd6au: goto P_0c06bd6a;
case 0x0c06bd6cu: goto P_0c06bd6c;
case 0x0c06bd6eu: goto P_0c06bd6e;
case 0x0c06bd70u: goto P_0c06bd70;
case 0x0c06bd72u: goto P_0c06bd72;
case 0x0c06bd74u: goto P_0c06bd74;
case 0x0c06bd76u: goto P_0c06bd76;
case 0x0c06bd78u: goto P_0c06bd78;
case 0x0c06bd7au: goto P_0c06bd7a;
case 0x0c06bd7cu: goto P_0c06bd7c;
case 0x0c06bd7eu: goto P_0c06bd7e;
case 0x0c06bd80u: goto P_0c06bd80;
case 0x0c06bd82u: goto P_0c06bd82;
case 0x0c06bd84u: goto P_0c06bd84;
case 0x0c06bd86u: goto P_0c06bd86;
case 0x0c06bd88u: goto P_0c06bd88;
case 0x0c06bd8au: goto P_0c06bd8a;
case 0x0c06bd8cu: goto P_0c06bd8c;
case 0x0c06bd8eu: goto P_0c06bd8e;
case 0x0c06bd90u: goto P_0c06bd90;
case 0x0c06bd92u: goto P_0c06bd92;
case 0x0c06bd94u: goto P_0c06bd94;
case 0x0c06bd96u: goto P_0c06bd96;
case 0x0c06bd98u: goto P_0c06bd98;
case 0x0c06bd9au: goto P_0c06bd9a;
case 0x0c06bd9cu: goto P_0c06bd9c;
case 0x0c06bd9eu: goto P_0c06bd9e;
case 0x0c06bda0u: goto P_0c06bda0;
case 0x0c06bda2u: goto P_0c06bda2;
case 0x0c06bda4u: goto P_0c06bda4;
case 0x0c06bda6u: goto P_0c06bda6;
case 0x0c06bda8u: goto P_0c06bda8;
case 0x0c06bdaau: goto P_0c06bdaa;
case 0x0c06bdacu: goto P_0c06bdac;
case 0x0c06bdaeu: goto P_0c06bdae;
case 0x0c06bdb0u: goto P_0c06bdb0;
case 0x0c06bdb2u: goto P_0c06bdb2;
case 0x0c06bdb4u: goto P_0c06bdb4;
case 0x0c06bdb6u: goto P_0c06bdb6;
case 0x0c06bdb8u: goto P_0c06bdb8;
case 0x0c06bdbau: goto P_0c06bdba;
case 0x0c06bdbcu: goto P_0c06bdbc;
case 0x0c06bdbeu: goto P_0c06bdbe;
case 0x0c06bdc0u: goto P_0c06bdc0;
case 0x0c06bdc2u: goto P_0c06bdc2;
case 0x0c06bdc4u: goto P_0c06bdc4;
case 0x0c06bdc6u: goto P_0c06bdc6;
case 0x0c06bdc8u: goto P_0c06bdc8;
case 0x0c06bdcau: goto P_0c06bdca;
case 0x0c06bdccu: goto P_0c06bdcc;
case 0x0c06bdceu: goto P_0c06bdce;
case 0x0c06bdd0u: goto P_0c06bdd0;
case 0x0c06bdd2u: goto P_0c06bdd2;
case 0x0c06bdd4u: goto P_0c06bdd4;
case 0x0c06bdd6u: goto P_0c06bdd6;
case 0x0c06bdd8u: goto P_0c06bdd8;
case 0x0c06bddau: goto P_0c06bdda;
case 0x0c06bddcu: goto P_0c06bddc;
case 0x0c06bddeu: goto P_0c06bdde;
case 0x0c06bde0u: goto P_0c06bde0;
case 0x0c06bde2u: goto P_0c06bde2;
case 0x0c06bde4u: goto P_0c06bde4;
case 0x0c06bde6u: goto P_0c06bde6;
case 0x0c06bde8u: goto P_0c06bde8;
case 0x0c06bdeau: goto P_0c06bdea;
case 0x0c06bdecu: goto P_0c06bdec;
case 0x0c06bdeeu: goto P_0c06bdee;
case 0x0c06bdf0u: goto P_0c06bdf0;
case 0x0c06bdf2u: goto P_0c06bdf2;
case 0x0c06bdf4u: goto P_0c06bdf4;
case 0x0c06bdf6u: goto P_0c06bdf6;
case 0x0c06bdf8u: goto P_0c06bdf8;
case 0x0c06bdfau: goto P_0c06bdfa;
case 0x0c06bdfcu: goto P_0c06bdfc;
case 0x0c06bdfeu: goto P_0c06bdfe;
case 0x0c06be00u: goto P_0c06be00;
case 0x0c06be02u: goto P_0c06be02;
case 0x0c06be04u: goto P_0c06be04;
case 0x0c06be06u: goto P_0c06be06;
case 0x0c06be08u: goto P_0c06be08;
case 0x0c06be0au: goto P_0c06be0a;
case 0x0c06be0cu: goto P_0c06be0c;
case 0x0c06be0eu: goto P_0c06be0e;
case 0x0c06be10u: goto P_0c06be10;
case 0x0c06be12u: goto P_0c06be12;
case 0x0c06be14u: goto P_0c06be14;
case 0x0c06be16u: goto P_0c06be16;
case 0x0c06be18u: goto P_0c06be18;
case 0x0c06be1au: goto P_0c06be1a;
case 0x0c06be1cu: goto P_0c06be1c;
case 0x0c06be1eu: goto P_0c06be1e;
case 0x0c06be20u: goto P_0c06be20;
case 0x0c06be22u: goto P_0c06be22;
case 0x0c06be24u: goto P_0c06be24;
case 0x0c06be26u: goto P_0c06be26;
case 0x0c06be28u: goto P_0c06be28;
case 0x0c06be2au: goto P_0c06be2a;
case 0x0c06be2cu: goto P_0c06be2c;
case 0x0c06be2eu: goto P_0c06be2e;
case 0x0c06be30u: goto P_0c06be30;
case 0x0c06be32u: goto P_0c06be32;
case 0x0c06be34u: goto P_0c06be34;
case 0x0c06be36u: goto P_0c06be36;
case 0x0c06be38u: goto P_0c06be38;
case 0x0c06be3au: goto P_0c06be3a;
case 0x0c06be3cu: goto P_0c06be3c;
case 0x0c06be3eu: goto P_0c06be3e;
case 0x0c06be40u: goto P_0c06be40;
case 0x0c06be42u: goto P_0c06be42;
case 0x0c06be44u: goto P_0c06be44;
case 0x0c06be46u: goto P_0c06be46;
case 0x0c06be48u: goto P_0c06be48;
case 0x0c06be4au: goto P_0c06be4a;
case 0x0c06be4cu: goto P_0c06be4c;
case 0x0c06be4eu: goto P_0c06be4e;
case 0x0c06be50u: goto P_0c06be50;
case 0x0c06be52u: goto P_0c06be52;
case 0x0c06be54u: goto P_0c06be54;
case 0x0c06be56u: goto P_0c06be56;
case 0x0c06be58u: goto P_0c06be58;
case 0x0c06be5au: goto P_0c06be5a;
case 0x0c06be5cu: goto P_0c06be5c;
case 0x0c06be5eu: goto P_0c06be5e;
case 0x0c06be60u: goto P_0c06be60;
case 0x0c06be62u: goto P_0c06be62;
case 0x0c06be64u: goto P_0c06be64;
case 0x0c06be66u: goto P_0c06be66;
case 0x0c06be68u: goto P_0c06be68;
case 0x0c06be6au: goto P_0c06be6a;
case 0x0c06be6cu: goto P_0c06be6c;
case 0x0c06be6eu: goto P_0c06be6e;
case 0x0c06be70u: goto P_0c06be70;
case 0x0c06be72u: goto P_0c06be72;
case 0x0c06be74u: goto P_0c06be74;
case 0x0c06be76u: goto P_0c06be76;
case 0x0c06be78u: goto P_0c06be78;
case 0x0c06be7au: goto P_0c06be7a;
case 0x0c06be7cu: goto P_0c06be7c;
case 0x0c06be7eu: goto P_0c06be7e;
case 0x0c06be80u: goto P_0c06be80;
case 0x0c06be82u: goto P_0c06be82;
case 0x0c06be84u: goto P_0c06be84;
case 0x0c06be86u: goto P_0c06be86;
case 0x0c06be88u: goto P_0c06be88;
case 0x0c06be8au: goto P_0c06be8a;
case 0x0c06be8cu: goto P_0c06be8c;
case 0x0c06bf54u: goto P_0c06bf54;
case 0x0c06bf56u: goto P_0c06bf56;
case 0x0c06bf58u: goto P_0c06bf58;
case 0x0c06bf5au: goto P_0c06bf5a;
case 0x0c06bf5cu: goto P_0c06bf5c;
case 0x0c06bf5eu: goto P_0c06bf5e;
case 0x0c06bf60u: goto P_0c06bf60;
case 0x0c06bf62u: goto P_0c06bf62;
case 0x0c06bf64u: goto P_0c06bf64;
case 0x0c06bf66u: goto P_0c06bf66;
case 0x0c06bf68u: goto P_0c06bf68;
case 0x0c06bf6au: goto P_0c06bf6a;
case 0x0c06bf6cu: goto P_0c06bf6c;
case 0x0c06bf6eu: goto P_0c06bf6e;
case 0x0c06bf70u: goto P_0c06bf70;
case 0x0c06bf72u: goto P_0c06bf72;
case 0x0c06bf74u: goto P_0c06bf74;
case 0x0c06bf76u: goto P_0c06bf76;
case 0x0c06bf78u: goto P_0c06bf78;
case 0x0c06bf7au: goto P_0c06bf7a;
case 0x0c06bf7cu: goto P_0c06bf7c;
case 0x0c06bf7eu: goto P_0c06bf7e;
case 0x0c06bf80u: goto P_0c06bf80;
case 0x0c06bf82u: goto P_0c06bf82;
case 0x0c06bf84u: goto P_0c06bf84;
case 0x0c06bf86u: goto P_0c06bf86;
case 0x0c06bf88u: goto P_0c06bf88;
case 0x0c06bf8au: goto P_0c06bf8a;
case 0x0c06bf8cu: goto P_0c06bf8c;
case 0x0c06bf8eu: goto P_0c06bf8e;
case 0x0c06bf90u: goto P_0c06bf90;
case 0x0c06bf92u: goto P_0c06bf92;
case 0x0c06bf94u: goto P_0c06bf94;
case 0x0c06bf96u: goto P_0c06bf96;
case 0x0c06bf98u: goto P_0c06bf98;
case 0x0c06bf9au: goto P_0c06bf9a;
case 0x0c06bf9cu: goto P_0c06bf9c;
case 0x0c06bf9eu: goto P_0c06bf9e;
case 0x0c06bfa0u: goto P_0c06bfa0;
case 0x0c06bfa2u: goto P_0c06bfa2;
case 0x0c06bfa4u: goto P_0c06bfa4;
case 0x0c06bfa6u: goto P_0c06bfa6;
case 0x0c06bfa8u: goto P_0c06bfa8;
case 0x0c06bfaau: goto P_0c06bfaa;
case 0x0c06bfe0u: goto P_0c06bfe0;
case 0x0c06bfe2u: goto P_0c06bfe2;
case 0x0c06bfe4u: goto P_0c06bfe4;
case 0x0c06bfe6u: goto P_0c06bfe6;
case 0x0c06bfe8u: goto P_0c06bfe8;
case 0x0c06bfeau: goto P_0c06bfea;
case 0x0c06bfecu: goto P_0c06bfec;
case 0x0c06bfeeu: goto P_0c06bfee;
case 0x0c06bff0u: goto P_0c06bff0;
case 0x0c06bff2u: goto P_0c06bff2;
case 0x0c06bff4u: goto P_0c06bff4;
case 0x0c06bff6u: goto P_0c06bff6;
case 0x0c06bff8u: goto P_0c06bff8;
case 0x0c06bffau: goto P_0c06bffa;
case 0x0c06bffcu: goto P_0c06bffc;
case 0x0c06bffeu: goto P_0c06bffe;
case 0x0c06c000u: goto P_0c06c000;
case 0x0c06c002u: goto P_0c06c002;
case 0x0c06c004u: goto P_0c06c004;
case 0x0c06c006u: goto P_0c06c006;
case 0x0c06c008u: goto P_0c06c008;
case 0x0c06c00au: goto P_0c06c00a;
case 0x0c06c00cu: goto P_0c06c00c;
case 0x0c06c00eu: goto P_0c06c00e;
case 0x0c06c010u: goto P_0c06c010;
case 0x0c06c012u: goto P_0c06c012;
case 0x0c06c014u: goto P_0c06c014;
case 0x0c06c016u: goto P_0c06c016;
case 0x0c06c018u: goto P_0c06c018;
case 0x0c06c01au: goto P_0c06c01a;
case 0x0c06c01cu: goto P_0c06c01c;
case 0x0c06c01eu: goto P_0c06c01e;
case 0x0c06c020u: goto P_0c06c020;
case 0x0c06c022u: goto P_0c06c022;
case 0x0c06c024u: goto P_0c06c024;
case 0x0c06c026u: goto P_0c06c026;
case 0x0c06c028u: goto P_0c06c028;
case 0x0c06c02au: goto P_0c06c02a;
case 0x0c06c02cu: goto P_0c06c02c;
case 0x0c06c02eu: goto P_0c06c02e;
case 0x0c06c030u: goto P_0c06c030;
case 0x0c06c032u: goto P_0c06c032;
case 0x0c06c034u: goto P_0c06c034;
case 0x0c06c036u: goto P_0c06c036;
case 0x0c06c038u: goto P_0c06c038;
case 0x0c06c03au: goto P_0c06c03a;
case 0x0c06c03cu: goto P_0c06c03c;
case 0x0c06c03eu: goto P_0c06c03e;
case 0x0c06c040u: goto P_0c06c040;
case 0x0c06c042u: goto P_0c06c042;
case 0x0c06c044u: goto P_0c06c044;
case 0x0c06c046u: goto P_0c06c046;
case 0x0c06c048u: goto P_0c06c048;
case 0x0c06c04au: goto P_0c06c04a;
case 0x0c06c04cu: goto P_0c06c04c;
case 0x0c06c04eu: goto P_0c06c04e;
case 0x0c06c050u: goto P_0c06c050;
case 0x0c06c052u: goto P_0c06c052;
case 0x0c06c054u: goto P_0c06c054;
case 0x0c06c056u: goto P_0c06c056;
case 0x0c06c058u: goto P_0c06c058;
case 0x0c06c05au: goto P_0c06c05a;
case 0x0c06c05cu: goto P_0c06c05c;
case 0x0c06c05eu: goto P_0c06c05e;
case 0x0c06c060u: goto P_0c06c060;
case 0x0c06c062u: goto P_0c06c062;
case 0x0c06c064u: goto P_0c06c064;
case 0x0c06c066u: goto P_0c06c066;
case 0x0c06c068u: goto P_0c06c068;
case 0x0c06c06au: goto P_0c06c06a;
case 0x0c06c06cu: goto P_0c06c06c;
case 0x0c06c06eu: goto P_0c06c06e;
case 0x0c06c070u: goto P_0c06c070;
case 0x0c06c072u: goto P_0c06c072;
case 0x0c06c074u: goto P_0c06c074;
case 0x0c06c076u: goto P_0c06c076;
case 0x0c06c078u: goto P_0c06c078;
case 0x0c06c07au: goto P_0c06c07a;
case 0x0c06c07cu: goto P_0c06c07c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06bd08: /* original 2fe6, guest PC 0x0c06bd08 */
if(!s->budget--) { s->failed_pc=0x0c06bd08u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06bd0a;
P_0c06bd0a: /* original 2fd6, guest PC 0x0c06bd0a */
if(!s->budget--) { s->failed_pc=0x0c06bd0au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06bd0c;
P_0c06bd0c: /* original 6d63, guest PC 0x0c06bd0c */
if(!s->budget--) { s->failed_pc=0x0c06bd0cu; return 0; }
r[13]=r[6];
goto P_0c06bd0e;
P_0c06bd0e: /* original 2fc6, guest PC 0x0c06bd0e */
if(!s->budget--) { s->failed_pc=0x0c06bd0eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06bd10;
P_0c06bd10: /* original 2fb6, guest PC 0x0c06bd10 */
if(!s->budget--) { s->failed_pc=0x0c06bd10u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06bd12;
P_0c06bd12: /* original 2fa6, guest PC 0x0c06bd12 */
if(!s->budget--) { s->failed_pc=0x0c06bd12u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06bd14;
P_0c06bd14: /* original 4f22, guest PC 0x0c06bd14 */
if(!s->budget--) { s->failed_pc=0x0c06bd14u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06bd16;
P_0c06bd16: /* original 4f12, guest PC 0x0c06bd16 */
if(!s->budget--) { s->failed_pc=0x0c06bd16u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c06bd18;
P_0c06bd18: /* original 7ff4, guest PC 0x0c06bd18 */
if(!s->budget--) { s->failed_pc=0x0c06bd18u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c06bd1a;
P_0c06bd1a: /* original 2f42, guest PC 0x0c06bd1a */
if(!s->budget--) { s->failed_pc=0x0c06bd1au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06bd1c;
P_0c06bd1c: /* original 1f51, guest PC 0x0c06bd1c */
if(!s->budget--) { s->failed_pc=0x0c06bd1cu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c06bd1e;
P_0c06bd1e: /* original 65d3, guest PC 0x0c06bd1e */
if(!s->budget--) { s->failed_pc=0x0c06bd1eu; return 0; }
r[5]=r[13];
goto P_0c06bd20;
P_0c06bd20: /* original 1f72, guest PC 0x0c06bd20 */
if(!s->budget--) { s->failed_pc=0x0c06bd20u; return 0; }
write(ram,r[15]+8,r[7],4);
goto P_0c06bd22;
P_0c06bd22: /* original 90b4, guest PC 0x0c06bd22 */
if(!s->budget--) { s->failed_pc=0x0c06bd22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06be8eu,2);
goto P_0c06bd24;
P_0c06bd24: /* original de5c, guest PC 0x0c06bd24 */
if(!s->budget--) { s->failed_pc=0x0c06bd24u; return 0; }
r[14]=read(ram,0x0c06be98u,4);
goto P_0c06bd26;
P_0c06bd26: /* original 54f1, guest PC 0x0c06bd26 */
if(!s->budget--) { s->failed_pc=0x0c06bd26u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c06bd28;
P_0c06bd28: /* original 0bec, guest PC 0x0c06bd28 */
if(!s->budget--) { s->failed_pc=0x0c06bd28u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bd2a;
P_0c06bd2a: /* original d35c, guest PC 0x0c06bd2a */
if(!s->budget--) { s->failed_pc=0x0c06bd2au; return 0; }
r[3]=read(ram,0x0c06be9cu,4);
goto P_0c06bd2c;
P_0c06bd2c: /* original 35bc, guest PC 0x0c06bd2c */
if(!s->budget--) { s->failed_pc=0x0c06bd2cu; return 0; }
r[5]+=r[11];
goto P_0c06bd2e;
P_0c06bd2e: /* original 6442, guest PC 0x0c06bd2e */
if(!s->budget--) { s->failed_pc=0x0c06bd2eu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c06bd30;
P_0c06bd30: /* original 6153, guest PC 0x0c06bd30 */
if(!s->budget--) { s->failed_pc=0x0c06bd30u; return 0; }
r[1]=r[5];
goto P_0c06bd32;
P_0c06bd32: /* original 430b, guest PC 0x0c06bd32 */
if(!s->budget--) { s->failed_pc=0x0c06bd32u; return 0; }
target=r[3];
r[16]=code_base|0x0c06bd36u;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bd36u) { target=s->pc; goto dispatch; }
goto P_0c06bd36;
P_0c06bd34: /* original 6043, guest PC 0x0c06bd34 */
if(!s->budget--) { s->failed_pc=0x0c06bd34u; return 0; }
r[0]=r[4];
goto P_0c06bd36;
P_0c06bd36: /* original 6a03, guest PC 0x0c06bd36 */
if(!s->budget--) { s->failed_pc=0x0c06bd36u; return 0; }
r[10]=r[0];
goto P_0c06bd38;
P_0c06bd38: /* original 6c53, guest PC 0x0c06bd38 */
if(!s->budget--) { s->failed_pc=0x0c06bd38u; return 0; }
r[12]=r[5];
goto P_0c06bd3a;
P_0c06bd3a: /* original 04a7, guest PC 0x0c06bd3a */
if(!s->budget--) { s->failed_pc=0x0c06bd3au; return 0; }
r[19]=r[4]*r[10];
goto P_0c06bd3c;
P_0c06bd3c: /* original 90a7, guest PC 0x0c06bd3c */
if(!s->budget--) { s->failed_pc=0x0c06bd3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06be8eu,2);
goto P_0c06bd3e;
P_0c06bd3e: /* original 041a, guest PC 0x0c06bd3e */
if(!s->budget--) { s->failed_pc=0x0c06bd3eu; return 0; }
r[4]=r[19];
goto P_0c06bd40;
P_0c06bd40: /* original 3c48, guest PC 0x0c06bd40 */
if(!s->budget--) { s->failed_pc=0x0c06bd40u; return 0; }
r[12]-=r[4];
goto P_0c06bd42;
P_0c06bd42: /* original 0ec4, guest PC 0x0c06bd42 */
if(!s->budget--) { s->failed_pc=0x0c06bd42u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06bd44;
P_0c06bd44: /* original 65c3, guest PC 0x0c06bd44 */
if(!s->budget--) { s->failed_pc=0x0c06bd44u; return 0; }
r[5]=r[12];
goto P_0c06bd46;
P_0c06bd46: /* original 64f2, guest PC 0x0c06bd46 */
if(!s->budget--) { s->failed_pc=0x0c06bd46u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06bd48;
P_0c06bd48: /* original d355, guest PC 0x0c06bd48 */
if(!s->budget--) { s->failed_pc=0x0c06bd48u; return 0; }
r[3]=read(ram,0x0c06bea0u,4);
goto P_0c06bd4a;
P_0c06bd4a: /* original 430b, guest PC 0x0c06bd4a */
if(!s->budget--) { s->failed_pc=0x0c06bd4au; return 0; }
target=r[3];
r[16]=code_base|0x0c06bd4eu;
r[4]+=0x00000028u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bd4eu) { target=s->pc; goto dispatch; }
goto P_0c06bd4e;
P_0c06bd4c: /* original 7428, guest PC 0x0c06bd4c */
if(!s->budget--) { s->failed_pc=0x0c06bd4cu; return 0; }
r[4]+=0x00000028u;
goto P_0c06bd4e;
P_0c06bd4e: /* original 909f, guest PC 0x0c06bd4e */
if(!s->budget--) { s->failed_pc=0x0c06bd4eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06be90u,2);
goto P_0c06bd50;
P_0c06bd50: /* original 3dac, guest PC 0x0c06bd50 */
if(!s->budget--) { s->failed_pc=0x0c06bd50u; return 0; }
r[13]+=r[10];
goto P_0c06bd52;
P_0c06bd52: /* original d352, guest PC 0x0c06bd52 */
if(!s->budget--) { s->failed_pc=0x0c06bd52u; return 0; }
r[3]=read(ram,0x0c06be9cu,4);
goto P_0c06bd54;
P_0c06bd54: /* original 04ec, guest PC 0x0c06bd54 */
if(!s->budget--) { s->failed_pc=0x0c06bd54u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bd56;
P_0c06bd56: /* original 70fb, guest PC 0x0c06bd56 */
if(!s->budget--) { s->failed_pc=0x0c06bd56u; return 0; }
r[0]+=0xfffffffbu;
goto P_0c06bd58;
P_0c06bd58: /* original 3d4c, guest PC 0x0c06bd58 */
if(!s->budget--) { s->failed_pc=0x0c06bd58u; return 0; }
r[13]+=r[4];
goto P_0c06bd5a;
P_0c06bd5a: /* original 04ec, guest PC 0x0c06bd5a */
if(!s->budget--) { s->failed_pc=0x0c06bd5au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bd5c;
P_0c06bd5c: /* original 61d3, guest PC 0x0c06bd5c */
if(!s->budget--) { s->failed_pc=0x0c06bd5cu; return 0; }
r[1]=r[13];
goto P_0c06bd5e;
P_0c06bd5e: /* original 430b, guest PC 0x0c06bd5e */
if(!s->budget--) { s->failed_pc=0x0c06bd5eu; return 0; }
target=r[3];
r[16]=code_base|0x0c06bd62u;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bd62u) { target=s->pc; goto dispatch; }
goto P_0c06bd62;
P_0c06bd60: /* original 6043, guest PC 0x0c06bd60 */
if(!s->budget--) { s->failed_pc=0x0c06bd60u; return 0; }
r[0]=r[4];
goto P_0c06bd62;
P_0c06bd62: /* original 6c03, guest PC 0x0c06bd62 */
if(!s->budget--) { s->failed_pc=0x0c06bd62u; return 0; }
r[12]=r[0];
goto P_0c06bd64;
P_0c06bd64: /* original 9094, guest PC 0x0c06bd64 */
if(!s->budget--) { s->failed_pc=0x0c06bd64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06be90u,2);
goto P_0c06bd66;
P_0c06bd66: /* original 04c7, guest PC 0x0c06bd66 */
if(!s->budget--) { s->failed_pc=0x0c06bd66u; return 0; }
r[19]=r[4]*r[12];
goto P_0c06bd68;
P_0c06bd68: /* original 041a, guest PC 0x0c06bd68 */
if(!s->budget--) { s->failed_pc=0x0c06bd68u; return 0; }
r[4]=r[19];
goto P_0c06bd6a;
P_0c06bd6a: /* original 3d48, guest PC 0x0c06bd6a */
if(!s->budget--) { s->failed_pc=0x0c06bd6au; return 0; }
r[13]-=r[4];
goto P_0c06bd6c;
P_0c06bd6c: /* original 0ed4, guest PC 0x0c06bd6c */
if(!s->budget--) { s->failed_pc=0x0c06bd6cu; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c06bd6e;
P_0c06bd6e: /* original 65d3, guest PC 0x0c06bd6e */
if(!s->budget--) { s->failed_pc=0x0c06bd6eu; return 0; }
r[5]=r[13];
goto P_0c06bd70;
P_0c06bd70: /* original 64f2, guest PC 0x0c06bd70 */
if(!s->budget--) { s->failed_pc=0x0c06bd70u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06bd72;
P_0c06bd72: /* original d34b, guest PC 0x0c06bd72 */
if(!s->budget--) { s->failed_pc=0x0c06bd72u; return 0; }
r[3]=read(ram,0x0c06bea0u,4);
goto P_0c06bd74;
P_0c06bd74: /* original 430b, guest PC 0x0c06bd74 */
if(!s->budget--) { s->failed_pc=0x0c06bd74u; return 0; }
target=r[3];
r[16]=code_base|0x0c06bd78u;
r[4]+=0x00000027u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bd78u) { target=s->pc; goto dispatch; }
goto P_0c06bd78;
P_0c06bd76: /* original 7427, guest PC 0x0c06bd76 */
if(!s->budget--) { s->failed_pc=0x0c06bd76u; return 0; }
r[4]+=0x00000027u;
goto P_0c06bd78;
P_0c06bd78: /* original 908b, guest PC 0x0c06bd78 */
if(!s->budget--) { s->failed_pc=0x0c06bd78u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06be92u,2);
goto P_0c06bd7a;
P_0c06bd7a: /* original 53f1, guest PC 0x0c06bd7a */
if(!s->budget--) { s->failed_pc=0x0c06bd7au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06bd7c;
P_0c06bd7c: /* original 04ec, guest PC 0x0c06bd7c */
if(!s->budget--) { s->failed_pc=0x0c06bd7cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bd7e;
P_0c06bd7e: /* original 7008, guest PC 0x0c06bd7e */
if(!s->budget--) { s->failed_pc=0x0c06bd7eu; return 0; }
r[0]+=0x00000008u;
goto P_0c06bd80;
P_0c06bd80: /* original 05ec, guest PC 0x0c06bd80 */
if(!s->budget--) { s->failed_pc=0x0c06bd80u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bd82;
P_0c06bd82: /* original 34cc, guest PC 0x0c06bd82 */
if(!s->budget--) { s->failed_pc=0x0c06bd82u; return 0; }
r[4]+=r[12];
goto P_0c06bd84;
P_0c06bd84: /* original 2352, guest PC 0x0c06bd84 */
if(!s->budget--) { s->failed_pc=0x0c06bd84u; return 0; }
write(ram,r[3],r[5],4);
goto P_0c06bd86;
P_0c06bd86: /* original 53f2, guest PC 0x0c06bd86 */
if(!s->budget--) { s->failed_pc=0x0c06bd86u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c06bd88;
P_0c06bd88: /* original 2342, guest PC 0x0c06bd88 */
if(!s->budget--) { s->failed_pc=0x0c06bd88u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c06bd8a;
P_0c06bd8a: /* original 53fa, guest PC 0x0c06bd8a */
if(!s->budget--) { s->failed_pc=0x0c06bd8au; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c06bd8c;
P_0c06bd8c: /* original 7f0c, guest PC 0x0c06bd8c */
if(!s->budget--) { s->failed_pc=0x0c06bd8cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c06bd8e;
P_0c06bd8e: /* original 4f16, guest PC 0x0c06bd8e */
if(!s->budget--) { s->failed_pc=0x0c06bd8eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c06bd90;
P_0c06bd90: /* original 23b2, guest PC 0x0c06bd90 */
if(!s->budget--) { s->failed_pc=0x0c06bd90u; return 0; }
write(ram,r[3],r[11],4);
goto P_0c06bd92;
P_0c06bd92: /* original 4f26, guest PC 0x0c06bd92 */
if(!s->budget--) { s->failed_pc=0x0c06bd92u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06bd94;
P_0c06bd94: /* original 6af6, guest PC 0x0c06bd94 */
if(!s->budget--) { s->failed_pc=0x0c06bd94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06bd96;
P_0c06bd96: /* original 6bf6, guest PC 0x0c06bd96 */
if(!s->budget--) { s->failed_pc=0x0c06bd96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06bd98;
P_0c06bd98: /* original 6cf6, guest PC 0x0c06bd98 */
if(!s->budget--) { s->failed_pc=0x0c06bd98u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06bd9a;
P_0c06bd9a: /* original 6df6, guest PC 0x0c06bd9a */
if(!s->budget--) { s->failed_pc=0x0c06bd9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06bd9c;
P_0c06bd9c: /* original 000b, guest PC 0x0c06bd9c */
if(!s->budget--) { s->failed_pc=0x0c06bd9cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06bd9e: /* original 6ef6, guest PC 0x0c06bd9e */
if(!s->budget--) { s->failed_pc=0x0c06bd9eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06bda0;
P_0c06bda0: /* original 2fe6, guest PC 0x0c06bda0 */
if(!s->budget--) { s->failed_pc=0x0c06bda0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06bda2;
P_0c06bda2: /* original 6e53, guest PC 0x0c06bda2 */
if(!s->budget--) { s->failed_pc=0x0c06bda2u; return 0; }
r[14]=r[5];
goto P_0c06bda4;
P_0c06bda4: /* original 7ffc, guest PC 0x0c06bda4 */
if(!s->budget--) { s->failed_pc=0x0c06bda4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06bda6;
P_0c06bda6: /* original 63e3, guest PC 0x0c06bda6 */
if(!s->budget--) { s->failed_pc=0x0c06bda6u; return 0; }
r[3]=r[14];
goto P_0c06bda8;
P_0c06bda8: /* original 2f42, guest PC 0x0c06bda8 */
if(!s->budget--) { s->failed_pc=0x0c06bda8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06bdaa;
P_0c06bdaa: /* original d43b, guest PC 0x0c06bdaa */
if(!s->budget--) { s->failed_pc=0x0c06bdaau; return 0; }
r[4]=read(ram,0x0c06be98u,4);
goto P_0c06bdac;
P_0c06bdac: /* original 9071, guest PC 0x0c06bdac */
if(!s->budget--) { s->failed_pc=0x0c06bdacu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06be92u,2);
goto P_0c06bdae;
P_0c06bdae: /* original 054c, guest PC 0x0c06bdae */
if(!s->budget--) { s->failed_pc=0x0c06bdaeu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06bdb0;
P_0c06bdb0: /* original 7018, guest PC 0x0c06bdb0 */
if(!s->budget--) { s->failed_pc=0x0c06bdb0u; return 0; }
r[0]+=0x00000018u;
goto P_0c06bdb2;
P_0c06bdb2: /* original 064c, guest PC 0x0c06bdb2 */
if(!s->budget--) { s->failed_pc=0x0c06bdb2u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06bdb4;
P_0c06bdb4: /* original 3358, guest PC 0x0c06bdb4 */
if(!s->budget--) { s->failed_pc=0x0c06bdb4u; return 0; }
r[3]-=r[5];
goto P_0c06bdb6;
P_0c06bdb6: /* original 6533, guest PC 0x0c06bdb6 */
if(!s->budget--) { s->failed_pc=0x0c06bdb6u; return 0; }
r[5]=r[3];
goto P_0c06bdb8;
P_0c06bdb8: /* original 365c, guest PC 0x0c06bdb8 */
if(!s->budget--) { s->failed_pc=0x0c06bdb8u; return 0; }
r[6]+=r[5];
goto P_0c06bdba;
P_0c06bdba: /* original 0464, guest PC 0x0c06bdba */
if(!s->budget--) { s->failed_pc=0x0c06bdbau; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c06bdbc;
P_0c06bdbc: /* original 70e8, guest PC 0x0c06bdbc */
if(!s->budget--) { s->failed_pc=0x0c06bdbcu; return 0; }
r[0]+=0xffffffe8u;
goto P_0c06bdbe;
P_0c06bdbe: /* original 04e4, guest PC 0x0c06bdbe */
if(!s->budget--) { s->failed_pc=0x0c06bdbeu; return 0; }
write(ram,r[4]+r[0],r[14],1);
goto P_0c06bdc0;
P_0c06bdc0: /* original 65e3, guest PC 0x0c06bdc0 */
if(!s->budget--) { s->failed_pc=0x0c06bdc0u; return 0; }
r[5]=r[14];
goto P_0c06bdc2;
P_0c06bdc2: /* original 64f2, guest PC 0x0c06bdc2 */
if(!s->budget--) { s->failed_pc=0x0c06bdc2u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06bdc4;
P_0c06bdc4: /* original 7f04, guest PC 0x0c06bdc4 */
if(!s->budget--) { s->failed_pc=0x0c06bdc4u; return 0; }
r[15]+=0x00000004u;
goto P_0c06bdc6;
P_0c06bdc6: /* original d336, guest PC 0x0c06bdc6 */
if(!s->budget--) { s->failed_pc=0x0c06bdc6u; return 0; }
r[3]=read(ram,0x0c06bea0u,4);
goto P_0c06bdc8;
P_0c06bdc8: /* original 7426, guest PC 0x0c06bdc8 */
if(!s->budget--) { s->failed_pc=0x0c06bdc8u; return 0; }
r[4]+=0x00000026u;
goto P_0c06bdca;
P_0c06bdca: /* original 432b, guest PC 0x0c06bdca */
if(!s->budget--) { s->failed_pc=0x0c06bdcau; return 0; }
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
P_0c06bdcc: /* original 6ef6, guest PC 0x0c06bdcc */
if(!s->budget--) { s->failed_pc=0x0c06bdccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06bdce;
P_0c06bdce: /* original 2fe6, guest PC 0x0c06bdce */
if(!s->budget--) { s->failed_pc=0x0c06bdceu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06bdd0;
P_0c06bdd0: /* original 2fd6, guest PC 0x0c06bdd0 */
if(!s->budget--) { s->failed_pc=0x0c06bdd0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06bdd2;
P_0c06bdd2: /* original 2fc6, guest PC 0x0c06bdd2 */
if(!s->budget--) { s->failed_pc=0x0c06bdd2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06bdd4;
P_0c06bdd4: /* original 2fb6, guest PC 0x0c06bdd4 */
if(!s->budget--) { s->failed_pc=0x0c06bdd4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06bdd6;
P_0c06bdd6: /* original 4f22, guest PC 0x0c06bdd6 */
if(!s->budget--) { s->failed_pc=0x0c06bdd6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06bdd8;
P_0c06bdd8: /* original 4f12, guest PC 0x0c06bdd8 */
if(!s->budget--) { s->failed_pc=0x0c06bdd8u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c06bdda;
P_0c06bdda: /* original 7ff4, guest PC 0x0c06bdda */
if(!s->budget--) { s->failed_pc=0x0c06bddau; return 0; }
r[15]+=0xfffffff4u;
goto P_0c06bddc;
P_0c06bddc: /* original 1f42, guest PC 0x0c06bddc */
if(!s->budget--) { s->failed_pc=0x0c06bddcu; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c06bdde;
P_0c06bdde: /* original 1f51, guest PC 0x0c06bdde */
if(!s->budget--) { s->failed_pc=0x0c06bddeu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c06bde0;
P_0c06bde0: /* original 2f72, guest PC 0x0c06bde0 */
if(!s->budget--) { s->failed_pc=0x0c06bde0u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c06bde2;
P_0c06bde2: /* original 9055, guest PC 0x0c06bde2 */
if(!s->budget--) { s->failed_pc=0x0c06bde2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06be90u,2);
goto P_0c06bde4;
P_0c06bde4: /* original de2c, guest PC 0x0c06bde4 */
if(!s->budget--) { s->failed_pc=0x0c06bde4u; return 0; }
r[14]=read(ram,0x0c06be98u,4);
goto P_0c06bde6;
P_0c06bde6: /* original d32d, guest PC 0x0c06bde6 */
if(!s->budget--) { s->failed_pc=0x0c06bde6u; return 0; }
r[3]=read(ram,0x0c06be9cu,4);
goto P_0c06bde8;
P_0c06bde8: /* original 0bec, guest PC 0x0c06bde8 */
if(!s->budget--) { s->failed_pc=0x0c06bde8u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bdea;
P_0c06bdea: /* original 70fb, guest PC 0x0c06bdea */
if(!s->budget--) { s->failed_pc=0x0c06bdeau; return 0; }
r[0]+=0xfffffffbu;
goto P_0c06bdec;
P_0c06bdec: /* original 04ec, guest PC 0x0c06bdec */
if(!s->budget--) { s->failed_pc=0x0c06bdecu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bdee;
P_0c06bdee: /* original 36bc, guest PC 0x0c06bdee */
if(!s->budget--) { s->failed_pc=0x0c06bdeeu; return 0; }
r[6]+=r[11];
goto P_0c06bdf0;
P_0c06bdf0: /* original 6163, guest PC 0x0c06bdf0 */
if(!s->budget--) { s->failed_pc=0x0c06bdf0u; return 0; }
r[1]=r[6];
goto P_0c06bdf2;
P_0c06bdf2: /* original 430b, guest PC 0x0c06bdf2 */
if(!s->budget--) { s->failed_pc=0x0c06bdf2u; return 0; }
target=r[3];
r[16]=code_base|0x0c06bdf6u;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bdf6u) { target=s->pc; goto dispatch; }
goto P_0c06bdf6;
P_0c06bdf4: /* original 6043, guest PC 0x0c06bdf4 */
if(!s->budget--) { s->failed_pc=0x0c06bdf4u; return 0; }
r[0]=r[4];
goto P_0c06bdf6;
P_0c06bdf6: /* original 6c03, guest PC 0x0c06bdf6 */
if(!s->budget--) { s->failed_pc=0x0c06bdf6u; return 0; }
r[12]=r[0];
goto P_0c06bdf8;
P_0c06bdf8: /* original 6d63, guest PC 0x0c06bdf8 */
if(!s->budget--) { s->failed_pc=0x0c06bdf8u; return 0; }
r[13]=r[6];
goto P_0c06bdfa;
P_0c06bdfa: /* original 04c7, guest PC 0x0c06bdfa */
if(!s->budget--) { s->failed_pc=0x0c06bdfau; return 0; }
r[19]=r[4]*r[12];
goto P_0c06bdfc;
P_0c06bdfc: /* original 9048, guest PC 0x0c06bdfc */
if(!s->budget--) { s->failed_pc=0x0c06bdfcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06be90u,2);
goto P_0c06bdfe;
P_0c06bdfe: /* original 041a, guest PC 0x0c06bdfe */
if(!s->budget--) { s->failed_pc=0x0c06bdfeu; return 0; }
r[4]=r[19];
goto P_0c06be00;
P_0c06be00: /* original 3d48, guest PC 0x0c06be00 */
if(!s->budget--) { s->failed_pc=0x0c06be00u; return 0; }
r[13]-=r[4];
goto P_0c06be02;
P_0c06be02: /* original 0ed4, guest PC 0x0c06be02 */
if(!s->budget--) { s->failed_pc=0x0c06be02u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c06be04;
P_0c06be04: /* original 65d3, guest PC 0x0c06be04 */
if(!s->budget--) { s->failed_pc=0x0c06be04u; return 0; }
r[5]=r[13];
goto P_0c06be06;
P_0c06be06: /* original 54f2, guest PC 0x0c06be06 */
if(!s->budget--) { s->failed_pc=0x0c06be06u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c06be08;
P_0c06be08: /* original d325, guest PC 0x0c06be08 */
if(!s->budget--) { s->failed_pc=0x0c06be08u; return 0; }
r[3]=read(ram,0x0c06bea0u,4);
goto P_0c06be0a;
P_0c06be0a: /* original 430b, guest PC 0x0c06be0a */
if(!s->budget--) { s->failed_pc=0x0c06be0au; return 0; }
target=r[3];
r[16]=code_base|0x0c06be0eu;
r[4]+=0x00000027u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06be0eu) { target=s->pc; goto dispatch; }
goto P_0c06be0e;
P_0c06be0c: /* original 7427, guest PC 0x0c06be0c */
if(!s->budget--) { s->failed_pc=0x0c06be0cu; return 0; }
r[4]+=0x00000027u;
goto P_0c06be0e;
P_0c06be0e: /* original 53f9, guest PC 0x0c06be0e */
if(!s->budget--) { s->failed_pc=0x0c06be0eu; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c06be10;
P_0c06be10: /* original 903f, guest PC 0x0c06be10 */
if(!s->budget--) { s->failed_pc=0x0c06be10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06be92u,2);
goto P_0c06be12;
P_0c06be12: /* original 04ec, guest PC 0x0c06be12 */
if(!s->budget--) { s->failed_pc=0x0c06be12u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06be14;
P_0c06be14: /* original 7008, guest PC 0x0c06be14 */
if(!s->budget--) { s->failed_pc=0x0c06be14u; return 0; }
r[0]+=0x00000008u;
goto P_0c06be16;
P_0c06be16: /* original 05ec, guest PC 0x0c06be16 */
if(!s->budget--) { s->failed_pc=0x0c06be16u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06be18;
P_0c06be18: /* original 23b2, guest PC 0x0c06be18 */
if(!s->budget--) { s->failed_pc=0x0c06be18u; return 0; }
write(ram,r[3],r[11],4);
goto P_0c06be1a;
P_0c06be1a: /* original 34cc, guest PC 0x0c06be1a */
if(!s->budget--) { s->failed_pc=0x0c06be1au; return 0; }
r[4]+=r[12];
goto P_0c06be1c;
P_0c06be1c: /* original 63f2, guest PC 0x0c06be1c */
if(!s->budget--) { s->failed_pc=0x0c06be1cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06be1e;
P_0c06be1e: /* original 2342, guest PC 0x0c06be1e */
if(!s->budget--) { s->failed_pc=0x0c06be1eu; return 0; }
write(ram,r[3],r[4],4);
goto P_0c06be20;
P_0c06be20: /* original 53f1, guest PC 0x0c06be20 */
if(!s->budget--) { s->failed_pc=0x0c06be20u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06be22;
P_0c06be22: /* original 7f0c, guest PC 0x0c06be22 */
if(!s->budget--) { s->failed_pc=0x0c06be22u; return 0; }
r[15]+=0x0000000cu;
goto P_0c06be24;
P_0c06be24: /* original 4f16, guest PC 0x0c06be24 */
if(!s->budget--) { s->failed_pc=0x0c06be24u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c06be26;
P_0c06be26: /* original 2352, guest PC 0x0c06be26 */
if(!s->budget--) { s->failed_pc=0x0c06be26u; return 0; }
write(ram,r[3],r[5],4);
goto P_0c06be28;
P_0c06be28: /* original 4f26, guest PC 0x0c06be28 */
if(!s->budget--) { s->failed_pc=0x0c06be28u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06be2a;
P_0c06be2a: /* original 6bf6, guest PC 0x0c06be2a */
if(!s->budget--) { s->failed_pc=0x0c06be2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06be2c;
P_0c06be2c: /* original 6cf6, guest PC 0x0c06be2c */
if(!s->budget--) { s->failed_pc=0x0c06be2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06be2e;
P_0c06be2e: /* original 6df6, guest PC 0x0c06be2e */
if(!s->budget--) { s->failed_pc=0x0c06be2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06be30;
P_0c06be30: /* original 000b, guest PC 0x0c06be30 */
if(!s->budget--) { s->failed_pc=0x0c06be30u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06be32: /* original 6ef6, guest PC 0x0c06be32 */
if(!s->budget--) { s->failed_pc=0x0c06be32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06be34;
P_0c06be34: /* original 4f22, guest PC 0x0c06be34 */
if(!s->budget--) { s->failed_pc=0x0c06be34u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06be36;
P_0c06be36: /* original e300, guest PC 0x0c06be36 */
if(!s->budget--) { s->failed_pc=0x0c06be36u; return 0; }
r[3]=0x00000000u;
goto P_0c06be38;
P_0c06be38: /* original 6233, guest PC 0x0c06be38 */
if(!s->budget--) { s->failed_pc=0x0c06be38u; return 0; }
r[2]=r[3];
goto P_0c06be3a;
P_0c06be3a: /* original 6523, guest PC 0x0c06be3a */
if(!s->budget--) { s->failed_pc=0x0c06be3au; return 0; }
r[5]=r[2];
goto P_0c06be3c;
P_0c06be3c: /* original 7ffc, guest PC 0x0c06be3c */
if(!s->budget--) { s->failed_pc=0x0c06be3cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06be3e;
P_0c06be3e: /* original 2f42, guest PC 0x0c06be3e */
if(!s->budget--) { s->failed_pc=0x0c06be3eu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06be40;
P_0c06be40: /* original 9028, guest PC 0x0c06be40 */
if(!s->budget--) { s->failed_pc=0x0c06be40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06be94u,2);
goto P_0c06be42;
P_0c06be42: /* original d415, guest PC 0x0c06be42 */
if(!s->budget--) { s->failed_pc=0x0c06be42u; return 0; }
r[4]=read(ram,0x0c06be98u,4);
goto P_0c06be44;
P_0c06be44: /* original 0434, guest PC 0x0c06be44 */
if(!s->budget--) { s->failed_pc=0x0c06be44u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c06be46;
P_0c06be46: /* original 70ff, guest PC 0x0c06be46 */
if(!s->budget--) { s->failed_pc=0x0c06be46u; return 0; }
r[0]+=0xffffffffu;
goto P_0c06be48;
P_0c06be48: /* original 0424, guest PC 0x0c06be48 */
if(!s->budget--) { s->failed_pc=0x0c06be48u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c06be4a;
P_0c06be4a: /* original d315, guest PC 0x0c06be4a */
if(!s->budget--) { s->failed_pc=0x0c06be4au; return 0; }
r[3]=read(ram,0x0c06bea0u,4);
goto P_0c06be4c;
P_0c06be4c: /* original 64f2, guest PC 0x0c06be4c */
if(!s->budget--) { s->failed_pc=0x0c06be4cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06be4e;
P_0c06be4e: /* original 430b, guest PC 0x0c06be4e */
if(!s->budget--) { s->failed_pc=0x0c06be4eu; return 0; }
target=r[3];
r[16]=code_base|0x0c06be52u;
r[4]+=0x0000002bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06be52u) { target=s->pc; goto dispatch; }
goto P_0c06be52;
P_0c06be50: /* original 742b, guest PC 0x0c06be50 */
if(!s->budget--) { s->failed_pc=0x0c06be50u; return 0; }
r[4]+=0x0000002bu;
goto P_0c06be52;
P_0c06be52: /* original 64f2, guest PC 0x0c06be52 */
if(!s->budget--) { s->failed_pc=0x0c06be52u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06be54;
P_0c06be54: /* original 7f04, guest PC 0x0c06be54 */
if(!s->budget--) { s->failed_pc=0x0c06be54u; return 0; }
r[15]+=0x00000004u;
goto P_0c06be56;
P_0c06be56: /* original d312, guest PC 0x0c06be56 */
if(!s->budget--) { s->failed_pc=0x0c06be56u; return 0; }
r[3]=read(ram,0x0c06bea0u,4);
goto P_0c06be58;
P_0c06be58: /* original e500, guest PC 0x0c06be58 */
if(!s->budget--) { s->failed_pc=0x0c06be58u; return 0; }
r[5]=0x00000000u;
goto P_0c06be5a;
P_0c06be5a: /* original 742a, guest PC 0x0c06be5a */
if(!s->budget--) { s->failed_pc=0x0c06be5au; return 0; }
r[4]+=0x0000002au;
goto P_0c06be5c;
P_0c06be5c: /* original 432b, guest PC 0x0c06be5c */
if(!s->budget--) { s->failed_pc=0x0c06be5cu; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c06be5e: /* original 4f26, guest PC 0x0c06be5e */
if(!s->budget--) { s->failed_pc=0x0c06be5eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06be60;
P_0c06be60: /* original 2fe6, guest PC 0x0c06be60 */
if(!s->budget--) { s->failed_pc=0x0c06be60u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06be62;
P_0c06be62: /* original 6e53, guest PC 0x0c06be62 */
if(!s->budget--) { s->failed_pc=0x0c06be62u; return 0; }
r[14]=r[5];
goto P_0c06be64;
P_0c06be64: /* original 7ffc, guest PC 0x0c06be64 */
if(!s->budget--) { s->failed_pc=0x0c06be64u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06be66;
P_0c06be66: /* original 63e3, guest PC 0x0c06be66 */
if(!s->budget--) { s->failed_pc=0x0c06be66u; return 0; }
r[3]=r[14];
goto P_0c06be68;
P_0c06be68: /* original 2f42, guest PC 0x0c06be68 */
if(!s->budget--) { s->failed_pc=0x0c06be68u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06be6a;
P_0c06be6a: /* original d40b, guest PC 0x0c06be6a */
if(!s->budget--) { s->failed_pc=0x0c06be6au; return 0; }
r[4]=read(ram,0x0c06be98u,4);
goto P_0c06be6c;
P_0c06be6c: /* original 9013, guest PC 0x0c06be6c */
if(!s->budget--) { s->failed_pc=0x0c06be6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06be96u,2);
goto P_0c06be6e;
P_0c06be6e: /* original 054c, guest PC 0x0c06be6e */
if(!s->budget--) { s->failed_pc=0x0c06be6eu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06be70;
P_0c06be70: /* original 7014, guest PC 0x0c06be70 */
if(!s->budget--) { s->failed_pc=0x0c06be70u; return 0; }
r[0]+=0x00000014u;
goto P_0c06be72;
P_0c06be72: /* original 064c, guest PC 0x0c06be72 */
if(!s->budget--) { s->failed_pc=0x0c06be72u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06be74;
P_0c06be74: /* original 3358, guest PC 0x0c06be74 */
if(!s->budget--) { s->failed_pc=0x0c06be74u; return 0; }
r[3]-=r[5];
goto P_0c06be76;
P_0c06be76: /* original 6533, guest PC 0x0c06be76 */
if(!s->budget--) { s->failed_pc=0x0c06be76u; return 0; }
r[5]=r[3];
goto P_0c06be78;
P_0c06be78: /* original 365c, guest PC 0x0c06be78 */
if(!s->budget--) { s->failed_pc=0x0c06be78u; return 0; }
r[6]+=r[5];
goto P_0c06be7a;
P_0c06be7a: /* original 0464, guest PC 0x0c06be7a */
if(!s->budget--) { s->failed_pc=0x0c06be7au; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c06be7c;
P_0c06be7c: /* original 70ec, guest PC 0x0c06be7c */
if(!s->budget--) { s->failed_pc=0x0c06be7cu; return 0; }
r[0]+=0xffffffecu;
goto P_0c06be7e;
P_0c06be7e: /* original 04e4, guest PC 0x0c06be7e */
if(!s->budget--) { s->failed_pc=0x0c06be7eu; return 0; }
write(ram,r[4]+r[0],r[14],1);
goto P_0c06be80;
P_0c06be80: /* original 65e3, guest PC 0x0c06be80 */
if(!s->budget--) { s->failed_pc=0x0c06be80u; return 0; }
r[5]=r[14];
goto P_0c06be82;
P_0c06be82: /* original 64f2, guest PC 0x0c06be82 */
if(!s->budget--) { s->failed_pc=0x0c06be82u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06be84;
P_0c06be84: /* original 7f04, guest PC 0x0c06be84 */
if(!s->budget--) { s->failed_pc=0x0c06be84u; return 0; }
r[15]+=0x00000004u;
goto P_0c06be86;
P_0c06be86: /* original d306, guest PC 0x0c06be86 */
if(!s->budget--) { s->failed_pc=0x0c06be86u; return 0; }
r[3]=read(ram,0x0c06bea0u,4);
goto P_0c06be88;
P_0c06be88: /* original 7429, guest PC 0x0c06be88 */
if(!s->budget--) { s->failed_pc=0x0c06be88u; return 0; }
r[4]+=0x00000029u;
goto P_0c06be8a;
P_0c06be8a: /* original 432b, guest PC 0x0c06be8a */
if(!s->budget--) { s->failed_pc=0x0c06be8au; return 0; }
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
P_0c06be8c: /* original 6ef6, guest PC 0x0c06be8c */
if(!s->budget--) { s->failed_pc=0x0c06be8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06be8eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06be8eu; return 0; } return 1;
P_0c06bf54: /* original 2fe6, guest PC 0x0c06bf54 */
if(!s->budget--) { s->failed_pc=0x0c06bf54u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06bf56;
P_0c06bf56: /* original 2fd6, guest PC 0x0c06bf56 */
if(!s->budget--) { s->failed_pc=0x0c06bf56u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06bf58;
P_0c06bf58: /* original 2fc6, guest PC 0x0c06bf58 */
if(!s->budget--) { s->failed_pc=0x0c06bf58u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06bf5a;
P_0c06bf5a: /* original 2fb6, guest PC 0x0c06bf5a */
if(!s->budget--) { s->failed_pc=0x0c06bf5au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06bf5c;
P_0c06bf5c: /* original 2fa6, guest PC 0x0c06bf5c */
if(!s->budget--) { s->failed_pc=0x0c06bf5cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06bf5e;
P_0c06bf5e: /* original 2f96, guest PC 0x0c06bf5e */
if(!s->budget--) { s->failed_pc=0x0c06bf5eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06bf60;
P_0c06bf60: /* original d11b, guest PC 0x0c06bf60 */
if(!s->budget--) { s->failed_pc=0x0c06bf60u; return 0; }
r[1]=read(ram,0x0c06bfd0u,4);
goto P_0c06bf62;
P_0c06bf62: /* original d31a, guest PC 0x0c06bf62 */
if(!s->budget--) { s->failed_pc=0x0c06bf62u; return 0; }
r[3]=read(ram,0x0c06bfccu,4);
goto P_0c06bf64;
P_0c06bf64: /* original 6212, guest PC 0x0c06bf64 */
if(!s->budget--) { s->failed_pc=0x0c06bf64u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c06bf66;
P_0c06bf66: /* original 4f22, guest PC 0x0c06bf66 */
if(!s->budget--) { s->failed_pc=0x0c06bf66u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06bf68;
P_0c06bf68: /* original da17, guest PC 0x0c06bf68 */
if(!s->budget--) { s->failed_pc=0x0c06bf68u; return 0; }
r[10]=read(ram,0x0c06bfc8u,4);
goto P_0c06bf6a;
P_0c06bf6a: /* original 2238, guest PC 0x0c06bf6a */
if(!s->budget--) { s->failed_pc=0x0c06bf6au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c06bf6c;
P_0c06bf6c: /* original 8901, guest PC 0x0c06bf6c */
if(!s->budget--) { s->failed_pc=0x0c06bf6cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06bf72; }
goto P_0c06bf6e;
P_0c06bf6e: /* original a07e, guest PC 0x0c06bf6e */
if(!s->budget--) { s->failed_pc=0x0c06bf6eu; return 0; }
goto P_0c06c06e;
P_0c06bf70: /* original 0009, guest PC 0x0c06bf70 */
if(!s->budget--) { s->failed_pc=0x0c06bf70u; return 0; }
goto P_0c06bf72;
P_0c06bf72: /* original 9021, guest PC 0x0c06bf72 */
if(!s->budget--) { s->failed_pc=0x0c06bf72u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bfb8u,2);
goto P_0c06bf74;
P_0c06bf74: /* original e310, guest PC 0x0c06bf74 */
if(!s->budget--) { s->failed_pc=0x0c06bf74u; return 0; }
r[3]=0x00000010u;
goto P_0c06bf76;
P_0c06bf76: /* original dc17, guest PC 0x0c06bf76 */
if(!s->budget--) { s->failed_pc=0x0c06bf76u; return 0; }
r[12]=read(ram,0x0c06bfd4u,4);
goto P_0c06bf78;
P_0c06bf78: /* original 04ce, guest PC 0x0c06bf78 */
if(!s->budget--) { s->failed_pc=0x0c06bf78u; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c06bf7a;
P_0c06bf7a: /* original 2438, guest PC 0x0c06bf7a */
if(!s->budget--) { s->failed_pc=0x0c06bf7au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c06bf7c;
P_0c06bf7c: /* original 8977, guest PC 0x0c06bf7c */
if(!s->budget--) { s->failed_pc=0x0c06bf7cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c06e; }
goto P_0c06bf7e;
P_0c06bf7e: /* original 62c2, guest PC 0x0c06bf7e */
if(!s->budget--) { s->failed_pc=0x0c06bf7eu; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c06bf80;
P_0c06bf80: /* original d115, guest PC 0x0c06bf80 */
if(!s->budget--) { s->failed_pc=0x0c06bf80u; return 0; }
r[1]=read(ram,0x0c06bfd8u,4);
goto P_0c06bf82;
P_0c06bf82: /* original 3210, guest PC 0x0c06bf82 */
if(!s->budget--) { s->failed_pc=0x0c06bf82u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c06bf84;
P_0c06bf84: /* original 8973, guest PC 0x0c06bf84 */
if(!s->budget--) { s->failed_pc=0x0c06bf84u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c06e; }
goto P_0c06bf86;
P_0c06bf86: /* original d415, guest PC 0x0c06bf86 */
if(!s->budget--) { s->failed_pc=0x0c06bf86u; return 0; }
r[4]=read(ram,0x0c06bfdcu,4);
goto P_0c06bf88;
P_0c06bf88: /* original e201, guest PC 0x0c06bf88 */
if(!s->budget--) { s->failed_pc=0x0c06bf88u; return 0; }
r[2]=0x00000001u;
goto P_0c06bf8a;
P_0c06bf8a: /* original 554a, guest PC 0x0c06bf8a */
if(!s->budget--) { s->failed_pc=0x0c06bf8au; return 0; }
r[5]=read(ram,r[4]+40,4);
goto P_0c06bf8c;
P_0c06bf8c: /* original 544b, guest PC 0x0c06bf8c */
if(!s->budget--) { s->failed_pc=0x0c06bf8cu; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c06bf8e;
P_0c06bf8e: /* original 6552, guest PC 0x0c06bf8e */
if(!s->budget--) { s->failed_pc=0x0c06bf8eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c06bf90;
P_0c06bf90: /* original 6442, guest PC 0x0c06bf90 */
if(!s->budget--) { s->failed_pc=0x0c06bf90u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c06bf92;
P_0c06bf92: /* original 245b, guest PC 0x0c06bf92 */
if(!s->budget--) { s->failed_pc=0x0c06bf92u; return 0; }
r[4]|=r[5];
goto P_0c06bf94;
P_0c06bf94: /* original 2428, guest PC 0x0c06bf94 */
if(!s->budget--) { s->failed_pc=0x0c06bf94u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c06bf96;
P_0c06bf96: /* original 8b6a, guest PC 0x0c06bf96 */
if(!s->budget--) { s->failed_pc=0x0c06bf96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c06e; }
goto P_0c06bf98;
P_0c06bf98: /* original 900f, guest PC 0x0c06bf98 */
if(!s->budget--) { s->failed_pc=0x0c06bf98u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bfbau,2);
goto P_0c06bf9a;
P_0c06bf9a: /* original de0a, guest PC 0x0c06bf9a */
if(!s->budget--) { s->failed_pc=0x0c06bf9au; return 0; }
r[14]=read(ram,0x0c06bfc4u,4);
goto P_0c06bf9c;
P_0c06bf9c: /* original 00ec, guest PC 0x0c06bf9c */
if(!s->budget--) { s->failed_pc=0x0c06bf9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bf9e;
P_0c06bf9e: /* original 8801, guest PC 0x0c06bf9e */
if(!s->budget--) { s->failed_pc=0x0c06bf9eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06bfa0;
P_0c06bfa0: /* original 8f1e, guest PC 0x0c06bfa0 */
if(!s->budget--) { s->failed_pc=0x0c06bfa0u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c06bfe0; }
goto P_0c06bfa4;
P_0c06bfa2: /* original 6403, guest PC 0x0c06bfa2 */
if(!s->budget--) { s->failed_pc=0x0c06bfa2u; return 0; }
r[4]=r[0];
goto P_0c06bfa4;
P_0c06bfa4: /* original b092, guest PC 0x0c06bfa4 */
if(!s->budget--) { s->failed_pc=0x0c06bfa4u; return 0; }
target=code_base|0x0c06c0ccu; r[16]=code_base|0x0c06bfa8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bfa8u) { target=s->pc; goto dispatch; }
goto P_0c06bfa8;
P_0c06bfa6: /* original 0009, guest PC 0x0c06bfa6 */
if(!s->budget--) { s->failed_pc=0x0c06bfa6u; return 0; }
goto P_0c06bfa8;
P_0c06bfa8: /* original a061, guest PC 0x0c06bfa8 */
if(!s->budget--) { s->failed_pc=0x0c06bfa8u; return 0; }
goto P_0c06c06e;
P_0c06bfaa: /* original 0009, guest PC 0x0c06bfaa */
if(!s->budget--) { s->failed_pc=0x0c06bfaau; return 0; }
if(!vf3_matrix_family(0x0c06bfacu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06bfacu; return 0; } return 1;
P_0c06bfe0: /* original 9062, guest PC 0x0c06bfe0 */
if(!s->budget--) { s->failed_pc=0x0c06bfe0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c0a8u,2);
goto P_0c06bfe2;
P_0c06bfe2: /* original 04ec, guest PC 0x0c06bfe2 */
if(!s->budget--) { s->failed_pc=0x0c06bfe2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bfe4;
P_0c06bfe4: /* original 7001, guest PC 0x0c06bfe4 */
if(!s->budget--) { s->failed_pc=0x0c06bfe4u; return 0; }
r[0]+=0x00000001u;
goto P_0c06bfe6;
P_0c06bfe6: /* original b04a, guest PC 0x0c06bfe6 */
if(!s->budget--) { s->failed_pc=0x0c06bfe6u; return 0; }
target=code_base|0x0c06c07eu; r[16]=code_base|0x0c06bfeau;
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06bfeau) { target=s->pc; goto dispatch; }
goto P_0c06bfea;
P_0c06bfe8: /* original 05ec, guest PC 0x0c06bfe8 */
if(!s->budget--) { s->failed_pc=0x0c06bfe8u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bfea;
P_0c06bfea: /* original 8801, guest PC 0x0c06bfea */
if(!s->budget--) { s->failed_pc=0x0c06bfeau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06bfec;
P_0c06bfec: /* original 6d03, guest PC 0x0c06bfec */
if(!s->budget--) { s->failed_pc=0x0c06bfecu; return 0; }
r[13]=r[0];
goto P_0c06bfee;
P_0c06bfee: /* original 8d05, guest PC 0x0c06bfee */
if(!s->budget--) { s->failed_pc=0x0c06bfeeu; return 0; }
cond=r[17]&1u;
r[4]=0x00000027u;
if(cond) { goto P_0c06bffc; }
goto P_0c06bff2;
P_0c06bff0: /* original e427, guest PC 0x0c06bff0 */
if(!s->budget--) { s->failed_pc=0x0c06bff0u; return 0; }
r[4]=0x00000027u;
goto P_0c06bff2;
P_0c06bff2: /* original 60d3, guest PC 0x0c06bff2 */
if(!s->budget--) { s->failed_pc=0x0c06bff2u; return 0; }
r[0]=r[13];
goto P_0c06bff4;
P_0c06bff4: /* original 8803, guest PC 0x0c06bff4 */
if(!s->budget--) { s->failed_pc=0x0c06bff4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c06bff6;
P_0c06bff6: /* original 890d, guest PC 0x0c06bff6 */
if(!s->budget--) { s->failed_pc=0x0c06bff6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c014; }
goto P_0c06bff8;
P_0c06bff8: /* original a00c, guest PC 0x0c06bff8 */
if(!s->budget--) { s->failed_pc=0x0c06bff8u; return 0; }
goto P_0c06c014;
P_0c06bffa: /* original 0009, guest PC 0x0c06bffa */
if(!s->budget--) { s->failed_pc=0x0c06bffau; return 0; }
goto P_0c06bffc;
P_0c06bffc: /* original e320, guest PC 0x0c06bffc */
if(!s->budget--) { s->failed_pc=0x0c06bffcu; return 0; }
r[3]=0x00000020u;
goto P_0c06bffe;
P_0c06bffe: /* original 9554, guest PC 0x0c06bffe */
if(!s->budget--) { s->failed_pc=0x0c06bffeu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c0aau,2);
goto P_0c06c000;
P_0c06c000: /* original e617, guest PC 0x0c06c000 */
if(!s->budget--) { s->failed_pc=0x0c06c000u; return 0; }
r[6]=0x00000017u;
goto P_0c06c002;
P_0c06c002: /* original 6b43, guest PC 0x0c06c002 */
if(!s->budget--) { s->failed_pc=0x0c06c002u; return 0; }
r[11]=r[4];
goto P_0c06c004;
P_0c06c004: /* original e918, guest PC 0x0c06c004 */
if(!s->budget--) { s->failed_pc=0x0c06c004u; return 0; }
r[9]=0x00000018u;
goto P_0c06c006;
P_0c06c006: /* original 2f36, guest PC 0x0c06c006 */
if(!s->budget--) { s->failed_pc=0x0c06c006u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c008;
P_0c06c008: /* original d22a, guest PC 0x0c06c008 */
if(!s->budget--) { s->failed_pc=0x0c06c008u; return 0; }
r[2]=read(ram,0x0c06c0b4u,4);
goto P_0c06c00a;
P_0c06c00a: /* original e703, guest PC 0x0c06c00a */
if(!s->budget--) { s->failed_pc=0x0c06c00au; return 0; }
r[7]=0x00000003u;
goto P_0c06c00c;
P_0c06c00c: /* original 420b, guest PC 0x0c06c00c */
if(!s->budget--) { s->failed_pc=0x0c06c00cu; return 0; }
target=r[2];
r[16]=code_base|0x0c06c010u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c010u) { target=s->pc; goto dispatch; }
goto P_0c06c010;
P_0c06c00e: /* original 64a3, guest PC 0x0c06c00e */
if(!s->budget--) { s->failed_pc=0x0c06c00eu; return 0; }
r[4]=r[10];
goto P_0c06c010;
P_0c06c010: /* original a002, guest PC 0x0c06c010 */
if(!s->budget--) { s->failed_pc=0x0c06c010u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c018;
P_0c06c012: /* original 7f04, guest PC 0x0c06c012 */
if(!s->budget--) { s->failed_pc=0x0c06c012u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c014;
P_0c06c014: /* original 6b43, guest PC 0x0c06c014 */
if(!s->budget--) { s->failed_pc=0x0c06c014u; return 0; }
r[11]=r[4];
goto P_0c06c016;
P_0c06c016: /* original e914, guest PC 0x0c06c016 */
if(!s->budget--) { s->failed_pc=0x0c06c016u; return 0; }
r[9]=0x00000014u;
goto P_0c06c018;
P_0c06c018: /* original d027, guest PC 0x0c06c018 */
if(!s->budget--) { s->failed_pc=0x0c06c018u; return 0; }
r[0]=read(ram,0x0c06c0b8u,4);
goto P_0c06c01a;
P_0c06c01a: /* original 65d3, guest PC 0x0c06c01a */
if(!s->budget--) { s->failed_pc=0x0c06c01au; return 0; }
r[5]=r[13];
goto P_0c06c01c;
P_0c06c01c: /* original 2dd8, guest PC 0x0c06c01c */
if(!s->budget--) { s->failed_pc=0x0c06c01cu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c06c01e;
P_0c06c01e: /* original 4508, guest PC 0x0c06c01e */
if(!s->budget--) { s->failed_pc=0x0c06c01eu; return 0; }
r[5]<<=2;
goto P_0c06c020;
P_0c06c020: /* original 8f08, guest PC 0x0c06c020 */
if(!s->budget--) { s->failed_pc=0x0c06c020u; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[5]+r[0],4);
if(!cond) { goto P_0c06c034; }
goto P_0c06c024;
P_0c06c022: /* original 055e, guest PC 0x0c06c022 */
if(!s->budget--) { s->failed_pc=0x0c06c022u; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c06c024;
P_0c06c024: /* original 62c2, guest PC 0x0c06c024 */
if(!s->budget--) { s->failed_pc=0x0c06c024u; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c06c026;
P_0c06c026: /* original d325, guest PC 0x0c06c026 */
if(!s->budget--) { s->failed_pc=0x0c06c026u; return 0; }
r[3]=read(ram,0x0c06c0bcu,4);
goto P_0c06c028;
P_0c06c028: /* original 2238, guest PC 0x0c06c028 */
if(!s->budget--) { s->failed_pc=0x0c06c028u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c06c02a;
P_0c06c02a: /* original 8910, guest PC 0x0c06c02a */
if(!s->budget--) { s->failed_pc=0x0c06c02au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c04e; }
goto P_0c06c02c;
P_0c06c02c: /* original 51c1, guest PC 0x0c06c02c */
if(!s->budget--) { s->failed_pc=0x0c06c02cu; return 0; }
r[1]=read(ram,r[12]+4,4);
goto P_0c06c02e;
P_0c06c02e: /* original d224, guest PC 0x0c06c02e */
if(!s->budget--) { s->failed_pc=0x0c06c02eu; return 0; }
r[2]=read(ram,0x0c06c0c0u,4);
goto P_0c06c030;
P_0c06c030: /* original a00d, guest PC 0x0c06c030 */
if(!s->budget--) { s->failed_pc=0x0c06c030u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c06c04e;
P_0c06c032: /* original 2128, guest PC 0x0c06c032 */
if(!s->budget--) { s->failed_pc=0x0c06c032u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c06c034;
P_0c06c034: /* original e307, guest PC 0x0c06c034 */
if(!s->budget--) { s->failed_pc=0x0c06c034u; return 0; }
r[3]=0x00000007u;
goto P_0c06c036;
P_0c06c036: /* original 62b3, guest PC 0x0c06c036 */
if(!s->budget--) { s->failed_pc=0x0c06c036u; return 0; }
r[2]=r[11];
goto P_0c06c038;
P_0c06c038: /* original 6493, guest PC 0x0c06c038 */
if(!s->budget--) { s->failed_pc=0x0c06c038u; return 0; }
r[4]=r[9];
goto P_0c06c03a;
P_0c06c03a: /* original 423d, guest PC 0x0c06c03a */
if(!s->budget--) { s->failed_pc=0x0c06c03au; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c06c03c;
P_0c06c03c: /* original 4400, guest PC 0x0c06c03c */
if(!s->budget--) { s->failed_pc=0x0c06c03cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c03e;
P_0c06c03e: /* original 242b, guest PC 0x0c06c03e */
if(!s->budget--) { s->failed_pc=0x0c06c03eu; return 0; }
r[4]|=r[2];
goto P_0c06c040;
P_0c06c040: /* original e100, guest PC 0x0c06c040 */
if(!s->budget--) { s->failed_pc=0x0c06c040u; return 0; }
r[1]=0x00000000u;
goto P_0c06c042;
P_0c06c042: /* original 6713, guest PC 0x0c06c042 */
if(!s->budget--) { s->failed_pc=0x0c06c042u; return 0; }
r[7]=r[1];
goto P_0c06c044;
P_0c06c044: /* original 2f16, guest PC 0x0c06c044 */
if(!s->budget--) { s->failed_pc=0x0c06c044u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c046;
P_0c06c046: /* original d21f, guest PC 0x0c06c046 */
if(!s->budget--) { s->failed_pc=0x0c06c046u; return 0; }
r[2]=read(ram,0x0c06c0c4u,4);
goto P_0c06c048;
P_0c06c048: /* original 420b, guest PC 0x0c06c048 */
if(!s->budget--) { s->failed_pc=0x0c06c048u; return 0; }
target=r[2];
r[16]=code_base|0x0c06c04cu;
r[6]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c04cu) { target=s->pc; goto dispatch; }
goto P_0c06c04c;
P_0c06c04a: /* original 66a3, guest PC 0x0c06c04a */
if(!s->budget--) { s->failed_pc=0x0c06c04au; return 0; }
r[6]=r[10];
goto P_0c06c04c;
P_0c06c04c: /* original 7f04, guest PC 0x0c06c04c */
if(!s->budget--) { s->failed_pc=0x0c06c04cu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c04e;
P_0c06c04e: /* original 65b3, guest PC 0x0c06c04e */
if(!s->budget--) { s->failed_pc=0x0c06c04eu; return 0; }
r[5]=r[11];
goto P_0c06c050;
P_0c06c050: /* original e61e, guest PC 0x0c06c050 */
if(!s->budget--) { s->failed_pc=0x0c06c050u; return 0; }
r[6]=0x0000001eu;
goto P_0c06c052;
P_0c06c052: /* original e703, guest PC 0x0c06c052 */
if(!s->budget--) { s->failed_pc=0x0c06c052u; return 0; }
r[7]=0x00000003u;
goto P_0c06c054;
P_0c06c054: /* original b1bc, guest PC 0x0c06c054 */
if(!s->budget--) { s->failed_pc=0x0c06c054u; return 0; }
target=code_base|0x0c06c3d0u; r[16]=code_base|0x0c06c058u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c058u) { target=s->pc; goto dispatch; }
goto P_0c06c058;
P_0c06c056: /* original 6493, guest PC 0x0c06c056 */
if(!s->budget--) { s->failed_pc=0x0c06c056u; return 0; }
r[4]=r[9];
goto P_0c06c058;
P_0c06c058: /* original 9026, guest PC 0x0c06c058 */
if(!s->budget--) { s->failed_pc=0x0c06c058u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c0a8u,2);
goto P_0c06c05a;
P_0c06c05a: /* original e62b, guest PC 0x0c06c05a */
if(!s->budget--) { s->failed_pc=0x0c06c05au; return 0; }
r[6]=0x0000002bu;
goto P_0c06c05c;
P_0c06c05c: /* original e700, guest PC 0x0c06c05c */
if(!s->budget--) { s->failed_pc=0x0c06c05cu; return 0; }
r[7]=0x00000000u;
goto P_0c06c05e;
P_0c06c05e: /* original 04ec, guest PC 0x0c06c05e */
if(!s->budget--) { s->failed_pc=0x0c06c05eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c060;
P_0c06c060: /* original b0d2, guest PC 0x0c06c060 */
if(!s->budget--) { s->failed_pc=0x0c06c060u; return 0; }
target=code_base|0x0c06c208u; r[16]=code_base|0x0c06c064u;
r[5]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c064u) { target=s->pc; goto dispatch; }
goto P_0c06c064;
P_0c06c062: /* original 6563, guest PC 0x0c06c062 */
if(!s->budget--) { s->failed_pc=0x0c06c062u; return 0; }
r[5]=r[6];
goto P_0c06c064;
P_0c06c064: /* original 9022, guest PC 0x0c06c064 */
if(!s->budget--) { s->failed_pc=0x0c06c064u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c0acu,2);
goto P_0c06c066;
P_0c06c066: /* original e52d, guest PC 0x0c06c066 */
if(!s->budget--) { s->failed_pc=0x0c06c066u; return 0; }
r[5]=0x0000002du;
goto P_0c06c068;
P_0c06c068: /* original 06ec, guest PC 0x0c06c068 */
if(!s->budget--) { s->failed_pc=0x0c06c068u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c06a;
P_0c06c06a: /* original b1da, guest PC 0x0c06c06a */
if(!s->budget--) { s->failed_pc=0x0c06c06au; return 0; }
target=code_base|0x0c06c422u; r[16]=code_base|0x0c06c06eu;
r[4]=0x00000015u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c06eu) { target=s->pc; goto dispatch; }
goto P_0c06c06e;
P_0c06c06c: /* original e415, guest PC 0x0c06c06c */
if(!s->budget--) { s->failed_pc=0x0c06c06cu; return 0; }
r[4]=0x00000015u;
goto P_0c06c06e;
P_0c06c06e: /* original 4f26, guest PC 0x0c06c06e */
if(!s->budget--) { s->failed_pc=0x0c06c06eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c070;
P_0c06c070: /* original 69f6, guest PC 0x0c06c070 */
if(!s->budget--) { s->failed_pc=0x0c06c070u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06c072;
P_0c06c072: /* original 6af6, guest PC 0x0c06c072 */
if(!s->budget--) { s->failed_pc=0x0c06c072u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06c074;
P_0c06c074: /* original 6bf6, guest PC 0x0c06c074 */
if(!s->budget--) { s->failed_pc=0x0c06c074u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06c076;
P_0c06c076: /* original 6cf6, guest PC 0x0c06c076 */
if(!s->budget--) { s->failed_pc=0x0c06c076u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06c078;
P_0c06c078: /* original 6df6, guest PC 0x0c06c078 */
if(!s->budget--) { s->failed_pc=0x0c06c078u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06c07a;
P_0c06c07a: /* original 000b, guest PC 0x0c06c07a */
if(!s->budget--) { s->failed_pc=0x0c06c07au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06c07c: /* original 6ef6, guest PC 0x0c06c07c */
if(!s->budget--) { s->failed_pc=0x0c06c07cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06c07eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
