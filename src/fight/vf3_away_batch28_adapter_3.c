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
int vf3_away_batch28_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05cb02u: goto P_0c05cb02;
case 0x0c05cb04u: goto P_0c05cb04;
case 0x0c05cb06u: goto P_0c05cb06;
case 0x0c05cb08u: goto P_0c05cb08;
case 0x0c05cb0au: goto P_0c05cb0a;
case 0x0c05cb0cu: goto P_0c05cb0c;
case 0x0c05cb0eu: goto P_0c05cb0e;
case 0x0c05cb10u: goto P_0c05cb10;
case 0x0c05cb12u: goto P_0c05cb12;
case 0x0c05cb14u: goto P_0c05cb14;
case 0x0c05cb16u: goto P_0c05cb16;
case 0x0c05cb18u: goto P_0c05cb18;
case 0x0c05cb1au: goto P_0c05cb1a;
case 0x0c05cb1cu: goto P_0c05cb1c;
case 0x0c05cb1eu: goto P_0c05cb1e;
case 0x0c05cb20u: goto P_0c05cb20;
case 0x0c05cb22u: goto P_0c05cb22;
case 0x0c05cb24u: goto P_0c05cb24;
case 0x0c05cb26u: goto P_0c05cb26;
case 0x0c05cb28u: goto P_0c05cb28;
case 0x0c05cb2au: goto P_0c05cb2a;
case 0x0c05cb2cu: goto P_0c05cb2c;
case 0x0c05cb2eu: goto P_0c05cb2e;
case 0x0c05cb30u: goto P_0c05cb30;
case 0x0c05cb32u: goto P_0c05cb32;
case 0x0c05cb34u: goto P_0c05cb34;
case 0x0c05cb36u: goto P_0c05cb36;
case 0x0c05cb38u: goto P_0c05cb38;
case 0x0c05cb3au: goto P_0c05cb3a;
case 0x0c05cb3cu: goto P_0c05cb3c;
case 0x0c05cb3eu: goto P_0c05cb3e;
case 0x0c05cb40u: goto P_0c05cb40;
case 0x0c05cb42u: goto P_0c05cb42;
case 0x0c05cb44u: goto P_0c05cb44;
case 0x0c05cb46u: goto P_0c05cb46;
case 0x0c05cb48u: goto P_0c05cb48;
case 0x0c05cb4au: goto P_0c05cb4a;
case 0x0c05cb4cu: goto P_0c05cb4c;
case 0x0c05cb4eu: goto P_0c05cb4e;
case 0x0c05cb50u: goto P_0c05cb50;
case 0x0c05cb52u: goto P_0c05cb52;
case 0x0c05cb54u: goto P_0c05cb54;
case 0x0c05cb56u: goto P_0c05cb56;
case 0x0c05cb58u: goto P_0c05cb58;
case 0x0c05cb5au: goto P_0c05cb5a;
case 0x0c05cb5cu: goto P_0c05cb5c;
case 0x0c05cb5eu: goto P_0c05cb5e;
case 0x0c05cb60u: goto P_0c05cb60;
case 0x0c05cb62u: goto P_0c05cb62;
case 0x0c05cb64u: goto P_0c05cb64;
case 0x0c05cb66u: goto P_0c05cb66;
case 0x0c05cb68u: goto P_0c05cb68;
case 0x0c05cb6au: goto P_0c05cb6a;
case 0x0c05cb6cu: goto P_0c05cb6c;
case 0x0c05cc20u: goto P_0c05cc20;
case 0x0c05cc22u: goto P_0c05cc22;
case 0x0c05cc24u: goto P_0c05cc24;
case 0x0c05cc26u: goto P_0c05cc26;
case 0x0c05cc28u: goto P_0c05cc28;
case 0x0c05cc2au: goto P_0c05cc2a;
case 0x0c05cc2cu: goto P_0c05cc2c;
case 0x0c05cc2eu: goto P_0c05cc2e;
case 0x0c05cc30u: goto P_0c05cc30;
case 0x0c05cc32u: goto P_0c05cc32;
case 0x0c05cc34u: goto P_0c05cc34;
case 0x0c05cc36u: goto P_0c05cc36;
case 0x0c05cc38u: goto P_0c05cc38;
case 0x0c05cc3au: goto P_0c05cc3a;
case 0x0c05cc3cu: goto P_0c05cc3c;
case 0x0c05cc3eu: goto P_0c05cc3e;
case 0x0c05cc40u: goto P_0c05cc40;
case 0x0c05cc42u: goto P_0c05cc42;
case 0x0c05cc44u: goto P_0c05cc44;
case 0x0c05cc46u: goto P_0c05cc46;
case 0x0c05cc48u: goto P_0c05cc48;
case 0x0c05cc4au: goto P_0c05cc4a;
case 0x0c05cc4cu: goto P_0c05cc4c;
case 0x0c05cc4eu: goto P_0c05cc4e;
case 0x0c05cc50u: goto P_0c05cc50;
case 0x0c05cc52u: goto P_0c05cc52;
case 0x0c05cc54u: goto P_0c05cc54;
case 0x0c05cc56u: goto P_0c05cc56;
case 0x0c05cc58u: goto P_0c05cc58;
case 0x0c05cc5au: goto P_0c05cc5a;
case 0x0c05cc5cu: goto P_0c05cc5c;
case 0x0c05cc5eu: goto P_0c05cc5e;
case 0x0c05cc60u: goto P_0c05cc60;
case 0x0c05cc62u: goto P_0c05cc62;
case 0x0c05cc64u: goto P_0c05cc64;
case 0x0c05cc66u: goto P_0c05cc66;
case 0x0c05cc68u: goto P_0c05cc68;
case 0x0c05cc6au: goto P_0c05cc6a;
case 0x0c05cc6cu: goto P_0c05cc6c;
case 0x0c05cc6eu: goto P_0c05cc6e;
case 0x0c05cc70u: goto P_0c05cc70;
case 0x0c05cc72u: goto P_0c05cc72;
case 0x0c05cc74u: goto P_0c05cc74;
case 0x0c05cc76u: goto P_0c05cc76;
case 0x0c05cc78u: goto P_0c05cc78;
case 0x0c05cc7au: goto P_0c05cc7a;
case 0x0c05cc7cu: goto P_0c05cc7c;
case 0x0c05cc7eu: goto P_0c05cc7e;
case 0x0c05cc80u: goto P_0c05cc80;
case 0x0c05cc82u: goto P_0c05cc82;
case 0x0c05cc84u: goto P_0c05cc84;
case 0x0c05cc86u: goto P_0c05cc86;
case 0x0c05cc88u: goto P_0c05cc88;
case 0x0c05cc8au: goto P_0c05cc8a;
case 0x0c05cc8cu: goto P_0c05cc8c;
case 0x0c05cc8eu: goto P_0c05cc8e;
case 0x0c05cc90u: goto P_0c05cc90;
case 0x0c05cc92u: goto P_0c05cc92;
case 0x0c05cc94u: goto P_0c05cc94;
case 0x0c05cc96u: goto P_0c05cc96;
case 0x0c05cc98u: goto P_0c05cc98;
case 0x0c05cc9au: goto P_0c05cc9a;
case 0x0c05cc9cu: goto P_0c05cc9c;
case 0x0c05cc9eu: goto P_0c05cc9e;
case 0x0c05cca0u: goto P_0c05cca0;
case 0x0c05cca2u: goto P_0c05cca2;
case 0x0c05cca4u: goto P_0c05cca4;
case 0x0c05cca6u: goto P_0c05cca6;
case 0x0c05cca8u: goto P_0c05cca8;
case 0x0c05ccaau: goto P_0c05ccaa;
case 0x0c05ccacu: goto P_0c05ccac;
case 0x0c05ccaeu: goto P_0c05ccae;
case 0x0c05ccb0u: goto P_0c05ccb0;
case 0x0c05ccb2u: goto P_0c05ccb2;
case 0x0c05ccb4u: goto P_0c05ccb4;
case 0x0c05ccb6u: goto P_0c05ccb6;
case 0x0c05ccb8u: goto P_0c05ccb8;
case 0x0c05ccbau: goto P_0c05ccba;
case 0x0c05ccbcu: goto P_0c05ccbc;
case 0x0c05ccbeu: goto P_0c05ccbe;
case 0x0c05ccf4u: goto P_0c05ccf4;
case 0x0c05ccf6u: goto P_0c05ccf6;
case 0x0c05ccf8u: goto P_0c05ccf8;
case 0x0c05ccfau: goto P_0c05ccfa;
case 0x0c05ccfcu: goto P_0c05ccfc;
case 0x0c05ccfeu: goto P_0c05ccfe;
case 0x0c05cd00u: goto P_0c05cd00;
case 0x0c05cd02u: goto P_0c05cd02;
case 0x0c05cd04u: goto P_0c05cd04;
case 0x0c05cd06u: goto P_0c05cd06;
case 0x0c05cd08u: goto P_0c05cd08;
case 0x0c05cd0au: goto P_0c05cd0a;
case 0x0c05cd0cu: goto P_0c05cd0c;
case 0x0c05cd0eu: goto P_0c05cd0e;
case 0x0c05cd10u: goto P_0c05cd10;
case 0x0c05cd12u: goto P_0c05cd12;
case 0x0c05cd14u: goto P_0c05cd14;
case 0x0c05cd16u: goto P_0c05cd16;
case 0x0c05cd18u: goto P_0c05cd18;
case 0x0c05cd1au: goto P_0c05cd1a;
case 0x0c05cd1cu: goto P_0c05cd1c;
case 0x0c05cd1eu: goto P_0c05cd1e;
case 0x0c05cd20u: goto P_0c05cd20;
case 0x0c05cd22u: goto P_0c05cd22;
case 0x0c05cd24u: goto P_0c05cd24;
case 0x0c05cd26u: goto P_0c05cd26;
case 0x0c05cd28u: goto P_0c05cd28;
case 0x0c05cd2au: goto P_0c05cd2a;
case 0x0c05cd2cu: goto P_0c05cd2c;
case 0x0c05cd2eu: goto P_0c05cd2e;
case 0x0c05cd30u: goto P_0c05cd30;
case 0x0c05cd32u: goto P_0c05cd32;
case 0x0c05cd34u: goto P_0c05cd34;
case 0x0c05cd36u: goto P_0c05cd36;
case 0x0c05cd38u: goto P_0c05cd38;
case 0x0c05cd3au: goto P_0c05cd3a;
case 0x0c05cd3cu: goto P_0c05cd3c;
case 0x0c05cd3eu: goto P_0c05cd3e;
case 0x0c05cd40u: goto P_0c05cd40;
case 0x0c05cd42u: goto P_0c05cd42;
case 0x0c05cd44u: goto P_0c05cd44;
case 0x0c05cd46u: goto P_0c05cd46;
case 0x0c05cd48u: goto P_0c05cd48;
case 0x0c05cd4au: goto P_0c05cd4a;
case 0x0c05cd4cu: goto P_0c05cd4c;
case 0x0c05cd4eu: goto P_0c05cd4e;
case 0x0c05cd50u: goto P_0c05cd50;
case 0x0c05cd52u: goto P_0c05cd52;
case 0x0c05cd54u: goto P_0c05cd54;
case 0x0c05cd56u: goto P_0c05cd56;
case 0x0c05cd58u: goto P_0c05cd58;
case 0x0c05cd5au: goto P_0c05cd5a;
case 0x0c05cd5cu: goto P_0c05cd5c;
case 0x0c05cd5eu: goto P_0c05cd5e;
case 0x0c05cd60u: goto P_0c05cd60;
case 0x0c05cd62u: goto P_0c05cd62;
case 0x0c05cd64u: goto P_0c05cd64;
case 0x0c05cd66u: goto P_0c05cd66;
case 0x0c05cd68u: goto P_0c05cd68;
case 0x0c05cd6au: goto P_0c05cd6a;
case 0x0c05cd6cu: goto P_0c05cd6c;
case 0x0c05cd6eu: goto P_0c05cd6e;
case 0x0c05cd70u: goto P_0c05cd70;
case 0x0c05cd72u: goto P_0c05cd72;
case 0x0c05cd74u: goto P_0c05cd74;
case 0x0c05cd76u: goto P_0c05cd76;
case 0x0c05cd78u: goto P_0c05cd78;
case 0x0c05cd7au: goto P_0c05cd7a;
case 0x0c05cd7cu: goto P_0c05cd7c;
case 0x0c05cd7eu: goto P_0c05cd7e;
case 0x0c05cd80u: goto P_0c05cd80;
case 0x0c05cd82u: goto P_0c05cd82;
case 0x0c05cd84u: goto P_0c05cd84;
case 0x0c05cd86u: goto P_0c05cd86;
case 0x0c05cd88u: goto P_0c05cd88;
case 0x0c05cd8au: goto P_0c05cd8a;
case 0x0c05cd8cu: goto P_0c05cd8c;
case 0x0c05cd8eu: goto P_0c05cd8e;
case 0x0c05cd90u: goto P_0c05cd90;
case 0x0c05cd92u: goto P_0c05cd92;
case 0x0c05cd94u: goto P_0c05cd94;
case 0x0c05cd96u: goto P_0c05cd96;
case 0x0c05cd98u: goto P_0c05cd98;
case 0x0c05cd9au: goto P_0c05cd9a;
case 0x0c05cd9cu: goto P_0c05cd9c;
case 0x0c05cd9eu: goto P_0c05cd9e;
case 0x0c05cda0u: goto P_0c05cda0;
case 0x0c05cda2u: goto P_0c05cda2;
case 0x0c05cda4u: goto P_0c05cda4;
case 0x0c05cda6u: goto P_0c05cda6;
case 0x0c05cda8u: goto P_0c05cda8;
case 0x0c05cdaau: goto P_0c05cdaa;
case 0x0c05cdacu: goto P_0c05cdac;
case 0x0c05cdaeu: goto P_0c05cdae;
case 0x0c05cdb0u: goto P_0c05cdb0;
case 0x0c05cdb2u: goto P_0c05cdb2;
case 0x0c05cdb4u: goto P_0c05cdb4;
case 0x0c05cdb6u: goto P_0c05cdb6;
case 0x0c05cdb8u: goto P_0c05cdb8;
case 0x0c05cdbau: goto P_0c05cdba;
case 0x0c05cdbcu: goto P_0c05cdbc;
case 0x0c05cdbeu: goto P_0c05cdbe;
case 0x0c05cdc0u: goto P_0c05cdc0;
case 0x0c05cdc2u: goto P_0c05cdc2;
case 0x0c05cdc4u: goto P_0c05cdc4;
case 0x0c05cdc6u: goto P_0c05cdc6;
case 0x0c05cdc8u: goto P_0c05cdc8;
case 0x0c05cdcau: goto P_0c05cdca;
case 0x0c05cdccu: goto P_0c05cdcc;
case 0x0c05cdceu: goto P_0c05cdce;
case 0x0c05cdd0u: goto P_0c05cdd0;
case 0x0c05cdd2u: goto P_0c05cdd2;
case 0x0c05cdd4u: goto P_0c05cdd4;
case 0x0c05cdd6u: goto P_0c05cdd6;
case 0x0c05cdd8u: goto P_0c05cdd8;
case 0x0c05cddau: goto P_0c05cdda;
case 0x0c05cddcu: goto P_0c05cddc;
case 0x0c05cddeu: goto P_0c05cdde;
case 0x0c05cde0u: goto P_0c05cde0;
case 0x0c05cde2u: goto P_0c05cde2;
case 0x0c05cde4u: goto P_0c05cde4;
case 0x0c05cde6u: goto P_0c05cde6;
case 0x0c05cde8u: goto P_0c05cde8;
case 0x0c05cdeau: goto P_0c05cdea;
case 0x0c05cdecu: goto P_0c05cdec;
case 0x0c05cdeeu: goto P_0c05cdee;
case 0x0c05cdf0u: goto P_0c05cdf0;
case 0x0c05cdf2u: goto P_0c05cdf2;
case 0x0c05cdf4u: goto P_0c05cdf4;
case 0x0c05cdf6u: goto P_0c05cdf6;
case 0x0c05cdf8u: goto P_0c05cdf8;
case 0x0c05cdfau: goto P_0c05cdfa;
case 0x0c05cdfcu: goto P_0c05cdfc;
case 0x0c05cdfeu: goto P_0c05cdfe;
case 0x0c05ce00u: goto P_0c05ce00;
case 0x0c05ce02u: goto P_0c05ce02;
case 0x0c05ce04u: goto P_0c05ce04;
case 0x0c05ce06u: goto P_0c05ce06;
case 0x0c05ce08u: goto P_0c05ce08;
case 0x0c05ce0au: goto P_0c05ce0a;
case 0x0c05ce0cu: goto P_0c05ce0c;
case 0x0c05ce0eu: goto P_0c05ce0e;
case 0x0c05ce10u: goto P_0c05ce10;
case 0x0c05ce12u: goto P_0c05ce12;
case 0x0c05ce14u: goto P_0c05ce14;
case 0x0c05ce16u: goto P_0c05ce16;
case 0x0c05ce18u: goto P_0c05ce18;
case 0x0c05ce1au: goto P_0c05ce1a;
case 0x0c05ce1cu: goto P_0c05ce1c;
case 0x0c05ce1eu: goto P_0c05ce1e;
case 0x0c05ce20u: goto P_0c05ce20;
case 0x0c05ce22u: goto P_0c05ce22;
case 0x0c05ce24u: goto P_0c05ce24;
case 0x0c05ce26u: goto P_0c05ce26;
case 0x0c05ce28u: goto P_0c05ce28;
case 0x0c05ce2au: goto P_0c05ce2a;
case 0x0c05ce2cu: goto P_0c05ce2c;
case 0x0c05ce2eu: goto P_0c05ce2e;
case 0x0c05ce30u: goto P_0c05ce30;
case 0x0c05ce32u: goto P_0c05ce32;
case 0x0c05ce34u: goto P_0c05ce34;
case 0x0c05ce36u: goto P_0c05ce36;
case 0x0c05ce38u: goto P_0c05ce38;
case 0x0c05ce3au: goto P_0c05ce3a;
case 0x0c05ce3cu: goto P_0c05ce3c;
case 0x0c05ce3eu: goto P_0c05ce3e;
case 0x0c05ce40u: goto P_0c05ce40;
case 0x0c05ce42u: goto P_0c05ce42;
case 0x0c05ce44u: goto P_0c05ce44;
case 0x0c05ce46u: goto P_0c05ce46;
case 0x0c05ce48u: goto P_0c05ce48;
case 0x0c05ce4au: goto P_0c05ce4a;
case 0x0c05ce4cu: goto P_0c05ce4c;
case 0x0c05ce4eu: goto P_0c05ce4e;
case 0x0c05ce50u: goto P_0c05ce50;
case 0x0c05ce52u: goto P_0c05ce52;
case 0x0c05ce54u: goto P_0c05ce54;
case 0x0c05ce56u: goto P_0c05ce56;
case 0x0c05ce58u: goto P_0c05ce58;
case 0x0c05ce5au: goto P_0c05ce5a;
case 0x0c05ce5cu: goto P_0c05ce5c;
case 0x0c05ce5eu: goto P_0c05ce5e;
case 0x0c05ce60u: goto P_0c05ce60;
case 0x0c05ce62u: goto P_0c05ce62;
case 0x0c05ce64u: goto P_0c05ce64;
case 0x0c05ce66u: goto P_0c05ce66;
case 0x0c05ce68u: goto P_0c05ce68;
case 0x0c05ce6au: goto P_0c05ce6a;
case 0x0c05ce6cu: goto P_0c05ce6c;
case 0x0c05ce6eu: goto P_0c05ce6e;
case 0x0c05ce70u: goto P_0c05ce70;
case 0x0c05ce72u: goto P_0c05ce72;
case 0x0c05ce74u: goto P_0c05ce74;
case 0x0c05ce76u: goto P_0c05ce76;
case 0x0c05ce78u: goto P_0c05ce78;
case 0x0c05ce7au: goto P_0c05ce7a;
case 0x0c05ce7cu: goto P_0c05ce7c;
case 0x0c05ce7eu: goto P_0c05ce7e;
case 0x0c05ce80u: goto P_0c05ce80;
case 0x0c05ce82u: goto P_0c05ce82;
case 0x0c05ce84u: goto P_0c05ce84;
case 0x0c05ce86u: goto P_0c05ce86;
case 0x0c05ce88u: goto P_0c05ce88;
case 0x0c05ce8au: goto P_0c05ce8a;
case 0x0c05ce8cu: goto P_0c05ce8c;
case 0x0c05ce8eu: goto P_0c05ce8e;
case 0x0c05ce90u: goto P_0c05ce90;
case 0x0c05ce92u: goto P_0c05ce92;
case 0x0c05ce94u: goto P_0c05ce94;
case 0x0c05ce96u: goto P_0c05ce96;
case 0x0c05ce98u: goto P_0c05ce98;
case 0x0c05ce9au: goto P_0c05ce9a;
case 0x0c05ce9cu: goto P_0c05ce9c;
case 0x0c05ce9eu: goto P_0c05ce9e;
case 0x0c05cea0u: goto P_0c05cea0;
case 0x0c05cea2u: goto P_0c05cea2;
case 0x0c05cea4u: goto P_0c05cea4;
case 0x0c05cea6u: goto P_0c05cea6;
case 0x0c05cea8u: goto P_0c05cea8;
case 0x0c05ceaau: goto P_0c05ceaa;
case 0x0c05ceacu: goto P_0c05ceac;
case 0x0c05ceaeu: goto P_0c05ceae;
case 0x0c05ceb0u: goto P_0c05ceb0;
case 0x0c05ceb2u: goto P_0c05ceb2;
case 0x0c05ceb4u: goto P_0c05ceb4;
case 0x0c05ceb6u: goto P_0c05ceb6;
case 0x0c05ceb8u: goto P_0c05ceb8;
case 0x0c05cebau: goto P_0c05ceba;
case 0x0c05cebcu: goto P_0c05cebc;
case 0x0c05cebeu: goto P_0c05cebe;
case 0x0c05cec0u: goto P_0c05cec0;
case 0x0c05cec2u: goto P_0c05cec2;
case 0x0c05cec4u: goto P_0c05cec4;
case 0x0c05cec6u: goto P_0c05cec6;
case 0x0c05cec8u: goto P_0c05cec8;
case 0x0c05cecau: goto P_0c05ceca;
case 0x0c05ceccu: goto P_0c05cecc;
case 0x0c05ceceu: goto P_0c05cece;
case 0x0c05ced0u: goto P_0c05ced0;
case 0x0c05ced2u: goto P_0c05ced2;
case 0x0c05ced4u: goto P_0c05ced4;
case 0x0c05ced6u: goto P_0c05ced6;
case 0x0c05ced8u: goto P_0c05ced8;
case 0x0c05cedau: goto P_0c05ceda;
case 0x0c05cedcu: goto P_0c05cedc;
case 0x0c05cedeu: goto P_0c05cede;
case 0x0c05cee0u: goto P_0c05cee0;
case 0x0c05cee2u: goto P_0c05cee2;
case 0x0c05cee4u: goto P_0c05cee4;
case 0x0c05cee6u: goto P_0c05cee6;
case 0x0c05cee8u: goto P_0c05cee8;
case 0x0c05ceeau: goto P_0c05ceea;
case 0x0c05ceecu: goto P_0c05ceec;
case 0x0c05ceeeu: goto P_0c05ceee;
case 0x0c05cef0u: goto P_0c05cef0;
case 0x0c05cef2u: goto P_0c05cef2;
case 0x0c05cef4u: goto P_0c05cef4;
case 0x0c05cef6u: goto P_0c05cef6;
case 0x0c05cef8u: goto P_0c05cef8;
case 0x0c05cefau: goto P_0c05cefa;
case 0x0c05cefcu: goto P_0c05cefc;
case 0x0c05cefeu: goto P_0c05cefe;
case 0x0c05cf00u: goto P_0c05cf00;
case 0x0c05cf02u: goto P_0c05cf02;
case 0x0c05cf04u: goto P_0c05cf04;
case 0x0c05cf06u: goto P_0c05cf06;
case 0x0c05cf08u: goto P_0c05cf08;
case 0x0c05cf0au: goto P_0c05cf0a;
case 0x0c05cf0cu: goto P_0c05cf0c;
case 0x0c05cf0eu: goto P_0c05cf0e;
case 0x0c05cf10u: goto P_0c05cf10;
case 0x0c05cf12u: goto P_0c05cf12;
case 0x0c05cf14u: goto P_0c05cf14;
case 0x0c05cf16u: goto P_0c05cf16;
case 0x0c05cf18u: goto P_0c05cf18;
case 0x0c05cf1au: goto P_0c05cf1a;
case 0x0c05cf1cu: goto P_0c05cf1c;
case 0x0c05cf1eu: goto P_0c05cf1e;
case 0x0c05cf20u: goto P_0c05cf20;
case 0x0c05cf22u: goto P_0c05cf22;
case 0x0c05cf24u: goto P_0c05cf24;
case 0x0c05cf26u: goto P_0c05cf26;
case 0x0c05cf28u: goto P_0c05cf28;
case 0x0c05cf2au: goto P_0c05cf2a;
case 0x0c05cf2cu: goto P_0c05cf2c;
case 0x0c05cf2eu: goto P_0c05cf2e;
case 0x0c05cf30u: goto P_0c05cf30;
case 0x0c05cf5cu: goto P_0c05cf5c;
case 0x0c05cf5eu: goto P_0c05cf5e;
case 0x0c05cf60u: goto P_0c05cf60;
case 0x0c05cf62u: goto P_0c05cf62;
case 0x0c05cf64u: goto P_0c05cf64;
case 0x0c05cf66u: goto P_0c05cf66;
case 0x0c05cf68u: goto P_0c05cf68;
case 0x0c05cf6au: goto P_0c05cf6a;
case 0x0c05cf6cu: goto P_0c05cf6c;
case 0x0c05cf6eu: goto P_0c05cf6e;
case 0x0c05cf70u: goto P_0c05cf70;
case 0x0c05cf72u: goto P_0c05cf72;
case 0x0c05cf74u: goto P_0c05cf74;
case 0x0c05cf76u: goto P_0c05cf76;
case 0x0c05cf78u: goto P_0c05cf78;
case 0x0c05cf7au: goto P_0c05cf7a;
case 0x0c05cf7cu: goto P_0c05cf7c;
case 0x0c05cf7eu: goto P_0c05cf7e;
case 0x0c05cf80u: goto P_0c05cf80;
case 0x0c05cf82u: goto P_0c05cf82;
case 0x0c05cf84u: goto P_0c05cf84;
case 0x0c05cf86u: goto P_0c05cf86;
case 0x0c05cf88u: goto P_0c05cf88;
case 0x0c05cf8au: goto P_0c05cf8a;
case 0x0c05cf8cu: goto P_0c05cf8c;
case 0x0c05cf8eu: goto P_0c05cf8e;
case 0x0c05cf90u: goto P_0c05cf90;
case 0x0c05cf92u: goto P_0c05cf92;
case 0x0c05cf94u: goto P_0c05cf94;
case 0x0c05cf96u: goto P_0c05cf96;
case 0x0c05cf98u: goto P_0c05cf98;
case 0x0c05cf9au: goto P_0c05cf9a;
case 0x0c05cf9cu: goto P_0c05cf9c;
case 0x0c05cf9eu: goto P_0c05cf9e;
case 0x0c05cfa0u: goto P_0c05cfa0;
case 0x0c05cfa2u: goto P_0c05cfa2;
case 0x0c05cfa4u: goto P_0c05cfa4;
case 0x0c05cfa6u: goto P_0c05cfa6;
case 0x0c05cfa8u: goto P_0c05cfa8;
case 0x0c05cfaau: goto P_0c05cfaa;
case 0x0c05cfacu: goto P_0c05cfac;
case 0x0c05cfaeu: goto P_0c05cfae;
case 0x0c05cfb0u: goto P_0c05cfb0;
case 0x0c05cfb2u: goto P_0c05cfb2;
case 0x0c05cfb4u: goto P_0c05cfb4;
case 0x0c05cfb6u: goto P_0c05cfb6;
case 0x0c05cfb8u: goto P_0c05cfb8;
case 0x0c05cfbau: goto P_0c05cfba;
case 0x0c05cfbcu: goto P_0c05cfbc;
case 0x0c05cfbeu: goto P_0c05cfbe;
case 0x0c05cfc0u: goto P_0c05cfc0;
case 0x0c05cfc2u: goto P_0c05cfc2;
case 0x0c05cfc4u: goto P_0c05cfc4;
case 0x0c05cfc6u: goto P_0c05cfc6;
case 0x0c05cfc8u: goto P_0c05cfc8;
case 0x0c05cfcau: goto P_0c05cfca;
case 0x0c05cfccu: goto P_0c05cfcc;
case 0x0c05cfceu: goto P_0c05cfce;
case 0x0c05cfd0u: goto P_0c05cfd0;
case 0x0c05cfd2u: goto P_0c05cfd2;
case 0x0c05cfd4u: goto P_0c05cfd4;
case 0x0c05cfd6u: goto P_0c05cfd6;
case 0x0c05cfd8u: goto P_0c05cfd8;
case 0x0c05cfdau: goto P_0c05cfda;
case 0x0c05cfdcu: goto P_0c05cfdc;
case 0x0c05cfdeu: goto P_0c05cfde;
case 0x0c05cfe0u: goto P_0c05cfe0;
case 0x0c05cfe2u: goto P_0c05cfe2;
case 0x0c05cfe4u: goto P_0c05cfe4;
case 0x0c05cfe6u: goto P_0c05cfe6;
case 0x0c05cfe8u: goto P_0c05cfe8;
case 0x0c05cfeau: goto P_0c05cfea;
case 0x0c05cfecu: goto P_0c05cfec;
case 0x0c05cfeeu: goto P_0c05cfee;
case 0x0c05cff0u: goto P_0c05cff0;
case 0x0c05cff2u: goto P_0c05cff2;
case 0x0c05cff4u: goto P_0c05cff4;
case 0x0c05cff6u: goto P_0c05cff6;
case 0x0c05cff8u: goto P_0c05cff8;
case 0x0c05cffau: goto P_0c05cffa;
case 0x0c05cffcu: goto P_0c05cffc;
case 0x0c05cffeu: goto P_0c05cffe;
case 0x0c05d000u: goto P_0c05d000;
case 0x0c05d002u: goto P_0c05d002;
case 0x0c05d004u: goto P_0c05d004;
case 0x0c05d006u: goto P_0c05d006;
case 0x0c05d008u: goto P_0c05d008;
case 0x0c05d00au: goto P_0c05d00a;
case 0x0c05d00cu: goto P_0c05d00c;
case 0x0c05d00eu: goto P_0c05d00e;
case 0x0c05d010u: goto P_0c05d010;
case 0x0c05d012u: goto P_0c05d012;
case 0x0c05d014u: goto P_0c05d014;
case 0x0c05d016u: goto P_0c05d016;
case 0x0c05d018u: goto P_0c05d018;
case 0x0c05d01au: goto P_0c05d01a;
case 0x0c05d01cu: goto P_0c05d01c;
case 0x0c05d01eu: goto P_0c05d01e;
case 0x0c05d020u: goto P_0c05d020;
case 0x0c05d022u: goto P_0c05d022;
case 0x0c05d024u: goto P_0c05d024;
case 0x0c05d026u: goto P_0c05d026;
case 0x0c05d028u: goto P_0c05d028;
case 0x0c05d02au: goto P_0c05d02a;
case 0x0c05d02cu: goto P_0c05d02c;
case 0x0c05d02eu: goto P_0c05d02e;
case 0x0c05d030u: goto P_0c05d030;
case 0x0c05d032u: goto P_0c05d032;
case 0x0c05d034u: goto P_0c05d034;
case 0x0c05d036u: goto P_0c05d036;
case 0x0c05d038u: goto P_0c05d038;
case 0x0c05d03au: goto P_0c05d03a;
case 0x0c05d03cu: goto P_0c05d03c;
case 0x0c05d03eu: goto P_0c05d03e;
case 0x0c05d040u: goto P_0c05d040;
case 0x0c05d042u: goto P_0c05d042;
case 0x0c05d044u: goto P_0c05d044;
case 0x0c05d046u: goto P_0c05d046;
case 0x0c05d048u: goto P_0c05d048;
case 0x0c05d04au: goto P_0c05d04a;
case 0x0c05d04cu: goto P_0c05d04c;
case 0x0c05d04eu: goto P_0c05d04e;
case 0x0c05d050u: goto P_0c05d050;
case 0x0c05d052u: goto P_0c05d052;
case 0x0c05d054u: goto P_0c05d054;
case 0x0c05d056u: goto P_0c05d056;
case 0x0c05d058u: goto P_0c05d058;
case 0x0c05d05au: goto P_0c05d05a;
case 0x0c05d05cu: goto P_0c05d05c;
case 0x0c05d05eu: goto P_0c05d05e;
case 0x0c05d060u: goto P_0c05d060;
case 0x0c05d062u: goto P_0c05d062;
case 0x0c05d064u: goto P_0c05d064;
case 0x0c05d066u: goto P_0c05d066;
case 0x0c05d068u: goto P_0c05d068;
case 0x0c05d06au: goto P_0c05d06a;
case 0x0c05d06cu: goto P_0c05d06c;
case 0x0c05d06eu: goto P_0c05d06e;
case 0x0c05d070u: goto P_0c05d070;
case 0x0c05d072u: goto P_0c05d072;
case 0x0c05d074u: goto P_0c05d074;
case 0x0c05d076u: goto P_0c05d076;
case 0x0c05d078u: goto P_0c05d078;
case 0x0c05d07au: goto P_0c05d07a;
case 0x0c05d07cu: goto P_0c05d07c;
case 0x0c05d07eu: goto P_0c05d07e;
case 0x0c05d080u: goto P_0c05d080;
case 0x0c05d082u: goto P_0c05d082;
case 0x0c05d084u: goto P_0c05d084;
case 0x0c05d086u: goto P_0c05d086;
case 0x0c05d088u: goto P_0c05d088;
case 0x0c05d08au: goto P_0c05d08a;
case 0x0c05d08cu: goto P_0c05d08c;
case 0x0c05d08eu: goto P_0c05d08e;
case 0x0c05d090u: goto P_0c05d090;
case 0x0c05d092u: goto P_0c05d092;
case 0x0c05d094u: goto P_0c05d094;
case 0x0c05d096u: goto P_0c05d096;
case 0x0c05d098u: goto P_0c05d098;
case 0x0c05d09au: goto P_0c05d09a;
case 0x0c05d09cu: goto P_0c05d09c;
case 0x0c05d09eu: goto P_0c05d09e;
case 0x0c05d0a0u: goto P_0c05d0a0;
case 0x0c05d0a2u: goto P_0c05d0a2;
case 0x0c05d0a4u: goto P_0c05d0a4;
case 0x0c05d0a6u: goto P_0c05d0a6;
case 0x0c05d0a8u: goto P_0c05d0a8;
case 0x0c05d0aau: goto P_0c05d0aa;
case 0x0c05d0acu: goto P_0c05d0ac;
case 0x0c05d0aeu: goto P_0c05d0ae;
case 0x0c05d0b0u: goto P_0c05d0b0;
case 0x0c05d0b2u: goto P_0c05d0b2;
case 0x0c05d0b4u: goto P_0c05d0b4;
case 0x0c05d0b6u: goto P_0c05d0b6;
case 0x0c05d0b8u: goto P_0c05d0b8;
case 0x0c05d0bau: goto P_0c05d0ba;
case 0x0c05d0bcu: goto P_0c05d0bc;
case 0x0c05d0beu: goto P_0c05d0be;
case 0x0c05d0c0u: goto P_0c05d0c0;
case 0x0c05d0c2u: goto P_0c05d0c2;
case 0x0c05d0c4u: goto P_0c05d0c4;
case 0x0c05d0c6u: goto P_0c05d0c6;
case 0x0c05d0c8u: goto P_0c05d0c8;
case 0x0c05d0cau: goto P_0c05d0ca;
case 0x0c05d0ccu: goto P_0c05d0cc;
case 0x0c05d0ceu: goto P_0c05d0ce;
case 0x0c05d0d0u: goto P_0c05d0d0;
case 0x0c05d0d2u: goto P_0c05d0d2;
case 0x0c05d0d4u: goto P_0c05d0d4;
case 0x0c05d0d6u: goto P_0c05d0d6;
case 0x0c05d0d8u: goto P_0c05d0d8;
case 0x0c05d0dau: goto P_0c05d0da;
case 0x0c05d0dcu: goto P_0c05d0dc;
case 0x0c05d0deu: goto P_0c05d0de;
case 0x0c05d0e0u: goto P_0c05d0e0;
case 0x0c05d0e2u: goto P_0c05d0e2;
case 0x0c05d0e4u: goto P_0c05d0e4;
case 0x0c05d0e6u: goto P_0c05d0e6;
case 0x0c05d0e8u: goto P_0c05d0e8;
case 0x0c05d0eau: goto P_0c05d0ea;
case 0x0c05d0ecu: goto P_0c05d0ec;
case 0x0c05d0eeu: goto P_0c05d0ee;
case 0x0c05d0f0u: goto P_0c05d0f0;
case 0x0c05d0f2u: goto P_0c05d0f2;
case 0x0c05d0f4u: goto P_0c05d0f4;
case 0x0c05d0f6u: goto P_0c05d0f6;
case 0x0c05d0f8u: goto P_0c05d0f8;
case 0x0c05d0fau: goto P_0c05d0fa;
case 0x0c05d0fcu: goto P_0c05d0fc;
case 0x0c05d0feu: goto P_0c05d0fe;
case 0x0c05d100u: goto P_0c05d100;
case 0x0c05d102u: goto P_0c05d102;
case 0x0c05d104u: goto P_0c05d104;
case 0x0c05d106u: goto P_0c05d106;
case 0x0c05d108u: goto P_0c05d108;
case 0x0c05d10au: goto P_0c05d10a;
case 0x0c05d10cu: goto P_0c05d10c;
case 0x0c05d10eu: goto P_0c05d10e;
case 0x0c05d110u: goto P_0c05d110;
case 0x0c05d112u: goto P_0c05d112;
case 0x0c05d114u: goto P_0c05d114;
case 0x0c05d116u: goto P_0c05d116;
case 0x0c05d118u: goto P_0c05d118;
case 0x0c05d11au: goto P_0c05d11a;
case 0x0c05d11cu: goto P_0c05d11c;
case 0x0c05d11eu: goto P_0c05d11e;
case 0x0c05d120u: goto P_0c05d120;
case 0x0c05d122u: goto P_0c05d122;
case 0x0c05d124u: goto P_0c05d124;
case 0x0c05d126u: goto P_0c05d126;
case 0x0c05d128u: goto P_0c05d128;
case 0x0c05d12au: goto P_0c05d12a;
case 0x0c05d12cu: goto P_0c05d12c;
case 0x0c05d12eu: goto P_0c05d12e;
case 0x0c05d130u: goto P_0c05d130;
case 0x0c05d132u: goto P_0c05d132;
case 0x0c05d134u: goto P_0c05d134;
case 0x0c05d136u: goto P_0c05d136;
case 0x0c05d138u: goto P_0c05d138;
case 0x0c05d13au: goto P_0c05d13a;
case 0x0c05d13cu: goto P_0c05d13c;
case 0x0c05d13eu: goto P_0c05d13e;
case 0x0c05d140u: goto P_0c05d140;
case 0x0c05d142u: goto P_0c05d142;
case 0x0c05d144u: goto P_0c05d144;
case 0x0c05d146u: goto P_0c05d146;
case 0x0c05d148u: goto P_0c05d148;
case 0x0c05d14au: goto P_0c05d14a;
case 0x0c05d14cu: goto P_0c05d14c;
case 0x0c05d14eu: goto P_0c05d14e;
case 0x0c05d150u: goto P_0c05d150;
case 0x0c05d152u: goto P_0c05d152;
case 0x0c05d154u: goto P_0c05d154;
case 0x0c05d156u: goto P_0c05d156;
case 0x0c05d158u: goto P_0c05d158;
case 0x0c05d15au: goto P_0c05d15a;
case 0x0c05d15cu: goto P_0c05d15c;
case 0x0c05d15eu: goto P_0c05d15e;
case 0x0c05d160u: goto P_0c05d160;
case 0x0c05d162u: goto P_0c05d162;
case 0x0c05d164u: goto P_0c05d164;
case 0x0c05d166u: goto P_0c05d166;
case 0x0c05d168u: goto P_0c05d168;
case 0x0c05d16au: goto P_0c05d16a;
case 0x0c05d16cu: goto P_0c05d16c;
case 0x0c05d16eu: goto P_0c05d16e;
case 0x0c05d170u: goto P_0c05d170;
case 0x0c05d172u: goto P_0c05d172;
case 0x0c05d174u: goto P_0c05d174;
case 0x0c05d176u: goto P_0c05d176;
case 0x0c05d178u: goto P_0c05d178;
case 0x0c05d17au: goto P_0c05d17a;
case 0x0c05d17cu: goto P_0c05d17c;
case 0x0c05d17eu: goto P_0c05d17e;
case 0x0c05d180u: goto P_0c05d180;
case 0x0c05d182u: goto P_0c05d182;
case 0x0c05d184u: goto P_0c05d184;
case 0x0c05d186u: goto P_0c05d186;
case 0x0c05d188u: goto P_0c05d188;
case 0x0c05d18au: goto P_0c05d18a;
case 0x0c05d18cu: goto P_0c05d18c;
case 0x0c05d18eu: goto P_0c05d18e;
case 0x0c05d190u: goto P_0c05d190;
case 0x0c05d192u: goto P_0c05d192;
case 0x0c05d194u: goto P_0c05d194;
case 0x0c05d196u: goto P_0c05d196;
case 0x0c05d198u: goto P_0c05d198;
case 0x0c05d19au: goto P_0c05d19a;
case 0x0c05d19cu: goto P_0c05d19c;
case 0x0c05d19eu: goto P_0c05d19e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05cb02: /* original 2fe6, guest PC 0x0c05cb02 */
if(!s->budget--) { s->failed_pc=0x0c05cb02u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05cb04;
P_0c05cb04: /* original 2fd6, guest PC 0x0c05cb04 */
if(!s->budget--) { s->failed_pc=0x0c05cb04u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05cb06;
P_0c05cb06: /* original ee00, guest PC 0x0c05cb06 */
if(!s->budget--) { s->failed_pc=0x0c05cb06u; return 0; }
r[14]=0x00000000u;
goto P_0c05cb08;
P_0c05cb08: /* original d32c, guest PC 0x0c05cb08 */
if(!s->budget--) { s->failed_pc=0x0c05cb08u; return 0; }
r[3]=read(ram,0x0c05cbbcu,4);
goto P_0c05cb0a;
P_0c05cb0a: /* original 4f22, guest PC 0x0c05cb0a */
if(!s->budget--) { s->failed_pc=0x0c05cb0au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05cb0c;
P_0c05cb0c: /* original 7ff8, guest PC 0x0c05cb0c */
if(!s->budget--) { s->failed_pc=0x0c05cb0cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c05cb0e;
P_0c05cb0e: /* original 1f41, guest PC 0x0c05cb0e */
if(!s->budget--) { s->failed_pc=0x0c05cb0eu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c05cb10;
P_0c05cb10: /* original 2f52, guest PC 0x0c05cb10 */
if(!s->budget--) { s->failed_pc=0x0c05cb10u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c05cb12;
P_0c05cb12: /* original 23e2, guest PC 0x0c05cb12 */
if(!s->budget--) { s->failed_pc=0x0c05cb12u; return 0; }
write(ram,r[3],r[14],4);
goto P_0c05cb14;
P_0c05cb14: /* original a008, guest PC 0x0c05cb14 */
if(!s->budget--) { s->failed_pc=0x0c05cb14u; return 0; }
r[13]=0x0000000au;
goto P_0c05cb28;
P_0c05cb16: /* original ed0a, guest PC 0x0c05cb16 */
if(!s->budget--) { s->failed_pc=0x0c05cb16u; return 0; }
r[13]=0x0000000au;
goto P_0c05cb18;
P_0c05cb18: /* original d329, guest PC 0x0c05cb18 */
if(!s->budget--) { s->failed_pc=0x0c05cb18u; return 0; }
r[3]=read(ram,0x0c05cbc0u,4);
goto P_0c05cb1a;
P_0c05cb1a: /* original 6232, guest PC 0x0c05cb1a */
if(!s->budget--) { s->failed_pc=0x0c05cb1au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c05cb1c;
P_0c05cb1c: /* original 420b, guest PC 0x0c05cb1c */
if(!s->budget--) { s->failed_pc=0x0c05cb1cu; return 0; }
target=r[2];
r[16]=code_base|0x0c05cb20u;
r[4]=read(ram,r[3]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05cb20u) { target=s->pc; goto dispatch; }
goto P_0c05cb20;
P_0c05cb1e: /* original 5431, guest PC 0x0c05cb1e */
if(!s->budget--) { s->failed_pc=0x0c05cb1eu; return 0; }
r[4]=read(ram,r[3]+4,4);
goto P_0c05cb20;
P_0c05cb20: /* original d226, guest PC 0x0c05cb20 */
if(!s->budget--) { s->failed_pc=0x0c05cb20u; return 0; }
r[2]=read(ram,0x0c05cbbcu,4);
goto P_0c05cb22;
P_0c05cb22: /* original 6122, guest PC 0x0c05cb22 */
if(!s->budget--) { s->failed_pc=0x0c05cb22u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c05cb24;
P_0c05cb24: /* original 31d6, guest PC 0x0c05cb24 */
if(!s->budget--) { s->failed_pc=0x0c05cb24u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[13])!=0);
goto P_0c05cb26;
P_0c05cb26: /* original 8903, guest PC 0x0c05cb26 */
if(!s->budget--) { s->failed_pc=0x0c05cb26u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05cb30; }
goto P_0c05cb28;
P_0c05cb28: /* original d026, guest PC 0x0c05cb28 */
if(!s->budget--) { s->failed_pc=0x0c05cb28u; return 0; }
r[0]=read(ram,0x0c05cbc4u,4);
goto P_0c05cb2a;
P_0c05cb2a: /* original 6302, guest PC 0x0c05cb2a */
if(!s->budget--) { s->failed_pc=0x0c05cb2au; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c05cb2c;
P_0c05cb2c: /* original 2338, guest PC 0x0c05cb2c */
if(!s->budget--) { s->failed_pc=0x0c05cb2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c05cb2e;
P_0c05cb2e: /* original 8bf3, guest PC 0x0c05cb2e */
if(!s->budget--) { s->failed_pc=0x0c05cb2eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05cb18; }
goto P_0c05cb30;
P_0c05cb30: /* original 53f1, guest PC 0x0c05cb30 */
if(!s->budget--) { s->failed_pc=0x0c05cb30u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c05cb32;
P_0c05cb32: /* original d225, guest PC 0x0c05cb32 */
if(!s->budget--) { s->failed_pc=0x0c05cb32u; return 0; }
r[2]=read(ram,0x0c05cbc8u,4);
goto P_0c05cb34;
P_0c05cb34: /* original 2232, guest PC 0x0c05cb34 */
if(!s->budget--) { s->failed_pc=0x0c05cb34u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c05cb36;
P_0c05cb36: /* original 61f2, guest PC 0x0c05cb36 */
if(!s->budget--) { s->failed_pc=0x0c05cb36u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c05cb38;
P_0c05cb38: /* original d324, guest PC 0x0c05cb38 */
if(!s->budget--) { s->failed_pc=0x0c05cb38u; return 0; }
r[3]=read(ram,0x0c05cbccu,4);
goto P_0c05cb3a;
P_0c05cb3a: /* original 2312, guest PC 0x0c05cb3a */
if(!s->budget--) { s->failed_pc=0x0c05cb3au; return 0; }
write(ram,r[3],r[1],4);
goto P_0c05cb3c;
P_0c05cb3c: /* original 60f2, guest PC 0x0c05cb3c */
if(!s->budget--) { s->failed_pc=0x0c05cb3cu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c05cb3e;
P_0c05cb3e: /* original c90f, guest PC 0x0c05cb3e */
if(!s->budget--) { s->failed_pc=0x0c05cb3eu; return 0; }
r[0]&=15u;
goto P_0c05cb40;
P_0c05cb40: /* original d123, guest PC 0x0c05cb40 */
if(!s->budget--) { s->failed_pc=0x0c05cb40u; return 0; }
r[1]=read(ram,0x0c05cbd0u,4);
goto P_0c05cb42;
P_0c05cb42: /* original 2102, guest PC 0x0c05cb42 */
if(!s->budget--) { s->failed_pc=0x0c05cb42u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c05cb44;
P_0c05cb44: /* original 7208, guest PC 0x0c05cb44 */
if(!s->budget--) { s->failed_pc=0x0c05cb44u; return 0; }
r[2]+=0x00000008u;
goto P_0c05cb46;
P_0c05cb46: /* original 22e2, guest PC 0x0c05cb46 */
if(!s->budget--) { s->failed_pc=0x0c05cb46u; return 0; }
write(ram,r[2],r[14],4);
goto P_0c05cb48;
P_0c05cb48: /* original d322, guest PC 0x0c05cb48 */
if(!s->budget--) { s->failed_pc=0x0c05cb48u; return 0; }
r[3]=read(ram,0x0c05cbd4u,4);
goto P_0c05cb4a;
P_0c05cb4a: /* original e4ff, guest PC 0x0c05cb4a */
if(!s->budget--) { s->failed_pc=0x0c05cb4au; return 0; }
r[4]=0xffffffffu;
goto P_0c05cb4c;
P_0c05cb4c: /* original 2342, guest PC 0x0c05cb4c */
if(!s->budget--) { s->failed_pc=0x0c05cb4cu; return 0; }
write(ram,r[3],r[4],4);
goto P_0c05cb4e;
P_0c05cb4e: /* original d122, guest PC 0x0c05cb4e */
if(!s->budget--) { s->failed_pc=0x0c05cb4eu; return 0; }
r[1]=read(ram,0x0c05cbd8u,4);
goto P_0c05cb50;
P_0c05cb50: /* original 2142, guest PC 0x0c05cb50 */
if(!s->budget--) { s->failed_pc=0x0c05cb50u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c05cb52;
P_0c05cb52: /* original 720c, guest PC 0x0c05cb52 */
if(!s->budget--) { s->failed_pc=0x0c05cb52u; return 0; }
r[2]+=0x0000000cu;
goto P_0c05cb54;
P_0c05cb54: /* original 2242, guest PC 0x0c05cb54 */
if(!s->budget--) { s->failed_pc=0x0c05cb54u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c05cb56;
P_0c05cb56: /* original 730c, guest PC 0x0c05cb56 */
if(!s->budget--) { s->failed_pc=0x0c05cb56u; return 0; }
r[3]+=0x0000000cu;
goto P_0c05cb58;
P_0c05cb58: /* original 23e2, guest PC 0x0c05cb58 */
if(!s->budget--) { s->failed_pc=0x0c05cb58u; return 0; }
write(ram,r[3],r[14],4);
goto P_0c05cb5a;
P_0c05cb5a: /* original 710c, guest PC 0x0c05cb5a */
if(!s->budget--) { s->failed_pc=0x0c05cb5au; return 0; }
r[1]+=0x0000000cu;
goto P_0c05cb5c;
P_0c05cb5c: /* original 21e2, guest PC 0x0c05cb5c */
if(!s->budget--) { s->failed_pc=0x0c05cb5cu; return 0; }
write(ram,r[1],r[14],4);
goto P_0c05cb5e;
P_0c05cb5e: /* original 720c, guest PC 0x0c05cb5e */
if(!s->budget--) { s->failed_pc=0x0c05cb5eu; return 0; }
r[2]+=0x0000000cu;
goto P_0c05cb60;
P_0c05cb60: /* original 22e2, guest PC 0x0c05cb60 */
if(!s->budget--) { s->failed_pc=0x0c05cb60u; return 0; }
write(ram,r[2],r[14],4);
goto P_0c05cb62;
P_0c05cb62: /* original e000, guest PC 0x0c05cb62 */
if(!s->budget--) { s->failed_pc=0x0c05cb62u; return 0; }
r[0]=0x00000000u;
goto P_0c05cb64;
P_0c05cb64: /* original 7f08, guest PC 0x0c05cb64 */
if(!s->budget--) { s->failed_pc=0x0c05cb64u; return 0; }
r[15]+=0x00000008u;
goto P_0c05cb66;
P_0c05cb66: /* original 4f26, guest PC 0x0c05cb66 */
if(!s->budget--) { s->failed_pc=0x0c05cb66u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05cb68;
P_0c05cb68: /* original 6df6, guest PC 0x0c05cb68 */
if(!s->budget--) { s->failed_pc=0x0c05cb68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05cb6a;
P_0c05cb6a: /* original 000b, guest PC 0x0c05cb6a */
if(!s->budget--) { s->failed_pc=0x0c05cb6au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05cb6c: /* original 6ef6, guest PC 0x0c05cb6c */
if(!s->budget--) { s->failed_pc=0x0c05cb6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05cb6eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05cb6eu; return 0; } return 1;
P_0c05cc20: /* original 2fe6, guest PC 0x0c05cc20 */
if(!s->budget--) { s->failed_pc=0x0c05cc20u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05cc22;
P_0c05cc22: /* original e302, guest PC 0x0c05cc22 */
if(!s->budget--) { s->failed_pc=0x0c05cc22u; return 0; }
r[3]=0x00000002u;
goto P_0c05cc24;
P_0c05cc24: /* original d22a, guest PC 0x0c05cc24 */
if(!s->budget--) { s->failed_pc=0x0c05cc24u; return 0; }
r[2]=read(ram,0x0c05ccd0u,4);
goto P_0c05cc26;
P_0c05cc26: /* original 6e43, guest PC 0x0c05cc26 */
if(!s->budget--) { s->failed_pc=0x0c05cc26u; return 0; }
r[14]=r[4];
goto P_0c05cc28;
P_0c05cc28: /* original 2fd6, guest PC 0x0c05cc28 */
if(!s->budget--) { s->failed_pc=0x0c05cc28u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05cc2a;
P_0c05cc2a: /* original 2fc6, guest PC 0x0c05cc2a */
if(!s->budget--) { s->failed_pc=0x0c05cc2au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05cc2c;
P_0c05cc2c: /* original 2fb6, guest PC 0x0c05cc2c */
if(!s->budget--) { s->failed_pc=0x0c05cc2cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05cc2e;
P_0c05cc2e: /* original 2fa6, guest PC 0x0c05cc2e */
if(!s->budget--) { s->failed_pc=0x0c05cc2eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05cc30;
P_0c05cc30: /* original 2f96, guest PC 0x0c05cc30 */
if(!s->budget--) { s->failed_pc=0x0c05cc30u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05cc32;
P_0c05cc32: /* original 2f86, guest PC 0x0c05cc32 */
if(!s->budget--) { s->failed_pc=0x0c05cc32u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05cc34;
P_0c05cc34: /* original fffb, guest PC 0x0c05cc34 */
if(!s->budget--) { s->failed_pc=0x0c05cc34u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c05cc36;
P_0c05cc36: /* original ff8d, guest PC 0x0c05cc36 */
if(!s->budget--) { s->failed_pc=0x0c05cc36u; return 0; }
fr[15]=0;
goto P_0c05cc38;
P_0c05cc38: /* original 4f22, guest PC 0x0c05cc38 */
if(!s->budget--) { s->failed_pc=0x0c05cc38u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05cc3a;
P_0c05cc3a: /* original 7f98, guest PC 0x0c05cc3a */
if(!s->budget--) { s->failed_pc=0x0c05cc3au; return 0; }
r[15]+=0xffffff98u;
goto P_0c05cc3c;
P_0c05cc3c: /* original 420b, guest PC 0x0c05cc3c */
if(!s->budget--) { s->failed_pc=0x0c05cc3cu; return 0; }
target=r[2];
r[16]=code_base|0x0c05cc40u;
write(ram,r[15]+4,r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05cc40u) { target=s->pc; goto dispatch; }
goto P_0c05cc40;
P_0c05cc3e: /* original 1f31, guest PC 0x0c05cc3e */
if(!s->budget--) { s->failed_pc=0x0c05cc3eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c05cc40;
P_0c05cc40: /* original b72e, guest PC 0x0c05cc40 */
if(!s->budget--) { s->failed_pc=0x0c05cc40u; return 0; }
target=code_base|0x0c05daa0u; r[16]=code_base|0x0c05cc44u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05cc44u) { target=s->pc; goto dispatch; }
goto P_0c05cc44;
P_0c05cc42: /* original 0009, guest PC 0x0c05cc42 */
if(!s->budget--) { s->failed_pc=0x0c05cc42u; return 0; }
goto P_0c05cc44;
P_0c05cc44: /* original dc23, guest PC 0x0c05cc44 */
if(!s->budget--) { s->failed_pc=0x0c05cc44u; return 0; }
r[12]=read(ram,0x0c05ccd4u,4);
goto P_0c05cc46;
P_0c05cc46: /* original e054, guest PC 0x0c05cc46 */
if(!s->budget--) { s->failed_pc=0x0c05cc46u; return 0; }
r[0]=0x00000054u;
goto P_0c05cc48;
P_0c05cc48: /* original ea00, guest PC 0x0c05cc48 */
if(!s->budget--) { s->failed_pc=0x0c05cc48u; return 0; }
r[10]=0x00000000u;
goto P_0c05cc4a;
P_0c05cc4a: /* original e901, guest PC 0x0c05cc4a */
if(!s->budget--) { s->failed_pc=0x0c05cc4au; return 0; }
r[9]=0x00000001u;
goto P_0c05cc4c;
P_0c05cc4c: /* original 0ca6, guest PC 0x0c05cc4c */
if(!s->budget--) { s->failed_pc=0x0c05cc4cu; return 0; }
write(ram,r[12]+r[0],r[10],4);
goto P_0c05cc4e;
P_0c05cc4e: /* original 53e1, guest PC 0x0c05cc4e */
if(!s->budget--) { s->failed_pc=0x0c05cc4eu; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c05cc50;
P_0c05cc50: /* original 2398, guest PC 0x0c05cc50 */
if(!s->budget--) { s->failed_pc=0x0c05cc50u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c05cc52;
P_0c05cc52: /* original 8902, guest PC 0x0c05cc52 */
if(!s->budget--) { s->failed_pc=0x0c05cc52u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05cc5a; }
goto P_0c05cc54;
P_0c05cc54: /* original e101, guest PC 0x0c05cc54 */
if(!s->budget--) { s->failed_pc=0x0c05cc54u; return 0; }
r[1]=0x00000001u;
goto P_0c05cc56;
P_0c05cc56: /* original a002, guest PC 0x0c05cc56 */
if(!s->budget--) { s->failed_pc=0x0c05cc56u; return 0; }
write(ram,r[15]+16,r[1],4);
goto P_0c05cc5e;
P_0c05cc58: /* original 1f14, guest PC 0x0c05cc58 */
if(!s->budget--) { s->failed_pc=0x0c05cc58u; return 0; }
write(ram,r[15]+16,r[1],4);
goto P_0c05cc5a;
P_0c05cc5a: /* original e200, guest PC 0x0c05cc5a */
if(!s->budget--) { s->failed_pc=0x0c05cc5au; return 0; }
r[2]=0x00000000u;
goto P_0c05cc5c;
P_0c05cc5c: /* original 1f24, guest PC 0x0c05cc5c */
if(!s->budget--) { s->failed_pc=0x0c05cc5cu; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c05cc5e;
P_0c05cc5e: /* original 50e1, guest PC 0x0c05cc5e */
if(!s->budget--) { s->failed_pc=0x0c05cc5eu; return 0; }
r[0]=read(ram,r[14]+4,4);
goto P_0c05cc60;
P_0c05cc60: /* original c820, guest PC 0x0c05cc60 */
if(!s->budget--) { s->failed_pc=0x0c05cc60u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c05cc62;
P_0c05cc62: /* original 8d03, guest PC 0x0c05cc62 */
if(!s->budget--) { s->failed_pc=0x0c05cc62u; return 0; }
cond=r[17]&1u;
r[13]=0x00000002u;
if(cond) { goto P_0c05cc6c; }
goto P_0c05cc66;
P_0c05cc64: /* original ed02, guest PC 0x0c05cc64 */
if(!s->budget--) { s->failed_pc=0x0c05cc64u; return 0; }
r[13]=0x00000002u;
goto P_0c05cc66;
P_0c05cc66: /* original e200, guest PC 0x0c05cc66 */
if(!s->budget--) { s->failed_pc=0x0c05cc66u; return 0; }
r[2]=0x00000000u;
goto P_0c05cc68;
P_0c05cc68: /* original a002, guest PC 0x0c05cc68 */
if(!s->budget--) { s->failed_pc=0x0c05cc68u; return 0; }
write(ram,r[15]+32,r[2],4);
goto P_0c05cc70;
P_0c05cc6a: /* original 1f28, guest PC 0x0c05cc6a */
if(!s->budget--) { s->failed_pc=0x0c05cc6au; return 0; }
write(ram,r[15]+32,r[2],4);
goto P_0c05cc6c;
P_0c05cc6c: /* original e101, guest PC 0x0c05cc6c */
if(!s->budget--) { s->failed_pc=0x0c05cc6cu; return 0; }
r[1]=0x00000001u;
goto P_0c05cc6e;
P_0c05cc6e: /* original 1f18, guest PC 0x0c05cc6e */
if(!s->budget--) { s->failed_pc=0x0c05cc6eu; return 0; }
write(ram,r[15]+32,r[1],4);
goto P_0c05cc70;
P_0c05cc70: /* original 53e1, guest PC 0x0c05cc70 */
if(!s->budget--) { s->failed_pc=0x0c05cc70u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c05cc72;
P_0c05cc72: /* original 23d8, guest PC 0x0c05cc72 */
if(!s->budget--) { s->failed_pc=0x0c05cc72u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c05cc74;
P_0c05cc74: /* original 8902, guest PC 0x0c05cc74 */
if(!s->budget--) { s->failed_pc=0x0c05cc74u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05cc7c; }
goto P_0c05cc76;
P_0c05cc76: /* original e101, guest PC 0x0c05cc76 */
if(!s->budget--) { s->failed_pc=0x0c05cc76u; return 0; }
r[1]=0x00000001u;
goto P_0c05cc78;
P_0c05cc78: /* original a002, guest PC 0x0c05cc78 */
if(!s->budget--) { s->failed_pc=0x0c05cc78u; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c05cc80;
P_0c05cc7a: /* original 1f13, guest PC 0x0c05cc7a */
if(!s->budget--) { s->failed_pc=0x0c05cc7au; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c05cc7c;
P_0c05cc7c: /* original e200, guest PC 0x0c05cc7c */
if(!s->budget--) { s->failed_pc=0x0c05cc7cu; return 0; }
r[2]=0x00000000u;
goto P_0c05cc7e;
P_0c05cc7e: /* original 1f23, guest PC 0x0c05cc7e */
if(!s->budget--) { s->failed_pc=0x0c05cc7eu; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c05cc80;
P_0c05cc80: /* original d315, guest PC 0x0c05cc80 */
if(!s->budget--) { s->failed_pc=0x0c05cc80u; return 0; }
r[3]=read(ram,0x0c05ccd8u,4);
goto P_0c05cc82;
P_0c05cc82: /* original 51e1, guest PC 0x0c05cc82 */
if(!s->budget--) { s->failed_pc=0x0c05cc82u; return 0; }
r[1]=read(ram,r[14]+4,4);
goto P_0c05cc84;
P_0c05cc84: /* original 2138, guest PC 0x0c05cc84 */
if(!s->budget--) { s->failed_pc=0x0c05cc84u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c05cc86;
P_0c05cc86: /* original 8902, guest PC 0x0c05cc86 */
if(!s->budget--) { s->failed_pc=0x0c05cc86u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05cc8e; }
goto P_0c05cc88;
P_0c05cc88: /* original d014, guest PC 0x0c05cc88 */
if(!s->budget--) { s->failed_pc=0x0c05cc88u; return 0; }
r[0]=read(ram,0x0c05ccdcu,4);
goto P_0c05cc8a;
P_0c05cc8a: /* original a002, guest PC 0x0c05cc8a */
if(!s->budget--) { s->failed_pc=0x0c05cc8au; return 0; }
write(ram,r[0],r[10],4);
goto P_0c05cc92;
P_0c05cc8c: /* original 20a2, guest PC 0x0c05cc8c */
if(!s->budget--) { s->failed_pc=0x0c05cc8cu; return 0; }
write(ram,r[0],r[10],4);
goto P_0c05cc8e;
P_0c05cc8e: /* original d113, guest PC 0x0c05cc8e */
if(!s->budget--) { s->failed_pc=0x0c05cc8eu; return 0; }
r[1]=read(ram,0x0c05ccdcu,4);
goto P_0c05cc90;
P_0c05cc90: /* original 2192, guest PC 0x0c05cc90 */
if(!s->budget--) { s->failed_pc=0x0c05cc90u; return 0; }
write(ram,r[1],r[9],4);
goto P_0c05cc92;
P_0c05cc92: /* original 56e5, guest PC 0x0c05cc92 */
if(!s->budget--) { s->failed_pc=0x0c05cc92u; return 0; }
r[6]=read(ram,r[14]+20,4);
goto P_0c05cc94;
P_0c05cc94: /* original 9414, guest PC 0x0c05cc94 */
if(!s->budget--) { s->failed_pc=0x0c05cc94u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ccc0u,2);
goto P_0c05cc96;
P_0c05cc96: /* original d312, guest PC 0x0c05cc96 */
if(!s->budget--) { s->failed_pc=0x0c05cc96u; return 0; }
r[3]=read(ram,0x0c05cce0u,4);
goto P_0c05cc98;
P_0c05cc98: /* original 430b, guest PC 0x0c05cc98 */
if(!s->budget--) { s->failed_pc=0x0c05cc98u; return 0; }
target=r[3];
r[16]=code_base|0x0c05cc9cu;
r[5]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05cc9cu) { target=s->pc; goto dispatch; }
goto P_0c05cc9c;
P_0c05cc9a: /* original 55f3, guest PC 0x0c05cc9a */
if(!s->budget--) { s->failed_pc=0x0c05cc9au; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c05cc9c;
P_0c05cc9c: /* original d411, guest PC 0x0c05cc9c */
if(!s->budget--) { s->failed_pc=0x0c05cc9cu; return 0; }
r[4]=read(ram,0x0c05cce4u,4);
goto P_0c05cc9e;
P_0c05cc9e: /* original d812, guest PC 0x0c05cc9e */
if(!s->budget--) { s->failed_pc=0x0c05cc9eu; return 0; }
r[8]=read(ram,0x0c05cce8u,4);
goto P_0c05cca0;
P_0c05cca0: /* original d312, guest PC 0x0c05cca0 */
if(!s->budget--) { s->failed_pc=0x0c05cca0u; return 0; }
r[3]=read(ram,0x0c05ccecu,4);
goto P_0c05cca2;
P_0c05cca2: /* original 52e1, guest PC 0x0c05cca2 */
if(!s->budget--) { s->failed_pc=0x0c05cca2u; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c05cca4;
P_0c05cca4: /* original 2238, guest PC 0x0c05cca4 */
if(!s->budget--) { s->failed_pc=0x0c05cca4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c05cca6;
P_0c05cca6: /* original 8901, guest PC 0x0c05cca6 */
if(!s->budget--) { s->failed_pc=0x0c05cca6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ccac; }
goto P_0c05cca8;
P_0c05cca8: /* original a190, guest PC 0x0c05cca8 */
if(!s->budget--) { s->failed_pc=0x0c05cca8u; return 0; }
goto P_0c05cfcc;
P_0c05ccaa: /* original 0009, guest PC 0x0c05ccaa */
if(!s->budget--) { s->failed_pc=0x0c05ccaau; return 0; }
goto P_0c05ccac;
P_0c05ccac: /* original 24a2, guest PC 0x0c05ccac */
if(!s->budget--) { s->failed_pc=0x0c05ccacu; return 0; }
write(ram,r[4],r[10],4);
goto P_0c05ccae;
P_0c05ccae: /* original 50e1, guest PC 0x0c05ccae */
if(!s->budget--) { s->failed_pc=0x0c05ccaeu; return 0; }
r[0]=read(ram,r[14]+4,4);
goto P_0c05ccb0;
P_0c05ccb0: /* original c810, guest PC 0x0c05ccb0 */
if(!s->budget--) { s->failed_pc=0x0c05ccb0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c05ccb2;
P_0c05ccb2: /* original 8d1f, guest PC 0x0c05ccb2 */
if(!s->budget--) { s->failed_pc=0x0c05ccb2u; return 0; }
cond=r[17]&1u;
r[0]=0x0000005cu;
if(cond) { goto P_0c05ccf4; }
goto P_0c05ccb6;
P_0c05ccb4: /* original e05c, guest PC 0x0c05ccb4 */
if(!s->budget--) { s->failed_pc=0x0c05ccb4u; return 0; }
r[0]=0x0000005cu;
goto P_0c05ccb6;
P_0c05ccb6: /* original d10e, guest PC 0x0c05ccb6 */
if(!s->budget--) { s->failed_pc=0x0c05ccb6u; return 0; }
r[1]=read(ram,0x0c05ccf0u,4);
goto P_0c05ccb8;
P_0c05ccb8: /* original 2192, guest PC 0x0c05ccb8 */
if(!s->budget--) { s->failed_pc=0x0c05ccb8u; return 0; }
write(ram,r[1],r[9],4);
goto P_0c05ccba;
P_0c05ccba: /* original d208, guest PC 0x0c05ccba */
if(!s->budget--) { s->failed_pc=0x0c05ccbau; return 0; }
r[2]=read(ram,0x0c05ccdcu,4);
goto P_0c05ccbc;
P_0c05ccbc: /* original a01c, guest PC 0x0c05ccbc */
if(!s->budget--) { s->failed_pc=0x0c05ccbcu; return 0; }
write(ram,r[2],r[9],4);
goto P_0c05ccf8;
P_0c05ccbe: /* original 2292, guest PC 0x0c05ccbe */
if(!s->budget--) { s->failed_pc=0x0c05ccbeu; return 0; }
write(ram,r[2],r[9],4);
if(!vf3_matrix_family(0x0c05ccc0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05ccc0u; return 0; } return 1;
P_0c05ccf4: /* original d18f, guest PC 0x0c05ccf4 */
if(!s->budget--) { s->failed_pc=0x0c05ccf4u; return 0; }
r[1]=read(ram,0x0c05cf34u,4);
goto P_0c05ccf6;
P_0c05ccf6: /* original 21a2, guest PC 0x0c05ccf6 */
if(!s->budget--) { s->failed_pc=0x0c05ccf6u; return 0; }
write(ram,r[1],r[10],4);
goto P_0c05ccf8;
P_0c05ccf8: /* original 05ee, guest PC 0x0c05ccf8 */
if(!s->budget--) { s->failed_pc=0x0c05ccf8u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c05ccfa;
P_0c05ccfa: /* original d38e, guest PC 0x0c05ccfa */
if(!s->budget--) { s->failed_pc=0x0c05ccfau; return 0; }
r[3]=read(ram,0x0c05cf34u,4);
goto P_0c05ccfc;
P_0c05ccfc: /* original bf01, guest PC 0x0c05ccfc */
if(!s->budget--) { s->failed_pc=0x0c05ccfcu; return 0; }
target=code_base|0x0c05cb02u; r[16]=code_base|0x0c05cd00u;
tmp=read(ram,r[3],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05cd00u) { target=s->pc; goto dispatch; }
goto P_0c05cd00;
P_0c05ccfe: /* original 6432, guest PC 0x0c05ccfe */
if(!s->budget--) { s->failed_pc=0x0c05ccfeu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c05cd00;
P_0c05cd00: /* original 54ea, guest PC 0x0c05cd00 */
if(!s->budget--) { s->failed_pc=0x0c05cd00u; return 0; }
r[4]=read(ram,r[14]+40,4);
goto P_0c05cd02;
P_0c05cd02: /* original 53e9, guest PC 0x0c05cd02 */
if(!s->budget--) { s->failed_pc=0x0c05cd02u; return 0; }
r[3]=read(ram,r[14]+36,4);
goto P_0c05cd04;
P_0c05cd04: /* original d28c, guest PC 0x0c05cd04 */
if(!s->budget--) { s->failed_pc=0x0c05cd04u; return 0; }
r[2]=read(ram,0x0c05cf38u,4);
goto P_0c05cd06;
P_0c05cd06: /* original 2232, guest PC 0x0c05cd06 */
if(!s->budget--) { s->failed_pc=0x0c05cd06u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c05cd08;
P_0c05cd08: /* original e51f, guest PC 0x0c05cd08 */
if(!s->budget--) { s->failed_pc=0x0c05cd08u; return 0; }
r[5]=0x0000001fu;
goto P_0c05cd0a;
P_0c05cd0a: /* original 6123, guest PC 0x0c05cd0a */
if(!s->budget--) { s->failed_pc=0x0c05cd0au; return 0; }
r[1]=r[2];
goto P_0c05cd0c;
P_0c05cd0c: /* original 6312, guest PC 0x0c05cd0c */
if(!s->budget--) { s->failed_pc=0x0c05cd0cu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c05cd0e;
P_0c05cd0e: /* original 2358, guest PC 0x0c05cd0e */
if(!s->budget--) { s->failed_pc=0x0c05cd0eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c05cd10;
P_0c05cd10: /* original 890b, guest PC 0x0c05cd10 */
if(!s->budget--) { s->failed_pc=0x0c05cd10u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05cd2a; }
goto P_0c05cd12;
P_0c05cd12: /* original e1e0, guest PC 0x0c05cd12 */
if(!s->budget--) { s->failed_pc=0x0c05cd12u; return 0; }
r[1]=0xffffffe0u;
goto P_0c05cd14;
P_0c05cd14: /* original d088, guest PC 0x0c05cd14 */
if(!s->budget--) { s->failed_pc=0x0c05cd14u; return 0; }
r[0]=read(ram,0x0c05cf38u,4);
goto P_0c05cd16;
P_0c05cd16: /* original 6302, guest PC 0x0c05cd16 */
if(!s->budget--) { s->failed_pc=0x0c05cd16u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c05cd18;
P_0c05cd18: /* original 2359, guest PC 0x0c05cd18 */
if(!s->budget--) { s->failed_pc=0x0c05cd18u; return 0; }
r[3]&=r[5];
goto P_0c05cd1a;
P_0c05cd1a: /* original 633b, guest PC 0x0c05cd1a */
if(!s->budget--) { s->failed_pc=0x0c05cd1au; return 0; }
r[3]=0u-r[3];
goto P_0c05cd1c;
P_0c05cd1c: /* original 7320, guest PC 0x0c05cd1c */
if(!s->budget--) { s->failed_pc=0x0c05cd1cu; return 0; }
r[3]+=0x00000020u;
goto P_0c05cd1e;
P_0c05cd1e: /* original 3438, guest PC 0x0c05cd1e */
if(!s->budget--) { s->failed_pc=0x0c05cd1eu; return 0; }
r[4]-=r[3];
goto P_0c05cd20;
P_0c05cd20: /* original 6203, guest PC 0x0c05cd20 */
if(!s->budget--) { s->failed_pc=0x0c05cd20u; return 0; }
r[2]=r[0];
goto P_0c05cd22;
P_0c05cd22: /* original 6322, guest PC 0x0c05cd22 */
if(!s->budget--) { s->failed_pc=0x0c05cd22u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c05cd24;
P_0c05cd24: /* original 731f, guest PC 0x0c05cd24 */
if(!s->budget--) { s->failed_pc=0x0c05cd24u; return 0; }
r[3]+=0x0000001fu;
goto P_0c05cd26;
P_0c05cd26: /* original 2319, guest PC 0x0c05cd26 */
if(!s->budget--) { s->failed_pc=0x0c05cd26u; return 0; }
r[3]&=r[1];
goto P_0c05cd28;
P_0c05cd28: /* original 2032, guest PC 0x0c05cd28 */
if(!s->budget--) { s->failed_pc=0x0c05cd28u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c05cd2a;
P_0c05cd2a: /* original d182, guest PC 0x0c05cd2a */
if(!s->budget--) { s->failed_pc=0x0c05cd2au; return 0; }
r[1]=read(ram,0x0c05cf34u,4);
goto P_0c05cd2c;
P_0c05cd2c: /* original 6212, guest PC 0x0c05cd2c */
if(!s->budget--) { s->failed_pc=0x0c05cd2cu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c05cd2e;
P_0c05cd2e: /* original 2228, guest PC 0x0c05cd2e */
if(!s->budget--) { s->failed_pc=0x0c05cd2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c05cd30;
P_0c05cd30: /* original 8f01, guest PC 0x0c05cd30 */
if(!s->budget--) { s->failed_pc=0x0c05cd30u; return 0; }
cond=r[17]&1u;
r[6]=0x00000000u;
if(!cond) { goto P_0c05cd36; }
goto P_0c05cd34;
P_0c05cd32: /* original e600, guest PC 0x0c05cd32 */
if(!s->budget--) { s->failed_pc=0x0c05cd32u; return 0; }
r[6]=0x00000000u;
goto P_0c05cd34;
P_0c05cd34: /* original 4401, guest PC 0x0c05cd34 */
if(!s->budget--) { s->failed_pc=0x0c05cd34u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c05cd36;
P_0c05cd36: /* original 6bf3, guest PC 0x0c05cd36 */
if(!s->budget--) { s->failed_pc=0x0c05cd36u; return 0; }
r[11]=r[15];
goto P_0c05cd38;
P_0c05cd38: /* original 7b40, guest PC 0x0c05cd38 */
if(!s->budget--) { s->failed_pc=0x0c05cd38u; return 0; }
r[11]+=0x00000040u;
goto P_0c05cd3a;
P_0c05cd3a: /* original 65b3, guest PC 0x0c05cd3a */
if(!s->budget--) { s->failed_pc=0x0c05cd3au; return 0; }
r[5]=r[11];
goto P_0c05cd3c;
P_0c05cd3c: /* original a003, guest PC 0x0c05cd3c */
if(!s->budget--) { s->failed_pc=0x0c05cd3cu; return 0; }
r[13]=0x00000005u;
goto P_0c05cd46;
P_0c05cd3e: /* original ed05, guest PC 0x0c05cd3e */
if(!s->budget--) { s->failed_pc=0x0c05cd3eu; return 0; }
r[13]=0x00000005u;
goto P_0c05cd40;
P_0c05cd40: /* original 25a2, guest PC 0x0c05cd40 */
if(!s->budget--) { s->failed_pc=0x0c05cd40u; return 0; }
write(ram,r[5],r[10],4);
goto P_0c05cd42;
P_0c05cd42: /* original 7601, guest PC 0x0c05cd42 */
if(!s->budget--) { s->failed_pc=0x0c05cd42u; return 0; }
r[6]+=0x00000001u;
goto P_0c05cd44;
P_0c05cd44: /* original 7504, guest PC 0x0c05cd44 */
if(!s->budget--) { s->failed_pc=0x0c05cd44u; return 0; }
r[5]+=0x00000004u;
goto P_0c05cd46;
P_0c05cd46: /* original 36d2, guest PC 0x0c05cd46 */
if(!s->budget--) { s->failed_pc=0x0c05cd46u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[13])!=0);
goto P_0c05cd48;
P_0c05cd48: /* original 8bfa, guest PC 0x0c05cd48 */
if(!s->budget--) { s->failed_pc=0x0c05cd48u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05cd40; }
goto P_0c05cd4a;
P_0c05cd4a: /* original 66e3, guest PC 0x0c05cd4a */
if(!s->budget--) { s->failed_pc=0x0c05cd4au; return 0; }
r[6]=r[14];
goto P_0c05cd4c;
P_0c05cd4c: /* original 762c, guest PC 0x0c05cd4c */
if(!s->budget--) { s->failed_pc=0x0c05cd4cu; return 0; }
r[6]+=0x0000002cu;
goto P_0c05cd4e;
P_0c05cd4e: /* original a003, guest PC 0x0c05cd4e */
if(!s->budget--) { s->failed_pc=0x0c05cd4eu; return 0; }
r[5]=0x00000005u;
goto P_0c05cd58;
P_0c05cd50: /* original e505, guest PC 0x0c05cd50 */
if(!s->budget--) { s->failed_pc=0x0c05cd50u; return 0; }
r[5]=0x00000005u;
goto P_0c05cd52;
P_0c05cd52: /* original 75ff, guest PC 0x0c05cd52 */
if(!s->budget--) { s->failed_pc=0x0c05cd52u; return 0; }
r[5]+=0xffffffffu;
goto P_0c05cd54;
P_0c05cd54: /* original f369, guest PC 0x0c05cd54 */
if(!s->budget--) { s->failed_pc=0x0c05cd54u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c05cd56;
P_0c05cd56: /* original ff30, guest PC 0x0c05cd56 */
if(!s->budget--) { s->failed_pc=0x0c05cd56u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c05cd58;
P_0c05cd58: /* original 2558, guest PC 0x0c05cd58 */
if(!s->budget--) { s->failed_pc=0x0c05cd58u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c05cd5a;
P_0c05cd5a: /* original 8bfa, guest PC 0x0c05cd5a */
if(!s->budget--) { s->failed_pc=0x0c05cd5au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05cd52; }
goto P_0c05cd5c;
P_0c05cd5c: /* original c777, guest PC 0x0c05cd5c */
if(!s->budget--) { s->failed_pc=0x0c05cd5cu; return 0; }
r[0]=code_base|0x0005cf3cu;
goto P_0c05cd5e;
P_0c05cd5e: /* original 65f3, guest PC 0x0c05cd5e */
if(!s->budget--) { s->failed_pc=0x0c05cd5eu; return 0; }
r[5]=r[15];
goto P_0c05cd60;
P_0c05cd60: /* original f408, guest PC 0x0c05cd60 */
if(!s->budget--) { s->failed_pc=0x0c05cd60u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c05cd62;
P_0c05cd62: /* original ff45, guest PC 0x0c05cd62 */
if(!s->budget--) { s->failed_pc=0x0c05cd62u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[4]))!=0);
goto P_0c05cd64;
P_0c05cd64: /* original 8f12, guest PC 0x0c05cd64 */
if(!s->budget--) { s->failed_pc=0x0c05cd64u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000054u;
if(!cond) { goto P_0c05cd8c; }
goto P_0c05cd68;
P_0c05cd66: /* original 7554, guest PC 0x0c05cd66 */
if(!s->budget--) { s->failed_pc=0x0c05cd66u; return 0; }
r[5]+=0x00000054u;
goto P_0c05cd68;
P_0c05cd68: /* original e700, guest PC 0x0c05cd68 */
if(!s->budget--) { s->failed_pc=0x0c05cd68u; return 0; }
r[7]=0x00000000u;
goto P_0c05cd6a;
P_0c05cd6a: /* original a00b, guest PC 0x0c05cd6a */
if(!s->budget--) { s->failed_pc=0x0c05cd6au; return 0; }
r[6]=r[7];
goto P_0c05cd84;
P_0c05cd6c: /* original 6673, guest PC 0x0c05cd6c */
if(!s->budget--) { s->failed_pc=0x0c05cd6cu; return 0; }
r[6]=r[7];
goto P_0c05cd6e;
P_0c05cd6e: /* original 6063, guest PC 0x0c05cd6e */
if(!s->budget--) { s->failed_pc=0x0c05cd6eu; return 0; }
r[0]=r[6];
goto P_0c05cd70;
P_0c05cd70: /* original 0009, guest PC 0x0c05cd70 */
if(!s->budget--) { s->failed_pc=0x0c05cd70u; return 0; }
goto P_0c05cd72;
P_0c05cd72: /* original 63e3, guest PC 0x0c05cd72 */
if(!s->budget--) { s->failed_pc=0x0c05cd72u; return 0; }
r[3]=r[14];
goto P_0c05cd74;
P_0c05cd74: /* original 732c, guest PC 0x0c05cd74 */
if(!s->budget--) { s->failed_pc=0x0c05cd74u; return 0; }
r[3]+=0x0000002cu;
goto P_0c05cd76;
P_0c05cd76: /* original 336c, guest PC 0x0c05cd76 */
if(!s->budget--) { s->failed_pc=0x0c05cd76u; return 0; }
r[3]+=r[6];
goto P_0c05cd78;
P_0c05cd78: /* original f338, guest PC 0x0c05cd78 */
if(!s->budget--) { s->failed_pc=0x0c05cd78u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c05cd7a;
P_0c05cd7a: /* original 7701, guest PC 0x0c05cd7a */
if(!s->budget--) { s->failed_pc=0x0c05cd7au; return 0; }
r[7]+=0x00000001u;
goto P_0c05cd7c;
P_0c05cd7c: /* original f342, guest PC 0x0c05cd7c */
if(!s->budget--) { s->failed_pc=0x0c05cd7cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05cd7e;
P_0c05cd7e: /* original 7604, guest PC 0x0c05cd7e */
if(!s->budget--) { s->failed_pc=0x0c05cd7eu; return 0; }
r[6]+=0x00000004u;
goto P_0c05cd80;
P_0c05cd80: /* original f3f3, guest PC 0x0c05cd80 */
if(!s->budget--) { s->failed_pc=0x0c05cd80u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'/');
goto P_0c05cd82;
P_0c05cd82: /* original f537, guest PC 0x0c05cd82 */
if(!s->budget--) { s->failed_pc=0x0c05cd82u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c05cd84;
P_0c05cd84: /* original 37d2, guest PC 0x0c05cd84 */
if(!s->budget--) { s->failed_pc=0x0c05cd84u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[13])!=0);
goto P_0c05cd86;
P_0c05cd86: /* original 8bf2, guest PC 0x0c05cd86 */
if(!s->budget--) { s->failed_pc=0x0c05cd86u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05cd6e; }
goto P_0c05cd88;
P_0c05cd88: /* original a00e, guest PC 0x0c05cd88 */
if(!s->budget--) { s->failed_pc=0x0c05cd88u; return 0; }
goto P_0c05cda8;
P_0c05cd8a: /* original 0009, guest PC 0x0c05cd8a */
if(!s->budget--) { s->failed_pc=0x0c05cd8au; return 0; }
goto P_0c05cd8c;
P_0c05cd8c: /* original e700, guest PC 0x0c05cd8c */
if(!s->budget--) { s->failed_pc=0x0c05cd8cu; return 0; }
r[7]=0x00000000u;
goto P_0c05cd8e;
P_0c05cd8e: /* original a009, guest PC 0x0c05cd8e */
if(!s->budget--) { s->failed_pc=0x0c05cd8eu; return 0; }
r[6]=r[7];
goto P_0c05cda4;
P_0c05cd90: /* original 6673, guest PC 0x0c05cd90 */
if(!s->budget--) { s->failed_pc=0x0c05cd90u; return 0; }
r[6]=r[7];
goto P_0c05cd92;
P_0c05cd92: /* original 6063, guest PC 0x0c05cd92 */
if(!s->budget--) { s->failed_pc=0x0c05cd92u; return 0; }
r[0]=r[6];
goto P_0c05cd94;
P_0c05cd94: /* original 0009, guest PC 0x0c05cd94 */
if(!s->budget--) { s->failed_pc=0x0c05cd94u; return 0; }
goto P_0c05cd96;
P_0c05cd96: /* original 63e3, guest PC 0x0c05cd96 */
if(!s->budget--) { s->failed_pc=0x0c05cd96u; return 0; }
r[3]=r[14];
goto P_0c05cd98;
P_0c05cd98: /* original 732c, guest PC 0x0c05cd98 */
if(!s->budget--) { s->failed_pc=0x0c05cd98u; return 0; }
r[3]+=0x0000002cu;
goto P_0c05cd9a;
P_0c05cd9a: /* original 336c, guest PC 0x0c05cd9a */
if(!s->budget--) { s->failed_pc=0x0c05cd9au; return 0; }
r[3]+=r[6];
goto P_0c05cd9c;
P_0c05cd9c: /* original f338, guest PC 0x0c05cd9c */
if(!s->budget--) { s->failed_pc=0x0c05cd9cu; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c05cd9e;
P_0c05cd9e: /* original 7701, guest PC 0x0c05cd9e */
if(!s->budget--) { s->failed_pc=0x0c05cd9eu; return 0; }
r[7]+=0x00000001u;
goto P_0c05cda0;
P_0c05cda0: /* original f537, guest PC 0x0c05cda0 */
if(!s->budget--) { s->failed_pc=0x0c05cda0u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c05cda2;
P_0c05cda2: /* original 7604, guest PC 0x0c05cda2 */
if(!s->budget--) { s->failed_pc=0x0c05cda2u; return 0; }
r[6]+=0x00000004u;
goto P_0c05cda4;
P_0c05cda4: /* original 37d2, guest PC 0x0c05cda4 */
if(!s->budget--) { s->failed_pc=0x0c05cda4u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[13])!=0);
goto P_0c05cda6;
P_0c05cda6: /* original 8bf4, guest PC 0x0c05cda6 */
if(!s->budget--) { s->failed_pc=0x0c05cda6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05cd92; }
goto P_0c05cda8;
P_0c05cda8: /* original e700, guest PC 0x0c05cda8 */
if(!s->budget--) { s->failed_pc=0x0c05cda8u; return 0; }
r[7]=0x00000000u;
goto P_0c05cdaa;
P_0c05cdaa: /* original a01d, guest PC 0x0c05cdaa */
if(!s->budget--) { s->failed_pc=0x0c05cdaau; return 0; }
r[6]=r[7];
goto P_0c05cde8;
P_0c05cdac: /* original 6673, guest PC 0x0c05cdac */
if(!s->budget--) { s->failed_pc=0x0c05cdacu; return 0; }
r[6]=r[7];
goto P_0c05cdae;
P_0c05cdae: /* original 6363, guest PC 0x0c05cdae */
if(!s->budget--) { s->failed_pc=0x0c05cdaeu; return 0; }
r[3]=r[6];
goto P_0c05cdb0;
P_0c05cdb0: /* original 33bc, guest PC 0x0c05cdb0 */
if(!s->budget--) { s->failed_pc=0x0c05cdb0u; return 0; }
r[3]+=r[11];
goto P_0c05cdb2;
P_0c05cdb2: /* original 6063, guest PC 0x0c05cdb2 */
if(!s->budget--) { s->failed_pc=0x0c05cdb2u; return 0; }
r[0]=r[6];
goto P_0c05cdb4;
P_0c05cdb4: /* original 0009, guest PC 0x0c05cdb4 */
if(!s->budget--) { s->failed_pc=0x0c05cdb4u; return 0; }
goto P_0c05cdb6;
P_0c05cdb6: /* original 445a, guest PC 0x0c05cdb6 */
if(!s->budget--) { s->failed_pc=0x0c05cdb6u; return 0; }
r[53]=r[4];
goto P_0c05cdb8;
P_0c05cdb8: /* original f356, guest PC 0x0c05cdb8 */
if(!s->budget--) { s->failed_pc=0x0c05cdb8u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c05cdba;
P_0c05cdba: /* original 4411, guest PC 0x0c05cdba */
if(!s->budget--) { s->failed_pc=0x0c05cdbau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c05cdbc;
P_0c05cdbc: /* original 8d04, guest PC 0x0c05cdbc */
if(!s->budget--) { s->failed_pc=0x0c05cdbcu; return 0; }
cond=r[17]&1u;
fr[2]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c05cdc8; }
goto P_0c05cdc0;
P_0c05cdbe: /* original f22d, guest PC 0x0c05cdbe */
if(!s->budget--) { s->failed_pc=0x0c05cdbeu; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c05cdc0;
P_0c05cdc0: /* original d25f, guest PC 0x0c05cdc0 */
if(!s->budget--) { s->failed_pc=0x0c05cdc0u; return 0; }
r[2]=read(ram,0x0c05cf40u,4);
goto P_0c05cdc2;
P_0c05cdc2: /* original 425a, guest PC 0x0c05cdc2 */
if(!s->budget--) { s->failed_pc=0x0c05cdc2u; return 0; }
r[53]=r[2];
goto P_0c05cdc4;
P_0c05cdc4: /* original f10d, guest PC 0x0c05cdc4 */
if(!s->budget--) { s->failed_pc=0x0c05cdc4u; return 0; }
fr[1]=r[53];
goto P_0c05cdc6;
P_0c05cdc6: /* original f210, guest PC 0x0c05cdc6 */
if(!s->budget--) { s->failed_pc=0x0c05cdc6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[1],r[18],'+');
goto P_0c05cdc8;
P_0c05cdc8: /* original d25e, guest PC 0x0c05cdc8 */
if(!s->budget--) { s->failed_pc=0x0c05cdc8u; return 0; }
r[2]=read(ram,0x0c05cf44u,4);
goto P_0c05cdca;
P_0c05cdca: /* original f322, guest PC 0x0c05cdca */
if(!s->budget--) { s->failed_pc=0x0c05cdcau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c05cdcc;
P_0c05cdcc: /* original f343, guest PC 0x0c05cdcc */
if(!s->budget--) { s->failed_pc=0x0c05cdccu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'/');
goto P_0c05cdce;
P_0c05cdce: /* original 425a, guest PC 0x0c05cdce */
if(!s->budget--) { s->failed_pc=0x0c05cdceu; return 0; }
r[53]=r[2];
goto P_0c05cdd0;
P_0c05cdd0: /* original f20d, guest PC 0x0c05cdd0 */
if(!s->budget--) { s->failed_pc=0x0c05cdd0u; return 0; }
fr[2]=r[53];
goto P_0c05cdd2;
P_0c05cdd2: /* original f235, guest PC 0x0c05cdd2 */
if(!s->budget--) { s->failed_pc=0x0c05cdd2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c05cdd4;
P_0c05cdd4: /* original 8901, guest PC 0x0c05cdd4 */
if(!s->budget--) { s->failed_pc=0x0c05cdd4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05cdda; }
goto P_0c05cdd6;
P_0c05cdd6: /* original f220, guest PC 0x0c05cdd6 */
if(!s->budget--) { s->failed_pc=0x0c05cdd6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[2],r[18],'+');
goto P_0c05cdd8;
P_0c05cdd8: /* original f321, guest PC 0x0c05cdd8 */
if(!s->budget--) { s->failed_pc=0x0c05cdd8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'-');
goto P_0c05cdda;
P_0c05cdda: /* original f33d, guest PC 0x0c05cdda */
if(!s->budget--) { s->failed_pc=0x0c05cddau; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05cddc;
P_0c05cddc: /* original 025a, guest PC 0x0c05cddc */
if(!s->budget--) { s->failed_pc=0x0c05cddcu; return 0; }
r[2]=r[53];
goto P_0c05cdde;
P_0c05cdde: /* original e1f8, guest PC 0x0c05cdde */
if(!s->budget--) { s->failed_pc=0x0c05cddeu; return 0; }
r[1]=0xfffffff8u;
goto P_0c05cde0;
P_0c05cde0: /* original 2219, guest PC 0x0c05cde0 */
if(!s->budget--) { s->failed_pc=0x0c05cde0u; return 0; }
r[2]&=r[1];
goto P_0c05cde2;
P_0c05cde2: /* original 7701, guest PC 0x0c05cde2 */
if(!s->budget--) { s->failed_pc=0x0c05cde2u; return 0; }
r[7]+=0x00000001u;
goto P_0c05cde4;
P_0c05cde4: /* original 2322, guest PC 0x0c05cde4 */
if(!s->budget--) { s->failed_pc=0x0c05cde4u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c05cde6;
P_0c05cde6: /* original 7604, guest PC 0x0c05cde6 */
if(!s->budget--) { s->failed_pc=0x0c05cde6u; return 0; }
r[6]+=0x00000004u;
goto P_0c05cde8;
P_0c05cde8: /* original 37d2, guest PC 0x0c05cde8 */
if(!s->budget--) { s->failed_pc=0x0c05cde8u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[13])!=0);
goto P_0c05cdea;
P_0c05cdea: /* original 8be0, guest PC 0x0c05cdea */
if(!s->budget--) { s->failed_pc=0x0c05cdeau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05cdae; }
goto P_0c05cdec;
P_0c05cdec: /* original d256, guest PC 0x0c05cdec */
if(!s->budget--) { s->failed_pc=0x0c05cdecu; return 0; }
r[2]=read(ram,0x0c05cf48u,4);
goto P_0c05cdee;
P_0c05cdee: /* original 6022, guest PC 0x0c05cdee */
if(!s->budget--) { s->failed_pc=0x0c05cdeeu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05cdf0;
P_0c05cdf0: /* original c840, guest PC 0x0c05cdf0 */
if(!s->budget--) { s->failed_pc=0x0c05cdf0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c05cdf2;
P_0c05cdf2: /* original 8d07, guest PC 0x0c05cdf2 */
if(!s->budget--) { s->failed_pc=0x0c05cdf2u; return 0; }
cond=r[17]&1u;
r[5]=r[11];
if(cond) { goto P_0c05ce04; }
goto P_0c05cdf6;
P_0c05cdf4: /* original 65b3, guest PC 0x0c05cdf4 */
if(!s->budget--) { s->failed_pc=0x0c05cdf4u; return 0; }
r[5]=r[11];
goto P_0c05cdf6;
P_0c05cdf6: /* original e138, guest PC 0x0c05cdf6 */
if(!s->budget--) { s->failed_pc=0x0c05cdf6u; return 0; }
r[1]=0x00000038u;
goto P_0c05cdf8;
P_0c05cdf8: /* original 6352, guest PC 0x0c05cdf8 */
if(!s->budget--) { s->failed_pc=0x0c05cdf8u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c05cdfa;
P_0c05cdfa: /* original 3312, guest PC 0x0c05cdfa */
if(!s->budget--) { s->failed_pc=0x0c05cdfau; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[1])!=0);
goto P_0c05cdfc;
P_0c05cdfc: /* original 8902, guest PC 0x0c05cdfc */
if(!s->budget--) { s->failed_pc=0x0c05cdfcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ce04; }
goto P_0c05cdfe;
P_0c05cdfe: /* original 6352, guest PC 0x0c05cdfe */
if(!s->budget--) { s->failed_pc=0x0c05cdfeu; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c05ce00;
P_0c05ce00: /* original 331c, guest PC 0x0c05ce00 */
if(!s->budget--) { s->failed_pc=0x0c05ce00u; return 0; }
r[3]+=r[1];
goto P_0c05ce02;
P_0c05ce02: /* original 2532, guest PC 0x0c05ce02 */
if(!s->budget--) { s->failed_pc=0x0c05ce02u; return 0; }
write(ram,r[5],r[3],4);
goto P_0c05ce04;
P_0c05ce04: /* original e700, guest PC 0x0c05ce04 */
if(!s->budget--) { s->failed_pc=0x0c05ce04u; return 0; }
r[7]=0x00000000u;
goto P_0c05ce06;
P_0c05ce06: /* original e6ff, guest PC 0x0c05ce06 */
if(!s->budget--) { s->failed_pc=0x0c05ce06u; return 0; }
r[6]=0xffffffffu;
goto P_0c05ce08;
P_0c05ce08: /* original a00d, guest PC 0x0c05ce08 */
if(!s->budget--) { s->failed_pc=0x0c05ce08u; return 0; }
r[5]=r[7];
goto P_0c05ce26;
P_0c05ce0a: /* original 6573, guest PC 0x0c05ce0a */
if(!s->budget--) { s->failed_pc=0x0c05ce0au; return 0; }
r[5]=r[7];
goto P_0c05ce0c;
P_0c05ce0c: /* original 6353, guest PC 0x0c05ce0c */
if(!s->budget--) { s->failed_pc=0x0c05ce0cu; return 0; }
r[3]=r[5];
goto P_0c05ce0e;
P_0c05ce0e: /* original 4308, guest PC 0x0c05ce0e */
if(!s->budget--) { s->failed_pc=0x0c05ce0eu; return 0; }
r[3]<<=2;
goto P_0c05ce10;
P_0c05ce10: /* original 33bc, guest PC 0x0c05ce10 */
if(!s->budget--) { s->failed_pc=0x0c05ce10u; return 0; }
r[3]+=r[11];
goto P_0c05ce12;
P_0c05ce12: /* original 2f32, guest PC 0x0c05ce12 */
if(!s->budget--) { s->failed_pc=0x0c05ce12u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c05ce14;
P_0c05ce14: /* original 6232, guest PC 0x0c05ce14 */
if(!s->budget--) { s->failed_pc=0x0c05ce14u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c05ce16;
P_0c05ce16: /* original 372c, guest PC 0x0c05ce16 */
if(!s->budget--) { s->failed_pc=0x0c05ce16u; return 0; }
r[7]+=r[2];
goto P_0c05ce18;
P_0c05ce18: /* original 6123, guest PC 0x0c05ce18 */
if(!s->budget--) { s->failed_pc=0x0c05ce18u; return 0; }
r[1]=r[2];
goto P_0c05ce1a;
P_0c05ce1a: /* original 3167, guest PC 0x0c05ce1a */
if(!s->budget--) { s->failed_pc=0x0c05ce1au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[6])!=0);
goto P_0c05ce1c;
P_0c05ce1c: /* original 8b02, guest PC 0x0c05ce1c */
if(!s->budget--) { s->failed_pc=0x0c05ce1cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05ce24; }
goto P_0c05ce1e;
P_0c05ce1e: /* original 1f52, guest PC 0x0c05ce1e */
if(!s->budget--) { s->failed_pc=0x0c05ce1eu; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c05ce20;
P_0c05ce20: /* original 66f2, guest PC 0x0c05ce20 */
if(!s->budget--) { s->failed_pc=0x0c05ce20u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c05ce22;
P_0c05ce22: /* original 6662, guest PC 0x0c05ce22 */
if(!s->budget--) { s->failed_pc=0x0c05ce22u; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c05ce24;
P_0c05ce24: /* original 7501, guest PC 0x0c05ce24 */
if(!s->budget--) { s->failed_pc=0x0c05ce24u; return 0; }
r[5]+=0x00000001u;
goto P_0c05ce26;
P_0c05ce26: /* original 35d2, guest PC 0x0c05ce26 */
if(!s->budget--) { s->failed_pc=0x0c05ce26u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[13])!=0);
goto P_0c05ce28;
P_0c05ce28: /* original 8bf0, guest PC 0x0c05ce28 */
if(!s->budget--) { s->failed_pc=0x0c05ce28u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05ce0c; }
goto P_0c05ce2a;
P_0c05ce2a: /* original 3746, guest PC 0x0c05ce2a */
if(!s->budget--) { s->failed_pc=0x0c05ce2au; return 0; }
r[17]=(r[17]&~1u)|((r[7]>r[4])!=0);
goto P_0c05ce2c;
P_0c05ce2c: /* original 8b0b, guest PC 0x0c05ce2c */
if(!s->budget--) { s->failed_pc=0x0c05ce2cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05ce46; }
goto P_0c05ce2e;
P_0c05ce2e: /* original 6573, guest PC 0x0c05ce2e */
if(!s->budget--) { s->failed_pc=0x0c05ce2eu; return 0; }
r[5]=r[7];
goto P_0c05ce30;
P_0c05ce30: /* original 3548, guest PC 0x0c05ce30 */
if(!s->budget--) { s->failed_pc=0x0c05ce30u; return 0; }
r[5]-=r[4];
goto P_0c05ce32;
P_0c05ce32: /* original 54f2, guest PC 0x0c05ce32 */
if(!s->budget--) { s->failed_pc=0x0c05ce32u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c05ce34;
P_0c05ce34: /* original 4408, guest PC 0x0c05ce34 */
if(!s->budget--) { s->failed_pc=0x0c05ce34u; return 0; }
r[4]<<=2;
goto P_0c05ce36;
P_0c05ce36: /* original 34bc, guest PC 0x0c05ce36 */
if(!s->budget--) { s->failed_pc=0x0c05ce36u; return 0; }
r[4]+=r[11];
goto P_0c05ce38;
P_0c05ce38: /* original 6342, guest PC 0x0c05ce38 */
if(!s->budget--) { s->failed_pc=0x0c05ce38u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c05ce3a;
P_0c05ce3a: /* original 3358, guest PC 0x0c05ce3a */
if(!s->budget--) { s->failed_pc=0x0c05ce3au; return 0; }
r[3]-=r[5];
goto P_0c05ce3c;
P_0c05ce3c: /* original 2432, guest PC 0x0c05ce3c */
if(!s->budget--) { s->failed_pc=0x0c05ce3cu; return 0; }
write(ram,r[4],r[3],4);
goto P_0c05ce3e;
P_0c05ce3e: /* original e3e0, guest PC 0x0c05ce3e */
if(!s->budget--) { s->failed_pc=0x0c05ce3eu; return 0; }
r[3]=0xffffffe0u;
goto P_0c05ce40;
P_0c05ce40: /* original 6242, guest PC 0x0c05ce40 */
if(!s->budget--) { s->failed_pc=0x0c05ce40u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c05ce42;
P_0c05ce42: /* original 2239, guest PC 0x0c05ce42 */
if(!s->budget--) { s->failed_pc=0x0c05ce42u; return 0; }
r[2]&=r[3];
goto P_0c05ce44;
P_0c05ce44: /* original 2422, guest PC 0x0c05ce44 */
if(!s->budget--) { s->failed_pc=0x0c05ce44u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c05ce46;
P_0c05ce46: /* original 64b3, guest PC 0x0c05ce46 */
if(!s->budget--) { s->failed_pc=0x0c05ce46u; return 0; }
r[4]=r[11];
goto P_0c05ce48;
P_0c05ce48: /* original 6342, guest PC 0x0c05ce48 */
if(!s->budget--) { s->failed_pc=0x0c05ce48u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c05ce4a;
P_0c05ce4a: /* original 2338, guest PC 0x0c05ce4a */
if(!s->budget--) { s->failed_pc=0x0c05ce4au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c05ce4c;
P_0c05ce4c: /* original 8d03, guest PC 0x0c05ce4c */
if(!s->budget--) { s->failed_pc=0x0c05ce4cu; return 0; }
cond=r[17]&1u;
r[6]=0x00000001u;
if(cond) { goto P_0c05ce56; }
goto P_0c05ce50;
P_0c05ce4e: /* original e601, guest PC 0x0c05ce4e */
if(!s->budget--) { s->failed_pc=0x0c05ce4eu; return 0; }
r[6]=0x00000001u;
goto P_0c05ce50;
P_0c05ce50: /* original 6342, guest PC 0x0c05ce50 */
if(!s->budget--) { s->failed_pc=0x0c05ce50u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c05ce52;
P_0c05ce52: /* original 73f0, guest PC 0x0c05ce52 */
if(!s->budget--) { s->failed_pc=0x0c05ce52u; return 0; }
r[3]+=0xfffffff0u;
goto P_0c05ce54;
P_0c05ce54: /* original 2432, guest PC 0x0c05ce54 */
if(!s->budget--) { s->failed_pc=0x0c05ce54u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c05ce56;
P_0c05ce56: /* original 67b3, guest PC 0x0c05ce56 */
if(!s->budget--) { s->failed_pc=0x0c05ce56u; return 0; }
r[7]=r[11];
goto P_0c05ce58;
P_0c05ce58: /* original 7704, guest PC 0x0c05ce58 */
if(!s->budget--) { s->failed_pc=0x0c05ce58u; return 0; }
r[7]+=0x00000004u;
goto P_0c05ce5a;
P_0c05ce5a: /* original 6473, guest PC 0x0c05ce5a */
if(!s->budget--) { s->failed_pc=0x0c05ce5au; return 0; }
r[4]=r[7];
goto P_0c05ce5c;
P_0c05ce5c: /* original a009, guest PC 0x0c05ce5c */
if(!s->budget--) { s->failed_pc=0x0c05ce5cu; return 0; }
r[5]=r[7];
goto P_0c05ce72;
P_0c05ce5e: /* original 6573, guest PC 0x0c05ce5e */
if(!s->budget--) { s->failed_pc=0x0c05ce5eu; return 0; }
r[5]=r[7];
goto P_0c05ce60;
P_0c05ce60: /* original 6352, guest PC 0x0c05ce60 */
if(!s->budget--) { s->failed_pc=0x0c05ce60u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c05ce62;
P_0c05ce62: /* original 2338, guest PC 0x0c05ce62 */
if(!s->budget--) { s->failed_pc=0x0c05ce62u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c05ce64;
P_0c05ce64: /* original 8d03, guest PC 0x0c05ce64 */
if(!s->budget--) { s->failed_pc=0x0c05ce64u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000001u;
if(cond) { goto P_0c05ce6e; }
goto P_0c05ce68;
P_0c05ce66: /* original 7601, guest PC 0x0c05ce66 */
if(!s->budget--) { s->failed_pc=0x0c05ce66u; return 0; }
r[6]+=0x00000001u;
goto P_0c05ce68;
P_0c05ce68: /* original 6342, guest PC 0x0c05ce68 */
if(!s->budget--) { s->failed_pc=0x0c05ce68u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c05ce6a;
P_0c05ce6a: /* original 73f0, guest PC 0x0c05ce6a */
if(!s->budget--) { s->failed_pc=0x0c05ce6au; return 0; }
r[3]+=0xfffffff0u;
goto P_0c05ce6c;
P_0c05ce6c: /* original 2432, guest PC 0x0c05ce6c */
if(!s->budget--) { s->failed_pc=0x0c05ce6cu; return 0; }
write(ram,r[4],r[3],4);
goto P_0c05ce6e;
P_0c05ce6e: /* original 7404, guest PC 0x0c05ce6e */
if(!s->budget--) { s->failed_pc=0x0c05ce6eu; return 0; }
r[4]+=0x00000004u;
goto P_0c05ce70;
P_0c05ce70: /* original 7504, guest PC 0x0c05ce70 */
if(!s->budget--) { s->failed_pc=0x0c05ce70u; return 0; }
r[5]+=0x00000004u;
goto P_0c05ce72;
P_0c05ce72: /* original 36d2, guest PC 0x0c05ce72 */
if(!s->budget--) { s->failed_pc=0x0c05ce72u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[13])!=0);
goto P_0c05ce74;
P_0c05ce74: /* original 8bf4, guest PC 0x0c05ce74 */
if(!s->budget--) { s->failed_pc=0x0c05ce74u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05ce60; }
goto P_0c05ce76;
P_0c05ce76: /* original 62b3, guest PC 0x0c05ce76 */
if(!s->budget--) { s->failed_pc=0x0c05ce76u; return 0; }
r[2]=r[11];
goto P_0c05ce78;
P_0c05ce78: /* original 53e8, guest PC 0x0c05ce78 */
if(!s->budget--) { s->failed_pc=0x0c05ce78u; return 0; }
r[3]=read(ram,r[14]+32,4);
goto P_0c05ce7a;
P_0c05ce7a: /* original 2c32, guest PC 0x0c05ce7a */
if(!s->budget--) { s->failed_pc=0x0c05ce7au; return 0; }
write(ram,r[12],r[3],4);
goto P_0c05ce7c;
P_0c05ce7c: /* original 1f22, guest PC 0x0c05ce7c */
if(!s->budget--) { s->failed_pc=0x0c05ce7cu; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c05ce7e;
P_0c05ce7e: /* original 6326, guest PC 0x0c05ce7e */
if(!s->budget--) { s->failed_pc=0x0c05ce7eu; return 0; }
tmp=read(ram,r[2],4);
r[2]+=4;
r[3]=tmp;
goto P_0c05ce80;
P_0c05ce80: /* original 1c31, guest PC 0x0c05ce80 */
if(!s->budget--) { s->failed_pc=0x0c05ce80u; return 0; }
write(ram,r[12]+4,r[3],4);
goto P_0c05ce82;
P_0c05ce82: /* original 1f27, guest PC 0x0c05ce82 */
if(!s->budget--) { s->failed_pc=0x0c05ce82u; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c05ce84;
P_0c05ce84: /* original 6322, guest PC 0x0c05ce84 */
if(!s->budget--) { s->failed_pc=0x0c05ce84u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c05ce86;
P_0c05ce86: /* original 62b3, guest PC 0x0c05ce86 */
if(!s->budget--) { s->failed_pc=0x0c05ce86u; return 0; }
r[2]=r[11];
goto P_0c05ce88;
P_0c05ce88: /* original 1c32, guest PC 0x0c05ce88 */
if(!s->budget--) { s->failed_pc=0x0c05ce88u; return 0; }
write(ram,r[12]+8,r[3],4);
goto P_0c05ce8a;
P_0c05ce8a: /* original 7208, guest PC 0x0c05ce8a */
if(!s->budget--) { s->failed_pc=0x0c05ce8au; return 0; }
r[2]+=0x00000008u;
goto P_0c05ce8c;
P_0c05ce8c: /* original 1f26, guest PC 0x0c05ce8c */
if(!s->budget--) { s->failed_pc=0x0c05ce8cu; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c05ce8e;
P_0c05ce8e: /* original 6322, guest PC 0x0c05ce8e */
if(!s->budget--) { s->failed_pc=0x0c05ce8eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c05ce90;
P_0c05ce90: /* original 1c33, guest PC 0x0c05ce90 */
if(!s->budget--) { s->failed_pc=0x0c05ce90u; return 0; }
write(ram,r[12]+12,r[3],4);
goto P_0c05ce92;
P_0c05ce92: /* original 62b3, guest PC 0x0c05ce92 */
if(!s->budget--) { s->failed_pc=0x0c05ce92u; return 0; }
r[2]=r[11];
goto P_0c05ce94;
P_0c05ce94: /* original 720c, guest PC 0x0c05ce94 */
if(!s->budget--) { s->failed_pc=0x0c05ce94u; return 0; }
r[2]+=0x0000000cu;
goto P_0c05ce96;
P_0c05ce96: /* original 1f25, guest PC 0x0c05ce96 */
if(!s->budget--) { s->failed_pc=0x0c05ce96u; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c05ce98;
P_0c05ce98: /* original 6322, guest PC 0x0c05ce98 */
if(!s->budget--) { s->failed_pc=0x0c05ce98u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c05ce9a;
P_0c05ce9a: /* original 62b3, guest PC 0x0c05ce9a */
if(!s->budget--) { s->failed_pc=0x0c05ce9au; return 0; }
r[2]=r[11];
goto P_0c05ce9c;
P_0c05ce9c: /* original 1c34, guest PC 0x0c05ce9c */
if(!s->budget--) { s->failed_pc=0x0c05ce9cu; return 0; }
write(ram,r[12]+16,r[3],4);
goto P_0c05ce9e;
P_0c05ce9e: /* original 7210, guest PC 0x0c05ce9e */
if(!s->budget--) { s->failed_pc=0x0c05ce9eu; return 0; }
r[2]+=0x00000010u;
goto P_0c05cea0;
P_0c05cea0: /* original 2f22, guest PC 0x0c05cea0 */
if(!s->budget--) { s->failed_pc=0x0c05cea0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c05cea2;
P_0c05cea2: /* original 6322, guest PC 0x0c05cea2 */
if(!s->budget--) { s->failed_pc=0x0c05cea2u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c05cea4;
P_0c05cea4: /* original 1c35, guest PC 0x0c05cea4 */
if(!s->budget--) { s->failed_pc=0x0c05cea4u; return 0; }
write(ram,r[12]+20,r[3],4);
goto P_0c05cea6;
P_0c05cea6: /* original 62f2, guest PC 0x0c05cea6 */
if(!s->budget--) { s->failed_pc=0x0c05cea6u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c05cea8;
P_0c05cea8: /* original 6322, guest PC 0x0c05cea8 */
if(!s->budget--) { s->failed_pc=0x0c05cea8u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c05ceaa;
P_0c05ceaa: /* original 2f36, guest PC 0x0c05ceaa */
if(!s->budget--) { s->failed_pc=0x0c05ceaau; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ceac;
P_0c05ceac: /* original 57f6, guest PC 0x0c05ceac */
if(!s->budget--) { s->failed_pc=0x0c05ceacu; return 0; }
r[7]=read(ram,r[15]+24,4);
goto P_0c05ceae;
P_0c05ceae: /* original 6772, guest PC 0x0c05ceae */
if(!s->budget--) { s->failed_pc=0x0c05ceaeu; return 0; }
tmp=read(ram,r[7],4);
r[7]=tmp;
goto P_0c05ceb0;
P_0c05ceb0: /* original 56f7, guest PC 0x0c05ceb0 */
if(!s->budget--) { s->failed_pc=0x0c05ceb0u; return 0; }
r[6]=read(ram,r[15]+28,4);
goto P_0c05ceb2;
P_0c05ceb2: /* original 6662, guest PC 0x0c05ceb2 */
if(!s->budget--) { s->failed_pc=0x0c05ceb2u; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c05ceb4;
P_0c05ceb4: /* original 55f8, guest PC 0x0c05ceb4 */
if(!s->budget--) { s->failed_pc=0x0c05ceb4u; return 0; }
r[5]=read(ram,r[15]+32,4);
goto P_0c05ceb6;
P_0c05ceb6: /* original 6552, guest PC 0x0c05ceb6 */
if(!s->budget--) { s->failed_pc=0x0c05ceb6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c05ceb8;
P_0c05ceb8: /* original 54f3, guest PC 0x0c05ceb8 */
if(!s->budget--) { s->failed_pc=0x0c05ceb8u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c05ceba;
P_0c05ceba: /* original b19f, guest PC 0x0c05ceba */
if(!s->budget--) { s->failed_pc=0x0c05cebau; return 0; }
target=code_base|0x0c05d1fcu; r[16]=code_base|0x0c05cebeu;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05cebeu) { target=s->pc; goto dispatch; }
goto P_0c05cebe;
P_0c05cebc: /* original 6442, guest PC 0x0c05cebc */
if(!s->budget--) { s->failed_pc=0x0c05cebcu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05cebe;
P_0c05cebe: /* original 7f04, guest PC 0x0c05cebe */
if(!s->budget--) { s->failed_pc=0x0c05cebeu; return 0; }
r[15]+=0x00000004u;
goto P_0c05cec0;
P_0c05cec0: /* original d122, guest PC 0x0c05cec0 */
if(!s->budget--) { s->failed_pc=0x0c05cec0u; return 0; }
r[1]=read(ram,0x0c05cf4cu,4);
goto P_0c05cec2;
P_0c05cec2: /* original 52e8, guest PC 0x0c05cec2 */
if(!s->budget--) { s->failed_pc=0x0c05cec2u; return 0; }
r[2]=read(ram,r[14]+32,4);
goto P_0c05cec4;
P_0c05cec4: /* original 6312, guest PC 0x0c05cec4 */
if(!s->budget--) { s->failed_pc=0x0c05cec4u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c05cec6;
P_0c05cec6: /* original 1234, guest PC 0x0c05cec6 */
if(!s->budget--) { s->failed_pc=0x0c05cec6u; return 0; }
write(ram,r[2]+16,r[3],4);
goto P_0c05cec8;
P_0c05cec8: /* original d421, guest PC 0x0c05cec8 */
if(!s->budget--) { s->failed_pc=0x0c05cec8u; return 0; }
r[4]=read(ram,0x0c05cf50u,4);
goto P_0c05ceca;
P_0c05ceca: /* original a003, guest PC 0x0c05ceca */
if(!s->budget--) { s->failed_pc=0x0c05cecau; return 0; }
r[5]=0x00000000u;
goto P_0c05ced4;
P_0c05cecc: /* original e500, guest PC 0x0c05cecc */
if(!s->budget--) { s->failed_pc=0x0c05ceccu; return 0; }
r[5]=0x00000000u;
goto P_0c05cece;
P_0c05cece: /* original 7501, guest PC 0x0c05cece */
if(!s->budget--) { s->failed_pc=0x0c05ceceu; return 0; }
r[5]+=0x00000001u;
goto P_0c05ced0;
P_0c05ced0: /* original 24a2, guest PC 0x0c05ced0 */
if(!s->budget--) { s->failed_pc=0x0c05ced0u; return 0; }
write(ram,r[4],r[10],4);
goto P_0c05ced2;
P_0c05ced2: /* original 7404, guest PC 0x0c05ced2 */
if(!s->budget--) { s->failed_pc=0x0c05ced2u; return 0; }
r[4]+=0x00000004u;
goto P_0c05ced4;
P_0c05ced4: /* original 35d2, guest PC 0x0c05ced4 */
if(!s->budget--) { s->failed_pc=0x0c05ced4u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[13])!=0);
goto P_0c05ced6;
P_0c05ced6: /* original 8bfa, guest PC 0x0c05ced6 */
if(!s->budget--) { s->failed_pc=0x0c05ced6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05cece; }
goto P_0c05ced8;
P_0c05ced8: /* original 2fa6, guest PC 0x0c05ced8 */
if(!s->budget--) { s->failed_pc=0x0c05ced8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ceda;
P_0c05ceda: /* original 53b4, guest PC 0x0c05ceda */
if(!s->budget--) { s->failed_pc=0x0c05cedau; return 0; }
r[3]=read(ram,r[11]+16,4);
goto P_0c05cedc;
P_0c05cedc: /* original 2f36, guest PC 0x0c05cedc */
if(!s->budget--) { s->failed_pc=0x0c05cedcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05cede;
P_0c05cede: /* original 57b3, guest PC 0x0c05cede */
if(!s->budget--) { s->failed_pc=0x0c05cedeu; return 0; }
r[7]=read(ram,r[11]+12,4);
goto P_0c05cee0;
P_0c05cee0: /* original 56b2, guest PC 0x0c05cee0 */
if(!s->budget--) { s->failed_pc=0x0c05cee0u; return 0; }
r[6]=read(ram,r[11]+8,4);
goto P_0c05cee2;
P_0c05cee2: /* original 55b1, guest PC 0x0c05cee2 */
if(!s->budget--) { s->failed_pc=0x0c05cee2u; return 0; }
r[5]=read(ram,r[11]+4,4);
goto P_0c05cee4;
P_0c05cee4: /* original b1f4, guest PC 0x0c05cee4 */
if(!s->budget--) { s->failed_pc=0x0c05cee4u; return 0; }
target=code_base|0x0c05d2d0u; r[16]=code_base|0x0c05cee8u;
tmp=read(ram,r[11],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05cee8u) { target=s->pc; goto dispatch; }
goto P_0c05cee8;
P_0c05cee6: /* original 64b2, guest PC 0x0c05cee6 */
if(!s->budget--) { s->failed_pc=0x0c05cee6u; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c05cee8;
P_0c05cee8: /* original 7f08, guest PC 0x0c05cee8 */
if(!s->budget--) { s->failed_pc=0x0c05cee8u; return 0; }
r[15]+=0x00000008u;
goto P_0c05ceea;
P_0c05ceea: /* original 2f02, guest PC 0x0c05ceea */
if(!s->budget--) { s->failed_pc=0x0c05ceeau; return 0; }
write(ram,r[15],r[0],4);
goto P_0c05ceec;
P_0c05ceec: /* original b35c, guest PC 0x0c05ceec */
if(!s->budget--) { s->failed_pc=0x0c05ceecu; return 0; }
target=code_base|0x0c05d5a8u; r[16]=code_base|0x0c05cef0u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05cef0u) { target=s->pc; goto dispatch; }
goto P_0c05cef0;
P_0c05ceee: /* original 6403, guest PC 0x0c05ceee */
if(!s->budget--) { s->failed_pc=0x0c05ceeeu; return 0; }
r[4]=r[0];
goto P_0c05cef0;
P_0c05cef0: /* original d210, guest PC 0x0c05cef0 */
if(!s->budget--) { s->failed_pc=0x0c05cef0u; return 0; }
r[2]=read(ram,0x0c05cf34u,4);
goto P_0c05cef2;
P_0c05cef2: /* original 6022, guest PC 0x0c05cef2 */
if(!s->budget--) { s->failed_pc=0x0c05cef2u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05cef4;
P_0c05cef4: /* original 8801, guest PC 0x0c05cef4 */
if(!s->budget--) { s->failed_pc=0x0c05cef4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05cef6;
P_0c05cef6: /* original 8b01, guest PC 0x0c05cef6 */
if(!s->budget--) { s->failed_pc=0x0c05cef6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05cefc; }
goto P_0c05cef8;
P_0c05cef8: /* original e101, guest PC 0x0c05cef8 */
if(!s->budget--) { s->failed_pc=0x0c05cef8u; return 0; }
r[1]=0x00000001u;
goto P_0c05cefa;
P_0c05cefa: /* original 1f11, guest PC 0x0c05cefa */
if(!s->budget--) { s->failed_pc=0x0c05cefau; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c05cefc;
P_0c05cefc: /* original 53f1, guest PC 0x0c05cefc */
if(!s->budget--) { s->failed_pc=0x0c05cefcu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c05cefe;
P_0c05cefe: /* original 2f36, guest PC 0x0c05cefe */
if(!s->budget--) { s->failed_pc=0x0c05cefeu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05cf00;
P_0c05cf00: /* original 2fa6, guest PC 0x0c05cf00 */
if(!s->budget--) { s->failed_pc=0x0c05cf00u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05cf02;
P_0c05cf02: /* original 53b4, guest PC 0x0c05cf02 */
if(!s->budget--) { s->failed_pc=0x0c05cf02u; return 0; }
r[3]=read(ram,r[11]+16,4);
goto P_0c05cf04;
P_0c05cf04: /* original 2f36, guest PC 0x0c05cf04 */
if(!s->budget--) { s->failed_pc=0x0c05cf04u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05cf06;
P_0c05cf06: /* original 57b3, guest PC 0x0c05cf06 */
if(!s->budget--) { s->failed_pc=0x0c05cf06u; return 0; }
r[7]=read(ram,r[11]+12,4);
goto P_0c05cf08;
P_0c05cf08: /* original 56b2, guest PC 0x0c05cf08 */
if(!s->budget--) { s->failed_pc=0x0c05cf08u; return 0; }
r[6]=read(ram,r[11]+8,4);
goto P_0c05cf0a;
P_0c05cf0a: /* original 55b1, guest PC 0x0c05cf0a */
if(!s->budget--) { s->failed_pc=0x0c05cf0au; return 0; }
r[5]=read(ram,r[11]+4,4);
goto P_0c05cf0c;
P_0c05cf0c: /* original b3c4, guest PC 0x0c05cf0c */
if(!s->budget--) { s->failed_pc=0x0c05cf0cu; return 0; }
target=code_base|0x0c05d698u; r[16]=code_base|0x0c05cf10u;
tmp=read(ram,r[11],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05cf10u) { target=s->pc; goto dispatch; }
goto P_0c05cf10;
P_0c05cf0e: /* original 64b2, guest PC 0x0c05cf0e */
if(!s->budget--) { s->failed_pc=0x0c05cf0eu; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c05cf10;
P_0c05cf10: /* original d510, guest PC 0x0c05cf10 */
if(!s->budget--) { s->failed_pc=0x0c05cf10u; return 0; }
r[5]=read(ram,0x0c05cf54u,4);
goto P_0c05cf12;
P_0c05cf12: /* original e600, guest PC 0x0c05cf12 */
if(!s->budget--) { s->failed_pc=0x0c05cf12u; return 0; }
r[6]=0x00000000u;
goto P_0c05cf14;
P_0c05cf14: /* original d710, guest PC 0x0c05cf14 */
if(!s->budget--) { s->failed_pc=0x0c05cf14u; return 0; }
r[7]=read(ram,0x0c05cf58u,4);
goto P_0c05cf16;
P_0c05cf16: /* original 7f0c, guest PC 0x0c05cf16 */
if(!s->budget--) { s->failed_pc=0x0c05cf16u; return 0; }
r[15]+=0x0000000cu;
goto P_0c05cf18;
P_0c05cf18: /* original 6453, guest PC 0x0c05cf18 */
if(!s->budget--) { s->failed_pc=0x0c05cf18u; return 0; }
r[4]=r[5];
goto P_0c05cf1a;
P_0c05cf1a: /* original 6342, guest PC 0x0c05cf1a */
if(!s->budget--) { s->failed_pc=0x0c05cf1au; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c05cf1c;
P_0c05cf1c: /* original 2832, guest PC 0x0c05cf1c */
if(!s->budget--) { s->failed_pc=0x0c05cf1cu; return 0; }
write(ram,r[8],r[3],4);
goto P_0c05cf1e;
P_0c05cf1e: /* original 5241, guest PC 0x0c05cf1e */
if(!s->budget--) { s->failed_pc=0x0c05cf1eu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c05cf20;
P_0c05cf20: /* original 1821, guest PC 0x0c05cf20 */
if(!s->budget--) { s->failed_pc=0x0c05cf20u; return 0; }
write(ram,r[8]+4,r[2],4);
goto P_0c05cf22;
P_0c05cf22: /* original 5342, guest PC 0x0c05cf22 */
if(!s->budget--) { s->failed_pc=0x0c05cf22u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c05cf24;
P_0c05cf24: /* original 1832, guest PC 0x0c05cf24 */
if(!s->budget--) { s->failed_pc=0x0c05cf24u; return 0; }
write(ram,r[8]+8,r[3],4);
goto P_0c05cf26;
P_0c05cf26: /* original 5243, guest PC 0x0c05cf26 */
if(!s->budget--) { s->failed_pc=0x0c05cf26u; return 0; }
r[2]=read(ram,r[4]+12,4);
goto P_0c05cf28;
P_0c05cf28: /* original 1823, guest PC 0x0c05cf28 */
if(!s->budget--) { s->failed_pc=0x0c05cf28u; return 0; }
write(ram,r[8]+12,r[2],4);
goto P_0c05cf2a;
P_0c05cf2a: /* original 5344, guest PC 0x0c05cf2a */
if(!s->budget--) { s->failed_pc=0x0c05cf2au; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c05cf2c;
P_0c05cf2c: /* original 1834, guest PC 0x0c05cf2c */
if(!s->budget--) { s->failed_pc=0x0c05cf2cu; return 0; }
write(ram,r[8]+16,r[3],4);
goto P_0c05cf2e;
P_0c05cf2e: /* original a01b, guest PC 0x0c05cf2e */
if(!s->budget--) { s->failed_pc=0x0c05cf2eu; return 0; }
r[4]=r[10];
goto P_0c05cf68;
P_0c05cf30: /* original 64a3, guest PC 0x0c05cf30 */
if(!s->budget--) { s->failed_pc=0x0c05cf30u; return 0; }
r[4]=r[10];
if(!vf3_matrix_family(0x0c05cf32u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05cf32u; return 0; } return 1;
P_0c05cf5c: /* original 6043, guest PC 0x0c05cf5c */
if(!s->budget--) { s->failed_pc=0x0c05cf5cu; return 0; }
r[0]=r[4];
goto P_0c05cf5e;
P_0c05cf5e: /* original 0009, guest PC 0x0c05cf5e */
if(!s->budget--) { s->failed_pc=0x0c05cf5eu; return 0; }
goto P_0c05cf60;
P_0c05cf60: /* original 038e, guest PC 0x0c05cf60 */
if(!s->budget--) { s->failed_pc=0x0c05cf60u; return 0; }
r[3]=read(ram,r[8]+r[0],4);
goto P_0c05cf62;
P_0c05cf62: /* original 7601, guest PC 0x0c05cf62 */
if(!s->budget--) { s->failed_pc=0x0c05cf62u; return 0; }
r[6]+=0x00000001u;
goto P_0c05cf64;
P_0c05cf64: /* original 0736, guest PC 0x0c05cf64 */
if(!s->budget--) { s->failed_pc=0x0c05cf64u; return 0; }
write(ram,r[7]+r[0],r[3],4);
goto P_0c05cf66;
P_0c05cf66: /* original 7404, guest PC 0x0c05cf66 */
if(!s->budget--) { s->failed_pc=0x0c05cf66u; return 0; }
r[4]+=0x00000004u;
goto P_0c05cf68;
P_0c05cf68: /* original 36d2, guest PC 0x0c05cf68 */
if(!s->budget--) { s->failed_pc=0x0c05cf68u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[13])!=0);
goto P_0c05cf6a;
P_0c05cf6a: /* original 8bf7, guest PC 0x0c05cf6a */
if(!s->budget--) { s->failed_pc=0x0c05cf6au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05cf5c; }
goto P_0c05cf6c;
P_0c05cf6c: /* original d48c, guest PC 0x0c05cf6c */
if(!s->budget--) { s->failed_pc=0x0c05cf6cu; return 0; }
r[4]=read(ram,0x0c05d1a0u,4);
goto P_0c05cf6e;
P_0c05cf6e: /* original 24a2, guest PC 0x0c05cf6e */
if(!s->budget--) { s->failed_pc=0x0c05cf6eu; return 0; }
write(ram,r[4],r[10],4);
goto P_0c05cf70;
P_0c05cf70: /* original 14a1, guest PC 0x0c05cf70 */
if(!s->budget--) { s->failed_pc=0x0c05cf70u; return 0; }
write(ram,r[4]+4,r[10],4);
goto P_0c05cf72;
P_0c05cf72: /* original 14a2, guest PC 0x0c05cf72 */
if(!s->budget--) { s->failed_pc=0x0c05cf72u; return 0; }
write(ram,r[4]+8,r[10],4);
goto P_0c05cf74;
P_0c05cf74: /* original 14a3, guest PC 0x0c05cf74 */
if(!s->budget--) { s->failed_pc=0x0c05cf74u; return 0; }
write(ram,r[4]+12,r[10],4);
goto P_0c05cf76;
P_0c05cf76: /* original e400, guest PC 0x0c05cf76 */
if(!s->budget--) { s->failed_pc=0x0c05cf76u; return 0; }
r[4]=0x00000000u;
goto P_0c05cf78;
P_0c05cf78: /* original d38a, guest PC 0x0c05cf78 */
if(!s->budget--) { s->failed_pc=0x0c05cf78u; return 0; }
r[3]=read(ram,0x0c05d1a4u,4);
goto P_0c05cf7a;
P_0c05cf7a: /* original 6143, guest PC 0x0c05cf7a */
if(!s->budget--) { s->failed_pc=0x0c05cf7au; return 0; }
r[1]=r[4];
goto P_0c05cf7c;
P_0c05cf7c: /* original db8a, guest PC 0x0c05cf7c */
if(!s->budget--) { s->failed_pc=0x0c05cf7cu; return 0; }
r[11]=read(ram,0x0c05d1a8u,4);
goto P_0c05cf7e;
P_0c05cf7e: /* original 2352, guest PC 0x0c05cf7e */
if(!s->budget--) { s->failed_pc=0x0c05cf7eu; return 0; }
write(ram,r[3],r[5],4);
goto P_0c05cf80;
P_0c05cf80: /* original 2b82, guest PC 0x0c05cf80 */
if(!s->budget--) { s->failed_pc=0x0c05cf80u; return 0; }
write(ram,r[11],r[8],4);
goto P_0c05cf82;
P_0c05cf82: /* original 52f1, guest PC 0x0c05cf82 */
if(!s->budget--) { s->failed_pc=0x0c05cf82u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c05cf84;
P_0c05cf84: /* original 3122, guest PC 0x0c05cf84 */
if(!s->budget--) { s->failed_pc=0x0c05cf84u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>=r[2])!=0);
goto P_0c05cf86;
P_0c05cf86: /* original 890e, guest PC 0x0c05cf86 */
if(!s->budget--) { s->failed_pc=0x0c05cf86u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05cfa6; }
goto P_0c05cf88;
P_0c05cf88: /* original d088, guest PC 0x0c05cf88 */
if(!s->budget--) { s->failed_pc=0x0c05cf88u; return 0; }
r[0]=read(ram,0x0c05d1acu,4);
goto P_0c05cf8a;
P_0c05cf8a: /* original 6243, guest PC 0x0c05cf8a */
if(!s->budget--) { s->failed_pc=0x0c05cf8au; return 0; }
r[2]=r[4];
goto P_0c05cf8c;
P_0c05cf8c: /* original 6343, guest PC 0x0c05cf8c */
if(!s->budget--) { s->failed_pc=0x0c05cf8cu; return 0; }
r[3]=r[4];
goto P_0c05cf8e;
P_0c05cf8e: /* original 4308, guest PC 0x0c05cf8e */
if(!s->budget--) { s->failed_pc=0x0c05cf8eu; return 0; }
r[3]<<=2;
goto P_0c05cf90;
P_0c05cf90: /* original 6143, guest PC 0x0c05cf90 */
if(!s->budget--) { s->failed_pc=0x0c05cf90u; return 0; }
r[1]=r[4];
goto P_0c05cf92;
P_0c05cf92: /* original 4208, guest PC 0x0c05cf92 */
if(!s->budget--) { s->failed_pc=0x0c05cf92u; return 0; }
r[2]<<=2;
goto P_0c05cf94;
P_0c05cf94: /* original 321c, guest PC 0x0c05cf94 */
if(!s->budget--) { s->failed_pc=0x0c05cf94u; return 0; }
r[2]+=r[1];
goto P_0c05cf96;
P_0c05cf96: /* original 4208, guest PC 0x0c05cf96 */
if(!s->budget--) { s->failed_pc=0x0c05cf96u; return 0; }
r[2]<<=2;
goto P_0c05cf98;
P_0c05cf98: /* original 622e, guest PC 0x0c05cf98 */
if(!s->budget--) { s->failed_pc=0x0c05cf98u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[2];
goto P_0c05cf9a;
P_0c05cf9a: /* original 325c, guest PC 0x0c05cf9a */
if(!s->budget--) { s->failed_pc=0x0c05cf9au; return 0; }
r[2]+=r[5];
goto P_0c05cf9c;
P_0c05cf9c: /* original 0326, guest PC 0x0c05cf9c */
if(!s->budget--) { s->failed_pc=0x0c05cf9cu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c05cf9e;
P_0c05cf9e: /* original 7401, guest PC 0x0c05cf9e */
if(!s->budget--) { s->failed_pc=0x0c05cf9eu; return 0; }
r[4]+=0x00000001u;
goto P_0c05cfa0;
P_0c05cfa0: /* original 53f1, guest PC 0x0c05cfa0 */
if(!s->budget--) { s->failed_pc=0x0c05cfa0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c05cfa2;
P_0c05cfa2: /* original 3432, guest PC 0x0c05cfa2 */
if(!s->budget--) { s->failed_pc=0x0c05cfa2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[3])!=0);
goto P_0c05cfa4;
P_0c05cfa4: /* original 8bf0, guest PC 0x0c05cfa4 */
if(!s->budget--) { s->failed_pc=0x0c05cfa4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05cf88; }
goto P_0c05cfa6;
P_0c05cfa6: /* original b23d, guest PC 0x0c05cfa6 */
if(!s->budget--) { s->failed_pc=0x0c05cfa6u; return 0; }
target=code_base|0x0c05d424u; r[16]=code_base|0x0c05cfaau;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05cfaau) { target=s->pc; goto dispatch; }
goto P_0c05cfaa;
P_0c05cfa8: /* original 54f1, guest PC 0x0c05cfa8 */
if(!s->budget--) { s->failed_pc=0x0c05cfa8u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c05cfaa;
P_0c05cfaa: /* original e500, guest PC 0x0c05cfaa */
if(!s->budget--) { s->failed_pc=0x0c05cfaau; return 0; }
r[5]=0x00000000u;
goto P_0c05cfac;
P_0c05cfac: /* original a00a, guest PC 0x0c05cfac */
if(!s->budget--) { s->failed_pc=0x0c05cfacu; return 0; }
r[4]=r[5];
goto P_0c05cfc4;
P_0c05cfae: /* original 6453, guest PC 0x0c05cfae */
if(!s->budget--) { s->failed_pc=0x0c05cfaeu; return 0; }
r[4]=r[5];
goto P_0c05cfb0;
P_0c05cfb0: /* original 62b2, guest PC 0x0c05cfb0 */
if(!s->budget--) { s->failed_pc=0x0c05cfb0u; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c05cfb2;
P_0c05cfb2: /* original 7501, guest PC 0x0c05cfb2 */
if(!s->budget--) { s->failed_pc=0x0c05cfb2u; return 0; }
r[5]+=0x00000001u;
goto P_0c05cfb4;
P_0c05cfb4: /* original d07e, guest PC 0x0c05cfb4 */
if(!s->budget--) { s->failed_pc=0x0c05cfb4u; return 0; }
r[0]=read(ram,0x0c05d1b0u,4);
goto P_0c05cfb6;
P_0c05cfb6: /* original 324c, guest PC 0x0c05cfb6 */
if(!s->budget--) { s->failed_pc=0x0c05cfb6u; return 0; }
r[2]+=r[4];
goto P_0c05cfb8;
P_0c05cfb8: /* original 034e, guest PC 0x0c05cfb8 */
if(!s->budget--) { s->failed_pc=0x0c05cfb8u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c05cfba;
P_0c05cfba: /* original 7404, guest PC 0x0c05cfba */
if(!s->budget--) { s->failed_pc=0x0c05cfbau; return 0; }
r[4]+=0x00000004u;
goto P_0c05cfbc;
P_0c05cfbc: /* original 6122, guest PC 0x0c05cfbc */
if(!s->budget--) { s->failed_pc=0x0c05cfbcu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c05cfbe;
P_0c05cfbe: /* original 4308, guest PC 0x0c05cfbe */
if(!s->budget--) { s->failed_pc=0x0c05cfbeu; return 0; }
r[3]<<=2;
goto P_0c05cfc0;
P_0c05cfc0: /* original 313c, guest PC 0x0c05cfc0 */
if(!s->budget--) { s->failed_pc=0x0c05cfc0u; return 0; }
r[1]+=r[3];
goto P_0c05cfc2;
P_0c05cfc2: /* original 2212, guest PC 0x0c05cfc2 */
if(!s->budget--) { s->failed_pc=0x0c05cfc2u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c05cfc4;
P_0c05cfc4: /* original 35d2, guest PC 0x0c05cfc4 */
if(!s->budget--) { s->failed_pc=0x0c05cfc4u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[13])!=0);
goto P_0c05cfc6;
P_0c05cfc6: /* original 8bf3, guest PC 0x0c05cfc6 */
if(!s->budget--) { s->failed_pc=0x0c05cfc6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05cfb0; }
goto P_0c05cfc8;
P_0c05cfc8: /* original a04b, guest PC 0x0c05cfc8 */
if(!s->budget--) { s->failed_pc=0x0c05cfc8u; return 0; }
goto P_0c05d062;
P_0c05cfca: /* original 0009, guest PC 0x0c05cfca */
if(!s->budget--) { s->failed_pc=0x0c05cfcau; return 0; }
goto P_0c05cfcc;
P_0c05cfcc: /* original d179, guest PC 0x0c05cfcc */
if(!s->budget--) { s->failed_pc=0x0c05cfccu; return 0; }
r[1]=read(ram,0x0c05d1b4u,4);
goto P_0c05cfce;
P_0c05cfce: /* original 2192, guest PC 0x0c05cfce */
if(!s->budget--) { s->failed_pc=0x0c05cfceu; return 0; }
write(ram,r[1],r[9],4);
goto P_0c05cfd0;
P_0c05cfd0: /* original 2492, guest PC 0x0c05cfd0 */
if(!s->budget--) { s->failed_pc=0x0c05cfd0u; return 0; }
write(ram,r[4],r[9],4);
goto P_0c05cfd2;
P_0c05cfd2: /* original d079, guest PC 0x0c05cfd2 */
if(!s->budget--) { s->failed_pc=0x0c05cfd2u; return 0; }
r[0]=read(ram,0x0c05d1b8u,4);
goto P_0c05cfd4;
P_0c05cfd4: /* original 6202, guest PC 0x0c05cfd4 */
if(!s->budget--) { s->failed_pc=0x0c05cfd4u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c05cfd6;
P_0c05cfd6: /* original d379, guest PC 0x0c05cfd6 */
if(!s->budget--) { s->failed_pc=0x0c05cfd6u; return 0; }
r[3]=read(ram,0x0c05d1bcu,4);
goto P_0c05cfd8;
P_0c05cfd8: /* original 2322, guest PC 0x0c05cfd8 */
if(!s->budget--) { s->failed_pc=0x0c05cfd8u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c05cfda;
P_0c05cfda: /* original 70f0, guest PC 0x0c05cfda */
if(!s->budget--) { s->failed_pc=0x0c05cfdau; return 0; }
r[0]+=0xfffffff0u;
goto P_0c05cfdc;
P_0c05cfdc: /* original d276, guest PC 0x0c05cfdc */
if(!s->budget--) { s->failed_pc=0x0c05cfdcu; return 0; }
r[2]=read(ram,0x0c05d1b8u,4);
goto P_0c05cfde;
P_0c05cfde: /* original 6122, guest PC 0x0c05cfde */
if(!s->budget--) { s->failed_pc=0x0c05cfdeu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c05cfe0;
P_0c05cfe0: /* original 4108, guest PC 0x0c05cfe0 */
if(!s->budget--) { s->failed_pc=0x0c05cfe0u; return 0; }
r[1]<<=2;
goto P_0c05cfe2;
P_0c05cfe2: /* original 01d6, guest PC 0x0c05cfe2 */
if(!s->budget--) { s->failed_pc=0x0c05cfe2u; return 0; }
write(ram,r[1]+r[0],r[13],4);
goto P_0c05cfe4;
P_0c05cfe4: /* original d376, guest PC 0x0c05cfe4 */
if(!s->budget--) { s->failed_pc=0x0c05cfe4u; return 0; }
r[3]=read(ram,0x0c05d1c0u,4);
goto P_0c05cfe6;
P_0c05cfe6: /* original 23a2, guest PC 0x0c05cfe6 */
if(!s->budget--) { s->failed_pc=0x0c05cfe6u; return 0; }
write(ram,r[3],r[10],4);
goto P_0c05cfe8;
P_0c05cfe8: /* original 7218, guest PC 0x0c05cfe8 */
if(!s->budget--) { s->failed_pc=0x0c05cfe8u; return 0; }
r[2]+=0x00000018u;
goto P_0c05cfea;
P_0c05cfea: /* original 2292, guest PC 0x0c05cfea */
if(!s->budget--) { s->failed_pc=0x0c05cfeau; return 0; }
write(ram,r[2],r[9],4);
goto P_0c05cfec;
P_0c05cfec: /* original 51e8, guest PC 0x0c05cfec */
if(!s->budget--) { s->failed_pc=0x0c05cfecu; return 0; }
r[1]=read(ram,r[14]+32,4);
goto P_0c05cfee;
P_0c05cfee: /* original 64f3, guest PC 0x0c05cfee */
if(!s->budget--) { s->failed_pc=0x0c05cfeeu; return 0; }
r[4]=r[15];
goto P_0c05cff0;
P_0c05cff0: /* original 5014, guest PC 0x0c05cff0 */
if(!s->budget--) { s->failed_pc=0x0c05cff0u; return 0; }
r[0]=read(ram,r[1]+16,4);
goto P_0c05cff2;
P_0c05cff2: /* original 7424, guest PC 0x0c05cff2 */
if(!s->budget--) { s->failed_pc=0x0c05cff2u; return 0; }
r[4]+=0x00000024u;
goto P_0c05cff4;
P_0c05cff4: /* original 6b43, guest PC 0x0c05cff4 */
if(!s->budget--) { s->failed_pc=0x0c05cff4u; return 0; }
r[11]=r[4];
goto P_0c05cff6;
P_0c05cff6: /* original 2099, guest PC 0x0c05cff6 */
if(!s->budget--) { s->failed_pc=0x0c05cff6u; return 0; }
r[0]&=r[9];
goto P_0c05cff8;
P_0c05cff8: /* original 2b02, guest PC 0x0c05cff8 */
if(!s->budget--) { s->failed_pc=0x0c05cff8u; return 0; }
write(ram,r[11],r[0],4);
goto P_0c05cffa;
P_0c05cffa: /* original 61b3, guest PC 0x0c05cffa */
if(!s->budget--) { s->failed_pc=0x0c05cffau; return 0; }
r[1]=r[11];
goto P_0c05cffc;
P_0c05cffc: /* original 7104, guest PC 0x0c05cffc */
if(!s->budget--) { s->failed_pc=0x0c05cffcu; return 0; }
r[1]+=0x00000004u;
goto P_0c05cffe;
P_0c05cffe: /* original 1f11, guest PC 0x0c05cffe */
if(!s->budget--) { s->failed_pc=0x0c05cffeu; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c05d000;
P_0c05d000: /* original 53e8, guest PC 0x0c05d000 */
if(!s->budget--) { s->failed_pc=0x0c05d000u; return 0; }
r[3]=read(ram,r[14]+32,4);
goto P_0c05d002;
P_0c05d002: /* original 5034, guest PC 0x0c05d002 */
if(!s->budget--) { s->failed_pc=0x0c05d002u; return 0; }
r[0]=read(ram,r[3]+16,4);
goto P_0c05d004;
P_0c05d004: /* original 2d09, guest PC 0x0c05d004 */
if(!s->budget--) { s->failed_pc=0x0c05d004u; return 0; }
r[13]&=r[0];
goto P_0c05d006;
P_0c05d006: /* original 63b3, guest PC 0x0c05d006 */
if(!s->budget--) { s->failed_pc=0x0c05d006u; return 0; }
r[3]=r[11];
goto P_0c05d008;
P_0c05d008: /* original 21d2, guest PC 0x0c05d008 */
if(!s->budget--) { s->failed_pc=0x0c05d008u; return 0; }
write(ram,r[1],r[13],4);
goto P_0c05d00a;
P_0c05d00a: /* original 7308, guest PC 0x0c05d00a */
if(!s->budget--) { s->failed_pc=0x0c05d00au; return 0; }
r[3]+=0x00000008u;
goto P_0c05d00c;
P_0c05d00c: /* original 2f32, guest PC 0x0c05d00c */
if(!s->budget--) { s->failed_pc=0x0c05d00cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c05d00e;
P_0c05d00e: /* original 6db3, guest PC 0x0c05d00e */
if(!s->budget--) { s->failed_pc=0x0c05d00eu; return 0; }
r[13]=r[11];
goto P_0c05d010;
P_0c05d010: /* original 50e8, guest PC 0x0c05d010 */
if(!s->budget--) { s->failed_pc=0x0c05d010u; return 0; }
r[0]=read(ram,r[14]+32,4);
goto P_0c05d012;
P_0c05d012: /* original 7d10, guest PC 0x0c05d012 */
if(!s->budget--) { s->failed_pc=0x0c05d012u; return 0; }
r[13]+=0x00000010u;
goto P_0c05d014;
P_0c05d014: /* original 5004, guest PC 0x0c05d014 */
if(!s->budget--) { s->failed_pc=0x0c05d014u; return 0; }
r[0]=read(ram,r[0]+16,4);
goto P_0c05d016;
P_0c05d016: /* original c904, guest PC 0x0c05d016 */
if(!s->budget--) { s->failed_pc=0x0c05d016u; return 0; }
r[0]&=4u;
goto P_0c05d018;
P_0c05d018: /* original 2302, guest PC 0x0c05d018 */
if(!s->budget--) { s->failed_pc=0x0c05d018u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05d01a;
P_0c05d01a: /* original 63b3, guest PC 0x0c05d01a */
if(!s->budget--) { s->failed_pc=0x0c05d01au; return 0; }
r[3]=r[11];
goto P_0c05d01c;
P_0c05d01c: /* original 730c, guest PC 0x0c05d01c */
if(!s->budget--) { s->failed_pc=0x0c05d01cu; return 0; }
r[3]+=0x0000000cu;
goto P_0c05d01e;
P_0c05d01e: /* original 1f32, guest PC 0x0c05d01e */
if(!s->budget--) { s->failed_pc=0x0c05d01eu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c05d020;
P_0c05d020: /* original 50e8, guest PC 0x0c05d020 */
if(!s->budget--) { s->failed_pc=0x0c05d020u; return 0; }
r[0]=read(ram,r[14]+32,4);
goto P_0c05d022;
P_0c05d022: /* original 5004, guest PC 0x0c05d022 */
if(!s->budget--) { s->failed_pc=0x0c05d022u; return 0; }
r[0]=read(ram,r[0]+16,4);
goto P_0c05d024;
P_0c05d024: /* original c908, guest PC 0x0c05d024 */
if(!s->budget--) { s->failed_pc=0x0c05d024u; return 0; }
r[0]&=8u;
goto P_0c05d026;
P_0c05d026: /* original 2302, guest PC 0x0c05d026 */
if(!s->budget--) { s->failed_pc=0x0c05d026u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05d028;
P_0c05d028: /* original 50e8, guest PC 0x0c05d028 */
if(!s->budget--) { s->failed_pc=0x0c05d028u; return 0; }
r[0]=read(ram,r[14]+32,4);
goto P_0c05d02a;
P_0c05d02a: /* original 5004, guest PC 0x0c05d02a */
if(!s->budget--) { s->failed_pc=0x0c05d02au; return 0; }
r[0]=read(ram,r[0]+16,4);
goto P_0c05d02c;
P_0c05d02c: /* original c910, guest PC 0x0c05d02c */
if(!s->budget--) { s->failed_pc=0x0c05d02cu; return 0; }
r[0]&=16u;
goto P_0c05d02e;
P_0c05d02e: /* original 6303, guest PC 0x0c05d02e */
if(!s->budget--) { s->failed_pc=0x0c05d02eu; return 0; }
r[3]=r[0];
goto P_0c05d030;
P_0c05d030: /* original 2d02, guest PC 0x0c05d030 */
if(!s->budget--) { s->failed_pc=0x0c05d030u; return 0; }
write(ram,r[13],r[0],4);
goto P_0c05d032;
P_0c05d032: /* original 2f06, guest PC 0x0c05d032 */
if(!s->budget--) { s->failed_pc=0x0c05d032u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d034;
P_0c05d034: /* original 57f3, guest PC 0x0c05d034 */
if(!s->budget--) { s->failed_pc=0x0c05d034u; return 0; }
r[7]=read(ram,r[15]+12,4);
goto P_0c05d036;
P_0c05d036: /* original 6772, guest PC 0x0c05d036 */
if(!s->budget--) { s->failed_pc=0x0c05d036u; return 0; }
tmp=read(ram,r[7],4);
r[7]=tmp;
goto P_0c05d038;
P_0c05d038: /* original 56f1, guest PC 0x0c05d038 */
if(!s->budget--) { s->failed_pc=0x0c05d038u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c05d03a;
P_0c05d03a: /* original 6662, guest PC 0x0c05d03a */
if(!s->budget--) { s->failed_pc=0x0c05d03au; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c05d03c;
P_0c05d03c: /* original 55f2, guest PC 0x0c05d03c */
if(!s->budget--) { s->failed_pc=0x0c05d03cu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c05d03e;
P_0c05d03e: /* original 6552, guest PC 0x0c05d03e */
if(!s->budget--) { s->failed_pc=0x0c05d03eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c05d040;
P_0c05d040: /* original b0dc, guest PC 0x0c05d040 */
if(!s->budget--) { s->failed_pc=0x0c05d040u; return 0; }
target=code_base|0x0c05d1fcu; r[16]=code_base|0x0c05d044u;
tmp=read(ram,r[11],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d044u) { target=s->pc; goto dispatch; }
goto P_0c05d044;
P_0c05d042: /* original 64b2, guest PC 0x0c05d042 */
if(!s->budget--) { s->failed_pc=0x0c05d042u; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c05d044;
P_0c05d044: /* original 2f96, guest PC 0x0c05d044 */
if(!s->budget--) { s->failed_pc=0x0c05d044u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d046;
P_0c05d046: /* original 62d2, guest PC 0x0c05d046 */
if(!s->budget--) { s->failed_pc=0x0c05d046u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c05d048;
P_0c05d048: /* original 2f26, guest PC 0x0c05d048 */
if(!s->budget--) { s->failed_pc=0x0c05d048u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d04a;
P_0c05d04a: /* original 57f5, guest PC 0x0c05d04a */
if(!s->budget--) { s->failed_pc=0x0c05d04au; return 0; }
r[7]=read(ram,r[15]+20,4);
goto P_0c05d04c;
P_0c05d04c: /* original 56f3, guest PC 0x0c05d04c */
if(!s->budget--) { s->failed_pc=0x0c05d04cu; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c05d04e;
P_0c05d04e: /* original 6772, guest PC 0x0c05d04e */
if(!s->budget--) { s->failed_pc=0x0c05d04eu; return 0; }
tmp=read(ram,r[7],4);
r[7]=tmp;
goto P_0c05d050;
P_0c05d050: /* original 6662, guest PC 0x0c05d050 */
if(!s->budget--) { s->failed_pc=0x0c05d050u; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c05d052;
P_0c05d052: /* original 55f4, guest PC 0x0c05d052 */
if(!s->budget--) { s->failed_pc=0x0c05d052u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c05d054;
P_0c05d054: /* original 6552, guest PC 0x0c05d054 */
if(!s->budget--) { s->failed_pc=0x0c05d054u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c05d056;
P_0c05d056: /* original b13b, guest PC 0x0c05d056 */
if(!s->budget--) { s->failed_pc=0x0c05d056u; return 0; }
target=code_base|0x0c05d2d0u; r[16]=code_base|0x0c05d05au;
tmp=read(ram,r[11],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d05au) { target=s->pc; goto dispatch; }
goto P_0c05d05a;
P_0c05d058: /* original 64b2, guest PC 0x0c05d058 */
if(!s->budget--) { s->failed_pc=0x0c05d058u; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c05d05a;
P_0c05d05a: /* original 7f0c, guest PC 0x0c05d05a */
if(!s->budget--) { s->failed_pc=0x0c05d05au; return 0; }
r[15]+=0x0000000cu;
goto P_0c05d05c;
P_0c05d05c: /* original 2f02, guest PC 0x0c05d05c */
if(!s->budget--) { s->failed_pc=0x0c05d05cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c05d05e;
P_0c05d05e: /* original b2a3, guest PC 0x0c05d05e */
if(!s->budget--) { s->failed_pc=0x0c05d05eu; return 0; }
target=code_base|0x0c05d5a8u; r[16]=code_base|0x0c05d062u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d062u) { target=s->pc; goto dispatch; }
goto P_0c05d062;
P_0c05d060: /* original 6403, guest PC 0x0c05d060 */
if(!s->budget--) { s->failed_pc=0x0c05d060u; return 0; }
r[4]=r[0];
goto P_0c05d062;
P_0c05d062: /* original e05c, guest PC 0x0c05d062 */
if(!s->budget--) { s->failed_pc=0x0c05d062u; return 0; }
r[0]=0x0000005cu;
goto P_0c05d064;
P_0c05d064: /* original 52e7, guest PC 0x0c05d064 */
if(!s->budget--) { s->failed_pc=0x0c05d064u; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c05d066;
P_0c05d066: /* original 0c26, guest PC 0x0c05d066 */
if(!s->budget--) { s->failed_pc=0x0c05d066u; return 0; }
write(ram,r[12]+r[0],r[2],4);
goto P_0c05d068;
P_0c05d068: /* original 6023, guest PC 0x0c05d068 */
if(!s->budget--) { s->failed_pc=0x0c05d068u; return 0; }
r[0]=r[2];
goto P_0c05d06a;
P_0c05d06a: /* original 0009, guest PC 0x0c05d06a */
if(!s->budget--) { s->failed_pc=0x0c05d06au; return 0; }
goto P_0c05d06c;
P_0c05d06c: /* original c807, guest PC 0x0c05d06c */
if(!s->budget--) { s->failed_pc=0x0c05d06cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&7u)==0)!=0);
goto P_0c05d06e;
P_0c05d06e: /* original 8905, guest PC 0x0c05d06e */
if(!s->budget--) { s->failed_pc=0x0c05d06eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d07c; }
goto P_0c05d070;
P_0c05d070: /* original e05c, guest PC 0x0c05d070 */
if(!s->budget--) { s->failed_pc=0x0c05d070u; return 0; }
r[0]=0x0000005cu;
goto P_0c05d072;
P_0c05d072: /* original e3f8, guest PC 0x0c05d072 */
if(!s->budget--) { s->failed_pc=0x0c05d072u; return 0; }
r[3]=0xfffffff8u;
goto P_0c05d074;
P_0c05d074: /* original 02ce, guest PC 0x0c05d074 */
if(!s->budget--) { s->failed_pc=0x0c05d074u; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c05d076;
P_0c05d076: /* original 7207, guest PC 0x0c05d076 */
if(!s->budget--) { s->failed_pc=0x0c05d076u; return 0; }
r[2]+=0x00000007u;
goto P_0c05d078;
P_0c05d078: /* original 2239, guest PC 0x0c05d078 */
if(!s->budget--) { s->failed_pc=0x0c05d078u; return 0; }
r[2]&=r[3];
goto P_0c05d07a;
P_0c05d07a: /* original 0c26, guest PC 0x0c05d07a */
if(!s->budget--) { s->failed_pc=0x0c05d07au; return 0; }
write(ram,r[12]+r[0],r[2],4);
goto P_0c05d07c;
P_0c05d07c: /* original d251, guest PC 0x0c05d07c */
if(!s->budget--) { s->failed_pc=0x0c05d07cu; return 0; }
r[2]=read(ram,0x0c05d1c4u,4);
goto P_0c05d07e;
P_0c05d07e: /* original e05c, guest PC 0x0c05d07e */
if(!s->budget--) { s->failed_pc=0x0c05d07eu; return 0; }
r[0]=0x0000005cu;
goto P_0c05d080;
P_0c05d080: /* original 01ce, guest PC 0x0c05d080 */
if(!s->budget--) { s->failed_pc=0x0c05d080u; return 0; }
r[1]=read(ram,r[12]+r[0],4);
goto P_0c05d082;
P_0c05d082: /* original 4108, guest PC 0x0c05d082 */
if(!s->budget--) { s->failed_pc=0x0c05d082u; return 0; }
r[1]<<=2;
goto P_0c05d084;
P_0c05d084: /* original 6322, guest PC 0x0c05d084 */
if(!s->budget--) { s->failed_pc=0x0c05d084u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c05d086;
P_0c05d086: /* original 3318, guest PC 0x0c05d086 */
if(!s->budget--) { s->failed_pc=0x0c05d086u; return 0; }
r[3]-=r[1];
goto P_0c05d088;
P_0c05d088: /* original d54f, guest PC 0x0c05d088 */
if(!s->budget--) { s->failed_pc=0x0c05d088u; return 0; }
r[5]=read(ram,0x0c05d1c8u,4);
goto P_0c05d08a;
P_0c05d08a: /* original e060, guest PC 0x0c05d08a */
if(!s->budget--) { s->failed_pc=0x0c05d08au; return 0; }
r[0]=0x00000060u;
goto P_0c05d08c;
P_0c05d08c: /* original d44f, guest PC 0x0c05d08c */
if(!s->budget--) { s->failed_pc=0x0c05d08cu; return 0; }
r[4]=read(ram,0x0c05d1ccu,4);
goto P_0c05d08e;
P_0c05d08e: /* original 01ce, guest PC 0x0c05d08e */
if(!s->budget--) { s->failed_pc=0x0c05d08eu; return 0; }
r[1]=read(ram,r[12]+r[0],4);
goto P_0c05d090;
P_0c05d090: /* original 4100, guest PC 0x0c05d090 */
if(!s->budget--) { s->failed_pc=0x0c05d090u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c05d092;
P_0c05d092: /* original 3318, guest PC 0x0c05d092 */
if(!s->budget--) { s->failed_pc=0x0c05d092u; return 0; }
r[3]-=r[1];
goto P_0c05d094;
P_0c05d094: /* original 4301, guest PC 0x0c05d094 */
if(!s->budget--) { s->failed_pc=0x0c05d094u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]>>=1;
goto P_0c05d096;
P_0c05d096: /* original e058, guest PC 0x0c05d096 */
if(!s->budget--) { s->failed_pc=0x0c05d096u; return 0; }
r[0]=0x00000058u;
goto P_0c05d098;
P_0c05d098: /* original 0c36, guest PC 0x0c05d098 */
if(!s->budget--) { s->failed_pc=0x0c05d098u; return 0; }
write(ram,r[12]+r[0],r[3],4);
goto P_0c05d09a;
P_0c05d09a: /* original d34d, guest PC 0x0c05d09a */
if(!s->budget--) { s->failed_pc=0x0c05d09au; return 0; }
r[3]=read(ram,0x0c05d1d0u,4);
goto P_0c05d09c;
P_0c05d09c: /* original 430b, guest PC 0x0c05d09c */
if(!s->budget--) { s->failed_pc=0x0c05d09cu; return 0; }
target=r[3];
r[16]=code_base|0x0c05d0a0u;
r[6]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d0a0u) { target=s->pc; goto dispatch; }
goto P_0c05d0a0;
P_0c05d09e: /* original e600, guest PC 0x0c05d09e */
if(!s->budget--) { s->failed_pc=0x0c05d09eu; return 0; }
r[6]=0x00000000u;
goto P_0c05d0a0;
P_0c05d0a0: /* original 8801, guest PC 0x0c05d0a0 */
if(!s->budget--) { s->failed_pc=0x0c05d0a0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05d0a2;
P_0c05d0a2: /* original 8b06, guest PC 0x0c05d0a2 */
if(!s->budget--) { s->failed_pc=0x0c05d0a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d0b2; }
goto P_0c05d0a4;
P_0c05d0a4: /* original d44b, guest PC 0x0c05d0a4 */
if(!s->budget--) { s->failed_pc=0x0c05d0a4u; return 0; }
r[4]=read(ram,0x0c05d1d4u,4);
goto P_0c05d0a6;
P_0c05d0a6: /* original e058, guest PC 0x0c05d0a6 */
if(!s->budget--) { s->failed_pc=0x0c05d0a6u; return 0; }
r[0]=0x00000058u;
goto P_0c05d0a8;
P_0c05d0a8: /* original 03ce, guest PC 0x0c05d0a8 */
if(!s->budget--) { s->failed_pc=0x0c05d0a8u; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c05d0aa;
P_0c05d0aa: /* original 3346, guest PC 0x0c05d0aa */
if(!s->budget--) { s->failed_pc=0x0c05d0aau; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[4])!=0);
goto P_0c05d0ac;
P_0c05d0ac: /* original 8b07, guest PC 0x0c05d0ac */
if(!s->budget--) { s->failed_pc=0x0c05d0acu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d0be; }
goto P_0c05d0ae;
P_0c05d0ae: /* original a006, guest PC 0x0c05d0ae */
if(!s->budget--) { s->failed_pc=0x0c05d0aeu; return 0; }
write(ram,r[12]+r[0],r[4],4);
goto P_0c05d0be;
P_0c05d0b0: /* original 0c46, guest PC 0x0c05d0b0 */
if(!s->budget--) { s->failed_pc=0x0c05d0b0u; return 0; }
write(ram,r[12]+r[0],r[4],4);
goto P_0c05d0b2;
P_0c05d0b2: /* original e058, guest PC 0x0c05d0b2 */
if(!s->budget--) { s->failed_pc=0x0c05d0b2u; return 0; }
r[0]=0x00000058u;
goto P_0c05d0b4;
P_0c05d0b4: /* original d448, guest PC 0x0c05d0b4 */
if(!s->budget--) { s->failed_pc=0x0c05d0b4u; return 0; }
r[4]=read(ram,0x0c05d1d8u,4);
goto P_0c05d0b6;
P_0c05d0b6: /* original 02ce, guest PC 0x0c05d0b6 */
if(!s->budget--) { s->failed_pc=0x0c05d0b6u; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c05d0b8;
P_0c05d0b8: /* original 3246, guest PC 0x0c05d0b8 */
if(!s->budget--) { s->failed_pc=0x0c05d0b8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[4])!=0);
goto P_0c05d0ba;
P_0c05d0ba: /* original 8b00, guest PC 0x0c05d0ba */
if(!s->budget--) { s->failed_pc=0x0c05d0bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d0be; }
goto P_0c05d0bc;
P_0c05d0bc: /* original 0c46, guest PC 0x0c05d0bc */
if(!s->budget--) { s->failed_pc=0x0c05d0bcu; return 0; }
write(ram,r[12]+r[0],r[4],4);
goto P_0c05d0be;
P_0c05d0be: /* original e058, guest PC 0x0c05d0be */
if(!s->budget--) { s->failed_pc=0x0c05d0beu; return 0; }
r[0]=0x00000058u;
goto P_0c05d0c0;
P_0c05d0c0: /* original 0dce, guest PC 0x0c05d0c0 */
if(!s->budget--) { s->failed_pc=0x0c05d0c0u; return 0; }
r[13]=read(ram,r[12]+r[0],4);
goto P_0c05d0c2;
P_0c05d0c2: /* original e064, guest PC 0x0c05d0c2 */
if(!s->budget--) { s->failed_pc=0x0c05d0c2u; return 0; }
r[0]=0x00000064u;
goto P_0c05d0c4;
P_0c05d0c4: /* original 03ce, guest PC 0x0c05d0c4 */
if(!s->budget--) { s->failed_pc=0x0c05d0c4u; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c05d0c6;
P_0c05d0c6: /* original 3d32, guest PC 0x0c05d0c6 */
if(!s->budget--) { s->failed_pc=0x0c05d0c6u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[3])!=0);
goto P_0c05d0c8;
P_0c05d0c8: /* original 8901, guest PC 0x0c05d0c8 */
if(!s->budget--) { s->failed_pc=0x0c05d0c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d0ce; }
goto P_0c05d0ca;
P_0c05d0ca: /* original a05e, guest PC 0x0c05d0ca */
if(!s->budget--) { s->failed_pc=0x0c05d0cau; return 0; }
r[0]=0x00000003u;
goto P_0c05d18a;
P_0c05d0cc: /* original e003, guest PC 0x0c05d0cc */
if(!s->budget--) { s->failed_pc=0x0c05d0ccu; return 0; }
r[0]=0x00000003u;
goto P_0c05d0ce;
P_0c05d0ce: /* original 66f3, guest PC 0x0c05d0ce */
if(!s->budget--) { s->failed_pc=0x0c05d0ceu; return 0; }
r[6]=r[15];
goto P_0c05d0d0;
P_0c05d0d0: /* original d342, guest PC 0x0c05d0d0 */
if(!s->budget--) { s->failed_pc=0x0c05d0d0u; return 0; }
r[3]=read(ram,0x0c05d1dcu,4);
goto P_0c05d0d2;
P_0c05d0d2: /* original 65f3, guest PC 0x0c05d0d2 */
if(!s->budget--) { s->failed_pc=0x0c05d0d2u; return 0; }
r[5]=r[15];
goto P_0c05d0d4;
P_0c05d0d4: /* original 763c, guest PC 0x0c05d0d4 */
if(!s->budget--) { s->failed_pc=0x0c05d0d4u; return 0; }
r[6]+=0x0000003cu;
goto P_0c05d0d6;
P_0c05d0d6: /* original 7538, guest PC 0x0c05d0d6 */
if(!s->budget--) { s->failed_pc=0x0c05d0d6u; return 0; }
r[5]+=0x00000038u;
goto P_0c05d0d8;
P_0c05d0d8: /* original 430b, guest PC 0x0c05d0d8 */
if(!s->budget--) { s->failed_pc=0x0c05d0d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c05d0dcu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d0dcu) { target=s->pc; goto dispatch; }
goto P_0c05d0dc;
P_0c05d0da: /* original 64d3, guest PC 0x0c05d0da */
if(!s->budget--) { s->failed_pc=0x0c05d0dau; return 0; }
r[4]=r[13];
goto P_0c05d0dc;
P_0c05d0dc: /* original 6403, guest PC 0x0c05d0dc */
if(!s->budget--) { s->failed_pc=0x0c05d0dcu; return 0; }
r[4]=r[0];
goto P_0c05d0de;
P_0c05d0de: /* original 2448, guest PC 0x0c05d0de */
if(!s->budget--) { s->failed_pc=0x0c05d0deu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c05d0e0;
P_0c05d0e0: /* original 8b51, guest PC 0x0c05d0e0 */
if(!s->budget--) { s->failed_pc=0x0c05d0e0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d186; }
goto P_0c05d0e2;
P_0c05d0e2: /* original e058, guest PC 0x0c05d0e2 */
if(!s->budget--) { s->failed_pc=0x0c05d0e2u; return 0; }
r[0]=0x00000058u;
goto P_0c05d0e4;
P_0c05d0e4: /* original d33e, guest PC 0x0c05d0e4 */
if(!s->budget--) { s->failed_pc=0x0c05d0e4u; return 0; }
r[3]=read(ram,0x0c05d1e0u,4);
goto P_0c05d0e6;
P_0c05d0e6: /* original 02ce, guest PC 0x0c05d0e6 */
if(!s->budget--) { s->failed_pc=0x0c05d0e6u; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c05d0e8;
P_0c05d0e8: /* original 2322, guest PC 0x0c05d0e8 */
if(!s->budget--) { s->failed_pc=0x0c05d0e8u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c05d0ea;
P_0c05d0ea: /* original 2fa6, guest PC 0x0c05d0ea */
if(!s->budget--) { s->failed_pc=0x0c05d0eau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d0ec;
P_0c05d0ec: /* original 52f4, guest PC 0x0c05d0ec */
if(!s->budget--) { s->failed_pc=0x0c05d0ecu; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c05d0ee;
P_0c05d0ee: /* original 6227, guest PC 0x0c05d0ee */
if(!s->budget--) { s->failed_pc=0x0c05d0eeu; return 0; }
r[2]=~r[2];
goto P_0c05d0f0;
P_0c05d0f0: /* original 51f1, guest PC 0x0c05d0f0 */
if(!s->budget--) { s->failed_pc=0x0c05d0f0u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c05d0f2;
P_0c05d0f2: /* original 2219, guest PC 0x0c05d0f2 */
if(!s->budget--) { s->failed_pc=0x0c05d0f2u; return 0; }
r[2]&=r[1];
goto P_0c05d0f4;
P_0c05d0f4: /* original 2f26, guest PC 0x0c05d0f4 */
if(!s->budget--) { s->failed_pc=0x0c05d0f4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d0f6;
P_0c05d0f6: /* original d73b, guest PC 0x0c05d0f6 */
if(!s->budget--) { s->failed_pc=0x0c05d0f6u; return 0; }
r[7]=read(ram,0x0c05d1e4u,4);
goto P_0c05d0f8;
P_0c05d0f8: /* original 5773, guest PC 0x0c05d0f8 */
if(!s->budget--) { s->failed_pc=0x0c05d0f8u; return 0; }
r[7]=read(ram,r[7]+12,4);
goto P_0c05d0fa;
P_0c05d0fa: /* original e2f9, guest PC 0x0c05d0fa */
if(!s->budget--) { s->failed_pc=0x0c05d0fau; return 0; }
r[2]=0xfffffff9u;
goto P_0c05d0fc;
P_0c05d0fc: /* original d639, guest PC 0x0c05d0fc */
if(!s->budget--) { s->failed_pc=0x0c05d0fcu; return 0; }
r[6]=read(ram,0x0c05d1e4u,4);
goto P_0c05d0fe;
P_0c05d0fe: /* original 472d, guest PC 0x0c05d0fe */
if(!s->budget--) { s->failed_pc=0x0c05d0feu; return 0; }
r[7]=(r[2]&0x80000000u)?((r[2]&31u)?r[7]>>((-r[2])&31u):0):r[7]<<(r[2]&31u);
goto P_0c05d100;
P_0c05d100: /* original 5662, guest PC 0x0c05d100 */
if(!s->budget--) { s->failed_pc=0x0c05d100u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c05d102;
P_0c05d102: /* original 462d, guest PC 0x0c05d102 */
if(!s->budget--) { s->failed_pc=0x0c05d102u; return 0; }
r[6]=(r[2]&0x80000000u)?((r[2]&31u)?r[6]>>((-r[2])&31u):0):r[6]<<(r[2]&31u);
goto P_0c05d104;
P_0c05d104: /* original d537, guest PC 0x0c05d104 */
if(!s->budget--) { s->failed_pc=0x0c05d104u; return 0; }
r[5]=read(ram,0x0c05d1e4u,4);
goto P_0c05d106;
P_0c05d106: /* original 5551, guest PC 0x0c05d106 */
if(!s->budget--) { s->failed_pc=0x0c05d106u; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c05d108;
P_0c05d108: /* original 452d, guest PC 0x0c05d108 */
if(!s->budget--) { s->failed_pc=0x0c05d108u; return 0; }
r[5]=(r[2]&0x80000000u)?((r[2]&31u)?r[5]>>((-r[2])&31u):0):r[5]<<(r[2]&31u);
goto P_0c05d10a;
P_0c05d10a: /* original d436, guest PC 0x0c05d10a */
if(!s->budget--) { s->failed_pc=0x0c05d10au; return 0; }
r[4]=read(ram,0x0c05d1e4u,4);
goto P_0c05d10c;
P_0c05d10c: /* original 6442, guest PC 0x0c05d10c */
if(!s->budget--) { s->failed_pc=0x0c05d10cu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05d10e;
P_0c05d10e: /* original d136, guest PC 0x0c05d10e */
if(!s->budget--) { s->failed_pc=0x0c05d10eu; return 0; }
r[1]=read(ram,0x0c05d1e8u,4);
goto P_0c05d110;
P_0c05d110: /* original 410b, guest PC 0x0c05d110 */
if(!s->budget--) { s->failed_pc=0x0c05d110u; return 0; }
target=r[1];
r[16]=code_base|0x0c05d114u;
r[4]=(r[2]&0x80000000u)?((r[2]&31u)?r[4]>>((-r[2])&31u):0):r[4]<<(r[2]&31u);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d114u) { target=s->pc; goto dispatch; }
goto P_0c05d114;
P_0c05d112: /* original 442d, guest PC 0x0c05d112 */
if(!s->budget--) { s->failed_pc=0x0c05d112u; return 0; }
r[4]=(r[2]&0x80000000u)?((r[2]&31u)?r[4]>>((-r[2])&31u):0):r[4]<<(r[2]&31u);
goto P_0c05d114;
P_0c05d114: /* original d335, guest PC 0x0c05d114 */
if(!s->budget--) { s->failed_pc=0x0c05d114u; return 0; }
r[3]=read(ram,0x0c05d1ecu,4);
goto P_0c05d116;
P_0c05d116: /* original 52e1, guest PC 0x0c05d116 */
if(!s->budget--) { s->failed_pc=0x0c05d116u; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c05d118;
P_0c05d118: /* original 2238, guest PC 0x0c05d118 */
if(!s->budget--) { s->failed_pc=0x0c05d118u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c05d11a;
P_0c05d11a: /* original 8d02, guest PC 0x0c05d11a */
if(!s->budget--) { s->failed_pc=0x0c05d11au; return 0; }
cond=r[17]&1u;
r[15]+=0x00000008u;
if(cond) { goto P_0c05d122; }
goto P_0c05d11e;
P_0c05d11c: /* original 7f08, guest PC 0x0c05d11c */
if(!s->budget--) { s->failed_pc=0x0c05d11cu; return 0; }
r[15]+=0x00000008u;
goto P_0c05d11e;
P_0c05d11e: /* original d028, guest PC 0x0c05d11e */
if(!s->budget--) { s->failed_pc=0x0c05d11eu; return 0; }
r[0]=read(ram,0x0c05d1c0u,4);
goto P_0c05d120;
P_0c05d120: /* original 2092, guest PC 0x0c05d120 */
if(!s->budget--) { s->failed_pc=0x0c05d120u; return 0; }
write(ram,r[0],r[9],4);
goto P_0c05d122;
P_0c05d122: /* original 53e8, guest PC 0x0c05d122 */
if(!s->budget--) { s->failed_pc=0x0c05d122u; return 0; }
r[3]=read(ram,r[14]+32,4);
goto P_0c05d124;
P_0c05d124: /* original d133, guest PC 0x0c05d124 */
if(!s->budget--) { s->failed_pc=0x0c05d124u; return 0; }
r[1]=read(ram,0x0c05d1f4u,4);
goto P_0c05d126;
P_0c05d126: /* original 2382, guest PC 0x0c05d126 */
if(!s->budget--) { s->failed_pc=0x0c05d126u; return 0; }
write(ram,r[3],r[8],4);
goto P_0c05d128;
P_0c05d128: /* original 52e8, guest PC 0x0c05d128 */
if(!s->budget--) { s->failed_pc=0x0c05d128u; return 0; }
r[2]=read(ram,r[14]+32,4);
goto P_0c05d12a;
P_0c05d12a: /* original d331, guest PC 0x0c05d12a */
if(!s->budget--) { s->failed_pc=0x0c05d12au; return 0; }
r[3]=read(ram,0x0c05d1f0u,4);
goto P_0c05d12c;
P_0c05d12c: /* original 1231, guest PC 0x0c05d12c */
if(!s->budget--) { s->failed_pc=0x0c05d12cu; return 0; }
write(ram,r[2]+4,r[3],4);
goto P_0c05d12e;
P_0c05d12e: /* original 52e8, guest PC 0x0c05d12e */
if(!s->budget--) { s->failed_pc=0x0c05d12eu; return 0; }
r[2]=read(ram,r[14]+32,4);
goto P_0c05d130;
P_0c05d130: /* original d31b, guest PC 0x0c05d130 */
if(!s->budget--) { s->failed_pc=0x0c05d130u; return 0; }
r[3]=read(ram,0x0c05d1a0u,4);
goto P_0c05d132;
P_0c05d132: /* original 1232, guest PC 0x0c05d132 */
if(!s->budget--) { s->failed_pc=0x0c05d132u; return 0; }
write(ram,r[2]+8,r[3],4);
goto P_0c05d134;
P_0c05d134: /* original 52e8, guest PC 0x0c05d134 */
if(!s->budget--) { s->failed_pc=0x0c05d134u; return 0; }
r[2]=read(ram,r[14]+32,4);
goto P_0c05d136;
P_0c05d136: /* original d31d, guest PC 0x0c05d136 */
if(!s->budget--) { s->failed_pc=0x0c05d136u; return 0; }
r[3]=read(ram,0x0c05d1acu,4);
goto P_0c05d138;
P_0c05d138: /* original 1233, guest PC 0x0c05d138 */
if(!s->budget--) { s->failed_pc=0x0c05d138u; return 0; }
write(ram,r[2]+12,r[3],4);
goto P_0c05d13a;
P_0c05d13a: /* original 52f3, guest PC 0x0c05d13a */
if(!s->budget--) { s->failed_pc=0x0c05d13au; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c05d13c;
P_0c05d13c: /* original 1c26, guest PC 0x0c05d13c */
if(!s->budget--) { s->failed_pc=0x0c05d13cu; return 0; }
write(ram,r[12]+24,r[2],4);
goto P_0c05d13e;
P_0c05d13e: /* original 53f3, guest PC 0x0c05d13e */
if(!s->budget--) { s->failed_pc=0x0c05d13eu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c05d140;
P_0c05d140: /* original 2132, guest PC 0x0c05d140 */
if(!s->budget--) { s->failed_pc=0x0c05d140u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c05d142;
P_0c05d142: /* original 52e2, guest PC 0x0c05d142 */
if(!s->budget--) { s->failed_pc=0x0c05d142u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c05d144;
P_0c05d144: /* original 6322, guest PC 0x0c05d144 */
if(!s->budget--) { s->failed_pc=0x0c05d144u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c05d146;
P_0c05d146: /* original 1c37, guest PC 0x0c05d146 */
if(!s->budget--) { s->failed_pc=0x0c05d146u; return 0; }
write(ram,r[12]+28,r[3],4);
goto P_0c05d148;
P_0c05d148: /* original 52e4, guest PC 0x0c05d148 */
if(!s->budget--) { s->failed_pc=0x0c05d148u; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c05d14a;
P_0c05d14a: /* original 1c28, guest PC 0x0c05d14a */
if(!s->budget--) { s->failed_pc=0x0c05d14au; return 0; }
write(ram,r[12]+32,r[2],4);
goto P_0c05d14c;
P_0c05d14c: /* original 53e5, guest PC 0x0c05d14c */
if(!s->budget--) { s->failed_pc=0x0c05d14cu; return 0; }
r[3]=read(ram,r[14]+20,4);
goto P_0c05d14e;
P_0c05d14e: /* original 1c39, guest PC 0x0c05d14e */
if(!s->budget--) { s->failed_pc=0x0c05d14eu; return 0; }
write(ram,r[12]+36,r[3],4);
goto P_0c05d150;
P_0c05d150: /* original 52f4, guest PC 0x0c05d150 */
if(!s->budget--) { s->failed_pc=0x0c05d150u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c05d152;
P_0c05d152: /* original 1c2a, guest PC 0x0c05d152 */
if(!s->budget--) { s->failed_pc=0x0c05d152u; return 0; }
write(ram,r[12]+40,r[2],4);
goto P_0c05d154;
P_0c05d154: /* original 53e2, guest PC 0x0c05d154 */
if(!s->budget--) { s->failed_pc=0x0c05d154u; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c05d156;
P_0c05d156: /* original 5231, guest PC 0x0c05d156 */
if(!s->budget--) { s->failed_pc=0x0c05d156u; return 0; }
r[2]=read(ram,r[3]+4,4);
goto P_0c05d158;
P_0c05d158: /* original 1c2b, guest PC 0x0c05d158 */
if(!s->budget--) { s->failed_pc=0x0c05d158u; return 0; }
write(ram,r[12]+44,r[2],4);
goto P_0c05d15a;
P_0c05d15a: /* original 53e4, guest PC 0x0c05d15a */
if(!s->budget--) { s->failed_pc=0x0c05d15au; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c05d15c;
P_0c05d15c: /* original 1c3c, guest PC 0x0c05d15c */
if(!s->budget--) { s->failed_pc=0x0c05d15cu; return 0; }
write(ram,r[12]+48,r[3],4);
goto P_0c05d15e;
P_0c05d15e: /* original 52e5, guest PC 0x0c05d15e */
if(!s->budget--) { s->failed_pc=0x0c05d15eu; return 0; }
r[2]=read(ram,r[14]+20,4);
goto P_0c05d160;
P_0c05d160: /* original 1c2d, guest PC 0x0c05d160 */
if(!s->budget--) { s->failed_pc=0x0c05d160u; return 0; }
write(ram,r[12]+52,r[2],4);
goto P_0c05d162;
P_0c05d162: /* original e040, guest PC 0x0c05d162 */
if(!s->budget--) { s->failed_pc=0x0c05d162u; return 0; }
r[0]=0x00000040u;
goto P_0c05d164;
P_0c05d164: /* original d424, guest PC 0x0c05d164 */
if(!s->budget--) { s->failed_pc=0x0c05d164u; return 0; }
r[4]=read(ram,0x0c05d1f8u,4);
goto P_0c05d166;
P_0c05d166: /* original 53f4, guest PC 0x0c05d166 */
if(!s->budget--) { s->failed_pc=0x0c05d166u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c05d168;
P_0c05d168: /* original 1c3e, guest PC 0x0c05d168 */
if(!s->budget--) { s->failed_pc=0x0c05d168u; return 0; }
write(ram,r[12]+56,r[3],4);
goto P_0c05d16a;
P_0c05d16a: /* original 52e2, guest PC 0x0c05d16a */
if(!s->budget--) { s->failed_pc=0x0c05d16au; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c05d16c;
P_0c05d16c: /* original 6322, guest PC 0x0c05d16c */
if(!s->budget--) { s->failed_pc=0x0c05d16cu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c05d16e;
P_0c05d16e: /* original 1c3f, guest PC 0x0c05d16e */
if(!s->budget--) { s->failed_pc=0x0c05d16eu; return 0; }
write(ram,r[12]+60,r[3],4);
goto P_0c05d170;
P_0c05d170: /* original 52e2, guest PC 0x0c05d170 */
if(!s->budget--) { s->failed_pc=0x0c05d170u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c05d172;
P_0c05d172: /* original 5321, guest PC 0x0c05d172 */
if(!s->budget--) { s->failed_pc=0x0c05d172u; return 0; }
r[3]=read(ram,r[2]+4,4);
goto P_0c05d174;
P_0c05d174: /* original 0c36, guest PC 0x0c05d174 */
if(!s->budget--) { s->failed_pc=0x0c05d174u; return 0; }
write(ram,r[12]+r[0],r[3],4);
goto P_0c05d176;
P_0c05d176: /* original e044, guest PC 0x0c05d176 */
if(!s->budget--) { s->failed_pc=0x0c05d176u; return 0; }
r[0]=0x00000044u;
goto P_0c05d178;
P_0c05d178: /* original 52f8, guest PC 0x0c05d178 */
if(!s->budget--) { s->failed_pc=0x0c05d178u; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c05d17a;
P_0c05d17a: /* original b45e, guest PC 0x0c05d17a */
if(!s->budget--) { s->failed_pc=0x0c05d17au; return 0; }
target=code_base|0x0c05da3au; r[16]=code_base|0x0c05d17eu;
write(ram,r[12]+r[0],r[2],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d17eu) { target=s->pc; goto dispatch; }
goto P_0c05d17e;
P_0c05d17c: /* original 0c26, guest PC 0x0c05d17c */
if(!s->budget--) { s->failed_pc=0x0c05d17cu; return 0; }
write(ram,r[12]+r[0],r[2],4);
goto P_0c05d17e;
P_0c05d17e: /* original e054, guest PC 0x0c05d17e */
if(!s->budget--) { s->failed_pc=0x0c05d17eu; return 0; }
r[0]=0x00000054u;
goto P_0c05d180;
P_0c05d180: /* original b3ae, guest PC 0x0c05d180 */
if(!s->budget--) { s->failed_pc=0x0c05d180u; return 0; }
target=code_base|0x0c05d8e0u; r[16]=code_base|0x0c05d184u;
r[4]=read(ram,r[12]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d184u) { target=s->pc; goto dispatch; }
goto P_0c05d184;
P_0c05d182: /* original 04ce, guest PC 0x0c05d182 */
if(!s->budget--) { s->failed_pc=0x0c05d182u; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c05d184;
P_0c05d184: /* original 6403, guest PC 0x0c05d184 */
if(!s->budget--) { s->failed_pc=0x0c05d184u; return 0; }
r[4]=r[0];
goto P_0c05d186;
P_0c05d186: /* original 6043, guest PC 0x0c05d186 */
if(!s->budget--) { s->failed_pc=0x0c05d186u; return 0; }
r[0]=r[4];
goto P_0c05d188;
P_0c05d188: /* original 0009, guest PC 0x0c05d188 */
if(!s->budget--) { s->failed_pc=0x0c05d188u; return 0; }
goto P_0c05d18a;
P_0c05d18a: /* original 7f68, guest PC 0x0c05d18a */
if(!s->budget--) { s->failed_pc=0x0c05d18au; return 0; }
r[15]+=0x00000068u;
goto P_0c05d18c;
P_0c05d18c: /* original 4f26, guest PC 0x0c05d18c */
if(!s->budget--) { s->failed_pc=0x0c05d18cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05d18e;
P_0c05d18e: /* original fff9, guest PC 0x0c05d18e */
if(!s->budget--) { s->failed_pc=0x0c05d18eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c05d190;
P_0c05d190: /* original 68f6, guest PC 0x0c05d190 */
if(!s->budget--) { s->failed_pc=0x0c05d190u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c05d192;
P_0c05d192: /* original 69f6, guest PC 0x0c05d192 */
if(!s->budget--) { s->failed_pc=0x0c05d192u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05d194;
P_0c05d194: /* original 6af6, guest PC 0x0c05d194 */
if(!s->budget--) { s->failed_pc=0x0c05d194u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05d196;
P_0c05d196: /* original 6bf6, guest PC 0x0c05d196 */
if(!s->budget--) { s->failed_pc=0x0c05d196u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05d198;
P_0c05d198: /* original 6cf6, guest PC 0x0c05d198 */
if(!s->budget--) { s->failed_pc=0x0c05d198u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05d19a;
P_0c05d19a: /* original 6df6, guest PC 0x0c05d19a */
if(!s->budget--) { s->failed_pc=0x0c05d19au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05d19c;
P_0c05d19c: /* original 000b, guest PC 0x0c05d19c */
if(!s->budget--) { s->failed_pc=0x0c05d19cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05d19e: /* original 6ef6, guest PC 0x0c05d19e */
if(!s->budget--) { s->failed_pc=0x0c05d19eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05d1a0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05d1a0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
