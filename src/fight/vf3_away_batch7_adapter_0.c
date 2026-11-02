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
int vf3_away_batch7_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042c1eu: goto P_0c042c1e;
case 0x0c042c20u: goto P_0c042c20;
case 0x0c042c22u: goto P_0c042c22;
case 0x0c042c24u: goto P_0c042c24;
case 0x0c042c26u: goto P_0c042c26;
case 0x0c042c28u: goto P_0c042c28;
case 0x0c042c2au: goto P_0c042c2a;
case 0x0c042c2cu: goto P_0c042c2c;
case 0x0c042c2eu: goto P_0c042c2e;
case 0x0c042c30u: goto P_0c042c30;
case 0x0c042c32u: goto P_0c042c32;
case 0x0c042c34u: goto P_0c042c34;
case 0x0c042c36u: goto P_0c042c36;
case 0x0c042c38u: goto P_0c042c38;
case 0x0c042c3au: goto P_0c042c3a;
case 0x0c042c3cu: goto P_0c042c3c;
case 0x0c042c3eu: goto P_0c042c3e;
case 0x0c042c40u: goto P_0c042c40;
case 0x0c042c42u: goto P_0c042c42;
case 0x0c042c44u: goto P_0c042c44;
case 0x0c042c46u: goto P_0c042c46;
case 0x0c042c48u: goto P_0c042c48;
case 0x0c042c4au: goto P_0c042c4a;
case 0x0c042c4cu: goto P_0c042c4c;
case 0x0c042c4eu: goto P_0c042c4e;
case 0x0c042c50u: goto P_0c042c50;
case 0x0c042c52u: goto P_0c042c52;
case 0x0c042c54u: goto P_0c042c54;
case 0x0c042c56u: goto P_0c042c56;
case 0x0c042c58u: goto P_0c042c58;
case 0x0c042c5au: goto P_0c042c5a;
case 0x0c042c5cu: goto P_0c042c5c;
case 0x0c042c5eu: goto P_0c042c5e;
case 0x0c042c60u: goto P_0c042c60;
case 0x0c042c62u: goto P_0c042c62;
case 0x0c042c64u: goto P_0c042c64;
case 0x0c042c66u: goto P_0c042c66;
case 0x0c042c68u: goto P_0c042c68;
case 0x0c042c6au: goto P_0c042c6a;
case 0x0c042c6cu: goto P_0c042c6c;
case 0x0c042c6eu: goto P_0c042c6e;
case 0x0c042c70u: goto P_0c042c70;
case 0x0c042c72u: goto P_0c042c72;
case 0x0c042c74u: goto P_0c042c74;
case 0x0c042c76u: goto P_0c042c76;
case 0x0c042c78u: goto P_0c042c78;
case 0x0c042c7au: goto P_0c042c7a;
case 0x0c042c7cu: goto P_0c042c7c;
case 0x0c042c7eu: goto P_0c042c7e;
case 0x0c042c80u: goto P_0c042c80;
case 0x0c042c82u: goto P_0c042c82;
case 0x0c042c84u: goto P_0c042c84;
case 0x0c042c86u: goto P_0c042c86;
case 0x0c042c88u: goto P_0c042c88;
case 0x0c042c8au: goto P_0c042c8a;
case 0x0c042c8cu: goto P_0c042c8c;
case 0x0c042c8eu: goto P_0c042c8e;
case 0x0c042c90u: goto P_0c042c90;
case 0x0c042c92u: goto P_0c042c92;
case 0x0c042c94u: goto P_0c042c94;
case 0x0c042c96u: goto P_0c042c96;
case 0x0c042c98u: goto P_0c042c98;
case 0x0c042c9au: goto P_0c042c9a;
case 0x0c042c9cu: goto P_0c042c9c;
case 0x0c042c9eu: goto P_0c042c9e;
case 0x0c042ca0u: goto P_0c042ca0;
case 0x0c042ca2u: goto P_0c042ca2;
case 0x0c042ca4u: goto P_0c042ca4;
case 0x0c042ca6u: goto P_0c042ca6;
case 0x0c042ca8u: goto P_0c042ca8;
case 0x0c042caau: goto P_0c042caa;
case 0x0c042cacu: goto P_0c042cac;
case 0x0c042caeu: goto P_0c042cae;
case 0x0c042cb0u: goto P_0c042cb0;
case 0x0c042cb2u: goto P_0c042cb2;
case 0x0c042cb4u: goto P_0c042cb4;
case 0x0c042cb6u: goto P_0c042cb6;
case 0x0c042cb8u: goto P_0c042cb8;
case 0x0c042cbau: goto P_0c042cba;
case 0x0c042cbcu: goto P_0c042cbc;
case 0x0c042cbeu: goto P_0c042cbe;
case 0x0c042cc0u: goto P_0c042cc0;
case 0x0c042cc2u: goto P_0c042cc2;
case 0x0c042cc4u: goto P_0c042cc4;
case 0x0c042cc6u: goto P_0c042cc6;
case 0x0c042cc8u: goto P_0c042cc8;
case 0x0c042ccau: goto P_0c042cca;
case 0x0c042cd4u: goto P_0c042cd4;
case 0x0c042cd6u: goto P_0c042cd6;
case 0x0c042cd8u: goto P_0c042cd8;
case 0x0c042cdau: goto P_0c042cda;
case 0x0c042cdcu: goto P_0c042cdc;
case 0x0c042cdeu: goto P_0c042cde;
case 0x0c042ce0u: goto P_0c042ce0;
case 0x0c042ce2u: goto P_0c042ce2;
case 0x0c042ce4u: goto P_0c042ce4;
case 0x0c042ce6u: goto P_0c042ce6;
case 0x0c042ce8u: goto P_0c042ce8;
case 0x0c042ceau: goto P_0c042cea;
case 0x0c042cecu: goto P_0c042cec;
case 0x0c042ceeu: goto P_0c042cee;
case 0x0c042cf0u: goto P_0c042cf0;
case 0x0c042cf2u: goto P_0c042cf2;
case 0x0c042cf4u: goto P_0c042cf4;
case 0x0c042cf6u: goto P_0c042cf6;
case 0x0c042cf8u: goto P_0c042cf8;
case 0x0c042cfau: goto P_0c042cfa;
case 0x0c042cfcu: goto P_0c042cfc;
case 0x0c042cfeu: goto P_0c042cfe;
case 0x0c042d00u: goto P_0c042d00;
case 0x0c042d02u: goto P_0c042d02;
case 0x0c042d04u: goto P_0c042d04;
case 0x0c042d06u: goto P_0c042d06;
case 0x0c042d08u: goto P_0c042d08;
case 0x0c042d0au: goto P_0c042d0a;
case 0x0c042d0cu: goto P_0c042d0c;
case 0x0c042d0eu: goto P_0c042d0e;
case 0x0c042d10u: goto P_0c042d10;
case 0x0c042d12u: goto P_0c042d12;
case 0x0c042d14u: goto P_0c042d14;
case 0x0c042d16u: goto P_0c042d16;
case 0x0c042d18u: goto P_0c042d18;
case 0x0c042d1au: goto P_0c042d1a;
case 0x0c042d1cu: goto P_0c042d1c;
case 0x0c042d1eu: goto P_0c042d1e;
case 0x0c042d20u: goto P_0c042d20;
case 0x0c042d22u: goto P_0c042d22;
case 0x0c042d24u: goto P_0c042d24;
case 0x0c042d26u: goto P_0c042d26;
case 0x0c042d28u: goto P_0c042d28;
case 0x0c042d2au: goto P_0c042d2a;
case 0x0c042d2cu: goto P_0c042d2c;
case 0x0c042d2eu: goto P_0c042d2e;
case 0x0c042d30u: goto P_0c042d30;
case 0x0c042d32u: goto P_0c042d32;
case 0x0c042d34u: goto P_0c042d34;
case 0x0c042d36u: goto P_0c042d36;
case 0x0c042d38u: goto P_0c042d38;
case 0x0c042d3au: goto P_0c042d3a;
case 0x0c042d3cu: goto P_0c042d3c;
case 0x0c042d3eu: goto P_0c042d3e;
case 0x0c042d40u: goto P_0c042d40;
case 0x0c042d42u: goto P_0c042d42;
case 0x0c042d44u: goto P_0c042d44;
case 0x0c042d46u: goto P_0c042d46;
case 0x0c042d48u: goto P_0c042d48;
case 0x0c042d4au: goto P_0c042d4a;
case 0x0c042d4cu: goto P_0c042d4c;
case 0x0c042d4eu: goto P_0c042d4e;
case 0x0c042d50u: goto P_0c042d50;
case 0x0c042d52u: goto P_0c042d52;
case 0x0c042d54u: goto P_0c042d54;
case 0x0c042d56u: goto P_0c042d56;
case 0x0c042d58u: goto P_0c042d58;
case 0x0c042d5au: goto P_0c042d5a;
case 0x0c042d5cu: goto P_0c042d5c;
case 0x0c042d5eu: goto P_0c042d5e;
case 0x0c042d60u: goto P_0c042d60;
case 0x0c042d62u: goto P_0c042d62;
case 0x0c042d64u: goto P_0c042d64;
case 0x0c042d66u: goto P_0c042d66;
case 0x0c042d68u: goto P_0c042d68;
case 0x0c042d6au: goto P_0c042d6a;
case 0x0c042d6cu: goto P_0c042d6c;
case 0x0c042d6eu: goto P_0c042d6e;
case 0x0c042d70u: goto P_0c042d70;
case 0x0c042d72u: goto P_0c042d72;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c042c1e: /* original 4f22, guest PC 0x0c042c1e */
if(!s->budget--) { s->failed_pc=0x0c042c1eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c042c20;
P_0c042c20: /* original 2008, guest PC 0x0c042c20 */
if(!s->budget--) { s->failed_pc=0x0c042c20u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c042c22;
P_0c042c22: /* original 2f26, guest PC 0x0c042c22 */
if(!s->budget--) { s->failed_pc=0x0c042c22u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042c24;
P_0c042c24: /* original 8d4c, guest PC 0x0c042c24 */
if(!s->budget--) { s->failed_pc=0x0c042c24u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042cc0; }
goto P_0c042c28;
P_0c042c26: /* original 0009, guest PC 0x0c042c26 */
if(!s->budget--) { s->failed_pc=0x0c042c26u; return 0; }
goto P_0c042c28;
P_0c042c28: /* original 2f36, guest PC 0x0c042c28 */
if(!s->budget--) { s->failed_pc=0x0c042c28u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042c2a;
P_0c042c2a: /* original e200, guest PC 0x0c042c2a */
if(!s->budget--) { s->failed_pc=0x0c042c2au; return 0; }
r[2]=0x00000000u;
goto P_0c042c2c;
P_0c042c2c: /* original 2127, guest PC 0x0c042c2c */
if(!s->budget--) { s->failed_pc=0x0c042c2cu; return 0; }
r[17]=(r[17]&~0x301u)|((r[1]>>31)<<8)|((r[2]>>31)<<9)|(((r[1]^r[2])>>31)&1u);
goto P_0c042c2e;
P_0c042c2e: /* original 333a, guest PC 0x0c042c2e */
if(!s->budget--) { s->failed_pc=0x0c042c2eu; return 0; }
wide=(uint64_t)r[3]-r[3]-(r[17]&1u); r[3]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042c30;
P_0c042c30: /* original 312a, guest PC 0x0c042c30 */
if(!s->budget--) { s->failed_pc=0x0c042c30u; return 0; }
wide=(uint64_t)r[1]-r[2]-(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042c32;
P_0c042c32: /* original 2307, guest PC 0x0c042c32 */
if(!s->budget--) { s->failed_pc=0x0c042c32u; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[0]>>31)<<9)|(((r[3]^r[0])>>31)&1u);
goto P_0c042c34;
P_0c042c34: /* original 4124, guest PC 0x0c042c34 */
if(!s->budget--) { s->failed_pc=0x0c042c34u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c36;
P_0c042c36: /* original 3304, guest PC 0x0c042c36 */
if(!s->budget--) { s->failed_pc=0x0c042c36u; return 0; }
divide_step(s,3,0);
goto P_0c042c38;
P_0c042c38: /* original 4124, guest PC 0x0c042c38 */
if(!s->budget--) { s->failed_pc=0x0c042c38u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c3a;
P_0c042c3a: /* original 3304, guest PC 0x0c042c3a */
if(!s->budget--) { s->failed_pc=0x0c042c3au; return 0; }
divide_step(s,3,0);
goto P_0c042c3c;
P_0c042c3c: /* original 4124, guest PC 0x0c042c3c */
if(!s->budget--) { s->failed_pc=0x0c042c3cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c3e;
P_0c042c3e: /* original 3304, guest PC 0x0c042c3e */
if(!s->budget--) { s->failed_pc=0x0c042c3eu; return 0; }
divide_step(s,3,0);
goto P_0c042c40;
P_0c042c40: /* original 4124, guest PC 0x0c042c40 */
if(!s->budget--) { s->failed_pc=0x0c042c40u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c42;
P_0c042c42: /* original 3304, guest PC 0x0c042c42 */
if(!s->budget--) { s->failed_pc=0x0c042c42u; return 0; }
divide_step(s,3,0);
goto P_0c042c44;
P_0c042c44: /* original 4124, guest PC 0x0c042c44 */
if(!s->budget--) { s->failed_pc=0x0c042c44u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c46;
P_0c042c46: /* original 3304, guest PC 0x0c042c46 */
if(!s->budget--) { s->failed_pc=0x0c042c46u; return 0; }
divide_step(s,3,0);
goto P_0c042c48;
P_0c042c48: /* original 4124, guest PC 0x0c042c48 */
if(!s->budget--) { s->failed_pc=0x0c042c48u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c4a;
P_0c042c4a: /* original 3304, guest PC 0x0c042c4a */
if(!s->budget--) { s->failed_pc=0x0c042c4au; return 0; }
divide_step(s,3,0);
goto P_0c042c4c;
P_0c042c4c: /* original 4124, guest PC 0x0c042c4c */
if(!s->budget--) { s->failed_pc=0x0c042c4cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c4e;
P_0c042c4e: /* original 3304, guest PC 0x0c042c4e */
if(!s->budget--) { s->failed_pc=0x0c042c4eu; return 0; }
divide_step(s,3,0);
goto P_0c042c50;
P_0c042c50: /* original 4124, guest PC 0x0c042c50 */
if(!s->budget--) { s->failed_pc=0x0c042c50u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c52;
P_0c042c52: /* original 3304, guest PC 0x0c042c52 */
if(!s->budget--) { s->failed_pc=0x0c042c52u; return 0; }
divide_step(s,3,0);
goto P_0c042c54;
P_0c042c54: /* original 4124, guest PC 0x0c042c54 */
if(!s->budget--) { s->failed_pc=0x0c042c54u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c56;
P_0c042c56: /* original 3304, guest PC 0x0c042c56 */
if(!s->budget--) { s->failed_pc=0x0c042c56u; return 0; }
divide_step(s,3,0);
goto P_0c042c58;
P_0c042c58: /* original 4124, guest PC 0x0c042c58 */
if(!s->budget--) { s->failed_pc=0x0c042c58u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c5a;
P_0c042c5a: /* original 3304, guest PC 0x0c042c5a */
if(!s->budget--) { s->failed_pc=0x0c042c5au; return 0; }
divide_step(s,3,0);
goto P_0c042c5c;
P_0c042c5c: /* original 4124, guest PC 0x0c042c5c */
if(!s->budget--) { s->failed_pc=0x0c042c5cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c5e;
P_0c042c5e: /* original 3304, guest PC 0x0c042c5e */
if(!s->budget--) { s->failed_pc=0x0c042c5eu; return 0; }
divide_step(s,3,0);
goto P_0c042c60;
P_0c042c60: /* original 4124, guest PC 0x0c042c60 */
if(!s->budget--) { s->failed_pc=0x0c042c60u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c62;
P_0c042c62: /* original 3304, guest PC 0x0c042c62 */
if(!s->budget--) { s->failed_pc=0x0c042c62u; return 0; }
divide_step(s,3,0);
goto P_0c042c64;
P_0c042c64: /* original 4124, guest PC 0x0c042c64 */
if(!s->budget--) { s->failed_pc=0x0c042c64u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c66;
P_0c042c66: /* original 3304, guest PC 0x0c042c66 */
if(!s->budget--) { s->failed_pc=0x0c042c66u; return 0; }
divide_step(s,3,0);
goto P_0c042c68;
P_0c042c68: /* original 4124, guest PC 0x0c042c68 */
if(!s->budget--) { s->failed_pc=0x0c042c68u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c6a;
P_0c042c6a: /* original 3304, guest PC 0x0c042c6a */
if(!s->budget--) { s->failed_pc=0x0c042c6au; return 0; }
divide_step(s,3,0);
goto P_0c042c6c;
P_0c042c6c: /* original 4124, guest PC 0x0c042c6c */
if(!s->budget--) { s->failed_pc=0x0c042c6cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c6e;
P_0c042c6e: /* original 3304, guest PC 0x0c042c6e */
if(!s->budget--) { s->failed_pc=0x0c042c6eu; return 0; }
divide_step(s,3,0);
goto P_0c042c70;
P_0c042c70: /* original 4124, guest PC 0x0c042c70 */
if(!s->budget--) { s->failed_pc=0x0c042c70u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c72;
P_0c042c72: /* original 3304, guest PC 0x0c042c72 */
if(!s->budget--) { s->failed_pc=0x0c042c72u; return 0; }
divide_step(s,3,0);
goto P_0c042c74;
P_0c042c74: /* original 4124, guest PC 0x0c042c74 */
if(!s->budget--) { s->failed_pc=0x0c042c74u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c76;
P_0c042c76: /* original 3304, guest PC 0x0c042c76 */
if(!s->budget--) { s->failed_pc=0x0c042c76u; return 0; }
divide_step(s,3,0);
goto P_0c042c78;
P_0c042c78: /* original 4124, guest PC 0x0c042c78 */
if(!s->budget--) { s->failed_pc=0x0c042c78u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c7a;
P_0c042c7a: /* original 3304, guest PC 0x0c042c7a */
if(!s->budget--) { s->failed_pc=0x0c042c7au; return 0; }
divide_step(s,3,0);
goto P_0c042c7c;
P_0c042c7c: /* original 4124, guest PC 0x0c042c7c */
if(!s->budget--) { s->failed_pc=0x0c042c7cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c7e;
P_0c042c7e: /* original 3304, guest PC 0x0c042c7e */
if(!s->budget--) { s->failed_pc=0x0c042c7eu; return 0; }
divide_step(s,3,0);
goto P_0c042c80;
P_0c042c80: /* original 4124, guest PC 0x0c042c80 */
if(!s->budget--) { s->failed_pc=0x0c042c80u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c82;
P_0c042c82: /* original 3304, guest PC 0x0c042c82 */
if(!s->budget--) { s->failed_pc=0x0c042c82u; return 0; }
divide_step(s,3,0);
goto P_0c042c84;
P_0c042c84: /* original 4124, guest PC 0x0c042c84 */
if(!s->budget--) { s->failed_pc=0x0c042c84u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c86;
P_0c042c86: /* original 3304, guest PC 0x0c042c86 */
if(!s->budget--) { s->failed_pc=0x0c042c86u; return 0; }
divide_step(s,3,0);
goto P_0c042c88;
P_0c042c88: /* original 4124, guest PC 0x0c042c88 */
if(!s->budget--) { s->failed_pc=0x0c042c88u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c8a;
P_0c042c8a: /* original 3304, guest PC 0x0c042c8a */
if(!s->budget--) { s->failed_pc=0x0c042c8au; return 0; }
divide_step(s,3,0);
goto P_0c042c8c;
P_0c042c8c: /* original 4124, guest PC 0x0c042c8c */
if(!s->budget--) { s->failed_pc=0x0c042c8cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c8e;
P_0c042c8e: /* original 3304, guest PC 0x0c042c8e */
if(!s->budget--) { s->failed_pc=0x0c042c8eu; return 0; }
divide_step(s,3,0);
goto P_0c042c90;
P_0c042c90: /* original 4124, guest PC 0x0c042c90 */
if(!s->budget--) { s->failed_pc=0x0c042c90u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c92;
P_0c042c92: /* original 3304, guest PC 0x0c042c92 */
if(!s->budget--) { s->failed_pc=0x0c042c92u; return 0; }
divide_step(s,3,0);
goto P_0c042c94;
P_0c042c94: /* original 4124, guest PC 0x0c042c94 */
if(!s->budget--) { s->failed_pc=0x0c042c94u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c96;
P_0c042c96: /* original 3304, guest PC 0x0c042c96 */
if(!s->budget--) { s->failed_pc=0x0c042c96u; return 0; }
divide_step(s,3,0);
goto P_0c042c98;
P_0c042c98: /* original 4124, guest PC 0x0c042c98 */
if(!s->budget--) { s->failed_pc=0x0c042c98u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c9a;
P_0c042c9a: /* original 3304, guest PC 0x0c042c9a */
if(!s->budget--) { s->failed_pc=0x0c042c9au; return 0; }
divide_step(s,3,0);
goto P_0c042c9c;
P_0c042c9c: /* original 4124, guest PC 0x0c042c9c */
if(!s->budget--) { s->failed_pc=0x0c042c9cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c9e;
P_0c042c9e: /* original 3304, guest PC 0x0c042c9e */
if(!s->budget--) { s->failed_pc=0x0c042c9eu; return 0; }
divide_step(s,3,0);
goto P_0c042ca0;
P_0c042ca0: /* original 4124, guest PC 0x0c042ca0 */
if(!s->budget--) { s->failed_pc=0x0c042ca0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ca2;
P_0c042ca2: /* original 3304, guest PC 0x0c042ca2 */
if(!s->budget--) { s->failed_pc=0x0c042ca2u; return 0; }
divide_step(s,3,0);
goto P_0c042ca4;
P_0c042ca4: /* original 4124, guest PC 0x0c042ca4 */
if(!s->budget--) { s->failed_pc=0x0c042ca4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ca6;
P_0c042ca6: /* original 3304, guest PC 0x0c042ca6 */
if(!s->budget--) { s->failed_pc=0x0c042ca6u; return 0; }
divide_step(s,3,0);
goto P_0c042ca8;
P_0c042ca8: /* original 4124, guest PC 0x0c042ca8 */
if(!s->budget--) { s->failed_pc=0x0c042ca8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042caa;
P_0c042caa: /* original 3304, guest PC 0x0c042caa */
if(!s->budget--) { s->failed_pc=0x0c042caau; return 0; }
divide_step(s,3,0);
goto P_0c042cac;
P_0c042cac: /* original 4124, guest PC 0x0c042cac */
if(!s->budget--) { s->failed_pc=0x0c042cacu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cae;
P_0c042cae: /* original 3304, guest PC 0x0c042cae */
if(!s->budget--) { s->failed_pc=0x0c042caeu; return 0; }
divide_step(s,3,0);
goto P_0c042cb0;
P_0c042cb0: /* original 4124, guest PC 0x0c042cb0 */
if(!s->budget--) { s->failed_pc=0x0c042cb0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cb2;
P_0c042cb2: /* original 3304, guest PC 0x0c042cb2 */
if(!s->budget--) { s->failed_pc=0x0c042cb2u; return 0; }
divide_step(s,3,0);
goto P_0c042cb4;
P_0c042cb4: /* original 4124, guest PC 0x0c042cb4 */
if(!s->budget--) { s->failed_pc=0x0c042cb4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cb6;
P_0c042cb6: /* original 312e, guest PC 0x0c042cb6 */
if(!s->budget--) { s->failed_pc=0x0c042cb6u; return 0; }
wide=(uint64_t)r[1]+r[2]+(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042cb8;
P_0c042cb8: /* original 6013, guest PC 0x0c042cb8 */
if(!s->budget--) { s->failed_pc=0x0c042cb8u; return 0; }
r[0]=r[1];
goto P_0c042cba;
P_0c042cba: /* original 63f6, guest PC 0x0c042cba */
if(!s->budget--) { s->failed_pc=0x0c042cbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042cbc;
P_0c042cbc: /* original 000b, guest PC 0x0c042cbc */
if(!s->budget--) { s->failed_pc=0x0c042cbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042cbe: /* original 62f6, guest PC 0x0c042cbe */
if(!s->budget--) { s->failed_pc=0x0c042cbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c042cc0;
P_0c042cc0: /* original d102, guest PC 0x0c042cc0 */
if(!s->budget--) { s->failed_pc=0x0c042cc0u; return 0; }
r[1]=read(ram,0x0c042cccu,4);
goto P_0c042cc2;
P_0c042cc2: /* original d203, guest PC 0x0c042cc2 */
if(!s->budget--) { s->failed_pc=0x0c042cc2u; return 0; }
r[2]=read(ram,0x0c042cd0u,4);
goto P_0c042cc4;
P_0c042cc4: /* original e000, guest PC 0x0c042cc4 */
if(!s->budget--) { s->failed_pc=0x0c042cc4u; return 0; }
r[0]=0x00000000u;
goto P_0c042cc6;
P_0c042cc6: /* original 2122, guest PC 0x0c042cc6 */
if(!s->budget--) { s->failed_pc=0x0c042cc6u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c042cc8;
P_0c042cc8: /* original 000b, guest PC 0x0c042cc8 */
if(!s->budget--) { s->failed_pc=0x0c042cc8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042cca: /* original 62f6, guest PC 0x0c042cca */
if(!s->budget--) { s->failed_pc=0x0c042ccau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042cccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042cccu; return 0; } return 1;
P_0c042cd4: /* original 2008, guest PC 0x0c042cd4 */
if(!s->budget--) { s->failed_pc=0x0c042cd4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c042cd6;
P_0c042cd6: /* original 2f26, guest PC 0x0c042cd6 */
if(!s->budget--) { s->failed_pc=0x0c042cd6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042cd8;
P_0c042cd8: /* original 8d46, guest PC 0x0c042cd8 */
if(!s->budget--) { s->failed_pc=0x0c042cd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042d68; }
goto P_0c042cdc;
P_0c042cda: /* original 0009, guest PC 0x0c042cda */
if(!s->budget--) { s->failed_pc=0x0c042cdau; return 0; }
goto P_0c042cdc;
P_0c042cdc: /* original e200, guest PC 0x0c042cdc */
if(!s->budget--) { s->failed_pc=0x0c042cdcu; return 0; }
r[2]=0x00000000u;
goto P_0c042cde;
P_0c042cde: /* original 0019, guest PC 0x0c042cde */
if(!s->budget--) { s->failed_pc=0x0c042cdeu; return 0; }
r[17]&=~0x301u;
goto P_0c042ce0;
P_0c042ce0: /* original 4124, guest PC 0x0c042ce0 */
if(!s->budget--) { s->failed_pc=0x0c042ce0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ce2;
P_0c042ce2: /* original 3204, guest PC 0x0c042ce2 */
if(!s->budget--) { s->failed_pc=0x0c042ce2u; return 0; }
divide_step(s,2,0);
goto P_0c042ce4;
P_0c042ce4: /* original 4124, guest PC 0x0c042ce4 */
if(!s->budget--) { s->failed_pc=0x0c042ce4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ce6;
P_0c042ce6: /* original 3204, guest PC 0x0c042ce6 */
if(!s->budget--) { s->failed_pc=0x0c042ce6u; return 0; }
divide_step(s,2,0);
goto P_0c042ce8;
P_0c042ce8: /* original 4124, guest PC 0x0c042ce8 */
if(!s->budget--) { s->failed_pc=0x0c042ce8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cea;
P_0c042cea: /* original 3204, guest PC 0x0c042cea */
if(!s->budget--) { s->failed_pc=0x0c042ceau; return 0; }
divide_step(s,2,0);
goto P_0c042cec;
P_0c042cec: /* original 4124, guest PC 0x0c042cec */
if(!s->budget--) { s->failed_pc=0x0c042cecu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cee;
P_0c042cee: /* original 3204, guest PC 0x0c042cee */
if(!s->budget--) { s->failed_pc=0x0c042ceeu; return 0; }
divide_step(s,2,0);
goto P_0c042cf0;
P_0c042cf0: /* original 4124, guest PC 0x0c042cf0 */
if(!s->budget--) { s->failed_pc=0x0c042cf0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cf2;
P_0c042cf2: /* original 3204, guest PC 0x0c042cf2 */
if(!s->budget--) { s->failed_pc=0x0c042cf2u; return 0; }
divide_step(s,2,0);
goto P_0c042cf4;
P_0c042cf4: /* original 4124, guest PC 0x0c042cf4 */
if(!s->budget--) { s->failed_pc=0x0c042cf4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cf6;
P_0c042cf6: /* original 3204, guest PC 0x0c042cf6 */
if(!s->budget--) { s->failed_pc=0x0c042cf6u; return 0; }
divide_step(s,2,0);
goto P_0c042cf8;
P_0c042cf8: /* original 4124, guest PC 0x0c042cf8 */
if(!s->budget--) { s->failed_pc=0x0c042cf8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cfa;
P_0c042cfa: /* original 3204, guest PC 0x0c042cfa */
if(!s->budget--) { s->failed_pc=0x0c042cfau; return 0; }
divide_step(s,2,0);
goto P_0c042cfc;
P_0c042cfc: /* original 4124, guest PC 0x0c042cfc */
if(!s->budget--) { s->failed_pc=0x0c042cfcu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cfe;
P_0c042cfe: /* original 3204, guest PC 0x0c042cfe */
if(!s->budget--) { s->failed_pc=0x0c042cfeu; return 0; }
divide_step(s,2,0);
goto P_0c042d00;
P_0c042d00: /* original 4124, guest PC 0x0c042d00 */
if(!s->budget--) { s->failed_pc=0x0c042d00u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d02;
P_0c042d02: /* original 3204, guest PC 0x0c042d02 */
if(!s->budget--) { s->failed_pc=0x0c042d02u; return 0; }
divide_step(s,2,0);
goto P_0c042d04;
P_0c042d04: /* original 4124, guest PC 0x0c042d04 */
if(!s->budget--) { s->failed_pc=0x0c042d04u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d06;
P_0c042d06: /* original 3204, guest PC 0x0c042d06 */
if(!s->budget--) { s->failed_pc=0x0c042d06u; return 0; }
divide_step(s,2,0);
goto P_0c042d08;
P_0c042d08: /* original 4124, guest PC 0x0c042d08 */
if(!s->budget--) { s->failed_pc=0x0c042d08u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d0a;
P_0c042d0a: /* original 3204, guest PC 0x0c042d0a */
if(!s->budget--) { s->failed_pc=0x0c042d0au; return 0; }
divide_step(s,2,0);
goto P_0c042d0c;
P_0c042d0c: /* original 4124, guest PC 0x0c042d0c */
if(!s->budget--) { s->failed_pc=0x0c042d0cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d0e;
P_0c042d0e: /* original 3204, guest PC 0x0c042d0e */
if(!s->budget--) { s->failed_pc=0x0c042d0eu; return 0; }
divide_step(s,2,0);
goto P_0c042d10;
P_0c042d10: /* original 4124, guest PC 0x0c042d10 */
if(!s->budget--) { s->failed_pc=0x0c042d10u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d12;
P_0c042d12: /* original 3204, guest PC 0x0c042d12 */
if(!s->budget--) { s->failed_pc=0x0c042d12u; return 0; }
divide_step(s,2,0);
goto P_0c042d14;
P_0c042d14: /* original 4124, guest PC 0x0c042d14 */
if(!s->budget--) { s->failed_pc=0x0c042d14u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d16;
P_0c042d16: /* original 3204, guest PC 0x0c042d16 */
if(!s->budget--) { s->failed_pc=0x0c042d16u; return 0; }
divide_step(s,2,0);
goto P_0c042d18;
P_0c042d18: /* original 4124, guest PC 0x0c042d18 */
if(!s->budget--) { s->failed_pc=0x0c042d18u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d1a;
P_0c042d1a: /* original 3204, guest PC 0x0c042d1a */
if(!s->budget--) { s->failed_pc=0x0c042d1au; return 0; }
divide_step(s,2,0);
goto P_0c042d1c;
P_0c042d1c: /* original 4124, guest PC 0x0c042d1c */
if(!s->budget--) { s->failed_pc=0x0c042d1cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d1e;
P_0c042d1e: /* original 3204, guest PC 0x0c042d1e */
if(!s->budget--) { s->failed_pc=0x0c042d1eu; return 0; }
divide_step(s,2,0);
goto P_0c042d20;
P_0c042d20: /* original 4124, guest PC 0x0c042d20 */
if(!s->budget--) { s->failed_pc=0x0c042d20u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d22;
P_0c042d22: /* original 3204, guest PC 0x0c042d22 */
if(!s->budget--) { s->failed_pc=0x0c042d22u; return 0; }
divide_step(s,2,0);
goto P_0c042d24;
P_0c042d24: /* original 4124, guest PC 0x0c042d24 */
if(!s->budget--) { s->failed_pc=0x0c042d24u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d26;
P_0c042d26: /* original 3204, guest PC 0x0c042d26 */
if(!s->budget--) { s->failed_pc=0x0c042d26u; return 0; }
divide_step(s,2,0);
goto P_0c042d28;
P_0c042d28: /* original 4124, guest PC 0x0c042d28 */
if(!s->budget--) { s->failed_pc=0x0c042d28u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d2a;
P_0c042d2a: /* original 3204, guest PC 0x0c042d2a */
if(!s->budget--) { s->failed_pc=0x0c042d2au; return 0; }
divide_step(s,2,0);
goto P_0c042d2c;
P_0c042d2c: /* original 4124, guest PC 0x0c042d2c */
if(!s->budget--) { s->failed_pc=0x0c042d2cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d2e;
P_0c042d2e: /* original 3204, guest PC 0x0c042d2e */
if(!s->budget--) { s->failed_pc=0x0c042d2eu; return 0; }
divide_step(s,2,0);
goto P_0c042d30;
P_0c042d30: /* original 4124, guest PC 0x0c042d30 */
if(!s->budget--) { s->failed_pc=0x0c042d30u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d32;
P_0c042d32: /* original 3204, guest PC 0x0c042d32 */
if(!s->budget--) { s->failed_pc=0x0c042d32u; return 0; }
divide_step(s,2,0);
goto P_0c042d34;
P_0c042d34: /* original 4124, guest PC 0x0c042d34 */
if(!s->budget--) { s->failed_pc=0x0c042d34u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d36;
P_0c042d36: /* original 3204, guest PC 0x0c042d36 */
if(!s->budget--) { s->failed_pc=0x0c042d36u; return 0; }
divide_step(s,2,0);
goto P_0c042d38;
P_0c042d38: /* original 4124, guest PC 0x0c042d38 */
if(!s->budget--) { s->failed_pc=0x0c042d38u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d3a;
P_0c042d3a: /* original 3204, guest PC 0x0c042d3a */
if(!s->budget--) { s->failed_pc=0x0c042d3au; return 0; }
divide_step(s,2,0);
goto P_0c042d3c;
P_0c042d3c: /* original 4124, guest PC 0x0c042d3c */
if(!s->budget--) { s->failed_pc=0x0c042d3cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d3e;
P_0c042d3e: /* original 3204, guest PC 0x0c042d3e */
if(!s->budget--) { s->failed_pc=0x0c042d3eu; return 0; }
divide_step(s,2,0);
goto P_0c042d40;
P_0c042d40: /* original 4124, guest PC 0x0c042d40 */
if(!s->budget--) { s->failed_pc=0x0c042d40u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d42;
P_0c042d42: /* original 3204, guest PC 0x0c042d42 */
if(!s->budget--) { s->failed_pc=0x0c042d42u; return 0; }
divide_step(s,2,0);
goto P_0c042d44;
P_0c042d44: /* original 4124, guest PC 0x0c042d44 */
if(!s->budget--) { s->failed_pc=0x0c042d44u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d46;
P_0c042d46: /* original 3204, guest PC 0x0c042d46 */
if(!s->budget--) { s->failed_pc=0x0c042d46u; return 0; }
divide_step(s,2,0);
goto P_0c042d48;
P_0c042d48: /* original 4124, guest PC 0x0c042d48 */
if(!s->budget--) { s->failed_pc=0x0c042d48u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d4a;
P_0c042d4a: /* original 3204, guest PC 0x0c042d4a */
if(!s->budget--) { s->failed_pc=0x0c042d4au; return 0; }
divide_step(s,2,0);
goto P_0c042d4c;
P_0c042d4c: /* original 4124, guest PC 0x0c042d4c */
if(!s->budget--) { s->failed_pc=0x0c042d4cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d4e;
P_0c042d4e: /* original 3204, guest PC 0x0c042d4e */
if(!s->budget--) { s->failed_pc=0x0c042d4eu; return 0; }
divide_step(s,2,0);
goto P_0c042d50;
P_0c042d50: /* original 4124, guest PC 0x0c042d50 */
if(!s->budget--) { s->failed_pc=0x0c042d50u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d52;
P_0c042d52: /* original 3204, guest PC 0x0c042d52 */
if(!s->budget--) { s->failed_pc=0x0c042d52u; return 0; }
divide_step(s,2,0);
goto P_0c042d54;
P_0c042d54: /* original 4124, guest PC 0x0c042d54 */
if(!s->budget--) { s->failed_pc=0x0c042d54u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d56;
P_0c042d56: /* original 3204, guest PC 0x0c042d56 */
if(!s->budget--) { s->failed_pc=0x0c042d56u; return 0; }
divide_step(s,2,0);
goto P_0c042d58;
P_0c042d58: /* original 4124, guest PC 0x0c042d58 */
if(!s->budget--) { s->failed_pc=0x0c042d58u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d5a;
P_0c042d5a: /* original 3204, guest PC 0x0c042d5a */
if(!s->budget--) { s->failed_pc=0x0c042d5au; return 0; }
divide_step(s,2,0);
goto P_0c042d5c;
P_0c042d5c: /* original 4124, guest PC 0x0c042d5c */
if(!s->budget--) { s->failed_pc=0x0c042d5cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d5e;
P_0c042d5e: /* original 3204, guest PC 0x0c042d5e */
if(!s->budget--) { s->failed_pc=0x0c042d5eu; return 0; }
divide_step(s,2,0);
goto P_0c042d60;
P_0c042d60: /* original 4124, guest PC 0x0c042d60 */
if(!s->budget--) { s->failed_pc=0x0c042d60u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d62;
P_0c042d62: /* original 6013, guest PC 0x0c042d62 */
if(!s->budget--) { s->failed_pc=0x0c042d62u; return 0; }
r[0]=r[1];
goto P_0c042d64;
P_0c042d64: /* original 000b, guest PC 0x0c042d64 */
if(!s->budget--) { s->failed_pc=0x0c042d64u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042d66: /* original 62f6, guest PC 0x0c042d66 */
if(!s->budget--) { s->failed_pc=0x0c042d66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c042d68;
P_0c042d68: /* original d202, guest PC 0x0c042d68 */
if(!s->budget--) { s->failed_pc=0x0c042d68u; return 0; }
r[2]=read(ram,0x0c042d74u,4);
goto P_0c042d6a;
P_0c042d6a: /* original d103, guest PC 0x0c042d6a */
if(!s->budget--) { s->failed_pc=0x0c042d6au; return 0; }
r[1]=read(ram,0x0c042d78u,4);
goto P_0c042d6c;
P_0c042d6c: /* original e000, guest PC 0x0c042d6c */
if(!s->budget--) { s->failed_pc=0x0c042d6cu; return 0; }
r[0]=0x00000000u;
goto P_0c042d6e;
P_0c042d6e: /* original 2212, guest PC 0x0c042d6e */
if(!s->budget--) { s->failed_pc=0x0c042d6eu; return 0; }
write(ram,r[2],r[1],4);
goto P_0c042d70;
P_0c042d70: /* original 000b, guest PC 0x0c042d70 */
if(!s->budget--) { s->failed_pc=0x0c042d70u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042d72: /* original 62f6, guest PC 0x0c042d72 */
if(!s->budget--) { s->failed_pc=0x0c042d72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042d74u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042d74u; return 0; } return 1;
P_0c042e44: /* original 2008, guest PC 0x0c042e44 */
if(!s->budget--) { s->failed_pc=0x0c042e44u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c042e46;
P_0c042e46: /* original 8d4e, guest PC 0x0c042e46 */
if(!s->budget--) { s->failed_pc=0x0c042e46u; return 0; }
cond=r[17]&1u;
if(cond) { return vf3_matrix_family(0x0c042ee6u,s,ram); }
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
if(!cond) { return vf3_matrix_family(0x0c042edeu,s,ram); }
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
return vf3_matrix_family(0x0c042edeu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
