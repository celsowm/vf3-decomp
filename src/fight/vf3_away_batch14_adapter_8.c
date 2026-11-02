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
int vf3_away_batch14_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c086cfcu: goto P_0c086cfc;
case 0x0c086cfeu: goto P_0c086cfe;
case 0x0c086d00u: goto P_0c086d00;
case 0x0c086d02u: goto P_0c086d02;
case 0x0c086d04u: goto P_0c086d04;
case 0x0c086d06u: goto P_0c086d06;
case 0x0c086d08u: goto P_0c086d08;
case 0x0c086d0au: goto P_0c086d0a;
case 0x0c086d0cu: goto P_0c086d0c;
case 0x0c086d0eu: goto P_0c086d0e;
case 0x0c086d10u: goto P_0c086d10;
case 0x0c086d12u: goto P_0c086d12;
case 0x0c086d14u: goto P_0c086d14;
case 0x0c086d16u: goto P_0c086d16;
case 0x0c086d18u: goto P_0c086d18;
case 0x0c086d1au: goto P_0c086d1a;
case 0x0c086d1cu: goto P_0c086d1c;
case 0x0c086d1eu: goto P_0c086d1e;
case 0x0c086d20u: goto P_0c086d20;
case 0x0c086d22u: goto P_0c086d22;
case 0x0c086d24u: goto P_0c086d24;
case 0x0c086d26u: goto P_0c086d26;
case 0x0c086d28u: goto P_0c086d28;
case 0x0c086d2au: goto P_0c086d2a;
case 0x0c086d2cu: goto P_0c086d2c;
case 0x0c086d2eu: goto P_0c086d2e;
case 0x0c086d30u: goto P_0c086d30;
case 0x0c086d32u: goto P_0c086d32;
case 0x0c086d34u: goto P_0c086d34;
case 0x0c086d36u: goto P_0c086d36;
case 0x0c086d38u: goto P_0c086d38;
case 0x0c086d3au: goto P_0c086d3a;
case 0x0c086d3cu: goto P_0c086d3c;
case 0x0c086d3eu: goto P_0c086d3e;
case 0x0c086d40u: goto P_0c086d40;
case 0x0c086d42u: goto P_0c086d42;
case 0x0c086d44u: goto P_0c086d44;
case 0x0c086d46u: goto P_0c086d46;
case 0x0c086d48u: goto P_0c086d48;
case 0x0c086d4au: goto P_0c086d4a;
case 0x0c086d4cu: goto P_0c086d4c;
case 0x0c086d4eu: goto P_0c086d4e;
case 0x0c086d50u: goto P_0c086d50;
case 0x0c086d52u: goto P_0c086d52;
case 0x0c086d54u: goto P_0c086d54;
case 0x0c086d56u: goto P_0c086d56;
case 0x0c086d58u: goto P_0c086d58;
case 0x0c086d5au: goto P_0c086d5a;
case 0x0c086d5cu: goto P_0c086d5c;
case 0x0c086d5eu: goto P_0c086d5e;
case 0x0c086d60u: goto P_0c086d60;
case 0x0c086d62u: goto P_0c086d62;
case 0x0c086d64u: goto P_0c086d64;
case 0x0c086d66u: goto P_0c086d66;
case 0x0c086d68u: goto P_0c086d68;
case 0x0c086d6au: goto P_0c086d6a;
case 0x0c086d6cu: goto P_0c086d6c;
case 0x0c086d6eu: goto P_0c086d6e;
case 0x0c086d70u: goto P_0c086d70;
case 0x0c086d72u: goto P_0c086d72;
case 0x0c086d74u: goto P_0c086d74;
case 0x0c086d76u: goto P_0c086d76;
case 0x0c086d78u: goto P_0c086d78;
case 0x0c086d7au: goto P_0c086d7a;
case 0x0c086d7cu: goto P_0c086d7c;
case 0x0c086d7eu: goto P_0c086d7e;
case 0x0c086d80u: goto P_0c086d80;
case 0x0c086d82u: goto P_0c086d82;
case 0x0c086d84u: goto P_0c086d84;
case 0x0c086d86u: goto P_0c086d86;
case 0x0c086d88u: goto P_0c086d88;
case 0x0c086d8au: goto P_0c086d8a;
case 0x0c086d8cu: goto P_0c086d8c;
case 0x0c086d8eu: goto P_0c086d8e;
case 0x0c086d90u: goto P_0c086d90;
case 0x0c086d92u: goto P_0c086d92;
case 0x0c086d94u: goto P_0c086d94;
case 0x0c086d96u: goto P_0c086d96;
case 0x0c086d98u: goto P_0c086d98;
case 0x0c086d9au: goto P_0c086d9a;
case 0x0c086d9cu: goto P_0c086d9c;
case 0x0c086d9eu: goto P_0c086d9e;
case 0x0c086da0u: goto P_0c086da0;
case 0x0c086da2u: goto P_0c086da2;
case 0x0c086da4u: goto P_0c086da4;
case 0x0c086da6u: goto P_0c086da6;
case 0x0c086da8u: goto P_0c086da8;
case 0x0c086daau: goto P_0c086daa;
case 0x0c086dacu: goto P_0c086dac;
case 0x0c086daeu: goto P_0c086dae;
case 0x0c086db0u: goto P_0c086db0;
case 0x0c086db2u: goto P_0c086db2;
case 0x0c086db4u: goto P_0c086db4;
case 0x0c086db6u: goto P_0c086db6;
case 0x0c086db8u: goto P_0c086db8;
case 0x0c086dbau: goto P_0c086dba;
case 0x0c086dbcu: goto P_0c086dbc;
case 0x0c086dbeu: goto P_0c086dbe;
case 0x0c086dc0u: goto P_0c086dc0;
case 0x0c086dc2u: goto P_0c086dc2;
case 0x0c086dc4u: goto P_0c086dc4;
case 0x0c086dc6u: goto P_0c086dc6;
case 0x0c086dc8u: goto P_0c086dc8;
case 0x0c086dcau: goto P_0c086dca;
case 0x0c086dccu: goto P_0c086dcc;
case 0x0c086dceu: goto P_0c086dce;
case 0x0c086dd0u: goto P_0c086dd0;
case 0x0c086dd2u: goto P_0c086dd2;
case 0x0c086dd4u: goto P_0c086dd4;
case 0x0c086dd6u: goto P_0c086dd6;
case 0x0c086dd8u: goto P_0c086dd8;
case 0x0c086ddau: goto P_0c086dda;
case 0x0c086ddcu: goto P_0c086ddc;
case 0x0c086ddeu: goto P_0c086dde;
case 0x0c086de0u: goto P_0c086de0;
case 0x0c086de2u: goto P_0c086de2;
case 0x0c086de4u: goto P_0c086de4;
case 0x0c086de6u: goto P_0c086de6;
case 0x0c086de8u: goto P_0c086de8;
case 0x0c086deau: goto P_0c086dea;
case 0x0c086decu: goto P_0c086dec;
case 0x0c086deeu: goto P_0c086dee;
case 0x0c086df0u: goto P_0c086df0;
case 0x0c086df2u: goto P_0c086df2;
case 0x0c086df4u: goto P_0c086df4;
case 0x0c086df6u: goto P_0c086df6;
case 0x0c086df8u: goto P_0c086df8;
case 0x0c086dfau: goto P_0c086dfa;
case 0x0c086dfcu: goto P_0c086dfc;
case 0x0c086dfeu: goto P_0c086dfe;
case 0x0c086e00u: goto P_0c086e00;
case 0x0c086e02u: goto P_0c086e02;
case 0x0c086e04u: goto P_0c086e04;
case 0x0c086e06u: goto P_0c086e06;
case 0x0c086e08u: goto P_0c086e08;
case 0x0c086e0au: goto P_0c086e0a;
case 0x0c086e0cu: goto P_0c086e0c;
case 0x0c086e0eu: goto P_0c086e0e;
case 0x0c086e10u: goto P_0c086e10;
case 0x0c086e12u: goto P_0c086e12;
case 0x0c086e14u: goto P_0c086e14;
case 0x0c086e16u: goto P_0c086e16;
case 0x0c086e18u: goto P_0c086e18;
case 0x0c086e1au: goto P_0c086e1a;
case 0x0c086e1cu: goto P_0c086e1c;
case 0x0c086e1eu: goto P_0c086e1e;
case 0x0c086e20u: goto P_0c086e20;
case 0x0c086e22u: goto P_0c086e22;
case 0x0c086e24u: goto P_0c086e24;
case 0x0c086e4cu: goto P_0c086e4c;
case 0x0c086e4eu: goto P_0c086e4e;
case 0x0c086e50u: goto P_0c086e50;
case 0x0c086e52u: goto P_0c086e52;
case 0x0c086e54u: goto P_0c086e54;
case 0x0c086e56u: goto P_0c086e56;
case 0x0c086e58u: goto P_0c086e58;
case 0x0c086e5au: goto P_0c086e5a;
case 0x0c086e5cu: goto P_0c086e5c;
case 0x0c086e5eu: goto P_0c086e5e;
case 0x0c086e60u: goto P_0c086e60;
case 0x0c086e62u: goto P_0c086e62;
case 0x0c086e64u: goto P_0c086e64;
case 0x0c086e66u: goto P_0c086e66;
case 0x0c086e68u: goto P_0c086e68;
case 0x0c086e6au: goto P_0c086e6a;
case 0x0c086e6cu: goto P_0c086e6c;
case 0x0c086e6eu: goto P_0c086e6e;
case 0x0c086e70u: goto P_0c086e70;
case 0x0c086e72u: goto P_0c086e72;
case 0x0c086e74u: goto P_0c086e74;
case 0x0c086e76u: goto P_0c086e76;
case 0x0c086e78u: goto P_0c086e78;
case 0x0c086e7au: goto P_0c086e7a;
case 0x0c086e7cu: goto P_0c086e7c;
case 0x0c086e7eu: goto P_0c086e7e;
case 0x0c086e80u: goto P_0c086e80;
case 0x0c086e82u: goto P_0c086e82;
case 0x0c086e84u: goto P_0c086e84;
case 0x0c086e86u: goto P_0c086e86;
case 0x0c086e88u: goto P_0c086e88;
case 0x0c086e8au: goto P_0c086e8a;
case 0x0c086e8cu: goto P_0c086e8c;
case 0x0c086e8eu: goto P_0c086e8e;
case 0x0c086e90u: goto P_0c086e90;
case 0x0c086e92u: goto P_0c086e92;
case 0x0c086e94u: goto P_0c086e94;
case 0x0c086e96u: goto P_0c086e96;
case 0x0c086e98u: goto P_0c086e98;
case 0x0c086e9au: goto P_0c086e9a;
case 0x0c086e9cu: goto P_0c086e9c;
case 0x0c086e9eu: goto P_0c086e9e;
case 0x0c086ea0u: goto P_0c086ea0;
case 0x0c086ea2u: goto P_0c086ea2;
case 0x0c086ea4u: goto P_0c086ea4;
case 0x0c086ea6u: goto P_0c086ea6;
case 0x0c086ea8u: goto P_0c086ea8;
case 0x0c086eaau: goto P_0c086eaa;
case 0x0c086eacu: goto P_0c086eac;
case 0x0c086eaeu: goto P_0c086eae;
case 0x0c086eb0u: goto P_0c086eb0;
case 0x0c086eb2u: goto P_0c086eb2;
case 0x0c086eb4u: goto P_0c086eb4;
case 0x0c086eb6u: goto P_0c086eb6;
case 0x0c086eb8u: goto P_0c086eb8;
case 0x0c086ebau: goto P_0c086eba;
case 0x0c086ebcu: goto P_0c086ebc;
case 0x0c086ebeu: goto P_0c086ebe;
case 0x0c086ec0u: goto P_0c086ec0;
case 0x0c086ec2u: goto P_0c086ec2;
case 0x0c086ec4u: goto P_0c086ec4;
case 0x0c086ec6u: goto P_0c086ec6;
case 0x0c086ec8u: goto P_0c086ec8;
case 0x0c086ecau: goto P_0c086eca;
case 0x0c086eccu: goto P_0c086ecc;
case 0x0c086eceu: goto P_0c086ece;
case 0x0c086ed0u: goto P_0c086ed0;
case 0x0c086ed2u: goto P_0c086ed2;
case 0x0c086ed4u: goto P_0c086ed4;
case 0x0c086ed6u: goto P_0c086ed6;
case 0x0c086ed8u: goto P_0c086ed8;
case 0x0c086edau: goto P_0c086eda;
case 0x0c086edcu: goto P_0c086edc;
case 0x0c086edeu: goto P_0c086ede;
case 0x0c086ee0u: goto P_0c086ee0;
case 0x0c086ee2u: goto P_0c086ee2;
case 0x0c086ee4u: goto P_0c086ee4;
case 0x0c086ee6u: goto P_0c086ee6;
case 0x0c086ee8u: goto P_0c086ee8;
case 0x0c086eeau: goto P_0c086eea;
case 0x0c086eecu: goto P_0c086eec;
case 0x0c086eeeu: goto P_0c086eee;
case 0x0c086ef0u: goto P_0c086ef0;
case 0x0c086ef2u: goto P_0c086ef2;
case 0x0c086ef4u: goto P_0c086ef4;
case 0x0c086ef6u: goto P_0c086ef6;
case 0x0c086ef8u: goto P_0c086ef8;
case 0x0c086efau: goto P_0c086efa;
case 0x0c086efcu: goto P_0c086efc;
case 0x0c086efeu: goto P_0c086efe;
case 0x0c086f00u: goto P_0c086f00;
case 0x0c086f02u: goto P_0c086f02;
case 0x0c086f04u: goto P_0c086f04;
case 0x0c086f06u: goto P_0c086f06;
case 0x0c086f08u: goto P_0c086f08;
case 0x0c086f0au: goto P_0c086f0a;
case 0x0c086f0cu: goto P_0c086f0c;
case 0x0c086f0eu: goto P_0c086f0e;
case 0x0c086f10u: goto P_0c086f10;
case 0x0c086f12u: goto P_0c086f12;
case 0x0c086f14u: goto P_0c086f14;
case 0x0c086f16u: goto P_0c086f16;
case 0x0c086f18u: goto P_0c086f18;
case 0x0c086f1au: goto P_0c086f1a;
case 0x0c086f1cu: goto P_0c086f1c;
case 0x0c086f1eu: goto P_0c086f1e;
case 0x0c086f20u: goto P_0c086f20;
case 0x0c086f22u: goto P_0c086f22;
case 0x0c086f24u: goto P_0c086f24;
case 0x0c086f26u: goto P_0c086f26;
case 0x0c086f28u: goto P_0c086f28;
case 0x0c086f2au: goto P_0c086f2a;
case 0x0c086f2cu: goto P_0c086f2c;
case 0x0c086f2eu: goto P_0c086f2e;
case 0x0c086f30u: goto P_0c086f30;
case 0x0c086f32u: goto P_0c086f32;
case 0x0c086f34u: goto P_0c086f34;
case 0x0c086f36u: goto P_0c086f36;
case 0x0c086f38u: goto P_0c086f38;
case 0x0c086f3au: goto P_0c086f3a;
case 0x0c086f3cu: goto P_0c086f3c;
case 0x0c086f3eu: goto P_0c086f3e;
case 0x0c086f40u: goto P_0c086f40;
case 0x0c086f42u: goto P_0c086f42;
case 0x0c086f44u: goto P_0c086f44;
case 0x0c086f46u: goto P_0c086f46;
case 0x0c086f48u: goto P_0c086f48;
case 0x0c086f4au: goto P_0c086f4a;
case 0x0c086f4cu: goto P_0c086f4c;
case 0x0c086f4eu: goto P_0c086f4e;
case 0x0c086f50u: goto P_0c086f50;
case 0x0c086f52u: goto P_0c086f52;
case 0x0c086f54u: goto P_0c086f54;
case 0x0c086f56u: goto P_0c086f56;
case 0x0c086f58u: goto P_0c086f58;
case 0x0c086f5au: goto P_0c086f5a;
case 0x0c086f5cu: goto P_0c086f5c;
case 0x0c086f5eu: goto P_0c086f5e;
case 0x0c086f60u: goto P_0c086f60;
case 0x0c086f62u: goto P_0c086f62;
case 0x0c086f64u: goto P_0c086f64;
case 0x0c086f66u: goto P_0c086f66;
case 0x0c086f68u: goto P_0c086f68;
case 0x0c086f6au: goto P_0c086f6a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c086cfc: /* original c74d, guest PC 0x0c086cfc */
if(!s->budget--) { s->failed_pc=0x0c086cfcu; return 0; }
r[0]=code_base|0x00086e34u;
goto P_0c086cfe;
P_0c086cfe: /* original 2fd6, guest PC 0x0c086cfe */
if(!s->budget--) { s->failed_pc=0x0c086cfeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086d00;
P_0c086d00: /* original 2fc6, guest PC 0x0c086d00 */
if(!s->budget--) { s->failed_pc=0x0c086d00u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086d02;
P_0c086d02: /* original ec00, guest PC 0x0c086d02 */
if(!s->budget--) { s->failed_pc=0x0c086d02u; return 0; }
r[12]=0x00000000u;
goto P_0c086d04;
P_0c086d04: /* original 2fa6, guest PC 0x0c086d04 */
if(!s->budget--) { s->failed_pc=0x0c086d04u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086d06;
P_0c086d06: /* original fa08, guest PC 0x0c086d06 */
if(!s->budget--) { s->failed_pc=0x0c086d06u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c086d08;
P_0c086d08: /* original c74b, guest PC 0x0c086d08 */
if(!s->budget--) { s->failed_pc=0x0c086d08u; return 0; }
r[0]=code_base|0x00086e38u;
goto P_0c086d0a;
P_0c086d0a: /* original da4c, guest PC 0x0c086d0a */
if(!s->budget--) { s->failed_pc=0x0c086d0au; return 0; }
r[10]=read(ram,0x0c086e3cu,4);
goto P_0c086d0c;
P_0c086d0c: /* original fb08, guest PC 0x0c086d0c */
if(!s->budget--) { s->failed_pc=0x0c086d0cu; return 0; }
vf3_matrix_load(s,ram,11,r[0]);
goto P_0c086d0e;
P_0c086d0e: /* original 60c3, guest PC 0x0c086d0e */
if(!s->budget--) { s->failed_pc=0x0c086d0eu; return 0; }
r[0]=r[12];
goto P_0c086d10;
P_0c086d10: /* original 4000, guest PC 0x0c086d10 */
if(!s->budget--) { s->failed_pc=0x0c086d10u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c086d12;
P_0c086d12: /* original 0dad, guest PC 0x0c086d12 */
if(!s->budget--) { s->failed_pc=0x0c086d12u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c086d14;
P_0c086d14: /* original d64a, guest PC 0x0c086d14 */
if(!s->budget--) { s->failed_pc=0x0c086d14u; return 0; }
r[6]=read(ram,0x0c086e40u,4);
goto P_0c086d16;
P_0c086d16: /* original 6ddd, guest PC 0x0c086d16 */
if(!s->budget--) { s->failed_pc=0x0c086d16u; return 0; }
r[13]=r[13]&65535u;
goto P_0c086d18;
P_0c086d18: /* original 3d60, guest PC 0x0c086d18 */
if(!s->budget--) { s->failed_pc=0x0c086d18u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[6])!=0);
goto P_0c086d1a;
P_0c086d1a: /* original 8946, guest PC 0x0c086d1a */
if(!s->budget--) { s->failed_pc=0x0c086d1au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086daa; }
goto P_0c086d1c;
P_0c086d1c: /* original 66d3, guest PC 0x0c086d1c */
if(!s->budget--) { s->failed_pc=0x0c086d1cu; return 0; }
r[6]=r[13];
goto P_0c086d1e;
P_0c086d1e: /* original 4600, guest PC 0x0c086d1e */
if(!s->budget--) { s->failed_pc=0x0c086d1eu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c086d20;
P_0c086d20: /* original 63d3, guest PC 0x0c086d20 */
if(!s->budget--) { s->failed_pc=0x0c086d20u; return 0; }
r[3]=r[13];
goto P_0c086d22;
P_0c086d22: /* original 9780, guest PC 0x0c086d22 */
if(!s->budget--) { s->failed_pc=0x0c086d22u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086e26u,2);
goto P_0c086d24;
P_0c086d24: /* original 363c, guest PC 0x0c086d24 */
if(!s->budget--) { s->failed_pc=0x0c086d24u; return 0; }
r[6]+=r[3];
goto P_0c086d26;
P_0c086d26: /* original f28d, guest PC 0x0c086d26 */
if(!s->budget--) { s->failed_pc=0x0c086d26u; return 0; }
fr[2]=0;
goto P_0c086d28;
P_0c086d28: /* original 6063, guest PC 0x0c086d28 */
if(!s->budget--) { s->failed_pc=0x0c086d28u; return 0; }
r[0]=r[6];
goto P_0c086d2a;
P_0c086d2a: /* original 4008, guest PC 0x0c086d2a */
if(!s->budget--) { s->failed_pc=0x0c086d2au; return 0; }
r[0]<<=2;
goto P_0c086d2c;
P_0c086d2c: /* original 375c, guest PC 0x0c086d2c */
if(!s->budget--) { s->failed_pc=0x0c086d2cu; return 0; }
r[7]+=r[5];
goto P_0c086d2e;
P_0c086d2e: /* original f976, guest PC 0x0c086d2e */
if(!s->budget--) { s->failed_pc=0x0c086d2eu; return 0; }
vf3_matrix_load(s,ram,9,r[7]+r[0]);
goto P_0c086d30;
P_0c086d30: /* original 6063, guest PC 0x0c086d30 */
if(!s->budget--) { s->failed_pc=0x0c086d30u; return 0; }
r[0]=r[6];
goto P_0c086d32;
P_0c086d32: /* original 7001, guest PC 0x0c086d32 */
if(!s->budget--) { s->failed_pc=0x0c086d32u; return 0; }
r[0]+=0x00000001u;
goto P_0c086d34;
P_0c086d34: /* original f79c, guest PC 0x0c086d34 */
if(!s->budget--) { s->failed_pc=0x0c086d34u; return 0; }
vf3_matrix_move(s,7,9);
goto P_0c086d36;
P_0c086d36: /* original f741, guest PC 0x0c086d36 */
if(!s->budget--) { s->failed_pc=0x0c086d36u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'-');
goto P_0c086d38;
P_0c086d38: /* original 4008, guest PC 0x0c086d38 */
if(!s->budget--) { s->failed_pc=0x0c086d38u; return 0; }
r[0]<<=2;
goto P_0c086d3a;
P_0c086d3a: /* original f076, guest PC 0x0c086d3a */
if(!s->budget--) { s->failed_pc=0x0c086d3au; return 0; }
vf3_matrix_load(s,ram,0,r[7]+r[0]);
goto P_0c086d3c;
P_0c086d3c: /* original 6063, guest PC 0x0c086d3c */
if(!s->budget--) { s->failed_pc=0x0c086d3cu; return 0; }
r[0]=r[6];
goto P_0c086d3e;
P_0c086d3e: /* original 7002, guest PC 0x0c086d3e */
if(!s->budget--) { s->failed_pc=0x0c086d3eu; return 0; }
r[0]+=0x00000002u;
goto P_0c086d40;
P_0c086d40: /* original 4008, guest PC 0x0c086d40 */
if(!s->budget--) { s->failed_pc=0x0c086d40u; return 0; }
r[0]<<=2;
goto P_0c086d42;
P_0c086d42: /* original f275, guest PC 0x0c086d42 */
if(!s->budget--) { s->failed_pc=0x0c086d42u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[7]))!=0);
goto P_0c086d44;
P_0c086d44: /* original f376, guest PC 0x0c086d44 */
if(!s->budget--) { s->failed_pc=0x0c086d44u; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c086d46;
P_0c086d46: /* original f83c, guest PC 0x0c086d46 */
if(!s->budget--) { s->failed_pc=0x0c086d46u; return 0; }
vf3_matrix_move(s,8,3);
goto P_0c086d48;
P_0c086d48: /* original 8d2d, guest PC 0x0c086d48 */
if(!s->budget--) { s->failed_pc=0x0c086d48u; return 0; }
cond=r[17]&1u;
fr[8]^=0x80000000u;
if(cond) { goto P_0c086da6; }
goto P_0c086d4c;
P_0c086d4a: /* original f84d, guest PC 0x0c086d4a */
if(!s->budget--) { s->failed_pc=0x0c086d4au; return 0; }
fr[8]^=0x80000000u;
goto P_0c086d4c;
P_0c086d4c: /* original f68c, guest PC 0x0c086d4c */
if(!s->budget--) { s->failed_pc=0x0c086d4cu; return 0; }
vf3_matrix_move(s,6,8);
goto P_0c086d4e;
P_0c086d4e: /* original f651, guest PC 0x0c086d4e */
if(!s->budget--) { s->failed_pc=0x0c086d4eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'-');
goto P_0c086d50;
P_0c086d50: /* original f38d, guest PC 0x0c086d50 */
if(!s->budget--) { s->failed_pc=0x0c086d50u; return 0; }
fr[3]=0;
goto P_0c086d52;
P_0c086d52: /* original f365, guest PC 0x0c086d52 */
if(!s->budget--) { s->failed_pc=0x0c086d52u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c086d54;
P_0c086d54: /* original 8927, guest PC 0x0c086d54 */
if(!s->budget--) { s->failed_pc=0x0c086d54u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086da6; }
goto P_0c086d56;
P_0c086d56: /* original fa75, guest PC 0x0c086d56 */
if(!s->budget--) { s->failed_pc=0x0c086d56u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[7]))!=0);
goto P_0c086d58;
P_0c086d58: /* original 8b25, guest PC 0x0c086d58 */
if(!s->budget--) { s->failed_pc=0x0c086d58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086da6; }
goto P_0c086d5a;
P_0c086d5a: /* original fa65, guest PC 0x0c086d5a */
if(!s->budget--) { s->failed_pc=0x0c086d5au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[6]))!=0);
goto P_0c086d5c;
P_0c086d5c: /* original 8b23, guest PC 0x0c086d5c */
if(!s->budget--) { s->failed_pc=0x0c086d5cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086da6; }
goto P_0c086d5e;
P_0c086d5e: /* original f6b2, guest PC 0x0c086d5e */
if(!s->budget--) { s->failed_pc=0x0c086d5eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'*');
goto P_0c086d60;
P_0c086d60: /* original 9362, guest PC 0x0c086d60 */
if(!s->budget--) { s->failed_pc=0x0c086d60u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086e28u,2);
goto P_0c086d62;
P_0c086d62: /* original f7b2, guest PC 0x0c086d62 */
if(!s->budget--) { s->failed_pc=0x0c086d62u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[11],r[18],'*');
goto P_0c086d64;
P_0c086d64: /* original 4d08, guest PC 0x0c086d64 */
if(!s->budget--) { s->failed_pc=0x0c086d64u; return 0; }
r[13]<<=2;
goto P_0c086d66;
P_0c086d66: /* original 335c, guest PC 0x0c086d66 */
if(!s->budget--) { s->failed_pc=0x0c086d66u; return 0; }
r[3]+=r[5];
goto P_0c086d68;
P_0c086d68: /* original 975f, guest PC 0x0c086d68 */
if(!s->budget--) { s->failed_pc=0x0c086d68u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086e2au,2);
goto P_0c086d6a;
P_0c086d6a: /* original 3d3c, guest PC 0x0c086d6a */
if(!s->budget--) { s->failed_pc=0x0c086d6au; return 0; }
r[13]+=r[3];
goto P_0c086d6c;
P_0c086d6c: /* original f63d, guest PC 0x0c086d6c */
if(!s->budget--) { s->failed_pc=0x0c086d6cu; return 0; }
r[53]=truncate_float(fr[6]);
goto P_0c086d6e;
P_0c086d6e: /* original f6d8, guest PC 0x0c086d6e */
if(!s->budget--) { s->failed_pc=0x0c086d6eu; return 0; }
vf3_matrix_load(s,ram,6,r[13]);
goto P_0c086d70;
P_0c086d70: /* original 374c, guest PC 0x0c086d70 */
if(!s->budget--) { s->failed_pc=0x0c086d70u; return 0; }
r[7]+=r[4];
goto P_0c086d72;
P_0c086d72: /* original 005a, guest PC 0x0c086d72 */
if(!s->budget--) { s->failed_pc=0x0c086d72u; return 0; }
r[0]=r[53];
goto P_0c086d74;
P_0c086d74: /* original f73d, guest PC 0x0c086d74 */
if(!s->budget--) { s->failed_pc=0x0c086d74u; return 0; }
r[53]=truncate_float(fr[7]);
goto P_0c086d76;
P_0c086d76: /* original 6d03, guest PC 0x0c086d76 */
if(!s->budget--) { s->failed_pc=0x0c086d76u; return 0; }
r[13]=r[0];
goto P_0c086d78;
P_0c086d78: /* original 4018, guest PC 0x0c086d78 */
if(!s->budget--) { s->failed_pc=0x0c086d78u; return 0; }
r[0]<<=8;
goto P_0c086d7a;
P_0c086d7a: /* original 065a, guest PC 0x0c086d7a */
if(!s->budget--) { s->failed_pc=0x0c086d7au; return 0; }
r[6]=r[53];
goto P_0c086d7c;
P_0c086d7c: /* original 4d08, guest PC 0x0c086d7c */
if(!s->budget--) { s->failed_pc=0x0c086d7cu; return 0; }
r[13]<<=2;
goto P_0c086d7e;
P_0c086d7e: /* original 4d08, guest PC 0x0c086d7e */
if(!s->budget--) { s->failed_pc=0x0c086d7eu; return 0; }
r[13]<<=2;
goto P_0c086d80;
P_0c086d80: /* original 6163, guest PC 0x0c086d80 */
if(!s->budget--) { s->failed_pc=0x0c086d80u; return 0; }
r[1]=r[6];
goto P_0c086d82;
P_0c086d82: /* original 4608, guest PC 0x0c086d82 */
if(!s->budget--) { s->failed_pc=0x0c086d82u; return 0; }
r[6]<<=2;
goto P_0c086d84;
P_0c086d84: /* original 4608, guest PC 0x0c086d84 */
if(!s->budget--) { s->failed_pc=0x0c086d84u; return 0; }
r[6]<<=2;
goto P_0c086d86;
P_0c086d86: /* original 360c, guest PC 0x0c086d86 */
if(!s->budget--) { s->failed_pc=0x0c086d86u; return 0; }
r[6]+=r[0];
goto P_0c086d88;
P_0c086d88: /* original e004, guest PC 0x0c086d88 */
if(!s->budget--) { s->failed_pc=0x0c086d88u; return 0; }
r[0]=0x00000004u;
goto P_0c086d8a;
P_0c086d8a: /* original 376c, guest PC 0x0c086d8a */
if(!s->budget--) { s->failed_pc=0x0c086d8au; return 0; }
r[7]+=r[6];
goto P_0c086d8c;
P_0c086d8c: /* original f79a, guest PC 0x0c086d8c */
if(!s->budget--) { s->failed_pc=0x0c086d8cu; return 0; }
vf3_matrix_store(s,ram,9,r[7]);
goto P_0c086d8e;
P_0c086d8e: /* original f707, guest PC 0x0c086d8e */
if(!s->budget--) { s->failed_pc=0x0c086d8eu; return 0; }
vf3_matrix_store(s,ram,0,r[7]+r[0]);
goto P_0c086d90;
P_0c086d90: /* original e008, guest PC 0x0c086d90 */
if(!s->budget--) { s->failed_pc=0x0c086d90u; return 0; }
r[0]=0x00000008u;
goto P_0c086d92;
P_0c086d92: /* original f787, guest PC 0x0c086d92 */
if(!s->budget--) { s->failed_pc=0x0c086d92u; return 0; }
vf3_matrix_store(s,ram,8,r[7]+r[0]);
goto P_0c086d94;
P_0c086d94: /* original e00c, guest PC 0x0c086d94 */
if(!s->budget--) { s->failed_pc=0x0c086d94u; return 0; }
r[0]=0x0000000cu;
goto P_0c086d96;
P_0c086d96: /* original f767, guest PC 0x0c086d96 */
if(!s->budget--) { s->failed_pc=0x0c086d96u; return 0; }
vf3_matrix_store(s,ram,6,r[7]+r[0]);
goto P_0c086d98;
P_0c086d98: /* original 6043, guest PC 0x0c086d98 */
if(!s->budget--) { s->failed_pc=0x0c086d98u; return 0; }
r[0]=r[4];
goto P_0c086d9a;
P_0c086d9a: /* original 6713, guest PC 0x0c086d9a */
if(!s->budget--) { s->failed_pc=0x0c086d9au; return 0; }
r[7]=r[1];
goto P_0c086d9c;
P_0c086d9c: /* original 7020, guest PC 0x0c086d9c */
if(!s->budget--) { s->failed_pc=0x0c086d9cu; return 0; }
r[0]+=0x00000020u;
goto P_0c086d9e;
P_0c086d9e: /* original 37dc, guest PC 0x0c086d9e */
if(!s->budget--) { s->failed_pc=0x0c086d9eu; return 0; }
r[7]+=r[13];
goto P_0c086da0;
P_0c086da0: /* original 307c, guest PC 0x0c086da0 */
if(!s->budget--) { s->failed_pc=0x0c086da0u; return 0; }
r[0]+=r[7];
goto P_0c086da2;
P_0c086da2: /* original e601, guest PC 0x0c086da2 */
if(!s->budget--) { s->failed_pc=0x0c086da2u; return 0; }
r[6]=0x00000001u;
goto P_0c086da4;
P_0c086da4: /* original 2060, guest PC 0x0c086da4 */
if(!s->budget--) { s->failed_pc=0x0c086da4u; return 0; }
write(ram,r[0],r[6],1);
goto P_0c086da6;
P_0c086da6: /* original afb2, guest PC 0x0c086da6 */
if(!s->budget--) { s->failed_pc=0x0c086da6u; return 0; }
r[12]+=0x00000001u;
goto P_0c086d0e;
P_0c086da8: /* original 7c01, guest PC 0x0c086da8 */
if(!s->budget--) { s->failed_pc=0x0c086da8u; return 0; }
r[12]+=0x00000001u;
goto P_0c086daa;
P_0c086daa: /* original 6af6, guest PC 0x0c086daa */
if(!s->budget--) { s->failed_pc=0x0c086daau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c086dac;
P_0c086dac: /* original 6cf6, guest PC 0x0c086dac */
if(!s->budget--) { s->failed_pc=0x0c086dacu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c086dae;
P_0c086dae: /* original 000b, guest PC 0x0c086dae */
if(!s->budget--) { s->failed_pc=0x0c086daeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c086db0: /* original 6df6, guest PC 0x0c086db0 */
if(!s->budget--) { s->failed_pc=0x0c086db0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c086db2;
P_0c086db2: /* original fffb, guest PC 0x0c086db2 */
if(!s->budget--) { s->failed_pc=0x0c086db2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c086db4;
P_0c086db4: /* original e018, guest PC 0x0c086db4 */
if(!s->budget--) { s->failed_pc=0x0c086db4u; return 0; }
r[0]=0x00000018u;
goto P_0c086db6;
P_0c086db6: /* original ffeb, guest PC 0x0c086db6 */
if(!s->budget--) { s->failed_pc=0x0c086db6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c086db8;
P_0c086db8: /* original 4f22, guest PC 0x0c086db8 */
if(!s->budget--) { s->failed_pc=0x0c086db8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c086dba;
P_0c086dba: /* original 7ff4, guest PC 0x0c086dba */
if(!s->budget--) { s->failed_pc=0x0c086dbau; return 0; }
r[15]+=0xfffffff4u;
goto P_0c086dbc;
P_0c086dbc: /* original 2f42, guest PC 0x0c086dbc */
if(!s->budget--) { s->failed_pc=0x0c086dbcu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c086dbe;
P_0c086dbe: /* original 1f62, guest PC 0x0c086dbe */
if(!s->budget--) { s->failed_pc=0x0c086dbeu; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c086dc0;
P_0c086dc0: /* original 1f71, guest PC 0x0c086dc0 */
if(!s->budget--) { s->failed_pc=0x0c086dc0u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c086dc2;
P_0c086dc2: /* original ff56, guest PC 0x0c086dc2 */
if(!s->budget--) { s->failed_pc=0x0c086dc2u; return 0; }
vf3_matrix_load(s,ram,15,r[5]+r[0]);
goto P_0c086dc4;
P_0c086dc4: /* original e01c, guest PC 0x0c086dc4 */
if(!s->budget--) { s->failed_pc=0x0c086dc4u; return 0; }
r[0]=0x0000001cu;
goto P_0c086dc6;
P_0c086dc6: /* original fe56, guest PC 0x0c086dc6 */
if(!s->budget--) { s->failed_pc=0x0c086dc6u; return 0; }
vf3_matrix_load(s,ram,14,r[5]+r[0]);
goto P_0c086dc8;
P_0c086dc8: /* original 55f2, guest PC 0x0c086dc8 */
if(!s->budget--) { s->failed_pc=0x0c086dc8u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c086dca;
P_0c086dca: /* original f4fc, guest PC 0x0c086dca */
if(!s->budget--) { s->failed_pc=0x0c086dcau; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c086dcc;
P_0c086dcc: /* original f5ec, guest PC 0x0c086dcc */
if(!s->budget--) { s->failed_pc=0x0c086dccu; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c086dce;
P_0c086dce: /* original bf95, guest PC 0x0c086dce */
if(!s->budget--) { s->failed_pc=0x0c086dceu; return 0; }
target=code_base|0x0c086cfcu; r[16]=code_base|0x0c086dd2u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c086dd2u) { target=s->pc; goto dispatch; }
goto P_0c086dd2;
P_0c086dd0: /* original 64f2, guest PC 0x0c086dd0 */
if(!s->budget--) { s->failed_pc=0x0c086dd0u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c086dd2;
P_0c086dd2: /* original 55f1, guest PC 0x0c086dd2 */
if(!s->budget--) { s->failed_pc=0x0c086dd2u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c086dd4;
P_0c086dd4: /* original 64f2, guest PC 0x0c086dd4 */
if(!s->budget--) { s->failed_pc=0x0c086dd4u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c086dd6;
P_0c086dd6: /* original 7f0c, guest PC 0x0c086dd6 */
if(!s->budget--) { s->failed_pc=0x0c086dd6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c086dd8;
P_0c086dd8: /* original 4f26, guest PC 0x0c086dd8 */
if(!s->budget--) { s->failed_pc=0x0c086dd8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c086dda;
P_0c086dda: /* original f5ec, guest PC 0x0c086dda */
if(!s->budget--) { s->failed_pc=0x0c086ddau; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c086ddc;
P_0c086ddc: /* original f4fc, guest PC 0x0c086ddc */
if(!s->budget--) { s->failed_pc=0x0c086ddcu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c086dde;
P_0c086dde: /* original fef9, guest PC 0x0c086dde */
if(!s->budget--) { s->failed_pc=0x0c086ddeu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086de0;
P_0c086de0: /* original af8c, guest PC 0x0c086de0 */
if(!s->budget--) { s->failed_pc=0x0c086de0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086cfc;
P_0c086de2: /* original fff9, guest PC 0x0c086de2 */
if(!s->budget--) { s->failed_pc=0x0c086de2u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086de4;
P_0c086de4: /* original d717, guest PC 0x0c086de4 */
if(!s->budget--) { s->failed_pc=0x0c086de4u; return 0; }
r[7]=read(ram,0x0c086e44u,4);
goto P_0c086de6;
P_0c086de6: /* original e048, guest PC 0x0c086de6 */
if(!s->budget--) { s->failed_pc=0x0c086de6u; return 0; }
r[0]=0x00000048u;
goto P_0c086de8;
P_0c086de8: /* original d317, guest PC 0x0c086de8 */
if(!s->budget--) { s->failed_pc=0x0c086de8u; return 0; }
r[3]=read(ram,0x0c086e48u,4);
goto P_0c086dea;
P_0c086dea: /* original 5674, guest PC 0x0c086dea */
if(!s->budget--) { s->failed_pc=0x0c086deau; return 0; }
r[6]=read(ram,r[7]+16,4);
goto P_0c086dec;
P_0c086dec: /* original 026e, guest PC 0x0c086dec */
if(!s->budget--) { s->failed_pc=0x0c086decu; return 0; }
r[2]=read(ram,r[6]+r[0],4);
goto P_0c086dee;
P_0c086dee: /* original 2238, guest PC 0x0c086dee */
if(!s->budget--) { s->failed_pc=0x0c086deeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c086df0;
P_0c086df0: /* original 8d03, guest PC 0x0c086df0 */
if(!s->budget--) { s->failed_pc=0x0c086df0u; return 0; }
cond=r[17]&1u;
r[7]=read(ram,r[7]+20,4);
if(cond) { goto P_0c086dfa; }
goto P_0c086df4;
P_0c086df2: /* original 5775, guest PC 0x0c086df2 */
if(!s->budget--) { s->failed_pc=0x0c086df2u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c086df4;
P_0c086df4: /* original 2472, guest PC 0x0c086df4 */
if(!s->budget--) { s->failed_pc=0x0c086df4u; return 0; }
write(ram,r[4],r[7],4);
goto P_0c086df6;
P_0c086df6: /* original a002, guest PC 0x0c086df6 */
if(!s->budget--) { s->failed_pc=0x0c086df6u; return 0; }
write(ram,r[5],r[6],4);
goto P_0c086dfe;
P_0c086df8: /* original 2562, guest PC 0x0c086df8 */
if(!s->budget--) { s->failed_pc=0x0c086df8u; return 0; }
write(ram,r[5],r[6],4);
goto P_0c086dfa;
P_0c086dfa: /* original 2462, guest PC 0x0c086dfa */
if(!s->budget--) { s->failed_pc=0x0c086dfau; return 0; }
write(ram,r[4],r[6],4);
goto P_0c086dfc;
P_0c086dfc: /* original 2572, guest PC 0x0c086dfc */
if(!s->budget--) { s->failed_pc=0x0c086dfcu; return 0; }
write(ram,r[5],r[7],4);
goto P_0c086dfe;
P_0c086dfe: /* original 000b, guest PC 0x0c086dfe */
if(!s->budget--) { s->failed_pc=0x0c086dfeu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c086e00: /* original 0009, guest PC 0x0c086e00 */
if(!s->budget--) { s->failed_pc=0x0c086e00u; return 0; }
goto P_0c086e02;
P_0c086e02: /* original 2fe6, guest PC 0x0c086e02 */
if(!s->budget--) { s->failed_pc=0x0c086e02u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086e04;
P_0c086e04: /* original 6543, guest PC 0x0c086e04 */
if(!s->budget--) { s->failed_pc=0x0c086e04u; return 0; }
r[5]=r[4];
goto P_0c086e06;
P_0c086e06: /* original 2fd6, guest PC 0x0c086e06 */
if(!s->budget--) { s->failed_pc=0x0c086e06u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086e08;
P_0c086e08: /* original 7520, guest PC 0x0c086e08 */
if(!s->budget--) { s->failed_pc=0x0c086e08u; return 0; }
r[5]+=0x00000020u;
goto P_0c086e0a;
P_0c086e0a: /* original 960e, guest PC 0x0c086e0a */
if(!s->budget--) { s->failed_pc=0x0c086e0au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086e2au,2);
goto P_0c086e0c;
P_0c086e0c: /* original 9010, guest PC 0x0c086e0c */
if(!s->budget--) { s->failed_pc=0x0c086e0cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086e30u,2);
goto P_0c086e0e;
P_0c086e0e: /* original 9e0d, guest PC 0x0c086e0e */
if(!s->budget--) { s->failed_pc=0x0c086e0eu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086e2cu,2);
goto P_0c086e10;
P_0c086e10: /* original 364c, guest PC 0x0c086e10 */
if(!s->budget--) { s->failed_pc=0x0c086e10u; return 0; }
r[6]+=r[4];
goto P_0c086e12;
P_0c086e12: /* original 9d0c, guest PC 0x0c086e12 */
if(!s->budget--) { s->failed_pc=0x0c086e12u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086e2eu,2);
goto P_0c086e14;
P_0c086e14: /* original 6103, guest PC 0x0c086e14 */
if(!s->budget--) { s->failed_pc=0x0c086e14u; return 0; }
r[1]=r[0];
goto P_0c086e16;
P_0c086e16: /* original e400, guest PC 0x0c086e16 */
if(!s->budget--) { s->failed_pc=0x0c086e16u; return 0; }
r[4]=0x00000000u;
goto P_0c086e18;
P_0c086e18: /* original f48d, guest PC 0x0c086e18 */
if(!s->budget--) { s->failed_pc=0x0c086e18u; return 0; }
fr[4]=0;
goto P_0c086e1a;
P_0c086e1a: /* original 316c, guest PC 0x0c086e1a */
if(!s->budget--) { s->failed_pc=0x0c086e1au; return 0; }
r[1]+=r[6];
goto P_0c086e1c;
P_0c086e1c: /* original 6763, guest PC 0x0c086e1c */
if(!s->budget--) { s->failed_pc=0x0c086e1cu; return 0; }
r[7]=r[6];
goto P_0c086e1e;
P_0c086e1e: /* original 3d6c, guest PC 0x0c086e1e */
if(!s->budget--) { s->failed_pc=0x0c086e1eu; return 0; }
r[13]+=r[6];
goto P_0c086e20;
P_0c086e20: /* original 3e6c, guest PC 0x0c086e20 */
if(!s->budget--) { s->failed_pc=0x0c086e20u; return 0; }
r[14]+=r[6];
goto P_0c086e22;
P_0c086e22: /* original a024, guest PC 0x0c086e22 */
if(!s->budget--) { s->failed_pc=0x0c086e22u; return 0; }
r[6]=0x00000040u;
goto P_0c086e6e;
P_0c086e24: /* original e640, guest PC 0x0c086e24 */
if(!s->budget--) { s->failed_pc=0x0c086e24u; return 0; }
r[6]=0x00000040u;
if(!vf3_matrix_family(0x0c086e26u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c086e26u; return 0; } return 1;
P_0c086e4c: /* original 2540, guest PC 0x0c086e4c */
if(!s->budget--) { s->failed_pc=0x0c086e4cu; return 0; }
write(ram,r[5],r[4],1);
goto P_0c086e4e;
P_0c086e4e: /* original 7501, guest PC 0x0c086e4e */
if(!s->budget--) { s->failed_pc=0x0c086e4eu; return 0; }
r[5]+=0x00000001u;
goto P_0c086e50;
P_0c086e50: /* original 2540, guest PC 0x0c086e50 */
if(!s->budget--) { s->failed_pc=0x0c086e50u; return 0; }
write(ram,r[5],r[4],1);
goto P_0c086e52;
P_0c086e52: /* original 7501, guest PC 0x0c086e52 */
if(!s->budget--) { s->failed_pc=0x0c086e52u; return 0; }
r[5]+=0x00000001u;
goto P_0c086e54;
P_0c086e54: /* original 2540, guest PC 0x0c086e54 */
if(!s->budget--) { s->failed_pc=0x0c086e54u; return 0; }
write(ram,r[5],r[4],1);
goto P_0c086e56;
P_0c086e56: /* original 7501, guest PC 0x0c086e56 */
if(!s->budget--) { s->failed_pc=0x0c086e56u; return 0; }
r[5]+=0x00000001u;
goto P_0c086e58;
P_0c086e58: /* original 2540, guest PC 0x0c086e58 */
if(!s->budget--) { s->failed_pc=0x0c086e58u; return 0; }
write(ram,r[5],r[4],1);
goto P_0c086e5a;
P_0c086e5a: /* original 76ff, guest PC 0x0c086e5a */
if(!s->budget--) { s->failed_pc=0x0c086e5au; return 0; }
r[6]+=0xffffffffu;
goto P_0c086e5c;
P_0c086e5c: /* original f74a, guest PC 0x0c086e5c */
if(!s->budget--) { s->failed_pc=0x0c086e5cu; return 0; }
vf3_matrix_store(s,ram,4,r[7]);
goto P_0c086e5e;
P_0c086e5e: /* original 7501, guest PC 0x0c086e5e */
if(!s->budget--) { s->failed_pc=0x0c086e5eu; return 0; }
r[5]+=0x00000001u;
goto P_0c086e60;
P_0c086e60: /* original fe4a, guest PC 0x0c086e60 */
if(!s->budget--) { s->failed_pc=0x0c086e60u; return 0; }
vf3_matrix_store(s,ram,4,r[14]);
goto P_0c086e62;
P_0c086e62: /* original 7e04, guest PC 0x0c086e62 */
if(!s->budget--) { s->failed_pc=0x0c086e62u; return 0; }
r[14]+=0x00000004u;
goto P_0c086e64;
P_0c086e64: /* original fd4a, guest PC 0x0c086e64 */
if(!s->budget--) { s->failed_pc=0x0c086e64u; return 0; }
vf3_matrix_store(s,ram,4,r[13]);
goto P_0c086e66;
P_0c086e66: /* original 7704, guest PC 0x0c086e66 */
if(!s->budget--) { s->failed_pc=0x0c086e66u; return 0; }
r[7]+=0x00000004u;
goto P_0c086e68;
P_0c086e68: /* original f14a, guest PC 0x0c086e68 */
if(!s->budget--) { s->failed_pc=0x0c086e68u; return 0; }
vf3_matrix_store(s,ram,4,r[1]);
goto P_0c086e6a;
P_0c086e6a: /* original 7104, guest PC 0x0c086e6a */
if(!s->budget--) { s->failed_pc=0x0c086e6au; return 0; }
r[1]+=0x00000004u;
goto P_0c086e6c;
P_0c086e6c: /* original 7d04, guest PC 0x0c086e6c */
if(!s->budget--) { s->failed_pc=0x0c086e6cu; return 0; }
r[13]+=0x00000004u;
goto P_0c086e6e;
P_0c086e6e: /* original 2668, guest PC 0x0c086e6e */
if(!s->budget--) { s->failed_pc=0x0c086e6eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c086e70;
P_0c086e70: /* original 8bec, guest PC 0x0c086e70 */
if(!s->budget--) { s->failed_pc=0x0c086e70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086e4c; }
goto P_0c086e72;
P_0c086e72: /* original 6df6, guest PC 0x0c086e72 */
if(!s->budget--) { s->failed_pc=0x0c086e72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c086e74;
P_0c086e74: /* original 000b, guest PC 0x0c086e74 */
if(!s->budget--) { s->failed_pc=0x0c086e74u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c086e76: /* original 6ef6, guest PC 0x0c086e76 */
if(!s->budget--) { s->failed_pc=0x0c086e76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c086e78;
P_0c086e78: /* original 2fe6, guest PC 0x0c086e78 */
if(!s->budget--) { s->failed_pc=0x0c086e78u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086e7a;
P_0c086e7a: /* original 2fd6, guest PC 0x0c086e7a */
if(!s->budget--) { s->failed_pc=0x0c086e7au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086e7c;
P_0c086e7c: /* original 6d43, guest PC 0x0c086e7c */
if(!s->budget--) { s->failed_pc=0x0c086e7cu; return 0; }
r[13]=r[4];
goto P_0c086e7e;
P_0c086e7e: /* original 2fc6, guest PC 0x0c086e7e */
if(!s->budget--) { s->failed_pc=0x0c086e7eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086e80;
P_0c086e80: /* original 60d2, guest PC 0x0c086e80 */
if(!s->budget--) { s->failed_pc=0x0c086e80u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c086e82;
P_0c086e82: /* original 4f22, guest PC 0x0c086e82 */
if(!s->budget--) { s->failed_pc=0x0c086e82u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c086e84;
P_0c086e84: /* original 88ff, guest PC 0x0c086e84 */
if(!s->budget--) { s->failed_pc=0x0c086e84u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c086e86;
P_0c086e86: /* original 8d09, guest PC 0x0c086e86 */
if(!s->budget--) { s->failed_pc=0x0c086e86u; return 0; }
cond=r[17]&1u;
r[14]=r[0];
if(cond) { goto P_0c086e9c; }
goto P_0c086e8a;
P_0c086e88: /* original 6e03, guest PC 0x0c086e88 */
if(!s->budget--) { s->failed_pc=0x0c086e88u; return 0; }
r[14]=r[0];
goto P_0c086e8a;
P_0c086e8a: /* original dc39, guest PC 0x0c086e8a */
if(!s->budget--) { s->failed_pc=0x0c086e8au; return 0; }
r[12]=read(ram,0x0c086f70u,4);
goto P_0c086e8c;
P_0c086e8c: /* original 65e3, guest PC 0x0c086e8c */
if(!s->budget--) { s->failed_pc=0x0c086e8cu; return 0; }
r[5]=r[14];
goto P_0c086e8e;
P_0c086e8e: /* original 4c0b, guest PC 0x0c086e8e */
if(!s->budget--) { s->failed_pc=0x0c086e8eu; return 0; }
target=r[12];
r[16]=code_base|0x0c086e92u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c086e92u) { target=s->pc; goto dispatch; }
goto P_0c086e92;
P_0c086e90: /* original 64d3, guest PC 0x0c086e90 */
if(!s->budget--) { s->failed_pc=0x0c086e90u; return 0; }
r[4]=r[13];
goto P_0c086e92;
P_0c086e92: /* original 6403, guest PC 0x0c086e92 */
if(!s->budget--) { s->failed_pc=0x0c086e92u; return 0; }
r[4]=r[0];
goto P_0c086e94;
P_0c086e94: /* original 6042, guest PC 0x0c086e94 */
if(!s->budget--) { s->failed_pc=0x0c086e94u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c086e96;
P_0c086e96: /* original 88ff, guest PC 0x0c086e96 */
if(!s->budget--) { s->failed_pc=0x0c086e96u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c086e98;
P_0c086e98: /* original 8ff8, guest PC 0x0c086e98 */
if(!s->budget--) { s->failed_pc=0x0c086e98u; return 0; }
cond=r[17]&1u;
r[14]=r[0];
if(!cond) { goto P_0c086e8c; }
goto P_0c086e9c;
P_0c086e9a: /* original 6e03, guest PC 0x0c086e9a */
if(!s->budget--) { s->failed_pc=0x0c086e9au; return 0; }
r[14]=r[0];
goto P_0c086e9c;
P_0c086e9c: /* original 4f26, guest PC 0x0c086e9c */
if(!s->budget--) { s->failed_pc=0x0c086e9cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c086e9e;
P_0c086e9e: /* original 6cf6, guest PC 0x0c086e9e */
if(!s->budget--) { s->failed_pc=0x0c086e9eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c086ea0;
P_0c086ea0: /* original 6df6, guest PC 0x0c086ea0 */
if(!s->budget--) { s->failed_pc=0x0c086ea0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c086ea2;
P_0c086ea2: /* original 000b, guest PC 0x0c086ea2 */
if(!s->budget--) { s->failed_pc=0x0c086ea2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c086ea4: /* original 6ef6, guest PC 0x0c086ea4 */
if(!s->budget--) { s->failed_pc=0x0c086ea4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c086ea6;
P_0c086ea6: /* original c733, guest PC 0x0c086ea6 */
if(!s->budget--) { s->failed_pc=0x0c086ea6u; return 0; }
r[0]=code_base|0x00086f74u;
goto P_0c086ea8;
P_0c086ea8: /* original 2fe6, guest PC 0x0c086ea8 */
if(!s->budget--) { s->failed_pc=0x0c086ea8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086eaa;
P_0c086eaa: /* original f708, guest PC 0x0c086eaa */
if(!s->budget--) { s->failed_pc=0x0c086eaau; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c086eac;
P_0c086eac: /* original c732, guest PC 0x0c086eac */
if(!s->budget--) { s->failed_pc=0x0c086eacu; return 0; }
r[0]=code_base|0x00086f78u;
goto P_0c086eae;
P_0c086eae: /* original f808, guest PC 0x0c086eae */
if(!s->budget--) { s->failed_pc=0x0c086eaeu; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c086eb0;
P_0c086eb0: /* original e00c, guest PC 0x0c086eb0 */
if(!s->budget--) { s->failed_pc=0x0c086eb0u; return 0; }
r[0]=0x0000000cu;
goto P_0c086eb2;
P_0c086eb2: /* original 6e63, guest PC 0x0c086eb2 */
if(!s->budget--) { s->failed_pc=0x0c086eb2u; return 0; }
r[14]=r[6];
goto P_0c086eb4;
P_0c086eb4: /* original f6e6, guest PC 0x0c086eb4 */
if(!s->budget--) { s->failed_pc=0x0c086eb4u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c086eb6;
P_0c086eb6: /* original f34c, guest PC 0x0c086eb6 */
if(!s->budget--) { s->failed_pc=0x0c086eb6u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c086eb8;
P_0c086eb8: /* original e014, guest PC 0x0c086eb8 */
if(!s->budget--) { s->failed_pc=0x0c086eb8u; return 0; }
r[0]=0x00000014u;
goto P_0c086eba;
P_0c086eba: /* original f46c, guest PC 0x0c086eba */
if(!s->budget--) { s->failed_pc=0x0c086ebau; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c086ebc;
P_0c086ebc: /* original f431, guest PC 0x0c086ebc */
if(!s->budget--) { s->failed_pc=0x0c086ebcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c086ebe;
P_0c086ebe: /* original fae6, guest PC 0x0c086ebe */
if(!s->budget--) { s->failed_pc=0x0c086ebeu; return 0; }
vf3_matrix_load(s,ram,10,r[14]+r[0]);
goto P_0c086ec0;
P_0c086ec0: /* original e310, guest PC 0x0c086ec0 */
if(!s->budget--) { s->failed_pc=0x0c086ec0u; return 0; }
r[3]=0x00000010u;
goto P_0c086ec2;
P_0c086ec2: /* original f35c, guest PC 0x0c086ec2 */
if(!s->budget--) { s->failed_pc=0x0c086ec2u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c086ec4;
P_0c086ec4: /* original 7ffc, guest PC 0x0c086ec4 */
if(!s->budget--) { s->failed_pc=0x0c086ec4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c086ec6;
P_0c086ec6: /* original f5ac, guest PC 0x0c086ec6 */
if(!s->budget--) { s->failed_pc=0x0c086ec6u; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c086ec8;
P_0c086ec8: /* original f531, guest PC 0x0c086ec8 */
if(!s->budget--) { s->failed_pc=0x0c086ec8u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c086eca;
P_0c086eca: /* original f472, guest PC 0x0c086eca */
if(!s->budget--) { s->failed_pc=0x0c086ecau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c086ecc;
P_0c086ecc: /* original f572, guest PC 0x0c086ecc */
if(!s->budget--) { s->failed_pc=0x0c086eccu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c086ece;
P_0c086ece: /* original f53d, guest PC 0x0c086ece */
if(!s->budget--) { s->failed_pc=0x0c086eceu; return 0; }
r[53]=truncate_float(fr[5]);
goto P_0c086ed0;
P_0c086ed0: /* original 075a, guest PC 0x0c086ed0 */
if(!s->budget--) { s->failed_pc=0x0c086ed0u; return 0; }
r[7]=r[53];
goto P_0c086ed2;
P_0c086ed2: /* original f43d, guest PC 0x0c086ed2 */
if(!s->budget--) { s->failed_pc=0x0c086ed2u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c086ed4;
P_0c086ed4: /* original 3737, guest PC 0x0c086ed4 */
if(!s->budget--) { s->failed_pc=0x0c086ed4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>(int32_t)r[3])!=0);
goto P_0c086ed6;
P_0c086ed6: /* original 8d46, guest PC 0x0c086ed6 */
if(!s->budget--) { s->failed_pc=0x0c086ed6u; return 0; }
cond=r[17]&1u;
r[6]=r[53];
if(cond) { goto P_0c086f66; }
goto P_0c086eda;
P_0c086ed8: /* original 065a, guest PC 0x0c086ed8 */
if(!s->budget--) { s->failed_pc=0x0c086ed8u; return 0; }
r[6]=r[53];
goto P_0c086eda;
P_0c086eda: /* original 3637, guest PC 0x0c086eda */
if(!s->budget--) { s->failed_pc=0x0c086edau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[3])!=0);
goto P_0c086edc;
P_0c086edc: /* original 8943, guest PC 0x0c086edc */
if(!s->budget--) { s->failed_pc=0x0c086edcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086f66; }
goto P_0c086ede;
P_0c086ede: /* original 6173, guest PC 0x0c086ede */
if(!s->budget--) { s->failed_pc=0x0c086edeu; return 0; }
r[1]=r[7];
goto P_0c086ee0;
P_0c086ee0: /* original 4108, guest PC 0x0c086ee0 */
if(!s->budget--) { s->failed_pc=0x0c086ee0u; return 0; }
r[1]<<=2;
goto P_0c086ee2;
P_0c086ee2: /* original 6343, guest PC 0x0c086ee2 */
if(!s->budget--) { s->failed_pc=0x0c086ee2u; return 0; }
r[3]=r[4];
goto P_0c086ee4;
P_0c086ee4: /* original 4108, guest PC 0x0c086ee4 */
if(!s->budget--) { s->failed_pc=0x0c086ee4u; return 0; }
r[1]<<=2;
goto P_0c086ee6;
P_0c086ee6: /* original 7320, guest PC 0x0c086ee6 */
if(!s->budget--) { s->failed_pc=0x0c086ee6u; return 0; }
r[3]+=0x00000020u;
goto P_0c086ee8;
P_0c086ee8: /* original 316c, guest PC 0x0c086ee8 */
if(!s->budget--) { s->failed_pc=0x0c086ee8u; return 0; }
r[1]+=r[6];
goto P_0c086eea;
P_0c086eea: /* original 313c, guest PC 0x0c086eea */
if(!s->budget--) { s->failed_pc=0x0c086eeau; return 0; }
r[1]+=r[3];
goto P_0c086eec;
P_0c086eec: /* original 6210, guest PC 0x0c086eec */
if(!s->budget--) { s->failed_pc=0x0c086eecu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[2]=tmp;
goto P_0c086eee;
P_0c086eee: /* original 2228, guest PC 0x0c086eee */
if(!s->budget--) { s->failed_pc=0x0c086eeeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c086ef0;
P_0c086ef0: /* original 8d39, guest PC 0x0c086ef0 */
if(!s->budget--) { s->failed_pc=0x0c086ef0u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[2],4);
if(cond) { goto P_0c086f66; }
goto P_0c086ef4;
P_0c086ef2: /* original 2f22, guest PC 0x0c086ef2 */
if(!s->budget--) { s->failed_pc=0x0c086ef2u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c086ef4;
P_0c086ef4: /* original 923a, guest PC 0x0c086ef4 */
if(!s->budget--) { s->failed_pc=0x0c086ef4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086f6cu,2);
goto P_0c086ef6;
P_0c086ef6: /* original 4608, guest PC 0x0c086ef6 */
if(!s->budget--) { s->failed_pc=0x0c086ef6u; return 0; }
r[6]<<=2;
goto P_0c086ef8;
P_0c086ef8: /* original 4718, guest PC 0x0c086ef8 */
if(!s->budget--) { s->failed_pc=0x0c086ef8u; return 0; }
r[7]<<=8;
goto P_0c086efa;
P_0c086efa: /* original 4608, guest PC 0x0c086efa */
if(!s->budget--) { s->failed_pc=0x0c086efau; return 0; }
r[6]<<=2;
goto P_0c086efc;
P_0c086efc: /* original 367c, guest PC 0x0c086efc */
if(!s->budget--) { s->failed_pc=0x0c086efcu; return 0; }
r[6]+=r[7];
goto P_0c086efe;
P_0c086efe: /* original 342c, guest PC 0x0c086efe */
if(!s->budget--) { s->failed_pc=0x0c086efeu; return 0; }
r[4]+=r[2];
goto P_0c086f00;
P_0c086f00: /* original e00c, guest PC 0x0c086f00 */
if(!s->budget--) { s->failed_pc=0x0c086f00u; return 0; }
r[0]=0x0000000cu;
goto P_0c086f02;
P_0c086f02: /* original 346c, guest PC 0x0c086f02 */
if(!s->budget--) { s->failed_pc=0x0c086f02u; return 0; }
r[4]+=r[6];
goto P_0c086f04;
P_0c086f04: /* original f946, guest PC 0x0c086f04 */
if(!s->budget--) { s->failed_pc=0x0c086f04u; return 0; }
vf3_matrix_load(s,ram,9,r[4]+r[0]);
goto P_0c086f06;
P_0c086f06: /* original e004, guest PC 0x0c086f06 */
if(!s->budget--) { s->failed_pc=0x0c086f06u; return 0; }
r[0]=0x00000004u;
goto P_0c086f08;
P_0c086f08: /* original f346, guest PC 0x0c086f08 */
if(!s->budget--) { s->failed_pc=0x0c086f08u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c086f0a;
P_0c086f0a: /* original e010, guest PC 0x0c086f0a */
if(!s->budget--) { s->failed_pc=0x0c086f0au; return 0; }
r[0]=0x00000010u;
goto P_0c086f0c;
P_0c086f0c: /* original f49c, guest PC 0x0c086f0c */
if(!s->budget--) { s->failed_pc=0x0c086f0cu; return 0; }
vf3_matrix_move(s,4,9);
goto P_0c086f0e;
P_0c086f0e: /* original f430, guest PC 0x0c086f0e */
if(!s->budget--) { s->failed_pc=0x0c086f0eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c086f10;
P_0c086f10: /* original f5e6, guest PC 0x0c086f10 */
if(!s->budget--) { s->failed_pc=0x0c086f10u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c086f12;
P_0c086f12: /* original f545, guest PC 0x0c086f12 */
if(!s->budget--) { s->failed_pc=0x0c086f12u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c086f14;
P_0c086f14: /* original 8927, guest PC 0x0c086f14 */
if(!s->budget--) { s->failed_pc=0x0c086f14u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086f66; }
goto P_0c086f16;
P_0c086f16: /* original fbe6, guest PC 0x0c086f16 */
if(!s->budget--) { s->failed_pc=0x0c086f16u; return 0; }
vf3_matrix_load(s,ram,11,r[14]+r[0]);
goto P_0c086f18;
P_0c086f18: /* original e004, guest PC 0x0c086f18 */
if(!s->budget--) { s->failed_pc=0x0c086f18u; return 0; }
r[0]=0x00000004u;
goto P_0c086f1a;
P_0c086f1a: /* original f746, guest PC 0x0c086f1a */
if(!s->budget--) { s->failed_pc=0x0c086f1au; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c086f1c;
P_0c086f1c: /* original e008, guest PC 0x0c086f1c */
if(!s->budget--) { s->failed_pc=0x0c086f1cu; return 0; }
r[0]=0x00000008u;
goto P_0c086f1e;
P_0c086f1e: /* original f548, guest PC 0x0c086f1e */
if(!s->budget--) { s->failed_pc=0x0c086f1eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
goto P_0c086f20;
P_0c086f20: /* original f7b1, guest PC 0x0c086f20 */
if(!s->budget--) { s->failed_pc=0x0c086f20u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[11],r[18],'-');
goto P_0c086f22;
P_0c086f22: /* original f446, guest PC 0x0c086f22 */
if(!s->budget--) { s->failed_pc=0x0c086f22u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c086f24;
P_0c086f24: /* original f561, guest PC 0x0c086f24 */
if(!s->budget--) { s->failed_pc=0x0c086f24u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c086f26;
P_0c086f26: /* original f39c, guest PC 0x0c086f26 */
if(!s->budget--) { s->failed_pc=0x0c086f26u; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c086f28;
P_0c086f28: /* original f4a1, guest PC 0x0c086f28 */
if(!s->budget--) { s->failed_pc=0x0c086f28u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[10],r[18],'-');
goto P_0c086f2a;
P_0c086f2a: /* original f932, guest PC 0x0c086f2a */
if(!s->budget--) { s->failed_pc=0x0c086f2au; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'*');
goto P_0c086f2c;
P_0c086f2c: /* original fa7c, guest PC 0x0c086f2c */
if(!s->budget--) { s->failed_pc=0x0c086f2cu; return 0; }
vf3_matrix_move(s,10,7);
goto P_0c086f2e;
P_0c086f2e: /* original fa72, guest PC 0x0c086f2e */
if(!s->budget--) { s->failed_pc=0x0c086f2eu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[7],r[18],'*');
goto P_0c086f30;
P_0c086f30: /* original f65c, guest PC 0x0c086f30 */
if(!s->budget--) { s->failed_pc=0x0c086f30u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c086f32;
P_0c086f32: /* original f652, guest PC 0x0c086f32 */
if(!s->budget--) { s->failed_pc=0x0c086f32u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c086f34;
P_0c086f34: /* original f74c, guest PC 0x0c086f34 */
if(!s->budget--) { s->failed_pc=0x0c086f34u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c086f36;
P_0c086f36: /* original f742, guest PC 0x0c086f36 */
if(!s->budget--) { s->failed_pc=0x0c086f36u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c086f38;
P_0c086f38: /* original f6a0, guest PC 0x0c086f38 */
if(!s->budget--) { s->failed_pc=0x0c086f38u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[10],r[18],'+');
goto P_0c086f3a;
P_0c086f3a: /* original f670, guest PC 0x0c086f3a */
if(!s->budget--) { s->failed_pc=0x0c086f3au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'+');
goto P_0c086f3c;
P_0c086f3c: /* original f695, guest PC 0x0c086f3c */
if(!s->budget--) { s->failed_pc=0x0c086f3cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[9]))!=0);
goto P_0c086f3e;
P_0c086f3e: /* original 8912, guest PC 0x0c086f3e */
if(!s->budget--) { s->failed_pc=0x0c086f3eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086f66; }
goto P_0c086f40;
P_0c086f40: /* original f582, guest PC 0x0c086f40 */
if(!s->budget--) { s->failed_pc=0x0c086f40u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'*');
goto P_0c086f42;
P_0c086f42: /* original e030, guest PC 0x0c086f42 */
if(!s->budget--) { s->failed_pc=0x0c086f42u; return 0; }
r[0]=0x00000030u;
goto P_0c086f44;
P_0c086f44: /* original f656, guest PC 0x0c086f44 */
if(!s->budget--) { s->failed_pc=0x0c086f44u; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c086f46;
P_0c086f46: /* original e018, guest PC 0x0c086f46 */
if(!s->budget--) { s->failed_pc=0x0c086f46u; return 0; }
r[0]=0x00000018u;
goto P_0c086f48;
P_0c086f48: /* original f482, guest PC 0x0c086f48 */
if(!s->budget--) { s->failed_pc=0x0c086f48u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'*');
goto P_0c086f4a;
P_0c086f4a: /* original e340, guest PC 0x0c086f4a */
if(!s->budget--) { s->failed_pc=0x0c086f4au; return 0; }
r[3]=0x00000040u;
goto P_0c086f4c;
P_0c086f4c: /* original 7f04, guest PC 0x0c086f4c */
if(!s->budget--) { s->failed_pc=0x0c086f4cu; return 0; }
r[15]+=0x00000004u;
goto P_0c086f4e;
P_0c086f4e: /* original 64e3, guest PC 0x0c086f4e */
if(!s->budget--) { s->failed_pc=0x0c086f4eu; return 0; }
r[4]=r[14];
goto P_0c086f50;
P_0c086f50: /* original fe57, guest PC 0x0c086f50 */
if(!s->budget--) { s->failed_pc=0x0c086f50u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c086f52;
P_0c086f52: /* original e01c, guest PC 0x0c086f52 */
if(!s->budget--) { s->failed_pc=0x0c086f52u; return 0; }
r[0]=0x0000001cu;
goto P_0c086f54;
P_0c086f54: /* original fe67, guest PC 0x0c086f54 */
if(!s->budget--) { s->failed_pc=0x0c086f54u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c086f56;
P_0c086f56: /* original e020, guest PC 0x0c086f56 */
if(!s->budget--) { s->failed_pc=0x0c086f56u; return 0; }
r[0]=0x00000020u;
goto P_0c086f58;
P_0c086f58: /* original fe47, guest PC 0x0c086f58 */
if(!s->budget--) { s->failed_pc=0x0c086f58u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c086f5a;
P_0c086f5a: /* original e026, guest PC 0x0c086f5a */
if(!s->budget--) { s->failed_pc=0x0c086f5au; return 0; }
r[0]=0x00000026u;
goto P_0c086f5c;
P_0c086f5c: /* original 0e34, guest PC 0x0c086f5c */
if(!s->budget--) { s->failed_pc=0x0c086f5cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c086f5e;
P_0c086f5e: /* original d307, guest PC 0x0c086f5e */
if(!s->budget--) { s->failed_pc=0x0c086f5eu; return 0; }
r[3]=read(ram,0x0c086f7cu,4);
goto P_0c086f60;
P_0c086f60: /* original 55ea, guest PC 0x0c086f60 */
if(!s->budget--) { s->failed_pc=0x0c086f60u; return 0; }
r[5]=read(ram,r[14]+40,4);
goto P_0c086f62;
P_0c086f62: /* original 432b, guest PC 0x0c086f62 */
if(!s->budget--) { s->failed_pc=0x0c086f62u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c03b450u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c086f64: /* original 6ef6, guest PC 0x0c086f64 */
if(!s->budget--) { s->failed_pc=0x0c086f64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c086f66;
P_0c086f66: /* original 7f04, guest PC 0x0c086f66 */
if(!s->budget--) { s->failed_pc=0x0c086f66u; return 0; }
r[15]+=0x00000004u;
goto P_0c086f68;
P_0c086f68: /* original 000b, guest PC 0x0c086f68 */
if(!s->budget--) { s->failed_pc=0x0c086f68u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c086f6a: /* original 6ef6, guest PC 0x0c086f6a */
if(!s->budget--) { s->failed_pc=0x0c086f6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c086f6cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c086f6cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
