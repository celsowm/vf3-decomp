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
int vf3_away_batch4_adapter_14(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04c9a2u: goto P_0c04c9a2;
case 0x0c04c9a4u: goto P_0c04c9a4;
case 0x0c04c9a6u: goto P_0c04c9a6;
case 0x0c04c9a8u: goto P_0c04c9a8;
case 0x0c04c9aau: goto P_0c04c9aa;
case 0x0c04c9acu: goto P_0c04c9ac;
case 0x0c04c9aeu: goto P_0c04c9ae;
case 0x0c04c9b0u: goto P_0c04c9b0;
case 0x0c04c9b2u: goto P_0c04c9b2;
case 0x0c04c9b4u: goto P_0c04c9b4;
case 0x0c04c9b6u: goto P_0c04c9b6;
case 0x0c04c9b8u: goto P_0c04c9b8;
case 0x0c04c9bau: goto P_0c04c9ba;
case 0x0c04c9bcu: goto P_0c04c9bc;
case 0x0c04c9beu: goto P_0c04c9be;
case 0x0c04c9c0u: goto P_0c04c9c0;
case 0x0c04c9c2u: goto P_0c04c9c2;
case 0x0c04c9c4u: goto P_0c04c9c4;
case 0x0c04c9c6u: goto P_0c04c9c6;
case 0x0c04c9c8u: goto P_0c04c9c8;
case 0x0c04c9cau: goto P_0c04c9ca;
case 0x0c04c9ccu: goto P_0c04c9cc;
case 0x0c04c9ceu: goto P_0c04c9ce;
case 0x0c04c9d0u: goto P_0c04c9d0;
case 0x0c04c9d2u: goto P_0c04c9d2;
case 0x0c04c9d4u: goto P_0c04c9d4;
case 0x0c04c9d6u: goto P_0c04c9d6;
case 0x0c04c9d8u: goto P_0c04c9d8;
case 0x0c04c9dau: goto P_0c04c9da;
case 0x0c04c9dcu: goto P_0c04c9dc;
case 0x0c04c9deu: goto P_0c04c9de;
case 0x0c04c9e0u: goto P_0c04c9e0;
case 0x0c04c9e2u: goto P_0c04c9e2;
case 0x0c04c9e4u: goto P_0c04c9e4;
case 0x0c04c9e6u: goto P_0c04c9e6;
case 0x0c04c9e8u: goto P_0c04c9e8;
case 0x0c04c9eau: goto P_0c04c9ea;
case 0x0c04c9ecu: goto P_0c04c9ec;
case 0x0c04c9eeu: goto P_0c04c9ee;
case 0x0c04c9f0u: goto P_0c04c9f0;
case 0x0c04c9f2u: goto P_0c04c9f2;
case 0x0c04c9f4u: goto P_0c04c9f4;
case 0x0c04c9f6u: goto P_0c04c9f6;
case 0x0c04c9f8u: goto P_0c04c9f8;
case 0x0c04c9fau: goto P_0c04c9fa;
case 0x0c04c9fcu: goto P_0c04c9fc;
case 0x0c04c9feu: goto P_0c04c9fe;
case 0x0c04ca00u: goto P_0c04ca00;
case 0x0c04ca02u: goto P_0c04ca02;
case 0x0c04ca04u: goto P_0c04ca04;
case 0x0c04ca06u: goto P_0c04ca06;
case 0x0c04ca08u: goto P_0c04ca08;
case 0x0c04ca0au: goto P_0c04ca0a;
case 0x0c04ca0cu: goto P_0c04ca0c;
case 0x0c04ca0eu: goto P_0c04ca0e;
case 0x0c04ca10u: goto P_0c04ca10;
case 0x0c04ca12u: goto P_0c04ca12;
case 0x0c04ca14u: goto P_0c04ca14;
case 0x0c04ca16u: goto P_0c04ca16;
case 0x0c04ca18u: goto P_0c04ca18;
case 0x0c04ca1au: goto P_0c04ca1a;
case 0x0c04ca1cu: goto P_0c04ca1c;
case 0x0c04ca1eu: goto P_0c04ca1e;
case 0x0c04ca20u: goto P_0c04ca20;
case 0x0c04ca22u: goto P_0c04ca22;
case 0x0c04ca24u: goto P_0c04ca24;
case 0x0c04ca26u: goto P_0c04ca26;
case 0x0c04ca28u: goto P_0c04ca28;
case 0x0c04ca50u: goto P_0c04ca50;
case 0x0c04ca52u: goto P_0c04ca52;
case 0x0c04ca54u: goto P_0c04ca54;
case 0x0c04ca56u: goto P_0c04ca56;
case 0x0c04ca58u: goto P_0c04ca58;
case 0x0c04ca5au: goto P_0c04ca5a;
case 0x0c04ca5cu: goto P_0c04ca5c;
case 0x0c04ca5eu: goto P_0c04ca5e;
case 0x0c04ca60u: goto P_0c04ca60;
case 0x0c04ca62u: goto P_0c04ca62;
case 0x0c04ca64u: goto P_0c04ca64;
case 0x0c04ca66u: goto P_0c04ca66;
case 0x0c04ca68u: goto P_0c04ca68;
case 0x0c04ca6au: goto P_0c04ca6a;
case 0x0c04ca6cu: goto P_0c04ca6c;
case 0x0c04ca6eu: goto P_0c04ca6e;
case 0x0c04ca70u: goto P_0c04ca70;
case 0x0c04ca72u: goto P_0c04ca72;
case 0x0c04ca74u: goto P_0c04ca74;
case 0x0c04ca76u: goto P_0c04ca76;
case 0x0c04ca78u: goto P_0c04ca78;
case 0x0c04ca7au: goto P_0c04ca7a;
case 0x0c04ca7cu: goto P_0c04ca7c;
case 0x0c04ca7eu: goto P_0c04ca7e;
case 0x0c04ca80u: goto P_0c04ca80;
case 0x0c04ca82u: goto P_0c04ca82;
case 0x0c04ca84u: goto P_0c04ca84;
case 0x0c04ca86u: goto P_0c04ca86;
case 0x0c04ca88u: goto P_0c04ca88;
case 0x0c04ca8au: goto P_0c04ca8a;
case 0x0c04ca8cu: goto P_0c04ca8c;
case 0x0c04ca8eu: goto P_0c04ca8e;
case 0x0c04ca90u: goto P_0c04ca90;
case 0x0c04ca92u: goto P_0c04ca92;
case 0x0c04ca94u: goto P_0c04ca94;
case 0x0c04ca96u: goto P_0c04ca96;
case 0x0c04ca98u: goto P_0c04ca98;
case 0x0c04ca9au: goto P_0c04ca9a;
case 0x0c04ca9cu: goto P_0c04ca9c;
case 0x0c04ca9eu: goto P_0c04ca9e;
case 0x0c04caa0u: goto P_0c04caa0;
case 0x0c04caa2u: goto P_0c04caa2;
case 0x0c04caa4u: goto P_0c04caa4;
case 0x0c04caa6u: goto P_0c04caa6;
case 0x0c04caa8u: goto P_0c04caa8;
case 0x0c04caaau: goto P_0c04caaa;
case 0x0c04caacu: goto P_0c04caac;
case 0x0c04caaeu: goto P_0c04caae;
case 0x0c04cab0u: goto P_0c04cab0;
case 0x0c04cab2u: goto P_0c04cab2;
case 0x0c04cab4u: goto P_0c04cab4;
case 0x0c04cab6u: goto P_0c04cab6;
case 0x0c04cab8u: goto P_0c04cab8;
case 0x0c04cabau: goto P_0c04caba;
case 0x0c04cabcu: goto P_0c04cabc;
case 0x0c04cabeu: goto P_0c04cabe;
case 0x0c04cac0u: goto P_0c04cac0;
case 0x0c04cac2u: goto P_0c04cac2;
case 0x0c04cac4u: goto P_0c04cac4;
case 0x0c04cac6u: goto P_0c04cac6;
case 0x0c04cac8u: goto P_0c04cac8;
case 0x0c04cacau: goto P_0c04caca;
case 0x0c04caccu: goto P_0c04cacc;
case 0x0c04caceu: goto P_0c04cace;
case 0x0c04cad0u: goto P_0c04cad0;
case 0x0c04cad2u: goto P_0c04cad2;
case 0x0c04cad4u: goto P_0c04cad4;
case 0x0c04cad6u: goto P_0c04cad6;
case 0x0c04cad8u: goto P_0c04cad8;
case 0x0c04cadau: goto P_0c04cada;
case 0x0c04cadcu: goto P_0c04cadc;
case 0x0c04cadeu: goto P_0c04cade;
case 0x0c04cae0u: goto P_0c04cae0;
case 0x0c04cae2u: goto P_0c04cae2;
case 0x0c04cae4u: goto P_0c04cae4;
case 0x0c04cae6u: goto P_0c04cae6;
case 0x0c04cae8u: goto P_0c04cae8;
case 0x0c04caeau: goto P_0c04caea;
case 0x0c04caecu: goto P_0c04caec;
case 0x0c04caeeu: goto P_0c04caee;
case 0x0c04caf0u: goto P_0c04caf0;
case 0x0c04caf2u: goto P_0c04caf2;
case 0x0c04caf4u: goto P_0c04caf4;
case 0x0c04caf6u: goto P_0c04caf6;
case 0x0c04caf8u: goto P_0c04caf8;
case 0x0c04cafau: goto P_0c04cafa;
case 0x0c04cafcu: goto P_0c04cafc;
case 0x0c04cafeu: goto P_0c04cafe;
case 0x0c04cb00u: goto P_0c04cb00;
case 0x0c04cb02u: goto P_0c04cb02;
case 0x0c04cb04u: goto P_0c04cb04;
case 0x0c04cb06u: goto P_0c04cb06;
case 0x0c04cb08u: goto P_0c04cb08;
case 0x0c04cb0au: goto P_0c04cb0a;
case 0x0c04cb0cu: goto P_0c04cb0c;
case 0x0c04cb0eu: goto P_0c04cb0e;
case 0x0c04cb10u: goto P_0c04cb10;
case 0x0c04cb12u: goto P_0c04cb12;
case 0x0c04cb14u: goto P_0c04cb14;
case 0x0c04cb16u: goto P_0c04cb16;
case 0x0c04cb18u: goto P_0c04cb18;
case 0x0c04cb1au: goto P_0c04cb1a;
case 0x0c04cb1cu: goto P_0c04cb1c;
case 0x0c04cb1eu: goto P_0c04cb1e;
case 0x0c04cb20u: goto P_0c04cb20;
case 0x0c04cb22u: goto P_0c04cb22;
case 0x0c04cb24u: goto P_0c04cb24;
case 0x0c04cb26u: goto P_0c04cb26;
case 0x0c04cb28u: goto P_0c04cb28;
case 0x0c04cb2au: goto P_0c04cb2a;
case 0x0c04cb2cu: goto P_0c04cb2c;
case 0x0c04cb2eu: goto P_0c04cb2e;
case 0x0c04cb30u: goto P_0c04cb30;
case 0x0c04cb32u: goto P_0c04cb32;
case 0x0c04cb34u: goto P_0c04cb34;
case 0x0c04cb36u: goto P_0c04cb36;
case 0x0c04cb38u: goto P_0c04cb38;
case 0x0c04cb3au: goto P_0c04cb3a;
case 0x0c04cb3cu: goto P_0c04cb3c;
case 0x0c04cc08u: goto P_0c04cc08;
case 0x0c04cc0au: goto P_0c04cc0a;
case 0x0c04cc0cu: goto P_0c04cc0c;
case 0x0c04cc0eu: goto P_0c04cc0e;
case 0x0c04cc10u: goto P_0c04cc10;
case 0x0c04cc12u: goto P_0c04cc12;
case 0x0c04cc14u: goto P_0c04cc14;
case 0x0c04cc16u: goto P_0c04cc16;
case 0x0c04cc18u: goto P_0c04cc18;
case 0x0c04cc1au: goto P_0c04cc1a;
case 0x0c04cc1cu: goto P_0c04cc1c;
case 0x0c04cc1eu: goto P_0c04cc1e;
case 0x0c04cc20u: goto P_0c04cc20;
case 0x0c04cc22u: goto P_0c04cc22;
case 0x0c04cc24u: goto P_0c04cc24;
case 0x0c04cc26u: goto P_0c04cc26;
case 0x0c04cc28u: goto P_0c04cc28;
case 0x0c04cc2au: goto P_0c04cc2a;
case 0x0c04cc2cu: goto P_0c04cc2c;
case 0x0c04cc2eu: goto P_0c04cc2e;
case 0x0c04cc30u: goto P_0c04cc30;
case 0x0c04cc32u: goto P_0c04cc32;
case 0x0c04cc34u: goto P_0c04cc34;
case 0x0c04cc36u: goto P_0c04cc36;
case 0x0c04cc38u: goto P_0c04cc38;
case 0x0c04cc3au: goto P_0c04cc3a;
case 0x0c04cc3cu: goto P_0c04cc3c;
case 0x0c04cc3eu: goto P_0c04cc3e;
case 0x0c04cc40u: goto P_0c04cc40;
case 0x0c04cc42u: goto P_0c04cc42;
case 0x0c04cc44u: goto P_0c04cc44;
case 0x0c04cc46u: goto P_0c04cc46;
case 0x0c04cc48u: goto P_0c04cc48;
case 0x0c04cc4au: goto P_0c04cc4a;
case 0x0c04cc4cu: goto P_0c04cc4c;
case 0x0c04cc4eu: goto P_0c04cc4e;
case 0x0c04cc50u: goto P_0c04cc50;
case 0x0c04cc52u: goto P_0c04cc52;
case 0x0c04cc54u: goto P_0c04cc54;
case 0x0c04cc56u: goto P_0c04cc56;
case 0x0c04cc58u: goto P_0c04cc58;
case 0x0c04cc5au: goto P_0c04cc5a;
case 0x0c04cc5cu: goto P_0c04cc5c;
case 0x0c04cc5eu: goto P_0c04cc5e;
case 0x0c04cc60u: goto P_0c04cc60;
case 0x0c04cc62u: goto P_0c04cc62;
case 0x0c04cc64u: goto P_0c04cc64;
case 0x0c04cc66u: goto P_0c04cc66;
case 0x0c04cc68u: goto P_0c04cc68;
case 0x0c04cc6au: goto P_0c04cc6a;
case 0x0c04cc6cu: goto P_0c04cc6c;
case 0x0c04cc6eu: goto P_0c04cc6e;
case 0x0c04cc70u: goto P_0c04cc70;
case 0x0c04cc72u: goto P_0c04cc72;
case 0x0c04cc74u: goto P_0c04cc74;
case 0x0c04cc76u: goto P_0c04cc76;
case 0x0c04cc78u: goto P_0c04cc78;
case 0x0c04cc7au: goto P_0c04cc7a;
case 0x0c04cc7cu: goto P_0c04cc7c;
case 0x0c04cc7eu: goto P_0c04cc7e;
case 0x0c04cc80u: goto P_0c04cc80;
case 0x0c04cc82u: goto P_0c04cc82;
case 0x0c04cc84u: goto P_0c04cc84;
case 0x0c04cc86u: goto P_0c04cc86;
case 0x0c04cc88u: goto P_0c04cc88;
case 0x0c04cc8au: goto P_0c04cc8a;
case 0x0c04cc8cu: goto P_0c04cc8c;
case 0x0c04cc8eu: goto P_0c04cc8e;
case 0x0c04cc90u: goto P_0c04cc90;
case 0x0c04cc92u: goto P_0c04cc92;
case 0x0c04cc94u: goto P_0c04cc94;
case 0x0c04cc96u: goto P_0c04cc96;
case 0x0c04cc98u: goto P_0c04cc98;
case 0x0c04cc9au: goto P_0c04cc9a;
case 0x0c04cc9cu: goto P_0c04cc9c;
case 0x0c04cc9eu: goto P_0c04cc9e;
case 0x0c04cca0u: goto P_0c04cca0;
case 0x0c04cca2u: goto P_0c04cca2;
case 0x0c04cca4u: goto P_0c04cca4;
case 0x0c04cca6u: goto P_0c04cca6;
case 0x0c04cca8u: goto P_0c04cca8;
case 0x0c04ccaau: goto P_0c04ccaa;
case 0x0c04ccacu: goto P_0c04ccac;
case 0x0c04ccaeu: goto P_0c04ccae;
case 0x0c04ccb0u: goto P_0c04ccb0;
case 0x0c04ccb2u: goto P_0c04ccb2;
case 0x0c04ccb4u: goto P_0c04ccb4;
case 0x0c04ccb6u: goto P_0c04ccb6;
case 0x0c04ccb8u: goto P_0c04ccb8;
case 0x0c04ccbau: goto P_0c04ccba;
case 0x0c04ccbcu: goto P_0c04ccbc;
case 0x0c04ccbeu: goto P_0c04ccbe;
case 0x0c04ccc0u: goto P_0c04ccc0;
case 0x0c04ccc2u: goto P_0c04ccc2;
case 0x0c04ccc4u: goto P_0c04ccc4;
case 0x0c04ccc6u: goto P_0c04ccc6;
case 0x0c04ccc8u: goto P_0c04ccc8;
case 0x0c04cccau: goto P_0c04ccca;
case 0x0c04ccccu: goto P_0c04cccc;
case 0x0c04ccceu: goto P_0c04ccce;
case 0x0c04ccd0u: goto P_0c04ccd0;
case 0x0c04ccd2u: goto P_0c04ccd2;
case 0x0c04ccd4u: goto P_0c04ccd4;
case 0x0c04ccd6u: goto P_0c04ccd6;
case 0x0c04ccd8u: goto P_0c04ccd8;
case 0x0c04ccdau: goto P_0c04ccda;
case 0x0c04ccdcu: goto P_0c04ccdc;
case 0x0c04ccdeu: goto P_0c04ccde;
case 0x0c04cce0u: goto P_0c04cce0;
case 0x0c04cce2u: goto P_0c04cce2;
case 0x0c04cce4u: goto P_0c04cce4;
case 0x0c04cce6u: goto P_0c04cce6;
case 0x0c04cce8u: goto P_0c04cce8;
case 0x0c04cceau: goto P_0c04ccea;
case 0x0c04ccecu: goto P_0c04ccec;
case 0x0c04cceeu: goto P_0c04ccee;
case 0x0c04ccf0u: goto P_0c04ccf0;
case 0x0c04ccf2u: goto P_0c04ccf2;
case 0x0c04ccf4u: goto P_0c04ccf4;
case 0x0c04ccf6u: goto P_0c04ccf6;
case 0x0c04ccf8u: goto P_0c04ccf8;
case 0x0c04ccfau: goto P_0c04ccfa;
case 0x0c04ccfcu: goto P_0c04ccfc;
case 0x0c04ccfeu: goto P_0c04ccfe;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04c9a2: /* original 2fe6, guest PC 0x0c04c9a2 */
if(!s->budget--) { s->failed_pc=0x0c04c9a2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c9a4;
P_0c04c9a4: /* original 2fd6, guest PC 0x0c04c9a4 */
if(!s->budget--) { s->failed_pc=0x0c04c9a4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c9a6;
P_0c04c9a6: /* original 2fc6, guest PC 0x0c04c9a6 */
if(!s->budget--) { s->failed_pc=0x0c04c9a6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c9a8;
P_0c04c9a8: /* original 2fb6, guest PC 0x0c04c9a8 */
if(!s->budget--) { s->failed_pc=0x0c04c9a8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c9aa;
P_0c04c9aa: /* original 2fa6, guest PC 0x0c04c9aa */
if(!s->budget--) { s->failed_pc=0x0c04c9aau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c9ac;
P_0c04c9ac: /* original d223, guest PC 0x0c04c9ac */
if(!s->budget--) { s->failed_pc=0x0c04c9acu; return 0; }
r[2]=read(ram,0x0c04ca3cu,4);
goto P_0c04c9ae;
P_0c04c9ae: /* original 4f22, guest PC 0x0c04c9ae */
if(!s->budget--) { s->failed_pc=0x0c04c9aeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04c9b0;
P_0c04c9b0: /* original 6322, guest PC 0x0c04c9b0 */
if(!s->budget--) { s->failed_pc=0x0c04c9b0u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c04c9b2;
P_0c04c9b2: /* original 5132, guest PC 0x0c04c9b2 */
if(!s->budget--) { s->failed_pc=0x0c04c9b2u; return 0; }
r[1]=read(ram,r[3]+8,4);
goto P_0c04c9b4;
P_0c04c9b4: /* original 4f12, guest PC 0x0c04c9b4 */
if(!s->budget--) { s->failed_pc=0x0c04c9b4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04c9b6;
P_0c04c9b6: /* original 2118, guest PC 0x0c04c9b6 */
if(!s->budget--) { s->failed_pc=0x0c04c9b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c04c9b8;
P_0c04c9b8: /* original 8d34, guest PC 0x0c04c9b8 */
if(!s->budget--) { s->failed_pc=0x0c04c9b8u; return 0; }
cond=r[17]&1u;
r[12]=r[4];
if(cond) { goto P_0c04ca24; }
goto P_0c04c9bc;
P_0c04c9ba: /* original 6c43, guest PC 0x0c04c9ba */
if(!s->budget--) { s->failed_pc=0x0c04c9bau; return 0; }
r[12]=r[4];
goto P_0c04c9bc;
P_0c04c9bc: /* original 2558, guest PC 0x0c04c9bc */
if(!s->budget--) { s->failed_pc=0x0c04c9bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c04c9be;
P_0c04c9be: /* original 8931, guest PC 0x0c04c9be */
if(!s->budget--) { s->failed_pc=0x0c04c9beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ca24; }
goto P_0c04c9c0;
P_0c04c9c0: /* original 9e33, guest PC 0x0c04c9c0 */
if(!s->budget--) { s->failed_pc=0x0c04c9c0u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ca2au,2);
goto P_0c04c9c2;
P_0c04c9c2: /* original d31b, guest PC 0x0c04c9c2 */
if(!s->budget--) { s->failed_pc=0x0c04c9c2u; return 0; }
r[3]=read(ram,0x0c04ca30u,4);
goto P_0c04c9c4;
P_0c04c9c4: /* original 2cef, guest PC 0x0c04c9c4 */
if(!s->budget--) { s->failed_pc=0x0c04c9c4u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[12]*(int32_t)(int16_t)r[14]);
goto P_0c04c9c6;
P_0c04c9c6: /* original d71f, guest PC 0x0c04c9c6 */
if(!s->budget--) { s->failed_pc=0x0c04c9c6u; return 0; }
r[7]=read(ram,0x0c04ca44u,4);
goto P_0c04c9c8;
P_0c04c9c8: /* original d41d, guest PC 0x0c04c9c8 */
if(!s->budget--) { s->failed_pc=0x0c04c9c8u; return 0; }
r[4]=read(ram,0x0c04ca40u,4);
goto P_0c04c9ca;
P_0c04c9ca: /* original 0e1a, guest PC 0x0c04c9ca */
if(!s->budget--) { s->failed_pc=0x0c04c9cau; return 0; }
r[14]=r[19];
goto P_0c04c9cc;
P_0c04c9cc: /* original 6eef, guest PC 0x0c04c9cc */
if(!s->budget--) { s->failed_pc=0x0c04c9ccu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04c9ce;
P_0c04c9ce: /* original 3e3c, guest PC 0x0c04c9ce */
if(!s->budget--) { s->failed_pc=0x0c04c9ceu; return 0; }
r[14]+=r[3];
goto P_0c04c9d0;
P_0c04c9d0: /* original 5de1, guest PC 0x0c04c9d0 */
if(!s->budget--) { s->failed_pc=0x0c04c9d0u; return 0; }
r[13]=read(ram,r[14]+4,4);
goto P_0c04c9d2;
P_0c04c9d2: /* original 60d3, guest PC 0x0c04c9d2 */
if(!s->budget--) { s->failed_pc=0x0c04c9d2u; return 0; }
r[0]=r[13];
goto P_0c04c9d4;
P_0c04c9d4: /* original 8800, guest PC 0x0c04c9d4 */
if(!s->budget--) { s->failed_pc=0x0c04c9d4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c04c9d6;
P_0c04c9d6: /* original 8907, guest PC 0x0c04c9d6 */
if(!s->budget--) { s->failed_pc=0x0c04c9d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c9e8; }
goto P_0c04c9d8;
P_0c04c9d8: /* original 8801, guest PC 0x0c04c9d8 */
if(!s->budget--) { s->failed_pc=0x0c04c9d8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c04c9da;
P_0c04c9da: /* original 8908, guest PC 0x0c04c9da */
if(!s->budget--) { s->failed_pc=0x0c04c9dau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c9ee; }
goto P_0c04c9dc;
P_0c04c9dc: /* original 8802, guest PC 0x0c04c9dc */
if(!s->budget--) { s->failed_pc=0x0c04c9dcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c04c9de;
P_0c04c9de: /* original 8909, guest PC 0x0c04c9de */
if(!s->budget--) { s->failed_pc=0x0c04c9deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c9f4; }
goto P_0c04c9e0;
P_0c04c9e0: /* original 8803, guest PC 0x0c04c9e0 */
if(!s->budget--) { s->failed_pc=0x0c04c9e0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c04c9e2;
P_0c04c9e2: /* original 890a, guest PC 0x0c04c9e2 */
if(!s->budget--) { s->failed_pc=0x0c04c9e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c9fa; }
goto P_0c04c9e4;
P_0c04c9e4: /* original a00c, guest PC 0x0c04c9e4 */
if(!s->budget--) { s->failed_pc=0x0c04c9e4u; return 0; }
goto P_0c04ca00;
P_0c04c9e6: /* original 0009, guest PC 0x0c04c9e6 */
if(!s->budget--) { s->failed_pc=0x0c04c9e6u; return 0; }
goto P_0c04c9e8;
P_0c04c9e8: /* original 6442, guest PC 0x0c04c9e8 */
if(!s->budget--) { s->failed_pc=0x0c04c9e8u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c04c9ea;
P_0c04c9ea: /* original a013, guest PC 0x0c04c9ea */
if(!s->budget--) { s->failed_pc=0x0c04c9eau; return 0; }
tmp=read(ram,r[7],4);
r[13]=tmp;
goto P_0c04ca14;
P_0c04c9ec: /* original 6d72, guest PC 0x0c04c9ec */
if(!s->budget--) { s->failed_pc=0x0c04c9ecu; return 0; }
tmp=read(ram,r[7],4);
r[13]=tmp;
goto P_0c04c9ee;
P_0c04c9ee: /* original 5441, guest PC 0x0c04c9ee */
if(!s->budget--) { s->failed_pc=0x0c04c9eeu; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c04c9f0;
P_0c04c9f0: /* original a010, guest PC 0x0c04c9f0 */
if(!s->budget--) { s->failed_pc=0x0c04c9f0u; return 0; }
r[13]=read(ram,r[7]+4,4);
goto P_0c04ca14;
P_0c04c9f2: /* original 5d71, guest PC 0x0c04c9f2 */
if(!s->budget--) { s->failed_pc=0x0c04c9f2u; return 0; }
r[13]=read(ram,r[7]+4,4);
goto P_0c04c9f4;
P_0c04c9f4: /* original 5442, guest PC 0x0c04c9f4 */
if(!s->budget--) { s->failed_pc=0x0c04c9f4u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c04c9f6;
P_0c04c9f6: /* original a00d, guest PC 0x0c04c9f6 */
if(!s->budget--) { s->failed_pc=0x0c04c9f6u; return 0; }
r[13]=read(ram,r[7]+8,4);
goto P_0c04ca14;
P_0c04c9f8: /* original 5d72, guest PC 0x0c04c9f8 */
if(!s->budget--) { s->failed_pc=0x0c04c9f8u; return 0; }
r[13]=read(ram,r[7]+8,4);
goto P_0c04c9fa;
P_0c04c9fa: /* original 5443, guest PC 0x0c04c9fa */
if(!s->budget--) { s->failed_pc=0x0c04c9fau; return 0; }
r[4]=read(ram,r[4]+12,4);
goto P_0c04c9fc;
P_0c04c9fc: /* original a00a, guest PC 0x0c04c9fc */
if(!s->budget--) { s->failed_pc=0x0c04c9fcu; return 0; }
r[13]=read(ram,r[7]+12,4);
goto P_0c04ca14;
P_0c04c9fe: /* original 5d73, guest PC 0x0c04c9fe */
if(!s->budget--) { s->failed_pc=0x0c04c9feu; return 0; }
r[13]=read(ram,r[7]+12,4);
goto P_0c04ca00;
P_0c04ca00: /* original 2fd6, guest PC 0x0c04ca00 */
if(!s->budget--) { s->failed_pc=0x0c04ca00u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ca02;
P_0c04ca02: /* original 9213, guest PC 0x0c04ca02 */
if(!s->budget--) { s->failed_pc=0x0c04ca02u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ca2cu,2);
goto P_0c04ca04;
P_0c04ca04: /* original 2f26, guest PC 0x0c04ca04 */
if(!s->budget--) { s->failed_pc=0x0c04ca04u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ca06;
P_0c04ca06: /* original d110, guest PC 0x0c04ca06 */
if(!s->budget--) { s->failed_pc=0x0c04ca06u; return 0; }
r[1]=read(ram,0x0c04ca48u,4);
goto P_0c04ca08;
P_0c04ca08: /* original 2f16, guest PC 0x0c04ca08 */
if(!s->budget--) { s->failed_pc=0x0c04ca08u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ca0a;
P_0c04ca0a: /* original d310, guest PC 0x0c04ca0a */
if(!s->budget--) { s->failed_pc=0x0c04ca0au; return 0; }
r[3]=read(ram,0x0c04ca4cu,4);
goto P_0c04ca0c;
P_0c04ca0c: /* original bdc8, guest PC 0x0c04ca0c */
if(!s->budget--) { s->failed_pc=0x0c04ca0cu; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04ca10u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04ca10u) { target=s->pc; goto dispatch; }
goto P_0c04ca10;
P_0c04ca0e: /* original 2f36, guest PC 0x0c04ca0e */
if(!s->budget--) { s->failed_pc=0x0c04ca0eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ca10;
P_0c04ca10: /* original a008, guest PC 0x0c04ca10 */
if(!s->budget--) { s->failed_pc=0x0c04ca10u; return 0; }
r[15]+=0x00000010u;
goto P_0c04ca24;
P_0c04ca12: /* original 7f10, guest PC 0x0c04ca12 */
if(!s->budget--) { s->failed_pc=0x0c04ca12u; return 0; }
r[15]+=0x00000010u;
goto P_0c04ca14;
P_0c04ca14: /* original 6743, guest PC 0x0c04ca14 */
if(!s->budget--) { s->failed_pc=0x0c04ca14u; return 0; }
r[7]=r[4];
goto P_0c04ca16;
P_0c04ca16: /* original 37dc, guest PC 0x0c04ca16 */
if(!s->budget--) { s->failed_pc=0x0c04ca16u; return 0; }
r[7]+=r[13];
goto P_0c04ca18;
P_0c04ca18: /* original 7701, guest PC 0x0c04ca18 */
if(!s->budget--) { s->failed_pc=0x0c04ca18u; return 0; }
r[7]+=0x00000001u;
goto P_0c04ca1a;
P_0c04ca1a: /* original 4718, guest PC 0x0c04ca1a */
if(!s->budget--) { s->failed_pc=0x0c04ca1au; return 0; }
r[7]<<=8;
goto P_0c04ca1c;
P_0c04ca1c: /* original 4700, guest PC 0x0c04ca1c */
if(!s->budget--) { s->failed_pc=0x0c04ca1cu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c04ca1e;
P_0c04ca1e: /* original 7720, guest PC 0x0c04ca1e */
if(!s->budget--) { s->failed_pc=0x0c04ca1eu; return 0; }
r[7]+=0x00000020u;
goto P_0c04ca20;
P_0c04ca20: /* original 3767, guest PC 0x0c04ca20 */
if(!s->budget--) { s->failed_pc=0x0c04ca20u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>(int32_t)r[6])!=0);
goto P_0c04ca22;
P_0c04ca22: /* original 8b15, guest PC 0x0c04ca22 */
if(!s->budget--) { s->failed_pc=0x0c04ca22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ca50; }
goto P_0c04ca24;
P_0c04ca24: /* original 9003, guest PC 0x0c04ca24 */
if(!s->budget--) { s->failed_pc=0x0c04ca24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ca2eu,2);
goto P_0c04ca26;
P_0c04ca26: /* original a082, guest PC 0x0c04ca26 */
if(!s->budget--) { s->failed_pc=0x0c04ca26u; return 0; }
goto P_0c04cb2e;
P_0c04ca28: /* original 0009, guest PC 0x0c04ca28 */
if(!s->budget--) { s->failed_pc=0x0c04ca28u; return 0; }
if(!vf3_matrix_family(0x0c04ca2au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04ca2au; return 0; } return 1;
P_0c04ca50: /* original e34c, guest PC 0x0c04ca50 */
if(!s->budget--) { s->failed_pc=0x0c04ca50u; return 0; }
r[3]=0x0000004cu;
goto P_0c04ca52;
P_0c04ca52: /* original 2c3f, guest PC 0x0c04ca52 */
if(!s->budget--) { s->failed_pc=0x0c04ca52u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[12]*(int32_t)(int16_t)r[3]);
goto P_0c04ca54;
P_0c04ca54: /* original eb01, guest PC 0x0c04ca54 */
if(!s->budget--) { s->failed_pc=0x0c04ca54u; return 0; }
r[11]=0x00000001u;
goto P_0c04ca56;
P_0c04ca56: /* original 60b3, guest PC 0x0c04ca56 */
if(!s->budget--) { s->failed_pc=0x0c04ca56u; return 0; }
r[0]=r[11];
goto P_0c04ca58;
P_0c04ca58: /* original 80e2, guest PC 0x0c04ca58 */
if(!s->budget--) { s->failed_pc=0x0c04ca58u; return 0; }
write(ram,r[14]+2,r[0],1);
goto P_0c04ca5a;
P_0c04ca5a: /* original e000, guest PC 0x0c04ca5a */
if(!s->budget--) { s->failed_pc=0x0c04ca5au; return 0; }
r[0]=0x00000000u;
goto P_0c04ca5c;
P_0c04ca5c: /* original 2ec1, guest PC 0x0c04ca5c */
if(!s->budget--) { s->failed_pc=0x0c04ca5cu; return 0; }
write(ram,r[14],r[12],2);
goto P_0c04ca5e;
P_0c04ca5e: /* original 031a, guest PC 0x0c04ca5e */
if(!s->budget--) { s->failed_pc=0x0c04ca5eu; return 0; }
r[3]=r[19];
goto P_0c04ca60;
P_0c04ca60: /* original d24f, guest PC 0x0c04ca60 */
if(!s->budget--) { s->failed_pc=0x0c04ca60u; return 0; }
r[2]=read(ram,0x0c04cba0u,4);
goto P_0c04ca62;
P_0c04ca62: /* original 633f, guest PC 0x0c04ca62 */
if(!s->budget--) { s->failed_pc=0x0c04ca62u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04ca64;
P_0c04ca64: /* original 332c, guest PC 0x0c04ca64 */
if(!s->budget--) { s->failed_pc=0x0c04ca64u; return 0; }
r[3]+=r[2];
goto P_0c04ca66;
P_0c04ca66: /* original 1e37, guest PC 0x0c04ca66 */
if(!s->budget--) { s->failed_pc=0x0c04ca66u; return 0; }
write(ram,r[14]+28,r[3],4);
goto P_0c04ca68;
P_0c04ca68: /* original 6353, guest PC 0x0c04ca68 */
if(!s->budget--) { s->failed_pc=0x0c04ca68u; return 0; }
r[3]=r[5];
goto P_0c04ca6a;
P_0c04ca6a: /* original 7320, guest PC 0x0c04ca6a */
if(!s->budget--) { s->failed_pc=0x0c04ca6au; return 0; }
r[3]+=0x00000020u;
goto P_0c04ca6c;
P_0c04ca6c: /* original 80ea, guest PC 0x0c04ca6c */
if(!s->budget--) { s->failed_pc=0x0c04ca6cu; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c04ca6e;
P_0c04ca6e: /* original 80eb, guest PC 0x0c04ca6e */
if(!s->budget--) { s->failed_pc=0x0c04ca6eu; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c04ca70;
P_0c04ca70: /* original 80ec, guest PC 0x0c04ca70 */
if(!s->budget--) { s->failed_pc=0x0c04ca70u; return 0; }
write(ram,r[14]+12,r[0],1);
goto P_0c04ca72;
P_0c04ca72: /* original 60b3, guest PC 0x0c04ca72 */
if(!s->budget--) { s->failed_pc=0x0c04ca72u; return 0; }
r[0]=r[11];
goto P_0c04ca74;
P_0c04ca74: /* original 1e5b, guest PC 0x0c04ca74 */
if(!s->budget--) { s->failed_pc=0x0c04ca74u; return 0; }
write(ram,r[14]+44,r[5],4);
goto P_0c04ca76;
P_0c04ca76: /* original 1e38, guest PC 0x0c04ca76 */
if(!s->budget--) { s->failed_pc=0x0c04ca76u; return 0; }
write(ram,r[14]+32,r[3],4);
goto P_0c04ca78;
P_0c04ca78: /* original 6343, guest PC 0x0c04ca78 */
if(!s->budget--) { s->failed_pc=0x0c04ca78u; return 0; }
r[3]=r[4];
goto P_0c04ca7a;
P_0c04ca7a: /* original 7301, guest PC 0x0c04ca7a */
if(!s->budget--) { s->failed_pc=0x0c04ca7au; return 0; }
r[3]+=0x00000001u;
goto P_0c04ca7c;
P_0c04ca7c: /* original 918c, guest PC 0x0c04ca7c */
if(!s->budget--) { s->failed_pc=0x0c04ca7cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04cb98u,2);
goto P_0c04ca7e;
P_0c04ca7e: /* original 4318, guest PC 0x0c04ca7e */
if(!s->budget--) { s->failed_pc=0x0c04ca7eu; return 0; }
r[3]<<=8;
goto P_0c04ca80;
P_0c04ca80: /* original 4300, guest PC 0x0c04ca80 */
if(!s->budget--) { s->failed_pc=0x0c04ca80u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c04ca82;
P_0c04ca82: /* original 335c, guest PC 0x0c04ca82 */
if(!s->budget--) { s->failed_pc=0x0c04ca82u; return 0; }
r[3]+=r[5];
goto P_0c04ca84;
P_0c04ca84: /* original 7320, guest PC 0x0c04ca84 */
if(!s->budget--) { s->failed_pc=0x0c04ca84u; return 0; }
r[3]+=0x00000020u;
goto P_0c04ca86;
P_0c04ca86: /* original 315c, guest PC 0x0c04ca86 */
if(!s->budget--) { s->failed_pc=0x0c04ca86u; return 0; }
r[1]+=r[5];
goto P_0c04ca88;
P_0c04ca88: /* original 1e19, guest PC 0x0c04ca88 */
if(!s->budget--) { s->failed_pc=0x0c04ca88u; return 0; }
write(ram,r[14]+36,r[1],4);
goto P_0c04ca8a;
P_0c04ca8a: /* original 1e3a, guest PC 0x0c04ca8a */
if(!s->budget--) { s->failed_pc=0x0c04ca8au; return 0; }
write(ram,r[14]+40,r[3],4);
goto P_0c04ca8c;
P_0c04ca8c: /* original 81e7, guest PC 0x0c04ca8c */
if(!s->budget--) { s->failed_pc=0x0c04ca8cu; return 0; }
write(ram,r[14]+14,r[0],2);
goto P_0c04ca8e;
P_0c04ca8e: /* original 6043, guest PC 0x0c04ca8e */
if(!s->budget--) { s->failed_pc=0x0c04ca8eu; return 0; }
r[0]=r[4];
goto P_0c04ca90;
P_0c04ca90: /* original 81e8, guest PC 0x0c04ca90 */
if(!s->budget--) { s->failed_pc=0x0c04ca90u; return 0; }
write(ram,r[14]+16,r[0],2);
goto P_0c04ca92;
P_0c04ca92: /* original 60d3, guest PC 0x0c04ca92 */
if(!s->budget--) { s->failed_pc=0x0c04ca92u; return 0; }
r[0]=r[13];
goto P_0c04ca94;
P_0c04ca94: /* original 81e9, guest PC 0x0c04ca94 */
if(!s->budget--) { s->failed_pc=0x0c04ca94u; return 0; }
write(ram,r[14]+18,r[0],2);
goto P_0c04ca96;
P_0c04ca96: /* original e020, guest PC 0x0c04ca96 */
if(!s->budget--) { s->failed_pc=0x0c04ca96u; return 0; }
r[0]=0x00000020u;
goto P_0c04ca98;
P_0c04ca98: /* original e500, guest PC 0x0c04ca98 */
if(!s->budget--) { s->failed_pc=0x0c04ca98u; return 0; }
r[5]=0x00000000u;
goto P_0c04ca9a;
P_0c04ca9a: /* original 64e3, guest PC 0x0c04ca9a */
if(!s->budget--) { s->failed_pc=0x0c04ca9au; return 0; }
r[4]=r[14];
goto P_0c04ca9c;
P_0c04ca9c: /* original 81ea, guest PC 0x0c04ca9c */
if(!s->budget--) { s->failed_pc=0x0c04ca9cu; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c04ca9e;
P_0c04ca9e: /* original e610, guest PC 0x0c04ca9e */
if(!s->budget--) { s->failed_pc=0x0c04ca9eu; return 0; }
r[6]=0x00000010u;
goto P_0c04caa0;
P_0c04caa0: /* original da40, guest PC 0x0c04caa0 */
if(!s->budget--) { s->failed_pc=0x0c04caa0u; return 0; }
r[10]=read(ram,0x0c04cba4u,4);
goto P_0c04caa2;
P_0c04caa2: /* original 4a0b, guest PC 0x0c04caa2 */
if(!s->budget--) { s->failed_pc=0x0c04caa2u; return 0; }
target=r[10];
r[16]=code_base|0x0c04caa6u;
r[4]+=0x00000038u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04caa6u) { target=s->pc; goto dispatch; }
goto P_0c04caa6;
P_0c04caa4: /* original 7438, guest PC 0x0c04caa4 */
if(!s->budget--) { s->failed_pc=0x0c04caa4u; return 0; }
r[4]+=0x00000038u;
goto P_0c04caa6;
P_0c04caa6: /* original 9678, guest PC 0x0c04caa6 */
if(!s->budget--) { s->failed_pc=0x0c04caa6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04cb9au,2);
goto P_0c04caa8;
P_0c04caa8: /* original 64e3, guest PC 0x0c04caa8 */
if(!s->budget--) { s->failed_pc=0x0c04caa8u; return 0; }
r[4]=r[14];
goto P_0c04caaa;
P_0c04caaa: /* original e500, guest PC 0x0c04caaa */
if(!s->budget--) { s->failed_pc=0x0c04caaau; return 0; }
r[5]=0x00000000u;
goto P_0c04caac;
P_0c04caac: /* original 4a0b, guest PC 0x0c04caac */
if(!s->budget--) { s->failed_pc=0x0c04caacu; return 0; }
target=r[10];
r[16]=code_base|0x0c04cab0u;
r[4]+=0x00000048u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04cab0u) { target=s->pc; goto dispatch; }
goto P_0c04cab0;
P_0c04caae: /* original 7448, guest PC 0x0c04caae */
if(!s->budget--) { s->failed_pc=0x0c04caaeu; return 0; }
r[4]+=0x00000048u;
goto P_0c04cab0;
P_0c04cab0: /* original e547, guest PC 0x0c04cab0 */
if(!s->budget--) { s->failed_pc=0x0c04cab0u; return 0; }
r[5]=0x00000047u;
goto P_0c04cab2;
P_0c04cab2: /* original e620, guest PC 0x0c04cab2 */
if(!s->budget--) { s->failed_pc=0x0c04cab2u; return 0; }
r[6]=0x00000020u;
goto P_0c04cab4;
P_0c04cab4: /* original 4a0b, guest PC 0x0c04cab4 */
if(!s->budget--) { s->failed_pc=0x0c04cab4u; return 0; }
target=r[10];
r[16]=code_base|0x0c04cab8u;
r[4]=read(ram,r[14]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04cab8u) { target=s->pc; goto dispatch; }
goto P_0c04cab8;
P_0c04cab6: /* original 54eb, guest PC 0x0c04cab6 */
if(!s->budget--) { s->failed_pc=0x0c04cab6u; return 0; }
r[4]=read(ram,r[14]+44,4);
goto P_0c04cab8;
P_0c04cab8: /* original e553, guest PC 0x0c04cab8 */
if(!s->budget--) { s->failed_pc=0x0c04cab8u; return 0; }
r[5]=0x00000053u;
goto P_0c04caba;
P_0c04caba: /* original e620, guest PC 0x0c04caba */
if(!s->budget--) { s->failed_pc=0x0c04cabau; return 0; }
r[6]=0x00000020u;
goto P_0c04cabc;
P_0c04cabc: /* original 4a0b, guest PC 0x0c04cabc */
if(!s->budget--) { s->failed_pc=0x0c04cabcu; return 0; }
target=r[10];
r[16]=code_base|0x0c04cac0u;
r[4]=read(ram,r[14]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04cac0u) { target=s->pc; goto dispatch; }
goto P_0c04cac0;
P_0c04cabe: /* original 54e8, guest PC 0x0c04cabe */
if(!s->budget--) { s->failed_pc=0x0c04cabeu; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c04cac0;
P_0c04cac0: /* original e546, guest PC 0x0c04cac0 */
if(!s->budget--) { s->failed_pc=0x0c04cac0u; return 0; }
r[5]=0x00000046u;
goto P_0c04cac2;
P_0c04cac2: /* original e620, guest PC 0x0c04cac2 */
if(!s->budget--) { s->failed_pc=0x0c04cac2u; return 0; }
r[6]=0x00000020u;
goto P_0c04cac4;
P_0c04cac4: /* original 4a0b, guest PC 0x0c04cac4 */
if(!s->budget--) { s->failed_pc=0x0c04cac4u; return 0; }
target=r[10];
r[16]=code_base|0x0c04cac8u;
r[4]=read(ram,r[14]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04cac8u) { target=s->pc; goto dispatch; }
goto P_0c04cac8;
P_0c04cac6: /* original 54e9, guest PC 0x0c04cac6 */
if(!s->budget--) { s->failed_pc=0x0c04cac6u; return 0; }
r[4]=read(ram,r[14]+36,4);
goto P_0c04cac8;
P_0c04cac8: /* original e544, guest PC 0x0c04cac8 */
if(!s->budget--) { s->failed_pc=0x0c04cac8u; return 0; }
r[5]=0x00000044u;
goto P_0c04caca;
P_0c04caca: /* original e620, guest PC 0x0c04caca */
if(!s->budget--) { s->failed_pc=0x0c04cacau; return 0; }
r[6]=0x00000020u;
goto P_0c04cacc;
P_0c04cacc: /* original 4a0b, guest PC 0x0c04cacc */
if(!s->budget--) { s->failed_pc=0x0c04caccu; return 0; }
target=r[10];
r[16]=code_base|0x0c04cad0u;
r[4]=read(ram,r[14]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04cad0u) { target=s->pc; goto dispatch; }
goto P_0c04cad0;
P_0c04cace: /* original 54ea, guest PC 0x0c04cace */
if(!s->budget--) { s->failed_pc=0x0c04caceu; return 0; }
r[4]=read(ram,r[14]+40,4);
goto P_0c04cad0;
P_0c04cad0: /* original 2fc6, guest PC 0x0c04cad0 */
if(!s->budget--) { s->failed_pc=0x0c04cad0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cad2;
P_0c04cad2: /* original d335, guest PC 0x0c04cad2 */
if(!s->budget--) { s->failed_pc=0x0c04cad2u; return 0; }
r[3]=read(ram,0x0c04cba8u,4);
goto P_0c04cad4;
P_0c04cad4: /* original bd64, guest PC 0x0c04cad4 */
if(!s->budget--) { s->failed_pc=0x0c04cad4u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04cad8u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04cad8u) { target=s->pc; goto dispatch; }
goto P_0c04cad8;
P_0c04cad6: /* original 2f36, guest PC 0x0c04cad6 */
if(!s->budget--) { s->failed_pc=0x0c04cad6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cad8;
P_0c04cad8: /* original 51e8, guest PC 0x0c04cad8 */
if(!s->budget--) { s->failed_pc=0x0c04cad8u; return 0; }
r[1]=read(ram,r[14]+32,4);
goto P_0c04cada;
P_0c04cada: /* original 71ff, guest PC 0x0c04cada */
if(!s->budget--) { s->failed_pc=0x0c04cadau; return 0; }
r[1]+=0xffffffffu;
goto P_0c04cadc;
P_0c04cadc: /* original 2f16, guest PC 0x0c04cadc */
if(!s->budget--) { s->failed_pc=0x0c04cadcu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cade;
P_0c04cade: /* original 53eb, guest PC 0x0c04cade */
if(!s->budget--) { s->failed_pc=0x0c04cadeu; return 0; }
r[3]=read(ram,r[14]+44,4);
goto P_0c04cae0;
P_0c04cae0: /* original 2f36, guest PC 0x0c04cae0 */
if(!s->budget--) { s->failed_pc=0x0c04cae0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cae2;
P_0c04cae2: /* original d232, guest PC 0x0c04cae2 */
if(!s->budget--) { s->failed_pc=0x0c04cae2u; return 0; }
r[2]=read(ram,0x0c04cbacu,4);
goto P_0c04cae4;
P_0c04cae4: /* original bd5c, guest PC 0x0c04cae4 */
if(!s->budget--) { s->failed_pc=0x0c04cae4u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04cae8u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04cae8u) { target=s->pc; goto dispatch; }
goto P_0c04cae8;
P_0c04cae6: /* original 2f26, guest PC 0x0c04cae6 */
if(!s->budget--) { s->failed_pc=0x0c04cae6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cae8;
P_0c04cae8: /* original 51e9, guest PC 0x0c04cae8 */
if(!s->budget--) { s->failed_pc=0x0c04cae8u; return 0; }
r[1]=read(ram,r[14]+36,4);
goto P_0c04caea;
P_0c04caea: /* original 71ff, guest PC 0x0c04caea */
if(!s->budget--) { s->failed_pc=0x0c04caeau; return 0; }
r[1]+=0xffffffffu;
goto P_0c04caec;
P_0c04caec: /* original 2f16, guest PC 0x0c04caec */
if(!s->budget--) { s->failed_pc=0x0c04caecu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04caee;
P_0c04caee: /* original 53e8, guest PC 0x0c04caee */
if(!s->budget--) { s->failed_pc=0x0c04caeeu; return 0; }
r[3]=read(ram,r[14]+32,4);
goto P_0c04caf0;
P_0c04caf0: /* original 2f36, guest PC 0x0c04caf0 */
if(!s->budget--) { s->failed_pc=0x0c04caf0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04caf2;
P_0c04caf2: /* original d22f, guest PC 0x0c04caf2 */
if(!s->budget--) { s->failed_pc=0x0c04caf2u; return 0; }
r[2]=read(ram,0x0c04cbb0u,4);
goto P_0c04caf4;
P_0c04caf4: /* original bd54, guest PC 0x0c04caf4 */
if(!s->budget--) { s->failed_pc=0x0c04caf4u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04caf8u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04caf8u) { target=s->pc; goto dispatch; }
goto P_0c04caf8;
P_0c04caf6: /* original 2f26, guest PC 0x0c04caf6 */
if(!s->budget--) { s->failed_pc=0x0c04caf6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04caf8;
P_0c04caf8: /* original 51ea, guest PC 0x0c04caf8 */
if(!s->budget--) { s->failed_pc=0x0c04caf8u; return 0; }
r[1]=read(ram,r[14]+40,4);
goto P_0c04cafa;
P_0c04cafa: /* original 71ff, guest PC 0x0c04cafa */
if(!s->budget--) { s->failed_pc=0x0c04cafau; return 0; }
r[1]+=0xffffffffu;
goto P_0c04cafc;
P_0c04cafc: /* original 2f16, guest PC 0x0c04cafc */
if(!s->budget--) { s->failed_pc=0x0c04cafcu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cafe;
P_0c04cafe: /* original 53e9, guest PC 0x0c04cafe */
if(!s->budget--) { s->failed_pc=0x0c04cafeu; return 0; }
r[3]=read(ram,r[14]+36,4);
goto P_0c04cb00;
P_0c04cb00: /* original 2f36, guest PC 0x0c04cb00 */
if(!s->budget--) { s->failed_pc=0x0c04cb00u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cb02;
P_0c04cb02: /* original d22c, guest PC 0x0c04cb02 */
if(!s->budget--) { s->failed_pc=0x0c04cb02u; return 0; }
r[2]=read(ram,0x0c04cbb4u,4);
goto P_0c04cb04;
P_0c04cb04: /* original bd4c, guest PC 0x0c04cb04 */
if(!s->budget--) { s->failed_pc=0x0c04cb04u; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04cb08u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04cb08u) { target=s->pc; goto dispatch; }
goto P_0c04cb08;
P_0c04cb06: /* original 2f26, guest PC 0x0c04cb06 */
if(!s->budget--) { s->failed_pc=0x0c04cb06u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cb08;
P_0c04cb08: /* original 52ea, guest PC 0x0c04cb08 */
if(!s->budget--) { s->failed_pc=0x0c04cb08u; return 0; }
r[2]=read(ram,r[14]+40,4);
goto P_0c04cb0a;
P_0c04cb0a: /* original 4d18, guest PC 0x0c04cb0a */
if(!s->budget--) { s->failed_pc=0x0c04cb0au; return 0; }
r[13]<<=8;
goto P_0c04cb0c;
P_0c04cb0c: /* original 4d00, guest PC 0x0c04cb0c */
if(!s->budget--) { s->failed_pc=0x0c04cb0cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c04cb0e;
P_0c04cb0e: /* original 3d2c, guest PC 0x0c04cb0e */
if(!s->budget--) { s->failed_pc=0x0c04cb0eu; return 0; }
r[13]+=r[2];
goto P_0c04cb10;
P_0c04cb10: /* original 7dff, guest PC 0x0c04cb10 */
if(!s->budget--) { s->failed_pc=0x0c04cb10u; return 0; }
r[13]+=0xffffffffu;
goto P_0c04cb12;
P_0c04cb12: /* original 2fd6, guest PC 0x0c04cb12 */
if(!s->budget--) { s->failed_pc=0x0c04cb12u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cb14;
P_0c04cb14: /* original 53ea, guest PC 0x0c04cb14 */
if(!s->budget--) { s->failed_pc=0x0c04cb14u; return 0; }
r[3]=read(ram,r[14]+40,4);
goto P_0c04cb16;
P_0c04cb16: /* original 2f36, guest PC 0x0c04cb16 */
if(!s->budget--) { s->failed_pc=0x0c04cb16u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cb18;
P_0c04cb18: /* original d227, guest PC 0x0c04cb18 */
if(!s->budget--) { s->failed_pc=0x0c04cb18u; return 0; }
r[2]=read(ram,0x0c04cbb8u,4);
goto P_0c04cb1a;
P_0c04cb1a: /* original bd41, guest PC 0x0c04cb1a */
if(!s->budget--) { s->failed_pc=0x0c04cb1au; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04cb1eu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04cb1eu) { target=s->pc; goto dispatch; }
goto P_0c04cb1e;
P_0c04cb1c: /* original 2f26, guest PC 0x0c04cb1c */
if(!s->budget--) { s->failed_pc=0x0c04cb1cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cb1e;
P_0c04cb1e: /* original 54e7, guest PC 0x0c04cb1e */
if(!s->budget--) { s->failed_pc=0x0c04cb1eu; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c04cb20;
P_0c04cb20: /* original 60b3, guest PC 0x0c04cb20 */
if(!s->budget--) { s->failed_pc=0x0c04cb20u; return 0; }
r[0]=r[11];
goto P_0c04cb22;
P_0c04cb22: /* original 7f38, guest PC 0x0c04cb22 */
if(!s->budget--) { s->failed_pc=0x0c04cb22u; return 0; }
r[15]+=0x00000038u;
goto P_0c04cb24;
P_0c04cb24: /* original 5247, guest PC 0x0c04cb24 */
if(!s->budget--) { s->failed_pc=0x0c04cb24u; return 0; }
r[2]=read(ram,r[4]+28,4);
goto P_0c04cb26;
P_0c04cb26: /* original 142c, guest PC 0x0c04cb26 */
if(!s->budget--) { s->failed_pc=0x0c04cb26u; return 0; }
write(ram,r[4]+48,r[2],4);
goto P_0c04cb28;
P_0c04cb28: /* original 80e8, guest PC 0x0c04cb28 */
if(!s->budget--) { s->failed_pc=0x0c04cb28u; return 0; }
write(ram,r[14]+8,r[0],1);
goto P_0c04cb2a;
P_0c04cb2a: /* original 80e9, guest PC 0x0c04cb2a */
if(!s->budget--) { s->failed_pc=0x0c04cb2au; return 0; }
write(ram,r[14]+9,r[0],1);
goto P_0c04cb2c;
P_0c04cb2c: /* original e000, guest PC 0x0c04cb2c */
if(!s->budget--) { s->failed_pc=0x0c04cb2cu; return 0; }
r[0]=0x00000000u;
goto P_0c04cb2e;
P_0c04cb2e: /* original 4f16, guest PC 0x0c04cb2e */
if(!s->budget--) { s->failed_pc=0x0c04cb2eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04cb30;
P_0c04cb30: /* original 4f26, guest PC 0x0c04cb30 */
if(!s->budget--) { s->failed_pc=0x0c04cb30u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04cb32;
P_0c04cb32: /* original 6af6, guest PC 0x0c04cb32 */
if(!s->budget--) { s->failed_pc=0x0c04cb32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04cb34;
P_0c04cb34: /* original 6bf6, guest PC 0x0c04cb34 */
if(!s->budget--) { s->failed_pc=0x0c04cb34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04cb36;
P_0c04cb36: /* original 6cf6, guest PC 0x0c04cb36 */
if(!s->budget--) { s->failed_pc=0x0c04cb36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04cb38;
P_0c04cb38: /* original 6df6, guest PC 0x0c04cb38 */
if(!s->budget--) { s->failed_pc=0x0c04cb38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04cb3a;
P_0c04cb3a: /* original 000b, guest PC 0x0c04cb3a */
if(!s->budget--) { s->failed_pc=0x0c04cb3au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04cb3c: /* original 6ef6, guest PC 0x0c04cb3c */
if(!s->budget--) { s->failed_pc=0x0c04cb3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04cb3eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04cb3eu; return 0; } return 1;
P_0c04cc08: /* original 2fe6, guest PC 0x0c04cc08 */
if(!s->budget--) { s->failed_pc=0x0c04cc08u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cc0a;
P_0c04cc0a: /* original 2fd6, guest PC 0x0c04cc0a */
if(!s->budget--) { s->failed_pc=0x0c04cc0au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cc0c;
P_0c04cc0c: /* original 6d43, guest PC 0x0c04cc0c */
if(!s->budget--) { s->failed_pc=0x0c04cc0cu; return 0; }
r[13]=r[4];
goto P_0c04cc0e;
P_0c04cc0e: /* original 2fc6, guest PC 0x0c04cc0e */
if(!s->budget--) { s->failed_pc=0x0c04cc0eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cc10;
P_0c04cc10: /* original 2fb6, guest PC 0x0c04cc10 */
if(!s->budget--) { s->failed_pc=0x0c04cc10u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cc12;
P_0c04cc12: /* original 4f22, guest PC 0x0c04cc12 */
if(!s->budget--) { s->failed_pc=0x0c04cc12u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04cc14;
P_0c04cc14: /* original 9e74, guest PC 0x0c04cc14 */
if(!s->budget--) { s->failed_pc=0x0c04cc14u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04cd00u,2);
goto P_0c04cc16;
P_0c04cc16: /* original 4f12, guest PC 0x0c04cc16 */
if(!s->budget--) { s->failed_pc=0x0c04cc16u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04cc18;
P_0c04cc18: /* original 2def, guest PC 0x0c04cc18 */
if(!s->budget--) { s->failed_pc=0x0c04cc18u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[14]);
goto P_0c04cc1a;
P_0c04cc1a: /* original 7ffc, guest PC 0x0c04cc1a */
if(!s->budget--) { s->failed_pc=0x0c04cc1au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04cc1c;
P_0c04cc1c: /* original 0e1a, guest PC 0x0c04cc1c */
if(!s->budget--) { s->failed_pc=0x0c04cc1cu; return 0; }
r[14]=r[19];
goto P_0c04cc1e;
P_0c04cc1e: /* original 6eef, guest PC 0x0c04cc1e */
if(!s->budget--) { s->failed_pc=0x0c04cc1eu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04cc20;
P_0c04cc20: /* original 2fe2, guest PC 0x0c04cc20 */
if(!s->budget--) { s->failed_pc=0x0c04cc20u; return 0; }
write(ram,r[15],r[14],4);
goto P_0c04cc22;
P_0c04cc22: /* original d338, guest PC 0x0c04cc22 */
if(!s->budget--) { s->failed_pc=0x0c04cc22u; return 0; }
r[3]=read(ram,0x0c04cd04u,4);
goto P_0c04cc24;
P_0c04cc24: /* original 2fd6, guest PC 0x0c04cc24 */
if(!s->budget--) { s->failed_pc=0x0c04cc24u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cc26;
P_0c04cc26: /* original d239, guest PC 0x0c04cc26 */
if(!s->budget--) { s->failed_pc=0x0c04cc26u; return 0; }
r[2]=read(ram,0x0c04cd0cu,4);
goto P_0c04cc28;
P_0c04cc28: /* original 3e3c, guest PC 0x0c04cc28 */
if(!s->budget--) { s->failed_pc=0x0c04cc28u; return 0; }
r[14]+=r[3];
goto P_0c04cc2a;
P_0c04cc2a: /* original bcb9, guest PC 0x0c04cc2a */
if(!s->budget--) { s->failed_pc=0x0c04cc2au; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04cc2eu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04cc2eu) { target=s->pc; goto dispatch; }
goto P_0c04cc2e;
P_0c04cc2c: /* original 2f26, guest PC 0x0c04cc2c */
if(!s->budget--) { s->failed_pc=0x0c04cc2cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cc2e;
P_0c04cc2e: /* original d338, guest PC 0x0c04cc2e */
if(!s->budget--) { s->failed_pc=0x0c04cc2eu; return 0; }
r[3]=read(ram,0x0c04cd10u,4);
goto P_0c04cc30;
P_0c04cc30: /* original 6032, guest PC 0x0c04cc30 */
if(!s->budget--) { s->failed_pc=0x0c04cc30u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c04cc32;
P_0c04cc32: /* original 5002, guest PC 0x0c04cc32 */
if(!s->budget--) { s->failed_pc=0x0c04cc32u; return 0; }
r[0]=read(ram,r[0]+8,4);
goto P_0c04cc34;
P_0c04cc34: /* original 8801, guest PC 0x0c04cc34 */
if(!s->budget--) { s->failed_pc=0x0c04cc34u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c04cc36;
P_0c04cc36: /* original 8f09, guest PC 0x0c04cc36 */
if(!s->budget--) { s->failed_pc=0x0c04cc36u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000008u;
if(!cond) { goto P_0c04cc4c; }
goto P_0c04cc3a;
P_0c04cc38: /* original 7f08, guest PC 0x0c04cc38 */
if(!s->budget--) { s->failed_pc=0x0c04cc38u; return 0; }
r[15]+=0x00000008u;
goto P_0c04cc3a;
P_0c04cc3a: /* original 7f04, guest PC 0x0c04cc3a */
if(!s->budget--) { s->failed_pc=0x0c04cc3au; return 0; }
r[15]+=0x00000004u;
goto P_0c04cc3c;
P_0c04cc3c: /* original 64d3, guest PC 0x0c04cc3c */
if(!s->budget--) { s->failed_pc=0x0c04cc3cu; return 0; }
r[4]=r[13];
goto P_0c04cc3e;
P_0c04cc3e: /* original 4f16, guest PC 0x0c04cc3e */
if(!s->budget--) { s->failed_pc=0x0c04cc3eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04cc40;
P_0c04cc40: /* original 4f26, guest PC 0x0c04cc40 */
if(!s->budget--) { s->failed_pc=0x0c04cc40u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04cc42;
P_0c04cc42: /* original 6bf6, guest PC 0x0c04cc42 */
if(!s->budget--) { s->failed_pc=0x0c04cc42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04cc44;
P_0c04cc44: /* original 6cf6, guest PC 0x0c04cc44 */
if(!s->budget--) { s->failed_pc=0x0c04cc44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04cc46;
P_0c04cc46: /* original 6df6, guest PC 0x0c04cc46 */
if(!s->budget--) { s->failed_pc=0x0c04cc46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04cc48;
P_0c04cc48: /* original a0f8, guest PC 0x0c04cc48 */
if(!s->budget--) { s->failed_pc=0x0c04cc48u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04ce3cu,s,ram);
P_0c04cc4a: /* original 6ef6, guest PC 0x0c04cc4a */
if(!s->budget--) { s->failed_pc=0x0c04cc4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04cc4c;
P_0c04cc4c: /* original 6cf2, guest PC 0x0c04cc4c */
if(!s->budget--) { s->failed_pc=0x0c04cc4cu; return 0; }
tmp=read(ram,r[15],4);
r[12]=tmp;
goto P_0c04cc4e;
P_0c04cc4e: /* original d32d, guest PC 0x0c04cc4e */
if(!s->budget--) { s->failed_pc=0x0c04cc4eu; return 0; }
r[3]=read(ram,0x0c04cd04u,4);
goto P_0c04cc50;
P_0c04cc50: /* original 3c3c, guest PC 0x0c04cc50 */
if(!s->budget--) { s->failed_pc=0x0c04cc50u; return 0; }
r[12]+=r[3];
goto P_0c04cc52;
P_0c04cc52: /* original 84c2, guest PC 0x0c04cc52 */
if(!s->budget--) { s->failed_pc=0x0c04cc52u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+2,1);
goto P_0c04cc54;
P_0c04cc54: /* original 2008, guest PC 0x0c04cc54 */
if(!s->budget--) { s->failed_pc=0x0c04cc54u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04cc56;
P_0c04cc56: /* original 892d, guest PC 0x0c04cc56 */
if(!s->budget--) { s->failed_pc=0x0c04cc56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ccb4; }
goto P_0c04cc58;
P_0c04cc58: /* original eb01, guest PC 0x0c04cc58 */
if(!s->budget--) { s->failed_pc=0x0c04cc58u; return 0; }
r[11]=0x00000001u;
goto P_0c04cc5a;
P_0c04cc5a: /* original 1cbc, guest PC 0x0c04cc5a */
if(!s->budget--) { s->failed_pc=0x0c04cc5au; return 0; }
write(ram,r[12]+48,r[11],4);
goto P_0c04cc5c;
P_0c04cc5c: /* original 53c1, guest PC 0x0c04cc5c */
if(!s->budget--) { s->failed_pc=0x0c04cc5cu; return 0; }
r[3]=read(ram,r[12]+4,4);
goto P_0c04cc5e;
P_0c04cc5e: /* original d02d, guest PC 0x0c04cc5e */
if(!s->budget--) { s->failed_pc=0x0c04cc5eu; return 0; }
r[0]=read(ram,0x0c04cd14u,4);
goto P_0c04cc60;
P_0c04cc60: /* original 6233, guest PC 0x0c04cc60 */
if(!s->budget--) { s->failed_pc=0x0c04cc60u; return 0; }
r[2]=r[3];
goto P_0c04cc62;
P_0c04cc62: /* original 4308, guest PC 0x0c04cc62 */
if(!s->budget--) { s->failed_pc=0x0c04cc62u; return 0; }
r[3]<<=2;
goto P_0c04cc64;
P_0c04cc64: /* original 332c, guest PC 0x0c04cc64 */
if(!s->budget--) { s->failed_pc=0x0c04cc64u; return 0; }
r[3]+=r[2];
goto P_0c04cc66;
P_0c04cc66: /* original 4308, guest PC 0x0c04cc66 */
if(!s->budget--) { s->failed_pc=0x0c04cc66u; return 0; }
r[3]<<=2;
goto P_0c04cc68;
P_0c04cc68: /* original 4308, guest PC 0x0c04cc68 */
if(!s->budget--) { s->failed_pc=0x0c04cc68u; return 0; }
r[3]<<=2;
goto P_0c04cc6a;
P_0c04cc6a: /* original 633f, guest PC 0x0c04cc6a */
if(!s->budget--) { s->failed_pc=0x0c04cc6au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04cc6c;
P_0c04cc6c: /* original 013e, guest PC 0x0c04cc6c */
if(!s->budget--) { s->failed_pc=0x0c04cc6cu; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c04cc6e;
P_0c04cc6e: /* original 63d3, guest PC 0x0c04cc6e */
if(!s->budget--) { s->failed_pc=0x0c04cc6eu; return 0; }
r[3]=r[13];
goto P_0c04cc70;
P_0c04cc70: /* original 4308, guest PC 0x0c04cc70 */
if(!s->budget--) { s->failed_pc=0x0c04cc70u; return 0; }
r[3]<<=2;
goto P_0c04cc72;
P_0c04cc72: /* original 4308, guest PC 0x0c04cc72 */
if(!s->budget--) { s->failed_pc=0x0c04cc72u; return 0; }
r[3]<<=2;
goto P_0c04cc74;
P_0c04cc74: /* original 1c1d, guest PC 0x0c04cc74 */
if(!s->budget--) { s->failed_pc=0x0c04cc74u; return 0; }
write(ram,r[12]+52,r[1],4);
goto P_0c04cc76;
P_0c04cc76: /* original 4308, guest PC 0x0c04cc76 */
if(!s->budget--) { s->failed_pc=0x0c04cc76u; return 0; }
r[3]<<=2;
goto P_0c04cc78;
P_0c04cc78: /* original d227, guest PC 0x0c04cc78 */
if(!s->budget--) { s->failed_pc=0x0c04cc78u; return 0; }
r[2]=read(ram,0x0c04cd18u,4);
goto P_0c04cc7a;
P_0c04cc7a: /* original 4300, guest PC 0x0c04cc7a */
if(!s->budget--) { s->failed_pc=0x0c04cc7au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c04cc7c;
P_0c04cc7c: /* original 332c, guest PC 0x0c04cc7c */
if(!s->budget--) { s->failed_pc=0x0c04cc7cu; return 0; }
r[3]+=r[2];
goto P_0c04cc7e;
P_0c04cc7e: /* original 2f32, guest PC 0x0c04cc7e */
if(!s->budget--) { s->failed_pc=0x0c04cc7eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c04cc80;
P_0c04cc80: /* original 56cc, guest PC 0x0c04cc80 */
if(!s->budget--) { s->failed_pc=0x0c04cc80u; return 0; }
r[6]=read(ram,r[12]+48,4);
goto P_0c04cc82;
P_0c04cc82: /* original 57cd, guest PC 0x0c04cc82 */
if(!s->budget--) { s->failed_pc=0x0c04cc82u; return 0; }
r[7]=read(ram,r[12]+52,4);
goto P_0c04cc84;
P_0c04cc84: /* original 7601, guest PC 0x0c04cc84 */
if(!s->budget--) { s->failed_pc=0x0c04cc84u; return 0; }
r[6]+=0x00000001u;
goto P_0c04cc86;
P_0c04cc86: /* original 1c6c, guest PC 0x0c04cc86 */
if(!s->budget--) { s->failed_pc=0x0c04cc86u; return 0; }
write(ram,r[12]+48,r[6],4);
goto P_0c04cc88;
P_0c04cc88: /* original 76ff, guest PC 0x0c04cc88 */
if(!s->budget--) { s->failed_pc=0x0c04cc88u; return 0; }
r[6]+=0xffffffffu;
goto P_0c04cc8a;
P_0c04cc8a: /* original 65f2, guest PC 0x0c04cc8a */
if(!s->budget--) { s->failed_pc=0x0c04cc8au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04cc8c;
P_0c04cc8c: /* original d323, guest PC 0x0c04cc8c */
if(!s->budget--) { s->failed_pc=0x0c04cc8cu; return 0; }
r[3]=read(ram,0x0c04cd1cu,4);
goto P_0c04cc8e;
P_0c04cc8e: /* original 5552, guest PC 0x0c04cc8e */
if(!s->budget--) { s->failed_pc=0x0c04cc8eu; return 0; }
r[5]=read(ram,r[5]+8,4);
goto P_0c04cc90;
P_0c04cc90: /* original 430b, guest PC 0x0c04cc90 */
if(!s->budget--) { s->failed_pc=0x0c04cc90u; return 0; }
target=r[3];
r[16]=code_base|0x0c04cc94u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04cc94u) { target=s->pc; goto dispatch; }
goto P_0c04cc94;
P_0c04cc92: /* original 64d3, guest PC 0x0c04cc92 */
if(!s->budget--) { s->failed_pc=0x0c04cc92u; return 0; }
r[4]=r[13];
goto P_0c04cc94;
P_0c04cc94: /* original d222, guest PC 0x0c04cc94 */
if(!s->budget--) { s->failed_pc=0x0c04cc94u; return 0; }
r[2]=read(ram,0x0c04cd20u,4);
goto P_0c04cc96;
P_0c04cc96: /* original ec00, guest PC 0x0c04cc96 */
if(!s->budget--) { s->failed_pc=0x0c04cc96u; return 0; }
r[12]=0x00000000u;
goto P_0c04cc98;
P_0c04cc98: /* original 55e7, guest PC 0x0c04cc98 */
if(!s->budget--) { s->failed_pc=0x0c04cc98u; return 0; }
r[5]=read(ram,r[14]+28,4);
goto P_0c04cc9a;
P_0c04cc9a: /* original 420b, guest PC 0x0c04cc9a */
if(!s->budget--) { s->failed_pc=0x0c04cc9au; return 0; }
target=r[2];
r[16]=code_base|0x0c04cc9eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04cc9eu) { target=s->pc; goto dispatch; }
goto P_0c04cc9e;
P_0c04cc9c: /* original 64d3, guest PC 0x0c04cc9c */
if(!s->budget--) { s->failed_pc=0x0c04cc9cu; return 0; }
r[4]=r[13];
goto P_0c04cc9e;
P_0c04cc9e: /* original 4011, guest PC 0x0c04cc9e */
if(!s->budget--) { s->failed_pc=0x0c04cc9eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04cca0;
P_0c04cca0: /* original 8d0b, guest PC 0x0c04cca0 */
if(!s->budget--) { s->failed_pc=0x0c04cca0u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c04ccba; }
goto P_0c04cca4;
P_0c04cca2: /* original 6403, guest PC 0x0c04cca2 */
if(!s->budget--) { s->failed_pc=0x0c04cca2u; return 0; }
r[4]=r[0];
goto P_0c04cca4;
P_0c04cca4: /* original 60c3, guest PC 0x0c04cca4 */
if(!s->budget--) { s->failed_pc=0x0c04cca4u; return 0; }
r[0]=r[12];
goto P_0c04cca6;
P_0c04cca6: /* original 80e9, guest PC 0x0c04cca6 */
if(!s->budget--) { s->failed_pc=0x0c04cca6u; return 0; }
write(ram,r[14]+9,r[0],1);
goto P_0c04cca8;
P_0c04cca8: /* original 80e8, guest PC 0x0c04cca8 */
if(!s->budget--) { s->failed_pc=0x0c04cca8u; return 0; }
write(ram,r[14]+8,r[0],1);
goto P_0c04ccaa;
P_0c04ccaa: /* original 2f46, guest PC 0x0c04ccaa */
if(!s->budget--) { s->failed_pc=0x0c04ccaau; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ccac;
P_0c04ccac: /* original d31d, guest PC 0x0c04ccac */
if(!s->budget--) { s->failed_pc=0x0c04ccacu; return 0; }
r[3]=read(ram,0x0c04cd24u,4);
goto P_0c04ccae;
P_0c04ccae: /* original bc77, guest PC 0x0c04ccae */
if(!s->budget--) { s->failed_pc=0x0c04ccaeu; return 0; }
target=code_base|0x0c04c5a0u; r[16]=code_base|0x0c04ccb2u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04ccb2u) { target=s->pc; goto dispatch; }
goto P_0c04ccb2;
P_0c04ccb0: /* original 2f36, guest PC 0x0c04ccb0 */
if(!s->budget--) { s->failed_pc=0x0c04ccb0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ccb2;
P_0c04ccb2: /* original 7f08, guest PC 0x0c04ccb2 */
if(!s->budget--) { s->failed_pc=0x0c04ccb2u; return 0; }
r[15]+=0x00000008u;
goto P_0c04ccb4;
P_0c04ccb4: /* original 9025, guest PC 0x0c04ccb4 */
if(!s->budget--) { s->failed_pc=0x0c04ccb4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04cd02u,2);
goto P_0c04ccb6;
P_0c04ccb6: /* original a01b, guest PC 0x0c04ccb6 */
if(!s->budget--) { s->failed_pc=0x0c04ccb6u; return 0; }
goto P_0c04ccf0;
P_0c04ccb8: /* original 0009, guest PC 0x0c04ccb8 */
if(!s->budget--) { s->failed_pc=0x0c04ccb8u; return 0; }
goto P_0c04ccba;
P_0c04ccba: /* original d21b, guest PC 0x0c04ccba */
if(!s->budget--) { s->failed_pc=0x0c04ccbau; return 0; }
r[2]=read(ram,0x0c04cd28u,4);
goto P_0c04ccbc;
P_0c04ccbc: /* original 420b, guest PC 0x0c04ccbc */
if(!s->budget--) { s->failed_pc=0x0c04ccbcu; return 0; }
target=r[2];
r[16]=code_base|0x0c04ccc0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04ccc0u) { target=s->pc; goto dispatch; }
goto P_0c04ccc0;
P_0c04ccbe: /* original 64e3, guest PC 0x0c04ccbe */
if(!s->budget--) { s->failed_pc=0x0c04ccbeu; return 0; }
r[4]=r[14];
goto P_0c04ccc0;
P_0c04ccc0: /* original 4011, guest PC 0x0c04ccc0 */
if(!s->budget--) { s->failed_pc=0x0c04ccc0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04ccc2;
P_0c04ccc2: /* original 8901, guest PC 0x0c04ccc2 */
if(!s->budget--) { s->failed_pc=0x0c04ccc2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ccc8; }
goto P_0c04ccc4;
P_0c04ccc4: /* original a014, guest PC 0x0c04ccc4 */
if(!s->budget--) { s->failed_pc=0x0c04ccc4u; return 0; }
r[0]=0xffffff83u;
goto P_0c04ccf0;
P_0c04ccc6: /* original e083, guest PC 0x0c04ccc6 */
if(!s->budget--) { s->failed_pc=0x0c04ccc6u; return 0; }
r[0]=0xffffff83u;
goto P_0c04ccc8;
P_0c04ccc8: /* original 7f04, guest PC 0x0c04ccc8 */
if(!s->budget--) { s->failed_pc=0x0c04ccc8u; return 0; }
r[15]+=0x00000004u;
goto P_0c04ccca;
P_0c04ccca: /* original 54e7, guest PC 0x0c04ccca */
if(!s->budget--) { s->failed_pc=0x0c04cccau; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c04cccc;
P_0c04cccc: /* original 4f16, guest PC 0x0c04cccc */
if(!s->budget--) { s->failed_pc=0x0c04ccccu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ccce;
P_0c04ccce: /* original 60b3, guest PC 0x0c04ccce */
if(!s->budget--) { s->failed_pc=0x0c04ccceu; return 0; }
r[0]=r[11];
goto P_0c04ccd0;
P_0c04ccd0: /* original 5247, guest PC 0x0c04ccd0 */
if(!s->budget--) { s->failed_pc=0x0c04ccd0u; return 0; }
r[2]=read(ram,r[4]+28,4);
goto P_0c04ccd2;
P_0c04ccd2: /* original 4f26, guest PC 0x0c04ccd2 */
if(!s->budget--) { s->failed_pc=0x0c04ccd2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ccd4;
P_0c04ccd4: /* original 142c, guest PC 0x0c04ccd4 */
if(!s->budget--) { s->failed_pc=0x0c04ccd4u; return 0; }
write(ram,r[4]+48,r[2],4);
goto P_0c04ccd6;
P_0c04ccd6: /* original 64d3, guest PC 0x0c04ccd6 */
if(!s->budget--) { s->failed_pc=0x0c04ccd6u; return 0; }
r[4]=r[13];
goto P_0c04ccd8;
P_0c04ccd8: /* original 80e9, guest PC 0x0c04ccd8 */
if(!s->budget--) { s->failed_pc=0x0c04ccd8u; return 0; }
write(ram,r[14]+9,r[0],1);
goto P_0c04ccda;
P_0c04ccda: /* original 80e8, guest PC 0x0c04ccda */
if(!s->budget--) { s->failed_pc=0x0c04ccdau; return 0; }
write(ram,r[14]+8,r[0],1);
goto P_0c04ccdc;
P_0c04ccdc: /* original 60c3, guest PC 0x0c04ccdc */
if(!s->budget--) { s->failed_pc=0x0c04ccdcu; return 0; }
r[0]=r[12];
goto P_0c04ccde;
P_0c04ccde: /* original 80ea, guest PC 0x0c04ccde */
if(!s->budget--) { s->failed_pc=0x0c04ccdeu; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c04cce0;
P_0c04cce0: /* original 80eb, guest PC 0x0c04cce0 */
if(!s->budget--) { s->failed_pc=0x0c04cce0u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c04cce2;
P_0c04cce2: /* original 80ec, guest PC 0x0c04cce2 */
if(!s->budget--) { s->failed_pc=0x0c04cce2u; return 0; }
write(ram,r[14]+12,r[0],1);
goto P_0c04cce4;
P_0c04cce4: /* original 6bf6, guest PC 0x0c04cce4 */
if(!s->budget--) { s->failed_pc=0x0c04cce4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04cce6;
P_0c04cce6: /* original d311, guest PC 0x0c04cce6 */
if(!s->budget--) { s->failed_pc=0x0c04cce6u; return 0; }
r[3]=read(ram,0x0c04cd2cu,4);
goto P_0c04cce8;
P_0c04cce8: /* original 6cf6, guest PC 0x0c04cce8 */
if(!s->budget--) { s->failed_pc=0x0c04cce8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04ccea;
P_0c04ccea: /* original 6df6, guest PC 0x0c04ccea */
if(!s->budget--) { s->failed_pc=0x0c04cceau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04ccec;
P_0c04ccec: /* original 432b, guest PC 0x0c04ccec */
if(!s->budget--) { s->failed_pc=0x0c04ccecu; return 0; }
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
P_0c04ccee: /* original 6ef6, guest PC 0x0c04ccee */
if(!s->budget--) { s->failed_pc=0x0c04cceeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04ccf0;
P_0c04ccf0: /* original 7f04, guest PC 0x0c04ccf0 */
if(!s->budget--) { s->failed_pc=0x0c04ccf0u; return 0; }
r[15]+=0x00000004u;
goto P_0c04ccf2;
P_0c04ccf2: /* original 4f16, guest PC 0x0c04ccf2 */
if(!s->budget--) { s->failed_pc=0x0c04ccf2u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ccf4;
P_0c04ccf4: /* original 4f26, guest PC 0x0c04ccf4 */
if(!s->budget--) { s->failed_pc=0x0c04ccf4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ccf6;
P_0c04ccf6: /* original 6bf6, guest PC 0x0c04ccf6 */
if(!s->budget--) { s->failed_pc=0x0c04ccf6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04ccf8;
P_0c04ccf8: /* original 6cf6, guest PC 0x0c04ccf8 */
if(!s->budget--) { s->failed_pc=0x0c04ccf8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04ccfa;
P_0c04ccfa: /* original 6df6, guest PC 0x0c04ccfa */
if(!s->budget--) { s->failed_pc=0x0c04ccfau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04ccfc;
P_0c04ccfc: /* original 000b, guest PC 0x0c04ccfc */
if(!s->budget--) { s->failed_pc=0x0c04ccfcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04ccfe: /* original 6ef6, guest PC 0x0c04ccfe */
if(!s->budget--) { s->failed_pc=0x0c04ccfeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04cd00u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04cd00u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
