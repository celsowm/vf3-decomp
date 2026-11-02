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
int vf3_away_batch27_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05acf4u: goto P_0c05acf4;
case 0x0c05acf6u: goto P_0c05acf6;
case 0x0c05acf8u: goto P_0c05acf8;
case 0x0c05acfau: goto P_0c05acfa;
case 0x0c05acfcu: goto P_0c05acfc;
case 0x0c05acfeu: goto P_0c05acfe;
case 0x0c05ad00u: goto P_0c05ad00;
case 0x0c05ad02u: goto P_0c05ad02;
case 0x0c05ad04u: goto P_0c05ad04;
case 0x0c05ad06u: goto P_0c05ad06;
case 0x0c05ad08u: goto P_0c05ad08;
case 0x0c05ad0au: goto P_0c05ad0a;
case 0x0c05ad0cu: goto P_0c05ad0c;
case 0x0c05ad0eu: goto P_0c05ad0e;
case 0x0c05ad10u: goto P_0c05ad10;
case 0x0c05ad12u: goto P_0c05ad12;
case 0x0c05ad14u: goto P_0c05ad14;
case 0x0c05ad16u: goto P_0c05ad16;
case 0x0c05ad18u: goto P_0c05ad18;
case 0x0c05ad1au: goto P_0c05ad1a;
case 0x0c05ad1cu: goto P_0c05ad1c;
case 0x0c05ad1eu: goto P_0c05ad1e;
case 0x0c05ad20u: goto P_0c05ad20;
case 0x0c05ad22u: goto P_0c05ad22;
case 0x0c05ad24u: goto P_0c05ad24;
case 0x0c05ad26u: goto P_0c05ad26;
case 0x0c05ad28u: goto P_0c05ad28;
case 0x0c05ad2au: goto P_0c05ad2a;
case 0x0c05ad2cu: goto P_0c05ad2c;
case 0x0c05ad2eu: goto P_0c05ad2e;
case 0x0c05ad30u: goto P_0c05ad30;
case 0x0c05ad32u: goto P_0c05ad32;
case 0x0c05ad34u: goto P_0c05ad34;
case 0x0c05ad36u: goto P_0c05ad36;
case 0x0c05ad38u: goto P_0c05ad38;
case 0x0c05ad3au: goto P_0c05ad3a;
case 0x0c05ad3cu: goto P_0c05ad3c;
case 0x0c05ad3eu: goto P_0c05ad3e;
case 0x0c05ad40u: goto P_0c05ad40;
case 0x0c05ad42u: goto P_0c05ad42;
case 0x0c05ad44u: goto P_0c05ad44;
case 0x0c05ad46u: goto P_0c05ad46;
case 0x0c05ad48u: goto P_0c05ad48;
case 0x0c05ad4au: goto P_0c05ad4a;
case 0x0c05ad4cu: goto P_0c05ad4c;
case 0x0c05ad4eu: goto P_0c05ad4e;
case 0x0c05ad50u: goto P_0c05ad50;
case 0x0c05ad52u: goto P_0c05ad52;
case 0x0c05ad54u: goto P_0c05ad54;
case 0x0c05ad56u: goto P_0c05ad56;
case 0x0c05ad58u: goto P_0c05ad58;
case 0x0c05ad5au: goto P_0c05ad5a;
case 0x0c05ad5cu: goto P_0c05ad5c;
case 0x0c05ad5eu: goto P_0c05ad5e;
case 0x0c05ad60u: goto P_0c05ad60;
case 0x0c05ad62u: goto P_0c05ad62;
case 0x0c05ad64u: goto P_0c05ad64;
case 0x0c05ad66u: goto P_0c05ad66;
case 0x0c05ad68u: goto P_0c05ad68;
case 0x0c05ad6au: goto P_0c05ad6a;
case 0x0c05ad6cu: goto P_0c05ad6c;
case 0x0c05ad6eu: goto P_0c05ad6e;
case 0x0c05ad70u: goto P_0c05ad70;
case 0x0c05ad72u: goto P_0c05ad72;
case 0x0c05ad74u: goto P_0c05ad74;
case 0x0c05ad76u: goto P_0c05ad76;
case 0x0c05ad78u: goto P_0c05ad78;
case 0x0c05ad7au: goto P_0c05ad7a;
case 0x0c05ad7cu: goto P_0c05ad7c;
case 0x0c05ad7eu: goto P_0c05ad7e;
case 0x0c05ad80u: goto P_0c05ad80;
case 0x0c05ad82u: goto P_0c05ad82;
case 0x0c05ad84u: goto P_0c05ad84;
case 0x0c05ad86u: goto P_0c05ad86;
case 0x0c05ad88u: goto P_0c05ad88;
case 0x0c05ad8au: goto P_0c05ad8a;
case 0x0c05ad8cu: goto P_0c05ad8c;
case 0x0c05ad8eu: goto P_0c05ad8e;
case 0x0c05ad90u: goto P_0c05ad90;
case 0x0c05ad92u: goto P_0c05ad92;
case 0x0c05ad94u: goto P_0c05ad94;
case 0x0c05ad96u: goto P_0c05ad96;
case 0x0c05ad98u: goto P_0c05ad98;
case 0x0c05ad9au: goto P_0c05ad9a;
case 0x0c05ad9cu: goto P_0c05ad9c;
case 0x0c05ad9eu: goto P_0c05ad9e;
case 0x0c05ada0u: goto P_0c05ada0;
case 0x0c05ada2u: goto P_0c05ada2;
case 0x0c05ada4u: goto P_0c05ada4;
case 0x0c05ada6u: goto P_0c05ada6;
case 0x0c05ada8u: goto P_0c05ada8;
case 0x0c05adaau: goto P_0c05adaa;
case 0x0c05adacu: goto P_0c05adac;
case 0x0c05adaeu: goto P_0c05adae;
case 0x0c05adb0u: goto P_0c05adb0;
case 0x0c05adb2u: goto P_0c05adb2;
case 0x0c05adb4u: goto P_0c05adb4;
case 0x0c05adb6u: goto P_0c05adb6;
case 0x0c05adb8u: goto P_0c05adb8;
case 0x0c05adbau: goto P_0c05adba;
case 0x0c05adbcu: goto P_0c05adbc;
case 0x0c05adbeu: goto P_0c05adbe;
case 0x0c05adc0u: goto P_0c05adc0;
case 0x0c05adc2u: goto P_0c05adc2;
case 0x0c05adc4u: goto P_0c05adc4;
case 0x0c05adc6u: goto P_0c05adc6;
case 0x0c05adc8u: goto P_0c05adc8;
case 0x0c05adcau: goto P_0c05adca;
case 0x0c05adccu: goto P_0c05adcc;
case 0x0c05adceu: goto P_0c05adce;
case 0x0c05add0u: goto P_0c05add0;
case 0x0c05add2u: goto P_0c05add2;
case 0x0c05add4u: goto P_0c05add4;
case 0x0c05add6u: goto P_0c05add6;
case 0x0c05add8u: goto P_0c05add8;
case 0x0c05addau: goto P_0c05adda;
case 0x0c05addcu: goto P_0c05addc;
case 0x0c05addeu: goto P_0c05adde;
case 0x0c05ade0u: goto P_0c05ade0;
case 0x0c05ade2u: goto P_0c05ade2;
case 0x0c05ade4u: goto P_0c05ade4;
case 0x0c05ade6u: goto P_0c05ade6;
case 0x0c05ade8u: goto P_0c05ade8;
case 0x0c05adeau: goto P_0c05adea;
case 0x0c05adecu: goto P_0c05adec;
case 0x0c05adeeu: goto P_0c05adee;
case 0x0c05adf0u: goto P_0c05adf0;
case 0x0c05adf2u: goto P_0c05adf2;
case 0x0c05adf4u: goto P_0c05adf4;
case 0x0c05adf6u: goto P_0c05adf6;
case 0x0c05adf8u: goto P_0c05adf8;
case 0x0c05adfau: goto P_0c05adfa;
case 0x0c05adfcu: goto P_0c05adfc;
case 0x0c05adfeu: goto P_0c05adfe;
case 0x0c05ae00u: goto P_0c05ae00;
case 0x0c05ae02u: goto P_0c05ae02;
case 0x0c05ae04u: goto P_0c05ae04;
case 0x0c05ae06u: goto P_0c05ae06;
case 0x0c05ae08u: goto P_0c05ae08;
case 0x0c05ae3cu: goto P_0c05ae3c;
case 0x0c05ae3eu: goto P_0c05ae3e;
case 0x0c05ae40u: goto P_0c05ae40;
case 0x0c05ae42u: goto P_0c05ae42;
case 0x0c05ae44u: goto P_0c05ae44;
case 0x0c05ae46u: goto P_0c05ae46;
case 0x0c05ae48u: goto P_0c05ae48;
case 0x0c05ae4au: goto P_0c05ae4a;
case 0x0c05ae4cu: goto P_0c05ae4c;
case 0x0c05ae4eu: goto P_0c05ae4e;
case 0x0c05ae50u: goto P_0c05ae50;
case 0x0c05ae52u: goto P_0c05ae52;
case 0x0c05ae54u: goto P_0c05ae54;
case 0x0c05ae56u: goto P_0c05ae56;
case 0x0c05ae58u: goto P_0c05ae58;
case 0x0c05ae5au: goto P_0c05ae5a;
case 0x0c05ae5cu: goto P_0c05ae5c;
case 0x0c05ae5eu: goto P_0c05ae5e;
case 0x0c05ae60u: goto P_0c05ae60;
case 0x0c05ae62u: goto P_0c05ae62;
case 0x0c05ae64u: goto P_0c05ae64;
case 0x0c05ae66u: goto P_0c05ae66;
case 0x0c05ae68u: goto P_0c05ae68;
case 0x0c05ae6au: goto P_0c05ae6a;
case 0x0c05ae6cu: goto P_0c05ae6c;
case 0x0c05ae6eu: goto P_0c05ae6e;
case 0x0c05ae70u: goto P_0c05ae70;
case 0x0c05ae72u: goto P_0c05ae72;
case 0x0c05ae74u: goto P_0c05ae74;
case 0x0c05ae76u: goto P_0c05ae76;
case 0x0c05ae78u: goto P_0c05ae78;
case 0x0c05ae7au: goto P_0c05ae7a;
case 0x0c05ae7cu: goto P_0c05ae7c;
case 0x0c05ae7eu: goto P_0c05ae7e;
case 0x0c05ae80u: goto P_0c05ae80;
case 0x0c05ae82u: goto P_0c05ae82;
case 0x0c05ae84u: goto P_0c05ae84;
case 0x0c05ae86u: goto P_0c05ae86;
case 0x0c05ae88u: goto P_0c05ae88;
case 0x0c05ae8au: goto P_0c05ae8a;
case 0x0c05ae8cu: goto P_0c05ae8c;
case 0x0c05ae8eu: goto P_0c05ae8e;
case 0x0c05ae90u: goto P_0c05ae90;
case 0x0c05ae92u: goto P_0c05ae92;
case 0x0c05ae94u: goto P_0c05ae94;
case 0x0c05ae96u: goto P_0c05ae96;
case 0x0c05ae98u: goto P_0c05ae98;
case 0x0c05ae9au: goto P_0c05ae9a;
case 0x0c05ae9cu: goto P_0c05ae9c;
case 0x0c05ae9eu: goto P_0c05ae9e;
case 0x0c05aea0u: goto P_0c05aea0;
case 0x0c05aea2u: goto P_0c05aea2;
case 0x0c05aea4u: goto P_0c05aea4;
case 0x0c05aea6u: goto P_0c05aea6;
case 0x0c05aea8u: goto P_0c05aea8;
case 0x0c05aeaau: goto P_0c05aeaa;
case 0x0c05aeacu: goto P_0c05aeac;
case 0x0c05aeaeu: goto P_0c05aeae;
case 0x0c05aeb0u: goto P_0c05aeb0;
case 0x0c05aeb2u: goto P_0c05aeb2;
case 0x0c05aeb4u: goto P_0c05aeb4;
case 0x0c05aeb6u: goto P_0c05aeb6;
case 0x0c05aeb8u: goto P_0c05aeb8;
case 0x0c05aebau: goto P_0c05aeba;
case 0x0c05aebcu: goto P_0c05aebc;
case 0x0c05aebeu: goto P_0c05aebe;
case 0x0c05aec0u: goto P_0c05aec0;
case 0x0c05aec2u: goto P_0c05aec2;
case 0x0c05aec4u: goto P_0c05aec4;
case 0x0c05aec6u: goto P_0c05aec6;
case 0x0c05aec8u: goto P_0c05aec8;
case 0x0c05aecau: goto P_0c05aeca;
case 0x0c05aeccu: goto P_0c05aecc;
case 0x0c05aeceu: goto P_0c05aece;
case 0x0c05aed0u: goto P_0c05aed0;
case 0x0c05aed2u: goto P_0c05aed2;
case 0x0c05aed4u: goto P_0c05aed4;
case 0x0c05aed6u: goto P_0c05aed6;
case 0x0c05aed8u: goto P_0c05aed8;
case 0x0c05aedau: goto P_0c05aeda;
case 0x0c05aedcu: goto P_0c05aedc;
case 0x0c05aedeu: goto P_0c05aede;
case 0x0c05aee0u: goto P_0c05aee0;
case 0x0c05aee2u: goto P_0c05aee2;
case 0x0c05aee4u: goto P_0c05aee4;
case 0x0c05aee6u: goto P_0c05aee6;
case 0x0c05aee8u: goto P_0c05aee8;
case 0x0c05aeeau: goto P_0c05aeea;
case 0x0c05aeecu: goto P_0c05aeec;
case 0x0c05aeeeu: goto P_0c05aeee;
case 0x0c05aef0u: goto P_0c05aef0;
case 0x0c05aef2u: goto P_0c05aef2;
case 0x0c05aef4u: goto P_0c05aef4;
case 0x0c05aef6u: goto P_0c05aef6;
case 0x0c05aef8u: goto P_0c05aef8;
case 0x0c05aefau: goto P_0c05aefa;
case 0x0c05aefcu: goto P_0c05aefc;
case 0x0c05aefeu: goto P_0c05aefe;
case 0x0c05af00u: goto P_0c05af00;
case 0x0c05af02u: goto P_0c05af02;
case 0x0c05af04u: goto P_0c05af04;
case 0x0c05af06u: goto P_0c05af06;
case 0x0c05af08u: goto P_0c05af08;
case 0x0c05af0au: goto P_0c05af0a;
case 0x0c05af0cu: goto P_0c05af0c;
case 0x0c05af0eu: goto P_0c05af0e;
case 0x0c05af10u: goto P_0c05af10;
case 0x0c05af12u: goto P_0c05af12;
case 0x0c05af14u: goto P_0c05af14;
case 0x0c05af16u: goto P_0c05af16;
case 0x0c05af18u: goto P_0c05af18;
case 0x0c05af1au: goto P_0c05af1a;
case 0x0c05af1cu: goto P_0c05af1c;
case 0x0c05af1eu: goto P_0c05af1e;
case 0x0c05af20u: goto P_0c05af20;
case 0x0c05af22u: goto P_0c05af22;
case 0x0c05af24u: goto P_0c05af24;
case 0x0c05af26u: goto P_0c05af26;
case 0x0c05af28u: goto P_0c05af28;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05acf4: /* original 2fe6, guest PC 0x0c05acf4 */
if(!s->budget--) { s->failed_pc=0x0c05acf4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05acf6;
P_0c05acf6: /* original 6e43, guest PC 0x0c05acf6 */
if(!s->budget--) { s->failed_pc=0x0c05acf6u; return 0; }
r[14]=r[4];
goto P_0c05acf8;
P_0c05acf8: /* original d246, guest PC 0x0c05acf8 */
if(!s->budget--) { s->failed_pc=0x0c05acf8u; return 0; }
r[2]=read(ram,0x0c05ae14u,4);
goto P_0c05acfa;
P_0c05acfa: /* original 2fd6, guest PC 0x0c05acfa */
if(!s->budget--) { s->failed_pc=0x0c05acfau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05acfc;
P_0c05acfc: /* original 2fc6, guest PC 0x0c05acfc */
if(!s->budget--) { s->failed_pc=0x0c05acfcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05acfe;
P_0c05acfe: /* original 6c73, guest PC 0x0c05acfe */
if(!s->budget--) { s->failed_pc=0x0c05acfeu; return 0; }
r[12]=r[7];
goto P_0c05ad00;
P_0c05ad00: /* original d345, guest PC 0x0c05ad00 */
if(!s->budget--) { s->failed_pc=0x0c05ad00u; return 0; }
r[3]=read(ram,0x0c05ae18u,4);
goto P_0c05ad02;
P_0c05ad02: /* original 2fb6, guest PC 0x0c05ad02 */
if(!s->budget--) { s->failed_pc=0x0c05ad02u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ad04;
P_0c05ad04: /* original 2fa6, guest PC 0x0c05ad04 */
if(!s->budget--) { s->failed_pc=0x0c05ad04u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ad06;
P_0c05ad06: /* original 4f22, guest PC 0x0c05ad06 */
if(!s->budget--) { s->failed_pc=0x0c05ad06u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05ad08;
P_0c05ad08: /* original 907f, guest PC 0x0c05ad08 */
if(!s->budget--) { s->failed_pc=0x0c05ad08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ae0au,2);
goto P_0c05ad0a;
P_0c05ad0a: /* original 3f0c, guest PC 0x0c05ad0a */
if(!s->budget--) { s->failed_pc=0x0c05ad0au; return 0; }
r[15]+=r[0];
goto P_0c05ad0c;
P_0c05ad0c: /* original 2f62, guest PC 0x0c05ad0c */
if(!s->budget--) { s->failed_pc=0x0c05ad0cu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c05ad0e;
P_0c05ad0e: /* original 61f3, guest PC 0x0c05ad0e */
if(!s->budget--) { s->failed_pc=0x0c05ad0eu; return 0; }
r[1]=r[15];
goto P_0c05ad10;
P_0c05ad10: /* original 7104, guest PC 0x0c05ad10 */
if(!s->budget--) { s->failed_pc=0x0c05ad10u; return 0; }
r[1]+=0x00000004u;
goto P_0c05ad12;
P_0c05ad12: /* original 430b, guest PC 0x0c05ad12 */
if(!s->budget--) { s->failed_pc=0x0c05ad12u; return 0; }
target=r[3];
r[16]=code_base|0x0c05ad16u;
r[0]=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05ad16u) { target=s->pc; goto dispatch; }
goto P_0c05ad16;
P_0c05ad14: /* original e018, guest PC 0x0c05ad14 */
if(!s->budget--) { s->failed_pc=0x0c05ad14u; return 0; }
r[0]=0x00000018u;
goto P_0c05ad16;
P_0c05ad16: /* original d441, guest PC 0x0c05ad16 */
if(!s->budget--) { s->failed_pc=0x0c05ad16u; return 0; }
r[4]=read(ram,0x0c05ae1cu,4);
goto P_0c05ad18;
P_0c05ad18: /* original dd41, guest PC 0x0c05ad18 */
if(!s->budget--) { s->failed_pc=0x0c05ad18u; return 0; }
r[13]=read(ram,0x0c05ae20u,4);
goto P_0c05ad1a;
P_0c05ad1a: /* original 6142, guest PC 0x0c05ad1a */
if(!s->budget--) { s->failed_pc=0x0c05ad1au; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c05ad1c;
P_0c05ad1c: /* original 4108, guest PC 0x0c05ad1c */
if(!s->budget--) { s->failed_pc=0x0c05ad1cu; return 0; }
r[1]<<=2;
goto P_0c05ad1e;
P_0c05ad1e: /* original 4108, guest PC 0x0c05ad1e */
if(!s->budget--) { s->failed_pc=0x0c05ad1eu; return 0; }
r[1]<<=2;
goto P_0c05ad20;
P_0c05ad20: /* original 63d3, guest PC 0x0c05ad20 */
if(!s->budget--) { s->failed_pc=0x0c05ad20u; return 0; }
r[3]=r[13];
goto P_0c05ad22;
P_0c05ad22: /* original 731c, guest PC 0x0c05ad22 */
if(!s->budget--) { s->failed_pc=0x0c05ad22u; return 0; }
r[3]+=0x0000001cu;
goto P_0c05ad24;
P_0c05ad24: /* original 313c, guest PC 0x0c05ad24 */
if(!s->budget--) { s->failed_pc=0x0c05ad24u; return 0; }
r[1]+=r[3];
goto P_0c05ad26;
P_0c05ad26: /* original 63d3, guest PC 0x0c05ad26 */
if(!s->budget--) { s->failed_pc=0x0c05ad26u; return 0; }
r[3]=r[13];
goto P_0c05ad28;
P_0c05ad28: /* original 21e2, guest PC 0x0c05ad28 */
if(!s->budget--) { s->failed_pc=0x0c05ad28u; return 0; }
write(ram,r[1],r[14],4);
goto P_0c05ad2a;
P_0c05ad2a: /* original 731c, guest PC 0x0c05ad2a */
if(!s->budget--) { s->failed_pc=0x0c05ad2au; return 0; }
r[3]+=0x0000001cu;
goto P_0c05ad2c;
P_0c05ad2c: /* original 6142, guest PC 0x0c05ad2c */
if(!s->budget--) { s->failed_pc=0x0c05ad2cu; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c05ad2e;
P_0c05ad2e: /* original 4108, guest PC 0x0c05ad2e */
if(!s->budget--) { s->failed_pc=0x0c05ad2eu; return 0; }
r[1]<<=2;
goto P_0c05ad30;
P_0c05ad30: /* original 4108, guest PC 0x0c05ad30 */
if(!s->budget--) { s->failed_pc=0x0c05ad30u; return 0; }
r[1]<<=2;
goto P_0c05ad32;
P_0c05ad32: /* original 313c, guest PC 0x0c05ad32 */
if(!s->budget--) { s->failed_pc=0x0c05ad32u; return 0; }
r[1]+=r[3];
goto P_0c05ad34;
P_0c05ad34: /* original 1151, guest PC 0x0c05ad34 */
if(!s->budget--) { s->failed_pc=0x0c05ad34u; return 0; }
write(ram,r[1]+4,r[5],4);
goto P_0c05ad36;
P_0c05ad36: /* original 63d3, guest PC 0x0c05ad36 */
if(!s->budget--) { s->failed_pc=0x0c05ad36u; return 0; }
r[3]=r[13];
goto P_0c05ad38;
P_0c05ad38: /* original 6142, guest PC 0x0c05ad38 */
if(!s->budget--) { s->failed_pc=0x0c05ad38u; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c05ad3a;
P_0c05ad3a: /* original 731c, guest PC 0x0c05ad3a */
if(!s->budget--) { s->failed_pc=0x0c05ad3au; return 0; }
r[3]+=0x0000001cu;
goto P_0c05ad3c;
P_0c05ad3c: /* original 60f2, guest PC 0x0c05ad3c */
if(!s->budget--) { s->failed_pc=0x0c05ad3cu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c05ad3e;
P_0c05ad3e: /* original 4108, guest PC 0x0c05ad3e */
if(!s->budget--) { s->failed_pc=0x0c05ad3eu; return 0; }
r[1]<<=2;
goto P_0c05ad40;
P_0c05ad40: /* original 4108, guest PC 0x0c05ad40 */
if(!s->budget--) { s->failed_pc=0x0c05ad40u; return 0; }
r[1]<<=2;
goto P_0c05ad42;
P_0c05ad42: /* original 313c, guest PC 0x0c05ad42 */
if(!s->budget--) { s->failed_pc=0x0c05ad42u; return 0; }
r[1]+=r[3];
goto P_0c05ad44;
P_0c05ad44: /* original 1102, guest PC 0x0c05ad44 */
if(!s->budget--) { s->failed_pc=0x0c05ad44u; return 0; }
write(ram,r[1]+8,r[0],4);
goto P_0c05ad46;
P_0c05ad46: /* original 61d3, guest PC 0x0c05ad46 */
if(!s->budget--) { s->failed_pc=0x0c05ad46u; return 0; }
r[1]=r[13];
goto P_0c05ad48;
P_0c05ad48: /* original 9060, guest PC 0x0c05ad48 */
if(!s->budget--) { s->failed_pc=0x0c05ad48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ae0cu,2);
goto P_0c05ad4a;
P_0c05ad4a: /* original 711c, guest PC 0x0c05ad4a */
if(!s->budget--) { s->failed_pc=0x0c05ad4au; return 0; }
r[1]+=0x0000001cu;
goto P_0c05ad4c;
P_0c05ad4c: /* original 1dc6, guest PC 0x0c05ad4c */
if(!s->budget--) { s->failed_pc=0x0c05ad4cu; return 0; }
write(ram,r[13]+24,r[12],4);
goto P_0c05ad4e;
P_0c05ad4e: /* original 6342, guest PC 0x0c05ad4e */
if(!s->budget--) { s->failed_pc=0x0c05ad4eu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c05ad50;
P_0c05ad50: /* original 4308, guest PC 0x0c05ad50 */
if(!s->budget--) { s->failed_pc=0x0c05ad50u; return 0; }
r[3]<<=2;
goto P_0c05ad52;
P_0c05ad52: /* original 4308, guest PC 0x0c05ad52 */
if(!s->budget--) { s->failed_pc=0x0c05ad52u; return 0; }
r[3]<<=2;
goto P_0c05ad54;
P_0c05ad54: /* original 331c, guest PC 0x0c05ad54 */
if(!s->budget--) { s->failed_pc=0x0c05ad54u; return 0; }
r[3]+=r[1];
goto P_0c05ad56;
P_0c05ad56: /* original 00fe, guest PC 0x0c05ad56 */
if(!s->budget--) { s->failed_pc=0x0c05ad56u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c05ad58;
P_0c05ad58: /* original 1303, guest PC 0x0c05ad58 */
if(!s->budget--) { s->failed_pc=0x0c05ad58u; return 0; }
write(ram,r[3]+12,r[0],4);
goto P_0c05ad5a;
P_0c05ad5a: /* original 6042, guest PC 0x0c05ad5a */
if(!s->budget--) { s->failed_pc=0x0c05ad5au; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c05ad5c;
P_0c05ad5c: /* original d331, guest PC 0x0c05ad5c */
if(!s->budget--) { s->failed_pc=0x0c05ad5cu; return 0; }
r[3]=read(ram,0x0c05ae24u,4);
goto P_0c05ad5e;
P_0c05ad5e: /* original 7001, guest PC 0x0c05ad5e */
if(!s->budget--) { s->failed_pc=0x0c05ad5eu; return 0; }
r[0]+=0x00000001u;
goto P_0c05ad60;
P_0c05ad60: /* original c901, guest PC 0x0c05ad60 */
if(!s->budget--) { s->failed_pc=0x0c05ad60u; return 0; }
r[0]&=1u;
goto P_0c05ad62;
P_0c05ad62: /* original 2402, guest PC 0x0c05ad62 */
if(!s->budget--) { s->failed_pc=0x0c05ad62u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05ad64;
P_0c05ad64: /* original 23c2, guest PC 0x0c05ad64 */
if(!s->budget--) { s->failed_pc=0x0c05ad64u; return 0; }
write(ram,r[3],r[12],4);
goto P_0c05ad66;
P_0c05ad66: /* original e054, guest PC 0x0c05ad66 */
if(!s->budget--) { s->failed_pc=0x0c05ad66u; return 0; }
r[0]=0x00000054u;
goto P_0c05ad68;
P_0c05ad68: /* original 01de, guest PC 0x0c05ad68 */
if(!s->budget--) { s->failed_pc=0x0c05ad68u; return 0; }
r[1]=read(ram,r[13]+r[0],4);
goto P_0c05ad6a;
P_0c05ad6a: /* original 2118, guest PC 0x0c05ad6a */
if(!s->budget--) { s->failed_pc=0x0c05ad6au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c05ad6c;
P_0c05ad6c: /* original 8903, guest PC 0x0c05ad6c */
if(!s->budget--) { s->failed_pc=0x0c05ad6cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ad76; }
goto P_0c05ad6e;
P_0c05ad6e: /* original 66f2, guest PC 0x0c05ad6e */
if(!s->budget--) { s->failed_pc=0x0c05ad6eu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c05ad70;
P_0c05ad70: /* original 944d, guest PC 0x0c05ad70 */
if(!s->budget--) { s->failed_pc=0x0c05ad70u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ae0eu,2);
goto P_0c05ad72;
P_0c05ad72: /* original b071, guest PC 0x0c05ad72 */
if(!s->budget--) { s->failed_pc=0x0c05ad72u; return 0; }
target=code_base|0x0c05ae58u; r[16]=code_base|0x0c05ad76u;
r[5]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05ad76u) { target=s->pc; goto dispatch; }
goto P_0c05ad76;
P_0c05ad74: /* original 65c3, guest PC 0x0c05ad74 */
if(!s->budget--) { s->failed_pc=0x0c05ad74u; return 0; }
r[5]=r[12];
goto P_0c05ad76;
P_0c05ad76: /* original d32c, guest PC 0x0c05ad76 */
if(!s->budget--) { s->failed_pc=0x0c05ad76u; return 0; }
r[3]=read(ram,0x0c05ae28u,4);
goto P_0c05ad78;
P_0c05ad78: /* original 430b, guest PC 0x0c05ad78 */
if(!s->budget--) { s->failed_pc=0x0c05ad78u; return 0; }
target=r[3];
r[16]=code_base|0x0c05ad7cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05ad7cu) { target=s->pc; goto dispatch; }
goto P_0c05ad7c;
P_0c05ad7a: /* original 0009, guest PC 0x0c05ad7a */
if(!s->budget--) { s->failed_pc=0x0c05ad7au; return 0; }
goto P_0c05ad7c;
P_0c05ad7c: /* original d22b, guest PC 0x0c05ad7c */
if(!s->budget--) { s->failed_pc=0x0c05ad7cu; return 0; }
r[2]=read(ram,0x0c05ae2cu,4);
goto P_0c05ad7e;
P_0c05ad7e: /* original 3020, guest PC 0x0c05ad7e */
if(!s->budget--) { s->failed_pc=0x0c05ad7eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[2])!=0);
goto P_0c05ad80;
P_0c05ad80: /* original 8b5c, guest PC 0x0c05ad80 */
if(!s->budget--) { s->failed_pc=0x0c05ad80u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05ae3c; }
goto P_0c05ad82;
P_0c05ad82: /* original 65e3, guest PC 0x0c05ad82 */
if(!s->budget--) { s->failed_pc=0x0c05ad82u; return 0; }
r[5]=r[14];
goto P_0c05ad84;
P_0c05ad84: /* original d32a, guest PC 0x0c05ad84 */
if(!s->budget--) { s->failed_pc=0x0c05ad84u; return 0; }
r[3]=read(ram,0x0c05ae30u,4);
goto P_0c05ad86;
P_0c05ad86: /* original e060, guest PC 0x0c05ad86 */
if(!s->budget--) { s->failed_pc=0x0c05ad86u; return 0; }
r[0]=0x00000060u;
goto P_0c05ad88;
P_0c05ad88: /* original 430b, guest PC 0x0c05ad88 */
if(!s->budget--) { s->failed_pc=0x0c05ad88u; return 0; }
target=r[3];
r[16]=code_base|0x0c05ad8cu;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05ad8cu) { target=s->pc; goto dispatch; }
goto P_0c05ad8c;
P_0c05ad8a: /* original 04de, guest PC 0x0c05ad8a */
if(!s->budget--) { s->failed_pc=0x0c05ad8au; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c05ad8c;
P_0c05ad8c: /* original 6403, guest PC 0x0c05ad8c */
if(!s->budget--) { s->failed_pc=0x0c05ad8cu; return 0; }
r[4]=r[0];
goto P_0c05ad8e;
P_0c05ad8e: /* original 2448, guest PC 0x0c05ad8e */
if(!s->budget--) { s->failed_pc=0x0c05ad8eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c05ad90;
P_0c05ad90: /* original 8901, guest PC 0x0c05ad90 */
if(!s->budget--) { s->failed_pc=0x0c05ad90u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ad96; }
goto P_0c05ad92;
P_0c05ad92: /* original a058, guest PC 0x0c05ad92 */
if(!s->budget--) { s->failed_pc=0x0c05ad92u; return 0; }
r[0]=r[4];
goto P_0c05ae46;
P_0c05ad94: /* original 6043, guest PC 0x0c05ad94 */
if(!s->budget--) { s->failed_pc=0x0c05ad94u; return 0; }
r[0]=r[4];
goto P_0c05ad96;
P_0c05ad96: /* original e401, guest PC 0x0c05ad96 */
if(!s->budget--) { s->failed_pc=0x0c05ad96u; return 0; }
r[4]=0x00000001u;
goto P_0c05ad98;
P_0c05ad98: /* original d226, guest PC 0x0c05ad98 */
if(!s->budget--) { s->failed_pc=0x0c05ad98u; return 0; }
r[2]=read(ram,0x0c05ae34u,4);
goto P_0c05ad9a;
P_0c05ad9a: /* original 61f3, guest PC 0x0c05ad9a */
if(!s->budget--) { s->failed_pc=0x0c05ad9au; return 0; }
r[1]=r[15];
goto P_0c05ad9c;
P_0c05ad9c: /* original 2e42, guest PC 0x0c05ad9c */
if(!s->budget--) { s->failed_pc=0x0c05ad9cu; return 0; }
write(ram,r[14],r[4],4);
goto P_0c05ad9e;
P_0c05ad9e: /* original 7104, guest PC 0x0c05ad9e */
if(!s->budget--) { s->failed_pc=0x0c05ad9eu; return 0; }
r[1]+=0x00000004u;
goto P_0c05ada0;
P_0c05ada0: /* original 6322, guest PC 0x0c05ada0 */
if(!s->budget--) { s->failed_pc=0x0c05ada0u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c05ada2;
P_0c05ada2: /* original 4308, guest PC 0x0c05ada2 */
if(!s->budget--) { s->failed_pc=0x0c05ada2u; return 0; }
r[3]<<=2;
goto P_0c05ada4;
P_0c05ada4: /* original 331c, guest PC 0x0c05ada4 */
if(!s->budget--) { s->failed_pc=0x0c05ada4u; return 0; }
r[3]+=r[1];
goto P_0c05ada6;
P_0c05ada6: /* original 6032, guest PC 0x0c05ada6 */
if(!s->budget--) { s->failed_pc=0x0c05ada6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05ada8;
P_0c05ada8: /* original 1e01, guest PC 0x0c05ada8 */
if(!s->budget--) { s->failed_pc=0x0c05ada8u; return 0; }
write(ram,r[14]+4,r[0],4);
goto P_0c05adaa;
P_0c05adaa: /* original 6023, guest PC 0x0c05adaa */
if(!s->budget--) { s->failed_pc=0x0c05adaau; return 0; }
r[0]=r[2];
goto P_0c05adac;
P_0c05adac: /* original 0009, guest PC 0x0c05adac */
if(!s->budget--) { s->failed_pc=0x0c05adacu; return 0; }
goto P_0c05adae;
P_0c05adae: /* original 6302, guest PC 0x0c05adae */
if(!s->budget--) { s->failed_pc=0x0c05adaeu; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c05adb0;
P_0c05adb0: /* original 1e32, guest PC 0x0c05adb0 */
if(!s->budget--) { s->failed_pc=0x0c05adb0u; return 0; }
write(ram,r[14]+8,r[3],4);
goto P_0c05adb2;
P_0c05adb2: /* original e048, guest PC 0x0c05adb2 */
if(!s->budget--) { s->failed_pc=0x0c05adb2u; return 0; }
r[0]=0x00000048u;
goto P_0c05adb4;
P_0c05adb4: /* original 02de, guest PC 0x0c05adb4 */
if(!s->budget--) { s->failed_pc=0x0c05adb4u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c05adb6;
P_0c05adb6: /* original e04c, guest PC 0x0c05adb6 */
if(!s->budget--) { s->failed_pc=0x0c05adb6u; return 0; }
r[0]=0x0000004cu;
goto P_0c05adb8;
P_0c05adb8: /* original 1e23, guest PC 0x0c05adb8 */
if(!s->budget--) { s->failed_pc=0x0c05adb8u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c05adba;
P_0c05adba: /* original 03de, guest PC 0x0c05adba */
if(!s->budget--) { s->failed_pc=0x0c05adbau; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c05adbc;
P_0c05adbc: /* original 1e34, guest PC 0x0c05adbc */
if(!s->budget--) { s->failed_pc=0x0c05adbcu; return 0; }
write(ram,r[14]+16,r[3],4);
goto P_0c05adbe;
P_0c05adbe: /* original 60c3, guest PC 0x0c05adbe */
if(!s->budget--) { s->failed_pc=0x0c05adbeu; return 0; }
r[0]=r[12];
goto P_0c05adc0;
P_0c05adc0: /* original 0009, guest PC 0x0c05adc0 */
if(!s->budget--) { s->failed_pc=0x0c05adc0u; return 0; }
goto P_0c05adc2;
P_0c05adc2: /* original 8801, guest PC 0x0c05adc2 */
if(!s->budget--) { s->failed_pc=0x0c05adc2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05adc4;
P_0c05adc4: /* original 8f02, guest PC 0x0c05adc4 */
if(!s->budget--) { s->failed_pc=0x0c05adc4u; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(!cond) { goto P_0c05adcc; }
goto P_0c05adc8;
P_0c05adc6: /* original e500, guest PC 0x0c05adc6 */
if(!s->budget--) { s->failed_pc=0x0c05adc6u; return 0; }
r[5]=0x00000000u;
goto P_0c05adc8;
P_0c05adc8: /* original a001, guest PC 0x0c05adc8 */
if(!s->budget--) { s->failed_pc=0x0c05adc8u; return 0; }
write(ram,r[14]+24,r[4],4);
goto P_0c05adce;
P_0c05adca: /* original 1e46, guest PC 0x0c05adca */
if(!s->budget--) { s->failed_pc=0x0c05adcau; return 0; }
write(ram,r[14]+24,r[4],4);
goto P_0c05adcc;
P_0c05adcc: /* original 1e56, guest PC 0x0c05adcc */
if(!s->budget--) { s->failed_pc=0x0c05adccu; return 0; }
write(ram,r[14]+24,r[5],4);
goto P_0c05adce;
P_0c05adce: /* original 901d, guest PC 0x0c05adce */
if(!s->budget--) { s->failed_pc=0x0c05adceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ae0cu,2);
goto P_0c05add0;
P_0c05add0: /* original 00fe, guest PC 0x0c05add0 */
if(!s->budget--) { s->failed_pc=0x0c05add0u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c05add2;
P_0c05add2: /* original 8801, guest PC 0x0c05add2 */
if(!s->budget--) { s->failed_pc=0x0c05add2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05add4;
P_0c05add4: /* original 8b36, guest PC 0x0c05add4 */
if(!s->budget--) { s->failed_pc=0x0c05add4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05ae44; }
goto P_0c05add6;
P_0c05add6: /* original e600, guest PC 0x0c05add6 */
if(!s->budget--) { s->failed_pc=0x0c05add6u; return 0; }
r[6]=0x00000000u;
goto P_0c05add8;
P_0c05add8: /* original 971a, guest PC 0x0c05add8 */
if(!s->budget--) { s->failed_pc=0x0c05add8u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ae10u,2);
goto P_0c05adda;
P_0c05adda: /* original 64f3, guest PC 0x0c05adda */
if(!s->budget--) { s->failed_pc=0x0c05addau; return 0; }
r[4]=r[15];
goto P_0c05addc;
P_0c05addc: /* original 741c, guest PC 0x0c05addc */
if(!s->budget--) { s->failed_pc=0x0c05addcu; return 0; }
r[4]+=0x0000001cu;
goto P_0c05adde;
P_0c05adde: /* original 7601, guest PC 0x0c05adde */
if(!s->budget--) { s->failed_pc=0x0c05addeu; return 0; }
r[6]+=0x00000001u;
goto P_0c05ade0;
P_0c05ade0: /* original 2452, guest PC 0x0c05ade0 */
if(!s->budget--) { s->failed_pc=0x0c05ade0u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c05ade2;
P_0c05ade2: /* original 3672, guest PC 0x0c05ade2 */
if(!s->budget--) { s->failed_pc=0x0c05ade2u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[7])!=0);
goto P_0c05ade4;
P_0c05ade4: /* original 8ffb, guest PC 0x0c05ade4 */
if(!s->budget--) { s->failed_pc=0x0c05ade4u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c05adde; }
goto P_0c05ade8;
P_0c05ade6: /* original 7404, guest PC 0x0c05ade6 */
if(!s->budget--) { s->failed_pc=0x0c05ade6u; return 0; }
r[4]+=0x00000004u;
goto P_0c05ade8;
P_0c05ade8: /* original db13, guest PC 0x0c05ade8 */
if(!s->budget--) { s->failed_pc=0x0c05ade8u; return 0; }
r[11]=read(ram,0x0c05ae38u,4);
goto P_0c05adea;
P_0c05adea: /* original ec00, guest PC 0x0c05adea */
if(!s->budget--) { s->failed_pc=0x0c05adeau; return 0; }
r[12]=0x00000000u;
goto P_0c05adec;
P_0c05adec: /* original 9d11, guest PC 0x0c05adec */
if(!s->budget--) { s->failed_pc=0x0c05adecu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ae12u,2);
goto P_0c05adee;
P_0c05adee: /* original 6af3, guest PC 0x0c05adee */
if(!s->budget--) { s->failed_pc=0x0c05adeeu; return 0; }
r[10]=r[15];
goto P_0c05adf0;
P_0c05adf0: /* original a006, guest PC 0x0c05adf0 */
if(!s->budget--) { s->failed_pc=0x0c05adf0u; return 0; }
r[10]+=0x0000001cu;
goto P_0c05ae00;
P_0c05adf2: /* original 7a1c, guest PC 0x0c05adf2 */
if(!s->budget--) { s->failed_pc=0x0c05adf2u; return 0; }
r[10]+=0x0000001cu;
goto P_0c05adf4;
P_0c05adf4: /* original 54e7, guest PC 0x0c05adf4 */
if(!s->budget--) { s->failed_pc=0x0c05adf4u; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c05adf6;
P_0c05adf6: /* original 66d3, guest PC 0x0c05adf6 */
if(!s->budget--) { s->failed_pc=0x0c05adf6u; return 0; }
r[6]=r[13];
goto P_0c05adf8;
P_0c05adf8: /* original 65a3, guest PC 0x0c05adf8 */
if(!s->budget--) { s->failed_pc=0x0c05adf8u; return 0; }
r[5]=r[10];
goto P_0c05adfa;
P_0c05adfa: /* original 4b0b, guest PC 0x0c05adfa */
if(!s->budget--) { s->failed_pc=0x0c05adfau; return 0; }
target=r[11];
r[16]=code_base|0x0c05adfeu;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05adfeu) { target=s->pc; goto dispatch; }
goto P_0c05adfe;
P_0c05adfc: /* original 34cc, guest PC 0x0c05adfc */
if(!s->budget--) { s->failed_pc=0x0c05adfcu; return 0; }
r[4]+=r[12];
goto P_0c05adfe;
P_0c05adfe: /* original 3cdc, guest PC 0x0c05adfe */
if(!s->budget--) { s->failed_pc=0x0c05adfeu; return 0; }
r[12]+=r[13];
goto P_0c05ae00;
P_0c05ae00: /* original 52e5, guest PC 0x0c05ae00 */
if(!s->budget--) { s->failed_pc=0x0c05ae00u; return 0; }
r[2]=read(ram,r[14]+20,4);
goto P_0c05ae02;
P_0c05ae02: /* original 3c22, guest PC 0x0c05ae02 */
if(!s->budget--) { s->failed_pc=0x0c05ae02u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>=r[2])!=0);
goto P_0c05ae04;
P_0c05ae04: /* original 8bf6, guest PC 0x0c05ae04 */
if(!s->budget--) { s->failed_pc=0x0c05ae04u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05adf4; }
goto P_0c05ae06;
P_0c05ae06: /* original a01d, guest PC 0x0c05ae06 */
if(!s->budget--) { s->failed_pc=0x0c05ae06u; return 0; }
goto P_0c05ae44;
P_0c05ae08: /* original 0009, guest PC 0x0c05ae08 */
if(!s->budget--) { s->failed_pc=0x0c05ae08u; return 0; }
if(!vf3_matrix_family(0x0c05ae0au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05ae0au; return 0; } return 1;
P_0c05ae3c: /* original 9475, guest PC 0x0c05ae3c */
if(!s->budget--) { s->failed_pc=0x0c05ae3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05af2au,2);
goto P_0c05ae3e;
P_0c05ae3e: /* original d33e, guest PC 0x0c05ae3e */
if(!s->budget--) { s->failed_pc=0x0c05ae3eu; return 0; }
r[3]=read(ram,0x0c05af38u,4);
goto P_0c05ae40;
P_0c05ae40: /* original 430b, guest PC 0x0c05ae40 */
if(!s->budget--) { s->failed_pc=0x0c05ae40u; return 0; }
target=r[3];
r[16]=code_base|0x0c05ae44u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05ae44u) { target=s->pc; goto dispatch; }
goto P_0c05ae44;
P_0c05ae42: /* original 0009, guest PC 0x0c05ae42 */
if(!s->budget--) { s->failed_pc=0x0c05ae42u; return 0; }
goto P_0c05ae44;
P_0c05ae44: /* original e000, guest PC 0x0c05ae44 */
if(!s->budget--) { s->failed_pc=0x0c05ae44u; return 0; }
r[0]=0x00000000u;
goto P_0c05ae46;
P_0c05ae46: /* original 9171, guest PC 0x0c05ae46 */
if(!s->budget--) { s->failed_pc=0x0c05ae46u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05af2cu,2);
goto P_0c05ae48;
P_0c05ae48: /* original 3f1c, guest PC 0x0c05ae48 */
if(!s->budget--) { s->failed_pc=0x0c05ae48u; return 0; }
r[15]+=r[1];
goto P_0c05ae4a;
P_0c05ae4a: /* original 4f26, guest PC 0x0c05ae4a */
if(!s->budget--) { s->failed_pc=0x0c05ae4au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05ae4c;
P_0c05ae4c: /* original 6af6, guest PC 0x0c05ae4c */
if(!s->budget--) { s->failed_pc=0x0c05ae4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05ae4e;
P_0c05ae4e: /* original 6bf6, guest PC 0x0c05ae4e */
if(!s->budget--) { s->failed_pc=0x0c05ae4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05ae50;
P_0c05ae50: /* original 6cf6, guest PC 0x0c05ae50 */
if(!s->budget--) { s->failed_pc=0x0c05ae50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05ae52;
P_0c05ae52: /* original 6df6, guest PC 0x0c05ae52 */
if(!s->budget--) { s->failed_pc=0x0c05ae52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05ae54;
P_0c05ae54: /* original 000b, guest PC 0x0c05ae54 */
if(!s->budget--) { s->failed_pc=0x0c05ae54u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05ae56: /* original 6ef6, guest PC 0x0c05ae56 */
if(!s->budget--) { s->failed_pc=0x0c05ae56u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c05ae58;
P_0c05ae58: /* original 2fe6, guest PC 0x0c05ae58 */
if(!s->budget--) { s->failed_pc=0x0c05ae58u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ae5a;
P_0c05ae5a: /* original 4f22, guest PC 0x0c05ae5a */
if(!s->budget--) { s->failed_pc=0x0c05ae5au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05ae5c;
P_0c05ae5c: /* original d237, guest PC 0x0c05ae5c */
if(!s->budget--) { s->failed_pc=0x0c05ae5cu; return 0; }
r[2]=read(ram,0x0c05af3cu,4);
goto P_0c05ae5e;
P_0c05ae5e: /* original 7fe8, guest PC 0x0c05ae5e */
if(!s->budget--) { s->failed_pc=0x0c05ae5eu; return 0; }
r[15]+=0xffffffe8u;
goto P_0c05ae60;
P_0c05ae60: /* original d337, guest PC 0x0c05ae60 */
if(!s->budget--) { s->failed_pc=0x0c05ae60u; return 0; }
r[3]=read(ram,0x0c05af40u,4);
goto P_0c05ae62;
P_0c05ae62: /* original 67f3, guest PC 0x0c05ae62 */
if(!s->budget--) { s->failed_pc=0x0c05ae62u; return 0; }
r[7]=r[15];
goto P_0c05ae64;
P_0c05ae64: /* original 61f3, guest PC 0x0c05ae64 */
if(!s->budget--) { s->failed_pc=0x0c05ae64u; return 0; }
r[1]=r[15];
goto P_0c05ae66;
P_0c05ae66: /* original 430b, guest PC 0x0c05ae66 */
if(!s->budget--) { s->failed_pc=0x0c05ae66u; return 0; }
target=r[3];
r[16]=code_base|0x0c05ae6au;
r[0]=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05ae6au) { target=s->pc; goto dispatch; }
goto P_0c05ae6a;
P_0c05ae68: /* original e018, guest PC 0x0c05ae68 */
if(!s->budget--) { s->failed_pc=0x0c05ae68u; return 0; }
r[0]=0x00000018u;
goto P_0c05ae6a;
P_0c05ae6a: /* original d136, guest PC 0x0c05ae6a */
if(!s->budget--) { s->failed_pc=0x0c05ae6au; return 0; }
r[1]=read(ram,0x0c05af44u,4);
goto P_0c05ae6c;
P_0c05ae6c: /* original 6012, guest PC 0x0c05ae6c */
if(!s->budget--) { s->failed_pc=0x0c05ae6cu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05ae6e;
P_0c05ae6e: /* original 8801, guest PC 0x0c05ae6e */
if(!s->budget--) { s->failed_pc=0x0c05ae6eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05ae70;
P_0c05ae70: /* original 8903, guest PC 0x0c05ae70 */
if(!s->budget--) { s->failed_pc=0x0c05ae70u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ae7a; }
goto P_0c05ae72;
P_0c05ae72: /* original d335, guest PC 0x0c05ae72 */
if(!s->budget--) { s->failed_pc=0x0c05ae72u; return 0; }
r[3]=read(ram,0x0c05af48u,4);
goto P_0c05ae74;
P_0c05ae74: /* original 6032, guest PC 0x0c05ae74 */
if(!s->budget--) { s->failed_pc=0x0c05ae74u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05ae76;
P_0c05ae76: /* original c810, guest PC 0x0c05ae76 */
if(!s->budget--) { s->failed_pc=0x0c05ae76u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c05ae78;
P_0c05ae78: /* original 8902, guest PC 0x0c05ae78 */
if(!s->budget--) { s->failed_pc=0x0c05ae78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ae80; }
goto P_0c05ae7a;
P_0c05ae7a: /* original 9e58, guest PC 0x0c05ae7a */
if(!s->budget--) { s->failed_pc=0x0c05ae7au; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05af2eu,2);
goto P_0c05ae7c;
P_0c05ae7c: /* original a001, guest PC 0x0c05ae7c */
if(!s->budget--) { s->failed_pc=0x0c05ae7cu; return 0; }
goto P_0c05ae82;
P_0c05ae7e: /* original 0009, guest PC 0x0c05ae7e */
if(!s->budget--) { s->failed_pc=0x0c05ae7eu; return 0; }
goto P_0c05ae80;
P_0c05ae80: /* original 9e56, guest PC 0x0c05ae80 */
if(!s->budget--) { s->failed_pc=0x0c05ae80u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05af30u,2);
goto P_0c05ae82;
P_0c05ae82: /* original 6053, guest PC 0x0c05ae82 */
if(!s->budget--) { s->failed_pc=0x0c05ae82u; return 0; }
r[0]=r[5];
goto P_0c05ae84;
P_0c05ae84: /* original 0009, guest PC 0x0c05ae84 */
if(!s->budget--) { s->failed_pc=0x0c05ae84u; return 0; }
goto P_0c05ae86;
P_0c05ae86: /* original 8801, guest PC 0x0c05ae86 */
if(!s->budget--) { s->failed_pc=0x0c05ae86u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05ae88;
P_0c05ae88: /* original 8b14, guest PC 0x0c05ae88 */
if(!s->budget--) { s->failed_pc=0x0c05ae88u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05aeb4; }
goto P_0c05ae8a;
P_0c05ae8a: /* original 761f, guest PC 0x0c05ae8a */
if(!s->budget--) { s->failed_pc=0x0c05ae8au; return 0; }
r[6]+=0x0000001fu;
goto P_0c05ae8c;
P_0c05ae8c: /* original d22f, guest PC 0x0c05ae8c */
if(!s->budget--) { s->failed_pc=0x0c05ae8cu; return 0; }
r[2]=read(ram,0x0c05af4cu,4);
goto P_0c05ae8e;
P_0c05ae8e: /* original e3e0, guest PC 0x0c05ae8e */
if(!s->budget--) { s->failed_pc=0x0c05ae8eu; return 0; }
r[3]=0xffffffe0u;
goto P_0c05ae90;
P_0c05ae90: /* original d02f, guest PC 0x0c05ae90 */
if(!s->budget--) { s->failed_pc=0x0c05ae90u; return 0; }
r[0]=read(ram,0x0c05af50u,4);
goto P_0c05ae92;
P_0c05ae92: /* original 2639, guest PC 0x0c05ae92 */
if(!s->budget--) { s->failed_pc=0x0c05ae92u; return 0; }
r[6]&=r[3];
goto P_0c05ae94;
P_0c05ae94: /* original 6102, guest PC 0x0c05ae94 */
if(!s->budget--) { s->failed_pc=0x0c05ae94u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c05ae96;
P_0c05ae96: /* original 2129, guest PC 0x0c05ae96 */
if(!s->budget--) { s->failed_pc=0x0c05ae96u; return 0; }
r[1]&=r[2];
goto P_0c05ae98;
P_0c05ae98: /* original e316, guest PC 0x0c05ae98 */
if(!s->budget--) { s->failed_pc=0x0c05ae98u; return 0; }
r[3]=0x00000016u;
goto P_0c05ae9a;
P_0c05ae9a: /* original 453d, guest PC 0x0c05ae9a */
if(!s->budget--) { s->failed_pc=0x0c05ae9au; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c05ae9c;
P_0c05ae9c: /* original 215b, guest PC 0x0c05ae9c */
if(!s->budget--) { s->failed_pc=0x0c05ae9cu; return 0; }
r[1]|=r[5];
goto P_0c05ae9e;
P_0c05ae9e: /* original 6063, guest PC 0x0c05ae9e */
if(!s->budget--) { s->failed_pc=0x0c05ae9eu; return 0; }
r[0]=r[6];
goto P_0c05aea0;
P_0c05aea0: /* original 0009, guest PC 0x0c05aea0 */
if(!s->budget--) { s->failed_pc=0x0c05aea0u; return 0; }
goto P_0c05aea2;
P_0c05aea2: /* original 4009, guest PC 0x0c05aea2 */
if(!s->budget--) { s->failed_pc=0x0c05aea2u; return 0; }
r[0]>>=2;
goto P_0c05aea4;
P_0c05aea4: /* original 4009, guest PC 0x0c05aea4 */
if(!s->budget--) { s->failed_pc=0x0c05aea4u; return 0; }
r[0]>>=2;
goto P_0c05aea6;
P_0c05aea6: /* original 4001, guest PC 0x0c05aea6 */
if(!s->budget--) { s->failed_pc=0x0c05aea6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c05aea8;
P_0c05aea8: /* original c91f, guest PC 0x0c05aea8 */
if(!s->budget--) { s->failed_pc=0x0c05aea8u; return 0; }
r[0]&=31u;
goto P_0c05aeaa;
P_0c05aeaa: /* original 4028, guest PC 0x0c05aeaa */
if(!s->budget--) { s->failed_pc=0x0c05aeaau; return 0; }
r[0]<<=16;
goto P_0c05aeac;
P_0c05aeac: /* original 210b, guest PC 0x0c05aeac */
if(!s->budget--) { s->failed_pc=0x0c05aeacu; return 0; }
r[1]|=r[0];
goto P_0c05aeae;
P_0c05aeae: /* original d028, guest PC 0x0c05aeae */
if(!s->budget--) { s->failed_pc=0x0c05aeaeu; return 0; }
r[0]=read(ram,0x0c05af50u,4);
goto P_0c05aeb0;
P_0c05aeb0: /* original a019, guest PC 0x0c05aeb0 */
if(!s->budget--) { s->failed_pc=0x0c05aeb0u; return 0; }
write(ram,r[0],r[1],4);
goto P_0c05aee6;
P_0c05aeb2: /* original 2012, guest PC 0x0c05aeb2 */
if(!s->budget--) { s->failed_pc=0x0c05aeb2u; return 0; }
write(ram,r[0],r[1],4);
goto P_0c05aeb4;
P_0c05aeb4: /* original d223, guest PC 0x0c05aeb4 */
if(!s->budget--) { s->failed_pc=0x0c05aeb4u; return 0; }
r[2]=read(ram,0x0c05af44u,4);
goto P_0c05aeb6;
P_0c05aeb6: /* original 6022, guest PC 0x0c05aeb6 */
if(!s->budget--) { s->failed_pc=0x0c05aeb6u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05aeb8;
P_0c05aeb8: /* original 8801, guest PC 0x0c05aeb8 */
if(!s->budget--) { s->failed_pc=0x0c05aeb8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05aeba;
P_0c05aeba: /* original 8910, guest PC 0x0c05aeba */
if(!s->budget--) { s->failed_pc=0x0c05aebau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05aede; }
goto P_0c05aebc;
P_0c05aebc: /* original d322, guest PC 0x0c05aebc */
if(!s->budget--) { s->failed_pc=0x0c05aebcu; return 0; }
r[3]=read(ram,0x0c05af48u,4);
goto P_0c05aebe;
P_0c05aebe: /* original e501, guest PC 0x0c05aebe */
if(!s->budget--) { s->failed_pc=0x0c05aebeu; return 0; }
r[5]=0x00000001u;
goto P_0c05aec0;
P_0c05aec0: /* original 6032, guest PC 0x0c05aec0 */
if(!s->budget--) { s->failed_pc=0x0c05aec0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05aec2;
P_0c05aec2: /* original 2059, guest PC 0x0c05aec2 */
if(!s->budget--) { s->failed_pc=0x0c05aec2u; return 0; }
r[0]&=r[5];
goto P_0c05aec4;
P_0c05aec4: /* original 8801, guest PC 0x0c05aec4 */
if(!s->budget--) { s->failed_pc=0x0c05aec4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05aec6;
P_0c05aec6: /* original 8906, guest PC 0x0c05aec6 */
if(!s->budget--) { s->failed_pc=0x0c05aec6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05aed6; }
goto P_0c05aec8;
P_0c05aec8: /* original d11f, guest PC 0x0c05aec8 */
if(!s->budget--) { s->failed_pc=0x0c05aec8u; return 0; }
r[1]=read(ram,0x0c05af48u,4);
goto P_0c05aeca;
P_0c05aeca: /* original 6012, guest PC 0x0c05aeca */
if(!s->budget--) { s->failed_pc=0x0c05aecau; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05aecc;
P_0c05aecc: /* original c92c, guest PC 0x0c05aecc */
if(!s->budget--) { s->failed_pc=0x0c05aeccu; return 0; }
r[0]&=44u;
goto P_0c05aece;
P_0c05aece: /* original 8820, guest PC 0x0c05aece */
if(!s->budget--) { s->failed_pc=0x0c05aeceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c05aed0;
P_0c05aed0: /* original 8b01, guest PC 0x0c05aed0 */
if(!s->budget--) { s->failed_pc=0x0c05aed0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05aed6; }
goto P_0c05aed2;
P_0c05aed2: /* original 2558, guest PC 0x0c05aed2 */
if(!s->budget--) { s->failed_pc=0x0c05aed2u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c05aed4;
P_0c05aed4: /* original 8b06, guest PC 0x0c05aed4 */
if(!s->budget--) { s->failed_pc=0x0c05aed4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05aee4; }
goto P_0c05aed6;
P_0c05aed6: /* original d31c, guest PC 0x0c05aed6 */
if(!s->budget--) { s->failed_pc=0x0c05aed6u; return 0; }
r[3]=read(ram,0x0c05af48u,4);
goto P_0c05aed8;
P_0c05aed8: /* original 6032, guest PC 0x0c05aed8 */
if(!s->budget--) { s->failed_pc=0x0c05aed8u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05aeda;
P_0c05aeda: /* original c820, guest PC 0x0c05aeda */
if(!s->budget--) { s->failed_pc=0x0c05aedau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c05aedc;
P_0c05aedc: /* original 8902, guest PC 0x0c05aedc */
if(!s->budget--) { s->failed_pc=0x0c05aedcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05aee4; }
goto P_0c05aede;
P_0c05aede: /* original 9628, guest PC 0x0c05aede */
if(!s->budget--) { s->failed_pc=0x0c05aedeu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05af32u,2);
goto P_0c05aee0;
P_0c05aee0: /* original a001, guest PC 0x0c05aee0 */
if(!s->budget--) { s->failed_pc=0x0c05aee0u; return 0; }
goto P_0c05aee6;
P_0c05aee2: /* original 0009, guest PC 0x0c05aee2 */
if(!s->budget--) { s->failed_pc=0x0c05aee2u; return 0; }
goto P_0c05aee4;
P_0c05aee4: /* original 9626, guest PC 0x0c05aee4 */
if(!s->budget--) { s->failed_pc=0x0c05aee4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05af34u,2);
goto P_0c05aee6;
P_0c05aee6: /* original e048, guest PC 0x0c05aee6 */
if(!s->budget--) { s->failed_pc=0x0c05aee6u; return 0; }
r[0]=0x00000048u;
goto P_0c05aee8;
P_0c05aee8: /* original 9325, guest PC 0x0c05aee8 */
if(!s->budget--) { s->failed_pc=0x0c05aee8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05af36u,2);
goto P_0c05aeea;
P_0c05aeea: /* original d51a, guest PC 0x0c05aeea */
if(!s->budget--) { s->failed_pc=0x0c05aeeau; return 0; }
r[5]=read(ram,0x0c05af54u,4);
goto P_0c05aeec;
P_0c05aeec: /* original 05e6, guest PC 0x0c05aeec */
if(!s->budget--) { s->failed_pc=0x0c05aeecu; return 0; }
write(ram,r[5]+r[0],r[14],4);
goto P_0c05aeee;
P_0c05aeee: /* original e04c, guest PC 0x0c05aeee */
if(!s->budget--) { s->failed_pc=0x0c05aeeeu; return 0; }
r[0]=0x0000004cu;
goto P_0c05aef0;
P_0c05aef0: /* original 3430, guest PC 0x0c05aef0 */
if(!s->budget--) { s->failed_pc=0x0c05aef0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c05aef2;
P_0c05aef2: /* original 8d02, guest PC 0x0c05aef2 */
if(!s->budget--) { s->failed_pc=0x0c05aef2u; return 0; }
cond=r[17]&1u;
write(ram,r[5]+r[0],r[6],4);
if(cond) { goto P_0c05aefa; }
goto P_0c05aef6;
P_0c05aef4: /* original 0566, guest PC 0x0c05aef4 */
if(!s->budget--) { s->failed_pc=0x0c05aef4u; return 0; }
write(ram,r[5]+r[0],r[6],4);
goto P_0c05aef6;
P_0c05aef6: /* original a002, guest PC 0x0c05aef6 */
if(!s->budget--) { s->failed_pc=0x0c05aef6u; return 0; }
r[0]=r[4];
goto P_0c05aefe;
P_0c05aef8: /* original 6043, guest PC 0x0c05aef8 */
if(!s->budget--) { s->failed_pc=0x0c05aef8u; return 0; }
r[0]=r[4];
goto P_0c05aefa;
P_0c05aefa: /* original d117, guest PC 0x0c05aefa */
if(!s->budget--) { s->failed_pc=0x0c05aefau; return 0; }
r[1]=read(ram,0x0c05af58u,4);
goto P_0c05aefc;
P_0c05aefc: /* original 6012, guest PC 0x0c05aefc */
if(!s->budget--) { s->failed_pc=0x0c05aefcu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05aefe;
P_0c05aefe: /* original 4008, guest PC 0x0c05aefe */
if(!s->budget--) { s->failed_pc=0x0c05aefeu; return 0; }
r[0]<<=2;
goto P_0c05af00;
P_0c05af00: /* original 027e, guest PC 0x0c05af00 */
if(!s->budget--) { s->failed_pc=0x0c05af00u; return 0; }
r[2]=read(ram,r[7]+r[0],4);
goto P_0c05af02;
P_0c05af02: /* original e050, guest PC 0x0c05af02 */
if(!s->budget--) { s->failed_pc=0x0c05af02u; return 0; }
r[0]=0x00000050u;
goto P_0c05af04;
P_0c05af04: /* original 4209, guest PC 0x0c05af04 */
if(!s->budget--) { s->failed_pc=0x0c05af04u; return 0; }
r[2]>>=2;
goto P_0c05af06;
P_0c05af06: /* original 4201, guest PC 0x0c05af06 */
if(!s->budget--) { s->failed_pc=0x0c05af06u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]>>=1;
goto P_0c05af08;
P_0c05af08: /* original 0526, guest PC 0x0c05af08 */
if(!s->budget--) { s->failed_pc=0x0c05af08u; return 0; }
write(ram,r[5]+r[0],r[2],4);
goto P_0c05af0a;
P_0c05af0a: /* original e04c, guest PC 0x0c05af0a */
if(!s->budget--) { s->failed_pc=0x0c05af0au; return 0; }
r[0]=0x0000004cu;
goto P_0c05af0c;
P_0c05af0c: /* original 035e, guest PC 0x0c05af0c */
if(!s->budget--) { s->failed_pc=0x0c05af0cu; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c05af0e;
P_0c05af0e: /* original e048, guest PC 0x0c05af0e */
if(!s->budget--) { s->failed_pc=0x0c05af0eu; return 0; }
r[0]=0x00000048u;
goto P_0c05af10;
P_0c05af10: /* original 025e, guest PC 0x0c05af10 */
if(!s->budget--) { s->failed_pc=0x0c05af10u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c05af12;
P_0c05af12: /* original e050, guest PC 0x0c05af12 */
if(!s->budget--) { s->failed_pc=0x0c05af12u; return 0; }
r[0]=0x00000050u;
goto P_0c05af14;
P_0c05af14: /* original 0237, guest PC 0x0c05af14 */
if(!s->budget--) { s->failed_pc=0x0c05af14u; return 0; }
r[19]=r[2]*r[3];
goto P_0c05af16;
P_0c05af16: /* original 031a, guest PC 0x0c05af16 */
if(!s->budget--) { s->failed_pc=0x0c05af16u; return 0; }
r[3]=r[19];
goto P_0c05af18;
P_0c05af18: /* original 015e, guest PC 0x0c05af18 */
if(!s->budget--) { s->failed_pc=0x0c05af18u; return 0; }
r[1]=read(ram,r[5]+r[0],4);
goto P_0c05af1a;
P_0c05af1a: /* original e060, guest PC 0x0c05af1a */
if(!s->budget--) { s->failed_pc=0x0c05af1au; return 0; }
r[0]=0x00000060u;
goto P_0c05af1c;
P_0c05af1c: /* original 0317, guest PC 0x0c05af1c */
if(!s->budget--) { s->failed_pc=0x0c05af1cu; return 0; }
r[19]=r[3]*r[1];
goto P_0c05af1e;
P_0c05af1e: /* original 031a, guest PC 0x0c05af1e */
if(!s->budget--) { s->failed_pc=0x0c05af1eu; return 0; }
r[3]=r[19];
goto P_0c05af20;
P_0c05af20: /* original 0536, guest PC 0x0c05af20 */
if(!s->budget--) { s->failed_pc=0x0c05af20u; return 0; }
write(ram,r[5]+r[0],r[3],4);
goto P_0c05af22;
P_0c05af22: /* original 7f18, guest PC 0x0c05af22 */
if(!s->budget--) { s->failed_pc=0x0c05af22u; return 0; }
r[15]+=0x00000018u;
goto P_0c05af24;
P_0c05af24: /* original 4f26, guest PC 0x0c05af24 */
if(!s->budget--) { s->failed_pc=0x0c05af24u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05af26;
P_0c05af26: /* original 000b, guest PC 0x0c05af26 */
if(!s->budget--) { s->failed_pc=0x0c05af26u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05af28: /* original 6ef6, guest PC 0x0c05af28 */
if(!s->budget--) { s->failed_pc=0x0c05af28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05af2au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05af2au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
