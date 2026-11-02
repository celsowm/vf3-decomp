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
int vf3_away_batch5_adapter_15(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04ea44u: goto P_0c04ea44;
case 0x0c04ea46u: goto P_0c04ea46;
case 0x0c04ea48u: goto P_0c04ea48;
case 0x0c04ea4au: goto P_0c04ea4a;
case 0x0c04ea4cu: goto P_0c04ea4c;
case 0x0c04ea4eu: goto P_0c04ea4e;
case 0x0c04ea50u: goto P_0c04ea50;
case 0x0c04ea52u: goto P_0c04ea52;
case 0x0c04ea54u: goto P_0c04ea54;
case 0x0c04ea56u: goto P_0c04ea56;
case 0x0c04ea58u: goto P_0c04ea58;
case 0x0c04ea5au: goto P_0c04ea5a;
case 0x0c04ea5cu: goto P_0c04ea5c;
case 0x0c04ea5eu: goto P_0c04ea5e;
case 0x0c04ea60u: goto P_0c04ea60;
case 0x0c04ea62u: goto P_0c04ea62;
case 0x0c04ea64u: goto P_0c04ea64;
case 0x0c04ea66u: goto P_0c04ea66;
case 0x0c04ea68u: goto P_0c04ea68;
case 0x0c04ea6au: goto P_0c04ea6a;
case 0x0c04ea6cu: goto P_0c04ea6c;
case 0x0c04ea6eu: goto P_0c04ea6e;
case 0x0c04ea70u: goto P_0c04ea70;
case 0x0c04ea72u: goto P_0c04ea72;
case 0x0c04ea74u: goto P_0c04ea74;
case 0x0c04ea76u: goto P_0c04ea76;
case 0x0c04ea78u: goto P_0c04ea78;
case 0x0c04ea7au: goto P_0c04ea7a;
case 0x0c04ea7cu: goto P_0c04ea7c;
case 0x0c04ea7eu: goto P_0c04ea7e;
case 0x0c04ea80u: goto P_0c04ea80;
case 0x0c04ea82u: goto P_0c04ea82;
case 0x0c04ea84u: goto P_0c04ea84;
case 0x0c04ea86u: goto P_0c04ea86;
case 0x0c04ea88u: goto P_0c04ea88;
case 0x0c04ea8au: goto P_0c04ea8a;
case 0x0c04ea8cu: goto P_0c04ea8c;
case 0x0c04ea8eu: goto P_0c04ea8e;
case 0x0c04ea90u: goto P_0c04ea90;
case 0x0c04ea92u: goto P_0c04ea92;
case 0x0c04ea94u: goto P_0c04ea94;
case 0x0c04ea96u: goto P_0c04ea96;
case 0x0c04ea98u: goto P_0c04ea98;
case 0x0c04ea9au: goto P_0c04ea9a;
case 0x0c04ea9cu: goto P_0c04ea9c;
case 0x0c04ea9eu: goto P_0c04ea9e;
case 0x0c04eaa0u: goto P_0c04eaa0;
case 0x0c04eaa2u: goto P_0c04eaa2;
case 0x0c04eaa4u: goto P_0c04eaa4;
case 0x0c04eaa6u: goto P_0c04eaa6;
case 0x0c04eaccu: goto P_0c04eacc;
case 0x0c04eaceu: goto P_0c04eace;
case 0x0c04ead0u: goto P_0c04ead0;
case 0x0c04ead2u: goto P_0c04ead2;
case 0x0c04ead4u: goto P_0c04ead4;
case 0x0c04ead6u: goto P_0c04ead6;
case 0x0c04ead8u: goto P_0c04ead8;
case 0x0c04eadau: goto P_0c04eada;
case 0x0c04eadcu: goto P_0c04eadc;
case 0x0c04eadeu: goto P_0c04eade;
case 0x0c04eae0u: goto P_0c04eae0;
case 0x0c04eae2u: goto P_0c04eae2;
case 0x0c04eae4u: goto P_0c04eae4;
case 0x0c04eae6u: goto P_0c04eae6;
case 0x0c04eae8u: goto P_0c04eae8;
case 0x0c04eaeau: goto P_0c04eaea;
case 0x0c04eaecu: goto P_0c04eaec;
case 0x0c04eaeeu: goto P_0c04eaee;
case 0x0c04eaf0u: goto P_0c04eaf0;
case 0x0c04eaf2u: goto P_0c04eaf2;
case 0x0c04eaf4u: goto P_0c04eaf4;
case 0x0c04eaf6u: goto P_0c04eaf6;
case 0x0c04eaf8u: goto P_0c04eaf8;
case 0x0c04eafau: goto P_0c04eafa;
case 0x0c04eafcu: goto P_0c04eafc;
case 0x0c04eafeu: goto P_0c04eafe;
case 0x0c04eb00u: goto P_0c04eb00;
case 0x0c04eb02u: goto P_0c04eb02;
case 0x0c04eb04u: goto P_0c04eb04;
case 0x0c04eb06u: goto P_0c04eb06;
case 0x0c04eb08u: goto P_0c04eb08;
case 0x0c04eb0au: goto P_0c04eb0a;
case 0x0c04eb0cu: goto P_0c04eb0c;
case 0x0c04eb0eu: goto P_0c04eb0e;
case 0x0c04eb10u: goto P_0c04eb10;
case 0x0c04eb12u: goto P_0c04eb12;
case 0x0c04eb14u: goto P_0c04eb14;
case 0x0c04eb16u: goto P_0c04eb16;
case 0x0c04eb18u: goto P_0c04eb18;
case 0x0c04eb1au: goto P_0c04eb1a;
case 0x0c04eb1cu: goto P_0c04eb1c;
case 0x0c04eb1eu: goto P_0c04eb1e;
case 0x0c04eb20u: goto P_0c04eb20;
case 0x0c04eb22u: goto P_0c04eb22;
case 0x0c04eb24u: goto P_0c04eb24;
case 0x0c04eb26u: goto P_0c04eb26;
case 0x0c04eb28u: goto P_0c04eb28;
case 0x0c04eb2au: goto P_0c04eb2a;
case 0x0c04eb2cu: goto P_0c04eb2c;
case 0x0c04eb2eu: goto P_0c04eb2e;
case 0x0c04eb30u: goto P_0c04eb30;
case 0x0c04eb32u: goto P_0c04eb32;
case 0x0c04eb34u: goto P_0c04eb34;
case 0x0c04eb36u: goto P_0c04eb36;
case 0x0c04eb38u: goto P_0c04eb38;
case 0x0c04eb3au: goto P_0c04eb3a;
case 0x0c04eb3cu: goto P_0c04eb3c;
case 0x0c04eb3eu: goto P_0c04eb3e;
case 0x0c04eb40u: goto P_0c04eb40;
case 0x0c04eb42u: goto P_0c04eb42;
case 0x0c04eb44u: goto P_0c04eb44;
case 0x0c04eb46u: goto P_0c04eb46;
case 0x0c04eb48u: goto P_0c04eb48;
case 0x0c04eb4au: goto P_0c04eb4a;
case 0x0c04eb4cu: goto P_0c04eb4c;
case 0x0c04eb4eu: goto P_0c04eb4e;
case 0x0c04eb50u: goto P_0c04eb50;
case 0x0c04eb52u: goto P_0c04eb52;
case 0x0c04eb54u: goto P_0c04eb54;
case 0x0c04eb56u: goto P_0c04eb56;
case 0x0c04eb58u: goto P_0c04eb58;
case 0x0c04eb5au: goto P_0c04eb5a;
case 0x0c04eb5cu: goto P_0c04eb5c;
case 0x0c04eb5eu: goto P_0c04eb5e;
case 0x0c04eb60u: goto P_0c04eb60;
case 0x0c04eb62u: goto P_0c04eb62;
case 0x0c04eb64u: goto P_0c04eb64;
case 0x0c04eb66u: goto P_0c04eb66;
case 0x0c04eb68u: goto P_0c04eb68;
case 0x0c04eb6au: goto P_0c04eb6a;
case 0x0c04eb6cu: goto P_0c04eb6c;
case 0x0c04eb6eu: goto P_0c04eb6e;
case 0x0c04ed80u: goto P_0c04ed80;
case 0x0c04ed82u: goto P_0c04ed82;
case 0x0c04ed84u: goto P_0c04ed84;
case 0x0c04ed86u: goto P_0c04ed86;
case 0x0c04ed88u: goto P_0c04ed88;
case 0x0c04ed8au: goto P_0c04ed8a;
case 0x0c04ed8cu: goto P_0c04ed8c;
case 0x0c04ed8eu: goto P_0c04ed8e;
case 0x0c04ed90u: goto P_0c04ed90;
case 0x0c04ed92u: goto P_0c04ed92;
case 0x0c04ed94u: goto P_0c04ed94;
case 0x0c04ed96u: goto P_0c04ed96;
case 0x0c04ed98u: goto P_0c04ed98;
case 0x0c04ed9au: goto P_0c04ed9a;
case 0x0c04ed9cu: goto P_0c04ed9c;
case 0x0c04ed9eu: goto P_0c04ed9e;
case 0x0c04eda0u: goto P_0c04eda0;
case 0x0c04eda2u: goto P_0c04eda2;
case 0x0c04eda4u: goto P_0c04eda4;
case 0x0c04eda6u: goto P_0c04eda6;
case 0x0c04eda8u: goto P_0c04eda8;
case 0x0c04edaau: goto P_0c04edaa;
case 0x0c04edacu: goto P_0c04edac;
case 0x0c04edaeu: goto P_0c04edae;
case 0x0c04edb0u: goto P_0c04edb0;
case 0x0c04edb2u: goto P_0c04edb2;
case 0x0c04edb4u: goto P_0c04edb4;
case 0x0c04edb6u: goto P_0c04edb6;
case 0x0c04edb8u: goto P_0c04edb8;
case 0x0c04edbau: goto P_0c04edba;
case 0x0c04edbcu: goto P_0c04edbc;
case 0x0c04edbeu: goto P_0c04edbe;
case 0x0c04edc0u: goto P_0c04edc0;
case 0x0c04edc2u: goto P_0c04edc2;
case 0x0c04edc4u: goto P_0c04edc4;
case 0x0c04edc6u: goto P_0c04edc6;
case 0x0c04edc8u: goto P_0c04edc8;
case 0x0c04edcau: goto P_0c04edca;
case 0x0c04edccu: goto P_0c04edcc;
case 0x0c04edceu: goto P_0c04edce;
case 0x0c04edd0u: goto P_0c04edd0;
case 0x0c04edd2u: goto P_0c04edd2;
case 0x0c04edd4u: goto P_0c04edd4;
case 0x0c04edd6u: goto P_0c04edd6;
case 0x0c04edd8u: goto P_0c04edd8;
case 0x0c04eddau: goto P_0c04edda;
case 0x0c04eddcu: goto P_0c04eddc;
case 0x0c04eddeu: goto P_0c04edde;
case 0x0c04ede0u: goto P_0c04ede0;
case 0x0c04ede2u: goto P_0c04ede2;
case 0x0c04ede4u: goto P_0c04ede4;
case 0x0c04ede6u: goto P_0c04ede6;
case 0x0c04ede8u: goto P_0c04ede8;
case 0x0c04edeau: goto P_0c04edea;
case 0x0c04edecu: goto P_0c04edec;
case 0x0c04edeeu: goto P_0c04edee;
case 0x0c04edf0u: goto P_0c04edf0;
case 0x0c04ee2cu: goto P_0c04ee2c;
case 0x0c04ee2eu: goto P_0c04ee2e;
case 0x0c04ee30u: goto P_0c04ee30;
case 0x0c04ee32u: goto P_0c04ee32;
case 0x0c04ee34u: goto P_0c04ee34;
case 0x0c04ee36u: goto P_0c04ee36;
case 0x0c04ee38u: goto P_0c04ee38;
case 0x0c04ee3au: goto P_0c04ee3a;
case 0x0c04ee3cu: goto P_0c04ee3c;
case 0x0c04ee3eu: goto P_0c04ee3e;
case 0x0c04ee40u: goto P_0c04ee40;
case 0x0c04ee42u: goto P_0c04ee42;
case 0x0c04ee44u: goto P_0c04ee44;
case 0x0c04ee46u: goto P_0c04ee46;
case 0x0c04ee48u: goto P_0c04ee48;
case 0x0c04ee4au: goto P_0c04ee4a;
case 0x0c04ee4cu: goto P_0c04ee4c;
case 0x0c04ee4eu: goto P_0c04ee4e;
case 0x0c04ee50u: goto P_0c04ee50;
case 0x0c04ee52u: goto P_0c04ee52;
case 0x0c04ee54u: goto P_0c04ee54;
case 0x0c04ee56u: goto P_0c04ee56;
case 0x0c04ee58u: goto P_0c04ee58;
case 0x0c04ee5au: goto P_0c04ee5a;
case 0x0c04ee5cu: goto P_0c04ee5c;
case 0x0c04ee5eu: goto P_0c04ee5e;
case 0x0c04ee60u: goto P_0c04ee60;
case 0x0c04ee62u: goto P_0c04ee62;
case 0x0c04ee64u: goto P_0c04ee64;
case 0x0c04ee66u: goto P_0c04ee66;
case 0x0c04ee68u: goto P_0c04ee68;
case 0x0c04ee6au: goto P_0c04ee6a;
case 0x0c04ee6cu: goto P_0c04ee6c;
case 0x0c04ee6eu: goto P_0c04ee6e;
case 0x0c04ee70u: goto P_0c04ee70;
case 0x0c04ee72u: goto P_0c04ee72;
case 0x0c04ee74u: goto P_0c04ee74;
case 0x0c04ee76u: goto P_0c04ee76;
case 0x0c04ee78u: goto P_0c04ee78;
case 0x0c04ee7au: goto P_0c04ee7a;
case 0x0c04ee7cu: goto P_0c04ee7c;
case 0x0c04ee7eu: goto P_0c04ee7e;
case 0x0c04ee80u: goto P_0c04ee80;
case 0x0c04ee82u: goto P_0c04ee82;
case 0x0c04ee84u: goto P_0c04ee84;
case 0x0c04ee86u: goto P_0c04ee86;
case 0x0c04ee88u: goto P_0c04ee88;
case 0x0c04ee8au: goto P_0c04ee8a;
case 0x0c04ee8cu: goto P_0c04ee8c;
case 0x0c04ee8eu: goto P_0c04ee8e;
case 0x0c04ee90u: goto P_0c04ee90;
case 0x0c04ee92u: goto P_0c04ee92;
case 0x0c04ee94u: goto P_0c04ee94;
case 0x0c04ee96u: goto P_0c04ee96;
case 0x0c04ee98u: goto P_0c04ee98;
case 0x0c04ee9au: goto P_0c04ee9a;
case 0x0c04ee9cu: goto P_0c04ee9c;
case 0x0c04ee9eu: goto P_0c04ee9e;
case 0x0c04eea0u: goto P_0c04eea0;
case 0x0c04eea2u: goto P_0c04eea2;
case 0x0c04eea4u: goto P_0c04eea4;
case 0x0c04eea6u: goto P_0c04eea6;
case 0x0c04eea8u: goto P_0c04eea8;
case 0x0c04eeaau: goto P_0c04eeaa;
case 0x0c04eeacu: goto P_0c04eeac;
case 0x0c04eeaeu: goto P_0c04eeae;
case 0x0c04eeb0u: goto P_0c04eeb0;
case 0x0c04eeb2u: goto P_0c04eeb2;
case 0x0c04eeb4u: goto P_0c04eeb4;
case 0x0c04eeb6u: goto P_0c04eeb6;
case 0x0c04eeb8u: goto P_0c04eeb8;
case 0x0c04eebau: goto P_0c04eeba;
case 0x0c04eebcu: goto P_0c04eebc;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04ea44: /* original 2fe6, guest PC 0x0c04ea44 */
if(!s->budget--) { s->failed_pc=0x0c04ea44u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ea46;
P_0c04ea46: /* original 6e43, guest PC 0x0c04ea46 */
if(!s->budget--) { s->failed_pc=0x0c04ea46u; return 0; }
r[14]=r[4];
goto P_0c04ea48;
P_0c04ea48: /* original 2fd6, guest PC 0x0c04ea48 */
if(!s->budget--) { s->failed_pc=0x0c04ea48u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ea4a;
P_0c04ea4a: /* original 2fc6, guest PC 0x0c04ea4a */
if(!s->budget--) { s->failed_pc=0x0c04ea4au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ea4c;
P_0c04ea4c: /* original 6c63, guest PC 0x0c04ea4c */
if(!s->budget--) { s->failed_pc=0x0c04ea4cu; return 0; }
r[12]=r[6];
goto P_0c04ea4e;
P_0c04ea4e: /* original 2fb6, guest PC 0x0c04ea4e */
if(!s->budget--) { s->failed_pc=0x0c04ea4eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ea50;
P_0c04ea50: /* original 6b53, guest PC 0x0c04ea50 */
if(!s->budget--) { s->failed_pc=0x0c04ea50u; return 0; }
r[11]=r[5];
goto P_0c04ea52;
P_0c04ea52: /* original 4f22, guest PC 0x0c04ea52 */
if(!s->budget--) { s->failed_pc=0x0c04ea52u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04ea54;
P_0c04ea54: /* original 4f12, guest PC 0x0c04ea54 */
if(!s->budget--) { s->failed_pc=0x0c04ea54u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04ea56;
P_0c04ea56: /* original 7fd0, guest PC 0x0c04ea56 */
if(!s->budget--) { s->failed_pc=0x0c04ea56u; return 0; }
r[15]+=0xffffffd0u;
goto P_0c04ea58;
P_0c04ea58: /* original 2f66, guest PC 0x0c04ea58 */
if(!s->budget--) { s->failed_pc=0x0c04ea58u; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ea5a;
P_0c04ea5a: /* original 2fb6, guest PC 0x0c04ea5a */
if(!s->budget--) { s->failed_pc=0x0c04ea5au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ea5c;
P_0c04ea5c: /* original 2fe6, guest PC 0x0c04ea5c */
if(!s->budget--) { s->failed_pc=0x0c04ea5cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ea5e;
P_0c04ea5e: /* original d216, guest PC 0x0c04ea5e */
if(!s->budget--) { s->failed_pc=0x0c04ea5eu; return 0; }
r[2]=read(ram,0x0c04eab8u,4);
goto P_0c04ea60;
P_0c04ea60: /* original d314, guest PC 0x0c04ea60 */
if(!s->budget--) { s->failed_pc=0x0c04ea60u; return 0; }
r[3]=read(ram,0x0c04eab4u,4);
goto P_0c04ea62;
P_0c04ea62: /* original 420b, guest PC 0x0c04ea62 */
if(!s->budget--) { s->failed_pc=0x0c04ea62u; return 0; }
target=r[2];
r[16]=code_base|0x0c04ea66u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04ea66u) { target=s->pc; goto dispatch; }
goto P_0c04ea66;
P_0c04ea64: /* original 2f36, guest PC 0x0c04ea64 */
if(!s->budget--) { s->failed_pc=0x0c04ea64u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ea66;
P_0c04ea66: /* original 9d20, guest PC 0x0c04ea66 */
if(!s->budget--) { s->failed_pc=0x0c04ea66u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04eaaau,2);
goto P_0c04ea68;
P_0c04ea68: /* original 7f10, guest PC 0x0c04ea68 */
if(!s->budget--) { s->failed_pc=0x0c04ea68u; return 0; }
r[15]+=0x00000010u;
goto P_0c04ea6a;
P_0c04ea6a: /* original e201, guest PC 0x0c04ea6a */
if(!s->budget--) { s->failed_pc=0x0c04ea6au; return 0; }
r[2]=0x00000001u;
goto P_0c04ea6c;
P_0c04ea6c: /* original 2edf, guest PC 0x0c04ea6c */
if(!s->budget--) { s->failed_pc=0x0c04ea6cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[13]);
goto P_0c04ea6e;
P_0c04ea6e: /* original 0d1a, guest PC 0x0c04ea6e */
if(!s->budget--) { s->failed_pc=0x0c04ea6eu; return 0; }
r[13]=r[19];
goto P_0c04ea70;
P_0c04ea70: /* original 6ddf, guest PC 0x0c04ea70 */
if(!s->budget--) { s->failed_pc=0x0c04ea70u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c04ea72;
P_0c04ea72: /* original 2fd2, guest PC 0x0c04ea72 */
if(!s->budget--) { s->failed_pc=0x0c04ea72u; return 0; }
write(ram,r[15],r[13],4);
goto P_0c04ea74;
P_0c04ea74: /* original d311, guest PC 0x0c04ea74 */
if(!s->budget--) { s->failed_pc=0x0c04ea74u; return 0; }
r[3]=read(ram,0x0c04eabcu,4);
goto P_0c04ea76;
P_0c04ea76: /* original 3d3c, guest PC 0x0c04ea76 */
if(!s->budget--) { s->failed_pc=0x0c04ea76u; return 0; }
r[13]+=r[3];
goto P_0c04ea78;
P_0c04ea78: /* original 1d2c, guest PC 0x0c04ea78 */
if(!s->budget--) { s->failed_pc=0x0c04ea78u; return 0; }
write(ram,r[13]+48,r[2],4);
goto P_0c04ea7a;
P_0c04ea7a: /* original 51d1, guest PC 0x0c04ea7a */
if(!s->budget--) { s->failed_pc=0x0c04ea7au; return 0; }
r[1]=read(ram,r[13]+4,4);
goto P_0c04ea7c;
P_0c04ea7c: /* original d010, guest PC 0x0c04ea7c */
if(!s->budget--) { s->failed_pc=0x0c04ea7cu; return 0; }
r[0]=read(ram,0x0c04eac0u,4);
goto P_0c04ea7e;
P_0c04ea7e: /* original 6213, guest PC 0x0c04ea7e */
if(!s->budget--) { s->failed_pc=0x0c04ea7eu; return 0; }
r[2]=r[1];
goto P_0c04ea80;
P_0c04ea80: /* original 4108, guest PC 0x0c04ea80 */
if(!s->budget--) { s->failed_pc=0x0c04ea80u; return 0; }
r[1]<<=2;
goto P_0c04ea82;
P_0c04ea82: /* original 312c, guest PC 0x0c04ea82 */
if(!s->budget--) { s->failed_pc=0x0c04ea82u; return 0; }
r[1]+=r[2];
goto P_0c04ea84;
P_0c04ea84: /* original 4108, guest PC 0x0c04ea84 */
if(!s->budget--) { s->failed_pc=0x0c04ea84u; return 0; }
r[1]<<=2;
goto P_0c04ea86;
P_0c04ea86: /* original 4108, guest PC 0x0c04ea86 */
if(!s->budget--) { s->failed_pc=0x0c04ea86u; return 0; }
r[1]<<=2;
goto P_0c04ea88;
P_0c04ea88: /* original 611f, guest PC 0x0c04ea88 */
if(!s->budget--) { s->failed_pc=0x0c04ea88u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[1];
goto P_0c04ea8a;
P_0c04ea8a: /* original 001e, guest PC 0x0c04ea8a */
if(!s->budget--) { s->failed_pc=0x0c04ea8au; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c04ea8c;
P_0c04ea8c: /* original 1d0d, guest PC 0x0c04ea8c */
if(!s->budget--) { s->failed_pc=0x0c04ea8cu; return 0; }
write(ram,r[13]+52,r[0],4);
goto P_0c04ea8e;
P_0c04ea8e: /* original 84d2, guest PC 0x0c04ea8e */
if(!s->budget--) { s->failed_pc=0x0c04ea8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+2,1);
goto P_0c04ea90;
P_0c04ea90: /* original 2008, guest PC 0x0c04ea90 */
if(!s->budget--) { s->failed_pc=0x0c04ea90u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ea92;
P_0c04ea92: /* original 8926, guest PC 0x0c04ea92 */
if(!s->budget--) { s->failed_pc=0x0c04ea92u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04eae2; }
goto P_0c04ea94;
P_0c04ea94: /* original d30b, guest PC 0x0c04ea94 */
if(!s->budget--) { s->failed_pc=0x0c04ea94u; return 0; }
r[3]=read(ram,0x0c04eac4u,4);
goto P_0c04ea96;
P_0c04ea96: /* original 430b, guest PC 0x0c04ea96 */
if(!s->budget--) { s->failed_pc=0x0c04ea96u; return 0; }
target=r[3];
r[16]=code_base|0x0c04ea9au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04ea9au) { target=s->pc; goto dispatch; }
goto P_0c04ea9a;
P_0c04ea98: /* original 64e3, guest PC 0x0c04ea98 */
if(!s->budget--) { s->failed_pc=0x0c04ea98u; return 0; }
r[4]=r[14];
goto P_0c04ea9a;
P_0c04ea9a: /* original 2008, guest PC 0x0c04ea9a */
if(!s->budget--) { s->failed_pc=0x0c04ea9au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ea9c;
P_0c04ea9c: /* original 8b16, guest PC 0x0c04ea9c */
if(!s->budget--) { s->failed_pc=0x0c04ea9cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04eacc; }
goto P_0c04ea9e;
P_0c04ea9e: /* original d30a, guest PC 0x0c04ea9e */
if(!s->budget--) { s->failed_pc=0x0c04ea9eu; return 0; }
r[3]=read(ram,0x0c04eac8u,4);
goto P_0c04eaa0;
P_0c04eaa0: /* original 430b, guest PC 0x0c04eaa0 */
if(!s->budget--) { s->failed_pc=0x0c04eaa0u; return 0; }
target=r[3];
r[16]=code_base|0x0c04eaa4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04eaa4u) { target=s->pc; goto dispatch; }
goto P_0c04eaa4;
P_0c04eaa2: /* original 64e3, guest PC 0x0c04eaa2 */
if(!s->budget--) { s->failed_pc=0x0c04eaa2u; return 0; }
r[4]=r[14];
goto P_0c04eaa4;
P_0c04eaa4: /* original a01d, guest PC 0x0c04eaa4 */
if(!s->budget--) { s->failed_pc=0x0c04eaa4u; return 0; }
goto P_0c04eae2;
P_0c04eaa6: /* original 0009, guest PC 0x0c04eaa6 */
if(!s->budget--) { s->failed_pc=0x0c04eaa6u; return 0; }
if(!vf3_matrix_family(0x0c04eaa8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04eaa8u; return 0; } return 1;
P_0c04eacc: /* original d23f, guest PC 0x0c04eacc */
if(!s->budget--) { s->failed_pc=0x0c04eaccu; return 0; }
r[2]=read(ram,0x0c04ebccu,4);
goto P_0c04eace;
P_0c04eace: /* original 420b, guest PC 0x0c04eace */
if(!s->budget--) { s->failed_pc=0x0c04eaceu; return 0; }
target=r[2];
r[16]=code_base|0x0c04ead2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04ead2u) { target=s->pc; goto dispatch; }
goto P_0c04ead2;
P_0c04ead0: /* original 64e3, guest PC 0x0c04ead0 */
if(!s->budget--) { s->failed_pc=0x0c04ead0u; return 0; }
r[4]=r[14];
goto P_0c04ead2;
P_0c04ead2: /* original 2008, guest PC 0x0c04ead2 */
if(!s->budget--) { s->failed_pc=0x0c04ead2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ead4;
P_0c04ead4: /* original 8905, guest PC 0x0c04ead4 */
if(!s->budget--) { s->failed_pc=0x0c04ead4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04eae2; }
goto P_0c04ead6;
P_0c04ead6: /* original 62f2, guest PC 0x0c04ead6 */
if(!s->budget--) { s->failed_pc=0x0c04ead6u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04ead8;
P_0c04ead8: /* original d33d, guest PC 0x0c04ead8 */
if(!s->budget--) { s->failed_pc=0x0c04ead8u; return 0; }
r[3]=read(ram,0x0c04ebd0u,4);
goto P_0c04eada;
P_0c04eada: /* original 323c, guest PC 0x0c04eada */
if(!s->budget--) { s->failed_pc=0x0c04eadau; return 0; }
r[2]+=r[3];
goto P_0c04eadc;
P_0c04eadc: /* original 8428, guest PC 0x0c04eadc */
if(!s->budget--) { s->failed_pc=0x0c04eadcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04eade;
P_0c04eade: /* original 2008, guest PC 0x0c04eade */
if(!s->budget--) { s->failed_pc=0x0c04eadeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04eae0;
P_0c04eae0: /* original 8b02, guest PC 0x0c04eae0 */
if(!s->budget--) { s->failed_pc=0x0c04eae0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04eae8; }
goto P_0c04eae2;
P_0c04eae2: /* original 906d, guest PC 0x0c04eae2 */
if(!s->budget--) { s->failed_pc=0x0c04eae2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ebc0u,2);
goto P_0c04eae4;
P_0c04eae4: /* original a03c, guest PC 0x0c04eae4 */
if(!s->budget--) { s->failed_pc=0x0c04eae4u; return 0; }
goto P_0c04eb60;
P_0c04eae6: /* original 0009, guest PC 0x0c04eae6 */
if(!s->budget--) { s->failed_pc=0x0c04eae6u; return 0; }
goto P_0c04eae8;
P_0c04eae8: /* original d33a, guest PC 0x0c04eae8 */
if(!s->budget--) { s->failed_pc=0x0c04eae8u; return 0; }
r[3]=read(ram,0x0c04ebd4u,4);
goto P_0c04eaea;
P_0c04eaea: /* original 430b, guest PC 0x0c04eaea */
if(!s->budget--) { s->failed_pc=0x0c04eaeau; return 0; }
target=r[3];
r[16]=code_base|0x0c04eaeeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04eaeeu) { target=s->pc; goto dispatch; }
goto P_0c04eaee;
P_0c04eaec: /* original 64e3, guest PC 0x0c04eaec */
if(!s->budget--) { s->failed_pc=0x0c04eaecu; return 0; }
r[4]=r[14];
goto P_0c04eaee;
P_0c04eaee: /* original 4011, guest PC 0x0c04eaee */
if(!s->budget--) { s->failed_pc=0x0c04eaeeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04eaf0;
P_0c04eaf0: /* original 8902, guest PC 0x0c04eaf0 */
if(!s->budget--) { s->failed_pc=0x0c04eaf0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04eaf8; }
goto P_0c04eaf2;
P_0c04eaf2: /* original 9066, guest PC 0x0c04eaf2 */
if(!s->budget--) { s->failed_pc=0x0c04eaf2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ebc2u,2);
goto P_0c04eaf4;
P_0c04eaf4: /* original a034, guest PC 0x0c04eaf4 */
if(!s->budget--) { s->failed_pc=0x0c04eaf4u; return 0; }
goto P_0c04eb60;
P_0c04eaf6: /* original 0009, guest PC 0x0c04eaf6 */
if(!s->budget--) { s->failed_pc=0x0c04eaf6u; return 0; }
goto P_0c04eaf8;
P_0c04eaf8: /* original d337, guest PC 0x0c04eaf8 */
if(!s->budget--) { s->failed_pc=0x0c04eaf8u; return 0; }
r[3]=read(ram,0x0c04ebd8u,4);
goto P_0c04eafa;
P_0c04eafa: /* original 65b3, guest PC 0x0c04eafa */
if(!s->budget--) { s->failed_pc=0x0c04eafau; return 0; }
r[5]=r[11];
goto P_0c04eafc;
P_0c04eafc: /* original 430b, guest PC 0x0c04eafc */
if(!s->budget--) { s->failed_pc=0x0c04eafcu; return 0; }
target=r[3];
r[16]=code_base|0x0c04eb00u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04eb00u) { target=s->pc; goto dispatch; }
goto P_0c04eb00;
P_0c04eafe: /* original 64e3, guest PC 0x0c04eafe */
if(!s->budget--) { s->failed_pc=0x0c04eafeu; return 0; }
r[4]=r[14];
goto P_0c04eb00;
P_0c04eb00: /* original 4011, guest PC 0x0c04eb00 */
if(!s->budget--) { s->failed_pc=0x0c04eb00u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04eb02;
P_0c04eb02: /* original 8902, guest PC 0x0c04eb02 */
if(!s->budget--) { s->failed_pc=0x0c04eb02u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04eb0a; }
goto P_0c04eb04;
P_0c04eb04: /* original 905e, guest PC 0x0c04eb04 */
if(!s->budget--) { s->failed_pc=0x0c04eb04u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ebc4u,2);
goto P_0c04eb06;
P_0c04eb06: /* original a02b, guest PC 0x0c04eb06 */
if(!s->budget--) { s->failed_pc=0x0c04eb06u; return 0; }
goto P_0c04eb60;
P_0c04eb08: /* original 0009, guest PC 0x0c04eb08 */
if(!s->budget--) { s->failed_pc=0x0c04eb08u; return 0; }
goto P_0c04eb0a;
P_0c04eb0a: /* original 66f3, guest PC 0x0c04eb0a */
if(!s->budget--) { s->failed_pc=0x0c04eb0au; return 0; }
r[6]=r[15];
goto P_0c04eb0c;
P_0c04eb0c: /* original 65b3, guest PC 0x0c04eb0c */
if(!s->budget--) { s->failed_pc=0x0c04eb0cu; return 0; }
r[5]=r[11];
goto P_0c04eb0e;
P_0c04eb0e: /* original 7604, guest PC 0x0c04eb0e */
if(!s->budget--) { s->failed_pc=0x0c04eb0eu; return 0; }
r[6]+=0x00000004u;
goto P_0c04eb10;
P_0c04eb10: /* original b73d, guest PC 0x0c04eb10 */
if(!s->budget--) { s->failed_pc=0x0c04eb10u; return 0; }
target=code_base|0x0c04f98eu; r[16]=code_base|0x0c04eb14u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04eb14u) { target=s->pc; goto dispatch; }
goto P_0c04eb14;
P_0c04eb12: /* original 64e3, guest PC 0x0c04eb12 */
if(!s->budget--) { s->failed_pc=0x0c04eb12u; return 0; }
r[4]=r[14];
goto P_0c04eb14;
P_0c04eb14: /* original 6d03, guest PC 0x0c04eb14 */
if(!s->budget--) { s->failed_pc=0x0c04eb14u; return 0; }
r[13]=r[0];
goto P_0c04eb16;
P_0c04eb16: /* original 4d11, guest PC 0x0c04eb16 */
if(!s->budget--) { s->failed_pc=0x0c04eb16u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=0)!=0);
goto P_0c04eb18;
P_0c04eb18: /* original 8902, guest PC 0x0c04eb18 */
if(!s->budget--) { s->failed_pc=0x0c04eb18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04eb20; }
goto P_0c04eb1a;
P_0c04eb1a: /* original 9054, guest PC 0x0c04eb1a */
if(!s->budget--) { s->failed_pc=0x0c04eb1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ebc6u,2);
goto P_0c04eb1c;
P_0c04eb1c: /* original a020, guest PC 0x0c04eb1c */
if(!s->budget--) { s->failed_pc=0x0c04eb1cu; return 0; }
goto P_0c04eb60;
P_0c04eb1e: /* original 0009, guest PC 0x0c04eb1e */
if(!s->budget--) { s->failed_pc=0x0c04eb1eu; return 0; }
goto P_0c04eb20;
P_0c04eb20: /* original 66f3, guest PC 0x0c04eb20 */
if(!s->budget--) { s->failed_pc=0x0c04eb20u; return 0; }
r[6]=r[15];
goto P_0c04eb22;
P_0c04eb22: /* original 65c3, guest PC 0x0c04eb22 */
if(!s->budget--) { s->failed_pc=0x0c04eb22u; return 0; }
r[5]=r[12];
goto P_0c04eb24;
P_0c04eb24: /* original 7604, guest PC 0x0c04eb24 */
if(!s->budget--) { s->failed_pc=0x0c04eb24u; return 0; }
r[6]+=0x00000004u;
goto P_0c04eb26;
P_0c04eb26: /* original b732, guest PC 0x0c04eb26 */
if(!s->budget--) { s->failed_pc=0x0c04eb26u; return 0; }
target=code_base|0x0c04f98eu; r[16]=code_base|0x0c04eb2au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04eb2au) { target=s->pc; goto dispatch; }
goto P_0c04eb2a;
P_0c04eb28: /* original 64e3, guest PC 0x0c04eb28 */
if(!s->budget--) { s->failed_pc=0x0c04eb28u; return 0; }
r[4]=r[14];
goto P_0c04eb2a;
P_0c04eb2a: /* original 4011, guest PC 0x0c04eb2a */
if(!s->budget--) { s->failed_pc=0x0c04eb2au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04eb2c;
P_0c04eb2c: /* original 8b02, guest PC 0x0c04eb2c */
if(!s->budget--) { s->failed_pc=0x0c04eb2cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04eb34; }
goto P_0c04eb2e;
P_0c04eb2e: /* original 904b, guest PC 0x0c04eb2e */
if(!s->budget--) { s->failed_pc=0x0c04eb2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ebc8u,2);
goto P_0c04eb30;
P_0c04eb30: /* original a016, guest PC 0x0c04eb30 */
if(!s->budget--) { s->failed_pc=0x0c04eb30u; return 0; }
goto P_0c04eb60;
P_0c04eb32: /* original 0009, guest PC 0x0c04eb32 */
if(!s->budget--) { s->failed_pc=0x0c04eb32u; return 0; }
goto P_0c04eb34;
P_0c04eb34: /* original d329, guest PC 0x0c04eb34 */
if(!s->budget--) { s->failed_pc=0x0c04eb34u; return 0; }
r[3]=read(ram,0x0c04ebdcu,4);
goto P_0c04eb36;
P_0c04eb36: /* original 65d3, guest PC 0x0c04eb36 */
if(!s->budget--) { s->failed_pc=0x0c04eb36u; return 0; }
r[5]=r[13];
goto P_0c04eb38;
P_0c04eb38: /* original 430b, guest PC 0x0c04eb38 */
if(!s->budget--) { s->failed_pc=0x0c04eb38u; return 0; }
target=r[3];
r[16]=code_base|0x0c04eb3cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04eb3cu) { target=s->pc; goto dispatch; }
goto P_0c04eb3c;
P_0c04eb3a: /* original 64e3, guest PC 0x0c04eb3a */
if(!s->budget--) { s->failed_pc=0x0c04eb3au; return 0; }
r[4]=r[14];
goto P_0c04eb3c;
P_0c04eb3c: /* original 6403, guest PC 0x0c04eb3c */
if(!s->budget--) { s->failed_pc=0x0c04eb3cu; return 0; }
r[4]=r[0];
goto P_0c04eb3e;
P_0c04eb3e: /* original 7404, guest PC 0x0c04eb3e */
if(!s->budget--) { s->failed_pc=0x0c04eb3eu; return 0; }
r[4]+=0x00000004u;
goto P_0c04eb40;
P_0c04eb40: /* original 67c3, guest PC 0x0c04eb40 */
if(!s->budget--) { s->failed_pc=0x0c04eb40u; return 0; }
r[7]=r[12];
goto P_0c04eb42;
P_0c04eb42: /* original e500, guest PC 0x0c04eb42 */
if(!s->budget--) { s->failed_pc=0x0c04eb42u; return 0; }
r[5]=0x00000000u;
goto P_0c04eb44;
P_0c04eb44: /* original a004, guest PC 0x0c04eb44 */
if(!s->budget--) { s->failed_pc=0x0c04eb44u; return 0; }
r[6]=0x0000000cu;
goto P_0c04eb50;
P_0c04eb46: /* original e60c, guest PC 0x0c04eb46 */
if(!s->budget--) { s->failed_pc=0x0c04eb46u; return 0; }
r[6]=0x0000000cu;
goto P_0c04eb48;
P_0c04eb48: /* original 6374, guest PC 0x0c04eb48 */
if(!s->budget--) { s->failed_pc=0x0c04eb48u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]+=1;
r[3]=tmp;
goto P_0c04eb4a;
P_0c04eb4a: /* original 7501, guest PC 0x0c04eb4a */
if(!s->budget--) { s->failed_pc=0x0c04eb4au; return 0; }
r[5]+=0x00000001u;
goto P_0c04eb4c;
P_0c04eb4c: /* original 2430, guest PC 0x0c04eb4c */
if(!s->budget--) { s->failed_pc=0x0c04eb4cu; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04eb4e;
P_0c04eb4e: /* original 7401, guest PC 0x0c04eb4e */
if(!s->budget--) { s->failed_pc=0x0c04eb4eu; return 0; }
r[4]+=0x00000001u;
goto P_0c04eb50;
P_0c04eb50: /* original 3563, guest PC 0x0c04eb50 */
if(!s->budget--) { s->failed_pc=0x0c04eb50u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c04eb52;
P_0c04eb52: /* original 8bf9, guest PC 0x0c04eb52 */
if(!s->budget--) { s->failed_pc=0x0c04eb52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04eb48; }
goto P_0c04eb54;
P_0c04eb54: /* original d322, guest PC 0x0c04eb54 */
if(!s->budget--) { s->failed_pc=0x0c04eb54u; return 0; }
r[3]=read(ram,0x0c04ebe0u,4);
goto P_0c04eb56;
P_0c04eb56: /* original 65d3, guest PC 0x0c04eb56 */
if(!s->budget--) { s->failed_pc=0x0c04eb56u; return 0; }
r[5]=r[13];
goto P_0c04eb58;
P_0c04eb58: /* original 430b, guest PC 0x0c04eb58 */
if(!s->budget--) { s->failed_pc=0x0c04eb58u; return 0; }
target=r[3];
r[16]=code_base|0x0c04eb5cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04eb5cu) { target=s->pc; goto dispatch; }
goto P_0c04eb5c;
P_0c04eb5a: /* original 64e3, guest PC 0x0c04eb5a */
if(!s->budget--) { s->failed_pc=0x0c04eb5au; return 0; }
r[4]=r[14];
goto P_0c04eb5c;
P_0c04eb5c: /* original b5f7, guest PC 0x0c04eb5c */
if(!s->budget--) { s->failed_pc=0x0c04eb5cu; return 0; }
target=code_base|0x0c04f74eu; r[16]=code_base|0x0c04eb60u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04eb60u) { target=s->pc; goto dispatch; }
goto P_0c04eb60;
P_0c04eb5e: /* original 64e3, guest PC 0x0c04eb5e */
if(!s->budget--) { s->failed_pc=0x0c04eb5eu; return 0; }
r[4]=r[14];
goto P_0c04eb60;
P_0c04eb60: /* original 7f30, guest PC 0x0c04eb60 */
if(!s->budget--) { s->failed_pc=0x0c04eb60u; return 0; }
r[15]+=0x00000030u;
goto P_0c04eb62;
P_0c04eb62: /* original 4f16, guest PC 0x0c04eb62 */
if(!s->budget--) { s->failed_pc=0x0c04eb62u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04eb64;
P_0c04eb64: /* original 4f26, guest PC 0x0c04eb64 */
if(!s->budget--) { s->failed_pc=0x0c04eb64u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04eb66;
P_0c04eb66: /* original 6bf6, guest PC 0x0c04eb66 */
if(!s->budget--) { s->failed_pc=0x0c04eb66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04eb68;
P_0c04eb68: /* original 6cf6, guest PC 0x0c04eb68 */
if(!s->budget--) { s->failed_pc=0x0c04eb68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04eb6a;
P_0c04eb6a: /* original 6df6, guest PC 0x0c04eb6a */
if(!s->budget--) { s->failed_pc=0x0c04eb6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04eb6c;
P_0c04eb6c: /* original 000b, guest PC 0x0c04eb6c */
if(!s->budget--) { s->failed_pc=0x0c04eb6cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04eb6e: /* original 6ef6, guest PC 0x0c04eb6e */
if(!s->budget--) { s->failed_pc=0x0c04eb6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04eb70u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04eb70u; return 0; } return 1;
P_0c04ed80: /* original 2fe6, guest PC 0x0c04ed80 */
if(!s->budget--) { s->failed_pc=0x0c04ed80u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ed82;
P_0c04ed82: /* original 6073, guest PC 0x0c04ed82 */
if(!s->budget--) { s->failed_pc=0x0c04ed82u; return 0; }
r[0]=r[7];
goto P_0c04ed84;
P_0c04ed84: /* original 2fd6, guest PC 0x0c04ed84 */
if(!s->budget--) { s->failed_pc=0x0c04ed84u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ed86;
P_0c04ed86: /* original 6e43, guest PC 0x0c04ed86 */
if(!s->budget--) { s->failed_pc=0x0c04ed86u; return 0; }
r[14]=r[4];
goto P_0c04ed88;
P_0c04ed88: /* original 2fc6, guest PC 0x0c04ed88 */
if(!s->budget--) { s->failed_pc=0x0c04ed88u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ed8a;
P_0c04ed8a: /* original 6c53, guest PC 0x0c04ed8a */
if(!s->budget--) { s->failed_pc=0x0c04ed8au; return 0; }
r[12]=r[5];
goto P_0c04ed8c;
P_0c04ed8c: /* original 4f22, guest PC 0x0c04ed8c */
if(!s->budget--) { s->failed_pc=0x0c04ed8cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04ed8e;
P_0c04ed8e: /* original 4f12, guest PC 0x0c04ed8e */
if(!s->budget--) { s->failed_pc=0x0c04ed8eu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04ed90;
P_0c04ed90: /* original 7fc8, guest PC 0x0c04ed90 */
if(!s->budget--) { s->failed_pc=0x0c04ed90u; return 0; }
r[15]+=0xffffffc8u;
goto P_0c04ed92;
P_0c04ed92: /* original 2f61, guest PC 0x0c04ed92 */
if(!s->budget--) { s->failed_pc=0x0c04ed92u; return 0; }
write(ram,r[15],r[6],2);
goto P_0c04ed94;
P_0c04ed94: /* original 80f4, guest PC 0x0c04ed94 */
if(!s->budget--) { s->failed_pc=0x0c04ed94u; return 0; }
write(ram,r[15]+4,r[0],1);
goto P_0c04ed96;
P_0c04ed96: /* original 84f4, guest PC 0x0c04ed96 */
if(!s->budget--) { s->failed_pc=0x0c04ed96u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c04ed98;
P_0c04ed98: /* original 600c, guest PC 0x0c04ed98 */
if(!s->budget--) { s->failed_pc=0x0c04ed98u; return 0; }
r[0]=r[0]&255u;
goto P_0c04ed9a;
P_0c04ed9a: /* original 2f06, guest PC 0x0c04ed9a */
if(!s->budget--) { s->failed_pc=0x0c04ed9au; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ed9c;
P_0c04ed9c: /* original 85f2, guest PC 0x0c04ed9c */
if(!s->budget--) { s->failed_pc=0x0c04ed9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c04ed9e;
P_0c04ed9e: /* original 6303, guest PC 0x0c04ed9e */
if(!s->budget--) { s->failed_pc=0x0c04ed9eu; return 0; }
r[3]=r[0];
goto P_0c04eda0;
P_0c04eda0: /* original 633d, guest PC 0x0c04eda0 */
if(!s->budget--) { s->failed_pc=0x0c04eda0u; return 0; }
r[3]=r[3]&65535u;
goto P_0c04eda2;
P_0c04eda2: /* original 2f36, guest PC 0x0c04eda2 */
if(!s->budget--) { s->failed_pc=0x0c04eda2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04eda4;
P_0c04eda4: /* original 2fc6, guest PC 0x0c04eda4 */
if(!s->budget--) { s->failed_pc=0x0c04eda4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04eda6;
P_0c04eda6: /* original 2fe6, guest PC 0x0c04eda6 */
if(!s->budget--) { s->failed_pc=0x0c04eda6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04eda8;
P_0c04eda8: /* original d31a, guest PC 0x0c04eda8 */
if(!s->budget--) { s->failed_pc=0x0c04eda8u; return 0; }
r[3]=read(ram,0x0c04ee14u,4);
goto P_0c04edaa;
P_0c04edaa: /* original d21b, guest PC 0x0c04edaa */
if(!s->budget--) { s->failed_pc=0x0c04edaau; return 0; }
r[2]=read(ram,0x0c04ee18u,4);
goto P_0c04edac;
P_0c04edac: /* original 420b, guest PC 0x0c04edac */
if(!s->budget--) { s->failed_pc=0x0c04edacu; return 0; }
target=r[2];
r[16]=code_base|0x0c04edb0u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04edb0u) { target=s->pc; goto dispatch; }
goto P_0c04edb0;
P_0c04edae: /* original 2f36, guest PC 0x0c04edae */
if(!s->budget--) { s->failed_pc=0x0c04edaeu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04edb0;
P_0c04edb0: /* original 9d1f, guest PC 0x0c04edb0 */
if(!s->budget--) { s->failed_pc=0x0c04edb0u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04edf2u,2);
goto P_0c04edb2;
P_0c04edb2: /* original 7f14, guest PC 0x0c04edb2 */
if(!s->budget--) { s->failed_pc=0x0c04edb2u; return 0; }
r[15]+=0x00000014u;
goto P_0c04edb4;
P_0c04edb4: /* original e201, guest PC 0x0c04edb4 */
if(!s->budget--) { s->failed_pc=0x0c04edb4u; return 0; }
r[2]=0x00000001u;
goto P_0c04edb6;
P_0c04edb6: /* original 2edf, guest PC 0x0c04edb6 */
if(!s->budget--) { s->failed_pc=0x0c04edb6u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[13]);
goto P_0c04edb8;
P_0c04edb8: /* original 0d1a, guest PC 0x0c04edb8 */
if(!s->budget--) { s->failed_pc=0x0c04edb8u; return 0; }
r[13]=r[19];
goto P_0c04edba;
P_0c04edba: /* original 6ddf, guest PC 0x0c04edba */
if(!s->budget--) { s->failed_pc=0x0c04edbau; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c04edbc;
P_0c04edbc: /* original 1fd2, guest PC 0x0c04edbc */
if(!s->budget--) { s->failed_pc=0x0c04edbcu; return 0; }
write(ram,r[15]+8,r[13],4);
goto P_0c04edbe;
P_0c04edbe: /* original d317, guest PC 0x0c04edbe */
if(!s->budget--) { s->failed_pc=0x0c04edbeu; return 0; }
r[3]=read(ram,0x0c04ee1cu,4);
goto P_0c04edc0;
P_0c04edc0: /* original 3d3c, guest PC 0x0c04edc0 */
if(!s->budget--) { s->failed_pc=0x0c04edc0u; return 0; }
r[13]+=r[3];
goto P_0c04edc2;
P_0c04edc2: /* original 1d2c, guest PC 0x0c04edc2 */
if(!s->budget--) { s->failed_pc=0x0c04edc2u; return 0; }
write(ram,r[13]+48,r[2],4);
goto P_0c04edc4;
P_0c04edc4: /* original 51d1, guest PC 0x0c04edc4 */
if(!s->budget--) { s->failed_pc=0x0c04edc4u; return 0; }
r[1]=read(ram,r[13]+4,4);
goto P_0c04edc6;
P_0c04edc6: /* original d016, guest PC 0x0c04edc6 */
if(!s->budget--) { s->failed_pc=0x0c04edc6u; return 0; }
r[0]=read(ram,0x0c04ee20u,4);
goto P_0c04edc8;
P_0c04edc8: /* original 6213, guest PC 0x0c04edc8 */
if(!s->budget--) { s->failed_pc=0x0c04edc8u; return 0; }
r[2]=r[1];
goto P_0c04edca;
P_0c04edca: /* original 4108, guest PC 0x0c04edca */
if(!s->budget--) { s->failed_pc=0x0c04edcau; return 0; }
r[1]<<=2;
goto P_0c04edcc;
P_0c04edcc: /* original 312c, guest PC 0x0c04edcc */
if(!s->budget--) { s->failed_pc=0x0c04edccu; return 0; }
r[1]+=r[2];
goto P_0c04edce;
P_0c04edce: /* original 4108, guest PC 0x0c04edce */
if(!s->budget--) { s->failed_pc=0x0c04edceu; return 0; }
r[1]<<=2;
goto P_0c04edd0;
P_0c04edd0: /* original 4108, guest PC 0x0c04edd0 */
if(!s->budget--) { s->failed_pc=0x0c04edd0u; return 0; }
r[1]<<=2;
goto P_0c04edd2;
P_0c04edd2: /* original 611f, guest PC 0x0c04edd2 */
if(!s->budget--) { s->failed_pc=0x0c04edd2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[1];
goto P_0c04edd4;
P_0c04edd4: /* original 001e, guest PC 0x0c04edd4 */
if(!s->budget--) { s->failed_pc=0x0c04edd4u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c04edd6;
P_0c04edd6: /* original 1d0d, guest PC 0x0c04edd6 */
if(!s->budget--) { s->failed_pc=0x0c04edd6u; return 0; }
write(ram,r[13]+52,r[0],4);
goto P_0c04edd8;
P_0c04edd8: /* original 84d2, guest PC 0x0c04edd8 */
if(!s->budget--) { s->failed_pc=0x0c04edd8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+2,1);
goto P_0c04edda;
P_0c04edda: /* original 2008, guest PC 0x0c04edda */
if(!s->budget--) { s->failed_pc=0x0c04eddau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04eddc;
P_0c04eddc: /* original 8931, guest PC 0x0c04eddc */
if(!s->budget--) { s->failed_pc=0x0c04eddcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ee42; }
goto P_0c04edde;
P_0c04edde: /* original d311, guest PC 0x0c04edde */
if(!s->budget--) { s->failed_pc=0x0c04eddeu; return 0; }
r[3]=read(ram,0x0c04ee24u,4);
goto P_0c04ede0;
P_0c04ede0: /* original 430b, guest PC 0x0c04ede0 */
if(!s->budget--) { s->failed_pc=0x0c04ede0u; return 0; }
target=r[3];
r[16]=code_base|0x0c04ede4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04ede4u) { target=s->pc; goto dispatch; }
goto P_0c04ede4;
P_0c04ede2: /* original 64e3, guest PC 0x0c04ede2 */
if(!s->budget--) { s->failed_pc=0x0c04ede2u; return 0; }
r[4]=r[14];
goto P_0c04ede4;
P_0c04ede4: /* original 2008, guest PC 0x0c04ede4 */
if(!s->budget--) { s->failed_pc=0x0c04ede4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ede6;
P_0c04ede6: /* original 8b21, guest PC 0x0c04ede6 */
if(!s->budget--) { s->failed_pc=0x0c04ede6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ee2c; }
goto P_0c04ede8;
P_0c04ede8: /* original d30f, guest PC 0x0c04ede8 */
if(!s->budget--) { s->failed_pc=0x0c04ede8u; return 0; }
r[3]=read(ram,0x0c04ee28u,4);
goto P_0c04edea;
P_0c04edea: /* original 430b, guest PC 0x0c04edea */
if(!s->budget--) { s->failed_pc=0x0c04edeau; return 0; }
target=r[3];
r[16]=code_base|0x0c04edeeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04edeeu) { target=s->pc; goto dispatch; }
goto P_0c04edee;
P_0c04edec: /* original 64e3, guest PC 0x0c04edec */
if(!s->budget--) { s->failed_pc=0x0c04edecu; return 0; }
r[4]=r[14];
goto P_0c04edee;
P_0c04edee: /* original a028, guest PC 0x0c04edee */
if(!s->budget--) { s->failed_pc=0x0c04edeeu; return 0; }
goto P_0c04ee42;
P_0c04edf0: /* original 0009, guest PC 0x0c04edf0 */
if(!s->budget--) { s->failed_pc=0x0c04edf0u; return 0; }
if(!vf3_matrix_family(0x0c04edf2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04edf2u; return 0; } return 1;
P_0c04ee2c: /* original d23a, guest PC 0x0c04ee2c */
if(!s->budget--) { s->failed_pc=0x0c04ee2cu; return 0; }
r[2]=read(ram,0x0c04ef18u,4);
goto P_0c04ee2e;
P_0c04ee2e: /* original 420b, guest PC 0x0c04ee2e */
if(!s->budget--) { s->failed_pc=0x0c04ee2eu; return 0; }
target=r[2];
r[16]=code_base|0x0c04ee32u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04ee32u) { target=s->pc; goto dispatch; }
goto P_0c04ee32;
P_0c04ee30: /* original 64e3, guest PC 0x0c04ee30 */
if(!s->budget--) { s->failed_pc=0x0c04ee30u; return 0; }
r[4]=r[14];
goto P_0c04ee32;
P_0c04ee32: /* original 2008, guest PC 0x0c04ee32 */
if(!s->budget--) { s->failed_pc=0x0c04ee32u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ee34;
P_0c04ee34: /* original 8905, guest PC 0x0c04ee34 */
if(!s->budget--) { s->failed_pc=0x0c04ee34u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ee42; }
goto P_0c04ee36;
P_0c04ee36: /* original 52f2, guest PC 0x0c04ee36 */
if(!s->budget--) { s->failed_pc=0x0c04ee36u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c04ee38;
P_0c04ee38: /* original d338, guest PC 0x0c04ee38 */
if(!s->budget--) { s->failed_pc=0x0c04ee38u; return 0; }
r[3]=read(ram,0x0c04ef1cu,4);
goto P_0c04ee3a;
P_0c04ee3a: /* original 323c, guest PC 0x0c04ee3a */
if(!s->budget--) { s->failed_pc=0x0c04ee3au; return 0; }
r[2]+=r[3];
goto P_0c04ee3c;
P_0c04ee3c: /* original 8428, guest PC 0x0c04ee3c */
if(!s->budget--) { s->failed_pc=0x0c04ee3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04ee3e;
P_0c04ee3e: /* original 2008, guest PC 0x0c04ee3e */
if(!s->budget--) { s->failed_pc=0x0c04ee3eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04ee40;
P_0c04ee40: /* original 8b02, guest PC 0x0c04ee40 */
if(!s->budget--) { s->failed_pc=0x0c04ee40u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ee48; }
goto P_0c04ee42;
P_0c04ee42: /* original 9064, guest PC 0x0c04ee42 */
if(!s->budget--) { s->failed_pc=0x0c04ee42u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ef0eu,2);
goto P_0c04ee44;
P_0c04ee44: /* original a034, guest PC 0x0c04ee44 */
if(!s->budget--) { s->failed_pc=0x0c04ee44u; return 0; }
goto P_0c04eeb0;
P_0c04ee46: /* original 0009, guest PC 0x0c04ee46 */
if(!s->budget--) { s->failed_pc=0x0c04ee46u; return 0; }
goto P_0c04ee48;
P_0c04ee48: /* original d335, guest PC 0x0c04ee48 */
if(!s->budget--) { s->failed_pc=0x0c04ee48u; return 0; }
r[3]=read(ram,0x0c04ef20u,4);
goto P_0c04ee4a;
P_0c04ee4a: /* original 430b, guest PC 0x0c04ee4a */
if(!s->budget--) { s->failed_pc=0x0c04ee4au; return 0; }
target=r[3];
r[16]=code_base|0x0c04ee4eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04ee4eu) { target=s->pc; goto dispatch; }
goto P_0c04ee4e;
P_0c04ee4c: /* original 64e3, guest PC 0x0c04ee4c */
if(!s->budget--) { s->failed_pc=0x0c04ee4cu; return 0; }
r[4]=r[14];
goto P_0c04ee4e;
P_0c04ee4e: /* original 4011, guest PC 0x0c04ee4e */
if(!s->budget--) { s->failed_pc=0x0c04ee4eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04ee50;
P_0c04ee50: /* original 8902, guest PC 0x0c04ee50 */
if(!s->budget--) { s->failed_pc=0x0c04ee50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ee58; }
goto P_0c04ee52;
P_0c04ee52: /* original 905d, guest PC 0x0c04ee52 */
if(!s->budget--) { s->failed_pc=0x0c04ee52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ef10u,2);
goto P_0c04ee54;
P_0c04ee54: /* original a02c, guest PC 0x0c04ee54 */
if(!s->budget--) { s->failed_pc=0x0c04ee54u; return 0; }
goto P_0c04eeb0;
P_0c04ee56: /* original 0009, guest PC 0x0c04ee56 */
if(!s->budget--) { s->failed_pc=0x0c04ee56u; return 0; }
goto P_0c04ee58;
P_0c04ee58: /* original d332, guest PC 0x0c04ee58 */
if(!s->budget--) { s->failed_pc=0x0c04ee58u; return 0; }
r[3]=read(ram,0x0c04ef24u,4);
goto P_0c04ee5a;
P_0c04ee5a: /* original 65c3, guest PC 0x0c04ee5a */
if(!s->budget--) { s->failed_pc=0x0c04ee5au; return 0; }
r[5]=r[12];
goto P_0c04ee5c;
P_0c04ee5c: /* original 430b, guest PC 0x0c04ee5c */
if(!s->budget--) { s->failed_pc=0x0c04ee5cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04ee60u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04ee60u) { target=s->pc; goto dispatch; }
goto P_0c04ee60;
P_0c04ee5e: /* original 64e3, guest PC 0x0c04ee5e */
if(!s->budget--) { s->failed_pc=0x0c04ee5eu; return 0; }
r[4]=r[14];
goto P_0c04ee60;
P_0c04ee60: /* original 4011, guest PC 0x0c04ee60 */
if(!s->budget--) { s->failed_pc=0x0c04ee60u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04ee62;
P_0c04ee62: /* original 8902, guest PC 0x0c04ee62 */
if(!s->budget--) { s->failed_pc=0x0c04ee62u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ee6a; }
goto P_0c04ee64;
P_0c04ee64: /* original 9055, guest PC 0x0c04ee64 */
if(!s->budget--) { s->failed_pc=0x0c04ee64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ef12u,2);
goto P_0c04ee66;
P_0c04ee66: /* original a023, guest PC 0x0c04ee66 */
if(!s->budget--) { s->failed_pc=0x0c04ee66u; return 0; }
goto P_0c04eeb0;
P_0c04ee68: /* original 0009, guest PC 0x0c04ee68 */
if(!s->budget--) { s->failed_pc=0x0c04ee68u; return 0; }
goto P_0c04ee6a;
P_0c04ee6a: /* original 66f3, guest PC 0x0c04ee6a */
if(!s->budget--) { s->failed_pc=0x0c04ee6au; return 0; }
r[6]=r[15];
goto P_0c04ee6c;
P_0c04ee6c: /* original 65c3, guest PC 0x0c04ee6c */
if(!s->budget--) { s->failed_pc=0x0c04ee6cu; return 0; }
r[5]=r[12];
goto P_0c04ee6e;
P_0c04ee6e: /* original 760c, guest PC 0x0c04ee6e */
if(!s->budget--) { s->failed_pc=0x0c04ee6eu; return 0; }
r[6]+=0x0000000cu;
goto P_0c04ee70;
P_0c04ee70: /* original b58d, guest PC 0x0c04ee70 */
if(!s->budget--) { s->failed_pc=0x0c04ee70u; return 0; }
target=code_base|0x0c04f98eu; r[16]=code_base|0x0c04ee74u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04ee74u) { target=s->pc; goto dispatch; }
goto P_0c04ee74;
P_0c04ee72: /* original 64e3, guest PC 0x0c04ee72 */
if(!s->budget--) { s->failed_pc=0x0c04ee72u; return 0; }
r[4]=r[14];
goto P_0c04ee74;
P_0c04ee74: /* original 6d03, guest PC 0x0c04ee74 */
if(!s->budget--) { s->failed_pc=0x0c04ee74u; return 0; }
r[13]=r[0];
goto P_0c04ee76;
P_0c04ee76: /* original 4d11, guest PC 0x0c04ee76 */
if(!s->budget--) { s->failed_pc=0x0c04ee76u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=0)!=0);
goto P_0c04ee78;
P_0c04ee78: /* original 8902, guest PC 0x0c04ee78 */
if(!s->budget--) { s->failed_pc=0x0c04ee78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ee80; }
goto P_0c04ee7a;
P_0c04ee7a: /* original 904b, guest PC 0x0c04ee7a */
if(!s->budget--) { s->failed_pc=0x0c04ee7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ef14u,2);
goto P_0c04ee7c;
P_0c04ee7c: /* original a018, guest PC 0x0c04ee7c */
if(!s->budget--) { s->failed_pc=0x0c04ee7cu; return 0; }
goto P_0c04eeb0;
P_0c04ee7e: /* original 0009, guest PC 0x0c04ee7e */
if(!s->budget--) { s->failed_pc=0x0c04ee7eu; return 0; }
goto P_0c04ee80;
P_0c04ee80: /* original d329, guest PC 0x0c04ee80 */
if(!s->budget--) { s->failed_pc=0x0c04ee80u; return 0; }
r[3]=read(ram,0x0c04ef28u,4);
goto P_0c04ee82;
P_0c04ee82: /* original 65d3, guest PC 0x0c04ee82 */
if(!s->budget--) { s->failed_pc=0x0c04ee82u; return 0; }
r[5]=r[13];
goto P_0c04ee84;
P_0c04ee84: /* original 430b, guest PC 0x0c04ee84 */
if(!s->budget--) { s->failed_pc=0x0c04ee84u; return 0; }
target=r[3];
r[16]=code_base|0x0c04ee88u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04ee88u) { target=s->pc; goto dispatch; }
goto P_0c04ee88;
P_0c04ee86: /* original 64e3, guest PC 0x0c04ee86 */
if(!s->budget--) { s->failed_pc=0x0c04ee86u; return 0; }
r[4]=r[14];
goto P_0c04ee88;
P_0c04ee88: /* original d328, guest PC 0x0c04ee88 */
if(!s->budget--) { s->failed_pc=0x0c04ee88u; return 0; }
r[3]=read(ram,0x0c04ef2cu,4);
goto P_0c04ee8a;
P_0c04ee8a: /* original 6232, guest PC 0x0c04ee8a */
if(!s->budget--) { s->failed_pc=0x0c04ee8au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c04ee8c;
P_0c04ee8c: /* original 2228, guest PC 0x0c04ee8c */
if(!s->budget--) { s->failed_pc=0x0c04ee8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04ee8e;
P_0c04ee8e: /* original 8d07, guest PC 0x0c04ee8e */
if(!s->budget--) { s->failed_pc=0x0c04ee8eu; return 0; }
cond=r[17]&1u;
r[12]=r[0];
if(cond) { goto P_0c04eea0; }
goto P_0c04ee92;
P_0c04ee90: /* original 6c03, guest PC 0x0c04ee90 */
if(!s->budget--) { s->failed_pc=0x0c04ee90u; return 0; }
r[12]=r[0];
goto P_0c04ee92;
P_0c04ee92: /* original d127, guest PC 0x0c04ee92 */
if(!s->budget--) { s->failed_pc=0x0c04ee92u; return 0; }
r[1]=read(ram,0x0c04ef30u,4);
goto P_0c04ee94;
P_0c04ee94: /* original e51a, guest PC 0x0c04ee94 */
if(!s->budget--) { s->failed_pc=0x0c04ee94u; return 0; }
r[5]=0x0000001au;
goto P_0c04ee96;
P_0c04ee96: /* original 66f1, guest PC 0x0c04ee96 */
if(!s->budget--) { s->failed_pc=0x0c04ee96u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[6]=tmp;
goto P_0c04ee98;
P_0c04ee98: /* original 6212, guest PC 0x0c04ee98 */
if(!s->budget--) { s->failed_pc=0x0c04ee98u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c04ee9a;
P_0c04ee9a: /* original 5024, guest PC 0x0c04ee9a */
if(!s->budget--) { s->failed_pc=0x0c04ee9au; return 0; }
r[0]=read(ram,r[2]+16,4);
goto P_0c04ee9c;
P_0c04ee9c: /* original 400b, guest PC 0x0c04ee9c */
if(!s->budget--) { s->failed_pc=0x0c04ee9cu; return 0; }
target=r[0];
r[16]=code_base|0x0c04eea0u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04eea0u) { target=s->pc; goto dispatch; }
goto P_0c04eea0;
P_0c04ee9e: /* original 64c3, guest PC 0x0c04ee9e */
if(!s->budget--) { s->failed_pc=0x0c04ee9eu; return 0; }
r[4]=r[12];
goto P_0c04eea0;
P_0c04eea0: /* original 84f4, guest PC 0x0c04eea0 */
if(!s->budget--) { s->failed_pc=0x0c04eea0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c04eea2;
P_0c04eea2: /* original 65d3, guest PC 0x0c04eea2 */
if(!s->budget--) { s->failed_pc=0x0c04eea2u; return 0; }
r[5]=r[13];
goto P_0c04eea4;
P_0c04eea4: /* original 80c1, guest PC 0x0c04eea4 */
if(!s->budget--) { s->failed_pc=0x0c04eea4u; return 0; }
write(ram,r[12]+1,r[0],1);
goto P_0c04eea6;
P_0c04eea6: /* original d323, guest PC 0x0c04eea6 */
if(!s->budget--) { s->failed_pc=0x0c04eea6u; return 0; }
r[3]=read(ram,0x0c04ef34u,4);
goto P_0c04eea8;
P_0c04eea8: /* original 430b, guest PC 0x0c04eea8 */
if(!s->budget--) { s->failed_pc=0x0c04eea8u; return 0; }
target=r[3];
r[16]=code_base|0x0c04eeacu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04eeacu) { target=s->pc; goto dispatch; }
goto P_0c04eeac;
P_0c04eeaa: /* original 64e3, guest PC 0x0c04eeaa */
if(!s->budget--) { s->failed_pc=0x0c04eeaau; return 0; }
r[4]=r[14];
goto P_0c04eeac;
P_0c04eeac: /* original b44f, guest PC 0x0c04eeac */
if(!s->budget--) { s->failed_pc=0x0c04eeacu; return 0; }
target=code_base|0x0c04f74eu; r[16]=code_base|0x0c04eeb0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04eeb0u) { target=s->pc; goto dispatch; }
goto P_0c04eeb0;
P_0c04eeae: /* original 64e3, guest PC 0x0c04eeae */
if(!s->budget--) { s->failed_pc=0x0c04eeaeu; return 0; }
r[4]=r[14];
goto P_0c04eeb0;
P_0c04eeb0: /* original 7f38, guest PC 0x0c04eeb0 */
if(!s->budget--) { s->failed_pc=0x0c04eeb0u; return 0; }
r[15]+=0x00000038u;
goto P_0c04eeb2;
P_0c04eeb2: /* original 4f16, guest PC 0x0c04eeb2 */
if(!s->budget--) { s->failed_pc=0x0c04eeb2u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04eeb4;
P_0c04eeb4: /* original 4f26, guest PC 0x0c04eeb4 */
if(!s->budget--) { s->failed_pc=0x0c04eeb4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04eeb6;
P_0c04eeb6: /* original 6cf6, guest PC 0x0c04eeb6 */
if(!s->budget--) { s->failed_pc=0x0c04eeb6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04eeb8;
P_0c04eeb8: /* original 6df6, guest PC 0x0c04eeb8 */
if(!s->budget--) { s->failed_pc=0x0c04eeb8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04eeba;
P_0c04eeba: /* original 000b, guest PC 0x0c04eeba */
if(!s->budget--) { s->failed_pc=0x0c04eebau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04eebc: /* original 6ef6, guest PC 0x0c04eebc */
if(!s->budget--) { s->failed_pc=0x0c04eebcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04eebeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04eebeu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
