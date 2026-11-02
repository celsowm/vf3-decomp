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
int vf3_away_batch137_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0aac14u: goto P_0c0aac14;
case 0x0c0aac16u: goto P_0c0aac16;
case 0x0c0aac18u: goto P_0c0aac18;
case 0x0c0aac1au: goto P_0c0aac1a;
case 0x0c0aac1cu: goto P_0c0aac1c;
case 0x0c0aac1eu: goto P_0c0aac1e;
case 0x0c0aac20u: goto P_0c0aac20;
case 0x0c0aac22u: goto P_0c0aac22;
case 0x0c0aac24u: goto P_0c0aac24;
case 0x0c0aac26u: goto P_0c0aac26;
case 0x0c0aac28u: goto P_0c0aac28;
case 0x0c0aac2au: goto P_0c0aac2a;
case 0x0c0aac2cu: goto P_0c0aac2c;
case 0x0c0aac2eu: goto P_0c0aac2e;
case 0x0c0aac30u: goto P_0c0aac30;
case 0x0c0aac32u: goto P_0c0aac32;
case 0x0c0aac34u: goto P_0c0aac34;
case 0x0c0aac36u: goto P_0c0aac36;
case 0x0c0aac38u: goto P_0c0aac38;
case 0x0c0aac3au: goto P_0c0aac3a;
case 0x0c0aac3cu: goto P_0c0aac3c;
case 0x0c0aac3eu: goto P_0c0aac3e;
case 0x0c0aac40u: goto P_0c0aac40;
case 0x0c0aac42u: goto P_0c0aac42;
case 0x0c0aac44u: goto P_0c0aac44;
case 0x0c0aac46u: goto P_0c0aac46;
case 0x0c0aac48u: goto P_0c0aac48;
case 0x0c0aac4au: goto P_0c0aac4a;
case 0x0c0aac4cu: goto P_0c0aac4c;
case 0x0c0aac4eu: goto P_0c0aac4e;
case 0x0c0aac50u: goto P_0c0aac50;
case 0x0c0aac52u: goto P_0c0aac52;
case 0x0c0aac54u: goto P_0c0aac54;
case 0x0c0aac56u: goto P_0c0aac56;
case 0x0c0aac58u: goto P_0c0aac58;
case 0x0c0aac5au: goto P_0c0aac5a;
case 0x0c0aac5cu: goto P_0c0aac5c;
case 0x0c0aac5eu: goto P_0c0aac5e;
case 0x0c0aac60u: goto P_0c0aac60;
case 0x0c0aac62u: goto P_0c0aac62;
case 0x0c0aac64u: goto P_0c0aac64;
case 0x0c0aac66u: goto P_0c0aac66;
case 0x0c0aac68u: goto P_0c0aac68;
case 0x0c0aac6au: goto P_0c0aac6a;
case 0x0c0aac6cu: goto P_0c0aac6c;
case 0x0c0aac6eu: goto P_0c0aac6e;
case 0x0c0aac70u: goto P_0c0aac70;
case 0x0c0aac72u: goto P_0c0aac72;
case 0x0c0aac74u: goto P_0c0aac74;
case 0x0c0aac76u: goto P_0c0aac76;
case 0x0c0aac78u: goto P_0c0aac78;
case 0x0c0aac7au: goto P_0c0aac7a;
case 0x0c0aac7cu: goto P_0c0aac7c;
case 0x0c0aac7eu: goto P_0c0aac7e;
case 0x0c0aac80u: goto P_0c0aac80;
case 0x0c0aac82u: goto P_0c0aac82;
case 0x0c0aac84u: goto P_0c0aac84;
case 0x0c0aac86u: goto P_0c0aac86;
case 0x0c0aac88u: goto P_0c0aac88;
case 0x0c0aac8au: goto P_0c0aac8a;
case 0x0c0aac8cu: goto P_0c0aac8c;
case 0x0c0aac8eu: goto P_0c0aac8e;
case 0x0c0aac90u: goto P_0c0aac90;
case 0x0c0aac92u: goto P_0c0aac92;
case 0x0c0aac94u: goto P_0c0aac94;
case 0x0c0aac96u: goto P_0c0aac96;
case 0x0c0aac98u: goto P_0c0aac98;
case 0x0c0aac9au: goto P_0c0aac9a;
case 0x0c0aac9cu: goto P_0c0aac9c;
case 0x0c0aac9eu: goto P_0c0aac9e;
case 0x0c0aaca0u: goto P_0c0aaca0;
case 0x0c0aaca2u: goto P_0c0aaca2;
case 0x0c0aaca4u: goto P_0c0aaca4;
case 0x0c0aaca6u: goto P_0c0aaca6;
case 0x0c0aaca8u: goto P_0c0aaca8;
case 0x0c0aacaau: goto P_0c0aacaa;
case 0x0c0aacacu: goto P_0c0aacac;
case 0x0c0aacaeu: goto P_0c0aacae;
case 0x0c0aacb0u: goto P_0c0aacb0;
case 0x0c0aacb2u: goto P_0c0aacb2;
case 0x0c0aacb4u: goto P_0c0aacb4;
case 0x0c0aacb6u: goto P_0c0aacb6;
case 0x0c0aacb8u: goto P_0c0aacb8;
case 0x0c0aacbau: goto P_0c0aacba;
case 0x0c0aacbcu: goto P_0c0aacbc;
case 0x0c0aacbeu: goto P_0c0aacbe;
case 0x0c0aacc0u: goto P_0c0aacc0;
case 0x0c0aacc2u: goto P_0c0aacc2;
case 0x0c0aacc4u: goto P_0c0aacc4;
case 0x0c0aacc6u: goto P_0c0aacc6;
case 0x0c0aacc8u: goto P_0c0aacc8;
case 0x0c0aaccau: goto P_0c0aacca;
case 0x0c0aacccu: goto P_0c0aaccc;
case 0x0c0aacceu: goto P_0c0aacce;
case 0x0c0aacd0u: goto P_0c0aacd0;
case 0x0c0aacd2u: goto P_0c0aacd2;
case 0x0c0aacd4u: goto P_0c0aacd4;
case 0x0c0aacd6u: goto P_0c0aacd6;
case 0x0c0aacd8u: goto P_0c0aacd8;
case 0x0c0aacdau: goto P_0c0aacda;
case 0x0c0aacdcu: goto P_0c0aacdc;
case 0x0c0aacdeu: goto P_0c0aacde;
case 0x0c0aace0u: goto P_0c0aace0;
case 0x0c0aace2u: goto P_0c0aace2;
case 0x0c0aace4u: goto P_0c0aace4;
case 0x0c0aace6u: goto P_0c0aace6;
case 0x0c0aace8u: goto P_0c0aace8;
case 0x0c0aaceau: goto P_0c0aacea;
case 0x0c0aacecu: goto P_0c0aacec;
case 0x0c0aaceeu: goto P_0c0aacee;
case 0x0c0aacf0u: goto P_0c0aacf0;
case 0x0c0aacf2u: goto P_0c0aacf2;
case 0x0c0aacf4u: goto P_0c0aacf4;
case 0x0c0aacf6u: goto P_0c0aacf6;
case 0x0c0aacf8u: goto P_0c0aacf8;
case 0x0c0aacfau: goto P_0c0aacfa;
case 0x0c0aacfcu: goto P_0c0aacfc;
case 0x0c0aacfeu: goto P_0c0aacfe;
case 0x0c0aad00u: goto P_0c0aad00;
case 0x0c0aad02u: goto P_0c0aad02;
case 0x0c0aad04u: goto P_0c0aad04;
case 0x0c0aad06u: goto P_0c0aad06;
case 0x0c0aad08u: goto P_0c0aad08;
case 0x0c0aad0au: goto P_0c0aad0a;
case 0x0c0aad0cu: goto P_0c0aad0c;
case 0x0c0aad0eu: goto P_0c0aad0e;
case 0x0c0aad10u: goto P_0c0aad10;
case 0x0c0aad12u: goto P_0c0aad12;
case 0x0c0aad14u: goto P_0c0aad14;
case 0x0c0aad16u: goto P_0c0aad16;
case 0x0c0aad18u: goto P_0c0aad18;
case 0x0c0aad1au: goto P_0c0aad1a;
case 0x0c0aad1cu: goto P_0c0aad1c;
case 0x0c0aad1eu: goto P_0c0aad1e;
case 0x0c0aad20u: goto P_0c0aad20;
case 0x0c0aad22u: goto P_0c0aad22;
case 0x0c0aad24u: goto P_0c0aad24;
case 0x0c0aad26u: goto P_0c0aad26;
case 0x0c0aad50u: goto P_0c0aad50;
case 0x0c0aad52u: goto P_0c0aad52;
case 0x0c0aad54u: goto P_0c0aad54;
case 0x0c0aad56u: goto P_0c0aad56;
case 0x0c0aad58u: goto P_0c0aad58;
case 0x0c0aad5au: goto P_0c0aad5a;
case 0x0c0aad5cu: goto P_0c0aad5c;
case 0x0c0aad5eu: goto P_0c0aad5e;
case 0x0c0aad60u: goto P_0c0aad60;
case 0x0c0aad62u: goto P_0c0aad62;
case 0x0c0aad64u: goto P_0c0aad64;
case 0x0c0aad66u: goto P_0c0aad66;
case 0x0c0aad68u: goto P_0c0aad68;
case 0x0c0aad6au: goto P_0c0aad6a;
case 0x0c0aad6cu: goto P_0c0aad6c;
case 0x0c0aad6eu: goto P_0c0aad6e;
case 0x0c0aad70u: goto P_0c0aad70;
case 0x0c0aad72u: goto P_0c0aad72;
case 0x0c0aad74u: goto P_0c0aad74;
case 0x0c0aad76u: goto P_0c0aad76;
case 0x0c0aad78u: goto P_0c0aad78;
case 0x0c0aad7au: goto P_0c0aad7a;
case 0x0c0aad7cu: goto P_0c0aad7c;
case 0x0c0aad7eu: goto P_0c0aad7e;
case 0x0c0aad80u: goto P_0c0aad80;
case 0x0c0aad82u: goto P_0c0aad82;
case 0x0c0aad84u: goto P_0c0aad84;
case 0x0c0aad86u: goto P_0c0aad86;
case 0x0c0aad88u: goto P_0c0aad88;
case 0x0c0aad8au: goto P_0c0aad8a;
case 0x0c0aad8cu: goto P_0c0aad8c;
case 0x0c0aad8eu: goto P_0c0aad8e;
case 0x0c0aad90u: goto P_0c0aad90;
case 0x0c0aad92u: goto P_0c0aad92;
case 0x0c0aad94u: goto P_0c0aad94;
case 0x0c0aad96u: goto P_0c0aad96;
case 0x0c0aad98u: goto P_0c0aad98;
case 0x0c0aad9au: goto P_0c0aad9a;
case 0x0c0aad9cu: goto P_0c0aad9c;
case 0x0c0aad9eu: goto P_0c0aad9e;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c0aac14: /* original 2fe6, guest PC 0x0c0aac14 */
if(!s->budget--) { s->failed_pc=0x0c0aac14u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aac16;
P_0c0aac16: /* original 6e43, guest PC 0x0c0aac16 */
if(!s->budget--) { s->failed_pc=0x0c0aac16u; return 0; }
r[14]=r[4];
goto P_0c0aac18;
P_0c0aac18: /* original 2fd6, guest PC 0x0c0aac18 */
if(!s->budget--) { s->failed_pc=0x0c0aac18u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aac1a;
P_0c0aac1a: /* original 6d63, guest PC 0x0c0aac1a */
if(!s->budget--) { s->failed_pc=0x0c0aac1au; return 0; }
r[13]=r[6];
goto P_0c0aac1c;
P_0c0aac1c: /* original 2fc6, guest PC 0x0c0aac1c */
if(!s->budget--) { s->failed_pc=0x0c0aac1cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aac1e;
P_0c0aac1e: /* original e401, guest PC 0x0c0aac1e */
if(!s->budget--) { s->failed_pc=0x0c0aac1eu; return 0; }
r[4]=0x00000001u;
goto P_0c0aac20;
P_0c0aac20: /* original 4f22, guest PC 0x0c0aac20 */
if(!s->budget--) { s->failed_pc=0x0c0aac20u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aac22;
P_0c0aac22: /* original d343, guest PC 0x0c0aac22 */
if(!s->budget--) { s->failed_pc=0x0c0aac22u; return 0; }
r[3]=read(ram,0x0c0aad30u,4);
goto P_0c0aac24;
P_0c0aac24: /* original e058, guest PC 0x0c0aac24 */
if(!s->budget--) { s->failed_pc=0x0c0aac24u; return 0; }
r[0]=0x00000058u;
goto P_0c0aac26;
P_0c0aac26: /* original 7fe8, guest PC 0x0c0aac26 */
if(!s->budget--) { s->failed_pc=0x0c0aac26u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0aac28;
P_0c0aac28: /* original 1f35, guest PC 0x0c0aac28 */
if(!s->budget--) { s->failed_pc=0x0c0aac28u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c0aac2a;
P_0c0aac2a: /* original 53d1, guest PC 0x0c0aac2a */
if(!s->budget--) { s->failed_pc=0x0c0aac2au; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0aac2c;
P_0c0aac2c: /* original 3342, guest PC 0x0c0aac2c */
if(!s->budget--) { s->failed_pc=0x0c0aac2cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[4])!=0);
goto P_0c0aac2e;
P_0c0aac2e: /* original 8f06, guest PC 0x0c0aac2e */
if(!s->budget--) { s->failed_pc=0x0c0aac2eu; return 0; }
cond=r[17]&1u;
r[12]=read(ram,r[14]+r[0],4);
if(!cond) { goto P_0c0aac3e; }
goto P_0c0aac32;
P_0c0aac30: /* original 0cee, guest PC 0x0c0aac30 */
if(!s->budget--) { s->failed_pc=0x0c0aac30u; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c0aac32;
P_0c0aac32: /* original 50d1, guest PC 0x0c0aac32 */
if(!s->budget--) { s->failed_pc=0x0c0aac32u; return 0; }
r[0]=read(ram,r[13]+4,4);
goto P_0c0aac34;
P_0c0aac34: /* original 8801, guest PC 0x0c0aac34 */
if(!s->budget--) { s->failed_pc=0x0c0aac34u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0aac36;
P_0c0aac36: /* original 8911, guest PC 0x0c0aac36 */
if(!s->budget--) { s->failed_pc=0x0c0aac36u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aac5c; }
goto P_0c0aac38;
P_0c0aac38: /* original 53d1, guest PC 0x0c0aac38 */
if(!s->budget--) { s->failed_pc=0x0c0aac38u; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0aac3a;
P_0c0aac3a: /* original 3346, guest PC 0x0c0aac3a */
if(!s->budget--) { s->failed_pc=0x0c0aac3au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[4])!=0);
goto P_0c0aac3c;
P_0c0aac3c: /* original 892e, guest PC 0x0c0aac3c */
if(!s->budget--) { s->failed_pc=0x0c0aac3cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aac9c; }
goto P_0c0aac3e;
P_0c0aac3e: /* original 62c3, guest PC 0x0c0aac3e */
if(!s->budget--) { s->failed_pc=0x0c0aac3eu; return 0; }
r[2]=r[12];
goto P_0c0aac40;
P_0c0aac40: /* original 7226, guest PC 0x0c0aac40 */
if(!s->budget--) { s->failed_pc=0x0c0aac40u; return 0; }
r[2]+=0x00000026u;
goto P_0c0aac42;
P_0c0aac42: /* original 6321, guest PC 0x0c0aac42 */
if(!s->budget--) { s->failed_pc=0x0c0aac42u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[3]=tmp;
goto P_0c0aac44;
P_0c0aac44: /* original 633d, guest PC 0x0c0aac44 */
if(!s->budget--) { s->failed_pc=0x0c0aac44u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0aac46;
P_0c0aac46: /* original 6533, guest PC 0x0c0aac46 */
if(!s->budget--) { s->failed_pc=0x0c0aac46u; return 0; }
r[5]=r[3];
goto P_0c0aac48;
P_0c0aac48: /* original 1f31, guest PC 0x0c0aac48 */
if(!s->budget--) { s->failed_pc=0x0c0aac48u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0aac4a;
P_0c0aac4a: /* original d23a, guest PC 0x0c0aac4a */
if(!s->budget--) { s->failed_pc=0x0c0aac4au; return 0; }
r[2]=read(ram,0x0c0aad34u,4);
goto P_0c0aac4c;
P_0c0aac4c: /* original 420b, guest PC 0x0c0aac4c */
if(!s->budget--) { s->failed_pc=0x0c0aac4cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0aac50u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aac50u) { target=s->pc; goto dispatch; }
goto P_0c0aac50;
P_0c0aac4e: /* original 64e3, guest PC 0x0c0aac4e */
if(!s->budget--) { s->failed_pc=0x0c0aac4eu; return 0; }
r[4]=r[14];
goto P_0c0aac50;
P_0c0aac50: /* original 53d1, guest PC 0x0c0aac50 */
if(!s->budget--) { s->failed_pc=0x0c0aac50u; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0aac52;
P_0c0aac52: /* original e062, guest PC 0x0c0aac52 */
if(!s->budget--) { s->failed_pc=0x0c0aac52u; return 0; }
r[0]=0x00000062u;
goto P_0c0aac54;
P_0c0aac54: /* original 7301, guest PC 0x0c0aac54 */
if(!s->budget--) { s->failed_pc=0x0c0aac54u; return 0; }
r[3]+=0x00000001u;
goto P_0c0aac56;
P_0c0aac56: /* original 6233, guest PC 0x0c0aac56 */
if(!s->budget--) { s->failed_pc=0x0c0aac56u; return 0; }
r[2]=r[3];
goto P_0c0aac58;
P_0c0aac58: /* original 1d31, guest PC 0x0c0aac58 */
if(!s->budget--) { s->failed_pc=0x0c0aac58u; return 0; }
write(ram,r[13]+4,r[3],4);
goto P_0c0aac5a;
P_0c0aac5a: /* original 0e24, guest PC 0x0c0aac5a */
if(!s->budget--) { s->failed_pc=0x0c0aac5au; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0aac5c;
P_0c0aac5c: /* original e03e, guest PC 0x0c0aac5c */
if(!s->budget--) { s->failed_pc=0x0c0aac5cu; return 0; }
r[0]=0x0000003eu;
goto P_0c0aac5e;
P_0c0aac5e: /* original 03ed, guest PC 0x0c0aac5e */
if(!s->budget--) { s->failed_pc=0x0c0aac5eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aac60;
P_0c0aac60: /* original e20a, guest PC 0x0c0aac60 */
if(!s->budget--) { s->failed_pc=0x0c0aac60u; return 0; }
r[2]=0x0000000au;
goto P_0c0aac62;
P_0c0aac62: /* original 633d, guest PC 0x0c0aac62 */
if(!s->budget--) { s->failed_pc=0x0c0aac62u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0aac64;
P_0c0aac64: /* original 3323, guest PC 0x0c0aac64 */
if(!s->budget--) { s->failed_pc=0x0c0aac64u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c0aac66;
P_0c0aac66: /* original 8901, guest PC 0x0c0aac66 */
if(!s->budget--) { s->failed_pc=0x0c0aac66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aac6c; }
goto P_0c0aac68;
P_0c0aac68: /* original a094, guest PC 0x0c0aac68 */
if(!s->budget--) { s->failed_pc=0x0c0aac68u; return 0; }
goto P_0c0aad94;
P_0c0aac6a: /* original 0009, guest PC 0x0c0aac6a */
if(!s->budget--) { s->failed_pc=0x0c0aac6au; return 0; }
goto P_0c0aac6c;
P_0c0aac6c: /* original e050, guest PC 0x0c0aac6c */
if(!s->budget--) { s->failed_pc=0x0c0aac6cu; return 0; }
r[0]=0x00000050u;
goto P_0c0aac6e;
P_0c0aac6e: /* original d332, guest PC 0x0c0aac6e */
if(!s->budget--) { s->failed_pc=0x0c0aac6eu; return 0; }
r[3]=read(ram,0x0c0aad38u,4);
goto P_0c0aac70;
P_0c0aac70: /* original 01ee, guest PC 0x0c0aac70 */
if(!s->budget--) { s->failed_pc=0x0c0aac70u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0aac72;
P_0c0aac72: /* original 2138, guest PC 0x0c0aac72 */
if(!s->budget--) { s->failed_pc=0x0c0aac72u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0aac74;
P_0c0aac74: /* original 8b01, guest PC 0x0c0aac74 */
if(!s->budget--) { s->failed_pc=0x0c0aac74u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aac7a; }
goto P_0c0aac76;
P_0c0aac76: /* original a08b, guest PC 0x0c0aac76 */
if(!s->budget--) { s->failed_pc=0x0c0aac76u; return 0; }
goto P_0c0aad90;
P_0c0aac78: /* original 0009, guest PC 0x0c0aac78 */
if(!s->budget--) { s->failed_pc=0x0c0aac78u; return 0; }
goto P_0c0aac7a;
P_0c0aac7a: /* original 9055, guest PC 0x0c0aac7a */
if(!s->budget--) { s->failed_pc=0x0c0aac7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aad28u,2);
goto P_0c0aac7c;
P_0c0aac7c: /* original 03cd, guest PC 0x0c0aac7c */
if(!s->budget--) { s->failed_pc=0x0c0aac7cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0aac7e;
P_0c0aac7e: /* original 633d, guest PC 0x0c0aac7e */
if(!s->budget--) { s->failed_pc=0x0c0aac7eu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0aac80;
P_0c0aac80: /* original 6533, guest PC 0x0c0aac80 */
if(!s->budget--) { s->failed_pc=0x0c0aac80u; return 0; }
r[5]=r[3];
goto P_0c0aac82;
P_0c0aac82: /* original 1f31, guest PC 0x0c0aac82 */
if(!s->budget--) { s->failed_pc=0x0c0aac82u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0aac84;
P_0c0aac84: /* original d22b, guest PC 0x0c0aac84 */
if(!s->budget--) { s->failed_pc=0x0c0aac84u; return 0; }
r[2]=read(ram,0x0c0aad34u,4);
goto P_0c0aac86;
P_0c0aac86: /* original 420b, guest PC 0x0c0aac86 */
if(!s->budget--) { s->failed_pc=0x0c0aac86u; return 0; }
target=r[2];
r[16]=code_base|0x0c0aac8au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aac8au) { target=s->pc; goto dispatch; }
goto P_0c0aac8a;
P_0c0aac88: /* original 64e3, guest PC 0x0c0aac88 */
if(!s->budget--) { s->failed_pc=0x0c0aac88u; return 0; }
r[4]=r[14];
goto P_0c0aac8a;
P_0c0aac8a: /* original e03e, guest PC 0x0c0aac8a */
if(!s->budget--) { s->failed_pc=0x0c0aac8au; return 0; }
r[0]=0x0000003eu;
goto P_0c0aac8c;
P_0c0aac8c: /* original e30a, guest PC 0x0c0aac8c */
if(!s->budget--) { s->failed_pc=0x0c0aac8cu; return 0; }
r[3]=0x0000000au;
goto P_0c0aac8e;
P_0c0aac8e: /* original 0e35, guest PC 0x0c0aac8e */
if(!s->budget--) { s->failed_pc=0x0c0aac8eu; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0aac90;
P_0c0aac90: /* original e062, guest PC 0x0c0aac90 */
if(!s->budget--) { s->failed_pc=0x0c0aac90u; return 0; }
r[0]=0x00000062u;
goto P_0c0aac92;
P_0c0aac92: /* original 52d1, guest PC 0x0c0aac92 */
if(!s->budget--) { s->failed_pc=0x0c0aac92u; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0aac94;
P_0c0aac94: /* original 7201, guest PC 0x0c0aac94 */
if(!s->budget--) { s->failed_pc=0x0c0aac94u; return 0; }
r[2]+=0x00000001u;
goto P_0c0aac96;
P_0c0aac96: /* original 6323, guest PC 0x0c0aac96 */
if(!s->budget--) { s->failed_pc=0x0c0aac96u; return 0; }
r[3]=r[2];
goto P_0c0aac98;
P_0c0aac98: /* original 1d21, guest PC 0x0c0aac98 */
if(!s->budget--) { s->failed_pc=0x0c0aac98u; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0aac9a;
P_0c0aac9a: /* original 0e34, guest PC 0x0c0aac9a */
if(!s->budget--) { s->failed_pc=0x0c0aac9au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0aac9c;
P_0c0aac9c: /* original 50f5, guest PC 0x0c0aac9c */
if(!s->budget--) { s->failed_pc=0x0c0aac9cu; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c0aac9e;
P_0c0aac9e: /* original e11c, guest PC 0x0c0aac9e */
if(!s->budget--) { s->failed_pc=0x0c0aac9eu; return 0; }
r[1]=0x0000001cu;
goto P_0c0aaca0;
P_0c0aaca0: /* original 001c, guest PC 0x0c0aaca0 */
if(!s->budget--) { s->failed_pc=0x0c0aaca0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0aaca2;
P_0c0aaca2: /* original 600c, guest PC 0x0c0aaca2 */
if(!s->budget--) { s->failed_pc=0x0c0aaca2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aaca4;
P_0c0aaca4: /* original c90f, guest PC 0x0c0aaca4 */
if(!s->budget--) { s->failed_pc=0x0c0aaca4u; return 0; }
r[0]&=15u;
goto P_0c0aaca6;
P_0c0aaca6: /* original 880d, guest PC 0x0c0aaca6 */
if(!s->budget--) { s->failed_pc=0x0c0aaca6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0aaca8;
P_0c0aaca8: /* original 8b0a, guest PC 0x0c0aaca8 */
if(!s->budget--) { s->failed_pc=0x0c0aaca8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aacc0; }
goto P_0c0aacaa;
P_0c0aacaa: /* original c724, guest PC 0x0c0aacaa */
if(!s->budget--) { s->failed_pc=0x0c0aacaau; return 0; }
r[0]=code_base|0x000aad3cu;
goto P_0c0aacac;
P_0c0aacac: /* original f308, guest PC 0x0c0aacac */
if(!s->budget--) { s->failed_pc=0x0c0aacacu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0aacae;
P_0c0aacae: /* original e05c, guest PC 0x0c0aacae */
if(!s->budget--) { s->failed_pc=0x0c0aacaeu; return 0; }
r[0]=0x0000005cu;
goto P_0c0aacb0;
P_0c0aacb0: /* original f2e6, guest PC 0x0c0aacb0 */
if(!s->budget--) { s->failed_pc=0x0c0aacb0u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0aacb2;
P_0c0aacb2: /* original f325, guest PC 0x0c0aacb2 */
if(!s->budget--) { s->failed_pc=0x0c0aacb2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0aacb4;
P_0c0aacb4: /* original 8904, guest PC 0x0c0aacb4 */
if(!s->budget--) { s->failed_pc=0x0c0aacb4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aacc0; }
goto P_0c0aacb6;
P_0c0aacb6: /* original e050, guest PC 0x0c0aacb6 */
if(!s->budget--) { s->failed_pc=0x0c0aacb6u; return 0; }
r[0]=0x00000050u;
goto P_0c0aacb8;
P_0c0aacb8: /* original d321, guest PC 0x0c0aacb8 */
if(!s->budget--) { s->failed_pc=0x0c0aacb8u; return 0; }
r[3]=read(ram,0x0c0aad40u,4);
goto P_0c0aacba;
P_0c0aacba: /* original 02ee, guest PC 0x0c0aacba */
if(!s->budget--) { s->failed_pc=0x0c0aacbau; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0aacbc;
P_0c0aacbc: /* original 2238, guest PC 0x0c0aacbc */
if(!s->budget--) { s->failed_pc=0x0c0aacbcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aacbe;
P_0c0aacbe: /* original 8b63, guest PC 0x0c0aacbe */
if(!s->budget--) { s->failed_pc=0x0c0aacbeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aad88; }
goto P_0c0aacc0;
P_0c0aacc0: /* original 61e2, guest PC 0x0c0aacc0 */
if(!s->budget--) { s->failed_pc=0x0c0aacc0u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0aacc2;
P_0c0aacc2: /* original d320, guest PC 0x0c0aacc2 */
if(!s->budget--) { s->failed_pc=0x0c0aacc2u; return 0; }
r[3]=read(ram,0x0c0aad44u,4);
goto P_0c0aacc4;
P_0c0aacc4: /* original 2138, guest PC 0x0c0aacc4 */
if(!s->budget--) { s->failed_pc=0x0c0aacc4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0aacc6;
P_0c0aacc6: /* original 891a, guest PC 0x0c0aacc6 */
if(!s->budget--) { s->failed_pc=0x0c0aacc6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aacfe; }
goto P_0c0aacc8;
P_0c0aacc8: /* original 62f3, guest PC 0x0c0aacc8 */
if(!s->budget--) { s->failed_pc=0x0c0aacc8u; return 0; }
r[2]=r[15];
goto P_0c0aacca;
P_0c0aacca: /* original 2f26, guest PC 0x0c0aacca */
if(!s->budget--) { s->failed_pc=0x0c0aaccau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aaccc;
P_0c0aaccc: /* original 65f3, guest PC 0x0c0aaccc */
if(!s->budget--) { s->failed_pc=0x0c0aacccu; return 0; }
r[5]=r[15];
goto P_0c0aacce;
P_0c0aacce: /* original d31e, guest PC 0x0c0aacce */
if(!s->budget--) { s->failed_pc=0x0c0aacceu; return 0; }
r[3]=read(ram,0x0c0aad48u,4);
goto P_0c0aacd0;
P_0c0aacd0: /* original 66f3, guest PC 0x0c0aacd0 */
if(!s->budget--) { s->failed_pc=0x0c0aacd0u; return 0; }
r[6]=r[15];
goto P_0c0aacd2;
P_0c0aacd2: /* original 67f3, guest PC 0x0c0aacd2 */
if(!s->budget--) { s->failed_pc=0x0c0aacd2u; return 0; }
r[7]=r[15];
goto P_0c0aacd4;
P_0c0aacd4: /* original 750c, guest PC 0x0c0aacd4 */
if(!s->budget--) { s->failed_pc=0x0c0aacd4u; return 0; }
r[5]+=0x0000000cu;
goto P_0c0aacd6;
P_0c0aacd6: /* original 7610, guest PC 0x0c0aacd6 */
if(!s->budget--) { s->failed_pc=0x0c0aacd6u; return 0; }
r[6]+=0x00000010u;
goto P_0c0aacd8;
P_0c0aacd8: /* original 7714, guest PC 0x0c0aacd8 */
if(!s->budget--) { s->failed_pc=0x0c0aacd8u; return 0; }
r[7]+=0x00000014u;
goto P_0c0aacda;
P_0c0aacda: /* original 430b, guest PC 0x0c0aacda */
if(!s->budget--) { s->failed_pc=0x0c0aacdau; return 0; }
target=r[3];
r[16]=code_base|0x0c0aacdeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aacdeu) { target=s->pc; goto dispatch; }
goto P_0c0aacde;
P_0c0aacdc: /* original 64e3, guest PC 0x0c0aacdc */
if(!s->budget--) { s->failed_pc=0x0c0aacdcu; return 0; }
r[4]=r[14];
goto P_0c0aacde;
P_0c0aacde: /* original 7f04, guest PC 0x0c0aacde */
if(!s->budget--) { s->failed_pc=0x0c0aacdeu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aace0;
P_0c0aace0: /* original 9323, guest PC 0x0c0aace0 */
if(!s->budget--) { s->failed_pc=0x0c0aace0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aad2au,2);
goto P_0c0aace2;
P_0c0aace2: /* original 62f2, guest PC 0x0c0aace2 */
if(!s->budget--) { s->failed_pc=0x0c0aace2u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0aace4;
P_0c0aace4: /* original 3328, guest PC 0x0c0aace4 */
if(!s->budget--) { s->failed_pc=0x0c0aace4u; return 0; }
r[3]-=r[2];
goto P_0c0aace6;
P_0c0aace6: /* original 633f, guest PC 0x0c0aace6 */
if(!s->budget--) { s->failed_pc=0x0c0aace6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c0aace8;
P_0c0aace8: /* original 2f32, guest PC 0x0c0aace8 */
if(!s->budget--) { s->failed_pc=0x0c0aace8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0aacea;
P_0c0aacea: /* original 85ef, guest PC 0x0c0aacea */
if(!s->budget--) { s->failed_pc=0x0c0aaceau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0aacec;
P_0c0aacec: /* original 6403, guest PC 0x0c0aacec */
if(!s->budget--) { s->failed_pc=0x0c0aacecu; return 0; }
r[4]=r[0];
goto P_0c0aacee;
P_0c0aacee: /* original 3438, guest PC 0x0c0aacee */
if(!s->budget--) { s->failed_pc=0x0c0aaceeu; return 0; }
r[4]-=r[3];
goto P_0c0aacf0;
P_0c0aacf0: /* original 644f, guest PC 0x0c0aacf0 */
if(!s->budget--) { s->failed_pc=0x0c0aacf0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0aacf2;
P_0c0aacf2: /* original 4411, guest PC 0x0c0aacf2 */
if(!s->budget--) { s->failed_pc=0x0c0aacf2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0aacf4;
P_0c0aacf4: /* original 8900, guest PC 0x0c0aacf4 */
if(!s->budget--) { s->failed_pc=0x0c0aacf4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aacf8; }
goto P_0c0aacf6;
P_0c0aacf6: /* original 644b, guest PC 0x0c0aacf6 */
if(!s->budget--) { s->failed_pc=0x0c0aacf6u; return 0; }
r[4]=0u-r[4];
goto P_0c0aacf8;
P_0c0aacf8: /* original 9218, guest PC 0x0c0aacf8 */
if(!s->budget--) { s->failed_pc=0x0c0aacf8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aad2cu,2);
goto P_0c0aacfa;
P_0c0aacfa: /* original 3427, guest PC 0x0c0aacfa */
if(!s->budget--) { s->failed_pc=0x0c0aacfau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[2])!=0);
goto P_0c0aacfc;
P_0c0aacfc: /* original 8b38, guest PC 0x0c0aacfc */
if(!s->budget--) { s->failed_pc=0x0c0aacfcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aad70; }
goto P_0c0aacfe;
P_0c0aacfe: /* original e050, guest PC 0x0c0aacfe */
if(!s->budget--) { s->failed_pc=0x0c0aacfeu; return 0; }
r[0]=0x00000050u;
goto P_0c0aad00;
P_0c0aad00: /* original d30d, guest PC 0x0c0aad00 */
if(!s->budget--) { s->failed_pc=0x0c0aad00u; return 0; }
r[3]=read(ram,0x0c0aad38u,4);
goto P_0c0aad02;
P_0c0aad02: /* original 01ee, guest PC 0x0c0aad02 */
if(!s->budget--) { s->failed_pc=0x0c0aad02u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0aad04;
P_0c0aad04: /* original 2138, guest PC 0x0c0aad04 */
if(!s->budget--) { s->failed_pc=0x0c0aad04u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0aad06;
P_0c0aad06: /* original 8933, guest PC 0x0c0aad06 */
if(!s->budget--) { s->failed_pc=0x0c0aad06u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aad70; }
goto P_0c0aad08;
P_0c0aad08: /* original 62e2, guest PC 0x0c0aad08 */
if(!s->budget--) { s->failed_pc=0x0c0aad08u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0aad0a;
P_0c0aad0a: /* original d30d, guest PC 0x0c0aad0a */
if(!s->budget--) { s->failed_pc=0x0c0aad0au; return 0; }
r[3]=read(ram,0x0c0aad40u,4);
goto P_0c0aad0c;
P_0c0aad0c: /* original 2238, guest PC 0x0c0aad0c */
if(!s->budget--) { s->failed_pc=0x0c0aad0cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aad0e;
P_0c0aad0e: /* original 8941, guest PC 0x0c0aad0e */
if(!s->budget--) { s->failed_pc=0x0c0aad0eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aad94; }
goto P_0c0aad10;
P_0c0aad10: /* original e048, guest PC 0x0c0aad10 */
if(!s->budget--) { s->failed_pc=0x0c0aad10u; return 0; }
r[0]=0x00000048u;
goto P_0c0aad12;
P_0c0aad12: /* original 01ee, guest PC 0x0c0aad12 */
if(!s->budget--) { s->failed_pc=0x0c0aad12u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0aad14;
P_0c0aad14: /* original 6213, guest PC 0x0c0aad14 */
if(!s->budget--) { s->failed_pc=0x0c0aad14u; return 0; }
r[2]=r[1];
goto P_0c0aad16;
P_0c0aad16: /* original 2f12, guest PC 0x0c0aad16 */
if(!s->budget--) { s->failed_pc=0x0c0aad16u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0aad18;
P_0c0aad18: /* original 9309, guest PC 0x0c0aad18 */
if(!s->budget--) { s->failed_pc=0x0c0aad18u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aad2eu,2);
goto P_0c0aad1a;
P_0c0aad1a: /* original d40c, guest PC 0x0c0aad1a */
if(!s->budget--) { s->failed_pc=0x0c0aad1au; return 0; }
r[4]=read(ram,0x0c0aad4cu,4);
goto P_0c0aad1c;
P_0c0aad1c: /* original 2238, guest PC 0x0c0aad1c */
if(!s->budget--) { s->failed_pc=0x0c0aad1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aad1e;
P_0c0aad1e: /* original 8917, guest PC 0x0c0aad1e */
if(!s->budget--) { s->failed_pc=0x0c0aad1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aad50; }
goto P_0c0aad20;
P_0c0aad20: /* original 62f2, guest PC 0x0c0aad20 */
if(!s->budget--) { s->failed_pc=0x0c0aad20u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0aad22;
P_0c0aad22: /* original 224b, guest PC 0x0c0aad22 */
if(!s->budget--) { s->failed_pc=0x0c0aad22u; return 0; }
r[2]|=r[4];
goto P_0c0aad24;
P_0c0aad24: /* original a018, guest PC 0x0c0aad24 */
if(!s->budget--) { s->failed_pc=0x0c0aad24u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0aad58;
P_0c0aad26: /* original 2f22, guest PC 0x0c0aad26 */
if(!s->budget--) { s->failed_pc=0x0c0aad26u; return 0; }
write(ram,r[15],r[2],4);
if(!vf3_matrix_family(0x0c0aad28u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aad28u; return 0; } return 1;
P_0c0aad50: /* original 61f2, guest PC 0x0c0aad50 */
if(!s->budget--) { s->failed_pc=0x0c0aad50u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0aad52;
P_0c0aad52: /* original d23e, guest PC 0x0c0aad52 */
if(!s->budget--) { s->failed_pc=0x0c0aad52u; return 0; }
r[2]=read(ram,0x0c0aae4cu,4);
goto P_0c0aad54;
P_0c0aad54: /* original 2129, guest PC 0x0c0aad54 */
if(!s->budget--) { s->failed_pc=0x0c0aad54u; return 0; }
r[1]&=r[2];
goto P_0c0aad56;
P_0c0aad56: /* original 2f12, guest PC 0x0c0aad56 */
if(!s->budget--) { s->failed_pc=0x0c0aad56u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0aad58;
P_0c0aad58: /* original 62f2, guest PC 0x0c0aad58 */
if(!s->budget--) { s->failed_pc=0x0c0aad58u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0aad5a;
P_0c0aad5a: /* original 63e2, guest PC 0x0c0aad5a */
if(!s->budget--) { s->failed_pc=0x0c0aad5au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0aad5c;
P_0c0aad5c: /* original 223a, guest PC 0x0c0aad5c */
if(!s->budget--) { s->failed_pc=0x0c0aad5cu; return 0; }
r[2]^=r[3];
goto P_0c0aad5e;
P_0c0aad5e: /* original 2248, guest PC 0x0c0aad5e */
if(!s->budget--) { s->failed_pc=0x0c0aad5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0aad60;
P_0c0aad60: /* original 2f22, guest PC 0x0c0aad60 */
if(!s->budget--) { s->failed_pc=0x0c0aad60u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0aad62;
P_0c0aad62: /* original 906b, guest PC 0x0c0aad62 */
if(!s->budget--) { s->failed_pc=0x0c0aad62u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aae3cu,2);
goto P_0c0aad64;
P_0c0aad64: /* original 0dcd, guest PC 0x0c0aad64 */
if(!s->budget--) { s->failed_pc=0x0c0aad64u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0aad66;
P_0c0aad66: /* original 8f09, guest PC 0x0c0aad66 */
if(!s->budget--) { s->failed_pc=0x0c0aad66u; return 0; }
cond=r[17]&1u;
r[13]=r[13]&65535u;
if(!cond) { goto P_0c0aad7c; }
goto P_0c0aad6a;
P_0c0aad68: /* original 6ddd, guest PC 0x0c0aad68 */
if(!s->budget--) { s->failed_pc=0x0c0aad68u; return 0; }
r[13]=r[13]&65535u;
goto P_0c0aad6a;
P_0c0aad6a: /* original 9068, guest PC 0x0c0aad6a */
if(!s->budget--) { s->failed_pc=0x0c0aad6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aae3eu,2);
goto P_0c0aad6c;
P_0c0aad6c: /* original a005, guest PC 0x0c0aad6c */
if(!s->budget--) { s->failed_pc=0x0c0aad6cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0aad7a;
P_0c0aad6e: /* original 0dcd, guest PC 0x0c0aad6e */
if(!s->budget--) { s->failed_pc=0x0c0aad6eu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0aad70;
P_0c0aad70: /* original 6dc3, guest PC 0x0c0aad70 */
if(!s->budget--) { s->failed_pc=0x0c0aad70u; return 0; }
r[13]=r[12];
goto P_0c0aad72;
P_0c0aad72: /* original 7d3a, guest PC 0x0c0aad72 */
if(!s->budget--) { s->failed_pc=0x0c0aad72u; return 0; }
r[13]+=0x0000003au;
goto P_0c0aad74;
P_0c0aad74: /* original d236, guest PC 0x0c0aad74 */
if(!s->budget--) { s->failed_pc=0x0c0aad74u; return 0; }
r[2]=read(ram,0x0c0aae50u,4);
goto P_0c0aad76;
P_0c0aad76: /* original 1e2d, guest PC 0x0c0aad76 */
if(!s->budget--) { s->failed_pc=0x0c0aad76u; return 0; }
write(ram,r[14]+52,r[2],4);
goto P_0c0aad78;
P_0c0aad78: /* original 6dd1, guest PC 0x0c0aad78 */
if(!s->budget--) { s->failed_pc=0x0c0aad78u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[13]=tmp;
goto P_0c0aad7a;
P_0c0aad7a: /* original 6ddd, guest PC 0x0c0aad7a */
if(!s->budget--) { s->failed_pc=0x0c0aad7au; return 0; }
r[13]=r[13]&65535u;
goto P_0c0aad7c;
P_0c0aad7c: /* original d335, guest PC 0x0c0aad7c */
if(!s->budget--) { s->failed_pc=0x0c0aad7cu; return 0; }
r[3]=read(ram,0x0c0aae54u,4);
goto P_0c0aad7e;
P_0c0aad7e: /* original 65d3, guest PC 0x0c0aad7e */
if(!s->budget--) { s->failed_pc=0x0c0aad7eu; return 0; }
r[5]=r[13];
goto P_0c0aad80;
P_0c0aad80: /* original 430b, guest PC 0x0c0aad80 */
if(!s->budget--) { s->failed_pc=0x0c0aad80u; return 0; }
target=r[3];
r[16]=code_base|0x0c0aad84u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aad84u) { target=s->pc; goto dispatch; }
goto P_0c0aad84;
P_0c0aad82: /* original 64e3, guest PC 0x0c0aad82 */
if(!s->budget--) { s->failed_pc=0x0c0aad82u; return 0; }
r[4]=r[14];
goto P_0c0aad84;
P_0c0aad84: /* original a006, guest PC 0x0c0aad84 */
if(!s->budget--) { s->failed_pc=0x0c0aad84u; return 0; }
goto P_0c0aad94;
P_0c0aad86: /* original 0009, guest PC 0x0c0aad86 */
if(!s->budget--) { s->failed_pc=0x0c0aad86u; return 0; }
goto P_0c0aad88;
P_0c0aad88: /* original d232, guest PC 0x0c0aad88 */
if(!s->budget--) { s->failed_pc=0x0c0aad88u; return 0; }
r[2]=read(ram,0x0c0aae54u,4);
goto P_0c0aad8a;
P_0c0aad8a: /* original 9559, guest PC 0x0c0aad8a */
if(!s->budget--) { s->failed_pc=0x0c0aad8au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aae40u,2);
goto P_0c0aad8c;
P_0c0aad8c: /* original 420b, guest PC 0x0c0aad8c */
if(!s->budget--) { s->failed_pc=0x0c0aad8cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0aad90u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aad90u) { target=s->pc; goto dispatch; }
goto P_0c0aad90;
P_0c0aad8e: /* original 64e3, guest PC 0x0c0aad8e */
if(!s->budget--) { s->failed_pc=0x0c0aad8eu; return 0; }
r[4]=r[14];
goto P_0c0aad90;
P_0c0aad90: /* original e300, guest PC 0x0c0aad90 */
if(!s->budget--) { s->failed_pc=0x0c0aad90u; return 0; }
r[3]=0x00000000u;
goto P_0c0aad92;
P_0c0aad92: /* original 1e3e, guest PC 0x0c0aad92 */
if(!s->budget--) { s->failed_pc=0x0c0aad92u; return 0; }
write(ram,r[14]+56,r[3],4);
goto P_0c0aad94;
P_0c0aad94: /* original 7f18, guest PC 0x0c0aad94 */
if(!s->budget--) { s->failed_pc=0x0c0aad94u; return 0; }
r[15]+=0x00000018u;
goto P_0c0aad96;
P_0c0aad96: /* original 4f26, guest PC 0x0c0aad96 */
if(!s->budget--) { s->failed_pc=0x0c0aad96u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aad98;
P_0c0aad98: /* original 6cf6, guest PC 0x0c0aad98 */
if(!s->budget--) { s->failed_pc=0x0c0aad98u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0aad9a;
P_0c0aad9a: /* original 6df6, guest PC 0x0c0aad9a */
if(!s->budget--) { s->failed_pc=0x0c0aad9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aad9c;
P_0c0aad9c: /* original 000b, guest PC 0x0c0aad9c */
if(!s->budget--) { s->failed_pc=0x0c0aad9cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0aad9e: /* original 6ef6, guest PC 0x0c0aad9e */
if(!s->budget--) { s->failed_pc=0x0c0aad9eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aada0;
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
unsupported: s->failed_pc=target; return 0;
}
