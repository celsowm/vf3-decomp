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
int vf3_away_batch56_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c089d4cu: goto P_0c089d4c;
case 0x0c089d4eu: goto P_0c089d4e;
case 0x0c089d50u: goto P_0c089d50;
case 0x0c089d52u: goto P_0c089d52;
case 0x0c089d54u: goto P_0c089d54;
case 0x0c089d56u: goto P_0c089d56;
case 0x0c089d58u: goto P_0c089d58;
case 0x0c089d5au: goto P_0c089d5a;
case 0x0c089d5cu: goto P_0c089d5c;
case 0x0c089d5eu: goto P_0c089d5e;
case 0x0c089d60u: goto P_0c089d60;
case 0x0c089d62u: goto P_0c089d62;
case 0x0c089d64u: goto P_0c089d64;
case 0x0c089d66u: goto P_0c089d66;
case 0x0c089d68u: goto P_0c089d68;
case 0x0c089d6au: goto P_0c089d6a;
case 0x0c089d6cu: goto P_0c089d6c;
case 0x0c089d6eu: goto P_0c089d6e;
case 0x0c089d70u: goto P_0c089d70;
case 0x0c089d72u: goto P_0c089d72;
case 0x0c089d74u: goto P_0c089d74;
case 0x0c089d76u: goto P_0c089d76;
case 0x0c089d78u: goto P_0c089d78;
case 0x0c089d7au: goto P_0c089d7a;
case 0x0c089d7cu: goto P_0c089d7c;
case 0x0c089d7eu: goto P_0c089d7e;
case 0x0c089d80u: goto P_0c089d80;
case 0x0c089d82u: goto P_0c089d82;
case 0x0c089d84u: goto P_0c089d84;
case 0x0c089d86u: goto P_0c089d86;
case 0x0c089d88u: goto P_0c089d88;
case 0x0c089d8au: goto P_0c089d8a;
case 0x0c089d8cu: goto P_0c089d8c;
case 0x0c089d8eu: goto P_0c089d8e;
case 0x0c089d90u: goto P_0c089d90;
case 0x0c089d92u: goto P_0c089d92;
case 0x0c089d94u: goto P_0c089d94;
case 0x0c089d96u: goto P_0c089d96;
case 0x0c089d98u: goto P_0c089d98;
case 0x0c089d9au: goto P_0c089d9a;
case 0x0c089d9cu: goto P_0c089d9c;
case 0x0c089d9eu: goto P_0c089d9e;
case 0x0c089da0u: goto P_0c089da0;
case 0x0c089da2u: goto P_0c089da2;
case 0x0c089da4u: goto P_0c089da4;
case 0x0c089da6u: goto P_0c089da6;
case 0x0c089da8u: goto P_0c089da8;
case 0x0c089daau: goto P_0c089daa;
case 0x0c089dacu: goto P_0c089dac;
case 0x0c089daeu: goto P_0c089dae;
case 0x0c089db0u: goto P_0c089db0;
case 0x0c089db2u: goto P_0c089db2;
case 0x0c089db4u: goto P_0c089db4;
case 0x0c089db6u: goto P_0c089db6;
case 0x0c089db8u: goto P_0c089db8;
case 0x0c089dbau: goto P_0c089dba;
case 0x0c089dbcu: goto P_0c089dbc;
case 0x0c089dbeu: goto P_0c089dbe;
case 0x0c089dc0u: goto P_0c089dc0;
case 0x0c089dc2u: goto P_0c089dc2;
case 0x0c089dc4u: goto P_0c089dc4;
case 0x0c089dc6u: goto P_0c089dc6;
case 0x0c089dc8u: goto P_0c089dc8;
case 0x0c089dcau: goto P_0c089dca;
case 0x0c089dccu: goto P_0c089dcc;
case 0x0c089dceu: goto P_0c089dce;
case 0x0c089dd0u: goto P_0c089dd0;
case 0x0c089dd2u: goto P_0c089dd2;
case 0x0c089dd4u: goto P_0c089dd4;
case 0x0c089dd6u: goto P_0c089dd6;
case 0x0c089dd8u: goto P_0c089dd8;
case 0x0c089ddau: goto P_0c089dda;
case 0x0c089ddcu: goto P_0c089ddc;
case 0x0c089ddeu: goto P_0c089dde;
case 0x0c089de0u: goto P_0c089de0;
case 0x0c089de2u: goto P_0c089de2;
case 0x0c089de4u: goto P_0c089de4;
case 0x0c089de6u: goto P_0c089de6;
case 0x0c089de8u: goto P_0c089de8;
case 0x0c089deau: goto P_0c089dea;
case 0x0c089decu: goto P_0c089dec;
case 0x0c089deeu: goto P_0c089dee;
case 0x0c089df0u: goto P_0c089df0;
case 0x0c089df2u: goto P_0c089df2;
case 0x0c089df4u: goto P_0c089df4;
case 0x0c089df6u: goto P_0c089df6;
case 0x0c089df8u: goto P_0c089df8;
case 0x0c089dfau: goto P_0c089dfa;
case 0x0c089dfcu: goto P_0c089dfc;
case 0x0c089dfeu: goto P_0c089dfe;
case 0x0c089e00u: goto P_0c089e00;
case 0x0c089e02u: goto P_0c089e02;
case 0x0c089e04u: goto P_0c089e04;
case 0x0c089e06u: goto P_0c089e06;
case 0x0c089e08u: goto P_0c089e08;
case 0x0c089e0au: goto P_0c089e0a;
case 0x0c089e0cu: goto P_0c089e0c;
case 0x0c089e0eu: goto P_0c089e0e;
case 0x0c089e10u: goto P_0c089e10;
case 0x0c089e12u: goto P_0c089e12;
case 0x0c089e14u: goto P_0c089e14;
case 0x0c089e16u: goto P_0c089e16;
case 0x0c089e18u: goto P_0c089e18;
case 0x0c089e1au: goto P_0c089e1a;
case 0x0c089e1cu: goto P_0c089e1c;
case 0x0c089e1eu: goto P_0c089e1e;
case 0x0c089e20u: goto P_0c089e20;
case 0x0c089e22u: goto P_0c089e22;
case 0x0c089e24u: goto P_0c089e24;
case 0x0c089e26u: goto P_0c089e26;
case 0x0c089e28u: goto P_0c089e28;
case 0x0c089e2au: goto P_0c089e2a;
case 0x0c089e2cu: goto P_0c089e2c;
case 0x0c089e2eu: goto P_0c089e2e;
case 0x0c089e30u: goto P_0c089e30;
case 0x0c089e32u: goto P_0c089e32;
case 0x0c089e34u: goto P_0c089e34;
case 0x0c089e36u: goto P_0c089e36;
case 0x0c089e38u: goto P_0c089e38;
case 0x0c089e3au: goto P_0c089e3a;
case 0x0c089e3cu: goto P_0c089e3c;
case 0x0c089e3eu: goto P_0c089e3e;
case 0x0c089e40u: goto P_0c089e40;
case 0x0c089e42u: goto P_0c089e42;
case 0x0c089e44u: goto P_0c089e44;
case 0x0c089e46u: goto P_0c089e46;
case 0x0c089e48u: goto P_0c089e48;
case 0x0c089e4au: goto P_0c089e4a;
case 0x0c089e4cu: goto P_0c089e4c;
case 0x0c089e4eu: goto P_0c089e4e;
case 0x0c089e50u: goto P_0c089e50;
case 0x0c089e52u: goto P_0c089e52;
case 0x0c089e54u: goto P_0c089e54;
case 0x0c089e56u: goto P_0c089e56;
case 0x0c089e58u: goto P_0c089e58;
case 0x0c089e5au: goto P_0c089e5a;
case 0x0c089e5cu: goto P_0c089e5c;
case 0x0c089e5eu: goto P_0c089e5e;
case 0x0c089e60u: goto P_0c089e60;
case 0x0c089e62u: goto P_0c089e62;
case 0x0c089e64u: goto P_0c089e64;
case 0x0c089e66u: goto P_0c089e66;
case 0x0c089e68u: goto P_0c089e68;
case 0x0c089e6au: goto P_0c089e6a;
case 0x0c089e6cu: goto P_0c089e6c;
case 0x0c089e6eu: goto P_0c089e6e;
case 0x0c089e84u: goto P_0c089e84;
case 0x0c089e86u: goto P_0c089e86;
case 0x0c089e88u: goto P_0c089e88;
case 0x0c089e8au: goto P_0c089e8a;
case 0x0c089e8cu: goto P_0c089e8c;
case 0x0c089e8eu: goto P_0c089e8e;
case 0x0c089e90u: goto P_0c089e90;
case 0x0c089e92u: goto P_0c089e92;
case 0x0c089e94u: goto P_0c089e94;
case 0x0c089e96u: goto P_0c089e96;
case 0x0c089e98u: goto P_0c089e98;
case 0x0c089e9au: goto P_0c089e9a;
case 0x0c089e9cu: goto P_0c089e9c;
case 0x0c089e9eu: goto P_0c089e9e;
case 0x0c089ea0u: goto P_0c089ea0;
case 0x0c089ea2u: goto P_0c089ea2;
case 0x0c089ea4u: goto P_0c089ea4;
case 0x0c089ea6u: goto P_0c089ea6;
case 0x0c089ea8u: goto P_0c089ea8;
case 0x0c089eaau: goto P_0c089eaa;
case 0x0c089eacu: goto P_0c089eac;
case 0x0c089eaeu: goto P_0c089eae;
case 0x0c089eb0u: goto P_0c089eb0;
case 0x0c089eb2u: goto P_0c089eb2;
case 0x0c089eb4u: goto P_0c089eb4;
case 0x0c089eb6u: goto P_0c089eb6;
case 0x0c089eb8u: goto P_0c089eb8;
case 0x0c089ebau: goto P_0c089eba;
case 0x0c089ebcu: goto P_0c089ebc;
case 0x0c089ebeu: goto P_0c089ebe;
case 0x0c089ec0u: goto P_0c089ec0;
case 0x0c089ec2u: goto P_0c089ec2;
case 0x0c089ec4u: goto P_0c089ec4;
case 0x0c089ec6u: goto P_0c089ec6;
case 0x0c089ec8u: goto P_0c089ec8;
case 0x0c089ecau: goto P_0c089eca;
case 0x0c089eccu: goto P_0c089ecc;
case 0x0c089eceu: goto P_0c089ece;
case 0x0c089ed0u: goto P_0c089ed0;
case 0x0c089ed2u: goto P_0c089ed2;
case 0x0c089ed4u: goto P_0c089ed4;
case 0x0c089ed6u: goto P_0c089ed6;
case 0x0c089ed8u: goto P_0c089ed8;
case 0x0c089edau: goto P_0c089eda;
case 0x0c089edcu: goto P_0c089edc;
case 0x0c089edeu: goto P_0c089ede;
case 0x0c089ee0u: goto P_0c089ee0;
case 0x0c089ee2u: goto P_0c089ee2;
case 0x0c089ee4u: goto P_0c089ee4;
case 0x0c089ee6u: goto P_0c089ee6;
case 0x0c089ee8u: goto P_0c089ee8;
case 0x0c089eeau: goto P_0c089eea;
case 0x0c089eecu: goto P_0c089eec;
case 0x0c089eeeu: goto P_0c089eee;
case 0x0c089ef0u: goto P_0c089ef0;
case 0x0c089ef2u: goto P_0c089ef2;
case 0x0c089ef4u: goto P_0c089ef4;
case 0x0c089ef6u: goto P_0c089ef6;
case 0x0c089ef8u: goto P_0c089ef8;
case 0x0c089efau: goto P_0c089efa;
case 0x0c089efcu: goto P_0c089efc;
case 0x0c089efeu: goto P_0c089efe;
case 0x0c089f00u: goto P_0c089f00;
case 0x0c089f02u: goto P_0c089f02;
case 0x0c089f04u: goto P_0c089f04;
case 0x0c089f06u: goto P_0c089f06;
case 0x0c089f08u: goto P_0c089f08;
case 0x0c089f0au: goto P_0c089f0a;
case 0x0c089f0cu: goto P_0c089f0c;
case 0x0c089f0eu: goto P_0c089f0e;
case 0x0c089f10u: goto P_0c089f10;
case 0x0c089f12u: goto P_0c089f12;
case 0x0c089f14u: goto P_0c089f14;
case 0x0c089f16u: goto P_0c089f16;
case 0x0c089f18u: goto P_0c089f18;
case 0x0c089f1au: goto P_0c089f1a;
case 0x0c089f1cu: goto P_0c089f1c;
case 0x0c089f1eu: goto P_0c089f1e;
case 0x0c089f20u: goto P_0c089f20;
case 0x0c089f22u: goto P_0c089f22;
case 0x0c089f24u: goto P_0c089f24;
case 0x0c089f26u: goto P_0c089f26;
case 0x0c089f28u: goto P_0c089f28;
case 0x0c089f2au: goto P_0c089f2a;
case 0x0c089f2cu: goto P_0c089f2c;
case 0x0c089f2eu: goto P_0c089f2e;
case 0x0c089f30u: goto P_0c089f30;
case 0x0c089f32u: goto P_0c089f32;
case 0x0c089f34u: goto P_0c089f34;
case 0x0c089f36u: goto P_0c089f36;
case 0x0c089f38u: goto P_0c089f38;
case 0x0c089f3au: goto P_0c089f3a;
case 0x0c089f3cu: goto P_0c089f3c;
case 0x0c089f3eu: goto P_0c089f3e;
case 0x0c089f40u: goto P_0c089f40;
case 0x0c089f42u: goto P_0c089f42;
case 0x0c089f44u: goto P_0c089f44;
case 0x0c089f46u: goto P_0c089f46;
case 0x0c089f48u: goto P_0c089f48;
case 0x0c089f4au: goto P_0c089f4a;
case 0x0c089f4cu: goto P_0c089f4c;
case 0x0c089f4eu: goto P_0c089f4e;
case 0x0c089f50u: goto P_0c089f50;
case 0x0c089f52u: goto P_0c089f52;
case 0x0c089f54u: goto P_0c089f54;
case 0x0c089f56u: goto P_0c089f56;
case 0x0c089f58u: goto P_0c089f58;
case 0x0c089f5au: goto P_0c089f5a;
case 0x0c089f5cu: goto P_0c089f5c;
case 0x0c089f5eu: goto P_0c089f5e;
case 0x0c089f60u: goto P_0c089f60;
case 0x0c089f62u: goto P_0c089f62;
case 0x0c089f64u: goto P_0c089f64;
case 0x0c089f66u: goto P_0c089f66;
case 0x0c089f68u: goto P_0c089f68;
case 0x0c089f6au: goto P_0c089f6a;
case 0x0c089f6cu: goto P_0c089f6c;
case 0x0c089f6eu: goto P_0c089f6e;
case 0x0c089f70u: goto P_0c089f70;
case 0x0c089f72u: goto P_0c089f72;
case 0x0c089f74u: goto P_0c089f74;
case 0x0c089f76u: goto P_0c089f76;
case 0x0c089f78u: goto P_0c089f78;
case 0x0c089f7au: goto P_0c089f7a;
case 0x0c089f7cu: goto P_0c089f7c;
case 0x0c089f7eu: goto P_0c089f7e;
case 0x0c089f80u: goto P_0c089f80;
case 0x0c089f82u: goto P_0c089f82;
case 0x0c089f84u: goto P_0c089f84;
case 0x0c089f86u: goto P_0c089f86;
case 0x0c089f88u: goto P_0c089f88;
case 0x0c089f8au: goto P_0c089f8a;
case 0x0c089f8cu: goto P_0c089f8c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c089d4c: /* original 2fe6, guest PC 0x0c089d4c */
if(!s->budget--) { s->failed_pc=0x0c089d4cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089d4e;
P_0c089d4e: /* original 6e43, guest PC 0x0c089d4e */
if(!s->budget--) { s->failed_pc=0x0c089d4eu; return 0; }
r[14]=r[4];
goto P_0c089d50;
P_0c089d50: /* original 2fd6, guest PC 0x0c089d50 */
if(!s->budget--) { s->failed_pc=0x0c089d50u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089d52;
P_0c089d52: /* original ed00, guest PC 0x0c089d52 */
if(!s->budget--) { s->failed_pc=0x0c089d52u; return 0; }
r[13]=0x00000000u;
goto P_0c089d54;
P_0c089d54: /* original 2fc6, guest PC 0x0c089d54 */
if(!s->budget--) { s->failed_pc=0x0c089d54u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089d56;
P_0c089d56: /* original 7e14, guest PC 0x0c089d56 */
if(!s->budget--) { s->failed_pc=0x0c089d56u; return 0; }
r[14]+=0x00000014u;
goto P_0c089d58;
P_0c089d58: /* original 2fb6, guest PC 0x0c089d58 */
if(!s->budget--) { s->failed_pc=0x0c089d58u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089d5a;
P_0c089d5a: /* original 2fa6, guest PC 0x0c089d5a */
if(!s->budget--) { s->failed_pc=0x0c089d5au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089d5c;
P_0c089d5c: /* original ea02, guest PC 0x0c089d5c */
if(!s->budget--) { s->failed_pc=0x0c089d5cu; return 0; }
r[10]=0x00000002u;
goto P_0c089d5e;
P_0c089d5e: /* original fffb, guest PC 0x0c089d5e */
if(!s->budget--) { s->failed_pc=0x0c089d5eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c089d60;
P_0c089d60: /* original ffeb, guest PC 0x0c089d60 */
if(!s->budget--) { s->failed_pc=0x0c089d60u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c089d62;
P_0c089d62: /* original ffdb, guest PC 0x0c089d62 */
if(!s->budget--) { s->failed_pc=0x0c089d62u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c089d64;
P_0c089d64: /* original ffcb, guest PC 0x0c089d64 */
if(!s->budget--) { s->failed_pc=0x0c089d64u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c089d66;
P_0c089d66: /* original 4f22, guest PC 0x0c089d66 */
if(!s->budget--) { s->failed_pc=0x0c089d66u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c089d68;
P_0c089d68: /* original 9b82, guest PC 0x0c089d68 */
if(!s->budget--) { s->failed_pc=0x0c089d68u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c089e70u,2);
goto P_0c089d6a;
P_0c089d6a: /* original dc42, guest PC 0x0c089d6a */
if(!s->budget--) { s->failed_pc=0x0c089d6au; return 0; }
r[12]=read(ram,0x0c089e74u,4);
goto P_0c089d6c;
P_0c089d6c: /* original 7fe8, guest PC 0x0c089d6c */
if(!s->budget--) { s->failed_pc=0x0c089d6cu; return 0; }
r[15]+=0xffffffe8u;
goto P_0c089d6e;
P_0c089d6e: /* original e004, guest PC 0x0c089d6e */
if(!s->budget--) { s->failed_pc=0x0c089d6eu; return 0; }
r[0]=0x00000004u;
goto P_0c089d70;
P_0c089d70: /* original ffc8, guest PC 0x0c089d70 */
if(!s->budget--) { s->failed_pc=0x0c089d70u; return 0; }
vf3_matrix_load(s,ram,15,r[12]);
goto P_0c089d72;
P_0c089d72: /* original fec6, guest PC 0x0c089d72 */
if(!s->budget--) { s->failed_pc=0x0c089d72u; return 0; }
vf3_matrix_load(s,ram,14,r[12]+r[0]);
goto P_0c089d74;
P_0c089d74: /* original e008, guest PC 0x0c089d74 */
if(!s->budget--) { s->failed_pc=0x0c089d74u; return 0; }
r[0]=0x00000008u;
goto P_0c089d76;
P_0c089d76: /* original fdc6, guest PC 0x0c089d76 */
if(!s->budget--) { s->failed_pc=0x0c089d76u; return 0; }
vf3_matrix_load(s,ram,13,r[12]+r[0]);
goto P_0c089d78;
P_0c089d78: /* original e00c, guest PC 0x0c089d78 */
if(!s->budget--) { s->failed_pc=0x0c089d78u; return 0; }
r[0]=0x0000000cu;
goto P_0c089d7a;
P_0c089d7a: /* original fcc6, guest PC 0x0c089d7a */
if(!s->budget--) { s->failed_pc=0x0c089d7au; return 0; }
vf3_matrix_load(s,ram,12,r[12]+r[0]);
goto P_0c089d7c;
P_0c089d7c: /* original e010, guest PC 0x0c089d7c */
if(!s->budget--) { s->failed_pc=0x0c089d7cu; return 0; }
r[0]=0x00000010u;
goto P_0c089d7e;
P_0c089d7e: /* original f3c6, guest PC 0x0c089d7e */
if(!s->budget--) { s->failed_pc=0x0c089d7eu; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c089d80;
P_0c089d80: /* original e014, guest PC 0x0c089d80 */
if(!s->budget--) { s->failed_pc=0x0c089d80u; return 0; }
r[0]=0x00000014u;
goto P_0c089d82;
P_0c089d82: /* original ff37, guest PC 0x0c089d82 */
if(!s->budget--) { s->failed_pc=0x0c089d82u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c089d84;
P_0c089d84: /* original e014, guest PC 0x0c089d84 */
if(!s->budget--) { s->failed_pc=0x0c089d84u; return 0; }
r[0]=0x00000014u;
goto P_0c089d86;
P_0c089d86: /* original f3c6, guest PC 0x0c089d86 */
if(!s->budget--) { s->failed_pc=0x0c089d86u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c089d88;
P_0c089d88: /* original e010, guest PC 0x0c089d88 */
if(!s->budget--) { s->failed_pc=0x0c089d88u; return 0; }
r[0]=0x00000010u;
goto P_0c089d8a;
P_0c089d8a: /* original ff37, guest PC 0x0c089d8a */
if(!s->budget--) { s->failed_pc=0x0c089d8au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c089d8c;
P_0c089d8c: /* original e032, guest PC 0x0c089d8c */
if(!s->budget--) { s->failed_pc=0x0c089d8cu; return 0; }
r[0]=0x00000032u;
goto P_0c089d8e;
P_0c089d8e: /* original 53c6, guest PC 0x0c089d8e */
if(!s->budget--) { s->failed_pc=0x0c089d8eu; return 0; }
r[3]=read(ram,r[12]+24,4);
goto P_0c089d90;
P_0c089d90: /* original 7c1c, guest PC 0x0c089d90 */
if(!s->budget--) { s->failed_pc=0x0c089d90u; return 0; }
r[12]+=0x0000001cu;
goto P_0c089d92;
P_0c089d92: /* original 2f32, guest PC 0x0c089d92 */
if(!s->budget--) { s->failed_pc=0x0c089d92u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c089d94;
P_0c089d94: /* original 63f3, guest PC 0x0c089d94 */
if(!s->budget--) { s->failed_pc=0x0c089d94u; return 0; }
r[3]=r[15];
goto P_0c089d96;
P_0c089d96: /* original 0ed4, guest PC 0x0c089d96 */
if(!s->budget--) { s->failed_pc=0x0c089d96u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c089d98;
P_0c089d98: /* original e028, guest PC 0x0c089d98 */
if(!s->budget--) { s->failed_pc=0x0c089d98u; return 0; }
r[0]=0x00000028u;
goto P_0c089d9a;
P_0c089d9a: /* original 0ed5, guest PC 0x0c089d9a */
if(!s->budget--) { s->failed_pc=0x0c089d9au; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c089d9c;
P_0c089d9c: /* original e034, guest PC 0x0c089d9c */
if(!s->budget--) { s->failed_pc=0x0c089d9cu; return 0; }
r[0]=0x00000034u;
goto P_0c089d9e;
P_0c089d9e: /* original 0ed5, guest PC 0x0c089d9e */
if(!s->budget--) { s->failed_pc=0x0c089d9eu; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c089da0;
P_0c089da0: /* original e036, guest PC 0x0c089da0 */
if(!s->budget--) { s->failed_pc=0x0c089da0u; return 0; }
r[0]=0x00000036u;
goto P_0c089da2;
P_0c089da2: /* original 0ed5, guest PC 0x0c089da2 */
if(!s->budget--) { s->failed_pc=0x0c089da2u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c089da4;
P_0c089da4: /* original e031, guest PC 0x0c089da4 */
if(!s->budget--) { s->failed_pc=0x0c089da4u; return 0; }
r[0]=0x00000031u;
goto P_0c089da6;
P_0c089da6: /* original 0ed4, guest PC 0x0c089da6 */
if(!s->budget--) { s->failed_pc=0x0c089da6u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c089da8;
P_0c089da8: /* original e038, guest PC 0x0c089da8 */
if(!s->budget--) { s->failed_pc=0x0c089da8u; return 0; }
r[0]=0x00000038u;
goto P_0c089daa;
P_0c089daa: /* original 0eb5, guest PC 0x0c089daa */
if(!s->budget--) { s->failed_pc=0x0c089daau; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c089dac;
P_0c089dac: /* original 2f36, guest PC 0x0c089dac */
if(!s->budget--) { s->failed_pc=0x0c089dacu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089dae;
P_0c089dae: /* original 66f3, guest PC 0x0c089dae */
if(!s->budget--) { s->failed_pc=0x0c089daeu; return 0; }
r[6]=r[15];
goto P_0c089db0;
P_0c089db0: /* original 65f3, guest PC 0x0c089db0 */
if(!s->budget--) { s->failed_pc=0x0c089db0u; return 0; }
r[5]=r[15];
goto P_0c089db2;
P_0c089db2: /* original 67f3, guest PC 0x0c089db2 */
if(!s->budget--) { s->failed_pc=0x0c089db2u; return 0; }
r[7]=r[15];
goto P_0c089db4;
P_0c089db4: /* original 7508, guest PC 0x0c089db4 */
if(!s->budget--) { s->failed_pc=0x0c089db4u; return 0; }
r[5]+=0x00000008u;
goto P_0c089db6;
P_0c089db6: /* original 7710, guest PC 0x0c089db6 */
if(!s->budget--) { s->failed_pc=0x0c089db6u; return 0; }
r[7]+=0x00000010u;
goto P_0c089db8;
P_0c089db8: /* original 760c, guest PC 0x0c089db8 */
if(!s->budget--) { s->failed_pc=0x0c089db8u; return 0; }
r[6]+=0x0000000cu;
goto P_0c089dba;
P_0c089dba: /* original bf64, guest PC 0x0c089dba */
if(!s->budget--) { s->failed_pc=0x0c089dbau; return 0; }
target=code_base|0x0c089c86u; r[16]=code_base|0x0c089dbeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c089dbeu) { target=s->pc; goto dispatch; }
goto P_0c089dbe;
P_0c089dbc: /* original 64e3, guest PC 0x0c089dbc */
if(!s->budget--) { s->failed_pc=0x0c089dbcu; return 0; }
r[4]=r[14];
goto P_0c089dbe;
P_0c089dbe: /* original 7f04, guest PC 0x0c089dbe */
if(!s->budget--) { s->failed_pc=0x0c089dbeu; return 0; }
r[15]+=0x00000004u;
goto P_0c089dc0;
P_0c089dc0: /* original 6403, guest PC 0x0c089dc0 */
if(!s->budget--) { s->failed_pc=0x0c089dc0u; return 0; }
r[4]=r[0];
goto P_0c089dc2;
P_0c089dc2: /* original 63f2, guest PC 0x0c089dc2 */
if(!s->budget--) { s->failed_pc=0x0c089dc2u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c089dc4;
P_0c089dc4: /* original e02a, guest PC 0x0c089dc4 */
if(!s->budget--) { s->failed_pc=0x0c089dc4u; return 0; }
r[0]=0x0000002au;
goto P_0c089dc6;
P_0c089dc6: /* original 0e35, guest PC 0x0c089dc6 */
if(!s->budget--) { s->failed_pc=0x0c089dc6u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c089dc8;
P_0c089dc8: /* original e00c, guest PC 0x0c089dc8 */
if(!s->budget--) { s->failed_pc=0x0c089dc8u; return 0; }
r[0]=0x0000000cu;
goto P_0c089dca;
P_0c089dca: /* original f3f6, guest PC 0x0c089dca */
if(!s->budget--) { s->failed_pc=0x0c089dcau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089dcc;
P_0c089dcc: /* original e018, guest PC 0x0c089dcc */
if(!s->budget--) { s->failed_pc=0x0c089dccu; return 0; }
r[0]=0x00000018u;
goto P_0c089dce;
P_0c089dce: /* original fe37, guest PC 0x0c089dce */
if(!s->budget--) { s->failed_pc=0x0c089dceu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089dd0;
P_0c089dd0: /* original e004, guest PC 0x0c089dd0 */
if(!s->budget--) { s->failed_pc=0x0c089dd0u; return 0; }
r[0]=0x00000004u;
goto P_0c089dd2;
P_0c089dd2: /* original f3f6, guest PC 0x0c089dd2 */
if(!s->budget--) { s->failed_pc=0x0c089dd2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089dd4;
P_0c089dd4: /* original e024, guest PC 0x0c089dd4 */
if(!s->budget--) { s->failed_pc=0x0c089dd4u; return 0; }
r[0]=0x00000024u;
goto P_0c089dd6;
P_0c089dd6: /* original fe37, guest PC 0x0c089dd6 */
if(!s->budget--) { s->failed_pc=0x0c089dd6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089dd8;
P_0c089dd8: /* original e01c, guest PC 0x0c089dd8 */
if(!s->budget--) { s->failed_pc=0x0c089dd8u; return 0; }
r[0]=0x0000001cu;
goto P_0c089dda;
P_0c089dda: /* original f38d, guest PC 0x0c089dda */
if(!s->budget--) { s->failed_pc=0x0c089ddau; return 0; }
fr[3]=0;
goto P_0c089ddc;
P_0c089ddc: /* original fe37, guest PC 0x0c089ddc */
if(!s->budget--) { s->failed_pc=0x0c089ddcu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089dde;
P_0c089dde: /* original e008, guest PC 0x0c089dde */
if(!s->budget--) { s->failed_pc=0x0c089ddeu; return 0; }
r[0]=0x00000008u;
goto P_0c089de0;
P_0c089de0: /* original f3f6, guest PC 0x0c089de0 */
if(!s->budget--) { s->failed_pc=0x0c089de0u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089de2;
P_0c089de2: /* original e020, guest PC 0x0c089de2 */
if(!s->budget--) { s->failed_pc=0x0c089de2u; return 0; }
r[0]=0x00000020u;
goto P_0c089de4;
P_0c089de4: /* original fe37, guest PC 0x0c089de4 */
if(!s->budget--) { s->failed_pc=0x0c089de4u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089de6;
P_0c089de6: /* original e02c, guest PC 0x0c089de6 */
if(!s->budget--) { s->failed_pc=0x0c089de6u; return 0; }
r[0]=0x0000002cu;
goto P_0c089de8;
P_0c089de8: /* original 0eb5, guest PC 0x0c089de8 */
if(!s->budget--) { s->failed_pc=0x0c089de8u; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c089dea;
P_0c089dea: /* original e030, guest PC 0x0c089dea */
if(!s->budget--) { s->failed_pc=0x0c089deau; return 0; }
r[0]=0x00000030u;
goto P_0c089dec;
P_0c089dec: /* original 0e44, guest PC 0x0c089dec */
if(!s->budget--) { s->failed_pc=0x0c089decu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c089dee;
P_0c089dee: /* original e00c, guest PC 0x0c089dee */
if(!s->budget--) { s->failed_pc=0x0c089deeu; return 0; }
r[0]=0x0000000cu;
goto P_0c089df0;
P_0c089df0: /* original fef7, guest PC 0x0c089df0 */
if(!s->budget--) { s->failed_pc=0x0c089df0u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c089df2;
P_0c089df2: /* original e010, guest PC 0x0c089df2 */
if(!s->budget--) { s->failed_pc=0x0c089df2u; return 0; }
r[0]=0x00000010u;
goto P_0c089df4;
P_0c089df4: /* original fee7, guest PC 0x0c089df4 */
if(!s->budget--) { s->failed_pc=0x0c089df4u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c089df6;
P_0c089df6: /* original e014, guest PC 0x0c089df6 */
if(!s->budget--) { s->failed_pc=0x0c089df6u; return 0; }
r[0]=0x00000014u;
goto P_0c089df8;
P_0c089df8: /* original fed7, guest PC 0x0c089df8 */
if(!s->budget--) { s->failed_pc=0x0c089df8u; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c089dfa;
P_0c089dfa: /* original e014, guest PC 0x0c089dfa */
if(!s->budget--) { s->failed_pc=0x0c089dfau; return 0; }
r[0]=0x00000014u;
goto P_0c089dfc;
P_0c089dfc: /* original feca, guest PC 0x0c089dfc */
if(!s->budget--) { s->failed_pc=0x0c089dfcu; return 0; }
vf3_matrix_store(s,ram,12,r[14]);
goto P_0c089dfe;
P_0c089dfe: /* original f3f6, guest PC 0x0c089dfe */
if(!s->budget--) { s->failed_pc=0x0c089dfeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089e00;
P_0c089e00: /* original e004, guest PC 0x0c089e00 */
if(!s->budget--) { s->failed_pc=0x0c089e00u; return 0; }
r[0]=0x00000004u;
goto P_0c089e02;
P_0c089e02: /* original 4a10, guest PC 0x0c089e02 */
if(!s->budget--) { s->failed_pc=0x0c089e02u; return 0; }
--r[10];
r[17]=(r[17]&~1u)|((r[10]==0)!=0);
goto P_0c089e04;
P_0c089e04: /* original fe37, guest PC 0x0c089e04 */
if(!s->budget--) { s->failed_pc=0x0c089e04u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089e06;
P_0c089e06: /* original e010, guest PC 0x0c089e06 */
if(!s->budget--) { s->failed_pc=0x0c089e06u; return 0; }
r[0]=0x00000010u;
goto P_0c089e08;
P_0c089e08: /* original f3f6, guest PC 0x0c089e08 */
if(!s->budget--) { s->failed_pc=0x0c089e08u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089e0a;
P_0c089e0a: /* original e008, guest PC 0x0c089e0a */
if(!s->budget--) { s->failed_pc=0x0c089e0au; return 0; }
r[0]=0x00000008u;
goto P_0c089e0c;
P_0c089e0c: /* original fe37, guest PC 0x0c089e0c */
if(!s->budget--) { s->failed_pc=0x0c089e0cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089e0e;
P_0c089e0e: /* original e02a, guest PC 0x0c089e0e */
if(!s->budget--) { s->failed_pc=0x0c089e0eu; return 0; }
r[0]=0x0000002au;
goto P_0c089e10;
P_0c089e10: /* original 63f2, guest PC 0x0c089e10 */
if(!s->budget--) { s->failed_pc=0x0c089e10u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c089e12;
P_0c089e12: /* original 0e35, guest PC 0x0c089e12 */
if(!s->budget--) { s->failed_pc=0x0c089e12u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c089e14;
P_0c089e14: /* original 8fab, guest PC 0x0c089e14 */
if(!s->budget--) { s->failed_pc=0x0c089e14u; return 0; }
cond=r[17]&1u;
r[14]+=0x0000003cu;
if(!cond) { goto P_0c089d6e; }
goto P_0c089e18;
P_0c089e16: /* original 7e3c, guest PC 0x0c089e16 */
if(!s->budget--) { s->failed_pc=0x0c089e16u; return 0; }
r[14]+=0x0000003cu;
goto P_0c089e18;
P_0c089e18: /* original 7f18, guest PC 0x0c089e18 */
if(!s->budget--) { s->failed_pc=0x0c089e18u; return 0; }
r[15]+=0x00000018u;
goto P_0c089e1a;
P_0c089e1a: /* original 4f26, guest PC 0x0c089e1a */
if(!s->budget--) { s->failed_pc=0x0c089e1au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c089e1c;
P_0c089e1c: /* original fcf9, guest PC 0x0c089e1c */
if(!s->budget--) { s->failed_pc=0x0c089e1cu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c089e1e;
P_0c089e1e: /* original fdf9, guest PC 0x0c089e1e */
if(!s->budget--) { s->failed_pc=0x0c089e1eu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c089e20;
P_0c089e20: /* original fef9, guest PC 0x0c089e20 */
if(!s->budget--) { s->failed_pc=0x0c089e20u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c089e22;
P_0c089e22: /* original fff9, guest PC 0x0c089e22 */
if(!s->budget--) { s->failed_pc=0x0c089e22u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c089e24;
P_0c089e24: /* original 6af6, guest PC 0x0c089e24 */
if(!s->budget--) { s->failed_pc=0x0c089e24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c089e26;
P_0c089e26: /* original 6bf6, guest PC 0x0c089e26 */
if(!s->budget--) { s->failed_pc=0x0c089e26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c089e28;
P_0c089e28: /* original 6cf6, guest PC 0x0c089e28 */
if(!s->budget--) { s->failed_pc=0x0c089e28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c089e2a;
P_0c089e2a: /* original 6df6, guest PC 0x0c089e2a */
if(!s->budget--) { s->failed_pc=0x0c089e2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c089e2c;
P_0c089e2c: /* original 000b, guest PC 0x0c089e2c */
if(!s->budget--) { s->failed_pc=0x0c089e2cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c089e2e: /* original 6ef6, guest PC 0x0c089e2e */
if(!s->budget--) { s->failed_pc=0x0c089e2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c089e30;
P_0c089e30: /* original 2fe6, guest PC 0x0c089e30 */
if(!s->budget--) { s->failed_pc=0x0c089e30u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089e32;
P_0c089e32: /* original 2fd6, guest PC 0x0c089e32 */
if(!s->budget--) { s->failed_pc=0x0c089e32u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089e34;
P_0c089e34: /* original 2fc6, guest PC 0x0c089e34 */
if(!s->budget--) { s->failed_pc=0x0c089e34u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089e36;
P_0c089e36: /* original 2fb6, guest PC 0x0c089e36 */
if(!s->budget--) { s->failed_pc=0x0c089e36u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089e38;
P_0c089e38: /* original 2fa6, guest PC 0x0c089e38 */
if(!s->budget--) { s->failed_pc=0x0c089e38u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089e3a;
P_0c089e3a: /* original 2f96, guest PC 0x0c089e3a */
if(!s->budget--) { s->failed_pc=0x0c089e3au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089e3c;
P_0c089e3c: /* original 2f86, guest PC 0x0c089e3c */
if(!s->budget--) { s->failed_pc=0x0c089e3cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089e3e;
P_0c089e3e: /* original d10f, guest PC 0x0c089e3e */
if(!s->budget--) { s->failed_pc=0x0c089e3eu; return 0; }
r[1]=read(ram,0x0c089e7cu,4);
goto P_0c089e40;
P_0c089e40: /* original 4f22, guest PC 0x0c089e40 */
if(!s->budget--) { s->failed_pc=0x0c089e40u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c089e42;
P_0c089e42: /* original 6212, guest PC 0x0c089e42 */
if(!s->budget--) { s->failed_pc=0x0c089e42u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c089e44;
P_0c089e44: /* original d30c, guest PC 0x0c089e44 */
if(!s->budget--) { s->failed_pc=0x0c089e44u; return 0; }
r[3]=read(ram,0x0c089e78u,4);
goto P_0c089e46;
P_0c089e46: /* original 7fe4, guest PC 0x0c089e46 */
if(!s->budget--) { s->failed_pc=0x0c089e46u; return 0; }
r[15]+=0xffffffe4u;
goto P_0c089e48;
P_0c089e48: /* original 2238, guest PC 0x0c089e48 */
if(!s->budget--) { s->failed_pc=0x0c089e48u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c089e4a;
P_0c089e4a: /* original 8901, guest PC 0x0c089e4a */
if(!s->budget--) { s->failed_pc=0x0c089e4au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089e50; }
goto P_0c089e4c;
P_0c089e4c: /* original a095, guest PC 0x0c089e4c */
if(!s->budget--) { s->failed_pc=0x0c089e4cu; return 0; }
goto P_0c089f7a;
P_0c089e4e: /* original 0009, guest PC 0x0c089e4e */
if(!s->budget--) { s->failed_pc=0x0c089e4eu; return 0; }
goto P_0c089e50;
P_0c089e50: /* original 6543, guest PC 0x0c089e50 */
if(!s->budget--) { s->failed_pc=0x0c089e50u; return 0; }
r[5]=r[4];
goto P_0c089e52;
P_0c089e52: /* original 8558, guest PC 0x0c089e52 */
if(!s->budget--) { s->failed_pc=0x0c089e52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+16,2);
goto P_0c089e54;
P_0c089e54: /* original 6e43, guest PC 0x0c089e54 */
if(!s->budget--) { s->failed_pc=0x0c089e54u; return 0; }
r[14]=r[4];
goto P_0c089e56;
P_0c089e56: /* original e402, guest PC 0x0c089e56 */
if(!s->budget--) { s->failed_pc=0x0c089e56u; return 0; }
r[4]=0x00000002u;
goto P_0c089e58;
P_0c089e58: /* original 6b03, guest PC 0x0c089e58 */
if(!s->budget--) { s->failed_pc=0x0c089e58u; return 0; }
r[11]=r[0];
goto P_0c089e5a;
P_0c089e5a: /* original 2b49, guest PC 0x0c089e5a */
if(!s->budget--) { s->failed_pc=0x0c089e5au; return 0; }
r[11]&=r[4];
goto P_0c089e5c;
P_0c089e5c: /* original 7b01, guest PC 0x0c089e5c */
if(!s->budget--) { s->failed_pc=0x0c089e5cu; return 0; }
r[11]+=0x00000001u;
goto P_0c089e5e;
P_0c089e5e: /* original e301, guest PC 0x0c089e5e */
if(!s->budget--) { s->failed_pc=0x0c089e5eu; return 0; }
r[3]=0x00000001u;
goto P_0c089e60;
P_0c089e60: /* original 60b3, guest PC 0x0c089e60 */
if(!s->budget--) { s->failed_pc=0x0c089e60u; return 0; }
r[0]=r[11];
goto P_0c089e62;
P_0c089e62: /* original ec3f, guest PC 0x0c089e62 */
if(!s->budget--) { s->failed_pc=0x0c089e62u; return 0; }
r[12]=0x0000003fu;
goto P_0c089e64;
P_0c089e64: /* original 8158, guest PC 0x0c089e64 */
if(!s->budget--) { s->failed_pc=0x0c089e64u; return 0; }
write(ram,r[5]+16,r[0],2);
goto P_0c089e66;
P_0c089e66: /* original d806, guest PC 0x0c089e66 */
if(!s->budget--) { s->failed_pc=0x0c089e66u; return 0; }
r[8]=read(ram,0x0c089e80u,4);
goto P_0c089e68;
P_0c089e68: /* original 2b39, guest PC 0x0c089e68 */
if(!s->budget--) { s->failed_pc=0x0c089e68u; return 0; }
r[11]&=r[3];
goto P_0c089e6a;
P_0c089e6a: /* original 7e14, guest PC 0x0c089e6a */
if(!s->budget--) { s->failed_pc=0x0c089e6au; return 0; }
r[14]+=0x00000014u;
goto P_0c089e6c;
P_0c089e6c: /* original a083, guest PC 0x0c089e6c */
if(!s->budget--) { s->failed_pc=0x0c089e6cu; return 0; }
r[10]=r[4];
goto P_0c089f76;
P_0c089e6e: /* original 6a43, guest PC 0x0c089e6e */
if(!s->budget--) { s->failed_pc=0x0c089e6eu; return 0; }
r[10]=r[4];
if(!vf3_matrix_family(0x0c089e70u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c089e70u; return 0; } return 1;
P_0c089e84: /* original e02a, guest PC 0x0c089e84 */
if(!s->budget--) { s->failed_pc=0x0c089e84u; return 0; }
r[0]=0x0000002au;
goto P_0c089e86;
P_0c089e86: /* original 04ed, guest PC 0x0c089e86 */
if(!s->budget--) { s->failed_pc=0x0c089e86u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c089e88;
P_0c089e88: /* original e028, guest PC 0x0c089e88 */
if(!s->budget--) { s->failed_pc=0x0c089e88u; return 0; }
r[0]=0x00000028u;
goto P_0c089e8a;
P_0c089e8a: /* original 03ed, guest PC 0x0c089e8a */
if(!s->budget--) { s->failed_pc=0x0c089e8au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c089e8c;
P_0c089e8c: /* original e02c, guest PC 0x0c089e8c */
if(!s->budget--) { s->failed_pc=0x0c089e8cu; return 0; }
r[0]=0x0000002cu;
goto P_0c089e8e;
P_0c089e8e: /* original 1f31, guest PC 0x0c089e8e */
if(!s->budget--) { s->failed_pc=0x0c089e8eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c089e90;
P_0c089e90: /* original 0ded, guest PC 0x0c089e90 */
if(!s->budget--) { s->failed_pc=0x0c089e90u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c089e92;
P_0c089e92: /* original e030, guest PC 0x0c089e92 */
if(!s->budget--) { s->failed_pc=0x0c089e92u; return 0; }
r[0]=0x00000030u;
goto P_0c089e94;
P_0c089e94: /* original 09ec, guest PC 0x0c089e94 */
if(!s->budget--) { s->failed_pc=0x0c089e94u; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c089e96;
P_0c089e96: /* original e018, guest PC 0x0c089e96 */
if(!s->budget--) { s->failed_pc=0x0c089e96u; return 0; }
r[0]=0x00000018u;
goto P_0c089e98;
P_0c089e98: /* original f3e6, guest PC 0x0c089e98 */
if(!s->budget--) { s->failed_pc=0x0c089e98u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c089e9a;
P_0c089e9a: /* original e00c, guest PC 0x0c089e9a */
if(!s->budget--) { s->failed_pc=0x0c089e9au; return 0; }
r[0]=0x0000000cu;
goto P_0c089e9c;
P_0c089e9c: /* original 3dbc, guest PC 0x0c089e9c */
if(!s->budget--) { s->failed_pc=0x0c089e9cu; return 0; }
r[13]+=r[11];
goto P_0c089e9e;
P_0c089e9e: /* original ff37, guest PC 0x0c089e9e */
if(!s->budget--) { s->failed_pc=0x0c089e9eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c089ea0;
P_0c089ea0: /* original e01c, guest PC 0x0c089ea0 */
if(!s->budget--) { s->failed_pc=0x0c089ea0u; return 0; }
r[0]=0x0000001cu;
goto P_0c089ea2;
P_0c089ea2: /* original f3e6, guest PC 0x0c089ea2 */
if(!s->budget--) { s->failed_pc=0x0c089ea2u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c089ea4;
P_0c089ea4: /* original e024, guest PC 0x0c089ea4 */
if(!s->budget--) { s->failed_pc=0x0c089ea4u; return 0; }
r[0]=0x00000024u;
goto P_0c089ea6;
P_0c089ea6: /* original ff3a, guest PC 0x0c089ea6 */
if(!s->budget--) { s->failed_pc=0x0c089ea6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c089ea8;
P_0c089ea8: /* original f4e6, guest PC 0x0c089ea8 */
if(!s->budget--) { s->failed_pc=0x0c089ea8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c089eaa;
P_0c089eaa: /* original e020, guest PC 0x0c089eaa */
if(!s->budget--) { s->failed_pc=0x0c089eaau; return 0; }
r[0]=0x00000020u;
goto P_0c089eac;
P_0c089eac: /* original f3e6, guest PC 0x0c089eac */
if(!s->budget--) { s->failed_pc=0x0c089eacu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c089eae;
P_0c089eae: /* original e008, guest PC 0x0c089eae */
if(!s->budget--) { s->failed_pc=0x0c089eaeu; return 0; }
r[0]=0x00000008u;
goto P_0c089eb0;
P_0c089eb0: /* original ff37, guest PC 0x0c089eb0 */
if(!s->budget--) { s->failed_pc=0x0c089eb0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c089eb2;
P_0c089eb2: /* original e00c, guest PC 0x0c089eb2 */
if(!s->budget--) { s->failed_pc=0x0c089eb2u; return 0; }
r[0]=0x0000000cu;
goto P_0c089eb4;
P_0c089eb4: /* original f3f8, guest PC 0x0c089eb4 */
if(!s->budget--) { s->failed_pc=0x0c089eb4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c089eb6;
P_0c089eb6: /* original f430, guest PC 0x0c089eb6 */
if(!s->budget--) { s->failed_pc=0x0c089eb6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c089eb8;
P_0c089eb8: /* original ff4a, guest PC 0x0c089eb8 */
if(!s->budget--) { s->failed_pc=0x0c089eb8u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c089eba;
P_0c089eba: /* original f3f6, guest PC 0x0c089eba */
if(!s->budget--) { s->failed_pc=0x0c089ebau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089ebc;
P_0c089ebc: /* original e00c, guest PC 0x0c089ebc */
if(!s->budget--) { s->failed_pc=0x0c089ebcu; return 0; }
r[0]=0x0000000cu;
goto P_0c089ebe;
P_0c089ebe: /* original f2e6, guest PC 0x0c089ebe */
if(!s->budget--) { s->failed_pc=0x0c089ebeu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c089ec0;
P_0c089ec0: /* original e018, guest PC 0x0c089ec0 */
if(!s->budget--) { s->failed_pc=0x0c089ec0u; return 0; }
r[0]=0x00000018u;
goto P_0c089ec2;
P_0c089ec2: /* original f230, guest PC 0x0c089ec2 */
if(!s->budget--) { s->failed_pc=0x0c089ec2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c089ec4;
P_0c089ec4: /* original ff27, guest PC 0x0c089ec4 */
if(!s->budget--) { s->failed_pc=0x0c089ec4u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c089ec6;
P_0c089ec6: /* original e010, guest PC 0x0c089ec6 */
if(!s->budget--) { s->failed_pc=0x0c089ec6u; return 0; }
r[0]=0x00000010u;
goto P_0c089ec8;
P_0c089ec8: /* original f2e6, guest PC 0x0c089ec8 */
if(!s->budget--) { s->failed_pc=0x0c089ec8u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c089eca;
P_0c089eca: /* original e014, guest PC 0x0c089eca */
if(!s->budget--) { s->failed_pc=0x0c089ecau; return 0; }
r[0]=0x00000014u;
goto P_0c089ecc;
P_0c089ecc: /* original f3f8, guest PC 0x0c089ecc */
if(!s->budget--) { s->failed_pc=0x0c089eccu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c089ece;
P_0c089ece: /* original 6593, guest PC 0x0c089ece */
if(!s->budget--) { s->failed_pc=0x0c089eceu; return 0; }
r[5]=r[9];
goto P_0c089ed0;
P_0c089ed0: /* original f230, guest PC 0x0c089ed0 */
if(!s->budget--) { s->failed_pc=0x0c089ed0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c089ed2;
P_0c089ed2: /* original ff27, guest PC 0x0c089ed2 */
if(!s->budget--) { s->failed_pc=0x0c089ed2u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c089ed4;
P_0c089ed4: /* original e008, guest PC 0x0c089ed4 */
if(!s->budget--) { s->failed_pc=0x0c089ed4u; return 0; }
r[0]=0x00000008u;
goto P_0c089ed6;
P_0c089ed6: /* original f3f6, guest PC 0x0c089ed6 */
if(!s->budget--) { s->failed_pc=0x0c089ed6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089ed8;
P_0c089ed8: /* original e014, guest PC 0x0c089ed8 */
if(!s->budget--) { s->failed_pc=0x0c089ed8u; return 0; }
r[0]=0x00000014u;
goto P_0c089eda;
P_0c089eda: /* original f2e6, guest PC 0x0c089eda */
if(!s->budget--) { s->failed_pc=0x0c089edau; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c089edc;
P_0c089edc: /* original e010, guest PC 0x0c089edc */
if(!s->budget--) { s->failed_pc=0x0c089edcu; return 0; }
r[0]=0x00000010u;
goto P_0c089ede;
P_0c089ede: /* original f230, guest PC 0x0c089ede */
if(!s->budget--) { s->failed_pc=0x0c089edeu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c089ee0;
P_0c089ee0: /* original ff27, guest PC 0x0c089ee0 */
if(!s->budget--) { s->failed_pc=0x0c089ee0u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c089ee2;
P_0c089ee2: /* original e028, guest PC 0x0c089ee2 */
if(!s->budget--) { s->failed_pc=0x0c089ee2u; return 0; }
r[0]=0x00000028u;
goto P_0c089ee4;
P_0c089ee4: /* original 53f1, guest PC 0x0c089ee4 */
if(!s->budget--) { s->failed_pc=0x0c089ee4u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c089ee6;
P_0c089ee6: /* original 334c, guest PC 0x0c089ee6 */
if(!s->budget--) { s->failed_pc=0x0c089ee6u; return 0; }
r[3]+=r[4];
goto P_0c089ee8;
P_0c089ee8: /* original 6233, guest PC 0x0c089ee8 */
if(!s->budget--) { s->failed_pc=0x0c089ee8u; return 0; }
r[2]=r[3];
goto P_0c089eea;
P_0c089eea: /* original 1f31, guest PC 0x0c089eea */
if(!s->budget--) { s->failed_pc=0x0c089eeau; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c089eec;
P_0c089eec: /* original 0e25, guest PC 0x0c089eec */
if(!s->budget--) { s->failed_pc=0x0c089eecu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c089eee;
P_0c089eee: /* original f4f8, guest PC 0x0c089eee */
if(!s->budget--) { s->failed_pc=0x0c089eeeu; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c089ef0;
P_0c089ef0: /* original be7b, guest PC 0x0c089ef0 */
if(!s->budget--) { s->failed_pc=0x0c089ef0u; return 0; }
target=code_base|0x0c089beau; r[16]=code_base|0x0c089ef4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c089ef4u) { target=s->pc; goto dispatch; }
goto P_0c089ef4;
P_0c089ef2: /* original 64e3, guest PC 0x0c089ef2 */
if(!s->budget--) { s->failed_pc=0x0c089ef2u; return 0; }
r[4]=r[14];
goto P_0c089ef4;
P_0c089ef4: /* original 62f3, guest PC 0x0c089ef4 */
if(!s->budget--) { s->failed_pc=0x0c089ef4u; return 0; }
r[2]=r[15];
goto P_0c089ef6;
P_0c089ef6: /* original 7210, guest PC 0x0c089ef6 */
if(!s->budget--) { s->failed_pc=0x0c089ef6u; return 0; }
r[2]+=0x00000010u;
goto P_0c089ef8;
P_0c089ef8: /* original 2f26, guest PC 0x0c089ef8 */
if(!s->budget--) { s->failed_pc=0x0c089ef8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089efa;
P_0c089efa: /* original 66f3, guest PC 0x0c089efa */
if(!s->budget--) { s->failed_pc=0x0c089efau; return 0; }
r[6]=r[15];
goto P_0c089efc;
P_0c089efc: /* original 65f3, guest PC 0x0c089efc */
if(!s->budget--) { s->failed_pc=0x0c089efcu; return 0; }
r[5]=r[15];
goto P_0c089efe;
P_0c089efe: /* original 67f3, guest PC 0x0c089efe */
if(!s->budget--) { s->failed_pc=0x0c089efeu; return 0; }
r[7]=r[15];
goto P_0c089f00;
P_0c089f00: /* original 7504, guest PC 0x0c089f00 */
if(!s->budget--) { s->failed_pc=0x0c089f00u; return 0; }
r[5]+=0x00000004u;
goto P_0c089f02;
P_0c089f02: /* original 7718, guest PC 0x0c089f02 */
if(!s->budget--) { s->failed_pc=0x0c089f02u; return 0; }
r[7]+=0x00000018u;
goto P_0c089f04;
P_0c089f04: /* original 761c, guest PC 0x0c089f04 */
if(!s->budget--) { s->failed_pc=0x0c089f04u; return 0; }
r[6]+=0x0000001cu;
goto P_0c089f06;
P_0c089f06: /* original be23, guest PC 0x0c089f06 */
if(!s->budget--) { s->failed_pc=0x0c089f06u; return 0; }
target=code_base|0x0c089b50u; r[16]=code_base|0x0c089f0au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c089f0au) { target=s->pc; goto dispatch; }
goto P_0c089f0a;
P_0c089f08: /* original 64e3, guest PC 0x0c089f08 */
if(!s->budget--) { s->failed_pc=0x0c089f08u; return 0; }
r[4]=r[14];
goto P_0c089f0a;
P_0c089f0a: /* original e018, guest PC 0x0c089f0a */
if(!s->budget--) { s->failed_pc=0x0c089f0au; return 0; }
r[0]=0x00000018u;
goto P_0c089f0c;
P_0c089f0c: /* original 3dc7, guest PC 0x0c089f0c */
if(!s->budget--) { s->failed_pc=0x0c089f0cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>(int32_t)r[12])!=0);
goto P_0c089f0e;
P_0c089f0e: /* original 7f04, guest PC 0x0c089f0e */
if(!s->budget--) { s->failed_pc=0x0c089f0eu; return 0; }
r[15]+=0x00000004u;
goto P_0c089f10;
P_0c089f10: /* original f3f6, guest PC 0x0c089f10 */
if(!s->budget--) { s->failed_pc=0x0c089f10u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089f12;
P_0c089f12: /* original e00c, guest PC 0x0c089f12 */
if(!s->budget--) { s->failed_pc=0x0c089f12u; return 0; }
r[0]=0x0000000cu;
goto P_0c089f14;
P_0c089f14: /* original fe37, guest PC 0x0c089f14 */
if(!s->budget--) { s->failed_pc=0x0c089f14u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089f16;
P_0c089f16: /* original e014, guest PC 0x0c089f16 */
if(!s->budget--) { s->failed_pc=0x0c089f16u; return 0; }
r[0]=0x00000014u;
goto P_0c089f18;
P_0c089f18: /* original f3f6, guest PC 0x0c089f18 */
if(!s->budget--) { s->failed_pc=0x0c089f18u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089f1a;
P_0c089f1a: /* original e010, guest PC 0x0c089f1a */
if(!s->budget--) { s->failed_pc=0x0c089f1au; return 0; }
r[0]=0x00000010u;
goto P_0c089f1c;
P_0c089f1c: /* original fe37, guest PC 0x0c089f1c */
if(!s->budget--) { s->failed_pc=0x0c089f1cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089f1e;
P_0c089f1e: /* original e010, guest PC 0x0c089f1e */
if(!s->budget--) { s->failed_pc=0x0c089f1eu; return 0; }
r[0]=0x00000010u;
goto P_0c089f20;
P_0c089f20: /* original f3f6, guest PC 0x0c089f20 */
if(!s->budget--) { s->failed_pc=0x0c089f20u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089f22;
P_0c089f22: /* original e014, guest PC 0x0c089f22 */
if(!s->budget--) { s->failed_pc=0x0c089f22u; return 0; }
r[0]=0x00000014u;
goto P_0c089f24;
P_0c089f24: /* original 8f1a, guest PC 0x0c089f24 */
if(!s->budget--) { s->failed_pc=0x0c089f24u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[14]+r[0]);
if(!cond) { goto P_0c089f5c; }
goto P_0c089f28;
P_0c089f26: /* original fe37, guest PC 0x0c089f26 */
if(!s->budget--) { s->failed_pc=0x0c089f26u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089f28;
P_0c089f28: /* original 62f3, guest PC 0x0c089f28 */
if(!s->budget--) { s->failed_pc=0x0c089f28u; return 0; }
r[2]=r[15];
goto P_0c089f2a;
P_0c089f2a: /* original 7204, guest PC 0x0c089f2a */
if(!s->budget--) { s->failed_pc=0x0c089f2au; return 0; }
r[2]+=0x00000004u;
goto P_0c089f2c;
P_0c089f2c: /* original 2f26, guest PC 0x0c089f2c */
if(!s->budget--) { s->failed_pc=0x0c089f2cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089f2e;
P_0c089f2e: /* original 66f3, guest PC 0x0c089f2e */
if(!s->budget--) { s->failed_pc=0x0c089f2eu; return 0; }
r[6]=r[15];
goto P_0c089f30;
P_0c089f30: /* original 65f3, guest PC 0x0c089f30 */
if(!s->budget--) { s->failed_pc=0x0c089f30u; return 0; }
r[5]=r[15];
goto P_0c089f32;
P_0c089f32: /* original 67f3, guest PC 0x0c089f32 */
if(!s->budget--) { s->failed_pc=0x0c089f32u; return 0; }
r[7]=r[15];
goto P_0c089f34;
P_0c089f34: /* original 7504, guest PC 0x0c089f34 */
if(!s->budget--) { s->failed_pc=0x0c089f34u; return 0; }
r[5]+=0x00000004u;
goto P_0c089f36;
P_0c089f36: /* original 7710, guest PC 0x0c089f36 */
if(!s->budget--) { s->failed_pc=0x0c089f36u; return 0; }
r[7]+=0x00000010u;
goto P_0c089f38;
P_0c089f38: /* original 760c, guest PC 0x0c089f38 */
if(!s->budget--) { s->failed_pc=0x0c089f38u; return 0; }
r[6]+=0x0000000cu;
goto P_0c089f3a;
P_0c089f3a: /* original bea4, guest PC 0x0c089f3a */
if(!s->budget--) { s->failed_pc=0x0c089f3au; return 0; }
target=code_base|0x0c089c86u; r[16]=code_base|0x0c089f3eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c089f3eu) { target=s->pc; goto dispatch; }
goto P_0c089f3e;
P_0c089f3c: /* original 64e3, guest PC 0x0c089f3c */
if(!s->budget--) { s->failed_pc=0x0c089f3cu; return 0; }
r[4]=r[14];
goto P_0c089f3e;
P_0c089f3e: /* original 7f04, guest PC 0x0c089f3e */
if(!s->budget--) { s->failed_pc=0x0c089f3eu; return 0; }
r[15]+=0x00000004u;
goto P_0c089f40;
P_0c089f40: /* original 52f1, guest PC 0x0c089f40 */
if(!s->budget--) { s->failed_pc=0x0c089f40u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c089f42;
P_0c089f42: /* original e02a, guest PC 0x0c089f42 */
if(!s->budget--) { s->failed_pc=0x0c089f42u; return 0; }
r[0]=0x0000002au;
goto P_0c089f44;
P_0c089f44: /* original 0e25, guest PC 0x0c089f44 */
if(!s->budget--) { s->failed_pc=0x0c089f44u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c089f46;
P_0c089f46: /* original e00c, guest PC 0x0c089f46 */
if(!s->budget--) { s->failed_pc=0x0c089f46u; return 0; }
r[0]=0x0000000cu;
goto P_0c089f48;
P_0c089f48: /* original f3f6, guest PC 0x0c089f48 */
if(!s->budget--) { s->failed_pc=0x0c089f48u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089f4a;
P_0c089f4a: /* original e018, guest PC 0x0c089f4a */
if(!s->budget--) { s->failed_pc=0x0c089f4au; return 0; }
r[0]=0x00000018u;
goto P_0c089f4c;
P_0c089f4c: /* original fe37, guest PC 0x0c089f4c */
if(!s->budget--) { s->failed_pc=0x0c089f4cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089f4e;
P_0c089f4e: /* original e024, guest PC 0x0c089f4e */
if(!s->budget--) { s->failed_pc=0x0c089f4eu; return 0; }
r[0]=0x00000024u;
goto P_0c089f50;
P_0c089f50: /* original f3f8, guest PC 0x0c089f50 */
if(!s->budget--) { s->failed_pc=0x0c089f50u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c089f52;
P_0c089f52: /* original fe37, guest PC 0x0c089f52 */
if(!s->budget--) { s->failed_pc=0x0c089f52u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089f54;
P_0c089f54: /* original e008, guest PC 0x0c089f54 */
if(!s->budget--) { s->failed_pc=0x0c089f54u; return 0; }
r[0]=0x00000008u;
goto P_0c089f56;
P_0c089f56: /* original f3f6, guest PC 0x0c089f56 */
if(!s->budget--) { s->failed_pc=0x0c089f56u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c089f58;
P_0c089f58: /* original e020, guest PC 0x0c089f58 */
if(!s->budget--) { s->failed_pc=0x0c089f58u; return 0; }
r[0]=0x00000020u;
goto P_0c089f5a;
P_0c089f5a: /* original fe37, guest PC 0x0c089f5a */
if(!s->budget--) { s->failed_pc=0x0c089f5au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089f5c;
P_0c089f5c: /* original e02c, guest PC 0x0c089f5c */
if(!s->budget--) { s->failed_pc=0x0c089f5cu; return 0; }
r[0]=0x0000002cu;
goto P_0c089f5e;
P_0c089f5e: /* original 2dc9, guest PC 0x0c089f5e */
if(!s->budget--) { s->failed_pc=0x0c089f5eu; return 0; }
r[13]&=r[12];
goto P_0c089f60;
P_0c089f60: /* original 0ed5, guest PC 0x0c089f60 */
if(!s->budget--) { s->failed_pc=0x0c089f60u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c089f62;
P_0c089f62: /* original 6093, guest PC 0x0c089f62 */
if(!s->budget--) { s->failed_pc=0x0c089f62u; return 0; }
r[0]=r[9];
goto P_0c089f64;
P_0c089f64: /* original 4008, guest PC 0x0c089f64 */
if(!s->budget--) { s->failed_pc=0x0c089f64u; return 0; }
r[0]<<=2;
goto P_0c089f66;
P_0c089f66: /* original 048e, guest PC 0x0c089f66 */
if(!s->budget--) { s->failed_pc=0x0c089f66u; return 0; }
r[4]=read(ram,r[8]+r[0],4);
goto P_0c089f68;
P_0c089f68: /* original 60d3, guest PC 0x0c089f68 */
if(!s->budget--) { s->failed_pc=0x0c089f68u; return 0; }
r[0]=r[13];
goto P_0c089f6a;
P_0c089f6a: /* original 4000, guest PC 0x0c089f6a */
if(!s->budget--) { s->failed_pc=0x0c089f6au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c089f6c;
P_0c089f6c: /* original 034d, guest PC 0x0c089f6c */
if(!s->budget--) { s->failed_pc=0x0c089f6cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c089f6e;
P_0c089f6e: /* original e02e, guest PC 0x0c089f6e */
if(!s->budget--) { s->failed_pc=0x0c089f6eu; return 0; }
r[0]=0x0000002eu;
goto P_0c089f70;
P_0c089f70: /* original 7aff, guest PC 0x0c089f70 */
if(!s->budget--) { s->failed_pc=0x0c089f70u; return 0; }
r[10]+=0xffffffffu;
goto P_0c089f72;
P_0c089f72: /* original 0e35, guest PC 0x0c089f72 */
if(!s->budget--) { s->failed_pc=0x0c089f72u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c089f74;
P_0c089f74: /* original 7e3c, guest PC 0x0c089f74 */
if(!s->budget--) { s->failed_pc=0x0c089f74u; return 0; }
r[14]+=0x0000003cu;
goto P_0c089f76;
P_0c089f76: /* original 2aa8, guest PC 0x0c089f76 */
if(!s->budget--) { s->failed_pc=0x0c089f76u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c089f78;
P_0c089f78: /* original 8b84, guest PC 0x0c089f78 */
if(!s->budget--) { s->failed_pc=0x0c089f78u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089e84; }
goto P_0c089f7a;
P_0c089f7a: /* original 7f1c, guest PC 0x0c089f7a */
if(!s->budget--) { s->failed_pc=0x0c089f7au; return 0; }
r[15]+=0x0000001cu;
goto P_0c089f7c;
P_0c089f7c: /* original 4f26, guest PC 0x0c089f7c */
if(!s->budget--) { s->failed_pc=0x0c089f7cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c089f7e;
P_0c089f7e: /* original 68f6, guest PC 0x0c089f7e */
if(!s->budget--) { s->failed_pc=0x0c089f7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c089f80;
P_0c089f80: /* original 69f6, guest PC 0x0c089f80 */
if(!s->budget--) { s->failed_pc=0x0c089f80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c089f82;
P_0c089f82: /* original 6af6, guest PC 0x0c089f82 */
if(!s->budget--) { s->failed_pc=0x0c089f82u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c089f84;
P_0c089f84: /* original 6bf6, guest PC 0x0c089f84 */
if(!s->budget--) { s->failed_pc=0x0c089f84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c089f86;
P_0c089f86: /* original 6cf6, guest PC 0x0c089f86 */
if(!s->budget--) { s->failed_pc=0x0c089f86u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c089f88;
P_0c089f88: /* original 6df6, guest PC 0x0c089f88 */
if(!s->budget--) { s->failed_pc=0x0c089f88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c089f8a;
P_0c089f8a: /* original 000b, guest PC 0x0c089f8a */
if(!s->budget--) { s->failed_pc=0x0c089f8au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c089f8c: /* original 6ef6, guest PC 0x0c089f8c */
if(!s->budget--) { s->failed_pc=0x0c089f8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c089f8eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
