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
int vf3_away_batch9_adapter_16(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06ad1cu: goto P_0c06ad1c;
case 0x0c06ad1eu: goto P_0c06ad1e;
case 0x0c06ad20u: goto P_0c06ad20;
case 0x0c06ad22u: goto P_0c06ad22;
case 0x0c06ad24u: goto P_0c06ad24;
case 0x0c06ad26u: goto P_0c06ad26;
case 0x0c06ad28u: goto P_0c06ad28;
case 0x0c06ad2au: goto P_0c06ad2a;
case 0x0c06ad2cu: goto P_0c06ad2c;
case 0x0c06ad2eu: goto P_0c06ad2e;
case 0x0c06ad30u: goto P_0c06ad30;
case 0x0c06ad32u: goto P_0c06ad32;
case 0x0c06ad34u: goto P_0c06ad34;
case 0x0c06ad36u: goto P_0c06ad36;
case 0x0c06ad38u: goto P_0c06ad38;
case 0x0c06ad3au: goto P_0c06ad3a;
case 0x0c06ad3cu: goto P_0c06ad3c;
case 0x0c06ad3eu: goto P_0c06ad3e;
case 0x0c06ad40u: goto P_0c06ad40;
case 0x0c06ad42u: goto P_0c06ad42;
case 0x0c06ad44u: goto P_0c06ad44;
case 0x0c06ad46u: goto P_0c06ad46;
case 0x0c06ad48u: goto P_0c06ad48;
case 0x0c06ad4au: goto P_0c06ad4a;
case 0x0c06ad4cu: goto P_0c06ad4c;
case 0x0c06ad4eu: goto P_0c06ad4e;
case 0x0c06ad50u: goto P_0c06ad50;
case 0x0c06ad52u: goto P_0c06ad52;
case 0x0c06ad54u: goto P_0c06ad54;
case 0x0c06ad56u: goto P_0c06ad56;
case 0x0c06ad58u: goto P_0c06ad58;
case 0x0c06ad5au: goto P_0c06ad5a;
case 0x0c06ad5cu: goto P_0c06ad5c;
case 0x0c06ad5eu: goto P_0c06ad5e;
case 0x0c06ad60u: goto P_0c06ad60;
case 0x0c06ad62u: goto P_0c06ad62;
case 0x0c06ad64u: goto P_0c06ad64;
case 0x0c06ad66u: goto P_0c06ad66;
case 0x0c06ad68u: goto P_0c06ad68;
case 0x0c06ad6au: goto P_0c06ad6a;
case 0x0c06ad6cu: goto P_0c06ad6c;
case 0x0c06ad6eu: goto P_0c06ad6e;
case 0x0c06ad70u: goto P_0c06ad70;
case 0x0c06ad72u: goto P_0c06ad72;
case 0x0c06ad74u: goto P_0c06ad74;
case 0x0c06ad76u: goto P_0c06ad76;
case 0x0c06ad78u: goto P_0c06ad78;
case 0x0c06ad7au: goto P_0c06ad7a;
case 0x0c06ad7cu: goto P_0c06ad7c;
case 0x0c06ad7eu: goto P_0c06ad7e;
case 0x0c06ad80u: goto P_0c06ad80;
case 0x0c06ad82u: goto P_0c06ad82;
case 0x0c06ad84u: goto P_0c06ad84;
case 0x0c06ad86u: goto P_0c06ad86;
case 0x0c06ad88u: goto P_0c06ad88;
case 0x0c06ad8au: goto P_0c06ad8a;
case 0x0c06ad8cu: goto P_0c06ad8c;
case 0x0c06ad8eu: goto P_0c06ad8e;
case 0x0c06ad90u: goto P_0c06ad90;
case 0x0c06ad92u: goto P_0c06ad92;
case 0x0c06ad94u: goto P_0c06ad94;
case 0x0c06ad96u: goto P_0c06ad96;
case 0x0c06ad98u: goto P_0c06ad98;
case 0x0c06ad9au: goto P_0c06ad9a;
case 0x0c06ad9cu: goto P_0c06ad9c;
case 0x0c06ad9eu: goto P_0c06ad9e;
case 0x0c06ada0u: goto P_0c06ada0;
case 0x0c06ada2u: goto P_0c06ada2;
case 0x0c06ada4u: goto P_0c06ada4;
case 0x0c06ada6u: goto P_0c06ada6;
case 0x0c06ada8u: goto P_0c06ada8;
case 0x0c06adaau: goto P_0c06adaa;
case 0x0c06adacu: goto P_0c06adac;
case 0x0c06adaeu: goto P_0c06adae;
case 0x0c06adb0u: goto P_0c06adb0;
case 0x0c06adb2u: goto P_0c06adb2;
case 0x0c06adb4u: goto P_0c06adb4;
case 0x0c06adb6u: goto P_0c06adb6;
case 0x0c06adb8u: goto P_0c06adb8;
case 0x0c06adbau: goto P_0c06adba;
case 0x0c06adbcu: goto P_0c06adbc;
case 0x0c06adbeu: goto P_0c06adbe;
case 0x0c06adc0u: goto P_0c06adc0;
case 0x0c06adc2u: goto P_0c06adc2;
case 0x0c06adc4u: goto P_0c06adc4;
case 0x0c06adc6u: goto P_0c06adc6;
case 0x0c06adc8u: goto P_0c06adc8;
case 0x0c06adcau: goto P_0c06adca;
case 0x0c06adccu: goto P_0c06adcc;
case 0x0c06adf4u: goto P_0c06adf4;
case 0x0c06adf6u: goto P_0c06adf6;
case 0x0c06adf8u: goto P_0c06adf8;
case 0x0c06adfau: goto P_0c06adfa;
case 0x0c06adfcu: goto P_0c06adfc;
case 0x0c06adfeu: goto P_0c06adfe;
case 0x0c06ae00u: goto P_0c06ae00;
case 0x0c06ae02u: goto P_0c06ae02;
case 0x0c06ae04u: goto P_0c06ae04;
case 0x0c06ae06u: goto P_0c06ae06;
case 0x0c06ae08u: goto P_0c06ae08;
case 0x0c06ae0au: goto P_0c06ae0a;
case 0x0c06ae0cu: goto P_0c06ae0c;
case 0x0c06ae0eu: goto P_0c06ae0e;
case 0x0c06ae10u: goto P_0c06ae10;
case 0x0c06ae12u: goto P_0c06ae12;
case 0x0c06ae14u: goto P_0c06ae14;
case 0x0c06ae16u: goto P_0c06ae16;
case 0x0c06ae18u: goto P_0c06ae18;
case 0x0c06ae1au: goto P_0c06ae1a;
case 0x0c06ae1cu: goto P_0c06ae1c;
case 0x0c06ae1eu: goto P_0c06ae1e;
case 0x0c06ae20u: goto P_0c06ae20;
case 0x0c06ae22u: goto P_0c06ae22;
case 0x0c06ae24u: goto P_0c06ae24;
case 0x0c06ae26u: goto P_0c06ae26;
case 0x0c06ae28u: goto P_0c06ae28;
case 0x0c06ae2au: goto P_0c06ae2a;
case 0x0c06ae2cu: goto P_0c06ae2c;
case 0x0c06ae2eu: goto P_0c06ae2e;
case 0x0c06ae30u: goto P_0c06ae30;
case 0x0c06ae32u: goto P_0c06ae32;
case 0x0c06ae34u: goto P_0c06ae34;
case 0x0c06ae36u: goto P_0c06ae36;
case 0x0c06ae38u: goto P_0c06ae38;
case 0x0c06ae3au: goto P_0c06ae3a;
case 0x0c06ae3cu: goto P_0c06ae3c;
case 0x0c06ae3eu: goto P_0c06ae3e;
case 0x0c06ae40u: goto P_0c06ae40;
case 0x0c06ae42u: goto P_0c06ae42;
case 0x0c06ae44u: goto P_0c06ae44;
case 0x0c06ae46u: goto P_0c06ae46;
case 0x0c06ae48u: goto P_0c06ae48;
case 0x0c06ae4au: goto P_0c06ae4a;
case 0x0c06ae4cu: goto P_0c06ae4c;
case 0x0c06ae4eu: goto P_0c06ae4e;
case 0x0c06ae50u: goto P_0c06ae50;
case 0x0c06ae52u: goto P_0c06ae52;
case 0x0c06ae54u: goto P_0c06ae54;
case 0x0c06ae56u: goto P_0c06ae56;
case 0x0c06ae58u: goto P_0c06ae58;
case 0x0c06ae5au: goto P_0c06ae5a;
case 0x0c06ae5cu: goto P_0c06ae5c;
case 0x0c06ae5eu: goto P_0c06ae5e;
case 0x0c06ae60u: goto P_0c06ae60;
case 0x0c06ae62u: goto P_0c06ae62;
case 0x0c06ae64u: goto P_0c06ae64;
case 0x0c06ae66u: goto P_0c06ae66;
case 0x0c06ae68u: goto P_0c06ae68;
case 0x0c06ae6au: goto P_0c06ae6a;
case 0x0c06ae6cu: goto P_0c06ae6c;
case 0x0c06ae6eu: goto P_0c06ae6e;
case 0x0c06ae70u: goto P_0c06ae70;
case 0x0c06ae72u: goto P_0c06ae72;
case 0x0c06ae74u: goto P_0c06ae74;
case 0x0c06ae76u: goto P_0c06ae76;
case 0x0c06ae78u: goto P_0c06ae78;
case 0x0c06ae7au: goto P_0c06ae7a;
case 0x0c06ae7cu: goto P_0c06ae7c;
case 0x0c06ae7eu: goto P_0c06ae7e;
case 0x0c06ae80u: goto P_0c06ae80;
case 0x0c06ae82u: goto P_0c06ae82;
case 0x0c06ae84u: goto P_0c06ae84;
case 0x0c06ae86u: goto P_0c06ae86;
case 0x0c06ae88u: goto P_0c06ae88;
case 0x0c06ae8au: goto P_0c06ae8a;
case 0x0c06ae8cu: goto P_0c06ae8c;
case 0x0c06ae8eu: goto P_0c06ae8e;
case 0x0c06ae90u: goto P_0c06ae90;
case 0x0c06ae92u: goto P_0c06ae92;
case 0x0c06ae94u: goto P_0c06ae94;
case 0x0c06ae96u: goto P_0c06ae96;
case 0x0c06ae98u: goto P_0c06ae98;
case 0x0c06ae9au: goto P_0c06ae9a;
case 0x0c06ae9cu: goto P_0c06ae9c;
case 0x0c06ae9eu: goto P_0c06ae9e;
case 0x0c06aea0u: goto P_0c06aea0;
case 0x0c06aea2u: goto P_0c06aea2;
case 0x0c06aea4u: goto P_0c06aea4;
case 0x0c06aea6u: goto P_0c06aea6;
case 0x0c06aea8u: goto P_0c06aea8;
case 0x0c06aeaau: goto P_0c06aeaa;
case 0x0c06aeacu: goto P_0c06aeac;
case 0x0c06aeaeu: goto P_0c06aeae;
case 0x0c06aeb0u: goto P_0c06aeb0;
case 0x0c06aeb2u: goto P_0c06aeb2;
case 0x0c06aeb4u: goto P_0c06aeb4;
case 0x0c06aeb6u: goto P_0c06aeb6;
case 0x0c06aeb8u: goto P_0c06aeb8;
case 0x0c06aebau: goto P_0c06aeba;
case 0x0c06aebcu: goto P_0c06aebc;
case 0x0c06aebeu: goto P_0c06aebe;
case 0x0c06aec0u: goto P_0c06aec0;
case 0x0c06aec2u: goto P_0c06aec2;
case 0x0c06aec4u: goto P_0c06aec4;
case 0x0c06aec6u: goto P_0c06aec6;
case 0x0c06aec8u: goto P_0c06aec8;
case 0x0c06aecau: goto P_0c06aeca;
case 0x0c06aeccu: goto P_0c06aecc;
case 0x0c06aeceu: goto P_0c06aece;
case 0x0c06aed0u: goto P_0c06aed0;
case 0x0c06aed2u: goto P_0c06aed2;
case 0x0c06aed4u: goto P_0c06aed4;
case 0x0c06aed6u: goto P_0c06aed6;
case 0x0c06aed8u: goto P_0c06aed8;
case 0x0c06aedau: goto P_0c06aeda;
case 0x0c06aedcu: goto P_0c06aedc;
case 0x0c06aefcu: goto P_0c06aefc;
case 0x0c06aefeu: goto P_0c06aefe;
case 0x0c06af00u: goto P_0c06af00;
case 0x0c06af02u: goto P_0c06af02;
case 0x0c06af04u: goto P_0c06af04;
case 0x0c06af06u: goto P_0c06af06;
case 0x0c06af08u: goto P_0c06af08;
case 0x0c06af0au: goto P_0c06af0a;
case 0x0c06af0cu: goto P_0c06af0c;
case 0x0c06af0eu: goto P_0c06af0e;
case 0x0c06af10u: goto P_0c06af10;
case 0x0c06af12u: goto P_0c06af12;
case 0x0c06af14u: goto P_0c06af14;
case 0x0c06af16u: goto P_0c06af16;
case 0x0c06af18u: goto P_0c06af18;
case 0x0c06af1au: goto P_0c06af1a;
case 0x0c06af1cu: goto P_0c06af1c;
case 0x0c06af1eu: goto P_0c06af1e;
case 0x0c06af20u: goto P_0c06af20;
case 0x0c06af22u: goto P_0c06af22;
case 0x0c06af24u: goto P_0c06af24;
case 0x0c06af26u: goto P_0c06af26;
case 0x0c06af28u: goto P_0c06af28;
case 0x0c06af2au: goto P_0c06af2a;
case 0x0c06af2cu: goto P_0c06af2c;
case 0x0c06af2eu: goto P_0c06af2e;
case 0x0c06af30u: goto P_0c06af30;
case 0x0c06af32u: goto P_0c06af32;
case 0x0c06af34u: goto P_0c06af34;
case 0x0c06af36u: goto P_0c06af36;
case 0x0c06af38u: goto P_0c06af38;
case 0x0c06af3au: goto P_0c06af3a;
case 0x0c06af3cu: goto P_0c06af3c;
case 0x0c06af3eu: goto P_0c06af3e;
case 0x0c06af40u: goto P_0c06af40;
case 0x0c06af42u: goto P_0c06af42;
case 0x0c06af44u: goto P_0c06af44;
case 0x0c06af46u: goto P_0c06af46;
case 0x0c06af48u: goto P_0c06af48;
case 0x0c06af4au: goto P_0c06af4a;
case 0x0c06af4cu: goto P_0c06af4c;
case 0x0c06af4eu: goto P_0c06af4e;
case 0x0c06af50u: goto P_0c06af50;
case 0x0c06af52u: goto P_0c06af52;
case 0x0c06af54u: goto P_0c06af54;
case 0x0c06af56u: goto P_0c06af56;
case 0x0c06af58u: goto P_0c06af58;
case 0x0c06af5au: goto P_0c06af5a;
case 0x0c06af5cu: goto P_0c06af5c;
case 0x0c06af5eu: goto P_0c06af5e;
case 0x0c06af60u: goto P_0c06af60;
case 0x0c06af62u: goto P_0c06af62;
case 0x0c06af64u: goto P_0c06af64;
case 0x0c06af66u: goto P_0c06af66;
case 0x0c06af68u: goto P_0c06af68;
case 0x0c06af6au: goto P_0c06af6a;
case 0x0c06af6cu: goto P_0c06af6c;
case 0x0c06af6eu: goto P_0c06af6e;
case 0x0c06af70u: goto P_0c06af70;
case 0x0c06af72u: goto P_0c06af72;
case 0x0c06af74u: goto P_0c06af74;
case 0x0c06af76u: goto P_0c06af76;
case 0x0c06af78u: goto P_0c06af78;
case 0x0c06af7au: goto P_0c06af7a;
case 0x0c06af7cu: goto P_0c06af7c;
case 0x0c06af7eu: goto P_0c06af7e;
case 0x0c06af80u: goto P_0c06af80;
case 0x0c06af82u: goto P_0c06af82;
case 0x0c06af84u: goto P_0c06af84;
case 0x0c06af86u: goto P_0c06af86;
case 0x0c06af88u: goto P_0c06af88;
case 0x0c06af8au: goto P_0c06af8a;
case 0x0c06af8cu: goto P_0c06af8c;
case 0x0c06af8eu: goto P_0c06af8e;
case 0x0c06af90u: goto P_0c06af90;
case 0x0c06af92u: goto P_0c06af92;
case 0x0c06af94u: goto P_0c06af94;
case 0x0c06af96u: goto P_0c06af96;
case 0x0c06af98u: goto P_0c06af98;
case 0x0c06af9au: goto P_0c06af9a;
case 0x0c06af9cu: goto P_0c06af9c;
case 0x0c06af9eu: goto P_0c06af9e;
case 0x0c06afa0u: goto P_0c06afa0;
case 0x0c06afa2u: goto P_0c06afa2;
case 0x0c06afa4u: goto P_0c06afa4;
case 0x0c06afa6u: goto P_0c06afa6;
case 0x0c06afa8u: goto P_0c06afa8;
case 0x0c06afaau: goto P_0c06afaa;
case 0x0c06afacu: goto P_0c06afac;
case 0x0c06afaeu: goto P_0c06afae;
case 0x0c06afb0u: goto P_0c06afb0;
case 0x0c06afb2u: goto P_0c06afb2;
case 0x0c06afb4u: goto P_0c06afb4;
case 0x0c06afb6u: goto P_0c06afb6;
case 0x0c06afb8u: goto P_0c06afb8;
case 0x0c06afbau: goto P_0c06afba;
case 0x0c06afbcu: goto P_0c06afbc;
case 0x0c06afbeu: goto P_0c06afbe;
case 0x0c06afc0u: goto P_0c06afc0;
case 0x0c06afc2u: goto P_0c06afc2;
case 0x0c06afc4u: goto P_0c06afc4;
case 0x0c06afc6u: goto P_0c06afc6;
case 0x0c06afc8u: goto P_0c06afc8;
case 0x0c06afcau: goto P_0c06afca;
case 0x0c06afccu: goto P_0c06afcc;
case 0x0c06afceu: goto P_0c06afce;
case 0x0c06afd0u: goto P_0c06afd0;
case 0x0c06afd2u: goto P_0c06afd2;
case 0x0c06afd4u: goto P_0c06afd4;
case 0x0c06afd6u: goto P_0c06afd6;
case 0x0c06afd8u: goto P_0c06afd8;
case 0x0c06afdau: goto P_0c06afda;
case 0x0c06afdcu: goto P_0c06afdc;
case 0x0c06afdeu: goto P_0c06afde;
case 0x0c06afe0u: goto P_0c06afe0;
case 0x0c06afe2u: goto P_0c06afe2;
case 0x0c06afe4u: goto P_0c06afe4;
case 0x0c06afe6u: goto P_0c06afe6;
case 0x0c06afe8u: goto P_0c06afe8;
case 0x0c06afeau: goto P_0c06afea;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06ad1c: /* original 2fe6, guest PC 0x0c06ad1c */
if(!s->budget--) { s->failed_pc=0x0c06ad1cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ad1e;
P_0c06ad1e: /* original c72d, guest PC 0x0c06ad1e */
if(!s->budget--) { s->failed_pc=0x0c06ad1eu; return 0; }
r[0]=code_base|0x0006add4u;
goto P_0c06ad20;
P_0c06ad20: /* original 2fd6, guest PC 0x0c06ad20 */
if(!s->budget--) { s->failed_pc=0x0c06ad20u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ad22;
P_0c06ad22: /* original 2fc6, guest PC 0x0c06ad22 */
if(!s->budget--) { s->failed_pc=0x0c06ad22u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ad24;
P_0c06ad24: /* original 455a, guest PC 0x0c06ad24 */
if(!s->budget--) { s->failed_pc=0x0c06ad24u; return 0; }
r[53]=r[5];
goto P_0c06ad26;
P_0c06ad26: /* original 4f22, guest PC 0x0c06ad26 */
if(!s->budget--) { s->failed_pc=0x0c06ad26u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06ad28;
P_0c06ad28: /* original f28d, guest PC 0x0c06ad28 */
if(!s->budget--) { s->failed_pc=0x0c06ad28u; return 0; }
fr[2]=0;
goto P_0c06ad2a;
P_0c06ad2a: /* original f32d, guest PC 0x0c06ad2a */
if(!s->budget--) { s->failed_pc=0x0c06ad2au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c06ad2c;
P_0c06ad2c: /* original f508, guest PC 0x0c06ad2c */
if(!s->budget--) { s->failed_pc=0x0c06ad2cu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c06ad2e;
P_0c06ad2e: /* original 4f12, guest PC 0x0c06ad2e */
if(!s->budget--) { s->failed_pc=0x0c06ad2eu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c06ad30;
P_0c06ad30: /* original f235, guest PC 0x0c06ad30 */
if(!s->budget--) { s->failed_pc=0x0c06ad30u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c06ad32;
P_0c06ad32: /* original 8f03, guest PC 0x0c06ad32 */
if(!s->budget--) { s->failed_pc=0x0c06ad32u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,3);
if(!cond) { goto P_0c06ad3c; }
goto P_0c06ad36;
P_0c06ad34: /* original f43c, guest PC 0x0c06ad34 */
if(!s->budget--) { s->failed_pc=0x0c06ad34u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c06ad36;
P_0c06ad36: /* original c728, guest PC 0x0c06ad36 */
if(!s->budget--) { s->failed_pc=0x0c06ad36u; return 0; }
r[0]=code_base|0x0006add8u;
goto P_0c06ad38;
P_0c06ad38: /* original f308, guest PC 0x0c06ad38 */
if(!s->budget--) { s->failed_pc=0x0c06ad38u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06ad3a;
P_0c06ad3a: /* original f430, guest PC 0x0c06ad3a */
if(!s->budget--) { s->failed_pc=0x0c06ad3au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c06ad3c;
P_0c06ad3c: /* original f64c, guest PC 0x0c06ad3c */
if(!s->budget--) { s->failed_pc=0x0c06ad3cu; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c06ad3e;
P_0c06ad3e: /* original f653, guest PC 0x0c06ad3e */
if(!s->budget--) { s->failed_pc=0x0c06ad3eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'/');
goto P_0c06ad40;
P_0c06ad40: /* original f28d, guest PC 0x0c06ad40 */
if(!s->budget--) { s->failed_pc=0x0c06ad40u; return 0; }
fr[2]=0;
goto P_0c06ad42;
P_0c06ad42: /* original f63d, guest PC 0x0c06ad42 */
if(!s->budget--) { s->failed_pc=0x0c06ad42u; return 0; }
r[53]=truncate_float(fr[6]);
goto P_0c06ad44;
P_0c06ad44: /* original 055a, guest PC 0x0c06ad44 */
if(!s->budget--) { s->failed_pc=0x0c06ad44u; return 0; }
r[5]=r[53];
goto P_0c06ad46;
P_0c06ad46: /* original 455a, guest PC 0x0c06ad46 */
if(!s->budget--) { s->failed_pc=0x0c06ad46u; return 0; }
r[53]=r[5];
goto P_0c06ad48;
P_0c06ad48: /* original f32d, guest PC 0x0c06ad48 */
if(!s->budget--) { s->failed_pc=0x0c06ad48u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c06ad4a;
P_0c06ad4a: /* original f235, guest PC 0x0c06ad4a */
if(!s->budget--) { s->failed_pc=0x0c06ad4au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c06ad4c;
P_0c06ad4c: /* original 8f03, guest PC 0x0c06ad4c */
if(!s->budget--) { s->failed_pc=0x0c06ad4cu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,6,3);
if(!cond) { goto P_0c06ad56; }
goto P_0c06ad50;
P_0c06ad4e: /* original f63c, guest PC 0x0c06ad4e */
if(!s->budget--) { s->failed_pc=0x0c06ad4eu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c06ad50;
P_0c06ad50: /* original c721, guest PC 0x0c06ad50 */
if(!s->budget--) { s->failed_pc=0x0c06ad50u; return 0; }
r[0]=code_base|0x0006add8u;
goto P_0c06ad52;
P_0c06ad52: /* original f308, guest PC 0x0c06ad52 */
if(!s->budget--) { s->failed_pc=0x0c06ad52u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06ad54;
P_0c06ad54: /* original f630, guest PC 0x0c06ad54 */
if(!s->budget--) { s->failed_pc=0x0c06ad54u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'+');
goto P_0c06ad56;
P_0c06ad56: /* original f562, guest PC 0x0c06ad56 */
if(!s->budget--) { s->failed_pc=0x0c06ad56u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c06ad58;
P_0c06ad58: /* original d220, guest PC 0x0c06ad58 */
if(!s->budget--) { s->failed_pc=0x0c06ad58u; return 0; }
r[2]=read(ram,0x0c06addcu,4);
goto P_0c06ad5a;
P_0c06ad5a: /* original f63d, guest PC 0x0c06ad5a */
if(!s->budget--) { s->failed_pc=0x0c06ad5au; return 0; }
r[53]=truncate_float(fr[6]);
goto P_0c06ad5c;
P_0c06ad5c: /* original e53c, guest PC 0x0c06ad5c */
if(!s->budget--) { s->failed_pc=0x0c06ad5cu; return 0; }
r[5]=0x0000003cu;
goto P_0c06ad5e;
P_0c06ad5e: /* original f451, guest PC 0x0c06ad5e */
if(!s->budget--) { s->failed_pc=0x0c06ad5eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c06ad60;
P_0c06ad60: /* original 0d5a, guest PC 0x0c06ad60 */
if(!s->budget--) { s->failed_pc=0x0c06ad60u; return 0; }
r[13]=r[53];
goto P_0c06ad62;
P_0c06ad62: /* original f43d, guest PC 0x0c06ad62 */
if(!s->budget--) { s->failed_pc=0x0c06ad62u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c06ad64;
P_0c06ad64: /* original 61d3, guest PC 0x0c06ad64 */
if(!s->budget--) { s->failed_pc=0x0c06ad64u; return 0; }
r[1]=r[13];
goto P_0c06ad66;
P_0c06ad66: /* original 0e5a, guest PC 0x0c06ad66 */
if(!s->budget--) { s->failed_pc=0x0c06ad66u; return 0; }
r[14]=r[53];
goto P_0c06ad68;
P_0c06ad68: /* original 420b, guest PC 0x0c06ad68 */
if(!s->budget--) { s->failed_pc=0x0c06ad68u; return 0; }
target=r[2];
r[16]=code_base|0x0c06ad6cu;
r[0]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ad6cu) { target=s->pc; goto dispatch; }
goto P_0c06ad6c;
P_0c06ad6a: /* original 6053, guest PC 0x0c06ad6a */
if(!s->budget--) { s->failed_pc=0x0c06ad6au; return 0; }
r[0]=r[5];
goto P_0c06ad6c;
P_0c06ad6c: /* original 6c03, guest PC 0x0c06ad6c */
if(!s->budget--) { s->failed_pc=0x0c06ad6cu; return 0; }
r[12]=r[0];
goto P_0c06ad6e;
P_0c06ad6e: /* original e364, guest PC 0x0c06ad6e */
if(!s->budget--) { s->failed_pc=0x0c06ad6eu; return 0; }
r[3]=0x00000064u;
goto P_0c06ad70;
P_0c06ad70: /* original 0c57, guest PC 0x0c06ad70 */
if(!s->budget--) { s->failed_pc=0x0c06ad70u; return 0; }
r[19]=r[12]*r[5];
goto P_0c06ad72;
P_0c06ad72: /* original d21a, guest PC 0x0c06ad72 */
if(!s->budget--) { s->failed_pc=0x0c06ad72u; return 0; }
r[2]=read(ram,0x0c06addcu,4);
goto P_0c06ad74;
P_0c06ad74: /* original 061a, guest PC 0x0c06ad74 */
if(!s->budget--) { s->failed_pc=0x0c06ad74u; return 0; }
r[6]=r[19];
goto P_0c06ad76;
P_0c06ad76: /* original 0e37, guest PC 0x0c06ad76 */
if(!s->budget--) { s->failed_pc=0x0c06ad76u; return 0; }
r[19]=r[14]*r[3];
goto P_0c06ad78;
P_0c06ad78: /* original 3d68, guest PC 0x0c06ad78 */
if(!s->budget--) { s->failed_pc=0x0c06ad78u; return 0; }
r[13]-=r[6];
goto P_0c06ad7a;
P_0c06ad7a: /* original 0e1a, guest PC 0x0c06ad7a */
if(!s->budget--) { s->failed_pc=0x0c06ad7au; return 0; }
r[14]=r[19];
goto P_0c06ad7c;
P_0c06ad7c: /* original 61e3, guest PC 0x0c06ad7c */
if(!s->budget--) { s->failed_pc=0x0c06ad7cu; return 0; }
r[1]=r[14];
goto P_0c06ad7e;
P_0c06ad7e: /* original 420b, guest PC 0x0c06ad7e */
if(!s->budget--) { s->failed_pc=0x0c06ad7eu; return 0; }
target=r[2];
r[16]=code_base|0x0c06ad82u;
r[0]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ad82u) { target=s->pc; goto dispatch; }
goto P_0c06ad82;
P_0c06ad80: /* original 6053, guest PC 0x0c06ad80 */
if(!s->budget--) { s->failed_pc=0x0c06ad80u; return 0; }
r[0]=r[5];
goto P_0c06ad82;
P_0c06ad82: /* original 2f06, guest PC 0x0c06ad82 */
if(!s->budget--) { s->failed_pc=0x0c06ad82u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ad84;
P_0c06ad84: /* original 6e03, guest PC 0x0c06ad84 */
if(!s->budget--) { s->failed_pc=0x0c06ad84u; return 0; }
r[14]=r[0];
goto P_0c06ad86;
P_0c06ad86: /* original 2fd6, guest PC 0x0c06ad86 */
if(!s->budget--) { s->failed_pc=0x0c06ad86u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ad88;
P_0c06ad88: /* original 2fc6, guest PC 0x0c06ad88 */
if(!s->budget--) { s->failed_pc=0x0c06ad88u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ad8a;
P_0c06ad8a: /* original d117, guest PC 0x0c06ad8a */
if(!s->budget--) { s->failed_pc=0x0c06ad8au; return 0; }
r[1]=read(ram,0x0c06ade8u,4);
goto P_0c06ad8c;
P_0c06ad8c: /* original d215, guest PC 0x0c06ad8c */
if(!s->budget--) { s->failed_pc=0x0c06ad8cu; return 0; }
r[2]=read(ram,0x0c06ade4u,4);
goto P_0c06ad8e;
P_0c06ad8e: /* original 420b, guest PC 0x0c06ad8e */
if(!s->budget--) { s->failed_pc=0x0c06ad8eu; return 0; }
target=r[2];
r[16]=code_base|0x0c06ad92u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ad92u) { target=s->pc; goto dispatch; }
goto P_0c06ad92;
P_0c06ad90: /* original 2f16, guest PC 0x0c06ad90 */
if(!s->budget--) { s->failed_pc=0x0c06ad90u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ad92;
P_0c06ad92: /* original 7f10, guest PC 0x0c06ad92 */
if(!s->budget--) { s->failed_pc=0x0c06ad92u; return 0; }
r[15]+=0x00000010u;
goto P_0c06ad94;
P_0c06ad94: /* original 4f16, guest PC 0x0c06ad94 */
if(!s->budget--) { s->failed_pc=0x0c06ad94u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c06ad96;
P_0c06ad96: /* original 4f26, guest PC 0x0c06ad96 */
if(!s->budget--) { s->failed_pc=0x0c06ad96u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06ad98;
P_0c06ad98: /* original 6cf6, guest PC 0x0c06ad98 */
if(!s->budget--) { s->failed_pc=0x0c06ad98u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06ad9a;
P_0c06ad9a: /* original 6df6, guest PC 0x0c06ad9a */
if(!s->budget--) { s->failed_pc=0x0c06ad9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06ad9c;
P_0c06ad9c: /* original 000b, guest PC 0x0c06ad9c */
if(!s->budget--) { s->failed_pc=0x0c06ad9cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06ad9e: /* original 6ef6, guest PC 0x0c06ad9e */
if(!s->budget--) { s->failed_pc=0x0c06ad9eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06ada0;
P_0c06ada0: /* original 2fe6, guest PC 0x0c06ada0 */
if(!s->budget--) { s->failed_pc=0x0c06ada0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ada2;
P_0c06ada2: /* original 2fd6, guest PC 0x0c06ada2 */
if(!s->budget--) { s->failed_pc=0x0c06ada2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ada4;
P_0c06ada4: /* original 2fc6, guest PC 0x0c06ada4 */
if(!s->budget--) { s->failed_pc=0x0c06ada4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ada6;
P_0c06ada6: /* original ec0d, guest PC 0x0c06ada6 */
if(!s->budget--) { s->failed_pc=0x0c06ada6u; return 0; }
r[12]=0x0000000du;
goto P_0c06ada8;
P_0c06ada8: /* original 2fb6, guest PC 0x0c06ada8 */
if(!s->budget--) { s->failed_pc=0x0c06ada8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06adaa;
P_0c06adaa: /* original eb00, guest PC 0x0c06adaa */
if(!s->budget--) { s->failed_pc=0x0c06adaau; return 0; }
r[11]=0x00000000u;
goto P_0c06adac;
P_0c06adac: /* original 2fa6, guest PC 0x0c06adac */
if(!s->budget--) { s->failed_pc=0x0c06adacu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06adae;
P_0c06adae: /* original 2f96, guest PC 0x0c06adae */
if(!s->budget--) { s->failed_pc=0x0c06adaeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06adb0;
P_0c06adb0: /* original 69b3, guest PC 0x0c06adb0 */
if(!s->budget--) { s->failed_pc=0x0c06adb0u; return 0; }
r[9]=r[11];
goto P_0c06adb2;
P_0c06adb2: /* original 2f86, guest PC 0x0c06adb2 */
if(!s->budget--) { s->failed_pc=0x0c06adb2u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06adb4;
P_0c06adb4: /* original fffb, guest PC 0x0c06adb4 */
if(!s->budget--) { s->failed_pc=0x0c06adb4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06adb6;
P_0c06adb6: /* original ffeb, guest PC 0x0c06adb6 */
if(!s->budget--) { s->failed_pc=0x0c06adb6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06adb8;
P_0c06adb8: /* original ffdb, guest PC 0x0c06adb8 */
if(!s->budget--) { s->failed_pc=0x0c06adb8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c06adba;
P_0c06adba: /* original 4f22, guest PC 0x0c06adba */
if(!s->budget--) { s->failed_pc=0x0c06adbau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06adbc;
P_0c06adbc: /* original 9e07, guest PC 0x0c06adbc */
if(!s->budget--) { s->failed_pc=0x0c06adbcu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06adceu,2);
goto P_0c06adbe;
P_0c06adbe: /* original d40b, guest PC 0x0c06adbe */
if(!s->budget--) { s->failed_pc=0x0c06adbeu; return 0; }
r[4]=read(ram,0x0c06adecu,4);
goto P_0c06adc0;
P_0c06adc0: /* original dd0b, guest PC 0x0c06adc0 */
if(!s->budget--) { s->failed_pc=0x0c06adc0u; return 0; }
r[13]=read(ram,0x0c06adf0u,4);
goto P_0c06adc2;
P_0c06adc2: /* original 7ff0, guest PC 0x0c06adc2 */
if(!s->budget--) { s->failed_pc=0x0c06adc2u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c06adc4;
P_0c06adc4: /* original 9a04, guest PC 0x0c06adc4 */
if(!s->budget--) { s->failed_pc=0x0c06adc4u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06add0u,2);
goto P_0c06adc6;
P_0c06adc6: /* original 3e4c, guest PC 0x0c06adc6 */
if(!s->budget--) { s->failed_pc=0x0c06adc6u; return 0; }
r[14]+=r[4];
goto P_0c06adc8;
P_0c06adc8: /* original fe8d, guest PC 0x0c06adc8 */
if(!s->budget--) { s->failed_pc=0x0c06adc8u; return 0; }
fr[14]=0;
goto P_0c06adca;
P_0c06adca: /* original a018, guest PC 0x0c06adca */
if(!s->budget--) { s->failed_pc=0x0c06adcau; return 0; }
r[10]+=r[14];
goto P_0c06adfe;
P_0c06adcc: /* original 3aec, guest PC 0x0c06adcc */
if(!s->budget--) { s->failed_pc=0x0c06adccu; return 0; }
r[10]+=r[14];
if(!vf3_matrix_family(0x0c06adceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06adceu; return 0; } return 1;
P_0c06adf4: /* original 4d0b, guest PC 0x0c06adf4 */
if(!s->budget--) { s->failed_pc=0x0c06adf4u; return 0; }
target=r[13];
r[16]=code_base|0x0c06adf8u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06adf8u) { target=s->pc; goto dispatch; }
goto P_0c06adf8;
P_0c06adf6: /* original 64a3, guest PC 0x0c06adf6 */
if(!s->budget--) { s->failed_pc=0x0c06adf6u; return 0; }
r[4]=r[10];
goto P_0c06adf8;
P_0c06adf8: /* original fe00, guest PC 0x0c06adf8 */
if(!s->budget--) { s->failed_pc=0x0c06adf8u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[0],r[18],'+');
goto P_0c06adfa;
P_0c06adfa: /* original 7a04, guest PC 0x0c06adfa */
if(!s->budget--) { s->failed_pc=0x0c06adfau; return 0; }
r[10]+=0x00000004u;
goto P_0c06adfc;
P_0c06adfc: /* original 7901, guest PC 0x0c06adfc */
if(!s->budget--) { s->failed_pc=0x0c06adfcu; return 0; }
r[9]+=0x00000001u;
goto P_0c06adfe;
P_0c06adfe: /* original 39c3, guest PC 0x0c06adfe */
if(!s->budget--) { s->failed_pc=0x0c06adfeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[12])!=0);
goto P_0c06ae00;
P_0c06ae00: /* original 8bf8, guest PC 0x0c06ae00 */
if(!s->budget--) { s->failed_pc=0x0c06ae00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06adf4; }
goto P_0c06ae02;
P_0c06ae02: /* original f38d, guest PC 0x0c06ae02 */
if(!s->budget--) { s->failed_pc=0x0c06ae02u; return 0; }
fr[3]=0;
goto P_0c06ae04;
P_0c06ae04: /* original f3e4, guest PC 0x0c06ae04 */
if(!s->budget--) { s->failed_pc=0x0c06ae04u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])==as_float(fr[14]))!=0);
goto P_0c06ae06;
P_0c06ae06: /* original d939, guest PC 0x0c06ae06 */
if(!s->budget--) { s->failed_pc=0x0c06ae06u; return 0; }
r[9]=read(ram,0x0c06aeecu,4);
goto P_0c06ae08;
P_0c06ae08: /* original c739, guest PC 0x0c06ae08 */
if(!s->budget--) { s->failed_pc=0x0c06ae08u; return 0; }
r[0]=code_base|0x0006aef0u;
goto P_0c06ae0a;
P_0c06ae0a: /* original 8d12, guest PC 0x0c06ae0a */
if(!s->budget--) { s->failed_pc=0x0c06ae0au; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,15,r[0]);
if(cond) { goto P_0c06ae32; }
goto P_0c06ae0e;
P_0c06ae0c: /* original ff08, guest PC 0x0c06ae0c */
if(!s->budget--) { s->failed_pc=0x0c06ae0cu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c06ae0e;
P_0c06ae0e: /* original fef3, guest PC 0x0c06ae0e */
if(!s->budget--) { s->failed_pc=0x0c06ae0eu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'/');
goto P_0c06ae10;
P_0c06ae10: /* original 68b3, guest PC 0x0c06ae10 */
if(!s->budget--) { s->failed_pc=0x0c06ae10u; return 0; }
r[8]=r[11];
goto P_0c06ae12;
P_0c06ae12: /* original a00c, guest PC 0x0c06ae12 */
if(!s->budget--) { s->failed_pc=0x0c06ae12u; return 0; }
r[10]=r[11];
goto P_0c06ae2e;
P_0c06ae14: /* original 6ab3, guest PC 0x0c06ae14 */
if(!s->budget--) { s->failed_pc=0x0c06ae14u; return 0; }
r[10]=r[11];
goto P_0c06ae16;
P_0c06ae16: /* original 9462, guest PC 0x0c06ae16 */
if(!s->budget--) { s->failed_pc=0x0c06ae16u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aedeu,2);
goto P_0c06ae18;
P_0c06ae18: /* original 34ec, guest PC 0x0c06ae18 */
if(!s->budget--) { s->failed_pc=0x0c06ae18u; return 0; }
r[4]+=r[14];
goto P_0c06ae1a;
P_0c06ae1a: /* original 4d0b, guest PC 0x0c06ae1a */
if(!s->budget--) { s->failed_pc=0x0c06ae1au; return 0; }
target=r[13];
r[16]=code_base|0x0c06ae1eu;
r[4]+=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ae1eu) { target=s->pc; goto dispatch; }
goto P_0c06ae1e;
P_0c06ae1c: /* original 34ac, guest PC 0x0c06ae1c */
if(!s->budget--) { s->failed_pc=0x0c06ae1cu; return 0; }
r[4]+=r[10];
goto P_0c06ae1e;
P_0c06ae1e: /* original f40c, guest PC 0x0c06ae1e */
if(!s->budget--) { s->failed_pc=0x0c06ae1eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c06ae20;
P_0c06ae20: /* original f4e3, guest PC 0x0c06ae20 */
if(!s->budget--) { s->failed_pc=0x0c06ae20u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'/');
goto P_0c06ae22;
P_0c06ae22: /* original 945d, guest PC 0x0c06ae22 */
if(!s->budget--) { s->failed_pc=0x0c06ae22u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aee0u,2);
goto P_0c06ae24;
P_0c06ae24: /* original 34ec, guest PC 0x0c06ae24 */
if(!s->budget--) { s->failed_pc=0x0c06ae24u; return 0; }
r[4]+=r[14];
goto P_0c06ae26;
P_0c06ae26: /* original 490b, guest PC 0x0c06ae26 */
if(!s->budget--) { s->failed_pc=0x0c06ae26u; return 0; }
target=r[9];
r[16]=code_base|0x0c06ae2au;
r[4]+=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ae2au) { target=s->pc; goto dispatch; }
goto P_0c06ae2a;
P_0c06ae28: /* original 34ac, guest PC 0x0c06ae28 */
if(!s->budget--) { s->failed_pc=0x0c06ae28u; return 0; }
r[4]+=r[10];
goto P_0c06ae2a;
P_0c06ae2a: /* original 7a04, guest PC 0x0c06ae2a */
if(!s->budget--) { s->failed_pc=0x0c06ae2au; return 0; }
r[10]+=0x00000004u;
goto P_0c06ae2c;
P_0c06ae2c: /* original 7801, guest PC 0x0c06ae2c */
if(!s->budget--) { s->failed_pc=0x0c06ae2cu; return 0; }
r[8]+=0x00000001u;
goto P_0c06ae2e;
P_0c06ae2e: /* original 38c3, guest PC 0x0c06ae2e */
if(!s->budget--) { s->failed_pc=0x0c06ae2eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[12])!=0);
goto P_0c06ae30;
P_0c06ae30: /* original 8bf1, guest PC 0x0c06ae30 */
if(!s->budget--) { s->failed_pc=0x0c06ae30u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ae16; }
goto P_0c06ae32;
P_0c06ae32: /* original 1fb2, guest PC 0x0c06ae32 */
if(!s->budget--) { s->failed_pc=0x0c06ae32u; return 0; }
write(ram,r[15]+8,r[11],4);
goto P_0c06ae34;
P_0c06ae34: /* original a02a, guest PC 0x0c06ae34 */
if(!s->budget--) { s->failed_pc=0x0c06ae34u; return 0; }
write(ram,r[15]+4,r[11],4);
goto P_0c06ae8c;
P_0c06ae36: /* original 1fb1, guest PC 0x0c06ae36 */
if(!s->budget--) { s->failed_pc=0x0c06ae36u; return 0; }
write(ram,r[15]+4,r[11],4);
goto P_0c06ae38;
P_0c06ae38: /* original 55f1, guest PC 0x0c06ae38 */
if(!s->budget--) { s->failed_pc=0x0c06ae38u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c06ae3a;
P_0c06ae3a: /* original 68e3, guest PC 0x0c06ae3a */
if(!s->budget--) { s->failed_pc=0x0c06ae3au; return 0; }
r[8]=r[14];
goto P_0c06ae3c;
P_0c06ae3c: /* original 2fb2, guest PC 0x0c06ae3c */
if(!s->budget--) { s->failed_pc=0x0c06ae3cu; return 0; }
write(ram,r[15],r[11],4);
goto P_0c06ae3e;
P_0c06ae3e: /* original 6453, guest PC 0x0c06ae3e */
if(!s->budget--) { s->failed_pc=0x0c06ae3eu; return 0; }
r[4]=r[5];
goto P_0c06ae40;
P_0c06ae40: /* original 4408, guest PC 0x0c06ae40 */
if(!s->budget--) { s->failed_pc=0x0c06ae40u; return 0; }
r[4]<<=2;
goto P_0c06ae42;
P_0c06ae42: /* original 384c, guest PC 0x0c06ae42 */
if(!s->budget--) { s->failed_pc=0x0c06ae42u; return 0; }
r[8]+=r[4];
goto P_0c06ae44;
P_0c06ae44: /* original a019, guest PC 0x0c06ae44 */
if(!s->budget--) { s->failed_pc=0x0c06ae44u; return 0; }
r[10]=r[4];
goto P_0c06ae7a;
P_0c06ae46: /* original 6a43, guest PC 0x0c06ae46 */
if(!s->budget--) { s->failed_pc=0x0c06ae46u; return 0; }
r[10]=r[4];
goto P_0c06ae48;
P_0c06ae48: /* original 944b, guest PC 0x0c06ae48 */
if(!s->budget--) { s->failed_pc=0x0c06ae48u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aee2u,2);
goto P_0c06ae4a;
P_0c06ae4a: /* original 34ec, guest PC 0x0c06ae4a */
if(!s->budget--) { s->failed_pc=0x0c06ae4au; return 0; }
r[4]+=r[14];
goto P_0c06ae4c;
P_0c06ae4c: /* original 4d0b, guest PC 0x0c06ae4c */
if(!s->budget--) { s->failed_pc=0x0c06ae4cu; return 0; }
target=r[13];
r[16]=code_base|0x0c06ae50u;
r[4]+=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ae50u) { target=s->pc; goto dispatch; }
goto P_0c06ae50;
P_0c06ae4e: /* original 34ac, guest PC 0x0c06ae4e */
if(!s->budget--) { s->failed_pc=0x0c06ae4eu; return 0; }
r[4]+=r[10];
goto P_0c06ae50;
P_0c06ae50: /* original 9448, guest PC 0x0c06ae50 */
if(!s->budget--) { s->failed_pc=0x0c06ae50u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aee4u,2);
goto P_0c06ae52;
P_0c06ae52: /* original fe0c, guest PC 0x0c06ae52 */
if(!s->budget--) { s->failed_pc=0x0c06ae52u; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c06ae54;
P_0c06ae54: /* original 34ec, guest PC 0x0c06ae54 */
if(!s->budget--) { s->failed_pc=0x0c06ae54u; return 0; }
r[4]+=r[14];
goto P_0c06ae56;
P_0c06ae56: /* original 4d0b, guest PC 0x0c06ae56 */
if(!s->budget--) { s->failed_pc=0x0c06ae56u; return 0; }
target=r[13];
r[16]=code_base|0x0c06ae5au;
r[4]+=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ae5au) { target=s->pc; goto dispatch; }
goto P_0c06ae5a;
P_0c06ae58: /* original 34ac, guest PC 0x0c06ae58 */
if(!s->budget--) { s->failed_pc=0x0c06ae58u; return 0; }
r[4]+=r[10];
goto P_0c06ae5a;
P_0c06ae5a: /* original f38d, guest PC 0x0c06ae5a */
if(!s->budget--) { s->failed_pc=0x0c06ae5au; return 0; }
fr[3]=0;
goto P_0c06ae5c;
P_0c06ae5c: /* original f40c, guest PC 0x0c06ae5c */
if(!s->budget--) { s->failed_pc=0x0c06ae5cu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c06ae5e;
P_0c06ae5e: /* original f344, guest PC 0x0c06ae5e */
if(!s->budget--) { s->failed_pc=0x0c06ae5eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])==as_float(fr[4]))!=0);
goto P_0c06ae60;
P_0c06ae60: /* original 8d04, guest PC 0x0c06ae60 */
if(!s->budget--) { s->failed_pc=0x0c06ae60u; return 0; }
cond=r[17]&1u;
r[4]=r[8];
if(cond) { goto P_0c06ae6c; }
goto P_0c06ae64;
P_0c06ae62: /* original 6483, guest PC 0x0c06ae62 */
if(!s->budget--) { s->failed_pc=0x0c06ae62u; return 0; }
r[4]=r[8];
goto P_0c06ae64;
P_0c06ae64: /* original fef2, guest PC 0x0c06ae64 */
if(!s->budget--) { s->failed_pc=0x0c06ae64u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'*');
goto P_0c06ae66;
P_0c06ae66: /* original f24c, guest PC 0x0c06ae66 */
if(!s->budget--) { s->failed_pc=0x0c06ae66u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c06ae68;
P_0c06ae68: /* original f4ec, guest PC 0x0c06ae68 */
if(!s->budget--) { s->failed_pc=0x0c06ae68u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06ae6a;
P_0c06ae6a: /* original f423, guest PC 0x0c06ae6a */
if(!s->budget--) { s->failed_pc=0x0c06ae6au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'/');
goto P_0c06ae6c;
P_0c06ae6c: /* original 490b, guest PC 0x0c06ae6c */
if(!s->budget--) { s->failed_pc=0x0c06ae6cu; return 0; }
target=r[9];
r[16]=code_base|0x0c06ae70u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ae70u) { target=s->pc; goto dispatch; }
goto P_0c06ae70;
P_0c06ae6e: /* original 0009, guest PC 0x0c06ae6e */
if(!s->budget--) { s->failed_pc=0x0c06ae6eu; return 0; }
goto P_0c06ae70;
P_0c06ae70: /* original 63f2, guest PC 0x0c06ae70 */
if(!s->budget--) { s->failed_pc=0x0c06ae70u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06ae72;
P_0c06ae72: /* original 7a04, guest PC 0x0c06ae72 */
if(!s->budget--) { s->failed_pc=0x0c06ae72u; return 0; }
r[10]+=0x00000004u;
goto P_0c06ae74;
P_0c06ae74: /* original 7804, guest PC 0x0c06ae74 */
if(!s->budget--) { s->failed_pc=0x0c06ae74u; return 0; }
r[8]+=0x00000004u;
goto P_0c06ae76;
P_0c06ae76: /* original 7301, guest PC 0x0c06ae76 */
if(!s->budget--) { s->failed_pc=0x0c06ae76u; return 0; }
r[3]+=0x00000001u;
goto P_0c06ae78;
P_0c06ae78: /* original 2f32, guest PC 0x0c06ae78 */
if(!s->budget--) { s->failed_pc=0x0c06ae78u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06ae7a;
P_0c06ae7a: /* original 63f2, guest PC 0x0c06ae7a */
if(!s->budget--) { s->failed_pc=0x0c06ae7au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06ae7c;
P_0c06ae7c: /* original 33c3, guest PC 0x0c06ae7c */
if(!s->budget--) { s->failed_pc=0x0c06ae7cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[12])!=0);
goto P_0c06ae7e;
P_0c06ae7e: /* original 8be3, guest PC 0x0c06ae7e */
if(!s->budget--) { s->failed_pc=0x0c06ae7eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ae48; }
goto P_0c06ae80;
P_0c06ae80: /* original 51f2, guest PC 0x0c06ae80 */
if(!s->budget--) { s->failed_pc=0x0c06ae80u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c06ae82;
P_0c06ae82: /* original 7101, guest PC 0x0c06ae82 */
if(!s->budget--) { s->failed_pc=0x0c06ae82u; return 0; }
r[1]+=0x00000001u;
goto P_0c06ae84;
P_0c06ae84: /* original 1f12, guest PC 0x0c06ae84 */
if(!s->budget--) { s->failed_pc=0x0c06ae84u; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c06ae86;
P_0c06ae86: /* original 53f1, guest PC 0x0c06ae86 */
if(!s->budget--) { s->failed_pc=0x0c06ae86u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06ae88;
P_0c06ae88: /* original 730d, guest PC 0x0c06ae88 */
if(!s->budget--) { s->failed_pc=0x0c06ae88u; return 0; }
r[3]+=0x0000000du;
goto P_0c06ae8a;
P_0c06ae8a: /* original 1f31, guest PC 0x0c06ae8a */
if(!s->budget--) { s->failed_pc=0x0c06ae8au; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c06ae8c;
P_0c06ae8c: /* original 52f2, guest PC 0x0c06ae8c */
if(!s->budget--) { s->failed_pc=0x0c06ae8cu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c06ae8e;
P_0c06ae8e: /* original 32c3, guest PC 0x0c06ae8e */
if(!s->budget--) { s->failed_pc=0x0c06ae8eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[12])!=0);
goto P_0c06ae90;
P_0c06ae90: /* original 8bd2, guest PC 0x0c06ae90 */
if(!s->budget--) { s->failed_pc=0x0c06ae90u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ae38; }
goto P_0c06ae92;
P_0c06ae92: /* original 2fb2, guest PC 0x0c06ae92 */
if(!s->budget--) { s->failed_pc=0x0c06ae92u; return 0; }
write(ram,r[15],r[11],4);
goto P_0c06ae94;
P_0c06ae94: /* original 9827, guest PC 0x0c06ae94 */
if(!s->budget--) { s->failed_pc=0x0c06ae94u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aee6u,2);
goto P_0c06ae96;
P_0c06ae96: /* original 38ec, guest PC 0x0c06ae96 */
if(!s->budget--) { s->failed_pc=0x0c06ae96u; return 0; }
r[8]+=r[14];
goto P_0c06ae98;
P_0c06ae98: /* original a019, guest PC 0x0c06ae98 */
if(!s->budget--) { s->failed_pc=0x0c06ae98u; return 0; }
r[10]=0x00000000u;
goto P_0c06aece;
P_0c06ae9a: /* original ea00, guest PC 0x0c06ae9a */
if(!s->budget--) { s->failed_pc=0x0c06ae9au; return 0; }
r[10]=0x00000000u;
goto P_0c06ae9c;
P_0c06ae9c: /* original 9424, guest PC 0x0c06ae9c */
if(!s->budget--) { s->failed_pc=0x0c06ae9cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aee8u,2);
goto P_0c06ae9e;
P_0c06ae9e: /* original 34ec, guest PC 0x0c06ae9e */
if(!s->budget--) { s->failed_pc=0x0c06ae9eu; return 0; }
r[4]+=r[14];
goto P_0c06aea0;
P_0c06aea0: /* original 4d0b, guest PC 0x0c06aea0 */
if(!s->budget--) { s->failed_pc=0x0c06aea0u; return 0; }
target=r[13];
r[16]=code_base|0x0c06aea4u;
r[4]+=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06aea4u) { target=s->pc; goto dispatch; }
goto P_0c06aea4;
P_0c06aea2: /* original 34ac, guest PC 0x0c06aea2 */
if(!s->budget--) { s->failed_pc=0x0c06aea2u; return 0; }
r[4]+=r[10];
goto P_0c06aea4;
P_0c06aea4: /* original 9421, guest PC 0x0c06aea4 */
if(!s->budget--) { s->failed_pc=0x0c06aea4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aeeau,2);
goto P_0c06aea6;
P_0c06aea6: /* original fe0c, guest PC 0x0c06aea6 */
if(!s->budget--) { s->failed_pc=0x0c06aea6u; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c06aea8;
P_0c06aea8: /* original 34ec, guest PC 0x0c06aea8 */
if(!s->budget--) { s->failed_pc=0x0c06aea8u; return 0; }
r[4]+=r[14];
goto P_0c06aeaa;
P_0c06aeaa: /* original 4d0b, guest PC 0x0c06aeaa */
if(!s->budget--) { s->failed_pc=0x0c06aeaau; return 0; }
target=r[13];
r[16]=code_base|0x0c06aeaeu;
r[4]+=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06aeaeu) { target=s->pc; goto dispatch; }
goto P_0c06aeae;
P_0c06aeac: /* original 34ac, guest PC 0x0c06aeac */
if(!s->budget--) { s->failed_pc=0x0c06aeacu; return 0; }
r[4]+=r[10];
goto P_0c06aeae;
P_0c06aeae: /* original f38d, guest PC 0x0c06aeae */
if(!s->budget--) { s->failed_pc=0x0c06aeaeu; return 0; }
fr[3]=0;
goto P_0c06aeb0;
P_0c06aeb0: /* original f40c, guest PC 0x0c06aeb0 */
if(!s->budget--) { s->failed_pc=0x0c06aeb0u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c06aeb2;
P_0c06aeb2: /* original f344, guest PC 0x0c06aeb2 */
if(!s->budget--) { s->failed_pc=0x0c06aeb2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])==as_float(fr[4]))!=0);
goto P_0c06aeb4;
P_0c06aeb4: /* original 8d04, guest PC 0x0c06aeb4 */
if(!s->budget--) { s->failed_pc=0x0c06aeb4u; return 0; }
cond=r[17]&1u;
r[4]=r[8];
if(cond) { goto P_0c06aec0; }
goto P_0c06aeb8;
P_0c06aeb6: /* original 6483, guest PC 0x0c06aeb6 */
if(!s->budget--) { s->failed_pc=0x0c06aeb6u; return 0; }
r[4]=r[8];
goto P_0c06aeb8;
P_0c06aeb8: /* original f24c, guest PC 0x0c06aeb8 */
if(!s->budget--) { s->failed_pc=0x0c06aeb8u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c06aeba;
P_0c06aeba: /* original f4ec, guest PC 0x0c06aeba */
if(!s->budget--) { s->failed_pc=0x0c06aebau; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06aebc;
P_0c06aebc: /* original f423, guest PC 0x0c06aebc */
if(!s->budget--) { s->failed_pc=0x0c06aebcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'/');
goto P_0c06aebe;
P_0c06aebe: /* original f4f2, guest PC 0x0c06aebe */
if(!s->budget--) { s->failed_pc=0x0c06aebeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c06aec0;
P_0c06aec0: /* original 490b, guest PC 0x0c06aec0 */
if(!s->budget--) { s->failed_pc=0x0c06aec0u; return 0; }
target=r[9];
r[16]=code_base|0x0c06aec4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06aec4u) { target=s->pc; goto dispatch; }
goto P_0c06aec4;
P_0c06aec2: /* original 0009, guest PC 0x0c06aec2 */
if(!s->budget--) { s->failed_pc=0x0c06aec2u; return 0; }
goto P_0c06aec4;
P_0c06aec4: /* original 63f2, guest PC 0x0c06aec4 */
if(!s->budget--) { s->failed_pc=0x0c06aec4u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06aec6;
P_0c06aec6: /* original 7a04, guest PC 0x0c06aec6 */
if(!s->budget--) { s->failed_pc=0x0c06aec6u; return 0; }
r[10]+=0x00000004u;
goto P_0c06aec8;
P_0c06aec8: /* original 7804, guest PC 0x0c06aec8 */
if(!s->budget--) { s->failed_pc=0x0c06aec8u; return 0; }
r[8]+=0x00000004u;
goto P_0c06aeca;
P_0c06aeca: /* original 7301, guest PC 0x0c06aeca */
if(!s->budget--) { s->failed_pc=0x0c06aecau; return 0; }
r[3]+=0x00000001u;
goto P_0c06aecc;
P_0c06aecc: /* original 2f32, guest PC 0x0c06aecc */
if(!s->budget--) { s->failed_pc=0x0c06aeccu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06aece;
P_0c06aece: /* original 63f2, guest PC 0x0c06aece */
if(!s->budget--) { s->failed_pc=0x0c06aeceu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06aed0;
P_0c06aed0: /* original 33c3, guest PC 0x0c06aed0 */
if(!s->budget--) { s->failed_pc=0x0c06aed0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[12])!=0);
goto P_0c06aed2;
P_0c06aed2: /* original 8be3, guest PC 0x0c06aed2 */
if(!s->budget--) { s->failed_pc=0x0c06aed2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ae9c; }
goto P_0c06aed4;
P_0c06aed4: /* original 2fb0, guest PC 0x0c06aed4 */
if(!s->budget--) { s->failed_pc=0x0c06aed4u; return 0; }
write(ram,r[15],r[11],1);
goto P_0c06aed6;
P_0c06aed6: /* original da08, guest PC 0x0c06aed6 */
if(!s->budget--) { s->failed_pc=0x0c06aed6u; return 0; }
r[10]=read(ram,0x0c06aef8u,4);
goto P_0c06aed8;
P_0c06aed8: /* original d906, guest PC 0x0c06aed8 */
if(!s->budget--) { s->failed_pc=0x0c06aed8u; return 0; }
r[9]=read(ram,0x0c06aef4u,4);
goto P_0c06aeda;
P_0c06aeda: /* original a026, guest PC 0x0c06aeda */
if(!s->budget--) { s->failed_pc=0x0c06aedau; return 0; }
r[8]=r[11];
goto P_0c06af2a;
P_0c06aedc: /* original 68b3, guest PC 0x0c06aedc */
if(!s->budget--) { s->failed_pc=0x0c06aedcu; return 0; }
r[8]=r[11];
if(!vf3_matrix_family(0x0c06aedeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06aedeu; return 0; } return 1;
P_0c06aefc: /* original 6483, guest PC 0x0c06aefc */
if(!s->budget--) { s->failed_pc=0x0c06aefcu; return 0; }
r[4]=r[8];
goto P_0c06aefe;
P_0c06aefe: /* original 4408, guest PC 0x0c06aefe */
if(!s->budget--) { s->failed_pc=0x0c06aefeu; return 0; }
r[4]<<=2;
goto P_0c06af00;
P_0c06af00: /* original 1f41, guest PC 0x0c06af00 */
if(!s->budget--) { s->failed_pc=0x0c06af00u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c06af02;
P_0c06af02: /* original 9373, guest PC 0x0c06af02 */
if(!s->budget--) { s->failed_pc=0x0c06af02u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06afecu,2);
goto P_0c06af04;
P_0c06af04: /* original 33ec, guest PC 0x0c06af04 */
if(!s->budget--) { s->failed_pc=0x0c06af04u; return 0; }
r[3]+=r[14];
goto P_0c06af06;
P_0c06af06: /* original 4d0b, guest PC 0x0c06af06 */
if(!s->budget--) { s->failed_pc=0x0c06af06u; return 0; }
target=r[13];
r[16]=code_base|0x0c06af0au;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06af0au) { target=s->pc; goto dispatch; }
goto P_0c06af0a;
P_0c06af08: /* original 343c, guest PC 0x0c06af08 */
if(!s->budget--) { s->failed_pc=0x0c06af08u; return 0; }
r[4]+=r[3];
goto P_0c06af0a;
P_0c06af0a: /* original 9270, guest PC 0x0c06af0a */
if(!s->budget--) { s->failed_pc=0x0c06af0au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06afeeu,2);
goto P_0c06af0c;
P_0c06af0c: /* original 53f1, guest PC 0x0c06af0c */
if(!s->budget--) { s->failed_pc=0x0c06af0cu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06af0e;
P_0c06af0e: /* original 32ac, guest PC 0x0c06af0e */
if(!s->budget--) { s->failed_pc=0x0c06af0eu; return 0; }
r[2]+=r[10];
goto P_0c06af10;
P_0c06af10: /* original f40c, guest PC 0x0c06af10 */
if(!s->budget--) { s->failed_pc=0x0c06af10u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c06af12;
P_0c06af12: /* original 323c, guest PC 0x0c06af12 */
if(!s->budget--) { s->failed_pc=0x0c06af12u; return 0; }
r[2]+=r[3];
goto P_0c06af14;
P_0c06af14: /* original f24a, guest PC 0x0c06af14 */
if(!s->budget--) { s->failed_pc=0x0c06af14u; return 0; }
vf3_matrix_store(s,ram,4,r[2]);
goto P_0c06af16;
P_0c06af16: /* original 936b, guest PC 0x0c06af16 */
if(!s->budget--) { s->failed_pc=0x0c06af16u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aff0u,2);
goto P_0c06af18;
P_0c06af18: /* original 64f0, guest PC 0x0c06af18 */
if(!s->budget--) { s->failed_pc=0x0c06af18u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[4]=tmp;
goto P_0c06af1a;
P_0c06af1a: /* original 65f0, guest PC 0x0c06af1a */
if(!s->budget--) { s->failed_pc=0x0c06af1au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[5]=tmp;
goto P_0c06af1c;
P_0c06af1c: /* original 33ec, guest PC 0x0c06af1c */
if(!s->budget--) { s->failed_pc=0x0c06af1cu; return 0; }
r[3]+=r[14];
goto P_0c06af1e;
P_0c06af1e: /* original 490b, guest PC 0x0c06af1e */
if(!s->budget--) { s->failed_pc=0x0c06af1eu; return 0; }
target=r[9];
r[16]=code_base|0x0c06af22u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06af22u) { target=s->pc; goto dispatch; }
goto P_0c06af22;
P_0c06af20: /* original 343c, guest PC 0x0c06af20 */
if(!s->budget--) { s->failed_pc=0x0c06af20u; return 0; }
r[4]+=r[3];
goto P_0c06af22;
P_0c06af22: /* original 62f0, guest PC 0x0c06af22 */
if(!s->budget--) { s->failed_pc=0x0c06af22u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[2]=tmp;
goto P_0c06af24;
P_0c06af24: /* original 7801, guest PC 0x0c06af24 */
if(!s->budget--) { s->failed_pc=0x0c06af24u; return 0; }
r[8]+=0x00000001u;
goto P_0c06af26;
P_0c06af26: /* original 7201, guest PC 0x0c06af26 */
if(!s->budget--) { s->failed_pc=0x0c06af26u; return 0; }
r[2]+=0x00000001u;
goto P_0c06af28;
P_0c06af28: /* original 2f20, guest PC 0x0c06af28 */
if(!s->budget--) { s->failed_pc=0x0c06af28u; return 0; }
write(ram,r[15],r[2],1);
goto P_0c06af2a;
P_0c06af2a: /* original 38c3, guest PC 0x0c06af2a */
if(!s->budget--) { s->failed_pc=0x0c06af2au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[12])!=0);
goto P_0c06af2c;
P_0c06af2c: /* original 8be6, guest PC 0x0c06af2c */
if(!s->budget--) { s->failed_pc=0x0c06af2cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06aefc; }
goto P_0c06af2e;
P_0c06af2e: /* original e401, guest PC 0x0c06af2e */
if(!s->budget--) { s->failed_pc=0x0c06af2eu; return 0; }
r[4]=0x00000001u;
goto P_0c06af30;
P_0c06af30: /* original 6043, guest PC 0x0c06af30 */
if(!s->budget--) { s->failed_pc=0x0c06af30u; return 0; }
r[0]=r[4];
goto P_0c06af32;
P_0c06af32: /* original 80f4, guest PC 0x0c06af32 */
if(!s->budget--) { s->failed_pc=0x0c06af32u; return 0; }
write(ram,r[15]+4,r[0],1);
goto P_0c06af34;
P_0c06af34: /* original a047, guest PC 0x0c06af34 */
if(!s->budget--) { s->failed_pc=0x0c06af34u; return 0; }
r[12]=r[11];
goto P_0c06afc6;
P_0c06af36: /* original 6cb3, guest PC 0x0c06af36 */
if(!s->budget--) { s->failed_pc=0x0c06af36u; return 0; }
r[12]=r[11];
goto P_0c06af38;
P_0c06af38: /* original 9459, guest PC 0x0c06af38 */
if(!s->budget--) { s->failed_pc=0x0c06af38u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06afeeu,2);
goto P_0c06af3a;
P_0c06af3a: /* original 60c3, guest PC 0x0c06af3a */
if(!s->budget--) { s->failed_pc=0x0c06af3au; return 0; }
r[0]=r[12];
goto P_0c06af3c;
P_0c06af3c: /* original 4008, guest PC 0x0c06af3c */
if(!s->budget--) { s->failed_pc=0x0c06af3cu; return 0; }
r[0]<<=2;
goto P_0c06af3e;
P_0c06af3e: /* original 34ac, guest PC 0x0c06af3e */
if(!s->budget--) { s->failed_pc=0x0c06af3eu; return 0; }
r[4]+=r[10];
goto P_0c06af40;
P_0c06af40: /* original 1f02, guest PC 0x0c06af40 */
if(!s->budget--) { s->failed_pc=0x0c06af40u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c06af42;
P_0c06af42: /* original ff46, guest PC 0x0c06af42 */
if(!s->budget--) { s->failed_pc=0x0c06af42u; return 0; }
vf3_matrix_load(s,ram,15,r[4]+r[0]);
goto P_0c06af44;
P_0c06af44: /* original 60c3, guest PC 0x0c06af44 */
if(!s->budget--) { s->failed_pc=0x0c06af44u; return 0; }
r[0]=r[12];
goto P_0c06af46;
P_0c06af46: /* original 7001, guest PC 0x0c06af46 */
if(!s->budget--) { s->failed_pc=0x0c06af46u; return 0; }
r[0]+=0x00000001u;
goto P_0c06af48;
P_0c06af48: /* original 4008, guest PC 0x0c06af48 */
if(!s->budget--) { s->failed_pc=0x0c06af48u; return 0; }
r[0]<<=2;
goto P_0c06af4a;
P_0c06af4a: /* original 1f03, guest PC 0x0c06af4a */
if(!s->budget--) { s->failed_pc=0x0c06af4au; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c06af4c;
P_0c06af4c: /* original fe46, guest PC 0x0c06af4c */
if(!s->budget--) { s->failed_pc=0x0c06af4cu; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c06af4e;
P_0c06af4e: /* original 944f, guest PC 0x0c06af4e */
if(!s->budget--) { s->failed_pc=0x0c06af4eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aff0u,2);
goto P_0c06af50;
P_0c06af50: /* original d328, guest PC 0x0c06af50 */
if(!s->budget--) { s->failed_pc=0x0c06af50u; return 0; }
r[3]=read(ram,0x0c06aff4u,4);
goto P_0c06af52;
P_0c06af52: /* original 34ec, guest PC 0x0c06af52 */
if(!s->budget--) { s->failed_pc=0x0c06af52u; return 0; }
r[4]+=r[14];
goto P_0c06af54;
P_0c06af54: /* original 430b, guest PC 0x0c06af54 */
if(!s->budget--) { s->failed_pc=0x0c06af54u; return 0; }
target=r[3];
r[16]=code_base|0x0c06af58u;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06af58u) { target=s->pc; goto dispatch; }
goto P_0c06af58;
P_0c06af56: /* original 34cc, guest PC 0x0c06af56 */
if(!s->budget--) { s->failed_pc=0x0c06af56u; return 0; }
r[4]+=r[12];
goto P_0c06af58;
P_0c06af58: /* original 934a, guest PC 0x0c06af58 */
if(!s->budget--) { s->failed_pc=0x0c06af58u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aff0u,2);
goto P_0c06af5a;
P_0c06af5a: /* original 64c3, guest PC 0x0c06af5a */
if(!s->budget--) { s->failed_pc=0x0c06af5au; return 0; }
r[4]=r[12];
goto P_0c06af5c;
P_0c06af5c: /* original d225, guest PC 0x0c06af5c */
if(!s->budget--) { s->failed_pc=0x0c06af5cu; return 0; }
r[2]=read(ram,0x0c06aff4u,4);
goto P_0c06af5e;
P_0c06af5e: /* original 680c, guest PC 0x0c06af5e */
if(!s->budget--) { s->failed_pc=0x0c06af5eu; return 0; }
r[8]=r[0]&255u;
goto P_0c06af60;
P_0c06af60: /* original 33ec, guest PC 0x0c06af60 */
if(!s->budget--) { s->failed_pc=0x0c06af60u; return 0; }
r[3]+=r[14];
goto P_0c06af62;
P_0c06af62: /* original 7401, guest PC 0x0c06af62 */
if(!s->budget--) { s->failed_pc=0x0c06af62u; return 0; }
r[4]+=0x00000001u;
goto P_0c06af64;
P_0c06af64: /* original 420b, guest PC 0x0c06af64 */
if(!s->budget--) { s->failed_pc=0x0c06af64u; return 0; }
target=r[2];
r[16]=code_base|0x0c06af68u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06af68u) { target=s->pc; goto dispatch; }
goto P_0c06af68;
P_0c06af66: /* original 343c, guest PC 0x0c06af66 */
if(!s->budget--) { s->failed_pc=0x0c06af66u; return 0; }
r[4]+=r[3];
goto P_0c06af68;
P_0c06af68: /* original 6483, guest PC 0x0c06af68 */
if(!s->budget--) { s->failed_pc=0x0c06af68u; return 0; }
r[4]=r[8];
goto P_0c06af6a;
P_0c06af6a: /* original 600c, guest PC 0x0c06af6a */
if(!s->budget--) { s->failed_pc=0x0c06af6au; return 0; }
r[0]=r[0]&255u;
goto P_0c06af6c;
P_0c06af6c: /* original 2f02, guest PC 0x0c06af6c */
if(!s->budget--) { s->failed_pc=0x0c06af6cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06af6e;
P_0c06af6e: /* original 4408, guest PC 0x0c06af6e */
if(!s->budget--) { s->failed_pc=0x0c06af6eu; return 0; }
r[4]<<=2;
goto P_0c06af70;
P_0c06af70: /* original 933f, guest PC 0x0c06af70 */
if(!s->budget--) { s->failed_pc=0x0c06af70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aff2u,2);
goto P_0c06af72;
P_0c06af72: /* original 33ec, guest PC 0x0c06af72 */
if(!s->budget--) { s->failed_pc=0x0c06af72u; return 0; }
r[3]+=r[14];
goto P_0c06af74;
P_0c06af74: /* original 4d0b, guest PC 0x0c06af74 */
if(!s->budget--) { s->failed_pc=0x0c06af74u; return 0; }
target=r[13];
r[16]=code_base|0x0c06af78u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06af78u) { target=s->pc; goto dispatch; }
goto P_0c06af78;
P_0c06af76: /* original 343c, guest PC 0x0c06af76 */
if(!s->budget--) { s->failed_pc=0x0c06af76u; return 0; }
r[4]+=r[3];
goto P_0c06af78;
P_0c06af78: /* original 933b, guest PC 0x0c06af78 */
if(!s->budget--) { s->failed_pc=0x0c06af78u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aff2u,2);
goto P_0c06af7a;
P_0c06af7a: /* original 64f2, guest PC 0x0c06af7a */
if(!s->budget--) { s->failed_pc=0x0c06af7au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06af7c;
P_0c06af7c: /* original 33ec, guest PC 0x0c06af7c */
if(!s->budget--) { s->failed_pc=0x0c06af7cu; return 0; }
r[3]+=r[14];
goto P_0c06af7e;
P_0c06af7e: /* original fd0c, guest PC 0x0c06af7e */
if(!s->budget--) { s->failed_pc=0x0c06af7eu; return 0; }
vf3_matrix_move(s,13,0);
goto P_0c06af80;
P_0c06af80: /* original 4408, guest PC 0x0c06af80 */
if(!s->budget--) { s->failed_pc=0x0c06af80u; return 0; }
r[4]<<=2;
goto P_0c06af82;
P_0c06af82: /* original 4d0b, guest PC 0x0c06af82 */
if(!s->budget--) { s->failed_pc=0x0c06af82u; return 0; }
target=r[13];
r[16]=code_base|0x0c06af86u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06af86u) { target=s->pc; goto dispatch; }
goto P_0c06af86;
P_0c06af84: /* original 343c, guest PC 0x0c06af84 */
if(!s->budget--) { s->failed_pc=0x0c06af84u; return 0; }
r[4]+=r[3];
goto P_0c06af86;
P_0c06af86: /* original fef5, guest PC 0x0c06af86 */
if(!s->budget--) { s->failed_pc=0x0c06af86u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[15]))!=0);
goto P_0c06af88;
P_0c06af88: /* original 8d04, guest PC 0x0c06af88 */
if(!s->budget--) { s->failed_pc=0x0c06af88u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,0);
if(cond) { goto P_0c06af94; }
goto P_0c06af8c;
P_0c06af8a: /* original f40c, guest PC 0x0c06af8a */
if(!s->budget--) { s->failed_pc=0x0c06af8au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c06af8c;
P_0c06af8c: /* original ffe5, guest PC 0x0c06af8c */
if(!s->budget--) { s->failed_pc=0x0c06af8cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[14]))!=0);
goto P_0c06af8e;
P_0c06af8e: /* original 8919, guest PC 0x0c06af8e */
if(!s->budget--) { s->failed_pc=0x0c06af8eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06afc4; }
goto P_0c06af90;
P_0c06af90: /* original f4d5, guest PC 0x0c06af90 */
if(!s->budget--) { s->failed_pc=0x0c06af90u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[13]))!=0);
goto P_0c06af92;
P_0c06af92: /* original 8b17, guest PC 0x0c06af92 */
if(!s->budget--) { s->failed_pc=0x0c06af92u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06afc4; }
goto P_0c06af94;
P_0c06af94: /* original 922b, guest PC 0x0c06af94 */
if(!s->budget--) { s->failed_pc=0x0c06af94u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06afeeu,2);
goto P_0c06af96;
P_0c06af96: /* original 64c3, guest PC 0x0c06af96 */
if(!s->budget--) { s->failed_pc=0x0c06af96u; return 0; }
r[4]=r[12];
goto P_0c06af98;
P_0c06af98: /* original 53f3, guest PC 0x0c06af98 */
if(!s->budget--) { s->failed_pc=0x0c06af98u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c06af9a;
P_0c06af9a: /* original 6583, guest PC 0x0c06af9a */
if(!s->budget--) { s->failed_pc=0x0c06af9au; return 0; }
r[5]=r[8];
goto P_0c06af9c;
P_0c06af9c: /* original 32ac, guest PC 0x0c06af9c */
if(!s->budget--) { s->failed_pc=0x0c06af9cu; return 0; }
r[2]+=r[10];
goto P_0c06af9e;
P_0c06af9e: /* original 323c, guest PC 0x0c06af9e */
if(!s->budget--) { s->failed_pc=0x0c06af9eu; return 0; }
r[2]+=r[3];
goto P_0c06afa0;
P_0c06afa0: /* original f2fa, guest PC 0x0c06afa0 */
if(!s->budget--) { s->failed_pc=0x0c06afa0u; return 0; }
vf3_matrix_store(s,ram,15,r[2]);
goto P_0c06afa2;
P_0c06afa2: /* original 7401, guest PC 0x0c06afa2 */
if(!s->budget--) { s->failed_pc=0x0c06afa2u; return 0; }
r[4]+=0x00000001u;
goto P_0c06afa4;
P_0c06afa4: /* original 9223, guest PC 0x0c06afa4 */
if(!s->budget--) { s->failed_pc=0x0c06afa4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06afeeu,2);
goto P_0c06afa6;
P_0c06afa6: /* original 53f2, guest PC 0x0c06afa6 */
if(!s->budget--) { s->failed_pc=0x0c06afa6u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c06afa8;
P_0c06afa8: /* original 32ac, guest PC 0x0c06afa8 */
if(!s->budget--) { s->failed_pc=0x0c06afa8u; return 0; }
r[2]+=r[10];
goto P_0c06afaa;
P_0c06afaa: /* original 323c, guest PC 0x0c06afaa */
if(!s->budget--) { s->failed_pc=0x0c06afaau; return 0; }
r[2]+=r[3];
goto P_0c06afac;
P_0c06afac: /* original f2ea, guest PC 0x0c06afac */
if(!s->budget--) { s->failed_pc=0x0c06afacu; return 0; }
vf3_matrix_store(s,ram,14,r[2]);
goto P_0c06afae;
P_0c06afae: /* original 931f, guest PC 0x0c06afae */
if(!s->budget--) { s->failed_pc=0x0c06afaeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aff0u,2);
goto P_0c06afb0;
P_0c06afb0: /* original 33ec, guest PC 0x0c06afb0 */
if(!s->budget--) { s->failed_pc=0x0c06afb0u; return 0; }
r[3]+=r[14];
goto P_0c06afb2;
P_0c06afb2: /* original 490b, guest PC 0x0c06afb2 */
if(!s->budget--) { s->failed_pc=0x0c06afb2u; return 0; }
target=r[9];
r[16]=code_base|0x0c06afb6u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06afb6u) { target=s->pc; goto dispatch; }
goto P_0c06afb6;
P_0c06afb4: /* original 343c, guest PC 0x0c06afb4 */
if(!s->budget--) { s->failed_pc=0x0c06afb4u; return 0; }
r[4]+=r[3];
goto P_0c06afb6;
P_0c06afb6: /* original 941b, guest PC 0x0c06afb6 */
if(!s->budget--) { s->failed_pc=0x0c06afb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aff0u,2);
goto P_0c06afb8;
P_0c06afb8: /* original 65f2, guest PC 0x0c06afb8 */
if(!s->budget--) { s->failed_pc=0x0c06afb8u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06afba;
P_0c06afba: /* original 34ec, guest PC 0x0c06afba */
if(!s->budget--) { s->failed_pc=0x0c06afbau; return 0; }
r[4]+=r[14];
goto P_0c06afbc;
P_0c06afbc: /* original 490b, guest PC 0x0c06afbc */
if(!s->budget--) { s->failed_pc=0x0c06afbcu; return 0; }
target=r[9];
r[16]=code_base|0x0c06afc0u;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06afc0u) { target=s->pc; goto dispatch; }
goto P_0c06afc0;
P_0c06afbe: /* original 34cc, guest PC 0x0c06afbe */
if(!s->budget--) { s->failed_pc=0x0c06afbeu; return 0; }
r[4]+=r[12];
goto P_0c06afc0;
P_0c06afc0: /* original 60b3, guest PC 0x0c06afc0 */
if(!s->budget--) { s->failed_pc=0x0c06afc0u; return 0; }
r[0]=r[11];
goto P_0c06afc2;
P_0c06afc2: /* original 80f4, guest PC 0x0c06afc2 */
if(!s->budget--) { s->failed_pc=0x0c06afc2u; return 0; }
write(ram,r[15]+4,r[0],1);
goto P_0c06afc4;
P_0c06afc4: /* original 7c01, guest PC 0x0c06afc4 */
if(!s->budget--) { s->failed_pc=0x0c06afc4u; return 0; }
r[12]+=0x00000001u;
goto P_0c06afc6;
P_0c06afc6: /* original e40c, guest PC 0x0c06afc6 */
if(!s->budget--) { s->failed_pc=0x0c06afc6u; return 0; }
r[4]=0x0000000cu;
goto P_0c06afc8;
P_0c06afc8: /* original 3c43, guest PC 0x0c06afc8 */
if(!s->budget--) { s->failed_pc=0x0c06afc8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[4])!=0);
goto P_0c06afca;
P_0c06afca: /* original 8bb5, guest PC 0x0c06afca */
if(!s->budget--) { s->failed_pc=0x0c06afcau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06af38; }
goto P_0c06afcc;
P_0c06afcc: /* original 84f4, guest PC 0x0c06afcc */
if(!s->budget--) { s->failed_pc=0x0c06afccu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c06afce;
P_0c06afce: /* original 2008, guest PC 0x0c06afce */
if(!s->budget--) { s->failed_pc=0x0c06afceu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06afd0;
P_0c06afd0: /* original 89ad, guest PC 0x0c06afd0 */
if(!s->budget--) { s->failed_pc=0x0c06afd0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06af2e; }
goto P_0c06afd2;
P_0c06afd2: /* original 7f10, guest PC 0x0c06afd2 */
if(!s->budget--) { s->failed_pc=0x0c06afd2u; return 0; }
r[15]+=0x00000010u;
goto P_0c06afd4;
P_0c06afd4: /* original 4f26, guest PC 0x0c06afd4 */
if(!s->budget--) { s->failed_pc=0x0c06afd4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06afd6;
P_0c06afd6: /* original fdf9, guest PC 0x0c06afd6 */
if(!s->budget--) { s->failed_pc=0x0c06afd6u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06afd8;
P_0c06afd8: /* original fef9, guest PC 0x0c06afd8 */
if(!s->budget--) { s->failed_pc=0x0c06afd8u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06afda;
P_0c06afda: /* original fff9, guest PC 0x0c06afda */
if(!s->budget--) { s->failed_pc=0x0c06afdau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06afdc;
P_0c06afdc: /* original 68f6, guest PC 0x0c06afdc */
if(!s->budget--) { s->failed_pc=0x0c06afdcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06afde;
P_0c06afde: /* original 69f6, guest PC 0x0c06afde */
if(!s->budget--) { s->failed_pc=0x0c06afdeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06afe0;
P_0c06afe0: /* original 6af6, guest PC 0x0c06afe0 */
if(!s->budget--) { s->failed_pc=0x0c06afe0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06afe2;
P_0c06afe2: /* original 6bf6, guest PC 0x0c06afe2 */
if(!s->budget--) { s->failed_pc=0x0c06afe2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06afe4;
P_0c06afe4: /* original 6cf6, guest PC 0x0c06afe4 */
if(!s->budget--) { s->failed_pc=0x0c06afe4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06afe6;
P_0c06afe6: /* original 6df6, guest PC 0x0c06afe6 */
if(!s->budget--) { s->failed_pc=0x0c06afe6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06afe8;
P_0c06afe8: /* original 000b, guest PC 0x0c06afe8 */
if(!s->budget--) { s->failed_pc=0x0c06afe8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06afea: /* original 6ef6, guest PC 0x0c06afea */
if(!s->budget--) { s->failed_pc=0x0c06afeau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06afecu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06afecu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
