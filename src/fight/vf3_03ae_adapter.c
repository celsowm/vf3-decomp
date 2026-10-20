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
int vf3_03ae_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03acf0u: goto P_0c03acf0;
case 0x0c03acf2u: goto P_0c03acf2;
case 0x0c03acf4u: goto P_0c03acf4;
case 0x0c03acf6u: goto P_0c03acf6;
case 0x0c03acf8u: goto P_0c03acf8;
case 0x0c03acfau: goto P_0c03acfa;
case 0x0c03acfcu: goto P_0c03acfc;
case 0x0c03acfeu: goto P_0c03acfe;
case 0x0c03ad00u: goto P_0c03ad00;
case 0x0c03ad02u: goto P_0c03ad02;
case 0x0c03ad04u: goto P_0c03ad04;
case 0x0c03ad06u: goto P_0c03ad06;
case 0x0c03ad08u: goto P_0c03ad08;
case 0x0c03ad0au: goto P_0c03ad0a;
case 0x0c03ad0cu: goto P_0c03ad0c;
case 0x0c03ad0eu: goto P_0c03ad0e;
case 0x0c03ad10u: goto P_0c03ad10;
case 0x0c03ad12u: goto P_0c03ad12;
case 0x0c03ad14u: goto P_0c03ad14;
case 0x0c03ad16u: goto P_0c03ad16;
case 0x0c03ad18u: goto P_0c03ad18;
case 0x0c03ad1au: goto P_0c03ad1a;
case 0x0c03ad1cu: goto P_0c03ad1c;
case 0x0c03ad1eu: goto P_0c03ad1e;
case 0x0c03ad20u: goto P_0c03ad20;
case 0x0c03ad22u: goto P_0c03ad22;
case 0x0c03ad24u: goto P_0c03ad24;
case 0x0c03ad26u: goto P_0c03ad26;
case 0x0c03ad28u: goto P_0c03ad28;
case 0x0c03ad2au: goto P_0c03ad2a;
case 0x0c03ad2cu: goto P_0c03ad2c;
case 0x0c03ad2eu: goto P_0c03ad2e;
case 0x0c03ad30u: goto P_0c03ad30;
case 0x0c03ad32u: goto P_0c03ad32;
case 0x0c03ad34u: goto P_0c03ad34;
case 0x0c03ad36u: goto P_0c03ad36;
case 0x0c03ad38u: goto P_0c03ad38;
case 0x0c03ad3au: goto P_0c03ad3a;
case 0x0c03ad3cu: goto P_0c03ad3c;
case 0x0c03ad3eu: goto P_0c03ad3e;
case 0x0c03ad40u: goto P_0c03ad40;
case 0x0c03ad50u: goto P_0c03ad50;
case 0x0c03ad52u: goto P_0c03ad52;
case 0x0c03ad54u: goto P_0c03ad54;
case 0x0c03ad56u: goto P_0c03ad56;
case 0x0c03ad58u: goto P_0c03ad58;
case 0x0c03ad5au: goto P_0c03ad5a;
case 0x0c03ad5cu: goto P_0c03ad5c;
case 0x0c03ad5eu: goto P_0c03ad5e;
case 0x0c03ad60u: goto P_0c03ad60;
case 0x0c03ad62u: goto P_0c03ad62;
case 0x0c03ad64u: goto P_0c03ad64;
case 0x0c03ad66u: goto P_0c03ad66;
case 0x0c03ad68u: goto P_0c03ad68;
case 0x0c03ad6au: goto P_0c03ad6a;
case 0x0c03ad6cu: goto P_0c03ad6c;
case 0x0c03ad6eu: goto P_0c03ad6e;
case 0x0c03ad70u: goto P_0c03ad70;
case 0x0c03ad72u: goto P_0c03ad72;
case 0x0c03ad80u: goto P_0c03ad80;
case 0x0c03ad82u: goto P_0c03ad82;
case 0x0c03ad84u: goto P_0c03ad84;
case 0x0c03ad86u: goto P_0c03ad86;
case 0x0c03ad88u: goto P_0c03ad88;
case 0x0c03ad8au: goto P_0c03ad8a;
case 0x0c03ad8cu: goto P_0c03ad8c;
case 0x0c03ad8eu: goto P_0c03ad8e;
case 0x0c03ad90u: goto P_0c03ad90;
case 0x0c03ad92u: goto P_0c03ad92;
case 0x0c03ad94u: goto P_0c03ad94;
case 0x0c03ad96u: goto P_0c03ad96;
case 0x0c03ad98u: goto P_0c03ad98;
case 0x0c03ada0u: goto P_0c03ada0;
case 0x0c03ada2u: goto P_0c03ada2;
case 0x0c03ada4u: goto P_0c03ada4;
case 0x0c03ada6u: goto P_0c03ada6;
case 0x0c03ada8u: goto P_0c03ada8;
case 0x0c03adaau: goto P_0c03adaa;
case 0x0c03adacu: goto P_0c03adac;
case 0x0c03adb0u: goto P_0c03adb0;
case 0x0c03adb2u: goto P_0c03adb2;
case 0x0c03adb4u: goto P_0c03adb4;
case 0x0c03adb6u: goto P_0c03adb6;
case 0x0c03adb8u: goto P_0c03adb8;
case 0x0c03adbau: goto P_0c03adba;
case 0x0c03adbcu: goto P_0c03adbc;
case 0x0c03adbeu: goto P_0c03adbe;
case 0x0c03adc0u: goto P_0c03adc0;
case 0x0c03adc2u: goto P_0c03adc2;
case 0x0c03adc4u: goto P_0c03adc4;
case 0x0c03adc6u: goto P_0c03adc6;
case 0x0c03adc8u: goto P_0c03adc8;
case 0x0c03adcau: goto P_0c03adca;
case 0x0c03adccu: goto P_0c03adcc;
case 0x0c03adceu: goto P_0c03adce;
case 0x0c03add0u: goto P_0c03add0;
case 0x0c03add2u: goto P_0c03add2;
case 0x0c03ade0u: goto P_0c03ade0;
case 0x0c03ade2u: goto P_0c03ade2;
case 0x0c03ade4u: goto P_0c03ade4;
case 0x0c03ade6u: goto P_0c03ade6;
case 0x0c03ade8u: goto P_0c03ade8;
case 0x0c03adeau: goto P_0c03adea;
case 0x0c03adecu: goto P_0c03adec;
case 0x0c03adeeu: goto P_0c03adee;
case 0x0c03adf0u: goto P_0c03adf0;
case 0x0c03adf2u: goto P_0c03adf2;
case 0x0c03adf4u: goto P_0c03adf4;
case 0x0c03adf6u: goto P_0c03adf6;
case 0x0c03adf8u: goto P_0c03adf8;
case 0x0c03ae16u: goto P_0c03ae16;
case 0x0c03ae18u: goto P_0c03ae18;
case 0x0c03ae1au: goto P_0c03ae1a;
case 0x0c03ae1cu: goto P_0c03ae1c;
case 0x0c03ae1eu: goto P_0c03ae1e;
case 0x0c03ae20u: goto P_0c03ae20;
case 0x0c03ae30u: goto P_0c03ae30;
case 0x0c03ae32u: goto P_0c03ae32;
case 0x0c03ae34u: goto P_0c03ae34;
case 0x0c03ae36u: goto P_0c03ae36;
case 0x0c03ae38u: goto P_0c03ae38;
case 0x0c03ae3au: goto P_0c03ae3a;
case 0x0c03ae3cu: goto P_0c03ae3c;
case 0x0c03ae3eu: goto P_0c03ae3e;
case 0x0c03ae40u: goto P_0c03ae40;
case 0x0c03ae42u: goto P_0c03ae42;
case 0x0c03ae44u: goto P_0c03ae44;
case 0x0c03ae46u: goto P_0c03ae46;
case 0x0c03ae48u: goto P_0c03ae48;
case 0x0c03ae50u: goto P_0c03ae50;
case 0x0c03ae52u: goto P_0c03ae52;
case 0x0c03ae54u: goto P_0c03ae54;
case 0x0c03ae56u: goto P_0c03ae56;
case 0x0c03ae58u: goto P_0c03ae58;
case 0x0c03ae60u: goto P_0c03ae60;
case 0x0c03ae62u: goto P_0c03ae62;
case 0x0c03ae64u: goto P_0c03ae64;
case 0x0c03ae66u: goto P_0c03ae66;
case 0x0c03ae68u: goto P_0c03ae68;
case 0x0c03ae6au: goto P_0c03ae6a;
case 0x0c03ae6cu: goto P_0c03ae6c;
case 0x0c03ae6eu: goto P_0c03ae6e;
case 0x0c03ae70u: goto P_0c03ae70;
case 0x0c03aeb0u: goto P_0c03aeb0;
case 0x0c03aeb2u: goto P_0c03aeb2;
case 0x0c03aeb4u: goto P_0c03aeb4;
case 0x0c03aeb6u: goto P_0c03aeb6;
case 0x0c03aeb8u: goto P_0c03aeb8;
case 0x0c03aebau: goto P_0c03aeba;
case 0x0c03aec0u: goto P_0c03aec0;
case 0x0c03aec2u: goto P_0c03aec2;
case 0x0c03aec4u: goto P_0c03aec4;
case 0x0c03aec6u: goto P_0c03aec6;
case 0x0c03aec8u: goto P_0c03aec8;
case 0x0c03aecau: goto P_0c03aeca;
case 0x0c03aeccu: goto P_0c03aecc;
case 0x0c03aeceu: goto P_0c03aece;
case 0x0c03aed0u: goto P_0c03aed0;
case 0x0c03aed2u: goto P_0c03aed2;
case 0x0c03aed4u: goto P_0c03aed4;
case 0x0c03aed6u: goto P_0c03aed6;
case 0x0c03aed8u: goto P_0c03aed8;
case 0x0c03aedau: goto P_0c03aeda;
case 0x0c03aedcu: goto P_0c03aedc;
case 0x0c03aedeu: goto P_0c03aede;
case 0x0c03aee0u: goto P_0c03aee0;
case 0x0c03aee2u: goto P_0c03aee2;
case 0x0c03aee4u: goto P_0c03aee4;
case 0x0c03aee6u: goto P_0c03aee6;
case 0x0c03aee8u: goto P_0c03aee8;
case 0x0c03aeeau: goto P_0c03aeea;
case 0x0c03aeecu: goto P_0c03aeec;
case 0x0c03aeeeu: goto P_0c03aeee;
case 0x0c03aef0u: goto P_0c03aef0;
case 0x0c03aef2u: goto P_0c03aef2;
case 0x0c03aef4u: goto P_0c03aef4;
case 0x0c03aef6u: goto P_0c03aef6;
case 0x0c03aef8u: goto P_0c03aef8;
case 0x0c03aefau: goto P_0c03aefa;
case 0x0c03aefcu: goto P_0c03aefc;
case 0x0c03aefeu: goto P_0c03aefe;
case 0x0c03af00u: goto P_0c03af00;
case 0x0c03af02u: goto P_0c03af02;
case 0x0c03af04u: goto P_0c03af04;
case 0x0c03af06u: goto P_0c03af06;
case 0x0c03af08u: goto P_0c03af08;
case 0x0c03af0au: goto P_0c03af0a;
case 0x0c03af0cu: goto P_0c03af0c;
case 0x0c03af0eu: goto P_0c03af0e;
case 0x0c03af10u: goto P_0c03af10;
case 0x0c03af12u: goto P_0c03af12;
case 0x0c03af14u: goto P_0c03af14;
case 0x0c03af16u: goto P_0c03af16;
case 0x0c03af18u: goto P_0c03af18;
case 0x0c03af1au: goto P_0c03af1a;
case 0x0c03af1cu: goto P_0c03af1c;
case 0x0c03af1eu: goto P_0c03af1e;
case 0x0c03af20u: goto P_0c03af20;
case 0x0c03af30u: goto P_0c03af30;
case 0x0c03af32u: goto P_0c03af32;
case 0x0c03af34u: goto P_0c03af34;
case 0x0c03af36u: goto P_0c03af36;
case 0x0c03af38u: goto P_0c03af38;
case 0x0c03af3au: goto P_0c03af3a;
case 0x0c03af3cu: goto P_0c03af3c;
case 0x0c03af3eu: goto P_0c03af3e;
case 0x0c03af40u: goto P_0c03af40;
case 0x0c03af50u: goto P_0c03af50;
case 0x0c03af52u: goto P_0c03af52;
case 0x0c03af54u: goto P_0c03af54;
case 0x0c03af56u: goto P_0c03af56;
case 0x0c03af58u: goto P_0c03af58;
case 0x0c03af5au: goto P_0c03af5a;
case 0x0c03af5cu: goto P_0c03af5c;
case 0x0c03af5eu: goto P_0c03af5e;
case 0x0c03af60u: goto P_0c03af60;
case 0x0c03af70u: goto P_0c03af70;
case 0x0c03af72u: goto P_0c03af72;
case 0x0c03af74u: goto P_0c03af74;
case 0x0c03af76u: goto P_0c03af76;
case 0x0c03af78u: goto P_0c03af78;
case 0x0c03af80u: goto P_0c03af80;
case 0x0c03af82u: goto P_0c03af82;
case 0x0c03af84u: goto P_0c03af84;
case 0x0c03af86u: goto P_0c03af86;
case 0x0c03af88u: goto P_0c03af88;
case 0x0c03af8au: goto P_0c03af8a;
case 0x0c03af8cu: goto P_0c03af8c;
case 0x0c03af8eu: goto P_0c03af8e;
case 0x0c03af90u: goto P_0c03af90;
case 0x0c03af92u: goto P_0c03af92;
case 0x0c03af94u: goto P_0c03af94;
case 0x0c03af96u: goto P_0c03af96;
case 0x0c03af98u: goto P_0c03af98;
case 0x0c03af9au: goto P_0c03af9a;
case 0x0c03af9cu: goto P_0c03af9c;
case 0x0c03af9eu: goto P_0c03af9e;
case 0x0c03afa0u: goto P_0c03afa0;
case 0x0c03afb0u: goto P_0c03afb0;
case 0x0c03afb2u: goto P_0c03afb2;
case 0x0c03afb4u: goto P_0c03afb4;
case 0x0c03afb6u: goto P_0c03afb6;
case 0x0c03afb8u: goto P_0c03afb8;
case 0x0c03afbau: goto P_0c03afba;
case 0x0c03afbcu: goto P_0c03afbc;
case 0x0c03afbeu: goto P_0c03afbe;
case 0x0c03afc0u: goto P_0c03afc0;
case 0x0c03afd0u: goto P_0c03afd0;
case 0x0c03afd2u: goto P_0c03afd2;
case 0x0c03afd4u: goto P_0c03afd4;
case 0x0c03afd6u: goto P_0c03afd6;
case 0x0c03afd8u: goto P_0c03afd8;
case 0x0c03afe0u: goto P_0c03afe0;
case 0x0c03afe2u: goto P_0c03afe2;
case 0x0c03afe4u: goto P_0c03afe4;
case 0x0c03afe6u: goto P_0c03afe6;
case 0x0c03afe8u: goto P_0c03afe8;
case 0x0c03afeau: goto P_0c03afea;
case 0x0c03afecu: goto P_0c03afec;
case 0x0c03afeeu: goto P_0c03afee;
case 0x0c03aff0u: goto P_0c03aff0;
case 0x0c03aff2u: goto P_0c03aff2;
case 0x0c03b000u: goto P_0c03b000;
case 0x0c03b002u: goto P_0c03b002;
case 0x0c03b004u: goto P_0c03b004;
case 0x0c03b006u: goto P_0c03b006;
case 0x0c03b008u: goto P_0c03b008;
case 0x0c03b00au: goto P_0c03b00a;
case 0x0c03b00cu: goto P_0c03b00c;
case 0x0c03b00eu: goto P_0c03b00e;
case 0x0c03b010u: goto P_0c03b010;
case 0x0c03b020u: goto P_0c03b020;
case 0x0c03b022u: goto P_0c03b022;
case 0x0c03b024u: goto P_0c03b024;
case 0x0c03b026u: goto P_0c03b026;
case 0x0c03b028u: goto P_0c03b028;
case 0x0c03b030u: goto P_0c03b030;
case 0x0c03b032u: goto P_0c03b032;
case 0x0c03b034u: goto P_0c03b034;
case 0x0c03b036u: goto P_0c03b036;
case 0x0c03b038u: goto P_0c03b038;
case 0x0c03b03au: goto P_0c03b03a;
case 0x0c03b03cu: goto P_0c03b03c;
case 0x0c03b040u: goto P_0c03b040;
case 0x0c03b042u: goto P_0c03b042;
case 0x0c03b044u: goto P_0c03b044;
case 0x0c03b046u: goto P_0c03b046;
case 0x0c03b048u: goto P_0c03b048;
case 0x0c03b04au: goto P_0c03b04a;
case 0x0c03b04cu: goto P_0c03b04c;
case 0x0c03b04eu: goto P_0c03b04e;
case 0x0c03b050u: goto P_0c03b050;
case 0x0c03b060u: goto P_0c03b060;
case 0x0c03b062u: goto P_0c03b062;
case 0x0c03b064u: goto P_0c03b064;
case 0x0c03b066u: goto P_0c03b066;
case 0x0c03b068u: goto P_0c03b068;
case 0x0c03b06au: goto P_0c03b06a;
case 0x0c03b070u: goto P_0c03b070;
case 0x0c03b072u: goto P_0c03b072;
case 0x0c03b074u: goto P_0c03b074;
case 0x0c03b076u: goto P_0c03b076;
case 0x0c03b078u: goto P_0c03b078;
case 0x0c03b07au: goto P_0c03b07a;
case 0x0c03b07cu: goto P_0c03b07c;
case 0x0c03b080u: goto P_0c03b080;
case 0x0c03b082u: goto P_0c03b082;
case 0x0c03b084u: goto P_0c03b084;
case 0x0c03b086u: goto P_0c03b086;
case 0x0c03b088u: goto P_0c03b088;
case 0x0c03b08au: goto P_0c03b08a;
case 0x0c03b08cu: goto P_0c03b08c;
case 0x0c03b08eu: goto P_0c03b08e;
case 0x0c03b090u: goto P_0c03b090;
case 0x0c03b092u: goto P_0c03b092;
case 0x0c03b0a0u: goto P_0c03b0a0;
case 0x0c03b0a2u: goto P_0c03b0a2;
case 0x0c03b0a4u: goto P_0c03b0a4;
case 0x0c03b0a6u: goto P_0c03b0a6;
case 0x0c03b0a8u: goto P_0c03b0a8;
case 0x0c03b0aau: goto P_0c03b0aa;
case 0x0c03b0acu: goto P_0c03b0ac;
case 0x0c03b0aeu: goto P_0c03b0ae;
case 0x0c03b0b0u: goto P_0c03b0b0;
case 0x0c03b0b2u: goto P_0c03b0b2;
case 0x0c03b0b4u: goto P_0c03b0b4;
case 0x0c03b0b6u: goto P_0c03b0b6;
case 0x0c03b0b8u: goto P_0c03b0b8;
case 0x0c03b0bau: goto P_0c03b0ba;
case 0x0c03b0bcu: goto P_0c03b0bc;
case 0x0c03b0beu: goto P_0c03b0be;
case 0x0c03b0c0u: goto P_0c03b0c0;
case 0x0c03b0c2u: goto P_0c03b0c2;
case 0x0c03b0c4u: goto P_0c03b0c4;
case 0x0c03b0c6u: goto P_0c03b0c6;
case 0x0c03b0c8u: goto P_0c03b0c8;
case 0x0c03b0cau: goto P_0c03b0ca;
case 0x0c03b0ccu: goto P_0c03b0cc;
case 0x0c03b0ceu: goto P_0c03b0ce;
case 0x0c03b0d0u: goto P_0c03b0d0;
case 0x0c03b0d2u: goto P_0c03b0d2;
case 0x0c03b0d4u: goto P_0c03b0d4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03acf0: /* original 2fe6, guest PC 0x0c03acf0 */
if(!s->budget--) { s->failed_pc=0x0c03acf0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03acf2;
P_0c03acf2: /* original 4f22, guest PC 0x0c03acf2 */
if(!s->budget--) { s->failed_pc=0x0c03acf2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03acf4;
P_0c03acf4: /* original d268, guest PC 0x0c03acf4 */
if(!s->budget--) { s->failed_pc=0x0c03acf4u; return 0; }
r[2]=read(ram,0x0c03ae98u,4);
goto P_0c03acf6;
P_0c03acf6: /* original d369, guest PC 0x0c03acf6 */
if(!s->budget--) { s->failed_pc=0x0c03acf6u; return 0; }
r[3]=read(ram,0x0c03ae9cu,4);
goto P_0c03acf8;
P_0c03acf8: /* original 7fd8, guest PC 0x0c03acf8 */
if(!s->budget--) { s->failed_pc=0x0c03acf8u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c03acfa;
P_0c03acfa: /* original 61f3, guest PC 0x0c03acfa */
if(!s->budget--) { s->failed_pc=0x0c03acfau; return 0; }
r[1]=r[15];
goto P_0c03acfc;
P_0c03acfc: /* original 7120, guest PC 0x0c03acfc */
if(!s->budget--) { s->failed_pc=0x0c03acfcu; return 0; }
r[1]+=0x00000020u;
goto P_0c03acfe;
P_0c03acfe: /* original 430b, guest PC 0x0c03acfe */
if(!s->budget--) { s->failed_pc=0x0c03acfeu; return 0; }
target=r[3];
r[16]=code_base|0x0c03ad02u;
r[0]=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ad02u) { target=s->pc; goto dispatch; }
goto P_0c03ad02;
P_0c03ad00: /* original e008, guest PC 0x0c03ad00 */
if(!s->budget--) { s->failed_pc=0x0c03ad00u; return 0; }
r[0]=0x00000008u;
goto P_0c03ad02;
P_0c03ad02: /* original d767, guest PC 0x0c03ad02 */
if(!s->budget--) { s->failed_pc=0x0c03ad02u; return 0; }
r[7]=read(ram,0x0c03aea0u,4);
goto P_0c03ad04;
P_0c03ad04: /* original 6073, guest PC 0x0c03ad04 */
if(!s->budget--) { s->failed_pc=0x0c03ad04u; return 0; }
r[0]=r[7];
goto P_0c03ad06;
P_0c03ad06: /* original 8403, guest PC 0x0c03ad06 */
if(!s->budget--) { s->failed_pc=0x0c03ad06u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+3,1);
goto P_0c03ad08;
P_0c03ad08: /* original c808, guest PC 0x0c03ad08 */
if(!s->budget--) { s->failed_pc=0x0c03ad08u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c03ad0a;
P_0c03ad0a: /* original 8b11, guest PC 0x0c03ad0a */
if(!s->budget--) { s->failed_pc=0x0c03ad0au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03ad30; }
goto P_0c03ad0c;
P_0c03ad0c: /* original 6073, guest PC 0x0c03ad0c */
if(!s->budget--) { s->failed_pc=0x0c03ad0cu; return 0; }
r[0]=r[7];
goto P_0c03ad0e;
P_0c03ad0e: /* original 8403, guest PC 0x0c03ad0e */
if(!s->budget--) { s->failed_pc=0x0c03ad0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+3,1);
goto P_0c03ad10;
P_0c03ad10: /* original c810, guest PC 0x0c03ad10 */
if(!s->budget--) { s->failed_pc=0x0c03ad10u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c03ad12;
P_0c03ad12: /* original 8908, guest PC 0x0c03ad12 */
if(!s->budget--) { s->failed_pc=0x0c03ad12u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03ad26; }
goto P_0c03ad14;
P_0c03ad14: /* original 6073, guest PC 0x0c03ad14 */
if(!s->budget--) { s->failed_pc=0x0c03ad14u; return 0; }
r[0]=r[7];
goto P_0c03ad16;
P_0c03ad16: /* original 5172, guest PC 0x0c03ad16 */
if(!s->budget--) { s->failed_pc=0x0c03ad16u; return 0; }
r[1]=read(ram,r[7]+8,4);
goto P_0c03ad18;
P_0c03ad18: /* original 1713, guest PC 0x0c03ad18 */
if(!s->budget--) { s->failed_pc=0x0c03ad18u; return 0; }
write(ram,r[7]+12,r[1],4);
goto P_0c03ad1a;
P_0c03ad1a: /* original 8403, guest PC 0x0c03ad1a */
if(!s->budget--) { s->failed_pc=0x0c03ad1au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+3,1);
goto P_0c03ad1c;
P_0c03ad1c: /* original c820, guest PC 0x0c03ad1c */
if(!s->budget--) { s->failed_pc=0x0c03ad1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c03ad1e;
P_0c03ad1e: /* original 8902, guest PC 0x0c03ad1e */
if(!s->budget--) { s->failed_pc=0x0c03ad1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03ad26; }
goto P_0c03ad20;
P_0c03ad20: /* original 5073, guest PC 0x0c03ad20 */
if(!s->budget--) { s->failed_pc=0x0c03ad20u; return 0; }
r[0]=read(ram,r[7]+12,4);
goto P_0c03ad22;
P_0c03ad22: /* original 70fe, guest PC 0x0c03ad22 */
if(!s->budget--) { s->failed_pc=0x0c03ad22u; return 0; }
r[0]+=0xfffffffeu;
goto P_0c03ad24;
P_0c03ad24: /* original 1703, guest PC 0x0c03ad24 */
if(!s->budget--) { s->failed_pc=0x0c03ad24u; return 0; }
write(ram,r[7]+12,r[0],4);
goto P_0c03ad26;
P_0c03ad26: /* original 5273, guest PC 0x0c03ad26 */
if(!s->budget--) { s->failed_pc=0x0c03ad26u; return 0; }
r[2]=read(ram,r[7]+12,4);
goto P_0c03ad28;
P_0c03ad28: /* original e301, guest PC 0x0c03ad28 */
if(!s->budget--) { s->failed_pc=0x0c03ad28u; return 0; }
r[3]=0x00000001u;
goto P_0c03ad2a;
P_0c03ad2a: /* original 3233, guest PC 0x0c03ad2a */
if(!s->budget--) { s->failed_pc=0x0c03ad2au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c03ad2c;
P_0c03ad2c: /* original 8900, guest PC 0x0c03ad2c */
if(!s->budget--) { s->failed_pc=0x0c03ad2cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03ad30; }
goto P_0c03ad2e;
P_0c03ad2e: /* original 1733, guest PC 0x0c03ad2e */
if(!s->budget--) { s->failed_pc=0x0c03ad2eu; return 0; }
write(ram,r[7]+12,r[3],4);
goto P_0c03ad30;
P_0c03ad30: /* original 63f3, guest PC 0x0c03ad30 */
if(!s->budget--) { s->failed_pc=0x0c03ad30u; return 0; }
r[3]=r[15];
goto P_0c03ad32;
P_0c03ad32: /* original 6e63, guest PC 0x0c03ad32 */
if(!s->budget--) { s->failed_pc=0x0c03ad32u; return 0; }
r[14]=r[6];
goto P_0c03ad34;
P_0c03ad34: /* original 7320, guest PC 0x0c03ad34 */
if(!s->budget--) { s->failed_pc=0x0c03ad34u; return 0; }
r[3]+=0x00000020u;
goto P_0c03ad36;
P_0c03ad36: /* original 67f3, guest PC 0x0c03ad36 */
if(!s->budget--) { s->failed_pc=0x0c03ad36u; return 0; }
r[7]=r[15];
goto P_0c03ad38;
P_0c03ad38: /* original 4e08, guest PC 0x0c03ad38 */
if(!s->budget--) { s->failed_pc=0x0c03ad38u; return 0; }
r[14]<<=2;
goto P_0c03ad3a;
P_0c03ad3a: /* original 3e3c, guest PC 0x0c03ad3a */
if(!s->budget--) { s->failed_pc=0x0c03ad3au; return 0; }
r[14]+=r[3];
goto P_0c03ad3c;
P_0c03ad3c: /* original 6ee2, guest PC 0x0c03ad3c */
if(!s->budget--) { s->failed_pc=0x0c03ad3cu; return 0; }
tmp=read(ram,r[14],4);
r[14]=tmp;
goto P_0c03ad3e;
P_0c03ad3e: /* original a015, guest PC 0x0c03ad3e */
if(!s->budget--) { s->failed_pc=0x0c03ad3eu; return 0; }
r[6]=0x00000000u;
goto P_0c03ad6c;
P_0c03ad40: /* original e600, guest PC 0x0c03ad40 */
if(!s->budget--) { s->failed_pc=0x0c03ad40u; return 0; }
r[6]=0x00000000u;
return vf3_matrix_family(0x0c03ad42u,s,ram);
P_0c03ad50: /* original d254, guest PC 0x0c03ad50 */
if(!s->budget--) { s->failed_pc=0x0c03ad50u; return 0; }
r[2]=read(ram,0x0c03aea4u,4);
goto P_0c03ad52;
P_0c03ad52: /* original 6363, guest PC 0x0c03ad52 */
if(!s->budget--) { s->failed_pc=0x0c03ad52u; return 0; }
r[3]=r[6];
goto P_0c03ad54;
P_0c03ad54: /* original 6143, guest PC 0x0c03ad54 */
if(!s->budget--) { s->failed_pc=0x0c03ad54u; return 0; }
r[1]=r[4];
goto P_0c03ad56;
P_0c03ad56: /* original 337c, guest PC 0x0c03ad56 */
if(!s->budget--) { s->failed_pc=0x0c03ad56u; return 0; }
r[3]+=r[7];
goto P_0c03ad58;
P_0c03ad58: /* original 420b, guest PC 0x0c03ad58 */
if(!s->budget--) { s->failed_pc=0x0c03ad58u; return 0; }
target=r[2];
r[16]=code_base|0x0c03ad5cu;
r[0]=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ad5cu) { target=s->pc; goto dispatch; }
goto P_0c03ad5c;
P_0c03ad5a: /* original e010, guest PC 0x0c03ad5a */
if(!s->budget--) { s->failed_pc=0x0c03ad5au; return 0; }
r[0]=0x00000010u;
goto P_0c03ad5c;
P_0c03ad5c: /* original 02ec, guest PC 0x0c03ad5c */
if(!s->budget--) { s->failed_pc=0x0c03ad5cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c03ad5e;
P_0c03ad5e: /* original e010, guest PC 0x0c03ad5e */
if(!s->budget--) { s->failed_pc=0x0c03ad5eu; return 0; }
r[0]=0x00000010u;
goto P_0c03ad60;
P_0c03ad60: /* original 2320, guest PC 0x0c03ad60 */
if(!s->budget--) { s->failed_pc=0x0c03ad60u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c03ad62;
P_0c03ad62: /* original d351, guest PC 0x0c03ad62 */
if(!s->budget--) { s->failed_pc=0x0c03ad62u; return 0; }
r[3]=read(ram,0x0c03aea8u,4);
goto P_0c03ad64;
P_0c03ad64: /* original 430b, guest PC 0x0c03ad64 */
if(!s->budget--) { s->failed_pc=0x0c03ad64u; return 0; }
target=r[3];
r[16]=code_base|0x0c03ad68u;
r[1]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ad68u) { target=s->pc; goto dispatch; }
goto P_0c03ad68;
P_0c03ad66: /* original 6143, guest PC 0x0c03ad66 */
if(!s->budget--) { s->failed_pc=0x0c03ad66u; return 0; }
r[1]=r[4];
goto P_0c03ad68;
P_0c03ad68: /* original 7601, guest PC 0x0c03ad68 */
if(!s->budget--) { s->failed_pc=0x0c03ad68u; return 0; }
r[6]+=0x00000001u;
goto P_0c03ad6a;
P_0c03ad6a: /* original 6403, guest PC 0x0c03ad6a */
if(!s->budget--) { s->failed_pc=0x0c03ad6au; return 0; }
r[4]=r[0];
goto P_0c03ad6c;
P_0c03ad6c: /* original 2448, guest PC 0x0c03ad6c */
if(!s->budget--) { s->failed_pc=0x0c03ad6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03ad6e;
P_0c03ad6e: /* original 8bef, guest PC 0x0c03ad6e */
if(!s->budget--) { s->failed_pc=0x0c03ad6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03ad50; }
goto P_0c03ad70;
P_0c03ad70: /* original a00c, guest PC 0x0c03ad70 */
if(!s->budget--) { s->failed_pc=0x0c03ad70u; return 0; }
r[4]=r[6];
goto P_0c03ad8c;
P_0c03ad72: /* original 6463, guest PC 0x0c03ad72 */
if(!s->budget--) { s->failed_pc=0x0c03ad72u; return 0; }
r[4]=r[6];
return vf3_matrix_family(0x0c03ad74u,s,ram);
P_0c03ad80: /* original 6063, guest PC 0x0c03ad80 */
if(!s->budget--) { s->failed_pc=0x0c03ad80u; return 0; }
r[0]=r[6];
goto P_0c03ad82;
P_0c03ad82: /* original 70ff, guest PC 0x0c03ad82 */
if(!s->budget--) { s->failed_pc=0x0c03ad82u; return 0; }
r[0]+=0xffffffffu;
goto P_0c03ad84;
P_0c03ad84: /* original 037c, guest PC 0x0c03ad84 */
if(!s->budget--) { s->failed_pc=0x0c03ad84u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c03ad86;
P_0c03ad86: /* original 76ff, guest PC 0x0c03ad86 */
if(!s->budget--) { s->failed_pc=0x0c03ad86u; return 0; }
r[6]+=0xffffffffu;
goto P_0c03ad88;
P_0c03ad88: /* original 2530, guest PC 0x0c03ad88 */
if(!s->budget--) { s->failed_pc=0x0c03ad88u; return 0; }
write(ram,r[5],r[3],1);
goto P_0c03ad8a;
P_0c03ad8a: /* original 7501, guest PC 0x0c03ad8a */
if(!s->budget--) { s->failed_pc=0x0c03ad8au; return 0; }
r[5]+=0x00000001u;
goto P_0c03ad8c;
P_0c03ad8c: /* original 2668, guest PC 0x0c03ad8c */
if(!s->budget--) { s->failed_pc=0x0c03ad8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c03ad8e;
P_0c03ad8e: /* original 8bf7, guest PC 0x0c03ad8e */
if(!s->budget--) { s->failed_pc=0x0c03ad8eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03ad80; }
goto P_0c03ad90;
P_0c03ad90: /* original 7f28, guest PC 0x0c03ad90 */
if(!s->budget--) { s->failed_pc=0x0c03ad90u; return 0; }
r[15]+=0x00000028u;
goto P_0c03ad92;
P_0c03ad92: /* original 6043, guest PC 0x0c03ad92 */
if(!s->budget--) { s->failed_pc=0x0c03ad92u; return 0; }
r[0]=r[4];
goto P_0c03ad94;
P_0c03ad94: /* original 4f26, guest PC 0x0c03ad94 */
if(!s->budget--) { s->failed_pc=0x0c03ad94u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03ad96;
P_0c03ad96: /* original 000b, guest PC 0x0c03ad96 */
if(!s->budget--) { s->failed_pc=0x0c03ad96u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03ad98: /* original 6ef6, guest PC 0x0c03ad98 */
if(!s->budget--) { s->failed_pc=0x0c03ad98u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03ad9au,s,ram);
P_0c03ada0: /* original 2fe6, guest PC 0x0c03ada0 */
if(!s->budget--) { s->failed_pc=0x0c03ada0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03ada2;
P_0c03ada2: /* original e70a, guest PC 0x0c03ada2 */
if(!s->budget--) { s->failed_pc=0x0c03ada2u; return 0; }
r[7]=0x0000000au;
goto P_0c03ada4;
P_0c03ada4: /* original 4f22, guest PC 0x0c03ada4 */
if(!s->budget--) { s->failed_pc=0x0c03ada4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03ada6;
P_0c03ada6: /* original 7fe0, guest PC 0x0c03ada6 */
if(!s->budget--) { s->failed_pc=0x0c03ada6u; return 0; }
r[15]+=0xffffffe0u;
goto P_0c03ada8;
P_0c03ada8: /* original 6ef3, guest PC 0x0c03ada8 */
if(!s->budget--) { s->failed_pc=0x0c03ada8u; return 0; }
r[14]=r[15];
goto P_0c03adaa;
P_0c03adaa: /* original a00f, guest PC 0x0c03adaa */
if(!s->budget--) { s->failed_pc=0x0c03adaau; return 0; }
r[6]=0x00000000u;
goto P_0c03adcc;
P_0c03adac: /* original e600, guest PC 0x0c03adac */
if(!s->budget--) { s->failed_pc=0x0c03adacu; return 0; }
r[6]=0x00000000u;
return vf3_matrix_family(0x0c03adaeu,s,ram);
P_0c03adb0: /* original d23c, guest PC 0x0c03adb0 */
if(!s->budget--) { s->failed_pc=0x0c03adb0u; return 0; }
r[2]=read(ram,0x0c03aea4u,4);
goto P_0c03adb2;
P_0c03adb2: /* original 6363, guest PC 0x0c03adb2 */
if(!s->budget--) { s->failed_pc=0x0c03adb2u; return 0; }
r[3]=r[6];
goto P_0c03adb4;
P_0c03adb4: /* original 6143, guest PC 0x0c03adb4 */
if(!s->budget--) { s->failed_pc=0x0c03adb4u; return 0; }
r[1]=r[4];
goto P_0c03adb6;
P_0c03adb6: /* original 33ec, guest PC 0x0c03adb6 */
if(!s->budget--) { s->failed_pc=0x0c03adb6u; return 0; }
r[3]+=r[14];
goto P_0c03adb8;
P_0c03adb8: /* original 420b, guest PC 0x0c03adb8 */
if(!s->budget--) { s->failed_pc=0x0c03adb8u; return 0; }
target=r[2];
r[16]=code_base|0x0c03adbcu;
r[0]=r[7];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03adbcu) { target=s->pc; goto dispatch; }
goto P_0c03adbc;
P_0c03adba: /* original 6073, guest PC 0x0c03adba */
if(!s->budget--) { s->failed_pc=0x0c03adbau; return 0; }
r[0]=r[7];
goto P_0c03adbc;
P_0c03adbc: /* original 7030, guest PC 0x0c03adbc */
if(!s->budget--) { s->failed_pc=0x0c03adbcu; return 0; }
r[0]+=0x00000030u;
goto P_0c03adbe;
P_0c03adbe: /* original 2300, guest PC 0x0c03adbe */
if(!s->budget--) { s->failed_pc=0x0c03adbeu; return 0; }
write(ram,r[3],r[0],1);
goto P_0c03adc0;
P_0c03adc0: /* original 6073, guest PC 0x0c03adc0 */
if(!s->budget--) { s->failed_pc=0x0c03adc0u; return 0; }
r[0]=r[7];
goto P_0c03adc2;
P_0c03adc2: /* original d339, guest PC 0x0c03adc2 */
if(!s->budget--) { s->failed_pc=0x0c03adc2u; return 0; }
r[3]=read(ram,0x0c03aea8u,4);
goto P_0c03adc4;
P_0c03adc4: /* original 430b, guest PC 0x0c03adc4 */
if(!s->budget--) { s->failed_pc=0x0c03adc4u; return 0; }
target=r[3];
r[16]=code_base|0x0c03adc8u;
r[1]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03adc8u) { target=s->pc; goto dispatch; }
goto P_0c03adc8;
P_0c03adc6: /* original 6143, guest PC 0x0c03adc6 */
if(!s->budget--) { s->failed_pc=0x0c03adc6u; return 0; }
r[1]=r[4];
goto P_0c03adc8;
P_0c03adc8: /* original 7601, guest PC 0x0c03adc8 */
if(!s->budget--) { s->failed_pc=0x0c03adc8u; return 0; }
r[6]+=0x00000001u;
goto P_0c03adca;
P_0c03adca: /* original 6403, guest PC 0x0c03adca */
if(!s->budget--) { s->failed_pc=0x0c03adcau; return 0; }
r[4]=r[0];
goto P_0c03adcc;
P_0c03adcc: /* original 2448, guest PC 0x0c03adcc */
if(!s->budget--) { s->failed_pc=0x0c03adccu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03adce;
P_0c03adce: /* original 8bef, guest PC 0x0c03adce */
if(!s->budget--) { s->failed_pc=0x0c03adceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03adb0; }
goto P_0c03add0;
P_0c03add0: /* original a00c, guest PC 0x0c03add0 */
if(!s->budget--) { s->failed_pc=0x0c03add0u; return 0; }
r[4]=r[6];
goto P_0c03adec;
P_0c03add2: /* original 6463, guest PC 0x0c03add2 */
if(!s->budget--) { s->failed_pc=0x0c03add2u; return 0; }
r[4]=r[6];
return vf3_matrix_family(0x0c03add4u,s,ram);
P_0c03ade0: /* original 6063, guest PC 0x0c03ade0 */
if(!s->budget--) { s->failed_pc=0x0c03ade0u; return 0; }
r[0]=r[6];
goto P_0c03ade2;
P_0c03ade2: /* original 70ff, guest PC 0x0c03ade2 */
if(!s->budget--) { s->failed_pc=0x0c03ade2u; return 0; }
r[0]+=0xffffffffu;
goto P_0c03ade4;
P_0c03ade4: /* original 03ec, guest PC 0x0c03ade4 */
if(!s->budget--) { s->failed_pc=0x0c03ade4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c03ade6;
P_0c03ade6: /* original 76ff, guest PC 0x0c03ade6 */
if(!s->budget--) { s->failed_pc=0x0c03ade6u; return 0; }
r[6]+=0xffffffffu;
goto P_0c03ade8;
P_0c03ade8: /* original 2530, guest PC 0x0c03ade8 */
if(!s->budget--) { s->failed_pc=0x0c03ade8u; return 0; }
write(ram,r[5],r[3],1);
goto P_0c03adea;
P_0c03adea: /* original 7501, guest PC 0x0c03adea */
if(!s->budget--) { s->failed_pc=0x0c03adeau; return 0; }
r[5]+=0x00000001u;
goto P_0c03adec;
P_0c03adec: /* original 2668, guest PC 0x0c03adec */
if(!s->budget--) { s->failed_pc=0x0c03adecu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c03adee;
P_0c03adee: /* original 8bf7, guest PC 0x0c03adee */
if(!s->budget--) { s->failed_pc=0x0c03adeeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03ade0; }
goto P_0c03adf0;
P_0c03adf0: /* original 7f20, guest PC 0x0c03adf0 */
if(!s->budget--) { s->failed_pc=0x0c03adf0u; return 0; }
r[15]+=0x00000020u;
goto P_0c03adf2;
P_0c03adf2: /* original 6043, guest PC 0x0c03adf2 */
if(!s->budget--) { s->failed_pc=0x0c03adf2u; return 0; }
r[0]=r[4];
goto P_0c03adf4;
P_0c03adf4: /* original 4f26, guest PC 0x0c03adf4 */
if(!s->budget--) { s->failed_pc=0x0c03adf4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03adf6;
P_0c03adf6: /* original 000b, guest PC 0x0c03adf6 */
if(!s->budget--) { s->failed_pc=0x0c03adf6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03adf8: /* original 6ef6, guest PC 0x0c03adf8 */
if(!s->budget--) { s->failed_pc=0x0c03adf8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03adfau,s,ram);
P_0c03ae16: /* original 4f22, guest PC 0x0c03ae16 */
if(!s->budget--) { s->failed_pc=0x0c03ae16u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03ae18;
P_0c03ae18: /* original da24, guest PC 0x0c03ae18 */
if(!s->budget--) { s->failed_pc=0x0c03ae18u; return 0; }
r[10]=read(ram,0x0c03aeacu,4);
goto P_0c03ae1a;
P_0c03ae1a: /* original dc21, guest PC 0x0c03ae1a */
if(!s->budget--) { s->failed_pc=0x0c03ae1au; return 0; }
r[12]=read(ram,0x0c03aea0u,4);
goto P_0c03ae1c;
P_0c03ae1c: /* original 7ff8, guest PC 0x0c03ae1c */
if(!s->budget--) { s->failed_pc=0x0c03ae1cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c03ae1e;
P_0c03ae1e: /* original a147, guest PC 0x0c03ae1e */
if(!s->budget--) { s->failed_pc=0x0c03ae1eu; return 0; }
r[13]=0x00000003u;
goto P_0c03b0b0;
P_0c03ae20: /* original ed03, guest PC 0x0c03ae20 */
if(!s->budget--) { s->failed_pc=0x0c03ae20u; return 0; }
r[13]=0x00000003u;
return vf3_matrix_family(0x0c03ae22u,s,ram);
P_0c03ae30: /* original 604e, guest PC 0x0c03ae30 */
if(!s->budget--) { s->failed_pc=0x0c03ae30u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c03ae32;
P_0c03ae32: /* original 8825, guest PC 0x0c03ae32 */
if(!s->budget--) { s->failed_pc=0x0c03ae32u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000025u)!=0);
goto P_0c03ae34;
P_0c03ae34: /* original 8901, guest PC 0x0c03ae34 */
if(!s->budget--) { s->failed_pc=0x0c03ae34u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03ae3a; }
goto P_0c03ae36;
P_0c03ae36: /* original a115, guest PC 0x0c03ae36 */
if(!s->budget--) { s->failed_pc=0x0c03ae36u; return 0; }
goto P_0c03b064;
P_0c03ae38: /* original 0009, guest PC 0x0c03ae38 */
if(!s->budget--) { s->failed_pc=0x0c03ae38u; return 0; }
goto P_0c03ae3a;
P_0c03ae3a: /* original 7901, guest PC 0x0c03ae3a */
if(!s->budget--) { s->failed_pc=0x0c03ae3au; return 0; }
r[9]+=0x00000001u;
goto P_0c03ae3c;
P_0c03ae3c: /* original 6490, guest PC 0x0c03ae3c */
if(!s->budget--) { s->failed_pc=0x0c03ae3cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[9],1);
r[4]=tmp;
goto P_0c03ae3e;
P_0c03ae3e: /* original 604e, guest PC 0x0c03ae3e */
if(!s->budget--) { s->failed_pc=0x0c03ae3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c03ae40;
P_0c03ae40: /* original 882d, guest PC 0x0c03ae40 */
if(!s->budget--) { s->failed_pc=0x0c03ae40u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002du)!=0);
goto P_0c03ae42;
P_0c03ae42: /* original 8b05, guest PC 0x0c03ae42 */
if(!s->budget--) { s->failed_pc=0x0c03ae42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03ae50; }
goto P_0c03ae44;
P_0c03ae44: /* original 84c3, guest PC 0x0c03ae44 */
if(!s->budget--) { s->failed_pc=0x0c03ae44u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+3,1);
goto P_0c03ae46;
P_0c03ae46: /* original a037, guest PC 0x0c03ae46 */
if(!s->budget--) { s->failed_pc=0x0c03ae46u; return 0; }
r[0]|=128u;
goto P_0c03aeb8;
P_0c03ae48: /* original cb80, guest PC 0x0c03ae48 */
if(!s->budget--) { s->failed_pc=0x0c03ae48u; return 0; }
r[0]|=128u;
return vf3_matrix_family(0x0c03ae4au,s,ram);
P_0c03ae50: /* original 882b, guest PC 0x0c03ae50 */
if(!s->budget--) { s->failed_pc=0x0c03ae50u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002bu)!=0);
goto P_0c03ae52;
P_0c03ae52: /* original 8b05, guest PC 0x0c03ae52 */
if(!s->budget--) { s->failed_pc=0x0c03ae52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03ae60; }
goto P_0c03ae54;
P_0c03ae54: /* original 84c3, guest PC 0x0c03ae54 */
if(!s->budget--) { s->failed_pc=0x0c03ae54u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+3,1);
goto P_0c03ae56;
P_0c03ae56: /* original a02f, guest PC 0x0c03ae56 */
if(!s->budget--) { s->failed_pc=0x0c03ae56u; return 0; }
r[0]|=64u;
goto P_0c03aeb8;
P_0c03ae58: /* original cb40, guest PC 0x0c03ae58 */
if(!s->budget--) { s->failed_pc=0x0c03ae58u; return 0; }
r[0]|=64u;
return vf3_matrix_family(0x0c03ae5au,s,ram);
P_0c03ae60: /* original 604e, guest PC 0x0c03ae60 */
if(!s->budget--) { s->failed_pc=0x0c03ae60u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c03ae62;
P_0c03ae62: /* original 8820, guest PC 0x0c03ae62 */
if(!s->budget--) { s->failed_pc=0x0c03ae62u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c03ae64;
P_0c03ae64: /* original 89e9, guest PC 0x0c03ae64 */
if(!s->budget--) { s->failed_pc=0x0c03ae64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03ae3a; }
goto P_0c03ae66;
P_0c03ae66: /* original 604e, guest PC 0x0c03ae66 */
if(!s->budget--) { s->failed_pc=0x0c03ae66u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c03ae68;
P_0c03ae68: /* original 8823, guest PC 0x0c03ae68 */
if(!s->budget--) { s->failed_pc=0x0c03ae68u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000023u)!=0);
goto P_0c03ae6a;
P_0c03ae6a: /* original 8b21, guest PC 0x0c03ae6a */
if(!s->budget--) { s->failed_pc=0x0c03ae6au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03aeb0; }
goto P_0c03ae6c;
P_0c03ae6c: /* original 84c3, guest PC 0x0c03ae6c */
if(!s->budget--) { s->failed_pc=0x0c03ae6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+3,1);
goto P_0c03ae6e;
P_0c03ae6e: /* original a023, guest PC 0x0c03ae6e */
if(!s->budget--) { s->failed_pc=0x0c03ae6eu; return 0; }
r[0]|=32u;
goto P_0c03aeb8;
P_0c03ae70: /* original cb20, guest PC 0x0c03ae70 */
if(!s->budget--) { s->failed_pc=0x0c03ae70u; return 0; }
r[0]|=32u;
return vf3_matrix_family(0x0c03ae72u,s,ram);
P_0c03aeb0: /* original 8830, guest PC 0x0c03aeb0 */
if(!s->budget--) { s->failed_pc=0x0c03aeb0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000030u)!=0);
goto P_0c03aeb2;
P_0c03aeb2: /* original 8b05, guest PC 0x0c03aeb2 */
if(!s->budget--) { s->failed_pc=0x0c03aeb2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03aec0; }
goto P_0c03aeb4;
P_0c03aeb4: /* original 84c3, guest PC 0x0c03aeb4 */
if(!s->budget--) { s->failed_pc=0x0c03aeb4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+3,1);
goto P_0c03aeb6;
P_0c03aeb6: /* original cb10, guest PC 0x0c03aeb6 */
if(!s->budget--) { s->failed_pc=0x0c03aeb6u; return 0; }
r[0]|=16u;
goto P_0c03aeb8;
P_0c03aeb8: /* original afbf, guest PC 0x0c03aeb8 */
if(!s->budget--) { s->failed_pc=0x0c03aeb8u; return 0; }
write(ram,r[12]+3,r[0],1);
goto P_0c03ae3a;
P_0c03aeba: /* original 80c3, guest PC 0x0c03aeba */
if(!s->budget--) { s->failed_pc=0x0c03aebau; return 0; }
write(ram,r[12]+3,r[0],1);
return vf3_matrix_family(0x0c03aebcu,s,ram);
P_0c03aec0: /* original 654e, guest PC 0x0c03aec0 */
if(!s->budget--) { s->failed_pc=0x0c03aec0u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c03aec2;
P_0c03aec2: /* original 6053, guest PC 0x0c03aec2 */
if(!s->budget--) { s->failed_pc=0x0c03aec2u; return 0; }
r[0]=r[5];
goto P_0c03aec4;
P_0c03aec4: /* original 8864, guest PC 0x0c03aec4 */
if(!s->budget--) { s->failed_pc=0x0c03aec4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000064u)!=0);
goto P_0c03aec6;
P_0c03aec6: /* original 8913, guest PC 0x0c03aec6 */
if(!s->budget--) { s->failed_pc=0x0c03aec6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03aef0; }
goto P_0c03aec8;
P_0c03aec8: /* original 6053, guest PC 0x0c03aec8 */
if(!s->budget--) { s->failed_pc=0x0c03aec8u; return 0; }
r[0]=r[5];
goto P_0c03aeca;
P_0c03aeca: /* original 8878, guest PC 0x0c03aeca */
if(!s->budget--) { s->failed_pc=0x0c03aecau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000078u)!=0);
goto P_0c03aecc;
P_0c03aecc: /* original 8910, guest PC 0x0c03aecc */
if(!s->budget--) { s->failed_pc=0x0c03aeccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03aef0; }
goto P_0c03aece;
P_0c03aece: /* original 6053, guest PC 0x0c03aece */
if(!s->budget--) { s->failed_pc=0x0c03aeceu; return 0; }
r[0]=r[5];
goto P_0c03aed0;
P_0c03aed0: /* original 8858, guest PC 0x0c03aed0 */
if(!s->budget--) { s->failed_pc=0x0c03aed0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000058u)!=0);
goto P_0c03aed2;
P_0c03aed2: /* original 890d, guest PC 0x0c03aed2 */
if(!s->budget--) { s->failed_pc=0x0c03aed2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03aef0; }
goto P_0c03aed4;
P_0c03aed4: /* original 6053, guest PC 0x0c03aed4 */
if(!s->budget--) { s->failed_pc=0x0c03aed4u; return 0; }
r[0]=r[5];
goto P_0c03aed6;
P_0c03aed6: /* original 8873, guest PC 0x0c03aed6 */
if(!s->budget--) { s->failed_pc=0x0c03aed6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000073u)!=0);
goto P_0c03aed8;
P_0c03aed8: /* original 890a, guest PC 0x0c03aed8 */
if(!s->budget--) { s->failed_pc=0x0c03aed8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03aef0; }
goto P_0c03aeda;
P_0c03aeda: /* original 6053, guest PC 0x0c03aeda */
if(!s->budget--) { s->failed_pc=0x0c03aedau; return 0; }
r[0]=r[5];
goto P_0c03aedc;
P_0c03aedc: /* original 8866, guest PC 0x0c03aedc */
if(!s->budget--) { s->failed_pc=0x0c03aedcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000066u)!=0);
goto P_0c03aede;
P_0c03aede: /* original 8907, guest PC 0x0c03aede */
if(!s->budget--) { s->failed_pc=0x0c03aedeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03aef0; }
goto P_0c03aee0;
P_0c03aee0: /* original 6053, guest PC 0x0c03aee0 */
if(!s->budget--) { s->failed_pc=0x0c03aee0u; return 0; }
r[0]=r[5];
goto P_0c03aee2;
P_0c03aee2: /* original 8870, guest PC 0x0c03aee2 */
if(!s->budget--) { s->failed_pc=0x0c03aee2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000070u)!=0);
goto P_0c03aee4;
P_0c03aee4: /* original 8904, guest PC 0x0c03aee4 */
if(!s->budget--) { s->failed_pc=0x0c03aee4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03aef0; }
goto P_0c03aee6;
P_0c03aee6: /* original 6053, guest PC 0x0c03aee6 */
if(!s->budget--) { s->failed_pc=0x0c03aee6u; return 0; }
r[0]=r[5];
goto P_0c03aee8;
P_0c03aee8: /* original 8863, guest PC 0x0c03aee8 */
if(!s->budget--) { s->failed_pc=0x0c03aee8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000063u)!=0);
goto P_0c03aeea;
P_0c03aeea: /* original 8901, guest PC 0x0c03aeea */
if(!s->budget--) { s->failed_pc=0x0c03aeeau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03aef0; }
goto P_0c03aeec;
P_0c03aeec: /* original 2558, guest PC 0x0c03aeec */
if(!s->budget--) { s->failed_pc=0x0c03aeecu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c03aeee;
P_0c03aeee: /* original 8ba4, guest PC 0x0c03aeee */
if(!s->budget--) { s->failed_pc=0x0c03aeeeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03ae3a; }
goto P_0c03aef0;
P_0c03aef0: /* original 604e, guest PC 0x0c03aef0 */
if(!s->budget--) { s->failed_pc=0x0c03aef0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c03aef2;
P_0c03aef2: /* original 8858, guest PC 0x0c03aef2 */
if(!s->budget--) { s->failed_pc=0x0c03aef2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000058u)!=0);
goto P_0c03aef4;
P_0c03aef4: /* original 8b01, guest PC 0x0c03aef4 */
if(!s->budget--) { s->failed_pc=0x0c03aef4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03aefa; }
goto P_0c03aef6;
P_0c03aef6: /* original a073, guest PC 0x0c03aef6 */
if(!s->budget--) { s->failed_pc=0x0c03aef6u; return 0; }
goto P_0c03afe0;
P_0c03aef8: /* original 0009, guest PC 0x0c03aef8 */
if(!s->budget--) { s->failed_pc=0x0c03aef8u; return 0; }
goto P_0c03aefa;
P_0c03aefa: /* original 8863, guest PC 0x0c03aefa */
if(!s->budget--) { s->failed_pc=0x0c03aefau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000063u)!=0);
goto P_0c03aefc;
P_0c03aefc: /* original 8b01, guest PC 0x0c03aefc */
if(!s->budget--) { s->failed_pc=0x0c03aefcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03af02; }
goto P_0c03aefe;
P_0c03aefe: /* original a097, guest PC 0x0c03aefe */
if(!s->budget--) { s->failed_pc=0x0c03aefeu; return 0; }
goto P_0c03b030;
P_0c03af00: /* original 0009, guest PC 0x0c03af00 */
if(!s->budget--) { s->failed_pc=0x0c03af00u; return 0; }
goto P_0c03af02;
P_0c03af02: /* original 8864, guest PC 0x0c03af02 */
if(!s->budget--) { s->failed_pc=0x0c03af02u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000064u)!=0);
goto P_0c03af04;
P_0c03af04: /* original 8914, guest PC 0x0c03af04 */
if(!s->budget--) { s->failed_pc=0x0c03af04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03af30; }
goto P_0c03af06;
P_0c03af06: /* original 8866, guest PC 0x0c03af06 */
if(!s->budget--) { s->failed_pc=0x0c03af06u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000066u)!=0);
goto P_0c03af08;
P_0c03af08: /* original 8b01, guest PC 0x0c03af08 */
if(!s->budget--) { s->failed_pc=0x0c03af08u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03af0e; }
goto P_0c03af0a;
P_0c03af0a: /* original a0d0, guest PC 0x0c03af0a */
if(!s->budget--) { s->failed_pc=0x0c03af0au; return 0; }
goto P_0c03b0ae;
P_0c03af0c: /* original 0009, guest PC 0x0c03af0c */
if(!s->budget--) { s->failed_pc=0x0c03af0cu; return 0; }
goto P_0c03af0e;
P_0c03af0e: /* original 8870, guest PC 0x0c03af0e */
if(!s->budget--) { s->failed_pc=0x0c03af0eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000070u)!=0);
goto P_0c03af10;
P_0c03af10: /* original 8936, guest PC 0x0c03af10 */
if(!s->budget--) { s->failed_pc=0x0c03af10u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03af80; }
goto P_0c03af12;
P_0c03af12: /* original 8873, guest PC 0x0c03af12 */
if(!s->budget--) { s->failed_pc=0x0c03af12u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000073u)!=0);
goto P_0c03af14;
P_0c03af14: /* original 8b01, guest PC 0x0c03af14 */
if(!s->budget--) { s->failed_pc=0x0c03af14u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03af1a; }
goto P_0c03af16;
P_0c03af16: /* original a0ab, guest PC 0x0c03af16 */
if(!s->budget--) { s->failed_pc=0x0c03af16u; return 0; }
goto P_0c03b070;
P_0c03af18: /* original 0009, guest PC 0x0c03af18 */
if(!s->budget--) { s->failed_pc=0x0c03af18u; return 0; }
goto P_0c03af1a;
P_0c03af1a: /* original 8878, guest PC 0x0c03af1a */
if(!s->budget--) { s->failed_pc=0x0c03af1au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000078u)!=0);
goto P_0c03af1c;
P_0c03af1c: /* original 8937, guest PC 0x0c03af1c */
if(!s->budget--) { s->failed_pc=0x0c03af1cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03af8e; }
goto P_0c03af1e;
P_0c03af1e: /* original a0c6, guest PC 0x0c03af1e */
if(!s->budget--) { s->failed_pc=0x0c03af1eu; return 0; }
goto P_0c03b0ae;
P_0c03af20: /* original 0009, guest PC 0x0c03af20 */
if(!s->budget--) { s->failed_pc=0x0c03af20u; return 0; }
return vf3_matrix_family(0x0c03af22u,s,ram);
P_0c03af30: /* original 64e3, guest PC 0x0c03af30 */
if(!s->budget--) { s->failed_pc=0x0c03af30u; return 0; }
r[4]=r[14];
goto P_0c03af32;
P_0c03af32: /* original 7404, guest PC 0x0c03af32 */
if(!s->budget--) { s->failed_pc=0x0c03af32u; return 0; }
r[4]+=0x00000004u;
goto P_0c03af34;
P_0c03af34: /* original 65b3, guest PC 0x0c03af34 */
if(!s->budget--) { s->failed_pc=0x0c03af34u; return 0; }
r[5]=r[11];
goto P_0c03af36;
P_0c03af36: /* original 24d8, guest PC 0x0c03af36 */
if(!s->budget--) { s->failed_pc=0x0c03af36u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[13])==0)!=0);
goto P_0c03af38;
P_0c03af38: /* original 35ac, guest PC 0x0c03af38 */
if(!s->budget--) { s->failed_pc=0x0c03af38u; return 0; }
r[5]+=r[10];
goto P_0c03af3a;
P_0c03af3a: /* original 8d09, guest PC 0x0c03af3a */
if(!s->budget--) { s->failed_pc=0x0c03af3au; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[4],4);
if(cond) { goto P_0c03af50; }
goto P_0c03af3e;
P_0c03af3c: /* original 2f42, guest PC 0x0c03af3c */
if(!s->budget--) { s->failed_pc=0x0c03af3cu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c03af3e;
P_0c03af3e: /* original a008, guest PC 0x0c03af3e */
if(!s->budget--) { s->failed_pc=0x0c03af3eu; return 0; }
r[14]+=0x00000008u;
goto P_0c03af52;
P_0c03af40: /* original 7e08, guest PC 0x0c03af40 */
if(!s->budget--) { s->failed_pc=0x0c03af40u; return 0; }
r[14]+=0x00000008u;
return vf3_matrix_family(0x0c03af42u,s,ram);
P_0c03af50: /* original 6ef2, guest PC 0x0c03af50 */
if(!s->budget--) { s->failed_pc=0x0c03af50u; return 0; }
tmp=read(ram,r[15],4);
r[14]=tmp;
goto P_0c03af52;
P_0c03af52: /* original 64e3, guest PC 0x0c03af52 */
if(!s->budget--) { s->failed_pc=0x0c03af52u; return 0; }
r[4]=r[14];
goto P_0c03af54;
P_0c03af54: /* original 74fc, guest PC 0x0c03af54 */
if(!s->budget--) { s->failed_pc=0x0c03af54u; return 0; }
r[4]+=0xfffffffcu;
goto P_0c03af56;
P_0c03af56: /* original 24d8, guest PC 0x0c03af56 */
if(!s->budget--) { s->failed_pc=0x0c03af56u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[13])==0)!=0);
goto P_0c03af58;
P_0c03af58: /* original 8d0a, guest PC 0x0c03af58 */
if(!s->budget--) { s->failed_pc=0x0c03af58u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[4],4);
if(cond) { goto P_0c03af70; }
goto P_0c03af5c;
P_0c03af5a: /* original 1f41, guest PC 0x0c03af5a */
if(!s->budget--) { s->failed_pc=0x0c03af5au; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c03af5c;
P_0c03af5c: /* original 64e3, guest PC 0x0c03af5c */
if(!s->budget--) { s->failed_pc=0x0c03af5cu; return 0; }
r[4]=r[14];
goto P_0c03af5e;
P_0c03af5e: /* original a008, guest PC 0x0c03af5e */
if(!s->budget--) { s->failed_pc=0x0c03af5eu; return 0; }
r[4]+=0xfffffff8u;
goto P_0c03af72;
P_0c03af60: /* original 74f8, guest PC 0x0c03af60 */
if(!s->budget--) { s->failed_pc=0x0c03af60u; return 0; }
r[4]+=0xfffffff8u;
return vf3_matrix_family(0x0c03af62u,s,ram);
P_0c03af70: /* original 54f1, guest PC 0x0c03af70 */
if(!s->budget--) { s->failed_pc=0x0c03af70u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c03af72;
P_0c03af72: /* original bf15, guest PC 0x0c03af72 */
if(!s->budget--) { s->failed_pc=0x0c03af72u; return 0; }
target=0x0c03ada0u; r[16]=code_base|0x0c03af76u;
tmp=read(ram,r[4],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03af76u) { target=s->pc; goto dispatch; }
goto P_0c03af76;
P_0c03af74: /* original 6442, guest PC 0x0c03af74 */
if(!s->budget--) { s->failed_pc=0x0c03af74u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c03af76;
P_0c03af76: /* original a056, guest PC 0x0c03af76 */
if(!s->budget--) { s->failed_pc=0x0c03af76u; return 0; }
goto P_0c03b026;
P_0c03af78: /* original 0009, guest PC 0x0c03af78 */
if(!s->budget--) { s->failed_pc=0x0c03af78u; return 0; }
return vf3_matrix_family(0x0c03af7au,s,ram);
P_0c03af80: /* original 84c3, guest PC 0x0c03af80 */
if(!s->budget--) { s->failed_pc=0x0c03af80u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+3,1);
goto P_0c03af82;
P_0c03af82: /* original cb02, guest PC 0x0c03af82 */
if(!s->budget--) { s->failed_pc=0x0c03af82u; return 0; }
r[0]|=2u;
goto P_0c03af84;
P_0c03af84: /* original 80c3, guest PC 0x0c03af84 */
if(!s->budget--) { s->failed_pc=0x0c03af84u; return 0; }
write(ram,r[12]+3,r[0],1);
goto P_0c03af86;
P_0c03af86: /* original 84c3, guest PC 0x0c03af86 */
if(!s->budget--) { s->failed_pc=0x0c03af86u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+3,1);
goto P_0c03af88;
P_0c03af88: /* original cb08, guest PC 0x0c03af88 */
if(!s->budget--) { s->failed_pc=0x0c03af88u; return 0; }
r[0]|=8u;
goto P_0c03af8a;
P_0c03af8a: /* original 80c3, guest PC 0x0c03af8a */
if(!s->budget--) { s->failed_pc=0x0c03af8au; return 0; }
write(ram,r[12]+3,r[0],1);
goto P_0c03af8c;
P_0c03af8c: /* original 1c83, guest PC 0x0c03af8c */
if(!s->budget--) { s->failed_pc=0x0c03af8cu; return 0; }
write(ram,r[12]+12,r[8],4);
goto P_0c03af8e;
P_0c03af8e: /* original 64e3, guest PC 0x0c03af8e */
if(!s->budget--) { s->failed_pc=0x0c03af8eu; return 0; }
r[4]=r[14];
goto P_0c03af90;
P_0c03af90: /* original 7404, guest PC 0x0c03af90 */
if(!s->budget--) { s->failed_pc=0x0c03af90u; return 0; }
r[4]+=0x00000004u;
goto P_0c03af92;
P_0c03af92: /* original 65b3, guest PC 0x0c03af92 */
if(!s->budget--) { s->failed_pc=0x0c03af92u; return 0; }
r[5]=r[11];
goto P_0c03af94;
P_0c03af94: /* original 24d8, guest PC 0x0c03af94 */
if(!s->budget--) { s->failed_pc=0x0c03af94u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[13])==0)!=0);
goto P_0c03af96;
P_0c03af96: /* original e600, guest PC 0x0c03af96 */
if(!s->budget--) { s->failed_pc=0x0c03af96u; return 0; }
r[6]=0x00000000u;
goto P_0c03af98;
P_0c03af98: /* original 35ac, guest PC 0x0c03af98 */
if(!s->budget--) { s->failed_pc=0x0c03af98u; return 0; }
r[5]+=r[10];
goto P_0c03af9a;
P_0c03af9a: /* original 8d09, guest PC 0x0c03af9a */
if(!s->budget--) { s->failed_pc=0x0c03af9au; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[4],4);
if(cond) { goto P_0c03afb0; }
goto P_0c03af9e;
P_0c03af9c: /* original 2f42, guest PC 0x0c03af9c */
if(!s->budget--) { s->failed_pc=0x0c03af9cu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c03af9e;
P_0c03af9e: /* original a008, guest PC 0x0c03af9e */
if(!s->budget--) { s->failed_pc=0x0c03af9eu; return 0; }
r[14]+=0x00000008u;
goto P_0c03afb2;
P_0c03afa0: /* original 7e08, guest PC 0x0c03afa0 */
if(!s->budget--) { s->failed_pc=0x0c03afa0u; return 0; }
r[14]+=0x00000008u;
return vf3_matrix_family(0x0c03afa2u,s,ram);
P_0c03afb0: /* original 6ef2, guest PC 0x0c03afb0 */
if(!s->budget--) { s->failed_pc=0x0c03afb0u; return 0; }
tmp=read(ram,r[15],4);
r[14]=tmp;
goto P_0c03afb2;
P_0c03afb2: /* original 64e3, guest PC 0x0c03afb2 */
if(!s->budget--) { s->failed_pc=0x0c03afb2u; return 0; }
r[4]=r[14];
goto P_0c03afb4;
P_0c03afb4: /* original 74fc, guest PC 0x0c03afb4 */
if(!s->budget--) { s->failed_pc=0x0c03afb4u; return 0; }
r[4]+=0xfffffffcu;
goto P_0c03afb6;
P_0c03afb6: /* original 24d8, guest PC 0x0c03afb6 */
if(!s->budget--) { s->failed_pc=0x0c03afb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[13])==0)!=0);
goto P_0c03afb8;
P_0c03afb8: /* original 8d0a, guest PC 0x0c03afb8 */
if(!s->budget--) { s->failed_pc=0x0c03afb8u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[4],4);
if(cond) { goto P_0c03afd0; }
goto P_0c03afbc;
P_0c03afba: /* original 1f41, guest PC 0x0c03afba */
if(!s->budget--) { s->failed_pc=0x0c03afbau; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c03afbc;
P_0c03afbc: /* original 64e3, guest PC 0x0c03afbc */
if(!s->budget--) { s->failed_pc=0x0c03afbcu; return 0; }
r[4]=r[14];
goto P_0c03afbe;
P_0c03afbe: /* original a008, guest PC 0x0c03afbe */
if(!s->budget--) { s->failed_pc=0x0c03afbeu; return 0; }
r[4]+=0xfffffff8u;
goto P_0c03afd2;
P_0c03afc0: /* original 74f8, guest PC 0x0c03afc0 */
if(!s->budget--) { s->failed_pc=0x0c03afc0u; return 0; }
r[4]+=0xfffffff8u;
return vf3_matrix_family(0x0c03afc2u,s,ram);
P_0c03afd0: /* original 54f1, guest PC 0x0c03afd0 */
if(!s->budget--) { s->failed_pc=0x0c03afd0u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c03afd2;
P_0c03afd2: /* original be8d, guest PC 0x0c03afd2 */
if(!s->budget--) { s->failed_pc=0x0c03afd2u; return 0; }
target=0x0c03acf0u; r[16]=code_base|0x0c03afd6u;
tmp=read(ram,r[4],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03afd6u) { target=s->pc; goto dispatch; }
goto P_0c03afd6;
P_0c03afd4: /* original 6442, guest PC 0x0c03afd4 */
if(!s->budget--) { s->failed_pc=0x0c03afd4u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c03afd6;
P_0c03afd6: /* original a026, guest PC 0x0c03afd6 */
if(!s->budget--) { s->failed_pc=0x0c03afd6u; return 0; }
goto P_0c03b026;
P_0c03afd8: /* original 0009, guest PC 0x0c03afd8 */
if(!s->budget--) { s->failed_pc=0x0c03afd8u; return 0; }
return vf3_matrix_family(0x0c03afdau,s,ram);
P_0c03afe0: /* original 64e3, guest PC 0x0c03afe0 */
if(!s->budget--) { s->failed_pc=0x0c03afe0u; return 0; }
r[4]=r[14];
goto P_0c03afe2;
P_0c03afe2: /* original 7404, guest PC 0x0c03afe2 */
if(!s->budget--) { s->failed_pc=0x0c03afe2u; return 0; }
r[4]+=0x00000004u;
goto P_0c03afe4;
P_0c03afe4: /* original 65b3, guest PC 0x0c03afe4 */
if(!s->budget--) { s->failed_pc=0x0c03afe4u; return 0; }
r[5]=r[11];
goto P_0c03afe6;
P_0c03afe6: /* original 24d8, guest PC 0x0c03afe6 */
if(!s->budget--) { s->failed_pc=0x0c03afe6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[13])==0)!=0);
goto P_0c03afe8;
P_0c03afe8: /* original e601, guest PC 0x0c03afe8 */
if(!s->budget--) { s->failed_pc=0x0c03afe8u; return 0; }
r[6]=0x00000001u;
goto P_0c03afea;
P_0c03afea: /* original 35ac, guest PC 0x0c03afea */
if(!s->budget--) { s->failed_pc=0x0c03afeau; return 0; }
r[5]+=r[10];
goto P_0c03afec;
P_0c03afec: /* original 8d08, guest PC 0x0c03afec */
if(!s->budget--) { s->failed_pc=0x0c03afecu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[4],4);
if(cond) { goto P_0c03b000; }
goto P_0c03aff0;
P_0c03afee: /* original 1f41, guest PC 0x0c03afee */
if(!s->budget--) { s->failed_pc=0x0c03afeeu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c03aff0;
P_0c03aff0: /* original a007, guest PC 0x0c03aff0 */
if(!s->budget--) { s->failed_pc=0x0c03aff0u; return 0; }
r[14]+=0x00000008u;
goto P_0c03b002;
P_0c03aff2: /* original 7e08, guest PC 0x0c03aff2 */
if(!s->budget--) { s->failed_pc=0x0c03aff2u; return 0; }
r[14]+=0x00000008u;
return vf3_matrix_family(0x0c03aff4u,s,ram);
P_0c03b000: /* original 5ef1, guest PC 0x0c03b000 */
if(!s->budget--) { s->failed_pc=0x0c03b000u; return 0; }
r[14]=read(ram,r[15]+4,4);
goto P_0c03b002;
P_0c03b002: /* original 64e3, guest PC 0x0c03b002 */
if(!s->budget--) { s->failed_pc=0x0c03b002u; return 0; }
r[4]=r[14];
goto P_0c03b004;
P_0c03b004: /* original 74fc, guest PC 0x0c03b004 */
if(!s->budget--) { s->failed_pc=0x0c03b004u; return 0; }
r[4]+=0xfffffffcu;
goto P_0c03b006;
P_0c03b006: /* original 24d8, guest PC 0x0c03b006 */
if(!s->budget--) { s->failed_pc=0x0c03b006u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[13])==0)!=0);
goto P_0c03b008;
P_0c03b008: /* original 8d0a, guest PC 0x0c03b008 */
if(!s->budget--) { s->failed_pc=0x0c03b008u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[4],4);
if(cond) { goto P_0c03b020; }
goto P_0c03b00c;
P_0c03b00a: /* original 2f42, guest PC 0x0c03b00a */
if(!s->budget--) { s->failed_pc=0x0c03b00au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c03b00c;
P_0c03b00c: /* original 64e3, guest PC 0x0c03b00c */
if(!s->budget--) { s->failed_pc=0x0c03b00cu; return 0; }
r[4]=r[14];
goto P_0c03b00e;
P_0c03b00e: /* original a008, guest PC 0x0c03b00e */
if(!s->budget--) { s->failed_pc=0x0c03b00eu; return 0; }
r[4]+=0xfffffff8u;
goto P_0c03b022;
P_0c03b010: /* original 74f8, guest PC 0x0c03b010 */
if(!s->budget--) { s->failed_pc=0x0c03b010u; return 0; }
r[4]+=0xfffffff8u;
return vf3_matrix_family(0x0c03b012u,s,ram);
P_0c03b020: /* original 64f2, guest PC 0x0c03b020 */
if(!s->budget--) { s->failed_pc=0x0c03b020u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c03b022;
P_0c03b022: /* original be65, guest PC 0x0c03b022 */
if(!s->budget--) { s->failed_pc=0x0c03b022u; return 0; }
target=0x0c03acf0u; r[16]=code_base|0x0c03b026u;
tmp=read(ram,r[4],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03b026u) { target=s->pc; goto dispatch; }
goto P_0c03b026;
P_0c03b024: /* original 6442, guest PC 0x0c03b024 */
if(!s->budget--) { s->failed_pc=0x0c03b024u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c03b026;
P_0c03b026: /* original a042, guest PC 0x0c03b026 */
if(!s->budget--) { s->failed_pc=0x0c03b026u; return 0; }
r[11]+=r[0];
goto P_0c03b0ae;
P_0c03b028: /* original 3b0c, guest PC 0x0c03b028 */
if(!s->budget--) { s->failed_pc=0x0c03b028u; return 0; }
r[11]+=r[0];
return vf3_matrix_family(0x0c03b02au,s,ram);
P_0c03b030: /* original 65e3, guest PC 0x0c03b030 */
if(!s->budget--) { s->failed_pc=0x0c03b030u; return 0; }
r[5]=r[14];
goto P_0c03b032;
P_0c03b032: /* original 7504, guest PC 0x0c03b032 */
if(!s->budget--) { s->failed_pc=0x0c03b032u; return 0; }
r[5]+=0x00000004u;
goto P_0c03b034;
P_0c03b034: /* original 6253, guest PC 0x0c03b034 */
if(!s->budget--) { s->failed_pc=0x0c03b034u; return 0; }
r[2]=r[5];
goto P_0c03b036;
P_0c03b036: /* original 22d8, guest PC 0x0c03b036 */
if(!s->budget--) { s->failed_pc=0x0c03b036u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c03b038;
P_0c03b038: /* original 8902, guest PC 0x0c03b038 */
if(!s->budget--) { s->failed_pc=0x0c03b038u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03b040; }
goto P_0c03b03a;
P_0c03b03a: /* original a002, guest PC 0x0c03b03a */
if(!s->budget--) { s->failed_pc=0x0c03b03au; return 0; }
r[14]+=0x00000008u;
goto P_0c03b042;
P_0c03b03c: /* original 7e08, guest PC 0x0c03b03c */
if(!s->budget--) { s->failed_pc=0x0c03b03cu; return 0; }
r[14]+=0x00000008u;
return vf3_matrix_family(0x0c03b03eu,s,ram);
P_0c03b040: /* original 6e53, guest PC 0x0c03b040 */
if(!s->budget--) { s->failed_pc=0x0c03b040u; return 0; }
r[14]=r[5];
goto P_0c03b042;
P_0c03b042: /* original 64e3, guest PC 0x0c03b042 */
if(!s->budget--) { s->failed_pc=0x0c03b042u; return 0; }
r[4]=r[14];
goto P_0c03b044;
P_0c03b044: /* original 74fc, guest PC 0x0c03b044 */
if(!s->budget--) { s->failed_pc=0x0c03b044u; return 0; }
r[4]+=0xfffffffcu;
goto P_0c03b046;
P_0c03b046: /* original 6243, guest PC 0x0c03b046 */
if(!s->budget--) { s->failed_pc=0x0c03b046u; return 0; }
r[2]=r[4];
goto P_0c03b048;
P_0c03b048: /* original 22d8, guest PC 0x0c03b048 */
if(!s->budget--) { s->failed_pc=0x0c03b048u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c03b04a;
P_0c03b04a: /* original 8909, guest PC 0x0c03b04a */
if(!s->budget--) { s->failed_pc=0x0c03b04au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03b060; }
goto P_0c03b04c;
P_0c03b04c: /* original 63e3, guest PC 0x0c03b04c */
if(!s->budget--) { s->failed_pc=0x0c03b04cu; return 0; }
r[3]=r[14];
goto P_0c03b04e;
P_0c03b04e: /* original a008, guest PC 0x0c03b04e */
if(!s->budget--) { s->failed_pc=0x0c03b04eu; return 0; }
r[3]+=0xfffffff8u;
goto P_0c03b062;
P_0c03b050: /* original 73f8, guest PC 0x0c03b050 */
if(!s->budget--) { s->failed_pc=0x0c03b050u; return 0; }
r[3]+=0xfffffff8u;
return vf3_matrix_family(0x0c03b052u,s,ram);
P_0c03b060: /* original 6343, guest PC 0x0c03b060 */
if(!s->budget--) { s->failed_pc=0x0c03b060u; return 0; }
r[3]=r[4];
goto P_0c03b062;
P_0c03b062: /* original 6432, guest PC 0x0c03b062 */
if(!s->budget--) { s->failed_pc=0x0c03b062u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c03b064;
P_0c03b064: /* original 60b3, guest PC 0x0c03b064 */
if(!s->budget--) { s->failed_pc=0x0c03b064u; return 0; }
r[0]=r[11];
goto P_0c03b066;
P_0c03b066: /* original 7b01, guest PC 0x0c03b066 */
if(!s->budget--) { s->failed_pc=0x0c03b066u; return 0; }
r[11]+=0x00000001u;
goto P_0c03b068;
P_0c03b068: /* original a021, guest PC 0x0c03b068 */
if(!s->budget--) { s->failed_pc=0x0c03b068u; return 0; }
write(ram,r[10]+r[0],r[4],1);
goto P_0c03b0ae;
P_0c03b06a: /* original 0a44, guest PC 0x0c03b06a */
if(!s->budget--) { s->failed_pc=0x0c03b06au; return 0; }
write(ram,r[10]+r[0],r[4],1);
return vf3_matrix_family(0x0c03b06cu,s,ram);
P_0c03b070: /* original 65e3, guest PC 0x0c03b070 */
if(!s->budget--) { s->failed_pc=0x0c03b070u; return 0; }
r[5]=r[14];
goto P_0c03b072;
P_0c03b072: /* original 7504, guest PC 0x0c03b072 */
if(!s->budget--) { s->failed_pc=0x0c03b072u; return 0; }
r[5]+=0x00000004u;
goto P_0c03b074;
P_0c03b074: /* original 6453, guest PC 0x0c03b074 */
if(!s->budget--) { s->failed_pc=0x0c03b074u; return 0; }
r[4]=r[5];
goto P_0c03b076;
P_0c03b076: /* original 24d8, guest PC 0x0c03b076 */
if(!s->budget--) { s->failed_pc=0x0c03b076u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[13])==0)!=0);
goto P_0c03b078;
P_0c03b078: /* original 8902, guest PC 0x0c03b078 */
if(!s->budget--) { s->failed_pc=0x0c03b078u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03b080; }
goto P_0c03b07a;
P_0c03b07a: /* original a002, guest PC 0x0c03b07a */
if(!s->budget--) { s->failed_pc=0x0c03b07au; return 0; }
r[14]+=0x00000008u;
goto P_0c03b082;
P_0c03b07c: /* original 7e08, guest PC 0x0c03b07c */
if(!s->budget--) { s->failed_pc=0x0c03b07cu; return 0; }
r[14]+=0x00000008u;
return vf3_matrix_family(0x0c03b07eu,s,ram);
P_0c03b080: /* original 6e53, guest PC 0x0c03b080 */
if(!s->budget--) { s->failed_pc=0x0c03b080u; return 0; }
r[14]=r[5];
goto P_0c03b082;
P_0c03b082: /* original 66e3, guest PC 0x0c03b082 */
if(!s->budget--) { s->failed_pc=0x0c03b082u; return 0; }
r[6]=r[14];
goto P_0c03b084;
P_0c03b084: /* original 76fc, guest PC 0x0c03b084 */
if(!s->budget--) { s->failed_pc=0x0c03b084u; return 0; }
r[6]+=0xfffffffcu;
goto P_0c03b086;
P_0c03b086: /* original 6463, guest PC 0x0c03b086 */
if(!s->budget--) { s->failed_pc=0x0c03b086u; return 0; }
r[4]=r[6];
goto P_0c03b088;
P_0c03b088: /* original 24d8, guest PC 0x0c03b088 */
if(!s->budget--) { s->failed_pc=0x0c03b088u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[13])==0)!=0);
goto P_0c03b08a;
P_0c03b08a: /* original 8901, guest PC 0x0c03b08a */
if(!s->budget--) { s->failed_pc=0x0c03b08au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03b090; }
goto P_0c03b08c;
P_0c03b08c: /* original 64e3, guest PC 0x0c03b08c */
if(!s->budget--) { s->failed_pc=0x0c03b08cu; return 0; }
r[4]=r[14];
goto P_0c03b08e;
P_0c03b08e: /* original 74f8, guest PC 0x0c03b08e */
if(!s->budget--) { s->failed_pc=0x0c03b08eu; return 0; }
r[4]+=0xfffffff8u;
goto P_0c03b090;
P_0c03b090: /* original a00a, guest PC 0x0c03b090 */
if(!s->budget--) { s->failed_pc=0x0c03b090u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c03b0a8;
P_0c03b092: /* original 6442, guest PC 0x0c03b092 */
if(!s->budget--) { s->failed_pc=0x0c03b092u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
return vf3_matrix_family(0x0c03b094u,s,ram);
P_0c03b0a0: /* original 6344, guest PC 0x0c03b0a0 */
if(!s->budget--) { s->failed_pc=0x0c03b0a0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[3]=tmp;
goto P_0c03b0a2;
P_0c03b0a2: /* original 60b3, guest PC 0x0c03b0a2 */
if(!s->budget--) { s->failed_pc=0x0c03b0a2u; return 0; }
r[0]=r[11];
goto P_0c03b0a4;
P_0c03b0a4: /* original 7b01, guest PC 0x0c03b0a4 */
if(!s->budget--) { s->failed_pc=0x0c03b0a4u; return 0; }
r[11]+=0x00000001u;
goto P_0c03b0a6;
P_0c03b0a6: /* original 0a34, guest PC 0x0c03b0a6 */
if(!s->budget--) { s->failed_pc=0x0c03b0a6u; return 0; }
write(ram,r[10]+r[0],r[3],1);
goto P_0c03b0a8;
P_0c03b0a8: /* original 6240, guest PC 0x0c03b0a8 */
if(!s->budget--) { s->failed_pc=0x0c03b0a8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c03b0aa;
P_0c03b0aa: /* original 2228, guest PC 0x0c03b0aa */
if(!s->budget--) { s->failed_pc=0x0c03b0aau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03b0ac;
P_0c03b0ac: /* original 8bf8, guest PC 0x0c03b0ac */
if(!s->budget--) { s->failed_pc=0x0c03b0acu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03b0a0; }
goto P_0c03b0ae;
P_0c03b0ae: /* original 7901, guest PC 0x0c03b0ae */
if(!s->budget--) { s->failed_pc=0x0c03b0aeu; return 0; }
r[9]+=0x00000001u;
goto P_0c03b0b0;
P_0c03b0b0: /* original 6490, guest PC 0x0c03b0b0 */
if(!s->budget--) { s->failed_pc=0x0c03b0b0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[9],1);
r[4]=tmp;
goto P_0c03b0b2;
P_0c03b0b2: /* original 634e, guest PC 0x0c03b0b2 */
if(!s->budget--) { s->failed_pc=0x0c03b0b2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c03b0b4;
P_0c03b0b4: /* original 2338, guest PC 0x0c03b0b4 */
if(!s->budget--) { s->failed_pc=0x0c03b0b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03b0b6;
P_0c03b0b6: /* original 8901, guest PC 0x0c03b0b6 */
if(!s->budget--) { s->failed_pc=0x0c03b0b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03b0bc; }
goto P_0c03b0b8;
P_0c03b0b8: /* original aeba, guest PC 0x0c03b0b8 */
if(!s->budget--) { s->failed_pc=0x0c03b0b8u; return 0; }
goto P_0c03ae30;
P_0c03b0ba: /* original 0009, guest PC 0x0c03b0ba */
if(!s->budget--) { s->failed_pc=0x0c03b0bau; return 0; }
goto P_0c03b0bc;
P_0c03b0bc: /* original 7f08, guest PC 0x0c03b0bc */
if(!s->budget--) { s->failed_pc=0x0c03b0bcu; return 0; }
r[15]+=0x00000008u;
goto P_0c03b0be;
P_0c03b0be: /* original 60b3, guest PC 0x0c03b0be */
if(!s->budget--) { s->failed_pc=0x0c03b0beu; return 0; }
r[0]=r[11];
goto P_0c03b0c0;
P_0c03b0c0: /* original 4f26, guest PC 0x0c03b0c0 */
if(!s->budget--) { s->failed_pc=0x0c03b0c0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03b0c2;
P_0c03b0c2: /* original e300, guest PC 0x0c03b0c2 */
if(!s->budget--) { s->failed_pc=0x0c03b0c2u; return 0; }
r[3]=0x00000000u;
goto P_0c03b0c4;
P_0c03b0c4: /* original 0a34, guest PC 0x0c03b0c4 */
if(!s->budget--) { s->failed_pc=0x0c03b0c4u; return 0; }
write(ram,r[10]+r[0],r[3],1);
goto P_0c03b0c6;
P_0c03b0c6: /* original 68f6, guest PC 0x0c03b0c6 */
if(!s->budget--) { s->failed_pc=0x0c03b0c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03b0c8;
P_0c03b0c8: /* original 69f6, guest PC 0x0c03b0c8 */
if(!s->budget--) { s->failed_pc=0x0c03b0c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03b0ca;
P_0c03b0ca: /* original 6af6, guest PC 0x0c03b0ca */
if(!s->budget--) { s->failed_pc=0x0c03b0cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03b0cc;
P_0c03b0cc: /* original 6bf6, guest PC 0x0c03b0cc */
if(!s->budget--) { s->failed_pc=0x0c03b0ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03b0ce;
P_0c03b0ce: /* original 6cf6, guest PC 0x0c03b0ce */
if(!s->budget--) { s->failed_pc=0x0c03b0ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03b0d0;
P_0c03b0d0: /* original 6df6, guest PC 0x0c03b0d0 */
if(!s->budget--) { s->failed_pc=0x0c03b0d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03b0d2;
P_0c03b0d2: /* original 000b, guest PC 0x0c03b0d2 */
if(!s->budget--) { s->failed_pc=0x0c03b0d2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03b0d4: /* original 6ef6, guest PC 0x0c03b0d4 */
if(!s->budget--) { s->failed_pc=0x0c03b0d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03b0d6u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c03acf0u,0x0c03acf2u,0x0c03acf4u,0x0c03acf6u,0x0c03acf8u,0x0c03acfau,0x0c03acfcu,0x0c03acfeu,0x0c03ad00u,0x0c03ad02u,0x0c03ad04u,0x0c03ad06u,0x0c03ad08u,0x0c03ad0au,0x0c03ad0cu,0x0c03ad0eu,
0x0c03ad10u,0x0c03ad12u,0x0c03ad14u,0x0c03ad16u,0x0c03ad18u,0x0c03ad1au,0x0c03ad1cu,0x0c03ad1eu,0x0c03ad20u,0x0c03ad22u,0x0c03ad24u,0x0c03ad26u,0x0c03ad28u,0x0c03ad2au,0x0c03ad2cu,0x0c03ad2eu,
0x0c03ad30u,0x0c03ad32u,0x0c03ad34u,0x0c03ad36u,0x0c03ad38u,0x0c03ad3au,0x0c03ad3cu,0x0c03ad3eu,0x0c03ad40u,0x0c03ad50u,0x0c03ad52u,0x0c03ad54u,0x0c03ad56u,0x0c03ad58u,0x0c03ad5au,0x0c03ad5cu,
0x0c03ad5eu,0x0c03ad60u,0x0c03ad62u,0x0c03ad64u,0x0c03ad66u,0x0c03ad68u,0x0c03ad6au,0x0c03ad6cu,0x0c03ad6eu,0x0c03ad70u,0x0c03ad72u,0x0c03ad80u,0x0c03ad82u,0x0c03ad84u,0x0c03ad86u,0x0c03ad88u,
0x0c03ad8au,0x0c03ad8cu,0x0c03ad8eu,0x0c03ad90u,0x0c03ad92u,0x0c03ad94u,0x0c03ad96u,0x0c03ad98u,0x0c03ada0u,0x0c03ada2u,0x0c03ada4u,0x0c03ada6u,0x0c03ada8u,0x0c03adaau,0x0c03adacu,0x0c03adb0u,
0x0c03adb2u,0x0c03adb4u,0x0c03adb6u,0x0c03adb8u,0x0c03adbau,0x0c03adbcu,0x0c03adbeu,0x0c03adc0u,0x0c03adc2u,0x0c03adc4u,0x0c03adc6u,0x0c03adc8u,0x0c03adcau,0x0c03adccu,0x0c03adceu,0x0c03add0u,
0x0c03add2u,0x0c03ade0u,0x0c03ade2u,0x0c03ade4u,0x0c03ade6u,0x0c03ade8u,0x0c03adeau,0x0c03adecu,0x0c03adeeu,0x0c03adf0u,0x0c03adf2u,0x0c03adf4u,0x0c03adf6u,0x0c03adf8u,0x0c03ae16u,0x0c03ae18u,
0x0c03ae1au,0x0c03ae1cu,0x0c03ae1eu,0x0c03ae20u,0x0c03ae30u,0x0c03ae32u,0x0c03ae34u,0x0c03ae36u,0x0c03ae38u,0x0c03ae3au,0x0c03ae3cu,0x0c03ae3eu,0x0c03ae40u,0x0c03ae42u,0x0c03ae44u,0x0c03ae46u,
0x0c03ae48u,0x0c03ae50u,0x0c03ae52u,0x0c03ae54u,0x0c03ae56u,0x0c03ae58u,0x0c03ae60u,0x0c03ae62u,0x0c03ae64u,0x0c03ae66u,0x0c03ae68u,0x0c03ae6au,0x0c03ae6cu,0x0c03ae6eu,0x0c03ae70u,0x0c03aeb0u,
0x0c03aeb2u,0x0c03aeb4u,0x0c03aeb6u,0x0c03aeb8u,0x0c03aebau,0x0c03aec0u,0x0c03aec2u,0x0c03aec4u,0x0c03aec6u,0x0c03aec8u,0x0c03aecau,0x0c03aeccu,0x0c03aeceu,0x0c03aed0u,0x0c03aed2u,0x0c03aed4u,
0x0c03aed6u,0x0c03aed8u,0x0c03aedau,0x0c03aedcu,0x0c03aedeu,0x0c03aee0u,0x0c03aee2u,0x0c03aee4u,0x0c03aee6u,0x0c03aee8u,0x0c03aeeau,0x0c03aeecu,0x0c03aeeeu,0x0c03aef0u,0x0c03aef2u,0x0c03aef4u,
0x0c03aef6u,0x0c03aef8u,0x0c03aefau,0x0c03aefcu,0x0c03aefeu,0x0c03af00u,0x0c03af02u,0x0c03af04u,0x0c03af06u,0x0c03af08u,0x0c03af0au,0x0c03af0cu,0x0c03af0eu,0x0c03af10u,0x0c03af12u,0x0c03af14u,
0x0c03af16u,0x0c03af18u,0x0c03af1au,0x0c03af1cu,0x0c03af1eu,0x0c03af20u,0x0c03af30u,0x0c03af32u,0x0c03af34u,0x0c03af36u,0x0c03af38u,0x0c03af3au,0x0c03af3cu,0x0c03af3eu,0x0c03af40u,0x0c03af50u,
0x0c03af52u,0x0c03af54u,0x0c03af56u,0x0c03af58u,0x0c03af5au,0x0c03af5cu,0x0c03af5eu,0x0c03af60u,0x0c03af70u,0x0c03af72u,0x0c03af74u,0x0c03af76u,0x0c03af78u,0x0c03af80u,0x0c03af82u,0x0c03af84u,
0x0c03af86u,0x0c03af88u,0x0c03af8au,0x0c03af8cu,0x0c03af8eu,0x0c03af90u,0x0c03af92u,0x0c03af94u,0x0c03af96u,0x0c03af98u,0x0c03af9au,0x0c03af9cu,0x0c03af9eu,0x0c03afa0u,0x0c03afb0u,0x0c03afb2u,
0x0c03afb4u,0x0c03afb6u,0x0c03afb8u,0x0c03afbau,0x0c03afbcu,0x0c03afbeu,0x0c03afc0u,0x0c03afd0u,0x0c03afd2u,0x0c03afd4u,0x0c03afd6u,0x0c03afd8u,0x0c03afe0u,0x0c03afe2u,0x0c03afe4u,0x0c03afe6u,
0x0c03afe8u,0x0c03afeau,0x0c03afecu,0x0c03afeeu,0x0c03aff0u,0x0c03aff2u,0x0c03b000u,0x0c03b002u,0x0c03b004u,0x0c03b006u,0x0c03b008u,0x0c03b00au,0x0c03b00cu,0x0c03b00eu,0x0c03b010u,0x0c03b020u,
0x0c03b022u,0x0c03b024u,0x0c03b026u,0x0c03b028u,0x0c03b030u,0x0c03b032u,0x0c03b034u,0x0c03b036u,0x0c03b038u,0x0c03b03au,0x0c03b03cu,0x0c03b040u,0x0c03b042u,0x0c03b044u,0x0c03b046u,0x0c03b048u,
0x0c03b04au,0x0c03b04cu,0x0c03b04eu,0x0c03b050u,0x0c03b060u,0x0c03b062u,0x0c03b064u,0x0c03b066u,0x0c03b068u,0x0c03b06au,0x0c03b070u,0x0c03b072u,0x0c03b074u,0x0c03b076u,0x0c03b078u,0x0c03b07au,
0x0c03b07cu,0x0c03b080u,0x0c03b082u,0x0c03b084u,0x0c03b086u,0x0c03b088u,0x0c03b08au,0x0c03b08cu,0x0c03b08eu,0x0c03b090u,0x0c03b092u,0x0c03b0a0u,0x0c03b0a2u,0x0c03b0a4u,0x0c03b0a6u,0x0c03b0a8u,
0x0c03b0aau,0x0c03b0acu,0x0c03b0aeu,0x0c03b0b0u,0x0c03b0b2u,0x0c03b0b4u,0x0c03b0b6u,0x0c03b0b8u,0x0c03b0bau,0x0c03b0bcu,0x0c03b0beu,0x0c03b0c0u,0x0c03b0c2u,0x0c03b0c4u,0x0c03b0c6u,0x0c03b0c8u,
0x0c03b0cau,0x0c03b0ccu,0x0c03b0ceu,0x0c03b0d0u,0x0c03b0d2u,0x0c03b0d4u,
};
int vf3_03ae_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
