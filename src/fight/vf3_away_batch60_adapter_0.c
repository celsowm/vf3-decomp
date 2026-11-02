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
int vf3_away_batch60_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042e44u: goto P_0c042e44;
case 0x0c042e46u: goto P_0c042e46;
case 0x0c042e48u: goto P_0c042e48;
case 0x0c042e4au: goto P_0c042e4a;
case 0x0c042e4cu: goto P_0c042e4c;
case 0x0c042e4eu: goto P_0c042e4e;
case 0x0c042e50u: goto P_0c042e50;
case 0x0c042e52u: goto P_0c042e52;
case 0x0c042e54u: goto P_0c042e54;
case 0x0c042e56u: goto P_0c042e56;
case 0x0c042e58u: goto P_0c042e58;
case 0x0c042e5au: goto P_0c042e5a;
case 0x0c042e5cu: goto P_0c042e5c;
case 0x0c042e5eu: goto P_0c042e5e;
case 0x0c042e60u: goto P_0c042e60;
case 0x0c042e62u: goto P_0c042e62;
case 0x0c042e64u: goto P_0c042e64;
case 0x0c042e66u: goto P_0c042e66;
case 0x0c042e68u: goto P_0c042e68;
case 0x0c042e6au: goto P_0c042e6a;
case 0x0c042e6cu: goto P_0c042e6c;
case 0x0c042e6eu: goto P_0c042e6e;
case 0x0c042e70u: goto P_0c042e70;
case 0x0c042e72u: goto P_0c042e72;
case 0x0c042e74u: goto P_0c042e74;
case 0x0c042e76u: goto P_0c042e76;
case 0x0c042e78u: goto P_0c042e78;
case 0x0c042e7au: goto P_0c042e7a;
case 0x0c042e7cu: goto P_0c042e7c;
case 0x0c042e7eu: goto P_0c042e7e;
case 0x0c042e80u: goto P_0c042e80;
case 0x0c042e82u: goto P_0c042e82;
case 0x0c042e84u: goto P_0c042e84;
case 0x0c042e86u: goto P_0c042e86;
case 0x0c042e88u: goto P_0c042e88;
case 0x0c042e8au: goto P_0c042e8a;
case 0x0c042e8cu: goto P_0c042e8c;
case 0x0c042e8eu: goto P_0c042e8e;
case 0x0c042e90u: goto P_0c042e90;
case 0x0c042e92u: goto P_0c042e92;
case 0x0c042e94u: goto P_0c042e94;
case 0x0c042e96u: goto P_0c042e96;
case 0x0c042e98u: goto P_0c042e98;
case 0x0c042e9au: goto P_0c042e9a;
case 0x0c042e9cu: goto P_0c042e9c;
case 0x0c042e9eu: goto P_0c042e9e;
case 0x0c042ea0u: goto P_0c042ea0;
case 0x0c042ea2u: goto P_0c042ea2;
case 0x0c042ea4u: goto P_0c042ea4;
case 0x0c042ea6u: goto P_0c042ea6;
case 0x0c042ea8u: goto P_0c042ea8;
case 0x0c042eaau: goto P_0c042eaa;
case 0x0c042eacu: goto P_0c042eac;
case 0x0c042eaeu: goto P_0c042eae;
case 0x0c042eb0u: goto P_0c042eb0;
case 0x0c042eb2u: goto P_0c042eb2;
case 0x0c042eb4u: goto P_0c042eb4;
case 0x0c042eb6u: goto P_0c042eb6;
case 0x0c042eb8u: goto P_0c042eb8;
case 0x0c042ebau: goto P_0c042eba;
case 0x0c042ebcu: goto P_0c042ebc;
case 0x0c042ebeu: goto P_0c042ebe;
case 0x0c042ec0u: goto P_0c042ec0;
case 0x0c042ec2u: goto P_0c042ec2;
case 0x0c042ec4u: goto P_0c042ec4;
case 0x0c042ec6u: goto P_0c042ec6;
case 0x0c042ec8u: goto P_0c042ec8;
case 0x0c042ecau: goto P_0c042eca;
case 0x0c042eccu: goto P_0c042ecc;
case 0x0c042eceu: goto P_0c042ece;
case 0x0c042ed0u: goto P_0c042ed0;
case 0x0c042ed2u: goto P_0c042ed2;
case 0x0c042ed4u: goto P_0c042ed4;
case 0x0c042ed6u: goto P_0c042ed6;
case 0x0c042ed8u: goto P_0c042ed8;
case 0x0c042edau: goto P_0c042eda;
case 0x0c042edcu: goto P_0c042edc;
case 0x0c042edeu: goto P_0c042ede;
case 0x0c042ee0u: goto P_0c042ee0;
case 0x0c042ee2u: goto P_0c042ee2;
case 0x0c042ee4u: goto P_0c042ee4;
case 0x0c042ee6u: goto P_0c042ee6;
case 0x0c042ee8u: goto P_0c042ee8;
case 0x0c042eeau: goto P_0c042eea;
case 0x0c042eecu: goto P_0c042eec;
case 0x0c042eeeu: goto P_0c042eee;
case 0x0c042ef0u: goto P_0c042ef0;
case 0x0c042ef2u: goto P_0c042ef2;
case 0x0c08ce66u: goto P_0c08ce66;
case 0x0c08ce68u: goto P_0c08ce68;
case 0x0c08ce6au: goto P_0c08ce6a;
case 0x0c08ce6cu: goto P_0c08ce6c;
case 0x0c08ce6eu: goto P_0c08ce6e;
case 0x0c08ce70u: goto P_0c08ce70;
case 0x0c08ce72u: goto P_0c08ce72;
case 0x0c08ce74u: goto P_0c08ce74;
case 0x0c08ce76u: goto P_0c08ce76;
case 0x0c08ce78u: goto P_0c08ce78;
case 0x0c08ce7au: goto P_0c08ce7a;
case 0x0c08ce7cu: goto P_0c08ce7c;
case 0x0c08ce7eu: goto P_0c08ce7e;
case 0x0c08ce80u: goto P_0c08ce80;
case 0x0c08ce82u: goto P_0c08ce82;
case 0x0c08ce84u: goto P_0c08ce84;
case 0x0c08ce86u: goto P_0c08ce86;
case 0x0c08ce88u: goto P_0c08ce88;
case 0x0c08ce8au: goto P_0c08ce8a;
case 0x0c08ce8cu: goto P_0c08ce8c;
case 0x0c08ce8eu: goto P_0c08ce8e;
case 0x0c08ce90u: goto P_0c08ce90;
case 0x0c08ce92u: goto P_0c08ce92;
case 0x0c08ce94u: goto P_0c08ce94;
case 0x0c08ce96u: goto P_0c08ce96;
case 0x0c08ce98u: goto P_0c08ce98;
case 0x0c08ce9au: goto P_0c08ce9a;
case 0x0c08ce9cu: goto P_0c08ce9c;
case 0x0c08ce9eu: goto P_0c08ce9e;
case 0x0c08cea0u: goto P_0c08cea0;
case 0x0c08cea2u: goto P_0c08cea2;
case 0x0c08cebcu: goto P_0c08cebc;
case 0x0c08cebeu: goto P_0c08cebe;
case 0x0c08cec0u: goto P_0c08cec0;
case 0x0c08cec2u: goto P_0c08cec2;
case 0x0c08cec4u: goto P_0c08cec4;
case 0x0c08cec6u: goto P_0c08cec6;
case 0x0c08cec8u: goto P_0c08cec8;
case 0x0c08cecau: goto P_0c08ceca;
case 0x0c08ceccu: goto P_0c08cecc;
case 0x0c08ceceu: goto P_0c08cece;
case 0x0c08ced0u: goto P_0c08ced0;
case 0x0c08ced2u: goto P_0c08ced2;
case 0x0c08ced4u: goto P_0c08ced4;
case 0x0c08ced6u: goto P_0c08ced6;
case 0x0c08ced8u: goto P_0c08ced8;
case 0x0c08cedau: goto P_0c08ceda;
case 0x0c08cedcu: goto P_0c08cedc;
case 0x0c08cedeu: goto P_0c08cede;
case 0x0c08cee0u: goto P_0c08cee0;
case 0x0c08cee2u: goto P_0c08cee2;
case 0x0c08cee4u: goto P_0c08cee4;
case 0x0c08cee6u: goto P_0c08cee6;
case 0x0c08cee8u: goto P_0c08cee8;
case 0x0c08ceeau: goto P_0c08ceea;
case 0x0c08ceecu: goto P_0c08ceec;
case 0x0c08ceeeu: goto P_0c08ceee;
case 0x0c08cef0u: goto P_0c08cef0;
case 0x0c08cef2u: goto P_0c08cef2;
case 0x0c08cef4u: goto P_0c08cef4;
case 0x0c08cef6u: goto P_0c08cef6;
case 0x0c08cef8u: goto P_0c08cef8;
case 0x0c08cefau: goto P_0c08cefa;
case 0x0c08cefcu: goto P_0c08cefc;
case 0x0c08cefeu: goto P_0c08cefe;
case 0x0c08cf00u: goto P_0c08cf00;
case 0x0c08cf02u: goto P_0c08cf02;
case 0x0c08cf04u: goto P_0c08cf04;
case 0x0c08cf06u: goto P_0c08cf06;
case 0x0c08cf08u: goto P_0c08cf08;
case 0x0c08cf0au: goto P_0c08cf0a;
case 0x0c08cf0cu: goto P_0c08cf0c;
case 0x0c08cf0eu: goto P_0c08cf0e;
case 0x0c08cf10u: goto P_0c08cf10;
case 0x0c08cf12u: goto P_0c08cf12;
case 0x0c08cf14u: goto P_0c08cf14;
case 0x0c08cf16u: goto P_0c08cf16;
case 0x0c08cf18u: goto P_0c08cf18;
case 0x0c08cf1au: goto P_0c08cf1a;
case 0x0c08cf1cu: goto P_0c08cf1c;
case 0x0c08cf1eu: goto P_0c08cf1e;
case 0x0c08cf20u: goto P_0c08cf20;
case 0x0c08cf22u: goto P_0c08cf22;
case 0x0c08cf24u: goto P_0c08cf24;
case 0x0c08cf26u: goto P_0c08cf26;
case 0x0c08cf28u: goto P_0c08cf28;
case 0x0c08cf2au: goto P_0c08cf2a;
case 0x0c08cf2cu: goto P_0c08cf2c;
case 0x0c08cf2eu: goto P_0c08cf2e;
case 0x0c08cf30u: goto P_0c08cf30;
case 0x0c08cf32u: goto P_0c08cf32;
case 0x0c08cf34u: goto P_0c08cf34;
case 0x0c08cf36u: goto P_0c08cf36;
case 0x0c08cf38u: goto P_0c08cf38;
case 0x0c08cf3au: goto P_0c08cf3a;
case 0x0c08cf3cu: goto P_0c08cf3c;
case 0x0c08cf3eu: goto P_0c08cf3e;
case 0x0c08cf40u: goto P_0c08cf40;
case 0x0c08cf42u: goto P_0c08cf42;
case 0x0c08cf44u: goto P_0c08cf44;
case 0x0c08cf46u: goto P_0c08cf46;
case 0x0c08cf48u: goto P_0c08cf48;
case 0x0c08cf4au: goto P_0c08cf4a;
case 0x0c08cf4cu: goto P_0c08cf4c;
case 0x0c08cf4eu: goto P_0c08cf4e;
case 0x0c08cf50u: goto P_0c08cf50;
case 0x0c08cf52u: goto P_0c08cf52;
case 0x0c08cf54u: goto P_0c08cf54;
case 0x0c08cf56u: goto P_0c08cf56;
case 0x0c08cf58u: goto P_0c08cf58;
case 0x0c08cf5au: goto P_0c08cf5a;
case 0x0c08cf5cu: goto P_0c08cf5c;
case 0x0c08cf5eu: goto P_0c08cf5e;
case 0x0c08cf60u: goto P_0c08cf60;
case 0x0c08cf62u: goto P_0c08cf62;
case 0x0c08cf64u: goto P_0c08cf64;
case 0x0c08cf66u: goto P_0c08cf66;
case 0x0c08cf68u: goto P_0c08cf68;
case 0x0c08cf6au: goto P_0c08cf6a;
case 0x0c08cf6cu: goto P_0c08cf6c;
case 0x0c08cf6eu: goto P_0c08cf6e;
case 0x0c08cf70u: goto P_0c08cf70;
case 0x0c08cf72u: goto P_0c08cf72;
case 0x0c08cf74u: goto P_0c08cf74;
case 0x0c08cf76u: goto P_0c08cf76;
case 0x0c08cf78u: goto P_0c08cf78;
case 0x0c08cf7au: goto P_0c08cf7a;
case 0x0c08cf7cu: goto P_0c08cf7c;
case 0x0c08cf7eu: goto P_0c08cf7e;
case 0x0c08cf80u: goto P_0c08cf80;
case 0x0c08cf82u: goto P_0c08cf82;
case 0x0c08cf84u: goto P_0c08cf84;
case 0x0c08cf86u: goto P_0c08cf86;
case 0x0c08cf88u: goto P_0c08cf88;
case 0x0c08cf8au: goto P_0c08cf8a;
case 0x0c08cf8cu: goto P_0c08cf8c;
case 0x0c08cf8eu: goto P_0c08cf8e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c042e44: /* original 2008, guest PC 0x0c042e44 */
if(!s->budget--) { s->failed_pc=0x0c042e44u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c042e46;
P_0c042e46: /* original 8d4e, guest PC 0x0c042e46 */
if(!s->budget--) { s->failed_pc=0x0c042e46u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042ee6; }
goto P_0c042e4a;
P_0c042e48: /* original 0009, guest PC 0x0c042e48 */
if(!s->budget--) { s->failed_pc=0x0c042e48u; return 0; }
goto P_0c042e4a;
P_0c042e4a: /* original 2f36, guest PC 0x0c042e4a */
if(!s->budget--) { s->failed_pc=0x0c042e4au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042e4c;
P_0c042e4c: /* original e300, guest PC 0x0c042e4c */
if(!s->budget--) { s->failed_pc=0x0c042e4cu; return 0; }
r[3]=0x00000000u;
goto P_0c042e4e;
P_0c042e4e: /* original 2f46, guest PC 0x0c042e4e */
if(!s->budget--) { s->failed_pc=0x0c042e4eu; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042e50;
P_0c042e50: /* original 6403, guest PC 0x0c042e50 */
if(!s->budget--) { s->failed_pc=0x0c042e50u; return 0; }
r[4]=r[0];
goto P_0c042e52;
P_0c042e52: /* original 0019, guest PC 0x0c042e52 */
if(!s->budget--) { s->failed_pc=0x0c042e52u; return 0; }
r[17]&=~0x301u;
goto P_0c042e54;
P_0c042e54: /* original 4124, guest PC 0x0c042e54 */
if(!s->budget--) { s->failed_pc=0x0c042e54u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e56;
P_0c042e56: /* original 3344, guest PC 0x0c042e56 */
if(!s->budget--) { s->failed_pc=0x0c042e56u; return 0; }
divide_step(s,3,4);
goto P_0c042e58;
P_0c042e58: /* original 4124, guest PC 0x0c042e58 */
if(!s->budget--) { s->failed_pc=0x0c042e58u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e5a;
P_0c042e5a: /* original 3344, guest PC 0x0c042e5a */
if(!s->budget--) { s->failed_pc=0x0c042e5au; return 0; }
divide_step(s,3,4);
goto P_0c042e5c;
P_0c042e5c: /* original 4124, guest PC 0x0c042e5c */
if(!s->budget--) { s->failed_pc=0x0c042e5cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e5e;
P_0c042e5e: /* original 3344, guest PC 0x0c042e5e */
if(!s->budget--) { s->failed_pc=0x0c042e5eu; return 0; }
divide_step(s,3,4);
goto P_0c042e60;
P_0c042e60: /* original 4124, guest PC 0x0c042e60 */
if(!s->budget--) { s->failed_pc=0x0c042e60u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e62;
P_0c042e62: /* original 3344, guest PC 0x0c042e62 */
if(!s->budget--) { s->failed_pc=0x0c042e62u; return 0; }
divide_step(s,3,4);
goto P_0c042e64;
P_0c042e64: /* original 4124, guest PC 0x0c042e64 */
if(!s->budget--) { s->failed_pc=0x0c042e64u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e66;
P_0c042e66: /* original 3344, guest PC 0x0c042e66 */
if(!s->budget--) { s->failed_pc=0x0c042e66u; return 0; }
divide_step(s,3,4);
goto P_0c042e68;
P_0c042e68: /* original 4124, guest PC 0x0c042e68 */
if(!s->budget--) { s->failed_pc=0x0c042e68u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e6a;
P_0c042e6a: /* original 3344, guest PC 0x0c042e6a */
if(!s->budget--) { s->failed_pc=0x0c042e6au; return 0; }
divide_step(s,3,4);
goto P_0c042e6c;
P_0c042e6c: /* original 4124, guest PC 0x0c042e6c */
if(!s->budget--) { s->failed_pc=0x0c042e6cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e6e;
P_0c042e6e: /* original 3344, guest PC 0x0c042e6e */
if(!s->budget--) { s->failed_pc=0x0c042e6eu; return 0; }
divide_step(s,3,4);
goto P_0c042e70;
P_0c042e70: /* original 4124, guest PC 0x0c042e70 */
if(!s->budget--) { s->failed_pc=0x0c042e70u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e72;
P_0c042e72: /* original 3344, guest PC 0x0c042e72 */
if(!s->budget--) { s->failed_pc=0x0c042e72u; return 0; }
divide_step(s,3,4);
goto P_0c042e74;
P_0c042e74: /* original 4124, guest PC 0x0c042e74 */
if(!s->budget--) { s->failed_pc=0x0c042e74u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e76;
P_0c042e76: /* original 3344, guest PC 0x0c042e76 */
if(!s->budget--) { s->failed_pc=0x0c042e76u; return 0; }
divide_step(s,3,4);
goto P_0c042e78;
P_0c042e78: /* original 4124, guest PC 0x0c042e78 */
if(!s->budget--) { s->failed_pc=0x0c042e78u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e7a;
P_0c042e7a: /* original 3344, guest PC 0x0c042e7a */
if(!s->budget--) { s->failed_pc=0x0c042e7au; return 0; }
divide_step(s,3,4);
goto P_0c042e7c;
P_0c042e7c: /* original 4124, guest PC 0x0c042e7c */
if(!s->budget--) { s->failed_pc=0x0c042e7cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e7e;
P_0c042e7e: /* original 3344, guest PC 0x0c042e7e */
if(!s->budget--) { s->failed_pc=0x0c042e7eu; return 0; }
divide_step(s,3,4);
goto P_0c042e80;
P_0c042e80: /* original 4124, guest PC 0x0c042e80 */
if(!s->budget--) { s->failed_pc=0x0c042e80u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e82;
P_0c042e82: /* original 3344, guest PC 0x0c042e82 */
if(!s->budget--) { s->failed_pc=0x0c042e82u; return 0; }
divide_step(s,3,4);
goto P_0c042e84;
P_0c042e84: /* original 4124, guest PC 0x0c042e84 */
if(!s->budget--) { s->failed_pc=0x0c042e84u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e86;
P_0c042e86: /* original 3344, guest PC 0x0c042e86 */
if(!s->budget--) { s->failed_pc=0x0c042e86u; return 0; }
divide_step(s,3,4);
goto P_0c042e88;
P_0c042e88: /* original 4124, guest PC 0x0c042e88 */
if(!s->budget--) { s->failed_pc=0x0c042e88u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e8a;
P_0c042e8a: /* original 3344, guest PC 0x0c042e8a */
if(!s->budget--) { s->failed_pc=0x0c042e8au; return 0; }
divide_step(s,3,4);
goto P_0c042e8c;
P_0c042e8c: /* original 4124, guest PC 0x0c042e8c */
if(!s->budget--) { s->failed_pc=0x0c042e8cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e8e;
P_0c042e8e: /* original 3344, guest PC 0x0c042e8e */
if(!s->budget--) { s->failed_pc=0x0c042e8eu; return 0; }
divide_step(s,3,4);
goto P_0c042e90;
P_0c042e90: /* original 4124, guest PC 0x0c042e90 */
if(!s->budget--) { s->failed_pc=0x0c042e90u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e92;
P_0c042e92: /* original 3344, guest PC 0x0c042e92 */
if(!s->budget--) { s->failed_pc=0x0c042e92u; return 0; }
divide_step(s,3,4);
goto P_0c042e94;
P_0c042e94: /* original 4124, guest PC 0x0c042e94 */
if(!s->budget--) { s->failed_pc=0x0c042e94u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e96;
P_0c042e96: /* original 3344, guest PC 0x0c042e96 */
if(!s->budget--) { s->failed_pc=0x0c042e96u; return 0; }
divide_step(s,3,4);
goto P_0c042e98;
P_0c042e98: /* original 4124, guest PC 0x0c042e98 */
if(!s->budget--) { s->failed_pc=0x0c042e98u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e9a;
P_0c042e9a: /* original 3344, guest PC 0x0c042e9a */
if(!s->budget--) { s->failed_pc=0x0c042e9au; return 0; }
divide_step(s,3,4);
goto P_0c042e9c;
P_0c042e9c: /* original 4124, guest PC 0x0c042e9c */
if(!s->budget--) { s->failed_pc=0x0c042e9cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e9e;
P_0c042e9e: /* original 3344, guest PC 0x0c042e9e */
if(!s->budget--) { s->failed_pc=0x0c042e9eu; return 0; }
divide_step(s,3,4);
goto P_0c042ea0;
P_0c042ea0: /* original 4124, guest PC 0x0c042ea0 */
if(!s->budget--) { s->failed_pc=0x0c042ea0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ea2;
P_0c042ea2: /* original 3344, guest PC 0x0c042ea2 */
if(!s->budget--) { s->failed_pc=0x0c042ea2u; return 0; }
divide_step(s,3,4);
goto P_0c042ea4;
P_0c042ea4: /* original 4124, guest PC 0x0c042ea4 */
if(!s->budget--) { s->failed_pc=0x0c042ea4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ea6;
P_0c042ea6: /* original 3344, guest PC 0x0c042ea6 */
if(!s->budget--) { s->failed_pc=0x0c042ea6u; return 0; }
divide_step(s,3,4);
goto P_0c042ea8;
P_0c042ea8: /* original 4124, guest PC 0x0c042ea8 */
if(!s->budget--) { s->failed_pc=0x0c042ea8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042eaa;
P_0c042eaa: /* original 3344, guest PC 0x0c042eaa */
if(!s->budget--) { s->failed_pc=0x0c042eaau; return 0; }
divide_step(s,3,4);
goto P_0c042eac;
P_0c042eac: /* original 4124, guest PC 0x0c042eac */
if(!s->budget--) { s->failed_pc=0x0c042eacu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042eae;
P_0c042eae: /* original 3344, guest PC 0x0c042eae */
if(!s->budget--) { s->failed_pc=0x0c042eaeu; return 0; }
divide_step(s,3,4);
goto P_0c042eb0;
P_0c042eb0: /* original 4124, guest PC 0x0c042eb0 */
if(!s->budget--) { s->failed_pc=0x0c042eb0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042eb2;
P_0c042eb2: /* original 3344, guest PC 0x0c042eb2 */
if(!s->budget--) { s->failed_pc=0x0c042eb2u; return 0; }
divide_step(s,3,4);
goto P_0c042eb4;
P_0c042eb4: /* original 4124, guest PC 0x0c042eb4 */
if(!s->budget--) { s->failed_pc=0x0c042eb4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042eb6;
P_0c042eb6: /* original 3344, guest PC 0x0c042eb6 */
if(!s->budget--) { s->failed_pc=0x0c042eb6u; return 0; }
divide_step(s,3,4);
goto P_0c042eb8;
P_0c042eb8: /* original 4124, guest PC 0x0c042eb8 */
if(!s->budget--) { s->failed_pc=0x0c042eb8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042eba;
P_0c042eba: /* original 3344, guest PC 0x0c042eba */
if(!s->budget--) { s->failed_pc=0x0c042ebau; return 0; }
divide_step(s,3,4);
goto P_0c042ebc;
P_0c042ebc: /* original 4124, guest PC 0x0c042ebc */
if(!s->budget--) { s->failed_pc=0x0c042ebcu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ebe;
P_0c042ebe: /* original 3344, guest PC 0x0c042ebe */
if(!s->budget--) { s->failed_pc=0x0c042ebeu; return 0; }
divide_step(s,3,4);
goto P_0c042ec0;
P_0c042ec0: /* original 4124, guest PC 0x0c042ec0 */
if(!s->budget--) { s->failed_pc=0x0c042ec0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ec2;
P_0c042ec2: /* original 3344, guest PC 0x0c042ec2 */
if(!s->budget--) { s->failed_pc=0x0c042ec2u; return 0; }
divide_step(s,3,4);
goto P_0c042ec4;
P_0c042ec4: /* original 4124, guest PC 0x0c042ec4 */
if(!s->budget--) { s->failed_pc=0x0c042ec4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ec6;
P_0c042ec6: /* original 3344, guest PC 0x0c042ec6 */
if(!s->budget--) { s->failed_pc=0x0c042ec6u; return 0; }
divide_step(s,3,4);
goto P_0c042ec8;
P_0c042ec8: /* original 4124, guest PC 0x0c042ec8 */
if(!s->budget--) { s->failed_pc=0x0c042ec8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042eca;
P_0c042eca: /* original 3344, guest PC 0x0c042eca */
if(!s->budget--) { s->failed_pc=0x0c042ecau; return 0; }
divide_step(s,3,4);
goto P_0c042ecc;
P_0c042ecc: /* original 4124, guest PC 0x0c042ecc */
if(!s->budget--) { s->failed_pc=0x0c042eccu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ece;
P_0c042ece: /* original 3344, guest PC 0x0c042ece */
if(!s->budget--) { s->failed_pc=0x0c042eceu; return 0; }
divide_step(s,3,4);
goto P_0c042ed0;
P_0c042ed0: /* original 4124, guest PC 0x0c042ed0 */
if(!s->budget--) { s->failed_pc=0x0c042ed0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ed2;
P_0c042ed2: /* original 3344, guest PC 0x0c042ed2 */
if(!s->budget--) { s->failed_pc=0x0c042ed2u; return 0; }
divide_step(s,3,4);
goto P_0c042ed4;
P_0c042ed4: /* original 8b03, guest PC 0x0c042ed4 */
if(!s->budget--) { s->failed_pc=0x0c042ed4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042ede; }
goto P_0c042ed6;
P_0c042ed6: /* original 6033, guest PC 0x0c042ed6 */
if(!s->budget--) { s->failed_pc=0x0c042ed6u; return 0; }
r[0]=r[3];
goto P_0c042ed8;
P_0c042ed8: /* original 64f6, guest PC 0x0c042ed8 */
if(!s->budget--) { s->failed_pc=0x0c042ed8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c042eda;
P_0c042eda: /* original 000b, guest PC 0x0c042eda */
if(!s->budget--) { s->failed_pc=0x0c042edau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
s->pc=target; return ram->oob==0;
P_0c042edc: /* original 63f6, guest PC 0x0c042edc */
if(!s->budget--) { s->failed_pc=0x0c042edcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042ede;
P_0c042ede: /* original 303c, guest PC 0x0c042ede */
if(!s->budget--) { s->failed_pc=0x0c042edeu; return 0; }
r[0]+=r[3];
goto P_0c042ee0;
P_0c042ee0: /* original 64f6, guest PC 0x0c042ee0 */
if(!s->budget--) { s->failed_pc=0x0c042ee0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c042ee2;
P_0c042ee2: /* original 000b, guest PC 0x0c042ee2 */
if(!s->budget--) { s->failed_pc=0x0c042ee2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
s->pc=target; return ram->oob==0;
P_0c042ee4: /* original 63f6, guest PC 0x0c042ee4 */
if(!s->budget--) { s->failed_pc=0x0c042ee4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042ee6;
P_0c042ee6: /* original 2f26, guest PC 0x0c042ee6 */
if(!s->budget--) { s->failed_pc=0x0c042ee6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042ee8;
P_0c042ee8: /* original d102, guest PC 0x0c042ee8 */
if(!s->budget--) { s->failed_pc=0x0c042ee8u; return 0; }
r[1]=read(ram,0x0c042ef4u,4);
goto P_0c042eea;
P_0c042eea: /* original d203, guest PC 0x0c042eea */
if(!s->budget--) { s->failed_pc=0x0c042eeau; return 0; }
r[2]=read(ram,0x0c042ef8u,4);
goto P_0c042eec;
P_0c042eec: /* original e000, guest PC 0x0c042eec */
if(!s->budget--) { s->failed_pc=0x0c042eecu; return 0; }
r[0]=0x00000000u;
goto P_0c042eee;
P_0c042eee: /* original 2122, guest PC 0x0c042eee */
if(!s->budget--) { s->failed_pc=0x0c042eeeu; return 0; }
write(ram,r[1],r[2],4);
goto P_0c042ef0;
P_0c042ef0: /* original 000b, guest PC 0x0c042ef0 */
if(!s->budget--) { s->failed_pc=0x0c042ef0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042ef2: /* original 62f6, guest PC 0x0c042ef2 */
if(!s->budget--) { s->failed_pc=0x0c042ef2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042ef4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042ef4u; return 0; } return 1;
P_0c08ce66: /* original 2fe6, guest PC 0x0c08ce66 */
if(!s->budget--) { s->failed_pc=0x0c08ce66u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ce68;
P_0c08ce68: /* original e048, guest PC 0x0c08ce68 */
if(!s->budget--) { s->failed_pc=0x0c08ce68u; return 0; }
r[0]=0x00000048u;
goto P_0c08ce6a;
P_0c08ce6a: /* original 2fd6, guest PC 0x0c08ce6a */
if(!s->budget--) { s->failed_pc=0x0c08ce6au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ce6c;
P_0c08ce6c: /* original 6d43, guest PC 0x0c08ce6c */
if(!s->budget--) { s->failed_pc=0x0c08ce6cu; return 0; }
r[13]=r[4];
goto P_0c08ce6e;
P_0c08ce6e: /* original 2fc6, guest PC 0x0c08ce6e */
if(!s->budget--) { s->failed_pc=0x0c08ce6eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ce70;
P_0c08ce70: /* original 00dc, guest PC 0x0c08ce70 */
if(!s->budget--) { s->failed_pc=0x0c08ce70u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08ce72;
P_0c08ce72: /* original 4f22, guest PC 0x0c08ce72 */
if(!s->budget--) { s->failed_pc=0x0c08ce72u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08ce74;
P_0c08ce74: /* original 8801, guest PC 0x0c08ce74 */
if(!s->budget--) { s->failed_pc=0x0c08ce74u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08ce76;
P_0c08ce76: /* original 8d53, guest PC 0x0c08ce76 */
if(!s->budget--) { s->failed_pc=0x0c08ce76u; return 0; }
cond=r[17]&1u;
r[14]=r[5];
if(cond) { goto P_0c08cf20; }
goto P_0c08ce7a;
P_0c08ce78: /* original 6e53, guest PC 0x0c08ce78 */
if(!s->budget--) { s->failed_pc=0x0c08ce78u; return 0; }
r[14]=r[5];
goto P_0c08ce7a;
P_0c08ce7a: /* original 60e2, guest PC 0x0c08ce7a */
if(!s->budget--) { s->failed_pc=0x0c08ce7au; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c08ce7c;
P_0c08ce7c: /* original cb01, guest PC 0x0c08ce7c */
if(!s->budget--) { s->failed_pc=0x0c08ce7cu; return 0; }
r[0]|=1u;
goto P_0c08ce7e;
P_0c08ce7e: /* original 2e02, guest PC 0x0c08ce7e */
if(!s->budget--) { s->failed_pc=0x0c08ce7eu; return 0; }
write(ram,r[14],r[0],4);
goto P_0c08ce80;
P_0c08ce80: /* original e048, guest PC 0x0c08ce80 */
if(!s->budget--) { s->failed_pc=0x0c08ce80u; return 0; }
r[0]=0x00000048u;
goto P_0c08ce82;
P_0c08ce82: /* original 04ee, guest PC 0x0c08ce82 */
if(!s->budget--) { s->failed_pc=0x0c08ce82u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c08ce84;
P_0c08ce84: /* original 9011, guest PC 0x0c08ce84 */
if(!s->budget--) { s->failed_pc=0x0c08ce84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ceaau,2);
goto P_0c08ce86;
P_0c08ce86: /* original d30b, guest PC 0x0c08ce86 */
if(!s->budget--) { s->failed_pc=0x0c08ce86u; return 0; }
r[3]=read(ram,0x0c08ceb4u,4);
goto P_0c08ce88;
P_0c08ce88: /* original 044e, guest PC 0x0c08ce88 */
if(!s->budget--) { s->failed_pc=0x0c08ce88u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c08ce8a;
P_0c08ce8a: /* original 2438, guest PC 0x0c08ce8a */
if(!s->budget--) { s->failed_pc=0x0c08ce8au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c08ce8c;
P_0c08ce8c: /* original 8916, guest PC 0x0c08ce8c */
if(!s->budget--) { s->failed_pc=0x0c08ce8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08cebc; }
goto P_0c08ce8e;
P_0c08ce8e: /* original d107, guest PC 0x0c08ce8e */
if(!s->budget--) { s->failed_pc=0x0c08ce8eu; return 0; }
r[1]=read(ram,0x0c08ceacu,4);
goto P_0c08ce90;
P_0c08ce90: /* original 410b, guest PC 0x0c08ce90 */
if(!s->budget--) { s->failed_pc=0x0c08ce90u; return 0; }
target=r[1];
r[16]=code_base|0x0c08ce94u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ce94u) { target=s->pc; goto dispatch; }
goto P_0c08ce94;
P_0c08ce92: /* original 0009, guest PC 0x0c08ce92 */
if(!s->budget--) { s->failed_pc=0x0c08ce92u; return 0; }
goto P_0c08ce94;
P_0c08ce94: /* original e503, guest PC 0x0c08ce94 */
if(!s->budget--) { s->failed_pc=0x0c08ce94u; return 0; }
r[5]=0x00000003u;
goto P_0c08ce96;
P_0c08ce96: /* original 6403, guest PC 0x0c08ce96 */
if(!s->budget--) { s->failed_pc=0x0c08ce96u; return 0; }
r[4]=r[0];
goto P_0c08ce98;
P_0c08ce98: /* original 2549, guest PC 0x0c08ce98 */
if(!s->budget--) { s->failed_pc=0x0c08ce98u; return 0; }
r[5]&=r[4];
goto P_0c08ce9a;
P_0c08ce9a: /* original d007, guest PC 0x0c08ce9a */
if(!s->budget--) { s->failed_pc=0x0c08ce9au; return 0; }
r[0]=read(ram,0x0c08ceb8u,4);
goto P_0c08ce9c;
P_0c08ce9c: /* original 6453, guest PC 0x0c08ce9c */
if(!s->budget--) { s->failed_pc=0x0c08ce9cu; return 0; }
r[4]=r[5];
goto P_0c08ce9e;
P_0c08ce9e: /* original 4400, guest PC 0x0c08ce9e */
if(!s->budget--) { s->failed_pc=0x0c08ce9eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08cea0;
P_0c08cea0: /* original a028, guest PC 0x0c08cea0 */
if(!s->budget--) { s->failed_pc=0x0c08cea0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08cef4;
P_0c08cea2: /* original 044d, guest PC 0x0c08cea2 */
if(!s->budget--) { s->failed_pc=0x0c08cea2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
if(!vf3_matrix_family(0x0c08cea4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08cea4u; return 0; } return 1;
P_0c08cebc: /* original e04c, guest PC 0x0c08cebc */
if(!s->budget--) { s->failed_pc=0x0c08cebcu; return 0; }
r[0]=0x0000004cu;
goto P_0c08cebe;
P_0c08cebe: /* original d24c, guest PC 0x0c08cebe */
if(!s->budget--) { s->failed_pc=0x0c08cebeu; return 0; }
r[2]=read(ram,0x0c08cff0u,4);
goto P_0c08cec0;
P_0c08cec0: /* original 0cee, guest PC 0x0c08cec0 */
if(!s->budget--) { s->failed_pc=0x0c08cec0u; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c08cec2;
P_0c08cec2: /* original e061, guest PC 0x0c08cec2 */
if(!s->budget--) { s->failed_pc=0x0c08cec2u; return 0; }
r[0]=0x00000061u;
goto P_0c08cec4;
P_0c08cec4: /* original 0ccc, guest PC 0x0c08cec4 */
if(!s->budget--) { s->failed_pc=0x0c08cec4u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c08cec6;
P_0c08cec6: /* original d049, guest PC 0x0c08cec6 */
if(!s->budget--) { s->failed_pc=0x0c08cec6u; return 0; }
r[0]=read(ram,0x0c08cfecu,4);
goto P_0c08cec8;
P_0c08cec8: /* original 6ccc, guest PC 0x0c08cec8 */
if(!s->budget--) { s->failed_pc=0x0c08cec8u; return 0; }
r[12]=r[12]&255u;
goto P_0c08ceca;
P_0c08ceca: /* original 0ccc, guest PC 0x0c08ceca */
if(!s->budget--) { s->failed_pc=0x0c08cecau; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c08cecc;
P_0c08cecc: /* original 420b, guest PC 0x0c08cecc */
if(!s->budget--) { s->failed_pc=0x0c08ceccu; return 0; }
target=r[2];
r[16]=code_base|0x0c08ced0u;
r[12]=r[12]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ced0u) { target=s->pc; goto dispatch; }
goto P_0c08ced0;
P_0c08cece: /* original 6ccc, guest PC 0x0c08cece */
if(!s->budget--) { s->failed_pc=0x0c08ceceu; return 0; }
r[12]=r[12]&255u;
goto P_0c08ced0;
P_0c08ced0: /* original d348, guest PC 0x0c08ced0 */
if(!s->budget--) { s->failed_pc=0x0c08ced0u; return 0; }
r[3]=read(ram,0x0c08cff4u,4);
goto P_0c08ced2;
P_0c08ced2: /* original 6103, guest PC 0x0c08ced2 */
if(!s->budget--) { s->failed_pc=0x0c08ced2u; return 0; }
r[1]=r[0];
goto P_0c08ced4;
P_0c08ced4: /* original 430b, guest PC 0x0c08ced4 */
if(!s->budget--) { s->failed_pc=0x0c08ced4u; return 0; }
target=r[3];
r[16]=code_base|0x0c08ced8u;
r[0]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ced8u) { target=s->pc; goto dispatch; }
goto P_0c08ced8;
P_0c08ced6: /* original 60c3, guest PC 0x0c08ced6 */
if(!s->budget--) { s->failed_pc=0x0c08ced6u; return 0; }
r[0]=r[12];
goto P_0c08ced8;
P_0c08ced8: /* original 6c03, guest PC 0x0c08ced8 */
if(!s->budget--) { s->failed_pc=0x0c08ced8u; return 0; }
r[12]=r[0];
goto P_0c08ceda;
P_0c08ceda: /* original e04c, guest PC 0x0c08ceda */
if(!s->budget--) { s->failed_pc=0x0c08cedau; return 0; }
r[0]=0x0000004cu;
goto P_0c08cedc;
P_0c08cedc: /* original 00ee, guest PC 0x0c08cedc */
if(!s->budget--) { s->failed_pc=0x0c08cedcu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c08cede;
P_0c08cede: /* original e161, guest PC 0x0c08cede */
if(!s->budget--) { s->failed_pc=0x0c08cedeu; return 0; }
r[1]=0x00000061u;
goto P_0c08cee0;
P_0c08cee0: /* original d345, guest PC 0x0c08cee0 */
if(!s->budget--) { s->failed_pc=0x0c08cee0u; return 0; }
r[3]=read(ram,0x0c08cff8u,4);
goto P_0c08cee2;
P_0c08cee2: /* original 64c3, guest PC 0x0c08cee2 */
if(!s->budget--) { s->failed_pc=0x0c08cee2u; return 0; }
r[4]=r[12];
goto P_0c08cee4;
P_0c08cee4: /* original 001c, guest PC 0x0c08cee4 */
if(!s->budget--) { s->failed_pc=0x0c08cee4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c08cee6;
P_0c08cee6: /* original 4400, guest PC 0x0c08cee6 */
if(!s->budget--) { s->failed_pc=0x0c08cee6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08cee8;
P_0c08cee8: /* original 600c, guest PC 0x0c08cee8 */
if(!s->budget--) { s->failed_pc=0x0c08cee8u; return 0; }
r[0]=r[0]&255u;
goto P_0c08ceea;
P_0c08ceea: /* original 4008, guest PC 0x0c08ceea */
if(!s->budget--) { s->failed_pc=0x0c08ceeau; return 0; }
r[0]<<=2;
goto P_0c08ceec;
P_0c08ceec: /* original 4008, guest PC 0x0c08ceec */
if(!s->budget--) { s->failed_pc=0x0c08ceecu; return 0; }
r[0]<<=2;
goto P_0c08ceee;
P_0c08ceee: /* original 330c, guest PC 0x0c08ceee */
if(!s->budget--) { s->failed_pc=0x0c08ceeeu; return 0; }
r[3]+=r[0];
goto P_0c08cef0;
P_0c08cef0: /* original 343c, guest PC 0x0c08cef0 */
if(!s->budget--) { s->failed_pc=0x0c08cef0u; return 0; }
r[4]+=r[3];
goto P_0c08cef2;
P_0c08cef2: /* original 6441, guest PC 0x0c08cef2 */
if(!s->budget--) { s->failed_pc=0x0c08cef2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[4]=tmp;
goto P_0c08cef4;
P_0c08cef4: /* original e028, guest PC 0x0c08cef4 */
if(!s->budget--) { s->failed_pc=0x0c08cef4u; return 0; }
r[0]=0x00000028u;
goto P_0c08cef6;
P_0c08cef6: /* original 644d, guest PC 0x0c08cef6 */
if(!s->budget--) { s->failed_pc=0x0c08cef6u; return 0; }
r[4]=r[4]&65535u;
goto P_0c08cef8;
P_0c08cef8: /* original 0d45, guest PC 0x0c08cef8 */
if(!s->budget--) { s->failed_pc=0x0c08cef8u; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c08cefa;
P_0c08cefa: /* original e040, guest PC 0x0c08cefa */
if(!s->budget--) { s->failed_pc=0x0c08cefau; return 0; }
r[0]=0x00000040u;
goto P_0c08cefc;
P_0c08cefc: /* original e500, guest PC 0x0c08cefc */
if(!s->budget--) { s->failed_pc=0x0c08cefcu; return 0; }
r[5]=0x00000000u;
goto P_0c08cefe;
P_0c08cefe: /* original 1e4d, guest PC 0x0c08cefe */
if(!s->budget--) { s->failed_pc=0x0c08cefeu; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c08cf00;
P_0c08cf00: /* original 0e56, guest PC 0x0c08cf00 */
if(!s->budget--) { s->failed_pc=0x0c08cf00u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c08cf02;
P_0c08cf02: /* original b129, guest PC 0x0c08cf02 */
if(!s->budget--) { s->failed_pc=0x0c08cf02u; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08cf06u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cf06u) { target=s->pc; goto dispatch; }
goto P_0c08cf06;
P_0c08cf04: /* original 64e3, guest PC 0x0c08cf04 */
if(!s->budget--) { s->failed_pc=0x0c08cf04u; return 0; }
r[4]=r[14];
goto P_0c08cf06;
P_0c08cf06: /* original e200, guest PC 0x0c08cf06 */
if(!s->budget--) { s->failed_pc=0x0c08cf06u; return 0; }
r[2]=0x00000000u;
goto P_0c08cf08;
P_0c08cf08: /* original 55ee, guest PC 0x0c08cf08 */
if(!s->budget--) { s->failed_pc=0x0c08cf08u; return 0; }
r[5]=read(ram,r[14]+56,4);
goto P_0c08cf0a;
P_0c08cf0a: /* original e02c, guest PC 0x0c08cf0a */
if(!s->budget--) { s->failed_pc=0x0c08cf0au; return 0; }
r[0]=0x0000002cu;
goto P_0c08cf0c;
P_0c08cf0c: /* original 54ef, guest PC 0x0c08cf0c */
if(!s->budget--) { s->failed_pc=0x0c08cf0cu; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c08cf0e;
P_0c08cf0e: /* original 0d24, guest PC 0x0c08cf0e */
if(!s->budget--) { s->failed_pc=0x0c08cf0eu; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c08cf10;
P_0c08cf10: /* original e02d, guest PC 0x0c08cf10 */
if(!s->budget--) { s->failed_pc=0x0c08cf10u; return 0; }
r[0]=0x0000002du;
goto P_0c08cf12;
P_0c08cf12: /* original 0d54, guest PC 0x0c08cf12 */
if(!s->budget--) { s->failed_pc=0x0c08cf12u; return 0; }
write(ram,r[13]+r[0],r[5],1);
goto P_0c08cf14;
P_0c08cf14: /* original 6043, guest PC 0x0c08cf14 */
if(!s->budget--) { s->failed_pc=0x0c08cf14u; return 0; }
r[0]=r[4];
goto P_0c08cf16;
P_0c08cf16: /* original 81da, guest PC 0x0c08cf16 */
if(!s->budget--) { s->failed_pc=0x0c08cf16u; return 0; }
write(ram,r[13]+20,r[0],2);
goto P_0c08cf18;
P_0c08cf18: /* original e048, guest PC 0x0c08cf18 */
if(!s->budget--) { s->failed_pc=0x0c08cf18u; return 0; }
r[0]=0x00000048u;
goto P_0c08cf1a;
P_0c08cf1a: /* original 03dc, guest PC 0x0c08cf1a */
if(!s->budget--) { s->failed_pc=0x0c08cf1au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08cf1c;
P_0c08cf1c: /* original 7301, guest PC 0x0c08cf1c */
if(!s->budget--) { s->failed_pc=0x0c08cf1cu; return 0; }
r[3]+=0x00000001u;
goto P_0c08cf1e;
P_0c08cf1e: /* original 0d34, guest PC 0x0c08cf1e */
if(!s->budget--) { s->failed_pc=0x0c08cf1eu; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c08cf20;
P_0c08cf20: /* original 4f26, guest PC 0x0c08cf20 */
if(!s->budget--) { s->failed_pc=0x0c08cf20u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08cf22;
P_0c08cf22: /* original 6cf6, guest PC 0x0c08cf22 */
if(!s->budget--) { s->failed_pc=0x0c08cf22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08cf24;
P_0c08cf24: /* original 6df6, guest PC 0x0c08cf24 */
if(!s->budget--) { s->failed_pc=0x0c08cf24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08cf26;
P_0c08cf26: /* original 000b, guest PC 0x0c08cf26 */
if(!s->budget--) { s->failed_pc=0x0c08cf26u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08cf28: /* original 6ef6, guest PC 0x0c08cf28 */
if(!s->budget--) { s->failed_pc=0x0c08cf28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08cf2a;
P_0c08cf2a: /* original 2fe6, guest PC 0x0c08cf2a */
if(!s->budget--) { s->failed_pc=0x0c08cf2au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cf2c;
P_0c08cf2c: /* original 6e43, guest PC 0x0c08cf2c */
if(!s->budget--) { s->failed_pc=0x0c08cf2cu; return 0; }
r[14]=r[4];
goto P_0c08cf2e;
P_0c08cf2e: /* original 2fd6, guest PC 0x0c08cf2e */
if(!s->budget--) { s->failed_pc=0x0c08cf2eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cf30;
P_0c08cf30: /* original e048, guest PC 0x0c08cf30 */
if(!s->budget--) { s->failed_pc=0x0c08cf30u; return 0; }
r[0]=0x00000048u;
goto P_0c08cf32;
P_0c08cf32: /* original 2fc6, guest PC 0x0c08cf32 */
if(!s->budget--) { s->failed_pc=0x0c08cf32u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cf34;
P_0c08cf34: /* original 00ec, guest PC 0x0c08cf34 */
if(!s->budget--) { s->failed_pc=0x0c08cf34u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08cf36;
P_0c08cf36: /* original 4f22, guest PC 0x0c08cf36 */
if(!s->budget--) { s->failed_pc=0x0c08cf36u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08cf38;
P_0c08cf38: /* original 8801, guest PC 0x0c08cf38 */
if(!s->budget--) { s->failed_pc=0x0c08cf38u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08cf3a;
P_0c08cf3a: /* original 8d24, guest PC 0x0c08cf3a */
if(!s->budget--) { s->failed_pc=0x0c08cf3au; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c08cf86; }
goto P_0c08cf3e;
P_0c08cf3c: /* original 6d53, guest PC 0x0c08cf3c */
if(!s->budget--) { s->failed_pc=0x0c08cf3cu; return 0; }
r[13]=r[5];
goto P_0c08cf3e;
P_0c08cf3e: /* original 60d2, guest PC 0x0c08cf3e */
if(!s->budget--) { s->failed_pc=0x0c08cf3eu; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c08cf40;
P_0c08cf40: /* original cb01, guest PC 0x0c08cf40 */
if(!s->budget--) { s->failed_pc=0x0c08cf40u; return 0; }
r[0]|=1u;
goto P_0c08cf42;
P_0c08cf42: /* original 2d02, guest PC 0x0c08cf42 */
if(!s->budget--) { s->failed_pc=0x0c08cf42u; return 0; }
write(ram,r[13],r[0],4);
goto P_0c08cf44;
P_0c08cf44: /* original d22a, guest PC 0x0c08cf44 */
if(!s->budget--) { s->failed_pc=0x0c08cf44u; return 0; }
r[2]=read(ram,0x0c08cff0u,4);
goto P_0c08cf46;
P_0c08cf46: /* original 420b, guest PC 0x0c08cf46 */
if(!s->budget--) { s->failed_pc=0x0c08cf46u; return 0; }
target=r[2];
r[16]=code_base|0x0c08cf4au;
r[12]=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cf4au) { target=s->pc; goto dispatch; }
goto P_0c08cf4a;
P_0c08cf48: /* original ec0c, guest PC 0x0c08cf48 */
if(!s->budget--) { s->failed_pc=0x0c08cf48u; return 0; }
r[12]=0x0000000cu;
goto P_0c08cf4a;
P_0c08cf4a: /* original d32a, guest PC 0x0c08cf4a */
if(!s->budget--) { s->failed_pc=0x0c08cf4au; return 0; }
r[3]=read(ram,0x0c08cff4u,4);
goto P_0c08cf4c;
P_0c08cf4c: /* original 6103, guest PC 0x0c08cf4c */
if(!s->budget--) { s->failed_pc=0x0c08cf4cu; return 0; }
r[1]=r[0];
goto P_0c08cf4e;
P_0c08cf4e: /* original 430b, guest PC 0x0c08cf4e */
if(!s->budget--) { s->failed_pc=0x0c08cf4eu; return 0; }
target=r[3];
r[16]=code_base|0x0c08cf52u;
r[0]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cf52u) { target=s->pc; goto dispatch; }
goto P_0c08cf52;
P_0c08cf50: /* original 60c3, guest PC 0x0c08cf50 */
if(!s->budget--) { s->failed_pc=0x0c08cf50u; return 0; }
r[0]=r[12];
goto P_0c08cf52;
P_0c08cf52: /* original 6403, guest PC 0x0c08cf52 */
if(!s->budget--) { s->failed_pc=0x0c08cf52u; return 0; }
r[4]=r[0];
goto P_0c08cf54;
P_0c08cf54: /* original d029, guest PC 0x0c08cf54 */
if(!s->budget--) { s->failed_pc=0x0c08cf54u; return 0; }
r[0]=read(ram,0x0c08cffcu,4);
goto P_0c08cf56;
P_0c08cf56: /* original 4400, guest PC 0x0c08cf56 */
if(!s->budget--) { s->failed_pc=0x0c08cf56u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08cf58;
P_0c08cf58: /* original 044d, guest PC 0x0c08cf58 */
if(!s->budget--) { s->failed_pc=0x0c08cf58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08cf5a;
P_0c08cf5a: /* original e028, guest PC 0x0c08cf5a */
if(!s->budget--) { s->failed_pc=0x0c08cf5au; return 0; }
r[0]=0x00000028u;
goto P_0c08cf5c;
P_0c08cf5c: /* original e500, guest PC 0x0c08cf5c */
if(!s->budget--) { s->failed_pc=0x0c08cf5cu; return 0; }
r[5]=0x00000000u;
goto P_0c08cf5e;
P_0c08cf5e: /* original 644d, guest PC 0x0c08cf5e */
if(!s->budget--) { s->failed_pc=0x0c08cf5eu; return 0; }
r[4]=r[4]&65535u;
goto P_0c08cf60;
P_0c08cf60: /* original 0e45, guest PC 0x0c08cf60 */
if(!s->budget--) { s->failed_pc=0x0c08cf60u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08cf62;
P_0c08cf62: /* original e040, guest PC 0x0c08cf62 */
if(!s->budget--) { s->failed_pc=0x0c08cf62u; return 0; }
r[0]=0x00000040u;
goto P_0c08cf64;
P_0c08cf64: /* original 1d4d, guest PC 0x0c08cf64 */
if(!s->budget--) { s->failed_pc=0x0c08cf64u; return 0; }
write(ram,r[13]+52,r[4],4);
goto P_0c08cf66;
P_0c08cf66: /* original 0d56, guest PC 0x0c08cf66 */
if(!s->budget--) { s->failed_pc=0x0c08cf66u; return 0; }
write(ram,r[13]+r[0],r[5],4);
goto P_0c08cf68;
P_0c08cf68: /* original b0f6, guest PC 0x0c08cf68 */
if(!s->budget--) { s->failed_pc=0x0c08cf68u; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08cf6cu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cf6cu) { target=s->pc; goto dispatch; }
goto P_0c08cf6c;
P_0c08cf6a: /* original 64d3, guest PC 0x0c08cf6a */
if(!s->budget--) { s->failed_pc=0x0c08cf6au; return 0; }
r[4]=r[13];
goto P_0c08cf6c;
P_0c08cf6c: /* original e200, guest PC 0x0c08cf6c */
if(!s->budget--) { s->failed_pc=0x0c08cf6cu; return 0; }
r[2]=0x00000000u;
goto P_0c08cf6e;
P_0c08cf6e: /* original 55de, guest PC 0x0c08cf6e */
if(!s->budget--) { s->failed_pc=0x0c08cf6eu; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c08cf70;
P_0c08cf70: /* original e02c, guest PC 0x0c08cf70 */
if(!s->budget--) { s->failed_pc=0x0c08cf70u; return 0; }
r[0]=0x0000002cu;
goto P_0c08cf72;
P_0c08cf72: /* original 54df, guest PC 0x0c08cf72 */
if(!s->budget--) { s->failed_pc=0x0c08cf72u; return 0; }
r[4]=read(ram,r[13]+60,4);
goto P_0c08cf74;
P_0c08cf74: /* original 0e24, guest PC 0x0c08cf74 */
if(!s->budget--) { s->failed_pc=0x0c08cf74u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c08cf76;
P_0c08cf76: /* original e02d, guest PC 0x0c08cf76 */
if(!s->budget--) { s->failed_pc=0x0c08cf76u; return 0; }
r[0]=0x0000002du;
goto P_0c08cf78;
P_0c08cf78: /* original 0e54, guest PC 0x0c08cf78 */
if(!s->budget--) { s->failed_pc=0x0c08cf78u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c08cf7a;
P_0c08cf7a: /* original 6043, guest PC 0x0c08cf7a */
if(!s->budget--) { s->failed_pc=0x0c08cf7au; return 0; }
r[0]=r[4];
goto P_0c08cf7c;
P_0c08cf7c: /* original 81ea, guest PC 0x0c08cf7c */
if(!s->budget--) { s->failed_pc=0x0c08cf7cu; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c08cf7e;
P_0c08cf7e: /* original e048, guest PC 0x0c08cf7e */
if(!s->budget--) { s->failed_pc=0x0c08cf7eu; return 0; }
r[0]=0x00000048u;
goto P_0c08cf80;
P_0c08cf80: /* original 03ec, guest PC 0x0c08cf80 */
if(!s->budget--) { s->failed_pc=0x0c08cf80u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08cf82;
P_0c08cf82: /* original 7301, guest PC 0x0c08cf82 */
if(!s->budget--) { s->failed_pc=0x0c08cf82u; return 0; }
r[3]+=0x00000001u;
goto P_0c08cf84;
P_0c08cf84: /* original 0e34, guest PC 0x0c08cf84 */
if(!s->budget--) { s->failed_pc=0x0c08cf84u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08cf86;
P_0c08cf86: /* original 4f26, guest PC 0x0c08cf86 */
if(!s->budget--) { s->failed_pc=0x0c08cf86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08cf88;
P_0c08cf88: /* original 6cf6, guest PC 0x0c08cf88 */
if(!s->budget--) { s->failed_pc=0x0c08cf88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08cf8a;
P_0c08cf8a: /* original 6df6, guest PC 0x0c08cf8a */
if(!s->budget--) { s->failed_pc=0x0c08cf8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08cf8c;
P_0c08cf8c: /* original 000b, guest PC 0x0c08cf8c */
if(!s->budget--) { s->failed_pc=0x0c08cf8cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08cf8e: /* original 6ef6, guest PC 0x0c08cf8e */
if(!s->budget--) { s->failed_pc=0x0c08cf8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08cf90u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
