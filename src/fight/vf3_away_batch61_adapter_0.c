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
int vf3_away_batch61_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042d7cu: goto P_0c042d7c;
case 0x0c042d7eu: goto P_0c042d7e;
case 0x0c042d80u: goto P_0c042d80;
case 0x0c042d82u: goto P_0c042d82;
case 0x0c042d84u: goto P_0c042d84;
case 0x0c042d86u: goto P_0c042d86;
case 0x0c042d88u: goto P_0c042d88;
case 0x0c042d8au: goto P_0c042d8a;
case 0x0c042d8cu: goto P_0c042d8c;
case 0x0c042d8eu: goto P_0c042d8e;
case 0x0c042d90u: goto P_0c042d90;
case 0x0c042d92u: goto P_0c042d92;
case 0x0c042d94u: goto P_0c042d94;
case 0x0c042d96u: goto P_0c042d96;
case 0x0c042d98u: goto P_0c042d98;
case 0x0c042d9au: goto P_0c042d9a;
case 0x0c042d9cu: goto P_0c042d9c;
case 0x0c042d9eu: goto P_0c042d9e;
case 0x0c042da0u: goto P_0c042da0;
case 0x0c042da2u: goto P_0c042da2;
case 0x0c042da4u: goto P_0c042da4;
case 0x0c042da6u: goto P_0c042da6;
case 0x0c042da8u: goto P_0c042da8;
case 0x0c042daau: goto P_0c042daa;
case 0x0c042dacu: goto P_0c042dac;
case 0x0c042daeu: goto P_0c042dae;
case 0x0c042db0u: goto P_0c042db0;
case 0x0c042db2u: goto P_0c042db2;
case 0x0c042db4u: goto P_0c042db4;
case 0x0c042db6u: goto P_0c042db6;
case 0x0c042db8u: goto P_0c042db8;
case 0x0c042dbau: goto P_0c042dba;
case 0x0c042dbcu: goto P_0c042dbc;
case 0x0c042dbeu: goto P_0c042dbe;
case 0x0c042dc0u: goto P_0c042dc0;
case 0x0c042dc2u: goto P_0c042dc2;
case 0x0c042dc4u: goto P_0c042dc4;
case 0x0c042dc6u: goto P_0c042dc6;
case 0x0c042dc8u: goto P_0c042dc8;
case 0x0c042dcau: goto P_0c042dca;
case 0x0c042dccu: goto P_0c042dcc;
case 0x0c042dceu: goto P_0c042dce;
case 0x0c042dd0u: goto P_0c042dd0;
case 0x0c042dd2u: goto P_0c042dd2;
case 0x0c042dd4u: goto P_0c042dd4;
case 0x0c042dd6u: goto P_0c042dd6;
case 0x0c042dd8u: goto P_0c042dd8;
case 0x0c042ddau: goto P_0c042dda;
case 0x0c042ddcu: goto P_0c042ddc;
case 0x0c042ddeu: goto P_0c042dde;
case 0x0c042de0u: goto P_0c042de0;
case 0x0c042de2u: goto P_0c042de2;
case 0x0c042de4u: goto P_0c042de4;
case 0x0c042de6u: goto P_0c042de6;
case 0x0c042de8u: goto P_0c042de8;
case 0x0c042deau: goto P_0c042dea;
case 0x0c042decu: goto P_0c042dec;
case 0x0c042deeu: goto P_0c042dee;
case 0x0c042df0u: goto P_0c042df0;
case 0x0c042df2u: goto P_0c042df2;
case 0x0c042df4u: goto P_0c042df4;
case 0x0c042df6u: goto P_0c042df6;
case 0x0c042df8u: goto P_0c042df8;
case 0x0c042dfau: goto P_0c042dfa;
case 0x0c042dfcu: goto P_0c042dfc;
case 0x0c042dfeu: goto P_0c042dfe;
case 0x0c042e00u: goto P_0c042e00;
case 0x0c042e02u: goto P_0c042e02;
case 0x0c042e04u: goto P_0c042e04;
case 0x0c042e06u: goto P_0c042e06;
case 0x0c042e08u: goto P_0c042e08;
case 0x0c042e0au: goto P_0c042e0a;
case 0x0c042e0cu: goto P_0c042e0c;
case 0x0c042e0eu: goto P_0c042e0e;
case 0x0c042e10u: goto P_0c042e10;
case 0x0c042e12u: goto P_0c042e12;
case 0x0c042e14u: goto P_0c042e14;
case 0x0c042e16u: goto P_0c042e16;
case 0x0c042e18u: goto P_0c042e18;
case 0x0c042e1au: goto P_0c042e1a;
case 0x0c042e1cu: goto P_0c042e1c;
case 0x0c042e1eu: goto P_0c042e1e;
case 0x0c042e20u: goto P_0c042e20;
case 0x0c042e22u: goto P_0c042e22;
case 0x0c042e24u: goto P_0c042e24;
case 0x0c042e26u: goto P_0c042e26;
case 0x0c042e28u: goto P_0c042e28;
case 0x0c042e2au: goto P_0c042e2a;
case 0x0c042e2cu: goto P_0c042e2c;
case 0x0c042e2eu: goto P_0c042e2e;
case 0x0c042e30u: goto P_0c042e30;
case 0x0c042e32u: goto P_0c042e32;
case 0x0c042e34u: goto P_0c042e34;
case 0x0c042e36u: goto P_0c042e36;
case 0x0c042e38u: goto P_0c042e38;
case 0x0c042e3au: goto P_0c042e3a;
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
case 0x0c08d0eeu: goto P_0c08d0ee;
case 0x0c08d0f0u: goto P_0c08d0f0;
case 0x0c08d0f2u: goto P_0c08d0f2;
case 0x0c08d0f4u: goto P_0c08d0f4;
case 0x0c08d0f6u: goto P_0c08d0f6;
case 0x0c08d0f8u: goto P_0c08d0f8;
case 0x0c08d0fau: goto P_0c08d0fa;
case 0x0c08d0fcu: goto P_0c08d0fc;
case 0x0c08d0feu: goto P_0c08d0fe;
case 0x0c08d100u: goto P_0c08d100;
case 0x0c08d102u: goto P_0c08d102;
case 0x0c08d104u: goto P_0c08d104;
case 0x0c08d106u: goto P_0c08d106;
case 0x0c08d108u: goto P_0c08d108;
case 0x0c08d10au: goto P_0c08d10a;
case 0x0c08d10cu: goto P_0c08d10c;
case 0x0c08d10eu: goto P_0c08d10e;
case 0x0c08d110u: goto P_0c08d110;
case 0x0c08d112u: goto P_0c08d112;
case 0x0c08d114u: goto P_0c08d114;
case 0x0c08d116u: goto P_0c08d116;
case 0x0c08d118u: goto P_0c08d118;
case 0x0c08d11au: goto P_0c08d11a;
case 0x0c08d11cu: goto P_0c08d11c;
case 0x0c08d11eu: goto P_0c08d11e;
case 0x0c08d120u: goto P_0c08d120;
case 0x0c08d122u: goto P_0c08d122;
case 0x0c08d124u: goto P_0c08d124;
case 0x0c08d126u: goto P_0c08d126;
case 0x0c08d128u: goto P_0c08d128;
case 0x0c08d12au: goto P_0c08d12a;
case 0x0c08d12cu: goto P_0c08d12c;
case 0x0c08d148u: goto P_0c08d148;
case 0x0c08d14au: goto P_0c08d14a;
case 0x0c08d14cu: goto P_0c08d14c;
case 0x0c08d14eu: goto P_0c08d14e;
case 0x0c08d150u: goto P_0c08d150;
case 0x0c08d152u: goto P_0c08d152;
case 0x0c08d154u: goto P_0c08d154;
case 0x0c08d156u: goto P_0c08d156;
default: return vf3_matrix_family(target,s,ram);
}
P_0c042d7c: /* original 2008, guest PC 0x0c042d7c */
if(!s->budget--) { s->failed_pc=0x0c042d7cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c042d7e;
P_0c042d7e: /* original 2f26, guest PC 0x0c042d7e */
if(!s->budget--) { s->failed_pc=0x0c042d7eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042d80;
P_0c042d80: /* original 8d56, guest PC 0x0c042d80 */
if(!s->budget--) { s->failed_pc=0x0c042d80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042e30; }
goto P_0c042d84;
P_0c042d82: /* original 0009, guest PC 0x0c042d82 */
if(!s->budget--) { s->failed_pc=0x0c042d82u; return 0; }
goto P_0c042d84;
P_0c042d84: /* original 2f36, guest PC 0x0c042d84 */
if(!s->budget--) { s->failed_pc=0x0c042d84u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042d86;
P_0c042d86: /* original e200, guest PC 0x0c042d86 */
if(!s->budget--) { s->failed_pc=0x0c042d86u; return 0; }
r[2]=0x00000000u;
goto P_0c042d88;
P_0c042d88: /* original 2f46, guest PC 0x0c042d88 */
if(!s->budget--) { s->failed_pc=0x0c042d88u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042d8a;
P_0c042d8a: /* original 2127, guest PC 0x0c042d8a */
if(!s->budget--) { s->failed_pc=0x0c042d8au; return 0; }
r[17]=(r[17]&~0x301u)|((r[1]>>31)<<8)|((r[2]>>31)<<9)|(((r[1]^r[2])>>31)&1u);
goto P_0c042d8c;
P_0c042d8c: /* original 0429, guest PC 0x0c042d8c */
if(!s->budget--) { s->failed_pc=0x0c042d8cu; return 0; }
r[4]=r[17]&1u;
goto P_0c042d8e;
P_0c042d8e: /* original 333a, guest PC 0x0c042d8e */
if(!s->budget--) { s->failed_pc=0x0c042d8eu; return 0; }
wide=(uint64_t)r[3]-r[3]-(r[17]&1u); r[3]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042d90;
P_0c042d90: /* original 312a, guest PC 0x0c042d90 */
if(!s->budget--) { s->failed_pc=0x0c042d90u; return 0; }
wide=(uint64_t)r[1]-r[2]-(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042d92;
P_0c042d92: /* original 2307, guest PC 0x0c042d92 */
if(!s->budget--) { s->failed_pc=0x0c042d92u; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[0]>>31)<<9)|(((r[3]^r[0])>>31)&1u);
goto P_0c042d94;
P_0c042d94: /* original 4124, guest PC 0x0c042d94 */
if(!s->budget--) { s->failed_pc=0x0c042d94u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d96;
P_0c042d96: /* original 3304, guest PC 0x0c042d96 */
if(!s->budget--) { s->failed_pc=0x0c042d96u; return 0; }
divide_step(s,3,0);
goto P_0c042d98;
P_0c042d98: /* original 4124, guest PC 0x0c042d98 */
if(!s->budget--) { s->failed_pc=0x0c042d98u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d9a;
P_0c042d9a: /* original 3304, guest PC 0x0c042d9a */
if(!s->budget--) { s->failed_pc=0x0c042d9au; return 0; }
divide_step(s,3,0);
goto P_0c042d9c;
P_0c042d9c: /* original 4124, guest PC 0x0c042d9c */
if(!s->budget--) { s->failed_pc=0x0c042d9cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d9e;
P_0c042d9e: /* original 3304, guest PC 0x0c042d9e */
if(!s->budget--) { s->failed_pc=0x0c042d9eu; return 0; }
divide_step(s,3,0);
goto P_0c042da0;
P_0c042da0: /* original 4124, guest PC 0x0c042da0 */
if(!s->budget--) { s->failed_pc=0x0c042da0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042da2;
P_0c042da2: /* original 3304, guest PC 0x0c042da2 */
if(!s->budget--) { s->failed_pc=0x0c042da2u; return 0; }
divide_step(s,3,0);
goto P_0c042da4;
P_0c042da4: /* original 4124, guest PC 0x0c042da4 */
if(!s->budget--) { s->failed_pc=0x0c042da4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042da6;
P_0c042da6: /* original 3304, guest PC 0x0c042da6 */
if(!s->budget--) { s->failed_pc=0x0c042da6u; return 0; }
divide_step(s,3,0);
goto P_0c042da8;
P_0c042da8: /* original 4124, guest PC 0x0c042da8 */
if(!s->budget--) { s->failed_pc=0x0c042da8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042daa;
P_0c042daa: /* original 3304, guest PC 0x0c042daa */
if(!s->budget--) { s->failed_pc=0x0c042daau; return 0; }
divide_step(s,3,0);
goto P_0c042dac;
P_0c042dac: /* original 4124, guest PC 0x0c042dac */
if(!s->budget--) { s->failed_pc=0x0c042dacu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dae;
P_0c042dae: /* original 3304, guest PC 0x0c042dae */
if(!s->budget--) { s->failed_pc=0x0c042daeu; return 0; }
divide_step(s,3,0);
goto P_0c042db0;
P_0c042db0: /* original 4124, guest PC 0x0c042db0 */
if(!s->budget--) { s->failed_pc=0x0c042db0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042db2;
P_0c042db2: /* original 3304, guest PC 0x0c042db2 */
if(!s->budget--) { s->failed_pc=0x0c042db2u; return 0; }
divide_step(s,3,0);
goto P_0c042db4;
P_0c042db4: /* original 4124, guest PC 0x0c042db4 */
if(!s->budget--) { s->failed_pc=0x0c042db4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042db6;
P_0c042db6: /* original 3304, guest PC 0x0c042db6 */
if(!s->budget--) { s->failed_pc=0x0c042db6u; return 0; }
divide_step(s,3,0);
goto P_0c042db8;
P_0c042db8: /* original 4124, guest PC 0x0c042db8 */
if(!s->budget--) { s->failed_pc=0x0c042db8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dba;
P_0c042dba: /* original 3304, guest PC 0x0c042dba */
if(!s->budget--) { s->failed_pc=0x0c042dbau; return 0; }
divide_step(s,3,0);
goto P_0c042dbc;
P_0c042dbc: /* original 4124, guest PC 0x0c042dbc */
if(!s->budget--) { s->failed_pc=0x0c042dbcu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dbe;
P_0c042dbe: /* original 3304, guest PC 0x0c042dbe */
if(!s->budget--) { s->failed_pc=0x0c042dbeu; return 0; }
divide_step(s,3,0);
goto P_0c042dc0;
P_0c042dc0: /* original 4124, guest PC 0x0c042dc0 */
if(!s->budget--) { s->failed_pc=0x0c042dc0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dc2;
P_0c042dc2: /* original 3304, guest PC 0x0c042dc2 */
if(!s->budget--) { s->failed_pc=0x0c042dc2u; return 0; }
divide_step(s,3,0);
goto P_0c042dc4;
P_0c042dc4: /* original 4124, guest PC 0x0c042dc4 */
if(!s->budget--) { s->failed_pc=0x0c042dc4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dc6;
P_0c042dc6: /* original 3304, guest PC 0x0c042dc6 */
if(!s->budget--) { s->failed_pc=0x0c042dc6u; return 0; }
divide_step(s,3,0);
goto P_0c042dc8;
P_0c042dc8: /* original 4124, guest PC 0x0c042dc8 */
if(!s->budget--) { s->failed_pc=0x0c042dc8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dca;
P_0c042dca: /* original 3304, guest PC 0x0c042dca */
if(!s->budget--) { s->failed_pc=0x0c042dcau; return 0; }
divide_step(s,3,0);
goto P_0c042dcc;
P_0c042dcc: /* original 4124, guest PC 0x0c042dcc */
if(!s->budget--) { s->failed_pc=0x0c042dccu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dce;
P_0c042dce: /* original 3304, guest PC 0x0c042dce */
if(!s->budget--) { s->failed_pc=0x0c042dceu; return 0; }
divide_step(s,3,0);
goto P_0c042dd0;
P_0c042dd0: /* original 4124, guest PC 0x0c042dd0 */
if(!s->budget--) { s->failed_pc=0x0c042dd0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dd2;
P_0c042dd2: /* original 3304, guest PC 0x0c042dd2 */
if(!s->budget--) { s->failed_pc=0x0c042dd2u; return 0; }
divide_step(s,3,0);
goto P_0c042dd4;
P_0c042dd4: /* original 4124, guest PC 0x0c042dd4 */
if(!s->budget--) { s->failed_pc=0x0c042dd4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dd6;
P_0c042dd6: /* original 3304, guest PC 0x0c042dd6 */
if(!s->budget--) { s->failed_pc=0x0c042dd6u; return 0; }
divide_step(s,3,0);
goto P_0c042dd8;
P_0c042dd8: /* original 4124, guest PC 0x0c042dd8 */
if(!s->budget--) { s->failed_pc=0x0c042dd8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dda;
P_0c042dda: /* original 3304, guest PC 0x0c042dda */
if(!s->budget--) { s->failed_pc=0x0c042ddau; return 0; }
divide_step(s,3,0);
goto P_0c042ddc;
P_0c042ddc: /* original 4124, guest PC 0x0c042ddc */
if(!s->budget--) { s->failed_pc=0x0c042ddcu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dde;
P_0c042dde: /* original 3304, guest PC 0x0c042dde */
if(!s->budget--) { s->failed_pc=0x0c042ddeu; return 0; }
divide_step(s,3,0);
goto P_0c042de0;
P_0c042de0: /* original 4124, guest PC 0x0c042de0 */
if(!s->budget--) { s->failed_pc=0x0c042de0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042de2;
P_0c042de2: /* original 3304, guest PC 0x0c042de2 */
if(!s->budget--) { s->failed_pc=0x0c042de2u; return 0; }
divide_step(s,3,0);
goto P_0c042de4;
P_0c042de4: /* original 4124, guest PC 0x0c042de4 */
if(!s->budget--) { s->failed_pc=0x0c042de4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042de6;
P_0c042de6: /* original 3304, guest PC 0x0c042de6 */
if(!s->budget--) { s->failed_pc=0x0c042de6u; return 0; }
divide_step(s,3,0);
goto P_0c042de8;
P_0c042de8: /* original 4124, guest PC 0x0c042de8 */
if(!s->budget--) { s->failed_pc=0x0c042de8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dea;
P_0c042dea: /* original 3304, guest PC 0x0c042dea */
if(!s->budget--) { s->failed_pc=0x0c042deau; return 0; }
divide_step(s,3,0);
goto P_0c042dec;
P_0c042dec: /* original 4124, guest PC 0x0c042dec */
if(!s->budget--) { s->failed_pc=0x0c042decu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dee;
P_0c042dee: /* original 3304, guest PC 0x0c042dee */
if(!s->budget--) { s->failed_pc=0x0c042deeu; return 0; }
divide_step(s,3,0);
goto P_0c042df0;
P_0c042df0: /* original 4124, guest PC 0x0c042df0 */
if(!s->budget--) { s->failed_pc=0x0c042df0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042df2;
P_0c042df2: /* original 3304, guest PC 0x0c042df2 */
if(!s->budget--) { s->failed_pc=0x0c042df2u; return 0; }
divide_step(s,3,0);
goto P_0c042df4;
P_0c042df4: /* original 4124, guest PC 0x0c042df4 */
if(!s->budget--) { s->failed_pc=0x0c042df4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042df6;
P_0c042df6: /* original 3304, guest PC 0x0c042df6 */
if(!s->budget--) { s->failed_pc=0x0c042df6u; return 0; }
divide_step(s,3,0);
goto P_0c042df8;
P_0c042df8: /* original 4124, guest PC 0x0c042df8 */
if(!s->budget--) { s->failed_pc=0x0c042df8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dfa;
P_0c042dfa: /* original 3304, guest PC 0x0c042dfa */
if(!s->budget--) { s->failed_pc=0x0c042dfau; return 0; }
divide_step(s,3,0);
goto P_0c042dfc;
P_0c042dfc: /* original 4124, guest PC 0x0c042dfc */
if(!s->budget--) { s->failed_pc=0x0c042dfcu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dfe;
P_0c042dfe: /* original 3304, guest PC 0x0c042dfe */
if(!s->budget--) { s->failed_pc=0x0c042dfeu; return 0; }
divide_step(s,3,0);
goto P_0c042e00;
P_0c042e00: /* original 4124, guest PC 0x0c042e00 */
if(!s->budget--) { s->failed_pc=0x0c042e00u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e02;
P_0c042e02: /* original 3304, guest PC 0x0c042e02 */
if(!s->budget--) { s->failed_pc=0x0c042e02u; return 0; }
divide_step(s,3,0);
goto P_0c042e04;
P_0c042e04: /* original 4124, guest PC 0x0c042e04 */
if(!s->budget--) { s->failed_pc=0x0c042e04u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e06;
P_0c042e06: /* original 3304, guest PC 0x0c042e06 */
if(!s->budget--) { s->failed_pc=0x0c042e06u; return 0; }
divide_step(s,3,0);
goto P_0c042e08;
P_0c042e08: /* original 4124, guest PC 0x0c042e08 */
if(!s->budget--) { s->failed_pc=0x0c042e08u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e0a;
P_0c042e0a: /* original 3304, guest PC 0x0c042e0a */
if(!s->budget--) { s->failed_pc=0x0c042e0au; return 0; }
divide_step(s,3,0);
goto P_0c042e0c;
P_0c042e0c: /* original 4124, guest PC 0x0c042e0c */
if(!s->budget--) { s->failed_pc=0x0c042e0cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e0e;
P_0c042e0e: /* original 3304, guest PC 0x0c042e0e */
if(!s->budget--) { s->failed_pc=0x0c042e0eu; return 0; }
divide_step(s,3,0);
goto P_0c042e10;
P_0c042e10: /* original 4124, guest PC 0x0c042e10 */
if(!s->budget--) { s->failed_pc=0x0c042e10u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e12;
P_0c042e12: /* original 3304, guest PC 0x0c042e12 */
if(!s->budget--) { s->failed_pc=0x0c042e12u; return 0; }
divide_step(s,3,0);
goto P_0c042e14;
P_0c042e14: /* original 2327, guest PC 0x0c042e14 */
if(!s->budget--) { s->failed_pc=0x0c042e14u; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[2]>>31)<<9)|(((r[3]^r[2])>>31)&1u);
goto P_0c042e16;
P_0c042e16: /* original 0229, guest PC 0x0c042e16 */
if(!s->budget--) { s->failed_pc=0x0c042e16u; return 0; }
r[2]=r[17]&1u;
goto P_0c042e18;
P_0c042e18: /* original 224a, guest PC 0x0c042e18 */
if(!s->budget--) { s->failed_pc=0x0c042e18u; return 0; }
r[2]^=r[4];
goto P_0c042e1a;
P_0c042e1a: /* original 4225, guest PC 0x0c042e1a */
if(!s->budget--) { s->failed_pc=0x0c042e1au; return 0; }
tmp=r[2]&1u; r[2]=(r[2]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e1c;
P_0c042e1c: /* original 8b02, guest PC 0x0c042e1c */
if(!s->budget--) { s->failed_pc=0x0c042e1cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042e24; }
goto P_0c042e1e;
P_0c042e1e: /* original 2307, guest PC 0x0c042e1e */
if(!s->budget--) { s->failed_pc=0x0c042e1eu; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[0]>>31)<<9)|(((r[3]^r[0])>>31)&1u);
goto P_0c042e20;
P_0c042e20: /* original 4321, guest PC 0x0c042e20 */
if(!s->budget--) { s->failed_pc=0x0c042e20u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c042e22;
P_0c042e22: /* original 3304, guest PC 0x0c042e22 */
if(!s->budget--) { s->failed_pc=0x0c042e22u; return 0; }
divide_step(s,3,0);
goto P_0c042e24;
P_0c042e24: /* original 334c, guest PC 0x0c042e24 */
if(!s->budget--) { s->failed_pc=0x0c042e24u; return 0; }
r[3]+=r[4];
goto P_0c042e26;
P_0c042e26: /* original 6033, guest PC 0x0c042e26 */
if(!s->budget--) { s->failed_pc=0x0c042e26u; return 0; }
r[0]=r[3];
goto P_0c042e28;
P_0c042e28: /* original 64f6, guest PC 0x0c042e28 */
if(!s->budget--) { s->failed_pc=0x0c042e28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c042e2a;
P_0c042e2a: /* original 63f6, guest PC 0x0c042e2a */
if(!s->budget--) { s->failed_pc=0x0c042e2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042e2c;
P_0c042e2c: /* original 000b, guest PC 0x0c042e2c */
if(!s->budget--) { s->failed_pc=0x0c042e2cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042e2e: /* original 62f6, guest PC 0x0c042e2e */
if(!s->budget--) { s->failed_pc=0x0c042e2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c042e30;
P_0c042e30: /* original d102, guest PC 0x0c042e30 */
if(!s->budget--) { s->failed_pc=0x0c042e30u; return 0; }
r[1]=read(ram,0x0c042e3cu,4);
goto P_0c042e32;
P_0c042e32: /* original d203, guest PC 0x0c042e32 */
if(!s->budget--) { s->failed_pc=0x0c042e32u; return 0; }
r[2]=read(ram,0x0c042e40u,4);
goto P_0c042e34;
P_0c042e34: /* original e000, guest PC 0x0c042e34 */
if(!s->budget--) { s->failed_pc=0x0c042e34u; return 0; }
r[0]=0x00000000u;
goto P_0c042e36;
P_0c042e36: /* original 2122, guest PC 0x0c042e36 */
if(!s->budget--) { s->failed_pc=0x0c042e36u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c042e38;
P_0c042e38: /* original 000b, guest PC 0x0c042e38 */
if(!s->budget--) { s->failed_pc=0x0c042e38u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042e3a: /* original 62f6, guest PC 0x0c042e3a */
if(!s->budget--) { s->failed_pc=0x0c042e3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042e3cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042e3cu; return 0; } return 1;
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
P_0c08d0ee: /* original 2fe6, guest PC 0x0c08d0ee */
if(!s->budget--) { s->failed_pc=0x0c08d0eeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d0f0;
P_0c08d0f0: /* original e02c, guest PC 0x0c08d0f0 */
if(!s->budget--) { s->failed_pc=0x0c08d0f0u; return 0; }
r[0]=0x0000002cu;
goto P_0c08d0f2;
P_0c08d0f2: /* original 2fd6, guest PC 0x0c08d0f2 */
if(!s->budget--) { s->failed_pc=0x0c08d0f2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d0f4;
P_0c08d0f4: /* original 6d43, guest PC 0x0c08d0f4 */
if(!s->budget--) { s->failed_pc=0x0c08d0f4u; return 0; }
r[13]=r[4];
goto P_0c08d0f6;
P_0c08d0f6: /* original 04dc, guest PC 0x0c08d0f6 */
if(!s->budget--) { s->failed_pc=0x0c08d0f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08d0f8;
P_0c08d0f8: /* original e310, guest PC 0x0c08d0f8 */
if(!s->budget--) { s->failed_pc=0x0c08d0f8u; return 0; }
r[3]=0x00000010u;
goto P_0c08d0fa;
P_0c08d0fa: /* original 4f22, guest PC 0x0c08d0fa */
if(!s->budget--) { s->failed_pc=0x0c08d0fau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08d0fc;
P_0c08d0fc: /* original 7401, guest PC 0x0c08d0fc */
if(!s->budget--) { s->failed_pc=0x0c08d0fcu; return 0; }
r[4]+=0x00000001u;
goto P_0c08d0fe;
P_0c08d0fe: /* original 3432, guest PC 0x0c08d0fe */
if(!s->budget--) { s->failed_pc=0x0c08d0feu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[3])!=0);
goto P_0c08d100;
P_0c08d100: /* original 8d22, guest PC 0x0c08d100 */
if(!s->budget--) { s->failed_pc=0x0c08d100u; return 0; }
cond=r[17]&1u;
r[14]=r[5];
if(cond) { goto P_0c08d148; }
goto P_0c08d104;
P_0c08d102: /* original 6e53, guest PC 0x0c08d102 */
if(!s->budget--) { s->failed_pc=0x0c08d102u; return 0; }
r[14]=r[5];
goto P_0c08d104;
P_0c08d104: /* original 0d44, guest PC 0x0c08d104 */
if(!s->budget--) { s->failed_pc=0x0c08d104u; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c08d106;
P_0c08d106: /* original e028, guest PC 0x0c08d106 */
if(!s->budget--) { s->failed_pc=0x0c08d106u; return 0; }
r[0]=0x00000028u;
goto P_0c08d108;
P_0c08d108: /* original 05dd, guest PC 0x0c08d108 */
if(!s->budget--) { s->failed_pc=0x0c08d108u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c08d10a;
P_0c08d10a: /* original e040, guest PC 0x0c08d10a */
if(!s->budget--) { s->failed_pc=0x0c08d10au; return 0; }
r[0]=0x00000040u;
goto P_0c08d10c;
P_0c08d10c: /* original 655d, guest PC 0x0c08d10c */
if(!s->budget--) { s->failed_pc=0x0c08d10cu; return 0; }
r[5]=r[5]&65535u;
goto P_0c08d10e;
P_0c08d10e: /* original 1e5d, guest PC 0x0c08d10e */
if(!s->budget--) { s->failed_pc=0x0c08d10eu; return 0; }
write(ram,r[14]+52,r[5],4);
goto P_0c08d110;
P_0c08d110: /* original 0e46, guest PC 0x0c08d110 */
if(!s->budget--) { s->failed_pc=0x0c08d110u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c08d112;
P_0c08d112: /* original b021, guest PC 0x0c08d112 */
if(!s->budget--) { s->failed_pc=0x0c08d112u; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08d116u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d116u) { target=s->pc; goto dispatch; }
goto P_0c08d116;
P_0c08d114: /* original 64e3, guest PC 0x0c08d114 */
if(!s->budget--) { s->failed_pc=0x0c08d114u; return 0; }
r[4]=r[14];
goto P_0c08d116;
P_0c08d116: /* original 920d, guest PC 0x0c08d116 */
if(!s->budget--) { s->failed_pc=0x0c08d116u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08d134u,2);
goto P_0c08d118;
P_0c08d118: /* original 55ee, guest PC 0x0c08d118 */
if(!s->budget--) { s->failed_pc=0x0c08d118u; return 0; }
r[5]=read(ram,r[14]+56,4);
goto P_0c08d11a;
P_0c08d11a: /* original 3520, guest PC 0x0c08d11a */
if(!s->budget--) { s->failed_pc=0x0c08d11au; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[2])!=0);
goto P_0c08d11c;
P_0c08d11c: /* original 8d14, guest PC 0x0c08d11c */
if(!s->budget--) { s->failed_pc=0x0c08d11cu; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[14]+60,4);
if(cond) { goto P_0c08d148; }
goto P_0c08d120;
P_0c08d11e: /* original 54ef, guest PC 0x0c08d11e */
if(!s->budget--) { s->failed_pc=0x0c08d11eu; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c08d120;
P_0c08d120: /* original 2448, guest PC 0x0c08d120 */
if(!s->budget--) { s->failed_pc=0x0c08d120u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c08d122;
P_0c08d122: /* original 8911, guest PC 0x0c08d122 */
if(!s->budget--) { s->failed_pc=0x0c08d122u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08d148; }
goto P_0c08d124;
P_0c08d124: /* original e02d, guest PC 0x0c08d124 */
if(!s->budget--) { s->failed_pc=0x0c08d124u; return 0; }
r[0]=0x0000002du;
goto P_0c08d126;
P_0c08d126: /* original 0d54, guest PC 0x0c08d126 */
if(!s->budget--) { s->failed_pc=0x0c08d126u; return 0; }
write(ram,r[13]+r[0],r[5],1);
goto P_0c08d128;
P_0c08d128: /* original 6043, guest PC 0x0c08d128 */
if(!s->budget--) { s->failed_pc=0x0c08d128u; return 0; }
r[0]=r[4];
goto P_0c08d12a;
P_0c08d12a: /* original a011, guest PC 0x0c08d12a */
if(!s->budget--) { s->failed_pc=0x0c08d12au; return 0; }
write(ram,r[13]+20,r[0],2);
goto P_0c08d150;
P_0c08d12c: /* original 81da, guest PC 0x0c08d12c */
if(!s->budget--) { s->failed_pc=0x0c08d12cu; return 0; }
write(ram,r[13]+20,r[0],2);
if(!vf3_matrix_family(0x0c08d12eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08d12eu; return 0; } return 1;
P_0c08d148: /* original 62e2, guest PC 0x0c08d148 */
if(!s->budget--) { s->failed_pc=0x0c08d148u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c08d14a;
P_0c08d14a: /* original e3fe, guest PC 0x0c08d14a */
if(!s->budget--) { s->failed_pc=0x0c08d14au; return 0; }
r[3]=0xfffffffeu;
goto P_0c08d14c;
P_0c08d14c: /* original 2239, guest PC 0x0c08d14c */
if(!s->budget--) { s->failed_pc=0x0c08d14cu; return 0; }
r[2]&=r[3];
goto P_0c08d14e;
P_0c08d14e: /* original 2e22, guest PC 0x0c08d14e */
if(!s->budget--) { s->failed_pc=0x0c08d14eu; return 0; }
write(ram,r[14],r[2],4);
goto P_0c08d150;
P_0c08d150: /* original 4f26, guest PC 0x0c08d150 */
if(!s->budget--) { s->failed_pc=0x0c08d150u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08d152;
P_0c08d152: /* original 6df6, guest PC 0x0c08d152 */
if(!s->budget--) { s->failed_pc=0x0c08d152u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08d154;
P_0c08d154: /* original 000b, guest PC 0x0c08d154 */
if(!s->budget--) { s->failed_pc=0x0c08d154u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08d156: /* original 6ef6, guest PC 0x0c08d156 */
if(!s->budget--) { s->failed_pc=0x0c08d156u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08d158u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
