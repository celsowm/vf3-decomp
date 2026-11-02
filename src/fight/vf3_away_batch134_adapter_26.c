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
int vf3_away_batch134_adapter_26(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0caa9cu: goto P_0c0caa9c;
case 0x0c0caa9eu: goto P_0c0caa9e;
case 0x0c0caaa0u: goto P_0c0caaa0;
case 0x0c0caaa2u: goto P_0c0caaa2;
case 0x0c0caaa4u: goto P_0c0caaa4;
case 0x0c0caaa6u: goto P_0c0caaa6;
case 0x0c0caaa8u: goto P_0c0caaa8;
case 0x0c0caaaau: goto P_0c0caaaa;
case 0x0c0caaacu: goto P_0c0caaac;
case 0x0c0caaaeu: goto P_0c0caaae;
case 0x0c0caab0u: goto P_0c0caab0;
case 0x0c0caab2u: goto P_0c0caab2;
case 0x0c0caab4u: goto P_0c0caab4;
case 0x0c0caab6u: goto P_0c0caab6;
case 0x0c0caab8u: goto P_0c0caab8;
case 0x0c0caabau: goto P_0c0caaba;
case 0x0c0caabcu: goto P_0c0caabc;
case 0x0c0caabeu: goto P_0c0caabe;
case 0x0c0caac0u: goto P_0c0caac0;
case 0x0c0caac2u: goto P_0c0caac2;
case 0x0c0caac4u: goto P_0c0caac4;
case 0x0c0caac6u: goto P_0c0caac6;
case 0x0c0caac8u: goto P_0c0caac8;
case 0x0c0caacau: goto P_0c0caaca;
case 0x0c0caaccu: goto P_0c0caacc;
case 0x0c0caaceu: goto P_0c0caace;
case 0x0c0caad0u: goto P_0c0caad0;
case 0x0c0caad2u: goto P_0c0caad2;
case 0x0c0caad4u: goto P_0c0caad4;
case 0x0c0caad6u: goto P_0c0caad6;
case 0x0c0caad8u: goto P_0c0caad8;
case 0x0c0caadau: goto P_0c0caada;
case 0x0c0caadcu: goto P_0c0caadc;
case 0x0c0caadeu: goto P_0c0caade;
case 0x0c0caae0u: goto P_0c0caae0;
case 0x0c0caae2u: goto P_0c0caae2;
case 0x0c0caae4u: goto P_0c0caae4;
case 0x0c0caae6u: goto P_0c0caae6;
case 0x0c0caae8u: goto P_0c0caae8;
case 0x0c0caaeau: goto P_0c0caaea;
case 0x0c0caaecu: goto P_0c0caaec;
case 0x0c0caaeeu: goto P_0c0caaee;
case 0x0c0caaf0u: goto P_0c0caaf0;
case 0x0c0caaf2u: goto P_0c0caaf2;
case 0x0c0caaf4u: goto P_0c0caaf4;
case 0x0c0caaf6u: goto P_0c0caaf6;
case 0x0c0caaf8u: goto P_0c0caaf8;
case 0x0c0caafau: goto P_0c0caafa;
case 0x0c0caafcu: goto P_0c0caafc;
case 0x0c0caafeu: goto P_0c0caafe;
case 0x0c0cab00u: goto P_0c0cab00;
case 0x0c0cab02u: goto P_0c0cab02;
case 0x0c0cab04u: goto P_0c0cab04;
case 0x0c0cab06u: goto P_0c0cab06;
case 0x0c0cab08u: goto P_0c0cab08;
case 0x0c0cab0au: goto P_0c0cab0a;
case 0x0c0cab0cu: goto P_0c0cab0c;
case 0x0c0cab0eu: goto P_0c0cab0e;
case 0x0c0cab10u: goto P_0c0cab10;
case 0x0c0cab30u: goto P_0c0cab30;
case 0x0c0cab32u: goto P_0c0cab32;
case 0x0c0cab34u: goto P_0c0cab34;
case 0x0c0cab36u: goto P_0c0cab36;
case 0x0c0cab38u: goto P_0c0cab38;
case 0x0c0cab3au: goto P_0c0cab3a;
case 0x0c0cab3cu: goto P_0c0cab3c;
case 0x0c0cab3eu: goto P_0c0cab3e;
case 0x0c0cab40u: goto P_0c0cab40;
case 0x0c0cab42u: goto P_0c0cab42;
case 0x0c0cab44u: goto P_0c0cab44;
case 0x0c0cab46u: goto P_0c0cab46;
case 0x0c0cab48u: goto P_0c0cab48;
case 0x0c0cab4au: goto P_0c0cab4a;
case 0x0c0cab4cu: goto P_0c0cab4c;
case 0x0c0cab4eu: goto P_0c0cab4e;
case 0x0c0cab50u: goto P_0c0cab50;
case 0x0c0cab52u: goto P_0c0cab52;
case 0x0c0cab54u: goto P_0c0cab54;
case 0x0c0cab56u: goto P_0c0cab56;
case 0x0c0cab58u: goto P_0c0cab58;
case 0x0c0cab5au: goto P_0c0cab5a;
case 0x0c0cab5cu: goto P_0c0cab5c;
case 0x0c0cab5eu: goto P_0c0cab5e;
case 0x0c0cab60u: goto P_0c0cab60;
case 0x0c0cab62u: goto P_0c0cab62;
case 0x0c0cab64u: goto P_0c0cab64;
case 0x0c0cab66u: goto P_0c0cab66;
case 0x0c0cab68u: goto P_0c0cab68;
case 0x0c0cab6au: goto P_0c0cab6a;
case 0x0c0cab6cu: goto P_0c0cab6c;
case 0x0c0cab6eu: goto P_0c0cab6e;
case 0x0c0cab70u: goto P_0c0cab70;
case 0x0c0cab72u: goto P_0c0cab72;
case 0x0c0cab74u: goto P_0c0cab74;
case 0x0c0cab76u: goto P_0c0cab76;
case 0x0c0cab78u: goto P_0c0cab78;
case 0x0c0cab7au: goto P_0c0cab7a;
case 0x0c0cab7cu: goto P_0c0cab7c;
case 0x0c0cab7eu: goto P_0c0cab7e;
case 0x0c0cab80u: goto P_0c0cab80;
case 0x0c0cab82u: goto P_0c0cab82;
case 0x0c0cab84u: goto P_0c0cab84;
case 0x0c0cab86u: goto P_0c0cab86;
case 0x0c0cab88u: goto P_0c0cab88;
case 0x0c0cab8au: goto P_0c0cab8a;
case 0x0c0cab8cu: goto P_0c0cab8c;
case 0x0c0cab8eu: goto P_0c0cab8e;
case 0x0c0cab90u: goto P_0c0cab90;
case 0x0c0cab92u: goto P_0c0cab92;
case 0x0c0cab94u: goto P_0c0cab94;
case 0x0c0cab96u: goto P_0c0cab96;
case 0x0c0cab98u: goto P_0c0cab98;
case 0x0c0cab9au: goto P_0c0cab9a;
case 0x0c0cab9cu: goto P_0c0cab9c;
case 0x0c0cab9eu: goto P_0c0cab9e;
case 0x0c0caba0u: goto P_0c0caba0;
case 0x0c0caba2u: goto P_0c0caba2;
case 0x0c0caba4u: goto P_0c0caba4;
case 0x0c0caba6u: goto P_0c0caba6;
case 0x0c0caba8u: goto P_0c0caba8;
case 0x0c0cabaau: goto P_0c0cabaa;
case 0x0c0cabacu: goto P_0c0cabac;
case 0x0c0cabaeu: goto P_0c0cabae;
case 0x0c0cabb0u: goto P_0c0cabb0;
case 0x0c0cabb2u: goto P_0c0cabb2;
case 0x0c0cabb4u: goto P_0c0cabb4;
case 0x0c0cabb6u: goto P_0c0cabb6;
case 0x0c0cabb8u: goto P_0c0cabb8;
case 0x0c0cabbau: goto P_0c0cabba;
case 0x0c0cabbcu: goto P_0c0cabbc;
case 0x0c0cabbeu: goto P_0c0cabbe;
case 0x0c0cabc0u: goto P_0c0cabc0;
case 0x0c0cabc2u: goto P_0c0cabc2;
case 0x0c0cabc4u: goto P_0c0cabc4;
case 0x0c0cabc6u: goto P_0c0cabc6;
case 0x0c0cabc8u: goto P_0c0cabc8;
case 0x0c0cabcau: goto P_0c0cabca;
case 0x0c0cabccu: goto P_0c0cabcc;
case 0x0c0cabceu: goto P_0c0cabce;
case 0x0c0cabd0u: goto P_0c0cabd0;
case 0x0c0cabd2u: goto P_0c0cabd2;
case 0x0c0cabd4u: goto P_0c0cabd4;
case 0x0c0cabd6u: goto P_0c0cabd6;
case 0x0c0cabd8u: goto P_0c0cabd8;
case 0x0c0cabdau: goto P_0c0cabda;
case 0x0c0cabdcu: goto P_0c0cabdc;
case 0x0c0cabdeu: goto P_0c0cabde;
case 0x0c0cabe0u: goto P_0c0cabe0;
case 0x0c0cabe2u: goto P_0c0cabe2;
case 0x0c0cabe4u: goto P_0c0cabe4;
case 0x0c0cabe6u: goto P_0c0cabe6;
case 0x0c0cabe8u: goto P_0c0cabe8;
case 0x0c0cabeau: goto P_0c0cabea;
case 0x0c0cabecu: goto P_0c0cabec;
case 0x0c0cabeeu: goto P_0c0cabee;
case 0x0c0cabf0u: goto P_0c0cabf0;
case 0x0c0cabf2u: goto P_0c0cabf2;
case 0x0c0cabf4u: goto P_0c0cabf4;
case 0x0c0cabf6u: goto P_0c0cabf6;
case 0x0c0cabf8u: goto P_0c0cabf8;
case 0x0c0cabfau: goto P_0c0cabfa;
case 0x0c0cabfcu: goto P_0c0cabfc;
case 0x0c0cabfeu: goto P_0c0cabfe;
case 0x0c0cac00u: goto P_0c0cac00;
case 0x0c0cac02u: goto P_0c0cac02;
case 0x0c0cac04u: goto P_0c0cac04;
case 0x0c0cac06u: goto P_0c0cac06;
case 0x0c0cac08u: goto P_0c0cac08;
case 0x0c0cac0au: goto P_0c0cac0a;
case 0x0c0cac0cu: goto P_0c0cac0c;
case 0x0c0cac0eu: goto P_0c0cac0e;
case 0x0c0cac10u: goto P_0c0cac10;
case 0x0c0cac12u: goto P_0c0cac12;
case 0x0c0cac14u: goto P_0c0cac14;
case 0x0c0cac16u: goto P_0c0cac16;
case 0x0c0cac18u: goto P_0c0cac18;
case 0x0c0cac1au: goto P_0c0cac1a;
case 0x0c0cac1cu: goto P_0c0cac1c;
case 0x0c0cac1eu: goto P_0c0cac1e;
case 0x0c0cac20u: goto P_0c0cac20;
case 0x0c0cac22u: goto P_0c0cac22;
case 0x0c0cac24u: goto P_0c0cac24;
case 0x0c0cac26u: goto P_0c0cac26;
case 0x0c0cac28u: goto P_0c0cac28;
case 0x0c0cac2au: goto P_0c0cac2a;
case 0x0c0cac2cu: goto P_0c0cac2c;
case 0x0c0cac2eu: goto P_0c0cac2e;
case 0x0c0cac5cu: goto P_0c0cac5c;
case 0x0c0cac5eu: goto P_0c0cac5e;
case 0x0c0cac60u: goto P_0c0cac60;
case 0x0c0cac62u: goto P_0c0cac62;
case 0x0c0cac64u: goto P_0c0cac64;
case 0x0c0cac66u: goto P_0c0cac66;
case 0x0c0cac68u: goto P_0c0cac68;
case 0x0c0cac6au: goto P_0c0cac6a;
case 0x0c0cac6cu: goto P_0c0cac6c;
case 0x0c0cac6eu: goto P_0c0cac6e;
case 0x0c0cac70u: goto P_0c0cac70;
case 0x0c0cac72u: goto P_0c0cac72;
case 0x0c0cac74u: goto P_0c0cac74;
case 0x0c0cac76u: goto P_0c0cac76;
case 0x0c0cac78u: goto P_0c0cac78;
case 0x0c0cac7au: goto P_0c0cac7a;
case 0x0c0cac7cu: goto P_0c0cac7c;
case 0x0c0cac7eu: goto P_0c0cac7e;
case 0x0c0cac80u: goto P_0c0cac80;
case 0x0c0cac82u: goto P_0c0cac82;
case 0x0c0cac84u: goto P_0c0cac84;
case 0x0c0cac86u: goto P_0c0cac86;
case 0x0c0cac88u: goto P_0c0cac88;
case 0x0c0cac8au: goto P_0c0cac8a;
case 0x0c0cac8cu: goto P_0c0cac8c;
case 0x0c0cac8eu: goto P_0c0cac8e;
case 0x0c0cac90u: goto P_0c0cac90;
case 0x0c0cac92u: goto P_0c0cac92;
case 0x0c0cac94u: goto P_0c0cac94;
case 0x0c0cac96u: goto P_0c0cac96;
case 0x0c0cac98u: goto P_0c0cac98;
case 0x0c0cac9au: goto P_0c0cac9a;
case 0x0c0cac9cu: goto P_0c0cac9c;
case 0x0c0cac9eu: goto P_0c0cac9e;
case 0x0c0caca0u: goto P_0c0caca0;
case 0x0c0caca2u: goto P_0c0caca2;
case 0x0c0caca4u: goto P_0c0caca4;
case 0x0c0caca6u: goto P_0c0caca6;
case 0x0c0caca8u: goto P_0c0caca8;
case 0x0c0cacaau: goto P_0c0cacaa;
case 0x0c0cacacu: goto P_0c0cacac;
case 0x0c0cacaeu: goto P_0c0cacae;
case 0x0c0cacb0u: goto P_0c0cacb0;
case 0x0c0cacb2u: goto P_0c0cacb2;
case 0x0c0cacb4u: goto P_0c0cacb4;
case 0x0c0cacb6u: goto P_0c0cacb6;
case 0x0c0cacb8u: goto P_0c0cacb8;
case 0x0c0cacbau: goto P_0c0cacba;
case 0x0c0cacbcu: goto P_0c0cacbc;
case 0x0c0cacbeu: goto P_0c0cacbe;
case 0x0c0cacc0u: goto P_0c0cacc0;
case 0x0c0cacc2u: goto P_0c0cacc2;
case 0x0c0cacc4u: goto P_0c0cacc4;
case 0x0c0cacc6u: goto P_0c0cacc6;
case 0x0c0cacc8u: goto P_0c0cacc8;
case 0x0c0caccau: goto P_0c0cacca;
case 0x0c0cacccu: goto P_0c0caccc;
case 0x0c0cacceu: goto P_0c0cacce;
case 0x0c0cacd0u: goto P_0c0cacd0;
case 0x0c0cacd2u: goto P_0c0cacd2;
case 0x0c0cacd4u: goto P_0c0cacd4;
case 0x0c0cacd6u: goto P_0c0cacd6;
case 0x0c0cacd8u: goto P_0c0cacd8;
case 0x0c0cacdau: goto P_0c0cacda;
case 0x0c0cacdcu: goto P_0c0cacdc;
case 0x0c0cacdeu: goto P_0c0cacde;
case 0x0c0cace0u: goto P_0c0cace0;
case 0x0c0cace2u: goto P_0c0cace2;
case 0x0c0cace4u: goto P_0c0cace4;
case 0x0c0cace6u: goto P_0c0cace6;
case 0x0c0cace8u: goto P_0c0cace8;
case 0x0c0caceau: goto P_0c0cacea;
case 0x0c0cacecu: goto P_0c0cacec;
case 0x0c0caceeu: goto P_0c0cacee;
case 0x0c0cad04u: goto P_0c0cad04;
case 0x0c0cad06u: goto P_0c0cad06;
case 0x0c0cad08u: goto P_0c0cad08;
case 0x0c0cad0au: goto P_0c0cad0a;
case 0x0c0cad0cu: goto P_0c0cad0c;
case 0x0c0cad0eu: goto P_0c0cad0e;
case 0x0c0cad10u: goto P_0c0cad10;
case 0x0c0cad12u: goto P_0c0cad12;
case 0x0c0cad14u: goto P_0c0cad14;
case 0x0c0cad16u: goto P_0c0cad16;
case 0x0c0cad18u: goto P_0c0cad18;
case 0x0c0cad1au: goto P_0c0cad1a;
case 0x0c0cad1cu: goto P_0c0cad1c;
case 0x0c0cad1eu: goto P_0c0cad1e;
case 0x0c0cad20u: goto P_0c0cad20;
case 0x0c0cad22u: goto P_0c0cad22;
case 0x0c0cad24u: goto P_0c0cad24;
case 0x0c0cad26u: goto P_0c0cad26;
case 0x0c0cad28u: goto P_0c0cad28;
case 0x0c0cad2au: goto P_0c0cad2a;
case 0x0c0cad2cu: goto P_0c0cad2c;
case 0x0c0cad2eu: goto P_0c0cad2e;
case 0x0c0cad30u: goto P_0c0cad30;
case 0x0c0cad32u: goto P_0c0cad32;
case 0x0c0cad34u: goto P_0c0cad34;
case 0x0c0cad36u: goto P_0c0cad36;
case 0x0c0cad38u: goto P_0c0cad38;
case 0x0c0cad3au: goto P_0c0cad3a;
case 0x0c0cad3cu: goto P_0c0cad3c;
case 0x0c0cad3eu: goto P_0c0cad3e;
case 0x0c0cad40u: goto P_0c0cad40;
case 0x0c0cad42u: goto P_0c0cad42;
case 0x0c0cad44u: goto P_0c0cad44;
case 0x0c0cad46u: goto P_0c0cad46;
case 0x0c0cad48u: goto P_0c0cad48;
case 0x0c0cad4au: goto P_0c0cad4a;
case 0x0c0cad4cu: goto P_0c0cad4c;
case 0x0c0cad4eu: goto P_0c0cad4e;
case 0x0c0cad50u: goto P_0c0cad50;
case 0x0c0cad52u: goto P_0c0cad52;
case 0x0c0cad54u: goto P_0c0cad54;
case 0x0c0cad56u: goto P_0c0cad56;
case 0x0c0cad58u: goto P_0c0cad58;
case 0x0c0cad5au: goto P_0c0cad5a;
case 0x0c0cad5cu: goto P_0c0cad5c;
case 0x0c0cad5eu: goto P_0c0cad5e;
case 0x0c0cad60u: goto P_0c0cad60;
case 0x0c0cad62u: goto P_0c0cad62;
case 0x0c0cad64u: goto P_0c0cad64;
case 0x0c0cad66u: goto P_0c0cad66;
case 0x0c0cad68u: goto P_0c0cad68;
case 0x0c0cad6au: goto P_0c0cad6a;
case 0x0c0cad6cu: goto P_0c0cad6c;
case 0x0c0cad6eu: goto P_0c0cad6e;
case 0x0c0cad70u: goto P_0c0cad70;
case 0x0c0cad72u: goto P_0c0cad72;
case 0x0c0cad74u: goto P_0c0cad74;
case 0x0c0cad76u: goto P_0c0cad76;
case 0x0c0cad78u: goto P_0c0cad78;
case 0x0c0cad7au: goto P_0c0cad7a;
case 0x0c0cad7cu: goto P_0c0cad7c;
case 0x0c0cad7eu: goto P_0c0cad7e;
case 0x0c0cad80u: goto P_0c0cad80;
case 0x0c0cad82u: goto P_0c0cad82;
case 0x0c0cad84u: goto P_0c0cad84;
case 0x0c0cad86u: goto P_0c0cad86;
case 0x0c0cad88u: goto P_0c0cad88;
case 0x0c0cad8au: goto P_0c0cad8a;
case 0x0c0cad8cu: goto P_0c0cad8c;
case 0x0c0cad8eu: goto P_0c0cad8e;
case 0x0c0cad90u: goto P_0c0cad90;
case 0x0c0cad92u: goto P_0c0cad92;
case 0x0c0cad94u: goto P_0c0cad94;
case 0x0c0cad96u: goto P_0c0cad96;
case 0x0c0cad98u: goto P_0c0cad98;
case 0x0c0cad9au: goto P_0c0cad9a;
case 0x0c0cad9cu: goto P_0c0cad9c;
case 0x0c0cad9eu: goto P_0c0cad9e;
case 0x0c0cada0u: goto P_0c0cada0;
case 0x0c0cada2u: goto P_0c0cada2;
case 0x0c0cada4u: goto P_0c0cada4;
case 0x0c0cada6u: goto P_0c0cada6;
case 0x0c0cada8u: goto P_0c0cada8;
case 0x0c0cadaau: goto P_0c0cadaa;
case 0x0c0cadacu: goto P_0c0cadac;
case 0x0c0cadaeu: goto P_0c0cadae;
case 0x0c0cadb0u: goto P_0c0cadb0;
case 0x0c0cadb2u: goto P_0c0cadb2;
case 0x0c0cadb4u: goto P_0c0cadb4;
case 0x0c0cadb6u: goto P_0c0cadb6;
case 0x0c0cadb8u: goto P_0c0cadb8;
case 0x0c0cadbau: goto P_0c0cadba;
case 0x0c0cadbcu: goto P_0c0cadbc;
case 0x0c0cadbeu: goto P_0c0cadbe;
case 0x0c0cadc0u: goto P_0c0cadc0;
case 0x0c0cadc2u: goto P_0c0cadc2;
case 0x0c0cade0u: goto P_0c0cade0;
case 0x0c0cade2u: goto P_0c0cade2;
case 0x0c0cade4u: goto P_0c0cade4;
case 0x0c0cade6u: goto P_0c0cade6;
case 0x0c0cade8u: goto P_0c0cade8;
case 0x0c0cadeau: goto P_0c0cadea;
case 0x0c0cadecu: goto P_0c0cadec;
case 0x0c0cadeeu: goto P_0c0cadee;
case 0x0c0cadf0u: goto P_0c0cadf0;
case 0x0c0cadf2u: goto P_0c0cadf2;
case 0x0c0cadf4u: goto P_0c0cadf4;
case 0x0c0cadf6u: goto P_0c0cadf6;
case 0x0c0cadf8u: goto P_0c0cadf8;
case 0x0c0cadfau: goto P_0c0cadfa;
case 0x0c0cadfcu: goto P_0c0cadfc;
case 0x0c0cadfeu: goto P_0c0cadfe;
case 0x0c0cae00u: goto P_0c0cae00;
case 0x0c0cae02u: goto P_0c0cae02;
case 0x0c0cae04u: goto P_0c0cae04;
case 0x0c0cae06u: goto P_0c0cae06;
case 0x0c0cae08u: goto P_0c0cae08;
case 0x0c0cae0au: goto P_0c0cae0a;
case 0x0c0cae0cu: goto P_0c0cae0c;
case 0x0c0cae0eu: goto P_0c0cae0e;
case 0x0c0cae10u: goto P_0c0cae10;
case 0x0c0cae12u: goto P_0c0cae12;
case 0x0c0cae14u: goto P_0c0cae14;
case 0x0c0cae16u: goto P_0c0cae16;
case 0x0c0cae18u: goto P_0c0cae18;
case 0x0c0cae1au: goto P_0c0cae1a;
case 0x0c0cae1cu: goto P_0c0cae1c;
case 0x0c0cae1eu: goto P_0c0cae1e;
case 0x0c0cae20u: goto P_0c0cae20;
case 0x0c0cae22u: goto P_0c0cae22;
case 0x0c0cae24u: goto P_0c0cae24;
case 0x0c0cae26u: goto P_0c0cae26;
case 0x0c0cae28u: goto P_0c0cae28;
case 0x0c0cae2au: goto P_0c0cae2a;
case 0x0c0cae2cu: goto P_0c0cae2c;
case 0x0c0cae2eu: goto P_0c0cae2e;
case 0x0c0cae30u: goto P_0c0cae30;
case 0x0c0cae32u: goto P_0c0cae32;
case 0x0c0cae34u: goto P_0c0cae34;
case 0x0c0cae36u: goto P_0c0cae36;
case 0x0c0cae38u: goto P_0c0cae38;
case 0x0c0cae3au: goto P_0c0cae3a;
case 0x0c0cae3cu: goto P_0c0cae3c;
case 0x0c0cae3eu: goto P_0c0cae3e;
case 0x0c0cae40u: goto P_0c0cae40;
case 0x0c0cae42u: goto P_0c0cae42;
case 0x0c0cae44u: goto P_0c0cae44;
case 0x0c0cae46u: goto P_0c0cae46;
case 0x0c0cae48u: goto P_0c0cae48;
case 0x0c0cae4au: goto P_0c0cae4a;
case 0x0c0cae4cu: goto P_0c0cae4c;
case 0x0c0cae4eu: goto P_0c0cae4e;
case 0x0c0cae50u: goto P_0c0cae50;
case 0x0c0cae52u: goto P_0c0cae52;
case 0x0c0cae54u: goto P_0c0cae54;
case 0x0c0cae56u: goto P_0c0cae56;
case 0x0c0cae58u: goto P_0c0cae58;
case 0x0c0cae5au: goto P_0c0cae5a;
case 0x0c0cae5cu: goto P_0c0cae5c;
case 0x0c0cae5eu: goto P_0c0cae5e;
case 0x0c0cae60u: goto P_0c0cae60;
case 0x0c0cae62u: goto P_0c0cae62;
case 0x0c0cae64u: goto P_0c0cae64;
case 0x0c0cae66u: goto P_0c0cae66;
case 0x0c0cae68u: goto P_0c0cae68;
case 0x0c0cae6au: goto P_0c0cae6a;
case 0x0c0cae6cu: goto P_0c0cae6c;
case 0x0c0cae6eu: goto P_0c0cae6e;
case 0x0c0cae70u: goto P_0c0cae70;
case 0x0c0cae72u: goto P_0c0cae72;
case 0x0c0cae74u: goto P_0c0cae74;
case 0x0c0cae76u: goto P_0c0cae76;
case 0x0c0cae78u: goto P_0c0cae78;
case 0x0c0cae7au: goto P_0c0cae7a;
case 0x0c0cae7cu: goto P_0c0cae7c;
case 0x0c0cae7eu: goto P_0c0cae7e;
case 0x0c0cae80u: goto P_0c0cae80;
case 0x0c0cae82u: goto P_0c0cae82;
case 0x0c0cae84u: goto P_0c0cae84;
case 0x0c0cae86u: goto P_0c0cae86;
case 0x0c0cae88u: goto P_0c0cae88;
case 0x0c0cae8au: goto P_0c0cae8a;
case 0x0c0cae8cu: goto P_0c0cae8c;
case 0x0c0cae8eu: goto P_0c0cae8e;
case 0x0c0cae90u: goto P_0c0cae90;
case 0x0c0cae92u: goto P_0c0cae92;
case 0x0c0cae94u: goto P_0c0cae94;
case 0x0c0cae96u: goto P_0c0cae96;
case 0x0c0cae98u: goto P_0c0cae98;
case 0x0c0cae9au: goto P_0c0cae9a;
case 0x0c0cae9cu: goto P_0c0cae9c;
case 0x0c0cae9eu: goto P_0c0cae9e;
case 0x0c0caea0u: goto P_0c0caea0;
case 0x0c0caea2u: goto P_0c0caea2;
case 0x0c0caea4u: goto P_0c0caea4;
case 0x0c0caea6u: goto P_0c0caea6;
case 0x0c0caea8u: goto P_0c0caea8;
case 0x0c0caeaau: goto P_0c0caeaa;
case 0x0c0caeacu: goto P_0c0caeac;
case 0x0c0caeaeu: goto P_0c0caeae;
case 0x0c0caeb0u: goto P_0c0caeb0;
case 0x0c0caeb2u: goto P_0c0caeb2;
case 0x0c0caeb4u: goto P_0c0caeb4;
case 0x0c0caeb6u: goto P_0c0caeb6;
case 0x0c0caeb8u: goto P_0c0caeb8;
case 0x0c0caebau: goto P_0c0caeba;
case 0x0c0caebcu: goto P_0c0caebc;
case 0x0c0caebeu: goto P_0c0caebe;
case 0x0c0caec0u: goto P_0c0caec0;
case 0x0c0caec2u: goto P_0c0caec2;
case 0x0c0caec4u: goto P_0c0caec4;
case 0x0c0caec6u: goto P_0c0caec6;
case 0x0c0caec8u: goto P_0c0caec8;
case 0x0c0caecau: goto P_0c0caeca;
case 0x0c0caeccu: goto P_0c0caecc;
case 0x0c0caeceu: goto P_0c0caece;
case 0x0c0caed0u: goto P_0c0caed0;
case 0x0c0caed2u: goto P_0c0caed2;
case 0x0c0caed4u: goto P_0c0caed4;
case 0x0c0caed6u: goto P_0c0caed6;
case 0x0c0caed8u: goto P_0c0caed8;
case 0x0c0caedau: goto P_0c0caeda;
case 0x0c0caedcu: goto P_0c0caedc;
case 0x0c0caedeu: goto P_0c0caede;
case 0x0c0caee0u: goto P_0c0caee0;
case 0x0c0caee2u: goto P_0c0caee2;
case 0x0c0caee4u: goto P_0c0caee4;
case 0x0c0caee6u: goto P_0c0caee6;
case 0x0c0caee8u: goto P_0c0caee8;
case 0x0c0caeeau: goto P_0c0caeea;
case 0x0c0caeecu: goto P_0c0caeec;
case 0x0c0caeeeu: goto P_0c0caeee;
case 0x0c0caef0u: goto P_0c0caef0;
case 0x0c0caef2u: goto P_0c0caef2;
case 0x0c0caf18u: goto P_0c0caf18;
case 0x0c0caf1au: goto P_0c0caf1a;
case 0x0c0caf1cu: goto P_0c0caf1c;
case 0x0c0caf1eu: goto P_0c0caf1e;
case 0x0c0caf20u: goto P_0c0caf20;
case 0x0c0caf22u: goto P_0c0caf22;
case 0x0c0caf24u: goto P_0c0caf24;
case 0x0c0caf26u: goto P_0c0caf26;
case 0x0c0caf28u: goto P_0c0caf28;
case 0x0c0caf2au: goto P_0c0caf2a;
case 0x0c0caf2cu: goto P_0c0caf2c;
case 0x0c0caf2eu: goto P_0c0caf2e;
case 0x0c0caf30u: goto P_0c0caf30;
case 0x0c0caf32u: goto P_0c0caf32;
case 0x0c0caf34u: goto P_0c0caf34;
case 0x0c0caf36u: goto P_0c0caf36;
case 0x0c0caf38u: goto P_0c0caf38;
case 0x0c0caf3au: goto P_0c0caf3a;
case 0x0c0caf3cu: goto P_0c0caf3c;
case 0x0c0caf3eu: goto P_0c0caf3e;
case 0x0c0caf40u: goto P_0c0caf40;
case 0x0c0caf42u: goto P_0c0caf42;
case 0x0c0caf44u: goto P_0c0caf44;
case 0x0c0caf46u: goto P_0c0caf46;
case 0x0c0caf48u: goto P_0c0caf48;
case 0x0c0caf4au: goto P_0c0caf4a;
case 0x0c0caf4cu: goto P_0c0caf4c;
case 0x0c0caf4eu: goto P_0c0caf4e;
case 0x0c0caf50u: goto P_0c0caf50;
case 0x0c0caf52u: goto P_0c0caf52;
case 0x0c0caf54u: goto P_0c0caf54;
case 0x0c0caf56u: goto P_0c0caf56;
case 0x0c0caf58u: goto P_0c0caf58;
case 0x0c0caf5au: goto P_0c0caf5a;
case 0x0c0caf5cu: goto P_0c0caf5c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0caa9c: /* original 903d, guest PC 0x0c0caa9c */
if(!s->budget--) { s->failed_pc=0x0c0caa9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cab1au,2);
goto P_0c0caa9e;
P_0c0caa9e: /* original e340, guest PC 0x0c0caa9e */
if(!s->budget--) { s->failed_pc=0x0c0caa9eu; return 0; }
r[3]=0x00000040u;
goto P_0c0caaa0;
P_0c0caaa0: /* original 054c, guest PC 0x0c0caaa0 */
if(!s->budget--) { s->failed_pc=0x0c0caaa0u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0caaa2;
P_0c0caaa2: /* original 655c, guest PC 0x0c0caaa2 */
if(!s->budget--) { s->failed_pc=0x0c0caaa2u; return 0; }
r[5]=r[5]&255u;
goto P_0c0caaa4;
P_0c0caaa4: /* original 2358, guest PC 0x0c0caaa4 */
if(!s->budget--) { s->failed_pc=0x0c0caaa4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0caaa6;
P_0c0caaa6: /* original 8922, guest PC 0x0c0caaa6 */
if(!s->budget--) { s->failed_pc=0x0c0caaa6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caaee; }
goto P_0c0caaa8;
P_0c0caaa8: /* original 9038, guest PC 0x0c0caaa8 */
if(!s->budget--) { s->failed_pc=0x0c0caaa8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cab1cu,2);
goto P_0c0caaaa;
P_0c0caaaa: /* original f646, guest PC 0x0c0caaaa */
if(!s->budget--) { s->failed_pc=0x0c0caaaau; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c0caaac;
P_0c0caaac: /* original 700c, guest PC 0x0c0caaac */
if(!s->budget--) { s->failed_pc=0x0c0caaacu; return 0; }
r[0]+=0x0000000cu;
goto P_0c0caaae;
P_0c0caaae: /* original f746, guest PC 0x0c0caaae */
if(!s->budget--) { s->failed_pc=0x0c0caaaeu; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c0caab0;
P_0c0caab0: /* original 70dc, guest PC 0x0c0caab0 */
if(!s->budget--) { s->failed_pc=0x0c0caab0u; return 0; }
r[0]+=0xffffffdcu;
goto P_0c0caab2;
P_0c0caab2: /* original f846, guest PC 0x0c0caab2 */
if(!s->budget--) { s->failed_pc=0x0c0caab2u; return 0; }
vf3_matrix_load(s,ram,8,r[4]+r[0]);
goto P_0c0caab4;
P_0c0caab4: /* original 700c, guest PC 0x0c0caab4 */
if(!s->budget--) { s->failed_pc=0x0c0caab4u; return 0; }
r[0]+=0x0000000cu;
goto P_0c0caab6;
P_0c0caab6: /* original f946, guest PC 0x0c0caab6 */
if(!s->budget--) { s->failed_pc=0x0c0caab6u; return 0; }
vf3_matrix_load(s,ram,9,r[4]+r[0]);
goto P_0c0caab8;
P_0c0caab8: /* original c719, guest PC 0x0c0caab8 */
if(!s->budget--) { s->failed_pc=0x0c0caab8u; return 0; }
r[0]=code_base|0x000cab20u;
goto P_0c0caaba;
P_0c0caaba: /* original f508, guest PC 0x0c0caaba */
if(!s->budget--) { s->failed_pc=0x0c0caabau; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0caabc;
P_0c0caabc: /* original c719, guest PC 0x0c0caabc */
if(!s->budget--) { s->failed_pc=0x0c0caabcu; return 0; }
r[0]=code_base|0x000cab24u;
goto P_0c0caabe;
P_0c0caabe: /* original f655, guest PC 0x0c0caabe */
if(!s->budget--) { s->failed_pc=0x0c0caabeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[5]))!=0);
goto P_0c0caac0;
P_0c0caac0: /* original 8d0e, guest PC 0x0c0caac0 */
if(!s->budget--) { s->failed_pc=0x0c0caac0u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[0]);
if(cond) { goto P_0c0caae0; }
goto P_0c0caac4;
P_0c0caac2: /* original f408, guest PC 0x0c0caac2 */
if(!s->budget--) { s->failed_pc=0x0c0caac2u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0caac4;
P_0c0caac4: /* original f465, guest PC 0x0c0caac4 */
if(!s->budget--) { s->failed_pc=0x0c0caac4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c0caac6;
P_0c0caac6: /* original 890b, guest PC 0x0c0caac6 */
if(!s->budget--) { s->failed_pc=0x0c0caac6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caae0; }
goto P_0c0caac8;
P_0c0caac8: /* original f755, guest PC 0x0c0caac8 */
if(!s->budget--) { s->failed_pc=0x0c0caac8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[5]))!=0);
goto P_0c0caaca;
P_0c0caaca: /* original 8909, guest PC 0x0c0caaca */
if(!s->budget--) { s->failed_pc=0x0c0caacau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caae0; }
goto P_0c0caacc;
P_0c0caacc: /* original f475, guest PC 0x0c0caacc */
if(!s->budget--) { s->failed_pc=0x0c0caaccu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[7]))!=0);
goto P_0c0caace;
P_0c0caace: /* original 8907, guest PC 0x0c0caace */
if(!s->budget--) { s->failed_pc=0x0c0caaceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caae0; }
goto P_0c0caad0;
P_0c0caad0: /* original f855, guest PC 0x0c0caad0 */
if(!s->budget--) { s->failed_pc=0x0c0caad0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[5]))!=0);
goto P_0c0caad2;
P_0c0caad2: /* original 8905, guest PC 0x0c0caad2 */
if(!s->budget--) { s->failed_pc=0x0c0caad2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caae0; }
goto P_0c0caad4;
P_0c0caad4: /* original f485, guest PC 0x0c0caad4 */
if(!s->budget--) { s->failed_pc=0x0c0caad4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[8]))!=0);
goto P_0c0caad6;
P_0c0caad6: /* original 8903, guest PC 0x0c0caad6 */
if(!s->budget--) { s->failed_pc=0x0c0caad6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caae0; }
goto P_0c0caad8;
P_0c0caad8: /* original f955, guest PC 0x0c0caad8 */
if(!s->budget--) { s->failed_pc=0x0c0caad8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[5]))!=0);
goto P_0c0caada;
P_0c0caada: /* original 8901, guest PC 0x0c0caada */
if(!s->budget--) { s->failed_pc=0x0c0caadau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caae0; }
goto P_0c0caadc;
P_0c0caadc: /* original f495, guest PC 0x0c0caadc */
if(!s->budget--) { s->failed_pc=0x0c0caadcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[9]))!=0);
goto P_0c0caade;
P_0c0caade: /* original 8b02, guest PC 0x0c0caade */
if(!s->budget--) { s->failed_pc=0x0c0caadeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0caae6; }
goto P_0c0caae0;
P_0c0caae0: /* original e310, guest PC 0x0c0caae0 */
if(!s->budget--) { s->failed_pc=0x0c0caae0u; return 0; }
r[3]=0x00000010u;
goto P_0c0caae2;
P_0c0caae2: /* original a002, guest PC 0x0c0caae2 */
if(!s->budget--) { s->failed_pc=0x0c0caae2u; return 0; }
r[5]|=r[3];
goto P_0c0caaea;
P_0c0caae4: /* original 253b, guest PC 0x0c0caae4 */
if(!s->budget--) { s->failed_pc=0x0c0caae4u; return 0; }
r[5]|=r[3];
goto P_0c0caae6;
P_0c0caae6: /* original e1ef, guest PC 0x0c0caae6 */
if(!s->budget--) { s->failed_pc=0x0c0caae6u; return 0; }
r[1]=0xffffffefu;
goto P_0c0caae8;
P_0c0caae8: /* original 2519, guest PC 0x0c0caae8 */
if(!s->budget--) { s->failed_pc=0x0c0caae8u; return 0; }
r[5]&=r[1];
goto P_0c0caaea;
P_0c0caaea: /* original 9016, guest PC 0x0c0caaea */
if(!s->budget--) { s->failed_pc=0x0c0caaeau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cab1au,2);
goto P_0c0caaec;
P_0c0caaec: /* original 0454, guest PC 0x0c0caaec */
if(!s->budget--) { s->failed_pc=0x0c0caaecu; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0caaee;
P_0c0caaee: /* original 000b, guest PC 0x0c0caaee */
if(!s->budget--) { s->failed_pc=0x0c0caaeeu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0caaf0: /* original 0009, guest PC 0x0c0caaf0 */
if(!s->budget--) { s->failed_pc=0x0c0caaf0u; return 0; }
goto P_0c0caaf2;
P_0c0caaf2: /* original 4f22, guest PC 0x0c0caaf2 */
if(!s->budget--) { s->failed_pc=0x0c0caaf2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0caaf4;
P_0c0caaf4: /* original 7ffc, guest PC 0x0c0caaf4 */
if(!s->budget--) { s->failed_pc=0x0c0caaf4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0caaf6;
P_0c0caaf6: /* original 2f52, guest PC 0x0c0caaf6 */
if(!s->budget--) { s->failed_pc=0x0c0caaf6u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0caaf8;
P_0c0caaf8: /* original d10c, guest PC 0x0c0caaf8 */
if(!s->budget--) { s->failed_pc=0x0c0caaf8u; return 0; }
r[1]=read(ram,0x0c0cab2cu,4);
goto P_0c0caafa;
P_0c0caafa: /* original d30b, guest PC 0x0c0caafa */
if(!s->budget--) { s->failed_pc=0x0c0caafau; return 0; }
r[3]=read(ram,0x0c0cab28u,4);
goto P_0c0caafc;
P_0c0caafc: /* original 6212, guest PC 0x0c0caafc */
if(!s->budget--) { s->failed_pc=0x0c0caafcu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0caafe;
P_0c0caafe: /* original 2238, guest PC 0x0c0caafe */
if(!s->budget--) { s->failed_pc=0x0c0caafeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cab00;
P_0c0cab00: /* original 8b03, guest PC 0x0c0cab00 */
if(!s->budget--) { s->failed_pc=0x0c0cab00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cab0a; }
goto P_0c0cab02;
P_0c0cab02: /* original b015, guest PC 0x0c0cab02 */
if(!s->budget--) { s->failed_pc=0x0c0cab02u; return 0; }
target=code_base|0x0c0cab30u; r[16]=code_base|0x0c0cab06u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cab06u) { target=s->pc; goto dispatch; }
goto P_0c0cab06;
P_0c0cab04: /* original 0009, guest PC 0x0c0cab04 */
if(!s->budget--) { s->failed_pc=0x0c0cab04u; return 0; }
goto P_0c0cab06;
P_0c0cab06: /* original b013, guest PC 0x0c0cab06 */
if(!s->budget--) { s->failed_pc=0x0c0cab06u; return 0; }
target=code_base|0x0c0cab30u; r[16]=code_base|0x0c0cab0au;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cab0au) { target=s->pc; goto dispatch; }
goto P_0c0cab0a;
P_0c0cab08: /* original 64f2, guest PC 0x0c0cab08 */
if(!s->budget--) { s->failed_pc=0x0c0cab08u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0cab0a;
P_0c0cab0a: /* original 7f04, guest PC 0x0c0cab0a */
if(!s->budget--) { s->failed_pc=0x0c0cab0au; return 0; }
r[15]+=0x00000004u;
goto P_0c0cab0c;
P_0c0cab0c: /* original 4f26, guest PC 0x0c0cab0c */
if(!s->budget--) { s->failed_pc=0x0c0cab0cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cab0e;
P_0c0cab0e: /* original 000b, guest PC 0x0c0cab0e */
if(!s->budget--) { s->failed_pc=0x0c0cab0eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0cab10: /* original 0009, guest PC 0x0c0cab10 */
if(!s->budget--) { s->failed_pc=0x0c0cab10u; return 0; }
if(!vf3_matrix_family(0x0c0cab12u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0cab12u; return 0; } return 1;
P_0c0cab30: /* original 2fe6, guest PC 0x0c0cab30 */
if(!s->budget--) { s->failed_pc=0x0c0cab30u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cab32;
P_0c0cab32: /* original 6e43, guest PC 0x0c0cab32 */
if(!s->budget--) { s->failed_pc=0x0c0cab32u; return 0; }
r[14]=r[4];
goto P_0c0cab34;
P_0c0cab34: /* original 2fd6, guest PC 0x0c0cab34 */
if(!s->budget--) { s->failed_pc=0x0c0cab34u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cab36;
P_0c0cab36: /* original 2fc6, guest PC 0x0c0cab36 */
if(!s->budget--) { s->failed_pc=0x0c0cab36u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cab38;
P_0c0cab38: /* original 2fb6, guest PC 0x0c0cab38 */
if(!s->budget--) { s->failed_pc=0x0c0cab38u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cab3a;
P_0c0cab3a: /* original 2fa6, guest PC 0x0c0cab3a */
if(!s->budget--) { s->failed_pc=0x0c0cab3au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cab3c;
P_0c0cab3c: /* original 2f96, guest PC 0x0c0cab3c */
if(!s->budget--) { s->failed_pc=0x0c0cab3cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cab3e;
P_0c0cab3e: /* original 2f86, guest PC 0x0c0cab3e */
if(!s->budget--) { s->failed_pc=0x0c0cab3eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cab40;
P_0c0cab40: /* original fffb, guest PC 0x0c0cab40 */
if(!s->budget--) { s->failed_pc=0x0c0cab40u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0cab42;
P_0c0cab42: /* original ffeb, guest PC 0x0c0cab42 */
if(!s->budget--) { s->failed_pc=0x0c0cab42u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0cab44;
P_0c0cab44: /* original ffdb, guest PC 0x0c0cab44 */
if(!s->budget--) { s->failed_pc=0x0c0cab44u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0cab46;
P_0c0cab46: /* original 4f22, guest PC 0x0c0cab46 */
if(!s->budget--) { s->failed_pc=0x0c0cab46u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cab48;
P_0c0cab48: /* original d33c, guest PC 0x0c0cab48 */
if(!s->budget--) { s->failed_pc=0x0c0cab48u; return 0; }
r[3]=read(ram,0x0c0cac3cu,4);
goto P_0c0cab4a;
P_0c0cab4a: /* original 7fc4, guest PC 0x0c0cab4a */
if(!s->budget--) { s->failed_pc=0x0c0cab4au; return 0; }
r[15]+=0xffffffc4u;
goto P_0c0cab4c;
P_0c0cab4c: /* original 1f37, guest PC 0x0c0cab4c */
if(!s->budget--) { s->failed_pc=0x0c0cab4cu; return 0; }
write(ram,r[15]+28,r[3],4);
goto P_0c0cab4e;
P_0c0cab4e: /* original d23c, guest PC 0x0c0cab4e */
if(!s->budget--) { s->failed_pc=0x0c0cab4eu; return 0; }
r[2]=read(ram,0x0c0cac40u,4);
goto P_0c0cab50;
P_0c0cab50: /* original 1f28, guest PC 0x0c0cab50 */
if(!s->budget--) { s->failed_pc=0x0c0cab50u; return 0; }
write(ram,r[15]+32,r[2],4);
goto P_0c0cab52;
P_0c0cab52: /* original bdb8, guest PC 0x0c0cab52 */
if(!s->budget--) { s->failed_pc=0x0c0cab52u; return 0; }
target=code_base|0x0c0ca6c6u; r[16]=code_base|0x0c0cab56u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cab56u) { target=s->pc; goto dispatch; }
goto P_0c0cab56;
P_0c0cab54: /* original 64e3, guest PC 0x0c0cab54 */
if(!s->budget--) { s->failed_pc=0x0c0cab54u; return 0; }
r[4]=r[14];
goto P_0c0cab56;
P_0c0cab56: /* original bfa1, guest PC 0x0c0cab56 */
if(!s->budget--) { s->failed_pc=0x0c0cab56u; return 0; }
target=code_base|0x0c0caa9cu; r[16]=code_base|0x0c0cab5au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cab5au) { target=s->pc; goto dispatch; }
goto P_0c0cab5a;
P_0c0cab58: /* original 64e3, guest PC 0x0c0cab58 */
if(!s->budget--) { s->failed_pc=0x0c0cab58u; return 0; }
r[4]=r[14];
goto P_0c0cab5a;
P_0c0cab5a: /* original e048, guest PC 0x0c0cab5a */
if(!s->budget--) { s->failed_pc=0x0c0cab5au; return 0; }
r[0]=0x00000048u;
goto P_0c0cab5c;
P_0c0cab5c: /* original 65e2, guest PC 0x0c0cab5c */
if(!s->budget--) { s->failed_pc=0x0c0cab5cu; return 0; }
tmp=read(ram,r[14],4);
r[5]=tmp;
goto P_0c0cab5e;
P_0c0cab5e: /* original 03ee, guest PC 0x0c0cab5e */
if(!s->budget--) { s->failed_pc=0x0c0cab5eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0cab60;
P_0c0cab60: /* original 1f34, guest PC 0x0c0cab60 */
if(!s->budget--) { s->failed_pc=0x0c0cab60u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0cab62;
P_0c0cab62: /* original d338, guest PC 0x0c0cab62 */
if(!s->budget--) { s->failed_pc=0x0c0cab62u; return 0; }
r[3]=read(ram,0x0c0cac44u,4);
goto P_0c0cab64;
P_0c0cab64: /* original 2358, guest PC 0x0c0cab64 */
if(!s->budget--) { s->failed_pc=0x0c0cab64u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0cab66;
P_0c0cab66: /* original 8f04, guest PC 0x0c0cab66 */
if(!s->budget--) { s->failed_pc=0x0c0cab66u; return 0; }
cond=r[17]&1u;
r[10]=0x00000000u;
if(!cond) { goto P_0c0cab72; }
goto P_0c0cab6a;
P_0c0cab68: /* original ea00, guest PC 0x0c0cab68 */
if(!s->budget--) { s->failed_pc=0x0c0cab68u; return 0; }
r[10]=0x00000000u;
goto P_0c0cab6a;
P_0c0cab6a: /* original 52f4, guest PC 0x0c0cab6a */
if(!s->budget--) { s->failed_pc=0x0c0cab6au; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0cab6c;
P_0c0cab6c: /* original 9360, guest PC 0x0c0cab6c */
if(!s->budget--) { s->failed_pc=0x0c0cab6cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cac30u,2);
goto P_0c0cab6e;
P_0c0cab6e: /* original 2238, guest PC 0x0c0cab6e */
if(!s->budget--) { s->failed_pc=0x0c0cab6eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cab70;
P_0c0cab70: /* original 8901, guest PC 0x0c0cab70 */
if(!s->budget--) { s->failed_pc=0x0c0cab70u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cab76; }
goto P_0c0cab72;
P_0c0cab72: /* original a001, guest PC 0x0c0cab72 */
if(!s->budget--) { s->failed_pc=0x0c0cab72u; return 0; }
r[8]=0x00000001u;
goto P_0c0cab78;
P_0c0cab74: /* original e801, guest PC 0x0c0cab74 */
if(!s->budget--) { s->failed_pc=0x0c0cab74u; return 0; }
r[8]=0x00000001u;
goto P_0c0cab76;
P_0c0cab76: /* original 68a3, guest PC 0x0c0cab76 */
if(!s->budget--) { s->failed_pc=0x0c0cab76u; return 0; }
r[8]=r[10];
goto P_0c0cab78;
P_0c0cab78: /* original c733, guest PC 0x0c0cab78 */
if(!s->budget--) { s->failed_pc=0x0c0cab78u; return 0; }
r[0]=code_base|0x000cac48u;
goto P_0c0cab7a;
P_0c0cab7a: /* original 6ba3, guest PC 0x0c0cab7a */
if(!s->budget--) { s->failed_pc=0x0c0cab7au; return 0; }
r[11]=r[10];
goto P_0c0cab7c;
P_0c0cab7c: /* original f308, guest PC 0x0c0cab7c */
if(!s->budget--) { s->failed_pc=0x0c0cab7cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cab7e;
P_0c0cab7e: /* original e004, guest PC 0x0c0cab7e */
if(!s->budget--) { s->failed_pc=0x0c0cab7eu; return 0; }
r[0]=0x00000004u;
goto P_0c0cab80;
P_0c0cab80: /* original 6cb3, guest PC 0x0c0cab80 */
if(!s->budget--) { s->failed_pc=0x0c0cab80u; return 0; }
r[12]=r[11];
goto P_0c0cab82;
P_0c0cab82: /* original 69b3, guest PC 0x0c0cab82 */
if(!s->budget--) { s->failed_pc=0x0c0cab82u; return 0; }
r[9]=r[11];
goto P_0c0cab84;
P_0c0cab84: /* original ff37, guest PC 0x0c0cab84 */
if(!s->budget--) { s->failed_pc=0x0c0cab84u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cab86;
P_0c0cab86: /* original e014, guest PC 0x0c0cab86 */
if(!s->budget--) { s->failed_pc=0x0c0cab86u; return 0; }
r[0]=0x00000014u;
goto P_0c0cab88;
P_0c0cab88: /* original f4e6, guest PC 0x0c0cab88 */
if(!s->budget--) { s->failed_pc=0x0c0cab88u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0cab8a;
P_0c0cab8a: /* original c730, guest PC 0x0c0cab8a */
if(!s->budget--) { s->failed_pc=0x0c0cab8au; return 0; }
r[0]=code_base|0x000cac4cu;
goto P_0c0cab8c;
P_0c0cab8c: /* original 9352, guest PC 0x0c0cab8c */
if(!s->budget--) { s->failed_pc=0x0c0cab8cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cac34u,2);
goto P_0c0cab8e;
P_0c0cab8e: /* original f708, guest PC 0x0c0cab8e */
if(!s->budget--) { s->failed_pc=0x0c0cab8eu; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0cab90;
P_0c0cab90: /* original e004, guest PC 0x0c0cab90 */
if(!s->budget--) { s->failed_pc=0x0c0cab90u; return 0; }
r[0]=0x00000004u;
goto P_0c0cab92;
P_0c0cab92: /* original 33ec, guest PC 0x0c0cab92 */
if(!s->budget--) { s->failed_pc=0x0c0cab92u; return 0; }
r[3]+=r[14];
goto P_0c0cab94;
P_0c0cab94: /* original f34c, guest PC 0x0c0cab94 */
if(!s->budget--) { s->failed_pc=0x0c0cab94u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0cab96;
P_0c0cab96: /* original f4f6, guest PC 0x0c0cab96 */
if(!s->budget--) { s->failed_pc=0x0c0cab96u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0cab98;
P_0c0cab98: /* original 904b, guest PC 0x0c0cab98 */
if(!s->budget--) { s->failed_pc=0x0c0cab98u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cac32u,2);
goto P_0c0cab9a;
P_0c0cab9a: /* original f430, guest PC 0x0c0cab9a */
if(!s->budget--) { s->failed_pc=0x0c0cab9au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0cab9c;
P_0c0cab9c: /* original dd2c, guest PC 0x0c0cab9c */
if(!s->budget--) { s->failed_pc=0x0c0cab9cu; return 0; }
r[13]=read(ram,0x0c0cac50u,4);
goto P_0c0cab9e;
P_0c0cab9e: /* original 07ee, guest PC 0x0c0cab9e */
if(!s->budget--) { s->failed_pc=0x0c0cab9eu; return 0; }
r[7]=read(ram,r[14]+r[0],4);
goto P_0c0caba0;
P_0c0caba0: /* original 1f3c, guest PC 0x0c0caba0 */
if(!s->budget--) { s->failed_pc=0x0c0caba0u; return 0; }
write(ram,r[15]+48,r[3],4);
goto P_0c0caba2;
P_0c0caba2: /* original 64d3, guest PC 0x0c0caba2 */
if(!s->budget--) { s->failed_pc=0x0c0caba2u; return 0; }
r[4]=r[13];
goto P_0c0caba4;
P_0c0caba4: /* original 9247, guest PC 0x0c0caba4 */
if(!s->budget--) { s->failed_pc=0x0c0caba4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cac36u,2);
goto P_0c0caba6;
P_0c0caba6: /* original 32ec, guest PC 0x0c0caba6 */
if(!s->budget--) { s->failed_pc=0x0c0caba6u; return 0; }
r[2]+=r[14];
goto P_0c0caba8;
P_0c0caba8: /* original 1f2d, guest PC 0x0c0caba8 */
if(!s->budget--) { s->failed_pc=0x0c0caba8u; return 0; }
write(ram,r[15]+52,r[2],4);
goto P_0c0cabaa;
P_0c0cabaa: /* original 9345, guest PC 0x0c0cabaa */
if(!s->budget--) { s->failed_pc=0x0c0cabaau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cac38u,2);
goto P_0c0cabac;
P_0c0cabac: /* original 33ec, guest PC 0x0c0cabac */
if(!s->budget--) { s->failed_pc=0x0c0cabacu; return 0; }
r[3]+=r[14];
goto P_0c0cabae;
P_0c0cabae: /* original 1f3e, guest PC 0x0c0cabae */
if(!s->budget--) { s->failed_pc=0x0c0cabaeu; return 0; }
write(ram,r[15]+56,r[3],4);
goto P_0c0cabb0;
P_0c0cabb0: /* original e32c, guest PC 0x0c0cabb0 */
if(!s->budget--) { s->failed_pc=0x0c0cabb0u; return 0; }
r[3]=0x0000002cu;
goto P_0c0cabb2;
P_0c0cabb2: /* original 923f, guest PC 0x0c0cabb2 */
if(!s->budget--) { s->failed_pc=0x0c0cabb2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cac34u,2);
goto P_0c0cabb4;
P_0c0cabb4: /* original 32ec, guest PC 0x0c0cabb4 */
if(!s->budget--) { s->failed_pc=0x0c0cabb4u; return 0; }
r[2]+=r[14];
goto P_0c0cabb6;
P_0c0cabb6: /* original 1f2a, guest PC 0x0c0cabb6 */
if(!s->budget--) { s->failed_pc=0x0c0cabb6u; return 0; }
write(ram,r[15]+40,r[2],4);
goto P_0c0cabb8;
P_0c0cabb8: /* original e11c, guest PC 0x0c0cabb8 */
if(!s->budget--) { s->failed_pc=0x0c0cabb8u; return 0; }
r[1]=0x0000001cu;
goto P_0c0cabba;
P_0c0cabba: /* original 1f3b, guest PC 0x0c0cabba */
if(!s->budget--) { s->failed_pc=0x0c0cabbau; return 0; }
write(ram,r[15]+44,r[3],4);
goto P_0c0cabbc;
P_0c0cabbc: /* original 50f7, guest PC 0x0c0cabbc */
if(!s->budget--) { s->failed_pc=0x0c0cabbcu; return 0; }
r[0]=read(ram,r[15]+28,4);
goto P_0c0cabbe;
P_0c0cabbe: /* original 001c, guest PC 0x0c0cabbe */
if(!s->budget--) { s->failed_pc=0x0c0cabbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0cabc0;
P_0c0cabc0: /* original 600c, guest PC 0x0c0cabc0 */
if(!s->budget--) { s->failed_pc=0x0c0cabc0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0cabc2;
P_0c0cabc2: /* original c90f, guest PC 0x0c0cabc2 */
if(!s->budget--) { s->failed_pc=0x0c0cabc2u; return 0; }
r[0]&=15u;
goto P_0c0cabc4;
P_0c0cabc4: /* original 8804, guest PC 0x0c0cabc4 */
if(!s->budget--) { s->failed_pc=0x0c0cabc4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0cabc6;
P_0c0cabc6: /* original 8d02, guest PC 0x0c0cabc6 */
if(!s->budget--) { s->failed_pc=0x0c0cabc6u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[0],4);
if(cond) { goto P_0c0cabce; }
goto P_0c0cabca;
P_0c0cabc8: /* original 2f02, guest PC 0x0c0cabc8 */
if(!s->budget--) { s->failed_pc=0x0c0cabc8u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0cabca;
P_0c0cabca: /* original 8801, guest PC 0x0c0cabca */
if(!s->budget--) { s->failed_pc=0x0c0cabcau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0cabcc;
P_0c0cabcc: /* original 8b02, guest PC 0x0c0cabcc */
if(!s->budget--) { s->failed_pc=0x0c0cabccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cabd4; }
goto P_0c0cabce;
P_0c0cabce: /* original d621, guest PC 0x0c0cabce */
if(!s->budget--) { s->failed_pc=0x0c0cabceu; return 0; }
r[6]=read(ram,0x0c0cac54u,4);
goto P_0c0cabd0;
P_0c0cabd0: /* original a001, guest PC 0x0c0cabd0 */
if(!s->budget--) { s->failed_pc=0x0c0cabd0u; return 0; }
goto P_0c0cabd6;
P_0c0cabd2: /* original 0009, guest PC 0x0c0cabd2 */
if(!s->budget--) { s->failed_pc=0x0c0cabd2u; return 0; }
goto P_0c0cabd4;
P_0c0cabd4: /* original d620, guest PC 0x0c0cabd4 */
if(!s->budget--) { s->failed_pc=0x0c0cabd4u; return 0; }
r[6]=read(ram,0x0c0cac58u,4);
goto P_0c0cabd6;
P_0c0cabd6: /* original e21c, guest PC 0x0c0cabd6 */
if(!s->budget--) { s->failed_pc=0x0c0cabd6u; return 0; }
r[2]=0x0000001cu;
goto P_0c0cabd8;
P_0c0cabd8: /* original 1f22, guest PC 0x0c0cabd8 */
if(!s->budget--) { s->failed_pc=0x0c0cabd8u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0cabda;
P_0c0cabda: /* original 53fe, guest PC 0x0c0cabda */
if(!s->budget--) { s->failed_pc=0x0c0cabdau; return 0; }
r[3]=read(ram,r[15]+56,4);
goto P_0c0cabdc;
P_0c0cabdc: /* original e004, guest PC 0x0c0cabdc */
if(!s->budget--) { s->failed_pc=0x0c0cabdcu; return 0; }
r[0]=0x00000004u;
goto P_0c0cabde;
P_0c0cabde: /* original 7304, guest PC 0x0c0cabde */
if(!s->budget--) { s->failed_pc=0x0c0cabdeu; return 0; }
r[3]+=0x00000004u;
goto P_0c0cabe0;
P_0c0cabe0: /* original 1f3e, guest PC 0x0c0cabe0 */
if(!s->budget--) { s->failed_pc=0x0c0cabe0u; return 0; }
write(ram,r[15]+56,r[3],4);
goto P_0c0cabe2;
P_0c0cabe2: /* original 73fc, guest PC 0x0c0cabe2 */
if(!s->budget--) { s->failed_pc=0x0c0cabe2u; return 0; }
r[3]+=0xfffffffcu;
goto P_0c0cabe4;
P_0c0cabe4: /* original f338, guest PC 0x0c0cabe4 */
if(!s->budget--) { s->failed_pc=0x0c0cabe4u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c0cabe6;
P_0c0cabe6: /* original 53fd, guest PC 0x0c0cabe6 */
if(!s->budget--) { s->failed_pc=0x0c0cabe6u; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c0cabe8;
P_0c0cabe8: /* original f576, guest PC 0x0c0cabe8 */
if(!s->budget--) { s->failed_pc=0x0c0cabe8u; return 0; }
vf3_matrix_load(s,ram,5,r[7]+r[0]);
goto P_0c0cabea;
P_0c0cabea: /* original 770c, guest PC 0x0c0cabea */
if(!s->budget--) { s->failed_pc=0x0c0cabeau; return 0; }
r[7]+=0x0000000cu;
goto P_0c0cabec;
P_0c0cabec: /* original 7304, guest PC 0x0c0cabec */
if(!s->budget--) { s->failed_pc=0x0c0cabecu; return 0; }
r[3]+=0x00000004u;
goto P_0c0cabee;
P_0c0cabee: /* original 1f3d, guest PC 0x0c0cabee */
if(!s->budget--) { s->failed_pc=0x0c0cabeeu; return 0; }
write(ram,r[15]+52,r[3],4);
goto P_0c0cabf0;
P_0c0cabf0: /* original 73fc, guest PC 0x0c0cabf0 */
if(!s->budget--) { s->failed_pc=0x0c0cabf0u; return 0; }
r[3]+=0xfffffffcu;
goto P_0c0cabf2;
P_0c0cabf2: /* original 6260, guest PC 0x0c0cabf2 */
if(!s->budget--) { s->failed_pc=0x0c0cabf2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[2]=tmp;
goto P_0c0cabf4;
P_0c0cabf4: /* original f838, guest PC 0x0c0cabf4 */
if(!s->budget--) { s->failed_pc=0x0c0cabf4u; return 0; }
vf3_matrix_load(s,ram,8,r[3]);
goto P_0c0cabf6;
P_0c0cabf6: /* original 1f26, guest PC 0x0c0cabf6 */
if(!s->budget--) { s->failed_pc=0x0c0cabf6u; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c0cabf8;
P_0c0cabf8: /* original 4208, guest PC 0x0c0cabf8 */
if(!s->budget--) { s->failed_pc=0x0c0cabf8u; return 0; }
r[2]<<=2;
goto P_0c0cabfa;
P_0c0cabfa: /* original 50fc, guest PC 0x0c0cabfa */
if(!s->budget--) { s->failed_pc=0x0c0cabfau; return 0; }
r[0]=read(ram,r[15]+48,4);
goto P_0c0cabfc;
P_0c0cabfc: /* original f581, guest PC 0x0c0cabfc */
if(!s->budget--) { s->failed_pc=0x0c0cabfcu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'-');
goto P_0c0cabfe;
P_0c0cabfe: /* original 032e, guest PC 0x0c0cabfe */
if(!s->budget--) { s->failed_pc=0x0c0cabfeu; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c0cac00;
P_0c0cac00: /* original 2f32, guest PC 0x0c0cac00 */
if(!s->budget--) { s->failed_pc=0x0c0cac00u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0cac02;
P_0c0cac02: /* original 52fb, guest PC 0x0c0cac02 */
if(!s->budget--) { s->failed_pc=0x0c0cac02u; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c0cac04;
P_0c0cac04: /* original 2239, guest PC 0x0c0cac04 */
if(!s->budget--) { s->failed_pc=0x0c0cac04u; return 0; }
r[2]&=r[3];
goto P_0c0cac06;
P_0c0cac06: /* original 1f26, guest PC 0x0c0cac06 */
if(!s->budget--) { s->failed_pc=0x0c0cac06u; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c0cac08;
P_0c0cac08: /* original 51fa, guest PC 0x0c0cac08 */
if(!s->budget--) { s->failed_pc=0x0c0cac08u; return 0; }
r[1]=read(ram,r[15]+40,4);
goto P_0c0cac0a;
P_0c0cac0a: /* original 7104, guest PC 0x0c0cac0a */
if(!s->budget--) { s->failed_pc=0x0c0cac0au; return 0; }
r[1]+=0x00000004u;
goto P_0c0cac0c;
P_0c0cac0c: /* original 1f1a, guest PC 0x0c0cac0c */
if(!s->budget--) { s->failed_pc=0x0c0cac0cu; return 0; }
write(ram,r[15]+40,r[1],4);
goto P_0c0cac0e;
P_0c0cac0e: /* original 2136, guest PC 0x0c0cac0e */
if(!s->budget--) { s->failed_pc=0x0c0cac0eu; return 0; }
tmp=r[3]; r[1]-=4; write(ram,r[1],tmp,4);
goto P_0c0cac10;
P_0c0cac10: /* original 53f6, guest PC 0x0c0cac10 */
if(!s->budget--) { s->failed_pc=0x0c0cac10u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0cac12;
P_0c0cac12: /* original f67c, guest PC 0x0c0cac12 */
if(!s->budget--) { s->failed_pc=0x0c0cac12u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c0cac14;
P_0c0cac14: /* original 2338, guest PC 0x0c0cac14 */
if(!s->budget--) { s->failed_pc=0x0c0cac14u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0cac16;
P_0c0cac16: /* original 8d03, guest PC 0x0c0cac16 */
if(!s->budget--) { s->failed_pc=0x0c0cac16u; return 0; }
cond=r[17]&1u;
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'+');
if(cond) { goto P_0c0cac20; }
goto P_0c0cac1a;
P_0c0cac18: /* original f630, guest PC 0x0c0cac18 */
if(!s->budget--) { s->failed_pc=0x0c0cac18u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'+');
goto P_0c0cac1a;
P_0c0cac1a: /* original e301, guest PC 0x0c0cac1a */
if(!s->budget--) { s->failed_pc=0x0c0cac1au; return 0; }
r[3]=0x00000001u;
goto P_0c0cac1c;
P_0c0cac1c: /* original a001, guest PC 0x0c0cac1c */
if(!s->budget--) { s->failed_pc=0x0c0cac1cu; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0cac22;
P_0c0cac1e: /* original 1f36, guest PC 0x0c0cac1e */
if(!s->budget--) { s->failed_pc=0x0c0cac1eu; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0cac20;
P_0c0cac20: /* original 1fa6, guest PC 0x0c0cac20 */
if(!s->budget--) { s->failed_pc=0x0c0cac20u; return 0; }
write(ram,r[15]+24,r[10],4);
goto P_0c0cac22;
P_0c0cac22: /* original 60f2, guest PC 0x0c0cac22 */
if(!s->budget--) { s->failed_pc=0x0c0cac22u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0cac24;
P_0c0cac24: /* original c820, guest PC 0x0c0cac24 */
if(!s->budget--) { s->failed_pc=0x0c0cac24u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0cac26;
P_0c0cac26: /* original 8d19, guest PC 0x0c0cac26 */
if(!s->budget--) { s->failed_pc=0x0c0cac26u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,8,5);
if(cond) { goto P_0c0cac5c; }
goto P_0c0cac2a;
P_0c0cac28: /* original f85c, guest PC 0x0c0cac28 */
if(!s->budget--) { s->failed_pc=0x0c0cac28u; return 0; }
vf3_matrix_move(s,8,5);
goto P_0c0cac2a;
P_0c0cac2a: /* original e201, guest PC 0x0c0cac2a */
if(!s->budget--) { s->failed_pc=0x0c0cac2au; return 0; }
r[2]=0x00000001u;
goto P_0c0cac2c;
P_0c0cac2c: /* original a017, guest PC 0x0c0cac2c */
if(!s->budget--) { s->failed_pc=0x0c0cac2cu; return 0; }
write(ram,r[15]+36,r[2],4);
goto P_0c0cac5e;
P_0c0cac2e: /* original 1f29, guest PC 0x0c0cac2e */
if(!s->budget--) { s->failed_pc=0x0c0cac2eu; return 0; }
write(ram,r[15]+36,r[2],4);
if(!vf3_matrix_family(0x0c0cac30u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0cac30u; return 0; } return 1;
P_0c0cac5c: /* original 1fa9, guest PC 0x0c0cac5c */
if(!s->budget--) { s->failed_pc=0x0c0cac5cu; return 0; }
write(ram,r[15]+36,r[10],4);
goto P_0c0cac5e;
P_0c0cac5e: /* original f841, guest PC 0x0c0cac5e */
if(!s->budget--) { s->failed_pc=0x0c0cac5eu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'-');
goto P_0c0cac60;
P_0c0cac60: /* original 60f2, guest PC 0x0c0cac60 */
if(!s->budget--) { s->failed_pc=0x0c0cac60u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0cac62;
P_0c0cac62: /* original c802, guest PC 0x0c0cac62 */
if(!s->budget--) { s->failed_pc=0x0c0cac62u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0cac64;
P_0c0cac64: /* original 8f1c, guest PC 0x0c0cac64 */
if(!s->budget--) { s->failed_pc=0x0c0cac64u; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
if(!cond) { goto P_0c0caca0; }
goto P_0c0cac68;
P_0c0cac66: /* original f561, guest PC 0x0c0cac66 */
if(!s->budget--) { s->failed_pc=0x0c0cac66u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c0cac68;
P_0c0cac68: /* original 53f6, guest PC 0x0c0cac68 */
if(!s->budget--) { s->failed_pc=0x0c0cac68u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0cac6a;
P_0c0cac6a: /* original 2338, guest PC 0x0c0cac6a */
if(!s->budget--) { s->failed_pc=0x0c0cac6au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0cac6c;
P_0c0cac6c: /* original 8902, guest PC 0x0c0cac6c */
if(!s->budget--) { s->failed_pc=0x0c0cac6cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cac74; }
goto P_0c0cac6e;
P_0c0cac6e: /* original 933f, guest PC 0x0c0cac6e */
if(!s->budget--) { s->failed_pc=0x0c0cac6eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cacf0u,2);
goto P_0c0cac70;
P_0c0cac70: /* original 2358, guest PC 0x0c0cac70 */
if(!s->budget--) { s->failed_pc=0x0c0cac70u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0cac72;
P_0c0cac72: /* original 8910, guest PC 0x0c0cac72 */
if(!s->budget--) { s->failed_pc=0x0c0cac72u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cac96; }
goto P_0c0cac74;
P_0c0cac74: /* original f38d, guest PC 0x0c0cac74 */
if(!s->budget--) { s->failed_pc=0x0c0cac74u; return 0; }
fr[3]=0;
goto P_0c0cac76;
P_0c0cac76: /* original f835, guest PC 0x0c0cac76 */
if(!s->budget--) { s->failed_pc=0x0c0cac76u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[3]))!=0);
goto P_0c0cac78;
P_0c0cac78: /* original 8908, guest PC 0x0c0cac78 */
if(!s->budget--) { s->failed_pc=0x0c0cac78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cac8c; }
goto P_0c0cac7a;
P_0c0cac7a: /* original 2888, guest PC 0x0c0cac7a */
if(!s->budget--) { s->failed_pc=0x0c0cac7au; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c0cac7c;
P_0c0cac7c: /* original 8b06, guest PC 0x0c0cac7c */
if(!s->budget--) { s->failed_pc=0x0c0cac7cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cac8c; }
goto P_0c0cac7e;
P_0c0cac7e: /* original 53f9, guest PC 0x0c0cac7e */
if(!s->budget--) { s->failed_pc=0x0c0cac7eu; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c0cac80;
P_0c0cac80: /* original 2338, guest PC 0x0c0cac80 */
if(!s->budget--) { s->failed_pc=0x0c0cac80u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0cac82;
P_0c0cac82: /* original 8902, guest PC 0x0c0cac82 */
if(!s->budget--) { s->failed_pc=0x0c0cac82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cac8a; }
goto P_0c0cac84;
P_0c0cac84: /* original 9234, guest PC 0x0c0cac84 */
if(!s->budget--) { s->failed_pc=0x0c0cac84u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cacf0u,2);
goto P_0c0cac86;
P_0c0cac86: /* original 2258, guest PC 0x0c0cac86 */
if(!s->budget--) { s->failed_pc=0x0c0cac86u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0cac88;
P_0c0cac88: /* original 8900, guest PC 0x0c0cac88 */
if(!s->budget--) { s->failed_pc=0x0c0cac88u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cac8c; }
goto P_0c0cac8a;
P_0c0cac8a: /* original 2c4b, guest PC 0x0c0cac8a */
if(!s->budget--) { s->failed_pc=0x0c0cac8au; return 0; }
r[12]|=r[4];
goto P_0c0cac8c;
P_0c0cac8c: /* original f38d, guest PC 0x0c0cac8c */
if(!s->budget--) { s->failed_pc=0x0c0cac8cu; return 0; }
fr[3]=0;
goto P_0c0cac8e;
P_0c0cac8e: /* original f535, guest PC 0x0c0cac8e */
if(!s->budget--) { s->failed_pc=0x0c0cac8eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[3]))!=0);
goto P_0c0cac90;
P_0c0cac90: /* original 890b, guest PC 0x0c0cac90 */
if(!s->budget--) { s->failed_pc=0x0c0cac90u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cacaa; }
goto P_0c0cac92;
P_0c0cac92: /* original a00a, guest PC 0x0c0cac92 */
if(!s->budget--) { s->failed_pc=0x0c0cac92u; return 0; }
r[9]|=r[4];
goto P_0c0cacaa;
P_0c0cac94: /* original 294b, guest PC 0x0c0cac94 */
if(!s->budget--) { s->failed_pc=0x0c0cac94u; return 0; }
r[9]|=r[4];
goto P_0c0cac96;
P_0c0cac96: /* original f38d, guest PC 0x0c0cac96 */
if(!s->budget--) { s->failed_pc=0x0c0cac96u; return 0; }
fr[3]=0;
goto P_0c0cac98;
P_0c0cac98: /* original f535, guest PC 0x0c0cac98 */
if(!s->budget--) { s->failed_pc=0x0c0cac98u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[3]))!=0);
goto P_0c0cac9a;
P_0c0cac9a: /* original 8906, guest PC 0x0c0cac9a */
if(!s->budget--) { s->failed_pc=0x0c0cac9au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cacaa; }
goto P_0c0cac9c;
P_0c0cac9c: /* original a005, guest PC 0x0c0cac9c */
if(!s->budget--) { s->failed_pc=0x0c0cac9cu; return 0; }
r[11]|=r[4];
goto P_0c0cacaa;
P_0c0cac9e: /* original 2b4b, guest PC 0x0c0cac9e */
if(!s->budget--) { s->failed_pc=0x0c0cac9eu; return 0; }
r[11]|=r[4];
goto P_0c0caca0;
P_0c0caca0: /* original 52f4, guest PC 0x0c0caca0 */
if(!s->budget--) { s->failed_pc=0x0c0caca0u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0caca2;
P_0c0caca2: /* original d316, guest PC 0x0c0caca2 */
if(!s->budget--) { s->failed_pc=0x0c0caca2u; return 0; }
r[3]=read(ram,0x0c0cacfcu,4);
goto P_0c0caca4;
P_0c0caca4: /* original 2238, guest PC 0x0c0caca4 */
if(!s->budget--) { s->failed_pc=0x0c0caca4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0caca6;
P_0c0caca6: /* original 8b00, guest PC 0x0c0caca6 */
if(!s->budget--) { s->failed_pc=0x0c0caca6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cacaa; }
goto P_0c0caca8;
P_0c0caca8: /* original 2b4b, guest PC 0x0c0caca8 */
if(!s->budget--) { s->failed_pc=0x0c0caca8u; return 0; }
r[11]|=r[4];
goto P_0c0cacaa;
P_0c0cacaa: /* original 53f2, guest PC 0x0c0cacaa */
if(!s->budget--) { s->failed_pc=0x0c0cacaau; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0cacac;
P_0c0cacac: /* original 4401, guest PC 0x0c0cacac */
if(!s->budget--) { s->failed_pc=0x0c0cacacu; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c0cacae;
P_0c0cacae: /* original 7601, guest PC 0x0c0cacae */
if(!s->budget--) { s->failed_pc=0x0c0cacaeu; return 0; }
r[6]+=0x00000001u;
goto P_0c0cacb0;
P_0c0cacb0: /* original 73ff, guest PC 0x0c0cacb0 */
if(!s->budget--) { s->failed_pc=0x0c0cacb0u; return 0; }
r[3]+=0xffffffffu;
goto P_0c0cacb2;
P_0c0cacb2: /* original 2338, guest PC 0x0c0cacb2 */
if(!s->budget--) { s->failed_pc=0x0c0cacb2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0cacb4;
P_0c0cacb4: /* original 8f91, guest PC 0x0c0cacb4 */
if(!s->budget--) { s->failed_pc=0x0c0cacb4u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[3],4);
if(!cond) { goto P_0c0cabda; }
goto P_0c0cacb8;
P_0c0cacb6: /* original 1f32, guest PC 0x0c0cacb6 */
if(!s->budget--) { s->failed_pc=0x0c0cacb6u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0cacb8;
P_0c0cacb8: /* original e061, guest PC 0x0c0cacb8 */
if(!s->budget--) { s->failed_pc=0x0c0cacb8u; return 0; }
r[0]=0x00000061u;
goto P_0c0cacba;
P_0c0cacba: /* original 00ec, guest PC 0x0c0cacba */
if(!s->budget--) { s->failed_pc=0x0c0cacbau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0cacbc;
P_0c0cacbc: /* original 600c, guest PC 0x0c0cacbc */
if(!s->budget--) { s->failed_pc=0x0c0cacbcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0cacbe;
P_0c0cacbe: /* original 8809, guest PC 0x0c0cacbe */
if(!s->budget--) { s->failed_pc=0x0c0cacbeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0cacc0;
P_0c0cacc0: /* original 8905, guest PC 0x0c0cacc0 */
if(!s->budget--) { s->failed_pc=0x0c0cacc0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cacce; }
goto P_0c0cacc2;
P_0c0cacc2: /* original 9017, guest PC 0x0c0cacc2 */
if(!s->budget--) { s->failed_pc=0x0c0cacc2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cacf4u,2);
goto P_0c0cacc4;
P_0c0cacc4: /* original 53f8, guest PC 0x0c0cacc4 */
if(!s->budget--) { s->failed_pc=0x0c0cacc4u; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c0cacc6;
P_0c0cacc6: /* original 9214, guest PC 0x0c0cacc6 */
if(!s->budget--) { s->failed_pc=0x0c0cacc6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cacf2u,2);
goto P_0c0cacc8;
P_0c0cacc8: /* original 013e, guest PC 0x0c0cacc8 */
if(!s->budget--) { s->failed_pc=0x0c0cacc8u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c0cacca;
P_0c0cacca: /* original 2128, guest PC 0x0c0cacca */
if(!s->budget--) { s->failed_pc=0x0c0caccau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0caccc;
P_0c0caccc: /* original 8b08, guest PC 0x0c0caccc */
if(!s->budget--) { s->failed_pc=0x0c0cacccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cace0; }
goto P_0c0cacce;
P_0c0cacce: /* original 9012, guest PC 0x0c0cacce */
if(!s->budget--) { s->failed_pc=0x0c0cacceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cacf6u,2);
goto P_0c0cacd0;
P_0c0cacd0: /* original 64f3, guest PC 0x0c0cacd0 */
if(!s->budget--) { s->failed_pc=0x0c0cacd0u; return 0; }
r[4]=r[15];
goto P_0c0cacd2;
P_0c0cacd2: /* original d30b, guest PC 0x0c0cacd2 */
if(!s->budget--) { s->failed_pc=0x0c0cacd2u; return 0; }
r[3]=read(ram,0x0c0cad00u,4);
goto P_0c0cacd4;
P_0c0cacd4: /* original 7404, guest PC 0x0c0cacd4 */
if(!s->budget--) { s->failed_pc=0x0c0cacd4u; return 0; }
r[4]+=0x00000004u;
goto P_0c0cacd6;
P_0c0cacd6: /* original 430b, guest PC 0x0c0cacd6 */
if(!s->budget--) { s->failed_pc=0x0c0cacd6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0cacdau;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cacdau) { target=s->pc; goto dispatch; }
goto P_0c0cacda;
P_0c0cacd8: /* original f4e6, guest PC 0x0c0cacd8 */
if(!s->budget--) { s->failed_pc=0x0c0cacd8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0cacda;
P_0c0cacda: /* original f38d, guest PC 0x0c0cacda */
if(!s->budget--) { s->failed_pc=0x0c0cacdau; return 0; }
fr[3]=0;
goto P_0c0cacdc;
P_0c0cacdc: /* original f035, guest PC 0x0c0cacdc */
if(!s->budget--) { s->failed_pc=0x0c0cacdcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c0cacde;
P_0c0cacde: /* original 8b05, guest PC 0x0c0cacde */
if(!s->budget--) { s->failed_pc=0x0c0cacdeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cacec; }
goto P_0c0cace0;
P_0c0cace0: /* original 2bb8, guest PC 0x0c0cace0 */
if(!s->budget--) { s->failed_pc=0x0c0cace0u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0cace2;
P_0c0cace2: /* original 8b0f, guest PC 0x0c0cace2 */
if(!s->budget--) { s->failed_pc=0x0c0cace2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cad04; }
goto P_0c0cace4;
P_0c0cace4: /* original 9008, guest PC 0x0c0cace4 */
if(!s->budget--) { s->failed_pc=0x0c0cace4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cacf8u,2);
goto P_0c0cace6;
P_0c0cace6: /* original 00ee, guest PC 0x0c0cace6 */
if(!s->budget--) { s->failed_pc=0x0c0cace6u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0cace8;
P_0c0cace8: /* original c804, guest PC 0x0c0cace8 */
if(!s->budget--) { s->failed_pc=0x0c0cace8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0cacea;
P_0c0cacea: /* original 8b0b, guest PC 0x0c0cacea */
if(!s->budget--) { s->failed_pc=0x0c0caceau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cad04; }
goto P_0c0cacec;
P_0c0cacec: /* original a01c, guest PC 0x0c0cacec */
if(!s->budget--) { s->failed_pc=0x0c0cacecu; return 0; }
r[12]=r[10];
goto P_0c0cad28;
P_0c0cacee: /* original 6ca3, guest PC 0x0c0cacee */
if(!s->budget--) { s->failed_pc=0x0c0caceeu; return 0; }
r[12]=r[10];
if(!vf3_matrix_family(0x0c0cacf0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0cacf0u; return 0; } return 1;
P_0c0cad04: /* original 905e, guest PC 0x0c0cad04 */
if(!s->budget--) { s->failed_pc=0x0c0cad04u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cadc4u,2);
goto P_0c0cad06;
P_0c0cad06: /* original d332, guest PC 0x0c0cad06 */
if(!s->budget--) { s->failed_pc=0x0c0cad06u; return 0; }
r[3]=read(ram,0x0c0cadd0u,4);
goto P_0c0cad08;
P_0c0cad08: /* original 02ee, guest PC 0x0c0cad08 */
if(!s->budget--) { s->failed_pc=0x0c0cad08u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0cad0a;
P_0c0cad0a: /* original 2238, guest PC 0x0c0cad0a */
if(!s->budget--) { s->failed_pc=0x0c0cad0au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cad0c;
P_0c0cad0c: /* original 8908, guest PC 0x0c0cad0c */
if(!s->budget--) { s->failed_pc=0x0c0cad0cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cad20; }
goto P_0c0cad0e;
P_0c0cad0e: /* original 905a, guest PC 0x0c0cad0e */
if(!s->budget--) { s->failed_pc=0x0c0cad0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cadc6u,2);
goto P_0c0cad10;
P_0c0cad10: /* original 01ec, guest PC 0x0c0cad10 */
if(!s->budget--) { s->failed_pc=0x0c0cad10u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0cad12;
P_0c0cad12: /* original d030, guest PC 0x0c0cad12 */
if(!s->budget--) { s->failed_pc=0x0c0cad12u; return 0; }
r[0]=read(ram,0x0c0cadd4u,4);
goto P_0c0cad14;
P_0c0cad14: /* original 611c, guest PC 0x0c0cad14 */
if(!s->budget--) { s->failed_pc=0x0c0cad14u; return 0; }
r[1]=r[1]&255u;
goto P_0c0cad16;
P_0c0cad16: /* original 4108, guest PC 0x0c0cad16 */
if(!s->budget--) { s->failed_pc=0x0c0cad16u; return 0; }
r[1]<<=2;
goto P_0c0cad18;
P_0c0cad18: /* original 031e, guest PC 0x0c0cad18 */
if(!s->budget--) { s->failed_pc=0x0c0cad18u; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c0cad1a;
P_0c0cad1a: /* original 6237, guest PC 0x0c0cad1a */
if(!s->budget--) { s->failed_pc=0x0c0cad1au; return 0; }
r[2]=~r[3];
goto P_0c0cad1c;
P_0c0cad1c: /* original 2f32, guest PC 0x0c0cad1c */
if(!s->budget--) { s->failed_pc=0x0c0cad1cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0cad1e;
P_0c0cad1e: /* original 2c29, guest PC 0x0c0cad1e */
if(!s->budget--) { s->failed_pc=0x0c0cad1eu; return 0; }
r[12]&=r[2];
goto P_0c0cad20;
P_0c0cad20: /* original 6397, guest PC 0x0c0cad20 */
if(!s->budget--) { s->failed_pc=0x0c0cad20u; return 0; }
r[3]=~r[9];
goto P_0c0cad22;
P_0c0cad22: /* original 62b7, guest PC 0x0c0cad22 */
if(!s->budget--) { s->failed_pc=0x0c0cad22u; return 0; }
r[2]=~r[11];
goto P_0c0cad24;
P_0c0cad24: /* original 2c39, guest PC 0x0c0cad24 */
if(!s->budget--) { s->failed_pc=0x0c0cad24u; return 0; }
r[12]&=r[3];
goto P_0c0cad26;
P_0c0cad26: /* original 2c29, guest PC 0x0c0cad26 */
if(!s->budget--) { s->failed_pc=0x0c0cad26u; return 0; }
r[12]&=r[2];
goto P_0c0cad28;
P_0c0cad28: /* original 904e, guest PC 0x0c0cad28 */
if(!s->budget--) { s->failed_pc=0x0c0cad28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cadc8u,2);
goto P_0c0cad2a;
P_0c0cad2a: /* original d82b, guest PC 0x0c0cad2a */
if(!s->budget--) { s->failed_pc=0x0c0cad2au; return 0; }
r[8]=read(ram,0x0c0cadd8u,4);
goto P_0c0cad2c;
P_0c0cad2c: /* original 0ec6, guest PC 0x0c0cad2c */
if(!s->budget--) { s->failed_pc=0x0c0cad2cu; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c0cad2e;
P_0c0cad2e: /* original 904c, guest PC 0x0c0cad2e */
if(!s->budget--) { s->failed_pc=0x0c0cad2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cadcau,2);
goto P_0c0cad30;
P_0c0cad30: /* original 0e96, guest PC 0x0c0cad30 */
if(!s->budget--) { s->failed_pc=0x0c0cad30u; return 0; }
write(ram,r[14]+r[0],r[9],4);
goto P_0c0cad32;
P_0c0cad32: /* original 70f8, guest PC 0x0c0cad32 */
if(!s->budget--) { s->failed_pc=0x0c0cad32u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0cad34;
P_0c0cad34: /* original 0eb6, guest PC 0x0c0cad34 */
if(!s->budget--) { s->failed_pc=0x0c0cad34u; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c0cad36;
P_0c0cad36: /* original 2fc2, guest PC 0x0c0cad36 */
if(!s->budget--) { s->failed_pc=0x0c0cad36u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c0cad38;
P_0c0cad38: /* original 1fa2, guest PC 0x0c0cad38 */
if(!s->budget--) { s->failed_pc=0x0c0cad38u; return 0; }
write(ram,r[15]+8,r[10],4);
goto P_0c0cad3a;
P_0c0cad3a: /* original dc28, guest PC 0x0c0cad3a */
if(!s->budget--) { s->failed_pc=0x0c0cad3au; return 0; }
r[12]=read(ram,0x0c0caddcu,4);
goto P_0c0cad3c;
P_0c0cad3c: /* original 4c0b, guest PC 0x0c0cad3c */
if(!s->budget--) { s->failed_pc=0x0c0cad3cu; return 0; }
target=r[12];
r[16]=code_base|0x0c0cad40u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cad40u) { target=s->pc; goto dispatch; }
goto P_0c0cad40;
P_0c0cad3e: /* original 64f2, guest PC 0x0c0cad3e */
if(!s->budget--) { s->failed_pc=0x0c0cad3eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0cad40;
P_0c0cad40: /* original 8820, guest PC 0x0c0cad40 */
if(!s->budget--) { s->failed_pc=0x0c0cad40u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c0cad42;
P_0c0cad42: /* original 8d10, guest PC 0x0c0cad42 */
if(!s->budget--) { s->failed_pc=0x0c0cad42u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0cad66; }
goto P_0c0cad46;
P_0c0cad44: /* original 6403, guest PC 0x0c0cad44 */
if(!s->budget--) { s->failed_pc=0x0c0cad44u; return 0; }
r[4]=r[0];
goto P_0c0cad46;
P_0c0cad46: /* original 6043, guest PC 0x0c0cad46 */
if(!s->budget--) { s->failed_pc=0x0c0cad46u; return 0; }
r[0]=r[4];
goto P_0c0cad48;
P_0c0cad48: /* original 058c, guest PC 0x0c0cad48 */
if(!s->budget--) { s->failed_pc=0x0c0cad48u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[8]+r[0],1);
goto P_0c0cad4a;
P_0c0cad4a: /* original 52f2, guest PC 0x0c0cad4a */
if(!s->budget--) { s->failed_pc=0x0c0cad4au; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0cad4c;
P_0c0cad4c: /* original 635b, guest PC 0x0c0cad4c */
if(!s->budget--) { s->failed_pc=0x0c0cad4cu; return 0; }
r[3]=0u-r[5];
goto P_0c0cad4e;
P_0c0cad4e: /* original 65d3, guest PC 0x0c0cad4e */
if(!s->budget--) { s->failed_pc=0x0c0cad4eu; return 0; }
r[5]=r[13];
goto P_0c0cad50;
P_0c0cad50: /* original 453d, guest PC 0x0c0cad50 */
if(!s->budget--) { s->failed_pc=0x0c0cad50u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c0cad52;
P_0c0cad52: /* original 634b, guest PC 0x0c0cad52 */
if(!s->budget--) { s->failed_pc=0x0c0cad52u; return 0; }
r[3]=0u-r[4];
goto P_0c0cad54;
P_0c0cad54: /* original 64d3, guest PC 0x0c0cad54 */
if(!s->budget--) { s->failed_pc=0x0c0cad54u; return 0; }
r[4]=r[13];
goto P_0c0cad56;
P_0c0cad56: /* original 443d, guest PC 0x0c0cad56 */
if(!s->budget--) { s->failed_pc=0x0c0cad56u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c0cad58;
P_0c0cad58: /* original 6447, guest PC 0x0c0cad58 */
if(!s->budget--) { s->failed_pc=0x0c0cad58u; return 0; }
r[4]=~r[4];
goto P_0c0cad5a;
P_0c0cad5a: /* original 252b, guest PC 0x0c0cad5a */
if(!s->budget--) { s->failed_pc=0x0c0cad5au; return 0; }
r[5]|=r[2];
goto P_0c0cad5c;
P_0c0cad5c: /* original 1f52, guest PC 0x0c0cad5c */
if(!s->budget--) { s->failed_pc=0x0c0cad5cu; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0cad5e;
P_0c0cad5e: /* original 63f2, guest PC 0x0c0cad5e */
if(!s->budget--) { s->failed_pc=0x0c0cad5eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0cad60;
P_0c0cad60: /* original 2439, guest PC 0x0c0cad60 */
if(!s->budget--) { s->failed_pc=0x0c0cad60u; return 0; }
r[4]&=r[3];
goto P_0c0cad62;
P_0c0cad62: /* original afeb, guest PC 0x0c0cad62 */
if(!s->budget--) { s->failed_pc=0x0c0cad62u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0cad3c;
P_0c0cad64: /* original 2f42, guest PC 0x0c0cad64 */
if(!s->budget--) { s->failed_pc=0x0c0cad64u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0cad66;
P_0c0cad66: /* original 9031, guest PC 0x0c0cad66 */
if(!s->budget--) { s->failed_pc=0x0c0cad66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cadccu,2);
goto P_0c0cad68;
P_0c0cad68: /* original 53f2, guest PC 0x0c0cad68 */
if(!s->budget--) { s->failed_pc=0x0c0cad68u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0cad6a;
P_0c0cad6a: /* original 0e36, guest PC 0x0c0cad6a */
if(!s->budget--) { s->failed_pc=0x0c0cad6au; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0cad6c;
P_0c0cad6c: /* original 2f92, guest PC 0x0c0cad6c */
if(!s->budget--) { s->failed_pc=0x0c0cad6cu; return 0; }
write(ram,r[15],r[9],4);
goto P_0c0cad6e;
P_0c0cad6e: /* original 69a3, guest PC 0x0c0cad6e */
if(!s->budget--) { s->failed_pc=0x0c0cad6eu; return 0; }
r[9]=r[10];
goto P_0c0cad70;
P_0c0cad70: /* original 4c0b, guest PC 0x0c0cad70 */
if(!s->budget--) { s->failed_pc=0x0c0cad70u; return 0; }
target=r[12];
r[16]=code_base|0x0c0cad74u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cad74u) { target=s->pc; goto dispatch; }
goto P_0c0cad74;
P_0c0cad72: /* original 64f2, guest PC 0x0c0cad72 */
if(!s->budget--) { s->failed_pc=0x0c0cad72u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0cad74;
P_0c0cad74: /* original 8820, guest PC 0x0c0cad74 */
if(!s->budget--) { s->failed_pc=0x0c0cad74u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c0cad76;
P_0c0cad76: /* original 8d0e, guest PC 0x0c0cad76 */
if(!s->budget--) { s->failed_pc=0x0c0cad76u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0cad96; }
goto P_0c0cad7a;
P_0c0cad78: /* original 6403, guest PC 0x0c0cad78 */
if(!s->budget--) { s->failed_pc=0x0c0cad78u; return 0; }
r[4]=r[0];
goto P_0c0cad7a;
P_0c0cad7a: /* original 6043, guest PC 0x0c0cad7a */
if(!s->budget--) { s->failed_pc=0x0c0cad7au; return 0; }
r[0]=r[4];
goto P_0c0cad7c;
P_0c0cad7c: /* original 058c, guest PC 0x0c0cad7c */
if(!s->budget--) { s->failed_pc=0x0c0cad7cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[8]+r[0],1);
goto P_0c0cad7e;
P_0c0cad7e: /* original 62f2, guest PC 0x0c0cad7e */
if(!s->budget--) { s->failed_pc=0x0c0cad7eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0cad80;
P_0c0cad80: /* original 635b, guest PC 0x0c0cad80 */
if(!s->budget--) { s->failed_pc=0x0c0cad80u; return 0; }
r[3]=0u-r[5];
goto P_0c0cad82;
P_0c0cad82: /* original 65d3, guest PC 0x0c0cad82 */
if(!s->budget--) { s->failed_pc=0x0c0cad82u; return 0; }
r[5]=r[13];
goto P_0c0cad84;
P_0c0cad84: /* original 453d, guest PC 0x0c0cad84 */
if(!s->budget--) { s->failed_pc=0x0c0cad84u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c0cad86;
P_0c0cad86: /* original 634b, guest PC 0x0c0cad86 */
if(!s->budget--) { s->failed_pc=0x0c0cad86u; return 0; }
r[3]=0u-r[4];
goto P_0c0cad88;
P_0c0cad88: /* original 64d3, guest PC 0x0c0cad88 */
if(!s->budget--) { s->failed_pc=0x0c0cad88u; return 0; }
r[4]=r[13];
goto P_0c0cad8a;
P_0c0cad8a: /* original 443d, guest PC 0x0c0cad8a */
if(!s->budget--) { s->failed_pc=0x0c0cad8au; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c0cad8c;
P_0c0cad8c: /* original 6447, guest PC 0x0c0cad8c */
if(!s->budget--) { s->failed_pc=0x0c0cad8cu; return 0; }
r[4]=~r[4];
goto P_0c0cad8e;
P_0c0cad8e: /* original 2429, guest PC 0x0c0cad8e */
if(!s->budget--) { s->failed_pc=0x0c0cad8eu; return 0; }
r[4]&=r[2];
goto P_0c0cad90;
P_0c0cad90: /* original 295b, guest PC 0x0c0cad90 */
if(!s->budget--) { s->failed_pc=0x0c0cad90u; return 0; }
r[9]|=r[5];
goto P_0c0cad92;
P_0c0cad92: /* original afed, guest PC 0x0c0cad92 */
if(!s->budget--) { s->failed_pc=0x0c0cad92u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0cad70;
P_0c0cad94: /* original 2f42, guest PC 0x0c0cad94 */
if(!s->budget--) { s->failed_pc=0x0c0cad94u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0cad96;
P_0c0cad96: /* original 901a, guest PC 0x0c0cad96 */
if(!s->budget--) { s->failed_pc=0x0c0cad96u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cadceu,2);
goto P_0c0cad98;
P_0c0cad98: /* original 0e96, guest PC 0x0c0cad98 */
if(!s->budget--) { s->failed_pc=0x0c0cad98u; return 0; }
write(ram,r[14]+r[0],r[9],4);
goto P_0c0cad9a;
P_0c0cad9a: /* original 2fb2, guest PC 0x0c0cad9a */
if(!s->budget--) { s->failed_pc=0x0c0cad9au; return 0; }
write(ram,r[15],r[11],4);
goto P_0c0cad9c;
P_0c0cad9c: /* original 6ba3, guest PC 0x0c0cad9c */
if(!s->budget--) { s->failed_pc=0x0c0cad9cu; return 0; }
r[11]=r[10];
goto P_0c0cad9e;
P_0c0cad9e: /* original 4c0b, guest PC 0x0c0cad9e */
if(!s->budget--) { s->failed_pc=0x0c0cad9eu; return 0; }
target=r[12];
r[16]=code_base|0x0c0cada2u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cada2u) { target=s->pc; goto dispatch; }
goto P_0c0cada2;
P_0c0cada0: /* original 64f2, guest PC 0x0c0cada0 */
if(!s->budget--) { s->failed_pc=0x0c0cada0u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0cada2;
P_0c0cada2: /* original 8820, guest PC 0x0c0cada2 */
if(!s->budget--) { s->failed_pc=0x0c0cada2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c0cada4;
P_0c0cada4: /* original 8d1c, guest PC 0x0c0cada4 */
if(!s->budget--) { s->failed_pc=0x0c0cada4u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0cade0; }
goto P_0c0cada8;
P_0c0cada6: /* original 6403, guest PC 0x0c0cada6 */
if(!s->budget--) { s->failed_pc=0x0c0cada6u; return 0; }
r[4]=r[0];
goto P_0c0cada8;
P_0c0cada8: /* original 6043, guest PC 0x0c0cada8 */
if(!s->budget--) { s->failed_pc=0x0c0cada8u; return 0; }
r[0]=r[4];
goto P_0c0cadaa;
P_0c0cadaa: /* original 058c, guest PC 0x0c0cadaa */
if(!s->budget--) { s->failed_pc=0x0c0cadaau; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[8]+r[0],1);
goto P_0c0cadac;
P_0c0cadac: /* original 62f2, guest PC 0x0c0cadac */
if(!s->budget--) { s->failed_pc=0x0c0cadacu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0cadae;
P_0c0cadae: /* original 635b, guest PC 0x0c0cadae */
if(!s->budget--) { s->failed_pc=0x0c0cadaeu; return 0; }
r[3]=0u-r[5];
goto P_0c0cadb0;
P_0c0cadb0: /* original 65d3, guest PC 0x0c0cadb0 */
if(!s->budget--) { s->failed_pc=0x0c0cadb0u; return 0; }
r[5]=r[13];
goto P_0c0cadb2;
P_0c0cadb2: /* original 453d, guest PC 0x0c0cadb2 */
if(!s->budget--) { s->failed_pc=0x0c0cadb2u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c0cadb4;
P_0c0cadb4: /* original 634b, guest PC 0x0c0cadb4 */
if(!s->budget--) { s->failed_pc=0x0c0cadb4u; return 0; }
r[3]=0u-r[4];
goto P_0c0cadb6;
P_0c0cadb6: /* original 64d3, guest PC 0x0c0cadb6 */
if(!s->budget--) { s->failed_pc=0x0c0cadb6u; return 0; }
r[4]=r[13];
goto P_0c0cadb8;
P_0c0cadb8: /* original 443d, guest PC 0x0c0cadb8 */
if(!s->budget--) { s->failed_pc=0x0c0cadb8u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c0cadba;
P_0c0cadba: /* original 6447, guest PC 0x0c0cadba */
if(!s->budget--) { s->failed_pc=0x0c0cadbau; return 0; }
r[4]=~r[4];
goto P_0c0cadbc;
P_0c0cadbc: /* original 2429, guest PC 0x0c0cadbc */
if(!s->budget--) { s->failed_pc=0x0c0cadbcu; return 0; }
r[4]&=r[2];
goto P_0c0cadbe;
P_0c0cadbe: /* original 2b5b, guest PC 0x0c0cadbe */
if(!s->budget--) { s->failed_pc=0x0c0cadbeu; return 0; }
r[11]|=r[5];
goto P_0c0cadc0;
P_0c0cadc0: /* original afed, guest PC 0x0c0cadc0 */
if(!s->budget--) { s->failed_pc=0x0c0cadc0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0cad9e;
P_0c0cadc2: /* original 2f42, guest PC 0x0c0cadc2 */
if(!s->budget--) { s->failed_pc=0x0c0cadc2u; return 0; }
write(ram,r[15],r[4],4);
if(!vf3_matrix_family(0x0c0cadc4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0cadc4u; return 0; } return 1;
P_0c0cade0: /* original 9088, guest PC 0x0c0cade0 */
if(!s->budget--) { s->failed_pc=0x0c0cade0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caef4u,2);
goto P_0c0cade2;
P_0c0cade2: /* original 0eb6, guest PC 0x0c0cade2 */
if(!s->budget--) { s->failed_pc=0x0c0cade2u; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c0cade4;
P_0c0cade4: /* original 52f4, guest PC 0x0c0cade4 */
if(!s->budget--) { s->failed_pc=0x0c0cade4u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0cade6;
P_0c0cade6: /* original 9386, guest PC 0x0c0cade6 */
if(!s->budget--) { s->failed_pc=0x0c0cade6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caef6u,2);
goto P_0c0cade8;
P_0c0cade8: /* original fe8d, guest PC 0x0c0cade8 */
if(!s->budget--) { s->failed_pc=0x0c0cade8u; return 0; }
fr[14]=0;
goto P_0c0cadea;
P_0c0cadea: /* original 2238, guest PC 0x0c0cadea */
if(!s->budget--) { s->failed_pc=0x0c0cadeau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cadec;
P_0c0cadec: /* original ffec, guest PC 0x0c0cadec */
if(!s->budget--) { s->failed_pc=0x0c0cadecu; return 0; }
vf3_matrix_move(s,15,14);
goto P_0c0cadee;
P_0c0cadee: /* original 8f02, guest PC 0x0c0cadee */
if(!s->budget--) { s->failed_pc=0x0c0cadeeu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,13,14);
if(!cond) { goto P_0c0cadf6; }
goto P_0c0cadf2;
P_0c0cadf0: /* original fdec, guest PC 0x0c0cadf0 */
if(!s->budget--) { s->failed_pc=0x0c0cadf0u; return 0; }
vf3_matrix_move(s,13,14);
goto P_0c0cadf2;
P_0c0cadf2: /* original a0a1, guest PC 0x0c0cadf2 */
if(!s->budget--) { s->failed_pc=0x0c0cadf2u; return 0; }
goto P_0c0caf38;
P_0c0cadf4: /* original 0009, guest PC 0x0c0cadf4 */
if(!s->budget--) { s->failed_pc=0x0c0cadf4u; return 0; }
goto P_0c0cadf6;
P_0c0cadf6: /* original 50f7, guest PC 0x0c0cadf6 */
if(!s->budget--) { s->failed_pc=0x0c0cadf6u; return 0; }
r[0]=read(ram,r[15]+28,4);
goto P_0c0cadf8;
P_0c0cadf8: /* original e11c, guest PC 0x0c0cadf8 */
if(!s->budget--) { s->failed_pc=0x0c0cadf8u; return 0; }
r[1]=0x0000001cu;
goto P_0c0cadfa;
P_0c0cadfa: /* original 001c, guest PC 0x0c0cadfa */
if(!s->budget--) { s->failed_pc=0x0c0cadfau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0cadfc;
P_0c0cadfc: /* original 600c, guest PC 0x0c0cadfc */
if(!s->budget--) { s->failed_pc=0x0c0cadfcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0cadfe;
P_0c0cadfe: /* original c90f, guest PC 0x0c0cadfe */
if(!s->budget--) { s->failed_pc=0x0c0cadfeu; return 0; }
r[0]&=15u;
goto P_0c0cae00;
P_0c0cae00: /* original 8801, guest PC 0x0c0cae00 */
if(!s->budget--) { s->failed_pc=0x0c0cae00u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0cae02;
P_0c0cae02: /* original 8b26, guest PC 0x0c0cae02 */
if(!s->budget--) { s->failed_pc=0x0c0cae02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cae52; }
goto P_0c0cae04;
P_0c0cae04: /* original 63f3, guest PC 0x0c0cae04 */
if(!s->budget--) { s->failed_pc=0x0c0cae04u; return 0; }
r[3]=r[15];
goto P_0c0cae06;
P_0c0cae06: /* original 2f36, guest PC 0x0c0cae06 */
if(!s->budget--) { s->failed_pc=0x0c0cae06u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cae08;
P_0c0cae08: /* original 65f3, guest PC 0x0c0cae08 */
if(!s->budget--) { s->failed_pc=0x0c0cae08u; return 0; }
r[5]=r[15];
goto P_0c0cae0a;
P_0c0cae0a: /* original d23f, guest PC 0x0c0cae0a */
if(!s->budget--) { s->failed_pc=0x0c0cae0au; return 0; }
r[2]=read(ram,0x0c0caf08u,4);
goto P_0c0cae0c;
P_0c0cae0c: /* original 66f3, guest PC 0x0c0cae0c */
if(!s->budget--) { s->failed_pc=0x0c0cae0cu; return 0; }
r[6]=r[15];
goto P_0c0cae0e;
P_0c0cae0e: /* original 67f3, guest PC 0x0c0cae0e */
if(!s->budget--) { s->failed_pc=0x0c0cae0eu; return 0; }
r[7]=r[15];
goto P_0c0cae10;
P_0c0cae10: /* original 7508, guest PC 0x0c0cae10 */
if(!s->budget--) { s->failed_pc=0x0c0cae10u; return 0; }
r[5]+=0x00000008u;
goto P_0c0cae12;
P_0c0cae12: /* original 7610, guest PC 0x0c0cae12 */
if(!s->budget--) { s->failed_pc=0x0c0cae12u; return 0; }
r[6]+=0x00000010u;
goto P_0c0cae14;
P_0c0cae14: /* original 7718, guest PC 0x0c0cae14 */
if(!s->budget--) { s->failed_pc=0x0c0cae14u; return 0; }
r[7]+=0x00000018u;
goto P_0c0cae16;
P_0c0cae16: /* original 420b, guest PC 0x0c0cae16 */
if(!s->budget--) { s->failed_pc=0x0c0cae16u; return 0; }
target=r[2];
r[16]=code_base|0x0c0cae1au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cae1au) { target=s->pc; goto dispatch; }
goto P_0c0cae1a;
P_0c0cae18: /* original 64e3, guest PC 0x0c0cae18 */
if(!s->budget--) { s->failed_pc=0x0c0cae18u; return 0; }
r[4]=r[14];
goto P_0c0cae1a;
P_0c0cae1a: /* original 906d, guest PC 0x0c0cae1a */
if(!s->budget--) { s->failed_pc=0x0c0cae1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caef8u,2);
goto P_0c0cae1c;
P_0c0cae1c: /* original 7f04, guest PC 0x0c0cae1c */
if(!s->budget--) { s->failed_pc=0x0c0cae1cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0cae1e;
P_0c0cae1e: /* original f3e6, guest PC 0x0c0cae1e */
if(!s->budget--) { s->failed_pc=0x0c0cae1eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cae20;
P_0c0cae20: /* original e014, guest PC 0x0c0cae20 */
if(!s->budget--) { s->failed_pc=0x0c0cae20u; return 0; }
r[0]=0x00000014u;
goto P_0c0cae22;
P_0c0cae22: /* original ff37, guest PC 0x0c0cae22 */
if(!s->budget--) { s->failed_pc=0x0c0cae22u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cae24;
P_0c0cae24: /* original 9069, guest PC 0x0c0cae24 */
if(!s->budget--) { s->failed_pc=0x0c0cae24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caefau,2);
goto P_0c0cae26;
P_0c0cae26: /* original f4e6, guest PC 0x0c0cae26 */
if(!s->budget--) { s->failed_pc=0x0c0cae26u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0cae28;
P_0c0cae28: /* original e004, guest PC 0x0c0cae28 */
if(!s->budget--) { s->failed_pc=0x0c0cae28u; return 0; }
r[0]=0x00000004u;
goto P_0c0cae2a;
P_0c0cae2a: /* original f2f6, guest PC 0x0c0cae2a */
if(!s->budget--) { s->failed_pc=0x0c0cae2au; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0cae2c;
P_0c0cae2c: /* original e004, guest PC 0x0c0cae2c */
if(!s->budget--) { s->failed_pc=0x0c0cae2cu; return 0; }
r[0]=0x00000004u;
goto P_0c0cae2e;
P_0c0cae2e: /* original f44d, guest PC 0x0c0cae2e */
if(!s->budget--) { s->failed_pc=0x0c0cae2eu; return 0; }
fr[4]^=0x80000000u;
goto P_0c0cae30;
P_0c0cae30: /* original f231, guest PC 0x0c0cae30 */
if(!s->budget--) { s->failed_pc=0x0c0cae30u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0cae32;
P_0c0cae32: /* original ff27, guest PC 0x0c0cae32 */
if(!s->budget--) { s->failed_pc=0x0c0cae32u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0cae34;
P_0c0cae34: /* original e00c, guest PC 0x0c0cae34 */
if(!s->budget--) { s->failed_pc=0x0c0cae34u; return 0; }
r[0]=0x0000000cu;
goto P_0c0cae36;
P_0c0cae36: /* original f1f6, guest PC 0x0c0cae36 */
if(!s->budget--) { s->failed_pc=0x0c0cae36u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0cae38;
P_0c0cae38: /* original f222, guest PC 0x0c0cae38 */
if(!s->budget--) { s->failed_pc=0x0c0cae38u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[2],r[18],'*');
goto P_0c0cae3a;
P_0c0cae3a: /* original e00c, guest PC 0x0c0cae3a */
if(!s->budget--) { s->failed_pc=0x0c0cae3au; return 0; }
r[0]=0x0000000cu;
goto P_0c0cae3c;
P_0c0cae3c: /* original f141, guest PC 0x0c0cae3c */
if(!s->budget--) { s->failed_pc=0x0c0cae3cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0cae3e;
P_0c0cae3e: /* original ff17, guest PC 0x0c0cae3e */
if(!s->budget--) { s->failed_pc=0x0c0cae3eu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0cae40;
P_0c0cae40: /* original e004, guest PC 0x0c0cae40 */
if(!s->budget--) { s->failed_pc=0x0c0cae40u; return 0; }
r[0]=0x00000004u;
goto P_0c0cae42;
P_0c0cae42: /* original f32c, guest PC 0x0c0cae42 */
if(!s->budget--) { s->failed_pc=0x0c0cae42u; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c0cae44;
P_0c0cae44: /* original f01c, guest PC 0x0c0cae44 */
if(!s->budget--) { s->failed_pc=0x0c0cae44u; return 0; }
vf3_matrix_move(s,0,1);
goto P_0c0cae46;
P_0c0cae46: /* original f31e, guest PC 0x0c0cae46 */
if(!s->budget--) { s->failed_pc=0x0c0cae46u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[1],fr[3],r[18]);
goto P_0c0cae48;
P_0c0cae48: /* original ff37, guest PC 0x0c0cae48 */
if(!s->budget--) { s->failed_pc=0x0c0cae48u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cae4a;
P_0c0cae4a: /* original c730, guest PC 0x0c0cae4a */
if(!s->budget--) { s->failed_pc=0x0c0cae4au; return 0; }
r[0]=code_base|0x000caf0cu;
goto P_0c0cae4c;
P_0c0cae4c: /* original f408, guest PC 0x0c0cae4c */
if(!s->budget--) { s->failed_pc=0x0c0cae4cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0cae4e;
P_0c0cae4e: /* original f345, guest PC 0x0c0cae4e */
if(!s->budget--) { s->failed_pc=0x0c0cae4eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0cae50;
P_0c0cae50: /* original 8972, guest PC 0x0c0cae50 */
if(!s->budget--) { s->failed_pc=0x0c0cae50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caf38; }
goto P_0c0cae52;
P_0c0cae52: /* original 9053, guest PC 0x0c0cae52 */
if(!s->budget--) { s->failed_pc=0x0c0cae52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caefcu,2);
goto P_0c0cae54;
P_0c0cae54: /* original e506, guest PC 0x0c0cae54 */
if(!s->budget--) { s->failed_pc=0x0c0cae54u; return 0; }
r[5]=0x00000006u;
goto P_0c0cae56;
P_0c0cae56: /* original d32e, guest PC 0x0c0cae56 */
if(!s->budget--) { s->failed_pc=0x0c0cae56u; return 0; }
r[3]=read(ram,0x0c0caf10u,4);
goto P_0c0cae58;
P_0c0cae58: /* original 6453, guest PC 0x0c0cae58 */
if(!s->budget--) { s->failed_pc=0x0c0cae58u; return 0; }
r[4]=r[5];
goto P_0c0cae5a;
P_0c0cae5a: /* original f8e6, guest PC 0x0c0cae5a */
if(!s->budget--) { s->failed_pc=0x0c0cae5au; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0cae5c;
P_0c0cae5c: /* original 7004, guest PC 0x0c0cae5c */
if(!s->budget--) { s->failed_pc=0x0c0cae5cu; return 0; }
r[0]+=0x00000004u;
goto P_0c0cae5e;
P_0c0cae5e: /* original f7e6, guest PC 0x0c0cae5e */
if(!s->budget--) { s->failed_pc=0x0c0cae5eu; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0cae60;
P_0c0cae60: /* original 701b, guest PC 0x0c0cae60 */
if(!s->budget--) { s->failed_pc=0x0c0cae60u; return 0; }
r[0]+=0x0000001bu;
goto P_0c0cae62;
P_0c0cae62: /* original 07ec, guest PC 0x0c0cae62 */
if(!s->budget--) { s->failed_pc=0x0c0cae62u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0cae64;
P_0c0cae64: /* original 1f34, guest PC 0x0c0cae64 */
if(!s->budget--) { s->failed_pc=0x0c0cae64u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0cae66;
P_0c0cae66: /* original 677c, guest PC 0x0c0cae66 */
if(!s->budget--) { s->failed_pc=0x0c0cae66u; return 0; }
r[7]=r[7]&255u;
goto P_0c0cae68;
P_0c0cae68: /* original 6353, guest PC 0x0c0cae68 */
if(!s->budget--) { s->failed_pc=0x0c0cae68u; return 0; }
r[3]=r[5];
goto P_0c0cae6a;
P_0c0cae6a: /* original 3348, guest PC 0x0c0cae6a */
if(!s->budget--) { s->failed_pc=0x0c0cae6au; return 0; }
r[3]-=r[4];
goto P_0c0cae6c;
P_0c0cae6c: /* original 2f32, guest PC 0x0c0cae6c */
if(!s->budget--) { s->failed_pc=0x0c0cae6cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0cae6e;
P_0c0cae6e: /* original 56f4, guest PC 0x0c0cae6e */
if(!s->budget--) { s->failed_pc=0x0c0cae6eu; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c0cae70;
P_0c0cae70: /* original d228, guest PC 0x0c0cae70 */
if(!s->budget--) { s->failed_pc=0x0c0cae70u; return 0; }
r[2]=read(ram,0x0c0caf14u,4);
goto P_0c0cae72;
P_0c0cae72: /* original 363c, guest PC 0x0c0cae72 */
if(!s->budget--) { s->failed_pc=0x0c0cae72u; return 0; }
r[6]+=r[3];
goto P_0c0cae74;
P_0c0cae74: /* original 6160, guest PC 0x0c0cae74 */
if(!s->budget--) { s->failed_pc=0x0c0cae74u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[1]=tmp;
goto P_0c0cae76;
P_0c0cae76: /* original 420b, guest PC 0x0c0cae76 */
if(!s->budget--) { s->failed_pc=0x0c0cae76u; return 0; }
target=r[2];
r[16]=code_base|0x0c0cae7au;
r[0]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cae7au) { target=s->pc; goto dispatch; }
goto P_0c0cae7a;
P_0c0cae78: /* original e004, guest PC 0x0c0cae78 */
if(!s->budget--) { s->failed_pc=0x0c0cae78u; return 0; }
r[0]=0x00000004u;
goto P_0c0cae7a;
P_0c0cae7a: /* original 9340, guest PC 0x0c0cae7a */
if(!s->budget--) { s->failed_pc=0x0c0cae7au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caefeu,2);
goto P_0c0cae7c;
P_0c0cae7c: /* original 660e, guest PC 0x0c0cae7c */
if(!s->budget--) { s->failed_pc=0x0c0cae7cu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c0cae7e;
P_0c0cae7e: /* original 4608, guest PC 0x0c0cae7e */
if(!s->budget--) { s->failed_pc=0x0c0cae7eu; return 0; }
r[6]<<=2;
goto P_0c0cae80;
P_0c0cae80: /* original 33ec, guest PC 0x0c0cae80 */
if(!s->budget--) { s->failed_pc=0x0c0cae80u; return 0; }
r[3]+=r[14];
goto P_0c0cae82;
P_0c0cae82: /* original 363c, guest PC 0x0c0cae82 */
if(!s->budget--) { s->failed_pc=0x0c0cae82u; return 0; }
r[6]+=r[3];
goto P_0c0cae84;
P_0c0cae84: /* original 6662, guest PC 0x0c0cae84 */
if(!s->budget--) { s->failed_pc=0x0c0cae84u; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c0cae86;
P_0c0cae86: /* original e204, guest PC 0x0c0cae86 */
if(!s->budget--) { s->failed_pc=0x0c0cae86u; return 0; }
r[2]=0x00000004u;
goto P_0c0cae88;
P_0c0cae88: /* original 2628, guest PC 0x0c0cae88 */
if(!s->budget--) { s->failed_pc=0x0c0cae88u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c0cae8a;
P_0c0cae8a: /* original 8902, guest PC 0x0c0cae8a */
if(!s->budget--) { s->failed_pc=0x0c0cae8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cae92; }
goto P_0c0cae8c;
P_0c0cae8c: /* original f58c, guest PC 0x0c0cae8c */
if(!s->budget--) { s->failed_pc=0x0c0cae8cu; return 0; }
vf3_matrix_move(s,5,8);
goto P_0c0cae8e;
P_0c0cae8e: /* original a002, guest PC 0x0c0cae8e */
if(!s->budget--) { s->failed_pc=0x0c0cae8eu; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c0cae96;
P_0c0cae90: /* original f47c, guest PC 0x0c0cae90 */
if(!s->budget--) { s->failed_pc=0x0c0cae90u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c0cae92;
P_0c0cae92: /* original f48d, guest PC 0x0c0cae92 */
if(!s->budget--) { s->failed_pc=0x0c0cae92u; return 0; }
fr[4]=0;
goto P_0c0cae94;
P_0c0cae94: /* original f54c, guest PC 0x0c0cae94 */
if(!s->budget--) { s->failed_pc=0x0c0cae94u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0cae96;
P_0c0cae96: /* original 4410, guest PC 0x0c0cae96 */
if(!s->budget--) { s->failed_pc=0x0c0cae96u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c0cae98;
P_0c0cae98: /* original 8be6, guest PC 0x0c0cae98 */
if(!s->budget--) { s->failed_pc=0x0c0cae98u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cae68; }
goto P_0c0cae9a;
P_0c0cae9a: /* original 9332, guest PC 0x0c0cae9a */
if(!s->budget--) { s->failed_pc=0x0c0cae9au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caf02u,2);
goto P_0c0cae9c;
P_0c0cae9c: /* original e41c, guest PC 0x0c0cae9c */
if(!s->budget--) { s->failed_pc=0x0c0cae9cu; return 0; }
r[4]=0x0000001cu;
goto P_0c0cae9e;
P_0c0cae9e: /* original 902f, guest PC 0x0c0cae9e */
if(!s->budget--) { s->failed_pc=0x0c0cae9eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caf00u,2);
goto P_0c0caea0;
P_0c0caea0: /* original 33ec, guest PC 0x0c0caea0 */
if(!s->budget--) { s->failed_pc=0x0c0caea0u; return 0; }
r[3]+=r[14];
goto P_0c0caea2;
P_0c0caea2: /* original 05ee, guest PC 0x0c0caea2 */
if(!s->budget--) { s->failed_pc=0x0c0caea2u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0caea4;
P_0c0caea4: /* original 1f32, guest PC 0x0c0caea4 */
if(!s->budget--) { s->failed_pc=0x0c0caea4u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0caea6;
P_0c0caea6: /* original 922d, guest PC 0x0c0caea6 */
if(!s->budget--) { s->failed_pc=0x0c0caea6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caf04u,2);
goto P_0c0caea8;
P_0c0caea8: /* original 32ec, guest PC 0x0c0caea8 */
if(!s->budget--) { s->failed_pc=0x0c0caea8u; return 0; }
r[2]+=r[14];
goto P_0c0caeaa;
P_0c0caeaa: /* original 1f24, guest PC 0x0c0caeaa */
if(!s->budget--) { s->failed_pc=0x0c0caeaau; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0caeac;
P_0c0caeac: /* original 53f2, guest PC 0x0c0caeac */
if(!s->budget--) { s->failed_pc=0x0c0caeacu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0caeae;
P_0c0caeae: /* original e004, guest PC 0x0c0caeae */
if(!s->budget--) { s->failed_pc=0x0c0caeaeu; return 0; }
r[0]=0x00000004u;
goto P_0c0caeb0;
P_0c0caeb0: /* original f656, guest PC 0x0c0caeb0 */
if(!s->budget--) { s->failed_pc=0x0c0caeb0u; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c0caeb2;
P_0c0caeb2: /* original 7304, guest PC 0x0c0caeb2 */
if(!s->budget--) { s->failed_pc=0x0c0caeb2u; return 0; }
r[3]+=0x00000004u;
goto P_0c0caeb4;
P_0c0caeb4: /* original 1f32, guest PC 0x0c0caeb4 */
if(!s->budget--) { s->failed_pc=0x0c0caeb4u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0caeb6;
P_0c0caeb6: /* original 73fc, guest PC 0x0c0caeb6 */
if(!s->budget--) { s->failed_pc=0x0c0caeb6u; return 0; }
r[3]+=0xfffffffcu;
goto P_0c0caeb8;
P_0c0caeb8: /* original 52f4, guest PC 0x0c0caeb8 */
if(!s->budget--) { s->failed_pc=0x0c0caeb8u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0caeba;
P_0c0caeba: /* original fa38, guest PC 0x0c0caeba */
if(!s->budget--) { s->failed_pc=0x0c0caebau; return 0; }
vf3_matrix_load(s,ram,10,r[3]);
goto P_0c0caebc;
P_0c0caebc: /* original 7204, guest PC 0x0c0caebc */
if(!s->budget--) { s->failed_pc=0x0c0caebcu; return 0; }
r[2]+=0x00000004u;
goto P_0c0caebe;
P_0c0caebe: /* original f6a1, guest PC 0x0c0caebe */
if(!s->budget--) { s->failed_pc=0x0c0caebeu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[10],r[18],'-');
goto P_0c0caec0;
P_0c0caec0: /* original 1f24, guest PC 0x0c0caec0 */
if(!s->budget--) { s->failed_pc=0x0c0caec0u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0caec2;
P_0c0caec2: /* original 72fc, guest PC 0x0c0caec2 */
if(!s->budget--) { s->failed_pc=0x0c0caec2u; return 0; }
r[2]+=0xfffffffcu;
goto P_0c0caec4;
P_0c0caec4: /* original f928, guest PC 0x0c0caec4 */
if(!s->budget--) { s->failed_pc=0x0c0caec4u; return 0; }
vf3_matrix_load(s,ram,9,r[2]);
goto P_0c0caec6;
P_0c0caec6: /* original f965, guest PC 0x0c0caec6 */
if(!s->budget--) { s->failed_pc=0x0c0caec6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[6]))!=0);
goto P_0c0caec8;
P_0c0caec8: /* original 8f2a, guest PC 0x0c0caec8 */
if(!s->budget--) { s->failed_pc=0x0c0caec8u; return 0; }
cond=r[17]&1u;
r[5]+=0x0000000cu;
if(!cond) { goto P_0c0caf20; }
goto P_0c0caecc;
P_0c0caeca: /* original 750c, guest PC 0x0c0caeca */
if(!s->budget--) { s->failed_pc=0x0c0caecau; return 0; }
r[5]+=0x0000000cu;
goto P_0c0caecc;
P_0c0caecc: /* original f961, guest PC 0x0c0caecc */
if(!s->budget--) { s->failed_pc=0x0c0caeccu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[6],r[18],'-');
goto P_0c0caece;
P_0c0caece: /* original e004, guest PC 0x0c0caece */
if(!s->budget--) { s->failed_pc=0x0c0caeceu; return 0; }
r[0]=0x00000004u;
goto P_0c0caed0;
P_0c0caed0: /* original f39c, guest PC 0x0c0caed0 */
if(!s->budget--) { s->failed_pc=0x0c0caed0u; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c0caed2;
P_0c0caed2: /* original f3f5, guest PC 0x0c0caed2 */
if(!s->budget--) { s->failed_pc=0x0c0caed2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0caed4;
P_0c0caed4: /* original 8f24, guest PC 0x0c0caed4 */
if(!s->budget--) { s->failed_pc=0x0c0caed4u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,9,r[15]+r[0]);
if(!cond) { goto P_0c0caf20; }
goto P_0c0caed8;
P_0c0caed6: /* original ff97, guest PC 0x0c0caed6 */
if(!s->budget--) { s->failed_pc=0x0c0caed6u; return 0; }
vf3_matrix_store(s,ram,9,r[15]+r[0]);
goto P_0c0caed8;
P_0c0caed8: /* original 6043, guest PC 0x0c0caed8 */
if(!s->budget--) { s->failed_pc=0x0c0caed8u; return 0; }
r[0]=r[4];
goto P_0c0caeda;
P_0c0caeda: /* original 880d, guest PC 0x0c0caeda */
if(!s->budget--) { s->failed_pc=0x0c0caedau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0caedc;
P_0c0caedc: /* original f58c, guest PC 0x0c0caedc */
if(!s->budget--) { s->failed_pc=0x0c0caedcu; return 0; }
vf3_matrix_move(s,5,8);
goto P_0c0caede;
P_0c0caede: /* original 8d1d, guest PC 0x0c0caede */
if(!s->budget--) { s->failed_pc=0x0c0caedeu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,7);
if(cond) { goto P_0c0caf1c; }
goto P_0c0caee2;
P_0c0caee0: /* original f47c, guest PC 0x0c0caee0 */
if(!s->budget--) { s->failed_pc=0x0c0caee0u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c0caee2;
P_0c0caee2: /* original e30d, guest PC 0x0c0caee2 */
if(!s->budget--) { s->failed_pc=0x0c0caee2u; return 0; }
r[3]=0x0000000du;
goto P_0c0caee4;
P_0c0caee4: /* original 3437, guest PC 0x0c0caee4 */
if(!s->budget--) { s->failed_pc=0x0c0caee4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c0caee6;
P_0c0caee6: /* original e602, guest PC 0x0c0caee6 */
if(!s->budget--) { s->failed_pc=0x0c0caee6u; return 0; }
r[6]=0x00000002u;
goto P_0c0caee8;
P_0c0caee8: /* original 8d16, guest PC 0x0c0caee8 */
if(!s->budget--) { s->failed_pc=0x0c0caee8u; return 0; }
cond=r[17]&1u;
r[6]&=r[7];
if(cond) { goto P_0c0caf18; }
goto P_0c0caeec;
P_0c0caeea: /* original 2679, guest PC 0x0c0caeea */
if(!s->budget--) { s->failed_pc=0x0c0caeeau; return 0; }
r[6]&=r[7];
goto P_0c0caeec;
P_0c0caeec: /* original 2668, guest PC 0x0c0caeec */
if(!s->budget--) { s->failed_pc=0x0c0caeecu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0caeee;
P_0c0caeee: /* original 8b17, guest PC 0x0c0caeee */
if(!s->budget--) { s->failed_pc=0x0c0caeeeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0caf20; }
goto P_0c0caef0;
P_0c0caef0: /* original a014, guest PC 0x0c0caef0 */
if(!s->budget--) { s->failed_pc=0x0c0caef0u; return 0; }
goto P_0c0caf1c;
P_0c0caef2: /* original 0009, guest PC 0x0c0caef2 */
if(!s->budget--) { s->failed_pc=0x0c0caef2u; return 0; }
if(!vf3_matrix_family(0x0c0caef4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0caef4u; return 0; } return 1;
P_0c0caf18: /* original 2668, guest PC 0x0c0caf18 */
if(!s->budget--) { s->failed_pc=0x0c0caf18u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0caf1a;
P_0c0caf1a: /* original 8901, guest PC 0x0c0caf1a */
if(!s->budget--) { s->failed_pc=0x0c0caf1au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caf20; }
goto P_0c0caf1c;
P_0c0caf1c: /* original e004, guest PC 0x0c0caf1c */
if(!s->budget--) { s->failed_pc=0x0c0caf1cu; return 0; }
r[0]=0x00000004u;
goto P_0c0caf1e;
P_0c0caf1e: /* original fff6, guest PC 0x0c0caf1e */
if(!s->budget--) { s->failed_pc=0x0c0caf1eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]+r[0]);
goto P_0c0caf20;
P_0c0caf20: /* original 4410, guest PC 0x0c0caf20 */
if(!s->budget--) { s->failed_pc=0x0c0caf20u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c0caf22;
P_0c0caf22: /* original 8bc3, guest PC 0x0c0caf22 */
if(!s->budget--) { s->failed_pc=0x0c0caf22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0caeac; }
goto P_0c0caf24;
P_0c0caf24: /* original 62e2, guest PC 0x0c0caf24 */
if(!s->budget--) { s->failed_pc=0x0c0caf24u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0caf26;
P_0c0caf26: /* original 9383, guest PC 0x0c0caf26 */
if(!s->budget--) { s->failed_pc=0x0c0caf26u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb030u,2);
goto P_0c0caf28;
P_0c0caf28: /* original 2238, guest PC 0x0c0caf28 */
if(!s->budget--) { s->failed_pc=0x0c0caf28u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0caf2a;
P_0c0caf2a: /* original 8903, guest PC 0x0c0caf2a */
if(!s->budget--) { s->failed_pc=0x0c0caf2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caf34; }
goto P_0c0caf2c;
P_0c0caf2c: /* original c742, guest PC 0x0c0caf2c */
if(!s->budget--) { s->failed_pc=0x0c0caf2cu; return 0; }
r[0]=code_base|0x000cb038u;
goto P_0c0caf2e;
P_0c0caf2e: /* original f608, guest PC 0x0c0caf2e */
if(!s->budget--) { s->failed_pc=0x0c0caf2eu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0caf30;
P_0c0caf30: /* original f462, guest PC 0x0c0caf30 */
if(!s->budget--) { s->failed_pc=0x0c0caf30u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0caf32;
P_0c0caf32: /* original f562, guest PC 0x0c0caf32 */
if(!s->budget--) { s->failed_pc=0x0c0caf32u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c0caf34;
P_0c0caf34: /* original fe4c, guest PC 0x0c0caf34 */
if(!s->budget--) { s->failed_pc=0x0c0caf34u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c0caf36;
P_0c0caf36: /* original fd5c, guest PC 0x0c0caf36 */
if(!s->budget--) { s->failed_pc=0x0c0caf36u; return 0; }
vf3_matrix_move(s,13,5);
goto P_0c0caf38;
P_0c0caf38: /* original 907b, guest PC 0x0c0caf38 */
if(!s->budget--) { s->failed_pc=0x0c0caf38u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb032u,2);
goto P_0c0caf3a;
P_0c0caf3a: /* original 7f3c, guest PC 0x0c0caf3a */
if(!s->budget--) { s->failed_pc=0x0c0caf3au; return 0; }
r[15]+=0x0000003cu;
goto P_0c0caf3c;
P_0c0caf3c: /* original 4f26, guest PC 0x0c0caf3c */
if(!s->budget--) { s->failed_pc=0x0c0caf3cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0caf3e;
P_0c0caf3e: /* original fed7, guest PC 0x0c0caf3e */
if(!s->budget--) { s->failed_pc=0x0c0caf3eu; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c0caf40;
P_0c0caf40: /* original 7004, guest PC 0x0c0caf40 */
if(!s->budget--) { s->failed_pc=0x0c0caf40u; return 0; }
r[0]+=0x00000004u;
goto P_0c0caf42;
P_0c0caf42: /* original fef7, guest PC 0x0c0caf42 */
if(!s->budget--) { s->failed_pc=0x0c0caf42u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0caf44;
P_0c0caf44: /* original 7004, guest PC 0x0c0caf44 */
if(!s->budget--) { s->failed_pc=0x0c0caf44u; return 0; }
r[0]+=0x00000004u;
goto P_0c0caf46;
P_0c0caf46: /* original fee7, guest PC 0x0c0caf46 */
if(!s->budget--) { s->failed_pc=0x0c0caf46u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c0caf48;
P_0c0caf48: /* original fdf9, guest PC 0x0c0caf48 */
if(!s->budget--) { s->failed_pc=0x0c0caf48u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0caf4a;
P_0c0caf4a: /* original fef9, guest PC 0x0c0caf4a */
if(!s->budget--) { s->failed_pc=0x0c0caf4au; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0caf4c;
P_0c0caf4c: /* original fff9, guest PC 0x0c0caf4c */
if(!s->budget--) { s->failed_pc=0x0c0caf4cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0caf4e;
P_0c0caf4e: /* original 68f6, guest PC 0x0c0caf4e */
if(!s->budget--) { s->failed_pc=0x0c0caf4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0caf50;
P_0c0caf50: /* original 69f6, guest PC 0x0c0caf50 */
if(!s->budget--) { s->failed_pc=0x0c0caf50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0caf52;
P_0c0caf52: /* original 6af6, guest PC 0x0c0caf52 */
if(!s->budget--) { s->failed_pc=0x0c0caf52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0caf54;
P_0c0caf54: /* original 6bf6, guest PC 0x0c0caf54 */
if(!s->budget--) { s->failed_pc=0x0c0caf54u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0caf56;
P_0c0caf56: /* original 6cf6, guest PC 0x0c0caf56 */
if(!s->budget--) { s->failed_pc=0x0c0caf56u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0caf58;
P_0c0caf58: /* original 6df6, guest PC 0x0c0caf58 */
if(!s->budget--) { s->failed_pc=0x0c0caf58u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0caf5a;
P_0c0caf5a: /* original 000b, guest PC 0x0c0caf5a */
if(!s->budget--) { s->failed_pc=0x0c0caf5au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0caf5c: /* original 6ef6, guest PC 0x0c0caf5c */
if(!s->budget--) { s->failed_pc=0x0c0caf5cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0caf5eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0caf5eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
