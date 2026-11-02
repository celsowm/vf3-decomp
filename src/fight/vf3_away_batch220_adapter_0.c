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
int vf3_away_batch220_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0afb62u: goto P_0c0afb62;
case 0x0c0afb64u: goto P_0c0afb64;
case 0x0c0afb66u: goto P_0c0afb66;
case 0x0c0afb68u: goto P_0c0afb68;
case 0x0c0afb6au: goto P_0c0afb6a;
case 0x0c0afb6cu: goto P_0c0afb6c;
case 0x0c0afb6eu: goto P_0c0afb6e;
case 0x0c0afb70u: goto P_0c0afb70;
case 0x0c0afb72u: goto P_0c0afb72;
case 0x0c0afb74u: goto P_0c0afb74;
case 0x0c0afb76u: goto P_0c0afb76;
case 0x0c0afb78u: goto P_0c0afb78;
case 0x0c0afb7au: goto P_0c0afb7a;
case 0x0c0afb7cu: goto P_0c0afb7c;
case 0x0c0afb7eu: goto P_0c0afb7e;
case 0x0c0afb80u: goto P_0c0afb80;
case 0x0c0afb82u: goto P_0c0afb82;
case 0x0c0afb84u: goto P_0c0afb84;
case 0x0c0afb86u: goto P_0c0afb86;
case 0x0c0afb88u: goto P_0c0afb88;
case 0x0c0afb8au: goto P_0c0afb8a;
case 0x0c0afb8cu: goto P_0c0afb8c;
case 0x0c0afb8eu: goto P_0c0afb8e;
case 0x0c0afb90u: goto P_0c0afb90;
case 0x0c0afb92u: goto P_0c0afb92;
case 0x0c0afb94u: goto P_0c0afb94;
case 0x0c0afb96u: goto P_0c0afb96;
case 0x0c0afb98u: goto P_0c0afb98;
case 0x0c0afb9au: goto P_0c0afb9a;
case 0x0c0afb9cu: goto P_0c0afb9c;
case 0x0c0afb9eu: goto P_0c0afb9e;
case 0x0c0afba0u: goto P_0c0afba0;
case 0x0c0afba2u: goto P_0c0afba2;
case 0x0c0afba4u: goto P_0c0afba4;
case 0x0c0afba6u: goto P_0c0afba6;
case 0x0c0afba8u: goto P_0c0afba8;
case 0x0c0afbaau: goto P_0c0afbaa;
case 0x0c0afbacu: goto P_0c0afbac;
case 0x0c0afbaeu: goto P_0c0afbae;
case 0x0c0afbb0u: goto P_0c0afbb0;
case 0x0c0afbb2u: goto P_0c0afbb2;
case 0x0c0afbb4u: goto P_0c0afbb4;
case 0x0c0afbb6u: goto P_0c0afbb6;
case 0x0c0afbb8u: goto P_0c0afbb8;
case 0x0c0afbbau: goto P_0c0afbba;
case 0x0c0afbbcu: goto P_0c0afbbc;
case 0x0c0afbbeu: goto P_0c0afbbe;
case 0x0c0afbc0u: goto P_0c0afbc0;
case 0x0c0afbc2u: goto P_0c0afbc2;
case 0x0c0afbc4u: goto P_0c0afbc4;
case 0x0c0afbc6u: goto P_0c0afbc6;
case 0x0c0afbc8u: goto P_0c0afbc8;
case 0x0c0afbcau: goto P_0c0afbca;
case 0x0c0afbccu: goto P_0c0afbcc;
case 0x0c0afbceu: goto P_0c0afbce;
case 0x0c0afbd0u: goto P_0c0afbd0;
case 0x0c0afbd2u: goto P_0c0afbd2;
case 0x0c0afbd4u: goto P_0c0afbd4;
case 0x0c0afbd6u: goto P_0c0afbd6;
case 0x0c0afbd8u: goto P_0c0afbd8;
case 0x0c0afbdau: goto P_0c0afbda;
case 0x0c0afbdcu: goto P_0c0afbdc;
case 0x0c0afbdeu: goto P_0c0afbde;
case 0x0c0afbe0u: goto P_0c0afbe0;
case 0x0c0afbe2u: goto P_0c0afbe2;
case 0x0c0afbe4u: goto P_0c0afbe4;
case 0x0c0afbe6u: goto P_0c0afbe6;
case 0x0c0afbe8u: goto P_0c0afbe8;
case 0x0c0afbeau: goto P_0c0afbea;
case 0x0c0afbecu: goto P_0c0afbec;
case 0x0c0afbeeu: goto P_0c0afbee;
case 0x0c0afbf0u: goto P_0c0afbf0;
case 0x0c0afbf2u: goto P_0c0afbf2;
case 0x0c0afbf4u: goto P_0c0afbf4;
case 0x0c0afbf6u: goto P_0c0afbf6;
case 0x0c0afbf8u: goto P_0c0afbf8;
case 0x0c0afbfau: goto P_0c0afbfa;
case 0x0c0afbfcu: goto P_0c0afbfc;
case 0x0c0afbfeu: goto P_0c0afbfe;
case 0x0c0afc00u: goto P_0c0afc00;
case 0x0c0afc02u: goto P_0c0afc02;
case 0x0c0afc04u: goto P_0c0afc04;
case 0x0c0afc06u: goto P_0c0afc06;
case 0x0c0afc08u: goto P_0c0afc08;
case 0x0c0afc0au: goto P_0c0afc0a;
case 0x0c0afc0cu: goto P_0c0afc0c;
case 0x0c0afc0eu: goto P_0c0afc0e;
case 0x0c0afc10u: goto P_0c0afc10;
case 0x0c0afc12u: goto P_0c0afc12;
case 0x0c0afc14u: goto P_0c0afc14;
case 0x0c0afc16u: goto P_0c0afc16;
case 0x0c0afc18u: goto P_0c0afc18;
case 0x0c0afc1au: goto P_0c0afc1a;
case 0x0c0afc1cu: goto P_0c0afc1c;
case 0x0c0afc1eu: goto P_0c0afc1e;
case 0x0c0afc20u: goto P_0c0afc20;
case 0x0c0afc22u: goto P_0c0afc22;
case 0x0c0afc24u: goto P_0c0afc24;
case 0x0c0afc26u: goto P_0c0afc26;
case 0x0c0afc28u: goto P_0c0afc28;
case 0x0c0afc2au: goto P_0c0afc2a;
case 0x0c0afc2cu: goto P_0c0afc2c;
case 0x0c0afc2eu: goto P_0c0afc2e;
case 0x0c0afc30u: goto P_0c0afc30;
case 0x0c0afc32u: goto P_0c0afc32;
case 0x0c0afc34u: goto P_0c0afc34;
case 0x0c0afc36u: goto P_0c0afc36;
case 0x0c0afc38u: goto P_0c0afc38;
case 0x0c0afc3au: goto P_0c0afc3a;
case 0x0c0afc3cu: goto P_0c0afc3c;
case 0x0c0afc3eu: goto P_0c0afc3e;
case 0x0c0afc40u: goto P_0c0afc40;
case 0x0c0afc42u: goto P_0c0afc42;
case 0x0c0afc44u: goto P_0c0afc44;
case 0x0c0afc74u: goto P_0c0afc74;
case 0x0c0afc76u: goto P_0c0afc76;
case 0x0c0afc78u: goto P_0c0afc78;
case 0x0c0afc7au: goto P_0c0afc7a;
case 0x0c0afc7cu: goto P_0c0afc7c;
case 0x0c0afc7eu: goto P_0c0afc7e;
case 0x0c0afc80u: goto P_0c0afc80;
case 0x0c0afc82u: goto P_0c0afc82;
case 0x0c0afc84u: goto P_0c0afc84;
case 0x0c0afc86u: goto P_0c0afc86;
case 0x0c0afc88u: goto P_0c0afc88;
case 0x0c0afc8au: goto P_0c0afc8a;
case 0x0c0afc8cu: goto P_0c0afc8c;
case 0x0c0afc8eu: goto P_0c0afc8e;
case 0x0c0afc90u: goto P_0c0afc90;
case 0x0c0afc92u: goto P_0c0afc92;
case 0x0c0afc94u: goto P_0c0afc94;
case 0x0c0afc96u: goto P_0c0afc96;
case 0x0c0afc98u: goto P_0c0afc98;
case 0x0c0afc9au: goto P_0c0afc9a;
case 0x0c0afc9cu: goto P_0c0afc9c;
case 0x0c0afc9eu: goto P_0c0afc9e;
case 0x0c0afca0u: goto P_0c0afca0;
case 0x0c0afca2u: goto P_0c0afca2;
case 0x0c0afca4u: goto P_0c0afca4;
case 0x0c0afca6u: goto P_0c0afca6;
case 0x0c0afca8u: goto P_0c0afca8;
case 0x0c0afcaau: goto P_0c0afcaa;
case 0x0c0afcacu: goto P_0c0afcac;
case 0x0c0afcaeu: goto P_0c0afcae;
case 0x0c0afcb0u: goto P_0c0afcb0;
case 0x0c0afcb2u: goto P_0c0afcb2;
case 0x0c0afcb4u: goto P_0c0afcb4;
case 0x0c0afcb6u: goto P_0c0afcb6;
case 0x0c0afcb8u: goto P_0c0afcb8;
case 0x0c0afcbau: goto P_0c0afcba;
case 0x0c0afcbcu: goto P_0c0afcbc;
case 0x0c0afcbeu: goto P_0c0afcbe;
case 0x0c0afcc0u: goto P_0c0afcc0;
case 0x0c0afcc2u: goto P_0c0afcc2;
case 0x0c0afcc4u: goto P_0c0afcc4;
case 0x0c0afcc6u: goto P_0c0afcc6;
case 0x0c0afcc8u: goto P_0c0afcc8;
case 0x0c0afccau: goto P_0c0afcca;
case 0x0c0afcccu: goto P_0c0afccc;
case 0x0c0afcceu: goto P_0c0afcce;
case 0x0c0afcd0u: goto P_0c0afcd0;
case 0x0c0afcd2u: goto P_0c0afcd2;
case 0x0c0afcd4u: goto P_0c0afcd4;
case 0x0c0afcd6u: goto P_0c0afcd6;
case 0x0c0afcd8u: goto P_0c0afcd8;
case 0x0c0afcdau: goto P_0c0afcda;
case 0x0c0afcdcu: goto P_0c0afcdc;
case 0x0c0afcdeu: goto P_0c0afcde;
case 0x0c0afce0u: goto P_0c0afce0;
case 0x0c0afce2u: goto P_0c0afce2;
case 0x0c0afce4u: goto P_0c0afce4;
case 0x0c0afce6u: goto P_0c0afce6;
case 0x0c0afce8u: goto P_0c0afce8;
case 0x0c0afceau: goto P_0c0afcea;
case 0x0c0afcecu: goto P_0c0afcec;
case 0x0c0afceeu: goto P_0c0afcee;
case 0x0c0afcf0u: goto P_0c0afcf0;
case 0x0c0afcf2u: goto P_0c0afcf2;
case 0x0c0afcf4u: goto P_0c0afcf4;
case 0x0c0afcf6u: goto P_0c0afcf6;
case 0x0c0afcf8u: goto P_0c0afcf8;
case 0x0c0afcfau: goto P_0c0afcfa;
case 0x0c0afcfcu: goto P_0c0afcfc;
case 0x0c0afcfeu: goto P_0c0afcfe;
case 0x0c0afd00u: goto P_0c0afd00;
case 0x0c0afd02u: goto P_0c0afd02;
case 0x0c0afd04u: goto P_0c0afd04;
case 0x0c0afd06u: goto P_0c0afd06;
case 0x0c0afd08u: goto P_0c0afd08;
case 0x0c0afd0au: goto P_0c0afd0a;
case 0x0c0afd0cu: goto P_0c0afd0c;
case 0x0c0afd0eu: goto P_0c0afd0e;
case 0x0c0afd10u: goto P_0c0afd10;
case 0x0c0afd12u: goto P_0c0afd12;
case 0x0c0afd14u: goto P_0c0afd14;
case 0x0c0afd16u: goto P_0c0afd16;
case 0x0c0afd18u: goto P_0c0afd18;
case 0x0c0afd1au: goto P_0c0afd1a;
case 0x0c0afd1cu: goto P_0c0afd1c;
case 0x0c0afd1eu: goto P_0c0afd1e;
case 0x0c0afd20u: goto P_0c0afd20;
case 0x0c0afd22u: goto P_0c0afd22;
case 0x0c0afd24u: goto P_0c0afd24;
case 0x0c0afd26u: goto P_0c0afd26;
case 0x0c0afd28u: goto P_0c0afd28;
case 0x0c0afd2au: goto P_0c0afd2a;
case 0x0c0afd2cu: goto P_0c0afd2c;
case 0x0c0afd2eu: goto P_0c0afd2e;
case 0x0c0afd30u: goto P_0c0afd30;
case 0x0c0afd32u: goto P_0c0afd32;
case 0x0c0afd34u: goto P_0c0afd34;
case 0x0c0afd36u: goto P_0c0afd36;
case 0x0c0afd38u: goto P_0c0afd38;
case 0x0c0afd3au: goto P_0c0afd3a;
case 0x0c0afd3cu: goto P_0c0afd3c;
case 0x0c0afd3eu: goto P_0c0afd3e;
case 0x0c0afd40u: goto P_0c0afd40;
case 0x0c0afd42u: goto P_0c0afd42;
case 0x0c0afd44u: goto P_0c0afd44;
case 0x0c0afd46u: goto P_0c0afd46;
case 0x0c0afd48u: goto P_0c0afd48;
case 0x0c0afd4au: goto P_0c0afd4a;
case 0x0c0afd4cu: goto P_0c0afd4c;
case 0x0c0afd6cu: goto P_0c0afd6c;
case 0x0c0afd6eu: goto P_0c0afd6e;
case 0x0c0afd70u: goto P_0c0afd70;
case 0x0c0afd72u: goto P_0c0afd72;
case 0x0c0afd74u: goto P_0c0afd74;
case 0x0c0afd76u: goto P_0c0afd76;
case 0x0c0afd78u: goto P_0c0afd78;
case 0x0c0afd7au: goto P_0c0afd7a;
case 0x0c0afd7cu: goto P_0c0afd7c;
case 0x0c0afd7eu: goto P_0c0afd7e;
case 0x0c0afd80u: goto P_0c0afd80;
case 0x0c0afd82u: goto P_0c0afd82;
case 0x0c0afd84u: goto P_0c0afd84;
case 0x0c0afd86u: goto P_0c0afd86;
case 0x0c0afd88u: goto P_0c0afd88;
case 0x0c0afd8au: goto P_0c0afd8a;
case 0x0c0afd8cu: goto P_0c0afd8c;
case 0x0c0afd8eu: goto P_0c0afd8e;
case 0x0c0afd90u: goto P_0c0afd90;
case 0x0c0afd92u: goto P_0c0afd92;
case 0x0c0afd94u: goto P_0c0afd94;
case 0x0c0afd96u: goto P_0c0afd96;
case 0x0c0afd98u: goto P_0c0afd98;
case 0x0c0afd9au: goto P_0c0afd9a;
case 0x0c0afd9cu: goto P_0c0afd9c;
case 0x0c0afd9eu: goto P_0c0afd9e;
case 0x0c0afda0u: goto P_0c0afda0;
case 0x0c0afda2u: goto P_0c0afda2;
case 0x0c0afda4u: goto P_0c0afda4;
case 0x0c0afda6u: goto P_0c0afda6;
case 0x0c0afda8u: goto P_0c0afda8;
case 0x0c0afdaau: goto P_0c0afdaa;
case 0x0c0afdacu: goto P_0c0afdac;
case 0x0c0afdaeu: goto P_0c0afdae;
case 0x0c0afdb0u: goto P_0c0afdb0;
case 0x0c0afdb2u: goto P_0c0afdb2;
case 0x0c0afdb4u: goto P_0c0afdb4;
case 0x0c0afdb6u: goto P_0c0afdb6;
case 0x0c0afdb8u: goto P_0c0afdb8;
case 0x0c0afdbau: goto P_0c0afdba;
case 0x0c0afdbcu: goto P_0c0afdbc;
case 0x0c0afdbeu: goto P_0c0afdbe;
case 0x0c0afdc0u: goto P_0c0afdc0;
case 0x0c0afdc2u: goto P_0c0afdc2;
case 0x0c0afdc4u: goto P_0c0afdc4;
case 0x0c0afdc6u: goto P_0c0afdc6;
case 0x0c0afdc8u: goto P_0c0afdc8;
case 0x0c0afdcau: goto P_0c0afdca;
case 0x0c0afdccu: goto P_0c0afdcc;
case 0x0c0afdceu: goto P_0c0afdce;
case 0x0c0afdd0u: goto P_0c0afdd0;
case 0x0c0afdd2u: goto P_0c0afdd2;
case 0x0c0afdd4u: goto P_0c0afdd4;
case 0x0c0afdd6u: goto P_0c0afdd6;
case 0x0c0afdd8u: goto P_0c0afdd8;
case 0x0c0afddau: goto P_0c0afdda;
case 0x0c0afddcu: goto P_0c0afddc;
case 0x0c0afddeu: goto P_0c0afdde;
case 0x0c0afde0u: goto P_0c0afde0;
case 0x0c0afde2u: goto P_0c0afde2;
case 0x0c0afde4u: goto P_0c0afde4;
case 0x0c0afde6u: goto P_0c0afde6;
case 0x0c0afde8u: goto P_0c0afde8;
case 0x0c0afdeau: goto P_0c0afdea;
case 0x0c0afdecu: goto P_0c0afdec;
case 0x0c0afdeeu: goto P_0c0afdee;
case 0x0c0afdf0u: goto P_0c0afdf0;
case 0x0c0afdf2u: goto P_0c0afdf2;
case 0x0c0afdf4u: goto P_0c0afdf4;
case 0x0c0afdf6u: goto P_0c0afdf6;
case 0x0c0afdf8u: goto P_0c0afdf8;
case 0x0c0afdfau: goto P_0c0afdfa;
case 0x0c0afdfcu: goto P_0c0afdfc;
case 0x0c0afdfeu: goto P_0c0afdfe;
case 0x0c0afe00u: goto P_0c0afe00;
case 0x0c0afe02u: goto P_0c0afe02;
case 0x0c0afe04u: goto P_0c0afe04;
case 0x0c0afe06u: goto P_0c0afe06;
case 0x0c0afe08u: goto P_0c0afe08;
case 0x0c0afe0au: goto P_0c0afe0a;
case 0x0c0afe0cu: goto P_0c0afe0c;
case 0x0c0afe0eu: goto P_0c0afe0e;
case 0x0c0afe10u: goto P_0c0afe10;
case 0x0c0afe12u: goto P_0c0afe12;
case 0x0c0afe14u: goto P_0c0afe14;
case 0x0c0afe3cu: goto P_0c0afe3c;
case 0x0c0afe3eu: goto P_0c0afe3e;
case 0x0c0afe40u: goto P_0c0afe40;
case 0x0c0afe42u: goto P_0c0afe42;
case 0x0c0afe44u: goto P_0c0afe44;
case 0x0c0afe46u: goto P_0c0afe46;
case 0x0c0afe48u: goto P_0c0afe48;
case 0x0c0afe4au: goto P_0c0afe4a;
case 0x0c0afe4cu: goto P_0c0afe4c;
case 0x0c0afe4eu: goto P_0c0afe4e;
case 0x0c0afe50u: goto P_0c0afe50;
case 0x0c0afe52u: goto P_0c0afe52;
case 0x0c0afe54u: goto P_0c0afe54;
case 0x0c0afe56u: goto P_0c0afe56;
case 0x0c0afe58u: goto P_0c0afe58;
case 0x0c0afe5au: goto P_0c0afe5a;
case 0x0c0afe5cu: goto P_0c0afe5c;
case 0x0c0afe5eu: goto P_0c0afe5e;
case 0x0c0afe60u: goto P_0c0afe60;
case 0x0c0afe62u: goto P_0c0afe62;
case 0x0c0afe64u: goto P_0c0afe64;
case 0x0c0afe66u: goto P_0c0afe66;
case 0x0c0afe68u: goto P_0c0afe68;
case 0x0c0afe6au: goto P_0c0afe6a;
case 0x0c0afe6cu: goto P_0c0afe6c;
case 0x0c0afe6eu: goto P_0c0afe6e;
case 0x0c0afe70u: goto P_0c0afe70;
case 0x0c0afe72u: goto P_0c0afe72;
case 0x0c0afe74u: goto P_0c0afe74;
case 0x0c0afe76u: goto P_0c0afe76;
case 0x0c0afe78u: goto P_0c0afe78;
case 0x0c0afe7au: goto P_0c0afe7a;
case 0x0c0afe7cu: goto P_0c0afe7c;
case 0x0c0afe7eu: goto P_0c0afe7e;
case 0x0c0afe80u: goto P_0c0afe80;
case 0x0c0afe82u: goto P_0c0afe82;
case 0x0c0afe84u: goto P_0c0afe84;
case 0x0c0afe86u: goto P_0c0afe86;
case 0x0c0afe88u: goto P_0c0afe88;
case 0x0c0afe8au: goto P_0c0afe8a;
case 0x0c0afe8cu: goto P_0c0afe8c;
case 0x0c0afe8eu: goto P_0c0afe8e;
case 0x0c0afe90u: goto P_0c0afe90;
case 0x0c0afe92u: goto P_0c0afe92;
case 0x0c0afe94u: goto P_0c0afe94;
case 0x0c0afe96u: goto P_0c0afe96;
case 0x0c0afe98u: goto P_0c0afe98;
case 0x0c0afe9au: goto P_0c0afe9a;
case 0x0c0afe9cu: goto P_0c0afe9c;
case 0x0c0afe9eu: goto P_0c0afe9e;
case 0x0c0afea0u: goto P_0c0afea0;
case 0x0c0afea2u: goto P_0c0afea2;
case 0x0c0afea4u: goto P_0c0afea4;
case 0x0c0afea6u: goto P_0c0afea6;
case 0x0c0afea8u: goto P_0c0afea8;
case 0x0c0afeaau: goto P_0c0afeaa;
case 0x0c0afeacu: goto P_0c0afeac;
case 0x0c0afeaeu: goto P_0c0afeae;
case 0x0c0afeb0u: goto P_0c0afeb0;
case 0x0c0afeb2u: goto P_0c0afeb2;
case 0x0c0afeb4u: goto P_0c0afeb4;
case 0x0c0afeb6u: goto P_0c0afeb6;
case 0x0c0afeb8u: goto P_0c0afeb8;
case 0x0c0afebau: goto P_0c0afeba;
case 0x0c0afebcu: goto P_0c0afebc;
case 0x0c0afebeu: goto P_0c0afebe;
case 0x0c0afec0u: goto P_0c0afec0;
case 0x0c0afec2u: goto P_0c0afec2;
case 0x0c0afec4u: goto P_0c0afec4;
case 0x0c0afec6u: goto P_0c0afec6;
case 0x0c0afec8u: goto P_0c0afec8;
case 0x0c0afecau: goto P_0c0afeca;
case 0x0c0afeccu: goto P_0c0afecc;
case 0x0c0afeceu: goto P_0c0afece;
case 0x0c0afed0u: goto P_0c0afed0;
case 0x0c0afed2u: goto P_0c0afed2;
case 0x0c0afed4u: goto P_0c0afed4;
case 0x0c0afed6u: goto P_0c0afed6;
case 0x0c0afed8u: goto P_0c0afed8;
case 0x0c0afedau: goto P_0c0afeda;
case 0x0c0afedcu: goto P_0c0afedc;
case 0x0c0afedeu: goto P_0c0afede;
case 0x0c0afee0u: goto P_0c0afee0;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0afb62: /* original 2fe6, guest PC 0x0c0afb62 */
if(!s->budget--) { s->failed_pc=0x0c0afb62u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0afb64;
P_0c0afb64: /* original 6e43, guest PC 0x0c0afb64 */
if(!s->budget--) { s->failed_pc=0x0c0afb64u; return 0; }
r[14]=r[4];
goto P_0c0afb66;
P_0c0afb66: /* original 2fd6, guest PC 0x0c0afb66 */
if(!s->budget--) { s->failed_pc=0x0c0afb66u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0afb68;
P_0c0afb68: /* original 2fc6, guest PC 0x0c0afb68 */
if(!s->budget--) { s->failed_pc=0x0c0afb68u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0afb6a;
P_0c0afb6a: /* original 2fb6, guest PC 0x0c0afb6a */
if(!s->budget--) { s->failed_pc=0x0c0afb6au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0afb6c;
P_0c0afb6c: /* original 2fa6, guest PC 0x0c0afb6c */
if(!s->budget--) { s->failed_pc=0x0c0afb6cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0afb6e;
P_0c0afb6e: /* original 2f96, guest PC 0x0c0afb6e */
if(!s->budget--) { s->failed_pc=0x0c0afb6eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0afb70;
P_0c0afb70: /* original 2f86, guest PC 0x0c0afb70 */
if(!s->budget--) { s->failed_pc=0x0c0afb70u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0afb72;
P_0c0afb72: /* original fffb, guest PC 0x0c0afb72 */
if(!s->budget--) { s->failed_pc=0x0c0afb72u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0afb74;
P_0c0afb74: /* original ffeb, guest PC 0x0c0afb74 */
if(!s->budget--) { s->failed_pc=0x0c0afb74u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0afb76;
P_0c0afb76: /* original 4f22, guest PC 0x0c0afb76 */
if(!s->budget--) { s->failed_pc=0x0c0afb76u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0afb78;
P_0c0afb78: /* original 62e2, guest PC 0x0c0afb78 */
if(!s->budget--) { s->failed_pc=0x0c0afb78u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0afb7a;
P_0c0afb7a: /* original 9364, guest PC 0x0c0afb7a */
if(!s->budget--) { s->failed_pc=0x0c0afb7au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afc46u,2);
goto P_0c0afb7c;
P_0c0afb7c: /* original 7fe4, guest PC 0x0c0afb7c */
if(!s->budget--) { s->failed_pc=0x0c0afb7cu; return 0; }
r[15]+=0xffffffe4u;
goto P_0c0afb7e;
P_0c0afb7e: /* original 2238, guest PC 0x0c0afb7e */
if(!s->budget--) { s->failed_pc=0x0c0afb7eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0afb80;
P_0c0afb80: /* original 8901, guest PC 0x0c0afb80 */
if(!s->budget--) { s->failed_pc=0x0c0afb80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afb86; }
goto P_0c0afb82;
P_0c0afb82: /* original a1a2, guest PC 0x0c0afb82 */
if(!s->budget--) { s->failed_pc=0x0c0afb82u; return 0; }
goto P_0c0afeca;
P_0c0afb84: /* original 0009, guest PC 0x0c0afb84 */
if(!s->budget--) { s->failed_pc=0x0c0afb84u; return 0; }
goto P_0c0afb86;
P_0c0afb86: /* original e048, guest PC 0x0c0afb86 */
if(!s->budget--) { s->failed_pc=0x0c0afb86u; return 0; }
r[0]=0x00000048u;
goto P_0c0afb88;
P_0c0afb88: /* original d330, guest PC 0x0c0afb88 */
if(!s->budget--) { s->failed_pc=0x0c0afb88u; return 0; }
r[3]=read(ram,0x0c0afc4cu,4);
goto P_0c0afb8a;
P_0c0afb8a: /* original 04ee, guest PC 0x0c0afb8a */
if(!s->budget--) { s->failed_pc=0x0c0afb8au; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0afb8c;
P_0c0afb8c: /* original 065e, guest PC 0x0c0afb8c */
if(!s->budget--) { s->failed_pc=0x0c0afb8cu; return 0; }
r[6]=read(ram,r[5]+r[0],4);
goto P_0c0afb8e;
P_0c0afb8e: /* original e04c, guest PC 0x0c0afb8e */
if(!s->budget--) { s->failed_pc=0x0c0afb8eu; return 0; }
r[0]=0x0000004cu;
goto P_0c0afb90;
P_0c0afb90: /* original 2348, guest PC 0x0c0afb90 */
if(!s->budget--) { s->failed_pc=0x0c0afb90u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0afb92;
P_0c0afb92: /* original 8d02, guest PC 0x0c0afb92 */
if(!s->budget--) { s->failed_pc=0x0c0afb92u; return 0; }
cond=r[17]&1u;
r[11]=read(ram,r[14]+r[0],4);
if(cond) { goto P_0c0afb9a; }
goto P_0c0afb96;
P_0c0afb94: /* original 0bee, guest PC 0x0c0afb94 */
if(!s->budget--) { s->failed_pc=0x0c0afb94u; return 0; }
r[11]=read(ram,r[14]+r[0],4);
goto P_0c0afb96;
P_0c0afb96: /* original a198, guest PC 0x0c0afb96 */
if(!s->budget--) { s->failed_pc=0x0c0afb96u; return 0; }
goto P_0c0afeca;
P_0c0afb98: /* original 0009, guest PC 0x0c0afb98 */
if(!s->budget--) { s->failed_pc=0x0c0afb98u; return 0; }
goto P_0c0afb9a;
P_0c0afb9a: /* original d72d, guest PC 0x0c0afb9a */
if(!s->budget--) { s->failed_pc=0x0c0afb9au; return 0; }
r[7]=read(ram,0x0c0afc50u,4);
goto P_0c0afb9c;
P_0c0afb9c: /* original 6373, guest PC 0x0c0afb9c */
if(!s->budget--) { s->failed_pc=0x0c0afb9cu; return 0; }
r[3]=r[7];
goto P_0c0afb9e;
P_0c0afb9e: /* original 2349, guest PC 0x0c0afb9e */
if(!s->budget--) { s->failed_pc=0x0c0afb9eu; return 0; }
r[3]&=r[4];
goto P_0c0afba0;
P_0c0afba0: /* original 3370, guest PC 0x0c0afba0 */
if(!s->budget--) { s->failed_pc=0x0c0afba0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[7])!=0);
goto P_0c0afba2;
P_0c0afba2: /* original 8f02, guest PC 0x0c0afba2 */
if(!s->budget--) { s->failed_pc=0x0c0afba2u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c0afbaa; }
goto P_0c0afba6;
P_0c0afba4: /* original 2f32, guest PC 0x0c0afba4 */
if(!s->budget--) { s->failed_pc=0x0c0afba4u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0afba6;
P_0c0afba6: /* original a190, guest PC 0x0c0afba6 */
if(!s->budget--) { s->failed_pc=0x0c0afba6u; return 0; }
goto P_0c0afeca;
P_0c0afba8: /* original 0009, guest PC 0x0c0afba8 */
if(!s->budget--) { s->failed_pc=0x0c0afba8u; return 0; }
goto P_0c0afbaa;
P_0c0afbaa: /* original d32a, guest PC 0x0c0afbaa */
if(!s->budget--) { s->failed_pc=0x0c0afbaau; return 0; }
r[3]=read(ram,0x0c0afc54u,4);
goto P_0c0afbac;
P_0c0afbac: /* original 2349, guest PC 0x0c0afbac */
if(!s->budget--) { s->failed_pc=0x0c0afbacu; return 0; }
r[3]&=r[4];
goto P_0c0afbae;
P_0c0afbae: /* original 2338, guest PC 0x0c0afbae */
if(!s->budget--) { s->failed_pc=0x0c0afbaeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0afbb0;
P_0c0afbb0: /* original 2f32, guest PC 0x0c0afbb0 */
if(!s->budget--) { s->failed_pc=0x0c0afbb0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0afbb2;
P_0c0afbb2: /* original d729, guest PC 0x0c0afbb2 */
if(!s->budget--) { s->failed_pc=0x0c0afbb2u; return 0; }
r[7]=read(ram,0x0c0afc58u,4);
goto P_0c0afbb4;
P_0c0afbb4: /* original 8d0a, guest PC 0x0c0afbb4 */
if(!s->budget--) { s->failed_pc=0x0c0afbb4u; return 0; }
cond=r[17]&1u;
r[7]&=r[4];
if(cond) { goto P_0c0afbcc; }
goto P_0c0afbb8;
P_0c0afbb6: /* original 2749, guest PC 0x0c0afbb6 */
if(!s->budget--) { s->failed_pc=0x0c0afbb6u; return 0; }
r[7]&=r[4];
goto P_0c0afbb8;
P_0c0afbb8: /* original 2778, guest PC 0x0c0afbb8 */
if(!s->budget--) { s->failed_pc=0x0c0afbb8u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0afbba;
P_0c0afbba: /* original 8b07, guest PC 0x0c0afbba */
if(!s->budget--) { s->failed_pc=0x0c0afbbau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afbcc; }
goto P_0c0afbbc;
P_0c0afbbc: /* original d326, guest PC 0x0c0afbbc */
if(!s->budget--) { s->failed_pc=0x0c0afbbcu; return 0; }
r[3]=read(ram,0x0c0afc58u,4);
goto P_0c0afbbe;
P_0c0afbbe: /* original 2368, guest PC 0x0c0afbbe */
if(!s->budget--) { s->failed_pc=0x0c0afbbeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0afbc0;
P_0c0afbc0: /* original 8904, guest PC 0x0c0afbc0 */
if(!s->budget--) { s->failed_pc=0x0c0afbc0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afbcc; }
goto P_0c0afbc2;
P_0c0afbc2: /* original d226, guest PC 0x0c0afbc2 */
if(!s->budget--) { s->failed_pc=0x0c0afbc2u; return 0; }
r[2]=read(ram,0x0c0afc5cu,4);
goto P_0c0afbc4;
P_0c0afbc4: /* original 2268, guest PC 0x0c0afbc4 */
if(!s->budget--) { s->failed_pc=0x0c0afbc4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c0afbc6;
P_0c0afbc6: /* original 8901, guest PC 0x0c0afbc6 */
if(!s->budget--) { s->failed_pc=0x0c0afbc6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afbcc; }
goto P_0c0afbc8;
P_0c0afbc8: /* original a17f, guest PC 0x0c0afbc8 */
if(!s->budget--) { s->failed_pc=0x0c0afbc8u; return 0; }
goto P_0c0afeca;
P_0c0afbca: /* original 0009, guest PC 0x0c0afbca */
if(!s->budget--) { s->failed_pc=0x0c0afbcau; return 0; }
goto P_0c0afbcc;
P_0c0afbcc: /* original d324, guest PC 0x0c0afbcc */
if(!s->budget--) { s->failed_pc=0x0c0afbccu; return 0; }
r[3]=read(ram,0x0c0afc60u,4);
goto P_0c0afbce;
P_0c0afbce: /* original 23b8, guest PC 0x0c0afbce */
if(!s->budget--) { s->failed_pc=0x0c0afbceu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c0afbd0;
P_0c0afbd0: /* original 8901, guest PC 0x0c0afbd0 */
if(!s->budget--) { s->failed_pc=0x0c0afbd0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afbd6; }
goto P_0c0afbd2;
P_0c0afbd2: /* original a17a, guest PC 0x0c0afbd2 */
if(!s->budget--) { s->failed_pc=0x0c0afbd2u; return 0; }
goto P_0c0afeca;
P_0c0afbd4: /* original 0009, guest PC 0x0c0afbd4 */
if(!s->budget--) { s->failed_pc=0x0c0afbd4u; return 0; }
goto P_0c0afbd6;
P_0c0afbd6: /* original e06a, guest PC 0x0c0afbd6 */
if(!s->budget--) { s->failed_pc=0x0c0afbd6u; return 0; }
r[0]=0x0000006au;
goto P_0c0afbd8;
P_0c0afbd8: /* original d322, guest PC 0x0c0afbd8 */
if(!s->budget--) { s->failed_pc=0x0c0afbd8u; return 0; }
r[3]=read(ram,0x0c0afc64u,4);
goto P_0c0afbda;
P_0c0afbda: /* original 0ded, guest PC 0x0c0afbda */
if(!s->budget--) { s->failed_pc=0x0c0afbdau; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0afbdc;
P_0c0afbdc: /* original e04c, guest PC 0x0c0afbdc */
if(!s->budget--) { s->failed_pc=0x0c0afbdcu; return 0; }
r[0]=0x0000004cu;
goto P_0c0afbde;
P_0c0afbde: /* original 0a5e, guest PC 0x0c0afbde */
if(!s->budget--) { s->failed_pc=0x0c0afbdeu; return 0; }
r[10]=read(ram,r[5]+r[0],4);
goto P_0c0afbe0;
P_0c0afbe0: /* original 23b9, guest PC 0x0c0afbe0 */
if(!s->budget--) { s->failed_pc=0x0c0afbe0u; return 0; }
r[3]&=r[11];
goto P_0c0afbe2;
P_0c0afbe2: /* original 9931, guest PC 0x0c0afbe2 */
if(!s->budget--) { s->failed_pc=0x0c0afbe2u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afc48u,2);
goto P_0c0afbe4;
P_0c0afbe4: /* original 6ddd, guest PC 0x0c0afbe4 */
if(!s->budget--) { s->failed_pc=0x0c0afbe4u; return 0; }
r[13]=r[13]&65535u;
goto P_0c0afbe6;
P_0c0afbe6: /* original 62a3, guest PC 0x0c0afbe6 */
if(!s->budget--) { s->failed_pc=0x0c0afbe6u; return 0; }
r[2]=r[10];
goto P_0c0afbe8;
P_0c0afbe8: /* original 9c2f, guest PC 0x0c0afbe8 */
if(!s->budget--) { s->failed_pc=0x0c0afbe8u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afc4au,2);
goto P_0c0afbea;
P_0c0afbea: /* original 2298, guest PC 0x0c0afbea */
if(!s->budget--) { s->failed_pc=0x0c0afbeau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[9])==0)!=0);
goto P_0c0afbec;
P_0c0afbec: /* original 8f17, guest PC 0x0c0afbec */
if(!s->budget--) { s->failed_pc=0x0c0afbecu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[3],4);
if(!cond) { goto P_0c0afc1e; }
goto P_0c0afbf0;
P_0c0afbee: /* original 1f31, guest PC 0x0c0afbee */
if(!s->budget--) { s->failed_pc=0x0c0afbeeu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0afbf0;
P_0c0afbf0: /* original 2ac8, guest PC 0x0c0afbf0 */
if(!s->budget--) { s->failed_pc=0x0c0afbf0u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[12])==0)!=0);
goto P_0c0afbf2;
P_0c0afbf2: /* original 8b14, guest PC 0x0c0afbf2 */
if(!s->budget--) { s->failed_pc=0x0c0afbf2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afc1e; }
goto P_0c0afbf4;
P_0c0afbf4: /* original e308, guest PC 0x0c0afbf4 */
if(!s->budget--) { s->failed_pc=0x0c0afbf4u; return 0; }
r[3]=0x00000008u;
goto P_0c0afbf6;
P_0c0afbf6: /* original 2368, guest PC 0x0c0afbf6 */
if(!s->budget--) { s->failed_pc=0x0c0afbf6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0afbf8;
P_0c0afbf8: /* original 8b11, guest PC 0x0c0afbf8 */
if(!s->budget--) { s->failed_pc=0x0c0afbf8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afc1e; }
goto P_0c0afbfa;
P_0c0afbfa: /* original 52f1, guest PC 0x0c0afbfa */
if(!s->budget--) { s->failed_pc=0x0c0afbfau; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0afbfc;
P_0c0afbfc: /* original 2228, guest PC 0x0c0afbfc */
if(!s->budget--) { s->failed_pc=0x0c0afbfcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0afbfe;
P_0c0afbfe: /* original 890e, guest PC 0x0c0afbfe */
if(!s->budget--) { s->failed_pc=0x0c0afbfeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afc1e; }
goto P_0c0afc00;
P_0c0afc00: /* original 6153, guest PC 0x0c0afc00 */
if(!s->budget--) { s->failed_pc=0x0c0afc00u; return 0; }
r[1]=r[5];
goto P_0c0afc02;
P_0c0afc02: /* original 7138, guest PC 0x0c0afc02 */
if(!s->budget--) { s->failed_pc=0x0c0afc02u; return 0; }
r[1]+=0x00000038u;
goto P_0c0afc04;
P_0c0afc04: /* original 8413, guest PC 0x0c0afc04 */
if(!s->budget--) { s->failed_pc=0x0c0afc04u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+3,1);
goto P_0c0afc06;
P_0c0afc06: /* original 600c, guest PC 0x0c0afc06 */
if(!s->budget--) { s->failed_pc=0x0c0afc06u; return 0; }
r[0]=r[0]&255u;
goto P_0c0afc08;
P_0c0afc08: /* original 8812, guest PC 0x0c0afc08 */
if(!s->budget--) { s->failed_pc=0x0c0afc08u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c0afc0a;
P_0c0afc0a: /* original 8d08, guest PC 0x0c0afc0a */
if(!s->budget--) { s->failed_pc=0x0c0afc0au; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[0],4);
if(cond) { goto P_0c0afc1e; }
goto P_0c0afc0e;
P_0c0afc0c: /* original 1f02, guest PC 0x0c0afc0c */
if(!s->budget--) { s->failed_pc=0x0c0afc0cu; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c0afc0e;
P_0c0afc0e: /* original 63e2, guest PC 0x0c0afc0e */
if(!s->budget--) { s->failed_pc=0x0c0afc0eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0afc10;
P_0c0afc10: /* original 1f32, guest PC 0x0c0afc10 */
if(!s->budget--) { s->failed_pc=0x0c0afc10u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0afc12;
P_0c0afc12: /* original 52f2, guest PC 0x0c0afc12 */
if(!s->budget--) { s->failed_pc=0x0c0afc12u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0afc14;
P_0c0afc14: /* original d314, guest PC 0x0c0afc14 */
if(!s->budget--) { s->failed_pc=0x0c0afc14u; return 0; }
r[3]=read(ram,0x0c0afc68u,4);
goto P_0c0afc16;
P_0c0afc16: /* original 2238, guest PC 0x0c0afc16 */
if(!s->budget--) { s->failed_pc=0x0c0afc16u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0afc18;
P_0c0afc18: /* original 8d01, guest PC 0x0c0afc18 */
if(!s->budget--) { s->failed_pc=0x0c0afc18u; return 0; }
cond=r[17]&1u;
r[13]+=r[9];
if(cond) { goto P_0c0afc1e; }
goto P_0c0afc1c;
P_0c0afc1a: /* original 3d9c, guest PC 0x0c0afc1a */
if(!s->budget--) { s->failed_pc=0x0c0afc1au; return 0; }
r[13]+=r[9];
goto P_0c0afc1c;
P_0c0afc1c: /* original 3dc8, guest PC 0x0c0afc1c */
if(!s->budget--) { s->failed_pc=0x0c0afc1cu; return 0; }
r[13]-=r[12];
goto P_0c0afc1e;
P_0c0afc1e: /* original e308, guest PC 0x0c0afc1e */
if(!s->budget--) { s->failed_pc=0x0c0afc1eu; return 0; }
r[3]=0x00000008u;
goto P_0c0afc20;
P_0c0afc20: /* original d812, guest PC 0x0c0afc20 */
if(!s->budget--) { s->failed_pc=0x0c0afc20u; return 0; }
r[8]=read(ram,0x0c0afc6cu,4);
goto P_0c0afc22;
P_0c0afc22: /* original 2349, guest PC 0x0c0afc22 */
if(!s->budget--) { s->failed_pc=0x0c0afc22u; return 0; }
r[3]&=r[4];
goto P_0c0afc24;
P_0c0afc24: /* original 2338, guest PC 0x0c0afc24 */
if(!s->budget--) { s->failed_pc=0x0c0afc24u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0afc26;
P_0c0afc26: /* original 8d25, guest PC 0x0c0afc26 */
if(!s->budget--) { s->failed_pc=0x0c0afc26u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+24,r[3],4);
if(cond) { goto P_0c0afc74; }
goto P_0c0afc2a;
P_0c0afc28: /* original 1f36, guest PC 0x0c0afc28 */
if(!s->budget--) { s->failed_pc=0x0c0afc28u; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0afc2a;
P_0c0afc2a: /* original 2778, guest PC 0x0c0afc2a */
if(!s->budget--) { s->failed_pc=0x0c0afc2au; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0afc2c;
P_0c0afc2c: /* original 8901, guest PC 0x0c0afc2c */
if(!s->budget--) { s->failed_pc=0x0c0afc2cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afc32; }
goto P_0c0afc2e;
P_0c0afc2e: /* original a0da, guest PC 0x0c0afc2e */
if(!s->budget--) { s->failed_pc=0x0c0afc2eu; return 0; }
goto P_0c0afde6;
P_0c0afc30: /* original 0009, guest PC 0x0c0afc30 */
if(!s->budget--) { s->failed_pc=0x0c0afc30u; return 0; }
goto P_0c0afc32;
P_0c0afc32: /* original c70f, guest PC 0x0c0afc32 */
if(!s->budget--) { s->failed_pc=0x0c0afc32u; return 0; }
r[0]=code_base|0x000afc70u;
goto P_0c0afc34;
P_0c0afc34: /* original f308, guest PC 0x0c0afc34 */
if(!s->budget--) { s->failed_pc=0x0c0afc34u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0afc36;
P_0c0afc36: /* original e05c, guest PC 0x0c0afc36 */
if(!s->budget--) { s->failed_pc=0x0c0afc36u; return 0; }
r[0]=0x0000005cu;
goto P_0c0afc38;
P_0c0afc38: /* original f2e6, guest PC 0x0c0afc38 */
if(!s->budget--) { s->failed_pc=0x0c0afc38u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0afc3a;
P_0c0afc3a: /* original f325, guest PC 0x0c0afc3a */
if(!s->budget--) { s->failed_pc=0x0c0afc3au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0afc3c;
P_0c0afc3c: /* original 8b01, guest PC 0x0c0afc3c */
if(!s->budget--) { s->failed_pc=0x0c0afc3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afc42; }
goto P_0c0afc3e;
P_0c0afc3e: /* original a0e1, guest PC 0x0c0afc3e */
if(!s->budget--) { s->failed_pc=0x0c0afc3eu; return 0; }
goto P_0c0afe04;
P_0c0afc40: /* original 0009, guest PC 0x0c0afc40 */
if(!s->budget--) { s->failed_pc=0x0c0afc40u; return 0; }
goto P_0c0afc42;
P_0c0afc42: /* original a0fb, guest PC 0x0c0afc42 */
if(!s->budget--) { s->failed_pc=0x0c0afc42u; return 0; }
goto P_0c0afe3c;
P_0c0afc44: /* original 0009, guest PC 0x0c0afc44 */
if(!s->budget--) { s->failed_pc=0x0c0afc44u; return 0; }
if(!vf3_matrix_family(0x0c0afc46u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0afc46u; return 0; } return 1;
P_0c0afc74: /* original e201, guest PC 0x0c0afc74 */
if(!s->budget--) { s->failed_pc=0x0c0afc74u; return 0; }
r[2]=0x00000001u;
goto P_0c0afc76;
P_0c0afc76: /* original da37, guest PC 0x0c0afc76 */
if(!s->budget--) { s->failed_pc=0x0c0afc76u; return 0; }
r[10]=read(ram,0x0c0afd54u,4);
goto P_0c0afc78;
P_0c0afc78: /* original 22b8, guest PC 0x0c0afc78 */
if(!s->budget--) { s->failed_pc=0x0c0afc78u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[11])==0)!=0);
goto P_0c0afc7a;
P_0c0afc7a: /* original 8d06, guest PC 0x0c0afc7a */
if(!s->budget--) { s->failed_pc=0x0c0afc7au; return 0; }
cond=r[17]&1u;
r[10]&=r[4];
if(cond) { goto P_0c0afc8a; }
goto P_0c0afc7e;
P_0c0afc7c: /* original 2a49, guest PC 0x0c0afc7c */
if(!s->budget--) { s->failed_pc=0x0c0afc7cu; return 0; }
r[10]&=r[4];
goto P_0c0afc7e;
P_0c0afc7e: /* original 2778, guest PC 0x0c0afc7e */
if(!s->budget--) { s->failed_pc=0x0c0afc7eu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0afc80;
P_0c0afc80: /* original 8903, guest PC 0x0c0afc80 */
if(!s->budget--) { s->failed_pc=0x0c0afc80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afc8a; }
goto P_0c0afc82;
P_0c0afc82: /* original 2aa8, guest PC 0x0c0afc82 */
if(!s->budget--) { s->failed_pc=0x0c0afc82u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0afc84;
P_0c0afc84: /* original 8901, guest PC 0x0c0afc84 */
if(!s->budget--) { s->failed_pc=0x0c0afc84u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afc8a; }
goto P_0c0afc86;
P_0c0afc86: /* original a0bd, guest PC 0x0c0afc86 */
if(!s->budget--) { s->failed_pc=0x0c0afc86u; return 0; }
goto P_0c0afe04;
P_0c0afc88: /* original 0009, guest PC 0x0c0afc88 */
if(!s->budget--) { s->failed_pc=0x0c0afc88u; return 0; }
goto P_0c0afc8a;
P_0c0afc8a: /* original d333, guest PC 0x0c0afc8a */
if(!s->budget--) { s->failed_pc=0x0c0afc8au; return 0; }
r[3]=read(ram,0x0c0afd58u,4);
goto P_0c0afc8c;
P_0c0afc8c: /* original 2349, guest PC 0x0c0afc8c */
if(!s->budget--) { s->failed_pc=0x0c0afc8cu; return 0; }
r[3]&=r[4];
goto P_0c0afc8e;
P_0c0afc8e: /* original 2338, guest PC 0x0c0afc8e */
if(!s->budget--) { s->failed_pc=0x0c0afc8eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0afc90;
P_0c0afc90: /* original 8d02, guest PC 0x0c0afc90 */
if(!s->budget--) { s->failed_pc=0x0c0afc90u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[3],4);
if(cond) { goto P_0c0afc98; }
goto P_0c0afc94;
P_0c0afc92: /* original 1f32, guest PC 0x0c0afc92 */
if(!s->budget--) { s->failed_pc=0x0c0afc92u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0afc94;
P_0c0afc94: /* original a0a7, guest PC 0x0c0afc94 */
if(!s->budget--) { s->failed_pc=0x0c0afc94u; return 0; }
goto P_0c0afde6;
P_0c0afc96: /* original 0009, guest PC 0x0c0afc96 */
if(!s->budget--) { s->failed_pc=0x0c0afc96u; return 0; }
goto P_0c0afc98;
P_0c0afc98: /* original d230, guest PC 0x0c0afc98 */
if(!s->budget--) { s->failed_pc=0x0c0afc98u; return 0; }
r[2]=read(ram,0x0c0afd5cu,4);
goto P_0c0afc9a;
P_0c0afc9a: /* original 2249, guest PC 0x0c0afc9a */
if(!s->budget--) { s->failed_pc=0x0c0afc9au; return 0; }
r[2]&=r[4];
goto P_0c0afc9c;
P_0c0afc9c: /* original 2228, guest PC 0x0c0afc9c */
if(!s->budget--) { s->failed_pc=0x0c0afc9cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0afc9e;
P_0c0afc9e: /* original 8d02, guest PC 0x0c0afc9e */
if(!s->budget--) { s->failed_pc=0x0c0afc9eu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+20,r[2],4);
if(cond) { goto P_0c0afca6; }
goto P_0c0afca2;
P_0c0afca0: /* original 1f25, guest PC 0x0c0afca0 */
if(!s->budget--) { s->failed_pc=0x0c0afca0u; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c0afca2;
P_0c0afca2: /* original a0af, guest PC 0x0c0afca2 */
if(!s->budget--) { s->failed_pc=0x0c0afca2u; return 0; }
goto P_0c0afe04;
P_0c0afca4: /* original 0009, guest PC 0x0c0afca4 */
if(!s->budget--) { s->failed_pc=0x0c0afca4u; return 0; }
goto P_0c0afca6;
P_0c0afca6: /* original d32c, guest PC 0x0c0afca6 */
if(!s->budget--) { s->failed_pc=0x0c0afca6u; return 0; }
r[3]=read(ram,0x0c0afd58u,4);
goto P_0c0afca8;
P_0c0afca8: /* original 2b38, guest PC 0x0c0afca8 */
if(!s->budget--) { s->failed_pc=0x0c0afca8u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[3])==0)!=0);
goto P_0c0afcaa;
P_0c0afcaa: /* original 8901, guest PC 0x0c0afcaa */
if(!s->budget--) { s->failed_pc=0x0c0afcaau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afcb0; }
goto P_0c0afcac;
P_0c0afcac: /* original a0aa, guest PC 0x0c0afcac */
if(!s->budget--) { s->failed_pc=0x0c0afcacu; return 0; }
goto P_0c0afe04;
P_0c0afcae: /* original 0009, guest PC 0x0c0afcae */
if(!s->budget--) { s->failed_pc=0x0c0afcaeu; return 0; }
goto P_0c0afcb0;
P_0c0afcb0: /* original e04c, guest PC 0x0c0afcb0 */
if(!s->budget--) { s->failed_pc=0x0c0afcb0u; return 0; }
r[0]=0x0000004cu;
goto P_0c0afcb2;
P_0c0afcb2: /* original 0b5e, guest PC 0x0c0afcb2 */
if(!s->budget--) { s->failed_pc=0x0c0afcb2u; return 0; }
r[11]=read(ram,r[5]+r[0],4);
goto P_0c0afcb4;
P_0c0afcb4: /* original 904b, guest PC 0x0c0afcb4 */
if(!s->budget--) { s->failed_pc=0x0c0afcb4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afd4eu,2);
goto P_0c0afcb6;
P_0c0afcb6: /* original 005e, guest PC 0x0c0afcb6 */
if(!s->budget--) { s->failed_pc=0x0c0afcb6u; return 0; }
r[0]=read(ram,r[5]+r[0],4);
goto P_0c0afcb8;
P_0c0afcb8: /* original c808, guest PC 0x0c0afcb8 */
if(!s->budget--) { s->failed_pc=0x0c0afcb8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c0afcba;
P_0c0afcba: /* original 8b04, guest PC 0x0c0afcba */
if(!s->budget--) { s->failed_pc=0x0c0afcbau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afcc6; }
goto P_0c0afcbc;
P_0c0afcbc: /* original 63b3, guest PC 0x0c0afcbc */
if(!s->budget--) { s->failed_pc=0x0c0afcbcu; return 0; }
r[3]=r[11];
goto P_0c0afcbe;
P_0c0afcbe: /* original 23c8, guest PC 0x0c0afcbe */
if(!s->budget--) { s->failed_pc=0x0c0afcbeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0afcc0;
P_0c0afcc0: /* original 8b01, guest PC 0x0c0afcc0 */
if(!s->budget--) { s->failed_pc=0x0c0afcc0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afcc6; }
goto P_0c0afcc2;
P_0c0afcc2: /* original 2b98, guest PC 0x0c0afcc2 */
if(!s->budget--) { s->failed_pc=0x0c0afcc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[9])==0)!=0);
goto P_0c0afcc4;
P_0c0afcc4: /* original 891d, guest PC 0x0c0afcc4 */
if(!s->budget--) { s->failed_pc=0x0c0afcc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afd02; }
goto P_0c0afcc6;
P_0c0afcc6: /* original 53f1, guest PC 0x0c0afcc6 */
if(!s->budget--) { s->failed_pc=0x0c0afcc6u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0afcc8;
P_0c0afcc8: /* original 2338, guest PC 0x0c0afcc8 */
if(!s->budget--) { s->failed_pc=0x0c0afcc8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0afcca;
P_0c0afcca: /* original 8901, guest PC 0x0c0afcca */
if(!s->budget--) { s->failed_pc=0x0c0afccau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afcd0; }
goto P_0c0afccc;
P_0c0afccc: /* original a0b6, guest PC 0x0c0afccc */
if(!s->budget--) { s->failed_pc=0x0c0afcccu; return 0; }
goto P_0c0afe3c;
P_0c0afcce: /* original 0009, guest PC 0x0c0afcce */
if(!s->budget--) { s->failed_pc=0x0c0afcceu; return 0; }
goto P_0c0afcd0;
P_0c0afcd0: /* original 52f2, guest PC 0x0c0afcd0 */
if(!s->budget--) { s->failed_pc=0x0c0afcd0u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0afcd2;
P_0c0afcd2: /* original 2228, guest PC 0x0c0afcd2 */
if(!s->budget--) { s->failed_pc=0x0c0afcd2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0afcd4;
P_0c0afcd4: /* original 8901, guest PC 0x0c0afcd4 */
if(!s->budget--) { s->failed_pc=0x0c0afcd4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afcda; }
goto P_0c0afcd6;
P_0c0afcd6: /* original a095, guest PC 0x0c0afcd6 */
if(!s->budget--) { s->failed_pc=0x0c0afcd6u; return 0; }
goto P_0c0afe04;
P_0c0afcd8: /* original 0009, guest PC 0x0c0afcd8 */
if(!s->budget--) { s->failed_pc=0x0c0afcd8u; return 0; }
goto P_0c0afcda;
P_0c0afcda: /* original 52f5, guest PC 0x0c0afcda */
if(!s->budget--) { s->failed_pc=0x0c0afcdau; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c0afcdc;
P_0c0afcdc: /* original 2228, guest PC 0x0c0afcdc */
if(!s->budget--) { s->failed_pc=0x0c0afcdcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0afcde;
P_0c0afcde: /* original 8901, guest PC 0x0c0afcde */
if(!s->budget--) { s->failed_pc=0x0c0afcdeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afce4; }
goto P_0c0afce0;
P_0c0afce0: /* original a090, guest PC 0x0c0afce0 */
if(!s->budget--) { s->failed_pc=0x0c0afce0u; return 0; }
goto P_0c0afe04;
P_0c0afce2: /* original 0009, guest PC 0x0c0afce2 */
if(!s->budget--) { s->failed_pc=0x0c0afce2u; return 0; }
goto P_0c0afce4;
P_0c0afce4: /* original 52f6, guest PC 0x0c0afce4 */
if(!s->budget--) { s->failed_pc=0x0c0afce4u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c0afce6;
P_0c0afce6: /* original 2228, guest PC 0x0c0afce6 */
if(!s->budget--) { s->failed_pc=0x0c0afce6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0afce8;
P_0c0afce8: /* original 8901, guest PC 0x0c0afce8 */
if(!s->budget--) { s->failed_pc=0x0c0afce8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afcee; }
goto P_0c0afcea;
P_0c0afcea: /* original a0ee, guest PC 0x0c0afcea */
if(!s->budget--) { s->failed_pc=0x0c0afceau; return 0; }
goto P_0c0afeca;
P_0c0afcec: /* original 0009, guest PC 0x0c0afcec */
if(!s->budget--) { s->failed_pc=0x0c0afcecu; return 0; }
goto P_0c0afcee;
P_0c0afcee: /* original 2778, guest PC 0x0c0afcee */
if(!s->budget--) { s->failed_pc=0x0c0afceeu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0afcf0;
P_0c0afcf0: /* original 8901, guest PC 0x0c0afcf0 */
if(!s->budget--) { s->failed_pc=0x0c0afcf0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afcf6; }
goto P_0c0afcf2;
P_0c0afcf2: /* original a0ea, guest PC 0x0c0afcf2 */
if(!s->budget--) { s->failed_pc=0x0c0afcf2u; return 0; }
goto P_0c0afeca;
P_0c0afcf4: /* original 0009, guest PC 0x0c0afcf4 */
if(!s->budget--) { s->failed_pc=0x0c0afcf4u; return 0; }
goto P_0c0afcf6;
P_0c0afcf6: /* original 902b, guest PC 0x0c0afcf6 */
if(!s->budget--) { s->failed_pc=0x0c0afcf6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afd50u,2);
goto P_0c0afcf8;
P_0c0afcf8: /* original 025d, guest PC 0x0c0afcf8 */
if(!s->budget--) { s->failed_pc=0x0c0afcf8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0afcfa;
P_0c0afcfa: /* original 4215, guest PC 0x0c0afcfa */
if(!s->budget--) { s->failed_pc=0x0c0afcfau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0afcfc;
P_0c0afcfc: /* original 8b01, guest PC 0x0c0afcfc */
if(!s->budget--) { s->failed_pc=0x0c0afcfcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afd02; }
goto P_0c0afcfe;
P_0c0afcfe: /* original a0e4, guest PC 0x0c0afcfe */
if(!s->budget--) { s->failed_pc=0x0c0afcfeu; return 0; }
goto P_0c0afeca;
P_0c0afd00: /* original 0009, guest PC 0x0c0afd00 */
if(!s->budget--) { s->failed_pc=0x0c0afd00u; return 0; }
goto P_0c0afd02;
P_0c0afd02: /* original 2948, guest PC 0x0c0afd02 */
if(!s->budget--) { s->failed_pc=0x0c0afd02u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[4])==0)!=0);
goto P_0c0afd04;
P_0c0afd04: /* original 8903, guest PC 0x0c0afd04 */
if(!s->budget--) { s->failed_pc=0x0c0afd04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afd0e; }
goto P_0c0afd06;
P_0c0afd06: /* original 2aa8, guest PC 0x0c0afd06 */
if(!s->budget--) { s->failed_pc=0x0c0afd06u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0afd08;
P_0c0afd08: /* original 8b67, guest PC 0x0c0afd08 */
if(!s->budget--) { s->failed_pc=0x0c0afd08u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afdda; }
goto P_0c0afd0a;
P_0c0afd0a: /* original a0de, guest PC 0x0c0afd0a */
if(!s->budget--) { s->failed_pc=0x0c0afd0au; return 0; }
goto P_0c0afeca;
P_0c0afd0c: /* original 0009, guest PC 0x0c0afd0c */
if(!s->budget--) { s->failed_pc=0x0c0afd0cu; return 0; }
goto P_0c0afd0e;
P_0c0afd0e: /* original db14, guest PC 0x0c0afd0e */
if(!s->budget--) { s->failed_pc=0x0c0afd0eu; return 0; }
r[11]=read(ram,0x0c0afd60u,4);
goto P_0c0afd10;
P_0c0afd10: /* original 2b49, guest PC 0x0c0afd10 */
if(!s->budget--) { s->failed_pc=0x0c0afd10u; return 0; }
r[11]&=r[4];
goto P_0c0afd12;
P_0c0afd12: /* original 2bb8, guest PC 0x0c0afd12 */
if(!s->budget--) { s->failed_pc=0x0c0afd12u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0afd14;
P_0c0afd14: /* original 8903, guest PC 0x0c0afd14 */
if(!s->budget--) { s->failed_pc=0x0c0afd14u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afd1e; }
goto P_0c0afd16;
P_0c0afd16: /* original 2778, guest PC 0x0c0afd16 */
if(!s->budget--) { s->failed_pc=0x0c0afd16u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0afd18;
P_0c0afd18: /* original 8901, guest PC 0x0c0afd18 */
if(!s->budget--) { s->failed_pc=0x0c0afd18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afd1e; }
goto P_0c0afd1a;
P_0c0afd1a: /* original a073, guest PC 0x0c0afd1a */
if(!s->budget--) { s->failed_pc=0x0c0afd1au; return 0; }
goto P_0c0afe04;
P_0c0afd1c: /* original 0009, guest PC 0x0c0afd1c */
if(!s->budget--) { s->failed_pc=0x0c0afd1cu; return 0; }
goto P_0c0afd1e;
P_0c0afd1e: /* original 6243, guest PC 0x0c0afd1e */
if(!s->budget--) { s->failed_pc=0x0c0afd1eu; return 0; }
r[2]=r[4];
goto P_0c0afd20;
P_0c0afd20: /* original 2288, guest PC 0x0c0afd20 */
if(!s->budget--) { s->failed_pc=0x0c0afd20u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[8])==0)!=0);
goto P_0c0afd22;
P_0c0afd22: /* original 6943, guest PC 0x0c0afd22 */
if(!s->budget--) { s->failed_pc=0x0c0afd22u; return 0; }
r[9]=r[4];
goto P_0c0afd24;
P_0c0afd24: /* original 8d22, guest PC 0x0c0afd24 */
if(!s->budget--) { s->failed_pc=0x0c0afd24u; return 0; }
cond=r[17]&1u;
r[9]&=r[12];
if(cond) { goto P_0c0afd6c; }
goto P_0c0afd28;
P_0c0afd26: /* original 29c9, guest PC 0x0c0afd26 */
if(!s->budget--) { s->failed_pc=0x0c0afd26u; return 0; }
r[9]&=r[12];
goto P_0c0afd28;
P_0c0afd28: /* original d30e, guest PC 0x0c0afd28 */
if(!s->budget--) { s->failed_pc=0x0c0afd28u; return 0; }
r[3]=read(ram,0x0c0afd64u,4);
goto P_0c0afd2a;
P_0c0afd2a: /* original 2348, guest PC 0x0c0afd2a */
if(!s->budget--) { s->failed_pc=0x0c0afd2au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0afd2c;
P_0c0afd2c: /* original 8901, guest PC 0x0c0afd2c */
if(!s->budget--) { s->failed_pc=0x0c0afd2cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afd32; }
goto P_0c0afd2e;
P_0c0afd2e: /* original a0cc, guest PC 0x0c0afd2e */
if(!s->budget--) { s->failed_pc=0x0c0afd2eu; return 0; }
goto P_0c0afeca;
P_0c0afd30: /* original 0009, guest PC 0x0c0afd30 */
if(!s->budget--) { s->failed_pc=0x0c0afd30u; return 0; }
goto P_0c0afd32;
P_0c0afd32: /* original 2998, guest PC 0x0c0afd32 */
if(!s->budget--) { s->failed_pc=0x0c0afd32u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0afd34;
P_0c0afd34: /* original 8b66, guest PC 0x0c0afd34 */
if(!s->budget--) { s->failed_pc=0x0c0afd34u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afe04; }
goto P_0c0afd36;
P_0c0afd36: /* original 62f2, guest PC 0x0c0afd36 */
if(!s->budget--) { s->failed_pc=0x0c0afd36u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0afd38;
P_0c0afd38: /* original 2228, guest PC 0x0c0afd38 */
if(!s->budget--) { s->failed_pc=0x0c0afd38u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0afd3a;
P_0c0afd3a: /* original 8901, guest PC 0x0c0afd3a */
if(!s->budget--) { s->failed_pc=0x0c0afd3au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afd40; }
goto P_0c0afd3c;
P_0c0afd3c: /* original a0c5, guest PC 0x0c0afd3c */
if(!s->budget--) { s->failed_pc=0x0c0afd3cu; return 0; }
goto P_0c0afeca;
P_0c0afd3e: /* original 0009, guest PC 0x0c0afd3e */
if(!s->budget--) { s->failed_pc=0x0c0afd3eu; return 0; }
goto P_0c0afd40;
P_0c0afd40: /* original d109, guest PC 0x0c0afd40 */
if(!s->budget--) { s->failed_pc=0x0c0afd40u; return 0; }
r[1]=read(ram,0x0c0afd68u,4);
goto P_0c0afd42;
P_0c0afd42: /* original 2418, guest PC 0x0c0afd42 */
if(!s->budget--) { s->failed_pc=0x0c0afd42u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[1])==0)!=0);
goto P_0c0afd44;
P_0c0afd44: /* original 8901, guest PC 0x0c0afd44 */
if(!s->budget--) { s->failed_pc=0x0c0afd44u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afd4a; }
goto P_0c0afd46;
P_0c0afd46: /* original a0c0, guest PC 0x0c0afd46 */
if(!s->budget--) { s->failed_pc=0x0c0afd46u; return 0; }
goto P_0c0afeca;
P_0c0afd48: /* original 0009, guest PC 0x0c0afd48 */
if(!s->budget--) { s->failed_pc=0x0c0afd48u; return 0; }
goto P_0c0afd4a;
P_0c0afd4a: /* original a05b, guest PC 0x0c0afd4a */
if(!s->budget--) { s->failed_pc=0x0c0afd4au; return 0; }
goto P_0c0afe04;
P_0c0afd4c: /* original 0009, guest PC 0x0c0afd4c */
if(!s->budget--) { s->failed_pc=0x0c0afd4cu; return 0; }
if(!vf3_matrix_family(0x0c0afd4eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0afd4eu; return 0; } return 1;
P_0c0afd6c: /* original d22d, guest PC 0x0c0afd6c */
if(!s->budget--) { s->failed_pc=0x0c0afd6cu; return 0; }
r[2]=read(ram,0x0c0afe24u,4);
goto P_0c0afd6e;
P_0c0afd6e: /* original 2249, guest PC 0x0c0afd6e */
if(!s->budget--) { s->failed_pc=0x0c0afd6eu; return 0; }
r[2]&=r[4];
goto P_0c0afd70;
P_0c0afd70: /* original 2f22, guest PC 0x0c0afd70 */
if(!s->budget--) { s->failed_pc=0x0c0afd70u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0afd72;
P_0c0afd72: /* original d32d, guest PC 0x0c0afd72 */
if(!s->budget--) { s->failed_pc=0x0c0afd72u; return 0; }
r[3]=read(ram,0x0c0afe28u,4);
goto P_0c0afd74;
P_0c0afd74: /* original 6133, guest PC 0x0c0afd74 */
if(!s->budget--) { s->failed_pc=0x0c0afd74u; return 0; }
r[1]=r[3];
goto P_0c0afd76;
P_0c0afd76: /* original 3210, guest PC 0x0c0afd76 */
if(!s->budget--) { s->failed_pc=0x0c0afd76u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c0afd78;
P_0c0afd78: /* original 1f31, guest PC 0x0c0afd78 */
if(!s->budget--) { s->failed_pc=0x0c0afd78u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0afd7a;
P_0c0afd7a: /* original 8934, guest PC 0x0c0afd7a */
if(!s->budget--) { s->failed_pc=0x0c0afd7au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afde6; }
goto P_0c0afd7c;
P_0c0afd7c: /* original 2998, guest PC 0x0c0afd7c */
if(!s->budget--) { s->failed_pc=0x0c0afd7cu; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0afd7e;
P_0c0afd7e: /* original 8902, guest PC 0x0c0afd7e */
if(!s->budget--) { s->failed_pc=0x0c0afd7eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afd86; }
goto P_0c0afd80;
P_0c0afd80: /* original 6243, guest PC 0x0c0afd80 */
if(!s->budget--) { s->failed_pc=0x0c0afd80u; return 0; }
r[2]=r[4];
goto P_0c0afd82;
P_0c0afd82: /* original 2288, guest PC 0x0c0afd82 */
if(!s->budget--) { s->failed_pc=0x0c0afd82u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[8])==0)!=0);
goto P_0c0afd84;
P_0c0afd84: /* original 892f, guest PC 0x0c0afd84 */
if(!s->budget--) { s->failed_pc=0x0c0afd84u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afde6; }
goto P_0c0afd86;
P_0c0afd86: /* original d329, guest PC 0x0c0afd86 */
if(!s->budget--) { s->failed_pc=0x0c0afd86u; return 0; }
r[3]=read(ram,0x0c0afe2cu,4);
goto P_0c0afd88;
P_0c0afd88: /* original 6233, guest PC 0x0c0afd88 */
if(!s->budget--) { s->failed_pc=0x0c0afd88u; return 0; }
r[2]=r[3];
goto P_0c0afd8a;
P_0c0afd8a: /* original 2f32, guest PC 0x0c0afd8a */
if(!s->budget--) { s->failed_pc=0x0c0afd8au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0afd8c;
P_0c0afd8c: /* original 2269, guest PC 0x0c0afd8c */
if(!s->budget--) { s->failed_pc=0x0c0afd8cu; return 0; }
r[2]&=r[6];
goto P_0c0afd8e;
P_0c0afd8e: /* original 1f21, guest PC 0x0c0afd8e */
if(!s->budget--) { s->failed_pc=0x0c0afd8eu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0afd90;
P_0c0afd90: /* original 63f2, guest PC 0x0c0afd90 */
if(!s->budget--) { s->failed_pc=0x0c0afd90u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0afd92;
P_0c0afd92: /* original 3230, guest PC 0x0c0afd92 */
if(!s->budget--) { s->failed_pc=0x0c0afd92u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0afd94;
P_0c0afd94: /* original 8936, guest PC 0x0c0afd94 */
if(!s->budget--) { s->failed_pc=0x0c0afd94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afe04; }
goto P_0c0afd96;
P_0c0afd96: /* original 2aa8, guest PC 0x0c0afd96 */
if(!s->budget--) { s->failed_pc=0x0c0afd96u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0afd98;
P_0c0afd98: /* original 8918, guest PC 0x0c0afd98 */
if(!s->budget--) { s->failed_pc=0x0c0afd98u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afdcc; }
goto P_0c0afd9a;
P_0c0afd9a: /* original 2778, guest PC 0x0c0afd9a */
if(!s->budget--) { s->failed_pc=0x0c0afd9au; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0afd9c;
P_0c0afd9c: /* original 8b01, guest PC 0x0c0afd9c */
if(!s->budget--) { s->failed_pc=0x0c0afd9cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afda2; }
goto P_0c0afd9e;
P_0c0afd9e: /* original a094, guest PC 0x0c0afd9e */
if(!s->budget--) { s->failed_pc=0x0c0afd9eu; return 0; }
goto P_0c0afeca;
P_0c0afda0: /* original 0009, guest PC 0x0c0afda0 */
if(!s->budget--) { s->failed_pc=0x0c0afda0u; return 0; }
goto P_0c0afda2;
P_0c0afda2: /* original 9038, guest PC 0x0c0afda2 */
if(!s->budget--) { s->failed_pc=0x0c0afda2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afe16u,2);
goto P_0c0afda4;
P_0c0afda4: /* original d322, guest PC 0x0c0afda4 */
if(!s->budget--) { s->failed_pc=0x0c0afda4u; return 0; }
r[3]=read(ram,0x0c0afe30u,4);
goto P_0c0afda6;
P_0c0afda6: /* original 02ee, guest PC 0x0c0afda6 */
if(!s->budget--) { s->failed_pc=0x0c0afda6u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0afda8;
P_0c0afda8: /* original 2238, guest PC 0x0c0afda8 */
if(!s->budget--) { s->failed_pc=0x0c0afda8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0afdaa;
P_0c0afdaa: /* original 8947, guest PC 0x0c0afdaa */
if(!s->budget--) { s->failed_pc=0x0c0afdaau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afe3c; }
goto P_0c0afdac;
P_0c0afdac: /* original 9034, guest PC 0x0c0afdac */
if(!s->budget--) { s->failed_pc=0x0c0afdacu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afe18u,2);
goto P_0c0afdae;
P_0c0afdae: /* original 015d, guest PC 0x0c0afdae */
if(!s->budget--) { s->failed_pc=0x0c0afdaeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0afdb0;
P_0c0afdb0: /* original 4115, guest PC 0x0c0afdb0 */
if(!s->budget--) { s->failed_pc=0x0c0afdb0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c0afdb2;
P_0c0afdb2: /* original 8b01, guest PC 0x0c0afdb2 */
if(!s->budget--) { s->failed_pc=0x0c0afdb2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afdb8; }
goto P_0c0afdb4;
P_0c0afdb4: /* original a089, guest PC 0x0c0afdb4 */
if(!s->budget--) { s->failed_pc=0x0c0afdb4u; return 0; }
goto P_0c0afeca;
P_0c0afdb6: /* original 0009, guest PC 0x0c0afdb6 */
if(!s->budget--) { s->failed_pc=0x0c0afdb6u; return 0; }
goto P_0c0afdb8;
P_0c0afdb8: /* original 6363, guest PC 0x0c0afdb8 */
if(!s->budget--) { s->failed_pc=0x0c0afdb8u; return 0; }
r[3]=r[6];
goto P_0c0afdba;
P_0c0afdba: /* original 2388, guest PC 0x0c0afdba */
if(!s->budget--) { s->failed_pc=0x0c0afdbau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0afdbc;
P_0c0afdbc: /* original 8b13, guest PC 0x0c0afdbc */
if(!s->budget--) { s->failed_pc=0x0c0afdbcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afde6; }
goto P_0c0afdbe;
P_0c0afdbe: /* original 2c68, guest PC 0x0c0afdbe */
if(!s->budget--) { s->failed_pc=0x0c0afdbeu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[6])==0)!=0);
goto P_0c0afdc0;
P_0c0afdc0: /* original 8b11, guest PC 0x0c0afdc0 */
if(!s->budget--) { s->failed_pc=0x0c0afdc0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afde6; }
goto P_0c0afdc2;
P_0c0afdc2: /* original d31c, guest PC 0x0c0afdc2 */
if(!s->budget--) { s->failed_pc=0x0c0afdc2u; return 0; }
r[3]=read(ram,0x0c0afe34u,4);
goto P_0c0afdc4;
P_0c0afdc4: /* original 2368, guest PC 0x0c0afdc4 */
if(!s->budget--) { s->failed_pc=0x0c0afdc4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0afdc6;
P_0c0afdc6: /* original 8b0e, guest PC 0x0c0afdc6 */
if(!s->budget--) { s->failed_pc=0x0c0afdc6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afde6; }
goto P_0c0afdc8;
P_0c0afdc8: /* original a01c, guest PC 0x0c0afdc8 */
if(!s->budget--) { s->failed_pc=0x0c0afdc8u; return 0; }
goto P_0c0afe04;
P_0c0afdca: /* original 0009, guest PC 0x0c0afdca */
if(!s->budget--) { s->failed_pc=0x0c0afdcau; return 0; }
goto P_0c0afdcc;
P_0c0afdcc: /* original 2bb8, guest PC 0x0c0afdcc */
if(!s->budget--) { s->failed_pc=0x0c0afdccu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0afdce;
P_0c0afdce: /* original 8b0a, guest PC 0x0c0afdce */
if(!s->budget--) { s->failed_pc=0x0c0afdceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afde6; }
goto P_0c0afdd0;
P_0c0afdd0: /* original e102, guest PC 0x0c0afdd0 */
if(!s->budget--) { s->failed_pc=0x0c0afdd0u; return 0; }
r[1]=0x00000002u;
goto P_0c0afdd2;
P_0c0afdd2: /* original 2418, guest PC 0x0c0afdd2 */
if(!s->budget--) { s->failed_pc=0x0c0afdd2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[1])==0)!=0);
goto P_0c0afdd4;
P_0c0afdd4: /* original 8b0c, guest PC 0x0c0afdd4 */
if(!s->budget--) { s->failed_pc=0x0c0afdd4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afdf0; }
goto P_0c0afdd6;
P_0c0afdd6: /* original a078, guest PC 0x0c0afdd6 */
if(!s->budget--) { s->failed_pc=0x0c0afdd6u; return 0; }
goto P_0c0afeca;
P_0c0afdd8: /* original 0009, guest PC 0x0c0afdd8 */
if(!s->budget--) { s->failed_pc=0x0c0afdd8u; return 0; }
goto P_0c0afdda;
P_0c0afdda: /* original 85ef, guest PC 0x0c0afdda */
if(!s->budget--) { s->failed_pc=0x0c0afddau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0afddc;
P_0c0afddc: /* original 640d, guest PC 0x0c0afddc */
if(!s->budget--) { s->failed_pc=0x0c0afddcu; return 0; }
r[4]=r[0]&65535u;
goto P_0c0afdde;
P_0c0afdde: /* original 855f, guest PC 0x0c0afdde */
if(!s->budget--) { s->failed_pc=0x0c0afddeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+30,2);
goto P_0c0afde0;
P_0c0afde0: /* original 660d, guest PC 0x0c0afde0 */
if(!s->budget--) { s->failed_pc=0x0c0afde0u; return 0; }
r[6]=r[0]&65535u;
goto P_0c0afde2;
P_0c0afde2: /* original a013, guest PC 0x0c0afde2 */
if(!s->budget--) { s->failed_pc=0x0c0afde2u; return 0; }
r[5]=r[6];
goto P_0c0afe0c;
P_0c0afde4: /* original 6563, guest PC 0x0c0afde4 */
if(!s->budget--) { s->failed_pc=0x0c0afde4u; return 0; }
r[5]=r[6];
goto P_0c0afde6;
P_0c0afde6: /* original d214, guest PC 0x0c0afde6 */
if(!s->budget--) { s->failed_pc=0x0c0afde6u; return 0; }
r[2]=read(ram,0x0c0afe38u,4);
goto P_0c0afde8;
P_0c0afde8: /* original 2628, guest PC 0x0c0afde8 */
if(!s->budget--) { s->failed_pc=0x0c0afde8u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c0afdea;
P_0c0afdea: /* original 890b, guest PC 0x0c0afdea */
if(!s->budget--) { s->failed_pc=0x0c0afdeau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afe04; }
goto P_0c0afdec;
P_0c0afdec: /* original a001, guest PC 0x0c0afdec */
if(!s->budget--) { s->failed_pc=0x0c0afdecu; return 0; }
r[4]=0x0000005bu;
goto P_0c0afdf2;
P_0c0afdee: /* original e45b, guest PC 0x0c0afdee */
if(!s->budget--) { s->failed_pc=0x0c0afdeeu; return 0; }
r[4]=0x0000005bu;
goto P_0c0afdf0;
P_0c0afdf0: /* original 9413, guest PC 0x0c0afdf0 */
if(!s->budget--) { s->failed_pc=0x0c0afdf0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afe1au,2);
goto P_0c0afdf2;
P_0c0afdf2: /* original 9013, guest PC 0x0c0afdf2 */
if(!s->budget--) { s->failed_pc=0x0c0afdf2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afe1cu,2);
goto P_0c0afdf4;
P_0c0afdf4: /* original 63d3, guest PC 0x0c0afdf4 */
if(!s->budget--) { s->failed_pc=0x0c0afdf4u; return 0; }
r[3]=r[13];
goto P_0c0afdf6;
P_0c0afdf6: /* original 9612, guest PC 0x0c0afdf6 */
if(!s->budget--) { s->failed_pc=0x0c0afdf6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afe1eu,2);
goto P_0c0afdf8;
P_0c0afdf8: /* original 05ed, guest PC 0x0c0afdf8 */
if(!s->budget--) { s->failed_pc=0x0c0afdf8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0afdfa;
P_0c0afdfa: /* original 655d, guest PC 0x0c0afdfa */
if(!s->budget--) { s->failed_pc=0x0c0afdfau; return 0; }
r[5]=r[5]&65535u;
goto P_0c0afdfc;
P_0c0afdfc: /* original 3358, guest PC 0x0c0afdfc */
if(!s->budget--) { s->failed_pc=0x0c0afdfcu; return 0; }
r[3]-=r[5];
goto P_0c0afdfe;
P_0c0afdfe: /* original 6533, guest PC 0x0c0afdfe */
if(!s->budget--) { s->failed_pc=0x0c0afdfeu; return 0; }
r[5]=r[3];
goto P_0c0afe00;
P_0c0afe00: /* original a024, guest PC 0x0c0afe00 */
if(!s->budget--) { s->failed_pc=0x0c0afe00u; return 0; }
r[7]=0x00000001u;
goto P_0c0afe4c;
P_0c0afe02: /* original e701, guest PC 0x0c0afe02 */
if(!s->budget--) { s->failed_pc=0x0c0afe02u; return 0; }
r[7]=0x00000001u;
goto P_0c0afe04;
P_0c0afe04: /* original 900a, guest PC 0x0c0afe04 */
if(!s->budget--) { s->failed_pc=0x0c0afe04u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afe1cu,2);
goto P_0c0afe06;
P_0c0afe06: /* original 65d3, guest PC 0x0c0afe06 */
if(!s->budget--) { s->failed_pc=0x0c0afe06u; return 0; }
r[5]=r[13];
goto P_0c0afe08;
P_0c0afe08: /* original 04ed, guest PC 0x0c0afe08 */
if(!s->budget--) { s->failed_pc=0x0c0afe08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0afe0a;
P_0c0afe0a: /* original 644d, guest PC 0x0c0afe0a */
if(!s->budget--) { s->failed_pc=0x0c0afe0au; return 0; }
r[4]=r[4]&65535u;
goto P_0c0afe0c;
P_0c0afe0c: /* original 3548, guest PC 0x0c0afe0c */
if(!s->budget--) { s->failed_pc=0x0c0afe0cu; return 0; }
r[5]-=r[4];
goto P_0c0afe0e;
P_0c0afe0e: /* original 9408, guest PC 0x0c0afe0e */
if(!s->budget--) { s->failed_pc=0x0c0afe0eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afe22u,2);
goto P_0c0afe10;
P_0c0afe10: /* original 9606, guest PC 0x0c0afe10 */
if(!s->budget--) { s->failed_pc=0x0c0afe10u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afe20u,2);
goto P_0c0afe12;
P_0c0afe12: /* original a01b, guest PC 0x0c0afe12 */
if(!s->budget--) { s->failed_pc=0x0c0afe12u; return 0; }
r[7]=0x00000000u;
goto P_0c0afe4c;
P_0c0afe14: /* original e700, guest PC 0x0c0afe14 */
if(!s->budget--) { s->failed_pc=0x0c0afe14u; return 0; }
r[7]=0x00000000u;
if(!vf3_matrix_family(0x0c0afe16u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0afe16u; return 0; } return 1;
P_0c0afe3c: /* original 9051, guest PC 0x0c0afe3c */
if(!s->budget--) { s->failed_pc=0x0c0afe3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afee2u,2);
goto P_0c0afe3e;
P_0c0afe3e: /* original 65d3, guest PC 0x0c0afe3e */
if(!s->budget--) { s->failed_pc=0x0c0afe3eu; return 0; }
r[5]=r[13];
goto P_0c0afe40;
P_0c0afe40: /* original e700, guest PC 0x0c0afe40 */
if(!s->budget--) { s->failed_pc=0x0c0afe40u; return 0; }
r[7]=0x00000000u;
goto P_0c0afe42;
P_0c0afe42: /* original 04ed, guest PC 0x0c0afe42 */
if(!s->budget--) { s->failed_pc=0x0c0afe42u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0afe44;
P_0c0afe44: /* original 644d, guest PC 0x0c0afe44 */
if(!s->budget--) { s->failed_pc=0x0c0afe44u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0afe46;
P_0c0afe46: /* original 3548, guest PC 0x0c0afe46 */
if(!s->budget--) { s->failed_pc=0x0c0afe46u; return 0; }
r[5]-=r[4];
goto P_0c0afe48;
P_0c0afe48: /* original 944c, guest PC 0x0c0afe48 */
if(!s->budget--) { s->failed_pc=0x0c0afe48u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afee4u,2);
goto P_0c0afe4a;
P_0c0afe4a: /* original 6643, guest PC 0x0c0afe4a */
if(!s->budget--) { s->failed_pc=0x0c0afe4au; return 0; }
r[6]=r[4];
goto P_0c0afe4c;
P_0c0afe4c: /* original 6d5f, guest PC 0x0c0afe4c */
if(!s->budget--) { s->failed_pc=0x0c0afe4cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c0afe4e;
P_0c0afe4e: /* original 656b, guest PC 0x0c0afe4e */
if(!s->budget--) { s->failed_pc=0x0c0afe4eu; return 0; }
r[5]=0u-r[6];
goto P_0c0afe50;
P_0c0afe50: /* original 3d53, guest PC 0x0c0afe50 */
if(!s->budget--) { s->failed_pc=0x0c0afe50u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[5])!=0);
goto P_0c0afe52;
P_0c0afe52: /* original 8b01, guest PC 0x0c0afe52 */
if(!s->budget--) { s->failed_pc=0x0c0afe52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afe58; }
goto P_0c0afe54;
P_0c0afe54: /* original 3d67, guest PC 0x0c0afe54 */
if(!s->budget--) { s->failed_pc=0x0c0afe54u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>(int32_t)r[6])!=0);
goto P_0c0afe56;
P_0c0afe56: /* original 8b04, guest PC 0x0c0afe56 */
if(!s->budget--) { s->failed_pc=0x0c0afe56u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afe62; }
goto P_0c0afe58;
P_0c0afe58: /* original 2778, guest PC 0x0c0afe58 */
if(!s->budget--) { s->failed_pc=0x0c0afe58u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0afe5a;
P_0c0afe5a: /* original 8b36, guest PC 0x0c0afe5a */
if(!s->budget--) { s->failed_pc=0x0c0afe5au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afeca; }
goto P_0c0afe5c;
P_0c0afe5c: /* original d323, guest PC 0x0c0afe5c */
if(!s->budget--) { s->failed_pc=0x0c0afe5cu; return 0; }
r[3]=read(ram,0x0c0afeecu,4);
goto P_0c0afe5e;
P_0c0afe5e: /* original 2d3a, guest PC 0x0c0afe5e */
if(!s->budget--) { s->failed_pc=0x0c0afe5eu; return 0; }
r[13]^=r[3];
goto P_0c0afe60;
P_0c0afe60: /* original 6ddf, guest PC 0x0c0afe60 */
if(!s->budget--) { s->failed_pc=0x0c0afe60u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c0afe62;
P_0c0afe62: /* original 654b, guest PC 0x0c0afe62 */
if(!s->budget--) { s->failed_pc=0x0c0afe62u; return 0; }
r[5]=0u-r[4];
goto P_0c0afe64;
P_0c0afe64: /* original 3d53, guest PC 0x0c0afe64 */
if(!s->budget--) { s->failed_pc=0x0c0afe64u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[5])!=0);
goto P_0c0afe66;
P_0c0afe66: /* original 8901, guest PC 0x0c0afe66 */
if(!s->budget--) { s->failed_pc=0x0c0afe66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afe6c; }
goto P_0c0afe68;
P_0c0afe68: /* original a003, guest PC 0x0c0afe68 */
if(!s->budget--) { s->failed_pc=0x0c0afe68u; return 0; }
r[13]=r[5];
goto P_0c0afe72;
P_0c0afe6a: /* original 6d53, guest PC 0x0c0afe6a */
if(!s->budget--) { s->failed_pc=0x0c0afe6au; return 0; }
r[13]=r[5];
goto P_0c0afe6c;
P_0c0afe6c: /* original 3d47, guest PC 0x0c0afe6c */
if(!s->budget--) { s->failed_pc=0x0c0afe6cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>(int32_t)r[4])!=0);
goto P_0c0afe6e;
P_0c0afe6e: /* original 8b00, guest PC 0x0c0afe6e */
if(!s->budget--) { s->failed_pc=0x0c0afe6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afe72; }
goto P_0c0afe70;
P_0c0afe70: /* original 6d43, guest PC 0x0c0afe70 */
if(!s->budget--) { s->failed_pc=0x0c0afe70u; return 0; }
r[13]=r[4];
goto P_0c0afe72;
P_0c0afe72: /* original 63e2, guest PC 0x0c0afe72 */
if(!s->budget--) { s->failed_pc=0x0c0afe72u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0afe74;
P_0c0afe74: /* original 2838, guest PC 0x0c0afe74 */
if(!s->budget--) { s->failed_pc=0x0c0afe74u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[3])==0)!=0);
goto P_0c0afe76;
P_0c0afe76: /* original 8904, guest PC 0x0c0afe76 */
if(!s->budget--) { s->failed_pc=0x0c0afe76u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afe82; }
goto P_0c0afe78;
P_0c0afe78: /* original 9035, guest PC 0x0c0afe78 */
if(!s->budget--) { s->failed_pc=0x0c0afe78u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afee6u,2);
goto P_0c0afe7a;
P_0c0afe7a: /* original 00ec, guest PC 0x0c0afe7a */
if(!s->budget--) { s->failed_pc=0x0c0afe7au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0afe7c;
P_0c0afe7c: /* original 600c, guest PC 0x0c0afe7c */
if(!s->budget--) { s->failed_pc=0x0c0afe7cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0afe7e;
P_0c0afe7e: /* original c801, guest PC 0x0c0afe7e */
if(!s->budget--) { s->failed_pc=0x0c0afe7eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0afe80;
P_0c0afe80: /* original 8b20, guest PC 0x0c0afe80 */
if(!s->budget--) { s->failed_pc=0x0c0afe80u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afec4; }
goto P_0c0afe82;
P_0c0afe82: /* original 9031, guest PC 0x0c0afe82 */
if(!s->budget--) { s->failed_pc=0x0c0afe82u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afee8u,2);
goto P_0c0afe84;
P_0c0afe84: /* original 65f3, guest PC 0x0c0afe84 */
if(!s->budget--) { s->failed_pc=0x0c0afe84u; return 0; }
r[5]=r[15];
goto P_0c0afe86;
P_0c0afe86: /* original 66f3, guest PC 0x0c0afe86 */
if(!s->budget--) { s->failed_pc=0x0c0afe86u; return 0; }
r[6]=r[15];
goto P_0c0afe88;
P_0c0afe88: /* original 7510, guest PC 0x0c0afe88 */
if(!s->budget--) { s->failed_pc=0x0c0afe88u; return 0; }
r[5]+=0x00000010u;
goto P_0c0afe8a;
P_0c0afe8a: /* original fee6, guest PC 0x0c0afe8a */
if(!s->budget--) { s->failed_pc=0x0c0afe8au; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c0afe8c;
P_0c0afe8c: /* original 7008, guest PC 0x0c0afe8c */
if(!s->budget--) { s->failed_pc=0x0c0afe8cu; return 0; }
r[0]+=0x00000008u;
goto P_0c0afe8e;
P_0c0afe8e: /* original ffe6, guest PC 0x0c0afe8e */
if(!s->budget--) { s->failed_pc=0x0c0afe8eu; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0afe90;
P_0c0afe90: /* original e010, guest PC 0x0c0afe90 */
if(!s->budget--) { s->failed_pc=0x0c0afe90u; return 0; }
r[0]=0x00000010u;
goto P_0c0afe92;
P_0c0afe92: /* original f5e6, guest PC 0x0c0afe92 */
if(!s->budget--) { s->failed_pc=0x0c0afe92u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0afe94;
P_0c0afe94: /* original e018, guest PC 0x0c0afe94 */
if(!s->budget--) { s->failed_pc=0x0c0afe94u; return 0; }
r[0]=0x00000018u;
goto P_0c0afe96;
P_0c0afe96: /* original f4e6, guest PC 0x0c0afe96 */
if(!s->budget--) { s->failed_pc=0x0c0afe96u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0afe98;
P_0c0afe98: /* original e010, guest PC 0x0c0afe98 */
if(!s->budget--) { s->failed_pc=0x0c0afe98u; return 0; }
r[0]=0x00000010u;
goto P_0c0afe9a;
P_0c0afe9a: /* original f5e1, guest PC 0x0c0afe9a */
if(!s->budget--) { s->failed_pc=0x0c0afe9au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'-');
goto P_0c0afe9c;
P_0c0afe9c: /* original 760c, guest PC 0x0c0afe9c */
if(!s->budget--) { s->failed_pc=0x0c0afe9cu; return 0; }
r[6]+=0x0000000cu;
goto P_0c0afe9e;
P_0c0afe9e: /* original f4f1, guest PC 0x0c0afe9e */
if(!s->budget--) { s->failed_pc=0x0c0afe9eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
goto P_0c0afea0;
P_0c0afea0: /* original ff57, guest PC 0x0c0afea0 */
if(!s->budget--) { s->failed_pc=0x0c0afea0u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0afea2;
P_0c0afea2: /* original e00c, guest PC 0x0c0afea2 */
if(!s->budget--) { s->failed_pc=0x0c0afea2u; return 0; }
r[0]=0x0000000cu;
goto P_0c0afea4;
P_0c0afea4: /* original ff47, guest PC 0x0c0afea4 */
if(!s->budget--) { s->failed_pc=0x0c0afea4u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0afea6;
P_0c0afea6: /* original d312, guest PC 0x0c0afea6 */
if(!s->budget--) { s->failed_pc=0x0c0afea6u; return 0; }
r[3]=read(ram,0x0c0afef0u,4);
goto P_0c0afea8;
P_0c0afea8: /* original 430b, guest PC 0x0c0afea8 */
if(!s->budget--) { s->failed_pc=0x0c0afea8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0afeacu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0afeacu) { target=s->pc; goto dispatch; }
goto P_0c0afeac;
P_0c0afeaa: /* original 64d3, guest PC 0x0c0afeaa */
if(!s->budget--) { s->failed_pc=0x0c0afeaau; return 0; }
r[4]=r[13];
goto P_0c0afeac;
P_0c0afeac: /* original e010, guest PC 0x0c0afeac */
if(!s->budget--) { s->failed_pc=0x0c0afeacu; return 0; }
r[0]=0x00000010u;
goto P_0c0afeae;
P_0c0afeae: /* original f4ec, guest PC 0x0c0afeae */
if(!s->budget--) { s->failed_pc=0x0c0afeaeu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0afeb0;
P_0c0afeb0: /* original f3f6, guest PC 0x0c0afeb0 */
if(!s->budget--) { s->failed_pc=0x0c0afeb0u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0afeb2;
P_0c0afeb2: /* original e00c, guest PC 0x0c0afeb2 */
if(!s->budget--) { s->failed_pc=0x0c0afeb2u; return 0; }
r[0]=0x0000000cu;
goto P_0c0afeb4;
P_0c0afeb4: /* original f2f6, guest PC 0x0c0afeb4 */
if(!s->budget--) { s->failed_pc=0x0c0afeb4u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0afeb6;
P_0c0afeb6: /* original e010, guest PC 0x0c0afeb6 */
if(!s->budget--) { s->failed_pc=0x0c0afeb6u; return 0; }
r[0]=0x00000010u;
goto P_0c0afeb8;
P_0c0afeb8: /* original f430, guest PC 0x0c0afeb8 */
if(!s->budget--) { s->failed_pc=0x0c0afeb8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0afeba;
P_0c0afeba: /* original f5fc, guest PC 0x0c0afeba */
if(!s->budget--) { s->failed_pc=0x0c0afebau; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0afebc;
P_0c0afebc: /* original f520, guest PC 0x0c0afebc */
if(!s->budget--) { s->failed_pc=0x0c0afebcu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'+');
goto P_0c0afebe;
P_0c0afebe: /* original fe47, guest PC 0x0c0afebe */
if(!s->budget--) { s->failed_pc=0x0c0afebeu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0afec0;
P_0c0afec0: /* original e018, guest PC 0x0c0afec0 */
if(!s->budget--) { s->failed_pc=0x0c0afec0u; return 0; }
r[0]=0x00000018u;
goto P_0c0afec2;
P_0c0afec2: /* original fe57, guest PC 0x0c0afec2 */
if(!s->budget--) { s->failed_pc=0x0c0afec2u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0afec4;
P_0c0afec4: /* original 85ef, guest PC 0x0c0afec4 */
if(!s->budget--) { s->failed_pc=0x0c0afec4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0afec6;
P_0c0afec6: /* original 30dc, guest PC 0x0c0afec6 */
if(!s->budget--) { s->failed_pc=0x0c0afec6u; return 0; }
r[0]+=r[13];
goto P_0c0afec8;
P_0c0afec8: /* original 81ef, guest PC 0x0c0afec8 */
if(!s->budget--) { s->failed_pc=0x0c0afec8u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0afeca;
P_0c0afeca: /* original 7f1c, guest PC 0x0c0afeca */
if(!s->budget--) { s->failed_pc=0x0c0afecau; return 0; }
r[15]+=0x0000001cu;
goto P_0c0afecc;
P_0c0afecc: /* original 4f26, guest PC 0x0c0afecc */
if(!s->budget--) { s->failed_pc=0x0c0afeccu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0afece;
P_0c0afece: /* original fef9, guest PC 0x0c0afece */
if(!s->budget--) { s->failed_pc=0x0c0afeceu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0afed0;
P_0c0afed0: /* original fff9, guest PC 0x0c0afed0 */
if(!s->budget--) { s->failed_pc=0x0c0afed0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0afed2;
P_0c0afed2: /* original 68f6, guest PC 0x0c0afed2 */
if(!s->budget--) { s->failed_pc=0x0c0afed2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0afed4;
P_0c0afed4: /* original 69f6, guest PC 0x0c0afed4 */
if(!s->budget--) { s->failed_pc=0x0c0afed4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0afed6;
P_0c0afed6: /* original 6af6, guest PC 0x0c0afed6 */
if(!s->budget--) { s->failed_pc=0x0c0afed6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0afed8;
P_0c0afed8: /* original 6bf6, guest PC 0x0c0afed8 */
if(!s->budget--) { s->failed_pc=0x0c0afed8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0afeda;
P_0c0afeda: /* original 6cf6, guest PC 0x0c0afeda */
if(!s->budget--) { s->failed_pc=0x0c0afedau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0afedc;
P_0c0afedc: /* original 6df6, guest PC 0x0c0afedc */
if(!s->budget--) { s->failed_pc=0x0c0afedcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0afede;
P_0c0afede: /* original 000b, guest PC 0x0c0afede */
if(!s->budget--) { s->failed_pc=0x0c0afedeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0afee0: /* original 6ef6, guest PC 0x0c0afee0 */
if(!s->budget--) { s->failed_pc=0x0c0afee0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0afee2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0afee2u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
