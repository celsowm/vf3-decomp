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
int vf3_away_batch42_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c062c24u: goto P_0c062c24;
case 0x0c062c26u: goto P_0c062c26;
case 0x0c062c28u: goto P_0c062c28;
case 0x0c062c2au: goto P_0c062c2a;
case 0x0c062c2cu: goto P_0c062c2c;
case 0x0c062c2eu: goto P_0c062c2e;
case 0x0c062c30u: goto P_0c062c30;
case 0x0c062c32u: goto P_0c062c32;
case 0x0c062c34u: goto P_0c062c34;
case 0x0c062c36u: goto P_0c062c36;
case 0x0c062c38u: goto P_0c062c38;
case 0x0c062c3au: goto P_0c062c3a;
case 0x0c062c3cu: goto P_0c062c3c;
case 0x0c062c3eu: goto P_0c062c3e;
case 0x0c062c40u: goto P_0c062c40;
case 0x0c062c42u: goto P_0c062c42;
case 0x0c062c44u: goto P_0c062c44;
case 0x0c062c46u: goto P_0c062c46;
case 0x0c062c48u: goto P_0c062c48;
case 0x0c062c4au: goto P_0c062c4a;
case 0x0c062c4cu: goto P_0c062c4c;
case 0x0c068d54u: goto P_0c068d54;
case 0x0c068d56u: goto P_0c068d56;
case 0x0c068d58u: goto P_0c068d58;
case 0x0c068d5au: goto P_0c068d5a;
case 0x0c068d5cu: goto P_0c068d5c;
case 0x0c068d5eu: goto P_0c068d5e;
case 0x0c068d60u: goto P_0c068d60;
case 0x0c068d62u: goto P_0c068d62;
case 0x0c068d64u: goto P_0c068d64;
case 0x0c068d66u: goto P_0c068d66;
case 0x0c068d68u: goto P_0c068d68;
case 0x0c068d6au: goto P_0c068d6a;
case 0x0c068d6cu: goto P_0c068d6c;
case 0x0c068d6eu: goto P_0c068d6e;
case 0x0c068d70u: goto P_0c068d70;
case 0x0c068d72u: goto P_0c068d72;
case 0x0c068d74u: goto P_0c068d74;
case 0x0c068d76u: goto P_0c068d76;
case 0x0c068d78u: goto P_0c068d78;
case 0x0c068d7au: goto P_0c068d7a;
case 0x0c068d7cu: goto P_0c068d7c;
case 0x0c068d7eu: goto P_0c068d7e;
case 0x0c068d80u: goto P_0c068d80;
case 0x0c068d82u: goto P_0c068d82;
case 0x0c068d84u: goto P_0c068d84;
case 0x0c068d86u: goto P_0c068d86;
case 0x0c068d88u: goto P_0c068d88;
case 0x0c068d8au: goto P_0c068d8a;
case 0x0c068d8cu: goto P_0c068d8c;
case 0x0c068d8eu: goto P_0c068d8e;
case 0x0c068d90u: goto P_0c068d90;
case 0x0c068d92u: goto P_0c068d92;
case 0x0c068d94u: goto P_0c068d94;
case 0x0c068d96u: goto P_0c068d96;
case 0x0c068d98u: goto P_0c068d98;
case 0x0c068d9au: goto P_0c068d9a;
case 0x0c068d9cu: goto P_0c068d9c;
case 0x0c068d9eu: goto P_0c068d9e;
case 0x0c068da0u: goto P_0c068da0;
case 0x0c068da2u: goto P_0c068da2;
case 0x0c068da4u: goto P_0c068da4;
case 0x0c068da6u: goto P_0c068da6;
case 0x0c068da8u: goto P_0c068da8;
case 0x0c068daau: goto P_0c068daa;
case 0x0c068dacu: goto P_0c068dac;
case 0x0c068daeu: goto P_0c068dae;
case 0x0c068db0u: goto P_0c068db0;
case 0x0c068db2u: goto P_0c068db2;
case 0x0c068db4u: goto P_0c068db4;
case 0x0c068db6u: goto P_0c068db6;
case 0x0c068db8u: goto P_0c068db8;
case 0x0c068dbau: goto P_0c068dba;
case 0x0c068dbcu: goto P_0c068dbc;
case 0x0c068dbeu: goto P_0c068dbe;
case 0x0c068dc0u: goto P_0c068dc0;
case 0x0c068dc2u: goto P_0c068dc2;
case 0x0c068dc4u: goto P_0c068dc4;
case 0x0c068dc6u: goto P_0c068dc6;
case 0x0c068dc8u: goto P_0c068dc8;
case 0x0c068dcau: goto P_0c068dca;
case 0x0c068dccu: goto P_0c068dcc;
case 0x0c068dceu: goto P_0c068dce;
case 0x0c068dd0u: goto P_0c068dd0;
case 0x0c068dd2u: goto P_0c068dd2;
case 0x0c068dd4u: goto P_0c068dd4;
case 0x0c068dd6u: goto P_0c068dd6;
case 0x0c068dd8u: goto P_0c068dd8;
case 0x0c068ddau: goto P_0c068dda;
case 0x0c068ddcu: goto P_0c068ddc;
case 0x0c068ddeu: goto P_0c068dde;
case 0x0c068de0u: goto P_0c068de0;
case 0x0c068de2u: goto P_0c068de2;
case 0x0c068de4u: goto P_0c068de4;
case 0x0c068de6u: goto P_0c068de6;
case 0x0c068de8u: goto P_0c068de8;
case 0x0c068deau: goto P_0c068dea;
case 0x0c068decu: goto P_0c068dec;
case 0x0c068deeu: goto P_0c068dee;
case 0x0c068df0u: goto P_0c068df0;
case 0x0c068df2u: goto P_0c068df2;
case 0x0c068df4u: goto P_0c068df4;
case 0x0c068df6u: goto P_0c068df6;
case 0x0c068df8u: goto P_0c068df8;
case 0x0c068dfau: goto P_0c068dfa;
case 0x0c068dfcu: goto P_0c068dfc;
case 0x0c068dfeu: goto P_0c068dfe;
case 0x0c068e00u: goto P_0c068e00;
case 0x0c068e02u: goto P_0c068e02;
case 0x0c068e04u: goto P_0c068e04;
case 0x0c068e06u: goto P_0c068e06;
case 0x0c068e08u: goto P_0c068e08;
case 0x0c068e0au: goto P_0c068e0a;
case 0x0c068e0cu: goto P_0c068e0c;
case 0x0c068e0eu: goto P_0c068e0e;
case 0x0c068e10u: goto P_0c068e10;
case 0x0c068e12u: goto P_0c068e12;
case 0x0c068e14u: goto P_0c068e14;
case 0x0c068e16u: goto P_0c068e16;
case 0x0c068e18u: goto P_0c068e18;
case 0x0c068e1au: goto P_0c068e1a;
case 0x0c068e1cu: goto P_0c068e1c;
case 0x0c068e1eu: goto P_0c068e1e;
case 0x0c068e20u: goto P_0c068e20;
case 0x0c068e22u: goto P_0c068e22;
case 0x0c068e24u: goto P_0c068e24;
case 0x0c068e26u: goto P_0c068e26;
case 0x0c068e28u: goto P_0c068e28;
case 0x0c068e2au: goto P_0c068e2a;
case 0x0c068e2cu: goto P_0c068e2c;
case 0x0c068e2eu: goto P_0c068e2e;
case 0x0c068e30u: goto P_0c068e30;
case 0x0c068e32u: goto P_0c068e32;
case 0x0c068e34u: goto P_0c068e34;
case 0x0c068e36u: goto P_0c068e36;
case 0x0c068e38u: goto P_0c068e38;
case 0x0c068e3au: goto P_0c068e3a;
case 0x0c068e3cu: goto P_0c068e3c;
case 0x0c068e3eu: goto P_0c068e3e;
case 0x0c068e40u: goto P_0c068e40;
case 0x0c068e42u: goto P_0c068e42;
case 0x0c068e44u: goto P_0c068e44;
case 0x0c068e46u: goto P_0c068e46;
case 0x0c068e48u: goto P_0c068e48;
case 0x0c068e4au: goto P_0c068e4a;
case 0x0c068e4cu: goto P_0c068e4c;
case 0x0c068e4eu: goto P_0c068e4e;
case 0x0c068e6cu: goto P_0c068e6c;
case 0x0c068e6eu: goto P_0c068e6e;
case 0x0c068e70u: goto P_0c068e70;
case 0x0c068e72u: goto P_0c068e72;
case 0x0c068e74u: goto P_0c068e74;
case 0x0c068e76u: goto P_0c068e76;
case 0x0c068e78u: goto P_0c068e78;
case 0x0c068e7au: goto P_0c068e7a;
case 0x0c068e7cu: goto P_0c068e7c;
case 0x0c068e7eu: goto P_0c068e7e;
case 0x0c068e80u: goto P_0c068e80;
case 0x0c068e82u: goto P_0c068e82;
case 0x0c068e84u: goto P_0c068e84;
case 0x0c068e86u: goto P_0c068e86;
case 0x0c068e88u: goto P_0c068e88;
case 0x0c068e8au: goto P_0c068e8a;
case 0x0c068e8cu: goto P_0c068e8c;
case 0x0c068e8eu: goto P_0c068e8e;
case 0x0c068e90u: goto P_0c068e90;
case 0x0c068e92u: goto P_0c068e92;
case 0x0c068e94u: goto P_0c068e94;
case 0x0c068e96u: goto P_0c068e96;
case 0x0c068e98u: goto P_0c068e98;
case 0x0c068e9au: goto P_0c068e9a;
case 0x0c068e9cu: goto P_0c068e9c;
case 0x0c068e9eu: goto P_0c068e9e;
case 0x0c068ea0u: goto P_0c068ea0;
case 0x0c068ea2u: goto P_0c068ea2;
case 0x0c068ea4u: goto P_0c068ea4;
case 0x0c068ea6u: goto P_0c068ea6;
case 0x0c068ea8u: goto P_0c068ea8;
case 0x0c068eaau: goto P_0c068eaa;
case 0x0c068eacu: goto P_0c068eac;
case 0x0c068eaeu: goto P_0c068eae;
case 0x0c068eb0u: goto P_0c068eb0;
case 0x0c068eb2u: goto P_0c068eb2;
case 0x0c068eb4u: goto P_0c068eb4;
case 0x0c068eb6u: goto P_0c068eb6;
case 0x0c068eb8u: goto P_0c068eb8;
case 0x0c068ebau: goto P_0c068eba;
case 0x0c068ebcu: goto P_0c068ebc;
case 0x0c068ebeu: goto P_0c068ebe;
case 0x0c068ec0u: goto P_0c068ec0;
case 0x0c068ec2u: goto P_0c068ec2;
case 0x0c068ec4u: goto P_0c068ec4;
case 0x0c068ec6u: goto P_0c068ec6;
case 0x0c068ec8u: goto P_0c068ec8;
case 0x0c068ecau: goto P_0c068eca;
case 0x0c068eccu: goto P_0c068ecc;
case 0x0c068eceu: goto P_0c068ece;
case 0x0c068ed0u: goto P_0c068ed0;
case 0x0c068ed2u: goto P_0c068ed2;
case 0x0c068ed4u: goto P_0c068ed4;
case 0x0c068ed6u: goto P_0c068ed6;
case 0x0c068ed8u: goto P_0c068ed8;
case 0x0c068edau: goto P_0c068eda;
case 0x0c068edcu: goto P_0c068edc;
case 0x0c068edeu: goto P_0c068ede;
case 0x0c068ee0u: goto P_0c068ee0;
case 0x0c068ee2u: goto P_0c068ee2;
case 0x0c068ee4u: goto P_0c068ee4;
case 0x0c068ee6u: goto P_0c068ee6;
case 0x0c068ee8u: goto P_0c068ee8;
case 0x0c068eeau: goto P_0c068eea;
case 0x0c068eecu: goto P_0c068eec;
case 0x0c068eeeu: goto P_0c068eee;
case 0x0c068ef0u: goto P_0c068ef0;
case 0x0c068ef2u: goto P_0c068ef2;
case 0x0c068ef4u: goto P_0c068ef4;
case 0x0c068ef6u: goto P_0c068ef6;
case 0x0c068ef8u: goto P_0c068ef8;
case 0x0c068efau: goto P_0c068efa;
case 0x0c068efcu: goto P_0c068efc;
case 0x0c068efeu: goto P_0c068efe;
case 0x0c068f00u: goto P_0c068f00;
case 0x0c068f02u: goto P_0c068f02;
case 0x0c068f04u: goto P_0c068f04;
case 0x0c068f06u: goto P_0c068f06;
case 0x0c068f08u: goto P_0c068f08;
case 0x0c068f0au: goto P_0c068f0a;
case 0x0c068f0cu: goto P_0c068f0c;
case 0x0c068f0eu: goto P_0c068f0e;
case 0x0c068f10u: goto P_0c068f10;
case 0x0c068f12u: goto P_0c068f12;
case 0x0c068f14u: goto P_0c068f14;
case 0x0c068f16u: goto P_0c068f16;
case 0x0c068f18u: goto P_0c068f18;
case 0x0c068f1au: goto P_0c068f1a;
case 0x0c068f1cu: goto P_0c068f1c;
case 0x0c068f1eu: goto P_0c068f1e;
case 0x0c068f20u: goto P_0c068f20;
case 0x0c068f22u: goto P_0c068f22;
case 0x0c068f24u: goto P_0c068f24;
case 0x0c068f26u: goto P_0c068f26;
case 0x0c068f28u: goto P_0c068f28;
case 0x0c068f2au: goto P_0c068f2a;
case 0x0c068f2cu: goto P_0c068f2c;
case 0x0c068f2eu: goto P_0c068f2e;
case 0x0c068f30u: goto P_0c068f30;
case 0x0c068f32u: goto P_0c068f32;
case 0x0c068f34u: goto P_0c068f34;
case 0x0c068f36u: goto P_0c068f36;
case 0x0c068f38u: goto P_0c068f38;
case 0x0c068f3au: goto P_0c068f3a;
case 0x0c068f3cu: goto P_0c068f3c;
case 0x0c068f3eu: goto P_0c068f3e;
case 0x0c068f40u: goto P_0c068f40;
case 0x0c068f42u: goto P_0c068f42;
case 0x0c068f44u: goto P_0c068f44;
case 0x0c068f46u: goto P_0c068f46;
case 0x0c068f48u: goto P_0c068f48;
case 0x0c068f4au: goto P_0c068f4a;
case 0x0c068f4cu: goto P_0c068f4c;
case 0x0c068f4eu: goto P_0c068f4e;
case 0x0c068f50u: goto P_0c068f50;
case 0x0c068f52u: goto P_0c068f52;
case 0x0c068f54u: goto P_0c068f54;
case 0x0c068f56u: goto P_0c068f56;
case 0x0c068f58u: goto P_0c068f58;
case 0x0c068f5au: goto P_0c068f5a;
case 0x0c068f5cu: goto P_0c068f5c;
case 0x0c068f5eu: goto P_0c068f5e;
case 0x0c068f60u: goto P_0c068f60;
case 0x0c068f62u: goto P_0c068f62;
case 0x0c068f64u: goto P_0c068f64;
case 0x0c068f66u: goto P_0c068f66;
case 0x0c068f68u: goto P_0c068f68;
case 0x0c068f6au: goto P_0c068f6a;
case 0x0c068f6cu: goto P_0c068f6c;
case 0x0c068f6eu: goto P_0c068f6e;
case 0x0c068f70u: goto P_0c068f70;
case 0x0c068f72u: goto P_0c068f72;
case 0x0c068f74u: goto P_0c068f74;
case 0x0c068f76u: goto P_0c068f76;
case 0x0c068f78u: goto P_0c068f78;
case 0x0c068f7au: goto P_0c068f7a;
case 0x0c068f7cu: goto P_0c068f7c;
case 0x0c068f7eu: goto P_0c068f7e;
case 0x0c068f80u: goto P_0c068f80;
case 0x0c068f82u: goto P_0c068f82;
case 0x0c068f84u: goto P_0c068f84;
case 0x0c068f86u: goto P_0c068f86;
case 0x0c068f88u: goto P_0c068f88;
case 0x0c068f8au: goto P_0c068f8a;
case 0x0c068f8cu: goto P_0c068f8c;
case 0x0c068f8eu: goto P_0c068f8e;
case 0x0c068f90u: goto P_0c068f90;
default: return vf3_matrix_family(target,s,ram);
}
P_0c062c24: /* original 2fd6, guest PC 0x0c062c24 */
if(!s->budget--) { s->failed_pc=0x0c062c24u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062c26;
P_0c062c26: /* original e700, guest PC 0x0c062c26 */
if(!s->budget--) { s->failed_pc=0x0c062c26u; return 0; }
r[7]=0x00000000u;
goto P_0c062c28;
P_0c062c28: /* original d51b, guest PC 0x0c062c28 */
if(!s->budget--) { s->failed_pc=0x0c062c28u; return 0; }
r[5]=read(ram,0x0c062c98u,4);
goto P_0c062c2a;
P_0c062c2a: /* original 7ffc, guest PC 0x0c062c2a */
if(!s->budget--) { s->failed_pc=0x0c062c2au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c062c2c;
P_0c062c2c: /* original dd1b, guest PC 0x0c062c2c */
if(!s->budget--) { s->failed_pc=0x0c062c2cu; return 0; }
r[13]=read(ram,0x0c062c9cu,4);
goto P_0c062c2e;
P_0c062c2e: /* original 6653, guest PC 0x0c062c2e */
if(!s->budget--) { s->failed_pc=0x0c062c2eu; return 0; }
r[6]=r[5];
goto P_0c062c30;
P_0c062c30: /* original 912f, guest PC 0x0c062c30 */
if(!s->budget--) { s->failed_pc=0x0c062c30u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062c92u,2);
goto P_0c062c32;
P_0c062c32: /* original 2f52, guest PC 0x0c062c32 */
if(!s->budget--) { s->failed_pc=0x0c062c32u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c062c34;
P_0c062c34: /* original 3640, guest PC 0x0c062c34 */
if(!s->budget--) { s->failed_pc=0x0c062c34u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[4])!=0);
goto P_0c062c36;
P_0c062c36: /* original 8f03, guest PC 0x0c062c36 */
if(!s->budget--) { s->failed_pc=0x0c062c36u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(!cond) { goto P_0c062c40; }
goto P_0c062c3a;
P_0c062c38: /* original 7701, guest PC 0x0c062c38 */
if(!s->budget--) { s->failed_pc=0x0c062c38u; return 0; }
r[7]+=0x00000001u;
goto P_0c062c3a;
P_0c062c3a: /* original 6251, guest PC 0x0c062c3a */
if(!s->budget--) { s->failed_pc=0x0c062c3au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c062c3c;
P_0c062c3c: /* original 22d9, guest PC 0x0c062c3c */
if(!s->budget--) { s->failed_pc=0x0c062c3cu; return 0; }
r[2]&=r[13];
goto P_0c062c3e;
P_0c062c3e: /* original 2521, guest PC 0x0c062c3e */
if(!s->budget--) { s->failed_pc=0x0c062c3eu; return 0; }
write(ram,r[5],r[2],2);
goto P_0c062c40;
P_0c062c40: /* original 754c, guest PC 0x0c062c40 */
if(!s->budget--) { s->failed_pc=0x0c062c40u; return 0; }
r[5]+=0x0000004cu;
goto P_0c062c42;
P_0c062c42: /* original 3713, guest PC 0x0c062c42 */
if(!s->budget--) { s->failed_pc=0x0c062c42u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[1])!=0);
goto P_0c062c44;
P_0c062c44: /* original 8ff6, guest PC 0x0c062c44 */
if(!s->budget--) { s->failed_pc=0x0c062c44u; return 0; }
cond=r[17]&1u;
r[6]+=0x0000004cu;
if(!cond) { goto P_0c062c34; }
goto P_0c062c48;
P_0c062c46: /* original 764c, guest PC 0x0c062c46 */
if(!s->budget--) { s->failed_pc=0x0c062c46u; return 0; }
r[6]+=0x0000004cu;
goto P_0c062c48;
P_0c062c48: /* original 7f04, guest PC 0x0c062c48 */
if(!s->budget--) { s->failed_pc=0x0c062c48u; return 0; }
r[15]+=0x00000004u;
goto P_0c062c4a;
P_0c062c4a: /* original 000b, guest PC 0x0c062c4a */
if(!s->budget--) { s->failed_pc=0x0c062c4au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c062c4c: /* original 6df6, guest PC 0x0c062c4c */
if(!s->budget--) { s->failed_pc=0x0c062c4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
if(!vf3_matrix_family(0x0c062c4eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062c4eu; return 0; } return 1;
P_0c068d54: /* original 6043, guest PC 0x0c068d54 */
if(!s->budget--) { s->failed_pc=0x0c068d54u; return 0; }
r[0]=r[4];
goto P_0c068d56;
P_0c068d56: /* original 8802, guest PC 0x0c068d56 */
if(!s->budget--) { s->failed_pc=0x0c068d56u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c068d58;
P_0c068d58: /* original 8902, guest PC 0x0c068d58 */
if(!s->budget--) { s->failed_pc=0x0c068d58u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068d60; }
goto P_0c068d5a;
P_0c068d5a: /* original 6043, guest PC 0x0c068d5a */
if(!s->budget--) { s->failed_pc=0x0c068d5au; return 0; }
r[0]=r[4];
goto P_0c068d5c;
P_0c068d5c: /* original 8807, guest PC 0x0c068d5c */
if(!s->budget--) { s->failed_pc=0x0c068d5cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c068d5e;
P_0c068d5e: /* original 8b08, guest PC 0x0c068d5e */
if(!s->budget--) { s->failed_pc=0x0c068d5eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068d72; }
goto P_0c068d60;
P_0c068d60: /* original c73b, guest PC 0x0c068d60 */
if(!s->budget--) { s->failed_pc=0x0c068d60u; return 0; }
r[0]=code_base|0x00068e50u;
goto P_0c068d62;
P_0c068d62: /* original f358, guest PC 0x0c068d62 */
if(!s->budget--) { s->failed_pc=0x0c068d62u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c068d64;
P_0c068d64: /* original f408, guest PC 0x0c068d64 */
if(!s->budget--) { s->failed_pc=0x0c068d64u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c068d66;
P_0c068d66: /* original f342, guest PC 0x0c068d66 */
if(!s->budget--) { s->failed_pc=0x0c068d66u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c068d68;
P_0c068d68: /* original f53a, guest PC 0x0c068d68 */
if(!s->budget--) { s->failed_pc=0x0c068d68u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c068d6a;
P_0c068d6a: /* original f268, guest PC 0x0c068d6a */
if(!s->budget--) { s->failed_pc=0x0c068d6au; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c068d6c;
P_0c068d6c: /* original f242, guest PC 0x0c068d6c */
if(!s->budget--) { s->failed_pc=0x0c068d6cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c068d6e;
P_0c068d6e: /* original 000b, guest PC 0x0c068d6e */
if(!s->budget--) { s->failed_pc=0x0c068d6eu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,2,r[6]);
s->pc=target; return ram->oob==0;
P_0c068d70: /* original f62a, guest PC 0x0c068d70 */
if(!s->budget--) { s->failed_pc=0x0c068d70u; return 0; }
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c068d72;
P_0c068d72: /* original 880d, guest PC 0x0c068d72 */
if(!s->budget--) { s->failed_pc=0x0c068d72u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c068d74;
P_0c068d74: /* original 8b34, guest PC 0x0c068d74 */
if(!s->budget--) { s->failed_pc=0x0c068d74u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068de0; }
goto P_0c068d76;
P_0c068d76: /* original c737, guest PC 0x0c068d76 */
if(!s->budget--) { s->failed_pc=0x0c068d76u; return 0; }
r[0]=code_base|0x00068e54u;
goto P_0c068d78;
P_0c068d78: /* original f458, guest PC 0x0c068d78 */
if(!s->budget--) { s->failed_pc=0x0c068d78u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
goto P_0c068d7a;
P_0c068d7a: /* original f508, guest PC 0x0c068d7a */
if(!s->budget--) { s->failed_pc=0x0c068d7au; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c068d7c;
P_0c068d7c: /* original f452, guest PC 0x0c068d7c */
if(!s->budget--) { s->failed_pc=0x0c068d7cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c068d7e;
P_0c068d7e: /* original f35c, guest PC 0x0c068d7e */
if(!s->budget--) { s->failed_pc=0x0c068d7eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c068d80;
P_0c068d80: /* original f568, guest PC 0x0c068d80 */
if(!s->budget--) { s->failed_pc=0x0c068d80u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c068d82;
P_0c068d82: /* original f532, guest PC 0x0c068d82 */
if(!s->budget--) { s->failed_pc=0x0c068d82u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c068d84;
P_0c068d84: /* original f43d, guest PC 0x0c068d84 */
if(!s->budget--) { s->failed_pc=0x0c068d84u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c068d86;
P_0c068d86: /* original 045a, guest PC 0x0c068d86 */
if(!s->budget--) { s->failed_pc=0x0c068d86u; return 0; }
r[4]=r[53];
goto P_0c068d88;
P_0c068d88: /* original f53d, guest PC 0x0c068d88 */
if(!s->budget--) { s->failed_pc=0x0c068d88u; return 0; }
r[53]=truncate_float(fr[5]);
goto P_0c068d8a;
P_0c068d8a: /* original 2448, guest PC 0x0c068d8a */
if(!s->budget--) { s->failed_pc=0x0c068d8au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c068d8c;
P_0c068d8c: /* original 8d13, guest PC 0x0c068d8c */
if(!s->budget--) { s->failed_pc=0x0c068d8cu; return 0; }
cond=r[17]&1u;
r[7]=r[53];
if(cond) { goto P_0c068db6; }
goto P_0c068d90;
P_0c068d8e: /* original 075a, guest PC 0x0c068d8e */
if(!s->budget--) { s->failed_pc=0x0c068d8eu; return 0; }
r[7]=r[53];
goto P_0c068d90;
P_0c068d90: /* original e201, guest PC 0x0c068d90 */
if(!s->budget--) { s->failed_pc=0x0c068d90u; return 0; }
r[2]=0x00000001u;
goto P_0c068d92;
P_0c068d92: /* original 2248, guest PC 0x0c068d92 */
if(!s->budget--) { s->failed_pc=0x0c068d92u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c068d94;
P_0c068d94: /* original 8905, guest PC 0x0c068d94 */
if(!s->budget--) { s->failed_pc=0x0c068d94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068da2; }
goto P_0c068d96;
P_0c068d96: /* original d130, guest PC 0x0c068d96 */
if(!s->budget--) { s->failed_pc=0x0c068d96u; return 0; }
r[1]=read(ram,0x0c068e58u,4);
goto P_0c068d98;
P_0c068d98: /* original 2148, guest PC 0x0c068d98 */
if(!s->budget--) { s->failed_pc=0x0c068d98u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c068d9a;
P_0c068d9a: /* original 8901, guest PC 0x0c068d9a */
if(!s->budget--) { s->failed_pc=0x0c068d9au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068da0; }
goto P_0c068d9c;
P_0c068d9c: /* original a001, guest PC 0x0c068d9c */
if(!s->budget--) { s->failed_pc=0x0c068d9cu; return 0; }
r[4]+=0xffffffffu;
goto P_0c068da2;
P_0c068d9e: /* original 74ff, guest PC 0x0c068d9e */
if(!s->budget--) { s->failed_pc=0x0c068d9eu; return 0; }
r[4]+=0xffffffffu;
goto P_0c068da0;
P_0c068da0: /* original 7401, guest PC 0x0c068da0 */
if(!s->budget--) { s->failed_pc=0x0c068da0u; return 0; }
r[4]+=0x00000001u;
goto P_0c068da2;
P_0c068da2: /* original 6343, guest PC 0x0c068da2 */
if(!s->budget--) { s->failed_pc=0x0c068da2u; return 0; }
r[3]=r[4];
goto P_0c068da4;
P_0c068da4: /* original 4408, guest PC 0x0c068da4 */
if(!s->budget--) { s->failed_pc=0x0c068da4u; return 0; }
r[4]<<=2;
goto P_0c068da6;
P_0c068da6: /* original 343c, guest PC 0x0c068da6 */
if(!s->budget--) { s->failed_pc=0x0c068da6u; return 0; }
r[4]+=r[3];
goto P_0c068da8;
P_0c068da8: /* original f258, guest PC 0x0c068da8 */
if(!s->budget--) { s->failed_pc=0x0c068da8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c068daa;
P_0c068daa: /* original 4400, guest PC 0x0c068daa */
if(!s->budget--) { s->failed_pc=0x0c068daau; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c068dac;
P_0c068dac: /* original 445a, guest PC 0x0c068dac */
if(!s->budget--) { s->failed_pc=0x0c068dacu; return 0; }
r[53]=r[4];
goto P_0c068dae;
P_0c068dae: /* original f32d, guest PC 0x0c068dae */
if(!s->budget--) { s->failed_pc=0x0c068daeu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c068db0;
P_0c068db0: /* original f43c, guest PC 0x0c068db0 */
if(!s->budget--) { s->failed_pc=0x0c068db0u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c068db2;
P_0c068db2: /* original f241, guest PC 0x0c068db2 */
if(!s->budget--) { s->failed_pc=0x0c068db2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'-');
goto P_0c068db4;
P_0c068db4: /* original f52a, guest PC 0x0c068db4 */
if(!s->budget--) { s->failed_pc=0x0c068db4u; return 0; }
vf3_matrix_store(s,ram,2,r[5]);
goto P_0c068db6;
P_0c068db6: /* original 2778, guest PC 0x0c068db6 */
if(!s->budget--) { s->failed_pc=0x0c068db6u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c068db8;
P_0c068db8: /* original 8912, guest PC 0x0c068db8 */
if(!s->budget--) { s->failed_pc=0x0c068db8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068de0; }
goto P_0c068dba;
P_0c068dba: /* original e201, guest PC 0x0c068dba */
if(!s->budget--) { s->failed_pc=0x0c068dbau; return 0; }
r[2]=0x00000001u;
goto P_0c068dbc;
P_0c068dbc: /* original 2278, guest PC 0x0c068dbc */
if(!s->budget--) { s->failed_pc=0x0c068dbcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[7])==0)!=0);
goto P_0c068dbe;
P_0c068dbe: /* original 8905, guest PC 0x0c068dbe */
if(!s->budget--) { s->failed_pc=0x0c068dbeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068dcc; }
goto P_0c068dc0;
P_0c068dc0: /* original d125, guest PC 0x0c068dc0 */
if(!s->budget--) { s->failed_pc=0x0c068dc0u; return 0; }
r[1]=read(ram,0x0c068e58u,4);
goto P_0c068dc2;
P_0c068dc2: /* original 2178, guest PC 0x0c068dc2 */
if(!s->budget--) { s->failed_pc=0x0c068dc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[7])==0)!=0);
goto P_0c068dc4;
P_0c068dc4: /* original 8901, guest PC 0x0c068dc4 */
if(!s->budget--) { s->failed_pc=0x0c068dc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068dca; }
goto P_0c068dc6;
P_0c068dc6: /* original a001, guest PC 0x0c068dc6 */
if(!s->budget--) { s->failed_pc=0x0c068dc6u; return 0; }
r[7]+=0xffffffffu;
goto P_0c068dcc;
P_0c068dc8: /* original 77ff, guest PC 0x0c068dc8 */
if(!s->budget--) { s->failed_pc=0x0c068dc8u; return 0; }
r[7]+=0xffffffffu;
goto P_0c068dca;
P_0c068dca: /* original 7701, guest PC 0x0c068dca */
if(!s->budget--) { s->failed_pc=0x0c068dcau; return 0; }
r[7]+=0x00000001u;
goto P_0c068dcc;
P_0c068dcc: /* original 6373, guest PC 0x0c068dcc */
if(!s->budget--) { s->failed_pc=0x0c068dccu; return 0; }
r[3]=r[7];
goto P_0c068dce;
P_0c068dce: /* original 4708, guest PC 0x0c068dce */
if(!s->budget--) { s->failed_pc=0x0c068dceu; return 0; }
r[7]<<=2;
goto P_0c068dd0;
P_0c068dd0: /* original 373c, guest PC 0x0c068dd0 */
if(!s->budget--) { s->failed_pc=0x0c068dd0u; return 0; }
r[7]+=r[3];
goto P_0c068dd2;
P_0c068dd2: /* original f268, guest PC 0x0c068dd2 */
if(!s->budget--) { s->failed_pc=0x0c068dd2u; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c068dd4;
P_0c068dd4: /* original 4700, guest PC 0x0c068dd4 */
if(!s->budget--) { s->failed_pc=0x0c068dd4u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c068dd6;
P_0c068dd6: /* original 475a, guest PC 0x0c068dd6 */
if(!s->budget--) { s->failed_pc=0x0c068dd6u; return 0; }
r[53]=r[7];
goto P_0c068dd8;
P_0c068dd8: /* original f32d, guest PC 0x0c068dd8 */
if(!s->budget--) { s->failed_pc=0x0c068dd8u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c068dda;
P_0c068dda: /* original f43c, guest PC 0x0c068dda */
if(!s->budget--) { s->failed_pc=0x0c068ddau; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c068ddc;
P_0c068ddc: /* original f241, guest PC 0x0c068ddc */
if(!s->budget--) { s->failed_pc=0x0c068ddcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'-');
goto P_0c068dde;
P_0c068dde: /* original f62a, guest PC 0x0c068dde */
if(!s->budget--) { s->failed_pc=0x0c068ddeu; return 0; }
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c068de0;
P_0c068de0: /* original 000b, guest PC 0x0c068de0 */
if(!s->budget--) { s->failed_pc=0x0c068de0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c068de2: /* original 0009, guest PC 0x0c068de2 */
if(!s->budget--) { s->failed_pc=0x0c068de2u; return 0; }
goto P_0c068de4;
P_0c068de4: /* original c71d, guest PC 0x0c068de4 */
if(!s->budget--) { s->failed_pc=0x0c068de4u; return 0; }
r[0]=code_base|0x00068e5cu;
goto P_0c068de6;
P_0c068de6: /* original f45d, guest PC 0x0c068de6 */
if(!s->budget--) { s->failed_pc=0x0c068de6u; return 0; }
fr[4]&=0x7fffffffu;
goto P_0c068de8;
P_0c068de8: /* original f608, guest PC 0x0c068de8 */
if(!s->budget--) { s->failed_pc=0x0c068de8u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c068dea;
P_0c068dea: /* original f55d, guest PC 0x0c068dea */
if(!s->budget--) { s->failed_pc=0x0c068deau; return 0; }
fr[5]&=0x7fffffffu;
goto P_0c068dec;
P_0c068dec: /* original f465, guest PC 0x0c068dec */
if(!s->budget--) { s->failed_pc=0x0c068decu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c068dee;
P_0c068dee: /* original 8d02, guest PC 0x0c068dee */
if(!s->budget--) { s->failed_pc=0x0c068deeu; return 0; }
cond=r[17]&1u;
fr[7]=0;
if(cond) { goto P_0c068df6; }
goto P_0c068df2;
P_0c068df0: /* original f78d, guest PC 0x0c068df0 */
if(!s->budget--) { s->failed_pc=0x0c068df0u; return 0; }
fr[7]=0;
goto P_0c068df2;
P_0c068df2: /* original f565, guest PC 0x0c068df2 */
if(!s->budget--) { s->failed_pc=0x0c068df2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[6]))!=0);
goto P_0c068df4;
P_0c068df4: /* original 8b02, guest PC 0x0c068df4 */
if(!s->budget--) { s->failed_pc=0x0c068df4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068dfc; }
goto P_0c068df6;
P_0c068df6: /* original c71a, guest PC 0x0c068df6 */
if(!s->budget--) { s->failed_pc=0x0c068df6u; return 0; }
r[0]=code_base|0x00068e60u;
goto P_0c068df8;
P_0c068df8: /* original a001, guest PC 0x0c068df8 */
if(!s->budget--) { s->failed_pc=0x0c068df8u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c068dfe;
P_0c068dfa: /* original f408, guest PC 0x0c068dfa */
if(!s->budget--) { s->failed_pc=0x0c068dfau; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c068dfc;
P_0c068dfc: /* original f47c, guest PC 0x0c068dfc */
if(!s->budget--) { s->failed_pc=0x0c068dfcu; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c068dfe;
P_0c068dfe: /* original e008, guest PC 0x0c068dfe */
if(!s->budget--) { s->failed_pc=0x0c068dfeu; return 0; }
r[0]=0x00000008u;
goto P_0c068e00;
P_0c068e00: /* original f477, guest PC 0x0c068e00 */
if(!s->budget--) { s->failed_pc=0x0c068e00u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c068e02;
P_0c068e02: /* original e004, guest PC 0x0c068e02 */
if(!s->budget--) { s->failed_pc=0x0c068e02u; return 0; }
r[0]=0x00000004u;
goto P_0c068e04;
P_0c068e04: /* original f47a, guest PC 0x0c068e04 */
if(!s->budget--) { s->failed_pc=0x0c068e04u; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c068e06;
P_0c068e06: /* original f39d, guest PC 0x0c068e06 */
if(!s->budget--) { s->failed_pc=0x0c068e06u; return 0; }
fr[3]=0x3f800000u;
goto P_0c068e08;
P_0c068e08: /* original f437, guest PC 0x0c068e08 */
if(!s->budget--) { s->failed_pc=0x0c068e08u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c068e0a;
P_0c068e0a: /* original 000b, guest PC 0x0c068e0a */
if(!s->budget--) { s->failed_pc=0x0c068e0au; return 0; }
target=r[16];
vf3_matrix_move(s,0,4);
s->pc=target; return ram->oob==0;
P_0c068e0c: /* original f04c, guest PC 0x0c068e0c */
if(!s->budget--) { s->failed_pc=0x0c068e0cu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c068e0e;
P_0c068e0e: /* original 2fe6, guest PC 0x0c068e0e */
if(!s->budget--) { s->failed_pc=0x0c068e0eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068e10;
P_0c068e10: /* original e008, guest PC 0x0c068e10 */
if(!s->budget--) { s->failed_pc=0x0c068e10u; return 0; }
r[0]=0x00000008u;
goto P_0c068e12;
P_0c068e12: /* original 2fd6, guest PC 0x0c068e12 */
if(!s->budget--) { s->failed_pc=0x0c068e12u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068e14;
P_0c068e14: /* original ed0f, guest PC 0x0c068e14 */
if(!s->budget--) { s->failed_pc=0x0c068e14u; return 0; }
r[13]=0x0000000fu;
goto P_0c068e16;
P_0c068e16: /* original 4f22, guest PC 0x0c068e16 */
if(!s->budget--) { s->failed_pc=0x0c068e16u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c068e18;
P_0c068e18: /* original 7fdc, guest PC 0x0c068e18 */
if(!s->budget--) { s->failed_pc=0x0c068e18u; return 0; }
r[15]+=0xffffffdcu;
goto P_0c068e1a;
P_0c068e1a: /* original ff47, guest PC 0x0c068e1a */
if(!s->budget--) { s->failed_pc=0x0c068e1au; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c068e1c;
P_0c068e1c: /* original e004, guest PC 0x0c068e1c */
if(!s->budget--) { s->failed_pc=0x0c068e1cu; return 0; }
r[0]=0x00000004u;
goto P_0c068e1e;
P_0c068e1e: /* original ff57, guest PC 0x0c068e1e */
if(!s->budget--) { s->failed_pc=0x0c068e1eu; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c068e20;
P_0c068e20: /* original 65f3, guest PC 0x0c068e20 */
if(!s->budget--) { s->failed_pc=0x0c068e20u; return 0; }
r[5]=r[15];
goto P_0c068e22;
P_0c068e22: /* original d310, guest PC 0x0c068e22 */
if(!s->budget--) { s->failed_pc=0x0c068e22u; return 0; }
r[3]=read(ram,0x0c068e64u,4);
goto P_0c068e24;
P_0c068e24: /* original 66f3, guest PC 0x0c068e24 */
if(!s->budget--) { s->failed_pc=0x0c068e24u; return 0; }
r[6]=r[15];
goto P_0c068e26;
P_0c068e26: /* original d210, guest PC 0x0c068e26 */
if(!s->budget--) { s->failed_pc=0x0c068e26u; return 0; }
r[2]=read(ram,0x0c068e68u,4);
goto P_0c068e28;
P_0c068e28: /* original 7508, guest PC 0x0c068e28 */
if(!s->budget--) { s->failed_pc=0x0c068e28u; return 0; }
r[5]+=0x00000008u;
goto P_0c068e2a;
P_0c068e2a: /* original 6030, guest PC 0x0c068e2a */
if(!s->budget--) { s->failed_pc=0x0c068e2au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c068e2c;
P_0c068e2c: /* original 7604, guest PC 0x0c068e2c */
if(!s->budget--) { s->failed_pc=0x0c068e2cu; return 0; }
r[6]+=0x00000004u;
goto P_0c068e2e;
P_0c068e2e: /* original 6e22, guest PC 0x0c068e2e */
if(!s->budget--) { s->failed_pc=0x0c068e2eu; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c068e30;
P_0c068e30: /* original 600c, guest PC 0x0c068e30 */
if(!s->budget--) { s->failed_pc=0x0c068e30u; return 0; }
r[0]=r[0]&255u;
goto P_0c068e32;
P_0c068e32: /* original 2d09, guest PC 0x0c068e32 */
if(!s->budget--) { s->failed_pc=0x0c068e32u; return 0; }
r[13]&=r[0];
goto P_0c068e34;
P_0c068e34: /* original bf8e, guest PC 0x0c068e34 */
if(!s->budget--) { s->failed_pc=0x0c068e34u; return 0; }
target=code_base|0x0c068d54u; r[16]=code_base|0x0c068e38u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c068e38u) { target=s->pc; goto dispatch; }
goto P_0c068e38;
P_0c068e36: /* original 64d3, guest PC 0x0c068e36 */
if(!s->budget--) { s->failed_pc=0x0c068e36u; return 0; }
r[4]=r[13];
goto P_0c068e38;
P_0c068e38: /* original 2ee8, guest PC 0x0c068e38 */
if(!s->budget--) { s->failed_pc=0x0c068e38u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c068e3a;
P_0c068e3a: /* original 8b17, guest PC 0x0c068e3a */
if(!s->budget--) { s->failed_pc=0x0c068e3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068e6c; }
goto P_0c068e3c;
P_0c068e3c: /* original e004, guest PC 0x0c068e3c */
if(!s->budget--) { s->failed_pc=0x0c068e3cu; return 0; }
r[0]=0x00000004u;
goto P_0c068e3e;
P_0c068e3e: /* original 64f3, guest PC 0x0c068e3e */
if(!s->budget--) { s->failed_pc=0x0c068e3eu; return 0; }
r[4]=r[15];
goto P_0c068e40;
P_0c068e40: /* original f5f6, guest PC 0x0c068e40 */
if(!s->budget--) { s->failed_pc=0x0c068e40u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c068e42;
P_0c068e42: /* original e008, guest PC 0x0c068e42 */
if(!s->budget--) { s->failed_pc=0x0c068e42u; return 0; }
r[0]=0x00000008u;
goto P_0c068e44;
P_0c068e44: /* original 7418, guest PC 0x0c068e44 */
if(!s->budget--) { s->failed_pc=0x0c068e44u; return 0; }
r[4]+=0x00000018u;
goto P_0c068e46;
P_0c068e46: /* original bfcd, guest PC 0x0c068e46 */
if(!s->budget--) { s->failed_pc=0x0c068e46u; return 0; }
target=code_base|0x0c068de4u; r[16]=code_base|0x0c068e4au;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c068e4au) { target=s->pc; goto dispatch; }
goto P_0c068e4a;
P_0c068e48: /* original f4f6, guest PC 0x0c068e48 */
if(!s->budget--) { s->failed_pc=0x0c068e48u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c068e4a;
P_0c068e4a: /* original e014, guest PC 0x0c068e4a */
if(!s->budget--) { s->failed_pc=0x0c068e4au; return 0; }
r[0]=0x00000014u;
goto P_0c068e4c;
P_0c068e4c: /* original a09a, guest PC 0x0c068e4c */
if(!s->budget--) { s->failed_pc=0x0c068e4cu; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c068f84;
P_0c068e4e: /* original ff07, guest PC 0x0c068e4e */
if(!s->budget--) { s->failed_pc=0x0c068e4eu; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(!vf3_matrix_family(0x0c068e50u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c068e50u; return 0; } return 1;
P_0c068e6c: /* original c758, guest PC 0x0c068e6c */
if(!s->budget--) { s->failed_pc=0x0c068e6cu; return 0; }
r[0]=code_base|0x00068fd0u;
goto P_0c068e6e;
P_0c068e6e: /* original f408, guest PC 0x0c068e6e */
if(!s->budget--) { s->failed_pc=0x0c068e6eu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c068e70;
P_0c068e70: /* original e008, guest PC 0x0c068e70 */
if(!s->budget--) { s->failed_pc=0x0c068e70u; return 0; }
r[0]=0x00000008u;
goto P_0c068e72;
P_0c068e72: /* original f3f6, guest PC 0x0c068e72 */
if(!s->budget--) { s->failed_pc=0x0c068e72u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c068e74;
P_0c068e74: /* original f345, guest PC 0x0c068e74 */
if(!s->budget--) { s->failed_pc=0x0c068e74u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c068e76;
P_0c068e76: /* original 8901, guest PC 0x0c068e76 */
if(!s->budget--) { s->failed_pc=0x0c068e76u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068e7c; }
goto P_0c068e78;
P_0c068e78: /* original e008, guest PC 0x0c068e78 */
if(!s->budget--) { s->failed_pc=0x0c068e78u; return 0; }
r[0]=0x00000008u;
goto P_0c068e7a;
P_0c068e7a: /* original ff47, guest PC 0x0c068e7a */
if(!s->budget--) { s->failed_pc=0x0c068e7au; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c068e7c;
P_0c068e7c: /* original e004, guest PC 0x0c068e7c */
if(!s->budget--) { s->failed_pc=0x0c068e7cu; return 0; }
r[0]=0x00000004u;
goto P_0c068e7e;
P_0c068e7e: /* original f3f6, guest PC 0x0c068e7e */
if(!s->budget--) { s->failed_pc=0x0c068e7eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c068e80;
P_0c068e80: /* original f345, guest PC 0x0c068e80 */
if(!s->budget--) { s->failed_pc=0x0c068e80u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c068e82;
P_0c068e82: /* original 8901, guest PC 0x0c068e82 */
if(!s->budget--) { s->failed_pc=0x0c068e82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068e88; }
goto P_0c068e84;
P_0c068e84: /* original e004, guest PC 0x0c068e84 */
if(!s->budget--) { s->failed_pc=0x0c068e84u; return 0; }
r[0]=0x00000004u;
goto P_0c068e86;
P_0c068e86: /* original ff47, guest PC 0x0c068e86 */
if(!s->budget--) { s->failed_pc=0x0c068e86u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c068e88;
P_0c068e88: /* original c752, guest PC 0x0c068e88 */
if(!s->budget--) { s->failed_pc=0x0c068e88u; return 0; }
r[0]=code_base|0x00068fd4u;
goto P_0c068e8a;
P_0c068e8a: /* original f408, guest PC 0x0c068e8a */
if(!s->budget--) { s->failed_pc=0x0c068e8au; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c068e8c;
P_0c068e8c: /* original e008, guest PC 0x0c068e8c */
if(!s->budget--) { s->failed_pc=0x0c068e8cu; return 0; }
r[0]=0x00000008u;
goto P_0c068e8e;
P_0c068e8e: /* original f3f6, guest PC 0x0c068e8e */
if(!s->budget--) { s->failed_pc=0x0c068e8eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c068e90;
P_0c068e90: /* original f435, guest PC 0x0c068e90 */
if(!s->budget--) { s->failed_pc=0x0c068e90u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c068e92;
P_0c068e92: /* original 8901, guest PC 0x0c068e92 */
if(!s->budget--) { s->failed_pc=0x0c068e92u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068e98; }
goto P_0c068e94;
P_0c068e94: /* original e008, guest PC 0x0c068e94 */
if(!s->budget--) { s->failed_pc=0x0c068e94u; return 0; }
r[0]=0x00000008u;
goto P_0c068e96;
P_0c068e96: /* original ff47, guest PC 0x0c068e96 */
if(!s->budget--) { s->failed_pc=0x0c068e96u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c068e98;
P_0c068e98: /* original e004, guest PC 0x0c068e98 */
if(!s->budget--) { s->failed_pc=0x0c068e98u; return 0; }
r[0]=0x00000004u;
goto P_0c068e9a;
P_0c068e9a: /* original f3f6, guest PC 0x0c068e9a */
if(!s->budget--) { s->failed_pc=0x0c068e9au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c068e9c;
P_0c068e9c: /* original f435, guest PC 0x0c068e9c */
if(!s->budget--) { s->failed_pc=0x0c068e9cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c068e9e;
P_0c068e9e: /* original 8901, guest PC 0x0c068e9e */
if(!s->budget--) { s->failed_pc=0x0c068e9eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068ea4; }
goto P_0c068ea0;
P_0c068ea0: /* original e004, guest PC 0x0c068ea0 */
if(!s->budget--) { s->failed_pc=0x0c068ea0u; return 0; }
r[0]=0x00000004u;
goto P_0c068ea2;
P_0c068ea2: /* original ff47, guest PC 0x0c068ea2 */
if(!s->budget--) { s->failed_pc=0x0c068ea2u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c068ea4;
P_0c068ea4: /* original c74c, guest PC 0x0c068ea4 */
if(!s->budget--) { s->failed_pc=0x0c068ea4u; return 0; }
r[0]=code_base|0x00068fd8u;
goto P_0c068ea6;
P_0c068ea6: /* original f508, guest PC 0x0c068ea6 */
if(!s->budget--) { s->failed_pc=0x0c068ea6u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c068ea8;
P_0c068ea8: /* original c74c, guest PC 0x0c068ea8 */
if(!s->budget--) { s->failed_pc=0x0c068ea8u; return 0; }
r[0]=code_base|0x00068fdcu;
goto P_0c068eaa;
P_0c068eaa: /* original f408, guest PC 0x0c068eaa */
if(!s->budget--) { s->failed_pc=0x0c068eaau; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c068eac;
P_0c068eac: /* original e008, guest PC 0x0c068eac */
if(!s->budget--) { s->failed_pc=0x0c068eacu; return 0; }
r[0]=0x00000008u;
goto P_0c068eae;
P_0c068eae: /* original f2f6, guest PC 0x0c068eae */
if(!s->budget--) { s->failed_pc=0x0c068eaeu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c068eb0;
P_0c068eb0: /* original e004, guest PC 0x0c068eb0 */
if(!s->budget--) { s->failed_pc=0x0c068eb0u; return 0; }
r[0]=0x00000004u;
goto P_0c068eb2;
P_0c068eb2: /* original f34c, guest PC 0x0c068eb2 */
if(!s->budget--) { s->failed_pc=0x0c068eb2u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c068eb4;
P_0c068eb4: /* original e307, guest PC 0x0c068eb4 */
if(!s->budget--) { s->failed_pc=0x0c068eb4u; return 0; }
r[3]=0x00000007u;
goto P_0c068eb6;
P_0c068eb6: /* original f05c, guest PC 0x0c068eb6 */
if(!s->budget--) { s->failed_pc=0x0c068eb6u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c068eb8;
P_0c068eb8: /* original f32e, guest PC 0x0c068eb8 */
if(!s->budget--) { s->failed_pc=0x0c068eb8u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c068eba;
P_0c068eba: /* original e17f, guest PC 0x0c068eba */
if(!s->budget--) { s->failed_pc=0x0c068ebau; return 0; }
r[1]=0x0000007fu;
goto P_0c068ebc;
P_0c068ebc: /* original f33d, guest PC 0x0c068ebc */
if(!s->budget--) { s->failed_pc=0x0c068ebcu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c068ebe;
P_0c068ebe: /* original ff3a, guest PC 0x0c068ebe */
if(!s->budget--) { s->failed_pc=0x0c068ebeu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c068ec0;
P_0c068ec0: /* original f2f6, guest PC 0x0c068ec0 */
if(!s->budget--) { s->failed_pc=0x0c068ec0u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c068ec2;
P_0c068ec2: /* original 9281, guest PC 0x0c068ec2 */
if(!s->budget--) { s->failed_pc=0x0c068ec2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068fc8u,2);
goto P_0c068ec4;
P_0c068ec4: /* original f42e, guest PC 0x0c068ec4 */
if(!s->budget--) { s->failed_pc=0x0c068ec4u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[2],fr[4],r[18]);
goto P_0c068ec6;
P_0c068ec6: /* original 045a, guest PC 0x0c068ec6 */
if(!s->budget--) { s->failed_pc=0x0c068ec6u; return 0; }
r[4]=r[53];
goto P_0c068ec8;
P_0c068ec8: /* original f64c, guest PC 0x0c068ec8 */
if(!s->budget--) { s->failed_pc=0x0c068ec8u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c068eca;
P_0c068eca: /* original f63d, guest PC 0x0c068eca */
if(!s->budget--) { s->failed_pc=0x0c068ecau; return 0; }
r[53]=truncate_float(fr[6]);
goto P_0c068ecc;
P_0c068ecc: /* original f4f8, guest PC 0x0c068ecc */
if(!s->budget--) { s->failed_pc=0x0c068eccu; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c068ece;
P_0c068ece: /* original 055a, guest PC 0x0c068ece */
if(!s->budget--) { s->failed_pc=0x0c068eceu; return 0; }
r[5]=r[53];
goto P_0c068ed0;
P_0c068ed0: /* original 445a, guest PC 0x0c068ed0 */
if(!s->budget--) { s->failed_pc=0x0c068ed0u; return 0; }
r[53]=r[4];
goto P_0c068ed2;
P_0c068ed2: /* original 2419, guest PC 0x0c068ed2 */
if(!s->budget--) { s->failed_pc=0x0c068ed2u; return 0; }
r[4]&=r[1];
goto P_0c068ed4;
P_0c068ed4: /* original f32d, guest PC 0x0c068ed4 */
if(!s->budget--) { s->failed_pc=0x0c068ed4u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c068ed6;
P_0c068ed6: /* original 455a, guest PC 0x0c068ed6 */
if(!s->budget--) { s->failed_pc=0x0c068ed6u; return 0; }
r[53]=r[5];
goto P_0c068ed8;
P_0c068ed8: /* original 453c, guest PC 0x0c068ed8 */
if(!s->budget--) { s->failed_pc=0x0c068ed8u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c068eda;
P_0c068eda: /* original 2529, guest PC 0x0c068eda */
if(!s->budget--) { s->failed_pc=0x0c068edau; return 0; }
r[5]&=r[2];
goto P_0c068edc;
P_0c068edc: /* original f22d, guest PC 0x0c068edc */
if(!s->budget--) { s->failed_pc=0x0c068edcu; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c068ede;
P_0c068ede: /* original 245b, guest PC 0x0c068ede */
if(!s->budget--) { s->failed_pc=0x0c068edeu; return 0; }
r[4]|=r[5];
goto P_0c068ee0;
P_0c068ee0: /* original f431, guest PC 0x0c068ee0 */
if(!s->budget--) { s->failed_pc=0x0c068ee0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c068ee2;
P_0c068ee2: /* original f52c, guest PC 0x0c068ee2 */
if(!s->budget--) { s->failed_pc=0x0c068ee2u; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c068ee4;
P_0c068ee4: /* original 6043, guest PC 0x0c068ee4 */
if(!s->budget--) { s->failed_pc=0x0c068ee4u; return 0; }
r[0]=r[4];
goto P_0c068ee6;
P_0c068ee6: /* original f56c, guest PC 0x0c068ee6 */
if(!s->budget--) { s->failed_pc=0x0c068ee6u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c068ee8;
P_0c068ee8: /* original f32c, guest PC 0x0c068ee8 */
if(!s->budget--) { s->failed_pc=0x0c068ee8u; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c068eea;
P_0c068eea: /* original 4008, guest PC 0x0c068eea */
if(!s->budget--) { s->failed_pc=0x0c068eeau; return 0; }
r[0]<<=2;
goto P_0c068eec;
P_0c068eec: /* original f531, guest PC 0x0c068eec */
if(!s->budget--) { s->failed_pc=0x0c068eecu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c068eee;
P_0c068eee: /* original f3e6, guest PC 0x0c068eee */
if(!s->budget--) { s->failed_pc=0x0c068eeeu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c068ef0;
P_0c068ef0: /* original e010, guest PC 0x0c068ef0 */
if(!s->budget--) { s->failed_pc=0x0c068ef0u; return 0; }
r[0]=0x00000010u;
goto P_0c068ef2;
P_0c068ef2: /* original f69d, guest PC 0x0c068ef2 */
if(!s->budget--) { s->failed_pc=0x0c068ef2u; return 0; }
fr[6]=0x3f800000u;
goto P_0c068ef4;
P_0c068ef4: /* original f86c, guest PC 0x0c068ef4 */
if(!s->budget--) { s->failed_pc=0x0c068ef4u; return 0; }
vf3_matrix_move(s,8,6);
goto P_0c068ef6;
P_0c068ef6: /* original f76c, guest PC 0x0c068ef6 */
if(!s->budget--) { s->failed_pc=0x0c068ef6u; return 0; }
vf3_matrix_move(s,7,6);
goto P_0c068ef8;
P_0c068ef8: /* original f741, guest PC 0x0c068ef8 */
if(!s->budget--) { s->failed_pc=0x0c068ef8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'-');
goto P_0c068efa;
P_0c068efa: /* original ff37, guest PC 0x0c068efa */
if(!s->budget--) { s->failed_pc=0x0c068efau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c068efc;
P_0c068efc: /* original 6043, guest PC 0x0c068efc */
if(!s->budget--) { s->failed_pc=0x0c068efcu; return 0; }
r[0]=r[4];
goto P_0c068efe;
P_0c068efe: /* original 7001, guest PC 0x0c068efe */
if(!s->budget--) { s->failed_pc=0x0c068efeu; return 0; }
r[0]+=0x00000001u;
goto P_0c068f00;
P_0c068f00: /* original f851, guest PC 0x0c068f00 */
if(!s->budget--) { s->failed_pc=0x0c068f00u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[5],r[18],'-');
goto P_0c068f02;
P_0c068f02: /* original 4008, guest PC 0x0c068f02 */
if(!s->budget--) { s->failed_pc=0x0c068f02u; return 0; }
r[0]<<=2;
goto P_0c068f04;
P_0c068f04: /* original f2e6, guest PC 0x0c068f04 */
if(!s->budget--) { s->failed_pc=0x0c068f04u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c068f06;
P_0c068f06: /* original e00c, guest PC 0x0c068f06 */
if(!s->budget--) { s->failed_pc=0x0c068f06u; return 0; }
r[0]=0x0000000cu;
goto P_0c068f08;
P_0c068f08: /* original ff27, guest PC 0x0c068f08 */
if(!s->budget--) { s->failed_pc=0x0c068f08u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c068f0a;
P_0c068f0a: /* original 905e, guest PC 0x0c068f0a */
if(!s->budget--) { s->failed_pc=0x0c068f0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068fcau,2);
goto P_0c068f0c;
P_0c068f0c: /* original 304c, guest PC 0x0c068f0c */
if(!s->budget--) { s->failed_pc=0x0c068f0cu; return 0; }
r[0]+=r[4];
goto P_0c068f0e;
P_0c068f0e: /* original 4008, guest PC 0x0c068f0e */
if(!s->budget--) { s->failed_pc=0x0c068f0eu; return 0; }
r[0]<<=2;
goto P_0c068f10;
P_0c068f10: /* original f1e6, guest PC 0x0c068f10 */
if(!s->budget--) { s->failed_pc=0x0c068f10u; return 0; }
vf3_matrix_load(s,ram,1,r[14]+r[0]);
goto P_0c068f12;
P_0c068f12: /* original ff1a, guest PC 0x0c068f12 */
if(!s->budget--) { s->failed_pc=0x0c068f12u; return 0; }
vf3_matrix_store(s,ram,1,r[15]);
goto P_0c068f14;
P_0c068f14: /* original 905a, guest PC 0x0c068f14 */
if(!s->budget--) { s->failed_pc=0x0c068f14u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068fccu,2);
goto P_0c068f16;
P_0c068f16: /* original 304c, guest PC 0x0c068f16 */
if(!s->budget--) { s->failed_pc=0x0c068f16u; return 0; }
r[0]+=r[4];
goto P_0c068f18;
P_0c068f18: /* original 4008, guest PC 0x0c068f18 */
if(!s->budget--) { s->failed_pc=0x0c068f18u; return 0; }
r[0]<<=2;
goto P_0c068f1a;
P_0c068f1a: /* original f6e6, guest PC 0x0c068f1a */
if(!s->budget--) { s->failed_pc=0x0c068f1au; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c068f1c;
P_0c068f1c: /* original e010, guest PC 0x0c068f1c */
if(!s->budget--) { s->failed_pc=0x0c068f1cu; return 0; }
r[0]=0x00000010u;
goto P_0c068f1e;
P_0c068f1e: /* original f3f6, guest PC 0x0c068f1e */
if(!s->budget--) { s->failed_pc=0x0c068f1eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c068f20;
P_0c068f20: /* original e010, guest PC 0x0c068f20 */
if(!s->budget--) { s->failed_pc=0x0c068f20u; return 0; }
r[0]=0x00000010u;
goto P_0c068f22;
P_0c068f22: /* original f372, guest PC 0x0c068f22 */
if(!s->budget--) { s->failed_pc=0x0c068f22u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c068f24;
P_0c068f24: /* original ff37, guest PC 0x0c068f24 */
if(!s->budget--) { s->failed_pc=0x0c068f24u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c068f26;
P_0c068f26: /* original e00c, guest PC 0x0c068f26 */
if(!s->budget--) { s->failed_pc=0x0c068f26u; return 0; }
r[0]=0x0000000cu;
goto P_0c068f28;
P_0c068f28: /* original f2f6, guest PC 0x0c068f28 */
if(!s->budget--) { s->failed_pc=0x0c068f28u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c068f2a;
P_0c068f2a: /* original e00c, guest PC 0x0c068f2a */
if(!s->budget--) { s->failed_pc=0x0c068f2au; return 0; }
r[0]=0x0000000cu;
goto P_0c068f2c;
P_0c068f2c: /* original f642, guest PC 0x0c068f2c */
if(!s->budget--) { s->failed_pc=0x0c068f2cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c068f2e;
P_0c068f2e: /* original f242, guest PC 0x0c068f2e */
if(!s->budget--) { s->failed_pc=0x0c068f2eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c068f30;
P_0c068f30: /* original ff27, guest PC 0x0c068f30 */
if(!s->budget--) { s->failed_pc=0x0c068f30u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c068f32;
P_0c068f32: /* original e010, guest PC 0x0c068f32 */
if(!s->budget--) { s->failed_pc=0x0c068f32u; return 0; }
r[0]=0x00000010u;
goto P_0c068f34;
P_0c068f34: /* original f1f8, guest PC 0x0c068f34 */
if(!s->budget--) { s->failed_pc=0x0c068f34u; return 0; }
vf3_matrix_load(s,ram,1,r[15]);
goto P_0c068f36;
P_0c068f36: /* original f172, guest PC 0x0c068f36 */
if(!s->budget--) { s->failed_pc=0x0c068f36u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[7],r[18],'*');
goto P_0c068f38;
P_0c068f38: /* original ff1a, guest PC 0x0c068f38 */
if(!s->budget--) { s->failed_pc=0x0c068f38u; return 0; }
vf3_matrix_store(s,ram,1,r[15]);
goto P_0c068f3a;
P_0c068f3a: /* original f3f6, guest PC 0x0c068f3a */
if(!s->budget--) { s->failed_pc=0x0c068f3au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c068f3c;
P_0c068f3c: /* original e010, guest PC 0x0c068f3c */
if(!s->budget--) { s->failed_pc=0x0c068f3cu; return 0; }
r[0]=0x00000010u;
goto P_0c068f3e;
P_0c068f3e: /* original f382, guest PC 0x0c068f3e */
if(!s->budget--) { s->failed_pc=0x0c068f3eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c068f40;
P_0c068f40: /* original ff37, guest PC 0x0c068f40 */
if(!s->budget--) { s->failed_pc=0x0c068f40u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c068f42;
P_0c068f42: /* original e00c, guest PC 0x0c068f42 */
if(!s->budget--) { s->failed_pc=0x0c068f42u; return 0; }
r[0]=0x0000000cu;
goto P_0c068f44;
P_0c068f44: /* original f2f6, guest PC 0x0c068f44 */
if(!s->budget--) { s->failed_pc=0x0c068f44u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c068f46;
P_0c068f46: /* original e00c, guest PC 0x0c068f46 */
if(!s->budget--) { s->failed_pc=0x0c068f46u; return 0; }
r[0]=0x0000000cu;
goto P_0c068f48;
P_0c068f48: /* original f282, guest PC 0x0c068f48 */
if(!s->budget--) { s->failed_pc=0x0c068f48u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[8],r[18],'*');
goto P_0c068f4a;
P_0c068f4a: /* original ff27, guest PC 0x0c068f4a */
if(!s->budget--) { s->failed_pc=0x0c068f4au; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c068f4c;
P_0c068f4c: /* original e014, guest PC 0x0c068f4c */
if(!s->budget--) { s->failed_pc=0x0c068f4cu; return 0; }
r[0]=0x00000014u;
goto P_0c068f4e;
P_0c068f4e: /* original f1f8, guest PC 0x0c068f4e */
if(!s->budget--) { s->failed_pc=0x0c068f4eu; return 0; }
vf3_matrix_load(s,ram,1,r[15]);
goto P_0c068f50;
P_0c068f50: /* original f05c, guest PC 0x0c068f50 */
if(!s->budget--) { s->failed_pc=0x0c068f50u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c068f52;
P_0c068f52: /* original f26e, guest PC 0x0c068f52 */
if(!s->budget--) { s->failed_pc=0x0c068f52u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[6],fr[2],r[18]);
goto P_0c068f54;
P_0c068f54: /* original f31e, guest PC 0x0c068f54 */
if(!s->budget--) { s->failed_pc=0x0c068f54u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[1],fr[3],r[18]);
goto P_0c068f56;
P_0c068f56: /* original ff3a, guest PC 0x0c068f56 */
if(!s->budget--) { s->failed_pc=0x0c068f56u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c068f58;
P_0c068f58: /* original f42c, guest PC 0x0c068f58 */
if(!s->budget--) { s->failed_pc=0x0c068f58u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c068f5a;
P_0c068f5a: /* original f340, guest PC 0x0c068f5a */
if(!s->budget--) { s->failed_pc=0x0c068f5au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c068f5c;
P_0c068f5c: /* original ff37, guest PC 0x0c068f5c */
if(!s->budget--) { s->failed_pc=0x0c068f5cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c068f5e;
P_0c068f5e: /* original 60d3, guest PC 0x0c068f5e */
if(!s->budget--) { s->failed_pc=0x0c068f5eu; return 0; }
r[0]=r[13];
goto P_0c068f60;
P_0c068f60: /* original 880b, guest PC 0x0c068f60 */
if(!s->budget--) { s->failed_pc=0x0c068f60u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c068f62;
P_0c068f62: /* original 8b0f, guest PC 0x0c068f62 */
if(!s->budget--) { s->failed_pc=0x0c068f62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068f84; }
goto P_0c068f64;
P_0c068f64: /* original 62f3, guest PC 0x0c068f64 */
if(!s->budget--) { s->failed_pc=0x0c068f64u; return 0; }
r[2]=r[15];
goto P_0c068f66;
P_0c068f66: /* original 2f26, guest PC 0x0c068f66 */
if(!s->budget--) { s->failed_pc=0x0c068f66u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068f68;
P_0c068f68: /* original 63f3, guest PC 0x0c068f68 */
if(!s->budget--) { s->failed_pc=0x0c068f68u; return 0; }
r[3]=r[15];
goto P_0c068f6a;
P_0c068f6a: /* original 7310, guest PC 0x0c068f6a */
if(!s->budget--) { s->failed_pc=0x0c068f6au; return 0; }
r[3]+=0x00000010u;
goto P_0c068f6c;
P_0c068f6c: /* original 2f36, guest PC 0x0c068f6c */
if(!s->budget--) { s->failed_pc=0x0c068f6cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068f6e;
P_0c068f6e: /* original 66f3, guest PC 0x0c068f6e */
if(!s->budget--) { s->failed_pc=0x0c068f6eu; return 0; }
r[6]=r[15];
goto P_0c068f70;
P_0c068f70: /* original 65f3, guest PC 0x0c068f70 */
if(!s->budget--) { s->failed_pc=0x0c068f70u; return 0; }
r[5]=r[15];
goto P_0c068f72;
P_0c068f72: /* original 67f3, guest PC 0x0c068f72 */
if(!s->budget--) { s->failed_pc=0x0c068f72u; return 0; }
r[7]=r[15];
goto P_0c068f74;
P_0c068f74: /* original d21a, guest PC 0x0c068f74 */
if(!s->budget--) { s->failed_pc=0x0c068f74u; return 0; }
r[2]=read(ram,0x0c068fe0u,4);
goto P_0c068f76;
P_0c068f76: /* original 64f3, guest PC 0x0c068f76 */
if(!s->budget--) { s->failed_pc=0x0c068f76u; return 0; }
r[4]=r[15];
goto P_0c068f78;
P_0c068f78: /* original 751c, guest PC 0x0c068f78 */
if(!s->budget--) { s->failed_pc=0x0c068f78u; return 0; }
r[5]+=0x0000001cu;
goto P_0c068f7a;
P_0c068f7a: /* original 7718, guest PC 0x0c068f7a */
if(!s->budget--) { s->failed_pc=0x0c068f7au; return 0; }
r[7]+=0x00000018u;
goto P_0c068f7c;
P_0c068f7c: /* original 760c, guest PC 0x0c068f7c */
if(!s->budget--) { s->failed_pc=0x0c068f7cu; return 0; }
r[6]+=0x0000000cu;
goto P_0c068f7e;
P_0c068f7e: /* original 420b, guest PC 0x0c068f7e */
if(!s->budget--) { s->failed_pc=0x0c068f7eu; return 0; }
target=r[2];
r[16]=code_base|0x0c068f82u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c068f82u) { target=s->pc; goto dispatch; }
goto P_0c068f82;
P_0c068f80: /* original 7410, guest PC 0x0c068f80 */
if(!s->budget--) { s->failed_pc=0x0c068f80u; return 0; }
r[4]+=0x00000010u;
goto P_0c068f82;
P_0c068f82: /* original 7f08, guest PC 0x0c068f82 */
if(!s->budget--) { s->failed_pc=0x0c068f82u; return 0; }
r[15]+=0x00000008u;
goto P_0c068f84;
P_0c068f84: /* original e014, guest PC 0x0c068f84 */
if(!s->budget--) { s->failed_pc=0x0c068f84u; return 0; }
r[0]=0x00000014u;
goto P_0c068f86;
P_0c068f86: /* original f0f6, guest PC 0x0c068f86 */
if(!s->budget--) { s->failed_pc=0x0c068f86u; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c068f88;
P_0c068f88: /* original 7f24, guest PC 0x0c068f88 */
if(!s->budget--) { s->failed_pc=0x0c068f88u; return 0; }
r[15]+=0x00000024u;
goto P_0c068f8a;
P_0c068f8a: /* original 4f26, guest PC 0x0c068f8a */
if(!s->budget--) { s->failed_pc=0x0c068f8au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c068f8c;
P_0c068f8c: /* original 6df6, guest PC 0x0c068f8c */
if(!s->budget--) { s->failed_pc=0x0c068f8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c068f8e;
P_0c068f8e: /* original 000b, guest PC 0x0c068f8e */
if(!s->budget--) { s->failed_pc=0x0c068f8eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c068f90: /* original 6ef6, guest PC 0x0c068f90 */
if(!s->budget--) { s->failed_pc=0x0c068f90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c068f92u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
